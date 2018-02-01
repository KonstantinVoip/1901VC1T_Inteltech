/**********************************************************************************************************************
*                                        (c) COPYRIGHT by ZAO RCZI FORT.                                             *
*        ..                                       All rights reserved.                                               *
***********************************************************************************************************************
* Module      : mem_test.cpp
* Description : Функции тестирования памяти какой?
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
//#include <os_syscall.h>
//#include <drv_dbgout.h>
	#include <rts.h>
	#include <tpo.h>
	#include "mem_test.h"


/* Функция тестирования ячейки памяти 
   Возвращаемый функцией результат:
   1 - ошибка тестирования;
   0 - положительный результата тестирования */
uint32 uniMemoryCellTest(uint32 uniMemoryAddress, uint64 *uniPtrErrorsPositions, uint32 Width_Bus);

/* Функция тестирования шины адреса памяти
   Возвращаемый функцией результат:
   1 - ошибка тестирования;
   0 - положительный результата тестирования */
uint32 uniMemoryBusAddressTest(mem_test *param);

/* Функция тестирования памяти
   Возвращаемый функцией результат:
   0 - положительный результата тестирования;
   1 - ошибка тестирования шины данных памяти;
   2 - ошибка тестирования шины адреса памяти;
   3 - ошибка тестирования памяти */
uint32 uniMemoryTest(mem_test *param);

/*   Возвращаемый функцией результат:
   0 - положительный результата тестирования;
   1 - ошибка тестирования шины данных памяти;
   2 - ошибка тестирования шины адреса памяти;
   3 - ошибка тестирования памяти */
uint32 uniTestRAM(uint32 *uniPtrErrorsPositions, uint32 *uniPtrErrorAddress);

//******************************************************************************
//                         Функция записи числа
//                               в память
//******************************************************************************
void WriteMemoryNumber(uint32 uniAbsoluteMemoryAddress, uint32 usiDataWriteMemory, uint32 len)
{ 
	/* Функция записи числа в память */
	/* Запись данных в память по абсолютному адресу */
	memcpy((void*)(uniAbsoluteMemoryAddress), &usiDataWriteMemory, len);
	//  *(uint32*)(uniAbsoluteMemoryAddress) = usiDataWriteMemory;
} /* Функция записи числа в память */



/*****************************************************************************
Syntax:      	    
Remarks: Функция чтения числа из памяти			    
*******************************************************************************/
uint32 usiReadMemoryNumber(
                                         /* Абсолютный адрес памяти */
                                         uint32 uniAbsoluteMemoryAddress,
										 uint32 len

                                       )
{ 
    /* Функция чтения числа из памяти */
    /* Чтение данных из из памяти    */
	uint32 uniDataReadMemory = 0;

	if(uniAbsoluteMemoryAddress == 0x68080000)
	{
		uniAbsoluteMemoryAddress++;
		uniAbsoluteMemoryAddress--;
	//	uniAbsoluteMemoryAddress==uniAbsoluteMemoryAddress;  ?? //skd_ бессмысленно
	}

	memcpy( &uniDataReadMemory, (void*)(uniAbsoluteMemoryAddress), len);
	//uniDataReadMemory = (*(uint32*)(uniAbsoluteMemoryAddress));

  return uniDataReadMemory;
} 

/* Функция чтения числа из памяти */

