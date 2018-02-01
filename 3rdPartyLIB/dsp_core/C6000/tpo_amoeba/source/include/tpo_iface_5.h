#ifndef IFACE_TPO_H
#define IFACE_TPO_H


#include "tests.h"
#include "console.h"




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
			gotoxy(0,13);\
            cprintf("%-22.22s\nENTER - ОК\nESC   - Выход\n",stroka);\
            if(getch()==KEY_ENTER)\
            {\
				clrscr();\
            	gotoxy(4,2);\
            	cprintf("%s\n",stroka)



#define T_clrbar(Y)		clrbar(Y,30)

#define T_clrbar_D(Y, dY)	for(int o = 0; o < dY; o++)\
							clrbar(Y + o, 30)\
//                con_clrbar(USER_CON,Y,DY)




extern uint32 Reg_N;

extern char MemTablo[MaxTable][MaxStr][MaxLen+1];


typedef struct _TEST_IFACE
{
	uint16 N_test;
	uint16 (*f_test)();
	const char *title;
	int startup;		//будет указывать наличие этого теста к прибору.
	int repeat;
}TEST_IFACE; 



char* NameTests[]=
{
"01.Тест ОЗУ(SDRAM) ПП",	//+	обьеденить в один универсальный файл с тестами на СВ
"02.Тест ГСЧ 1", 			//+
"03.Тест ГСЧ 2",			//+
"04.Тест датч. вскр. РИК", 	//+	только проверка: открыт или закрыт
"05.Тест датч. вскр.", 		//+	только проверка: открыт или закрыт
"06.Тест датч. панели", 	//+	только проверка: открыт или закрыт
"07.Тест часов р. вр.",		//+
"08.Тест контр. USB ПП",	//+
"09.Тест з/чт USB флэш1",	//+ 
"10.Тест з/чт USB флэш2",	//+
"11.Тест РИК 1",			//+
"12.Тест РИК 2",			//+
"13.Тест ПУ(ПЛИС)",			//+
"14.Целостность ПО ПП",		//+
"15.Ф-ия сравнения в ПП",	//---
"16.Ответ ЦП периф-ому",	//--- нет и, наверное, не будет

//-----------------------------------
"17.резерв для ПП",
"18.резерв для ПП",
"19.резерв для ПП",
"20.резерв для ПП",
//-----------------------------------

// Для СВ
//номер первого теста для СВ - НЕЛЬЗЯ изменять без изменения
//#define minN_Test6416  и maxN_AllTest  tpo_iface.h   

"21.Целостность ПО ЦП",		//+

"22.Целостность ПО СП 0",	//+
"23.Целостность ПО СП 1",	//+
"24.Целостность ПО СП 2",
"25.Целостность ПО СП 3",

"26.Тест ОЗУ(SDRAM) ЦП",	//+
"27.Тест ЭОЗУ(NVRAM) ЦП",	//+ без сохранности
"28.Сохранность ЭОЗУ ЦП",	//сиос проводит свой тест, добавить запись теста как в сиос, шоба не выдавал ошибку

"29.Тест контр. USB ЦП",	//+ предполагается тест шины
"30.З/чт внутр. USB флэш",	//+

"31.Тест ДОЗУ(ЦП0 - ЦП1)",	//---

"32.Тест ДОЗУ(ЦП - СП0)",	//+
"33.Тест ДОЗУ(ЦП - СП1)",	//+
"34.Тест ДОЗУ(ЦП - СП2)",
"35.Тест ДОЗУ(ЦП - СП3)",

"36.Тест ДОЗУ(СП0 - Ш)",	//+
"37.Тест ДОЗУ(СП1 - Ш)",	//+
"38.Тест ДОЗУ(СП2 - Ш)",
"39.Тест ДОЗУ(СП3 - Ш)",

"40.Тест СК0",				//+
"41.Тест СК1",				//+
"42.Тест СК2",
"43.Тест СК3",

"44.Ответ СП0 центр-ому",	//-  нет и, наверное, не будет
"45.Ответ СП1 центр-ому",	//-
"46.Ответ СП2 центр-ому",
"47.Ответ СП3 центр-ому",


"44.Ф-ия сравнения СП0",	//---
"45.Ф-ия сравнения СП1",	//---
"46.Ф-ия сравнения СП2",
"47.Ф-ия сравнения СП3",

"endik",
""
};

// "1.Тест ОЗУ ПП"
TEST_IFACE test1 = {1, F_test_ram, 
	NameTests[0], true, 1};

// "2.Тест ГСЧ1"
TEST_IFACE test2 = {2, F_test_random1, 
	NameTests[1], true, 1};

// "3.Тест ГСЧ2"
TEST_IFACE test3 = {3, F_test_random2, 
	NameTests[2], true, 1};

// "4.Тест датчика вскр. РИК"
TEST_IFACE test4 = {4, F_test_access_sensor_rik, 
	NameTests[3], true, 1};

// "5.Тест датчика вскрытия"
TEST_IFACE test5 = {5, F_test_access_sensor, 
	NameTests[4], true, 1};

// "6.Тест датчика панели"
TEST_IFACE test6 = {6, F_test_power_sensor, 
	NameTests[5], true, 1};

// "7.Тест часов реал. времени"
TEST_IFACE test7 = {7, F_test_rtc, 
	NameTests[6], true, 1};

// "8.Тест контроллера USB"
TEST_IFACE test8 = {8, F_test_usbc, 
	NameTests[7], true, 1};

// "9.Тест чтения USB флэш #1"
TEST_IFACE test9 = {9, F_test_usb_flash1, 
	NameTests[8], true, 1};

// "10.Тест чтения USB флэш #2"
TEST_IFACE test10 = {10, F_test_usb_flash2, 
	NameTests[9], true, 1};

// "11.Тест РИК1"
TEST_IFACE test11 = {11, F_test_rik1, 
	NameTests[10], true, 1};

// "12.Тест РИК2"
TEST_IFACE test12 = {12, F_test_rik2, 
	NameTests[11], true, 1};

// "13.Тест записи чтения Периферийного устройства"
TEST_IFACE test13 = {13, F_test_PU, 
	NameTests[12], true, 1};

// "14.Целостность ПО ПП"
TEST_IFACE test14 = {14, F_hash_comp, 
	NameTests[13], true, 1};

// "15.Тест фун-ии сравн-ия ПП"
TEST_IFACE test15 = {15, F_TEST_CMP_PP, 
	NameTests[14],true, 1};

// "16.Ответ ЦП периф-ому"
TEST_IFACE test16 = {16, F_reserved, 
	NameTests[15],true, 1};



// "17.резерв для ПП"
TEST_IFACE test17 = {17, F_reserved, 
	NameTests[16],false, 1};
// "18.резерв для ПП"
TEST_IFACE test18 = {18, F_reserved, 
	NameTests[17],false, 1};
// "19.резерв для ПП"
TEST_IFACE test19 = {19, F_reserved, 
	NameTests[18],false, 1};
// "20.резерв для ПП"
TEST_IFACE test20 = {20, F_reserved, 
	NameTests[19],false, 1};


//Для СВ
TEST_IFACE test21 = {21, F_hash_comp_main, 
	NameTests[20],true, 1};
TEST_IFACE test22 = {22, F_hash_comp_comm0, 
	NameTests[21],true, 1};
TEST_IFACE test23 = {23, F_hash_comp_comm1, 
	NameTests[22],true, 1};
TEST_IFACE test24 = {24, F_reserved, 
	NameTests[23],false, 1};
TEST_IFACE test25 = {25, F_reserved, 
	NameTests[24],false, 1};
TEST_IFACE test26 = {26, F_test_sdram_main, 
	NameTests[25],true, 1};
TEST_IFACE test27 = {27, F_test_nvram_main, 
	NameTests[26],true, 1};
TEST_IFACE test28 = {28, F_reserved, 
	NameTests[27],false, 1};
TEST_IFACE test29 = {29, F_test_usbc_main, 
	NameTests[28],true, 1};
TEST_IFACE test30 = {30, F_test_usb_main, 
	NameTests[29],true, 1};

TEST_IFACE test31 = {31, F_reserved, 
	NameTests[30],true, 1};
TEST_IFACE test32 = {32, F_test_dozu0, 
	NameTests[31],true, 1};
TEST_IFACE test33 = {33, F_test_dozu1, 
	NameTests[32],true, 1};
TEST_IFACE test34 = {34, F_reserved, 
	NameTests[33],false, 1};
TEST_IFACE test35 = {35, F_reserved, 
	NameTests[34],false, 1};
TEST_IFACE test36 = {36, F_test_move0, 
	NameTests[35],true, 1};
TEST_IFACE test37 = {37, F_test_move1, 
	NameTests[36],true, 1};
TEST_IFACE test38 = {38, F_reserved, 
	NameTests[37],false, 1};
TEST_IFACE test39 = {39, F_reserved, 
	NameTests[38],false, 1};
TEST_IFACE test40 = {40, F_test_sk0, 
	NameTests[39],true, 1};
TEST_IFACE test41 = {41, F_test_sk1, 
	NameTests[40],true, 1};
TEST_IFACE test42 = {42, F_reserved, 
	NameTests[41],true, 1};
TEST_IFACE test43 = {43, F_reserved, 
	NameTests[42],true, 1};
TEST_IFACE test44 = {44, F_reserved, //тест спарки на СП0
	NameTests[43],true, 1};
TEST_IFACE test45 = {45, F_reserved, 
	NameTests[44],true, 1};
TEST_IFACE test46 = {46, F_reserved, 
	NameTests[45],true, 1};
TEST_IFACE test47 = {47, F_reserved, 
	NameTests[46],true, 1};



TEST_IFACE *TESTS_PP[]=
{
    &test1,
    &test2,
    &test3,
    &test4,
    &test5,
    &test6,
    &test7,
    &test8,
    &test9,
    &test10,
    &test11,
    &test12,
    &test13,
    &test14,
    &test15,

//#	ifdef MCBSP_TEST
//    &test46,
//#	endif
    NULL
};


TEST_IFACE *NASTROJKA[]=
{
    &test1,
    &test2,
    &test3,
    &test4,
    &test5,
    &test6,
    &test7,
    &test8,
    &test9,
    &test10,
    &test11,
    &test12,
    &test13,
    &test14,
    &test15,
    &test16,

    &test17,
    &test18,
    &test19,
    &test20,
	//все тесты ПП


    &test21,
    &test22,
    &test23,
    &test24,
    &test25,
    &test26,
    &test27,
    &test28,
    &test29,
    &test30,
    &test31,
    &test32,
    &test33,
    &test34,
    &test35,
    &test36,
    &test37,
    &test38,
    &test39,
    &test40,
    &test41,

    NULL
};




void F_BeginTest(uint32);
void F_StartTest(uint32 count);
int PrintfResCiklTest(uint32 count);
void F_PrintMemTablo(uint16);
void F_GetPageTablo(uint16 key);


void F_TestProgress(int weight);

#endif //IFACE_TPO_H

