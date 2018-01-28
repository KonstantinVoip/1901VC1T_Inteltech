#ifndef __FS_H__
#define __FS_H__

#ifndef __FS_Defines_H__
#define __FS_Defines_H__

#include <stddef.h>
#include <os.h>

#define USB_DEVICE_RECEIVE_IS_LESS_BYTES        1234

// == Types ==================================================================
#define FS_CHAR char
#define FS_UINT8 unsigned char
#define FS_INT8 signed char
#define FS_UINT16 unsigned short int
#define FS_INT16 signed short int
#define FS_UINT32 unsigned int
#define FS_INT32 signed int
#define FS_BOOL bool
#define FS_FALSE false
#define FS_TRUE true

class FS_UINT16UP
{
  private:

    FS_UINT8            al;
    FS_UINT8            ah;

  public:

    FS_UINT16UP() { al = 0; ah = 0; }

    FS_UINT16UP( FS_UINT16UP& n ) { al = n.al; ah = n.ah; }

    FS_UINT16UP( FS_UINT16 n )
    {
      al = n & 0x00ff;
      ah = ( n >> 8 ) & 0x00ff;
    }

    void operator =( FS_UINT16UP& n ) { al = n.al; ah = n.ah; }
  
    void operator =( FS_UINT16 n )
    {
      al = n & 0x00ff;
      ah = ( n >> 8 ) & 0x00ff;
    }
  
    operator FS_UINT16() { return al + ( ah << 8 ); }

    void* operator new( size_t s ) { return heap_alloc( NULL, s, HEAP_ALIGN_4 ); }
    void operator delete( void* ptr ) { heap_free( NULL, ptr ); }

};

class FS_UINT32UP
{
  private:

    FS_UINT16UP         al;
    FS_UINT16UP         ah;

  public:

    FS_UINT32UP() { al = 0; ah = 0; }

    FS_UINT32UP( FS_UINT32UP& n ) { al = n.al; ah = n.ah; }

    FS_UINT32UP( FS_UINT32 n )
    {
      al = n & 0x0000ffff;
      ah = ( n >> 16 ) & 0x0000ffff;
    }

    void operator =( FS_UINT32UP& n ) { al = n.al; ah = n.ah; }

    void operator =( FS_UINT32 n )
    {
      al = n & 0x0000ffff;
      ah = ( n >> 16 ) & 0x0000ffff;
    }
  
    operator FS_UINT32() { return (FS_UINT32)al + ( (FS_UINT32)ah << 16 ); }

    void* operator new( size_t s ) { return heap_alloc( NULL, s, HEAP_ALIGN_4 ); }
    void operator delete( void* ptr ) { heap_free( NULL, ptr ); }

};

class FS_PCHAR
{
  private:

    FS_CHAR*            ptr;

  public:

    FS_PCHAR() { ptr = NULL; }

    FS_PCHAR( const FS_PCHAR& pc ) { ptr = pc.ptr; }

    FS_PCHAR( FS_CHAR* iptr ) { ptr = iptr; }

    ~FS_PCHAR() { heap_free( NULL, ptr ); }

    void operator =( FS_CHAR* iptr )
    {
      heap_free( NULL, ptr );
      ptr = iptr;
    }

    operator FS_CHAR*() { return ptr; }

    void* operator new( size_t s ) { return heap_alloc( NULL, s, HEAP_ALIGN_4 ); }
    void operator delete( void* ptr ) { heap_free( NULL, ptr ); }

};

// == File systems types =====================================================
#define FS_NO                                   0x0000
#define FS_FAT12                                0x0001
#define FS_FAT16                                0x0002
#define FS_FAT32                                0x0003
#define FS_ROOTFS                               0x0004
// == Error codes ============================================================
#define DEV_ER_NO                               0x0000
#define DEV_ER_NO_FREE_MEM                      0xffff
#define DEV_ER_USB_CONTROLLER                   0xfffe
#define DEV_ER_READ_SECTOR                      0xfffd
#define DEV_ER_WRITE_SECTOR                     0xfffc
#define DEV_ER_NULL_SLOT                        0xfffb
#define DEV_ER_BAD_INDEX                        0xfffa
#define DEV_ER_NO_FREE_SLOT                     0xfff9
#define DEV_ER_GET_DEV_SIZE                     0xfff8
#define DEV_ER_BAD_SECTOR_SIZE                  0xfff7
#define DEV_ER_BAD_LD_INDEX                     0xfff6
#define DEV_ER_BAD_LD_INDEX_BUSY                0xfff5
#define DEV_ER_LD_CHECK_OK                      0xfff4
#define DEV_ER_LD_CHECK_FAIL                    0xfff3
#define DEV_ER_CHECK_MEDIUM_CMD                 0xfff2
#define DEV_ER_NULL_LD_SLOT                     0xfff1
#define DEV_WR_CANT_DETECT_MBR_OR_BOOT_SECTOR   0xfff0
#define DEV_ER_BAD_FS_TYPE                      0xffef
#define DEV_WR_UNKNOW_FS_TYPE                   0xffee
#define DEV_ER_CANT_GET_KEY                     0xffed
#define DEV_ER_IMIT_MISMATCH                    0xffec
#define DEV_ER_DEVICE_TOO_SHORT                 0xffeb
#define DEV_ER_WRONG_FS                         0xffea
#define DEV_ER_CANT_START_TRANSACTION           0xffe9
#define DEV_WR_CANT_END_TRANSACTION             0xffe8
#define DEV_ER_BAD_DEVICE_SIZE                  0xffe7
#define DEV_ER_TOO_MANY_SECTORS                 0xffe6
#define DEV_WARN_NEED_TO_SHRINK_PORTION         0xffe5

