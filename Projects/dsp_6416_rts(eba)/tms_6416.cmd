/****************************************************************************/
/*  lnk.cmd                                                                 */
/*  Copyright (c) 1997-1999  Texas Instruments Incorporated                 */
/****************************************************************************/ 
MEMORY
{
   VEC:     o=0x00000000 l=0x00000800
   L2:      o=0x00000800 l=0x00080000
   SDRAM:   o=0x90000000 l=0x00800000
}
   
SECTIONS
{ 
  .intvecs    > VEC
  .off_chip   > L2
  .bss        > L2
  .far        > L2
  .chip_image > L2
  .data       > L2
  .text       > L2
  .cio        > L2
  .cinit      > L2
  .boot       > L2
  .const      > L2
  .stack      > L2
  .sysmem     > L2
}
