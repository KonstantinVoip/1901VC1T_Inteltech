/**********************************************************************************************************************
*                                        (c) COPYRIGHT by ZAO RCZI FORT.                                             *
*        ..                                       All rights reserved.                                               *
***********************************************************************************************************************
* Module      : test_i.cpp
* Description : Тестовые функции ИП (Интерфейсного Процессора) для TPO5,TPO6,TPO7
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








#include <os.h>
#include <drv_dbgout.h>
#include <__fs.h>
#include <drv_usbms.h>
#include <rts.h>
#include <drv_vfat.h>
#include <drv_fwmem.h>

#include "tests.h"
#include "tpo.h"
#include "tpo_hash.h"
#include "mem_fpga.iface15.h"
#include "mem_test.h"
#include "drv_rtc.h"
#include "drv_rik.h"
#include "drv_lcd.h"
	//#include "drv_usb.h"


#include "tpo_iface.h"
	/*
	#ifdef TPO5
	#include "tpo_iface_5.h"
	#endif

	#ifdef TPO7
	#include "tpo_iface_7.h"
	#endif
	*/
#define REG_RIK_STATUS_tpo						(*(uint16 *)0x6000004C)
#define REG_RND_NUMBER_tpo						(*(uint16 *)0x6000002A)
#define REG_DEVICE_STATUS_tpo					(*(uint16 *)0x60000020)
#define REG_RND_RESET_tpo						(*(uint16 *)0x60000024)
#define REG_NMI_CONTROL_tpo						(*(uint16 *)0x60000034)
#define REG_SENSOR_POWER_CONTROL_tpo			(*(uint16 *)0x60000038)

#define Y_WAIT_LINE         5
#define Y_LAST_LINE         15



//Вынес Пашкины define из глубин  сознания

#define RANDOM_INTERVALS (16)
#define RANDOM_VALUES (512)
#define NL ( (RANDOM_VALUES*2)/RANDOM_INTERVALS)



extern void UserRikEvent(uint16 rik_status);



/////


char* TPO_ERROR[]=
{
	"ЦП не отвечает",
	"CП0 не отвечает",
	"CП1 не отвечает",
	"CП2 не отвечает",
	"CП3 не отвечает",

	"Ошибка обмена с ЦП",
	"Ошибка обмена с ЦП(Рез.цикл)",

	"Ошибка обмена с CП0",
	"Ошибка обмена с CП1",
	"Ошибка обмена с CП2",
	"Ошибка обмена с CП3",

	"Ошибка драйвера",
	"Ошибка msg_open",

	"Ошибка выделения памяти CП0",
	"Ошибка выделения памяти CП1",
	"Ошибка выделения памяти ЦП"

};




#define print_err(proc,n)  {T_clrbar(6);\
							T_clrbar(7);\
							con_gotoxy(SYS_CON,0,6);\
                   			con_putstr(SYS_CON, proc);\
                   			con_set_text_attribute(SYS_CON,0,6,30,ATTR_BLINK_REVERSE);\
							con_gotoxy(SYS_CON,0,7);\
			                con_putstr(SYS_CON, TPO_ERROR[n]);\
			                con_set_text_attribute(SYS_CON,0,7,30,ATTR_BLINK_REVERSE);\
						    getch();\
							con_clrbar(SYS_CON,6,30);\
							con_clrbar(SYS_CON,7,30);}\


//extern void FS_REINIT_LOCK();
//extern void FS_REINIT_UNLOCK();



extern hash_window hwindow[];
//extern char* NameTests[];

extern uint32 msg_pid_main;
extern comm_status pid_comm[];

extern void put_end_line(const char* str, int32 key);
extern void put_str_center(int32 y, const char* str);

extern void load_lif(void* mem_lif);
extern void Send_cmd_main(uint32 cmd);

const char* _put_esc_exit = "<ESC> - Выход";
const char* _put_esc_stop = "<ESC> - Стоп";



/*****************************************************************************
Syntax: int32 tpo_msg_discover()     	    
Remarks:			    
*******************************************************************************/
int32 tpo_msg_discover()
{
    int32  error, key;
    char   name[6];

    clrscr();

	key = 0x10000000;
	while(key--);
	//key = 0x80000000;
	//while(key--);

    error = msg_open("tpo");
	if(error != OSE_OK)
	{
		print_err("IFACE", ERR_MSG_OPEN);
		return -1;
	}

	msg_pid_main = msg_discover("main", "tpo", 30000);
	
	if(msg_pid_main == RES_VOID)
	{
	print_err("IFACE", MAIN_TIME_OUT);
	return -1;
	}

	for(int i = MIN_NUMBER_COMM; i < NUMBER_COMM_DSP; i++)
	{
		sprintf(name, "comm%d", i);

		pid_comm[i].N = i;
		pid_comm[i].pid = msg_discover(name, "tpo", MSG_WAIT_5);
		if(pid_comm[i].pid == RES_VOID)
		{
			print_err("IFACE", COMM_TIME_OUT + i);
			return -1;
		}

	}
	
return 0;
}




/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
int32 receive_msg(void* recev, int32 length, uint32 ms)
{
  s_message*  		msg_desc;
  int32 error;

  error = msg_recv( &msg_desc, ms);

  if( (error != OSE_OK)||(msg_desc == NULL) )
  {
    return MSG_ER_TIME_OUT;
  }
  if(msg_desc->length != length)
  {
    msg_free(msg_desc);
    return MSG_ER_SYNC;
  }

  memcpy(recev, msg_desc->data, length);
  msg_free(msg_desc);
  return TPO_OK;

}


/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
void Send_cmd_main(uint32 cmd)
{

	kdg_cmd		to_main;
	kdg_cmd_ask	cdg_error;
	int32		error;

    to_main.cmd = cmd;

    msg_send(msg_pid_main, &to_main, sizeof(kdg_cmd));
    error = receive_msg(&cdg_error, sizeof(kdg_cmd_ask), MSG_WAIT_DEBUG);

	if(error == TPO_OK)
	    return;
	if(error == MSG_ER_TIME_OUT)
	    print_err("IFACE", MAIN_TIME_OUT);
	if(error == MSG_ER_SYNC)
		print_err("IFACE", MAIN_ERR_MSG);
}

/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
void Send_cmd_comm(uint32 n_comm, uint32 cmd)
{

kdg_cmd		to_comm;
kdg_cmd_ask	cdg_error;
int32		error;

  to_comm.cmd = cmd;

  msg_send(pid_comm[n_comm].pid, &to_comm, sizeof(kdg_cmd));
  error = receive_msg(&cdg_error, sizeof(kdg_cmd_ask), MSG_WAIT_DEBUG);

  if(error == TPO_OK)
    return;
  if(error == MSG_ER_TIME_OUT)
	print_err("IFACE", COMM_TIME_OUT+n_comm);
  if(error == MSG_ER_SYNC)
	print_err("IFACE", COMM_ERR_MSG+n_comm);

}



/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
int32 flash_chip_clear()
{
  volatile uint8& REG_555 = (*(uint8*)(0x64000000 + 0x00000555 ));
  volatile uint8& REG_AAA = (*(uint8*)(0x64000000 + 0x00000aaa ));
//  uint32 offset;
  volatile uint8 tgl0, tgl1;

  REG_AAA = 0xaa;
  REG_555 = 0x55;
  REG_AAA = 0x80;
  REG_AAA = 0xaa;
  REG_555 = 0x55;
  REG_AAA = 0x10;
  
  volatile uint8& REG_DATA = (*(uint8*)0x64000000);

  tgl1 = REG_DATA;
  while( true )
  {
    tgl0 = REG_DATA;
    if( ( ( tgl0 ^ tgl1 ) & 0x44 ) == 0x00 ) break;
    if( ( tgl0 & 0x28 ) == 0x28 )
    {
      tgl1 = REG_DATA;
      tgl0 = REG_DATA;
      if( ( ( tgl0 ^ tgl1 ) & 0x44 ) == 0x00 ) break;
      REG_DATA = 0xf0;
      return 1;
    }
    tgl1 = tgl0;
  }

  return OSE_OK;
}


/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
uint32 Load_po_pp()
{

	int res = 0;
	
    char	file_path[32];
	uint8   buf[1024];
    FILE*	file;


  int32          fwm_file;
  s_fwmem_rwbuf  fwrw;

	fwrw.buffer = buf;
	fwrw.length = 1024;

	fwm_file = RES_VOID;


   	strcpy(file_path, "/vfat/a/iface.bin");

    file = fopen(file_path, "rb");
    if(file == NULL)
		return 1;

	if(flash_chip_clear())
	{
		fclose(file);
		return 1;
	}

	fwm_file = drv_mkd("/fwmem");
	if(fwm_file == RES_VOID)
	{
		fclose(file);
		return 1;
	}
	
for(int i=0; i<1024; i++)
{

	res = fread(buf, 1, sizeof(buf), file);
	if(res != sizeof(buf))
	{
	drv_rmd(fwm_file);
	fclose(file);
	return 1;
	}

	res = drv_ioctl(fwm_file, FWMEM_WRITE, &fwrw);
	if(res)
	{
	drv_rmd(fwm_file);
	fclose(file);
	return 1;
	}

}


drv_rmd(fwm_file);
fclose(file);

return 0;
}


/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/

uint32 Load_po_main()
{

	int res = 0;
	
    char	file_path[32];
	uint8   buf[1024];
    FILE*	file;

	kdg_cmd_ask	cdg_error;
	int32		error;

//	fwm_file = RES_VOID;


   	strcpy(file_path, "/vfat/a/main.bin");

    file = fopen(file_path, "rb");
    if(file == NULL)
		return 1;

	Send_cmd_main(START_LOAD_PO);
	
for(int i=0; i<2048; i++)
{

	res = fread(buf, 1, sizeof(buf), file);
	if(res != sizeof(buf))
	{
	fclose(file);
	return 1;
	}


	msg_send(msg_pid_main, buf, sizeof(buf));
	error = receive_msg(&cdg_error, sizeof(kdg_cmd_ask), MSG_WAIT_DEBUG);

}


msg_send(msg_pid_main, buf, 32);
//drv_rmd(fwm_file);
fclose(file);
return 0;

}
/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
uint32 Load_po_comm()
{

	int res = 0;
	
    char	file_path[32];
	uint8   buf[1024];
    FILE*	file;

	kdg_cmd_ask	cdg_error;
	int32		error;

//	fwm_file = RES_VOID;


   	strcpy(file_path, "/vfat/a/comm.bin");

    file = fopen(file_path, "rb");
    if(file == NULL)
		return 1;

	Send_cmd_comm(0, START_LOAD_PO);
	Send_cmd_comm(1, START_LOAD_PO);
	
for(int i=0; i<2048; i++)
{

	res = fread(buf, 1, sizeof(buf), file);
	if(res != sizeof(buf))
	{
	fclose(file);
	return 1;
	}


	msg_send(pid_comm[0].pid, buf, sizeof(buf));
	error = receive_msg(&cdg_error, sizeof(kdg_cmd_ask), MSG_WAIT_DEBUG);

	msg_send(pid_comm[1].pid, buf, sizeof(buf));
	error = receive_msg(&cdg_error, sizeof(kdg_cmd_ask), MSG_WAIT_DEBUG);
}

	msg_send(pid_comm[0].pid, buf, 32);
	msg_send(pid_comm[1].pid, buf, 32);

fclose(file);
return 0;

}

/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/

uint32 Load_plis_sialp()
{

	int res = 0;
	
    char	file_path[32];
	uint8   buf[1024];
    FILE*	file;

	kdg_cmd_ask	cdg_error;
	int32		error;

//	fwm_file = RES_VOID;


   	strcpy(file_path, "/vfat/a/sv5_si.bin");

    file = fopen(file_path, "rb");
    if(file == NULL)
		return 1;

	Send_cmd_main(WRITE_PO_TO_FLASH);
	
do
{

	res = fread(buf, 1, sizeof(buf), file);
	if(res == 0)
	{
	fclose(file);
	return 1;
	}

	msg_send(msg_pid_main, buf, res);
	error = receive_msg(&cdg_error, sizeof(kdg_cmd_ask), MSG_WAIT_DEBUG);

}
while(res == sizeof(buf));

//msg_send(msg_pid_main, buf, 32);
//drv_rmd(fwm_file);
fclose(file);
return 0;

}




/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
uint32 Receve_Res_Cikl(uint32* data, uint32 Otsvetka)
{
kdg_rez_test rezult;
int32		error;


  Send_cmd_comm(MIN_NUMBER_COMM, GOTOV_PP);

  error = receive_msg(&rezult, sizeof(kdg_rez_test), MSG_WAIT_DEBUG);
  if(error == TPO_OK)
  {
	if(rezult.cmd == RES_N_TEST)
	{
		if(rezult.n_test == CIKL)
		{
		Send_cmd_main(GOTOV_PP);
			switch(Otsvetka)
			{
				case FIRST_CH:
				memcpy(data, &rezult.data, sizeof(rezult.data));
				break;

				case SECOND_CH:
				memcpy(data, &rezult.data1, sizeof(rezult.data1));
				break;

				case TWO_CH:
				{
				rezult.rez = rezult.data | rezult.data1;
				memcpy(data, &rezult.rez, sizeof(rezult.rez));
				}
				break;
			}
		error = receive_msg(&rezult, sizeof(kdg_rez_test), MSG_WAIT_10);

		if(rezult.err != TPO_OK)
		{
			print_err("MAIN", rezult.err);
			return CIKL_NOT_READY;
		}


		return CIKL;
		}

		if(rezult.n_test == CIKL_NOT_READY)
		return CIKL_NOT_READY;
	}
  }

	print_err("IFACE", MAIN_ERR_MSG_CICL_RES);
return CIKL_NOT_READY;
}






/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
uint16 F_reserved()
{
return 0;
}



/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
uint16 F_TEST_CMP_PP()
{
	F_TestProgress(1);
	return 1;
}                



/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
uint16 F_test_ram()
{
    uint32 res = 0;
    
	F_TestProgress(1);

//	uint32 ErrorsPositions;
//	uint32 ErrorAddress;
//debug!!!!!!!!!1
//	res = uniTestSDRAM( &ErrorsPositions, &ErrorAddress);
//debug!!!!!!!!!1

    res = sdram_test_base();    
    
	return res == 0 ? 0 : 1;
}


/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
uint16 F_hash_comp()
{
    uint32 res = 0;
//    uint32 ret = 3;

	F_TestProgress(1);

	res = analysis_hash_fwmem(hwindow);

	return res == 0 ? 0 : 1;
}


/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
uint16 F_test_rtc()
{
    int res = 0;
    
	F_TestProgress(1);

    res = rtc_test_base();
    
	return res == 0 ? 0 : 1;
}

/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
uint16 F_test_power_sensor()
{
    int res = 0;

	F_TestProgress(1);

    res = power_test_base();
    
	return res == 0 ? 0 : 1;
}

/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
uint16 F_test_access_sensor_verh()
{
    int res = 0;

	F_TestProgress(1);

    res = access_test_base(VERH_DATCHIK);
    
//debug!!!!!!!!
//res=0;
	return res == 0 ? 0 : 1;
}

/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
uint16 F_test_access_sensor_niz()
{
    int res = 0;

	F_TestProgress(1);

    res = access_test_base(NIJN_DATCHIK);
    
//debug!!!!!!!!
//res=0;
	return res == 0 ? 0 : 1;
}

/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
uint16 F_test_access_sensor_rik()
{
    int res = 0;

	F_TestProgress(1);

    res = access_test_rik_door();
    
	return res == 0 ? 0 : 1;
}

/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
uint16 F_test_usbc()
{
    int res = 0;
    
	F_TestProgress(1);

    res = usb_test_base();
    
	return res == 0 ? 0 : 1;
}

/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
uint16 F_test_usb_flash1()
{
    int res = 0;

	F_TestProgress(1);

    res = usb_test_rw(1, 0x55, 0);
    
	return res == 0x300 ? 0 : 1;
}

/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
uint16 F_test_usb_flash2()
{
    int res = 0;

	F_TestProgress(1);

    res = usb_test_rw(2, 0xAA, 0);
    
	return res == 0x300 ? 0 : 1;
}

#define REG_SCRATCH_TPO					(*(uint16 *)0x60000030)

/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
uint16 F_test_PU()
{

    int res = 0;

	F_TestProgress(1);

    res = test_pu();
    
	return res == 0 ? 0 : 1;

}


/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
uint16 F_test_rik1()
{
    int res = 0;
	
	F_TestProgress(1);

//	drv_select(File_rik, "rik1");

    res = rik_test_card(1);
    
	return res == 0 ? 0 : 1;
}

/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
uint16 F_test_rik2()
{
    int res = 0;

	F_TestProgress(1);

//	drv_select(File_rik, "rik2");

    res = rik_test_card(2);
    
	return res == 0 ? 0 : 1;
}

