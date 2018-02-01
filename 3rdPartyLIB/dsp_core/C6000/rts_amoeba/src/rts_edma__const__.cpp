#include <rts.h>

uint32 rts_edma__allocMaskCL = 0x00000000;
uint32 rts_edma__allocMaskCH = 0x00000000;
uint32 rts_edma__allocMaskT[4] = {0,0,0,0};

uint8 rts_edma__tccAllocTable[64] =
{
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};
