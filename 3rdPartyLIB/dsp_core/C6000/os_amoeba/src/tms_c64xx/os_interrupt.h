// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp866
// !: d: Модуль содержит прототипы функций менеджера прерываний.
// !: -:
// ---------------------------------------------------------------------------
#ifndef __OS_Interrupt_H__
#define __OS_Interrupt_H__

#include <os_types.h>

// -- Interrupt registers ----------------------------------------------------

#if defined(CHIP_6412) || defined(CHIP_6416)

#define REG_MUXH                (*(volatile uint32*)0x019c0000)
#define REG_MUXL                (*(volatile uint32*)0x019c0004)
#define REG_EXTPOL              (*(volatile uint32*)0x019c0008)

#endif

#if defined(CHIP_6457)

#define REG_EVTFLAG             ((volatile uint32*)0x01800000)
#define REG_EVTFLAG0            (*(volatile uint32*)0x01800000)
#define REG_EVTFLAG1            (*(volatile uint32*)0x01800004)
#define REG_EVTFLAG2            (*(volatile uint32*)0x01800008)
#define REG_EVTFLAG3            (*(volatile uint32*)0x0180000c)

#define REG_EVTSET              ((volatile uint32*)0x01800020)
#define REG_EVTSET0             (*(volatile uint32*)0x01800020)
#define REG_EVTSET1             (*(volatile uint32*)0x01800024)
#define REG_EVTSET2             (*(volatile uint32*)0x01800028)
#define REG_EVTSET3             (*(volatile uint32*)0x0180002c)

#define REG_EVTCLR              ((volatile uint32*)0x01800040)
#define REG_EVTCLR0             (*(volatile uint32*)0x01800040)
#define REG_EVTCLR1             (*(volatile uint32*)0x01800044)
#define REG_EVTCLR2             (*(volatile uint32*)0x01800048)
#define REG_EVTCLR3             (*(volatile uint32*)0x0180004c)

#define REG_EVTMASK             ((volatile uint32*)0x01800080)
#define REG_EVTMASK0            (*(volatile uint32*)0x01800080)
#define REG_EVTMASK1            (*(volatile uint32*)0x01800084)
#define REG_EVTMASK2            (*(volatile uint32*)0x01800088)
#define REG_EVTMASK3            (*(volatile uint32*)0x0180008c)

#define REG_MEVTFLAG            ((volatile uint32*)0x018000a0)
#define REG_MEVTFLAG0           (*(volatile uint32*)0x018000a0)
#define REG_MEVTFLAG1           (*(volatile uint32*)0x018000a4)
#define REG_MEVTFLAG2           (*(volatile uint32*)0x018000a8)
#define REG_MEVTFLAG3           (*(volatile uint32*)0x018000ac)

#define REG_EXPMASK             ((volatile uint32*)0x018000c0)
#define REG_EXPMASK0            (*(volatile uint32*)0x018000c0)
#define REG_EXPMASK1            (*(volatile uint32*)0x018000c4)
#define REG_EXPMASK2            (*(volatile uint32*)0x018000c8)
#define REG_EXPMASK3            (*(volatile uint32*)0x018000cc)

#define REG_MEXPFLAG            ((volatile uint32*)0x018000e0)
#define REG_MEXPFLAG0           (*(volatile uint32*)0x018000e0)
#define REG_MEXPFLAG1           (*(volatile uint32*)0x018000e4)
#define REG_MEXPFLAG2           (*(volatile uint32*)0x018000e8)
#define REG_MEXPFLAG3           (*(volatile uint32*)0x018000ec)

#define REG_INTMUX              ((volatile uint32*)0x01800100)
#define REG_INTMUX0             (*(volatile uint32*)0x01800100) // Do not use this register (it's not documented)
#define REG_INTMUX1             (*(volatile uint32*)0x01800104)
#define REG_INTMUX2             (*(volatile uint32*)0x01800108)
#define REG_INTMUX3             (*(volatile uint32*)0x0180010c)

#define REG_AEGMUX0             (*(volatile uint32*)0x01810140)
#define REG_AEGMUX1             (*(volatile uint32*)0x01810144)
#define REG_INTXSTAT            (*(volatile uint32*)0x01800180)
#define REG_INTXCLR             (*(volatile uint32*)0x01800184)
#define REG_INTDMASK            (*(volatile uint32*)0x01800188)

#endif

// -- Interrupt sources ------------------------------------------------------

#if defined(CHIP_6412) || defined(CHIP_6416)

