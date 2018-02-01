#include <rts.h>
void EDMA_clearChannel(EDMA_Handle hEdma)
{

  int chaNum = (hEdma & 0x00FF0000)>>16;

  if (chaNum < 32) EDMA_RSET(ECRL,1<<chaNum);
  else EDMA_RSET(ECRH,1<<(chaNum-32));
}
