#include <rts.h>
// ---------------------------------------------------------------------------
int32 bit_read( BIT_FILE* f, void* buf, int32 blen )
{
  uint8* u8buf = (uint8*)buf;
  int32 i, j, k, rc;
  uint8 ms, md;

  if( ( f == NULL ) || ( buf == NULL ) ) return -1;
  if( f->mode != 2 ) return -1;
  if( blen <= 0 ) return 0;

  md = 0x01;
  ms = 1 << f->bpos;

  for( k = 0, rc = 0, j = 0, i = 0; i < blen; i++, rc++ )
  {
    if( k == 0 ) u8buf[j] = 0;
    if( f->bpos == 0 ) if( fread( &f->b, 1, 1, f->f ) != 1 ) return rc;
    if( f->b & ms ) u8buf[j] |= md;
    k++; if( k == 8 ) { k = 0; j++; md = 0x01; } else md <<= 1;
    f->bpos++;
    if( f->bpos == 8 ) { f->bpos = 0; ms = 0x01; } else ms <<= 1;
  }

  return rc;
}
// ---------------------------------------------------------------------------
