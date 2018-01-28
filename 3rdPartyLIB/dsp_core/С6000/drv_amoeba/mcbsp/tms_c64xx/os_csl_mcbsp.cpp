#include <os.h>
#include <os_types.h>
#include "os_csl_mcbsp.h"

#define DEVICE_ENTRY(devNum) { \
  FALSE, \
  INT_MCBSP##devNum##_TX, \
  INT_MCBSP##devNum##_RX, \
  (volatile uint32*)_MCBSP_BASE_PORT##devNum##, \
  _MCBSP_DRR##devNum##_ADDR, \
  _MCBSP_DXR##devNum##_ADDR \
}

#define PIN_MASK (uint32)(\
  _MCBSP_PCR_CLKXP_MASK| \
  _MCBSP_PCR_FSXP_MASK| \
  _MCBSP_PCR_DXSTAT_MASK| \
  _MCBSP_PCR_CLKRP_MASK| \
  _MCBSP_PCR_FSRP_MASK| \
  _MCBSP_PCR_DRSTAT_MASK| \
  _MCBSP_PCR_CLKSSTAT_MASK \
)


static MCBSP_Obj _MCBSP_deviceTable[_MCBSP_PORT_CNT] = 
{
  DEVICE_ENTRY(0),
  DEVICE_ENTRY(1)
  #if (_MCBSP_PORT_CNT==3)
    ,DEVICE_ENTRY(2)
  #endif
};

/* predefined handles for legacy - should not be used */
MCBSP_Handle _MCBSP_hDev0=(MCBSP_Handle)(&(_MCBSP_deviceTable[0]));
MCBSP_Handle _MCBSP_hDev1=(MCBSP_Handle)(&(_MCBSP_deviceTable[1]));
#if (_MCBSP_PORT_CNT == 3)
  MCBSP_Handle _MCBSP_hDev2=(MCBSP_Handle)(&(_MCBSP_deviceTable[2]));
#endif

/*----------------------------------------------------------------------------*/
void MCBSP_reset(MCBSP_Handle hMcbsp)
{

  register volatile uint32 gie;

  gie = int_disable();
  if (hMcbsp == INV) {
    MCBSP_reset((MCBSP_Handle)(&(_MCBSP_deviceTable[0])));
    MCBSP_reset((MCBSP_Handle)(&(_MCBSP_deviceTable[1])));
    #if (_MCBSP_PORT_CNT==3)
      MCBSP_reset((MCBSP_Handle)(&(_MCBSP_deviceTable[2])));
    #endif
  } else {
    MCBSP_RSETH(hMcbsp,SPCR,MCBSP_SPCR_DEFAULT);
    MCBSP_RSETH(hMcbsp,RCR, MCBSP_RCR_DEFAULT);
    MCBSP_RSETH(hMcbsp,XCR, MCBSP_XCR_DEFAULT);
    MCBSP_RSETH(hMcbsp,SRGR,MCBSP_SRGR_DEFAULT);
    MCBSP_RSETH(hMcbsp,MCR, MCBSP_MCR_DEFAULT);
    MCBSP_RSETH(hMcbsp,RCERE0,MCBSP_RCERE0_DEFAULT);
    MCBSP_RSETH(hMcbsp,RCERE1,MCBSP_RCERE1_DEFAULT);
    MCBSP_RSETH(hMcbsp,RCERE2,MCBSP_RCERE2_DEFAULT);
    MCBSP_RSETH(hMcbsp,RCERE3,MCBSP_RCERE3_DEFAULT);
    MCBSP_RSETH(hMcbsp,XCERE0,MCBSP_XCERE0_DEFAULT);
    MCBSP_RSETH(hMcbsp,XCERE1,MCBSP_XCERE1_DEFAULT);
    MCBSP_RSETH(hMcbsp,XCERE2,MCBSP_XCERE2_DEFAULT);
    MCBSP_RSETH(hMcbsp,XCERE3,MCBSP_XCERE3_DEFAULT);
    MCBSP_RSETH(hMcbsp,PCR, MCBSP_PCR_DEFAULT);
  }
  int_enable(gie);
  return;
}

