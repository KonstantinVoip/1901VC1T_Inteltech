
#include <rts_edma3.h>
/* =============================================================================
 *   EDMA3_qdmaIntClear
 *
 *   @b Description
 *   @n сброс прерывания QDMA
 *      numCha - номер канала от 0 до 7
 *
 * ===========================================================================
 */ 
void EDMA3_qdmaIntClear(uint32 numCha)
{
  volatile CSL_Edma3ccRegs *base;
  base = (volatile CSL_Edma3ccRegs*)(0x02A00000);

  base->ICR |= (1 << numCha);
//  base->ICR = base->IPR & (1 << num);
  
//  base->ICRH = base->IPRH;

  // disable chanel
//  base->QEECR = (1 << tccIntNum);
}


