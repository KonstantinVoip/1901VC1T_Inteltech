/**********************************************************\
*            NEC uPD720150 memory configuration
*                        EMIFB CE0
\**********************************************************/
MEMORY 
{
    PD720150_REGISTER :  origin = 0x60000000, length = 0x1b2
}

SECTIONS 
{
    .pd720150_reg     : load = PD720150_REGISTER, type = NOLOAD 
    {
        _reg_pd720150 = .;
    }
}
 