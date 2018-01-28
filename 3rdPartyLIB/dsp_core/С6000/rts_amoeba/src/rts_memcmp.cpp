// ---------------------------------------------------------------------------
// int memcmp( const void* cs, const void* ct, size_t n )
// ---------------------------------------------------------------------------
#include <rts.h>
// ---------------------------------------------------------------------------
extern "C" int memcmp( const void* cs, const void* ct, size_t n )
{
  if( n )
  {
    const unsigned char* mem1 = (unsigned char*)cs - 1;
    const unsigned char* mem2 = (unsigned char*)ct - 1;
    int cp;
    while( ( cp = *++mem1 ) == *++mem2 && --n );
    return cp - *mem2;
  }
  return 0;
}
// ---------------------------------------------------------------------------
