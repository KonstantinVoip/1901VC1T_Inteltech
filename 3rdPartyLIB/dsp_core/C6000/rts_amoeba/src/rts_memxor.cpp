// ---------------------------------------------------------------------------
#include <rts.h>
// ---------------------------------------------------------------------------
extern "C" void memxor( void* dst, const void* src1, const void* src2, uint32 length )
{
  uint8* s1 = (uint8*)const_cast<void*>( src1 );
  uint8* s2 = (uint8*)const_cast<void*>( src2 );
  uint8* d = (uint8*)const_cast<void*>( dst );
  while( length-- )
  {
    (*d) = (*s1) ^ (*s2);
    d++; s1++; s2++;
  }
}
// ---------------------------------------------------------------------------
