
#include <rts_edma3.h>

/* =============================================================================
 *   @n@b CSL_edma3ErrorEval
 *
 *   @b Description
 *   @n This API enables enables evaluation of errros for the specified 
 *      view/shadow region.Sets EVAL bit of the EEVAL register in the Global 
 *      register space
 *
 * ===========================================================================
 */    
int32 EDMA3_errorEval( CSL_Edma3Handle hModule )
{
    hModule->regs->EEVAL = 1; 
    
    return OSE_OK;
}



