/***********************************************************************************
*                             (c) COPYRIGHT by PAO Inteltech.     			*
*                             All rights reserved.         					*
*************************************************************************************
* Module      : Main.c
* Description : Main Initialization File for DSP CORE 1901ВЦ1Т
* Author      : Konstantin Shiluaev
******************************************************************************/
/*Ядро DSP 16 разрядное соответсвенно регистры с фиксированной точкой
  Регистры тоже 16 бит. */ 
  
/* Reference to start of interrupt vectors */
//extern void VECSTART(void);

//#include "C:\1901VC1T_Inteltech\Projects\skd_arm_dsp\inc\skd_test_buf.h"

/*ТИПЫ ДАННЫХ TMS54xx в соответсвии с spru103g  p.112
* signed char 16 bits ASCII							 -32 768 32 767
* char, unsigned char 16 bits ASCII 					0    65 535
* short, signed short 16 bits 2s complement 		 -32 768 до 32 767
* unsigned short 16 bits Binary 						0 65 535
* int, signed int 16 bits 2s complement 			-32 768 до 32 767
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
Установил размер Кучи Heap = 0x2000 (8 К/байт) отсюда берём malloc
Установил размер стека     = 0x400  (1 К/байт)
*/

#include <stdio.h>
#include <math.h>
#include <ctype.h> 
#include <limits.h>
#include <string.h>
 
 
#include "header.h"


/*Codec Init Files */
#include "skd_dsp_arm_memory.h"    //работа с памятьб 1901ВЦ1Т
#include "skd_dsp_arm_delay.h"     //работа с задержками и временем 1901ВЦ1Т




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
#define WAVFILE_SAMPLES_PER_SECOND  8000 //Частота дискретизации

/*Глобальные Переменные для аудио Кодека*/

/*
static unsigned short all_num_codec_interrupt=0;
static unsigned short num_codec_interrupt_0=0;
static unsigned short num_codec_interrupt_1=0;
static unsigned short num_codec_interrupt_2=0;
static unsigned short num_codec_interrupt_3=0;
static unsigned long  num_codec_interrupt_4=0;
static unsigned long  num_codec_interrupt_5=0;
static unsigned short num_codec_interrupt_6=0;
static unsigned short num_codec_interrupt_7=0;
static unsigned short num_codec_interrupt_8=0;
static unsigned short num_codec_interrupt_9=0;
static unsigned short num_codec_interrupt_A=0;
static unsigned short num_codec_interrupt_B=0;
static unsigned short num_codec_interrupt_C=0;
static unsigned short num_codec_interrupt_D=0;
static unsigned short num_codec_interrupt_E=0;
static unsigned short num_codec_interrupt_F=0;
*/

//Потом разберусь с этим 
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

/*Внешние функции Обработчики Прерываний*/
extern void _tint_intr(void);
extern void _codec_intr(void);




/*Функции инициализации 26 Базовых регистров DSP ядра*/
static unsigned short init_dsp_core();
/*Функции инициализации аудио кодек*/
static unsigned short init_dsp_audio_codec();


/*************************Инициализация Аудио Кодеков********************/
struct g722_init_encode_structure *g722e_1=0;
//struct g722_init_encode_structure *g722e_2=0;
//struct g722_init_encode_structure *g722e_3=0;
//struct g722_init_encode_structure *g722e_4=0;

  
struct g722_init_decode_structure *g722d_1=0;
//struct g722_init_decode_structure *g722d_2=0;
//struct g722_init_decode_structure *g722d_3=0;
//struct g722_init_decode_structure *g722d_4=0;


signed short   in_enc_sample_buffer_0[80*2];
unsigned short out_enc[40*2];
signed short   out_dec[80*2];


/*******************************ТАЙМЕРЫ*************************************/

/*******************************************************************************
* Function Name :static  void isr_dsp_timer()
* Description   :Функция обработчик преываний от таймера
*******************************************************************************/

