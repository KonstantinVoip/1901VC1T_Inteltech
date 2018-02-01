#include <drv_ipmp.dsp-16.h>
#include <os.h>
// ---------------------------------------------------------------------------
//#define NEED_STAT
// ---------------------------------------------------------------------------

#define VREG64( a )             (*(volatile uint64*)(a))

#define RREG_FLAG0              0xc0001ff0
#define RREG_FLAG1              0xd0001ff0
#define RREG_DATA0              0xc0001ff8
#define RREG_DATA1              0xd0001ff8

#define WREG_FLAG               VREG64( 0xa0001ff0 )
#define WREG_DATA               VREG64( 0xa0001ff8 )

#define TXR                     0x0000000000000001
#define RXR                     0x0000000000000002

// ---------------------------------------------------------------------------

#define C_ALFA2006              0x414c464132303036
#define C_GOST2006              0x474f535432303036

// ---------------------------------------------------------------------------

#define S_WAIT                  0
#define S_CONNECT               1
#define S_EXCHANGE              2
#define S_PAUSE                 3

// ---------------------------------------------------------------------------

#define FRAME_PACKET            0x0013223113223100
#define FRAME_PAUSE             0x1124334224334211
#define FRAME_CONTINUE          0x2235445335445322
#define FRAME_PAUSE_ACK         0x3346556446556433
#define FRAME_CONTINUE_ACK      0x4457667557667544
#define FRAME_NUMBER            0x5568778668778655
#define FRAME_NUMBER_ACK        0x6679889779889766

// ---------------------------------------------------------------------------

static int32 mode;
static int32 rx_process;
static int32 tx_process;
static int32 state;
static uint32 comm_n;
static s_message* avg_message;
static s_message_queue outq;
static s_message_context mctx;
static uint32 send_sem;
static bool terminate;
static bool number_received;
static bool sparca_test;
static bool sparca_tack;
static void (*synfail_callback)(int32);

