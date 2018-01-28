MEMORY
{
  OS_IVECT      : origin = 0x00000000, len = 0x00000200
  OS_LOADER     : origin = 0x00000200, len = 0x00000200
  OS_INIT_EP    : origin = 0x00000400, len = 0x00000200
  OS_INIT_CODE  : origin = 0x00000600, len = 0x00000980
  OS_INIT_SCALL : origin = 0x00000f80, len = 0x00000080
  OS_STACK      : origin = 0x00001000, len = 0x00000400
  OS_ISTACK     : origin = 0x00001400, len = 0x00000400
  OS_NMISTACK   : origin = 0x00001800, len = 0x00000100
  OS_CODE       : origin = 0x00001900, len = 0x0002b000
  MPAGE0        : origin = 0x0002c900, len = 0x00003700
}
