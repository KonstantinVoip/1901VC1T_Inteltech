//******************************************************************************
// @Module        unCP_MemoryTest
// @Filename      unCP_MemoryTest.cpp
// @Project       MB5
//------------------------------------------------------------------------------
// @Controller    TMS320C6416
//
// @Description   Модуль функций тестов памяти Чего
//------------------------------------------------------------------------------

//******************************************************************************
#include <os_syscall.h>
#include <drv_dbgout.h>
#include <rts.h>
#include <tpo.h>

#include "unCP_MemoryTest.h"




/* Функция записи числа в память */
void WriteMemoryNumber(uint32 uniAbsoluteMemoryAddress,uint32 usiDataWriteMemory,uint32 len);

/* Функция чтения числа из памяти */
uint32 usiReadMemoryNumber(uint32 uniAbsoluteMemoryAddress, uint32 len);

/* Функция тестирования ячейки памяти 
   Возвращаемый функцией результат:
   0 - ошибка тестирования;
   1 - положительный результата тестирования */
uint32 uniMemoryCellTest(uint32 uniMemoryAddress, uint32 *uniPtrErrorsPositions, uint32 Width_Bus);

/* Функция тестирования шины адреса памяти
   Возвращаемый функцией результат:
   0 - ошибка тестирования;
   1 - положительный результата тестирования */
uint32 uniMemoryBusAddressTest(uint32 uniStartMemoryAddress, uint32 uniMemoryLength, uint32 *uniPtrErrorAddress);

/* Функция тестирования памяти
   Возвращаемый функцией результат:
   0 - положительный результата тестирования;
   1 - ошибка тестирования шины данных памяти;
   2 - ошибка тестирования шины адреса памяти;
   3 - ошибка тестирования памяти */
uint32 uniMemoryTest(uint32 uniStartMemoryAddress, uint32 uniMemoryLength, uint32 *uniPtrErrorsPositions, uint32 *uniPtrErrorAddress, uint32 Width_Bus);

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
void WriteMemoryNumber
                             (
                               /* Абсолютный адрес памяти */
                               uint32 uniAbsoluteMemoryAddress,
                               /* Данные записываемые в память */
                               uint32 usiDataWriteMemory,
							   uint32 len
                             )
{ /* Функция записи числа в память */
  /* Запись данных в память по абсолютному адресу */

memcpy((void*)(uniAbsoluteMemoryAddress), &usiDataWriteMemory, len);

//  *(uint32*)(uniAbsoluteMemoryAddress) = usiDataWriteMemory;



} /* Функция записи числа в память */

//******************************************************************************
//                         Функция чтения числа
//                              из памяти
//******************************************************************************
uint32 usiReadMemoryNumber
                                       (
                                         /* Абсолютный адрес памяти */
                                         uint32 uniAbsoluteMemoryAddress,
										 uint32 len

                                       )
{ /* Функция чтения числа из памяти */
  /* Чтение данных из из памяти */
	uint32 uniDataReadMemory = 0;

if(uniAbsoluteMemoryAddress == 0x68080000)
{
uniAbsoluteMemoryAddress++;
uniAbsoluteMemoryAddress--;
uniAbsoluteMemoryAddress==uniAbsoluteMemoryAddress;
}

	memcpy( &uniDataReadMemory, (void*)(uniAbsoluteMemoryAddress), len);

//  uniDataReadMemory = (*(uint32*)(uniAbsoluteMemoryAddress));

  return uniDataReadMemory;
} /* Функция чтения числа из памяти */

