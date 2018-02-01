#include <rts.h>
uint32 EDMA_getPriQStatus()
{
  return (uint32)EDMA_RGET(PQSR);
}
