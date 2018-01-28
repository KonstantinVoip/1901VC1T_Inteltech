/**********************************************************************************************************************
*                                        (c) COPYRIGHT by ZAO RCZI FORT.                                             *
*        ..                                       All rights reserved.                                               *
***********************************************************************************************************************
* Module      : sialp_i.cpp
* Description : Тестовые функции ИП(Интерфейсного Процессора iface) для СИ и АЛП
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

#include "console.h"
#include <mem_fpga.iface15.h>
#include "drv_rik.h"
#include "drv_gpio.h"

#include "os_csl_mcbsp.h"

//#include "drv_mcbsp.h"
#include "sialp.h"
#include "tpo.h"

	char* tip[] = {"СИ ", "АЛП"};

	extern	uint32 msg_pid_main;
	extern comm_status pid_comm[NUMBER_COMM_DSP];


	uint32 getheximal(uint32 decade);
	extern int32 getdecimal(uint32 decade);
	void alp_rik(int reader, uint8 num0, uint8 num1, int delay);
	int32 receive_msg(void* recev, int32 length, uint32 ms);
	void send_main_start_sialp(kdg_sialp* par);
	void send_comm_start_sialp(kdg_sialp* par);
	extern void Send_cmd_comm(uint32 n_comm, uint32 cmd);





void Vvod(kdg_sialp* arg)
{
	uint32 Y;
	arg->val_1=0;
	arg->val_2=0;

	vv1:
	  Y=5;
	  gotoxy(2,Y);
	  putstr("Введите число 1: ");
	  cprintf("%2.2d",arg->val_1);
	  set_text_attribute(19,Y,2,ATTR_BLINK_NORMAL);
	  gotoxy(19,Y);
	  arg->val_1 = getheximal(2);
		if(arg->val_1 == KEY_ESC)
		goto vv1;

	if(arg->tiptest == TIP_SI)
	{
	vv2:
	  Y=6;
	  gotoxy(2,Y);
	  putstr("Введите число 2: ");
	  cprintf("%2.2d",arg->val_2);
	  set_text_attribute(19,Y,2,ATTR_BLINK_NORMAL);
	  gotoxy(19,Y);
	  arg->val_2 = getheximal(2);
		if(arg->val_2 == KEY_ESC)
		goto vv2;
	}

	  gotoxy(0,9);
	  putstr("Нажмите любую клавишу");
	  Y = getch();

	/*
	Y=7;
	  gotoxy(2,Y);
	  putstr("Введите задержку: ");
	  cprintf("%2.2d",arg->val_1);
	  set_text_attribute(19,Y,2,ATTR_BLINK_NORMAL);
	  gotoxy(19,Y);
	  arg->val_2 = getdecimal(2);
	*/
}




void SI_RIK(cs_menu* m, void* arg)
{
  clrscr();
  gotoxy(0,2);
  putstr("           Тест СИ   ");
  gotoxy(7,3);
  putstr(m->name);

kdg_sialp* par = (kdg_sialp*)arg;

par->tiptest = TIP_ALP;
par->kodtest = RIK;
par->channel = 0;
par->time_ms = 3;
par->val_1=0;
par->val_2=0;

#ifdef TPO5
Send_cmd_comm(0,STOP_TX);
Send_cmd_comm(1,STOP_TX);
#endif


Vvod(par);
par->tiptest = TIP_SI;

  gotoxy(0,9);
  putstr("          Идет тест        ");
  set_text_attribute(0,9,30,ATTR_BLINK_REVERSE); 
//while(1);
si_rik_read(par->channel, (uint8)par->val_1, (uint8)par->val_2, par->time_ms);

}



void SI_MCBSP(cs_menu* m, void* arg)
{
  clrscr();
  gotoxy(0,2);
  putstr("           Тест СИ   ");
  gotoxy(7,3);
  putstr(m->name);

kdg_sialp* par = (kdg_sialp*)arg;

par->tiptest = TIP_ALP;
par->kodtest = MCBSP;
par->channel = 0;
par->time_ms = 3;
par->val_1=0;
par->val_2=0;


Vvod(par);
par->tiptest = TIP_SI;

  gotoxy(0,9);
  putstr("          Идет тест        ");
  set_text_attribute(0,9,30,ATTR_BLINK_REVERSE); 

si_mcbsp(par->channel, (uint8)par->val_1, (uint8)par->val_2, par->time_ms);


}



void SI_CP_PLIS(cs_menu* m, void* arg)
{
  clrscr();
  gotoxy(0,2);
  putstr("           Тест СИ   ");
  gotoxy(7,3);
  putstr(m->name);

kdg_sialp* par = (kdg_sialp*)arg;

par->tiptest = TIP_SI;
par->kodtest = CP_PLIS;
par->channel = 0;
par->time_ms = 3;
par->val_1=0;
par->val_2=0;

#ifdef TPO5
Send_cmd_comm(0,STOP_TX);
Send_cmd_comm(1,STOP_TX);
#endif


Vvod(par);

send_main_start_sialp(par);

while(1);

}

void SI_CRYPTO(cs_menu* m, void* arg)
{
  clrscr();
  gotoxy(0,2);
  putstr("           Тест СИ   ");
  gotoxy(7,3);
  putstr(m->name);

kdg_sialp* par = (kdg_sialp*)arg;

par->tiptest = TIP_SI;
par->kodtest = CRYPTO;
par->channel = 0;
par->time_ms = 3;
par->val_1=0;
par->val_2=0;

#ifdef TPO5
Send_cmd_comm(0,STOP_TX);
Send_cmd_comm(1,STOP_TX);
#endif

Vvod(par);

send_main_start_sialp(par);

while(1);

}


void SI_EXT_RAM(cs_menu* m, void* arg)
{
  clrscr();
  gotoxy(0,2);
  putstr("           Тест СИ   ");
  gotoxy(7,3);
  putstr(m->name);


kdg_sialp* par = (kdg_sialp*)arg;

par->tiptest = TIP_SI;
par->kodtest = CP_EXT_RAM;
par->channel = 0;
par->time_ms = 3;
par->val_1=0;
par->val_2=0;

#ifdef TPO5
Send_cmd_comm(0,STOP_TX);
Send_cmd_comm(1,STOP_TX);
#endif

Vvod(par);

send_main_start_sialp(par);

while(1);

}


