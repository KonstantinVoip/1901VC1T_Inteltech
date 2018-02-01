
#include <rts_edma3.h>

int32 EDMA3_getHwStatus( CSL_Edma3Handle        hMod, 
                         CSL_Edma3HwStatusQuery myQuery,
                         void                   *response )
{
    int32 status = OSE_OK;
    
    if( hMod == NULL )
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
#if CSL_EDMA3_MEMPROTECT        
            case CSL_EDMA3_QUERY_MEMFAULT:  
                status = EDMA3_getMemoryFaultError( hMod, (CSL_Edma3MemFaultStat*)response );
                break;  
            case CSL_EDMA3_QUERY_MEMPROTECT:    
                ((CSL_Edma3CmdRegion*)response)->regionVal = \
                    EDMA3_getMemoryProtectionAttrib( hMod, ((CSL_Edma3CmdRegion*)response)->region );
                break;              
#endif              
            case CSL_EDMA3_QUERY_CTRLERROR: 
                status = EDMA3_getControllerError( hMod, (CSL_Edma3CtrlErrStat*)response );
                break;          
            case CSL_EDMA3_QUERY_INTRPEND:  
                status = EDMA3_getIntrPendStatus( hMod, \
                                       ((CSL_Edma3CmdIntr*)response)->region, \
                                       &((CSL_Edma3CmdIntr*)response)->intr, \
                                       &((CSL_Edma3CmdIntr*)response)->intrh );
                break;          
            
            case CSL_EDMA3_QUERY_EVENTMISSED:   
                status = \
                EDMA3_getEventMissed( hMod,&((uint32*)response)[0],\
                                        &((uint32*)response)[1], \
                                        &((uint32*)response)[2] );
                break;   
            case CSL_EDMA3_QUERY_QUESTATUS: 
                status = \
                EDMA3_getQueStatus( hMod,((CSL_Edma3QueStat*)response)->que,\
                                     ((CSL_Edma3QueStat*)response) );
                break;  
            case CSL_EDMA3_QUERY_ACTIVITY:
                status = \
                EDMA3_getActivityStatus( hMod,\
                                           ((CSL_Edma3ActivityStat*)response) );
                break;
            case  CSL_EDMA3_QUERY_INFO:
                status = EDMA3_getInfo( hMod,((CSL_Edma3QueryInfo*)response) );
                break;
            default:
                status = OSE_BAD_ACTION;
                break; 
        }  
    }

    return( status );
}

