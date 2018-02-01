// ---------------------------------------------------------------------------
// void* memcpy( void* dst, const void* src, unsigned int len )
// ---------------------------------------------------------------------------
#include <rts.h>
// ---------------------------------------------------------------------------
void* memcpy( void* dst, const void* src, unsigned int len )
{
#if defined(CHIP_6457) || defined(CHIP_1808)
  char* s_p  = (char*)src;
  char* d_p  = (char*)dst;

  while(len--) *d_p++ = *s_p++;

  return dst;
#else
  char* s_p  = (char*)src;
  char* d_p  = (char*)dst;
  int loop = len >> 3;
  int i;
  if( len & 1 ) *d_p++ = *s_p++;
  if( len & 2 ) { *d_p++ = *s_p++; *d_p++ = *s_p++; }
  if( len & 4 ) { _mem4( d_p ) = _mem4( s_p ); d_p += 4; s_p += 4; }
  if( loop == 1 ) _memd8( d_p ) = _memd8( s_p );
  if( loop >= 2 )
  {
    for( i = 0; i < loop; i++, d_p += 8, s_p += 8 )
    {
      _memd8( d_p ) = _memd8( s_p );
    }
  }
  return dst;
#endif
}
// ---------------------------------------------------------------------------
