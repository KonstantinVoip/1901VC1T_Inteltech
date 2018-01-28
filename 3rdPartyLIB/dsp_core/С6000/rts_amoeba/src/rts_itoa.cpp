// ---------------------------------------------------------------------------
// extern int32 itoa( int32 val, char* buffer )
// ---------------------------------------------------------------------------
#include <rts.h>
// ---------------------------------------------------------------------------
#define BUFLEN 20
// ---------------------------------------------------------------------------
int itoa( int32 val, char* buffer )
{
  int8 tempc[BUFLEN];
  register int8 *bufptr;
  register int32 neg = val < 0;
  register int32 uval = neg ? -val : val;

  *( bufptr = &tempc[BUFLEN-1] ) = 0;

  do { *--bufptr = ( uval % 10 ) + '0'; } while( uval /= 10 );
  if (neg) *--bufptr = '-';

  memcpy( buffer, bufptr, uval = ( tempc + BUFLEN ) - bufptr );

  return uval - 1;
}
// ---------------------------------------------------------------------------
