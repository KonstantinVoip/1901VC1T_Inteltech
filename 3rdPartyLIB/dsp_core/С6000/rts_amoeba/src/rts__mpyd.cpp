// ---------------------------------------------------------------------------
// extern "C" double _mpyd( double left, double right )
// ---------------------------------------------------------------------------
#include <rts_real_d.h>
#include <rts.h>
// ---------------------------------------------------------------------------
extern "C" REAL MPYF( REAL left, REAL right )
{ 
  int rfrc, lfrc, sign;
  int lexp, rexp, pexp;
  REAL_2UNS lft, rgt, prd;

  prd.r = 0.0;
  lft.r = left; rgt.r = right;
  sign = ( lft.u.msh ^ rgt.u.msh ) & MINUS;
  lfrc = ( lft.u.msh &= ~MINUS ); 
  rfrc = ( rgt.u.msh &= ~MINUS );

  if( lexp = ( lfrc >> REAL_FRC_MSBs ) )
  {
    if( !( lfrc &= REAL_FRC_MASK ) && !lft.u.lsh )
    {
      if( !( rexp = ( rfrc >> REAL_FRC_MSBs ) ) )
      {
        goto resign;
      }
      prd.u.msh = ( rfrc & REAL_FRC_MASK ) + REAL_HIDDEN_BIT;
      pexp = lexp + rexp;
      prd.u.lsh = rgt.u.lsh;
      goto insert_exponent;
    }
    lft.u.msh = lfrc + REAL_HIDDEN_BIT;
  }
  else
  {
    goto resign;
  }

  if( rexp = rfrc >> REAL_FRC_MSBs )
  {
    if( !( rfrc &= REAL_FRC_MASK ) && !rgt.u.lsh )
    {
      pexp = lexp + rexp;
      prd.u.msh = lft.u.msh;
      prd.u.lsh = lft.u.lsh;
      goto insert_exponent;
    }
    rgt.u.msh = rfrc + REAL_HIDDEN_BIT;
  }
  else
  {
    goto resign;
  }

  pexp = lexp + rexp;
  pexp += FRCMPYF( &prd, &lft, &rgt );

insert_exponent:

  if( ( pexp -= ( 1023 + 1 ) ) < 0 )
  {
    prd.r = 0.0;
    goto resign;
  }
  else if( pexp >= ( REAL_EXP_INFNAN - 1 ) )
  {
    prd.u.lsh = 0;
    prd.u.msh = REAL_INFNAN;
    goto resign;
  }

  prd.u.msh += (int)pexp << REAL_FRC_MSBs;

resign:

  prd.u.msh += sign;

  return prd.r;
}
// ---------------------------------------------------------------------------
