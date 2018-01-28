// ---------------------------------------------------------------------------
// long long strtoll( const char* st, char** endptr, int base )
// ---------------------------------------------------------------------------
#include <limits.h>
#include <rts.h>
// ---------------------------------------------------------------------------
extern "C" long long strtoll( const char* st, char** endptr, int base )
{
  register long long result = 0;
  register char cp;
  register const char* fst = st;
  int digits = 0;
  int sign;

  while( isspace( (*fst) ) ) ++fst;

  if( sign = ( ( cp = (*fst) ) == '-' ) ) cp = *++fst; else if( cp == '+' ) cp = *++fst;

  if( base > 36 ) base = 0;

  switch( base )
  {
    case 0:
    {
      if( cp != '0' )
      {
        base = 10;
      }
      else if( ( ( cp = *++fst ) == 'x' ) || ( cp == 'X' ) )
      {
        if( isxdigit( fst[1] ) )
        {
          base = 16;
          cp = *++fst;
        }
        else
        {
          base = 10;
          cp = *--fst;
        }
      }
      else 
      {
        base = 8; 
        if( ( cp < '0' ) || ( cp > '7' ) ) cp = *--fst;
      } 
    }
    break;

    case 16:
    {
      if( ( cp == '0' ) && ( ( fst[1] == 'x' ) || ( fst[1] == 'X' ) ) && isxdigit( cp ) ) cp = *( fst += 2 );
    }
    break;
  }

  for (;; cp = *++fst)
  {
    register long long addval;

    if( !( ( isdigit( cp ) && ( addval = cp - '0' ) < base ) ||
           ( isupper( cp ) && ( addval = cp - 'A' + 10 ) < base ) ||
           ( islower( cp ) && ( addval = cp - 'a' + 10 ) < base ) ) ) break;

    if( result == ( addval = ( result * base + addval ) ) / base )
    {
      result = addval;
    }
    else
    {   
      errno = ERANGE;
      if( endptr ) (*endptr) = (char*)st; 
      return sign ? LLONG_MIN : LLONG_MAX; 
    }

    digits++;
  }

  if( endptr ) (*endptr) = (char*)( digits ? fst : st );
  if( sign )
  {
    if( result > LLONG_MAX )
    {
      errno = ERANGE;
      return LLONG_MIN;
    }
    return -result;
  }

  return result;
}
// ---------------------------------------------------------------------------
