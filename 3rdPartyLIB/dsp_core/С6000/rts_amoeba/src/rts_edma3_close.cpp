
#include <rts_edma3.h>


int32 EDMA3_close( CSL_Edma3Handle hEdma )
{   
    int32    status = OSE_OK;
    
    if( hEdma != NULL )
    {
        hEdma->regs = (CSL_Edma3ccRegsOvly) NULL;
        hEdma->instNum = (int16)-1;
    } 
    else
    {
        status = OSE_NULL_PARAM;
    }
    
    return( status );
}

