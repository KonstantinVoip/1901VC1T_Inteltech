// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: all
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d:
// !: -:
// ---------------------------------------------------------------------------
#include <drv_vrnet.h>
#include <rts.h>
#include <net_packet_parser.h>
// ---------------------------------------------------------------------------

#define VRNET_F_UP              0x00000001

// ---------------------------------------------------------------------------

struct s_vrnet_queue
{
  uint32                        sem;
  net_descriptor*               first;
  net_descriptor*               last;
};

struct s_vrnet_ctxdata
{
  net_config                    config;
  uint32                        rxd_count;
  uint32                        txd_count;
  net_descriptor*               rx;
  net_descriptor*               tx;
  s_vrnet_queue                 rx_queue;
  s_vrnet_queue                 rxf_queue;
  s_vrnet_queue                 tx_queue;
  s_vrnet_queue                 txf_queue;
  void*                         data;
  uint32                        flags;
  void                          (*callback)( const char* iname, net_config* cfg );
};

// ---------------------------------------------------------------------------
int32 vrnet_open( s_os_driver_descriptor* d, uint16 access )
{
  return -1;
}
// ---------------------------------------------------------------------------
int32 vrnet_close( s_os_driver_descriptor* d )
{
  return -1;
}
// ---------------------------------------------------------------------------
int32 vrnet_read( s_os_driver_descriptor* d, void* buf, int32 length )
{
  return -1;
}
// ---------------------------------------------------------------------------
int32 vrnet_write( s_os_driver_descriptor* d, const void* buf, int32 length )
{
  return -1;
}
// ---------------------------------------------------------------------------
void vrnet_lock( s_vrnet_ctxdata* dctxdata )
{
  sem_lock( dctxdata->rx_queue.sem, SEM_INFINITY );
  sem_lock( dctxdata->rxf_queue.sem, SEM_INFINITY );
  sem_lock( dctxdata->tx_queue.sem, SEM_INFINITY );
  sem_lock( dctxdata->txf_queue.sem, SEM_INFINITY );
}
// ---------------------------------------------------------------------------
void vrnet_unlock( s_vrnet_ctxdata* dctxdata )
{
  sem_unlock( dctxdata->txf_queue.sem );
  sem_unlock( dctxdata->tx_queue.sem );
  sem_unlock( dctxdata->rxf_queue.sem );
  sem_unlock( dctxdata->rx_queue.sem );
}
// ---------------------------------------------------------------------------
int32 vrnet_queue_get( net_descriptor*& carg, s_vrnet_queue& q )
{
  sem_lock( q.sem, SEM_INFINITY );
  if( q.first == NULL )
  {
    carg = NULL;
  }
  else
  {
    carg = q.first;
    q.first = q.first->next;
    if( q.first )
    {
      q.first->prev = NULL;
    }
    else
    {
      q.last = NULL;
    }
    carg->next = NULL;
  }
  
  sem_unlock( q.sem );
  
  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 vrnet_queue_put( net_descriptor*& carg, net_descriptor* arr, uint32 arr_size, s_vrnet_queue& q )
{
  uint32 i;
//  for( i = 0; i < arr_size; i++ ) if( &arr[i] == carg ) break;
//  if( i == arr_size ) return OSE_BAD_PARAM;
  sem_lock( q.sem, SEM_INFINITY );
  for( i = 0; i < arr_size; i++ ) if( &arr[i] == carg ) break;
  if( i == arr_size )
  {
     sem_unlock( q.sem );
     return OSE_BAD_PARAM;
  }


  if( q.last == NULL )
  {
    q.first = carg;
    q.last = carg;
    carg->next = NULL;
    carg->prev = NULL;
  }
  else
  {
    carg->next = NULL;
    carg->prev = q.last;
    q.last->next = carg;
    q.last = carg;
  }
  sem_unlock( q.sem );

  return OSE_OK;
}
// ---------------------------------------------------------------------------
bool vrnet_queue_have( s_vrnet_queue& q )
{
  return ( q.first != NULL );
}
// ---------------------------------------------------------------------------
int32 vrnet_ioctl( s_os_driver_descriptor* d, int32 cmd, const void* arg )
{
  switch( cmd )
  {
    case IOC_INIT:
    {
      int32 i, offset;
      int32 res = OSE_OK;
      
      if( arg == NULL ) return OSE_NULL_PARAM;
      s_os_driver_context* dctx = (s_os_driver_context*)const_cast<void*>( arg );
      s_vrnet_ctxdata* dctxdata = (s_vrnet_ctxdata*)dctx->data;
    
      dctxdata->rx = (net_descriptor*)heap_alloc( NULL, sizeof(net_descriptor) * dctxdata->rxd_count, HEAP_ALIGN_8 );
      if( dctxdata->rx == NULL ) { res = OSE_NO_MEMORY; goto net_init_fail; }
      dctxdata->tx = (net_descriptor*)heap_alloc( NULL, sizeof(net_descriptor) * dctxdata->txd_count, HEAP_ALIGN_8 );
      if( dctxdata->tx == NULL ) { res = OSE_NO_MEMORY; goto net_init_fail; }
      dctxdata->data = heap_alloc( NULL, NET_PACKET_SIZE * ( dctxdata->rxd_count + dctxdata->txd_count ), HEAP_ALIGN_8 );
      if( dctxdata->data == NULL ) { res = OSE_NO_MEMORY; goto net_init_fail; }

      if( ( dctxdata->rx_queue.sem = sem_alloc( 1, NULL ) ) == RES_VOID ) { res = OSE_CANT_CREATE_SEM; goto net_init_fail; }
      if( ( dctxdata->tx_queue.sem = sem_alloc( 1, NULL ) ) == RES_VOID ) { res = OSE_CANT_CREATE_SEM; goto net_init_fail; }
      if( ( dctxdata->rxf_queue.sem = sem_alloc( 1, NULL ) ) == RES_VOID ) { res = OSE_CANT_CREATE_SEM; goto net_init_fail; }
      if( ( dctxdata->txf_queue.sem = sem_alloc( 1, NULL ) ) == RES_VOID ) { res = OSE_CANT_CREATE_SEM; goto net_init_fail; }

      memset( dctxdata->rx, 0, sizeof(net_descriptor) * dctxdata->rxd_count );
      memset( dctxdata->tx, 0, sizeof(net_descriptor) * dctxdata->txd_count );
      memset( dctxdata->data, 0, NET_PACKET_SIZE * ( dctxdata->rxd_count + dctxdata->txd_count ) );

      offset = 0;

      for( i = 0; i < dctxdata->rxd_count; i++ )
      {
        dctxdata->rx[i].data = (uint8*)( (uint32)dctxdata->data + offset );
        offset += NET_PACKET_SIZE;
        dctxdata->rx[i].size = NET_PACKET_SIZE;
        if( i == 0 )
        {
          dctxdata->rxf_queue.first = dctxdata->rx;
          dctxdata->rx->next = &dctxdata->rx[1];
        }
        else if( i == ( dctxdata->rxd_count - 1 ) )
        {
          dctxdata->rxf_queue.last = &dctxdata->rx[i];
          dctxdata->rx[i].prev = &dctxdata->rx[i-1];
        }
        else
        {
          dctxdata->rx[i].prev = &dctxdata->rx[i-1];
          dctxdata->rx[i].next = &dctxdata->rx[i+1];
        }
      }

      for( i = 0; i < dctxdata->txd_count; i++ )
      {
        dctxdata->tx[i].data = (uint8*)( (uint32)dctxdata->data + offset );
        offset += NET_PACKET_SIZE;
        dctxdata->tx[i].size = NET_PACKET_SIZE;
        if( i == 0 )
        {
          dctxdata->txf_queue.first = dctxdata->tx;
          dctxdata->tx->next = &dctxdata->tx[1];
        }
        else if( i == ( dctxdata->txd_count - 1 ) )
        {
          dctxdata->txf_queue.last = &dctxdata->tx[i];
          dctxdata->tx[i].prev = &dctxdata->tx[i-1];
        }
        else
        {
          dctxdata->tx[i].prev = &dctxdata->tx[i-1];
          dctxdata->tx[i].next = &dctxdata->tx[i+1];
        }
      }

    net_init_fail:

      if( res != OSE_OK )
      {
        if( dctxdata->rx_queue.sem != RES_VOID ) sem_free( dctxdata->rx_queue.sem );
        if( dctxdata->tx_queue.sem != RES_VOID ) sem_free( dctxdata->tx_queue.sem );
        if( dctxdata->rxf_queue.sem != RES_VOID ) sem_free( dctxdata->rxf_queue.sem );
        if( dctxdata->txf_queue.sem != RES_VOID ) sem_free( dctxdata->txf_queue.sem );
        if( dctxdata->rx != NULL ) heap_free( NULL, dctxdata->rx );
        if( dctxdata->tx != NULL ) heap_free( NULL, dctxdata->tx );
        if( dctxdata->data != NULL ) heap_free( NULL, dctxdata->data );
        dctxdata->rx = NULL;
        dctxdata->tx = NULL;
        dctxdata->data = NULL;
        return res;
      }
    }
    break;

    case IOC_DEINIT:
    {
      if( arg == NULL ) return OSE_NULL_PARAM;
      s_os_driver_context* dctx = (s_os_driver_context*)const_cast<void*>( arg );
      if( dctx->data != NULL )
      {
        s_vrnet_ctxdata* dctxdata = (s_vrnet_ctxdata*)dctx->data;
        sem_free( dctxdata->rx_queue.sem );
        sem_free( dctxdata->tx_queue.sem );
        sem_free( dctxdata->rxf_queue.sem );
        sem_free( dctxdata->txf_queue.sem );
        heap_free( NULL, dctx->data );
        dctx->data = NULL;
      }
    }
    break;

    case IOC_INIT_DESCRIPTOR:
    case IOC_DEINIT_DESCRIPTOR:
      break;

    case IOC_INODE_SELECT:
    {
      if( arg == NULL ) return OSE_NULL_PARAM;
      char* dst = (char*)const_cast<void*>( arg );
      if( strcmp( dst, "." ) == 0 ) break;
      if( strcmp( dst, ".." ) != 0 ) return OSE_NO_NODE;
      drv_dec( d );
      drv_rfs( d );
    }
    break;

    case NET_UP:
    {
      s_vrnet_ctxdata* dctxdata = (s_vrnet_ctxdata*)d->ctx->data;
      vrnet_lock( dctxdata );
      dctxdata->flags |= VRNET_F_UP;
      vrnet_unlock( dctxdata );
    }
    break;

    case NET_DOWN:
    {
      s_vrnet_ctxdata* dctxdata = (s_vrnet_ctxdata*)d->ctx->data;
      vrnet_lock( dctxdata );
      dctxdata->flags &= 0xffffffff ^ VRNET_F_UP;
      vrnet_unlock( dctxdata );
    }
    break;

    case NET_LINK:
    {
      if( arg == NULL ) return OSE_NULL_PARAM;
      s_vrnet_ctxdata* dctxdata = (s_vrnet_ctxdata*)d->ctx->data;
      (*(bool*)const_cast<void*>( arg )) = ( dctxdata->flags & VRNET_F_UP ) ? true : false;
    }
    break;

    case NET_RECV_GET:
    {
      if( arg == NULL ) return OSE_NULL_PARAM;
      net_descriptor** carg = (net_descriptor**)const_cast<void*>( arg );
      s_vrnet_ctxdata* dctxdata = (s_vrnet_ctxdata*)d->ctx->data;
      return vrnet_queue_get( (*carg), dctxdata->rx_queue );
    }

    case NET_RECV_PUT:
    {
      if( arg == NULL ) return OSE_NULL_PARAM;
      net_descriptor** carg = (net_descriptor**)const_cast<void*>( arg );
      s_vrnet_ctxdata* dctxdata = (s_vrnet_ctxdata*)d->ctx->data;
      return vrnet_queue_put( (*carg), dctxdata->rx, dctxdata->rxd_count, dctxdata->rxf_queue );
    }

    case NET_SEND_GET:
    {
      if( arg == NULL ) return OSE_NULL_PARAM;
      net_descriptor** carg = (net_descriptor**)const_cast<void*>( arg );
      s_vrnet_ctxdata* dctxdata = (s_vrnet_ctxdata*)d->ctx->data;
      return vrnet_queue_get( (*carg), dctxdata->txf_queue );
    }

    case NET_SEND_PUT:
    {
      if( arg == NULL ) return OSE_NULL_PARAM;
      net_descriptor** carg = (net_descriptor**)const_cast<void*>( arg );
      s_vrnet_ctxdata* dctxdata = (s_vrnet_ctxdata*)d->ctx->data;
      if( dctxdata->config.flags & NETCFG_NOARP )
      {
        memset( (*carg)->data, 0, 6 );
      }
      if( !( dctxdata->config.flags & NETCFG_PROMISCUOUSE ) )
      {
        memcpy( (*carg)->data + 6, dctxdata->config.mac, 6 );
      }
      return vrnet_queue_put( (*carg), dctxdata->tx, dctxdata->txd_count, dctxdata->tx_queue );
    }

    case NET_HOST_RECV_GET:
    {
      if( arg == NULL ) return OSE_NULL_PARAM;
      net_descriptor** carg = (net_descriptor**)const_cast<void*>( arg );
      s_vrnet_ctxdata* dctxdata = (s_vrnet_ctxdata*)d->ctx->data;
      return vrnet_queue_get( (*carg), dctxdata->rxf_queue );
    }

    case NET_HOST_RECV_PUT:
    {
      int32 r;
      if( arg == NULL ) return OSE_NULL_PARAM;
      net_descriptor** carg = (net_descriptor**)const_cast<void*>( arg );
      s_vrnet_ctxdata* dctxdata = (s_vrnet_ctxdata*)d->ctx->data;
      if( netpp_parse( dctxdata->config, (*carg) ) != NETPP_OK )
      {
        if( ( r = vrnet_queue_put( (*carg), dctxdata->rx, dctxdata->rxd_count, dctxdata->rxf_queue ) ) != OSE_OK ) return r;
        return OSE_DROPPED;
      }
      if( ( r = vrnet_queue_put( (*carg), dctxdata->rx, dctxdata->rxd_count, dctxdata->rx_queue ) ) != OSE_OK ) return r;
    }
    break;
/*
    case NET_HOST_RECV_HAVE:
    {
      if( arg == NULL ) return OSE_NULL_PARAM;
      bool* carg = (bool*)const_cast<void*>( arg );
      s_vrnet_ctxdata* dctxdata = (s_vrnet_ctxdata*)d->ctx->data;
      (*carg) = vrnet_queue_have( dctxdata->rxf_queue );
    }
    break;
*/
    case NET_HOST_SEND_GET:
    {
      if( arg == NULL ) return OSE_NULL_PARAM;
      net_descriptor** carg = (net_descriptor**)const_cast<void*>( arg );
      s_vrnet_ctxdata* dctxdata = (s_vrnet_ctxdata*)d->ctx->data;
      return vrnet_queue_get( (*carg), dctxdata->tx_queue );
    }

    case NET_HOST_SEND_PUT:
    {
      if( arg == NULL ) return OSE_NULL_PARAM;
      net_descriptor** carg = (net_descriptor**)const_cast<void*>( arg );
      s_vrnet_ctxdata* dctxdata = (s_vrnet_ctxdata*)d->ctx->data;
      return vrnet_queue_put( (*carg), dctxdata->tx, dctxdata->txd_count, dctxdata->txf_queue );
    }
/*
    case NET_HOST_SEND_HAVE:
    {
      if( arg == NULL ) return OSE_NULL_PARAM;
      bool* carg = (bool*)const_cast<void*>( arg );
      s_vrnet_ctxdata* dctxdata = (s_vrnet_ctxdata*)d->ctx->data;
      (*carg) = vrnet_queue_have( dctxdata->tx_queue );
    }
    break;
*/
    case NET_SET_CONFIG:
    {
      if( arg == NULL ) return OSE_NULL_PARAM;
      s_vrnet_ctxdata* dctxdata = (s_vrnet_ctxdata*)d->ctx->data;
      vrnet_lock( dctxdata );
      memcpy( &dctxdata->config, arg, sizeof(net_config) );
      uint32 mtu = dctxdata->config.mtu;
      if( mtu == 0 ) mtu = 1500;
      if( mtu < 64 ) mtu = 64;
      if( mtu > 1500 ) mtu = 1500;
      dctxdata->config.mtu = mtu;
      if( dctxdata->callback ) dctxdata->callback( d->ctx->name, &dctxdata->config );
      vrnet_unlock( dctxdata );
    }
    break;

    case NET_SET_CONFIG_CALLBACK:
    {
      if( arg == NULL ) return OSE_NULL_PARAM;
      s_vrnet_ctxdata* dctxdata = (s_vrnet_ctxdata*)d->ctx->data;
      if( dctxdata->callback ) return OSE_ALLREADY_SET;
      dctxdata->callback = ((void(*)(const char*,net_config*))((uint32)const_cast<void*>( arg )));
    }
    break;

    case NET_GET_CONFIG:
    {
      if( arg == NULL ) return OSE_NULL_PARAM;
      s_vrnet_ctxdata* dctxdata = (s_vrnet_ctxdata*)d->ctx->data;
      vrnet_lock( dctxdata );
      memcpy( const_cast<void*>( arg ), &dctxdata->config, sizeof(net_config) );
      vrnet_unlock( dctxdata );
    }
    break;

    default:
      return OSE_BAD_CMD;
  }

  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 drv_vrnet_plug( const char* path, net_config& ncfg, uint32 rxdc, uint32 txdc )
{
  s_vrnet_ctxdata data;
  memset( &data, 0, sizeof(data) );
  memcpy( &data.config, &ncfg, sizeof(data.config) );
  data.rxd_count = rxdc;
  data.txd_count = txdc;
  data.rx_queue.sem = RES_VOID;
  data.tx_queue.sem = RES_VOID;
  data.rxf_queue.sem = RES_VOID;
  data.txf_queue.sem = RES_VOID;
  return drv_plug( path, INOT_FILE, &vrnet_open, &vrnet_close, &vrnet_read, &vrnet_write, &vrnet_ioctl, &data, sizeof(s_vrnet_ctxdata) );
}
// ---------------------------------------------------------------------------
int32 drv_vrnet_unplug( const char* name )
{
  return drv_unplug( name );
}
// ---------------------------------------------------------------------------
