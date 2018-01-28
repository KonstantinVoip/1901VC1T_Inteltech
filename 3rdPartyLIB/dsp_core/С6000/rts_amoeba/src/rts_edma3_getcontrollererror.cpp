
#include <rts_edma3.h>

/* ============================================================================
 *   @n@b CSL_edma3GetControllerError
 *
 *   @b Description
 *   @n Gets the status of the controller Error.
 *
 * ===========================================================================
 */
int32 EDMA3_getControllerError( CSL_Edma3Handle hModule, CSL_Edma3CtrlErrStat *ccStat )
{ 
    ccStat->error = hModule->regs->CCERR & 0xFF ; 
    ccStat->exceedTcc = (bool)(CSL_FEXT(hModule->regs->CCERR, \
                                        EDMA3CC_CCERR_TCCERR)) ;
    
    return OSE_OK;     
}




