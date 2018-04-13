/**********************************************************************************************************************
*                                        (c) COPYRIGHT by ZAO RCZI FORT.                                             *
*        ..                                       All rights reserved.                                               *
***********************************************************************************************************************
* Module      : tpo_main.cpp
* Description : Функция ТПО старта Центральных Процессоров СВ-043
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
#include <drv_fwmem.h>

#include "tpo.h"
#include "tests.h"
#include "tpo_hash.h"
#include "sialp.h"
#include "mem_test.h"
#include "test_crypt.h"

#ifndef TPO7
#include "crypter_15.h"
#endif
//#include "os_csl_mcbsp.h"

//#include "drv_mcbsp.h"

extern void load_lif(void* mem_lif);
extern void Load_lif_from_usb();


//----------------------------------------------------------------------------
hash_window hwindow[] =
{
  { 0x00000000, 0x0036FFFF },
  { 0x003F0000, 0x003FFFBF },
  { 0x00000000, 0x00000000 }
};

uint32 D = 1;

comm_status pid_comm[NUMBER_COMM_DSP];
//uint32 msg_pid_comm1;

#ifdef TPO5
	void* sh_mem_write[NUMBER_COMM_DSP]=
	{
		(void*)0x90000000,
		(void*)0x90001000,
		//(void*)0x90002000,
		//(void*)0x90003000,
	};
	void* sh_mem_read[NUMBER_COMM_DSP]=
	{
		(void*)0x90000000,
		(void*)0x90001000,
		//(void*)0x90002000,
		//(void*)0x90003000,
	};

#else TPO7  //М-632
	void* sh_mem_write[NUMBER_COMM_DSP]=
	{
	(void*)0xA0000000,
	(void*)0xA0002000,
	(void*)0xA0004000,
	};
	void* sh_mem_read[NUMBER_COMM_DSP]=
	{
	(void*)0xA0000000,
	(void*)0xA0002000,
	(void*)0xA0004000,
	};
#endif

uint32 ResAllTest = 0x00000000;	//результаты циклического тестирования


int NVRAM=0;	// 1 - сохранность данных после вкл питания 
				// 2 - ошибка адресный тест 

int SDRAM=0;  // 1 - ошибка адресный тест

int SP=0;       // 1 - нет ответа от 1СП
				// 2 - нет ответа от 2СП

int INTR=0;     // 1 - нет прерыв от 1СП
				// 2 - нет прерыв от 2СП

int SK=0;       // 1 - СК1 или СК2 неиспр 
				// 2 - СК1 или СК2 неиспр

int DOZU=0;     // 1 - ошибка адресный тест ДОЗУ (ЦП и 1СП )
				// 2 - ошибка адресный тест ДОЗУ (ЦП и 2СП )


int COMM_DOZU_COMM=0;     // 1 - ошибка адресный тест ДОЗУ (ЦП и 1СП (и шифратор))
					  	  // 2 - ошибка адресный тест ДОЗУ (ЦП и 2СП (и шифратор))

//int SPARKO=0;           // 1 - ошибка адресный тест ДОЗУ (ЦП и 1СП (и шифратор))

int USB=0;     

int SHIF=0;     


uint16  Next_cikl = 0;
uint16 	Start_cikl = 0;
uint16 	Dnsd_enn = 0;
uint32  Count_cikl=0;
uint16 	Usb_enn = 0;

uint16 Start_n_test = 0;
uint16 Start_dozu_nagr = 0;
uint16 Start_tst_rom = 0;
uint16 Start_tst_cr_ch = 0;
uint16	Start_move = 0;

EthCFG	to_from;
uint32  ResNTest = 0;
uint16  sv_msg_open=0;
kdg_rez_test gl_result;

CryptErrors* EncryptDecryptErr;

//----------------------------------------------------------------------------
int32 sv_msg_discover()
{

	char   name[16];
	if(D)
	{
	 	for(int i = MIN_NUMBER_COMM; i < NUMBER_COMM_DSP; i++)
		{
			sprintf(name, "comm%d",i);

			pid_comm[i].N = i;
			pid_comm[i].pid = msg_discover(name, "sv", MSG_WAIT_5);
			if(pid_comm[i].pid == RES_VOID)
			return TPO_ERR;
		}
	}

return TPO_OK;
}


extern void ReadDARAM(uint16 n_comm,uint16 addr,void* buf,uint16 len);
extern void WriteDARAM(uint16 n_comm,uint16 addr,void* buf,uint16 len);

//extern void si_load_key(uint32 num0, uint32 num1, int delay);


/*****************************************************************************
Syntax:  процесс для цикл. тестов и совместных тестов ЦП и СП    	    
Remarks:			    
*******************************************************************************/
int SV_Test(void* arg)
{

	uint64 adv = 0;
	uint32 error = 0;
	Start_cikl = 0;
	Start_n_test = 0;
	Start_move = 0;

	memset(&gl_result, 0, sizeof(kdg_rez_test));

	//si_load_key(0xFFFFFFFF, 0x55555555,1);


	  error = msg_open("sv");
	//  if(error != OSE_OK)
	//	while(1);

	  error = sv_msg_discover();
	//  if(error != TPO_OK)
	//	while(1);


	/*
		//debug!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		uint32 bufwr[0x380];
		uint32 bufrd[0x380];
		uint32 rezzz=0;

		uint32 err=0;

		for(int i=0;i<0x380;i++)
		bufwr[i]=i;

		while(1)
		{

		WriteDARAM(0,0,bufwr, 0x380*4);
		WriteDARAM(1,0,bufwr, 0x380*4);

		ReadDARAM(0,0,bufrd, 0x380*4);
		if(memcmp(bufrd, bufwr, 0x380*4))
		err++;

		ReadDARAM(0,0,bufrd, 0x380*4);
		if(memcmp(bufrd, bufwr, 0x380*4))
		err++;
		}
		//debug!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	*/


	/*
	//debug!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	uint32 N = 100;
	uint32 nnn[100];
	uint32 errN = 0;
	s_message*  msg_desc;

	uint64 rec = 0;
	uint64 wr = 0;

	for(int i=0;i<N;i++)
	nnn[i]=i;

	      msg_send(pid_comm[0].pid, nnn, sizeof(nnn));  
	      msg_send(pid_comm[1].pid, nnn, sizeof(nnn));  

	  while(true)
	  {

	    error = msg_recv(&msg_desc, MSG_WAIT_DEBUG);
		rec++;
	    if(msg_desc == NULL)
	    {
		prc_yield();
		errN++;
	    continue;
		}
		else
	    {

	      msg_send(msg_desc->from, nnn, sizeof(nnn));  
		  wr++;
	      msg_free(msg_desc);      
	      continue;
	    }
	   }
	//debug!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	*/



	while(sv_msg_open)
	{
//		if(Start_cikl)
		while(Start_cikl)
		{
			//еще не отпр за прошлый цикл...
			if(Next_cikl)
			{
				error = 0x12345678;
//				if(Dnsd_enn)
//				BeginTest(1);
				BeginTest(Usb_enn | Dnsd_enn, Count_cikl);
//				else
//				BeginTest(0);
//				BeginTest(Usb_enn | Dnsd_enn,Count_cikl);

//				if(ResAllTest)
//				syslog(114,"ResAllTest = %d ", ResAllTest);

//				syn_begin();
//				syn_end();
				Next_cikl = 0;//закончил цикл.. мона отправлять.
				adv = ResAllTest | (0x1234567800000000);
				WriteDARAM(MIN_NUMBER_COMM, 0xF00, &adv,8);
//				WriteDARAM(MIN_NUMBER_COMM, 4, &error,4);

			} //end if
		prc_yield();
	   }//end while Start_cikl

#ifndef TPO7 //Если не Определено ТПО7
	    switch (Start_n_test)
    	{

	      case TEST_DOZU:
		  {
			memset(&gl_result, 0, sizeof(kdg_rez_test));
			ResNTest = TestObmenDOZU_N_SP(0, &gl_result);
			Start_n_test = 0;
		  }
		  break;

	      case TEST_DOZU_ST1:
		  {
			memset(&gl_result, 0, sizeof(kdg_rez_test));
			ResNTest = TestObmenDOZU_N_SP(1, &gl_result);
			Start_n_test = 0;
		  }
		  break;

	      case TEST_DOZU_ST2:
		  {
			memset(&gl_result, 0, sizeof(kdg_rez_test));
			ResNTest = TestObmenDOZU_N_SP(2, &gl_result);
			Start_n_test = 0;
		  }
		  break;

	      case TEST_DOZU_ST3:
		  {
			memset(&gl_result, 0, sizeof(kdg_rez_test));
			ResNTest = TestObmenDOZU_N_SP(3, &gl_result);
			Start_n_test = 0;
		  }
		  break;

		  case TEST_MOVE:
		  {
			memset(&gl_result, 0, sizeof(kdg_rez_test));
			ResNTest = TestMoveDOZU_N_SP(0, &gl_result);
			Start_n_test = 0;
		  }
		  break;

		  case TEST_MOVE_ST1:
		  {
			memset(&gl_result, 0, sizeof(kdg_rez_test));
			ResNTest = TestMoveDOZU_N_SP(1, &gl_result);
			Start_n_test = 0;
		  }
		  break;

		  case TEST_MOVE_ST2:
		  {
			memset(&gl_result, 0, sizeof(kdg_rez_test));
			ResNTest = TestMoveDOZU_N_SP(2, &gl_result);
			Start_n_test = 0;
		  }
		  break;

		  case TEST_MOVE_ST3:
		  {
			memset(&gl_result, 0, sizeof(kdg_rez_test));
			ResNTest = TestMoveDOZU_N_SP(3, &gl_result);
			Start_n_test = 0;
		  }
		  break;
		
		  default:   //skd_add
		  break;
		
		}//end switch Start_n_test


		if(Start_dozu_nagr)
		{
		TestDOZU_Nagr();
		}

		if(Start_move)
		{
		Test_MOVE();
		}

		if(Start_tst_rom)
		{
		Test_ROM();
		}
#endif

#ifndef TPO7
		if(Start_tst_cr_ch)
		{
		CrypterChTestLoop();
		}
#endif

	prc_yield();
	
	}//End Gloabl While

msg_close();
//prc_exit();
//while(1);
return 0;
}

