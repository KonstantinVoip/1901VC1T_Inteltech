// ---------------------------------------------------------------------------
// extern "C" int _frcaddd( int lx, double* lf, int rx, double* rf )
// ---------------------------------------------------------------------------
#include <rts_real_d.h>
#include <rts.h>
// ---------------------------------------------------------------------------
extern "C" int FRCADDF( int lx, REAL_2UNS* lf, int rx, REAL_2UNS* rf )
{
  int sc, dx;
  unsigned sign;
  REAL_2UNS* tf;

  dx = lx; sc = dx - rx;
  if( sc < 0 ) { sc = -sc; dx = rx; tf = lf; lf = rf; rf = tf; }

  if( sc < 52 + 2 )
  {
    unsigned lf_u_msh = lf->u.msh;
    unsigned lf_u_lsh = lf->u.lsh;
    unsigned rf_u_msh = rf->u.msh;
    unsigned rf_u_lsh = rf->u.lsh;

    LSH1( lf_u_msh, lf_u_lsh );

    sc--;
    if( sc >= 32 )
    {
      rf_u_lsh = rf_u_msh;
      rf_u_msh = (int)rf_u_msh >> (REAL_FRC_MSBs) + 2;
      sc -= 32;
    }
    if( sc > 0 )
    {
      rf_u_lsh = ( rf_u_msh << 32 - sc ) + ( rf_u_lsh >> sc );
      rf_u_msh = (int)rf_u_msh >> sc;
    }
    else if( sc < 0 )
    {
      LSH1( rf_u_msh, rf_u_lsh );
    }

    lf_u_msh += rf_u_msh;
    lf_u_lsh += rf_u_lsh;
    if( lf_u_lsh < rf_u_lsh ) lf_u_msh += 1;

    sign = 0;
    if( (int)lf_u_msh < 0 )
    {
      sign = MINUS;
      lf_u_msh = ~lf_u_msh + ( ( lf_u_lsh = -lf_u_lsh ) == 0 );
    }

    if( lf_u_msh < REAL_HIDDEN_BIT * 2 )
    {
      lf->u.msh = lf_u_msh;
      lf->u.lsh = lf_u_lsh;
      if( ( sc = RENORMF( lf ) + 2 ) <= 0 ) return 0;
      dx -= sc;
      lf->u.msh |= sign;
    }
    else
    {
      if( lf_u_msh >= REAL_HIDDEN_BIT * 4 )
      {
        RSH1( lf_u_msh, lf_u_lsh );
        dx += 1;
      }
      if( ( lf_u_lsh += 1 ) == 0 ) lf_u_msh += 1;
      RSH1( lf_u_msh, lf_u_lsh );
      lf_u_msh |= sign;
      lf->u.msh = lf_u_msh;
      lf->u.lsh = lf_u_lsh;
    }
  }
  else if( (int)lf->u.msh < 0 )
  {
    NEG2sCOMP( (*lf) );
    lf->u.msh |= MINUS;
  }

  if( lx < rx ) *rf = *lf;
               
  return dx;
}
// ---------------------------------------------------------------------------
