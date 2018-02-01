// ---------------------------------------------------------------------------
// int remove( const char* _file )
// ---------------------------------------------------------------------------
#include <os.h>
#include <rts.h>
// ---------------------------------------------------------------------------
int remove( const char* _file )
{
  int32 r, l;
  if( _file == NULL ) { errno = EINVAL; return -1; }
  l = strlen( _file );
  if( ( _file[l-1] == '/' ) || ( _file[l-1] == '\\' ) ) { errno = EINVAL; return -1; }
  uint32 d = drv_mkd( _file );
  if( d == RES_VOID ) { errno = ENOENT; return -1; }
  r = drv_select( d, ".." );
  if( r != OSE_OK ) { drv_rmd( d ); errno = EIO; return -1; }
  for( r = l - 1; r >= 0; r-- ) if( ( _file[r] == '/' ) || ( _file[r] == '\\' ) ) break;
  if( r == -1 ) { drv_rmd( d ); errno = EINVAL; return -1; }
  r = drv_remove( d, ( const_cast<char*>( _file ) + r + 1 ) );
  drv_rmd( d );
  if( r != OSE_OK ) { errno = EIO; return -1; }
  return 0;
}
// ---------------------------------------------------------------------------
