// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp866
// !: d: Модуль содержит реализацию менеджера прерываний.
// !: -:
// ---------------------------------------------------------------------------
#define SYSCALL_DIRECT
#include <os.h>
#if !defined(CHIP_6457)
#error This module can be compiled only for tms320c6457 processor (use CHIP_6457 define)!
#endif
// ---------------------------------------------------------------------------

uint32 v_os_interrupt_vector_01_NMI;
uint32 v_os_interrupt_vector_evt0;
uint32 v_os_interrupt_vector_evt1;
uint32 v_os_interrupt_vector_evt2;
uint32 v_os_interrupt_vector_evt3;
void (*interrupt_handler[124])();
s_os_interrupt v_os_interrupt_table[125];

static bool os_interrupt_map( uint32 vector, uint32 source );

// ---------------------------------------------------------------------------
static void os_interrupt_evt_disable_ll( uint32 event )
{
  register uint32 is = int_disable();
  REG_EVTMASK[event>>5] |= 1 << ( event & 31 );
  int_enable( is );
}
// ---------------------------------------------------------------------------
static void os_interrupt_evt_enable_ll( uint32 event )
{
  register uint32 is = int_disable();
  REG_EVTMASK[event>>5] &= ~( 1 << ( event & 31 ) );
  int_enable( is );
}
// ---------------------------------------------------------------------------
static void os_interrupt_evt_clear_ll( uint32 event )
{
  REG_EVTCLR[event>>5] = 1 << ( event & 31 );
}
// ---------------------------------------------------------------------------
static void os_interrupt_evt_set_ll( uint32 event )
{
  REG_EVTSET[event>>5] = 1 << ( event & 31 );
}
// ---------------------------------------------------------------------------
static void os_interrupt_evt0_handler()
{
  register uint32 mevtflag;
  register uint32 evt;
  register uint32 evt_index;
  register void (*handler)();

  while( mevtflag = REG_MEVTFLAG0 )
  {
    REG_EVTCLR0 = mevtflag;

    for( evt_index = 0, evt = 16; evt != 0; evt <<= 1, evt_index++ )
    {
      if( mevtflag & evt )
      {
        if( handler = interrupt_handler[evt_index] ) handler();
      }
    }
  }
}
// ---------------------------------------------------------------------------
static void os_interrupt_evt1_handler()
{
  register uint32 mevtflag;
  register uint32 evt;
  register uint32 evt_index;
  register void (*handler)();

  while( mevtflag = REG_MEVTFLAG1 )
  {
    REG_EVTCLR1 = mevtflag;

    for( evt_index = 28, evt = 1; evt != 0; evt <<= 1, evt_index++ )
    {
      if( mevtflag & evt )
      {
        if( handler = interrupt_handler[evt_index] ) handler();
      }
    }
  }
}
// ---------------------------------------------------------------------------
static void os_interrupt_evt2_handler()
{
  register uint32 mevtflag;
  register uint32 evt;
  register uint32 evt_index;
  register void (*handler)();

  while( mevtflag = REG_MEVTFLAG2 )
  {
    REG_EVTCLR2 = mevtflag;

    for( evt_index = 60, evt = 1; evt != 0; evt <<= 1, evt_index++ )
    {
      if( mevtflag & evt )
      {
        if( handler = interrupt_handler[evt_index] ) handler();
      }
    }
  }
}
// ---------------------------------------------------------------------------
static void os_interrupt_evt3_handler()
{
  register uint32 mevtflag;
  register uint32 evt;
  register uint32 evt_index;
  register void (*handler)();

  while( mevtflag = REG_MEVTFLAG3 )
  {
    REG_EVTCLR3 = mevtflag;

    for( evt_index = 92, evt = 1; evt != 0; evt <<= 1, evt_index++ )
    {
      if( mevtflag & evt )
      {
        if( handler = interrupt_handler[evt_index] ) handler();
      }
    }
  }
}
// ---------------------------------------------------------------------------
// !: fn: void os_interrupt_init_module()
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция инициализирует менеджер прерываний и настраивает отображение
// !: d: аппаратных источников прерываний на прерывания процессорного ядра.
// !: d: Функция не доступна пользователю.
// !: -:
// ---------------------------------------------------------------------------
void os_interrupt_init_module()
{
  register uint32 i;

  memset( interrupt_handler, 0, sizeof(interrupt_handler) );

  for( i = 0; i < 125; i++ )
  {
    v_os_interrupt_table[i].id = RES_VOID;
    v_os_interrupt_table[i].vector = ( ( i == 0 ) ? 1 : ( i + 3 ) );
    v_os_interrupt_table[i].source = INT_NOTUSED;
    v_os_interrupt_table[i].own_process = 0;
  }

  v_os_interrupt_vector_evt0 = (uint32)&os_interrupt_evt0_handler;
  v_os_interrupt_vector_evt1 = (uint32)&os_interrupt_evt1_handler;
  v_os_interrupt_vector_evt2 = (uint32)&os_interrupt_evt2_handler;
  v_os_interrupt_vector_evt3 = (uint32)&os_interrupt_evt3_handler;
  
  os_interrupt_map( 4, INT_TINTLO0 );
  os_interrupt_map( 5, INT_EVT0 );
  os_interrupt_map( 6, INT_EVT1 );
  os_interrupt_map( 7, INT_EVT2 );
  os_interrupt_map( 8, INT_EVT3 );

  for( i = 0; i < 128; i++ ) os_interrupt_evt_disable_ll( i );
  for( i = 9; i < 16; i++ ) os_interrupt_lock_ll( i );
  for( i = 4; i < 9; i++ ) os_interrupt_unlock_ll( i );

  asm( "        mvkl    .s2     0x00900000, b24         " );
  asm( "        mvkh    .s2     0x00900000, b24         " );
  asm( "        mvc     .s2     b24, istp               " );
}
// ---------------------------------------------------------------------------
// !: fn: void os_interrupt_cleanup()
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция освобождает все ресурсы (прерывания), которые были захвачены
// !: d: завершающимся процессом. Функция не доступна пользователю.
// !: -:
// ---------------------------------------------------------------------------
void os_interrupt_cleanup()
{
  register uint32 is = int_disable();

  for( int32 i = 0; i < 125; i++ )
  {
    if( v_os_interrupt_table[i].own_process == v_os_current_process->id )
    {
      os_interrupt_free( v_os_interrupt_table[i].id );
    }
  }

  int_enable( is );
}
// ---------------------------------------------------------------------------
// !: fn: static bool os_interrupt_map( uint32 vector, uint32 source )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция отображает аппаратный источник прерываний source на
// !: d: процессорный вектор vector. Функция не доступна пользователю.<br>
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: В случае успеха функция возвращает true, иначе false.
// !: -:
// ---------------------------------------------------------------------------
static bool os_interrupt_map( uint32 vector, uint32 source )
{
  register uint32 v_index;
  register uint32 v_shift;
  register uint32 value;
  register uint32 is;

  if( ( vector < 4 ) || ( vector >= 16 ) ) return false;
  if( source >= 128 ) return false;
  
  is = int_disable();

  v_index = vector >> 2;
  v_shift = ( vector & 3 ) << 3;
  value = REG_INTMUX[v_index];
  value = ( value & ~( 0x000000ff << v_shift ) ) | ( source << v_shift );
  REG_INTMUX[v_index] = value;

  int_enable( is );

  return true;
}
// ---------------------------------------------------------------------------
// !: fn: uint32 os_interrupt_check( uint32 rid )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция осуществляет проверку ресурса rid перед его использованием на
// !: d: предмет корректности идентификатора. Так же преверяются права доступа
// !: d: к ресурсу. Функция не доступна пользователю.<br>
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: Функция возвращает индекс ресурса в системной таблице.
// !: -:
// ---------------------------------------------------------------------------
uint32 os_interrupt_check( uint32 rid )
{
  uint32 index = rid & RES_I_MASK;

  if( ( ( rid & RES_T_MASK ) != RES_T_INTERRUPT ) || ( index >= 125 ) )
  {
    os_sfault( OSSF_BAD_DESCRIPTOR );
    // No return from ^-- this point
  }
  s_os_interrupt* i = &v_os_interrupt_table[index];
  if( i->id == RES_VOID ) return 0xffffffff;
  if( ( i->id & RES_F_SHARED ) == 0 )
  {
    if( i->own_process != v_os_current_process->id )
    {
      os_sfault( OSSF_PROTECTION_FAULT );
      // No return from ^-- this point
    }
  }

  return index;
}
// ---------------------------------------------------------------------------
// !: fn: uint32 os_interrupt_alloc( uint32 source, void (*handler)() )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall псевдоним:</b><br>
// !: d: <br>
// !: d: int_alloc<br>
// !: d: <br>
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Фукция выделяет один из неиспользуемых процессорных векторов
// !: d: прерываний и связывает с ним аппартный источник прерываний source.
// !: d: А так же устанавливает пользовательский обработчик прерываний
// !: d: handler.
// !: d: В качестве входного источка могут быть указаны следующие типы
// !: d: прерываний:<br>
// !: d: <br>
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: При возникновении ошибки функция возвращает RES_VOID, иначе функция
// !: d: возвращает идентификатор ресурса, который необходим для вызова
// !: d: функций работающих с ресурсом.
// !: -:
// ---------------------------------------------------------------------------
uint32 os_interrupt_alloc( uint32 source, void (*handler)() )
{
  uint32 r = RES_VOID;
  register uint32 is;

  if( handler == NULL ) return RES_VOID;
  if( source == INT_TINTLO0 ) return RES_VOID;
  if( source == INT_TINTHI0 ) return RES_VOID;

  is = int_disable();

  if( source == INT_NMI )
  {
    if( v_os_interrupt_table[0].id != RES_VOID ) goto l_fail;
    v_os_interrupt_vector_01_NMI = (uint32)handler;
    v_os_interrupt_table[0].own_process = ( v_os_core_call ) ? 0 : v_os_current_process->id;
    v_os_interrupt_table[0].source = source;
    v_os_interrupt_table[0].id = RES_T_INTERRUPT;
    r = v_os_interrupt_table[0].id;
  }
  else if( ( source >= 4 ) && ( source < 128 ) )
  {
    source -= 3;
    if( v_os_interrupt_table[source].id != RES_VOID ) goto l_fail;
    v_os_interrupt_table[source].id = RES_T_INTERRUPT | source;
    v_os_interrupt_table[source].own_process = ( v_os_core_call ) ? 0 : v_os_current_process->id;
    v_os_interrupt_table[source].source = source + 3;
    interrupt_handler[source-1] = handler;
    r = v_os_interrupt_table[source].id;
  }

l_fail:

  int_enable( is );

  return r;
}
// ---------------------------------------------------------------------------
// !: fn: uint32 os_interrupt_free( uint32 rid )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall псевдоним:</b><br>
// !: d: <br>
// !: d: int_free<br>
// !: d: <br>
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция освобождает прерывание rid, выделенное функцией int_alloc.<br>
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: В случае успеха функция возвращает OSE_OK, иначе одну из ошибок:<br><br>
// !: d: <table cellpadding=2 cellspacing=2 border=0>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_VOID_RESOURCE</td>
// !: d: <td> - </td>
// !: d: <td>идентификатор ресурса rid равен RES_VOID;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_BAD_RDESC</td>
// !: d: <td> - </td>
// !: d: <td>неправильный идентификатор ресурса rid.</td>
// !: d: </tr>
// !: d: </table><br>
// !: -:
// ---------------------------------------------------------------------------
int32 os_interrupt_free( uint32 rid )
{
  if( rid == RES_VOID ) return OSE_VOID_RESOURCE;

  uint32 index = os_interrupt_check( rid );
  if( index == 0xffffffff ) return OSE_BAD_RDESC;

  int_lock( rid );

  if( index == 0 )
  {
    v_os_interrupt_vector_01_NMI = (uint32)&os_interrupt_null_vector_ll;
  }
  else
  {
    interrupt_handler[index-1] = NULL;
  }
  v_os_interrupt_table[index].source = INT_NOTUSED;
  v_os_interrupt_table[index].own_process = 0;
  v_os_interrupt_table[index].id = RES_VOID;

  return OSE_OK;
}
// ---------------------------------------------------------------------------
void os_interrupt_swto( uint16 pid )
{
  v_os_swto_pid = pid;
  REG_CNTLO0 = sys_quant - 1;
}
// ---------------------------------------------------------------------------
// !: fn: uint32 os_interrupt_lock( uint32 rid )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall псевдоним:</b><br>
// !: d: <br>
// !: d: int_lock<br>
// !: d: <br>
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция маскирует прерывание на которое ссылается идентификатор
// !: d: ресурса rid.<br>
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: В случае успеха функция возвращает OSE_OK, иначе одну из ошибок:<br><br>
// !: d: <table cellpadding=2 cellspacing=2 border=0>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_VOID_RESOURCE</td>
// !: d: <td> - </td>
// !: d: <td>идентификатор ресурса rid равен RES_VOID;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_BAD_RDESC</td>
// !: d: <td> - </td>
// !: d: <td>неправильный идентификатор ресурса rid.</td>
// !: d: </tr>
// !: d: </table><br>
// !: -:
// ---------------------------------------------------------------------------
int32 os_interrupt_lock( uint32 rid )
{
  if( rid == RES_VOID ) return OSE_VOID_RESOURCE;
  
  uint32 index = os_interrupt_check( rid );
  if( index == 0xffffffff ) return OSE_BAD_RDESC;

  if( index == 0 )
  {
    os_interrupt_lock_ll( v_os_interrupt_table[index].vector );
  }
  else
  {
    os_interrupt_evt_disable_ll( v_os_interrupt_table[index].source );
  }

  return OSE_OK;
}
// ---------------------------------------------------------------------------
// !: fn: int32 os_interrupt_unlock( uint32 rid )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall псевдоним:</b><br>
// !: d: <br>
// !: d: int_unlock<br>
// !: d: <br>
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция размаскирует прерывание на которое ссылается идентификатор
// !: d: ресурса rid.<br>
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: В случае успеха функция возвращает OSE_OK, иначе одну из ошибок:<br><br>
// !: d: <table cellpadding=2 cellspacing=2 border=0>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_VOID_RESOURCE</td>
// !: d: <td> - </td>
// !: d: <td>идентификатор ресурса rid равен RES_VOID;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_BAD_RDESC</td>
// !: d: <td> - </td>
// !: d: <td>неправильный идентификатор ресурса rid.</td>
// !: d: </tr>
// !: d: </table><br>
// !: -:
// ---------------------------------------------------------------------------
int32 os_interrupt_unlock( uint32 rid )
{
  if( rid == RES_VOID ) return OSE_VOID_RESOURCE;

  uint32 index = os_interrupt_check( rid );
  if( index == 0xffffffff ) return OSE_BAD_RDESC;

  if( index == 0 )
  {
    os_interrupt_unlock_ll( v_os_interrupt_table[index].vector );
  }
  else
  {
    os_interrupt_evt_enable_ll( v_os_interrupt_table[index].source );
  }

  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 os_interrupt_clear( uint32 rid )
{
  if( rid == RES_VOID ) return OSE_VOID_RESOURCE;

  uint32 index = os_interrupt_check( rid );
  if( index == 0xffffffff ) return OSE_BAD_RDESC;

  if( index == 0 )
  {
    os_interrupt_clear_ll( v_os_interrupt_table[index].vector );
  }
  else
  {
    os_interrupt_evt_clear_ll( v_os_interrupt_table[index].source );
  }

  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 os_interrupt_set( uint32 rid )
{
  if( rid == RES_VOID ) return OSE_VOID_RESOURCE;

  uint32 index = os_interrupt_check( rid );
  if( index == 0xffffffff ) return OSE_BAD_RDESC;

  if( index == 0 )
  {
    os_interrupt_set_ll( v_os_interrupt_table[index].vector );
  }
  else
  {
    os_interrupt_evt_set_ll( v_os_interrupt_table[index].source );
  }

  return OSE_OK;
}
// ---------------------------------------------------------------------------