//******************************************************************************
//                             Функция тестирования 
//                                ячейки памяти 
//******************************************************************************
uint32 uniMemoryCellTest
                                     (
                                       /* Адрес памяти */
                                       uint32 uniMemoryAddress,
                                       /* Разряды ошибок записи/чтения */
                                       uint32 *uniPtrErrorsPositions,
									   uint32 Width_Bus
                                     )
{ /* Функция тестирования ячейки памяти */
  /* Номер первого теста */
  const uint32 uniTEST_ONE = 1;
  /* Данные первого теста */
  const uint32 usiTEST_DATA_ONE = 0x00000000;

  /* Номер второго теста */
  const uint32 uniTEST_TWO = 2;
  /* Данные второго теста */
  const uint32 usiTEST_DATA_TWO = 0xFFFFFFFF;

  /* Номер третьего теста */
  const uint32 uniTEST_THREE = 3;
  /* Данные третьего теста */
  const uint32 usiTEST_DATA_THREE = 0x55555555;

  /* Номер четвёртого теста */
  const uint32 uniTEST_FOUR = 4;
  /* Данные четвёртого теста */
  const uint32 usiTEST_DATA_FOUR = 0xAAAAAAAA;

  /* ячейка для сохранения */
  uint32 Save_mem;
  /* Текущий номер теста */
  uint32 uniCurrentTestNumber;
  /* Данные записываемые в память */
  uint32 usiSetMemoryValue;
  /* Получаемое из памяти значение */
  uint32 usiGetMemoryValue;
  /* Результат тестирования */
  uint32 uniTestResult_OK;

  /* Количество разрядов ошибок */
  const uint32 uniQUANTITY_ERRORS_POSITION = Width_Bus;
  /* Текущий индекс разряда ошибок */
  uint32 uniCurrentErrorPositionIndex;
  /* Разряды ошибок записи/чтения */
  uint32 uniErrorsPositions;
  /* Маска ошибки */
  uint32 usiMaskError;
  /* Сохраняемое в памяти значение */
  uint32 usiSaveMemoryValue;
  /* Считанное из памяти значение */
  uint32 usiReadMemoryValue;

  /* Сброс положительного результата тестирования */
  uniTestResult_OK = 0;
  /* Сброс разрядов ошибок */
  uniErrorsPositions = 0;

  uint32 deltaAdrr = Width_Bus / 8;

	uint32 int_old = 0;

	int_old = int_disable();

  //сохранение числа
  Save_mem = usiReadMemoryNumber(uniMemoryAddress, deltaAdrr);

  /* Тестирование записи/чтения данных */
  for (uniCurrentTestNumber = 1;
       uniCurrentTestNumber < uniTEST_FOUR + 1;
       uniCurrentTestNumber++)
    { /* Тестирование записи/чтения данных */
      /* Если выполняется первый тест */
      if (uniCurrentTestNumber == uniTEST_ONE)
        usiSetMemoryValue = usiTEST_DATA_ONE;
      /* Иначе если выполняется второй тест */
      else if (uniCurrentTestNumber == uniTEST_TWO)
        usiSetMemoryValue = usiTEST_DATA_TWO;
      /* Иначе если выполняется третий тест */
      else if (uniCurrentTestNumber == uniTEST_THREE)
        usiSetMemoryValue = usiTEST_DATA_THREE;
      /* Иначе если выполняется четвёртый тест */
      else if (uniCurrentTestNumber == uniTEST_FOUR)
        usiSetMemoryValue = usiTEST_DATA_FOUR;

//      HWI_disable();
      
//      ram_cell = usiReadMemoryNumber(uniMemoryAddress);//Сохраняем ячейку;

      /* Запись числа в память */
      WriteMemoryNumber(uniMemoryAddress,usiSetMemoryValue,deltaAdrr);

if(uniMemoryAddress == 0x60000308)//для usb контроллера delay
{
uint32 o = 0x100;
while(o--);
}
      /* Чтение числа из памяти */
      usiGetMemoryValue = usiReadMemoryNumber(uniMemoryAddress, deltaAdrr);

//      WriteMemoryNumber(uniMemoryAddress,ram_cell);//Восстанавливаем ячейку;

//      HWI_enable();

      /* Если не совпадают записанные и считанные данных */
      if (memcmp(&usiSetMemoryValue, &usiGetMemoryValue, deltaAdrr))
        { /* Не совпадают записанные и считанные данных */
          /* Поиск разрядов с ошибками */
          for (uniCurrentErrorPositionIndex = 0;
               uniCurrentErrorPositionIndex < uniQUANTITY_ERRORS_POSITION;
               uniCurrentErrorPositionIndex++)
            { /* Поиск разрядов с ошибками */
              /* Маска ошибки */
              usiMaskError = (uint32)(1 << uniCurrentErrorPositionIndex);
              /* Маскирование сохраняемого в памяти значения */
              usiSaveMemoryValue = usiSetMemoryValue & usiMaskError;
              /* Маскирование считанного из памяти значения */
              usiReadMemoryValue = usiGetMemoryValue & usiMaskError;
              /* Если не совпадает записанный и считанный разряд данных, то
                 установка разряда ошибки */
              if (usiSaveMemoryValue != usiReadMemoryValue)
                uniErrorsPositions = uniErrorsPositions | usiMaskError;
            } /* Поиск разрядов с ошибками */
          
          /* Сброс положительного результата тестирования */
          uniTestResult_OK = 0;
          break;
        } /* Не совпадают записанные и считанные данных */

      /* Иначе установка положительного результата тестирования */
      else uniTestResult_OK = 1;
    } /* Тестирование записи/чтения данных */

  /* Возврат функцией разрядов с ошибками записи/чтения */
  *uniPtrErrorsPositions = uniErrorsPositions;
  /* Возврат функцией результата тестирования */

//востановление ячейки
  WriteMemoryNumber(uniMemoryAddress, Save_mem, deltaAdrr);

	int_enable(int_old);	

  return uniTestResult_OK;
} /* Функция тестирования ячейки памяти */

