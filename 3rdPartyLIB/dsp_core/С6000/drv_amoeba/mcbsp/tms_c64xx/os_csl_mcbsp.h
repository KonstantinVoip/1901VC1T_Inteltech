#ifndef _OS_CSL_MCBSP_H_
#define _OS_CSL_MCBSP_H_

#include <os_types.h>
#include "os_csl_mcbsphal.h"

/* MCBSP_open() flags */
#define MCBSP_OPEN_RESET     (0x00000001)
/* Renaming MCBSP_read/write  */
#define MCBSP_read32 MCBSP_read 
#define MCBSP_write32 MCBSP_write 
/* pin identifiers used with MCBSP_getPins() and MCBSP_setPins() */
#define MCBSP_PIN_CLKX       _MCBSP_PCR_CLKXP_MASK
#define MCBSP_PIN_FSX        _MCBSP_PCR_FSXP_MASK
#define MCBSP_PIN_DX         _MCBSP_PCR_DXSTAT_MASK
#define MCBSP_PIN_CLKR       _MCBSP_PCR_CLKRP_MASK
#define MCBSP_PIN_FSR        _MCBSP_PCR_FSRP_MASK
#define MCBSP_PIN_DR         _MCBSP_PCR_DRSTAT_MASK
#define MCBSP_PIN_CLKS       _MCBSP_PCR_CLKSSTAT_MASK

/* device identifiers for MCBSP_open() */
#define MCBSP_DEV0    (0)
#define MCBSP_DEV1    (1)
#if (_MCBSP_PORT_CNT == 3)
  #define MCBSP_DEV2  (2)
#endif
/* device identifiers for MCBSP_open() */
#define MCBSP_PORT0    MCBSP_DEV0
#define MCBSP_PORT1    MCBSP_DEV1
#if (_MCBSP_PORT_CNT == 3)
  #define MCBSP_PORT2  MCBSP_DEV2
#endif
/* Constants for MCBSP_start */
#define MCBSP_RCV_START       (1u)
#define MCBSP_XMIT_START      (2u)
#define MCBSP_SRGR_START      (4u)
#define MCBSP_SRGR_FRAMESYNC  (8u)
#define MCBSP_SRGR_DEFAULT_DELAY  (0xFFFFFFFFu)
/* device handle object */

typedef struct {
  uint32 allocated;
  uint32 xmtEventId;
  uint32 rcvEventId;
  volatile uint32 *baseAddr;
  uint32 drrAddr;
  uint32 dxrAddr;
} MCBSP_Obj, *MCBSP_Handle;
/* device configuration structure */
typedef struct {

  uint32 spcr;
  uint32 rcr;
  uint32 xcr;
  uint32 srgr;
  uint32 mcr;
  uint32 rcere0;
  uint32 rcere1;
  uint32 rcere2;
  uint32 rcere3;
  uint32 xcere0;
  uint32 xcere1;
  uint32 xcere2;
  uint32 xcere3;
  uint32 pcr;
} MCBSP_Config;
/* predefined deviced handles for legacy - should not be used*/
extern far MCBSP_Handle _MCBSP_hDev0;
extern far MCBSP_Handle _MCBSP_hDev1;
#if (_MCBSP_PORT_CNT == 3)
extern far MCBSP_Handle _MCBSP_hDev2;
#endif

/******************************************************************************\
* global function declarations
\******************************************************************************/
void MCBSP_resetAll();

void MCBSP_reset(MCBSP_Handle hMcbsp);

void MCBSP_close(MCBSP_Handle hMcbsp);

void MCBSP_enableXmt(MCBSP_Handle hMcbsp);

void MCBSP_enableRcv(MCBSP_Handle hMcbsp);

void MCBSP_enableSrgr(MCBSP_Handle hMcbsp);

void MCBSP_enableFsync(MCBSP_Handle hMcbsp);

void MCBSP_write(MCBSP_Handle hMcbsp, uint32 val);

void MCBSP_setPins(MCBSP_Handle hMcbsp, uint32 pins);

void MCBSP_config(MCBSP_Handle hMcbsp, MCBSP_Config *config);

void MCBSP_getConfig(MCBSP_Handle hMcbsp, MCBSP_Config *config);

void MCBSP_start(MCBSP_Handle hMcbsp, uint32 startMask, uint32 sampleratedelay); 

void MCBSP_configArgs(MCBSP_Handle hMcbsp, uint32 spcr, uint32 rcr, 

  uint32 xcr, uint32 srgr, uint32 mcr, uint32 rcere0, uint32 rcere1, 

  uint32 rcere2, uint32 rcere3, uint32 xcere0, uint32 xcere1, uint32 xcere2, 

  uint32 xcere3, uint32 pcr);


uint32 MCBSP_getPins(MCBSP_Handle hMcbsp);

uint32 MCBSP_getXmtAddr(MCBSP_Handle hMcbsp);

uint32 MCBSP_getRcvAddr(MCBSP_Handle hMcbsp);

uint32 MCBSP_getXmtEventId(MCBSP_Handle hMcbsp);

uint32 MCBSP_getRcvEventId(MCBSP_Handle hMcbsp);

uint32 MCBSP_read(MCBSP_Handle hMcbsp);

uint32 MCBSP_xrdy(MCBSP_Handle hMcbsp);

uint32 MCBSP_rrdy(MCBSP_Handle hMcbsp);

uint32 MCBSP_xempty(MCBSP_Handle hMcbsp);

uint32 MCBSP_rfull(MCBSP_Handle hMcbsp);

uint32 MCBSP_xsyncerr(MCBSP_Handle hMcbsp);

uint32 MCBSP_rsyncerr(MCBSP_Handle hMcbsp);

MCBSP_Handle MCBSP_open(int devNum, uint32 flags);
#endif /* _OS_CSL_MCBSP_H_ */


