#ifndef _SIALP_H
#define _SIALP_H
/**********************************************************************************************************************
*                                        (c) COPYRIGHT by ZAO RCZI FORT.                                             *
*        ..                                       All rights reserved.                                               *
***********************************************************************************************************************
* Module      : sialp.h
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

#ifdef	IFACE
	#include    "menu.h"
#endif//	IFACE


#define	TIP_SI		0
#define	TIP_ALP		1
#define	qqq	   	    1



enum
{
	RIK = 1,
	PP_PLIS,
	MCBSP,//3
	CP_EXT_RAM,
	CP_INT_RAM1,
	CP_INT_RAM2,
	CP_INT_RAM3,
	CP_PLIS,
	CRYPTO,
	ETHERNET,//10
	DISPLEY,
	RESET_PLIS,
	SP_PLIS,
	PLIS_SI,//14
	SATA_SI,//15
	USB3_SI //16
};


struct kdg_sialp
{
    uint8	tiptest;	//si или alp    
    uint8	kodtest;	//номер теста   
    uint16	time_ms;	//время задержки в мс
    uint8	val_1;		//число 1       
    uint8	val_2;		//число 2       
    uint16	channel;	//канал (если понадобится)
};

#ifdef	IFACE  //Определена Интерфейсная Плата (ПВ-040,ПВ-044)

	struct TEST_SIALP
	{
		uint32	N_test;
	    void	(*funct)(cs_menu*,void*); 
		const	char *title;
	}; 

	//void Vvod(kdg_sialp* arg);
	void SI_RIK(cs_menu* m, void* arg);
	void SI_MCBSP(cs_menu* m, void* arg);
	void SI_CP_PLIS(cs_menu* m, void* arg);
	void SI_CRYPTO(cs_menu* m, void* arg);
	void SI_EXT_RAM(cs_menu* m, void* arg);
	void SI_INT_RAM(cs_menu* m, void* arg);
	void SI_ETH(cs_menu* m, void* arg);
	void SI_DISPL(cs_menu* m, void* arg);
	void SI_PLIS(cs_menu* m, void* arg);
	void SI_SATA(cs_menu* m, void* arg);
	void SI_USB3(cs_menu* m, void* arg);

	void ALP_RIK(cs_menu* m, void* arg);
	void ALP_PP_PLIS(cs_menu* m, void* arg);
	void ALP_MCBSP(cs_menu* m, void* arg);
	void ALP_CP_PLIS(cs_menu* m, void* arg);
	void ALP_CRYPT(cs_menu* m, void* arg);
	void ALP_EXT_RAM(cs_menu* m, void* arg);
	void ALP_INT_RAM(cs_menu* m, void* arg);
	void ALP_ETHERNET(cs_menu* m, void* arg);
	void ALP_SP_PLIS(cs_menu* m, void* arg);
	void ALP_DISPL(cs_menu* m, void* arg);
	void ALP_PLIS(cs_menu* m, void* arg);


	void si_mcbsp(int reader, uint8 num0, uint8 num1, int delay);
	void si_rik_read(int reader, uint8 num0, uint8 num1, int delay);
	void alp_pp_plis(int reader, uint8 num0, uint8 num1, int delay);
	void alp_mcbsp(int reader, uint8 num0, uint8 num1, int delay);
#endif//	IFACE



//----------main-------------
#ifdef	MAIN

	void Test_sialp();
	void si_ext_ram(int RW, uint16 num0, uint16 num1, int delay);
	void si_int_ram(int RW, uint16 num0, uint16 num1, int delay);
	void si_load_key(uint32 num0, uint32 num1, int delay);
#endif	//MAIN



//----------comm-------------
#ifdef	COMM
	void Test_sialp();
	void si_eth(int delay, uint8 num0);	//start stop trancemiter
	void alp_eth_6457(int delay, uint8 num0);	//start stop trancemiter
	void alp_eth_6412(int delay, uint8 num0);
	void si_stop_tx(int delay);	//start stop trancemiter
	void alp_to_plis_6457(uint8 num0);
	void alp_to_plis_6412(uint8 num0);
#endif	//COMM





#endif //_SIALP_H

