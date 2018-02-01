#include <__fs.h>
#include <rts.h>
// ---------------------------------------------------------------------------
#ifdef FS_PACKCHAR
#
#  if defined( FS_PACK_LE ) && defined( FS_PACK_BE )
#    undef FS_PACK_BE
#  endif
#
#  if !defined( FS_PACK_LE ) && !defined( FS_PACK_BE )
#    define FS_PACK_LE
#  endif
#
#  define FS_RW_BUF_LEN 64
#
#endif
// ---------------------------------------------------------------------------

File* curWorkDir = NULL;

// ---------------------------------------------------------------------------
FS_INT16 get_object_count( FS_CHAR* path )
{
  FS_INT16 res,i;
  if( path == NULL ) return 0;
  if( ( path[0] == '/' ) && ( path[1] == 0 ) ) return 0;
  for( res = 0, i = strlen( path ) - 1; i >= 0; i-- ) if( path[i] == '/' ) res++;
  if( path[0] != '/' ) res++;
  return res;
}
// ---------------------------------------------------------------------------
void get_object_name_boundary( FS_CHAR* path, FS_INT16 n, FS_INT16* pStart, FS_INT16* pEnd )
{
  FS_INT16 i, stl, cobj;
  (*pStart) = 0;
  (*pEnd) = 0;
  stl = strlen( path );
  for( cobj = 0, i = 0; i < stl; i++ )
  {
    if( ( path[i] == '/' ) || ( i == 0 ) )
    {
      if( cobj == n )
      {
        if( path[i] == '/' ) (*pStart) = ++i;
        for( ; i <= stl; i++ ) if( ( path[i] == '/' ) || ( path[i] == 0 ) ) { *pEnd = i; return; }
        (*pStart) = 0;
        return;
      }
      else
      {
        cobj++;
      }
    }
  }
}
// ---------------------------------------------------------------------------
FS_CHAR* normalize_path( FS_CHAR* path )
{
  FS_INT32 stl, i, j, a;
  FS_CHAR* res;
  FS_BOOL bb;

  if( path == NULL ) return NULL;
  stl = strlen( path ) + 1;

  if( path[1] == ':' )
  {
    if( ( path[2] != '/' ) && ( path[2] != '\\' ) ) bb = FS_TRUE; else bb = FS_FALSE;
//    if( bb ) res = new FS_CHAR[stl+1]; else res = new FS_CHAR[stl];
    if( bb ) res = (FS_CHAR*)fs_alloc( stl + 1 ); else res = (FS_CHAR*)fs_alloc( stl );
    if( res == NULL ) return NULL;
    res[0] = '/';
    res[1] = path[0];
    res[2] = '/';
    if( bb ) a = 2; else a = 3;
    for( i = a, j = 3; i < stl; i++, j++ )
    {
      if( path[i] == '\\' ) { res[j] = '/'; continue; }
      res[j] = path[i];
    }
    if( res[j-2] == '/' ) res[j-2] = 0;
  }
  else
  {
    res = (FS_CHAR*)fs_alloc( stl ); //new FS_CHAR[stl];
    if( res == NULL ) return NULL;
    for( i = 0; i < stl; i++ )
    {
      if( path[i] == '\\' ) { res[i] = '/'; continue; }
      res[i] = path[i];
    }
    if( stl != 2 ) if( res[stl-2] == '/' ) res[stl-2] = 0;
  }

  return res;
}
// ---------------------------------------------------------------------------
FS_UINT16 fs_goto( OLD_FILE* f, FS_CHAR* path, FS_INT16 nStep )
{
  FS_INT16 i;
  FS_UINT16 res;
  FS_INT16 ps,pe;
  FS_CHAR tc;

  for( i = 0; i < nStep; i++ )
  {
    get_object_name_boundary( path, i, &ps, &pe );
    tc = path[pe];
    path[pe] = 0;
    res = f->switchObjectTo( path + ps );
    path[pe] = tc;
    if( res != 0 ) return res;
  }

  return 0;
}
// ---------------------------------------------------------------------------
OLD_FILE* old_fopen( FS_CHAR* path, FS_CHAR* mode )
{
  FS_BOOL createIfNotExists = FS_FALSE;
  FS_BOOL seekToEnd = FS_FALSE;
  FS_BOOL needRecreate = FS_FALSE;
  FS_INT32 accessMode = 0;
  File* newFlow = NULL;
  FS_INT16 stl, i, ps, pe, res;
  FS_PCHAR nPath;

  if( ( path == NULL ) || ( mode == NULL ) ) return NULL;

  for( stl = strlen( mode ), i = 0; i < stl; i++ )
  {
    switch( mode[i] )
    {
      case 'r': accessMode |= FL_READ; break;
      case 'w': accessMode |= FL_WRITE; createIfNotExists = FS_TRUE; needRecreate = FS_TRUE; break;
      case 'a': accessMode |= FL_WRITE; createIfNotExists = FS_TRUE; seekToEnd = FS_TRUE; break;
      case '+':
      {
        if( accessMode == FL_READ ) { createIfNotExists = FS_FALSE; }
        accessMode |= ( FL_WRITE | FL_READ );
      }
      break;
    }
  }

  nPath = normalize_path( path );
  if( nPath == NULL ) return NULL;

  FS_REINIT_LOCK();
  dev.reInitLogicDisks( nPath[1] );
  FS_REINIT_UNLOCK();

  newFlow = new File;
  if( newFlow == NULL ) return NULL;

  stl = get_object_count( nPath );
  if( fs_goto( newFlow, nPath, stl - 1 ) != 0 )
  {
    delete newFlow;
    return NULL;
  }
  get_object_name_boundary( nPath, stl - 1, &ps, &pe );

  if( ( ((FATFileData*)newFlow->data)->attributes & FAT_ATTR_DIR ) == 0 )
  {
    delete newFlow;
    return NULL;
  }

  if( needRecreate )
  {
    if( ( res = newFlow->removeObject( nPath + ps ) ) != 0 )
    {
      if( res != FS_WR_NOT_ENOUGHT_RECORDS )
      {
        delete newFlow;
        return NULL;
      }
    }
  }

  if( newFlow->switchObjectTo( nPath + ps ) )
  {
    if( createIfNotExists )
    {
      if( newFlow->createObject( nPath + ps, FAT_ATTR_ARCHIVE ) != 0 )
      {
        delete newFlow;
        return NULL;
      }
      if( newFlow->switchObjectTo( nPath + ps ) != 0 )
      {
        delete newFlow;
        return NULL;
      }
    }
    else
    {
      delete newFlow;
      return NULL;
    }
  }
  else
  {
    if( ( ((FATFileData*)newFlow->data)->attributes & FAT_ATTR_DIR ) != 0 )
    {
      newFlow->close();
      delete newFlow;
      return NULL;
    }
  }

  if( newFlow->open( accessMode ) != 0 )
  {
    delete newFlow;
    return NULL;
  }

  if( seekToEnd )
  {
    if( newFlow->seek( 0, OLD_SEEK_END ) != 0 )
    {
      newFlow->close();
      delete newFlow;
      return NULL;
    }
  }

  return newFlow;
}
// ---------------------------------------------------------------------------
FS_UINT32 old_fread( void* ptr, FS_UINT32 size, FS_UINT32 n, OLD_FILE* stream )
{
  if( stream == NULL ) return 0;
  if( size == 0 ) return 0;

  #ifdef FS_PACKCHAR

  FS_UINT16 fs_posix_rw_buf[FS_RW_BUF_LEN];
  FS_UINT16* bufptr;
  FS_UINT32 length = ( size * n ) << 1;
  FS_UINT16* pptr = (FS_UINT16*)ptr;
  FS_UINT32 readed = 0;
  FS_UINT32 tmp, i;
  FS_UINT32 rsize;

  while( length != 0 )
  {
    if( length < FS_RW_BUF_LEN ) rsize = length; else rsize = FS_RW_BUF_LEN;
    stream->read( (void*)fs_posix_rw_buf, rsize );
    tmp = stream->getRWCounter();
    bufptr = fs_posix_rw_buf;
    i = tmp >> 1;
    while( i-- )
    {
      #ifdef FS_PACK_LE
      (*pptr) = (*bufptr);
      bufptr++;
      (*pptr) |= (*bufptr) << 8;
      bufptr++;
      pptr++;
      #endif
      #ifdef FS_PACK_BE
      (*pptr) = (*bufptr) << 8;
      bufptr++;
      (*pptr) |= (*bufptr);
      bufptr++;
      pptr++;
      #endif
    }
    if( tmp & 1 )
    {
      #ifdef FS_PACK_LE
      (*pptr) = (*bufptr);
      #endif
      #ifdef FS_PACK_BE
      (*pptr) = (*bufptr) << 8;
      #endif
    }
    readed += tmp;
    if( tmp != rsize ) return ( readed / size ) >> 1;
    length -= rsize;
  }

  return ( readed / size ) >> 1;

  #else

  stream->read( ptr, size * n );
  return stream->getRWCounter() / size;

  #endif
}
// ---------------------------------------------------------------------------
FS_UINT32 old_fwrite( void* ptr, FS_UINT32 size, FS_UINT32 n, OLD_FILE* stream )
{
  if( stream == NULL ) return 0;
  if( size == 0 ) return 0;

  #ifdef FS_PACKCHAR

  FS_UINT16 fs_posix_rw_buf[FS_RW_BUF_LEN];
  FS_UINT16* bufptr;
  FS_UINT32 length = ( size * n ) << 1;
  FS_UINT16* pptr = (FS_UINT16*)ptr;
  FS_UINT32 writed = 0;
  FS_UINT32 tmp, i;
  FS_UINT32 wsize;

  while( length != 0 )
  {
    if( length < FS_RW_BUF_LEN ) wsize = length; else wsize = FS_RW_BUF_LEN;
    bufptr = fs_posix_rw_buf;
    i = wsize >> 1;
    while( i-- )
    {
      #ifdef FS_PACK_LE
      (*bufptr) = (*pptr) & 0x00ff;
      bufptr++;
      (*bufptr) = ( (*pptr) >> 8 ) & 0x00ff; // <-- paranoia, I'm fear to remove operator >> 0x00ff. Someone! Do it for me ;)
      bufptr++;
      pptr++;
      #endif
      #ifdef FS_PACK_BE
      (*bufptr) = ( (*pptr) >> 8 ) & 0x00ff; // <-- paranoia, I'm fear to remove operator >> 0x00ff. Someone! Do it for me ;)
      bufptr++;
      (*bufptr) = (*pptr) & 0x00ff;
      bufptr++;
      pptr++;
      #endif
    }
    stream->write( (void*)fs_posix_rw_buf, wsize );
    tmp = stream->getRWCounter();
    writed += tmp;
    if( tmp != wsize ) return ( writed / size ) >> 1;
    length -= wsize;
  }

  return ( writed / size ) >> 1;

  #else

  stream->write( ptr, size * n );
  return stream->getRWCounter() / size;

  #endif
}
// ---------------------------------------------------------------------------
FS_INT32 old_fseek( OLD_FILE* stream, FS_INT32 offset, FS_UINT32 whence )
{
  FS_UINT16 res;
  errno = 0;
  if( stream == NULL ) { errno = EBADF; return EBADF; }
  if( ( whence != OLD_SEEK_SET ) && ( whence != OLD_SEEK_CUR ) && ( whence != OLD_SEEK_END ) ) { errno = EINVAL; return EINVAL; }
  #ifdef FS_PACKCHAR
  res = stream->seek( offset << 1, whence );
  #else
  res = stream->seek( offset, whence );
  #endif
  if( res != 0 ) { errno = ESPIPE; return ESPIPE; }
  return 0;
}
// ---------------------------------------------------------------------------
FS_UINT32 old_ftell( OLD_FILE* stream )
{
  FS_UINT16 res;
  FS_UINT32 offset;
  errno = 0;
  if( stream == NULL ) { errno = EBADF; return 0xffffffff; }
  res = stream->tell( &offset );
  if( res != 0 ) { errno = ESPIPE; return 0xffffffff; }
  #ifdef FS_PACKCHAR
  return offset >> 1;
  #else
  return offset;
  #endif
}
// ---------------------------------------------------------------------------
FS_INT32 old_remove( FS_CHAR* path )
{
  FS_PCHAR nPath;
  File* f = new File;
  FS_INT16 ps, pe;
  errno = 0;
  if( f == NULL ) return -1;
  if( path == NULL ) { delete f; errno = EINVAL; return -1; }
  nPath = normalize_path( path );
  if( nPath == NULL ) { delete f; errno = ENOMEM; return -1; }
  if( nPath[0] != '/' )
  {
    if( fs_goto( f, curWorkDir->data->getPath(), get_object_count( curWorkDir->data->getPath() ) ) != 0 ) { delete f; return -1; }
  }
  if( fs_goto( f, nPath, get_object_count( nPath ) - 1 ) != 0 ) { delete f; return -1; }
  get_object_name_boundary( nPath, get_object_count( nPath ) - 1, &ps, &pe );
  if( f->rmfile( nPath + ps ) != 0 ) { errno = ENOENT; delete f; return -1; }
  delete f;
  return 0;
}
// ---------------------------------------------------------------------------
FS_INT32 old_rename( FS_CHAR* oldpath, FS_CHAR* newpath )
{
  FS_PCHAR nPath;
  if( ( oldpath == NULL ) || ( newpath == NULL ) ) { errno = EINVAL; return -1; }
  nPath = normalize_path( oldpath );
  if( nPath == NULL ) { errno = ENOMEM; return -1; }
  File* f = new File();
  if( f == NULL ) return -1;
  if( fs_goto( f, nPath, get_object_count( nPath ) ) != 0 ) { errno = ENOENT; delete f; return -1; }
  if( f->rename( newpath ) != 0 ) { delete f; return -1; }
  delete f;
  return 0;
}
// ---------------------------------------------------------------------------
FS_INT32 old_feof( OLD_FILE* stream )
{
  FS_BOOL eof;
  if( stream == NULL ) return 1;
  if( stream->eof( &eof ) != 0 ) return 1;
  if( eof ) return 1;
  return 0;
}
// ---------------------------------------------------------------------------
FS_INT32 old_fclose( OLD_FILE*& stream )
{
  FS_UINT16 res;
  if( stream == NULL ) return EOF;
  res = stream->close();
  delete stream;
  stream = NULL;
  if( res != 0 ) return EOF;
  return 0;
}
// ---------------------------------------------------------------------------
/*
FS_INT32 old_chdir( FS_CHAR* path )
{
  FS_CHAR* cwd;
  FS_INT16 nCObj;
  FS_INT16 i;
  FS_UINT16 res;
  FS_PCHAR normPath;
  FS_INT16 nObj;
  FS_PCHAR oldPath;

  if( curWorkDir == NULL )
  {
    curWorkDir = new File;
    if( curWorkDir == NULL ) return -1;
    cwd = NULL;
    nCObj = 0;
  }
  else
  {
    cwd = curWorkDir->data->getPath();
    nCObj = get_object_count( cwd );
  }
  errno = ENOENT;
  normPath = normalize_path( path );
  nObj = get_object_count( normPath );
  if( ( path == NULL ) || ( normPath == NULL ) ) return -1;
  if( cwd != NULL )
  {
    res = strlen( cwd ) + 1;
    oldPath = new FS_CHAR[res];
    if( oldPath == NULL ) return -1;
    strcpy( oldPath, cwd );
  }
  if( normPath[0] == '/' )
  {
    for( i = 0; i < nCObj; i++ ) if( ( res = curWorkDir->switchObjectTo( const_fs_BackPointer ) ) != 0 ) return -1;
    if( ( res = fs_goto( curWorkDir, normPath, nObj ) ) != 0 )
    {
      cwd = curWorkDir->data->getPath();
      FS_INT16 cwL = get_object_count( cwd );
      for( i = 0; i < cwL; i++ ) if( ( res = curWorkDir->switchObjectTo( const_fs_BackPointer ) ) != 0 ) return -1;
      if( oldPath != NULL ) fs_goto( curWorkDir, oldPath, nCObj );
      return -1;
    }
  }
  else
  {
    if( ( res = fs_goto( curWorkDir, normPath, nObj ) ) != 0 )
    {
      cwd = curWorkDir->data->getPath();
      FS_INT16 cwL = get_object_count( cwd );
      for( i = 0; i < cwL; i++ ) if( ( res = curWorkDir->switchObjectTo( const_fs_BackPointer ) ) != 0 ) return -1;
      if( oldPath != NULL ) fs_goto( curWorkDir, oldPath, nCObj );
      return -1;
    }
  }
  errno = 0;
  return 0;
}
*/
// ---------------------------------------------------------------------------
FS_UINT32 old_fsize( OLD_FILE* stream )
{
  FS_UINT32 fileSize;
  errno = 0;
  if( stream == NULL ) { errno = EBADF; return 0xffffffff; }
  if( stream->size( &fileSize ) != 0 ) { errno = ESPIPE; return 0xffffffff; }
  #ifdef FS_PACKCHAR
  return fileSize >> 1;
  #else
  return fileSize;
  #endif
}
// ---------------------------------------------------------------------------
/*
FS_UINT32 old_fsize( FS_CHAR* fileName )
{
  FS_UINT32 fileSize;
  OLD_FILE* f = old_fopen( fileName,"r" );
  if( f == NULL ) { errno = ENOENT; return 0xffffffff;}
  fileSize = old_fsize( f );
  old_fclose( f );
  return fileSize;
}
*/
// ---------------------------------------------------------------------------
FS_UINT32 old_ftrim( OLD_FILE* stream, FS_UINT32 position )
{
  FS_UINT16 res;
  errno = 0;
  if( stream == NULL ) { errno = EBADF; return 0xffffffff; }
  #ifdef FS_PACKCHAR
  res = stream->trim( position << 1 );
  #else
  res = stream->trim( position );
  #endif
  if( res != 0 ) return 0xffffffff;
  return position;
}
// ---------------------------------------------------------------------------
/*
FS_BOOL old_findfirst( FS_CHAR* mask, FREC* frec, FS_INT16 attr )
{
  FS_UINT16 res;
  if( curWorkDir == NULL )
  {
    curWorkDir = new File;
    if( curWorkDir == NULL ) return FS_FALSE;
  }
  res = curWorkDir->findFirst( mask, attr, frec );
  if( res != 0 ) return FS_FALSE;
  return FS_TRUE;
}
*/
// ---------------------------------------------------------------------------
/*
FS_BOOL old_findnext( FREC* frec )
{
  FS_UINT16 res = curWorkDir->findNext( frec );
  if( res != 0 ) return FS_FALSE;
  return FS_TRUE;
}
*/
// ---------------------------------------------------------------------------
/*
void old_findclose()
{
  curWorkDir->findClose();
}
*/
// ---------------------------------------------------------------------------
/*
FS_BOOL old_fcopy( FS_CHAR* from_file_name, FS_CHAR* to_file_name )
{
  OLD_FILE* from_file;
  OLD_FILE* to_file;
  FS_CHAR buf[128];
  FS_UINT32 i, bigSectNum, ffSize;

  if( ( from_file = old_fopen( from_file_name, "r" ) ) == NULL ) return FS_FALSE;
  if( ( to_file = old_fopen( to_file_name, "w" ) ) == NULL )
  {
    old_fclose( from_file );
    return FS_FALSE;
  }

  ffSize = old_fsize( from_file );
  bigSectNum = ffSize >> 7;
  for( i = 0; i < bigSectNum; i++ )
  {
    if( from_file->read( buf, 128 ) != 0 )
    {
      old_fclose( from_file );
      old_fclose( to_file );
      return FS_FALSE;
    }
    if( to_file->write( buf, 128 ) != 0 )
    {
      old_fclose( from_file );
      old_fclose( to_file );
      return FS_FALSE;
    }
  }
  bigSectNum = ffSize & 0x0000007f;
  if( from_file->read( buf, bigSectNum ) != 0 )
  {
    old_fclose( from_file );
    old_fclose( to_file );
    return FS_FALSE;
  }
  if( to_file->write( buf, bigSectNum ) != 0 )
  {
    old_fclose( from_file );
    old_fclose( to_file );
    return FS_FALSE;
  }

  old_fclose( from_file );
  old_fclose( to_file );

  return FS_TRUE;
}
*/
// ---------------------------------------------------------------------------
/*
FS_UINT32 disk_free_space( FS_CHAR disk )
{
  FS_CHAR tmp[2];
  FS_UINT32 res;
  File* f = new File;
  if( f == NULL )return 0xffffffff;
  tmp[0] = disk; tmp[1] = 0;
  if( f->switchObjectTo( tmp ) != 0 )
  {
    res = 0xffffffff;
  }
  else
  {
    if( f->getFreeSpaceInBytes( &res ) != 0 ) res = 0xffffffff;
  }
  delete f;
  return res;
}
*/
// ---------------------------------------------------------------------------
/*
FS_UINT32 disk_size( FS_CHAR disk )
{
  FS_CHAR tmp[2];
  FS_UINT32 res;
  File* f = new File;
  if( f == NULL ) return 0xffffffff;
  tmp[0] = disk; tmp[1] = 0;
  if( f->switchObjectTo( tmp ) != 0 )
  {
    res = 0xffffffff;
  }
  else
  {
    if( f->getSize( &res ) != 0 ) res = 0xffffffff;
  }
  delete f;
  return res;
}
*/
// ---------------------------------------------------------------------------
/*
FS_CHAR* disk_lable( FS_CHAR disk )
{
  FS_CHAR tmp[2];
  FS_CHAR mask[2];
  FS_CHAR* res = NULL;
  File* f = new File();
  FileInfo finf;
  FS_BOOL ff;

  if( f == NULL ) goto get_from_ldinf;
  tmp[0] = fsUtils::upCase( disk ) - 'A' + 'a'; tmp[1] = 0;
  mask[0] = '*'; mask[1] = 0;
  if( f->switchObjectTo( tmp ) == 0 )
  {
    ff = (FS_BOOL)( f->findFirst( mask, FAT_ATTR_LABLE, &finf ) == 0 );
    while( ff )
    {
      if( finf.name[0] != '.' )
      {
        res = new FS_CHAR[strlen(finf.name)+1];
        if( res == NULL )break;
        strcpy( res, finf.name );
        break;
      }
      ff = (FS_BOOL)( f->findNext( &finf ) == 0 );
    }
    if( !ff )
    {
      LogicDiskInfo* ldInfo;
      get_from_ldinf:
      if( logicDisk.getInfo( fsUtils::upCase( disk ) - 'A', &ldInfo ) == 0 )
      {
        res = new FS_CHAR[strlen(ldInfo->lable)+1];
        if( res != NULL ) strcpy(res,ldInfo->lable);
      }
    }
  }
  else
  {
    goto get_from_ldinf;
  }
  if( f != NULL ) delete f;

  return res;
}
*/
// ---------------------------------------------------------------------------
/*
FS_BOOL write_lable( FS_CHAR disk, FS_CHAR* lable )
{
  FS_CHAR tmp[2];
  File* f = new File();

  if( f == NULL ) return FS_FALSE;
  tmp[0] = disk; tmp[1] = 0;
  if( f->switchObjectTo( tmp ) != 0 ) return FS_FALSE;
  if( f->open( FL_READ | FL_WRITE ) != 0 ) return FS_FALSE;
  if( f->writeLable( lable ) != 0 ) return FS_FALSE;
  f->close();
  delete f;

  return FS_TRUE;
}
*/
// ---------------------------------------------------------------------------
OLD_DIR* old_opendir( FS_CHAR* name )
{
  FS_PCHAR nPath;

  nPath = normalize_path( name );
  if( nPath == NULL ) return NULL;

  OLD_DIR* dir = new Dir;
  if( dir == NULL ) return NULL;

  FS_REINIT_LOCK();
  dev.reInitLogicDisks( nPath[1] );
  FS_REINIT_UNLOCK();

  if( fs_goto( dir, nPath, get_object_count( nPath ) ) != 0 )
  {
    delete dir;
    return NULL;
  }

  if( (((FATFileData*)dir->data)->attributes & FAT_ATTR_DIR ) == 0 )
  {
    delete dir;
    return NULL;
  }

  if( dir->open( FL_READ ) != 0 )
  {
    delete dir;
    return NULL;
  }

  return dir;
}
// ---------------------------------------------------------------------------
FS_INT32 old_closedir( OLD_DIR*& dir )
{
  if( dir == NULL )
  {
    errno = EBADF;
    return -1;
  }
  dir->close();
  delete dir;
  dir = NULL;
  return 0;
}
// ---------------------------------------------------------------------------
old_dirent* old_readdir( OLD_DIR* dir )
{
  if( dir == NULL ) return NULL;
  switch( dir->ssp )
  {
    case 0:
    {
      FREC fRec;
      FS_INT32 t;
      if( dir->findFirst( "*", 0, &fRec ) != 0 ) { dir->ssp = 2; return NULL; }
      if( fRec.attr == FAT_ATTR_LABLE ) {
        if( dir->findNext( &fRec ) != 0 ) { dir->ssp = 2; return NULL; }
      }
      dir->ssp = 1;
      memset( &dir->rec, 0, sizeof(old_dirent) );
      t = strlen( fRec.name );
      if( t > 255 ) t = 255;
      memcpy( &dir->rec.d_name, fRec.name, t );
      dir->rec.d_name[t] = 0;
      if( fRec.attr & FAT_ATTR_DIR ) dir->rec.d_type = DT_DIR; else dir->rec.d_type = DT_REG;
    }
    break;
    case 1:
    {
      FREC fRec;
      FS_INT32 t;
      if( dir->findNext( &fRec ) != 0 ) { dir->ssp = 2; return NULL; }
      if( fRec.attr == FAT_ATTR_LABLE ) {
        if( dir->findNext( &fRec ) != 0 ) { dir->ssp = 2; return NULL; }
      }
      t = strlen( fRec.name );
      if( t > 255 ) t = 255;
      memcpy( &dir->rec.d_name, fRec.name, t );
      dir->rec.d_name[t] = 0;
      if( fRec.attr & FAT_ATTR_DIR ) dir->rec.d_type = DT_DIR; else dir->rec.d_type = DT_REG;
    }
    break;
    case 2:
    {
      dir->ssp = 3;
      dir->findClose();
      return NULL;
    }
    case 3: return NULL;
  }

  return &dir->rec;
}
// ---------------------------------------------------------------------------
FS_INT32 old_mkdir( FS_CHAR* path )
{
  FS_UINT16 res;
  OLD_FILE* f = new File;
  FS_PCHAR nPath = normalize_path( path );
  FS_UINT16 cnt = get_object_count( nPath );
  FS_INT16 ps, pe;
  if( ( f == NULL ) || ( path == NULL ) || ( nPath == NULL ) ) return EINVAL;
  if( fs_goto( f, nPath, cnt - 1 ) != 0 )
  {
    delete f;
    return ENOENT;
  }
  get_object_name_boundary( nPath, cnt - 1, &ps, &pe );
  res = f->mkdir( nPath + ps );
  delete f;
  if( res != 0 ) return EOF;
  return 0;
}
// ---------------------------------------------------------------------------
FS_INT32 old_rmdir( FS_CHAR* path )
{
  FS_UINT16 res;
  OLD_FILE* f = new File;
  FS_PCHAR nPath = normalize_path( path );
  FS_UINT16 cnt = get_object_count( nPath );
  FS_INT16 ps, pe;
  if( ( f == NULL ) || ( path == NULL ) || ( nPath == NULL ) ) return EINVAL;
  if( fs_goto( f, nPath, cnt - 1 ) != 0 )
  {
    delete f;
    return ENOENT;
  }
  get_object_name_boundary( nPath, cnt - 1, &ps, &pe );
  res = f->rmdir( nPath + ps );
  delete f;
  if( res != 0 ) return ENOENT;
  return 0;
}
// ---------------------------------------------------------------------------
/*
FS_CHAR* old_getcwd(FS_CHAR* buf, FS_INT16 buflen)
{
  errno = 0;
  if( curWorkDir == NULL )
  {
    curWorkDir = new File;
    buf[0] = 0;
    if( curWorkDir == NULL ) return NULL;
    errno = ENODEV;
  }
  if( buf == NULL )
  {
    FS_CHAR* res = new FS_CHAR[strlen(curWorkDir->data->getPath())+1];
    if( res == NULL )
    {
      errno = ENOMEM;
      return NULL;
    }
    strcpy( res, curWorkDir->data->getPath() );
    return res;
  }
  if( buflen < ( strlen( curWorkDir->data->getPath() ) + 1 ) )
  {
    errno = ERANGE;
    return NULL;
  }
  strcpy( buf, curWorkDir->data->getPath() );
  return NULL;
}
*/
// ---------------------------------------------------------------------------
FS_INT32 old_fputs( const FS_CHAR* s, OLD_FILE* f )
{
  if( old_fwrite( (void*)s, 1, strlen( s ), f ) != strlen( s ) ) return EOF;
  return 0;
}
// ---------------------------------------------------------------------------
/*
FS_CHAR* old_fgets( FS_CHAR* buf, FS_INT32 len, OLD_FILE* f )
{
  FS_BOOL readed = FS_FALSE;
  FS_CHAR c;
  FS_INT32 i = 0;

  if( len < 2 ) return NULL;

  while( FS_TRUE )
  {
    if( old_feof( f ) ) break;
    if( old_fread( &c, 1, 1, f ) != 1 ) break;
    readed = FS_TRUE;
    if( c == '\n' ) break;
    buf[i] = c; i++;
    if( i == ( len - 1 ) ) break;
  }
  if( !readed ) return NULL;
  buf[i] = 0;

  return buf;
}
*/
// ---------------------------------------------------------------------------
