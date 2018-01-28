#include <rts.h>
#include "os_csl_mcbsp.h"
#include "drv_mcbsp.h"
#include "rs_circ_buf.h"

#define MCBSP_PORT_RECV      0
#define MCBSP_PORT_SEND      1

#define TCCINTNUM_XMIT      10
#define TCCINTNUM_RECV1     11
#define TCCINTNUM_RECV2     12

#define MCBSP_BUF_SIZE      1024//512// //размер буфера в uint32

MCBSP_Handle h_out;     
MCBSP_Handle h_in;

EDMA_Handle hEdmaOut;
EDMA_Handle hEdmaIn;
EDMA_Handle hEdmaInRld; /* Handle for the EDMA reload parameters  */

EDMA_Config cfgEdmaOut;
EDMA_Config cfgEdmaIn;
EDMA_Config cfgEdmaInRld;

uint32 rs_buf[MCBSP_BUF_SIZE];

circ_buf rs_in;

uint16 rs_count_out;
uint16 rs_count_in;

uint32 rs_send_sem;
uint32 rs_recv_sem;
uint32 edma_out_sem;

uint32 int_descriptor_edma;

uint32 mcbsp_is_open;

//-----Прототипы внутренних функций--------
void edmaIsr();
int32 InitCfg(mcbsp_context* mctx);
int32 InitDev(mcbsp_context* mctx);
void SendBuf(uint32 *buf, int len);
int32 ReadBuf(EDMA_Handle h_edma,circ_buf *c_buf,uint32 *rs_buf,uint16 *rs_count,uint32 **t);

