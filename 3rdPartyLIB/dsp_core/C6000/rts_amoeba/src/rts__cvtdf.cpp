// ---------------------------------------------------------------------------
// extern "C" float _cvtdf( double x )
// ---------------------------------------------------------------------------
#include <rts_real_d.h>
#include <rts.h>
// ---------------------------------------------------------------------------
extern "C" LEAN SLIMF( REAL x )
{ 
  int exp;
  int frc;
  CREAL crx;

  REALasCREAL( crx, x );

  frc = ( ( crx.u.msh & REAL_FRC_MASK ) << ( LEAN_FRC_MSBs + 1 - REAL_FRC_MSBs ) ) + ( crx.u.lsh >> ( 32 + REAL_FRC_MSBs - LEAN_FRC_MSBs - 1 ) );
  exp = (int)( ( crx.u.msh >> REAL_FRC_MSBs ) & REAL_EXP_MASK );

  if( ( exp -= 1023 - 127 ) <= 0 )
  {
    frc = 0;
    exp = 0;
  }
  else if( exp >= LEAN_EXP_INFNAN )
  {
    if( exp == ( REAL_EXP_INFNAN - 1023 + 127 ) )
    {
      if( frc || crx.u.lsh ) frc |= LEAN_NSNAN_BIT * 2;
      frc &= ((unsigned int)-2);
    }
    else frc = 0;
    exp = LEAN_EXP_INFNAN;
  }

  frc = ( ( frc + 1 ) >> 1 ) + ( exp << LEAN_FRC_MSBs );
  if( (int)crx.u.msh < 0 ) frc += MINUS;

  return_INTasLEAN( frc );
}
// ---------------------------------------------------------------------------
