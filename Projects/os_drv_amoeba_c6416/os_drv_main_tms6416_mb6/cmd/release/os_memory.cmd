/* -- DO NOT REMOVE ----------------------------------------------------------
// !: arch = tms320c6000
// !: sarc = all
// !: proj = soft-debug
// !: desc = Боевая Карта Памяти для tms6416 есть секция LOAD_PO
// ------------------------------------------------------------------------ */

MEMORY
{
  OS_IVECT      : origin = 0x00000000, len = 0x00000200
  OS_LOADER     : origin = 0x00000200, len = 0x00000200
  OS_INIT_EP    : origin = 0x00000400, len = 0x00000200
  OS_INIT_CODE  : origin = 0x00000600, len = 0x00000980
  OS_INIT_SCALL : origin = 0x00000f80, len = 0x00000080
  OS_STACK      : origin = 0x00001000, len = 0x00001000
  OS_ISTACK     : origin = 0x00002000, len = 0x00001000
  OS_NMISTACK   : origin = 0x00003000, len = 0x00001000
  OS_CODE       : origin = 0x00004000, len = 0x00054DB0
  OS_BUILD_ATTR : origin = 0x00058DB0, len = 0x00000250
  LOAD_PO       : origin = 0x00059000, len = 0x00057000
  MPAGE0        : origin = 0x000b0000, len = 0x00050000
}
