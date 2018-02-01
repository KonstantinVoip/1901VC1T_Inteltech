//#include "posix.h"
#include <rts.h>
#include "qdma_rwrd.h"

#define TCCINTNUM_READ	7//Если изменить, то необходимо поменять регистр QOPT в EDMA_qdmaConfigArgs
#define TCCINTNUM_WRITE	6//Если изменить, то необходимо поменять регистр QOPT в EDMA_qdmaConfigArgs

#define QDMA_CHANNEL_WR       1//Номер канала для QDMA_Write для TMS6457  
#define QDMA_CHANNEL_RD       2//Номер канала для QDMA_Read  для TMS6457  
#define QDMA_CHANNEL_RD2CH    4//Номер канала для QDMA_Read2CH  для TMS6457  //3
#define QDMA_CHANNEL_RD_PROC  5//Номер канала для QDMA_Read  для TMS6457  

#define QDMA_PARAMNUM_RD_CH1  1//Номер набора параметров для QDMA_Read2CH1
#define QDMA_PARAMNUM_RD_CH2  2//Номер набора параметров для QDMA_Read2CH2
#define QDMA_PARAMNUM_WR      3//Номер набора параметров для QDMA_Write
#define QDMA_PARAMNUM_RD      4//Номер набора параметров для QDMA_Read  
#define QDMA_PARAMNUM_RD_PROC 5//Номер набора параметров для QDMA_ReadProc  


#ifdef CHIP_6457
CSL_Edma3ParamSetup param_wr;
CSL_Edma3ParamSetup param_rd;
CSL_Edma3ParamSetup param_rd_proc;

CSL_Edma3ParamSetup param1_rd;
CSL_Edma3ParamSetup param2_rd;
#endif

volatile int qdma2ch_len;

void* qdma2ch_src1;
void* qdma2ch_dst1;

void* qdma2ch_src2;
void* qdma2ch_dst2;

//-------------------------------------------------------------------------------------
void QDMA_StartRead2Ch(void* dst1,void* dst2,void* src1,void* src2,uint16 len)
{
    sys_buslock();

    uint16 l=len/4;

    param1_rd.srcAddr     = (uint32)src2;
    param1_rd.aCntbCnt    = CSL_EDMA3_CNT_MAKE((l+2)*4,1);
    param1_rd.dstAddr     = (uint32)dst2;
    param1_rd.srcDstBidx  = CSL_EDMA3_BIDX_MAKE(0,0);
    param1_rd.linkBcntrld = CSL_EDMA3_LINKBCNTRLD_MAKE(2*0x20,0);
    param1_rd.srcDstCidx  = CSL_EDMA3_CIDX_MAKE(0,0);
    param1_rd.cCnt        = 1;

    param2_rd.srcAddr     = (uint32)src1;
    param2_rd.aCntbCnt    = CSL_EDMA3_CNT_MAKE((l+2)*4,1);
    param2_rd.dstAddr     = (uint32)dst1;
    param2_rd.srcDstBidx  = CSL_EDMA3_BIDX_MAKE(0,0);
    param2_rd.linkBcntrld = CSL_EDMA3_LINKBCNTRLD_MAKE(CSL_EDMA3_LINK_DEFAULT,0);
    param2_rd.srcDstCidx  = CSL_EDMA3_CIDX_MAKE(0,0);
    param2_rd.cCnt        = 1;

    EDMA3_qdmaIntClear( QDMA_CHANNEL_RD2CH );

    if(l)
    {
        EDMA3_qdmaConfigArgs( QDMA_PARAMNUM_RD_CH2, &param2_rd );
        EDMA3_qdmaConfigArgs( QDMA_PARAMNUM_RD_CH1, &param1_rd );
    }

    qdma2ch_len=len;
    qdma2ch_src1=src1;
    qdma2ch_dst1=dst1;

    qdma2ch_src2=src2;
    qdma2ch_dst2=dst2;
}
//-------------------------------------------------------------------------------------
uint16 QDMA_EndRead2Ch()
{
    if(EDMA3_qdmaIntTest(QDMA_CHANNEL_RD2CH))
    {

        int ost=qdma2ch_len&0x3;
        uint16 off=qdma2ch_len&~0x3;

        if(ost)
        {
            memcpy(((char*)qdma2ch_dst1+off),((char*)qdma2ch_src1+off),ost);
            memcpy(((char*)qdma2ch_dst2+off),((char*)qdma2ch_src2+off),ost);
        }

        sys_busunlock();
        
        return 1;
    }
    else
        return 0;
}
//-------------------------------------------------------------------------------------
void QDMA_Read(void* dst,void* src,uint16 len)
{
    uint16 l=len/4;
    int ost=len&0x3;
        
    sys_buslock();

    if(l)
    {

        #ifdef CHIP_6457
        param_rd.srcAddr     = (uint32)src;
        param_rd.aCntbCnt    = CSL_EDMA3_CNT_MAKE(len,1);
        param_rd.dstAddr     = (uint32)dst;
        param_rd.srcDstBidx  = CSL_EDMA3_BIDX_MAKE(0,0);
        param_rd.linkBcntrld = CSL_EDMA3_LINKBCNTRLD_MAKE(CSL_EDMA3_LINK_DEFAULT,0);
        param_rd.srcDstCidx  = CSL_EDMA3_CIDX_MAKE(0,0);
        param_rd.cCnt        = 1;
        
        EDMA3_qdmaIntClear( QDMA_CHANNEL_RD );
        EDMA3_qdmaConfigArgs( QDMA_PARAMNUM_RD, &param_rd );
        while(!EDMA3_qdmaIntTest(QDMA_CHANNEL_RD));
        #else
        EDMA_intClear(TCCINTNUM_READ);
        EDMA_qdmaConfigArgs(0x01370000,(uint32)src,l,(uint32)dst,0);//Urgent priority 
        while(!EDMA_intTest(TCCINTNUM_READ));
        if(ost)
           memcpy(((char*)dst+4*l),((char*)src+4*l),ost);
        #endif
    }
    //if(ost)
    //    memcpy(((char*)dst+4*l),((char*)src+4*l),ost);
    sys_busunlock();

}

