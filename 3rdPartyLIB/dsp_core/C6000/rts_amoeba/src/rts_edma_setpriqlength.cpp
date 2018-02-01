#include <rts.h>
void EDMA_setPriQLength(uint32 priNum, uint32 length)
{
  if (priNum == 0x0) {
   EDMA_RSET(PQAR0,(0x00000007 & length));
   } else {
          if (priNum == 0x1) {
           EDMA_RSET(PQAR1,(0x00000007 & length));
          }else {
                if (priNum == 0x2) {
                EDMA_RSET(PQAR2,(0x00000007 & length));
                } else {
                       if (priNum == 0x3) {
                       EDMA_RSET(PQAR3,(0x00000007 & length));
                       }
                  }
           }
    }
}
