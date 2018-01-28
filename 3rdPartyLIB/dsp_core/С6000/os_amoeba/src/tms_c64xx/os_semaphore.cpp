// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp866
// !: d: Модуль содержит реализацию менеджера семафоров.
// !: -:
// ---------------------------------------------------------------------------
#define SYSCALL_DIRECT
#include <os.h>
// ---------------------------------------------------------------------------

uint32 v_os_semaphore_list_length;
s_os_semaphore** v_os_semaphore_list;

// ---------------------------------------------------------------------------
// !: fn: void os_semaphore_init_module()
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция инициализирует менеджер семафоров. Функция системная и не
// !: d: доступна пользователю.
// ---------------------------------------------------------------------------
void os_semaphore_init_module( int32 stage )
{
  uint32 l;

  // Allocate memory for some count of semaphores
  v_os_semaphore_list_length = core_init_cfg.sem_list_len;
  l = sizeof(s_os_semaphore*) * v_os_semaphore_list_length;
  v_os_semaphore_list = (s_os_semaphore**)heap_alloc( NULL, l, HEAP_ALIGN_4 );
  if( v_os_semaphore_list == NULL )
  {
    // Startup error
    while( true )
      asm( " nop " );
  }
  // Initialize resource
  memset( v_os_semaphore_list, 0, l );
}
// ---------------------------------------------------------------------------
// !: fn: uint32 os_semaphore_check( uint32 rid )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция проверяет корректность идентификатора ресурса семафоров rid.
// !: d: А так же права доступа к ресурсу. Функция системная и пользователю не
// !: d: доступна.<br>
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: Функция возвращает номер семафора в системной таблице.
// ---------------------------------------------------------------------------
uint32 os_semaphore_check( uint32 rid )
{
  uint32 index = rid & RES_I_MASK;

  if( ( ( rid & RES_T_MASK ) != RES_T_SEMAPHORE ) || ( index >= v_os_semaphore_list_length ) )
  {
    os_sfault( OSSF_BAD_DESCRIPTOR );
    // No return from ^-- this point
  }

  s_os_semaphore* s = v_os_semaphore_list[index];

  if( s == NULL )
  {
    os_sfault( OSSF_BAD_DESCRIPTOR );
    // No return from ^-- this point
  }

  if( ( s->id & RES_F_SHARED ) == 0 )
  {
    if( s->own_process != v_os_current_process->id )
    {
      os_sfault( OSSF_PROTECTION_FAULT );
      // No return from ^-- this point
    }
  }

  return index;
}
// ---------------------------------------------------------------------------
// !: fn: void os_semaphore_cleanup()
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция освобождает все ресурсы (семафоры), которые были захвачены
// !: d: завершающимся процессом. Функция не доступна пользователю.
// ---------------------------------------------------------------------------
void os_semaphore_cleanup()
{
  register uint32 is = int_disable();

  for( uint32 i = 0; i < v_os_semaphore_list_length; i++ )
  {
    if( v_os_semaphore_list[i] == NULL ) continue;
    if( v_os_semaphore_list[i]->own_process == v_os_current_process->id )
    {
      os_semaphore_free( v_os_semaphore_list[i]->id );
    }
  }
  
  int_enable( is );
}
// ---------------------------------------------------------------------------
// !: fn: uint32 os_semaphore_alloc( int32 value, const char* name )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall псевдоним:</b><br>
// !: d: <br>
// !: d: sem_alloc<br>
// !: d: <br>
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция создает семафор с уникальным именем name и инициализирует его
// !: d: значением value. Параметр name может быть равен NULL, в этом случае
// !: d: создается не именованный семафор. После завершения работы с семафором
// !: d: процесс должен его удалить, используя функцию sem_free.<br>
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: В случае успешного завершения функция возвращает идентификатор
// !: d: ресурса, иначе RES_VOID.
// ---------------------------------------------------------------------------
uint32 os_semaphore_alloc( int32 value, const char* name )
{
  uint32 i, l;
  uint32 si = 0;
  uint32 rid = RES_VOID;
  s_os_semaphore** nlist;
  register uint32 is;
  char* nname;

  if( name )
  {
    nname = (char*)heap_alloc( NULL, strlen( name ) + 1, HEAP_ALIGN_4 );
    if( nname == NULL ) return RES_VOID;
  }
  else
  {
    nname = NULL;
  }

  is = int_disable();

  if( name )
  {
    for( i = si; i < v_os_semaphore_list_length; i++ )
    {
      if( v_os_semaphore_list[i] == NULL ) continue;
      if( v_os_semaphore_list[i]->name == NULL ) continue;
      if( strcmp( name, v_os_semaphore_list[i]->name ) == 0 )
      {
        int_enable( is );
        heap_free( NULL, nname );
        return RES_VOID;
      }
    }
  }

l_retry:

  for( i = si; i < v_os_semaphore_list_length; i++ )
  {
    if( v_os_semaphore_list[i] == NULL )
    {
      s_os_semaphore* s = (s_os_semaphore*)heap_alloc( NULL, sizeof(s_os_semaphore), HEAP_ALIGN_4 );
      if( s == NULL )
      {
        int_enable( is );
        heap_free( NULL, nname );
        return RES_VOID;
      }
      s->first = NULL;
      s->id = RES_T_SEMAPHORE | RES_F_USED | RES_F_SHARED | i;
      s->v = value;
      s->w = 0;
      s->own_process = ( v_os_core_call ) ? 0 : v_os_current_process->id;
      s->name = nname;
      if(nname != NULL)
        strcpy( nname, name );
      v_os_semaphore_list[i] = s;
      rid = s->id;
      break;
    }
  }
  if( i == v_os_semaphore_list_length )
  {
    si = v_os_semaphore_list_length << 1;
    if( nlist = (s_os_semaphore**)heap_alloc( NULL, sizeof(s_os_semaphore*) * si, HEAP_ALIGN_4 ) )
    {
      l = sizeof(s_os_semaphore*) * v_os_semaphore_list_length;
      memcpy( nlist, v_os_semaphore_list, l );
      memset( (char*)nlist + l, 0, l );
      i = v_os_semaphore_list_length;
      v_os_semaphore_list_length = si;
      si = i;
      heap_free( NULL, v_os_semaphore_list );
      v_os_semaphore_list = nlist;
      goto l_retry;
    }
  }

  int_enable( is );
  if( rid == RES_VOID ) heap_free( NULL, nname );

  return rid;
}
// ---------------------------------------------------------------------------
// !: fn: uint32 os_semaphore_open( const char* name )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall псевдоним:</b><br>
// !: d: <br>
// !: d: sem_open<br>
// !: d: <br>
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция открывает для доступа семафор с именем name.<br>
// !: d: <br>
// !: d: <b>Примечание:</b><br>
// !: d: <br>
// !: d: Получив идентификатор доступа, процесс не должн пытаться его
// !: d: освободить с помощью функции sem_free. Удалять семафор должен
// !: d: процесс-владелец.<br>
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: Функция возвращает идентификатор ресурса, если семафор с именем name
// !: d: существует в системе, иначе возвращается RES_VOID.
// ---------------------------------------------------------------------------
uint32 os_semaphore_open( const char* name )
{
  uint32 rid = RES_VOID;
  register uint32 is;

  is = int_disable();

  for( uint32 i = 0; i < v_os_semaphore_list_length; i++ )
  {
    s_os_semaphore* s = v_os_semaphore_list[i];
    if( s == NULL ) continue;
    if( s->name == NULL ) continue;
    if( strcmp( s->name, name ) != 0 ) continue;
    rid = s->id;
    break;
  }

  int_enable( is );

  return rid;
}

