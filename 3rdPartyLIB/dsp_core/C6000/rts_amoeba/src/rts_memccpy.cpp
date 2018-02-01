// ---------------------------------------------------------------------------
// char* memccpy( char* dest, const char* src, int ch, int cnt )
// ---------------------------------------------------------------------------
#include <rts.h>
// ---------------------------------------------------------------------------
extern "C" char* memccpy( char* dest, const char* src, int ch, int cnt )
{
  if( cnt <= 0 ) return NULL;
  do { if( ( *dest++ = *src++ ) == ch ) return dest; } while ( --cnt != 0 );
  return NULL;
}
// ---------------------------------------------------------------------------
