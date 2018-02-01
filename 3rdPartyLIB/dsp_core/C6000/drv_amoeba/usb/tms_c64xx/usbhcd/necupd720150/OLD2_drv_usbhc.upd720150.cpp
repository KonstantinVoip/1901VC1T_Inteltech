//**************************************************************************************************
//                         Copyright (C) 2011 RCZI
//--------------------------------------------------------------------------------------------------
// FILENAME....... drv_usbhc.cpp
// DATE CREATED... 08/06/2011
// LAST MODIFIED.. 08/06/2011
// DRIVER VERSION. 1.0
//--------------------------------------------------------------------------------------------------
//       NEC uPD720150 Hi-Speed Universal Serial Bus host controller driver
//-------------------------------------------------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
//
// !: codepage: cp1251 
//
// !: d: Драйвер NEC uPD720150 Hi-Speed Universal Serial Bus host controller.<br>
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
#include    <mem_upd720150.h>
//-------------------------------------------------------------------------------------------------
//#define GP_HC_RESET     12
//#define GP_HC_INTERRUPT 5
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
static int32 lg_usbhc_configuration(s_usbhc_config* arg);

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
      return lg_usbhc_configuration((s_usbhc_config*)arg);    
    
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
int32 drv_usbhc_upd720150_plug(uint32 number_gpio_interrupt)
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
int32 drv_usbhc_upd720150_unplug()
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
struct s_usb_request
{
    uint8       request_type;
    uint8       request;
    uint16le    value;
    uint16le    index;
    uint16le    length;
};
struct  s_int_exchange
{
    int32           exchange;
    int32*          flag;
    uint32          sem;    
    void*           data;
    char*           name;
    int32           size;
};
struct s_mch_hoot
{
  int                                  (*function)(s_usbhc_bulk*);
  int                                  (*control)();
  int32                                narg;
  int32                                arg[4];
};
struct s_root_hub
{
  uint16                               address;
  uint16                               configuration;  
  uint16                               next_toggle0;
  uint8*                               buf;
  s_mch_hoot                           mstate;
  s_usb_request                        request;
  s_int_exchange                       exchange;  
  s_standard_device_descriptor*        dsc_device;
  s_standard_configuration_descriptor* dsc_config;
  s_standard_interface_descriptor*     dsc_interface;
  s_standard_endpoint_descriptor*      dsc_endpoint;
  s_hub_descriptor*                    dsc_hub;
  s_hub_status*                        dsc_hub_status;
  s_hub_port_status*                   dsc_hub_port[2];
};
//-------------------------------------------------------------------------------------------------
static int8        usbhc_driver_init = 0;
static int8        usbhc_descriptor_init = 0;
static uint32      sem_usbhc = RES_VOID;
static int32       sem_usbtr = RES_VOID;
s_root_hub         hoot;
//-------------------------------------------------------------------------------------------------
static void  usbhc_interrupt();
static int32 ph_hc_init();
static int32 ph_bulk_transaction(s_usbhc_bulk* tsk);
static int32 ph_start_interrupt_transaction(s_usbhc_s_interrupt* tsk);
static int32 ph_complete_interrupt_transaction(s_usbhc_c_interrupt* tsk);
static int32 ph_hoot_bulk_transaction(s_usbhc_bulk* tsk);
static int32 ph_hoot_start_interrupt_transaction(s_usbhc_s_interrupt* tsk);
static int32 ph_hoot_complete_interrupt_transaction(s_usbhc_c_interrupt* tsk);
static int32 ph_configuration_transaction(s_usbhc_config* tsk);

/**************************************************************************************************\
*   Инициализация драйвера
\***sss********************************************************************************************/
static int32 lg_usbhc_init_driver(s_os_driver_context* ctx)
{
  if(usbhc_driver_init) return OSE_ALREADY_PLUGGED;
  int32            error, stage;
  uint32           file;
  s_gpio_interrupt hcgpio;

  stage = 0;
  error = OSE_OK;
  
  //*** STAGE 1 ***
  //Инициализация прерывания от GPIO:
  file = drv_mkd("/dev/gpio");
  if(file == RES_VOID)
  {
    error = OSE_NO_DEVICE;
    stage = 1;    
    goto m_return;
  }

  //*** STAGE 2 ***
  //s_gpio_operation gp;  
  //HC reset:
  //gp.number_gpio = GP_HC_RESET;
  //gp.value_gpio  = 1; error |= drv_ioctl(file, GPIO_PULL, &gp);
  //sleep_m(500);
  //gp.value_gpio  = 0; error |= drv_ioctl(file, GPIO_PULL, &gp);
  //sleep_m(1000);    
  //gp.value_gpio  = 1; error |= drv_ioctl(file, GPIO_PULL, &gp);
  //sleep_m(1000);    
  //if(error != OSE_OK){ stage = 2 goto m_return };

  //*** STAGE 3 ***
  //Инициализация host controller:
  error = ph_hc_init();
  if(error) 
  {
    stage = 3;      
    goto m_return;
  }
  //*** STAGE 4 ***
  //Инициализация прерывания от GPIO:    
  hcgpio.number_gpio = *(uint32*)ctx->data;
  hcgpio.call_functoin = &usbhc_interrupt;    
  error = drv_ioctl(file, GPIO_INT_ALLOC, &hcgpio);
  drv_rmd(file);
  if(error != OSE_OK)
  {
    stage = 4;
    goto m_return;
  }
  //*** STAGE 5 ***
  sem_usbhc = sem_alloc(1, NULL);
  if(sem_usbhc == RES_VOID)
  {
    stage = 5;  
    error = OSE_CANT_CREATE_SEM;
    goto m_return;
  }
  //*** STAGE 6 ***
  sem_usbtr = sem_alloc(0, NULL);
  if(sem_usbtr == RES_VOID)
  {
    stage = 6;  
    error = OSE_CANT_CREATE_SEM;
    goto m_return;
  }  
  //*** STAGE COMPLETE ***    
  usbhc_driver_init = 1;
  error = OSE_OK;
  
  m_return:
  switch(stage)
  {
    case  7: sem_free(sem_usbtr);  
    case  6: sem_free(sem_usbhc);
    case  5: file = drv_mkd("/dev/gpio");
             drv_ioctl(file, GPIO_INT_FREE, &hcgpio);      
    case  4:    
    case  3:
    case  2: drv_rmd(file);
  }
  return error;
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
    sem_free(sem_usbtr);    
    sem_free(sem_usbhc);
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
    error = OSE_OK;
    usbhc_descriptor_init = 1;
  }
  else
  {
    error = OSE_NO_DEVICE;
  }
  sem_unlock(sem_usbhc);
  return error;
}
/**************************************************************************************************\
*   Деинициализация дескриптора дисплея
\***sss********************************************************************************************/
static int32 lg_usbhc_deinit_descriptor(void* (*descriptor))
{
  usbhc_descriptor_init = 0;
  return OSE_OK;
}
/**************************************************************************************************\
*   Транзакция типа BULK
\***sss********************************************************************************************/
static int32 lg_usbhc_bulk_transaction(s_usbhc_bulk* tsk)
{
  int32 error;
  sem_lock(sem_usbhc, SEM_INFINITY);
  if(tsk->irp.device_address == hoot.address) 
    error = ph_hoot_bulk_transaction(tsk);
  else
    error = ph_bulk_transaction(tsk);
  sem_unlock(sem_usbhc);        
  return error;
}
/**************************************************************************************************\
*   Начать транзакцию типа INTERRUPT
\***sss********************************************************************************************/
static int32 lg_usbhc_start_interrupt_transaction(s_usbhc_s_interrupt* tsk)
{
  int32 error;
  sem_lock(sem_usbhc, SEM_INFINITY);
  if(tsk->irp.device_address == hoot.address) 
  {
    *tsk->id = NUM_USBHC_PIPE;
    error = ph_hoot_start_interrupt_transaction(tsk);
  }
  else
    error = ph_start_interrupt_transaction(tsk);
  sem_unlock(sem_usbhc);        
  return error;    
}
/**************************************************************************************************\
*   Результат транзакции типа INTERRUPT
\***sss********************************************************************************************/
static int32 lg_usbhc_complete_interrupt_transaction(s_usbhc_c_interrupt* tsk)
{
  int32 error;
  sem_lock(sem_usbhc, SEM_INFINITY);
  if(tsk->id == NUM_USBHC_PIPE) 
    error = ph_hoot_complete_interrupt_transaction(tsk);
  else
    error = ph_complete_interrupt_transaction(tsk);  
  sem_unlock(sem_usbhc);        
  return error;        
}
/**************************************************************************************************\
*   Конфигурация HC при подключении и отключении устройства
\***sss********************************************************************************************/
static int32 lg_usbhc_configuration(s_usbhc_config* arg)
{
  int32 error;
  if(arg->device_address == hoot.address) return OSE_OK;
  sem_lock(sem_usbhc, SEM_INFINITY);
  error = ph_configuration_transaction(arg);
  sem_unlock(sem_usbhc);        
  return error;    
}
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//
//      Физический уровень драйвера 
//
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
#define REG_PIPE   *pipe->reg
//-------------------------------------------------------------------------------------------------
uint8 hub_standard_device_descriptor[] =
{
  0x12, 0x01, 0x00, 0x02, 0x09, 0x00, 0x01, 0x40,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00
};
uint8 hub_standard_configuration_descriptor[] = 
{
  0x09, 0x02, 0x19, 0x00, 0x01, 0x01, 0x00, 0xe0,
  0x00, 0x09, 0x04, 0x00, 0x00, 0x01, 0x09, 0x00,
  0x00, 0x00, 0x07, 0x05, 0x81, 0x03, 0x01, 0x00,
  0x0C
};
uint8 hub_descriptor[] = 
{
  0x09, 0x29, 0x02, 0xa9, 0x00, 0x32, 0x00, 0x00,
  0xff
};
uint8 hub_status[] = {0x00, 0x00};
uint8 hub_port_status[][2] = {{0x00, 0x00},{0x00, 0x00}};
//Регистры пайпа хост контроллера:
struct s_usbhc_pipe_reg
{
  volatile uint16*   config1;
  volatile uint16*   config2;
  volatile uint16*   control1;
  volatile uint16*   control2;
  volatile uint16*   devinfo;
  volatile uint16*   hubinfo;
  volatile uint16*   length;
  volatile uint16*   tbt;
  volatile uint16*   bufport;
  volatile uint16*   status;
  volatile uint16*   intstatus;
  volatile uint16*   intenable;
};
struct s_usbhc_pipe
{
  volatile uint8     alloc;
  volatile uint32    sem;
  s_usbhc_config     config;
  s_usbhc_config_ep  endpoint;
  s_usbhc_pipe_reg   reg;
  s_int_exchange     intexch;
};
//Указатели на регистры порта HC:
struct s_reg_hcusbp
{
  volatile uint16*   status;
  volatile uint16*   intstatus;
  volatile uint16*   intenable;
};
struct s_usbhc_request
{
  volatile uint16    request;
  volatile uint16    value;
  volatile uint16    index;
  volatile uint16    length;
};
//-------------------------------------------------------------------------------------------------
uint16         usb_tr_complete;
//-------------------------------------------------------------------------------------------------
s_usbhc_pipe   hc_pipe[NUM_USBHC_PIPE];
//-------------------------------------------------------------------------------------------------
int32 ph_int_status__port_int(int32 port);
int32 ph_int_status__ep0_int();
int32 ph_int_status__pipe_int(int32 npipe);
//-------------------------------------------------------------------------------------------------
void ph_hc_write_bufport(uint16* dst_usb, uint8* src_mem, int32 size_in_byte);
void ph_hc_read_bufport(uint8* dst_mem, uint16* src_usb, int32 size_in_byte);
//-------------------------------------------------------------------------------------------------
int32 mch_hoot__setup(s_usbhc_bulk* tsk);
int32 mch_hoot__data_in(s_usbhc_bulk* tsk);
int32 mch_hoot__status_out(s_usbhc_bulk* tsk);
int32 mch_hoot__status(s_usbhc_bulk* tsk);
//-------------------------------------------------------------------------------------------------
int32 get_s_reg_hcusbp(int32 port, s_reg_hcusbp* hcusbp);

