#include <rts.h>
EDMA_Handle EDMA_allocTable(int tableNum)
{

  uint32 addr;
  register volatile uint32 gie;

  EDMA_Handle hEdma = EDMA_HINV;
  int tbl,major,minor;

  gie = int_disable();

  if (tableNum==EDMA_ALLOC_ANY) {
    for (tbl=0; tbl<EDMA_TABLE_CNT; tbl++) {
      major = ((tbl)&(~0x1F))>>5;
      minor = (tbl)&(0x1F);
      if (!(rts_edma__allocMaskT[major] & (1<<minor))) {
        rts_edma__allocMaskT[major] |= (1<<minor);
        addr = (tbl*_EDMA_ENTRY_SIZE)+_EDMA_LINK_START;
        hEdma=_EDMA_MK_HANDLE(addr,tbl,_EDMA_TYPE_T);
        break;
      }
    }
  } else {
   if ((tableNum < EDMA_TABLE_CNT)) {
    major = ((tableNum)&(~0x1F))>>5;
    minor = (tableNum)&(0x1F);
    if (!(rts_edma__allocMaskT[major] & (1<<minor))) {
      rts_edma__allocMaskT[major] |= (1<<minor);
      addr = (tableNum*_EDMA_ENTRY_SIZE)+_EDMA_LINK_START;
      hEdma=_EDMA_MK_HANDLE(addr,tableNum,_EDMA_TYPE_T);
    }
   }
  }

  int_enable(gie);

  return hEdma;
}
