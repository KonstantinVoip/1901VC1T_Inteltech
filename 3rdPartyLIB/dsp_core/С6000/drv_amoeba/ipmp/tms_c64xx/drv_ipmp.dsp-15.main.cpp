#include <drv_ipmp.dsp-15.h>
#include <drv_gpio.h>
#include <rts.h>
// ---------------------------------------------------------------------------
//#define NEED_STAT
// ---------------------------------------------------------------------------

#define C_PLIS_LENGTH           959128

// ---------------------------------------------------------------------------

#define S_WAIT                  0
#define S_CONNECT               1
#define S_EXCHANGE              2
#define S_CONTINUE              3

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

struct s_dsp15_context
{
  #ifdef NEED_STAT
  s_ipmp_stat                   stat;
  #endif
  int32                         rx_process;
  int32                         tx_process;
  int32                         state;
  uint32                        n;
  uint32                        rx;
  uint32                        tx;
  uint32                        rxf;
  uint32                        txf;
  s_message*                    avg_message;
  s_message_queue               outq;
  s_message_context             mctx;
  uint32                        send_sem;
  bool                          terminate;
};

// ---------------------------------------------------------------------------
static void wait_plis()
{
  while( true )
  {
    if( REG_M_RFLAG_PORT0 == 0xffffffff ) continue;
    break;
  }
  sleep_m( 100 );
}
// ---------------------------------------------------------------------------
static uint32 recv_4b( s_dsp15_context* ctx )
{
  register volatile uint32 flag_val;
  register volatile uint32 ret_val;

  int32 i = 0;
  if( ctx->terminate ) return 0;
  while( true )
  {
    flag_val = (*(uint32*)ctx->rxf);//������ ���� ���������� ������

    if( flag_val == 0xffffffff ) goto l_idle;
    if( flag_val == F_M_RXR ) break;//��������� ���� ���������� ������
  l_idle:
    if( ctx->terminate ) return 0;
    i++;
    if( i == 2 )
    {
      i = 0;
      prc_yield();
    }
  }

  ret_val = (*(uint32*)ctx->rx);//������ ������

  (*(uint32*)ctx->rxf) = 0;//���������� ���� ���������� ������

  return ret_val;
}
// ---------------------------------------------------------------------------
static void send_4b( s_dsp15_context* ctx, uint32 w )
{
  register volatile uint32 flag_val;
  int32 i = 0;
  if( ctx->terminate ) return;
  while( true )
  {
    flag_val = (*(uint32*)ctx->txf);//������ ���� ����������� ������

    if( flag_val == 0xffffffff ) goto l_idle;
    if( ( flag_val == F_M_TXR ) ) break;//��������� ���� ����������� ������
  l_idle:
    if( ctx->terminate ) return;
    i++;
    if( i == 2 )
    {
      i = 0;
      prc_yield();
    }
  }

  (*(uint32*)ctx->tx)  = w;//���������� ������ � �������
  (*(uint32*)ctx->txf) = 1;//���������� ���� � ������� ������ ��� ��

  // Waiting (1 fpga bus takt) for 33ns (for 720MHz CPU)
  asm( " nop 9 " );
  asm( " nop 9 " );
  asm( " nop 6 " );
}

