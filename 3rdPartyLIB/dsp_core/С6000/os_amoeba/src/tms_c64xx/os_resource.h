// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: all
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp866
// !: d: Модуль содержит прототипы функций менеджера ресурсов.
// !: -:
// ---------------------------------------------------------------------------
#ifndef __OS_Resource_H__
#define __OS_Resource_H__

#include <os_types.h>

// -- Constants --------------------------------------------------------------

#define RES_T_MASK              0xf0000000
#define RES_T_BAD               0x00000000
#define RES_T_INTERRUPT         0x10000000
#define RES_T_SEMAPHORE         0x20000000
#define RES_T_FSDESCRIPTOR      0x30000000
#define RES_T_MSGPIPE           0x40000000
#define RES_T_SOCKET            0x50000000
#define RES_T_MEMPAGE           0x60000000
#define RES_T_HEAP              0x70000000
#define RES_T_LOCAL             0xf0000000

#define RES_F_MASK              0x0f000000 // flags will be removed from current place
#define RES_F_USED              0x08000000
#define RES_F_SHARED            0x04000000

#define RES_I_MASK              0x00ffffff

#define RES_VOID                0x00000000

// -- Functions --------------------------------------------------------------

extern void                     os_resource_init_module();

extern int32                    os_resource_share( uint32 rid );
extern int32                    os_resource_unshare( uint32 rid );
extern int32                    os_resource_shared( uint32 rid );
extern int32                    os_resource_chown( uint32 rid, uint16 pid );

#endif
