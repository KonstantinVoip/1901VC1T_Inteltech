// ---------------------------------------------------------------------------
// char* strstr( register const char* string1, const char* string2 )
// ---------------------------------------------------------------------------
extern "C" char* strstr( register const char* string1, const char* string2 )
{
  register char cp1, cp2;
  register const char* pos = string1;
  while( *string1 )
  {
    register const char* cmp = string2;
    while( ( ( cp1 = *string1++ ) == ( cp2 = *cmp++ ) ) && cp1 );
    if( cp2 == 0 ) return (char*)pos;
    string1 = ++pos;
  }
  return 0;
}
// ---------------------------------------------------------------------------
