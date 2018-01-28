
#include <rts_edma3.h>

/* =============================================================================
 *   @n@b CSL_edma3HwChannelEnable
 *
 *   @b Description
 *   @n This API enables the event associated with the Channel. Enables
 *      the channel
 * 
 * ===========================================================================
 */   
int32 EDMA3_channelEnable( CSL_Edma3ChannelHandle hEdma )
{
    /* Ensure this is a normal channel and not a QDMA channel */
    if( hEdma->region == CSL_EDMA3_REGION_GLOBAL )
    {
        if( hEdma->chaNum >= CSL_EDMA3_NUM_DMACH )
		{
            hEdma->regs->QEESR = (1 << (hEdma->chaNum - CSL_EDMA3_NUM_DMACH));
        }
        else if( hEdma->chaNum < 32 )
		{
            hEdma->regs->EESR = (1 << hEdma->chaNum);
        }
        else
		{
            hEdma->regs->EESRH = (1 << (hEdma->chaNum - 32));
		}
    } 
    else
    {
        if( hEdma->chaNum >= CSL_EDMA3_NUM_DMACH )
		{
            hEdma->regs->SHADOW[hEdma->region].QEESR = \
                                   (1 << (hEdma->chaNum - CSL_EDMA3_NUM_DMACH));
        }
        else if( hEdma->chaNum < 32 )
		{
            hEdma->regs->SHADOW[hEdma->region].EESR = (1 << hEdma->chaNum);
        }
        else
		{
            hEdma->regs->SHADOW[hEdma->region].EESRH = 
                                                 (1 << (hEdma->chaNum - 32));
		}
    }
    
    return OSE_OK;     
}



