
#include <rts_edma3.h>

int32  EDMA3_getHwSetup( CSL_Edma3Handle hMod, CSL_Edma3HwSetup *setup )
{
    uint32      numCha;
    uint32      tempQnum  = 0;
    uint32      tempChmap = 0;
    uint32      ii = 0;
    int32       status = OSE_OK;  
    
    if( hMod == NULL )
    {
        status = OSE_NULL_PARAM;
    }
    else if( setup == NULL )
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
                setup->dmaChaSetup[numCha].paramNum = \
                    CSL_FEXT( hMod->regs->DCHMAP[numCha], EDMA3CC_DCHMAP_PAENTRY );
#endif      
                if( ((ii) % 8) == 0 )
                    tempQnum = hMod->regs->DMAQNUM[numCha/8];
                ii = numCha % 8;
                setup->dmaChaSetup[numCha].que = \
                      (CSL_Edma3Que)CSL_FEXTR( tempQnum, (ii * 4) + 2, (ii * 4) );
            }
        }
        
        if( setup->qdmaChaSetup != NULL )
        {
            tempQnum = hMod->regs->QDMAQNUM;
            for( numCha = 0 ; numCha < CSL_EDMA3_NUM_QDMACH; numCha++ )
            {
                tempChmap = hMod->regs->QCHMAP[numCha];
                setup->qdmaChaSetup[numCha].paramNum = \
                        CSL_FEXT( tempChmap, EDMA3CC_QCHMAP_PAENTRY );
                setup->qdmaChaSetup[numCha].triggerWord = \
                      CSL_FEXT( tempChmap, EDMA3CC_QCHMAP_TRWORD );
                setup->qdmaChaSetup[numCha].que = \
                     (CSL_Edma3Que)CSL_FEXTR( tempQnum, (numCha * 4) + 2, numCha * 4 );
            }
        }
    }

    return( status ); 
}



