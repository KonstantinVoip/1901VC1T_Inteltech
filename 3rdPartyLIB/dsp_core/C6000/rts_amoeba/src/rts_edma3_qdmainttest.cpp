
#include <rts_edma3.h>
/* =============================================================================
 *   EDMA3_qdmaIntTest
 *
 *   @b Description
 *   @n �������� ���������� QDMA
 *      numCha - ����� ������ �� 0 �� 7
 *
 * ===========================================================================
 */ 
uint32 EDMA3_qdmaIntTest(uint32 numCha)
{
  volatile CSL_Edma3ccRegs *base;
  base = (volatile CSL_Edma3ccRegs*)(0x02A00000);

  return( (base->IPR & (1<<numCha)) ? 1 : 0 );
}


