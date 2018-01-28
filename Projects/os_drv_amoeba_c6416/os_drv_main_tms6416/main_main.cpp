/**********************************************************************************************************************
*                                        (c) COPYRIGHT by ZAO RCZI FORT.                                             *
*                                               All rights reserved.                                                  *
***********************************************************************************************************************
#
# NAME
# > main_main.cpp  Функция Старта ЗООСРВ и Запуска ТПО для ЦП Цетральных Процессоров 0 и 1 платы СВ-039 !!! 
#
# DESCRIPTION
# 
#   
# REFERENCEs
# > 
#
# NOTEs
# > 
********************************************************************************************************/
#define SYSCALL_DIRECT
#include <os.h>
#include <rts.h>


#include <drv_gpio.h>                //GPIO
#include <drv_fwmem.h>               //внутренняя флэшка S29

//USB драйвер
#include <drv_usbhc.h>
#include <drv_usb.h>
#include <drv_usbms.h>

//Отладочный вывод
#include <drv_dbgout.h>


#include <drv_mcbsp.h>


//МежПроцессорное Взаимодействие 
#include <drv_ipmp.mcbsp.h>           //МежПроцессорное Взаимодействие по шине MCBSP к Интерфейсной Плате IFACE 
#include <drv_ipmp.dsp-15.h>          //МежПроцессорное взаимдействие  с Сетевыми Процессорами!через ДОЗУ EMIF
                                      //Для Центрального Процессора здесь осуществляеться загрузка Прошивки ПЛИС ДОЗУ sv5.bin
									  //из USB флэшки

#include <drv_nvram.h>                //ЭОЗУ ЦП NVRAM CY14B104N

//Файловая система
#include <drv_vfat.h>               //попозже
#include <__fs.h>


#include <drv_dnsd.h>                //Датчик Вскрытия 




extern int os_main(void* arg);




DEFINE_USBDEV(USB1,0,0);
DEFINE_USBDEV(USB2,1,0);
DEFINE_USBDEV(USB3,2,0);

/*****************************************************************************
Syntax:  void dev_assignLetter(uint32 usbhc_plug) 	    
Remarks:			    
*******************************************************************************/
void dev_assignLetter(uint32 usbhc_plug)
{
  switch(usbhc_plug)
  {
    case USBHC_NEC_PLUG: 
    {
      dev.assignLetter(USB1,0,1,4);
    }
    break;
    case USBHC_ISP_PLUG: 
    {
      dev.assignLetter(USB3,0,1,4);     
    }
    break;    
  }  
}



// ---------------------------------------------------------------------------
void os_config()
{
  syscall_init( __syscall_tab, sizeof(void*) * SYSCALL__COUNT__ );

  OS_TOUCH_CODE();

  sys_setname( "main" );

  sys_frequency = 720000000ull;
  sys_quant = core_init_cfg.sys_quant;

  emif_init();
}

/*****************************************************************************
Syntax:  bool wait_msd0_flash()    	    
Remarks:			    
*******************************************************************************/
bool wait_msd0_flash()
{
  s_inode *first_list, *list;
  uint32 msd_found;
  //  uint64 limit_time = time_m()+10000;
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
    asm(" nop");    
    while(list != NULL)
    {
      if(memcmp(list->name, "sd", 2)==0)
      {
        msd_found = 1;
        asm(" nop");
        break;
      }
      list = list->next;
    }
    drv_list_destroy( first_list );
    asm(" nop");    
    if( msd_found ) break;


    
   // if(time_m()>=limit_time)
   // {
    //  drv_rmd(d);
     // return false;
    //}
    
    prc_yield();
  }

  drv_rmd(d);

  return OSE_OK;
}



// ---------------------------------------------------------------------------
int test_process_1( void* arg )
{
  uint32 d;
  #define L 1024
  char buf[L];
  s_message* m;
  uint32 st, et;
  int32 traf;
  FILE* dout;
  dout = fopen( "/dev/dbgout", "wb" );
  msg_open( "speed_test_1" );
  st = time_s();
  traf = 0;
  while( true )
  {
    msg_recv( &m, SEM_INFINITY );
    msg_free( m );
    et = time_s();
    traf += m->length;
    if( ( et - st ) >= 10 )
    {
      st = et;
      traf <<= 3;
      fprintf( dout, "speed: %d.%03d Mbit/sec\n", traf / 10000000, (traf % 10000000)/10000  );
      traf = 0;
    }
  }
  msg_close();
  fclose( dout );
}
// ---------------------------------------------------------------------------
int test_process_2( void* arg )
{
  uint32 d;
  #define L 1024
  char buf[L];
  msg_open( "speed_test_2" );
  d = msg_discover( "comm0", "speed_test_2", SEM_INFINITY );
  for( int32 i = 0; i < L; i++ ) buf[i] = i;
  while( true )
  {
    msg_send( d, buf, L );
  }
  msg_close();
}




