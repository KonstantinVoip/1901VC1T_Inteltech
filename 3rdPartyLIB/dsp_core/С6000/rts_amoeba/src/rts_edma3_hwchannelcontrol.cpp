
#include <rts_edma3.h>


int32 EDMA3_hwChannelControl( CSL_Edma3ChannelHandle        hCh,
                               CSL_Edma3HwChannelControlCmd  cmd,
                               void                         *cmdArg )
{ 
    int32 status = OSE_OK;
    
    if( hCh == NULL )
    {
        status = OSE_NULL_PARAM;
    }
    else if( (cmd == CSL_EDMA3_CMD_CHANNEL_CLEARERR) && (cmdArg == NULL) )
    {
        status = OSE_BAD_PARAM;
    }
    else
    {
        switch( cmd )
        {
            case CSL_EDMA3_CMD_CHANNEL_ENABLE:
                status = EDMA3_channelEnable( hCh );
                break;
            
            case CSL_EDMA3_CMD_CHANNEL_DISABLE:
                status = EDMA3_channelDisable( hCh );
                break;
            
            case CSL_EDMA3_CMD_CHANNEL_SET:
                status = EDMA3_channelEventSet( hCh );
                break;
            
            case CSL_EDMA3_CMD_CHANNEL_CLEAR:
                status = EDMA3_channelEventClear( hCh );
                break;          
            
            case CSL_EDMA3_CMD_CHANNEL_CLEARERR:
                status = EDMA3_channelErrorClear( hCh, (CSL_Edma3ChannelErr*)cmdArg );
                break;
            
            default:
                status = OSE_BAD_CMD;
                break;
        }
    }

    return( status );
}

