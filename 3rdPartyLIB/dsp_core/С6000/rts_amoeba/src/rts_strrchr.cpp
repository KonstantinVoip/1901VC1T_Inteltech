// ---------------------------------------------------------------------------
// char* strrchr( const char* string, int c )
// ---------------------------------------------------------------------------
extern "C" char* strrchr( const char* string, int c )
{
  char tch, ch = c;
  char* result = 0;
  const char* s = string - 1;
  for( ; ; )
  {
    if( ( tch = *++s ) == ch ) result = (char*)s;
    if( !tch ) break;
  }
  return result;
}
// ---------------------------------------------------------------------------
