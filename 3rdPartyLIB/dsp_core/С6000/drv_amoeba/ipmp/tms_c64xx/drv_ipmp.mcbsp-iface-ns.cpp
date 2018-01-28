#include <rts.h>
#include <drv_ipmp.mcbsp.h>
// ---------------------------------------------------------------------------
//#define NEED_STAT
// ---------------------------------------------------------------------------

#define S_WAIT0                 0
#define S_WAIT1                 1
#define S_CONNECT               2
#define S_ESTABLISHED           3

// ---------------------------------------------------------------------------

#define FRAME_ACK               0x00132231
#define FRAME_PACKET            0x11243342
#define FRAME_FRAGMENT          0x22354453
#define FRAME_SIDE_RESPONSE     0x33465564
#define FRAME_CONNECT           0x44576675
#define FRAME_RESET             0xf0f00f0f

// ---------------------------------------------------------------------------
uint32 cmp_frame[FRAME_LENGTH/4];
// ---------------------------------------------------------------------------
uint32 ipmp_out_buf[FRAME_LENGTH/4];
// ---------------------------------------------------------------------------
void QDMA_ipmpRead(void* dst,void* src,uint16 len);
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

static uint32 send_sem;
static uint32 tx_sem;

static volatile bool terminate;
static volatile bool have_remote_side;
static volatile bool connect_sended;
static volatile int32 state;
static s_message_queue outq;
static s_message_context mctx;
static void (*synfail_callback)(int32) = NULL;
#ifdef NEED_STAT
s_ipmp_stat rs_ipmp_stat;
#endif

static uint32 mcbsp_rd0;
static uint32 mcbsp_rd1;
static uint32 mcbsp_wr;

static int32 rx_process;
static int32 tx_process;

