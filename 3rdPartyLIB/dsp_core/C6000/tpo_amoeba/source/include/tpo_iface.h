#ifndef IFACE_TPO_H
#define IFACE_TPO_H
/**********************************************************************************************************************
*                                        (c) COPYRIGHT by ZAO RCZI FORT.                                             *
*        ..                                       All rights reserved.                                               *
***********************************************************************************************************************
* Module      : tpo_iface.h
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

#include "tests.h"
#include "console.h"
#include "tpo.h"
//#include "err.h"


	#define resNO_INT 0xFF
	#define MaxCicle 1000000
	#define MaxTable 8
	#define MaxStr 10
	#define MaxLen 30
	#define StartStr 4

	#define MaxCicleNastr 4000000000

	#define maxN_Tests_PP	15 //тк № первого теста на 00, а 01!!!!!
	#define minN_Tests_CP	20 //тк № первого теста на 00, а 01!!!!!
	#define maxN_AllTest 	64

//оформление запуска тестов
#define start(stroka)   clrscr();\
            	gotoxy(3,2);\
            	cprintf("%s",stroka)
//			gotoxy(0,13);\
//            cprintf("%-22.22s\nENTER - ОК\nESC   - Выход\n",stroka);\
//            if(getch()==KEY_ENTER)\
//            {\
//				clrscr();\



#define T_clrbar(Y)		clrbar(Y,30)

#define T_clrbar_D(Y, dY)	for(int o = 0; o < dY; o++)\
							clrbar(Y + o, 30)\
//                con_clrbar(USER_CON,Y,DY)

//-------------------------------------------------------------------------------------------------
	extern uint32 Reg_N;
	extern char MemTablo[MaxTable][MaxStr][MaxLen+1];

	//Основная Структура _от_которой Потом мы заполняемся
	typedef struct _TEST_IFACE
	{
		uint16 N_test;
		uint16 (*f_test)();
		const char *title;
		int startup;		//будет указывать наличие этого теста к прибору.
		int repeat;
	}TEST_IFACE; 

	void F_BeginTest(uint32);
	void F_StartTest(uint32 count, uint32* result);
	//void F_StartTest(uint32 count);
	int PrintfResCiklTest(uint32 count, uint32 end,	uint32 ResAllTest_P, uint32 ResAllTest6416);
	//int PrintfResCiklTest(uint32 count, uint32 end);
	void F_PrintMemTablo(uint16);
	void F_GetPageTablo(uint16 key);
	void F_TestProgress(int weight);

#endif //IFACE_TPO_H

