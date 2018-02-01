
#include <rts_edma3.h>

CSL_Edma3ChannelHandle EDMA3_channelOpen(
    CSL_Edma3ChannelObj     *pEdmaObj,
    int32             edmaNum,
    CSL_Edma3ChannelAttr    *pChAttr,
    int32              *pStatus
)
{
    CSL_Edma3ChannelHandle        hEdma = (CSL_Edma3ChannelHandle)NULL;
    CSL_Edma3ModuleBaseAddress    baseAddress;
    
    if( pStatus == NULL )
    {
        /* Do nothing : Module handle already initialised to NULL */
    }
    else if( pEdmaObj == NULL )
    {
        *pStatus = OSE_BAD_PARAM;
    }
    else
    {
        if( pChAttr != NULL )
        {
            *pStatus = EDMA3_ccGetModuleBaseAddr( edmaNum, NULL, &baseAddress );
            if( *pStatus == OSE_OK )
            {
                pEdmaObj->regs = baseAddress.regs;
                pEdmaObj->edmaNum = edmaNum;
                pEdmaObj->chaNum = pChAttr->chaNum;
                pEdmaObj->region = pChAttr->regionNum;
                hEdma = (CSL_Edma3ChannelHandle)pEdmaObj;
            }
            else
            {
                pEdmaObj->regs = (CSL_Edma3ccRegsOvly)NULL;
                pEdmaObj->edmaNum = (int32) -1;
                pEdmaObj->chaNum = -1;
                pEdmaObj->region = -2;
            } 
        }
        else
        {
            *pStatus = OSE_BAD_PARAM;
        }        
    }

    return( hEdma );
}