int32         hc_pipe_get_count_free();
int32         hc_pipe_number(s_usbhc_pipe* pipe);
int32         hc_pipe_free(s_usbhc_pipe* pipe);
s_usbhc_pipe* hc_pipe_alloc();
s_usbhc_pipe* hc_pipe_resource(uint8 device_address, uint8 endpoint_number);
/**************************************************************************************************\
*   Обработчик прерывания от контроллера
\***sss********************************************************************************************/
uint16 reg_int_status = 0;
static void usbhc_interrupt()
{
  reg_int_status = REG_INT_STATUS;
  //Прерывание ПОРТ1:
  if(reg_int_status & BM_PORT1INT) 
    ph_int_status__port_int(0);
  //Прерывание ПОРТ2:
  else if(reg_int_status & BM_PORT2INT) 
    ph_int_status__port_int(1); 
  //Прерывание 0EP:
  else if(reg_int_status & BM_HCEP0INT) 
    ph_int_status__ep0_int();
  //Прерывание Pipe 0:
  else if(reg_int_status & BM_PIPE1INT)
    ph_int_status__pipe_int(0);
  //Прерывание Pipe 1:
  else if(reg_int_status & BM_PIPE2INT)
    ph_int_status__pipe_int(1);
  //Прерывание Pipe 2:
  else if(reg_int_status & BM_PIPE3INT)
    ph_int_status__pipe_int(2);
  //Прерывание Pipe 3:
  else if(reg_int_status & BM_PIPE4INT)
    ph_int_status__pipe_int(3);
  //Прерывание Pipe 4:
  else if(reg_int_status & BM_PIPE5INT)
    ph_int_status__pipe_int(4);
  //Прерывание Pipe 5:
  else if(reg_int_status & BM_PIPE6INT)
    ph_int_status__pipe_int(5);
  //Прерывание Pipe 6:
  else if(reg_int_status & BM_PIPE7INT)
    ph_int_status__pipe_int(6);
  //Прерывание Pipe 7:
  else if(reg_int_status & BM_PIPE8INT)
    ph_int_status__pipe_int(7);
  //Прерывание Pipe 8:
  else if(reg_int_status & BM_PIPE9INT)
    ph_int_status__pipe_int(8);
  else
    asm(" nop");
  asm(" nop");    
}
//**************************************************************************************************
//  машина состояния порта
//***sss********************************************************************************************
int32 ph_int_status__port_int(int32 port)
{
  int32         error;
  s_reg_hcusbp  hcusbp;
  error = get_s_reg_hcusbp(port, &hcusbp);
  if( error != OSE_OK ) return error;
  //if(hoot.exchange.exchange != 1)
  //{
  //  //*hcusbp.intstatus = *hcusbp.intstatus;
  //  return OSE_NOT_INITIALIZED;
  //}
  hoot.exchange.exchange = 0;
  if(hoot.exchange.sem != RES_VOID)
    sem_unlock_sw(hoot.exchange.sem);
  if(hoot.exchange.flag != NULL)
    *hoot.exchange.flag = 0xA0|(port&0xF);  
  *(uint8*)hoot.exchange.data = 0x2<<port;
  //*hcusbp.intstatus = *hcusbp.intstatus;
  return OSE_OK;
}
//**************************************************************************************************
//  машина состояния нулевой конечной точки:
//***sss********************************************************************************************
int32 ph_int_status__ep0_int()
{
  usb_tr_complete |= BM_HCEP0INT;  
  sem_unlock_sw(sem_usbtr);  
  return OSE_OK;
}
//**************************************************************************************************
//  машина состояния пайпа:
//***sss********************************************************************************************
int32 ph_int_status__pipe_int(int32 npipe)
{
  usb_tr_complete |= (BM_PIPE1INT<<npipe);  
  sem_unlock_sw(sem_usbtr);  
  return OSE_OK;
}
/**************************************************************************************************\
*   Инициализация HC
\***sss********************************************************************************************/
static int32 ph_hc_init()
{
  uint64 ctime, ltime;
  uint16 wrval, rdval;
  
  ltime = time_m() + 500;
  while( true )
  {
    if( REG_ID == 0x120 ) break;
    ctime = time_m();
    if( ctime >= ltime ) return OSE_NO_DRIVER;
  }
  REG_POWER_CONTROL = BM_ALLRST;
  ltime = time_m() + 500;
  while( true )
  {
    if( REG_ID == 0x120 ) break;
    ctime = time_m();
    if( ctime >= ltime ) return OSE_NO_DRIVER;
  }  
  REG_SYSTEM_CONFIG = BM_INT_POL|BM_INT_SEL;
  REG_USB_CONFIG = BM_PPC|BM_P2_E|BM_P1_E;
  REG_INT_ENABLE = BM_HCEP0INT_E|BM_PORT2INT_E|BM_PORT1INT_E;
  REG_HCUSBP1_INTENABLE = 0x0;//BM_PRSC_E|BM_OCIC_E|BM_SUSPENDC_E|BM_PESC_E|BM_CSC_E;
  REG_HCUSBP2_INTENABLE = 0x0;//BM_PRSC_E|BM_OCIC_E|BM_SUSPENDC_E|BM_PESC_E|BM_CSC_E;
  REG_HCEP0_INTENABLE = BM_EP0IE_HALT_E|BM_EP0IE_NULL_E|BM_EP0IE_ORUN_E|BM_EP0IE_SHORT_E|BM_EP0IE_COMPLETE_E|BM_EP0IE_OUTDT_E|BM_EP0IE_STALL_E|BM_EP0IE_INDT_E;
  REG_PIPE_INTENABLE_1 = 0x0;  
  REG_PIPE_INTENABLE_2 = 0x0;  
  REG_PIPE_INTENABLE_3 = 0x0;  
  REG_PIPE_INTENABLE_4 = 0x0;        
  REG_PIPE_INTENABLE_5 = 0x0;  
  REG_PIPE_INTENABLE_6 = 0x0;      
  REG_PIPE_INTENABLE_7 = 0x0;  
  REG_PIPE_INTENABLE_8 = 0x0;      
  REG_PIPE_INTENABLE_9 = 0x0;    
  
  REG_INT_STATUS         = BM_INT_STATUS_CLR_ALL;
  REG_HCUSBP1_INTSTATUS  = BM_HCUSBP1_INTSTATUS_CLR_ALL;
  REG_HCUSBP2_INTSTATUS  = BM_HCUSBP2_INTSTATUS_CLR_ALL;
  REG_HCEP0_INTSTATUS    = BM_HCEP0_INTSTATUS_CLR_ALL;
  REG_PIPE_INTSTATUS_1 = BM_PIPEIS_INTSTATUS_CLR_ALL;
  REG_PIPE_INTSTATUS_2 = BM_PIPEIS_INTSTATUS_CLR_ALL;
  REG_PIPE_INTSTATUS_3 = BM_PIPEIS_INTSTATUS_CLR_ALL;
  REG_PIPE_INTSTATUS_4 = BM_PIPEIS_INTSTATUS_CLR_ALL;
  REG_PIPE_INTSTATUS_5 = BM_PIPEIS_INTSTATUS_CLR_ALL;
  REG_PIPE_INTSTATUS_6 = BM_PIPEIS_INTSTATUS_CLR_ALL;
  REG_PIPE_INTSTATUS_7 = BM_PIPEIS_INTSTATUS_CLR_ALL;
  REG_PIPE_INTSTATUS_8 = BM_PIPEIS_INTSTATUS_CLR_ALL;
  REG_PIPE_INTSTATUS_9 = BM_PIPEIS_INTSTATUS_CLR_ALL;

  //Инициализация переменных ROOT HUB:
  hoot.address = 0x0;
  hoot.configuration = 0x1;
  hoot.next_toggle0 = 0;
  memset(&hoot.mstate, 0x0, sizeof(s_mch_hoot));
  hoot.mstate.function = &mch_hoot__setup;
  hoot.buf = NULL;
  memset(&hoot.request, 0x0, sizeof(s_usb_request));
  hoot.dsc_device = (s_standard_device_descriptor*) hub_standard_device_descriptor;
  hoot.dsc_config = (s_standard_configuration_descriptor*) (&hub_standard_configuration_descriptor[0]); 
  hoot.dsc_interface = (s_standard_interface_descriptor*) (&hub_standard_configuration_descriptor[9]);
  hoot.dsc_endpoint = (s_standard_endpoint_descriptor*) (&hub_standard_configuration_descriptor[18]); 
  hoot.dsc_hub = (s_hub_descriptor*) hub_descriptor;
  hoot.dsc_hub_status = (s_hub_status*) hub_status;
  hoot.dsc_hub_port[0] = (s_hub_port_status*) &REG_HCUSBP1_STATUS;
  hoot.dsc_hub_port[1] = (s_hub_port_status*) &REG_HCUSBP2_STATUS;  
  
  for(int32 i=0; i<NUM_USBHC_PIPE; i++ )
  {
    hc_pipe[i].alloc = 0x0;
    hc_pipe[i].sem = RES_VOID;
    memset(&hc_pipe[i].config, 0x0, sizeof(s_usbhc_config));
    memset(&hc_pipe[i].endpoint, 0x0, sizeof(s_usbhc_config_ep));  
    memset(&hc_pipe[i].intexch, 0x0, sizeof(s_int_exchange));
    hc_pipe[i].reg.config1   = DREG_PIPE_CONFIG1(i);
    hc_pipe[i].reg.config2   = DREG_PIPE_CONFIG2(i);
    hc_pipe[i].reg.control1  = DREG_PIPE_CONTROL1(i);
    hc_pipe[i].reg.control2  = DREG_PIPE_CONTROL2(i);
    hc_pipe[i].reg.devinfo   = DREG_PIPE_DEVINFO(i);
    hc_pipe[i].reg.hubinfo   = DREG_PIPE_HUBINFO(i);
    hc_pipe[i].reg.length    = DREG_PIPE_LENGTH(i);
    hc_pipe[i].reg.tbt       = DREG_PIPE_TBT(i);
    hc_pipe[i].reg.bufport   = DREG_PIPE_BUFPORT(i);
    hc_pipe[i].reg.status    = DREG_PIPE_STATUS(i);
    hc_pipe[i].reg.intstatus = DREG_PIPE_INTSTATUS(i);
    hc_pipe[i].reg.intenable = DREG_PIPE_INTENABLE(i);
  }
  usb_tr_complete = 0;      

  //Test:
  REG_USB_CONFIG |= 0x4;
  for(int32 i=0; i<16; i++)
  {
    wrval = 0x1 << i;
    REG_SCRATCHPAD = wrval;
    rdval = REG_SCRATCHPAD;
    if(wrval != rdval) 
      return OSE_DATA_TEST_ERROR;
  }
  REG_USB_CONFIG &= ~0x4;
  return OSE_OK;
}
/**************************************************************************************************\
*   Выполнение BULK транзакция
\***sss********************************************************************************************/
int32 usbhc_bulk_wait_interrupt(uint16 mask_tr_complete)
{
  int32 error;
  while( (usb_tr_complete & mask_tr_complete) == 0 )
  {
    error = sem_lock(sem_usbtr, 5000);
    if(error != SEM_OK)
    {
      asm(" nop");
      break;
    }  
  }
  usb_tr_complete &= ~mask_tr_complete;
  return error;
}
//--------------------------------------------------------------------------------------------------
int32 usbhc_bulk_control_transaction(s_usbhc_bulk* tsk)
{
  int32  error;
  s_usbhc_request* req = (s_usbhc_request*)tsk->irp.data;
  switch(tsk->irp.token)
  {
    case USB_SETUP_TOKEN:
    {
      //Setting transfer request (TR):
      REG_HCEP0_CONFIG    = (tsk->irp.device_speed<<12)|tsk->irp.max_packet_length;
      REG_HCEP0_USBREQ    = req->request;
      REG_HCEP0_USBVALUE  = req->value;
      REG_HCEP0_USBINDEX  = req->index;
      REG_HCEP0_USBLENGTH = req->length;
      REG_HCEP0_DEVINFO   = tsk->irp.device_address;
      
      REG_HCEP0_CONTROL   = BM_EP0C_PID_SETUP|BM_EP0C_DPID_CLR;
      REG_HCEP0_CONFIG   |= BM_SET;
      while((REG_HCEP0_STATUS & BM_EP0S_CONF) == 0);

      //Setup Stage start <TR active>:
      REG_HCEP0_CONTROL |= BM_EP0C_ACTIVE;
      
      usbhc_bulk_wait_interrupt(BM_HCEP0INT);

      if(REG_HCEP0_INTSTATUS & (BM_EP0IS_HALT|BM_EP0IS_STALL)) error = USB_ER_STALL;
      else if (REG_HCEP0_INTSTATUS & BM_EP0IS_COMPLETE) error = 0x0;
      else error = OSE_FAIL;
      REG_HCEP0_INTSTATUS = REG_HCEP0_INTSTATUS;
      return error;
    }
    case USB_IN_TOKEN:
    {
      //Setting transfer request (TR):
      REG_HCEP0_TBT = tsk->irp.size;
      REG_HCEP0_CONTROL = BM_EP0C_PID_IN|BM_EP0C_DPID_SET;
      //Data Stage start <TR active>:
      REG_HCEP0_CONTROL |= BM_EP0C_ACTIVE;

      usbhc_bulk_wait_interrupt(BM_HCEP0INT);      
     
      //Data transfer / Data Stage complete <TR inactive>:
      if(REG_HCEP0_INTSTATUS & (BM_EP0IS_HALT|BM_EP0IS_STALL)) 
        error = USB_ER_STALL;
      else
      {
        if(REG_HCEP0_INTSTATUS & (BM_EP0IS_INDT | BM_EP0IS_SHORT | BM_EP0IS_NULL))
        {
          //Reading received data:
          if(REG_HCEP0_LENGTH == tsk->irp.size)
          {
            ph_hc_read_bufport((uint8*)tsk->irp.data, (uint16*)&REG_HCEP0_BUFPORT, tsk->irp.size);
          }
        }
        if (REG_HCEP0_INTSTATUS & BM_EP0IS_COMPLETE) 
          error = 0x0;
        else 
          error = OSE_FAIL;
      }

      REG_HCEP0_INTSTATUS = REG_HCEP0_INTSTATUS;
      return error;
    }
    case USB_OUT_TOKEN:
    {
      //Setting transfer request (TR):
      REG_HCEP0_TBT      = tsk->irp.size;
      REG_HCEP0_CONTROL  = BM_EP0C_PID_OUT|BM_EP0C_DPID_SET;
      //Data Stage start <TR active>:
      REG_HCEP0_CONTROL |= BM_EP0C_ACTIVE;
      //Data transfer / Data Stage complete <TR inactive>:
      while(true)
      {
        bool             complete = false;

        ph_hc_write_bufport((uint16*)&REG_HCEP0_BUFPORT, (uint8*)tsk->irp.data, tsk->irp.size);

        REG_HCEP0_CONTROL |= BM_EP0C_DEND;

        usbhc_bulk_wait_interrupt(BM_HCEP0INT);        

        if(REG_HCEP0_INTSTATUS & (BM_EP0IS_HALT|BM_EP0IS_STALL))
        {
          complete = true;
          error = USB_ER_STALL;
        }
        else if(REG_HCEP0_INTSTATUS & BM_EP0IS_OUTDT)
        {
          complete = false;
        }
        else if(REG_HCEP0_INTSTATUS & BM_EP0IS_COMPLETE) 
        {
          complete = true;
          error = 0x0;
        }
        else
        {
          complete = true;
          error = OSE_FAIL;
        }
        REG_HCEP0_INTSTATUS = REG_HCEP0_INTSTATUS;
        if(complete == true) break;
      }
      return error;
    }
    default: return OSE_BAD_DATA;
  }
}
//--------------------------------------------------------------------------------------------------
int32 usbhc_bulk_out_transaction(s_usbhc_bulk* tsk, s_usbhc_pipe* pipe, int32 npipe)
{
  int32          error;
  register int32 size;
  register int32 size_left;  
  
  REG_PIPE.intstatus |= BM_PIPEIS_OUTDT;
  REG_PIPE.intenable |= BM_PIPEIE_OUTDT_E;
  REG_PIPE.control1 &= ~BM_PIPE_AUTO;
  
  size_left = tsk->irp.size;
  while(true)
  {
    size = (size_left < tsk->irp.max_packet_length) ? size_left : tsk->irp.max_packet_length;
        
    //Writing data to send:
    ph_hc_write_bufport((uint16*)pipe->reg.bufport, &((uint8*)tsk->irp.data)[tsk->irp.size-size_left], size);
    REG_PIPE.control2 |= BM_PIPE_DEND;
        
    error = usbhc_bulk_wait_interrupt(BM_PIPE1INT << npipe);
    if( error != OSE_OK )
      return OSE_TIMEOUT;  
        
    if(REG_PIPE.intstatus & (BM_PIPEIS_HALT|BM_PIPEIS_STALL)) 
    {
      REG_PIPE.intstatus = REG_PIPE.intstatus;
      return USB_ER_STALL;
    }
    if(REG_PIPE.intstatus & BM_PIPEIS_COMPLETE) 
    {
      size_left -= size;
      REG_PIPE.intstatus = REG_PIPE.intstatus;      
      return 0x0;
    }
    if(REG_PIPE.intstatus & BM_PIPEIS_OUTDT)
    {
      size_left -= size;
      REG_PIPE.intstatus = REG_PIPE.intstatus;          
      continue;
    }
    return OSE_BAD_DATA;
  }

}
//--------------------------------------------------------------------------------------------------
int32 usbhc_bulk_in_transaction(s_usbhc_bulk* tsk, s_usbhc_pipe* pipe, int32 npipe)
{
  int32          error;
  register int32 size;
  register int32 size_left;  

  size_left = tsk->irp.size;
      
  error = usbhc_bulk_wait_interrupt(BM_PIPE1INT << npipe);
  if( error != OSE_OK )
    return OSE_TIMEOUT;  
      
  while(true)
  {
    size = (size_left < tsk->irp.max_packet_length) ? size_left : tsk->irp.max_packet_length;
      
    //Data transfer / Data Stage complete <TR inactive>:
    if(REG_PIPE.intstatus & (BM_PIPEIS_HALT|BM_PIPEIS_STALL|BM_PIPEIS_ORUN)) 
    {
      REG_PIPE.intstatus = REG_PIPE.intstatus;
      return USB_ER_STALL;
    }
    if(REG_PIPE.intstatus & (BM_PIPEIS_INDT|BM_PIPEIS_SHORT|BM_PIPEIS_NULL))
    {
      //Reading received data:
      if(REG_PIPE.length == size)
      {
        ph_hc_read_bufport(&((uint8*)tsk->irp.data)[tsk->irp.size-size_left], (uint16*)pipe->reg.bufport, size);
        size_left -= size;
      }
    }
    if(REG_PIPE.intstatus & BM_PIPEIS_COMPLETE) 
    {
      REG_PIPE.intstatus = REG_PIPE.intstatus;
      return 0x0;
    }
  }
}
//--------------------------------------------------------------------------------------------------
int32 usbhc_bulk_transaction(s_usbhc_bulk* tsk)
{
  int32 error, npipe;
  s_usbhc_pipe* pipe;

  pipe = hc_pipe_resource(tsk->irp.device_address, tsk->irp.endpoint_number);
  if(pipe == NULL) return OSE_BAD_DATA;  
  npipe = hc_pipe_number(pipe);

  //Preparation for data transfer:
  REG_PIPE.tbt = tsk->irp.size;
  switch(tsk->irp.token)
  {
    case USB_OUT_TOKEN: REG_PIPE.intenable = BM_PIPEIE_HALT_E|BM_PIPEIE_COMPLETE_E|BM_PIPEIE_STALL_E; break;
    case USB_IN_TOKEN:  REG_PIPE.intenable = BM_PIPEIE_HALT_E|BM_PIPEIE_NULL_E|BM_PIPEIE_ORUN_E|BM_PIPEIE_SHORT_E|BM_PIPEIE_COMPLETE_E|BM_PIPEIE_STALL_E|BM_PIPEIE_INDT_E; break;
    default: return OSE_BAD_DATA;
  }
  REG_PIPE.control2 |= BM_PIPE_ACTIVE;
  switch(tsk->irp.token)
  {
    case USB_OUT_TOKEN: error = usbhc_bulk_out_transaction(tsk, pipe, npipe); break;
    case USB_IN_TOKEN:  error = usbhc_bulk_in_transaction(tsk, pipe, npipe);  break;
  }
  switch(tsk->irp.token)
  {
    case USB_OUT_TOKEN: REG_PIPE.intenable = 0x0000; break;
    case USB_IN_TOKEN:  REG_PIPE.intenable = 0x0000; break;
  }  
  return error;
}
//--------------------------------------------------------------------------------------------------
static int32 ph_bulk_transaction(s_usbhc_bulk* tsk)
{
  switch(tsk->irp.endpoint_type)
  {
    case USB_CONTROL_TYPE: return usbhc_bulk_control_transaction(tsk);
    case USB_BULK_TYPE:    return usbhc_bulk_transaction(tsk);
    default:               return OSE_BAD_DATA;
  }
}
/**************************************************************************************************\
*   Выполнение INTERRUPT транзакция
\***sss********************************************************************************************/
int32 usbhc_interrup_out_transaction(s_usbhc_s_interrupt* tsk, s_usbhc_pipe* pipe, int32 npipe)
{
  return OSE_BAD_DATA;
}
//--------------------------------------------------------------------------------------------------
int32 usbhc_interrup_in_transaction(s_usbhc_s_interrupt* tsk, s_usbhc_pipe* pipe, int32 npipe)
{
  int32          error;
  register int32 size;
  register int32 size_left;  

  size_left = tsk->irp.size;
      
  error = usbhc_bulk_wait_interrupt(BM_PIPE1INT << npipe);
  if( error != OSE_OK )
    return OSE_TIMEOUT;  
      
  while(true)
  {
    size = (size_left < tsk->irp.max_packet_length) ? size_left : tsk->irp.max_packet_length;
      
    //Data transfer / Data Stage complete <TR inactive>:
    if(REG_PIPE.intstatus & (BM_PIPEIS_HALT|BM_PIPEIS_STALL|BM_PIPEIS_ORUN)) 
    {
      REG_PIPE.intstatus = REG_PIPE.intstatus;
      return USB_ER_STALL;
    }
    if(REG_PIPE.intstatus & (BM_PIPEIS_INDT|BM_PIPEIS_SHORT|BM_PIPEIS_NULL))
    {
      //Reading received data:
      if(REG_PIPE.length == size)
      {
        ph_hc_read_bufport(&((uint8*)tsk->irp.data)[tsk->irp.size-size_left], (uint16*)pipe->reg.bufport, size);
        size_left -= size;
      }
    }
    if(REG_PIPE.intstatus & BM_PIPEIS_COMPLETE) 
    {
      REG_PIPE.intstatus = REG_PIPE.intstatus;
      return 0x0;
    }
  }
}
//--------------------------------------------------------------------------------------------------
int32 usbhc_start_interrupt_transaction(s_usbhc_s_interrupt* tsk)
{
  int32 error, npipe;
  s_usbhc_pipe* pipe;
  error = 0x0;
  pipe = hc_pipe_resource(tsk->irp.device_address, tsk->irp.endpoint_number);
  if(pipe == NULL) return OSE_BAD_DATA;  
  npipe = hc_pipe_number(pipe);

  //Preparation for data transfer:
  REG_PIPE.tbt = tsk->irp.size;
  switch(tsk->irp.token)
  {
    case USB_OUT_TOKEN: REG_PIPE.intenable = BM_PIPEIE_HALT_E|BM_PIPEIE_COMPLETE_E|BM_PIPEIE_STALL_E; break;
    case USB_IN_TOKEN:  REG_PIPE.intenable = BM_PIPEIE_HALT_E|BM_PIPEIE_NULL_E|BM_PIPEIE_ORUN_E|BM_PIPEIE_SHORT_E|BM_PIPEIE_COMPLETE_E|BM_PIPEIE_STALL_E|BM_PIPEIE_INDT_E; break;
    default: return OSE_BAD_DATA;
  }

  s_int_exchange* prt_ex_int_ptd = &pipe->intexch;  
  *tsk->id = npipe;
  prt_ex_int_ptd->exchange = 1;
  prt_ex_int_ptd->flag     = tsk->flag;
  prt_ex_int_ptd->sem      = tsk->sem;
  prt_ex_int_ptd->data     = tsk->irp.data;
  prt_ex_int_ptd->name     = tsk->name;
  prt_ex_int_ptd->size     = tsk->irp.size;
  
  REG_PIPE.control2 |= BM_PIPE_ACTIVE;
/*  
  switch(tsk->irp.token)
  {
    case USB_OUT_TOKEN: error = usbhc_interrup_out_transaction(tsk, pipe, npipe); break;
    case USB_IN_TOKEN:  error = usbhc_interrup_in_transaction(tsk, pipe, npipe);  break;
  }
  switch(tsk->irp.token)
  {
    case USB_OUT_TOKEN: REG_PIPE.intenable = 0x0000; break;
    case USB_IN_TOKEN:  REG_PIPE.intenable = 0x0000; break;
  }
*/
  return error;
}
//--------------------------------------------------------------------------------------------------
static int32 ph_start_interrupt_transaction(s_usbhc_s_interrupt* tsk)
{
  switch(tsk->irp.endpoint_type)
  {
    case USB_INTERRUPT_TYPE: return usbhc_start_interrupt_transaction(tsk);
    default:                 return OSE_BAD_DATA;
  }
}
//==================================================================================================
static int32 ph_complete_interrupt_transaction(s_usbhc_c_interrupt* tsk)
{
  return USB_ER_STALL;
}
/**************************************************************************************************\
*   Конфигурация PIPE-ов
\***sss********************************************************************************************/
int32 ph_configuration_connect(s_usbhc_config* tsk)
{
  uint16        bm_tr_type, bm_dir, bm_itvl;
  int32         npipe;
  s_usbhc_pipe* pipe;
  if( hc_pipe_get_count_free() < tsk->number_endpoints ) return OSE_RESOURCE_LIMIT_REACHED;
  
  for(int32 i=0; i<tsk->number_endpoints; i++)
  {
    pipe = hc_pipe_alloc();
    npipe = hc_pipe_number(pipe);
    memcpy( &pipe->config, tsk, sizeof(s_usbhc_config) );
    memcpy( &pipe->endpoint, &tsk->endpoint[i], sizeof(s_usbhc_config_ep) );    
    memset( &pipe->intexch, 0x0, sizeof(s_int_exchange));
    pipe->config.endpoint = &pipe->endpoint;
    //Pipe configuration (Setting endpoint information):
    bm_tr_type = ( pipe->endpoint.attributes & USB_TRANSFER_TYPE_MASK ) << 2; 
	switch(pipe->endpoint.attributes & USB_TRANSFER_TYPE_MASK)
	{
      case USB_INTERRUPT_TYPE: bm_itvl = pipe->config.endpoint->interval; break;
	  default:                 bm_itvl = 0x0; 
	}
    switch(pipe->endpoint.endpoint_number & ENDPOINT_DIRECTION_MASK) 
    {
      case ENDPOINT_OUT: bm_dir = BM_DIR_OUT; break; 
      case ENDPOINT_IN:  bm_dir = BM_DIR_IN;  break; 
    }
    //Checking unused pipe number:
    REG_PIPE.config1  = 0x0000;
    REG_PIPE.config1 &= ~BM_PIPE_EN;
    //Pipe configuration (Setting endpoint information):    
    REG_PIPE.config1  = BM_BUFTYPE_S|bm_itvl|bm_tr_type|bm_dir|BM_PIPE_DIS;    
    REG_PIPE.config1 |= (pipe->endpoint.endpoint_number & 0xf)<<4;
    REG_PIPE.config2  = (pipe->config.device_speed<<12)|pipe->endpoint.max_packet_size;
    REG_PIPE.devinfo  = pipe->config.device_address;
    //Enabling pipe:
    REG_PIPE.config1 |= BM_PIPE_EN;
    sleep_m(10);
    while( (REG_PIPE.intstatus & BM_PIPEIE_SM_CONF_E)==0 );
    REG_PIPE.intstatus |= BM_PIPEIE_SM_CONF_E;
    //REG_PIPE.intenable  = BM_PIPEIE_SM_ERR_E|BM_PIPEIE_BYTE_E|BM_PIPEIE_HALT_E|BM_PIPEIE_NULL_E|BM_PIPEIE_ORUN_E|BM_PIPEIE_SHORT_E|BM_PIPEIE_SM_CONF_E|BM_PIPEIE_COMPLETE_E|BM_PIPEIE_OUTDT_E|BM_PIPEIE_STALL_E|BM_PIPEIE_INDT_E;
    REG_INT_ENABLE |= ( BM_PIPE1INT_E << npipe );
  }
  return OSE_OK; 
}
/**************************************************************************************************/
int32 ph_configuration_disconnect(s_usbhc_config* tsk)
{
  int32         npipe;
  int32         error = OSE_OK;
  s_usbhc_pipe* pipe;
  for(int32 i=0; i<tsk->number_endpoints; i++)
  {
    pipe = hc_pipe_resource(tsk->device_address, tsk->endpoint[i].endpoint_number);
    if(pipe == NULL) continue;
    npipe = hc_pipe_number(pipe);    
    
    while( (REG_PIPE.status & BM_PIPEST_ACTIVE) != 0 );
    //Disabling pipe:
    REG_PIPE.config1 &= ~BM_PIPE_EN;
    //Confirmation of pipe unconfiguration
    while( (REG_PIPE.config1 & BM_PIPE_EN) != 0 );
    //Disabling pipe interrupts:
    REG_INT_ENABLE &= ~( BM_PIPE1INT_E << npipe );
    REG_PIPE.intenable  = 0x0;    
    error |= hc_pipe_free(pipe);
  }
  error = (error == OSE_OK) ? OSE_OK : OSE_BAD_RESOURCE_INDEX;
  return error; 
}
/**************************************************************************************************/
static int32 ph_configuration_transaction(s_usbhc_config* tsk)
{
  if( tsk->connect_flag ) return ph_configuration_connect(tsk);
  else return ph_configuration_disconnect(tsk);
}
/**************************************************************************************************\
*   Запись в хост
\***sss********************************************************************************************/
void ph_hc_write_bufport(uint16* dst_usb, uint8* src_mem, int32 size_in_byte)
{
  register uint16  data;
  register int32   i=0;
  //Writing data to send:
  while(i < (size_in_byte & ~0x1) )
  {
    data  = src_mem[i++];
    data |= src_mem[i++] << 0x8;
    *dst_usb = data;
  }
  if(size_in_byte & 0x1)
  {
    data  = src_mem[i++];
    *dst_usb = data;
  }
}
/**************************************************************************************************\
*   Четение из хоста
\***sss********************************************************************************************/
void ph_hc_read_bufport(uint8* dst_mem, uint16* src_usb, int32 size_in_byte)
{
  register uint16  data;
  register int32   i=0;
  while(i < (size_in_byte & ~0x1) )
  {
    data = *src_usb;
    dst_mem[i++] = data & 0xff;
    dst_mem[i++] = data >> 0x8;
  }
  if(size_in_byte & 0x1)
  {
    data = *src_usb;
    dst_mem[i++] = data & 0xff;
  }
}
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//
//      Функции работы с ROOT HUB
//
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
int32 ctl_set_address(int32 addr);
int32 ctl_set_config(int32 cfg);
int32 ctl_set_port_feature(int32 port, int32 feature);
int32 ctl_clear_port_feature(int32 port, int32 feature);
/**************************************************************************************************\
*   "BULK транзакция" root hub
\***sss********************************************************************************************/
static int32 ph_hoot_bulk_transaction(s_usbhc_bulk* tsk)
{
  int32 error;
  if(tsk->irp.endpoint_number != 0x0) return USB_ER_STALL;
  error = hoot.mstate.function(tsk);
  *tsk->next_data_toggle = hoot.next_toggle0;
  return error;
}
/**************************************************************************************************\
*   Начало "INTERRUPT транзакция" root hub
\***sss********************************************************************************************/
static int32 ph_hoot_start_interrupt_transaction(s_usbhc_s_interrupt* tsk)
{
  hoot.exchange.exchange = 1;
  hoot.exchange.flag     = tsk->flag;
  hoot.exchange.sem      = tsk->sem;
  hoot.exchange.data     = tsk->irp.data;
  hoot.exchange.name     = tsk->name;
  hoot.exchange.size     = tsk->irp.size;
  REG_INT_ENABLE |= BM_PORT2INT_E|BM_PORT1INT_E;
  REG_HCUSBP1_INTENABLE = BM_PRSC_E|BM_OCIC_E|BM_SUSPENDC_E|BM_PESC_E|BM_CSC_E;
  REG_HCUSBP2_INTENABLE = BM_PRSC_E|BM_OCIC_E|BM_SUSPENDC_E|BM_PESC_E|BM_CSC_E;  
  return OSE_OK;
}
/**************************************************************************************************\
*   Конец "INTERRUPT транзакция" root hub
\***sss********************************************************************************************/
static int32 ph_hoot_complete_interrupt_transaction(s_usbhc_c_interrupt* tsk)
{
  return OSE_OK;
}
//oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
//
//  Машина состояние EP0 ROOT HUB
//  
//oosssooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
/**************************************************************************************************\
*   SETUP
\***sss********************************************************************************************/
int32 hoot_request_type_device(s_usbhc_irp* irp);
int32 hoot_request_type_other(s_usbhc_irp* irp);
//--------------------------------------------------------------------------------------------------
int32 mch_hoot__setup(s_usbhc_bulk* tsk)
{
  int32 error = USB_ER_STALL;
  if(tsk->irp.data_toggle != hoot.next_toggle0) return USB_ER_STALL;
  if(sizeof(s_usb_request) != tsk->irp.size) return USB_ER_STALL;

  s_usb_request* rq = (s_usb_request*)tsk->irp.data;
  switch(rq->request_type & 0x80)
  {
    //Хост передает устройству:
    case USB_REQUEST_TYPE_HOST_DEV:
    {
      switch(rq->request_type & 0x40)
      {
        case USB_REQUEST_TYPE_STANDARD:
        {
          switch(rq->request_type & 0x03)
          {
            case USB_REQUEST_TYPE_DEVICE: error = hoot_request_type_device(&tsk->irp); break;
            case USB_REQUEST_TYPE_INTERFACE: break;
            case USB_REQUEST_TYPE_ENDPOINT: break;
            case USB_REQUEST_TYPE_OTHER: error = hoot_request_type_other(&tsk->irp); break;
          }
        }
        break;
        case USB_REQUEST_TYPE_CLASS: break;        
        case USB_REQUEST_TYPE_VENDOR: break;         
      }
    }
    break;
    //Устройство передает хосту:    
    case USB_REQUEST_TYPE_DEV_HOST:
    {
      switch(rq->request_type & 0x40)
      {
        case USB_REQUEST_TYPE_STANDARD:
        {
          switch(rq->request_type & 0x03)
          {
            case USB_REQUEST_TYPE_DEVICE: error = hoot_request_type_device(&tsk->irp); break;
            case USB_REQUEST_TYPE_INTERFACE: break;
            case USB_REQUEST_TYPE_ENDPOINT: break;
            case USB_REQUEST_TYPE_OTHER: error = hoot_request_type_other(&tsk->irp); break;
          }
        }
        break;
        case USB_REQUEST_TYPE_CLASS: break;        
        case USB_REQUEST_TYPE_VENDOR: break;        
      }
    }
    break;    
  }
  if(!error) hoot.next_toggle0 = 1;
//  else hoot.mfunc = &mch_hoot__setup;
  return error;
}
//--------------------------------------------------------------------------------------------------
int32 hoot_request_type_device(s_usbhc_irp* irp)
{
  int32 error = USB_ER_STALL;
  s_usb_request* rq = (s_usb_request*)irp->data;
  switch(rq->request)
  {
    case USB_REQUEST_GET_DESCRIPTOR:
    {
      switch( rq->value>>8 & 0xff )
      {
        case USB_DEVICE_DESCRIPTOR_TYPE: 
        {
          hoot.buf = (uint8*) hoot.dsc_device;
          hoot.mstate.function = &mch_hoot__data_in;
          memcpy(&hoot.request, irp->data, sizeof(s_usb_request));
          error = OSE_OK;
        }
        break;
        case USB_CONFIGURATION_DESCRIPTOR_TYPE: 
        {
          hoot.buf = (uint8*) hoot.dsc_config;
          hoot.mstate.function = &mch_hoot__data_in;
          memcpy(&hoot.request, irp->data, sizeof(s_usb_request));
          error = OSE_OK;
        }
        break;
        case 0x00: //HUB DESCRIPTOR 
        {
          hoot.buf = (uint8*) hoot.dsc_hub;
          hoot.mstate.function = &mch_hoot__data_in;
          memcpy(&hoot.request, irp->data, sizeof(s_usb_request));
          error = OSE_OK;
        }
        break;
      }
    }
    break;
    case USB_REQUEST_SET_ADDRESS: 
    {
      hoot.buf = NULL;
      hoot.mstate.function = &mch_hoot__status;
      memcpy(&hoot.request, irp->data, sizeof(s_usb_request));
      hoot.mstate.control = (int (*)())&ctl_set_address;
      hoot.mstate.narg = 1; 
      hoot.mstate.arg[0] = rq->value;
      error = OSE_OK;
    }
    break;
    case USB_REQUEST_SET_CONFIGURATION:    
    {
      if( (rq->value > (hoot.dsc_device->num_configurations+1)) ) break;
      hoot.buf = NULL;
      hoot.mstate.function = &mch_hoot__status;
      memcpy(&hoot.request, irp->data, sizeof(s_usb_request));
      hoot.mstate.control = (int (*)())&ctl_set_config;
      hoot.mstate.narg = 1; 
      hoot.mstate.arg[0] = rq->value;
      error = OSE_OK;
    }    
    break;    
    case USB_REQUEST_GET_CONFIGURATION:
    {
      hoot.buf = (uint8*) &hoot.configuration;
      hoot.mstate.function = &mch_hoot__data_in;
      memcpy(&hoot.request, irp->data, sizeof(s_usb_request));
      error = OSE_OK;    
    }
    break;
    //HUB STATUS:
    case USB_REQUEST_GET_STATUS:
    {
      hoot.buf = (uint8*) hoot.dsc_hub_status;
      hoot.mstate.function = &mch_hoot__data_in;
      memcpy(&hoot.request, irp->data, sizeof(s_usb_request));
      error = OSE_OK;
    }
    break;
  }
  return error;
}
//--------------------------------------------------------------------------------------------------
int32 hoot_request_type_other(s_usbhc_irp* irp)
{
  int32 error = USB_ER_STALL;
  s_usb_request* rq = (s_usb_request*)irp->data;
  switch(rq->request)
  {
    //GET PORT STATUS:
    case USB_REQUEST_GET_STATUS:
    {
      hoot.buf = NULL;
      switch(rq->index & 0xf)
      {
        case 1: hoot.buf = (uint8*) hoot.dsc_hub_port[0]; break;
        case 2: hoot.buf = (uint8*) hoot.dsc_hub_port[1]; break;
      }
      if(hoot.buf == NULL) break;
      hoot.mstate.function = &mch_hoot__data_in;
      memcpy(&hoot.request, irp->data, sizeof(s_usb_request));
      error = OSE_OK;
    }
    break;
    case USB_REQUEST_SET_FEATURE:
    {
      int32 port = rq->index & 0xf;
      if( (port<1)||(port>2) ) break;
      hoot.mstate.function = &mch_hoot__status;
      memcpy(&hoot.request, irp->data, sizeof(s_usb_request));
      hoot.mstate.control = (int (*)())&ctl_set_port_feature;
      hoot.mstate.narg = 2;
      hoot.mstate.arg[0] = port;
      hoot.mstate.arg[1] = rq->value;
      error = OSE_OK;
    }
    break;
    case USB_REQUEST_CLEAR_FEATURE:
    {
      int32 port = rq->index & 0xf;
      if( (port<1)||(port>2) ) break;
      hoot.mstate.function = &mch_hoot__status;
      memcpy(&hoot.request, irp->data, sizeof(s_usb_request));
      hoot.mstate.control = (int (*)())&ctl_clear_port_feature;
      hoot.mstate.narg = 2;
      hoot.mstate.arg[0] = port;
      hoot.mstate.arg[1] = rq->value;
      error = OSE_OK; 
    }
    break;
  }
  return error;
}
/**************************************************************************************************\
*   DATA IN
\***sss********************************************************************************************/
int32 mch_hoot__data_in(s_usbhc_bulk* tsk)
{
  //Error control:
  if(tsk->irp.data_toggle != hoot.next_toggle0) 
  {
    hoot.next_toggle0 = 0;  
    hoot.mstate.function = &mch_hoot__setup;
    return USB_ER_STALL;
  }
  if(tsk->irp.size > hoot.dsc_device->max_packet_size_0) 
  {
    hoot.next_toggle0 = 0;  
    hoot.mstate.function = &mch_hoot__setup;
    return USB_ER_STALL;
  }
  if(tsk->irp.size > hoot.request.length)
  {
    hoot.next_toggle0 = 0;  
    hoot.mstate.function = &mch_hoot__setup;
    return USB_ER_STALL;    
  }
  memcpy(tsk->irp.data, hoot.buf, tsk->irp.size);
  hoot.request.length = hoot.request.length - tsk->irp.size;
  if(hoot.request.length == 0x0)
  {
    hoot.buf = NULL;  
    hoot.next_toggle0 = 1;
    hoot.mstate.function = &mch_hoot__status_out;      
  }
  else
  {
    hoot.buf = &hoot.buf[tsk->irp.size];
    hoot.next_toggle0 = (hoot.next_toggle0 + 1) & 0x1;
    hoot.mstate.function = &mch_hoot__data_in;    
  }    
  return OSE_OK;
}
/**************************************************************************************************\
*   STATUS OUT
\***sss********************************************************************************************/
int32 mch_hoot__status_out(s_usbhc_bulk* tsk)
{
  register int32 next_toggle0 = hoot.next_toggle0;
  hoot.next_toggle0 = 0;
  hoot.mstate.function = &mch_hoot__setup;
  //Error control:
  if(tsk->irp.data_toggle != next_toggle0) 
    return USB_ER_STALL;
  if(tsk->irp.size > hoot.dsc_device->max_packet_size_0) 
    return USB_ER_STALL;
  if(tsk->irp.size != 0x0)
    return USB_ER_STALL;    
  return OSE_OK;
}
/**************************************************************************************************\
*   STATUS
\***sss********************************************************************************************/
int32 mch_hoot__status(s_usbhc_bulk* tsk)
{
  register int32 next_toggle0 = hoot.next_toggle0;
  hoot.next_toggle0 = 0;  
  hoot.mstate.function = &mch_hoot__setup;
  //Error control:
  if(tsk->irp.data_toggle != next_toggle0) 
    return USB_ER_STALL;
  if(tsk->irp.size > hoot.dsc_device->max_packet_size_0) 
    return USB_ER_STALL;
  if(tsk->irp.size != 0x0)
    return USB_ER_STALL;    

  switch(hoot.mstate.narg)
  {
    case  1: return ((int32(*)(int32))hoot.mstate.control)(hoot.mstate.arg[0]);
    case  2: return ((int32(*)(int32,int32))hoot.mstate.control)(hoot.mstate.arg[0],hoot.mstate.arg[1]);
    case  3: return ((int32(*)(int32,int32,int32))hoot.mstate.control)(hoot.mstate.arg[0],hoot.mstate.arg[1],hoot.mstate.arg[2]);
    case  4: return ((int32(*)(int32,int32,int32,int32))hoot.mstate.control)(hoot.mstate.arg[0],hoot.mstate.arg[1],hoot.mstate.arg[2],hoot.mstate.arg[3]);
    default: return USB_ER_STALL;
  }
}
//oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
//
//  Управление ROOT HUB
//  
//oosssooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
/**************************************************************************************************\
*   Установка адреса
\***sss********************************************************************************************/
int32 ctl_set_address(int32 addr)
{
  hoot.address = addr;
  return OSE_OK;
}
/**************************************************************************************************\
*   Установка конфигурации
\***sss********************************************************************************************/
int32 ctl_set_config(int32 cfg)
{
  hoot.configuration = cfg;
  return OSE_OK;
}
/**************************************************************************************************\
*   Установка свойств порта
\***sss********************************************************************************************/
int32 ctl_set_port_feature(int32 port, int32 feature)
{
  int32         error = OSE_OK;
  s_reg_hcusbp  hcusbp;
  error = get_s_reg_hcusbp(port-1, &hcusbp);  
  if( error != OSE_OK ) return error;  
  switch(feature)
  {
    case FEATURE_PORT_POWER: 
    {
      *hcusbp.status |= BM_PP;
    }
    break;          
    case FEATURE_PORT_RESET:
    {
      sleep_m(100);
      *hcusbp.status |= BM_PR;      
    }
    break;                
    case FEATURE_PORT_SUSPEND: return OSE_FAIL;    
    case FEATURE_PORT_TEST: return OSE_FAIL;    
    case FEATURE_INDICATOR: return OSE_FAIL;    
    default: return USB_ER_STALL;    
  }
  return OSE_OK;
}
/**************************************************************************************************\
*   Отчистка свойств порта
\***sss********************************************************************************************/
int32 ctl_clear_port_feature(int32 port, int32 feature)
{
  int32         error = OSE_OK;
  s_reg_hcusbp  hcusbp;  
  error = get_s_reg_hcusbp(port-1, &hcusbp);  
  if( error != OSE_OK ) return error;
  switch(feature)
  {
    case FEATURE_PORT_ENABLE: return OSE_FAIL;
    case FEATURE_PORT_SUSPEND: break;
    case FEATURE_PORT_POWER: 
    {
      *hcusbp.status &= ~BM_PP;            
    }
    break;    
    case FEATURE_C_PORT_CONNECTION: 
    {
      *hcusbp.intstatus = BM_CSC;                  
    }
    break;    
    case FEATURE_C_PORT_ENABLE: return OSE_FAIL;
    case FEATURE_C_PORT_SUSPEND: return OSE_FAIL;
    case FEATURE_C_PORT_OVER_CURRENT: return OSE_FAIL;
    case FEATURE_C_PORT_RESET:
    {
      *hcusbp.intstatus = BM_PRSC;                  
    }
    break;        
    case FEATURE_INDICATOR: return OSE_FAIL;
    default: return USB_ER_STALL;
  }
  return OSE_OK;
}
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//
// Запросы к нулевой конечной точки ROOT HUB:
//
// ------------------------------------------
//
// Стандартные:
// - USB_REQUEST_GET_DESCRIPTOR
//   + USB_DEVICE_DESCRIPTOR_TYPE
//   + USB_CONFIGURATION_DESCRIPTOR_TYPE
// - USB_REQUEST_SET_ADDRESS
// - USB_REQUEST_SET_CONFIGURATION
// - USB_REQUEST_GET_CONFIGURATION
//
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO



