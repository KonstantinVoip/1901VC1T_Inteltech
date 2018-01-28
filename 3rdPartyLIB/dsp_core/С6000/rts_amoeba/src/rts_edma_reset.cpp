#include <rts.h>
void EDMA_reset(EDMA_Handle hEdma)
{

  register volatile uint32 gie;
   
  gie = int_disable();

  if (hEdma != EDMA_HINV) {
    EDMA_disableChannel(hEdma);
    EDMA_clearChannel(hEdma);
    EDMA_RSETH(hEdma,OPT,EDMA_OPT_DEFAULT);
    EDMA_RSETH(hEdma,SRC,EDMA_SRC_DEFAULT);
    EDMA_RSETH(hEdma,DST,EDMA_DST_DEFAULT);
    EDMA_RSETH(hEdma,CNT,EDMA_CNT_DEFAULT);
    EDMA_RSETH(hEdma,RLD,EDMA_RLD_DEFAULT);
    EDMA_RSETH(hEdma,IDX,EDMA_IDX_DEFAULT);
  }

  int_enable(gie);
}

