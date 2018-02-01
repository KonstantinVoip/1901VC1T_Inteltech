#include <os_syscall.h>
//#include <drv_dbgout.h>
#include <rts.h>
#include <drv_fwmem.h>

#include "tpo.h"
#include "tpo_hash.h"
#include "tests.h"
#include "sialp.h"

#include <net_struct.h>
#include <drv_eth6412_emachal.h>



#ifdef TPO7
	#include "fifo.h"
	#include <drv_eth6457.h>
#endif


#ifdef CHIP_6457
	#include "qdma_rwrd.h"
#endif

//#include "drv_dp83820.h"
//#include "os_csl_mcbsp.h"
//#include "drv_mcbsp.h"

hash_window hwindow[] =
{
  { 0x00000000, 0x0036FFFF },
  { 0x003F0000, 0x003FFFBF },
  { 0x00000000, 0x00000000 }
};

uint32 sv_msg_open = 0;
uint32 read_res_fifo = 0;

#ifdef TPO5
	void* sh_mem_write=(void*)0x80000000;    

	void* sh_mem_read_proc=(void*)0xA0000000;               //начло общей памяти на чтение из процессора 1
	void* sh_mem_read_crypt=(void*)0xA0001000;      		//начло общей памяти на чтение из шифратора

	void* sh_mem_read_proc2=(void*)0xB0000000;               //начло общей памяти на чтение из процессора 2
	void* sh_mem_read_crypt2=(void*)0xB0001000;     		 //начло общей памяти на чтение из шифратора 2
#else
	void* sh_mem_write=(void*)0xA0000000;    

	void* sh_mem_read_proc=(void*)0xC0000000;                //начло общей памяти на чтение из процессора 1
	void* sh_mem_read_crypt=(void*)0xC0002000;      		 //начло общей памяти на чтение из шифратора

	void* sh_mem_read_proc2=(void*)0xD0000000;               //начло общей памяти на чтение из процессора 2
	void* sh_mem_read_crypt2=(void*)0xD0002000;      		//начло общей памяти на чтение из шифратора 2
#endif

	uint16 Start_dozu_nagr = 0;
	kdg_rez_test gl_result;


	//----------------------------------------------------------------------------
	extern int ReadDARAM0(uint16 addr,void* buf,uint16 len);
	extern int ReadDARAM1(uint16 addr,void* buf,uint16 len);
	extern int ReadDARAM_CRYPT0(uint16 addr,void* buf,uint16 len);
	extern int ReadDARAM_CRYPT1(uint16 addr,void* buf,uint16 len);
	extern void WriteDARAM(uint16 addr,void* buf,uint16 len);
	extern void load_lif(void* mem_lif);
	extern void Load_lif_from_usb();
	extern void QDMA_Read(void* dst,void* src,uint16 len);


	/*
	int SK_TsT(void* arg)
	{

	uint32 tsk = 0;
	while(1)
	{
	tsk = Test_SK();
	}

	}
	*/

#ifdef CHIP_6457
	//--------------------------------------------------------------------------------------------------
	//CSL_Edma3ParamSetup param_rd;
	//--------------------------------------------------------------------------------------------------
	uint8 check_buf[2048/sizeof(uint8)];
	extern int32   drv_eth6457_plug( const char* path, net_config& cfg, uint32 rxd_count, uint32 txd_count );
	extern int32   drv_eth6457_unplug( const char* name );
#endif


extern void alp_eth_6412(int delay, uint8 num0);
#define EMAC_PKT_FLAGS_SOP              0x80000000u     //< Start of packet
#define EMAC_PKT_FLAGS_EOP              0x40000000u     //< End of packet



