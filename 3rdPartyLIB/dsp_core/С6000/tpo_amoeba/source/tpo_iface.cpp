/**********************************************************************************************************************
*                                        (c) COPYRIGHT by ZAO RCZI FORT.                                             *
*        ..                                       All rights reserved.                                               *
***********************************************************************************************************************
* Module      : tpo_iface.cpp
* Description : основные функции ИП(Интерфейсного Процессора iface)
* Author      : 
******************************************************************************
******************************************************************************
* Module's Description Record:
* ============================
* Module's revision history:
* ==========================
* --------- $Log: mpcdrvlbcCyclone.h $
* --------- Initial revision
******************************************************************************/





#include <os_syscall.h>
#include <drv_dbgout.h>
#include <rts.h>

#include "tpo.h"
#include "drv_usbms.h"
#include "drv_rtc.h"
//#include "tpo_iface.h"
#include "tpo_hash.h"
#include "sialp.h"

#include <mem_fpga.iface15.h>
#include "console.h"
#include "tpo_iface.h"


#ifdef TPO5
//#include "tpo_iface_5.h"
#include "tests_name_5.h"
#endif

#ifdef TPO6
	#ifdef TPO_M711B
	#include "tests_name_711.h"
	#else
	#include "tests_name_6.h"
	#endif
#endif

#ifdef TPO7
//#include "tpo_iface_7.h"
#include "tests_name_7.h"
#endif


        #define	D	1		//работаем с СВ платой типа здесь будет Обмен ставим еденичку.
//      #define	D	0		//работаем только с Перефирйной платой ПВ-40 (ПП)


  //#define TPO711MD //Для работы без экрана надо раскоментировать.


	#define	LOAD_PO		    	9
	#define	LOAD_PO_PP			0
	#define	LOAD_PO_MAIN		1
	#define	LOAD_PO_COMM		2
	#define	LOAD_PO_ALL			3
	#define	LOAD_PO_PLIS_SI		4


   







hash_window hwindow[] =
{
  { 0x00000000, 0x001FFFFF },
  { 0x00220000, 0x0036FFFF },
  { 0x003F0000, 0x003FFFBF },
  { 0x00000000, 0x00000000 }
};

const char* _str__sys_header = "     Т П О      ";
const char* _str__usb_device_detect = "Обнаружено USB устройство";
const char* _str__usb_device_ready = "Устройство готово к работе";
const char* _str__usb_device_remove = "USB устройство отключено";



struct s_load_po_prc_arg
{
  uint32*               exit;  
};
struct s_print_time_prc_arg
{
  uint32*               exit;  
  uint32                sem;
};
struct s_usb_attach_func_prc_user_arg
{
  uint32                sem;
};

void Exit_tpo(cs_menu* m, void* arg);
#ifdef TPO5
void F_load_lif(cs_menu* m, void* arg);
#endif

int print_time_prc(s_print_time_prc_arg* arg);
int usb_device_attach(s_usb_attach_func_arg* arg);
void inmenu_set_time(cs_menu* node, void* arg);
extern void  inmenu_usb_fat_test(cs_menu* node, void* arg);
void put_end_line(const char* str, int32 key);
void put_str_center(int32 y, const char* str);

void  tpo_run_inside_menu(cs_menu* node, bool present, void*);

void F_ClearPageTablo(uint16 CountStr);
void run_menu();
void run_command_from_usb();


extern int32 tpo_msg_discover();
extern void Send_cmd_main(uint32 cmd);
extern void Send_cmd_comm(uint32 n_comm, uint32 cmd);
extern void send_main_start_sialp(kdg_sialp* par);
extern void send_comm_start_sialp(kdg_sialp* par);
extern uint32 Receve_Res_Cikl(uint32* data, uint32 Otsvetka);
extern void load_lif(void* mem_lif);

uint32 msg_pid_main;
comm_status pid_comm[NUMBER_COMM_DSP];

//uint32 ResAllTest_PP = 0;
//uint32 ResAllTest6416_0 = 0;
//uint32 ResAllTest6416_1 = 0;

uint32 sem_disp=0; 
int8 N_page_tablo;

//1-Пропускать тесты РИК и USB; 2-Не пропускать
uint16 FlagRikUSBTest;
uint16 Dnsd_enn;
cs_menu*   menu_tpo;

uint32 T_ErrTest[maxN_AllTest + 1];
char MemTablo[MaxTable][MaxStr][MaxLen+1];


//-------------------------------------------------------------------------------------------------
#define header()  {con_gotoxy(SYS_CON,0,0);\
                   con_putch(SYS_CON, CHAR_ICO0);\
                   con_putch(SYS_CON, CHAR_ICO1);\
                   con_putch(SYS_CON, CHAR_DOT);\
                   con_putch(SYS_CON, CHAR_DOT);\
                   con_putch(SYS_CON, CHAR_DOT);\
                   con_putch(SYS_CON, CHAR_LEFT_UP_WIND);\
                   con_putch(SYS_CON, CHAR_UP_WIND);\
                   con_gotoxy(SYS_CON,0,1);\
                   con_putch(SYS_CON, CHAR_ICO2);\
                   con_putch(SYS_CON, CHAR_ICO3);\
                   con_putch(SYS_CON, CHAR_BIG_DOT);\
                   con_putch(SYS_CON, CHAR_BIG_DOT);\
                   con_putch(SYS_CON, CHAR_BIG_DOT);\
                   con_putch(SYS_CON, CHAR_RIGHT_UP_WIND);\
                   con_putch(SYS_CON, CHAR_LEFT_DOWN_WIND);\
                   con_gotoxy(SYS_CON, 7,0);\
                   con_putstr(SYS_CON, _str__sys_header);\
                   con_gotoxy(SYS_CON, 29,0);\
                   con_putch(SYS_CON, PRGSS_R_FULL);\
                   con_set_text_attribute(SYS_CON,7,0,22,ATTR_REVERSE);\
                   con_set_text_attribute(SYS_CON,7,1,1,ATTR_REVERSE);\
                   con_gotoxy(SYS_CON, 8,1);\
                   con_putch(SYS_CON, CHAR_HEAD);}\
//-------------------------------------------------------------------------------------------------

static void led_blik(int n);
static void led_blik_err(int error);
static void Check_Time();
static bool wait_usb_flash();











/**************************************************************************************************\
*       
\***sss********************************************************************************************/
int tpo_iface(void* arg)
{
	int32  error=0;


	//  int32  key;
	//!!debug
	/*
	int yyy;
	int yn=0;
	while(1)
	yyy = random_test_base(yn);
	*/

	//!!debug
     /* 
	 while(1)
	 {
	  led_blik(1);   //Светодиод Абонент
	  led_blik(2);   //Светодиод Канал
	 }
     */


//#if 0 Попробуем запуститься по боевому как мы умеем 

        //Видимо Инициализация Консоли 
	    error = con_init();

		if(error!=0)
		{
			led_blik(1);
        }
	   //Установка обмена: 
		if(D)
		{
			error = tpo_msg_discover();
        } 

		if(error == TPO_OK)
		{
	      Start_TPO:

			#ifdef TPO711MD
				if(wait_usb_flash())
					run_command_from_usb();
			#else
				header();	
				Check_Time();
				run_menu();
			#endif
		}
		else
		led_blik(1);

	goto Start_TPO;

	//msg_close();
	//gotoxy(0,3);
	//cprintf("Завершение ТПО\n");

  //#endif  //Конец Запуска
}


/**************************************************************************************************\
*       
\***sss********************************************************************************************/
bool wait_usb_flash()
{
  s_inode *first_list, *list;
  uint32 msd_found;
  //uint64 limit_time = time_m()+10000;
  uint32 d = drv_mkd("/dev");
  if( d == RES_VOID ) return false;

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
	
	/*    
	    if(time_m()>=limit_time)
	    {
	      drv_rmd(d);
	      return false;
	    }
	*/    
    prc_yield();
  }

  drv_rmd(d);
  return true;
}

/**************************************************************************************************\
*       
\***sss********************************************************************************************/
void Check_Time()
{
	uint32 d;
	uint32 time;
	uint32 N = 3;
//	uint16 KEY;
//	s_rtc_regs	set_time;

	set_time:
	if(N == 0)
	{
		clrscr();
		gotoxy(1,5);
		cprintf("Проверте микросхему DS1302!!!\n");
		set_text_attribute(0,5,30,ATTR_BLINK_NORMAL);
		getch();
		return;
	}
	N--;
	d = drv_mkd( "/dev/rtc" );
    drv_ioctl(d, RTC_GET_TIME, &time);
	drv_rmd( d );
	if(time < 1261440000)	//меньше 2010 года
	{
	clrscr();
	gotoxy(3,5);
	cprintf("Установите дату и время!!!\n");
	set_text_attribute(0,5,30,ATTR_BLINK_NORMAL);

	getch();

	inmenu_set_time(NULL, NULL);
	goto set_time;
	}

}



/**************************************************************************************************\
*       
\***sss********************************************************************************************/
void led_blik(int n)
{
	uint32 d;
	uint32 green = 0x0000ff00;
	uint32 black = 0x00000000;
	uint32 red   = 0x00ff0000;

	if(n==1)
	d = drv_mkd( "/dev/led/abonent" );
	if(n==2)
	d = drv_mkd( "/dev/led/channel" );

//		while(1)
//		{
    	drv_ioctl( d, LED_SETCOLOR, &green );
		sleep_s( 1 );
		drv_ioctl( d, LED_SETCOLOR, &black );
		sleep_s( 1 );
		drv_ioctl( d, LED_SETCOLOR, &red );
		sleep_s( 1 );
		drv_ioctl( d, LED_SETCOLOR, &black );
//		}

//  drv_rmd( d );
}
/**************************************************************************************************\
*       
\***sss********************************************************************************************/
void led_blik_err(int error)
{
	uint32 d;
	uint32 green = 0x0000ff00;
	uint32 black = 0x00000000;
	uint32 red   = 0x00ff0000;

	d = drv_mkd( "/dev/led/abonent" );
	if(error==0)
	{
		while(1)
		{
		    	drv_ioctl( d, LED_SETCOLOR, &green );
				sleep_s( 3 );
				drv_ioctl( d, LED_SETCOLOR, &black );
		}
	} 
	if(error==1)
	{
		while(1)
		{
				drv_ioctl( d, LED_SETCOLOR, &red );
				sleep_s( 3 );
				drv_ioctl( d, LED_SETCOLOR, &black );
		}
	} 

	while(1);

 	drv_rmd( d );
}




















