#ifndef __DRV_InterProcessor_Message_Pipe_DOZU_Serial_Port_E65_H__
#define __DRV_InterProcessor_Message_Pipe_DOZU_Serial_Port_E65_H__

#include <os_types.h>

// -- Additional commands ----------------------------------------------------

#define IPMP_NUMBER             ( IPMP__USER__ + 0 )
#define IPMP_PAUSE              ( IPMP__USER__ + 1 )
#define IPMP_CONTINUE           ( IPMP__USER__ + 2 )
#define IPMP_LOAD_PLIS          ( IPMP__USER__ + 3 )

#ifndef IPMP_SET_SYNFAIL_CALLBACK
#  define IPMP_SET_SYNFAIL_CALLBACK     ( IPMP__USER__ + 8 )
#endif
#ifndef IPMP_SPTEST
#  define IPMP_SPTEST                   ( IPMP__USER__ + 9 )
#endif

// -- Definitions ------------------------------------------------------------

//#define ADR_M_DEVINDEX          0xa0000ffc

#define ADR_M_CONST_PORT0       0xA0000FF8
#define ADR_M_CONST_PORT1       0xA0001FF8

#define ADR_M_WFLAG_PORT0       0xA0000FC0//(3f6<<2)
#define ADR_M_WFLAG_PORT1       0xA0001FC0//(7f6<<2)

#define ADR_M_RFLAG_PORT0       0xA0000FC4//(3fd<<2)
#define ADR_M_RFLAG_PORT1       0xA0001FC4//(7fd<<2)

#define ADR_M_TX_PORT0          0xA0000FC8//(3fe<<2)
#define ADR_M_TX_PORT1          0xA0001FC8//(7fe<<2)

#define ADR_M_RX_PORT0          0xA0000FCC//(3ff<<2)
#define ADR_M_RX_PORT1          0xA0001FCC//(7ff<<2)


#define ADR_C_CONST_PORT0       0xA0001ff8
#define ADR_C_CONST_PORT1       0xB0001ff8

#define ADR_C_RRFLAG_PORT0      0xA0001FC0//(3f6<<2)
#define ADR_C_RRFLAG_PORT1      0xB0001FC0//(3f6<<2)
#define ADR_C_WRFLAG_PORT       0x80001FC0//(3f6<<2)                         

#define ADR_C_RWFLAG_PORT0      0xA0001FC4//(3fd<<2)
#define ADR_C_RWFLAG_PORT1      0xB0001FC4//(3fd<<2)
#define ADR_C_WWFLAG_PORT       0x80001FC4//(3fd<<2)

#define ADR_C_RX0_PORT          0xA0001FC8//(3fe<<2)
#define ADR_C_RX1_PORT          0xB0001FC8//(3fe<<2)

#define ADR_C_TX_PORT           0x80001FCC//(3ff<<2)

//------------------------------------------------------------------------
//------------------------------------------------------------------------
//#define REG_M_DEVINDEX          (*(volatile uint32*)ADR_M_DEVINDEX)

#define REG_M_CONST_PORT0       (*(volatile uint64*)ADR_M_CONST_PORT0)
#define REG_M_CONST_PORT1       (*(volatile uint64*)ADR_M_CONST_PORT1)

#define REG_M_WFLAG_PORT0       (*(volatile uint32*)ADR_M_WFLAG_PORT0)
#define REG_M_WFLAG_PORT1       (*(volatile uint32*)ADR_M_WFLAG_PORT1)

#define REG_M_RFLAG_PORT0       (*(volatile uint32*)ADR_M_RFLAG_PORT0)
#define REG_M_RFLAG_PORT1       (*(volatile uint32*)ADR_M_RFLAG_PORT1)

#define REG_M_TX_PORT0          (*(volatile uint32*)ADR_M_TX_PORT0)
#define REG_M_TX_PORT1          (*(volatile uint32*)ADR_M_TX_PORT1)

#define REG_M_RX_PORT0          (*(volatile uint32*)ADR_M_RX_PORT0)
#define REG_M_RX_PORT1          (*(volatile uint32*)ADR_M_RX_PORT1)


#define REG_C_CONST_PORT0       (*(volatile uint64*)ADR_C_CONST_PORT0)
#define REG_C_CONST_PORT1       (*(volatile uint64*)ADR_C_CONST_PORT1)

#define REG_C_RRFLAG_PORT0      (*(volatile uint32*)ADR_C_RRFLAG_PORT0)
#define REG_C_RRFLAG_PORT1      (*(volatile uint32*)ADR_C_RRFLAG_PORT1)
#define REG_C_WRFLAG_PORT       (*(volatile uint32*)ADR_C_WRFLAG_PORT)                                                                    

#define REG_C_RWFLAG_PORT0      (*(volatile uint32*)ADR_C_RWFLAG_PORT0)
#define REG_C_RWFLAG_PORT1      (*(volatile uint32*)ADR_C_RWFLAG_PORT1)
#define REG_C_WWFLAG_PORT       (*(volatile uint32*)ADR_C_WWFLAG_PORT) 
                                                                      
#define REG_C_RX0_PORT          (*(volatile uint32*)ADR_C_RX0_PORT)    
#define REG_C_RX1_PORT          (*(volatile uint32*)ADR_C_RX1_PORT)    
                                                                      
#define REG_C_TX_PORT           (*(volatile uint32*)ADR_C_TX_PORT)     


#define F_M_TXR                 0x00000000
#define F_M_RXR                 0x00000001

#define F_C_TXR                 0x00000001
#define F_C_RXR                 0x00000001

#define PLIS_LOAD_DEFAULT       0x00000000
#define PLIS_LOAD_FWMEM         0x00000001
#define PLIS_LOAD_USBMSD        0x00000002

// -- Function prototypes ----------------------------------------------------

extern int32 drv_ipmp_dspE65_plug( const char* path );
extern int32 drv_ipmp_dspE65_plug( const char* path, uint32 plis_load );
extern int32 drv_ipmp_dspE65_plug( const char* path, uint32 i0_d, uint32 i1_d );
extern int32 drv_ipmp_dspE65_unplug( const char* name );

#endif
