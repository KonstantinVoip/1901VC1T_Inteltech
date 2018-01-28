#include <rts.h>
int EDMA_allocTableEx(int cnt, EDMA_Handle *array)
{

  EDMA_Handle hEdma;

  int x,numAllocated=0;

  register volatile uint32 gie;
 
  gie = int_disable();
  for (x=0; x<cnt; x++) {
    hEdma = EDMA_allocTable(EDMA_ALLOC_ANY);
    if (hEdma != EDMA_HINV) {
      numAllocated++;
      array[x] = hEdma;
    } else {
      EDMA_freeTableEx(numAllocated,array);
      numAllocated = 0;
    }
  }
  int_enable(gie);
  return numAllocated;
}
