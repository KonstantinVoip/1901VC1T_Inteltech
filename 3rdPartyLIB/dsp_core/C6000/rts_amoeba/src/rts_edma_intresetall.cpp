#include <rts.h>
void EDMA_intResetAll()
{
  register volatile uint32 gie = int_disable();
  /* disable then clear all interrupts */
  EDMA_RSET(CIERL, 0x00000000);
  EDMA_RSET(CIERH, 0x00000000);
  EDMA_RSET(CIPRL, 0xFFFFFFFF);
  EDMA_RSET(CIPRH, 0xFFFFFFFF);

  int_enable(gie);
}