#define FS_OK                                   0x0000
#define FS_ER                                   0x7fff
#define FS_ER_FUNC_NOT_ASSIGNED                 0x0001
#define FS_ER_CANT_DELETE_MOUNT_POINT           0x0002
#define FS_ER_RFS_REC_EXISTS                    0x0003
#define FS_ER_RFS_REC_NOT_EXISTS                0x0004
#define FS_ER_CANT_ALLOCATE_MEMORY              0x0005
#define FS_ER_NULL_POINTER                      0x0006
#define FS_ER_OBJECT_NOT_FOUND                  0x0007
#define FS_WR_RFS_WAS_CHANGED                   0x0008
#define FS_ER_BAD_MOUNT_POINT                   0x0009
#define FS_ER_BAD_LD_LETTER                     0x000a
#define FS_ER_ALLREADY_MOUNTED                  0x000b
#define FS_ER_NOT_MOUNTED                       0x000c
#define FS_ER_ITS_NOT_MOUNT_POINT               0x000d

#define FS_ER_FAT_NOT_FREE_SPACE                0x0100
#define FS_ER_FAT_ZERO_RECORD                   0x0101
#define FS_ER_NOT_ENOUGHT_FREE_SPACE            0x0102
#define FS_ER_FAT_CRASHED                       0x0103
#define FS_ER_CANT_READ_FROM_FILE               0x0104
#define FS_ER_CANT_WRITE_TO_FILE                0x0105
#define FS_WR_FLOW_TOO_SHORT                    0x0106
#define FS_ER_FLOW_NOT_OPENED                   0x0107
#define FS_ER_THIS_IS_NOT_DIRRECTORY            0x0108
#define FS_ER_FAT_EOF                           0x0109
#define FS_ER_CRITICAL                          0x010a
#define FS_ER_FILE_NOT_EXISTS                   0x010b
#define FS_WR_NOT_ENOUGHT_RECORDS               0x010c
#define FS_ER_FLOW_OPENED                       0x010d
#define FS_ER_PDIRINFO_STRUCT_CREATED           0x010e
#define FS_ER_PDIRINFO_STRUCT_NOT_CREATED       0x010f
#define FS_ER_BAD_FILE_RECORD_DATA              0x0110
#define FS_ER_FILE_EXISTS                       0x0111
#define FS_WR_CANT_RETURN_TO_VALUE              0x0112
#define FS_ER_THIS_IS_NOT_FILE                  0x0113
#define FS_ER_BAD_CLUSTER_VALUE                 0x0114
#define FS_ER_THIS_NOT_ROOT_DIR                 0x0115
#define FS_ER_BAD_DST_PATH                      0x0116
#define FS_ER_PATH_NOT_FOUND                    0x0117
#define FS_ER_BAD_SRC_PATH                      0x0118

// == Device flags ===========================================================
#define DEV_FL_HAVE_MBR                         0x0001
#define DEV_FL_HAVE_BOOT_SECTOR                 0x0002
#define DEV_FL_PRESENT                          0x0004
#define DEV_FL_FLOPPY                           0x0008
#define DEV_FL_INTER_FLASH                      0x0010
#define DEV_FL_EXTER_FLASH                      0x0020
#define DEV_FL_MEMORY_STICK                     0x0040
#define DEV_FL_COMPACT_FLASH                    0x0080
#define DEV_FL_SD_MMC                           0x0100
#define DEV_FL_SM                               0x0200
#define DEV_FL_LETTER_ASSIGNED                  0x0400
#define DEV_FL_USB_NEED_REINIT                  0x8000

// == Device arrays configuration ============================================
#define DEV_MAX_DEVICES                         4
#define DEV_MAX_LOGIC_DISKS                     8

// == FAT constatnts =========================================================
#define FAT_ATTR_READONLY                       0x0001
#define FAT_ATTR_HIDDEN                         0x0002
#define FAT_ATTR_SYSTEM                         0x0004
#define FAT_ATTR_LABLE                          0x0008
#define FAT_ATTR_DIR                            0x0010
#define FAT_ATTR_ARCHIVE                        0x0020
#define FAT_ATTR_EXTREC                         0x000f

#define FL_READ                                 0x0001
#define FL_WRITE                                0x0002
#define FL_READING                              0x0004
#define FL_ROOT_DIR                             0x0008

// == Seek constants =========================================================
#define OLD_SEEK_SET                                0x00000000
#define OLD_SEEK_END                                0xffffffff
#define OLD_SEEK_CUR                                0xfffffffe

struct FS_ST_USBDEV
{
  FS_UINT16             lport;
  FS_UINT16             lunit;
};

#define DEFINE_USBDEV( n, p, u ) FS_ST_USBDEV n = { p, u }
#define EXTERN_USBDEV( n ) extern FS_ST_USBDEV n

#endif

#ifndef __FS_Device_H__
#define __FS_Device_H__

struct MBRLogicalDiskInfo
{
  FS_UINT8                      actived;
  FS_UINT8                      startHead;
  FS_UINT16UP                   startCylinderSector;
  FS_UINT8                      type;
  FS_UINT8                      endHead;
  FS_UINT16UP                   endCylinderSector;
  FS_UINT32UP                   lbaStart;
  FS_UINT32UP                   lbaSize;
};

struct BootSectorBPB
{
  FS_CHAR                       BS_JmpBoot[3];
  FS_CHAR                       BS_OEMName[8];
  FS_UINT16UP                   BPB_BytsPerSec;
  FS_UINT8                      BPB_SecPerClus;
  FS_UINT16UP                   BPB_RsvdSecCnt;
  FS_UINT8                      BPB_NumFATs;
  FS_UINT16UP                   BPB_RootEntCnt;
  FS_UINT16UP                   BPB_TotSec16;
  FS_UINT8                      BPB_Media;
  FS_UINT16UP                   BPB_FATSz16;
  FS_UINT16UP                   BPB_SecPerTrk;
  FS_UINT16UP                   BPB_NumHeads;
  FS_UINT32UP                   BPB_HiddSec;
  FS_UINT32UP                   BPB_TotSec32;
};