/*****************************************************************************
Syntax:     static int32 ipmp_dsp15_load_plis( const void* arg ) 	    
Remarks:	Load FPGA		    
*******************************************************************************/
static int32 ipmp_dsp15_load_plis( const void* arg )
{
  int32 r;
  uint32 d;
  s_gpio_load_plis lplis;

  if( ( d = drv_mkd( "/dev/gpio" ) ) == RES_VOID )
  {
  return OSE_NO_DEVICE;  // -2   OSE_NO_DEVICE
  }
  

  lplis.data = const_cast<void*>( arg );
  lplis.size = C_PLIS_LENGTH;
  lplis.gpio_prog = 15;
  lplis.gpio_init = 12;
  lplis.gpio_clk = 14;
  lplis.gpio_dout = 13;
  lplis.gpio_done = 11;
  r = drv_ioctl( d, GPIO_LOAD_PLIS, &lplis );

  drv_rmd( d );

  return r;
}
// ---------------------------------------------------------------------------
static int ipmp_dsp15_tx_process( void* arg )
{
  s_dsp15_context* ctx = (s_dsp15_context*)(*(uint32*)arg);
  bool connect_sended = false;
  s_message* m;
  register uint32* dp;
  uint32 c32, i, l;
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
          send_4b( ctx, FRAME_NUMBER );
          send_4b( ctx, ctx->n );
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

        dp = (uint32*)m->data;

        c16 = cry_crc16( &m->from, sizeof(uint32), 0 );
        c16 = cry_crc16( &m->to, sizeof(uint32), c16 );
        c16 = cry_crc16( &m->length, sizeof(uint32), c16 );
        c32 = (uint32)cry_crc16( m->data, m->length, c16 );

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

        send_4b( ctx, FRAME_PACKET );
        send_4b( ctx, m->from );
        send_4b( ctx, m->to );
        send_4b( ctx, m->length );
        for( i = 0, l = m->length >> 2; i < l; i++, dp++ ) send_4b( ctx, (*dp) );
        if( m->length & 3 )
        {
          l = 0;
          memcpy( &l, dp, m->length & 3 );
          send_4b( ctx, l );
        }
        send_4b( ctx, c32 );

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
static int ipmp_dsp15_rx_process( void* arg )
{
  s_dsp15_context* ctx = (s_dsp15_context*)(*(uint32*)arg);
  uint32 frame, d;
  
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
        if( recv_4b( ctx ) != FRAME_NUMBER_ACK ) break;
        ctx->state = S_EXCHANGE;
      }
      break;

      case S_EXCHANGE:
      {
        frame = recv_4b( ctx );

        switch( frame )
        {
          case FRAME_PACKET:
          {
            uint32 length, from, to;
            uint32 i, l, rc32, c32;
            register uint32* dp;
            uint16 c16;

            from = recv_4b( ctx );
            to = recv_4b( ctx );
            length = recv_4b( ctx );

            if( ( ctx->avg_message = msg_alloc( (int32)length, ctx->mctx.pipe ) ) != NULL )
            {
              register s_message* m = ctx->avg_message;
              dp = (uint32*)m->data;

              m->from = from;
              m->to = to;
              for( i = 0, l = ( length >> 2 ); i < l; i++, dp++ ) (*dp) = recv_4b( ctx );
              if( length & 3 )
              {
                d = recv_4b( ctx );
                memcpy( dp, &d, length & 3 );
              }
              rc32 = recv_4b( ctx );

              c16 = cry_crc16( &from, sizeof(uint32), 0 );
              c16 = cry_crc16( &to, sizeof(uint32), c16 );
              c16 = cry_crc16( &length, sizeof(uint32), c16 );
              c32 = (uint32)cry_crc16( m->data, length, c16 );
              
              if( rc32 == c32 )
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
                // todo: syslog
                msg_free( ctx->avg_message );
                ctx->avg_message = NULL;
                #ifdef NEED_STAT
                syn_begin();
                _mem8( &ctx->stat.rx_drop_hash ) = _mem8( &ctx->stat.rx_drop_hash ) + 1;
                syn_end();
                #endif
              }
            }
            else
            {
              // todo: syslog
              for( i = 0, l = length >> 2; i < l; i++ ) recv_4b( ctx );
              if( length & 3 ) recv_4b( ctx );
              recv_4b( ctx );
              #ifdef NEED_STAT
              syn_begin();
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

          case FRAME_RESET:
          {
            while( true )
              asm( " nop " );
          }
        }
      }
      break;

      case S_CONTINUE:
      {
        if( recv_4b( ctx ) == FRAME_CONTINUE_ACK )
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
int32 ipmp_dsp15_main_open( s_os_driver_descriptor* d, uint16 access )
{
  return -1;
}
// ---------------------------------------------------------------------------
int32 ipmp_dsp15_main_close( s_os_driver_descriptor* d )
{
  return -1;
}
// ---------------------------------------------------------------------------
int32 ipmp_dsp15_main_read( s_os_driver_descriptor* d, void* buf, int32 length )
{
  return -1;
}
// ---------------------------------------------------------------------------
int32 ipmp_dsp15_main_write( s_os_driver_descriptor* d, const void* buf, int32 length )
{
  return -1;
}
//---------------------------------------------------------------------------
int32 ipmp_dsp15_main_ioctl( s_os_driver_descriptor* d, int32 cmd, const void* arg )
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
      s_dsp15_context* ctx = (s_dsp15_context*)dctx->data;
      uint32 prcd;

      ctx->state = S_WAIT;
      ctx->terminate = false;
      ctx->send_sem = RES_VOID;

      if( ( ctx->send_sem = sem_alloc( 1, NULL ) ) == RES_VOID ) { r = OSE_CANT_CREATE_SEM; goto l_fail; }
      if( ( r = msg_queue_init( &ctx->outq ) ) != OSE_OK ) goto l_fail;

      wait_plis();

      memset( &pattr, 0, sizeof(pattr) );
      pattr.stack = 512;
      prcd = (uint32)ctx;
      ctx->rx_process = prc_create( &ipmp_dsp15_rx_process, &prcd, sizeof(uint32), &pattr );
      ctx->tx_process = prc_create( &ipmp_dsp15_tx_process, &prcd, sizeof(uint32), &pattr );

      if( ( ctx->rx_process <= 0 ) || ( ctx->tx_process <= 0 ) ) { r = OSE_CANT_CREATE_PROCESS; goto l_fail; }

      ctx->mctx.outq = &ctx->outq;
      if( ( r = msg_regpipe( &ctx->mctx, 4 ) ) != OSE_OK ) goto l_fail;

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
      s_dsp15_context* ctx = (s_dsp15_context*)dctx->data;
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
      s_dsp15_context* ctx = (s_dsp15_context*)d->ctx->data;
      s_ipmp_stat* s = (s_ipmp_stat*)const_cast<void*>( arg );
      syn_begin();
      memcpy( s, &ctx->stat, sizeof(s_ipmp_stat) );
      syn_end();
    }
    break;
    #endif

    case IPMP_PAUSE:
    {
      s_dsp15_context* ctx = (s_dsp15_context*)d->ctx->data;
      sem_lock( ctx->send_sem, SEM_INFINITY );
      send_4b( ctx, FRAME_PAUSE );
      while( ctx->state != S_WAIT ) prc_yield();
      sem_unlock( ctx->send_sem );
    }
    break;
    
    case IPMP_CONTINUE:
    {
      s_dsp15_context* ctx = (s_dsp15_context*)d->ctx->data;
      sem_lock( ctx->send_sem, SEM_INFINITY );
      wait_plis();
      ctx->state = S_CONTINUE;
      send_4b( ctx, FRAME_CONTINUE );
      while( ctx->state != S_EXCHANGE ) prc_yield();
      sem_unlock( ctx->send_sem );
    }
    break;

    case IPMP_LOAD_PLIS:
    {
      if( arg == NULL ) return OSE_NULL_PARAM;
      s_dsp15_context* ctx = (s_dsp15_context*)d->ctx->data;
      int32 r;

      sem_lock( ctx->send_sem, SEM_INFINITY );
      r = ipmp_dsp15_load_plis( arg );
      sem_unlock( ctx->send_sem );

      return r;
    }

    default:
      return OSE_BAD_CMD;
  }

  return OSE_OK;
}


