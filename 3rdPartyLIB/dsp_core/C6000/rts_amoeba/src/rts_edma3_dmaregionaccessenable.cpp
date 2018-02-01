
#include <rts_edma3.h>

/* =============================================================================
 *   @n@b CSL_edma3DmaRegionAccessEnable
 *
 *   @b Description
 *   @n This API sets the DRAE/DRAEH BitMask.Enables shadow region access bits
 *      DRAE,DRAEH.
 *
 * ===========================================================================
 */
int32 EDMA3_dmaRegionAccessEnable(
    CSL_Edma3Handle     hModule,
    int32               edmaRegion,
    uint32         		drae,
    uint32         		draeh
)
{

    if( edmaRegion == CSL_EDMA3_REGION_GLOBAL )
    {
        return OSE_BAD_PARAM;
    }
    
    hModule->regs->DRA[edmaRegion].DRAE |= drae;
    hModule->regs->DRA[edmaRegion].DRAEH |= draeh;
    
    return OSE_OK;
}



