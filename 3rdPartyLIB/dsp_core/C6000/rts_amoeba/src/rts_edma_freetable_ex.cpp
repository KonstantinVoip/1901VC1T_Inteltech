#include <rts.h>
void EDMA_freeTableEx(int cnt, EDMA_Handle *array)
{

  int x;
  register volatile uint32 gie;

  gie = int_disable();
  for (x=0; x<cnt; x++) {
    EDMA_freeTable(array[x]);
    array[x] = EDMA_HINV;
  }
  int_enable(gie);
}
