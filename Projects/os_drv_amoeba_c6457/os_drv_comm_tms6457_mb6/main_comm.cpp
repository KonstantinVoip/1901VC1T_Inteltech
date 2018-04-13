/**********************************************************************************************************************
*                                        (c) COPYRIGHT by ZAO RCZI FORT.                                             *
*                                               All rights reserved.                                                  *
***********************************************************************************************************************
#
# NAME
# > main_comm.cpp Функция Старта Сетевого Процессора(СП) TMS6457 !!! 
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

#include <drv_fwmem.h>
#include <drv_dbgout.h>
#include <net_struct.h>
#include <drv_eth6457.h>
#include <drv_eth6457_emac.h>


//Системный обмен с сообщениями c Центральными Процесорами
#include <drv_ipmp.dsp-16.h>


extern int os_main(void* arg);



//Структура Хранения Данных с Флэш Памяти
struct fwmem_rwbuf
{
	  void*                         buffer;
	  uint32                        length;
};




/**
 * Prints a string to debug output stream of IDE.
 *
 * @param str   an output string.
 * @Вывод на Печать отдельной функцией
 */
/*
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
*/



/**
 * Stops an initialization executing.
 *
 * @param error failed error.
 * @return given error value.
 */

/*
static int32 os_panic(int32 error=OSE_FAIL)
{
    while(true) asm(" idle");
}
*/
/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
/*
void os_fail()
{
  int_disable();
  while( true )
    asm( " idle " );
}
*/

/**
 * Sets OS configuration.
 */
void os_config()
{
    syscall_init( __syscall_tab, sizeof(void*) * SYSCALL__COUNT__ );
    OS_TOUCH_CODE();
    sys_frequency = 1000000000ull; //1 ГГц коммуникационный частота
    emif_init();
}



// ---------------------------------------------------------------------------
// Заглушка для тестирования ОС и драйверов без ТПО нужно тогда удалить библиотеку ТПО tpo_16_comm.lib
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
    uint32 number_of_comm_cpu=0;
   
    //Работат с External Flash [4М/байт] 
    int32  fwm_file=0;
    uint8 buf[32];      //буфер на 32 элемента 0-31 где будут храниться исходные данные
    uint32 offset=0;    //смещение
    fwmem_rwbuf fwrw;
    

    



    FILE* dbg_out; 
    s_message* tm_msg;   //Здесь Будет Храниться время Сетевых
    struct 
    {
        uint32  number;
        char    name[8];
    } processor;
    

   
    //EMAC_Pkt *pRX, *pTX;   //буфера для пакета      
    //fprintf(dbg_out,"iface(ПП)_pv44:?dscr_error_stop =%d\n?",dscr);
    // Initialize the OS root file system
    d = drv_mkd( "/" );
    if(d == RES_VOID)
    {
      while(true) asm(" idle");
    }
    error |= drv_create(d, "dev", INOT_FOLDER);
    error |= drv_select(d, "dev" );
    error |= drv_create(d, "net", INOT_FOLDER);
    error |= drv_create(d, "ipmp", INOT_FOLDER);
    drv_rmd(d);
    
    if(error != OSE_OK) 
    {
      
	  while(true) asm(" idle");
      
    }
    

    error = drv_dbgout_plug();
    dbg_out = fopen( "/dev/dbgout", "w" ); 
    
   

  
    // ----------------------------------------------------------  
    //print("Initializing FWMEM driver: ");
    fprintf(dbg_out,"comm_sv043:Init_FLASH_MEMORY_0 \n?");
    error = drv_fwmem_plug("/fwmem", 0xb0000000, &fwmem_s29al032dxxxxx04_gpio_m632_comm );    
    if(error != OSE_OK)
    {
       REG_OSTS0 |= OSTS0_FWMEM_FAIL;
	   while(true) asm(" idle");
    }
   
    ////////////Работаем с внешнеё FLASH памятью COMM процессора. проверяем на чтение и запись///////////
    //Объём FLASH [4М/байт] 4 = 4 194 304 [байт]  = 0x00400000 (hex)
    fwm_file = drv_mkd("/fwmem");
    if(fwm_file == RES_VOID) 
	{
       while(true) asm(" idle");  
	}


    memset(buf, 0, sizeof(buf)); //Зачищаем буфер
    fwrw.buffer = buf;
    fwrw.length = 32;
    offset=0;  					//начало флэшки

    
    error = drv_ioctl(fwm_file, FWMEM_SET_OFFSET, &offset);      //Нужно установить смещение откуда читать
    if(error != OSE_OK)
    {
	   while(true) asm(" idle");
    }
   
    /////////////
    error = drv_ioctl(fwm_file, FWMEM_READ, &fwrw); 			//Типа читаем но откуда???
    if(error != OSE_OK)
    {
	   while(true) asm(" idle");
    }





