//******************************************************************************
// @Module        unCP_MemoryTest
// @Filename      unCP_MemoryTest.cpp
// @Project       MB5
//------------------------------------------------------------------------------
// @Controller    TMS320C6416
//
// @Description   ������ ������� ������ ������ ����
//------------------------------------------------------------------------------

//******************************************************************************
#include <os_syscall.h>
#include <drv_dbgout.h>
#include <rts.h>
#include <tpo.h>

#include "unCP_MemoryTest.h"




/* ������� ������ ����� � ������ */
void WriteMemoryNumber(uint32 uniAbsoluteMemoryAddress,uint32 usiDataWriteMemory,uint32 len);

/* ������� ������ ����� �� ������ */
uint32 usiReadMemoryNumber(uint32 uniAbsoluteMemoryAddress, uint32 len);

/* ������� ������������ ������ ������ 
   ������������ �������� ���������:
   0 - ������ ������������;
   1 - ������������� ���������� ������������ */
uint32 uniMemoryCellTest(uint32 uniMemoryAddress, uint32 *uniPtrErrorsPositions, uint32 Width_Bus);

/* ������� ������������ ���� ������ ������
   ������������ �������� ���������:
   0 - ������ ������������;
   1 - ������������� ���������� ������������ */
uint32 uniMemoryBusAddressTest(uint32 uniStartMemoryAddress, uint32 uniMemoryLength, uint32 *uniPtrErrorAddress);

/* ������� ������������ ������
   ������������ �������� ���������:
   0 - ������������� ���������� ������������;
   1 - ������ ������������ ���� ������ ������;
   2 - ������ ������������ ���� ������ ������;
   3 - ������ ������������ ������ */
uint32 uniMemoryTest(uint32 uniStartMemoryAddress, uint32 uniMemoryLength, uint32 *uniPtrErrorsPositions, uint32 *uniPtrErrorAddress, uint32 Width_Bus);

/*   ������������ �������� ���������:
   0 - ������������� ���������� ������������;
   1 - ������ ������������ ���� ������ ������;
   2 - ������ ������������ ���� ������ ������;
   3 - ������ ������������ ������ */
uint32 uniTestRAM(uint32 *uniPtrErrorsPositions, uint32 *uniPtrErrorAddress);

//******************************************************************************
//                         ������� ������ �����
//                               � ������
//******************************************************************************
void WriteMemoryNumber
                             (
                               /* ���������� ����� ������ */
                               uint32 uniAbsoluteMemoryAddress,
                               /* ������ ������������ � ������ */
                               uint32 usiDataWriteMemory,
							   uint32 len
                             )
{ /* ������� ������ ����� � ������ */
  /* ������ ������ � ������ �� ����������� ������ */

memcpy((void*)(uniAbsoluteMemoryAddress), &usiDataWriteMemory, len);

//  *(uint32*)(uniAbsoluteMemoryAddress) = usiDataWriteMemory;



} /* ������� ������ ����� � ������ */

//******************************************************************************
//                         ������� ������ �����
//                              �� ������
//******************************************************************************
uint32 usiReadMemoryNumber
                                       (
                                         /* ���������� ����� ������ */
                                         uint32 uniAbsoluteMemoryAddress,
										 uint32 len

                                       )
{ /* ������� ������ ����� �� ������ */
  /* ������ ������ �� �� ������ */
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
} /* ������� ������ ����� �� ������ */

