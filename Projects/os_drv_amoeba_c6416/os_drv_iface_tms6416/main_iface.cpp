/**********************************************************************************************************************
*                                        (c) COPYRIGHT by ZAO RCZI FORT.                                             *
*                                               All rights reserved.                                                  *
***********************************************************************************************************************
#
# NAME
# > main_iface.cpp  Функция Старта ЗООСРВ и Запуска ТПО для Переферийной Платы ПВ-40 !!! 
#
# DESCRIPTION
#   
#   
# REFERENCEs
# > 
#
# NOTEs
# > 
*/
#define SYSCALL_DIRECT
#include <os.h>
#include <rts.h>


//Файлы с Драйверами Видимо Это у нас

#include <drv_led.h>
#include <drv_rnd.h>
#include <drv_rik.h>       //Ридер РИК
#include <drv_gpio.h>
#include <drv_lcd.h>       //дисплей
#include <drv_fwmem.h>     //внутренняя флэшка AT48BV322D
#include <drv_kbd_4x6.h>   //клава


//Теперь добавим USB
#include <drv_usbhc.h>
#include <drv_usb.h>
#include <drv_usbms.h>



#include <drv_dbgout.h>
#include <drv_rtc.h>        //часы реального времени
#include <drv_mcbsp.h>
#include <drv_ipmp.mcbsp.h>// IPMP обмен черз шину MCBSP с Центарльными ЦП


//Файловая Система наша
#include <drv_vfat.h>
#include <__fs.h>                //Файловая система


extern int os_main(void* arg);   //Внешний Старт от os_Main_Нужно_видимо_ТПО

// ---------------------------------------------------------------------------



DEFINE_USBDEV(USB1,0,0);
DEFINE_USBDEV(USB2,1,0);
DEFINE_USBDEV(USB3,2,0);

void dev_assignLetter(uint32 usbhc_plug)
{
  switch(usbhc_plug)
  {
    case USBHC_NEC_PLUG: 
    {
      dev.assignLetter(USB1,0,1,4);
      dev.assignLetter(USB2,1,1,4);  
    }
    break;
    case USBHC_ISP_PLUG: 
    {
      dev.assignLetter(USB2,0,1,4);
      dev.assignLetter(USB3,1,1,4);  
    }
    break;    
  }  
}





// ---------------------------------------------------------------------------
void os_config()
{
  syscall_init( __syscall_tab, sizeof(void*) * SYSCALL__COUNT__ );

  OS_TOUCH_CODE();

  sys_setname( "iface" );

  sys_frequency = 720000000ull;
  sys_quant = core_init_cfg.sys_quant;

  emif_init();
}
// ---------------------------------------------------------------------------
int test_process_1( void* arg )
{
  uint32 d;
  #define L 1024
  char buf[L];
  msg_open( "speed_test_1" );
  d = msg_discover( "comm0", "speed_test_1", SEM_INFINITY );
  for( int32 i = 0; i < L; i++ ) buf[i] = i;
  while( true )
  {
    msg_send( d, buf, L );
  }
  msg_close();
}
// ---------------------------------------------------------------------------
int test_process_2( void* arg )
{
  #define L 1024
  char buf[L];
  s_message* m;
  uint32 st, et;
  int32 traf;
  FILE* dout; 
  dout = fopen( "/dev/dbgout", "wb" );
  msg_open( "speed_test_2" );
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
      fprintf( dout, "speed: %d.%02d Mbit/sec\n", traf / 10000000, (traf % 10000000)/10000  );
      traf = 0;
    }
  }
  msg_close();
  fclose( dout );
}
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

#if 0
int os_process(void* arg)
{
 
    //Тестирование Старта Процесса os_main. Когда есть ТПО
    /*
    s_prc_attr pattr;
    memset( &pattr, 0, sizeof(pattr) );
    pattr.stack = 4096;   
    prc_create( &os_main, NULL, 0, &pattr );  //должны типа в os_main Где у нас есть ТПО или другаю Приложуха нужно убрать tpo_15_iface.lib
    */
    //Тестирование Процесса заглушки
     
    while(true)
    {
    asm(" nop");
    }
    

}
#endif


