// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp1251
// !: d: Модуль содержит прототипы функций и описание структур для работы
// !: d: с модулем MDIO процессора tms320c6412
// !: -: 
// ---------------------------------------------------------------------------
#ifndef _ETH6412_MDIO_H
#define _ETH6412_MDIO_H_


#include <drv_eth6412_mdiohal.h>
#include <os.h>


typedef void * Handle;

typedef struct _MDIO_Device {
    uint32            ModeFlags;      /* User specified configuration flgs */
    uint32            phyAddr;        /* Current PHY addr (0-31) */
    uint32            phyState;       /* PHY State                         */
    uint32            LinkStatus;     /* Link State EMI_STATUS_LINKSTATUS  */
    uint32            control_reg;
} MDIO_Device;

/*-----------------------------------------------------------------------*\
* MDIO Configuration Mode Flags
*
* These flags determine how the MDIO module behaves
\*-----------------------------------------------------------------------*/
#define MDIO_MODEFLG_AUTONEG     0x0001 /* Use Autonegotiate         */
/* The following bits are used for manual and fallback configuration */
#define MDIO_MODEFLG_HD10        0x0002 /* Use 10Mb/s Half Duplex    */
#define MDIO_MODEFLG_FD10        0x0004 /* Use 10Mb/s Full Duplex    */
#define MDIO_MODEFLG_HD100       0x0008 /* Use 100Mb/s Half Duplex   */
#define MDIO_MODEFLG_FD100       0x0010 /* Use 100Mb/s Full Duplex   */
#define MDIO_MODEFLG_LOOPBACK    0x0020 /* Use PHY Loopback          */
/* The following bits are reserved for use by the MDIO module */
#define MDIO_MODEFLG_NWAYACTIVE  0x0040 /* NWAY is currently active  */

/*-----------------------------------------------------------------------*\
* MDIO Link Status Values
*
* These values indicate current PHY link status
\*-----------------------------------------------------------------------*/
#define MDIO_LINKSTATUS_NOLINK   0
#define MDIO_LINKSTATUS_HD10     1
#define MDIO_LINKSTATUS_FD10     2
#define MDIO_LINKSTATUS_HD100    3
#define MDIO_LINKSTATUS_FD100    4

/*-----------------------------------------------------------------------*\
* MDIO Events
*
* These events are returned by MDIO_timerTick() to allow the application
* (or EMAC) to track MDIO status.
\*-----------------------------------------------------------------------*/
//#define MDIO_EVENT_NOCHANGE      0   /* No change from previous status */
//#define MDIO_EVENT_LINKDOWN      1   /* Link down event                */
//#define MDIO_EVENT_LINKUP        2   /* Link (or re-link) event        */
//#define MDIO_EVENT_PHYERROR      3   /* No PHY connected               */


/*-----------------------------------------------------------------------*\
* PHY Control Registers
*
* Used by MDIO to configure a MII compliant PHY
\*-----------------------------------------------------------------------*/
#define PHYREG_CONTROL              0
#define PHYREG_CONTROL_RESET        (1<<15)
#define PHYREG_CONTROL_LOOPBACK     (1<<14)
#define PHYREG_CONTROL_SPEED100     (1<<13)
#define PHYREG_CONTROL_AUTONEGEN    (1<<12)
#define PHYREG_CONTROL_POWERDOWN    (1<<11)
#define PHYREG_CONTROL_ISOLATE      (1<<10)
#define PHYREG_CONTROL_AUTORESTART  (1<<9)
#define PHYREG_CONTROL_DUPLEXFULL   (1<<8)

#define PHYREG_STATUS               1
#define PHYREG_STATUS_FD100         (1<<14)
#define PHYREG_STATUS_HD100         (1<<13)
#define PHYREG_STATUS_FD10          (1<<12)
#define PHYREG_STATUS_HD10          (1<<11)
#define PHYREG_STATUS_NOPREAMBLE    (1<<6)
#define PHYREG_STATUS_AUTOCOMPLETE  (1<<5)
#define PHYREG_STATUS_REMOTEFAULT   (1<<4)
#define PHYREG_STATUS_AUTOCAPABLE   (1<<3)
#define PHYREG_STATUS_LINKSTATUS    (1<<2)
#define PHYREG_STATUS_JABBER        (1<<1)
#define PHYREG_STATUS_EXTENDED      (1<<0)

