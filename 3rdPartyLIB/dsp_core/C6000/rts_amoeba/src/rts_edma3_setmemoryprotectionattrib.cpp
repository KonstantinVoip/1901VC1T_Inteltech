
#include <rts_edma3.h>

/* =============================================================================
 *   @n@b CSL_edma3SetMemoryProtectionAttrib
 *
 *   @b Description
 *   @n This API sets the memory protection attributes for the specified region.
 *      Sets specified memory protection attributes for the specifed region.
 *
 * ===========================================================================
 */
#if CSL_EDMA3_MEMPROTECT 

int32 EDMA3_setMemoryProtectionAttrib(
    CSL_Edma3Handle     hModule,
    int32               edmaRegion,
    uint32              mppa
)
{    
    if( edmaRegion == CSL_EDMA3_REGION_GLOBAL )
    {
        hModule->regs->MPPAG = mppa;
    }
    else
    {
        hModule->regs->MPPA[edmaRegion] = mppa;
    }
    
    return OSE_OK;
}

#endif


