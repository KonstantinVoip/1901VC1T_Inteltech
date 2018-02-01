
#include <rts_edma3.h>

/* ============================================================================
 *   @n@b CSL_edma3GetIntrPendStatus
 *
 *   @b Description
 *   @n Queries the interrupt status of the interrupts.This is read from the 
 *      Global Channel Register.Gets the interrupt pend status.
 *
 * ===========================================================================
 */
int32 EDMA3_getIntrPendStatus( CSL_Edma3Handle  hModule,
                                   int32           region,
                                   uint32          *intrLo,
                                   uint32          *intrHi
)
{
    if( region != CSL_EDMA3_REGION_GLOBAL )
    {   
        *intrLo = hModule->regs->SHADOW[region].IPR  ;
        *intrHi = hModule->regs->SHADOW[region].IPRH ;
    } 
    else
    {
        *intrLo = hModule->regs->IPR  ;
        *intrHi = hModule->regs->IPRH ;
    }
    
    return OSE_OK; 
}