// ---------------------------------------------------------------------------
// Заглушка для тестирования ОС и драйверов без ТПО нужно тогда удалить библиотеку ТПО tpo_15_main.lib
// Если нужно Тестировать с ТПО то тогда нужно закоментировать этот вызов os_main чтобы os_main
// вызывался из ТПО и стартовал для ЦП(main)Процессоров
#if 0
int os_main(void* arg)
{

  while(true)
  {
    asm(" nop");
  }
}
#endif




// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
int os_process(void* arg)
{
    s_gpio_start_value gpio;
    int32   error;  
    FILE* dbg_out;
    

  // -- Initialize extensions ------------------------------------------------
    uint32 dscr = drv_mkd( "/" );  
    if( dscr == RES_VOID ) goto fail;
    drv_create( dscr, "dev", INOT_FOLDER );
    drv_create( dscr, "mnt", INOT_FOLDER );
    drv_select( dscr, "dev" );
    drv_create( dscr, "ipmp",INOT_FOLDER );
    drv_create( dscr, "net",INOT_FOLDER );
    drv_rmd( dscr );
    
    //На Центральном Процессоре Испольщуеться 2 шины MCBSP 0 и 1 для обмена с IFACE платой 
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

    gpio.reg_gpen  = 0x00F0;
    gpio.reg_gpdir = 0x0000;
    gpio.reg_gpval = 0x0000;
    fprintf(dbg_out,"main(ЦП)_sv39:01-Init_GPIO\n");
    error = drv_gpio_plug(&gpio);
    if(error) REG_OSTS0 |= OSTS0_GPIO_FAIL;
    else
    {
        // Reset PLIS видимо сбрасваем ПЛИС
        s_gpio_load_plis lplis;
        dscr = drv_mkd( "/dev/gpio" );
        memset( &lplis, 0, sizeof(lplis) );
        lplis.gpio_prog = 15;
        lplis.gpio_init = 12;
        lplis.gpio_clk  = 14;
        lplis.gpio_dout = 13;
        lplis.gpio_done = 11;
        fprintf(dbg_out,"main(ЦП)_sv39:02-GPIO_ResetFPGA\n");
        error=drv_ioctl( dscr, GPIO_RESET_PLIS, &lplis );  //ПЛИС мы reset через драйвер GPIO
        
        if(error)
   	    {
  			fprintf(dbg_out,"?GPIO_ResetFPGA:error =%d\n?",error);
     		while(1);
	 		{
	 		 asm( " nop" );
	 		}
		}
      drv_rmd( dscr );
    }


 
    fprintf(dbg_out,"main(ЦП)_sv39:02-Init_внутренней флэш\n");
    error = drv_fwmem_plug("/fwmem", 0x64000000, &fwmem_s29al032dxxxxx04_gpio );
    if(error) REG_OSTS0 |= OSTS0_FWMEM_FAIL;  
    
    fprintf(dbg_out,"main(ЦП)_sv39:03-Init_MCBSP\n");
    error = drv_mcbsp_plug(&mcbsp_ctx);
    if(error) REG_OSTS0 |= OSTS0_MCBSP_FAIL;

   
    fprintf(dbg_out,"main(ЦП)_sv39:04-Init_драйвера ДНСД\n");
    error = drv_dnsd_plug( "/dev/dnsd" );
    if(error) REG_OSTS0 |= OSTS0_MCBSP_FAIL;
    

	//Для Боевого(Release) Проекта только Старт SYSLOG!!! 
    /*
    fprintf(dbg_out,"main(ЦП)_sv39:05-Init_журнала syslog\n");
    syslog_init();
    syslog_level(LOG_DEBUG);
    */
   
    fprintf(dbg_out,"main(ЦП)_sv39:06-Init_ЭОЗУ(NVRAM)\n");
    if( ( error = drv_nvram_plug("/dev/nvram") ) != OSE_OK )
    {
      if(error == OSE_DATA_TEST_ERROR)
        REG_OSTS0 |= OSTS0_NVRAM_FAIL1;
      else
        REG_OSTS0 |= OSTS0_NVRAM_FAIL2;
    }


    //Инициализация USB контроллера
    fprintf(dbg_out,"main(ЦП)_sv39:06 - Init_USB Controller\n");
    uint32       usbhc_plug;
    s_usbhc_plug usbhc;
    usbhc.isp.gpio_number = 5;
    usbhc.nec.gpio_number = 5;    
    error = drv_usbhc_plug( &usbhc, &usbhc_plug );    

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



     fprintf(dbg_out,"main(ЦП)_sv39:10-Init_msd0_flash\n");
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

     dev_assignLetter(usbhc_plug); //ничего не возвращает функция нам. 
    
    
     fprintf(dbg_out,"main(ЦП)_sv39:06-Init VFAT_DRV\n");
     error=drv_vfat_trigger_plug();
	 if(error)
	 {

	 }

    

    //Инициализация Спарки и МежПроцессорного Обмена
        
    //Модуль Инициализации Спареных Процессоров(Спарки) ЦП Центарльных процессоров
	//реализовано через syscall ОС Переопределно //функция возвращает значение назад.
    //modsyn_m448m15_init переопределно в os_syn Спарка просто вистент по таймату
	
    fprintf(dbg_out,"main(ЦП)_sv39:10-Init_SPARKA\n");
    error=syn_init( 20, 60*60000, NULL );  
     
    
    
    //IPMP0 через MCBSP0 ->iface  , MCBSP1 <--iface
    fprintf(dbg_out,"main(ЦП)_sv39:11-Init_IPMP0_MCBSP <-> IFACE\n");
    error = drv_ipmp_mcbsp_plug( "/dev/ipmp/ipmp0" );
    if(error) REG_OSTS1 |= OSTS1_EXCH_IFACE_FAIL;
    

    //IPMP1 через ДОЗУ  с COMM0 Здесь Происходит Загрузка прошивки в ПЛИС sv5.bin
    
    fprintf(dbg_out,"main(ЦП)_sv39:07-IPMP1<-->COMM0+LOAD_FPGA_\n");
    error = drv_ipmp_dsp15_plug( "/dev/ipmp/ipmp1", 0 );
    if(error)
    {
     REG_OSTS1 |= OSTS1_EXCH_COMM0_FAIL;
     fprintf(dbg_out,"?IPMP1<-->COMM0:error=%d_stop\n?",error);
     while(1);
	 {
	 	asm( " nop" );
	 }
	}
    
    //IPMP2 через ДОЗУ  с COMM1 Здесь Происходит Загрузка прошивки в ПЛИС sv5.bin
    fprintf(dbg_out,"main(ЦП)_sv39:07-IPMP2<-->COMM1+LOAD_FPGA_\n");
    error = drv_ipmp_dsp15_plug( "/dev/ipmp/ipmp2", 1 );
    if(error)
    {
     REG_OSTS1 |= OSTS1_EXCH_COMM1_FAIL;;
     fprintf(dbg_out,"?IPMP2<-->COMM1:error=%d_stop?\n?",error);
     while(1);
	 {
	 	asm( " nop" );
	 }
	}
    




	//// Функция инициализирует и запускает процесс межпроцессорно-процессного
    // обмена. Переменная id указывает на уникальный номер процессора в
    // системе (от 0 до 255)  //Ядро ОС отсюда функция вызываеться
    fprintf(dbg_out,"main(ЦП)_sv39:12-Init Interprocess Communication\n"); 
    msg_start( 2, 24 );
    //msg_start( 2, 8 );

	//
    fprintf(dbg_out,"main(ЦП)_sv39:++OS_System Startup Succesful++\n");
    fclose(dbg_out); //Зарывем Отладочный вывоод
    

    //Для тестирования ТПО Запускаем os_main находящийся в ТПО или у нас локально.
    s_prc_attr pattr;
    memset( &pattr, 0, sizeof(pattr) );
    pattr.stack = 4096;   
    prc_create( &os_main, NULL, 0, &pattr );  //должны типа в os_main Где у нас есть ТПО или другаю Приложуха нужно убрать tpo_15_iface.lib  
    
    
   // prc_system();    //Функция переводит процесс в состояние спящего системного процесса.


#if 0   
    //IPMP1 через ДОЗУ  с COMM0
    fprintf(dbg_out,"07 - Загрузка ПЛИС ДОЗУ и инициализация межпроцессорного обмена сообщениями(IPMP DOZU) с COMM0\n");
    error = drv_ipmp_dsp15_plug( "/dev/ipmp/ipmp1", 0 );
    if(error) REG_OSTS1 |= OSTS1_EXCH_COMM0_FAIL;
    
    //IPMP2 через ДОЗУ  с COMM1
    fprintf(dbg_out,"08 - Инициализация межпроцессорного обмена сообщениями(IPMP DOZU) с COMM1\n");
    error = drv_ipmp_dsp15_plug( "/dev/ipmp/ipmp2", 1 );
    if(error) REG_OSTS1 |= OSTS1_EXCH_COMM1_FAIL;

   // socket_init(10);    //Верхний Уровень Протокола TCP/IP который будет ложиться на VNET виртуальные Адаптеры
#endif      
      



#if 0   //skd
   
   // s_prc_attr pattr;
   // memset( &pattr, 0, sizeof(pattr) );
   // pattr.stack = 8192;
   // fprintf(dbg_out,"11 - Создание основного процесса СИОС\n");

 //   prc_create( &os_main, NULL, 0, &pattr );
//    prc_create( &test_process_1, NULL, 0, &pattr );
//    prc_create( &test_process_2, NULL, 0, &pattr );

    fprintf(dbg_out,"12 - Система запущена!!!\n");
    fclose(dbg_out);
    prc_system();
#endif

fail:

    while( true )
        asm( " nop" );
}

