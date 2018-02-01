#include <rts.h>
void EDMA_freeTable(EDMA_Handle hEdma)
{

  register volatile uint32 gie;
  uint32 tbl,major,minor;

  gie = int_disable();
  if (hEdma & _EDMA_TYPE_T) {
    tbl = ((((uint32)hEdma)&0x00FF0000)>>16);
    major = ((tbl)&(~0x1F))>>5;
    minor = (tbl)&(0x1F);
    rts_edma__allocMaskT[major] &= ~(1<<minor);
  }
  int_enable(gie);
}
