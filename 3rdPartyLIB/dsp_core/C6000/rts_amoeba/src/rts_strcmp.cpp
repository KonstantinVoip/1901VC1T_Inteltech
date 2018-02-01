// ---------------------------------------------------------------------------
// int strcmp( register const char* string1, register const char* string2 )
// ---------------------------------------------------------------------------
#include <rts.h>
// ---------------------------------------------------------------------------
int strcmp( register const char* string1, register const char* string2 )
{
  register int c1, res;
  for( ; ; )
  {
    c1 = *string1++;
    res = c1 - *string2++;
    if( ( c1 == 0 ) || ( res != 0 ) ) break;
  }
  return res;
}
// ---------------------------------------------------------------------------
