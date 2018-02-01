
#include <rts_edma3.h>

int32 CSL_edma3HwChannelSetupTriggerWord(
    CSL_Edma3ChannelHandle      hEdma,
    uint8                       triggerWord   
)
{
    int32 status = OSE_OK;

    if( hEdma == NULL )
    {
        status = OSE_NULL_PARAM;
    }
    else if( triggerWord > 7 )
    {
        status = OSE_BAD_PARAM;
    }
    else if( hEdma->chaNum  < CSL_EDMA3_NUM_DMACH )
    {
        /* CSL_edma3ChannelSetEvtQue(hEdma,setup->que); */    
        status = OSE_BAD_PARAM;
    } 
    else
    {
        CSL_FINS(hEdma->regs->QCHMAP[hEdma->chaNum-CSL_EDMA3_NUM_DMACH], \
                     EDMA3CC_QCHMAP_TRWORD,triggerWord);
    }
    
    return( status ); 
}


