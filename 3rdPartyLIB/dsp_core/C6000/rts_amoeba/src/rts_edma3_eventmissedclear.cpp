
#include <rts_edma3.h>

/* =============================================================================
 *   @n@b CSL_edma3EventMissedClear
 *
 *   @b Description
 *   @n Clear the Event missed errors
 * 
 * ===========================================================================
 */   
int32 EDMA3_eventsMissedClear(
    CSL_Edma3Handle        hModule,
    uint32          missedLo,
    uint32          missedHi,
    uint32          missedQdma
)
{
    hModule->regs->EMCR   = missedLo;
    hModule->regs->EMCRH  = missedHi;
    hModule->regs->QEMCR  = missedQdma;
    
    return OSE_OK;
}


