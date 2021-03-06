// ---------------------------------------------------------------------------
// char* fgets( char* s, int n, FILE* stream )
// ---------------------------------------------------------------------------
#include <rts.h>
// ---------------------------------------------------------------------------
char* fgets( char* s, int n, FILE* stream )
{
  char* ts = s;
  if( ( s == NULL ) || ( stream == NULL ) ) { errno = EINVAL; return NULL; }
  while( n > 1 )
  {
    if( fread( ts, 1, 1, stream ) != 1 ) break;
    if( (*ts) == '\n' ) { ts++; break; }
    ts++;
    n--;
  }
  (*ts) = 0;
  return s;
}
// ---------------------------------------------------------------------------
