/* -- DO NOT REMOVE ----------------------------------------------------------
// !: arch = tms320c6000
// !: sarc = all
// !: proj = core-release, loader-release
// !: desc =
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
  OS_CODE       : origin = 0x00004000, len = 0x00018000
  CODE          : origin = 0x00020000, len = 0x00060000
  MPAGE0        : origin = 0x00080000, len = 0x00080000
}
