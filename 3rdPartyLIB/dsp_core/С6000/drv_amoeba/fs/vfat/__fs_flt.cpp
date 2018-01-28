#include <__fs.h>
#include <rts.h>
// ---------------------------------------------------------------------------
Flt::Flt()
{
  /* Nothing */
}
// ---------------------------------------------------------------------------
Flt::~Flt()
{
  /* Nothing */
}
// ---------------------------------------------------------------------------
FS_UINT16 Flt::switchObjectTo( File* f, FS_CHAR* objName )
{
  return FS_ER_FUNC_NOT_ASSIGNED;
}
// ---------------------------------------------------------------------------
FS_UINT16 Flt::init( File* f )
{
  return FS_ER_FUNC_NOT_ASSIGNED;
}
// ---------------------------------------------------------------------------
FS_UINT16 Flt::open( File* f, FS_UINT16 mode )
{
  return FS_ER_FUNC_NOT_ASSIGNED;
}
// ---------------------------------------------------------------------------
FS_UINT16 Flt::close( File* f )
{
  return FS_ER_FUNC_NOT_ASSIGNED;
}
// ---------------------------------------------------------------------------
FS_UINT16 Flt::read( File* f, void* dataPtr, FS_UINT32 length )
{
  return FS_ER_FUNC_NOT_ASSIGNED;
}
// ---------------------------------------------------------------------------
FS_UINT16 Flt::write( File* f, void* dataPtr, FS_UINT32 length )
{
  return FS_ER_FUNC_NOT_ASSIGNED;
}
// ---------------------------------------------------------------------------
FS_UINT16 Flt::seek( File* f, FS_INT32 offset, FS_UINT32 startPoint )
{
  return FS_ER_FUNC_NOT_ASSIGNED;
}
// ---------------------------------------------------------------------------
FS_UINT16 Flt::tell( File* f, FS_UINT32* offset )
{
  return FS_ER_FUNC_NOT_ASSIGNED;
}
// ---------------------------------------------------------------------------
FS_UINT16 Flt::eof( File* f, FS_BOOL* state )
{
  return FS_ER_FUNC_NOT_ASSIGNED;
}
// ---------------------------------------------------------------------------
FS_UINT16 Flt::findFirst( File* f, FS_CHAR* mask, FS_UINT32 attr, FileInfo* info )
{
  return FS_ER_FUNC_NOT_ASSIGNED;
}
// ---------------------------------------------------------------------------
FS_UINT16 Flt::findNext( File* f, FileInfo* info )
{
  return FS_ER_FUNC_NOT_ASSIGNED;
}
// ---------------------------------------------------------------------------
FS_UINT16 Flt::findClose( File* f )
{
  return FS_ER_FUNC_NOT_ASSIGNED;
}
// ---------------------------------------------------------------------------
FS_UINT16 Flt::mkdir( File* f, FS_CHAR* dirName )
{
  return FS_ER_FUNC_NOT_ASSIGNED;
}
// ---------------------------------------------------------------------------
FS_UINT16 Flt::rmdir( File* f, FS_CHAR* dirName )
{
  return FS_ER_FUNC_NOT_ASSIGNED;
}
// ---------------------------------------------------------------------------
FS_UINT16 Flt::size( File* f, FS_UINT32* flowSize )
{
  return FS_ER_FUNC_NOT_ASSIGNED;
}
// ---------------------------------------------------------------------------
FS_UINT16 Flt::getCreateDate( File* f, FS_UINT32* data )
{
  return FS_ER_FUNC_NOT_ASSIGNED;
}
// ---------------------------------------------------------------------------
FS_UINT16 Flt::getLastModifyDate( File* f, FS_UINT32* data )
{
  return FS_ER_FUNC_NOT_ASSIGNED;
}
// ---------------------------------------------------------------------------
FS_UINT16 Flt::createObject( File* f, FS_CHAR* objName, FS_UINT32 attr )
{
  return FS_ER_FUNC_NOT_ASSIGNED;
}
// ---------------------------------------------------------------------------
FS_UINT16 Flt::mkfile( File* f, FS_CHAR* fileName )
{
  return FS_ER_FUNC_NOT_ASSIGNED;
}
// ---------------------------------------------------------------------------
FS_UINT16 Flt::rmfile( File* f, FS_CHAR* fileName )
{
  return FS_ER_FUNC_NOT_ASSIGNED;
}
// ---------------------------------------------------------------------------
FS_UINT16 Flt::removeObject( File* f, FS_CHAR* objName )
{
  return FS_ER_FUNC_NOT_ASSIGNED;
}
// ---------------------------------------------------------------------------
FS_UINT16 Flt::removeObjectRecursive( File* f, FS_CHAR* objName )
{
  return FS_ER_FUNC_NOT_ASSIGNED;
}
// ---------------------------------------------------------------------------
FS_UINT16 Flt::trim( File* f, FS_UINT32 position )
{
  return FS_ER_FUNC_NOT_ASSIGNED;
}
// ---------------------------------------------------------------------------
FS_UINT32 Flt::getRWCounter( File* f )
{
  return 0;
}
// ---------------------------------------------------------------------------
FS_UINT16 Flt::getFreeSpaceInBytes( FS_UINT32* freeBytes )
{
  (*freeBytes) = 0xffffffff;
  return FS_ER_FUNC_NOT_ASSIGNED;
}
// ---------------------------------------------------------------------------
FS_UINT16 Flt::getSize( FS_UINT32* size )
{
  (*size) = 0xffffffff;
  return FS_ER_FUNC_NOT_ASSIGNED;
}
// ---------------------------------------------------------------------------
FS_UINT16 Flt::writeLable( File* f, FS_CHAR* lable )
{
  return FS_ER_FUNC_NOT_ASSIGNED;
}
// ---------------------------------------------------------------------------
FS_UINT16 Flt::rename( File* f, FS_CHAR* newPath )
{
  return FS_ER_FUNC_NOT_ASSIGNED;
}
// ---------------------------------------------------------------------------
FS_UINT16 Flt::cflush( File* f )
{
  return FS_OK;
}
// ---------------------------------------------------------------------------
FS_UINT16 Flt::fsType()
{
  return FS_NO;
}
// ---------------------------------------------------------------------------
FS_UINT16 Flt::stUsbDev(FS_ST_USBDEV* d)
{
  return FS_NO;
}
// ---------------------------------------------------------------------------

