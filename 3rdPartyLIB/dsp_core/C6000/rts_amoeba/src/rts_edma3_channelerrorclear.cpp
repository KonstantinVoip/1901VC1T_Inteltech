
#include <rts_edma3.h>

/* =============================================================================
 *   @n@b CSL_Edma3ChannelErrorClear
 *
 *   @b Description
 *   @n Clears the channel and associated error conditions:- Clears 
 *      EMR/EMRH/QEMR and  SER/SERH/QSER. 
 *
 * ===========================================================================
 */   
int32 EDMA3_channelErrorClear(
    CSL_Edma3ChannelHandle      hChannel,
    CSL_Edma3ChannelErr         *errClr
)
{
    if( errClr->missed == true )
    {
        if( hChannel->chaNum < CSL_EDMA3_NUM_DMACH )
        {
            if( hChannel->chaNum < 32 )
            {
                hChannel->regs->EMCR = 1 << hChannel->chaNum;
                if( errClr->secEvt == true )
				{
                    hChannel->regs->SECR = 1 << hChannel->chaNum;
				}
            } 
            else
            {
                hChannel->regs->EMCRH = 1 << (hChannel->chaNum - 32);
                if( errClr->secEvt == true )
				{
                    hChannel->regs->SECRH = 1 << (hChannel->chaNum - 32);
				}
            }
        }
        else
        {
           hChannel->regs->QEMR = 1 << (hChannel->chaNum - CSL_EDMA3_NUM_DMACH);
           if( errClr->secEvt == true )
		   {
               hChannel->regs->QSECR = 1 << \
                                      (hChannel->chaNum - CSL_EDMA3_NUM_DMACH);
            }
        }
    }
    
    return OSE_OK;
}

