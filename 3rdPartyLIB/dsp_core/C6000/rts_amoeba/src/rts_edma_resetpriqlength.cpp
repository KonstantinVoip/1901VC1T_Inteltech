#include <rts.h>
void EDMA_resetPriQLength(uint32 priNum)
{
 if (priNum == 0x0) {
   EDMA_FSET(PQAR0,PQA,EDMA_PQAR0_PQA_DEFAULT);
   } else {
          if (priNum == 0x1) {
          EDMA_FSET(PQAR1,PQA,EDMA_PQAR1_PQA_DEFAULT);
          } else {
                 if (priNum == 0x2) {
                 EDMA_FSET(PQAR2,PQA,EDMA_PQAR2_PQA_DEFAULT);
                 }else {
                      if (priNum == 0x3) {
                      EDMA_FSET(PQAR3,PQA,EDMA_PQAR3_PQA_DEFAULT);
                       }
                  }
           }
   }
}
