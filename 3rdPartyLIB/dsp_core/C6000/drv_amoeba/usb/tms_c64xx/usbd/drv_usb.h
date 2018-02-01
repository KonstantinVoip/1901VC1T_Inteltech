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
// !: d: Описание внутренних управляющих команд, структур драйвера Universal Serial Bus. 
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
//Тип конечной точки
#define EP_CONTROL_TYPE         0x0
#define EP_ISOCHRONOUS_TYPE     0x1
#define EP_BULK_TYPE            0x2
#define EP_INTERRUPT_TYPE       0x3

// ---------------------------------------------------------------------------
// !: sn: s_usb_request
// !: sd: Структура USB запроса к нулевой конечной точки.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: uint8,       request_type
// !: cd: Тип запроса
// !: sc: uint8,       request
// !: cd: Запрос
// !: sc: uint16le,    value
// !: cd: Значение
// !: sc: uint16le,    index
// !: cd: Индекс
// !: sc: uint16le,    length
// !: cd: Длина 
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
// !: sd: Аргумент команды USB_CONTROL_TRANSFER.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: void*,           data
// !: cd: указатель на данные
// !: sc: s_usb_request,   request
// !: cd: структура USB запроса
// ---------------------------------------------------------------------------
// USB device request argument via control pipe:
struct s_usb_control
{
    void*           data;
    s_usb_request   request;
};
// ---------------------------------------------------------------------------
// !: sn: s_usb_bulk
// !: sd: Аргумент команды USB_BULK_TRANSFER.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: void*,           data
// !: cd: указатель на данные
// !: sc: int32,           size
// !: cd: размер данных
// !: sc: int32,           endpoit_number
// !: cd: номер конечной точки
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
// !: sd: Аргумент команды USB_START_INTERRUPT.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: int32*,          id
// !: cd: указатель на ID транзакции
// !: sc: int32*,          flag
// !: cd: указатель на флаг окончания транзакции
// !: sc: uint32,          sem
// !: cd: дескриптор семафора. Будет разблокирован по завершении транзакции
// !: sc: void*,           data
// !: cd: указатель на данные
// !: sc: int32,           size
// !: cd: размер данных
// !: sc: int32,           endpoit_number
// !: cd: номер конечной точки
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
// !: sd: Аргумент команды USB_COMPLETE_INTERRUPT.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: int32,           id
// !: cd: ID полученный при инициализации обмена
// !: sc: int32,           endpoit_number
// !: cd: номер конечной точки
// ---------------------------------------------------------------------------
// USB interrupt transactiont argument:
struct s_usb_c_interrupt
{
	int32           id;
	int32           endpoit_number; 
};
// ---------------------------------------------------------------------------
// !: sn: s_usb_driver_context
// !: sd: Аргумент команды USB_ADD_DEVICE_CLASS.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: int32,                                             device_class
// !: cd: класс USB устройства
// !: sc: int32(*)( s_os_driver_descriptor*, uint16 ),       open_func
// !: cd: указатель на функцию open
// !: sc: int32(*)( s_os_driver_descriptor* ),               close_func
// !: cd: указатель на функцию close
// !: sc: int32(*)( s_os_driver_descriptor*, void*, int32 ), read_func
// !: cd: указатель на функцию read
// !: sc: int32(*)( s_os_driver_descriptor*, const void*, int32 ), write_func
// !: cd: указатель на функцию write
// !: sc: int32(*)( s_os_driver_descriptor*, int32, const void* ), ioctl_func
// !: cd: указатель на функцию ioctl
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
// !: sd: Аргумент передаваемый функции вызываемой при обнаружении 
// !: sd: изменений на шине USB.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: uint8,       connect_event
// !: cd: состояние устройства: 1 - подключено, 0 - отключено
// !: sc: uint8,       interface_class
// !: cd: класс устройства
// !: sc: char[30],    drv_path  
// !: cd: путь к устройству
// !: sc: uin8[n],     data
// !: cd: данные пользователя
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
// !: sd: Аргумент команды USB_DEVICE_ATTACH.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: int (*)(s_usb_attach_func_arg*),     func
// !: cd: указатель на функцию
// !: sc: void*,        data
// !: cd: указатель на данные пользователя, передаваемые в аргумент функции
// !: sc: uint32,       size
// !: cd: размер данных пользователя
// ---------------------------------------------------------------------------
struct s_usb_attach_func
{
    int      (*func)(s_usb_attach_func_arg*);
    void*     data;
    uint32    size;
};
// ---------------------------------------------------------------------------
// !: sn: s_usb_endpoints
// !: sd: Контекст конечной точки передаваемый драйверам USB устройств 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: uint8,        endpoint_number
// !: cd: номер конечной точки
// !: sc: uint8*,       data_toggle
// !: cd: указатель на toggle bit конечной точки
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
// !: sd: Контекст USB устройства передаваемый драйверам USB устройств
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: void*,                       data
// !: cd: указатель на данные
// !: sc: char[32],                    path_usbd
// !: cd: путь к физическому устройству
// !: sc: char[16],                    device_name
// !: cd: имя файла физического устройства
// !: sc: uint8,                       interface_number
// !: cd: количество интерфейсов
// !: sc: uint8,                       interface_class
// !: cd: класс интерфейса
// !: sc: uint8,                       interface_sub_class
// !: cd: подкласс интерфейса
// !: sc: uint8,                       interface_protocol
// !: cd: протокол интерфейса
// !: sc: uint8,                       number_endpoints
// !: cd: количество конечных точек устройства
// !: sc: s_usb_endpoints*,            endpoint
// !: cd: указатель на таблицу контекстов конечных точек
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


