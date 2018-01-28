
#include <rts_edma3.h>

/* =============================================================================
 *   @n@b CSL_edma3MemFaultClear
 *
 *   @b Description
 *   @n Clear Memory Fault.
 * 
 * ===========================================================================
 */    
int32 EDMA3_memFaultClear( CSL_Edma3Handle hModule )
{
    hModule->regs->MPFCR = 1;
    
    return OSE_OK; 
}



