/**********************************************************************************************************************
*                                        (c) COPYRIGHT by ZAO RCZI FORT.                                             *
*                                               All rights reserved.                                                  *
***********************************************************************************************************************
#
# NAME
# > main_comm.cpp  Функция Старта ЗООСРВ и Запуска ТПО для платы СВ-039 !!! 
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
#include <drv_gpio.h>             //GPIO
#include <drv_fwmem.h>            //внутренняя флэшка S29
#include <drv_dbgout.h>           //Отладочный вывод

//Системный обмен с сообщениями c Центральными Процесорами
#include <drv_ipmp.dsp-15.h>  



//Сетевая Инициализация 

#include <drv_eth6412.h>
#include <drv_eth6412_emac.h>
#include <drv_eth6412_mdio.h>
#include <net_struct.h>

//#include <vnet_eth.h>           //В МБ этот драйвер не нужен видимо у нас



extern int os_main(void* arg);

void os_fail()
{
  int_disable();
  while( true )
    asm( " idle " );
}

void os_nmi_handler()
{
  // Disable interrupts
  int_disable();
  // Generate nonmaskable interrupt for IFACE processor
  REG_GPEN  |=  0x00004000;
  REG_GPDIR |=  0x00004000;
  REG_GPVAL &= ~0x00004000;  
  asm( " nop 9 " );  
  REG_GPVAL |=  0x00004000;
  asm( " nop 9 " );
  REG_GPVAL &= 0xffffbfff;
  // Halt the processor
  while( true )
    asm( " idle " );
}

// ---------------------------------------------------------------------------
void os_config()
{
  syscall_init( __syscall_tab, sizeof(void*) * SYSCALL__COUNT__ );
  OS_TOUCH_CODE();
  sys_frequency = 500000000ull;
  sys_quant = core_init_cfg.sys_quant;
  emif_init();
}
// ---------------------------------------------------------------------------
int test_process_2( void* arg )
{
  uint32 d;
  #define L 1024
  char buf[L];
  msg_open( "speed_test_2" );
  d = msg_discover( "iface", "speed_test_2", SEM_INFINITY );
  for( int32 i = 0; i < L; i++ ) buf[i] = i;
  while( true )
  {
    msg_send( d, buf, L );
  }
  msg_close();
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
  //FILE* dout;
  uint32 dout;
  //dout = fopen( "/dev/dbgout", "wb" );
  dout = drv_mkd( "/dev/dbgout" );
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
      drv_write( dout, "speed: ", 7 );
      itoa( traf / 10000000, buf );
      drv_write( dout, buf, strlen(buf) );
      drv_write( dout, ".", 1 );
      itoa( (traf % 10000000)/10000, buf );
      if( strlen(buf)==1) drv_write( dout, "00", 2 );
      else if( strlen(buf)==2) drv_write( dout, "0", 1 );
      drv_write( dout, buf, strlen(buf) );
      drv_write( dout, " Mbit/sec\n", 10 );
      traf = 0;
    }
  }
  msg_close();
  drv_rmd( dout );
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




/**************************************************************************************************
Syntax:    int os_process(void* arg) 	  		
Return Value: СТАРТ инициализации ЗООСРВ amoeba
***************************************************************************************************/
int os_process(void* arg)
{
  s_gpio_start_value gpio;
  uint32 number_of_comm_cpu;
  char pname[8];
  int32   error;  
  FILE* dbg_out;
  
  //Для ethernet
  net_config ncfg;  
  uint32 net;

  uint32 dint;
 
  uint32 d = drv_mkd( "/" );
  if( d == RES_VOID ) goto fail;
  drv_create( d, "dev", INOT_FOLDER );
  drv_select( d, "dev" );
  drv_create( d, "net", INOT_FOLDER );
  drv_create( d, "ipmp", INOT_FOLDER );
  drv_rmd( d );
  
  error = drv_dbgout_plug();
  dbg_out = fopen( "/dev/dbgout", "w" );

  gpio.reg_gpen  = 0x00F0;
  gpio.reg_gpdir = 0x0000;
  gpio.reg_gpval = 0x0000;    
  fprintf(dbg_out,"comm(СП)_sv39:01-Init_GPIO\n");
  error = drv_gpio_plug(&gpio);
  if(error) REG_OSTS0 |= OSTS0_GPIO_FAIL;
 
 
  fprintf(dbg_out,"comm(СП)_sv39:02-Init_внутренней флэш\n");
  error = drv_fwmem_plug("/fwmem", 0x90000000, &fwmem_s29al032dxxxxx04_gpio );
  if(error) REG_OSTS0 |= OSTS0_FWMEM_FAIL;


//#if 0  //Часть Которая отвечает за Межпроцессорный обмен

  //Системный Обмен Сетевых с Центарльным нужен Здесь 
  //так раздаються номера коммункационных интерфейсов 
  fprintf(dbg_out,"comm(СП)_sv39:03-Init_IPMP0_EMIF_A <-DOZU-><-> MAIN\n");
  error = drv_ipmp_dsp15_plug("/dev/ipmp/ipmp0");
  d = drv_mkd( "/dev/ipmp/ipmp0" );

  //Получение номера Сетевого Интерфейса(CPU) от Центральных.   
   error = drv_ioctl( d, IPMP_NUMBER, &number_of_comm_cpu );
   if( error < 0 )
      {
       while( true )
       asm(" nop");
      }
   drv_rmd( d );
   fprintf(dbg_out,"comm(СП)_sv39:04-Get_Num_Iface =%d\n",number_of_comm_cpu);
     
  
   //Вот Имя в межпроцессорном обмене
   strcpy( pname, "comm" );
   pname[4] = '0' + number_of_comm_cpu;
   pname[5] = 0;
   sys_setname( pname );
   fprintf(dbg_out,"comm(СП)_sv39:06-Init Interprocess Communication\n"); 
   error=msg_start( 3 + number_of_comm_cpu, 4 ); 
   if( error < 0 )
     {
       fprintf(dbg_out,"?Interprocess Communication Failed%d_stop?\n?",error);
       while( true )
       asm(" nop");
     }
//#endif
  
  //Инициализация Ethernet.

  number_of_comm_cpu=0;
  memset( &ncfg, 0, sizeof(ncfg) );
  //set eth0 mac_adress
  ncfg.mask4 = NET_IP4( 255, 255, 255, 0 );
  ncfg.ip4 = NET_IP4( 192, 168, number_of_comm_cpu, 1 );
  ncfg.mac[0] = 0x00;
  ncfg.mac[1] = 0x11;
  ncfg.mac[2] = 0x22;
  ncfg.mac[3] = 0x44;
  ncfg.mac[4] = 0x44;
  ncfg.mac[5] = 0x44;
  ncfg.flags = NETCFG_PROMISCUOUSE;
  
  fprintf(dbg_out,"comm(СП)_sv39:05 -Init_100BaseFX_Ethernet_Interface\n");

  //Параметры Фнкции 
  //  path     - точка монтирования драйвера; <br>
  //  cfg      - конфигурационные параметры драйвера; <br>
  //  rxd_count - задание количества пакетов в приемной очереди; <br>
  //  txd_count - задание количества пакетов в передающей очереди; <br>
  //  flag - > непонтный Параметр из файла drv_eth6412_demo.cpp (определение)
    error=drv_eth6412_plug( "/dev/net/eth0", ncfg, 2, 2 );
    if(error)
	  {
          fprintf(dbg_out,"comm(СП)_sv39:?Error InitEth %d ?\n",error);
          while(1);
	 	  {
	 	  asm( " nop" );
	 	  }
	  }
    
    
    net=drv_mkd( "/dev/net/eth0" );
 


    










    fprintf(dbg_out,"comm(СП)_sv39:++OS_System Startup Succesful++\n");
    fclose(dbg_out); //Зарывем Отладочный вывоод

    //////////////////////////////////////////////////////////////////////////////////////////// 
    //видимо это мы выделяем стек для задач и запускаем os_main наш любимый
    s_prc_attr pattr;
    memset( &pattr, 0, sizeof(pattr) );
    pattr.stack = 4096;  //16384   // 16 Kb //4Кб                
    prc_create( &os_main, NULL, 0, &pattr );


fail:

  while( true )
      asm( " nop" );
}





