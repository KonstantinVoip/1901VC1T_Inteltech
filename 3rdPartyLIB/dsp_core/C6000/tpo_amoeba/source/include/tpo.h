#ifndef _TPO_H
#define _TPO_H
/**********************************************************************************************************************
*                                        (c) COPYRIGHT by ZAO RCZI FORT.                                             *
*        ..                                       All rights reserved.                                               *
***********************************************************************************************************************
* Module      : tpo.h
* Description : 
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
#include    <os_types.h>

#define MIN_NUMBER_COMM		0



#ifdef IFACE
	#include    "menu.h"
	#include    "drv_usbms.h"
#endif


#ifdef TPO5
	#define NUMBER_COMM_DSP		2
#endif

#ifdef TPO6
	#define NUMBER_COMM_DSP		3
#endif

#ifdef TPO7
	#define NUMBER_COMM_DSP		3
#endif

	#define	TPO_OK		0
	#define	TPO_ERR		1

	#define FIRST_CH	1
	#define SECOND_CH	2	
	#define TWO_CH		FIRST_CH|SECOND_CH

	#define VERH_DATCHIK	0x0040
	#define NIJN_DATCHIK	0x0020

	#define	TPO_ERR_FWM		0x5502
	#define	TPO_ER_HASH		0x5503


	#define ERR_RW_DP		2// - ошибка общения с DP
	#define ERR_RW_LXT		4// - ошибка общения с модулем 
	#define ERR_LOOP_DP		8// - ошибка LOOPBACK в DP
	#define ERR_LOOP_LXT	16// - ошибка LOOPBACK в модуле
	#define ERR_LOOP_PHY	32// - ошибка LOOPBACK в физической среде

	#define ERR_DNSD_TIMEOUT		2// 
	#define ERR_DNSD_READ_C0		4//   
	#define ERR_DNSD_TRIGGER		8// 

	#define	MSG_ER_TIME_OUT		-1
	#define	MSG_ER_SYNC			-2


	#define	MSG_WAIT_DEBUG		60000
	#define	MSG_WAIT_10			10000
	#define	MSG_WAIT_5			5000
	#define	MSG_WAIT_3			3000
	#define	MSG_WAIT_1			1000
	#define	MSG_WAIT_05			500

#ifdef TPO5
	#define LEN_DUZU_FOR_TEST		0xE00	//байты
	#define SH_DOZU					32
	#define LEN_BUF_FOR_TEST_DOZU	LEN_DUZU_FOR_TEST/(SH_DOZU/8)// dword
	#define LEN_MOVE 				0x600
#endif

#ifdef TPO6						// !!!!!!!!!!!!
	#define LEN_DUZU_FOR_TEST		0x400//0x1000	//байты
	#define SH_DOZU					64
	#define LEN_BUF_FOR_TEST_DOZU	LEN_DUZU_FOR_TEST/(SH_DOZU/8)// dword
	#define LEN_MOVE 				0x600
#endif

#ifdef TPO7						// !!!!!!!!!!!!
	#define LEN_DUZU_FOR_TEST		0x400//0x1000	//байты
	#define SH_DOZU					64
	#define LEN_BUF_FOR_TEST_DOZU	LEN_DUZU_FOR_TEST/(SH_DOZU/8)// dword
	#define LEN_MOVE 				0x600
#endif

#define LEN_BUF1_FOR_TEST_SK		140
#define LEN_BUF2_FOR_TEST_SK		64

	#define TEST_RESULT_OK 0
	/* Ошибка тестирования шины данных памяти */
	#define TEST_DATA_BUS_ERROR 2
	/* Ошибка тестирования шины адреса памяти */
	#define TEST_ADDRESS_BUS_ERROR 3
	/* Ошибка тестирования памяти */
	#define TEST_MEMORY_ERROR 4
	#define ERR_DOZU_WRCP0_RDSP	5// ошибка записи ЦП0? чтения СП
	#define ERR_DOZU_WRCP1_RDSP	6// ошибка записи ЦП1? чтения СП
	#define ERR_DOZU_WRSP_RDCP	7// ошибка записи СП? чтения ЦП
	#define ERR_DOZUMOVE_WRSP_RDSH	8// ошибка записи СП чтения Ш

	#define ENABLE_FLASH	1// 
	#define DISABLE_FLASH	0// 


	//cmd tpo 
	enum
	{
		START = 0x000D0000,
		START_SIALP,

		START_CIKL,
		GOTOV_PP,
		STOP_CIKL,

		N_TEST,
		GOTOV_TEST,
		TEST_NOT_READY,
		RES_N_TEST,

		TEST_SDRAM_FULL,
		TEST_NVRAM_FULL,
		START_TEST_DOZU_NAGR,
		RES_TEST_DOZU_NAGR,
		STOP_TEST_DOZU_NAGR,
		TEST_CR_SERVISE,

		START_TEST_ROM,
		RES_TEST_ROM_CP0,
		RES_TEST_ROM_CP1,
		STOP_TEST_ROM,

		START_TEST_CR_CH,
		RES_TEST_CR_CH,
		STOP_TEST_CR_CH,

		CLEAR_TEST_PACKET,
		RECV_TEST_PACKET,
		SEND_TEST_PACKET,

		START_TEST_MOVE,
		GOTOV_TEST_MOVE_15,
		GOTOV_TEST_MOVE_1A,
		GOTOV_TEST_MOVE_25,
		GOTOV_TEST_MOVE_2A,
		RES_TEST_MOVE,
		STOP_TEST_MOVE,

		GET_RES_FROM_DOZU,

		INF_ABOUT_USB,
		TEST_IPMP,

		ASK_CMD,
		OPEN_SV_MSG,
		CLOSE_SV_MSG,
		ERROR_CMD,
		STOP_TX,
		EXIT_TPO,
		LOAD_LIF,
		START_LIF,

		START_LOAD_PO,
		WRITE_PO_TO_FLASH
	};

	//tests
	enum
	{
		CELOSTN = 21,

		TEST_SDRAM = 26,
		TEST_NVRAM,

		TEST_USB_CONTR = 29,
		TEST_USB_FLASH,

		TEST_DOZU = 32,		//не разделять
		TEST_DOZU_ST1,		//
		TEST_DOZU_ST2,		//
		TEST_DOZU_ST3,		//

		TEST_MOVE,			//не разделять
		TEST_MOVE_ST1,		//
		TEST_MOVE_ST2,		//
		TEST_MOVE_ST3,		//

		TEST_SK,			//не разделять
		TEST_SK1,			//
		TEST_SK2,			//
		TEST_SK3,			//

		TEST_DNSD_CRC,
		TEST_DNSD_VD10,
		TEST_DNSD_VD11,
		ZAVESTI_DNSD,
		PROCHITAT,
		VKL_VD10,
		VKL_VD11,
		VIKL_VD11,
		TEST_DNSD_OSVESCH,
		MAGIC_NUMBER,

		CELOSTN_PP056,
		TEST_CDROM,
		TEST_RAID,
		TEST_USB3,

		CIKL = 100,
		CIKL_NOT_READY 
	};

	//ошибки ТПО
	enum
	{
		MAIN_TIME_OUT = 0,
		COMM_TIME_OUT,
		COMM1_TIME_OUT,
		COMM2_TIME_OUT,
		COMM3_TIME_OUT,

		MAIN_ERR_MSG,
		MAIN_ERR_MSG_CICL_RES,

		COMM_ERR_MSG,
		COMM1_ERR_MSG,
		COMM2_ERR_MSG,
		COMM3_ERR_MSG,

		DRV_ERR,
		ERR_MSG_OPEN,

		NO_MEM_COMM,
		NO_MEM_COMM1,
		NO_MEM_MAIN,
		NO_MEM_IFACE

	//END_ERR
	};


	struct kdg_cmd
	{
	    uint32	cmd;	//    
	};

	struct kdg_cmd_ask
	{
	    uint32	cmd;	//    
	    uint32	ask;	//    
	};


	struct kdg_rez_test
	{
	    uint32	cmd;	//    
	    uint32	n_test;	//номер теста    
	    uint32	rez;	//результат теста(0- ok)    
	    uint32	adrr;	//адрес по которому произошла ошибка(если нужно)    
	    uint32	data;	//данные    
	    uint32	data1;	//данные    
	    uint32  err;
	    uint8  buf[32];
	};

	struct rez_test
	{
	    uint32	cmd;	//
	    uint32	n_test;	//
	    uint32	rez0;	//
	    uint32	rez1;	//
	};

	struct about_usb
	{
		uint32		enable;
	    uint32      block_length;
	    uint64      flash_capacity;              
	    char        vendor_identification[10];
	    char        product_identification[17];
	    char        product_revision_level[5];
		char 		fstr[8];
	};

	struct comm_status
	{
	    uint32	N;	//    
	    uint32	pid;	//    
		//    uint32	ask;	//    
		//    uint32	rez;	//    
		//    uint32	adrr;	//    
	};


	typedef struct _SkEthTestRes
	{
		uint32 errRegDP;//Ошибок чтения регистров DP83820
		uint32 errRegLX;//Ошибок чтение регистров LXT971AL
		uint32 errSP_DP;//Ошибок при передачи по петле от СП до DP83820
		uint32 errSP_LX;//Ошибок при передачи по петле от СП до Intel LXT971AL
		uint32 errSP_TR;//Ошибок прием\передачи через кабель
	}SkEthTestRes;  


	typedef struct _TestDnsdRes
	{
		uint32 errTimeout;//Ошибок timeout
		uint32 errReadC0;//Ошибок чтения C0
		uint32 errTrigger;//Ошибок срабатывания
	}TestDnsdRes;  


	typedef struct _EthCFG
	{
		uint16 eth_send;
		uint16 eth_recv;
	}EthCFG;

	typedef struct _CryptErrors
	{
		uint32 NumPack;	//Количество пакетов
		uint32 BodyErr;	//Ошибок в теле текста
	//	uint32 SlbErr;  //Ошибок в служебных данных
		uint32 ImvErr;  //Ошибок имитовставки
		uint32 CtrBErr; //Ошибок контрольного байта
		uint32 LostPack; //Потерено пакетов
		uint32 CMPerr;  //Ошибок сравнивания пакетов от ЦП0 и ЦП1
	}CryptErrors;



