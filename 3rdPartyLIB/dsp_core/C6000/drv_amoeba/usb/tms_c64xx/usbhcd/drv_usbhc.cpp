//**************************************************************************************************
//                         Copyright (C) 2013 RCZI
//--------------------------------------------------------------------------------------------------
// FILENAME....... drv_usbhc.cpp
// DATE CREATED... 15/05/2013
// LAST MODIFIED.. 15/05/2013
// DRIVER VERSION. 1.0
//--------------------------------------------------------------------------------------------------
//       Hi-Speed Universal Serial Bus host controller driver
//-------------------------------------------------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
//
// !: codepage: cp1251 
//
// !: d: ������� Hi-Speed Universal Serial Bus host controller.<br>
// !: md: ���������� (����) ���� ���������� � �� �������� � ����������� ������ 
// !: md: usbhc. ���� � ����������: "/dev/usbhc". ������� ��������� ����������� 
// !: md: ��������� �������������� ������������ � ����������� �� ��������� 
// !: md: ������� ����������� ����������� �� ����������.
// !: -:
//***sss********************************************************************************************
#include    <os.h>
#include    <rts.h>
#include    <drv_gpio.h>
#include    <drv_usbhc.h>

//-------------------------------------------------------------------------------------------------
static volatile int32 gb_usbhc_plug = USBHC_NO_PLUG;

//**************************************************************************************************
//       �������� ������� � �������
//-------------------------------------------------------------------------------------------------
// !: fn: int32 drv_usbhc_plug(uint32 number_gpio_interrupt)
//
// !: d: ��������� ������� USB Host Controller � �������<br><br> 
//
// !: d: ������� ���������:<br>
// !: d: - number_gpio_interrupt - ����� GPIO - ��������� ����������.<br><br>
//
// !: d: ������������ ��������:<br>
// !: d: - ����������� ���� ������ ioctl.<br>
//***sss********************************************************************************************
int32 drv_usbhc_plug(s_usbhc_plug* arg, uint32* usbhc_plug)
{
  int32 error;
  gb_usbhc_plug = *usbhc_plug = USBHC_NO_PLUG;
  error = drv_usbhc_upd720150_plug( arg->nec.gpio_number );
  if( error == OSE_OK )   
  {
    gb_usbhc_plug = *usbhc_plug = USBHC_NEC_PLUG;
    return error;  
  }
  error = drv_usbhc_isp176x_plug( arg->isp.gpio_number );
  if( error == OSE_OK ) 
  {
    gb_usbhc_plug = *usbhc_plug = USBHC_ISP_PLUG;
    return error;
  }
  return error;  
}
//**************************************************************************************************
//      ������� ������� �� ������� 
//-------------------------------------------------------------------------------------------------
// !: fn: int32 drv_usbhc_unplug()
//
// !: d: ������� ������� USB Host Controller �� �������.<br><br>
//
// !: d: ������������ ��������:<br>
// !: d: - ����������� ���� ������ ioctl.<br>
//***sss********************************************************************************************
int32 drv_usbhc_unplug()
{
  switch(gb_usbhc_plug)
  {
    case USBHC_NEC_PLUG: 
    {
      gb_usbhc_plug = USBHC_NO_PLUG;
      return drv_usbhc_upd720150_unplug();
    }
    case USBHC_ISP_PLUG: 
    {
      gb_usbhc_plug = USBHC_NO_PLUG;
      return drv_usbhc_isp176x_unplug();
    }
    case USBHC_NO_PLUG: 
    default: 
    {
      gb_usbhc_plug = USBHC_NO_PLUG;
      return OSE_NO_DRIVER;    
    }
  }
}
