/* -- DO NOT REMOVE ----------------------------------------------------------
// !: arch = tms320c6416
// !: sarc = all
// !: proj = soft-debug
// !: desc = ���������� ����� ������ ��� tms6416 ��� ������ LOAD_PO
// !: desc = ���������� ���� ����� SDRAM flash ��� ����� ��-043 = 16 M/bait � ������ 0x80000000
// !: desc = ���������� ������ Internal RAM CPU = 1024 [�/����] c ������ 0x00000000
// ------------------------------------------------------------------------ */
SECTIONS
{
  .ext_ram:	{ _EXT_RAM_BEGIN = .; }	> EXT_RAM, SIZE(_EXT_RAM_SIZE)
}

MEMORY
{
  OS_IVECT      : origin = 0x00000000, len = 0x00000200  //Internal RAM_MAIN_CPU
  OS_LOADER     : origin = 0x00000200, len = 0x00000200  //Internal RAM_MAIN_CPU 
  OS_INIT_EP    : origin = 0x00000400, len = 0x00000200  //Internal RAM_MAIN_CPU
  OS_INIT_CODE  : origin = 0x00000600, len = 0x00000B80  //Internal RAM_MAIN_CPU
  OS_INIT_SCALL : origin = 0x00001180, len = 0x00000080  //Internal RAM_MAIN_CPU
  OS_STACK      : origin = 0x00001200, len = 0x00000800  //Internal RAM_MAIN_CPU
  OS_ISTACK     : origin = 0x00002000, len = 0x00001000  //Internal RAM_MAIN_CPU
  OS_NMISTACK   : origin = 0x00003000, len = 0x00001000  //Internal RAM_MAIN_CPU
  OS_CODE       : origin = 0x00004000, len = 0x0008c000  //Internal RAM_MAIN_CPU
  MPAGE0        : origin = 0x00090000, len = 0x00070000  //Internal RAM_MAIN_CPU

  EXT_RAM       : origin = 0x80000000, len = 0x01000000   //16 M/bait SDRAM flash
}
