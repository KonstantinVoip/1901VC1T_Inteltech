// ---------------------------------------------------------------------------
// extern "C" int renormd( REAL_2UNS* ff )
// ---------------------------------------------------------------------------
#include <rts_real_d.h>
#include <rts.h>
// ---------------------------------------------------------------------------
int RENORMF( REAL_2UNS* ff )
{
  int shift;
  int offset = -1;
  unsigned tmp;

  while( ( tmp = ff->u.msh ) == 0 )
  {
    if( ff->u.lsh == 0 ) return -10;
    ff->u.msh = ff->u.lsh >> 32 - (REAL_FRC_MSBs) - 1;
    ff->u.lsh <<= (REAL_FRC_MSBs) + 1;
    offset += (REAL_FRC_MSBs) + 1;
  }

  shift = _lmbd( 1, tmp ) - 32 + (REAL_FRC_MSBs) + 1;
  tmp <<= shift;

  if( shift != 0 )
  {
    ff->u.msh = tmp | ( ff->u.lsh >> 32 - shift );
    ff->u.lsh <<= shift;
  }

  return shift + offset;
}
// ---------------------------------------------------------------------------