//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//
//      Вспомагательные функции 
//
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
/**************************************************************************************************\
*  Получение адресов СТАТУС ПОРТА HC
\**************************************************************************************************/
int32 get_s_reg_hcusbp(int32 port, s_reg_hcusbp* hcusbp)
{
  switch(port)
  {
    case 0: 
    {
      hcusbp->status    = &REG_HCUSBP1_STATUS;
      hcusbp->intstatus = &REG_HCUSBP1_INTSTATUS;
      hcusbp->intenable = &REG_HCUSBP1_INTENABLE;
    }
    break;
    case 1: 
    {
      hcusbp->status    = &REG_HCUSBP2_STATUS;
      hcusbp->intstatus = &REG_HCUSBP2_INTSTATUS;
      hcusbp->intenable = &REG_HCUSBP2_INTENABLE;
    }
    break;    
    default: return OSE_BAD_PARAM;
  }
  return OSE_OK;
}
/**************************************************************************************************\
*  Получение количества свободных ресурсов
\**************************************************************************************************/
int32 hc_pipe_get_count_free()
{
  int32 count = 0;
  for(int32 i=0; i<NUM_USBHC_PIPE; i++ )
    if( hc_pipe[i].alloc == 0x0 )
      count++;
  return count;
}
/**************************************************************************************************\
*  Получение ресурса 
\**************************************************************************************************/
s_usbhc_pipe* hc_pipe_resource(uint8 device_address, uint8 endpoint_number)
{
  s_usbhc_pipe* pipe = NULL;
  for(int32 i=0; i<NUM_USBHC_PIPE; i++ )
  {
    if( hc_pipe[i].alloc == 0x0 ) continue;
    if( hc_pipe[i].config.device_address != device_address ) continue;
    if( hc_pipe[i].config.endpoint->endpoint_number != endpoint_number ) continue;
    pipe = &hc_pipe[i];
	break;
  }
  return pipe;
}
/**************************************************************************************************\
*  Получение номера ресурса
\**************************************************************************************************/
int32 hc_pipe_number(s_usbhc_pipe* pipe)
{
  int32 num = -1;
  for(int32 i=0; i<NUM_USBHC_PIPE; i++ )
  {
    if( &hc_pipe[i] != pipe ) continue;
    num = i;
	break;
  }
  return num;
}
/**************************************************************************************************\
*  Получение свободного ресурса
\**************************************************************************************************/
s_usbhc_pipe* hc_pipe_alloc()
{
  s_usbhc_pipe* pipe = NULL;
  for(int32 i=0; i<NUM_USBHC_PIPE; i++ )
  {
    if( hc_pipe[i].alloc != 0x0 ) continue;
    pipe = &hc_pipe[i];
    hc_pipe[i].alloc = 1;
    break;
  }
  return pipe;
}
/**************************************************************************************************\
*  Освобождение ресурса
\**************************************************************************************************/
int32 hc_pipe_free(s_usbhc_pipe* pipe)
{
  if( pipe == NULL ) return OSE_BAD_RESOURCE_INDEX;
  if( pipe->alloc == 0) return OSE_BAD_RESOURCE_INDEX;
  pipe->alloc = 0;
  return OSE_OK;
}

