// ---------------------------------------------------------------------------
// int fseek( FILE* d, int32 offset, int whence )
// ---------------------------------------------------------------------------
#include <os_syscall.h>
#include <rts.h>
// ---------------------------------------------------------------------------
int fseek( FILE* d, int32 offset, int whence )
{
  int64 off;

  if( d == NULL ) return -1;

  d->ungetc_count = 0;

  switch( whence )
  {
    case SEEK_SET: off = (int64)offset; break;

    case SEEK_CUR:
    {
      int64 r;
      if( drv_ioctl( d->rid, IOC_POSITION, &r ) != OSE_OK ) return -1;
      off = r + (int64)offset;
    }
    break;
    
    case SEEK_END:
    {
      int64 r;
      if( drv_ioctl( d->rid, IOC_SIZE, &r ) != OSE_OK ) return -1;
      off = r + (int64)offset;
    }
    break;
  }

  if( drv_ioctl( d->rid, IOC_SEEK, &off ) != OSE_OK ) return -1;

  return 0;
}
// ---------------------------------------------------------------------------
