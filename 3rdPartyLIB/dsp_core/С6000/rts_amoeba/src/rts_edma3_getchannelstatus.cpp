
#include <rts_edma3.h>

/* =============================================================================
 *   @n@b CSL_Edma3GetChannelStatus
 *
 *   @b Description
 *   @n Obtains the Channel Status i.e whether an even is set.
 * 
 * ===========================================================================
 */   
int32 EDMA3_getChannelStatus( CSL_Edma3ChannelHandle hChannel, bool *response )
{
    if( hChannel->chaNum < CSL_EDMA3_NUM_DMACH )
    {
        if( hChannel->chaNum < 32 )
        {
            if( CSL_FEXTR(hChannel->regs->ER,hChannel->chaNum,hChannel->chaNum) )
			{
                *response = true;
			}
            else
			{
                *response = false;
			}
        } 
        else
        {
            if( CSL_FEXTR(hChannel->regs->ERH,hChannel->chaNum-32, hChannel->chaNum-32) )
			{
                *response = true;
			}
            else
			{
                *response = false;
			}
        }
    }
    else
    {
        if( CSL_FEXTR(hChannel->regs->QER,hChannel->chaNum-CSL_EDMA3_NUM_DMACH,\
                      hChannel->chaNum-CSL_EDMA3_NUM_DMACH) )
		{
			*response = true;
		}
		else
		{
			*response = false;
		}
    }
    return OSE_OK;
}



