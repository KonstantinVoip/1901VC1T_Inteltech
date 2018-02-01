// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp1251
// !: d: Модуль содержит реализацию функций драйвера DNSD.
// !: d: 
// !: -: 
// ---------------------------------------------------------------------------
#include <drv_dnsd.h>
#include <rts.h>

#include <drv_mcbsp.h>
// ---------------------------------------------------------------------------

#define DELAY_WAKEUP    80
#define DELAY_STREAM    20

MCBSP_Handle dnsd_hMcbsp = NULL;

//*******************************
//       Прототипы функций
//*******************************

//----------------------------------------------------------------------
MCBSP_Handle spi_init( int devNum );
//----------------------------------------------------------------------
void led_on();
//----------------------------------------------------------------------
void led_off();
//----------------------------------------------------------------------
void k0k1_write( MCBSP_Handle hMcbsp, uint8* data );
//----------------------------------------------------------------------
void k0_read( MCBSP_Handle hMcbsp, uint8* data );
//----------------------------------------------------------------------
void crc_read( MCBSP_Handle hMcbsp, uint8* data );
//----------------------------------------------------------------------
uint8 spi_rw( MCBSP_Handle hMcbsp, uint8* data, uint32 time );
//----------------------------------------------------------------------
void magic_read( MCBSP_Handle hMcbsp, uint8* data );
//----------------------------------------------------------------------
void lux_read( MCBSP_Handle hMcbsp, uint8* data );

// ---------------------------------------------------------------------------
// !: fn: int32 dnsd_open( s_os_driver_descriptor* d, uint16 access )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция не используется.
// !: d: В случае вызова, возвращает стандартный код ошибки OSE_BAD_CMD.
// !: -:
// ---------------------------------------------------------------------------
int32 dnsd_open( s_os_driver_descriptor* d, uint16 access )
{
  return OSE_BAD_CMD;
}

// ---------------------------------------------------------------------------
// !: fn: int32 dnsd_close( s_os_driver_descriptor* d )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция не используется.
// !: d: В случае вызова, возвращает стандартный код ошибки OSE_BAD_CMD.
// !: -:
// ---------------------------------------------------------------------------
int32 dnsd_close( s_os_driver_descriptor* d )
{
  return OSE_BAD_CMD;
}

// ---------------------------------------------------------------------------
// !: fn: int32 dnsd_read( s_os_driver_descriptor* d, void* buf, int32 length )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция не используется.
// !: d: В случае вызова, возвращает стандартный код ошибки OSE_BAD_CMD.
// !: -:
// ---------------------------------------------------------------------------
int32 dnsd_read( s_os_driver_descriptor* d, void* buf, int32 length )
{
  return OSE_BAD_CMD;
}

// ---------------------------------------------------------------------------
// !: fn: int32 dnsd_write( s_os_driver_descriptor* d, const void* buf, int32 length )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция не используется.
// !: d: В случае вызова, возвращает стандартный код ошибки OSE_BAD_CMD.
// !: -:
// ---------------------------------------------------------------------------
int32 dnsd_write( s_os_driver_descriptor* d, const void* buf, int32 length )
{
  return OSE_BAD_CMD;
}