/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
uint16 F_test_random1()
{
    int res = 0;

	F_TestProgress(1);

	res = random_test_base(0);

	return res == 0 ? 0 : 1;
}

/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
uint16 F_test_random2()
{
    int res = 0;

	F_TestProgress(1);

	res = random_test_base(1);

	return res == 0 ? 0 : 1;
}

/*
//-------------------------------------------------------------------------------------------------
#ifdef MCBSP_TEST
uint16 F_test_mcbsp()
{
    int res = 0;

	F_TestProgress(1);

	res = mcbsp_test_rw();

	return res == 0 ? 0 : 1;
}
#endif
*/


/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
int sdram_test_base(void)
{

uint32 save_buf[SDRAM_BLOK_LEN/SDRAM_WIDTH];
uint32 a = SDRAM_START_ADDR;				
uint32* addr = (uint32*)a;
uint32* save_addr;
uint32 int_old = 0;

int i = 0;

int_old = int_disable();
save_addr = addr;
memcpy(save_buf, save_addr, sizeof(save_buf));

*addr = 0x55555555;
	if(*addr != 0x55555555)
		goto sdram_error;
*addr = 0xAAAAAAAA;
	if(*addr != 0xAAAAAAAA)
		goto sdram_error;

memcpy(save_addr, save_buf,sizeof(save_buf));
int_enable(int_old);	

	for(i = 0; i < (SDRAM_LEN/SDRAM_BLOK_LEN); i++)
	{
		int_old = int_disable();
		save_addr = addr + (i * sizeof(save_buf))/SDRAM_WIDTH;
		memcpy(save_buf, save_addr, sizeof(save_buf));

		for(int j = i*(SDRAM_BLOK_LEN/SDRAM_WIDTH); j < ((i+1)*(SDRAM_BLOK_LEN/SDRAM_WIDTH)); j++)
		{
		addr[j] = j & 0xFFFFFFFF;
		}

		for(int j = i*(SDRAM_BLOK_LEN/SDRAM_WIDTH); j < ((i+1)*(SDRAM_BLOK_LEN/SDRAM_WIDTH)); j++)
		{
			if(addr[j] != j & 0xFFFFFFFF)
			goto sdram_error;
		}

		memcpy(save_addr, save_buf,sizeof(save_buf));
		int_enable(int_old);	
	}

return TPO_OK;

sdram_error:

	memcpy(save_addr, save_buf,sizeof(save_buf));
	int_enable(int_old);	
	return TPO_ERR;
}    



/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
int test_pu(void)
{
	uint32 error;

	uint64 bits_error;

	error = uniMemoryCellTest((uint32)&REG_SCRATCH_TPO , &bits_error, 16);


	if(!error)		//если ошибка
	return bits_error; 

	return 0;
}


#define RND_REDY		(REG_DEVICE_STATUS_tpo & 0x8)

/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
uint16 random(uint16 channel)
{
	uint16	rnd_value;

	while(!RND_REDY);
	rnd_value = REG_RND_NUMBER_tpo;
	REG_RND_RESET_tpo = 0x1;
	if(!channel)
	return rnd_value&0xFF;
	else
	return (rnd_value>>8)&0xFF;
}




/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
int random_test_hi(int channel)
{

	uint16 random_buf[RANDOM_VALUES];
	uint16 interv[RANDOM_INTERVALS];


	memset(interv,0,sizeof(interv));


		for (int i = 0; i < RANDOM_VALUES; i++)
		{
			uint16 r = random(channel);
			random_buf[i] = r;
		}

	//float Max_NL = (NL)*(24.996);
	uint32 Max_NL = (NL)*25;
	uint32 sum = 0;
	uint32 sum1 = 0;


		for(int j = 0; j < RANDOM_VALUES; j++)
		{
		interv[random_buf[j]&0xf]++;
		random_buf[j]>>=4;
		interv[random_buf[j]&0xf]++;
		}

		for (int i = 0; i < RANDOM_INTERVALS; i++)
		{
		  sum1 = interv[i]-NL;	
		  sum += sum1 * sum1;
		}
	if(sum < Max_NL)
	return 0;	//OK

	return 1;
}

/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
int random_test_base(int channel)
{
    int status = random_test_hi(channel);

    return status == 0 ? 0 : 1;
}



/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
int rtc_test_base()
{
	int error;
	uint32 FileRTC   = drv_mkd("/dev/rtc/");
	uint32 time0 = 0, time1 = 0;

	error = drv_ioctl(FileRTC, RTC_GET_TIME, &time0);

	//uint32 t = 0x12800000;
	uint32 t = 0x13000000;//13.07.17
	while(t--);

	error = drv_ioctl(FileRTC, RTC_GET_TIME, &time1);

	drv_rmd(FileRTC);

	 if(error == OSE_OK)
	 {
		if(time0 < time1)
		return 0;	//OK
	 }
	return 1;
}




/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
int usb_test_base()
{

	uint32 error;

	uint64 bits_error;



	uint32 addr_scretch_reg = 0x80000610;
	uint32 *addr_chip_id    = (uint32*)0x80000608;

	uint16 *addr_chip_id_nec   = (uint16*)0x6C000000;
	uint16 *addr_chip_cfg_nec   = (uint16*)0x6C000006;
	uint32 addr_scretch_reg_nec = 0x6C0001B0;
	uint16 iiiddd = 0;

	iiiddd = *addr_chip_id_nec;
	if(iiiddd == 0x0120)
	{
		*addr_chip_cfg_nec |= 0x4;
			error = uniMemoryCellTest(addr_scretch_reg_nec , &bits_error, 16);
		*addr_chip_cfg_nec &= ~0x4;;
				if(!error)		
					return 0; 
	}



	if(*addr_chip_id != 0x00011761)
	return 1; 

	error = uniMemoryCellTest(addr_scretch_reg , &bits_error, 32);

	if(!error)		//если ошибка
	return bits_error; 


return 0;
}




//-------------------------------------------------------------------------------------------------
int rik_test_card(int card)
{

int32			zone, offset;
s_rik_reset		rik_reset;
//s_inode* 		list;

	uint8 			buf0[32];
	uint8 			buf1[32];

	memset(buf0, 0, sizeof(buf0));
	memset(buf1, 0, sizeof(buf1));

	for(uint8 ch=0; ch<sizeof(buf0); ch++)
	buf0[ch]=ch;


	uint32 File_r = drv_mkd("/dev/rik/");
		if(File_r == NULL)
		return 1;
	  
	 //Выбор РИК:
	if(card == 1)
	  drv_select(File_r, "rik1");
	else
	  drv_select(File_r, "rik2");


	if(drv_ioctl(File_r, RIK_GET_RESET_STRUCT, &rik_reset) != OSE_OK)
		goto ret_rik_err;
	

	if(drv_open(File_r, DRV_WR|DRV_RD) != OSE_OK)
		goto ret_rik_err;

	zone = 0x1;
	if(drv_ioctl(File_r, RIK_SET_ZONE, &zone) != OSE_OK)
		goto ret_rik_err;

	offset = 0;

	if(drv_ioctl(File_r, RIK_SET_OFFSET, &offset) != OSE_OK)
		goto ret_rik_err;
	if(drv_write(File_r, buf0, sizeof(buf0)) != sizeof(buf0))
		goto ret_rik_err;

	if(drv_ioctl(File_r, RIK_SET_OFFSET, &offset) != OSE_OK)
		goto ret_rik_err;
	if(drv_read(File_r, buf1, sizeof(buf1)) != sizeof(buf1))
		goto ret_rik_err;

	if(drv_close(File_r) != OSE_OK)
		goto ret_rik_err;

	if(memcmp(buf0, buf1, sizeof(buf0)))
		goto ret_rik_err;

	return 0;

ret_rik_err:
	drv_rmd(File_r);
	return 1;

}

//-------------------------------------------------------------------------------------------------
//проверяет закрыта или открыта крышка рик
int access_test_rik_door(void)
{

if(REG_RIK_STATUS_tpo & 0x20)
return 1;				//открыта

return 0;

}


//-------------------------------------------------------------------------------------------------
//проверяет закрыта или открыта крышка прибора
int access_test_base(uint16 datchik)
{
	uint32 int_old = 0;
	int_old = int_disable();

//#define REG_NMI_CONTROL_tpo						(*(uint16 *)0x60000034)
//#define REG_SENSOR_POWER_CONTROL_tpo			(*(uint16 *)0x60000036)
uint16 res = TPO_ERR;

if(REG_DEVICE_STATUS_tpo & datchik)
{
	REG_NMI_CONTROL_tpo = 0x8;
	sleep_m(100);
	REG_SENSOR_POWER_CONTROL_tpo = 1;
	sleep_m(100);
	res = REG_DEVICE_STATUS_tpo & datchik;
	REG_SENSOR_POWER_CONTROL_tpo = 0;
	REG_NMI_CONTROL_tpo = 0x8;
	sleep_m(100);
	REG_NMI_CONTROL_tpo = 0x1;
}

 int_enable(int_old);

return res == 0 ? TPO_OK : TPO_ERR;
//return TPO_ERR;
}


//-------------------------------------------------------------------------------------------------
//проверяет закрыта или открыта панель управления
int power_test_base(void)
{

if(REG_DEVICE_STATUS_tpo & 0x4)
	return 0;				//открыта

return 1;				

}


#define 	CREATE_OK		0x100
#define 	OPEN_OK			0x200

#define 	CREATE_FILE		0x01
#define 	OPEN_FILE		0x02
#define 	WRITE_FILE		0x04
#define 	READ_FILE		0x08
#define 	CMP_FILE		0x10

//-------------------------------------------------------------------------------------------------
int usb_test_rw(uint32 dev, uint32 n, uint32 Otsvetka)
{
	int res = 0;

    char	file_path[32];
	char    number[4];
    FILE*	file;

    char	buf_wr[1024];
    char	buf_rd[1024];

	for(int i=0;i<sizeof(buf_wr);i++ )
	buf_wr[i]= n&0xFF;

	memset(buf_rd, 0, sizeof(buf_rd));

	if(dev == 1)
    	strcpy(file_path, "/vfat/a/test");
	if(dev == 2)
    	strcpy(file_path, "/vfat/b/test");

		itoa(n, number);
		strcat(file_path, number);
		strcat(file_path, ".bin");



if(Otsvetka)
cprintf("Создание файла  ");

    file = fopen(file_path, "wb");
    if(file == NULL)
    { 
		res |= CREATE_FILE;
			if(Otsvetka)
			cprintf("- ошибка\n");

	}
	else
	{
		res |= CREATE_OK;
			if(Otsvetka)
			cprintf("- норма \n");
	}

if(Otsvetka)
cprintf("Запись в файл   ");

    if(sizeof(buf_wr) != fwrite(buf_wr, 1, sizeof(buf_wr), file))
	{
		res |= WRITE_FILE;
			if(Otsvetka)
			cprintf("- ошибка\n");

	}
	else
	{
		if(Otsvetka)
		cprintf("- норма \n");
	}


	fclose(file);

if(Otsvetka)
cprintf("Открытие файла  ");

    file = fopen(file_path, "rb");
    if(file == NULL)
    {
    	res |= OPEN_FILE;
			if(Otsvetka)
			cprintf("- ошибка\n");
	}
	else
	{
		res |= OPEN_OK;
			if(Otsvetka)
			cprintf("- норма \n");
	}
if(Otsvetka)
cprintf("Чтение из файла ");

    if(sizeof(buf_rd) != fread(buf_rd, 1, sizeof(buf_rd), file))
	{
		res |= READ_FILE;
			if(Otsvetka)
			cprintf("- ошибка\n");

	}
	else
	{
		if(Otsvetka)
		cprintf("- норма \n");
	}

	fclose(file);

if(Otsvetka)
cprintf("Сравнение       ");

	if(memcmp(buf_wr, buf_rd, sizeof(buf_rd)))
	{
		res |= CMP_FILE;
			if(Otsvetka)
			cprintf("- ошибка\n");

	}
	else
	{
		if(Otsvetka)
		cprintf("- норма \n");
	}


if(Otsvetka)
cprintf("Удаление файла  ");				 

	if(remove(file_path))
	{
		if(Otsvetka)
			cprintf("- ошибка");
	}
	else
	{
		if(Otsvetka)
			cprintf("- норма");
	}

return res;
}



//-------------------------------------------------------------------------------------------------
uint16 LongToBinStr(uint16 value, char *strP, uint16 len)
{

	uint32 Mask;

	for(int CurPos=len-1;CurPos >= 0;CurPos--)
	{
		Mask = (uint32)(1 << CurPos);
		
		if(value & Mask)
			*strP = '1';
		else
			*strP = '0';

		*strP++;
	}	

	*strP = '\0';

	return 0;
}


