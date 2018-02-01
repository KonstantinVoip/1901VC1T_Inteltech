/* -- DO NOT REMOVE ----------------------------------------------------------
// !: arch = tms320c6000
// !: sarc = all
// !: proj = core-release, loader-release
// !: desc =
// ------------------------------------------------------------------------ */

SECTIONS
{
  .os_ivect     : { }                                   > OS_IVECT

  .os_loader    : { }                                   > OS_LOADER

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

  .os_data      : {
                    _OS_NMISTACK_END = .;
                    _OS_DATA_BEGIN = .;
                  }                                     > OS_DATA

  .os_code      : {
                    _OS_DATA_END = .;
                  }                                     > OS_CODE

  .mpage0       : {
                    _OS_MPAGE0_BEGIN = .;
                    _OS_MPAGE0_END   = 0x00100000;

                    _OS_MPAGE1_BEGIN = 0x00000000;
                    _OS_MPAGE1_END   = 0x00000000;
                    
                    _OS_MPAGE2_BEGIN = 0x00000000;
                    _OS_MPAGE2_END   = 0x00000000;
                    
                    _OS_MPAGE3_BEGIN = 0x00000000;
                    _OS_MPAGE3_END   = 0x00000000;
                  }                                     > MPAGE0

  .cinit        : { }                                   > CODE
  .pinit        : { }                                   > CODE
  .bss          : { }                                   > CODE
  .data         : { }                                   > CODE
  .const        : { }                                   > CODE
  .text         : { }                                   > CODE
  .far          : { }                                   > CODE
  .cio          : { }                                   > CODE
  .switch       : { }                                   > CODE
  .template     : { }                                   > CODE

}
