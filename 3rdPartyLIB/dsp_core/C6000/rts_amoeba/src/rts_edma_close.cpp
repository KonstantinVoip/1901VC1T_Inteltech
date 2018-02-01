#include <rts.h>
void EDMA_close(EDMA_Handle hEdma)
{

  uint32 cha;

  register volatile uint32 gie;

  gie = int_disable();
  if (hEdma & _EDMA_TYPE_C) {
    cha  = ((((uint32)hEdma)&0x00FF0000)>>16);
      if (cha < 32) rts_edma__allocMaskCL &= ~(1<<cha);
      else rts_edma__allocMaskCH &= ~(1<<(cha-32));
    EDMA_reset(hEdma);
  }
  int_enable(gie);
}