#ifdef NEED_STAT
s_ipmp_stat                     dsp_stat;
#endif
// ---------------------------------------------------------------------------
uint64 read_ipmp_reg(uint32 reg)
{
    uint64 val;

    sys_buslock();
    val = VREG64(reg);
    sys_busunlock();

    return val;
}
// ---------------------------------------------------------------------------
static void syn_fail( int32 critical )
{
  if( synfail_callback )
  {
    synfail_callback( critical );
  }
  else
  {
    // Disable interrupts
    int_disable();
    // Halt the processor
    while( true )
      asm( " idle " );
  }
  sparca_test = false;
}
// ---------------------------------------------------------------------------
static void wait_plis()
{
  bool c0, c1;

  // Wait for PLIS down
  while( true )
  {
    uint64 rval0 = VREG64( 0xc0001fe8 );
    uint64 rval1 = VREG64( 0xd0001fe8 );
    if( mode & IPMP_DSP16_CH_FIRST ) c0 = ( rval0 == C_GOST2006 ) || ( rval0 == C_ALFA2006 ); else c0 = false;
    if( mode & IPMP_DSP16_CH_SECOND ) c1 = ( rval1 == C_GOST2006 ) || ( rval1 == C_ALFA2006 ); else c1 = false;
    if( !c0 && !c1 ) break;
    prc_yield();
  }

  // Wait for PLIS up
  while( true )
  {
    uint64 rval0 = VREG64( 0xc0001fe8 );
    uint64 rval1 = VREG64( 0xd0001fe8 );
    if( mode & IPMP_DSP16_CH_FIRST ) c0 = ( rval0 == C_GOST2006 ) || ( rval0 == C_ALFA2006 ); else c0 = true;
    if( mode & IPMP_DSP16_CH_SECOND ) c1 = ( rval1 == C_GOST2006 ) || ( rval1 == C_ALFA2006 ); else c1 = true;
    if( c0 && c1 ) break;
    prc_yield();
  }
}
// ---------------------------------------------------------------------------
static bool recv_8b( uint64* r )
{
  register uint64 r0 = 0;
  register uint64 r1 = 0;

  if( mode & IPMP_DSP16_CH_FIRST )
  {
    while( !( read_ipmp_reg(RREG_FLAG0) & RXR ) )
    {
      if( terminate ) return true;
      prc_yield();
    }
    r0 = read_ipmp_reg(RREG_DATA0);
  }

  if( mode & IPMP_DSP16_CH_SECOND )
  {
    while( !( read_ipmp_reg(RREG_FLAG1) & RXR ) )
    {
      if( terminate ) return true;
      prc_yield();
    }
    r1 = read_ipmp_reg(RREG_DATA1);
  }

  if( ( mode == IPMP_DSP16_CH_BOTH ) && ( r0 != r1 ) ) 
  {

     asm("  nop");
     asm("  nop");
     asm("  nop");
     return false;
  }
  _mem8( r ) = r0 | r1;

  // 25ns delay
  asm( " nop 9 " );
  asm( " nop 9 " );
  asm( " nop 7 " );

  return true;
}
// ---------------------------------------------------------------------------
static void send_8b( uint64 w )
{
  if( mode & IPMP_DSP16_CH_FIRST )
  {
    while( read_ipmp_reg(RREG_FLAG0) & TXR )
    {
      if( terminate ) return;
      prc_yield();
    }
  }

  if( mode & IPMP_DSP16_CH_SECOND )
  {
    while( read_ipmp_reg(RREG_FLAG1) & TXR )
    {
      if( terminate ) return;
      prc_yield();
    }
  }

  WREG_DATA = w;
  WREG_FLAG = TXR;

  // 25ns delay
  asm( " nop 9 " );
  asm( " nop 9 " );
  asm( " nop 7 " );
}
// ---------------------------------------------------------------------------
static int ipmp_dsp16_tx_process( void* arg )
{
  register uint64* dp;
  uint64 t;
  uint32 i, l;
  uint16 c16;
  s_message* m;
  
  while( !terminate )
  {
    switch( state )
    {
      case S_WAIT:
      {
        sleep_m( 1 );
      }
      break;

      case S_CONNECT:
      {
        if( number_received )
        {
          send_8b( FRAME_NUMBER_ACK );
          state = S_EXCHANGE;
        }
        else
        {
          sleep_m( 1 );
        }
      }
      break;

      case S_EXCHANGE:
      {
        if( msg_queue_pop( &outq, &m, SEM_INFINITY ) != OSE_OK ) break;
        if( m == NULL ) break;

        dp = (uint64*)m->data;

        c16 = cry_crc16( &m->from, sizeof(uint32), 0 );
        c16 = cry_crc16( &m->to, sizeof(uint32), c16 );
        c16 = cry_crc16( &m->length, sizeof(uint32), c16 );
        c16 = cry_crc16( m->data, m->length, c16 );
        
      l_relock:
    
        sem_lock( send_sem, SEM_INFINITY );
        if( state != S_EXCHANGE )
        {
          sem_unlock( send_sem );
          while( state != S_EXCHANGE )
          {
            if( terminate ) break;
            prc_yield();
          }
          if( terminate ) break;
          goto l_relock;
        }
    
        send_8b( FRAME_PACKET );
        send_8b( (uint64)m->from );
        send_8b( (uint64)m->to );
        send_8b( (uint64)m->length );
        for( i = 0, l = m->length >> 3; i < l; i++, dp++ ) send_8b( _mem8( dp ) );
        if( m->length & 7 )
        {
          t = 0llu;
          memcpy( &t, dp, m->length & 7 );
          send_8b( t );
        }
        send_8b( (uint64)c16 );
    
        sem_unlock( send_sem );

        #ifdef NEED_STAT
        _mem8( &dsp_stat.tx_count ) = _mem8( &dsp_stat.tx_count ) + 1;
        _mem8( &dsp_stat.tx_bytes ) = _mem8( &dsp_stat.tx_bytes ) + (uint64)m->length;
        #endif
    
        msg_free( m );
      }
      break;

      case S_PAUSE:
      {
        sleep_m( 1 );
      }
      break;
    }
  }

  return 0;
}
// ---------------------------------------------------------------------------
static int ipmp_dsp16_rx_process( void* arg )
{
  uint64 frame, d;
  
  while( !terminate )
  {
    switch( state )
    {
      case S_WAIT:
      {
        sleep_m( 1 );
      }
      break;

      case S_CONNECT:
      {
        if( !number_received )
        {
          if( !recv_8b( &frame ) ) { syn_fail( 1 ); break; }
          if( frame != FRAME_NUMBER ) break;
          if( !recv_8b( &d ) ) { syn_fail( 1 ); break; }
          comm_n = (uint32)d;
          number_received = true;
        }
        else
        {
          sleep_m( 1 );
        }
      }
      break;

      case S_EXCHANGE:
      {
        if( !recv_8b( &frame ) ) { syn_fail( 1 ); break; }

        switch( frame )
        {
          case FRAME_PACKET:
          {
            uint32 length, from, to, i, l;
            register uint64* dp;
            uint16 c16, rc16;

            if( !recv_8b( &d ) ) { syn_fail( 1 ); break; }
            from = (uint32)d;
            if( !recv_8b( &d ) ) { syn_fail( 1 ); break; }
            to = (uint32)d;
            if( !recv_8b( &d ) ) { syn_fail( 1 ); break; }
            length = (uint32)d;

            sparca_tack = false;

            if( ( avg_message = msg_alloc( (int32)length, mctx.pipe ) ) != NULL )
            {
              dp = (uint64*)avg_message->data;
              avg_message->from = from;
              avg_message->to = to;

              for( i = 0, l = length >> 3; i < l; i++, dp++ )
              {
                if( !recv_8b( dp ) )
                {
                  if( sparca_test )
                  {
                    sparca_tack = true;
                  }
                  else
                  {
                    syn_fail( 1 );
                    goto l_read_fail;
                  }
                }
              }
              
              if( length & 7 )
              {
                if( !recv_8b( &d ) )
                {
                  if( sparca_test )
                  {
                    sparca_tack = true;
                  }
                  else
                  {
                    syn_fail( 1 );
                    goto l_read_fail;
                  }
                }
                memcpy( dp, &d, length & 7 );
              }
              
              if( !recv_8b( &d ) )
              {
                if( !sparca_test )
                {
                  goto l_read_fail;
                }
              }
              rc16 = (uint16)d;

              if( sparca_tack )
              {
                syn_fail( 0 );
                goto l_read_fail;
              }

              c16 = cry_crc16( &from, sizeof(uint32), 0 );
              c16 = cry_crc16( &to, sizeof(uint32), c16 );
              c16 = cry_crc16( &length, sizeof(uint32), c16 );
              c16 = cry_crc16( avg_message->data, length, c16 );
              
              if( rc16 == c16 )
              {
                #ifdef NEED_STAT
                _mem8( &dsp_stat.rx_count ) = _mem8( &dsp_stat.rx_count ) + 1;
                _mem8( &dsp_stat.rx_bytes ) = _mem8( &dsp_stat.rx_bytes ) + (uint64)length;
                #endif
                msg_queue_push( mctx.inq, avg_message );
                avg_message = NULL;
              }
              else
              {
                #ifdef NEED_STAT
                _mem8( &dsp_stat.rx_drop ) = _mem8( &dsp_stat.rx_drop ) + 1;
                _mem8( &dsp_stat.rx_drop_hash ) = _mem8( &dsp_stat.rx_drop_hash ) + 1;
                #endif
                goto l_read_fail;
              }
            }
            else
            {
              for( i = 0, l = length >> 3; i < l; i++ )
              {
                if( !recv_8b( &d ) )
                {
                  if( sparca_test )
                  {
                    sparca_tack = true;
                  }
                  else
                  {
                    syn_fail( 1 );
                    goto l_read_fail;
                  }
                }
              }
              if( length & 7 )
              {
                if( !recv_8b( &d ) )
                {
                  if( sparca_test )
                  {
                    sparca_tack = true;
                  }
                  else
                  {
                    syn_fail( 1 );
                    break;
                  }
                }
              }
              if( !recv_8b( &d ) ) if( !sparca_test ) { syn_fail( 1 ); break; }
              
              if( sparca_tack )
              {
                syn_fail( 0 );
                break;
              }

              #ifdef NEED_STAT
              _mem8( &dsp_stat.rx_drop ) = _mem8( &dsp_stat.rx_drop ) + 1;
              _mem8( &dsp_stat.rx_drop_mem ) = _mem8( &dsp_stat.rx_drop_mem ) + 1;
              #endif
            }

            break;
          
          l_read_fail:

            msg_free( avg_message );
            avg_message = NULL;
          }
          break;

          case FRAME_PAUSE:
          {
            // Lock interrupt events 60 61
            register uint32 is = int_disable();
            REG_EVTMASK[1] |= 0x30000000;
            int_enable( is );

            sem_lock( send_sem, SEM_INFINITY );
            state = S_PAUSE;
            send_8b( FRAME_PAUSE_ACK );
            sem_unlock( send_sem );
          }
          break;
          
          default:
          {
            #ifdef NEED_STAT
            _mem8( &dsp_stat.rx_drop ) = _mem8( &dsp_stat.rx_drop ) + 1;
            #endif
          }
          break;
        }
      }
      break;

      case S_PAUSE:
      {
        sem_lock( send_sem, SEM_INFINITY );
        wait_plis();
        while( true )
        {
          if( !recv_8b( &frame ) ) { syn_fail( 1 ); break; }
          if( frame == FRAME_CONTINUE )
          {
            // Reset interrupt state and unlock interrupts
            register uint32 is = int_disable();
            REG_EVTCLR[1] = 0x30000000;
            REG_EVTMASK[1] &= 0xcfffffff;
            int_enable( is );
            
            send_8b( FRAME_CONTINUE_ACK );
            state = S_EXCHANGE;
            break;
          }
          sleep_m( 1 );
        }
        sem_unlock( send_sem );
      }
      break;
    }
  }

  return 0;
}
// ---------------------------------------------------------------------------
int32 ipmp_dsp16_comm_open( s_os_driver_descriptor* d, uint16 access )
{
  return -1;
}
// ---------------------------------------------------------------------------
int32 ipmp_dsp16_comm_close( s_os_driver_descriptor* d )
{
  return -1;
}
// ---------------------------------------------------------------------------
int32 ipmp_dsp16_comm_read( s_os_driver_descriptor* d, void* buf, int32 length )
{
  return -1;
}
// ---------------------------------------------------------------------------
int32 ipmp_dsp16_comm_write( s_os_driver_descriptor* d, const void* buf, int32 length )
{
  return -1;
}
//---------------------------------------------------------------------------
int32 ipmp_dsp16_comm_ioctl( s_os_driver_descriptor* d, int32 cmd, const void* arg )
{
  switch( cmd )
  {
    case IOC_INIT_DESCRIPTOR:
    case IOC_DEINIT_DESCRIPTOR:
      break;

    case IOC_INIT:
    {
      int32 r;
      s_prc_attr pattr;

      terminate = false;
      number_received = false;
      rx_process = 0;
      tx_process = 0;
      state = S_WAIT;
      comm_n = 0xffffffff;
      avg_message = NULL;
      memset( &mctx, 0, sizeof(mctx) );
      send_sem = RES_VOID;
      #ifdef NEED_STAT
      memset( &dsp_stat, 0, sizeof(s_ipmp_stat) );
      #endif
      sparca_test = false;
      sparca_tack = false;
      synfail_callback = NULL;

      if( ( r = msg_queue_init( &outq ) ) != OSE_OK ) return r;
      if( ( send_sem = sem_alloc( 1, NULL ) ) == RES_VOID ) { r = OSE_CANT_CREATE_SEM; goto l_fail; }

      wait_plis();
      
      memset( &pattr, 0, sizeof(pattr) );
      pattr.stack = 512;
      tx_process = prc_create( &ipmp_dsp16_tx_process, NULL, 0, &pattr );
      rx_process = prc_create( &ipmp_dsp16_rx_process, NULL, 0, &pattr );
      if( ( rx_process <= 0 ) || ( tx_process <= 0 ) ) { r = OSE_CANT_CREATE_PROCESS; goto l_fail; }

      mctx.outq = &outq;
      if( ( r = msg_regpipe( &mctx, 2 ) ) != OSE_OK ) goto l_fail;

      state = S_CONNECT;
      while( state != S_EXCHANGE ) prc_yield();

      break;

    l_fail:

      terminate = true;
      sem_unlock( outq.count_sem );
      prc_join( rx_process );
      prc_join( tx_process );
      msg_queue_deinit( &outq );
      sem_free( send_sem );

      return r;
    }

    case IOC_DEINIT:
    {
      terminate = true;
      sem_unlock( outq.count_sem );
      prc_join( rx_process );
      prc_join( tx_process );
      msg_queue_deinit( &outq );
      sem_free( send_sem );
      mode = 0;
    }
    break;

    case IOC_INODE_SELECT:
    {
      if( arg == NULL ) return OSE_NULL_PARAM;
      const char* name = (const char*)arg;
      
      if( strcmp( name, "." ) == 0 ) break;
      if( strcmp( name, ".." ) != 0 ) return OSE_NO_NODE;

      drv_dec( d );
      drv_rfs( d );
    }
    break;
    
    #ifdef NEED_STAT
    case IPMP_STAT:
    {
      if( arg == NULL ) return OSE_NULL_PARAM;
      s_ipmp_stat* s = (s_ipmp_stat*)const_cast<void*>( arg );
      memcpy( s, &dsp_stat, sizeof(s_ipmp_stat) );
    }
    break;
    #endif

    case IPMP_NUMBER:
    {
      if( arg == NULL ) return OSE_NULL_PARAM;
      (*(uint32*)const_cast<void*>( arg )) = comm_n;
    }
    break;

    case IPMP_SET_SYNFAIL_CALLBACK:
    {
      synfail_callback = (void(*)(int32))(uint32)const_cast<void*>( arg );
    }
    break;

    case IPMP_SPTEST:
    {
      if( sparca_test )
      {
        sparca_test = false;
        syn_fail( 1 );
      }
      sparca_test = true;
    }
    break;
    
    default:
      return OSE_BAD_CMD;
  }

  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 drv_ipmp_dsp16_plug( const char* path, uint32 s_mode )
{
  mode = s_mode;
  return drv_plug( path, INOT_FILE, &ipmp_dsp16_comm_open, &ipmp_dsp16_comm_close, &ipmp_dsp16_comm_read, &ipmp_dsp16_comm_write, &ipmp_dsp16_comm_ioctl, NULL, 0 );
}
// ---------------------------------------------------------------------------
int32 drv_ipmp_dsp16_unplug( const char* name )
{
  return drv_unplug( name );
}
// ---------------------------------------------------------------------------