// ---------------------------------------------------------------------------
// Заглушка для тестирования ОС и драйверов без ТПО нужно тогда удалить библиотеку ТПО tpo_15_iface.lib
// Если нужно Тестировать с ТПО то тогда нужно закоментировать этот вызов os_main чтобы os_main
// вызывался из ТПО и стартовал
#if 0
int os_main(void* arg)
{

  while(true)
  {
    asm(" nop");
  }
}
#endif



//#if 0
int os_process(void* arg)
{
    int32   error;  
    s_gpio_start_value gpio;
    FILE* dbg_out;
    uint32 dscr,rtc_d,dtm;
    dscr = drv_mkd( "/" );
    if( dscr == RES_VOID ) goto fail;
    drv_create( dscr, "dev", INOT_FOLDER );
    drv_create( dscr, "mnt", INOT_FOLDER );
    drv_select( dscr, "dev" );
    drv_create( dscr, "ipmp", INOT_FOLDER );
    drv_rmd( dscr );
   
    
 
   
    mcbsp_context mcbsp_ctx;
    mcbsp_ctx.out_port      = MCBSP_PORT2;
    mcbsp_ctx.in_port1      = MCBSP_PORT0;
    mcbsp_ctx.in_port2      = MCBSP_PORT1;
    mcbsp_ctx.mcbsp_cfg_in  = iface_in_mcbspCfg;  
    mcbsp_ctx.mcbsp_cfg_out = iface_out_mcbspCfg;
    mcbsp_ctx.edma_cfg_in   = iface_in_edmaCfg;   
    mcbsp_ctx.edma_cfg_out  = iface_out_edmaCfg;

    error = drv_dbgout_plug();
    dbg_out = fopen( "/dev/dbgout", "w" );

    gpio.reg_gpen  = 0x00F0;
    gpio.reg_gpdir = 0x0000;
    gpio.reg_gpval = 0x0000;    
    fprintf(dbg_out,"iface(ПП)_pv40:01 - Init_GPIO\n");
    error = drv_gpio_plug(&gpio);
    if(error) REG_OSTS0 |= OSTS0_GPIO_FAIL;
   
    fprintf(dbg_out,"iface(ПП)_pv40:02 - Init_светодиодов\n");
    error = drv_led_plug();
    if(error) REG_OSTS0 |= OSTS0_LED_FAIL;
    

    fprintf(dbg_out,"iface(ПП)_pv40:03 - Init_ MCBSP\n");
    error = drv_mcbsp_plug(&mcbsp_ctx);
    if(error) REG_OSTS0 |= OSTS0_MCBSP_FAIL;
    
    
    fprintf(dbg_out,"iface(ПП)_pv40:05 - Init_LCD\n");
    error = drv_lcd_plug(9);
    if(error)
    {
       REG_OSTS0 |= OSTS0_DISPLAY_FAIL;
       fprintf(dbg_out,"?05-Init_LCD:error=%d_stop?\n\r",error);
       while(1);
	   {
	 	asm( " nop" );
	   }
     
    }
    
    fprintf(dbg_out,"iface(ПП)_pv40:06 - Init_RTC\n");
    error = drv_rtc_plug("/dev/rtc");
    if(error) REG_OSTS0 |= OSTS0_RTC_FAIL;
    if((rtc_d = drv_mkd( "/dev/rtc" ) ) == RES_VOID )
    fprintf(dbg_out,"iface_pv40:Ошибка открытия rtc\n");
    drv_ioctl( rtc_d, RTC_GET_TIME, &dtm );
    time_set( dtm );
    
    
  
    fprintf(dbg_out,"iface(ПП)_pv40:07 - Init_ГСЧ\n");
    error = drv_rnd_plug();
    if(error) REG_OSTS0 |= OSTS0_RND_FAIL;



    
    fprintf(dbg_out,"iface(ПП)_pv40:08 - Init_клавиатуры\n");
    error = drv_kbd_4x6_plug(2);
    if(error) REG_OSTS0 |= OSTS0_KBD_FAIL;
    
	
    fprintf(dbg_out,"iface(ПП)_pv40:09 - Init_внутренней флэш\n");
    error = drv_fwmem_plug("/fwmem", 0x64000000, &fwmem_at49bv322d_gpio );
    if(error) REG_OSTS0 |= OSTS0_FWMEM_FAIL;
    

	
    fprintf(dbg_out,"iface(ПП)_pv40:10 - Init_драйвера РИК\n");
    error = drv_rik_plug(10, 1);
    if(error) REG_OSTS0 |= OSTS0_RIK_FAIL;    
    


    //Журнал SYSLog нужен в боевом проекте для запис LOG на флэшку может здесь не нужен.
    /*
    fprintf(dbg_out,"iface(ПП)_pv40:11 - Init_журнала syslog\n");
    syslog_init();
    syslog_level(LOG_DEBUG);
    */
      
    fprintf(dbg_out,"iface(ПП)_pv40:12 - Init_контроллера USB\n");
    
    uint32 usbhc_plug;
    s_usbhc_plug usbhc;
    usbhc.isp.gpio_number = 1;   //isp1760 driver 
    usbhc.nec.gpio_number = 5;   //nec driver  
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
                uint32 d   = drv_mkd("/dev/usb/");
                drv_ioctl(d, USB_ADD_DEVICE_CLASS, &msd);
                drv_rmd(d);
        }
    }


	dev_assignLetter(usbhc_plug); //назначение букв usb партициям
    drv_vfat_trigger_plug();

