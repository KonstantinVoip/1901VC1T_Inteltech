// ---------------------------------------------------------------------------
// int rmdir( const char* path )
// ---------------------------------------------------------------------------
#include <rts.h>
// ---------------------------------------------------------------------------
int rmdir( const char* path )
{
  int32 r, l;
  if( path == NULL ) { errno = EINVAL; return -1; }
  l = strlen( path );
  if( ( path[l-1] == '/' ) || ( path[l-1] == '\\' ) ) { errno = EINVAL; return -1; }
  uint32 d = drv_mkd( path );
  if( d == RES_VOID ) { errno = ENOENT; return -1; }
  r = drv_select( d, ".." );
  if( r != OSE_OK ) { drv_rmd( d ); errno = EIO; return -1; }
  for( r = l - 1; r >= 0; r-- ) if( ( path[r] == '/' ) || ( path[r] == '\\' ) ) break;
  if( r == -1 ) { drv_rmd( d ); errno = EINVAL; return -1; }
  r = drv_remove( d, ( const_cast<char*>( path ) + r + 1 ) );
  drv_rmd( d );
  if( r != OSE_OK ) { errno = EIO; return -1; }
  return 0;
}
// ---------------------------------------------------------------------------
