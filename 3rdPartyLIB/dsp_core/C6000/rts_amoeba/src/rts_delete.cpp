// ---------------------------------------------------------------------------
// operator delete redeclaration
// operator delete[] redeclaration
// ---------------------------------------------------------------------------
#include <rts.h>
// ---------------------------------------------------------------------------
void operator delete( void* ptr )
{
  if( ptr != NULL ) free( ptr );
}
// ---------------------------------------------------------------------------
void operator delete[]( void* ptr )
{
  if( ptr != NULL ) free( ptr );
}
// ---------------------------------------------------------------------------
void operator delete( void* ptr, const std::nothrow_t& nothrow_arg )
{
  if( ptr != NULL ) free( ptr );
}
// ---------------------------------------------------------------------------
void operator delete[]( void* ptr, const std::nothrow_t& nothrow_arg )
{
  if( ptr != NULL ) free( ptr );
}
// ---------------------------------------------------------------------------
void operator delete( void*, void* )
{
  /* Nothing */
}
// ---------------------------------------------------------------------------
void operator delete[]( void*, void* )
{
  /* Nothing */
}
// ---------------------------------------------------------------------------
