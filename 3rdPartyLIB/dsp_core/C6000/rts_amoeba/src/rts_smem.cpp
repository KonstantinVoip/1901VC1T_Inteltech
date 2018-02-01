// ---------------------------------------------------------------------------
#include <rts.h>
// ---------------------------------------------------------------------------
//#define LIST_WIC
// ---------------------------------------------------------------------------
#define _LIST_TAIL_LINK( list, e )                      \
{                                                       \
  e->next = NULL;                                       \
                                                        \
  if( list##_last == NULL )                             \
  {                                                     \
    e->prev = NULL;                                     \
    list##_first = e;                                   \
  }                                                     \
  else                                                  \
  {                                                     \
    e->prev = list##_last;                              \
    list##_last->next = e;                              \
  }                                                     \
                                                        \
  list##_last = e;                                      \
  list##_count++;                                       \
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
#define _LIST_TAIL_LINK_WIC( list, e )                  \
{                                                       \
  register int32 is = os_interrupt_disable_ll();        \
                                                        \
  e->next = NULL;                                       \
                                                        \
  if( list##_last == NULL )                             \
  {                                                     \
    e->prev = NULL;                                     \
    list##_first = e;                                   \
  }                                                     \
  else                                                  \
  {                                                     \
    e->prev = list##_last;                              \
    list##_last->next = e;                              \
  }                                                     \
                                                        \
  list##_last = e;                                      \
  list##_count++;                                       \
                                                        \
  os_interrupt_enable_ll( is );                         \
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
#define _LIST_HEAD_LINK( list, e )                      \
{                                                       \
  e->prev = NULL;                                       \
                                                        \
  if( list##_first == NULL )                            \
  {                                                     \
    e->next = NULL;                                     \
    list##_last = e;                                    \
  }                                                     \
  else                                                  \
  {                                                     \
    e->next = list##_first;                             \
    list##_first->prev = e;                             \
  }                                                     \
                                                        \
  list##_first = e;                                     \
  list##_count++;                                       \
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
#define _LIST_HEAD_LINK_WIC( list, e )                  \
{                                                       \
  register int32 is = os_interrupt_disable_ll();        \
                                                        \
  e->prev = NULL;                                       \
                                                        \
  if( list##_first == NULL )                            \
  {                                                     \
    e->next = NULL;                                     \
    list##_last = e;                                    \
  }                                                     \
  else                                                  \
  {                                                     \
    e->next = list##_first;                             \
    list##_first->prev = e;                             \
  }                                                     \
                                                        \
  list##_first = e;                                     \
  list##_count++;                                       \
                                                        \
  os_interrupt_enable_ll( is );                         \
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
#define _LIST_TAIL_UNLINK( list, e )                    \
{                                                       \
  if( ( e = list##_last ) != NULL )                     \
  {                                                     \
    list##_last = e->prev;                              \
    if( list##_last ) list##_last->next = NULL;         \
    else list##_first = NULL;                           \
    e->prev = NULL;                                     \
    e->next = NULL;                                     \
    list##_count--;                                     \
  }                                                     \
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
#define _LIST_TAIL_UNLINK_WIC( list, e )                \
{                                                       \
  register int32 is = os_interrupt_disable_ll();        \
                                                        \
  if( ( e = list##_last ) != NULL )                     \
  {                                                     \
    list##_last = e->prev;                              \
    if( list##_last ) list##_last->next = NULL;         \
    else list##_first = NULL;                           \
    e->prev = NULL;                                     \
    e->next = NULL;                                     \
    list##_count--;                                     \
  }                                                     \
                                                        \
  os_interrupt_enable_ll( is );                         \
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
#define _LIST_HEAD_UNLINK( list, e )                    \
{                                                       \
  if( ( e = list##_first ) != NULL )                    \
  {                                                     \
    list##_first = e->next;                             \
    if( list##_first ) list##_first->prev = NULL;       \
    else list##_last = NULL;                            \
    e->prev = NULL;                                     \
    e->next = NULL;                                     \
    list##_count--;                                     \
  }                                                     \
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
#define _LIST_HEAD_UNLINK_WIC( list, e )                \
{                                                       \
  register int32 is = os_interrupt_disable_ll();        \
                                                        \
  if( ( e = list##_first ) != NULL )                    \
  {                                                     \
    list##_first = e->next;                             \
    if( list##_first ) list##_first->prev = NULL;       \
    else list##_last = NULL;                            \
    e->prev = NULL;                                     \
    e->next = NULL;                                     \
    list##_count--;                                     \
  }                                                     \
                                                        \
  os_interrupt_enable_ll( is );                         \
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
#define _LIST_UNLINK( list, e )                                         \
{                                                                       \
  if( e->prev ) e->prev->next = e->next; else list##_first = e->next;   \
  if( e->next ) e->next->prev = e->prev; else list##_last = e->prev;    \
  e->prev = NULL;                                                       \
  e->next = NULL;                                                       \
  list##_count--;                                                       \
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
#define _LIST_UNLINK_WIC( list, e )                                     \
{                                                                       \
  register int32 is = os_interrupt_disable_ll();                        \
                                                                        \
  if( e->prev ) e->prev->next = e->next; else list##_first = e->next;   \
  if( e->next ) e->next->prev = e->prev; else list##_last = e->prev;    \
  e->prev = NULL;                                                       \
  e->next = NULL;                                                       \
  list##_count--;                                                       \
                                                                        \
  os_interrupt_enable_ll( is );                                         \
}
// ---------------------------------------------------------------------------
#ifdef LIST_WIC
#
#  define LIST_UNLINK           _LIST_UNLINK_WIC
#  define LIST_HEAD_UNLINK      _LIST_HEAD_UNLINK_WIC
#  define LIST_TAIL_UNLINK      _LIST_TAIL_UNLINK_WIC
#  define LIST_HEAD_LINK        _LIST_HEAD_LINK_WIC
#  define LIST_TAIL_LINK        _LIST_TAIL_LINK_WIC
#
#else
#
#  define LIST_UNLINK           _LIST_UNLINK
#  define LIST_HEAD_UNLINK      _LIST_HEAD_UNLINK
#  define LIST_TAIL_UNLINK      _LIST_TAIL_UNLINK
#  define LIST_HEAD_LINK        _LIST_HEAD_LINK
#  define LIST_TAIL_LINK        _LIST_TAIL_LINK
#
#endif
// ---------------------------------------------------------------------------
struct s_smem_block
{
  s_smem_block*                 prev;
  s_smem_block*                 next;
};
// ---------------------------------------------------------------------------
static s_smem_block*            bfree_first;
static s_smem_block*            bfree_last;
static int32                    bfree_count;
static s_smem_block*            bused_first;
static s_smem_block*            bused_last;
static int32                    bused_count;
// ---------------------------------------------------------------------------
int smem_init( int bcount, int bsize )
{
  int32 sz, i;
  s_os_mem_block* page;
  char* ptr;

  bfree_first = NULL;
  bfree_last = NULL;
  bfree_count = 0;
  bused_first = NULL;
  bused_last = NULL;
  bused_count = 0;
  s_smem_block* nowarn = bused_first;
  bused_first = nowarn;

//  if( bsize & 7 ) bsize = ( bsize & 0xfffffff8 ) + 8;

  bsize = (bsize+0x3f)&~0x3f;
  int s_size=(sizeof(s_smem_block)+0x3f)&~0x3f;

  sz = ((sizeof(s_os_mem_block)+0x3f)&~0x3f)+(bsize+s_size )* bcount;

  page = mem_alloc( sz, /*MPAGE_ALL*/1 );
  if( page == NULL ) return -2;
  ptr = (char*)page + ((sizeof(s_os_mem_block)+0x3f)&~0x3f);
//  memset( ptr, 0, sz );

  for( i = 0; i < bcount; i++ )
  {
    s_smem_block* block = (s_smem_block*)ptr;
    memset( block, 0, sizeof(s_smem_block));
    LIST_TAIL_LINK( bfree, block );
    ptr += bsize + s_size;
  }

  return 0;
}
// ---------------------------------------------------------------------------
void* smem_alloc()
{
  s_smem_block* block;
  LIST_HEAD_UNLINK( bfree, block );
  if( block == NULL ) return NULL;
  LIST_TAIL_LINK( bused, block );
  return (void*)( (char*)block + sizeof(s_smem_block) );
}
// ---------------------------------------------------------------------------
void smem_free( void* ptr )
{
  s_smem_block* block;
  if( ptr == NULL ) return;
  block = (s_smem_block*)( (char*)ptr - sizeof(s_smem_block) );
  LIST_UNLINK( bused, block );
  LIST_TAIL_LINK( bfree, block );
}
// ---------------------------------------------------------------------------
