/**********************************************************************************************************************
*                                        (c) COPYRIGHT by ZAO RCZI FORT.                                             *
*        ..                                       All rights reserved.                                               *
***********************************************************************************************************************
* Module      : drv_vfat.trigger.cpp
* Description : 
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
#include <os.h>
#include <__fs.h>
#include <rts.h>
#include <drv_vfat.h>
// ---------------------------------------------------------------------------


struct s_vfat_context
{
  OLD_FILE*                     f;
};

// ---------------------------------------------------------------------------

static uint32 fs_reinit_sem = RES_VOID;
static uint32 fs_sem1 = RES_VOID;
static uint32 fs_sem0 = RES_VOID;
static uint32 fs_sem = RES_VOID;

// ---------------------------------------------------------------------------
int32 drv_vfat_trigger_open( s_os_driver_descriptor* d, uint16 access )
{
  FS_UINT16 mode = 0;
  OLD_FILE* fd = ((s_vfat_context*)d->data)->f;
  if( ((FATFileData*)fd->data)->attributes & FAT_ATTR_DIR ) return OSE_FAIL;
  access &= DRV_RD | DRV_WR;
  if( access & DRV_RD ) mode |= FL_READ;
  if( access & DRV_WR ) mode |= FL_WRITE;
  if( fd->open( mode ) != FS_OK ) return OSE_FAIL;
  d->access = access | DRV_OPENED;
  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 drv_vfat_trigger_close( s_os_driver_descriptor* d )
{
  OLD_FILE* fd = ((s_vfat_context*)d->data)->f;
  if( !( d->access & DRV_OPENED ) ) return OSE_OK;
  fd->close();
  d->access = 0;
  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 drv_vfat_trigger_read( s_os_driver_descriptor* d, void* buf, int32 length )
{
  OLD_FILE* fd = ((s_vfat_context*)d->data)->f;
  if( !( d->access & DRV_OPENED ) ) return OSE_STREAM_NOT_OPENED;
  if( !( d->access & DRV_RD ) ) return OSE_PERMISSION_DENIED;
  if( fd->read( buf, length ) != FS_OK ) return OSE_FAIL;
  return fd->getRWCounter();
}
// ---------------------------------------------------------------------------
int32 drv_vfat_trigger_write( s_os_driver_descriptor* d, const void* buf, int32 length )
{
  OLD_FILE* fd = ((s_vfat_context*)d->data)->f;
  if( !( d->access & DRV_OPENED ) ) return OSE_STREAM_NOT_OPENED;
  if( !( d->access & DRV_WR ) ) return OSE_PERMISSION_DENIED;
  if( fd->write( const_cast<void*>( buf ), length ) != FS_OK ) return OSE_FAIL;
  return fd->getRWCounter();
}
// ---------------------------------------------------------------------------
static int32 new_inode( s_inode*& list, FileInfo* frec )
{
  s_inode* node;

  if( strcmp( frec->name, "." ) == 0 ) return OSE_OK;
  if( strcmp( frec->name, ".." ) == 0 ) return OSE_OK;

  node = new s_inode;
  if( node == NULL ) return OSE_NO_MEMORY;
  memset( node, 0, sizeof(s_inode) );
  node->name = new char[strlen(frec->name)+1];
  if( node->name == NULL )
  {
    heap_free( NULL, node );
    return OSE_NO_MEMORY;
  }
  strcpy( node->name, frec->name );

  _mem8( &node->size ) = (uint64)frec->size;
  node->mktime = frec->createTime;
  if( frec->attr & FAT_ATTR_DIR )
  {
    node->type = INOT_FOLDER;
    node->access = ACC_FULL_FOLDER;
  }
  else
  {
    node->type = INOT_FILE;
    node->access = ACC_FULL_FILE;
  }

  if(list == NULL)
  {    
    node->next = NULL;
    list = node;
  }
  else
  {
    node->next = list;
    list->prev = node;
    list = node;
  }
  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 drv_vfat_trigger_ioctl( s_os_driver_descriptor* d, int32 cmd, const void* arg )
{
  switch( cmd )
  {
    case IOC_INIT_DESCRIPTOR:
    {
      d->data = (s_vfat_context*)heap_alloc( NULL, sizeof(s_vfat_context), HEAP_ALIGN_4 );
      if( d->data == NULL ) return OSE_NO_MEMORY;
      s_vfat_context* ctx = (s_vfat_context*)d->data;
      ctx->f = new OLD_FILE();
      if( ctx->f == NULL )
      {
        heap_free( NULL, d->data );
        d->data = NULL;
        return OSE_NO_MEMORY;
      }
    }
    break;

    case IOC_DEINIT_DESCRIPTOR:
    {
      s_vfat_context* ctx = (s_vfat_context*)d->data;
      delete ctx->f;
      heap_free( NULL, d->data );
      d->data = NULL;
    }
    break;

    case IOC_EOF:
    {
      FS_BOOL state;
      s_vfat_context* ctx = (s_vfat_context*)d->data;
      if( arg == NULL ) return OSE_NULL_PARAM;
      if( ( d->access & DRV_OPENED ) == 0 ) return OSE_STREAM_NOT_OPENED;
      if( ctx->f->eof( &state ) != FS_OK ) return OSE_FAIL;
      int32* carg = (int32*)const_cast<void*>( arg );
      (*carg) = state ? 1 : 0;
    }
    break;

    case IOC_SEEK:
    {
      if( arg == NULL ) return OSE_NULL_PARAM;
      s_vfat_context* ctx = (s_vfat_context*)d->data;
      if( ( d->access & DRV_OPENED ) == 0 ) return OSE_STREAM_NOT_OPENED;
      int64* carg = (int64*)const_cast<void*>( arg );
      if( ctx->f->seek( (FS_INT32)_mem8( carg ), 0 ) != FS_OK ) return OSE_FAIL;
    }
    break;

    case IOC_SIZE:
    {
      FS_UINT32 s;
      if( arg == NULL ) return OSE_NULL_PARAM;
      s_vfat_context* ctx = (s_vfat_context*)d->data;
      if( ctx->f->size( &s ) != FS_OK ) return OSE_FAIL;
      int64* carg = (int64*)const_cast<void*>( arg );
      _mem8( carg ) = (int64)s;
    }
    break;

    case IOC_POSITION:
    {
      FS_UINT32 off;
      if( arg == NULL ) return OSE_NULL_PARAM;
      s_vfat_context* ctx = (s_vfat_context*)d->data;
      if( ( d->access & DRV_OPENED ) == 0 ) return OSE_STREAM_NOT_OPENED;
      if( ctx->f->tell( &off ) != FS_OK ) return OSE_FAIL;
      int64* carg = (int64*)const_cast<void*>( arg );
      _mem8( carg ) = (int64)off;
    }
    break;

    case IOC_RESIZE:
    {
      FS_UINT32 s, off;
      if( arg == NULL ) return OSE_NULL_PARAM;
      OLD_FILE* fd = ((s_vfat_context*)d->data)->f;
      if( ( d->access & DRV_OPENED ) == 0 ) return OSE_STREAM_NOT_OPENED;
      if( !( d->access & DRV_WR ) ) return OSE_PERMISSION_DENIED;
      int64* carg = (int64*)const_cast<void*>( arg );
      if( fd->size( &s ) != FS_OK ) return OSE_FAIL;
      if( (int64)s < _mem8( carg ) )
      {
        if( fd->tell( &off ) != FS_OK ) return OSE_FAIL;
        if( fd->seek( (FS_UINT32)_mem8( carg ), 0 ) != FS_OK ) return OSE_FAIL;
        if( fd->seek( off, 0 ) != FS_OK ) return OSE_FAIL;
      }
      else
      {
        if( fd->trim( (FS_UINT32)_mem8( carg ) ) != FS_OK ) return OSE_FAIL;
      }
    }
    break;

    case IOC_INODE_LIST:
    {
      FileInfo frec;

      if( arg == NULL ) return OSE_NULL_PARAM;
      OLD_FILE* fd = ((s_vfat_context*)d->data)->f;
      if( d->access & DRV_OPENED ) return OSE_STREAM_OPENED;
      s_inode*& list = (*((s_inode**)const_cast<void*>( arg )));

      if( !fd->data->isRoot() )
      {
        FS_REINIT_LOCK();
        dev.reInitLogicDisks( d->path[6] );
        FS_REINIT_UNLOCK();
      }
      else
      {
        dev.reInit();
      }

      list = NULL;

      if( fd->findFirst( "*", 0, &frec ) == 0 )
      {
        if( ( frec.attr & FAT_ATTR_LABLE ) == 0 )
        {
          if( new_inode( list, &frec ) != OSE_OK )
          {
            fd->findClose();
            return OSE_NO_MEMORY;
          }
        }
      }

      while( true )
      {
        if( fd->findNext( &frec ) == 0 )
        {
          if( ( frec.attr & FAT_ATTR_LABLE ) == 0 )
          {
            if( new_inode( list, &frec ) != OSE_OK )
            {
              drv_list_destroy( list );
              list = NULL;
              fd->findClose();
              return OSE_NO_MEMORY;
            }
          }
          continue;
        }
        break;
      }

      fd->findClose();
    }
    break;

    case IOC_INODE_SELECT:
    {
      if( arg == NULL ) return OSE_NULL_PARAM;
      char* carg = (char*)const_cast<void*>( arg );
      OLD_FILE* fd = ((s_vfat_context*)d->data)->f;
      if( d->access & DRV_OPENED ) return OSE_STREAM_OPENED;
      if( strcmp( carg, "." ) == 0 )
      {
        break;
      }
      else if( strcmp( carg, ".." ) == 0 )
      {
        drv_dec( d );
        if( fd->data->isRoot() )
        {
          drv_rfs( d );
        }
        else
        {
          return ( fd->switchObjectTo( carg ) == FS_OK ) ? OSE_OK : OSE_FAIL;
        }
      }
      else
      {
        bool rd = false;
        if( fd->data->isRoot() )
        {
          FS_REINIT_LOCK();
          dev.reInitLogicDisks( carg[0] );
          FS_REINIT_UNLOCK();
          rd = true;
        }
        if( fd->switchObjectTo( carg ) != FS_OK ) return OSE_NO_NODE;
        if( rd ) fd->cflush();
        drv_inc( d, carg );
      }
    }
    break;

    case IOC_INODE_CREATE:
    {
      FS_UINT32 attr = 0;
      if( arg == NULL ) return OSE_NULL_PARAM;
      s_vfat_context* ctx = (s_vfat_context*)d->data;
      if( d->access & DRV_OPENED ) return OSE_STREAM_OPENED;
      s_inode_create* carg = (s_inode_create*)const_cast<void*>( arg );
      if( carg->type == INOT_FOLDER ) attr = FAT_ATTR_DIR;
      if( ctx->f->createObject( const_cast<char*>( carg->name ), attr ) != FS_OK ) return OSE_FAIL;
    }
    break;

    case IOC_INODE_REMOVE:
    {
      uint32 attr;
      if( arg == NULL ) return OSE_NULL_PARAM;
      File* fd = ((s_vfat_context*)d->data)->f;
      if( d->access & DRV_OPENED ) return OSE_STREAM_OPENED;
      char* carg = (char*)const_cast<void*>( arg );
      if( fd->data->isRoot() ) return OSE_FAIL;
      if( fd->switchObjectTo( carg ) != FS_OK ) return OSE_FAIL;
      attr = ((FATFileData*)fd->data)->attributes;
      fd->switchObjectTo( ".." );
      if( attr & FAT_ATTR_DIR )
      {
        if( fd->rmdir( carg ) != FS_OK ) return OSE_FAIL;
      }
      else
      {
        if( fd->rmfile( carg ) != FS_OK ) return OSE_FAIL;
      }
    }
    break;
    
    case IOC_INODE_RENAME:
    {
      if( arg == NULL ) return OSE_NULL_PARAM;
      File* fd = ((s_vfat_context*)d->data)->f;
      if( d->access & DRV_OPENED ) return OSE_STREAM_OPENED;
      char* newpath = ((char*)const_cast<void*>( arg ))+5;//Обрезаем /vfat
      if( fd->data->isRoot() ) return OSE_FAIL;
      if( newpath == NULL ) return OSE_FAIL;

      if( fd->rename( newpath ) != 0 )
        return OSE_FAIL; 

      return OSE_OK;
    }

    case IOC_INIT:
    {
      dev.reInit();
    }
    break;

    case IOC_DEINIT:
    {
      /* Nothing */
    }
    break;

    case FSI_TYPE:
    {
      if( arg == NULL ) return OSE_NULL_PARAM;
      s_vfat_context* ctx = (s_vfat_context*)d->data;
      s_vfat_info* carg = (s_vfat_info*)const_cast<void*>( arg );
      carg->type = ctx->f->fsType();
    }
    break;

    case FSI_FORMAT:
    {
      if( arg == NULL ) return OSE_NULL_PARAM;
	  FS_ST_USBDEV dev;      
      s_vfat_format* carg = (s_vfat_format*)arg;
      OLD_FILE* fd = ((s_vfat_context*)d->data)->f;      
      if( fd->stUsbDev(&dev) != FS_OK )
        return OSE_FAIL;      
      if( FormatFlash( dev, carg->func, carg->arg ) != 0 )
        return OSE_FAIL;
    }
    break;
    
    case FSI_RESET:
    {
      FS_REINIT_LOCK();
      dev.resetAllApplPipe();
      FS_REINIT_UNLOCK();
    }
    break;        

    default:
      return OSE_BAD_CMD;
  }

  return OSE_OK;
}

