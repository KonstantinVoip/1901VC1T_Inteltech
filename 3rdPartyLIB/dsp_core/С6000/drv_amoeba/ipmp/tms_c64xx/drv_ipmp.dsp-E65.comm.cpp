#include <drv_ipmp.dsp-E65.h>
#include <os.h>
// ---------------------------------------------------------------------------
//#define NEED_STAT
// ---------------------------------------------------------------------------

#define S_WAIT                  0
#define S_CONNECT               1
#define S_EXCHANGE              2
#define S_PAUSE                 3

// ---------------------------------------------------------------------------

#define FRAME_PACKET            0x00132231
#define FRAME_PAUSE             0x11243342
#define FRAME_CONTINUE          0x22354453
#define FRAME_PAUSE_ACK         0x33465564
#define FRAME_CONTINUE_ACK      0x44576675
#define FRAME_NUMBER            0x55687786
#define FRAME_NUMBER_ACK        0x66798897
#define FRAME_RESET             0xf0f00f0f

// ---------------------------------------------------------------------------

static bool terminate;
static bool number_received;
static int32 rx_process;
static int32 tx_process;
static int32 state;
static uint32 comm_n;
static s_message* avg_message;
static s_message_queue outq;
static s_message_context mctx;
static uint32 send_sem;
static void (*synfail_callback)(int32);
static bool sparca_test;
static bool sparca_tack;
static uint32 int0_d;
static uint32 int1_d;