#ifdef IFACE
	struct arg_exit_tpo
	{
	    uint32*					exit;	//    
		s_usb_attach_func*		ubs_event;
		uint32                  file_usb;
		uint32                  sem;
		uint32                  pid;
		cs_menu*                menu;
	};

	struct File_lif
	{
	    uint32	file;	   
	    uint32	len;	   
	};



	int32 receive_msg(void* recev, int32 length, uint32 ms);
	uint32 Chek_usb_dev(uint32 dev);

	void Nastrojka(cs_menu* m, void* arg);
	void Cikl_tests(cs_menu* m, void* arg);
	void Kb_and_Displ(cs_menu* m, void* arg);
	void Tst_led(cs_menu* m, void* arg);
	void Test_Crypto(cs_menu* m, void* arg);
	void Tst_SDRAM_full(cs_menu* m, void* arg);
	void Tst_USB_file(cs_menu* m, void* arg);
	void GSCh_USB_file(cs_menu* m, void* arg);
	void F_AboutUSB(cs_menu* m, void* arg);
	void Tst_SDRAM_full_SV(cs_menu* m, void* arg);
	void Tst_NVRAM_full_SV(cs_menu* m, void* arg);
	void TestDARAM_PrintRes(cs_menu* m, void* arg);
	void TestDARAM_MOVE_PrintRes(cs_menu* m, void* arg);
	void TestDARAM_MOVE_CiklPrintRes(cs_menu* m, void* arg);
	void TestDARAM_Nagruz(cs_menu* m, void* arg);
	void Tst_ROM_SV(cs_menu* m, void* arg);
	void F_TestSkEth(cs_menu* m, void* arg);
	void F_CrServiceTest(cs_menu* m, void* arg);
	void F_CrChannelCfgEth0_1(cs_menu* m, void* arg);
	void F_CrChannelCfgEth0_2(cs_menu* m, void* arg);
	void F_CrChannelCfgEth1_0(cs_menu* m, void* arg);
	void Tst_MOVE(cs_menu* m, void* arg);
	void F_AboutUSB_CP(cs_menu* m, void* arg);
	void Tst_ipmp_comm(cs_menu* m, void* arg);
	void Tst_ipmp_main(cs_menu* m, void* arg);
	void Dnsd_crc_po(cs_menu* m, void* arg);
	void Dnsd_rasshiren_test(cs_menu* m, void* arg);
	void ZavestiDNSD(cs_menu* m, void* arg);
	void Prochitat(cs_menu* m, void* arg);
	void Vkluchit_VD(cs_menu* m, void* arg);
	void Vikluchit_VD(cs_menu* m, void* arg);
	void Magic_Number(cs_menu* m, void* arg);
	void Osveschennost(cs_menu* m, void* arg);

#endif//IFACE


#ifdef MAIN
	void BeginTest(uint32 Dnsd, uint32 Count);
	//void BeginTest(uint32 Dnsd);
	void Start_Test_N(kdg_rez_test* result);
	uint32 TestCelostnost();
#endif//MAIN


#ifdef COMM
int Read_Res_Fifo(void* arg);
int Sv_Msg(void* arg);
int TestDOZU_Nagr(void* arg);
void Start_Test_N(kdg_rez_test* result);
#endif//COMM


#endif //_TPO_H

