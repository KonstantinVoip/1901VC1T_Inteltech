
#include <rts_edma3.h>

/* =============================================================================
 *   @n@b CSL_edma3ChannelEventSet
 *
 *   @b Description
 *   @n Manually triggers an EDMA event by setting the ER register
 * 
 * ===========================================================================
 */   
int32 EDMA3_channelEventSet( CSL_Edma3ChannelHandle hEdma )
{
    if( hEdma->region == CSL_EDMA3_REGION_GLOBAL )
    {
        if( hEdma->chaNum < 32 )
		{
            hEdma->regs->ESR = (1 << hEdma->chaNum);
		}
        else if( hEdma->chaNum < CSL_EDMA3_NUM_DMACH )
		{
            hEdma->regs->ESRH = (1 << (hEdma->chaNum - 32));
		}
        else
		{
            return OSE_BAD_PARAM;
		}
    } 
    else
    {
        if( hEdma->chaNum < 32 )
		{
            hEdma->regs->SHADOW[hEdma->region].ESR = (1 << hEdma->chaNum);
		}
        else if( hEdma->chaNum < CSL_EDMA3_NUM_DMACH )
		{
            hEdma->regs->SHADOW[hEdma->region].ESRH = 
                                                (1 << (hEdma->chaNum - 32));
		}
        else
		{
            return OSE_BAD_PARAM;
		}
    }
               
    return OSE_OK;
}