void SI_INT_RAM(cs_menu* m, void* arg)
{

	uint32* n_usb = (uint32*)arg;

	clrscr();
	gotoxy(0,2);
	putstr("           Тест СИ   ");
	gotoxy(7,3);
	putstr(m->name);

	#ifdef TPO5
	Send_cmd_comm(0,STOP_TX);
	Send_cmd_comm(1,STOP_TX);
	#endif


	kdg_sialp* par;
	//kdg_sialp* par = (kdg_sialp*)arg;

	par->tiptest = TIP_SI;
	
	switch(n_usb[0])
	{
		case 1:
		par->kodtest = CP_INT_RAM1;
		break;
		case 2:
		par->kodtest = CP_INT_RAM2;
		break;
		case 3:
		par->kodtest = CP_INT_RAM3;
		break;
	}

	par->channel = 0;
	par->time_ms = 3;
	par->val_1=0;
	par->val_2=0;

	Vvod(par);

	send_main_start_sialp(par);

	while(1);

}


void SI_PLIS(cs_menu* m, void* arg)
{

	//uint32* n_usb = (uint32*)arg;

	  clrscr();
	  gotoxy(0,2);
	  putstr("           Тест СИ   ");
	  gotoxy(7,3);
	  putstr(m->name);

      kdg_sialp* par;
	//kdg_sialp* par = (kdg_sialp*)arg;

	  par->tiptest = TIP_ALP;
	  par->kodtest = PLIS_SI;
	  par->channel = 0;
	  par->time_ms = 3;
	  par->val_1=0;
	  par->val_2=0;

  	 #ifdef TPO5
  	 Send_cmd_comm(0,STOP_TX);
	 Send_cmd_comm(1,STOP_TX);
 	 #endif


	Vvod(par);
	par->tiptest = TIP_SI;

	send_main_start_sialp(par);

	while(1);
}
/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
void SI_SATA(cs_menu* m, void* arg)
{

	//uint32* n_usb = (uint32*)arg;


       
      //Вывод на Экран вот как происходит
	  clrscr();
	  gotoxy(0,2);
	  putstr("           Тест СИ   ");
	  gotoxy(7,3);
	  putstr(m->name);

 	  kdg_sialp* par;
	  //kdg_sialp* par = (kdg_sialp*)arg;

      par->tiptest = TIP_ALP;
	  par->kodtest = SATA_SI;
	  par->channel = 0;
	  par->time_ms = 3;
	  par->val_1=0;
	  par->val_2=0;

	  #ifdef TPO5
  	  Send_cmd_comm(0,STOP_TX);
 	  Send_cmd_comm(1,STOP_TX);
	  #endif


	  Vvod(par);
	  par->tiptest = TIP_SI;

	  send_main_start_sialp(par);

	 while(1);
}
/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
void SI_USB3(cs_menu* m, void* arg)
{

	//uint32* n_usb = (uint32*)arg;
	  clrscr();
	  gotoxy(0,2);
	  putstr("           Тест СИ   ");
	  gotoxy(7,3);
	  putstr(m->name);

	  kdg_sialp* par;
	  //kdg_sialp* par = (kdg_sialp*)arg;

	  par->tiptest = TIP_ALP;
	  par->kodtest = USB3_SI;
	  par->channel = 0;
	  par->time_ms = 3;
	  par->val_1=0;
	  par->val_2=0;

 	  #ifdef TPO5
	  Send_cmd_comm(0,STOP_TX);
	  Send_cmd_comm(1,STOP_TX);
	  #endif


 	  Vvod(par);
	  par->tiptest = TIP_SI;
	  send_main_start_sialp(par);

	while(1);
}

/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
void SI_ETH(cs_menu* m, void* arg)
{
    clrscr();
    gotoxy(0,2);
    putstr("           Тест СИ   ");
    gotoxy(7,3);
    putstr(m->name);

	kdg_sialp* par = (kdg_sialp*)arg;

	par->tiptest = TIP_SI;
	par->kodtest = ETHERNET;
	par->channel = 0;
	par->time_ms = 3;
	par->val_1=0;
	par->val_2=0;

	Vvod(par);
	#ifdef TPO5
	Send_cmd_comm(1,STOP_TX);
	#endif

	send_comm_start_sialp(par);

	while(1);
}


/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
void SI_DISPL(cs_menu* m, void* arg)
{

	uint32* exit = (uint32*)arg;
	*exit = 1;
	uint16 KEY = 0;
	sleep_s(1);
	con_clrscr(SYS_CON);

	while(1)
	{
		    /*
			while(1)
			{
			clrscr();
			sleep_s(3);

		  	gotoxy(0,0);
			for(int i = 0; i<16; i++)
			{ 
				for(int j = 0; j<30; j+=2)
					 set_text_attribute(j,i,1,ATTR_REVERSE); 

			}
			sleep_s(3);
			KEY = 0;
			KEY = kb_hit();
			KEY &= 0xFF;
			if(KEY == KEY_ENTER)
			break;
			}

			while(1)
			{
			clrscr();
			sleep_s(3);

			gotoxy(0,0);
			for(int i = 0; i<16; i+=2)
			{ 
				 set_text_attribute(0,i,30,ATTR_REVERSE); 

			}	
			sleep_s(3);
			KEY = 0;
			KEY = kb_hit();
			KEY &= 0xFF;
			if(KEY == KEY_ENTER)
			break;
			}
		   */
	clrscr();
	gotoxy(0,0);
	for(int i = 0; i<16; i++)
	{ 
		gotoxy(0,i);
		for(int j = 0; j<30; j++)
        putch( 0xA0);
	}	
	
	while(1)
	{
		KEY = 0;
		KEY = kb_hit();
		KEY &= 0xFF;
		if(KEY == KEY_ENTER)
		break;
	}  //end while(1)


	while(1)
	{
		clrscr();
		sleep_s(3);

		gotoxy(0,0);
		for(int i = 0; i<16; i++)
		{ 
			gotoxy(0,i);
			for(int j = 0; j<30; j++)
	        putch( 0xA0);
		}	
		sleep_s(3);
		KEY = 0;
		KEY = kb_hit();
		KEY &= 0xFF;
		if(KEY == KEY_ENTER)
		break;
	} //end while(1)


	clrscr();
	gotoxy(0,0);
	for(int i = 0; i<16; i++)
	{ 
		gotoxy(0,i);
		for(int j = 0; j<30; j++)
        putch( 0xA1);

	}	

	while(1)
	{
		KEY = 0;
		KEY = kb_hit();
		KEY &= 0xFF;
		if(KEY == KEY_ENTER)
		break;
	} //end while(1)


	while(1)
	{
		clrscr();
		sleep_s(3);

		gotoxy(0,0);
		for(int i = 0; i<16; i++)
		{ 
			gotoxy(0,i);
			for(int j = 0; j<30; j++)
	        putch( 0xA1);

		}	
		sleep_s(3);
		KEY = 0;
		KEY = kb_hit();
		KEY &= 0xFF;
		if(KEY == KEY_ENTER)
		break;
	} //end while(1)

		/*
			while(1)
			{
			clrscr();
			sleep_s(3);

			gotoxy(0,0);
			for(int i = 0; i<16; i++)
			{ 
				gotoxy(0,i);
				for(int j = 0; j<30; j++)
		        putch( 0xA3);

			}	
			sleep_s(3);
			KEY = 0;
			KEY = kb_hit();
			KEY &= 0xFF;
			if(KEY == KEY_ENTER)
			break;
			}


				while(1)
			{
			clrscr();
			sleep_s(3);

			gotoxy(0,0);
			for(int i = 0; i<16; i++)
			{ 
				gotoxy(0,i);
				for(int j = 0; j<30; j++)
		        putch( 0xA6);

			}	
			sleep_s(3);
			KEY = 0;
			KEY = kb_hit();
			KEY &= 0xFF;
			if(KEY == KEY_ENTER)
			break;
			}


				while(1)
			{
			clrscr();
			sleep_s(3);

			gotoxy(0,0);
			for(int i = 0; i<16; i++)
			{ 
				gotoxy(0,i);
				for(int j = 0; j<30; j++)
		        putch( 0xA7);

			}	
			sleep_s(3);
			KEY = 0;
			KEY = kb_hit();
			KEY &= 0xFF;
			if(KEY == KEY_ENTER)
			break;
			}
		*/

  } //end Global while(1)

}


