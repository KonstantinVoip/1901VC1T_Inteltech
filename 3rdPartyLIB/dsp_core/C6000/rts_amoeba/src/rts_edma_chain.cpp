#include <rts.h>
void EDMA_chain(EDMA_Handle parent, EDMA_Handle nextChannel,int tccflag, int atccflag)
{
  uint32 tccm,tcc;
  int TccNum = (nextChannel & 0x00FF0000)>>16;
  register volatile uint32 gie;

  gie = int_disable();

  if (tccflag)
  {
   if (TccNum < 16) {  tccm = 0 ; tcc = TccNum;}
   else {
        if ( TccNum  > 15 && TccNum < 32 ) { tccm = 1 ; tcc = TccNum-16;}
         else  {
              if ( TccNum  > 31 && TccNum < 48 ) { tccm = 2 ; tcc = TccNum-32;}
              else {   /* channel > 47 */
                     tccm = 3 ; tcc = TccNum-48;
                   }
         }
    }
      EDMA_FSETH(parent,OPT,TCCM,tccm);
      EDMA_FSETH(parent,OPT,TCC,tcc);
      EDMA_FSETH(parent,OPT,TCINT,1);
  }
/* ATCC */
  if (atccflag)
  {
    EDMA_FSETH(parent,OPT,ATCC,TccNum);
    EDMA_FSETH(parent,OPT,ATCINT,1);
  }
  rts_edma__tccAllocTable[TccNum] = 1;
  int_enable(gie);
}
