#include <rts.h>
// ---------------------------------------------------------------------------
void wlpk_winwrite( WLPK_FILE* f, const void* data, int32 len )
{
  const char* b8 = (const char*)data;
  for( int32 i = 0; i < len; i++, f->wpos++ )
  {
    if( f->wpos == 1024 ) f->wpos = 0;
    f->w[f->wpos] = b8[i];
  }
}
// ---------------------------------------------------------------------------
