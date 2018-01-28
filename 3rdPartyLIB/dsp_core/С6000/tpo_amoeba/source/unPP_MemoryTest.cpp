//******************************************************************************
// @Module        unPP_MemoryTest
// @Filename      unPP_MemoryTest.cpp
// @Project       MB5
//------------------------------------------------------------------------------
// @Controller    TMS320C6416
//
// @Description   ������ ������� ������ ������ 
//------------------------------------------------------------------------------

//******************************************************************************
#include <os_syscall.h>
#include <drv_dbgout.h>
#include <rts.h>
#include <tpo.h>

#include "unPP_MemoryTest.h"


/* ������� ������ ����� � ������ */
void WriteMemoryNumber(uint32 uniAbsoluteMemoryAddress,uint16 usiDataWriteMemory);

/* ������� ������ ����� �� ������ */
uint32 usiReadMemoryNumber(uint32 uniAbsoluteMemoryAddress);

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
uint32 uniMemoryTest(uint32 uniStartMemoryAddress, uint32 uniMemoryLength, uint32 *uniPtrErrorsPositions, uint32 *uniPtrErrorAddress);

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
                               uint32 usiDataWriteMemory
                             )
{ /* ������� ������ ����� � ������ */
  /* ������ ������ � ������ �� ����������� ������ */
  *(uint32*)(uniAbsoluteMemoryAddress) = usiDataWriteMemory;
//usiMemoryCell = usiDataWriteMemory;

} /* ������� ������ ����� � ������ */

//******************************************************************************
//                         ������� ������ �����
//                              �� ������
//******************************************************************************
uint32 usiReadMemoryNumber
                                       (
                                         /* ���������� ����� ������ */
                                         uint32 uniAbsoluteMemoryAddress
                                       )
{ /* ������� ������ ����� �� ������ */
  /* ������ ������ �� �� ������ */
  uint32 uniDataReadMemory;
   
  uniDataReadMemory = (*(uint32*)(uniAbsoluteMemoryAddress));
//  uniDataReadMemory = usiMemoryCell; 

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

	uint32 int_old = 0;

	int_old = int_disable();

//���������� �����
  Save_mem = usiReadMemoryNumber(uniMemoryAddress);

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
      WriteMemoryNumber(uniMemoryAddress,usiSetMemoryValue);

if(uniMemoryAddress == 0x80000610)//��� usb ����������� delay
{
uint32 o = 0x100;
while(o--);
}
      /* ������ ����� �� ������ */
      usiGetMemoryValue = usiReadMemoryNumber(uniMemoryAddress);

//      WriteMemoryNumber(uniMemoryAddress,ram_cell);//��������������� ������;

//      HWI_enable();

      /* ���� �� ��������� ���������� � ��������� ������ */
      if (usiSetMemoryValue != usiGetMemoryValue)
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
//������������� ������
  WriteMemoryNumber(uniMemoryAddress,Save_mem);

	int_enable(int_old);	

  /* ������� �������� ���������� ������������ */
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
                                             uint32 *uniPtrErrorAddress
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

uint32 ram_cell = 0;
uint32 int_old = 0;

  /* ������������ ���� ������ */
  for (uniCurrentMemoryIndex = 0;
       uniCurrentMemoryIndex < (uniMemoryLength/4);
       uniCurrentMemoryIndex++)
    { /* ������������ ���� ������ */
      /* ������ ������������ � ������ */
      usiSetMemoryValue = (uint32)uniCurrentMemoryIndex;
      /* ������ ����� � ������ */
//      HWI_disable();
	int_old = int_disable();

      ram_cell = usiReadMemoryNumber(uniStartMemoryAddress + 4*uniCurrentMemoryIndex);//��������� ������;

      WriteMemoryNumber(uniStartMemoryAddress + 4*uniCurrentMemoryIndex,usiSetMemoryValue);
      /* ������ ����� �� ������ */
      usiGetMemoryValue = usiReadMemoryNumber(uniStartMemoryAddress + 4*uniCurrentMemoryIndex);

      WriteMemoryNumber(uniStartMemoryAddress + 4*uniCurrentMemoryIndex,ram_cell);

	int_enable(int_old);	
//	  HWI_enable();

      /* ���� �� ��������� ���������� � ��������� ������ */
      if (usiSetMemoryValue != usiGetMemoryValue)
        { /* �� ��������� ���������� � ��������� ������ */
          /* ���������� ������ ������ ������/������ */
          uniErrorAddress = 4*uniCurrentMemoryIndex;
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
                                   uint32 *uniPtrErrorAddress
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
											  32
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
                                                & uniErrorAddress
                                              );
    } /* �������� ���� ���� ������ ������ */

  /* ���� �������� ���� ���� ������ ������ */
  if(uniTestAddressBusResult_OK)
    { /* �������� ���� ���� ������ ������ */
      /* ������������ ������ */
      for (uniCurrentMemoryIndex = 0;
           uniCurrentMemoryIndex < (uniMemoryLength/4);
           uniCurrentMemoryIndex++)
        { /* ������������ ������ */
          /* ������������ ������ ������ */
          uniTestMemoryResult_OK = uniMemoryCellTest
                                (
                                  /* ����� ������ */
                                  uniStartMemoryAddress + 4*uniCurrentMemoryIndex,
                                  /* ������� ������ ������/������ */
                                  & uniErrorsPosition,
								  32
                                );
          /* ���� ������ ������������, �� ��������� ����� */
          if(uniTestMemoryResult_OK == 0)
		  {
		 	uniErrorAddress = 4*uniCurrentMemoryIndex;
            break;
		  }
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
      *uniPtrErrorAddress = uniErrorAddress;
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

  /* ��� - CE1 EMIFA */
  const uint32 uniRAM_ADDRESS = 0x90000000;
  /* ����� � 8 �����, o���������� � 2M � 32,
     ��������� � �������� 22 ������� ������ � ������������ ���� EMIFA, ����
     ������ � 1/2 ���� ������ EMIFA */
  const uint32 uniRAM_LENGTH = 0x800000;

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
                                    & uniErrorAddress
                                  );

  // ������� �������� �������� ������ ������/������ 
  *uniPtrErrorsPositions = uniErrorsPositions;
  /* ������� �������� ������ ������ ������/������ */
  *uniPtrErrorAddress = uniErrorAddress;
  /* ������� �������� ��������� ������������ */
  return uniTestResult_OK;
} /* ������� ������������ �������� ������������ ��� */

