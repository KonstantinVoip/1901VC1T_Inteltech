#include <rts.h>
void EDMA_configArgs(EDMA_Handle hEdma, uint32 opt, uint32 src,
  uint32 cnt, uint32 dst, uint32 idx, uint32 rld)
{

  register volatile uint32 gie;
  volatile uint32 *base;
 /* Test if QDMA handle was passed with CCS 1.2 */
 if ( hEdma == (0x20000000) || hEdma == (0x10000000)) {
        EDMA_qdmaConfigArgs(opt, src, cnt, dst, idx);
 }else{
  gie = int_disable();
  base = (volatile uint32*)((hEdma&0x0000FFFF)+_EDMA_PRAM_START);
  base[_EDMA_OPT_OFFSET] = 0x00000000;
  base[_EDMA_SRC_OFFSET] = src;
  base[_EDMA_CNT_OFFSET] = cnt;
  base[_EDMA_DST_OFFSET] = dst;
  base[_EDMA_IDX_OFFSET] = idx;
  base[_EDMA_RLD_OFFSET] = rld;
  base[_EDMA_OPT_OFFSET] = opt;
  int_enable(gie);
 }
}
