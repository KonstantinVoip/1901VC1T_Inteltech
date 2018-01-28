// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: all
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp1251
// !: d: .
// !: -: 
// ---------------------------------------------------------------------------
#ifndef __DNSD_H__
#define __DNSD_H__


#include <os_types.h>
#include <os_csl_mcbsp.h>

extern MCBSP_Handle dnsd_hMcbsp;

#define K0K1_WRITE_SIZE    64
#define K0_READ_SIZE       32
#define CRC_READ_SIZE      4
#define MAGIC_SIZE         4
#define LUX_SIZE           2

#define  DAT_CRC           0x71        // Datchik make crc32
#define  MAGIC_READ        0x72        // Magic number
#define  LUX_READ          0x74        // Read lumen
#define  DAT_INIT          0x81        // Datchik init
#define  SPI_WRITE_BUFFER  0x82        // Send a series of bytes from the
                                       // Master to the Slave
#define  SPI_READ_BUFFER   0x84        // Send a series of bytes from the Slave
                                       // to the Master
#define  READ_ADC          0x88        // Battery control
#define  LED_ON            0x8A        // Turn the LED ON for 1 sec
#define  SPI_READ_0A5      0x8B        // Read constant 0xA5



#define DNSD_PlateLED_ON                ( DNSD__USER__ + 1 )
#define DNSD_PlateLED_OFF               ( DNSD__USER__ + 2 )

#define DNSD_K0K1_WRITE                 ( DNSD__USER__ + SPI_WRITE_BUFFER )
#define DNSD_K0_READ                    ( DNSD__USER__ + SPI_READ_BUFFER )
#define DNSD_INIT                       ( DNSD__USER__ + DAT_INIT )
#define DNSD_READ_ADC                   ( DNSD__USER__ + READ_ADC )
#define DNSD_LED_ON                     ( DNSD__USER__ + LED_ON )
#define DNSD_READ_CRC                   ( DNSD__USER__ + DAT_CRC )
#define DNSD_READ_0A5                   ( DNSD__USER__ + SPI_READ_0A5 )
#define DNSD_MAGIC                      ( DNSD__USER__ + MAGIC_READ )
#define DNSD_LUX                        ( DNSD__USER__ + LUX_READ )



int32 drv_dnsd_plug( const char* path );
int32 drv_dnsd_unplug( const char* name );

#endif