/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
int32 flash_chip_clear()
{
  volatile uint8& REG_555 = (*(uint8*)(0x64000000 + 0x00000555 ));
  volatile uint8& REG_AAA = (*(uint8*)(0x64000000 + 0x00000aaa ));
  uint32 offset;
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
void Load_po_flash()
{

	uint32		msg_from;
//	kdg_cmd		to_iface;
	kdg_cmd_ask	cdg_error;
	s_message*  msg_desc;
	uint8	buf[1024];
	uint32		flesh_offset = 0;
	uint32      fwm_file = RES_VOID;
	s_fwmem_rwbuf        fwrw;

	fwrw.buffer = buf;
	fwrw.length = 1024;
	
	
	fwm_file = drv_mkd("/fwmem");


  while(true)
  {
	if(msg_recv( &msg_desc, MSG_WAIT_5) != OSE_OK)

    if(msg_desc == NULL) continue;
	if(msg_desc->length < 1024) break;
			
    msg_from = msg_desc->from;
	memcpy(buf, msg_desc->data, msg_desc->length);
    msg_free(msg_desc);      

	drv_ioctl(fwm_file, FWMEM_WRITE, &fwrw);

	cdg_error.cmd = START_LOAD_PO;
	cdg_error.ask = TPO_OK;
	msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
	
  }

 drv_rmd(fwm_file);

}



/*****************************************************************************
Syntax:      	    
Remarks:			    
*******************************************************************************/
void Load_po_plis_si()
{

	uint32		msg_from;
	kdg_cmd_ask	cdg_error;
	s_message*  msg_desc;
	int res = 0;
	
    char	file_path[32];
	uint8   buf[1024];
    FILE*	file;
//	uint32		flesh_offset = 0;
//	uint32      fwm_file = RES_VOID;
//	s_fwmem_rwbuf        fwrw;

//	fwrw.buffer = buf;
//	fwrw.length = 1024;
	
	
   	strcpy(file_path, "/vfat/a/sv5_si.bin");

    file = fopen(file_path, "w");
    if(file == NULL) 
		return;



  while(true)
  {
	if(msg_recv( &msg_desc, MSG_WAIT_5) != OSE_OK)

    if(msg_desc == NULL) continue;
	if(msg_desc->length < 1024)
	{
    res = fwrite(buf, 1, msg_desc->length, file);
	cdg_error.cmd = WRITE_PO_TO_FLASH;
	cdg_error.ask = TPO_OK;
	msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
	break;
	}
			
    msg_from = msg_desc->from;
	memcpy(buf, msg_desc->data, msg_desc->length);
    msg_free(msg_desc);      

    res = fwrite(buf, 1, msg_desc->length, file);

	cdg_error.cmd = WRITE_PO_TO_FLASH;
	cdg_error.ask = TPO_OK;
	msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
	
  }



fclose(file);

}



//!!!!!!!debug
extern void alp_AbEncrypt(uint32 num0, uint32 num1, int delay);
extern void si_crypto(uint32 num0, uint32 num1, int delay);
extern void si_load_key(uint32 num0, uint32 num1, int delay);


//!!!!!!!debug

extern int32 tst_nvram_addr();


//    syslog( 4, "%s:drv_ioctl:%d: Null driver context (cmd = %08x dev = '%s')", os_module, __LINE__, cmd, d->path );

/*****************************************************************************
Syntax:  int tpo_main(void* arg)    	    
Remarks:			    
*******************************************************************************/
int tpo_main(void* arg)
{

    int32			error;
	uint32			cmd;
	uint32			msg_from;
//	kdg_cmd			to_iface;
	kdg_cmd_ask		cdg_error;
	kdg_rez_test	res_test;
	s_message*  	msg_desc;

	uint64 adv = 0;
	//alp_AbEncrypt(0, 0x00000000, 3);
	//sys_debug(1);
	//si_crypto(0X55555555, 0X33333333, 3);
	//error =  TestCelostnost();
	//si_load_key(0, 0xFFFFFFFF, 1);

	/*
	uint16* tre = (uint16*)0x68000000;
	memset(tre, 0, 0x100000);
	uint16 dart = 0;

	for(int g=0; g<0x80000; g++)
	{
	*tre++ = (uint16)(g & 0xFFFF);
	}
	tre = (uint16*)0x68000000;

	for(int g=0; g<0x80000; g++)
	{
	dart = *tre++;

	if((dart&0xFFFF) != (uint16)(g & 0xFFFF))
	dart++;
	}
	*/
	/*
	 uint64 ErrorsPositions1;
	 uint32 ErrorAddress1;
	 error = uniTestNVRAM( &ErrorsPositions1, &ErrorAddress1);
	*/



  	error = msg_open("tpo");
	//  if(error != OSE_OK)
	//	while(1);

	sv_msg_open = 1;
	s_prc_attr atr;
	memset( &atr, 0, sizeof(atr) );
	atr.stack = 4096*8;   
	error =	prc_create( &SV_Test, NULL, 0, &atr );
	/*
	#ifdef TPO6
		CrypterInit(); //init crypt!!!!!!!!!!1
	#endif
	*/


	/*
	kdg_rez_test result;     

	result.cmd = 0	//    
	    uint32	n_test;	//номер теста    
	    uint32	rez;	//результат теста(0- ok)    
	    uint32	adrr;	//адрес по которому произошла ошибка(если нужно)    
	    uint32	data;	//данные    
	*/

	/*
	uint32 red=0;

	while(1)
	red = TestCelostnost();
	*/
	//Start_Test_N(&result);



  while(true)
  {
    error = msg_recv(&msg_desc, MSG_WAIT_05);
    if(msg_desc == NULL)
    {
		prc_yield();
	    continue;
	}
    msg_from = msg_desc->from;
    cmd = ((kdg_cmd*)msg_desc->data)->cmd;

    if(msg_desc->length != sizeof(kdg_cmd))
    {
      cdg_error.cmd = ERROR_CMD;
      cdg_error.ask = TPO_ERR;
      msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));  
      msg_free(msg_desc);      
      continue;
    }
	cdg_error.cmd = ASK_CMD;

    msg_free(msg_desc);      

    switch (cmd)
    {
	  //Тесты СИ АЛП:
      case START_SIALP:
	  {
		cdg_error.ask = START_SIALP;
        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
        Test_sialp();
	  }
      break;

	  case START_CIKL:
	  {
		cdg_error.ask = START_CIKL;
        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));


		error = msg_recv(&msg_desc, MSG_WAIT_10);
	    if(msg_desc == NULL) continue;
	    if(msg_desc->length != sizeof(kdg_cmd))
	    {
	      cdg_error.cmd = ERROR_CMD;
		  cdg_error.ask = TPO_ERR;
//		  while(1);//нужно убрать
	    }

	    Dnsd_enn = (((kdg_cmd*)msg_desc->data)->cmd) & 0x1;; //выполнять тест днсд или нет
		Usb_enn = (((kdg_cmd*)msg_desc->data)->cmd) & 0x2;; //выполнять тест usb3 или нет
	    msg_free(msg_desc);      

		cdg_error.ask = Dnsd_enn | Usb_enn;
        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));

		Count_cikl = 0;
		Start_cikl = 1;
		Next_cikl = 1;
	  }
      break;

	  case GOTOV_PP:
	  {
		cdg_error.ask = GOTOV_PP;
		kdg_rez_test gotov;
		memset(&gotov, 0, sizeof(kdg_rez_test));
        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
		
#ifndef TPO7
		adv = 0;
		WriteDARAM(MIN_NUMBER_COMM, 0xF00, &adv,8);
#endif

 		if(gl_result.err != TPO_OK)
		{
		gotov.err = gl_result.err;
		gl_result.err = 0;
		}
        msg_send(msg_from, &gotov, sizeof(kdg_rez_test));

		Next_cikl = 1;
		Count_cikl++;


		/*
				gotov.cmd = RES_N_TEST;
				//еще не закончен цикл 
		syn_begin();
				if(Next_cikl == 1)
				{
				gotov.n_test = CIKL_NOT_READY;
				gotov.rez = 0; 
				}
				else
				{
				gotov.n_test = CIKL;
				gotov.rez = ResAllTest;
		//			if(!Stop_cikl)
				Next_cikl = 1;
				}
		syn_end();

		*/
 	  }
      break;

	  case STOP_CIKL:
	  {
		Start_cikl = 0;
		cdg_error.ask = STOP_CIKL;
        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
	  }
      break;

      case N_TEST:
	  {
		cdg_error.ask = N_TEST;
        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));

		kdg_rez_test result;
		memset(&result, 0, sizeof(kdg_rez_test));        
		error = msg_recv(&msg_desc, MSG_WAIT_1);
	    if(msg_desc == NULL) continue;
	    if(msg_desc->length != sizeof(kdg_rez_test))
	    {
	      cdg_error.cmd = ERROR_CMD;
		  cdg_error.ask = TPO_ERR;
		  while(1);//нужно убрать
	    }
		memcpy(&result, msg_desc->data, sizeof(kdg_rez_test));
	    msg_free(msg_desc);      

        Start_Test_N(&result);

		WriteDARAM(MIN_NUMBER_COMM,0,&result,sizeof(kdg_rez_test));

		memset(&result, 0, sizeof(kdg_rez_test));        
		result.cmd = RES_N_TEST;
 
 		if(gl_result.err != TPO_OK)
		{
		result.err = gl_result.err;
		gl_result.err = 0;
		}

        msg_send(msg_from, &result, sizeof(kdg_rez_test));

		
	  }
      break;

	  case START_TEST_DOZU_NAGR:
	  {
		Start_dozu_nagr = 1;
		cdg_error.ask = START_TEST_DOZU_NAGR;
        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
	  }
      break;

	  case RES_TEST_DOZU_NAGR:
	  {
		cdg_error.ask = RES_TEST_DOZU_NAGR;
        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));

		kdg_rez_test result;
		memset(&result, 0, sizeof(kdg_rez_test));

		result.cmd = RES_TEST_DOZU_NAGR;

		result.rez = gl_result.rez; 
		result.data = gl_result.data; 

 		if(gl_result.err != TPO_OK)
		{
		result.err = gl_result.err;
		gl_result.err = 0;
		}
				
        msg_send(msg_from, &result, sizeof(kdg_rez_test));

 	  }
      break;

	  case STOP_TEST_DOZU_NAGR:
	  {
		Start_dozu_nagr = 0;
		cdg_error.ask = STOP_TEST_DOZU_NAGR;
        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
	  }
      break;

	  case START_TEST_ROM:
	  {
		Start_tst_rom = 1;
		cdg_error.ask = START_TEST_ROM;
        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
	  }
      break;

	  case STOP_TEST_ROM:
	  {
		Start_tst_rom = 0;
		cdg_error.ask = STOP_TEST_ROM;
        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
	  }
      break;

	  case START_TEST_CR_CH:
	  {
		cdg_error.ask = START_TEST_CR_CH;
        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));

		memset(&gl_result, 0, sizeof(kdg_rez_test));        
		memset(&to_from, 0, sizeof(to_from));        
		error = msg_recv(&msg_desc, MSG_WAIT_1);
	    if(msg_desc == NULL) continue;


		memcpy(&to_from, msg_desc->data, sizeof(to_from));
	    msg_free(msg_desc);      