//******************************************************************************
//                             ������� ������������ 
//                                ������ ������ 
//******************************************************************************
uint32 uniMemoryCellTest
                                     (
                                       /* ����� ������ */
                                       uint32 uniMemoryAddress,
                                       /* ������� ������ ������/������ */
                                       uint32 *uniPtrErrorsPositions,
									   uint32 Width_Bus
                                     )
{ /* ������� ������������ ������ ������ */
  /* ����� ������� ����� */
  const uint32 uniTEST_ONE = 1;
  /* ������ ������� ����� */
  const uint32 usiTEST_DATA_ONE = 0x00000000;

  /* ����� ������� ����� */
  const uint32 uniTEST_TWO = 2;
  /* ������ ������� ����� */
  const uint32 usiTEST_DATA_TWO = 0xFFFFFFFF;

  /* ����� �������� ����� */
  const uint32 uniTEST_THREE = 3;
  /* ������ �������� ����� */
  const uint32 usiTEST_DATA_THREE = 0x55555555;

  /* ����� ��������� ����� */
  const uint32 uniTEST_FOUR = 4;
  /* ������ ��������� ����� */
  const uint32 usiTEST_DATA_FOUR = 0xAAAAAAAA;

  /* ������ ��� ���������� */
  uint32 Save_mem;
  /* ������� ����� ����� */
  uint32 uniCurrentTestNumber;
  /* ������ ������������ � ������ */
  uint32 usiSetMemoryValue;
  /* ���������� �� ������ �������� */
  uint32 usiGetMemoryValue;
  /* ��������� ������������ */
  uint32 uniTestResult_OK;

  /* ���������� �������� ������ */
  const uint32 uniQUANTITY_ERRORS_POSITION = Width_Bus;
  /* ������� ������ ������� ������ */
  uint32 uniCurrentErrorPositionIndex;
  /* ������� ������ ������/������ */
  uint32 uniErrorsPositions;
  /* ����� ������ */
  uint32 usiMaskError;
  /* ����������� � ������ �������� */
  uint32 usiSaveMemoryValue;
  /* ��������� �� ������ �������� */
  uint32 usiReadMemoryValue;

  /* ����� �������������� ���������� ������������ */
  uniTestResult_OK = 0;
  /* ����� �������� ������ */
  uniErrorsPositions = 0;

  uint32 deltaAdrr = Width_Bus / 8;

	uint32 int_old = 0;

	int_old = int_disable();

  //���������� �����
  Save_mem = usiReadMemoryNumber(uniMemoryAddress, deltaAdrr);

  /* ������������ ������/������ ������ */
  for (uniCurrentTestNumber = 1;
       uniCurrentTestNumber < uniTEST_FOUR + 1;
       uniCurrentTestNumber++)
    { /* ������������ ������/������ ������ */
      /* ���� ����������� ������ ���� */
      if (uniCurrentTestNumber == uniTEST_ONE)
        usiSetMemoryValue = usiTEST_DATA_ONE;
      /* ����� ���� ����������� ������ ���� */
      else if (uniCurrentTestNumber == uniTEST_TWO)
        usiSetMemoryValue = usiTEST_DATA_TWO;
      /* ����� ���� ����������� ������ ���� */
      else if (uniCurrentTestNumber == uniTEST_THREE)
        usiSetMemoryValue = usiTEST_DATA_THREE;
      /* ����� ���� ����������� �������� ���� */
      else if (uniCurrentTestNumber == uniTEST_FOUR)
        usiSetMemoryValue = usiTEST_DATA_FOUR;

//      HWI_disable();
      
//      ram_cell = usiReadMemoryNumber(uniMemoryAddress);//��������� ������;

      /* ������ ����� � ������ */
      WriteMemoryNumber(uniMemoryAddress,usiSetMemoryValue,deltaAdrr);

if(uniMemoryAddress == 0x60000308)//��� usb ����������� delay
{
uint32 o = 0x100;
while(o--);
}
      /* ������ ����� �� ������ */
      usiGetMemoryValue = usiReadMemoryNumber(uniMemoryAddress, deltaAdrr);

//      WriteMemoryNumber(uniMemoryAddress,ram_cell);//��������������� ������;

//      HWI_enable();

      /* ���� �� ��������� ���������� � ��������� ������ */
      if (memcmp(&usiSetMemoryValue, &usiGetMemoryValue, deltaAdrr))
        { /* �� ��������� ���������� � ��������� ������ */
          /* ����� �������� � �������� */
          for (uniCurrentErrorPositionIndex = 0;
               uniCurrentErrorPositionIndex < uniQUANTITY_ERRORS_POSITION;
               uniCurrentErrorPositionIndex++)
            { /* ����� �������� � �������� */
              /* ����� ������ */
              usiMaskError = (uint32)(1 << uniCurrentErrorPositionIndex);
              /* ������������ ������������ � ������ �������� */
              usiSaveMemoryValue = usiSetMemoryValue & usiMaskError;
              /* ������������ ���������� �� ������ �������� */
              usiReadMemoryValue = usiGetMemoryValue & usiMaskError;
              /* ���� �� ��������� ���������� � ��������� ������ ������, ��
                 ��������� ������� ������ */
              if (usiSaveMemoryValue != usiReadMemoryValue)
                uniErrorsPositions = uniErrorsPositions | usiMaskError;
            } /* ����� �������� � �������� */
          
          /* ����� �������������� ���������� ������������ */
          uniTestResult_OK = 0;
          break;
        } /* �� ��������� ���������� � ��������� ������ */

      /* ����� ��������� �������������� ���������� ������������ */
      else uniTestResult_OK = 1;
    } /* ������������ ������/������ ������ */

  /* ������� �������� �������� � �������� ������/������ */
  *uniPtrErrorsPositions = uniErrorsPositions;
  /* ������� �������� ���������� ������������ */

//������������� ������
  WriteMemoryNumber(uniMemoryAddress, Save_mem, deltaAdrr);

	int_enable(int_old);	

  return uniTestResult_OK;
} /* ������� ������������ ������ ������ */