//------------------ALP---------------------
/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
void ALP_RIK(cs_menu* m, void* arg)
{
	  clrscr();
	  gotoxy(0,2);
	  putstr("           Тест АЛП   ");
	  gotoxy(7,3);
	  putstr(m->name);

  	  kdg_sialp* par = (kdg_sialp*)arg;

	  par->tiptest = TIP_ALP;
	  par->kodtest = RIK;
	  par->channel = 0;
	  par->time_ms = 10;
	  par->val_1=0;
	  par->val_2=0;

	  Vvod(par);

	  gotoxy(0,8);
	  putstr(" ! ИЗВЛЕКИТЕ РИК ИЗ РИДЕРА ! ");
	  set_text_attribute(0,8,30,ATTR_BLINK_REVERSE); 

  	  int32 k = getch();

	  gotoxy(0,9);
	  putstr("          Идет тест        ");
	  set_text_attribute(0,9,30,ATTR_BLINK_REVERSE); 
	  //while(1);
	  alp_rik(par->channel, (uint8)par->val_1, (uint8)par->val_2, par->time_ms);

}


/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
void ALP_PP_PLIS(cs_menu* m, void* arg)
{
  clrscr();
  gotoxy(0,2);
  putstr("           Тест АЛП   ");
  gotoxy(7,3);
  putstr(m->name);

kdg_sialp* par = (kdg_sialp*)arg;

par->tiptest = TIP_ALP;
par->kodtest = PP_PLIS;
par->channel = 0;
par->time_ms = 10;
par->val_1=0;
par->val_2=0;

Vvod(par);

  gotoxy(0,9);
  putstr("          Идет тест        ");
  set_text_attribute(0,9,30,ATTR_BLINK_REVERSE); 
//while(1);

alp_pp_plis(par->channel, (uint8)par->val_1, (uint8)par->val_2, par->time_ms);

}



void ALP_MCBSP(cs_menu* m, void* arg)
{
  clrscr();
  gotoxy(0,2);
  putstr("           Тест АЛП   ");
  gotoxy(7,3);
  putstr(m->name);

kdg_sialp* par = (kdg_sialp*)arg;

par->tiptest = TIP_ALP;
par->kodtest = MCBSP;
par->channel = 0;
par->time_ms = 10;
par->val_1=0;
par->val_2=0;

Vvod(par);

  gotoxy(0,9);
  putstr("          Идет тест        ");
  set_text_attribute(0,9,30,ATTR_BLINK_REVERSE); 

alp_mcbsp(par->channel, (uint8)par->val_1, (uint8)par->val_2, par->time_ms);

}


void ALP_CP_PLIS(cs_menu* m, void* arg)
{
  clrscr();
  gotoxy(0,2);
  putstr("           Тест АЛП   ");
  gotoxy(7,3);
  putstr(m->name);

kdg_sialp* par = (kdg_sialp*)arg;

par->tiptest = TIP_ALP;
par->kodtest = CP_PLIS;
par->channel = 0;
par->time_ms = 10;
par->val_1=0;
par->val_2=0;

Vvod(par);

send_main_start_sialp(par);

while(1);

}



void ALP_CRYPT(cs_menu* m, void* arg)
{
  clrscr();
  gotoxy(0,2);
  putstr("           Тест АЛП   ");
  gotoxy(7,3);
  putstr(m->name);

kdg_sialp* par = (kdg_sialp*)arg;

par->tiptest = TIP_ALP;
par->kodtest = CRYPTO;
par->channel = 0;
par->time_ms = 10;
par->val_1=0;
par->val_2=0;

Vvod(par);

send_main_start_sialp(par);

while(1);

}




void ALP_EXT_RAM(cs_menu* m, void* arg)
{
  clrscr();
  gotoxy(0,2);
  putstr("           Тест АЛП  ");
  gotoxy(7,3);
  putstr(m->name);

kdg_sialp* par = (kdg_sialp*)arg;

par->tiptest = TIP_ALP;
par->kodtest = CP_EXT_RAM;
par->channel = 0;
par->time_ms = 10;
par->val_1=0;
par->val_2=0;

Vvod(par);

send_main_start_sialp(par);

while(1);
}


