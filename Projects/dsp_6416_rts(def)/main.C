/***********************************************************************************
*                             (c) COPYRIGHT by PAO Inteltech.     			*
*                             All rights reserved.         					*
*************************************************************************************
* Module      : Main.c
* Description : Main Initialization File for DSP CORE 1901��1�
* Author      : Konstantin Shiluaev
******************************************************************************/
/*���� DSP 16 ��������� ������������� �������� � ������������� ������
  �������� ���� 16 ���. */ 
  
/* Reference to start of interrupt vectors */
//extern void VECSTART(void);

//#include "C:\1901VC1T_Inteltech\Projects\skd_arm_dsp\inc\skd_test_buf.h"

/*���� ������ TMS54xx � ����������� � spru103g  p.112
* signed char 16 bits ASCII							 -32 768 32 767
* char, unsigned char 16 bits ASCII 					0    65 535
* short, signed short 16 bits 2s complement 		 -32 768 �� 32 767
* unsigned short 16 bits Binary 						0 65 535
* int, signed int 16 bits 2s complement 			-32 768 �� 32 767
* unsigned int 16 bits Binary 							0 65 535
* long, signed long 32 bits 2s complement    -2 147 483 648    2 147 483 647
* unsigned long 32 bits Binary 							0      4 294 967 295
* enum 16 bits 2s complement 						-32 768   32 767
  float 32 bits IEEE 32-bit 				  1.175 494e-38   3.40 282 346e+38
  double 32 bits IEEE 32-bit 				  1.175 494e-38   3.40 282 346e+38
  long double 32 bits IEEE 32-bit             1.175 494e-38   3.40 282 346e+38
  pointers 16 bits Binary							   0      0xFFFF
*/

/*
��������� ������ ���� Heap = 0x2000 (8 �/����) ������ ���� malloc
��������� ������ �����     = 0x400  (1 �/����)
*/

#include <stdio.h>
#include <math.h>
#include <ctype.h> 
#include <limits.h>
#include <string.h>
 
 
//#include "header.h"






unsigned long volatile  dsp_TimerCounter=0;
static unsigned long timer_counter =0;

//#define  TRUE  1
//#define  FALSE 0

/*CPU Register */
#define 	IMR                     0x0000

/*Audio Codec Reg*/
#define     DACREG                  0x005C 
#define     ADCREG                  0x005A 
#define     IRQFLAG                 0x0058  
#define     MASKCTL                 0x0056 
#define     DACCTL					0x0054 
#define     ADCCTL					0x0052 
#define     POWCTL					0x0050 




#define M_PI					    3.14159265358979323846
#define WAVFILE_SAMPLES_PER_SECOND  8000 //������� �������������

/*���������� ���������� ��� ����� ������*/


//����� ��������� � ���� 
/*
static _DATA_ACCESS const unsigned int kosta_len[] = {31,28,31,30};

_CODE_ACCESS int is_kosta(int c)
{
    return 0;
}*/

/*
static long global_timer_counter=0;
static long global_nop_counter=0;

static unsigned short dsp_CurrentLed=0;

static int count1=0;
static int count2=0;
static int count3=0;
*/
/*******************************************************************/
/*  INCLUDES                                					   */
/******************************************************************/
volatile unsigned short i_adc =0;
volatile unsigned short i_dac =0;

/*������� ������� ����������� ����������*/
extern void _tint_intr(void);
extern void _codec_intr(void);




/*������� ������������� 26 ������� ��������� DSP ����*/
static unsigned short init_dsp_core();
/*������� ������������� ����� �����*/
static unsigned short init_dsp_audio_codec();



/*******************************�������*************************************/

/*******************************************************************************
* Function Name :static  void isr_dsp_timer()
* Description   :������� ���������� ��������� �� �������
*******************************************************************************/

/*******************************************************************************
* Function Name  : unsigned short init_dsp_core()
* Description    : 
*******************************************************************************/
unsigned short init_dsp_core()
{
        /*������������� ������� IMR */
       //������� ����� ���������� ��������� ���������� ������ � ������� p.333
       //������� ������������ ������ ����� ���������� �������.
        //_IMR=0x0808;
       /*��������� ������ ����� ����� + ������ */
       // _IMR=0x0800;
       // write_2bait_memory(IMR,0x0800);
       
       //26 ��������� ���� ���� ���������� �������� STM 
	     //��������� ��
	     //  asm(" STM  #0x0000, imr ");
        /*��������� ������ ������ */
        //   asm(" STM  #0x0008, imr "); 
       /*���������  ����� ����� + ������ */
        // asm(" STM  #0x0808, imr "); 
	   /*��������� ������ ����� ����� */
       // asm(" STM  #0x0800, imr ");  
      
      //������������ ���������� ������������� ���  INTM = 0 
      //� �������� ST1 ,���������� ��������� ������������ ������ ���� DSP
        //  asm("  RSBX INTM  ");   
      //  asm("  SSBX INTM  "); 

  printf("init_dsp_core()_OK\n");

  return 1;
}




/*******************************************************************************
* Function Name  : void main()
* Description    : Start Function Main
*******************************************************************************/
void main()
{
//	unsigned short num_of_sample_encoder=0;
//	unsigned short size_of_array_encoder =0;
//	unsigned short num_of_sample_decoder=0;
//	unsigned short size_of_array_decoder =0;


    init_dsp_core();
    
    while(1)
    {
        
    }//end while 1
 
}



/*-----------------------------------------------------------------------------
* void PerformIsr1(void)
*
* Indicate that Isr1 is being performed, and increment the number of times
* it has been performed. Every so often, take a longer time than normal
* to introduce some variability into the system timing.
*----------------------------------------------------------------------------*/
interrupt void PerformIsr1(void)
{

}

 								
/*-----------------------------------------------------------------------------
* void PerformIsr2(void)
*
* Indicate that Isr2 is being performed, and increment the number of times
* it has been performed. Every so often, take a longer time than normal
* to introduce some variability into the system timing.
*----------------------------------------------------------------------------*/
interrupt void PerformIsr2(void)
{
 
}


/*-----------------------------------------------------------------------------
* void PerformIsr3(void)
*
* Indicate that Isr3 is being performed, and increment the number of times
* it has been performed. Every so often, take a longer time than normal
* to introduce some variability into the system timing.
*----------------------------------------------------------------------------*/
interrupt void PerformIsr3(void)
{
 
}