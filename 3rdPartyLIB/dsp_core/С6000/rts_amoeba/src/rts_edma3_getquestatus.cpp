
#include <rts_edma3.h>

/* =============================================================================
 *   @n@b CSL_edma3GetQueStatus
 *
 *   @b Description
 *   @n Obtains the queue status
 * 
 * ===========================================================================
 */   
int32 EDMA3_getQueStatus(
    CSL_Edma3Handle      hModule,
    CSL_Edma3Que         que,
    CSL_Edma3QueStat    *queStat
)
{
    uint32 qstat = hModule->regs->QSTAT[que];
    
    queStat->waterMark = (uint16)CSL_FEXT(qstat,EDMA3CC_QSTAT_WM);
    queStat->numVal = (uint16)CSL_FEXT(qstat,EDMA3CC_QSTAT_NUMVAL);
    queStat->startPtr = (uint8)CSL_FEXT(qstat,EDMA3CC_QSTAT_STRTPTR);
    queStat->exceed = (bool)CSL_FEXT(qstat,EDMA3CC_QSTAT_THRXD);
    
    return OSE_OK;
}



