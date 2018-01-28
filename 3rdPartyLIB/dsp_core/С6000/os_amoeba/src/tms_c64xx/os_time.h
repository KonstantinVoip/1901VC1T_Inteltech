// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp866
// !: d: Модуль содержит прототипы функций для работы с системным таймером,
// !: d: временем и задержками.
// !: -:
// ---------------------------------------------------------------------------
#ifndef __OS_Time_H__
#define __OS_Time_H__

#include <os_types.h>

// -- Timer registers --------------------------------------------------------

#if defined(CHIP_6412) || defined(CHIP_6416)

#define REG_CTL0                        (*(volatile uint32*)0x01940000)
#define REG_CTL1                        (*(volatile uint32*)0x01980000)
#define REG_CTL2                        (*(volatile uint32*)0x01ac0000)

#define REG_PRD0                        (*(volatile uint32*)0x01940004)
#define REG_PRD1                        (*(volatile uint32*)0x01980004)
#define REG_PRD2                        (*(volatile uint32*)0x01ac0004)

#define REG_CNT0                        (*(volatile uint32*)0x01940008)
#define REG_CNT1                        (*(volatile uint32*)0x01980008)
#define REG_CNT2                        (*(volatile uint32*)0x01ac0008)

#define TCTL_FUNC                       0x00000001
#define TCTL_INVOUT                     0x00000002
#define TCTL_DATOUT                     0x00000004
#define TCTL_DATIN                      0x00000008
#define TCTL_PWID                       0x00000010
#define TCTL_GO                         0x00000040
#define TCTL_HLD                        0x00000080
#define TCTL_CP                         0x00000100
#define TCTL_CLKSRC                     0x00000200
#define TCTL_INVINP                     0x00000400
#define TCTL_TSTAT                      0x00000800
#define TCTL_SPND                       0x00008000

#endif

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#if defined(CHIP_6457)

#define REG_EMUMGT_CLKSPD0              (*(volatile uint32*)0x02940004) // Timer 0 Emulation Management/Clock Speed Register
#define REG_CNTLO0                      (*(volatile uint32*)0x02940010) // Timer 0 Counter Register Low
#define REG_CNTHI0                      (*(volatile uint32*)0x02940014) // Timer 0 Counter Register High
#define REG_PRDLO0                      (*(volatile uint32*)0x02940018) // Timer 0 Period Register Low
#define REG_PRDHI0                      (*(volatile uint32*)0x0294001c) // Timer 0 Period Register High
#define REG_TCR0                        (*(volatile uint32*)0x02940020) // Timer 0 Control Register
#define REG_TGCR0                       (*(volatile uint32*)0x02940024) // Timer 0 Global Control Register
#define REG_WDTCR0                      (*(volatile uint32*)0x02940028) // Timer 0 Watchdog Timer Control Register

#define REG_EMUMGT_CLKSPD1              (*(volatile uint32*)0x02980004) // Timer 1 Emulation Management/Clock Speed Register
#define REG_CNTLO1                      (*(volatile uint32*)0x02980010) // Timer 1 Counter Register Low
#define REG_CNTHI1                      (*(volatile uint32*)0x02980014) // Timer 1 Counter Register High
#define REG_PRDLO1                      (*(volatile uint32*)0x02980018) // Timer 1 Period Register Low
#define REG_PRDHI1                      (*(volatile uint32*)0x0298001c) // Timer 1 Period Register High
#define REG_TCR1                        (*(volatile uint32*)0x02980020) // Timer 1 Control Register
#define REG_TGCR1                       (*(volatile uint32*)0x02980024) // Timer 1 Global Control Register
#define REG_WDTCR1                      (*(volatile uint32*)0x02980028) // Timer 1 Watchdog Timer Control Register

#define TGCR_TIMMODE_64GP               0x00000000
#define TGCR_TIMMODE_32UNCHAINED        0x00000004
#define TGCR_TIMMODE_64WD               0x00000008
#define TGCR_TIMMODE_32CHAINED          0x0000000c
#define TGCR_TIMHIRS                    0x00000002
#define TGCR_TIMLORS                    0x00000001

#define TCR_ENAMODE_HI_DISABLED         0x00000000
#define TCR_ENAMODE_HI_ENABLED_ONCE     0x00400000
#define TCR_ENAMODE_HI_ENABLED          0x00800000
#define TCR_PWID_HI_1                   0x00000000
#define TCR_PWID_HI_2                   0x00010000
#define TCR_PWID_HI_3                   0x00020000
#define TCR_PWID_HI_4                   0x00030000
#define TCR_CP_HI_PULSE                 0x00000000
#define TCR_CP_HI_CLOCK                 0x00008000
#define TCR_INVOUTP_HI                  0x00002000
#define TCR_TSTAT_HI                    0x00001000
#define TCR_TIEN_LO                     0x00000200
#define TCR_CLKSRC_LO_INTERNAL          0x00000000
#define TCR_CLKSRC_LO_EXTERNAL          0x00000100
#define TCR_ENAMODE_LO_DISABLED         0x00000000
#define TCR_ENAMODE_LO_ENABLED_ONCE     0x00000040
#define TCR_ENAMODE_LO_ENABLED          0x00000080
#define TCR_PWID_LO_1                   0x00000000
#define TCR_PWID_LO_2                   0x00000010
#define TCR_PWID_LO_3                   0x00000020
#define TCR_PWID_LO_4                   0x00000030
#define TCR_CP_LO_PULSE                 0x00000000
#define TCR_CP_LO_CLOCK                 0x00000008
#define TCR_INVINP_LO                   0x00000004
#define TCR_INVOUTP_LO                  0x00000002
#define TCR_TSTAT_LO                    0x00000001

#endif

// -- Functions and Variables ------------------------------------------------

extern void                             os_time_init_module( int32 stage );
extern void                             os_time_cleanup();

extern void                             os_time_update();
extern void                             os_time_set( uint32 tm );
extern uint32                           os_time_s();
extern uint64                           os_time_m();
extern uint64                           os_time_u();
extern uint64                           os_time_n();
extern uint64                           os_time_core();
extern uint64                           os_time_core_n();
extern void                             os_sleep_s( uint32 s );
extern void                             os_sleep_m( uint32 ms );
extern void                             os_sleep_u( uint32 us );

#endif