uint32 os_semaphore_free( uint32 rid )
{
  uint32 i, index;
  register uint32 is;

  if( rid == RES_VOID ) return SEM_VOID_RESOURCE;
  
  is = int_disable();

  if( ( index = os_semaphore_check( rid ) ) == 0xffffffff )
  {
    int_enable( is );
    return SEM_NOT_REGISTERED;
  }

  s_os_process_context* cprc = v_os_process_ring;
  for( i = 0; i < v_os_process_count; i++, cprc = cprc->next )
  {
    if( cprc->locker.s == RES_VOID ) continue;
    if( ( cprc->locker.s & RES_I_MASK ) == index ) cprc->locker.state = OSE_SEM_DESTROYED;
  }

  heap_free( NULL, v_os_semaphore_list[index] );
  v_os_semaphore_list[index] = NULL;

  int_enable( is );
  
  return SEM_OK;
}
// ---------------------------------------------------------------------------
// !: fn: uint32 os_semaphore_reset( uint32 rid, int32 value )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall псевдоним:</b><br>
// !: d: <br>
// !: d: sem_reset<br>
// !: d: <br>
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция устанавливает значение семафора, на который ссылается
// !: d: идентификатор ресурса rid, в значение value.<br>
// !: d: <br>
// !: d: <b>Примечание:</b><br>
// !: d: <br>
// !: d: Использвание данной функции может повлиять на корректность работы
// !: d: синхронизируемых процессов. Использовать данную функцию нужно
// !: d: крайне осторожно!<br>
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: В случае успеха функция возвращает SEM_OK, иначе одну из ошибок:<br><br>
// !: d: <table cellpadding=2 cellspacing=2 border=0>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>SEM_VOID_RESOURCE</td>
// !: d: <td> - </td>
// !: d: <td>идентификатор ресурса rid равен RES_VOID;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>SEM_NOT_REGISTERED</td>
// !: d: <td> - </td>
// !: d: <td>семафор с таким идентификатором не зарегистрирован в системе (возможно был удален владельцем).</td>
// !: d: </tr>
// !: d: </table><br>
// ---------------------------------------------------------------------------
uint32 os_semaphore_reset( uint32 rid, int32 value )
{
  uint32 index;
  register uint32 is;

  if( rid == RES_VOID ) return SEM_VOID_RESOURCE;

  is = int_disable();

  if( ( index = os_semaphore_check( rid ) ) == 0xffffffff )
  {
    int_enable( is );
    return SEM_NOT_REGISTERED;
  }

  v_os_semaphore_list[index]->v = value;

  int_enable( is );
  
  return SEM_OK;
}
// ---------------------------------------------------------------------------
// !: fn: uint32 os_semaphore_lock( uint32 rid, uint32 tmo )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall псевдоним:</b><br>
// !: d: <br>
// !: d: sem_lock<br>
// !: d: <br>
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция осуществляет захват семафора, на который ссылается
// !: d: идентификатор ресурса rid. Переменная tmo указывает максимальное
// !: d: количество милисекунд, которое процесс будет находиться в состоянии
// !: d: ожидания исполнения, дожидаясь получения контроля над семафором.
// !: d: Значение SEM_INFINITY заставляет процесс ожидать вечно.
// !: d: При успешном захвате, значение семафора декриментируется. Так же,
// !: d: если при захвате значение семафора было меньше или равно 0, процесс,
// !: d: осуществляющий захват, блокируется.<br>
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: В случае успеха функуия возвращает SEM_OK, иначе одну из ошибок:<br><br>
// !: d: <table cellpadding=2 cellspacing=2 border=0>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>SEM_VOID_RESOURCE</td>
// !: d: <td> - </td>
// !: d: <td>идентификатор ресурса rid равен RES_VOID;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>SEM_NOT_REGISTERED</td>
// !: d: <td> - </td>
// !: d: <td>семафор с таким идентификатором не зарегистрирован в системе (возможно был удален владельцем);</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>SEM_DESTROYED</td>
// !: d: <td> - </td>
// !: d: <td>процесс-владелец удалил семафор (необходимо прекратить использование данного семафора);</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>SEM_TIMEOUT</td>
// !: d: <td> - </td>
// !: d: <td>истекло время ожидания семафора (захват семафора не был произведен).</td>
// !: d: </tr>
// !: d: </table><br>
// ---------------------------------------------------------------------------
uint32 os_semaphore_lock( uint32 rid, uint32 tmo )
{
  uint32 index;
  s_os_semaphore* s;
  register uint32 is;

  if( rid == RES_VOID ) return SEM_VOID_RESOURCE;

  is = int_disable();

  if( ( index = os_semaphore_check( rid ) ) == 0xffffffff )
  {
    int_enable( is );
    return SEM_NOT_REGISTERED;
  }

  s = v_os_semaphore_list[index];

  s->v--;
  if( s->v < 0 )
  {
    if( tmo == 0 )
    {
      s->v++;
      int_enable( is );
      return SEM_TIMEOUT;
    }
    v_os_current_process->locker.unlock_at = ( tmo == SEM_INFINITY ) ? 0ull : ( os_time_core_n() + (uint64)tmo * 1000000ull );
    v_os_current_process->locker.s = rid;
    v_os_current_process->locker.state = SEM_OK;
    if( s->first == NULL )
    {
      s->first = &v_os_current_process->locker;
    }
    else
    {
      s_os_locker* clocker = s->first;
      while( true )
      {
        if( clocker->next == NULL )
        {
          clocker->next = &v_os_current_process->locker;
          clocker->next->prev = clocker;
          break;
        }
        clocker = clocker->next;
      }
    }
    s->w--;
    int_enable( is );
    prc_yield();

    return v_os_current_process->locker.state;
  }

  int_enable( is );

  return SEM_OK;
}
// ---------------------------------------------------------------------------
// !: fn: uint32 os_semaphore_unlock( uint32 rid )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall псевдоним:</b><br>
// !: d: <br>
// !: d: sem_unlock<br>
// !: d: <br>
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция инкрементирует значение семафора, на который ссылается
// !: d: идентификатор ресурса rid. Если в очереди на захват семафора есть
// !: d: процессы, управление получит первый в очереди (в порядке вызова
// !: d: функции sem_lock и в соответствии с приоритетом исполнения).<br>
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: В случае успеха функция возвращает SEM_OK, иначе одну из ошибок:<br><br>
// !: d: <table cellpadding=2 cellspacing=2 border=0>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>SEM_VOID_RESOURCE</td>
// !: d: <td> - </td>
// !: d: <td>идентификатор ресурса rid равен RES_VOID;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>SEM_NOT_REGISTERED</td>
// !: d: <td> - </td>
// !: d: <td>семафор с таким идентификатором не зарегистрирован в системе (возможно был удален владельцем).</td>
// !: d: </tr>
// !: d: </table><br>
// ---------------------------------------------------------------------------
uint32 os_semaphore_unlock( uint32 rid )
{
  uint32 index;
  register uint32 is;

  if( rid == RES_VOID ) return SEM_VOID_RESOURCE;

  is = int_disable();

  if( ( index = os_semaphore_check( rid ) ) == 0xffffffff )
  {
    int_enable( is );
    return SEM_NOT_REGISTERED;
  }

  v_os_semaphore_list[index]->v++;

  int_enable( is );

  return SEM_OK;
}
// ---------------------------------------------------------------------------
// !: fn: uint32 os_semaphore_unlock_sw( uint32 rid )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall псевдоним:</b><br>
// !: d: <br>
// !: d: sem_unlock_sw<br>
// !: d: <br>
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Вызов данной функции эквивалентен вызову функции sem_unlock, за тем
// !: d: исключением, что если в очереди на захват семыфора есть хотя бы один
// !: d: процесс, он получит управление моментально после разблокировки
// !: d: семафора, игнорируя приоритеты других процессов.<br>
// !: d: <br>
// !: d: <b>Примечание:</b><br>
// !: d: <br>
// !: d: Данную функцию имеет смысл использовать только тогда, когда требуется
// !: d: наискорейшая реакция на разблокировку семафора. Например, можно
// !: d: разблокировать процесс, ожидающий события от периферийного устройства
// !: d: по прерыванию.<br>
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: В случае успеха функция возвращает SEM_OK, иначе одину из ошибок:<br><br>
// !: d: <table cellpadding=2 cellspacing=2 border=0>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>SEM_VOID_RESOURCE</td>
// !: d: <td> - </td>
// !: d: <td>идентификатор ресурса rid равен RES_VOID;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>SEM_NOT_REGISTERED</td>
// !: d: <td> - </td>
// !: d: <td>семафор с таким идентификатором не зарегистрирован в системе (возможно был удален владельцем).</td>
// !: d: </tr>
// !: d: </table><br>
// ---------------------------------------------------------------------------
uint32 os_semaphore_unlock_sw( uint32 rid )
{
  uint16 lprc = 0;
  uint32 index;
  s_os_semaphore* s;
  register uint32 is;

  if( rid == RES_VOID ) return SEM_VOID_RESOURCE;

  is = int_disable();

  if( ( index = os_semaphore_check( rid ) ) == 0xffffffff )
  {
    int_enable( is );
    return SEM_NOT_REGISTERED;
  }

  s = v_os_semaphore_list[index];
  if( s->first ) lprc = s->first->p->id;
  s->v++;

  if( lprc )
  {
    v_os_swto_pid = lprc;
    int_enable( is );
    if( is )
    {
      prc_yield();
    }
    else
    {
      #if defined(CHIP_6412) || defined(CHIP_6416)
      REG_CNT0 = sys_quant - 1;
      #endif
      #if defined(CHIP_6457)
      REG_CNTLO0 = sys_quant - 1;
      #endif
    }
  }
  else
  {
    int_enable( is );
  }
  
  return SEM_OK;
}
// ---------------------------------------------------------------------------
// !: fn: uint32 os_semaphore_lockunlock( uint32 rid_lock, uint32 rid_unlock, uint32 tmo )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall псевдоним:</b><br>
// !: d: <br>
// !: d: sem_lockunlock<br>
// !: d: <br>
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Вызов данной функции эквиваленте атамарному вызову функции sem_unlock
// !: d: с аргументом rid_unlock, а затем вызову sem_lock с аргументами
// !: d: rid_lock и tmo.<br>
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: В случае успеха функуия возвращает SEM_OK, иначе одну из ошибок:<br><br>
// !: d: <table cellpadding=2 cellspacing=2 border=0>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>SEM_VOID_RESOURCE</td>
// !: d: <td> - </td>
// !: d: <td>идентификатор ресурса rid_lock или rid_unlock равен RES_VOID;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>SEM_NOT_REGISTERED</td>
// !: d: <td> - </td>
// !: d: <td>один из семафоров с не зарегистрирован в системе (возможно был удален владельцем);</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>SEM_DESTROYED</td>
// !: d: <td> - </td>
// !: d: <td>процесс-владелец удалил семафор rid_lock (необходимо прекратить использование данного семафора);</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>SEM_TIMEOUT</td>
// !: d: <td> - </td>
// !: d: <td>истекло время ожидания семафора rid_lock (захват семафора не был произведен).</td>
// !: d: </tr>
// !: d: </table><br>
// ---------------------------------------------------------------------------
uint32 os_semaphore_lockunlock( uint32 rid_lock, uint32 rid_unlock, uint32 tmo )
{
  uint32 index_lock, index_unlock;
  s_os_semaphore* s;
  register uint32 is;

  if( ( rid_lock == RES_VOID ) || ( rid_unlock == RES_VOID ) ) return SEM_VOID_RESOURCE;

  is = int_disable();

  if( ( index_lock = os_semaphore_check( rid_lock ) ) == 0xffffffff )
  {
    int_enable( is );
    return SEM_NOT_REGISTERED;
  }
  if( ( index_unlock = os_semaphore_check( rid_unlock ) ) == 0xffffffff )
  {
    int_enable( is );
    return SEM_NOT_REGISTERED;
  }

  v_os_semaphore_list[index_unlock]->v++;

  s = v_os_semaphore_list[index_lock];

  s->v--;
  if( s->v < 0 )
  {
    if( tmo == 0 )
    {
      s->v++;
      int_enable( is );
      return SEM_TIMEOUT;
    }
    v_os_current_process->locker.unlock_at = ( tmo == SEM_INFINITY ) ? 0ull : ( os_time_core_n() + (uint64)tmo * 1000000ull );
    v_os_current_process->locker.s = rid_lock;
    v_os_current_process->locker.state = SEM_OK;
    if( s->first == NULL )
    {
      s->first = &v_os_current_process->locker;
    }
    else
    {
      s_os_locker* clocker = s->first;
      while( true )
      {
        if( clocker->next == NULL )
        {
          clocker->next = &v_os_current_process->locker;
          clocker->next->prev = clocker;
          break;
        }
        clocker = clocker->next;
      }
    }
    s->w--;
    int_enable( is );
    prc_yield();

    return v_os_current_process->locker.state;
  }

  int_enable( is );

  return SEM_OK;
}
// ---------------------------------------------------------------------------
// !: fn: uint32 os_semaphore_locked( uint32 rid )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall псевдоним:</b><br>
// !: d: <br>
// !: d: sem_locked<br>
// !: d: <br>
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция проверяет состояние семафора.<br>
// !: d: <br>
// !: d: <b>Примечание:</b><br>
// !: d: <br>
// !: d: Состояние семафора фиксируется на момент вызова функции и после выхода
// !: d: уже не является достоверным.<br>
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: В случае если семафор находится в заблокированном состоянии (иначе
// !: d: говоря, вызов функции sem_lock переведет процесс в состояние ожидания
// !: d: исполнения) функция вернет SEM_LOCKED. Значение SEM_UNLOCKED
// !: d: будет возвращено в случае когда семафор разблокирован, или не
// !: d: существует, или идентификатор ресурса rid равен RES_VOID.
// ---------------------------------------------------------------------------
uint32 os_semaphore_locked( uint32 rid )
{
  uint32 index;
  bool r;
  register uint32 is;

  if( rid == RES_VOID ) return SEM_UNLOCKED;

  is = int_disable();

  if( ( index = os_semaphore_check( rid ) ) == 0xffffffff )
  {
    int_enable( is );
    return SEM_UNLOCKED;
  }
  
  r = v_os_semaphore_list[index]->v <= v_os_semaphore_list[index]->w;
  
  int_enable( is );
  
  return ( r ? SEM_LOCKED : SEM_UNLOCKED );
}
// ---------------------------------------------------------------------------
// !: fn: uint32 os_semaphore_value( uint32 rid, int32* v )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall псевдоним:</b><br>
// !: d: <br>
// !: d: sem_value<br>
// !: d: <br>
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция запрашивает значение семафора, на который ссылается
// !: d: идентификатор ресурса rid.<br>
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: В случае успеха функция присвоит переменной на которую указывает v
// !: d: значение семафора и вернет SEM_OK, иначе функция вернет одну из ошибок:<br><br>
// !: d: <table cellpadding=2 cellspacing=2 border=0>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>SEM_VOID_RESOURCE</td>
// !: d: <td> - </td>
// !: d: <td>идентификатор ресурса rid равен RES_VOID;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>SEM_NOT_REGISTERED</td>
// !: d: <td> - </td>
// !: d: <td>семафор с таким идентификатором не зарегистрирован в системе (возможно был удален владельцем);</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>SEM_NULL_PARAM</td>
// !: d: <td> - </td>
// !: d: <td>указатель v равен нулю.</td>
// !: d: </tr>
// !: d: </table><br>
// ---------------------------------------------------------------------------
uint32 os_semaphore_value( uint32 rid, int32* v )
{
  uint32 index;
  register uint32 is;

  if( rid == RES_VOID ) return SEM_VOID_RESOURCE;
  if( v == NULL ) return SEM_NULL_PARAM;

  is = int_disable();

  if( ( index = os_semaphore_check( rid ) ) == 0xffffffff )
  {
    int_enable( is );
    return SEM_UNLOCKED;
  }

  (*v) = v_os_semaphore_list[index]->v;
  
  int_enable( is );

  return SEM_OK;
}
// ---------------------------------------------------------------------------
