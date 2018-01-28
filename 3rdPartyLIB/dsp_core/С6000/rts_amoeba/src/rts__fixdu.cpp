// ---------------------------------------------------------------------------
// extern "C" unsigned int _fixdu( double x )
// ---------------------------------------------------------------------------
#include <rts_real_d.h>
#include <rts.h>
// ---------------------------------------------------------------------------
extern "C" unsigned int FIXFU( REAL x )
{ 
  unsigned int rslt; int rexp;
  REAL_2UNS xx;

  xx.r = x;
  if( ( rexp = ( xx.u.msh >> REAL_FRC_MSBs ) & MASK( 11 ) ) == 0 ) return 0;
  rexp = 1023 + 32 - 1 - rexp;
  if( rexp < 0 )
  {
    if( xx.u.msh & MINUS ) return (unsigned int)INT_MIN;
    return UINT_MAX;
  }
  if( rexp >= 32 ) return 0;
  rslt = ( ( (unsigned int)( ( xx.u.msh & REAL_FRC_MASK ) + REAL_HIDDEN_BIT ) << ( 32 - REAL_FRC_MSBs - 1 ) ) + ( (unsigned int)( xx.u.lsh >> REAL_FRC_MSBs + 1 ) ) ) >> rexp;
  if( xx.u.msh & MINUS ) rslt = ( ( (int)rslt ) < 0 ) ? (unsigned int)INT_MIN : -rslt;
 
  return rslt;
}
// ---------------------------------------------------------------------------
