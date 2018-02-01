
#ifndef _CSL_SGMII_H_
#define _CSL_SGMII_H_

#include <drv_eth6457_sgmiihal.h>

// SGMII module base address
#define CSL_SGMII_0_REGS                (0x02C40000u)

// SGMII module Base address
#define SGMII_REGS    ((CSL_SgmiiRegs *)CSL_SGMII_0_REGS)

// macros for mode of operation of SGMII
// To select auto negotiation mode
#define SGMII_MODE_OF_OPERATION_WITH_AN      0x1
// Not to select auto negotiation mode
#define SGMII_MODE_OF_OPERATION_WITHOUT_AN   0x2


// These macros can be used to extract the specific status value read from STATUS reg

#define SGMII_STATUS_FIB_SIG_DETECT      0x00000020	// Fiber signal detect status
#define SGMII_STATUS_LOCK                0x00000010	// lock status
#define SGMII_STATUS_MR_PAGE_NEXT        0x00000008	// Next page received status
#define SGMII_STATUS_MR_AN_COMPLTE       0x00000004	// Auto negotiation complete status
#define SGMII_STATUS_AN_ERROR            0x00000002	// Auto negotiation status
#define SGMII_STATUS_LINK                0x00000001	// link indicator


// Error codes

#define SGMII_ERROR_INVALID   1		// Function or calling parameter is invalid
#define SGMII_ERROR_DEVICE    2		// Device hardware error

// CSL_SGMII_DATASTRUCT

// This structure is used for configuration of SGMII module
typedef struct  {
    uint8  masterEn;		// Enables master mode
    uint8  loopbackEn;		// Enables loopback
    uint8  modeOfOperation;	// SGMII mode of operation
    uint32 txConfig;		// Transmit configuration to control SERDES
    uint32 rxConfig;		// Receive configuration to control SERDES
    uint32 auxConfig;		// Auxiliary configuration to control SERDES
}SGMII_Config;

// SGMII module Status Structure
typedef struct  {
    uint32 txCfgStatus;		// Gets the status of Transmit configuration to control SERDES
    uint32 rxCfgStatus;		// Gets the status of Transmit configuration to control SERDES
    uint32 auxCfgStatus;	// Gets the status of Transmit configuration to control SERDES
}SGMII_Status;


// CSL_SGMII_FUNCTION

/** ============================================================================
 *   @n@b SGMII_reset
 *
 *   @b Description
 *   @n Module reset is achieved by calling SGMII_reset().
 *
 *   <b> Return Value </b>  Uint32
 *   @li Always returns a '0' if reset happens properly.
 *
 *   <b> Pre Condition </b>
 *   @n  None.
 *
 *   <b> Post Condition </b>
 *   @n  SGMII logic is reset
 *
 *   @b Modifies
 *   @n  Memory mapped register SOFT_RESET is modified.
 *
 *   @b Example
 *   @verbatim

     SGMII_reset ();

     @endverbatim
 * =============================================================================
 */
int32 SGMII_reset ();


/** ============================================================================
 *   @n@b SGMII_config
 *
 *   @b Description
 *   @n Module configuration is achieved by calling SGMII_config().
 *   @b Arguments
 *   @verbatim

            config        Reference to struture which contains configuration for the SGMII module

     @endverbatim
 *   <b> Return Value </b>  Uint32
 *   @li                    0                   - Configure successful
 *   @li                    SGMII_ERROR_INVALID - Invalid parameter
 *
 *   <b> Pre Condition </b>
 *   @n  None.
 *
 *   <b> Post Condition </b>
 *   @n  Module configuration is achieved.
 *
 *   @b Modifies
 *   @n SGMII registers are modified.
 *
 *   @b Example
 *   @verbatim
     ...
     SGMII_Config SgmiiCfg;

    SgmiiCfg.masterEn   = 0x0;
    SgmiiCfg.loopbackEn = 0x1;
    SgmiiCfg.txConfig   = 0x00000e13;
    SgmiiCfg.rxConfig   = 0x00081013;
    SgmiiCfg.auxConfig  = 0x0000000b;
    SgmiiCfg.modeOfOperation = 0x0;


     SGMII_reset();
     SGMII_config (&SgmiiCfg);
     ...
     @endverbatim
 * =============================================================================
 */
uint32 SGMII_config (SGMII_Config *config);


