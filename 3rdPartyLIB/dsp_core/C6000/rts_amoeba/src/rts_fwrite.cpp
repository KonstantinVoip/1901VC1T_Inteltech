// ---------------------------------------------------------------------------
// size_t fwrite( const void* buf, size_t l, size_t b, FILE* d )
// ---------------------------------------------------------------------------
#include <rts.h>
#include <os_syscall.h>
// ---------------------------------------------------------------------------
size_t fwrite( const void* buf, size_t l, size_t b, FILE* d )
{
  int32 r;
  if( d == NULL ) return 0;
  d->ungetc_count = 0;
  r = drv_write( d->rid, buf, l * b );
  if( r < 0 ) return 0;
  return r / l;
}
// ---------------------------------------------------------------------------
