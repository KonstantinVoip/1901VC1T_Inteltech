
#include <rts_edma3.h>

/* =============================================================================
 *   @n@b CSL_edma3DmaRegionAccessDisable
 *
 *   @b Description
 *   @n This API clears the DRAE/DRAEH BitMask..Disable shadow region access bits
 *      DRAE,DRAEH.
 *
 * ===========================================================================
 */
int32 EDMA3_dmaRegionAccessDisable(
    CSL_Edma3Handle     hModule,
    int32               edmaRegion,
    uint32          	drae,
    uint32          	draeh
)
{
    if( edmaRegion == CSL_EDMA3_REGION_GLOBAL )
    {
        return OSE_BAD_PARAM;
    }
    
    hModule->regs->DRA[edmaRegion].DRAE &= ~drae;
    hModule->regs->DRA[edmaRegion].DRAEH &= ~draeh;
    
    return OSE_OK;
}



