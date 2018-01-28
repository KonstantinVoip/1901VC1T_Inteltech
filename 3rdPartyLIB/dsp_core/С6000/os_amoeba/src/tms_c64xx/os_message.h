// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: all
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp866
// !: d: ����� ᮤ�ন� �������� ������ � ���⨯� �㭪権 ��������
// !: d: �⥬���� ������.
// !: -:
// ---------------------------------------------------------------------------
#ifndef __OS_Message_Manager_H__
#define __OS_Message_Manager_H__

#include <os_driver.h>

// ---------------------------------------------------------------------------

#define MFD_PID                 0x0000ffff
#define MFD_HID                 0x0fff0000

// ---------------------------------------------------------------------------

struct s_ipmp_stat
{
  uint64                        rx_count;
  uint64                        rx_bytes;
  uint64                        rx_drop;
  uint64                        rx_drop_mem;
  uint64                        rx_drop_hash;
  uint64                        tx_count;
  uint64                        tx_bytes;
};

// ---------------------------------------------------------------------------

struct s_message_link
{
  s_message_link*               next;
  s_message_link*               prev;
  uint32                        id;
  char                          name[24];
};

// ---------------------------------------------------------------------------
// !: sn: s_message
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sd: ������� ��⥬���� ᮮ�饭��.
// !: sc: s_message*, prev
// !: cd: 㪠��⥫� �� �।��饥 ᮮ�饭�� (� ��।�)
// !: sc: s_message*, next
// !: cd: 㪠��⥫� �� ᫥���饥 ᮮ�饭�� (� ��।�)
// !: sc: uint32, from
// !: cd: ���� ���筨�� ᮮ�饭��
// !: sc: uint32, to
// !: cd: ���� �����祭�� ᮮ�饭��
// !: sc: int32, length
// !: cd: ����� ������ ᮮ�饭��
// !: sc: void*, data
// !: cd: 㪠��⥫� �� ����� ᮮ�饭��
// ---------------------------------------------------------------------------

struct s_message_pipe;

struct s_message
{
  s_message*                    prev;
  s_message*                    next;
  s_message_pipe*               pipe;
  uint32                        from;
  uint32                        to;
  int32                         length;
  void*                         data;
};

// ---------------------------------------------------------------------------
// !: sn: s_message_queue
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sd: ������� ��।� ᮮ�饭��.
// !: sc: s_message*, first
// !: cd: 㪠��⥫� �� ��ࢮ� ᮮ�饭�� � ��।�
// !: sc: s_message*, last
// !: cd: 㪠��⥫� �� ��᫥���� ᮮ�饭�� � ��।�
// !: sc: uint32, sem
// !: cd: ᥬ��� ��� ᨭ�஭���樨 ����㯠 � ��।�
// !: sc: int32, count
// !: cd: ������⢮ ᮮ�饭�� � ��।�
// ---------------------------------------------------------------------------
struct s_message_queue
{
  s_message*                    first;
  s_message*                    last;
  uint32                        syn_sem;
  uint32                        count_sem;
};

struct s_message_pipe
{
  s_message_pipe*               next;
  s_message_pipe*               prev;
  s_message_link*               route;
  uint32                        route_count;
  uint32                        limit_sem;
  s_message_queue*              outq;
};

// ---------------------------------------------------------------------------
// !: sn: s_message_context
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sd: ������� ���⥪�� �ࠩ��� ��������୮�� ������.
// !: sc: s_message_queue*, inq
// !: cd: 㪠��⥫� �� ��।� �室��� ᮮ�饭�� (���樠��������� ��⥬��)
// !: sc: s_message_queue*, outq
// !: cd: 㪠��⥫� �� ��।� ��室��� ᮮ�饭�� (���樠��������� �ࠩ��஬)
// !: sc: s_message_pipe*, pipe
// !: cd: 㪠��⥫� �� ��⥬��� �������� ������ �裡 (���樠��������� ��⥬��)
// ---------------------------------------------------------------------------
struct s_message_context
{
  s_message_queue*              inq;
  s_message_queue*              outq;
  s_message_pipe*               pipe;
};

struct s_os_process_context;

struct s_message_process_data
{
  s_message_process_data*       prev;
  s_message_process_data*       next;
  s_os_process_context*         p;
  char*                         name;
  s_message_queue               inq;
  uint32                        avg_ppid;
  uint32                        avg_reqid;
};

extern void                     os_message_init_module();
extern void                     os_message_cleanup();
extern int32                    os_message_start( uint32 id, int32 limit );
extern int32                    os_message_end();

extern int32                    os_message_open( const char* name );
extern int32                    os_message_close();

extern uint32                   os_message_pid();
extern uint32                   os_message_discover( const char* hname, const char* pname, uint32 tm_m );
extern int32                    os_message_send( uint32 to, const void* data, int32 length );
extern int32                    os_message_have();
extern int32                    os_message_recv( s_message** m, uint32 tm_m );
extern int32                    os_message_free( s_message* msg );
extern s_message*               os_message_alloc( uint32 length, s_message_pipe* p );

extern int32                    os_message_queue_init( s_message_queue* q );
extern int32                    os_message_queue_push( s_message_queue* q, s_message* m );
extern int32                    os_message_queue_pop( s_message_queue* q, s_message** m, uint32 tm_m );
extern int32                    os_message_queue_deinit( s_message_queue* q );

extern int32                    os_message_regpipe( s_message_context* ctx, int32 limit );

#endif
