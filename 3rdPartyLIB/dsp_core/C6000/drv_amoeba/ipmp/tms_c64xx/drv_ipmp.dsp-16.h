#ifndef __DRV_InterProcessor_Message_Pipe_DOZU_Serial_Port_16_H__
#define __DRV_InterProcessor_Message_Pipe_DOZU_Serial_Port_16_H__

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

#define IPMP_DSP16_CH_FIRST     1
#define IPMP_DSP16_CH_SECOND    2
#define IPMP_DSP16_CH_BOTH      3

// -- Function prototypes ----------------------------------------------------

extern int32 drv_ipmp_dsp16_plug( const char* path, uint32 v );
extern int32 drv_ipmp_dsp16_unplug( const char* name );

#endif
