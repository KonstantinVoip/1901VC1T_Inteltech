#include <__fs.h>
#include <drv_usbms.h>
#include <rts.h>
// ---------------------------------------------------------------------------
class APPL_TRIGGER
{
  public:

    class PIPE_TRIGGER
    {
      public:

      FS_INT32 iParentPort;
      uint32 pipe_rid;

      PIPE_TRIGGER()
      {
        iParentPort = -1;
        pipe_rid = RES_VOID;
      }

      ~PIPE_TRIGGER()
      {
        drv_rmd( pipe_rid );
      }

      void clear()
      {
	    if(pipe_rid != NULL) drv_rmd( pipe_rid );
        pipe_rid = RES_VOID;
        iParentPort = -1;
      }
      //Reset class variables:
      void reset()
      {
	    if(pipe_rid != NULL) drv_rmd( pipe_rid );      
        pipe_rid = RES_VOID;
        iParentPort = -1;
      }      

    }
    Pipe[3];

    bool inited;

    APPL_TRIGGER()
    {
      inited = false;
    }

    ~APPL_TRIGGER()
    {
      /* Nothing */
    }

    int32 getParentPort( uint32 d )
    {
      char* lodev_name = NULL;
      if( drv_ioctl( d, MSD_DEVICE_NAME, &lodev_name ) != OSE_OK ) return -1;
      if( lodev_name == NULL ) return -1;
      if( memcmp( lodev_name, "msd1", 4 ) != 0 ) return -1;
      if( strlen( lodev_name ) != 5 ) return -1;
      return (int32)( lodev_name[4] - '1' );
    }

    FS_INT32 EnumUsbDev( void* b )
    {
      char tname[64];
      int32 pnum;
      uint32 d = drv_mkd( "/dev" );
      uint32 tdev;

      for( int32 i = 0; i < 3; i++ ) Pipe[i].clear();

      if( d == RES_VOID )
        return -1;

      s_inode* l;

      if( drv_list( d, &l ) != OSE_OK )
      {
        drv_rmd( d );
        return -2;
      }

      s_inode* cl = l;
      while( cl )
      {
        if( memcmp( cl->name, "sd", 2 ) == 0 )
        {
          strcpy( tname, "/dev/" );
          strcat( tname, cl->name );
          tdev = drv_mkd( tname );
          res_share( tdev );
          if( tdev != RES_VOID )
          {
            pnum = getParentPort( tdev );
            if( ( pnum >= 0 ) && ( pnum <= 2 ) )
            {
              Pipe[pnum].pipe_rid = tdev;
              Pipe[pnum].iParentPort = pnum;
            }
            else
            {
              drv_rmd( tdev );
            }
          }
        }
        cl = cl->next;
      }

      drv_list_destroy( l );
      drv_rmd( d );

      return 0;
    }
    
    void EnumeratePrimaryDisk( void* b )
    {
      for( int32 i = 0; i < 3; i++ )
      {
        if( Pipe[i].pipe_rid == RES_VOID ) continue;
        dev.add( i, 0, 0 );
      }
    }

    FS_INT32 UFI_Read_Capacity( FS_UINT16 n, FS_UINT16 l, long* size, long* sector_size )
    {
      s_msd_capacity d;
      if( size ) (*size) = 0;
      if( sector_size ) (*sector_size) = 0;
      if( n > 3 ) return -1;
      if( drv_ioctl( Pipe[n].pipe_rid, MSD_CAPACITY, &d ) != OSE_OK ) return -1;
      if( size ) (*size) = (long)d.last_lba;
      if( sector_size ) (*sector_size) = (long)d.block_length;
      return 0;
    }

    FS_INT32 CheckMedium( FS_UINT16 n, FS_UINT16 l )
    {
      s_msd_capacity d;
      if( n > 3 ) return 1;
	  if(Pipe[n].pipe_rid == NULL) return 4;
      if( drv_ioctl( Pipe[n].pipe_rid, MSD_CAPACITY, &d ) != OSE_OK ) return 4;
      return 0;
    }

    FS_INT32 ReadSectorFromUSB( FS_UINT32 lba, void* buf, FS_UINT32 count, FS_UINT16 n, FS_UINT16 l )
    {
      s_msd_io data;
      data.data = buf;
      data.lba = lba;
      data.size = count;
      if( n > 3 ) return -1;
      if( drv_ioctl( Pipe[n].pipe_rid, MSD_READ, &data ) != OSE_OK ) return -1;
      return 0;
    }

    FS_INT32 WriteSectorToUSB( FS_UINT32 lba, void* buf, FS_UINT32 count, FS_UINT16 n, FS_UINT16 l )
    {
      s_msd_io data;
      data.data = buf;
      data.lba = lba;
      data.size = count;
      if( n > 3 ) return -1;
      if( drv_ioctl( Pipe[n].pipe_rid, MSD_WRITE, &data ) != OSE_OK ) return -1;
      return 0;
    }

}
Appl;

// ---------------------------------------------------------------------------

Device dev( DEV_MAX_DEVICES );
LogicDisk logicDisk( DEV_MAX_LOGIC_DISKS );

