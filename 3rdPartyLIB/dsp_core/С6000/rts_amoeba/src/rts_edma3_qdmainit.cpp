
#include <rts_edma3.h>

/* =============================================================================
 *   EDMA3_qdmaInit
 *
 *   @b Description
 *   @n инициализация QDMA канала
 *      numCha - номер канала от 0 до 7
 *		paramNumm - номер набора параметров 0 - 255
 *
 * ===========================================================================
 */
void EDMA3_qdmaInit( uint32 numCha, uint32 paramNum )
{
  volatile CSL_Edma3ccRegs *base;
//  volatile CSL_Edma3ccRegs *base2;
  base = (volatile CSL_Edma3ccRegs*)(0x02A00000);
  uint32 tempChmap = 0;
  uint32 tempQnum = base->QDMAQNUM;

//  for( uint32 numCha = 0 ; numCha < CSL_EDMA3_NUM_QDMACH; numCha++ )
//  {
      tempChmap = CSL_FMK( EDMA3CC_QCHMAP_PAENTRY, paramNum ) | \
                  CSL_FMK( EDMA3CC_QCHMAP_TRWORD, CSL_EDMA3_TRIGWORD_CCNT );
      base->QCHMAP[numCha] = tempChmap;
      CSL_FINSR( tempQnum, (numCha * 4) + 2, (numCha * 4), (numCha%5) );
//  }

  base->QDMAQNUM = tempQnum;

//  base = (volatile CSL_Edma3ccRegs*)(0x02A00000);
  base->QEESR = (1 << numCha);


  CSL_Edma3tcRegs* base2 = (CSL_Edma3tcRegs*)(0x02A20000);
  base2->RDRATE = 4;
  base2 = (CSL_Edma3tcRegs*)(0x02A28000);
  base2->RDRATE = 4;
  base2 = (CSL_Edma3tcRegs*)(0x02A30000);
  base2->RDRATE = 4;
  base2 = (CSL_Edma3tcRegs*)(0x02A38000);
  base2->RDRATE = 4;
  base2 = (CSL_Edma3tcRegs*)(0x02A40000);
  base2->RDRATE = 4;
  base2 = (CSL_Edma3tcRegs*)(0x02A48000);
  base2->RDRATE = 4;
}