/*
static  void isr_dsp_timer()
{
 
 
  //write_16bit_unsigned_mem(0xC000,num_codec_interrupt_4);    
 // write_32bit_signed_to_RISC(0xC000,num_codec_interrupt_4);
 // write_32bit_signed_to_RISC(0xC002,num_codec_interrupt_5);
//зажигаем светодиоды    
#if 0   
   switch (dsp_CurrentLed)
	{
      case 0 :
      dsp_CurrentLed=1;
      write_16bit_unsigned_mem(0xC000,0x0001);
      break;

      case 1 :
	  dsp_CurrentLed=0;
      write_16bit_unsigned_mem(0xC000,0x0000);
      break;

	  default:
	  break;
	}
#endif

}
*/


/*******************************************************************************
* Function Name  : unsigned short init_dsp_core()
* Description    : 
*******************************************************************************/
unsigned short init_dsp_core()
{
        /*Устанавливаем регистр IMR */
       //Регистр Маски Прерывания разрешаем прерывания кодека и таймера p.333
       //регистр сбрасыветься только после выключения питания.
        //_IMR=0x0808;
       /*разрешаем только аудио кодек + таймер */
       // _IMR=0x0800;
       // write_2bait_memory(IMR,0x0800);
       
       //26 регистров ядра буду выставлять командой STM 
	     //запрещаем всё
	     //  asm(" STM  #0x0000, imr ");
        /*разрешаем только таймер */
        //   asm(" STM  #0x0008, imr "); 
       /*разрешаем  аудио кодек + таймер */
         asm(" STM  #0x0808, imr "); 
	   /*разрешаем только аудио кодек */
       // asm(" STM  #0x0800, imr ");  
      
      //Ассемблерная инструкция устанавливает бит  INTM = 0 
      //в регистре ST1 ,разрешение прерывний перефирийных блоков ядра DSP
          asm("  RSBX INTM  ");   
      //  asm("  SSBX INTM  "); 

  printf("init_dsp_core()_OK\n");

  return 1;
}

/*******************************************************************************
* Function Name  : unsigned short init_dsp_audio_codec()
* Description    : 
*******************************************************************************/
unsigned short init_dsp_audio_codec()
{
 unsigned short i;
 static unsigned short gromk_din  =42 ;
// static unsigned short chustv_mic =42;  
          
 	 
 
	   //Локальная Петля через кодек DSP 
       #if 0
         write_16bit_unsigned_mem(DACCTL,0x83AA);
         write_16bit_unsigned_mem(ADCCTL,0x05E2);
         write_16bit_unsigned_mem(POWCTL,0x0007); //DAC enable, ADC enable
       #endif

       //Петля через внутренние буфера
	  // #if 0
        /*Инициализация Аудио Кодека*/	   
	    //Влиляет не слышно хлама в наушниках    
	    for(i=0;i<=15;i++)
        {
         write_16bit_signed_mem(DACREG,0xFFFF);
        } 		    
       	
       	write_16bit_unsigned_mem(DACCTL,0xF380|gromk_din);

       // write_2bait_memory(DACCTL,0xF380|gromk_din);   
       // write_2bait_memory(DACCTL,0xF380|gromk_din);
       // write_16bit_unsigned_mem(ADCCTL,0x0500|chustv_mic);
        write_16bit_unsigned_mem(ADCCTL,0x052A);

       /********Маскирование прерывний от Аудиокодека*****/
	   //При старте все Прерывания разрешены 0x001f 
       //write_2bait_memory(MASKCTL,0x001F);// разрешение всех прерывний  АЦП+ЦАП
       //write_2bait_memory(MASKCTL,0x0000);// запрет всех прерывний
		//write_2bait_memory(MASKCTL,0x0002);// FIFO ADC _enable
        //write_2bait_memory(MASKCTL,0x0004);// FIFO ADC _enable
	    write_16bit_unsigned_mem(MASKCTL,0x000F);// FIFO ADC _enable + FIFO DAC _enable
        //write_2bait_memory(MASKCTL,0x0019);// разрешение прерывний ЦАП  (DAC)
      //  write_16bit_unsigned_mem(MASKCTL,0x0006);// разрешение прерывний АЦП  (ADC)
	   /*******Управление питанием Аудиокодека******/        
        // write_16bit_unsigned_mem(POWCTL,0x0007);//ADC+DAC POWER_ON
       // write_2bait_memory(POWCTL,0x0006);//ADC_POWER_OFF|DAC_POWER_ON
       //   write_2bait_memory(POWCTL,0x0005);//ADC_POWER_ON|DAC_POWER_OFF
       //   write_2bait_memory(POWCTL,0x0000);//ADC_POWER_OFF|DAC_POWER_OFF
        //   write_2bait_memory(POWCTL,0x0001);//ADC_POWER_ON
        write_16bit_unsigned_mem(POWCTL,0x0003);//ADC_POWER_ON
    
       //#endif
       
       
 printf("+init_dsp_audio_codec()_OK+\n");
       

  return 1;
}


