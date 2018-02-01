//**************************************************************************************************
//                         Copyright (C) 2009 RCZI
//--------------------------------------------------------------------------------------------------
// FILENAME....... drv_usbhc.cpp
// DATE CREATED... 10/11/2009
// LAST MODIFIED.. 10/12/2009
// DRIVER VERSION. 1.0
//--------------------------------------------------------------------------------------------------
//       ISP 1760/1761 Hi-Speed Universal Serial Bus host controller driver
//-------------------------------------------------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
//
// !: codepage: cp1251 
//
// !: d: Драйвер ISP 1760/1761 Hi-Speed Universal Serial Bus host controller.<br>
// !: md: Устройство (файл) хост контроллер в ОС связанно с собственным файлом 
// !: md: usbhc. Путь к устройству: "/dev/usbhc". Драйвер реализует стандартный 
// !: md: интерфейс взаимодействия пользователя с устройством по средствам 
// !: md: функции управляющих воздействий на устройство.
// !: -:
//***sss********************************************************************************************
#include    <os.h>
#include    <rts.h>
#include    <drv_gpio.h>
#include    <drv_usbhc.h> 
#include    <mem_isp176x.h>

//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//
//          Интерфейсные функции драйвера
//
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
static int32 lg_usbhc_init_driver(s_os_driver_context* ctx);
static int32 lg_usbhc_deinit_driver(s_os_driver_context* ctx);
static int32 lg_usbhc_init_descriptor(void* (*descriptor));
static int32 lg_usbhc_deinit_descriptor(void* (*descriptor));
static int32 lg_usbhc_bulk_transaction(s_usbhc_bulk* tsk);
static int32 lg_usbhc_start_interrupt_transaction(s_usbhc_s_interrupt* tsk);
static int32 lg_usbhc_complete_interrupt_transaction(s_usbhc_c_interrupt* tsk);

//**************************************************************************************************
//       Открытие потока
//-------------------------------------------------------------------------------------------------
// !: fn: int32 usbhc_open(s_os_driver_descriptor* d, uint16 access)
//
// !: d: Функция драйвером не поддерживаеться.<br> 
// !: -:
//***sss********************************************************************************************
static int32 usbhc_open(s_os_driver_descriptor* d, uint16 access)
{
    return OSE_CANT_OPEN;
}
//**************************************************************************************************
//       Закрытие потока
//-------------------------------------------------------------------------------------------------
// !: fn: int32 usbhc_close(s_os_driver_descriptor* d)
//
// !: d: Функция драйвером не поддерживаеться.<br> 
// !: -:
//***sss********************************************************************************************
static int32 usbhc_close(s_os_driver_descriptor* d)
{
    return OSE_STREAM_NOT_OPENED;
}
//**************************************************************************************************
//       Чтение из потока
//-------------------------------------------------------------------------------------------------
// !: fn: int32 usbhc_read(s_os_driver_descriptor* d, void* buf, int32 length)
//
// !: d: Функция драйвером не поддерживаеться.<br> 
// !: -:
//***sss********************************************************************************************
static int32 usbhc_read(s_os_driver_descriptor* d, void* buf, int32 length)
{
    return OSE_PERMISSION_DENIED;
}
//**************************************************************************************************
//       Запись в поток
//-------------------------------------------------------------------------------------------------
// !: fn: int32 usbhc_write(s_os_driver_descriptor* d, const void* buf, int32 length)
//
// !: d: Функция драйвером не поддерживаеться.<br> 
// !: -:
//***sss********************************************************************************************
static int32 usbhc_write(s_os_driver_descriptor* d, const void* buf, int32 length)
{
    return OSE_PERMISSION_DENIED;
}
//**************************************************************************************************
//       Управление вводом/выводом
//-------------------------------------------------------------------------------------------------
// !: fn: int32 usbhc_ioctl(s_os_driver_descriptor* d, int32 cmd, const void* arg)
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
// !: d: <table cellpadding=5 cellspacing=0 border=1>
// !: d: <tr>
// !: d:   <td width=70 align=center>7</td><td width=70 align=center>6</td><td width=70 align=center>5</td><td width=70 align=center>4</td><td width=70 align=center>3</td><td width=70 align=center>2</td><td width=70 align=center>1</td><td width=70 align=center>0</td>
// !: d: </tr>
// !: d: <tr>
// !: d:    <td colspan=4 align=center>
// !: d:    Резерв
// !: d:    </td>
// !: d:    <td align=center>
// !: d:      PID
// !: d:    </td>
// !: d:    <td align=center>
// !: d:      BABBLE
// !: d:    </td>
// !: d:    <td align=center>
// !: d:      STALL
// !: d:    </td>
// !: d:    <td align=center>
// !: d:      NAK
// !: d:    </td>
// !: d: </tr>
// !: d: </table>
// !: d: - Стандартные коды ошибок ioctl;<br>
// !: d: - USB_ER_NAK - маска ошибки NAK;<br>
// !: d: - USB_ER_STALL - маска ошибки STALL;<br>
// !: d: - USB_ER_BABBLE - маска ошибки BABBLE;<br>
// !: d: - USB_ER_PID - маска ошибки PID.<br><br>
//
// !: d: Стандартные команды управления:<br>
// !: d: - IOC_INIT, IOC_DEINIT, IOC_INIT_DESCRIPTOR, IOC_DEINIT_DESCRIPTOR,
// !: d:   IOC_INODE_SELECT.<br><br>
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
// !: d:   USBHC_BULK
// !: d:   </td> 
// !: d:   <td valign=top>
// !: d:   s_usbhc_bulk
// !: d:   </td>
// !: d:   <td valign=top>
// !: d:   Транзакция типа bulk.
// !: d:   </td>
// !: d: </tr>
//
// !: d: <tr>
// !: d:   <td valign=top>
// !: d:   USBHC_START_INTERRUPT
// !: d:   </td> 
// !: d:   <td valign=top>
// !: d:   s_usbhc_s_interrupt
// !: d:   </td>
// !: d:   <td valign=top>
// !: d:   Начать транзакцию типа interrupt.
// !: d:   </td>
// !: d: </tr>
//
// !: d: <tr>
// !: d:   <td valign=top>
// !: d:   USBHC_COMPLETE_INTERRUPT
// !: d:   </td> 
// !: d:   <td valign=top>
// !: d:   s_usbhc_c_interrupt
// !: d:   </td>
// !: d:   <td valign=top>
// !: d:   Завершить транзакцию типа interrupt.
// !: d:   </td>
// !: d: </tr>
// !: d: </table>
// !: -:
//***sss********************************************************************************************
static int32 usbhc_ioctl(s_os_driver_descriptor* d, int32 cmd, const void* arg)
{
    switch(cmd)
    {
    //===============================================================
    //Standard control command:
        //Инициализация:
        case IOC_INIT:
            return lg_usbhc_init_driver((s_os_driver_context*)arg);

        //Деинициализация:
        case IOC_DEINIT:            
            return lg_usbhc_deinit_driver((s_os_driver_context*)arg);

        //Инициализация данных:
        case IOC_INIT_DESCRIPTOR:
            return lg_usbhc_init_descriptor(&d->data);

        //Деинициализация данных:
        case IOC_DEINIT_DESCRIPTOR: 
            return lg_usbhc_deinit_descriptor(&d->data);

        //Переход по директориям в корне драйвера:
        case IOC_INODE_SELECT:      
        {   
            if(d->access & DRV_OPENED) 
                return OSE_STREAM_OPENED;
            if(!strcmp((const char*)arg,"."))
                break;
            else
            if(!strcmp((const char*)arg,".."))
            {
                drv_dec(d);
                drv_rfs(d);
            }
            else
                return  OSE_NO_NODE;
        }
        break;

    //===============================================================
    //Driver control command:   
        case USBHC_BULK:
            return lg_usbhc_bulk_transaction((s_usbhc_bulk*)arg);

        case USBHC_START_INTERRUPT:
            return lg_usbhc_start_interrupt_transaction((s_usbhc_s_interrupt*)arg);

        case USBHC_COMPLETE_INTERRUPT:
            return lg_usbhc_complete_interrupt_transaction((s_usbhc_c_interrupt*)arg);
            
        case USBHC_CONFIGURATION:            
            return OSE_OK;        

        default:
            return OSE_BAD_CMD;
    }
    return OSE_OK;
}       
//**************************************************************************************************
//       Добавить драйвер в систему
//-------------------------------------------------------------------------------------------------
// !: fn: int32 drv_usbhc_plug(uint32 number_gpio_interrupt)
//
// !: d: Добавляет драйвер USB Host Controller в систему<br><br> 
//
// !: d: Входные аргументы:<br>
// !: d: - number_gpio_interrupt - номер GPIO - источника прерывания.<br><br>
//
// !: d: Возвращаемые значения:<br>
// !: d: - Стандартные коды ошибок ioctl.<br>
//***sss********************************************************************************************
int32 drv_usbhc_isp176x_plug(uint32 number_gpio_interrupt)
{
  return drv_plug("/dev/usbhc", INOT_FILE, &usbhc_open, &usbhc_close, &usbhc_read, &usbhc_write, &usbhc_ioctl, &number_gpio_interrupt, sizeof(uint32));
}
//**************************************************************************************************
//      Удалить драйвер из системы 
//-------------------------------------------------------------------------------------------------
// !: fn: int32 drv_usbhc_unplug()
//
// !: d: Удаляет драйвер USB Host Controller из системы.<br><br>
//
// !: d: Возвращаемые значения:<br>
// !: d: - Стандартные коды ошибок ioctl.<br>
//***sss********************************************************************************************
int32 drv_usbhc_isp176x_unplug()
{
  return drv_unplug("usbhc");
}

