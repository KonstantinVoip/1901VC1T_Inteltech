//**************************************************************************************************
//                         Copyright (C) 2009 RCZI
//--------------------------------------------------------------------------------------------------
// FILENAME....... drv_usbhc.h
// DATE CREATED... 10/11/2009
// LAST MODIFIED.. 23/11/2009
// DRIVER VERSION. 1.0
//-------------------------------------------------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
//
// !: codepage: cp1251 
//
// !: d: �������� ����� ������, ���������� ����������� ������, �������� 
// !: d: �������� NEC uPD720150 Hi-Speed Universal Serial Bus host controller.
// !: -:
//***sss********************************************************************************************
#ifndef __Driver_USBHC_uPD720150_H__
#define __Driver_USBHC_uPD720150_H__

// -- For system calls only ---------------------------------------------------
extern int32     drv_usbhc_upd720150_plug(uint32 number_gpio_interrupt);
extern int32     drv_usbhc_upd720150_unplug();

#endif //__Driver_USBHC_uPD720150_H__