/*******************************************************************************
* Function Name  : void main()
* Description    : Start Function Main
*******************************************************************************/
void main()
{
unsigned short num_of_sample_encoder=0;
unsigned short size_of_array_encoder =0;
unsigned short num_of_sample_decoder=0;
unsigned short size_of_array_decoder =0;


/*Настройки синуса*/
  //unsigned short tick=0x0000;
 //   int i;
  //,count2=0;,count3=0;
 // double frequency_1 = 150.0;  //частота
//  double frequency_2 = 200.0;
//  double frequency_3 = 250.0;
//  double frequency_4 = 400.0;
  
  //int volume = 16000;        //громкость
 // unsigned short i=0,j=0,m=0;
 //long l=0;
 // double t,t1,t2;

 // signed short retvalue1=0,retvalue2=0,retvalue3=0,retvalue4=0;
 // signed short dec_retvalue1=0,dec_retvalue2=0,dec_retvalue3=0,dec_retvalue4=0;

//unsigned short out_enc[40];
//signed short   out_dec[80];


/*
signed short in_enc_sample_buffer_0[80]={
0,8810,-16300,21348,-23198,21570,-16710,9346,-582,-8268,15880,-21114,23182,-21778,17110,-9878,
1164,7720,-15450,20866,-23154,21972,-17498,10402,-1746,-7168,15010,-20604,23110,-22152,17874,-10920,
2328,6612,-14562,20330,-23050,22318,-18240,11430,-2906,-6050,14102,-20042,22978,-22470,18596,-11934,
3484,5486,-13636,19742,-22890,22608,-18938,12430,-4060,-4918,13160,-19430,22788,-22732,19268,-12918,
4632,4346,-12676,19106,-22672,22840,-19588,13398,-5202,-3772,12184,-18768,22540,-22936,19894,-13870};
*/


/*
signed short out_enc_sample_buffer_0[20]=
{
0xB222,
0x8420,
0x8520,
0xbbbf,
0xbebd,
0x3E3F,
0x3F3F,
0xbdbd,
0xbfbf,
0x3F3F,
0x3D3D,
0xbdbd,
0xbfbf,
0x3f3f,
0x3d3d,
0xbdbd,
0xbfbf,
0x3f3f,
0x3d3d,
0xbdbd,
};
*/
/*
signed short in_dec_sample_buffer_0[40]=
{
0x00B2,
0x0022,
0x0084,
0x0020,
0x0085,
0x0020,
0x00bb,
0x00bf,
0x00be,
0x00bd,
0x003E,
0x003F,
0x003F,
0x003F,
0x00bd,
0x00bd,
0x00bf,
0x00bf,
0x003F,
0x003F,
0x003D,
0x003D,
0x00bd,
0x00bd,
0x00bf,
0x00bf,
0x003f,
0x003f,
0x003d,
0x003d,
0x00bd,
0x00bd,
0x00bf,
0x00bf,
0x003f,
0x003f,
0x003d,
0x003d,
0x00bd,
0x00bd,
};
*/

  /*
  unsigned short A =0x0000;
  unsigned short B =0x0000;
  unsigned short C =0x0000;
  */
 /*
  A=0x00F0;
  B=0x001A;
 */
 
  /*
   A=0x5551;
   B=0x1001;
  
  //C=A&B;
   C=A&&B;  
  */


   //  unsigned char mas1[4]={0x11,0x22,0x33,0x55};
   write_32bit_signed_to_RISC(0xC000,0x00000000);
   write_32bit_signed_to_RISC(0xC002,0x00000000);
   write_32bit_signed_to_RISC(0xC004,0x00000000);
   write_32bit_signed_to_RISC(0xC006,0x00000000);
   write_32bit_signed_to_RISC(0xC008,0x00000000);
   write_32bit_signed_to_RISC(0xC00A,0x00000000);
   write_32bit_signed_to_RISC(0xC00C,0x00000000);
   write_32bit_signed_to_RISC(0xC00E,0x00000000); 
   write_32bit_signed_to_RISC(0xC010,0x00000000);
   write_32bit_signed_to_RISC(0xC012,0x00000000);
   write_32bit_signed_to_RISC(0xC014,0x00000000);
   write_32bit_signed_to_RISC(0xC016,0x00000000);
   write_32bit_signed_to_RISC(0xC018,0x00000000);
   write_32bit_signed_to_RISC(0xC01A,0x00000000);
   write_32bit_signed_to_RISC(0xC01C,0x00000000);
   write_32bit_signed_to_RISC(0xC01E,0x00000000);


	/*
    write_16bit_unsigned_to_RISC(0xC000,0x0000);
    
    write_16bit_unsigned_to_RISC(0xC001,0x1122);
    
    write_16bit_unsigned_to_RISC(0xC002,0x3344);  
    */
   
/*
 signed short a=1;
 signed short b=2;
 signed short c=3;

 signed short e=-1;
 signed short f=-2;
 signed short g=-3;
*/

/*
 signed short a=23198;   //расположение отрицательного числа в памяти =  (FFFFA561).
 signed short b=16710;
 signed short c=582;

 signed short e=-23198; 
 signed short f=-16710;
 signed short g=-582; 
 */

    //f ();

    init_dsp_audio_codec();
    init_dsp_timer();
    init_dsp_core();
    
        
         
      g722e_1=init_g722_encoder(1);
    //  g722e_2=init_g722_encoder(2);
	//  g722e_3=init_g722_encoder(3);
	//  g722e_4=init_g722_encoder(4);
      g722d_1=init_g722_decoder(1);
    

 /*     
	  memset(out_enc, 0x0000, sizeof(out_enc));
      memset(out_dec, 0x0000, sizeof(out_dec));
      

	  //Количество Отсчётов 
      num_of_sample_encoder=g722_encoder1(g722e_1,out_enc, in_enc_sample_buffer_0, 80);
      size_of_array_encoder=sizeof(out_enc);

      //Здесь должно быть что-то вроде передачи информации по сети ,задержка
      //Передаём Данные в RISC ядро или что-то подобное декодируем 
      
      num_of_sample_decoder=g722_decoder1(g722d_1,out_dec, out_enc, 40);
      size_of_array_decoder=sizeof(out_dec);
*/



	  //Когда Закончили выделять Память нужно её очистить. 
	  /* 
      free (g722d_1);
	  free (g722e_1);
      */

    /*
	g722e_2=init_g722_encoder(2);
    g722d_2=init_g722_decoder(2); 

    g722e_3=init_g722_encoder(3);
    g722d_3=init_g722_decoder(3); 

	g722e_4=init_g722_encoder(4);
    g722d_4=init_g722_decoder(4); 
    */

   
   
    //g722_encoder11(g722e_1, out_enc_sample_buffer_1, in_enc_sample_buffer_0, 80);

   

   //dsp_sys_timer_set_millisecond_delay(5000); //Задержка перед стартом Аудиокодека 5 секунд
   
   //функция обработчик прерываний от аудокодека только после инициализации
   // init_dsp_audio_codec();
    
    //dsp_sys_timer_start_millisecond(10000);          //запустили таймер c задержкой 10 [сек]
	//Функция работы с таймером DSP 
    //dsp_sys_timer_start_millisecond(10000); //устанавливаем задержку 10000 [мс] = 10 [сек]

    //Тестовые Прогоны Кодека должны G.722
//#if 0
   
   //m=get_timer_tick_value();
   //sys_timer_start();
  // write_16bit_unsigned_to_RISC(0xC00F,get_timer_tick_value());
    //i=100;
    //write_16bit_unsigned_mem(TCR,0x0020);// START TIMER TSS=0 | TRB =1 |TRD=0x0
     
	 
	  /*
	  retvalue2=encode_g722_1(in_enc_sample_buffer_0,80);
	  for(i=0;i<retvalue2;i++)
   	  {
   	  printf("elm[%d]=%x\n",i,out_enc_sample_buffer_1[i]);
   	  }
      */  
          
      /*
	  dec_retvalue1=decode_g722_1(in_dec_sample_buffer_0,40);
	  for(j=0;j<dec_retvalue1;j++)
   	  {
   	  printf("elm_dec[%d]=%d\n",j,out_dec_sample_buffer_1[j]);
   	  }
      */


	 /*
      while(i)
	  {
      //asm ("NOP"); 
      i--;
	  }
     */

   /*
   for(i=0;i<1;i++)
   {
     asm ("NOP");
   }*/
 //  write_16bit_unsigned_mem(TCR,0x0010);// STOP TIMER
   //retvalue2=encode_g722_2(in_enc_sample_buffer_0,10000); //на вход кодека 80 отсчётов 16 бит
  // retvalue2=encode_g722_1(in_enc_sample_buffer_0,80); //на вход кодека 80 отсчётов 16 бит
   //sys_timer_stop();
 //  write_16bit_unsigned_to_RISC(0xC010,get_timer_tick_value());
   //tick=get_timer_tick_value();
 //  write_16bit_unsigned_to_RISC(0xC00F,timer_counter);
   //printf("tick =%d|%x\n\r",tick,tick);
   /*
    =get_timer_tick_value();
   dec_retvalue1=decode_g722_2(out_enc_sample_buffer_2,retvalue2);        
    =get_timer_tick_value();
     sys_timer_stop();
   */
   /*
  	  for(i=0;i<retvalue2;i++)
   	  {
   	  printf("elm[%d]=%x\n",i,out_enc_sample_buffer_2[i]);
   	  }
   */  
       
   /*  
      for(j=0;j<dec_retvalue1;j++)
   	  {
   	  printf("elm_dec[%d]=%d\n",j,out_dec_sample_buffer_2[j]);
   	  }
   
   }*/
//#endif


   //#if 0
      //Генератор массива синуса заполняем входные буфера отсчётами синуса 320 отсчётов
      /*
	  for(i=0;i<320;i++)
      {
        t = (double) i / WAVFILE_SAMPLES_PER_SECOND;
        in_enc_sample_buffer_1[i] = volume*sin(frequency_1*t*2*M_PI);
      }*/
  
      /*
      for(i=0;i<320;i++)
      {
        t = (double) i / WAVFILE_SAMPLES_PER_SECOND;
        in_enc_sample_buffer_2[i] = volume*sin(frequency_2*t*2*M_PI);
      }
        
        
	  for(i=0;i<320;i++)
      {
        t = (double) i / WAVFILE_SAMPLES_PER_SECOND;
        in_enc_sample_buffer_3[i] = volume*sin(frequency_3*t*2*M_PI);
      } 

   
      for(i=0;i<320;i++)
      {
        t = (double) i / WAVFILE_SAMPLES_PER_SECOND;
        in_enc_sample_buffer_4[i] = volume*sin(frequency_4*t*2*M_PI);
      } 
      */

   // #endif
   
   //dsp_sys_timer_set_millisecond_delay(10000);
   
  //printf("++OK++\n");
  //i=0;
  
   //dsp_sys_timer_start_second(10000);          //запустили таймер c задержкой 10 [сек]
   while(1)
   {

     
      if(i_adc==80)
      {
      memset(out_enc, 0x0000, sizeof(out_enc));
	  //Количество Отсчётов 
      num_of_sample_encoder=g722_encoder1(g722e_1,out_enc, in_enc_sample_buffer_0, i_adc);
      //size_of_array_encoder=sizeof(out_enc);
      }

      //Здесь должно быть что-то вроде передачи информации по сети ,задержка
      //Передаём Данные в RISC ядро или что-то подобное декодируем 
     
      

      
      memset(out_dec, 0x0000, sizeof(out_dec)); 
      num_of_sample_decoder=g722_decoder1(g722d_1,out_dec, out_enc, 40);
      size_of_array_decoder=sizeof(out_dec);
      




    //Пока нет задержек это работает 

	//dsp_sys_timer_set_millisecond_delay(10000); //задержка 10 [сек]
	//isr_dsp_timer();


	//if(global_nop_counter==100000000)
	//{ 
   	//	 write_32bit_signed_to_RISC(0xC000,global_timer_counter);
    //write_32bit_signed_to_RISC(0xC000,global_timer_counter); 
    //	 global_nop_counter=0;;
    //}
    //global_nop_counter++;
    /*
    t = (double) i / WAVFILE_SAMPLES_PER_SECOND;
    in_enc_sample_buffer_2[i] = volume*sin(frequency_2*t*2*M_PI);
    if(i==320)
	{
    retvalue2=encode_g722_2(in_enc_sample_buffer_2,i);
    decode_g722_2(out_enc_sample_buffer_2,retvalue2);
    i=0;
	count1++;
	}
    i++;
    */

   
    /*
    t1 = (double) j / WAVFILE_SAMPLES_PER_SECOND;
    in_enc_sample_buffer_3[j] = volume*sin(frequency_3*t1*2*M_PI);
    if(j==320)
	{
    retvalue1=encode_g722_3(in_enc_sample_buffer_3,j);
    decode_g722_3(out_enc_sample_buffer_3,retvalue1);
    j=0;
	count2++;
	}
    j++;


  
    t2 = (double) m / WAVFILE_SAMPLES_PER_SECOND;
    in_enc_sample_buffer_4[m] = volume*sin(frequency_4*t2*2*M_PI);
    if(m==320)
	{
    retvalue2=encode_g722_4(in_enc_sample_buffer_4,m);
    decode_g722_4(out_enc_sample_buffer_4,retvalue2);
    m=0;
	count3++;
	}
    m++;
   */

   }//end while 1
 
}


