//**************************************************************************************************
//                         Copyright (C) 2009 RCZI
//--------------------------------------------------------------------------------------------------
// FILENAME....... drv_gpio.cpp
// DATE CREATED... 13/10/2009
// LAST MODIFIED.. 23/12/2009
// DRIVER VERSION. 1.1
//--------------------------------------------------------------------------------------------------
//   Содержимое папки: /dev/
//               ..
//   <FILE>      gpio
//--------------------------------------------------------------------------------------------------
//                              ДРАЙВЕР GPIO
//-------------------------------------------------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
//
// !: codepage: cp1251 
//
// !: d: Драйвер GPIO.<br>
// !: md: Драйвер реализует: диспечирезацию прерываний от GPIO Interrupt Logic,
// !: md: функции манипуляций с GPIO.<br> 
// !: md: Устройство (файл) GPIO в ОС связанно с собственным файлом gpio. 
// !: md: Путь к устройству: "/dev/gpio". Драйвер реализует стандартный 
// !: md: интерфейс взаимодействия пользователя с устройством по средствам 
// !: md: функции управляющих воздействий на устройство.
// !: -:
//***sss********************************************************************************************
#include    <os.h>
#include    <rts.h>
#include    <drv_gpio.h>
/**************************************************************************************************\
*       КОНСТАНТЫ
\**************************************************************************************************/
#define NUMBER_DSP_GPIO         16

/**************************************************************************************************\
*       СТРУКТУРЫ
\**************************************************************************************************/
struct  s_gpio_event
{
    void    (*interrupt_functoin)();
};

/**************************************************************************************************\
*       ГЛОБАЛЬНЫЕ ПЕРЕМЕННЫЕ
\**************************************************************************************************/
uint32              os_interrupt_descriptor_gpio;
uint32              sem_gpio;
s_gpio_event        gpio_event[NUMBER_DSP_GPIO];

/**************************************************************************************************\
*       ПРОТОТИПЫ
\**************************************************************************************************/
void    gpio_interrupt_logic();
int32   gpio_init(s_os_driver_context* ctx);
int32   gpio_deinit();
int32   gpio_alloc(s_gpio_interrupt* gpio);
int32   gpio_free(s_gpio_interrupt* gpio);
int32   gpio_lock(uint32* gpio);
int32   gpio_unlock(uint32* gpio);        
int32   gpio_pull(s_gpio_operation* gpio);
int32   gpio_value(s_gpio_operation* gpio);