//******************************************************************************
//                             Функция тестирования 
//                              шины адреса памяти 
//******************************************************************************
uint32 uniMemoryBusAddressTest
                                           (
                                             /* Начальный адрес памяти */
                                             uint32 uniStartMemoryAddress,
                                             /* Длина памяти */
                                             uint32 uniMemoryLength,
                                             /* Адрес ошибки записи/чтения */
                                             uint32 *uniPtrErrorAddress,
											 uint32 Width_Bus
                                           )
{ /* Функция тестирования шины адреса памяти */
  /* Текущий индекс памяти */
  uint32 uniCurrentMemoryIndex;
  /* Данные записываемые в память */
  uint32 usiSetMemoryValue;
  /* Получаемое из памяти значение */
  uint32 usiGetMemoryValue;
  /* Адрес ошибки записи/чтения */
  uint32 uniErrorAddress;
  /* Результат тестирования */
  uint32 uniTestResult_OK;

  /* Сброс положительного результата тестирования */
  uniTestResult_OK = 0;

  uint32 deltaAdrr = Width_Bus / 8;

  uint32 ram_cell = 0;
  uint32 int_old = 0;

  /* Тестирование шины адреса */
  for (uniCurrentMemoryIndex = 0;
       uniCurrentMemoryIndex < uniMemoryLength;
       uniCurrentMemoryIndex += deltaAdrr)
    { /* Тестирование шины адреса */
      /* Данные записываемые в память */
      usiSetMemoryValue = (uint32)uniCurrentMemoryIndex;
      /* Запись числа в память */
//      HWI_disable();

//      ram_cell = usiReadMemoryNumber(uniStartMemoryAddress + 2*uniCurrentMemoryIndex);//Сохраняем ячейку;
	int_old = int_disable();

    ram_cell = usiReadMemoryNumber(uniStartMemoryAddress + uniCurrentMemoryIndex, deltaAdrr);//Сохраняем ячейку;

      WriteMemoryNumber(uniStartMemoryAddress + uniCurrentMemoryIndex,usiSetMemoryValue, deltaAdrr);
      /* Чтение числа из памяти */
      usiGetMemoryValue = usiReadMemoryNumber(uniStartMemoryAddress + uniCurrentMemoryIndex, deltaAdrr);
//      WriteMemoryNumber(uniStartMemoryAddress + 2*uniCurrentMemoryIndex,ram_cell);
//	  HWI_enable();
      WriteMemoryNumber(uniStartMemoryAddress + uniCurrentMemoryIndex, ram_cell, deltaAdrr);
	  int_enable(int_old);	

      /* Если не совпадают записанные и считанные данных */
      if (memcmp(&usiSetMemoryValue, &usiGetMemoryValue, deltaAdrr))
        { /* Не совпадают записанные и считанные данных */
          /* Сохранение адреса ошибки записи/чтения */
          uniErrorAddress = uniCurrentMemoryIndex;
          /* Сброс положительного результата тестирования */
          uniTestResult_OK = 0;
          break;
        } /* Не совпадают записанные и считанные данных */

      /* Иначе установка положительного результата тестирования */
      else uniTestResult_OK = 1;
    } /* Тестирование шины адреса */

  /* Возврат функцией адреса ошибки записи/чтения */
  *uniPtrErrorAddress = uniErrorAddress;
  /* Возврат функцией результата тестирования */
  return uniTestResult_OK;
} /* Функция тестирования шины адреса памяти */

