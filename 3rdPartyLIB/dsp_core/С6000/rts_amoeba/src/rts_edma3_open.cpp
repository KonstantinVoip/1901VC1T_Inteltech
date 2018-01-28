
#include <rts_edma3.h>


CSL_Edma3Handle  EDMA3_open (
    CSL_Edma3Obj            *pEdmaObj,
    int32                   edmaNum,
    CSL_Edma3ModuleAttr     *pAttr,
    int32                   *pStatus
)
{
    CSL_Edma3ModuleBaseAddress    baseAddress;
    CSL_Edma3Handle               hEdma = (CSL_Edma3Handle)NULL;
    
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
        *pStatus = EDMA3_ccGetModuleBaseAddr( edmaNum, pAttr, &baseAddress );
        if( *pStatus == OSE_OK )
        {
            pEdmaObj->regs = baseAddress.regs;
            pEdmaObj->instNum = (int16)edmaNum;
            hEdma = (CSL_Edma3Handle)pEdmaObj;
        }
        else
        {
            pEdmaObj->regs = (CSL_Edma3ccRegsOvly)NULL;
            pEdmaObj->instNum = (int16) -1;
        }
    }

    return( hEdma );
}

