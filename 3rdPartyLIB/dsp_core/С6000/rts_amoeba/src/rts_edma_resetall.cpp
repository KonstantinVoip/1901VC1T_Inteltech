#include <rts.h>
void EDMA_resetAll()
{
  int x;
  
  register volatile uint32 gie;
  
  uint32 *pram = (uint32*)_EDMA_PRAM_START;
  
  gie = int_disable();
  
  EDMA_RSET(EERL,  EDMA_EERL_DEFAULT);
  EDMA_RSET(EERH,  EDMA_EERH_DEFAULT);
  EDMA_RSET(CCERL, EDMA_CCERL_DEFAULT);
  EDMA_RSET(CCERH, EDMA_CCERH_DEFAULT);
  EDMA_RSET(ECRL,  0xFFFFFFFF);
  EDMA_RSET(ECRH,  0xFFFFFFFF);
  
  EDMA_RSET(CIERL, EDMA_CIERL_DEFAULT);
  EDMA_RSET(CIERH, EDMA_CIERH_DEFAULT);
  EDMA_RSET(CIPRL, 0xFFFFFFFF);
  EDMA_RSET(CIPRH, 0xFFFFFFFF);
  
   /* now let's clear out the parameter RAM */
   //EDMA_clearPram(0x00000000);
  
  for (x=0; x<_EDMA_PRAM_ERASE>>2; x++)
  {
    pram[x] = 0x00000000;
  }
  
  for (x=0; x<4; ++x)
  {
      rts_edma__allocMaskT[x] = 0;
  }
  
  int_enable(gie);
}
