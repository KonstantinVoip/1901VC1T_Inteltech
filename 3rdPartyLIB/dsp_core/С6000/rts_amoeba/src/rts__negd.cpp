// ---------------------------------------------------------------------------
// extern "C" double _negd( double x )
// ---------------------------------------------------------------------------
#include <rts_real_d.h>
#include <rts.h>
// ---------------------------------------------------------------------------
extern "C" REAL NEGF( REAL x )
{
  MSC( x ) ^= 0x80;
  return x;
}
// ---------------------------------------------------------------------------
