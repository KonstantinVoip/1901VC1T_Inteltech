/**********************************************************************************************************************
*                                        (c) COPYRIGHT by ZAO RCZI FORT.                                             *
*        ..                                       All rights reserved.                                               *
***********************************************************************************************************************
* Module      : drv_dbgout.cpp
* Description : Отладочный Вывод
* Author      : 
******************************************************************************
******************************************************************************
* Module's Description Record:
* ============================
* Module's revision history:
* ==========================
* --------- $Log:  $
* --------- Initial revision
******************************************************************************/
#include <drv_dbgout.h>
#include <os.h>
// ---------------------------------------------------------------------------



uint8 _CIOBUF_[256];
uint32 dbgout_sem = RES_VOID;
int32 dbgout_buf_offset = 0;

// ---------------------------------------------------------------------------
void dbgout_wmsg()
{
  memset( _CIOBUF_, 0, 13 );
  (*(int32*)_CIOBUF_) = dbgout_buf_offset;
  _CIOBUF_[4] = 0xf3;
  _CIOBUF_[5] = 1;
  _CIOBUF_[7] = dbgout_buf_offset;
  __asm( "     .global C$$IO$$  " );
  __asm( "     nop              " );
  __asm( "C$$IO$$:nop           " );
}
// ---------------------------------------------------------------------------
int32 dbgout_open( s_os_driver_descriptor* d, uint16 access )
{
  d->access = DRV_OPENED | DRV_WR;
  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 dbgout_close( s_os_driver_descriptor* d )
{
  d->access = 0;
  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 dbgout_read( s_os_driver_descriptor* d, void* buf, int32 length )
{
  return OSE_PERMISSION_DENIED;
}
// ---------------------------------------------------------------------------
int32 dbgout_write( s_os_driver_descriptor* d, const void* buf, int32 length )
{
  char* b = (char*)const_cast<void*>( buf );

  sem_lock( dbgout_sem, SEM_INFINITY );

  for( int32 i = 0; i < length; i++ )
  {
    if( b[i] != '\xff' )
    {
      _CIOBUF_[dbgout_buf_offset+13] = b[i];
      dbgout_buf_offset++;
    }
    if( ( dbgout_buf_offset == 243 ) || ( b[i] == '\n' ) || ( b[i] == '\xff' ) )
    {
      dbgout_wmsg();
      dbgout_buf_offset = 0;
    }
  }

  sem_unlock( dbgout_sem );

  return length;
}
// ---------------------------------------------------------------------------
int32 dbgout_ioctl( s_os_driver_descriptor* d, int32 cmd, const void* arg )
{
  switch( cmd )
  {
    case IOC_INIT_DESCRIPTOR:
    case IOC_DEINIT_DESCRIPTOR:
    case IOC_RESIZE:
      break;

    case IOC_SIZE:
    {
      if( arg == NULL ) return OSE_BAD_PARAM;
      int64* carg = (int64*)const_cast<void*>( arg );
      (*carg) = 0ull;
    }
    break;

    case IOC_INIT:
    {
      dbgout_sem = sem_alloc( 1, NULL );
    }
    break;

    case IOC_DEINIT:
    {
      sem_free( dbgout_sem );
    }
    break;

    case IOC_INODE_SELECT:
    {
      if( d->access != 0 ) return OSE_STREAM_OPENED;
      if( arg == NULL ) return OSE_BAD_PARAM;
      char* dst = (char*)const_cast<void*>( arg );
      if( strcmp( dst, "." ) == 0 ) break;
      if( strcmp( dst, ".." ) != 0 ) return OSE_NO_NODE;
      drv_dec( d );
      drv_rfs( d );
    }
    break;

    default:
      return OSE_BAD_CMD;
  }

  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 drv_dbgout_plug()
{
  return drv_plug( "/dev/dbgout", INOT_FILE, &dbgout_open, &dbgout_close, &dbgout_read, &dbgout_write, &dbgout_ioctl, NULL, 0 );
}
// ---------------------------------------------------------------------------
int32 drv_dbgout_unplug()
{
  return drv_unplug( "dbgout" );
}
// ---------------------------------------------------------------------------
