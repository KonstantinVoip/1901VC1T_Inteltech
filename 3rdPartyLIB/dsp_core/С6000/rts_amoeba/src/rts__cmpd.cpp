// ---------------------------------------------------------------------------
// extern "C" int _cmpd( double left, double right )
// ---------------------------------------------------------------------------
#include <rts_real_d.h>
#include <rts.h>
// ---------------------------------------------------------------------------
extern "C" int CMPF( REAL left, REAL right )
{
  REAL_2UNS lft, rgt;
  int l, r;

  lft.r = left; l = lft.u.msh;
  rgt.r = right; r = rgt.u.msh;

  if( ( l ^ r ) < 0 )
  {
    if( ( ( l | r ) == MINUS ) && ( ( lft.u.lsh | rgt.u.lsh ) == 0 ) ) return 0;
    l |= 1;
  }
  else
  {
    l -= r;
    if( l == 0 )
    {
      unsigned ul = lft.u.lsh;
      unsigned ur = rgt.u.lsh;
      l = ( ul < ur ) ? -1 : ( ul != ur );
    }
    if( r < 0 ) l = -l;
  }

  return l;
}
// ---------------------------------------------------------------------------
