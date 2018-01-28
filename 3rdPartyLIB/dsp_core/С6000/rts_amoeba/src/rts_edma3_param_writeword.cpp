
#include <rts_edma3.h>

int32  EDMA3_paramWriteWord(
    CSL_Edma3ParamHandle       hParamHndl,
    uint32                     wordOffset,
    uint32                     word 
)
{
    uint32        *hParam = (uint32*)(hParamHndl);
    int32    status = OSE_OK;
    
    if( hParamHndl == NULL )
    {
        status = OSE_NULL_PARAM;
    }
    else
    {
        hParam[wordOffset] = word;
    }
    
    return( status );
}