/**************************************************************************************************\
*       
\***sss********************************************************************************************/
void run_command_from_usb()
{

	int res = 0;
	
    char	file_path[32];
	//	char    number[4];
    FILE*	file;
	char 	cmd[10];
	uint8 Tip_si_alp = 0;
	uint8 Num_si_alp = 0;
	uint8 Chislo1 = 0;
	uint8 Chislo2 = 0;

   	strcpy(file_path, "/vfat/a/commanda.txt");

    file = fopen(file_path, "rb");
    if(file == NULL)
    {
   		strcpy(file_path, "/vfat/b/commanda.txt");
	    file = fopen(file_path, "rb");
	    if(file == NULL)
			return;
	}

	res = fread(cmd, 1, 10, file);
	if(!res)
	{
	fclose(file);
	return;
	}
	fclose(file);

	Tip_si_alp = cmd[0]-0x30;
	Num_si_alp = ((cmd[2]-0x30)*10)+(cmd[3]-0x30);
	Chislo1 = ((cmd[5]-0x30)*10)+(cmd[6]-0x30);
	Chislo2 = ((cmd[8]-0x30)*10)+(cmd[9]-0x30);


	kdg_sialp* par;

	par->tiptest = Tip_si_alp;
	par->kodtest = Num_si_alp;
	par->channel = 0;
	par->time_ms = 10;
	par->val_1=Chislo1;
	par->val_2=Chislo2;


	/*
	enum
	{
	RIK,
	PP_PLIS,
	MCBSP,
	CP_EXT_RAM,
	CP_INT_RAM1,
	CP_INT_RAM2,
	CP_INT_RAM3,
	CP_PLIS,
	CRYPTO,
	ETHERNET,
	DISPLEY,
	RESET_PLIS,
	SP_PLIS,
	PLIS_SI,
	SATA_SI
	};
	*/
    switch (Tip_si_alp)
    {
	  //Тесты СИ АЛП:
      case TIP_SI:
	  {


	    switch (Num_si_alp)
	    {
	      case RIK:
		  {
			//				val_1=0 - постояннй меандр
			si_rik_read(par->channel, (uint8)par->val_1, (uint8)par->val_2, par->time_ms);
		  }
	      break;

	      case MCBSP:
		  {	
			//				val_1=0 - постояннй меандр
		  	si_mcbsp(par->channel, (uint8)par->val_1, (uint8)par->val_2, par->time_ms);
		  }
	      break;
	      case ETHERNET:
		  {
			#ifdef TPO5
			Send_cmd_comm(1,STOP_TX);
			#endif

			//				val_1=0 - постояннй меандр
			send_comm_start_sialp(par);
			while(1);

		  }
	      break;
	      case PLIS_SI:
		  {
			//				val_1 - команда плисене
			send_main_start_sialp(par);
			while(1);

		  }
	      break;
	      case SATA_SI:
		  {
		  }
	      break;
		}

	  }
      break;

      case TIP_ALP:
	  {
	    switch (Num_si_alp)
	    {
	      case RIK:
		  {
			//				val_1=0 - постояннй меандр
			si_rik_read(par->channel, (uint8)par->val_1, (uint8)par->val_2, par->time_ms);
		  }
	      break;

	      case PP_PLIS:
		  {
			//				val_1=0 - постояннй меандр
			alp_pp_plis(par->channel, (uint8)par->val_1, (uint8)par->val_2, par->time_ms);
		  }
	      break;

	      case MCBSP:
		  {	
			//				val_1=0 - постояннй меандр
		  	si_mcbsp(par->channel, (uint8)par->val_1, (uint8)par->val_2, par->time_ms);
		  }
	      break;
	      case ETHERNET:
		  {
			#ifdef TPO5
			Send_cmd_comm(1,STOP_TX);
			#endif

			//				val_1=0 - постояннй меандр
			send_comm_start_sialp(par);
			while(1);

		  }
	      break;
	      case PLIS_SI:
		  {
			//				val_1 - команда плисене
			send_main_start_sialp(par);
			while(1);

		  }
	      break;
	      case SATA_SI:
		  {
		  }
	      break;
		}
	  }
      break;


      case LOAD_PO:
	  {
	    switch (Num_si_alp)
	    {
	      case LOAD_PO_PP:
		  {
			res = Load_po_pp();
			led_blik_err(res);
			
		  }
	      break;

	      case LOAD_PO_MAIN:
		  {
			res = Load_po_main();
			led_blik_err(res);
		  }
	      break;

	      case LOAD_PO_COMM:
		  {
			res = Load_po_comm();
			led_blik_err(res);
		   
		  }
	      break;

	      case LOAD_PO_ALL:
		  {
			res = Load_po_pp();
			res = Load_po_main();
			res = Load_po_comm();
			led_blik_err(res);
		  }
	      break;

	      case LOAD_PO_PLIS_SI:
		  {
			res = Load_plis_sialp();
			led_blik_err(res);
		  }
	      break;

		}
	  }

      default:
      {
		res=0;

      };

	}
}

