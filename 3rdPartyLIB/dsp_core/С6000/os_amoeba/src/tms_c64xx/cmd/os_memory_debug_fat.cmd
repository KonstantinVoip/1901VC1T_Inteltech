/* -- DO NOT REMOVE ----------------------------------------------------------
// !: arch = tms320c6000
// !: sarc = all
// !: proj = soft-debug
// !: desc = 
// ------------------------------------------------------------------------ */
SECTIONS
{
  .ext_ram:	{ _EXT_RAM_BEGIN = .; }	> EXT_RAM, SIZE(_EXT_RAM_SIZE)
}

MEMORY
{
  OS_IVECT      : origin = 0x00000000, len = 0x00000200
  OS_LOADER     : origin = 0x00000200, len = 0x00000200
  OS_INIT_EP    : origin = 0x00000400, len = 0x00000200
  OS_INIT_CODE  : origin = 0x00000600, len = 0x00000B80
  OS_INIT_SCALL : origin = 0x00001180, len = 0x00000080
  OS_STACK      : origin = 0x00001200, len = 0x00000800
  OS_ISTACK     : origin = 0x00002000, len = 0x00000800
  OS_NMISTACK   : origin = 0x00002800, len = 0x00000800
  OS_CODE       : origin = 0x00003000, len = 0x0009d000
  MPAGE0        : origin = 0x000a0000, len = 0x00060000

  EXT_RAM       : origin = 0x80080000, len = 0x00620000
}