/** ============================================================================
 *   @n@b SGMII_getStatus                 SGMII module Status Structure
 *
 *   @b Description
 *   @n Module status is obtained by calling SGMII_getStatus().
 *   @b Arguments
 *   @verbatim

            status         Reference to an SGMII module Status Structure.

     @endverbatim
 *
 *   <b> Return Value </b>  Uint32
 *   @li                    0                   - Status is obtained successfully.
 *   @li                    SGMII_ERROR_INVALID - Invalid parameter.
 *
 *   <b> Pre Condition </b>
 *   @n  None.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Modifies
 *   @n  Updates the argument "status".
 *
 *   @b Example
 *   @verbatim
     ...
    SGMII_Status status;
    SGMII_Config SgmiiCfg;

    SgmiiCfg.masterEn   = 0x0;
    SgmiiCfg.loopbackEn = 0x1;
    SgmiiCfg.txConfig   = 0x00000e13;
    SgmiiCfg.rxConfig   = 0x00081013;
    SgmiiCfg.auxConfig  = 0x0000000b;
    SgmiiCfg.modeOfOperation = 0x0;


     SGMII_reset();
     SGMII_config (&SgmiiCfg);

     SGMII_getStatus (&status);
     ...
     @endverbatim
 * =============================================================================
 */
uint32 SGMII_getStatus (SGMII_Status *pStatus);


/** ============================================================================
 *   @n@b SGMII_getLinkPatnerStatus
 *
 *   @b Description
 *   @n Gets the status value of link partner.
 *
 *   <b> Return Value </b>  Uint32
 *   @li                    SGMII_ERROR_DEVICE  - auto negotiation not complete
 *
 *   <b> Pre Condition </b>
 *   @n  None.
 *
 *   <b> Post Condition </b>
 *   @n   returns auto negotiation status value
 *
 *   @b Modifies
 *   @n None.
 *
 *   @b Example
 *   @verbatim

    SGMII_Config SgmiiCfg;

    SgmiiCfg.masterEn   = 0x0;
    SgmiiCfg.loopbackEn = 0x1;
    SgmiiCfg.txConfig   = 0x00000e13;
    SgmiiCfg.rxConfig   = 0x00081013;
    SgmiiCfg.auxConfig  = 0x0000000b;
    SgmiiCfg.modeOfOperation = 0x0;


     SGMII_reset();
     SGMII_config (&SgmiiCfg);


     SGMII_getLinkPartnerStatus ( );
     ...
     @endverbatim
 * =============================================================================
 */
uint32 SGMII_getLinkPartnerStatus ();


/** ============================================================================
 *   @n@b SGMII_getAnErrorStatus
 *
 *   @b Description
 *   @n The function returns Error status of Auto negotiation process.
 *
 *   <b> Return Value </b>  Uint32
 *   @li Error status of Auto negotiation process.
 *
 *   <b> Pre Condition </b>
 *   @n  None.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Modifies
 *   @n None.
 *
 *   @b Example
 *   @verbatim

    SGMII_Config SgmiiCfg;

    SgmiiCfg.masterEn   = 0x0;
    SgmiiCfg.loopbackEn = 0x1;
    SgmiiCfg.speed      = 0x0;
    SgmiiCfg.txConfig   = 0x00000e13;
    SgmiiCfg.rxConfig   = 0x00081013;
    SgmiiCfg.auxConfig  = 0x0000000b;
    SgmiiCfg.diagSmSel = 0x0;
    SgmiiCfg.diagEdgeSel = 0x0;
    SgmiiCfg.modeOfOperation = 0x0;


    SGMII_reset();
    SGMII_config (&SgmiiCfg);

    SGMII_getAnErrorStatus ( );

     @endverbatim
 * =============================================================================
 */
uint32 SGMII_getAnErrorStatus ();

/** ============================================================================
 *   @n@b SGMII_getStatusReg
 *
 *   @b Description
 *   @n The function returns the value read from STATUS register
 *
 *   <b> Return Value </b>  Uint32
 *   @li Returns value read from STATUS register
 *
 *   <b> Pre Condition </b>
 *   @n  None.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Modifies
 *   @n None.
 *
 *   @b Example
 *   @verbatim

     SGMII_reset();
     SGMII_getStatusReg ( );

     @endverbatim
 * =============================================================================
 */
uint32 SGMII_getStatusReg ();


#endif  /* _CSL_SGMII_H_ */

