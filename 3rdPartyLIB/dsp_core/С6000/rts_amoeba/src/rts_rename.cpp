// ---------------------------------------------------------------------------
// int rename( const char* o_name, const char* nname )
// ---------------------------------------------------------------------------
#include <rts.h>
// ---------------------------------------------------------------------------
int rename( const char* o_name, const char* n_name )
{
  uint32 d;
  int32 r;
  if( ( o_name == NULL ) || ( n_name == NULL ) ) return -1;
  d = drv_mkd( o_name );
  if( d == RES_VOID ) return -1;
  r = drv_rename( d, n_name );
  drv_rmd( d );
  return ( r == OSE_OK ) ? 0 : -1;
}
// ---------------------------------------------------------------------------
