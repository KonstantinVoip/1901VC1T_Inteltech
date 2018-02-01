//**************************************************************************************************\
//                         Copyright (C) 2009 RCZI
//--------------------------------------------------------------------------------------------------
// FILENAME....... drv_usb_descr.h
// DATE CREATED... 25/11/2009
//-------------------------------------------------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
//
// !: codepage: cp1251 
//
// !: d: �������� ���������� ��������� �������� � ���������������� ��������.
// !: d: �������� Universal Serial Bus.
// !: -:
//***sss********************************************************************************************
#ifndef __USB_Descriptors_H__
#define __USB_Descriptors_H__

#include <os_types.h>
#include <os_utils.h>

/**************************************************************************************************\
*   ������ USB ���������
\***sss********************************************************************************************/
#define USB_DEVICE_CLASS_RESERVED                       0x00
#define USB_DEVICE_CLASS_AUDIO                          0x01
#define USB_DEVICE_CLASS_COMMUNICATIONS                 0x02
#define USB_DEVICE_CLASS_HUMAN_INTERFACE                0x03
#define USB_DEVICE_CLASS_MONITOR                        0x04
#define USB_DEVICE_CLASS_PHYSICAL_INTERFACE             0x05
#define USB_DEVICE_CLASS_POWER                          0x06
#define USB_DEVICE_CLASS_PRINTER                        0x07
#define USB_DEVICE_CLASS_STORAGE                        0x08
#define USB_DEVICE_CLASS_HUB                            0x09
#define USB_DEVICE_CLASS_VENDOR_SPECIFIC                0xFF

/**************************************************************************************************\
*   ����������� ����������� ����������
\***sss********************************************************************************************/
//===== ����� ���� ���� ������� ===========================
// Data transfer direction:
#define USB_REQUEST_TYPE_HOST_DEV                       0x00
#define USB_REQUEST_TYPE_DEV_HOST                       0x80
// Type:                                                
#define USB_REQUEST_TYPE_STANDARD                       0x00
#define USB_REQUEST_TYPE_CLASS                          0x20
#define USB_REQUEST_TYPE_VENDOR                         0x40
// Recipient:
#define USB_REQUEST_TYPE_DEVICE                         0x00
#define USB_REQUEST_TYPE_INTERFACE                      0x01
#define USB_REQUEST_TYPE_ENDPOINT                       0x02
#define USB_REQUEST_TYPE_OTHER                          0x03

//===== ���� ����������� �������� =========================
#define USB_REQUEST_GET_STATUS                          0x0 //����������� ��������� ����������
#define USB_REQUEST_CLEAR_FEATURE                       0x1 //����� ����������
#define USB_REQUEST_SET_FEATURE                         0x3 //��������� �������
#define USB_REQUEST_SET_ADDRESS                         0x5 //��������� ������
#define USB_REQUEST_GET_DESCRIPTOR                      0x6 //�������� ����������
#define USB_REQUEST_SET_DESCRIPTOR                      0x7 //���������� ����������
#define USB_REQUEST_GET_CONFIGURATION                   0x8 //�������� ������������
#define USB_REQUEST_SET_CONFIGURATION                   0x9 //���������� ������������
#define USB_REQUEST_GET_INTERFACE                       0xA //�������� ���������
#define USB_REQUEST_SET_INTERFACE                       0xB //���������� ���������
#define USB_REQUEST_SYNCH_FRAME                         0xC //���� �������������

//===== ���� ������������ =================================
#define USB_DEVICE_DESCRIPTOR_TYPE                      0x1
#define USB_CONFIGURATION_DESCRIPTOR_TYPE               0x2
#define USB_STRING_DESCRIPTOR_TYPE                      0x3
#define USB_INTERFACE_DESCRIPTOR_TYPE                   0x4
#define USB_ENDPOINT_DESCRIPTOR_TYPE                    0x5
#define USB_DEVICE_QUALIFIER_DESCRIPTOR_TYPE            0x6
#define USB_OTHER_SPEED_CONFIGURATION_DESCRIPTOR_TYPE   0x7
#define USB_INTERFACE_POWER1_DESCRIPTOR_TYPE            0x8