//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//
//          Логические функции драйвера
//
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
#define PTD_DT_MASK                0x10
#define PTD_DT_SHIFT               0x04

#define HS_BULK_MAX_BYTE_PTD       512//31*1024
#define SC_BULK_MAX_BYTE_PTD       512//1*1024
//-------------------------------------------------------------------------------------------------
struct s_empty_number
{
    uint8           max_number;
    uint8*          tab_number;
    uint32          sem_empty_number;
};
struct s_isp_memory
{
    uint32          max_block;
    uint32          size_block;
    uint32*         isp_memory;
    uint8*          mem_markers;
        s_empty_number  marker;
        uint32                  sem_isp_memory;
};
struct  s_int_exchange
{
    int32           exchange;
    int32*          flag;
    uint32          sem;    
    void*           data;
    char*           name;
    int32           size;
    int32           nb_int;
    void*           mem_pl64;
};
struct s_complete_irq
{
    uint32          otg;
    uint32          iso;
    uint32          atl;
    uint32          intp;
    uint32          clkready;
    uint32          hcsusp;
    uint32          dma;
    uint32          sofitl;
};   
//-------------------------------------------------------------------------------------------------
static int8         usbhc_driver_init = 0;
static int8         usbhc_descriptor_init = 0;

static uint32       sem_usbhc = RES_VOID;
static uint32       sem_atl = RES_VOID;

s_empty_number      nb_iso_ptd;
s_empty_number      nb_int_ptd;
s_empty_number      nb_atl_ptd;

s_isp_memory        isp_memory_64;
s_isp_memory        isp_memory_512;

s_int_exchange      ex_int_ptd[MAX_INT_PTD];
s_complete_irq      complete_irq;
//-------------------------------------------------------------------------------------------------
int32   init_empty_struct_usbhc(s_empty_number* istruct, int32 imax_number);
int32   deinit_empty_struct_usbhc(s_empty_number* istruct);
int32   get_empty_number_usbhc(s_empty_number* istruct);
int32   clear_empty_number_usbhc(s_empty_number* istruct, int32 inumber);

int32   init_isp_memory_manager(s_isp_memory* istruct, int32 imax_block, uint32 isize_block, void* isp_memory);
int32   deinit_isp_memory_manager(s_isp_memory* istruct);
void*   isp_memory_alloc(s_isp_memory* istruct, int32 inumber_block);
int32   isp_memory_free(s_isp_memory* istruct, void* isp_mem);

static void  usbhc_interrupt();
static int32 ph_hc_init();
static int32 ph_bulk_transaction(s_usbhc_irp* irp, int32* error, int32* time_out, int32 nb_atl, void* isp_mem);
static int32 ph_start_interrupt_transaction(s_usbhc_irp* irp, int32 nb_int, void* isp_mem);
static int32 ph_complete_interrupt_transaction(void* data, int32 size, int32 nb_int, void* isp_mem);

