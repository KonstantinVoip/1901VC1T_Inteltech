
#include <rts_edma3.h>


int32  EDMA3_hwChannelSetupParam( CSL_Edma3ChannelHandle hEdma, uint32 paramNum )
{
    int32 status = OSE_OK;

    if( hEdma == NULL )
    {
        status = OSE_NULL_PARAM;
    }
    else if( paramNum >= CSL_EDMA3_NUM_PARAMSETS )
    {
        status = OSE_BAD_PARAM;
    }
    else
    {
        /* CSL_edma3ChannelSetEvtQue(hCh,setup->que); */
        if( hEdma->chaNum  < CSL_EDMA3_NUM_DMACH )
        {
#if CSL_EDMA3_CHMAPEXIST        
         CSL_FINS( hEdma->regs->DCHMAP[hEdma->chaNum], EDMA3CC_DCHMAP_PAENTRY, paramNum);
#endif      
        }
        else
        {
        
        CSL_FINS(hEdma->regs->QCHMAP[hEdma->chaNum-CSL_EDMA3_NUM_DMACH], \
                 EDMA3CC_QCHMAP_PAENTRY,paramNum);
        }
    }

    return( status );
}