//===== Standard Feature Selectors ========================
#define FEATURE_DEVICE_REMOTE_WAKEUP                    0x1//Device 
#define FEATURE_ENDPOINT_HALT                           0x0//Endpoint
#define FEATURE_TEST_MODE                               0x2//Device 

/**************************************************************************************************\
*   �����, ��������� ������������
\***sss********************************************************************************************/
// Transaction type:
#define USB_TRANSFER_TYPE_MASK                          0x3
#define USB_CONTROL_TYPE                                0x0
#define USB_ISOCHRONOUS_TYPE                            0x1
#define USB_BULK_TYPE                                   0x2
#define USB_INTERRUPT_TYPE                              0x3
// Transaction direction::
#define ENDPOINT_DIRECTION_MASK                         0x80
#define ENDPOINT_IN                                     0x80
#define ENDPOINT_OUT                                    0x00
// Transaction token:
#define USB_OUT_TOKEN                                    0x0
#define USB_IN_TOKEN                                     0x1
#define USB_SETUP_TOKEN                                  0x2
// USB device speed:
#define USB_LOW_SPEED                                    0x01
#define USB_FULL_SPEED                                   0x00
#define USB_HI_SPEED                                     0x02

// ---------------------------------------------------------------------------
// !: sn: s_standard_divice_descriptor
// !: sd: ����������� ���������� USB ����������.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: uint8,          length
// !: cd: ����� �����������
// !: sc: uint8,          descriptor_type
// !: cd: ��� �����������
// !: sc: uint16le,       bcd_usb
// !: cd: ������ USB
// !: sc: uint8,                  device_class
// !: cd: ����� ����������
// !: sc: uint8,          device_sub_class
// !: cd: �������� ����������
// !: sc: uint8,          device_protocol 
// !: cd: �������� ����������
// !: sc: uint8,          max_packet_size_0
// !: cd: ������������ ������ ������ ������������ ������� �������� �����
// !: sc: uint16le,               id_vendor
// !: cd: ��� �������������
// !: sc: uint16le,               id_product
// !: cd: ��� ��������
// !: sc: uint16le,               id_device 
// !: cd: ��� ����������
// !: sc: uint8,          manufacturer
// !: cd: ������������
// !: sc: uint8,          product
// !: cd: �������
// !: sc: uint8,          serial_number
// !: cd: �������� �����
// !: sc: uint8,          num_configurations
// !: cd: ���������� ������������ ����������
// ---------------------------------------------------------------------------
struct s_standard_device_descriptor
{
    uint8            length;
    uint8            descriptor_type;
    uint16le         bcd_usb; 
    uint8            device_class; 
    uint8            device_sub_class; 
    uint8            device_protocol; 
    uint8            max_packet_size_0; 
    uint16le         id_vendor; 
    uint16le         id_product; 
    uint16le         id_device; 
    uint8            manufacturer;
    uint8            product;
    uint8            serial_number;
    uint8            num_configurations;
};
// ---------------------------------------------------------------------------
// !: sn: s_device_qualifier_descriptor
// !: sd: �������������� ���������� USB ����������.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: uint8,            length
// !: cd: ����� �����������
// !: sc: uint8,            descriptor_type
// !: cd: ��� �����������
// !: sc: uint16le,         bcd_usb
// !: cd: ������ USB
// !: sc: uint8,            device_class
// !: cd: ����� ����������
// !: sc: uint8,            device_sub_class
// !: cd: �������� ����������
// !: sc: uint8,            device_protocol
// !: cd: �������� ����������
// !: sc: uint8,            max_packet_size_0
// !: cd: ������������ ������ ������ ������������ ������� �������� �����
// !: sc: uint8,            num_configurations
// !: cd: ���������� ������������ ����������
// !: sc: uint8,            reserved
// !: cd: ��������������
// ---------------------------------------------------------------------------
struct s_device_qualifier_descriptor
{
    uint8            length;
    uint8            descriptor_type;
    uint16le         bcd_usb; 
    uint8            device_class; 
    uint8            device_sub_class;
    uint8            device_protocol; 
    uint8            max_packet_size_0;
    uint8            num_configurations;
    uint8            reserved;
};
// ---------------------------------------------------------------------------
// !: sn: s_standard_configuration_descriptor
// !: sd: ����������� ���������� ������������ USB ����������.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: uint8,            length
// !: cd: ����� �����������
// !: sc: uint8,            descriptor_type
// !: cd: ��� �����������
// !: sc: uint16le,         total_length
// !: cd: ����� ����� ��������� ������������
// !: sc: uint8,            num_interfaces
// !: cd: ���������� �����������
// !: sc: uint8,            configuration_value
// !: cd: ���������������� �������� ������������ ��� ��������� ������ �����������
// !: sc: uint8,            configuration
// !: cd: ������ ���������� ����������� ������������ ��� ������������
// !: sc: uint8,            attributes
// !: cd: �������������� ������������
// !: sc: uint8,            max_power
// !: cd: ����������� ������������ ��������
// ---------------------------------------------------------------------------
struct s_standard_configuration_descriptor
{
    uint8            length;
    uint8            descriptor_type;
    uint16le         total_length;
    uint8            num_interfaces; 
    uint8            configuration_value;
    uint8            configuration; 
    uint8            attributes;
    uint8            max_power;
};
// ---------------------------------------------------------------------------
// !: sn: s_other_speed_configuration_descriptor
// !: sd: ���������� ������������ Hi-Speed USB ����������
// !: sd: ����������� �� ������ ��������
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: uint8,            length
// !: cd: ����� �����������
// !: sc: uint8,            descriptor_type
// !: cd: ��� �����������
// !: sc: uint16le,         total_length
// !: cd: ����� ����� ��������� ������������
// !: sc: uint8,            num_interfaces
// !: cd: ���������� �����������
// !: sc: uint8,            configuration_value
// !: cd: ���������������� �������� ������������ ��� ��������� ������ �����������
// !: sc: uint8,            configuration
// !: cd: ������ ���������� ����������� ������������ ��� ������������
// !: sc: uint8,            attributes
// !: cd: �������������� ������������
// !: sc: uint8,            max_power
// !: cd: ����������� ������������ ��������
// ---------------------------------------------------------------------------
struct s_other_speed_configuration_descriptor
{
    uint8            length;        
    uint8            descriptor_type;
    uint16le         total_length;
    uint8            num_interfaces; 
    uint8            configuration_value;
    uint8            configuration; 
    uint8            attributes;
    uint8            max_power;
};
// ---------------------------------------------------------------------------
// !: sn: s_standard_interface_descriptor
// !: sd: ����������� ���������� ���������� USB ����������
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: uint8,            length
// !: cd: ����� �����������
// !: sc: uint8,            descriptor_type
// !: cd: ��� �����������
// !: sc: uint8,            interface_number
// !: cd: ����� ����������
// !: sc: uint8,            alternate_setting
// !: cd: ������������� ���������
// !: sc: uint8,            number_endpoints
// !: cd: ���������� �������� �����
// !: sc: uint8,            interface_class
// !: cd: ����� ����������
// !: sc: uint8,            interface_sub_class
// !: cd: �������� ����������
// !: sc: uint8,            interface_protocol
// !: cd: �������� ����������
// !: sc: uint8,            iinterface
// !: cd: ������ ���������� ����������� ������������ ���� ���������
// ---------------------------------------------------------------------------
struct s_standard_interface_descriptor
{
    uint8            length;
    uint8            descriptor_type;
    uint8            interface_number;
    uint8            alternate_setting;
    uint8            number_endpoints;
    uint8            interface_class;
    uint8            interface_sub_class;
    uint8            interface_protocol;
    uint8            iinterface;
};
// ---------------------------------------------------------------------------
// !: sn: s_standard_endpoint_descriptor
// !: sd: ����������� ���������� �������� ����� USB ����������
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: uint8,            length
// !: cd: ����� �����������
// !: sc: uint8,            descriptor_type
// !: cd: ��� �����������
// !: sc: uint8,            endpoint_number
// !: cd: ����� �������� �����
// !: sc: uint8,            attributes
// !: cd: �������� �������� �����
// !: sc: uint16le,         max_packet_size
// !: cd: ������������ ����� ������ ������������ �������� �����
// !: sc: uint8,            interval
// !: cd: �������� ������ �������� �����
// ---------------------------------------------------------------------------
struct s_standard_endpoint_descriptor
{
    uint8            length;
    uint8            descriptor_type;
    uint8            endpoint_number;
    uint8            attributes;
    uint16le         max_packet_size;
    uint8            interval;
};
/**************************************************************************************************\
*   ����������� ����
\***sss********************************************************************************************/
//===== ���� ������������ =================================
#define USB_HUB_DESCRIPTOR_TYPE             0x29
//===== ���� �������� ���� ================================
#define USB_REQUEST_HUB_CLEAR_TT_BUFFER     0x08
#define USB_REQUEST_HUB_RESET_TT            0x09
#define USB_REQUEST_HUB_GET_TT_STATE        0x0A
#define USB_REQUEST_HUB_STOP_TT             0x0B