/**************************************************************************************************\
*   Инициализация драйвера
\***sss********************************************************************************************/
static int32 lg_usbhc_init_driver(s_os_driver_context* ctx)
{
    if(!usbhc_driver_init)
    {

        int32            error, stage;
        uint32           file;
        s_gpio_interrupt hcgpio;
        stage = 0;
        //*** STAGE 1 ***
        //Инициализация host controller:
        error = ph_hc_init();
        if(error) 
        {
            stage = 1;
            goto m_return;
        }
        //*** STAGE 2,3 ***
        //Инициализация прерывания от GPIO:
        hcgpio.number_gpio = *(uint32*)ctx->data;
        hcgpio.call_functoin = &usbhc_interrupt;
        file = drv_mkd("/dev/gpio");
        if(file == RES_VOID)
        {
            error = OSE_NO_DEVICE;
            stage = 2;
            goto m_return;
        }
        error = drv_ioctl(file,GPIO_INT_ALLOC,&hcgpio);
        drv_rmd(file);
        if(error)
        {
            stage = 3;
            goto m_return;
        }
        //*** STAGE 4 ***
        sem_usbhc = sem_alloc(1,NULL);
        if(sem_usbhc == RES_VOID)
        {
            stage = 4;
            error = OSE_CANT_CREATE_SEM;
            goto m_return;
        }
        //*** STAGE 5 ***
        sem_atl = sem_alloc(0,NULL);
        if(sem_atl == RES_VOID)
        {
            stage = 5;
            error = OSE_CANT_CREATE_SEM;
            goto m_return;
        }

        usbhc_driver_init = 1;
        error = OSE_OK;

        m_return:
        switch(stage)
        {
            case 5: sem_free(sem_atl);
            case 4: sem_free(sem_usbhc);
            case 3: file = drv_mkd("/dev/gpio");
                    drv_ioctl(file,GPIO_INT_FREE,&hcgpio);
            case 2: drv_rmd(file);            
        }
        return error;
    }
    else
        return OSE_ALREADY_PLUGGED;
}
/**************************************************************************************************\
*   Деинициализация драйвера
\***sss********************************************************************************************/
static int32 lg_usbhc_deinit_driver(s_os_driver_context* ctx)
{
    int32               error;
    s_gpio_interrupt    hcgpio;
    //Деинициализация прерывания от GPIO:
    hcgpio.number_gpio = *(uint32*)ctx->data;
    hcgpio.call_functoin = &usbhc_interrupt;
    uint32 file = drv_mkd("/dev/gpio");
    error = drv_ioctl(file,GPIO_INT_FREE,&hcgpio);
    drv_rmd(file);
    //Деинициализация семафора: 
    if(usbhc_driver_init)
    {
        sem_free(sem_usbhc);
        sem_free(sem_atl);
    }
    return error;
}
/**************************************************************************************************\
*   Инициализация дескриптора
\***sss********************************************************************************************/
static int32 lg_usbhc_init_descriptor(void* (*descriptor))
{
    int32   error;
    if(!usbhc_driver_init) return OSE_NO_DEVICE;
    sem_lock(sem_usbhc,SEM_INFINITY);
    if(!usbhc_descriptor_init)
    {
        error  = init_empty_struct_usbhc(&nb_iso_ptd, MAX_ISO_PTD);
        error |= init_empty_struct_usbhc(&nb_int_ptd, MAX_INT_PTD);
        error |= init_empty_struct_usbhc(&nb_atl_ptd, MAX_ATL_PTD);

        error |= init_isp_memory_manager(&isp_memory_64, MAX_PL64, sizeof(MEM_Payload64[0]), &MEM_Payload64[0]);
        error |= init_isp_memory_manager(&isp_memory_512, MAX_PL512, sizeof(MEM_Payload512[0]), &MEM_Payload512[0]);
        if(!error)
        {
            memset(&complete_irq, 0x0, sizeof(s_complete_irq));
            memset(ex_int_ptd, 0x0, sizeof(s_int_exchange)*MAX_INT_PTD);
            usbhc_descriptor_init = 1;
            error = OSE_OK;
        }
        else
        {
            deinit_empty_struct_usbhc(&nb_iso_ptd);
            deinit_empty_struct_usbhc(&nb_int_ptd);
            deinit_empty_struct_usbhc(&nb_atl_ptd);

            deinit_isp_memory_manager(&isp_memory_64);  
            deinit_isp_memory_manager(&isp_memory_512);  
        }
    }
    else
    {
        error = OSE_NO_DEVICE;
    }
    sem_unlock(sem_usbhc);
    return error;
}
/**************************************************************************************************\
*   Деинициализация дескриптора
\***sss********************************************************************************************/
static int32 lg_usbhc_deinit_descriptor(void* (*descriptor))
{
    deinit_empty_struct_usbhc(&nb_iso_ptd);
    deinit_empty_struct_usbhc(&nb_int_ptd);
    deinit_empty_struct_usbhc(&nb_atl_ptd);

    deinit_isp_memory_manager(&isp_memory_64);  
    deinit_isp_memory_manager(&isp_memory_512);
    return OSE_OK;
}
/**************************************************************************************************\
*   Транзакция типа BULK
\***sss********************************************************************************************/
static int32 lg_usbhc_bulk_transaction(s_usbhc_bulk* tsk)
{
    int32           error, len, nb_atl, need_bloks, allocated_size;
    int32           size_left, hc_time_out;
    uint64          limit_time;
    void*           isp_mem_pl;
    s_usbhc_irp     irp;
    
    memcpy(&irp, &tsk->irp, sizeof(s_usbhc_irp));
    //Ожидаем свободной ATL PTD:
    do{
        nb_atl = get_empty_number_usbhc(&nb_atl_ptd);
            if(nb_atl == -1) sleep_m(10);
    }while(nb_atl == -1);

    //Выделение памяти из Payload 512:
    if(tsk->irp.size == 0x0)
        need_bloks = 1;
    else
    if(tsk->irp.size > ((tsk->irp.device_speed == USB_HI_SPEED) ? HS_BULK_MAX_BYTE_PTD : SC_BULK_MAX_BYTE_PTD))
        need_bloks = (tsk->irp.device_speed == USB_HI_SPEED) ? HS_BULK_MAX_BYTE_PTD/ELEMENT_PL512 : SC_BULK_MAX_BYTE_PTD/ELEMENT_PL512;
    else
    {
        need_bloks = tsk->irp.size/ELEMENT_PL512;
        need_bloks = (tsk->irp.size & (ELEMENT_PL512-1)) ? need_bloks+1 : need_bloks;
    }
    do{
        isp_mem_pl = isp_memory_alloc(&isp_memory_512, need_bloks);
            if(isp_mem_pl == NULL) sleep_m(10);
    }while(isp_mem_pl == NULL);
    allocated_size = need_bloks*ELEMENT_PL512;
    size_left = tsk->irp.size;

    sem_lock(sem_usbhc, SEM_INFINITY);
    do{
        if(size_left > allocated_size)  irp.size = allocated_size;
        else                            irp.size = size_left;
        limit_time = time_core()+5000;
        while(true)
        {
            len = ph_bulk_transaction(&irp, &error, &hc_time_out, nb_atl, isp_mem_pl);
            irp.data_toggle = (error & PTD_DT_MASK)>>PTD_DT_SHIFT;            
            if( (error & USB_HC_ERROR) == 0x0) 
            {
              break;
            }
            else if( ((error & USB_HC_ERROR) == USB_ER_PID) && (len == irp.size) )
            {
              error &= ~USB_ER_PID;
              break;
            }
            else if( (time_core() >= limit_time) || (hc_time_out != 0x0) )
            {
              error = OSE_TIMEOUT;
              goto m_error;              
            }            
            else if( (error & USB_HC_ERROR) == USB_ER_NAK)
            {
              prc_yield();
              limit_time = time_core()+5000;
              continue;
            }
            else if( error & USB_ER_NAK )    
            {
              continue;
            }
            else                             
            {
              goto m_error;
            }
        }
        irp.data = (uint8*)irp.data + len;
        size_left -= len;
    }while(size_left!=0);
    m_error:
    sem_unlock(sem_usbhc);      
    tsk->irp.size -= size_left;
    *tsk->next_data_toggle = (error & PTD_DT_MASK)>>PTD_DT_SHIFT;
    clear_empty_number_usbhc(&nb_atl_ptd, nb_atl);
        isp_memory_free(&isp_memory_512, isp_mem_pl);
    if(error >= 0) return error & USB_HC_ERROR;
    else return error;
}
/**************************************************************************************************\
*   Начать транзакцию типа INTERRUPT
\***sss********************************************************************************************/
static int32 lg_usbhc_start_interrupt_transaction(s_usbhc_s_interrupt* tsk)
{
    int32   nb_int;
    void*   isp_mem_pl;
    //Ожидаем свободной INT PTD:
    do{
        nb_int = get_empty_number_usbhc(&nb_int_ptd);
            if(nb_int == -1) sleep_m(10);
    }while(nb_int == -1);
    //Выделение памяти из Payload 64:
    do{
        isp_mem_pl = isp_memory_alloc(&isp_memory_64, 1);
            if(isp_mem_pl == NULL) sleep_m(10);
    }while(isp_mem_pl == NULL);

    *tsk->id = nb_int;

    //Отчистка структуры данных об обмене:
    s_int_exchange* prt_ex_int_ptd = &ex_int_ptd[nb_int];
    prt_ex_int_ptd->exchange = 1;
    prt_ex_int_ptd->flag     = tsk->flag;
    prt_ex_int_ptd->sem      = tsk->sem;
    prt_ex_int_ptd->data     = tsk->irp.data;
    prt_ex_int_ptd->name     = tsk->name;
    prt_ex_int_ptd->size     = tsk->irp.size;
    prt_ex_int_ptd->nb_int   = nb_int;
    prt_ex_int_ptd->mem_pl64 = isp_mem_pl;

    sem_lock(sem_usbhc, SEM_INFINITY);
    ph_start_interrupt_transaction(&tsk->irp, nb_int, isp_mem_pl);
    sem_unlock(sem_usbhc);

    return OSE_OK;
}
/**************************************************************************************************\
*   Результат транзакции типа INTERRUPT
\***sss********************************************************************************************/
static int32 lg_usbhc_complete_interrupt_transaction(s_usbhc_c_interrupt* tsk)
{
    int32 error, nb_int;
    void* mem_pl;     
    if(tsk->id == ex_int_ptd[tsk->id].nb_int)
    {
        nb_int = ex_int_ptd[tsk->id].nb_int;
        mem_pl  = ex_int_ptd[tsk->id].mem_pl64;
        sem_lock(sem_usbhc, SEM_INFINITY);
        error = ph_complete_interrupt_transaction(ex_int_ptd[nb_int].data, ex_int_ptd[nb_int].size, ex_int_ptd[nb_int].nb_int, ex_int_ptd[nb_int].mem_pl64);
        sem_unlock(sem_usbhc);
        *tsk->next_data_toggle = (error & PTD_DT_MASK)>>PTD_DT_SHIFT;

        //Отчистка структуры данных об обмене:
        s_int_exchange* prt_ex_int_ptd = &ex_int_ptd[nb_int];
        prt_ex_int_ptd->exchange = 0;
        prt_ex_int_ptd->flag     = NULL;
        prt_ex_int_ptd->sem      = RES_VOID;
        prt_ex_int_ptd->data     = NULL;
        prt_ex_int_ptd->name     = NULL;
        prt_ex_int_ptd->size     = 0x0;
        prt_ex_int_ptd->nb_int   = 0x0;
        prt_ex_int_ptd->mem_pl64 = NULL;

        //Освобождение занимаемых ресурсов контроллера:
        clear_empty_number_usbhc(&nb_int_ptd, nb_int);
        isp_memory_free(&isp_memory_64, mem_pl);

        error &= USB_HC_ERROR;
    }
    else
        error = OSE_BAD_PARAM;
    return error;
}

