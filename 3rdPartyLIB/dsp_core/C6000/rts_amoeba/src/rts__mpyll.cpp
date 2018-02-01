// ---------------------------------------------------------------------------
// extern "C" unsigned long long _mpyll( unsigned long long src1, unsigned long long src2 )
// ---------------------------------------------------------------------------
extern "C" unsigned long long _mpyll( unsigned long long src1, unsigned long long src2 )
{
  unsigned int src1_lo, src2_lo, src1_hi, src2_hi;
  unsigned int temp1, temp3, temp5;
  unsigned long long temp2, temp4, temp6;
  unsigned long long dst;

  src1_lo = (unsigned int)src1;
  src1_hi = src1 >> 32;
  src2_lo = (unsigned int)src2;
  src2_hi = src2 >> 32;

  temp1 = _mpyu( src1_lo, src2_lo );
  temp2 = ( (unsigned long long)_mpyhlu( src1_lo, src2_lo ) + (unsigned long long)_mpyhlu( src2_lo, src1_lo ) ) << 16;
  temp3 = _mpyhu( src1_lo, src2_lo ) + _mpyu( src1_hi, src2_lo ) + _mpyu( src2_hi, src1_lo ); 
  temp4 = ( (unsigned long long)temp3 ) << 32;
  temp5 = _mpyhlu( src1_hi, src2_lo ) + _mpyhlu( src2_hi, src1_lo ) + _mpyhlu( src2_lo, src1_hi ) + _mpyhlu( src1_lo, src2_hi );
  temp6 = ( (unsigned long long)temp5 ) << 48; 
  dst = temp1 + temp2 + temp4 + temp6;

  return dst;
}
// ---------------------------------------------------------------------------
