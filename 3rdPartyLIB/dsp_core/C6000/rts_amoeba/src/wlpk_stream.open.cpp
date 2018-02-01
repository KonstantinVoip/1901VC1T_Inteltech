#include <rts.h>
// ---------------------------------------------------------------------------
static uint8 wlpk_mode( const char* m )
{
  uint8 r = 0;
  while( (*m) )
  {
    if( (*m) == 'r' ) r |= 2;
    else if( (*m) == 'w' ) r |= 1;
    m++;
  }
  if( r == 3 ) r = 0;
  return r;
}
// ---------------------------------------------------------------------------
WLPK_FILE* wlpk_open( const char* fname, const char* mode )
{
  WLPK_FILE* f;
  uint8 m = wlpk_mode( mode );

  if( ( fname == NULL ) || ( mode == NULL ) ) return NULL;
  if( m == 0 ) return NULL;
  
  f = new WLPK_FILE;
  if( f == NULL ) return NULL;
  memset( f, 0, sizeof(WLPK_FILE) );

  f->f = bit_open( fname, mode );
  if( f->f == NULL )
  {
    delete f;
    return NULL;
  }

  f->mode = m;
  
  return f;
}
// ---------------------------------------------------------------------------