/**************************************************************************************************\
*       
\***sss********************************************************************************************/
void run_menu()
{

	struct kdg_sialp kdg = {0,0,10,0,0,0};

	//  cs_menu   si_alp;
	/*
	  menu_tpo = new cs_menu;
	  if(menu_tpo == NULL)
	  {
	  while(1);
	  }
	*/

	  cs_menu                       menu_tpo;
	  cs_menu*  					tmp_menu_tpo[5];

	  uint32                          exit;
	  uint32                          pid;
	  uint32                          file_usb;
	  s_usb_attach_func               ubs_event;
	  s_prc_attr                      prc_attr;
	  s_usb_attach_func_prc_user_arg  arg_usb_prc;
	  s_print_time_prc_arg            arg_time_prc;

	  uint32 usb_n[3] = {1,2,3};
	  uint32 num_led[2] = {0,1};
	  uint32 cilk_test[3] = {TWO_CH, FIRST_CH, SECOND_CH};


  //char name[20];
  //Регистрация семафора:
  sem_disp = sem_alloc(1,NULL);      
  if(sem_disp != RES_VOID)
  {
    //Создание процесса вывода системного времени:
    memset(&prc_attr, 0x0, sizeof(s_prc_attr));
    prc_attr.exit_vector = NULL;
    prc_attr.stack = 1024;
    exit = 0;
    arg_time_prc.exit = &exit;
    arg_time_prc.sem = sem_disp;
    pid = prc_create((int(*)(void*))((uint32)print_time_prc), &arg_time_prc, sizeof(s_print_time_prc_arg), &prc_attr);
    //Добавление callback функции при подключении msd:
    arg_usb_prc.sem = sem_disp;
    ubs_event.func = usb_device_attach;
    ubs_event.data = &arg_usb_prc;
    ubs_event.size = sizeof(s_usb_attach_func_prc_user_arg);
    file_usb = drv_mkd("/dev/usb");
    drv_ioctl(file_usb, USB_DEVICE_ATTACH, &ubs_event);
  }

	arg_exit_tpo exit_tpo;

	exit_tpo.exit = &exit;
	exit_tpo.ubs_event = &ubs_event;
	exit_tpo.sem = sem_disp;
	exit_tpo.pid = pid;
	exit_tpo.file_usb = file_usb;
	exit_tpo.menu = &menu_tpo;

tmp_menu_tpo[0] = menu_tpo.create(NULL, NULL, "Тесты");
{
	tmp_menu_tpo[1] = tmp_menu_tpo[0]->create(NULL, NULL, "Циклические тесты");
	{
	  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(Cikl_tests, &cilk_test[0], "Результаты 2-х каналов");
	  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(Cikl_tests, &cilk_test[1], "Результаты 0-канала");
	  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(Cikl_tests, &cilk_test[2], "Результаты 1-канала");
	}
	tmp_menu_tpo[1] = tmp_menu_tpo[0]->create(Kb_and_Displ, NULL, "Клавиатура и дисплей");

#ifdef TPO5
	tmp_menu_tpo[1] = tmp_menu_tpo[0]->create(NULL, NULL, "Тесты платы ПВ-040");
#else
	tmp_menu_tpo[1] = tmp_menu_tpo[0]->create(NULL, NULL, "Тесты платы ПВ-044");
#endif
	{
	  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(Tst_SDRAM_full, NULL,"Тест ОЗУ");
	  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(NULL, NULL, "Тест USB");
		{
		  	tmp_menu_tpo[3] = tmp_menu_tpo[2]->create(NULL, NULL, "Файловый тест");
			{
			  	tmp_menu_tpo[4] = tmp_menu_tpo[3]->create(Tst_USB_file, &usb_n[0], "USB1");
			  	tmp_menu_tpo[4] = tmp_menu_tpo[3]->create(Tst_USB_file, &usb_n[1], "USB2");
			}
		  	tmp_menu_tpo[3] = tmp_menu_tpo[2]->create(NULL, NULL, "Тест скорости");
			{
			  	tmp_menu_tpo[4] = tmp_menu_tpo[3]->create(inmenu_usb_fat_test, &usb_n[0], "USB1");
		  		tmp_menu_tpo[4] = tmp_menu_tpo[3]->create(inmenu_usb_fat_test, &usb_n[1], "USB2");
			}
		  	tmp_menu_tpo[3] = tmp_menu_tpo[2]->create(NULL, NULL, "Информация о носителе");
			{
			  	tmp_menu_tpo[4] = tmp_menu_tpo[3]->create(F_AboutUSB, &usb_n[0], "USB1");
		  		tmp_menu_tpo[4] = tmp_menu_tpo[3]->create(F_AboutUSB, &usb_n[1], "USB2");
			}

// Сохранение ГСЧ
		  	tmp_menu_tpo[3] = tmp_menu_tpo[2]->create(GSCh_USB_file, NULL, "ГСЧ -> usb flash");
//
		}
	  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(inmenu_set_time, NULL, "Тест часов по питанию");
	  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(NULL, NULL, "Тест светодиодов");
		{
#ifdef TPO5
		  	tmp_menu_tpo[3] = tmp_menu_tpo[2]->create(Tst_led, &num_led[0], "Абонент");
		  	tmp_menu_tpo[3] = tmp_menu_tpo[2]->create(Tst_led, &num_led[1], "Канал");
#else
		  	tmp_menu_tpo[3] = tmp_menu_tpo[2]->create(Tst_led, &num_led[0], "Статус");
#endif
		}
	}

#ifdef TPO5
	tmp_menu_tpo[1] = tmp_menu_tpo[0]->create(NULL, NULL, "Тесты платы СВ-039");
#else
	tmp_menu_tpo[1] = tmp_menu_tpo[0]->create(NULL, NULL, "Тесты платы СВ-043");
#endif
	{
	  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(NULL, NULL,"Тест ОЗУ");
		{
		  	tmp_menu_tpo[3] = tmp_menu_tpo[2]->create(Tst_SDRAM_full_SV, &cilk_test[1], "0 канал");
		  	tmp_menu_tpo[3] = tmp_menu_tpo[2]->create(Tst_SDRAM_full_SV, &cilk_test[2], "1 канал");
		}

	  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(NULL, NULL, "Тест USB");
		{
	  		tmp_menu_tpo[3] = tmp_menu_tpo[2]->create(NULL, NULL, "Информация о USB носителе");
			{
		  		tmp_menu_tpo[4] = tmp_menu_tpo[3]->create(F_AboutUSB_CP, &usb_n[0], "USB 0 канала");
	  			tmp_menu_tpo[4] = tmp_menu_tpo[3]->create(F_AboutUSB_CP, &usb_n[1], "USB 1 канала");
			}

		}

	  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(NULL, NULL,"Тест ЭОЗУ");
		{
		  	tmp_menu_tpo[3] = tmp_menu_tpo[2]->create(Tst_NVRAM_full_SV, &cilk_test[1], "0 канал");
		  	tmp_menu_tpo[3] = tmp_menu_tpo[2]->create(Tst_NVRAM_full_SV, &cilk_test[2], "1 канал");
		}


//	  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(Tst_ROM_SV, NULL,"Тест ПЗУ");
//	  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(Tst_MOVE, NULL,"Тест MOVE");


#ifndef TPO7
	  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(NULL, NULL,"Тест ДОЗУ");
		{
		  	tmp_menu_tpo[3] = tmp_menu_tpo[2]->create(NULL, NULL, "ЦП - СП");
			{
				if((MIN_NUMBER_COMM < 1)&(NUMBER_COMM_DSP > 0))
			  	tmp_menu_tpo[4] = tmp_menu_tpo[3]->create(TestDARAM_PrintRes, &pid_comm[0], "ЦП - СП0");
				if((MIN_NUMBER_COMM < 2)&(NUMBER_COMM_DSP > 1))
			  	tmp_menu_tpo[4] = tmp_menu_tpo[3]->create(TestDARAM_PrintRes, &pid_comm[1], "ЦП - СП1");
				if((MIN_NUMBER_COMM < 3)&(NUMBER_COMM_DSP > 2))
			  		tmp_menu_tpo[4] = tmp_menu_tpo[3]->create(TestDARAM_PrintRes, &pid_comm[2], "ЦП - СП2");
				if((MIN_NUMBER_COMM < 4)&(NUMBER_COMM_DSP > 3))
			  		tmp_menu_tpo[4] = tmp_menu_tpo[3]->create(TestDARAM_PrintRes, &pid_comm[3], "ЦП - СП3");
			}
		  	tmp_menu_tpo[3] = tmp_menu_tpo[2]->create(NULL, NULL, "СП - Ш");
			{
				if((MIN_NUMBER_COMM < 1)&(NUMBER_COMM_DSP > 0))
			  	tmp_menu_tpo[4] = tmp_menu_tpo[3]->create(TestDARAM_MOVE_PrintRes, &pid_comm[0], "СП0 - Ш");
				if((MIN_NUMBER_COMM < 2)&(NUMBER_COMM_DSP > 1))
			  	tmp_menu_tpo[4] = tmp_menu_tpo[3]->create(TestDARAM_MOVE_PrintRes, &pid_comm[1], "СП1 - Ш");
				if((MIN_NUMBER_COMM < 3)&(NUMBER_COMM_DSP > 2))
			  		tmp_menu_tpo[4] = tmp_menu_tpo[3]->create(TestDARAM_MOVE_PrintRes, &pid_comm[2], "СП2 - Ш");
				if((MIN_NUMBER_COMM < 4)&(NUMBER_COMM_DSP > 3))
			  		tmp_menu_tpo[4] = tmp_menu_tpo[3]->create(TestDARAM_MOVE_PrintRes, &pid_comm[3], "СП3 - Ш");

			}
#ifdef TPO5

		  	tmp_menu_tpo[3] = tmp_menu_tpo[2]->create(NULL, NULL, "цикл СП - Ш");
			{
			  	tmp_menu_tpo[4] = tmp_menu_tpo[3]->create(TestDARAM_MOVE_CiklPrintRes, &pid_comm[0], "цикл СП0 - Ш");
			  	tmp_menu_tpo[4] = tmp_menu_tpo[3]->create(TestDARAM_MOVE_CiklPrintRes, &pid_comm[1], "цикл СП1 - Ш");
			}

		  	tmp_menu_tpo[3] = tmp_menu_tpo[2]->create(TestDARAM_Nagruz, NULL, "Нагрузочный тест");
#endif
		}
#endif

	  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(NULL, NULL,"Тест СК");
		{
			if((MIN_NUMBER_COMM < 1)&(NUMBER_COMM_DSP > 0))
		  	tmp_menu_tpo[3] = tmp_menu_tpo[2]->create(F_TestSkEth, &pid_comm[0], "ETH0");
			if((MIN_NUMBER_COMM < 2)&(NUMBER_COMM_DSP > 1))
		  	tmp_menu_tpo[3] = tmp_menu_tpo[2]->create(F_TestSkEth, &pid_comm[1], "ETH1");
			if((MIN_NUMBER_COMM < 3)&(NUMBER_COMM_DSP > 2))
			  	tmp_menu_tpo[3] = tmp_menu_tpo[2]->create(F_TestSkEth, &pid_comm[2], "ETH2");
			if((MIN_NUMBER_COMM < 4)&(NUMBER_COMM_DSP > 3))
			  	tmp_menu_tpo[3] = tmp_menu_tpo[2]->create(F_TestSkEth, &pid_comm[3], "ETH3");
		}
	  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(NULL, NULL,"Тест АУПИ");
		{
		  	tmp_menu_tpo[3] = tmp_menu_tpo[2]->create(F_CrServiceTest, NULL,"Тесты служебных режимов");
		  	tmp_menu_tpo[3] = tmp_menu_tpo[2]->create(NULL, NULL,"Тесты канальных режимов");
			{
#ifdef TPO5
			  	tmp_menu_tpo[4] = tmp_menu_tpo[3]->create(F_CrChannelCfgEth0_1, NULL, "СП0 -> СП1");
			  	tmp_menu_tpo[4] = tmp_menu_tpo[3]->create(F_CrChannelCfgEth1_0, NULL, "СП1 -> СП0");
//#endif
#else
			  	tmp_menu_tpo[4] = tmp_menu_tpo[3]->create(F_CrChannelCfgEth0_1, NULL, "СП0 -> СП1");
			  	tmp_menu_tpo[4] = tmp_menu_tpo[3]->create(F_CrChannelCfgEth0_2, NULL, "СП0 -> СП2");
#endif
			}
		}
#ifdef TPO5

	  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(NULL, NULL,"Тесты для C8051F902");
		{
		  	tmp_menu_tpo[3] = tmp_menu_tpo[2]->create(Dnsd_crc_po, NULL,"Контр. сумма за ПО");
		  	tmp_menu_tpo[3] = tmp_menu_tpo[2]->create(Dnsd_rasshiren_test, &num_led[0],"Тест VD10");
		  	tmp_menu_tpo[3] = tmp_menu_tpo[2]->create(Dnsd_rasshiren_test, &num_led[1],"Тест VD11");
		  	tmp_menu_tpo[3] = tmp_menu_tpo[2]->create(NULL, NULL,"Дополнительные тесты");
		  	{
		  	
		  		tmp_menu_tpo[4] = tmp_menu_tpo[3]->create(ZavestiDNSD, NULL,"Записать С0");
		  		tmp_menu_tpo[4] = tmp_menu_tpo[3]->create(Prochitat, NULL,"Прочитать С0");
		  		tmp_menu_tpo[4] = tmp_menu_tpo[3]->create(Vkluchit_VD, &num_led[0],"Моргнуть VD10");
		  		tmp_menu_tpo[4] = tmp_menu_tpo[3]->create(Vkluchit_VD, &num_led[1],"Включить VD11");
		  		tmp_menu_tpo[4] = tmp_menu_tpo[3]->create(Vikluchit_VD, &num_led[1],"Выключить VD11");
		  		tmp_menu_tpo[4] = tmp_menu_tpo[3]->create(Osveschennost, NULL,"Освещенность датчика");//2b
		  		tmp_menu_tpo[4] = tmp_menu_tpo[3]->create(Magic_Number, NULL,"Magic number");//4b
			}
		}


#endif


	}
	/*
#ifdef TPO711B 
	tmp_menu_tpo[1] = tmp_menu_tpo[0]->create(NULL, NULL, "Тесты платы ПП-056");
	{
	  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(Tst_SDRAM_full_SV, NULL,"Целостность ПО ПП-056");
	  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(Tst_SDRAM_full_SV, NULL,"Чтение CD-ROM");
	  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(Tst_SDRAM_full_SV, NULL,"Запись/Чтение RAID");
	  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(Tst_SDRAM_full_SV, NULL,"Запись/Чтение USB 3");
	}
#endif
*/
/*
	tmp_menu_tpo[1] = tmp_menu_tpo[0]->create(NULL, NULL, "Тесты IPMP");
	{
	  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(Tst_ipmp_main, NULL,"ПП - ЦП");
	  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(Tst_ipmp_comm, NULL,"ПП - СП");
	}
*/
}
tmp_menu_tpo[0] = menu_tpo.create(NULL, NULL, "Настройка");
{
	for(int m = 0; m < maxN_AllTest; m++)
	{
		if(NASTROJKA[m]->startup == true)
		{
			tmp_menu_tpo[1] = tmp_menu_tpo[0]->create(Nastrojka,  NASTROJKA[m], (char*)(NameTests[m] + 3));//номер здеся лишний поэтому +3
		}
	}
}
tmp_menu_tpo[0] = menu_tpo.create(NULL, NULL, "Тесты СИ АЛП");
{
  tmp_menu_tpo[1] = tmp_menu_tpo[0]->create(NULL, &kdg, "Тесты СИ");
  {
  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(SI_RIK, NULL,		"Чтение инф с РИК     ");
  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(SI_MCBSP, NULL,	"Обмен инф ПП с ЦП    ");
//  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(SI_CP_PLIS, NULL, "Передача инф в Шиф   ");
//  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(SI_CRYPTO, NULL,  "Шифрование           ");
//  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(SI_EXT_RAM, NULL,	    "Обмен инф с внешн ОЗУ");
//  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(SI_INT_RAM, &usb_n[0],"Обм инф с внутр ОЗУ 1");
//  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(SI_INT_RAM, &usb_n[1],"Обм инф с внутр ОЗУ 2");
//  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(SI_INT_RAM, &usb_n[2],"Обм инф с внутр ОЗУ 3");
 	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(SI_ETH, NULL,		"Оптический модуль    ");
//  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(SI_DISPL, &exit,	"Дисплей              ");
  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(SI_PLIS, NULL,	"ПЛИС                 ");
  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(SI_SATA, NULL,	"САТА                 ");
  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(SI_USB3, NULL,	"USB3                 ");
 
  }
  tmp_menu_tpo[1] = tmp_menu_tpo[0]->create(NULL, &kdg, "Тесты АЛП");
  {
  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(ALP_RIK, NULL,	"Обмен инф с РИК      ");
  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(ALP_PP_PLIS, NULL,"Обмен инф ПП с ПЛИС  ");
  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(ALP_MCBSP, NULL,	"Обмен инф ПП с ЦП    ");
  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(ALP_CP_PLIS, NULL,"Передача инф в Шиф   ");
  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(ALP_CRYPT, NULL,	"Шифрование инф в ПЛИС");
  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(ALP_EXT_RAM, NULL,"Обмен инф с внешн ОЗУ");
  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(ALP_INT_RAM, &usb_n[0],"Обм инф с внутр ОЗУ 1");
  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(ALP_INT_RAM, &usb_n[1],"Обм инф с внутр ОЗУ 2");
  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(ALP_INT_RAM, &usb_n[2],"Обм инф с внутр ОЗУ 3");
  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(ALP_ETHERNET, NULL,"Оптический модуль");
  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(ALP_SP_PLIS, NULL,"Перед инф из СП в Шиф");
  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(ALP_DISPL,  &exit,"Дисплей              ");
  	tmp_menu_tpo[2] = tmp_menu_tpo[1]->create(ALP_PLIS, NULL,	"ПЛИС                 ");

  }
}

	//tmp_menu_tpo[0] = menu_tpo->create(NULL, NULL, "Сохранить отчет на USB");
	tmp_menu_tpo[0] = menu_tpo.create(Exit_tpo, &exit_tpo, "Выход в СИОС");

	#ifdef TPO5
	menu_tpo.hidden(tpo_run_inside_menu, &exit_tpo);
	#endif

	mun:
	menu_tpo.run();
	goto mun;
}



