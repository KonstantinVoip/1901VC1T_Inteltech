#include <rts.h>
uint32 EDMA_getChannel(EDMA_Handle hEdma)
{
  int chaNum = (hEdma & 0x00FF0000)>>16;

    if (chaNum < 32) return (uint32)(((EDMA_RGET(ERL)>>chaNum) & 1) ==1);
    else return (uint32)(((EDMA_RGET(ERH)>>(chaNum-32)) & 1)==1);
}
