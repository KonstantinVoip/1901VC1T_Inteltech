#include <rts.h>
// ---------------------------------------------------------------------------

extern void wlpk_winwrite( WLPK_FILE* f, const void* data, int32 len );
extern void wlpk_find( WLPK_FILE* f, int32* position, int32* length, uint8* buf, int32 bufLength );

// ---------------------------------------------------------------------------
int32 wlpk_write( WLPK_FILE* f, const void* buf, int32 blen )
{
  uint8* u8buf = (uint8*)(const_cast<void*>(buf));
  int32 opos, olen, i;
  uint8 one = 1;
  uint8 zero = 0;
  uint8 tmp, r;

  if( ( f == NULL ) || ( buf == NULL ) ) return -1;
  if( f->mode != 1 ) return -1;
  if( blen <= 0 ) return 0;

  for( r = 0, i = 0; i < blen; i++ )
  {
    f->b[f->blen] = u8buf[i];
    f->blen++;
    r++;
    if( f->blen == 32 )
    {
      wlpk_find( f, &opos, &olen, f->b, f->blen );
      if( olen < 2 )
      {
        olen = 1;
        if( bit_write( f->f, &zero, 1 ) != 1 ) return r;
        if( bit_write( f->f, f->b, 8 ) != 8 ) return r;
      }
      else
      {
        if( bit_write( f->f, &one, 1 ) != 1 ) return r;
        if( bit_write( f->f, &opos, 10 ) != 10 ) return r;
        tmp = olen - 1;
        if( bit_write( f->f, &tmp, 5 ) != 5 ) return r;
      }
      wlpk_winwrite( f, f->b, olen );
      f->blen -= olen;
      memmove( &f->b[0], &f->b[olen], f->blen );
    }
  }

  return r;
}
// ---------------------------------------------------------------------------