/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
void ALP_INT_RAM(cs_menu* m, void* arg)
{

	  uint32* n_usb = (uint32*)arg;

	  clrscr();
	  gotoxy(0,2);
	  putstr("           Тест АЛП  ");
	  gotoxy(7,3);
	  putstr(m->name);

  	  kdg_sialp* par;
	  //kdg_sialp* par = (kdg_sialp*)arg;

  	  par->tiptest = TIP_ALP;
	
 	  switch(n_usb[0])
	  {
		case 1:
		par->kodtest = CP_INT_RAM1;
		break;
		case 2:
		par->kodtest = CP_INT_RAM2;
		break;
		case 3:
		par->kodtest = CP_INT_RAM3;
		Vvod(par);
		break;
		default:
		break;
	   }

     par->channel = 0;
  	 par->time_ms = 10;
	//par->val_1=0;
	//par->val_2=0;
	send_main_start_sialp(par);

	while(1);

}

/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
void ALP_PLIS(cs_menu* m, void* arg)
{

	//uint32* n_usb = (uint32*)arg;

	  clrscr();
	  gotoxy(0,2);
	  putstr("           Тест АЛП  ");
	  gotoxy(7,3);
	  putstr(m->name);

  	  kdg_sialp* par;
	  //kdg_sialp* par = (kdg_sialp*)arg;

	  par->tiptest = TIP_ALP;
	  par->kodtest = PLIS_SI;
	  par->channel = 0;
	  par->time_ms = 10;
	  par->val_1=0;
	  par->val_2=0;

	  Vvod(par);
	  send_main_start_sialp(par);

 	  while(1);
}




void ALP_ETHERNET(cs_menu* m, void* arg)
{
  clrscr();
  gotoxy(0,2);
  putstr("           Тест АЛП  ");
  gotoxy(7,3);
  putstr(m->name);

kdg_sialp* par = (kdg_sialp*)arg;

par->tiptest = TIP_ALP;
par->kodtest = ETHERNET;
par->channel = 0;
par->time_ms = 10;
par->val_1=0;
par->val_2=0;

Vvod(par);

Send_cmd_comm(0,STOP_TX);
#ifndef TPO5
Send_cmd_comm(2,STOP_TX);
#endif
send_comm_start_sialp(par);

//send_main_start_sialp(par);

while(1);
}


void ALP_SP_PLIS(cs_menu* m, void* arg)
{
  clrscr();
  gotoxy(0,2);
  putstr("           Тест АЛП  ");
  gotoxy(7,3);
  putstr(m->name);

kdg_sialp* par = (kdg_sialp*)arg;

par->tiptest = TIP_ALP;
par->kodtest = SP_PLIS;
par->channel = 0;
par->time_ms = 10;
par->val_1=0;
par->val_2=0;

Vvod(par);

send_comm_start_sialp(par);

#ifndef TPO5
Send_cmd_comm(0,STOP_TX);
Send_cmd_comm(2,STOP_TX);
send_main_start_sialp(par);
#else
Send_cmd_comm(1,STOP_TX);
#endif

send_main_start_sialp(par);

while(1);


}


/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
void UserRikEvent(uint16 rik_status)
{
	asm(" nop");
}

#define MAX_CYCLES 64
/*****************************************************************************
Syntax:      	    
Remarks:SI RIK READ			    
*******************************************************************************/
void si_rik_read(int reader, uint8 num0, uint8 num1, int delay)
{

	s_rik_reset		rik_reset;
	s_inode* 		list;
    int32			error, zone, offset0, offset1;
	uint64			CurTime;
	uint8 			buf0[32];

    //	uint8 			buf1[32];
	/*
	    clrscr();
	    cprintf ("Тест СИ \nЧтение РИК \nРидер:%i, число:0x%x\n\n\n", reader+1, num);
	    cprintf ("        Для выхода нажмите\n");
	    cprintf ("           любую клавишу\n");
	*/

	//	memset(buf0, num0, sizeof(buf0));
	//	memset(buf1, num1, sizeof(buf1));
	memset(buf0, 0x55, sizeof(buf0));


	uint32 file = drv_mkd("/dev/rik/");
	  
	//Получение списка устройств РИК:
	error = drv_ioctl(file, IOC_INODE_LIST, &list);
	  
	 //Выбор РИК:
	if(reader == 0)
	{
	  drv_select(file, "rik1");
	}
	else
	{  
	  drv_select(file, "rik2");
    } 

	error = drv_ioctl(file, RIK_USER_INT_FUNC, (void*)((uint32)&UserRikEvent));
	error = drv_ioctl(file, RIK_GET_RESET_STRUCT, &rik_reset);
	error = drv_open(file, DRV_WR|DRV_RD);
	zone = 0x1;
	error = drv_ioctl(file, RIK_SET_ZONE, &zone);
	offset0 = 0;
	offset1 = sizeof(buf0);
	error = drv_ioctl(file, RIK_SET_OFFSET, &offset0);
	error = drv_write(file, buf0, sizeof(buf0));
	/*
		error = drv_ioctl(file, RIK_SET_OFFSET, &offset1);
		error = drv_write(file, buf1, sizeof(buf1));
	*/




	//while (!kb_hit())
    while (1)
    {
		CurTime = time_m() + delay*1000;
   		while (time_m() < CurTime)
    	{

			//for(int k = 0; k < MAX_CYCLES && !kb_hit(); k++)
        	for(int k = 0; k < MAX_CYCLES ; k++)
       		{
				error = drv_ioctl(file, RIK_SET_OFFSET, &offset0);
				error = drv_read(file, buf0, sizeof(buf0));

           		if (!error)
            	{
					error = drv_ioctl(file, RIK_GET_RESET_STRUCT, &rik_reset);
	           	    if (error)
					{
					return;
            	    }
            	}

            	if (time_m() >= CurTime)
            	{
					break;
            	}
        	}//end for
	
	    error = drv_ioctl(file, RIK_GET_RESET_STRUCT, &rik_reset);
        if (error)
		return;
    	} //end while time

		if(num0)
		{
		  CurTime = time_m() + delay*1000;
   		  while (time_m() < CurTime)
    	  {
			/*
			//        for(int k = 0; k < MAX_CYCLES && !kb_hit(); k++)
			        for(int k = 0; k < MAX_CYCLES; k++)
			        {

				error = drv_ioctl(file, RIK_SET_OFFSET, &offset1);
				error = drv_read(file, buf1, sizeof(buf1));

			            if (!error)
			            {
					error = drv_ioctl(file, RIK_GET_RESET_STRUCT, &rik_reset);
				            if (error)
						return;
			            }

			            if (time_m() >= CurTime)
			            {
					break;
			            }
			        }
				error = drv_ioctl(file, RIK_GET_RESET_STRUCT, &rik_reset);
			            if (error)
					return;
			*/
          }//end while time_n
       }// end if(num0)
    
    }//end global while(1)

}



