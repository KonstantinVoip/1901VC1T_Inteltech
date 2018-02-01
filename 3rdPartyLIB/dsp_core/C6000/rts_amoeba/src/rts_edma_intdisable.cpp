#include <rts.h>
void EDMA_intDisable(uint32 tccIntNum)
{
  register volatile uint32 gie;

  gie = int_disable();

  if (tccIntNum < 32) EDMA_RSET(CIERL,EDMA_RGET(CIERL) & ~(1<<tccIntNum));
  else EDMA_RSET(CIERH,EDMA_RGET(CIERH) & ~(1<<(tccIntNum-32)));

  int_enable(gie);
}
