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
// !: d: �������� ISP 1760/1761 Hi-Speed Universal Serial Bus host controller.
// !: -:
//***sss********************************************************************************************
#ifndef __Driver_USBHC_H__
#define __Driver_USBHC_H__

#include <os_types.h>
#include <drv_usb_descr.h>
#include <drv_usbhc.isp176x.h> 
#include <drv_usbhc.upd720150.h> 

//--- HC vendor plug ---------------------------------------------------------
#define USBHC_NO_PLUG                   0
#define USBHC_NEC_PLUG                  1
#define USBHC_ISP_PLUG                  2
//--- HC Driver control command codes ----------------------------------------
#define USBHC_BULK                      0x10000
#define USBHC_START_INTERRUPT           0x10001
#define USBHC_COMPLETE_INTERRUPT        0x10002
#define USBHC_CONFIGURATION             0x10003
//--- Transaction error ------------------------------------------------------
#define USB_HC_ERROR                    0xF
#define USB_ER_NAK                      0x8
#define USB_ER_STALL                    0x4
#define USB_ER_BABBLE                   0x2
#define USB_ER_PID                      0x1
//--- HC Driver structur -----------------------------------------------------
// ---------------------------------------------------------------------------
// !: sn: s_usbhc_irp
// !: sd: ��������� ������� �����-������ ������ ������
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: void*,           data
// !: cd: ��������� �� �����������/������������ ������
// !: sc: uint32,          size
// !: cd: ������ ������
// !: sc: uint16,          device_address
// !: cd: ����� ���������� �� ���� USB
// !: sc: uint16,          device_speed
// !: cd: �������� ����������
// !: sc: uint16,          hub_address
// !: cd: ����� ���������� � ������� hi-speed ���� ��� �� hi-speed ����������
// !: sc: uint16,          port_number
// !: cd: ����� ����� �� hi-speed ����
// !: sc: uint16,          endpoint_number
// !: cd: ����� �������� ���� ����������
// !: sc: uint16,          endpoint_type
// !: cd: ��� �������� �����
// !: sc: uint16,          token
// !: cd: PID ����������
// !: sc: uint16,          max_packet_length
// !: cd: ����� ������ ��� �������� ����� ����������
// !: sc: uint16,          data_toggle
// !: cd: �������� �������� toggle bit ��� �������� �����
// !: sc: uint16,          interval_polling
// !: cd: �������� ��������� ������ �������� �����
// ---------------------------------------------------------------------------
//  I/O Request Packet:
struct  s_usbhc_irp
{
    void*           data;
    uint32          size;
    uint16          device_address;
    uint16          device_speed;
    uint16          hub_address;
    uint16          port_number;
    uint16          endpoint_number;
    uint16          endpoint_type;
    uint16          token;
    uint16          max_packet_length;
    uint16          data_toggle;
    uint16          interval_polling;
};
// ---------------------------------------------------------------------------
// !: sn: s_usbhc_data
// !: sd: ��������� ������ �������������� ���� ������������
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: void*,           data
// !: cd: ��������� �� �����������/������������ ������
// !: sc: uint32,          size
// !: cd: ����� �����
// !: sc: uint32,          count
// !: cd: �������
// ---------------------------------------------------------------------------
// ��������� ������� ��� NEC uPD720150 HC
// �� ������ ������ ������������ ��� ������ � 0EP,
// �.�. ��������� ��� ��������� DATA IN ���� �� ����������
// ������ ������� ������������ ����� ������ � 0EP.
// ---------------------------------------------------------------------------
struct  s_usbhc_data
{
    void*           data;
    int32           size;
    int32           count;
};
// ---------------------------------------------------------------------------
// !: sn: s_usbhc_bulk
// !: sd: �������� ������� USBHC_BULK
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: uint8*,          next_data_toggle
// !: cd: ��������� �� ���������� data toggle, ������� ����� ��������� 
// !: cd: �������� toggle bit �� ��������� ����������
// !: sc: uint32,          temp
// !: cd: ���������� �������������� ��������� HC � �������� ����������
// !: cd: Control Transfer � ������� �������� �����
// !: sc: s_usbhc_irp,     irp
// !: cd: ����� ������� �����-������
// ---------------------------------------------------------------------------
//  Bulk transfet argument:
struct  s_usbhc_bulk
{
    uint8*          next_data_toggle;
    s_usbhc_data    data;
    s_usbhc_irp     irp;
};
// ---------------------------------------------------------------------------
// !: sn: s_usbhc_s_interrupt
// !: sd: �������� ������� USBHC_START_INTERRUPT
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: int32*,          id
// !: cd: ��������� �� ID ����������
// !: sc: int32*,          flag
// !: cd: ��������� �� ���� ��������� ����������
// !: sc: uint32,          sem
// !: cd: ���������� ��������. ����� ������������� �� ���������� ����������
// !: sc: char*,           name
// !: cd: ��������� �� ��� ����������
// !: sc: s_usbhc_irp,     irp
// !: cd: ����� ������� �����-������
// ---------------------------------------------------------------------------
//  Start interrupt transfet argument:
struct  s_usbhc_s_interrupt
{
    int32*          id;     //transaction id
    int32*          flag;   //complete flag
    uint32          sem;    //unlock if sem != NULL
    char*           name;
    s_usbhc_irp     irp;
};
// ---------------------------------------------------------------------------
// !: sn: s_usbhc_c_interrupt
// !: sd: �������� ������� USBHC_COMPLETE_INTERRUPT
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: int32*,          id
// !: cd: ID ���������� ��� ������������� ������
// !: sc: uint8*,          next_data_toggle
// !: cd: ��������� �� ���������� data toggle, ������� ����� ��������� 
// !: cd: �������� toggle bit
// ---------------------------------------------------------------------------
//  Complete interrupt transfet argument:
struct  s_usbhc_c_interrupt
{
    int32           id;     //transaction id
    uint8*          next_data_toggle;
};
// ---------------------------------------------------------------------------
// !: sn: s_usbhc_config
// !: sd: �������� ������� USBHC_CONFIGURATION
// ---------------------------------------------------------------------------
struct s_usbhc_config_endpoint
{
    uint8               endpoint_number;
    uint8               attributes;
    uint16              max_packet_size;
    uint8               interval;
};
struct s_usbhc_config_device
{
    uint16          device_address;
    uint16          device_speed;
    uint16          hub_address;
    uint16          port_number;
    uint16          number_endpoints;
};
struct s_usbhc_config
{
    bool                      connected;
    s_usbhc_config_device     device;
    s_usbhc_config_endpoint*  endpoint;
};
// ---------------------------------------------------------------------------
// !: sn: s_usbhc_config
// !: sd: �������� ������� USBHC_CONFIGURATION
// ---------------------------------------------------------------------------
struct s_usbhc_plug_data
{
    uint32              gpio_number;
};
struct s_usbhc_plug
{
    s_usbhc_plug_data   isp;
    s_usbhc_plug_data   nec;
};

// -- For system calls only ---------------------------------------------------

extern int32     drv_usbhc_plug(s_usbhc_plug* arg, uint32* usbhc_plug);
extern int32     drv_usbhc_unplug();

#endif //__Driver_USBHC_H__

