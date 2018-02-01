
#include <rts_edma3.h>


int32  EDMA3_hwControl( CSL_Edma3Handle         hMod,
                        CSL_Edma3HwControlCmd   cmd,
                        void                    *cmdArg )
{ 
    int32    status = OSE_OK; 
    
    if( hMod == NULL )
    {
        status = OSE_NULL_PARAM;
    }
    else if( ((cmd >= 0) && (cmd <= CSL_EDMA3_CMD_EVENTMISSED_CLEAR)) && 
              ((cmd != CSL_EDMA3_CMD_MEMFAULT_CLEAR) && 
               (cmd != CSL_EDMA3_CMD_ERROR_EVAL)) && (cmdArg == NULL) )
    {
        status = OSE_BAD_PARAM;
    }
    else
    {
        switch( cmd )
        {
#if CSL_EDMA3_MEMPROTECT    
            case CSL_EDMA3_CMD_MEMPROTECT_SET:
                status = EDMA3_setMemoryProtectionAttrib( hMod, \
                                     ((CSL_Edma3CmdRegion*)cmdArg)->region,\
                                     ((CSL_Edma3CmdRegion*)cmdArg)->regionVal );
                break;
            case CSL_EDMA3_CMD_MEMFAULT_CLEAR:
                status = EDMA3_memFaultClear(hMod);
                break;
#endif                      
            case CSL_EDMA3_CMD_DMAREGION_ENABLE:
                status = EDMA3_dmaRegionAccessEnable( hMod, \
                                     ((CSL_Edma3CmdDrae*)cmdArg)->region, \
                                     ((CSL_Edma3CmdDrae*)cmdArg)->drae, \
                                     ((CSL_Edma3CmdDrae*)cmdArg)->draeh );
                break;
                
            case CSL_EDMA3_CMD_DMAREGION_DISABLE:
                status = EDMA3_dmaRegionAccessDisable( hMod, \
                                     ((CSL_Edma3CmdDrae*)cmdArg)->region, \
                                     ((CSL_Edma3CmdDrae*)cmdArg)->drae, \
                                     ((CSL_Edma3CmdDrae*)cmdArg)->draeh );
                break;
                
            case CSL_EDMA3_CMD_QDMAREGION_ENABLE:
                status = EDMA3_qdmaRegionAccessEnable( hMod, \
                                     ((CSL_Edma3CmdQrae*)cmdArg)->region,\
                                     ((CSL_Edma3CmdQrae*)cmdArg)->qrae );
                break;
                
            case CSL_EDMA3_CMD_QDMAREGION_DISABLE:
                status = EDMA3_qdmaRegionAccessDisable( hMod, \
                                     ((CSL_Edma3CmdQrae*)cmdArg)->region, \
                                     ((CSL_Edma3CmdQrae*)cmdArg)->qrae );
                break;  
                
            case CSL_EDMA3_CMD_QUEPRIORITY_SET:
                status = EDMA3_eventQueuePrioritySet( hMod, \
                                     ((CSL_Edma3CmdQuePri*)cmdArg)->que, \
                                     ((CSL_Edma3CmdQuePri*)cmdArg)->pri );
                break;
                
            case CSL_EDMA3_CMD_QUETHRESHOLD_SET:
                status = EDMA3_eventQueueThresholdSet( hMod,\
                                     ((CSL_Edma3CmdQueThr*)cmdArg)->que, \
                                     ((CSL_Edma3CmdQueThr*)cmdArg)->threshold );
                break;          
                
            case CSL_EDMA3_CMD_ERROR_EVAL:
                status = EDMA3_errorEval( hMod );
                break;          
                
            case CSL_EDMA3_CMD_INTRPEND_CLEAR:
                status = EDMA3_interruptClear( hMod, \
                                     ((CSL_Edma3CmdIntr*)(cmdArg))->region, \
                                     ((CSL_Edma3CmdIntr*)(cmdArg))->intr,\
                                     ((CSL_Edma3CmdIntr*)(cmdArg))->intrh );
                break;          
                
            case CSL_EDMA3_CMD_INTR_ENABLE:
                status = EDMA3_interruptEnable( hMod, \
                                     ((CSL_Edma3CmdIntr*)(cmdArg))->region, \
                                     ((CSL_Edma3CmdIntr*)(cmdArg))->intr, \
                                     ((CSL_Edma3CmdIntr*)(cmdArg))->intrh );
                break;          
                
            case CSL_EDMA3_CMD_INTR_DISABLE:
                status = EDMA3_interruptDisable( hMod, \
                                     ((CSL_Edma3CmdIntr*)(cmdArg))->region, \
                                     ((CSL_Edma3CmdIntr*)(cmdArg))->intr, \
                                     ((CSL_Edma3CmdIntr*)(cmdArg))->intrh );
                break;
                
            case CSL_EDMA3_CMD_INTR_EVAL:
                status = EDMA3_interruptEval( hMod, *((int*)(cmdArg)) );
                break;  
                        
            case CSL_EDMA3_CMD_CTRLERROR_CLEAR:
                status = EDMA3_controllerErrorClear( hMod, \
                ((CSL_Edma3CtrlErrStat*)(cmdArg)) );
                break;
                
            case CSL_EDMA3_CMD_EVENTMISSED_CLEAR:
                status = EDMA3_eventsMissedClear( hMod, ((uint32*)cmdArg)[0], \
                ((uint32*)cmdArg)[1], ((uint32*)cmdArg)[2] );
                break;
                
            default:
                 status = OSE_BAD_CMD;
                 break;
        }
    }

    return( status );
}

