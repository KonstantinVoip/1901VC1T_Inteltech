#include <rts.h>
void EDMA_intReset(uint32 tccIntNum)
{
  register volatile uint32 gie;

  gie = int_disable();

  /* disable then clear interrupt */
  if (tccIntNum < 32)
  {
    EDMA_RSET(CIERL,EDMA_RGET(CIERL) & ~(1<<tccIntNum));
    EDMA_RSET(CIPRL,1<<tccIntNum);
  }
  else
  {
    EDMA_RSET(CIERH,EDMA_RGET(CIERH) & ~(1<<(tccIntNum-32)));
    EDMA_RSET(CIPRH,1<<(tccIntNum-32));
  }
  
  int_enable(gie);
}