#define		TXD_MCBSP2				(*(uint32 *)0x01A40004)
#define		MCBSP2_SPCR				(*(uint32 *)0x01A40008)
extern MCBSP_Handle h_out;

//-------------------------------------------------------------
void si_mcbsp(int reader, uint8 num0, uint8 num1, int delay)
{

/*

uint32 FileMCBS2 = drv_mkd("/dev/mcbsp/mcbsp_outt");
uint32 FileMCBS3 = drv_mkd("/dev/mcbsp/123");

uint32 FileMCBS1 = drv_mkd("/dev/mcbsp");

  s_os_driver_descriptor* d;
  uint32 index;
//  int32 r;


	res_share(FileMCBS1);
	drv_open(FileMCBS1,DRV_WR);




  index = os_driver_descriptor_check( FileMCBS1 );

  d = v_os_desc_list[index];


 drv_write(FileMCBS1,buf0, sizeof(buf0));

*/


	uint32 			buf0[1];
	uint32 u = 0;

	u = MCBSP2_SPCR;
    MCBSP2_SPCR = u | 0x10000;

uint32 r = prc_disable();


while(1)
{
 memset(buf0, 0x55, sizeof(buf0));
 u = 900000; 
 
  while(u)
  { 
 	TXD_MCBSP2 = buf0[0]; 
  
 	while(MCBSP2_SPCR & 0x20000); 
	while(!(MCBSP2_SPCR & 0x20000));

    u--;
  }
 

 if(num0)
 {
  memset(buf0, 0xFF, sizeof(buf0));
  u = 900000;
  while(u)
  {
	TXD_MCBSP2 = buf0[0];

	while(MCBSP2_SPCR & 0x20000);
	while(!(MCBSP2_SPCR & 0x20000));

   u--;
  }
 }
}





}





#define		LED				(*(uint16 *)0x60000034)

#define		EN				(*(uint32 *)0x01B00000)
#define		DIR				(*(uint32 *)0x01B00004)
#define		VAL				(*(uint32 *)0x01B00008)

void alp_sinhrosig()
{
//uint32 en = EN;
//uint32 dir = DIR;
//uint32 val = VAL;


EN |= 0x8000;
DIR |= 0x8000;
VAL |= 0x8000;

asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );

VAL ^= 0x8000;

}


//#define REG_RIK_BUFPRMPRD_tpo			0x60000080// ;RW
#define REG_RIK_POWER_tpo						(*(uint16 *)0x6000004C)
#define REG_RIK_STATUS_tpo						(*(uint16 *)0x6000004C)
#define REG_RIK_RESET_STATUS_tpo				(*(uint16 *)0x60000044)
#define REG_RIK_PRD_DATA_tpo					(*(uint16 *)0x60000006)

#define RIK_ER_TIMEOUT_tpo		    			0x7011 
#define MASK_RIK_TRANSFER_COMPLETE_tpo          0x0001
#define C_MAX_BLOCK_LENGTH_tpo                  64          //Макс. длина блока РИК в байтах
#define CMD_RIK_1_POWER_ON_tpo                  0x0001
#define CMD_RIK_2_POWER_ON_tpo                  0x0002
#define CMD_RST_RIK_TRANSFER_COMPLETE_tpo       0x0001
#define CMD_RIK_TRANSFER_START_tpo              0x0001
#define RIK_WRITE_CMD_LEN_tpo                   5
//extern int32   RIKReady_tpo();
int32 RIKReady_tpo()
{
    uint64 limit_time = time_m()+5000;
    uint32 time_out = 0;

    while(((REG_RIK_STATUS_tpo & MASK_RIK_TRANSFER_COMPLETE_tpo)==0) && (time_out==0))
    {
        prc_yield();
        if(time_m()>=limit_time)
            time_out = 1;
    }

    if(!time_out)
        return OSE_OK;
    else
        return RIK_ER_TIMEOUT_tpo;
}

//-------------------------------------------------------------
//-------------------------------------------------------------

/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
void alp_rik(int reader, uint8 num0, uint8 num1, int delay)
{

//	s_rik_reset		rik_reset;
//	s_os_inode* 	list;
//    int32			error, zone, offset0, offset1;
	uint8 			buf0[C_MAX_BLOCK_LENGTH_tpo];
    uint16* BufPrmPrdRIK_tpo     = (uint16*)(0x60000080);//&REG_RIK_BUFPRMPRD;
    uint16* BufPrmPrdDataRIK_tpo = (uint16*)(0x60000080 + RIK_WRITE_CMD_LEN_tpo);//&REG_RIK_BUFPRMPRD + RIK_WRITE_CMD_LEN;
    uint16  Nout, Nin;
	int32	res = 0;	

	uint32 u = 333;
	uint32 r = prc_disable();


//	memset(buf0, num0, sizeof(buf0));

    switch(reader)
    {
       case 0:         
       REG_RIK_POWER_tpo = CMD_RIK_1_POWER_ON_tpo;
       break;
       
       case 1:
       REG_RIK_POWER_tpo = CMD_RIK_2_POWER_ON_tpo;
       break;
    }       

	memset(buf0, num0, sizeof(buf0));
        //Подготовка 5 байт команды:
    BufPrmPrdRIK_tpo[0] = 0x90;
    BufPrmPrdRIK_tpo[1] = 0xD6;
    BufPrmPrdRIK_tpo[2] = (1<<4)|(0);
    BufPrmPrdRIK_tpo[3] = 0 & 0xFF;
    BufPrmPrdRIK_tpo[4] = C_MAX_BLOCK_LENGTH_tpo;

    //Подготовка передаваемого буфера:
    Nout = 0;
    Nin=0;
    for(uint16 i=0; i<C_MAX_BLOCK_LENGTH_tpo; i++)
    {
     BufPrmPrdDataRIK_tpo[Nout++] = buf0[Nin++] & 0xFF;
    }


	while(true)
	{
		u = 256;
		while(u--)
		{
		asm ( " nop " );
		asm ( " nop " );
		asm ( " nop " );
		asm ( " nop " );
		asm ( " nop " );
		asm ( " nop " );
		asm ( " nop " );
		asm ( " nop " );
		}
		alp_sinhrosig();

		u = 450;
		while(u--)
		{
		asm ( " nop " );
		asm ( " nop " );
		asm ( " nop " );
		asm ( " nop " );
		asm ( " nop " );
		asm ( " nop " );
		asm ( " nop " );
		asm ( " nop " );
		}

	   //Запись передаваемого буфера:
	   REG_RIK_RESET_STATUS_tpo = CMD_RST_RIK_TRANSFER_COMPLETE_tpo;
	   REG_RIK_PRD_DATA_tpo = CMD_RIK_TRANSFER_START_tpo;
	   res = RIKReady_tpo();

	} //end while (true)

}


