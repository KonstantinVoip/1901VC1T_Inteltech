
#include <rts_edma3.h>

int32 EDMA3_paramSetup (
    CSL_Edma3ParamHandle       hParamHndl,
    CSL_Edma3ParamSetup        *setup
)
{
    uint32      *paramHndl = (uint32*)hParamHndl;
    uint32      i;
    int32       status = OSE_OK;
    
    if( hParamHndl == NULL )
    {
        status = OSE_NULL_PARAM;
    }
    else if( setup == NULL )
    {
        status = OSE_BAD_PARAM;
    }
    else
    {
        for( i = 0; i < 8 ; i++ )
        {
            paramHndl[i] = ((uint32*)setup)[i];
        }
    }

    return( status );
}