struct Fat16Info
{
  FS_UINT8                      BS_DrvNum;
  FS_UINT8                      BS_Reserved1;
  FS_UINT8                      BS_BootSig;
  FS_UINT32UP                   BS_VolID;
  FS_CHAR                       BS_VolLab[11];
  FS_CHAR                       BS_FilSysType[8];
};

struct Fat32Info
{
  FS_UINT32UP                   BPB_FATSz32;
  FS_UINT16UP                   BPB_ExtFlags;
  FS_UINT16UP                   BPB_FSVer;
  FS_UINT32UP                   BPB_RootClus;
  FS_UINT16UP                   BPB_FSInfo;
  FS_UINT16UP                   BPB_BkBootSec;
  FS_UINT8                      Reserved[12];
  FS_UINT8                      BS_DrvNum;
  FS_UINT8                      BS_Reserved1;
  FS_UINT8                      BS_BootSig;
  FS_UINT32UP                   BS_VolID;
  FS_CHAR                       BS_VolLab[11];
  FS_CHAR                       BS_FilSysType[8];
};

class DeviceInfo
{
  public:

    FS_UINT16                   devNum;
    FS_UINT16                   devParentPort;
    FS_UINT16                   devLun;
    FS_UINT32                   devSize;

    FS_UINT16                   flags;

                                DeviceInfo();

    void                        setFlag( FS_UINT16 mask );
    void                        clrFlag( FS_UINT16 mask );
    FS_BOOL                     chkFlag( FS_UINT16 mask );

    FS_UINT16                   fsDetect( FS_UINT16 mbrRecType );
    FS_UINT16                   fsDetectByBootSector( FS_UINT16* fsType, FS_BOOL dnud = FS_FALSE );
    FS_UINT16                   detectMBR();
    FS_UINT16                   readMBR( FS_UINT32 sectorNumber );
    FS_UINT16                   readBootSector( FS_UINT32 sectorNumber, FS_UINT32 size, FS_UINT16 fsType );
    FS_UINT16                   reInit();

    void* operator new( size_t s ) { return heap_alloc( NULL, s, HEAP_ALIGN_4 ); }
    void operator delete( void* ptr ) { heap_free( NULL, ptr ); }

};

struct DeviceLetterSelector
{
  FS_BOOL                       used;
  FS_UINT16                     port;
  FS_UINT16                     logic_unit;
  FS_UINT16                     midx;
  FS_UINT16                     midxw;
  FS_UINT16                     midx2;
  FS_UINT16                     hlport;
  FS_UINT16                     hlunit;
};

class Device
{
  friend class                  LogicDisk;
  friend class                  LogicDiskInfo;

  private:

    FS_UINT16                   numOfDevices;
    DeviceInfo**                devInfo;

  public:

    static const FS_UINT16      Auto;

    DeviceLetterSelector*       pLetterSelector;
    FS_UINT16                   pLetterSelectorCount;

    FS_UINT8                    sbuf[512];
    FS_BOOL                     usbDeviceReconnect;

                                Device( FS_UINT16 iNumOfDevices );
                                ~Device();

    FS_UINT16                   reInit();
    FS_UINT16                   resetApplPipe( FS_UINT16 ldChar );
    FS_UINT16                   resetAllApplPipe();
    FS_UINT16                   reInitLogicDisks( FS_UINT16 ldChar = 0xffff );
    FS_UINT16                   reInitLoLevel();
    FS_UINT16                   add( FS_INT16 num, FS_INT16 lun, FS_UINT16 setFlags );
    FS_UINT16                   del( FS_UINT16 devIndex );
    FS_UINT16                   getDevIndex( FS_UINT16 devNum, FS_UINT16 devLun );
    FS_UINT16                   getDevIndexByDevType( FS_UINT16 devType );
    FS_UINT16                   getDevIndexByUsbDev( FS_ST_USBDEV& pudev );
    FS_UINT16                   getFreeIndex();
    FS_UINT16                   getInfoStructure( FS_UINT16 devIndex, DeviceInfo** di );

    FS_UINT16                   drivePresent( FS_UINT16 devIndex );

    FS_UINT16                   readSector( FS_UINT16 devIndex, void* buf, FS_UINT32 sectorNumber, FS_UINT32 sectorCount = 1 );
    FS_UINT16                   readSector( DeviceInfo* devInf, void* buf, FS_UINT32 sectorNumber, FS_UINT32 sectorCount = 1 );
    FS_UINT16                   writeSector( FS_UINT16 devIndex, void* buf, FS_UINT32 sectorNumber, FS_UINT32 sectorCount = 1 );
    FS_UINT16                   writeSector( DeviceInfo* devInf, void* buf, FS_UINT32 sectorNumber, FS_UINT32 sectorCount = 1 );

    FS_UINT32                   calcCheckSum();

    FS_UINT16                   checkForAssignation( DeviceInfo* di );
    FS_UINT16                   assignLetter( FS_ST_USBDEV& pudev, FS_UINT16 midx, FS_UINT16 midxw, FS_UINT16 midx2 );

    void* operator new( size_t s ) { return heap_alloc( NULL, s, HEAP_ALIGN_4 ); }
    void operator delete( void* ptr ) { heap_free( NULL, ptr ); }

};

class LogicDiskInfo
{
  public:

    DeviceInfo*                 dev;

    FS_UINT16                   fsType;

    FS_UINT32                   lbaStart;
    FS_UINT32                   lbaSize;

    FS_UINT32                   fatStart;
    FS_UINT32                   fatSize;

    FS_UINT32                   rootDirStart;
    FS_UINT32                   rootDirCluster;
    FS_UINT32                   rootDirSectors;

    FS_UINT32                   firstDataSector;
    FS_UINT16                   sectorsPerCluster;
    FS_UINT32                   dataSectors;

    FS_CHAR*                    lable;
    FS_UINT32                   bootSectorCheckSum;

