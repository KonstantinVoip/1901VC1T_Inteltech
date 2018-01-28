//******************************************************************************
// @Module        unPP_MemoryTest
// @Filename      unPP_MemoryTest.h
// @Project       MB5
//------------------------------------------------------------------------------
// @Controller    TMS320C6416
//
// @Description   Модуль функций тестов памяти переферийного процессора 
//
//------------------------------------------------------------------------------
//
//******************************************************************************

#ifndef unPP_MEMORY_TEST_H
#define unPP_MEMORY_TEST_H

//#include "types.h"

uint32 uniTestSDRAM(uint32 *uniPtrErrorsPositions,uint32 *uniPtrErrorAddress);
uint32 uniMemoryCellTest(uint32 uniMemoryAddress, uint32 *uniPtrErrorsPositions, uint32 Width_Bus);

#endif /* unPP_MEMORY_TEST_H */
