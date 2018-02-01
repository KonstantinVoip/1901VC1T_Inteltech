
#include <rts_edma3.h>

/* =============================================================================
 *   @n@b CSL_edma3GetInfo
 *
 *   @b Description
 *   @n Obtains the Channel Controller's Information
 * 
 * ===========================================================================
 */   
int32 EDMA3_getInfo( CSL_Edma3Handle hModule, CSL_Edma3QueryInfo *response )
{
    response->config   = hModule->regs->CCCFG; 
    response->revision = hModule->regs->PID; 
    
    return OSE_OK;
}



