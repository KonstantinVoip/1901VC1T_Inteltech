
#include <rts_edma3.h>


int32 EDMA3_hwSetup( CSL_Edma3Handle hMod, CSL_Edma3HwSetup *setup )
{
    uint32      numCha;
    uint32      tempQnum = 0;
    uint32      tempChmap = 0;
    uint32      ii;
    int32       status = OSE_OK;
    
    if( hMod == NULL )
    {
        status = OSE_NULL_PARAM;
    }    
    else if( setup == NULL)
    {
        status = OSE_BAD_PARAM;
    }
    else
    {
        if( setup->dmaChaSetup != NULL )
        {
            for( numCha = 0 ; numCha < CSL_EDMA3_NUM_DMACH; numCha++ )
            {
#ifdef CSL_EDMA3_CHMAPEXIST
                hMod->regs->DCHMAP[numCha] = 
                    CSL_FMK( EDMA3CC_DCHMAP_PAENTRY, \
                             setup->dmaChaSetup[numCha].paramNum );
#endif              
                ii = numCha % 8;
                CSL_FINSR( tempQnum, (ii * 4) + 2, (ii * 4), \
                           setup->dmaChaSetup[numCha].que );
                if( ((ii + 1) % 8) == 0 )
                {
                    hMod->regs->DMAQNUM[numCha/8] = tempQnum;
                    tempQnum = 0;
                }
            }
        }
        
        if( setup->qdmaChaSetup != NULL )
        {
            for( numCha = 0 ; numCha < CSL_EDMA3_NUM_QDMACH; numCha++ )
            {
                tempChmap = CSL_FMK( EDMA3CC_QCHMAP_PAENTRY, \
                                     setup->qdmaChaSetup[numCha].paramNum ) | \
                            CSL_FMK( EDMA3CC_QCHMAP_TRWORD, \
                                     setup->qdmaChaSetup[numCha].triggerWord );
                hMod->regs->QCHMAP[numCha] = tempChmap;
                CSL_FINSR( tempQnum, (numCha * 4) + 2, (numCha * 4), \
                            setup->qdmaChaSetup[numCha].que );
            }
            
            hMod->regs->QDMAQNUM = tempQnum;
        }
    }

    return( status ); 
}

