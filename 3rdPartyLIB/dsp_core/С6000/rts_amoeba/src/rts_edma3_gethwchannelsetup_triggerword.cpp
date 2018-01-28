
#include <rts_edma3.h>
//#include <csl_edma3Aux.h>

int32  CSL_edma3GetHwChannelSetupTriggerWord( CSL_Edma3ChannelHandle hEdma,
                                              uint8                 *triggerWord )
{
    int32    status = OSE_OK;

    if( hEdma == NULL )
    {
        status = OSE_NULL_PARAM;
    }
    else
    {
        if( hEdma->chaNum  < CSL_EDMA3_NUM_DMACH )
        {
            status = OSE_BAD_PARAM;
        } 
        else
        {
            *triggerWord = \
                CSL_FEXT(hEdma->regs->QCHMAP[hEdma->chaNum-CSL_EDMA3_NUM_DMACH], \
                      EDMA3CC_QCHMAP_TRWORD);
        }
    }
    
    return( status ); 
}



