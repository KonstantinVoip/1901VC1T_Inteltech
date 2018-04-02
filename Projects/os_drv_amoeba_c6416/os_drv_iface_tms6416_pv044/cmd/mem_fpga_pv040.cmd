/**********************************************************\
*                 FPGA memory configuration
*                         EMIFB CE0
\**********************************************************/
MEMORY 
{
    /* 64 MByte addressable space */
    FPGA  :   origin =    0x60000000, len = 0x4000000
}

SECTIONS 
{
   .mem_fpga  :  load = FPGA, type = NOLOAD     
}

