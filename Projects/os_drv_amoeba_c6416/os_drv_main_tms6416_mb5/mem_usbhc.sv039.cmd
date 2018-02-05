/**********************************************************\
*                  ISP 176x and NEC uPD720150 
*                    memory configuration
*                        EMIFB CE0
\**********************************************************/
MEMORY 
{
    USBHC_REGISTER   :  origin = 0x60000000, length = 0x400
    ISP176X_PAYLOAD  :  origin = 0x60000400, length = 0xFC00
}

SECTIONS 
{
    UNION: run = USBHC_REGISTER
    {
      .pd720150_reg : load = USBHC_REGISTER,  type = NOLOAD
      .isp176x_reg  : load = USBHC_REGISTER,  type = NOLOAD
    }
/*
    .pd720150_reg   : load = USBHC_REGISTER,  type = NOLOAD 
    {
        _reg_pd720150 = .;
    } 

    .isp176x_reg    : load = USBHC_REGISTER,  type = NOLOAD 
    {
        _reg_isp176x = .;
    }
*/
    .isp176x_mem    : load = ISP176X_PAYLOAD, type = NOLOAD 
    {
        _mem_isp176x = .;
    }
}
 