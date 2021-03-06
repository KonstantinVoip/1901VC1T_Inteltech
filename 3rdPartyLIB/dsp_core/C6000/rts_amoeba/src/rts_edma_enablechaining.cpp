#include <rts.h>
void EDMA_enableChaining(EDMA_Handle hEdma)
{
  register volatile uint32 gie;
  int chaNum = (hEdma & 0x00FF0000)>>16;

  gie = int_disable();
  if (chaNum < 32) EDMA_RSET(CCERL,EDMA_RGET(CCERL) | (1<<chaNum));
  else EDMA_RSET(CCERH,EDMA_RGET(CCERH) | (1<<(chaNum-32)));
  int_enable(gie);
}
