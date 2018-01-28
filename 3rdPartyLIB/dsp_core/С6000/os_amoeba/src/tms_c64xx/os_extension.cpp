// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: all
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp866
// !: d: ����� ᮤ�ন� ॠ������ �������� ���७�� ��.
// !: -:
// ---------------------------------------------------------------------------
#define SYSCALL_DIRECT
#include <os.h>
// ---------------------------------------------------------------------------

s_os_extension* ext_first = NULL;
s_os_extension* ext_last = NULL;
uint32 ext_sem = RES_VOID;

// ---------------------------------------------------------------------------
void os_extension_init_module()
{
  if( ( ext_sem = sem_alloc( 1, NULL ) ) == RES_VOID )
  {
    while( true )
      asm( " nop " );
  }
}
// ---------------------------------------------------------------------------
void os_extension_cleanup()
{
}
// ---------------------------------------------------------------------------
// !: fn: int32 os_extension_plug( s_os_extension* e )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall �ᥢ�����:</b><br>
// !: d: <br>
// !: d: ext_plug<br>
// !: d: <br>
// !: d: <b>���ᠭ��:</b><br>
// !: d: <br>
// !: d: �㭪�� �������� � ��⥬� ���७��, ���ᠭ��� ������ன e.<br>
// !: d: <br>
// !: d: <b>�����頥�� ���祭��:</b><br>
// !: d: <br>
// !: d: � ��砥 �ᯥ� �㭪�� �����頥� OSE_OK, ���� ����� �� �訡��:<br><br>
// !: d: <table cellpadding=2 cellspacing=2 border=0>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_NULL_PARAM</td>
// !: d: <td> - </td>
// !: d: <td>��६����� e ࠢ�� ���;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_EXTENSION_PLUGGED</td>
// !: d: <td> - </td>
// !: d: <td>���७�� � ⠪�� ������ 㦥 ��ॣ����஢��� � ��⥬�;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_EXTENSION_BAD_HEADER</td>
// !: d: <td> - </td>
// !: d: <td>���� �� �������, ����뢠��� �㭪�� ���७�� �����४⭠;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_EXTENSION_F_PLUGGED</td>
// !: d: <td> - </td>
// !: d: <td>���� �� �㭪権 �������� �㭪樮��� syscall ����䥩� 㦥
// !: d: ��������� � ��⥬�.</td>
// !: d: </tr>
// !: d: </table><br>
// ---------------------------------------------------------------------------
int32 os_extension_plug( s_os_extension* e )
{
  s_os_extension* cext;
  int32 i;

  if( e == NULL ) return OSE_NULL_PARAM;

  sem_lock( ext_sem, SEM_INFINITY );

  // Check for loaded extensions
  cext = ext_first;
  while( cext )
  {
    if( strcmp( e->name, cext->name ) == 0 )
    {
      sem_unlock( ext_sem );
      return OSE_EXTENSION_PLUGGED;
    }
    cext = cext->next;
  }

  // Check for loaded functions
  for( i = 0; i < e->f_count; i++ )
  {
    s_os_extension_f& ef = e->f_tab[i];
    if( ( ef.f_ptr == 0 ) || ( ( ef.f_syscall_index != EXT_DYNAMIC ) && ( ef.f_syscall_index >= SYSCALL__COUNT__ ) ) )
    {
      sem_unlock( ext_sem );
      return OSE_EXTENSION_BAD_HEADER;
    }
    if( ef.f_name == NULL )
    {
      if( ef.f_syscall_index == EXT_DYNAMIC )
      {
        sem_unlock( ext_sem );
        return OSE_EXTENSION_BAD_HEADER;
      }
      if( __os_syscall_table__[ef.f_syscall_index] != (void*)(uint32)&os_syscall_sfault_vector )
      {
        sem_unlock( ext_sem );
        return OSE_EXTENSION_F_PLUGGED;
      }
    }
  }

  // Plug extension
  e->next = NULL;
  e->prev = NULL;
  if( ext_first == NULL )
  {
    ext_first = e;
    ext_last = e;
  }
  else
  {
    e->prev = ext_last;
    ext_last->next = e;
    ext_last = e;
  }

  // Plug syscall functions
  for( i = 0; i < e->f_count; i++ )
  {
    s_os_extension_f& ef = e->f_tab[i];
    if( ef.f_syscall_index != EXT_DYNAMIC )
    {
      __os_syscall_table__[ef.f_syscall_index] = (void*)ef.f_ptr;
    }
  }

  sem_unlock( ext_sem );

  return OSE_OK;
}
// ---------------------------------------------------------------------------
// !: fn: int32 os_extension_unplug( s_os_extension* e )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall �ᥢ�����:</b><br>
// !: d: <br>
// !: d: ext_unplug<br>
// !: d: <br>
// !: d: <b>���ᠭ��:</b><br>
// !: d: <br>
// !: d: �㭪�� ��������� ���७�� e �� ��⥬�.<br>
// !: d: <br>
// !: d: <b>�����頥�� ���祭��:</b><br>
// !: d: <br>
// !: d: � ��砥 �ᯥ� �㭪�� �����頥� OSE_OK.
// ---------------------------------------------------------------------------

