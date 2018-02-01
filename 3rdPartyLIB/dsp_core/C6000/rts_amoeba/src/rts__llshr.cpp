// ---------------------------------------------------------------------------
// extern "C" long long _llshr( long long src1, unsigned int src2 )
// ---------------------------------------------------------------------------
extern "C" long long _llshr( long long src1, unsigned int src2 )
{
  unsigned int src1_lo = (unsigned int)src1;
  int src1_hi = src1 >> 32;
  unsigned int dst_lo, dst_hi;

  if( src2 < 32 )
  {
    unsigned int hi_to_lo = 32 - src2;
    unsigned int xfer_bits;
    dst_lo = src1_lo >> src2;
    xfer_bits = src1_hi << hi_to_lo;
    dst_lo |= xfer_bits;
    dst_hi = src1_hi >> src2;
  }
  else if( src2 < 64 )
  {
    unsigned int rem = src2 - 32;
    dst_lo = src1_hi >> rem;
    dst_hi = src1_hi >> 31;
  }
  else
  {
    dst_lo = dst_hi = src1_hi >> 31;
  }

  return( _itoll( dst_hi, dst_lo ) );
}
// ---------------------------------------------------------------------------
