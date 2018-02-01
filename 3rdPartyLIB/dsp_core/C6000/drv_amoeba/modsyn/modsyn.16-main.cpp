// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: m448-16-main, m632-main
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp866
// !: d: Модуль реализует менеджер синхронизации спаренных процессоров.
// !: -:
// ---------------------------------------------------------------------------
#include <os.h>
#include <drv_gpio.h>
// ---------------------------------------------------------------------------
#define SYN_STAT
// ---------------------------------------------------------------------------

#define MAIN_X                  0
#define MAIN_0                  1
#define MAIN_1                  2

#define EVENT_BEGIN             0
#define EVENT_END               1

#define INFINITY                0xffffffffffffffff

// ---------------------------------------------------------------------------

#define BASE_ADDRESS            0x6c000000

#define SOFF_DATA0              0
#define SOFF_RXR0               1
#define SOFF_DATA1              2
#define SOFF_RXR1               3
#define SOFF_WAIT_TM0           4//
#define SOFF_WAIT_TM1           5//

#define SOFF_PROCESS            32
#define SOFF_OPEN_CLOSE_PID     34

#define SOFF_TIME_M             64
#define SOFF_TIME_U             72
#define SOFF_TIME_CORE          80
#define SOFF_TIME_S             88
#define SOFF_OSTS0_M0           92
#define SOFF_OSTS1_M0           96
#define SOFF_OSTS0_M1           100
#define SOFF_OSTS1_M1           104

#define SOFF_RESERVED_BPO0      128
#define SOFF_RESERVED_BPO1      129

#define SOFF_DATA_STATUS        251
#define SOFF_DATA_LENGTH        252
#define SOFF_DATA               256

// ---------------------------------------------------------------------------

#define SREG_DATA0              (*(volatile uint8* )( BASE_ADDRESS + SOFF_DATA0          ))
#define SREG_RXR0               (*(volatile uint8* )( BASE_ADDRESS + SOFF_RXR0           ))
#define SREG_DATA1              (*(volatile uint8* )( BASE_ADDRESS + SOFF_DATA1          ))
#define SREG_RXR1               (*(volatile uint8* )( BASE_ADDRESS + SOFF_RXR1           ))
#define SREG_WAIT_TM0           (*(volatile uint8* )( BASE_ADDRESS + SOFF_WAIT_TM0       ))
#define SREG_WAIT_TM1           (*(volatile uint8* )( BASE_ADDRESS + SOFF_WAIT_TM1       ))

#define SREG_PROCESS            (*(volatile uint16*)( BASE_ADDRESS + SOFF_PROCESS        ))
#define SREG_OPEN_CLOSE_PID     (*(volatile uint16*)( BASE_ADDRESS + SOFF_OPEN_CLOSE_PID ))

#define SREG_TIME_M             (*(volatile uint64*)( BASE_ADDRESS + SOFF_TIME_M         ))
#define SREG_TIME_U             (*(volatile uint64*)( BASE_ADDRESS + SOFF_TIME_U         ))
#define SREG_TIME_S             (*(volatile uint32*)( BASE_ADDRESS + SOFF_TIME_S         ))
#define SREG_TIME_CORE          (*(volatile uint32*)( BASE_ADDRESS + SOFF_TIME_CORE      ))
#define SREG_OSTS0_M0           (*(volatile uint32*)( BASE_ADDRESS + SOFF_OSTS0_M0       ))
#define SREG_OSTS1_M0           (*(volatile uint32*)( BASE_ADDRESS + SOFF_OSTS1_M0       ))
#define SREG_OSTS0_M1           (*(volatile uint32*)( BASE_ADDRESS + SOFF_OSTS0_M1       ))
#define SREG_OSTS1_M1           (*(volatile uint32*)( BASE_ADDRESS + SOFF_OSTS1_M1       ))

#define SREG_DATA_STATUS        (*(volatile uint8* )( BASE_ADDRESS + SOFF_DATA_STATUS    ))
#define SREG_DATA_LENGTH        (*(volatile uint32*)( BASE_ADDRESS + SOFF_DATA_LENGTH    ))
#define SREG_DATA               ( (volatile uint8* )( BASE_ADDRESS + SOFF_DATA           ))

// ---------------------------------------------------------------------------

