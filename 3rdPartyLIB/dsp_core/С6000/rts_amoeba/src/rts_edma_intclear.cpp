#include <rts.h>
void EDMA_intClear(uint32 tccIntNum)
{
  if (tccIntNum < 32) EDMA_RSET(CIPRL,1<<tccIntNum);
  else EDMA_RSET(CIPRH,1<<(tccIntNum-32));
}
