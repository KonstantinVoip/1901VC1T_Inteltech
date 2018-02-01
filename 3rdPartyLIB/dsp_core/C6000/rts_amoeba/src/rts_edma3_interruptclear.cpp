
#include <rts_edma3.h>

/* =============================================================================
 *   @n@b CSL_edma3InterruptClear
 *
 *   @b Description
 *   @n This API clears the interrupt as specified.Clears the specified 
 *      interrupt in the Global Channel register space.
 *
 * ===========================================================================
 */    
int32 EDMA3_interruptClear(
    CSL_Edma3Handle        hModule,
    int32                  region,
    uint32          intrLo,
    uint32          intrHi
)
{
    if( region != CSL_EDMA3_REGION_GLOBAL )
    {
        hModule->regs->SHADOW[region].ICR = intrLo;
        hModule->regs->SHADOW[region].ICRH = intrHi;
    } 
    else
    {
        hModule->regs->ICR = intrLo;
        hModule->regs->ICRH = intrHi;
    }   
    return OSE_OK; 
}