//******************************************************************************
//                                Функция  
//                          тестирования памяти 
//******************************************************************************
uint32 uniMemoryTest
                                 (
                                   /* Начальный адрес памяти */
                                   uint32 uniStartMemoryAddress,
                                   /* Длина памяти */
                                   uint32 uniMemoryLength,
                                   /* Разряды ошибок записи/чтения */
                                   uint32 *uniPtrErrorsPositions,
                                   /* Адрес ошибки записи/чтения */
                                   uint32 *uniPtrErrorAddress,
								   uint32 Width_Bus
                                 )
{ /* Функция тестирования памяти */
  /* Разряды ошибок записи/чтения */
  uint32 uniErrorsPosition;
  /* Адрес ошибки записи/чтения */
  uint32 uniErrorAddress;
  /* Текущий индекс памяти */
  uint32 uniCurrentMemoryIndex;

  /* Результат тестирования шины данных памяти */
  uint32 uniTestDataBusResult_OK;
  /* Результат тестирования шины адреса памяти */
  uint32 uniTestAddressBusResult_OK;
  /* Результат тестирования памяти */
  uint32 uniTestMemoryResult_OK;
  /* Возвращаемый функцией результат тестирования */
  uint32 uniTestResultReturn;

  uint32 deltaAdrr = Width_Bus / 8;

  /* Сброс положительного результата тестирования шины данных памяти */
  uniTestDataBusResult_OK = 0;
  /* Сброс положительного результата тестирования шины адреса памяти */
  uniTestAddressBusResult_OK = 0;
  /* Сброс положительного результата тестирования памяти */
  uniTestMemoryResult_OK = 0;

  /* Сброс разрядов ошибок записи/чтения */
  uniErrorsPosition = 0;
  /* Сброс адреса ошибки записи/чтения */
  uniErrorAddress = 0;

  /* Тестирование шины данных памяти */
  uniTestDataBusResult_OK = uniMemoryCellTest
                                            (
                                              /* Адрес памяти */
                                              uniStartMemoryAddress,
                                              /* Разряды ошибок записи/чтения */
                                              & uniErrorsPosition,
											  Width_Bus
                                            );
  /* Если выполнен тест шины данных памяти */
  if(uniTestDataBusResult_OK)
    { /* Выполнен тест шины данных памяти */
      /* Тестирование шины адреса памяти */
      uniTestAddressBusResult_OK = uniMemoryBusAddressTest
                                              (
                                                /* Начальный адрес памяти */
                                                uniStartMemoryAddress,
                                                /* Длина памяти */
                                                uniMemoryLength,
                                                /* Адрес ошибки записи/чтения */
                                                & uniErrorAddress,
												Width_Bus
                                              );
    } /* Выполнен тест шины данных памяти */

  /* Если выполнен тест шины адреса памяти */
  if(uniTestAddressBusResult_OK)
    { /* Выполнен тест шины адреса памяти */
      /* Тестирование памяти */
      for (uniCurrentMemoryIndex = 0;
           uniCurrentMemoryIndex < uniMemoryLength;
           uniCurrentMemoryIndex++)
        { /* Тестирование памяти */
          /* Тестирование ячейки памяти */
          uniTestMemoryResult_OK = uniMemoryCellTest
                                (
                                  /* Адрес памяти */
                                  uniStartMemoryAddress + deltaAdrr * uniCurrentMemoryIndex,
                                  /* Разряды ошибок записи/чтения */
                                  & uniErrorsPosition,
								  Width_Bus
                                );
          /* Если ошибка тестирования, то окончание теста */
          if(uniTestMemoryResult_OK == 0)
            break;
        } /* Тестирование памяти */
    } /* Выполнен тест шины адреса памяти */

  /* Если не прошло тестирование шины данных памяти */
  if(uniTestDataBusResult_OK == 0)
    { /* Не прошло тестирование шины данных памяти */
      /* Разряды ошибок записи/чтения памяти */
      *uniPtrErrorsPositions = uniErrorsPosition;
      /* Адрес ошибки записи/чтения памяти */
      *uniPtrErrorAddress = 0;
      /* Возвращаемый функцией результат теста */
      uniTestResultReturn = TEST_DATA_BUS_ERROR;
    } /* Не прошло тестирование шины данных памяти */
  /* Иначе если не прошло тестирование шины адреса памяти */
  else if(uniTestAddressBusResult_OK == 0)
    { /* Не прошло тестирование шины адреса памяти */
      /* Разряды ошибок записи/чтения памяти */
      *uniPtrErrorsPositions = 0;
      /* Адрес ошибки записи/чтения памяти */
      *uniPtrErrorAddress = uniErrorAddress;
      /* Возвращаемый функцией результат теста */
      uniTestResultReturn = TEST_ADDRESS_BUS_ERROR;
    } /* Не прошло тестирование шины адреса памяти */
  /* Иначе если не прошло тестирование памяти */
  else if(uniTestMemoryResult_OK == 0)
    { /* Не прошло тестирование шины памяти */
      /* Разряды ошибок записи/чтения памяти */
      *uniPtrErrorsPositions = uniErrorsPosition;
      /* Адрес ошибки записи/чтения памяти */
      *uniPtrErrorAddress = 0;
      /* Возвращаемый функцией результат теста */
      uniTestResultReturn = TEST_MEMORY_ERROR;
    } /* Не прошло тестирование шины памяти */
  /* Иначе прошло тестирование памяти */
  else 
    { /* Прошло тестирование памяти */
      /* Разряды ошибок записи/чтения памяти */
      *uniPtrErrorsPositions = 0;
      /* Адрес ошибки записи/чтения памяти */
      *uniPtrErrorAddress = 0;
      /* Возвращаемый функцией результат теста */
      uniTestResultReturn = TEST_RESULT_OK;
    } /* Прошло тестирование памяти */

  /* Возврат функцией результата тестирования */
  return uniTestResultReturn;
} /* Функция тестирования памяти */