//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//
//      Физический уровень драйвера 
//
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
#define ATL_IRQ_EVENT   0x00000100
#define INT_IRQ_EVENT   0x00000080
#define HC_SUSP_EVENT   0x00000020

//-------------------------------------------------------------------------------------------------
struct s_ptd_dw
{
    uint32     dw[8];
};
//-------------------------------------------------------------------------------------------------
void    write_atl(int32 number_atl, void* cpu_payload, s_usbhc_irp* irp, uint32 jump, uint32 next_ptd);
int32   read_atl(int32 number_atl, int32* error);
int32   exec_atl(int32 number_atl);

void    write_int(int32 number_int, void* cpu_payload, s_usbhc_irp* irp);
int32   read_int(int32 number_int);
int32   exec_int(int32 number_int);

extern  "C" void   hc_write_reg(void* isp_internal_address, int32 value);
extern  "C" uint32 hc_read_reg (void* isp_internal_address);
extern  "C" void   hc_write_mem(void* dst_usb, void* src_mem, int32 size_in_byte);
extern  "C" void   hc_read_mem (void* dst_mem, void* src_usb, int32 size_in_byte);
extern  "C" uint32 number_completed_ptd(uint32 number); 
/**************************************************************************************************\
*   Обработчик прерывания от контроллера
\***sss********************************************************************************************/
static void usbhc_interrupt()
{
    register uint32 irq_event;
    irq_event = hc_read_reg(&REG_Interrupt);
    //Сброс флагов в Interrupt регистре Хост Контроллера: 
    hc_write_reg(&REG_Interrupt,irq_event);

    //-----------------------------------------------------------------------------
    //Асинхронная транзакция:
    if(irq_event & ATL_IRQ_EVENT)
    {
        complete_irq.atl |= hc_read_reg(&REG_ATL_PTD_Done_Map);
        sem_unlock_sw(sem_atl);
    }
    //-----------------------------------------------------------------------------
    //Транзакция по Прерыванию:
    if(irq_event & INT_IRQ_EVENT)
    {
        register uint32 int_done_map, nb_int;
        int_done_map = hc_read_reg(&REG_INT_PTD_Done_Map);
        //Остановить обмен:
        hc_write_reg(&REG_INT_IRQ_Mask_OR, hc_read_reg(&REG_INT_IRQ_Mask_OR)  & ~int_done_map);
        hc_write_reg(&REG_INT_PTD_Skip_Map,hc_read_reg(&REG_INT_PTD_Skip_Map) |  int_done_map);
        while(int_done_map)
        {
            nb_int = number_completed_ptd(int_done_map);
            int_done_map &= ~(0x1<<nb_int);
            if(ex_int_ptd[nb_int].exchange == 1)
            {
                ex_int_ptd[nb_int].exchange = 0;
                if(ex_int_ptd[nb_int].sem != RES_VOID)
                    sem_unlock_sw(ex_int_ptd[nb_int].sem);
                if(ex_int_ptd[nb_int].flag != NULL)
                    *ex_int_ptd[nb_int].flag = 0xC0|(nb_int&0xF);
            }
        }
    }
}
/**************************************************************************************************\
*   Инициализация ISP176x
\***sss********************************************************************************************/
static int32 ph_hc_init()
{
    int64  limit_time;
    uint32 one_w = 1;   
    uint32 one_r = 0;
    //Сброс:
    hc_write_reg(&REG_SW_Reset, 0x00000003);    
    sleep_m(100);
    //Установка ширины шины:
    #if   ISP176_BUS_32==1
    hc_write_reg(&REG_HW_Mode_Control, 0x00000100);//32bit mode.
    #else 
    hc_write_reg(&REG_HW_Mode_Control, 0x00000000);//16bit mode.
    #endif
    //Отчистка флагов прерывания:
    hc_write_reg(&REG_Interrupt, REG_Interrupt);     
    //Команда HCRESET:
    hc_write_reg(&REG_USBCMD, 0x00080002);    
    sleep_m(100); //in mks
    //Тест Scratch:
    for(char i=0;i<32;i++)
    {
        hc_write_reg(&REG_Scratch, one_w);
        one_r = hc_read_reg(&REG_Scratch);
        if(one_w!=one_r)
            return OSE_DATA_TEST_ERROR; 
        one_w = one_w << 1;
    }
    //Отчистка статуса:
    hc_write_reg(&REG_USBSTS, 0x00000000);             
    hc_write_reg(&REG_ATL_PTD_Skip_Map, 0xFFFFFFFF);   
    hc_write_reg(&REG_INT_PTD_Skip_Map, 0xFFFFFFFF);   
    hc_write_reg(&REG_ISO_PTD_Skip_Map, 0xFFFFFFFF);   
    hc_write_reg(&REG_ATL_PTD_Done_Map, 0x00000000);   
    hc_write_reg(&REG_INT_PTD_Done_Map, 0x00000000);   
    hc_write_reg(&REG_ISO_PTD_Done_Map, 0x00000000);   
    hc_write_reg(&REG_INT_PTD_Last_PTD, 0x80000000);   
    hc_write_reg(&REG_ATL_PTD_Last_PTD, 0x80000000);   
    sleep_m(50);//10ms                                 
    //Отчистка флагов прерывания:
    hc_write_reg(&REG_Interrupt, REG_Interrupt); 
    //Разрешение прерываний ATL_PTD_done,INT_PTD_done, SOF and HC_Suspend:
    hc_write_reg(&REG_Interrupt_Enable, 0x000001A0);//0x000001E0);
    //ALL_ATX_RESET:
    /*
    hc_write_reg(&HW_Mode_Control, HW_Mode_Control |  0x80000000);
    sleep_m(10); //ms
    hc_write_reg(&HW_Mode_Control, HW_Mode_Control & ~0x80000000);
    */
    //Установка масок прерывания:
    hc_write_reg(&REG_ATL_IRQ_Mask_AND,0x00000000);
    hc_write_reg(&REG_ATL_IRQ_Mask_OR, 0x00000000);  
    hc_write_reg(&REG_INT_IRQ_Mask_AND,0x00000000);  
    hc_write_reg(&REG_INT_IRQ_Mask_OR, 0x00000000);  
    hc_write_reg(&REG_ISO_IRQ_Mask_AND,0x00000000);  
    hc_write_reg(&REG_ISO_IRQ_Mask_OR, 0x00000000);  
    //Interrupt transaction enable:
    hc_write_reg(&REG_Buffer_Status,   hc_read_reg(&REG_Buffer_Status) | 0x00000002);
    //Установка ATL done time-out interrupt в мс:
    //hc_write_reg(&ATL_Done_Timeout,    0x00000040);
    //Interrupt Polarity - Active HIGH, INT is edge triggered, Global Interrupt Enable:
    hc_write_reg(&REG_HW_Mode_Control, REG_HW_Mode_Control | 0x00000007);
    //Установка  Run/Stop = 1:
    hc_write_reg(&REG_USBCMD, 0x00080001);
    limit_time = time_core()+1000;
    while(true)
    {
      if((hc_read_reg(&REG_USBCMD) & 0x00000001) == 0x1) break;
      if(time_core() >= limit_time) 
        return OSE_TIMEOUT;
    }
    //3 порта downstream:
    //hc_write_reg(&REG_Port_1_Control, 0x00800000);
    //while(hc_read_reg(&REG_Port_1_Control) & 0x00000080);
    //Разрешение конфигурации порта PORTSC1:
    hc_write_reg(&REG_CONFIGFLAG, 0x00000001);
    limit_time = time_core()+1000;
    while(true)
    {
      if((hc_read_reg(&REG_CONFIGFLAG) & 0x00000001) == 0x1) break;
      if(time_core() >= limit_time) 
        return OSE_TIMEOUT;
    }
    //Включение питания:
    hc_write_reg(&REG_PORTSC1, 0x00001000);
    limit_time = time_core()+1000;
    while(true)
    {
      if((hc_read_reg(&REG_PORTSC1) & 0x00000002) == 0x2) break;
      if(time_core() >= limit_time) 
        return OSE_TIMEOUT;
    }
    //Сброс:
    hc_write_reg(&REG_PORTSC1, 0x00001901);
    sleep_m(100); //ms
    hc_write_reg(&REG_PORTSC1, REG_PORTSC1 & ~0x00000100);
    hc_write_reg(&REG_OTG_Control_set, 0x00800418);
    //hc_write_reg(&REG_Port_1_Control, 0x00800418);
    hc_write_reg(&REG_Power_Down_Control, REG_Power_Down_Control | 0x0000061);

    return  OSE_OK;
}
/**************************************************************************************************\
*   Выполнение BULK транзакция
\***sss********************************************************************************************/
static int32 ph_bulk_transaction(s_usbhc_irp* irp, int32* error, int32* time_out, int32 nb_atl, void* isp_mem)
{
    register int32   len;
    //Запись данных в Payload:
    if((irp->token == USB_OUT_TOKEN)||(irp->token == USB_SETUP_TOKEN))
        hc_write_mem(isp_mem, irp->data, irp->size);
    //Формирование Asynchronous Transfer List:
    write_atl(nb_atl, isp_mem, irp, 0, 0);
    //Выполнение Asynchronous Transfer List:
    *time_out = exec_atl(nb_atl);
    //Результат Asynchronous Transfer List:
    len = read_atl(nb_atl, error);
    //Чтение данных из Payload:
    if(irp->token == USB_IN_TOKEN)
        hc_read_mem(irp->data, isp_mem, len);
    return len;
}
/*================================================================================================*\
*   Постановка задачи ATL
\*==sss===========================================================================================*/
void write_atl(int32 number_atl, void* cpu_payload, s_usbhc_irp* irp, uint32 jump, uint32 next_ptd)
{
    s_ptd_dw    set;
    uint32      data_start_address, ping, se;

    data_start_address = ( ( ((uint32)cpu_payload & ~(uint32)(&reg_isp176x)) >> USB_MEM_SHIFT )-0x400 )>>3;
    switch(irp->device_speed)
    {
        case USB_HI_SPEED:
            if((irp->token == USB_OUT_TOKEN)||(irp->token == USB_SETUP_TOKEN))
                ping = 1;
            else 
                ping = 0;   
            set.dw[7] = HS_BULK_DW7;            
            set.dw[6] = HS_BULK_DW6;            
            set.dw[5] = HS_BULK_DW5;            
            set.dw[4] = HS_BULK_DW4|(jump<<5)|(next_ptd);
            set.dw[3] = HS_BULK_DW3|(ping<<26)|(irp->data_toggle<<25);
            set.dw[2] = HS_BULK_DW2|(data_start_address<<8);
            set.dw[1] = HS_BULK_DW1|(irp->endpoint_type<<12)|(irp->token<<10)|(irp->device_address<<3)|((irp->endpoint_number&0xF)>>1);
            set.dw[0] = HS_BULK_DW0|((irp->endpoint_number&0x1)<<31)|(irp->max_packet_length<<18)|(irp->size<<3);
            break;
        default:
            if(irp->device_speed == USB_FULL_SPEED)  //USB_FULL_SPEED
                se = 0;
            else                                    //USB_LOW_SPEED
                se = 2;
            set.dw[7] = CS_BULK_DW7;            
            set.dw[6] = CS_BULK_DW6;            
            set.dw[5] = CS_BULK_DW5;            
            set.dw[4] = CS_BULK_DW4|(jump<<5)|(next_ptd);
            set.dw[3] = CS_BULK_DW3|(irp->data_toggle<<25);
            set.dw[2] = CS_BULK_DW2|(data_start_address<<8);
            set.dw[1] = CS_BULK_DW1|(irp->hub_address<<25)|(irp->port_number<<18)|(se<<16)|(irp->endpoint_type<<12)|(irp->token<<10)|(irp->device_address<<3)|((irp->endpoint_number&0xF)>>1);
            set.dw[0] = CS_BULK_DW0|((irp->endpoint_number&0x1)<<31)|(irp->max_packet_length<<18)|(irp->size<<3);
    }
    hc_write_mem(MEM_AtlPTD[number_atl],&set,(sizeof(s_ptd_dw)));
}
/*================================================================================================*\
*   Результат выполнения задачи ATL
\*==sss===========================================================================================*/
int32 read_atl(int32 number_atl, int32* error)
{
    s_ptd_dw  get;
    hc_read_mem(&get, MEM_AtlPTD[number_atl], sizeof(s_ptd_dw));
    *error = ((get.dw[3]>>21)&PTD_DT_MASK)|((get.dw[3]>>28)&USB_HC_ERROR);
    return get.dw[3]&0x7FFF; 
}
/*================================================================================================*\
*   Выполнение ATL
\*==sss===========================================================================================*/
int32 exec_atl(int32 number_atl)
{
    uint32 time_out, atl_ptd_skip_map, temp_buffer_status;
    atl_ptd_skip_map  = 0x00000001 << number_atl;

    hc_write_reg(&REG_ATL_IRQ_Mask_AND, hc_read_reg(&REG_ATL_IRQ_Mask_AND) |  atl_ptd_skip_map);
    hc_write_reg(&REG_ATL_PTD_Skip_Map, hc_read_reg(&REG_ATL_PTD_Skip_Map) & ~atl_ptd_skip_map);

    //  FOR PHILIPS_USB:
    //  На контролерах Philips обнаружен баг, при установленном бите INT Buffer Filled
    //  в Buffer Status регистре установка бита ATL Buffer Filled не приводит 
    //  к выполнению ATL PTD. Исходя из чего можно сделать предположение, что контроллер
    //  Philips, как это не породоксально, в один момент времени может выполнять
    //  только один вид транзакций. Для испровления этого бага была введена данная
    //  условная компеляция с целью остановки других типов транзакций.
    //  NOTE: На контроллерах NXP данна бага необнаружена.
    temp_buffer_status = hc_read_reg(&REG_Buffer_Status);
    hc_write_reg(&REG_Buffer_Status,0x00000000);
    //  ---------------
    hc_write_reg(&REG_Buffer_Status, hc_read_reg(&REG_Buffer_Status) | 0x00000001);
   
    time_out = sem_lock(sem_atl, 5000);
    if(time_out == SEM_OK)
        time_out = 0;
    else if(time_out == SEM_TIMEOUT)
        time_out = 1;
    else
        time_out = 2;

    complete_irq.atl &= ~atl_ptd_skip_map;
    hc_write_reg(&REG_Buffer_Status, hc_read_reg(&REG_Buffer_Status) & ~0x00000001);

    //  FOR PHILIPS_USB:
    hc_write_reg(&REG_Buffer_Status, temp_buffer_status);
    //  ---------------

    hc_write_reg(&REG_ATL_IRQ_Mask_AND, hc_read_reg(&REG_ATL_IRQ_Mask_AND) & ~atl_ptd_skip_map);
    hc_write_reg(&REG_ATL_PTD_Skip_Map, hc_read_reg(&REG_ATL_PTD_Skip_Map) |  atl_ptd_skip_map);

    return  time_out;
}

