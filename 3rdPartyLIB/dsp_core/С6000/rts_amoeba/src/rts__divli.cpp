// ---------------------------------------------------------------------------
// extern "C" long _divli( long a, long b )
// ---------------------------------------------------------------------------
#include <rts.h>
#include <limits.h>
// ---------------------------------------------------------------------------
extern "C" unsigned long _divul( unsigned long x1, unsigned long x2 );
// ---------------------------------------------------------------------------
extern "C" long _divli( long a, long b )
{
  long sign = ( a ^ b ) >> 39;
  unsigned long ua = ( a == LONG_MIN ? a : labs( a ) );
  unsigned long ub = ( b == LONG_MIN ? b : labs( b ) );
  unsigned long q = _divul( ua, ub );
  if( b == 0 ) return a ? ( ( (unsigned long) - 1 ) >> 1 ) ^ sign : 0;
  return sign ? -q : q;
}
// ---------------------------------------------------------------------------