/*
void alp_rik(int reader, uint8 num0, uint8 num1, int delay)
{

//	s_rik_reset		rik_reset;
//	s_os_inode* 	list;
//    int32			error, zone, offset0, offset1;
	uint8 			buf0[C_MAX_BLOCK_LENGTH_tpo];

    uint16* BufPrmPrdRIK_tpo     = (uint16*)(0x60000080);//&REG_RIK_BUFPRMPRD;
    uint16* BufPrmPrdDataRIK_tpo = (uint16*)(0x60000080 + RIK_WRITE_CMD_LEN_tpo);//&REG_RIK_BUFPRMPRD + RIK_WRITE_CMD_LEN;
    uint16  Nout, Nin;
	int32	res = 0;	

	uint32 u = 333;
uint32 r = prc_disable();


//	memset(buf0, num0, sizeof(buf0));

            switch(reader)
            {
                case 0:         
                    REG_RIK_POWER_tpo = CMD_RIK_1_POWER_ON_tpo;
                break;
                case 1:
                    REG_RIK_POWER_tpo = CMD_RIK_2_POWER_ON_tpo;
                break;
            }       

EN |= 0x1000;
DIR |= 0x1000;
//VAL |= 0x1000;


while(true)
{

VAL |= 0x1000;

	memset(buf0, 0xFF, sizeof(buf0));
        //Подготовка 5 байт команды:
        BufPrmPrdRIK_tpo[0] = 0x90;
        BufPrmPrdRIK_tpo[1] = 0xD6;
        BufPrmPrdRIK_tpo[2] = (1<<4)|(0);
        BufPrmPrdRIK_tpo[3] = 0 & 0xFF;
        BufPrmPrdRIK_tpo[4] = C_MAX_BLOCK_LENGTH_tpo;

        //Подготовка передаваемого буфера:
        Nout = 0;
		Nin=0;
        for(uint16 i=0; i<C_MAX_BLOCK_LENGTH_tpo; i++)
            BufPrmPrdDataRIK_tpo[Nout++] = buf0[Nin++] & 0xFF;


u = 256;
while(u--)
{
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
}
alp_sinhrosig();

u = 450;
while(u--)
{
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
}

        //Запись передаваемого буфера:
        REG_RIK_RESET_STATUS_tpo = CMD_RST_RIK_TRANSFER_COMPLETE_tpo;
        REG_RIK_PRD_DATA_tpo = CMD_RIK_TRANSFER_START_tpo;

		res = RIKReady_tpo();






VAL ^= 0x1000;

	memset(buf0, num0, sizeof(buf0));
        //Подготовка 5 байт команды:
        BufPrmPrdRIK_tpo[0] = 0x90;
        BufPrmPrdRIK_tpo[1] = 0xD6;
        BufPrmPrdRIK_tpo[2] = (1<<4)|(0);
        BufPrmPrdRIK_tpo[3] = 0 & 0xFF;
        BufPrmPrdRIK_tpo[4] = C_MAX_BLOCK_LENGTH_tpo;

        //Подготовка передаваемого буфера:
        Nout = 0;
		Nin=0;
        for(uint16 i=0; i<C_MAX_BLOCK_LENGTH_tpo; i++)
            BufPrmPrdDataRIK_tpo[Nout++] = buf0[Nin++] & 0xFF;


u = 256;
while(u--)
{
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
}
alp_sinhrosig();

u = 450;
while(u--)
{
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
}

        //Запись передаваемого буфера:
        REG_RIK_RESET_STATUS_tpo = CMD_RST_RIK_TRANSFER_COMPLETE_tpo;
        REG_RIK_PRD_DATA_tpo = CMD_RIK_TRANSFER_START_tpo;

		res = RIKReady_tpo();




}

}
*/
//-------------------------------------------------------------
//-------------------------------------------------------------

#define EMIFB_GLBCONT        (*(volatile uint32*)0x01A80000) 
#define EMIFB_CESEC0        (*(volatile uint32*)0x01A80048) 
#define EMIFB_CECTL0        (*(volatile uint32*)0x01A80008) 
/*
void alp_pp_plis(int reader, uint8 num0, uint8 num1, int delay)
{

	uint16 			buf0[C_MAX_BLOCK_LENGTH_tpo];
	uint32		save = 0;
	uint32		b = 1;
//   uint16* BufPrmPrdRIK_tpo     = (uint16*)(0x60000080);//&REG_RIK_BUFPRMPRD;
    uint16* BufPrmPrdDataRIK_tpo = (uint16*)(0x60000080 + RIK_WRITE_CMD_LEN_tpo);//&REG_RIK_BUFPRMPRD + RIK_WRITE_CMD_LEN;
    uint16* BufPrmPrdDataRIK_tpo1 = (uint16*)(0x60000180 + RIK_WRITE_CMD_LEN_tpo);//&REG_RIK_BUFPRMPRD + RIK_WRITE_CMD_LEN;
//	int32	res;	

	memset(buf0, num0, sizeof(buf0));
//while(1);
uint32 u = 333;

uint32 r = prc_disable();


save = EMIFB_CECTL0;
EMIFB_CECTL0 = save | (0xFFC00000);
save = EMIFB_CESEC0;
EMIFB_CESEC0 = save | (b << 6);
//save = EMIFB_GLBCONT;
//EMIFB_GLBCONT = (save & 0xFFF3FFFF) | (b << 18);


while(true)
{
u = 800;
while(u--)
{
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
}

BufPrmPrdDataRIK_tpo[0] = 0xFFFF;
BufPrmPrdDataRIK_tpo1[0] = 0xFFFF;
BufPrmPrdDataRIK_tpo1[0] = 0xFFFF;
BufPrmPrdDataRIK_tpo1[0] = 0xFFFF;
BufPrmPrdDataRIK_tpo1[0] = 0xFFFF;
BufPrmPrdDataRIK_tpo1[0] = 0xFFFF;
BufPrmPrdDataRIK_tpo1[0] = 0xFFFF;
BufPrmPrdDataRIK_tpo1[0] = 0xFFFF;
BufPrmPrdDataRIK_tpo1[0] = 0xFFFF;
BufPrmPrdDataRIK_tpo1[0] = 0xFFFF;
BufPrmPrdDataRIK_tpo1[0] = 0xFFFF;
BufPrmPrdDataRIK_tpo1[0] = 0xFFFF;
BufPrmPrdDataRIK_tpo1[0] = 0xFFFF;
BufPrmPrdDataRIK_tpo1[0] = buf0[0];

}

}
*/



