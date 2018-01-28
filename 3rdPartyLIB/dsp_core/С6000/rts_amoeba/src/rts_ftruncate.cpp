// ---------------------------------------------------------------------------
// int ftruncate( uint32 d, off_t length )
// ---------------------------------------------------------------------------
#include <rts.h>
// ---------------------------------------------------------------------------
int ftruncate( uint32 d, off_t length )
{
  int64 nlen = (int64)length;
  return ( drv_ioctl( d, IOC_RESIZE, &nlen ) == OSE_OK ) ? 0 : -1;
}
// ---------------------------------------------------------------------------