//===== �������� �������� ���� ============================
#define FEATURE_C_HUB_LOCAL_POWER           0x0000
#define FEATURE_C_HUB_OVER_CURRENT          0x0001
//===== �������� �������� ����� ===========================
    //--- ��� SetPortFeature � ClearPortFeature ---
#define FEATURE_PORT_CONNECTION             0x0000
#define FEATURE_PORT_ENABLE                 0x0001
#define FEATURE_PORT_SUSPEND                0x0002
#define FEATURE_PORT_OVER_CURRENT           0x0003
#define FEATURE_PORT_RESET                  0x0004
#define FEATURE_PORT_POWER                  0x0008
#define FEATURE_PORT_LOW_SPEED              0x0009
    //--- ��� ClearPortFeature ---
#define FEATURE_C_PORT_CONNECTION           0x0010 
#define FEATURE_C_PORT_ENABLE               0x0011
#define FEATURE_C_PORT_SUSPEND              0x0012
#define FEATURE_C_PORT_OVER_CURRENT         0x0013
#define FEATURE_C_PORT_RESET                0x0014
#define FEATURE_PORT_TEST                   0x0015
#define FEATURE_INDICATOR                   0x0016

//===== Hub Port status bits ==============================
#define PORT_CONNECTION                     0x0001
#define PORT_ENABLE                         0x0002
#define PORT_SUSPEND                        0x0004
#define PORT_OVER_CURRENT                   0x0008
#define PORT_RESET                          0x0010
#define PORT_PORT_POWER                     0x0100
#define PORT_LOW_SPEED                      0x0200
#define PORT_HIGH_SPEED                     0x0400
#define PORT_TEST                           0x0800
#define PORT_INDICATOR                      0x1000

