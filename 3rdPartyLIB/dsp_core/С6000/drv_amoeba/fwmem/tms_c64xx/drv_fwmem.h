// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: all
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp866
// !: d:
// !: -: 
// ---------------------------------------------------------------------------
#ifndef __Firmware_Memory_Driver_H__
#define __Firmware_Memory_Driver_H__

#include <os_types.h>

// -- Error codes ------------------------------------------------------------

#define FWMEM_CANT_WRITE                -1024
#define FWMEM_CANT_ERASE_SECTOR         -1025
#define FWMEM_BYTE_ALLREADY_WRITED      -1026

// -- Structures -------------------------------------------------------------

struct s_fwmem_selector;

struct s_fwmem_context
{
  s_fwmem_selector*             wctx;
  uint32                        address;
  uint32                        arg0;
  uint32                        arg1;
  uint32                        sem;
};

struct s_fwmem_record
{
  uint32                        magic;
  uint32                        prev_shift;
  uint32                        next_shift;
  uint32                        length;
  uint32                        mktime;
  uint32                        access;
  uint16                        own_user;
  uint16                        own_group;
  uint32                        reserved_0;
  char                          name[32];
};

struct s_fwmem_sector_size
{
  uint32                        n;
  uint32                        size;
};

struct s_fwmem_selector
{
  int32                         (*init)( s_fwmem_context* ctx );
  int32                         (*deinit)( s_fwmem_context* ctx );
  int32                         (*sector_count)( s_fwmem_context* ctx, uint32* arg );
  int32                         (*sector_size)( s_fwmem_context* ctx, s_fwmem_sector_size* arg );
  int32                         (*sector_clear)( s_fwmem_context* ctx, uint32 sector );
  int32                         (*write_buffer)( s_fwmem_context* ctx, uint32 offset, void* data, uint32 length );
  int32                         (*read_buffer)( s_fwmem_context* ctx, uint32 offset, void* data, uint32 length );
  int32                         (*size)( s_fwmem_context* ctx, uint32* size );
};

struct s_fwmem_rwbuf
{
  void*                         buffer;
  uint32                        length;
};

// -- Driver functions -------------------------------------------------------

extern int32                    drv_fwmem_plug( const char* path, uint32 address, s_fwmem_selector* wctx );
extern int32                    drv_fwmem_unplug( const char* name );

// -- External lolevel functions ---------------------------------------------

extern s_fwmem_selector         fwmem_emulator;
extern s_fwmem_selector         fwmem_at49bv322d_plis;
extern s_fwmem_selector         fwmem_at49bv322d_gpio;
extern s_fwmem_selector         fwmem_s29al032dxxxxx04_gpio;
extern s_fwmem_selector         fwmem_s29al032dxxxxx04_gpio_sdctl;
extern s_fwmem_selector         fwmem_s29al032dxxxxx04_gpio_m632_comm;

// ---------------------------------------------------------------------------

#endif
