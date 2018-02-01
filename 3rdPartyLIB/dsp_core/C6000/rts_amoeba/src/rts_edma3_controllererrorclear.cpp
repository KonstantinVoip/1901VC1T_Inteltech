
#include <rts_edma3.h>

/* =============================================================================
 *   @n@b CSL_edma3ControllerErrorClear
 *
 *   @b Description
 *   @n Channel Controller Error Fault.
 * 
 * ===========================================================================
 */    
int32 EDMA3_controllerErrorClear(
    CSL_Edma3Handle         hModule,
    CSL_Edma3CtrlErrStat   *ccStat
)
{
    /* Clears the errors */
    hModule->regs->CCERRCLR = CSL_FMK(EDMA3CC_CCERRCLR_TCCERR, \
                                      ccStat->exceedTcc) | ccStat->error;
                             
    return OSE_OK;
}


