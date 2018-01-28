#include <rts.h>
uint32 EDMA_getTableAddress(EDMA_Handle hEdma)
{
  return (hEdma&0x0000FFFF)+_EDMA_PRAM_START;
}