static int32 syn_processor = MAIN_X;
static uint32 syn_process_count = 5;
static uint32* syn_sem = NULL;
//static uint32 syn_interrupt = RES_VOID;
static uint8* syn_mem = (uint8*)0;
static volatile uint8* syn_intr = (volatile uint8*)0;
static volatile uint8* syn_intl = (volatile uint8*)0;
static void (*syn_callback)(int32) = NULL;
uint32* syn_started = NULL;
uint16* syn_trans_tab = NULL;

static volatile uint8* reg_rxdata;
static volatile uint8* reg_txdata;
static volatile uint8* reg_rxr;
static volatile uint8* reg_txr;
static volatile uint8* reg_wait_txr;
static volatile uint8* reg_wait_rxr;
static uint32 off_rxr;
static uint32 off_txr;
static uint32 off_wait_rxr;
static uint64 syn_timeout = 30000000000ull;
static uint32 syn_sem_timeout = 60000;

// ---------------------------------------------------------------------------
static int32 modsyn_m448m16_error( int32 error )
{
/* 
  // Local definitions
  #define SOFTINT_COMM0   ( 1 << 10 )
  #define SOFTINT_COMM1   ( 1 << 9 )
  #define SOFTINT_COMM2   ( 1 << 14 )
  #define SOFTINT_ALLBITS ( SOFTINT_COMM0 | SOFTINT_COMM1 | SOFTINT_COMM2 )

  // Generate interrupt
  register uint32 tdir;
  register uint32 ten;
  register uint32 is = int_disable();
  tdir = REG_GPDIR;
  ten = REG_GPEN;
  REG_GPDIR = tdir | SOFTINT_ALLBITS;
  REG_GPEN = ten | SOFTINT_ALLBITS;
  REG_GPVAL |= SOFTINT_ALLBITS;
  asm( " nop 8 " ); asm( " nop 8 " ); asm( " nop 8 " ); asm( " nop 8 " );
  REG_GPVAL &= ~SOFTINT_ALLBITS;
  REG_GPDIR = tdir;
  REG_GPEN = ten;
  int_enable( is );
*/
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
int64 intk =0;
// ---------------------------------------------------------------------------
static void modsyn_interrupt()
{
  register uint8 cmd = syn_intl[0];
  register uint16 p;
intk++;
  switch( cmd )
  {
    case EVENT_BEGIN:
    {
      if( syn_processor == MAIN_1 )
      {
        p = syn_trans_tab[SREG_PROCESS];
        if( p < syn_process_count )
        {
          sem_unlock( syn_sem[p] );
          int_swto( p );
        }
      }
    }
    break;

    case EVENT_END:
    {
      if( syn_processor == MAIN_0 )
      {
        sem_unlock( syn_sem[1] );
//        sem_unlock_sw( syn_sem[1] );
      }
    }
    break;
  }

}
// ---------------------------------------------------------------------------
static bool modsyn_wait( uint32 address, uint8 b, uint64 tm_n )
{
  uint64 st = time_core_n();
  while( true )
  {
    if( syn_mem[address] == b ) return true;
    if( tm_n == INFINITY )
    {
      prc_yield();
      continue;
    }
    if( ( time_core_n() - st ) >= (uint64)tm_n ) break;
    prc_yield();
  }
  return false;
}
// ---------------------------------------------------------------------------
static bool modsyn_check( uint8 b )
{
  for( int32 i = 0; i < 1022; i++ ) if( syn_mem[i] != b ) return false;
  return true;
}
// ---------------------------------------------------------------------------
static bool modsyn_read( uint8* v )
{
  if( !modsyn_wait( off_rxr, 1, syn_timeout ) ) return false;
  (*v) = (*reg_rxdata);
  (*reg_rxr) = 0;
  return true;
}
// ---------------------------------------------------------------------------
static bool modsyn_write( uint8 v )
{
  if( !modsyn_wait( off_txr, 0, syn_timeout ) ) return false;
  (*reg_txdata) = v;
  (*reg_txr) = 1;
  return true;
}
// ---------------------------------------------------------------------------
static bool modsyn_handshake()
{
  uint8 v;
  if( syn_processor == MAIN_0 )
  {
    if( !modsyn_write( 5 ) ) return false;
    if( !modsyn_read( &v ) ) return false;
    if( v != 5 ) return false;
  }
  else if( syn_processor == MAIN_1 )
  {
    if( !modsyn_read( &v ) ) return false;
    if( v != 5 ) return false;
    if( !modsyn_write( 5 ) ) return false;
  }
  return true;
}
// ---------------------------------------------------------------------------
static int32 modsyn_test_side( uint32 side )
{
  register volatile uint8* lreg = &syn_mem[256+side];
  register volatile uint8* rreg = &syn_mem[256+(side^1)];
  uint8 v;

  while( true )
  {
    if( (*lreg) == 255 )
    {
      if( (*rreg) == 255 ) break;
    }
    else
    {
      if( (*lreg) <= (*rreg) ) (*lreg)++;
    } 
  }

  if( side == 0 ) memset( syn_mem, 0, 1022 );
  sleep_m( 1 );

  if( side == 0 )
  {
    if( !modsyn_write( 128 ) ) return OSE_SIDE_TEST_ERROR;
    if( !modsyn_read( &v ) ) return OSE_SIDE_TEST_ERROR;
    if( v != 128 ) return OSE_SIDE_TEST_ERROR;
  }
  else
  {
    if( !modsyn_read( &v ) ) return OSE_SIDE_TEST_ERROR;
    if( v != 128 ) return OSE_SIDE_TEST_ERROR;
    if( !modsyn_write( 128 ) ) return OSE_SIDE_TEST_ERROR;
  }

  return OSE_OK;
}
// ---------------------------------------------------------------------------
static int32 modsyn_test_active()
{
  uint32 i;
  uint8 v;

  // Side test and initial pipe buffer cleaning
  if( modsyn_test_side( 0 ) != OSE_OK ) modsyn_fail( OSE_SIDE_TEST_ERROR );

  // Synchronize
  if( !modsyn_write( 2 ) ) modsyn_fail( OSE_SIDE_TEST_ERROR );
  if( !modsyn_read( &v ) ) modsyn_fail( OSE_SIDE_TEST_ERROR );
  if( v != 2 ) modsyn_fail( OSE_SIDE_TEST_ERROR );

  // Address test
  for( i = 0; i < 1022; i++ ) syn_mem[i] = ( i < 4 ) ? ( 255 - i ) : i;
  for( i = 0; i < 1022; i++ ) if( syn_mem[i] != (uint8)( ( i < 4 ) ? ( 255 - i ) : i ) ) modsyn_fail( OSE_ADDRESS_TEST_ERROR );
  memset( syn_mem, 0, 1022 );
  if( !modsyn_write( 3 ) ) modsyn_fail( OSE_ADDRESS_TEST_ERROR );
  if( !modsyn_read( &v ) ) modsyn_fail( OSE_ADDRESS_TEST_ERROR );
  if( v != 3 ) modsyn_fail( OSE_ADDRESS_TEST_ERROR );

  // Data test
  memset( syn_mem, 0x55, 1022 );
  if( !modsyn_check( 0x55 ) ) modsyn_fail( OSE_DATA_TEST_ERROR );
  memset( syn_mem, 0xaa, 1022 );
  if( !modsyn_check( 0xaa ) ) modsyn_fail( OSE_DATA_TEST_ERROR );
  memset( syn_mem, 0, 1022 );
  if( !modsyn_write( 4 ) ) modsyn_fail( OSE_DATA_TEST_ERROR );
  if( !modsyn_read( &v ) ) modsyn_fail( OSE_DATA_TEST_ERROR );
  if( v != 4 ) modsyn_fail( OSE_DATA_TEST_ERROR );

  return OSE_OK;
}
// ---------------------------------------------------------------------------
static int32 modsyn_test_passive()
{
  uint8 v;

  // Side test and initial pipe buffer cleaning
  if( modsyn_test_side( 1 ) != OSE_OK ) modsyn_fail( OSE_SIDE_TEST_ERROR );

  // Synchronize
  if( !modsyn_read( &v ) ) modsyn_fail( OSE_SIDE_TEST_ERROR );
  if( v != 2 ) modsyn_fail( OSE_SIDE_TEST_ERROR );
  if( !modsyn_write( 2 ) ) modsyn_fail( OSE_SIDE_TEST_ERROR );

  // Address test
  if( !modsyn_read( &v ) ) modsyn_fail( OSE_ADDRESS_TEST_ERROR );
  if( v != 3 ) modsyn_fail( OSE_ADDRESS_TEST_ERROR );
  if( !modsyn_write( 3 ) ) modsyn_fail( OSE_ADDRESS_TEST_ERROR );

  // Data test
  if( !modsyn_read( &v ) ) modsyn_fail( OSE_DATA_TEST_ERROR );
  if( v != 4 ) modsyn_fail( OSE_DATA_TEST_ERROR );
  if( !modsyn_write( 4 ) ) modsyn_fail( OSE_DATA_TEST_ERROR );

  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 modsyn_m448m16_init( int32 p_count, uint32 tmo_ms, void (*cbfunc)(int32) )
{
  int32 i, r;

  if( ( p_count <= 0 ) || ( p_count >= 65536 ) ) modsyn_fail( OSE_BAD_PARAM );

  syn_sem_timeout = tmo_ms;
  syn_callback = cbfunc;
  syn_mem = (uint8*)BASE_ADDRESS;
  i = sizeof(uint32) * p_count;
  syn_started = (uint32*)heap_alloc( NULL, i, HEAP_ALIGN_4 );
  if( syn_started == NULL ) modsyn_fail( OSE_NO_MEMORY );
  memset( syn_started, 0, i );

  if( ( syn_processor = ( REG_CTL0 & TCTL_DATIN ) ? MAIN_0 : MAIN_1 ) == MAIN_0 )
  {
    // Initialize addresses
    syn_intr = (volatile uint8*)( BASE_ADDRESS + 0x000003ff );
    syn_intl = (volatile uint8*)( BASE_ADDRESS + 0x000003fe );
    reg_rxdata = (volatile uint8*)( BASE_ADDRESS + SOFF_DATA0 );
    reg_txdata = (volatile uint8*)( BASE_ADDRESS + SOFF_DATA1 );
    reg_rxr = (volatile uint8*)( BASE_ADDRESS + SOFF_RXR0 );
    reg_txr = (volatile uint8*)( BASE_ADDRESS + SOFF_RXR1 );
    reg_wait_txr = (volatile uint8*)( BASE_ADDRESS + SOFF_WAIT_TM1 );
    reg_wait_rxr = (volatile uint8*)( BASE_ADDRESS + SOFF_WAIT_TM0 );
    off_rxr = SOFF_RXR0;
    off_txr = SOFF_RXR1;
    off_wait_rxr = SOFF_WAIT_TM0;

    // Perform chip tests
    if( ( r = modsyn_test_active() ) != OSE_OK ) goto l_fail;
    sleep_m( 100 );
    if( ( r = modsyn_test_passive() ) != OSE_OK ) goto l_fail;

    // Create semaphore for MAIN0 processor
    syn_process_count = p_count;
    if( ( syn_sem = (uint32*)heap_alloc( NULL, sizeof(uint32) * 2, HEAP_ALIGN_4 ) ) == NULL ) { r = OSE_NO_MEMORY; goto l_fail; }
    memset( syn_sem, 0, sizeof(uint32) * 2 );
    if( ( syn_sem[0] = sem_alloc( 1, NULL ) ) == RES_VOID ) { r = OSE_CANT_CREATE_SEM; goto l_fail; }
    if( ( syn_sem[1] = sem_alloc( 0, NULL ) ) == RES_VOID ) { r = OSE_CANT_CREATE_SEM; goto l_fail; }
  }
  else
  {
    // Initialize addresses
    syn_intr = (volatile uint8*)( BASE_ADDRESS + 0x000003fe );
    syn_intl = (volatile uint8*)( BASE_ADDRESS + 0x000003ff );
    reg_rxdata = (volatile uint8*)( BASE_ADDRESS + SOFF_DATA1 );
    reg_txdata = (volatile uint8*)( BASE_ADDRESS + SOFF_DATA0 );
    reg_rxr = (volatile uint8*)( BASE_ADDRESS + SOFF_RXR1 );
    reg_txr = (volatile uint8*)( BASE_ADDRESS + SOFF_RXR0 );
    reg_wait_txr = (volatile uint8*)( BASE_ADDRESS + SOFF_WAIT_TM0 );
    reg_wait_rxr = (volatile uint8*)( BASE_ADDRESS + SOFF_WAIT_TM1 );
    off_rxr = SOFF_RXR1;
    off_txr = SOFF_RXR0;
    off_wait_rxr = SOFF_WAIT_TM1;

    // Perform chip tests
    if( ( r = modsyn_test_passive() ) != OSE_OK ) goto l_fail;
    sleep_m( 100 );
    if( ( r = modsyn_test_active() ) != OSE_OK ) goto l_fail;

    // Create PID translation table
    if( ( syn_trans_tab = (uint16*)heap_alloc( NULL, p_count << 1, HEAP_ALIGN_4 ) ) == NULL ) { r = OSE_NO_MEMORY; goto l_fail; }
    for( i = 0; i < p_count; i++ ) syn_trans_tab[i] = i;

    // Create semaphores for MAIN1 processor
    syn_process_count = p_count;
    if( ( syn_sem = (uint32*)heap_alloc( NULL, sizeof(uint32) * syn_process_count, HEAP_ALIGN_4 ) ) == NULL ) { r = OSE_NO_MEMORY; goto l_fail; }
    memset( syn_sem, 0, sizeof(uint32) * syn_process_count );
    for( i = 0; i < syn_process_count; i++ ) if( ( syn_sem[i] = sem_alloc( 0, NULL ) ) == RES_VOID ) { r = OSE_CANT_CREATE_SEM; goto l_fail; }
  }

  // Clear interrupt state
  i = (*syn_intr);
  i = (*syn_intl);

  // All test passed, initialize module
  {
    s_gpio_interrupt vector;
    int32 _r;
    uint32 d = drv_mkd( "/dev/gpio" );
    if( d == RES_VOID ) { r = OSE_CANT_CREATE_INTERRUPT; goto l_fail; }
    vector.number_gpio = 12;
    vector.call_functoin = &modsyn_interrupt;
    _r = drv_ioctl( d, GPIO_INT_ALLOC, &vector );
    drv_rmd( d );
    if( _r != OSE_OK ) { r = _r; goto l_fail; }
  }

  modsyn_handshake();

  return OSE_OK;

l_fail:

  if( syn_sem )
  {
    if( syn_processor == MAIN_0 )
    {
      sem_free( syn_sem[0] );
      sem_free( syn_sem[1] );
    }
    else if( syn_processor == MAIN_1 )
    {
      for( i = 0; i < syn_process_count; i++ ) sem_free( syn_sem[i] );
    }
    heap_free( NULL, syn_sem );
  }

  heap_free( NULL, syn_trans_tab );
  syn_trans_tab = NULL;

//  syn_interrupt = RES_VOID;
  syn_sem = NULL;
  syn_process_count = 0;
  syn_processor = MAIN_X;

  modsyn_fail( r );
  return r;
}
// ---------------------------------------------------------------------------
int32 modsyn_m448m16_begin()
{
  register uint16 p;
  
  if( syn_processor == MAIN_X ) return OSE_OK;
  if( ( p = prc_id() ) >= syn_process_count ) modsyn_fail( OSE_TOO_BIG_PROCESS_ID );
  if( syn_started[p] != 0 )
  {
    syn_started[p]++;
    return OSE_OK;
  }

  if( syn_processor == MAIN_0 )
  {
    if( sem_lock( syn_sem[0], syn_sem_timeout ) != OSE_OK )
      modsyn_fail( OSE_SYN_TIMEOUT );

    SREG_PROCESS = p;
    (*syn_intr) = EVENT_BEGIN;
  }
  else if( syn_processor == MAIN_1 )
  {
    if( sem_lock( syn_sem[p], syn_sem_timeout ) != OSE_OK )
      modsyn_fail( OSE_SYN_TIMEOUT );
  }
  syn_started[p]++;

  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 modsyn_m448m16_end()
{
  register uint16 p;
  
  if( syn_processor == MAIN_X ) return OSE_OK;
  if( ( p = prc_id() ) >= syn_process_count ) modsyn_fail( OSE_TOO_BIG_PROCESS_ID );
  if( syn_started[p] == 0 ) modsyn_fail( OSE_OUT_OF_A_RANGE );
  if( syn_started[p] == 1 )
  {
    if( syn_processor == MAIN_0 )
    {
      if( sem_lock( syn_sem[1], syn_sem_timeout ) != OSE_OK ) modsyn_fail( OSE_SYN_TIMEOUT );
      sem_unlock( syn_sem[0] );
    }
    else if( syn_processor == MAIN_1 )
    {
      (*syn_intr) = EVENT_END;
    }
  }
  syn_started[p]--;

  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 modsyn_m448m16_open( uint16 pid )
{
  int32 r;
  uint8 v;

  if( syn_processor == MAIN_X ) return OSE_OK;

  if( pid >= syn_process_count )
      return OSE_TOO_BIG_PROCESS_ID;

  if( syn_processor == MAIN_X ) return OSE_OK;
  if( ( r = modsyn_m448m16_begin() ) != OSE_OK ) modsyn_fail( r );

  if( syn_processor == MAIN_0 )
  {
    SREG_OPEN_CLOSE_PID = pid;
    if( !modsyn_write( 100 ) ) modsyn_fail( OSE_SYN_FAIL );
  }
  else if( syn_processor == MAIN_1 )
  {
    if( !modsyn_read( &v ) ) modsyn_fail( OSE_SYN_FAIL );
    if( v != 100 ) modsyn_fail( OSE_SYN_FAIL );
    syn_trans_tab[SREG_OPEN_CLOSE_PID] = pid;
  }
  
  if( ( r = modsyn_m448m16_end() ) != OSE_OK ) modsyn_fail( r );
  
  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 modsyn_m448m16_close( uint16 pid )
{
  int32 r;
  uint8 v;

  if( syn_processor == MAIN_X ) return OSE_OK;
  if( ( r = modsyn_m448m16_begin() ) != OSE_OK ) modsyn_fail( r );

  if( syn_processor == MAIN_0 )
  {
    SREG_OPEN_CLOSE_PID = pid;
    if( !modsyn_write( 101 ) ) modsyn_fail( OSE_SYN_FAIL );
  }
  else if( syn_processor == MAIN_1 )
  {
    if( !modsyn_read( &v ) ) modsyn_fail( OSE_SYN_FAIL );
    if( v != 101 ) modsyn_fail( OSE_SYN_FAIL );
    syn_trans_tab[SREG_OPEN_CLOSE_PID] = 0;
  }
  
  if( ( r = modsyn_m448m16_end() ) != OSE_OK ) modsyn_fail( r );

  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 modsyn_m448m16_time_s( uint32* tm_s )
{
  int32 r;
  uint8 v;

  if( syn_processor == MAIN_X )
  {
    _mem4( tm_s ) = time_s();
    return OSE_OK;
  }

  if( ( r = modsyn_m448m16_begin() ) != OSE_OK ) modsyn_fail( r );

  if( syn_processor == MAIN_0 )
  {
    _mem4( tm_s ) = time_s();
    SREG_TIME_S = _mem4( tm_s );
    if( !modsyn_write( 6 ) ) modsyn_fail( OSE_SYN_FAIL );
  }
  else if( syn_processor == MAIN_1 )
  {
    if( !modsyn_read( &v ) ) modsyn_fail( OSE_SYN_FAIL );
    if( v != 6 ) modsyn_fail( OSE_SYN_FAIL );
    _mem4( tm_s ) = SREG_TIME_S;
  }
  
  if( ( r = modsyn_m448m16_end() ) != OSE_OK ) modsyn_fail( r );
  
  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 modsyn_m448m16_time_m( uint64* tm_m )
{
  int32 r;
  uint8 v;

  if( syn_processor == MAIN_X )
  {
    _mem8( tm_m ) = time_m();
    return OSE_OK;
  }

  if( ( r = modsyn_m448m16_begin() ) != OSE_OK ) modsyn_fail( r );

  if( syn_processor == MAIN_0 )
  {
    _mem8( tm_m ) = time_m();
    SREG_TIME_M = _mem8( tm_m );
    if( !modsyn_write( 7 ) ) modsyn_fail( OSE_SYN_FAIL );
  }
  else if( syn_processor == MAIN_1 )
  {
    if( !modsyn_read( &v ) ) modsyn_fail( OSE_SYN_FAIL );
    if( v != 7 ) modsyn_fail( OSE_SYN_FAIL );
    _mem8( tm_m ) = SREG_TIME_M;
  }
  
  if( ( r = modsyn_m448m16_end() ) != OSE_OK ) modsyn_fail( r );
  
  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 modsyn_m448m16_time_u( uint64* tm_u )
{
  int32 r;
  uint8 v;

  if( syn_processor == MAIN_X )
  {
    _mem8( tm_u ) = time_u();
    return OSE_OK;
  }

  if( ( r = modsyn_m448m16_begin() ) != OSE_OK ) modsyn_fail( r );

  if( syn_processor == MAIN_0 )
  {
    _mem8( tm_u ) = time_u();
    SREG_TIME_U = _mem8( tm_u );
    if( !modsyn_write( 8 ) ) modsyn_fail( OSE_SYN_FAIL );
  }
  else if( syn_processor == MAIN_1 )
  {
    if( !modsyn_read( &v ) ) modsyn_fail( OSE_SYN_FAIL );
    if( v != 8 ) modsyn_fail( OSE_SYN_FAIL );
    _mem8( tm_u ) = SREG_TIME_U;
  }
  
  if( ( r = modsyn_m448m16_end() ) != OSE_OK ) modsyn_fail( r );
  
  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 modsyn_m448m16_time_core( uint64* tm_core )
{
  int32 r;
  uint8 v;

  if( syn_processor == MAIN_X )
  {
    _mem8( tm_core ) = time_core();
    return OSE_OK;
  }

  if( ( r = modsyn_m448m16_begin() ) != OSE_OK ) modsyn_fail( r );

  if( syn_processor == MAIN_0 )
  {
    _mem8( tm_core ) = time_core();
    SREG_TIME_CORE = _mem8( tm_core );
    if( !modsyn_write( 9 ) ) modsyn_fail( OSE_SYN_FAIL );
  }
  else if( syn_processor == MAIN_1 )
  {
    if( !modsyn_read( &v ) ) modsyn_fail( OSE_SYN_FAIL );
    if( v != 9 ) modsyn_fail( OSE_SYN_FAIL );
    _mem8( tm_core ) = SREG_TIME_CORE;
  }
  
  if( ( r = modsyn_m448m16_end() ) != OSE_OK ) modsyn_fail( r );
  
  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 modsyn_m448m16_read_osts( uint32* osts0_m0, uint32* osts1_m0, uint32* osts0_m1, uint32* osts1_m1 )
{
  uint8 v;
  register int32 r;

  if( syn_processor == MAIN_X )
  {
    if( osts0_m0 ) (*osts0_m0) = REG_OSTS0;
    if( osts1_m0 ) (*osts1_m0) = REG_OSTS1;
    if( osts0_m1 ) (*osts0_m1) = REG_OSTS0;
    if( osts1_m1 ) (*osts1_m1) = REG_OSTS1;
    return OSE_OK;
  }

  if( ( r = modsyn_m448m16_begin() ) != OSE_OK ) modsyn_fail( r );

  if( syn_processor == MAIN_0 )
  {
    SREG_OSTS0_M0 = REG_OSTS0;
    SREG_OSTS1_M0 = REG_OSTS1;
  }
  else if( syn_processor == MAIN_1 )
  {
    SREG_OSTS0_M1 = REG_OSTS0;
    SREG_OSTS1_M1 = REG_OSTS1;
  }
  if( !modsyn_write( 10 ) ) modsyn_fail( OSE_SYN_FAIL );
  if( !modsyn_read( &v ) ) modsyn_fail( OSE_SYN_FAIL );
  if( v != 10 ) modsyn_fail( OSE_SYN_FAIL );
  
  if( osts0_m0 ) (*osts0_m0) = SREG_OSTS0_M0;
  if( osts1_m0 ) (*osts1_m0) = SREG_OSTS1_M0;
  if( osts0_m1 ) (*osts0_m1) = SREG_OSTS0_M1;
  if( osts1_m1 ) (*osts1_m1) = SREG_OSTS1_M1;

  if( ( r = modsyn_m448m16_end() ) != OSE_OK ) modsyn_fail( r );

  return OSE_OK;
}
// ---------------------------------------------------------------------------
static int32 modsyn_m448m16_data0( void* data, uint32 length )
{
  register int32 r = OSE_OK;
  uint8 v;

  memcpy( (void*)( BASE_ADDRESS + SOFF_DATA ), data, length );
  SREG_DATA_LENGTH = length;
  SREG_DATA_STATUS = 0x00;
  if( !modsyn_write( 11 ) ) modsyn_fail( OSE_SYN_FAIL );

  if( !modsyn_read( &v ) ) modsyn_fail( OSE_SYN_FAIL );
  if( v != 12 ) modsyn_fail( OSE_SYN_FAIL );
  if( SREG_DATA_STATUS == 0x01 )
  {
    r = OSE_DIFFERENT_LENGTH;
  }
  else if( SREG_DATA_STATUS == 0x02 )
  {
    r = OSE_DATA_ALIGNED;
  }

  return r;
}
// ---------------------------------------------------------------------------
static int32 modsyn_m448m16_data1( void* data, uint32 length )
{
  register int32 r = OSE_OK;
  uint8 v;

  if( !modsyn_read( &v ) ) modsyn_fail( OSE_SYN_FAIL );
  if( v != 11 ) modsyn_fail( OSE_SYN_FAIL );

  if( length != SREG_DATA_LENGTH )
  {
    SREG_DATA_STATUS = 0x01;
    r = OSE_DIFFERENT_LENGTH;
  }
  else
  {
    if( memcmp( (void*)( BASE_ADDRESS + SOFF_DATA ), data, length ) != 0 )
    {
      memcpy( data, (void*)( BASE_ADDRESS + SOFF_DATA ), length );
      SREG_DATA_STATUS = 0x02;
      r = OSE_DATA_ALIGNED;
    }
  }
  if( !modsyn_write( 12 ) ) modsyn_fail( OSE_SYN_FAIL );

  return r;
}
// ---------------------------------------------------------------------------
int32 modsyn_m448m16_data( void* data, uint32 length, int32 prcn )
{
  register int32 r = OSE_OK;
  int32 tr;

  if( length > 512 ) modsyn_fail( OSE_TOO_MANY_DATA );
  if( syn_processor == MAIN_X ) return OSE_OK;
  prcn++;

  if( ( r = modsyn_m448m16_begin() ) != OSE_OK ) modsyn_fail( r );

  if( syn_processor == MAIN_0 )
  {
    if( prcn == MAIN_0 )
    {
      r = modsyn_m448m16_data0( data, length );
    }
    else if( prcn == MAIN_1 )
    {
      r = modsyn_m448m16_data1( data, length );
    }
  }
  else if( syn_processor == MAIN_1 )
  {
    if( prcn == MAIN_0 )
    {
      r = modsyn_m448m16_data1( data, length );
    }
    else if( prcn == MAIN_1 )
    {
      r = modsyn_m448m16_data0( data, length );
    }
  }

  if( ( tr = modsyn_m448m16_end() ) != OSE_OK ) modsyn_fail( tr );

  return r;
}
// ---------------------------------------------------------------------------
int32 modsyn_m448m16_wait_tm(uint64 timeout_us)//TIMEOUT V USEC
{
  (*reg_wait_txr) = 0x77;

  if( !modsyn_wait( off_wait_rxr, 0x77, (timeout_us*1000) ) )//TIMEOUT V NSEC
    modsyn_fail( OSE_SYN_TIMEOUT );

  (*reg_wait_rxr) = 0;
  
  return OSE_OK;
}
// ---------------------------------------------------------------------------

s_os_extension modsyn;

s_os_extension_f modsyn_f[] =
{
  { NULL, SYSCALL_SYN_INIT,      (uint32)&modsyn_m448m16_init      },
  { NULL, SYSCALL_SYN_OPEN,      (uint32)&modsyn_m448m16_open      },
  { NULL, SYSCALL_SYN_CLOSE,     (uint32)&modsyn_m448m16_close     },
  { NULL, SYSCALL_SYN_BEGIN,     (uint32)&modsyn_m448m16_begin     },
  { NULL, SYSCALL_SYN_END,       (uint32)&modsyn_m448m16_end       },
  { NULL, SYSCALL_SYN_TIME_S,    (uint32)&modsyn_m448m16_time_s    },
  { NULL, SYSCALL_SYN_TIME_M,    (uint32)&modsyn_m448m16_time_m    },
  { NULL, SYSCALL_SYN_TIME_U,    (uint32)&modsyn_m448m16_time_u    },
  { NULL, SYSCALL_SYN_TIME_CORE, (uint32)&modsyn_m448m16_time_core },
  { NULL, SYSCALL_SYN_READ_OSTS, (uint32)&modsyn_m448m16_read_osts },
  { NULL, SYSCALL_SYN_DATA,      (uint32)&modsyn_m448m16_data      },
  { NULL, SYSCALL_SYN_ERROR,     (uint32)&modsyn_m448m16_error     },
  { NULL, SYSCALL_SYN_WAIT_TM,   (uint32)&modsyn_m448m16_wait_tm   }
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
