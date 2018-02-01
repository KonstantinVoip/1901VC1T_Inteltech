
#include <rts_edma3.h>
/* =============================================================================
 *   EDMA3_qdmaConfigArgs
 *
 *   @b Description
 *   @n конфигурирование набора параметров для QDMA канала
 *		paramNumm - номер набора параметров 0 - 255
 *      ps - набор параметров
 *
 * ===========================================================================
 */ 

void EDMA3_qdmaConfigArgs( uint32 paramNum, CSL_Edma3ParamSetup* ps )
{
  uint32 gie;
  volatile CSL_Edma3ccParamsetRegs *base;

  gie = int_disable();

  // param setup
  base = (volatile CSL_Edma3ccParamsetRegs*)(0x02A04000);
  base[paramNum].OPT = ps->option;
  base[paramNum].SRC = ps->srcAddr;
  base[paramNum].A_B_CNT = ps->aCntbCnt;
  base[paramNum].DST = ps->dstAddr;
  base[paramNum].SRC_DST_BIDX = ps->srcDstBidx;
  base[paramNum].LINK_BCNTRLD = ps->linkBcntrld;
  base[paramNum].SRC_DST_CIDX = ps->srcDstCidx;
  base[paramNum].CCNT = ps->cCnt;

  int_enable(gie);
}