/**************************************************************************************************
Syntax:    int32 flash_chip_clear()  	  		
Return Value:	
***************************************************************************************************/
int32 flash_chip_clear()
{
  volatile uint8& REG_555 = (*(uint8*)(0x90000000 + 0x00000555 ));
  volatile uint8& REG_AAA = (*(uint8*)(0x90000000 + 0x00000aaa ));
  uint32 offset;
  volatile uint8 tgl0, tgl1;

  REG_AAA = 0xaa;
  REG_555 = 0x55;
  REG_AAA = 0x80;
  REG_AAA = 0xaa;
  REG_555 = 0x55;
  REG_AAA = 0x10;
  
  volatile uint8& REG_DATA = (*(uint8*)0x90000000);

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

/**************************************************************************************************
Syntax:    void Load_po_flash()	  		
Return Value:	
***************************************************************************************************/
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
	if(msg_recv( &msg_desc, MSG_WAIT_10) != OSE_OK)

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


/**************************************************************************************************
Syntax:    int tpo_comm(void* arg, char* sys_name)  		
Return Value:	
***************************************************************************************************/
int tpo_comm(void* arg, char* sys_name)
{

    int32	error;
	uint32		msg_from;
	kdg_cmd		to_iface;
	kdg_cmd_ask	cdg_error;
	s_message*  msg_desc;


	#ifdef CHIP_6457
	QDMA_init();
	#endif



	//Load_lif_from_usb();
	/*
	while(1)
	Test_SK();
	si_eth(0,0);	
	*/
	//alp_to_plis_6457(0);



	//#ifdef TPO7
	 uint32 FileNet = drv_mkd("/dev/net/eth0");
	//if(FileNet == RES_VOID)
	//while(1);

	 net_config netcfg;
	 error = drv_ioctl(FileNet, NET_GET_CONFIG, &netcfg ); //нужно для теста
	 netcfg.flags |= NETCFG_PROMISCUOUSE;
	 error = drv_ioctl(FileNet, NET_SET_CONFIG, &netcfg );
	 drv_rmd(FileNet);
	//#endif


	  error = msg_open("tpo");
	  if(error != OSE_OK)
		return -1;

		sv_msg_open = 1;
		s_prc_attr atr;
		memset( &atr, 0, sizeof(atr) );
		atr.stack = 4096*3;   
		prc_create( &Sv_Msg, NULL, 0, &atr );

		#ifdef TPO7
		#ifdef CHIP_6457

		s_prc_attr atr1;
		memset( &atr1, 0, sizeof(atr1) );
		atr1.stack = 4048;   
		prc_create( &Read_Res_Fifo, NULL, 0, &atr1 );

		#endif
		#endif



  while(true)
  {
    error = msg_recv(&msg_desc, MSG_WAIT_5);
    if(msg_desc == NULL)
    {
	prc_yield();
    continue;
	}
    if(msg_desc->length != sizeof(kdg_cmd))
    {
      cdg_error.cmd = ERROR_CMD;
      cdg_error.ask = TPO_ERR;
      msg_send(msg_desc->from, &cdg_error, sizeof(kdg_cmd_ask));  
      msg_free(msg_desc);      
      continue;
    }
    msg_from = msg_desc->from;
    cdg_error.cmd = ((kdg_cmd*)msg_desc->data)->cmd;
    msg_free(msg_desc);      
    switch (cdg_error.cmd)
    {
	  //Тесты СИ АЛП:
      case START_SIALP:
	  {
	    //cdg_error.cmd = START_SIALP;
		cdg_error.ask = TPO_OK;
        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
     	//debug!!!!!!!!
        Test_sialp();
	  }
      break;
      // 
      case N_TEST:
	  {
		cdg_error.ask = TPO_OK;
        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));

		kdg_rez_test result;        

		error = msg_recv(&msg_desc, MSG_WAIT_10);
	    if(msg_desc == NULL) continue;
	    if(msg_desc->length != sizeof(kdg_rez_test))
	    {
	      cdg_error.cmd = ERROR_CMD;
		  cdg_error.ask = TPO_ERR;
	      msg_send(msg_desc->from, &cdg_error, sizeof(kdg_cmd_ask));  
	      msg_free(msg_desc);      
	      continue;
	    }
		memcpy(&result, msg_desc->data, sizeof(kdg_rez_test));
	    msg_free(msg_desc);      

        Start_Test_N(&result);
		result.cmd = RES_N_TEST;
        msg_send(msg_from, &result, sizeof(kdg_rez_test));	
	  }
      break;
     //
	  case START_TEST_DOZU_NAGR:
	  {
		Start_dozu_nagr = 1;
		cdg_error.ask = START_TEST_DOZU_NAGR;
        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));

		memset( &gl_result, 0, sizeof(gl_result) );

		memset( &atr, 0, sizeof(atr) );
		atr.stack = 4048*3;   
		prc_create( &TestDOZU_Nagr, NULL, 0, &atr );

	  }
      break;
      //
	  case RES_TEST_DOZU_NAGR:
	  {
		cdg_error.ask = RES_TEST_DOZU_NAGR;
        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));

		kdg_rez_test result;
		memcpy(&result, &gl_result, sizeof(kdg_rez_test));

		result.cmd = RES_TEST_DOZU_NAGR;

 		if(gl_result.err != TPO_OK)
		{
		result.err = gl_result.err;
		gl_result.err = 0;
		}
        msg_send(msg_from, &result, sizeof(kdg_rez_test));

 	  }
      break;
      //
	  case STOP_TEST_DOZU_NAGR:
	  {
		Start_dozu_nagr = 0;
		cdg_error.ask = STOP_TEST_DOZU_NAGR;
        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
	  }
      break;
      //
	  case RES_TEST_ROM_CP0:
	  {
		cdg_error.ask = RES_TEST_ROM_CP0;
        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));

		kdg_rez_test result;
		memset(&result, 0, sizeof(kdg_rez_test));

		result.cmd = RES_TEST_ROM_CP0;
		ReadDARAM0(0,&result.n_test,4);
		ReadDARAM0(4,&result.rez,4);
		ReadDARAM0(8,&result.adrr,4);
		ReadDARAM0(0xc,&result.data,4);

 		if(gl_result.err != TPO_OK)
		{
		result.err = gl_result.err;
		gl_result.err = 0;
		}
        msg_send(msg_from, &result, sizeof(kdg_rez_test));

 	  }
      break;
      //
	  case RES_TEST_ROM_CP1:
	  {
		cdg_error.ask = RES_TEST_ROM_CP1;
        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));

		kdg_rez_test result;
		memset(&result, 0, sizeof(kdg_rez_test));

		result.cmd = RES_TEST_ROM_CP1;
		ReadDARAM1(0,&result.n_test,4);
		ReadDARAM1(4,&result.rez,4);
		ReadDARAM1(8,&result.adrr,4);
		ReadDARAM1(0xc,&result.data,4);

 		if(gl_result.err != TPO_OK)
		{
		result.err = gl_result.err;
		gl_result.err = 0;
		}
        msg_send(msg_from, &result, sizeof(kdg_rez_test));

 	  }
      break;
      //
	  case RES_TEST_CR_CH:
	  {
		cdg_error.ask = RES_TEST_CR_CH;
        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));

		CryptErrors CrTestRes[2];
		memset(CrTestRes, 0, sizeof(CryptErrors)*2);

		ReadDARAM0(0,&CrTestRes[0],sizeof(CryptErrors));
		ReadDARAM1(0,&CrTestRes[1],sizeof(CryptErrors));

        msg_send(msg_from, CrTestRes, sizeof(CryptErrors)*2);

 	  }
      break;
      //
	  case GOTOV_PP:
	  {
		uint8 recb[400];
		memset(recb, 0, sizeof(recb));
		uint32 result[2][2];
		cdg_error.ask = GOTOV_PP;
		kdg_rez_test gotov;
		memset(&gotov, 0, sizeof(kdg_rez_test));
        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
		gotov.cmd = RES_N_TEST;

		#ifndef TPO7
		ReadDARAM0(0xF00,&result[0],8);
		ReadDARAM1(0xF00,&result[1],8);
		if((result[0][1] == 0x12345678) | (result[1][1] == 0x12345678))
		{
		#else
		uint16	res12 = FIFO_outIsReady();
		if(res12 != 0)
		{
		FIFO_StartReadPacket(&recb,0, 8 + 20); //20 ???? 8-0
		sleep_m(100);
		memcpy(&result[0],&recb[20],8);
		memcpy(&result[1],&check_buf[20],8);
		FIFO_EndReadPacket();
		#endif
		gotov.n_test = CIKL;
		gotov.data  = result[0][0];
		gotov.data1 = result[1][0];

		}
		
		//еще не закончен цикл 
		else
		{
		gotov.n_test = CIKL_NOT_READY;
		gotov.data  = 0;
		gotov.data1 = 0;
		}

		/* 		
		if(gl_result.err != TPO_OK)
		{
		gotov.err = gl_result.err;
		gl_result.err = 0;
		}
		*/				
        msg_send(msg_from, &gotov, sizeof(kdg_rez_test));

 	  }
      break;

	  case START_TEST_MOVE:
	  {
		cdg_error.ask = START_TEST_MOVE;
		uint32 buf[LEN_MOVE/4];
		memset(buf, 0x55, sizeof(buf));
		/*
		if( OSE_OK == sys_chkname("comm0") )
		{
			for(int ui=0; ui<(LEN_MOVE/4); ui++)
			{
			buf[ui] = ui;
			}
		}
		if( OSE_OK == sys_chkname("comm1") )
		{
			for(int ui=0; ui<(LEN_MOVE/4); ui++)
			{
			buf[ui] = 0xFFFFFFFF-ui;
			}
		}
		*/
		/*
			s_prc_attr atr_test;
			memset( &atr_test, 0, sizeof(atr_test) );
			atr_test.stack = 4048*4;   
			prc_create( &SK_TsT, NULL, 0, &atr_test );
		*/
		WriteDARAM(0, buf, sizeof(buf));
		WriteDARAM(sizeof(buf), buf, sizeof(buf));
		
		memset(&gl_result, 0, sizeof(gl_result));
        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));

	  }
      break;


	  case RES_TEST_MOVE:
	  {
		cdg_error.ask = RES_TEST_MOVE;
        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));

		rez_test result;        
		
		result.cmd = RES_TEST_MOVE;
		result.n_test = gl_result.n_test;
		result.rez0 = gl_result.data;
		result.rez1 = gl_result.data1;

        msg_send(msg_from, &result, sizeof(result));

	  }
      break;

	  case GET_RES_FROM_DOZU:
	  {
		

		cdg_error.ask = GET_RES_FROM_DOZU;
        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));

		kdg_rez_test result;
		memset(&result, 0, sizeof(kdg_rez_test));
		kdg_rez_test result1;
		memset(&result1, 0, sizeof(kdg_rez_test));
		uint16 res12=0;
		uint8 recb[400];
		memset(recb, 0, sizeof(recb));

		sleep_m(100);