/**************************************************************************************************\
*   Выполнение INTERRUPT транзакция
\***sss********************************************************************************************/
static int32 ph_start_interrupt_transaction(s_usbhc_irp* irp, int32 nb_int, void* isp_mem)
{
    //Формирование Interrupt Transfer List:
    write_int(nb_int, isp_mem, irp);
    //Выполнение Interrupt Transfer List:
    exec_int(nb_int);
    return 0;
}

static int32 ph_complete_interrupt_transaction(void* data, int32 size, int32 nb_int, void* isp_mem)
{
    int32   error;
    //Результат выполнения транзакции:
    error = read_int(nb_int);
    //Чтение принятых данных в буфер указанный USB драйвером:
    if( (!(error & USB_HC_ERROR)) && (data != NULL) )
        hc_read_mem(data, isp_mem, size);
    return error;
}

/*================================================================================================*\
*   Постановка задачи INT
\*==sss===========================================================================================*/
void    write_int(int32 number_int, void* cpu_payload, s_usbhc_irp* irp)
{
    s_ptd_dw  set;
    uint32   data_start_address, se, u_sa, u_frame, u_scs, polling_rate, units;

    data_start_address = ( ( ((uint32)cpu_payload & ~(uint32)(&reg_isp176x)) >> USB_MEM_SHIFT )-0x400 )>>3;
    switch(irp->device_speed)
    {
        case USB_HI_SPEED:
            //интервал опроса в мкс:
            polling_rate = ((0x1<<(irp->interval_polling-1)) * 125);//PollingRate = 2^(iIntervalPolling-1)*125
            //количество интервалов в uSOF:
            units = 0x1<<(irp->interval_polling-1);
            switch(irp->interval_polling)
            {
                case 1:     u_sa = 0xFF; break;
                case 2:     u_sa = 0x55; break;
                case 3:     u_sa = 0x11; break;
                default:    u_sa = 0x01;         
            }
            u_frame = (units-1) & 0xFF;//0xF8;

            set.dw[7] = HS_INT_DW7;
            set.dw[6] = HS_INT_DW6;
            set.dw[5] = HS_INT_DW5;
            set.dw[4] = HS_INT_DW4|u_sa;
            set.dw[3] = HS_INT_DW3|(irp->data_toggle<<25);
            set.dw[2] = HS_INT_DW2|(data_start_address<<8)|(u_frame);
            set.dw[1] = HS_INT_DW1|(irp->endpoint_type<<12)|(irp->token<<10)|(irp->device_address<<3)|(((irp->endpoint_number&0xF)>>1));
            set.dw[0] = HS_INT_DW0|((irp->endpoint_number&0x1)<<31)|(irp->max_packet_length<<18)|(irp->size<<3);
            break;
        default:
            polling_rate = irp->interval_polling * 1000;
        
            if((0<polling_rate)&&(polling_rate<=125)){
            u_sa = 0xFF;
            u_frame = 0;     //125
            } else if((125<polling_rate)&&(polling_rate<=250)){
            u_sa = 0x55;
            u_frame = 0;     //250
            } else if((250<polling_rate)&&(polling_rate<=500)){
            u_sa = 0x11;
            u_frame = 0;     //500
            } else if((500<polling_rate)&&(polling_rate<=1000)){
            u_sa = 0x01;
            u_frame = 0;     //1000
            } else if((1000<polling_rate)&&(polling_rate<=2000)){
            u_sa = 0x01;
            u_frame = 0x08; //2000
            } else if((2000<polling_rate)&&(polling_rate<=4000)){
            u_sa = 0x01;
            u_frame = 0x10; //4000
            } else if((4000<polling_rate)&&(polling_rate<=8000)){
            u_sa = 0x01;
            u_frame = 0x20; //8000
            } else if((8000<polling_rate)&&(polling_rate<=16000)){
            u_sa = 0x01;
            u_frame = 0x40; //16000
            } else if(16000<polling_rate){
            u_sa = 0x01;
            u_frame = 0x80; //32000
            }
            u_scs = (irp->token == USB_IN_TOKEN) ? 0x4 : 0x0;
            se = (irp->device_speed == USB_FULL_SPEED) ? 0x0 : 0x2; 
        
            set.dw[7] = SC_INT_DW7;
            set.dw[6] = SC_INT_DW6;
            set.dw[5] = SC_INT_DW5|u_scs;
            set.dw[4] = SC_INT_DW4|u_sa;
            set.dw[3] = SC_INT_DW3|(irp->data_toggle<<25);
            set.dw[2] = SC_INT_DW2|(data_start_address<<8)|(u_frame);
            set.dw[1] = SC_INT_DW1|(irp->hub_address<<25)|(irp->port_number<<18)|(se<<16)|(irp->endpoint_type<<12)|(irp->token<<10)|(irp->device_address<<3)|(((irp->endpoint_number&0xF)>>1));
            set.dw[0] = SC_INT_DW0|((irp->endpoint_number&0x1)<<31)|(irp->max_packet_length<<18)|(irp->size<<3);
    }
    hc_write_mem(MEM_IntPTD[number_int],&set,sizeof(s_ptd_dw));
}
/*================================================================================================*\
*   Результат выполнения задачи INT
\*==sss===========================================================================================*/
int32   read_int(int32 number_int)
{
    s_ptd_dw  get;
    hc_read_mem(&get, MEM_IntPTD[number_int], sizeof(s_ptd_dw));
    return  ((get.dw[3]>>21)&PTD_DT_MASK)|((get.dw[3]>>28)&USB_HC_ERROR);
}
/*================================================================================================*\
*   Выполнение INT
\*==sss===========================================================================================*/
int32   exec_int(int32 number_int)
{
    uint32 int_ptd_exe = 0x00000001 << number_int;
    hc_write_reg(&REG_INT_PTD_Skip_Map,hc_read_reg(&REG_INT_PTD_Skip_Map) & ~int_ptd_exe);
    hc_write_reg(&REG_INT_IRQ_Mask_OR, hc_read_reg(&REG_INT_IRQ_Mask_OR)  | int_ptd_exe);
    return 0;
}