// ---------------------------------------------------------------------------
// !: fn: int32 dnsd_ioctl( s_os_driver_descriptor* d, int32 cmd, const void* arg )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция используется для выполнения управляющих воздействий cmd
// !: d: на DNSD.
// !: d:
// !: d: Поддерживаются стандартные управляющие воздействия:
// !: d: IOC_INIT, IOC_INODE_SELECT.
// !: d: Остальные стандартные управляющие воздействия не поддерживаются.
// !: d: 
// !: d: В случае успеха возвращает OSE_OK, иначе, кроме стандартных ошибок:
// !: d: OSE_ADDRESS_TEST_ERROR - ошибка адресного теста;
// !: d: OSE_DATA_TEST_ERROR - ошибка теста хранения.
// !: d: 
// !: d: Данная функция доступна пользователю.
// !: -:
// ---------------------------------------------------------------------------
int32 dnsd_ioctl( s_os_driver_descriptor* d, int32 cmd, const void* arg )
{
    int32 error = OSE_OK;
    uint8 command = 0;

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
//            dnsd_hMcbsp = spi_init( MCBSP_DEV2 );
            if( dnsd_hMcbsp == NULL )
                return OSE_NO_DEVICE;
            if( dnsd_hMcbsp->allocated != TRUE )
                return OSE_NOT_INITIALIZED;
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

        case DNSD_K0K1_WRITE:
        {
            if( arg == NULL ) return OSE_NULL_PARAM;
            uint8 *data = (uint8 *)const_cast<void*>(arg);

            k0k1_write( dnsd_hMcbsp, data );
        }
          break;

        case DNSD_K0_READ:
        {
            if( arg == NULL ) return OSE_NULL_PARAM;
            uint8 *data = (uint8 *)const_cast<void*>(arg);

            k0_read( dnsd_hMcbsp, data );
        }
          break;

        case DNSD_INIT:
        {
            command = 0x81;
            spi_rw( dnsd_hMcbsp, &command, DELAY_WAKEUP );
        }
          break;

        case DNSD_PlateLED_ON:
        {
            led_on();
        }
          break;

        case DNSD_PlateLED_OFF:
        {
            led_off();
        }
          break;

        case DNSD_READ_ADC:
        {
            if( arg == NULL ) return OSE_NULL_PARAM;
            uint8 *data = (uint8 *)const_cast<void*>(arg);

            command = 0x88;
            spi_rw( dnsd_hMcbsp, &command, DELAY_WAKEUP );
            sleep_m( 200 );

            command = 0;
            *data = spi_rw( dnsd_hMcbsp, &command, DELAY_WAKEUP );
        }
          break;

        case DNSD_LED_ON:
        {
            command = 0x8A;
            spi_rw( dnsd_hMcbsp, &command, DELAY_WAKEUP );
            sleep_s( 1 );
        }
          break;

        case DNSD_READ_CRC:
        {
            if( arg == NULL ) return OSE_NULL_PARAM;
            uint8 *data = (uint8 *)const_cast<void*>(arg);

            crc_read( dnsd_hMcbsp, data );
        }
          break;

        case DNSD_READ_0A5:
        {
            if( arg == NULL ) return OSE_NULL_PARAM;
            uint8 *data = (uint8 *)const_cast<void*>(arg);

            command = 0x8B;
            spi_rw( dnsd_hMcbsp, &command, DELAY_WAKEUP );

            sleep_m( 200 );
            command = 0;
            *data = spi_rw( dnsd_hMcbsp, &command, DELAY_WAKEUP );
        }
          break;

        case DNSD_MAGIC:
        {
            if( arg == NULL ) return OSE_NULL_PARAM;
            uint8 *data = (uint8 *)const_cast<void*>(arg);

            command = 0x72;
            magic_read( dnsd_hMcbsp, data );
        }
          break;

        case DNSD_LUX:
        {
            if( arg == NULL ) return OSE_NULL_PARAM;
            uint8 *data = (uint8 *)const_cast<void*>(arg);

            command = 0x74;
            lux_read( dnsd_hMcbsp, data );
        }
          break;

        default:
          return OSE_BAD_CMD;
    }
  return error;
}

// ---------------------------------------------------------------------------
// !: fn: int32 drv_dnsd_plug( const char* path, const char* name )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция добавляет драйвер DNSD под именем name
// !: d: в точку монтирования path.
// !: d: Данная функция доступна пользователю.
// !: -:
// ---------------------------------------------------------------------------
int32 drv_dnsd_plug( const char* path )
{
  return drv_plug( path, INOT_FILE, &dnsd_open, &dnsd_close, &dnsd_read, &dnsd_write, &dnsd_ioctl, NULL, 0 );
}

