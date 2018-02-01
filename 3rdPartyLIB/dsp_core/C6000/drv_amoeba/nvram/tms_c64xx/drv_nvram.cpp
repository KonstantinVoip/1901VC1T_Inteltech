// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp1251
// !: d: ������ �������� ���������� ������� �������� NVRAM.
// !: d: 
// !: -: 
// ---------------------------------------------------------------------------
#include <drv_nvram.h>
#include <rts.h>
// ---------------------------------------------------------------------------

//*******************************
//       ��������� �������
//*******************************
int32 nvram_keep();
int32 nvram_addr();
void nvram_align();
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
// !: fn: int32 nvram_open (s_os_driver_descriptor* d, uint16 access)
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: ������� �� ������������.
// !: d: � ������ ������, ���������� ����������� ��� ������ OSE_BAD_CMD.
// !: -:
// ---------------------------------------------------------------------------
int32 nvram_open (s_os_driver_descriptor* d, uint16 access)
{
  return OSE_BAD_CMD;
}

// ---------------------------------------------------------------------------
// !: fn: int32 nvram_close (s_os_driver_descriptor* d)
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: ������� �� ������������.
// !: d: � ������ ������, ���������� ����������� ��� ������ OSE_BAD_CMD.
// !: -:
// ---------------------------------------------------------------------------
int32 nvram_close (s_os_driver_descriptor* d)
{
  return OSE_BAD_CMD;
}

// ---------------------------------------------------------------------------
// !: fn: int32 nvram_read (s_os_driver_descriptor* d, void* buf, int32 length)
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: ������� �� ������������.
// !: d: � ������ ������, ���������� ����������� ��� ������ OSE_BAD_CMD.
// !: -:
// ---------------------------------------------------------------------------
int32 nvram_read (s_os_driver_descriptor* d, void* buf, int32 length)
{
  return OSE_BAD_CMD;
}

// ---------------------------------------------------------------------------
// !: fn: int32 nvram_write (s_os_driver_descriptor* d, const void* buf, int32 length)
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: ������� �� ������������.
// !: d: � ������ ������, ���������� ����������� ��� ������ OSE_BAD_CMD.
// !: -:
// ---------------------------------------------------------------------------
int32 nvram_write (s_os_driver_descriptor* d, const void* buf, int32 length)
{
  return OSE_BAD_CMD;
}

// ---------------------------------------------------------------------------
// !: fn: int32 nvram_ioctl( s_os_driver_descriptor* d, int32 cmd, const void* arg )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: ������� ������������ ��� ���������� ����������� ����������� cmd
// !: d: ��� ������� NVRAM.
// !: d:
// !: d: �������������� ����������� ����������� �����������:
// !: d: IOC_INIT, IOC_INODE_SELECT.
// !: d: ��������� ����������� ����������� ����������� �� ��������������.
// !: d: 
// !: d: � ������ ������ ���������� OSE_OK, �����, ����� ����������� ������:
// !: d: OSE_ADDRESS_TEST_ERROR - ������ ��������� �����;
// !: d: OSE_DATA_TEST_ERROR - ������ ����� ��������.
// !: d: 
// !: d: ������ ������� �������� ������������.
// !: -:
// ---------------------------------------------------------------------------
int32 nvram_ioctl( s_os_driver_descriptor* d, int32 cmd, const void* arg )
{
  //int32 err1,err2;
    int32 error = OSE_OK;

    switch( cmd )
    {
    //================================
    //Standard control command:
    //================================
        case IOC_INIT_DESCRIPTOR:
		case IOC_DEINIT_DESCRIPTOR:
			break;
            
        case IOC_INIT:
        {
            uint32 bpo_file;
            bpo_file = drv_mkd( "/fwmem/bpo-main.lif" );
            if( bpo_file != RES_VOID )
            {
                drv_rmd( bpo_file );
                //  ������������
                nvram_align();
                break;
            }
            #ifndef NO_OS_MEMTST
            //  ���� ��������
            err1 = nvram_keep();
            //  �������� ����
            err2 = nvram_addr();

            if(err2==OSE_OK)
              error = err1;
            else 
              error = err2;
            #endif
        }
        break;

        case IOC_DEINIT:
          break;

        case IOC_INODE_SELECT:
        {
            if( arg == NULL ) return OSE_NULL_PARAM;
            
            char* dst = (char*)const_cast<void*>( arg );
            
            if( strcmp( dst, "." ) == 0 ) break;
            if( strcmp( dst, ".." ) != 0 ) return OSE_NO_NODE;
            drv_dec( d );
            drv_rfs( d );
        }
        break;

        default:
          return OSE_BAD_CMD;
    }
  return error;
}

