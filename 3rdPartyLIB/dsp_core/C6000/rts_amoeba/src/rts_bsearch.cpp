// ---------------------------------------------------------------------------
// void* bsearch( register const void* key, register const void* base, size_t nmemb, size_t size, int (*compar)( const void*, const void* ) )
// ---------------------------------------------------------------------------
#include <stddef.h>
// ---------------------------------------------------------------------------
void* bsearch( register const void* key, register const void* base, size_t nmemb, size_t size, int (*compar)( const void*, const void* ) )
{
  register int i = 0;
  register int j = nmemb - 1;
  while( i <= j )
  {
    register int pivot = ( j + i ) >> 1;            
    int result = (*compar)( key, (char*)base + ( pivot * size ) );
    if( result == 0 ) return ( (char*)base + pivot * size );
    if( result < 0 ) j = pivot - 1; else i = pivot + 1;
  }
  return NULL;
}
// ---------------------------------------------------------------------------
