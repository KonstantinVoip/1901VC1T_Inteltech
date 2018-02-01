// ---------------------------------------------------------------------------
// extern "C" int _frcaddd( int lx, double* lf, int rx, double* rf )
// ---------------------------------------------------------------------------
#include <rts_real_d.h>
#include <rts.h>
// ---------------------------------------------------------------------------
extern "C" int FRCDIVF( REAL_2UNS* q, REAL_2UNS* l, REAL_2UNS* r )
{
  int rsh, inv_div, i, t; 
  int rm_0, dv_0, quo_0;
  int rm_1, dv_1, quo_1;
  int rm_2, dv_2, quo_2;
  int rm_3, dv_3, quo_3;

  rm_0 = l->u.msh >> ( REAL_FRC_MSBs - ( 32 / 2 - 2 ) ); 
  rm_1 = ( ( l->u.msh << ( 2 * ( 32 / 2 - 2 ) - REAL_FRC_MSBs ) ) + ( l->u.lsh >> (32 - 2 * ( 32 / 2 - 2 ) + REAL_FRC_MSBs ) ) ) & ( ( ((int)1) << (32 / 2 - 2 ) ) - 1 );
  rm_2 = ( l->u.lsh >> ( 32 - 3 * ( 32 / 2 - 2 ) + REAL_FRC_MSBs ) ) & ( ( ((int)1) << ( 32 / 2 - 2 ) ) - 1 );
  rm_3 = ( l->u.lsh << ( 4 * ( 32 / 2 - 2 ) - REAL_FRC_MSBs - 32 ) ) & ( ( ((int)1) << ( 32 / 2 - 2 ) ) - 1 );

  dv_0 = r->u.msh >> ( REAL_FRC_MSBs - ( 32 / 2 - 2 ) ); 
  dv_1 = ( ( r->u.msh << ( 2 * ( 32 / 2 - 2 ) - REAL_FRC_MSBs ) ) + ( r->u.lsh >> ( 32 - 2 * ( 32 / 2 - 2 ) + REAL_FRC_MSBs ) ) ) & ( ( ((int)1) << ( 32 / 2 - 2 ) ) - 1 );
  dv_2 = ( r->u.lsh >> ( 32 - 3 * ( 32 / 2 - 2 ) + REAL_FRC_MSBs ) ) & ( ( ((int)1) << ( 32 / 2 - 2 ) ) - 1 );
  dv_3 = ( r->u.lsh << ( 4 * ( 32 / 2 - 2 ) - REAL_FRC_MSBs - 32 ) ) & ( ( ((int)1) << ( 32 / 2 - 2 ) ) - 1 );

  inv_div = ( (int)( ( 1.411622 ) * ( ((int)1) << ( 32 / 2 - 2 ) ) ) ) - ( ( ((int)( ( 0.470459 ) * ( ((int)1) << ( 32 / 2 - 2 ) ) ) ) * dv_0 ) >> ( 32 / 2 - 2 ) );
  inv_div = ( ( ( (int)( ( 2.0 ) * ( ((int)1) << ( 32 / 2 - 2 ) ) ) ) - ( ( inv_div * dv_0 ) >> ( 32 / 2 - 2 ) ) ) * inv_div ) >> 2 * ( 32 / 2 - 2 ) - ( 32 / 2 );
  inv_div = ( ( ( ( (int)( ( 1.0 ) * ( ((int)1) << ( 32 / 2 ) ) ) ) - ( ( inv_div * dv_0 ) >> ( 32 / 2 - 2 ) ) ) * inv_div ) >> ( 32 / 2 ) ) + inv_div;

  t = 0;
  for( i = 0; i <= 3; i += 1 )
  {
    int p = ( t * inv_div ) >> ( 32 / 2 ) - ( 32 / 2 - 2 );
    p += ( rm_0 * inv_div ) >> ( 32 / 2 );
    rm_0 += t << ( 32 / 2 - 2 ); 

    switch( i )
    {
      case 0: quo_0 = p; break;
      case 1: quo_1 = p; break;
      case 2: quo_2 = p; break;
      case 3: quo_3 = p; break;
    }
    t = -p;

    p = dv_0 * t; rm_0 += p >> ( 32 / 2 - 2 ); rm_1 += p & ( ( ((int)1) << ( 32 / 2 - 2 ) ) - 1 );
    p = dv_1 * t; rm_1 += p >> ( 32 / 2 - 2 ); rm_2 += p & ( ( ((int)1) << ( 32 / 2 - 2 ) ) - 1 );
    p = dv_2 * t; rm_2 += p >> ( 32 / 2 - 2 ); rm_3 += p & ( ( ((int)1) << ( 32 / 2 - 2 ) ) - 1 );
    p = dv_3 * t; rm_3 += p >> ( 32 / 2 - 2 );

    rm_2 += rm_3 >> ( 32 / 2 - 2 );
    rm_1 += rm_2 >> ( 32 / 2 - 2 );
    rm_0 += rm_1 >> ( 32 / 2 - 2 );

    t = rm_0;
    rm_0 = rm_1 & ( ( ((int)1) << ( 32 / 2 - 2 ) ) - 1 );
    rm_1 = rm_2 & ( ( ((int)1) << ( 32 / 2 - 2 ) ) - 1 );
    rm_2 = rm_3 & ( ( ((int)1) << ( 32 / 2 - 2 ) ) - 1 );
    rm_3 = p & ( ( ((int)1) << ( 32 / 2 - 2 ) ) - 1 );
  }

  quo_2 = ( quo_2 << ( 32 / 2 - 2 ) ) + quo_3;
  quo_0 = ( quo_0 << ( 32 / 2 - 2 ) ) + quo_1 + ( quo_2 >> 2 * ( 32 / 2 - 2 ) );
  quo_1 = quo_2 & ( ( ((int)1) << ( 2 * ( 32 / 2 - 2 ) ) ) - 1 );

  rsh = 0;
  if( quo_0 < ( ( (int)1) << 2 * ( 32 / 2 - 2 ) ) )
  {
     quo_0 <<= 1;
     quo_1 <<= 1;
     rsh = -1;
  }

  quo_1 = ( ( quo_1 >> 4 * ( 32 / 2 - 2 ) - 52 - 1 ) + 1 ) >> 1;
  q->u.lsh = ( quo_0 << 52 - 2 * ( 32 / 2 - 2 ) ) + quo_1;
  q->u.msh = ( ( quo_1 >> 52 - 2 * ( 32 / 2 - 2 ) ) + quo_0 ) >> 2 * ( 32 / 2 - 2 ) - REAL_FRC_MSBs;

  if( q->u.msh >= REAL_HIDDEN_BIT * 2 )
  {
    q->u.msh = REAL_HIDDEN_BIT;
    rsh += 1;
  }

  return rsh;
}
// ---------------------------------------------------------------------------