    FS_UINT32                   totalClusters;
    FS_UINT32                   freeClusters;
    FS_UINT32                   firstFreeCluster;

                                LogicDiskInfo( DeviceInfo* iDevInfo );
                                ~LogicDiskInfo();

    FS_UINT16                   init( FS_UINT32 iLbaStart, FS_UINT32 iLbaSize, FS_UINT16 iFsType );
    FS_UINT32                   firstSectorOfCluster( FS_UINT32 clusterNumber );
    FS_UINT16                   check();
    FS_UINT16                   read();

    void* operator new( size_t s ) { return heap_alloc( NULL, s, HEAP_ALIGN_4 ); }
    void operator delete( void* ptr ) { heap_free( NULL, ptr ); }

};

class LogicDisk
{
  private:

    FS_UINT16                   numOfLogicDisks;
    LogicDiskInfo**             logicDiskInfo;

  public:

    static const FS_UINT16      Auto;

                                LogicDisk( FS_UINT16 iNumOfLogicDisks );
                                ~LogicDisk();

    FS_UINT16                   getFreeIndex( FS_UINT16 minIndex, FS_UINT16 numOfIndexes, FS_UINT16 minIndex2 );
    FS_UINT16                   getInfo( FS_UINT16 ldIndex, LogicDiskInfo** infoPtr );

    FS_UINT16                   add( FS_UINT16 ldIndex, DeviceInfo* iDevInfo, FS_UINT32 lbaStart, FS_UINT32 lbaSize, FS_UINT16 fsType );
    FS_UINT16                   del( FS_UINT16 ldIndex );
    FS_UINT16                   removeByDev( DeviceInfo* iDevInfo );

    FS_UINT16                   checkPartitionData( DeviceInfo* iDevInfo );
    FS_UINT16                   getNumOfPartitions( DeviceInfo* iDevInfo );

    void* operator new( size_t s ) { return heap_alloc( NULL, s, HEAP_ALIGN_4 ); }
    void operator delete( void* ptr ) { heap_free( NULL, ptr ); }

};

extern LogicDisk logicDisk;
extern Device dev;

#endif

#ifndef __FS_File_H__
#define __FS_File_H__

class FileData
{
  protected:

    FS_CHAR*            curPath;

  public:

                        FileData();
    virtual             ~FileData();

    FS_BOOL             incPath( FS_CHAR* objName );
    FS_BOOL             decPath();
    FS_BOOL             copyPath( FileData* oldData );
    FS_BOOL             setPath( FS_CHAR* newPath );
    FS_CHAR*            getPath();
    FS_BOOL             isRoot();

    void* operator new( size_t s ) { return heap_alloc( NULL, s, HEAP_ALIGN_4 ); }
    void operator delete( void* ptr ) { heap_free( NULL, ptr ); }

};

class FileInfo
{
  public:

    FS_CHAR*            name;
    FS_UINT32           size;
    FS_UINT32           createTime;
    FS_UINT32           attr;

                        FileInfo();
                        ~FileInfo();

    void                clear();

    void* operator new( size_t s ) { return heap_alloc( NULL, s, HEAP_ALIGN_4 ); }
    void operator delete( void* ptr ) { heap_free( NULL, ptr ); }

};

class Flt;

class File
{
  public:

    FileData*           data;
    Flt*                flt;

                        File();
    virtual             ~File();

    FS_UINT16           switchObjectTo( FS_CHAR* objName );
    FS_UINT16           createObject( FS_CHAR* objName, FS_UINT32 attr );
    FS_UINT16           removeObject( FS_CHAR* objName );

    FS_UINT16           open( FS_UINT16 mode );
    FS_UINT16           close();
    FS_UINT16           read( void* data, FS_UINT32 length );
    FS_UINT16           write( void* data, FS_UINT32 lenght );
    FS_UINT16           seek( FS_INT32 offset, FS_UINT32 startPoint );
    FS_UINT16           tell( FS_UINT32* offset );
    FS_UINT16           eof( FS_BOOL* state );
    FS_UINT16           size( FS_UINT32* flowSize );
    FS_UINT16           getCreateDate( FS_UINT32* data );
    FS_UINT16           getLastModifyDate( FS_UINT32* data );
    FS_UINT16           trim( FS_UINT32 position );
    FS_UINT16           rename( FS_CHAR* newPath );

    FS_UINT16           writeLable( FS_CHAR* lable );

    FS_UINT16           findFirst( FS_CHAR* mask, FS_UINT32 attr, FileInfo* info );
    FS_UINT16           findNext( FileInfo* info );
    FS_UINT16           findClose();

    FS_UINT16           mkfile( FS_CHAR* fileName );
    FS_UINT16           rmfile( FS_CHAR* fileName );
    FS_UINT16           mkdir( FS_CHAR* dirName );
    FS_UINT16           rmdir( FS_CHAR* dirName );

    FS_UINT16           getFreeSpaceInBytes( FS_UINT32* freeBytes );
    FS_UINT16           getSize( FS_UINT32* size );

    FS_UINT32           getRWCounter();

    FS_UINT16           cflush();

    FS_UINT16           fsType();

    FS_UINT16           stUsbDev(FS_ST_USBDEV* d);

    void* operator new( size_t s ) { return heap_alloc( NULL, s, HEAP_ALIGN_4 ); }
    void operator delete( void* ptr ) { heap_free( NULL, ptr ); }

};

extern FS_CHAR*         const_fs_SelfPointer;
extern FS_CHAR*         const_fs_BackPointer;

#endif

#ifndef __File_Location_Table_H__
#define __File_Location_Table_H__

class File;
class FileInfo;

class Flt
{
  protected:

  public:

                        Flt();
    virtual             ~Flt();

    virtual FS_UINT16   switchObjectTo( File* f, FS_CHAR* objName );
    virtual FS_UINT16   createObject( File* f, FS_CHAR* objName, FS_UINT32 attr );
    virtual FS_UINT16   removeObject( File* f, FS_CHAR* objName );
    virtual FS_UINT16   removeObjectRecursive( File* f, FS_CHAR* objName );
    virtual FS_UINT16   init( File* f );