#ifdef TPO5
/**************************************************************************************************\
*       
\***sss********************************************************************************************/
void tpo_run_inside_menu(cs_menu* node, bool present, void* arg)
{
//  uint32 usb_n[3] = {1,2,3};

  if(present == false)
  {
    cs_menu* temp_node[2];
    node->temp = node->create(NULL, NULL, "Дополнительно");
    {
      temp_node[0] = node->temp->create(NULL, NULL, "Загрузка ПО");
      {
//         = ->create(NULL, NULL, "Загрузка ЗОС РВ");
	  	temp_node[1] = temp_node[0]->create(F_load_lif, arg, "USB2");
//  		temp_node[1] = temp_node[0]->create(F_load_lif, &usb_n[1], "USB2");
      }

    }
  }
  else
  {
    node->remove(node->temp);
  }
}
#endif


/**************************************************************************************************\
*       
\***sss********************************************************************************************/
void Exit_tpo(cs_menu* m, void* arg)
{

	uint16 key=0;
	arg_exit_tpo* exit_tpo = (arg_exit_tpo*)arg;

	clrscr();
	put_str_center(4, "Перейти в CИОС?");
	put_str_center(6, "<ENTER> - Да, <ESC> - Нет");  

	while(true)
	{
   	  key = getch();
	  if(key == KEY_ENTER) break;
	   else
	   if(key == KEY_ESC) return;
	    else continue;
	}

	if(D)
	{
		for(int i = MIN_NUMBER_COMM; i < NUMBER_COMM_DSP; i++)
		Send_cmd_comm(i, EXIT_TPO);

		Send_cmd_main(EXIT_TPO);
	}


	if(exit_tpo->sem != RES_VOID)
	{
	//Удаление callback функции при подключении msd:
	  exit_tpo->ubs_event->func = NULL;
	  drv_ioctl(exit_tpo->file_usb, USB_DEVICE_ATTACH, exit_tpo->ubs_event);
	  if(exit_tpo->pid > 0x0)
	  {
	    *(exit_tpo->exit) = 1;
	    prc_join(exit_tpo->pid);
	  }  
	  drv_rmd(exit_tpo->file_usb);
	  sem_free(exit_tpo->sem);
	}

	load_lif(NULL);

	#ifdef TPO5
	uint32 file = drv_mkd("/vfat/");
	drv_ioctl(file, FSI_RESET, NULL);
	////
	drv_rmd(file);
	////
	#endif


	con_clrscr(USER_CON);
	con_clrscr(SYS_CON);
	con_deinit();

	msg_close();
	delete(menu_tpo);
	//exit_tpo->menu->~cs_menu();
	//////
	sleep_m(1500);
	sleep_m(1500);
	sleep_m(1500);
	//////
	prc_exit();
	while(1);

}




