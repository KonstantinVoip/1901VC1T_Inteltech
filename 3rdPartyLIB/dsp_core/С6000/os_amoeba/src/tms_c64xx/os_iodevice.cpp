// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: all
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp866
// !: d:
// !: -:
// ---------------------------------------------------------------------------
#define SYSCALL_DIRECT
#include <os.h>
// ---------------------------------------------------------------------------

s_os_iodevice* indev_first;
s_os_iodevice* indev_last;

s_os_iodevice* outdev_first;
s_os_iodevice* outdev_last;

uint32 iodevice_sem;

// ---------------------------------------------------------------------------
void os_iodevice_init_module()
{
  indev_first = NULL;
  indev_last = NULL;
  outdev_first = NULL;
  outdev_last = NULL;
  if( ( iodevice_sem = sem_alloc( 1, NULL ) ) == RES_VOID )
  {
    while( true )
      asm( " nop " );
  }
}
// ---------------------------------------------------------------------------
void os_iodevice_cleanup()
{
}
// ---------------------------------------------------------------------------
int32 os_iodevice_cmd( const char* dev, int32 cmd, void* arg )
{
  uint32 d = drv_mkd( dev );
  if( d == RES_VOID ) return IOD_ER_CANT_OPEN_DEVICE;
  drv_ioctl( d, cmd, arg );
  drv_rmd( d );
  return IOD_OK;
}
// ---------------------------------------------------------------------------
int32 os_iodevice_reg( const char* dev, uint32 type )
{
  s_os_iodevice* ndev;
  int32 r = IOD_OK;

  if( dev == NULL ) return IOD_ER_NULL_PARAM;

  ndev = (s_os_iodevice*)heap_alloc( NULL, sizeof(s_os_iodevice), HEAP_ALIGN_4 );
  if( ndev == NULL ) return IOD_ER_NO_MEM;
  memset( ndev, 0, sizeof(s_os_iodevice) );

  ndev->path = (char*)heap_alloc( NULL, strlen( dev ) + 1, HEAP_ALIGN_4 );
  if( ndev->path == NULL )
  {
    heap_free( NULL, ndev );
    return IOD_ER_NO_MEM;
  }
  strcpy( ndev->path, dev );

  sem_lock( iodevice_sem, SEM_INFINITY );
  if( type == IODT_INPUT )
  {
    if( indev_first == NULL )
    {
      indev_first = ndev;
      indev_last = ndev;
    }
    else
    {
      indev_last->next = ndev;
      ndev->prev = indev_last;
      indev_last = ndev;
    }
  }
  else if( type == IODT_OUTPUT )
  {
    if( indev_first == NULL )
    {
      outdev_first = ndev;
      outdev_last = ndev;
    }
    else
    {
      outdev_last->next = ndev;
      ndev->prev = outdev_last;
      outdev_last = ndev;
    }
  }
  else
  {
    r = IOD_ER_BAD_TYPE;
  }
  sem_unlock( iodevice_sem );

  return r;
}
// ---------------------------------------------------------------------------
int32 os_iodevice_unreg( const char* dev, uint32 type )
{
}
// ---------------------------------------------------------------------------
int32 os_idev_select( const char* con, const char* dev )
{
  s_os_console* ncon;
  s_os_iodevice* cdev;

  if( ( con == NULL ) || ( dev == NULL ) ) return IOD_ER_NULL_PARAM;

  ncon = (s_os_console*)heap_alloc( NULL, sizeof(s_os_console), HEAP_ALIGN_4 );
  if( ncon == NULL ) return IOD_ER_NO_MEM;
  memset( ncon, 0, sizeof(s_os_console) );
  ncon->path = (char*)heap_alloc( NULL, strlen( con ) + 1, HEAP_ALIGN_4 );
  if( ncon->path == NULL )
  {
    heap_free( NULL, ncon );
    return IOD_ER_NO_MEM;
  }
  strcpy( ncon->path, con );

  sem_lock( iodevice_sem, SEM_INFINITY );
  cdev = indev_first;
  while( cdev )
  {
    if( strcmp( cdev->path, dev ) == NULL )
    {
      int32 r = IOD_OK;
      if( cdev->active == NULL )
      {
        cdev->active = ncon;
// todo        r = os_iodevice_cmd( ncon->path, IOC_CON_ACTIVATE, NULL );
      }
      else
      {
        ncon->prev = cdev->active->prev;
        ncon->next = cdev->active;
        cdev->active->prev->next = ncon;
        cdev->active->prev = ncon;
      }
      cdev->con_count++;
      sem_unlock( iodevice_sem );

// todo      if( r == 0 ) r = os_iodevice_cmd( ncon->path, IOC_CON_ATTACH_IDEV, cdev->path );

      return r;
    }
    cdev = cdev->next;
  }
  sem_unlock( iodevice_sem );

  heap_free( NULL, ncon->path );
  heap_free( NULL, ncon );

  return IOD_ER_NO_DEVICE;
}
// ---------------------------------------------------------------------------
int32 os_idev_switch( int32 cnum )
{
}
// ---------------------------------------------------------------------------
int32 os_odev_select( const char* con, const char* dev )
{
}
// ---------------------------------------------------------------------------