    virtual FS_UINT16   open( File* f, FS_UINT16 mode );
    virtual FS_UINT16   close( File* f );
    virtual FS_UINT16   read( File* f, void* dataPtr, FS_UINT32 length );
    virtual FS_UINT16   write( File* f, void* dataPtr, FS_UINT32 length );
    virtual FS_UINT16   seek( File* f, FS_INT32 offset, FS_UINT32 startPoint );
    virtual FS_UINT16   tell( File* f, FS_UINT32* offset );
    virtual FS_UINT16   eof( File* f, FS_BOOL* state );
    virtual FS_UINT16   size( File* f, FS_UINT32* flowSize );
    virtual FS_UINT16   getCreateDate( File* f, FS_UINT32* data );
    virtual FS_UINT16   getLastModifyDate( File* f, FS_UINT32* data );
    virtual FS_UINT16   trim( File* f, FS_UINT32 position );
    virtual FS_UINT16   rename( File* f, FS_CHAR* newPath );

    virtual FS_UINT16   writeLable( File* f, FS_CHAR* lable );

    virtual FS_UINT16   findFirst( File* f, FS_CHAR* mask, FS_UINT32 attr, FileInfo* info );
    virtual FS_UINT16   findNext( File* f, FileInfo* info );
    virtual FS_UINT16   findClose( File* f );

    virtual FS_UINT16   mkdir( File* f, FS_CHAR* dirName );
    virtual FS_UINT16   rmdir( File* f, FS_CHAR* dirName );
    virtual FS_UINT16   mkfile( File* f, FS_CHAR* fileName );
    virtual FS_UINT16   rmfile( File* f, FS_CHAR* fileName );

    virtual FS_UINT16   getFreeSpaceInBytes( FS_UINT32* freeBytes );
    virtual FS_UINT16   getSize( FS_UINT32* size );

    virtual FS_UINT32   getRWCounter( File* f );

    virtual FS_UINT16   cflush( File* f );

    virtual FS_UINT16   fsType();

    virtual FS_UINT16   stUsbDev(FS_ST_USBDEV* d);

    void* operator new( size_t s ) { return heap_alloc( NULL, s, HEAP_ALIGN_4 ); }
    void operator delete( void* ptr ) { heap_free( NULL, ptr ); }

};

#endif

#ifndef __FS_Format_H__
#define __FS_Format_H__

// return values: zero - good, nonzero - suxx
extern FS_UINT16 FormatFlash( FS_ST_USBDEV& pudev, void (*cbfunc)( FS_UINT32, FS_UINT32, void* ), void* arg );

#endif

#ifndef __FS_Monitor_H__
#define __FS_Monitor_H__

#define MAX_OPEN_FILES  16

class File;

class fsMonitor
{
  private:

    static File**       ofList;
    static FS_INT16     maxOpenFiles;
    static FS_INT16     numOfOpenFiles;

  public:

    static void         init( FS_INT16 iMaxOpenFiles );
    static void         deinit();
    static FS_BOOL      addOpenFile( File* f );
    static FS_BOOL      delOpenFile( File* f );
    static FS_BOOL      checkOpened( File* f );
    static void         umount( char* mountPointName );

    void* operator new( size_t s ) { return heap_alloc( NULL, s, HEAP_ALIGN_4 ); }
    void operator delete( void* ptr ) { heap_free( NULL, ptr ); }

};

#endif

#ifndef __FS_Mount_H__
#define __FS_Mount_H__

extern FS_UINT16 mount( FS_CHAR logicDiskLetter );
extern FS_UINT16 umount( FS_CHAR logicDiskLetter );
extern void mount_all();
extern void umount_all();

#endif

#ifndef __FS_Posix_Extension_H__
#define __FS_Posix_Extension_H__

/*
enum
{
  OLD_DT_UNKNOWN = 0,
  OLD_DT_FIFO = 1,
  OLD_DT_CHR = 2,
  OLD_DT_DIR = 4,
  OLD_DT_BLK = 6,
  OLD_DT_REG = 8,
  OLD_DT_LNK = 10,
  OLD_DT_SOCK = 12,
  OLD_DT_WHT = 14
};
*/

struct old_dirent
{
  FS_UINT32             d_ino;
  FS_UINT32             d_off;
  FS_UINT16             d_reclen;
  FS_UINT8              d_type;
  FS_CHAR               d_name[256];
};

class Dir: public File
{
  public:

    old_dirent          rec;
    FS_INT32            ssp;

    Dir() : File()
    {
      ssp = 0;
    }

    ~Dir()
    {
      /* Nothing */
    }

};

#define OLD_FILE        File
#define FREC            FileInfo
#define OLD_DIR         Dir

// -- Posix functions --------------------------------------------------------

/*[+]*/extern OLD_FILE*        old_fopen( FS_CHAR* path, FS_CHAR* mode );
/*[+]*/extern FS_INT32         old_fclose( OLD_FILE*& stream );
/*[+]*/extern FS_UINT32        old_fread( void* ptr, FS_UINT32 size, FS_UINT32 n, OLD_FILE* stream );
/*[+]*/extern FS_UINT32        old_fwrite( void* ptr, FS_UINT32 size, FS_UINT32 n, OLD_FILE* stream );
/*[+]*/extern FS_INT32         old_fseek( OLD_FILE* stream, FS_INT32 offset, FS_UINT32 whence );
/*[+]*/extern FS_UINT32        old_ftell( OLD_FILE* stream );

