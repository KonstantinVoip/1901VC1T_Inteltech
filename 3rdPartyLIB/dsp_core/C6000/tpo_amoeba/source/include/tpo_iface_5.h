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

#define maxN_Tests_PP	15 //�� � ������� ����� �� 00, � 01!!!!!
#define minN_Tests_CP	20 //�� � ������� ����� �� 00, � 01!!!!!
#define maxN_AllTest 	64

//���������� ������� ������
#define start(stroka)   clrscr();\
			gotoxy(0,13);\
            cprintf("%-22.22s\nENTER - ��\nESC   - �����\n",stroka);\
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
	int startup;		//����� ��������� ������� ����� ����� � �������.
	int repeat;
}TEST_IFACE; 



char* NameTests[]=
{
"01.���� ���(SDRAM) ��",	//+	���������� � ���� ������������� ���� � ������� �� ��
"02.���� ��� 1", 			//+
"03.���� ��� 2",			//+
"04.���� ����. ����. ���", 	//+	������ ��������: ������ ��� ������
"05.���� ����. ����.", 		//+	������ ��������: ������ ��� ������
"06.���� ����. ������", 	//+	������ ��������: ������ ��� ������
"07.���� ����� �. ��.",		//+
"08.���� �����. USB ��",	//+
"09.���� �/�� USB ����1",	//+ 
"10.���� �/�� USB ����2",	//+
"11.���� ��� 1",			//+
"12.���� ��� 2",			//+
"13.���� ��(����)",			//+
"14.����������� �� ��",		//+
"15.�-�� ��������� � ��",	//---
"16.����� �� �����-���",	//--- ��� �, ��������, �� �����

//-----------------------------------
"17.������ ��� ��",
"18.������ ��� ��",
"19.������ ��� ��",
"20.������ ��� ��",
//-----------------------------------

// ��� ��
//����� ������� ����� ��� �� - ������ �������� ��� ���������
//#define minN_Test6416  � maxN_AllTest  tpo_iface.h   

"21.����������� �� ��",		//+

"22.����������� �� �� 0",	//+
"23.����������� �� �� 1",	//+
"24.����������� �� �� 2",
"25.����������� �� �� 3",

"26.���� ���(SDRAM) ��",	//+
"27.���� ����(NVRAM) ��",	//+ ��� �����������
"28.����������� ���� ��",	//���� �������� ���� ����, �������� ������ ����� ��� � ����, ���� �� ������� ������

"29.���� �����. USB ��",	//+ �������������� ���� ����
"30.�/�� �����. USB ����",	//+

"31.���� ����(��0 - ��1)",	//---

"32.���� ����(�� - ��0)",	//+
"33.���� ����(�� - ��1)",	//+
"34.���� ����(�� - ��2)",
"35.���� ����(�� - ��3)",

"36.���� ����(��0 - �)",	//+
"37.���� ����(��1 - �)",	//+
"38.���� ����(��2 - �)",
"39.���� ����(��3 - �)",

"40.���� ��0",				//+
"41.���� ��1",				//+
"42.���� ��2",
"43.���� ��3",

"44.����� ��0 �����-���",	//-  ��� �, ��������, �� �����
"45.����� ��1 �����-���",	//-
"46.����� ��2 �����-���",
"47.����� ��3 �����-���",


"44.�-�� ��������� ��0",	//---
"45.�-�� ��������� ��1",	//---
"46.�-�� ��������� ��2",
"47.�-�� ��������� ��3",

"endik",
""
};

// "1.���� ��� ��"
TEST_IFACE test1 = {1, F_test_ram, 
	NameTests[0], true, 1};

// "2.���� ���1"
TEST_IFACE test2 = {2, F_test_random1, 
	NameTests[1], true, 1};

// "3.���� ���2"
TEST_IFACE test3 = {3, F_test_random2, 
	NameTests[2], true, 1};

// "4.���� ������� ����. ���"
TEST_IFACE test4 = {4, F_test_access_sensor_rik, 
	NameTests[3], true, 1};

// "5.���� ������� ��������"
TEST_IFACE test5 = {5, F_test_access_sensor, 
	NameTests[4], true, 1};

// "6.���� ������� ������"
TEST_IFACE test6 = {6, F_test_power_sensor, 
	NameTests[5], true, 1};

// "7.���� ����� ����. �������"
TEST_IFACE test7 = {7, F_test_rtc, 
	NameTests[6], true, 1};

// "8.���� ����������� USB"
TEST_IFACE test8 = {8, F_test_usbc, 
	NameTests[7], true, 1};

// "9.���� ������ USB ���� #1"
TEST_IFACE test9 = {9, F_test_usb_flash1, 
	NameTests[8], true, 1};

// "10.���� ������ USB ���� #2"
TEST_IFACE test10 = {10, F_test_usb_flash2, 
	NameTests[9], true, 1};

// "11.���� ���1"
TEST_IFACE test11 = {11, F_test_rik1, 
	NameTests[10], true, 1};

// "12.���� ���2"
TEST_IFACE test12 = {12, F_test_rik2, 
	NameTests[11], true, 1};

// "13.���� ������ ������ ������������� ����������"
TEST_IFACE test13 = {13, F_test_PU, 
	NameTests[12], true, 1};

// "14.����������� �� ��"
TEST_IFACE test14 = {14, F_hash_comp, 
	NameTests[13], true, 1};

// "15.���� ���-�� �����-�� ��"
TEST_IFACE test15 = {15, F_TEST_CMP_PP, 
	NameTests[14],true, 1};

// "16.����� �� �����-���"
TEST_IFACE test16 = {16, F_reserved, 
	NameTests[15],true, 1};



// "17.������ ��� ��"
TEST_IFACE test17 = {17, F_reserved, 
	NameTests[16],false, 1};
// "18.������ ��� ��"
TEST_IFACE test18 = {18, F_reserved, 
	NameTests[17],false, 1};
// "19.������ ��� ��"
TEST_IFACE test19 = {19, F_reserved, 
	NameTests[18],false, 1};
// "20.������ ��� ��"
TEST_IFACE test20 = {20, F_reserved, 
	NameTests[19],false, 1};


//��� ��
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
TEST_IFACE test44 = {44, F_reserved, //���� ������ �� ��0
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
	//��� ����� ��


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

