
#include <rts_edma3.h>

/* =============================================================================
 *   @n@b CSL_edma3HwChannelDisable
 *
 *   @b Description
 *   @n This API disables the event associated with the Channel. Disables 
 *      the channel
 * 
 * ===========================================================================
 */   
int32 EDMA3_channelDisable( CSL_Edma3ChannelHandle hEdma )
{
    /* Ensure this is a normal channel and not a QDMA channel */
    if( hEdma->region ==CSL_EDMA3_REGION_GLOBAL )
    {
        if( hEdma->chaNum >= CSL_EDMA3_NUM_DMACH )
		{
            hEdma->regs->QEECR = (1 << (hEdma->chaNum - CSL_EDMA3_NUM_DMACH));
        }
        else if( hEdma->chaNum < 32 )
		{
            hEdma->regs->EECR = (1 << hEdma->chaNum);
		}
        else
		{
            hEdma->regs->EECRH = (1 << (hEdma->chaNum - 32));
		}
    }
    else
    {
        if( hEdma->chaNum >= CSL_EDMA3_NUM_DMACH )
		{
            hEdma->regs->SHADOW[hEdma->region].QEECR = 
                                  (1 << (hEdma->chaNum - CSL_EDMA3_NUM_DMACH));
		}
        else if( hEdma->chaNum < 32 )
		{
            hEdma->regs->SHADOW[hEdma->region].EECR = (1 << hEdma->chaNum);
		}
        else
		{
            hEdma->regs->SHADOW[hEdma->region].EECRH = 
                                                    (1 << (hEdma->chaNum - 32));
		}
    }
    return OSE_OK;     
}