/**************************************************************************************************\
*  Вывода системного времени     
\***sss********************************************************************************************/
int print_time_prc(s_print_time_prc_arg* arg)
{
  int32   dot;
  tm      time;
  tm*     addr_time;
  time_t  utime;
  char    strdot[16];
  dot = 0;
  while(*arg->exit == 0)
  {
    utime = time_s();
    addr_time = localtime_r( &utime, &time);
    switch(dot)
    {
      case 0: strcpy(strdot, STR_CHAR_BIG_DOT" "STR_CHAR_SMALL_DOT" "STR_CHAR_SMALL_DOT); break;
      case 1: strcpy(strdot, STR_CHAR_SMALL_DOT" "STR_CHAR_BIG_DOT" "STR_CHAR_SMALL_DOT); break;
      case 2: strcpy(strdot, STR_CHAR_SMALL_DOT" "STR_CHAR_SMALL_DOT" "STR_CHAR_BIG_DOT); break;
    }
    if(dot < 2) dot++;
    else dot = 0;

    sem_lock(arg->sem, SEM_INFINITY);
    //con_gotoxy(SYS_CON, 3, 1);
    //con_putstr(SYS_CON, ATTR_REVERSE, strdot);
    if(addr_time != NULL)
    {
      con_gotoxy(SYS_CON, 9, 1);
      con_cprintf(SYS_CON, "%2.2d ", time.tm_mday);
      switch(time.tm_mon+1)
      {
        case  1: con_putstr(SYS_CON, "янв"); break;     
        case  2: con_putstr(SYS_CON, "фев"); break;
        case  3: con_putstr(SYS_CON, "мар"); break;
        case  4: con_putstr(SYS_CON, "апр"); break;
        case  5: con_putstr(SYS_CON, "май"); break;
        case  6: con_putstr(SYS_CON, "ин"); break;
        case  7: con_putstr(SYS_CON, "ил"); break;
        case  8: con_putstr(SYS_CON, "авг"); break;
        case  9: con_putstr(SYS_CON, "сен"); break;
        case 10: con_putstr(SYS_CON, "окт"); break;
        case 11: con_putstr(SYS_CON, "ноя"); break;
        case 12: con_putstr(SYS_CON, "дек"); break;
      }
      con_cprintf(SYS_CON, " %4.4d %2.2d:%2.2d:%2.2d ", time.tm_year+1900, time.tm_hour, time.tm_min, time.tm_sec);
    }
    sem_unlock(arg->sem);

    sleep_m(500);
  }
  return 0;
}
/**************************************************************************************************\
*  Функция обработки события при подключении USB устройства     
\***sss********************************************************************************************/
int usb_device_attach(s_usb_attach_func_arg* arg)
{

  s_usb_attach_func_prc_user_arg* user = (s_usb_attach_func_prc_user_arg*)(&((uint8*)arg)[sizeof(s_usb_attach_func_arg)]);
  if(arg->interface_class != USB_DEVICE_CLASS_STORAGE) return 0;
  char up_line[31], down_line[31], text_line[31];
  //Подготовка верхней строчки:
  up_line[0] = CHAR_LEFT_UP_CORNER;
  memset(&up_line[1], CHAR_UP_BORDER, 28);
  up_line[29] = CHAR_RIGHT_UP_CORNER;
  up_line[30] = 0x00;
  //Подготовка нижней строчки:  
  down_line[0] = CHAR_LEFT_DOWN_CORNER;
  memset(&down_line[1], CHAR_DOWN_BORDER, 28);
  down_line[29] = CHAR_RIGHT_DOWN_CORNER;
  down_line[30] = 0x00;
  //Подготовка текстовой строчки:
  text_line[0] = CHAR_LEFT_BORDER;
  memset(&text_line[1], ' ', 28);
  text_line[29] = CHAR_RIGHT_BORDER;
  text_line[30] = 0x00;
  sem_lock(user->sem, SEM_INFINITY);
  if(arg->connect_event)
  {
    uint32 file_msd = drv_mkd(arg->drv_path);
    if(file_msd == RES_VOID)
    {
      sem_unlock(user->sem);
      return -1;
    }
    char flash_size[28];
    char num_size[16];
    s_msd_capacity  capacity;
    s_msd_vendor    vendor;
    drv_ioctl(file_msd, MSD_VENDOR, &vendor);
    drv_ioctl(file_msd, MSD_CAPACITY, &capacity);

    //Вывод "Обнаружено USB устройство":
    con_gotoxy(SYS_CON, 0, 13);
    con_putstr(SYS_CON, up_line);
    
    con_gotoxy(SYS_CON, 0, 14);
    memcpy(&text_line[1], _str__usb_device_detect, strlen(_str__usb_device_detect));
    con_putstr(SYS_CON, text_line);
    memset(&text_line[1], ' ', 28);
    
    con_gotoxy(SYS_CON, 0, 15);
    con_putstr(SYS_CON, down_line);
    sleep_m(1000);
    con_clrbar(SYS_CON,13,30*3);

    //Вывод производителя:
    con_gotoxy(SYS_CON, 0, 12);
    con_putstr(SYS_CON, up_line);
    
    con_gotoxy(SYS_CON, 0, 13);
    memcpy(&text_line[1], vendor.vendor_identification, strlen(vendor.vendor_identification));
    con_putstr(SYS_CON, text_line);
    memset(&text_line[1], ' ', 28);
    con_gotoxy(SYS_CON, 0, 14);
    memcpy(&text_line[1], vendor.product_identification, strlen(vendor.product_identification));
    con_putstr(SYS_CON, text_line);
    memset(&text_line[1], ' ', 28);

    con_gotoxy(SYS_CON, 0, 15);
    con_putstr(SYS_CON, down_line);
    sleep_m(1000);
    con_clrbar(SYS_CON,12,30*4);

    //Вывод объема:
    con_gotoxy(SYS_CON, 0, 13);
    con_putstr(SYS_CON, up_line);
    
    con_gotoxy(SYS_CON, 0, 14);
    strcpy(flash_size, "Объем ");
    itoa(_mem8(&capacity.flash_capacity)/(1024*1024), num_size);
    strcat(flash_size, num_size);
    strcat(flash_size, "МБ");   
    memcpy(&text_line[1], flash_size, strlen(flash_size));
    con_putstr(SYS_CON, text_line);
    memset(&text_line[1], ' ', 28);
    
    con_gotoxy(SYS_CON, 0, 15);
    con_putstr(SYS_CON, down_line);
    sleep_m(1000);
    con_clrbar(SYS_CON,13,30*3);

    //Вывод "Устройство готово к работе":   
    con_gotoxy(SYS_CON, 0, 13);
    con_putstr(SYS_CON, up_line);
    
    con_gotoxy(SYS_CON, 0, 14);
    memcpy(&text_line[1], _str__usb_device_ready, strlen(_str__usb_device_ready));
    con_putstr(SYS_CON, text_line);
    memset(&text_line[1], ' ', 28);
    
    con_gotoxy(SYS_CON, 0, 15);
    con_putstr(SYS_CON, down_line);
    sleep_m(1000);
    con_clrbar(SYS_CON,13,30*3);
    drv_rmd(file_msd);
  }
  else
  {
    //Вывод "USB устройство отключенно":
    con_gotoxy(SYS_CON, 0, 13);
    con_putstr(SYS_CON, up_line);
    
    con_gotoxy(SYS_CON, 0, 14);
    memcpy(&text_line[1], _str__usb_device_remove, strlen(_str__usb_device_remove));
    con_putstr(SYS_CON, text_line);
    memset(&text_line[1], ' ', 28);
    
    con_gotoxy(SYS_CON, 0, 15);
    con_putstr(SYS_CON, down_line);
    sleep_m(1000);
    con_clrbar(SYS_CON,13,30*3);
  }
  sem_unlock(user->sem);
  return 0;


/*

  s_usb_attach_func_prc_user_arg* user = (s_usb_attach_func_prc_user_arg*)arg->data;
  if(arg->interface_class != USB_DEVICE_CLASS_STORAGE) return 0;
  char up_line[31], down_line[31], text_line[31];
  //Подготовка верхней строчки:
  up_line[0] = CHAR_LEFT_UP_CORNER;
  memset(&up_line[1], CHAR_UP_BORDER, 28);
  up_line[29] = CHAR_RIGHT_UP_CORNER;
  up_line[30] = 0x00;
  //Подготовка нижней строчки:  
  down_line[0] = CHAR_LEFT_DOWN_CORNER;
  memset(&down_line[1], CHAR_DOWN_BORDER, 28);
  down_line[29] = CHAR_RIGHT_DOWN_CORNER;
  down_line[30] = 0x00;
  //Подготовка текстовой строчки:
  text_line[0] = CHAR_LEFT_BORDER;
  memset(&text_line[1], ' ', 28);
  text_line[29] = CHAR_RIGHT_BORDER;
  text_line[30] = 0x00;
  sem_lock(user->sem, SEM_INFINITY);
  if(arg->connect_event)
  {
    uint32 file_msd = drv_mkd(arg->drv_path);
    if(file_msd == RES_VOID) return -1;
    char flash_size[28];
    char num_size[16];
    s_msd_capacity  capacity;
    s_msd_vendor    vendor;
    drv_ioctl(file_msd, MSD_VENDOR, &vendor);
    drv_ioctl(file_msd, MSD_CAPACITY, &capacity);

    //Вывод "Обнаружено USB устройство":
    con_gotoxy(SYS_CON, 0, 13);
    con_putstr(SYS_CON, up_line);
    
    con_gotoxy(SYS_CON, 0, 14);
    memcpy(&text_line[1], _str__usb_device_detect, strlen(_str__usb_device_detect));
    con_putstr(SYS_CON, text_line);
    memset(&text_line[1], ' ', 28);
    
    con_gotoxy(SYS_CON, 0, 15);
    con_putstr(SYS_CON, down_line);
    sleep_m(1000);
    con_clrbar(SYS_CON,13,30*3);

    //Вывод производителя:
    con_gotoxy(SYS_CON, 0, 12);
    con_putstr(SYS_CON, up_line);
    
    con_gotoxy(SYS_CON, 0, 13);
    memcpy(&text_line[1], vendor.vendor_identification, strlen(vendor.vendor_identification));
    con_putstr(SYS_CON, text_line);
    memset(&text_line[1], ' ', 28);
    con_gotoxy(SYS_CON, 0, 14);
    memcpy(&text_line[1], vendor.product_identification, strlen(vendor.product_identification));
    con_putstr(SYS_CON, text_line);
    memset(&text_line[1], ' ', 28);

    con_gotoxy(SYS_CON, 0, 15);
    con_putstr(SYS_CON, down_line);
    sleep_m(1000);
    con_clrbar(SYS_CON,12,30*4);

    //Вывод объема:
    con_gotoxy(SYS_CON, 0, 13);
    con_putstr(SYS_CON, up_line);
    
    con_gotoxy(SYS_CON, 0, 14);
    strcpy(flash_size, "Объем ");
    itoa(_mem8(&capacity.flash_capacity)/(1024*1024), num_size);
    strcat(flash_size, num_size);
    strcat(flash_size, "МБ");   
    memcpy(&text_line[1], flash_size, strlen(flash_size));
    con_putstr(SYS_CON, text_line);
    memset(&text_line[1], ' ', 28);
    
    con_gotoxy(SYS_CON, 0, 15);
    con_putstr(SYS_CON, down_line);
    sleep_m(1000);
    con_clrbar(SYS_CON,13,30*3);

    //Вывод "Устройство готово к работе":   
    con_gotoxy(SYS_CON, 0, 13);
    con_putstr(SYS_CON, up_line);
    
    con_gotoxy(SYS_CON, 0, 14);
    memcpy(&text_line[1], _str__usb_device_ready, strlen(_str__usb_device_ready));
    con_putstr(SYS_CON, text_line);
    memset(&text_line[1], ' ', 28);
    
    con_gotoxy(SYS_CON, 0, 15);
    con_putstr(SYS_CON, down_line);
    sleep_m(1000);
    con_clrbar(SYS_CON,13,30*3);
    drv_rmd(file_msd);
  }
  else
  {
    //Вывод "USB устройство отключенно":
    con_gotoxy(SYS_CON, 0, 13);
    con_putstr(SYS_CON, up_line);
    
    con_gotoxy(SYS_CON, 0, 14);
    memcpy(&text_line[1], _str__usb_device_remove, strlen(_str__usb_device_remove));
    con_putstr(SYS_CON, text_line);
    memset(&text_line[1], ' ', 28);
    
    con_gotoxy(SYS_CON, 0, 15);
    con_putstr(SYS_CON, down_line);
    sleep_m(1000);
    con_clrbar(SYS_CON,13,30*3);
  }
  sem_unlock(user->sem);
  return 0;
*/
}

//-------------------------------------------------------------------------------------------------
//пака пустая
void F_TestProgress(int weight)
{

}
/*
//-------------------------------------------------------------------------------------------------
int32 receive_msg_comm(void* recev, uint32* n_comm, int32 length, uint32 ms)
{
  s_message*  		msg_desc;
  int32 error;

  error = msg_recv( &msg_desc, ms);


	for(int y = MIN_NUMBER_COMM; y < NUMBER_COMM_DSP; y++)
	{
	if(pid_comm[y].pid == msg_desc->from)
	*n_comm = y;
	}

  if( (error != OSE_OK)||(msg_desc == NULL) )
  {
	print_err("IFACE", COMM_TIME_OUT + *n_comm);
    return MSG_ER_TIME_OUT;
  }
  if(msg_desc->length != length)
  {
    msg_free(msg_desc);
	print_err("IFACE", COMM_ERR_MSG + *n_comm)
    return MSG_ER_SYNC;
  }


  memcpy(recev, msg_desc->data, length);
  msg_free(msg_desc);
  return TPO_OK;

}
*/




/**************************************************************************************************\
*       
\***sss********************************************************************************************/
void F_StartTest(uint32 count, uint32* result)
{
    uint16 i = 0;
    uint32 maska = 0;
    int res;

    uint32 ResAllTes = 0;

/*
//для бегущих звездочек, может не понадобится
    clrbar(15, 1); gotoxy(0, 15);

    progress_div = 64;
    progress_count = 0;
    progress_on = 1;
*/

	i = 0;
    while(TESTS_PP[i] != NULL)
    {
   		if(TESTS_PP[i]->startup)
		{
			if(i==8|i==9|i==10|i==11)// тесты РИК и USB проводятся первые 10 циклов , а потом каждый 8
			{
				if((FlagRikUSBTest==2)&&((count<10)||(count&0x7)==0))
		        	res = TESTS_PP[i]->f_test();
				else
					res = 0;
			}
			else 
			{
#ifdef TPO5
//debug
//			    if((i<12)&(i>12))// тесты Пока уберем из циклов.
//				res = 0;
//debug
//						// исключил в tests_name.h
			    if((i==4) | (i==13))// тесты датчиков вскрытия пока уберем из циклов.
					res = 0;
				else
					res = TESTS_PP[i]->f_test();
#else
			    if(i==4)// тесты датчиков вскрытия пока уберем из циклов.
					res = 0;
				else
				{
			     if(i>=14)// тесты датчиков вскрытия пока уберем из циклов.
					res = 0;
				 else
					res = TESTS_PP[i]->f_test();
				}
#endif
			}
		}
		else 
		res = 0;
        
        if (res != 0)
        {
            maska = 0x1;
            maska <<= (TESTS_PP[i]->N_test - 1);
            ResAllTes |= maska;
        }
        i++;
    }
memcpy(result, &ResAllTes, 4);
}


