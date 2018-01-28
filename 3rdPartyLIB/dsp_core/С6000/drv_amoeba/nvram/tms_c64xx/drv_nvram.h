// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: all
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp1251
// !: d: .
// !: -: 
// ---------------------------------------------------------------------------
#include <os_types.h>

#define NVRAM_START_ADDR    0x68000000  // Начальный адрес NVRAM
#define NVRAM_SIZE          0x00100000  // Размер NVRAM в байтах. 0x00100000 = 1MB

extern int32   drv_nvram_plug( const char* path );
extern int32   drv_nvram_unplug( const char* name );