/////////обработчик прерывания от аппаратного таймера DSP
interrupt void _tint_intr(void)
{
timer_counter++;   
 //Функции установки задержек в коде можем пока не использовать   
#if 0 
    if(dsp_TimerCounter)
    {
      dsp_TimerCounter--;
    }
#endif     
 
 //Функции Обработчики аппаратных прерываний по таймеру           
#if 0
  //для 8 [Мгц]
  if(DSP_TIMER_8MHz)
  {
             if(dsp_TimerCounter==timer_counter)
             {
             isr_dsp_timer();
             timer_counter=0;
             }

  }  //END DSP_TIMER_8MHz

 
 //для 24 [Мгц]
 if(DSP_TIMER_24MHZ)
 {
            
             if(SYSTIMER_SECOND)
			 {
             	if((dsp_TimerCounter*1000)==timer_counter)
             	{
             	isr_dsp_timer();
             	timer_counter=0;
                }
             }
             
             //////////////////////////////////////////////////////
             if(SYSTIMER_MILLISECOND)
			 {
                if(dsp_TimerCounter==timer_counter)
                {
                isr_dsp_timer();
                timer_counter=0;
                }
             }

 } //END DSP_TIMER_24MHZ

  //для 96 [Мгц]
  if(DSP_TIMER_96MHz) 
  { 
            if(SYSTIMER_SECOND)
			{
            	if((dsp_TimerCounter*2000)==timer_counter)
           		 {
           		 isr_dsp_timer();
            	timer_counter=0;
				}
            }
          

            if(SYSTIMER_MILLISECOND)
			{
           	  if(dsp_TimerCounter==timer_counter)
              {
              isr_dsp_timer();
              timer_counter=0;
              }
            }
  } //END DSP_TIMER_96MHz

timer_counter++; //общее количество вызова функции обработчкиа прерываний

#endif

}  //END TININTR


