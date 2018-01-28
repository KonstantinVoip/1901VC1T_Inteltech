
#include <rts_edma3.h>

#if CSL_EDMA3_MEMPROTECT 

/* ============================================================================
 *   @n@b CSL_edma3GetMemoryProtectionAttrib
 *
 *   @b Description
 *   @n Queries the Memory Access rights of the specified region. This 
 *      may be global/view.Gets the memory protection attributes.
 *
 * ===========================================================================
 */
uint32 EDMA3_getMemoryProtectionAttrib( CSL_Edma3Handle hModule, int32 region )
{
    /* Memory protection page fault attribute */
    uint32         mppa;
    
    if( region < 0 )
    {
        mppa = hModule->regs->MPPAG;
    }
    else
    {
        mppa = hModule->regs->MPPA[region];
    }
                 
    return  mppa;
}

#endif



