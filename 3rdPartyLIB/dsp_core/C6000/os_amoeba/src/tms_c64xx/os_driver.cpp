// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: all
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp866
// !: d: Модуль содержит реализацию менеджера драйверов и драйвера корневой
// !: d: файловой системы.
// !: [os_driver.cpp]
// ---------------------------------------------------------------------------
#define SYSCALL_DIRECT
#include <os.h>
// ---------------------------------------------------------------------------
#ifdef OS_SUPPORT_SYSLOG
static const char* os_module = { __FILE__ };
#endif
// ---------------------------------------------------------------------------

char*                           os_driver_get_npunit( int32& p, int32 l, const char* path, int32 sc = 0 );
int32                           os_driver_get_npunit_count( const char* path );

// ---------------------------------------------------------------------------

struct s_rootfs_rec
{
  s_rootfs_rec*                 prev;
  s_rootfs_rec*                 next;
  s_rootfs_rec*                 child;
  s_rootfs_rec*                 parent;
  s_inode                       inode;
  s_os_driver_context*          driver;
};

struct s_rootfs_desc_data
{
  s_rootfs_rec*                 crec;
};

// ---------------------------------------------------------------------------

uint32                          rootfs_sem;
s_rootfs_rec                    rootfs_root_rec;

s_os_driver_context*            v_os_driver_list;
uint32                          v_os_driver_list_sem;

s_os_driver_descriptor**        v_os_desc_list;
uint32                          v_os_desc_list_length;
uint32                          v_os_desc_list_sem;

s_os_driver_context             v_os_driver_root;

