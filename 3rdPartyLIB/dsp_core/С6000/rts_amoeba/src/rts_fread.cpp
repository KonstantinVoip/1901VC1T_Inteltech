// ---------------------------------------------------------------------------
// size_t fread( void* buf, size_t l, size_t b, FILE* d )
// ---------------------------------------------------------------------------
#include <rts.h>
#include <os_syscall.h>
// ---------------------------------------------------------------------------
size_t fread( void* buf, size_t l, size_t b, FILE* d )
{
  int32 r = 0;
  int32 cb, off;
  if( d == NULL ) return 0;
  cb = l * b;
  if( cb == 0 ) return 0;
  off = 0;
  while( d->ungetc_count )
  {
    d->ungetc_count--;
    (*( (uint8*)buf + off )) = d->ungetc_buf[d->ungetc_count];
    r++;
    if( r == cb ) return b;
  }
  int32 tr = drv_read( d->rid, (void*)( (char*)buf + off ), cb - off );
  if( tr < 0 ) return 0;
  return ( r + tr ) / l;
}
// ---------------------------------------------------------------------------