/**************************************************************************************************\
*       
\***sss********************************************************************************************/
void Bear_foot(int b)
{

	sem_lock(sem_disp, SEM_INFINITY);

	if(b&0x2)
	{
		if(b>2)
		{
		gotoxy(b-4,14);
		putch(BEAR_UP_DOBLEFOOT_1);
		putch(BEAR_UP_DOBLEFOOT_2);
		}
		if(b<30)
		{
		sleep_m(200);
		gotoxy(b,14);
		putch(BEAR_UP_FOREFOOT);
		}
	}
	else
	{
		if(b>2)
		{
		gotoxy(b-4,15);
		putch(BEAR_DOWN_DOBLEFOOT_1);
		putch(BEAR_DOWN_DOBLEFOOT_2);
		}

		if(b<30)
		{
		sleep_m(200);
		gotoxy(b,15);
		putch(BEAR_DOWN_FOREFOOT);
		}
	}
sem_unlock(sem_disp);
//int_enable(int_old);	
sleep_m(700);
}

 uint32 end_cikl;

/**************************************************************************************************\
*    // процесс следящей за наж клавишь во время циклич тестов   
\***sss********************************************************************************************/
 int kbd_str(void* arg) 
 {
	uint16 KEY = 0;
	int B = 0;

	T_clrbar(14);
	T_clrbar(15);

	while(true)
	{
		if(B>32)
		{
		B=0;
		T_clrbar(14);
		T_clrbar(15);
		}

		Bear_foot(B);
		B=B+2;

		KEY = kb_hit();

		KEY &= 0xFF;
		switch(KEY)
		{
		case KEY_DOWN:
		case KEY_UP:
			KEY = getch();
			F_GetPageTablo(KEY); 
		    break;

		case KEY_ESC:
			KEY = getch();
			goto end_ciklich;

		case 0:
		    break;

		default:
		KEY = getch();
		prc_yield();
		}
	}//end while

	end_ciklich:
	T_clrbar(14);
	T_clrbar(15);
	end_cikl = 1;
	prc_exit();
	while(1);
 
 }

/**************************************************************************************************\
*   Циклические тесты    
\***sss********************************************************************************************/
void Cikl_tests(cs_menu* m, void* arg)
{

//	tm      time;
//	tm*     addr_time;
//	time_t  utime;
	uint32 otsvetka = *(uint32*)arg;

    uint16 KEY = 0;
    uint32 CountCicl = 0;

	uint16	CountStr = 0;

	Dnsd_enn = 0;
	FlagRikUSBTest = 2;
	N_page_tablo = 0;

	uint32 res = 0;

	uint32 ResAllTest_PP = 0;
	uint32 ResAllTest6416_0 = 0;



//--------- очистка таблицы результатов тестов
    memset(T_ErrTest, 0, (maxN_AllTest + 1) * sizeof(uint32));
    CountStr = MaxTable*MaxStr;		
	F_ClearPageTablo(CountStr);
//--------- очистка

    start("Циклические тесты");
#ifdef TPO5
		while(1)
		{	
			gotoxy(0,12);
			cprintf("Тест C8051F902?\n\n");
			cprintf("ENTER - Выполнять\nESC   - Пропускать");
			KEY=getch();
			if(KEY==KEY_ENTER||KEY==KEY_ESC)
			{
				if(KEY==KEY_ESC)Dnsd_enn = 0;
				if(KEY==KEY_ENTER)Dnsd_enn = 1;
				break;
			}
			else continue;
		}
		T_clrbar(12); T_clrbar(13);	T_clrbar(14); T_clrbar(15);
		KEY = 0;
#endif

		while(1)
		{	
			gotoxy(0,12);
#ifdef TPO_M711B
			cprintf("Тесты CD-ROM, РИК и USB?\n\n");
#else
			cprintf("Тесты РИК и USB?\n\n");
#endif
//			cprintf("Тесты РИК и USB?\n\n");
			cprintf("ENTER - Выполнять\nESC   - Пропускать");
			KEY=getch();
			if(KEY==KEY_ENTER||KEY==KEY_ESC)
			{
				if(KEY==KEY_ESC)FlagRikUSBTest = 1;
				if(KEY==KEY_ENTER)FlagRikUSBTest = 2;
				break;
			}
			else continue;
		}
		T_clrbar(12); T_clrbar(13);	T_clrbar(14); T_clrbar(15);
		KEY = 0;


        gotoxy(0, 12);
        cprintf("Соедините TX с RX всех\n              интерфейсов ETH\nENTER - ОК\nESC   - Выход"); 

        if(getch() == KEY_ENTER)
        {
        	if(FlagRikUSBTest == 2)
			{
	        	T_clrbar_D(12,4); gotoxy(0, 12);
	        	cprintf("Установите РИК в оба ридера\n\nENTER - ОК\nESC - Выход"); 
	        	if (getch() == KEY_ENTER)
	        	{
		        	T_clrbar_D(12,4); gotoxy(0, 12);
#ifdef TPO_M711B
	        		cprintf("Подключите ФЛЭШ к трем USB\nразьемам и вставте CD диск\nENTER - ОК\nESC   - Выход"); 
#else
	        		cprintf("Подключите ФЛЭШ к обоим USB\n                     разьемам\nENTER - ОК\nESC   - Выход"); 
#endif
	        		if(getch() != KEY_ENTER)
					return;
				}
				else
				return;
			}
		}
		else
		return;

	if(D)
	{
		Send_cmd_main(START_CIKL);

       	if(FlagRikUSBTest == 2)
		Send_cmd_main(2|Dnsd_enn);
		else
		Send_cmd_main(Dnsd_enn);

//		if(Dnsd_enn)
//		Send_cmd_main(1);
//		Send_cmd_main(0);
	}

//    utime = time_s();
//    addr_time = localtime_r( &utime, &time);
	syslog(100,"Старт циклические тесты");

	
	end_cikl = 0;
	//создание процесса следящего за нажат kbd во время циклич тестов
	s_prc_attr atr;
	memset( &atr, 0, sizeof(atr) );
	atr.stack = 4048;   
    prc_create( &kbd_str, NULL, 0, &atr );

		clrscr();
//надо чета добавить, а то пустой экран
        while(1)
        {
            CountCicl++;
            if (CountCicl == MaxCicle) CountCicl = 1;

//		    uint16 ch=0;
		    ResAllTest_PP = 0;
		    ResAllTest6416_0 = 0;
//		    ResAllTest6416_1 = 0;

//!!!!!!!!!!!!!!!!!
			F_StartTest(CountCicl, &ResAllTest_PP); //сами тесты на ПП....


//				if(ResAllTest_PP & 0xFFFFFFF9)
//				syslog(120," ResAllTest_PP = %d ", ResAllTest_PP);


				if(D)
				{
				esche_razok:
				sleep_m(1000);
					if(end_cikl)
					{
						Send_cmd_main(STOP_CIKL);

						res = Receve_Res_Cikl(&ResAllTest6416_0, otsvetka);
						if(res == CIKL)
						{

//						    utime = time_s();
//						    addr_time = localtime_r( &utime, &time);
							syslog(101,"Стоп циклические тесты. Пройденно %d циклов", CountCicl);
							PrintfResCiklTest(CountCicl, 1, ResAllTest_PP, ResAllTest6416_0);
							break;
						}
						else if(res == CIKL_NOT_READY) goto esche_razok;
					}
					else
					res = Receve_Res_Cikl(&ResAllTest6416_0, otsvetka);
					if(res == CIKL_NOT_READY) goto esche_razok;
				}
				else
				{
					if(end_cikl)
					{
					PrintfResCiklTest(CountCicl, 1, ResAllTest_PP, ResAllTest6416_0);
					break;
					}
				}
			PrintfResCiklTest(CountCicl, 0, ResAllTest_PP, ResAllTest6416_0);

       } 

//    }

	gotoxy(0, 14);
    cprintf("Для возврата в меню нажмите  \n<ENTER>.");
    do
    { 
	KEY = 0;
	KEY = getch();
		if(KEY!=0)
		F_GetPageTablo(KEY);

    } while(KEY != KEY_ENTER);    

    return;   
}



/**************************************************************************************************\
*       
\***sss********************************************************************************************/
void F_PrintMemTablo(uint16 t)
{
    uint16 s = 0;
    uint16 page_t = 0;

	sem_lock(sem_disp, SEM_INFINITY);
    for (s = 0; s < MaxStr; s++)
    {
//        gotoxy(0, StartStr + s);
		T_clrbar(StartStr + s);
        gotoxy(0, StartStr + s);
        cprintf("%s\n", &MemTablo[t][s][0]);
    }
	sem_unlock(sem_disp);

    for (s = 0; s < MaxTable; s++)
		if(MemTablo[s][0][0] != 0)
		page_t++;

	sem_lock(sem_disp, SEM_INFINITY);
	T_clrbar(StartStr - 1);
	if( page_t > 1 )
	{
	gotoxy(0,StartStr - 1);
    cprintf("Стр.%dиз%d Листать-<Вверх><Вниз>", t+1, page_t);
	set_text_attribute(0,StartStr - 1,30,ATTR_BLINK_REVERSE);
	}
	sem_unlock(sem_disp);

}

/**************************************************************************************************\
*       
\***sss********************************************************************************************/
void F_GetPageTablo(uint16 key)
{
        if((key == KEY_DOWN) && (N_page_tablo < (MaxTable - 1)) && (MemTablo[N_page_tablo+1][0][0] != 0))
        	N_page_tablo++;
        if((key == KEY_UP) && (N_page_tablo > 0)) N_page_tablo--;
        F_PrintMemTablo(N_page_tablo);

}


/**************************************************************************************************\
*       
\***sss********************************************************************************************/
void F_ClearPageTablo(uint16 CountStr)
{
uint16 s = 0, t = 0;

    while (CountStr != 0)
    {
        CountStr--;
        strcpy(&MemTablo[t][s][0], "");
        s++;
        if (s == MaxStr) {s = 0; t++;};
    }
}