//******************************************************************************
//                             ������� ������������ 
//                              ���� ������ ������ 
//******************************************************************************
uint32 uniMemoryBusAddressTest
                                           (
                                             /* ��������� ����� ������ */
                                             uint32 uniStartMemoryAddress,
                                             /* ����� ������ */
                                             uint32 uniMemoryLength,
                                             /* ����� ������ ������/������ */
                                             uint32 *uniPtrErrorAddress,
											 uint32 Width_Bus
                                           )
{ /* ������� ������������ ���� ������ ������ */
  /* ������� ������ ������ */
  uint32 uniCurrentMemoryIndex;
  /* ������ ������������ � ������ */
  uint32 usiSetMemoryValue;
  /* ���������� �� ������ �������� */
  uint32 usiGetMemoryValue;
  /* ����� ������ ������/������ */
  uint32 uniErrorAddress;
  /* ��������� ������������ */
  uint32 uniTestResult_OK;

  /* ����� �������������� ���������� ������������ */
  uniTestResult_OK = 0;

  uint32 deltaAdrr = Width_Bus / 8;

  uint32 ram_cell = 0;
  uint32 int_old = 0;

  /* ������������ ���� ������ */
  for (uniCurrentMemoryIndex = 0;
       uniCurrentMemoryIndex < uniMemoryLength;
       uniCurrentMemoryIndex += deltaAdrr)
    { /* ������������ ���� ������ */
      /* ������ ������������ � ������ */
      usiSetMemoryValue = (uint32)uniCurrentMemoryIndex;
      /* ������ ����� � ������ */
//      HWI_disable();

//      ram_cell = usiReadMemoryNumber(uniStartMemoryAddress + 2*uniCurrentMemoryIndex);//��������� ������;
	int_old = int_disable();

    ram_cell = usiReadMemoryNumber(uniStartMemoryAddress + uniCurrentMemoryIndex, deltaAdrr);//��������� ������;

      WriteMemoryNumber(uniStartMemoryAddress + uniCurrentMemoryIndex,usiSetMemoryValue, deltaAdrr);
      /* ������ ����� �� ������ */
      usiGetMemoryValue = usiReadMemoryNumber(uniStartMemoryAddress + uniCurrentMemoryIndex, deltaAdrr);
//      WriteMemoryNumber(uniStartMemoryAddress + 2*uniCurrentMemoryIndex,ram_cell);
//	  HWI_enable();
      WriteMemoryNumber(uniStartMemoryAddress + uniCurrentMemoryIndex, ram_cell, deltaAdrr);
	  int_enable(int_old);	

      /* ���� �� ��������� ���������� � ��������� ������ */
      if (memcmp(&usiSetMemoryValue, &usiGetMemoryValue, deltaAdrr))
        { /* �� ��������� ���������� � ��������� ������ */
          /* ���������� ������ ������ ������/������ */
          uniErrorAddress = uniCurrentMemoryIndex;
          /* ����� �������������� ���������� ������������ */
          uniTestResult_OK = 0;
          break;
        } /* �� ��������� ���������� � ��������� ������ */

      /* ����� ��������� �������������� ���������� ������������ */
      else uniTestResult_OK = 1;
    } /* ������������ ���� ������ */

  /* ������� �������� ������ ������ ������/������ */
  *uniPtrErrorAddress = uniErrorAddress;
  /* ������� �������� ���������� ������������ */
  return uniTestResult_OK;
} /* ������� ������������ ���� ������ ������ */