/*[+]*/extern FS_INT32         old_remove( FS_CHAR* path );
/*[+]*/extern FS_INT32         old_rename( FS_CHAR* oldpath, FS_CHAR* newpath );
/*[+]*/extern FS_INT32         old_feof( OLD_FILE* stream );
/*[+]*/extern FS_INT32         old_fputs( const FS_CHAR* s, OLD_FILE* f );
//-STD-extern FS_CHAR*         old_fgets( FS_CHAR* buf, FS_INT32 len, OLD_FILE* f );
//-----extern FS_BOOL          old_findfirst( FS_CHAR* mask, FREC* frec, FS_INT16 attr );
//-----extern FS_BOOL          old_findnext( FREC* frec );
//-----extern void             old_findclose();
/*[+]*/extern OLD_DIR*         old_opendir( FS_CHAR* name );
/*[+]*/extern FS_INT32         old_closedir( OLD_DIR*& dir );
/*[+]*/extern old_dirent*      old_readdir( OLD_DIR* dir );
//-----extern FS_INT32         old_chdir( FS_CHAR* path );
/*[+]*/extern FS_INT32         old_mkdir( FS_CHAR* path );
/*[+]*/extern FS_INT32         old_rmdir( FS_CHAR* path );
//-----extern FS_CHAR*         old_getcwd( FS_CHAR* buf, FS_INT16 buflen );
/*[+]*/extern FS_UINT32        old_ftrim( OLD_FILE* stream, FS_UINT32 position );
//-----extern FS_UINT32        old_ftrimb( OLD_FILE* stream, FS_UINT32 position );

// -- Additional functions ---------------------------------------------------

/*[+]*/extern FS_UINT32        old_fsize( OLD_FILE* stream );
//-----extern FS_UINT32        old_fsize( FS_CHAR* fileName );
//-----extern FS_BOOL          old_fcopy( FS_CHAR* from_file_name, FS_CHAR* to_file_name );
//-----extern FS_BOOL          old_write_lable( FS_CHAR disk, FS_CHAR* lable );
//-----extern FS_UINT32        old_disk_free_space( FS_CHAR disk ); // Returned value is KBytes, if 0xffffffff then error
//-----extern FS_UINT32        old_disk_size( FS_CHAR disk ); // Returned value is KBytes, if 0xffffffff then error
//-----extern FS_CHAR*         old_disk_lable( FS_CHAR disk );

// -- System functions [do not use] ------------------------------------------

extern FS_INT16         get_object_count( FS_CHAR* path );
extern void             get_object_name_boundary( FS_CHAR* path, FS_INT16 n, FS_INT16* pStart, FS_INT16* pEnd );
extern FS_CHAR*         normalize_path( FS_CHAR* path );
extern FS_UINT16        fs_goto( OLD_FILE* f, FS_CHAR* path, FS_INT16 nStep );

#endif

#ifndef __FS_RootFS_H__
#define __FS_RootFS_H__

#define RFS_TYPE_NO             0x0000
#define RFS_TYPE_DIR            0x0001
#define RFS_TYPE_MOUNT_POINT    0x0002
#define RFS_TYPE_BACK_POINT     0x0003
#define RFS_TYPE_UNMOUNTED      0x0010

class RootFSFileData: public FileData
{
  public:

    FS_UINT16           findIndex;
    FS_CHAR*            findMask;
    FS_UINT32           findAttr;
    FS_UINT16           numOfIndexes;

                        RootFSFileData();
    virtual             ~RootFSFileData();

    void* operator new( size_t s ) { return heap_alloc( NULL, s, HEAP_ALIGN_4 ); }
    void operator delete( void* ptr ) { heap_free( NULL, ptr ); }

};

class RootFSRec
{
  public:

    FS_UINT16           type;
    FS_CHAR*            name;
    FS_UINT32           createTime;
    FS_UINT32           attr;

                        RootFSRec();
    virtual             ~RootFSRec();

    void* operator new( size_t s ) { return heap_alloc( NULL, s, HEAP_ALIGN_4 ); }
    void operator delete( void* ptr ) { heap_free( NULL, ptr ); }

};

class RootFSMountPoint: public RootFSRec
{
  public:

    Flt*                drv;

                        RootFSMountPoint();
                        ~RootFSMountPoint();

    void* operator new( size_t s ) { return heap_alloc( NULL, s, HEAP_ALIGN_4 ); }
    void operator delete( void* ptr ) { heap_free( NULL, ptr ); }

};

class RootFS: public Flt
{
  private:

    RootFSRec**         recs;
    FS_UINT16           numOfRecs;

  public:

                        RootFS();
                        ~RootFS();

    FS_UINT16           switchObjectTo( File* f, FS_CHAR* objName );
    FS_UINT16           init( File* f );

    FS_UINT16           getCreateDate( File* f, FS_UINT32* data );
    FS_UINT16           getLastModifyDate( File* f, FS_UINT32* data );

    FS_UINT16           findFirst( File* f, FS_CHAR* mask, FS_UINT32 attr, FileInfo* info );
    FS_UINT16           findNext( File* f, FileInfo* info );
    FS_UINT16           findClose( File* f );
    FS_UINT16           mkdir( File* f, FS_CHAR* dirName );
    FS_UINT16           rmdir( File* f, FS_CHAR* dirName );

    FS_UINT16           mount( FS_CHAR* path, Flt* fsDrv );
    FS_UINT16           umount( FS_CHAR* path );
    FS_UINT16           addRec( RootFSRec* rec );
    FS_UINT16           delRec( FS_CHAR* path );
    FS_UINT16           getRecIndexByName( FS_CHAR* name );
    FS_UINT16           getRecPointerByName( FS_CHAR* name, RootFSRec** rec );

    FS_UINT16           fsType();

    void* operator new( size_t s ) { return heap_alloc( NULL, s, HEAP_ALIGN_4 ); }
    void operator delete( void* ptr ) { heap_free( NULL, ptr ); }

};

extern RootFS           rootFs;

#endif

#ifndef __FS_Utils_H__
#define __FS_Utils_H__

extern void                     (*fs_vfat_rnd_func)( void* data, FS_UINT32 length );

class fsUtils
{
  public:

