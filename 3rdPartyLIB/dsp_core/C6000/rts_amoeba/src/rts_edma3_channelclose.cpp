
#include <rts_edma3.h>

int32 EDMA3_channelClose( CSL_Edma3ChannelHandle hEdma )
{
    int32 status = OSE_OK;
    
    if( hEdma != NULL )
    {
        hEdma->regs    = (CSL_Edma3ccRegsOvly) NULL;
        hEdma->edmaNum = (int16) - 1;
        hEdma->region  = -2;  /* -2 specifies the invalid region number */
        hEdma->chaNum  = -1;  /* -1 specifies the invalid channel */
    } 
    else
    {
        status = OSE_NULL_PARAM;
    }
            
    return( status );
}

