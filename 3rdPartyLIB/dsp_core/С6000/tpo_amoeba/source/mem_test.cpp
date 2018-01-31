/**********************************************************************************************************************
*                                        (c) COPYRIGHT by ZAO RCZI FORT.                                             *
*        ..                                       All rights reserved.                                               *
***********************************************************************************************************************
* Module      : mem_test.cpp
* Description : ������� ������������ ������ �����?
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


/* ������� ������������ ������ ������ 
   ������������ �������� ���������:
   1 - ������ ������������;
   0 - ������������� ���������� ������������ */
uint32 uniMemoryCellTest(uint32 uniMemoryAddress, uint64 *uniPtrErrorsPositions, uint32 Width_Bus);

/* ������� ������������ ���� ������ ������
   ������������ �������� ���������:
   1 - ������ ������������;
   0 - ������������� ���������� ������������ */
uint32 uniMemoryBusAddressTest(mem_test *param);

/* ������� ������������ ������
   ������������ �������� ���������:
   0 - ������������� ���������� ������������;
   1 - ������ ������������ ���� ������ ������;
   2 - ������ ������������ ���� ������ ������;
   3 - ������ ������������ ������ */
uint32 uniMemoryTest(mem_test *param);

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
void WriteMemoryNumber(uint32 uniAbsoluteMemoryAddress, uint32 usiDataWriteMemory, uint32 len)
{ 
	/* ������� ������ ����� � ������ */
	/* ������ ������ � ������ �� ����������� ������ */
	memcpy((void*)(uniAbsoluteMemoryAddress), &usiDataWriteMemory, len);
	//  *(uint32*)(uniAbsoluteMemoryAddress) = usiDataWriteMemory;
} /* ������� ������ ����� � ������ */



/*****************************************************************************
Syntax:      	    
Remarks: ������� ������ ����� �� ������			    
*******************************************************************************/
uint32 usiReadMemoryNumber(
                                         /* ���������� ����� ������ */
                                         uint32 uniAbsoluteMemoryAddress,
										 uint32 len

                                       )
{ 
    /* ������� ������ ����� �� ������ */
    /* ������ ������ �� �� ������    */
	uint32 uniDataReadMemory = 0;

	if(uniAbsoluteMemoryAddress == 0x68080000)
	{
		uniAbsoluteMemoryAddress++;
		uniAbsoluteMemoryAddress--;
	//	uniAbsoluteMemoryAddress==uniAbsoluteMemoryAddress;  ?? //skd_ ������������
	}

	memcpy( &uniDataReadMemory, (void*)(uniAbsoluteMemoryAddress), len);
	//uniDataReadMemory = (*(uint32*)(uniAbsoluteMemoryAddress));

  return uniDataReadMemory;
} 

/* ������� ������ ����� �� ������ */

//******************************************************************************
//                             ������� ������������ 
//                                ������ ������ 
//******************************************************************************
uint32 uniMemoryCellTest(             /* ����� ������ */
                                       uint32 uniMemoryAddress,
                                       /* ������� ������ ������/������ */
                                       uint64 *uniPtrErrorsPositions,
									   uint32 Width_Bus)
{ 

  uint64 TEST_DATA[4] = {0, 0xFFFFFFFFFFFFFFFF, 0x5555555555555555, 0xAAAAAAAAAAAAAAAA};
  /* ������ ��� ���������� */
  uint64 Save_mem;
  /* ���������� �� ������ �������� */
  uint64 GetMemVal;

  uint64 Mask = 0;
  for(int i=0; i<Width_Bus; i++)
  Mask |= 1<<i;

  uint32 deltaAdrr = Width_Bus / 8;

  /* ��������� ������������ */
  uint32 TestRes = 0;
  /* ������� ������ ������/������ */
  uint32 uniErrorsPositions = 0;


	uint32 int_old = 0;
	int_old = int_disable();

	//���������� �����
	memcpy( &Save_mem, (void*)uniMemoryAddress, deltaAdrr);
//  Save_mem = usiReadMemoryNumber(uniMemoryAddress, deltaAdrr);

  /* ������������ ������/������ ������ */
	for (int i = 0; i < 4; i++)
	{
	    /* ������ ����� � ������ */
		memcpy((void*)uniMemoryAddress, &TEST_DATA[i], deltaAdrr);
	//	WriteMemoryNumber(uniMemoryAddress,usiSetMemoryValue,deltaAdrr);

	/*
	if(uniMemoryAddress == 0x60000308)//��� usb ����������� delay ����� ���� ������
	{
	uint32 o = 0x100;
	while(o--);
	}
	*/
	    /* ������ ����� �� ������ */
		memcpy( &GetMemVal, (void*)uniMemoryAddress, deltaAdrr);
	//  usiGetMemoryValue = usiReadMemoryNumber(uniMemoryAddress, deltaAdrr);

	    /* ���� �� ��������� ���������� � ��������� ������ */
    	if(memcmp(&TEST_DATA[i], &GetMemVal, deltaAdrr))
	    {
    	 uniErrorsPositions = (TEST_DATA[i] & Mask) ^ (GetMemVal & Mask);
	     TestRes = 1;
    	 break;
	    }
    } /* ������������ ������/������ ������ */

  /* ������� �������� �������� � �������� ������/������ */
  *uniPtrErrorsPositions = uniErrorsPositions;
  /* ������� �������� ���������� ������������ */

//������������� ������
  memcpy((void*)uniMemoryAddress, &Save_mem, deltaAdrr);
//  WriteMemoryNumber(uniMemoryAddress, Save_mem, deltaAdrr);

  int_enable(int_old);	

  return TestRes;
} /* ������� ������������ ������ ������ */

