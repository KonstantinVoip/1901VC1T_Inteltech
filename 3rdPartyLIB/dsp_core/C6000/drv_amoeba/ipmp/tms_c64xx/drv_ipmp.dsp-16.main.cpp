/**********************************************************************************************************************
*                                        (c) COPYRIGHT by ZAO RCZI FORT.                                             *
*        ..                                       All rights reserved.                                               *
***********************************************************************************************************************
* Module      : drv_ipmp.dsp-16.main.cpp
* Description : 
* Author      : 
******************************************************************************
******************************************************************************
* Module's Description Record:
* ============================
* Module's revision history:
* ==========================
* --------- $Log: mpcdrvlbcCyclone.h $
* --------- Initial revision
******************************************************************************/
#include <drv_ipmp.dsp-16.h>
#include <drv_gpio.h>
#include <rts.h>

#ifdef HAVE_ARAMEC
	#include <ARAM_Exchange_main.h>
#endif
// ---------------------------------------------------------------------------
//#define NEED_STAT
// ---------------------------------------------------------------------------

#define C_ALFA2006              0x414c464132303036
#define C_GOST2006              0x474f535432303036
#define C_PLIS_LENGTH           3640576

// ---------------------------------------------------------------------------

#define S_WAIT                  0
#define S_CONNECT               1
#define S_EXCHANGE              2
#define S_CONTINUE              3

// ---------------------------------------------------------------------------

#define FRAME_PACKET            0x0013223113223100
#define FRAME_PAUSE             0x1124334224334211
#define FRAME_CONTINUE          0x2235445335445322
#define FRAME_PAUSE_ACK         0x3346556446556433
#define FRAME_CONTINUE_ACK      0x4457667557667544
#define FRAME_NUMBER            0x5568778668778655
#define FRAME_NUMBER_ACK        0x6679889779889766

// ---------------------------------------------------------------------------

#define VREG64( a )             (*(volatile uint64*)(a))
#define REG_DATA( ctx )         VREG64( ctx->data_port )
#define REG_FLAG( ctx )         VREG64( ctx->flag_port )

#define TXR                     0x0000000000000001
#define RXR                     0x0000000000000002

// ---------------------------------------------------------------------------

struct s_dsp_context
{
  #ifdef NEED_STAT
  s_ipmp_stat                   stat;
  #endif
  int32                         rx_process;
  int32                         tx_process;
  int32                         state;
  uint32                        n;
  uint32                        data_port;
  uint32                        flag_port;
  s_message*                    avg_message;
  s_message_queue               outq;
  s_message_context             mctx;
  uint32                        send_sem;
  bool                          terminate;
};