//#if 0
    //Оставлю это не завтра  меж платный обмен IPMP!!! 17.01.2018
    //МежПроцессорный обмен по шине MCBSP c ЦП 
    fprintf(dbg_out,"iface(ПП)_pv40:13-Init_IPMP0_MCBSP<->MAIN\n");
    error = drv_ipmp_mcbsp_plug( "/dev/ipmp/ipmp0" );
    if(error) REG_OSTS0 |= OSTS0_MCBSP_FAIL;
   
//#if 0
    // Функция инициализирует и запускает процесс межпроцессорно-процессного
    // обмена. Переменная id указывает на уникальный номер процессора в
    // системе (от 0 до 255)  //Ядро ОС отсюда функция вызываеться
    fprintf(dbg_out,"iface(ПП)_pv40:14-Init Interprocess Communication\n");
    msg_start( 1, 8 );  //1 порядковый номер ЦП в нашеё системе
//#endif

	fprintf(dbg_out,"iface(ПП)_pv40:++System Startup Succesful++\n");
    fclose(dbg_out); //Зарывем Отладочный вывоод
    
    //Для тестирования ТПО Запускаем os_main находящийся в ТПО или у нас локально.
    s_prc_attr pattr;
    memset( &pattr, 0, sizeof(pattr) );
    pattr.stack = 4096*4;   
    prc_create( &os_main, NULL, 0, &pattr );  //должны типа в os_main Где у нас есть ТПО или другаю Приложуха нужно убрать tpo_15_iface.lib  
    
    
   // prc_system();    //Функция переводит процесс в состояние спящего системного процесса.




	#if 0  
    s_prc_attr pattr;
    memset( &pattr, 0, sizeof(pattr) );
    pattr.stack = 4096;   
    fprintf(dbg_out,"14 - Создание основного процесса СИОС\n");
    prc_create( &os_main, NULL, 0, &pattr );
	//    prc_create( &test_process_1, NULL, 0, &pattr );
	//    prc_create( &test_process_2, NULL, 0, &pattr );
    fprintf(dbg_out,"15 - Система запущена!!!\n");
    fclose(dbg_out);
    prc_system();
    #endif

	fail:

	    while( true )
	        asm( " nop" );

  

}


//#endif