/*****************************************************************************
Syntax:   int32 drv_ipmp_dsp15_plug( const char* path, uint32 comm_n )   	    
Remarks:			    
*******************************************************************************/
int32 drv_ipmp_dsp15_plug( const char* path, uint32 comm_n )
{
  s_dsp15_context ctx;

  if( comm_n == 0 )
  {
    uint32 d = drv_mkd( "/vfat/a/sv5.bin" );
    if( d == RES_VOID ) 
    {
    return OSE_NO_DEVICE;            //-2
    }
    if( drv_open( d, DRV_RD ) != OSE_OK )
    {
      drv_rmd( d );
      return OSE_PERMISSION_DENIED; //-35
    }
    s_os_mem_block* block = mem_alloc( C_PLIS_LENGTH, 1 );
    if( block == NULL )
    {
      drv_rmd( d );
      return OSE_NO_MEMORY;         //-1
    }
    void* ptr = mem_ptr( block );
    int32 res = drv_read( d, ptr, C_PLIS_LENGTH );
    drv_rmd( d );
    if( res != C_PLIS_LENGTH )
    {
      mem_free( block );
      return OSE_NOT_ENOUGHT_DATA; //-55
    }
	
	//while(1)
    res = ipmp_dsp15_load_plis( ptr );
    mem_free( block );
    if( res != OSE_OK ) return res;
    // determine processor number for plis
    while( REG_M_RFLAG_PORT0 == 0xffffffff );
    REG_M_DEVINDEX = ( REG_CTL0 & TCTL_DATIN ) ? 0 : 1;
  
  } //end if

	//debug!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//return;

  memset( &ctx, 0, sizeof(ctx) );
  ctx.n = comm_n;
  if( comm_n == 0 )
  {
    ctx.rx  = ADR_M_RX_PORT0;
    ctx.tx  = ADR_M_TX_PORT0;
    ctx.txf = ADR_M_WFLAG_PORT0;
    ctx.rxf = ADR_M_RFLAG_PORT0;
  }
  else if( comm_n == 1 )
  {
    ctx.rx  = ADR_M_RX_PORT1;
    ctx.tx  = ADR_M_TX_PORT1;
    ctx.txf = ADR_M_WFLAG_PORT1;
    ctx.rxf = ADR_M_RFLAG_PORT1;
  }
  else
  {
    return OSE_BAD_PARAM;             //-4
  }

  return drv_plug( path, INOT_FILE, &ipmp_dsp15_main_open, &ipmp_dsp15_main_close, &ipmp_dsp15_main_read, &ipmp_dsp15_main_write, &ipmp_dsp15_main_ioctl, &ctx, sizeof(ctx) );
}
// ---------------------------------------------------------------------------
int32 drv_ipmp_dsp15_unplug( const char* name )
{
  return drv_unplug( name );
}
// ---------------------------------------------------------------------------