//-------------------------------------------------------------------------------------------------
int32 PrintResTstRAM(mem_test* param)
//uint32 Res, uint32 ErrorsPosit, uint32 ErrorAddr, uint32 Bus_Width, uint32 Mem_Len)
{

char BusStr[18];

uint16 Bus;

uint32 BusAddrLen = 0;

	if(param->addr)
	{
		while(1)
		{
			if(param->length >> BusAddrLen)
			BusAddrLen++;
			else
			break;
		}

		switch(param->addr)
		{
			case TPO_ERR:
			{
				gotoxy(7,7);
				cprintf("ОШИБКА ОБМЕНА !\n");
			}
			break;

			case TEST_DATA_BUS_ERROR: 
			{
					Bus = (param->ErrPosition & 0xFFFF);
//					Bus = (ErrorsPosit & 0xFFFF);
					memset(BusStr,'.',sizeof(BusStr));
					LongToBinStr(Bus,BusStr,16);
					gotoxy(4,5);
					cprintf("ОШИБКА НА ШИНЕ ДАННЫХ!\n\n");
					cprintf("        Разряды ошибки\n\n");
					cprintf(" (15р)-%s-(0р)\n",BusStr);

					if(param->Width_Bus > 16)
					{
						Bus = ((param->ErrPosition >> 16) & 0xFFFF);
						memset(BusStr,'.',sizeof(BusStr));
						LongToBinStr(Bus,BusStr,16);
						cprintf(" (31р)-%s-(16р)\n",BusStr);
					}

					if(param->Width_Bus > 32)
					{
						Bus = ((param->ErrPosition >> 32) & 0xFFFF);
						memset(BusStr,'.',sizeof(BusStr));
						LongToBinStr(Bus,BusStr,16);
						cprintf(" (47р)-%s-(32р)\n",BusStr);
					}

					if(param->Width_Bus > 48)
					{
						Bus = ((param->ErrPosition >> 48) & 0xFFFF);
						memset(BusStr,'.',sizeof(BusStr));
						LongToBinStr(Bus,BusStr,16);
						cprintf(" (63р)-%s-(48р)\n",BusStr);
					}
			}
			break;
			case TEST_ADDRESS_BUS_ERROR:
			{	
					Bus = (param->ErrAddr & 0xFFFF);
					LongToBinStr(Bus,BusStr,16);
					gotoxy(4,5);                                  
					cprintf("ОШИБКА НА ШИНЕ АДРЕСА!\n\n");            
					cprintf("        Разряды ошибки:\n\n");
					cprintf(" (15р)-%s-( 0р)\n",BusStr);
					
					if(BusAddrLen>16)
					{
						Bus = ((param->ErrAddr >> 16) & 0xFFFF);
						LongToBinStr(Bus,BusStr,16);
						cprintf(" (31р)-%s-(16р)\n",BusStr);
					}
/*
//для порога.
					if(BusAddrLen>32)
					{
						Bus = (m_BusRes.BusErrAddr[1]&0xFFFF);
						LongToBinStr(Bus,BusStr,16);
						cprintf(" (47р)-%s-(32р)\n",BusStr);
					}
					if(BusAddrLen>48)
					{
						Bus = (m_BusRes.BusErrAddr[1]>>16);
						LongToBinStr(Bus,BusStr,16);
						cprintf(" (63р)-%s-(48р)\n",BusStr);					
					}
*/
			}
			break;						
			case TEST_MEMORY_ERROR: 
			{
					Bus = (param->ErrAddr & 0xFFFF);
					LongToBinStr(Bus,BusStr,16);
					gotoxy(4,4);
					cprintf("ОШИБКА ЗАПИСИ/ЧТЕНИЯ \n\n");
					cprintf("    Разряды адреса ошибки:\n");
					cprintf(" (15р)-%s-( 0р)\n",BusStr);

					if(BusAddrLen>16)
					{
						Bus = ((param->ErrAddr >> 16) & 0xFFFF);
						LongToBinStr(Bus,BusStr,16);
						cprintf(" (31р)-%s-(16р)\n",BusStr);
					}


					Bus = (param->ErrPosition & 0xFFFF);
					memset(BusStr,'.',sizeof(BusStr));
					LongToBinStr(Bus,BusStr,16);
//					gotoxy(4,6);
//					cprintf("ОШИБКА НА ШИНЕ ДАННЫХ!\n\n");
					cprintf("\n    Разряды данных ошибки:\n");
					cprintf(" (15р)-%s-( 0р)\n",BusStr);

					if(param->Width_Bus > 16)
					{
						Bus = ((param->ErrPosition >> 16) & 0xFFFF);
						memset(BusStr,'.',sizeof(BusStr));
						LongToBinStr(Bus,BusStr,16);
						cprintf(" (31р)-%s-(16р)\n",BusStr);
					}

					if(param->Width_Bus > 32)
					{
						Bus = ((param->ErrPosition >> 32) & 0xFFFF);
						memset(BusStr,'.',sizeof(BusStr));
						LongToBinStr(Bus,BusStr,16);
						cprintf(" (47р)-%s-(32р)\n",BusStr);
					}

					if(param->Width_Bus > 48)
					{
						Bus = ((param->ErrPosition >> 48) & 0xFFFF);
						memset(BusStr,'.',sizeof(BusStr));
						LongToBinStr(Bus,BusStr,16);
						cprintf(" (63р)-%s-(48р)\n",BusStr);
					}

			}
			break;
			case ERR_DOZU_WRCP0_RDSP: case ERR_DOZU_WRCP1_RDSP: case ERR_DOZU_WRSP_RDCP: case ERR_DOZUMOVE_WRSP_RDSH:
			{
					Bus = (param->ErrAddr & 0xFFFF);
					LongToBinStr(Bus,BusStr,16);
					gotoxy(1,4);                                  

					if(param->addr == ERR_DOZU_WRCP0_RDSP)
						cprintf("ОШИБКА НА ШИНЕ WR_ЦП0-->RD_СП\n");            
					if(param->addr == ERR_DOZU_WRCP1_RDSP)
						cprintf("ОШИБКА НА ШИНЕ WR_ЦП1-->RD_СП\n");            
					if(param->addr == ERR_DOZU_WRSP_RDCP)
						cprintf("ОШИБКА НА ШИНЕ WR_СП-->RD_ЦП\n");            
					if(param->addr == ERR_DOZUMOVE_WRSP_RDSH)
						cprintf("ОШИБКА НА ШИНЕ WR_СП-->RD_Ш\n");            

					cprintf("    Разряды адреса ошибки:\n");
					cprintf(" (15р)-%s-( 0р)\n",BusStr);

					if(BusAddrLen > 16)
					{
						Bus = ((param->ErrAddr >> 16) & 0xFFFF);
						LongToBinStr(Bus,BusStr,16);
						cprintf(" (31р)-%s-(16р)\n",BusStr);
					}


					Bus = (param->ErrPosition & 0xFFFF);
					memset(BusStr,'.',sizeof(BusStr));
					LongToBinStr(Bus,BusStr,16);
					cprintf("\n    Разряды данных ошибки:\n");
					cprintf(" (15р)-%s-( 0р)\n",BusStr);

					if(param->Width_Bus > 16)
					{
						Bus = ((param->ErrPosition >> 16) & 0xFFFF);
						memset(BusStr,'.',sizeof(BusStr));
						LongToBinStr(Bus,BusStr,16);
						cprintf(" (31р)-%s-(16р)\n",BusStr);
					}

					if(param->Width_Bus > 32)
					{
						Bus = ((param->ErrPosition >> 32) & 0xFFFF);
						memset(BusStr,'.',sizeof(BusStr));
						LongToBinStr(Bus,BusStr,16);
						cprintf(" (47р)-%s-(32р)\n",BusStr);
					}

					if(param->Width_Bus > 48)
					{
						Bus = ((param->ErrPosition >> 48) & 0xFFFF);
						memset(BusStr,'.',sizeof(BusStr));
						LongToBinStr(Bus,BusStr,16);
						cprintf(" (63р)-%s-(48р)\n",BusStr);
					}
			}
			break;
		}			
	}
	else
	{
		gotoxy(4,7);
		cprintf("Ошибок в шине данных и\n");
		cprintf("        в шине адреса \n");
		cprintf("        НЕ ОБНАРУЖЕНО!");
	}

		gotoxy(0,15);
		cprintf("<Enter>-Еще раз. <Esc>-Выход.\n");

uint16 KEY=0;

do
{
KEY = getch();
}
while((KEY != KEY_ENTER) & (KEY != KEY_ESC));

if(KEY == KEY_ENTER)
return TPO_ERR;
else   
return TPO_OK;
}

//-------------------------------------------------------------------------------------------------
void Tst_SDRAM_full(cs_menu* m, void* arg)
{

 start("Тест ОЗУ на ПВ");

    uint32 res = 0;
    int32 res2 = 0;
	mem_test param;
	    
	F_TestProgress(1);

	uint64 ErrorsPositions;
	uint32 ErrorAddress;

tst_sdram:
	T_clrbar_D(4,12);

	gotoxy(9,7);
	cprintf("Идет тест...");

	res = uniTestSDRAM_PP( &ErrorsPositions, &ErrorAddress);

	T_clrbar(7);
		
	
	param.addr = res;
	param.length = 0x800000;
	param.Width_Bus = 32;
	param.ErrPosition = ErrorsPositions;
	param.ErrAddr = ErrorAddress;

	res2 = PrintResTstRAM(&param);

	if(res2) goto tst_sdram;
// }
}


//-------------------------------------------------------------------------------------------------
uint32 Chek_usb_dev(uint32 dev)
{

char devv[16];

uint16 KEY;
uint32 file;

if(dev == 1)
strcpy(devv,"/vfat/a");

if(dev == 2)
strcpy(devv,"/vfat/b");

//sprintf(ttt, "Тест USB%d на ПВ", n_usb[0]);


file = drv_mkd(devv);
 if(file != RES_VOID)
 { 	
	drv_rmd(file);
	return TPO_OK;
 }

	clrscr();
	gotoxy(3,7);
	cprintf("USB флэш не установлена");
	gotoxy(0,15);
	cprintf("<Нажмите ESC>");
	while(1)
	{
	KEY = kb_hit();
	if(KEY == KEY_ESC)
	break;
	}

drv_rmd(file);
return TPO_ERR;
}

/*
//-------------------------------------------------------------------------------------------------
uint32 Chek_usb_dev(uint32 dev)
{

char devv[6];

uint16 KEY;
uint32 ms;
uint32 res;
s_inode* 		list;

if(dev == 1)
strcpy(devv,"msd11");

if(dev == 2)
strcpy(devv,"msd12");

//sprintf(ttt, "Тест USB%d на ПВ", n_usb[0]);

ms = drv_mkd("/dev/usb");
//ms = drv_mkd("/dev");
if(ms != NULL)
{
res = drv_ioctl(ms, IOC_INODE_LIST, &list);
drv_rmd(ms);

  if(res == OSE_OK)
  {
	if(list->next != NULL)
	{
		if(!(memcmp(list->next->name, devv, 5)))
			return TPO_OK;
		if(list->next->next != NULL)
		{
			if(!(memcmp(list->next->next->name, devv, 5)))
				return TPO_OK;
		}
	}
  }
}
	clrscr();
	gotoxy(3,7);
	cprintf("USB флэш не установлена");
	gotoxy(0,15);
	cprintf("<Нажмите ESC>");
	while(1)
	{
	KEY = kb_hit();
	if(KEY == KEY_ESC)
	break;
	}

return TPO_ERR;
}
*/


#define	N_TST_USB	256
//-------------------------------------------------------------------------------------------------
void Tst_USB_file(cs_menu* m, void* arg)
{

 uint32 NotErr;
 uint32 OkCreate;
 uint32 ErrCreate;
 uint32 ErrOpen;
 uint32 OkOpen;
 uint32 ErrWrite;
 uint32 ErrRead;
 uint32 ErrCmp;

// uint32 ms;
 uint32 res = 0;
 uint32* n_usb = (uint32*)arg;
 
 uint16 KEY;

 char ttt[30];

	if(Chek_usb_dev(n_usb[0]) == TPO_OK) 
	{

		sprintf(ttt, "Файловый тест USB%d на ПВ", n_usb[0]);
	start( ttt );
    
tst_usb:

		NotErr		 = 0;
		OkCreate	 = 0;
		ErrCreate	 = 0;
		ErrOpen		 = 0;
		OkOpen		 = 0;
		ErrWrite	 = 0;
		ErrRead		 = 0;
		ErrCmp		 = 0;


		T_clrbar_D(4,12);

		for(int i = 0; i < N_TST_USB; i++)
		{	

		KEY = kb_hit();
		if(KEY == KEY_ESC)
			break;

		gotoxy(0,4);
		cprintf("Идет тест файла test%d",i);
		gotoxy(0,15);
		cprintf("<ESC - Стоп>");
		gotoxy(0,6);
		
		res = usb_test_rw(n_usb[0], i, 1);
		
			if(res != (CREATE_OK | OPEN_OK))
			{
				if(res & CREATE_OK)
					OkCreate++;
				if(res & CREATE_FILE)
					ErrCreate++;
				if(res & OPEN_OK)
					OkOpen++;
				if(res & OPEN_FILE)
					ErrOpen++;
				if(res & WRITE_FILE)
					ErrWrite++;
				if(res & READ_FILE)
					ErrRead++;
				if(res & CMP_FILE)
					ErrCmp++;
			}
			else
			{
				OkOpen++;
				OkCreate++;
				NotErr++;
			}
		sleep_m(150);
		}	

		T_clrbar_D(4,12);	

		gotoxy(0,4);
		cprintf("Результаты тестирования\n\n");
		cprintf("Создано файлов на запись: %03d\n",OkCreate);
		cprintf("Ошибок создания файла   : %03d\n",ErrCreate);
		cprintf("Ошибок записи в файл    : %03d\n",ErrWrite);
		cprintf("Открыто файлов на чтение: %03d\n",OkOpen);
		cprintf("Ошибок открытия файлов  : %03d\n",ErrOpen);
		cprintf("Ошибок чтения из файла  : %03d\n",ErrRead);
		cprintf("Ошибок сравнения        : %03d\n",ErrCmp);
		cprintf("Успешных операций       : %03d\n\n",NotErr);

		gotoxy(0,15);
		cprintf("<Enter>-Еще раз. <Esc>-Выход.\n");

		do
		KEY = getch();
		while((KEY != KEY_ENTER) & (KEY != KEY_ESC));

		if(KEY == KEY_ENTER)
		goto tst_usb;
// 	}

//	drv_rmd(ms);
	}
}
/*****************************************************************************
Syntax:   	    
Remarks:			    
*******************************************************************************/
void GSCh_USB_file(cs_menu* m, void* arg)
{

    char	file_path[32];
//	char    number[4];
    FILE*	file;

	uint32 res = 0;
	int i=0;
	int j=0;

    uint16	buf_wr[512];
	memset(buf_wr, 0, sizeof(buf_wr));

   	strcpy(file_path, "/vfat/b/gsch00.bin");

    file = fopen(file_path, "wb");
    if(file == NULL)
    { 
		res++;
	}

	for(i=0; i<1024; i++)
	{
	memset(buf_wr, 0, sizeof(buf_wr));
		for(j=0; j<512; j++)
		{
        uint16 r1 = random(0);
        uint16 r2 = random(0);
		buf_wr[j] = (r1&0x00FF)|((r2<<8)&0xFF00);
		}
		    if(sizeof(buf_wr) != fwrite(buf_wr, 1, sizeof(buf_wr), file))
			{
				res ++;
			}
	}
	fclose(file);


   	strcpy(file_path, "/vfat/b/gsch01.bin");

    file = fopen(file_path, "wb");
    if(file == NULL)
    { 
		res++;
	}

	for(i=0; i<1024; i++)
	{
	memset(buf_wr, 0, sizeof(buf_wr));
		for(j=0; j<512; j++)
		{
        uint16 r1 = random(0);
        uint16 r2 = random(0);
		buf_wr[j] = (r1&0x00FF)|((r2<<8)&0xFF00);
		}
		    if(sizeof(buf_wr) != fwrite(buf_wr, 1, sizeof(buf_wr), file))
			{
				res ++;
			}
	}
	fclose(file);


   	strcpy(file_path, "/vfat/b/gsch10.bin");

    file = fopen(file_path, "wb");
    if(file == NULL)
    { 
		res++;
	}

	for(i=0; i<1024; i++)
	{
	memset(buf_wr, 0, sizeof(buf_wr));
		for(j=0; j<512; j++)
		{
        uint16 r1 = random(1);
        uint16 r2 = random(1);
		buf_wr[j] = (r1&0x00FF)|((r2<<8)&0xFF00);
		}
		    if(sizeof(buf_wr) != fwrite(buf_wr, 1, sizeof(buf_wr), file))
			{
				res ++;
			}
	}
	fclose(file);


   	strcpy(file_path, "/vfat/b/gsch11.bin");

    file = fopen(file_path, "wb");
    if(file == NULL)
    { 
		res++;
	}

	for(i=0; i<1024; i++)
	{
	memset(buf_wr, 0, sizeof(buf_wr));
		for(j=0; j<512; j++)
		{
        uint16 r1 = random(1);
        uint16 r2 = random(1);
		buf_wr[j] = (r1&0x00FF)|((r2<<8)&0xFF00);
		}
		    if(sizeof(buf_wr) != fwrite(buf_wr, 1, sizeof(buf_wr), file))
			{
				res ++;
			}
	}
	fclose(file);

}




//extern LogicDisk logicDisk;
//extern Device dev;
//-------------------------------------------------------------------------------------------------
void AboutUSB(uint32 device_id)
{

	char fstr[8];
	char devv[6];
	char* name;

//    char	file_path[32];
//    FILE*	file;
	uint32 d = 0;
	s_vfat_info info;
	
	uint32 ms;
	s_msd_capacity  capacity;
    s_msd_vendor    vendor;
	
	uint16 *ne = (uint16*)0x6c000000;  
	uint16 nec = *ne;  
/*   
*/

	if(Chek_usb_dev(device_id) == TPO_OK) 
	{

	    if(device_id == 1)
		{
//		   	strcpy(file_path, "/vfat/a/test1.bin");
			if(nec == 0x0120)
			strcpy(devv,"msd11");
			else
			strcpy(devv,"msd12");
    		d = drv_mkd( "/vfat/a" );
		}
	    if(device_id == 2)
		{
//	    	strcpy(file_path, "/vfat/b/test1.bin");
			if(nec == 0x0120)
			strcpy(devv,"msd12");
			else
			strcpy(devv,"msd13");
    		d = drv_mkd( "/vfat/b" );
		}


   		ms = drv_mkd("/dev/sd2u0");
	    drv_ioctl(ms, MSD_DEVICE_NAME, &name);

		if(memcmp(name, devv, 5))
		{
   			drv_rmd(ms);
	   		ms = drv_mkd("/dev/sd3u0");
		}

					
	    drv_ioctl(ms, MSD_VENDOR, &vendor);
		drv_ioctl(ms, MSD_CAPACITY, &capacity);
//для определения ФС



		if( d != RES_VOID )
		{
			if( drv_ioctl( d, FSI_TYPE, &info ) != OSE_OK )
			{
			print_err("IFACE", DRV_ERR);
			goto end_about;
		// FS_NO, FS_FAT12, FS_FAT16, FS_FAT32, FS_ROOTFS
			}
		}

		switch( info.type )
		{
			case FS_NO:	  strcpy(fstr,"НЕТ");
						  break;					    
			case FS_FAT12:strcpy(fstr,"FAT12");
						  break;
			case FS_FAT16:strcpy(fstr,"FAT16");
						  break;	
			case FS_FAT32:strcpy(fstr,"FAT32");
						  break;
			default:strcpy(fstr,"ERROR");

		}

		gotoxy(0,4);
		cprintf("Производитель:%s",vendor.vendor_identification);
		gotoxy(0,6);
		cprintf("Модель флэшки:%s",vendor.product_identification);
		gotoxy(0,8);
		cprintf("Номер ревизии:%s",vendor.product_revision_level);


		gotoxy(0,10);
		cprintf("Размер сектора:%d",capacity.block_length);
		gotoxy(0,12);
		cprintf("Емкость флэшки:%lu",capacity.flash_capacity);
		gotoxy(0,14);
		cprintf("Файловая система:%s",fstr);
	
  	getch();      

end_about:
    drv_rmd(ms);
    drv_rmd(d);

	}

//	return 0;
}
//-------------------------------------------------------------------------------------------------
void F_AboutUSB(cs_menu* m, void* arg)
{

uint32* n_usb = (uint32*)arg;
//uint16 KEY;

	clrscr();

	gotoxy(0,2);
	cprintf("Информация о флэш \n");
	cprintf("           вставленном в USB%d", n_usb[0]);

	AboutUSB(n_usb[0]);
}


