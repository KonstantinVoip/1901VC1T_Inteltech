/**********************************************************************************************************************
*                                        (c) COPYRIGHT by ZAO RCZI FORT.                                             *
*                                               All rights reserved.                                                  *
***********************************************************************************************************************
#
# NAME
# > main_main.cpp  Функция Старта ЗООСРВ и Запуска ТПО для ЦП Цетральных Процессоров 0 и 1 платы СВ-040 !!! 
#
# DESCRIPTION
# 
#   
# REFERENCEs
# > 
#
# NOTEs
##################################################################################################################### > 
*/
#define SYSCALL_DIRECT
#include <os.h>
#include <rts.h>
#include <__fs.h>
#include <drv_fwmem.h>
#include <drv_gpio.h>
#include <drv_usbhc.h>
#include <drv_usb.h>
#include <drv_usbms.h>
#include <drv_mcbsp.h>
#include <drv_nvram.h>
#include <drv_ipmp.dsp-16.h>
#include <drv_ipmp.mcbsp.h>
#include <drv_vfat.h>
#include <drv_dbgout.h>

/**
 * Executes a user application main process.
 *
 * @param arg application arguments.
 */
extern int os_main(void* arg);

/**
 * Global USB struct definitions
 */
DEFINE_USBDEV(USB1,0,0);
DEFINE_USBDEV(USB2,1,0);
DEFINE_USBDEV(USB3,2,0);

/**
 * Assigns a volume letter for a USB device.
 *
 * @param usbhc a type of plugged HC.
 */
static void dev_assign_letter(uint32 usbhc_plug)
{
    switch(usbhc_plug)
    {
        case USBHC_NEC_PLUG: dev.assignLetter(USB1,0,1,4); break;
        case USBHC_ISP_PLUG: dev.assignLetter(USB3,0,1,4); break;    
    }  
}

/**
 * Waits for flash "msd0".
 */
static bool wait_msd0_flash(uint32 wait_time_m = 0)
{
    s_inode *first_list, *list;
    uint32 msd_found;
    uint64 limit_time = (wait_time_m != 0) ? time_m() + wait_time_m : 0;
    uint32 d = drv_mkd("/dev");
    if( d == RES_VOID ) return false;
    
    msd_found = 0;
    while(msd_found == 0)
    {
        drv_ioctl(d, IOC_INODE_LIST, &first_list);
        list = first_list;
        while(list != NULL)
        {
            if(memcmp(list->name, "sd", 2)==0)
            {
                msd_found = 1;
                break;
            }
            list = list->next;
        }
        drv_list_destroy( first_list );
        if( msd_found ) break;
        if(limit_time != 0)
        {
            if(time_m()>=limit_time)
            {
                drv_rmd(d);
                return false;
            }
        }
        prc_yield();
    }
    drv_rmd(d);
    return true;
}

/**
 * Prints a string to debug output stream of IDE.
 *
 * @param str   an output string.
 * @param close out stream close flag.
 */
static void print(const char* str, bool complete=false)
{
    static FILE* file = NULL;
    if(file == NULL) file = fopen("/dev/dbgout", "w");
    if(file != NULL) fprintf(file, str);
    if(file != NULL && complete == true) 
    {
        fclose(file);
        file = NULL;
    }
}

/**
 * Stops an initialization executing.
 *
 * @param error failed error.
 * @return given error value.
 */
static int32 os_panic(int32 error=OSE_FAIL)
{
    while(true) asm(" idle");
}

/**
 * Sets OS configuration.
 */
void os_config()
{
    OS_TOUCH_CODE();
    syscall_init(__syscall_tab, sizeof(void*) * SYSCALL__COUNT__);
    sys_frequency = 1000000000ull;
    sys_quant = core_init_cfg.sys_quant;
    emif_init();
}


// ---------------------------------------------------------------------------
// Заглушка для тестирования ОС и драйверов без ТПО нужно тогда удалить библиотеку ТПО tpo_15_main.lib
// Если нужно Тестировать с ТПО то тогда нужно закоментировать этот вызов os_main чтобы os_main
// вызывался из ТПО и стартовал для ЦП(main)Процессоров
//#if 0
int os_main(void* arg)
{

  while(true)
  {
    asm(" nop");
  }
}
//#endif




/**
 * Initializes OS environment. 
 * 
 * @param arg process arguments.
 * @return OS error. 
 */