#define INT_TIMER0              1
#define INT_TIMER1              2
#define INT_TIMER2              19
#define INT_MCBSP0_RX           13
#define INT_MCBSP1_RX           15
#define INT_MCBSP2_RX           18
#define INT_MCBSP0_TX           12
#define INT_MCBSP1_TX           14
#define INT_MCBSP2_TX           17
#define INT_SD_INTA             3
#define INT_SD_INTB             20
#define INT_UTOPIA              23
#define INT_DSP                 0
#define INT_GP0                 16
#define INT_GP4                 4
#define INT_GP5                 5
#define INT_GP6                 6
#define INT_GP7                 7
#define INT_EDMA                8
#define INT_PCI_WAKEUP          21
#define INT_EMAC_MDIO           24
#define INT_NMI                 1024
#define INT_NOTUSED             0xffffffff

#endif

#if defined(CHIP_6457)

#define INT_EVT0                0    // Output of event combiner 0 in interrupt controller, for events 1 - 31.
#define INT_EVT1                1    // Output of event combiner 1 in interrupt controller, for events 32 - 63.
#define INT_EVT2                2    // Output of event combiner 2 in interrupt controller, for events 64 - 95.
#define INT_EVT3                3    // Output of event combiner 3 in interrupt controller, for events 96 - 127.
#define INT_EMU_DTDMA           9    // EMU interrupt for: Host scan access; DTDMA transfer complete; AET interrupt
#define INT_EMU_RTDXRX          11   // EMU real-time data exchange (RTDX) receive complete
#define INT_EMU_RTDXTX          12   // EMU RTDX transmit complete
#define INT_IDMA0               13   // IDMA channel 0 interrupt
#define INT_IDMA1               14   // IDMA channel 1 interrupt
#define INT_DSPINT              15   // HPI-to-DSP interrupt
#define INT_I2CINT              16   // I2C interrupt
#define INT_MACINT              17   // Ethernet MAC interrupt
#define INT_AEASYNCERR          18   // EMIFA error interrupt
#define INT_INTDST0             20   // RapidIO interrupt 0
#define INT_INTDST1             21   // RapidIO interrupt 1
#define INT_INTDST2             22   // RapidIO interrupt 2
#define INT_INTDST3             23   // RapidIO interrupt 3
#define INT_EDMA3CC_GINT        24   // EDMA3 channel global completion interrupt
#define INT_MACRXINT            25   // Ethernet MAC receive interrupt
#define INT_MACTXINT            26   // Ethernet MAC transmit interrupt
#define INT_MACTHRESH           27   // Ethernet MAC receive threshold interrupt
#define INT_INTDST4             28   // RapidIO interrupt 4
#define INT_INTDST5             29   // RapidIO interrupt 5
#define INT_INTDST6             30   // RapidIO interrupt 6
#define INT_VCP2_INT            32   // VCP2 error interrupt
#define INT_TCP2A_INT           33   // TCP2_A error interrupt
#define INT_TCP2B_INT           34   // TCP2_B error interrupt
#define INT_UINT                36   // UTOPIA interrupt
#define INT_RINT0               40   // McBSP0 receive interrupt
#define INT_XINT0               41   // McBSP0 transmit interrupt
#define INT_RINT1               42   // McBSP1 receive interrupt
#define INT_XINT1               43   // McBSP1 transmit interrupt
#define INT_GPINT0              51   // GPIO interrupt
#define INT_GPINT1              52   // GPIO interrupt
#define INT_GPINT2              53   // GPIO interrupt
#define INT_GPINT3              54   // GPIO interrupt
#define INT_GPINT4              55   // GPIO interrupt
#define INT_GPINT5              56   // GPIO interrupt
#define INT_GPINT6              57   // GPIO interrupt
#define INT_GPINT7              58   // GPIO interrupt
#define INT_GPINT8              59   // GPIO interrupt
#define INT_GPINT9              60   // GPIO interrupt
#define INT_GPINT10             61   // GPIO interrupt
#define INT_GPINT11             62   // GPIO interrupt
#define INT_GPINT12             63   // GPIO interrupt
#define INT_GPINT13             64   // GPIO interrupt
#define INT_GPINT14             65   // GPIO interrupt
#define INT_GPINT15             66   // GPIO interrupt
#define INT_TINTLO0             67   // Timer 0 lower counter interrupt
#define INT_TINTHI0             68   // Timer 0 higher counter interrupt
#define INT_TINTLO1             69   // Timer 1 lower counter interrupt
#define INT_TINTHI1             70   // Timer 1 higher counter interrupt
#define INT_EDMA3CC_INT0        71   // EDMA3CC completion interrupt - Mask0
#define INT_EDMA3CC_INT1        72   // EDMA3CC completion interrupt - Mask1
#define INT_EDMA3CC_INT2        73   // EDMA3CC completion interrupt - Mask2
#define INT_EDMA3CC_INT3        74   // EDMA3CC completion interrupt - Mask3
#define INT_EDMA3CC_INT4        75   // EDMA3CC completion interrupt - Mask4
#define INT_EDMA3CC_INT5        76   // EDMA3CC completion interrupt - Mask5
#define INT_EDMA3CC_INT6        77   // EDMA3CC completion interrupt - Mask6
#define INT_EDMA3CC_INT7        78   // EDMA3CC completion interrupt - Mask7
#define INT_EDMA3CC_ERRINT      79   // EDMA3CC error interrupt
#define INT_EDMA3TC0_ERRINT     81   // EDMA3TC0 error interrupt
#define INT_EDMA3TC1_ERRINT     82   // EDMA3TC1 error interrupt
#define INT_EDMA3TC2_ERRINT     83   // EDMA3TC2 error interrupt
#define INT_EDMA3TC3_ERRINT     84   // EDMA3TC3 error interrupt
#define INT_EDMA3CC_AET         85   // EDMA3CC AET Event
#define INT_EDMA3TC4_ERRINT     86   // EDMA3TC4 error interrupt
#define INT_EDMA3TC5_ERRINT     87   // EDMA3TC5 error interrupt
#define INT_ETBOVFLINT          94   // Overflow condition occurred in ETB
#define INT_ETBUNFLINT          95   // Underflow condition occurred in ETB
#define INT_INTERR              96   // Interrupt Controller dropped CPU interrupt event
#define INT_EMC_IDMAERR         97   // EMC invalid IDMA parameters
#define INT_EFIINTA             100  // EFI interrupt from side A
#define INT_EFIINTB             101  // EFI interrupt from side B
#define INT_L1P_ED1             113  // L1P single bit error detected during DMA read
#define INT_L2_ED1              116  // L2 single bit error detected
#define INT_L2_ED2              117  // L2 two bit error detected
#define INT_PDC_INT             118  // Powerdown sleep interrupt
#define INT_SYS_CMPA            119  // CPU memory protection fault
#define INT_L1P_CMPA            120  // L1P CPU memory protection fault
#define INT_L1P_DMPA            121  // L1P DMA memory protection fault
#define INT_L1D_CMPA            122  // L1D CPU memory protection fault
#define INT_L1D_DMPA            123  // L1D DMA memory protection fault
#define INT_L2_CMPA             124  // L2 CPU memory protection fault
#define INT_L2_DMPA             125  // L2 DMA memory protection fault
#define INT_IDMA_CMPA           126  // IDMA CPU memory protection fault
#define INT_IDMA_BUSERR         127  // IDMA bus error interrupt