//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//
//      Вспомогательнее функции 
//
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
/**************************************************************************************************\
*       Менеджер памяти хост контроллера
\***sss********************************************************************************************/
int32   init_isp_memory_manager(s_isp_memory* istruct, int32 imax_block, uint32 isize_block, void* isp_memory)     
{
  register int32 error, stage;
  stage = 0;
  //*** STAGE 1 ***
  istruct->sem_isp_memory = sem_alloc(1,NULL);
  if(istruct->sem_isp_memory == RES_VOID)
  {
    stage = 1;
    error = OSE_CANT_CREATE_SEM;
    goto m_return;
  }
  //*** STAGE 2 ***
  istruct->mem_markers =(uint8*) heap_alloc(NULL, imax_block, HEAP_ALIGN_4);
  if(istruct->mem_markers == NULL)
  {
    stage = 2;
    error = OSE_NO_MEMORY;
    goto m_return;
  }
  //*** STAGE 3 ***
  error = init_empty_struct_usbhc(&istruct->marker, imax_block);
  if(error)
  {
    stage = 3;
    goto m_return;
  }

  istruct->max_block = imax_block;
  istruct->size_block = isize_block;
  istruct->isp_memory = (uint32*)isp_memory;
  memset(istruct->mem_markers, 0x0, istruct->max_block);
  error = 0x0;

  m_return:
  switch(stage)
  {
    case 3: deinit_empty_struct_usbhc(&istruct->marker);
    case 2: heap_free(NULL, istruct->mem_markers);
    case 1: sem_free(istruct->sem_isp_memory);
  }
  return error;
}

