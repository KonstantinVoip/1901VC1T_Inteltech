// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: all
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d:
// !: -:
// ---------------------------------------------------------------------------
#ifndef __Driver_Network_Virtual_Adapter_H__
#define __Driver_Network_Virtual_Adapter_H__

#include <net_struct.h>

extern int32 drv_vrnet_plug( const char* path, net_config& ncfg, uint32 rxdc, uint32 txdc );
extern int32 drv_vrnet_unplug( const char* name );

#endif
