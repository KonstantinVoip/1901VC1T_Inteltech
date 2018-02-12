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



/*****************************************************************************
Syntax:  static void dev_assign_letter(uint32 usbhc_plug) 	    
Remarks: Assigns a volume letter for a USB device.@param usbhc a type of plugged HC.			    
*******************************************************************************/
static void dev_assign_letter(uint32 usbhc_plug)
{
    switch(usbhc_plug)
    {
        case USBHC_NEC_PLUG: dev.assignLetter(USB1,0,1,4); break;
        case USBHC_ISP_PLUG: dev.assignLetter(USB3,0,1,4); break;    
    }  
}


/*****************************************************************************
Syntax:  static void dev_assign_letter(uint32 usbhc_plug) 	    
Remarks: Waits for flash "msd0".			    
*******************************************************************************/
static bool wait_msd0_flash()
{
    s_inode *first_list, *list;
    uint32 msd_found;
    
    uint32 d = drv_mkd("/dev");
    if( d == RES_VOID )
    {
     return OSE_FAIL;
    }

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
        
        prc_yield();
    }
    drv_rmd(d);

    return OSE_OK;
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
    syscall_init(__syscall_tab, sizeof(void*) * SYSCALL__COUNT__);
    OS_TOUCH_CODE();
    
    sys_setname( "main" );                  //Имя в Центрального Процессора
  
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
    s_gpio_start_value gpio;
    FILE* dbg_out;

      
   


    // Initialize the OS root file system
    d = drv_mkd("/");
    if( d == RES_VOID )
    {
        //fprintf(dbg_out,"?d_error_stop =%d\n?",d);
        while(1);
	 	{
	 		 asm( " nop" );
	 	}

	}





    drv_create(d, "dev", INOT_FOLDER);
    drv_create(d, "mnt", INOT_FOLDER);
    drv_select(d, "dev" );
    drv_create(d, "ipmp",INOT_FOLDER);
    drv_create(d, "net",INOT_FOLDER);
 
    drv_rmd(d);
   
   //На Центральном Процессоре Испольщуеться 2 шины MCBSP 0 и 1 для обмена с IFACE платой ПВ-044 
    mcbsp_context mcbsp_ctx;
    mcbsp_ctx.out_port      = MCBSP_PORT0;
    mcbsp_ctx.in_port1      = MCBSP_PORT1;
    mcbsp_ctx.in_port2      = PORT_UNUSED;
    mcbsp_ctx.mcbsp_cfg_in  = main_in_mcbspCfg;   
    mcbsp_ctx.mcbsp_cfg_out = main_out_mcbspCfg;
    mcbsp_ctx.edma_cfg_in   = main_in_edmaCfg;    
    mcbsp_ctx.edma_cfg_out  = main_out_edmaCfg;
    
    

	error = drv_dbgout_plug();
    dbg_out = fopen( "/dev/dbgout", "w" );

    
   
    gpio.reg_gpen  = 0x46f0;
    gpio.reg_gpdir = 0x4600;
    gpio.reg_gpval = 0x0000;
    fprintf(dbg_out,"main(ЦП)_sv43:01-Init_GPIO\n");
    error = drv_gpio_plug(&gpio);
    if(error) REG_OSTS0 |= OSTS0_GPIO_FAIL;
    else
	{
        // Reset PLIS видимо сбрасваем ПЛИС по сигналу GPIO
        s_gpio_load_plis lplis;
        d = drv_mkd( "/dev/gpio" );
        memset( &lplis, 0, sizeof(lplis) );   
        lplis.gpio_prog = 15;
        lplis.gpio_init = 12;
        lplis.gpio_clk  = 14;
        lplis.gpio_dout = 13;
        lplis.gpio_done = 11;
        lplis.gpio_switch = 2;
        fprintf(dbg_out,"main(ЦП)_sv43:02-GPIO_ResetFPGA\n");
        error=drv_ioctl( d, GPIO_RESET_PLIS, &lplis );
        
        if(error)
   	    {
  			fprintf(dbg_out,"?GPIO_ResetFPGA:error =%d\n?",error);
     		while(1);
	 		{
	 		 asm( " nop" );
	 		}
		}
      
	   drv_rmd( d ); 

	} //end else
    

    fprintf(dbg_out,"main(ЦП)_sv43:02-Init_внутренней флэш\n");
    error = drv_fwmem_plug("/fwmem", 0x64000000, &fwmem_s29al032dxxxxx04_gpio );
    if(error) REG_OSTS0 |= OSTS0_FWMEM_FAIL;  
 

    fprintf(dbg_out,"main(ЦП)_sv43:03-Init_MCBSP\n");
    error = drv_mcbsp_plug(&mcbsp_ctx);
    if(error) REG_OSTS0 |= OSTS0_MCBSP_FAIL;


    	//Для Боевого(Release) Проекта только Старт SYSLOG!!! 
    fprintf(dbg_out,"main(ЦП)_sv43:05-Init_журнала syslog\n");
    syslog_init();
    syslog_level(LOG_DEBUG);


    fprintf(dbg_out,"main(ЦП)_sv43:06-Init_ЭОЗУ(NVRAM)\n");
    if( ( error = drv_nvram_plug("/dev/nvram") ) != OSE_OK )
    {
      if(error == OSE_DATA_TEST_ERROR)
        REG_OSTS0 |= OSTS0_NVRAM_FAIL1;
      else
        REG_OSTS0 |= OSTS0_NVRAM_FAIL2;
    }

    //Инициализация USB контроллера
    // ----------------------------------------------------------  
    fprintf(dbg_out,"main(ЦП)_sv43:07 - Init_USB Controller\n");
    uint32 usbhc_plug;
    s_usbhc_plug usbhc;
    usbhc.isp.gpio_number = 8;
    usbhc.nec.gpio_number = 7;    
    error = drv_usbhc_plug(&usbhc, &usbhc_plug);    
    
    if(error) REG_OSTS0 |= OSTS0_USBHC_FAIL;
    else
    {
        error = drv_usb_plug();
        if(error) REG_OSTS0 |= OSTS0_USB_FAIL;
        else
        {
          s_usb_driver_context    msd;
          msd.device_class = USB_DEVICE_CLASS_STORAGE;
          msd.open_func    = &usbms_open;
          msd.close_func   = &usbms_close;
          msd.read_func    = &usbms_read;
          msd.write_func   = &usbms_write;
          msd.ioctl_func   = &usbms_ioctl;                    
          uint32 d = drv_mkd("/dev/usb/");
          drv_ioctl(d, USB_ADD_DEVICE_CLASS, &msd);
          drv_rmd(d);
        }
    }


	 fprintf(dbg_out,"main(ЦП)_sv43:08-Init_msd0_flash\n");
     error=wait_msd0_flash();
     if(error)
     {
	  REG_OSTS0 |= OSTS0_MSD0_FAIL;
	  fprintf(dbg_out,"?Error wait_msd0_flash\n?",error);
       while(1);
	 	{
	 	asm( " nop" );
	 	}
	 }

    dev_assign_letter(usbhc_plug); //ничего не возвращает функция нам.


    fprintf(dbg_out,"main(ЦП)_sv43:09-Init VFAT_DRV\n");
    error=drv_vfat_trigger_plug();
	if(error)
	{
       fprintf(dbg_out,"?Error VFAT_DRV\n?",error);
	}

     
    //Инициализация Спарки и МежПроцессорного Обмена
        
    //Модуль Инициализации Спареных Процессоров(Спарки) ЦП Центарльных процессоров
	//реализовано через syscall ОС Переопределно //функция возвращает значение назад.
    //modsyn_m448m16_init переопределно в os_syn Спарка просто вистент по таймату
	//Функция описывает counter и задержку в миллисекундах для синхронизации Спарки.
	//По Истечении времении Спарки подвиснет выдаст OS_FAIL 
    fprintf(dbg_out,"main(ЦП)_sv43:10-Init_SPARKA\n");
    error=syn_init( 20, 60*60000, NULL ); 


    
    //Инициализация Межплатного Обмена с Интерфейсной Платой  ПВ-044 
    //IPMP0 через MCBSP0 ->iface  , MCBSP1 <--iface
    fprintf(dbg_out,"main(ЦП)_sv43:11-Init_IPMP0_MCBSP <-> IFACE\n");
    error = drv_ipmp_mcbsp_plug( "/dev/ipmp/ipmp0" );
    if(error) REG_OSTS1 |= OSTS1_EXCH_IFACE_FAIL;


    //Три Коммуникационных Процессора TMS6457
 

    //IPMP1 через ДОЗУ  с COMM0 Здесь Происходит Загрузка прошивки в ПЛИС sv6.bin
    fprintf(dbg_out,"main(ЦП)_sv43:12-IPMP1<-->COMM0+LOAD_FPGA_\n");
    error = drv_ipmp_dsp16_plug( "/dev/ipmp/ipmp1", 0 );
    if(error)
    {
     REG_OSTS1 |= OSTS1_EXCH_COMM0_FAIL;
     fprintf(dbg_out,"?IPMP1<-->COMM0:error=%d_stop\n?",error);
     while(1);
	 {
	 	asm( " nop" );
	 }
	}
    
    //IPMP2 через ДОЗУ  с COMM1 Здесь Происходит Загрузка прошивки в ПЛИС sv6.bin	  
    fprintf(dbg_out,"main(ЦП)_sv43:13-IPMP2<-->COMM1+LOAD_FPGA_\n");
    error = drv_ipmp_dsp16_plug( "/dev/ipmp/ipmp2", 1 );
    if(error)
    {
     REG_OSTS1 |= OSTS1_EXCH_COMM1_FAIL;
     fprintf(dbg_out,"?IPMP2<-->COMM1:error=%d_stop\n?",error);
     while(1);
	 {
	 	asm( " nop" );
	 }
	}
 
    //IPMP3 через ДОЗУ  с COMM2 Здесь Происходит Загрузка прошивки в ПЛИС sv6.bin	  
    fprintf(dbg_out,"main(ЦП)_sv43:14-IPMP3<-->COMM2+LOAD_FPGA_\n");
    error = drv_ipmp_dsp16_plug( "/dev/ipmp/ipmp3", 2 );
    if(error)
    {
     REG_OSTS1 |= OSTS1_EXCH_COMM2_FAIL;
     fprintf(dbg_out,"?IPMP3<-->COMM2:error=%d_stop\n?",error);
     while(1);
	 {
	 	asm( " nop" );
	 }
	}


   	//// Функция инициализирует и запускает процесс межпроцессорно-процессного
    // обмена. Переменная id указывает на уникальный номер процессора в
    // системе (от 0 до 255)  //Ядро ОС отсюда функция вызываеться
    fprintf(dbg_out,"main(ЦП)_sv43:15-Init Interprocess Communication\n"); 
   // msg_start( 2, 24 );
    msg_start( 2, 8 );

 
    //Получение Обмена Сообениями между Платами видимо завтра сделаю 
     






 























#if 0

   
    /*   
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
    */  
  
    /*
    error = drv_mcbsp_plug(&mcbsp_ctx);
    if(error == OSE_OK) print("OK\n"); else print("ERROR\n");
    if(error != OSE_OK) REG_OSTS0 |= OSTS0_MCBSP_FAIL; 
    */

   // drv_dbgout_plug();    
   // #ifdef MAIN_ONLY
   // print("MAIN_ONLY was defined for project build.\n");
   // #endif
   // print("OS Root File System has been successfully initialized.\n");
    
    // ----------------------------------------------------------

    
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
 
 
#endif 
    
    // ----------------------------------------------------------  
    //print("Starting SIOS: ");
    s_prc_attr pattr;
    memset(&pattr, 0, sizeof(s_prc_attr));
    pattr.stack = 0x2000;
    prc_create(&os_main, NULL, 0, &pattr);

   // print("Operating System has been successfully loaded.\n", true);
    prc_system();
    return 0;

}
