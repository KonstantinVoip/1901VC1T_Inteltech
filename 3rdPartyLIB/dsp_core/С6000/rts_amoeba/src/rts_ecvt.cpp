// ---------------------------------------------------------------------------
// char* ecvt( long double value, register int ndigit, int *decpt, int* sign )
// ---------------------------------------------------------------------------
#include <math.h>
#include <rts.h>
// ---------------------------------------------------------------------------
char* ecvt( long double value, register int ndigit, int *decpt, int* sign )
{
  static char out[100]; 

  register int digits = 0;
  register char* pos = out + 1;     
  register int temp;

  out[0] = '0';
  ndigit++;

  { 
    unsigned exp_part = _hi( value );
    if( ( ( exp_part >> 20 ) & 0x7ff ) == 0x7ff )
      value = ( exp_part & 0x80000000 ) ? -HUGE_VALL : HUGE_VALL;
  }

  if( (*sign) = ( value < 0 ) ) value = -value;
  while( value > 0x7FFFFFFF ) { value /= 10; digits++; }
  while( value && ( value < 1 ) ) { value *= 10; digits--; }

  pos += temp = ltoa( (long)value, pos );
  *decpt = digits + temp;

  if( temp >= ndigit )
  {
    pos = out + ndigit + 1;
  }
  else if( ( ndigit -= temp ) > 0 ) do
  {
    value -= (int) value;
    *pos++ = (int)( value *= 10.0 ) + '0';
  }
  while( --ndigit );

  if( *--pos >= '5' )
  {
    register char* ptr = pos;
    while( ( *--ptr += 1 ) > '9') (*ptr) = '0';
    if( ptr == out ) { *--pos = 0; *decpt += 1; return out; }
  }

  (*pos) = 0;

  return ( out + 1 );
}
// ---------------------------------------------------------------------------
