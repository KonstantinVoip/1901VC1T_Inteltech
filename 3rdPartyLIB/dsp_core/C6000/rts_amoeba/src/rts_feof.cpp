// ---------------------------------------------------------------------------
// int feof( FILE* d )
// ---------------------------------------------------------------------------
#include <os_syscall.h>
#include <rts.h>
// ---------------------------------------------------------------------------
int feof( FILE* d )
{
  int32 r;
  if( d == NULL ) return -1;
  if( drv_ioctl( d->rid, IOC_EOF, &r ) != OSE_OK ) return 0;
  return r;
}
// ---------------------------------------------------------------------------