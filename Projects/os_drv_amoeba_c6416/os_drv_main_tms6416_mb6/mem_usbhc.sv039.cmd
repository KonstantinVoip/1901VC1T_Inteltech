/**********************************************************\
*                  ISP 176x and NEC uPD720150 
*                    memory configuration
*                  EMIF_B CE0 Это Файл для ЦП (MAIN) процессоров шина 16 бит.
*                  СВ-039 и СВ-043
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

    .isp176x_mem    : load = ISP176X_PAYLOAD, type = NOLOAD 
    {
        _mem_isp176x = .;
    }
}
 