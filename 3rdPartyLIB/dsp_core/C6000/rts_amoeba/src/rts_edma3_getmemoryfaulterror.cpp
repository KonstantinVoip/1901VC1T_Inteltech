
#include <rts_edma3.h>

#if CSL_EDMA3_MEMPROTECT

/* ============================================================================
 *   @n@b CSL_edma3GetMemoryFaultError
 *
 *   @b Description
 *   @n Queries the Channel controllers memory fault error and the error 
 *      attributes.Gets the memory fault status details, clears the fault.
 *
 * ===========================================================================
 */
int32 EDMA3_getMemoryFaultError( CSL_Edma3Handle hModule, CSL_Edma3MemFaultStat *memFault )
{ 
    /* Reading the Memory Fault Status registers */
    memFault->addr = hModule->regs->MPFAR; 
    memFault->error =  CSL_FEXTR(hModule->regs->MPFSR, 8, 0);
    memFault->fid = CSL_FEXTR(hModule->regs->MPFSR, 12, 9);
    
    return OSE_OK;     
}

#endif