int32 os_extension_unplug( s_os_extension* e )
{
  return 0;
}
// ---------------------------------------------------------------------------
// !: fn: int32 os_extension_load( const char* name )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall �ᥢ�����:</b><br>
// !: d: <br>
// !: d: ext_load<br>
// !: d: <br>
// !: d: <b>���ᠭ��:</b><br>
// !: d: <br>
// !: d: �㭪�� ����㦠�� ���७�� � ������ name � ��⥬� (���७��
// !: d: ����� � ��⥬��� ������).<br>
// !: d: <br>
// !: d: <b>�����頥�� ���祭��:</b><br>
// !: d: <br>
// !: d: � ��砥 �ᯥ� �㭪�� �����頥� OSE_OK.
// ---------------------------------------------------------------------------
int32 os_extension_load( const char* name )
{
  return 0;
}
// ---------------------------------------------------------------------------
// !: fn: int32 os_extension_unload( const char* name )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall �ᥢ�����:</b><br>
// !: d: <br>
// !: d: ext_unload<br>
// !: d: <br>
// !: d: <b>���ᠭ��:</b><br>
// !: d: <br>
// !: d: �㭪�� ���㦠�� ���७�� � ������ name �� ��⥬�.<br>
// !: d: <br>
// !: d: <b>�����頥�� ���祭��:</b><br>
// !: d: <br>
// !: d: � ��砥 �ᯥ� �㭪�� �����頥� OSE_OK.
// ---------------------------------------------------------------------------
int32 os_extension_unload( const char* name )
{
  return 0;
}
// ---------------------------------------------------------------------------
// !: fn: void* os_extension_symbol( const char* name )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall �ᥢ�����:</b><br>
// !: d: <br>
// !: d: ext_symbol<br>
// !: d: <br>
// !: d: <b>���ᠭ��:</b><br>
// !: d: <br>
// !: d: �㭪�� �����頥� 㪠��⥫� �� ᨬ��� name. ��� ᨬ���� ����� ����
// !: d: 㪠���� ���� ᯮᮡ���. ��-����� �����।�⢥��� ���, ���ਬ��:
// !: d: "symbol_foo". ��-����� ����� ������ ��� ���७�� �� ���ண� �㤥�
// !: d: ���� ᨬ���, ���ਬ��: "extension::symbol_foo".<br>
// !: d: <br>
// !: d: <b>�����頥�� ���祭��:</b><br>
// !: d: <br>
// !: d: � ��砥 �ᯥ� �㭪�� �����頥� 㪠��⥫� �� ���� � ����� ���
// !: d: ����� ᨬ���. �᫨ � ࠧ��� ���७��� ���������� ᨬ���� �
// !: d: ��������묨 ������� � ��� ���७�� �� 㪠���� � �����, �㭪��
// !: d: ��୥� ���� �����訩�� ᨬ��� � ������� ������. �㭪�� �����頥�
// !: d: NULL, �᫨ 㪠����� ᨬ��� �� �� ������.
// ---------------------------------------------------------------------------
void* os_extension_symbol( const char* name )
{
  return 0;
}
// ---------------------------------------------------------------------------


