#include <rts.h>
// ---------------------------------------------------------------------------
void wlpk_find( WLPK_FILE* f, int32* position, int32* length, uint8* buf, int32 blen )
{
  int32 i, j1, j2, k, opos, olen;

  k = 1024 - blen;

  for( opos = 0, olen = 0, i = 0; i < k; i++ )
  {
    for( j2 = 0, j1 = i; j2 < blen; j1++, j2++ ) if( f->w[j1] != buf[j2] ) break;
    if( j2 == 32 )
    {
      (*position) = i;
      (*length) = 32;
      return;
    }
    if( j2 > olen )
    {
      opos = i;
      olen = j2;
    }
  }

  (*position) = opos;
  (*length) = olen;
}
// ---------------------------------------------------------------------------
