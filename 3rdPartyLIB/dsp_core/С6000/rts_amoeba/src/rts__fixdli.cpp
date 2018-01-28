// ---------------------------------------------------------------------------
// extern "C" int _fixdi( double x )
// ---------------------------------------------------------------------------
#include <rts_real_d.h>
#include <rts.h>
// ---------------------------------------------------------------------------
extern "C" long FIXFLI( REAL x )
{ 
  long rslt;
  int rexp;
  REAL_2UNS xx;

  xx.r = x;
  if( ( rexp = ( xx.u.msh >> REAL_FRC_MSBs ) & MASK( 11 ) ) == 0 ) return 0;

  rexp = 1023 + 40 - 1 - rexp;
  if( rexp <= 0 )
  {
    rslt = LONG_MAX;
    if( xx.u.msh & MINUS ) rslt = LONG_MIN;
    return rslt;
  }
  if( rexp >= 40 ) return 0;

  rslt = ( ( (unsigned long)( ( xx.u.msh & REAL_FRC_MASK ) + REAL_HIDDEN_BIT ) << ( 40 - REAL_FRC_MSBs - 1 ) ) + ( (unsigned long)( xx.u.lsh >> ( REAL_FRC_BITS % BPlong ) + 1 ) ) ) >> rexp;
  if( xx.u.msh & MINUS ) rslt = -rslt;

  return rslt;
}
// ---------------------------------------------------------------------------
