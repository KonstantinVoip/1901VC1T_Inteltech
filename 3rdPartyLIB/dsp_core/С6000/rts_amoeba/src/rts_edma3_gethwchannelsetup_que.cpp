
#include <rts_edma3.h>
//#include <csl_edma3Aux.h>

int32  CSL_edma3GetHwChannelSetupQue (
    CSL_Edma3ChannelHandle        hEdma,
    CSL_Edma3Que                  *evtQue   
) 
{
    uint32      _cha;
    uint32      _qNumIndex;
    uint32      _qchMap;
    int32       status = OSE_OK;
    
    if( hEdma == NULL )
    {
        status = OSE_NULL_PARAM;
    }    
    else if( evtQue == NULL )
    {
        status = OSE_BAD_PARAM;
    }
    else
    {
        if( hEdma->chaNum >= CSL_EDMA3_NUM_DMACH )
        {
            /* Extracting the Channel Number in case of QDMA */
            _cha = hEdma->chaNum - CSL_EDMA3_NUM_DMACH;
           /*  Channel to Event Queue mapping */
            *evtQue = (CSL_Edma3Que)CSL_FEXTR(hEdma->regs->QDMAQNUM, _cha * 4 + 2, \
                                              _cha * 4);
        } 
        else
        {
            /*  Finding out the relevant DMAQNUM register and the correct bit 
             *  positions to write into 
             */ 
            _qNumIndex = hEdma->chaNum >> 3;
            _qchMap = hEdma->chaNum - (_qNumIndex * 8);
            *evtQue = (CSL_Edma3Que)CSL_FEXTR(hEdma->regs->DMAQNUM[_qNumIndex], \
                                              _qchMap * 4 + 2, _qchMap * 4);
        }
    }

    return( status );
}