//******************************************************************************
//                             Функция тестирования 
//                                ячейки памяти 
//******************************************************************************
uint32 uniMemoryCellTest(             /* Адрес памяти */
                                       uint32 uniMemoryAddress,
                                       /* Разряды ошибок записи/чтения */
                                       uint64 *uniPtrErrorsPositions,
									   uint32 Width_Bus)
{ 

  uint64 TEST_DATA[4] = {0, 0xFFFFFFFFFFFFFFFF, 0x5555555555555555, 0xAAAAAAAAAAAAAAAA};
  /* ячейка для сохранения */
  uint64 Save_mem;
  /* Получаемое из памяти значение */
  uint64 GetMemVal;

  uint64 Mask = 0;
  for(int i=0; i<Width_Bus; i++)
  Mask |= 1<<i;

  uint32 deltaAdrr = Width_Bus / 8;

  /* Результат тестирования */
  uint32 TestRes = 0;
  /* Разряды ошибок записи/чтения */
  uint32 uniErrorsPositions = 0;


	uint32 int_old = 0;
	int_old = int_disable();

	//сохранение числа
	memcpy( &Save_mem, (void*)uniMemoryAddress, deltaAdrr);
//  Save_mem = usiReadMemoryNumber(uniMemoryAddress, deltaAdrr);

  /* Тестирование записи/чтения данных */
	for (int i = 0; i < 4; i++)
	{
	    /* Запись числа в память */
		memcpy((void*)uniMemoryAddress, &TEST_DATA[i], deltaAdrr);
	//	WriteMemoryNumber(uniMemoryAddress,usiSetMemoryValue,deltaAdrr);

	/*
	if(uniMemoryAddress == 0x60000308)//для usb контроллера delay потом надо убрать
	{
	uint32 o = 0x100;
	while(o--);
	}
	*/
	    /* Чтение числа из памяти */
		memcpy( &GetMemVal, (void*)uniMemoryAddress, deltaAdrr);
	//  usiGetMemoryValue = usiReadMemoryNumber(uniMemoryAddress, deltaAdrr);

	    /* Если не совпадают записанные и считанные данных */
    	if(memcmp(&TEST_DATA[i], &GetMemVal, deltaAdrr))
	    {
    	 uniErrorsPositions = (TEST_DATA[i] & Mask) ^ (GetMemVal & Mask);
	     TestRes = 1;
    	 break;
	    }
    } /* Тестирование записи/чтения данных */

  /* Возврат функцией разрядов с ошибками записи/чтения */
  *uniPtrErrorsPositions = uniErrorsPositions;
  /* Возврат функцией результата тестирования */

//востановление ячейки
  memcpy((void*)uniMemoryAddress, &Save_mem, deltaAdrr);
//  WriteMemoryNumber(uniMemoryAddress, Save_mem, deltaAdrr);

  int_enable(int_old);	

  return TestRes;
} /* Функция тестирования ячейки памяти */

//******************************************************************************
//                             Функция тестирования 
//                              шины адреса памяти 
//******************************************************************************
uint32 uniMemoryBusAddressTest(mem_test *param)
{ /* Функция тестирования шины адреса памяти */

  uint32 i;
  /* Получаемое из памяти значение */
  uint64 rd_data = 0;
  uint64 wr_data = 0;
  /* Результат тестирования */
  uint32 TestResult = 0;

  uint32 deltaAdrr = param->Width_Bus / 8;

  uint64 ram_cell[32+1];
  memset(ram_cell, 0, sizeof(ram_cell));

  uint64 Mask = 0;
  for(int i=0; i < param->Width_Bus; i++)
  Mask |= 1 << i;

  uint32 int_old = 0;

  int_old = int_disable();

  // Тестирование шины адреса 
  //Сохраняем ячейки памяти x0, (x1, x2, x4, x8,) x10, x20;
  for (i = 0; ((deltaAdrr<<i) < param->length); i++)
		memcpy( &ram_cell[i+1], (void*)(param->addr + (deltaAdrr << i)), deltaAdrr);
 	    memcpy( &ram_cell[0], (void*)param->addr, deltaAdrr);
	   //	ram_cell[i+1] = usiReadMemoryNumber(param->addr+(deltaAdrr<<i), deltaAdrr);//Сохраняем ячейку;
      //	ram_cell[0] = usiReadMemoryNumber(param->addr, deltaAdrr);

  memset((void*)param->addr, 0, deltaAdrr);
//	WriteMemoryNumber(param->addr, 0, deltaAdrr);
  for (i = 0; ((deltaAdrr<<i) < param->length); i++)
  {
	wr_data = deltaAdrr+i;
	memcpy((void*)(param->addr + (deltaAdrr << i)), &wr_data, deltaAdrr);
//	WriteMemoryNumber(param->addr + (deltaAdrr<<i), deltaAdrr+i, deltaAdrr);
  }

  for (i = 0; ((deltaAdrr<<i) < param->length); i++)
  {
	memcpy( &rd_data, (void*)(param->addr + (deltaAdrr << i)), deltaAdrr);
//	rd_data = usiReadMemoryNumber(param->addr+(deltaAdrr<<i), deltaAdrr);
	if(rd_data != (deltaAdrr+i))
	{
	 param->ErrAddr = (deltaAdrr << (rd_data - deltaAdrr));
//	 param->ErrAddr = 1<<i;
     TestResult = 1;
	 break;
	}
	 
  }
  memcpy( &rd_data, (void*)param->addr, deltaAdrr);
//rd_data = usiReadMemoryNumber(param->addr, deltaAdrr);
  if(rd_data != 0)
  {
	param->ErrAddr = (deltaAdrr << (rd_data - deltaAdrr));
    TestResult = 1;
  }

  for (i = 0; ((deltaAdrr<<i) < param->length); i++)
    memcpy((void*)(param->addr + (deltaAdrr << i)), &ram_cell[i+1], deltaAdrr);
//	WriteMemoryNumber(param->addr+(deltaAdrr<<i), ram_cell[i+1], deltaAdrr);
    memcpy((void*)param->addr, &ram_cell[0], deltaAdrr);
//	WriteMemoryNumber(param->addr, ram_cell[0], deltaAdrr);


  int_enable(int_old);	

  return TestResult;
} /* Функция тестирования шины адреса памяти */