/*----------------------------------------------------------------------------*/
void MCBSP_resetAll()
{
	MCBSP_reset((MCBSP_Handle)INV);
}

/*----------------------------------------------------------------------------*/
MCBSP_Handle MCBSP_open(int devNum, uint32 flags)
{

  register volatile uint32 gie;

  MCBSP_Handle hMcbsp = (MCBSP_Handle)INV;

  gie = int_disable();
  if (!_MCBSP_deviceTable[devNum].allocated) {
    hMcbsp = &(_MCBSP_deviceTable[devNum]);
    _MCBSP_deviceTable[devNum].allocated = TRUE;

    if (hMcbsp != INV) {
      if (flags&MCBSP_OPEN_RESET) {
        MCBSP_reset(hMcbsp);
      }
    }
  }
  int_enable(gie);

  return hMcbsp;
}

/*----------------------------------------------------------------------------*/
void MCBSP_close(MCBSP_Handle hMcbsp)
{

  register volatile uint32 gie;

  gie = int_disable();
  if (hMcbsp != INV) {
    MCBSP_reset(hMcbsp);
    hMcbsp->allocated = FALSE;
  }
  int_enable(gie);
  return;
}

/*----------------------------------------------------------------------------*/
void MCBSP_start(MCBSP_Handle hMcbsp, uint32 startMask, uint32 sampleratedelay)
{
  /* compiler should not optimize delay loop after setting GRST under -o3 switch */
  volatile uint32 count = sampleratedelay;
  

  if (startMask & MCBSP_SRGR_START) {
    MCBSP_FSETSH(hMcbsp,SPCR,GRST,NO);
    while(count > 0) {
        --count;
    }
  }

  if (startMask & MCBSP_RCV_START) {
    MCBSP_FSETSH(hMcbsp,SPCR,RRST,NO);
  }
  
  if (startMask & MCBSP_XMIT_START) {
    MCBSP_FSETSH(hMcbsp,SPCR,XRST,NO);
  }

  if (startMask & MCBSP_SRGR_FRAMESYNC) {
     MCBSP_FSETSH(hMcbsp,SPCR,FRST,NO);
  }
  
}


/*----------------------------------------------------------------------------*/

uint32 MCBSP_getPins(MCBSP_Handle hMcbsp)
{
	return (MCBSP_RGETH(hMcbsp,PCR)& PIN_MASK);
}

/*----------------------------------------------------------------------------*/
void MCBSP_setPins(MCBSP_Handle hMcbsp, uint32 pins)
{

  MCBSP_RSETH(hMcbsp,PCR, 
    (MCBSP_RGETH(hMcbsp,PCR)&~PIN_MASK)
    |(
       MCBSP_FMK(PCR, CLKXP,    pins>>_MCBSP_PCR_CLKXP_SHIFT)
      |MCBSP_FMK(PCR, FSXP,     pins>>_MCBSP_PCR_FSXP_SHIFT)
      |MCBSP_FMK(PCR, DXSTAT,   pins>>_MCBSP_PCR_DXSTAT_SHIFT)
      |MCBSP_FMK(PCR, CLKRP,    pins>>_MCBSP_PCR_CLKRP_SHIFT)
      |MCBSP_FMK(PCR, FSRP,     pins>>_MCBSP_PCR_FSRP_SHIFT)
      |MCBSP_FMK(PCR, DRSTAT,   pins>>_MCBSP_PCR_DRSTAT_SHIFT)
      |MCBSP_FMK(PCR, CLKSSTAT, pins>>_MCBSP_PCR_CLKSSTAT_SHIFT)
    )
  );
}
/*----------------------------------------------------------------------------*/

uint32 MCBSP_getXmtAddr(MCBSP_Handle hMcbsp)
{
  return (uint32)(hMcbsp->dxrAddr);
}

/*----------------------------------------------------------------------------*/

uint32 MCBSP_getRcvAddr(MCBSP_Handle hMcbsp)
{
  return (uint32)(hMcbsp->drrAddr);
}

/*----------------------------------------------------------------------------*/

uint32 MCBSP_getXmtEventId(MCBSP_Handle hMcbsp)
{
  return (hMcbsp->xmtEventId);
}

/*----------------------------------------------------------------------------*/

