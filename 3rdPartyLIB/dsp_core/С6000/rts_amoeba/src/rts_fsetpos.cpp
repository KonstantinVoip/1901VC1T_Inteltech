// ---------------------------------------------------------------------------
// int fsetpos( FILE* d, const int64* offset )
// ---------------------------------------------------------------------------
#include <os_syscall.h>
#include <rts.h>
// ---------------------------------------------------------------------------
int fsetpos( FILE* d, const int64* offset )
{
  if( d == NULL ) return -2;
  if( offset == NULL ) return -1;
  d->ungetc_count = 0;
  if( drv_ioctl( d->rid, IOC_SEEK, offset ) != OSE_OK ) return -2;
  return 0;
}
// ---------------------------------------------------------------------------
