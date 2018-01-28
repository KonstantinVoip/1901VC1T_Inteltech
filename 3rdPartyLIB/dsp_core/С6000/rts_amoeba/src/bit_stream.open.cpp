#include <rts.h>
// ---------------------------------------------------------------------------
static uint8 bit_mode( const char* m )
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
BIT_FILE* bit_open( const char* fname, const char* mode )
{
  BIT_FILE* f;
  uint8 m = bit_mode( mode );

  if( ( fname == NULL ) || ( mode == NULL ) ) return NULL;
  if( m == 0 ) return NULL;
  
  f = new BIT_FILE;
  if( f == NULL ) return NULL;
  memset( f, 0, sizeof(BIT_FILE) );

  f->f = fopen( fname, mode );
  if( f->f == NULL )
  {
    delete f;
    return NULL;
  }

  f->mode = m;
  
  return f;
}
// ---------------------------------------------------------------------------