//******************************************************************************
//                             ������� ������������ 
//                              ���� ������ ������ 
//******************************************************************************
uint32 uniMemoryBusAddressTest(mem_test *param)
{ /* ������� ������������ ���� ������ ������ */

  uint32 i;
  /* ���������� �� ������ �������� */
  uint64 rd_data = 0;
  uint64 wr_data = 0;
  /* ��������� ������������ */
  uint32 TestResult = 0;

  uint32 deltaAdrr = param->Width_Bus / 8;

  uint64 ram_cell[32+1];
  memset(ram_cell, 0, sizeof(ram_cell));

  uint64 Mask = 0;
  for(int i=0; i < param->Width_Bus; i++)
  Mask |= 1 << i;

  uint32 int_old = 0;

  int_old = int_disable();

  // ������������ ���� ������ 
  //��������� ������ ������ x0, (x1, x2, x4, x8,) x10, x20;
  for (i = 0; ((deltaAdrr<<i) < param->length); i++)
		memcpy( &ram_cell[i+1], (void*)(param->addr + (deltaAdrr << i)), deltaAdrr);
 	    memcpy( &ram_cell[0], (void*)param->addr, deltaAdrr);
	   //	ram_cell[i+1] = usiReadMemoryNumber(param->addr+(deltaAdrr<<i), deltaAdrr);//��������� ������;
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
} /* ������� ������������ ���� ������ ������ */

//******************************************************************************
//                                �������  
//                          ������������ ������ 
//******************************************************************************
uint32 uniMemoryTest(mem_test *param)

