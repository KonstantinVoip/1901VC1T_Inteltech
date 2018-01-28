//**************************************************************************************************
//                         Copyright (C) 2009 RCZI
//--------------------------------------------------------------------------------------------------
// FILENAME....... drv_usb.h
// DATE CREATED... 23/11/2009
// LAST MODIFIED.. 23/11/2009
// DRIVER VERSION. 1.0
//--------------------------------------------------------------------------------------------------
//                       UNIVERSAL SERIAL BUS DRIVER
//-------------------------------------------------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
//
// !: codepage: cp1251 
//
// !: d: �������� ���������� ����������� ������, �������� �������� Universal Serial Bus. 
// !: -:
//***sss********************************************************************************************
#ifndef     __Driver_USB_H__
#define     __Driver_USB_H__

#include    <os_driver.h>
#include    <drv_usbhc.h>

//=== USB Driver control command codes =======================================
#define USB_CONTROL_TRANSFER                    0x10000
#define USB_BULK_TRANSFER                       0x10001
#define USB_START_INTERRUPT                     0x10002
#define USB_COMPLETE_INTERRUPT                  0x10003
#define USB_ADD_DEVICE_CLASS                    0x10010
#define USB_REMOVE_DEVICE_CLASS                 0x10020
#define USB_DEVICE_ATTACH                       0x10100

//=== USB Driver structur ====================================================
//��� �������� �����
#define EP_CONTROL_TYPE         0x0
#define EP_ISOCHRONOUS_TYPE     0x1
#define EP_BULK_TYPE            0x2
#define EP_INTERRUPT_TYPE       0x3

