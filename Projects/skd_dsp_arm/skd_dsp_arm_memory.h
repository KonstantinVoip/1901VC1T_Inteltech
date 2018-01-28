/**********************************************************************************************************************
*                                        (c) COPYRIGHT by PAO Inteltech.                                             *
*                                               All rights reserved.                                                  *
***********************************************************************************************************************
* Module      : skd_dsp_arm_memory
* Description : Работа с Памятью DSP ядра 1901ВЦ1Т
* Author      : Konstantin Shiluaev
******************************************************************************
******************************************************************************
* Module's Description Record:
* ============================
* $State: Debug$
* $Revision: 0.0.0 $
* $Date: 2015/03/02 10:40:51 $
******************************************************************************/
#ifndef SKD_DSP_ARM_MEMORY_H
#define SKD_DSP_ARM_MEMORY_H

/*Типы Данных DSP Ядра 1901ВЦ1Т*/
/*signed short      16 bits 2s complement 		 -32 768 до 32 767
* unsigned short    16 bits 2s complement		    0    до 65 535
*
* signed long       32 bits 2s complement    -2 147 483 648  до  2 147 483 647
* unsigned long     32 bits Binary 					0        до  4 294 967 295
*
* double 			64 bits IEEE 32-bit 	1.175 494e-38    до  3.40 282 346e+38 
*/


/* Пишу в DSP 32 бита      
*  [адрес] 0xC000 [Значение]  
*                 11|22 | 33|44 
*
   вижу в  RISC   33|44 | 11|22 
*/



/*****************Работа с 16 Битными Данными ***********/
////////////////////////////////от -32 768 до 32 767//////////////////////////
/*******************************************************************************
* Function Name  : signed short read_2bait_memory(const signed short memory_addr)
* Description    : Функция Чтения Памяти 16 бит со знаком = 2 байта от -32 768 до 32 767
* input  value   : адрес памяти должен быть только положительным :  от 0x0000 до 0xFFFF    
*******************************************************************************/
static inline signed short read_16bit_signed_mem(const unsigned short dsp_mem_addr)
{
   return  *(signed short*)(dsp_mem_addr);
}
/*******************************************************************************
* Function Name  : void write_2bait_memory(const signed short memaddr,c onst signed short mem_val)
* Description    : Функция Записи в Память 16 бит = 2 байта от -32 768 до 32 767
* input  value   : dsp_mem_addr -> адрес памяти должен быть только положительным :  от 0x0000 до 0xFFFF
*******************************************************************************/
static inline void write_16bit_signed_mem(const unsigned short dsp_mem_addr,const signed short mem_val)
{
 unsigned short  *dst;
 signed short    *src;
 
 dst = (unsigned short*)dsp_mem_addr;
 src = ((signed short*)&mem_val);
 * dst  = * src;
}


////////////////////////////////от 0 до 65535//////////////////////////
/*Для работы с регистрами процессора не может быть отрицательного значения */
/*******************************************************************************
* Function Name  : signed short read_2bait_memory(const signed short memory_addr)
* Description    : Функция Чтения Памяти 16 бит со знаком = 2 байта от 0 до 65535
* input  value   : адрес памяти должен быть только положительным :  от 0x0000 до 0xFFFF    
*******************************************************************************/
static inline unsigned short read_16bit_unsigned_mem(const unsigned short dsp_mem_addr)
{
   return  *(unsigned short*)(dsp_mem_addr);
}
/*******************************************************************************
* Function Name  : void write_2bait_memory(const signed short memaddr,c onst signed short mem_val)
* Description    : Функция Записи в Память 16 бит = 2 байта от 0 до 65535
* input  value   : dsp_mem_addr -> адрес памяти должен быть только положительным :  от 0x0000 до 0xFFFF
*******************************************************************************/
static inline void write_16bit_unsigned_mem(const unsigned short dsp_mem_addr,const unsigned short mem_val)
{
 unsigned short  *dst;
 unsigned short    *src;
 
 dst = (unsigned short*)dsp_mem_addr;
 src = ((unsigned short*)&mem_val);
 * dst  = * src;
}

/*********************Работа с 32 Битными Данными **************/
/*******************************************************************************
* Function Name  : static inline signed long read_32bit_siged_mem(const unsigned short dsp_mem_addr)
* Description    : Функция Чтения Памяти 32 бит со знаком = 4 байта от -2 147 483 648  до  2 147 483 647
* input  value   : dsp_mem_addr -> адрес памяти должен быть только положительным :  от 0x0000 до 0xFFFF
*******************************************************************************/
static inline signed long read_32bit_siged_mem(const unsigned short dsp_mem_addr)
{
   return  *(signed long*)(dsp_mem_addr);
}

