/**********************************************************\
*          ISP 176x (32-bit bus) memory configuration
*                        EMIFA CE0
\**********************************************************/
MEMORY 
{
        /* 1 KByte */
        ISP176X_REGISTER :  origin = 0x80000000, length = 0x800
        /* 63 KByte */
        ISP176X_PAYLOAD  :  origin = 0x80000800, length = 0x1F800
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
 