#ifndef __DRV_InterProcessorMessagePipe_MCBSP_H__
#define __DRV_InterProcessorMessagePipe_MCBSP_H__

#include <os.h>

#ifndef IPMP_SET_SYNFAIL_CALLBACK
#  define IPMP_SET_SYNFAIL_CALLBACK     ( IPMP__USER__ + 8 )
#endif
#ifndef IPMP_SPTEST
#  define IPMP_SPTEST                   ( IPMP__USER__ + 9 )
#endif

typedef struct _ipmp_frame_hdr
{
uint32 frame;
uint32 from;
uint32 to;
uint32 length;
uint32 crc32;
}ipmp_frame_hdr;

//#define FRAME_LENGTH                     2048//1056//1024+32(data+hdr)
#define FRAME_LENGTH                     256

extern int32 drv_ipmp_mcbsp_plug( const char* path );
extern int32 drv_ipmp_mcbsp_unplug( const char* name );

#endif
