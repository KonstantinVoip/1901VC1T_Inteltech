#define SYSCALL_DIRECT
#include <os.h>

// -- Cache registers --------------------------------------------------------

#define REG_CCFG                (*(volatile uint32*)0x01840000) // CCFG Cache configuration register
#define REG_L2WBAR              (*(volatile uint32*)0x01844000) // L2WBAR L2 writeback base address register
#define REG_L2WWC               (*(volatile uint32*)0x01844004) // L2WWC L2 writeback word count register
#define REG_L2WIBAR             (*(volatile uint32*)0x01844010) // L2WIBAR L2 writeback-invalidate base address register
#define REG_L2WIWC              (*(volatile uint32*)0x01844014) // L2WIWC L2 writeback-invalidate word count register
#define REG_L1PIBAR             (*(volatile uint32*)0x01844020) // L1PIBAR L1P invalidate base address register
#define REG_L1PIWC              (*(volatile uint32*)0x01844024) // L1PIWC L1P invalidate word count register
#define REG_L1DWIBAR            (*(volatile uint32*)0x01844030) // L1DWIBAR L1D writeback-invalidate base address register
#define REG_L1DWIWC             (*(volatile uint32*)0x01844034) // L1DWIWC L1D writeback-invalidate word count register
#define REG_L2WB                (*(volatile uint32*)0x01845000) // L2WB L2 writeback all register
#define REG_L2WBINV             (*(volatile uint32*)0x01845004) // L2WBINV L2 writeback-invalidate all register

#define CCFG_IP                 0x00000200
#define CCFG_ID                 0x00000100

// ---------------------------------------------------------------------------
static void os_cache_writeback_invalidate_ll( uint32 address, uint32 length )
{
  length >>= 2;
  REG_L1DWIBAR = address;
  REG_L1DWIWC = length;
  while( REG_L1DWIWC );
  REG_L1PIBAR = address;
  REG_L1PIWC = length;
  while( REG_L1PIWC );
}
// ---------------------------------------------------------------------------
// !: fn: void os_cache_writeback_invalidate( uint32 address, uint32 length )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция осуществляет сброс программного кеша и кеша данных
// !: d: для всех адресов начиная с address и заканчивая
// !: d: address + length - 1.
// ---------------------------------------------------------------------------
void os_cache_writeback_invalidate( uint32 address, uint32 length )
{
  register uint32 is = int_disable();
  register uint32 l;

  while( length )
  {
    if( length >= 262100 ) l = 262100; else l = length;
    os_cache_writeback_invalidate_ll( address, l );
    length -= l;
    address += l;
  }

  int_enable( is );
}
// ---------------------------------------------------------------------------