#define PHYREG_ID1                  2

#define PHYREG_ID2                  3

#define PHYREG_ADVERTISE            4
#define PHYREG_ADVERTISE_NEXTPAGE   (1<<15)
#define PHYREG_ADVERTISE_ACK        (1<<14)
#define PHYREG_ADVERTISE_FAULT      (1<<13)
#define PHYREG_ADVERTISE_PAUSE      (1<<10)
#define PHYREG_ADVERTISE_FD100      (1<<8)
#define PHYREG_ADVERTISE_HD100      (1<<7)
#define PHYREG_ADVERTISE_FD10       (1<<6)
#define PHYREG_ADVERTISE_HD10       (1<<5)
#define PHYREG_ADVERTISE_MSGMASK    (0x1F)
#define PHYREG_ADVERTISE_MSG        (1)

#define PHYREG_PARTNER              5
#define PHYREG_PARTNER_NEXTPAGE     (1<<15)
#define PHYREG_PARTNER_ACK          (1<<14)
#define PHYREG_PARTNER_FAULT        (1<<13)
#define PHYREG_PARTNER_PAUSE        (1<<10)
#define PHYREG_PARTNER_FD100        (1<<8)
#define PHYREG_PARTNER_HD100        (1<<7)
#define PHYREG_PARTNER_FD10         (1<<6)
#define PHYREG_PARTNER_HD10         (1<<5)
#define PHYREG_PARTNER_MSGMASK      (0x1F)

#define PHYREG_LEDCONFIG           20
#define PHYREG_PHY_CONTROL_1       30

/*-----------------------------------------------------------------------*\
* MDIO_open()
*
* Opens the MDIO peripheral and start searching for a PHY device.
*
* It is assumed that the MDIO module is reset prior to calling this
* function.
\*-----------------------------------------------------------------------*/
extern "C" void MDIO_open( Handle hMDIO, uint32 mdioModeFlags );

/*-----------------------------------------------------------------------*\
* MDIO_close()
*
* Close the MDIO peripheral and disable further operation.
\*-----------------------------------------------------------------------*/
extern "C" void MDIO_close( Handle hMDIO );

/*-----------------------------------------------------------------------*\
* MDIO_getStatus()
*
* Called to get the status of the MDIO/PHY
\*-----------------------------------------------------------------------*/
//extern "C" void MDIO_getStatus( Handle hMDIO, uint32 *pPhy, uint32 *pLinkStatus );

/*-----------------------------------------------------------------------*\
* MDIO_timerTick()
*
* Called to signify that approx 100mS have elapsed
*
* Returns an MDIO event code (see MDIO Events in CSL_MDIO.H).
\*-----------------------------------------------------------------------*/
extern "C" int32 MDIO_findPHY( Handle hMDIO );


/*-----------------------------------------------------------------------*\
* MDIO_initPHY()
*
* Force a switch to the specified PHY, and start negotiation.
*
* This call is only used to override the normal PHY detection process.
*
* Returns 1 if the PHY selection completed OK, else 0
\*-----------------------------------------------------------------------*/
extern "C" uint32 MDIO_initPHY( Handle hMDIO );

/*-----------------------------------------------------------------------*\
* MDIO_phyRegRead()
*
* Raw data read of a PHY register.
*
* Returns 1 if the PHY ACK'd the read, else 0
\*-----------------------------------------------------------------------*/
extern "C" uint32 MDIO_phyRegRead( uint32 phyIdx, uint32 phyReg, uint16 *pData );

/*-----------------------------------------------------------------------*\
* MDIO_phyRegWrite()
*
* Raw data write  of a PHY register.
*
* Returns 1 if the PHY ACK'd the write, else 0
\*-----------------------------------------------------------------------*/
extern "C" uint32 MDIO_phyRegWrite( uint32 phyIdx, uint32 phyReg, uint16 data );

#endif /* _ETH6412_MDIO_H_ */
