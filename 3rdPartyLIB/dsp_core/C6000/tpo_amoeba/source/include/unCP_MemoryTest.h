//******************************************************************************
// @Module        unCP_MemoryTest
// @Filename      unCP_MemoryTest.h
// @Project       MB5
//------------------------------------------------------------------------------
// @Controller    TMS320C6416
//
// @Description   Модуль функций тестов памяти центрального процессора (ЦП)
//
//------------------------------------------------------------------------------
//
//******************************************************************************

#ifndef unCP_MEMORY_TEST_H
#define unCP_MEMORY_TEST_H

//#include "types.h"

uint32 uniTestSDRAM(uint32 *uniPtrErrorsPositions,uint32 *uniPtrErrorAddress);
uint32 uniTestNVRAM(uint32 *uniPtrErrorsPositions,uint32 *uniPtrErrorAddress);
uint32 uniMemoryCellTest(uint32 uniMemoryAddress, uint32 *uniPtrErrorsPositions, uint32 Width_Bus);

#endif /* unCP_MEMORY_TEST_H */

