#include <rts.h>
// ---------------------------------------------------------------------------

extern void wlpk_winwrite( WLPK_FILE* f, const void* data, int32 len );

// ---------------------------------------------------------------------------
int32 wlpk_read( WLPK_FILE* f, const void* buf, int32 blen )
{
  uint8* u8buf = (uint8*)buf;
  int32 rc = 0;
  int32 opos;
  uint8 t1, t3;

  if( ( f == NULL ) || ( buf == NULL ) ) return -1;
  if( f->mode != 2 ) return -1;
  if( blen <= 0 ) return 0;
  while( blen )
  {
    if( f->blen != 0 )
    {
      if( blen > f->blen )
      {
        memcpy( u8buf, f->b, f->blen );
        rc += f->blen;
        u8buf += f->blen;
        blen -= f->blen;
        f->blen = 0;
      }
      else
      {
        memcpy( u8buf, f->b, blen );
        memmove( f->b, f->b + blen, f->blen - blen );
        f->blen -= blen;
        rc += blen;
        return rc;
      }
    }
    if( bit_read( f->f, &t1, 1 ) != 1 ) return rc;
    if( t1 )
    {
      opos = 0;
      if( bit_read( f->f, &opos, 10 ) != 10 ) return rc;
      if( bit_read( f->f, &t3, 5 ) != 5 ) return rc;
      f->blen = (uint32)t3 + 1;
      if( ( opos + f->blen ) > 1024 )
      {
        // Note: May be used for compression extensions
        return rc;
      }
      memcpy( f->b, &f->w[opos], f->blen );
      wlpk_winwrite( f, f->b, f->blen );
    }
    else
    {
      if( bit_read( f->f, u8buf, 8 ) != 8 ) return rc;
      wlpk_winwrite( f, u8buf, 1 );
      rc++;
      u8buf++;
      blen--;
    }
  }

  return rc;
}
// ---------------------------------------------------------------------------