/**************************************************************************************************\
*       
\***sss********************************************************************************************/
int PrintfResCiklTest(uint32 count, uint32 end,	uint32 ResAllTest_P, uint32 ResAllTest6416)
{
    uint16 i = 1, t = 0, s = 0, r = 0;
    uint32 maska = 0x1;
    uint16 CountStr = 0;
    char Stroka[MaxLen + 5]; 


//	int tyu[15];



//#ifdef DEBUG_VERBOSE
///    int newError[maxN_AllTest + 1];
//    memset(newError, 0, (maxN_AllTest + 1) * sizeof(int));
//#endif

    uint32 ResAllTest[2] = {ResAllTest_P,ResAllTest6416};

//    uint32 ResAllTest[2];
//	ResAllTest[0] = ResAllTest_P;
//	ResAllTest[1] = ResAllTest6416;
	
//	if(ResAllTest[0] & 0xFFFFFFF9)
//	 syslog(121," ResAllTest[0] = %d ", ResAllTest[0]);

    CountStr = MaxTable*MaxStr;		// очистка
	F_ClearPageTablo(CountStr);

//    clrscr();

	sem_lock(sem_disp, SEM_INFINITY);
	T_clrbar(StartStr - 2);

    gotoxy(0, StartStr - 2);
    cprintf("Циклов: %6.6d  ( ESC - Стоп )\n",count);
	sem_unlock(sem_disp);

        for (r = 0; r < 2; r++)
        {
            for (i = 0; i<32; i++)
            {
                if ((ResAllTest[r] & (maska<<i)) != 0)
				{
                    T_ErrTest[i + (minN_Tests_CP) * r]++;
				}
            }
        }

        for (i = 0, t = 0, s = 0; strcmp(NameTests[i], "") != 0; i++)
        {
            if (T_ErrTest[i] != 0)
            {

//                sprintf(Stroka, "%B", tyu);  //23+1+6=MaxLen

                sprintf(Stroka, "%-23.23s %6.6d", NameTests[i], T_ErrTest[i]);  //23+1+6=MaxLen
                          //поле 6.6lu для MaxCicle

                strcpy(&MemTablo[t][s][0], Stroka);
                CountStr++;
                s++;
                if (s == MaxStr) {s = 0; t++;}

				if(end)
				{

//!!!!!!!!!!!!!!!!!!!!!
//	memset(tyu, 1, sizeof(tyu));

//tyu[0]=0;
//tyu[1]=1;
//    sprintf(Stroka, "iface_int-%1d iface_drv-%2d comm0_int-%3d comm0_drv-%4d comm1_int-%d comm1_drv-%d iface_ready-%d comm0_ready-%d comm1_ready-%d ready-%d success-%d", tyu[0],tyu[0],tyu[0],tyu[0],tyu[0],tyu[0],tyu[0],tyu[0],tyu[0],tyu[1],tyu[1]); 
//    syslog(91,"%200s", Stroka);
//!!!!!!!!!!!!!!!!!!!!!

				syslog(102,"%30s", Stroka);
				}
            }
        }

        F_PrintMemTablo(N_page_tablo);

    return 1;
}   



/**************************************************************************************************\
*       
\***sss********************************************************************************************/
void Kb_and_Displ(cs_menu* m, void* arg)
{
	char temp_char;
    clrscr();
	gotoxy(0, 2);
	putstr("  Тест клавиатуры и дисплея  \n");
    putstr("<ESC> - Выход. Нажимайте...:\n");

	gotoxy(0, 4);

    cursor_enable();
	while(1)
	{
		switch(temp_char = getch())
		{
		case KEY_ENTER:
			putstr("<ENTER>");
			break;
		case KEY_LEFT:
			putstr("<ВЛЕВО>");
			break;
		case KEY_RIGHT:
			putstr("<ВПРАВО>");
			break;
		case KEY_UP:
			putstr("<ВВЕРХ>");
			break;
		case KEY_DOWN:
			putstr("<ВНИЗ>");
			break;
		case KEY_DEL:
			putstr("<DEL>");
			break;
		case KEY_SHIFT:
			putstr("<SHIFT>");
			break;
		case KEY_ESC:
		    cursor_disable();
			for(int z = 0; z < 16; z++)
			set_text_attribute(0,z,30,ATTR_BLINK_REVERSE);
			temp_char = getch(); 
			return;
		default:
			putch(temp_char);
		}
	}

}

/**************************************************************************************************\
*       
\***sss********************************************************************************************/
void Tst_led(cs_menu* m, void* arg)
{


	uint32 d;
	uint32 green = 0x0000ff00;
	uint32 red   = 0x00ff0000;
	uint32 orange= green | red;
	uint32 black = 0x00000000;
	uint32* n 	 = (uint32*)arg;
//	uint32 key	 = 0;

#ifdef TPO5
	if(n[0] == 0)
	{
	d = drv_mkd( "/dev/led/abonent" );
    start("Тест светодиода АБОНЕНТ");
	}
	if(n[0] == 1)
	{
	d = drv_mkd( "/dev/led/channel" );
    start("Тест светодиода КАНАЛ");
	}
#else
	if(n[0] == 0)
	{
	d = drv_mkd( "/dev/led/status" );
    start("Тест светодиода СТАТУС");
	}
#endif

//clrscr();

gotoxy(0, 4);
cprintf("Нажмите клавишу: \n"); 
cprintf("0. Зеленый \n"); 
cprintf("1. Красный \n"); 
cprintf("2. Оранжевый \n"); 
cprintf("3. Выключить \n"); 

gotoxy(0, 14);
cprintf("ESC - Выход"); 


		while(1)
		{
			switch(getch())
			{	

			case '0':
			drv_ioctl( d, LED_SETCOLOR, &green );
			break;

			case '1':
			drv_ioctl( d, LED_SETCOLOR, &red );
			break;

			case '2':
			drv_ioctl( d, LED_SETCOLOR, &orange );
			break;

			case '3':
			drv_ioctl( d, LED_SETCOLOR, &black );
			break;

			case KEY_ESC:
			goto led_end;
						
			}
		}

led_end:
drv_ioctl( d, LED_SETCOLOR, &black );
drv_rmd( d );
clrscr();
}

/**************************************************************************************************\
*       
\***sss********************************************************************************************/
void Test_Crypto(cs_menu* m, void* arg)
{

}


/**************************************************************************************************\
*       
\***sss********************************************************************************************/
void Nastrojka(cs_menu* m, void* arg)
{
TEST_IFACE testik;

uint16 KEY = 0;
uint32 CountCicl = 0;
uint32 CountErr = 0;
int res=0;

memcpy(&testik, arg, sizeof(TEST_IFACE));

	start((char*)(testik.title + 3));

	gotoxy(0, 8);
	cprintf("Пройденно циклов: \n\n"); 
	cprintf("Ошибок: "); 

prodolj:
	gotoxy(0, 15);
	cprintf("ESC - Стоп"); 


	    do
    	{
    	CountCicl++;
    	 
       	res = testik.f_test();
			if(res) 
			CountErr++;

		gotoxy(18, 8);
	    cprintf("%10.10d",CountCicl);
		gotoxy(18, 10);
	    cprintf("%10.10d",CountErr);

			if(CountCicl == MaxCicleNastr)
			{
				gotoxy(0, 13);
			    cprintf("Прошло много циклов. Продолжить?\nENTER - ОК\nESC - Выход");
		        if(getch() == KEY_ENTER)
				{
				T_clrbar(13); T_clrbar(14); T_clrbar(15);
				CountCicl = 0;
				CountErr = 0;
				goto prodolj;
				}
			}

		KEY = 0;
		KEY = kb_hit();
    	} while(KEY != KEY_ESC);    

//    }
//	else return;

	T_clrbar(14); T_clrbar(15);
	gotoxy(0, 14);
    cprintf("Для возврата в меню нажмите  \n<ENTER>.");
    do
    { 
	KEY = 0;
	KEY = getch();
    } while(KEY != KEY_ENTER);    

    return;   
}





/**************************************************************************************************\
*  МЕНЮ установки времени
\***sss********************************************************************************************/
#define DEC_ESC             0x11000000
#define DEC_ARROW_LEFT      0x14000000
#define DEC_ARROW_RIGHT     0x15000000
 
 int32 getdecimal(uint32 decade);
