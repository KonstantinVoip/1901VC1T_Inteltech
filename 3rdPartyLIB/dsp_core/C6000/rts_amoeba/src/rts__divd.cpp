// ---------------------------------------------------------------------------
// extern "C" int _divd( double left, double right )
// ---------------------------------------------------------------------------
#include <rts_real_d.h>
#include <rts.h>
// ---------------------------------------------------------------------------
extern "C" REAL DIVF( REAL left, REAL right )
{ 
  unsigned lfrc, rfrc, sign;
  int lexp, rexp, qexp;
  REAL_2UNS lft, rgt, quo;

  quo.r = 0.0;
  lft.r = left; 
  rgt.r = right;
  sign = ( lft.u.msh ^ rgt.u.msh ) & MINUS;
  lfrc = ( lft.u.msh &= ~MINUS ); 
  rfrc = ( rgt.u.msh &= ~MINUS );

  if( rexp = (int)( rfrc >> REAL_FRC_MSBs ) )
  {
    if( !( rfrc &= REAL_FRC_MASK ) && !rgt.u.lsh )
    {
      if( !( lexp = (int)( lfrc >> REAL_FRC_MSBs ) ) )
      {
        goto resign;
      }
      quo.u.msh = ( lfrc & REAL_FRC_MASK ) + REAL_HIDDEN_BIT;
      quo.u.lsh = lft.u.lsh;
      qexp = lexp - rexp;
      goto insert_exponent;
    }
    rgt.u.msh = rfrc + REAL_HIDDEN_BIT;
  }
  else
  {
    quo.u.msh = REAL_NAN;
    if( ( lfrc != 0 ) || ( lft.u.lsh != 0 ) ) quo.u.msh = REAL_INFNAN;
    goto resign;
  }
  if( lexp = (int)( lfrc >> REAL_FRC_MSBs ) )
  {
    lft.u.msh = ( lfrc & REAL_FRC_MASK ) + REAL_HIDDEN_BIT;
  }
  else
  {
    goto resign;
  }

  qexp = lexp - rexp;
  qexp += FRCDIVF( &quo, &lft, &rgt );

insert_exponent:

  if( ( qexp += 1023 ) <= 0 )
  {
    quo.r = 0.0;
    qexp = 0;
  }
  else if( qexp >= REAL_EXP_INFNAN )
  {
    qexp = REAL_EXP_INFNAN;
    quo.r = 0.0;
  }

  quo.u.msh = ( quo.u.msh & REAL_FRC_MASK ) + ( ((int)qexp) << REAL_FRC_MSBs );

resign:

  quo.u.msh += sign;

  return quo.r;
}
// ---------------------------------------------------------------------------
