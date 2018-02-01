#include <rts.h>
void EDMA_qdmaGetConfig(EDMA_Config *config)
{

  register volatile uint32 gie;
  volatile uint32 *base;
  volatile EDMA_Config* cfg = (volatile EDMA_Config*)config;
  register volatile uint32 x0,x1,x2,x3,x4;

  gie = int_disable();

  base = (volatile uint32 *)(_EDMA_QOPT_ADDR);
  x0 = base[_EDMA_QOPT_OFFSET];
  x1 = base[_EDMA_QSRC_OFFSET];
  x2 = base[_EDMA_QCNT_OFFSET];
  x3 = base[_EDMA_QDST_OFFSET];
  x4 = base[_EDMA_QIDX_OFFSET];

  cfg->opt = x0;
  cfg->src = x1;
  cfg->cnt = x2;
  cfg->dst = x3;
  cfg->idx = x4;
  cfg->rld = 0x00000000;

  int_enable(gie);
}
