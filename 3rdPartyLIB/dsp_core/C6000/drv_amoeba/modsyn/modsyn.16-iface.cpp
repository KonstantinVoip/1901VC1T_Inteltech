// ---------------------------------------------------------------------------
#include <os.h>
// ---------------------------------------------------------------------------

static uint32 syn_sem = RES_VOID;
static uint32 syn_sem_timeout = 60000;
static void (*syn_callback)(int32) = NULL;
static bool syn_inited = false;
static int32 syn_process_count = 0;
static uint32* syn_started = NULL;

// ---------------------------------------------------------------------------
int32 modsyn_m448i16_error( int32 error )
{
  // Local definitions
  #define REG_FPGA_NMI_CONTROL  (*(volatile uint16*)0x60000034)
  #define NMI_CONTROL_ENABLE    0x00000001
  #define NMI_CONTROL_SOFTINT   0x00000002

  // Generate software interrupt
  register uint32 is = int_disable();
  REG_FPGA_NMI_CONTROL = NMI_CONTROL_ENABLE | NMI_CONTROL_SOFTINT;
  asm( " nop 8 " ); asm( " nop 8 " ); asm( " nop 8 " ); asm( " nop 8 " );
  REG_FPGA_NMI_CONTROL = NMI_CONTROL_ENABLE;
  int_enable( is );

  // Return error code
  return error;
}
// ---------------------------------------------------------------------------
static void modsyn_fail( int32 error )
{
  if( syn_callback ) syn_callback( error );
  while( true )
    asm( " nop " );
}
// ---------------------------------------------------------------------------
int32 modsyn_m448i16_init( int32 v, uint32 tmo_ms, void (*cbfail)(int32) )
{
  if( syn_inited ) return OSE_OK;
  int32 i = sizeof(uint32) * v;
  if( ( v <= 0 ) || ( v >= 65536 ) ) modsyn_fail( OSE_BAD_PARAM );
  syn_sem_timeout = tmo_ms;
  syn_process_count = v;
  syn_started = (uint32*)heap_alloc( NULL, i, HEAP_ALIGN_4 );
  if( syn_started == NULL ) modsyn_fail( OSE_NO_MEMORY );
  memset( syn_started, 0, i );
  syn_sem = sem_alloc( 1, NULL );
  if( syn_sem == RES_VOID ) modsyn_fail( OSE_CANT_CREATE_SEM );
  syn_inited = true;
  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 modsyn_m448i16_begin()
{
  register uint16 p;
  if( !syn_inited ) return OSE_OK;
  if( ( p = prc_id() ) >= syn_process_count ) modsyn_fail( OSE_TOO_BIG_PROCESS_ID );
  if( syn_started[p] != 0 )
  {
    syn_started[p]++;
    return OSE_OK;
  }
  if( sem_lock( syn_sem, syn_sem_timeout ) != OSE_OK ) modsyn_fail( OSE_SYN_FAIL );
  syn_started[p]++;
  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 modsyn_m448i16_end()
{
  register uint16 p;
  if( !syn_inited ) return OSE_OK;
  if( ( p = prc_id() ) >= syn_process_count ) modsyn_fail( OSE_TOO_BIG_PROCESS_ID );
  if( syn_started[p] == 0 ) modsyn_fail( OSE_OUT_OF_A_RANGE );
  if( syn_started[p] == 1 ) sem_unlock( syn_sem );
  syn_started[p]--;
  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 modsyn_m448i16_open_close( uint16 pid )
{
  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 modsyn_m448i16_time_s( uint32* tm_s )
{
  (*tm_s) = time_s();
  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 modsyn_m448i16_time_m( uint64* tm_m )
{
  (*tm_m) = time_m();
  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 modsyn_m448i16_time_u( uint64* tm_u )
{
  (*tm_u) = time_u();
  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 modsyn_m448i16_time_core( uint64* tm_u )
{
  (*tm_u) = time_core();
  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 modsyn_m448i16_read_osts( uint32* osts0_m0, uint32* osts1_m0, uint32* osts0_m1, uint32* osts1_m1 )
{
  if( osts0_m0 ) (*osts0_m0) = REG_OSTS0;
  if( osts1_m0 ) (*osts1_m0) = REG_OSTS1;
  if( osts0_m1 ) (*osts0_m1) = REG_OSTS0;
  if( osts1_m1 ) (*osts1_m1) = REG_OSTS1;
  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 modsyn_m448i16_data( void* data, uint32 length, int32 prcn )
{
  if( length > 512 ) return OSE_TOO_MANY_DATA;
  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 modsyn_m448i16_wait_tm(uint64 timeout_us)
{
  return OSE_OK;
}
// ---------------------------------------------------------------------------

s_os_extension modsyn;

s_os_extension_f modsyn_f[] =
{
  { NULL, SYSCALL_SYN_INIT,      (uint32)&modsyn_m448i16_init       },
  { NULL, SYSCALL_SYN_OPEN,      (uint32)&modsyn_m448i16_open_close },
  { NULL, SYSCALL_SYN_CLOSE,     (uint32)&modsyn_m448i16_open_close },
  { NULL, SYSCALL_SYN_BEGIN,     (uint32)&modsyn_m448i16_begin      },
  { NULL, SYSCALL_SYN_END,       (uint32)&modsyn_m448i16_end        },
  { NULL, SYSCALL_SYN_TIME_S,    (uint32)&modsyn_m448i16_time_s     },
  { NULL, SYSCALL_SYN_TIME_M,    (uint32)&modsyn_m448i16_time_m     },
  { NULL, SYSCALL_SYN_TIME_U,    (uint32)&modsyn_m448i16_time_u     },
  { NULL, SYSCALL_SYN_TIME_CORE, (uint32)&modsyn_m448i16_time_core  },
  { NULL, SYSCALL_SYN_READ_OSTS, (uint32)&modsyn_m448i16_read_osts  },
  { NULL, SYSCALL_SYN_DATA,      (uint32)&modsyn_m448i16_data       },
  { NULL, SYSCALL_SYN_ERROR,     (uint32)&modsyn_m448i16_error      },
  { NULL, SYSCALL_SYN_WAIT_TM,   (uint32)&modsyn_m448i16_wait_tm    }
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
