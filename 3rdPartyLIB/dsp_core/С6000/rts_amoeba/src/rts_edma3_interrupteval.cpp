
#include <rts_edma3.h>

/* =============================================================================
 *   @n@b CSL_edma3InterruptEval
 *
 *   @b Description
 *   @n If any enabled interrutps are pending, the tpcc_intN output signal 
 *      to be pulsed.
 *
 * ===========================================================================
 */    
int32 EDMA3_interruptEval( CSL_Edma3Handle hModule, int32 region )
{
    if( region != CSL_EDMA3_REGION_GLOBAL )
    {
        hModule->regs->SHADOW[region].IEVAL = 1;
    }
    else
    {
        hModule->regs->IEVAL = 1; 
    }
          
    return OSE_OK; 
}



