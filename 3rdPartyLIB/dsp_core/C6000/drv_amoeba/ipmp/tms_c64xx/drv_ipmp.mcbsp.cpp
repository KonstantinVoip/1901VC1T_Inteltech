#include <drv_ipmp.mcbsp.h>
// ---------------------------------------------------------------------------
//#define NEED_STAT
// ---------------------------------------------------------------------------

#define S_WAIT0                 0
#define S_WAIT1                 1
#define S_CONNECT               2
#define S_ESTABLISHED           3
#define S_SYN_FAIL              4

// ---------------------------------------------------------------------------

#define FRAME_ACK               0x00132231
#define FRAME_PACKET            0x11243342
#define FRAME_FRAGMENT          0x22354453
#define FRAME_SIDE_RESPONSE     0x33465564
#define FRAME_CONNECT           0x44576675
#define FRAME_RESET             0xf0f00f0f

//#define FRAME_LENGTH            1024//в байтах
// ---------------------------------------------------------------------------

static const char* mcbsp_device = { "/dev/mcbsp" };

// ---------------------------------------------------------------------------

static uint32 send_sem;
static uint32 tx_sem;

static volatile bool terminate;
static volatile bool have_remote_side;
static volatile bool connect_sended;
static volatile int32 state;
static s_message_queue outq;
static s_message_context mctx;
static void (*synfail_callback)() = NULL;
#ifdef NEED_STAT
s_ipmp_stat stat;
#endif

static uint32 mcbsp_rd;
static uint32 mcbsp_wr;

static int32 rx_process;
static int32 tx_process;

static s_message* avg_message;
static int32 avg_offset;

