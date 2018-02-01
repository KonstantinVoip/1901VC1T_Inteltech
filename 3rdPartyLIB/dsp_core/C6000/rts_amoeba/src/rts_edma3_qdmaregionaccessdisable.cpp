
#include <rts_edma3.h>

/* =============================================================================
 *   @n@b CSL_edma3QdmaRegionAccessDisable
 *
 *   @b Description
 *   @n This API clears the QRAE BitMask.Disables shadow region access bits QRAE
 *
 * ===========================================================================
 */
int32 EDMA3_qdmaRegionAccessDisable(
    CSL_Edma3Handle     hModule,
    int32               edmaRegion,
    uint32          	qrae
)
{ 
    if( edmaRegion == CSL_EDMA3_REGION_GLOBAL )
    {
        return OSE_BAD_PARAM;
    }
        
    hModule->regs->QRAE[edmaRegion] &= ~qrae;
    
    return OSE_OK;
}



