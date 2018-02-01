#ifndef _CSL_STDINC_H_
#define _CSL_STDINC_H_

#include "os_csl_stdinchal.h"

#ifndef TRUE
  #define TRUE   1
#endif
#ifndef FALSE
  #define FALSE  0
#endif

#ifndef INV
  #define INV    ((void*)(-1))
#endif

#ifndef UNREFERENCED_PARAMETER
  #define UNREFERENCED_PARAMETER(P)    ((P)=(P))
#endif

#ifndef REG32
  #define REG32(addr) (*(volatile unsigned int*)(addr))
  #define REG16(addr) (*(volatile unsigned short*)(addr))
  #define REG8(addr)  (*(volatile unsigned char*)(addr))
#endif

//#include <tistdtypes.h> /* use typedefs provided with CCS*/

#endif /* _CSL_STDINC_H_ */

