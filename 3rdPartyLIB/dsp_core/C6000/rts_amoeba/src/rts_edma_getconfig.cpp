#include <rts.h>
void EDMA_getConfig(EDMA_Handle hEdma, EDMA_Config *config)
{

  register volatile uint32 gie;
  volatile uint32 *base;
  register volatile uint32 x0,x1,x2,x3,x4,x5;

  gie = int_disable();

  base = (volatile uint32 *)((hEdma&0x0000FFFF)+_EDMA_PRAM_START);
  x0 = base[_EDMA_OPT_OFFSET];
  x1 = base[_EDMA_SRC_OFFSET];
  x2 = base[_EDMA_CNT_OFFSET];
  x3 = base[_EDMA_DST_OFFSET];
  x4 = base[_EDMA_IDX_OFFSET];
  x5 = base[_EDMA_RLD_OFFSET];

  config->opt = x0;
  config->src = x1;
  config->cnt = x2;
  config->dst = x3;
  config->idx = x4;
  config->rld = x5;

  int_enable(gie);
}
