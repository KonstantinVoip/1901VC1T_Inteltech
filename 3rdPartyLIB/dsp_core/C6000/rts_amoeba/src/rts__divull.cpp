/****************************************************************************
* Module      : rts__divull.cpp
* Description : 
* Author      : 
*****************************************************************************/
// ---------------------------------------------------------------------------
// extern "C" unsigned long _divul( unsigned long a, unsigned long b )
// ---------------------------------------------------------------------------
#include <rts.h>
// ---------------------------------------------------------------------------

extern "C" unsigned long long _subcull( unsigned long long src1, unsigned long long src2 );

// ---------------------------------------------------------------------------
static __inline unsigned _lmbdull( int val, unsigned long long src )
{
  unsigned int p1 = src >> 32;
  unsigned p2 = src;
  unsigned int pos;
  if( ( pos = _lmbd( val, p1 ) ) == 32 ) return _lmbd( val, p2 ) + 32;
  return pos;
}
// ---------------------------------------------------------------------------
extern "C" unsigned long long _divull(unsigned long long x1, unsigned long long x2 )
{
  register int i;
  register unsigned long long num;
  register unsigned long long den;
  register int shift;
  unsigned long long first_div = 0;
  unsigned long long num64;

  shift = _lmbdull( 1, x2 ) - _lmbdull( 1, x1 );

  if( x1 < x2 ) return 0;
  if( x1 == 0 ) return 0;
  if( x2 == 0 ) return (unsigned long long)-1;

  num = x1;
  den = x2 << shift;
  num64 = ( _lmbdull( 1, x1 ) == 0 );
  first_div = num64 << shift;
  if( den > num ) first_div >>= 1;

  if( num64 )
  {
    if( den > num )
    {
      den >>= 1;
      num -= den;
    }
    else
    {
      num -= den;
      den >>= 1;
    }
  }
  else
  {
    shift++;
  }

  for( i = 0; i < shift; i++ ) num = _subcull( num, den );
  if( shift ) return num << ( 64 - shift ) >> ( 64 - shift ) | first_div;

  return first_div;
}
// ---------------------------------------------------------------------------
