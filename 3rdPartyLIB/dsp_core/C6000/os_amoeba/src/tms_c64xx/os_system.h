// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: all
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp866
// !: d: Модуль содержит прототипы функций для работы с системными настройками.
// !: -:
// ---------------------------------------------------------------------------
#ifndef __OS_System_H__
#define __OS_System_H__

#include <os_types.h>

// -- Register constants -----------------------------------------------------

#define OSCFG0                  0
#define OSTS0                   1
#define OSTS1                   2
#define OSSYSQUANT              3

// -- Configuration variables ------------------------------------------------

extern uint64                   sys_frequency;
extern uint32                   sys_quant;
extern uint32                   sys_stack;

// -- Core config ------------------------------------------------------------

#define OSCFG0_STACK_PAGE0      0x00000000
#define OSCFG0_STACK_PAGE1      0x00000001
#define OSCFG0_STACK_PAGE2      0x00000002
#define OSCFG0_STACK_PAGE3      0x00000003

#define OSCFG0_HEAP_PAGE0       0x00000000
#define OSCFG0_HEAP_PAGE1       0x00000008
#define OSCFG0_HEAP_PAGE2       0x00000010
#define OSCFG0_HEAP_PAGE3       0x00000018

#define OSCFG0_STACK_PAGEM      0x00000003
#define OSCFG0_STACK_PAGEU      0x00000004
#define OSCFG0_HEAP_PAGEM       0x00000018
#define OSCFG0_HEAP_PAGEU       0x00000020

extern uint32                   REG_OSCFG0;

// -- Self test registers ----------------------------------------------------

#define OSTS0_MSD0_FAIL         0x00000001
#define OSTS0_USB_FAIL          0x00000002
#define OSTS0_KBD_FAIL          0x00000004
#define OSTS0_RIK_FAIL          0x00000008
#define OSTS0_RND_FAIL          0x00000010
#define OSTS0_LED_FAIL          0x00000020
#define OSTS0_DISPLAY_FAIL      0x00000040
#define OSTS0_FWMEM_FAIL        0x00000080
#define OSTS0_NETCARD_FAIL      0x00000100
#define OSTS0_SNSD_0_FAIL       0x00000200
#define OSTS0_SNSD_1_FAIL       0x00000400
#define OSTS0_CRYPTER_FAIL      0x00000800
#define OSTS0_GPIO_FAIL         0x00001000
#define OSTS0_MCBSP_FAIL        0x00002000
#define OSTS0_USBHC_FAIL        0x00004000
#define OSTS0_USBMS_FAIL        0x00008000
#define OSTS0_RTC_FAIL          0x00010000
#define OSTS0_NVRAM_FAIL1       0x00020000
#define OSTS0_DUAL_RAM_FAIL     0x00040000
#define OSTS0_NVRAM_FAIL2       0x00080000

#define OSTS1_MPAGE0_FAIL       0x00000001
#define OSTS1_MPAGE1_FAIL       0x00000002
#define OSTS1_MPAGE2_FAIL       0x00000004
#define OSTS1_MPAGE3_FAIL       0x00000008
#define OSTS1_EXCH_COMM0_FAIL   0x00000010
#define OSTS1_EXCH_COMM1_FAIL   0x00000020
#define OSTS1_EXCH_COMM2_FAIL   0x00000040
#define OSTS1_EXCH_COMM3_FAIL   0x00000080
#define OSTS1_EXCH_MAIN_FAIL    0x00000100
#define OSTS1_EXCH_IFACE_FAIL   0x00000200
#define OSTS1_EXCH_FAIL         0x00000400
#define OSTS1_RTC_OPEN_FAIL     0x00000800
#define OSTS1_EXTRAM_FAIL       0x00001000
#define OSTS1_NETFS_FAIL        0x00002000
#define OSTS1_TCPIP_FAIL        0x00004000

extern uint32                   REG_OSTS0;
extern uint32                   REG_OSTS1;

// -- Functions --------------------------------------------------------------

extern void                     os_system_init_module( int32 stage );

extern int32                    os_system_setname( const char* name );
extern int32                    os_system_getname( char* buf, uint32 buf_length );
extern int32                    os_system_chkname( const char* name );
extern int32                    os_system_reglock();
extern int32                    os_system_regunlock();
extern int32                    os_system_regget( uint32 regid, uint32* value );
extern int32                    os_system_regset( uint32 regid, uint32 value );
extern void                     os_system_debug( uint32 x );

extern int32                    os_system_buslock();
extern int32                    os_system_busunlock();
// ---------------------------------------------------------------------------

#endif