static s_message* avg_message;
static int32 avg_offset;
static bool avg_spdrop;
static bool sparca_test;
// ---------------------------------------------------------------------------
/*
void DebugPin1(int32 value)
{
    register int is = int_disable();
    REG_GPEN |= (1<<12);
    REG_GPDIR |= (1<<12);
    if(value)
        REG_GPVAL |= (1<<12);
    else
        REG_GPVAL &= ~(1<<12);
    int_enable(is);
}*/
/*
void DebugPin2(int32 value)
{
    register int is = int_disable();
    REG_GPEN |= (1<<14);
    REG_GPDIR |= (1<<14);
    if(value)
        REG_GPVAL |= (1<<14);
    else
        REG_GPVAL &= ~(1<<14);
    int_enable(is);
}*/
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
//---------------------------------------------------------------------------
typedef uint64 cmp_unit;
//---------------------------------------------------------------------------
static int memcmp_xor(void* src1,void* src2,uint32 len)
{
register cmp_unit* s1=(cmp_unit*)src1;
register cmp_unit* s2=(cmp_unit*)src2;

uint32 l=len/sizeof(cmp_unit);

while(l--)
//	if(_amem4(s1++)^_amem4(s2++))
	if(_mem8(s1++)^_amem8(s2++))
		return 1;

uint32 ost=len&(sizeof(cmp_unit)-1);
if(ost)
	return memcmp(s1,s2,ost);

return 0;
}
//---------------------------------------------------------------------------
static bool recv_frame( char *frame, uint16 length, uint16 c16, uint32 *c32)
{
  drv_read(mcbsp_rd0,frame,length);  
  drv_read(mcbsp_rd1,cmp_frame,length);

  *c32 = (uint32)cry_crc16( (char*)cmp_frame, length, c16 );

  if(memcmp_xor(frame,cmp_frame,length) != 0)
  {
    return false;  
  }
  return true;
}
// ---------------------------------------------------------------------------
static bool recv_4b( uint32* v )
{
  uint32 c0, c1;

  volatile uint16 rd_retry = 1; 

  drv_read( mcbsp_rd0, &c0, 4 );//Чтение слова(4 байта) из порта mcbsp первого ЦП
  drv_read( mcbsp_rd1, &c1, 4 );//Чтение слова(4 байта) из порта mcbsp второго ЦП

compare:
  if( c0 != c1 )//Сравнение вычетанных значений из обоих ЦП
  {
    if(rd_retry)//Антидребезговая защита шины
    {
      rd_retry--;

      if(c0==0xFFFFFFFF)//
        drv_read( mcbsp_rd0, &c0, 4 );
      if(c1==0xFFFFFFFF)//
        drv_read( mcbsp_rd1, &c1, 4 );

      goto compare;
    }
    else
      return false;//Возвращение ошибки в случае не совпадения (Разбег спарки)
  }

  (*v) = ( c0 | c1 );//Заполнение выходного аргумента принятыми данными

  return true;//В случае успешного сравнения
}
// ---------------------------------------------------------------------------
static void send_4b( uint32 c )
{
  drv_write( mcbsp_wr, &c, 4 );
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
        sem_lock( tx_sem, SEM_INFINITY );
        send_4b( FRAME_SIDE_RESPONSE );
        sem_unlock( tx_sem );
        if( !have_remote_side ) sleep_m( 100 ); else state = S_CONNECT;
      }
      break;

      case S_CONNECT:
      {
        if( !connect_sended )
        {
          sem_lock( tx_sem, SEM_INFINITY );
          send_4b( FRAME_CONNECT );
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
        ipmp_frame_hdr frame_hdr;
        uint32 offset, length, clen;

        if( msg_queue_pop( &outq, &m, SEM_INFINITY ) != OSE_OK ) break;
        if( m == NULL ) break;

        c16 = cry_crc16( &m->from, sizeof(uint32), 0 );
        c16 = cry_crc16( &m->to, sizeof(uint32), c16 );
        c32 = (uint32)cry_crc16( &m->length, sizeof(uint32), c16 );
        frame = FRAME_PACKET;

        sem_lock( tx_sem, SEM_INFINITY );
        frame_hdr.frame  = frame;
        frame_hdr.from   = m->from;
        frame_hdr.to     = m->to;
        frame_hdr.length = m->length;
        frame_hdr.crc32  = c32;
        drv_write( mcbsp_wr, &frame_hdr, sizeof(frame_hdr) );
        sem_unlock( tx_sem );

        frame = FRAME_FRAGMENT;
        offset = 0;
        length = m->length;

        while( length )
        {
          sem_lock( send_sem, SEM_INFINITY );

          if( length >= FRAME_LENGTH ) clen = FRAME_LENGTH; else clen = length;
          c16 = cry_crc16( &clen, sizeof(uint32), 0 );
          QDMA_ipmpRead(ipmp_out_buf,(char*)m->data + offset,clen);
          c32 = (uint32)cry_crc16( ipmp_out_buf, clen, c16 );

          sem_lock( tx_sem, SEM_INFINITY );
          drv_write( mcbsp_wr, &frame, sizeof(uint32) );
          drv_write( mcbsp_wr, &clen, sizeof(uint32) );
          drv_write( mcbsp_wr, ipmp_out_buf, clen );
          drv_write( mcbsp_wr, &c32, sizeof(uint32) );
          sem_unlock( tx_sem );

          offset += clen;
          length -= clen;
        }

        #ifdef NEED_STAT
        _mem8( &rs_ipmp_stat.tx_count ) = _mem8( &rs_ipmp_stat.tx_count ) + 1;
        _mem8( &rs_ipmp_stat.tx_bytes ) = _mem8( &rs_ipmp_stat.tx_bytes ) + (uint64)m->length;
        #endif

        msg_free( m ); 
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
          if( !recv_4b( &frame ) ) { syn_fail( 1 ); break; }
          if( frame == FRAME_SIDE_RESPONSE ) have_remote_side = true;
        }
        else
        {
          sleep_m( 1 );
        }
      }
      break;

      case S_CONNECT:
      {
        if( !recv_4b( &frame ) ) { syn_fail( 1 ); break; }
        if( frame == FRAME_CONNECT )
        {
          while( !connect_sended ) sleep_m( 1 );
          state = S_ESTABLISHED;
        }
      }
      break;

      case S_ESTABLISHED:
      {
        if( !recv_4b( &frame ) ) { syn_fail( 1 ); break; }

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
            if( avg_spdrop )
            {
              avg_spdrop = false;
              if( sparca_test ) syn_fail( 0 ); else syn_fail( 1 );
            }

            if( !recv_4b( &from   ) ) { syn_fail( 1 ); break; }
            if( !recv_4b( &to     ) ) { syn_fail( 1 ); break; }
            if( !recv_4b( &length ) ) { syn_fail( 1 ); break; }
            if( !recv_4b( &rc32   ) ) { syn_fail( 1 ); break; }

            c16 = cry_crc16( &from, sizeof(uint32), 0 );
            c16 = cry_crc16( &to, sizeof(uint32), c16 );
            c32 = (uint32)cry_crc16( &length, sizeof(uint32), c16 );

            if( rc32 != c32 )
            {
              #ifdef NEED_STAT
              _mem8( &rs_ipmp_stat.rx_drop_hash ) = _mem8( &rs_ipmp_stat.rx_drop_hash ) + 1;
              #endif
              break;
            }

            avg_message = msg_alloc( length, mctx.pipe );
            avg_offset = 0;

            if( avg_message == NULL )
            {
              #ifdef NEED_STAT
              _mem8( &rs_ipmp_stat.rx_drop_mem ) = _mem8( &rs_ipmp_stat.rx_drop_mem ) + 1;
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

            if( !recv_4b( &length ) ) { syn_fail( 1 ); break; }

            c16 = cry_crc16( &length, sizeof(uint32), 0 );

            if( avg_message )
            {
              // Read frame data
              if(!recv_frame( (char*)avg_message->data+avg_offset,length, c16, &c32 ))
              {
                 if( sparca_test )
                 {
                   avg_spdrop = true;
                 }
                 else
                 {
                   syn_fail( 1 );
                 }
              }
              // Read CRC16
              if( !recv_4b( &rc32 ) )
              {
                if( !sparca_test )
                  syn_fail( 1 );
              }
              
              if( c32 != rc32 )
              {
                if( !sparca_test )
                {
                  msg_free( avg_message );
                  avg_message = NULL;
                  #ifdef NEED_STAT
                  _mem8( &rs_ipmp_stat.rx_drop_hash ) = _mem8( &rs_ipmp_stat.rx_drop_hash ) + 1;
                  #endif
                  break;
                }
              }

              avg_offset += length;
              
              if( avg_message->length == avg_offset )
              {
                if( avg_spdrop )
                {
                  avg_spdrop = false;
                  msg_free( avg_message );
                  avg_message = NULL;
                  if( sparca_test ) syn_fail( 0 ); else syn_fail( 1 );
                }
                else
                {
                  #ifdef NEED_STAT
                  _mem8( &rs_ipmp_stat.rx_count ) = _mem8( &rs_ipmp_stat.rx_count ) + 1;
                  _mem8( &rs_ipmp_stat.rx_bytes ) = _mem8( &rs_ipmp_stat.rx_bytes ) + (uint64)avg_message->length;
                  #endif
                  msg_queue_push( mctx.inq, avg_message );
                  avg_message = NULL;
                }
              }
            }
            else
            {
              r = length >> 2;
              if( r & 3 ) r++;
              while( r-- )
              {
                if( !recv_4b( &frame ) )
                {
                  if( sparca_test )
                  {
                    avg_spdrop = true;
                  }
                  else
                  {
                    syn_fail( 1 );
                  }
                }
              }
              if( avg_message->length == avg_offset )
              {
                if( avg_spdrop )
                {
                  avg_spdrop = false;
                  msg_free( avg_message );
                  avg_message = NULL;
                  if( sparca_test ) syn_fail( 0 ); else syn_fail( 1 );
                }
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

      memset(ipmp_out_buf,0,sizeof(ipmp_out_buf));

      #ifdef NEED_STAT
      memset( &rs_ipmp_stat, 0, sizeof(rs_ipmp_stat) );
      #endif
      memset( &outq, 0, sizeof(outq) );
      memset( &mctx, 0, sizeof(mctx) );
      mcbsp_rd0 = RES_VOID;
      mcbsp_rd1 = RES_VOID;
      mcbsp_wr = RES_VOID;
      rx_process = 0;
      tx_process = 0;
      avg_message = NULL;
      avg_offset = 0;
      avg_spdrop = false;
      sparca_test = false;

      if( ( r = msg_queue_init( &outq ) ) != OSE_OK ) return r;
      mctx.outq = &outq;
      
      mcbsp_rd0 = drv_mkd( "/dev/mcbsp/mcbsp_in1" );
      mcbsp_rd1 = drv_mkd( "/dev/mcbsp/mcbsp_in2" );
      mcbsp_wr = drv_mkd( "/dev/mcbsp/mcbsp_out" );
      if( ( mcbsp_rd0 == RES_VOID ) || ( mcbsp_rd1 == RES_VOID ) || ( mcbsp_wr == RES_VOID ) ) { r = OSE_NO_DEVICE; goto l_fail; }
      drv_open( mcbsp_rd0, DRV_RD );
      drv_open( mcbsp_rd1, DRV_RD );
      drv_open( mcbsp_wr, DRV_WR );
      res_share( mcbsp_rd0 );
      res_share( mcbsp_rd1 );
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
      drv_rmd( mcbsp_rd0 );
      drv_rmd( mcbsp_rd1 );
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
      drv_rmd( mcbsp_rd0 );
      drv_rmd( mcbsp_rd1 );
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
      memcpy( s, &rs_ipmp_stat, sizeof(s_ipmp_stat) );
    }
    break;
    #endif

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
void QDMA_ipmpRead(void* dst,void* src,uint16 len)
{
  uint16 l = len/4;
  int ost = len&0x3;

  if(l)
  {
    EDMA_intClear(5);
    EDMA_qdmaConfigArgs(0x01350000,(uint32)src,l,(uint32)dst,0);//Urgent priority 
    while(!EDMA_intTest(5));
  }
  if(ost)
    memcpy(((char*)dst+4*l),((char*)src+4*l),ost);
}
//---------------------------------------------------------------------------