// ---------------------------------------------------------------------------
// !: fn: int32 drv_nvram_plug( const char* path, const char* name )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: ������� ��������� ������� NVRAM ��� ������ name
// !: d: � ����� ������������ path.
// !: d: ������ ������� �������� ������������.
// !: -:
// ---------------------------------------------------------------------------
int32 drv_nvram_plug( const char* path )
{
  return drv_plug( path, INOT_FILE, &nvram_open, &nvram_close, &nvram_read, &nvram_write, &nvram_ioctl, NULL, 0 );
}

// ---------------------------------------------------------------------------
// !: fn: int32 drv_nvram_unplug( const char* name )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: ������� ������� ������� NVRAM � ������ name.
// !: d: ������ ������� �������� ������������.
// !: -:
// ---------------------------------------------------------------------------
int32 drv_nvram_unplug( const char* name )
{
  return drv_unplug( name );
}

// ---------------------------------------------------------------------------
// !: fn: int32 nvram_keep()
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: ������� ��������� ���� �������� NVRAM. 
// !: d: � ������ ������ ���������� OSE_OK, �����:
// !: d: OSE_DATA_TEST_ERROR - ������ ����� ��������.
// !: d: 
// !: d: ������ ������� �� �������� ������������.
// !: -:
// ---------------------------------------------------------------------------
int32 nvram_keep()
{
    uint16* addr = (uint16*)NVRAM_START_ADDR;
	uint16 D;
    uint32 i;
    
    for( i = 0; i < NVRAM_SIZE/2; i++ )
    {
        D = *addr++;
        if(D != ((0x7FFFF-i)&0xFFFF))
            return OSE_DATA_TEST_ERROR;
    }
    return OSE_OK;
}

// ---------------------------------------------------------------------------
// !: fn: int32 nvram_addr()
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: ������� ��������� �������� ���� NVRAM. 
// !: d: � ������ ������ ���������� OSE_OK, �����:
// !: d: OSE_ADDRESS_TEST_ERROR - ������ ��������� �����.
// !: d: 
// !: d: ������ ������� �� �������� ������������.
// !: -:
// ---------------------------------------------------------------------------
int32 nvram_addr()
{
    uint16* addr = (uint16*)NVRAM_START_ADDR;
	uint16 D;
    uint32 i;
    
    for( i = 0; i < NVRAM_SIZE/2; i++ )
        *addr++ = (i&0xFFFF);

    addr =(uint16*)NVRAM_START_ADDR;
    for( i = 0; i < NVRAM_SIZE/2; i++ )
    {
        D = *addr++;
        if( D != (i&0xFFFF) )
            return OSE_ADDRESS_TEST_ERROR;
	}
 
    addr =(uint16*)NVRAM_START_ADDR;
    for( i = 0; i < NVRAM_SIZE/2; i++ )
        *addr++ = (0x7FFFF-i)&0xFFFF;

    for( i = 0; i < NVRAM_SIZE/2; i++ )
    {
        D = *addr++;
        if(D != ((0x7FFFF-i)&0xFFFF))
            return OSE_ADDRESS_TEST_ERROR;
    }
    return OSE_OK;
}

// ---------------------------------------------------------------------------
// !: fn: void nvram_align()
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: ������� ��������� ������������ NVRAM. 
// !: d: 
// !: d: ������ ������� �� �������� ������������.
// !: -:
// ---------------------------------------------------------------------------
void nvram_align()
{
  uint8 b[512];
  uint8* nvptr = (uint8*)NVRAM_START_ADDR;
  for( uint32 i = 0; i < 1048576; i += 512 )
  {
    memcpy( b, nvptr, 512 );
    syn_data( b, 512, 0 );
    memcpy( nvptr, b, 512 );
    nvptr += 512;
  }
}
// ---------------------------------------------------------------------------




