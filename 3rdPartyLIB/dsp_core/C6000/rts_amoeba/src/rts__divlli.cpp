// ---------------------------------------------------------------------------
// extern "C" long long _divlli( long long a, long long b )
// ---------------------------------------------------------------------------
#include <rts.h>
#include <limits.h>
// ---------------------------------------------------------------------------
extern "C" unsigned long long _divull( unsigned long long a, unsigned long long b );
// ---------------------------------------------------------------------------
extern "C" long long _divlli( long long a, long long b )
{
  long long sign = ( a ^ b ) >> 63;
  unsigned long long ua = ( a == LLONG_MIN ? a : llabs( a ) );
  unsigned long long ub = ( b == LLONG_MIN ? b : llabs( b ) );
  unsigned long long q = _divull( ua, ub );
  if( b == 0 ) return a ? ( ( (unsigned long long) - 1 ) >> 1 ) ^ sign : 0;
  return sign ? -q : q;
}
// ---------------------------------------------------------------------------
