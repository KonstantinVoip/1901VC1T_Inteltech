#include <rts.h>
void EDMA_config(EDMA_Handle hEdma, EDMA_Config *config)
{

  register volatile uint32 gie;
  volatile uint32 *base;
  register volatile uint32 x0,x1,x2,x3,x4,x5;

/* Test if QDMA handle was passed with CCS 1.2 */
 if ( hEdma == (0x20000000) || hEdma == (0x10000000)) {
        EDMA_qdmaConfig(config);
 }else{

  gie = int_disable();

  x0 = config->opt;
  x1 = config->src;
  x2 = config->cnt;
  x3 = config->dst;
  x4 = config->idx;
  x5 = config->rld;

  base = (volatile uint32 *)((hEdma&0x0000FFFF)+_EDMA_PRAM_START);
  base[_EDMA_OPT_OFFSET] = 0x00000000;
  base[_EDMA_SRC_OFFSET] = x1;
  base[_EDMA_CNT_OFFSET] = x2;
  base[_EDMA_DST_OFFSET] = x3;
  base[_EDMA_IDX_OFFSET] = x4;
  base[_EDMA_RLD_OFFSET] = x5;
  base[_EDMA_OPT_OFFSET] = x0;
  int_enable(gie);
  }
}