// ---------------------------------------------------------------------------
// !: sn: s_usb_request
// !: sd: ��������� USB ������� � ������� �������� �����.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: uint8,       request_type
// !: cd: ��� �������
// !: sc: uint8,       request
// !: cd: ������
// !: sc: uint16le,    value
// !: cd: ��������
// !: sc: uint16le,    index
// !: cd: ������
// !: sc: uint16le,    length
// !: cd: ����� 
// ---------------------------------------------------------------------------
struct s_usb_request
{
    uint8       request_type;
    uint8       request;
    uint16le    value;
    uint16le    index;
    uint16le    length;
};
// ---------------------------------------------------------------------------
// !: sn: s_usb_control
// !: sd: �������� ������� USB_CONTROL_TRANSFER.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: void*,           data
// !: cd: ��������� �� ������
// !: sc: s_usb_request,   request
// !: cd: ��������� USB �������
// ---------------------------------------------------------------------------
// USB device request argument via control pipe:
struct s_usb_control
{
    void*           data;
    s_usb_request   request;
};
// ---------------------------------------------------------------------------
// !: sn: s_usb_bulk
// !: sd: �������� ������� USB_BULK_TRANSFER.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: void*,           data
// !: cd: ��������� �� ������
// !: sc: int32,           size
// !: cd: ������ ������
// !: sc: int32,           endpoit_number
// !: cd: ����� �������� �����
// ---------------------------------------------------------------------------
// USB bulk transactiont argument:
struct s_usb_bulk
{
    void*           data; 
    int32           size;
    int32           endpoit_number;
};
// ---------------------------------------------------------------------------
// !: sn: s_usb_s_interrupt
// !: sd: �������� ������� USB_START_INTERRUPT.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: int32*,          id
// !: cd: ��������� �� ID ����������
// !: sc: int32*,          flag
// !: cd: ��������� �� ���� ��������� ����������
// !: sc: uint32,          sem
// !: cd: ���������� ��������. ����� ������������� �� ���������� ����������
// !: sc: void*,           data
// !: cd: ��������� �� ������
// !: sc: int32,           size
// !: cd: ������ ������
// !: sc: int32,           endpoit_number
// !: cd: ����� �������� �����
// ---------------------------------------------------------------------------
// USB interrupt transactiont argument:
struct s_usb_s_interrupt
{
    int32*          id;
    int32*          flag;
    uint32          sem; 
    void*           data; 
    int32           size;
    int32           endpoit_number;
};
// ---------------------------------------------------------------------------
// !: sn: s_usb_c_interrupt
// !: sd: �������� ������� USB_COMPLETE_INTERRUPT.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: int32,           id
// !: cd: ID ���������� ��� ������������� ������
// !: sc: int32,           endpoit_number
// !: cd: ����� �������� �����
// ---------------------------------------------------------------------------
// USB interrupt transactiont argument:
struct s_usb_c_interrupt
{
	int32           id;
	int32           endpoit_number; 
};
// ---------------------------------------------------------------------------
// !: sn: s_usb_driver_context
// !: sd: �������� ������� USB_ADD_DEVICE_CLASS.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: int32,                                             device_class
// !: cd: ����� USB ����������
// !: sc: int32(*)( s_os_driver_descriptor*, uint16 ),       open_func
// !: cd: ��������� �� ������� open
// !: sc: int32(*)( s_os_driver_descriptor* ),               close_func
// !: cd: ��������� �� ������� close
// !: sc: int32(*)( s_os_driver_descriptor*, void*, int32 ), read_func
// !: cd: ��������� �� ������� read
// !: sc: int32(*)( s_os_driver_descriptor*, const void*, int32 ), write_func
// !: cd: ��������� �� ������� write
// !: sc: int32(*)( s_os_driver_descriptor*, int32, const void* ), ioctl_func
// !: cd: ��������� �� ������� ioctl
// ---------------------------------------------------------------------------
// Add device class argument:
struct s_usb_driver_context
{
    int32       device_class;
    int32       (*open_func)( s_os_driver_descriptor*, uint16 );
    int32       (*close_func)( s_os_driver_descriptor* );
    int32       (*read_func)( s_os_driver_descriptor*, void*, int32 );
    int32       (*write_func)( s_os_driver_descriptor*, const void*, int32 ); 
    int32       (*ioctl_func)( s_os_driver_descriptor*, int32, const void* );
};
// ---------------------------------------------------------------------------
// !: sn: s_usb_attach_func_arg
// !: sd: �������� ������������ ������� ���������� ��� ����������� 
// !: sd: ��������� �� ���� USB.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: uint8,       connect_event
// !: cd: ��������� ����������: 1 - ����������, 0 - ���������
// !: sc: uint8,       interface_class
// !: cd: ����� ����������
// !: sc: char[30],    drv_path  
// !: cd: ���� � ����������
// !: sc: uin8[n],     data
// !: cd: ������ ������������
// ---------------------------------------------------------------------------
// Device attach function argument:
struct s_usb_attach_func_arg
{
    uint8                       connect_event;
    uint8                       interface_class;    
    char                        drv_path[30];
};
// ---------------------------------------------------------------------------
// !: sn: s_usb_attach_func
// !: sd: �������� ������� USB_DEVICE_ATTACH.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: int (*)(s_usb_attach_func_arg*),     func
// !: cd: ��������� �� �������
// !: sc: void*,        data
// !: cd: ��������� �� ������ ������������, ������������ � �������� �������
// !: sc: uint32,       size
// !: cd: ������ ������ ������������
// ---------------------------------------------------------------------------
struct s_usb_attach_func
{
    int      (*func)(s_usb_attach_func_arg*);
    void*     data;
    uint32    size;
};
// ---------------------------------------------------------------------------
// !: sn: s_usb_endpoints
// !: sd: �������� �������� ����� ������������ ��������� USB ��������� 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: uint8,        endpoint_number
// !: cd: ����� �������� �����
// !: sc: uint8*,       data_toggle
// !: cd: ��������� �� toggle bit �������� �����
// ---------------------------------------------------------------------------
// Endpoints context for device class driver context structur:
struct s_usb_endpoints
{
    uint8                       endpoint_number;
    uint8                       attributes;
    uint8*                      data_toggle;
};
// ---------------------------------------------------------------------------
// !: sn: s_usb_class_driver_context
// !: sd: �������� USB ���������� ������������ ��������� USB ���������
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: void*,                       data
// !: cd: ��������� �� ������
// !: sc: char[32],                    path_usbd
// !: cd: ���� � ����������� ����������
// !: sc: char[16],                    device_name
// !: cd: ��� ����� ����������� ����������
// !: sc: uint8,                       interface_number
// !: cd: ���������� �����������
// !: sc: uint8,                       interface_class
// !: cd: ����� ����������
// !: sc: uint8,                       interface_sub_class
// !: cd: �������� ����������
// !: sc: uint8,                       interface_protocol
// !: cd: �������� ����������
// !: sc: uint8,                       number_endpoints
// !: cd: ���������� �������� ����� ����������
// !: sc: s_usb_endpoints*,            endpoint
// !: cd: ��������� �� ������� ���������� �������� �����
// ---------------------------------------------------------------------------
// Device class driver context structur:
struct s_usb_class_driver_context
{
    void*                       data;       
    char                        path_usbd[32];
    char                        device_name[16];
    uint8                       config_value;
    uint8                       interface_number;
    uint8                       interface_class;
    uint8                       interface_sub_class;
    uint8                       interface_protocol;
    uint8                       number_endpoints;
    s_usb_endpoints*            endpoint;
};
//=== For system calls only ==================================================
extern int32     drv_usb_plug();
extern int32     drv_usb_unplug();

#endif //__Driver_USB_H__