#ifdef NEED_STAT
s_ipmp_stat stat;
#endif

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
  bool r;

  // Wait PLIS down
  while( true )
  {
    r = true;
    if( REG_C_RRFLAG_PORT0 != 0xffffffff ) r = false;
    if( REG_C_RRFLAG_PORT1 != 0xffffffff ) r = false;
    if( r ) break;
    prc_yield();
  }
  // Wait PLIS up
  while( true )
  {
    r = true;
    if( REG_C_RRFLAG_PORT0 == 0xffffffff ) r = false;
    if( REG_C_RRFLAG_PORT1 == 0xffffffff ) r = false;
    if( r ) break;
    prc_yield();
  }
  sleep_m( 100 );
}
// ---------------------------------------------------------------------------
static bool recv_4b( uint32* r )
{
  register uint32 r0 = 0;
  register uint32 r1 = 0;
  
  while(!(( REG_C_RRFLAG_PORT0 & F_C_RXR ) & ( REG_C_RRFLAG_PORT1 & F_C_RXR )) )
  {
    if( terminate ) return true;
      prc_yield();
  }
  r1 = REG_C_RX1_PORT;
  r0 = REG_C_RX0_PORT;

  REG_C_WRFLAG_PORT = 0;

  if( r0 != r1 ) 
  {
    return false;
  }

  _mem4( r ) = r0 | r1;

  // 34ns delay
  asm( " nop 9 " );
  asm( " nop 8 " );

  return true;
}
// ---------------------------------------------------------------------------
static void send_4b( uint32 w )
{
  while( REG_C_RWFLAG_PORT0 == F_C_TXR )
  {
    if( terminate ) return;
    prc_yield();
  }

  while( REG_C_RWFLAG_PORT1 == F_C_TXR )
  {
    if( terminate ) return;
    prc_yield();
  }

  REG_C_TX_PORT     = w;//Записываем данные
  REG_C_WWFLAG_PORT = 1;//Выставляем флаг о наличие данных для ЦП 

  // 34ns delay
  asm( " nop 9 " );
  asm( " nop 8 " );
}
// ---------------------------------------------------------------------------
static int ipmp_dspE65_tx_process( void* arg )
{
  register uint32* dp;
  uint32 c32, i, l;
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
          send_4b( FRAME_NUMBER_ACK );
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

        dp = (uint32*)m->data;

        c16 = cry_crc16( &m->from, sizeof(uint32), 0 );
        c16 = cry_crc16( &m->to, sizeof(uint32), c16 );
        c16 = cry_crc16( &m->length, sizeof(uint32), c16 );
        c32 = (uint32)cry_crc16( m->data, m->length, c16 );
        
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
    
        send_4b( FRAME_PACKET );
        send_4b( m->from );
        send_4b( m->to );
        send_4b( m->length );
        for( i = 0, l = m->length >> 2; i < l; i++, dp++ ) send_4b( (*dp) );
        if( m->length & 3 )
        {
          l = 0;
          memcpy( &l, dp, m->length & 3 );
          send_4b( l );
        }
        send_4b( c32 );
    
        sem_unlock( send_sem );

        #ifdef NEED_STAT
        _mem8( &stat.tx_count ) = _mem8( &stat.tx_count ) + 1;
        _mem8( &stat.tx_bytes ) = _mem8( &stat.tx_bytes ) + (uint64)m->length;
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
static int ipmp_dspE65_rx_process( void* arg )
{
  uint32 frame, d;
  
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
          if( !recv_4b( &frame ) ) { syn_fail( 1 ); break; }
          if( frame != FRAME_NUMBER ) break;
          if( !recv_4b( &comm_n ) ) { syn_fail( 1 ); break; }
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
        if( !recv_4b( &frame ) ) break;

        switch( frame )
        {
          case FRAME_PACKET:
          {
            uint32 length, from, to;
            uint32 i, l, rc32, c32;
            register uint32* dp;
            uint16 c16;

            if( !recv_4b( &from ) ) { syn_fail( 1 ); break; }
            if( !recv_4b( &to ) ) { syn_fail( 1 ); break; }
            if( !recv_4b( &length ) ) { syn_fail( 1 ); break; }

            sparca_tack = false;

            if( ( avg_message = msg_alloc( (int32)length, mctx.pipe ) ) != NULL )
            {
              dp = (uint32*)avg_message->data;
              avg_message->from = from;
              avg_message->to = to;

              for( i = 0, l = length >> 2; i < l; i++, dp++ )
              {
                if( !recv_4b( dp ) )
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

              if( length & 3 )
              {
                if( !recv_4b( &d ) )
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
                memcpy( dp, &d, length & 3 );
              }

              if( !recv_4b( &rc32 ) )
              {
                if( !sparca_test )
                {
                  goto l_read_fail;
                }
              }

              if( sparca_tack )
              {
                syn_fail( 0 );
                goto l_read_fail;
              }

              c16 = cry_crc16( &from, sizeof(uint32), 0 );
              c16 = cry_crc16( &to, sizeof(uint32), c16 );
              c16 = cry_crc16( &length, sizeof(uint32), c16 );
              c32 = (uint32)cry_crc16( avg_message->data, length, c16 );
              
              if( rc32 == c32 )
              {
                #ifdef NEED_STAT
                _mem8( &stat.rx_count ) = _mem8( &stat.rx_count ) + 1;
                _mem8( &stat.rx_bytes ) = _mem8( &stat.rx_bytes ) + (uint64)length;
                #endif
                msg_queue_push( mctx.inq, avg_message );
                avg_message = NULL;
              }
              else
              {
                #ifdef NEED_STAT
                _mem8( &stat.rx_drop ) = _mem8( &stat.rx_drop ) + 1;
                _mem8( &stat.rx_drop_hash ) = _mem8( &stat.rx_drop_hash ) + 1;
                #endif
                goto l_read_fail;
              }
            }
            else
            {
              for( i = 0, l = length >> 2; i < l; i++ )
              {
                if( !recv_4b( &d ) )
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
              if( length & 3 )
              {
                if( !recv_4b( &d ) )
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
              if( !recv_4b( &d ) ) if( !sparca_test ) { syn_fail( 1 ); break; }
              
              if( sparca_tack )
              {
                syn_fail( 0 );
                break;
              }

              #ifdef NEED_STAT
              _mem8( &stat.rx_drop ) = _mem8( &stat.rx_drop ) + 1;
              _mem8( &stat.rx_drop_mem ) = _mem8( &stat.rx_drop_mem ) + 1;
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
            // Lock interrupts 4 5
            int_lock( int0_d );
            int_lock( int1_d );

            sem_lock( send_sem, SEM_INFINITY );
            state = S_PAUSE;
            send_4b( FRAME_PAUSE_ACK );
            sem_unlock( send_sem );
          }
          break;

          default:
          {
            #ifdef NEED_STAT
            _mem8( &stat.rx_drop ) = _mem8( &stat.rx_drop ) + 1;
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
          if( !recv_4b( &frame ) ) break;
          if( frame == FRAME_CONTINUE )
          {
            // Clear and unlock interrupts
            int_clear( int0_d );
            int_clear( int1_d );
            int_unlock( int0_d );
            int_unlock( int1_d );
            
            send_4b( FRAME_CONTINUE_ACK );
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
int32 ipmp_dspE65_comm_open( s_os_driver_descriptor* d, uint16 access )
{
  return -1;
}
// ---------------------------------------------------------------------------
int32 ipmp_dspE65_comm_close( s_os_driver_descriptor* d )
{
  return -1;
}
// ---------------------------------------------------------------------------
int32 ipmp_dspE65_comm_read( s_os_driver_descriptor* d, void* buf, int32 length )
{
  return -1;
}
// ---------------------------------------------------------------------------
int32 ipmp_dspE65_comm_write( s_os_driver_descriptor* d, const void* buf, int32 length )
{
  return -1;
}
//---------------------------------------------------------------------------
int32 ipmp_dspE65_comm_ioctl( s_os_driver_descriptor* d, int32 cmd, const void* arg )
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
      memset( &stat, 0, sizeof(s_ipmp_stat) );
      #endif
      sparca_test = false;
      sparca_tack = false;
      synfail_callback = NULL;
      int0_d = RES_VOID;
      int1_d = RES_VOID;

      if( ( r = msg_queue_init( &outq ) ) != OSE_OK ) return r;
      if( ( send_sem = sem_alloc( 1, NULL ) ) == RES_VOID ) { r = OSE_CANT_CREATE_SEM; goto l_fail; }

      wait_plis();
      
      memset( &pattr, 0, sizeof(pattr) );
      pattr.stack = 512;
      tx_process = prc_create( &ipmp_dspE65_tx_process, NULL, 0, &pattr );
      rx_process = prc_create( &ipmp_dspE65_rx_process, NULL, 0, &pattr );
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
      memcpy( s, &stat, sizeof(s_ipmp_stat) );
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
int32 drv_ipmp_dspE65_plug( const char* path, uint32 i0_d, uint32 i1_d )
{
  if( ( i0_d == RES_VOID ) || ( i1_d == RES_VOID ) ) return OSE_VOID_RESOURCE;
  int0_d = i0_d;
  int1_d = i1_d;
  res_share( int0_d );
  res_share( int1_d );
/*
  // determine const
  while( REG_C_CONST_PORT0 != 0x474F535432303036 );
  while( REG_C_CONST_PORT0 != 0x474F535432303036 );
*/
  return drv_plug( path, INOT_FILE, &ipmp_dspE65_comm_open, &ipmp_dspE65_comm_close, &ipmp_dspE65_comm_read, &ipmp_dspE65_comm_write, &ipmp_dspE65_comm_ioctl, NULL, 0 );
}
// ---------------------------------------------------------------------------
int32 drv_ipmp_dspE65_plug( const char* path )
{
  int0_d = RES_VOID;
  int1_d = RES_VOID;
  return drv_plug( path, INOT_FILE, &ipmp_dspE65_comm_open, &ipmp_dspE65_comm_close, &ipmp_dspE65_comm_read, &ipmp_dspE65_comm_write, &ipmp_dspE65_comm_ioctl, NULL, 0 );
}
// ---------------------------------------------------------------------------
int32 drv_ipmp_dspE65_unplug( const char* name )
{
  return drv_unplug( name );
}
// ---------------------------------------------------------------------------
