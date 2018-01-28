
#include <rts_edma3.h>

/* =============================================================================
 *   @n@b CSL_edma3InterruptDisable
 *
 *   @b Description
 *   @n Disables the specified interrupt in the Global Channel register space.
 *      This API disables the interrupts as specified in the BitMask.
 *
 * ===========================================================================
 */    

int32 EDMA3_interruptDisable(
    CSL_Edma3Handle        hModule,
    int32                  region,
    uint32          intrLo,
    uint32          intrHi
)
{
    if( region !=CSL_EDMA3_REGION_GLOBAL )
    {
        hModule->regs->SHADOW[region].IECR = intrLo;
        hModule->regs->SHADOW[region].IECRH = intrHi;
    } 
    else
    {
        hModule->regs->IECR  = intrLo;
        hModule->regs->IECRH = intrHi;
    }
    
    return OSE_OK; 
}



