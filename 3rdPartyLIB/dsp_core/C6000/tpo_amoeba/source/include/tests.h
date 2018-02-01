#ifndef _TEST_H
#define _TEST_H
/**********************************************************************************************************************
*                                        (c) COPYRIGHT by ZAO RCZI FORT.                                             *
*        ..                                       All rights reserved.                                               *
***********************************************************************************************************************
* Module      : tests.h
* Description : 
* Author      : 
******************************************************************************
******************************************************************************
* Module's Description Record:
* ============================
* Module's revision history:
* ==========================
* --------- $Log:  $
* --------- Initial revision
******************************************************************************/

#include "tpo.h"

#ifdef IFACE /////////////////////////

	#define		SDRAM_START_ADDR	0x90000000
	#define		SDRAM_LEN			0x800000
	#define		SDRAM_BLOK_LEN		0x400
	#define		SDRAM_WIDTH			4


	//uint16 resStart_N_Test(uint16 N);


	uint16 F_TEST_CMP_PP();

	uint16 F_test_PU();
	uint16 F_test_ram();
	uint16 F_test_rtc();
	uint16 F_hash_comp();
	uint16 F_test_power_sensor();
	uint16 F_test_access_sensor_verh();
	uint16 F_test_access_sensor_niz();
	uint16 F_test_access_sensor_rik();

	uint16 F_test_usbc();
	uint16 F_test_usb_flash1();
	uint16 F_test_usb_flash2 ();

	//uint16 F_test_rikc();
	uint16 F_test_rik1();
	uint16 F_test_rik2();

	uint16 F_test_random1();
	uint16 F_test_random2();

	uint16 F_hash_comp_pp056();
	uint16 F_test_usb_flash3();
	uint16 F_test_cdrom();
	uint16 F_test_raid();

	uint16 F_hash_comp_main();
	uint16 F_hash_comp_comm0();
	uint16 F_hash_comp_comm1();
	uint16 F_hash_comp_comm2();
	uint16 F_hash_comp_comm3();
	uint16 F_test_sdram_main();
	uint16 F_test_nvram_main();
	uint16 F_test_usbc_main();
	uint16 F_test_usb_main();
	uint16 F_test_dozu0();
	uint16 F_test_dozu1();
	uint16 F_test_dozu2();
	uint16 F_test_dozu3();
	uint16 F_test_move0();
	uint16 F_test_move1();
	uint16 F_test_move2();
	uint16 F_test_move3();
	uint16 F_test_sk0();
	uint16 F_test_sk1();
	uint16 F_test_sk2();
	uint16 F_test_sk3();
	uint16 F_reserved();

	uint32 Load_po_pp();
	uint32 Load_po_main();
	uint32 Load_po_comm();
	uint32 Load_plis_sialp();


	#ifdef MCBSP_TEST
		uint16 F_test_mcbsp();
	#endif


	int test_pu(void);
	int flash_test_base(void);
	int sdram_test_base(void);
	int ram_test_base(void);
	int rtc_test_base(void);
	int display_test_base(void);
	int keyboard_test_base(void);
	int power_test_base(void);
	int access_test_base(uint16 datchik);
	int access_test_rik_door(void);
	int mcbsp_test_rw(void);

	int usb_test_base(void);
	int usb_test_rw(uint32 dev, uint32 n, uint32 Otsvetka);
	int rik_test_card(int card);
	int random_test_base(int channel);
	int software_get_start(uint32 *start_vector);
	
	int software_check(
		uint32 *start_vector,
		uint32 offset, uint32 length, 
		uint32 *hash_value,
		int use_vector);

	//void F_TestProgress(void);
	int keyboard_test_all_keys(void);

#endif//IFACE

/////////////////////////////////////////////////////////////////////////////
#ifdef MAIN

	#ifdef TPO5
		#define		SDRAM_START_ADDR	0x80000000
		#define		SDRAM_LEN			0x800000
		#define		SDRAM_BLOK_LEN		0x400
		#define		SDRAM_WIDTH			4
    #else
		#define		SDRAM_START_ADDR	0x80000000
		#define		SDRAM_LEN			0x1000000
		#define		SDRAM_BLOK_LEN		0x400
		#define		SDRAM_WIDTH			8
 	#endif

	int usb_test_base(void);
	int usb_test_rw(uint32 dev);
	int sdram_test_base(void);

	uint32 TestObmenDOZU_N_SP(uint32 n_comm, kdg_rez_test* result);
	uint32 TestMoveDOZU_N_SP(uint32 n_comm, kdg_rez_test* result);
	void TestDOZU_Nagr();
	void Test_ROM();
	void Test_MOVE();
	void About_usb();

#endif/////////////////////////////////////MAIN

/////////////////////////////////////COMM
#ifdef COMM
	uint32 Test_SK();
#endif//COMM

#endif//_TEST_H