int32   deinit_isp_memory_manager(s_isp_memory* istruct)  
{
  deinit_empty_struct_usbhc(&istruct->marker);
  heap_free(NULL, istruct->mem_markers);
  sem_free(istruct->sem_isp_memory);
  istruct->mem_markers = NULL;
  return 0;
}

void* isp_memory_alloc(s_isp_memory* istruct, int32 inumber_block)
{
  register void*  isp_memory;
  register int32  start_block, current_block, alloc_block_left, marker;
  if(inumber_block == 0x0) return NULL;
  sem_lock(istruct->sem_isp_memory, SEM_INFINITY);
  start_block = 0x0;
  current_block = 0x0;
  alloc_block_left = inumber_block;
  for(; current_block<istruct->max_block; current_block++)
  {
    if(istruct->mem_markers[current_block]==0)
      alloc_block_left--;
    else
    {
      start_block = current_block+1;
      alloc_block_left = inumber_block;
    }
    if(alloc_block_left==0) break;
  }
  if(current_block == istruct->max_block)
  {
    isp_memory = NULL;
  }
  else
  {
    marker = get_empty_number_usbhc(&istruct->marker)+1;
    for(int32 i=start_block; i<=current_block; i++)
      istruct->mem_markers[i] = marker;
    isp_memory = &istruct->isp_memory[start_block*(istruct->size_block>>2)];
  }
  sem_unlock(istruct->sem_isp_memory);
  return isp_memory;
}

