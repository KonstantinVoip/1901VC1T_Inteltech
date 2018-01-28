#include <rts.h>
void EDMA_qdmaConfigArgs(uint32 opt, uint32 src, uint32 cnt, uint32 dst,
  uint32 idx)
{

  register volatile uint32 gie;
  volatile uint32 *base;

  gie = int_disable();

  base = (volatile uint32*)(_EDMA_QOPT_ADDR);
  base[_EDMA_QSRC_OFFSET]  = src;
  base[_EDMA_QCNT_OFFSET]  = cnt;
  base[_EDMA_QDST_OFFSET]  = dst;
  base[_EDMA_QIDX_OFFSET]  = idx;
  base[_EDMA_QSOPT_OFFSET] = opt;

  int_enable(gie);
}
