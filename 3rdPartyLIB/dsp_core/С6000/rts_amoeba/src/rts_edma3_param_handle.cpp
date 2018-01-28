
#include <rts_edma3.h>

/* ============================================================================
 *    CSL_edma3GetParamHandle
 * =============================================================================
 */

CSL_Edma3ParamHandle  EDMA3_getParamHandle (
    CSL_Edma3ChannelHandle    hEdma,
    int32                     paramNum,
    int32                     *status       
)
{   
    CSL_Edma3ParamHandle handle = (CSL_Edma3ParamHandle)NULL;

    if( status == NULL )
    {
        /* Do nothing */
    }
    else if( hEdma == NULL )
    {
        *status = OSE_NULL_PARAM;
    }
    else if( paramNum < 0 || (paramNum >= CSL_EDMA3_NUM_PARAMSETS) )
    {
        *status = OSE_BAD_PARAM;
    }
    else
    {
        handle = (&hEdma->regs->PARAMSET[paramNum ]);
        *status = OSE_OK;
    }

    return( handle );
}



