//**************************************************************************************************
//                    Copyright (C) 2011-2013 RCZI
//--------------------------------------------------------------------------------------------------
// FILENAME....... drv_usbhc.cpp
// DATE CREATED... 08/06/2011
// LAST MODIFIED.. 01/08/2011
// DRIVER VERSION. 2.0
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
//#include  <mem_upd720150.h>
#include    <reg_upd720150.h>
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
    int32*          flag;
    uint32          sem;    
    void*           data;
    char*           name;
    int32           size;
};
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
struct s_usbhc_pipe_irp
{
  void*              data;
  uint32             size;
  uint32             sem_int;  
  int32*             flag_int;    
};
struct s_usbhc_pipe
{
  bool                    alloc;
  uint32                  num;
  s_usbhc_config_device   device;  
  s_usbhc_config_endpoint endpoint;
  s_usbhc_pipe_reg        reg;
  s_usbhc_pipe_irp        irp;
};
struct s_usbhc_pipe0
{
  volatile uint32    sem_int;
  volatile uint32    sem_loc;
};

struct s_mch_hoot
{
  int                                  (*function)(s_usbhc_bulk*);
  int                                  (*control)();
  int32                                narg;
  int32                                arg[4];
};
struct s_root_descriptor
{
  s_standard_device_descriptor*        usbdevice;
  s_standard_configuration_descriptor* usbconfig;
  s_standard_interface_descriptor*     usbinterface;
  s_standard_endpoint_descriptor*      usbendpoint;
  s_hub_descriptor*                    usbhub;
  s_hub_status*                        usbhub_status;
  s_hub_port_status*                   usbhub_port[2];
};
struct s_root_hub
{
  uint16                               address;
  uint16                               configuration;  
  uint16                               next_toggle0;
  uint8*                               buf;
  uint8                                data;  
  s_mch_hoot                           mstate;
  s_usb_request                        request;
  s_int_exchange                       exchange;  
  s_root_descriptor                    descriptor;
};
//-------------------------------------------------------------------------------------------------
static int8        usbhc_driver_init = 0;
static int8        usbhc_descriptor_init = 0;
static uint32      sem_usbhc = RES_VOID;
s_root_hub         hoot;
s_usbhc_pipe0      hc_pipe0;
s_usbhc_pipe       hc_pipe[NUM_PIPES];
//-------------------------------------------------------------------------------------------------
static void  usbhc_interrupt();
static int32 ph_hc_init();
static int32 ph_control_transfer(s_usbhc_bulk* tsk);
static int32 ph_bulk_transfer(s_usbhc_pipe* pipe);
static int32 ph_interrupt_transfer(s_usbhc_pipe* pipe, int32 mstate);
static int32 ph_hoot_bulk_transaction(s_usbhc_bulk* tsk);
static int32 ph_hoot_start_interrupt_transaction(s_usbhc_s_interrupt* tsk);
static int32 ph_hoot_complete_interrupt_transaction(s_usbhc_c_interrupt* tsk);
static int32 ph_configuration_connect(s_usbhc_config* tsk);
static int32 ph_configuration_disconnect(s_usbhc_config* tsk);
//-------------------------------------------------------------------------------------------------
int32         hc_pipe_init();
int32         hc_pipe_deinit();
int32         hc_pipe_get_count_free();
int32         hc_pipe_free(s_usbhc_pipe* pipe);
s_usbhc_pipe* hc_pipe_alloc();
s_usbhc_pipe* hc_pipe_resource(uint8 device_address, uint8 endpoint_number);
s_usbhc_pipe* hc_pipe_resource(uint32 npipe);
void          hc_pipe_clear(s_usbhc_pipe* pipe);
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
  hc_pipe0.sem_loc = sem_alloc(1, NULL);
  if(hc_pipe0.sem_loc == RES_VOID)
  {
    stage = 6;  
    error = OSE_CANT_CREATE_SEM;
    goto m_return;
  }
  //*** STAGE 7 ***
  hc_pipe0.sem_int = sem_alloc(0, NULL);
  if(hc_pipe0.sem_int == RES_VOID)
  {
    stage = 7;  
    error = OSE_CANT_CREATE_SEM;
    goto m_return;
  }
  //*** STAGE 8 ***
  error = hc_pipe_init();
  if(error != OSE_OK)
  {
    stage = 8;  
    error = OSE_NOT_INITIALIZED;
    goto m_return;
  }  
  //*** STAGE COMPLETE ***    
  usbhc_driver_init = 1;
  error = OSE_OK;
  
  m_return:
  switch(stage)
  {
    case  9: hc_pipe_deinit();
    case  8: sem_free(hc_pipe0.sem_int);
    case  7: sem_free(hc_pipe0.sem_loc);
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
    hc_pipe_deinit();
    sem_free(hc_pipe0.sem_int);
    sem_free(hc_pipe0.sem_loc);
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
static int32 lg_cast_bulk_pipe(s_usbhc_pipe** adr_pipe, s_usbhc_bulk* tsk)
{
  s_usbhc_pipe* &pipe = *adr_pipe;
  pipe = hc_pipe_resource(tsk->irp.device_address, tsk->irp.endpoint_number);
  if(pipe == NULL) return OSE_BAD_DATA;
  pipe->irp.data = tsk->irp.data;
  pipe->irp.size = tsk->irp.size;
  return OSE_OK;
}
//--------------------------------------------------------------------------------------------------
static int32 lg_usbhc_bulk_transaction(s_usbhc_bulk* tsk)
{
  int32 error;  
  s_usbhc_pipe* pipe;  
  sem_lock(sem_usbhc, SEM_INFINITY);
  if(tsk->irp.device_address == hoot.address)  
  {
    error = ph_hoot_bulk_transaction(tsk);  
    sem_unlock(sem_usbhc);
    return error;
  }
  switch(tsk->irp.endpoint_type)
  {
    case USB_BULK_TYPE: break;
    case USB_CONTROL_TYPE: 
    {
      error = ph_control_transfer(tsk);    
      sem_unlock(sem_usbhc);
      return error;
    }
    default: 
    {
      sem_unlock(sem_usbhc);
      return OSE_BAD_DATA;
    }
  }
  error = lg_cast_bulk_pipe(&pipe, tsk);
  if( error != OSE_OK ) 
  {
    sem_unlock(sem_usbhc);
    return error;
  }
  error = ph_bulk_transfer(pipe);
  sem_unlock(sem_usbhc);
  return error;
}
/**************************************************************************************************\
*   Начать транзакцию типа INTERRUPT
\***sss********************************************************************************************/
static int32 lg_cast_interrupt_pipe(s_usbhc_pipe** adr_pipe, s_usbhc_s_interrupt* tsk)
{
  s_usbhc_pipe* &pipe = *adr_pipe;
  pipe = hc_pipe_resource(tsk->irp.device_address, tsk->irp.endpoint_number);
  if(pipe == NULL) return OSE_BAD_DATA;
  *tsk->id = pipe->num;
  pipe->irp.data = tsk->irp.data;
  pipe->irp.size = tsk->irp.size;
  pipe->irp.sem_int = tsk->sem;  
  pipe->irp.flag_int = tsk->flag;    
  return OSE_OK;
}
//--------------------------------------------------------------------------------------------------
static int32 lg_usbhc_start_interrupt_transaction(s_usbhc_s_interrupt* tsk)
{
  if(tsk->irp.device_address == hoot.address) return ph_hoot_start_interrupt_transaction(tsk);
  switch(tsk->irp.endpoint_type)
  {
    case USB_INTERRUPT_TYPE: break;
    default:                 return OSE_BAD_DATA;
  }  
  int32 error;
  s_usbhc_pipe* pipe;
  error = lg_cast_interrupt_pipe(&pipe, tsk);
  if( error != OSE_OK ) return error;
  return ph_interrupt_transfer(pipe, 0);
}
/**************************************************************************************************\
*   Результат транзакции типа INTERRUPT
\***sss********************************************************************************************/
static int32 lg_usbhc_complete_interrupt_transaction(s_usbhc_c_interrupt* tsk)
{
  if(tsk->id == -1) return ph_hoot_complete_interrupt_transaction(tsk);
  s_usbhc_pipe* pipe = hc_pipe_resource(tsk->id);  
  if( pipe == NULL ) return OSE_BAD_DATA;
  return ph_interrupt_transfer(pipe, 1);  
}
/**************************************************************************************************\
*   Конфигурация HC при подключении и отключении устройства
\***sss********************************************************************************************/
static int32 lg_usbhc_configuration(s_usbhc_config* tsk)
{
  if(tsk->device.device_address == hoot.address) return OSE_OK;
  if(tsk->connected) return ph_configuration_connect(tsk);
  else return ph_configuration_disconnect(tsk);
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
uint16 hub_port_status[][2] = {{0x0000, 0x0000},{0x0000, 0x0000}};
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
/**************************************************************************************************\
*   Обработчик прерывания от контроллера
\***sss********************************************************************************************/
uint16 reg_int_status = 0;
static void usbhc_interrupt()
{
  reg_int_status = REG_INT_STATUS;
  //Прерывание ПОРТ1 или ПОРТ2:
  ph_int_status__port_int(reg_int_status & (BM_PORT2INT|BM_PORT1INT));
  //Прерывание 0EP:
  if(reg_int_status & BM_HCEP0INT) 
    ph_int_status__ep0_int();
  //Прерывание Pipe 0:
  if(reg_int_status & BM_PIPE1INT)
    ph_int_status__pipe_int(0);
  //Прерывание Pipe 1:
  if(reg_int_status & BM_PIPE2INT)
    ph_int_status__pipe_int(1);
  //Прерывание Pipe 2:
  if(reg_int_status & BM_PIPE3INT)
    ph_int_status__pipe_int(2);
  //Прерывание Pipe 3:
  if(reg_int_status & BM_PIPE4INT)
    ph_int_status__pipe_int(3);
  //Прерывание Pipe 4:
  if(reg_int_status & BM_PIPE5INT)
    ph_int_status__pipe_int(4);
  //Прерывание Pipe 5:
  if(reg_int_status & BM_PIPE6INT)
    ph_int_status__pipe_int(5);
  //Прерывание Pipe 6:
  if(reg_int_status & BM_PIPE7INT)
    ph_int_status__pipe_int(6);
  //Прерывание Pipe 7:
  if(reg_int_status & BM_PIPE8INT)
    ph_int_status__pipe_int(7);
  //Прерывание Pipe 8:
  if(reg_int_status & BM_PIPE9INT)
    ph_int_status__pipe_int(8);
//  else
//    asm(" nop");
  asm(" nop");
}
//**************************************************************************************************
//  Прерывание порта
//***sss********************************************************************************************
int32 ph_fix_port_data(int32 port)
{
  s_reg_hcusbp  hcusbp;
  get_s_reg_hcusbp(port, &hcusbp);
  memcpy(hoot.descriptor.usbhub_port[port], (void*)hcusbp.status, sizeof(s_hub_port_status));
  *hcusbp.intstatus |= *hcusbp.intstatus;
  return OSE_OK;
}
//**************************************************************************************************
int32 ph_int_status__port_int(int32 port)
{
  if( port & BM_PORT1INT ) ph_fix_port_data(0);      
  if( port & BM_PORT2INT ) ph_fix_port_data(1);        
  if(hoot.exchange.sem != RES_VOID)
    sem_unlock_sw(hoot.exchange.sem);
  if(hoot.exchange.flag != NULL)
    *hoot.exchange.flag = 0xA0|(port&0xF);
  hoot.data = port<<1;    
  return OSE_OK;
}
//**************************************************************************************************
//  Прерывание нулевой конечной точки
//***sss********************************************************************************************
int32 ph_int_status__ep0_int()
{
  sem_unlock_sw(hc_pipe0.sem_int);  
  return OSE_OK;
}
//**************************************************************************************************
//  Прерывание пайпа:
//***sss********************************************************************************************
uint32 hub_int = 0;
int32 ph_int_status__pipe_int(int32 npipe)
{
  s_usbhc_pipe* pipe = hc_pipe_resource(npipe);
  if( pipe == NULL ) return OSE_FAIL;
  if( pipe->irp.flag_int != NULL) *pipe->irp.flag_int = 0xC0|(npipe&0xF);    
  if( pipe->irp.sem_int != RES_VOID ) sem_unlock_sw(pipe->irp.sem_int);   
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
  hoot.next_toggle0 = 0x0;
  hoot.data = 0x0;
  memset(&hoot.mstate, 0x0, sizeof(s_mch_hoot));
  hoot.mstate.function = &mch_hoot__setup;
  hoot.buf = NULL;
  memset(&hoot.request, 0x0, sizeof(s_usb_request));
  hoot.descriptor.usbdevice = (s_standard_device_descriptor*) hub_standard_device_descriptor;
  hoot.descriptor.usbconfig = (s_standard_configuration_descriptor*) (&hub_standard_configuration_descriptor[0]); 
  hoot.descriptor.usbinterface = (s_standard_interface_descriptor*) (&hub_standard_configuration_descriptor[9]);
  hoot.descriptor.usbendpoint = (s_standard_endpoint_descriptor*) (&hub_standard_configuration_descriptor[18]); 
  hoot.descriptor.usbhub = (s_hub_descriptor*) hub_descriptor;
  hoot.descriptor.usbhub_status = (s_hub_status*) hub_status;
  hoot.descriptor.usbhub_port[0] = (s_hub_port_status*) &hub_port_status[0];
  hoot.descriptor.usbhub_port[1] = (s_hub_port_status*) &hub_port_status[1];
  memcpy(hoot.descriptor.usbhub_port[0], (void*)&REG_HCUSBP1_STATUS, sizeof(s_hub_port_status));
  memcpy(hoot.descriptor.usbhub_port[1], (void*)&REG_HCUSBP2_STATUS, sizeof(s_hub_port_status));  
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
*   Ожидание прерывания
\***sss********************************************************************************************/
static int32 ph_wait_interrupt(int32 sem)
{
  if(sem_lock(sem, 5000) != SEM_OK) 
    return OSE_TIMEOUT;
  return 0x0;
}
/**************************************************************************************************\
*   Обмен с нулевой конечной точкой
\***sss********************************************************************************************/
static int32 ph_control_setup_transfer(s_usbhc_bulk* tsk)
{
  int32  error;
  uint16 bm_speed, reg_hcep0_intstatus;
  s_usbhc_request* req = (s_usbhc_request*)tsk->irp.data;
  //Set begin HC data:
  tsk->data.size = req->length;
  tsk->data.count = req->length;  
  //Setting transfer request (TR):
  switch(tsk->irp.device_speed)
  {
    case USB_LOW_SPEED:  bm_speed = BM_SPEED_LS; break;
    case USB_FULL_SPEED: bm_speed = BM_SPEED_FS; break;
    case USB_HI_SPEED:   bm_speed = BM_SPEED_HS; break;
  }
  REG_HCEP0_CONFIG    = bm_speed|tsk->irp.max_packet_length;
  //Настройка запроса:
  REG_HCEP0_USBREQ    = req->request;
  REG_HCEP0_USBVALUE  = req->value;
  REG_HCEP0_USBINDEX  = req->index;
  REG_HCEP0_USBLENGTH = req->length;
  REG_HCEP0_DEVINFO   = tsk->irp.device_address;
  if(tsk->irp.hub_address == hoot.address || tsk->irp.hub_address == 0)
    REG_HCEP0_HUBINFO = 0x0;
  else
    REG_HCEP0_HUBINFO = ((tsk->irp.hub_address & 0x7f)<<8)|(tsk->irp.port_number & 0x7f);
  //Конфигурация 0 пайпа:
  REG_HCEP0_CONTROL = BM_EP0C_PID_SETUP|BM_EP0C_DPID_CLR;
  REG_HCEP0_CONFIG |= BM_SET;      
  while((REG_HCEP0_STATUS & BM_EP0S_CONF) == 0);
  //Setup Stage start <TR active>:
  REG_HCEP0_CONTROL |= BM_EP0C_ACTIVE;
  ph_wait_interrupt(hc_pipe0.sem_int);
  while(true)
  {
    reg_hcep0_intstatus = REG_HCEP0_INTSTATUS;
    if(reg_hcep0_intstatus & (BM_EP0IS_HALT|BM_EP0IS_STALL)) 
    {
      error = USB_ER_STALL;
      break;
    }
    if(reg_hcep0_intstatus & BM_EP0IS_COMPLETE) 
    {
      error = 0x0;
      break;
    }
  }
  REG_HCEP0_INTSTATUS = REG_HCEP0_INTSTATUS;
  return error;
}
//-------------------------------------------------------------------------------------------------
static int32 ph_control_data_in_transfer(s_usbhc_bulk* tsk)
{
  int32  error;
  //Control HC data:  
  if(tsk->data.count == tsk->data.size) tsk->data.data = tsk->irp.data; 
  tsk->data.count -= tsk->irp.size;
  if(tsk->data.count > 0) return 0x0; 
  else if(tsk->data.count < 0) return OSE_BAD_DATA;   
  //Setting transfer request (TR):
  REG_HCEP0_TBT = tsk->data.size;//tsk->irp.size;
  REG_HCEP0_CONTROL = BM_EP0C_PID_IN|BM_EP0C_DPID_SET;
  //Data Stage start <TR active>:
  REG_HCEP0_CONTROL |= BM_EP0C_ACTIVE;
  ph_wait_interrupt(hc_pipe0.sem_int);      
  while(true)
  {
    uint16 reg_hcep0_intstatus = REG_HCEP0_INTSTATUS;      
    //Data transfer / Data Stage complete <TR inactive>:
    if(reg_hcep0_intstatus & (BM_EP0IS_HALT|BM_EP0IS_STALL|BM_EP0IS_ORUN)) 
    {
      error = USB_ER_STALL;
      break;
    }
    if(reg_hcep0_intstatus & (BM_EP0IS_INDT | BM_EP0IS_SHORT | BM_EP0IS_NULL))
    {
      //Reading received data:
      if(REG_HCEP0_LENGTH != 0x0000)
      {
        ph_hc_read_bufport((uint8*)tsk->data.data, (uint16*)&REG_HCEP0_BUFPORT, REG_HCEP0_LENGTH);
      }
    }
    if(reg_hcep0_intstatus & BM_EP0IS_COMPLETE) 
    {
      error = 0x0;
      break;
    }
  }
  REG_HCEP0_INTSTATUS = REG_HCEP0_INTSTATUS;    
  return error;
}
//-------------------------------------------------------------------------------------------------
static int32 ph_control_data_out_transfer(s_usbhc_bulk* tsk)
{
  int32 error;
  //Setting transfer request (TR):
  REG_HCEP0_TBT      = tsk->irp.size;
  REG_HCEP0_CONTROL  = BM_EP0C_PID_OUT|BM_EP0C_DPID_SET;
  //Data Stage start <TR active>:
  REG_HCEP0_CONTROL |= BM_EP0C_ACTIVE;
  //Data transfer / Data Stage complete <TR inactive>:
  while(true)
  {
    bool complete = false;
    ph_hc_write_bufport((uint16*)&REG_HCEP0_BUFPORT, (uint8*)tsk->irp.data, tsk->irp.size);
    REG_HCEP0_CONTROL |= BM_EP0C_DEND;
    ph_wait_interrupt(hc_pipe0.sem_int);        
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
//-------------------------------------------------------------------------------------------------
static int32 ph_control_transfer(s_usbhc_bulk* tsk)
{
  int32  error;
  sem_lock(hc_pipe0.sem_loc, SEM_INFINITY);
  switch(tsk->irp.token)
  {
    case USB_SETUP_TOKEN: error = ph_control_setup_transfer(tsk); break;
    case USB_IN_TOKEN: error = ph_control_data_in_transfer(tsk); break;
    case USB_OUT_TOKEN: error = ph_control_data_out_transfer(tsk); break;
    default: error = OSE_BAD_DATA;
  }
  sem_unlock(hc_pipe0.sem_loc);
  return error;
}
/**************************************************************************************************\
*   Обмен с конечной точкой
\***sss********************************************************************************************/
//--------------------------------------------------------------------------------------------------
//  Bulk/Interrupt preparation for data transfer
//--------------------------------------------------------------------------------------------------
static int32 ph_preparation_transfer(s_usbhc_pipe* pipe)
{
  REG_PIPE.tbt = pipe->irp.size;
  switch(pipe->endpoint.endpoint_number & ENDPOINT_DIRECTION_MASK)
  {
    case ENDPOINT_IN:  REG_PIPE.intenable = BM_PIPEIE_HALT_E|BM_PIPEIE_NULL_E|BM_PIPEIE_ORUN_E|BM_PIPEIE_SHORT_E|BM_PIPEIE_COMPLETE_E|BM_PIPEIE_STALL_E|BM_PIPEIE_INDT_E; break;
    case ENDPOINT_OUT: REG_PIPE.intenable = BM_PIPEIE_HALT_E|BM_PIPEIE_COMPLETE_E|BM_PIPEIE_STALL_E; break;
  }
  REG_PIPE.control2 |= BM_PIPE_ACTIVE;
  return 0x0;
}
//--------------------------------------------------------------------------------------------------
//  Bulk/Interrupt IN Data Transfer Flow
//--------------------------------------------------------------------------------------------------
static int32 ph_indata_transfer(s_usbhc_pipe* pipe)
{
  int32 size, size_left;  
  size_left = pipe->irp.size;
  while(true)
  {
    size = (size_left < pipe->endpoint.max_packet_size) ? size_left : pipe->endpoint.max_packet_size;
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
        ph_hc_read_bufport(&((uint8*)pipe->irp.data)[pipe->irp.size-size_left], (uint16*)pipe->reg.bufport, size);
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
//  Bulk/Interrupt IN Data Transfer Flow
//--------------------------------------------------------------------------------------------------
static int32 ph_outdata_transfer(s_usbhc_pipe* pipe)
{
  int32          error;
  register int32 size;
  register int32 size_left;  
  
  REG_PIPE.intstatus |= BM_PIPEIS_OUTDT;
  REG_PIPE.intenable |= BM_PIPEIE_OUTDT_E;
  REG_PIPE.control1 &= ~BM_PIPE_AUTO;
  
  size_left = pipe->irp.size;
  while(true)
  {
    size = (size_left < pipe->endpoint.max_packet_size) ? size_left : pipe->endpoint.max_packet_size;
    //Writing data to send:
    ph_hc_write_bufport((uint16*)pipe->reg.bufport, &((uint8*)pipe->irp.data)[pipe->irp.size-size_left], size);
    REG_PIPE.control2 |= BM_PIPE_DEND;
        
    if( error = ph_wait_interrupt(pipe->irp.sem_int) ) return error;  
        
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
//  BULK data transfer
//--------------------------------------------------------------------------------------------------
static int32 ph_bulk_transfer(s_usbhc_pipe* pipe)
{
  int32 error;
  if( error = ph_preparation_transfer(pipe) ) return error;
  switch(pipe->endpoint.endpoint_number & ENDPOINT_DIRECTION_MASK)
  {
    case ENDPOINT_IN:  
	{
      if( error = ph_wait_interrupt(pipe->irp.sem_int) ) break;	  
      error = ph_indata_transfer(pipe);
    }
    break;
    case ENDPOINT_OUT: 
	{
      error = ph_outdata_transfer(pipe);
    }
    break;
  }
  //REG_PIPE.intenable = 0x0000;  
  return error;
}
//--------------------------------------------------------------------------------------------------
//  INTERRUPT data transfer
//--------------------------------------------------------------------------------------------------
static int32 ph_interrupt_transfer(s_usbhc_pipe* pipe, int32 mstate)
{
  int32 error;
  if( (pipe->endpoint.endpoint_number & ENDPOINT_DIRECTION_MASK) == ENDPOINT_OUT ) return OSE_NO_DRIVER;
  switch(mstate)
  {
    case 0:  
	{
      error = ph_preparation_transfer(pipe);
    }
    break;
    case 1: 
    {
      error = ph_indata_transfer(pipe);    
    }
    break;
  }
  return error;
}
/**************************************************************************************************\
*   Конфигурация PIPE-ов
\***sss********************************************************************************************/
static int32 ph_configuration_connect(s_usbhc_config* tsk)
{
  uint16        bm_tr_type, bm_dir, bm_itvl;
  int32         npipe;
  s_usbhc_pipe* pipe;
  if( hc_pipe_get_count_free() < tsk->device.number_endpoints ) return OSE_RESOURCE_LIMIT_REACHED;
  for(int32 i=0; i<tsk->device.number_endpoints; i++)
  {
    pipe = hc_pipe_alloc();
    if(pipe == NULL) return OSE_RESOURCE_LIMIT_REACHED;
    npipe = pipe->num;
    memcpy( &pipe->device, &tsk->device, sizeof(s_usbhc_config_device) );
    memcpy( &pipe->endpoint, &tsk->endpoint[i], sizeof(s_usbhc_config_endpoint) );    
    //Pipe configuration (Setting endpoint information):
    bm_tr_type = ( pipe->endpoint.attributes & USB_TRANSFER_TYPE_MASK ) << 2; 
	switch(pipe->endpoint.attributes & USB_TRANSFER_TYPE_MASK)
	{
      case USB_INTERRUPT_TYPE: 
      {
        if( pipe->device.device_speed != USB_HI_SPEED ) return OSE_NO_DRIVER;
        bm_itvl = ( (0x1<<pipe->endpoint.interval) > 8 ) ? 8 : 0x1<<pipe->endpoint.interval;
        bm_itvl = bm_itvl<<8;
      }
      break;
      case USB_BULK_TYPE:
      {
        if(pipe->irp.sem_int == RES_VOID) pipe->irp.sem_int = sem_alloc(0, NULL);
        if(pipe->irp.sem_int == RES_VOID) return OSE_CANT_CREATE_SEM;
      }
	  default: bm_itvl = 0x0; 
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
    REG_PIPE.config2  = (pipe->device.device_speed<<12)|pipe->endpoint.max_packet_size;
    REG_PIPE.devinfo  = pipe->device.device_address;
    if(pipe->device.hub_address == hoot.address || pipe->device.hub_address == 0)
      REG_PIPE.hubinfo  = 0x0;
    else
      REG_PIPE.hubinfo = ((pipe->device.hub_address & 0x7f)<<8)|(pipe->device.port_number & 0x7f);    
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
static int32 ph_configuration_disconnect(s_usbhc_config* tsk)
{
  int32         npipe;
  int32         error = OSE_OK;
  s_usbhc_pipe* pipe;
  for(int32 i=0; i<tsk->device.number_endpoints; i++)
  {
    pipe = hc_pipe_resource(tsk->device.device_address, tsk->endpoint[i].endpoint_number);
    if(pipe == NULL) continue;
    npipe = pipe->num; 
	switch(pipe->endpoint.attributes & USB_TRANSFER_TYPE_MASK)
	{
      case USB_BULK_TYPE: if(pipe->irp.sem_int != RES_VOID) sem_free(pipe->irp.sem_int); break;
	}
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
  *tsk->id = -1;
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
  *(uint8*)hoot.exchange.data = hoot.data;
  hoot.data = 0x0;
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
          hoot.buf = (uint8*) hoot.descriptor.usbdevice;
          hoot.mstate.function = &mch_hoot__data_in;
          memcpy(&hoot.request, irp->data, sizeof(s_usb_request));
          error = OSE_OK;
        }
        break;
        case USB_CONFIGURATION_DESCRIPTOR_TYPE: 
        {
          hoot.buf = (uint8*) hoot.descriptor.usbconfig;
          hoot.mstate.function = &mch_hoot__data_in;
          memcpy(&hoot.request, irp->data, sizeof(s_usb_request));
          error = OSE_OK;
        }
        break;
        case 0x00: //HUB DESCRIPTOR 
        {
          hoot.buf = (uint8*) hoot.descriptor.usbhub;
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
      if( (rq->value > (hoot.descriptor.usbdevice->num_configurations+1)) ) break;
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
      hoot.buf = (uint8*) hoot.descriptor.usbhub_status;
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
        case 1: hoot.buf = (uint8*) hoot.descriptor.usbhub_port[0]; break;
        case 2: hoot.buf = (uint8*) hoot.descriptor.usbhub_port[1]; break;
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
  if(tsk->irp.size > hoot.descriptor.usbdevice->max_packet_size_0) 
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
  if(tsk->irp.size > hoot.descriptor.usbdevice->max_packet_size_0) 
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
  if(tsk->irp.size > hoot.descriptor.usbdevice->max_packet_size_0) 
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
    //*hcusbp.intstatus = BM_CSC;                  
    }
    break;    
    case FEATURE_C_PORT_ENABLE: return OSE_FAIL;
    case FEATURE_C_PORT_SUSPEND: return OSE_FAIL;
    case FEATURE_C_PORT_OVER_CURRENT: return OSE_FAIL;
    case FEATURE_C_PORT_RESET:
    {
    //*hcusbp.intstatus = BM_PRSC;                  
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
//      Диспечер пайпов
//
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
static uint32   sem_pipe = RES_VOID;
/**************************************************************************************************\
*  Инициализация диспечера пайпов
\**************************************************************************************************/
int32 hc_pipe_init()
{
  sem_pipe = sem_alloc(1, NULL);
  if(sem_pipe == RES_VOID) return OSE_CANT_CREATE_SEM;
  for(int32 i=0; i<NUM_PIPES; i++ )
    hc_pipe_clear(&hc_pipe[i]);
  return OSE_OK;
}
/**************************************************************************************************\
*  Инициализация диспечера пайпов
\**************************************************************************************************/
int32 hc_pipe_deinit()
{
  if(sem_pipe != RES_VOID) sem_free(sem_usbhc);
  return OSE_OK;
}
/**************************************************************************************************\
*  Получение количества свободных ресурсов
\**************************************************************************************************/
int32 hc_pipe_get_count_free()
{
  int32 count = 0;
  sem_lock(sem_pipe,SEM_INFINITY);
  for(int32 i=0; i<NUM_PIPES; i++ )
    if( hc_pipe[i].alloc == false )
      count++;
  sem_unlock(sem_pipe);
  return count;
}
/**************************************************************************************************\
*  Получение ресурса 
\**************************************************************************************************/
s_usbhc_pipe* hc_pipe_resource(uint8 device_address, uint8 endpoint_number)
{
  s_usbhc_pipe* pipe = NULL;
  sem_lock(sem_pipe,SEM_INFINITY);
  for(int32 i=0; i<NUM_PIPES; i++ )
  {
    if( hc_pipe[i].alloc == false ) continue;
    if( hc_pipe[i].device.device_address != device_address ) continue;
    if( hc_pipe[i].endpoint.endpoint_number != endpoint_number ) continue;
    pipe = &hc_pipe[i];
	break;
  }
  sem_unlock(sem_pipe);
  return pipe;
}
/**************************************************************************************************\
*  Получение ресурса 
\**************************************************************************************************/
s_usbhc_pipe* hc_pipe_resource(uint32 npipe)
{
  if( npipe >= NUM_PIPES ) return NULL;
  return &hc_pipe[npipe];
}
/**************************************************************************************************\
*  Получение свободного ресурса
\**************************************************************************************************/
s_usbhc_pipe* hc_pipe_alloc()
{
  s_usbhc_pipe* pipe = NULL;
  sem_lock(sem_pipe,SEM_INFINITY);
  for(int32 i=0; i<NUM_PIPES; i++ )
  {
    if( hc_pipe[i].alloc != false ) continue;
    pipe = &hc_pipe[i];
    pipe->alloc = true;
    break;
  }
  sem_unlock(sem_pipe);
  return pipe;
}
/**************************************************************************************************\
*  Освобождение ресурса
\**************************************************************************************************/
int32 hc_pipe_free(s_usbhc_pipe* pipe)
{
  if( pipe == NULL ) return OSE_BAD_RESOURCE_INDEX;
  if( pipe->alloc == false) return OSE_BAD_RESOURCE_INDEX;
  sem_lock(sem_pipe,SEM_INFINITY);
  hc_pipe_clear(pipe);
  sem_unlock(sem_pipe);
  return OSE_OK;
}
/**************************************************************************************************\
*  Получение номера ресурса
\**************************************************************************************************/
int32 hc_pipe_number(s_usbhc_pipe* pipe)
{
  int32 num = -1;
  for(int32 i=0; i<NUM_PIPES; i++ )
  {
    if( &hc_pipe[i] != pipe ) continue;
    num = i;
	break;
  }
  return num;
}
/**************************************************************************************************\
*  Освобождение ресурса
\**************************************************************************************************/
void hc_pipe_clear(s_usbhc_pipe* pipe)
{
  int32 i = hc_pipe_number(pipe);
  if(i < 0) return;
  pipe->alloc = false;
  pipe->num = i;
  memset(&pipe->device, 0x0, sizeof(s_usbhc_config_device));
  memset(&pipe->endpoint, 0x0, sizeof(s_usbhc_config_endpoint));  
//memset(&pipe->intexch, 0x0, sizeof(s_int_exchange));
  memset(&pipe->irp, 0x0, sizeof(s_usbhc_pipe_irp) );
  pipe->reg.config1   = DREG_PIPE_CONFIG1(i);
  pipe->reg.config2   = DREG_PIPE_CONFIG2(i);
  pipe->reg.control1  = DREG_PIPE_CONTROL1(i);
  pipe->reg.control2  = DREG_PIPE_CONTROL2(i);
  pipe->reg.devinfo   = DREG_PIPE_DEVINFO(i);
  pipe->reg.hubinfo   = DREG_PIPE_HUBINFO(i);
  pipe->reg.length    = DREG_PIPE_LENGTH(i);
  pipe->reg.tbt       = DREG_PIPE_TBT(i);
  pipe->reg.bufport   = DREG_PIPE_BUFPORT(i);
  pipe->reg.status    = DREG_PIPE_STATUS(i);
  pipe->reg.intstatus = DREG_PIPE_INTSTATUS(i);
  pipe->reg.intenable = DREG_PIPE_INTENABLE(i);
}
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
