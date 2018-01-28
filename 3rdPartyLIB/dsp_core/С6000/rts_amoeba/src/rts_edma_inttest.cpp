#include <rts.h>
uint32 EDMA_intTest(uint32 tccIntNum)
{
  if (tccIntNum < 32) return ((EDMA_RGET(CIPRL) & (1<<tccIntNum)) ? 1 : 0);
  else return ((EDMA_RGET(CIPRH) & (1<<(tccIntNum-32))) ? 1 : 0);
}
