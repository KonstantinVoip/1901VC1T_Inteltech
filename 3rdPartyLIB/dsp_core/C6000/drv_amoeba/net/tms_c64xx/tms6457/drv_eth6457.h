// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp1251
// !: d: Модуль содержит прототипы функций, описание структур, кодов ошибок
// !: d: и внутренних управляющих команд драйвера сетевого контроллера.
// !: -: 
// ---------------------------------------------------------------------------
#ifndef __ETH6457_H__
#define __ETH6457_H__

#include <os_types.h>
#include <net_struct.h>
#include <os_ioctl.h>

#define NET_READ_REG    ( NET__USER__ + 0 )
#define NET_WRITE_REG   ( NET__USER__ + 1 )
#define EMAC_RW_REG     ( NET__USER__ + 2 )
#define PHY_RW_REG      ( NET__USER__ + 3 )
#define NET_SEND_PACKET    ( NET__USER__ + 4 )
#define NET_SEND_RETURN    ( NET__USER__ + 5 )


struct dev_reg
{
    uint32  device;
    uint32  reg;
    uint32  value;
};

extern int32   drv_eth6457_plug( const char* path, net_config& cfg, uint32 rxd_count, uint32 txd_count );
extern int32   drv_eth6457_unplug( const char* name );

#endif

