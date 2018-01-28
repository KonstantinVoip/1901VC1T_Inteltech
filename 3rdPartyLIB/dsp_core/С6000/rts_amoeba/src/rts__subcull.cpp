// ---------------------------------------------------------------------------
// extern "C" unsigned long long _subcull( unsigned long long src1, unsigned long long src2 )
// ---------------------------------------------------------------------------
extern "C" unsigned long long _subcull( unsigned long long src1, unsigned long long src2 )
{
  unsigned long long res1 = ( ( src1 - src2 ) << 1 ) | 0x1;
  unsigned long long res2 = src1 << 1;
  if( src1 >= src2 ) return res1;
  return res2;
}
// ---------------------------------------------------------------------------
