// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp866
// !: d: Модуль содержит прототипы функций менеджера семафоров.
// !: -:
// ---------------------------------------------------------------------------
#ifndef __OS_Semaphore_H__
#define __OS_Semaphore_H__

#include <os_types.h>
#include <os_error.h>

// -- Constants --------------------------------------------------------------

#define SEM_INFINITY            0xffffffff

#define SEM_NULL_PARAM          ((uint32)OSE_NULL_PARAM)
#define SEM_VOID_RESOURCE       ((uint32)OSE_VOID_RESOURCE)
#define SEM_DESTROYED           ((uint32)OSE_SEM_DESTROYED)
#define SEM_NOT_REGISTERED      ((uint32)OSE_SEM_NOT_REGISTERED)
#define SEM_OK                  OSE_OK
#define SEM_FAIL                ((uint32)OSE_FAIL)
#define SEM_TIMEOUT             ((uint32)OSE_TIMEOUT)
#define SEM_LOCKED              ((uint32)OSE_SEM_LOCKED)
#define SEM_UNLOCKED            ((uint32)OSE_SEM_UNLOCKED)

// -- Structures -------------------------------------------------------------

struct s_os_locker;

struct s_os_semaphore
{
  uint32                        id;             // Resource identificator
  char*                         name;           // Semaphore name
  int32                         v;              // Semaphore state
  int32                         w;              // Wait process count
  s_os_locker*                  first;          // Locked processes
  uint16                        own_process;    // Semaphore owner process
};

// -- Functions and Variables ------------------------------------------------

extern s_os_semaphore**         v_os_semaphore_list;
extern uint32                   v_os_semaphore_list_length;

extern void                     os_semaphore_init_module( int32 stage );
extern uint32                   os_semaphore_check( uint32 rid );
extern void                     os_semaphore_cleanup();

extern uint32                   os_semaphore_alloc( int32 value, const char* name );
extern uint32                   os_semaphore_open( const char* name );
extern uint32                   os_semaphore_free( uint32 rid );
extern uint32                   os_semaphore_reset( uint32 rid, int32 value );
extern uint32                   os_semaphore_lock( uint32 rid, uint32 tmo );
extern uint32                   os_semaphore_unlock( uint32 rid );
extern uint32                   os_semaphore_unlock_sw( uint32 rid );
extern uint32                   os_semaphore_lockunlock( uint32 rid_lock, uint32 rid_unlock, uint32 tmo );
extern uint32                   os_semaphore_locked( uint32 rid );
extern uint32                   os_semaphore_value( uint32 rid, int32* v );

#endif

/*

  new

//

struct s_semaphore
{
  uint32                        sem;
  s_accl_object                 acl;
  char*                         name;

  int32                         v;
  int32                         w;
  s_process_locker*             lprc;
};


extern uint32                   os_semaphore_alloc( int32 value, const char* name );
extern uint32                   os_semaphore_open( const char* name );
extern int32                    os_semaphore_free( uint32 rid );
extern int32                    os_semaphore_lock( uint32 rid, uint32 tmo );
extern int32                    os_semaphore_unlock( uint32 rid );
extern int32                    os_semaphore_unlock_sw( uint32 rid );
extern int32                    os_semaphore_lockunlock( uint32 rid_lock, uint32 rid_unlock, uint32 tmo );
extern int32                    os_semaphore_locked( uint32 rid );
extern int32                    os_semaphore_value( uint32 rid, int32* v );

*/
