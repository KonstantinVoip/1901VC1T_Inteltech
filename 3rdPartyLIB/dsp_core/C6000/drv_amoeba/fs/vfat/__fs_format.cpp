#include <__fs.h>
#include <rts.h>
// ---------------------------------------------------------------------------
FS_UINT16 FormatFlash( FS_ST_USBDEV& pudev, void (*cbfunc)( FS_UINT32, FS_UINT32, void* ), void* arg )
{
  FS_INT32 i;
  FS_UINT16 res, devIndex;
  DeviceInfo* devInfo;
  FS_UINT32 ta, tb, spc, fatSize, partitionLength;
  BootSectorBPB* bsBpb = (BootSectorBPB*)dev.sbuf;
  Fat32Info* fat32Info = (Fat32Info*)( dev.sbuf + 36 );
  MBRLogicalDiskInfo* mbrRec;

  char LocBuf[512];

  // Get device info structure
  devIndex = dev.getDevIndexByUsbDev( pudev );
  if( devIndex == 0xffff ) return DEV_ER_BAD_INDEX;
  if( ( res = dev.getInfoStructure( devIndex, &devInfo ) ) != 0 ) return res;
  // Form partition size
  partitionLength = devInfo->devSize - 32;

  // Unmount all logic disks
  umount_all();

  FS_LOCK();
  // -- Form MBR --------------------------------------------------------------
  if( ( res = dev.readSector( devInfo, LocBuf, 0, 1 ) ) != 0 ) { FS_UNLOCK(); return res; }
  memset( LocBuf, 0, 512 );
  // Bootable code
  LocBuf[0] = 0xeb; // jmp $
  LocBuf[1] = 0xfe;
  LocBuf[2] = 0x90; // nop
  LocBuf[3] = 0x90; // nop
  // End of sector
  LocBuf[510] = 0x55;
  LocBuf[511] = 0xaa;
  // Record for first partition
  mbrRec = (MBRLogicalDiskInfo*)( LocBuf + 0x1be );
  mbrRec->actived = 0x80;
  mbrRec->type = 0x1c;
  mbrRec->lbaStart = 32;
  mbrRec->lbaSize = partitionLength;
  // Write MBR to disk
  if( ( res = dev.writeSector( devInfo, LocBuf, 0, 1 ) ) != 0 ) { FS_UNLOCK(); return res; }
  // -- Form MBR --------------------------------------------------------------

  // -- Form Boot Sector ------------------------------------------------------
  // Determine cluster size
  spc = 0;
  if( devInfo->devSize < 0x7fffffff ) spc = 64;
  if( devInfo->devSize < 67108864 ) spc = 32;
  if( devInfo->devSize < 33554432 ) spc = 16;
  if( devInfo->devSize < 16777216 ) spc = 8;
  if( devInfo->devSize < 66600 ) spc = 0;
  // Flash too small for FAT32
  if( spc == 0 ) { FS_UNLOCK(); return DEV_ER_BAD_DEVICE_SIZE; }
  // Calculate FAT size
  ta = partitionLength - 32 + 2 * spc;
  tb = 128 * spc + 2;
  fatSize = ta / tb;
  if( fsUtils::fsMod( ta, tb ) != 0 ) fatSize++;
  // Callback
  if( cbfunc ) cbfunc( 0, fatSize, arg );
  // Prepare boot sector data
  memset( LocBuf, 0, 512 );
  LocBuf[510] = 0x55;
  LocBuf[511] = 0xaa;
  bsBpb->BS_JmpBoot[0] = 0xeb;
  bsBpb->BS_JmpBoot[1] = 0xfe;
  bsBpb->BS_JmpBoot[2] = 0x90;
  for( i = 0; i < 8; i++ ) bsBpb->BS_OEMName[i]  = '_';
  bsBpb->BPB_BytsPerSec = 512;
  bsBpb->BPB_NumFATs = 2;
  bsBpb->BPB_Media = 0x00f8;
  bsBpb->BPB_NumHeads = 0x00ff;
  bsBpb->BPB_SecPerTrk = 0x003f;
  bsBpb->BPB_HiddSec = 0;
  bsBpb->BPB_SecPerClus = spc;
  bsBpb->BPB_RsvdSecCnt = 32;
  bsBpb->BPB_RootEntCnt = 0;
  bsBpb->BPB_TotSec16 = 0;
  bsBpb->BPB_FATSz16 = 0;
  bsBpb->BPB_TotSec32 = partitionLength;
  fat32Info->BS_VolLab[0] = 'F';
  fat32Info->BS_VolLab[1] = 'L';
  fat32Info->BS_VolLab[2] = 'A';
  fat32Info->BS_VolLab[3] = 'S';
  fat32Info->BS_VolLab[4] = 'H';
  fat32Info->BS_VolLab[5] = 'K';
  fat32Info->BS_VolLab[6] = 'A';
  fat32Info->BS_VolLab[7] = ' ';
  fat32Info->BS_VolLab[8] = ' ';
  fat32Info->BS_VolLab[9] = ' ';
  fat32Info->BS_VolLab[10] = ' ';
  fat32Info->BPB_BkBootSec = 0x0006;
  fat32Info->BPB_ExtFlags = 0x0000;
  fat32Info->BPB_FATSz32 = fatSize;
  fat32Info->BPB_FSInfo = 0x0001;
  fat32Info->BPB_FSVer = 0x0000;
  fat32Info->BPB_RootClus = 0x00000002;
  fat32Info->BS_BootSig = 0x0029;
  fat32Info->BS_VolID = time( NULL );
  fat32Info->BS_FilSysType[0] = 'F';
  fat32Info->BS_FilSysType[1] = 'A';
  fat32Info->BS_FilSysType[2] = 'T';
  fat32Info->BS_FilSysType[3] = '3';
  fat32Info->BS_FilSysType[4] = '2';
  fat32Info->BS_FilSysType[5] = ' ';
  fat32Info->BS_FilSysType[6] = ' ';
  fat32Info->BS_FilSysType[7] = ' ';
  for( i = 0; i < 12; i++ ) fat32Info->Reserved[i] = 0;
  // Write reserv copy of boot sector
  if( ( res = dev.writeSector( devInfo, LocBuf, 32 + fat32Info->BPB_BkBootSec, 1 ) ) != 0 ) goto l_exit;
  // Write main copy of boot sector
  if( ( res = dev.writeSector( devInfo, LocBuf, 32, 1 ) ) != 0 ) goto l_exit;
  // -- Form Boot Sector ------------------------------------------------------

  // -- Form FAT table --------------------------------------------------------
  memset( LocBuf, 0, 512 );
  // Zero record in FAT
  LocBuf[0] = 0x00f8;
  LocBuf[1] = 0x00ff;
  LocBuf[2] = 0x00ff;
  LocBuf[3] = 0x000f;
  // First record FAT (Flags)
  LocBuf[4] = 0x00ff;
  LocBuf[5] = 0x00ff;
  LocBuf[6] = 0x00ff;
  LocBuf[7] = 0x00ff;
  // Finish of the root directory
  LocBuf[8] = 0x00f8;
  LocBuf[9] = 0x00ff;
  LocBuf[10] = 0x00ff;
  LocBuf[11] = 0x000f;
  // Make two copy of FAT
  if( ( res = dev.writeSector( devInfo, LocBuf, 64, 1 ) ) != 0 ) goto l_exit;
  if( ( res = dev.writeSector( devInfo, LocBuf, 64 + fatSize, 1 ) ) != 0 ) goto l_exit;
  memset( LocBuf, 0, 512 );
  for( i = 1; i < fatSize; i++ )
  {
    // Callback
    if( cbfunc && !( i & 31 ) ) cbfunc( i, fatSize, arg );
    if( ( res = dev.writeSector( devInfo, LocBuf, 64 + i, 1 ) ) != 0 ) goto l_exit;
    if( ( res = dev.writeSector( devInfo, LocBuf, 64 + i + fatSize, 1 ) ) != 0 ) goto l_exit;
  }
  // -- Form FAT table --------------------------------------------------------

  // -- Form Root directory ---------------------------------------------------
  for( i = 0; i < spc; i++ )
  {
    if( ( res = dev.writeSector( devInfo, LocBuf, 64 + ( fatSize << 1 ) + i, 1 ) ) != 0 ) goto l_exit;
  }
  // -- Form Root directory ---------------------------------------------------

  res = 0;
  cbfunc( fatSize, fatSize, arg );
  
l_exit:

  FS_UNLOCK();
  mount_all();

  return res;
}
// ---------------------------------------------------------------------------