//******************************************************************************
//                                Функция  
//                          тестирования памяти 
//******************************************************************************
uint32 uniMemoryTest(mem_test *param)

{ /* Функция тестирования памяти */
  uint32 i;

  /* Результат тестирования шины данных памяти */
  uint32 DataBusResult=0;
  /* Результат тестирования шины адреса памяти */
  uint32 AddressBusResult=0;
  /* Результат тестирования памяти */
  uint32 TestMemoryResult=0;
  /* Возвращаемый функцией результат тестирования */
  uint32 TestResult = 0;

  uint32 deltaAdrr = param->Width_Bus / 8;

  /* Тестирование шины данных памяти */
  DataBusResult = uniMemoryCellTest(param->addr, & param->ErrPosition, param->Width_Bus);

  /* Если выполнен тест шины данных памяти */
  if(!DataBusResult)
    /* Тестирование шины адреса памяти */
    AddressBusResult = uniMemoryBusAddressTest(param);

  /* Если выполнен тест шины адреса памяти */
  if(!AddressBusResult)
    { /* Тестирование памяти */
      for (i = 0; i < param->length; i++)
      {
      TestMemoryResult = uniMemoryCellTest(param->addr + deltaAdrr * i, & param->ErrPosition, param->Width_Bus);
          /* Если ошибка тестирования, то окончание теста */
          if(TestMemoryResult == 1)
			{
			param->ErrAddr = deltaAdrr * i;
            break;
			}
      } 
    }

  /* Если не прошло тестирование шины данных памяти */
  if(DataBusResult == 1)
    { 
      /* Адрес ошибки записи/чтения памяти */
      param->ErrAddr = 0;
      /* Возвращаемый функцией результат теста */
      TestResult = TEST_DATA_BUS_ERROR;
    }
  /* Иначе если не прошло тестирование шины адреса памяти */
  else if(AddressBusResult == 1)
    { 
      /* Разряды ошибок записи/чтения памяти */
      param->ErrPosition = 0;
      /* Возвращаемый функцией результат теста */
      TestResult = TEST_ADDRESS_BUS_ERROR;
    }
  /* Иначе если не прошло тестирование памяти */
  else 
  if(TestMemoryResult == 1)
      TestResult = TEST_MEMORY_ERROR;
  else 
    { /* Прошло тестирование памяти */
      /* Разряды ошибок записи/чтения памяти */
      param->ErrPosition = 0;
      /* Адрес ошибки записи/чтения памяти */
      param->ErrAddr = 0;
      /* Возвращаемый функцией результат теста */
      TestResult = TEST_RESULT_OK;
    } /* Прошло тестирование памяти */
  return TestResult;
}
//******************************************************************************
//                           Функция тестирования ОЗУ ЦП
//******************************************************************************
uint32 uniTestSDRAM_CP(uint64 *uniPtrErrorsPositions,uint32 *uniPtrErrorAddress)
{ 

mem_test sd_tst;

sd_tst.addr = 0x80000000;
sd_tst.length = 0x800000;
sd_tst.Width_Bus = 32;
sd_tst.ErrPosition = 0;
sd_tst.ErrAddr = 0;

  /* ОЗУ - CE0 EMIFA */
  /* Объём – 8 Мбайт, oрганизация – 2M х 32,
     адресация – напрямую 22 разряа адреса с процессорной шины EMIFA, шина
     данных – 1/2 шины данных EMIFA */
  /* Результат тестирования */

uint32 uniTestResult_OK;

  /* Тестирование быстрого статического ОЗУ */
uniTestResult_OK = uniMemoryTest(&sd_tst);

  /* Возврат функцией разрядов ошибок записи/чтения */
  *uniPtrErrorsPositions = sd_tst.ErrPosition;
  /* Возврат функцией адреса ошибки записи/чтения */
  *uniPtrErrorAddress = sd_tst.ErrAddr;
  /* Возврат функцией результат тестирования */
  return uniTestResult_OK;
} /* Функция тестирования быстрого статического ОЗУ */


