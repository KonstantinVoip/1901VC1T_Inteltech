
#include <rts_edma3.h>

/* =============================================================================
 *   @n@b CSL_Edma3QueThresholdSet
 *
 *   @b Description
 *   @n Sets the specified threshold for the specified queue.This API sets the 
 *      Queue threshold to the appropriate level.
 * 
 * ===========================================================================
 */
int32 EDMA3_eventQueueThresholdSet(
    CSL_Edma3Handle      hModule,
    CSL_Edma3Que         que,
    CSL_Edma3QueThr      threshold
)
{
    uint32 temp;

	if( que < 4 )
	{
		CSL_FINSR(hModule->regs->QWMTHRA, (8 * que + 4),(8 * que),threshold);
    }
    else
	{
		temp = que - 4;
		CSL_FINSR(hModule->regs->QWMTHRB, (8 * temp + 4),(8 * temp),threshold);
	}

    return OSE_OK;
}