    static void                 rnd( void* data, FS_UINT32 length );
    static void                 setRandFunc( void (*f)(void*,FS_UINT32) );
    static FS_BOOL              cmpL( FS_CHAR* str1, FS_CHAR* str2, FS_UINT16 length );
    static FS_BOOL              maskCmp( FS_CHAR* mask, FS_CHAR* str );
    static FS_BOOL              maskCmpEndChar( FS_CHAR* mask, FS_CHAR* str, FS_CHAR endChar );
    static FS_CHAR              upCase( FS_CHAR ch );
    static FS_BOOL              upCaseCmp( FS_CHAR* str1, FS_CHAR* str2 );
    static FS_BOOL              upCaseMaskCmp( FS_CHAR* mask, FS_CHAR* str );
    static FS_UINT16            findChar( FS_CHAR* str, FS_CHAR ch );
    static FS_UINT32            crc32( FS_CHAR* str );
    static FS_BOOL              aGb( FS_CHAR* a, FS_CHAR* b );
    static FS_UINT32            fsMod( FS_UINT32 a, FS_UINT32 b );
    static void                 timeDos2Unix( FS_UINT16 ymd, FS_UINT16 hms, FS_UINT32* tunix );
    static void                 timeUnix2Dos( FS_UINT32 tunix, FS_UINT16* ymd, FS_UINT16* hms );

};

extern void* fs_alloc( FS_INT32 s );
extern void fs_free( void* p );

#endif

#ifndef __FS_VFAT_H__
#define __FS_VFAT_H__

#define FAT_CASH_SIZE   4

// Full secure clearing
//#define VFAT_SECLEAN_FULL
// Only first 1kb in file will be cleared
#define VFAT_SECLEAN_PARTIAL

#ifdef VFAT_SECLEAN_FULL
#  ifdef VFAT_SECLEAN_PARTIAL
#    undef VFAT_SECLEAN_PARTIAL
#  endif
#endif

struct FATParentDirInfo
{
  FS_UINT32             attributes;
  FS_UINT16             timeCreateYMD;
  FS_UINT16             timeCreateHMS;
  FS_UINT16             timeModifyYMD;
  FS_UINT16             timeModifyHMS;
  FS_UINT32             startCluster;
  FS_UINT32             startSector;
  FS_UINT32             flowSize;
  FS_INT32              dirStartSection;
  FS_INT32              dirEndSection;
  FS_UINT32             dirSectionSector;
};

class FATFileData: public FileData
{
  public:

    FS_UINT32           attributes;
    FS_UINT16           timeCreateYMD;
    FS_UINT16           timeCreateHMS;
    FS_UINT16           timeModifyYMD;
    FS_UINT16           timeModifyHMS;

    FS_UINT8*           cash;
    FS_UINT32           cashSize;
    FS_UINT32           cashCluster;
    FS_BOOL             cashModifyed;

    FS_UINT32           startSector;
    FS_UINT32           startCluster;
    FS_UINT32           currentSector;
    FS_UINT32           currentCluster;

    FS_UINT32           flowSize;
    FS_UINT32           flowPosition;
    FS_UINT16           clusterPosition;

    FS_INT32            dirStartSection;
    FS_INT32            dirEndSection;
    FS_UINT32           dirSectionSector;

    FS_UINT16           flowMode;
    FS_BOOL             newClusterAllocated;

    FS_CHAR*            findMask;
    FS_UINT32           findAttr;

    FATParentDirInfo*   pDirInfo;

    FS_UINT32           rwCounter;

                        FATFileData();
                        ~FATFileData();

    FS_UINT16           prepareParentDirInfo();
    FS_UINT16           backToParentDir();
    void                clearParentDirInfo();

    void* operator new( size_t s ) { return heap_alloc( NULL, s, HEAP_ALIGN_4 ); }
    void operator delete( void* ptr ) { heap_free( NULL, ptr ); }

};

struct InterfaceLFNRec
{
  FS_UINT8              number;
  FS_UINT16UP           name1[5];
  FS_UINT8              attr;
  FS_UINT8              LDIR_Type;
  FS_UINT8              LDIR_ChkSum;
  FS_UINT16UP           name2[9];
  FS_UINT16             getChar( FS_UINT16 idx );
};

struct InterfaceFileRec
{
  FS_CHAR               Name[8];
  FS_CHAR               Ext[3];
  FS_UINT8              Attr;
  FS_UINT8              NTRes;
  FS_UINT8              CrtTimeTenth;
  FS_UINT16UP           CrtTime;
  FS_UINT16UP           CrtDate;
  FS_UINT16UP           LstAccDate;
  FS_UINT16UP           FstClusHi;
  FS_UINT16UP           WrtTime;
  FS_UINT16UP           WrtDate;
  FS_UINT16UP           FstClusLo;
  FS_UINT32UP           FileSize;
  // TI # SDSCM00038073 defect fixing
  FS_UINT8 checkSum()
  {
    FS_UINT8 res = 0;
    FS_INT16 i;
    for( i = 0; i < 8; i++ ) res = ( ( ( res & 1 ) ? 0x80 : 0 ) + ( ( res >> 1 ) & 0x7f ) + Name[i] ) & 0xff;
    for( i = 0; i < 3; i++ ) res = ( ( ( res & 1 ) ? 0x80 : 0 ) + ( ( res >> 1 ) & 0x7f ) + Ext[i] ) & 0xff;
    return res;
  }
};

class FATFileRecord
{
  public:

    FS_CHAR*            shortName;
    FS_CHAR*            name;
    FS_UINT32           size;
    FS_UINT32           startCluster;
    FS_UINT16           attributes;
    FS_UINT32           sSection;
    FS_UINT32           eSection;
    FS_UINT32           dirSectionSector;
    FS_UINT16           tcymd;
    FS_UINT16           tchms;
    FS_UINT16           tmymd;
    FS_UINT16           tmhms;

                        FATFileRecord();
                        ~FATFileRecord();