uint32 uniTestNVRAM(uint64 *uniPtrErrorsPositions,uint32 *uniPtrErrorAddress)
{ 

mem_test nv_tst;

nv_tst.addr = 0x68000000;
nv_tst.length = 0x100000;
nv_tst.Width_Bus = 16;
nv_tst.ErrPosition = 0;
nv_tst.ErrAddr = 0;

  /* Энергонезависимое ОЗУ - CE2 EMIFB */
  /* Объём – 1 Мбайт, oрганизация – 512K х 16,
     адресация – напрямую 20 разрядов адреса с процессорной шины EMIFB, шина
     данных – полная шина данных EMIFB */
  /* Результат тестирования */
  uint32 uniTestResult_OK;

  /* Тестирование быстрого статического ОЗУ */
  uniTestResult_OK = uniMemoryTest(&nv_tst);

  /* Возврат функцией разрядов ошибок записи/чтения */
  *uniPtrErrorsPositions = nv_tst.ErrPosition;
  /* Возврат функцией адреса ошибки записи/чтения */
  *uniPtrErrorAddress = nv_tst.ErrAddr;
  /* Возврат функцией результат тестирования */
  return uniTestResult_OK;
} /* Функция тестирования быстрого статического ОЗУ */


//******************************************************************************
//                           Функция тестирования ОЗУ ПП
//******************************************************************************
uint32 uniTestSDRAM_PP(uint64 *uniPtrErrorsPositions,uint32 *uniPtrErrorAddress)
{ 

mem_test sd_tst;

sd_tst.addr = 0x90000000;
sd_tst.length = 0x800000;
sd_tst.Width_Bus = 32;
sd_tst.ErrPosition = 0;
sd_tst.ErrAddr = 0;

  /* ОЗУ - CE0 EMIFA */
  /* Объём – 8 Мбайт, oрганизация – 2M х 32,
     адресация – напрямую 22 разряа адреса с процессорной шины EMIFA, шина
     данных – 1/2 шины данных EMIFA */
  /* Результат тестирования */

uint32 uniTestResult_OK;

  /* Тестирование быстрого статического ОЗУ */
uniTestResult_OK = uniMemoryTest(&sd_tst);

  /* Возврат функцией разрядов ошибок записи/чтения */
  *uniPtrErrorsPositions = sd_tst.ErrPosition;
  /* Возврат функцией адреса ошибки записи/чтения */
  *uniPtrErrorAddress = sd_tst.ErrAddr;
  /* Возврат функцией результат тестирования */
  return uniTestResult_OK;
} /* Функция тестирования быстрого статического ОЗУ */