int32 isp_memory_free(s_isp_memory* istruct, void* isp_mem)
{
  register int32      start_block, marker;
  sem_lock(istruct->sem_isp_memory, SEM_INFINITY);
  if(isp_mem == NULL) 
    goto m_end;
  if(isp_mem < istruct->isp_memory) 
    goto m_end;
  start_block = ( (int32)isp_mem - (int32)istruct->isp_memory )/( istruct->size_block );
  if( !( (0<=start_block) && (start_block<istruct->max_block) ) )
    goto m_end;
  marker = istruct->mem_markers[start_block];
  clear_empty_number_usbhc(&istruct->marker, marker-1);
  for(int32 i=start_block; i<istruct->max_block; i++)
  {
    if(istruct->mem_markers[i]==marker)
      istruct->mem_markers[i] = 0x0;
    else break;
  }
m_end:
  sem_unlock(istruct->sem_isp_memory);
  return 0x0;
}

/**************************************************************************************************\
*       Незанятый номер
\***sss********************************************************************************************/
#define EMPTY_CELL      0xCB
#define FULL_CELL       0x3A

int32   init_empty_struct_usbhc(s_empty_number* istruct, int32 imax_number)     
{
  istruct->sem_empty_number = sem_alloc(1,NULL);
  if(sem_atl == RES_VOID)
    return OSE_CANT_CREATE_SEM;
  istruct->tab_number =(uint8*) heap_alloc(NULL, imax_number, HEAP_ALIGN_4);
  if(istruct->tab_number == NULL) 
  {
    sem_free(istruct->sem_empty_number);
    return OSE_NO_MEMORY;
  }
  istruct->max_number = imax_number;
  memset(istruct->tab_number, EMPTY_CELL, imax_number);
  return 0;
}

int32   deinit_empty_struct_usbhc(s_empty_number* istruct)  
{
  sem_free(istruct->sem_empty_number);
  heap_free(NULL, istruct->tab_number);
  istruct->tab_number = NULL;
  return 0;
}

int32   get_empty_number_usbhc(s_empty_number* istruct)
{
  register int32 number;
    sem_lock(istruct->sem_empty_number, SEM_INFINITY);
  if(istruct->tab_number != NULL)
  {
    for(uint32 i=0; i < istruct->max_number; i++)
    {
      if(istruct->tab_number[i] == EMPTY_CELL) 
      {
        istruct->tab_number[i] = FULL_CELL;
        number = i;
        break;
      }
    }
  }
  else
    number = -1;
  sem_unlock(istruct->sem_empty_number);
  return  number;    
}

int32   clear_empty_number_usbhc(s_empty_number* istruct, int32 inumber)
{
  if( (inumber >= istruct->max_number)||(istruct->tab_number == NULL) ) 
    return -1;
  sem_lock(istruct->sem_empty_number, SEM_INFINITY);
  istruct->tab_number[inumber] = EMPTY_CELL;
  sem_unlock(istruct->sem_empty_number);
  return 0;
}