/*
#ifdef TPO6
		CrypterInit(); //init crypt!!!!!!!!!!1
#endif
*/
		Start_tst_cr_ch = 1;

	  }
      break;

	  case STOP_TEST_CR_CH:
	  {
		Start_tst_cr_ch = 0;
		cdg_error.ask = STOP_TEST_CR_CH;
        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
	  }
      break;


      case TEST_SDRAM_FULL:
	  {
		cdg_error.ask = TEST_SDRAM_FULL;
        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));

		kdg_rez_test result;
		memset(&result, 0, sizeof(kdg_rez_test));
        
		uint64 ErrorsPositions;
		uint32 ErrorAddress;

		result.rez = uniTestSDRAM_CP( &ErrorsPositions, &ErrorAddress);
		result.data = (uint32)(ErrorsPositions & 0xFFFFFFFF);
		result.data1 = (uint32)(ErrorsPositions >> 32);
		result.adrr = ErrorAddress;

		result.cmd = TEST_SDRAM_FULL;

		WriteDARAM(MIN_NUMBER_COMM,0,&result,sizeof(kdg_rez_test));

		memset(&result, 0, sizeof(kdg_rez_test));	//отсылаем пустой результат - как поттвержд о конце теста
		result.cmd = TEST_SDRAM_FULL;

 		if(gl_result.err != TPO_OK)
		{
		result.err = gl_result.err;
		gl_result.err = 0;
		}

        msg_send(msg_from, &result, sizeof(kdg_rez_test));

	  }
      break;


      case TEST_NVRAM_FULL:
	  {
		cdg_error.ask = TEST_NVRAM_FULL;
        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));

		kdg_rez_test result;
		memset(&result, 0, sizeof(kdg_rez_test));
		uint64 ErrorsPositions;
		uint32 ErrorAddress;

		result.rez = uniTestNVRAM( &ErrorsPositions, &ErrorAddress);
		result.data = (uint32)(ErrorsPositions & 0xFFFFFFFF);
		result.data1 = (uint32)(ErrorsPositions >> 32);
