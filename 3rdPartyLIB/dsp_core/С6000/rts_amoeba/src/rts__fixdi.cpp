// ---------------------------------------------------------------------------
// extern "C" int _fixdi( double x )
// ---------------------------------------------------------------------------
#include <rts_real_d.h>
#include <rts.h>
// ---------------------------------------------------------------------------
extern "C" int FIXFI( REAL x )
{ 
  int rslt;
  int rexp;
  REAL_2UNS xx;

  xx.r = x;
  if( ( rexp = ( xx.u.msh >> REAL_FRC_MSBs ) & MASK( 11 ) ) == 0 ) return 0;
  rexp = 1023 + 32 - 1 - rexp;

  if( rexp <= 0 )
  {
    rslt = INT_MAX ;
    if( xx.u.msh & MINUS ) rslt = INT_MIN ;
    return rslt;
  }

  if( rexp >= 32 ) return 0;

  rslt = ( ( (unsigned)( ( xx.u.msh & REAL_FRC_MASK ) + REAL_HIDDEN_BIT ) << ( 32 - REAL_FRC_MSBs - 1 ) ) + ( (unsigned)( xx.u.lsh >> REAL_FRC_MSBs + 1 ) ) ) >> rexp;
  if( xx.u.msh & MINUS ) rslt = -rslt;

  return rslt;
}
// ---------------------------------------------------------------------------
