/**********************************************************************************************************************
*                                        (c) COPYRIGHT by ZAO RCZI FORT.                                             *
*        ..                                       All rights reserved.                                               *
***********************************************************************************************************************
* Module      : emif.m632-comm.c64plus.cpp
* Description : Иногда зависает функция psc_powerup нужно перегоужать Прибор
* Author      : 
******************************************************************************
******************************************************************************
* Module's Description Record:
* ============================
* Module's revision history:
* ==========================
* --------- $Log: mpcdrvlbcCyclone.h $
* --------- Initial revision
******************************************************************************/


#include <os.h>

#define REG_EMIFA_MIDR                  (*(volatile uint32*)0x70000000) // Module ID and Revision Register
#define REG_EMIFA_STAT                  (*(volatile uint32*)0x70000004) // Status Register
#define REG_EMIFA_BURST_PRIO            (*(volatile uint32*)0x70000020) // Burst Priority Register
#define REG_EMIFA_CE2CFG                (*(volatile uint32*)0x70000080) // EMIFA CE2 Configuration Register
#define REG_EMIFA_CE3CFG                (*(volatile uint32*)0x70000084) // EMIFA CE3 Configuration Register
#define REG_EMIFA_CE4CFG                (*(volatile uint32*)0x70000088) // EMIFA CE4 Configuration Register
#define REG_EMIFA_CE5CFG                (*(volatile uint32*)0x7000008c) // EMIFA CE5 Configuration Register
#define REG_EMIFA_AWCC                  (*(volatile uint32*)0x700000a0) // EMIFA Async Wait Cycle Configuration Register
#define REG_EMIFA_INTRAW                (*(volatile uint32*)0x700000c0) // EMIFA Interrupt RAW Register
#define REG_EMIFA_INTMSK                (*(volatile uint32*)0x700000c4) // EMIFA Interrupt Masked Register
#define REG_EMIFA_INTMSKSET             (*(volatile uint32*)0x700000c8) // EMIFA Interrupt Mask Set Register
#define REG_EMIFA_INTMSKCLR             (*(volatile uint32*)0x700000cc) // EMIFA Interrupt Mask Clear Register

// ---------------------------------------------------------------------------

// Bus type selection (synchronouse/asynchronouse)
#define CECFG_SSEL_SYNCH                0x80000000
#define CECFG_SSEL_ASYNCH               0x00000000

// Used for asynchronouse bus configuration
#define CECFG_A_SS_ENABLE               0x40000000
#define CECFG_A_SS_DISABLE              0x00000000
#define CECFG_A_BWEM_ENABLE             0x20000000
#define CECFG_A_BWEM_DISABLE            0x00000000
#define CECFG_A_AE_ENABLE               0x10000000
#define CECFG_A_AE_DISABLE              0x00000000
#define CECFG_A_W_SETUP( a )            ( ( (a) & 0x0000000f ) << 24 )
#define CECFG_A_W_STROBE( a )           ( ( (a) & 0x0000003f ) << 18 )
#define CECFG_A_W_HOLD( a )             ( ( (a) & 0x00000007 ) << 15 )
#define CECFG_A_R_SETUP( a )            ( ( (a) & 0x0000000f ) << 11 )
#define CECFG_A_R_STROBE( a )           ( ( (a) & 0x0000003f ) << 5  )
#define CECFG_A_R_HOLD( a )             ( ( (a) & 0x00000007 ) << 2  )
#define CECFG_A_SIZE_8                  0x00000000
#define CECFG_A_SIZE_16                 0x00000001
#define CECFG_A_SIZE_32                 0x00000002
#define CECFG_A_SIZE_64                 0x00000003

// Used for synchronouse bus configuration
#define CECFG_S_RD_BE_EN                0x00000400
#define CECFG_S_CE_EXT                  0x00000200
#define CECFG_S_R_ENABLE                0x00000100
#define CECFG_S_W_LATENCY_0             0x00000000
#define CECFG_S_W_LATENCY_1             0x00000040
#define CECFG_S_W_LATENCY_2             0x00000080
#define CECFG_S_W_LATENCY_3             0x000000c0
#define CECFG_S_R_LATENCY_0             0x00000000
#define CECFG_S_R_LATENCY_1             0x00000004
#define CECFG_S_R_LATENCY_2             0x00000008
#define CECFG_S_R_LATENCY_3             0x0000000c
#define CECFG_S_SIZE_8                  0x00000000
#define CECFG_S_SIZE_16                 0x00000001
#define CECFG_S_SIZE_32                 0x00000002
#define CECFG_S_SIZE_64                 0x00000003

#define AWCC_AP_ACTIVE_HIGH             0x40000000
#define AWCC_AP_ACTIVE_LOW              0x00000000
#define AWCC_AT( a )                    ( ( (a) & 0x00000007 ) << 8  )
#define AWCC_MAX_EXT_WAIT( a )          ( ( (a) & 0x000000ff )       )

