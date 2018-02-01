
#include <rts_edma3.h>

/* ============================================================================
 *   @n@b CSL_edma3GetEventMissed
 *
 *   @b Description
 *   @n Queries all the events missed.Since there may be upto 64 EDMA 
 *      channels + upto 8 QDMA channels,this points to an  array of 3, 
 *      32 bit elements.Gets the status of the missed events.
 *
 * ===========================================================================
 */

int32 EDMA3_getEventMissed( CSL_Edma3Handle  hModule,
                            uint32           *missedLo,
                            uint32           *missedHi,
                            uint32           *missedQdma
)
{
    /* Reading the missed Status registers */
    *missedLo    = hModule->regs->EMR;
    *missedHi    = hModule->regs->EMRH;
    *missedQdma  = hModule->regs->QEMR;
    
    return OSE_OK;     
}



