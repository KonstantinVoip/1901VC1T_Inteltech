// ---------------------------------------------------------------------------
// int mkdir( const char* path, mode_t mode )
// ---------------------------------------------------------------------------
#include <rts.h>
// ---------------------------------------------------------------------------
int mkdir( const char* path, mode_t mode )
{
  int32 i, r;
  uint32 d;
  char* t;

  if( path == NULL ) return -1;
  for( i = strlen(path) - 1; i >= 0; i-- ) if( ( path[i] == '/' ) || ( path[i] == '\\' ) ) break;
  if( i == -1 ) return -1;
  t = (char*)heap_alloc( NULL, i + 1, HEAP_ALIGN_4 );
  if( t == NULL ) return -1;
  memcpy( t, path, i );
  t[i] = 0;
  d = drv_mkd( t );
  heap_free( NULL, t );
  if( d == RES_VOID ) return -1;
  r = drv_create( d, path + i + 1, INOT_FOLDER );
  drv_rmd( d );

  return ( r == OSE_OK ) ? 0 : -1;
}
// ---------------------------------------------------------------------------