//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//          Интерфейсные функции драйвера
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//*************************************************************************************************
//       Открытие потока
//-------------------------------------------------------------------------------------------------
// !: fn: int32 gpio_open(s_os_driver_descriptor* d, uint16 access)
//
// !: d: Функция драйвером не поддерживаеться.<br> 
// !: -:
//***sss*******************************************************************************************
int32 gpio_open(s_os_driver_descriptor* d, uint16 access)
{
    return  OSE_CANT_OPEN;
}
//*************************************************************************************************
//       Закрытие потока
//-------------------------------------------------------------------------------------------------
// !: fn: int32 gpio_close(s_os_driver_descriptor* d)
//
// !: d: Функция драйвером не поддерживаеться.<br> 
// !: -:
//***sss*******************************************************************************************
int32 gpio_close(s_os_driver_descriptor* d)
{
    return OSE_STREAM_NOT_OPENED;
}
//*************************************************************************************************
//       Чтение из потока
//-------------------------------------------------------------------------------------------------
// !: fn: int32 gpio_read(s_os_driver_descriptor* d, void* buf, int32 length)
//
// !: d: Функция драйвером не поддерживаеться.<br> 
// !: -:
//***sss*******************************************************************************************
int32 gpio_read(s_os_driver_descriptor* d, void* buf, int32 length)
{
    return OSE_PERMISSION_DENIED;
}
//*************************************************************************************************
//       Запись в поток
//-------------------------------------------------------------------------------------------------
// !: fn: int32 gpio_write(s_os_driver_descriptor* d, const void* buf, int32 length)
//
// !: d: Функция драйвером не поддерживаеться.<br> 
// !: -:
//***sss********************************************************************************************
int32 gpio_write(s_os_driver_descriptor* d, const void* buf, int32 length)
{
    return OSE_PERMISSION_DENIED;
}
//**************************************************************************************************
//       Управление вводом/выводом
//-------------------------------------------------------------------------------------------------
// !: fn: int32 gpio_ioctl(s_os_driver_descriptor* d, int32 cmd, const void* arg)
//
// !: d: Функция реализует управляющее воздействие на устройство
// !: d: в соответствии с поданной командой.<br><br> 
//
// !: d: Входные аргументы:<br>
// !: d: - d - указатель на дескриптор драйвера, формируемый ОС;<br>
// !: d: - cmd - команды управления;<br>
// !: d: - arg - аргумент.<br><br>
//
// !: d: Возвращаемые значения:<br>
// !: d: - Стандартные коды ошибок ioctl;<br>
//
// !: d: Стандартные команды управления:<br>
// !: d: - IOC_INIT, IOC_DEINIT, IOC_INIT_DESCRIPTOR, IOC_DEINIT_DESCRIPTOR,
// !: d:   IOC_INODE_SELECT, IOC_RESIZE.<br><br>
//
// !: d: Дополнительные команды управления:<br>
// !: d: <table cellpadding=10 cellspacing=0 border=0>
// !: d: <tr>
// !: d:   <td valign=top>
// !: d:   Команда:
// !: d:   </td> 
// !: d:   <td valign=top>
// !: d:   Тип&nbsp;аргумента:
// !: d:   </td>
// !: d:   <td valign=top>
// !: d:   Описание:
// !: d:   </td>
// !: d: </tr>
//
// !: d: <tr>
// !: d:   <td valign=top>
// !: d:   GPIO_INT_ALLOC
// !: d:   </td> 
// !: d:   <td valign=top>
// !: d:   s_gpio_interrupt
// !: d:   </td> 
// !: d:   <td valign=top>
// !: d:   Захватить вектор прерывания GPIO
// !: d:   </td>
// !: d: </tr>
//
// !: d: <tr>
// !: d:   <td valign=top>
// !: d:   GPIO_INT_FREE 
// !: d:   </td> 
// !: d:   <td valign=top>
// !: d:   s_gpio_interrupt
// !: d:   </td> 
// !: d:   <td valign=top>
// !: d:   Освободить вектор прерывания GPIO
// !: d:   </td>
// !: d: </tr>
//
// !: d: <tr>
// !: d:   <td valign=top>
// !: d:   GPIO_PULL
// !: d:   </td> 
// !: d:   <td valign=top>
// !: d:   s_gpio_operation
// !: d:   </td> 
// !: d:   <td valign=top>
// !: d:   Установка значения GPIO
// !: d:   </td>
// !: d: </tr>
//
// !: d: <tr>
// !: d:   <td valign=top>
// !: d:   GPIO_VALUE
// !: d:   </td> 
// !: d:   <td valign=top>
// !: d:   s_gpio_operation
// !: d:   </td> 
// !: d:   <td valign=top>
// !: d:   Получение значения GPIO
// !: d:   </td>
// !: d: </tr>
//
// !: d: </table>
//
//***sss********************************************************************************************
int32 gpio_ioctl(s_os_driver_descriptor* d, int32 cmd, const void* arg)
{
    switch(cmd)
    {
    //===============================================================
    //Standard control command:
        //Инициализация драйвера:
        case IOC_INIT:
            return gpio_init((s_os_driver_context*)arg);

        //Деинициализация драйвера:
        case IOC_DEINIT:            
            return gpio_deinit();

        //Инициализация данных:
        case IOC_INIT_DESCRIPTOR:
        //Деинициализация данных:
        case IOC_DEINIT_DESCRIPTOR:
        //Удаление данных из потока:
        case IOC_RESIZE:                
        break;

        //Переход по директориям в корне драйвера:
        case IOC_INODE_SELECT:      
        {   
            const char* recast_arg = (const char*) arg;
            //---------------------------------------------
            if(!strcmp(recast_arg,"."))
            break;
            //---------------------------------------------
            else
            if(!strcmp(recast_arg,".."))
            {
                drv_dec(d);
                drv_rfs(d);
            }
            //---------------------------------------------
            else
                return  OSE_NO_NODE;
        }
        break;
    //===============================================================
    //Driver self control command:
        case GPIO_INT_ALLOC:
            return gpio_alloc((s_gpio_interrupt*)arg);

        case GPIO_INT_FREE:
            return gpio_free((s_gpio_interrupt*)arg);

        case GPIO_LOCK:
            return gpio_lock((uint32*)arg);
        
        case GPIO_UNLOCK:
            return gpio_unlock((uint32*)arg);        

        case GPIO_PULL:
            return gpio_pull((s_gpio_operation*)arg);

        case GPIO_VALUE:
            return gpio_value((s_gpio_operation*)arg);

        default:
            return OSE_BAD_CMD;
    }
    return OSE_OK;
}       
//**************************************************************************************************
//       Добавить драйвер в систему
//-------------------------------------------------------------------------------------------------
// !: fn: int32 drv_gpio_plug()
//
// !: d: Добавляет драйвер GPIO в систему<br><br> 
//
// !: d: Входные аргументы:<br>
// !: d: - Указатель на структуру s_gpio_start_value<br><br>
//
// !: d: Возвращаемые значения:<br>
// !: d: - Стандартные коды ошибок ioctl.<br>
//***sss********************************************************************************************
int32 drv_gpio_plug(s_gpio_start_value* reg)
{
    return drv_plug("/dev/gpio", INOT_FILE, &gpio_open, &gpio_close, &gpio_read, &gpio_write, &gpio_ioctl, reg, sizeof(s_gpio_start_value));
}
//**************************************************************************************************
//      Удалить драйвер из системы 
//-------------------------------------------------------------------------------------------------
// !: fn: int32 drv_gpio_unplug()
//
// !: d: Удаляет драйвер GPIO из системы.<br><br>
//
// !: d: Возвращаемые значения:<br>
// !: d: - Стандартные коды ошибок ioctl.<br>
//***sss********************************************************************************************
int32 drv_gpio_unplug()
{
    return drv_unplug("gpio");
}
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//          Внутренние функции драйвера
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
#define DRV_GPIO_LOCKED  ( (void(*)())0xFFFFFFFF )
/**************************************************************************************************\
*   Процидура обработки прерывания от GPIO Interrupt Logic
\***sss********************************************************************************************/
void gpio_interrupt_logic()
{
    register uint32 gphm = REG_GPHM;
    register uint32 gpdh = REG_GPDH & gphm;
    REG_GPDH = gpdh;
    for(uint32 gp=0; gp<NUMBER_DSP_GPIO; gp++)
    {
        if(gpdh & (0x1<<gp))
        {
            if( (gpio_event[gp].interrupt_functoin != NULL)&&(gpio_event[gp].interrupt_functoin != DRV_GPIO_LOCKED) )
            {
                gpio_event[gp].interrupt_functoin();
            }
        }
    }
    REG_GPHM = 0x0;
    REG_GPHM = gphm;
}
/**************************************************************************************************\
*   Инициализация GPIO Interrupt Logic
\***sss********************************************************************************************/
int32  gpio_init(s_os_driver_context* ctx)
{
    s_gpio_start_value* gpio = (s_gpio_start_value*)ctx->data;
    os_interrupt_descriptor_gpio = int_alloc(INT_GP0,gpio_interrupt_logic);
    if(os_interrupt_descriptor_gpio == RES_VOID)    return OSE_CANT_CREATE_INTERRUPT;
    if( (sem_gpio = sem_alloc(1,NULL)) == RES_VOID )
    {
      int_free(os_interrupt_descriptor_gpio);
      return OSE_CANT_CREATE_SEM;
    }
    memset(gpio_event,NULL,sizeof(s_gpio_event)*NUMBER_DSP_GPIO);
    REG_GPDIR = gpio->reg_gpdir;   
    REG_GPVAL = gpio->reg_gpval;      
    REG_GPEN  = gpio->reg_gpen; 
    REG_GPGC  = 0x0010;          //Set Delta OR mode
    REG_GPDH  = 0xFFFF;          //Reset
    REG_GPHM  = 0x0000;
    REG_GPDL  = 0xFFFF;          //Reset
    REG_GPLM  = 0x0000;
    int_unlock(os_interrupt_descriptor_gpio);
    return OSE_OK;
}