int os_process(void* arg)
{
    int32 error = OSE_OK;  
    uint32 d = RES_VOID;
    
    // Initialize the OS root file system
    d = drv_mkd("/");
    if(d == RES_VOID) return os_panic();
    error |= drv_create(d, "dev", INOT_FOLDER);
    error |= drv_create(d, "mnt", INOT_FOLDER);
    error |= drv_select(d, "dev" );
    error |= drv_create(d, "ipmp",INOT_FOLDER);
    error |= drv_create(d, "net",INOT_FOLDER);
    drv_rmd(d);
    if(error != OSE_OK) return os_panic();
    drv_dbgout_plug();
    
    
    #ifdef MAIN_ONLY
    print("MAIN_ONLY was defined for project build.\n");
    #endif
    print("OS Root File System has been successfully initialized.\n");
    
    // ----------------------------------------------------------
    print("Initializing GPIO Driver: ");
    s_gpio_start_value gpio;
    gpio.reg_gpen  = 0x46f0;
    gpio.reg_gpdir = 0x4600;
    gpio.reg_gpval = 0x0000;
    error = drv_gpio_plug(&gpio);
    if(error == OSE_OK)
    {
        // Reset PLIS
        s_gpio_load_plis arg;
        d = drv_mkd("/dev/gpio");
        memset(&arg, 0, sizeof(s_gpio_load_plis));
        error = drv_ioctl(d, GPIO_RESET_PLIS, &arg);
        if(error == OSE_OK) print("OK\n"); else print("ERROR\n");    
        drv_rmd(d);
    }
    else  
    {
        print("ERROR\n");
        REG_OSTS0 |= OSTS0_GPIO_FAIL;
    }
    
    
    // ----------------------------------------------------------  
    print("Initializing FWMEM Driver: ");
    error = drv_fwmem_plug("/fwmem", 0x64000000, &fwmem_s29al032dxxxxx04_gpio );
    if(error == OSE_OK) print("OK\n"); else print("ERROR\n");
    if(error != OSE_OK) REG_OSTS0 |= OSTS0_FWMEM_FAIL;
    
    // ----------------------------------------------------------  
    print("Initializing Syslog: ");
    error = syslog_init();
    if(error == OSE_OK) print("OK\n"); else print("ERROR\n");  
    
    // ----------------------------------------------------------  
    print("Initializing MCBSP Driver: ");  
    mcbsp_context mcbsp_ctx;
    mcbsp_ctx.out_port      = MCBSP_PORT0;
    mcbsp_ctx.in_port1      = MCBSP_PORT1;
    mcbsp_ctx.in_port2      = PORT_UNUSED;
    mcbsp_ctx.mcbsp_cfg_in  = main_in_mcbspCfg;   
    mcbsp_ctx.mcbsp_cfg_out = main_out_mcbspCfg;
    mcbsp_ctx.edma_cfg_in   = main_in_edmaCfg;    
    mcbsp_ctx.edma_cfg_out  = main_out_edmaCfg;
    error = drv_mcbsp_plug(&mcbsp_ctx);
    if(error == OSE_OK) print("OK\n"); else print("ERROR\n");
    if(error != OSE_OK) REG_OSTS0 |= OSTS0_MCBSP_FAIL;
    
    // ----------------------------------------------------------  
    print("Initializing USB Host Controller Driver: ");  
    uint32 usbhc_plug;
    s_usbhc_plug usbhc;
    usbhc.isp.gpio_number = 8;
    usbhc.nec.gpio_number = 7;    
    error = drv_usbhc_plug(&usbhc, &usbhc_plug);    
    if(error == OSE_OK)
    {
        print("OK\n");
        print("Initializing USB Bus Driver: ");      
        error = drv_usb_plug();
        if(error == OSE_OK) 
        {
            print("OK\n");    
            s_usb_driver_context msd;
            msd.device_class = USB_DEVICE_CLASS_STORAGE;
            msd.open_func    = &usbms_open;
            msd.close_func   = &usbms_close;
            msd.read_func    = &usbms_read;
            msd.write_func   = &usbms_write;
            msd.ioctl_func   = &usbms_ioctl;                    
            uint32 d = drv_mkd("/dev/usb/");
            error = drv_ioctl(d, USB_ADD_DEVICE_CLASS, &msd);
            drv_rmd(d);
        }
        else
        {
            print("ERROR\n");    
            REG_OSTS0 |= OSTS0_USB_FAIL;
        }
        dev_assign_letter(usbhc_plug);
    }  
    else
    {
        print("ERROR\n");
        REG_OSTS0 |= OSTS0_USBHC_FAIL;
    }
    
    // ----------------------------------------------------------  
    print("Waiting for USB drive: ");  
    if( wait_msd0_flash() == true )
    {
        print("OK\n");
    }
    else
    {
        print("ERROR\n");
        REG_OSTS0 |= OSTS0_MSD0_FAIL;  
    }

    // ----------------------------------------------------------  
    print("Initializing FAT Driver: ");
    error = drv_vfat_trigger_plug();
    if(error == OSE_OK) print("OK\n"); else print("ERROR\n");
    

    // ----------------------------------------------------------
    print("Initializing NVRAM Driver: ");
    error = drv_nvram_plug("/dev/nvram");
    if(error == OSE_OK) print("OK\n"); else print("ERROR\n");  
    if(error != OSE_OK) REG_OSTS0 |= (error == OSE_DATA_TEST_ERROR) ? OSTS0_NVRAM_FAIL1 : OSTS0_NVRAM_FAIL2;
    
    // ----------------------------------------------------------
    print("Initializing TCP/IP Stack: ");  
    error = socket_init(8);
    if(error == OSE_OK) print("OK\n"); else print("ERROR\n");    
    if(error != OSE_OK) REG_OSTS1 |= OSTS1_TCPIP_FAIL;  
    
    // ----------------------------------------------------------  



   //МежПроцессорное Взаимодействие и Загрузка Прошивки FPGA sv6.bin

//#if 0
   
    // ----------------------------------------------------------  
    print("Initializing SPARCA Driver: ");    
    syn_init(24, 30000, NULL);    
    print("OK\n");
    // ----------------------------------------------------------  
    print("Initializing IPMP IFACE Driver: ");
    error = drv_ipmp_mcbsp_plug("/dev/ipmp/ipmp0");
    if(error == OSE_OK) print("OK\n"); else print("ERROR\n");
    if(error != OSE_OK) REG_OSTS1 |= OSTS1_EXCH_IFACE_FAIL;
    
    // ----------------------------------------------------------  
    print("Initializing IPMP COMM0 Driver and loading FPGA: ");
    error = drv_ipmp_dsp16_plug("/dev/ipmp/ipmp1", 0);
    if(error == OSE_OK) print("OK\n"); else print("ERROR\n");
    if(error != OSE_OK) REG_OSTS1 |= OSTS1_EXCH_COMM0_FAIL;  
    
    // ----------------------------------------------------------  
    print("Initializing IPMP COMM1 Driver: ");
    error = drv_ipmp_dsp16_plug("/dev/ipmp/ipmp2", 1);
    if(error == OSE_OK) print("OK\n"); else print("ERROR\n");
    if(error != OSE_OK) REG_OSTS1 |= OSTS1_EXCH_COMM1_FAIL;  
    
    // ----------------------------------------------------------  
    print("Initializing IPMP COMM3 Driver: ");
    error = drv_ipmp_dsp16_plug("/dev/ipmp/ipmp3", 2);
    if(error == OSE_OK) print("OK\n"); else print("ERROR\n");
    if(error != OSE_OK) REG_OSTS1 |= OSTS1_EXCH_COMM1_FAIL;  
    
 
    print("Running Inter-Process Exchange: ");
    error  = sys_setname("main");
    error |= msg_start(2, 8);
    if(error == OSE_OK) print("OK\n"); else print("ERROR\n");    
    if(error != OSE_OK) REG_OSTS1 |= OSTS1_EXCH_FAIL;  
    
    // ----------------------------------------------------------    
    print("Opening OS Message Connection: ");
    error = msg_open("os");    
    if(error == OSE_OK) print("OK\n"); else print("ERROR\n");      
    
    // ----------------------------------------------------------  
    print("Discovering OS Message channel to MAIN: ");    
    d = msg_discover("main", "os", SEM_INFINITY);
    if(d != RES_VOID) print("OK\n"); else print("ERROR\n");    
    if(d == RES_VOID) REG_OSTS1 |= OSTS1_EXCH_MAIN_FAIL;  
    
    // ----------------------------------------------------------  
    print("Discovering OS Message channel to IFACE: ");
    d = msg_discover("iface", "os", SEM_INFINITY);
    if(d != RES_VOID) print("OK\n"); else print("ERROR\n");    
    if(d == RES_VOID) REG_OSTS1 |= OSTS1_EXCH_IFACE_FAIL;
      
    // ----------------------------------------------------------  
    print("Discover OS Message channel to COMM0: ");
    d = msg_discover("comm0", "os", SEM_INFINITY);
    if(d != RES_VOID) print("OK\n"); else print("ERROR\n");    
    if(d == RES_VOID) REG_OSTS1 |= OSTS1_EXCH_COMM0_FAIL;  
    
    // ----------------------------------------------------------  
    print("Discover OS Message channel to COMM1: ");
    d = msg_discover("comm1", "os", SEM_INFINITY);
    if(d != RES_VOID) print("OK\n"); else print("ERROR\n");    
    if(d == RES_VOID) REG_OSTS1 |= OSTS1_EXCH_COMM1_FAIL;  

    // ----------------------------------------------------------  
    print("Discover OS Message channel to COMM2: ");
    d = msg_discover("comm2", "os", SEM_INFINITY);
    if(d != RES_VOID) print("OK\n"); else print("ERROR\n");    
    if(d == RES_VOID) REG_OSTS1 |= OSTS1_EXCH_COMM2_FAIL;    
    
    // ----------------------------------------------------------  
    print("Setting system time: ");
    s_message* tm_msg;
    error = msg_recv(&tm_msg, SEM_INFINITY);
    if(error == OSE_OK) 
    {
        print("OK\n");   
        time_set( (*(uint32*)tm_msg->data) );  
        msg_free( tm_msg );
    }
    else 
    {
        print("ERROR\n");    
    }

//#endif   //Завершение Обмена
    
    // ----------------------------------------------------------  
    print("Starting SIOS: ");
    s_prc_attr pattr;
    memset(&pattr, 0, sizeof(s_prc_attr));
    pattr.stack = 0x2000;
    if(prc_create(&os_main, NULL, 0, &pattr) > 0) print("OK\n"); else print("ERROR\n");    
    
    print("Operating System has been successfully loaded.\n", true);
    prc_system();
    return 0;
}