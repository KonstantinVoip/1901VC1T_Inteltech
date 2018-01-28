// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: all
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp866
// !: d: ����� ᮤ�ন� �������� � ���⨯� �㭪権 �������� ���७��
// !: d: �� ����樮���� ��⥬�.
// !: -:
// ---------------------------------------------------------------------------
#ifndef __OS_Extension_Manager_H__
#define __OS_Extension_Manager_H__

#include <os_types.h>

// -- Constants --------------------------------------------------------------

#define EXT_DYNAMIC             0xffffffff

#define EXT_F_STATIC            0x00000001      // Extension can not be unloaded

// -- Structures -------------------------------------------------------------

// ---------------------------------------------------------------------------
// !: sn: s_os_extension_f
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sd: ������� ��� ॣ����樨 �㭪樨 � ��⥬�.
// !: sc: const char*, f_name
// !: cd: 㪠��⥫� �� ��ப� � ������ �㭪樨 (����� ���� NULL, � ��砥 �᫨
// !: cd: f_syscall_index �� ࠢ�� EXT_DYNAMIC)
// !: sc: uint32, f_syscall_index
// !: cd: ������ �㭪樨 � syscall ⠡��� (�᫨ ࠢ�� EXT_DYNAMIC �㭪��
// !: cd: ॣ��������� �� �� ����� � ������ ����� �� �㫥��� ��㬥�� f_name)
// !: sc: uint32, f_ptr
// !: cd: 㪠��⥫� �� �㭪��
// !: -:
// ---------------------------------------------------------------------------
struct s_os_extension_f
{
  const char*                   f_name;
  uint32                        f_syscall_index;
  uint32                        f_ptr;
};

struct s_os_extension
{
  s_os_extension*               next;                   // Next extension in list
  s_os_extension*               prev;                   // Previouse extension in list
  const char*                   name;                   // Extension name
  uint32                        f_count;                // Function count in extension packet
  s_os_extension_f*             f_tab;                  // Function table
  uint32                        usage;                  // Count of processes useing this extension
  uint64                        lacc;                   // Time of last access to extension
  uint32                        flags;                  // Flags
  uint16                        own_process;            // Owner
};

struct s_os_extension_link
{
  s_os_extension_link*          prev;
  s_os_extension_link*          next;
  s_os_extension*               e;
};

// -- Module functions -------------------------------------------------------

extern void                     os_extension_init_module();
extern void                     os_extension_cleanup();

extern int32                    os_extension_plug( s_os_extension* e );
extern int32                    os_extension_unplug( s_os_extension* e );
extern int32                    os_extension_load( const char* name );
extern int32                    os_extension_unload( const char* name );
extern void*                    os_extension_symbol( const char* name );

#endif