/*****************************************************************************
Syntax: int32 drv_vfat_trigger_plug()    	    
Remarks:			    
*******************************************************************************/
int32 drv_vfat_trigger_plug()
{
  return drv_plug( "/vfat", INOT_FOLDER, &drv_vfat_trigger_open, &drv_vfat_trigger_close, &drv_vfat_trigger_read, &drv_vfat_trigger_write, &drv_vfat_trigger_ioctl, NULL, 0 );
}
// ---------------------------------------------------------------------------
int32 drv_vfat_trigger_unplug()
{
  return drv_unplug( "vfat" );
}
// ---------------------------------------------------------------------------
void FS_LOCK_INIT()
{
  fs_reinit_sem = sem_alloc( 1, NULL );
  fs_sem = sem_alloc( 1, NULL );
  fs_sem0 = sem_alloc( 1, NULL );
  fs_sem1 = sem_alloc( 1, NULL );
}
// ---------------------------------------------------------------------------
void FS_REINIT_UNLOCK()
{
  sem_unlock( fs_reinit_sem );
}
// ---------------------------------------------------------------------------
void FS_REINIT_LOCK()
{
  sem_lock( fs_reinit_sem, SEM_INFINITY );
}
// ---------------------------------------------------------------------------
void FS_LOCK()
{
  sem_lock( fs_sem, SEM_INFINITY );
}
// ---------------------------------------------------------------------------
void FS_UNLOCK()
{
  sem_unlock( fs_sem );
}
// ---------------------------------------------------------------------------
void FS_LOCK0()
{
  sem_lock( fs_sem0, SEM_INFINITY );
}
// ---------------------------------------------------------------------------
void FS_UNLOCK0()
{
  sem_unlock( fs_sem0 );
}
// ---------------------------------------------------------------------------
void FS_LOCK1()
{
  sem_lock( fs_sem1, SEM_INFINITY );
}
// ---------------------------------------------------------------------------
void FS_UNLOCK1()
{
  sem_unlock( fs_sem1 );
}
// ---------------------------------------------------------------------------
