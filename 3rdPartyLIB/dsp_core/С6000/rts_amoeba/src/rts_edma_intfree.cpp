#include <rts.h>
void EDMA_intFree(int tcc)
{

  register volatile uint32 gie;

  gie = int_disable();
  rts_edma__tccAllocTable[tcc] = 0;
  int_enable(gie);
}