/*******************************************************************************
* Function Name  : void write_2bait_memory(const signed short memaddr,c onst signed short mem_val)
* Description    : Функция Записи в Память 32 бит со знаком = 4 байта от -2 147 483 648  до  2 147 483 647
* input  value   : dsp_mem_addr -> адрес памяти должен быть только положительным :  от 0x0000 до 0xFFFF
*******************************************************************************/
static inline void write_32bit_signed_mem(const unsigned short dsp_mem_addr,const signed long mem_val)
{
 //Знаковый только Плюс там пишем
 /*Нужно доделать фунция записи 32 бит пока работает только 16 бит 
  не могу внести 32 битное значение получаеться только 16 бит*/
 signed short low_word;
 signed short high_word;
 signed long  l_mem_val;
 
  //Нужно разделить на два шестнадцати разрядных и записать друг за другом
 unsigned short    *dst_high_value;
 unsigned short    *dst_low_value;
 
 unsigned short    *src_high_value;
 unsigned short    *src_low_value;


 low_word =(signed short)mem_val;
 l_mem_val=(mem_val&&0xFFFF0000)>>16;
 high_word=(signed short)l_mem_val;
  
 //Пишем старшее слово 16 бит high_word
 dst_high_value = (unsigned short*)dsp_mem_addr;
 src_high_value = ((unsigned short*)&high_word);
 * dst_high_value  = * src_high_value;

//Пишем младшее слово 16 бит  low_word
 dst_low_value = (unsigned short*)dsp_mem_addr+1;
 src_low_value = ((unsigned short*)&low_word);
 * dst_low_value  = * src_low_value;

 

}
/*************************************************************************/
/*************************************************************************/
/*************************************************************************/
/*Функции работы с памятью для Межядерного взаимодействия к от DSP к RISC*/
/*************************************************************************/
/*************************************************************************/
/*************************************************************************/
static inline void write_16bit_unsigned_to_RISC(const unsigned short dsp_mem_addr,const unsigned short mem_val)
{
 unsigned short    *dst;
 unsigned short    *src;
 
 dst = (unsigned short*)dsp_mem_addr;
 src = ((unsigned short*)&mem_val);
 * dst  = * src;
}



/*******************************************************************************
* Function Name  : void write_2bait_memory(const signed short memaddr,c onst signed short mem_val)
* Description    : Функция Записи в Память 16 бит = 2 байта от -32 768 до 32 767
* input  value   : dsp_mem_addr -> адрес памяти должен быть только положительным :  от 0x0000 до 0xFFFF
*******************************************************************************/
static inline void write_16bit_signed_to_RISC(const unsigned short dsp_mem_addr,const signed short mem_val)
{
 unsigned short  *dst;
 signed short    *src;
 
 dst = (unsigned short*)dsp_mem_addr;
 src = ((signed short*)&mem_val);
 * dst  = * src;
}



/////////////////////////////////////////////////////////////////////////
static inline void write_32bit_signed_to_RISC(const unsigned short dsp_mem_addr,const signed long mem_val)
{
 //Знаковый только Плюс там пишем
 /*Нужно доделать фунция записи 32 бит пока работает только 16 бит 
  не могу внести 32 битное значение получаеться только 16 бит*/
 signed short low_word;
 signed short high_word;
 signed long  l_mem_val;
 
  //Нужно разделить на два шестнадцати разрядных и записать друг за другом
 unsigned short    *dst_high_value;
 unsigned short    *dst_low_value;
 
 unsigned short    *src_high_value;
 unsigned short    *src_low_value;


 low_word =(signed short)mem_val;
 l_mem_val=(mem_val&0xFFFF0000)>>16;
 high_word=(signed short)l_mem_val;
  
 //Для записи в память RISC меняем местами high_word и low_word соответсвенно память
 //куда пишем память меняем местами.

 //Пишем старшее слово 16 бит high_word
 dst_high_value = (unsigned short*)dsp_mem_addr+1;
 src_high_value = ((unsigned short*)&high_word);
 * dst_high_value  = * src_high_value;

//Пишем младшее слово 16 бит  low_word
 dst_low_value = (unsigned short*)dsp_mem_addr;
 src_low_value = ((unsigned short*)&low_word);
 * dst_low_value  = * src_low_value;

}


#endif /* SKD_DSP_ARM_MEMORY_H */