/*
// ---------------------------------------------------------------------------
void os_extension_init_module()
{
  if( ( ext_sem = sem_alloc( 1, NULL ) ) == RES_VOID )
  {
    while( true )
      asm( " nop " );
  }
}
// ---------------------------------------------------------------------------
int32 os_extension_plug( s_os_extension* e, uint32 scall_index, void* function, const char* name )
{
  if( e == NULL ) return EXT_ER_NULL_PARAM;
  sem_lock( ext_sem, SEM_INFINITY );

  if( scall_index != EXT_DYNAMIC )
  {
    if( scall_index > SYSCALL__COUNT__ )
    {
      sem_unlock( ext_sem );
      return EXT_ER_BAD_SYSCALL_INDEX;
    }
    if( __os_syscall_table__[scall_index] != (void*)(uint32)&os_syscall_sfault_vector )
    {
      sem_unlock( ext_sem );
      return EXT_ER_SYSCALL_REGISTERED;
    }
  }
  else
  {
    if( name == NULL )
    {
      sem_unlock( ext_sem );
      return EXT_ER_NULL_PARAM;
    }
  }

  memset( e, 0, sizeof(s_os_extension) );

  if( ext_last == NULL )
  {
    ext_first = e;
    ext_last = e;
  }
  else
  {
    e->prev = ext_last;
    ext_last->next = e;
    ext_last = e;
  }
  e->own_process = v_os_current_process->id;
  e->syscall_vector = scall_index;
  e->function = function;
  e->name = name;
  __os_syscall_table__[scall_index] = function;

  sem_unlock( ext_sem );
  return EXT_OK;
}
// ---------------------------------------------------------------------------
int32 os_extension_unplug( s_os_extension* e )
{
  s_os_extension* cext;

  if( e == NULL ) return EXT_ER_NULL_PARAM;
  sem_lock( ext_sem, SEM_INFINITY );

  cext = ext_first;
  while( cext )
  {
    if( cext == e )
    {
      if( cext->usage != 0 )
      {
        sem_unlock( ext_sem );
        return EXT_ER_LOCKED;
      }
      if( e->syscall_vector ) __os_syscall_table__[e->syscall_vector] = (void*)(uint32)&os_syscall_sfault_vector;
      if( e->next ) e->next->prev = e->prev; else ext_last = e->prev;
      if( e->prev ) e->prev->next = e->next; else ext_first = e->next;
      sem_unlock( ext_sem );
      return EXT_OK;
    }
    cext = cext->next;
  }

  sem_unlock( ext_sem );
  os_sfault( OSSF_BAD_DESCRIPTOR );
  return EXT_ER_SEGFAULT; // It's never happens!
}
// ---------------------------------------------------------------------------
void* os_extension_lock( const char* name )
{
  if( name == NULL ) return NULL;
  sem_lock( ext_sem, SEM_INFINITY );
  
  s_os_extension* cext = ext_first;
  while( cext )
  {
    if( strcmp( cext->name, name ) == 0 )
    {
      if( cext->usage < 65535 )
      {
        cext->usage++;
        sem_unlock( ext_sem );
        return cext->function;
      }
      break;
    }
    cext = cext->next;
  }

  sem_unlock( ext_sem );
  return NULL;
}
// ---------------------------------------------------------------------------
int32 os_extension_unlock( const char* name, void* func )
{
  bool eqr;

  if( ( func == NULL ) && ( name == NULL ) ) return EXT_ER_NULL_PARAM;
  sem_lock( ext_sem, SEM_INFINITY );

  s_os_extension* cext = ext_first;
  while( cext )
  {
    eqr = false;
    if( name ) eqr = ( strcmp( cext->name, name ) == 0 );
    else eqr = ( cext->function == func );
    if( eqr )
    {
      if( cext->usage > 0 )
      {
        cext->usage--;
        sem_unlock( ext_sem );
        return EXT_OK;
      }
      break;
    }
    cext = cext->next;
  }

  sem_unlock( ext_sem );
  return NULL;
}
// ---------------------------------------------------------------------------
int32 os_extension_check( uint32 scall_index, const char* name )
{
  if( ( scall_index == EXT_DYNAMIC ) && ( name == NULL ) ) return OSE_NULL_PARAM;
  sem_lock( ext_sem, SEM_INFINITY );

  if( scall_index != EXT_DYNAMIC )
  {
    if( scall_index >= SYSCALL__COUNT__ )
    {
      sem_unlock( ext_sem );
      return OSE_NO_EXTENSION;
    }
    if( (uint32)__os_syscall_table__[scall_index] == (uint32)&os_syscall_sfault_vector )
    {
      sem_unlock( ext_sem );
      return OSE_NO_EXTENSION;
    }
    sem_unlock( ext_sem );
    return OSE_OK;
  }
  else
  {
    s_os_extension* cext = ext_first;
    while( cext )
    {
      if( strcmp( cext->name, name ) == 0 )
      {
        sem_unlock( ext_sem );
        return OSE_OK;
      }
      cext = cext->next;
    }
  }

  sem_unlock( ext_sem );

  return OSE_NO_EXTENSION;
}
// ---------------------------------------------------------------------------
*/
