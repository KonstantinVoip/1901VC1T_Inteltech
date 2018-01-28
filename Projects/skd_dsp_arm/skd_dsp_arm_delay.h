/**********************************************************************************************************************
*                                        (c) COPYRIGHT by PAO Inteltech.                                             *
*                                               All rights reserved.                                                  *
***********************************************************************************************************************
* Module      : skd_dsp_arm_delay
* Description : Работа с Аппаратным Таймером и задержками  1901ВЦ1Т
* Author      : Konstantin Shiluaev
******************************************************************************
******************************************************************************
* Module's Description Record:
* ============================
* $State: Debug$
* $Revision: 0.0.0 $
* $Date: 2015/03/02 10:40:51 $
******************************************************************************/
#ifndef SKD_DSP_ARM_DELAY_H
#define SKD_DSP_ARM_DELAY_H

#include "stdio.h"

#include "skd_dsp_arm_memory.h"

extern unsigned long volatile dsp_TimerCounter;

/*Timer Reg*/
#define  	TIM                     0x0038
#define  	PRD                     0x0039
#define  	TCR                     0x003A

    /*Для того чтобы у нас считали одинаково таймеры для DSP и RISC количество процессорных циклов = 0xFFFF = 65535
    *  0xFFFF = 65535 тиков[процессорных_циклов]  частота_hclk = 24 [Мгц] = 24 000 000 [Гц]
    *  время 1 прерывания = 0.002730625 [c] = 2.730625 [мс] //24 [Мгц]
    *                       0.008191875 [c] = 8.191875 [мс] //8  [Мгц]
    *                       0.000682656 [c] = 0.68265  [мс] //96 [Мгц]
    * 
       время 1 тика       = 				  0.000125 [мс] //8  [Мгц]
    *                                                  [мс] //24 [Мгц]
    *                                                  [мс] //96 [Мгц] 
    *  //Устанаваливаем время прерывания 1[мс] и 1 мкс
    *  Для того чтобы у нас считали одинаково таймеры для DSP и RISC количество процессорных циклов = 0x5DC0 = 24000
    *  частота_hclk = 24 [Мгц] = 24 000 000 [Гц]
    *
    *         время 1 прерывания = 0.001 [c] =    1 [мс] //24 [Мгц]
    *  Для того чтобы у нас считали одинаково таймеры для DSP и RISC количество процессорных циклов = 0x0018 = 24
    *         время 1 прерывания = 0.000001 [c] = 1 [мКс] //24 [Мгц]   */
    
    /*16 разрядный таймер DSP ядра*/
    //Базовые времна которые можем получить с помощью таймера от которого буду работать.
    //для частоты 8  Мгц   1[cек] = ? ticks ,1[мс]    = 0x1F40(8000)  [ticks] , 1[мкс] =0x0008(8) [ticks]
    //для частоты 24 Мгц   1[cек] = ? ticks ,1[мс]    = 0x5DC0(24000) [ticks] , 1[мкс] =0x0018(24)[ticks]
    //для частоты 96 Мгц   1[cек] = ? ticks ,0.5[мс]  = 0xBB80(48000) [ticks] , 1[мкс] =0x0060(96)[ticks]

    //Производные времена.                /*количество повторений  для 1 секунды*/
    //для частоты 8   Мгц      1[сек] =   1 мс *   (1000);
    //для частоты 24  Мгц  =   1[сек] =   1 мс *   (1000);
    //для частоты 96  Мгц  =   1[сек] =   0.5 мс * (2000);
	 
    /* приблизительная формула для подсчёта: время[с] = [Процессорные циклы] /[частоту] */
    /*Тестирование системных Тиков DSP ядра*/
    static const unsigned short DSP_TIMER_TICK_TEST = 1; 
    static const unsigned short DSP_TIMER_8MHz  = 0;
    static const unsigned short DSP_TIMER_24MHZ = 0;  
	static const unsigned short DSP_TIMER_96MHz = 0;  
   	/*Определение Системного Таймера*/ 
	static const unsigned short SYSTIMER_MICROSECOND =0;
	static const unsigned short SYSTIMER_MILLISECOND =1;
	static const unsigned short SYSTIMER_SECOND =     0;
 
