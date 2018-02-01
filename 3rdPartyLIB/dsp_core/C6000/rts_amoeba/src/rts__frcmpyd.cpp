// ---------------------------------------------------------------------------
// extern "C" int _frcmpyd( double* p, double* l, double* r )
// ---------------------------------------------------------------------------
#include <rts_real_d.h>
#include <rts.h>
// ---------------------------------------------------------------------------
extern "C" int FRCMPYF( REAL_2UNS* p, REAL_2UNS* l, REAL_2UNS* r )
{
  REAL_2UNS lp = *l;
  REAL_2UNS rp = *r;

  unsigned long p0, p1, p2, p3, msh;

  LEFT_SHIFT( lp, 32 - REAL_FRC_MSBs - 2 );
  LEFT_SHIFT( rp, 32 - REAL_FRC_MSBs - 2 );

  p0 = _mpyhu( lp.u.msh, rp.u.msh );
  p1 = _mpyhlu( lp.u.msh, rp.u.msh );
  p2 = _mpyhu( lp.u.msh, rp.u.lsh );
  p3 = _mpyhlu( lp.u.msh, rp.u.lsh );
  p1 += _mpylhu( lp.u.msh, rp.u.msh );
  p2 += _mpyu( lp.u.msh, rp.u.msh );
  p3 += _mpylhu( lp.u.msh, rp.u.lsh );
  p2 += _mpyhu( lp.u.lsh, rp.u.msh );
  p3 += _mpyhlu( lp.u.lsh, rp.u.msh );
  p3 += _mpylhu( lp.u.lsh, rp.u.msh );

  p0 += p1 >> ( 32 / 2 );
  p1 = ( ( p1 & ( ( ((unsigned long)1) << ( 32 / 2 ) ) - 1 ) ) << ( 32 / 2 ) ) + p2 + ( p3 >> ( 32 / 2 ) );
  p1 = ( p1 >> ( ( 2 * 32 - 4 ) - 52 - 1 ) ) + 1;
  msh = p0 + ( p1 >> ( 52 - ( 32 - 4 ) + 1 ) );

  if( msh >= ( ((long)1) << ( 32 - 3 ) ) )
  {
    p1 = ( ( ( p1 - 1 ) >> 1 ) + 1 ) >> 1;
    p->u.lsh = (int)p1 + (int)( p0 << ( 52 - ( 32 - 4 ) - 1 ) );
    p->u.msh = ( ( p1 >> ( 52 - ( 32 - 4 ) - 1 ) ) + p0 ) >> ( ( 32 - 4 ) - REAL_FRC_MSBs + 1 );
    return 1;  
  }
  p->u.lsh = (int)( p1 >> 1 ) + (int)( p0 << ( 52 - ( 32 - 4 ) ) );
  p->u.msh = msh >> ( 32 - 4 ) - REAL_FRC_MSBs;

  return 0;
}
// ---------------------------------------------------------------------------
