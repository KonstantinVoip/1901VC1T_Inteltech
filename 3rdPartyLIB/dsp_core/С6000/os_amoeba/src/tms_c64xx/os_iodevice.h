// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: all
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp866
// !: d:
// !: -:
// ---------------------------------------------------------------------------
#ifndef __OS_Console_H__
#define __OS_Console_H__

#include <os_types.h>

// -- Error codes ------------------------------------------------------------

#define IOD_OK                          0
#define IOD_ER_CANT_OPEN_DEVICE         -1
#define IOD_ER_NULL_PARAM               -2
#define IOD_ER_NO_MEM                   -3
#define IOD_ER_BAD_TYPE                 -4
#define IOD_ER_NO_DEVICE                -5

// -- Definitions ------------------------------------------------------------

#define IODT_INPUT              0
#define IODT_OUTPUT             1

// -- Structures -------------------------------------------------------------

struct s_os_console
{
  s_os_console*                 next;
  s_os_console*                 prev;
  char*                         path;
};

struct s_os_iodevice
{
  s_os_iodevice*                next;
  s_os_iodevice*                prev;
  uint32                        con_count;
  s_os_console*                 active;
  char*                         path;
};

// -- Functions --------------------------------------------------------------

extern void                     os_iodevice_init_module();
extern void                     os_iodevice_cleanup();

extern int32                    os_iodevice_reg( const char* dev, uint32 type );
extern int32                    os_iodevice_unreg( const char* dev, uint32 type );
extern int32                    os_idev_select( const char* con, const char* dev );
extern int32                    os_idev_switch( int32 cnum );
extern int32                    os_odev_select( const char* con, const char* dev );

#endif