#define PORT_SPEED_MASK                     0x0600

// ---------------------------------------------------------------------------
// !: sn: s_hub_descriptor
// !: sd: ���������� USB ����
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: uint8,            length
// !: cd: ����� �����������
// !: sc: uint8,            descriptor_type
// !: cd: ��� �����������
// !: sc: uint8,            number_ports
// !: cd: ���������� ������ ����
// !: sc: uint16le,         hub_characteristics
// !: cd: �������������� ����
// !: sc: uint8,            pwr_on_2_pwr_good
// !: cd: ����� ���������� ������� �� ����� �� ������ ����
// !: sc: uint8,            hub_contr_current
// !: cd: ����������� ����������� ��� ��� ���� � ��
// !: sc: uint8,            device_removable
// !: cd: ����������� ������� �� ������ ���� ����������� ���������
// !: sc: uint8,            port_pwr_ctrl_mask
// !: cd: ��������������
// ---------------------------------------------------------------------------
struct s_hub_descriptor
{
    uint8            length;
    uint8            descriptor_type;
    uint8            number_ports;
    uint16le         hub_characteristics;
    uint8            pwr_on_2_pwr_good;
    uint8            hub_contr_current;
    uint8            device_removable;
    uint8            port_pwr_ctrl_mask;
};
// ---------------------------------------------------------------------------
// !: sn: s_hub_status
// !: sd: ��������� ������ ���������� ��� ������� ������� ����
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: uint16le,           hub_status
// !: cd: ������� ��������� ����
// !: sc: uint16le,           hub_change
// !: cd: ��������� ��������� ����
// ---------------------------------------------------------------------------
struct s_hub_status 
{
    uint16le           hub_status;
    uint16le           hub_change;
};
// ---------------------------------------------------------------------------
// !: sn: s_hub_port_status
// !: sd: ��������� ������ ���������� ��� ������� ������� ����� ����
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: uint16le,           port_status
// !: cd: ������� ��������� ����� ����
// !: sc: uint16le,           port_change
// !: cd: ��������� ��������� ����� ����
// ---------------------------------------------------------------------------
struct s_hub_port_status 
{
    uint16le           port_status;
    uint16le           port_change;
};
/**************************************************************************************************\
*   ����������� HID
\***sss********************************************************************************************/
//===== ���� ������������ =================================
#define USB_HID_DESCRIPTOR_TYPE                         0x21
#define USB_HID_REPORT_DESCRIPTOR_TYPE                  0x22
#define USB_HID_PHYSICAL_DESCRIPTOR_TYPE                0x23
//===== ���� �������� HID =================================
#define USB_REQUEST_HID_GET_REPORT                      0x01
#define USB_REQUEST_HID_GET_IDLE                        0x02
#define USB_REQUEST_HID_GET_PROTOCOL                    0x03
#define USB_REQUEST_HID_SET_REPORT                      0x09
#define USB_REQUEST_HID_SET_IDLE                        0x0A
#define USB_REQUEST_HID_SET_PROTOCOL                    0x0B
//===== ���� �������� HID =================================
#define USB_HID_REPORT_TYPE_INPUT                       0x01
#define USB_HID_REPORT_TYPE_OUTPUT                      0x02
#define USB_HID_REPORT_TYPE_FEATURE                     0x03
//===== ��������� HID ��������� ===========================
#define USB_HID_USER_PROTOCOL                           0x00
#define USB_HID_KEYBOARD_PROTOCOL                       0x01
#define USB_HID_MOUSE_PROTOCOL                          0x02
//===== ����� HID ��������� ===============================
#define USB_HID_CLASS_BOOT_PROTOCOL                     0x00
#define USB_HID_CLASS_REPORT_PROTOCOL                   0x01

// ---------------------------------------------------------------------------
// !: sn: s_hid_descriptor
// !: sd: HID ����������
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: uint8,            length
// !: cd: 
// !: sc: uint8,            descriptor_type
// !: cd: 
// !: sc: uint16le,         cd_hid
// !: cd: 
// !: sc: uint8,            country_code
// !: cd: 
// !: sc: uint8,            num_descriptor
// !: cd: 
// !: sc: uint8,            report_type
// !: cd: 
// !: sc: uint16le,         report_length
// !: cd: 
// ---------------------------------------------------------------------------
struct s_hid_descriptor 
{
    uint8            length;
    uint8            descriptor_type;
    uint16le         cd_hid;
    uint8            country_code;
    uint8            num_descriptor;
    uint8            report_type;
    uint16le         report_length;
};

#endif //__USB_Descriptors_H__