//		result.data = ErrorsPositions;
		result.adrr = ErrorAddress;

		int32 rrr = tst_nvram_addr();// для теста сохранности

		result.cmd = TEST_NVRAM_FULL;

		WriteDARAM(MIN_NUMBER_COMM,0,&result,sizeof(kdg_rez_test));

		memset(&result, 0, sizeof(kdg_rez_test));	//отсылаем пустой результат - как поттвержд о конце теста
		result.cmd = TEST_NVRAM_FULL;

 		if(gl_result.err != TPO_OK)
		{
		result.err = gl_result.err;
		gl_result.err = 0;
		}

        msg_send(msg_from, &result, sizeof(kdg_rez_test));

	  }
      break;


	  case INF_ABOUT_USB:
	  {
		cdg_error.ask = INF_ABOUT_USB;

		About_usb();

        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
	  }
      break;

//#ifndef TPO7
      case TEST_CR_SERVISE:
	  {
		cdg_error.ask = TEST_CR_SERVISE;
        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));

		kdg_rez_test result;
		memset(&result, 0, sizeof(kdg_rez_test));
		result.cmd = TEST_CR_SERVISE;
        
#ifndef TPO7        
		result.rez = TestGostAB(1);
#else
		result.rez = 0;
//		result.rez = TestAlfaAB(1);
#endif

 		if(gl_result.err != TPO_OK)
		{
		result.err = gl_result.err;
		gl_result.err = 0;
		}

        msg_send(msg_from, &result, sizeof(kdg_rez_test));

	  }
      break;

