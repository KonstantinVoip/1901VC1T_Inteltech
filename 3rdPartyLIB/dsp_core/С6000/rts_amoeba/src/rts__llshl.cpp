// ---------------------------------------------------------------------------
// extern "C" unsigned long long _llshl( unsigned long long src1, unsigned int src2 )
// ---------------------------------------------------------------------------
extern "C" unsigned long long _llshl( unsigned long long src1, unsigned int src2 )
{
  unsigned int src1_lo = (unsigned int)src1;
  unsigned int src1_hi = src1 >> 32;
  unsigned int dst_lo, dst_hi;

  if( !src1 || !src2 ) return src1;

  if( src2 < 32 )
  {
    unsigned int lo_to_hi = 32 - src2;
    unsigned int xfer_bits;
    dst_lo = src1_lo << src2;
    xfer_bits = src1_lo >> lo_to_hi;
    dst_hi = ( src1_hi << src2 ) | xfer_bits;
    return( (unsigned long long)_itoll( dst_hi, dst_lo ) );
  }
  
  if( src2 < 64 )
  {
    unsigned int rem = src2 - 32;
    dst_hi = src1_lo << rem;
    dst_lo = 0;
    return( (unsigned long long)_itoll( dst_hi, dst_lo ) );
  }

  return 0ull;
}
// ---------------------------------------------------------------------------