//обработчик прерывания от Аудио Кодека
interrupt void _codec_intr(void)
{
//    unsigned short out_enc_num_samples=0x0000;
//    unsigned short out_dec_num_samples=0x0000;  
    unsigned short out_irq=0x0000;

	//Пишем общее количество прерываний
     // all_num_codec_interrupt++;
      //write_16bit_unsigned_to_RISC(0xC000,all_num_codec_interrupt);
   // all_num_codec_interrupt++; 
    out_irq=read_16bit_unsigned_mem(IRQFLAG);
   
   // write_16bit_unsigned_to_RISC(0xC000,out_irq);
#if 0 
    switch(out_irq)
	{
    case 0x0000:
	num_codec_interrupt_0++;
	//write_16bit_unsigned_to_RISC(0xC001,num_codec_interrupt_0);	
	break;

	case 0x0001:
	num_codec_interrupt_1++;
	//write_16bit_unsigned_to_RISC(0xC002,num_codec_interrupt_1);
	break;

	case 0x0002:
	num_codec_interrupt_2++;
	//write_16bit_unsigned_to_RISC(0xC003,num_codec_interrupt_2);	
	break;

    case 0x0003:
	num_codec_interrupt_3++;
	//write_16bit_unsigned_to_RISC(0xC004,num_codec_interrupt_3);
	break;

	case 0x0004:
	in_enc_sample_buffer_2[i_adc]=read_16bit_signed_mem(ADCREG);
	num_codec_interrupt_4++; //можно сказать что это количество входных отсчётов
	//write_16bit_unsigned_to_RISC(0xC005,num_codec_interrupt_4);
	break;

    case 0x0005:
    in_enc_sample_buffer_2[i_adc]=read_16bit_signed_mem(ADCREG);
    num_codec_interrupt_5++;
    write_16bit_unsigned_to_RISC(0xC006,num_codec_interrupt_5);
	break;

    case 0x0006:
	num_codec_interrupt_6++;
//	write_16bit_unsigned_to_RISC(0xC007,num_codec_interrupt_6);
	break;

    case 0x0007:
    in_enc_sample_buffer_2[i_adc]=read_16bit_signed_mem(ADCREG);
    num_codec_interrupt_7++;

    write_16bit_unsigned_to_RISC(0xC008,num_codec_interrupt_7);
	break;

	case 0x0008:
	write_16bit_signed_mem(DACREG,in_enc_sample_buffer_2[i_adc]);
	num_codec_interrupt_8++;
//	write_16bit_unsigned_to_RISC(0xC009,num_codec_interrupt_8);
	break;
    
    case 0x0009:
    write_16bit_signed_mem(DACREG,in_enc_sample_buffer_2[i_adc]);
	num_codec_interrupt_9++;
	write_16bit_unsigned_to_RISC(0xC00A,num_codec_interrupt_9);
	break;

	case 0x000A:
    num_codec_interrupt_A++;
//	write_16bit_unsigned_to_RISC(0xC00B,num_codec_interrupt_A);
	break;

    case 0x000B:
    write_16bit_signed_mem(DACREG,in_enc_sample_buffer_2[i_adc]);
	num_codec_interrupt_B++;
	write_16bit_unsigned_to_RISC(0xC00C,num_codec_interrupt_B);
	break;

    case 0x000C:
    in_enc_sample_buffer_2[i_adc]=read_16bit_signed_mem(ADCREG);
    write_16bit_signed_mem(DACREG,in_enc_sample_buffer_2[i_adc]);
    num_codec_interrupt_C++;
    write_16bit_unsigned_to_RISC(0xC00D,num_codec_interrupt_C);
	break;

	case 0x000D:
	num_codec_interrupt_D++;
	//write_16bit_unsigned_to_RISC(0xC00E,num_codec_interrupt_D);
	break;

	case 0x000E:
	num_codec_interrupt_E++;
	//write_16bit_unsigned_to_RISC(0xC00F,num_codec_interrupt_E);
	break;

    case 0x000F:
	num_codec_interrupt_F++;
	in_enc_sample_buffer_2[i_adc]=read_16bit_signed_mem(ADCREG);
	write_16bit_signed_mem(DACREG,in_enc_sample_buffer_2[i_adc]);
	write_16bit_unsigned_to_RISC(0xC010,num_codec_interrupt_F);
	write_16bit_unsigned_mem(IRQFLAG,0x0003);
	break;


    default:
    //write_16bit_unsigned_to_RISC(0xC000,all_num_codec_interrupt);
    //all_num_codec_interrupt++; 
	break;
	}
#endif 

//write_16bit_unsigned_mem(IRQFLAG,0x0003); //Нужно ли это ?   
//printf("out_irq=%d,=%x\n\r",out_irq,out_irq);

/*Работающий вариант простая тестовая проверка вход на выход */    
//При i_adc =320 мы слышим щелчки значит не успеваем.
//работаем при i_adc =16 мы слышим нормально.
//16 отсчётов АудиоКодека G.722 (не очень хорошо слышим) 
//#if 0
    //В FIFO АЦП есть один отсчёт для чтения   
    if(out_irq & 0x0004)
	{  
      in_enc_sample_buffer_0[i_adc++] = read_16bit_signed_mem(ADCREG);
      if(i_adc==80){i_adc=0;}
     // in_enc_sample_buffer_2[i_adc]=read_16bit_signed_mem(ADCREG);
     // num_codec_interrupt_4++;
    }
    //ЦАП пока не рассматриваем 
    //В FIFO ЦАП одно свободное место для записи
    if(out_irq & 0x0008)
	{
            
       write_16bit_signed_mem(DACREG,out_dec[i_dac++]);
	   if(i_dac==80){i_dac=0;}
       // write_16bit_signed_mem(DACREG,in_enc_sample_buffer_2[i_adc]);
    // num_codec_interrupt_5++;
	}
    

    if(out_irq & 0x0001)
	{
     write_16bit_unsigned_mem(IRQFLAG,0x0001);
    // write_16bit_unsigned_to_RISC(0xC010,num_codec_interrupt_F); 
	}

    if(out_irq & 0x0002)
	{
     write_16bit_unsigned_mem(IRQFLAG,0x0002);
	 //write_16bit_unsigned_to_RISC(0xC00F,num_codec_interrupt_E);
	}

//write_16bit_unsigned_mem(IRQFLAG,0x0003); //Нужно ли это ?
//#endif    

}//END Audio_Codec_Interrupt
