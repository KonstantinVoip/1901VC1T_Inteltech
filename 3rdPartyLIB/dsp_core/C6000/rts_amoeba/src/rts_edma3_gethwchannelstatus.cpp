
#include <rts_edma3.h>


int32  EDMA3_gethwchannelstatus(
    CSL_Edma3ChannelHandle             hEdma,
    CSL_Edma3HwChannelStatusQuery      myQuery,
    void                               *response
)
{
    int32 status = OSE_OK;
    
    if( hEdma == NULL )
    {
        status = OSE_NULL_PARAM;
    }
    else if( response == NULL )
    {
        status = OSE_BAD_PARAM;
    }
    else
    {
        switch( myQuery )
        {
            case CSL_EDMA3_QUERY_CHANNEL_STATUS:    
                status = EDMA3_getChannelStatus( hEdma, (bool*)response );
                break;
                
            case CSL_EDMA3_QUERY_CHANNEL_ERR:     
                status = EDMA3_getChannelErrStatus( hEdma, (CSL_Edma3ChannelErr*)response );
                break;
                
            default:
                status = OSE_BAD_ACTION;
                break;
        }
    }

    return( status );
}



