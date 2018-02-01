//**************************************************************************************************
//                         Copyright (C) 2009 RCZI
//--------------------------------------------------------------------------------------------------
// FILENAME....... drv_gpio.h
//--------------------------------------------------------------------------------------------------
//                               ������� GPIO
//-------------------------------------------------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
//
// !: codepage: cp1251 
//
// !: d: �������� ����� ������, ���������� ����������� ������, �������� 
// !: d: �������� GPIO.
// !: -:
//***sss********************************************************************************************/
#ifndef     __Driver_GPIO_H__
#define     __Driver_GPIO_H__
#include    <os_ioctl.h>
#include    <os_types.h>

//--- GPIO Driver control command codes ----------------------------------------
#define GPIO_LOAD_PLIS          ( GPIO__USER__ + 0 )
#define GPIO_RESET_PLIS         ( GPIO__USER__ + 1 )

//--- GPIO Driver structur -----------------------------------------------------
// ---------------------------------------------------------------------------
// !: sn: s_gpio_start_value
// !: sd: ��������� �������� GPIO
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: int32,       reg_gpen
// !: cd: GPEN
// !: sc: int32,       reg_gpdir
// !: cd: GPDIR
// !: sc: int32,       reg_gpval
// !: cd: GPVAL
// ---------------------------------------------------------------------------
struct s_gpio_start_value
{
    int32   reg_gpen;
    int32   reg_gpdir;
    int32   reg_gpval;
};
// ---------------------------------------------------------------------------
// !: sn: s_gpio_interrupt
// !: sd: �������� ������� GPIO_INT_ALLOC/GPIO_INT_FREE
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: int32,       number_gpio
// !: cd: ����� GPIO
// !: sc: void(*)(),   call_functoin
// !: cd: ����� ���������� �������
// ---------------------------------------------------------------------------
struct s_gpio_interrupt
{
    int32   number_gpio;
    void    (*call_functoin)();         
};
// ---------------------------------------------------------------------------
// !: sn: s_gpio_operation
// !: sd: �������� ������� GPIO_PULL/GPIO_VALUE
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: int32,       number_gpio
// !: cd: ����� GPIO
// !: sc: int32,       value_gpio
// !: cd: �������� GPIO
// ---------------------------------------------------------------------------
struct s_gpio_operation
{
    int32   number_gpio;
    int32   value_gpio;
};
// ---------------------------------------------------------------------------
// !: sn: s_gpio_load_plis
// !: sd: �������� ������� GPIO_LOAD_PLIS
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: void*,   data
// !: cd: ��������� �� ������
// !: sc: int32,   size
// !: cd: ������ ������
// !: sc: int32,   gpio_prog
// !: cd: ����� GPIO
// !: sc: int32,   gpio_init
// !: cd: ����� GPIO
// !: sc: int32,   gpio_clk
// !: cd: ����� GPIO
// !: sc: int32,   gpio_dout
// !: cd: ����� GPIO
// !: sc: int32,   gpio_done
// !: cd: ����� GPIO
// !: sc: int32,   gpio_switch
// !: cd: ����� GPIO
// ---------------------------------------------------------------------------
struct s_gpio_load_plis
{
    void*   data;
    int32   size;
    int32   gpio_prog;
    int32   gpio_init;
    int32   gpio_clk;
    int32   gpio_dout;
    int32   gpio_done;
    int32   gpio_switch;
};

// -- For system calls only ---------------------------------------------------
extern int32    drv_gpio_plug(s_gpio_start_value*);
extern int32    drv_gpio_unplug();

#endif //__Driver_GPIO_H__

