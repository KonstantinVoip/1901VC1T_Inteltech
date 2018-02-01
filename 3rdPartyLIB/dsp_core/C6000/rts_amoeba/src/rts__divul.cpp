// ---------------------------------------------------------------------------
// extern "C" unsigned long _divul( unsigned long a, unsigned long b )
// ---------------------------------------------------------------------------
static __inline unsigned _lmbdul( int val, unsigned long src )
{
  unsigned p1 = src >> 32; 
  unsigned p2 = src;
  unsigned pos;
  if( !val ) p1 |= 0xffffff00;
  if( ( pos = _lmbd( val, p1 ) ) == 32 ) return _lmbd( val, p2 ) + 32;
  else return pos;
}
// ---------------------------------------------------------------------------
static __inline unsigned long _subcul( unsigned long src1, unsigned long src2 )
{
  unsigned long res1 = ( ( src1 - src2 ) << 1 ) | 0x1;
  unsigned long res2 = src1 << 1;
  if( src1 >= src2 ) return res1;
  return res2;
}
// ---------------------------------------------------------------------------
extern "C" unsigned long _divul( unsigned long x1, unsigned long x2 )
{
  register int i;
  register unsigned long num;
  register unsigned long den;
  register int shift;
  unsigned long first_div = 0;
  unsigned long num40;

  shift = _lmbdul( 1, x2 ) - _lmbdul( 1, x1 );

  if( x1 < x2 ) return 0;
  if( x1 == 0 ) return 0;
  if( x2 == 0 ) return (unsigned long)-1;

  num = x1;
  den = x2 << shift;
  num40 = ( _lmbdul( 1, x1 ) == 24 );
  first_div = num40 << shift;
  if( den > num ) first_div >>= 1; 

  if( num40 )
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

  for( i = 0; i < shift; i++ ) num = _subcul( num, den );
  if( shift ) return num << ( 40 - shift ) >> ( 40 - shift ) | first_div;

  return first_div;
}
// ---------------------------------------------------------------------------
