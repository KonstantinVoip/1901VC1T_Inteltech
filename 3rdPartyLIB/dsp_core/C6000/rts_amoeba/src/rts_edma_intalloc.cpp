#include <rts.h>
int EDMA_intAlloc(int tcc)
{

  int tccReturn = -1;

  register volatile uint32 gie;

  gie = int_disable();
  if (tcc == -1) {
    for (tcc=0; tcc<EDMA_CHA_CNT; tcc++) {
      if (rts_edma__tccAllocTable[tcc] == 0) {
        rts_edma__tccAllocTable[tcc] = 1;
        tccReturn = tcc;
        break;
      }
    }
  } else {
    if (rts_edma__tccAllocTable[tcc] == 0) {
      rts_edma__tccAllocTable[tcc] = 1;
      tccReturn = tcc;
    }
  }
  int_enable(gie);

  return tccReturn;
}
