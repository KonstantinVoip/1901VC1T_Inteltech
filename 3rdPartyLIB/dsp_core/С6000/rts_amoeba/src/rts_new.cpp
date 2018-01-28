// ---------------------------------------------------------------------------
// std::operator new redeclaration
// std::operator new[] redeclaration
// ---------------------------------------------------------------------------
#include <rts.h>
// ---------------------------------------------------------------------------

const std::nothrow_t nothrow = 0;

// ---------------------------------------------------------------------------
void* operator new( size_t size )
{
  return (void*)malloc( size );
}
// ---------------------------------------------------------------------------
void* operator new[]( size_t size )
{
  return (void*)malloc( size );
}
// ---------------------------------------------------------------------------
void* operator new( size_t size, const std::nothrow_t& nothrow_arg )
{
  if( size == 0 ) size = 1;
  return (void*)malloc( size );
}
// ---------------------------------------------------------------------------
void* operator new[]( size_t size, const std::nothrow_t& nothrow_arg )
{
  return operator new( size, nothrow );
}
// ---------------------------------------------------------------------------
void* operator new( size_t s, void* ptr )
{
  return ptr;
}
// ---------------------------------------------------------------------------
void* operator new[]( size_t s, void* ptr )
{
  return ptr;
}
// ---------------------------------------------------------------------------
