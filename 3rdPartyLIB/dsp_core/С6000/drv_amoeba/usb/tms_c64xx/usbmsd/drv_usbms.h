//**************************************************************************************************
//                         Copyright (C) 2009 RCZI
//--------------------------------------------------------------------------------------------------
// FILENAME....... drv_usbms.h
// DATE CREATED... 10/12/2009
// LAST MODIFIED.. 10/12/2009
// DRIVER VERSION. 0.1
//-------------------------------------------------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
//
// !: codepage: cp1251 
//
// !: d: �������� ����� ������, ���������� ����������� ������, �������� 
// !: d: �������� USB Mass Storage Device Class.
// !: -:
//***sss********************************************************************************************/
#ifndef		__Driver_USB_Mass_Storage_Class_H__
#define		__Driver_USB_Mass_Storage_Class_H__
#include    <os_driver.h>
#include	<drv_usb.h>
//--- MSD Driver control command codes ---------------------------------------
#define MSD_WRITE                   0x10001
#define MSD_READ                    0x10002
#define MSD_CAPACITY                0x10003
#define MSD_VENDOR                  0x10004
#define MSD_DEVICE_NAME             0x10005
#define MSD_CHECK_MEDIA_CHANGE      0x10006
#define MSD_CLEAR_MEDIA_CHANGE      0x10007

//--- MSD Driver error code ---------------------------------------------------
#define MSD_ER_BASE                 -10000

//--- Bulk-only transport protocol errors ------------------------------------
#define BOT_ER_CMD_FAILED           0x0010
#define BOT_ER_PHASE_STATUS         0x0020

//--- MSD Driver structur ----------------------------------------------------
// ---------------------------------------------------------------------------
// !: sn: s_msd_io
// !: sd: �������� ������� MSD_WRITE / MSD_READ.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: void*,  data
// !: cd: ��������� �� ������
// !: sc: uint32, size
// !: cd: ���������� ������������ ���������� ������
// !: sc: uint32, lba
// !: cd: ����� ���������� ����������� �����
// ---------------------------------------------------------------------------
struct s_msd_io
{
    void*       data;
    uint32      size;
    uint32      lba;
};
// ---------------------------------------------------------------------------
// !: sn: s_msd_capacity
// !: sd: �������� ������� MSD_CAPACITY.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: uint32,      last_lba
// !: cd: ����� ���������� ����������� �����
// !: sc: uint32,      block_length
// !: cd: ������ ������ ����� � ������
// !: sc: uint64,      flash_capacity
// !: cd: ������� ���� � ������
// ---------------------------------------------------------------------------
struct s_msd_capacity
{
    uint32      last_lba;        
    uint32      block_length;
    uint64      flash_capacity;              
};
// ---------------------------------------------------------------------------
// !: sn: s_msd_vendor
// !: sd: �������� ������� MSD_VENDOR.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: char[10],        vendor_identification
// !: cd: �������������
// !: sc: char[17],        product_identification
// !: cd: �������
// !: sc: char[5],         product_revision_level
// !: cd: �������
// ---------------------------------------------------------------------------
struct s_msd_vendor
{
    char        vendor_identification[10];
    char        product_identification[17];
    char        product_revision_level[5];
};
//--- For system calls only --------------------------------------------------
extern int32 usbms_open(s_os_driver_descriptor* d, uint16 access);
extern int32 usbms_close(s_os_driver_descriptor* d);
extern int32 usbms_read(s_os_driver_descriptor* d, void* buf, int32 length);
extern int32 usbms_write(s_os_driver_descriptor* d, const void* buf, int32 length);
extern int32 usbms_ioctl(s_os_driver_descriptor* d, int32 cmd, const void* arg);
#endif //__Driver_USB_Mass_Storage_Class_H__


