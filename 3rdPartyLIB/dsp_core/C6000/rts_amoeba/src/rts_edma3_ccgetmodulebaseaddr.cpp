
#include <rts_edma3.h>

int32 EDMA3_ccGetModuleBaseAddr(
    int32                       edmaNum,
    CSL_Edma3ModuleAttr         *pParam,
    CSL_Edma3ModuleBaseAddress  *pBaseAddress 
)
{
    int32 status = OSE_OK;

    if (pBaseAddress == NULL) {
        status = OSE_BAD_PARAM;
	}
    else {
        switch (edmaNum) {
            case CSL_EDMA3:
                pBaseAddress->regs = (CSL_Edma3ccRegsOvly)CSL_EDMA3CC_0_REGS;
                break;

            default:
                pBaseAddress->regs = (CSL_Edma3ccRegsOvly)NULL;
                status = OSE_FAIL;
        }
    }
    return( status );
}



