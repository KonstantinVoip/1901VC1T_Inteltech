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
                    _OS_NMISTACK_END = _OS_NMISTACK_BEGIN + 0x00000400;
                  }                                     > OS_NMISTACK

  .cinit        : { }                                   > OS_CODE
  .pinit        : { }                                   > OS_CODE
  .bss          : { }                                   > OS_CODE
  .data         : { }                                   > OS_CODE
  .const        : { }                                   > OS_CODE
  .text         : { }                                   > OS_CODE
  .far          : { }                                   > OS_CODE
  .cio          : { }                                   > OS_CODE
  .switch       : { }                                   > OS_CODE
//.template     : { }                                   > OS_CODE
//$build.attributes : { }                               > OS_CODE  

  .mpage0       : {
                    _OS_MPAGE0_BEGIN = 0x00950000;
                    _OS_MPAGE0_END   = 0x00990000;

                    _OS_MPAGE1_BEGIN = 0x009D8000;
                    _OS_MPAGE1_END   = 0x009F0000;

                    _OS_MPAGE2_BEGIN = 0x00000000;
                    _OS_MPAGE2_END   = 0x00000000;

                    _OS_MPAGE3_BEGIN = 0x00000000;
                    _OS_MPAGE3_END   = 0x00000000;
                  }                                     > MPAGE0
  .netcard     : load = NETCARD, type = NOLOAD
}
