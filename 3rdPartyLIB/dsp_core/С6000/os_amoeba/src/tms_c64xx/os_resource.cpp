// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp866
// !: d: Модуль содержит реализацию менеджера ресурсов.
// !: -:
// ---------------------------------------------------------------------------
#define SYSCALL_DIRECT
#include <os.h>
// ---------------------------------------------------------------------------

/* SM
static s_resource_table         grdt[16];
*/

// ---------------------------------------------------------------------------
/* SM
void os_resource_init_module()
{
  memset( grdt, 0, sizeof(grdt) );
  for( uint32 i = 0; i < 16; i++ )
  {
    if( ( grdt[i].sem = sem_alloc( 1, NULL ) ) == RES_VOID )
    {
      while( true )
        asm( " nop " );
    }
  }
}
*/
// ---------------------------------------------------------------------------
/* SM
void os_resource_grdt_set( uint32 res_type, void*)
{
  memset( grdt, 0, sizeof(grdt) );
  for( uint32 i = 0; i < 16; i++ )
  {
    if( ( grdt[i].sem = sem_alloc( 1, NULL ) ) == RES_VOID )
    {
      while( true )
        asm( " nop " );
    }
  }
}
*/
// ---------------------------------------------------------------------------
// !: fn: int32 os_resource_share( uint32 rid )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall псевдоним:</b><br>
// !: d: <br>
// !: d: res_share<br>
// !: d: <br>
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция расширяет права доступа к ресурсу rid до общих.<br>
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: В случае успеха функция возвращает OSE_OK, иначе код ошибки.
// !: d: 
// ---------------------------------------------------------------------------
int32 os_resource_share( uint32 rid )
{
  uint32 index;
  register uint32 is;

  is = int_disable();

  switch( rid & RES_T_MASK )
  {
    case RES_T_INTERRUPT:
    {
      index = os_interrupt_check( rid );
      if( index == 0xffffffff )
      {
        int_enable( is );
        return OSE_BAD_RDESC;
      }
      v_os_interrupt_table[index].id |= RES_F_SHARED;
    }
    break;

    case RES_T_SEMAPHORE:
    {
      index = os_semaphore_check( rid );
      if( index == 0xffffffff )
      {
        int_enable( is );
        return OSE_BAD_RDESC;
      }
      v_os_semaphore_list[index]->id |= RES_F_SHARED;
    }
    break;
    
    case RES_T_FSDESCRIPTOR:
    {
      index = os_driver_descriptor_check( rid );
      if( index == 0xffffffff )
      {
        int_enable( is );
        return OSE_BAD_RDESC;
      }
      v_os_desc_list[index]->id |= RES_F_SHARED;
    }
    break;

    case RES_T_MSGPIPE:
      break;

    default:
    {
      int_enable( is );
      return OSE_BAD_RESOURCE_TYPE;
    }
  }

  int_enable( is );

  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 os_resource_unshare( uint32 rid )
{
  return 0;
}
// ---------------------------------------------------------------------------
int32 os_resource_shared( uint32 rid )
{
  return 0;
}
// ---------------------------------------------------------------------------
int32 os_resource_chown( uint32 rid, uint16 pid )
{
  register volatile uint32 index;
  register uint32 is;
  register s_os_process_context* cprc;
  int32 i;

  is = int_disable();

  index = 0;
  cprc = v_os_current_process;
  for( i = 0; i < v_os_process_count; i++, cprc = cprc->next )
  {
    if( cprc->id == pid )
    {
      index = 1;
      break;
    }
  }
  if( index == 0 )
  {
    int_enable( is );
    return OSE_NO_PROCESS;
  }

  switch( rid & RES_T_MASK )
  {
    case RES_T_SEMAPHORE:
    {
      index = os_semaphore_check( rid );
      if( index == 0xffffffff )
      {
        int_enable( is );
        return OSE_BAD_RDESC;
      }
      v_os_semaphore_list[index]->own_process = pid;
    }
    break;

    default:
    {
      int_enable( is );
      return OSE_BAD_RESOURCE_TYPE;
    }
  }

  int_enable( is );

  return OSE_OK;
}
// ---------------------------------------------------------------------------
/*
// ---------------------------------------------------------------------------

s_resource_table                resource_table;

// ---------------------------------------------------------------------------
void os_resource_init_module( int32 stage )
{
  if( stage == 0 )
  {
    memset( &resource_table, 0, sizeof(resource_table) );
  }
  else if( stage == 1 )
  {
    if( ( resource_table.sem = sem_alloc( 1, NULL ) ) == RES_VOID )
      os_core_panic( OSE_CANT_CREATE_SEMAPHORE );
  }
}
// ---------------------------------------------------------------------------
int32 os_resource_reg_pool( uint32 ptype, s_resource_pool* p )
{
  ptype &= RES_T__MASK__;
  if( ptype == 0 ) return OSE_BAD_RESOURCE_TYPE;
  ptype = ( ptype >> 28 ) - 1;

  sem_lock( resource_table.sem, OS_INFINITY );
  
  if( resource_table.tab[ptype] != NULL ) return OSE_RESOURCE_POOL_BUSY;
  resource_table.tab[ptype] = p;
  
  sem_unlock( rpool.sem );
  
  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 os_resource_map( uint32* lrid, uint32 grid )
{
//todo
}
// ---------------------------------------------------------------------------
int32 os_resource_unmap( uint32 rid )
{
//todo
}
// ---------------------------------------------------------------------------
int32 os_resource_reg( uint32* grid, uint32 rtype, s_resource* r )
{
  s_resource_pool* tab;
  s_resource** pool;
  int32 i;

  if( ( grid == NULL ) || ( r == NULL ) ) return OSE_NULL_PARAM;

  rtype &= RES_T__MASK__;
  if( rtype == 0 ) return OSE_BAD_RESOURCE_TYPE;
  tab = resource_table.tab[(rtype>>28)-1];
  if( tab == NULL ) return OSE_BAD_RESOURCE_TYPE;
  pool = tab->pool;

  sem_lock( tab->sem, OS_INFINITY );

  for( i = 0; i < tab->pool_size; i++ ) if( pool[i] == NULL ) break;
  if( i == tab->pool_size )
  {
    if( tab->pool_expand )
      tab->pool_expand();
    else
      return OSE_RESOURCE_LIMIT_REACHED;
  }
  pool[i] = r;

  sem_unlock( tab->sem );

  (*grid) = rtype | (uint32)i;
  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 os_resource_unreg( uint32 grid )
{
  int32 r, index;
  s_resource_pool* tab;
  s_resource** pool;

  if( ( grid & RES_T__MASK__ ) == 0 ) return OSE_BAD_RESOURCE_TYPE;
  tab = resource_table.tab[(grid>>28)-1];
  if( tab == NULL ) return OSE_BAD_RESOURCE_TYPE;
  pool = tab->pool;
  index = (int32)( grid & RES_I__MASK__ );

  sem_lock( tab->sem, OS_INFINITY );

  if( pool[index] == NULL )
  {
    r = OSE_BAD_RESOURCE_INDEX;
  }
  else
  {
    r = OSE_OK;
    pool[index] = NULL;
  }

  sem_unlock( tab->sem );

  return r;
}
// ---------------------------------------------------------------------------
int32 os_resource_require( uint32 grid, uint32 rtype, uint32 action, s_resource** r )
{
  
// todo
//  return OSE_OK;
}
// ---------------------------------------------------------------------------
*/

