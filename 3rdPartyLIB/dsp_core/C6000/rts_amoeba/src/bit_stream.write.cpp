#include <rts.h>
// ---------------------------------------------------------------------------
int32 bit_write( BIT_FILE* f, const void* buf, int32 blen )
{
  uint8* u8buf = (uint8*)(const_cast<void*>(buf));
  int32 i, j, k, wc;
  uint8 ms, md;

  if( ( f == NULL ) || ( buf == NULL ) ) return -1;
  if( f->mode != 1 ) return -1;
  if( blen <= 0 ) return 0;

  ms = 0x01;
  md = 1 << f->bpos;

  for( k = 0, wc = 0, j = 0, i = 0; i < blen; i++, wc++ )
  {
    if( u8buf[j] & ms ) f->b |= md;
    k++; if( k == 8 ) { k = 0; j++; ms = 0x01; } else ms <<= 1;
    f->bpos++;
    if( f->bpos == 8 )
    {
      if( fwrite( &f->b, 1, 1, f->f ) != 1 ) return wc;
      f->b = 0; f->bpos = 0; md = 0x01;
    }
    else
    {
      md <<= 1;
    }
  }

  return wc;
}
// ---------------------------------------------------------------------------
