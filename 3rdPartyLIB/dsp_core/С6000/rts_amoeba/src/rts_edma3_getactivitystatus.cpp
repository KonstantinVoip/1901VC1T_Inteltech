
#include <rts_edma3.h>

/* =============================================================================
 *   @n@b CSL_edma3GetActivityStatus
 *
 *   @b Description
 *   @n Obtains the Channel Controller Activity Status
 * 
 * ===========================================================================
 */   
int32 EDMA3_getActivityStatus( CSL_Edma3Handle hModule, CSL_Edma3ActivityStat *activityStat )
{
    uint32 ccstat = hModule->regs->CCSTAT;
    
    activityStat->active = (bool)CSL_FEXT(ccstat,EDMA3CC_CCSTAT_ACTV);
    activityStat->evtActive = (bool)CSL_FEXT(ccstat,EDMA3CC_CCSTAT_EVTACTV);
    activityStat->outstandingTcc = CSL_FEXT(ccstat,EDMA3CC_CCSTAT_COMPACTV);
    activityStat->qevtActive = (bool)CSL_FEXT(ccstat,EDMA3CC_CCSTAT_QEVTACTV);
    activityStat->queActive = CSL_FEXTR(ccstat,23,16);
    activityStat->trActive = (bool)CSL_FEXT(ccstat,EDMA3CC_CCSTAT_TRACTV); 
         
    return OSE_OK;
}



