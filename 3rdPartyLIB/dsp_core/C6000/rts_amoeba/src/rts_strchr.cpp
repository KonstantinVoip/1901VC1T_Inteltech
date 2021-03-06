// ---------------------------------------------------------------------------
// char* strchr( const char* string, int c )
// ---------------------------------------------------------------------------
#include <rts.h>
// ---------------------------------------------------------------------------
char* strchr( const char* string, int c )
{
  char tch, ch = c;
  const char* s = string - 1;
  for( ; ; )
  {
    if( ( tch = *++s ) == ch ) return (char *)s;
    if( !tch ) return (char *)0;
  }
}
// ---------------------------------------------------------------------------