//******************************************************************************
//                           Функция тестирования ОЗУ 
//******************************************************************************
uint32 uniTestSDRAM(uint32 *uniPtrErrorsPositions,uint32 *uniPtrErrorAddress)
{ 

  /* ОЗУ - CE0 EMIFA */
  const uint32 uniRAM_ADDRESS = 0x80000000;
  /* Объём – 8 Мбайт, oрганизация – 2M х 32,
     адресация – напрямую 22 разряа адреса с процессорной шины EMIFA, шина
     данных – 1/2 шины данных EMIFA */
  const uint32 uniRAM_LENGTH = 0x800000;

  uint32 Width_Bus = 32;

  /* Результат тестирования */
  uint32 uniTestResult_OK;
  /* Разряды ошибок записи/чтения */
  uint32 uniErrorsPositions;
  /* Адрес ошибки записи/чтения */
  uint32 uniErrorAddress;

  /* Тестирование быстрого статического ОЗУ */
  uniTestResult_OK = uniMemoryTest
                                  (
                                    /* Начальный адрес памяти */
                                    uniRAM_ADDRESS,
                                    /* Длина памяти */
                                    uniRAM_LENGTH,
                                    /* Разряды ошибок записи/чтения */
                                    & uniErrorsPositions,
                                    /* Адрес ошибки записи/чтения */
                                    & uniErrorAddress,
									Width_Bus
                                  );

  /* Возврат функцией разрядов ошибок записи/чтения */
  *uniPtrErrorsPositions = uniErrorsPositions;
  /* Возврат функцией адреса ошибки записи/чтения */
  *uniPtrErrorAddress = uniErrorAddress;
  /* Возврат функцией результат тестирования */
  return uniTestResult_OK;
} /* Функция тестирования быстрого статического ОЗУ */


uint32 uniTestNVRAM(uint32 *uniPtrErrorsPositions,uint32 *uniPtrErrorAddress)
{ 

  /* Энергонезависимое ОЗУ - CE2 EMIFB */
  const uint32 uniRAM_ADDRESS = 0x68000000;
  /* Объём – 1 Мбайт, oрганизация – 512K х 16,
     адресация – напрямую 20 разрядов адреса с процессорной шины EMIFB, шина
     данных – полная шина данных EMIFB */
  const uint32 uniRAM_LENGTH = 0x100000;

  uint32 Width_Bus = 16;

  /* Результат тестирования */
  uint32 uniTestResult_OK;
  /* Разряды ошибок записи/чтения */
  uint32 uniErrorsPositions;
  /* Адрес ошибки записи/чтения */
  uint32 uniErrorAddress;

  /* Тестирование быстрого статического ОЗУ */
  uniTestResult_OK = uniMemoryTest
                                  (
                                    /* Начальный адрес памяти */
                                    uniRAM_ADDRESS,
                                    /* Длина памяти */
                                    uniRAM_LENGTH,
                                    /* Разряды ошибок записи/чтения */
                                    & uniErrorsPositions,
                                    /* Адрес ошибки записи/чтения */
                                    & uniErrorAddress,
									Width_Bus
								   );

  /* Возврат функцией разрядов ошибок записи/чтения */
  *uniPtrErrorsPositions = uniErrorsPositions;
  /* Возврат функцией адреса ошибки записи/чтения */
  *uniPtrErrorAddress = uniErrorAddress;
  /* Возврат функцией результат тестирования */
  return uniTestResult_OK;
} /* Функция тестирования быстрого статического ОЗУ */
