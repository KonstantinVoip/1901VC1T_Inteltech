// ---------------------------------------------------------------------------
// int chdir( const char* path )
// ---------------------------------------------------------------------------
#include <rts.h>
// ---------------------------------------------------------------------------
int chdir( const char* path )
{
  if( path == NULL ) return -1;

// -- IT MUST BE DESTROYED -[ OLD FS TRIGGER ]--------------------------------
//  if( path[0] == '!' ) // ----------------------------------------------------
//  { // -----------------------------------------------------------------------
//    return old_chdir( const_cast<char*>( path ) + 1 ); // --------------------
//  } // -----------------------------------------------------------------------
// -- IT MUST BE DESTROYED -[ OLD FS TRIGGER ]--------------------------------

  return -1;
}
// ---------------------------------------------------------------------------
