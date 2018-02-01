/* -- DO NOT REMOVE ----------------------------------------------------------
// !: arch = tms320c6000
// !: sarc = all
// !: proj = core-release, loader-release
// !: desc =
// ------------------------------------------------------------------------ */

SECTIONS
{
  GROUP
  {
  .text         : align(64){}                                  
  .far          : align(64){}                                   
  .const        : align(64){}                                   
  .data         : align(64){}                                   
  .bss          : align(64){}                                  
  .cinit        : align(64){}                                   
  .pinit        : align(64){}                                  
  .cio          : align(64){}                                  
  .switch       : align(64){}                                   
  .template     : align(64){}                                   
  } > PO_MEMORY
} 

