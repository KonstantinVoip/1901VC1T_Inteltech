#include <rts.h>
#include "os_csl_mcbsp.h"
#include "drv_mcbsp.h"
#include "rs_circ_buf.h"

#define RS_TIME_WAIT        10000

#define MCBSP_PORT_RECV     00
#define MCBSP_PORT_SEND     01

#define TCCINTNUM_XMIT      10
#define TCCINTNUM_RECV1     11
#define TCCINTNUM_RECV2     12

#define MCBSP_BUF_SIZE      1024//512 //размер буфера в uint32 //512

// -- Путь ---------------------------------------------------------------------------------------------
#define DRV_MCBSP_OUT_NUM   0x0
#define DRV_MCBSP_IN1_NUM   0x1
#define DRV_MCBSP_IN2_NUM   0x2

struct  s_drv_mcbsp_var
{
    char   name[10];   //Имя файла канала mcbsp
    uint32 *rs_buf;        //Указатель куда складывать данные циклического буфера от каждого канала mcbsp своим каналом EDMA 
    uint32 rs_count;   //Оставшееся количества слов текущего сессии чтения
    circ_buf c_buf;    //Циклический буфер для каждого канала mcbsp
    EDMA_Handle h_edma;//Структура с настройками для каждого из каналов mcbsp   
};

static volatile bool    mcbsp_struct_init = false;
static s_drv_mcbsp_var  mcbsp_channels[3];

MCBSP_Handle h_out;     
MCBSP_Handle h_in1;
MCBSP_Handle h_in2;

EDMA_Handle hEdmaInRld1; /* Handle for the EDMA reload parameters  */
EDMA_Handle hEdmaInRld2; /* Handle for the EDMA reload parameters  */

EDMA_Config cfgEdmaOut;
EDMA_Config cfgEdmaIn1;
EDMA_Config cfgEdmaIn2;
EDMA_Config cfgEdmaInRld1;
EDMA_Config cfgEdmaInRld2;

uint32 rs_buf1[MCBSP_BUF_SIZE];
uint32 rs_buf2[MCBSP_BUF_SIZE];

//uint32 cmp_buf[MCBSP_BUF_SIZE];

static uint32 rs_send_sem;
static uint32 rs_recv_sem;
static uint32 edma_out_sem;

uint32 int_descriptor_edma;

//-----Прототипы внутренних функций--------
void edmaIsr();
int32 InitCfg(mcbsp_context* mctx);
int32 InitDev(mcbsp_context* mctx);
int32 ReadBuf(s_drv_mcbsp_var *mcbsp_var,uint32 **t);
void  SendBuf(s_drv_mcbsp_var *mcbsp_var,uint32 *buf, int len);

int32 mcbsp_init_channel_struct();
s_drv_mcbsp_var* get_mcbsp_channel(const char* name);
int32 mcbsp_inode_select(s_os_driver_descriptor* d, char* name);
int32 mcbsp_inode_list(s_os_driver_descriptor* d, s_inode* *arg);

//-----------------------------------------

