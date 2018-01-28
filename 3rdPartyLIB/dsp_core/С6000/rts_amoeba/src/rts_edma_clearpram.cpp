#include <rts.h>
void EDMA_clearPram(uint32 val)
{

  int x;
  register volatile uint32 gie;

  uint32 *pram = (uint32*)_EDMA_PRAM_START;

  gie = int_disable();

  for (x=0; x<_EDMA_PRAM_SIZE>>2; x++) {
    pram[x] = val;
  }

  int_enable(gie);
}
