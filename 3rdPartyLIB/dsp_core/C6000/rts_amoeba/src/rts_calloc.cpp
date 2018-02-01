// ---------------------------------------------------------------------------
// extern void* calloc( size_t num, size_t size )
// ---------------------------------------------------------------------------
#include <rts.h>
#include <os_types.h>
// ---------------------------------------------------------------------------
void* calloc( size_t num, size_t size )
{
  size_t bs = num * size;
  void* res = malloc( bs );
  if( res == NULL ) return NULL;
  uint8* u8 = (uint8*)res;
  while( bs-- ) *u8++ = 0;
  return res;
}
// ---------------------------------------------------------------------------
