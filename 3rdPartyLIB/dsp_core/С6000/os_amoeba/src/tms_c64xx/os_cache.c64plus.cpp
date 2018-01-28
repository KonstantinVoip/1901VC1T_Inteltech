#define SYSCALL_DIRECT
#include <os.h>

// -- Cache registers --------------------------------------------------------

#define REG_L2CFG               (*(volatile uint32*)0x01840000) // L2 Cache Configuration Register
#define REG_L1PCFG              (*(volatile uint32*)0x01840020) // L1P Configuration Register
#define REG_L1PCC               (*(volatile uint32*)0x01840024) // L1P Cache Control Register
#define REG_L1DCFG              (*(volatile uint32*)0x01840040) // L1D Configuration Register
#define REG_L1DCC               (*(volatile uint32*)0x01840044) // L1D Cache Control Register
#define REG_L2WBAR              (*(volatile uint32*)0x01844000) // L2 Writeback Base Address Register - for Block Writebacks
#define REG_L2WWC               (*(volatile uint32*)0x01844004) // L2 Writeback Word Count Register
#define REG_L2WIBAR             (*(volatile uint32*)0x01844010) // L2 Writeback and Invalidate Base Address Register - for Block Writebacks
#define REG_L2WIWC              (*(volatile uint32*)0x01844014) // L2 Writeback and Invalidate word count register
#define REG_L2IBAR              (*(volatile uint32*)0x01844018) // L2 Invalidate Base Address Register
#define REG_L2IWC               (*(volatile uint32*)0x0184401C) // L2 Invalidate Word Count Register
#define REG_L1PIBAR             (*(volatile uint32*)0x01844020) // L1P Invalidate Base Address Register
#define REG_L1PIWC              (*(volatile uint32*)0x01844024) // L1P Invalidate Word Count Register
#define REG_L1DWIBAR            (*(volatile uint32*)0x01844030) // L1D Writeback and Invalidate Base Address Register
#define REG_L1DWIWC             (*(volatile uint32*)0x01844034) // L1D Writeback and Invalidate Word Count Register
#define REG_L1DWBAR             (*(volatile uint32*)0x01844040) // L1D Writeback Base Address Register - for Block Writebacks
#define REG_L1DWWC              (*(volatile uint32*)0x01844044) // L1D Writeback Word Count Register
#define REG_L1DIBAR             (*(volatile uint32*)0x01844048) // L1D Invalidate Base Address Register
#define REG_L1DIWC              (*(volatile uint32*)0x0184404C) // L1D Invalidate Word Count Register
#define REG_L2WB                (*(volatile uint32*)0x01845000) // L2 Global Writeback Register
#define REG_L2WBINV             (*(volatile uint32*)0x01845004) // L2 Global Writeback and Invalidate Register
#define REG_L2INV               (*(volatile uint32*)0x01845008) // L2 Global Invalidate Register
#define REG_L1PINV              (*(volatile uint32*)0x01845028) // L1P Global Invalidate Register
#define REG_L1DWB               (*(volatile uint32*)0x01845040) // L1D Global Writeback Register
#define REG_L1DWBINV            (*(volatile uint32*)0x01845044) // L1D Global Writeback and Invalidate Register
#define REG_L1DINV              (*(volatile uint32*)0x01845048) // L1D Global Invalidate Register

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
