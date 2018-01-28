// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp1251
// !: d: Модуль содержит реализацию функций работы с MDIO модулем
// !: d: процессора tms320c6412.
// !: -: 
// ---------------------------------------------------------------------------
#include <drv_eth6412_mdio.h>

// Standard defines/assumptions for MDIO interface

#define VBUSCLK     125     /* VBUS Clock Rate in MHz (1-255) */

#define MICREL_ID       0x0022

/*-----------------------------------------------------------------------*\
* PHY Control Register Macros
*
* These MACROS provide an easy way to read/write PHY registers
\*-----------------------------------------------------------------------*/
#define PHYREG_read(regadr, phyadr)                         \
            MDIO_RSET( USERACCESS0,                         \
                    MDIO_FMK(USERACCESS0,GO,1u)         |   \
                    MDIO_FMK(USERACCESS0,REGADR,regadr) |   \
                    MDIO_FMK(USERACCESS0,PHYADR,phyadr) )

#define PHYREG_write(regadr, phyadr, data)                  \
            MDIO_RSET( USERACCESS0,                         \
                    MDIO_FMK(USERACCESS0,GO,1u)         |   \
                    MDIO_FMK(USERACCESS0,WRITE,1u)      |   \
                    MDIO_FMK(USERACCESS0,REGADR,regadr) |   \
                    MDIO_FMK(USERACCESS0,PHYADR,phyadr) |   \
                    MDIO_FMK(USERACCESS0,DATA, data) )

#define PHYREG_wait()                                       \
            while( MDIO_FGET(USERACCESS0,GO) )

#define PHYREG_waitResults( results )  {                    \
            while( MDIO_FGET(USERACCESS0,GO) );             \
            results = MDIO_FGET(USERACCESS0,DATA); }

#define PHYREG_waitResultsAck( results, ack )  {            \
            while( MDIO_FGET(USERACCESS0,GO) );             \
            results = MDIO_FGET(USERACCESS0,DATA);          \
            ack = MDIO_FGET(USERACCESS0,ACK); }


/*-----------------------------------------------------------------------*\
* PHY State Machine
*
* When using auto-negotiation, the software must keep the MAC in
* sync with the PHY (for duplex). This module will also attempt to
* "auto-select" the PHY from a potential list of 32 based on which is
* first to get a link.
*
* On detection of a good link, the link speed and duplex settings will be
* used to update the EMAC configuration (done external to this module).
\*-----------------------------------------------------------------------*/

/* States in the PHY State Machine */
#define PHYSTATE_MDIOINIT       0
//#define PHYSTATE_NWAYSTART      1
//#define PHYSTATE_NWAYWAIT       2
#define PHYSTATE_LINKWAIT       3
#define PHYSTATE_LINKED         4


/*-----------------------------------------------------------------------*\
* MDIO_open()
*
* Opens the MDIO peripheral and start searching for a PHY device.
*
* It is assumed that the MDIO module is reset prior to calling this
* function.
\*-----------------------------------------------------------------------*/
void MDIO_open( Handle hMDIO, uint32 mdioModeFlags )
{
  MDIO_Device *pMDev = (MDIO_Device *)hMDIO;
 // Get the mode flags from the user - clear our reserved flag /
  pMDev->ModeFlags = mdioModeFlags & ~MDIO_MODEFLG_NWAYACTIVE;

 // Setup the MDIO state machine defaults /
  pMDev->phyAddr       = 0;
  pMDev->phyState      = PHYSTATE_MDIOINIT;
  pMDev->LinkStatus    = MDIO_LINKSTATUS_NOLINK;

 // Enable MDIO and setup divider /
  MDIO_RSET( CONTROL, MDIO_FMKS(CONTROL,ENABLE,YES) | MDIO_FMK(CONTROL,CLKDIV,VBUSCLK) );
}


/*-----------------------------------------------------------------------*\
* MDIO_close()
*
* Close the  MDIO peripheral and disable further operation.
\*-----------------------------------------------------------------------*/
void MDIO_close( Handle hMDIO )
{
  MDIO_Device *pmd = (MDIO_Device *)hMDIO;;

  PHYREG_write( PHYREG_CONTROL, pmd->phyAddr, PHYREG_CONTROL_ISOLATE | PHYREG_CONTROL_POWERDOWN );
  PHYREG_wait();
}
//-----------------------------------------------------------------------
// MDIO_findPHY(Handle hMDIO)
//
// Returns an MDIO event code (see MDIO Events in CSL_MDIO.H).
//-----------------------------------------------------------------------
int32 MDIO_findPHY( Handle hMDIO )
{
  MDIO_Device *pmd = (MDIO_Device *)hMDIO;
  uint32 ltmp1;
  uint64 tms;
    
  // If running in a non-linked state, execute the next
  // state of the state machine.
  if( pmd->phyState != PHYSTATE_LINKED )
  {
    // Here we just try to find a PHY /
    tms = time_core();
    do
    {
      ltmp1 = MDIO_RGET( ALIVE );
      if( (time_core() - tms) >= 1000 ) 
         return OSE_NO_PHY;
    }while (!ltmp1);

    for( uint32 i = 0; i < 32; i++ )
    {
      ++pmd->phyAddr;
      if( ltmp1 & (1 << pmd->phyAddr) )
        break;
    }

    if( MDIO_initPHY( pmd ) == 0 )
      return OSE_PHY_ERROR;

    // Start monitoring this PHY /
    MDIO_RSET( USERPHYSEL0, pmd->phyAddr );
    MDIO_FSETS( USERPHYSEL0, LINKINTENB, ENABLE );

    MDIO_RSET( USERPHYSEL1, 31 );
    // Clear the link change flag so we can detect a "re-link" later /
    MDIO_RSET( LINKINTRAW, 3 );

    // Setup our linked state /
    pmd->phyState   = PHYSTATE_LINKED;
    pmd->LinkStatus = MDIO_LINKSTATUS_FD100;
  }
  return OSE_OK;
}