    void                clear();

    void* operator new( size_t s ) { return heap_alloc( NULL, s, HEAP_ALIGN_4 ); }
    void operator delete( void* ptr ) { heap_free( NULL, ptr ); }

};

class RootFSMountPoint;
class LogicDiskInfo;

struct FatCash
{
  FS_UINT32             sector;
  FS_UINT16             usage;
  FS_UINT8              data[512];
};

class Fat: public Flt
{
  protected:

    LogicDiskInfo*      ldInfo;
    RootFSMountPoint*   myMountPoint;
    FatCash             fatCash[FAT_CASH_SIZE];
    FS_UINT32           mayRead;

  public:

                        Fat();
                        ~Fat();

    void                setup( LogicDiskInfo* iLdInfo, RootFSMountPoint* iMyMountPoint );

    FS_UINT16           switchObjectTo( File* f, FS_CHAR* objName );
    FS_UINT16           backForOneObject( File* f, FATFileRecord& frec );
    FS_UINT16           createObject( File* f, FS_CHAR* objName, FS_UINT32 attr );
    FS_UINT16           removeObject( File* f, FS_CHAR* objName );
    FS_UINT16           removeObjectRecursive( File* f, FS_CHAR* objName );
    FS_UINT16           init( File* f );

    FS_UINT16           open( File* f, FS_UINT16 mode );
    FS_UINT16           close( File* f );
    FS_UINT16           read( File* f, void* dataPtr, FS_UINT32 length );
    FS_UINT16           write( File* f, void* dataPtr, FS_UINT32 length );
    FS_UINT16           eof( File* f, FS_BOOL* state );
    FS_UINT16           seek( File* f, FS_INT32 offset, FS_UINT32 startPoint );
    FS_UINT16           tell( File* f, FS_UINT32* offset );
    FS_UINT16           size( File* f, FS_UINT32* flowSize );
    FS_UINT16           getCreateDate( File* f, FS_UINT32* data );
    FS_UINT16           getLastModifyDate( File* f, FS_UINT32* data );
    FS_UINT16           trim( File* f, FS_UINT32 position );
    FS_UINT16           rename( File* f, FS_CHAR* newPath );

    FS_UINT16           writeLable( File* f, FS_CHAR* lable );

    FS_UINT16           findFirst( File* f, FS_CHAR* mask, FS_UINT32 attr, FileInfo* info );
    FS_UINT16           findNext( File* f, FileInfo* info );
    FS_UINT16           findClose( File* f );

    FS_UINT16           mkdir( File* f, FS_CHAR* dirName );
    FS_UINT16           rmdir( File* f, FS_CHAR* dirName );
    FS_UINT16           mkfile( File* f, FS_CHAR* fileName );
    FS_UINT16           rmfile( File* f, FS_CHAR* fileName );

    FS_UINT16           doCashCluster( File* f );
    FS_UINT16           doCashStore( File* f );

    FS_UINT16           getNextClusterNumber( File* f );
    FS_UINT16           readFileRecord( File* f, FATFileRecord* fRec );
    FS_UINT16           writeFileRecord( File* f, FATFileRecord* fRec );
    FS_BOOL             checkFileRecord( FATFileRecord* fRec );

    FS_UINT32           fatGetCashIndex( FS_UINT32 sector );
    FS_UINT16           fatGetRecValue( FS_UINT32 cluster, FS_UINT32* value );
    FS_UINT16           fatSetRecValue( FS_UINT32 cluster, FS_UINT32 value );
    FS_UINT16           fatAllocFreeCluster( FS_UINT32 prev, FS_UINT32* cluster );
    FS_UINT16           fatRemoveFrom( FS_UINT32 cluster );
    FS_UINT16           fatGetSequenceLength( FS_UINT32 startCluster, FS_UINT32* length );
    FS_UINT16           fatFindFirstFreeCluster( FS_UINT32 fromClaster );
    FS_UINT16           getFreeSpaceInBytes( FS_UINT32* freeBytes );
    FS_UINT16           getSize( FS_UINT32* size );

    FS_UINT32           getRWCounter( File* f );

    FS_UINT16           cflush( File* f );

    FS_UINT16           fsType();

    FS_UINT16           stUsbDev(FS_ST_USBDEV* d);

    void* operator new( size_t s ) { return heap_alloc( NULL, s, HEAP_ALIGN_4 ); }
    void operator delete( void* ptr ) { heap_free( NULL, ptr ); }

};

#endif

#ifndef __FS_External_H__
#define __FS_External_H__

extern void FS_LOCK_INIT();
extern void FS_LOCK();
extern void FS_UNLOCK();
extern void FS_LOCK0();
extern void FS_UNLOCK0();
extern void FS_LOCK1();
extern void FS_UNLOCK1();
extern void FS_REINIT_LOCK();
extern void FS_REINIT_UNLOCK();

#endif

#ifndef __UniCode_H__
#define __UniCode_H__

#define CHS_KOI8R       0x0000
#define CHS_CP1251      0x0001
#define CHS_CP866       0x0002
#define CHS_RU_UNICODE  0x0003

#define CHS_NONE        0xffff

extern unsigned short int cp1251_to_unicode( unsigned char c );
extern unsigned char unicode_to_cp1251( unsigned short int c );

extern unsigned char cp1251_to_cp866( unsigned char c );
extern unsigned char cp866_to_cp1251( unsigned char c );

extern unsigned char koi8r_to_cp866( unsigned char c );
extern unsigned char cp866_to_koi8r( unsigned char c );

extern unsigned char cp1251_to_koi8r( unsigned char c );
extern unsigned char koi8r_to_cp1251( unsigned char c );

// CHS_RU_UNICODE not allowed as char set
extern void chs_recode( char* str, int from_chs, int to_chs );
extern void chs_mem_recode( void* vbuf, int len, unsigned short int from_chs, unsigned short int to_chs );

#endif

#endif
