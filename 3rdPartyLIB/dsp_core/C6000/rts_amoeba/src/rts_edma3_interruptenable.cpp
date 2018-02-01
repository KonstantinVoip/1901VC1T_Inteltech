
#include <rts_edma3.h>

/* =============================================================================
 *   @n@b CSL_edma3InterruptEnable
 *
 *   @b Description
 *   @n Enables the specified interrupt in the Global Channel register space.
 *      This API enables the interrupts as specified in the BitMask.
 *
 * ===========================================================================
 */    
int32 EDMA3_interruptEnable(
    CSL_Edma3Handle        hModule,
    int32                  region,
    uint32          intrLo,
    uint32          intrHi
)
{
    
    if( region != CSL_EDMA3_REGION_GLOBAL )
    {
        hModule->regs->SHADOW[region].IESR = intrLo;
        hModule->regs->SHADOW[region].IESRH = intrHi;
    } 
    else
    {
        hModule->regs->IESR = intrLo;
        hModule->regs->IESRH = intrHi;
    }
    
    return OSE_OK; 
}