#ifndef TPO7
		ReadDARAM0(0,&result, sizeof(kdg_rez_test));
        msg_send(msg_from, &result, sizeof(result));

		ReadDARAM1(0,&result1, sizeof(kdg_rez_test));
        msg_send(msg_from, &result, sizeof(result));
#else

		res12 = FIFO_outIsReady();

		FIFO_StartReadPacket(&recb,0, sizeof(kdg_rez_test)+20); //20 ???? 8-0
		sleep_m(100);
		memcpy(&result,&recb[20],sizeof(kdg_rez_test));
		memcpy(&result1,&check_buf[20],sizeof(kdg_rez_test));
		FIFO_EndReadPacket();

		msg_send(msg_from, &result, sizeof(result));
		msg_send(msg_from, &result1, sizeof(result));

#endif


	  }
      break;

	  case INF_ABOUT_USB:
	  {
				
				uint16 res12=0;
				cdg_error.ask = INF_ABOUT_USB;
		        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));

				about_usb usb_cp[2];
				memset(usb_cp, 0, sizeof(about_usb)*2);

				uint8 recb[400];
				memset(recb, 0, sizeof(recb));

				sleep_m(100);

				#ifndef TPO7
				ReadDARAM0(0,&usb_cp[0], sizeof(about_usb));
				ReadDARAM1(0,&usb_cp[1], sizeof(about_usb));
				#else
				res12 = FIFO_outIsReady();
				FIFO_StartReadPacket(&recb,0, sizeof(about_usb)+20); //20 ???? 8-0
				sleep_m(100);
				memcpy(&usb_cp[0],&recb[20],sizeof(about_usb));
				memcpy(&usb_cp[1],&check_buf[20],sizeof(about_usb));
				FIFO_EndReadPacket();
				#endif
		        msg_send(msg_from, usb_cp, sizeof(about_usb)*2);

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

		error = msg_recv(&msg_desc, MSG_WAIT_10);
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


	  case STOP_TX:
	  {
		cdg_error.ask = STOP_TX;
        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));

		#ifdef TPO5
				si_stop_tx(5);	//start stop trancemiter
		#else
		uint32* regtx = (uint32*)0x02C40030;
		uint32  regdat=0;
		regdat = *regtx;
		regdat = regdat & 0xFFFFFFFE;
		uint32 dg = 10000000;
		while(dg--);
		uint32 rui = prc_disable();
		#endif

	  }
      break;
      //
	  case START_LOAD_PO:
	  {
		flash_chip_clear();
		cdg_error.ask = START_LOAD_PO;
        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
		Load_po_flash();
	  }
      break;
	  //
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
		//		while(1);
		return 0;
	  }
      //
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
      //
      default:
      {
       cdg_error.cmd = ERROR_CMD;
       cdg_error.ask = TPO_ERR;
       msg_send(msg_desc->from, &cdg_error, sizeof(kdg_cmd_ask));  
      }
    }
  }
}