// ---------------------------------------------------------------------------
DeviceInfo::DeviceInfo()
{
  devNum = 0xffff;
  devParentPort = 0;
  devLun = 0;
  devSize = 0;
  flags = 0;
}
// ---------------------------------------------------------------------------
void DeviceInfo::setFlag( FS_UINT16 mask )
{
  flags |= mask;
}
// ---------------------------------------------------------------------------
void DeviceInfo::clrFlag( FS_UINT16 mask )
{
  flags &= mask ^ 0xffff;
}
// ---------------------------------------------------------------------------
FS_BOOL DeviceInfo::chkFlag( FS_UINT16 mask )
{
  return (FS_BOOL)( ( flags & mask ) == mask );
}
// ---------------------------------------------------------------------------
FS_UINT16 DeviceInfo::detectMBR()
{
  FS_UINT16 i, noc, noa, addr, res;

  clrFlag( DEV_FL_HAVE_MBR | DEV_FL_HAVE_BOOT_SECTOR );

  if( chkFlag( DEV_FL_FLOPPY ) )
  {
    setFlag( DEV_FL_HAVE_BOOT_SECTOR );
    return DEV_ER_NO;
  }

  if( ( res = dev.readSector( this, NULL, 0, 1 ) ) != 0 ) return res;

  res = fsDetectByBootSector( &i, FS_TRUE );
  if( res == DEV_ER_NO )
  {
    setFlag( DEV_FL_HAVE_BOOT_SECTOR );
    return DEV_ER_NO;
  }

  for( noa = 0, noc = 0, i = 0; i < 4; i++ )
  {
    addr = ( i << 4 ) + 0x01be;
    if( dev.sbuf[addr] == 0x00 )
    {
      noc++;
      continue;
    }
    if( dev.sbuf[addr] == 0x80 )
    {
      noc++; noa++;
      continue;
    }
  }

  if( noc == 4 )
  {
    setFlag( DEV_FL_HAVE_MBR );
    return DEV_ER_NO;
  }

  setFlag( DEV_FL_HAVE_BOOT_SECTOR );

  return DEV_ER_NO;
}
// ---------------------------------------------------------------------------
FS_UINT16 DeviceInfo::readMBR( FS_UINT32 sectorNumber )
{
  MBRLogicalDiskInfo *mbrRec;
  FS_UINT16 addr, res, fsType;

  dev.readSector( this, NULL, sectorNumber, 1 );

  for( addr = 0x01be; addr < 0x01fe; addr += 16 )
  {
    mbrRec = (MBRLogicalDiskInfo*)( dev.sbuf + addr );
    if( ( mbrRec->type == 0x05 ) || ( mbrRec->type == 0x0f ) )
    {
      if( ( res = readMBR( mbrRec->lbaStart ) ) != 0 ) return res;
      dev.readSector( this, NULL, sectorNumber, 1 );
      continue;
    }
    if( ( fsType = fsDetect( mbrRec->type ) ) != FS_NO )
    {
      if( ( res = readBootSector( mbrRec->lbaStart, mbrRec->lbaSize, fsType ) ) != 0 ) return res;
      dev.readSector( this, NULL, sectorNumber, 1 );
    }
  }

  return DEV_ER_NO;
}
// ---------------------------------------------------------------------------
FS_UINT16 DeviceInfo::fsDetect( FS_UINT16 mbrRecType )
{
  switch( mbrRecType )
  {
    // FAT32
    case 0x000b:
    case 0x000c:
    case 0x001c:
      return FS_FAT32;

    // FAT16
    case 0x0006:
    case 0x000e:
    case 0x001e:
      return FS_FAT16;
    
    // FAT12
    case 0x0001:
    case 0x0011:
      return FS_FAT12;
  }

  return FS_NO;
}
// ---------------------------------------------------------------------------
FS_UINT16 DeviceInfo::fsDetectByBootSector( FS_UINT16* fsType, FS_BOOL dnud )
{
  Fat16Info* fat16info;
  Fat32Info* fat32info;
  BootSectorBPB* bpb;

  dev.readSector( this, NULL, 0, 1 );

  bpb = (BootSectorBPB*)( ::dev.sbuf );
  fat16info = (Fat16Info*)( ::dev.sbuf + 36 );
  fat32info = (Fat32Info*)( ::dev.sbuf + 36 );

  (*fsType) = FS_NO;

  // Test for FAT12 / FAT16
  if( ( fat16info->BS_FilSysType[0] == 'F' ) && ( fat16info->BS_FilSysType[1] == 'A' ) &&
      ( fat16info->BS_FilSysType[2] == 'T' ) && ( fat16info->BS_FilSysType[3] == '1' ) )
  {
    if( fat16info->BS_FilSysType[4] == '2' )
    {
      (*fsType) = FS_FAT12;
      return DEV_ER_NO;
    }
    if( fat16info->BS_FilSysType[4] == '6' )
    {
      (*fsType) = FS_FAT16;
      return DEV_ER_NO;
    }
  }

  // Test for FAT32
  if( ( fat32info->BS_FilSysType[0] == 'F' ) && ( fat32info->BS_FilSysType[1] == 'A' ) &&
      ( fat32info->BS_FilSysType[2] == 'T' ) && ( fat32info->BS_FilSysType[3] == '3' ) &&
      ( fat32info->BS_FilSysType[4] == '2' ) )
  {
    (*fsType) = FS_FAT32;
    return DEV_ER_NO;
  }

  // Heuristic test for FAT16 / FAT32
  if( !dnud )
  {
    if( bpb->BPB_RootEntCnt == 0 )
    {
      if( fat32info->BPB_RootClus != 0 )
      {
        (*fsType) = FS_FAT32;
        return DEV_ER_NO;
      }
    }
    else
    {
      (*fsType) = FS_FAT16;
      return DEV_ER_NO;
    }
  }

  return DEV_WR_UNKNOW_FS_TYPE;
}
// ---------------------------------------------------------------------------
FS_UINT16 DeviceInfo::readBootSector( FS_UINT32 sectorNumber, FS_UINT32 size, FS_UINT16 fsType )
{
  FS_UINT16 ldIndex, res;

  if( chkFlag( DEV_FL_LETTER_ASSIGNED ) )
  {
    for( res = 0; res < dev.pLetterSelectorCount; res++ )
    {
      if( !dev.pLetterSelector[res].used ) continue;
      if( dev.pLetterSelector[res].port == devParentPort )
      {
        if( ( dev.pLetterSelector[res].logic_unit == Device::Auto ) || ( dev.pLetterSelector[res].logic_unit == devLun ) )
        {
          ldIndex = logicDisk.getFreeIndex( dev.pLetterSelector[res].midx, dev.pLetterSelector[res].midxw, dev.pLetterSelector[res].midx2 );
          break;
        }
      }
    }
  }
  else
  {
    ldIndex = logicDisk.getFreeIndex( LogicDisk::Auto, LogicDisk::Auto, LogicDisk::Auto );
  }

  if( size == 0xffffffff ) size = devSize;
  if( ( res = logicDisk.add( ldIndex, this, sectorNumber, size, fsType ) ) != 0 ) return res;

  return DEV_ER_NO;
}
// ---------------------------------------------------------------------------
FS_UINT16 DeviceInfo::reInit()
{
  FS_UINT16 res;
  FS_UINT16 fsType;

  if( ( res = detectMBR() ) != 0 ) return res;

  if( chkFlag( DEV_FL_HAVE_MBR ) )
  {
    if( ( res = readMBR( 0 ) ) != 0 ) return res;
  }
  else if( chkFlag( DEV_FL_HAVE_BOOT_SECTOR ) )
  {
    if( ( res = fsDetectByBootSector( &fsType ) ) != 0 ) return res;
    if( ( res = readBootSector( 0, devSize, fsType ) ) != 0 ) return res;
  }
  else
  {
    return DEV_WR_CANT_DETECT_MBR_OR_BOOT_SECTOR;
  }

  return DEV_ER_NO;
}
// ---------------------------------------------------------------------------

