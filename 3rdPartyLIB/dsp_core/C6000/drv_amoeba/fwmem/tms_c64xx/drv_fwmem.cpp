/**********************************************************************************************************************
*                                        (c) COPYRIGHT by ZAO RCZI FORT.                                             *
*        ..                                       All rights reserved.                                               *
***********************************************************************************************************************
* Module      :drv_fwmem.cpp
* Description : 
* Author      : 
******************************************************************************
******************************************************************************
* Module's Description Record:
* ============================
* Module's revision history:
* ==========================
* --------- $Log: mpcdrvlbcCyclone.h $
* --------- Initial revision
******************************************************************************/
#include <drv_fwmem.h>
#include <os.h>
#include <rts.h>
// ---------------------------------------------------------------------------

struct s_fwmem_data
{
  uint32                        position;
  uint32                        offset;
  s_fwmem_record                record;
  uint32                        record_offset;
};

// ---------------------------------------------------------------------------
int32 fwmem_open( s_os_driver_descriptor* d, uint16 access )
{
  if( access != DRV_RD ) return OSE_PERMISSION_DENIED;
  d->access = DRV_OPENED | DRV_RD;
  s_fwmem_data* cdata = (s_fwmem_data*)d->data;
  cdata->position = 0;
  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 fwmem_close( s_os_driver_descriptor* d )
{
  if( ( d->access & DRV_OPENED ) == 0 ) return OSE_STREAM_NOT_OPENED;
  d->access = 0;
  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 fwmem_read( s_os_driver_descriptor* d, void* buf, int32 length )
{
  int32 l, r;
  s_fwmem_data* cdata;
  s_fwmem_context* dctxdata = (s_fwmem_context*)d->ctx->data;

  if( ( d->access & DRV_OPENED ) == 0 ) return OSE_STREAM_NOT_OPENED;
  if( buf == NULL ) return OSE_NULL_PARAM;
  if( length < 0 ) return OSE_BAD_PARAM;
  if( length == 0 ) return 0;

  l = length;
  cdata = (s_fwmem_data*)d->data;
  if( ( cdata->position + l ) > _mem4( &cdata->record.length ) ) l = _mem4( &cdata->record.length ) - cdata->position;
  sem_lock( dctxdata->sem, SEM_INFINITY );
  r = dctxdata->wctx->read_buffer( dctxdata, cdata->record_offset + sizeof(s_fwmem_record) + cdata->position, buf, l );
  sem_unlock( dctxdata->sem );
  if( r == OSE_OK ) cdata->position += l; else l = 0;

  return l;
}
// ---------------------------------------------------------------------------
int32 fwmem_write( s_os_driver_descriptor* d, const void* buf, int32 length )
{
  return OSE_PERMISSION_DENIED;
}
// ---------------------------------------------------------------------------
static int32 add_inode( s_inode*& list, s_fwmem_record& frec )
{
  s_inode* node;

  node = new s_inode;
  if( node == NULL ) return OSE_NO_MEMORY;
  memset( node, 0, sizeof(s_inode) );
  node->name = new char[strlen(frec.name)+1];
  if( node->name == NULL )
  {
    heap_free( NULL, node );
    return OSE_NO_MEMORY;
  }

  strcpy( node->name, frec.name );
  _mem8( &node->size ) = (uint64)frec.length;
  node->mktime = frec.mktime;
  node->access = frec.access;
  node->type = INOT_FILE;
  node->own_user = frec.own_user;
  node->own_group = frec.own_group;

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
int32 fwmem_ioctl( s_os_driver_descriptor* d, int32 cmd, const void* arg )
{
  s_fwmem_data* cdata = (s_fwmem_data*)d->data;
  s_fwmem_context* dctxdata = (s_fwmem_context*)d->ctx->data;

  switch( cmd )
  {
    case IOC_INIT:
    {
      s_os_driver_context* dctx = (s_os_driver_context*)const_cast<void*>( arg );
      s_fwmem_context* actx = (s_fwmem_context*)dctx->data;
      actx->sem = sem_alloc( 1, NULL );
      if( actx->sem == RES_VOID ) return OSE_CANT_CREATE_SEM;
      int32 r = actx->wctx->init( actx );
      if( r != OSE_OK ) return r;
    }
    break;

    case IOC_DEINIT:
    {
      s_os_driver_context* dctx = (s_os_driver_context*)const_cast<void*>( arg );
      s_fwmem_context* actx = (s_fwmem_context*)dctx->data;
      int32 r = actx->wctx->deinit( actx );
      if( r != OSE_OK ) return r;
    }
    break;

    case IOC_EOF:
    {
      if( ( d->access & DRV_OPENED ) == 0 ) return OSE_STREAM_NOT_OPENED;
      if( arg == NULL ) return OSE_NULL_PARAM;
      int32* carg = (int32*)const_cast<void*>( arg );
      (*carg) = ( cdata->position >= _mem4( &cdata->record.length ) ) ? 1 : 0;
    }
    break;

    case IOC_SEEK:
    {
      if( ( d->access & DRV_OPENED ) == 0 ) return OSE_STREAM_NOT_OPENED;
      if( arg == NULL ) return OSE_NULL_PARAM;
      int64* carg = (int64*)const_cast<void*>( arg );
      cdata->position = (uint32)(*carg);
      if( cdata->position > _mem4( &cdata->record.length ) ) cdata->position = _mem4( &cdata->record.length );
    }
    break;

    case IOC_SIZE:
    {
      if( arg == NULL ) return OSE_NULL_PARAM;
      int64* carg = (int64*)const_cast<void*>( arg );
      (*carg) = (int64)_mem4( &cdata->record.length );
    }
    break;

    case IOC_POSITION:
    {
      if( ( d->access & DRV_OPENED ) == 0 ) return OSE_STREAM_NOT_OPENED;
      if( arg == NULL ) return OSE_NULL_PARAM;
      int64* carg = (int64*)const_cast<void*>( arg );
      (*carg) = (int64)cdata->position;
    }
    break;

    case IOC_INODE_LIST:
    {
      s_fwmem_record crec;
      uint32 coffset;
      int32 r;

      if( arg == NULL ) return OSE_NULL_PARAM;
      if( d->access & DRV_OPENED ) return OSE_STREAM_OPENED;
      s_inode*& list = (*((s_inode**)const_cast<void*>( arg )));

      list = NULL;

      coffset = 1024;
      while( true )
      {
        sem_lock( dctxdata->sem, SEM_INFINITY );
        r = dctxdata->wctx->read_buffer( dctxdata, coffset, &crec, sizeof(crec) );
        sem_unlock( dctxdata->sem );
        if( r != OSE_OK ) return r;
        if( _mem4( &crec.magic ) != 0xf01ff10f ) break;

        if( ( r = add_inode( list, crec ) ) != OSE_OK )
        {
          drv_list_destroy( list );
          list = NULL;
          return r;
        }
        
        if( _mem4( &crec.next_shift ) == 0 ) break;
        coffset += _mem4( &crec.next_shift );
      }
    }
    break;

    case IOC_INODE_SELECT:
    {
      if( arg == NULL ) return OSE_NULL_PARAM;
      const char* nname = (const char*)arg;
      if( d->access & DRV_OPENED ) return OSE_STREAM_OPENED;
      if( strcmp( nname, "." ) == 0 )
      {
        break;
      }
      else if( strcmp( nname, ".." ) == 0 )
      {
        drv_dec( d );
        if( cdata->record_offset == 0 )
        {
          drv_rfs( d );
        }
        else
        {
          cdata->record_offset = 0;
        }
      }
      else
      {
        if( cdata->record_offset == 0 )
        {
          int32 r;
          s_fwmem_record crec;
          uint32 coffset = 1024;
          while( true )
          {
            sem_lock( dctxdata->sem, SEM_INFINITY );
            r = dctxdata->wctx->read_buffer( dctxdata, coffset, &crec, sizeof(crec) );
            sem_unlock( dctxdata->sem );
            if( r != OSE_OK ) return r;
            if( _mem4( &crec.magic ) != 0xf01ff10f ) break;
            if( strcmp( nname, crec.name ) == 0 )
            {
              cdata->record_offset = coffset;
              memcpy( &cdata->record, &crec, sizeof(s_fwmem_record) );
              return OSE_OK;
            }
            if( _mem4( &crec.next_shift ) == 0 ) break;
            coffset += _mem4( &crec.next_shift );
          }
        }
        return OSE_NO_NODE;
      }
    }
    break;

    case IOC_INIT_DESCRIPTOR:
    {
      d->data = heap_alloc( NULL, sizeof(s_fwmem_data), HEAP_ALIGN_4 );
      if( d->data == NULL ) return OSE_NO_MEMORY;
      cdata = (s_fwmem_data*)d->data;
      memset( cdata, 0, sizeof(s_fwmem_data) );
    }
    break;

    case IOC_DEINIT_DESCRIPTOR:
    {
      if( d->data ) heap_free( NULL, d->data );
      d->data = NULL;
    }
    break;

    case FWMEM_SECTOR_COUNT:
    {
      if( arg == NULL ) return OSE_NULL_PARAM;
      return dctxdata->wctx->sector_count( dctxdata, (uint32*)const_cast<void*>( arg ) );
    }

    case FWMEM_SECTOR_SIZE:
    {
      if( arg == NULL ) return OSE_NULL_PARAM;
      return dctxdata->wctx->sector_size( dctxdata, (s_fwmem_sector_size*)const_cast<void*>( arg ) );
    }

    case FWMEM_SECTOR_CLEAR:
    {
      if( arg == NULL ) return OSE_NULL_PARAM;
      sem_lock( dctxdata->sem, SEM_INFINITY );
      int32 r = dctxdata->wctx->sector_clear( dctxdata, (*(uint32*)const_cast<void*>( arg )) );
      sem_unlock( dctxdata->sem );
      return r;
    }

    case FWMEM_SET_OFFSET:
    {
      if( arg == NULL ) return OSE_NULL_PARAM;
      cdata->offset = (*(uint32*)const_cast<void*>( arg ));
    }
    break;

    case FWMEM_WRITE:
    {
      if( arg == NULL ) return OSE_NULL_PARAM;
      s_fwmem_rwbuf* carg = (s_fwmem_rwbuf*)const_cast<void*>( arg );
      sem_lock( dctxdata->sem, SEM_INFINITY );
      int32 r = dctxdata->wctx->write_buffer( dctxdata, cdata->offset, carg->buffer, carg->length );
      sem_unlock( dctxdata->sem );
      if( r == OSE_OK ) cdata->offset += carg->length;
      return r;
    }

    case FWMEM_READ:
    {
      if( arg == NULL ) return OSE_NULL_PARAM;
      s_fwmem_rwbuf* carg = (s_fwmem_rwbuf*)const_cast<void*>( arg );
      sem_lock( dctxdata->sem, SEM_INFINITY );
      int32 r = dctxdata->wctx->read_buffer( dctxdata, cdata->offset, carg->buffer, carg->length );
      sem_unlock( dctxdata->sem );
      if( r == OSE_OK ) cdata->offset += carg->length;
      return r;
    }

    case FWMEM_SIZE:
    {
      if( arg == NULL ) return OSE_NULL_PARAM;
      return dctxdata->wctx->size( dctxdata, (uint32*)const_cast<void*>( arg ) );
    }

    default:
      return OSE_BAD_CMD;
  }

  return OSE_OK;
}
/*****************************************************************************
Syntax:  int32 drv_fwmem_plug( const char* path, uint32 address, s_fwmem_selector* wctx )    	    
Remarks:			    
*******************************************************************************/
int32 drv_fwmem_plug( const char* path, uint32 address, s_fwmem_selector* wctx )
{
  s_fwmem_context ctx;
  if( wctx == NULL ) return OSE_NULL_PARAM;
  ctx.address = address;
  ctx.wctx = wctx;
  ctx.arg0 = 0;
  ctx.arg1 = 0;
  ctx.sem = RES_VOID;
  return drv_plug( path, INOT_FOLDER, &fwmem_open, &fwmem_close, &fwmem_read, &fwmem_write, &fwmem_ioctl, &ctx, sizeof(s_fwmem_context) );
}
// ---------------------------------------------------------------------------
int32 drv_fwmem_unplug( const char* name )
{
  return drv_unplug( name );
}
// ---------------------------------------------------------------------------
