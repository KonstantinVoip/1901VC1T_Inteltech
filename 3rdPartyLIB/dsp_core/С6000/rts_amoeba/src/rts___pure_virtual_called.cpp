// ---------------------------------------------------------------------------
// extern "C" void __abort_execution( an_error_code err_code )
// ---------------------------------------------------------------------------
#include <rts.h>
// ---------------------------------------------------------------------------
extern "C" void __pure_virtual_called( an_error_code err_code )
{
  __abort_execution(ec_pure_virtual_called);
}
// ---------------------------------------------------------------------------
