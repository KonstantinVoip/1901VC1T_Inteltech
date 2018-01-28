// ---------------------------------------------------------------------------
// char *strncat( char *dest, const char *src, register size_t n )
// ---------------------------------------------------------------------------
#include <rts.h>
// ---------------------------------------------------------------------------
char* strncat( char* dest, const char* src, register size_t n )
{
  if( n )
  {
    char* d = dest - 1;
    const char* s = src  - 1;
    while( *++d );
    d--;
    while( n-- ) if( !( *++d = *++s ) ) return dest;
    *++d = 0;
  }
  return dest;
}
// ---------------------------------------------------------------------------
