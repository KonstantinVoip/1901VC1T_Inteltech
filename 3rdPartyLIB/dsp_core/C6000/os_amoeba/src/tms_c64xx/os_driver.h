// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: all
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp866
// !: d: Модуль содержит описание структур данных, необходимых для работы с
// !: d: менеджером драйверов.
// !: -:
// ---------------------------------------------------------------------------
#ifndef __OS_Driver_Manager_H__
#define __OS_Driver_Manager_H__

#include <os_types.h>

// read         [r]
// write        [w]
// open         [r] | [w] | [rw]
// close        
// create
// remove       [w]
// seek         [w]
// size         [r]
// position     [r]
// select       [x]
// list         [r]
// ioctl        [rw]
// getaccl      [r]
// setaccl      [w]
// resize       [w]
// rename

// -- Access macroses --------------------------------------------------------

#define ACC_RD                  0x00000001
#define ACC_WR                  0x00000002
#define ACC_EXEC                0x00000004

#define ACC_RW                  ( ACC_RD | ACC_WR )
#define ACC_FULL                ( ACC_RD | ACC_WR | ACC_EXEC )

#define ACC_OTHER( a )          ( ( (uint32)(a) << 0 ) & 0x00000007 )
#define ACC_USER( a )           ( ( (uint32)(a) << 3 ) & 0x00000038 )
#define ACC_GROUP( a )          ( ( (uint32)(a) << 6 ) & 0x000001c0 )

#define ACC_DIR                 0x00000200
#define ACC_SUID                0x00000400
#define ACC_SGID                0x00000800

#define ACC_FULL_FOLDER         ( ACC_OTHER( ACC_FULL ) | ACC_USER( ACC_FULL ) | ACC_GROUP( ACC_FULL ) | ACC_DIR )
#define ACC_FULL_FILE           ( ACC_OTHER( ACC_RW ) | ACC_USER( ACC_RW ) | ACC_GROUP( ACC_RW ) )

// -- Stream access mode codes -----------------------------------------------

#define DRV_OPENED              0x0001
#define DRV_WR                  0x0002
#define DRV_RD                  0x0004
#define DRV_EXCLUSIVE           0x0008

// -- Standard index node types ----------------------------------------------

#define INOT_FILE               0x01
#define INOT_FOLDER             0x02
#define INOT_SYMLINK            0x40
#define INOT_MOUNT_POINT        0x80

// -- Structures -------------------------------------------------------------

#define DRV_F_INFS              0x0001
#define DRV_F_UNLOADING         0x0002

/*
  --> new <--

  struct s_function_context
  {
    int32                       (*init)                 ( s_driver_context* c );
    int32                       (*deinit)               ( s_driver_context* c );

    int32                       (*d_init)               ( s_driver_descriptor* d );
    int32                       (*d_deinit)             ( s_driver_descriptor* d );

    int32                       (*stream_open)          ( s_driver_descriptor* d, uint32 access );
    int32                       (*stream_close)         ( s_driver_descriptor* d );
    int32                       (*stream_read)          ( s_driver_descriptor* d, void* buffer, int32 length );
    int32                       (*stream_write)         ( s_driver_descriptor* d, const void* buffer, int32 length );
    int32                       (*stream_seek)          ( s_driver_descriptor* d, int32 whence, int64 position );
    int32                       (*stream_size)          ( s_driver_descriptor* d, int64* size );
    int32                       (*stream_position)      ( s_driver_descriptor* d, int64* position );
    int32                       (*stream_resize)        ( s_driver_descriptor* d, int64 position );

    int32                       (*inode_select)         ( s_driver_descriptor* d, const char* name )
    int32                       (*inode_create)         ( s_driver_descriptor* d, const char* name );
    int32                       (*inode_remove)         ( s_driver_descriptor* d, const char* name );
    int32                       (*inode_rename)         ( s_driver_descriptor* d, const char* src_name, const char* dst_name );
    int32                       (*inode_list)           ( s_driver_descriptor* d, s_inode** list );
    
    int32                       (*secure_get)           ( s_driver_descriptor* d, s_secure_object* label );
    int32                       (*secure_set)           ( s_driver_descriptor* d, uint32 mask, s_secure_object* label );

    int32                       (*ioctl)                ( s_driver_descriptor* d, int32 cmd, const void* arg );
  };

  struct s_driver_context
  {
    s_driver_context*           next;
    s_driver_context*           prev;

    char*                       name;
    char*                       root;
    s_function_context          f;
    s_process_context*          master;

    int32                       inactive;
    uint32                      data_length;
    void*                       data;
  };

  struct s_driver_descriptor
  {
    s_driver_context*           driver;
    s_process_context*          master;
    uint32                      sem;

    uint32                      access;
    char*                       path;
    uint32                      data_length;
    void*                       data;
  };

*/

