// ---------------------------------------------------------------------------
#include <os.h>
// ---------------------------------------------------------------------------
int32 modsyn_m448c15_error( int32 error )
{
  // Local definitions
  #define SOFTINT_MAIN    ( 1 << 8 )
  #define SOFTINT_IFACE   ( 1 << 14 )
  #define SOFTINT_ALLBITS ( SOFTINT_MAIN | SOFTINT_IFACE )

  // Generate software interrupt
  register uint32 is = int_disable();
  REG_GPVAL &= ~SOFTINT_ALLBITS;
  asm( " nop 8 " ); asm( " nop 8 " ); asm( " nop 8 " ); asm( " nop 8 " );
  REG_GPVAL |= SOFTINT_ALLBITS;
  int_enable( is );

  // Return error code
  return error;
}
// ---------------------------------------------------------------------------

s_os_extension modsyn;

s_os_extension_f modsyn_f[] =
{
  { NULL, SYSCALL_SYN_ERROR,     (uint32)&modsyn_m448c15_error      }
};

// ---------------------------------------------------------------------------
OS_MODULE_INICIATOR( modsyn )
{
  OS_MODULE_INIT( modsyn )
  {
    modsyn.name = "modsyn.lif";
    modsyn.f_count = sizeof(modsyn_f) / sizeof(s_os_extension_f);
    modsyn.f_tab = modsyn_f;
    modsyn.flags = EXT_F_STATIC;
    ext_plug( &modsyn );
  }
  OS_MODULE_DEINIT( modsyn ) { }
}
OS_MODULE_ACTIVATOR( modsyn );
// ---------------------------------------------------------------------------
