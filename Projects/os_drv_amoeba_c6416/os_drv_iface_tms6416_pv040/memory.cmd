MEMORY
{
  OS_IVECT      : origin = 0x00000000, len = 0x00000200
  OS_LOADER     : origin = 0x00000200, len = 0x00000200
  OS_INIT_EP    : origin = 0x00000400, len = 0x00000200
  OS_INIT_CODE  : origin = 0x00000600, len = 0x00000B80
  OS_INIT_SCALL : origin = 0x00001180, len = 0x00000080
  OS_STACK      : origin = 0x00001200, len = 0x00000800
  OS_ISTACK     : origin = 0x00002000, len = 0x00001000
  OS_NMISTACK   : origin = 0x00003000, len = 0x00001000
  OS_CODE       : origin = 0x00004000, len = 0x0008c000
  MPAGE0        : origin = 0x00090000, len = 0x00070000

  EXT_RAM       : origin = 0x80080000, len = 0x00620000
}

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
                    _OS_MPAGE0_END   = 0x00100000;

                    _OS_MPAGE1_BEGIN = 0x90000000;
                    _OS_MPAGE1_END   = 0x90800000;
                    
                    _OS_MPAGE2_BEGIN = 0x00000000;
                    _OS_MPAGE2_END   = 0x00000000;
                    
                    _OS_MPAGE3_BEGIN = 0x00000000;
                    _OS_MPAGE3_END   = 0x00000000;
                  }                                     > MPAGE0

  .cinit        : { }                                   > OS_CODE
  .pinit        : { }                                   > OS_CODE
  .bss          : fill = 0x00000000 { }                 > OS_CODE
  .data         : { }                                   > OS_CODE
  .const        : { }                                   > OS_CODE
  .text         : { }                                   > OS_CODE
  .far          : fill = 0x00000000 { }                 > OS_CODE
  .cio          : { }                                   > OS_CODE
  .switch       : { }                                   > OS_CODE
//  .template     : { }                                   > OS_CODE

}