// ---------------------------------------------------------------------------
static void syn_fail()
{
  // Disable interrupts
  int_disable();

  if( synfail_callback )
  {
    synfail_callback();
  }
  else
  {
    // Halt the processor
    while( true )
      asm( " idle " );
  }
}
// ---------------------------------------------------------------------------
static int ipmp_mcbsp_tx_process( void* arg )
{
  uint32 frame;
  s_message* m;
  uint32 c32;
  uint16 c16;

  while( !terminate )
  {
    switch( state )
    {
      case S_WAIT0:
      {
        sleep_m( 1 );
      }
      break;

      case S_WAIT1:
      {
        frame = FRAME_SIDE_RESPONSE;
        sem_lock( tx_sem, SEM_INFINITY );
        drv_write( mcbsp_wr, &frame, sizeof(uint32) );
        sem_unlock( tx_sem );
        if( !have_remote_side ) sleep_m( 100 ); else state = S_CONNECT;
      }
      break;

      case S_CONNECT:
      {
        if( !connect_sended )
        {
          frame = FRAME_CONNECT;
          sem_lock( tx_sem, SEM_INFINITY );
          drv_write( mcbsp_wr, &frame, sizeof(uint32) );
          sem_unlock( tx_sem );
          connect_sended = true;
        }
        else
        {
          sleep_m( 1 );
        }
      }
      break;

      case S_ESTABLISHED:
      {
        uint32 offset, length, clen;

        if( msg_queue_pop( &outq, &m, SEM_INFINITY ) != OSE_OK ) break;
        if( m == NULL ) break;

        c16 = cry_crc16( &m->from, sizeof(uint32), 0 );
        c16 = cry_crc16( &m->to, sizeof(uint32), c16 );
        c32 = (uint32)cry_crc16( &m->length, sizeof(uint32), c16 );
        frame = FRAME_PACKET;

        sem_lock( tx_sem, SEM_INFINITY );
        drv_write( mcbsp_wr, &frame, sizeof(uint32) );
        drv_write( mcbsp_wr, &m->from, sizeof(uint32) );
        drv_write( mcbsp_wr, &m->to, sizeof(uint32) );
        drv_write( mcbsp_wr, &m->length, sizeof(uint32) );
        drv_write( mcbsp_wr, &c32, sizeof(uint32) );
        sem_unlock( tx_sem );

        frame = FRAME_FRAGMENT;
        offset = 0;
        length = m->length;

        while( length )
        {
          sem_lock( send_sem, SEM_INFINITY );

          if( length >= FRAME_LENGTH ) clen = FRAME_LENGTH; else clen = length;
          c16 = cry_crc16( &clen, sizeof(uint32), 0 );
          c32 = (uint32)cry_crc16( (char*)m->data + offset, clen, c16 );

          sem_lock( tx_sem, SEM_INFINITY );
          drv_write( mcbsp_wr, &frame, sizeof(uint32) );
          drv_write( mcbsp_wr, &clen, sizeof(uint32) );
          drv_write( mcbsp_wr, (char*)m->data + offset, clen );
          drv_write( mcbsp_wr, &c32, sizeof(uint32) );
          sem_unlock( tx_sem );

          offset += clen;
          length -= clen;
        }

        #ifdef NEED_STAT
        _mem8( &stat.tx_count ) = _mem8( &stat.tx_count ) + 1;
        _mem8( &stat.tx_bytes ) = _mem8( &stat.tx_bytes ) + (uint64)m->length;
        #endif

        msg_free( m ); 
      }
      break;

      case S_SYN_FAIL:
      {
        syn_fail();
      }
      break;
    }

  }

  return 0;
}
// ---------------------------------------------------------------------------
static int ipmp_mcbsp_rx_process( void* arg )
{
  int32 r;
  uint32 frame;
  uint32 c32, rc32;
  uint16 c16;

  while( !terminate )
  {
    switch( state )
    {
      case S_WAIT0:
      {
        sleep_m( 1 );
      }
      break;

      case S_WAIT1:
      {
        if( !have_remote_side )
        {
          if( ( r = drv_read( mcbsp_rd, &frame, sizeof(uint32) ) ) < 0 ) { state = S_SYN_FAIL; break; }
          if( ( r == sizeof(uint32) ) && ( frame == FRAME_SIDE_RESPONSE ) ) have_remote_side = true;
        }
        else
        {
          sleep_m( 1 );
        }
      }
      break;

      case S_CONNECT:
      {
        if( ( r = drv_read( mcbsp_rd, &frame, sizeof(uint32) ) ) < 0 ) { state = S_SYN_FAIL; break; }
        if( ( r == sizeof(uint32) ) && ( frame == FRAME_CONNECT ) )
        {
          while( !connect_sended ) sleep_m( 1 );
          state = S_ESTABLISHED;
        }
      }
      break;

      case S_ESTABLISHED:
      {
        if( drv_read( mcbsp_rd, &frame, sizeof(uint32) ) != sizeof(uint32) ) { state = S_SYN_FAIL; break; }
        
        switch( frame )
        {
          case FRAME_ACK:
          {
            sem_unlock( send_sem );
          }
          break;

          case FRAME_PACKET:
          {
            uint32 length, from, to;

            msg_free( avg_message );
            avg_message = NULL;

            if( drv_read( mcbsp_rd, &from, sizeof(uint32) ) != sizeof(uint32) ) { state = S_SYN_FAIL; break; }
            if( drv_read( mcbsp_rd, &to, sizeof(uint32) ) != sizeof(uint32) ) { state = S_SYN_FAIL; break; }
            if( drv_read( mcbsp_rd, &length, sizeof(uint32) ) != sizeof(uint32) ) { state = S_SYN_FAIL; break; }
            if( drv_read( mcbsp_rd, &rc32, sizeof(uint32) ) != sizeof(uint32) ) { state = S_SYN_FAIL; break; }

            c16 = cry_crc16( &from, sizeof(uint32), 0 );
            c16 = cry_crc16( &to, sizeof(uint32), c16 );
            c32 = (uint32)cry_crc16( &length, sizeof(uint32), c16 );

            if( rc32 != c32 )
            {
              #ifdef NEED_STAT
              _mem8( &stat.rx_drop_hash ) = _mem8( &stat.rx_drop_hash ) + 1;
              #endif
              break;
            }

            avg_message = msg_alloc( length, mctx.pipe );
            avg_offset = 0;

            if( avg_message == NULL )
            {
              #ifdef NEED_STAT
              _mem8( &stat.rx_drop_mem ) = _mem8( &stat.rx_drop_mem ) + 1;
              #endif
              break;
            }

            avg_message->from = from;
            avg_message->to = to;
          }
          break;

          case FRAME_FRAGMENT:
          {
            uint32 length;

            if( drv_read( mcbsp_rd, &length, sizeof(uint32) ) != sizeof(uint32) ) { state = S_SYN_FAIL; break; }

            if( avg_message )
            {
              if( drv_read( mcbsp_rd, (char*)avg_message->data + avg_offset, length ) != length ) { state = S_SYN_FAIL; break; }
              if( drv_read( mcbsp_rd, &rc32, sizeof(uint32) ) != sizeof(uint32) ) { state = S_SYN_FAIL; break; }

              c16 = cry_crc16( &length, sizeof(uint32), 0 );
              c32 = (uint32)cry_crc16( (char*)avg_message->data + avg_offset, length, c16 );
              
              if( c32 != rc32 )
              {
                msg_free( avg_message );
                avg_message = NULL;
                #ifdef NEED_STAT
                _mem8( &stat.rx_drop_hash ) = _mem8( &stat.rx_drop_hash ) + 1;
                #endif
                break;
              }

              avg_offset += length;
              
              if( avg_message->length == avg_offset )
              {
                #ifdef NEED_STAT
                _mem8( &stat.rx_count ) = _mem8( &stat.rx_count ) + 1;
                _mem8( &stat.rx_bytes ) = _mem8( &stat.rx_bytes ) + (uint64)avg_message->length;
                #endif
                msg_queue_push( mctx.inq, avg_message );
                avg_message = NULL;
              }
            }
            else
            {
              bool t = false;
              for( r = length >> 2; r > 0 ; r-- )
              {
                if( drv_read( mcbsp_rd, &frame, 4 ) != 4 ) { t = true; state = S_SYN_FAIL; break; }
              }
              if( t ) break;
              if( length & 3 )
              {
                if( drv_read( mcbsp_rd, &frame, length & 3 ) != ( length & 3 ) ) { state = S_SYN_FAIL; break; }
              }
            }

            frame = FRAME_ACK;
            sem_lock( tx_sem, SEM_INFINITY );
            drv_write( mcbsp_wr, &frame, sizeof(frame) );
            sem_unlock( tx_sem );
          }
          break;
        }
      }
      break;

      case S_SYN_FAIL:
      {
        syn_fail();
      }
      break;
    }
  
  }

  return 0;
}
// ---------------------------------------------------------------------------
int32 ipmp_mcbsp_open( s_os_driver_descriptor* d, uint16 access )
{
  return -1;
}
// ---------------------------------------------------------------------------
int32 ipmp_mcbsp_close( s_os_driver_descriptor* d )
{
  return -1;
}
// ---------------------------------------------------------------------------
int32 ipmp_mcbsp_read( s_os_driver_descriptor* d, void* buf, int32 length )
{
  return -1;
}
// ---------------------------------------------------------------------------
int32 ipmp_mcbsp_write( s_os_driver_descriptor* d, const void* buf, int32 length )
{
  return -1;
}
//---------------------------------------------------------------------------
int32 ipmp_mcbsp_ioctl( s_os_driver_descriptor* d, int32 cmd, const void* arg )
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

      send_sem = RES_VOID;
      tx_sem = RES_VOID;
      terminate = false;
      connect_sended = false;
      have_remote_side = false;
      state = S_WAIT0;
      #ifdef NEED_STAT
      memset( &stat, 0, sizeof(stat) );
      #endif
      memset( &outq, 0, sizeof(outq) );
      memset( &mctx, 0, sizeof(mctx) );
      mcbsp_rd = RES_VOID;
      mcbsp_wr = RES_VOID;
      rx_process = 0;
      tx_process = 0;
      avg_message = NULL;
      avg_offset = 0;

      if( ( r = msg_queue_init( &outq ) ) != OSE_OK ) return r;
      mctx.outq = &outq;
      
      mcbsp_rd = drv_mkd( mcbsp_device );
      mcbsp_wr = drv_mkd( mcbsp_device );
      if( ( mcbsp_rd == RES_VOID ) || ( mcbsp_wr == RES_VOID ) ) { r = OSE_NO_DEVICE; goto l_fail; }
      res_share( mcbsp_rd );
      res_share( mcbsp_wr );

      send_sem = sem_alloc( 6, NULL );
      tx_sem = sem_alloc( 1, NULL );
      if( ( send_sem == RES_VOID ) || ( tx_sem == RES_VOID ) ) { r = OSE_CANT_CREATE_SEM; goto l_fail; }

      memset( &pattr, 0, sizeof(pattr) );
      pattr.stack = 1024;
      rx_process = prc_create( &ipmp_mcbsp_rx_process, NULL, 0, &pattr );
      tx_process = prc_create( &ipmp_mcbsp_tx_process, NULL, 0, &pattr );
      if( ( rx_process <= 0 ) || ( tx_process <= 0 ) )
      {
        r = OSE_CANT_CREATE_PROCESS;
        goto l_fail;
      }

      if( ( r = msg_regpipe( &mctx, 8 ) ) != OSE_OK ) goto l_fail;

      state = S_WAIT1;
      while( state != S_ESTABLISHED ) sleep_m( 1 );
      
      break;

    l_fail:

      terminate = true;
      sem_unlock( outq.count_sem );
      if( rx_process > 0 ) prc_join( rx_process );
      if( tx_process > 0 ) prc_join( tx_process );
      msg_queue_deinit( &outq );
      sem_free( send_sem );
      sem_free( tx_sem );
      drv_rmd( mcbsp_rd );
      drv_rmd( mcbsp_wr );

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
      sem_free( tx_sem );
      drv_rmd( mcbsp_rd );
      drv_rmd( mcbsp_wr );
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

    case IPMP_SET_SYNFAIL_CALLBACK:
    {
      synfail_callback = (void(*)())(uint32)const_cast<void*>( arg );
    }
    break;

    default:
      return OSE_BAD_CMD;
  }

  return OSE_OK;
}
//---------------------------------------------------------------------------
int32 drv_ipmp_mcbsp_plug( const char* path )
{
  return drv_plug( path, INOT_FILE, &ipmp_mcbsp_open, &ipmp_mcbsp_close, &ipmp_mcbsp_read, &ipmp_mcbsp_write, &ipmp_mcbsp_ioctl, NULL, 0 );
}
//---------------------------------------------------------------------------
int32 drv_ipmp_mcbsp_unplug( const char* name )
{
  return drv_unplug( name );
}
//---------------------------------------------------------------------------
