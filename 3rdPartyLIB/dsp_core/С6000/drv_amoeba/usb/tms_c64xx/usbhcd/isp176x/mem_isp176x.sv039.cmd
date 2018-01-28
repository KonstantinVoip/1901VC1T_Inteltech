/**********************************************************\
*          ISP 176x (16-bit bus) memory configuration
*                        EMIFB CE0
\**********************************************************/
MEMORY 
{
    /* 1 KByte */
    ISP176X_REGISTER :  origin = 0x60000000, length = 0x400
    /* 63 KByte */
    ISP176X_PAYLOAD  :  origin = 0x60000400, length = 0xFC00
}

SECTIONS 
{
    .isp176x_reg     : load = ISP176X_REGISTER, type = NOLOAD 
    {
        _reg_isp176x = .;
    }

    .isp176x_mem     : load = ISP176X_PAYLOAD,  type = NOLOAD 
    {
        _mem_isp176x = .;
    }
}
 