uint32 MCBSP_getRcvEventId(MCBSP_Handle hMcbsp)
{
  return (hMcbsp->rcvEventId);
}

/*----------------------------------------------------------------------------*/

uint32 MCBSP_read(MCBSP_Handle hMcbsp)
{
  return (*(volatile uint32 *)(hMcbsp->drrAddr));
}

/*----------------------------------------------------------------------------*/

void MCBSP_write(MCBSP_Handle hMcbsp, uint32 val)
{
  (*(volatile uint32 *)(hMcbsp->dxrAddr)) = val;
}

/*----------------------------------------------------------------------------*/

uint32 MCBSP_xrdy(MCBSP_Handle hMcbsp)
{
  return MCBSP_FGETH(hMcbsp,SPCR,XRDY);
}

/*----------------------------------------------------------------------------*/

uint32 MCBSP_rrdy(MCBSP_Handle hMcbsp)
{
  return MCBSP_FGETH(hMcbsp,SPCR,RRDY);
}

/*----------------------------------------------------------------------------*/

uint32 MCBSP_xempty(MCBSP_Handle hMcbsp)
{
  return MCBSP_FGETH(hMcbsp,SPCR,XEMPTY);
}

/*----------------------------------------------------------------------------*/

uint32 MCBSP_rfull(MCBSP_Handle hMcbsp)
{
  return MCBSP_FGETH(hMcbsp,SPCR,RFULL);
}

/*----------------------------------------------------------------------------*/

uint32 MCBSP_xsyncerr(MCBSP_Handle hMcbsp)
{
  return MCBSP_FGETH(hMcbsp,SPCR,XSYNCERR);
}

/*----------------------------------------------------------------------------*/

uint32 MCBSP_rsyncerr(MCBSP_Handle hMcbsp)
{
  return MCBSP_FGETH(hMcbsp,SPCR,RSYNCERR);
}
/*----------------------------------------------------------------------------*/
void MCBSP_enableXmt(MCBSP_Handle hMcbsp)
{
  MCBSP_FSETSH(hMcbsp,SPCR,XRST,NO);
}
/*----------------------------------------------------------------------------*/

void MCBSP_enableRcv(MCBSP_Handle hMcbsp)
{
  MCBSP_FSETSH(hMcbsp,SPCR,RRST,NO);
}

/*----------------------------------------------------------------------------*/

void MCBSP_enableFsync(MCBSP_Handle hMcbsp)
{
  MCBSP_FSETSH(hMcbsp,SPCR,FRST,NO);
}

/*----------------------------------------------------------------------------*/

void MCBSP_enableSrgr(MCBSP_Handle hMcbsp)
{
  MCBSP_FSETSH(hMcbsp,SPCR,GRST,NO);
}

/*----------------------------------------------------------------------------*/
void MCBSP_config(MCBSP_Handle hMcbsp, MCBSP_Config *config)
{

  register volatile uint32 gie;

  volatile uint32 *base = (volatile uint32 *)(hMcbsp->baseAddr);

  register volatile int x0,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13;



  gie = int_disable();



  /* the compiler generates more efficient code if the loads */

  /* and stores are grouped together rather than intermixed  */

  x0  = config->spcr;

  x1  = config->rcr;

  x2  = config->xcr;

  x3  = config->srgr;

  x4  = config->mcr;

  x5  = config->rcere0;

  x6  = config->rcere1;

  x7  = config->rcere2;

  x8  = config->rcere3;

  x9  = config->xcere0;

  x10 = config->xcere1;

  x11 = config->xcere2;

  x12 = config->xcere3;

  x13 = config->pcr;



  base[_MCBSP_SPCR_OFFSET]   = 0x00000000;

  base[_MCBSP_RCR_OFFSET]    = x1;

  base[_MCBSP_XCR_OFFSET]    = x2;

  base[_MCBSP_SRGR_OFFSET]   = x3;

  base[_MCBSP_MCR_OFFSET]    = x4;

  base[_MCBSP_RCERE0_OFFSET] = x5;

  base[_MCBSP_RCERE1_OFFSET] = x6;

  base[_MCBSP_RCERE2_OFFSET] = x7;

  base[_MCBSP_RCERE3_OFFSET] = x8;

  base[_MCBSP_XCERE0_OFFSET] = x9;

  base[_MCBSP_XCERE1_OFFSET] = x10;

  base[_MCBSP_XCERE2_OFFSET] = x11;

  base[_MCBSP_XCERE3_OFFSET] = x12;

  base[_MCBSP_PCR_OFFSET]    = x13;

  base[_MCBSP_SPCR_OFFSET]   = x0;



  int_enable(gie);

}

