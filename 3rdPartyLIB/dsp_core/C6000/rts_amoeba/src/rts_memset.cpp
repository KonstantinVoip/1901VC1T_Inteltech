// ---------------------------------------------------------------------------
// void* memset( void *dst, int fill, size_t len )
// ---------------------------------------------------------------------------
#include <rts.h>
// ---------------------------------------------------------------------------
extern "C" void* memset( void* dst, int fill, size_t len )
{
#ifdef CHIP_1808
  const unsigned char uc = (unsigned char)fill;
  unsigned char *su = (unsigned char *)dst;

  for (; 0 < len; ++su, --len)
    *su = uc;
  return dst;
#else  
  char* dst1;
  char* dst2;
  int pre_bytes, post_bytes, wfill, i;
  double dfill1, dfill2;

  dst1 = (char*)dst;

  wfill = _pack2( fill,  fill );
  wfill = _packl4( wfill, wfill );
  dfill1 = _itod( wfill, wfill );
  dfill2 = _itod( wfill, wfill );

  pre_bytes = ( 8 - (int)dst ) & 7;

  if( len > pre_bytes )
  {
    len -= pre_bytes;
    if( pre_bytes & 1 ) { *dst1 = fill;  dst1 += 1; }
    if( pre_bytes & 2 ) { _amem2( dst1 ) = wfill; dst1 += 2; }
    if( pre_bytes & 4 ) { _amem4( dst1 ) = wfill; dst1 += 4; }
  }

  post_bytes = ( len > 0 ) ? len : 0;   
  dst2 = dst1 + 8;

  if( len > 15 )
  {
    for( i = 0; i < ( len >> 4 ); i++ )
    {
      _amemd8( dst1 ) = dfill1; dst1 += 16;
      _amemd8( dst2 ) = dfill2; dst2 += 16;
      post_bytes -= 16;
    }
  }

  if( post_bytes & 8 ) { _memd8( dst1 ) = dfill1; dst1 += 8; }
  if( post_bytes & 4 ) { _mem4 ( dst1 ) = wfill; dst1 += 4; }
  if( post_bytes & 2 ) { dst1[0] = wfill; dst1[1] = wfill; dst1 += 2; }
  if( post_bytes & 1 ) { *dst1 = fill; dst1 += 1; }

  return dst;
#endif
}
// ---------------------------------------------------------------------------
