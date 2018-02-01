
#include <rts_edma3.h>

/* =============================================================================
 *   @n@b CSL_Edma3GetChannelErrStatus
 *
 *   @b Description
 *   @n Obtains the Channel Error Status.
 * 
 * ===========================================================================
 */   
int32 EDMA3_getChannelErrStatus( CSL_Edma3ChannelHandle hChannel, CSL_Edma3ChannelErr *errClr )
{
    
    errClr->missed = false;
    errClr->secEvt = false;
    
    if( hChannel->chaNum < CSL_EDMA3_NUM_DMACH )
    {
        if( hChannel->chaNum < 32 )
        {
            if( CSL_FEXTR(hChannel->regs->EMR,hChannel->chaNum, 
                hChannel->chaNum) )
			{
				errClr->missed = true;
			}
            if( CSL_FEXTR(hChannel->regs->SER,hChannel->chaNum, 
                hChannel->chaNum) )
			{
				errClr->secEvt = true;
			}
        } 
        else
        {
            if( CSL_FEXTR(hChannel->regs->EMRH,hChannel->chaNum-32, \
                          hChannel->chaNum-32) )
			{
                errClr->missed = true;
			}
            if( CSL_FEXTR(hChannel->regs->SERH,hChannel->chaNum-32, \
                          hChannel->chaNum-32) )
			{
                errClr->secEvt = true;
			}
        }
    }
    else
    {
        if( CSL_FEXTR(hChannel->regs->QEMR,hChannel->chaNum-CSL_EDMA3_NUM_DMACH, 
                      hChannel->chaNum-CSL_EDMA3_NUM_DMACH) )
		{
			errClr->missed = true;
		}
        if( CSL_FEXTR(hChannel->regs->QSER,hChannel->chaNum-CSL_EDMA3_NUM_DMACH,
                      hChannel->chaNum-CSL_EDMA3_NUM_DMACH) )
		{
			errClr->secEvt = true;
		}
    }
    
    return OSE_OK;
}