/*******************************************************************************
* Function Name  : unsigned short init_dsp_timer()
* Description    : Инициализация таймера DSP процессора.
*******************************************************************************/
unsigned short init_dsp_timer()
{
// static unsigned short PRD_REG_value  = 0x5DC0;//0xFFFF;  //0-65535  //счётчик таймера 0x0000 - 0xFFFF
// static unsigned short TCR_TRRD_value = 0x0020;//0-15     //делитель входной частоты = 0 (ноль)
 
  //Stop the timer by writing a 1 to TSS in TCR.
  write_16bit_unsigned_mem(TCR,0x0010);// STOP TIMER
  
  //Для тестирование производительности количества Тиков
  if(DSP_TIMER_TICK_TEST)
  {
   write_16bit_unsigned_mem(PRD,0xFFFF);// устанавливаем максимальное значение 65535 тиков 
  }

  //Для 8 Мгц
  if(DSP_TIMER_8MHz) 
  { 
       if (SYSTIMER_MICROSECOND)
	   {
       write_16bit_unsigned_mem(PRD,0x0008);// set the PRD reg value
       }

       if(SYSTIMER_MILLISECOND)
	   {
       write_16bit_unsigned_mem(PRD,0x1F40);// set the PRD reg value
	   }

       if(SYSTIMER_SECOND)
	   {
       write_16bit_unsigned_mem(PRD,0x0000);// set the PRD reg value
	   }

  } //END DSP_TIMER_8MHz
 
  //Для 24 Мгц
   if(DSP_TIMER_24MHZ)
   {
         if(SYSTIMER_MICROSECOND)
  		 {
          write_16bit_unsigned_mem(PRD,0x0018);// set the PRD reg value
    	 }

         if(SYSTIMER_MILLISECOND)
	     {
         write_16bit_unsigned_mem(PRD,0x5DC0);// set the PRD reg value
	     }

         if(SYSTIMER_SECOND)
         { 
         write_16bit_unsigned_mem(PRD,0x0000);// set the PRD reg value 
         }
    }//END DSP_TIMER_24MHZ

  //Для 96 Мгц
  if (DSP_TIMER_96MHz) 
  {
        if (SYSTIMER_MICROSECOND)
		{
        write_16bit_unsigned_mem(PRD,0x0060);// set the PRD reg value
	    }

        if (SYSTIMER_MILLISECOND)
		{
        write_16bit_unsigned_mem(PRD,0xBB80);// set the PRD reg value
        }

        if(SYSTIMER_SECOND)
        {
        write_16bit_unsigned_mem(PRD,0x0000);// set the PRD reg value 
	    }
  
  }////END DSP_TIMER_96MHZ
 //Start the timer by reloading TCR to initialize TDDR.
 //write_16bit_unsigned_mem(TCR,TCR_TRRD_value);// START TIMER TSS=0 | TRB =1 |TRD=0x0
   
  return 1;
}
	
	
	
/*******************************************************************************
* Function Name  : void sys_timer_stop()
* Description    : Функция Записи в Память 16 бит = 2 байта от -32 768 до 32 767
*******************************************************************************/
void sys_timer_stop()
{
  write_16bit_unsigned_mem(TCR,0x0010);// STOP TIMER
}	
/*******************************************************************************
* Function Name  : void sys_timer_start()
* Description    : Функция Записи в Память 16 бит = 2 байта от -32 768 до 32 767
*******************************************************************************/	
void sys_timer_start()
{
  write_16bit_unsigned_mem(TCR,0x0020);// START TIMER TSS=0 | TRB =1 |TRD=0x0
}





////////////////////////////////от 0 до 65535//////////////////////////
/*Для работы с регистрами процессора не может быть отрицательного значения */
/*******************************************************************************
* Function Name  : void dsp_sys_timer_start_second(uint8_t second)
* Description    : таймер 0-60  [секунд]
*******************************************************************************/
void dsp_sys_timer_start_second(unsigned short second)
{
    //Стартуем таймер
    dsp_TimerCounter = second;
    write_16bit_unsigned_mem(TCR,0x0020);// START TIMER TSS=0 | TRB =1 |TRD=0x0
} 


/*******************************************************************************
* Function Name  : void dsp_sys_timer_start_millisecond(uint16_t  millisecond)
* Description    : Функция Записи в Память 16 бит = 2 байта от 0 до 65535
*******************************************************************************/
void dsp_sys_timer_start_millisecond(unsigned short  millisecond)
{
     
    dsp_TimerCounter = millisecond;
    //Start the timer by reloading TCR to initialize TDDR.
    write_16bit_unsigned_mem(TCR,0x0020);// START TIMER TSS=0 | TRB =1 |TRD=0x0
    

}

/*******************************************************************************
* Function Name  : void dsp_sys_timer_set_second_delay(uint8_t second)
* Description    : Функция Чтения Памяти 32 бит со знаком = 4 байта от -2 147 483 648  до  2 147 483 647
*******************************************************************************/
void dsp_sys_timer_set_second_delay(unsigned short second)
{



}
/*******************************************************************************
* Function Name  : void dsp_sys_timer_set_millisecond_delay(uint16_t  millisecond)
* Description    : Функция Записи в Память 32 бит со знаком = 4 байта от -2 147 483 648  до  2 147 483 647
*******************************************************************************/
void dsp_sys_timer_set_millisecond_delay(unsigned short  millisecond)
{
	   dsp_sys_timer_start_second(millisecond);
	   while(dsp_TimerCounter)
	   {
	   }
       sys_timer_stop(); 
}

/*******************************************************************************
* Function Name  : void dsp_sys_timer_set_millisecond_delay(uint16_t  millisecond)
* Description    : берём текущее значение тиков из таймера.
*******************************************************************************/
unsigned short get_timer_tick_value()
{
  unsigned short val=0x0000;
  val=read_16bit_unsigned_mem(0x0038);
  
  return val;
}





/////////////////////////////////////////////////////////////////////////
#endif /* SKD_DSP_ARM_DELAY_H */
