// ---------------------------------------------------------------------------
// extern "C" double _fltid( int x )
// ---------------------------------------------------------------------------
#include <rts_real_d.h>
#include <rts.h>
// ---------------------------------------------------------------------------
extern "C" REAL FLTIF( int x )
{
  unsigned rfrc;
  int rexp;
  unsigned rmsh;
  REAL_2UNS rslt;

  rfrc = x;
  if( rfrc == 0 ) return ZERO;
  if( (int)rfrc <= 0 ) rfrc = -rfrc;

  rexp = _lmbd( 1, rfrc );
  rfrc <<= rexp;
  rexp = 1023 + 32 - 2 - rexp;

  #define SHIFT_COUNT ( REAL_FRC_MSBs + 1 - 32 + 32 )
  #if ( SHIFT_COUNT >= 0 )
    rslt.u.lsh = (unsigned)( rfrc << SHIFT_COUNT );
  #else 
    rslt.u.lsh = (unsigned)( rfrc >> -SHIFT_COUNT );
  #endif 
  #undef SHIFT_COUNT

  #define SHIFT_COUNT ( 32 - REAL_FRC_MSBs - 1 )
  #if ( SHIFT_COUNT >= 0 )
    rmsh = (unsigned)( rfrc >> SHIFT_COUNT );
  #else 
    rmsh = (unsigned)( rfrc << -SHIFT_COUNT );
  #endif 
  #undef SHIFT_COUNT

  rmsh += ((unsigned)rexp) << REAL_FRC_MSBs;
  if( x < 0 ) rmsh += MINUS;
  rslt.u.msh = rmsh;

  return rslt.r;
}
// ---------------------------------------------------------------------------