//ПОКА КОММЕНТАРИМ
#if 0  


    /*Здесь Один Коммуникационный Процессор Читает с Двух ПЛИС (ДОЗУ)*/
    fprintf(dbg_out,"comm_sv043:Init_IPMP0<-->DOZU_1 \n?");
    error = drv_ipmp_dsp16_plug( "/dev/ipmp/ipmp0", IPMP_DSP16_CH_BOTH );
    if(error != OSE_OK)
    {
     REG_OSTS1 |= OSTS1_EXCH_MAIN_FAIL; 
      while(true) asm(" idle");
    }


    
    
  
    fprintf(dbg_out,"comm_sv043:GET_NUMBER_of_comm_2 \n");
    d = drv_mkd("/dev/ipmp/ipmp0");
    error = drv_ioctl(d, IPMP_NUMBER, &number_of_comm_cpu);
    if(error != OSE_OK)
    {
        while(true) asm(" idle");
       
    }
    fprintf(dbg_out,"comm_sv043:curr_COMM =%d\n",number_of_comm_cpu);
    drv_rmd(d);
    strcpy(processor.name, "comm");
    processor.name[4] = '0' + number_of_comm_cpu;
    processor.name[5] = 0;
   

    
    // ----------------------------------------------------------  
    fprintf(dbg_out,"comm_sv043:Init_network_Adapter_3\n");
    net_config netcfg;
    memset( &netcfg, 0, sizeof(net_config) );
    netcfg.mask4 = NET_IP4( 255, 255, 255, 0 );
    netcfg.ip4 = NET_IP4( 192, 168, number_of_comm_cpu, 1 );
    netcfg.mac[0] = 0x00;
    netcfg.mac[1] = 0x80;
    netcfg.mac[2] = 0xc0;
    netcfg.mac[3] = 0xa8;
    netcfg.mac[4] = number_of_comm_cpu;
    netcfg.mac[5] = 0x01; 
    netcfg.flags = NETCFG_PROMISCUOUSE; //promisc regim enable.
       

    //идём в drv_eth6457.cpp 
    fprintf(dbg_out,"comm_sv043:PLUG_NetworkCard_Driver_4\n");
    error = drv_eth6457_plug( "/dev/net/eth0", netcfg, 64, 64);
    if(error != OSE_OK)
    {
     REG_OSTS0 |= OSTS0_NETCARD_FAIL;
     while(true) asm(" idle");
    }

    
   /// EMAC_sendPacket( Handle hEMAC, EMAC_Pkt *pPkt );

    // ----------------------------------------------------------  
    fprintf(dbg_out,"comm_sv043:RUN_Interprocess_Exchange_5\n");
    error  = sys_setname(processor.name);
    error |= msg_start(3 + processor.number, 8);
    if(error != OSE_OK)
    {
   	     REG_OSTS1 |= OSTS1_EXCH_FAIL;
		 while(true) asm(" idle");
   	   
    }
 

    // ----------------------------------------------------------    
    fprintf(dbg_out,"Opening OS Message Connection:\n ");
    error = msg_open("os");    
    if(error == OSE_OK) 
    {
    	//fprintf("OK\n"); 
    }
    else 
    {
   	    while(true) asm(" idle");
   	    //fprintf("ERROR\n");      
    }

#endif




 /*
    // ----------------------------------------------------------  
    fprintf("Discover OS Message channel to MAIN: ");
    d = msg_discover("main", "os", SEM_INFINITY);
    if(d != RES_VOID) print("OK\n"); else print("ERROR\n");    
    if(d == RES_VOID) REG_OSTS1 |= OSTS1_EXCH_MAIN_FAIL;  

    // ----------------------------------------------------------  
     fprintf("Discover OS Message channel to IFACE: ");
     d = msg_discover("iface", "os", SEM_INFINITY);
     if(d != RES_VOID) print("OK\n"); else print("ERROR\n");    
     if(d == RES_VOID) REG_OSTS1 |= OSTS1_EXCH_IFACE_FAIL;
      
    // ----------------------------------------------------------  
   fprintf("Discover OS Message channel to COMM0: ");
    d = msg_discover("comm0", "os", SEM_INFINITY);
    if(d != RES_VOID) print("OK\n"); else print("ERROR\n");    
    if(d == RES_VOID) REG_OSTS1 |= OSTS1_EXCH_COMM0_FAIL;  
    
    // ----------------------------------------------------------  
    fprintf("Discover OS Message channel to COMM1: ");
    d = msg_discover("comm1", "os", SEM_INFINITY);
    if(d != RES_VOID) print("OK\n"); else print("ERROR\n");    
    if(d == RES_VOID) REG_OSTS1 |= OSTS1_EXCH_COMM1_FAIL;  
    
    // ----------------------------------------------------------  
   fprintf("Discover OS Message channel to COMM2: ");
    d = msg_discover("comm2", "os", SEM_INFINITY);
    if(d != RES_VOID) print("OK\n"); else print("ERROR\n");    
    if(d == RES_VOID) REG_OSTS1 |= OSTS1_EXCH_COMM2_FAIL;      
 */


    
    //Время Видимо нужно будт в будущем сделать.
    /*
    fprintf(dbg_out,"comm_sv043:Get_Time_for_MAIN\n");
    error = msg_recv(&tm_msg, SEM_INFINITY);
    if(error != OSE_OK) 
    {
        	 while(true) asm(" idle");
    }
    time_set( (*(uint32*)tm_msg->data) );  
    msg_free( tm_msg );
    */

        
    fprintf(dbg_out,"comm_sv043:++OS_System Startup Succesful++\n");
    fclose(dbg_out); //Зарывем Отладочный вывоод

    //видимо это мы выделяем стек для задач и запускаем os_main наш любимый
    s_prc_attr pattr;
    memset( &pattr, 0, sizeof(pattr) );
    pattr.stack = 16384;   // 16 Kb //4Кб                
    prc_create( &os_main, NULL, 0, &pattr );
    prc_system();    //Функция переводит процесс в состояние спящего системного процесса.

    return 0;
}

   //////////////////////////////////////////////////////////////////////////////////////////// 




