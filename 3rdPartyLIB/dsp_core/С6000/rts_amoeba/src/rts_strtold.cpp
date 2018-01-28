// ---------------------------------------------------------------------------
// long double strtold( const char* st, char** endptr )
// ---------------------------------------------------------------------------
#include <limits.h>
#include <float.h>
#include <math.h>
#include <rts.h>
// ---------------------------------------------------------------------------

#if( LDBL_MAX_10_EXP >= 256 )
static const long double powerof10[] = { 1.e1, 1.e2, 1.e4, 1.e8, 1.e16, 1.e32, 1.e64L, 1.e128L, 1.e256L };
#else                       
static const long double powerof10[] = { 1.e1, 1.e2, 1.e4, 1.e8, 1.e16, 1.e32 };
#endif

static const double digits[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

// ---------------------------------------------------------------------------
extern "C" long double strtold( const char* st, char** endptr )
{
  long double result = 0;
  char cp;
  const char* fst = st;
  int exp = 0;
  int count;
  int value = 0;
  int sign;
  int plus_or_minus = 0;

  while( isspace( (*fst) ) ) ++fst;

  if( ( sign = ( ( cp = (*fst) ) == '-' ) ) || ( cp == '+' ) )
  {
    ++fst;
    value = 1;
  }

  for( ; isdigit( cp = (*fst) ); ++fst )
  {
    result = result * 10 + digits[cp-'0']; 
    value = 1;
  }

  if( cp == '.' )
  {
    while( isdigit( cp = *++fst ) )
    {
      result = result * 10 + digits[cp-'0']; 
      value = 1;
      --exp;
    }
  }

  if( sign ) result = -result;

  if( value && toupper( (*fst) ) == 'E' )
  {
    if( ( sign = ( ( cp = *++fst ) == '-' ) ) || ( cp == '+' ) )
    {
      cp = *++fst;
      plus_or_minus = 1;
    }

    if( !isdigit( cp ) )
    {
      if( plus_or_minus ) *--fst;
      *--fst;
      goto skip_loop;
    }

    for( count = 0; isdigit( cp ); cp = *++fst )
    {
      if( ( ( INT_MAX - abs( exp ) - ( cp - '0' ) ) / 10 ) > count)
      {
        count *= 10; 
        count += cp - '0';
      }
      else
      {
        count = INT_MAX - exp;
        break;
      }
    }

  skip_loop:

    if( sign ) exp -= count; else exp += count;
  }

  if( result != 0.0 )
  {
    if( exp > LDBL_MAX_10_EXP )
    {
      errno = ERANGE;
      result = ( result < 0 ) ? -HUGE_VALL : HUGE_VALL;
    }
    else if( exp < LDBL_MIN_10_EXP )
    {
      errno = ERANGE;
      result = 0.0;
    }
    else if( exp < 0 )
    {
      for( count = 0, exp = -exp; exp; count++, exp >>= 1 )
      {
        if( exp & 1 ) result /= powerof10[count];
      }
    }
    else
    {
      for( count = 0; exp; count++, exp >>= 1 )
      {
        if( exp & 1 ) result *= powerof10[count];
      }
    }
  }

  if( endptr ) (*endptr) = (char*)( value ? fst : st );

  return result;
}
// ---------------------------------------------------------------------------
