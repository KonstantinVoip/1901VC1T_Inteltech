// ---------------------------------------------------------------------------
// extern "C" void __add_dtor( s_rts_dtorlist* dtor_entry )
// extern "C" void __call_dtors()
// ---------------------------------------------------------------------------
#include <rts.h>
// ---------------------------------------------------------------------------

s_rts_dtorlist* __rts_dtors = NULL;

// ---------------------------------------------------------------------------
extern "C" void __add_dtor( s_rts_dtorlist* dtor_entry )
{
  dtor_entry->next = __rts_dtors;
  __rts_dtors = dtor_entry;
}
// ---------------------------------------------------------------------------
extern "C" void __call_dtors()
{
  s_rts_dtorlist *cdtor = __rts_dtors;
  s_rts_dtorlist *tdtor;
  while( cdtor )
  {
    tdtor = cdtor;
    cdtor = cdtor->next;
    if( tdtor->object )
    {
      tdtor->fun.dtor( tdtor->object, 2 );
    }
    else
    {
      tdtor->fun.dfun();
    }
  }
}
// ---------------------------------------------------------------------------
