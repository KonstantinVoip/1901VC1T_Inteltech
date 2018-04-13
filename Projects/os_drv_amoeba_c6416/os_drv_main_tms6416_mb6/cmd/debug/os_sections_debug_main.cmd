/* -- DO NOT REMOVE ----------------------------------------------------------
// !: arch = tms320c6416
// !: sarc = MAIN CPU SV-043 board
// !: proj = soft-debug
// !: desc = Отладочный варинат Секции для tms6416 используём всё емкость SDRAM 16 м/байт
// ------------------------------------------------------------------------ */

SECTIONS
{
  .os_ivect     : { }                                   > OS_IVECT
  .os_loader    : fill = 0x00000000 { }                 > OS_LOADER
  .os_init_ep   : { }                                   > OS_INIT_EP
  .os_init_code : { }                                   > OS_INIT_CODE
  .os_init_scall: { }                                   > OS_INIT_SCALL
  .os_stack     : {
                    _OS_STACK_BEGIN = .;
                  }                                     > OS_STACK
  .os_istack    : {
                    _OS_STACK_END = .;
                    _OS_ISTACK_BEGIN = .;
                  }                                     > OS_ISTACK
  .os_nmistack  : {
                    _OS_ISTACK_END = .;
                    _OS_NMISTACK_BEGIN = .;
                  }                                     > OS_NMISTACK
  .os_code      : {
                    _OS_NMISTACK_END = .;
                  }                                     > OS_CODE
  .mpage0       : {
                    _OS_MPAGE0_BEGIN = .;                
                    _OS_MPAGE0_END   = 0x00100000;     //Internal RAM CPU tms6416. 1 M/bait

                    _OS_MPAGE1_BEGIN = 0x80000000;     //16 M/bait External SDRAM memory
                    _OS_MPAGE1_END   = 0x81000000;

                  }                                     > MPAGE0

  .cinit        : { }                                   > OS_CODE
  .pinit        : { }                                   > OS_CODE
  .bss          : { }                                   > OS_CODE
  .data         : { }                                   > OS_CODE
  .const        : { }                                   > OS_CODE
  .text         : { }                                   > OS_CODE
  .far          : { }                                   > OS_CODE
  .cio          : { }                                   > OS_CODE
  .switch       : { }                                   > OS_CODE
//  .template     : { }                                 > OS_CODE   //не нужен в новой версии компилятора

}
