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
// ---------------------------------------------------------------------------

uint32 v_os_interrupt_vector_01_NMI;
uint32 v_os_interrupt_vector_05;
uint32 v_os_interrupt_vector_06;
uint32 v_os_interrupt_vector_07;
uint32 v_os_interrupt_vector_08;
uint32 v_os_interrupt_vector_09;
uint32 v_os_interrupt_vector_10;
uint32 v_os_interrupt_vector_11;
uint32 v_os_interrupt_vector_12;
uint32 v_os_interrupt_vector_13;
uint32 v_os_interrupt_vector_14;
uint32 v_os_interrupt_vector_15;
s_os_interrupt v_os_interrupt_table[12];

static bool os_interrupt_map( uint32 vector, uint32 source );

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
  // Fill interrupt table
  for( uint32 i = 0; i < 12; i++ )
  {
    v_os_interrupt_table[i].id = RES_VOID;
    v_os_interrupt_table[i].vector = ( ( i == 0 ) ? 1 : ( i + 4 ) );
    v_os_interrupt_table[i].source = INT_NOTUSED;
    v_os_interrupt_table[i].own_process = 0;
  }
  // Map timer interrupt
  REG_MUXL = ( REG_MUXL & 0xffffffe0 ) | 1;
  // Map other interrupts
  for( int32 i = 5; i <= 15; i++ ) os_interrupt_map( i, INT_DSP );
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

  for( int32 i = 0; i < 12; i++ )
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
  bool res = true;
  register uint32 is = int_disable();

  switch( vector )
  {
    case 5 : REG_MUXL = ( REG_MUXL & 0xfffffc1f ) | ( source << 5  ); break;
    case 6 : REG_MUXL = ( REG_MUXL & 0xffff83ff ) | ( source << 10 ); break;
    case 7 : REG_MUXL = ( REG_MUXL & 0xffe0ffff ) | ( source << 16 ); break;
    case 8 : REG_MUXL = ( REG_MUXL & 0xfc1fffff ) | ( source << 21 ); break;
    case 9 : REG_MUXL = ( REG_MUXL & 0x83ffffff ) | ( source << 26 ); break;
    case 10: REG_MUXH = ( REG_MUXH & 0xffffffe0 ) | ( source       ); break;
    case 11: REG_MUXH = ( REG_MUXH & 0xfffffc1f ) | ( source << 5  ); break;
    case 12: REG_MUXH = ( REG_MUXH & 0xffff83ff ) | ( source << 10 ); break;
    case 13: REG_MUXH = ( REG_MUXH & 0xffe0ffff ) | ( source << 16 ); break;
    case 14: REG_MUXH = ( REG_MUXH & 0xfc1fffff ) | ( source << 21 ); break;
    case 15: REG_MUXH = ( REG_MUXH & 0x83ffffff ) | ( source << 26 ); break;
    default: res = false;
  }
 
  int_enable( is );

  return res;
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

  if( ( ( rid & RES_T_MASK ) != RES_T_INTERRUPT ) || ( index >= 12 ) )
  {
    os_sfault( OSSF_BAD_DESCRIPTOR );
    // No return from ^-- this point
  }
  s_os_interrupt* i = &v_os_interrupt_table[index];
  if( ( i->id & RES_F_USED ) == 0 ) return 0xffffffff;
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
// !: d: <table cellpadding=2 cellspacing=2 border=0 width=100%>
// !: d: <tr><td width=32>
// !: d:   <td valign=top width=1>INT_TIMER0</td>
// !: d:   <td>-</td>
// !: d:   <td>Прерывание от 0-го таймера</td>
// !: d: </tr><tr><td width=32>
// !: d:   <td valign=top width=1>INT_TIMER1</td>
// !: d:   <td>-</td>
// !: d:   <td>Прерывание от 1-го таймера</td>
// !: d: </tr><tr><td width=32>
// !: d:   <td valign=top width=1>INT_TIMER2</td>
// !: d:   <td>-</td>
// !: d:   <td>Прерывание от 2-го таймера</td>
// !: d: </tr><tr><td width=32>
// !: d:   <td valign=top width=1>INT_MCBSP0_RX</td>
// !: d:   <td>-</td>
// !: d:   <td>Прервание от 0-го канала MCBSP происходящее при приеме слова</td>
// !: d: </tr><tr><td width=32>
// !: d:   <td valign=top width=1>INT_MCBSP1_RX</td>
// !: d:   <td>-</td>
// !: d:   <td>Прервание от 1-го канала MCBSP происходящее при приеме слова</td>
// !: d: </tr><tr><td width=32>
// !: d:   <td valign=top width=1>INT_MCBSP2_RX</td>
// !: d:   <td>-</td>
// !: d:   <td>Прервание от 2-го канала MCBSP происходящее при приеме слова</td>
// !: d: </tr><tr><td width=32>
// !: d:   <td valign=top width=1>INT_MCBSP0_TX</td>
// !: d:   <td>-</td>
// !: d:   <td>Прервание от 0-го канала MCBSP происходящее при отправке слова</td>
// !: d: </tr><tr><td width=32>
// !: d:   <td valign=top width=1>INT_MCBSP1_TX</td>
// !: d:   <td>-</td>
// !: d:   <td>Прервание от 1-го канала MCBSP происходящее при отправке слова</td>
// !: d: </tr><tr><td width=32>
// !: d:   <td valign=top width=1>INT_MCBSP2_TX</td>
// !: d:   <td>-</td>
// !: d:   <td>Прервание от 2-го канала MCBSP происходящее при отправке слова</td>
// !: d: </tr><tr><td width=32>
// !: d:   <td valign=top width=1>INT_SD_INTA</td>
// !: d:   <td>-</td>
// !: d:   <td></td>
// !: d: </tr><tr><td width=32>
// !: d:   <td valign=top width=1>INT_SD_INTB</td>
// !: d:   <td>-</td>
// !: d:   <td></td>
// !: d: </tr><tr><td width=32>
// !: d:   <td valign=top width=1>INT_UTOPIA</td>
// !: d:   <td>-</td>
// !: d:   <td></td>
// !: d: </tr><tr><td width=32>
// !: d:   <td valign=top width=1>INT_DSP</td>
// !: d:   <td>-</td>
// !: d:   <td></td>
// !: d: </tr><tr><td width=32>
// !: d:   <td valign=top width=1>INT_GP0</td>
// !: d:   <td>-</td>
// !: d:   <td>Прерывание GP0</td>
// !: d: </tr><tr><td width=32>
// !: d:   <td valign=top width=1>INT_GP4</td>
// !: d:   <td>-</td>
// !: d:   <td>Прерывание GP4</td>
// !: d: </tr><tr><td width=32>
// !: d:   <td valign=top width=1>INT_GP5</td>
// !: d:   <td>-</td>
// !: d:   <td>Прерывание GP5</td>
// !: d: </tr><tr><td width=32>
// !: d:   <td valign=top width=1>INT_GP6</td>
// !: d:   <td>-</td>
// !: d:   <td>Прерывание GP6</td>
// !: d: </tr><tr><td width=32>
// !: d:   <td valign=top width=1>INT_GP7</td>
// !: d:   <td>-</td>
// !: d:   <td>Прерывание GP7</td>
// !: d: </tr><tr><td width=32>
// !: d:   <td valign=top width=1>INT_EDMA</td>
// !: d:   <td>-</td>
// !: d:   <td>Прерывание от EDMA контроллера</td>
// !: d: </tr><tr><td width=32>
// !: d:   <td valign=top width=1>INT_PCI_WAKEUP</td>
// !: d:   <td>-</td>
// !: d:   <td>Прервание от PCI шины провоцирующее процессор выйти из состояние ожидания</td>
// !: d: </tr><tr><td width=32>
// !: d:   <td valign=top width=1>INT_EMAC_MDIO</td>
// !: d:   <td>-</td>
// !: d:   <td>Прервание от внутриядерного сетевого Ethernet контроллера</td>
// !: d: </tr><tr><td width=32>
// !: d:   <td valign=top width=1>INT_NMI</td>
// !: d:   <td>-</td>
// !: d:   <td>Немаскируемое прерывание</td>
// !: d: </tr>
// !: d: </table>
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

  is = int_disable();

  if( handler == NULL ) goto l_fail;

  if( source == INT_NMI )
  {
    if( v_os_interrupt_table[0].id != RES_VOID ) goto l_fail;
    v_os_interrupt_vector_01_NMI = (uint32)handler;
    v_os_interrupt_table[0].own_process = ( v_os_core_call ) ? 0 : v_os_current_process->id;
    v_os_interrupt_table[0].source = source;
    v_os_interrupt_table[0].id = RES_T_INTERRUPT | RES_F_USED;
    r = v_os_interrupt_table[0].id;
  }
  else if( source < 32 )
  {
    for( uint32 i = 1; i < 12; i++ )
    {
      if( v_os_interrupt_table[i].id == RES_VOID )
      {
        if( !os_interrupt_map( v_os_interrupt_table[i].vector, source ) ) goto l_fail;
        v_os_interrupt_table[i].id = RES_T_INTERRUPT | RES_F_USED | i;
        v_os_interrupt_table[i].own_process = ( v_os_core_call ) ? 0 : v_os_current_process->id;
        v_os_interrupt_table[i].source = source;
        switch( v_os_interrupt_table[i].vector )
        {
          case 5 : v_os_interrupt_vector_05 = (uint32)handler; break;
          case 6 : v_os_interrupt_vector_06 = (uint32)handler; break;
          case 7 : v_os_interrupt_vector_07 = (uint32)handler; break;
          case 8 : v_os_interrupt_vector_08 = (uint32)handler; break;
          case 9 : v_os_interrupt_vector_09 = (uint32)handler; break;
          case 10: v_os_interrupt_vector_10 = (uint32)handler; break;
          case 11: v_os_interrupt_vector_11 = (uint32)handler; break;
          case 12: v_os_interrupt_vector_12 = (uint32)handler; break;
          case 13: v_os_interrupt_vector_13 = (uint32)handler; break;
          case 14: v_os_interrupt_vector_14 = (uint32)handler; break;
          case 15: v_os_interrupt_vector_15 = (uint32)handler; break;
        }
        r = v_os_interrupt_table[i].id;
        break;
      }
    }
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

  switch( v_os_interrupt_table[index].vector )
  {
    case 1 : v_os_interrupt_vector_01_NMI = (uint32)&os_interrupt_null_vector_ll; break;
    case 5 : v_os_interrupt_vector_05     = (uint32)&os_interrupt_null_vector_ll; break;
    case 6 : v_os_interrupt_vector_06     = (uint32)&os_interrupt_null_vector_ll; break;
    case 7 : v_os_interrupt_vector_07     = (uint32)&os_interrupt_null_vector_ll; break;
    case 8 : v_os_interrupt_vector_08     = (uint32)&os_interrupt_null_vector_ll; break;
    case 9 : v_os_interrupt_vector_09     = (uint32)&os_interrupt_null_vector_ll; break;
    case 10: v_os_interrupt_vector_10     = (uint32)&os_interrupt_null_vector_ll; break;
    case 11: v_os_interrupt_vector_11     = (uint32)&os_interrupt_null_vector_ll; break;
    case 12: v_os_interrupt_vector_12     = (uint32)&os_interrupt_null_vector_ll; break;
    case 13: v_os_interrupt_vector_13     = (uint32)&os_interrupt_null_vector_ll; break;
    case 14: v_os_interrupt_vector_14     = (uint32)&os_interrupt_null_vector_ll; break;
    case 15: v_os_interrupt_vector_15     = (uint32)&os_interrupt_null_vector_ll; break;
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
  REG_CNT0 = sys_quant - 1;
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

  os_interrupt_lock_ll( v_os_interrupt_table[index].vector );

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

  os_interrupt_unlock_ll( v_os_interrupt_table[index].vector );

  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 os_interrupt_clear( uint32 rid )
{
  if( rid == RES_VOID ) return OSE_VOID_RESOURCE;

  uint32 index = os_interrupt_check( rid );
  if( index == 0xffffffff ) return OSE_BAD_RDESC;

  os_interrupt_clear_ll( v_os_interrupt_table[index].vector );

  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 os_interrupt_set( uint32 rid )
{
  if( rid == RES_VOID ) return OSE_VOID_RESOURCE;

  uint32 index = os_interrupt_check( rid );
  if( index == 0xffffffff ) return OSE_BAD_RDESC;

  os_interrupt_set_ll( v_os_interrupt_table[index].vector );

  return OSE_OK;
}
// ---------------------------------------------------------------------------
