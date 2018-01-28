#include <rts.h>
void EDMA_qdmaConfig(EDMA_Config *config)
{

  register volatile uint32 gie;
  volatile uint32 *base;
  register volatile uint32 x0,x1,x2,x3,x4;

  gie = int_disable();

  x0 = config->opt;
  x1 = config->src;
  x2 = config->cnt;
  x3 = config->dst;
  x4 = config->idx;

  base = (volatile uint32 *)(_EDMA_QOPT_ADDR);
  base[_EDMA_QSRC_OFFSET]  = x1;
  base[_EDMA_QCNT_OFFSET]  = x2;
  base[_EDMA_QDST_OFFSET]  = x3;
  base[_EDMA_QIDX_OFFSET]  = x4;
  base[_EDMA_QSOPT_OFFSET] = x0;

  int_enable(gie);
}
