/* -- DO NOT REMOVE ----------------------------------------------------------
// !: arch = tms320c6457
// !: sarc = all
// !: proj = soft-debug
// !: desc = 
// !: desc = 
// !: desc = внутреннее ОЗУ 2 М/байт =2048 К/байт.
// ------------------------------------------------------------------------ */
MEMORY
{
  OS_IVECT      : origin = 0x00900000, len = 0x00000200   //Internal RAM_COMM_CPU
  OS_LOADER     : origin = 0x00900200, len = 0x00000200   //Internal RAM_COMM_CPU
  OS_INIT_EP    : origin = 0x00900400, len = 0x00000200   //Internal RAM_COMM_CPU
  OS_INIT_CODE  : origin = 0x00900600, len = 0x00000980   //Internal RAM_COMM_CPU
  OS_INIT_SCALL : origin = 0x00900f80, len = 0x00000080   //Internal RAM_COMM_CPU
  OS_STACK      : origin = 0x00901000, len = 0x00000400   //Internal RAM_COMM_CPU
  OS_ISTACK     : origin = 0x00901400, len = 0x00000400   //Internal RAM_COMM_CPU
  OS_NMISTACK   : origin = 0x00901800, len = 0x00000400   //Internal RAM_COMM_CPU
  OS_CODE       : origin = 0x00901c00, len = 0x0004e400   //Internal RAM_COMM_CPU
  MPAGE0        : origin = 0x00950000, len = 0x00040000   //Internal RAM_COMM_CPU
  NETCARD       : origin = 0x00990000, len = 0x00048000   //Internal RAM_COMM_CPU
}
