#include <__fs.h>
#include <rts.h>
// ---------------------------------------------------------------------------

RootFS rootFs;

// ---------------------------------------------------------------------------
RootFSFileData::RootFSFileData() : FileData()
{
  findIndex = 0;
  findMask = NULL;
  findAttr = 0;
  numOfIndexes = 0;
}
// ---------------------------------------------------------------------------
RootFSFileData::~RootFSFileData()
{
  fs_free( findMask );
}
// ---------------------------------------------------------------------------
RootFSRec::RootFSRec()
{
  type = RFS_TYPE_NO;
  createTime = time( NULL );
  name = NULL;
  attr = 0777;
}
// ---------------------------------------------------------------------------
RootFSRec::~RootFSRec()
{
  fs_free( name );
}
// ---------------------------------------------------------------------------
RootFSMountPoint::RootFSMountPoint() : RootFSRec()
{
  drv = NULL;
}
// ---------------------------------------------------------------------------
RootFSMountPoint::~RootFSMountPoint()
{
  if( type == RFS_TYPE_UNMOUNTED ) if( drv != NULL ) delete drv;
}
// ---------------------------------------------------------------------------
RootFS::RootFS() : Flt()
{
  recs = NULL;
  numOfRecs = 0;
}
// ---------------------------------------------------------------------------
RootFS::~RootFS()
{
  FS_UINT16 i;
  if( recs != NULL )
  {
    for( i = 0; i < numOfRecs; i++ ) delete recs[i];
    fs_free( recs );
  }
}
// ---------------------------------------------------------------------------
FS_UINT16 RootFS::switchObjectTo( File* f, FS_CHAR* objName )
{
  FS_UINT16 stl1;
  FS_UINT16 stl2;
  FS_CHAR* fp;
  RootFSMountPoint* MP;
  FileData* fdata = f->data;
  FS_CHAR* fdCurPath;

  if( objName == NULL ) return FS_ER_NULL_POINTER;
  if( f == NULL ) return FS_ER_NULL_POINTER;
  if( f->data == NULL ) return FS_ER_NULL_POINTER;

  if( strcmp( objName, const_fs_SelfPointer ) == 0 ) return FS_OK;

  fdCurPath = fdata->getPath();
  if( ( fdCurPath[0] == '/' ) && ( fdCurPath[1] == 0 ) ) stl1 = 0; else stl1 = strlen( fdCurPath );
  stl2 = strlen( objName );
  fp = (FS_CHAR*)fs_alloc( stl1 + stl2 + 2 );// new FS_CHAR[stl1+stl2+2];
  if( fp == NULL ) return FS_ER_CANT_ALLOCATE_MEMORY;
  memcpy( fp, fdCurPath, stl1 );
  fp[stl1] = '/';
  strcpy( fp + stl1 + 1, objName );
  stl1 = getRecIndexByName( fp );
  fs_free( fp );
  fp = NULL;
  if( stl1 == 0xffff ) return FS_ER_RFS_REC_NOT_EXISTS;

  if( recs[stl1]->type == RFS_TYPE_MOUNT_POINT )
  {
    MP = (RootFSMountPoint*)recs[stl1];
    f->flt = MP->drv;
    stl1 = f->flt->init( f );
    if( stl1 != FS_OK )
    {
      f->flt = this;
      return stl1;
    }
  }
  if( recs[stl1]->type == RFS_TYPE_BACK_POINT )
  {
    RootFSFileData* newData = new RootFSFileData;
    if( newData == NULL ) return FS_ER_CRITICAL;
    if( !newData->copyPath( f->data ) )
    {
      delete newData;
      return FS_ER_CRITICAL;
    }
    if( f->data != NULL ) delete f->data;
    f->data = newData;
    f->flt = this;
  }
  if( strcmp( objName, const_fs_BackPointer ) == 0 ) f->data->decPath(); else f->data->incPath( objName );

  return FS_OK;
}
// ---------------------------------------------------------------------------
FS_UINT16 RootFS::init( File* f )
{
  RootFSFileData* newData;
  newData = new RootFSFileData;
  if( newData == NULL ) return FS_ER_CANT_ALLOCATE_MEMORY;
  newData->incPath( NULL );
  f->data = newData;
  return FS_OK;
}
// ---------------------------------------------------------------------------
FS_UINT16 RootFS::findFirst( File* f, FS_CHAR* mask, FS_UINT32 attr, FileInfo* info )
{
  RootFSFileData* fdata;
  FS_UINT16 stl;

  if( f == NULL ) return FS_ER_NULL_POINTER;
  if( info == NULL ) return FS_ER_NULL_POINTER;
  if( f->data == NULL ) return FS_ER_NULL_POINTER;

  fdata = (RootFSFileData*)f->data;

  fs_free( fdata->findMask );
  stl = strlen( mask ) + 1;
  fdata->findMask = (FS_CHAR*)fs_alloc( stl ); //new FS_CHAR[stl];
  if( fdata->findMask == NULL ) return FS_ER_CANT_ALLOCATE_MEMORY;

  memcpy( fdata->findMask, mask, stl );
  fdata->numOfIndexes = numOfRecs;
  fdata->findIndex = 0;
  fdata->findAttr = attr;

  return findNext( f, info );
}
// ---------------------------------------------------------------------------
FS_UINT16 RootFS::findNext( File* f, FileInfo* info )
{
  FS_UINT16 i,stl,stl1;
  RootFSFileData* fdata;
  FS_CHAR* fdCurPath;

  if( f == NULL ) return FS_ER_NULL_POINTER;
  if( info == NULL ) return FS_ER_NULL_POINTER;
  if( f->data == NULL ) return FS_ER_NULL_POINTER;

  info->clear();
  fdata = (RootFSFileData*)f->data;
  fdCurPath = fdata->getPath();
  if( fdata->numOfIndexes != numOfRecs ) return FS_WR_RFS_WAS_CHANGED;

  stl1 = strlen( fdCurPath );
  for( i = fdata->findIndex; i < numOfRecs; i++ )
  {
    if( fsUtils::cmpL( fdCurPath, recs[i]->name, stl1 ) )
    {
      if( ( fdCurPath[0] == '/' ) && ( fdCurPath[1] == 0 ) ) stl1--;
      if( fsUtils::findChar( recs[i]->name + stl1 + 1, '/' ) == 0xffff )
      {
        if( ( fsUtils::maskCmpEndChar( fdata->findMask, recs[i]->name + stl1 + 1, '/' ) ) &&
            ( ( recs[i]->attr & fdata->findAttr ) == fdata->findAttr ) )
        {
          stl = strlen( recs[i]->name + stl1 + 1 );
          info->name = (FS_CHAR*)fs_alloc( stl + 1 ); //new FS_CHAR[stl+1];
          if( info->name == NULL ) return FS_ER_CANT_ALLOCATE_MEMORY;
          strcpy( info->name, recs[i]->name + stl1 + 1 );
          info->attr = recs[i]->attr;
          info->createTime = recs[i]->createTime;
          info->size = 0;
          fdata->findIndex = i+1;
          return FS_OK;
        }
      }
      if( ( fdCurPath[0] == '/' ) && ( fdCurPath[1] == 0 ) ) stl1++;
    }
  }

  return FS_ER_OBJECT_NOT_FOUND;
}
// ---------------------------------------------------------------------------
FS_UINT16 RootFS::findClose( File* f )
{
  RootFSFileData* fdata;
  if( f == NULL ) return FS_ER_NULL_POINTER;
  if( f->data == NULL ) return FS_ER_NULL_POINTER;
  fdata = (RootFSFileData*)f->data;
  fdata->findIndex = 0;
  fdata->numOfIndexes = 0;
  fdata->findAttr = 0;
  fs_free( fdata->findMask );
  fdata->findMask = NULL;
  return FS_OK;
}
// ---------------------------------------------------------------------------
FS_UINT16 RootFS::mkdir( File* f, FS_CHAR* dirName )
{
  RootFSRec* newRec;
  FS_UINT16 stl1, stl2;
  RootFSFileData* fdata;
  FS_CHAR* fdCurPath;

  if( dirName == NULL ) return FS_ER_NULL_POINTER;
  if( f == NULL ) return FS_ER_NULL_POINTER;
  if( f->data == NULL ) return FS_ER_NULL_POINTER;
  fdata = (RootFSFileData*)f->data;
  fdCurPath = fdata->getPath();
  newRec = new RootFSRec;
  if( newRec == NULL ) return FS_ER_CANT_ALLOCATE_MEMORY;
  stl1 = strlen( dirName );
  if( ( fdCurPath[0] == '/' ) && ( fdCurPath[1] == 0 ) ) stl2 = 0; else stl2 = strlen( fdCurPath );
  newRec->name = (FS_CHAR*)fs_alloc( stl1 + stl2 + 2 ); //new FS_CHAR[stl1+stl2+2];
  if( newRec->name == NULL )
  {
    delete newRec;
    return FS_ER_CANT_ALLOCATE_MEMORY;
  }
  newRec->type = RFS_TYPE_DIR;
  memcpy( newRec->name, fdCurPath, stl2 );
  newRec->name[stl2] = '/';
  strcpy( newRec->name + stl2 + 1, dirName );
  if( ( stl1 = addRec( newRec ) ) != FS_OK )
  {
    delete newRec;
    return stl1;
  }
  return FS_OK;
}
// ---------------------------------------------------------------------------
FS_UINT16 RootFS::rmdir( File* f, FS_CHAR* dirName )
{
  FS_UINT16 stl1;
  FS_UINT16 stl2;
  FS_CHAR* fp;
  FS_CHAR* fdCurPath;

  if( dirName == NULL ) return FS_ER_NULL_POINTER;
  if( f == NULL ) return FS_ER_NULL_POINTER;
  if( f->data == NULL ) return FS_ER_NULL_POINTER;

  fdCurPath = f->data->getPath();

  stl1 = strlen( fdCurPath );
  stl2 = strlen( dirName );
  fp = (FS_CHAR*)fs_alloc( stl1 + stl2 + 2 ); //new FS_CHAR[stl1+stl2+2];
  if( fp == NULL ) return FS_ER_CANT_ALLOCATE_MEMORY;

  memcpy( fp, fdCurPath, stl1 );
  fp[stl1] = '/';
  strcpy( fp + stl1 + 1, dirName );

  stl1 = delRec( fp );
  fs_free( fp );

  return stl1;
}
// ---------------------------------------------------------------------------
FS_UINT16 RootFS::mount( FS_CHAR* path, Flt* fsDrv )
{
  RootFSMountPoint* mpRec;
  FS_UINT16 stl;

  if( path == NULL ) return FS_ER_NULL_POINTER;
  if( fsDrv == NULL ) return FS_ER_NULL_POINTER;

  mpRec = new RootFSMountPoint;
  if( mpRec == NULL ) return FS_ER_CANT_ALLOCATE_MEMORY;
  stl = strlen( path );
  mpRec->name = (FS_CHAR*)fs_alloc( stl + 1 ); //new FS_CHAR[stl+1];
  if( mpRec->name == NULL )
  {
    mpRec->drv = NULL;
    delete mpRec;
    return FS_ER_CANT_ALLOCATE_MEMORY;
  }
  strcpy( mpRec->name, path );
  mpRec->type = RFS_TYPE_MOUNT_POINT;
  mpRec->drv = fsDrv;
  mpRec->attr = FAT_ATTR_DIR;
  if( ( path[stl-1] == '.' ) && ( path[stl-2] == '.' ) ) mpRec->type = RFS_TYPE_BACK_POINT;
  if( ( stl = addRec( mpRec ) ) != FS_OK )
  {
    mpRec->drv = NULL;
    delete mpRec;
    return stl;
  }

  return FS_OK;
}
// ---------------------------------------------------------------------------
FS_UINT16 RootFS::umount( FS_CHAR* path )
{
  FS_UINT16 idx;
  if( path == NULL ) return FS_ER_NULL_POINTER;
  if( ( idx = getRecIndexByName( path ) ) == 0xffff ) return FS_ER_BAD_MOUNT_POINT;
  if( recs[idx]->type != RFS_TYPE_MOUNT_POINT ) return FS_ER_ITS_NOT_MOUNT_POINT;
  recs[idx]->type = RFS_TYPE_UNMOUNTED;
  delRec( path );
  return FS_OK;
}
// ---------------------------------------------------------------------------
FS_UINT16 RootFS::getRecIndexByName( FS_CHAR* name )
{
  FS_UINT16 i;
  if( name == NULL ) return 0xffff;
  for( i = 0; i < numOfRecs; i++ ) if( strcmp( name, recs[i]->name ) == 0 ) break;
  if( i == numOfRecs ) i = 0xffff;
  return i;
}
// ---------------------------------------------------------------------------
FS_UINT16 RootFS::getRecPointerByName( FS_CHAR* name, RootFSRec** rec )
{
  FS_UINT16 idx;
  if( ( idx = getRecIndexByName( name ) ) == 0xffff )
  {
    (*rec) = NULL;
    return FS_ER_RFS_REC_NOT_EXISTS;
  }
  (*rec) = recs[idx];
  return FS_OK;
}
// ---------------------------------------------------------------------------
FS_UINT16 RootFS::addRec( RootFSRec* rec )
{
  RootFSRec** newRecs;
  FS_UINT16 i;

  if( rec == NULL ) return FS_ER;
  if( getRecIndexByName( rec->name ) != 0xffff ) return FS_ER_RFS_REC_EXISTS;

  newRecs = (RootFSRec**)fs_alloc( sizeof(RootFSRec*) * ( numOfRecs + 1 ) ); //new RootFSRec*[numOfRecs+1];
  if( newRecs == NULL ) return FS_ER;

  for( i = 0; i < numOfRecs; i++ ) newRecs[i] = recs[i];
  newRecs[numOfRecs] = rec;
  numOfRecs++;

  fs_free( recs );
  recs = newRecs;

  return FS_OK;
}
// ---------------------------------------------------------------------------
FS_UINT16 RootFS::delRec( FS_CHAR* path )
{
  FS_UINT16 i,j;
  RootFSRec** newRecs;

  if( path == NULL ) return FS_ER_NULL_POINTER;
  if( ( i = getRecIndexByName( path ) ) == 0xffff ) return FS_ER_RFS_REC_NOT_EXISTS;
  if( recs[i]->type == RFS_TYPE_MOUNT_POINT ) return FS_ER_CANT_DELETE_MOUNT_POINT;
  delete recs[i];
  for( j = i; j < numOfRecs - 1; j++ ) recs[j] = recs[j+1];
  numOfRecs--;
  newRecs = (RootFSRec**)fs_alloc( sizeof(RootFSRec*) * numOfRecs ); // new RootFSRec*[numOfRecs];
  if( newRecs != NULL )
  {
    for( j = 0; j < numOfRecs; j++ ) newRecs[j] = recs[j];
    fs_free( recs );
    recs = newRecs;
  }
  return FS_OK;
}
// ---------------------------------------------------------------------------
FS_UINT16 RootFS::getCreateDate( File* f, FS_UINT32* data )
{
  FS_UINT16 idx;
  if( ( idx = getRecIndexByName( f->data->getPath() ) ) == 0xffff ) return FS_ER_RFS_REC_NOT_EXISTS;
  *data = recs[idx]->createTime;
  return FS_OK;
}
// ---------------------------------------------------------------------------
FS_UINT16 RootFS::getLastModifyDate( File* f, FS_UINT32* data )
{
  FS_UINT16 idx;
  if( ( idx = getRecIndexByName( f->data->getPath() ) ) == 0xffff ) return FS_ER_RFS_REC_NOT_EXISTS;
  (*data) = recs[idx]->createTime;
  return FS_OK;
}
// ---------------------------------------------------------------------------
FS_UINT16 RootFS::fsType()
{
  return FS_ROOTFS;
}
// ---------------------------------------------------------------------------