/**************************************************************************************************\
*  МЕНЮ тест записи на USB
\***sss********************************************************************************************/
void  inmenu_usb_fat_test(cs_menu* node, void* arg)
{
#define USB_BUF_SIZE 4096
  FILE*  file;
  uint8* buf;
  int32  speed, key, size, error;
  int32  buf_size = USB_BUF_SIZE;
  uint64 limit_time;
  char   str[64];
  char   spd[16];

 char file_path[32];
 uint32* n_usb = (uint32*)arg;
 

 char ttt[30];


	if(Chek_usb_dev(n_usb[0]) == TPO_OK) 
	{

		sprintf(ttt, "Тест скорости USB%d на ПВ", n_usb[0]);
	start( ttt );
    
	  buf = new uint8[USB_BUF_SIZE];
	  if(buf == NULL)
	  {
    	put_str_center(Y_WAIT_LINE, "Ошибка выделения памяти");
	    put_end_line(_put_esc_exit, KEY_ESC);
    	return;
	  }

		if(n_usb[0] == 1)
   		 	strcpy(file_path, "/vfat/a/usb_test.dbg");
		if(n_usb[0] == 2)
    		strcpy(file_path, "/vfat/b/usb_test.dbg");


	  file = fopen(file_path, "wb");
	  if(file != NULL)
	  {
    	memset(buf, 0x0, buf_size);
	    put_str_center(Y_LAST_LINE, _put_esc_stop);
    	set_text_attribute(0,Y_LAST_LINE,30,ATTR_REVERSE);
    
    	con_roll_open(1, 2, 13, 3);
	    con_roll_putstr(100, node->name);
   		con_roll_putstr(100, "\n");
	    error = 0;
    	size = 0;
	    limit_time = time_m()+5000;
    	while(true)
		{
    	  if(buf_size != fwrite(buf, 1, buf_size, file))
		  {
    	    error = 1;
        	con_roll_putstr(100, "Ошибка записи в файл\n");
			break;
		  }
		  else
    	     size += buf_size;
	      if(time_m()>=limit_time)
    	  {
			speed = size/5;
			strcpy(str, "Запись: ");
			itoa(speed, spd);
			strcat(str, spd);
			strcat(str, " Байт/с\n");
    	    con_roll_putstr(100, str);
	        if(con_roll_kbhit())
    	    {
	          key = con_roll_getch();
			  if(key == KEY_ESC) break;
	        }
			size = 0;
			limit_time = time_m()+5000;
    	  }
	    }
    	fclose(file);
		remove(file_path);

	    if(error == 0)
	      con_roll_close(0x0);
		else
	      con_roll_close(KEY_ESC);
	  }
	  else
	  {
	    put_str_center(Y_WAIT_LINE, "Ошибка открытия файла:");
	    put_str_center(Y_WAIT_LINE+1, "/vfat/a/usb_test.dbg");
//		return;
	  }
	  delete buf;
	  put_end_line(_put_esc_exit, KEY_ESC);
//	}
	}
#undef USB_BUF_SIZE
}




//-------------------------------------------------------------------
/*
void F_(cs_menu* m, void* arg)
{

uint32* n_usb = (uint32*)arg;
uint16 KEY;

	clrscr();

	gotoxy(0,2);
	cprintf("Информация о флэш \n");
	cprintf("           вставленном в USB%d", n_usb[0]);

	AboutUSB(n_usb[0]);
}
*/
//-------------------------------------------------------------------




//!!!!!!!!!!!Для СВ!!!!!!!!!!!!1
//-------------------------------------------------------------------------------------------------
void Receve_Res_From_Dozu(kdg_rez_test* res0ch, kdg_rez_test* res1ch)
{

  Send_cmd_comm(MIN_NUMBER_COMM, GET_RES_FROM_DOZU);
  receive_msg(res0ch, sizeof(kdg_rez_test), MSG_WAIT_DEBUG);
  receive_msg(res1ch, sizeof(kdg_rez_test), MSG_WAIT_DEBUG);

}

//-------------------------------------------------------------------------------------------------
int32 Send_Receve_N_Test(uint32 pid, uint32 n_test, kdg_rez_test* rezult)
{
kdg_cmd		to_proc;
kdg_cmd_ask	cdg_error;
int32		error;
//char*	name = 0;

kdg_rez_test rezult0;
kdg_rez_test rezult1;
memset(&rezult0, 0, sizeof(kdg_rez_test));
memset(&rezult1, 0, sizeof(kdg_rez_test));

to_proc.cmd = N_TEST;

  msg_send(pid, &to_proc, sizeof(kdg_cmd));
  error = receive_msg(&cdg_error, sizeof(kdg_cmd_ask), MSG_WAIT_DEBUG);

  if(error == MSG_ER_TIME_OUT)
  {
	print_err("IFACE", MAIN_TIME_OUT);
	return error;
  }
  if(error == MSG_ER_SYNC)
  {
	print_err("IFACE", MAIN_ERR_MSG);
	return error;
  }

  memset(rezult, 0, sizeof(kdg_rez_test));
  rezult->n_test = n_test;
  msg_send(pid, rezult, sizeof(kdg_rez_test));


  if(pid == msg_pid_main)
  {
  error = receive_msg(rezult, sizeof(kdg_rez_test), MSG_WAIT_DEBUG);

  	if(rezult->err != TPO_OK)
  	{
		print_err("MAIN", rezult->err);
		return TPO_ERR;
  	}

  Send_cmd_comm(MIN_NUMBER_COMM, GET_RES_FROM_DOZU);
  error = receive_msg(&rezult0, sizeof(kdg_rez_test), MSG_WAIT_DEBUG);
  error = receive_msg(&rezult1, sizeof(kdg_rez_test), MSG_WAIT_DEBUG);

	rezult->n_test = rezult0.n_test | rezult1.n_test;
	rezult->rez = rezult0.rez | rezult1.rez;
	rezult->adrr = rezult0.adrr | rezult1.adrr;
	rezult->data = rezult0.data | rezult1.data;
	rezult->data1 = rezult0.data1 | rezult1.data1;
	memcpy(rezult->buf, rezult0.buf, 32 );
  }
  else
  {
  error = receive_msg(rezult, sizeof(kdg_rez_test), MSG_WAIT_DEBUG);

  	if(rezult->err != TPO_OK)
  	{
		print_err("MAIN", rezult->err);
		return TPO_ERR;
  	}
  }

  if(error != TPO_OK)
	  return error;

  if(rezult->cmd != RES_N_TEST)
		return MSG_ER_SYNC;

  if(rezult->n_test != n_test)
		return MSG_ER_SYNC;

  if(rezult->rez != 0)
	return rezult->rez;


return TPO_OK;
}


//!!!!!!!!!!!Для ПП-056!!!!!!!!!!!!1
//-------------------------------------------------------------------------------------------------
uint16 F_hash_comp_pp056()
{
    int32 res = 0;
	kdg_rez_test rezult;    
	F_TestProgress(1);

	res = Send_Receve_N_Test(msg_pid_main, CELOSTN_PP056, &rezult);

	if(res == MSG_ER_TIME_OUT)
	{
		print_err("IFACE", MAIN_TIME_OUT);
		return TPO_ERR;
	}
	
	if(res == MSG_ER_SYNC)
	{
		print_err("IFACE", MAIN_ERR_MSG);
		return TPO_ERR;
	}

	return res == 0 ? 0 : 1;
}

/*****************************************************************************
Syntax:   	    
Remarks:			    
*******************************************************************************/

uint16 F_test_usb_flash3()
{
    int32 res = 0;
	kdg_rez_test rezult;    
	F_TestProgress(1);

	res = Send_Receve_N_Test(msg_pid_main, TEST_USB3, &rezult);

	if(res == MSG_ER_TIME_OUT)
	{
		print_err("IFACE", MAIN_TIME_OUT);
		return TPO_ERR;
	}
	
	if(res == MSG_ER_SYNC)
	{
		print_err("IFACE", MAIN_ERR_MSG);
		return TPO_ERR;
	}

	return res == 0 ? 0 : 1;
}

uint16 F_test_cdrom()
{
    int32 res = 0;
	kdg_rez_test rezult;    
	F_TestProgress(1);

	res = Send_Receve_N_Test(msg_pid_main, TEST_CDROM, &rezult);

	if(res == MSG_ER_TIME_OUT)
	{
		print_err("IFACE", MAIN_TIME_OUT);
		return TPO_ERR;
	}
	
	if(res == MSG_ER_SYNC)
	{
		print_err("IFACE", MAIN_ERR_MSG);
		return TPO_ERR;
	}

	return res == 0 ? 0 : 1;
}


uint16 F_test_raid()
{
    int32 res = 0;
	kdg_rez_test rezult;    
	F_TestProgress(1);

	res = Send_Receve_N_Test(msg_pid_main, TEST_RAID, &rezult);

	if(res == MSG_ER_TIME_OUT)
	{
		print_err("IFACE", MAIN_TIME_OUT);
		return TPO_ERR;
	}
	
	if(res == MSG_ER_SYNC)
	{
		print_err("IFACE", MAIN_ERR_MSG);
		return TPO_ERR;
	}

	return res == 0 ? 0 : 1;
}


//!!!!!!!!!!!Для СВ!!!!!!!!!!!!1
//-------------------------------------------------------------------------------------------------
uint16 F_hash_comp_main()
{
    int32 res = 0;
	kdg_rez_test rezult;    
	F_TestProgress(1);

	res = Send_Receve_N_Test(msg_pid_main, CELOSTN, &rezult);

	if(res == MSG_ER_TIME_OUT)
	{
		print_err("IFACE", MAIN_TIME_OUT);
		return TPO_ERR;
	}
	
	if(res == MSG_ER_SYNC)
	{
		print_err("IFACE", MAIN_ERR_MSG);
		return TPO_ERR;
	}

	return res == 0 ? 0 : 1;
}

//-------------------------------------------------------------------------------------------------
uint16 F_hash_comp_comm0()
{
    int32 res = 0;
	kdg_rez_test rezult;    
    
	F_TestProgress(1);

	res = Send_Receve_N_Test(pid_comm[0].pid, CELOSTN, &rezult);

	if(res== MSG_ER_TIME_OUT)
	{
		print_err("IFACE", COMM_TIME_OUT);
		return TPO_ERR;
	}
	
	if(res == MSG_ER_SYNC)
	{
		print_err("IFACE", COMM_ERR_MSG);
		return TPO_ERR;
	}

	return res == 0 ? 0 : 1;
}

//-------------------------------------------------------------------------------------------------
uint16 F_hash_comp_comm1()
{
    int32 res = 0;
	kdg_rez_test rezult;    
    
	F_TestProgress(1);

	res = Send_Receve_N_Test(pid_comm[1].pid, CELOSTN, &rezult);

	if(res== MSG_ER_TIME_OUT)
	{
		print_err("IFACE", COMM1_TIME_OUT);
		return TPO_ERR;
	}
	
	if(res == MSG_ER_SYNC)
	{
		print_err("IFACE", COMM1_ERR_MSG);
		return TPO_ERR;
	}

	return res == 0 ? 0 : 1;
}


//-------------------------------------------------------------------------------------------------
uint16 F_hash_comp_comm2()
{
    int32 res = 0;
	kdg_rez_test rezult;    
    
	F_TestProgress(1);

	res = Send_Receve_N_Test(pid_comm[2].pid, CELOSTN, &rezult);

	if(res== MSG_ER_TIME_OUT)
	{
		print_err("IFACE", COMM2_TIME_OUT);
		return TPO_ERR;
	}
	
	if(res == MSG_ER_SYNC)
	{
		print_err("IFACE", COMM2_ERR_MSG);
		return TPO_ERR;
	}

	return res == 0 ? 0 : 1;
}

//-------------------------------------------------------------------------------------------------
uint16 F_hash_comp_comm3()
{
    int32 res = 0;
	kdg_rez_test rezult;    
    
	F_TestProgress(1);

	res = Send_Receve_N_Test(pid_comm[3].pid, CELOSTN, &rezult);

	if(res== MSG_ER_TIME_OUT)
	{
		print_err("IFACE", COMM3_TIME_OUT);
		return TPO_ERR;
	}
	
	if(res == MSG_ER_SYNC)
	{
		print_err("IFACE", COMM3_ERR_MSG);
		return TPO_ERR;
	}

	return res == 0 ? 0 : 1;
}

//-------------------------------------------------------------------------------------------------
uint16 F_test_sdram_main()
{
    int32 res = 0;
	kdg_rez_test rezult;    
    
	F_TestProgress(1);

	res = Send_Receve_N_Test(msg_pid_main, TEST_SDRAM, &rezult);

	if(res== MSG_ER_TIME_OUT)
	{
		print_err("IFACE", MAIN_TIME_OUT);
		return TPO_ERR;
	}
	
	if(res == MSG_ER_SYNC)
	{
		print_err("IFACE", MAIN_ERR_MSG);
		return TPO_ERR;
	}

	return res == 0 ? 0 : 1;
}


//-------------------------------------------------------------------------------------------------
uint16 F_test_nvram_main()
{
    int32 res = 0;
	kdg_rez_test rezult;    
    
	F_TestProgress(1);

	res = Send_Receve_N_Test(msg_pid_main, TEST_NVRAM, &rezult);

	if(res== MSG_ER_TIME_OUT)
	{
		print_err("IFACE", MAIN_TIME_OUT);
		return TPO_ERR;
	}
	
	if(res == MSG_ER_SYNC)
	{
		print_err("IFACE", MAIN_ERR_MSG);
		return TPO_ERR;
	}

	return res == 0 ? 0 : 1;
}


//-------------------------------------------------------------------------------------------------
uint16 F_test_usbc_main()
{
    int32 res = 0;
	kdg_rez_test rezult;    
    
	F_TestProgress(1);

	res = Send_Receve_N_Test(msg_pid_main, TEST_USB_CONTR, &rezult);

	if(res== MSG_ER_TIME_OUT)
	{
		print_err("IFACE", MAIN_TIME_OUT);
		return TPO_ERR;
	}
	
	if(res == MSG_ER_SYNC)
	{
		print_err("IFACE", MAIN_ERR_MSG);
		return TPO_ERR;
	}

	return res == 0 ? 0 : 1;
}

//-------------------------------------------------------------------------------------------------
uint16 F_test_usb_main()
{
    int32 res = 0;
	kdg_rez_test rezult;    
    
	F_TestProgress(1);

	res = Send_Receve_N_Test(msg_pid_main, TEST_USB_FLASH, &rezult);

	if(res== MSG_ER_TIME_OUT)
	{
		print_err("IFACE", MAIN_TIME_OUT);
		return TPO_ERR;
	}
	
	if(res == MSG_ER_SYNC)
	{
		print_err("IFACE", MAIN_ERR_MSG);
		return TPO_ERR;
	}

	return res == 0 ? 0 : 1;
}


//-------------------------------------------------------------------------------------------------
uint16 F_test_dozu0()
{
    int32 res = 0;
	kdg_rez_test rezult;    

	F_TestProgress(1);

	res = Send_Receve_N_Test(msg_pid_main, TEST_DOZU, &rezult);

	if(res == MSG_ER_TIME_OUT)
	{
		print_err("IFACE", MAIN_TIME_OUT);
		return TPO_ERR;
	}
	
	if(res == MSG_ER_SYNC)
	{
		print_err("IFACE", MAIN_ERR_MSG);
		return TPO_ERR;
	}

	return res == 0 ? 0 : 1;
}


//-------------------------------------------------------------------------------------------------
uint16 F_test_dozu1()
{
    int32 res = 0;
	kdg_rez_test rezult;    

	F_TestProgress(1);

	res = Send_Receve_N_Test(msg_pid_main, TEST_DOZU_ST1, &rezult);

	if(res== MSG_ER_TIME_OUT)
	{
		print_err("IFACE", MAIN_TIME_OUT);
		return TPO_ERR;
	}
	
	if(res == MSG_ER_SYNC)
	{
		print_err("IFACE", MAIN_ERR_MSG);
		return TPO_ERR;
	}

	return res == 0 ? 0 : 1;
}


//-------------------------------------------------------------------------------------------------
uint16 F_test_dozu2()
{
    int32 res = 0;
	kdg_rez_test rezult;    

	F_TestProgress(1);

	res = Send_Receve_N_Test(msg_pid_main, TEST_DOZU_ST2, &rezult);

	if(res== MSG_ER_TIME_OUT)
	{
		print_err("IFACE", MAIN_TIME_OUT);
		return TPO_ERR;
	}
	
	if(res == MSG_ER_SYNC)
	{
		print_err("IFACE", MAIN_ERR_MSG);
		return TPO_ERR;
	}

	return res == 0 ? 0 : 1;
}

