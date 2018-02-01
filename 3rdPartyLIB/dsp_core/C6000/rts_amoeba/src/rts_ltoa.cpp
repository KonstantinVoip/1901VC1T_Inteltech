// ---------------------------------------------------------------------------
// int ltoa( long val, char* buffer )
// ---------------------------------------------------------------------------
#include <rts.h>
// ---------------------------------------------------------------------------
#define BUFLEN 20
// ---------------------------------------------------------------------------
int ltoa( long val, char* buffer )
{
  char tempc[BUFLEN];
  register char* bufptr;
  register int neg = val < 0;
  register long uval = neg ? -val : val;
  *( bufptr = &tempc[BUFLEN-1] ) = 0;
  do { *--bufptr = ( uval % 10 ) + '0'; } while( uval /= 10 );
  if( neg ) *--bufptr = '-';
  memcpy( buffer, bufptr, uval = ( tempc + BUFLEN ) - bufptr );
  return ( uval - 1 );
}
// ---------------------------------------------------------------------------