{ /* ������� ������������ ������ */
  uint32 i;

  /* ��������� ������������ ���� ������ ������ */
  uint32 DataBusResult=0;
  /* ��������� ������������ ���� ������ ������ */
  uint32 AddressBusResult=0;
  /* ��������� ������������ ������ */
  uint32 TestMemoryResult=0;
  /* ������������ �������� ��������� ������������ */
  uint32 TestResult = 0;

  uint32 deltaAdrr = param->Width_Bus / 8;

  /* ������������ ���� ������ ������ */
  DataBusResult = uniMemoryCellTest(param->addr, & param->ErrPosition, param->Width_Bus);

  /* ���� �������� ���� ���� ������ ������ */
  if(!DataBusResult)
    /* ������������ ���� ������ ������ */
    AddressBusResult = uniMemoryBusAddressTest(param);

  /* ���� �������� ���� ���� ������ ������ */
  if(!AddressBusResult)
    { /* ������������ ������ */
      for (i = 0; i < param->length; i++)
      {
      TestMemoryResult = uniMemoryCellTest(param->addr + deltaAdrr * i, & param->ErrPosition, param->Width_Bus);
          /* ���� ������ ������������, �� ��������� ����� */
          if(TestMemoryResult == 1)
			{
			param->ErrAddr = deltaAdrr * i;
            break;
			}
      } 
    }

  /* ���� �� ������ ������������ ���� ������ ������ */
  if(DataBusResult == 1)
    { 
      /* ����� ������ ������/������ ������ */
      param->ErrAddr = 0;
      /* ������������ �������� ��������� ����� */
      TestResult = TEST_DATA_BUS_ERROR;
    }
  /* ����� ���� �� ������ ������������ ���� ������ ������ */
  else if(AddressBusResult == 1)
    { 
      /* ������� ������ ������/������ ������ */
      param->ErrPosition = 0;
      /* ������������ �������� ��������� ����� */
      TestResult = TEST_ADDRESS_BUS_ERROR;
    }
  /* ����� ���� �� ������ ������������ ������ */
  else 
  if(TestMemoryResult == 1)
      TestResult = TEST_MEMORY_ERROR;
  else 
    { /* ������ ������������ ������ */
      /* ������� ������ ������/������ ������ */
      param->ErrPosition = 0;
      /* ����� ������ ������/������ ������ */
      param->ErrAddr = 0;
      /* ������������ �������� ��������� ����� */
      TestResult = TEST_RESULT_OK;
    } /* ������ ������������ ������ */
  return TestResult;
}
//******************************************************************************
//                           ������� ������������ ��� ��
//******************************************************************************
uint32 uniTestSDRAM_CP(uint64 *uniPtrErrorsPositions,uint32 *uniPtrErrorAddress)
{ 

mem_test sd_tst;

sd_tst.addr = 0x80000000;
sd_tst.length = 0x800000;
sd_tst.Width_Bus = 32;
sd_tst.ErrPosition = 0;
sd_tst.ErrAddr = 0;

  /* ��� - CE0 EMIFA */
  /* ����� � 8 �����, o���������� � 2M � 32,
     ��������� � �������� 22 ������ ������ � ������������ ���� EMIFA, ����
     ������ � 1/2 ���� ������ EMIFA */
  /* ��������� ������������ */

uint32 uniTestResult_OK;

  /* ������������ �������� ������������ ��� */
uniTestResult_OK = uniMemoryTest(&sd_tst);

  /* ������� �������� �������� ������ ������/������ */
  *uniPtrErrorsPositions = sd_tst.ErrPosition;
  /* ������� �������� ������ ������ ������/������ */
  *uniPtrErrorAddress = sd_tst.ErrAddr;
  /* ������� �������� ��������� ������������ */
  return uniTestResult_OK;
} /* ������� ������������ �������� ������������ ��� */


uint32 uniTestNVRAM(uint64 *uniPtrErrorsPositions,uint32 *uniPtrErrorAddress)
{ 

mem_test nv_tst;

nv_tst.addr = 0x68000000;
nv_tst.length = 0x100000;
nv_tst.Width_Bus = 16;
nv_tst.ErrPosition = 0;
nv_tst.ErrAddr = 0;

  /* ����������������� ��� - CE2 EMIFB */
  /* ����� � 1 �����, o���������� � 512K � 16,
     ��������� � �������� 20 �������� ������ � ������������ ���� EMIFB, ����
     ������ � ������ ���� ������ EMIFB */
  /* ��������� ������������ */
  uint32 uniTestResult_OK;

  /* ������������ �������� ������������ ��� */
  uniTestResult_OK = uniMemoryTest(&nv_tst);

  /* ������� �������� �������� ������ ������/������ */
  *uniPtrErrorsPositions = nv_tst.ErrPosition;
  /* ������� �������� ������ ������ ������/������ */
  *uniPtrErrorAddress = nv_tst.ErrAddr;
  /* ������� �������� ��������� ������������ */
  return uniTestResult_OK;
} /* ������� ������������ �������� ������������ ��� */


//******************************************************************************
//                           ������� ������������ ��� ��
//******************************************************************************
uint32 uniTestSDRAM_PP(uint64 *uniPtrErrorsPositions,uint32 *uniPtrErrorAddress)
{ 

mem_test sd_tst;

sd_tst.addr = 0x90000000;
sd_tst.length = 0x800000;
sd_tst.Width_Bus = 32;
sd_tst.ErrPosition = 0;
sd_tst.ErrAddr = 0;

  /* ��� - CE0 EMIFA */
  /* ����� � 8 �����, o���������� � 2M � 32,
     ��������� � �������� 22 ������ ������ � ������������ ���� EMIFA, ����
     ������ � 1/2 ���� ������ EMIFA */
  /* ��������� ������������ */

uint32 uniTestResult_OK;

  /* ������������ �������� ������������ ��� */
uniTestResult_OK = uniMemoryTest(&sd_tst);

  /* ������� �������� �������� ������ ������/������ */
  *uniPtrErrorsPositions = sd_tst.ErrPosition;
  /* ������� �������� ������ ������ ������/������ */
  *uniPtrErrorAddress = sd_tst.ErrAddr;
  /* ������� �������� ��������� ������������ */
  return uniTestResult_OK;
} /* ������� ������������ �������� ������������ ��� */