void alp_pp_plis(int reader, uint8 num0, uint8 num1, int delay)
{

	uint16 			buf0[C_MAX_BLOCK_LENGTH_tpo];
	uint32		save = 0;
	uint32		b = 1;
//   uint16* BufPrmPrdRIK_tpo     = (uint16*)(0x60000080);//&REG_RIK_BUFPRMPRD;
    uint16* BufPrmPrdDataRIK_tpo = (uint16*)(0x60000080 + RIK_WRITE_CMD_LEN_tpo);//&REG_RIK_BUFPRMPRD + RIK_WRITE_CMD_LEN;
    uint16* BufPrmPrdDataRIK_tpo1 = (uint16*)(0x60000180 + RIK_WRITE_CMD_LEN_tpo);//&REG_RIK_BUFPRMPRD + RIK_WRITE_CMD_LEN;
//	int32	res;	

	memset(buf0, num0, sizeof(buf0));
//while(1);
uint32 u = 333;

uint32 r = prc_disable();


save = EMIFB_CECTL0;
EMIFB_CECTL0 = save | (0xFFC00000);
save = EMIFB_CESEC0;
EMIFB_CESEC0 = save | (b << 6);
//save = EMIFB_GLBCONT;
//EMIFB_GLBCONT = (save & 0xFFF3FFFF) | (b << 18);


EN |= 0x1000;
DIR |= 0x1000;
//VAL |= 0x1000;

while(true)
{
u = 800;
while(u--)
{
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
}
VAL |= 0x1000;

BufPrmPrdDataRIK_tpo[0] = 0xFFFF;
BufPrmPrdDataRIK_tpo1[0] = 0xFFFF;
BufPrmPrdDataRIK_tpo1[0] = 0xFFFF;
BufPrmPrdDataRIK_tpo1[0] = 0xFFFF;
BufPrmPrdDataRIK_tpo1[0] = 0xFFFF;
BufPrmPrdDataRIK_tpo1[0] = 0xFFFF;
BufPrmPrdDataRIK_tpo1[0] = 0xFFFF;
BufPrmPrdDataRIK_tpo1[0] = 0xFFFF;
BufPrmPrdDataRIK_tpo1[0] = 0xFFFF;
BufPrmPrdDataRIK_tpo1[0] = 0xFFFF;
BufPrmPrdDataRIK_tpo1[0] = 0xFFFF;
BufPrmPrdDataRIK_tpo1[0] = 0xFFFF;
BufPrmPrdDataRIK_tpo1[0] = 0xFFFF;
BufPrmPrdDataRIK_tpo1[0] = 0xFFFF;






u = 800;
while(u--)
{
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
}
VAL ^= 0x1000;

BufPrmPrdDataRIK_tpo[0] = 0xFFFF;
BufPrmPrdDataRIK_tpo1[0] = 0xFFFF;
BufPrmPrdDataRIK_tpo1[0] = 0xFFFF;
BufPrmPrdDataRIK_tpo1[0] = 0xFFFF;
BufPrmPrdDataRIK_tpo1[0] = 0xFFFF;
BufPrmPrdDataRIK_tpo1[0] = 0xFFFF;
BufPrmPrdDataRIK_tpo1[0] = 0xFFFF;
BufPrmPrdDataRIK_tpo1[0] = 0xFFFF;
BufPrmPrdDataRIK_tpo1[0] = 0xFFFF;
BufPrmPrdDataRIK_tpo1[0] = 0xFFFF;
BufPrmPrdDataRIK_tpo1[0] = 0xFFFF;
BufPrmPrdDataRIK_tpo1[0] = 0xFFFF;
BufPrmPrdDataRIK_tpo1[0] = 0xFFFF;
BufPrmPrdDataRIK_tpo1[0] = buf0[0];

}

}

	

	
//-------------------------------------------------------------
//-------------------------------------------------------------



void alp_mcbsp(int reader, uint8 num0, uint8 num1, int delay)
{

	uint32 			buf0[1];

//	int32	res;	

	uint32 u = 0;

	buf0[0] = 0xFFFFFF00 | num0;
//	memset(buf0, num0, sizeof(buf0));

uint32 FileMCBS1 = drv_mkd("/dev/mcbsp");

	res_share(FileMCBS1);
	drv_open(FileMCBS1,DRV_RD|DRV_WR);

	u = MCBSP2_SPCR;
    MCBSP2_SPCR = u | 0x10000;
//    MCBSP_enableXmt(h_out);



uint32 r = prc_disable();

while(true)
{
u = 256;
while(u--)
{
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
}

alp_sinhrosig();

u = 450;
while(u--)
{
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
}

TXD_MCBSP2 = buf0[0];

}

}

/*
void alp_mcbsp(int reader, uint8 num0, uint8 num1, int delay)
{

	uint32 			buf0[1];

//	int32	res;	

	uint32 u = 0;

	buf0[0] = 0xFFFFFF00 | num0;
//	memset(buf0, num0, sizeof(buf0));

uint32 FileMCBS1 = drv_mkd("/dev/mcbsp");

	res_share(FileMCBS1);
	drv_open(FileMCBS1,DRV_RD|DRV_WR);

	u = MCBSP2_SPCR;
    MCBSP2_SPCR = u | 0x10000;
//    MCBSP_enableXmt(h_out);

EN |= 0x1000;
DIR |= 0x1000;
//VAL |= 0x1000;



uint32 r = prc_disable();

while(true)
{
u = 256;
while(u--)
{
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
}

VAL |= 0x1000;
alp_sinhrosig();

u = 450;
while(u--)
{
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
}

TXD_MCBSP2 = 0xFFFFFFFF;
//drv_write(FileMCBS1,buf0, sizeof(buf0));




u = 256;
while(u--)
{
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
}

VAL ^= 0x1000;
alp_sinhrosig();

u = 450;
while(u--)
{
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
}

TXD_MCBSP2 = 0xFFFFFFFE;

}

}
*/