// ---------------------------------------------------------------------------
// !: fn: int32 drv_dnsd_unplug( const char* name )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция удаляет драйвер DNSD с именем name.
// !: d: Данная функция доступна пользователю.
// !: -:
// ---------------------------------------------------------------------------
int32 drv_dnsd_unplug( const char* name )
{
  return drv_unplug( name );
}
//----------------------------------------------------------------------
void MCBSP_resetXmt( MCBSP_Handle hMcbsp )
{
    MCBSP_FSETSH( hMcbsp, SPCR, XRST, YES );
}
//----------------------------------------------------------------------
void MCBSP_gpio( MCBSP_Handle hMcbsp )
{
    MCBSP_FSETSH( hMcbsp, PCR, XIOEN, GPIO );
}
//----------------------------------------------------------------------
void MCBSP_spi( MCBSP_Handle hMcbsp )
{
    MCBSP_FSETSH( hMcbsp, PCR, XIOEN, SP );
}
//----------------------------------------------------------------------
void led_on()
{
    syn_begin();
    REG_CTL2 |= TCTL_DATOUT;
    sleep_m( 500 );
    syn_end();
}
//----------------------------------------------------------------------
void led_off()
{
    syn_begin();
    REG_CTL2 &= ~TCTL_DATOUT;
    syn_end();
}
//----------------------------------------------------------------------
MCBSP_Handle spi_init( int devNum )
{
    MCBSP_Handle hMcbsp = MCBSP_open( devNum , MCBSP_OPEN_RESET );

    MCBSP_Config config;
    MCBSP_getConfig( hMcbsp, &config );

    config.rcr = MCBSP_RCR_RMK( MCBSP_RCR_RPHASE_SINGLE,
                              MCBSP_RCR_RFRLEN2_OF( 0 ),
                              MCBSP_RCR_RWDLEN2_8BIT,
                              MCBSP_RCR_RCOMPAND_DEFAULT,
                              MCBSP_RCR_RFIG_DEFAULT,
                              MCBSP_RCR_RDATDLY_1BIT,
                              MCBSP_RCR_RFRLEN1_OF( 0 ),
                              MCBSP_RCR_RWDLEN1_8BIT,
                              MCBSP_RCR_RWDREVRS_DEFAULT
                            );

    config.xcr = MCBSP_XCR_RMK( MCBSP_XCR_XPHASE_SINGLE,
                              MCBSP_XCR_XFRLEN2_OF( 0 ),
                              MCBSP_XCR_XWDLEN2_8BIT,
                              MCBSP_XCR_XCOMPAND_DEFAULT,
                              MCBSP_XCR_XFIG_DEFAULT,
                              MCBSP_XCR_XDATDLY_1BIT,
                              MCBSP_XCR_XFRLEN1_OF( 0 ),
                              MCBSP_XCR_XWDLEN1_8BIT,
                              MCBSP_XCR_XWDREVRS_DEFAULT
                            );

    config.srgr = MCBSP_SRGR_RMK( MCBSP_SRGR_GSYNC_FREE,
                                MCBSP_SRGR_CLKSP_RISING,
                                MCBSP_SRGR_CLKSM_CLKS,
                                MCBSP_SRGR_FSGM_DXR2XSR,
                                MCBSP_SRGR_FPER_DEFAULT,
                                MCBSP_SRGR_FWID_DEFAULT,
                                MCBSP_SRGR_CLKGDV_OF( 30 )
                              );

    config.spcr = MCBSP_SPCR_RMK( MCBSP_SPCR_FREE_YES,
                               MCBSP_SPCR_SOFT_YES,
                               MCBSP_SPCR_FRST_0,
                               MCBSP_SPCR_GRST_0,
                               MCBSP_SPCR_XINTM_XRDY,
                               MCBSP_SPCR_XSYNCERR_0,
                               MCBSP_SPCR_XRST_DEFAULT,
                               MCBSP_SPCR_DLB_OFF,
                               MCBSP_SPCR_RJUST_RZF,
                               MCBSP_SPCR_CLKSTP_DELAY,
                               MCBSP_SPCR_DXENA_OFF,
                               MCBSP_SPCR_RINTM_RRDY,
                               MCBSP_SPCR_RSYNCERR_0,
                               MCBSP_SPCR_RRST_0
                             );

    config.pcr = MCBSP_PCR_RMK( MCBSP_PCR_XIOEN_SP,
                              MCBSP_PCR_RIOEN_SP,
                              MCBSP_PCR_FSXM_INTERNAL,
                              MCBSP_PCR_FSRM_EXTERNAL,
                              MCBSP_PCR_CLKXM_OUTPUT,
                              MCBSP_PCR_CLKRM_INPUT,
                              MCBSP_PCR_CLKSSTAT_0,
                              MCBSP_PCR_DXSTAT_0,
                              MCBSP_PCR_FSXP_ACTIVEHIGH,
                              MCBSP_PCR_FSRP_ACTIVEHIGH,
                              MCBSP_PCR_CLKXP_FALLING,
                              MCBSP_PCR_CLKRP_RISING
                            );

    MCBSP_config( hMcbsp, &config );
    MCBSP_start( hMcbsp, MCBSP_SRGR_START | MCBSP_RCV_START | MCBSP_XMIT_START, 5 );

    return hMcbsp;
}
//----------------------------------------------------------------------
uint8 spi_rw( MCBSP_Handle hMcbsp, uint8* data, uint32 time )
{
    syn_begin();
    MCBSP_resetXmt( hMcbsp );
    MCBSP_gpio( hMcbsp );
    sleep_u( time );
    MCBSP_spi( hMcbsp );
    MCBSP_enableXmt( hMcbsp );
    while( !MCBSP_xrdy( hMcbsp ) );
    MCBSP_write( hMcbsp, *data );
    while( !MCBSP_rrdy( hMcbsp ) );
    uint8 temp = MCBSP_read( hMcbsp );
    syn_end();
    return ~temp;
}
//----------------------------------------------------------------------
void k0k1_write( MCBSP_Handle hMcbsp, uint8* data )
{
    uint8* ptr = data;
    uint8 command = SPI_WRITE_BUFFER;
    spi_rw( hMcbsp, &command, DELAY_WAKEUP );
    for( uint32 i = 0; i < K0K1_WRITE_SIZE; i++ )
    {
        spi_rw( hMcbsp, ptr++, DELAY_STREAM );
    }
}
//----------------------------------------------------------------------
void k0_read( MCBSP_Handle hMcbsp, uint8* data )
{
    uint8* ptr = data;
    uint8 command = SPI_READ_BUFFER;
    spi_rw( hMcbsp, &command, DELAY_WAKEUP );
    command = 0;
    for( uint32 i = 0; i < K0_READ_SIZE; i++ )
    {
        *ptr++ = spi_rw( hMcbsp, &command, DELAY_STREAM );
    }
}
//----------------------------------------------------------------------
void crc_read( MCBSP_Handle hMcbsp, uint8* data )
{
    uint8* ptr = data;
    uint8 command = DAT_CRC;
    spi_rw( hMcbsp, &command, DELAY_WAKEUP );
    sleep_m( 1600 );
    command = 0;
    for( uint32 i = 0; i < CRC_READ_SIZE; i++ )
    {
        *ptr++ = spi_rw( hMcbsp, &command, DELAY_WAKEUP );
    }
}
//----------------------------------------------------------------------
void magic_read( MCBSP_Handle hMcbsp, uint8* data )
{
    uint8* ptr = data;
    uint8 command = MAGIC_READ;
    spi_rw( hMcbsp, &command, DELAY_WAKEUP );
    command = 0;
    for( uint32 i = 0; i < MAGIC_SIZE; i++ )
    {
        *ptr++ = spi_rw( hMcbsp, &command, DELAY_STREAM );
    }
}
//----------------------------------------------------------------------
void lux_read( MCBSP_Handle hMcbsp, uint8* data )
{
    uint8* ptr = data;
    uint8 command = LUX_READ;
    spi_rw( hMcbsp, &command, DELAY_WAKEUP );
    command = 0;
    for( uint32 i = 0; i < LUX_SIZE; i++ )
    {
        *ptr++ = spi_rw( hMcbsp, &command, DELAY_STREAM );
    }
}
//----------------------------------------------------------------------
//----------------------------------------------------------------------
