void QDMA_ReadProc(void* dst,void* src,uint16 len)
{
    uint16 l=len/4;
            
    if(l)
    {
        param_rd_proc.srcAddr     = (uint32)src;
        param_rd_proc.aCntbCnt    = CSL_EDMA3_CNT_MAKE(len,1);
        param_rd_proc.dstAddr     = (uint32)dst;
        param_rd_proc.srcDstBidx  = CSL_EDMA3_BIDX_MAKE(0,0);
        param_rd_proc.linkBcntrld = CSL_EDMA3_LINKBCNTRLD_MAKE(CSL_EDMA3_LINK_DEFAULT,0);
        param_rd_proc.srcDstCidx  = CSL_EDMA3_CIDX_MAKE(0,0);
        param_rd_proc.cCnt        = 1;
        
        EDMA3_qdmaIntClear( QDMA_CHANNEL_RD_PROC );
        EDMA3_qdmaConfigArgs( QDMA_PARAMNUM_RD_PROC, &param_rd_proc );
        while(!EDMA3_qdmaIntTest(QDMA_CHANNEL_RD_PROC));
    }
}

void QDMA_Write(void* dst,void* src,uint16 len)
{
    uint16 l=len/4;
	
    if(len&0x3)
        l++;

    sys_buslock();

    if(l)
    {
        #ifdef CHIP_6457
        param_wr.srcAddr     = (uint32)src;
        param_wr.aCntbCnt    = CSL_EDMA3_CNT_MAKE(l*4,1);
        param_wr.dstAddr     = (uint32)dst;
        param_wr.srcDstBidx  = CSL_EDMA3_BIDX_MAKE(0,0);
        param_wr.linkBcntrld = CSL_EDMA3_LINKBCNTRLD_MAKE(CSL_EDMA3_LINK_DEFAULT,0);
        param_wr.srcDstCidx  = CSL_EDMA3_CIDX_MAKE(0,0);
        param_wr.cCnt        = 1;

        EDMA3_qdmaIntClear( QDMA_CHANNEL_WR );
        EDMA3_qdmaConfigArgs( QDMA_PARAMNUM_WR, &param_wr );
        while(!EDMA3_qdmaIntTest(QDMA_CHANNEL_WR));
        #else
        EDMA_intClear(TCCINTNUM_WRITE);
        EDMA_qdmaConfigArgs(0x01360000,(uint32)src,l,(uint32)dst,0);//Urgent priority 
        while(!EDMA_intTest(TCCINTNUM_WRITE));
        #endif
    }
    sys_busunlock();

}
//----------------------------------------------------------------------------
void QDMA_StartRead(void* dst,void* src,uint16 len)
{
    uint16 l=len/4;
    int ost=len&0x3;

    sys_buslock();

    if(ost)
        memcpy(((char*)dst+4*l),((char*)src+4*l),ost);

    if(l)
    {
        #ifdef CHIP_6457
        param_rd.srcAddr     = (uint32)src;
        param_rd.aCntbCnt    = CSL_EDMA3_CNT_MAKE(len,1);
        param_rd.dstAddr     = (uint32)dst;
        param_rd.srcDstBidx  = CSL_EDMA3_BIDX_MAKE(0,0);
        param_rd.linkBcntrld = CSL_EDMA3_LINKBCNTRLD_MAKE(CSL_EDMA3_LINK_DEFAULT,0);
        param_rd.srcDstCidx  = CSL_EDMA3_CIDX_MAKE(0,0);
        param_rd.cCnt        = 1;
        
        EDMA3_qdmaIntClear( QDMA_CHANNEL_RD );
        EDMA3_qdmaConfigArgs( QDMA_PARAMNUM_RD, &param_rd );
        #else
        EDMA_intClear(TCCINTNUM_READ);
        EDMA_qdmaConfigArgs(0x01370000,(uint32)src,l,(uint32)dst,0);//Urgent priority 
        #endif
    }
}
//----------------------------------------------------------------------------
uint16 QDMA_CheckEndRead()
{
#ifdef CHIP_6457
    if(EDMA3_qdmaIntTest(QDMA_CHANNEL_RD))
#else
    if(EDMA_intTest(TCCINTNUM_READ))
#endif
    {
        sys_busunlock();
        return 1;
                
    }    
    else
        return 0;
}
//----------------------------------------------------------------------------
void QDMA_StartWrite(void* dst,void* src,uint16 len)
{
    uint16 l=len/4;

    if(len&0x3)
        l++;

    sys_buslock();

    if(l)
    {
        #ifdef CHIP_6457
        param_wr.srcAddr     = (uint32)src;
        param_wr.aCntbCnt    = CSL_EDMA3_CNT_MAKE(l*4,1);
        param_wr.dstAddr     = (uint32)dst;
        param_wr.srcDstBidx  = CSL_EDMA3_BIDX_MAKE(0,0);
        param_wr.linkBcntrld = CSL_EDMA3_LINKBCNTRLD_MAKE(CSL_EDMA3_LINK_DEFAULT,0);
        param_wr.srcDstCidx  = CSL_EDMA3_CIDX_MAKE(0,0);
        param_wr.cCnt        = 1;

        EDMA3_qdmaIntClear( QDMA_CHANNEL_WR );
        EDMA3_qdmaConfigArgs( QDMA_PARAMNUM_WR, &param_wr );
        #else	
        EDMA_intClear(TCCINTNUM_WRITE);
        EDMA_qdmaConfigArgs(0x01360000,(uint32)src,l,(uint32)dst,0);//Urgent priority 
        #endif	
    }
}
//----------------------------------------------------------------------------
uint16 QDMA_CheckEndWrite()
{
#ifdef CHIP_6457
    if(EDMA3_qdmaIntTest(QDMA_CHANNEL_WR))
#else
    if(EDMA_intTest(TCCINTNUM_WRITE))
#endif
    {
        sys_busunlock();
        return 1;
                
    }    
    else
        return 0;

}
//----------------------------------------------------------------------------
void QDMA_init()
{
#ifdef CHIP_6457
    param1_rd.option = 
            CSL_EDMA3_OPT_MAKE(CSL_EDMA3_ITCCH_DIS, \
            CSL_EDMA3_TCCH_DIS, \
            CSL_EDMA3_ITCINT_DIS, \
            CSL_EDMA3_TCINT_DIS,\
            QDMA_CHANNEL_RD2CH, CSL_EDMA3_TCC_NORMAL,\
            CSL_EDMA3_FIFOWIDTH_NONE, \
            CSL_EDMA3_STATIC_DIS, \
            CSL_EDMA3_SYNC_A, \
            CSL_EDMA3_ADDRMODE_INCR, \
            CSL_EDMA3_ADDRMODE_INCR);

    param2_rd.option = 
            CSL_EDMA3_OPT_MAKE(CSL_EDMA3_ITCCH_DIS, \
            CSL_EDMA3_TCCH_DIS, \
            CSL_EDMA3_ITCINT_DIS, \
            CSL_EDMA3_TCINT_EN,\
            QDMA_CHANNEL_RD2CH, CSL_EDMA3_TCC_NORMAL,\
            CSL_EDMA3_FIFOWIDTH_NONE, \
            CSL_EDMA3_STATIC_EN, \
            CSL_EDMA3_SYNC_A, \
            CSL_EDMA3_ADDRMODE_INCR, \
            CSL_EDMA3_ADDRMODE_INCR);

    param_rd.option = 
            CSL_EDMA3_OPT_MAKE(CSL_EDMA3_ITCCH_DIS, \
            CSL_EDMA3_TCCH_DIS, \
            CSL_EDMA3_ITCINT_DIS, \
            CSL_EDMA3_TCINT_EN,\
            QDMA_CHANNEL_RD, CSL_EDMA3_TCC_NORMAL,\
            CSL_EDMA3_FIFOWIDTH_NONE, \
            CSL_EDMA3_STATIC_EN, \
            CSL_EDMA3_SYNC_A, \
            CSL_EDMA3_ADDRMODE_INCR, \
            CSL_EDMA3_ADDRMODE_INCR);

    param_wr.option = 
            CSL_EDMA3_OPT_MAKE(CSL_EDMA3_ITCCH_DIS, \
            CSL_EDMA3_TCCH_DIS, \
            CSL_EDMA3_ITCINT_DIS, \
            CSL_EDMA3_TCINT_EN,\
            QDMA_CHANNEL_WR, CSL_EDMA3_TCC_NORMAL,\
            CSL_EDMA3_FIFOWIDTH_NONE, \
            CSL_EDMA3_STATIC_EN, \
            CSL_EDMA3_SYNC_A, \
            CSL_EDMA3_ADDRMODE_INCR, \
            CSL_EDMA3_ADDRMODE_INCR);

    param_rd_proc.option = 
            CSL_EDMA3_OPT_MAKE(CSL_EDMA3_ITCCH_DIS, \
            CSL_EDMA3_TCCH_DIS, \
            CSL_EDMA3_ITCINT_DIS, \
            CSL_EDMA3_TCINT_EN,\
            QDMA_CHANNEL_RD_PROC, CSL_EDMA3_TCC_NORMAL,\
            CSL_EDMA3_FIFOWIDTH_NONE, \
            CSL_EDMA3_STATIC_EN, \
            CSL_EDMA3_SYNC_A, \
            CSL_EDMA3_ADDRMODE_INCR, \
            CSL_EDMA3_ADDRMODE_INCR);

    EDMA3_qdmaInit(QDMA_CHANNEL_WR,QDMA_PARAMNUM_WR);
    EDMA3_qdmaInit(QDMA_CHANNEL_RD,QDMA_PARAMNUM_RD);
    EDMA3_qdmaInit(QDMA_CHANNEL_RD2CH,QDMA_PARAMNUM_RD_CH1);
    EDMA3_qdmaInit(QDMA_CHANNEL_RD_PROC,QDMA_PARAMNUM_RD_PROC);

#endif
}
//----------------------------------------------------------------------------