void ALP_DISPL(cs_menu* m, void* arg)
{

uint32* exit = (uint32*)arg;
*exit = 1;
uint16 KEY = 0;
sleep_s(1);

con_clrscr(SYS_CON);

	while(1)
	{
	clrscr();
	KEY = 0;
	KEY = getch();
	KEY &= 0xFF;
	if(KEY == KEY_ENTER)
	break;
	}

	while(1)
	{
	clrscr();

  	gotoxy(0,0);
	for(int i = 0; i<16; i++)
	{ 
	int j = 14;

	 set_text_attribute(j,i,1,ATTR_REVERSE); 

	}
//	sleep_s(3);
	KEY = 0;
	KEY = getch();
	KEY &= 0xFF;
	if(KEY == KEY_ENTER)
	break;
	}

	while(1)
	{
	clrscr();

  	gotoxy(0,0);
	int i = 7;
		 
//	for(int j = 0; j<30; j+=2)
	set_text_attribute(0,i,7,ATTR_REVERSE); 

	KEY = 0;
	KEY = getch();
	KEY &= 0xFF;
	if(KEY == KEY_ENTER)
	break;
	if(KEY == KEY_ESC)
	return;
	}

	while(1)
	{
	clrscr();

  	gotoxy(0,0);
	int i = 7;
		 
//	for(int j = 0; j<30; j+=2)
	set_text_attribute(0,i,15,ATTR_REVERSE); 

	KEY = 0;
	KEY = getch();
	KEY &= 0xFF;
	if(KEY == KEY_ENTER)
	break;
	if(KEY == KEY_ESC)
	return;
	}


	while(1)
	{
	clrscr();

  	gotoxy(0,0);
	int i = 7;
		 
//	for(int j = 0; j<30; j+=2)
	set_text_attribute(0,i,23,ATTR_REVERSE); 

	KEY = 0;
	KEY = getch();
	KEY &= 0xFF;
	if(KEY == KEY_ENTER)
	break;
	if(KEY == KEY_ESC)
	return;
	}


	while(1)
	{
	clrscr();

  	gotoxy(0,0);
	int i = 7;
		 
//	for(int j = 0; j<30; j+=2)
	set_text_attribute(0,i,30,ATTR_REVERSE); 

	KEY = 0;
	KEY = getch();
	KEY &= 0xFF;
	if(KEY == KEY_ENTER)
	break;
	if(KEY == KEY_ESC)
	return;
	}

}


//-------------------------------------------------------------
//-------------------------------------------------------------

int32 asci_to_hex(uint32 ch)//от 'a' до 'f' 
{
switch(ch)
{
	case 'a': return 0xa;
	case 'b': return 0xb;
	case 'c': return 0xc;
	case 'd': return 0xd;
	case 'e': return 0xe;
	case 'f': return 0xf;
	default:  return 0;
}
}

// --- Взятие шестнадцатиричного числа -----------------------------------------------------------
uint32 getheximal(uint32 decade)
{
  int32  ch;
  int32  hexnumber = 0;
  bool redy;
//  uint32 i=(decade-1);

if((decade<1)|(decade>8))
return KEY_ESC;

  
for(int i = 0; i<decade; i++)
{
  redy = false;
  do
  {
  	ch = getch();
      if(('0'<=ch)&&(ch<='9'))
      {
        putch(ch);
        ch -= 0x30;
        hexnumber |= ((ch&0xf) << ((decade-i-1)*4));
        redy = true;
      }
	  else if(('a'<=ch)&&(ch<='f'))
	  {
        putch(ch);
		hexnumber |= ((asci_to_hex(ch)&0xf) << ((decade-i-1)*4));
        redy = true;
	  }
      else if(ch == KEY_ESC)
        return KEY_ESC;
   }while(!redy);
}

 return hexnumber;   
}




void send_main_start_sialp(kdg_sialp* par)
{

kdg_cmd		to_main;
kdg_cmd_ask	cdg_error;
int32		error;

  to_main.cmd = START_SIALP;
  msg_send(msg_pid_main, &to_main, sizeof(kdg_cmd));
  error = receive_msg(&cdg_error, sizeof(kdg_cmd_ask), SEM_INFINITY);
  if(error == TPO_OK)
  {
	  msg_send(msg_pid_main, par, sizeof(kdg_sialp));
  	  error = receive_msg(&cdg_error, sizeof(kdg_cmd_ask), SEM_INFINITY);
	  if(error == TPO_OK)
	  {
	  gotoxy(0,9);
	  putstr("          Идет тест        ");
	  set_text_attribute(0,9,30,ATTR_BLINK_REVERSE); 
	  }
	  else
	  while(1);// print error

  }
  else
  while(1);// print error


}


void send_comm_start_sialp(kdg_sialp* par)
{

kdg_cmd		to_comm;
kdg_cmd_ask	cdg_error;
int32		error;

  to_comm.cmd = START_SIALP;
#ifdef TPO5
  msg_send(pid_comm[0].pid, &to_comm, sizeof(kdg_cmd));
#else
  msg_send(pid_comm[1].pid, &to_comm, sizeof(kdg_cmd));
#endif
  error = receive_msg(&cdg_error, sizeof(kdg_cmd_ask), SEM_INFINITY);
  if(error == TPO_OK)
  {
#ifdef TPO5
	  msg_send(pid_comm[0].pid, par, sizeof(kdg_sialp));
#else
  	  msg_send(pid_comm[1].pid, par, sizeof(kdg_sialp));
#endif
  	  error = receive_msg(&cdg_error, sizeof(kdg_cmd_ask), SEM_INFINITY);
	  if(error == TPO_OK)
	  {
	  gotoxy(0,9);
	  putstr("          Идет тест        ");
	  set_text_attribute(0,9,30,ATTR_BLINK_REVERSE); 
	  }
	  else
	  while(1);// print error

  }
  else
  while(1);// print error
}
