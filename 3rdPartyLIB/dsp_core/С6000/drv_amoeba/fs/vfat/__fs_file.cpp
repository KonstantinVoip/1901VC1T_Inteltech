#include <__fs.h>
#include <rts.h>
// ---------------------------------------------------------------------------

FS_CHAR* const_fs_SelfPointer = { "." };
FS_CHAR* const_fs_BackPointer = { ".." };

// ---------------------------------------------------------------------------
FileData::FileData()
{
  curPath = NULL;
}
// ---------------------------------------------------------------------------
FileData::~FileData()
{
  fs_free( curPath );
}
// ---------------------------------------------------------------------------
FS_BOOL FileData::isRoot()
{
  return ( strlen( curPath ) == 1 ) ? FS_TRUE : FS_FALSE;
}
// ---------------------------------------------------------------------------
FS_BOOL FileData::incPath( FS_CHAR* objName )
{
  FS_CHAR* newPath;
  FS_UINT16 stl1, stl2;
  if( ( curPath == NULL ) || ( objName == NULL ) )
  {
    if( curPath != NULL ) fs_free( curPath );
    curPath = (FS_CHAR*)fs_alloc( 2 ); // new FS_CHAR[2];
    if( curPath == NULL ) return FS_FALSE;
    curPath[0] = '/';
    curPath[1] = 0;
    return FS_TRUE;
  }
  stl2 = strlen( objName );
  if( stl2 == 0 ) return FS_FALSE;
  if( ( curPath[0] == '/' ) && ( curPath[1] == 0 ) ) stl1 = 0; else stl1 = strlen( curPath );
  newPath = (FS_CHAR*)fs_alloc( stl1 + stl2 + 2 ); // new FS_CHAR[stl1+stl2+2];
  if( newPath == NULL ) return FS_FALSE;
  memcpy( newPath, curPath, stl1 );
  newPath[stl1] = '/';
  strcpy( newPath + stl1 + 1, objName );
  fs_free( curPath );
  curPath = newPath;
  return FS_TRUE;
}
// ---------------------------------------------------------------------------
FS_BOOL FileData::decPath()
{
  FS_CHAR* newPath;
  FS_UINT16 stl;
  FS_INT16 i;
  if( curPath == NULL ) return FS_TRUE;
  if( ( curPath[0] == '/' ) && ( curPath[1] == 0 ) ) return FS_TRUE;
  for( i = strlen( curPath ) - 1;i >= 0; i-- ) if( curPath[i] == '/' ) { stl = i; break; }
  if( stl == 0 ) stl = 1;
  newPath = (FS_CHAR*)fs_alloc( stl + 1 ); // new FS_CHAR[stl+1];
  if( newPath == NULL ) return FS_FALSE;
  memcpy( newPath, curPath, stl );
  newPath[stl] = 0;
  fs_free( curPath );
  curPath = newPath;
  return FS_TRUE;
}
// ---------------------------------------------------------------------------
FS_BOOL FileData::copyPath( FileData* oldData )
{
  FS_CHAR* newPath;
  FS_UINT16 stl;
  if( oldData == NULL ) return FS_FALSE;
  if( oldData->curPath == NULL ) return FS_FALSE;
  stl = strlen( oldData->curPath );
  newPath = (FS_CHAR*)fs_alloc( stl + 1 ); // new FS_CHAR[stl+1];
  if( newPath == NULL ) return FS_FALSE;
  fs_free( curPath );
  strcpy( newPath, oldData->curPath );
  curPath = newPath;
  return FS_TRUE;
}
// ---------------------------------------------------------------------------
FS_BOOL FileData::setPath( FS_CHAR* newPath )
{
  FS_BOOL fl = FS_FALSE;
  if( newPath == NULL ) return FS_FALSE;
  FS_UINT16 stl = strlen( newPath ) + 1;
  if( newPath[stl-2] == '/' ) { fl = FS_TRUE; stl--; }
  FS_CHAR* np = (FS_CHAR*)fs_alloc( stl ); // new FS_CHAR[stl];
  if( np == NULL ) return FS_FALSE;
  memcpy( np, newPath, stl );
  if( fl ) np[stl-1] = 0;
  fs_free( curPath );
  curPath = np;
  return FS_TRUE;
}
// ---------------------------------------------------------------------------
FS_CHAR* FileData::getPath()
{
  return curPath;
}
// ---------------------------------------------------------------------------
FileInfo::FileInfo()
{
  name = NULL;
  size = 0;
  createTime = 0;
  attr = 0;
}
// ---------------------------------------------------------------------------
FileInfo::~FileInfo()
{
  clear();
}
// ---------------------------------------------------------------------------
void FileInfo::clear()
{
  fs_free( name );
  name = NULL;
  size = 0;
  createTime = 0;
  attr = 0;
}
// ---------------------------------------------------------------------------
File::File()
{
  fsMonitor::addOpenFile( this );
  flt = &rootFs;
  data = NULL;
  flt->init( this );
}
// ---------------------------------------------------------------------------
File::~File()
{
  fsMonitor::delOpenFile( this );
  if( data != NULL ) delete data;
}
// ---------------------------------------------------------------------------
FS_UINT16 File::switchObjectTo( FS_CHAR* objName )
{
  return flt->switchObjectTo( this, objName );
}
// ---------------------------------------------------------------------------
FS_UINT16 File::open( FS_UINT16 mode )
{
  return flt->open( this, mode );
}
// ---------------------------------------------------------------------------
FS_UINT16 File::close()
{
  return flt->close( this );
}
// ---------------------------------------------------------------------------
FS_UINT16 File::read( void* data, FS_UINT32 length )
{
  return flt->read( this, data, length );
}
// ---------------------------------------------------------------------------
FS_UINT16 File::write( void* data, FS_UINT32 length )
{
  return flt->write( this, data, length );
}
// ---------------------------------------------------------------------------
FS_UINT16 File::seek( FS_INT32 offset, FS_UINT32 startPoint )
{
  return flt->seek( this, offset, startPoint );
}
// ---------------------------------------------------------------------------
FS_UINT16 File::tell( FS_UINT32* offset )
{
  return flt->tell( this, offset );
}
// ---------------------------------------------------------------------------
FS_UINT16 File::eof( FS_BOOL* state )
{
  return flt->eof( this, state );
}
// ---------------------------------------------------------------------------
FS_UINT16 File::findFirst( FS_CHAR* mask, FS_UINT32 attr, FileInfo* info )
{
  return flt->findFirst( this, mask, attr, info );
}
// ---------------------------------------------------------------------------
FS_UINT16 File::findNext( FileInfo* info )
{
  return flt->findNext( this, info );
}
// ---------------------------------------------------------------------------
FS_UINT16 File::findClose()
{
  return flt->findClose( this );
}
// ---------------------------------------------------------------------------
FS_UINT16 File::mkdir( FS_CHAR* dirName )
{
  return flt->mkdir( this, dirName );
}
// ---------------------------------------------------------------------------
FS_UINT16 File::rmdir( FS_CHAR* dirName )
{
  return flt->rmdir( this, dirName );
}
// ---------------------------------------------------------------------------
FS_UINT16 File::size( FS_UINT32* flowSize )
{
  return flt->size( this, flowSize );
}
// ---------------------------------------------------------------------------
FS_UINT16 File::getCreateDate( FS_UINT32* data )
{
  return flt->getCreateDate( this, data );
}
// ---------------------------------------------------------------------------
FS_UINT16 File::getLastModifyDate( FS_UINT32* data )
{
  return flt->getLastModifyDate( this, data );
}
// ---------------------------------------------------------------------------
FS_UINT16 File::createObject( FS_CHAR* objName, FS_UINT32 attr )
{
  return flt->createObject( this, objName, attr );
}
// ---------------------------------------------------------------------------
FS_UINT16 File::mkfile(FS_CHAR* fileName)
{
  return flt->mkfile( this, fileName );
}
// ---------------------------------------------------------------------------
FS_UINT16 File::rmfile( FS_CHAR* fileName )
{
  return flt->rmfile( this, fileName );
}
// ---------------------------------------------------------------------------
FS_UINT16 File::removeObject( FS_CHAR* objName )
{
  return flt->removeObject( this, objName );
}
// ---------------------------------------------------------------------------
FS_UINT16 File::trim( FS_UINT32 position )
{
  return flt->trim( this, position );
}
// ---------------------------------------------------------------------------
FS_UINT32 File::getRWCounter()
{
  return flt->getRWCounter( this );
}
// ---------------------------------------------------------------------------
FS_UINT16 File::getFreeSpaceInBytes( FS_UINT32* freeBytes )
{
  return flt->getFreeSpaceInBytes( freeBytes );
}
// ---------------------------------------------------------------------------
FS_UINT16 File::getSize( FS_UINT32* size )
{
  return flt->getSize( size );
}
// ---------------------------------------------------------------------------
FS_UINT16 File::writeLable( FS_CHAR* lable )
{
  return flt->writeLable( this, lable );
}
// ---------------------------------------------------------------------------
FS_UINT16 File::rename( FS_CHAR* newPath )
{
  return flt->rename( this, newPath );
}
// ---------------------------------------------------------------------------
FS_UINT16 File::cflush()
{
  return flt->cflush( this );
}
// ---------------------------------------------------------------------------
FS_UINT16 File::fsType()
{
  return flt->fsType();
}
// ---------------------------------------------------------------------------
FS_UINT16 File::stUsbDev(FS_ST_USBDEV* d)
{
  return flt->stUsbDev(d);
}
// ---------------------------------------------------------------------------