struct s_os_driver_descriptor;

struct s_os_driver_context
{
  s_os_driver_context*          prev;
  s_os_driver_context*          next;
  int32                         (*open)( s_os_driver_descriptor* d, uint16 access );
  int32                         (*close)( s_os_driver_descriptor* d );
  int32                         (*read)( s_os_driver_descriptor* d, void* buf, int32 length );
  int32                         (*write)( s_os_driver_descriptor* d, const void* buf, int32 length );
  int32                         (*ioctl)( s_os_driver_descriptor* d, int32 cmd, const void* arg );
  uint16                        own_process;
  char*                         name;
  char*                         path;
  void*                         data;
  uint16                        flags;
};

struct s_os_driver_descriptor
{
  uint32                        id;
  s_os_driver_context*          ctx;
  uint16                        own_process;
  uint16                        access;
  char*                         path;
  void*                         data;
  uint32                        sem;
};

struct s_inode
{
  s_inode*                      prev;
  s_inode*                      next;
  char*                         name;
  uint64                        size;
  uint32                        mktime;
  uint16                        own_user;
  uint16                        own_group;
  uint32                        access;
  uint8                         type;
};

struct s_inode_create
{
  const char*                   name;
  uint8                         type;
};

// -- Standard interface realisation -----------------------------------------

extern s_os_driver_descriptor** v_os_desc_list;

extern void                     os_driver_init_module();
extern void                     os_driver_cleanup();
extern uint32                   os_driver_descriptor_check( uint32 rid );

extern int32                    os_driver_plug( const char* path, uint8 type, int32 (*open_func)( s_os_driver_descriptor*, uint16 ), int32 (*close_func)( s_os_driver_descriptor* ), int32 (*read_func)( s_os_driver_descriptor*, void*, int32 ), int32 (*write_func)( s_os_driver_descriptor*, const void*, int32 ), int32 (*ioctl_func)( s_os_driver_descriptor*, int32, const void* ), void* data, int32 datalen );
extern int32                    os_driver_unplug( const char* name );
extern uint32                   os_driver_mkd( const char* path );
extern int32                    os_driver_rmd( uint32 rid );
extern int32                    os_driver_open( uint32 rid, uint16 access );
extern int32                    os_driver_close( uint32 rid );
extern int32                    os_driver_read( uint32 rid, void* buf, int32 length );
extern int32                    os_driver_write( uint32 rid, const void* buf, int32 length );
extern int32                    os_driver_ioctl( uint32 rid, int32 cmd, const void* arg );
extern int32                    os_driver_select( uint32 rid, const char* name );
extern int32                    os_driver_create( uint32 rid, const char* name, uint8 type );
extern int32                    os_driver_remove( uint32 rid, const char* name );
extern int32                    os_driver_rename( uint32 rid, const char* name );
extern bool                     os_driver_inc_path( s_os_driver_descriptor* d, const char* name );
extern bool                     os_driver_dec_path( s_os_driver_descriptor* d );
extern void                     os_driver_return_to_rfs( s_os_driver_descriptor* d );
extern void                     os_driver_list_destroy( s_inode* first );
extern int32                    os_driver_list( uint32 rid, s_inode** list );

#endif
