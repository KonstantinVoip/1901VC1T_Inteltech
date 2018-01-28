
#include <rts_edma3.h>


int32  EDMA3_getHwChannelSetupParam( CSL_Edma3ChannelHandle  hEdma,
                                     uint32                 *paramNum )
{
    int32    status = OSE_OK;

    if( hEdma == NULL )
    {
        status = OSE_NULL_PARAM;        
    }
    else if( paramNum == NULL )
    {
        status = OSE_BAD_PARAM;
    }
    else
    {
        if( hEdma->chaNum  < CSL_EDMA3_NUM_DMACH )
        {
#if CSL_EDMA3_CHMAPEXIST        
            *paramNum = CSL_FEXT(hEdma->regs->DCHMAP[hEdma->chaNum], \
                                 EDMA3CC_DCHMAP_PAENTRY);           
#endif      
        } 
        else
        {
            *paramNum = 
             CSL_FEXT(hEdma->regs->QCHMAP[hEdma->chaNum-CSL_EDMA3_NUM_DMACH],\
                        EDMA3CC_QCHMAP_PAENTRY);
        }
    }

    return( status ); 
}




