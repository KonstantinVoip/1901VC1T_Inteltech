// ---------------------------------------------------------------------------
// char *strncpy( register char* dest, register const char* src, register size_t n )
// ---------------------------------------------------------------------------
#include <rts.h>
// ---------------------------------------------------------------------------
char* strncpy( register char* dest, register const char* src, register size_t n )
{
  if( n ) 
  {
    register char* d = dest - 1;
    register const char* s = src - 1;
    while( ( *++d = *++s ) && --n );
    if( n-- > 1 ) do *++d = '\0'; while( --n );
  }
  return dest;
}
// ---------------------------------------------------------------------------