// ---------------------------------------------------------------------------
static int32 ipmp_dsp16_load_plis( const void* arg )
{
  int32 r;
  uint32 d;
  s_gpio_load_plis lplis;

  if( ( d = drv_mkd( "/dev/gpio" ) ) == RES_VOID ) return OSE_NO_DEVICE;

  lplis.data = const_cast<void*>( arg );
  lplis.size = C_PLIS_LENGTH;
  r = drv_ioctl( d, GPIO_LOAD_PLIS, &lplis );

  drv_rmd( d );

  return r;
}
// ---------------------------------------------------------------------------
static void wait_plis()
{
  while( true )
  {                              
    uint64 rval = VREG64( 0xb0007ff8 );
    if( rval == C_GOST2006 ) break;
    if( rval == C_ALFA2006 ) break;
    prc_yield();
  }
}
// ---------------------------------------------------------------------------
static uint64 recv_8b( s_dsp_context* ctx )
{
  while( !( REG_FLAG( ctx ) & RXR ) )
  {
    if( ctx->terminate ) return 0llu;
    prc_yield();
  }
  return REG_DATA( ctx );
}
// ---------------------------------------------------------------------------
static void send_8b( s_dsp_context* ctx, uint64 w )
{
  while( REG_FLAG( ctx ) & TXR )
  {
    if( ctx->terminate ) return;
    prc_yield();
  }
  REG_DATA( ctx ) = w;
  REG_FLAG( ctx ) = TXR;
  // 33ns delay
  asm( " nop 9 " );
  asm( " nop 9 " );
  asm( " nop 6 " );
}
uint32 dbg_pop_queue = 0;
// ---------------------------------------------------------------------------
static int ipmp_dsp16_tx_process( void* arg )
{
  s_dsp_context* ctx = (s_dsp_context*)(*(uint32*)arg);
  bool connect_sended = false;
  s_message* m;
  register uint64* dp;
  uint64 t;
  uint32 i, l;
  uint16 c16;
  
  while( !ctx->terminate )
  {
    switch( ctx->state )
    {
      case S_WAIT:
      {
        sleep_m( 1 );
      }
      break;
    
      case S_CONNECT:
      {
        if( !connect_sended )
        {
          send_8b( ctx, FRAME_NUMBER );
          send_8b( ctx, (uint64)ctx->n );
          connect_sended = true;
        }
        else
        {
          sleep_m( 1 );
        }
      }
      break;
    
      case S_EXCHANGE:
      {
        if( msg_queue_pop( &ctx->outq, &m, SEM_INFINITY ) != OSE_OK ) break;
        if( m == NULL ) break;
        dbg_pop_queue++;
        dp = (uint64*)m->data;

        c16 = cry_crc16( &m->from, sizeof(uint32), 0 );
        c16 = cry_crc16( &m->to, sizeof(uint32), c16 );
        c16 = cry_crc16( &m->length, sizeof(uint32), c16 );
        c16 = cry_crc16( m->data, m->length, c16 );

      l_relock:

        sem_lock( ctx->send_sem, SEM_INFINITY );
        if( ctx->state != S_EXCHANGE )
        {
          sem_unlock( ctx->send_sem );
          while( ctx->state != S_EXCHANGE )
          {
            if( ctx->terminate ) break;
            sleep_m( 1 );
          }
          if( ctx->terminate ) break;
          goto l_relock;
        }

        send_8b( ctx, FRAME_PACKET );
        send_8b( ctx, (uint64)m->from );
        send_8b( ctx, (uint64)m->to );
        send_8b( ctx, (uint64)m->length );
        for( i = 0, l = m->length >> 3; i < l; i++, dp++ ) send_8b( ctx, _mem8( dp ) );
        if( m->length & 7 )
        {
          t = 0;
          memcpy( &t, dp, m->length & 7 );
          send_8b( ctx, t );
        }
        send_8b( ctx, (uint64)c16 );

        sem_unlock( ctx->send_sem );

        #ifdef NEED_STAT
        syn_begin();
        _mem8( &ctx->stat.tx_count ) = _mem8( &ctx->stat.tx_count ) + 1;
        _mem8( &ctx->stat.tx_bytes ) = _mem8( &ctx->stat.tx_bytes ) + (uint64)m->length;
        syn_end();
        #endif

        msg_free( m );
      }
      break;

      case S_CONTINUE:
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
  s_dsp_context* ctx = (s_dsp_context*)(*(uint32*)arg);
  uint64 frame, d;
  
  while( !ctx->terminate )
  {
    switch( ctx->state )
    {
      case S_WAIT:
      {
        sleep_m( 1 );
      }
      break;

      case S_CONNECT:
      {
        if( recv_8b( ctx ) != FRAME_NUMBER_ACK ) break;
        ctx->state = S_EXCHANGE;
      }
      break;

      case S_EXCHANGE:
      {
        frame = recv_8b( ctx );

        switch( frame )
        {
          case FRAME_PACKET:
          {
            uint32 length, from, to, i, l;
            register uint64* dp;
            uint16 c16, rc16;

            from = (uint32)recv_8b( ctx );
            to = (uint32)recv_8b( ctx );
            length = (uint32)recv_8b( ctx );

            if( ( ctx->avg_message = msg_alloc( (int32)length, ctx->mctx.pipe ) ) != NULL )
            {
              register s_message* m = ctx->avg_message;
              dp = (uint64*)m->data;

              m->from = from;
              m->to = to;
              for( i = 0, l = ( length >> 3 ); i < l; i++, dp++ ) _mem8( dp ) = recv_8b( ctx );
              if( length & 7 )
              {
                d = recv_8b( ctx );
                memcpy( dp, &d, length & 7 );
              }
              rc16 = (uint16)recv_8b( ctx );

              c16 = cry_crc16( &from, sizeof(uint32), 0 );
              c16 = cry_crc16( &to, sizeof(uint32), c16 );
              c16 = cry_crc16( &length, sizeof(uint32), c16 );
              c16 = cry_crc16( m->data, length, c16 );
              
              if( rc16 == c16 )
              {
                #ifdef NEED_STAT
                syn_begin();
                _mem8( &ctx->stat.rx_count ) = _mem8( &ctx->stat.rx_count ) + 1;
                _mem8( &ctx->stat.rx_bytes ) = _mem8( &ctx->stat.rx_bytes ) + (uint64)ctx->avg_message->length;
                syn_end();
                #endif
                msg_queue_push( ctx->mctx.inq, ctx->avg_message );
                ctx->avg_message = NULL;
              }
              else
              {
                msg_free( ctx->avg_message );
                ctx->avg_message = NULL;
                #ifdef NEED_STAT
                syn_begin();
                _mem8( &ctx->stat.rx_drop ) = _mem8( &ctx->stat.rx_drop ) + 1;
                _mem8( &ctx->stat.rx_drop_hash ) = _mem8( &ctx->stat.rx_drop_hash ) + 1;
                syn_end();
                #endif
              }
            }
            else
            {
              for( i = 0, l = length >> 3; i < l; i++ ) recv_8b( ctx );
              if( length & 7 ) recv_8b( ctx );
              recv_8b( ctx );
              #ifdef NEED_STAT
              syn_begin();
              _mem8( &ctx->stat.rx_drop ) = _mem8( &ctx->stat.rx_drop ) + 1;
              _mem8( &ctx->stat.rx_drop_mem ) = _mem8( &ctx->stat.rx_drop_mem ) + 1;
              syn_end();
              #endif
            }
          }
          break;

          case FRAME_PAUSE_ACK:
          {
            ctx->state = S_WAIT;
          }
          break;
          
          default:
          {
            #ifdef NEED_STAT
            syn_begin();
            _mem8( &ctx->stat.rx_drop ) = _mem8( &ctx->stat.rx_drop ) + 1;
            syn_end();
            #endif
          }
          break;
        }
      }
      break;

      case S_CONTINUE:
      {
        if( recv_8b( ctx ) == FRAME_CONTINUE_ACK )
        {
          ctx->state = S_EXCHANGE;
        }
        else
        {
          sleep_m( 1 );
        }
      }
      break;
    }
  }

  return 0;
}
// ---------------------------------------------------------------------------
int32 ipmp_dsp16_main_open( s_os_driver_descriptor* d, uint16 access )
{
  return -1;
}
// ---------------------------------------------------------------------------
int32 ipmp_dsp16_main_close( s_os_driver_descriptor* d )
{
  return -1;
}
// ---------------------------------------------------------------------------
int32 ipmp_dsp16_main_read( s_os_driver_descriptor* d, void* buf, int32 length )
{
  return -1;
}
// ---------------------------------------------------------------------------
int32 ipmp_dsp16_main_write( s_os_driver_descriptor* d, const void* buf, int32 length )
{
  return -1;
}
//---------------------------------------------------------------------------
int32 ipmp_dsp16_main_ioctl( s_os_driver_descriptor* d, int32 cmd, const void* arg )
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
      s_os_driver_context* dctx = (s_os_driver_context*)const_cast<void*>( arg );
      s_dsp_context* ctx = (s_dsp_context*)dctx->data;
      uint32 prcd;

      ctx->state = S_WAIT;
      ctx->terminate = false;
      ctx->send_sem = RES_VOID;

      if( ( ctx->send_sem = sem_alloc( 1, NULL ) ) == RES_VOID ) { r = OSE_CANT_CREATE_SEM; goto l_fail; }
      if( ( r = msg_queue_init( &ctx->outq ) ) != OSE_OK ) goto l_fail;

      wait_plis();

      memset( &pattr, 0, sizeof(pattr) );
      pattr.stack = 512;
      pattr.priority = 1;
      prcd = (uint32)ctx;
      ctx->rx_process = prc_create( &ipmp_dsp16_rx_process, &prcd, sizeof(uint32), &pattr );
      ctx->tx_process = prc_create( &ipmp_dsp16_tx_process, &prcd, sizeof(uint32), &pattr );

      if( ( ctx->rx_process <= 0 ) || ( ctx->tx_process <= 0 ) ) { r = OSE_CANT_CREATE_PROCESS; goto l_fail; }

      ctx->mctx.outq = &ctx->outq;
      if( ( r = msg_regpipe( &ctx->mctx, 8 ) ) != OSE_OK ) goto l_fail;//4

      ctx->state = S_CONNECT;
      while( ctx->state != S_EXCHANGE ) prc_yield();

      break;

    l_fail:

      ctx->terminate = true;
      sem_unlock( ctx->outq.count_sem );
      if( ctx->rx_process > 0 ) prc_join( ctx->rx_process );
      if( ctx->tx_process > 0 ) prc_join( ctx->tx_process );
      msg_queue_deinit( &ctx->outq );
      sem_free( ctx->send_sem );

      return r;
    }

    case IOC_DEINIT:
    {
      s_os_driver_context* dctx = (s_os_driver_context*)const_cast<void*>( arg );
      s_dsp_context* ctx = (s_dsp_context*)dctx->data;
      ctx->terminate = true;
      sem_unlock( ctx->outq.count_sem );
      if( ctx->rx_process > 0 ) prc_join( ctx->rx_process );
      if( ctx->tx_process > 0 ) prc_join( ctx->tx_process );
      msg_queue_deinit( &ctx->outq );
      sem_free( ctx->send_sem );
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
      s_dsp_context* ctx = (s_dsp_context*)d->ctx->data;
      s_ipmp_stat* s = (s_ipmp_stat*)const_cast<void*>( arg );
      syn_begin();
      memcpy( s, &ctx->stat, sizeof(s_ipmp_stat) );
      syn_end();
    }
    break;
    #endif

    case IPMP_PAUSE:
    {
      #ifdef HAVE_ARAMEC
      LockARAMExchange();
      #endif
      s_dsp_context* ctx = (s_dsp_context*)d->ctx->data;
      sem_lock( ctx->send_sem, SEM_INFINITY );
      send_8b( ctx, FRAME_PAUSE );
      while( ctx->state != S_WAIT ) prc_yield();
      sem_unlock( ctx->send_sem );
    }
    break;
    
    case IPMP_CONTINUE:
    {
      s_dsp_context* ctx = (s_dsp_context*)d->ctx->data;
      sem_lock( ctx->send_sem, SEM_INFINITY );
      wait_plis();
      ctx->state = S_CONTINUE;
      send_8b( ctx, FRAME_CONTINUE );
      while( ctx->state != S_EXCHANGE ) prc_yield();
      sem_unlock( ctx->send_sem );
      #ifdef HAVE_ARAMEC
      UnlockARAMExchange();
      #endif
    }
    break;

    case IPMP_LOAD_PLIS:
    {
      if( arg == NULL ) return OSE_NULL_PARAM;
      s_dsp_context* ctx = (s_dsp_context*)d->ctx->data;
      int32 r;

      sem_lock( ctx->send_sem, SEM_INFINITY );
      r = ipmp_dsp16_load_plis( arg );
      sem_unlock( ctx->send_sem );

      return r;
    }

    default:
      return OSE_BAD_CMD;
  }

  return OSE_OK;

}
// ---------------------------------------------------------------------------
int32 drv_ipmp_dsp16_plug( const char* path, uint32 comm_n )
{
  s_dsp_context ctx;

  if( comm_n >= 3 ) return OSE_OUT_OF_A_RANGE;

  if( comm_n == 0 )
  {
    uint32 d = drv_mkd( "/vfat/a/sv6.bin" );
    if( d == RES_VOID ) return OSE_NO_DEVICE;
    if( drv_open( d, DRV_RD ) != OSE_OK )
    {
      drv_rmd( d );
      return OSE_PERMISSION_DENIED;
    }
    s_os_mem_block* block = mem_alloc( C_PLIS_LENGTH, 1 );
    if( block == NULL )
    {
      drv_rmd( d );
      return OSE_NO_MEMORY;
    }
    void* ptr = mem_ptr( block );
    int32 res = drv_read( d, ptr, C_PLIS_LENGTH );
    drv_rmd( d );
    if( res != C_PLIS_LENGTH )
    {
      mem_free( block );
      return OSE_NOT_ENOUGHT_DATA;
    }
    res = ipmp_dsp16_load_plis( ptr );
    mem_free( block );
    if( res != OSE_OK ) return res;
  }

  memset( &ctx, 0, sizeof(ctx) );
  ctx.n = comm_n;
  comm_n = 0x000000d0 + ( comm_n << 4 );
  ctx.flag_port = 0xa0007f00 | comm_n;
  ctx.data_port = 0xa0007f08 | comm_n;
  
  return drv_plug( path, INOT_FILE, &ipmp_dsp16_main_open, &ipmp_dsp16_main_close, &ipmp_dsp16_main_read, &ipmp_dsp16_main_write, &ipmp_dsp16_main_ioctl, &ctx, sizeof(ctx) );
}
// ---------------------------------------------------------------------------
int32 drv_ipmp_dsp16_unplug( const char* name )
{
  return drv_unplug( name );
}
// ---------------------------------------------------------------------------