const FS_UINT16 Device::Auto = 0xffff;

// ---------------------------------------------------------------------------
Device::Device( FS_UINT16 iNumOfDevices )
{
  FS_INT32 i;

  numOfDevices = 0;
  usbDeviceReconnect = FS_FALSE;

  devInfo = (DeviceInfo**)fs_alloc( sizeof(DeviceInfo*) * iNumOfDevices ); // new DeviceInfo*[iNumOfDevices];
  if( devInfo == NULL )
  {
    // Critical error
    while( FS_TRUE );
  }
  for( numOfDevices = iNumOfDevices, i = 0; i < numOfDevices; i++ ) devInfo[i] = NULL;

  pLetterSelectorCount = iNumOfDevices;
  pLetterSelector = (DeviceLetterSelector*)fs_alloc( sizeof(DeviceLetterSelector) * pLetterSelectorCount ); // new DeviceLetterSelector[pLetterSelectorCount];
  if( devInfo == NULL )
  {
    // Critical error
    while( FS_TRUE );
  }
  memset( pLetterSelector, 0, sizeof(DeviceLetterSelector) * pLetterSelectorCount );

  FS_LOCK_INIT();
}
// ---------------------------------------------------------------------------
Device::~Device()
{
  fs_free( devInfo );
  fs_free( pLetterSelector );
}
// ---------------------------------------------------------------------------
FS_UINT16 Device::reInitLoLevel()
{
  FS_UINT16 i;

  for( i = 0; i < numOfDevices; i++ ) if( devInfo[i] != NULL ) devInfo[i]->clrFlag( DEV_FL_PRESENT );
  
  #ifdef __TMS320C55X__
  if( Appl.EnumUsbDev( (unsigned short*)sbuf ) ) return DEV_ER_USB_CONTROLLER;
  Appl.EnumeratePrimaryDisk( (unsigned short*)sbuf );
  #else
  if( Appl.EnumUsbDev( (unsigned char*)sbuf ) ) return DEV_ER_USB_CONTROLLER;
  Appl.EnumeratePrimaryDisk( (unsigned char*)sbuf );
  #endif
  
  for( i = 0; i < numOfDevices; i++ ) if( devInfo[i] != NULL ) if( !devInfo[i]->chkFlag( DEV_FL_PRESENT ) ) del( i );

  return DEV_ER_NO;
}
// ---------------------------------------------------------------------------
FS_UINT16 Device::reInit()
{
  FS_UINT16 res;
  if( ( res = reInitLoLevel() ) != 0 ) return res;
  return reInitLogicDisks();
}
// ---------------------------------------------------------------------------
FS_UINT16 Device::resetApplPipe( FS_UINT16 ldChar )
{
  LogicDiskInfo* ldi;
  if( logicDisk.getInfo( fsUtils::upCase( ldChar ) - 'A', &ldi ) != 0 ) return DEV_ER_BAD_INDEX;
  if( ldi->dev->devNum>=3 ) return DEV_ER_BAD_INDEX;
  Appl.Pipe[ldi->dev->devNum].reset();
  return DEV_ER_NO;
}
// ---------------------------------------------------------------------------
FS_UINT16 Device::resetAllApplPipe()
{
  for(FS_UINT16 i=0; i<3; i++) Appl.Pipe[i].reset();
  return DEV_ER_NO;
}
// ---------------------------------------------------------------------------
FS_UINT16 Device::reInitLogicDisks( FS_UINT16 ldChar )
{
  FS_INT16 i;
  long devSize, sectorSize;
  FS_UINT16 res;
  FS_INT16 startDev = 0;
  FS_INT16 endDev = numOfDevices - 1;
  LogicDiskInfo* ldi;

  if( usbDeviceReconnect )
  {
    if( ( res = reInitLoLevel() ) != 0 ) return res;
    usbDeviceReconnect = false;
  }

  if( ldChar != 0xffff )
  {
    if( logicDisk.getInfo( fsUtils::upCase( ldChar ) - 'A', &ldi ) == 0 )
    {
      startDev = getDevIndex( ldi->dev->devNum, ldi->dev->devLun );
      if( startDev == 0xffff ) startDev = 0; else endDev = startDev;
    }
    else
    {
      if( ( res = reInitLoLevel() ) != 0 ) return res;
    }
  }

again_reinit:

  for( i = startDev; i <= endDev; i++ )
  {
    if( devInfo[i] != NULL )
    {
      res = drivePresent( i );
      if( res != 0 )
      {
        if( ( res == 4 ) || ( res == 2 ) )
        {
          if( ( res = reInitLoLevel() ) != 0 ) return res;
          startDev = 0; endDev = numOfDevices - 1;
          goto again_reinit;
        }
        else
        {
          logicDisk.removeByDev( devInfo[i] );
          devInfo[i]->devSize = 0;
        }
        continue;
      }

      if( Appl.UFI_Read_Capacity( devInfo[i]->devNum, devInfo[i]->devLun, &devSize, &sectorSize ) != 0 ) return DEV_ER_GET_DEV_SIZE;
      if( sectorSize != 512 )continue;
      devSize++;

      if( ( devInfo[i]->devSize != devSize ) || ( ( devInfo[i]->flags & DEV_FL_USB_NEED_REINIT ) != 0 ) )
      {
        devInfo[i]->flags &= DEV_FL_USB_NEED_REINIT ^ 0xffff;
        logicDisk.removeByDev( devInfo[i] );
        devInfo[i]->devSize = devSize;
        res = devInfo[i]->reInit();
        switch( res )
        {
          case 0:
          case DEV_WR_CANT_DETECT_MBR_OR_BOOT_SECTOR: break;
          default: return res;
        }
        continue;
      }

      switch( logicDisk.checkPartitionData( devInfo[i] ) )
      {
        case DEV_ER_LD_CHECK_OK: break;

        case DEV_ER_LD_CHECK_FAIL:
        {
          logicDisk.removeByDev( devInfo[i] );
          res = devInfo[i]->reInit();
          switch( res )
          {
            case 0:
            case DEV_WR_CANT_DETECT_MBR_OR_BOOT_SECTOR:
            case DEV_WR_UNKNOW_FS_TYPE: break;
            default: return res;
          }
        }
        break;
        
        default: return res;
      }

    }
  }

  return DEV_ER_NO;
}
// ---------------------------------------------------------------------------
FS_UINT16 Device::add( FS_INT16 num, FS_INT16 lun, FS_UINT16 setFlags )
{
  FS_UINT16 devIndex, res;
  long devSize, sectorSize;
  DeviceInfo* newDev;

  if( ( devIndex = getDevIndex( num, lun ) ) != 0xffff )
  {
    devInfo[devIndex]->setFlag( DEV_FL_PRESENT );
    devInfo[devIndex]->devParentPort = Appl.Pipe[num].iParentPort;
    checkForAssignation( devInfo[devIndex] );
    return DEV_ER_NO;
  }

  if( ( devIndex = getFreeIndex() ) == 0xffff ) return DEV_ER_NO_FREE_SLOT;

  res = Appl.CheckMedium( num, lun );
  if( res == 2 ) return DEV_ER_CHECK_MEDIUM_CMD;
  if( res == 0 )
  {
    if( Appl.UFI_Read_Capacity( num, lun, &devSize, &sectorSize ) != 0 ) return DEV_ER_GET_DEV_SIZE;
    if( sectorSize != 512 ) return DEV_ER_BAD_SECTOR_SIZE;
  }
  else
  {
    devSize = 0xffffffff;
  }
  newDev = new DeviceInfo();
  if( newDev == NULL ) return DEV_ER_NO_FREE_MEM;
  newDev->devNum = num;
  newDev->devParentPort = Appl.Pipe[num].iParentPort;
  newDev->devLun = lun;
  newDev->devSize = devSize + 1;
  newDev->setFlag( setFlags | DEV_FL_PRESENT );
  checkForAssignation( newDev );
  devInfo[devIndex] = newDev;

  return DEV_ER_NO;
}
// ---------------------------------------------------------------------------
FS_UINT16 Device::del( FS_UINT16 devIndex )
{
  if( devIndex >= numOfDevices ) return DEV_ER_BAD_INDEX;
  if( devInfo[devIndex] == NULL ) return DEV_ER_NULL_SLOT;
  logicDisk.removeByDev( devInfo[devIndex] );
  delete devInfo[devIndex];
  devInfo[devIndex] = NULL;
  return DEV_ER_NO;
}
// ---------------------------------------------------------------------------
FS_UINT16 Device::checkForAssignation( DeviceInfo* di )
{
  FS_INT32 i;

  for( i = 0; i < pLetterSelectorCount; i++ )
  {
    if( !pLetterSelector[i].used ) continue;
    if( pLetterSelector[i].port == di->devParentPort )
    {
      if( ( pLetterSelector[i].logic_unit == Device::Auto ) || ( pLetterSelector[i].logic_unit == di->devLun ) )
      {
        di->setFlag( DEV_FL_LETTER_ASSIGNED );
        pLetterSelector[i].hlport = di->devNum;
        pLetterSelector[i].hlunit = di->devLun;
      }
    }
  }

  return DEV_ER_NO;
}
// ---------------------------------------------------------------------------
FS_UINT16 Device::assignLetter( FS_ST_USBDEV& pudev, FS_UINT16 midx, FS_UINT16 midxw, FS_UINT16 midx2 )
{
  FS_INT32 i;

  for( i = 0; i < pLetterSelectorCount; i++ )
  {
    if( !pLetterSelector[i].used )
    {
      pLetterSelector[i].used = FS_TRUE;
      pLetterSelector[i].port = pudev.lport;
      pLetterSelector[i].logic_unit = pudev.lunit;
      pLetterSelector[i].midx = midx;
      pLetterSelector[i].midxw = midxw;
      pLetterSelector[i].midx2 = midx2;
      pLetterSelector[i].hlport = 0xffff;
      pLetterSelector[i].hlunit = 0xffff;
      return DEV_ER_NO;
    }
  }

  return DEV_ER_NO_FREE_SLOT;
}
// ---------------------------------------------------------------------------
FS_UINT16 Device::drivePresent( FS_UINT16 devIndex )
{
  if( devInfo[devIndex] == NULL ) return 0xffff;
  return Appl.CheckMedium( devInfo[devIndex]->devNum, devInfo[devIndex]->devLun );
}
// ---------------------------------------------------------------------------
FS_UINT16 Device::getDevIndex( FS_UINT16 devNum, FS_UINT16 devLun )
{
  FS_INT16 i;
  FS_UINT16 res = 0xffff;

  for( i = 0; i < numOfDevices; i++ )
  {
    if( devInfo[i] != NULL )
    {
      if( ( devInfo[i]->devNum == devNum ) && ( devInfo[i]->devLun == devLun ) )
      {
        res = i;
        break;
      }
    }
  }

  return res;
}
// ---------------------------------------------------------------------------
FS_UINT16 Device::getDevIndexByDevType( FS_UINT16 devType )
{
  FS_INT16 i;
  FS_UINT16 res = 0xffff;

  for( i = 0; i < numOfDevices; i++ )
  {
    if( devInfo[i] != NULL )
    {
      if( ( devInfo[i]->flags & devType ) == devType )
      {
        res = i;
        break;
      }
    }
  }

  return res;
}
// ---------------------------------------------------------------------------
FS_UINT16 Device::getDevIndexByUsbDev( FS_ST_USBDEV& pudev )
{
  for( FS_INT16 i = 0; i < pLetterSelectorCount; i++ )
  {
    if( ( pLetterSelector[i].port == pudev.lport ) && ( pLetterSelector[i].logic_unit == pudev.lunit ) )
    {
      return getDevIndex( pLetterSelector[i].hlport, pLetterSelector[i].hlunit );
    }
  }
  return 0xffff;
}
// ---------------------------------------------------------------------------
FS_UINT16 Device::getFreeIndex()
{
  FS_UINT16 i, res = 0xffff;
  for( i = 0; i < numOfDevices; i++ ) if( devInfo[i] == NULL ) { res = i; break; }
  return res;
}
// ---------------------------------------------------------------------------
FS_UINT16 Device::readSector( FS_UINT16 devIndex, void* buf, FS_UINT32 sectorNumber, FS_UINT32 sectorCount )
{
  FS_UINT16 res;

  if( devIndex >= numOfDevices ) return DEV_ER_BAD_INDEX;
  if( devInfo[devIndex] == NULL ) return DEV_ER_NULL_SLOT;

  if( buf == NULL )
  {
    if( sectorCount != 1 ) return DEV_ER_TOO_MANY_SECTORS;
    #ifdef __TMS320C55X__
    res = Appl.ReadSectorFromUSB( sectorNumber, (unsigned short*)sbuf, sectorCount, devInfo[devIndex]->devNum, devInfo[devIndex]->devLun );
    #else
    res = Appl.ReadSectorFromUSB( sectorNumber, (unsigned char*)sbuf, sectorCount, devInfo[devIndex]->devNum, devInfo[devIndex]->devLun );
    #endif
  }
  else
  {
    #ifdef __TMS320C55X__
    res = Appl.ReadSectorFromUSB( sectorNumber, (unsigned short*)buf, sectorCount, devInfo[devIndex]->devNum, devInfo[devIndex]->devLun );
    #else
    res = Appl.ReadSectorFromUSB( sectorNumber, (unsigned char*)buf, sectorCount, devInfo[devIndex]->devNum, devInfo[devIndex]->devLun );
    #endif
  }
  
  if( usbDeviceReconnect )
  {
    devInfo[devIndex]->flags |= DEV_FL_USB_NEED_REINIT;
    usbDeviceReconnect = FS_FALSE;
  }
  
  if( ( res == USB_DEVICE_RECEIVE_IS_LESS_BYTES ) && ( sectorCount > 1 ) ) return DEV_WARN_NEED_TO_SHRINK_PORTION;
  if( res != 0 ) return DEV_ER_READ_SECTOR;

  return DEV_ER_NO;
}
// ---------------------------------------------------------------------------
FS_UINT16 Device::readSector( DeviceInfo* devInf, void* buf, FS_UINT32 sectorNumber, FS_UINT32 sectorCount )
{
  FS_UINT16 res;

  if( devInf == NULL ) return DEV_ER_NULL_SLOT;

  if( buf == NULL )
  {
    if( sectorCount != 1 ) return DEV_ER_TOO_MANY_SECTORS;
    #ifdef __TMS320C55X__
    res = Appl.ReadSectorFromUSB( sectorNumber, (unsigned short*)sbuf, sectorCount, devInf->devNum, devInf->devLun );
    #else
    res = Appl.ReadSectorFromUSB( sectorNumber, (unsigned char*)sbuf, sectorCount, devInf->devNum, devInf->devLun );
    #endif
  }
  else
  {
    #ifdef __TMS320C55X__
    res = Appl.ReadSectorFromUSB( sectorNumber, (unsigned short*)buf, sectorCount, devInf->devNum, devInf->devLun );
    #else
    res = Appl.ReadSectorFromUSB( sectorNumber, (unsigned char*)buf, sectorCount, devInf->devNum, devInf->devLun );
    #endif
  }

  if( usbDeviceReconnect )
  {
    devInf->flags |= DEV_FL_USB_NEED_REINIT;
    usbDeviceReconnect = FS_FALSE;
  }

  if( ( res == USB_DEVICE_RECEIVE_IS_LESS_BYTES ) && ( sectorCount > 1 ) ) return DEV_WARN_NEED_TO_SHRINK_PORTION;
  if( res != 0 ) return DEV_ER_READ_SECTOR;

  return DEV_ER_NO;
}
// ---------------------------------------------------------------------------
FS_UINT16 Device::writeSector( FS_UINT16 devIndex, void* buf, FS_UINT32 sectorNumber, FS_UINT32 sectorCount )
{
  FS_UINT16 res;

  if( devIndex >= numOfDevices ) return DEV_ER_BAD_INDEX;
  if( devInfo[devIndex] == NULL ) return DEV_ER_NULL_SLOT;

  if( buf == NULL )
  {
    if( sectorCount != 1 ) return DEV_ER_TOO_MANY_SECTORS;
    #ifdef __TMS320C55X__
    res = Appl.WriteSectorToUSB( sectorNumber, (unsigned short*)sbuf, sectorCount, devInfo[devIndex]->devNum, devInfo[devIndex]->devLun );
    #else
    res = Appl.WriteSectorToUSB( sectorNumber, (unsigned char*)sbuf, sectorCount, devInfo[devIndex]->devNum, devInfo[devIndex]->devLun );
    #endif
  }
  else
  {
    #ifdef __TMS320C55X__
    res = Appl.WriteSectorToUSB( sectorNumber, (unsigned short*)buf, sectorCount, devInfo[devIndex]->devNum, devInfo[devIndex]->devLun );
    #else
    res = Appl.WriteSectorToUSB( sectorNumber, (unsigned char*)buf, sectorCount, devInfo[devIndex]->devNum, devInfo[devIndex]->devLun );
    #endif
  }
  
  if( usbDeviceReconnect )
  {
    devInfo[devIndex]->flags |= DEV_FL_USB_NEED_REINIT;
    usbDeviceReconnect = FS_FALSE;
  }
  if( res != 0 ) return DEV_ER_WRITE_SECTOR;

  return DEV_ER_NO;
}
// ---------------------------------------------------------------------------
FS_UINT16 Device::writeSector( DeviceInfo* devInf, void* buf, FS_UINT32 sectorNumber, FS_UINT32 sectorCount )
{
  FS_UINT16 res;

  if( devInf == NULL ) return DEV_ER_NULL_SLOT;

  if( buf == NULL )
  {
    if( sectorCount != 1 ) return DEV_ER_TOO_MANY_SECTORS;
    #ifdef __TMS320C55X__
    res = Appl.WriteSectorToUSB( sectorNumber, (unsigned short*)sbuf, sectorCount, devInf->devNum, devInf->devLun );
    #else
    res = Appl.WriteSectorToUSB( sectorNumber, (unsigned char*)sbuf, sectorCount, devInf->devNum, devInf->devLun );
    #endif
  }
  else
  {
    #ifdef __TMS320C55X__
    res = Appl.WriteSectorToUSB( sectorNumber, (unsigned short*)buf, sectorCount, devInf->devNum, devInf->devLun );
    #else
    res = Appl.WriteSectorToUSB( sectorNumber, (unsigned char*)buf, sectorCount, devInf->devNum, devInf->devLun );
    #endif
  }
  
  if( usbDeviceReconnect )
  {
    devInf->flags |= DEV_FL_USB_NEED_REINIT;
    usbDeviceReconnect = FS_FALSE;
  }
  if( res != 0 ) return DEV_ER_WRITE_SECTOR;

  return DEV_ER_NO;
}
// ---------------------------------------------------------------------------
FS_UINT32 Device::calcCheckSum()
{
  FS_UINT32 crc32;
  FS_UINT16 i,j;
  FS_UINT32 hiBit;

  for( crc32 = 0, i = 0; i < 512; i++ )
  {
    crc32 ^= (FS_UINT32)sbuf[i] << 24;
    for( j = 0; j < 8; j++ )
    {
      hiBit = crc32 & 0x80000000;
      crc32 <<= 1;
      if( hiBit ) crc32 ^= 0x04c11db7;
    }
  }

  return crc32;
}
// ---------------------------------------------------------------------------
FS_UINT16 Device::getInfoStructure( FS_UINT16 devIndex, DeviceInfo** di )
{
  if( devIndex >= numOfDevices ) return DEV_ER_BAD_INDEX;
  if( devInfo[devIndex] == NULL ) return DEV_ER_NULL_SLOT;
  *di = devInfo[devIndex];
  return DEV_ER_NO;
}
// ---------------------------------------------------------------------------
LogicDiskInfo::LogicDiskInfo( DeviceInfo* iDevInfo )
{
  fsType = 0;
  lbaStart = 0;
  lbaSize = 0;
  fatStart = 0;
  fatSize = 0;
  rootDirStart = 0;
  rootDirCluster = 0;
  rootDirSectors = 0;
  firstDataSector = 0;
  sectorsPerCluster = 0;
  dataSectors = 0;
  lable = NULL;
  bootSectorCheckSum = 0;
  totalClusters = 0;
  freeClusters = 0xffffffff;
  firstFreeCluster = 0xffffffff;
  dev = iDevInfo;
}
// ---------------------------------------------------------------------------
LogicDiskInfo::~LogicDiskInfo()
{
  fs_free( lable );
}
// ---------------------------------------------------------------------------
FS_UINT16 LogicDiskInfo::init( FS_UINT32 iLbaStart, FS_UINT32 iLbaSize, FS_UINT16 iFsType )
{
  FS_UINT16 res;
  lbaStart = iLbaStart;
  lbaSize = iLbaSize;
  fsType = iFsType;
  if( ( res = read() ) != 0 )return res;
  return DEV_ER_NO;
}
// ---------------------------------------------------------------------------
FS_UINT16 LogicDiskInfo::read()
{
  FS_UINT16 res;
  BootSectorBPB *bootRec;
  Fat16Info *fat16i;
  Fat32Info *fat32i;

  if( ( res = ::dev.readSector( dev, NULL, lbaStart, 1 ) ) != 0 ) return res;

  bootRec = (BootSectorBPB*)::dev.sbuf;
  fat16i = (Fat16Info*)( ::dev.sbuf + 36 );
  fat32i = (Fat32Info*)( ::dev.sbuf + 36 );

  sectorsPerCluster = bootRec->BPB_SecPerClus;
  fatStart = lbaStart + bootRec->BPB_RsvdSecCnt;
  rootDirSectors = ( ( bootRec->BPB_RootEntCnt << 5 ) + bootRec->BPB_BytsPerSec - 1 ) / bootRec->BPB_BytsPerSec;

  if( fsType == FS_FAT32 )
  {
    fatSize = fat32i->BPB_FATSz32;
    rootDirCluster = fat32i->BPB_RootClus;
  }
  else
  {
    fatSize = bootRec->BPB_FATSz16;
    rootDirCluster = 0;
  }

  firstDataSector = lbaStart + bootRec->BPB_RsvdSecCnt + rootDirSectors + bootRec->BPB_NumFATs * fatSize;

  if( fsType == FS_FAT32 )
  {
    rootDirStart = firstSectorOfCluster( fat32i->BPB_RootClus );
  }
  else
  {
    rootDirStart = firstDataSector - rootDirSectors;
  }
  dataSectors = lbaSize - ( bootRec->BPB_RsvdSecCnt + rootDirSectors + bootRec->BPB_NumFATs * fatSize );
  totalClusters = dataSectors / sectorsPerCluster;
  bootSectorCheckSum = ::dev.calcCheckSum();

  lable = (FS_CHAR*)fs_alloc( 12 ); // new FS_CHAR[12];
  if( lable != NULL )
  {
    switch( fsType )
    {
      case FS_FAT12:
      case FS_FAT16:
        for( res = 0; res < 11; res++ ) lable[res] = fat16i->BS_VolLab[res];
      break;
      case FS_FAT32:
        for( res = 0; res < 11; res++ ) lable[res] = fat32i->BS_VolLab[res];
      break;
    }
    lable[11] = 0;
  }

  return DEV_ER_NO;
}
// ---------------------------------------------------------------------------
FS_UINT16 LogicDiskInfo::check()
{
  FS_UINT16 res;
  FS_UINT32 curCrc32;
  if( ( res = ::dev.readSector( dev, NULL, lbaStart, 1 ) ) != 0 ) return res;
  curCrc32 = ::dev.calcCheckSum();
  if( curCrc32 != bootSectorCheckSum ) return DEV_ER_LD_CHECK_FAIL;
  return DEV_ER_LD_CHECK_OK;
}
// ---------------------------------------------------------------------------
FS_UINT32 LogicDiskInfo::firstSectorOfCluster( FS_UINT32 clusterNumber )
{
  if( clusterNumber == 0 ) return 0;
  return ( clusterNumber - 2 ) * sectorsPerCluster + firstDataSector;
}
// ---------------------------------------------------------------------------

