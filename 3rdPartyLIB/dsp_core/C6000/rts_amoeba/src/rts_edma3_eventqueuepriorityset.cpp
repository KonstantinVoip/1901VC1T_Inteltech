
#include <rts_edma3.h>

/* =============================================================================
 *   @n@b CSL_edma3EventQueuePrioritySet
 *
 *   @b Description
 *   @n This API sets the Queue priority level to the appropriate value.
 *
 * ===========================================================================
 */
int32 EDMA3_eventQueuePrioritySet(
    CSL_Edma3Handle      hModule,
    CSL_Edma3Que         que,
    CSL_Edma3QuePri      pri
)
{
    CSL_FINSR( hModule->regs->QUEPRI, (4 * que + 2), (4 * que), pri );
    
    return OSE_OK;
} 



