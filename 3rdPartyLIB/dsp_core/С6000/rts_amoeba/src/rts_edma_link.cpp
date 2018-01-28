#include <rts.h>
void EDMA_link(EDMA_Handle parent, EDMA_Handle child)
{
  EDMA_FSETH(parent,RLD,LINK,child);
}