const FS_UINT16 LogicDisk::Auto = 0xffff;

// ---------------------------------------------------------------------------
LogicDisk::LogicDisk( FS_UINT16 iNumOfLogicDisks )
{
  FS_INT32 i;
  numOfLogicDisks = 0;
  logicDiskInfo = (LogicDiskInfo**)fs_alloc( sizeof(LogicDiskInfo*) * iNumOfLogicDisks ); // new LogicDiskInfo*[iNumOfLogicDisks];
  if( logicDiskInfo == NULL )
  {
    // Critical error
    while( FS_TRUE );
  }
  numOfLogicDisks = iNumOfLogicDisks;
  for( i = 0; i < numOfLogicDisks; i++ ) logicDiskInfo[i] = NULL;
}
// ---------------------------------------------------------------------------
LogicDisk::~LogicDisk()
{
  for( FS_UINT16 i = 0; i < numOfLogicDisks; i++ ) if( logicDiskInfo[i] != NULL ) delete logicDiskInfo[i];
  fs_free( logicDiskInfo );
}
// ---------------------------------------------------------------------------
FS_UINT16 LogicDisk::getFreeIndex( FS_UINT16 minIndex, FS_UINT16 numOfIndexes, FS_UINT16 minIndex2 )
{
  FS_UINT16 res = 0xffff;
  FS_UINT16 tIdx, i;

  if( minIndex == LogicDisk::Auto )
  {
    minIndex = 0;
    for( i = 0; i < dev.pLetterSelectorCount; i++ )
    {
      if( ( dev.pLetterSelector[i].midx + dev.pLetterSelector[i].midxw ) > minIndex )
      {
        minIndex = dev.pLetterSelector[i].midx + dev.pLetterSelector[i].midxw;
      }
      if( dev.pLetterSelector[i].midx2 > minIndex )
      {
        minIndex = dev.pLetterSelector[i].midx2;
      }
    }
  }
  if( numOfIndexes == LogicDisk::Auto ) numOfIndexes = numOfLogicDisks - minIndex;
  if( minIndex2 == LogicDisk::Auto ) minIndex2 = minIndex;

  tIdx = minIndex + numOfIndexes;
  if( tIdx > numOfLogicDisks ) tIdx = numOfLogicDisks;
  for( i = minIndex; i < tIdx; i++ ) if( logicDiskInfo[i] == NULL ) { res = i; break; }
  if(res!=0xffff)return res;
  for( i = minIndex2; i < numOfLogicDisks; i++ ) if( logicDiskInfo[i] == NULL ) { res = i; break; }

  return res;
}
// ---------------------------------------------------------------------------
FS_UINT16 LogicDisk::getInfo( FS_UINT16 ldIndex, LogicDiskInfo** infoPtr )
{
  if( ldIndex >= numOfLogicDisks ) return DEV_ER_BAD_LD_INDEX;
  if( logicDiskInfo[ldIndex] == NULL ) return DEV_ER_NULL_LD_SLOT;
  *infoPtr = logicDiskInfo[ldIndex];
  return DEV_ER_NO;
}
// ---------------------------------------------------------------------------
FS_UINT16 LogicDisk::add( FS_UINT16 ldIndex, DeviceInfo* iDevInfo, FS_UINT32 lbaStart, FS_UINT32 lbaSize, FS_UINT16 fsType )
{
  LogicDiskInfo* newLd;
  FS_UINT16 res;

  if( ldIndex >= numOfLogicDisks ) return DEV_ER_BAD_LD_INDEX;
  if( logicDiskInfo[ldIndex] != NULL ) return DEV_ER_BAD_LD_INDEX_BUSY;
  newLd = new LogicDiskInfo( iDevInfo );
  if( newLd == NULL ) return DEV_ER_NO_FREE_MEM;
  if( ( res = newLd->init( lbaStart, lbaSize, fsType ) ) != 0 )
  {
    delete newLd;
    return res;
  }
  logicDiskInfo[ldIndex] = newLd;
  mount( 'a' + ldIndex );

  return DEV_ER_NO;
}
// ---------------------------------------------------------------------------
FS_UINT16 LogicDisk::del( FS_UINT16 ldIndex )
{
  if( ldIndex >= numOfLogicDisks ) return DEV_ER_BAD_LD_INDEX;
  if( logicDiskInfo[ldIndex] == NULL ) return DEV_ER_NULL_LD_SLOT;
  delete logicDiskInfo[ldIndex];
  logicDiskInfo[ldIndex] = NULL;
  umount( 'a' + ldIndex );
  return DEV_ER_NO;
}
// ---------------------------------------------------------------------------
FS_UINT16 LogicDisk::removeByDev( DeviceInfo* iDevInfo )
{
  FS_UINT16 i;
  for( i = 0; i < numOfLogicDisks; i++ )
  {
    if( logicDiskInfo[i] != NULL )
    {
      if( logicDiskInfo[i]->dev == iDevInfo ) del( i );
    }
  }
  return DEV_ER_NO;
}
// ---------------------------------------------------------------------------
FS_UINT16 LogicDisk::checkPartitionData( DeviceInfo* iDevInfo )
{
  FS_UINT16 i,res;
  if( getNumOfPartitions( iDevInfo ) == 0 ) return DEV_ER_LD_CHECK_FAIL;
  for( i = 0; i < numOfLogicDisks; i++ )
  {
    if( logicDiskInfo[i]->dev == iDevInfo )
    {
      res = logicDiskInfo[i]->check();
      if( res != DEV_ER_LD_CHECK_OK ) return res;
    }
  }
  return DEV_ER_LD_CHECK_OK;
}
// ---------------------------------------------------------------------------
FS_UINT16 LogicDisk::getNumOfPartitions( DeviceInfo* iDevInfo )
{
  FS_UINT16 i,res;
  for( res = 0, i = 0; i < numOfLogicDisks; i++ )
  {
    if( logicDiskInfo[i]->dev == iDevInfo ) res++;
  }
  return res;
}
// ---------------------------------------------------------------------------