//-------------------------------------------------------------------------------------------------
uint16 F_test_dozu3()
{
    int32 res = 0;
	kdg_rez_test rezult;    

	F_TestProgress(1);

	res = Send_Receve_N_Test(msg_pid_main, TEST_DOZU_ST3, &rezult);

	if(res== MSG_ER_TIME_OUT)
	{
		print_err("IFACE", MAIN_TIME_OUT);
		return TPO_ERR;
	}
	
	if(res == MSG_ER_SYNC)
	{
		print_err("IFACE", MAIN_ERR_MSG);
		return TPO_ERR;
	}

	return res == 0 ? 0 : 1;
}


//-------------------------------------------------------------------------------------------------
uint16 F_test_move0()
{
    int32 res = 0;
	kdg_rez_test rezult;    

	F_TestProgress(1);

	res = Send_Receve_N_Test(msg_pid_main, TEST_MOVE, &rezult);

	if(res== MSG_ER_TIME_OUT)
	{
		print_err("IFACE", MAIN_TIME_OUT);
		return TPO_ERR;
	}
	
	if(res == MSG_ER_SYNC)
	{
		print_err("IFACE", MAIN_ERR_MSG);
		return TPO_ERR;
	}

	return res == 0 ? 0 : 1;
}


//-------------------------------------------------------------------------------------------------
uint16 F_test_move1()
{
    int32 res = 0;

	F_TestProgress(1);
	kdg_rez_test rezult;    

	res = Send_Receve_N_Test(msg_pid_main, TEST_MOVE_ST1, &rezult);

	if(res== MSG_ER_TIME_OUT)
	{
		print_err("IFACE", MAIN_TIME_OUT);
		return TPO_ERR;
	}
	
	if(res == MSG_ER_SYNC)
	{
		print_err("IFACE", MAIN_ERR_MSG);
		return TPO_ERR;
	}

	return res == 0 ? 0 : 1;
}


//-------------------------------------------------------------------------------------------------
uint16 F_test_move2()
{
    int32 res = 0;

	F_TestProgress(1);
	kdg_rez_test rezult;    

	res = Send_Receve_N_Test(msg_pid_main, TEST_MOVE_ST2, &rezult);

	if(res== MSG_ER_TIME_OUT)
	{
		print_err("IFACE", MAIN_TIME_OUT);
		return TPO_ERR;
	}
	
	if(res == MSG_ER_SYNC)
	{
		print_err("IFACE", MAIN_ERR_MSG);
		return TPO_ERR;
	}
	return res == 0 ? 0 : 1;
}

//-------------------------------------------------------------------------------------------------
uint16 F_test_move3()
{
    int32 res = 0;

	F_TestProgress(1);
	kdg_rez_test rezult;    

	res = Send_Receve_N_Test(msg_pid_main, TEST_MOVE_ST3, &rezult);

	if(res== MSG_ER_TIME_OUT)
	{
		print_err("IFACE", MAIN_TIME_OUT);
		return TPO_ERR;
	}
	
	if(res == MSG_ER_SYNC)
	{
		print_err("IFACE", MAIN_ERR_MSG);
		return TPO_ERR;
	}

	return res == 0 ? 0 : 1;
}

//-------------------------------------------------------------------------------------------------
uint16 F_test_sk0()
{
    int32 res = 0;
	kdg_rez_test rezult;    

	F_TestProgress(1);

	res = Send_Receve_N_Test(pid_comm[0].pid, TEST_SK, &rezult);

	if(res== MSG_ER_TIME_OUT)
	{
		print_err("IFACE", COMM_TIME_OUT);
		return TPO_ERR;
	}
	
	if(res == MSG_ER_SYNC)
	{
		print_err("IFACE", COMM_ERR_MSG);
		return TPO_ERR;
	}
	return res == 0 ? 0 : 1;
}


//-------------------------------------------------------------------------------------------------
uint16 F_test_sk1()
{
    int32 res = 0;
	kdg_rez_test rezult;    

	F_TestProgress(1);

	res = Send_Receve_N_Test(pid_comm[1].pid, TEST_SK, &rezult);

	if(res== MSG_ER_TIME_OUT)
	{
		print_err("IFACE", COMM1_TIME_OUT);
		return TPO_ERR;
	}
	
	if(res == MSG_ER_SYNC)
	{
		print_err("IFACE", COMM1_ERR_MSG);
		return TPO_ERR;
	}
	return res == 0 ? 0 : 1;
}



//-------------------------------------------------------------------------------------------------
uint16 F_test_sk2()
{
    int32 res = 0;
	kdg_rez_test rezult;    

	F_TestProgress(1);

	res = Send_Receve_N_Test(pid_comm[2].pid, TEST_SK, &rezult);

	if(res== MSG_ER_TIME_OUT)
	{
		print_err("IFACE", COMM2_TIME_OUT);
		return TPO_ERR;
	}
	
	if(res == MSG_ER_SYNC)
	{
		print_err("IFACE", COMM2_ERR_MSG);
		return TPO_ERR;
	}

	return res == 0 ? 0 : 1;
}

//-------------------------------------------------------------------------------------------------
uint16 F_test_sk3()
{
    int32 res = 0;
	kdg_rez_test rezult;    

	F_TestProgress(1);

	res = Send_Receve_N_Test(pid_comm[3].pid, TEST_SK, &rezult);

	if(res== MSG_ER_TIME_OUT)
	{
		print_err("IFACE", COMM3_TIME_OUT);
		return TPO_ERR;
	}
	
	if(res == MSG_ER_SYNC)
	{
		print_err("IFACE", COMM3_ERR_MSG);
		return TPO_ERR;
	}

	return res == 0 ? 0 : 1;
}


//-------------------------------------------------------------------------------------------------
void Tst_SDRAM_full_SV(cs_menu* m, void* arg)
{
uint32* n_ch = ((uint32*)arg);

 start("Тест ОЗУ на СВ ");
 cprintf("%d канала", n_ch[0]-1);

    int32 res = 0;
    uint32 res2 = 0;
	mem_test param;
    
	F_TestProgress(1);

//	uint32 ErrorsPositions;
//	uint32 ErrorAddress;
	kdg_rez_test rezult;        

	kdg_rez_test rezult_ch[2];
	memset(&rezult_ch, 0, sizeof(rezult_ch));


tst_sdram_sv:
	T_clrbar_D(4,12);

	gotoxy(9,7);
	cprintf("Идет тест...");

	Send_cmd_main(TEST_SDRAM_FULL);
sleep_s(10); // тест идет примерно 30 сек.
	res = receive_msg(&rezult, sizeof(kdg_rez_test), MSG_WAIT_DEBUG );

	if(res == MSG_ER_TIME_OUT)
	{
		print_err("IFACE", MAIN_TIME_OUT);
		return ;
	}
	
	if(res == MSG_ER_SYNC)
	{
		print_err("IFACE", MAIN_ERR_MSG);
		return ;
	}

	Receve_Res_From_Dozu(&rezult_ch[0], &rezult_ch[1]);

 	T_clrbar(7);

	param.addr = rezult_ch[n_ch[0] - 1].rez;
	param.length = 0x800000;
	param.Width_Bus = SH_DOZU;
	param.ErrPosition = rezult_ch[n_ch[0] - 1].data1;
	param.ErrPosition = (param.ErrPosition << 32) | (rezult_ch[n_ch[0] - 1].data);
	param.ErrAddr = rezult_ch[n_ch[0] - 1].adrr;

	res2 = PrintResTstRAM(&param);

//	res2 = PrintResTstRAM(rezult_ch[n_ch[0] - 1].rez, rezult_ch[n_ch[0] - 1].data, rezult_ch[n_ch[0] - 1].adrr, 32, 0x800000);

	if(res2) goto tst_sdram_sv;
// }
}

//-------------------------------------------------------------------------------------------------
void Tst_NVRAM_full_SV(cs_menu* m, void* arg)
{

uint32* n_ch = ((uint32*)arg);

 start("Тест ЭОЗУ на СВ ");
 cprintf("%d канала", n_ch[0]-1);

    int32 res = 0;
    uint32 res2 = 0;
	mem_test param;
    
	F_TestProgress(1);

	kdg_rez_test rezult;        

	kdg_rez_test rezult_ch[2];
	memset(&rezult_ch, 0, sizeof(rezult_ch));

tst_nvram_sv:
	T_clrbar_D(4,12);

	gotoxy(9,7);
	cprintf("Идет тест...");


	Send_cmd_main(TEST_NVRAM_FULL);

	res = receive_msg(&rezult, sizeof(kdg_rez_test), MSG_WAIT_DEBUG );

	if(res== MSG_ER_TIME_OUT)
	{
		print_err("IFACE", MAIN_TIME_OUT);
		return ;
	}
	
	if(res == MSG_ER_SYNC)
	{
		print_err("IFACE", MAIN_ERR_MSG);
		return ;
	}

	Receve_Res_From_Dozu(&rezult_ch[0], &rezult_ch[1]);

 	T_clrbar(7);

	param.addr = rezult_ch[n_ch[0] - 1].rez;
	param.length = 0x100000;
	param.Width_Bus = 16;
	param.ErrPosition = rezult_ch[n_ch[0] - 1].data1;
	param.ErrPosition = (param.ErrPosition << 32) | (rezult_ch[n_ch[0] - 1].data);
	param.ErrAddr = rezult_ch[n_ch[0] - 1].adrr;

	res2 = PrintResTstRAM(&param);
//	res2 = PrintResTstRAM(rezult_ch[n_ch[0] - 1].rez, rezult_ch[n_ch[0] - 1].data, rezult_ch[n_ch[0] - 1].adrr, 16, 0x100000);

	if(res2) goto tst_nvram_sv;
// }
}



//-------------------------------------------------------------------------------------------------
void Tst_ROM_SV(cs_menu* m, void* arg)
{
uint16 KEY = 0;
int32 res = 0;

 start("Тест ПЗУ");

    
	F_TestProgress(1);

//	uint32 ErrorsPositions;
//	uint32 ErrorAddress;
	kdg_rez_test rezult_main[NUMBER_COMM_DSP];        

tst_rom:

	T_clrbar_D(4,12);
	gotoxy(0,15);
	cprintf("<ESC - Стоп>");

	Send_cmd_main(START_TEST_ROM);


// об ошибках спрашиваю только у сетевых. центральный передает свои ошибки сетевому через дозу и не проверяеться спаркой.
	while(1)
	{
		sleep_s(1);
//		sleep_m(333);
		for(int i = 0; i <2; i++)
		{	
	
			Send_cmd_comm(0, RES_TEST_ROM_CP0 + i);
			res = receive_msg(&rezult_main[i], sizeof(kdg_rez_test), MSG_WAIT_DEBUG );
			if(res== MSG_ER_TIME_OUT)
			{
				print_err("IFACE", COMM_TIME_OUT+i);
				goto end_tst_rom;
			}
			if(res == MSG_ER_SYNC)
			{
				print_err("IFACE", COMM_ERR_MSG+i);
				goto end_tst_rom;
			}
			if(rezult_main[i].cmd != RES_TEST_ROM_CP0 + i)
			{
				print_err("IFACE", COMM_ERR_MSG+i);
				goto end_tst_rom;
			}	
		}

		gotoxy(0,5);
		cprintf("ЦП0:Прошло циклов :%d\n", rezult_main[0].n_test);
		cprintf("Ошибок чтения  ПЗУ:%d\n", rezult_main[0].rez);
		cprintf("Чтение memcpy  ПЗУ:%d\n", rezult_main[0].data);
		cprintf("Ошибок расчета ХЭШ:%d\n", rezult_main[0].adrr);

		cprintf("ЦП1:Прошло циклов :%d\n", rezult_main[1].n_test);
		cprintf("Ошибок чтения  ПЗУ:%d\n", rezult_main[1].rez);
		cprintf("Чтение memcpy  ПЗУ:%d\n", rezult_main[1].data);
		cprintf("Ошибок расчета ХЭШ:%d\n", rezult_main[1].adrr);

		if(kb_hit() == KEY_ESC)
		break;
	}

end_tst_rom:

		Send_cmd_main(STOP_TEST_ROM);


		gotoxy(0,15);
		cprintf("<Enter>-Еще раз. <Esc>-Выход.\n");

		do
		KEY = getch();
		while((KEY != KEY_ENTER) & (KEY != KEY_ESC));

		if(KEY == KEY_ENTER)
		goto tst_rom;

// }




}

//-------------------------------------------------------------------------------------------------
void TestDARAM_PrintRes(cs_menu* m, void* arg)
//uint16 TestDARAM_PrintRes(uint16 n_comm,uint32 BusDataLen,uint32 BusAddrLen)
{
	comm_status* n_eth = (comm_status*)arg;
//	uint16 KEY;

	kdg_rez_test rezult;        
	int32 res;
	uint32 res2;
	mem_test param;

	char ttt[30];

		sprintf(ttt, "Тест ДОЗУ ЦП - СП%d", n_eth->N);
  start( ttt );


tst_dozu_pr:

	T_clrbar_D(4,12);	

	gotoxy(9,7);
	cprintf("Идет тест...");

//	if(n_eth->N == 0)
	res = Send_Receve_N_Test(msg_pid_main, TEST_DOZU + n_eth->N, &rezult);
//	if(n_eth->N == 1)
//		res = Send_Receve_N_Test(msg_pid_main, TEST_DOZU_ST1, &rezult);

//	res = receive_msg(&rezult, sizeof(kdg_rez_test), MSG_WAIT_DEBUG );
	if(res == MSG_ER_TIME_OUT)
	{
		print_err("IFACE", MAIN_TIME_OUT);
		return;
	}
	
	if(res == MSG_ER_SYNC)
	{
		print_err("IFACE", MAIN_ERR_MSG);
		return;
	}

	if(res == TPO_ERR)
	{
		gotoxy(7,7);
		cprintf("ОШИБКА ОБМЕНА !\n");
		getch();
		return;
	}
 	T_clrbar(7);

	param.addr = rezult.rez;
	param.length = LEN_DUZU_FOR_TEST;
	param.Width_Bus = SH_DOZU;
	param.ErrPosition = rezult.data1;
	param.ErrPosition = (param.ErrPosition << 32) | (rezult.data);
	param.ErrAddr = rezult.adrr;

	res2 = PrintResTstRAM(&param);

//	res2 = PrintResTstRAM(rezult.rez, rezult.data, rezult.adrr, 32, LEN_DUZU_FOR_TEST);

	if(res2) goto tst_dozu_pr;
//  }
}




//-------------------------------------------------------------------------------------------------
void TestDARAM_MOVE_PrintRes(cs_menu* m, void* arg)
//uint16 TestDARAM_PrintRes(uint16 n_comm,uint32 BusDataLen,uint32 BusAddrLen)
{
	comm_status* n_eth = (comm_status*)arg;
//	uint16 KEY;

	kdg_rez_test rezult;        
	int32 res;
	uint32 res2;
	mem_test param;

	char ttt[30];

		sprintf(ttt, "Тест ДОЗУ СП%d - Ш", n_eth->N);
  start( ttt );


tst_dozu_move_pr:

	T_clrbar_D(4,12);	

	gotoxy(9,7);
	cprintf("Идет тест...");

//	if(n_eth->N == 0)
	res = Send_Receve_N_Test(msg_pid_main, TEST_MOVE + n_eth->N, &rezult);
//	if(n_eth->N == 1)
//		res = Send_Receve_N_Test(msg_pid_main, TEST_MOVE_ST1, &rezult);

//	res = receive_msg(&rezult, sizeof(kdg_rez_test), MSG_WAIT_DEBUG );
	if(res== MSG_ER_TIME_OUT)
	{
		print_err("IFACE", MAIN_TIME_OUT);
		return;
	}
	
	if(res == MSG_ER_SYNC)
	{
		print_err("IFACE", MAIN_ERR_MSG);
		return;
	}

	if(res == TPO_ERR)
	{
		gotoxy(7,7);
		cprintf("ОШИБКА ОБМЕНА !\n");
		getch();
		return;
	}
 	T_clrbar(7);

	param.addr = rezult.rez;
	param.length = LEN_DUZU_FOR_TEST;
	param.Width_Bus = SH_DOZU;
	param.ErrPosition = rezult.data1;
	param.ErrPosition = (param.ErrPosition << 32) | (rezult.data);
	param.ErrAddr = rezult.adrr;

	res2 = PrintResTstRAM(&param);

//	res2 = PrintResTstRAM(rezult.rez, rezult.data, rezult.adrr, 32, LEN_DUZU_FOR_TEST);

	if(res2) goto tst_dozu_move_pr;
//  }
}