//******************************************************************************
//                                �������  
//                          ������������ ������ 
//******************************************************************************
uint32 uniMemoryTest
                                 (
                                   /* ��������� ����� ������ */
                                   uint32 uniStartMemoryAddress,
                                   /* ����� ������ */
                                   uint32 uniMemoryLength,
                                   /* ������� ������ ������/������ */
                                   uint32 *uniPtrErrorsPositions,
                                   /* ����� ������ ������/������ */
                                   uint32 *uniPtrErrorAddress,
								   uint32 Width_Bus
                                 )
{ /* ������� ������������ ������ */
  /* ������� ������ ������/������ */
  uint32 uniErrorsPosition;
  /* ����� ������ ������/������ */
  uint32 uniErrorAddress;
  /* ������� ������ ������ */
  uint32 uniCurrentMemoryIndex;

  /* ��������� ������������ ���� ������ ������ */
  uint32 uniTestDataBusResult_OK;
  /* ��������� ������������ ���� ������ ������ */
  uint32 uniTestAddressBusResult_OK;
  /* ��������� ������������ ������ */
  uint32 uniTestMemoryResult_OK;
  /* ������������ �������� ��������� ������������ */
  uint32 uniTestResultReturn;

  uint32 deltaAdrr = Width_Bus / 8;

  /* ����� �������������� ���������� ������������ ���� ������ ������ */
  uniTestDataBusResult_OK = 0;
  /* ����� �������������� ���������� ������������ ���� ������ ������ */
  uniTestAddressBusResult_OK = 0;
  /* ����� �������������� ���������� ������������ ������ */
  uniTestMemoryResult_OK = 0;

  /* ����� �������� ������ ������/������ */
  uniErrorsPosition = 0;
  /* ����� ������ ������ ������/������ */
  uniErrorAddress = 0;

  /* ������������ ���� ������ ������ */
  uniTestDataBusResult_OK = uniMemoryCellTest
                                            (
                                              /* ����� ������ */
                                              uniStartMemoryAddress,
                                              /* ������� ������ ������/������ */
                                              & uniErrorsPosition,
											  Width_Bus
                                            );
  /* ���� �������� ���� ���� ������ ������ */
  if(uniTestDataBusResult_OK)
    { /* �������� ���� ���� ������ ������ */
      /* ������������ ���� ������ ������ */
      uniTestAddressBusResult_OK = uniMemoryBusAddressTest
                                              (
                                                /* ��������� ����� ������ */
                                                uniStartMemoryAddress,
                                                /* ����� ������ */
                                                uniMemoryLength,
                                                /* ����� ������ ������/������ */
                                                & uniErrorAddress,
												Width_Bus
                                              );
    } /* �������� ���� ���� ������ ������ */

  /* ���� �������� ���� ���� ������ ������ */
  if(uniTestAddressBusResult_OK)
    { /* �������� ���� ���� ������ ������ */
      /* ������������ ������ */
      for (uniCurrentMemoryIndex = 0;
           uniCurrentMemoryIndex < uniMemoryLength;
           uniCurrentMemoryIndex++)
        { /* ������������ ������ */
          /* ������������ ������ ������ */
          uniTestMemoryResult_OK = uniMemoryCellTest
                                (
                                  /* ����� ������ */
                                  uniStartMemoryAddress + deltaAdrr * uniCurrentMemoryIndex,
                                  /* ������� ������ ������/������ */
                                  & uniErrorsPosition,
								  Width_Bus
                                );
          /* ���� ������ ������������, �� ��������� ����� */
          if(uniTestMemoryResult_OK == 0)
            break;
        } /* ������������ ������ */
    } /* �������� ���� ���� ������ ������ */

  /* ���� �� ������ ������������ ���� ������ ������ */
  if(uniTestDataBusResult_OK == 0)
    { /* �� ������ ������������ ���� ������ ������ */
      /* ������� ������ ������/������ ������ */
      *uniPtrErrorsPositions = uniErrorsPosition;
      /* ����� ������ ������/������ ������ */
      *uniPtrErrorAddress = 0;
      /* ������������ �������� ��������� ����� */
      uniTestResultReturn = TEST_DATA_BUS_ERROR;
    } /* �� ������ ������������ ���� ������ ������ */
  /* ����� ���� �� ������ ������������ ���� ������ ������ */
  else if(uniTestAddressBusResult_OK == 0)
    { /* �� ������ ������������ ���� ������ ������ */
      /* ������� ������ ������/������ ������ */
      *uniPtrErrorsPositions = 0;
      /* ����� ������ ������/������ ������ */
      *uniPtrErrorAddress = uniErrorAddress;
      /* ������������ �������� ��������� ����� */
      uniTestResultReturn = TEST_ADDRESS_BUS_ERROR;
    } /* �� ������ ������������ ���� ������ ������ */
  /* ����� ���� �� ������ ������������ ������ */
  else if(uniTestMemoryResult_OK == 0)
    { /* �� ������ ������������ ���� ������ */
      /* ������� ������ ������/������ ������ */
      *uniPtrErrorsPositions = uniErrorsPosition;
      /* ����� ������ ������/������ ������ */
      *uniPtrErrorAddress = 0;
      /* ������������ �������� ��������� ����� */
      uniTestResultReturn = TEST_MEMORY_ERROR;
    } /* �� ������ ������������ ���� ������ */
  /* ����� ������ ������������ ������ */
  else 
    { /* ������ ������������ ������ */
      /* ������� ������ ������/������ ������ */
      *uniPtrErrorsPositions = 0;
      /* ����� ������ ������/������ ������ */
      *uniPtrErrorAddress = 0;
      /* ������������ �������� ��������� ����� */
      uniTestResultReturn = TEST_RESULT_OK;
    } /* ������ ������������ ������ */

  /* ������� �������� ���������� ������������ */
  return uniTestResultReturn;
} /* ������� ������������ ������ */