/**************************************************************************************************\
*       
\***sss********************************************************************************************/
void inmenu_set_time(cs_menu* node, void* arg)
{
  #define     SET_X    5
  #define     SET_DY   3
  s_rtc_regs  rtc;
  uint32      file_rtc;
  uint32      temp;
  uint32      sec;
  uint32      min;
  uint32      hour;
  uint32      day;
  uint32      month;
  uint32      year;
  int32       error;
  bool        exit_set_clock = false;
  int32       position_set_clock = 0;
  memset(&rtc, 0x0, sizeof(s_rtc_regs));
  clrscr();
  gotoxy(0,2);
  putstr("  Установка даты и времени    ");

  file_rtc = drv_mkd("/dev/rtc");
  if(file_rtc == RES_VOID) 
  {
    error = OSE_CANT_OPEN;
    goto m_error;
  }

  gotoxy(SET_X,4+SET_DY);
  putstr("ДД.ММ.ГГГГ  ЧЧ:ММ:СС");

  gotoxy(2,15);
  putstr("<ESC> - сохранить и выйти");
  set_text_attribute(0,15,30,ATTR_REVERSE); 
  while(exit_set_clock == false)
  {
    //Вывод времени
    error = drv_ioctl(file_rtc, RTC_GET_TIME_STRUCT, &rtc);
    if(error != OSE_OK) goto m_error;
    gotoxy(SET_X,3+SET_DY);
    cprintf("%2.2d.%2.2d.%4.4d  %2.2d:%2.2d:%2.2d",rtc.day,rtc.month,rtc.year,rtc.hour,rtc.min,rtc.sec);
    switch(position_set_clock)
    {   
      //=== Установка дня ===
      case 0:
      do
      {
        set_text_attribute(SET_X,3+SET_DY,2,ATTR_BLINK_NORMAL);
        gotoxy(SET_X,3+SET_DY);
        day = getdecimal(2);
        if((day == DEC_ARROW_RIGHT)||(day == DEC_ARROW_LEFT))
        {
          gotoxy(SET_X,6+SET_DY);
          putstr("                    ");
          gotoxy(SET_X,3+SET_DY);
          cprintf("%2.2d",rtc.day);
          set_text_attribute(SET_X,3+SET_DY,2,ATTR_NORMAL);
          if(day == DEC_ARROW_RIGHT)
            position_set_clock++;
          else if(day == DEC_ARROW_LEFT)
            position_set_clock = 5;     
          break;
        }
        else if (day == DEC_ESC)
        {
           exit_set_clock = true;
           break;
        }
		temp = rtc.day;
		rtc.day = day;
        error = drv_ioctl(file_rtc, RTC_SET_TIME_STRUCT, &rtc);
        if(error == OSE_OK)
        {
          gotoxy(SET_X,6+SET_DY);
          putstr("                    ");
          position_set_clock++;
        }
        else
        if(error == OSE_BAD_PARAM)
        {
          rtc.day = temp;
          gotoxy(SET_X,6+SET_DY);
          putstr("Неверный день месяца");
        }
        else goto m_error;       
      }while(error == OSE_BAD_PARAM);
      break;
      //=== Установка месяца ===
      case 1:
      do
      {
        set_text_attribute(SET_X+3,3+SET_DY,2,ATTR_BLINK_NORMAL);
        gotoxy(SET_X+3,3+SET_DY);
        month = getdecimal(2);
        if((month == DEC_ARROW_RIGHT)||(month == DEC_ARROW_LEFT))
        {
          gotoxy(SET_X,6+SET_DY);
          putstr("                    ");
          gotoxy(SET_X+3,3+SET_DY);
          cprintf("%2.2d",rtc.month);
          set_text_attribute(SET_X+3,3+SET_DY,2,ATTR_NORMAL);
          if(month == DEC_ARROW_RIGHT)
            position_set_clock++;
          else if(month == DEC_ARROW_LEFT)
            position_set_clock--;       
          break;
        }
        else if (month == DEC_ESC)
        {
          exit_set_clock = true;
          break;
        }
		temp = rtc.month;
		rtc.month = month;
        error = drv_ioctl(file_rtc, RTC_SET_TIME_STRUCT, &rtc);
        if(error == OSE_OK)
        {
          gotoxy(SET_X,6+SET_DY);
          putstr("                    ");
          position_set_clock++;
        }
        else
        if(error == OSE_BAD_PARAM)
        {
		  rtc.month = temp;
          gotoxy(SET_X,6+SET_DY);
          putstr("Неверный месяц");
        }
        else goto m_error;
      }while(error == OSE_BAD_PARAM);
      break;          
      //=== Установка года ===
      case 2:
      do
      {
        set_text_attribute(SET_X+6,3+SET_DY,4,ATTR_BLINK_NORMAL);
        gotoxy(SET_X+6,3+SET_DY);
        year = getdecimal(4);
        if((year == DEC_ARROW_RIGHT)||(year == DEC_ARROW_LEFT))
        {
          gotoxy(SET_X,6+SET_DY);
          putstr("                    ");
          gotoxy(SET_X+6,3+SET_DY);
          cprintf("%4.4d",rtc.year);
          set_text_attribute(SET_X+6,3+SET_DY,4,ATTR_NORMAL);
          if(year == DEC_ARROW_RIGHT)
            position_set_clock++;
          else if(year == DEC_ARROW_LEFT)
            position_set_clock--;       
          break;
        }
        else if (year == DEC_ESC)
        {
          exit_set_clock = true;
          break;
        }
		temp = rtc.year;
		rtc.year = year;
        error = drv_ioctl(file_rtc, RTC_SET_TIME_STRUCT, &rtc);
        if(error == OSE_OK)
        {
          gotoxy(SET_X,6+SET_DY);
          putstr("                    ");
          position_set_clock++;
        }
        else
        if(error == OSE_BAD_PARAM)
        {
          rtc.year = temp;
          gotoxy(SET_X,6+SET_DY);
          putstr("Недопустимый год");
        }
        else goto m_error;
      }while(error == OSE_BAD_PARAM);
      break;
      //=== Установка часов ===
      case 3:
      do
      {
        set_text_attribute(SET_X+12,3+SET_DY,2,ATTR_BLINK_NORMAL);
        gotoxy(SET_X+12,3+SET_DY);
        hour = getdecimal(2);
        if((hour == DEC_ARROW_RIGHT)||(hour == DEC_ARROW_LEFT))
        {
          gotoxy(SET_X,6+SET_DY);
          putstr("                    ");
          gotoxy(SET_X+12,3+SET_DY);
          cprintf("%2.2d",rtc.hour);
          set_text_attribute(SET_X+12,3+SET_DY,2,ATTR_NORMAL);
          if(hour == DEC_ARROW_RIGHT)
            position_set_clock++;
          else if(hour == DEC_ARROW_LEFT)
            position_set_clock--;       
          break;
        }
        else if (hour == DEC_ESC)
        {
          exit_set_clock = true;
          break;
        }
		temp = rtc.hour;
		rtc.hour = hour;
        error = drv_ioctl(file_rtc, RTC_SET_TIME_STRUCT, &rtc);
        if(error == OSE_OK)
        {
          gotoxy(SET_X,6+SET_DY);
          putstr("                    ");
          position_set_clock++;
        }
        else       
        if(error == OSE_BAD_PARAM)
        {
		  rtc.hour = temp;
          gotoxy(SET_X,6+SET_DY);
          putstr("Неверный час");
        }
        else goto m_error;
      }while(error == OSE_BAD_PARAM);
      break;
      //=== Установка минут ===
      case 4:
      do
      {
        set_text_attribute(SET_X+15,3+SET_DY,2,ATTR_BLINK_NORMAL);
        gotoxy(SET_X+15,3+SET_DY);
        min = getdecimal(2);
        if((min == DEC_ARROW_RIGHT)||(min == DEC_ARROW_LEFT))
        {
          gotoxy(SET_X,6+SET_DY);
          putstr("                    ");
          gotoxy(SET_X+15,3+SET_DY);
          cprintf("%2.2d",rtc.min);
          set_text_attribute(SET_X+15,3+SET_DY,2,ATTR_NORMAL);
          if(min == DEC_ARROW_RIGHT)
            position_set_clock++;
          else if(min == DEC_ARROW_LEFT)
            position_set_clock--;       
          break;
        }
        else if (min == DEC_ESC)
        {
          exit_set_clock = true;
          break;
        }
		temp = rtc.min;
		rtc.min = min;
        error = drv_ioctl(file_rtc, RTC_SET_TIME_STRUCT, &rtc);
        if(error == OSE_OK)
        {
          gotoxy(SET_X,6+SET_DY);
          putstr("                    ");
          position_set_clock++;
        }       
        else
        if(error == OSE_BAD_PARAM)
        {
		  rtc.min = temp;
          gotoxy(SET_X,6+SET_DY);
          putstr("Неверные минуты");
        }
        else goto m_error;
      }while(error == OSE_BAD_PARAM);
      break;
      //=== Установка секунд ===
      case 5:
      do
      {
        set_text_attribute(SET_X+18,3+SET_DY,2,ATTR_BLINK_NORMAL);
        gotoxy(SET_X+18,3+SET_DY);
        sec = getdecimal(2);
        if((sec == DEC_ARROW_RIGHT)||(sec == DEC_ARROW_LEFT))
        {
          gotoxy(SET_X,6+SET_DY);
          putstr("                    ");
          gotoxy(SET_X+18,3+SET_DY);
          cprintf("%2.2d",rtc.sec);
          set_text_attribute(SET_X+18,3+SET_DY,2,ATTR_NORMAL);
          if(sec == DEC_ARROW_RIGHT)
            position_set_clock = 0;
          else if(sec == DEC_ARROW_LEFT)
            position_set_clock--;       
          break;
        }
        else if (sec == DEC_ESC)
        {
          exit_set_clock = true;
          break;
        }
		temp = rtc.sec;
		rtc.sec = sec;
        error = drv_ioctl(file_rtc, RTC_SET_TIME_STRUCT, &rtc);
        if(error == OSE_OK)
        {
          gotoxy(SET_X,6+SET_DY);
          putstr("                    ");
          exit_set_clock = true;
        }
        else
        if(error == OSE_BAD_PARAM)
        {
		  rtc.sec = temp;
          gotoxy(SET_X,6+SET_DY);
          putstr("Неверные секунды");
        }
        else goto m_error;
      }while(error == OSE_BAD_PARAM);
      break;
    }
  }
  clrbar(15,30);
  gotoxy(15-13/2,15);
  putstr("Нажмите <ESC>");
  set_text_attribute(0,15,30,ATTR_BLINK_REVERSE);
  while(kb_hit() != KEY_ESC)
  {
    error = drv_ioctl(file_rtc, RTC_GET_TIME_STRUCT, &rtc);
    if(error != OSE_OK) goto m_error;
    gotoxy(SET_X,3+SET_DY);
    cprintf("%2.2d.%2.2d.%4.4d  %2.2d:%2.2d:%2.2d",rtc.day,rtc.month,rtc.year,rtc.hour,rtc.min,rtc.sec);
  }

	clrscr();
	gotoxy(3,5);
	cprintf("Перезапустите прибор и убедитесь, что отсвечиваемые дата и время верные!!!\n");
	set_text_attribute(0,5,30,ATTR_BLINK_NORMAL);
	set_text_attribute(0,6,30,ATTR_BLINK_NORMAL);
	set_text_attribute(0,7,30,ATTR_BLINK_NORMAL);
	while(1);
//  return;
m_error:
  clrscr();
  gotoxy(2,4+SET_DY);
  cprintf("Ошибка доступа: 0x%8.8x", error);
  put_end_line("Для выхода нажмите <ESC>", KEY_ESC);
}

/**************************************************************************************************\
* Взятие Целого Беззнакового Числа      
\***sss********************************************************************************************/

int32 getdecimal(uint32 decade)
{
  int32  string[7];
  int32  decnumber = 0;
  int32  multiplier;
  bool decaderedy;
  for(int i=0;i<decade;i++)
  {
    multiplier = 1;
    for(int j=i+1;j<decade;j++)
      multiplier *= 10;
    decaderedy = false;
    do{
      string[i] = getch();
      if(('0'<=string[i])&&(string[i]<='9'))
      {
        putch(string[i]);
        string[i] -= 0x30;
        string[i] *= multiplier;
        decnumber += string[i];
        decaderedy = true;
      }
      else if(string[i] == KEY_ESC)
        return DEC_ESC;
      else if(string[i] == KEY_LEFT)
        return DEC_ARROW_LEFT;
      else if(string[i] == KEY_RIGHT)
        return DEC_ARROW_RIGHT;
    }while(!decaderedy);
  }
  return decnumber;   
}

/**************************************************************************************************\
*  Вывод последней строки
\***sss********************************************************************************************/
void put_end_line(const char* str, int32 key)
{
  clrbar(15,30);
  gotoxy(15-strlen(str)/2,15); 
  putstr(str);
  set_text_attribute(0,15,30,ATTR_BLINK_REVERSE);
  while(kb_hit() != key);
}
/**************************************************************************************************\
*  Вывод строки поцентру
\***sss********************************************************************************************/
void put_str_center(int32 y, const char* str)
{
  clrbar(y,30);
  gotoxy(15-strlen(str)/2, y);
  putstr(str);
}