#define PSC_PID                         (*(volatile uint32*)0x02ac0000) // Peripheral Revision and Class Information Section 3.2.1
#define PSC_PTCMD                       (*(volatile uint32*)0x02ac0120) // Power Domain Transition Command Register Section 3.2.2
#define PSC_PTSTAT                      (*(volatile uint32*)0x02ac0128) // Power Domain Transition Status Register Section 3.2.3
#define PSC_PDSTAT0                     (*(volatile uint32*)0x02ac0200) // Power Domain Status Register 0-5 Section 3.2.4
#define PSC_PDSTAT1                     (*(volatile uint32*)0x02ac0204) // Power Domain Status Register 0-5 Section 3.2.4
#define PSC_PDSTAT2                     (*(volatile uint32*)0x02ac0208) // Power Domain Status Register 0-5 Section 3.2.4
#define PSC_PDSTAT3                     (*(volatile uint32*)0x02ac020c) // Power Domain Status Register 0-5 Section 3.2.4
#define PSC_PDSTAT4                     (*(volatile uint32*)0x02ac0210) // Power Domain Status Register 0-5 Section 3.2.4
#define PSC_PDSTAT5                     (*(volatile uint32*)0x02ac0214) // Power Domain Status Register 0-5 Section 3.2.4
#define PSC_PDCTL0                      (*(volatile uint32*)0x02ac0300) // Power Domain Control Register 0 (AlwaysOn) Section 3.2.5
#define PSC_PDCTL1                      (*(volatile uint32*)0x02ac0304) // Power Domain Control Register 1 (Serial RapidIO) Section 3.2.5
#define PSC_PDCTL2                      (*(volatile uint32*)0x02ac0308) // Power Domain Control Register 2 (TCP2_0) Section 3.2.5
#define PSC_PDCTL3                      (*(volatile uint32*)0x02ac030c) // Power Domain Control Register 3 (TCP2_1) Section 3.2.5
#define PSC_PDCTL4                      (*(volatile uint32*)0x02ac0310) // Power Domain Control Register 4 (VCP2) Section 3.2.5

#define PSC_MDSTAT                      ( (volatile uint32*)0x02ac0800) // Module Status Register
#define PSC_MDCTL                       ( (volatile uint32*)0x02ac0a00) // Module Control Register

#define PSC_MODULE_RESERVED             0
#define PSC_MODULE_C64XP_CORE           1
#define PSC_MODULE_EMIF64               2
#define PSC_MODULE_HPI                  3
#define PSC_MODULE_UTOPIA               4
#define PSC_MODULE_NEVERGATED           5
#define PSC_MODULE_DEBUGSS              6
#define PSC_MODULE_SRIO                 7
#define PSC_MODULE_TCP2_0               8
#define PSC_MODULE_TCP2_1               9
#define PSC_MODULE_VCP2                 10

// ---------------------------------------------------------------------------
bool psc_powerup( uint32 domain, uint32 module )
{
  // Check arguments
  if( domain >= 5 ) return false;
  domain = 1 << domain;
  if( module >= 11 ) return false;
  
  // 1. Wait for PTSTAT.GOSTAT[X] to clear to 0x0. Wait for any previously initiated
  //    transitions to finish before initiating a new transition.
  while( PSC_PTSTAT & domain );
  
  // 2. Set MDCTL[Y].NEXT to Enable (0x3). Note that you may set transitions in multiple
  //    MDCTL[Y].NEXT fields in this step as long as the corresponding power domain is on.
  PSC_MDCTL[module] = 0x00000003;
  
  // 3. Set PTCMD.GO[X] to 0x1 to initiate the transition(s).
  PSC_PTCMD = domain;

  // 4. Wait for PTSTAT.GOSTAT[X] to clear to 0x0. The module is safely in the new state
  //    only after PTSTAT.GOSTAT[X] clears to 0x0.
  while( PSC_PTSTAT & domain );

  return true;
}
// ---------------------------------------------------------------------------
void emif_m632_comm_init()
{
  // Powerup EMIF
  psc_powerup( 0, PSC_MODULE_EMIF64 );

  // FPGA
  REG_EMIFA_CE2CFG = CECFG_SSEL_SYNCH | CECFG_S_SIZE_64 | CECFG_S_W_LATENCY_0 | CECFG_S_R_LATENCY_1 |
                     CECFG_S_CE_EXT | CECFG_S_RD_BE_EN;

  // Flash ROM
  REG_EMIFA_CE3CFG = CECFG_SSEL_ASYNCH | CECFG_A_SIZE_8 | CECFG_A_SS_ENABLE |
                     CECFG_A_W_SETUP( 1 ) | CECFG_A_W_STROBE( 4 ) | CECFG_A_W_HOLD( 1 ) |
                     CECFG_A_R_SETUP( 1 ) | CECFG_A_R_STROBE( 4 ) | CECFG_A_R_HOLD( 1 );
  
  // FPGA
  REG_EMIFA_CE4CFG = CECFG_SSEL_SYNCH | CECFG_S_SIZE_64 | CECFG_S_W_LATENCY_0 | CECFG_S_R_LATENCY_1 |
                     CECFG_S_CE_EXT | CECFG_S_RD_BE_EN;

  // FPGA
  REG_EMIFA_CE5CFG = CECFG_SSEL_SYNCH | CECFG_S_SIZE_64 | CECFG_S_W_LATENCY_0 | CECFG_S_R_LATENCY_1 |
                     CECFG_S_CE_EXT | CECFG_S_RD_BE_EN;
}
// ---------------------------------------------------------------------------

s_os_extension modemif;

s_os_extension_f modemif_f[] =
{
  { NULL, SYSCALL_EMIF_INIT, (uint32)&emif_m632_comm_init }
};

// ---------------------------------------------------------------------------
OS_MODULE_INICIATOR( modemif )
{
  OS_MODULE_INIT( modemif )
  {
    modemif.name = "modemif-init.lif";
    modemif.f_count = sizeof(modemif_f) / sizeof(s_os_extension_f);
    modemif.f_tab = modemif_f;
    modemif.flags = EXT_F_STATIC;
    ext_plug( &modemif );
  }
  OS_MODULE_DEINIT( modemif ) { }
}
OS_MODULE_ACTIVATOR( modemif );
// ---------------------------------------------------------------------------
