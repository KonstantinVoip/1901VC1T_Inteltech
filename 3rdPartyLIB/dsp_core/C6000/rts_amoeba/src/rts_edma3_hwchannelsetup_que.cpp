
#include <rts_edma3.h>

int32 CSL_edma3HwChannelSetupQue(
    CSL_Edma3ChannelHandle       hEdma,
    CSL_Edma3Que                 evtQue 
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
    else
    {
        if( hEdma->chaNum >= CSL_EDMA3_NUM_DMACH )
        {
        /*  Extracting the Channel Number in case of QDMA */
            _cha = hEdma->chaNum - CSL_EDMA3_NUM_DMACH;
        /*  Channel to Event Queue mapping */
            CSL_FINSR( hEdma->regs->QDMAQNUM, _cha * 4 + 2, _cha * 4,evtQue );
        } 
        else
        {
        /*  Finding out the relevant DMAQNUM register and the correct bit positions 
            to write into */ 
            _qNumIndex = hEdma->chaNum >> 3;
            _qchMap = hEdma->chaNum - (_qNumIndex * 8);
            CSL_FINSR( hEdma->regs->DMAQNUM[_qNumIndex], _qchMap * 4 + 2, \
                       _qchMap * 4, evtQue );
        }
    }

    return( status );
}

