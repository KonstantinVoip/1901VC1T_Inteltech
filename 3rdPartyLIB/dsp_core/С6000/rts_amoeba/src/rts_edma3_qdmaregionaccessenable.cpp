
#include <rts_edma3.h>

/* =============================================================================
 *   @n@b CSL_edma3QdmaRegionAccessEnable
 *
 *   @b Description
 *   @n This API sets the QRAE BitMask.Enables shadow region access bits QRAE
 *
 * ===========================================================================
 */
int32 EDMA3_qdmaRegionAccessEnable(
    CSL_Edma3Handle        hModule,
    int32                  edmaRegion,
    uint32          qrae
)
{
    if( edmaRegion == CSL_EDMA3_REGION_GLOBAL )
    {
        return OSE_BAD_PARAM;
    }
    
    hModule->regs->QRAE[edmaRegion] |= qrae;
    
    return OSE_OK;
}



