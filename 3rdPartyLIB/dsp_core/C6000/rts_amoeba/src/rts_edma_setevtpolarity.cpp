#include <rts.h>
void EDMA_setEvtPolarity(EDMA_Handle hEdma,int polarity)
{

    int chaNum = (hEdma & 0x00FF0000)>>16;

    if (chaNum < 32) EDMA_RSET(EPRL,polarity<<chaNum);
    else EDMA_RSET(EPRH,polarity<<(chaNum-32));
}
