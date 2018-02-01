// ---------------------------------------------------------------------------
// int stat( const char* path, stat* buf )
// ---------------------------------------------------------------------------
#include <rts.h>
// ---------------------------------------------------------------------------
int stat( const char* path, struct stat* buf )
{
  uint32 d;
  uint64 dsize;
  int r = 0;
  
  if( path == NULL ) { errno = ENOENT; return -1; }
  if( buf == NULL ) { errno = EINVAL; return -1; }

  memset( buf, 0, sizeof(struct stat) );

  d = drv_mkd( path );
  if( d == RES_VOID ) { errno = ENOENT; return -1; }

  if( drv_ioctl( d, IOC_SIZE, &dsize ) == OSE_OK )
  {
    if( dsize >= 4294967296llu ) { errno = EOVERFLOW; goto l_fail; }
    buf->st_size = (uint32)dsize;
  }

l_fail:

  drv_rmd( d );

  return r;
}
// ---------------------------------------------------------------------------
