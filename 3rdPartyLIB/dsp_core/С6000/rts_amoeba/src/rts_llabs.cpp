// ---------------------------------------------------------------------------
// extern "C" long long llabs( long long i )
// ---------------------------------------------------------------------------
extern "C" long long llabs( long long i )
{
  if( i < 0 ) i = -i;
  return i;
}
// ---------------------------------------------------------------------------
