// ---------------------------------------------------------------------------
// int strncmp( const char* string1, const char* string2, size_t n )
// ---------------------------------------------------------------------------
#include <rts.h>
// ---------------------------------------------------------------------------
int strncmp( const char* string1, const char* string2, size_t n )
{
  if( n ) 
  {
    const char* s1 = string1 - 1;
    const char* s2 = string2 - 1;
    char cp;
    int result;
    do
    { 
      if( result = *++s1 - ( cp = *++s2 ) ) return result;
    }
    while( cp && --n );
  }
  return 0;
}
// ---------------------------------------------------------------------------