#ifndef TPO7

	  case START_TEST_MOVE:
	  {
		Start_move = 1;
		cdg_error.ask = START_TEST_MOVE;
        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
	  }
      break;

	  case STOP_TEST_MOVE:
	  {
		Start_move = 0;
		cdg_error.ask = START_TEST_MOVE;
        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
	  }
      break;

	  case TEST_IPMP:
	  {
		uint16 buf_wr[0x201];
		uint16 buf_rd[0x201];
		
		memset(buf_rd, 0, sizeof(buf_rd));        

		for(uint16 i = 1; i < 0x201; i++)
		buf_wr[i] = i;

		cdg_error.ask = TEST_IPMP;
        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));

		error = msg_recv(&msg_desc, MSG_WAIT_5);
	    if(msg_desc == NULL) continue;

		memcpy(buf_rd, msg_desc->data, sizeof(buf_rd));
	    msg_free(msg_desc);      

		if(memcmp(&buf_rd[1], &buf_wr[1], sizeof(buf_wr)-2))
			buf_wr[0]=TPO_ERR;
		else
			buf_wr[0]=TPO_OK;

        msg_send(msg_from, buf_wr, sizeof(buf_wr));

	  }
      break;


#endif


	  case START_LOAD_PO:
	  {
		flash_chip_clear();
//		flesh_offset = 0;
		cdg_error.ask = START_LOAD_PO;
        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
		Load_po_flash();
	  }
      break;

	  case WRITE_PO_TO_FLASH:
	  {

		cdg_error.ask = WRITE_PO_TO_FLASH;
        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
		Load_po_plis_si();
	  }
      break;

	/*
		  case LOAD_LIF:
		  {
			sv_msg_open = 0;
			cdg_error.ask = LOAD_LIF;
	        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));

			load_lif(NULL);
			sleep_m(500);
			msg_close();
			prc_exit();
			while(1);
		  }
	*/
	  case EXIT_TPO:
	  {
		sv_msg_open = 0;
		cdg_error.ask = EXIT_TPO;
        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));

		sleep_m(1000);
		load_lif(NULL);
		sleep_m(7000);
		msg_close();
//		prc_exit();
		return 0;
		while(1);
	  }


	  case LOAD_LIF:
	  {
		sv_msg_open = 0;
		cdg_error.ask = LOAD_LIF;
        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));

		Load_lif_from_usb();
		sleep_m(1000);
		load_lif(NULL);
		sleep_m(7000);
		msg_close();
		prc_exit();
		while(1);
	  }


//      break;
      default:
      {
       cdg_error.cmd = ERROR_CMD;
       cdg_error.ask = TPO_ERR;
       msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));  
      }
    }//switch
  }//while
}//tpo_main