//-------------------------------------------------------------------------------------------------
void TestDARAM_MOVE_CiklPrintRes(cs_menu* m, void* arg)
//uint16 TestDARAM_PrintRes(uint16 n_comm,uint32 BusDataLen,uint32 BusAddrLen)
{
	comm_status* n_eth = (comm_status*)arg;
//	uint16 KEY;

	kdg_rez_test rezult;        
	int32 res;
	uint32 res2;
	mem_test param;

	uint32 n_cikl = 0;
	uint32 n_err = 0;


	char ttt[30];


		sprintf(ttt, "Тест ДОЗУ СП%d - Ш", n_eth->N);

  start( ttt );


tst_dozu_move_pr:

	T_clrbar_D(4,12);	

tst_dozu_move_cikl_pr:

//	gotoxy(9,7);
//	cprintf("Идет тест...");

//	if(n_eth->N == 0)
	res = Send_Receve_N_Test(msg_pid_main, TEST_MOVE + n_eth->N, &rezult);
//	if(n_eth->N == 1)
//		res = Send_Receve_N_Test(msg_pid_main, TEST_MOVE_ST1, &rezult);

//	res = receive_msg(&rezult, sizeof(kdg_rez_test), MSG_WAIT_DEBUG );
	if(res== MSG_ER_TIME_OUT)
	{
		print_err("IFACE", MAIN_TIME_OUT);
		return;
	}
	
	if(res == MSG_ER_SYNC)
	{
		print_err("IFACE", MAIN_ERR_MSG);
		return;
	}

	if(res == TPO_ERR)
	{
		gotoxy(7,7);
		cprintf("ОШИБКА ОБМЕНА !\n");
		getch();
		return;
	}
// 	T_clrbar(7);


if(!rezult.rez)
{
n_cikl++;
		gotoxy(0,4);
		cprintf("Прошло циклов:%d\n", n_cikl);
		cprintf("Ошибок :%d\n", n_err);
		goto tst_dozu_move_cikl_pr;
}
else
{

n_err++;
	param.addr = rezult.rez;
	param.length = LEN_DUZU_FOR_TEST;
	param.Width_Bus = SH_DOZU;
	param.ErrPosition = rezult.data1;
	param.ErrPosition = (param.ErrPosition << 32) | (rezult.data);
	param.ErrAddr = rezult.adrr;

	res2 = PrintResTstRAM(&param);
}
//	res2 = PrintResTstRAM(rezult.rez, rezult.data, rezult.adrr, 32, LEN_DUZU_FOR_TEST);

	if(res2) goto tst_dozu_move_pr;
//  }
}
//-------------------------------------------------------------------------------------------------
void TestDARAM_Nagruz(cs_menu* m, void* arg)
{
uint16 KEY = 0;
int32 res = 0;

 start("Нагрузочный тест ДОЗУ");

	F_TestProgress(1);

//kdg_rez_test rezult_main;        
	kdg_rez_test rezult_comm[NUMBER_COMM_DSP];        

tst_nagr_dozu:

	T_clrbar_D(4,12);
	gotoxy(0,15);
	cprintf("<ESC - Стоп>");

	Send_cmd_main(START_TEST_DOZU_NAGR);

	for(int i = MIN_NUMBER_COMM; i < NUMBER_COMM_DSP; i++)
	Send_cmd_comm(i, START_TEST_DOZU_NAGR);

// отсылаем кмд на начало всем, а об ошибках спрашиваю только у сетевых. центральный передает свои ошибки сетевому через дозу и не проверяеться спаркой.
	while(1)
	{
//		sleep_s(1);
//		sleep_m(250);
		for(int i = MIN_NUMBER_COMM; i < NUMBER_COMM_DSP; i++)
		{	
	
			Send_cmd_comm(i, RES_TEST_DOZU_NAGR);
			res = receive_msg(&rezult_comm[i], sizeof(kdg_rez_test), MSG_WAIT_DEBUG );
			if(res== MSG_ER_TIME_OUT)
			{
				print_err("IFACE", COMM_TIME_OUT+i);
				goto end_tst_nagr_dozu;
			}
			if(res == MSG_ER_SYNC)
			{
				print_err("IFACE", COMM_ERR_MSG+i);
				goto end_tst_nagr_dozu;
			}
			if(rezult_comm[i].cmd != RES_TEST_DOZU_NAGR)
			{
				print_err("IFACE", COMM_ERR_MSG+i);
				goto end_tst_nagr_dozu;
			}	
		}

		gotoxy(0,4);
		cprintf("СП0:Прошло циклов:%d\n", rezult_comm[0].n_test);
		cprintf("Ошибок ДОЗУ0 ЦП0 :%d\n", rezult_comm[0].data);
		cprintf("Ошибок ДОЗУ1 ЦП1 :%d\n", rezult_comm[0].data1);
		cprintf("Ошибок ДОЗУ0 СП0 :%d\n", rezult_comm[0].rez);
		cprintf("Ошибок ДОЗУ1 СП0 :%d\n", rezult_comm[0].adrr);

		cprintf("СП1:Прошло циклов:%d\n", rezult_comm[1].n_test);
		cprintf("Ошибок ДОЗУ0 ЦП0 :%d\n", rezult_comm[1].data);
		cprintf("Ошибок ДОЗУ1 ЦП1 :%d\n", rezult_comm[1].data1);
		cprintf("Ошибок ДОЗУ0 СП1 :%d\n", rezult_comm[1].rez);
		cprintf("Ошибок ДОЗУ1 СП1 :%d\n", rezult_comm[1].adrr);

		if(kb_hit() == KEY_ESC)
		break;
	}

end_tst_nagr_dozu:

	Send_cmd_main(STOP_TEST_DOZU_NAGR);

	for(int i = MIN_NUMBER_COMM; i < NUMBER_COMM_DSP; i++)
	Send_cmd_comm(i, STOP_TEST_DOZU_NAGR);



		gotoxy(0,15);
		cprintf("<Enter>-Еще раз. <Esc>-Выход.\n");

		do
		KEY = getch();
		while((KEY != KEY_ENTER) & (KEY != KEY_ESC));

		if(KEY == KEY_ENTER)
		goto tst_nagr_dozu;

// }

}

//
//-------------------------------------------------------------------------------------------------
void F_TestSkEth(cs_menu* m, void* arg)
{
	comm_status* n_eth = (comm_status*)arg;
	uint16 KEY;
	int32 res;
	SkEthTestRes m_SkEthRes;
	uint32 io_cycle;
	kdg_rez_test rezult;        
	char ttt[30];
	uint32 Ycon = 6;

		sprintf(ttt, "Тест контроллера eth%d", n_eth->N);
  start( ttt );
    
tst_eth:

	T_clrbar_D(4,12);	
	gotoxy(0,15);
	cprintf("<ESC - Стоп>");

//	TestRes = 0;
	io_cycle = 0;

	memset(&m_SkEthRes,0,sizeof(m_SkEthRes));

	do
	{                            
		res = Send_Receve_N_Test(n_eth->pid, TEST_SK, &rezult);
//		if(res)return res;

	if(res== MSG_ER_TIME_OUT)
	{
		print_err("IFACE", COMM_TIME_OUT + n_eth->N);
		return;
	}
	
	if(res == MSG_ER_SYNC)
	{
		print_err("IFACE", COMM_ERR_MSG + n_eth->N);
		return;
	}
		
		if(res & ERR_RW_DP)
			m_SkEthRes.errRegDP++;
		if(res & ERR_RW_LXT)
			m_SkEthRes.errRegLX++;		
		if(res & ERR_LOOP_DP)
			m_SkEthRes.errSP_DP++;		
		if(res & ERR_LOOP_LXT)
			m_SkEthRes.errSP_LX++;		
		if(res & ERR_LOOP_PHY)
			m_SkEthRes.errSP_TR++;		

		if(res == TPO_ERR)
		{
			gotoxy(7,7);
			cprintf("ОШИБКА ОБМЕНА !\n");
			getch();
			return;
		}

		io_cycle++;
		Ycon = 6;

		gotoxy(0,4);
		cprintf("Прошло тестов:       %7d",io_cycle);

		gotoxy(0,5);
		cprintf("Ошибок:");

//		gotoxy(1,6);
//		cprintf("-чтения из DP83820:  %7d",m_SkEthRes.errRegDP);
#ifdef TPO5
		gotoxy(1,Ycon);
		Ycon +=2; 
		cprintf("-чтения из LXT971:   %7d",m_SkEthRes.errRegLX);

//		gotoxy(1,10);     
//		cprintf("-в петле СП-DP83820: %7d",m_SkEthRes.errSP_DP);
		gotoxy(1,Ycon);
		Ycon +=2; 
		cprintf("-в петле СП-LXT971:  %7d",m_SkEthRes.errSP_LX);
#endif
		gotoxy(1,Ycon);
		cprintf("-в петле с кабелем: %7d",m_SkEthRes.errSP_TR);
		
	}
	while( kb_hit() != KEY_ESC );

//  }

		gotoxy(0,15);
		cprintf("<Enter>-Еще раз. <Esc>-Выход.\n");

		do
		KEY = getch();
		while((KEY != KEY_ENTER) & (KEY != KEY_ESC));

		if(KEY == KEY_ENTER)
		goto tst_eth;

}
//-------------------------------------------------------------------


void Tst_MOVE(cs_menu* m, void* arg)
{
uint16 KEY = 0;
int32 res = 0;

 start("Tест MOVE");

//	F_TestProgress(1);

//kdg_rez_test rezult_main;        
/*
struct rez_test
{
    uint32	cmd;	//
    uint32	n_test;	//
    uint32	rez;	//
};
*/
	rez_test rezult_comm[NUMBER_COMM_DSP];        

tst_move:

	T_clrbar_D(4,12);
	gotoxy(0,15);
	cprintf("<ESC - Стоп>");

	for(int i = MIN_NUMBER_COMM; i < NUMBER_COMM_DSP; i++)
	Send_cmd_comm(i, START_TEST_MOVE);

	Send_cmd_main(START_TEST_MOVE);


// об ошибках спрашиваю только у сетевых. 
	while(1)
	{
		sleep_s(1);
//		sleep_m(250);
		for(int i = MIN_NUMBER_COMM; i < NUMBER_COMM_DSP; i++)
		{	
	
			Send_cmd_comm(i, RES_TEST_MOVE);
			res = receive_msg(&rezult_comm[i], sizeof(rez_test), MSG_WAIT_DEBUG );
			if(res== MSG_ER_TIME_OUT)
			{
				print_err("IFACE", COMM_TIME_OUT+i);
				goto end_tst_move;
			}
			if(res == MSG_ER_SYNC)
			{
				print_err("IFACE", COMM_ERR_MSG+i);
				goto end_tst_move;
			}
			if(rezult_comm[i].cmd != RES_TEST_MOVE)
			{
				print_err("IFACE", COMM_ERR_MSG+i);
				goto end_tst_move;
			}	
		}

		gotoxy(0,4);
		cprintf("СП0:Прошло циклов:%d\n", rezult_comm[0].n_test);
		cprintf("Ошибок ДОЗУ0:     %d\n", rezult_comm[0].rez0);
		cprintf("Ошибок ДОЗУ1:     %d\n", rezult_comm[0].rez1);

		cprintf("СП1:Прошло циклов:%d\n", rezult_comm[1].n_test);
		cprintf("Ошибок ДОЗУ0:     %d\n", rezult_comm[1].rez0);
		cprintf("Ошибок ДОЗУ1:     %d\n", rezult_comm[1].rez1);

		if(kb_hit() == KEY_ESC)
		break;
	}

end_tst_move:

	Send_cmd_main(STOP_TEST_MOVE);

//	for(int i = MIN_NUMBER_COMM; i < NUMBER_COMM_DSP; i++)
//	Send_cmd_comm(i, STOP_TEST_DOZU_NAGR);



		gotoxy(0,15);
		cprintf("<Enter>-Еще раз. <Esc>-Выход.\n");

		do
		KEY = getch();
		while((KEY != KEY_ENTER) & (KEY != KEY_ESC));

		if(KEY == KEY_ENTER)
		goto tst_move;

// }

}

//
//-------------------------------------------------------------------------------------------------







uint32 CrypterTestRes;

#define	E_AB			0x00000001ull//Ошибка простой замены
#define	E_GAM			0x00000002ull//Ошибка гаммирования
#define	E_IMV			0x00000004ull//Ошибка имитовставки 
#define	E_UPZ			0x00000008ull//Ошибка УПЗ

#define	E_CH_BODY		0x00000100ull//Ошибка в теле текста
#define	E_CH_CB			0x00000200ull//Ошибка в служебных данных
#define	E_CH_IMV		0x00000400ull//Ошибка имитовставки 
#define NOT_LOAD_PLIS   0x10000000ull//ПЛИС шифратора незагружена

/*****************************************************************************
Syntax:   	    
Remarks:			    
*******************************************************************************/
void F_CrServiceTest(cs_menu* m, void* arg)
{
	uint32 num_test = 0;
	uint32 ABerr,GAMerr,IMVerr,UPZerr;
	int32 res = 0;

	ABerr  = 0;
	GAMerr = 0;
	IMVerr = 0;
	UPZerr = 0;

	kdg_rez_test rezult;
	uint16 KEY;

//	char ttt[30];
//	sprintf(ttt, "Тест контроллера eth%d", n_eth->N);


  start("Тест служебных режимов");
    
tst_sl_rej:

	T_clrbar_D(4,12);	
	gotoxy(0,15);
	cprintf("<ESC - Стоп>");

	do
	{
	
		Send_cmd_main(TEST_CR_SERVISE);
	
		memset(&rezult, 0, sizeof(kdg_rez_test));
		res = receive_msg(&rezult, sizeof(kdg_rez_test), MSG_WAIT_DEBUG );

		if(res == MSG_ER_TIME_OUT)
		{
			print_err("IFACE", MAIN_TIME_OUT);
			return ;
		}
		
		if(res == MSG_ER_SYNC)
		{
			print_err("IFACE", MAIN_ERR_MSG);
			return ;
		}	
	
		if(rezult.cmd != TEST_CR_SERVISE)
		{
			print_err("IFACE", MAIN_ERR_MSG);
			return ;
		}

		CrypterTestRes = rezult.rez;

		if(CrypterTestRes&E_AB)
			ABerr++;
		if(CrypterTestRes&E_GAM)
			GAMerr++;
		if(CrypterTestRes&E_IMV)
			IMVerr++;
		if(CrypterTestRes&E_UPZ)
			UPZerr++;

		gotoxy(0,5);
		cprintf("Прошло тестов:  %7d",num_test);

		gotoxy(0,7);
		cprintf("Ошибок:");

		gotoxy(0,8);
		cprintf("-УПЗ:           %7d",UPZerr);

		gotoxy(0,9);     
		cprintf("-гаммирования:  %7d",GAMerr);

		gotoxy(0,10);
		cprintf("-имитовставки:  %7d",IMVerr);

		gotoxy(0,11);
		cprintf("-простой замены:%7d",ABerr);

		num_test++;

	}
	while( kb_hit() != KEY_ESC );

	gotoxy(0,15);
	cprintf("<Enter>-Еще раз. <Esc>-Выход.\n");

	do
	KEY = getch();
	while((KEY != KEY_ENTER) & (KEY != KEY_ESC));

	if(KEY == KEY_ENTER)
	goto tst_sl_rej;

//  }
}

/*****************************************************************************
Syntax:   	    
Remarks:			    
*******************************************************************************/

void F_CrChannelCfgEth(uint16 eth_send,uint16 eth_recv)
{
	int32 res;
//	uint32 TestRes;
	EthCFG m_eth_cfg;
	CryptErrors CrTestRes[2];
//	kdg_rez_test rezult[2];
	uint16 KEY;

    
tst_kan_rej:

	T_clrbar_D(4,12);	
	gotoxy(0,4);
	cprintf("Шифрование из eth%d в eth%d",eth_send,eth_recv);
	gotoxy(0,15);
	cprintf("<ESC - Стоп>");

	m_eth_cfg.eth_send = eth_send;
	m_eth_cfg.eth_recv = eth_recv;

	Send_cmd_main(START_TEST_CR_CH);
	msg_send(msg_pid_main, &m_eth_cfg, sizeof(m_eth_cfg));

	do
	{
		sleep_s(1);

			Send_cmd_comm(eth_send, RES_TEST_CR_CH);
			res = receive_msg(CrTestRes, sizeof(CryptErrors)*2, MSG_WAIT_DEBUG );
			if(res == MSG_ER_TIME_OUT)
			{
				print_err("IFACE", COMM_TIME_OUT + eth_send);
				goto end_tst_kan_rej;
			}
			if(res == MSG_ER_SYNC)
			{
				print_err("IFACE", COMM_ERR_MSG + eth_send);
				goto end_tst_kan_rej;
			}

		gotoxy(0,6);
		cprintf("Прошло тестов:     %8d",CrTestRes[0].NumPack);

		gotoxy(0,7);
		cprintf("-потеряно пакетов:   %6d",CrTestRes[0].LostPack);

		gotoxy(0,8);
		cprintf("-разные пакеты от ЦП:%6d",CrTestRes[0].CMPerr);

		gotoxy(0,10);
		cprintf("Ошибок:            ЦП0|    ЦП1");

		gotoxy(0,11);     
		cprintf("-имитовставки:  %6d| %6d",CrTestRes[0].ImvErr, CrTestRes[1].ImvErr);

		gotoxy(0,12);
		cprintf("-в теле пакета: %6d| %6d",CrTestRes[0].BodyErr, CrTestRes[1].BodyErr);

		gotoxy(0,13);
		cprintf("-контр-го байта:%6d| %6d",CrTestRes[0].CtrBErr, CrTestRes[1].CtrBErr);

	}
	while( kb_hit() != KEY_ESC );

	Send_cmd_main(STOP_TEST_CR_CH);

	gotoxy(0,15);
	cprintf("<Enter>-Еще раз. <Esc>-Выход.\n");

	do
	KEY = getch();
	while((KEY != KEY_ENTER) & (KEY != KEY_ESC));

	if(KEY == KEY_ENTER)
	goto tst_kan_rej;

end_tst_kan_rej:

Send_cmd_main(STOP_TEST_CR_CH);

}




