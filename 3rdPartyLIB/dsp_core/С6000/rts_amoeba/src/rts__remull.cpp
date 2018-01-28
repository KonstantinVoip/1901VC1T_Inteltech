// ---------------------------------------------------------------------------
// extern "C" unsigned long long _remull( unsigned long long a, unsigned long long b )
// ---------------------------------------------------------------------------
#include <rts.h>
// ---------------------------------------------------------------------------
extern "C" unsigned long long _divull(unsigned long long x1, unsigned long long x2 );
// ---------------------------------------------------------------------------
extern "C" unsigned long long _remull( unsigned long long a, unsigned long long b )
{
  return a - _divull( a, b ) * b;
}
// ---------------------------------------------------------------------------
