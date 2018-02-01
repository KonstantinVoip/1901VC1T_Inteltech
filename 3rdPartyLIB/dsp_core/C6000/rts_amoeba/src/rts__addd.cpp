// ---------------------------------------------------------------------------
// extern "C" double _addd( double left, double right )
// ---------------------------------------------------------------------------
#include <rts_real_d.h>
#include <rts.h>
// ---------------------------------------------------------------------------
extern "C" REAL ADDF( REAL left, REAL right )
{
  int lexp, rexp;
  REAL_2UNS lft, rgt;
  int lsign, rsign;

  lft.r = left; 
  rgt.r = right;
  lsign = lft.u.msh & MINUS;
  rsign = rgt.u.msh & MINUS;
  lexp = lft.u.msh - lsign;
  rexp = rgt.u.msh - rsign;

  lft.u.msh = ( lexp & REAL_FRC_MASK ) + REAL_HIDDEN_BIT;
  if( !( lexp >>= (REAL_FRC_MSBs) ) )
  {
    if( rexp == 0 )
    {
      lft.r = left;
      rgt.u.msh &= lft.u.msh;
    }
    return rgt.r;
  }
  if( lsign ) NEG2sCOMP( lft );

  rgt.u.msh = ( rexp & REAL_FRC_MASK ) + REAL_HIDDEN_BIT;
  if( !( rexp >>= (REAL_FRC_MSBs) ) ) return left;
  if( rsign ) NEG2sCOMP( rgt );
  lexp = FRCADDF( lexp, &lft, rexp, &rgt );

  if( ( lexp -= 1 ) < 0 )
  {
    lft.r = 0.0;
  }
  else if( lexp >= ( REAL_EXP_INFNAN - 1 ) )
  {
    lft.u.msh = ( lft.u.msh & MINUS ) + REAL_INFNAN;
    lft.u.lsh = 0;
  }
  else
  {
    lft.u.msh += ( ((int)lexp) << REAL_FRC_MSBs );
  }

  return lft.r;
}
// ---------------------------------------------------------------------------