//******************************************************************************
//                           ������� ������������ ��� 
//******************************************************************************
uint32 uniTestSDRAM(uint32 *uniPtrErrorsPositions,uint32 *uniPtrErrorAddress)
{ 

  /* ��� - CE0 EMIFA */
  const uint32 uniRAM_ADDRESS = 0x80000000;
  /* ����� � 8 �����, o���������� � 2M � 32,
     ��������� � �������� 22 ������ ������ � ������������ ���� EMIFA, ����
     ������ � 1/2 ���� ������ EMIFA */
  const uint32 uniRAM_LENGTH = 0x800000;

  uint32 Width_Bus = 32;

  /* ��������� ������������ */
  uint32 uniTestResult_OK;
  /* ������� ������ ������/������ */
  uint32 uniErrorsPositions;
  /* ����� ������ ������/������ */
  uint32 uniErrorAddress;

  /* ������������ �������� ������������ ��� */
  uniTestResult_OK = uniMemoryTest
                                  (
                                    /* ��������� ����� ������ */
                                    uniRAM_ADDRESS,
                                    /* ����� ������ */
                                    uniRAM_LENGTH,
                                    /* ������� ������ ������/������ */
                                    & uniErrorsPositions,
                                    /* ����� ������ ������/������ */
                                    & uniErrorAddress,
									Width_Bus
                                  );

  /* ������� �������� �������� ������ ������/������ */
  *uniPtrErrorsPositions = uniErrorsPositions;
  /* ������� �������� ������ ������ ������/������ */
  *uniPtrErrorAddress = uniErrorAddress;
  /* ������� �������� ��������� ������������ */
  return uniTestResult_OK;
} /* ������� ������������ �������� ������������ ��� */


uint32 uniTestNVRAM(uint32 *uniPtrErrorsPositions,uint32 *uniPtrErrorAddress)
{ 

  /* ����������������� ��� - CE2 EMIFB */
  const uint32 uniRAM_ADDRESS = 0x68000000;
  /* ����� � 1 �����, o���������� � 512K � 16,
     ��������� � �������� 20 �������� ������ � ������������ ���� EMIFB, ����
     ������ � ������ ���� ������ EMIFB */
  const uint32 uniRAM_LENGTH = 0x100000;

  uint32 Width_Bus = 16;

  /* ��������� ������������ */
  uint32 uniTestResult_OK;
  /* ������� ������ ������/������ */
  uint32 uniErrorsPositions;
  /* ����� ������ ������/������ */
  uint32 uniErrorAddress;

  /* ������������ �������� ������������ ��� */
  uniTestResult_OK = uniMemoryTest
                                  (
                                    /* ��������� ����� ������ */
                                    uniRAM_ADDRESS,
                                    /* ����� ������ */
                                    uniRAM_LENGTH,
                                    /* ������� ������ ������/������ */
                                    & uniErrorsPositions,
                                    /* ����� ������ ������/������ */
                                    & uniErrorAddress,
									Width_Bus
								   );

  /* ������� �������� �������� ������ ������/������ */
  *uniPtrErrorsPositions = uniErrorsPositions;
  /* ������� �������� ������ ������ ������/������ */
  *uniPtrErrorAddress = uniErrorAddress;
  /* ������� �������� ��������� ������������ */
  return uniTestResult_OK;
} /* ������� ������������ �������� ������������ ��� */