void RS_Delay(uint16 num)
{
    for(uint16 i=0;i<num;i++)
        asm(" nop");            
}
//-----------------------------------------
int32 mcbsp_open( s_os_driver_descriptor* d, uint16 access )
{
    s_drv_mcbsp_var *mcbsp_var = (s_drv_mcbsp_var*)d->data;

    if((!strcmp(mcbsp_var->name,"mcbsp_in1") || (!strcmp(mcbsp_var->name,"mcbsp_in2"))))
    {
      if(access != DRV_RD)
        return OSE_PERMISSION_DENIED;
    }
    else
    {
      if((!strcmp(mcbsp_var->name,"mcbsp_out"))&&(access != DRV_WR))
        return OSE_PERMISSION_DENIED;
    }
    
    d->access = DRV_OPENED | access;

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

    if((d->access) == (DRV_OPENED | DRV_RD))
    {
        if(length == 0)
            return 0;

        uint32* buf_int = (uint32*)const_cast<void*>( buf );

        s_drv_mcbsp_var *mcbsp_var = (s_drv_mcbsp_var*)d->data;

        mcbsp_var->rs_count = length/4;
        
        if(length%4)
            mcbsp_var->rs_count++;

        while(1)
        {
            ReadBuf(mcbsp_var,&buf_int);

            if(mcbsp_var->rs_count == 0)
                  break;          

            prc_yield();
        }
    }
    else
        return OSE_PERMISSION_DENIED;
        
   return length;
}
// ---------------------------------------------------------------------------
int32 mcbsp_write( s_os_driver_descriptor* d, const void* buf, int32 length )
{
    if((d->access) == (DRV_OPENED | DRV_WR))
    {
        s_drv_mcbsp_var *mcbsp_var = (s_drv_mcbsp_var*)d->data;

        if(length == 0)
            return length;

        sem_lock(rs_send_sem,SEM_INFINITY );

        uint32* b = (uint32*)const_cast<void*>( buf );

        uint16 l=length/4;
        
        if(length%4)l++;
    
        if (mcbsp_var->rs_count == MCBSP_BUF_SIZE)
        {
            RS_Delay(15);
            mcbsp_var->rs_count = 0;
        }

        while (l > MCBSP_BUF_SIZE - mcbsp_var->rs_count)
        {
            SendBuf(mcbsp_var,b,MCBSP_BUF_SIZE - mcbsp_var->rs_count);

            b += MCBSP_BUF_SIZE - mcbsp_var->rs_count;
            l -= MCBSP_BUF_SIZE - mcbsp_var->rs_count;

            mcbsp_var->rs_count = 0;

            RS_Delay(5);
        }

        SendBuf(mcbsp_var,b,l);

        mcbsp_var->rs_count += l;

        sem_unlock(rs_send_sem);
    }
    else
        return OSE_PERMISSION_DENIED;
    
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
                                   
            rs_send_sem = sem_alloc(1,NULL);
            rs_recv_sem = sem_alloc(1,NULL);
            edma_out_sem = sem_alloc(0,NULL);
            
            int_descriptor_edma = int_alloc(INT_EDMA,edmaIsr);
            if(int_descriptor_edma == RES_VOID) return OSE_CANT_CREATE_INTERRUPT;
            res_share( int_descriptor_edma );
           
                        mcbsp_init_channel_struct();
            
                        InitCfg(mctx);
            InitDev(mctx);                  
        }
        break;

        case IOC_DEINIT:
        {

                        mcbsp_struct_init = false;
            int_free(int_descriptor_edma);
            sem_free(rs_send_sem);
            sem_free(rs_recv_sem);
            sem_free(edma_out_sem);
        }
        break;

        case IOC_INODE_SELECT:
            return mcbsp_inode_select(d, (char*)arg);

        case IOC_INODE_LIST:
            return mcbsp_inode_list(d, (s_inode**)arg);
        
        default:
                return OSE_BAD_CMD;
    }

    return OSE_OK;

}
//---------------------------------------------------------------------------
int32 drv_mcbsp_plug(mcbsp_context* ctx)
{
    return drv_plug( "/dev/mcbsp", INOT_FOLDER, &mcbsp_open, &mcbsp_close, &mcbsp_read, &mcbsp_write, &mcbsp_ioctl, ctx, sizeof(mcbsp_context));
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
        cfgEdmaIn1 = mctx->edma_cfg_in;
        cfgEdmaIn1.opt |= (EDMA_OPT_TCC_OF(TCCINTNUM_RECV1)<<_EDMA_OPT_TCC_SHIFT); 
        cfgEdmaIn1.opt |= (EDMA_OPT_TCCM_OF(TCCINTNUM_RECV1>>4)<<_EDMA_OPT_TCCM_SHIFT); 
    }
    if(mctx->in_port2 != PORT_UNUSED)
    {
        cfgEdmaIn2 = mctx->edma_cfg_in;
        cfgEdmaIn2.opt |= (EDMA_OPT_TCC_OF(TCCINTNUM_RECV2)<<_EDMA_OPT_TCC_SHIFT); 
        cfgEdmaIn2.opt |= (EDMA_OPT_TCCM_OF(TCCINTNUM_RECV2>>4)<<_EDMA_OPT_TCCM_SHIFT); 
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
    uint32 mcbsp_xmt_addr,mcbsp_rcv_addr1,mcbsp_rcv_addr2;

    MCBSP_resetAll();                       

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

        mcbsp_channels[DRV_MCBSP_OUT_NUM].h_edma = EDMA_open(edma_channel, EDMA_OPEN_RESET);
        cfgEdmaOut.dst = EDMA_DST_OF(mcbsp_xmt_addr);           

        mcbsp_channels[DRV_MCBSP_OUT_NUM].rs_count = 0;

    }
    
    if(mctx->in_port1 != PORT_UNUSED)
    {
        h_in1 = MCBSP_open(mctx->in_port1, MCBSP_OPEN_RESET);
        MCBSP_config(h_in1, &mctx->mcbsp_cfg_in);

        mcbsp_rcv_addr1 = MCBSP_getRcvAddr(h_in1);

        mcbsp_channels[DRV_MCBSP_IN1_NUM].h_edma = EDMA_allocTable(1);
        hEdmaInRld1 = EDMA_allocTable(2);

        edma_channel = EDMA_GetChannel(mctx->in_port1,MCBSP_PORT_RECV);

        mcbsp_channels[DRV_MCBSP_IN1_NUM].h_edma = EDMA_open(edma_channel, EDMA_OPEN_RESET);
        cfgEdmaIn1.src  =  EDMA_SRC_OF(mcbsp_rcv_addr1);

        cfgEdmaInRld1 = cfgEdmaIn1;

        mcbsp_channels[DRV_MCBSP_IN1_NUM].rs_count   = 0;
        mcbsp_channels[DRV_MCBSP_IN1_NUM].c_buf.head = 0;
        mcbsp_channels[DRV_MCBSP_IN1_NUM].c_buf.tail = 0;
        mcbsp_channels[DRV_MCBSP_IN1_NUM].rs_buf = rs_buf1;
        
        memset(rs_buf1,0,sizeof(rs_buf1));

        cfgEdmaIn1.rld = EDMA_RLD_RMK(0, hEdmaInRld1);
        cfgEdmaIn1.dst = EDMA_DST_OF(rs_buf1);
        cfgEdmaIn1.cnt = EDMA_DST_OF(MCBSP_BUF_SIZE);

        EDMA_config(mcbsp_channels[DRV_MCBSP_IN1_NUM].h_edma, &cfgEdmaIn1);
        EDMA_config(hEdmaInRld1, &cfgEdmaIn1);

        EDMA_enableChannel(mcbsp_channels[DRV_MCBSP_IN1_NUM].h_edma);

        MCBSP_start(h_in1, MCBSP_RCV_START, 0x00003000);
        MCBSP_read(h_in1);

        MCBSP_FSETH(h_in1, SPCR, XRST, 0);

    }
    
    if(mctx->in_port2 != PORT_UNUSED)
    {
        h_in2 = MCBSP_open(mctx->in_port2, MCBSP_OPEN_RESET);
        MCBSP_config(h_in2, &mctx->mcbsp_cfg_in);

        mcbsp_rcv_addr2 = MCBSP_getRcvAddr(h_in2);

        mcbsp_channels[DRV_MCBSP_IN2_NUM].h_edma = EDMA_allocTable(3);
        hEdmaInRld2 = EDMA_allocTable(4);

        edma_channel = EDMA_GetChannel(mctx->in_port2,MCBSP_PORT_RECV);

        mcbsp_channels[DRV_MCBSP_IN2_NUM].h_edma = EDMA_open(edma_channel, EDMA_OPEN_RESET);
        cfgEdmaIn2.src  =  EDMA_SRC_OF(mcbsp_rcv_addr2);

        cfgEdmaInRld2 = cfgEdmaIn2;

        mcbsp_channels[DRV_MCBSP_IN2_NUM].rs_count   = 0;
        mcbsp_channels[DRV_MCBSP_IN2_NUM].c_buf.head = 0;
        mcbsp_channels[DRV_MCBSP_IN2_NUM].c_buf.tail = 0;
        mcbsp_channels[DRV_MCBSP_IN2_NUM].rs_buf = rs_buf2;

        memset(rs_buf2,0,sizeof(rs_buf2));

        cfgEdmaIn2.rld = EDMA_RLD_RMK(0, hEdmaInRld2);
        cfgEdmaIn2.dst = EDMA_DST_OF(rs_buf2);
        cfgEdmaIn2.cnt = EDMA_DST_OF(MCBSP_BUF_SIZE);

        EDMA_config(mcbsp_channels[DRV_MCBSP_IN2_NUM].h_edma, &cfgEdmaIn2);
        EDMA_config(hEdmaInRld2, &cfgEdmaIn2);

        EDMA_enableChannel(mcbsp_channels[DRV_MCBSP_IN2_NUM].h_edma);

        MCBSP_start(h_in2, MCBSP_RCV_START, 0x00003000);
        MCBSP_read(h_in2);

        MCBSP_FSETH(h_in2, SPCR, XRST, 0);
    }
    return 0;
}
//---------------------------------------------------------------------------
void SendBuf(s_drv_mcbsp_var *mcbsp_var,uint32 *buf, int len)
{
    int_lock(int_descriptor_edma);

    cfgEdmaOut.rld = EDMA_RLD_RMK(0, EDMA_hNull);
    cfgEdmaOut.src = EDMA_SRC_OF(buf);
    cfgEdmaOut.cnt = EDMA_SRC_OF(len);
    EDMA_config(mcbsp_var->h_edma, &cfgEdmaOut);

    EDMA_intDisable(TCCINTNUM_XMIT);
    EDMA_intClear(TCCINTNUM_XMIT);
    EDMA_intEnable(TCCINTNUM_XMIT);

    int_unlock(int_descriptor_edma);

    EDMA_enableChannel(mcbsp_var->h_edma);

    MCBSP_enableXmt(h_out);

    sem_lock(edma_out_sem,SEM_INFINITY );

    while(MCBSP_xempty(h_out));

    MCBSP_FSETH(h_out, SPCR, XRST, 0);
    EDMA_disableChannel(mcbsp_var->h_edma);
}
//---------------------------------------------------------------------------
int32 ReadBuf(s_drv_mcbsp_var *mcbsp_var,uint32 **t)
{
    if(mcbsp_var->rs_count == 0)
        return 0;
                
    mcbsp_var->c_buf.head = MCBSP_BUF_SIZE - EDMA_FGETH(mcbsp_var->h_edma,CNT,ELECNT);

    if(mcbsp_var->c_buf.head >= mcbsp_var->c_buf.tail)
    {
        if((mcbsp_var->c_buf.head - mcbsp_var->c_buf.tail) >= mcbsp_var->rs_count)
        {
            RS_Delay(5);
            memcpy(*t,(mcbsp_var->rs_buf+mcbsp_var->c_buf.tail),mcbsp_var->rs_count*4);            

            mcbsp_var->c_buf.tail += mcbsp_var->rs_count;                               
            mcbsp_var->c_buf.tail &= MCBSP_BUF_SIZE-1;
            mcbsp_var->rs_count = 0;
        }
    }
    else
    {
        if(mcbsp_var->rs_count >= (MCBSP_BUF_SIZE - mcbsp_var->c_buf.tail))
        {
            RS_Delay(5);

            memcpy(*t,(mcbsp_var->rs_buf + mcbsp_var->c_buf.tail),(MCBSP_BUF_SIZE - mcbsp_var->c_buf.tail)*4);

            *t += (MCBSP_BUF_SIZE - mcbsp_var->c_buf.tail);

            mcbsp_var->rs_count -= (MCBSP_BUF_SIZE - mcbsp_var->c_buf.tail);
            mcbsp_var->c_buf.tail = 0;        
        }
        else
        {
            RS_Delay(5);

            memcpy(*t,(mcbsp_var->rs_buf+mcbsp_var->c_buf.tail),(mcbsp_var->rs_count)*4);

            mcbsp_var->c_buf.tail += mcbsp_var->rs_count;                               
            mcbsp_var->c_buf.tail &= MCBSP_BUF_SIZE-1;
            mcbsp_var->rs_count = 0;
        }
    }       

    return mcbsp_var->rs_count;
}
//----------------------------------------------------------------------------
int32 mcbsp_inode_select(s_os_driver_descriptor* d, char* name)
{
    s_drv_mcbsp_var* mcbsp_var; 
    
    if(!strcmp(name,"."))
        return OSE_OK;
    else
    if(!strcmp(name,".."))
    {
        drv_dec(d);
        if(d->data == NULL)
            drv_rfs(d);
        else
            d->data = NULL;
    }
    else 
    if( ( (mcbsp_var = get_mcbsp_channel(name)) != NULL ) && (d->data == NULL) )
    {
        drv_inc(d, name);
        d->data   = mcbsp_var;
    }
    else
        return  OSE_NO_NODE;

    return OSE_OK;
}
//----------------------------------------------------------------------------
int32 mcbsp_inode_list(s_os_driver_descriptor* d, s_inode* *arg)
{
  if(d->data != NULL)
    return OSE_NO_NODE;
  s_inode*     node;
  s_inode*     first_node = NULL;
  s_inode*     last_node = NULL;
  
  for(int32 i = 0; i < 3; i++)
  {
    node = new s_inode;
    if( node == NULL )
      return OSE_NO_MEMORY;
  
    node->name = new char[10];
    if(node->name == NULL)
    {
      delete node;
      return OSE_NO_MEMORY;
    }
  
    node->prev = NULL;
    node->next = NULL;
    strcpy(node->name, mcbsp_channels[i].name);
    node->size = sizeof(void*);
    node->mktime = 0;
    node->own_user = 0;
    node->own_group = 0;
    node->access = 0;//mcbsp_channels[i].ch_access;
    node->type = INOT_FILE;
  
    if(first_node == NULL) 
      first_node = node;
    if(last_node == NULL)
      node->prev = NULL;
    else
    {
      last_node->next = node;
      node->prev = last_node;
    }
    last_node = node;
    node->next = NULL;
  }
  *((s_inode**)arg) = first_node;
  return OSE_OK;
}
//----------------------------------------------------------------------------
int32 mcbsp_init_channel_struct()
{
  if(mcbsp_struct_init == false)
  {
    memset(mcbsp_channels,0,sizeof(mcbsp_channels));

    strcpy(mcbsp_channels[DRV_MCBSP_OUT_NUM].name, "mcbsp_out");
    strcpy(mcbsp_channels[DRV_MCBSP_IN1_NUM].name, "mcbsp_in1");
    strcpy(mcbsp_channels[DRV_MCBSP_IN2_NUM].name, "mcbsp_in2");

    mcbsp_struct_init = true;
    return OSE_OK;
  }
  else
    return OSE_NO_DEVICE;
}
//----------------------------------------------------------------------------
s_drv_mcbsp_var* get_mcbsp_channel(const char* name)
{
  for(int32 i = 0; i < 3; i++)
  {
    if(!strcmp(name, mcbsp_channels[i].name))
      return &mcbsp_channels[i];
  }
  return NULL;
}
//----------------------------------------------------------------------------


