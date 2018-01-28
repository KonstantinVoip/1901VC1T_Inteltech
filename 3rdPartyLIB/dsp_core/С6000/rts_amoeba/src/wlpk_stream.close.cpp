#include <rts.h>
// ---------------------------------------------------------------------------

extern void wlpk_winwrite( WLPK_FILE* f, const void* data, int32 len );
extern void wlpk_find( WLPK_FILE* f, int32* position, int32* length, uint8* buf, int32 bufLength );

// ---------------------------------------------------------------------------
void wlpk_close( WLPK_FILE* f )
{
  if( f == NULL ) return;
  if( f->blen && ( f->mode == 1 ) )
  {
    int32 opos, olen;
    uint8 one = 1;
    uint8 zero = 0;
    uint8 tmp;
    while( f->blen )
    {
      wlpk_find( f, &opos, &olen, f->b, f->blen );
      if( olen < 2 )
      {
        olen = 1;
        if( bit_write( f->f, &zero, 1 ) != 1 ) break;
        if( bit_write( f->f, f->b, 8 ) != 8 ) break;
      }
      else
      {
        if( bit_write( f->f, &one, 1 ) != 1 ) break;
        if( bit_write( f->f, &opos, 10 ) != 10 ) break;
        tmp = olen - 1;
        if( bit_write( f->f, &tmp, 5 ) != 5 ) break;
      }
      wlpk_winwrite( f, f->b, olen );
      f->blen -= olen;
      memmove( &f->b[0], &f->b[olen], f->blen );
    }

  }
  bit_close( f->f );
  delete f;
}
// ---------------------------------------------------------------------------
