/**********************************************************************************************************************
*                                        (c) COPYRIGHT by ZAO RCZI FORT.                                             *
*        ..                                       All rights reserved.                                               *
***********************************************************************************************************************
* Module      : os_start_tpo_main.cpp
* Description : Функция Старта ТПО для всех CPU
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
#include <rts.h>
#include "tpo.h"




/*
extern const uint32 hash_bp[] =
{
  0xE8C30F95, 0x2F656500, 0x11D04E8C, 0xB642F4BF,
  0x845A38F9, 0x00AFE34E, 0xFA9D8C1A, 0xA2F12BD8,
  0x9E78C76D, 0xDD36A2E4, 0x3C271073, 0x59BCB1AB,
  0xC78E79C7, 0x63045626, 0x7B1B9A31, 0x45E9DD52
};
*/

static const uint32 hash_bp[16]=
{
   0xE8C30F95, 0x2F656500, 0x11D04E8C, 0xB642F4BF,
   0x845A38F9, 0x00AFE34E, 0xFA9D8C1A, 0xA2F12BD8,
   0x9E78C76D, 0xDD36A2E4, 0x3C271073, 0x59BCB1AB,
   0xC78E79C7, 0x63045626, 0x7B1B9A31, 0x45E9DD52

};



int tpo_main(void* arg);
int tpo_iface(void* arg);
int tpo_comm(void* arg, char* sys_name);




/**************************************************************************************************
Syntax:    int os_main(void* arg) 	  		
Return Value: Общий Файл Старт os_main ТПО для  [IFACE ,MAIN и COMM Процессоров]
***************************************************************************************************/
int os_main(void* arg)
{
  int error = 0;  
 
   
   //Заглушка для отладки
   /*
   while(true)
   {
    asm(" nop");
   }
   */
 

     
     //core_common\h\os_syscall.h  #define SYSCALL_CRYPTO_GOST_HASH_INIT                   134   
     cry_hash_init(hash_bp);   //неявный вызов через таблицу SYSCALL ОС

    //
	#ifdef IFACE //Интерфейсная плата
	  if( OSE_OK == sys_chkname("iface") )
	    error = tpo_iface(arg);
	#endif    
    //
	#ifdef MAIN  //Центральный Процессор а где Спарка или одинаковое имя у них
	  if( OSE_OK == sys_chkname("main") )
	    error = tpo_main(arg);
	#endif    
    //
	#ifdef COMM  //Коммуникационный процессоры  переменные определены в tpo.h
		if((MIN_NUMBER_COMM < 1)&(NUMBER_COMM_DSP > 0))
		{
		  if( OSE_OK == sys_chkname("comm0") )
		    error = tpo_comm(arg, "comm0");
		}
		if((MIN_NUMBER_COMM < 2)&(NUMBER_COMM_DSP > 1))
		{
		  if( OSE_OK == sys_chkname("comm1") )
		    error = tpo_comm(arg, "comm1");
		}
		if((MIN_NUMBER_COMM < 3)&(NUMBER_COMM_DSP > 2))
		{
			  if( OSE_OK == sys_chkname("comm2") )
		    	error = tpo_comm(arg, "comm2");
		}

		if((MIN_NUMBER_COMM < 4)&(NUMBER_COMM_DSP > 3))
		{
			  if( OSE_OK == sys_chkname("comm3") )
		    	error = tpo_comm(arg, "comm3");
		}
	#endif  //конец процессоров     

return error;
} 