#define INT_NMI                 1024
#define INT_NOTUSED             0xffffffff

#endif

// -- Constants --------------------------------------------------------------


// -- Structures -------------------------------------------------------------

struct s_os_interrupt
{
  uint32                        id;                     // Resource ID
  uint32                        vector;                 // Interrupt vector number
  uint32                        source;                 // Interrupt source number
  uint16                        own_process;            // Resource owner
};

// -- Functions and variables ------------------------------------------------

extern s_os_interrupt           v_os_interrupt_table[];

extern void                     os_interrupt_enable_ll( uint32 old_state );
extern uint32                   os_interrupt_disable_ll();
extern void                     os_interrupt_lock_ll( uint32 int_number );
extern void                     os_interrupt_unlock_ll( uint32 int_number );
extern void                     os_interrupt_null_vector_ll();
extern void                     os_interrupt_nmi_trigger_ll();
extern void                     os_interrupt_trigger_ll();
extern void                     os_interrupt_clear_ll( uint32 int_number );
extern void                     os_interrupt_set_ll( uint32 int_number );

extern void                     os_interrupt_init_module();
extern uint32                   os_interrupt_check( uint32 rid );
extern void                     os_interrupt_cleanup();

extern uint32                   os_interrupt_alloc( uint32 source, void (*handler)() );
extern int32                    os_interrupt_free( uint32 rid );
extern void                     os_interrupt_swto( uint16 pid );
extern int32                    os_interrupt_lock( uint32 rid );
extern int32                    os_interrupt_unlock( uint32 rid );
extern int32                    os_interrupt_clear( uint32 rid );
extern int32                    os_interrupt_set( uint32 rid );

#endif