/*-----------------------------------------------------------------------*\
* MDIO_initPHY()
*
* Force a switch to the specified PHY, and start the negotiation process.
*
* Returns 1 if the PHY selection completed OK, else 0
\*-----------------------------------------------------------------------*/
uint32 MDIO_initPHY( Handle hMDIO )
{
  MDIO_Device *pmd = (MDIO_Device *)hMDIO;
  uint16 tmp1, tmp2;
  uint32 i;

  // There will be no link when we're done with this PHY /
  pmd->LinkStatus = MDIO_LINKSTATUS_NOLINK;

  // Reset the PHY we plan to use /
  PHYREG_write( PHYREG_CONTROL, pmd->phyAddr, PHYREG_CONTROL_RESET );
  PHYREG_wait();

  sleep_m( 50 );

    // Wait for reset to go low (but not forever) /
  for( i=0; i<10000; i++ )
  {
    PHYREG_read( PHYREG_CONTROL, pmd->phyAddr );
    PHYREG_waitResults( tmp1 );
    if( (tmp1 & PHYREG_CONTROL_RESET) != PHYREG_CONTROL_RESET )
      break;
  }
  if( i == 10000 )
    return(0);

  pmd->control_reg = tmp1;

  // We will use a fixed configuration /

  // read PHY Identifier 1 register
  PHYREG_read( PHYREG_ID1, pmd->phyAddr );
  PHYREG_waitResults( tmp1 );

  if( tmp1 == MICREL_ID )
  {
    PHYREG_read( PHYREG_PHY_CONTROL_1, pmd->phyAddr );
    PHYREG_waitResults( tmp1 );
    // write PHY LED CONFIGURATION for MICREL
    PHYREG_write( PHYREG_PHY_CONTROL_1, pmd->phyAddr, tmp1 | 0x4000 );
    PHYREG_wait();
    // Setup Control word and pending status /
    if(pmd->control_reg & PHYREG_CONTROL_AUTONEGEN)
      tmp2 = PHYREG_CONTROL_SPEED100 | PHYREG_CONTROL_DUPLEXFULL;
    else
      tmp2 = PHYREG_CONTROL_DUPLEXFULL;
  }
  else
  {
    // write PHY LED CONFIGURATION for LXT971A
    PHYREG_write( PHYREG_LEDCONFIG, pmd->phyAddr, 0x5476 );
    PHYREG_wait();

    // Setup Control word and pending status /
    tmp2 = PHYREG_CONTROL_DUPLEXFULL;
    pmd->control_reg &= ~PHYREG_CONTROL_AUTONEGEN;
  }

  // Configure PHY /
  PHYREG_write( PHYREG_CONTROL, pmd->phyAddr, tmp2 );
  PHYREG_wait();

  // Add in loopback if user wanted it /
  if( pmd->ModeFlags & MDIO_MODEFLG_LOOPBACK )
  {
    tmp2 |= PHYREG_CONTROL_LOOPBACK;

    // Configure PHY /
    PHYREG_write( PHYREG_CONTROL, pmd->phyAddr, tmp2 );
    PHYREG_wait();
  }
  // Setup current state /
  pmd->ModeFlags &= ~MDIO_MODEFLG_NWAYACTIVE;
  pmd->phyState = PHYSTATE_LINKWAIT;
 
  return(1);
}


/*-----------------------------------------------------------------------*\
* MDIO_phyRegRead()
*
* Raw data read of a PHY register.
*
* Returns 1 if the PHY ACK'd the read, else 0
\*-----------------------------------------------------------------------*/
uint32 MDIO_phyRegRead( volatile uint32 phyIdx, volatile uint32 phyReg, uint16 *pData )
{
  uint32 data,ack;

  PHYREG_read( phyReg, phyIdx );
  PHYREG_waitResultsAck( data, ack );
  if( !ack )
    return(0);
  if( pData )
    *pData = data;
  return(1);
}


/*-----------------------------------------------------------------------*\
* MDIO_phyRegWrite()
*
* Raw data write of a PHY register.
*
* Returns 1 if the PHY ACK'd the write, else 0
\*-----------------------------------------------------------------------*/
uint32 MDIO_phyRegWrite( volatile uint32 phyIdx, volatile uint32 phyReg, uint16 data )
{
  uint32 ack;

  PHYREG_write( phyReg, phyIdx, data );
  PHYREG_waitResultsAck( data, ack );
  if( !ack )
    return(0);
  return(1);
}

