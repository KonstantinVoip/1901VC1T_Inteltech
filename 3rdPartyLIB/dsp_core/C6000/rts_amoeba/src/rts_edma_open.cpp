#include <rts.h>
EDMA_Handle EDMA_open(int channel, uint32 flags)
{

  uint32 addr;
  register volatile uint32 gie;

  EDMA_Handle hEdma = EDMA_HINV;
  int cha;

  gie = int_disable();

  if (channel==EDMA_CHA_ANY) {
    for (cha=0; cha<EDMA_CHA_CNT; cha++) {
        if (cha < 32) {
          if (!(rts_edma__allocMaskCL & (1<<cha))) {
            rts_edma__allocMaskCL |= (1<<cha);
            addr = (cha*_EDMA_ENTRY_SIZE)+_EDMA_PRAM_START;
            hEdma=_EDMA_MK_HANDLE(addr,cha,_EDMA_TYPE_C);
            break;
          }
        } else {
          if (!(rts_edma__allocMaskCH & (1<<(cha-32)))) {
            rts_edma__allocMaskCH |= (1<<(cha-32));
            addr = (cha*_EDMA_ENTRY_SIZE)+_EDMA_PRAM_START;
            hEdma=_EDMA_MK_HANDLE(addr,cha,_EDMA_TYPE_C);
            break;
          }
        }
    }
  } else {
      if (channel < 32) {
        if (!(rts_edma__allocMaskCL & (1<<channel))) {
          rts_edma__allocMaskCL |= (1<<channel);
          addr = (channel*_EDMA_ENTRY_SIZE)+_EDMA_PRAM_START;
          hEdma=_EDMA_MK_HANDLE(addr,channel,_EDMA_TYPE_C);
        }
      } else {
        if (!(rts_edma__allocMaskCH & (1<<(channel-32)))) {
          rts_edma__allocMaskCH |= (1<<(channel-32));
          addr = (channel*_EDMA_ENTRY_SIZE)+_EDMA_PRAM_START;
          hEdma=_EDMA_MK_HANDLE(addr,channel,_EDMA_TYPE_C);
        }
      }
  }

  int_enable(gie);

  if (hEdma != (EDMA_Handle)INV) {
    if (flags & EDMA_OPEN_RESET) {
      EDMA_reset(hEdma);
    }

    if (flags & EDMA_OPEN_ENABLE) {
      EDMA_enableChannel(hEdma);
    }
  }

  return hEdma;
}