/*----------------------------------------------------------------------------*/
void MCBSP_configArgs(MCBSP_Handle hMcbsp, uint32 spcr, uint32 rcr, 

  uint32 xcr, uint32 srgr, uint32 mcr, uint32 rcere0, uint32 rcere1, 

  uint32 rcere2, uint32 rcere3, uint32 xcere0, uint32 xcere1, uint32 xcere2, 

  uint32 xcere3, uint32 pcr)
{



  register volatile uint32 gie;

  volatile uint32 *base = (volatile uint32 *)(hMcbsp->baseAddr);



  gie = int_disable();



  base[_MCBSP_SPCR_OFFSET]   = 0x00000000;

  base[_MCBSP_RCR_OFFSET]    = rcr;

  base[_MCBSP_XCR_OFFSET]    = xcr;

  base[_MCBSP_SRGR_OFFSET]   = srgr;

  base[_MCBSP_MCR_OFFSET]    = mcr;

  base[_MCBSP_RCERE0_OFFSET] = rcere0;

  base[_MCBSP_RCERE1_OFFSET] = rcere1;

  base[_MCBSP_RCERE2_OFFSET] = rcere2;

  base[_MCBSP_RCERE3_OFFSET] = rcere3;

  base[_MCBSP_XCERE0_OFFSET] = xcere0;

  base[_MCBSP_XCERE1_OFFSET] = xcere1;

  base[_MCBSP_XCERE2_OFFSET] = xcere2;

  base[_MCBSP_XCERE3_OFFSET] = xcere3;

  base[_MCBSP_PCR_OFFSET]    = pcr;

  base[_MCBSP_SPCR_OFFSET]   = spcr;



  int_enable(gie);

}
/*----------------------------------------------------------------------------*/
void MCBSP_getConfig(MCBSP_Handle hMcbsp, MCBSP_Config *config)
{

  register volatile uint32 gie;

  volatile uint32 *base = (volatile uint32 *)(hMcbsp->baseAddr);

  volatile MCBSP_Config* cfg = (volatile MCBSP_Config*)config;

  register volatile int x0,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13;



  gie = int_disable();



  /* the compiler generates more efficient code if the loads */

  /* and stores are grouped together rather than intermixed  */



  x0  = base[_MCBSP_SPCR_OFFSET];

  x1  = base[_MCBSP_RCR_OFFSET];

  x2  = base[_MCBSP_XCR_OFFSET];

  x3  = base[_MCBSP_SRGR_OFFSET];

  x4  = base[_MCBSP_MCR_OFFSET];

  x5  = base[_MCBSP_RCERE0_OFFSET];

  x6  = base[_MCBSP_RCERE1_OFFSET];

  x7  = base[_MCBSP_RCERE2_OFFSET];

  x8  = base[_MCBSP_RCERE3_OFFSET];

  x9  = base[_MCBSP_XCERE0_OFFSET];

  x10 = base[_MCBSP_XCERE1_OFFSET];

  x11 = base[_MCBSP_XCERE2_OFFSET];

  x12 = base[_MCBSP_XCERE3_OFFSET];

  x13 = base[_MCBSP_PCR_OFFSET];



  cfg->spcr   = x0;

  cfg->rcr    = x1;

  cfg->xcr    = x2;

  cfg->srgr   = x3;

  cfg->mcr    = x4;

  cfg->rcere0 = x5;

  cfg->rcere1 = x6;

  cfg->rcere2 = x7;

  cfg->rcere3 = x8;

  cfg->xcere0 = x9;

  cfg->xcere1 = x10;

  cfg->xcere2 = x11;

  cfg->xcere3 = x12;

  cfg->pcr    = x13;

  int_enable(gie);
}

