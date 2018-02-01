// ---------------------------------------------------------------------------
// void* malloc( size_t size )
// ---------------------------------------------------------------------------
#include <os.h>
// ---------------------------------------------------------------------------
void* malloc( size_t size )
{
  s_os_heap* pheap = prc_heap();
  if( pheap == NULL )
  {
    int32 asize = size;
    if( asize & 4095 ) asize = ( asize & 0xfffff000 ) + 4096;
    pheap = heap_create( asize );
    if( pheap == NULL ) return NULL;
  }
  return heap_alloc( pheap, size, HEAP_ALIGN_8 );
}
// ---------------------------------------------------------------------------