void F_CrChannelCfgEth0_1(cs_menu* m, void* arg)
{
	F_CrChannelCfgEth(0,1);

}

void F_CrChannelCfgEth0_2(cs_menu* m, void* arg)
{
	F_CrChannelCfgEth(0,2);

}

void F_CrChannelCfgEth1_0(cs_menu* m, void* arg)
{
	F_CrChannelCfgEth(1,0);

}


/*

void AboutUSB(uint32 device_id)
{

	char fstr[8];
	char devv[6];
	char* name;

    char	file_path[32];
    FILE*	file;

//для определения ФС
	
	FS_UINT16 res;
	FS_UINT16 ldIndex;
	LogicDiskInfo *ldInfo;
	FS_CHAR logicDiskLetter;
	
	uint32 ms;
	s_msd_capacity  capacity;
    s_msd_vendor    vendor;

  

	if(Chek_usb_dev(device_id) == TPO_OK) 
	{

	    if(device_id == 1)
		{
		   	strcpy(file_path, "/vfat/a/test1.bin");
			strcpy(devv,"msd12");
			logicDiskLetter = 'a';
		}
	    if(device_id == 2)
		{
	    	strcpy(file_path, "/vfat/b/test1.bin");
			strcpy(devv,"msd13");
			logicDiskLetter = 'b';
		}

	    file = fopen(file_path, "wb");
	    if(file != NULL)
    	{
		fclose(file);
		remove(file_path);
		}

   		ms = drv_mkd("/dev/sd2u0");
	    drv_ioctl(ms, MSD_DEVICE_NAME, &name);

		if(memcmp(name, devv, 5))
		{
   			drv_rmd(ms);
	   		ms = drv_mkd("/dev/sd3u0");
		}

					
	    drv_ioctl(ms, MSD_VENDOR, &vendor);
		drv_ioctl(ms, MSD_CAPACITY, &capacity);
//для определения ФС
	
		memset(fstr,0,sizeof(fstr));
		ldIndex = fsUtils::upCase(logicDiskLetter) - 'A';

		res = logicDisk.getInfo( ldIndex, &ldInfo );

		switch( ldInfo->fsType )
		{
			case FS_NO:	  strcpy(fstr,"НЕТ");
						  break;					    
			case FS_FAT12:strcpy(fstr,"FAT12");
						  break;
			case FS_FAT16:strcpy(fstr,"FAT16");
						  break;	
			case FS_FAT32:strcpy(fstr,"FAT32");
						  break;
			default:strcpy(fstr,"ERROR");

		}

		gotoxy(0,4);
		cprintf("Производитель:%s",vendor.vendor_identification);
		gotoxy(0,6);
		cprintf("Модель флэшки:%s",vendor.product_identification);
		gotoxy(0,8);
		cprintf("Номер ревизии:%s",vendor.product_revision_level);


		gotoxy(0,10);
		cprintf("Размер сектора:%d",capacity.block_length);
		gotoxy(0,12);
		cprintf("Емкость флэшки:%lu",capacity.flash_capacity);
		gotoxy(0,14);
		cprintf("Файловая система:%s",fstr);
	
    drv_rmd(ms);
  	getch();      
	}
//	return 0;
}
*/
//-------------------------------------------------------------------------------------------------
void F_AboutUSB_CP(cs_menu* m, void* arg)
{
int32 res = 0;
uint32* n_usb = (uint32*)arg;
uint16 KEY;
about_usb usb_cp[2];
/*
{
	uint32		enable;
    uint32      block_length;
    uint64      flash_capacity;              
    char        vendor_identification[10];
    char        product_identification[17];
    char        product_revision_level[5];
	char 		fstr[8];
}
*/
	clrscr();

	gotoxy(0,2);
	cprintf("Информация о USB носителе \n");
	cprintf("               %d канала", n_usb[0]-1);

//	AboutUSB(n_usb[0]);

	Send_cmd_main(INF_ABOUT_USB);

	Send_cmd_comm(MIN_NUMBER_COMM, INF_ABOUT_USB);

	res = receive_msg(&usb_cp, sizeof(about_usb)*2, MSG_WAIT_DEBUG );

	if(res == MSG_ER_TIME_OUT)
	{
		print_err("IFACE", COMM_TIME_OUT);
		return;
	}
	if(res == MSG_ER_SYNC)
	{
		print_err("IFACE", COMM_ERR_MSG);
		return;
	}


	if(usb_cp[n_usb[0]-1].enable == ENABLE_FLASH)
	{
		gotoxy(0,4);
		cprintf("Производитель:%s",usb_cp[n_usb[0]-1].vendor_identification);
		gotoxy(0,6);
		cprintf("Модель флэшки:%s",usb_cp[n_usb[0]-1].product_identification);
		gotoxy(0,8);
		cprintf("Номер ревизии:%s",usb_cp[n_usb[0]-1].product_revision_level);


		gotoxy(0,10);
		cprintf("Размер сектора:%d",usb_cp[n_usb[0]-1].block_length);
		gotoxy(0,12);
		cprintf("Емкость флэшки:%lu",usb_cp[n_usb[0]-1].flash_capacity);
		gotoxy(0,14);
		cprintf("Файловая система:%s",usb_cp[n_usb[0]-1].fstr);
	}
	else
	{

	clrscr();
	gotoxy(3,7);
	cprintf("USB флэш не установлена");
	}

	gotoxy(0,15);
	cprintf("<Нажмите ESC>");
	while(1)
	{
	KEY = kb_hit();
	if(KEY == KEY_ESC)
	break;
	}
}



/*****************************************************************************
Syntax:   	    
Remarks:			    
*******************************************************************************/
void Tst_ipmp_main(cs_menu* m, void* arg)
{
uint16 KEY=0;

uint16 buf_wr[0x201];
uint16 buf_rd[0x201];

uint32 N_cikl=0;
uint32 err_iface=0;
uint32 err_main=0;

int32 res=0;

memset(buf_wr, 0, sizeof(buf_wr));

for(uint16 i = 1; i < 0x201; i++)
buf_wr[i] = i;

  start("Тест ipmp ЦП");
    
tst_ipmp_main:

	T_clrbar_D(4,12);	
	gotoxy(0,15);
	cprintf("<ESC - Стоп>");

	do
	{
	
		Send_cmd_main(TEST_IPMP);
	
		msg_send(msg_pid_main, buf_wr, sizeof(buf_wr));
		
		memset(buf_rd, 0, sizeof(buf_rd));
		res = receive_msg(buf_rd, sizeof(buf_rd), MSG_WAIT_DEBUG );

		if(res == MSG_ER_TIME_OUT)
		{
			print_err("IFACE", MAIN_TIME_OUT);
		}
		
		if(res == MSG_ER_SYNC)
		{
			print_err("IFACE", MAIN_ERR_MSG);
		}	
	

		if(buf_rd[0] != TPO_OK)
			err_main++;

		if(memcmp(&buf_wr[1], &buf_rd[1], sizeof(buf_wr)-2))
			err_iface++;

		N_cikl++;

		gotoxy(0,6);
		cprintf("Прошло тестов:  %7d",N_cikl);

		gotoxy(0,8);
		cprintf("Ошибок:");

		gotoxy(0,10);
		cprintf("-ПП->ЦП:        %7d",err_main);

		gotoxy(0,12);
		cprintf("-ЦП->ПП:        %7d",err_iface);


	}
	while( kb_hit() != KEY_ESC );

	gotoxy(0,15);
	cprintf("<Enter>-Еще раз. <Esc>-Выход.\n");

	do
	KEY = getch();
	while((KEY != KEY_ENTER) & (KEY != KEY_ESC));

	if(KEY == KEY_ENTER)
	goto tst_ipmp_main;
}


/*****************************************************************************
Syntax:   void Tst_ipmp_comm(cs_menu* m, void* arg)   	    
Remarks:			    
*******************************************************************************/
void Tst_ipmp_comm(cs_menu* m, void* arg)
{
uint16 KEY=0;

uint16 buf_wr[0x201];
uint16 buf_rd[0x201];

uint32 N_cikl=0;
uint32 err_iface[3];
uint32 err_comm[3];
int32 res=0;

memset(err_iface, 0, sizeof(err_iface));
memset(err_comm, 0, sizeof(err_comm));

memset(buf_wr, 0, sizeof(buf_wr));

for(uint16 i = 1; i < 0x201; i++)
buf_wr[i] = i;

  start("Тест ipmp CП");
    
tst_ipmp_comm:

	T_clrbar_D(4,12);	
	gotoxy(0,15);
	cprintf("<ESC - Стоп>");

	do
	{
	for(uint32 i = 0; i < 2; i++)
	{

		Send_cmd_comm(i,TEST_IPMP);
//		Send_cmd_comm(1,TEST_IPMP);

		msg_send(pid_comm[i].pid, buf_wr, sizeof(buf_wr));
//		msg_send(pid_comm[1].pid, buf_wr, sizeof(buf_wr));
		
		memset(buf_rd, 0, sizeof(buf_rd));
		res = receive_msg(buf_rd, sizeof(buf_rd), MSG_WAIT_DEBUG );

		if(res == MSG_ER_TIME_OUT)
			print_err("IFACE", COMM_TIME_OUT+i);
		if(res == MSG_ER_SYNC)
			print_err("IFACE", COMM_ERR_MSG+i);
	

		if(buf_rd[0] != TPO_OK)
			err_comm[i]++;

		if(memcmp(&buf_wr[1], &buf_rd[1], sizeof(buf_wr)-2))
			err_iface[i]++;

	}
		N_cikl++;

		gotoxy(0,5);
		cprintf("Прошло тестов:  %7d",N_cikl);

		gotoxy(0,6);
		cprintf("Ошибок:");

		gotoxy(0,8);
		cprintf("-ПП->CП0:        %7d",err_comm[0]);

		gotoxy(0,9);
		cprintf("-CП0->ПП:        %7d",err_iface[0]);

		gotoxy(0,10);
		cprintf("-ПП->CП1:        %7d",err_comm[1]);

		gotoxy(0,11);
		cprintf("-CП1->ПП:        %7d",err_iface[1]);

		gotoxy(0,12);
		cprintf("-ПП->CП2:        %7d",err_comm[1]);

		gotoxy(0,13);
		cprintf("-CП2->ПП:        %7d",err_iface[1]);
	}
	while( kb_hit() != KEY_ESC );

	gotoxy(0,15);
	cprintf("<Enter>-Еще раз. <Esc>-Выход.\n");

	do
	KEY = getch();
	while((KEY != KEY_ENTER) & (KEY != KEY_ESC));

	if(KEY == KEY_ENTER)
	goto tst_ipmp_comm;
}







//ТПО для 5
#ifdef TPO5

				//extern void* OS_START_PO_ADDR;
				//extern void* OS_LEN_LOAD_PO;
				//_OS_START_PO_ADDR = 0x00054000;        
				//_OS_LEN_LOAD_PO   = 0x00055000;        
				//void* OS_START_PO_ADD = (void*) 0x00054000;
				//void* OS_LEN_LOAD = (void*) 0x00055000;
				//void* OS_START_PO_ADD = (void*) 0x00080000;
				//void* OS_LEN_LOAD = (void*) 0x00029000;
				//extern int32     os_lif_load_fixed( const char* fname, void* prg_mem, const char* args, uint32 type, uint32 paddr, uint32 psize );

/*****************************************************************************
Syntax:   void F_load_lif(cs_menu* m, void* arg)   	    
Remarks:			    
*******************************************************************************/
void F_load_lif(cs_menu* m, void* arg)
	{

	 char				file_path[32];
	 uint16 			KEY;

	 File_lif 			files[3];
	 int32				error = 0;

	 s_os_mem_block*    mem_block;
	 uint8*             buf;

	 kdg_cmd			to_main;
	 kdg_cmd_ask		cdg_error;
	// int32		error;
	 
	 uint8				block[128];
	 uint32				N_block;
	 uint32				len;

	 arg_exit_tpo* exit_tpo = (arg_exit_tpo*)arg;

	 con_clrscr(USER_CON);
	 con_clrscr(SYS_CON);
	/*
	if(D)
	{
		for(int i = MIN_NUMBER_COMM; i < NUMBER_COMM_DSP; i++)
		Send_cmd_comm(i, EXIT_TPO);

		Send_cmd_main(EXIT_TPO);
	}
	*/


	if(Chek_usb_dev(2) != TPO_OK) 
	return;


	strcpy(file_path, "/vfat/b/bpo-iface.lif");

		files[0].file = drv_mkd(file_path);
		if(files[0].file == RES_VOID)
		{
		clrscr();
		gotoxy(3,7);
		cprintf("Невозможно открыть файл:");
		gotoxy(6,8);
		cprintf("tpo-iface.lif");
		gotoxy(0,15);
		cprintf("<Нажмите ESC>");
		 while(1)
		 {
		 KEY = kb_hit();
		 if(KEY == KEY_ESC)
		 break;
		 }
		return;
		}
		else
		 if(drv_open(files[0].file, DRV_RD) == OSE_OK)
		   if(drv_ioctl(files[0].file, IOC_SIZE, &files[0].len) != OSE_OK)
		   {
			error = 1;
			goto err_file;
		   }
		

	strcpy(file_path, "/vfat/b/bpo-main.lif");

		files[1].file = drv_mkd(file_path);
		if(files[1].file == RES_VOID)
		{
		clrscr();
		gotoxy(3,7);
		cprintf("Невозможно открыть файл:");
		gotoxy(6,8);
		cprintf("tpo-main.lif");
		gotoxy(0,15);
		cprintf("<Нажмите ESC>");
		 while(1)
		 {
		 KEY = kb_hit();
		 if(KEY == KEY_ESC)
		 break;
		 }
		return;
		}
		else
		  if(drv_open(files[1].file, DRV_RD) == OSE_OK)
			if(drv_ioctl(files[1].file, IOC_SIZE, &files[1].len) != OSE_OK)
		   {
			error = 1;
			goto err_file;
		   }

	strcpy(file_path, "/vfat/b/bpo-comm.lif");

		files[2].file = drv_mkd(file_path);
		if(files[2].file == RES_VOID)
		{
		clrscr();
		gotoxy(3,7);
		cprintf("Невозможно открыть файл:");
		gotoxy(6,8);
		cprintf("tpo-comm.lif");
		gotoxy(0,15);
		cprintf("<Нажмите ESC>");
		 while(1)
		 {
		 KEY = kb_hit();
		 if(KEY == KEY_ESC)
		 break;
		 }
		return;
		}
		else
		  if(drv_open(files[2].file, DRV_RD) == OSE_OK)
			if(drv_ioctl(files[2].file, IOC_SIZE, &files[2].len) != OSE_OK)
		   {
			error = 1;
			goto err_file;
		   }



		Send_cmd_main(LOAD_LIF);
		Send_cmd_comm(0, LOAD_LIF);
		Send_cmd_comm(1, LOAD_LIF);

			sleep_m(500);


	//Длинну на центральный
	  to_main.cmd = files[1].len;
	  msg_send(msg_pid_main, &to_main, sizeof(kdg_cmd));
	  error = receive_msg(&cdg_error, sizeof(kdg_cmd_ask), MSG_WAIT_DEBUG);

	  if(error == MSG_ER_TIME_OUT)
		print_err("IFACE", MAIN_TIME_OUT);
	  if(error == MSG_ER_SYNC)
		print_err("IFACE", MAIN_ERR_MSG);
	  if(cdg_error.ask == TPO_ERR)
	  {
		print_err("IFACE", NO_MEM_MAIN);
		return;
	  }

			sleep_m(500);


	//Длинну на сетевые
	 to_main.cmd = files[2].len;
	 for(int n_comm = 0; n_comm < 2; n_comm++)
	 {
	  msg_send(pid_comm[n_comm].pid, &to_main, sizeof(kdg_cmd));
	  error = receive_msg(&cdg_error, sizeof(kdg_cmd_ask), MSG_WAIT_DEBUG);

	  if(error == MSG_ER_TIME_OUT)
		print_err("IFACE", COMM_TIME_OUT+n_comm);
	  if(error == MSG_ER_SYNC)
		print_err("IFACE", COMM_ERR_MSG+n_comm);
	  if(cdg_error.ask == TPO_ERR)
	  {
		print_err("IFACE", NO_MEM_COMM+n_comm);
		return;
	  }

	 }

			sleep_m(500);

	//выделяем место на iface
	  mem_block = mem_alloc(files[0].len, MPAGE_ALL);
	  if(mem_block != NULL)
	  {
	  buf = (uint8*)mem_ptr(mem_block);
	   if( drv_read(files[0].file, buf, files[0].len) != files[0].len )
		goto err_file;
	  }
	  else
	  {
		mem_free(mem_block);
		print_err("IFACE", NO_MEM_IFACE);
		return;
	  }

			sleep_m(500);


	//перебрасываем на comm
	N_block = (files[2].len/sizeof(block))+1;
	for(int N = 0; N < N_block; N++)
	{
	len = drv_read(files[2].file, block, sizeof(block));

	 for(int n_comm = 0; n_comm < 2; n_comm++)
	 {
	  msg_send(pid_comm[n_comm].pid, block, len);
	  error = receive_msg(&cdg_error, sizeof(kdg_cmd_ask), MSG_WAIT_DEBUG);

	  if(error == MSG_ER_TIME_OUT)
		print_err("IFACE", COMM_TIME_OUT+n_comm);
	  if(error == MSG_ER_SYNC)
		print_err("IFACE", COMM_ERR_MSG+n_comm);
	  if(cdg_error.ask == TPO_ERR)
	  {
		print_err("IFACE", COMM_ERR_MSG+n_comm);
		return;
	  }

	 }

	}

			sleep_m(500);

	//перебрасываем на main
	N_block = (files[1].len/sizeof(block))+1;
	for(int N = 0; N < N_block; N++)
	{
	len = drv_read(files[1].file, block, sizeof(block));

	  msg_send(msg_pid_main, block, len);
	  error = receive_msg(&cdg_error, sizeof(kdg_cmd_ask), MSG_WAIT_DEBUG);

	  if(error == MSG_ER_TIME_OUT)
		print_err("IFACE", MAIN_TIME_OUT);
	  if(error == MSG_ER_SYNC)
		print_err("IFACE", MAIN_ERR_MSG);
	  if(cdg_error.ask == TPO_ERR)
	  {
		print_err("IFACE", MAIN_ERR_MSG);
		return;
	  }

	}


	drv_close(files[0].file);
	drv_close(files[1].file);
	drv_close(files[2].file);

	drv_rmd(files[0].file);
	drv_rmd(files[1].file);
	drv_rmd(files[2].file);


		Send_cmd_comm(0, START_LIF);
		Send_cmd_comm(1, START_LIF);
		Send_cmd_main(START_LIF);





	load_lif(buf);
	mem_free(mem_block);


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




	con_clrscr(USER_CON);
	con_clrscr(SYS_CON);
	con_deinit();

	msg_close();
	//delete(menu_tpo);
	exit_tpo->menu->~cs_menu();

	uint32 file = drv_mkd("/vfat/");
	drv_ioctl(file, FSI_RESET, NULL);

	prc_exit();
	while(1);

	err_file:

		clrscr();
		gotoxy(3,7);
		cprintf("Ошибка работы с файлом:");
		gotoxy(0,15);
		cprintf("<Нажмите ESC>");
		 while(1)
		 {
		 KEY = kb_hit();
		 if(KEY == KEY_ESC)
		 break;
		 }
		return;

	}

