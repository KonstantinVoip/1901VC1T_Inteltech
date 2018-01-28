// ---------------------------------------------------------------------------
// int fgetpos( FILE* d, int64* offset )
// ---------------------------------------------------------------------------
#include <os_syscall.h>
#include <rts.h>
// ---------------------------------------------------------------------------
int fgetpos( FILE* d, int64* offset )
{
  if( d == NULL ) return -2;
  if( offset == NULL ) return -1;
  if( drv_ioctl( d->rid, IOC_POSITION, offset ) != OSE_OK ) return -2;
  return 0;
}
// ---------------------------------------------------------------------------
