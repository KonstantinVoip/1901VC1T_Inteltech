// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: all
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp866
// !: d: Модуль содержит реализацию функций работы с системными настройками.
// !: -:
// ---------------------------------------------------------------------------
#define SYSCALL_DIRECT
#include <os.h>
// ---------------------------------------------------------------------------
char sys_processor_name[24];

uint64 sys_frequency;
uint32 sys_quant;
uint32 sys_stack;

uint32 REG_OSCFG0;
uint32 REG_OSTS0;
uint32 REG_OSTS1;

uint32 reg_sem;
uint32 bus_sem;

// ---------------------------------------------------------------------------
// !: fn: void os_system_init()
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция инициализирует системные настрйоки по умолчанию. Данная
// !: d: функция не доступна пользователю.
// !: -:
// ---------------------------------------------------------------------------
void os_system_init_module( int32 stage )
{
  if( stage == 0 )
  {
    memset( sys_processor_name, 0, sizeof(sys_processor_name) );
    sys_frequency = 1000000000llu;
    sys_quant = core_init_cfg.sys_quant;
    sys_stack = 4096;
    REG_OSCFG0 = 0;
    REG_OSTS0 = 0;
    REG_OSTS1 = 0;
  }
  else if( stage == 1 )
  {
    if( ( reg_sem = sem_alloc( 1, NULL ) ) == RES_VOID )
      while( true );

    if( ( bus_sem = sem_alloc( 1, NULL ) ) == RES_VOID )
      while( true );
  }
}
// ---------------------------------------------------------------------------
// !: fn: int32 os_system_setname( const char* name )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall псевдоним:</b><br>
// !: d: <br>
// !: d: sys_setname<br>
// !: d: <br>
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция устанавливает имя системы в name. Используется для определения
// !: d: процессорного ядра в многопроцессорных системах. Установить имя
// !: d: системы можно только один раз, как правило это делается по старту
// !: d: системы.<br>
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: В случае успеха функция возвращает OSE_OK, иначе одну из ошибок:
// !: d: OSE_NULL_PARAM - передан нулевой указатель на строку name;
// !: d: OSE_TOO_LONG_STRING - длина переданной строки слишком велика;
// !: d: OSE_ALLREADY_NAMED - имя системы уже установлено.
// !: -:
// ---------------------------------------------------------------------------
int32 os_system_setname( const char* name )
{
  if( name == NULL ) return OSE_NULL_PARAM;
  if( strlen( name ) > 23 ) return OSE_TOO_LONG_STRING;
  if( sys_processor_name[0] != 0 ) return OSE_ALLREADY_NAMED;
  strcpy( sys_processor_name, name );
  return OSE_OK;
}
// ---------------------------------------------------------------------------
// !: fn: int32 os_system_getname( char* buf, uint32 buf_length )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall псевдоним:</b><br>
// !: d: <br>
// !: d: sys_getname<br>
// !: d: <br>
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция копирует имя системы в пользовательский буффер buf, длина
// !: d: которого определена как buf_length (включая завершающий 0).<br>
// !: d: <br>
// !: d: <b>Примечание:</b><br>
// !: d: <br>
// !: d: Если имя системы не было установлено, в результирующем буфере
// !: d: окажется строка нулевой длины.<br>
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: В случае успеха функция возвращает OSE_OK, иначе одну из ошибок:
// !: d: OSE_NULL_PARAM - передан нулевой указатель на буффер buf;
// !: d: OSE_TOO_SHORT_BUFFER - длина буфера не достаточна, для вмещения
// !: d: имени системы.
// !: -:
// ---------------------------------------------------------------------------
int32 os_system_getname( char* buf, uint32 buf_length )
{
  if( buf == NULL ) return OSE_NULL_PARAM;
  if( buf_length <= strlen( sys_processor_name ) ) return OSE_TOO_SHORT_BUFFER;
  strcpy( buf, sys_processor_name );
  return OSE_OK;
}
// ---------------------------------------------------------------------------
// !: fn: int32 os_system_chkname( const char* name )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall псевдоним:</b><br>
// !: d: <br>
// !: d: sys_chkname<br>
// !: d: <br>
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция сравнивает установленное имя системы с переданным name.<br>
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: Если переданное имя совпадает с установленным, функция возвращает
// !: d: OSE_OK, в случае если передана нулевая строка или имена не совпадают
// !: d: функция возвращает OSE_FAIL.
// !: -:
// ---------------------------------------------------------------------------
int32 os_system_chkname( const char* name )
{
  if( name == NULL ) return OSE_FAIL;
  return ( ( strcmp( sys_processor_name, name ) == 0 ) ? OSE_OK : OSE_FAIL );
}
// ---------------------------------------------------------------------------
uint32 os_system_osts0()
{
  return REG_OSTS0;
}
// ---------------------------------------------------------------------------
uint32 os_system_osts1()
{
  return REG_OSTS1;
}
// ---------------------------------------------------------------------------
uint32 last_x;
void os_system_debug( uint32 x )
{
last_x = x;
  asm( " nop " );
}
// ---------------------------------------------------------------------------
int32 os_system_regget( uint32 regid, uint32* value )
{
  if( value == NULL ) return OSE_NULL_PARAM;

  switch( regid )
  {
    case OSCFG0:
      (*value) = REG_OSCFG0;
      break;

    case OSTS0:
      (*value) = REG_OSTS0;
      break;

    case OSTS1:
      (*value) = REG_OSTS1;
      break;

    case OSSYSQUANT:
      (*value) = sys_quant;
      break;

    default:
      return OSE_BAD_RESOURCE_INDEX;
  }

  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 os_system_regset( uint32 regid, uint32 value )
{
  switch( regid )
  {
    case OSCFG0:
      REG_OSCFG0 = value;
      break;

    case OSTS0:
      REG_OSTS0 = value;
      break;

    case OSTS1:
      REG_OSTS1 = value;
      break;

    default:
      return OSE_BAD_RESOURCE_INDEX;
  }

  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 os_system_reglock()
{
  return (int32)sem_lock( reg_sem, SEM_INFINITY );
}
// ---------------------------------------------------------------------------
int32 os_system_regunlock()
{
  return (int32)sem_unlock( reg_sem );
}
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
int32 os_system_buslock()
{
  return (int32)sem_lock( bus_sem, SEM_INFINITY );
}
// ---------------------------------------------------------------------------
int32 os_system_busunlock()
{
  return (int32)sem_unlock( bus_sem );
}
// ---------------------------------------------------------------------------
