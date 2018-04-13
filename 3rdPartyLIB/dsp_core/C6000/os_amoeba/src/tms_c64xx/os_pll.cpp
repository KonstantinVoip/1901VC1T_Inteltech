/**********************************************************************************************************************
*                                        (c) COPYRIGHT by ZAO RCZI FORT.                                             *
*        ..                                       All rights reserved.                                               *
***********************************************************************************************************************
* Module      : os_pll.cpp
* Description : for tms6457 DSP CPU 
* Author      : 
******************************************************************************
******************************************************************************
* Module's Description Record:
* ============================
* Module's revision history:
* ==========================
* --------- $Log:  $
* --------- Initial revision
******************************************************************************/


#include <os_pll.h>
// ---------------------------------------------------------------------------

#define REG_RSTYPE              (*(volatile uint32*)0x029a00e4) // Reset Type Status Register (Reset Controller)
#define REG_RSTCTRL             (*(volatile uint32*)0x029a00e8) // Software Reset Control Register
#define REG_RSTCFG              (*(volatile uint32*)0x029a00ec) // Reset Configuration Register
#define REG_PLLCTL              (*(volatile uint32*)0x029a0100) // PLL Control Register
#define REG_PLLM                (*(volatile uint32*)0x029a0110) // PLL Multiplier Control Register
#define REG_PREDIV              (*(volatile uint32*)0x029a0114) // PLL Pre-Divider Control Register 
#define REG_PLLDIV3             (*(volatile uint32*)0x029a0120) // PLL Controller Divider 3 Register
#define REG_POSTDIV             (*(volatile uint32*)0x029a0128) // PLL Post-Divider Register
#define REG_PLLCMD              (*(volatile uint32*)0x029a0138) // PLL Controller Command Register
#define REG_PLLSTAT             (*(volatile uint32*)0x029a013c) // PLL Controller Status Register
#define REG_ALNCTL              (*(volatile uint32*)0x029a0140) // PLL Controller Clock Align Control Register
#define REG_DCHANGE             (*(volatile uint32*)0x029a0144) // PLLDIV Ratio Change Status Register
#define REG_SYSTAT              (*(volatile uint32*)0x029a0150) // SYSCLK Status Register
#define REG_PLLDIV6             (*(volatile uint32*)0x029a0168) // PLL Controller Divider 6 Register
#define REG_PLLDIV7             (*(volatile uint32*)0x029a016c) // PLL Controller Divider 7 Register
#define REG_PLLDIV8             (*(volatile uint32*)0x029a0170) // PLL Controller Divider 8 Register

#define PLLCTL_ENSRC            0x00000020
#define PLLCTL_RST              0x00000008
#define PLLCTL_PWRDN            0x00000002
#define PLLCTL_EN               0x00000001

#define PLLDIV_ENABLE           0x00008000
#define PLLDIV_DISABLE          0x00000000

// ---------------------------------------------------------------------------
void os_pll_init_module()
{
  register uint32 i;

  // Switch PLL into bypass mode
  REG_PLLCTL &= ~PLLCTL_ENSRC;
  REG_PLLCTL &= ~PLLCTL_EN;
  asm( "        nop             4       " );

  // Reset PLL
  REG_PLLCTL |= PLLCTL_RST;
  
  // Configure core frequency
  REG_PREDIV = PLLDIV_ENABLE | 0;       // 50 MHz / 1 = 50 MHz
  REG_PLLM = 20 - 1;                    // 50 MHz x 20 = 1 GHz
  REG_POSTDIV = PLLDIV_ENABLE | 0;      // 1 GHz / 1 = 1 GHz

  // Configure clock (GEM_TRACE_CLK) for emulation and trace logic of the DSP
  REG_PLLDIV3 = PLLDIV_ENABLE | 4;      // 1 Ghz / 5 = 200 MHz

  // Configure clock (CHIP_CLKS) for an optional McBSP CLKS module input to drive the clock generator
  REG_PLLDIV6 = PLLDIV_DISABLE;         // Generator disabled

  // Configure clock (EMIF_MCLK) for an optional internal clock for EMIFA
  REG_PLLDIV7 = PLLDIV_DISABLE;         // Generator disabled (we use external 45MHz generator)

  // Configure clock (SLOW_SYSCLK)
  REG_PLLDIV8 = PLLDIV_ENABLE | 9;      // 1 Ghz / 10 = 100 MHz

  // Waiting for PLL reset (minimum 1000 ns)
  i = 1000;
  while( i-- ) asm( " nop " );

  // End of reset
  REG_PLLCTL &= ~PLLCTL_RST;

  // Switch PLL into PLL mode
  REG_PLLCTL |= PLLCTL_EN;
}
// ---------------------------------------------------------------------------
