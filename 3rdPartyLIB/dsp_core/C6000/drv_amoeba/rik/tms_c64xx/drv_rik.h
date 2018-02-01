//**************************************************************************************************
//                         Copyright (C) 2009 RCZI
//--------------------------------------------------------------------------------------------------
// FILENAME....... drv_rik.h
// DATE CREATED... 05/10/2009
// LAST MODIFIED.. 21/12/2009
// DRIVER VERSION. 1.0
//--------------------------------------------------------------------------------------------------
//                  ДРАЙВЕР РОССИЙСКОЙ ИНТЕЛЛЕКТУАЛЬНОЙ КАРТЫ
//-------------------------------------------------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
//
// !: codepage: cp1251 
//
// !: d: Описание кодов ошибок, внутренних управляющих команд, структур 
// !: d: драйвера РИК.
// !: -:
//**************************************************************************************************
#ifndef     __Driver_Rik_H__
#define     __Driver_Rik_H__
#include    <os_types.h>

//--- RIK Driver control command codes ----------------------------------------
#define RIK_USER_INT_FUNC           0x10000
#define RIK_SET_ZONE                0x10001
#define RIK_SET_OFFSET              0x10002
#define RIK_GET_RESET_STRUCT        0x10003
#define RIK_VERIFY_PASSWORD         0x10004
#define RIK_CHANGE_PASSWORD         0x10005
#define RIK_UNLOCK_CARD             0x10006
#define RIK_CHECK_DOOR              0x10007
#define RIK_ERRNO                   0x10008

//--- RIK Driver error code ---------------------------------------------------
#define RIK_ER_UNKNOWN              0x7001       //неизвестная команда        
#define RIK_ER_PARITY               0x7010       //ошибка четности РИК    
#define RIK_ER_TIMEOUT              0x7011       //ошибка таймаута РИК
#define RIK_ER_DATA                 0x7012       //недопустимые данные
#define RIK_ER_NO_CARD              0x7013       //карточка отсутствует   
#define RIK_ER_BLOCK_CARD           0x7014       //блокировка карточки
#define RIK_ER_NO_ANSWER            0x7016       //отсутствие ответа на RST
#define RIK_ER_PASSWORD             0x63C0       //неверный пароль (младшая тетрада-количество попыток)
#define RIK_ER_NOT_CLOSE_DOOR       0x7023       //не закрыта крышка

//--- Bit mask for interrupt callback user function argument ------------------
#define MASK_RIK_1_INSERT           0x0002
#define MASK_RIK_2_INSERT           0x0004
#define MASK_RIK_1_INSERT_CHANGE    0x0008
#define MASK_RIK_2_INSERT_CHANGE    0x0010
#define MASK_RIK_DOOR_OPEN          0x0020
#define MASK_RIK_DOOR_CHANGE        0x0040

//--- RIK Driver structur -----------------------------------------------------
// ---------------------------------------------------------------------------
// !: sn: s_rik_reset
// !: sd: Структура сброса РИК.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: uint16,      year
// !: cd: год
// !: sc: uint16,      code1
// !: cd: код
// !: sc: uint16,      code2
// !: cd: код
// !: sc: uint16[2],   serial
// !: cd: серийный номер
// !: sc: uint16,      type
// !: cd: тип
// !: sc: uint16,      status
// !: cd: статус
// ---------------------------------------------------------------------------
struct s_rik_reset
{
    uint16      year;
    uint16      code1;
    uint16      code2;
    uint16      serial[2];
    uint16      type;
    uint16      status;
};
// ---------------------------------------------------------------------------
// !: sn: s_rik_reset
// !: sd: Аргумент команды RIK_VERIFY_PASSWORD.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: uint8,       n_pwd
// !: cd: номер ключа
// !: sc: void*,       pwd
// !: cd: указатель на ключ
// ---------------------------------------------------------------------------
struct s_rik_password_arg
{
    uint8       n_pwd;
    void*       pwd;        
};
// ---------------------------------------------------------------------------
// !: sn: s_rik_int_func
// !: sd: Аргумент команды RIK_USER_INT_FUNC.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: void (*)(uint16),     func
// !: cd: указатель на функцию
// ---------------------------------------------------------------------------
struct s_rik_int_func
{
    void (*func)(uint16);
};
// -- For system calls only ---------------------------------------------------
extern int32     drv_rik_plug(uint32 number_gpio_interrupt);
extern int32     drv_rik_plug(uint32 number_gpio_interrupt, uint8 redirect);
extern int32     drv_rik_redirect_plug();
extern int32     drv_rik_unplug();

#endif //__Driver_Rik_H__


