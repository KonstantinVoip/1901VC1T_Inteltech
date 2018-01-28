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
// !: d: Описание кодов ошибок, внутренних управляющих команд, структур 
// !: d: драйвера ISP 1760/1761 Hi-Speed Universal Serial Bus host controller.
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
// !: sd: Структура запроса ввода-вывода пакета данных
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: void*,           data
// !: cd: указатель на принимаемые/передаваемые данные
// !: sc: uint32,          size
// !: cd: размер данных
// !: sc: uint16,          device_address
// !: cd: адрес устройства на шине USB
// !: sc: uint16,          device_speed
// !: cd: скорость устройства
// !: sc: uint16,          hub_address
// !: cd: адрес последнего в цепочке hi-speed хаба для не hi-speed устройства
// !: sc: uint16,          port_number
// !: cd: номер порта на hi-speed хаба
// !: sc: uint16,          endpoint_number
// !: cd: номер конечной точи устройства
// !: sc: uint16,          endpoint_type
// !: cd: тип конечной точки
// !: sc: uint16,          token
// !: cd: PID транзакции
// !: sc: uint16,          max_packet_length
// !: cd: длина пакета для конечной точки устройства
// !: sc: uint16,          data_toggle
// !: cd: значение текущего toggle bit для конечной точки
// !: sc: uint16,          interval_polling
// !: cd: величина интервала опроса конечной точки
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
// !: sd: Структура данных модифицируемая хост контроллером
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: void*,           data
// !: cd: указатель на принимаемые/передаваемые данные
// !: sc: uint32,          size
// !: cd: общая длина
// !: sc: uint32,          count
// !: cd: счётчик
// ---------------------------------------------------------------------------
// Структура введена для NEC uPD720150 HC
// На данный момент используется при обмене с 0EP,
// т.к. контролер сам разбивает DATA IN этап на транзакции
// равные размеру максимальной длины пакета к 0EP.
// ---------------------------------------------------------------------------
struct  s_usbhc_data
{
    void*           data;
    int32           size;
    int32           count;
};
// ---------------------------------------------------------------------------
// !: sn: s_usbhc_bulk
// !: sd: Аргумент команды USBHC_BULK
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: uint8*,          next_data_toggle
// !: cd: указатель на переменную data toggle, которой будет присвоено 
// !: cd: значение toggle bit по окончании транзакции
// !: sc: uint32,          temp
// !: cd: переменная модифицируемая драйвером HC в процессе выполнения
// !: cd: Control Transfer к нулевой конечной точке
// !: sc: s_usbhc_irp,     irp
// !: cd: пакет запроса ввода-вывода
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
// !: sd: Аргумент команды USBHC_START_INTERRUPT
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: int32*,          id
// !: cd: указатель на ID транзакции
// !: sc: int32*,          flag
// !: cd: указатель на флаг окончания транзакции
// !: sc: uint32,          sem
// !: cd: дескриптор семафора. Будет разблокирован по завершении транзакции
// !: sc: char*,           name
// !: cd: указатель на имя устройства
// !: sc: s_usbhc_irp,     irp
// !: cd: пакет запроса ввода-вывода
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
// !: sd: Аргумент команды USBHC_COMPLETE_INTERRUPT
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: int32*,          id
// !: cd: ID полученный при инициализации обмена
// !: sc: uint8*,          next_data_toggle
// !: cd: указатель на переменную data toggle, которой будет присвоено 
// !: cd: значение toggle bit
// ---------------------------------------------------------------------------
//  Complete interrupt transfet argument:
struct  s_usbhc_c_interrupt
{
    int32           id;     //transaction id
    uint8*          next_data_toggle;
};
// ---------------------------------------------------------------------------
// !: sn: s_usbhc_config
// !: sd: Аргумент команды USBHC_CONFIGURATION
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
// !: sd: Аргумент команды USBHC_CONFIGURATION
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

