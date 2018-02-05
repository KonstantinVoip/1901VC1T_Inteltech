/**********************************************************************************************************************
*                                        (c) COPYRIGHT by ZAO RCZI FORT.                                             *
*        ..                                       All rights reserved.                                               *
***********************************************************************************************************************
* Module      : __fs_vfat.cpp
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



#include <__fs.h>
#include <rts.h>
// ---------------------------------------------------------------------------
FATFileRecord::FATFileRecord()
{
  shortName = NULL;
  name = NULL;
  clear();
}
// ---------------------------------------------------------------------------
FATFileRecord::~FATFileRecord()
{
  clear();
}
// ---------------------------------------------------------------------------
void FATFileRecord::clear()
{
  fs_free( shortName );
  fs_free( name );
  shortName = NULL;
  name = NULL;
  size = 0;
  startCluster = 0;
  attributes = 0;
  sSection = 0;
  eSection = 0;
  tcymd = 0;
  tchms = 0;
  tmymd = 0;
  tmhms = 0;
  dirSectionSector = 0;
}
// ---------------------------------------------------------------------------
FS_UINT16 InterfaceLFNRec::getChar( FS_UINT16 idx )
{
  if( idx < 5 ) return name1[idx];
  if( idx < 11 ) return name2[idx-5];
  if( idx < 13 ) return name2[idx-4];
  return 0x0000;
}
// ---------------------------------------------------------------------------
FATFileData::FATFileData() : FileData()
{
  attributes = 0;
  timeCreateYMD = 0;
  timeCreateHMS = 0;
  timeModifyYMD = 0;
  timeModifyHMS = 0;
  cash = NULL;
  cashSize = 0;
  cashCluster = 0xffffffff;
  cashModifyed = FS_FALSE;
  startSector = 0;
  startCluster = 0;
  currentSector = 0;
  currentCluster = 0;
  flowSize = 0;
  flowPosition = 0;
  clusterPosition = 0;
  dirStartSection = 0;
  dirEndSection = 0;
  dirSectionSector = 0;
  flowMode = 0;
  findMask = NULL;
  findAttr = 0;
  pDirInfo = NULL;
  rwCounter = 0;
  newClusterAllocated = FS_FALSE;
}
// ---------------------------------------------------------------------------
FATFileData::~FATFileData()
{
  fs_free( findMask );
  fs_free( pDirInfo );
  fs_free( cash );
}
// ---------------------------------------------------------------------------
FS_UINT16 FATFileData::prepareParentDirInfo()
{
  if( pDirInfo != NULL ) return FS_ER_PDIRINFO_STRUCT_CREATED;
  pDirInfo = (FATParentDirInfo*)fs_alloc( sizeof(FATParentDirInfo) );// new FATParentDirInfo;
  if( pDirInfo == NULL ) return FS_ER_CANT_ALLOCATE_MEMORY;
  pDirInfo->attributes = attributes;
  pDirInfo->timeCreateYMD = timeCreateYMD;
  pDirInfo->timeCreateHMS = timeCreateHMS;
  pDirInfo->timeModifyYMD = timeModifyYMD;
  pDirInfo->timeModifyHMS = timeModifyHMS;
  pDirInfo->startCluster = startCluster;
  pDirInfo->startSector = startSector;
  pDirInfo->flowSize = flowSize;
  pDirInfo->dirStartSection = dirStartSection;
  pDirInfo->dirEndSection = dirEndSection;
  pDirInfo->dirSectionSector = dirSectionSector;
  return FS_OK;
}
// ---------------------------------------------------------------------------
FS_UINT16 FATFileData::backToParentDir()
{
  if( pDirInfo == NULL ) return FS_ER_PDIRINFO_STRUCT_NOT_CREATED;
  attributes = pDirInfo->attributes;
  timeCreateYMD = pDirInfo->timeCreateYMD;
  timeCreateHMS = pDirInfo->timeCreateHMS;
  timeModifyYMD = pDirInfo->timeModifyYMD;
  timeModifyHMS = pDirInfo->timeModifyHMS;
  startCluster = pDirInfo->startCluster;
  startSector = pDirInfo->startSector;
  flowSize = pDirInfo->flowSize;
  dirStartSection  = pDirInfo->dirStartSection;
  dirEndSection = pDirInfo->dirEndSection;
  dirSectionSector = pDirInfo->dirSectionSector;
  return FS_OK;
}
// ---------------------------------------------------------------------------
void FATFileData::clearParentDirInfo()
{
  fs_free( pDirInfo );
  pDirInfo = NULL;
}
// ---------------------------------------------------------------------------
Fat::Fat() : Flt()
{
  ldInfo = NULL;
  myMountPoint = NULL;
  mayRead = 0;
  cflush( NULL );
}
// ---------------------------------------------------------------------------
Fat::~Fat()
{
  /* Nothing */
}
// ---------------------------------------------------------------------------
void Fat::setup( LogicDiskInfo* iLdInfo, RootFSMountPoint* iMyMountPoint )
{
  ldInfo = iLdInfo;
  myMountPoint = iMyMountPoint;
  mayRead = ldInfo->sectorsPerCluster;
}
// ---------------------------------------------------------------------------
FS_UINT16 Fat::backForOneObject( File* f, FATFileRecord& frec )
{
  FATFileData* fdata = (FATFileData*)f->data;
  FS_UINT16 res;
  FS_BOOL founded = FS_FALSE;

  if( ( res = open( f, FL_READ ) ) != NULL ) return res;
  while( FS_TRUE )
  {
    if( ( res = readFileRecord( f, &frec ) != 0 ) ) break;
    if( fsUtils::upCaseCmp( frec.name, const_fs_BackPointer ) ) { founded = FS_TRUE; break; }
  }
  if( ( res != FS_WR_NOT_ENOUGHT_RECORDS ) && ( res != 0 ) )
  {
    close(f);
    return res;
  }
  if( ( res = close( f ) ) != 0 ) return res;
  if( !founded )
  {
    return FS_WR_NOT_ENOUGHT_RECORDS;
  }
  else
  {
    if( !f->data->decPath() ) return FS_ER_CANT_ALLOCATE_MEMORY;
    fdata->attributes = frec.attributes;
    fdata->timeCreateYMD = frec.tcymd;
    fdata->timeCreateHMS = frec.tchms;
    fdata->timeModifyYMD = frec.tmymd;
    fdata->timeModifyHMS = frec.tmhms;
    fdata->startCluster = frec.startCluster;
    fdata->startSector = ldInfo->firstSectorOfCluster( fdata->startCluster );
    fdata->currentSector = 0;
    fdata->currentCluster = 0;
    fdata->flowSize = frec.size;
    fdata->flowPosition = 0;
    fdata->clusterPosition = 0;
    fdata->dirStartSection = frec.sSection;
    fdata->dirEndSection = frec.eSection;
    fdata->dirSectionSector = frec.dirSectionSector;
    if( fsUtils::upCaseCmp( fdata->getPath(), myMountPoint->name ) )
    {
      if( ( ldInfo->fsType == FS_FAT12 ) || ( ldInfo->fsType == FS_FAT16 ) )
      {
        fdata->startSector = ldInfo->rootDirStart;
      }
    }
  }
  return FS_OK;
}
// ---------------------------------------------------------------------------
FS_UINT16 Fat::switchObjectTo( File* f, FS_CHAR* objName )
{
  FATFileData* fdata;
  FATFileRecord frec;
  FS_UINT16 res,stl;
  FS_INT16 i;
  FS_BOOL founded;
  FS_CHAR* tmp;
  FS_CHAR* curPath;

  if( f == NULL ) return FS_ER_NULL_POINTER;
  if( f->data == NULL ) return FS_ER_NULL_POINTER;

  fdata = (FATFileData*)f->data;
  if( ( fdata->flowMode & 3 ) != 0 ) return FS_ER_FLOW_OPENED;

  if( strcmp( objName, const_fs_SelfPointer ) == 0 ) return FS_OK;

  res = rootFs.switchObjectTo( f, objName );
  if( ( res == FS_OK ) || ( res == FS_ER_CRITICAL ) ) return res;

  if( strcmp( objName, const_fs_BackPointer ) == 0 )
  {
    if( ( fdata->attributes & FAT_ATTR_DIR ) == 0 )
    {
      if( ( res = fdata->backToParentDir() ) != 0 ) return res;
      if( !fdata->decPath() ) return FS_ER_CANT_ALLOCATE_MEMORY;
      fdata->clearParentDirInfo();
    }
    else
    {
      if( ( res = backForOneObject( f, frec ) ) != 0 ) return res;
      if( fsUtils::upCaseCmp( myMountPoint->name, fdata->getPath() ) )
      {
        fdata->flowMode |= FL_ROOT_DIR;
        fdata->dirStartSection = 0;
        fdata->dirEndSection = 0;
        fdata->dirSectionSector = 0;
      }
      else
      {
        curPath = fdata->getPath();
        stl = strlen( curPath );
        for( i = stl - 1; i >= 0; i-- ) if( curPath[i] == '/' ) break;
        tmp = (FS_CHAR*)fs_alloc( stl - i ); //new FS_CHAR[stl-i];
        if( tmp == NULL ) return FS_ER_CANT_ALLOCATE_MEMORY;
        memcpy( tmp, curPath + i + 1, stl - i );
        if( ( res = backForOneObject( f, frec ) ) != 0 )
        {
          fs_free( tmp );
          return res;
        }
        if( ( res = open( f, FL_READ ) ) != 0 )
        {
          fs_free( tmp );
          return res;
        }
        founded = FS_FALSE;
        while( FS_TRUE )
        {
          if( ( res = readFileRecord( f, &frec ) != 0 ) ) break;
          if( fsUtils::upCaseCmp( frec.name, tmp ) ) { founded = FS_TRUE; break; }
        }
        fs_free( tmp );
        if( ( res != FS_WR_NOT_ENOUGHT_RECORDS ) && ( res != 0 ) )
        {
          close( f );
          return res;
        }
        if( ( res = close( f ) ) != 0 ) return res;
        if( !founded )
        {
          return FS_WR_NOT_ENOUGHT_RECORDS;
        }
        else
        {
          if( ( frec.attributes & FAT_ATTR_DIR ) == 0 )
          {
            if( ( res = fdata->prepareParentDirInfo() ) != 0 ) return res;
          }
          if( !f->data->incPath( frec.name ) )
          {
            fdata->clearParentDirInfo();
            return FS_ER_CANT_ALLOCATE_MEMORY;
          }
          fdata->attributes = frec.attributes;
          fdata->timeCreateYMD = frec.tcymd;
          fdata->timeCreateHMS = frec.tchms;
          fdata->timeModifyYMD = frec.tmymd;
          fdata->timeModifyHMS = frec.tmhms;
          fdata->startCluster = frec.startCluster;
          fdata->startSector = ldInfo->firstSectorOfCluster( frec.startCluster );
          fdata->currentSector = 0;
          fdata->currentCluster = 0;
          fdata->flowSize = frec.size;
          fdata->flowMode &= FL_ROOT_DIR ^ 0xffff;
          fdata->flowPosition = 0;
          fdata->clusterPosition = 0;
          fdata->dirStartSection = frec.sSection;
          fdata->dirEndSection = frec.eSection;
          fdata->dirSectionSector = frec.dirSectionSector;
        }
      }
    }
  }
  else
  {
    if( ( fdata->attributes & FAT_ATTR_DIR ) == 0 ) return FS_ER_THIS_IS_NOT_DIRRECTORY;
    if( ( res = open( f, FL_READ ) ) != NULL ) return res;
    founded = FS_FALSE;
    while( FS_TRUE )
    {
      if( ( res = readFileRecord( f, &frec ) ) != 0 ) break;
      if( fsUtils::upCaseCmp( frec.name, objName ) ) { founded = FS_TRUE; break; }
    }
    if( ( res != FS_WR_NOT_ENOUGHT_RECORDS ) && ( res != 0 ) )
    {
      close( f );
      return res;
    }
    if( ( res = close( f ) ) != 0 ) return res;
    if( !founded )
    {
      return FS_WR_NOT_ENOUGHT_RECORDS;
    }
    else
    {
      if( ( frec.attributes & FAT_ATTR_DIR ) == 0 )
      {
        if( ( res = fdata->prepareParentDirInfo() ) != 0 ) return res;
      }
      if( !f->data->incPath( frec.name ) )
      {
        fdata->clearParentDirInfo();
        return FS_ER_CANT_ALLOCATE_MEMORY;
      }
      fdata->attributes = frec.attributes;
      fdata->timeCreateYMD = frec.tcymd;
      fdata->timeCreateHMS = frec.tchms;
      fdata->timeModifyYMD = frec.tmymd;
      fdata->timeModifyHMS = frec.tmhms;
      fdata->startCluster = frec.startCluster;
      fdata->startSector = ldInfo->firstSectorOfCluster( frec.startCluster );
      fdata->currentSector = 0;
      fdata->currentCluster = 0;
      fdata->flowSize = frec.size;
      fdata->flowMode &= FL_ROOT_DIR ^ 0xffff;
      fdata->flowPosition = 0;
      fdata->clusterPosition = 0;
      fdata->dirStartSection = frec.sSection;
      fdata->dirEndSection = frec.eSection;
      fdata->dirSectionSector = frec.dirSectionSector;
    }
  }
  return FS_OK;
}
// ---------------------------------------------------------------------------
FS_UINT16 Fat::init( File* f )
{
  FATFileData* newData;
  FS_UINT16 HMS, YMD;

  if( f == NULL ) return FS_ER_NULL_POINTER;
  if( f->data == NULL ) return FS_ER_NULL_POINTER;

  newData = new FATFileData;
  if( newData == NULL ) return FS_ER_CANT_ALLOCATE_MEMORY;

  newData->copyPath( f->data );
  newData->attributes = FAT_ATTR_DIR;
  newData->startCluster = ldInfo->rootDirCluster;
  newData->currentCluster = newData->startCluster;
  newData->clusterPosition = 0;
  newData->flowPosition = 0;
  newData->flowMode = FL_ROOT_DIR;
  fsUtils::timeUnix2Dos( myMountPoint->createTime, &YMD, &HMS );
  newData->timeCreateYMD = YMD;
  newData->timeCreateHMS = HMS;
  newData->timeModifyYMD = YMD;
  newData->timeModifyHMS = HMS;
  newData->dirStartSection = 0;
  newData->dirEndSection = 0;
  switch( ldInfo->fsType )
  {
    case FS_FAT12:
    case FS_FAT16:
    {
      newData->flowSize = ldInfo->rootDirSectors << 9;
      newData->startSector = ldInfo->rootDirStart;
    }
    break;
    case FS_FAT32:
    {
      FS_UINT32 len;
      FS_UINT16 res;
      newData->startSector = ldInfo->firstSectorOfCluster( newData->startCluster );
      if( ( res = fatGetSequenceLength( ldInfo->rootDirCluster, &len ) ) != 0 )
      {
        delete newData;
        return res;
      }
      newData->flowSize = ( len * ldInfo->sectorsPerCluster ) << 9;
    }
    break;
  }
  newData->currentSector = newData->startSector;
  
  delete f->data;
  f->data = newData;

  return FS_OK;
}
// ---------------------------------------------------------------------------
FS_UINT16 Fat::open( File* f, FS_UINT16 mode )
{
  FATFileData* fdata;
  FS_UINT16 res;

  if( f == NULL ) return FS_ER_NULL_POINTER;
  if( f->data == NULL ) return FS_ER_NULL_POINTER;

  fdata = (FATFileData*)f->data;

  fdata->flowMode = mode;
  if( strcmp( fdata->getPath(), myMountPoint->name ) == 0 )
  {
    fdata->flowMode |= FL_ROOT_DIR;
    if( ( ldInfo->fsType == FS_FAT12 ) || ( ldInfo->fsType == FS_FAT16 ) )
    {
      fdata->cashSize = ldInfo->rootDirSectors << 9;
    }
    else
    {
      fdata->cashSize = (FS_UINT32)ldInfo->sectorsPerCluster << 9;
    }
  }
  else
  {
    fdata->cashSize = (FS_UINT32)ldInfo->sectorsPerCluster << 9;
  }
  fdata->cash = (FS_UINT8*)fs_alloc( fdata->cashSize ); //new FS_UINT8[fdata->cashSize];
  if( fdata->cash == NULL )
  {
    fdata->flowMode = 0;
    fdata->cashSize = 0;
    return FS_ER_CANT_ALLOCATE_MEMORY;
  }
  fdata->currentSector = fdata->startSector;
  fdata->currentCluster = fdata->startCluster;
  fdata->flowPosition = 0;
  fdata->clusterPosition = 0;

  if( ( res = doCashCluster( f ) ) != 0 )
  {
    close( f );
    return res;
  }

  return FS_OK;
}
// ---------------------------------------------------------------------------
FS_UINT16 Fat::close( File* f )
{
  FATFileData* fdata;
  FS_UINT16 res;
  int mode;

  if( f == NULL ) return FS_ER_NULL_POINTER;
  if( f->data == NULL ) return FS_ER_NULL_POINTER;

  fdata = (FATFileData*)f->data;

  if( ( res = doCashStore( f ) ) != 0 )
  {
  asm(" nop");
    goto c_exit;
}

  mode = fdata->flowMode & 3;
  fdata->flowMode &= 0xfffc;

  if( ( ( fdata->flowMode & FL_ROOT_DIR ) == 0 ) && ( ( mode & FL_WRITE ) != 0 ) )
  {
    FS_UINT32 recOffset;
    InterfaceFileRec* fileRec;
    FS_UINT16 YMD, HMS;
    char Nbuf[512];
    
    recOffset = ( fdata->dirEndSection << 5 ) & 0x000001ff;
    fileRec = (InterfaceFileRec*)( Nbuf + recOffset );
    
    FS_LOCK();
    
    if( ( res = dev.readSector( ldInfo->dev, Nbuf, fdata->dirSectionSector, 1 ) ) != 0 ) goto c_unlock_exit;
    fsUtils::timeUnix2Dos( time( NULL ), &YMD, &HMS );
    fileRec->WrtTime = HMS;
    fileRec->WrtDate = YMD;
    if( ( fdata->attributes & FAT_ATTR_DIR ) == 0 )
    {
      fileRec->FileSize = fdata->flowSize;
    }
    else
    {
      fileRec->FileSize = 0;
    }
    fileRec->FstClusHi = (FS_UINT16)( fdata->startCluster >> 16 );
    fileRec->FstClusLo = (FS_UINT16)( fdata->startCluster & 0x0000ffff );
    res = dev.writeSector( ldInfo->dev, Nbuf, fdata->dirSectionSector, 1 );

  c_unlock_exit:

    FS_UNLOCK();
  }

c_exit:

  fs_free( fdata->cash );
  fdata->cash = NULL;
  fdata->cashSize = 0;
  fdata->cashModifyed = FS_FALSE;
  fdata->cashCluster = 0xffffffff;
  fdata->flowPosition = 0;
  fdata->clusterPosition = 0;
  fdata->currentCluster = 0;
  fdata->currentSector = 0;

  return res;
}
// ---------------------------------------------------------------------------
FS_UINT16 Fat::read( File* f, void* dataPtr, FS_UINT32 length )
{
  FATFileData* fdata;
  FS_UINT32 needBytes;
  FS_BOOL wrn = FS_FALSE;
  FS_UINT16 res;
  FS_UINT32 rsize;
  FS_CHAR* dstPtr = (FS_CHAR*)dataPtr;
  FS_CHAR* srcPtr;

  if( ( f == NULL ) || ( dataPtr == NULL ) ) return FS_ER_NULL_POINTER;
  if( f->data == NULL ) return FS_ER_NULL_POINTER;

  fdata = (FATFileData*)f->data;
  if( ( fdata->flowMode & FL_READ ) == 0 ) return FS_ER_CANT_READ_FROM_FILE;

  fdata->rwCounter = 0;
  needBytes = fdata->flowSize - fdata->flowPosition;
  if( needBytes >= length ) needBytes = length;
  fdata->flowMode |= FL_READING;

  while( needBytes != 0 )
  {
    if( fdata->clusterPosition == fdata->cashSize )
    {
      res = getNextClusterNumber( f );
      switch( res )
      {
        case FS_ER_FAT_EOF: wrn = FS_TRUE; break;
        case FS_OK: break;
        default:
          fdata->flowMode &= FL_READING ^ 0xffff;
          return res;
      }
      if( wrn ) break;
      if( ( res = doCashCluster( f ) ) != 0 )
      {
        fdata->flowMode &= FL_READING ^ 0xffff;
        return res;
      }
    }
    if( ( fdata->clusterPosition + needBytes ) > fdata->cashSize ) rsize = fdata->cashSize - fdata->clusterPosition; else rsize = needBytes;
    srcPtr = (FS_CHAR*)fdata->cash + fdata->clusterPosition;
    memcpy( dstPtr, srcPtr, rsize );
    needBytes -= rsize;
    fdata->clusterPosition += rsize;
    fdata->flowPosition += rsize;
    fdata->rwCounter += rsize;
    dstPtr += rsize;
  }

  fdata->flowMode &= FL_READING ^ 0xffff;
  if( wrn ) return FS_WR_FLOW_TOO_SHORT;

  return FS_OK;
}
// ---------------------------------------------------------------------------
FS_UINT16 Fat::write( File* f, void* dataPtr, FS_UINT32 length )
{
  FATFileData* fdata;
  FS_UINT32 rsize, clv;
  FS_UINT16 res;
  FS_UINT8* srcPtr = (FS_UINT8*)dataPtr;
  FS_UINT8* dstPtr;

  if( ( f == NULL ) || ( dataPtr == NULL ) ) return FS_ER_NULL_POINTER;
  if( f->data == NULL ) return FS_ER_NULL_POINTER;

  fdata = (FATFileData*)f->data;
  if( ( fdata->flowMode & FL_WRITE ) == 0 ) return FS_ER_CANT_READ_FROM_FILE;
  fdata->rwCounter = 0;

  if( ( fdata->startCluster == 0 ) && ( ( fdata->flowMode & FL_ROOT_DIR ) == 0 ) )
  {
    if( ( res = fatAllocFreeCluster( 0, &clv ) ) != 0 ) return res;
    memset( fdata->cash, 0, fdata->cashSize );
    fdata->cashCluster = clv;
    fdata->startCluster = clv;
    fdata->startSector = ldInfo->firstSectorOfCluster( clv );
    fdata->currentSector = fdata->startSector;
    fdata->currentCluster = clv;
    if( ( fdata->attributes & FAT_ATTR_DIR ) != 0 )
    {
      fdata->flowSize = fdata->cashSize;
      memset( fdata->cash, 0, fdata->cashSize );
      fdata->cashCluster = clv;
      fdata->cashModifyed = FS_TRUE;
    }
    else
    {
      fdata->flowSize = 0;
    }
  }

  while( length != 0 )
  {
    if( fdata->clusterPosition == fdata->cashSize )
    {
      if( ( res = getNextClusterNumber( f ) ) != 0 ) return res;
      fdata->cashModifyed = FS_TRUE;
      if( fdata->newClusterAllocated )
      {
        if( ( res = doCashStore( f ) ) != 0 ) return res;
        fdata->newClusterAllocated = FS_FALSE;
        fdata->cashCluster = fdata->currentCluster;
        memset( fdata->cash, 0, fdata->cashSize );
      }
      else
      {
        if( ( res = doCashCluster( f ) ) != 0 ) return res;
      }
    }
    if( ( fdata->clusterPosition + length ) > fdata->cashSize ) rsize = fdata->cashSize - fdata->clusterPosition; else rsize = length;
    dstPtr = fdata->cash + fdata->clusterPosition;
    memcpy( dstPtr, srcPtr, rsize );
    length -= rsize;
    fdata->clusterPosition += rsize;
    fdata->flowPosition += rsize;
    fdata->rwCounter += rsize;
    srcPtr += rsize;
  }

  fdata->cashModifyed = FS_TRUE;
  if( fdata->flowPosition > fdata->flowSize ) fdata->flowSize = fdata->flowPosition;

  return FS_OK;
}
// ---------------------------------------------------------------------------
FS_UINT16 Fat::eof( File* f, FS_BOOL* state )
{
  FATFileData* fdata;
  if( ( f == NULL ) || ( state == NULL ) ) return FS_ER_NULL_POINTER;
  if( f->data == NULL ) return FS_ER_NULL_POINTER;
  fdata = (FATFileData*)f->data;
  (*state) = (FS_BOOL)( fdata->flowSize == fdata->flowPosition );
  return FS_OK;
}
// ---------------------------------------------------------------------------
FS_UINT16 Fat::seek( File* f, FS_INT32 offset, FS_UINT32 startPoint )
{
  FATFileData* fdata;
  FS_INT32 absolutePosition;
  FS_UINT32 skipClusters, i;
  FS_UINT16 res;

  if( f == NULL ) return FS_ER_NULL_POINTER;
  if( f->data == NULL ) return FS_ER_NULL_POINTER;

  fdata = (FATFileData*)f->data;

  if( ( fdata->flowMode & 3 ) == 0 ) return FS_ER_FLOW_NOT_OPENED;

  switch( startPoint )
  {
    case OLD_SEEK_SET: absolutePosition = offset; break;
    case OLD_SEEK_END: absolutePosition = fdata->flowSize + offset; break;
    case OLD_SEEK_CUR: absolutePosition = fdata->flowPosition + offset; break;
    default: absolutePosition = startPoint + offset; break;
  }
  if( absolutePosition < 0 ) absolutePosition = 0;
  if( absolutePosition > fdata->flowSize )
  {
    if( ( fdata->flowMode & FL_WRITE ) != 0 )
    {
      FS_UINT32 rsize, needw = absolutePosition - fdata->flowSize;
      FS_UINT8 buf[32];
      FS_UINT16 res;
      if( ( res = seek( f, 0, OLD_SEEK_END ) ) != 0 ) return res;
      memset( buf, 0, 32 );
      while( needw != 0 )
      {
        if( needw > 32 ) rsize = 32; else rsize = needw;
        if( ( res = write( f, buf, rsize ) ) != 0 ) return res;
        needw -= rsize;
      }
      return FS_OK;
    }
    else
    {
      absolutePosition = fdata->flowSize;
    }
  }

  fdata->currentCluster = fdata->startCluster;
  fdata->currentSector = fdata->startSector;
  fdata->flowPosition = 0;
  fdata->clusterPosition = 0;

  if( fdata->flowSize == 0 ) return FS_OK;

  skipClusters = absolutePosition / fdata->cashSize;
  if( fsUtils::fsMod( absolutePosition, fdata->cashSize ) == 0 )
  {
    if( skipClusters > 0 ) skipClusters--;
    for( i = 0; i < skipClusters; i++ ) if( ( res = getNextClusterNumber( f ) ) != 0 ) return res;
    if( absolutePosition != 0 ) fdata->clusterPosition = fdata->cashSize;
  }
  else
  {
    for( i = 0; i < skipClusters; i++ ) if( ( res = getNextClusterNumber( f ) ) != 0 ) return res;
    fdata->clusterPosition = fsUtils::fsMod( absolutePosition, fdata->cashSize );
  }
  fdata->flowPosition = absolutePosition;

  if( ( res = doCashCluster( f ) ) != 0 ) return res;

  return FS_OK;
}
// ---------------------------------------------------------------------------
FS_UINT16 Fat::getNextClusterNumber( File* f )
{
  FATFileData* fdata;
  FS_UINT32 clv;
  FS_UINT16 res, i;
  FS_BOOL feo;

  fdata = (FATFileData*)f->data;

  // todo: Check this modification
  if( ( ( ldInfo->fsType == FS_FAT12 ) || ( ldInfo->fsType == FS_FAT16 ) ) && ( fdata->flowMode & FL_ROOT_DIR ) ) return FS_ER_FAT_EOF;
  // todo: ^^^

  switch( fdata->flowMode & 0x0003 )
  {
    case 1:
    {
      if( ( res = fatGetRecValue( fdata->currentCluster, &clv ) ) != 0 ) return res;
      switch( ldInfo->fsType )
      {
        case FS_FAT12: if( clv >= 0x00000ff8 ) return FS_ER_FAT_EOF; break;
        case FS_FAT16: if( clv >= 0x0000fff8 ) return FS_ER_FAT_EOF; break;
        case FS_FAT32: if( clv >= 0x0ffffff8 ) return FS_ER_FAT_EOF; break;
      }
      fdata->currentCluster = clv;
      fdata->currentSector = ldInfo->firstSectorOfCluster( clv );
      fdata->clusterPosition = 0;
    }
    return FS_OK;

    case 2:
    case 3:
    {
      feo = FS_FALSE;
      if( ( res = fatGetRecValue( fdata->currentCluster, &clv ) ) != 0 ) return res;
      switch( ldInfo->fsType )
      {
        case FS_FAT12: if( clv >= 0x00000ff8 ) feo = FS_TRUE; break;
        case FS_FAT16: if( clv >= 0x0000fff8 ) feo = FS_TRUE; break;
        case FS_FAT32: if( clv >= 0x0ffffff8 ) feo = FS_TRUE; break;
      }
      if( feo )
      {
        if( fdata->flowMode & FL_READING ) return FS_ER_FAT_EOF;

        if( ( res = fatAllocFreeCluster( fdata->currentCluster, &clv ) ) != 0 ) return res;
        fdata->newClusterAllocated = FS_TRUE;
        fdata->currentCluster = clv;
        fdata->currentSector = ldInfo->firstSectorOfCluster( clv );

        if( fdata->attributes & FAT_ATTR_DIR )
        {
          FS_LOCK();
          char Nbuf[512];
          memset( Nbuf, 0, 512 );
          for( i = 0; i < ldInfo->sectorsPerCluster; i++ )
          {
            dev.writeSector( ldInfo->dev, Nbuf, fdata->currentSector + i, 1 );
          }
          
          FS_UNLOCK();
          
          fdata->flowSize += ldInfo->sectorsPerCluster << 9;
        }
      }
      else
      {
        fdata->currentCluster = clv;
        fdata->currentSector = ldInfo->firstSectorOfCluster( clv );
      }
      fdata->clusterPosition = 0;
    }
    return FS_OK;
  }

  return FS_ER_FLOW_NOT_OPENED;
}
// ---------------------------------------------------------------------------
FS_UINT16 Fat::doCashCluster( File* f )
{
  FS_UINT16 res;
  FATFileData* fdata;
  FS_UINT8* cptr;
  FS_UINT16 needSectors;
  FS_UINT32 csector, rs;
  FS_BOOL nf32rd;

  if( f == NULL ) return FS_ER_NULL_POINTER;
  if( f->data == NULL ) return FS_ER_NULL_POINTER;

  fdata = (FATFileData*)f->data;

  if( fdata->cashCluster == fdata->currentCluster ) return FS_OK;

  nf32rd = ( ( fdata->flowMode & FL_ROOT_DIR ) != 0 ) && ( ( ldInfo->fsType == FS_FAT12 ) || ( ldInfo->fsType == FS_FAT16 ) );
  if( fdata->cashModifyed ) if( ( res = doCashStore( f ) ) != 0 ) return res;
  if( !nf32rd && ( fdata->currentCluster == 0 ) ) return FS_OK;
  
  FS_LOCK();

  needSectors = fdata->cashSize >> 9;
  cptr = fdata->cash;
  csector = nf32rd ? fdata->startSector : ldInfo->firstSectorOfCluster( fdata->currentCluster );

  while( needSectors )
  {
    if( needSectors >= mayRead ) rs = mayRead; else rs = needSectors;
    res = dev.readSector( ldInfo->dev, cptr, csector, rs );
    if( res == DEV_WARN_NEED_TO_SHRINK_PORTION )
    {
      mayRead >>= 1;
      continue;
    }
    if( res != 0 ) { FS_UNLOCK(); return res; }
    cptr += rs << 9;
    needSectors -= rs;
    csector += rs;
  }

  FS_UNLOCK();

  fdata->cashCluster = fdata->currentCluster;

  return FS_OK;
}
// ---------------------------------------------------------------------------
FS_UINT16 Fat::doCashStore( File* f )
{
  FS_UINT16 res;
  FATFileData* fdata;
  FS_UINT8* cptr;
  volatile FS_UINT16 needSectors;
  FS_UINT32 csector, rs;
  FS_BOOL nf32rd;

  if( f == NULL ) return FS_ER_NULL_POINTER;
  if( f->data == NULL ) return FS_ER_NULL_POINTER;

  fdata = (FATFileData*)f->data;

  if( fdata->cashModifyed )
  {
    if( fdata->cashCluster == 0xffffffff )
    {
      fdata->cashModifyed = FS_FALSE;
      return FS_OK;
    }

    nf32rd = ( ( fdata->flowMode & FL_ROOT_DIR ) != 0 ) && ( ( ldInfo->fsType == FS_FAT12 ) || ( ldInfo->fsType == FS_FAT16 ) );
    if( !nf32rd && ( fdata->cashCluster == 0 ) ) return FS_ER_BAD_CLUSTER_VALUE;

    FS_LOCK();

    needSectors = fdata->cashSize >> 9;
    cptr = fdata->cash;
    csector = nf32rd ? fdata->startSector : ldInfo->firstSectorOfCluster( fdata->cashCluster );
    
    while( needSectors )
    {
//      rs = 1;
      if( needSectors >= mayRead ) rs = mayRead; else rs = needSectors;
      if( ( res = dev.writeSector( ldInfo->dev, cptr, csector, rs ) ) != 0 ) { FS_UNLOCK(); return res; }
      cptr += rs << 9;
      needSectors -= rs;
      csector += rs;
    }
    
    FS_UNLOCK();

    fdata->cashModifyed = FS_FALSE;
  }

  return FS_OK;
}
// ---------------------------------------------------------------------------
FS_UINT32 Fat::fatGetCashIndex( FS_UINT32 sector )
{
  FS_UINT32 i;
  FS_UINT32 fatCLSI;
  FS_UINT16 fatCLSImin;

  for( i = 0; i < FAT_CASH_SIZE; i++ )
  {
    if( fatCash[i].sector == sector )
    {
      if( fatCash[i].usage < 65000 ) fatCash[i].usage += 4;
      for( fatCLSI = 0; fatCLSI < FAT_CASH_SIZE; fatCLSI++ ) if( fatCash[fatCLSI].usage > 0 ) fatCash[fatCLSI].usage--;
      return i;
    }
  }

  if( i == FAT_CASH_SIZE )
  {
    for( fatCLSImin = 65535, fatCLSI = 0, i = 0; i < FAT_CASH_SIZE; i++ )
    {
      if( fatCash[i].usage < fatCLSImin )
      {
        fatCLSImin = fatCash[i].usage;
        fatCLSI = i;
      }
    }
    if( dev.readSector( ldInfo->dev, fatCash[fatCLSI].data, sector, 1 ) != 0 )
    {
      if( dev.readSector( ldInfo->dev, fatCash[fatCLSI].data, sector + ldInfo->fatSize, 1 ) != 0 ) return 0xffffffff;
    }
    fatCash[fatCLSI].sector = sector;
    fatCash[fatCLSI].usage = 1;
  }

  return fatCLSI;
}
// ---------------------------------------------------------------------------
FS_UINT16 Fat::fatGetRecValue( FS_UINT32 cluster, FS_UINT32* value )
{
  FS_UINT32 lFatOffset, lFatSecNum, lFatEntOffset, csi;
  FS_UINT8* cs;

  if( ( cluster < 2 ) || ( ( cluster - 2 ) >= ldInfo->totalClusters ) ) return FS_ER_BAD_CLUSTER_VALUE;

  switch( ldInfo->fsType )
  {
    case FS_FAT12: lFatOffset = cluster + ( cluster >> 1 ); break;
    case FS_FAT16: lFatOffset = cluster << 1; break;
    case FS_FAT32: lFatOffset = cluster << 2; break;
  }
  lFatSecNum = ldInfo->fatStart + ( lFatOffset >> 9 );
  lFatEntOffset = lFatOffset & 0x000001ff;

  FS_LOCK1();

  if( ( csi = fatGetCashIndex( lFatSecNum ) ) == 0xffffffff ) { FS_UNLOCK1(); return FS_ER_FAT_CRASHED; }
  cs = fatCash[csi].data;

  switch( ldInfo->fsType )
  {
    case FS_FAT12:
    {
      if( lFatEntOffset == 511 )
      {
        (*value) = (FS_UINT32)cs[511];
        if( ( csi = fatGetCashIndex( lFatSecNum + 1 ) ) == 0xffffffff ) { FS_UNLOCK1(); return FS_ER_FAT_CRASHED; }
        cs = fatCash[csi].data;
        (*value) += ( (FS_UINT32)cs[0] << 8 );
      }
      else
      {
        (*value) = (FS_UINT32)cs[lFatEntOffset] + ( (FS_UINT32)cs[lFatEntOffset+1] << 8 );
      }
      if( cluster & 1 ) (*value) >>= 4; else (*value) &= 0x00000fff;
    }
    break;
    case FS_FAT16:
    {
      (*value) = (FS_UINT32)cs[lFatEntOffset++];
      (*value) += ( (FS_UINT32)cs[lFatEntOffset] ) << 8;
    }
    break;
    case FS_FAT32:
    {
      (*value) = (FS_UINT32)cs[lFatEntOffset++];
      (*value) += ( (FS_UINT32)cs[lFatEntOffset++] ) << 8;
      (*value) += ( (FS_UINT32)cs[lFatEntOffset++] ) << 16;
      (*value) += ( (FS_UINT32)cs[lFatEntOffset] ) << 24;
      (*value) &= 0x0fffffff;
    }
    break;
  }

  FS_UNLOCK1();

  return FS_OK;
}
// ---------------------------------------------------------------------------
FS_UINT16 Fat::fatSetRecValue( FS_UINT32 cluster, FS_UINT32 value )
{
  FS_UINT32 lFatOffset, lFatSecNum, lFatEntOffset, csi;
  FS_UINT16 res1, res2;
  FS_UINT8* cs;

  if( ( cluster < 2 ) || ( ( cluster - 2 ) >= ldInfo->totalClusters ) ) return FS_ER_BAD_CLUSTER_VALUE;

  switch( ldInfo->fsType )
  {
    case FS_FAT12: lFatOffset = cluster + ( cluster >> 1 ); break;
    case FS_FAT16: lFatOffset = cluster << 1; break;
    case FS_FAT32: lFatOffset = cluster << 2; break;
  }
  lFatSecNum = ldInfo->fatStart + ( lFatOffset >> 9 );
  lFatEntOffset = lFatOffset & 0x000001ff;

  FS_LOCK1();

  if( ( csi = fatGetCashIndex( lFatSecNum ) ) == 0xffffffff ) { FS_UNLOCK1(); return FS_ER_FAT_CRASHED; }
  cs = fatCash[csi].data;

  switch( ldInfo->fsType )
  {
    case FS_FAT12:
    {
      if( lFatEntOffset == 511 )
      {
        if( cluster & 1 )
        {
          cs[511] &= 0x000f;
          cs[511] |= ( (FS_UINT16)value & 0x0000000f ) << 4;
          res1 = dev.writeSector( ldInfo->dev, cs, lFatSecNum, 1 );
          res2 = dev.writeSector( ldInfo->dev, cs, lFatSecNum + ldInfo->fatSize, 1 );
          if( ( res1 != 0 ) && ( res2 != 0 ) ) { FS_UNLOCK1(); return FS_ER_FAT_CRASHED; }
          if( ( csi = fatGetCashIndex( lFatSecNum + 1 ) ) == 0xffffffff ) { FS_UNLOCK1(); return FS_ER_FAT_CRASHED; }
          cs = fatCash[csi].data;
          cs[0] = ( (FS_UINT16)value >> 4 );
        }
        else
        {
          cs[511] = (FS_UINT16)( value & 0x000000ff );
          res1 = dev.writeSector( ldInfo->dev, cs, lFatSecNum, 1 );
          res2 = dev.writeSector( ldInfo->dev, cs, lFatSecNum + ldInfo->fatSize, 1 );
          if( ( res1 != 0 ) && ( res2 != 0 ) ) { FS_UNLOCK1(); return FS_ER_FAT_CRASHED; }
          if( ( csi = fatGetCashIndex( lFatSecNum + 1 ) ) == 0xffffffff ) { FS_UNLOCK1(); return FS_ER_FAT_CRASHED; }
          cs = fatCash[csi].data;
          cs[0] &= 0x00f0;
          cs[0] |= (FS_UINT16)( value >> 8 ) & 0x000f;
        }
        res1 = dev.writeSector( ldInfo->dev, cs, lFatSecNum + 1, 1 );
        res2 = dev.writeSector( ldInfo->dev, cs, lFatSecNum + ldInfo->fatSize + 1, 1 );
        if( ( res1 != 0 ) && ( res2 != 0 ) ) { FS_UNLOCK1(); return FS_ER_FAT_CRASHED; }
      }
      else
      {
        if( cluster & 1 )
        {
          cs[lFatEntOffset] &= 0x000f;
          cs[lFatEntOffset] |= ( (FS_UINT16)value & 0x0000000f ) << 4;
          cs[lFatEntOffset+1] = ( (FS_UINT16)value >> 4 );
        }
        else
        {
          cs[lFatEntOffset] = (FS_UINT16)( value & 0x000000ff );
          cs[lFatEntOffset+1] &= 0x00f0;
          cs[lFatEntOffset+1] |= (FS_UINT16)( value >> 8 );
        }
        res1 = dev.writeSector( ldInfo->dev, cs, lFatSecNum, 1 );
        res2 = dev.writeSector( ldInfo->dev, cs, lFatSecNum + ldInfo->fatSize, 1 );
        if( ( res1 != 0 ) && ( res2 != 0 ) ) { FS_UNLOCK1(); return FS_ER_FAT_CRASHED; }
      }
    }
    break;
    case FS_FAT16:
    {
      cs[lFatEntOffset] = (FS_UINT16)( value & 0x000000ff );
      cs[lFatEntOffset+1] = (FS_UINT16)( ( value >> 8 ) & 0x000000ff );
      res1 = dev.writeSector( ldInfo->dev, cs, lFatSecNum, 1 );
      res2 = dev.writeSector( ldInfo->dev, cs, lFatSecNum + ldInfo->fatSize, 1 );
      if( ( res1 != 0 ) && ( res2 != 0 ) ) { FS_UNLOCK1(); return FS_ER_FAT_CRASHED; }
    }
    break;
    case FS_FAT32:
    {
      cs[lFatEntOffset] = (FS_UINT16)( value & 0x000000ff );
      cs[lFatEntOffset+1] = (FS_UINT16)( ( value >> 8 ) & 0x000000ff );
      cs[lFatEntOffset+2] = (FS_UINT16)( ( value >> 16 ) & 0x000000ff );
      cs[lFatEntOffset+3] = (FS_UINT16)( ( value >> 24 ) & 0x000000ff );
      res1 = dev.writeSector( ldInfo->dev, cs, lFatSecNum, 1 );
      res2 = dev.writeSector( ldInfo->dev, cs, lFatSecNum + ldInfo->fatSize, 1 );
      if( ( res1 != 0 ) && ( res2 != 0 ) ) { FS_UNLOCK1(); return FS_ER_FAT_CRASHED; }
    }
    break;
  }

  if( value == 0 )
  {
    if( ldInfo->firstFreeCluster > cluster ) ldInfo->firstFreeCluster = cluster;
    #ifdef VFAT_SECLEAN_FULL
    FS_UINT8* debuf;
    FS_UINT32 debufSize, needSectors, rsn, debuf_s;
    lFatSecNum = ldInfo->firstSectorOfCluster( cluster );
    if( ldInfo->sectorsPerCluster > 1 )
    {
      if( ldInfo->sectorsPerCluster >= mayRead )
      {
        debuf_s = (FS_UINT32)mayRead;
      }
      else
      {
        debuf_s = (FS_UINT32)ldInfo->sectorsPerCluster;
      }
    }
    else
    {
      debuf_s = 1;
    }
    debufSize = debuf_s << 9;
    debuf = (FS_UINT8*)fs_alloc( debufSize ); //new FS_UINT8[debufSize];
    if( debuf == NULL )
    {
      char Nbuf[512];
      for( csi = 0; csi < ldInfo->sectorsPerCluster; csi++ )
      {
        fsUtils::rnd( Nbuf, 512 );
        if( ( res1 = dev.writeSector( ldInfo->dev, Nbuf, lFatSecNum + csi, 1 ) ) != 0 ) { FS_UNLOCK1(); return res1; }
      }
    }
    else
    {
      needSectors = ldInfo->sectorsPerCluster;
      while( needSectors )
      {
        if( needSectors > debuf_s ) rsn = debuf_s; else rsn = needSectors;
        fsUtils::rnd( debuf, rsn << 9 );
        if( ( res1 = dev.writeSector( ldInfo->dev, debuf, lFatSecNum, rsn ) ) != 0 ) { fs_free( debuf ); FS_UNLOCK1(); return res1; }
        needSectors -= rsn;
        lFatSecNum += rsn;
      }
      fs_free( debuf );
    }
    #endif
  }
  
  if( ldInfo->freeClusters != 0xffffffff )
  {
    if( value == 0 ) ldInfo->freeClusters++; else ldInfo->freeClusters--;
  }

  FS_UNLOCK1();

  return FS_OK;
}
// ---------------------------------------------------------------------------
FS_UINT16 Fat::fatAllocFreeCluster( FS_UINT32 prev, FS_UINT32* cluster )
{
  FS_UINT32 clv, eval;
  FS_UINT16 res = FS_OK;

  FS_LOCK0();

  if( ldInfo->firstFreeCluster == 0xffffffff )
  {
    if( ( res = fatFindFirstFreeCluster( 2 ) ) != 0 ) goto l_fail;
  }
  else
  {
    if( ( res = fatGetRecValue( ldInfo->firstFreeCluster, &clv ) ) != 0 ) goto l_fail;
    if( clv != 0 )
    {
      if( ( res = fatFindFirstFreeCluster( ldInfo->firstFreeCluster ) ) != 0 ) goto l_fail;
    }
  }
  if( prev != 0 ) if( ( res = fatSetRecValue( prev, ldInfo->firstFreeCluster ) ) != 0 ) goto l_fail;
  switch( ldInfo->fsType )
  {
    case FS_FAT12: eval = 0x00000ff8; break;
    case FS_FAT16: eval = 0x0000fff8; break;
    case FS_FAT32: eval = 0x0ffffff8; break;
  }
  if( ( res = fatSetRecValue( ldInfo->firstFreeCluster, eval ) ) != 0 ) goto l_fail;
  (*cluster) = ldInfo->firstFreeCluster;

l_fail:

  FS_UNLOCK0();

  return res;
}
// ---------------------------------------------------------------------------
FS_UINT16 Fat::fatRemoveFrom( FS_UINT32 cluster )
{
  FS_UINT32 clv;
  FS_UINT16 res = FS_OK;
  FS_BOOL exitFlag = FS_FALSE;

  FS_LOCK0();

  if( cluster < 2 ) goto l_fail;
  if( ( cluster - 2 ) >= ldInfo->totalClusters ) { res = FS_ER_BAD_CLUSTER_VALUE; goto l_fail; }

  while( FS_TRUE )
  {
    if( ( res = fatGetRecValue( cluster, &clv ) ) != NULL ) goto l_fail;
    if( clv == 0 ) { res = FS_ER_FAT_ZERO_RECORD; goto l_fail; }
    switch( ldInfo->fsType )
    {
      case FS_FAT12: if( clv >= 0x00000ff8 ) exitFlag = FS_TRUE; break;
      case FS_FAT16: if( clv >= 0x0000fff8 ) exitFlag = FS_TRUE; break;
      case FS_FAT32: if( clv >= 0x0ffffff8 ) exitFlag = FS_TRUE; break;
    }
    if( ( res = fatSetRecValue( cluster, 0 ) ) != 0 ) goto l_fail;
    if( exitFlag ) break;
    cluster = clv;
  }

l_fail:

  FS_UNLOCK0();

  return res;
}
// ---------------------------------------------------------------------------
FS_UINT16 Fat::fatGetSequenceLength( FS_UINT32 startCluster, FS_UINT32* length )
{
  FS_UINT32 clv;
  FS_UINT16 res = FS_OK;
  FS_BOOL exitFlag = FS_FALSE;

  FS_LOCK0();

  if( startCluster < 2 )
  {
    (*length) = 0;
    goto l_fail;
  }
  (*length) = 1;
  while( FS_TRUE )
  {
    if( ( res = fatGetRecValue( startCluster, &clv ) ) != NULL ) goto l_fail;
    if( clv == 0 ) { res = FS_ER_FAT_ZERO_RECORD; goto l_fail; }
    switch( ldInfo->fsType )
    {
      case FS_FAT12: if( clv >= 0x00000ff8 ) exitFlag = FS_TRUE; break;
      case FS_FAT16: if( clv >= 0x0000fff8 ) exitFlag = FS_TRUE; break;
      case FS_FAT32: if( clv >= 0x0ffffff8 ) exitFlag = FS_TRUE; break;
    }
    if( exitFlag ) break; else (*length)++;
    startCluster = clv;
  }

l_fail:

  FS_UNLOCK0();

  return res;
}
// ---------------------------------------------------------------------------
FS_UINT16 Fat::tell( File* f, FS_UINT32* offset )
{
  FATFileData* fdata = (FATFileData*)f->data;
  if( ( f == NULL ) || ( offset == NULL ) ) return FS_ER_NULL_POINTER;
  if( f->data == NULL ) return FS_ER_NULL_POINTER;
  if( ( fdata->flowMode & 3 ) == 0 ) return FS_ER_FLOW_NOT_OPENED;
  (*offset) = fdata->flowPosition;
  return FS_OK;
}
// ---------------------------------------------------------------------------
FS_UINT16 Fat::findFirst( File* f, FS_CHAR* mask, FS_UINT32 attr, FileInfo* info )
{
  FS_UINT16 res;
  FATFileData* fdata = (FATFileData*)f->data;

  if( ( f == NULL ) || ( mask == NULL ) || ( info == NULL ) ) return FS_ER_NULL_POINTER;
  if( f->data == NULL ) return FS_ER_NULL_POINTER;

  if( fdata->findMask != NULL ) findClose(f);
  res = strlen( mask ) + 1;
  fdata->findMask = (FS_CHAR*)fs_alloc( res ); // new FS_CHAR[res];
  if( fdata->findMask == NULL ) return FS_ER_CANT_ALLOCATE_MEMORY;
  memcpy( fdata->findMask, mask, res );
  fdata->findAttr = attr;
  if( ( fdata->flowMode & 3 ) == 0 ) if( ( res = open( f, FL_READ ) ) != 0 ) return res;
  if( ( res = seek( f, 0, OLD_SEEK_SET ) ) != 0 ) return res;
  if( fsUtils::upCaseCmp( myMountPoint->name, fdata->getPath() ) && fsUtils::upCaseMaskCmp( fdata->findMask, const_fs_BackPointer ) )
  {
    info->clear();
    info->name = (FS_CHAR*)fs_alloc( 3 ); // new FS_CHAR[3];
    if( info->name == NULL ) return FS_ER_CANT_ALLOCATE_MEMORY;
    info->name[0] = '.';
    info->name[1] = '.';
    info->name[2] = 0;
    info->size = 0;
    info->createTime = myMountPoint->createTime;
    info->attr = 0777;
    return FS_OK;
  }

  return findNext( f, info );
}
// ---------------------------------------------------------------------------
FS_UINT16 Fat::findNext( File* f, FileInfo* info )
{
  FATFileRecord frec;
  FS_UINT32 ctime;
  FS_UINT16 stl, res;
  FATFileData* fdata = (FATFileData*)f->data;

  if( ( f == NULL ) || ( info == NULL ) ) return FS_ER_NULL_POINTER;
  if( f->data == NULL ) return FS_ER_NULL_POINTER;

  info->clear();

  while( FS_TRUE )
  {
    if( ( res = readFileRecord( f, &frec ) ) != 0 ) return res;
    if( !fsUtils::upCaseMaskCmp( fdata->findMask, frec.name ) ) continue;
    if( ( frec.attributes & fdata->findAttr ) != fdata->findAttr ) continue;
    break;
  }
  stl = strlen( frec.name ) + 1;
  fsUtils::timeDos2Unix( frec.tcymd, frec.tchms, &ctime );
  info->name = (FS_CHAR*)fs_alloc( stl ); //new FS_CHAR[stl];
  if( info->name == NULL ) return FS_ER_CANT_ALLOCATE_MEMORY;
  memcpy( info->name, frec.name, stl );
  info->size = frec.size;
  info->createTime = ctime;
  info->attr = frec.attributes;

  return FS_OK;
}
// ---------------------------------------------------------------------------
FS_UINT16 Fat::findClose( File* f )
{
  FS_UINT16 res;
  FATFileData* fdata = (FATFileData*)f->data;
  if( f == NULL ) return FS_ER_NULL_POINTER;
  if( f->data == NULL ) return FS_ER_NULL_POINTER;
  fs_free( fdata->findMask ); // if( fdata->findMask != NULL ) delete fdata->findMask;
  fdata->findMask = NULL;
  fdata->findAttr = 0;
  if( ( res = close( f ) ) != 0 ) return res;
  return FS_OK;
}
// ---------------------------------------------------------------------------
FS_UINT16 Fat::readFileRecord( File* f, FATFileRecord* fRec )
{
  FATFileData* fdata = (FATFileData*)f->data;
  FS_UINT32 currentRecordNumber;
  FS_UINT16 res, sAddr, i, tmp;
  FS_UINT8 buf[32];
  InterfaceFileRec* fileRec = (InterfaceFileRec*)buf;

  if( ( f == NULL ) || ( fRec == NULL ) ) return FS_ER_NULL_POINTER;
  if( f->data == NULL ) return FS_ER_NULL_POINTER;

  fRec->clear();
  fRec->sSection = 0xffffffff;

  if( ( res = tell( f, &currentRecordNumber ) ) != 0 ) return res;
  if( ( currentRecordNumber & 31 ) != 0 )
  {
    if( ( res = seek( f, ( currentRecordNumber >> 5 ) << 5, OLD_SEEK_SET ) ) != 0 ) return res;
  }
  currentRecordNumber >>= 5;
  currentRecordNumber--;

  while( FS_TRUE )
  {
    if( fdata->flowPosition == fdata->flowSize ) return FS_WR_NOT_ENOUGHT_RECORDS;
    if( ( res = read( f, buf, 32 ) ) != 0 ) return res;
    currentRecordNumber++;
    if( ( buf[0] == 0x0000 ) || ( buf[0] == 0x0005 ) || ( buf[0] == 0x00e5 ) ) continue;
    if( fileRec->Attr == FAT_ATTR_EXTREC )
    {
      if( ( fileRec->Name[0] & 0x40 ) != 0 )
      {
        FS_INT16 numOfSections, lfnLength;
        FS_UINT16 j, i;
        InterfaceLFNRec* lfnRec = (InterfaceLFNRec*)buf;

        fRec->clear();
        fRec->sSection = currentRecordNumber;
        numOfSections = lfnRec->number - 0x41;
        for( lfnLength = numOfSections * 13, i = 0; i < 13; i++ )
        {
          tmp = lfnRec->getChar( i );
          if( ( tmp != 0 ) && ( tmp != 0xffff ) ) lfnLength++;
        }
        fRec->name = (FS_CHAR*)fs_alloc( lfnLength + 1 ); //new FS_CHAR[lfnLength+1];
        if( fRec->name == NULL ) return FS_ER_CANT_ALLOCATE_MEMORY;
        memset( fRec->name, 0, lfnLength + 1 );
        for( sAddr = numOfSections * 13, i = 0; i < 13; i++ )
        {
          tmp = lfnRec->getChar( i );
          if( ( tmp == 0 ) || ( tmp == 0xffff ) )
          {
            fRec->name[sAddr+i] = 0;
            break;
          }
          fRec->name[sAddr+i] = unicode_to_cp1251( tmp );
        }
        for( j = 0; j < numOfSections; j++ )
        {
          if( fdata->flowPosition == fdata->flowSize ) return FS_WR_NOT_ENOUGHT_RECORDS;
          if( ( res = read( f, buf, 32 ) ) != 0 ) return res;
          currentRecordNumber++;
          for( sAddr = ( lfnRec->number - 1 ) * 13, i = 0; i < 13; i++ )
          {
            fRec->name[sAddr+i] = unicode_to_cp1251( lfnRec->getChar( i ) );
          }
        }
      }
      continue;
    }
    if( fRec->sSection == 0xffffffff ) fRec->sSection = currentRecordNumber;
    fRec->eSection = currentRecordNumber;
    fRec->dirSectionSector = fdata->currentSector + ( ( fdata->clusterPosition - 32 ) >> 9 ); // todo: need check this modification
    fRec->startCluster = ( (FS_UINT32)fileRec->FstClusHi << 16 ) + (FS_UINT32)fileRec->FstClusLo;
    if( ( fileRec->Name[0] == '.' ) && ( fileRec->Name[1] == '.' ) )
    {
      if( fRec->startCluster == 0 )
      {
        if( ldInfo->fsType == FS_FAT32 ) fRec->startCluster = ldInfo->rootDirCluster;
      }
    }
    fRec->attributes = fileRec->Attr;
    fRec->tcymd = fileRec->CrtDate;
    fRec->tchms = fileRec->CrtTime;
    fRec->tmymd = fileRec->WrtDate;
    fRec->tmhms = fileRec->WrtTime;
    if( ( fileRec->Attr & FAT_ATTR_DIR ) == 0 )
    {
      fRec->size = fileRec->FileSize;
    }
    else
    {
      FS_UINT32 len;
      FS_UINT16 p,stl;
      FS_INT16 i;
      FS_CHAR* cfPath = fdata->getPath();
      FS_BOOL rsf;

      if( ( fileRec->Name[0] == '.' ) && ( fileRec->Name[1] == '.' ) )
      {
        switch( ldInfo->fsType )
        {
          case FS_FAT12:
          case FS_FAT16:
          {
            stl = strlen( cfPath );
            for( i = stl - 1; i >= 0; i-- ) if( cfPath[i] == '/' ) { p = i; break; }
            cfPath[p] = 0;
            rsf = fsUtils::cmpL( cfPath, myMountPoint->name, strlen( myMountPoint->name ) );
            cfPath[p] = '/';
          }
          break;
          case FS_FAT32:
          {
            rsf = FS_FALSE;
          }
          break;
        }
      }
      else
      {
        rsf = FS_FALSE;
      }
      if( rsf )
      {
        fRec->size = ldInfo->rootDirSectors << 9;
      }
      else
      {
        if( ( res = fatGetSequenceLength( fRec->startCluster, &len ) ) != 0 ) return res;
        fRec->size = ( len * ldInfo->sectorsPerCluster ) << 9;
      }
    }
    fRec->shortName = (FS_CHAR*)fs_alloc( 13 ); //new FS_CHAR[13];
    memset( fRec->shortName, 0, 13 );
    if( fRec->shortName == NULL ) return FS_ER_CANT_ALLOCATE_MEMORY;
    if( fRec->attributes == FAT_ATTR_LABLE )
    {
      for( sAddr = 0, i = 0; i < 8; i++ )
      {
        tmp = fileRec->Name[i];
        fRec->shortName[sAddr++] = cp866_to_cp1251( tmp );
      }
      for( i = 0; i < 3; i++ )
      {
        tmp = fileRec->Ext[i];
        fRec->shortName[sAddr++] = cp866_to_cp1251( tmp );
      }
    }
    else
    {
      for( i = 0; i < 8; i++ )
      {
        tmp = fileRec->Name[i];
        if( tmp == 0x20 ) break;
        fRec->shortName[i] = cp866_to_cp1251( tmp );
      }
      sAddr = i;
      fRec->shortName[sAddr++] = '.';
      for( i = 0; i < 3; i++ )
      {
        tmp = fileRec->Ext[i];
        if( tmp == 0x20 )
        {
          if( i == 0 ) fRec->shortName[sAddr-1] = 0;
          break;
        }
        fRec->shortName[sAddr+i] = cp866_to_cp1251( tmp );
      }
    }
    if( fRec->name == NULL )
    {
      tmp = strlen( fRec->shortName ) + 1;
      fRec->name = (FS_CHAR*)fs_alloc( tmp ); //new FS_CHAR[tmp];
      if( fRec->name == NULL )
      {
        fRec->clear();
        return FS_ER_CANT_ALLOCATE_MEMORY;
      }
      memcpy( fRec->name, fRec->shortName, tmp );
    }
    break;
  }

  return FS_OK;
}
// ---------------------------------------------------------------------------
FS_UINT16 Fat::writeFileRecord( File* f, FATFileRecord* fRec )
{
  FS_UINT16 res,stl;
  FATFileData* fdata = (FATFileData*)f->data;
  FATFileRecord cfr;
  FS_BOOL exf = FS_FALSE;
  FS_UINT32 neededSections, startOfNewRecord, currentSection, k, nk;
  FS_UINT8 buf[32];
  FS_CHAR CSum;

  if( ( f == NULL ) || ( fRec == NULL ) ) return FS_ER_NULL_POINTER;
  if( f->data == NULL ) return FS_ER_NULL_POINTER;

  if( ( fdata->attributes & FAT_ATTR_DIR ) == 0 ) return FS_ER_THIS_IS_NOT_DIRRECTORY;
  if( !checkFileRecord( fRec ) ) return FS_ER_BAD_FILE_RECORD_DATA;

  if( fRec->attributes == FAT_ATTR_LABLE )
  {
    if( ( fdata->flowMode & FL_ROOT_DIR ) == 0 ) return FS_ER_THIS_NOT_ROOT_DIR;

    if( ( res = seek( f, 0, OLD_SEEK_SET ) ) != 0 ) return res;
    while( FS_TRUE )
    {
      res = readFileRecord( f, &cfr );
      switch( res )
      {
        case FS_OK: break;
        case FS_WR_NOT_ENOUGHT_RECORDS: exf = FS_TRUE; break;
        default: return res;
      }
      if( exf ) break;
      if( cfr.attributes == FAT_ATTR_LABLE ) break;
    }
    if( !exf )
    {
      if( ( res = seek( f, cfr.eSection << 5, OLD_SEEK_SET ) ) != 0 ) return res;
      if( fRec->name == NULL )
      {
        CSum = ' ';
        for( FS_INT32 i = 0; i < 11; i++ ) if( ( res = write( f, &CSum, 1 ) ) != 0 ) return res;
      }
      else
      {
        for( FS_INT32 i = 0; i < 11; i++ )
        {
          CSum = fsUtils::upCase( fRec->name[i] );
          if( ( res = write( f, &CSum, 1 ) ) != 0 ) return res;
        }
      }
    }
    else
    {
      if( ( res = seek( f, 0, OLD_SEEK_SET ) ) != 0 ) return res;
      currentSection = 0xffffffff;
      while( FS_TRUE )
      {
        if( fdata->flowPosition == fdata->flowSize )
        {
          if( ( ( fdata->flowMode & FL_ROOT_DIR ) != 0 ) && ( ( ldInfo->fsType == FS_FAT12 ) || ( ldInfo->fsType == FS_FAT16 ) ) ) return FS_ER_NOT_ENOUGHT_FREE_SPACE;
          CSum = 0;
          if( ( res = write( f, &CSum, 1 ) ) != 0 ) return res;
          seek( f, -1, OLD_SEEK_CUR );
        }
        read( f, buf, 32 );
        currentSection++;
        if( ( buf[0] == 0 ) || ( buf[0] == 0xe5 ) || ( buf[0] == 0x05 ) ) break;
      }
      if( ( res = seek( f, currentSection << 5, OLD_SEEK_SET ) ) != 0 ) return res;
      if( fRec->name == NULL )
      {
        CSum = ' ';
        for( FS_INT32 i = 0; i < 11; i++ ) if( ( res = write( f, &CSum, 1 ) ) != 0 ) return res;
      }
      else
      {
        for( FS_INT32 i = 0; i < 11; i++ )
        {
          CSum = fsUtils::upCase( fRec->name[i] );
          if( ( res = write( f, &CSum, 1 ) ) != 0 ) return res;
        }
      }
      CSum = FAT_ATTR_LABLE; write( f, &CSum, 1 );
      CSum = 0; for( FS_INT32 i = 0; i < 20; i++ ) write( f, &CSum, 1 );

    }
    return FS_OK;
  }

  seek( f, 0, OLD_SEEK_SET );
  while( FS_TRUE )
  {
    res = readFileRecord( f, &cfr );
    switch( res )
    {
      case FS_OK: break;
      case FS_WR_NOT_ENOUGHT_RECORDS: exf = FS_TRUE; break;
      default: return res;
    }
    if( exf ) break;
    if( fRec->name != NULL ) if( fsUtils::upCaseCmp( cfr.name, fRec->name ) ) return FS_ER_FILE_EXISTS;
  }

  if( fRec->shortName == NULL )
  {
    fRec->shortName = (FS_CHAR*)fs_alloc( 13 ); // new FS_CHAR[13];
    if( fRec->shortName == NULL ) return FS_ER_CANT_ALLOCATE_MEMORY;
    FS_UINT32 ctm = fsUtils::crc32( fRec->name );
    FS_UINT16 i,k;
    for( i = 0; i < 6; i++ )
    {
      k = ctm - ( ctm / 41 ) * 41;
      if( k < 10 ) k += '0';
      else if( k < 36 ) k += 'A' - 10;
      else if( k == 36 ) k  = '_';
      else if( k == 37 ) k  = '!';
      else if( k == 38 ) k  = '@';
      else if( k == 39 ) k  = '$';
      else if( k == 40 ) k  = '%';
      fRec->shortName[i] = k;
      ctm /= 41;
    }
    fRec->shortName[6] = '~';
    fRec->shortName[7] = '1';
    fRec->shortName[8] = '.';
    fRec->shortName[9] = 'S';
    fRec->shortName[10] = 'F';
    fRec->shortName[11] = 'N';
    fRec->shortName[12] = 0;
  }

  if( fRec->name != NULL )
  {
    stl = strlen( fRec->name );
    neededSections = 2 + stl / 13;
    if( ( stl - ( stl / 13 ) * 13 ) == 0 ) neededSections--;
  }
  else
  {
    neededSections = 1;
  }
  seek( f, 0, OLD_SEEK_SET );
  currentSection = 0xffffffff;
  startOfNewRecord = 0xffffffff;
  while( FS_TRUE )
  {
    if( fdata->flowPosition == fdata->flowSize )
    {
      if( ( ( fdata->flowMode & FL_ROOT_DIR ) != 0 ) && ( ( ldInfo->fsType == FS_FAT12 ) || ( ldInfo->fsType == FS_FAT16 ) ) ) return FS_ER_NOT_ENOUGHT_FREE_SPACE;
      CSum = 0;
      if( ( res = write( f, &CSum, 1 ) ) != 0 ) return res;
      seek( f, -1, OLD_SEEK_CUR );
    }
    read( f, buf, 32 );
    currentSection++;
    if( ( buf[0] == 0x0000 ) || ( buf[0] == 0x00e5 ) || ( buf[0] == 0x0005 ) )
    {
      nk = 1; k = currentSection;
      while( FS_TRUE )
      {
        if( nk == neededSections ) break;
        if( fdata->flowPosition == fdata->flowSize )
        {
          if( ( ( fdata->flowMode & FL_ROOT_DIR ) != 0 ) && ( ( ldInfo->fsType == FS_FAT12 ) || ( ldInfo->fsType == FS_FAT16 ) ) ) return FS_ER_NOT_ENOUGHT_FREE_SPACE;
          CSum = 0;
          if( ( res = write( f, &CSum, 1 ) ) != 0 ) return res;
          seek( f, -1, OLD_SEEK_CUR );
        }
        read( f, buf, 32 );
        currentSection++;
        if( ( buf[0] == 0x0000 ) || ( buf[0] == 0x00e5 ) || ( buf[0] == 0x0005 ) ) nk++; else{ k = 0xffffffff; break; }
      }
      if( k != 0xffffffff )
      {
        startOfNewRecord = k;
        break;
      }
    }
    if( buf[11] == 0x000f )
    {
      nk = buf[0] - 0x0040;
      for( k = 0; k < nk; k++ )
      {
        read( f, buf, 32 );
        currentSection++;
      }
    }
  }

  seek( f, startOfNewRecord << 5, OLD_SEEK_SET );

  {
    FS_INT16 i, j, stl;
    InterfaceFileRec* fileRecord = (InterfaceFileRec*)buf;
    stl = strlen( fRec->shortName );
    for( i = 0; i < 8; i++ )
    {
      if( i >= stl ) { j = i; break; }
      if( fRec->shortName[i] == '.' ) { j = i + 1; break; }
      fileRecord->Name[i] = fRec->shortName[i];
    }
    if( i == 8 ) j = 9;
    for( i = j; i < ( j + 3 ); i++ )
    {
      if( i >= stl ) break;
      if( fRec->shortName[i] == 0 ) break;
      fileRecord->Ext[i-j] = fRec->shortName[i];
    }
    CSum = fileRecord->checkSum();
  }

  {
    InterfaceLFNRec* lfnRec = (InterfaceLFNRec*)buf;
    int noslfn = neededSections - 1;
    int i, j, addr, k, dk;

    if( fRec->name != NULL )
    {
      k = strlen( fRec->name );
      dk = k - ( k / 13 ) * 13;
      lfnRec->attr = 0x000f;
      lfnRec->LDIR_Type = 0x0000;
      lfnRec->LDIR_ChkSum = CSum;
      lfnRec->name2[6] = 0x0000;
      for( i = noslfn - 1; i >= 0; i-- )
      {
        lfnRec->number = i + 1;
        if( i == ( noslfn - 1 ) ) lfnRec->number += 0x0040;
        for( j = 0, addr = i * 13; j < 5; j++, addr++ )
        {
          if( ( dk != 0 ) && ( i == ( noslfn - 1 ) ) )
          {
            if( addr <= k ) lfnRec->name1[j] = cp1251_to_unicode( fRec->name[addr] );
            else lfnRec->name1[j] = 0xffff;
            continue;
          }
          if( addr < k ) lfnRec->name1[j] = cp1251_to_unicode( fRec->name[addr] );
          else lfnRec->name1[j] = 0xffff;
        }
        for( j = 0; j < 9; j++ )
        {
          if( j == 6 ) continue;
          if( ( dk != 0 ) && ( i == ( noslfn - 1 ) ) )
          {
            if( addr <= k ) lfnRec->name2[j] = cp1251_to_unicode( fRec->name[addr] );
            else lfnRec->name2[j] = 0xffff;
          }
          else
          {
            if( addr < k ) lfnRec->name2[j] = cp1251_to_unicode( fRec->name[addr] );
            else lfnRec->name2[j] = 0xffff;
          }
          addr++;
        }
        write( f, buf, 32 );
      }
    }

  }

  {
    int i, j, stl;
    InterfaceFileRec* fileRecord = (InterfaceFileRec*)buf;

    memset( buf, 0x20, 32 );
    fileRecord->Attr = fRec->attributes;
    fileRecord->FstClusLo = (FS_UINT16)( fRec->startCluster & 0x0000ffff );
    fileRecord->FstClusHi = (FS_UINT16)( fRec->startCluster >> 16 );
    fileRecord->CrtTime = fRec->tchms;
    fileRecord->CrtDate = fRec->tcymd;
    fileRecord->WrtTime = fRec->tmhms;
    fileRecord->WrtDate = fRec->tmymd;
    fileRecord->LstAccDate = 0;
    fileRecord->CrtTimeTenth = 0;
    fileRecord->FileSize = fRec->size;
    fileRecord->NTRes = 0;
    stl = strlen( fRec->shortName );
    for( i = 0; i < 8; i++ )
    {
      if( i >= stl ) { j = i; break; }
      if( fRec->shortName[i] == '.' ) { j = i + 1; break; }
      fileRecord->Name[i] = fRec->shortName[i];
    }
    if( i == 8 ) j = 9;
    for( i = j; i < ( j + 3 ); i++ )
    {
      if( i >= stl ) break;
      if( fRec->shortName[i] == 0 ) break;
      fileRecord->Ext[i-j] = fRec->shortName[i];
    }
    write( f, buf, 32 );
  }

  return FS_OK;
}
// ---------------------------------------------------------------------------
FS_BOOL Fat::checkFileRecord( FATFileRecord* fRec )
{
  FS_UINT16 i, stl;

  if( fRec->attributes != FAT_ATTR_LABLE )
  {
    if( fRec->name == NULL ) return FS_FALSE;
  }
  else
  {
    if( fRec->name == NULL ) return FS_TRUE;
    if( strlen( fRec->name ) != 11 ) return FS_FALSE;
  }
  if( fRec->shortName != NULL ) return FS_FALSE;

  if( fRec->name != NULL )
  {
    stl = strlen( fRec->name );
    for( i = 0; i < stl; i++ )
    {
      switch( fRec->name[i] )
      {
        case ':':
        case '/':
        case '\\':
        case '*':
        case '?':
        case '\"':
        case '|':
        case '>':
        case '<':
          return FS_FALSE;
      }
    }
  }

  return FS_TRUE;
}
// ---------------------------------------------------------------------------
FS_UINT16 Fat::size( File* f, FS_UINT32* flowSize )
{
  FATFileData* fdata = (FATFileData*)f->data;
  if( ( f == NULL ) || ( flowSize == NULL ) ) return FS_ER_NULL_POINTER;
  if( f->data == NULL ) return FS_ER_NULL_POINTER;
  (*flowSize) = fdata->flowSize;
  return FS_OK;
}
// ---------------------------------------------------------------------------
FS_UINT16 Fat::getCreateDate( File* f, FS_UINT32* data )
{
  FATFileData* fdata = (FATFileData*)f->data;
  if( ( f == NULL ) || ( data == NULL ) ) return FS_ER_NULL_POINTER;
  if( f->data == NULL ) return FS_ER_NULL_POINTER;
  fsUtils::timeDos2Unix( fdata->timeCreateYMD, fdata->timeCreateHMS, data );
  return FS_OK;
}
// ---------------------------------------------------------------------------
FS_UINT16 Fat::getLastModifyDate( File* f, FS_UINT32* data )
{
  FATFileData* fdata = (FATFileData*)f->data;
  if( ( f == NULL ) || ( data == NULL ) ) return FS_ER_NULL_POINTER;
  if( f->data == NULL ) return FS_ER_NULL_POINTER;
  fsUtils::timeDos2Unix( fdata->timeModifyYMD, fdata->timeModifyHMS, data );
  return FS_OK;
}
// ---------------------------------------------------------------------------
FS_UINT16 Fat::createObject( File* f, FS_CHAR* objName, FS_UINT32 attr )
{
  FATFileRecord fRec;
  FATFileData* fdata = (FATFileData*)f->data;
  FS_UINT16 HMS, YMD, res;
  FS_UINT32 parentStartCluster;

  fsUtils::timeUnix2Dos( time( NULL ), &YMD, &HMS );
  fRec.name = objName;
  fRec.attributes = attr;
  fRec.tchms = HMS;
  fRec.tcymd = YMD;
  fRec.tmhms = HMS;
  fRec.tmymd = YMD;
  if( ( res = open( f, FL_READ | FL_WRITE ) != 0 ) ) return res;
  res = writeFileRecord( f, &fRec );
  fRec.name = NULL;
  close( f );
  if( ( ( attr & FAT_ATTR_DIR ) != 0 ) && ( res == 0 ) )
  {
    FS_UINT8 buf[32];
    InterfaceFileRec* fileRecord = (InterfaceFileRec*)buf;

    parentStartCluster = fdata->startCluster;

    switchObjectTo( f, objName );
    open( f, FL_READ | FL_WRITE );
    memset( buf, 0, 32 );
    write( f, buf, 32 );
    seek( f, 0, OLD_SEEK_SET );

    memset( buf, 0x20, 11 );
    fileRecord->Name[0] = '.';
    fileRecord->Attr = 0x10;
    fileRecord->FstClusHi = (FS_UINT16)( fdata->startCluster >> 16 );
    fileRecord->FstClusLo = (FS_UINT16)( fdata->startCluster & 0x0000ffff );
    write( f, buf, 32 );

    fileRecord->Name[1] = '.';
    fileRecord->FstClusHi = (FS_UINT16)( parentStartCluster >> 16 );
    fileRecord->FstClusLo = (FS_UINT16)( parentStartCluster & 0x0000ffff );
    write( f, buf, 32 );

    close( f );
    res = switchObjectTo( f, const_fs_BackPointer );
  }

  return res;
}
// ---------------------------------------------------------------------------
FS_UINT16 Fat::removeObject( File* f, FS_CHAR* objName )
{
  FATFileData* fdata = (FATFileData*)f->data;
  FS_UINT16 res;
  FS_UINT32 startSection, endSection, startCluster;
  FS_INT32 i;
  FS_UINT8 rndBuf[64];

  if( ( f == NULL ) || ( objName == NULL ) ) return FS_ER_NULL_POINTER;
  if( f->data == NULL ) return FS_ER_NULL_POINTER;

  if( ( fdata->flowMode & 3 ) != 0 ) return FS_ER_FLOW_OPENED;
  if( ( res = switchObjectTo( f, objName ) ) != NULL ) return res;

  #ifdef VFAT_SECLEAN_PARTIAL
  if( fdata->flowSize != 0 )
  {
    if( ( res = open( f, FL_READ | FL_WRITE ) ) != res ) return res;
    for( i = 0; i < 16; i++ )
    {
      if( i == 0 )
      {
        if( fdata->attributes & FAT_ATTR_DIR )
        {
          seek( f, 64, OLD_SEEK_CUR );
          continue;
        }
      }
      fsUtils::rnd( rndBuf, 64 );
      if( ( res = write( f, rndBuf, 64 ) ) != 0 ) break;
    }
    close( f );
  }
  #endif

  startSection = fdata->dirStartSection;
  endSection = fdata->dirEndSection;
  startCluster = fdata->startCluster;

  if( ( res = switchObjectTo( f, const_fs_BackPointer ) ) != 0 ) return res;
  if( ( res = open( f, FL_READ | FL_WRITE ) ) != 0 ) return res;
  if( ( res = seek( f, startSection << 5, OLD_SEEK_SET ) ) != 0 )
  {
    close( f );
    return res;
  }
  rndBuf[0] = 0xe5;
  for( i = endSection - startSection; i >= 0; i-- )
  {
    if( ( res = write( f, rndBuf, 1 ) ) != 0 )
    {
      close( f );
      return res;
    }
    seek( f, 31, OLD_SEEK_CUR );
  }
  if( ( res = close( f ) ) != 0 ) return res;
  if( ( res = fatRemoveFrom( startCluster ) ) != 0 ) return res;

  return FS_OK;
}
// ---------------------------------------------------------------------------
FS_UINT16 Fat::mkfile( File* f, FS_CHAR* fileName )
{
  return createObject( f, fileName, 0x20 );
}
// ---------------------------------------------------------------------------
FS_UINT16 Fat::rmfile( File* f, FS_CHAR* fileName )
{
  FATFileData* fdata = (FATFileData*)f->data;
  FS_UINT32 tempAttr;
  FS_UINT16 res;
  if( ( f == NULL ) || ( fileName == NULL ) ) return FS_ER_NULL_POINTER;
  if( f->data == NULL ) return FS_ER_NULL_POINTER;
  if( ( res = switchObjectTo( f, fileName ) ) != 0 ) return res;
  tempAttr = fdata->attributes;
  if( ( res = switchObjectTo( f, const_fs_BackPointer ) ) != 0 ) return FS_WR_CANT_RETURN_TO_VALUE;
  if( ( tempAttr & FAT_ATTR_DIR ) != 0 ) return FS_ER_THIS_IS_NOT_FILE;
  return removeObject( f, fileName );
}
// ---------------------------------------------------------------------------
FS_UINT16 Fat::mkdir( File* f, FS_CHAR* dirName )
{
  return createObject( f, dirName, 0x10 );
}
// ---------------------------------------------------------------------------
FS_UINT16 Fat::removeObjectRecursive( File* f, FS_CHAR* objName )
{
  FATFileData* fdata = (FATFileData*)f->data;
  FATFileRecord fRec;
  FS_UINT16 res;

  if( ( res = switchObjectTo( f, objName ) ) != 0 ) return res;

  if( ( fdata->attributes & FAT_ATTR_DIR ) == FAT_ATTR_DIR )
  {
    fRec.eSection = 0xffffffff;
    while( FS_TRUE )
    {
      if( ( res = f->open( FL_READ ) ) != 0 ) return res;
      if( ( res = seek( f, ( fRec.eSection + 1 ) << 5, OLD_SEEK_SET ) ) != 0 ) return res;
      if( ( res = readFileRecord( f, &fRec ) ) != 0 )
      {
        FS_UINT16 res2;
        res2 = close( f );
        if( res == FS_WR_NOT_ENOUGHT_RECORDS )
        {
          if( res2 != 0 ) return res2;
          break;
        }
        return res2;
      }
      else
      {
        if( ( res = close( f ) ) != 0 ) return res;
      }
      if( fsUtils::upCaseCmp( fRec.name, const_fs_BackPointer ) || fsUtils::upCaseCmp( fRec.name, const_fs_SelfPointer ) ) continue;
      if( ( res = removeObjectRecursive( f, fRec.name ) ) != 0 ) return res;
    }
  }
  if( ( res = switchObjectTo( f, const_fs_BackPointer ) ) != 0 ) return res;

  return removeObject( f, objName );
}
// ---------------------------------------------------------------------------
FS_UINT16 Fat::rmdir( File* f, FS_CHAR* dirName )
{
  FATFileData* fdata = (FATFileData*)f->data;
  FS_UINT32 tempAttr;
  FS_UINT16 res;
  if( ( f == NULL ) || ( dirName == NULL ) ) return FS_ER_NULL_POINTER;
  if( f->data == NULL ) return FS_ER_NULL_POINTER;
  if( ( res = switchObjectTo( f, dirName ) ) != 0 ) return res;
  tempAttr = fdata->attributes;
  if( ( res = switchObjectTo( f, const_fs_BackPointer ) ) != 0 ) return FS_WR_CANT_RETURN_TO_VALUE;
  if( ( tempAttr & FAT_ATTR_DIR ) == 0 ) return FS_ER_THIS_IS_NOT_DIRRECTORY;
  return removeObjectRecursive( f, dirName );
}
// ---------------------------------------------------------------------------
FS_UINT16 Fat::trim( File* f, FS_UINT32 position )
{
  FS_UINT16 res;
  FS_UINT32 clrCounter, bigBlock, i, oldMode;
  FATFileData* fdata = (FATFileData*)f->data;
  FS_UINT32 curClus, nextClus, endVal, oldPosition;
  FS_BOOL needClearFat = FS_TRUE;
  FS_UINT8 buf[32];

  if( f == NULL ) return FS_ER_NULL_POINTER;
  if( f->data == NULL ) return FS_ER_NULL_POINTER;
  if( fdata->flowSize == position ) return FS_OK;
  if( fdata->flowSize = position ) return FS_WR_FLOW_TOO_SHORT;
  oldMode = fdata->flowMode & 3;
  if( oldMode == 0 )
  {
    if( ( res = open( f, FL_READ | FL_WRITE ) ) != 0 ) return res;
    oldPosition = 0;
  }
  else
  {
    fdata->flowMode |= FL_READ | FL_WRITE;
    tell( f, &oldPosition );
  }
  if( ( res = seek( f, position, OLD_SEEK_SET ) ) != 0 )
  {
    if( oldMode == 0 ) close( f ); else { seek( f, oldPosition, OLD_SEEK_SET ); fdata->flowMode = ( fdata->flowMode & 0xfffc ) | oldMode; }
    return res;
  }
  clrCounter = fdata->flowSize - position;
  bigBlock = clrCounter >> 5;
  for( i = 0; i < bigBlock; i++ )
  {
    fsUtils::rnd( buf, 32 );
    if( ( res = write( f, buf, 32 ) ) != 0 )
    {
      if( oldMode == 0 ) close( f ); else { seek( f, oldPosition, OLD_SEEK_SET ); fdata->flowMode = ( fdata->flowMode & 0xfffc ) | oldMode; }
      return res;
    }
  }
  clrCounter &= 0x1f;
  if( clrCounter != 0 )
  {
    fsUtils::rnd( buf, clrCounter );
    if( ( res = write( f, buf, clrCounter ) ) != 0 )
    {
      if( oldMode == 0 ) close( f ); else { seek( f, oldPosition, OLD_SEEK_SET ); fdata->flowMode = ( fdata->flowMode & 0xfffc ) | oldMode; }
      return res;
    }
  }
  if( ( res = seek( f, position, OLD_SEEK_SET ) ) != 0 )
  {
    if( oldMode == 0 ) close( f ); else { seek( f, oldPosition, OLD_SEEK_SET ); fdata->flowMode = ( fdata->flowMode & 0xfffc ) | oldMode; }
    return res;
  }
  curClus = fdata->currentCluster;
  if( ( res = fatGetRecValue( curClus, &nextClus ) ) != 0 )
  {
    if( oldMode == 0 ) close( f ); else { seek( f, oldPosition, OLD_SEEK_SET ); fdata->flowMode = ( fdata->flowMode & 0xfffc ) | oldMode; }
    return res;
  }
  switch( ldInfo->fsType )
  {
    case FS_FAT12: endVal = 0x00000ff8; break;
    case FS_FAT16: endVal = 0x0000fff8; break;
    case FS_FAT32: endVal = 0x0ffffff8; break;
  }
  if( nextClus >= endVal ) needClearFat = FS_FALSE;
  if( ( res = fatSetRecValue( curClus, endVal ) ) != 0 )
  {
    if( oldMode == 0 ) close( f ); else { seek( f, oldPosition, OLD_SEEK_SET); fdata->flowMode = ( fdata->flowMode & 0xfffc ) | oldMode; }
    return res;
  }
  if( needClearFat ) if ( ( res = fatRemoveFrom( nextClus ) ) != 0 )
  {
    if( oldMode == 0 ) close( f ); else { seek( f, oldPosition, OLD_SEEK_SET ); fdata->flowMode = ( fdata->flowMode & 0xfffc ) | oldMode; }
    return res;
  }
  fdata->flowSize = position;
  if( oldMode == 0 )
  {
    if( ( res = close( f ) ) != 0 ) return res;
  }
  else
  {
    seek( f, oldPosition, OLD_SEEK_SET );
    fdata->flowMode = ( fdata->flowMode & 0xfffc ) | oldMode;
  }

  return FS_OK;
}
// ---------------------------------------------------------------------------
FS_UINT16 Fat::fatFindFirstFreeCluster( FS_UINT32 fromCluster )
{
  FS_UINT32 i,clv;
  FS_UINT16 res;
  ldInfo->firstFreeCluster = 0xffffffff;
  for( i = fromCluster; i < ( ldInfo->totalClusters + 2 ); i++ )
  {
    if( ( res = fatGetRecValue( i, &clv ) ) != 0 ) return res;
    if( clv == 0 )
    {
      ldInfo->firstFreeCluster = i;
      return FS_OK;
    }
  }
  ldInfo->firstFreeCluster = 0;
  return FS_ER_NOT_ENOUGHT_FREE_SPACE;
}
// ---------------------------------------------------------------------------
FS_UINT16 Fat::getFreeSpaceInBytes( FS_UINT32* freeBytes )
{
  FS_UINT32 i,clv;
  FS_UINT16 res;

  FS_LOCK0();

  if( ldInfo->freeClusters == 0xffffffff )
  {
    ldInfo->freeClusters = 0;
    for( i = 2; i < ( ldInfo->totalClusters + 2 ); i++ )
    {
      if( ( res = fatGetRecValue( i, &clv ) ) != 0 )
      {
        (*freeBytes) = 0xffffffff;
        ldInfo->freeClusters = 0xffffffff;
        FS_UNLOCK0();
        return res;
      }
      if( clv == 0 ) ldInfo->freeClusters++;
    }
  }
  (*freeBytes) = ldInfo->freeClusters * ldInfo->sectorsPerCluster;
  (*freeBytes) <<= 9;

  FS_UNLOCK0();

  return FS_OK;
}
// ---------------------------------------------------------------------------
FS_UINT16 Fat::getSize( FS_UINT32* size )
{
  (*size) = ldInfo->lbaSize << 9;
  return FS_OK;
}
// ---------------------------------------------------------------------------
FS_UINT32 Fat::getRWCounter( File* f )
{
  return ((FATFileData*)f->data)->rwCounter;
}
// ---------------------------------------------------------------------------
FS_UINT16 Fat::writeLable( File* f, FS_CHAR* lable )
{
  FATFileRecord fRec;
  FATFileData* fdata = (FATFileData*)f->data;
  FS_UINT16 res;
  FS_CHAR buf[12];
  if( fdata == NULL ) return FS_ER_NULL_POINTER;
  memset( buf, ' ', 11 ); buf[11] = 0;
  if( lable != NULL )
  {
    for( FS_INT32 i = 0; ; i++ )
    {
      if( ( lable[i] == 0 ) || ( i == 11 ) ) break;
      buf[i] = fsUtils::upCase( lable[i] );
    }
  }
  fRec.name = buf;
  fRec.attributes = FAT_ATTR_LABLE;
  res = writeFileRecord( f, &fRec );
  fRec.name = NULL;
  return res;
}
// ---------------------------------------------------------------------------
FS_UINT16 Fat::rename( File* f, FS_CHAR* newPath )
{
  FS_UINT16 res;
  FATFileData* fdata = (FATFileData*)f->data;
  FATFileRecord fRec;

  if( fdata == NULL ) return FS_ER_NULL_POINTER;
  if( newPath == NULL ) return FS_ER_NULL_POINTER;

  if( ( fdata->flowMode & 3 ) != 0 ) return FS_ER_FLOW_OPENED;
  if( fsMonitor::checkOpened( f ) ) return FS_ER_FLOW_OPENED;

  if( strcmp( myMountPoint->name, f->data->getPath() ) == 0 ) return FS_ER_BAD_SRC_PATH;
  if( memcmp( myMountPoint->name, newPath, strlen( myMountPoint->name ) ) != 0 ) return FS_ER_BAD_DST_PATH;

  FS_UINT16 cnt = get_object_count( newPath );

  File* nf = new File();
  if( nf == NULL ) return FS_ER_CANT_ALLOCATE_MEMORY;

  if( fs_goto( nf, newPath, cnt ) == 0 )
  {
    delete nf;
    return FS_ER_FILE_EXISTS;
  }
  delete nf;

  nf = new File();
  if( nf == NULL ) return FS_ER_CANT_ALLOCATE_MEMORY;

  if( fs_goto( nf, newPath, cnt - 1 ) != 0 )
  {
    delete nf;
    return FS_ER_PATH_NOT_FOUND;
  }
  if( ( res = nf->open( FL_READ | FL_WRITE ) ) != 0 )
  {
    delete nf;
    return res;
  }

  FS_INT16 ps,pe;
  get_object_name_boundary( newPath, cnt - 1, &ps, &pe );

  fRec.name = (FS_CHAR*)fs_alloc( strlen( newPath + ps ) + 1 ); // new FS_CHAR[strlen(newPath+ps)+1];
  if( fRec.name == NULL )
  {
    delete nf;
    return FS_ER_CANT_ALLOCATE_MEMORY;
  }
  strcpy( fRec.name, newPath + ps );
  fRec.tcymd = fdata->timeCreateYMD;
  fRec.tchms = fdata->timeCreateHMS;
  fRec.tmymd = fdata->timeModifyYMD;
  fRec.tmhms = fdata->timeModifyHMS;
  fRec.size = fdata->flowSize;
  fRec.startCluster = fdata->startCluster;
  fRec.attributes = fdata->attributes;

  if( ( res = writeFileRecord( nf, &fRec ) ) !=0 )
  {
    delete nf;
    return res;
  }

  nf->close();
  delete nf;

  FS_INT32 dirStartSection = fdata->dirStartSection;
  FS_INT32 dirEndSection = fdata->dirEndSection;

  if( ( res = switchObjectTo( f, const_fs_BackPointer ) ) != 0 ) return res;
  
  FS_UINT8 buf[32];
  fsUtils::rnd( buf, 32 );
  buf[0] = 0xe5;
  open( f, FL_READ | FL_WRITE );
  seek( f, dirStartSection << 5, OLD_SEEK_SET );
  for( FS_INT32 i = dirStartSection; i <= dirEndSection; i++ )
  {
    write( f, buf, 32 );
  }
  close( f );

  return FS_OK;
}
// ---------------------------------------------------------------------------
FS_UINT16 Fat::cflush( File* f )
{
  FS_LOCK0();
  FS_LOCK1();
  for( FS_UINT16 i = 0; i < FAT_CASH_SIZE; i++ )
  {
    fatCash[i].sector = 0xffffffff;
    fatCash[i].usage = 0;
  }
  FS_UNLOCK1();
  FS_UNLOCK0();
  return FS_OK;
}
// ---------------------------------------------------------------------------
FS_UINT16 Fat::fsType()
{
  if( ldInfo == NULL ) return FS_NO;
  return ldInfo->fsType;
}
// ---------------------------------------------------------------------------
FS_UINT16 Fat::stUsbDev(FS_ST_USBDEV* d)
{
  if( ldInfo == NULL ) return FS_NO;
  if( ldInfo->dev == NULL ) return FS_NO;
  d->lport = ldInfo->dev->devParentPort;
  d->lunit = ldInfo->dev->devLun;
  return FS_OK;
}
// ---------------------------------------------------------------------------