/**************************************************************************************************\
*   Деинициализация GPIO Interrupt Logic
\***sss********************************************************************************************/
int32 gpio_deinit()
{
    int_free(os_interrupt_descriptor_gpio);
    sem_free(sem_gpio);
    REG_GPGC = 0x0000;
    return OSE_OK;
}

/**************************************************************************************************\
*   Занять GPIO
\***sss********************************************************************************************/
int32 gpio_alloc(s_gpio_interrupt* gpio)
{
    int32   error;
    sem_lock(sem_gpio,SEM_INFINITY);
    if(!((0x0 <= gpio->number_gpio)&&(gpio->number_gpio < NUMBER_DSP_GPIO)))
    {
        error = OSE_BAD_PARAM;
        goto    m_return;
    }
    if(gpio->call_functoin == NULL)
    {
        error = OSE_BAD_PARAM;
        goto    m_return;
    }
    if(gpio_event[gpio->number_gpio].interrupt_functoin != NULL)
    {
        error = OSE_CANT_CREATE_INTERRUPT;
        goto    m_return;
    }
    gpio_event[gpio->number_gpio].interrupt_functoin = gpio->call_functoin;
    REG_GPEN  &= ~(0x1<<gpio->number_gpio);
    REG_GPDIR &= ~(0x1<<gpio->number_gpio); //Set GPIO as input
    REG_GPDH   =   0x1<<gpio->number_gpio;
    REG_GPDL   =   0x1<<gpio->number_gpio;
    REG_GPHM  |=   0x1<<gpio->number_gpio;
    REG_GPEN  |=   0x1<<gpio->number_gpio;
    error = OSE_OK; 
m_return:
    sem_unlock(sem_gpio);
    return error;
}
/**************************************************************************************************\
*   Освободить GPIO
\***sss********************************************************************************************/
int32 gpio_free(s_gpio_interrupt* gpio)
{
    int32   error;
    sem_lock(sem_gpio,SEM_INFINITY);
    if(gpio_event[gpio->number_gpio].interrupt_functoin != NULL)
    {
        REG_GPEN &= ~(0x1<<gpio->number_gpio);
        REG_GPDH  =   0x1<<gpio->number_gpio;
        REG_GPDL  =   0x1<<gpio->number_gpio;
        REG_GPHM &= ~(0x1<<gpio->number_gpio);
        gpio_event[gpio->number_gpio].interrupt_functoin = NULL;
        error = OSE_OK;
    }
    else
        error = OSE_BAD_PARAM;
    sem_unlock(sem_gpio);
    return error;
}
/**************************************************************************************************\
*   Заблокировать GPIO
\***sss********************************************************************************************/
int32   gpio_lock(uint32* gpio)
{
    int32   error;
    sem_lock(sem_gpio,SEM_INFINITY);
    if(*gpio >= NUMBER_DSP_GPIO)
        error = OSE_BAD_PARAM;
    else
    if(gpio_event[*gpio].interrupt_functoin != NULL)
        error = OSE_RESOURCE_BUSY;
    else
    {
        gpio_event[*gpio].interrupt_functoin = DRV_GPIO_LOCKED;
        error = OSE_OK;
    }
    sem_unlock(sem_gpio);
    return error;
}
/**************************************************************************************************\
*   Заблокировать GPIO
\***sss********************************************************************************************/
int32   gpio_unlock(uint32* gpio)       
{
    int32   error;
    sem_lock(sem_gpio,SEM_INFINITY);
    if(*gpio >= NUMBER_DSP_GPIO)
        error = OSE_BAD_PARAM;
    else
    if(gpio_event[*gpio].interrupt_functoin != DRV_GPIO_LOCKED)
        error = OSE_BAD_PARAM;
    else
    {
        gpio_event[*gpio].interrupt_functoin = NULL;
        error = OSE_OK;
    }
    sem_unlock(sem_gpio);
    return error;
}
/**************************************************************************************************\
*   Дернуть GPIO
\***sss********************************************************************************************/
int32 gpio_pull(s_gpio_operation* gpio)
{
    int32   error;
    sem_lock(sem_gpio,SEM_INFINITY);
    if(!((0x0 <= gpio->number_gpio)&&(gpio->number_gpio < NUMBER_DSP_GPIO)))
    {
        error = OSE_BAD_PARAM;
        goto    m_return;
    }
    //Если GPIO незадействованно под прерывание:
    if(gpio_event[gpio->number_gpio].interrupt_functoin == NULL)
    {
        REG_GPEN  |= 0x1<<gpio->number_gpio;
        REG_GPDIR |= 0x1<<gpio->number_gpio; //Set GPIO as output
        switch (gpio->value_gpio)
        {
            case 0:
            {
                REG_GPVAL &= ~(0x1<<gpio->number_gpio);
                break;
            }
            case 1:
            {   
                REG_GPVAL |= 0x1<<gpio->number_gpio;
                break;
            }
            default:
                error = OSE_BAD_PARAM;
        }
        error = OSE_OK;
    }
    else
        error = OSE_RESOURCE_BUSY;
m_return:
    sem_unlock(sem_gpio);
    return error;
}
/**************************************************************************************************\
*   Взять значение GPIO
\***sss********************************************************************************************/
int32 gpio_value(s_gpio_operation* gpio)
{
    if(!((0x0 <= gpio->number_gpio)&&(gpio->number_gpio < NUMBER_DSP_GPIO)))
        return OSE_BAD_PARAM;
    else
    {
        sem_lock(sem_gpio,SEM_INFINITY);
        REG_GPEN |= 0x1<<gpio->number_gpio;
        gpio->value_gpio = (REG_GPVAL>>gpio->number_gpio)&0x1;
        sem_unlock(sem_gpio);
    }
    return OSE_OK;
}
