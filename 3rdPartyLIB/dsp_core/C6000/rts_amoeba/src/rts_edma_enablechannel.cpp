#include <rts.h>
void EDMA_enableChannel(EDMA_Handle hEdma)
{
  register volatile uint32 gie;
  int chaNum = (hEdma & 0x00FF0000)>>16;

  gie = int_disable();
  if (chaNum < 32) EDMA_RSET(EERL,EDMA_RGET(EERL) | (1<<chaNum));
  else EDMA_RSET(EERH,EDMA_RGET(EERH) | (1<<(chaNum-32)));
  int_enable(gie);
}
