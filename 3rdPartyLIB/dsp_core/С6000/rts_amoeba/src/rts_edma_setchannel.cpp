#include <rts.h>
void EDMA_setChannel(EDMA_Handle hEdma)
{
  int chaNum = (hEdma & 0x00FF0000)>>16;

  if (chaNum < 32) EDMA_RSET(ESRL,1<<chaNum);
  else EDMA_RSET(ESRH,1<<(chaNum-32));
}