//-----------------------------------------
void RS_Delay(uint16 num)
{
        for(uint16 i=0;i<num;i++)
                asm(" nop");            
}
//-----------------------------------------
int32 mcbsp_open( s_os_driver_descriptor* d, uint16 access )
{
    d->access = DRV_OPENED | DRV_WR | DRV_RD;
    return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 mcbsp_close( s_os_driver_descriptor* d )
{
    d->access = 0;
    return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 mcbsp_read( s_os_driver_descriptor* d, void* buf, int32 length )
{
    if(length == 0)
        return 0;

    uint32 *buf_int = (uint32*)const_cast<void*>( buf );

    rs_count_in = length/4;

    if(length%4)
      rs_count_in++;

    while(1)
    {
        ReadBuf(hEdmaIn,&rs_in,rs_buf,&rs_count_in,&buf_int);

        if(rs_count_in==0)break;          
            prc_yield();
    }
    return length;
}
// ---------------------------------------------------------------------------
int32 mcbsp_write( s_os_driver_descriptor* d, const void* buf, int32 length )
{
    if(length == 0)
        return length;

    sem_lock(rs_send_sem,SEM_INFINITY );

    uint32 *b = (uint32*)buf;

    uint16 ost;
    uint16 l=length/4;

    ost = length%4;                
    if(ost)
      l++;
          
    if (rs_count_out == MCBSP_BUF_SIZE)
    {
        RS_Delay(15);
        rs_count_out = 0;
    }

    while (l > MCBSP_BUF_SIZE - rs_count_out)
    {
        SendBuf(b, MCBSP_BUF_SIZE - rs_count_out);

        b += MCBSP_BUF_SIZE - rs_count_out;
        l -= MCBSP_BUF_SIZE - rs_count_out;

        rs_count_out = 0;

        RS_Delay(5);//15
    }

    SendBuf(b,l);

    rs_count_out += l;
    
    sem_unlock(rs_send_sem);

    return length;
}
//---------------------------------------------------------------------------
int32 mcbsp_ioctl( s_os_driver_descriptor* d, int32 cmd, const void* arg )
{
        switch( cmd )
        {
                case IOC_INIT_DESCRIPTOR:
                        break;
                case IOC_DEINIT_DESCRIPTOR:
                        break;

                case IOC_SIZE:
                {
                        if(arg == NULL)
                                return OSE_BAD_PARAM;
                        int64* carg = (int64*)const_cast<void*>(arg);
                        (*carg) = 0ull;                 
                }
                break;

                case IOC_INIT:
                {
                        s_os_driver_context* dctx = (s_os_driver_context*)const_cast<void*>(arg);

                        mcbsp_context* mctx = (mcbsp_context*)dctx->data;

                        rs_count_out = 0;
                        
                        mcbsp_is_open = 0;
            
                        rs_send_sem = sem_alloc(1,NULL);
                        rs_recv_sem = sem_alloc(1,NULL);
                        edma_out_sem = sem_alloc(0,NULL);
                        
                        int_descriptor_edma = int_alloc(INT_EDMA,edmaIsr);
                        if(int_descriptor_edma == RES_VOID) return OSE_CANT_CREATE_INTERRUPT;
                        res_share( int_descriptor_edma );
                        
                        InitCfg(mctx);
                        InitDev(mctx);                  
                }
                break;

                case IOC_DEINIT:
                {
                        int_free(int_descriptor_edma);
                        sem_free(rs_send_sem);
                        sem_free(rs_recv_sem);
                        sem_free(edma_out_sem);
                }
                break;

                case IOC_INODE_SELECT:
                {

                        const char* recast_arg = (const char*) arg;

                        if(recast_arg == NULL)
                                return OSE_BAD_PARAM;

                        if(d->access & DRV_OPENED) 
                                return OSE_STREAM_OPENED;

                        if(!strcmp(recast_arg,"."))
                                break;
                        else
                        if(!strcmp(recast_arg,".."))
                        {
                                drv_dec(d);
                                drv_rfs(d);
                        }
                        else
                                return  OSE_NO_NODE;

                }
                break;
                
                default:
                        return OSE_BAD_CMD;
        }

        return OSE_OK;

}
//---------------------------------------------------------------------------
int32 drv_mcbsp_plug(mcbsp_context* ctx)
{
    return drv_plug( "/dev/mcbsp", INOT_FILE, &mcbsp_open, &mcbsp_close, &mcbsp_read, &mcbsp_write, &mcbsp_ioctl, ctx, sizeof(mcbsp_context));
}
// ---------------------------------------------------------------------------
int32 drv_mcbsp_unplug()
{
    return drv_unplug( "mcbsp" );
}
//---------------------------------------------------------------------------
void edmaIsr()
{
    if(EDMA_intTest(TCCINTNUM_XMIT))
    {
        EDMA_intClear(TCCINTNUM_XMIT);
                sem_unlock(edma_out_sem);
    }
}
//---------------------------------------------------------------------------
int32 InitCfg(mcbsp_context* mctx)
{
    if(mctx->out_port != PORT_UNUSED)
    {
        cfgEdmaOut = mctx->edma_cfg_out;
        cfgEdmaOut.opt |= (EDMA_OPT_TCC_OF(TCCINTNUM_XMIT)<<_EDMA_OPT_TCC_SHIFT); 
        cfgEdmaOut.opt |= (EDMA_OPT_TCCM_OF(TCCINTNUM_XMIT>>4)<<_EDMA_OPT_TCCM_SHIFT); 
    }
    if(mctx->in_port1 != PORT_UNUSED)
    {
        cfgEdmaIn = mctx->edma_cfg_in;
        cfgEdmaIn.opt |= (EDMA_OPT_TCC_OF(TCCINTNUM_RECV1)<<_EDMA_OPT_TCC_SHIFT); 
        cfgEdmaIn.opt |= (EDMA_OPT_TCCM_OF(TCCINTNUM_RECV1>>4)<<_EDMA_OPT_TCCM_SHIFT); 
    }
    return 0;
}
//---------------------------------------------------------------------------
uint16 EDMA_GetChannel(uint16 n_mcbsp_port, uint16 port_type)
{
    if((port_type!=MCBSP_PORT_SEND)&&(port_type!=MCBSP_PORT_RECV))
            return 0;

    switch(n_mcbsp_port)
    {
        case MCBSP_PORT0:
        {
            if(port_type==MCBSP_PORT_SEND)
                return EDMA_CHA_XEVT0;
            if(port_type==MCBSP_PORT_RECV)
                return EDMA_CHA_REVT0;
        }
        case MCBSP_PORT1:
        {
            if(port_type==MCBSP_PORT_SEND)
                return EDMA_CHA_XEVT1;
            if(port_type==MCBSP_PORT_RECV)
                return EDMA_CHA_REVT1;
        }
        case MCBSP_PORT2:
        {
            if(port_type==MCBSP_PORT_SEND)
                    return EDMA_CHA_XEVT2;
            if(port_type==MCBSP_PORT_RECV)
                    return EDMA_CHA_REVT2;
        }
        default: 
            return 0;
    }

}
//---------------------------------------------------------------------------
int32 InitDev(mcbsp_context* mctx)
{
    uint16 edma_channel;
    uint32 mcbsp_xmt_addr,mcbsp_rcv_addr;

//    MCBSP_resetAll();

    EDMA_resetAll();
    EDMA_clearPram(0x00000000);

    if(mctx->out_port != PORT_UNUSED)
    {
        h_out = MCBSP_open(mctx->out_port, MCBSP_OPEN_RESET);
        MCBSP_config(h_out, &mctx->mcbsp_cfg_out);

        mcbsp_xmt_addr = MCBSP_getXmtAddr(h_out);

        MCBSP_enableSrgr(h_out);
        MCBSP_enableFsync(h_out);

        edma_channel = EDMA_GetChannel(mctx->out_port,MCBSP_PORT_SEND);

        hEdmaOut = EDMA_open(edma_channel, EDMA_OPEN_RESET);
        cfgEdmaOut.dst = EDMA_DST_OF(mcbsp_xmt_addr);           
    }
        
    if(mctx->in_port1 != PORT_UNUSED)
    {
        h_in = MCBSP_open(mctx->in_port1, MCBSP_OPEN_RESET);
        MCBSP_config(h_in, &mctx->mcbsp_cfg_in);

        mcbsp_rcv_addr = MCBSP_getRcvAddr(h_in);

        hEdmaIn = EDMA_allocTable(1);
        hEdmaInRld = EDMA_allocTable(2);

        edma_channel = EDMA_GetChannel(mctx->in_port1,MCBSP_PORT_RECV);

        hEdmaIn = EDMA_open(edma_channel, EDMA_OPEN_RESET);
        cfgEdmaIn.src  =  EDMA_SRC_OF(mcbsp_rcv_addr);

        cfgEdmaInRld = cfgEdmaIn;

        rs_in.head  = 0;
        rs_in.tail  = 0;
        rs_count_in = 0;
        
        memset(rs_buf,0,sizeof(rs_buf));

        cfgEdmaIn.rld = EDMA_RLD_RMK(0, hEdmaInRld);
        cfgEdmaIn.dst = EDMA_DST_OF(rs_buf);
        cfgEdmaIn.cnt = EDMA_DST_OF(MCBSP_BUF_SIZE);

        EDMA_config(hEdmaIn, &cfgEdmaIn);
        EDMA_config(hEdmaInRld, &cfgEdmaIn);

        EDMA_enableChannel(hEdmaIn);

        MCBSP_start(h_in, MCBSP_RCV_START, 0x00003000);
        MCBSP_read(h_in);

        }
        
        return 0;
}
//---------------------------------------------------------------------------
void SendBuf(uint32 *buf, int len)
{
    int_lock(int_descriptor_edma);

    cfgEdmaOut.rld = EDMA_RLD_RMK(0, EDMA_hNull);
    cfgEdmaOut.src = EDMA_SRC_OF(buf);
    cfgEdmaOut.cnt = EDMA_SRC_OF(len);
    EDMA_config(hEdmaOut, &cfgEdmaOut);

    EDMA_intDisable(TCCINTNUM_XMIT);
    EDMA_intClear(TCCINTNUM_XMIT);
    EDMA_intEnable(TCCINTNUM_XMIT);

    int_unlock(int_descriptor_edma);

    EDMA_enableChannel(hEdmaOut);

    MCBSP_enableXmt(h_out);

    sem_lock(edma_out_sem,SEM_INFINITY );

    while(MCBSP_xempty(h_out));

    MCBSP_FSETH(h_out, SPCR, XRST, 0);
    EDMA_disableChannel(hEdmaOut);
}
//---------------------------------------------------------------------------
int32 ReadBuf(EDMA_Handle h_edma,circ_buf *c_buf,uint32 *rs_buf,uint16 *rs_count,uint32 **t)
{
    if(*rs_count==0)
        return 0;

    c_buf->head = MCBSP_BUF_SIZE - EDMA_FGETH(h_edma,CNT,ELECNT);

    if(c_buf->head >= c_buf->tail)
    {
        if((c_buf->head - c_buf->tail) >= *rs_count)
        {
            RS_Delay(10);
            
            memcpy(*t,(rs_buf+c_buf->tail),*rs_count*4);            
            c_buf->tail += *rs_count;                               
            c_buf->tail &= MCBSP_BUF_SIZE-1;
            *rs_count = 0;
        }
    }
    else
    {
        if(*rs_count>=(MCBSP_BUF_SIZE-c_buf->tail))
        {
            RS_Delay(10);

            memcpy(*t,(rs_buf+c_buf->tail),(MCBSP_BUF_SIZE-c_buf->tail)*4);
            *t += (MCBSP_BUF_SIZE-c_buf->tail);                                                                                                                             
            *rs_count -= (MCBSP_BUF_SIZE-c_buf->tail);
            c_buf->tail = 0;
                        
        }
        else
        {
            RS_Delay(10);

            memcpy(*t,(rs_buf+c_buf->tail),*rs_count*4);
            c_buf->tail += *rs_count;                               
            c_buf->tail &= MCBSP_BUF_SIZE-1;
            *rs_count = 0;
        }
    }       
    
    return *rs_count;
}
//----------------------------------------------------------------------------
MCBSP_Handle mcbsp_spi_init( int devNum )
{
    MCBSP_Handle hMcbsp = MCBSP_open( devNum , MCBSP_OPEN_RESET );
    MCBSP_config( hMcbsp, &main_spi_mcbspCfg );
    MCBSP_start( hMcbsp, MCBSP_SRGR_START | MCBSP_RCV_START | MCBSP_XMIT_START, 5 );

    return hMcbsp;
}
//----------------------------------------------------------------------------