// ---------------------------------------------------------------------------
static inline bool is_slash( char c )
{
  return ( ( c == '/' ) || ( c == '\\' ) );
}
// ---------------------------------------------------------------------------
int32 os_rootfs_open( s_os_driver_descriptor* d, uint16 access )
{
  return -1;
}
// ---------------------------------------------------------------------------
int32 os_rootfs_close( s_os_driver_descriptor* d )
{
  return -1;
}
// ---------------------------------------------------------------------------
int32 os_rootfs_read( s_os_driver_descriptor* d, void* buf, int32 length )
{
  return -1;
}
// ---------------------------------------------------------------------------
int32 os_rootfs_write( s_os_driver_descriptor* d, const void* buf, int32 length )
{
  return -1;
}
// ---------------------------------------------------------------------------
int32 os_rootfs_ioctl( s_os_driver_descriptor* d, int32 cmd, const void* arg )
{
  s_rootfs_desc_data* vdata = (s_rootfs_desc_data*)d->data;

  switch( cmd )
  {
    case IOC_INIT:
      break;

    case IOC_DEINIT:
      return OSE_PERMISSION_DENIED;

    case IOC_INODE_LIST:
    {
      s_rootfs_rec* crec;
      s_inode** list;
      s_inode* node = NULL;
      s_inode* tnode;

      if( arg == NULL ) return OSE_NULL_PARAM;

      list = (s_inode**)const_cast<void*>( arg );
      (*list) = NULL;
      
      if( vdata == NULL ) return OSE_BAD_DATA;
      if( vdata->crec->child == NULL ) return OSE_NO_NODE;
      
      sem_lock( rootfs_sem, SEM_INFINITY );

      crec = vdata->crec->child;
      while( crec )
      {
        node = new s_inode;
        if( node == NULL ) goto l_fail;
        memset( node, 0, sizeof(s_inode) );
        node->name = new char[strlen(crec->inode.name)+1];
        if( node->name == NULL ) goto l_fail;
        strcpy( node->name, crec->inode.name );
        _mem8( &node->size ) = _mem8( &crec->inode.size );
        _mem4( &node->mktime ) = _mem4( &crec->inode.mktime );
        node->type = crec->inode.type;
        _mem4( &node->access ) = _mem4( &crec->inode.access );
        node->own_group = crec->inode.own_group;
        node->own_user = crec->inode.own_user;
        if( (*list) != NULL )
        {
          (*list)->prev = node;
          node->next = (*list);
        }
        (*list) = node;
        crec = crec->next;
      }
      node = NULL;

      goto l_end;

    l_fail:

      sem_unlock( rootfs_sem );

      if( node )
      {
        if( node->name ) delete[] node->name;
        delete node;
      }

      if( (*list) )
      {
        node = (*list);
        while( node )
        {
          tnode = node;
          node = node->next;
          if( tnode->name ) delete[] tnode->name;
          delete tnode;
        }
        (*list) = NULL;
      }

      return OSE_NO_MEMORY;

    l_end:

      sem_unlock( rootfs_sem );
    }
    break;

    case IOC_INODE_SELECT:
    {
      char* npath;
      char* varg;
      int32 i;
      bool finded = false;

      if( arg == NULL ) return OSE_NULL_PARAM;
      varg = (char*)const_cast<void*>( arg );
      if( vdata == NULL ) return OSE_BAD_DATA;
      if( vdata->crec->child == NULL ) return OSE_NO_NODE;

      sem_lock( rootfs_sem, SEM_INFINITY );

      if( strcmp( varg, ".." ) == 0 )
      {
        finded = true;
        if( vdata->crec->parent != NULL )
        {
          for( i = strlen( d->path ) - 1; i >= 0; i-- )
          {
            if( is_slash( d->path[i] ) )
            {
              if( i == 0 )
              {
                npath = (char*)heap_alloc( NULL, 2, HEAP_ALIGN_4 );
              }
              else
              {
                npath = (char*)heap_alloc( NULL, i, HEAP_ALIGN_4 );
              }
              if( npath == NULL )
              {
                sem_unlock( rootfs_sem );
                return OSE_NO_MEMORY;
              }
              if( i == 0 )
              {
                strcpy( npath, "/" );
              }
              else
              {
                memcpy( npath, d->path, i );
                npath[i] = 0;
              }
              heap_free( NULL, d->path );
              d->path = npath;
              vdata->crec = vdata->crec->parent;
              break;
            }
          }
        }
      }
      else
      {
        s_rootfs_rec* crec = vdata->crec->child;
        while( crec )
        {
          if( strcmp( crec->inode.name, varg ) == 0 )
          {
            npath = (char*)heap_alloc( NULL, strlen( d->path ) + strlen( crec->inode.name ) + 2, HEAP_ALIGN_4 );
            if( npath == NULL )
            {
              sem_unlock( rootfs_sem );
              return OSE_NO_MEMORY;
            }
            strcpy( npath, d->path );
            if( vdata->crec != &rootfs_root_rec ) strcat( npath, "/" );
            strcat( npath, crec->inode.name );
            if( crec->inode.type & INOT_MOUNT_POINT )
            {
              heap_free( NULL, d->data );
              d->data = NULL;
              if( crec->driver->flags & DRV_F_UNLOADING )
              {
                sem_unlock( rootfs_sem );
                heap_free( NULL, npath );
                return OSE_DRIVER_UNLOADED;
              }
              if( ( i = crec->driver->ioctl( d, IOC_INIT_DESCRIPTOR, NULL ) ) != 0 )
              {
                sem_unlock( rootfs_sem );
                heap_free( NULL, npath );
                return i;
              }
              d->ctx = crec->driver;
            }
            else
            {
              vdata->crec = crec;
            }
            heap_free( NULL, d->path );
            d->path = npath;
            finded = true;
            break;
          }
          crec = crec->next;
        }
      }
      
      sem_unlock( rootfs_sem );
      if( !finded ) return OSE_NO_NODE;
    }
    break;

    case IOC_INODE_CREATE:
    {
      if( arg == NULL ) return OSE_NULL_PARAM;
      s_inode_create* varg = (s_inode_create*)const_cast<void*>( arg );
      if( varg->name == NULL ) return OSE_NULL_PARAM;
      if( varg->type != INOT_FOLDER ) return OSE_BAD_PARAM;
      if( vdata == NULL ) return OSE_BAD_DATA;

      sem_lock( rootfs_sem, SEM_INFINITY );
      
      s_rootfs_rec* crec = vdata->crec->child;
      while( crec )
      {
        if( strcmp( crec->inode.name, varg->name ) == 0 )
        {
          sem_unlock( rootfs_sem );
          return OSE_NODE_EXISTS;
        }
        crec = crec->next;
      }

      s_rootfs_rec* nrec = (s_rootfs_rec*)heap_alloc( NULL, sizeof(s_rootfs_rec), HEAP_ALIGN_4 );
      if( nrec == NULL )
      {
        sem_unlock( rootfs_sem );
        return OSE_NO_MEMORY;
      }
      memset( nrec, 0, sizeof(s_rootfs_rec) );

      nrec->inode.name = (char*)heap_alloc( NULL, strlen( varg->name ) + 1, HEAP_ALIGN_4 );
      if( nrec->inode.name == NULL )
      {
        sem_unlock( rootfs_sem );
        heap_free( NULL, nrec );
        return OSE_NO_MEMORY;
      }

      strcpy( nrec->inode.name, varg->name );
      nrec->inode.type = varg->type;
      nrec->inode.mktime = time_s();
      if( varg->type & INOT_FOLDER ) nrec->inode.access = ACC_FULL_FOLDER;
      else if( varg->type & INOT_FILE ) nrec->inode.access = ACC_FULL_FILE;
      _mem8( &nrec->inode.size ) = sizeof(s_rootfs_rec) + strlen( varg->name ) + 1;
      crec = vdata->crec->child;
      if( crec != NULL )
      {
        crec->prev = nrec;
        nrec->next = crec;
      }
      vdata->crec->child = nrec;
      nrec->parent = vdata->crec;

      sem_unlock( rootfs_sem );
    }
    break;

    case IOC_INODE_REMOVE:
    {
      // todo
    }
    break;

    case IOC_INIT_DESCRIPTOR:
    {
      char* cunit;
      int32 cunitp = 0;
      int32 pathlen;
      s_rootfs_rec* crec;
      bool nfnd;

      d->data = heap_alloc( NULL, sizeof(s_rootfs_desc_data), HEAP_ALIGN_4 );
      if( d->data == NULL )
      {
        heap_free( NULL, d->path );
        d->path = NULL;
        return OSE_NO_MEMORY;
      }
      if( d->path )
      {
        sem_lock( rootfs_sem, SEM_INFINITY );
        pathlen = strlen( d->path );
        crec = &rootfs_root_rec;
        while( cunit = os_driver_get_npunit( cunitp, pathlen, d->path ) )
        {
          crec = crec->child;
          nfnd = true;
          while( crec )
          {
            if( strcmp( crec->inode.name, cunit ) == 0 ) { nfnd = false; break; }
            crec = crec->next;
          }
          heap_free( NULL, cunit );
          if( nfnd ) break;
          nfnd = false;
        }
        sem_unlock( rootfs_sem );
        if( nfnd )
        {// todo: goto root
          heap_free( NULL, d->path );
          d->path = NULL;
          heap_free( NULL, d->data );
          d->data = NULL;
          return OSE_NO_NODE;
        }
        else
        {
          ((s_rootfs_desc_data*)d->data)->crec = crec;
        }
      }
      else
      {
        d->path = (char*)heap_alloc( NULL, 2, HEAP_ALIGN_4 );
        if( d->path == NULL )
        {
          heap_free( NULL, d->data );
          d->data = NULL;
          return OSE_NO_MEMORY;
        }
        d->path[0] = '/';
        d->path[1] = 0;
        ((s_rootfs_desc_data*)d->data)->crec = &rootfs_root_rec;
      }
    }
    break;

    case IOC_DEINIT_DESCRIPTOR:
    {
      heap_free( NULL, d->data );
      d->data = NULL;
    }
    break;

    default:
      return OSE_BAD_CMD;
  }

  return OSE_OK;
}
// ---------------------------------------------------------------------------
void os_driver_init_module()
{
  uint32 t;

  memset( &v_os_driver_root, 0, sizeof(v_os_driver_root) );
  v_os_driver_root.open = &os_rootfs_open;
  v_os_driver_root.close = &os_rootfs_close;
  v_os_driver_root.read = &os_rootfs_read;
  v_os_driver_root.write = &os_rootfs_write;
  v_os_driver_root.ioctl = &os_rootfs_ioctl;
  v_os_driver_root.name = "rootfs";
  v_os_driver_list = &v_os_driver_root;
  memset( &rootfs_root_rec, 0, sizeof(rootfs_root_rec) );
  rootfs_root_rec.inode.type = INOT_MOUNT_POINT | INOT_FOLDER;
  rootfs_root_rec.driver = &v_os_driver_root;
  v_os_desc_list_length = 32;
  t = sizeof(s_os_driver_descriptor*) * v_os_desc_list_length;
  v_os_desc_list = (s_os_driver_descriptor**)heap_alloc( NULL, t, HEAP_ALIGN_4 );
  memset( v_os_desc_list, 0, t );

  rootfs_sem = sem_alloc( 1, NULL );
  v_os_driver_list_sem = sem_alloc( 1, NULL );
  v_os_desc_list_sem = sem_alloc( 1, NULL );
  
  if( ( v_os_desc_list == NULL ) || ( rootfs_sem == RES_VOID ) ||
      ( v_os_driver_list_sem == RES_VOID ) || ( v_os_desc_list_sem == RES_VOID ) )
  {
    while( true )
      asm( " nop " );
  }

}
// ---------------------------------------------------------------------------
char* os_driver_get_npunit( int32& p, int32 l, const char* path, int32 sc )
{
  if( p >= l ) return NULL;
  if( p == 0 ) { if( is_slash( path[0] ) ) p++; } else p++;
  int32 s = p;
  for( ; p < l; p++ ) if( is_slash( path[p] ) ) { sc--; if( sc < 0 ) break; else s = p + 1; }
  l = p - s;
  if( l <= 0 ) return NULL;
  char* u = (char*)heap_alloc( NULL, l + 1, HEAP_ALIGN_4 );
  if( u == NULL ) return NULL;
  memcpy( u, path + s, l );
  u[l] = 0;
  return u;
}
// ---------------------------------------------------------------------------
int32 os_driver_get_npunit_count( const char* path )
{
  int32 res = 0;
  int32 l = strlen( path );
  if( l == 1 ) return 0;
  for( int32 i = 0; i < l; i++ ) if( is_slash( path[i] ) ) res++;
  if( is_slash( path[l-1] ) ) res--;
  return res;
}
// ---------------------------------------------------------------------------
// !: fn: int32 os_driver_plug( const char* path, const char* name, uint8 type, int32 (*open_func)( s_os_driver_descriptor*, uint16 ), int32 (*close_func)( s_os_driver_descriptor* ), int32 (*read_func)( s_os_driver_descriptor*, void*, int32 ), int32 (*write_func)( s_os_driver_descriptor*, const void*, int32 ), int32 (*ioctl_func)( s_os_driver_descriptor*, int32, const void* ), void* data, int32 datalen )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall псевдоним:</b><br>
// !: d: <br>
// !: d: drv_plug<br>
// !: d: <br>
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция монтирует драйвер в корневую файловую систему по пути path.
// !: d: Переменная name ссылается на уникально имя драйвера в системе.
// !: d: Переменная type указывает тип создаваемого объекта и может принимать
// !: d: значения: INOT_FILE или INOT_FOLDER, указывая на файл или папку
// !: d: соответственно. Контекст драйвера формируется из пяти функций на
// !: d: которые указывают переменные open_func, close_func, read_func,
// !: d: write_func и ioctl_func, а также из данных расположенных в массиве
// !: d: data и имеющих длину datalen.<br>
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: В случае успеха функция возвращает OSE_OK, иначе одну из ошибок:<br><br>
// !: d: <table cellpadding=2 cellspacing=2 border=0>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_NO_MEMORY</td>
// !: d: <td> - </td>
// !: d: <td>недостаточно памяти для размещения драйвера в системе;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_NULL_PARAM</td>
// !: d: <td> - </td>
// !: d: <td>Одна из переменных path, name, open_func, close_func, read_func,
// !: d: write_func, ioctl_func равна нулю;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_BAD_DATA</td>
// !: d: <td> - </td>
// !: d: <td>плохое сочетание значений переменных data и datalen;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_ALREADY_PLUGGED</td>
// !: d: <td> - </td>
// !: d: <td>драйвер с таким именем уже зарегистрирован в системе.</td>
// !: d: </tr>
// !: d: </table><br>
// !: d: Так же возможны ошибки формируемые монтируемым драйвером.
// ---------------------------------------------------------------------------
int32 os_driver_plug( const char* path, uint8 type, int32 (*open_func)( s_os_driver_descriptor*, uint16 ), int32 (*close_func)( s_os_driver_descriptor* ), int32 (*read_func)( s_os_driver_descriptor*, void*, int32 ), int32 (*write_func)( s_os_driver_descriptor*, const void*, int32 ), int32 (*ioctl_func)( s_os_driver_descriptor*, int32, const void* ), void* data, int32 datalen )
{
  s_os_driver_context* ndrv = NULL;
  s_rootfs_rec* rrec;
  s_rootfs_rec* nrec = NULL;
  s_rootfs_rec* crec;
  s_rootfs_rec* prec;
  int32 unp, unr;
  volatile int32 unc, unl;
  char* cunit;
  bool uok;
  int32 r = OSE_NO_MEMORY;
  bool need_deinit = false;
  const char* name;
  
  if( path == NULL ) return OSE_NULL_PARAM;
  if( open_func == NULL ) return OSE_NULL_PARAM;
  if( close_func == NULL ) return OSE_NULL_PARAM;
  if( read_func == NULL ) return OSE_NULL_PARAM;
  if( write_func == NULL ) return OSE_NULL_PARAM;
  if( ioctl_func == NULL ) return OSE_NULL_PARAM;
  if( ( data != NULL ) && ( datalen <= 0 ) ) return OSE_BAD_DATA;

  unl = strlen( path );
  if( is_slash( path[unl-1] ) ) return OSE_BAD_PARAM;
  for( unc = unl - 1; unc >= 0; unc-- )
  {
    if( is_slash( path[unc] ) )
    {
      name = &path[unc+1];
      break;
    }
  }
  if( unc == -1 ) return OSE_BAD_PARAM;

  sem_lock( v_os_driver_list_sem, SEM_INFINITY );

  ndrv = v_os_driver_list;
  while( ndrv )
  {
    if( strcmp( ndrv->name, name ) == 0 )
    {
      ndrv = NULL;
      r = OSE_ALREADY_PLUGGED;
      goto l_fail;
    }
    ndrv = ndrv->next;
  }

  ndrv = (s_os_driver_context*)heap_alloc( NULL, sizeof(s_os_driver_context), HEAP_ALIGN_4 );
  if( ndrv == NULL ) goto l_fail;
  memset( ndrv, 0, sizeof(s_os_driver_context) );

  ndrv->name = (char*)heap_alloc( NULL, strlen( name ) + 1, HEAP_ALIGN_4 );
  if( ndrv->name == NULL ) goto l_fail;
  
  ndrv->path = (char*)heap_alloc( NULL, strlen( path ) + 1, HEAP_ALIGN_4 );
  if( ndrv->path == NULL ) goto l_fail;
  
  if( data != NULL )
  {
    ndrv->data = heap_alloc( NULL, datalen, HEAP_ALIGN_4 );
    if( ndrv->data == NULL ) goto l_fail;
    memcpy( ndrv->data, data, datalen );
  }

  strcpy( ndrv->name, name );
  strcpy( ndrv->path, path );
  ndrv->open = open_func;
  ndrv->close = close_func;
  ndrv->read = read_func;
  ndrv->write = write_func;
  ndrv->ioctl = ioctl_func;
  ndrv->own_process = v_os_current_process->id;

  if( ( r = ndrv->ioctl( NULL, IOC_INIT, ndrv ) ) != OSE_OK ) goto l_fail;
  need_deinit = true;

  unc = os_driver_get_npunit_count( path );
  unl = strlen( path );
  unr = unp = 0;
  prec = rrec = &rootfs_root_rec;

  sem_lock( rootfs_sem, SEM_INFINITY );

  while( rrec )
  {
    crec = rrec->child;
    if( crec == NULL ) break;
    cunit = os_driver_get_npunit( unp, unl, path );
    if( cunit == NULL )
    {
      if( unr < unc ) unr = -2;
      break;
    }
    uok = false;
    while( crec )
    {
      if( strcmp( cunit, crec->inode.name ) == 0 )
      {
        uok = true;
        rrec = crec;
        break;
      }
      crec = crec->next;
    }
    heap_free( NULL, cunit );
    if( !uok ) break;
    unr++;
    if( unr == ( unc - 1 ) ) prec = rrec;
  }

  if( unr != ( unc - 1 ) )
  {
    sem_unlock( rootfs_sem );
    r = OSE_NO_NODE;
    goto l_fail;
  }

  nrec = (s_rootfs_rec*)heap_alloc( NULL, sizeof(s_rootfs_rec), HEAP_ALIGN_4 );
  if( nrec == NULL )
  {
    sem_unlock( rootfs_sem );
    goto l_fail;
  }
  memset( nrec, 0, sizeof(s_rootfs_rec) );

  unp = 0;
  nrec->inode.name = os_driver_get_npunit( unp, unl, path, unc - 1 );
  if( nrec->inode.name == NULL )
  {
    sem_unlock( rootfs_sem );
    goto l_fail;
  }

  nrec->parent = prec;
  _mem8( &nrec->inode.size ) = sizeof(s_rootfs_rec) + sizeof(s_os_driver_context) + strlen( ndrv->name ) + strlen( nrec->inode.name ) + datalen;
  nrec->inode.type = type | INOT_MOUNT_POINT;
  nrec->inode.mktime = time_s();
  if( type == INOT_FOLDER ) nrec->inode.access = ACC_FULL_FOLDER;
  else if( type == INOT_FILE ) nrec->inode.access = ACC_FULL_FILE;
  nrec->driver = ndrv;

  if( prec->child != NULL )
  {
    prec->child->prev = nrec;
    nrec->next = prec->child;
  }
  prec->child = nrec;

  sem_unlock( rootfs_sem );

  v_os_driver_list->prev = ndrv;
  ndrv->next = v_os_driver_list;
  v_os_driver_list = ndrv;

  sem_unlock( v_os_driver_list_sem );

  return OSE_OK;

l_fail:

  sem_unlock( v_os_driver_list_sem );

  if( need_deinit )
  {
    ndrv->ioctl( NULL, IOC_DEINIT, ndrv );
  }

  if( nrec )
  {
    heap_free( NULL, nrec->inode.name );
    heap_free( NULL, nrec );
  }

  if( ndrv )
  {
    heap_free( NULL, ndrv->data );
    heap_free( NULL, ndrv->name );
    heap_free( NULL, ndrv->path );
    heap_free( NULL, ndrv );
  }

  return r;
}
// ---------------------------------------------------------------------------
int32 os_driver_unplug( const char* name )
{
  s_os_driver_context* cctx;
  s_os_driver_descriptor* cdesc;
  bool fnd = false;
  uint32 i, cunitc, pathlen;
  int32 cunitp;
  char* cunit;
  s_rootfs_rec* cnode;

  if( name == NULL ) return OSE_NULL_PARAM;
  if( strcmp( name, v_os_driver_root.name ) == 0 ) return OSE_NO_DRIVER;

// -- Set unloading flag for driver <name> - - - - - - - - - - - - - - - - - -

  sem_lock( v_os_driver_list_sem, SEM_INFINITY );
  cctx = v_os_driver_list;
  while( cctx )
  {
    if( strcmp( cctx->name, name ) == 0 )
    {
      if( cctx->own_process != v_os_current_process->id )
      {
        sem_unlock( v_os_driver_list_sem );
        return OSE_PERMISSION_DENIED;
      }
      cctx->flags |= DRV_F_UNLOADING;
      fnd = true;
      break;
    }
    cctx = cctx->next;
  }
  sem_unlock( v_os_driver_list_sem );
  
  if( !fnd ) return OSE_NO_DRIVER;
  
// -- Unlink all descriptors from this driver  - - - - - - - - - - - - - - - -

  i = 0;
  while( true )
  {
    sem_lock( v_os_desc_list_sem, SEM_INFINITY );
    if( i >= v_os_desc_list_length )
    {
      sem_unlock( v_os_desc_list_sem );
      break;
    }
    cdesc = v_os_desc_list[i];
    if( cdesc == NULL )
    {
      sem_unlock( v_os_desc_list_sem );
      i++;
      continue;
    }
    if( cdesc->ctx != cctx )
    {
      sem_unlock( v_os_desc_list_sem );
    }
    else
    {
      sem_lockunlock( cdesc->sem, v_os_desc_list_sem, SEM_INFINITY );
      if( cdesc->access & DRV_OPENED ) cdesc->ctx->close( cdesc );
      cdesc->ctx = NULL;
      sem_unlock( cdesc->sem );
    }
    i++;
  }

// -- Remove driver from root file system  - - - - - - - - - - - - - - - - - -

  sem_lock( v_os_driver_list_sem, SEM_INFINITY );
  cctx = v_os_driver_list;
  while( cctx )
  {
    if( strcmp( cctx->name, name ) == 0 )
    {
      if( cctx->next ) cctx->next->prev = cctx->prev;
      if( cctx->prev ) cctx->prev->next = cctx->next; else v_os_driver_list = cctx->next;
      cctx->prev = NULL;
      cctx->next = NULL;
      break;
    }
    cctx = cctx->next;
  }
  sem_unlock( v_os_driver_list_sem );

  cctx->ioctl( NULL, IOC_DEINIT, cctx );

// -- Search mount point in root file system and remove  - - - - - - - - - - -

  sem_lock( rootfs_sem, SEM_INFINITY );

  cunitp = 0;
  cunitc = os_driver_get_npunit_count( cctx->path );
  pathlen = strlen( cctx->path );
  cnode = &rootfs_root_rec;
  
  for( i = 0; i < cunitc; i++ )
  {
    cunit = os_driver_get_npunit( cunitp, pathlen, cctx->path );
    if( cunit == NULL ) break;
    cnode = cnode->child;
    while( cnode )
    {
      if( strcmp( cnode->inode.name, cunit ) == 0 ) break;
      cnode = cnode->next;
    }
    heap_free( NULL, cunit );
    if( cnode == NULL ) break;
  }

  if( ( i == cunitc ) && ( cnode != NULL ) )
  {
    if( cnode->parent ) if( cnode->parent->child == cnode ) cnode->parent->child = cnode->next;
    if( cnode->prev ) cnode->prev->next = cnode->next;
    if( cnode->next ) cnode->next->prev = cnode->prev;
    heap_free( NULL, cnode->inode.name );
    heap_free( NULL, cnode );
  }

  sem_unlock( rootfs_sem );

  heap_free( NULL, cctx->data );
  heap_free( NULL, cctx->name );
  heap_free( NULL, cctx->path );
  heap_free( NULL, cctx );

  return OSE_OK;
}
// ---------------------------------------------------------------------------
uint32 os_driver_descriptor_check( uint32 rid )
{
  s_os_driver_descriptor* d;
  uint32 index = rid & RES_I_MASK;

  if( ( ( rid & RES_T_MASK ) != RES_T_FSDESCRIPTOR ) || ( index >= v_os_desc_list_length ) )
  {
    os_sfault( OSSF_BAD_DESCRIPTOR );
    // No return from ^-- this point
  }

  d = v_os_desc_list[index];

  if( d == NULL )
  {
    os_sfault( OSSF_BAD_DESCRIPTOR );
    // No return from ^-- this point
  }

  if( ( d->id & RES_F_SHARED ) == 0 )
  {
    if( d->own_process != v_os_current_process->id )
    {
      os_sfault( OSSF_PROTECTION_FAULT );
      // No return from ^-- this point
    }
  }

  return index;
}
// ---------------------------------------------------------------------------
// !: fn: uint32 os_driver_mkd( const char* path )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall псевдоним:</b><br>
// !: d: <br>
// !: d: drv_mkd<br>
// !: d: <br>
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция создает дескриптор устройства/файла ссылающийся на объект
// !: d: расположенный по пути path в файловой системе.<br>
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: В случае успеха функция возвращает идентификатор ресурса, иначе RES_VOID.
// ---------------------------------------------------------------------------
uint32 os_driver_mkd( const char* path )
{
  s_os_driver_descriptor* d;
  char* cunit;
  int32 cunitp = 0;
  int32 cunitc, i, r;
  int32 pathlen;
  uint32 index = 0;
  uint32 rid;

  // Check path and calculate path length
  if( path == NULL ) return RES_VOID;
  pathlen = strlen( path );

  // Create new descriptor
  d = (s_os_driver_descriptor*)heap_alloc( NULL, sizeof(s_os_driver_descriptor), HEAP_ALIGN_4 );
  if( d == NULL ) return RES_VOID;
  memset( d, 0, sizeof(s_os_driver_descriptor) );

  // Lock descriptors list
  sem_lock( v_os_desc_list_sem, SEM_INFINITY );

  // Allocate descriptor slot and initialize new descriptor
l_retry:

  for( ; index < v_os_desc_list_length; index++ )
  {
    if( v_os_desc_list[index] == NULL )
    {
      if( ( d->sem = sem_alloc( 1, NULL ) ) == RES_VOID )
      {
        sem_unlock( v_os_desc_list_sem );
        heap_free( NULL, d );
        return RES_VOID;
      }
      d->ctx = &v_os_driver_root;
      d->own_process = v_os_current_process->id;
      d->id = RES_T_FSDESCRIPTOR | RES_F_USED | index;
      if( d->ctx->ioctl( d, IOC_INIT_DESCRIPTOR, NULL ) != OSE_OK )
      {
        sem_unlock( v_os_desc_list_sem );
        sem_free( d->sem );
        heap_free( NULL, d );
        return RES_VOID;
      }
      v_os_desc_list[index] = d;
      rid = d->id;
      break;
    }
  }

  if( index == v_os_desc_list_length )
  {
    uint32 t = sizeof(s_os_driver_descriptor*) * v_os_desc_list_length;
    s_os_driver_descriptor** nlist = (s_os_driver_descriptor**)heap_alloc( NULL, t << 1, HEAP_ALIGN_4 );
    if( nlist == NULL )
    {
      sem_unlock( v_os_desc_list_sem );
      heap_free( NULL, d );
      return RES_VOID;
    }
    memcpy( nlist, v_os_desc_list, t );
    memset( (uint8*)nlist + t, 0, t );
    v_os_desc_list_length <<= 1;
    heap_free( NULL, v_os_desc_list );
    v_os_desc_list = nlist;
    goto l_retry;
  }

  // Unlock descriptors list
  sem_unlock( v_os_desc_list_sem );

  // Goto specified path
  cunitc = os_driver_get_npunit_count( path );
  for( i = 0; i < cunitc; i++ )
  {
    cunit = os_driver_get_npunit( cunitp, pathlen, path );
    if( cunit == NULL ) break;
    r = drv_select( rid, cunit );
    heap_free( NULL, cunit );
    if( r != OSE_OK ) break;
  }
  if( i != cunitc )
  {
    drv_rmd( rid );
    return RES_VOID;
  }

  return rid;
}
// ---------------------------------------------------------------------------
// !: fn: int32 os_driver_rmd( uint32 rid )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall псевдоним:</b><br>
// !: d: <br>
// !: d: drv_rmd<br>
// !: d: <br>
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция удаляет дескриптор устройства/файла rid, созданный функцией
// !: d: drv_mkd.<br>
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
// !: d: <td>не корректный идентификатор ресурса rid;</td>
// !: d: </tr>
// !: d: </table><br>
// ---------------------------------------------------------------------------
int32 os_driver_rmd( uint32 rid )
{
  s_os_driver_descriptor* d;
  uint32 index;

  // Successfull result for VOID resource
  if( rid == RES_VOID ) return OSE_VOID_RESOURCE;

  // Lock descriptors list
  sem_lock( v_os_desc_list_sem, SEM_INFINITY );

  // Check descriptor identificator
  if( ( index = os_driver_descriptor_check( rid ) ) == 0xffffffff )
  {
    // Unlock descriptors list
    sem_unlock( v_os_desc_list_sem );
    return OSE_BAD_RDESC;
  }
  d = v_os_desc_list[index];
  // Unlock descriptors list
  sem_unlock( v_os_desc_list_sem );
  // Waiting while descriptor is busy
  sem_lock( d->sem, SEM_INFINITY );
  // Deinitialize descriptor
  if( d->ctx )
  {
    if( d->access & DRV_OPENED ) d->ctx->close( d );
    d->ctx->ioctl( d, IOC_DEINIT_DESCRIPTOR, NULL );
  }
  // Lock descriptors list
  sem_lock( v_os_desc_list_sem, SEM_INFINITY );
  // Clear descriptor slot
  v_os_desc_list[index] = NULL;
  // Unlock descriptors list
  sem_unlock( v_os_desc_list_sem );

  // Remove descriptor data
  heap_free( NULL, d->path );
  sem_free( d->sem );
  heap_free( NULL, d );

  return OSE_OK;
}
// ---------------------------------------------------------------------------
// !: fn: int32 os_driver_open( uint32 rid, uint16 access )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall псевдоним:</b><br>
// !: d: <br>
// !: d: drv_open<br>
// !: d: <br>
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция открывает режим потокового доступа (с режимом access) к
// !: d: устройству/файлу, на которое ссылается идентификатор ресурса rid.
// !: d: Переменная access задает режим доступа в виде комбинации флагов:<br><br>
// !: d: <table cellpadding=2 cellspacing=2 border=0>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>DRV_RD</td>
// !: d: <td> - </td>
// !: d: <td>запросить возможность чтения из потока;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>DRV_WR</td>
// !: d: <td> - </td>
// !: d: <td>запросить возможность записи в поток;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>DRV_EXCLUSIVE</td>
// !: d: <td> - </td>
// !: d: <td>запросить монопольный доступ, заданного режима.</td>
// !: d: </tr>
// !: d: </table><br>
// !: d: Возможность использования того или иного флага доступа определяется
// !: d: драйвером, обслуживающим устройство/файл rid.<br>
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
// !: d: <td>OSE_BAD_DCTX</td>
// !: d: <td> - </td>
// !: d: <td>в дескрипторе отсутствует контекст драйвера, обслуживающего
// !: d: текущее устройство/файл;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_BAD_RDESC</td>
// !: d: <td> - </td>
// !: d: <td>не корректный идентификатор ресурса rid;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_PERMISSION_DENIED</td>
// !: d: <td> - </td>
// !: d: <td>не достаточно прав для открытия устройства/файла в указанном режиме
// !: d: доступа.</td>
// !: d: </tr>
// !: d: </table><br>
// !: d: Так же возможны ошибки формируемые драйвером, обслуживающим текущий
// !: d: объект.
// ---------------------------------------------------------------------------
int32 os_driver_open( uint32 rid, uint16 access )
{
  s_os_driver_descriptor* d;
  s_os_driver_descriptor* cur_d;
  uint32 index;
  int32 r;

  if( rid == RES_VOID )
  {
    #ifdef OS_SUPPORT_SYSLOG
    syslog( 7, "%s:%d: Void resource descriptor", os_module, __LINE__ );
    #endif
    return OSE_VOID_RESOURCE;
  }

  // TODO: Translate local descriptor into global descriptor
  //       Rename rid into lrid
  //
  // grid = v_process->lrdt[lrid]; <-- descriptor translation
  // 
  // TODO: Check permissions
  //
  // 
  //

  sem_lock( v_os_desc_list_sem, SEM_INFINITY );

  if( ( index = os_driver_descriptor_check( rid ) ) == 0xffffffff )
  {
    sem_unlock( v_os_desc_list_sem );
    #ifdef OS_SUPPORT_SYSLOG
    syslog( 3, "%s:%d: Bad resource descriptor", os_module, __LINE__ );
    #endif
    return OSE_BAD_RDESC;
  }
  d = v_os_desc_list[index];
//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------  
  int i = 0;

  while( true )
  {
    if( i >= v_os_desc_list_length )
      break;

    cur_d = v_os_desc_list[i];
    if( (cur_d == NULL) || (i == index) )
    {
      i++;
      continue;
    }
    if( strcmp(d->path,cur_d->path) == 0)
    {
       if( (cur_d->access & DRV_WR) || ((cur_d->access & DRV_OPENED) && (access & DRV_WR)) )
       {
         sem_unlock( v_os_desc_list_sem );
         return OSE_PERMISSION_DENIED;
       }
    }
    i++;
  }
//-----------------------------------------------------------------------------------------  
//-----------------------------------------------------------------------------------------  
  sem_lockunlock( d->sem, v_os_desc_list_sem, SEM_INFINITY );
  if( d->ctx )
  {
    r = d->ctx->open( d, access );
    #ifdef OS_SUPPORT_SYSLOG
    if( r != OSE_OK ) syslog( 3, "%s:drv_open:%d: dev '%s' status = %d", os_module, __LINE__, d->path, r );
    #endif
  }
  else
  {
    r = OSE_BAD_DCTX;
    #ifdef OS_SUPPORT_SYSLOG
    syslog( 4, "%s:drv_open:%d: Null driver context (dev = '%s')", os_module, __LINE__, d->path );
    #endif
  }
  sem_unlock( d->sem );

  return r;
}
// ---------------------------------------------------------------------------
// !: fn: int32 os_driver_close( uint32 rid )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall псевдоним:</b><br>
// !: d: <br>
// !: d: drv_close<br>
// !: d: <br>
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция закрывает режим потокового чтения из устройства/файла, на
// !: d: которое ссылается идентификатор ресурса rid.<br>
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
// !: d: <td>OSE_BAD_DCTX</td>
// !: d: <td> - </td>
// !: d: <td>в дескрипторе отсутствует контекст драйвера, обслуживающего
// !: d: текущее устройство/файл;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_BAD_RDESC</td>
// !: d: <td> - </td>
// !: d: <td>не корректный идентификатор ресурса rid;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_PERMISSION_DENIED</td>
// !: d: <td> - </td>
// !: d: <td>нет прав для закрытия устройства/файла.</td>
// !: d: </tr>
// !: d: </table><br>
// !: d: Так же возможны ошибки формируемые драйвером, обслуживающим текущий
// !: d: объект.
// ---------------------------------------------------------------------------
int32 os_driver_close( uint32 rid )
{
  s_os_driver_descriptor* d;
  uint32 index;
  int32 r;

  if( rid == RES_VOID )
  {
    #ifdef OS_SUPPORT_SYSLOG
    syslog( 7, "%s:%d: Void resource descriptor", os_module, __LINE__ );
    #endif
    return OSE_VOID_RESOURCE;
  }

  sem_lock( v_os_desc_list_sem, SEM_INFINITY );

  if( ( index = os_driver_descriptor_check( rid ) ) == 0xffffffff )
  {
    sem_unlock( v_os_desc_list_sem );
    #ifdef OS_SUPPORT_SYSLOG
    syslog( 3, "%s:%d: Bad resource descriptor", os_module, __LINE__ );
    #endif
    return OSE_BAD_RDESC;
  }
  d = v_os_desc_list[index];

  sem_lockunlock( d->sem, v_os_desc_list_sem, SEM_INFINITY );
  if( d->ctx )
  {
    r = d->ctx->close( d );
    #ifdef OS_SUPPORT_SYSLOG
    if( r != OSE_OK ) syslog( 3, "%s:drv_close:%d: dev '%s' status = %d", os_module, __LINE__, d->path, r );
    #endif
  }
  else
  {
    r = OSE_BAD_DCTX;
    #ifdef OS_SUPPORT_SYSLOG
    syslog( 4, "%s:drv_close:%d: Null driver context (dev = '%s')", os_module, __LINE__, d->path );
    #endif
  }
  sem_unlock( d->sem );

  return r;
}
// ---------------------------------------------------------------------------
// !: fn: int32 os_driver_read( uint32 rid, void* buf, int32 length )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall псевдоним:</b><br>
// !: d: <br>
// !: d: drv_read<br>
// !: d: <br>
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция читает данные в буфер buf длиной length байт из потока данных,
// !: d: связанного с устройством/файлом на который ссылается идентификатор
// !: d: ресурсов rid.<br>
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: В случае успеха функция возвращает количество успешно прочитанных байт
// !: d: (число лежащее на отрезке от 0 до length), иначе одну из ошибок:<br><br>
// !: d: <table cellpadding=2 cellspacing=2 border=0>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_VOID_RESOURCE</td>
// !: d: <td> - </td>
// !: d: <td>идентификатор ресурса rid равен RES_VOID;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_BAD_DCTX</td>
// !: d: <td> - </td>
// !: d: <td>в дескрипторе отсутствует контекст драйвера, обслуживающего
// !: d: текущее устройство/файл;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_BAD_RDESC</td>
// !: d: <td> - </td>
// !: d: <td>не корректный идентификатор ресурса rid;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_PERMISSION_DENIED</td>
// !: d: <td> - </td>
// !: d: <td>нет прав для чтения из потока устройства/файла.</td>
// !: d: </tr>
// !: d: </table><br>
// !: d: Так же возможны ошибки формируемые драйвером, обслуживающим текущий
// !: d: объект.
// ---------------------------------------------------------------------------
int32 os_driver_read( uint32 rid, void* buf, int32 length )
{
  s_os_driver_descriptor* d;
  uint32 index;
  int32 r;

  if( rid == RES_VOID )
  {
    #ifdef OS_SUPPORT_SYSLOG
    syslog( 7, "%s:%d: Void resource descriptor", os_module, __LINE__ );
    #endif
    return OSE_VOID_RESOURCE;
  }

  sem_lock( v_os_desc_list_sem, SEM_INFINITY );

  if( ( index = os_driver_descriptor_check( rid ) ) == 0xffffffff )
  {
    sem_unlock( v_os_desc_list_sem );
    #ifdef OS_SUPPORT_SYSLOG
    syslog( 3, "%s:%d: Bad resource descriptor", os_module, __LINE__ );
    #endif
    return OSE_BAD_RDESC;
  }
  d = v_os_desc_list[index];

  sem_lockunlock( d->sem, v_os_desc_list_sem, SEM_INFINITY );
  if( d->ctx )
  {
    r = d->ctx->read( d, buf, length );
    #ifdef OS_SUPPORT_SYSLOG
    if( r < 0 ) syslog( 3, "%s:drv_read:%d: dev '%s' status = %d", os_module, __LINE__, d->path, r );
    #endif
  }
  else
  {
    r = OSE_BAD_DCTX;
    #ifdef OS_SUPPORT_SYSLOG
    syslog( 4, "%s:drv_read:%d: Null driver context (dev = '%s')", os_module, __LINE__, d->path );
    #endif
  }
  sem_unlock( d->sem );

  return r;
}
// ---------------------------------------------------------------------------
// !: fn: int32 os_driver_write( uint32 rid, const void* buf, int32 length )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall псевдоним:</b><br>
// !: d: <br>
// !: d: drv_write<br>
// !: d: <br>
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция пишет данные из буфера buf длиной length байт в поток данных,
// !: d: связанный с устройством/файлом на который ссылается идентификатор
// !: d: ресурсов rid.<br>
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: В случае успеха функция возвращает количество успешно записанных байт
// !: d: (число лежащее на отрезке от 0 до length), иначе одну из ошибок:<br><br>
// !: d: <table cellpadding=2 cellspacing=2 border=0>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_VOID_RESOURCE</td>
// !: d: <td> - </td>
// !: d: <td>идентификатор ресурса rid равен RES_VOID;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_BAD_DCTX</td>
// !: d: <td> - </td>
// !: d: <td>в дескрипторе отсутствует контекст драйвера, обслуживающего
// !: d: текущее устройство/файл;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_BAD_RDESC</td>
// !: d: <td> - </td>
// !: d: <td>не корректный идентификатор ресурса rid;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_PERMISSION_DENIED</td>
// !: d: <td> - </td>
// !: d: <td>нет прав для записи в поток устройства/файла.</td>
// !: d: </tr>
// !: d: </table><br>
// !: d: Так же возможны ошибки формируемые драйвером, обслуживающим текущий
// !: d: объект.
// ---------------------------------------------------------------------------
int32 os_driver_write( uint32 rid, const void* buf, int32 length )
{
  s_os_driver_descriptor* d;
  uint32 index;
  int32 r;

  if( rid == RES_VOID )
  {
    #ifdef OS_SUPPORT_SYSLOG
    syslog( 7, "%s:%d: Void resource descriptor", os_module, __LINE__ );
    #endif
    return OSE_VOID_RESOURCE;
  }

  sem_lock( v_os_desc_list_sem, SEM_INFINITY );

  if( ( index = os_driver_descriptor_check( rid ) ) == 0xffffffff )
  {
    sem_unlock( v_os_desc_list_sem );
    #ifdef OS_SUPPORT_SYSLOG
    syslog( 3, "%s:%d: Bad resource descriptor", os_module, __LINE__ );
    #endif
    return OSE_BAD_RDESC;
  }
  d = v_os_desc_list[index];

  sem_lockunlock( d->sem, v_os_desc_list_sem, SEM_INFINITY );
  if( d->ctx )
  {
    r = d->ctx->write( d, buf, length );
    #ifdef OS_SUPPORT_SYSLOG
    if( r < 0 ) syslog( 3, "%s:drv_write:%d: dev '%s' status = %d", os_module, __LINE__, d->path, r );
    #endif
  }
  else
  {
    r = OSE_BAD_DCTX;
    #ifdef OS_SUPPORT_SYSLOG
    syslog( 4, "%s:drv_write:%d: Null driver context (dev = '%s')", os_module, __LINE__, d->path );
    #endif
  }
  sem_unlock( d->sem );

  return r;
}
// ---------------------------------------------------------------------------
// !: fn: int32 os_driver_ioctl( uint32 rid, int32 cmd, const void* arg )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall псевдоним:</b><br>
// !: d: <br>
// !: d: drv_ioctl<br>
// !: d: <br>
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция оказывает управляющее воздействие cmd на устройство/файл, на
// !: d: который ссылается идентификатор ресурса rid. Переменная arg содержит
// !: d: аргументы для вызываемой команды.<br>
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
// !: d: <td>OSE_BAD_DCTX</td>
// !: d: <td> - </td>
// !: d: <td>в дескрипторе отсутствует контекст драйвера, обслуживающего
// !: d: текущее устройство/файл;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_BAD_RDESC</td>
// !: d: <td> - </td>
// !: d: <td>не корректный идентификатор ресурса rid;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_PERMISSION_DENIED</td>
// !: d: <td> - </td>
// !: d: <td>нет прав для выполнения управляющих воздействий.</td>
// !: d: </tr>
// !: d: </table><br>
// !: d: Так же возможны ошибки формируемые драйвером, обслуживающим текущий
// !: d: объект.
// ---------------------------------------------------------------------------
int32 os_driver_ioctl( uint32 rid, int32 cmd, const void* arg )
{
  s_os_driver_descriptor* d;
  uint32 index;
  int32 r;

  if( rid == RES_VOID )
  {
    #ifdef OS_SUPPORT_SYSLOG
    syslog( 7, "%s:%d: Void resource descriptor", os_module, __LINE__ );
    #endif
    return OSE_VOID_RESOURCE;
  }

  sem_lock( v_os_desc_list_sem, SEM_INFINITY );

  if( ( index = os_driver_descriptor_check( rid ) ) == 0xffffffff )
  {
    sem_unlock( v_os_desc_list_sem );
    #ifdef OS_SUPPORT_SYSLOG
    syslog( 3, "%s:%d: Bad resource descriptor", os_module, __LINE__ );
    #endif
    return OSE_BAD_RDESC;
  }
  d = v_os_desc_list[index];

  sem_lockunlock( d->sem, v_os_desc_list_sem, SEM_INFINITY );
  if( d->ctx )
  {
    r = d->ctx->ioctl( d, cmd, const_cast<void*>( arg ) );
    #ifdef OS_SUPPORT_SYSLOG
    if( r < 0 ) syslog( 3, "%s:drv_ioctl:%d: cmd = %08x dev = '%s' status = %d", os_module, __LINE__, cmd, d->path, r );
    #endif
  }
  else
  {
    r = OSE_BAD_DCTX;
    #ifdef OS_SUPPORT_SYSLOG
    syslog( 4, "%s:drv_ioctl:%d: Null driver context (cmd = %08x dev = '%s')", os_module, __LINE__, cmd, d->path );
    #endif
  }
  sem_unlock( d->sem );

  return r;
}
// ---------------------------------------------------------------------------
void os_driver_cleanup()
{
  s_os_driver_descriptor* cdesc;
  s_os_driver_context* cctx;
  uint32 i;

// -- Set unloading flag for all drivers loaded from this process  - - - - - -

  sem_lock( v_os_driver_list_sem, SEM_INFINITY );
  cctx = v_os_driver_list;
  while( cctx )
  {
    if( cctx->own_process == v_os_current_process->id ) cctx->flags |= DRV_F_UNLOADING;
    cctx = cctx->next;
  }
  sem_unlock( v_os_driver_list_sem );

// -- Unlink all descriptors from each driver owned by current process - - - -

  i = 0;
  while( true )
  {
    sem_lock( v_os_desc_list_sem, SEM_INFINITY );
    if( i >= v_os_desc_list_length )
    {
      sem_unlock( v_os_desc_list_sem );
      break;
    }
    cdesc = v_os_desc_list[i];
    if( cdesc == NULL )
    {
      sem_unlock( v_os_desc_list_sem );
      i++;
      continue;
    }
    if( cdesc->own_process == v_os_current_process->id )
    {
      sem_lockunlock( cdesc->sem, v_os_desc_list_sem, SEM_INFINITY );
      if( cdesc->access & DRV_OPENED ) cdesc->ctx->close( cdesc );
      cdesc->ctx = NULL;
      sem_unlock( cdesc->sem );
    }
    else
    {
      sem_unlock( v_os_desc_list_sem );
    }
    i++;
  }

// -- Unplug all drivers loaded from this process  - - - - - - - - - - - - - -

more_drivers:

  sem_lock( v_os_driver_list_sem, SEM_INFINITY );
  cctx = v_os_driver_list;
  while( cctx )
  {
    if( cctx->own_process == v_os_current_process->id )
    {
      sem_unlock( v_os_driver_list_sem );
      drv_unplug( cctx->name );
      goto more_drivers;
    }
    cctx = cctx->next;
  }
  sem_unlock( v_os_driver_list_sem );

// -- Remove all driver descriptors owned by process - - - - - - - - - - - - -

  i = 0;
  while( true )
  {
    sem_lock( v_os_desc_list_sem, SEM_INFINITY );
    if( i >= v_os_desc_list_length )
    {
      sem_unlock( v_os_desc_list_sem );
      break;
    }
    cdesc = v_os_desc_list[i];
    if( cdesc == NULL )
    {
      sem_unlock( v_os_desc_list_sem );
      i++;
      continue;
    }
    sem_unlock( v_os_desc_list_sem );
    if( cdesc->own_process == v_os_current_process->id ) drv_rmd( cdesc->id );
    i++;
  }

}
// ---------------------------------------------------------------------------
// !: fn: int32 os_driver_select( uint32 rid, const char* name )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall псевдоним:</b><br>
// !: d: <br>
// !: d: drv_select<br>
// !: d: <br>
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция выбирает устройство/файл (с именем name) среди дочерних
// !: d: устройств/файлов устройства/файла, на которое ссылается идентификатор
// !: d: ресурса rid. Если имя name равно "." выбирается текущее устройство/файл,
// !: d: если name равно "..", выбирается родительское устройство/файл.<br>
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
// !: d: <td>OSE_BAD_DCTX</td>
// !: d: <td> - </td>
// !: d: <td>в дескрипторе отсутствует контекст драйвера, обслуживающего
// !: d: текущее устройство/файл;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_BAD_RDESC</td>
// !: d: <td> - </td>
// !: d: <td>не корректный идентификатор ресурса rid;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_PERMISSION_DENIED</td>
// !: d: <td> - </td>
// !: d: <td>нет прав для перехода к объекту с именем name.</td>
// !: d: </tr>
// !: d: </table><br>
// !: d: Так же возможны ошибки формируемые драйвером, обслуживающим текущий
// !: d: объект.
// ---------------------------------------------------------------------------
int32 os_driver_select( uint32 rid, const char* name )
{
  s_os_driver_descriptor* d;
  uint32 index;
  int32 r;

  // Bad descriptor result for VOID resource
  if( rid == RES_VOID ) return OSE_VOID_RESOURCE;

  // Lock descriptors list
  sem_lock( v_os_desc_list_sem, SEM_INFINITY );

  // Check descriptor identificator
  if( ( index = os_driver_descriptor_check( rid ) ) == 0xffffffff )
  {
    // Unlock descriptors list
    sem_unlock( v_os_desc_list_sem );
    return OSE_BAD_RDESC;
  }
  d = v_os_desc_list[index];

  // Relock semaphores and call open function
  sem_lockunlock( d->sem, v_os_desc_list_sem, SEM_INFINITY );
  if( d->ctx ) r = d->ctx->ioctl( d, IOC_INODE_SELECT, const_cast<char*>( name ) ); else r = OSE_BAD_DCTX;
  sem_unlock( d->sem );

  return r;
}
// ---------------------------------------------------------------------------
// !: fn: int32 os_driver_create( uint32 rid, const char* name, uint8 type )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall псевдоним:</b><br>
// !: d: <br>
// !: d: drv_create<br>
// !: d: <br>
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция создает новый дочерний элемент с именем name и типом type у
// !: d: устройства/файла, на которое ссылается идентификатор ресурса rid.
// !: d: Переменная type может принимать значения INOT_FILE или INIT_FOLDER.<br>
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
// !: d: <td>OSE_BAD_DCTX</td>
// !: d: <td> - </td>
// !: d: <td>в дескрипторе отсутствует контекст драйвера, обслуживающего
// !: d: текущее устройство/файл;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_BAD_RDESC</td>
// !: d: <td> - </td>
// !: d: <td>не корректный идентификатор ресурса rid;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_PERMISSION_DENIED</td>
// !: d: <td> - </td>
// !: d: <td>нет прав для создания нового объекта.</td>
// !: d: </tr>
// !: d: </table><br>
// !: d: Так же возможны ошибки формируемые драйвером, обслуживающим текущий
// !: d: объект.
// ---------------------------------------------------------------------------
int32 os_driver_create( uint32 rid, const char* name, uint8 type )
{
  s_os_driver_descriptor* d;
  uint32 index;
  int32 r;

  // Bad descriptor result for VOID resource
  if( rid == RES_VOID ) return OSE_VOID_RESOURCE;

  // Lock descriptors list
  sem_lock( v_os_desc_list_sem, SEM_INFINITY );

  // Check descriptor identificator
  if( ( index = os_driver_descriptor_check( rid ) ) == 0xffffffff )
  {
    // Unlock descriptors list
    sem_unlock( v_os_desc_list_sem );
    return OSE_BAD_RDESC;
  }
  d = v_os_desc_list[index];

  // Relock semaphores and call open function
  sem_lockunlock( d->sem, v_os_desc_list_sem, SEM_INFINITY );
  if( d->ctx )
  {
    s_inode_create data;
    data.name = name;
    data.type = type;
    r = d->ctx->ioctl( d, IOC_INODE_CREATE, &data );
  }
  else
  {
    r = OSE_BAD_DCTX;
  }
  sem_unlock( d->sem );

  return r;
}
// ---------------------------------------------------------------------------
int32 os_driver_remove( uint32 rid, const char* name )
{
  s_os_driver_descriptor* d;
  s_os_driver_descriptor* cur_d;
  uint32 index;
  int32 r;

  // Bad descriptor result for VOID resource
  if( rid == RES_VOID ) return OSE_VOID_RESOURCE;

  // Lock descriptors list
relook:
  sem_lock( v_os_desc_list_sem, SEM_INFINITY );

  // Check descriptor identificator
  if( ( index = os_driver_descriptor_check( rid ) ) == 0xffffffff )
  {
    // Unlock descriptors list
    sem_unlock( v_os_desc_list_sem );
    return OSE_BAD_RDESC;
  }

  d = v_os_desc_list[index];

  os_driver_inc_path( d,name );

  int i = 0;

  while( true )
  {
    if( i >= v_os_desc_list_length )
      break;

    cur_d = v_os_desc_list[i];
    if( (cur_d == NULL) || (i == index) )
    {
      i++;
      continue;
    }
    if( strcmp(d->path,cur_d->path) == 0)
    {
      os_driver_dec_path( d );
      sem_unlock( v_os_desc_list_sem );
      sleep_m(100);
      goto relook;
    }
    i++;
  }
  os_driver_dec_path( d );
  // Relock semaphores and call open function
  sem_lockunlock( d->sem, v_os_desc_list_sem, SEM_INFINITY );
  if( d->ctx ) r = d->ctx->ioctl( d, IOC_INODE_REMOVE, name ); else r = OSE_BAD_DCTX;
  sem_unlock( d->sem );

  return r;
}
// ---------------------------------------------------------------------------
bool os_driver_inc_path( s_os_driver_descriptor* d, const char* name )
{
  if( name == NULL ) return false;
  int32 l = strlen( d->path ) + strlen( name ) + 2;
  bool ads = true;
  if( strcmp( d->path, "/" ) == 0 ) { l--; ads = false; }
  char* npath = (char*)heap_alloc( NULL, l, HEAP_ALIGN_4 );
  if( npath == NULL ) return false;
  strcpy( npath, d->path );
  if( ads ) strcat( npath, "/" );
  strcat( npath, name );
  heap_free( NULL, d->path );
  d->path = npath;
  return true;
}
// ---------------------------------------------------------------------------
bool os_driver_dec_path( s_os_driver_descriptor* d )
{
  int32 i;
  int32 l = strlen( d->path );
  if( l == 1 ) return is_slash( d->path[0] );
  for( i = l; i >= 0; i-- ) if( is_slash( d->path[i] ) ) break;
  if( i == -1 ) return false;
  if( i == 0 ) i++;
  char* npath = (char*)heap_alloc( NULL, i + 1, HEAP_ALIGN_4 );
  if( npath == NULL ) return false;
  memcpy( npath, d->path, i );
  npath[i] = 0;
  heap_free( NULL, d->path );
  d->path = npath;
  return true;
}
// ---------------------------------------------------------------------------
void os_driver_return_to_rfs( s_os_driver_descriptor* d )
{
  d->ctx->ioctl( d, IOC_DEINIT_DESCRIPTOR, NULL );
  d->data = NULL;
  d->ctx = &v_os_driver_root;
  d->ctx->ioctl( d, IOC_INIT_DESCRIPTOR, NULL );
}
// ---------------------------------------------------------------------------
// !: fn: void os_driver_list_destroy( s_inode* first )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall псевдоним:</b><br>
// !: d: <br>
// !: d: drv_list_destroy<br>
// !: d: <br>
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция удаляет список объектов, созданный функцией drv_list.<br>
// ---------------------------------------------------------------------------
void os_driver_list_destroy( s_inode* first )
{
  if( first == NULL ) return;
  s_inode* tnode;
  while( first->prev != NULL ) first = first->prev;
  while( first )
  {
    tnode = first;
    first = first->next;
    if( tnode->name ) delete[] tnode->name;
    delete tnode;
  }
}
// ---------------------------------------------------------------------------
// !: fn: int32 os_driver_list( uint32 rid, s_inode** list )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall псевдоним:</b><br>
// !: d: <br>
// !: d: drv_list<br>
// !: d: <br>
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция передает пользователю (через указатель list) список дочерних
// !: d: объектов, объекта на который ссылается идентификатор ресурса rid.
// !: d: После завершения использования список необходимо удалить, вызвав
// !: d: функцию drv_list_destroy.<br>
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
// !: d: <td>OSE_BAD_DCTX</td>
// !: d: <td> - </td>
// !: d: <td>в дескрипторе отсутствует контекст драйвера, обслуживающего
// !: d: текущее устройство/файл;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_BAD_RDESC</td>
// !: d: <td> - </td>
// !: d: <td>не корректный идентификатор ресурса rid;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_PERMISSION_DENIED</td>
// !: d: <td> - </td>
// !: d: <td>нет прав для чтения списка дочерних объектов.</td>
// !: d: </tr>
// !: d: </table><br>
// !: d: Так же возможны ошибки формируемые драйвером, обслуживающим текущий
// !: d: объект.
// ---------------------------------------------------------------------------
int32 os_driver_list( uint32 rid, s_inode** list )
{
  s_os_driver_descriptor* d;
  uint32 index;
  int32 r;

  // Bad descriptor result for VOID resource
  if( rid == RES_VOID ) return OSE_VOID_RESOURCE;

  // Lock descriptors list
  sem_lock( v_os_desc_list_sem, SEM_INFINITY );

  // Check descriptor identificator
  if( ( index = os_driver_descriptor_check( rid ) ) == 0xffffffff )
  {
    // Unlock descriptors list
    sem_unlock( v_os_desc_list_sem );
    return OSE_BAD_RDESC;
  }
  d = v_os_desc_list[index];

  // Relock semaphores and call open function
  sem_lockunlock( d->sem, v_os_desc_list_sem, SEM_INFINITY );
  if( d->ctx ) r = d->ctx->ioctl( d, IOC_INODE_LIST, list ); else r = OSE_BAD_DCTX;
  sem_unlock( d->sem );

  return r;
}
// ---------------------------------------------------------------------------
int32 os_driver_rename( uint32 rid, const char* name )
{
  s_os_driver_descriptor* d;
  uint32 index;
  int32 r;

  // Bad descriptor result for VOID resource
  if( rid == RES_VOID ) return OSE_VOID_RESOURCE;
  if( name == NULL ) return OSE_NULL_PARAM;

  // Lock descriptors list
  sem_lock( v_os_desc_list_sem, SEM_INFINITY );

  // Check descriptor identificator
  if( ( index = os_driver_descriptor_check( rid ) ) == 0xffffffff )
  {
    // Unlock descriptors list
    sem_unlock( v_os_desc_list_sem );
    return OSE_BAD_RDESC;
  }
  d = v_os_desc_list[index];

  // Relock semaphores and call open function
  sem_lockunlock( d->sem, v_os_desc_list_sem, SEM_INFINITY );
  register s_os_driver_context* ctx = d->ctx;
  if( ctx )
  {
    if( memcmp( name, ctx->path, strlen(ctx->path) ) == 0 )
    {
      r = ctx->ioctl( d, IOC_INODE_RENAME, name );
    }
    else
    {
      // todo: copy object
      r = OSE_FAIL;
    }
  }
  else
  {
    r = OSE_BAD_DCTX;
  }
  sem_unlock( d->sem );

  return r;
}
// ---------------------------------------------------------------------------
