
#include <rts_edma3.h>

/* =============================================================================
 *   @n@b CSL_edma3ChannelEventClear
 *
 *   @b Description
 *   @n This API clears the event (if set) for the channel .Clears the EDMA 
 *      event by writing the ECR register for normal channels for QDMA channels
 * 
 * ===========================================================================
 */   
int32 EDMA3_channelEventClear( CSL_Edma3ChannelHandle hEdma )
{       
    if( hEdma->region ==CSL_EDMA3_REGION_GLOBAL )
    {
        if( hEdma->chaNum >= CSL_EDMA3_NUM_DMACH )
		{
            return OSE_BAD_PARAM;
		}
        else if( hEdma->chaNum < 32 )
		{
            hEdma->regs->ECR = (1 << hEdma->chaNum);
		}
        else
		{
            hEdma->regs->ECRH = (1 << (hEdma->chaNum - 32));
		}
    } 
    else
    {
        if( hEdma->chaNum >= CSL_EDMA3_NUM_DMACH )
		{
            return OSE_BAD_PARAM;
        }
        else
        {
            if( hEdma->chaNum < 32 )
			{
                hEdma->regs->SHADOW[hEdma->region].ECR = (1 << hEdma->chaNum);
			}
            else
			{
                hEdma->regs->SHADOW[hEdma->region].ECRH = 
                                                (1 << (hEdma->chaNum - 32));
			}
        }
    }
    
    return OSE_OK;     
}