#endif  /////////////////////END  TPO5


/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
void Osveschennost(cs_menu* m, void* arg)
{


	uint16 KEY=0;
    int32 res = 0;
	kdg_rez_test rezult;    


//  start("Контрольная сумма за ПО");

tst_dnsd_osvesch:
    
	T_clrbar_D(4,12);	

	gotoxy(3,8);
	cprintf("Освещенность датчика");

	gotoxy(10,9);
	cprintf("ЖДИТЕ...");

	res = Send_Receve_N_Test(msg_pid_main, TEST_DNSD_OSVESCH, &rezult);

	if(res== MSG_ER_TIME_OUT)
	{
		print_err("IFACE", MAIN_TIME_OUT);
		return;
	}
	
	if(res == MSG_ER_SYNC)
	{
		print_err("IFACE", MAIN_ERR_MSG);
		return;
	}



//	gotoxy(5,6);
//	cprintf("%d%%",rezult.data);

	gotoxy(10,9);
	cprintf("0x%04X",rezult.rez);



	gotoxy(0,15);
	cprintf("<Enter>-Еще раз. <Esc>-Выход.\n");

	do
	KEY = getch();
	while((KEY != KEY_ENTER) & (KEY != KEY_ESC));

	if(KEY == KEY_ENTER)
	goto tst_dnsd_osvesch;

}




/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
void Magic_Number(cs_menu* m, void* arg)
{


	uint16 KEY=0;
    int32 res = 0;
	kdg_rez_test rezult;    


//  start("Контрольная сумма за ПО");

tst_dnsd_magic:
    
	T_clrbar_D(4,12);	

	gotoxy(3,8);
	cprintf("Magic Number");

	gotoxy(10,9);
	cprintf("ЖДИТЕ...");

	res = Send_Receve_N_Test(msg_pid_main, MAGIC_NUMBER, &rezult);

	if(res== MSG_ER_TIME_OUT)
	{
		print_err("IFACE", MAIN_TIME_OUT);
		return;
	}
	
	if(res == MSG_ER_SYNC)
	{
		print_err("IFACE", MAIN_ERR_MSG);
		return;
	}



//	gotoxy(5,6);
//	cprintf("Magic number:%d%%",rezult.rez);

	gotoxy(10,9);
	cprintf("0x%08X",rezult.rez);



	gotoxy(0,15);
	cprintf("<Enter>-Еще раз. <Esc>-Выход.\n");

	do
	KEY = getch();
	while((KEY != KEY_ENTER) & (KEY != KEY_ESC));

	if(KEY == KEY_ENTER)
	goto tst_dnsd_magic;

}





/*****************************************************************************
Syntax:     void Dnsd_crc_po(cs_menu* m, void* arg)  	    
Remarks:	Видимо Тест Датчика Вскрытия ??		    
*******************************************************************************/
void Dnsd_crc_po(cs_menu* m, void* arg)
{


	uint16 KEY=0;
    int32 res = 0;
	kdg_rez_test rezult;    


//  start("Контрольная сумма за ПО");

tst_dnsd_crc:
    
	T_clrbar_D(4,12);	

	gotoxy(3,8);
	cprintf("Контрольная сумма за ПО");

	gotoxy(10,9);
	cprintf("ЖДИТЕ...");

	res = Send_Receve_N_Test(msg_pid_main, TEST_DNSD_CRC, &rezult);

	if(res== MSG_ER_TIME_OUT)
	{
		print_err("IFACE", MAIN_TIME_OUT);
		return;
	}
	
	if(res == MSG_ER_SYNC)
	{
		print_err("IFACE", MAIN_ERR_MSG);
		return;
	}



	gotoxy(5,6);
	cprintf("Заряда батареи:%d%%",rezult.data);

	gotoxy(10,9);
	cprintf("0x%08X",rezult.rez);



	gotoxy(0,15);
	cprintf("<Enter>-Еще раз. <Esc>-Выход.\n");

	do
	KEY = getch();
	while((KEY != KEY_ENTER) & (KEY != KEY_ESC));

	if(KEY == KEY_ENTER)
	goto tst_dnsd_crc;

}



/*****************************************************************************
Syntax:   void Dnsd_rasshiren_test(cs_menu* m, void* arg)   	    
Remarks:  Видимо Тест Датчика Вскрытия ??	    
*******************************************************************************/
void Dnsd_rasshiren_test(cs_menu* m, void* arg)
{
//TEST_DNSD_RASSH,
/*
uint32 errTimeout;//Ошибок timeout
uint32 errReadC0;//Ошибок чтения C0
uint32 errTrigger;//Ошибок срабатывания
}TestDnsdRes;  
*/

//	comm_status* n_eth = (comm_status*)arg;
	uint16 KEY;
	int32 res;
	TestDnsdRes DnsdRes;
	uint32 io_cycle;
	kdg_rez_test rezult;        
	uint32 Ycon = 6;
	uint32* n_usb = (uint32*)arg;



	if(n_usb[0]==0)
	{
		start("Тест VD10");
	}
	else
	{
		start("Тест VD11");
	}

    
tst_dnsd:

	T_clrbar_D(4,12);	
	gotoxy(0,15);
	cprintf("<ESC - Стоп>");

	io_cycle = 0;

	memset(&DnsdRes,0,sizeof(DnsdRes));

	do
	{                            
	if(n_usb[0]==0)
		res = Send_Receve_N_Test(msg_pid_main, TEST_DNSD_VD10, &rezult);
	else
		res = Send_Receve_N_Test(msg_pid_main, TEST_DNSD_VD11, &rezult);

	if(res== MSG_ER_TIME_OUT)
	{
		print_err("IFACE", MAIN_TIME_OUT);
		return;
	}
	
	if(res == MSG_ER_SYNC)
	{
		print_err("IFACE", MAIN_ERR_MSG);
		return;
	}

		if(rezult.rez & ERR_DNSD_TIMEOUT)
			DnsdRes.errTimeout++;
		if(rezult.rez & ERR_DNSD_READ_C0)
		{
			DnsdRes.errReadC0++;		
	
	gotoxy(0,9);
	cprintf("0x%2X",rezult.buf[11]);
	cprintf("%2X",rezult.buf[10]);
	cprintf("%2X",rezult.buf[9]);
	cprintf("%2X",rezult.buf[8]);
	cprintf("%2X",rezult.buf[7]);
	cprintf("%2X",rezult.buf[6]);
	cprintf("%2X",rezult.buf[5]);
	cprintf("%2X",rezult.buf[4]);
	cprintf("%2X",rezult.buf[3]);
	cprintf("%2X",rezult.buf[2]);
	cprintf("%2X",rezult.buf[1]);
	cprintf("%2X",rezult.buf[0]);
	gotoxy(0,10);
	cprintf("0x%2X",rezult.buf[23]);
	cprintf("%2X",rezult.buf[22]);
	cprintf("%2X",rezult.buf[21]);
	cprintf("%2X",rezult.buf[20]);
	cprintf("%2X",rezult.buf[19]);
	cprintf("%2X",rezult.buf[18]);
	cprintf("%2X",rezult.buf[17]);
	cprintf("%2X",rezult.buf[16]);
	cprintf("%2X",rezult.buf[15]);
	cprintf("%2X",rezult.buf[14]);
	cprintf("%2X",rezult.buf[13]);
	cprintf("%2X",rezult.buf[12]);
	gotoxy(0,11);
	cprintf("0x%2X",rezult.buf[31]);
	cprintf("%2X",rezult.buf[30]);
	cprintf("%2X",rezult.buf[29]);
	cprintf("%2X",rezult.buf[28]);
	cprintf("%2X",rezult.buf[27]);
	cprintf("%2X",rezult.buf[26]);
	cprintf("%2X",rezult.buf[25]);
	cprintf("%2X",rezult.buf[24]);

	KEY = getch();
		}
		if(rezult.rez & ERR_DNSD_TRIGGER)
			DnsdRes.errTrigger++;		

		if(res == TPO_ERR)
		{
			gotoxy(7,7);
			cprintf("ОШИБКА ОБМЕНА !\n");
			getch();
			return;
		}

		io_cycle++;
		Ycon = 6;

		gotoxy(0,4);
		cprintf("Прошло тестов:       %7d",io_cycle);


		gotoxy(1,Ycon);
		Ycon +=2; 
		cprintf("-Ошибок таймаута:    %7d",DnsdRes.errTimeout);

		gotoxy(1,Ycon);
		Ycon +=2; 
		cprintf("-Ошибок чтения C0:   %7d",DnsdRes.errReadC0);

		gotoxy(1,Ycon);
		cprintf("-Ошибок срабатывания:%7d",DnsdRes.errTrigger);
		
	}
	while( kb_hit() != KEY_ESC );

	KEY = getch();

//  }

		gotoxy(0,15);
		cprintf("<Enter>-Еще раз. <Esc>-Выход.\n");

		do
		KEY = getch();
		while((KEY != KEY_ENTER) & (KEY != KEY_ESC));

		if(KEY == KEY_ENTER)
		goto tst_dnsd;

}

/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
void ZavestiDNSD(cs_menu* m, void* arg)
{


	uint16 KEY=0;
    int32 res = 0;
	kdg_rez_test rezult;    


//  start("Контрольная сумма за ПО");

   
	T_clrbar_D(4,12);	

	gotoxy(10,9);
	cprintf("ЖДИТЕ...");

	res = Send_Receve_N_Test(msg_pid_main, ZAVESTI_DNSD, &rezult);

	if(res== MSG_ER_TIME_OUT)
	{
		print_err("IFACE", MAIN_TIME_OUT);
		return;
	}
	
	if(res == MSG_ER_SYNC)
	{
		print_err("IFACE", MAIN_ERR_MSG);
		return;
	}



	gotoxy(0,15);
	cprintf("<Esc>-Выход.\n");

	do
	KEY = getch();
	while((KEY != KEY_ESC));


}
/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
void Vkluchit_VD(cs_menu* m, void* arg)
{


//	uint16 KEY=0;
    int32 res = 0;
	kdg_rez_test rezult;    

	uint32* n_usb = (uint32*)arg;

//  start("Контрольная сумма за ПО");

	if(n_usb[0]==0)
	res = Send_Receve_N_Test(msg_pid_main, VKL_VD10, &rezult);
	else
	res = Send_Receve_N_Test(msg_pid_main, VKL_VD11, &rezult);


}

/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
void Vikluchit_VD(cs_menu* m, void* arg)
{
//	uint16 KEY=0;
    int32 res = 0;
	kdg_rez_test rezult;    

//	uint32* n_usb = (uint32*)arg;

//  start("Контрольная сумма за ПО");

	res = Send_Receve_N_Test(msg_pid_main, VIKL_VD11, &rezult);


}

/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
void Prochitat(cs_menu* m, void* arg)
{


	uint16 KEY=0;
    int32 res = 0;
	kdg_rez_test rezult;    


//  start("Контрольная сумма за ПО");

dnsd_read:
    
	T_clrbar_D(4,12);	

	gotoxy(3,8);
	cprintf("Прочитать С0");

	gotoxy(10,9);
	cprintf("ЖДИТЕ...");

	res = Send_Receve_N_Test(msg_pid_main, PROCHITAT, &rezult);

	if(res== MSG_ER_TIME_OUT)
	{
		print_err("IFACE", MAIN_TIME_OUT);
		return;
	}
	
	if(res == MSG_ER_SYNC)
	{
		print_err("IFACE", MAIN_ERR_MSG);
		return;
	}



	gotoxy(0,9);
	cprintf("0x%2X",rezult.buf[11]);
	cprintf("%2X",rezult.buf[10]);
	cprintf("%2X",rezult.buf[9]);
	cprintf("%2X",rezult.buf[8]);
	cprintf("%2X",rezult.buf[7]);
	cprintf("%2X",rezult.buf[6]);
	cprintf("%2X",rezult.buf[5]);
	cprintf("%2X",rezult.buf[4]);
	cprintf("%2X",rezult.buf[3]);
	cprintf("%2X",rezult.buf[2]);
	cprintf("%2X",rezult.buf[1]);
	cprintf("%2X",rezult.buf[0]);
	gotoxy(0,10);
	cprintf("0x%2X",rezult.buf[23]);
	cprintf("%2X",rezult.buf[22]);
	cprintf("%2X",rezult.buf[21]);
	cprintf("%2X",rezult.buf[20]);
	cprintf("%2X",rezult.buf[19]);
	cprintf("%2X",rezult.buf[18]);
	cprintf("%2X",rezult.buf[17]);
	cprintf("%2X",rezult.buf[16]);
	cprintf("%2X",rezult.buf[15]);
	cprintf("%2X",rezult.buf[14]);
	cprintf("%2X",rezult.buf[13]);
	cprintf("%2X",rezult.buf[12]);
	gotoxy(0,11);
	cprintf("0x%2X",rezult.buf[31]);
	cprintf("%2X",rezult.buf[30]);
	cprintf("%2X",rezult.buf[29]);
	cprintf("%2X",rezult.buf[28]);
	cprintf("%2X",rezult.buf[27]);
	cprintf("%2X",rezult.buf[26]);
	cprintf("%2X",rezult.buf[25]);
	cprintf("%2X",rezult.buf[24]);


	gotoxy(0,15);
	cprintf("<Enter>-Еще раз. <Esc>-Выход.\n");

	do
	KEY = getch();
	while((KEY != KEY_ENTER) & (KEY != KEY_ESC));

	if(KEY == KEY_ENTER)
	goto dnsd_read;

}

