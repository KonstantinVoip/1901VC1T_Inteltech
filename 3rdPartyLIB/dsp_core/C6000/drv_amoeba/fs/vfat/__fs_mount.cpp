#include <__fs.h>
#include <rts.h>
// ---------------------------------------------------------------------------
FS_UINT16 mount( FS_CHAR logicDiskLetter )
{
  FS_UINT16 res,stl;
  FS_UINT16 ldIndex = fsUtils::upCase( logicDiskLetter ) - 'A';
  LogicDiskInfo *ldInfo;
  RootFSRec* mPoint;
  Flt* newFsDrv;
  FS_CHAR* mBPath;
  FS_CHAR mPath[3];

  mPath[0] = '/'; mPath[1] = 'a' + ldIndex; mPath[2] = 0;

  if( ( res = logicDisk.getInfo( ldIndex, &ldInfo ) ) != 0 ) return res;

  switch( ldInfo->fsType )
  {
    case FS_FAT12: 
    case FS_FAT16: 
    case FS_FAT32: newFsDrv = new Fat(); break;
  }

  if( newFsDrv == NULL ) return FS_ER_CANT_ALLOCATE_MEMORY;

  if( ( res = rootFs.mount( mPath, newFsDrv ) ) != 0 )
  {
    delete newFsDrv;
    return res;
  }

  stl = strlen( mPath );
  mBPath = (FS_CHAR*)fs_alloc( stl + 4 ); // new FS_CHAR[stl+4];
  if( mBPath == NULL )
  {
    rootFs.umount( mPath );
    return FS_ER_CANT_ALLOCATE_MEMORY;
  }

  memcpy( mBPath, mPath, stl );
  mBPath[stl] = '/';
  mBPath[stl+1] = '.';
  mBPath[stl+2] = '.';
  mBPath[stl+3] = 0;

  if( ( res = rootFs.mount( mBPath, &rootFs ) ) != 0 )
  {
    fs_free( mBPath );
    rootFs.umount(mPath);
    return res;
  }
  fs_free( mBPath );

  rootFs.getRecPointerByName( mPath, &mPoint );

  switch( ldInfo->fsType )
  {
    case FS_FAT12:
    {
      Fat* fsd = (Fat*)newFsDrv;
      fsd->setup( ldInfo, (RootFSMountPoint*)mPoint );
    }
    break;
    case FS_FAT16:
    {
      Fat* fsd = (Fat*)newFsDrv;
      fsd->setup( ldInfo, (RootFSMountPoint*)mPoint );
    }
    break;
    case FS_FAT32:
    {
      Fat* fsd = (Fat*)newFsDrv;
      fsd->setup( ldInfo, (RootFSMountPoint*)mPoint );
    }
    break;
  }

  return FS_OK;
}
// ---------------------------------------------------------------------------
FS_UINT16 umount(FS_CHAR logicDiskLetter)
{
  FS_CHAR mPath[6];
  FS_UINT16 ldIndex = fsUtils::upCase( logicDiskLetter ) - 'A';
  mPath[0] = mPath[2] = '/'; mPath[1] = 'a' + ldIndex;
  mPath[3] = mPath[4] = '.'; mPath[5] = 0;
  rootFs.delRec( mPath );
  mPath[2] = 0;
  fsMonitor::umount( mPath );
  rootFs.umount( mPath );
  return FS_OK;
}
// ---------------------------------------------------------------------------
void mount_all()
{
  FS_REINIT_LOCK();
  dev.reInitLogicDisks();
  FS_REINIT_UNLOCK();
  for( FS_INT32 i = 0; i < DEV_MAX_LOGIC_DISKS; i++ ) mount( 'a' + i );
}
// ---------------------------------------------------------------------------
void umount_all()
{
  for( FS_INT32 i = 0; i < DEV_MAX_LOGIC_DISKS; i++ ) umount( 'a' + i );
}
// ---------------------------------------------------------------------------

