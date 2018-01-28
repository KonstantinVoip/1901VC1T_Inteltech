//******************************************************************************
// @Module        unCP_MemoryTest
// @Filename      unCP_MemoryTest.h
// @Project       MB5
//------------------------------------------------------------------------------
// @Controller    TMS320C6416
//
// @Description   Модуль функций тестов памяти центрального процессора 
//
//------------------------------------------------------------------------------
//
//******************************************************************************

#ifndef unCP_MEMORY_TEST_H
#define unCP_MEMORY_TEST_H

//#include "types.h"

struct	mem_test
		{
		uint32 addr;
		uint32 length;
		uint32 Width_Bus;
		uint64 ErrPosition;
		uint32 ErrAddr;
		};

uint32 uniTestSDRAM_PP(uint64 *uniPtrErrorsPositions,uint32 *uniPtrErrorAddress);
uint32 uniTestSDRAM_CP(uint64 *uniPtrErrorsPositions,uint32 *uniPtrErrorAddress);
uint32 uniTestNVRAM(uint64 *uniPtrErrorsPositions,uint32 *uniPtrErrorAddress);
uint32 uniMemoryCellTest(uint32 uniMemoryAddress, uint64 *uniPtrErrorsPositions, uint32 Width_Bus);

#endif /* unCP_MEMORY_TEST_H */

