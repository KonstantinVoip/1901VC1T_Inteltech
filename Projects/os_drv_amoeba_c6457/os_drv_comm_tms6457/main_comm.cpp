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

/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
void os_fail()
{
  int_disable();
  while( true )
    asm( " idle " );
}


/**
 * Sets OS configuration.
 */
void os_config()
{
    syscall_init( __syscall_tab, sizeof(void*) * SYSCALL__COUNT__ );
    OS_TOUCH_CODE();
    sys_frequency = 1000000000ull;
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
 
 
#if 0 
    
    // Initialize the OS root file system
    d = drv_mkd( "/" );
    if(d == RES_VOID) return os_panic();
    error |= drv_create(d, "dev", INOT_FOLDER);
    error |= drv_select(d, "dev" );
    error |= drv_create(d, "net", INOT_FOLDER);
    error |= drv_create(d, "ipmp", INOT_FOLDER);
    drv_rmd(d);
    if(error != OSE_OK) return os_panic();
    drv_dbgout_plug();
    #ifdef COMM_ONLY
    print("COMM_ONLY was defined for project build.\n");
    #endif
    print("OS Root File System has been successfully initialized.\n"); 
  
    // ----------------------------------------------------------  
    print("Initializing FWMEM driver: ");
    error = drv_fwmem_plug("/fwmem", 0xb0000000, &fwmem_s29al032dxxxxx04_gpio_m632_comm );    
    if(error == OSE_OK) print("OK\n"); else print("ERROR\n");
    if(error != OSE_OK) REG_OSTS0 |= OSTS0_FWMEM_FAIL;
  
    // ----------------------------------------------------------  
    print("Initializing IPMP DOZU driver: ");    
    error = drv_ipmp_dsp16_plug( "/dev/ipmp/ipmp0", IPMP_DSP16_CH_BOTH );
    if(error == OSE_OK) print("OK\n"); else print("ERROR\n");
    if(error != OSE_OK) REG_OSTS1 |= OSTS1_EXCH_MAIN_FAIL;  
    
    // ----------------------------------------------------------  
    struct 
    {
        uint32  number;
        char    name[8];
    } processor;
    d = drv_mkd("/dev/ipmp/ipmp0");
    error = drv_ioctl(d, IPMP_NUMBER, &processor.number);
    if(error != OSE_OK) os_panic();
    drv_rmd(d);
    strcpy(processor.name, "comm");
    processor.name[4] = '0' + processor.number;
    processor.name[5] = 0;
    
    // ----------------------------------------------------------  
    print("Initializing Network Adapter driver: ");
    net_config netcfg;
    memset( &netcfg, 0, sizeof(net_config) );
    netcfg.mask4 = NET_IP4( 255, 255, 255, 0 );
    netcfg.ip4 = NET_IP4( 192, 168, processor.number, 1 );
    netcfg.mac[0] = 0x00;
    netcfg.mac[1] = 0x80;
    netcfg.mac[2] = 0xc0;
    netcfg.mac[3] = 0xa8;
    netcfg.mac[4] = processor.number;
    netcfg.mac[5] = 0x01;    
    error = drv_eth6457_plug( "/dev/net/eth0", netcfg, 64, 64);
    if(error == OSE_OK) print("OK\n"); else print("ERROR\n");
    if(error != OSE_OK) REG_OSTS0 |= OSTS0_NETCARD_FAIL;    
    
    // ----------------------------------------------------------  
    print("Running Inter-Process Exchange: ");
    error  = sys_setname(processor.name);
    error |= msg_start(3 + processor.number, 8);
    if(error == OSE_OK) print("OK\n"); else print("ERROR\n");    
    if(error != OSE_OK) REG_OSTS1 |= OSTS1_EXCH_FAIL;  

    // ----------------------------------------------------------    
    print("Opening OS Message Connection: ");
    error = msg_open("os");    
    if(error == OSE_OK) print("OK\n"); else print("ERROR\n");      

    // ----------------------------------------------------------  
    print("Discover OS Message channel to MAIN: ");
    d = msg_discover("main", "os", SEM_INFINITY);
    if(d != RES_VOID) print("OK\n"); else print("ERROR\n");    
    if(d == RES_VOID) REG_OSTS1 |= OSTS1_EXCH_MAIN_FAIL;  

    // ----------------------------------------------------------  
    print("Discover OS Message channel to IFACE: ");
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
    
      //видимо это мы выделяем стек для задач и запускаем os_main наш любимый
    s_prc_attr pattr;
    memset( &pattr, 0, sizeof(pattr) );
    pattr.stack = 4096;  //16384   // 16 Kb //4Кб                
    prc_create( &os_main, NULL, 0, &pattr );
    prc_system();    //Функция переводит процесс в состояние спящего системного процесса.

#endif 
 
  

    return 0;
}

   //////////////////////////////////////////////////////////////////////////////////////////// 




