//**************************************************************************************************
//                         Copyright (C) 2009 RCZI
//--------------------------------------------------------------------------------------------------
// FILENAME....... drv_usb.cpp
// DATE CREATED... 23/11/2009
// LAST MODIFIED.. 10/12/2009
// DRIVER VERSION. 1.0
//--------------------------------------------------------------------------------------------------
//                       UNIVERSAL SERIAL BUS DRIVER
//-------------------------------------------------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
//
// !: codepage: cp1251 
//
// !: d: Драйвер Universal Serial Bus.<br>
// !: -:
// !: md: Драйвер шины USB работает в составе операционной системы "ОС". 
// !: md: Он реализует следующие возможности:<br> 
// !: md: - Обнаружение подключение и отключение USB устройств;<br>
// !: md: - Управление системным обменом между хост контроллером и USB устройством;<br>
// !: md: - Управление обменом данных между хост контроллером и USB устройством;<br>
// !: md: - Контроль состояния устройства на шине USB.<br><br>
//
// !: md: При обнаружении подключенного устройства, драйвер USB монтирует 
// !: md: его в файловую систему ОС. Путь к устройству:"/dev/usb/name", 
// !: md: где name - имя формируемое в зависимости от класса устройства и 
// !: md: его физического положения на шине USB.<br> 
// !: md: Порядок формирования имени (name).<br>
// !: md: Шаг 1.<br>
// !: md: Зависимость от класса:<br>
// !: md: - класс Audio устройств "aud";<br>
// !: md: - класс Communications устройств "com";<br>
// !: md: - класс HID устройств "hid";<br>
// !: md: - класс Monitor устройств "dsp";<br>
// !: md: - класс Physical interface устройств "phs";<br>
// !: md: - класс Power устройств "pwr";<br>
// !: md: - класс Printer устройств "prt";<br>
// !: md: - класс Mass Storage устройств "msd";<br>
// !: md: - класс Hub устройств "hub";<br>
// !: md: Шаг 2.<br>
// !: md: Зависимость от физического положения на шине USB:<br>
// !: md: К имени, полученному на шаге 1, добавляется последовательность 
// !: md: номеров портов хабов.<br><br>
//
// !: md: В процессе обнаружения подключенного устройства, 
// !: md: драйвер сканирует внутренний список контекстов драйверов 
// !: md: USB устройств, при обнаружении контекста для устройства 
// !: md: соответствующего класса, производит добавление (plug) устройства 
// !: md: в систему. Путь к устройству:"/dev/device_name", где device_name - 
// !: md: имя устройства.<br>
// !: md: Порядок формирования имени устройства (device_name).<br>
// !: md: Для класса Mass Storage: имя устройства имеет следующий 
// !: md: формат "sdAuL", где:<br>
// !: md: - A - адрес физического устройства на шине от 1 до 127;<br>
// !: md: - L - номер логической устройства (LUN) от 0 до N.<br>
//***sss********************************************************************************************
#include    <os.h>
#include    <rts.h>
#include    <drv_usb.h>
#include    <drv_usbhc.h> 
#ifdef FS_MOUNT
#include    <drv_mnt.h> 
#endif
#ifdef CONSOLE_DEBUG
#include    <drv_dbgout.h>
#endif

//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//
//          Интерфейсные функции драйвера
//
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
int32 lg_usb_init_driver();
int32 lg_usb_deinit_driver();
int32 lg_usb_init_descriptor(s_os_driver_descriptor* d);
int32 lg_usb_deinit_descriptor(s_os_driver_descriptor* d);
int32 lg_usb_inode_select(s_os_driver_descriptor* d, char* arg);
int32 lg_usb_inode_list(s_os_driver_descriptor* d, s_inode* *arg);

int32 lg_usb_control_transaction(s_os_driver_descriptor* d, s_usb_control* arg);
int32 lg_usb_bulk_transaction(s_os_driver_descriptor* d, s_usb_bulk* arg);
int32 lg_usb_start_interrupt_transaction(s_os_driver_descriptor* d, s_usb_s_interrupt* arg);
int32 lg_usb_complete_interrupt_transaction(s_os_driver_descriptor* d, s_usb_c_interrupt* arg);
int32 lg_usb_add_device_class(s_os_driver_descriptor* d, s_usb_driver_context* ctx);
int32 lg_usb_remove_device_class(s_os_driver_descriptor* d, int32* device_class);
int32 lg_usb_attach_function(s_os_driver_descriptor* d, s_usb_attach_func* arg);

//**************************************************************************************************
//       Открытие потока
//-------------------------------------------------------------------------------------------------
// !: fn: int32 usb_open(s_os_driver_descriptor* d, uint16 access)
//
// !: d: Функция драйвером не поддерживаеться.<br> 
// !: -:
//***sss********************************************************************************************
int32 usb_open(s_os_driver_descriptor* d, uint16 access)
{
  return OSE_CANT_OPEN;
}
//**************************************************************************************************
//       Закрытие потока
//-------------------------------------------------------------------------------------------------
// !: fn: int32 usb_close(s_os_driver_descriptor* d)
//
// !: d: Функция драйвером не поддерживаеться.<br> 
// !: -:
//***sss********************************************************************************************
int32 usb_close(s_os_driver_descriptor* d)
{
  return OSE_STREAM_NOT_OPENED;
}
//**************************************************************************************************
//       Чтение из потока
//-------------------------------------------------------------------------------------------------
// !: fn: int32 usb_read(s_os_driver_descriptor* d, void* buf, int32 length)
//
// !: d: Функция драйвером не поддерживаеться.<br> 
// !: -:
//***sss********************************************************************************************
int32 usb_read(s_os_driver_descriptor* d, void* buf, int32 length)
{
  return OSE_PERMISSION_DENIED;
}
//**************************************************************************************************
//       Запись в поток
//-------------------------------------------------------------------------------------------------
// !: fn: int32 usb_write(s_os_driver_descriptor* d, const void* buf, int32 length)
//
// !: d: Функция драйвером не поддерживаеться.<br> 
// !: -:
//***sss********************************************************************************************
int32 usb_write(s_os_driver_descriptor* d, const void* buf, int32 length)
{
  return OSE_PERMISSION_DENIED;
}
//**************************************************************************************************
//       Управление вводом/выводом
//-------------------------------------------------------------------------------------------------
// !: fn: int32 usb_ioctl(s_os_driver_descriptor* d, int32 cmd, const void* arg)
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
// !: d:   IOC_INODE_SELECT, IOC_INODE_LIST.<br><br>
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
// !: d:   USB_CONTROL_TRANSFER
// !: d:   </td> 
// !: d:   <td valign=top>
// !: d:   s_usb_control
// !: d:   </td> 
// !: d:   <td valign=top>
// !: d:   Cистемный обмен.
// !: d:   </td>
// !: d: </tr>
//
// !: d: <tr>
// !: d:   <td valign=top>
// !: d:   USB_BULK_TRANSFER 
// !: d:   </td> 
// !: d:   <td valign=top>
// !: d:   s_usb_bulk
// !: d:   </td> 
// !: d:   <td valign=top>
// !: d:   Транзакция типа bulk. 
// !: d:   </td>
// !: d: </tr>
//
// !: d: <tr>
// !: d:   <td valign=top>
// !: d:   USB_START_INTERRUPT
// !: d:   </td> 
// !: d:   <td valign=top>
// !: d:   s_usb_s_interrupt
// !: d:   </td> 
// !: d:   <td valign=top>
// !: d:   Начать транзакцию типа interrupt. 
// !: d:   </td>
// !: d: </tr>
//
// !: d: <tr>
// !: d:   <td valign=top>
// !: d:   USB_COMPLETE_INTERRUPT 
// !: d:   </td> 
// !: d:   <td valign=top>
// !: d:   s_usb_c_interrupt
// !: d:   </td> 
// !: d:   <td valign=top>
// !: d:   Завершить транзакцию типа interrupt.
// !: d:   </td>
// !: d: </tr>
//
// !: d: <tr>
// !: d:   <td valign=top>
// !: d:   USB_ADD_DEVICE_CLASS 
// !: d:   </td> 
// !: d:   <td valign=top>
// !: d:   s_usb_driver_context
// !: d:   </td> 
// !: d:   <td valign=top>
// !: d:   Добавление контекста драйвера USB устройства.
// !: d:   </td>
// !: d: </tr>
//
// !: d: <tr>
// !: d:   <td valign=top>
// !: d:   USB_REMOVE_DEVICE_CLASS
// !: d:   </td> 
// !: d:   <td valign=top>
// !: d:   int32
// !: d:   </td> 
// !: d:   <td valign=top>
// !: d:   Удаление контекста драйвера USB устройства. Аргумент функции - 
// !: d:   указатель на содержащую класс устройства переменную.
// !: d:   </td>
// !: d: </tr>
//
// !: d: <tr>
// !: d:   <td valign=top>
// !: d:   USB_DEVICE_ATTACH
// !: d:   </td> 
// !: d:   <td valign=top>
// !: d:   s_usb_attach_func 
// !: d:   </td> 
// !: d:   <td valign=top>
// !: d:   Добавление адреса функции вызываемой при обнаружении события 
// !: d:   подключения/отключения USB устройства. 
// !: d:   Аргумент функции - указатель на адрес функции. Функция вызывается 
// !: d:   путем создания процесса с системным стеком в 2048Кб. 
// !: d:   Входным аргументом функции является указатель на структуру 
// !: d:   s_usb_attach_func_arg. При удалении функции необходимо 
// !: d:   передать NULL указатель на вызываемую функцию.
// !: d:   </td>
// !: d: </tr>
//
// !: d: </table>
// !: -:
//***sss********************************************************************************************
int32 usb_ioctl(s_os_driver_descriptor* d, int32 cmd, const void* arg)
{
  switch(cmd)
  {
  //===============================================================
  //Standard control command:
    //Инициализация:
    case IOC_INIT:
      return lg_usb_init_driver();
        
    //Деинициализация:
    case IOC_DEINIT:            
      return lg_usb_deinit_driver();

    //Инициализация данных:
    case IOC_INIT_DESCRIPTOR:
      return lg_usb_init_descriptor(d);

    //Деинициализация данных:
    case IOC_DEINIT_DESCRIPTOR: 
      return lg_usb_deinit_descriptor(d);

    //Переход по директориям в корне драйвера:
    case IOC_INODE_SELECT:      
      return lg_usb_inode_select(d, (char*)arg);

    //Получение списка файлов:
    case IOC_INODE_LIST:
      return lg_usb_inode_list(d, (s_inode**)arg);
  //===============================================================
  //Driver control command:
    case USB_CONTROL_TRANSFER:
      return lg_usb_control_transaction(d, (s_usb_control*)arg);

    case USB_BULK_TRANSFER:
      return lg_usb_bulk_transaction(d, (s_usb_bulk*)arg);
        
    case USB_START_INTERRUPT:
      return lg_usb_start_interrupt_transaction(d, (s_usb_s_interrupt*)arg);

    case USB_COMPLETE_INTERRUPT:
      return lg_usb_complete_interrupt_transaction(d, (s_usb_c_interrupt*)arg);

    case USB_ADD_DEVICE_CLASS:
      return lg_usb_add_device_class(d, (s_usb_driver_context*)arg);
        
    case USB_REMOVE_DEVICE_CLASS:
      return lg_usb_remove_device_class(d, (int32*)arg);
    
    case USB_DEVICE_ATTACH:
      return lg_usb_attach_function(d, (s_usb_attach_func*)arg);

    default:
      return OSE_BAD_CMD;
  }
}       
//**************************************************************************************************
//       Добавить драйвер в систему
//-------------------------------------------------------------------------------------------------
// !: fn: int32 drv_usb_plug()
//
// !: d: Добавляет драйвер шины USB в систему<br><br> 
//
// !: d: Возвращаемые значения:<br>
// !: d: - Стандартные коды ошибок ioctl.<br>
//***sss********************************************************************************************
int32 drv_usb_plug()
{
  return drv_plug("/dev/usb", INOT_FOLDER, &usb_open, &usb_close, &usb_read, &usb_write, &usb_ioctl, NULL, 0);
}
//**************************************************************************************************
//      Удалить драйвер из системы 
//-------------------------------------------------------------------------------------------------
// !: fn: int32 drv_usb_unplug()
//
// !: d: Удаляет драйвер ГСЧ из системы<br><br> 
//
// !: d: Возвращаемые значения:<br>
// !: d: - Стандартные коды ошибок ioctl.<br>
//***sss********************************************************************************************
int32 drv_usb_unplug()
{
  return drv_unplug("usb");
}

//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//
//          Логические функции драйвера
//
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
struct s_empty_number
{
    uint8                                   max_number;
    uint8*                                  tab_number;
};
//Обобщенная информация устройста:
struct s_pipe
{
    uint8                                   device_address;
    uint8                                   device_speed;
    uint8                                   config_value;
    uint8                                   device_class;
    uint8                                   device_sub_class;   
    uint8                                   interface_number;
    uint8                                   interface_class;
    uint8                                   interface_sub_class;
    uint8                                   interface_protocol;
    uint8                                   number_endpoints;
    uint8                                   hub_address;
    uint8                                   port_number;
    uint8                                   max_packet_size_0;
};
//Стандартные дескрипторы устройства:
struct s_standard_descriptors
{
    s_standard_device_descriptor            usbdevice;
    s_standard_configuration_descriptor     usbconfiguration;
    s_standard_interface_descriptor         usbinterface;
};
//Описание конечной точки:
struct s_list_usb_endpoint
{
    char                                    name[16];
    s_standard_endpoint_descriptor          descriptor;
    uint8                                   data_toggle;
};
//Данные об устройстве:
struct s_list_usb_device
{
    char*                                   name;
    s_list_usb_device*                      prev;
    s_list_usb_device*                      next;
    s_pipe                                  pipe;
    s_standard_descriptors                  descriptor;
    s_list_usb_endpoint*                    endpoint;           
    void*                                   classdesc;
    void*                                   data;
    uint32                                  sem;
    uint32                                  drv_pluged;
};
//Список контекстов драйверов USB устройств:
struct s_list_usb_driver_context
{
    s_list_usb_driver_context*              prev;
    s_list_usb_driver_context*              next;
    s_usb_driver_context                    ctx;
    int32                                   cnew;
};
//Список контекстов запущенных пользовательских процессов:
struct s_list_usb_attach_func
{
    s_list_usb_attach_func*                 prev;
    s_list_usb_attach_func*                 next;
    uint32                                  pid;
};
//Дескрипторы HUB устройства:
struct s_hubclass_descriptors
{
    s_hub_descriptor                        hub_descriptor;
    s_hub_status                            hub_status;
    s_hub_port_status                       hub_port_status;
};
struct s_usb_hub_data
{
    int32                                   id;
    int32                                   flag;
    int32                                   data;
    int32                                   size;
    int32                                   endpoint;
    s_list_usb_device**                     device_on_port;
};
struct s_usb_attach_func_info
{
    int       (*func)(s_usb_attach_func_arg*);
    void*     data;
    uint32    size;
};
//-------------------------------------------------------------------------------------------------
int8    usb_driver_init = 0;
uint32  filehc = RES_VOID;
uint32  sem_usb = RES_VOID;
uint32  sem_usb_hub_enumeration = RES_VOID;
uint32  sem_usb_attach_func_sync = RES_VOID;
s_usb_attach_func_info  usb_attach;
//-------------------------------------------------------------------------------------------------
//Системные и транспортные:
int32   usb_init_driver();
int32   usb_deinit_driver();
int32   usb_device_request(s_list_usb_device* device, s_usb_request* request, void* data);
int32   usb_bulk_transaction(s_list_usb_device* device, s_usb_bulk* arg);
int32   usb_start_interrupt_transaction(s_list_usb_device* device, s_usb_s_interrupt* arg);
int32   usb_complete_interrupt_transaction(s_list_usb_device* device, int32 endpoit_number, int32 id);
//-------------------------------------------------------------------------------------------------
//Системные:
int     usb_enumeration_process(void* arg);
int32   usb_device_add(s_list_usb_device* hub, int32 port_event);
void    usb_device_delete(s_list_usb_device* hub, int32 port_event);
int32   usb_device_enumerate(s_list_usb_device* device);
int32   usb_class_descriptor(s_list_usb_device* device, char* parent_name, char* self_name, char* hub_name, int32 hub_port);
int32   usb_class_drv_plug(s_list_usb_device* device, s_list_usb_driver_context* context);
int32   usb_hc_config(s_list_usb_device* device, bool connected);
void    usb_class_descriptor_destroy(s_list_usb_device* device);
int32   usb_attach_function(s_usb_attach_func* arg);
void    usb_attach_func_exit_vector();
//Работа со списком USB устройств:
int32               init_usbd_list();
void                deinit_usbd_list();
s_list_usb_device*  create_device();
void                delete_device(s_list_usb_device* device);
s_list_usb_device*  get_device(char* name);
void                delete_all_device();
int32               add_name_device(s_list_usb_device* device, char* name, char* parent_name, char* self_name);
//Работа со списком контекстов драйверов USB устройств:
s_list_usb_driver_context*  create_driver_context(s_usb_driver_context* ctx);
void                        delete_driver_context(s_list_usb_driver_context* device);
s_list_usb_driver_context*  get_driver_context(int32 device_class);
//Работа со списком контекстов запущенных пользовательских процессов:
int32                    init_usb_attach_func_list();
void                     deinit_usb_attach_func_list();
s_list_usb_attach_func*  create_usb_attach_func();
void                     delete_usb_attach_func(s_list_usb_attach_func* ctx);
s_list_usb_attach_func*  get_usb_attach_func(uint32 pid);
/**************************************************************************************************\
*   Инициализация драйвера
\***sss********************************************************************************************/
int32 lg_usb_init_driver()
{
  if(!usb_driver_init)
  {
    int32 error;
    usb_attach.func = NULL;
    usb_attach.data = NULL;
    usb_attach.size = 0x0;
    filehc = drv_mkd("/dev/usbhc");
    if(filehc == RES_VOID) 
      return OSE_NO_DEVICE;
    res_share(filehc);
    
    error = usb_init_driver();
    if(error) return error;

    usb_driver_init = 1;
    return OSE_OK;
  }
  else
    return OSE_ALREADY_PLUGGED;
}
/**************************************************************************************************\
*   Деинициализация драйвера
\***sss********************************************************************************************/
int32 lg_usb_deinit_driver()
{
   drv_rmd(filehc);
   usb_deinit_driver();
   usb_driver_init = 0;
   return OSE_OK;
}
/**************************************************************************************************\
*   Инициализация дескриптора
\***sss********************************************************************************************/
int32 lg_usb_init_descriptor(s_os_driver_descriptor* d)
{
  return OSE_OK;
}
/**************************************************************************************************\
*   Деинициализация дескриптора
\***sss********************************************************************************************/
int32 lg_usb_deinit_descriptor(s_os_driver_descriptor* d)
{
  return OSE_OK;
}
/**************************************************************************************************\
*   Переход по директориям в корне драйвера
\***sss********************************************************************************************/
int32 lg_usb_inode_select(s_os_driver_descriptor* d, char* name)
{
  s_list_usb_device* device; 
  
  if(!strcmp(name,"."))
      return OSE_OK;
  else
  if(!strcmp(name,".."))
  {
    drv_dec(d);
    if(d->data == NULL)
      drv_rfs(d);
    else
      d->data = NULL;
  }
  else 
  if( ( (device = get_device(name)) != NULL ) && (d->data == NULL) )
  {
    drv_inc(d, name);
    d->data = device;
  }
  else
    return  OSE_NO_NODE;

  return OSE_OK;
}
/**************************************************************************************************\
*   Получение списка файлов
\***sss********************************************************************************************/
int32 lg_usb_inode_list(s_os_driver_descriptor* d, s_inode **arg)
{
  extern uint32               sem_usbd_list;
  extern s_list_usb_device*   first_usb_device;
  s_inode* node;
  s_list_usb_device* device;
  s_inode* first_device = NULL;
  s_inode* last_device = NULL;
  if(d->data != NULL) return OSE_NO_NODE;

  sem_lock( sem_usbd_list, SEM_INFINITY );
  device = first_usb_device;
  while(device != NULL)
  {
    node = new s_inode;
    if(node == NULL)
    {
      sem_unlock(sem_usbd_list);
      return OSE_NO_MEMORY;
    }

    node->name = new char[strlen(device->name)+1];
    if(node->name == NULL)
    {
      sem_unlock(sem_usbd_list);
      delete node;
      return OSE_NO_MEMORY;
    }

    node->prev = NULL;
    node->next = NULL;
    strcpy(node->name, device->name);
    node->size = sizeof(s_list_usb_device);
    node->mktime = 0;
    node->own_user = 0;
    node->own_group = 0;
    node->access = ACC_FULL_FILE;
    node->type = INOT_FILE;

    if(first_device == NULL) 
        first_device = node;
    if(last_device == NULL)
        node->prev = NULL;
    else
    {
      last_device->next = node;
      node->prev = last_device;
    }
    last_device = node;
    node->next = NULL;

    device = device->next;
  }
  (*arg) = first_device;
  sem_unlock(sem_usbd_list);
  return OSE_OK;
}
/**************************************************************************************************\
*   Control
\***sss********************************************************************************************/
int32 lg_usb_control_transaction(s_os_driver_descriptor* d, s_usb_control* arg)
{
  if(d->data == NULL) return OSE_BAD_RDESC;
  if(arg == NULL) return OSE_BAD_PARAM;
  return usb_device_request((s_list_usb_device*)d->data, &arg->request, arg->data);
}
/**************************************************************************************************\
*   Bulk
\***sss********************************************************************************************/
int32 lg_usb_bulk_transaction(s_os_driver_descriptor* d, s_usb_bulk* arg)
{
  if(d->data == NULL) return OSE_NO_DEVICE;
  if(arg == NULL) return OSE_BAD_PARAM;
  return usb_bulk_transaction((s_list_usb_device*)d->data, arg);
}
/**************************************************************************************************\
*   Interrupt
\***sss********************************************************************************************/
int32 lg_usb_start_interrupt_transaction(s_os_driver_descriptor* d, s_usb_s_interrupt* arg)
{
  if(d->data == NULL) return OSE_NO_DEVICE;
  if(arg == NULL) return OSE_BAD_PARAM;
  return usb_start_interrupt_transaction((s_list_usb_device*)d->data, arg);   
}

int32 lg_usb_complete_interrupt_transaction(s_os_driver_descriptor* d, s_usb_c_interrupt* arg)
{
  if(d->data == NULL) return OSE_NO_DEVICE;
  if(arg == NULL) return OSE_BAD_PARAM;
  return usb_complete_interrupt_transaction((s_list_usb_device*)d->data, arg->endpoit_number, arg->id);   
}
/**************************************************************************************************\
*   Добавление в список контекст драйвера USB устройства
\***sss********************************************************************************************/
int32 lg_usb_add_device_class(s_os_driver_descriptor* d, s_usb_driver_context* ctx)
{
  s_list_usb_driver_context*    context;
  context = get_driver_context(ctx->device_class);
  if(context != NULL) return OSE_ALREADY_ADDED;
  context = create_driver_context(ctx);
  if(context == NULL) return OSE_NO_MEMORY;
  sem_unlock(sem_usb_hub_enumeration);
  return OSE_OK;
}
/**************************************************************************************************\
*   Удаление из списока контекст драйвера USB устройства
\***sss********************************************************************************************/
int32 lg_usb_remove_device_class(s_os_driver_descriptor* d, int32* device_class)
{
  s_list_usb_driver_context* context;
  context = get_driver_context(*device_class);
  if(context == NULL) return OSE_NO_ELEMENT;
  delete_driver_context(context);
  return OSE_OK;
}
/**************************************************************************************************\
*   Callback function
\***sss********************************************************************************************/
int32 lg_usb_attach_function(s_os_driver_descriptor* d, s_usb_attach_func* arg)
{
  if(d->data != NULL) return OSE_NO_NODE;
  return usb_attach_function(arg);
}
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//
//          Функции драйвера
//
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//Максимальное количество USB устройсв:
#define NUMBER_USB_DEVICE       128

//-------------------------------------------------------------------------------------------------
int8                exit_enumeration_process = 0;
s_empty_number      empty_device_address;

//Дескрипторы/запросы устройств:
//  Standatd request:
int32   rqst_get_short_device_descriptor(s_list_usb_device* device, void* descriptor);
int32   rqst_set_address(s_list_usb_device* device, int32 address);
int32   rqst_get_device_descriptor(s_list_usb_device* device, void* descriptor);
int32   rqst_get_short_configuration_descriptor(s_list_usb_device* device, void* descriptor);
int32   rqst_get_configuration_descriptor(s_list_usb_device* device, void* descriptor, void* total_buf, int32 total_len);
int32   rqst_get_interface_descriptor(s_list_usb_device* device, void* descriptor, void* total_buf, int32 total_len);
int32   rqst_get_end_point_descriptor(s_list_usb_device* device, int32 num_ep, void* descriptor, void* total_buf, int32 total_len);
int32   rqst_set_configuration(s_list_usb_device* device, int32 config_value);
int32   rqst_get_configuration(s_list_usb_device* device, void* config_value);
int32   rqst_clear_feature(s_list_usb_device* device, uint8 reqest_type, uint16 feature_selector, int32 endpoint_number);
int32   rqst_set_feature(s_list_usb_device* device, uint8 reqest_type, uint16 feature_selector, int32 endpoint_number);
int32   descriptor_copy(int32 descriptor_tyre, uint8* addr_dst, uint8* addr_src, int32 all_length);
//  HUB request:
int32   rqst_get_hub_descriptor(s_list_usb_device* device, void* descriptor);
int32   rqst_get_hub_status(s_list_usb_device* device, void* descriptor);
int32   rqst_get_port_status(s_list_usb_device* device, int32 port, void* descriptor);
int32   rqst_set_port_feature(s_list_usb_device* device, uint16 feature_selector, uint16 port);
int32   rqst_clear_port_feature(s_list_usb_device* device, uint16 feature_selector, uint16 port);
int32   rqst_clear_port_feature_with_status(s_list_usb_device* device, uint16 feature_selector, uint16 port, void* descriptor);
int32   rqst_set_port_feature_with_status(s_list_usb_device* device, uint16 feature_selector, uint16 port, void* descriptor);
//  Mass storage device request:
int32   rqst_bulk_only_mass_storage_reset(s_list_usb_device* device, int32 interface_number);
int32   rqst_get_max_lun(s_list_usb_device* device,void* lun, int32 interface_number);
//Список конечных точек:
int32                create_endpiont_list(s_list_usb_endpoint** first_endpoint, int32 number_endpoints);
void                 delete_endpiont_list(s_list_usb_endpoint** first_endpoint);
s_list_usb_endpoint* get_endpiont(s_list_usb_endpoint* endpoint, int32 number_endpoints, int32 endpoint_number);
//Служебные:
int32   init_usb_address(s_empty_number* istruct, int32 imax_number);
int32   deinit_usb_address(s_empty_number* istruct);
int32   alloc_usb_address(s_empty_number* istruct);
int32   free_usb_address(s_empty_number* istruct, int32 inumber);
/**************************************************************************************************\
*   Инициализация
\***sss********************************************************************************************/
int32 usb_init_driver()
{
  int32   error, stage;
  s_list_usb_device* internal_hub;
  stage = 0;
  //*** STAGE1 ***
  //Инициализация списка USB устройств:
  error = init_usbd_list();
  if(error)
  {
    stage = 0;
    goto m_return;
  }  

  //*** STAGE2 ***
  //Инициализация структуры свободных адресов USB устройств:
  error = init_usb_address(&empty_device_address,NUMBER_USB_DEVICE);
  if(error)
  {
    stage = 1;
    goto m_return;
  }  

  //*** STAGE3 ***
  //Создаем дескриптор внутреннего хаба:
  internal_hub = create_device();
  if(internal_hub == NULL) 
  {
    stage = 2;
    goto m_return;
  }
  internal_hub->pipe.device_speed = USB_HI_SPEED;
  #ifdef CONSOLE_DEBUG
  {FILE* dbgout = fopen( "/dev/dbgout", "w" );
  fprintf(dbgout,"<usbhc>[1]: Найдено новое USB устройство\n");
  fclose( dbgout );}
  #endif 
  //*** STAGE4 ***
  sem_usb = sem_alloc(1, NULL);
  if(sem_usb == RES_VOID)
  {
    stage = 3;  
    error = OSE_CANT_CREATE_SEM;
    goto m_return;
  }  
  //*** STAGE5 ***
  //Регистрируем семафор:
  internal_hub->sem = sem_alloc(1, NULL);
  if(internal_hub->sem == RES_VOID) 
  {
    stage = 4;
    error = OSE_CANT_CREATE_SEM;
    goto m_return;
  }
  //*** STAGE6 ***
  //Инициализация семафора процесса нумерации:
  sem_usb_hub_enumeration = sem_alloc(0, NULL);
  if(sem_usb_hub_enumeration==RES_VOID) 
  {
    stage = 5;
    error = OSE_CANT_CREATE_SEM;
    goto m_return;
  }
  //*** STAGE7 ***
  //Регистрируем семафор синхронизации: 
  sem_usb_attach_func_sync = sem_alloc(1,NULL);
  if(sem_usb_attach_func_sync == RES_VOID) 
  {
    stage = 6;
    error = OSE_CANT_CREATE_SEM;
    goto m_return;
  }
  //*** STAGE8 ***
  error = init_usb_attach_func_list();
  if(error)
  {
    stage = 7;
    goto m_return;
  }  
  //*** STAGE9 ***
  //Нумерация внутреннего хаба:
  error = usb_device_enumerate(internal_hub);
  if(error)
  {
    stage = 8;
    goto m_return;
  }
  error = usb_hc_config(internal_hub, true);  
  if(error)
  {
    stage = 8;
    goto m_return;
  }  
  error = usb_class_descriptor(internal_hub,"","1","usbhc",1);
  if(error)
  {
    stage = 8;
    goto m_return;
  }
  //*** STAGE10 ***
  //Создание процесса нумерации устойств на шине USB:
  s_prc_attr enum_attr;
  memset(&enum_attr, 0x0, sizeof(s_prc_attr));
  enum_attr.exit_vector = NULL;
  enum_attr.stack = 2048;
  error = prc_create(&usb_enumeration_process, NULL, 0, &enum_attr);
  if(error <= 0x0)
  {
    stage = 9;
    goto m_return;
  }
  error = OSE_OK;
  m_return:
  switch(stage)
  {
    case 9:  
    case 8: deinit_usb_attach_func_list();
    case 7: sem_free(sem_usb_attach_func_sync); 
    case 6: sem_free(sem_usb_hub_enumeration);
    case 5: sem_free(internal_hub->sem);
    case 4: sem_free(sem_usb);
    case 3: delete_device(internal_hub);
    case 2: deinit_usb_address(&empty_device_address); 
    case 1: deinit_usbd_list();
  }
  return error;
}
/**************************************************************************************************\
*   Деинициализация TODO
\***sss********************************************************************************************/
int32 usb_deinit_driver()
{
  delete_all_device();
  deinit_usbd_list();
  deinit_usb_address(&empty_device_address);
  deinit_usb_attach_func_list();
  sem_free(sem_usb_attach_func_sync);
  sem_free(sem_usb_hub_enumeration);
  sem_free(sem_usb);  
  return OSE_OK;
}
/**************************************************************************************************\
*   Нумерация устойств на шине USB
\***sss********************************************************************************************/
int usb_enumeration_process(void* arg)
{
  extern s_list_usb_device*   first_usb_device;
  s_list_usb_device*          device;
  s_usb_s_interrupt           hub_int;
  s_usb_hub_data*             hub_data;
  s_hubclass_descriptors*     hub_desc;
  s_list_usb_driver_context*  context;
  char                        name[4];
  while(!exit_enumeration_process)
  {
    device = first_usb_device;
    sem_lock(sem_usb_hub_enumeration, SEM_INFINITY);
    //Проверка всех возможных хабов:
    while(device != NULL)
    {
      strcpy(name, "");
      strncat(name, device->name, 3);
      //Если Хаб есть:
      if(strcmp(name,"hub") == 0)
      {
        hub_data = (s_usb_hub_data*)device->data;
        hub_desc = (s_hubclass_descriptors*)device->classdesc;
        //Был обмен с Хабом?
        //Т.е. на портах хаба (device) произошли изменения:
        if(hub_data->flag)
        {   
          int32   error;
          error = usb_complete_interrupt_transaction(device, hub_data->endpoint, hub_data->id);
          //Были в выполненной транзакции ошибки?
          if(!error)
          {
            hub_data->flag = 0x0;                   
            //Перебираем все порты данного ХАБА:
            for(int32 port=1; port<=hub_desc->hub_descriptor.number_ports; port++)
            {
              int32   error;
              //Были изменения на данном порту Хаба?
              if((hub_data->data>>port)&0x1)
              {
                //Взять статус порта:
                error = rqst_get_port_status(device, port, &hub_desc->hub_port_status);
                hub_data->data &= ~(0x1<<port);
                if(error) continue;
                //=====================================================================
                //CONNECT STATUS CHANGE:
                if(PORT_CONNECTION & hub_desc->hub_port_status.port_change)
                {
                  //Очищаем признак "Connect Status Change":
                  error = rqst_clear_port_feature_with_status(device, FEATURE_C_PORT_CONNECTION, port, &hub_desc->hub_port_status);
                  //Если устройство подключено:
                  if(PORT_CONNECTION & hub_desc->hub_port_status.port_status)
                  {
                    //Сброс порта и начало SOF:
                    error = rqst_set_port_feature_with_status(device, FEATURE_PORT_RESET, port, &hub_desc->hub_port_status);
                    #ifdef CONSOLE_DEBUG
                    {FILE* dbgout = fopen( "/dev/dbgout", "w" );    
                    fprintf(dbgout,"<");
                    fprintf(dbgout,device->name);                    
                    fprintf(dbgout,">[");                    
                    char nport[8];memset(nport,0x0,8);itoa(port,nport);
                    fprintf(dbgout,nport);
                    fprintf(dbgout,"]: Найдено новое USB устройство\n");
                    fclose( dbgout );}
                    #endif
                  }
                  //Если устройство отключено:
                  else
                  {
                    usb_device_delete(device, port);
                    #ifdef CONSOLE_DEBUG
                    {FILE* dbgout = fopen( "/dev/dbgout", "w" );
                    fprintf(dbgout,"<");
                    fprintf(dbgout,device->name);           
                    fprintf(dbgout,">[");                    
                    char nport[8];memset(nport,0x0,8);itoa(port,nport);
                    fprintf(dbgout,nport);
                    fprintf(dbgout,"]: USB устройство удалено\n");
                    fclose( dbgout );}
                    #endif
                  }
                }
                //=====================================================================
                //PORT ENABLE/DISABLE CHANGE:
                if(PORT_ENABLE & hub_desc->hub_port_status.port_change)
                {
                  //  Для особо "умных" девайсов:
                  //  Согласно спецификации USB 2.0 п.11.24.2.7.1.2:
                  //  "Bit PORT_ENABLE may be set only as a result 
                  //  of a SetPortFeature(PORT_RESET) request".
                  //  Следовательно если после сброса порта данный бит 
                  //  небыл устанослен, то считаем это состояние,
                  //  опять же согласно спецификации, "Other fault condition",
                  //  а точнее "Port_Error detection".
                  //  Посему снимаем питание с этого порта и подаем его снова,
                  //  тем самым инициируя повторное обнаружение устройства.
                  //  NOTE: Данные действия повторяем неограниченно, пока
                  //  наш isp176x чего-нибудь не найдет или "не умрет".
                  #ifdef CONSOLE_DEBUG
                  {FILE* dbgout = fopen( "/dev/dbgout", "w" );
                  fprintf(dbgout,"<");
                  fprintf(dbgout,device->name);                    
                  fprintf(dbgout,">[");                    
                  char nport[8];memset(nport,0x0,8);itoa(port,nport);
                  fprintf(dbgout,nport);
                  fprintf(dbgout,"]: Ошибка - обнаружения порта\n");
                  fclose(dbgout);}
                  #endif
                  error = rqst_clear_port_feature_with_status(device, FEATURE_PORT_POWER, port, &hub_desc->hub_port_status);
                  error = rqst_set_port_feature_with_status(device, FEATURE_PORT_POWER, port, &hub_desc->hub_port_status);             
                }
                //=====================================================================
                //SUSPEND CHANGE:
                if(PORT_SUSPEND & hub_desc->hub_port_status.port_change)
                {
                  error = rqst_clear_port_feature_with_status(device, FEATURE_C_PORT_SUSPEND, port, &hub_desc->hub_port_status);
                }
                //=====================================================================
                //OVER-CURRENT INDICATOR CHANGE:
                if(PORT_OVER_CURRENT & hub_desc->hub_port_status.port_change)
                {
                  error = rqst_clear_port_feature_with_status(device, FEATURE_C_PORT_OVER_CURRENT, port, &hub_desc->hub_port_status);
                  #ifdef CONSOLE_DEBUG
                  {FILE* dbgout = fopen( "/dev/dbgout", "w" );
                  fprintf(dbgout,"<");
                  fprintf(dbgout,device->name);                    
                  fprintf(dbgout,">[");                    
                  char nport[8];memset(nport,0x0,8);itoa(port,nport);
                  fprintf(dbgout,nport);
                  fprintf(dbgout,"]: Ошибка - нехватка электропитания\n");
                  fclose(dbgout);}
                  #endif
                  if(!(PORT_OVER_CURRENT & hub_desc->hub_port_status.port_status))
                  {
                    usb_device_delete(device, port);
                    error = rqst_set_port_feature_with_status(device, FEATURE_PORT_POWER, port, &hub_desc->hub_port_status);             
                  }
                }
                //=====================================================================
                //RESET CHANGE:
                if(PORT_RESET & hub_desc->hub_port_status.port_change)
                {
                  //Очищаем признак "Reset Change":
                  error = rqst_clear_port_feature_with_status(device, FEATURE_C_PORT_RESET, port, &hub_desc->hub_port_status);
                  error = usb_device_add(device, port);                           
                  #ifdef CONSOLE_DEBUG
                  if(error)
                  {
                    FILE* dbgout = fopen( "/dev/dbgout", "w" );
                    fprintf(dbgout,"<");
                    fprintf(dbgout,device->name);                    
                    fprintf(dbgout,">[");                    
                    char nport[8];memset(nport,0x0,8);itoa(port,nport);
                    fprintf(dbgout,nport);
                    fprintf(dbgout,"]: Ошибка - ");                     
                    if(error > 0) fprintf(dbgout,"(0x%4.4x) нумерации\n", error);
                    else fprintf(dbgout,"(%d) нумерации\n", error);
                    fclose( dbgout );
                  }
                  #endif
                  if(error > 0)
                  {
                    usb_device_delete(device, port);
                    error = rqst_clear_port_feature_with_status(device, FEATURE_PORT_POWER, port, &hub_desc->hub_port_status);
                    error = rqst_set_port_feature_with_status(device, FEATURE_PORT_POWER, port, &hub_desc->hub_port_status);             
                  }
                }
              }//Были изменения на данном порту Хаба?
            }//Перебираем все порты данного ХАБА:           
          }//Были ли в выполненной транзакции ошибки?
          if( (error & (USB_ER_STALL|USB_ER_BABBLE|USB_ER_PID))==0x0 )
          {
            hub_int.id   = &hub_data->id;
            hub_int.flag = &hub_data->flag;
            hub_int.sem  = sem_usb_hub_enumeration;
            hub_int.data = &hub_data->data;
            hub_int.size = hub_data->size;
            hub_int.endpoit_number = hub_data->endpoint;
            usb_start_interrupt_transaction(device, &hub_int);
          }
        }//Был обмен с Хабом?
      }//Если Хаб есть
      context = get_driver_context(device->pipe.interface_class);
      if(context != NULL)
        usb_class_drv_plug(device, context);
      device = device->next;
    }//Проверка всех возможных хабов
  }//Новый цикл
  return 0x0;
}
/**************************************************************************************************\
*   Добавление информации о подключенном устройстве в структуру данных: Pipe, Descriptor
\***sss********************************************************************************************/
int32 usb_device_add(s_list_usb_device* hub, int32 port_event)
{
  int32               error;
  char                self_name[4];
  s_list_usb_device*  device;
  s_usb_hub_data*     hub_data = (s_usb_hub_data*)hub->data;
  //Создаем девайс:
  device = create_device();
  if(device == NULL) return OSE_NO_MEMORY;
  //У данного Хаба на данном порту весит устройство с Адресом:
  if(hub_data->device_on_port[port_event-1] != NULL)
    usb_device_delete(hub, port_event);
  hub_data->device_on_port[port_event-1] = device;  
  //Регистрируем семафор:
  device->sem = sem_alloc(1,NULL);
  if(device->sem == RES_VOID) return OSE_CANT_CREATE_SEM;
  //Скорость устройства:
  device->pipe.device_speed = ( ((s_hubclass_descriptors*)hub->classdesc)->hub_port_status.port_status & PORT_SPEED_MASK) >> 0x9;
  //Если к ХАБу подключено не HiSpeed устройство, а сам ХАБ HiSpeed:   
  if((device->pipe.device_speed != USB_HI_SPEED)&&(hub->pipe.device_speed == USB_HI_SPEED))
  {
    device->pipe.hub_address = hub->pipe.device_address;
    device->pipe.port_number = port_event;
  }   
  //Если к ХАБу подключено не HiSpeed устройство и сам ХАБ не HiSpeed:
  else if((device->pipe.device_speed != USB_HI_SPEED)&&(hub->pipe.device_speed != USB_HI_SPEED))
  {
    device->pipe.hub_address = hub->pipe.hub_address;
    device->pipe.port_number = hub->pipe.port_number;
  }   
  error = usb_device_enumerate(device);
  if(error) return error;

  error = usb_hc_config(device, true);
  if(error) return error;

  itoa(port_event, self_name);
  error = usb_class_descriptor(device, strchr(hub->name,'1'), self_name, hub->name, port_event);
  return error;
}
/**************************************************************************************************\
*   Удаление информации об отключенных устройствах из структур данных: Pipe, Descriptor
\**************************************************************************************************/
void usb_device_delete(s_list_usb_device* hub, int32 port_event)
{
  s_list_usb_device* device = ((s_usb_hub_data*)hub->data)->device_on_port[port_event-1];
  if(device == NULL) return;
  //Если у хаба "hub" на порту "port_event" подклучен хаб:
  if( USB_DEVICE_CLASS_HUB == device->pipe.interface_class )
  {
    for(int32 port=1; port<=((s_hubclass_descriptors*)device->classdesc)->hub_descriptor.number_ports; port++)
    {
      if( ((s_usb_hub_data*)device->data)->device_on_port[port-1] != NULL )
        usb_device_delete(device, port);
    }
  }
  usb_class_descriptor_destroy(device);
  usb_hc_config(device, false);  
  delete_endpiont_list(&device->endpoint);
  free_usb_address(&empty_device_address, device->pipe.device_address);
  sem_free(device->sem);
  delete_device(device);
  ((s_usb_hub_data*)hub->data)->device_on_port[port_event-1] = NULL;
}
//ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
//      Конфигурация НС
//ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
int32 usb_hc_config(s_list_usb_device* device, bool connected)
{
  int32           error;
  uint32          len;
  s_usbhc_config* config;
  
  //Вычисление длины передаваемого контекста
  len = sizeof(s_usbhc_config) + sizeof(s_usbhc_config_endpoint) * device->pipe.number_endpoints;
  //Резервирование памяти под передачу контекста:
  config = (s_usbhc_config*)heap_alloc(NULL, len, HEAP_ALIGN_4);
  if(config == NULL) return OSE_NO_MEMORY;
  
  config->connected = connected;
  memset(&config->device, 0x0, sizeof(s_usbhc_config_device));
  config->device.device_address = device->pipe.device_address;
  config->device.device_speed = device->pipe.device_speed;  
  config->device.hub_address = device->pipe.hub_address;
  config->device.port_number = device->pipe.port_number;  
  config->device.number_endpoints = device->pipe.number_endpoints;  
  config->endpoint = (s_usbhc_config_endpoint*)((int8*)(&config->endpoint)+sizeof(s_usbhc_config_endpoint*));

  for(int32 i=0; i<device->pipe.number_endpoints; i++)
  {
    config->endpoint[i].endpoint_number = device->endpoint[i].descriptor.endpoint_number;
    config->endpoint[i].attributes = device->endpoint[i].descriptor.attributes;    
    config->endpoint[i].max_packet_size = device->endpoint[i].descriptor.max_packet_size;
    config->endpoint[i].interval = device->endpoint[i].descriptor.interval;
  }  
  error = drv_ioctl(filehc, USBHC_CONFIGURATION, config);  
  heap_free(NULL, config);  
  return error;
}
//ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
//      Нумеровать USB устойства, сбор стандартных дескрипторов.
//ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
int32 usb_device_enumerate(s_list_usb_device* device)
{
  int32   error, new_address;
  uint8*  total_desc = NULL;

  error = 0x0;
  //Получение 8 байт ДЕСКРИПТОРА УСТРОЙСТВА для опрелеления 
  //максимальной длины пакета для нулевой конечной точки:
  device->pipe.max_packet_size_0 = 0x8;
  error = rqst_get_short_device_descriptor(device, &device->descriptor.usbdevice);
  if(error) goto m_error;
  device->pipe.max_packet_size_0 = device->descriptor.usbdevice.max_packet_size_0;

  //Установка адреса устройству:
  new_address = alloc_usb_address(&empty_device_address);
  error = rqst_set_address(device, new_address);
  if(error) goto m_error;
  device->pipe.device_address = new_address;

  //Контроль установки адреса устройству:
  error = rqst_get_short_device_descriptor(device, &device->descriptor.usbdevice);
  if(error) goto m_error;

  //Получение всех 18 байт ДЕСКРИПТОРА УСТРОЙСТВА:
  error = rqst_get_device_descriptor(device, &device->descriptor.usbdevice);
  if(error) goto m_error;
  device->pipe.device_class = device->descriptor.usbdevice.device_class;
  device->pipe.device_sub_class = device->descriptor.usbdevice.device_sub_class;

  //Получение 8 байт ДЕСКРИПТОРА КОНФИГУРАЦИИ:
  error = rqst_get_short_configuration_descriptor(device, &device->descriptor.usbconfiguration);
  if(error) goto m_error;

  total_desc = (uint8*)heap_alloc(NULL, device->descriptor.usbconfiguration.total_length, HEAP_ALIGN_4);
  if(total_desc == NULL)
  { 
    error = OSE_NO_MEMORY;
    goto m_error;
  }

  //Получение ДЕСКРИПТОРА КОНФИГУРАЦИИ:
  error = rqst_get_configuration_descriptor(device, &device->descriptor.usbconfiguration, total_desc, device->descriptor.usbconfiguration.total_length);
  if(error) goto m_error;

  error = rqst_get_interface_descriptor(device, &device->descriptor.usbinterface, total_desc, device->descriptor.usbconfiguration.total_length);
  if(error) goto m_error;
  device->pipe.interface_number = device->descriptor.usbinterface.interface_number;
  device->pipe.interface_class = device->descriptor.usbinterface.interface_class;
  device->pipe.interface_sub_class = device->descriptor.usbinterface.interface_sub_class;
  device->pipe.interface_protocol = device->descriptor.usbinterface.interface_protocol;
  device->pipe.number_endpoints = device->descriptor.usbinterface.number_endpoints;

  //Получение ДЕСКРИПТОРОВ КОНЕЧНЫХ ТОЧЕК:
  error = create_endpiont_list(&device->endpoint, device->pipe.number_endpoints);
  if(error) goto m_error;

  for(int32 i=0; i<device->pipe.number_endpoints; i++)
  {   
    error = rqst_get_end_point_descriptor(device, i, &device->endpoint[i].descriptor, total_desc, device->descriptor.usbconfiguration.total_length);
    if(error) goto m_error;
    switch(device->endpoint[i].descriptor.attributes & 0x3)
    {
      case EP_CONTROL_TYPE:       strcpy(device->endpoint[i].name, "control");        break;
      case EP_ISOCHRONOUS_TYPE:   strcpy(device->endpoint[i].name, "isochronous");    break;
      case EP_BULK_TYPE:          strcpy(device->endpoint[i].name, "bulk");           break;
      case EP_INTERRUPT_TYPE:     strcpy(device->endpoint[i].name, "interrupt");  break;
    }
    switch(device->endpoint[i].descriptor.endpoint_number & 0x80)
    {
      case 0x80:  strcat(device->endpoint[i].name, " in");    break;
      case 0x00:  strcat(device->endpoint[i].name, " out");   break;
    }
    device->endpoint[i].data_toggle = 0x00;
  }

  heap_free(NULL, total_desc);
  total_desc = NULL;

  //Установка конфигурации:
  error = rqst_set_configuration(device, device->descriptor.usbconfiguration.configuration_value);
  if(error) goto m_error;

  //Чтение конфигурации:
  error = rqst_get_configuration(device, &device->pipe.config_value);
  if(error) goto m_error;
  return error;

  m_error:
  if(total_desc != NULL) heap_free(NULL, total_desc);
  return error;
}
/**************************************************************************************************\
*       Получение восьми байтного дескриптора устройства
\**************************************************************************************************/
int32   rqst_get_short_device_descriptor(s_list_usb_device* device, void* descriptor)
{
  int32           error;
  s_usb_request   request;
  // Настройка Запроса
  request.request_type = USB_REQUEST_TYPE_DEV_HOST|USB_REQUEST_TYPE_STANDARD|USB_REQUEST_TYPE_DEVICE;
  request.request      = USB_REQUEST_GET_DESCRIPTOR;
  request.value        = USB_DEVICE_DESCRIPTOR_TYPE<<8|0x00;//Index
  request.index        = 0x0000;
  request.length       = 8;//18
  error = usb_device_request(device, &request, descriptor);
  return error;    
}
/**************************************************************************************************\
*       Установка адреса устройства
\**************************************************************************************************/
int32   rqst_set_address(s_list_usb_device* device, int32 address)
{
  int32           error;
  s_usb_request   request;
  // Настройка Запроса
  request.request_type = USB_REQUEST_TYPE_HOST_DEV|USB_REQUEST_TYPE_STANDARD|USB_REQUEST_TYPE_DEVICE;
  request.request      = USB_REQUEST_SET_ADDRESS;
  request.value        = address;
  request.index        = 0x0000;
  request.length       = 0x0000;
  error = usb_device_request(device, &request, NULL);
  sleep_m(50);
  return error;    
}
/**************************************************************************************************\
*       Получение дескриптора устройства
\**************************************************************************************************/
int32   rqst_get_device_descriptor(s_list_usb_device* device, void* descriptor)
{
  int32           error;
  s_usb_request   request;
  // Настройка Запроса
  request.request_type = USB_REQUEST_TYPE_DEV_HOST|USB_REQUEST_TYPE_STANDARD|USB_REQUEST_TYPE_DEVICE;
  request.request      = USB_REQUEST_GET_DESCRIPTOR;
  request.value        = USB_DEVICE_DESCRIPTOR_TYPE<<8|0x00;
  request.index        = 0x0000;
  request.length       = 18;
  error = usb_device_request(device, &request, descriptor);
  return error;    
}
/**************************************************************************************************\
*       Получение дескриптора конфигурации
\**************************************************************************************************/
int32   rqst_get_short_configuration_descriptor(s_list_usb_device* device, void* descriptor)
{
  int32           error;
  s_usb_request   request;
  // Настройка Запроса      
  request.request_type = USB_REQUEST_TYPE_DEV_HOST|USB_REQUEST_TYPE_STANDARD|USB_REQUEST_TYPE_DEVICE;
  request.request      = USB_REQUEST_GET_DESCRIPTOR;
  request.value        = USB_CONFIGURATION_DESCRIPTOR_TYPE<<8|0x00;
  request.index        = 0x0000;
  request.length       = 8;
  error = usb_device_request(device, &request, descriptor);
  return error;    
}
/**************************************************************************************************\
*       Получение дескриптора конфигурации
\**************************************************************************************************/
int32   rqst_get_configuration_descriptor(s_list_usb_device* device, void* descriptor, void* total_buf, int32 total_len)
{
  int32           error;
  s_usb_request   request;
  // Настройка Запроса
  request.request_type = USB_REQUEST_TYPE_DEV_HOST|USB_REQUEST_TYPE_STANDARD|USB_REQUEST_TYPE_DEVICE;
  request.request      = USB_REQUEST_GET_DESCRIPTOR;
  request.value        = USB_CONFIGURATION_DESCRIPTOR_TYPE<<8|0x00;
  request.index        = 0x0000;
  request.length       = total_len;
  error = usb_device_request(device, &request, total_buf);    
  if(!error)
  descriptor_copy(USB_CONFIGURATION_DESCRIPTOR_TYPE, (uint8*)descriptor, (uint8*)total_buf, total_len);
  return error;    
}
/**************************************************************************************************\
*       Получение дескриптора интерфейса
\**************************************************************************************************/
int32   rqst_get_interface_descriptor(s_list_usb_device* device, void* descriptor, void* total_buf, int32 total_len)
{
  int32           error;
  s_usb_request   request;
  // Настройка Запроса
  request.request_type = USB_REQUEST_TYPE_DEV_HOST|USB_REQUEST_TYPE_STANDARD|USB_REQUEST_TYPE_DEVICE;
  request.request      = USB_REQUEST_GET_DESCRIPTOR;
  request.value        = USB_CONFIGURATION_DESCRIPTOR_TYPE<<8|0x00;
  request.index        = 0x0000;
  request.length       = total_len;
  error = usb_device_request(device, &request, total_buf);    
  if(!error)
  descriptor_copy(USB_INTERFACE_DESCRIPTOR_TYPE, (uint8*)descriptor, (uint8*)total_buf, total_len);
  return error;    
}
/**************************************************************************************************\
*       Получение дескриптора конечных точек
\**************************************************************************************************/
int32   rqst_get_end_point_descriptor(s_list_usb_device* device, int32 num_ep, void* descriptor, void* total_buf, int32 total_len)
{
  int32           error;
  s_usb_request   request;
  // Настройка Запроса
  request.request_type  = USB_REQUEST_TYPE_DEV_HOST|USB_REQUEST_TYPE_STANDARD|USB_REQUEST_TYPE_DEVICE;
  request.request       = USB_REQUEST_GET_DESCRIPTOR;
  request.value         = USB_CONFIGURATION_DESCRIPTOR_TYPE<<8|0x00;//Index
  request.index         = 0x0000;
  request.length        = total_len;//9
  error = usb_device_request(device, &request, total_buf);    
  if(!error)
  {
    int32 descr_length, found_num_ep; 
    uint8* addr_dst = (uint8*)descriptor;
    uint8* addr_src = (uint8*)total_buf;
    found_num_ep = 0;
    while(total_len)
    {
      descr_length = *addr_src;
      if(*(++addr_src) == USB_ENDPOINT_DESCRIPTOR_TYPE)
      {
        if(found_num_ep == num_ep)
        {
          memcpy(addr_dst,--addr_src, descr_length);
          return error;
        }
        else
            found_num_ep++;
      }
      --addr_src += descr_length;
      total_len -= descr_length;
    }
    return OSE_NO_ELEMENT;
  }
  return error;    
}
/**************************************************************************************************\
*       Установить конфигурацию
\**************************************************************************************************/
int32   rqst_set_configuration(s_list_usb_device* device, int32 config_value)
{
  int32           error;
  s_usb_request   request;
  // Настройка Запроса
  request.request_type = USB_REQUEST_TYPE_HOST_DEV|USB_REQUEST_TYPE_STANDARD|USB_REQUEST_TYPE_DEVICE;
  request.request      = USB_REQUEST_SET_CONFIGURATION;
  request.value        = config_value;
  request.index        = 0x0000;
  request.length       = 0x0000;
  error = usb_device_request(device, &request, NULL);    
  sleep_m(100);
  return error;    
}
/**************************************************************************************************\
*       Получить конфигурацию
\**************************************************************************************************/
int32   rqst_get_configuration(s_list_usb_device* device, void* config_value)
{
  int32           error;
  s_usb_request   request;
  // Настройка Запроса
  request.request_type = USB_REQUEST_TYPE_DEV_HOST|USB_REQUEST_TYPE_STANDARD|USB_REQUEST_TYPE_DEVICE;
  request.request      = USB_REQUEST_GET_CONFIGURATION;
  request.value        = 0x0000;
  request.index        = 0x0000;
  request.length       = 0x0001;
  error = usb_device_request(device, &request, config_value);
  return error;    
}
/**************************************************************************************************\
*       Отчистка свойств
\**************************************************************************************************/
int32 rqst_clear_feature(s_list_usb_device* device, uint8 reqest_type, uint16 feature_selector, int32 endpoint_number)
{
  int32           error;
  s_usb_request   request;
  // Настройка Запроса
  request.request_type = USB_REQUEST_TYPE_HOST_DEV|USB_REQUEST_TYPE_STANDARD|reqest_type;
  request.request      = USB_REQUEST_CLEAR_FEATURE;
  request.value        = feature_selector;
  if(reqest_type == USB_REQUEST_TYPE_ENDPOINT)
    request.index    = endpoint_number;
  else 
  if(reqest_type == USB_REQUEST_TYPE_INTERFACE)
    request.index    = endpoint_number;
  else
    request.index    = 0x0000;
  request.length      = 0x0000;
  error = usb_device_request(device, &request, NULL);
  sleep_m(100);
  return error;    
}
/**************************************************************************************************\
*       Установка свойств
\**************************************************************************************************/
int32 rqst_set_feature(s_list_usb_device* device, uint8 reqest_type, uint16 feature_selector, int32 endpoint_number)
{
  int32           error;
  s_usb_request   request;
  // Настройка Запроса
  request.request_type = USB_REQUEST_TYPE_HOST_DEV|USB_REQUEST_TYPE_STANDARD|reqest_type;
  request.request      = USB_REQUEST_SET_FEATURE;
  request.value        = feature_selector;
  if(reqest_type == USB_REQUEST_TYPE_ENDPOINT)
    request.index    = endpoint_number;
  else 
  if(reqest_type == USB_REQUEST_TYPE_INTERFACE)
    request.index    = endpoint_number;
  else
    request.index    = 0x0000;
  request.length     = 0x0000;
  error = usb_device_request(device, &request, NULL);
  return error;    
}
/**************************************************************************************************\
*       Копирование дескриптора
\**************************************************************************************************/
int32   descriptor_copy(int32 descriptor_tyre, uint8* addr_dst, uint8* addr_src, int32 all_length)
{
  uint16 descr_length;
  while(all_length)
  {
    descr_length = *addr_src;
    if(*(++addr_src) == descriptor_tyre)
    {
      memcpy(addr_dst,--addr_src, descr_length);
      addr_src++;
      addr_dst += descr_length;
      return OSE_OK;
    }
    --addr_src += descr_length;
    all_length -= descr_length;
  }
  return OSE_NO_ELEMENT;
}

//ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
//      Создание дескрипторов класса
//ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
/**************************************************************************************************\
*       Сбор дескрипторов класса
\**************************************************************************************************/
int32 usb_class_descriptor(s_list_usb_device* device, char* parent_name, char* self_name, char* hub_name, int32 hub_port)
{
  int32 error = 0x0;
  switch(device->pipe.interface_class)
  {
    case USB_DEVICE_CLASS_RESERVED:             
      add_name_device(device, "res", parent_name, self_name);
      break;
    case USB_DEVICE_CLASS_AUDIO:
    {                
      add_name_device(device, "aud", parent_name, self_name);
      #ifdef CONSOLE_DEBUG
      {FILE* dbgout = fopen( "/dev/dbgout", "w" );
      fprintf(dbgout,"<");fprintf(dbgout,hub_name);fprintf(dbgout,">[");      
      char nport[8];memset(nport,0x0,8);itoa(hub_port,nport);
      fprintf(dbgout,nport);      
      fprintf(dbgout,"]: Устройство класса AUDIO <");                     
      fprintf(dbgout,device->name);                    
      fprintf(dbgout,">\n");
      fclose(dbgout);}
      #endif
      break;
    }
    case USB_DEVICE_CLASS_COMMUNICATIONS:       
    {
      add_name_device(device, "com", parent_name, self_name);
      #ifdef CONSOLE_DEBUG
      {FILE* dbgout = fopen( "/dev/dbgout", "w" );
      fprintf(dbgout,"<");fprintf(dbgout,hub_name);fprintf(dbgout,">[");      
      char nport[8];memset(nport,0x0,8);itoa(hub_port,nport);
      fprintf(dbgout,nport);      
      fprintf(dbgout,"]: Устройство класса COMMUNICATIONS <");                     
      fprintf(dbgout,device->name);                    
      fprintf(dbgout,">\n");      
      fclose(dbgout);}
      #endif
      break;
    }
    case USB_DEVICE_CLASS_HUMAN_INTERFACE:      
    {
      add_name_device(device, "hid", parent_name, self_name);
      #ifdef CONSOLE_DEBUG
      {FILE* dbgout = fopen( "/dev/dbgout", "w" );
      fprintf(dbgout,"<");fprintf(dbgout,hub_name);fprintf(dbgout,">[");      
      char nport[8];memset(nport,0x0,8);itoa(hub_port,nport);
      fprintf(dbgout,nport);      
      fprintf(dbgout,"]: Устройство класса HUMAN INTERFACE <");                     
      fprintf(dbgout,device->name);                    
      fprintf(dbgout,">\n");      
      fclose(dbgout);}
      #endif
      break;
    }
    case USB_DEVICE_CLASS_MONITOR:
    {              
      add_name_device(device, "dsp", parent_name, self_name);
      #ifdef CONSOLE_DEBUG
      {FILE* dbgout = fopen( "/dev/dbgout", "w" );
      fprintf(dbgout,"<");fprintf(dbgout,hub_name);fprintf(dbgout,">[");      
      char nport[8];memset(nport,0x0,8);itoa(hub_port,nport);
      fprintf(dbgout,nport);      
      fprintf(dbgout,"]: Устройство класса MONITOR <");                     
      fprintf(dbgout,device->name);                    
      fprintf(dbgout,">\n");      
      fclose(dbgout);}
      #endif
      break;
    }
    case USB_DEVICE_CLASS_PHYSICAL_INTERFACE:   
    {
      add_name_device(device, "phs", parent_name, self_name);
      #ifdef CONSOLE_DEBUG
      {FILE* dbgout = fopen( "/dev/dbgout", "w" );
      fprintf(dbgout,"<");fprintf(dbgout,hub_name);fprintf(dbgout,">[");      
      char nport[8];memset(nport,0x0,8);itoa(hub_port,nport);
      fprintf(dbgout,nport);      
      fprintf(dbgout,"]: Устройство класса PHYSICAL INTERFACE <");                     
      fprintf(dbgout,device->name);                    
      fprintf(dbgout,">\n");      
      fclose(dbgout);}
      #endif
      break;
    }
    case USB_DEVICE_CLASS_POWER:
    {
      add_name_device(device, "pwr", parent_name, self_name);
      #ifdef CONSOLE_DEBUG
      {FILE* dbgout = fopen( "/dev/dbgout", "w" );
      fprintf(dbgout,"<");fprintf(dbgout,hub_name);fprintf(dbgout,">[");      
      char nport[8];memset(nport,0x0,8);itoa(hub_port,nport);
      fprintf(dbgout,nport);      
      fprintf(dbgout,"]: Устройство класса POWER <");                     
      fprintf(dbgout,device->name);                    
      fprintf(dbgout,">\n");      
      fclose(dbgout);}
      #endif
      break;
    }
    case USB_DEVICE_CLASS_PRINTER:
    {
      s_list_usb_driver_context* context;   
      error = add_name_device(device, "prt", parent_name, self_name);
      if(error) break;      
      #ifdef CONSOLE_DEBUG
      {FILE* dbgout = fopen( "/dev/dbgout", "w" );
      fprintf(dbgout,"<");fprintf(dbgout,hub_name);fprintf(dbgout,">[");      
      char nport[8];memset(nport,0x0,8);itoa(hub_port,nport);
      fprintf(dbgout,nport);      
      fprintf(dbgout,"]: Устройство класса PRINTER <");                     
      fprintf(dbgout,device->name);                    
      fprintf(dbgout,">\n");      
      fclose(dbgout);}
      #endif
      context = get_driver_context(device->pipe.interface_class);
      if(context != NULL)
        error = usb_class_drv_plug(device, context);
      break;
    }
    case USB_DEVICE_CLASS_STORAGE:              
    {
      s_list_usb_driver_context* context;   
      error = add_name_device(device, "msd", parent_name, self_name);
      if(error) break;      
      #ifdef CONSOLE_DEBUG
      {FILE* dbgout = fopen( "/dev/dbgout", "w" );
      fprintf(dbgout,"<");fprintf(dbgout,hub_name);fprintf(dbgout,">[");      
      char nport[8];memset(nport,0x0,8);itoa(hub_port,nport);
      fprintf(dbgout,nport);      
      fprintf(dbgout,"]: Устройство класса MASS STORAGE <");                     
      fprintf(dbgout,device->name);                    
      fprintf(dbgout,">\n");      
      fclose(dbgout);}
      #endif
      context = get_driver_context(device->pipe.interface_class);
      if(context != NULL)
        error = usb_class_drv_plug(device, context);
      break;
    }
    case USB_DEVICE_CLASS_HUB:
    {
      s_usb_s_interrupt       hub_int;
      s_hubclass_descriptors* hub_desc;
      s_usb_hub_data*         hub_data;

      //Выделение памяти для структуры дескрипторов класса HUB:
      device->classdesc = heap_alloc(NULL, sizeof(s_hubclass_descriptors), HEAP_ALIGN_4);
      if(device->classdesc != NULL) memset(device->classdesc, NULL, sizeof(s_hubclass_descriptors));
      else return OSE_NO_MEMORY;
      hub_desc = (s_hubclass_descriptors*) device->classdesc;
      
      //Выделение памяти для структуры данных HUB:
      device->data = heap_alloc(NULL, sizeof(s_usb_hub_data), HEAP_ALIGN_4);
      if(device->data != NULL) memset(device->data, 0x0, sizeof(s_usb_hub_data));
      else return OSE_NO_MEMORY;
      hub_data = (s_usb_hub_data*) device->data;

      error = rqst_get_hub_descriptor(device, &hub_desc->hub_descriptor);
      if(error) return error;

      error = rqst_get_hub_status(device, &hub_desc->hub_status);
      if(error) return error;

      //Выделение памяти для буфера адресов устройств на портах HUB:
      hub_data->device_on_port = (s_list_usb_device**)heap_alloc(NULL, hub_desc->hub_descriptor.number_ports * sizeof(s_list_usb_device*), HEAP_ALIGN_4);
      if(hub_data->device_on_port != NULL) memset(hub_data->device_on_port, NULL, hub_desc->hub_descriptor.number_ports * sizeof(s_list_usb_device*));
      else return OSE_NO_MEMORY;

      //Подаем питание на все порты Хаба:
      for(int32 port=1; port<=hub_desc->hub_descriptor.number_ports; port++)
      {
        error = rqst_clear_port_feature(device, FEATURE_PORT_SUSPEND, port);
        if(error) return error;
        error = rqst_set_port_feature(device, FEATURE_PORT_POWER, port);
        if(error) return error;
      }

      //Заполнение структуры hub data:
      for(int16 i=0; i<device->pipe.number_endpoints; i++)
      {
        if(device->endpoint[i].descriptor.endpoint_number & 0x80)
        {
          hub_data->endpoint = device->endpoint[i].descriptor.endpoint_number;
          hub_data->size = device->endpoint[i].descriptor.max_packet_size;
        }
      }
      error = add_name_device(device, "hub", parent_name, self_name);
      if(error) return error;
      #ifdef CONSOLE_DEBUG
      {FILE* dbgout = fopen( "/dev/dbgout", "w" );
      fprintf(dbgout,"<");fprintf(dbgout,hub_name);fprintf(dbgout,">[");      
      char nport[8];memset(nport,0x0,8);itoa(hub_port,nport);
      fprintf(dbgout,nport);      
      fprintf(dbgout,"]: Устройство класса HUB <");                     
      fprintf(dbgout,device->name);                    
      fprintf(dbgout,">\n");      
      fclose(dbgout);}
      #endif

      hub_int.id   = &hub_data->id;
      hub_int.flag = &hub_data->flag;
      hub_int.sem  = sem_usb_hub_enumeration;
      hub_int.data = &hub_data->data;
      hub_int.size = hub_data->size;
      hub_int.endpoit_number = hub_data->endpoint;
    
      error = usb_start_interrupt_transaction(device, &hub_int);
      if(error) return error;
      device->drv_pluged = 0x1;
      break;
    }
    case USB_DEVICE_CLASS_VENDOR_SPECIFIC:      
      add_name_device(device, "ven", parent_name, self_name);
      break;
  }
  return error;
}
/**************************************************************************************************\
*       Добавление драйверов классов устройств
\**************************************************************************************************/
int32 usb_class_drv_plug(s_list_usb_device* device, s_list_usb_driver_context* context)
{
  int32                           error;
  s_usb_class_driver_context*     dev_ctx;
  uint32                          datalen_dev_ctx;
  char                            path[32], number[4];
  
  error = 0x0;
  if(device->drv_pluged) return error;
  switch(device->pipe.interface_class)
  {
    case USB_DEVICE_CLASS_RESERVED:             
    case USB_DEVICE_CLASS_AUDIO:                
    case USB_DEVICE_CLASS_COMMUNICATIONS:       
    case USB_DEVICE_CLASS_HUMAN_INTERFACE:      
    case USB_DEVICE_CLASS_MONITOR:              
    case USB_DEVICE_CLASS_PHYSICAL_INTERFACE:   
    case USB_DEVICE_CLASS_POWER: break;               
    case USB_DEVICE_CLASS_PRINTER:
    {
      //Вычисление длины передаваемого контекста
      datalen_dev_ctx = sizeof(s_usb_class_driver_context)+( sizeof(s_usb_endpoints)*device->pipe.number_endpoints );
      //Резервирование памяти под передачу контекста:
      dev_ctx = (s_usb_class_driver_context*)heap_alloc(NULL, datalen_dev_ctx, HEAP_ALIGN_4);
      if(dev_ctx == NULL) return OSE_NO_MEMORY;
      dev_ctx->endpoint = (s_usb_endpoints*)((int8*)(&dev_ctx->endpoint)+sizeof(s_usb_endpoints*));
      
      dev_ctx->data = NULL;
      strcpy(dev_ctx->path_usbd, "/dev/usb/");
      strcat(dev_ctx->path_usbd, device->name);
      strcpy(dev_ctx->device_name, device->name);
      dev_ctx->config_value        = device->pipe.config_value;
      dev_ctx->interface_number    = device->pipe.interface_number;
      dev_ctx->interface_class     = device->pipe.interface_class;
      dev_ctx->interface_sub_class = device->pipe.interface_sub_class;
      dev_ctx->interface_protocol  = device->pipe.interface_protocol;
      dev_ctx->number_endpoints    = device->pipe.number_endpoints;
      for(int16 i=0; i<device->pipe.number_endpoints; i++)
      {
        dev_ctx->endpoint[i].endpoint_number = device->endpoint[i].descriptor.endpoint_number;
        dev_ctx->endpoint[i].data_toggle = &device->endpoint[i].data_toggle;
      }
      //path:
      itoa(device->pipe.device_address, number);         
      strcpy(path, "/dev/prt");
      strcat(path, number);
      error = drv_plug(path, INOT_FILE, context->ctx.open_func, context->ctx.close_func, context->ctx.read_func, context->ctx.write_func, context->ctx.ioctl_func, dev_ctx, datalen_dev_ctx);
      heap_free(NULL, dev_ctx);
      if(!error) device->drv_pluged = 0x1;
      break;
    }              
    case USB_DEVICE_CLASS_STORAGE:              
    {
      int8 number_luns = 0;
      error = rqst_bulk_only_mass_storage_reset(device, device->pipe.interface_number);
      if(error) break;
      for(int16 i=0; i<device->pipe.number_endpoints; i++)
      {
        error = rqst_clear_feature(device, USB_REQUEST_TYPE_ENDPOINT, FEATURE_ENDPOINT_HALT, device->endpoint[i].descriptor.endpoint_number);        
        if(error) break;
      }
      if(error) break;
      error = rqst_get_max_lun(device, &number_luns, device->pipe.interface_number);
      if(error & ~USB_ER_STALL) break;
      else error = 0;

      //Выделение памяти для структуры дескрипторов класса MSD:
      device->classdesc = heap_alloc(NULL, sizeof(int32), HEAP_ALIGN_4);
      if(device->classdesc != NULL) memset(device->classdesc, 0x0, sizeof(int32));
      else return OSE_NO_MEMORY;
      *(int8*)device->classdesc = number_luns;
      //Вычисление длины передаваемого контекста
      datalen_dev_ctx = sizeof(s_usb_class_driver_context)+( sizeof(s_usb_endpoints)*device->pipe.number_endpoints );
      //Резервирование памяти под передачу контекста:
      dev_ctx = (s_usb_class_driver_context*)heap_alloc(NULL, datalen_dev_ctx, HEAP_ALIGN_4);
      if(dev_ctx == NULL) return OSE_NO_MEMORY;
      dev_ctx->endpoint = (s_usb_endpoints*)((int8*)(&dev_ctx->endpoint)+sizeof(s_usb_endpoints*));
      //Формирование контекста для каждого логического юнита:
      for(int8 i=0; i<=number_luns; i++)
      {
        dev_ctx->data = NULL;
        strcpy(dev_ctx->path_usbd, "/dev/usb/");
        strcat(dev_ctx->path_usbd, device->name);
        strcpy(dev_ctx->device_name, device->name);
        dev_ctx->config_value        = device->pipe.config_value;        
        dev_ctx->interface_number    = device->pipe.interface_number;
        dev_ctx->interface_class     = device->pipe.interface_class;
        dev_ctx->interface_sub_class = device->pipe.interface_sub_class;
        dev_ctx->interface_protocol  = device->pipe.interface_protocol;
        dev_ctx->number_endpoints    = device->pipe.number_endpoints;
        for(int16 i=0; i<device->pipe.number_endpoints; i++)
        {
          dev_ctx->endpoint[i].endpoint_number = device->endpoint[i].descriptor.endpoint_number;
          dev_ctx->endpoint[i].attributes = device->endpoint[i].descriptor.attributes;
          dev_ctx->endpoint[i].data_toggle = &device->endpoint[i].data_toggle;
        }
        //path:
        itoa(device->pipe.device_address, number);         
        strcpy(path, "/dev/sd");
        strcat(path, number);
        //name:                 
        itoa(i, number);           
        strcat(path, "u");
        strcat(path, number);                   
        error = drv_plug(path, INOT_FILE, context->ctx.open_func, context->ctx.close_func, context->ctx.read_func, context->ctx.write_func, context->ctx.ioctl_func, dev_ctx, datalen_dev_ctx);
        #ifdef FS_MOUNT
        //Mount USB flash:
        {
          uint32 d = drv_mkd("/mnt");
          if(d != RES_VOID)
          {
            if(drv_ioctl(d, IOC_MNT_MOUNT, path) == OSE_OK)
            {
              if(strcmp("msd11", device->name) == 0)
                error = drv_ioctl(d, IOC_MNT_SET_VOLUME, "a");
              if(strcmp("msd12", device->name) == 0)
                error = drv_ioctl(d, IOC_MNT_SET_VOLUME, "b");
            }
            drv_rmd(d);
          }
        }
        #endif
        sem_lock(sem_usb_attach_func_sync, SEM_INFINITY);
        if(usb_attach.func != NULL && error == OSE_OK)
        {
          s_usb_attach_func_arg*  arg_prc;
          s_prc_attr              enum_attr;
          s_list_usb_attach_func* attach_ctx;
          attach_ctx = create_usb_attach_func();
          if(attach_ctx != NULL)
          {
		    int32 arg_size = usb_attach.size+sizeof(s_usb_attach_func_arg);
            arg_prc = (s_usb_attach_func_arg*)heap_alloc(NULL, arg_size, HEAP_ALIGN_4);
			if(arg_prc != NULL)
			{
              //Заполнение аргументов:
              arg_prc->connect_event = 1;
              arg_prc->interface_class = device->pipe.interface_class;
              strcpy(arg_prc->drv_path, path);
              memcpy(&((uint8*)arg_prc)[sizeof(s_usb_attach_func_arg)], usb_attach.data, usb_attach.size);
              //Создание процесса:
              memset(&enum_attr, 0x0, sizeof(s_prc_attr));
              enum_attr.exit_vector = &usb_attach_func_exit_vector;
              enum_attr.stack = 2048;
              attach_ctx->pid = prc_create((int (*)(void*))((uint32)usb_attach.func), arg_prc, arg_size, &enum_attr);
              heap_free(NULL, arg_prc);
              if(((int32)attach_ctx->pid) <= 0x0)
                delete_usb_attach_func(attach_ctx);
            }
          }
        }
        sem_unlock(sem_usb_attach_func_sync);
        if(error) break;
      }
      heap_free(NULL, dev_ctx);
      if(!error) device->drv_pluged = 0x1;
      break;
    }
    case USB_DEVICE_CLASS_HUB:
    case USB_DEVICE_CLASS_VENDOR_SPECIFIC: break;
  }
  return error;
}
/**************************************************************************************************\
*       Удаление дескрипторов класса
\**************************************************************************************************/
void usb_class_descriptor_destroy(s_list_usb_device* device)
{
  switch(device->pipe.interface_class)
  {
    case USB_DEVICE_CLASS_RESERVED:             break;
    case USB_DEVICE_CLASS_AUDIO:                break;
    case USB_DEVICE_CLASS_COMMUNICATIONS:       break;
    case USB_DEVICE_CLASS_HUMAN_INTERFACE:      break;
    case USB_DEVICE_CLASS_MONITOR:              break;
    case USB_DEVICE_CLASS_PHYSICAL_INTERFACE:   break;
    case USB_DEVICE_CLASS_POWER:                break;
    case USB_DEVICE_CLASS_PRINTER:
    {
      char    name[20], number[4];
      //path:
      itoa(device->pipe.device_address, number);         
      strcpy(name, "prt");
      strcat(name, number);
      drv_unplug(name);
      break;
    }
    case USB_DEVICE_CLASS_STORAGE:
    {
      if(device->classdesc == NULL) break;
      char    name[20], number[4];//, path[32];
      int8    number_luns = *(int8*)device->classdesc;
      for(int8 i=0; i<=number_luns; i++)
      {
        //path:
        itoa(device->pipe.device_address, number);         
        strcpy(name, "sd");
        strcat(name, number);
        //name:                 
        itoa(i, number);           
        strcat(name, "u");
        strcat(name, number);                   
        sem_lock(sem_usb_attach_func_sync, SEM_INFINITY);
        if(usb_attach.func != NULL)
        {
          s_usb_attach_func_arg*  arg_prc;
          s_prc_attr              enum_attr;
          s_list_usb_attach_func* attach_ctx;
          attach_ctx = create_usb_attach_func();
          if(attach_ctx != NULL)
          {
		    int32 arg_size = usb_attach.size+sizeof(s_usb_attach_func_arg);
            arg_prc = (s_usb_attach_func_arg*)heap_alloc(NULL, arg_size, HEAP_ALIGN_4);
			if(arg_prc != NULL)
            {
              //Заполнение аргументов:
              arg_prc->connect_event = 0;
              arg_prc->interface_class = device->pipe.interface_class;
              arg_prc->drv_path[0] = 0x0;
              memcpy(&((uint8*)arg_prc)[sizeof(s_usb_attach_func_arg)], usb_attach.data, usb_attach.size);
              //Создание процесса:
              memset(&enum_attr, 0x0, sizeof(s_prc_attr));
              enum_attr.exit_vector = &usb_attach_func_exit_vector;
              enum_attr.stack = 2048;
              attach_ctx->pid = prc_create((int (*)(void*))((uint32)usb_attach.func), arg_prc, arg_size, &enum_attr);
              heap_free(NULL, arg_prc);
              if(((int32)attach_ctx->pid) <= 0x0)
                delete_usb_attach_func(attach_ctx);
            }
          }
        }
        sem_unlock(sem_usb_attach_func_sync);
        #ifdef FS_MOUNT
        //Unmount USB flash:
        {
          char path[64];
          strcpy(path, "/dev/");
          strcat(path, name);
          uint32 d = drv_mkd("/mnt");
          if(d != RES_VOID)
          {
            drv_ioctl(d, IOC_MNT_UNMOUNT, path);
            drv_rmd(d);
          }
        }
        #endif
        drv_unplug(name);
      }
      heap_free(NULL, device->classdesc);
      device->classdesc = NULL;
      break;
    }

    case USB_DEVICE_CLASS_HUB:
    {
      s_hubclass_descriptors* hub_desc = (s_hubclass_descriptors*) device->classdesc;
      s_usb_hub_data*         hub_data = (s_usb_hub_data*) device->data;
      //Завершение транзакции отключенного хаба:
      usb_complete_interrupt_transaction(device, hub_data->endpoint, hub_data->id);

      //Удаление памяти для буфера адресов устройств на портах HUB:
      if(hub_data->device_on_port != NULL) 
      {
        memset(hub_data->device_on_port, NULL, hub_desc->hub_descriptor.number_ports * sizeof(s_list_usb_device*));
        heap_free(NULL, hub_data->device_on_port);
        hub_data->device_on_port = NULL;
      }
      //Удаление памяти для структуры данных HUB:
      if(device->data != NULL) 
      {
        memset(device->data, 0x0, sizeof(s_usb_hub_data));
        heap_free(NULL, device->data);
        device->data = NULL;
      }
      //Удаление памяти для структуры дескрипторов класса HUB:
      if(device->classdesc != NULL)
      {
        memset(device->classdesc, NULL, sizeof(s_hubclass_descriptors));
        heap_free(NULL, device->classdesc);
        device->classdesc = NULL;
      }   
      break;
    }
    case USB_DEVICE_CLASS_VENDOR_SPECIFIC: break;
  }
}
/**************************************************************************************************\
*       Добавление функции callback
\**************************************************************************************************/
int32 usb_attach_function(s_usb_attach_func* arg)
{
  extern s_list_usb_attach_func*  first_usb_attach_func;
  if(arg == NULL) return OSE_BAD_PARAM;
  int32  error;
  sem_lock(sem_usb_attach_func_sync, SEM_INFINITY);
  //Удаление функции:
  if( (arg->func == NULL)&&(usb_attach.func != NULL) )
  {
    while(first_usb_attach_func != NULL)
      prc_yield();
    usb_attach.func = arg->func;
    heap_free(NULL, usb_attach.data);
    usb_attach.data = NULL;
    usb_attach.size = 0x0;
    error = OSE_OK;
  }
  else
  //Добавление функции:
  if( (arg->func != NULL)&&(usb_attach.func == NULL) )
  {
    usb_attach.func = arg->func;
    if(arg->size != 0x0)
    {
      usb_attach.data = heap_alloc(NULL, arg->size, HEAP_ALIGN_4);
      if(usb_attach.data != NULL)
      {
        memcpy(usb_attach.data, arg->data, arg->size);
        usb_attach.size = arg->size;
      }
    }
    error = OSE_OK;
  }
  else
    error = OSE_BAD_ACTION;
  sem_unlock(sem_usb_attach_func_sync);
  return error;
}
/**************************************************************************************************\
*       Функция выхода из процесса callback
\**************************************************************************************************/
void usb_attach_func_exit_vector()
{
  uint32 pid;
  s_list_usb_attach_func* ctx;
  pid = prc_id();
  ctx = get_usb_attach_func(pid);
  delete_usb_attach_func(ctx);
  prc_exit();
}
//ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
//                          Дескрипторы HUB Device
//ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
/**************************************************************************************************\
*       Получение дескриптора HUB
\**************************************************************************************************/
int32 rqst_get_hub_descriptor(s_list_usb_device* device, void* descriptor)
{
  int32           error;
  s_usb_request   request;
  // Настройка Запроса
  request.request_type  = USB_REQUEST_TYPE_DEV_HOST|USB_REQUEST_TYPE_CLASS|USB_REQUEST_TYPE_DEVICE;
  request.request       = USB_REQUEST_GET_DESCRIPTOR;
  request.value         = 0x0000;
  request.index         = 0x0000;
  request.length        = 9;
  error = usb_device_request(device, &request, descriptor);
  return error;    
}
/**************************************************************************************************\
*       Получить статус ХАБа
\**************************************************************************************************/
int32 rqst_get_hub_status(s_list_usb_device* device, void* descriptor)
{
  int32           error;
  s_usb_request   request;
  // Настройка Запроса
  request.request_type = USB_REQUEST_TYPE_DEV_HOST|USB_REQUEST_TYPE_CLASS|USB_REQUEST_TYPE_DEVICE;
  request.request      = USB_REQUEST_GET_STATUS;
  request.value        = 0x0000;
  request.index        = 0x0000;
  request.length       = 4;
  error = usb_device_request(device, &request, descriptor);
  return error;    
}
/**************************************************************************************************\
*       Получить статус ПОРТА
\**************************************************************************************************/
int32 rqst_get_port_status(s_list_usb_device* device, int32 port, void* descriptor)
{
  int32           error;
  s_usb_request   request;
  // Настройка Запроса
  request.request_type = USB_REQUEST_TYPE_DEV_HOST|USB_REQUEST_TYPE_CLASS|USB_REQUEST_TYPE_OTHER;
  request.request      = USB_REQUEST_GET_STATUS;
  request.value        = 0x0000;
  request.index        = 0x00|port;
  request.length       = 4;
  error = usb_device_request(device, &request, descriptor);
  return error;    
}
/**************************************************************************************************\
*       Установить свойства ПОРТА ХАБа
\**************************************************************************************************/
int32 rqst_set_port_feature(s_list_usb_device* device, uint16 feature_selector, uint16 port)
{
  int32           error;
  s_usb_request   request;
  // Настройка Запроса
  request.request_type = USB_REQUEST_TYPE_HOST_DEV|USB_REQUEST_TYPE_CLASS|USB_REQUEST_TYPE_OTHER;
  request.request      = USB_REQUEST_SET_FEATURE;
  request.value        = feature_selector;
  request.index        = 0x00|port;
  request.length       = 0x0000;
  error = usb_device_request(device, &request, NULL);
  sleep_m(200);
  return error; 
}
/**************************************************************************************************\
*       Очистить свойства ПОРТА ХАБа
\**************************************************************************************************/
int32 rqst_clear_port_feature(s_list_usb_device* device, uint16 feature_selector, uint16 port)
{
  int32           error;
  s_usb_request   request;
  // Настройка Запроса
  request.request_type = USB_REQUEST_TYPE_HOST_DEV|USB_REQUEST_TYPE_CLASS|USB_REQUEST_TYPE_OTHER;
  request.request      = USB_REQUEST_CLEAR_FEATURE;
  request.value        = feature_selector;
  request.index        = 0x00|port;
  request.length       = 0x0000;
  error = usb_device_request(device, &request, NULL);
  sleep_m(500);
  return error;    
}
/**************************************************************************************************\
*       Очистить свойства ПОРТА ХАБа и Получить статус ПОРТА
\**************************************************************************************************/
int32 rqst_clear_port_feature_with_status(s_list_usb_device* device, uint16 feature_selector, uint16 port, void* descriptor)
{
  int32 error;
  error  = rqst_clear_port_feature(device, feature_selector, port);
  error |= rqst_get_port_status(device, port, descriptor);
  return error;
}
/**************************************************************************************************\
*       Установить свойства ПОРТА ХАБа и Получить статус ПОРТА
\**************************************************************************************************/
int32 rqst_set_port_feature_with_status(s_list_usb_device* device, uint16 feature_selector, uint16 port, void* descriptor)
{
  int32 error;
  error  = rqst_set_port_feature(device, feature_selector, port);
  error |= rqst_get_port_status(device, port, descriptor);
  return error;
}
//ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
//                          Дескрипторы Mass Storage Device
//ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
/**************************************************************************************************\
*       Сброс Mass Storage Device
\**************************************************************************************************/
int32 rqst_bulk_only_mass_storage_reset(s_list_usb_device* device, int32 interface_number)
{
  int32           error;
  s_usb_request   request;
  // Настройка Запроса
  request.request_type = USB_REQUEST_TYPE_HOST_DEV|USB_REQUEST_TYPE_CLASS|USB_REQUEST_TYPE_INTERFACE;
  request.request      = 0xFF;
  request.value        = 0x0000;
  request.index        = interface_number;
  request.length       = 0x0000;
  error = usb_device_request(device, &request, NULL);
  sleep_m(200);
  return error;    
}
/**************************************************************************************************\
*       Получение количества Logical Units (LUN)
\**************************************************************************************************/
int32 rqst_get_max_lun(s_list_usb_device* device,void* lun, int32 interface_number)
{
  int32           error;
  s_usb_request   request;
  // Настройка Запроса
  request.request_type = USB_REQUEST_TYPE_DEV_HOST|USB_REQUEST_TYPE_CLASS|USB_REQUEST_TYPE_INTERFACE;
  request.request      = 0xFE;
  request.value        = 0x0000;
  request.index        = interface_number;
  request.length       = 0x0001;
  error = usb_device_request(device, &request, lun);
  return error;    
}

/**************************************************************************************************\
*   Отправка запроса
*--------------------------------------------------------------------------------------------------
* При отправке запроса используется Control Transfers типа:
*   Control Read:
*                     Setup                                                 Status
*                   < Stage >           <     Data IN stage    >          < Stage >
*                    ________           _____  _____     _______          _________
*                   |SETUP(0)|..500ms..|IN(1)||IN(0)|...|IN(0/1)|..50ms..|  OUT(1) |
*   No-data Control:
*                     Setup              Status
*                   < Stage >          < Stage >
*                    ________          _________
*                   |SETUP(0)|..50ms..|  IN(1)  |
* (см. Universal Serial Bus Specification п.8.5.3)
\***sss********************************************************************************************/
int32 usb_device_request(s_list_usb_device* device, s_usb_request* request, void* data)
{
  int32           error, size_left;
  uint8           data_toggle;
  s_usbhc_bulk    bulk;
  memset(&bulk.data, 0x0, sizeof(s_usbhc_data));
  sem_lock(sem_usb, SEM_INFINITY);  
//sem_lock(device->sem, SEM_INFINITY);
  bulk.irp.device_address    = device->pipe.device_address;
  bulk.irp.device_speed      = device->pipe.device_speed;
  bulk.irp.hub_address       = device->pipe.hub_address;
  bulk.irp.port_number       = device->pipe.port_number;
  bulk.irp.endpoint_number   = 0x0;
  bulk.irp.endpoint_type     = USB_CONTROL_TYPE;
  bulk.irp.max_packet_length = device->pipe.max_packet_size_0;

  error = 0;
  //====================== Setup Stage ======================//
  bulk.irp.data         = request;
  bulk.irp.size         = sizeof(s_usb_request);
  bulk.irp.token        = USB_SETUP_TOKEN;
  bulk.irp.data_toggle  = 0;
  bulk.next_data_toggle = &data_toggle;
  //Выполнение SETUP TRANSACTION:
  error = drv_ioctl(filehc, USBHC_BULK, &bulk);
  
  //====================== Data stage =======================//
  if(!error && request->length && (data!=NULL))
  {
    //sleep_m(500);//500 ms
    size_left = request->length;
    bulk.irp.token = USB_IN_TOKEN;
    for(int32 offset=0; offset<request->length; offset+=device->pipe.max_packet_size_0)
    {
      bulk.irp.data        = &((uint8*)data)[offset];
      bulk.irp.size        = (size_left > device->pipe.max_packet_size_0) ? device->pipe.max_packet_size_0 : size_left;
      bulk.irp.data_toggle = data_toggle;
      size_left -= device->pipe.max_packet_size_0;
      //Выполнение IN TRANSACTION:
      error = drv_ioctl(filehc, USBHC_BULK, &bulk);
      if(error) break;
    }
  }
  //====================== Status stage =====================//
  bulk.irp.data        = NULL;
  bulk.irp.size        = 0x0;
  bulk.irp.data_toggle = 1;
  //Если был приём данных выполнение OUT TRANSACTION::
  if(!error && request->length)
  {
    sleep_m(50);//50 ms
    bulk.irp.token   = USB_OUT_TOKEN;
    //Выполнение OUT TRANSACTION:
    error = drv_ioctl(filehc, USBHC_BULK, &bulk);   
  }
  //Если небыло приёма данных выполнение IN TRANSACTION:
  else if(!error && !request->length)
  {
    sleep_m(50);//50 ms
    bulk.irp.token   = USB_IN_TOKEN;
    //Выполнение IN TRANSACTION:
    error = drv_ioctl(filehc, USBHC_BULK, &bulk);   
  }
//sem_unlock(device->sem);  
  sem_unlock(sem_usb);
  return error;
}
/**************************************************************************************************\
*       Транзакция типа Bulk
\**************************************************************************************************/
int32 usb_bulk_transaction(s_list_usb_device* device, s_usb_bulk* arg)
{
  int32                   error;
  s_list_usb_endpoint*    endpoint;
  s_usbhc_bulk            bulk;

  endpoint = get_endpiont(device->endpoint, device->pipe.number_endpoints, arg->endpoit_number);
  if(endpoint == NULL) return OSE_BAD_PARAM;
  if((endpoint->descriptor.attributes & USB_TRANSFER_TYPE_MASK) != USB_BULK_TYPE) return OSE_BAD_PARAM;  
//sem_lock(sem_usb, SEM_INFINITY);    
  sem_lock(device->sem, SEM_INFINITY);
  bulk.next_data_toggle      = &endpoint->data_toggle;
  bulk.irp.data              = arg->data;
  bulk.irp.size              = arg->size;
  bulk.irp.device_address    = device->pipe.device_address;
  bulk.irp.device_speed      = device->pipe.device_speed;
  bulk.irp.hub_address       = device->pipe.hub_address;
  bulk.irp.port_number       = device->pipe.port_number;
  bulk.irp.endpoint_number   = endpoint->descriptor.endpoint_number;
  bulk.irp.endpoint_type     = endpoint->descriptor.attributes;
  switch(bulk.irp.endpoint_number & ENDPOINT_DIRECTION_MASK) 
  {
    case ENDPOINT_IN:  bulk.irp.token = USB_IN_TOKEN;  break;
    case ENDPOINT_OUT: bulk.irp.token = USB_OUT_TOKEN; break;
  }
  bulk.irp.max_packet_length = endpoint->descriptor.max_packet_size;
  bulk.irp.data_toggle       = endpoint->data_toggle;
  bulk.irp.interval_polling  = endpoint->descriptor.interval;

  error = drv_ioctl(filehc, USBHC_BULK, &bulk);
  sem_unlock(device->sem);
//sem_unlock(sem_usb);  
  arg->size = bulk.irp.size;
  return error;
}
/**************************************************************************************************\
*       Транзакция типа Interrupt
*--------------------------------------------------------------------------------------------------
* Данная функция организует обмен с заданной конечной точкой устройства в режиме прерывания.
* По завершении обмена типа "прерывания" по адресу flag устанавливаеться 
* флаг-идентификатор об окончании обмена.
\**************************************************************************************************/
int32 usb_start_interrupt_transaction(s_list_usb_device* device, s_usb_s_interrupt* arg)
{
  int32                   error;
  s_list_usb_endpoint*    endpoint;
  s_usbhc_s_interrupt     interrupr;

  endpoint = get_endpiont(device->endpoint, device->pipe.number_endpoints, arg->endpoit_number);
  if(endpoint == NULL) return OSE_BAD_PARAM;
  if((endpoint->descriptor.attributes & USB_TRANSFER_TYPE_MASK) != USB_INTERRUPT_TYPE) return OSE_BAD_PARAM;
  if(arg->size != endpoint->descriptor.max_packet_size) return OSE_BAD_PARAM;    

  interrupr.id                    = arg->id;
  interrupr.flag                  = arg->flag;
  interrupr.sem                   = arg->sem;
  interrupr.name                  = device->name;
  interrupr.irp.data              = arg->data;
  interrupr.irp.size              = arg->size;
  interrupr.irp.device_address    = device->pipe.device_address;
  interrupr.irp.device_speed      = device->pipe.device_speed;
  interrupr.irp.hub_address       = device->pipe.hub_address;
  interrupr.irp.port_number       = device->pipe.port_number;
  interrupr.irp.endpoint_type     = endpoint->descriptor.attributes;

  interrupr.irp.endpoint_number   = endpoint->descriptor.endpoint_number;
  interrupr.irp.max_packet_length = endpoint->descriptor.max_packet_size;
  interrupr.irp.data_toggle       = endpoint->data_toggle;
  interrupr.irp.interval_polling  = endpoint->descriptor.interval;

  switch(interrupr.irp.endpoint_number & ENDPOINT_DIRECTION_MASK) 
  {
    case ENDPOINT_IN:  interrupr.irp.token = USB_IN_TOKEN; break;
    case ENDPOINT_OUT: interrupr.irp.token = USB_OUT_TOKEN; break;
  }
  error = drv_ioctl(filehc, USBHC_START_INTERRUPT, &interrupr);
  return error;
}
//==================================================================================================
int32 usb_complete_interrupt_transaction(s_list_usb_device* device, int32 endpoit_number, int32 id)
{
  int32                   error;
  s_list_usb_endpoint*    endpoint;
  s_usbhc_c_interrupt     interrupr;

  endpoint = get_endpiont(device->endpoint, device->pipe.number_endpoints, endpoit_number);
  if(endpoint == NULL) return OSE_BAD_PARAM;
  if((endpoint->descriptor.attributes & USB_TRANSFER_TYPE_MASK) != USB_INTERRUPT_TYPE) return OSE_BAD_PARAM;
  interrupr.id = id;
  interrupr.next_data_toggle = &endpoint->data_toggle;
  error = drv_ioctl(filehc, USBHC_COMPLETE_INTERRUPT, &interrupr);
  return error;
}
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//
//      Вспомогательнее функции 
//
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
/**************************************************************************************************\
*   Список USB устройств
\***sss********************************************************************************************/
s_list_usb_device*  first_usb_device = NULL;
s_list_usb_device*  last_usb_device = NULL;
uint32              sem_usbd_list;

void  clear_device(s_list_usb_device* device);
//=================================================================================================
int32 init_usbd_list()
{
  sem_usbd_list = sem_alloc(1,NULL);
  if(sem_usbd_list != RES_VOID) 
    return OSE_OK;
  else
    return OSE_CANT_CREATE_SEM;
}
//=================================================================================================
void deinit_usbd_list()
{
    sem_free(sem_usbd_list);
}
//=================================================================================================
s_list_usb_device* create_device()
{
  s_list_usb_device* device;
  device = (s_list_usb_device*)heap_alloc(NULL, sizeof(s_list_usb_device), HEAP_ALIGN_4);
  if(device != NULL)
  {   
    clear_device(device);
    sem_lock(sem_usbd_list, SEM_INFINITY);
    if(first_usb_device == NULL) 
        first_usb_device = device;
    if(last_usb_device == NULL)
        device->prev = NULL;
    else
    {
      last_usb_device->next = device;
      device->prev = last_usb_device;
    }
    last_usb_device = device;
    device->next = NULL;
    sem_unlock(sem_usbd_list);
  }
  return device;
}
//=================================================================================================
void delete_device(s_list_usb_device* device)
{
  if(device == NULL) return;
  sem_lock(sem_usbd_list, SEM_INFINITY);
  if(device->prev != NULL)
    device->prev->next = device->next;
  else
    first_usb_device = device->next;
  if(device->next != NULL)
    device->next->prev = device->prev;
  else
    last_usb_device = device->prev;
  if(device->name != NULL)
    heap_free(NULL, device->name);  
  clear_device(device);
  heap_free(NULL, device);
  sem_unlock(sem_usbd_list);
}
//=================================================================================================
s_list_usb_device* get_device(char* name)
{
  sem_lock(sem_usbd_list, SEM_INFINITY);
  s_list_usb_device* parse_device = first_usb_device;
  //Перебираем весь список:
  while(parse_device != NULL)
  {
    //Если есть имя:
    if(!strcmp(name, parse_device->name))
        break;
    else
        parse_device = parse_device->next;
  }
  sem_unlock(sem_usbd_list);
  return parse_device;
}
//=================================================================================================
void delete_all_device()
{

}
//=================================================================================================
void clear_device(s_list_usb_device* device)
{
  memset(device, 0x0, sizeof(s_list_usb_device));
  device->prev = NULL;
  device->next = NULL;
  device->name = NULL;
  device->endpoint = NULL;
  device->classdesc = NULL;
  device->data = NULL;
  device->sem = RES_VOID;
  device->drv_pluged = 0x0;
}
//=================================================================================================
int32 add_name_device(s_list_usb_device* device, char* name, char* parent_name, char* self_name)
{
  int32 name_length;
  name_length = strlen(name) + strlen(parent_name) + strlen(self_name) + 1;
  sem_lock(sem_usbd_list, SEM_INFINITY);
  device->name = (char*)heap_alloc(NULL, name_length ,HEAP_ALIGN_4);
  if(device->name != NULL)
  {
    strcpy(device->name, name);
    strcat(device->name, parent_name);
    strcat(device->name, self_name);
    sem_unlock(sem_usbd_list);
    return OSE_OK;
  }
  else
    sem_unlock(sem_usbd_list);
  return OSE_NO_MEMORY;
}
/**************************************************************************************************\
*   Список конечных точек
\***sss********************************************************************************************/
int32 create_endpiont_list(s_list_usb_endpoint** endpoint, int32 number_endpoints)
{
  sem_lock(sem_usbd_list, SEM_INFINITY);
  if(*endpoint != NULL) 
  {
    sem_unlock(sem_usbd_list);
    return OSE_BAD_PARAM;
  }
  *endpoint = (s_list_usb_endpoint*)heap_alloc(NULL, sizeof(s_list_usb_endpoint)*number_endpoints, HEAP_ALIGN_4);
  if(*endpoint != NULL) memset(*endpoint, 0x0, sizeof(s_list_usb_endpoint)*number_endpoints); 
  else
  { 
    sem_unlock(sem_usbd_list);
    return OSE_NO_MEMORY;
  }
  sem_unlock(sem_usbd_list);
  return OSE_OK;
}
//=================================================================================================
void delete_endpiont_list(s_list_usb_endpoint** endpoint)
{
  sem_lock(sem_usbd_list, SEM_INFINITY);
  heap_free(NULL, *endpoint);
  *endpoint = NULL;
  sem_unlock(sem_usbd_list);
}
//=================================================================================================
s_list_usb_endpoint* get_endpiont(s_list_usb_endpoint* endpoint, int32 number_endpoints, int32 endpoint_number)
{
  sem_lock(sem_usbd_list, SEM_INFINITY);
  for(int32 i=0; i<number_endpoints; i++)
  {
    if(endpoint[i].descriptor.endpoint_number == endpoint_number)
    {
      sem_unlock(sem_usbd_list);
      return &endpoint[i];
    }
  }
  sem_unlock(sem_usbd_list);
  return NULL;
}
/**************************************************************************************************\
*   Список контекстов драйверов USB устройств
\***sss********************************************************************************************/
s_list_usb_driver_context*  first_usb_context = NULL;
s_list_usb_driver_context*  last_usb_context = NULL;
void clear_driver_context(s_list_usb_driver_context* context);
//=================================================================================================
s_list_usb_driver_context* create_driver_context(s_usb_driver_context* ctx)
{
  s_list_usb_driver_context* context;
  context = (s_list_usb_driver_context*)heap_alloc(NULL, sizeof(s_list_usb_driver_context), HEAP_ALIGN_4);
  if(context != NULL)
  {   
    clear_driver_context(context);
    sem_lock(sem_usbd_list, SEM_INFINITY);
    if(first_usb_context == NULL) 
      first_usb_context = context;
    if(last_usb_context == NULL)
      context->prev = NULL;
    else
    {
      last_usb_context->next = context;
      context->prev = last_usb_context;
    }
    last_usb_context = context;
    context->next = NULL;
    //Сохранение контекста:
    context->ctx.device_class = ctx->device_class;
    context->ctx.open_func    = ctx->open_func;
    context->ctx.close_func   = ctx->close_func;
    context->ctx.read_func    = ctx->read_func; 
    context->ctx.write_func   = ctx->write_func;  
    context->ctx.ioctl_func   = ctx->ioctl_func;
    sem_unlock(sem_usbd_list);
  }
  return context;
}
//=================================================================================================
void delete_driver_context(s_list_usb_driver_context* context)
{
  if(context == NULL) return;
  sem_lock(sem_usbd_list, SEM_INFINITY);
  if(context->prev != NULL)
    context->prev->next = context->next;
  else
    first_usb_context = context->next;
  if(context->next != NULL)
    context->next->prev = context->prev;
  else
    last_usb_context = context->prev;
  clear_driver_context(context);
  heap_free(NULL, context);
  sem_unlock(sem_usbd_list);
}
//=================================================================================================
s_list_usb_driver_context* get_driver_context(int32 device_class)
{
  sem_lock(sem_usbd_list, SEM_INFINITY);
  s_list_usb_driver_context* parse_context = first_usb_context;
  //Перебираем весь список:
  while(parse_context != NULL)
  {
    //Если есть имя:
    if(parse_context->ctx.device_class == device_class)
      break;
    else
      parse_context = parse_context->next;
  }
  sem_unlock(sem_usbd_list);
  return parse_context;
}
void clear_driver_context(s_list_usb_driver_context* context)
{
  memset(context, NULL, sizeof(s_list_usb_driver_context));
  context->ctx.device_class = NULL;
}
/**************************************************************************************************\
*   Список контекстов запущенных пользовательских процессов:
\***sss********************************************************************************************/
s_list_usb_attach_func*  first_usb_attach_func = NULL;
s_list_usb_attach_func*  last_usb_attach_func = NULL;
uint32                   sem_usb_attach_func_list;

void  clear_device(s_list_usb_device* device);
//=================================================================================================
int32 init_usb_attach_func_list()
{
  sem_usb_attach_func_list = sem_alloc(1, NULL);
  if(sem_usbd_list != RES_VOID) 
    return OSE_OK;
  else
    return OSE_CANT_CREATE_SEM;
}
//=================================================================================================
void deinit_usb_attach_func_list()
{
    sem_free(sem_usb_attach_func_list);
}
//=================================================================================================
s_list_usb_attach_func* create_usb_attach_func()
{
  s_list_usb_attach_func* ctx;
  ctx = (s_list_usb_attach_func*)heap_alloc(NULL, sizeof(s_list_usb_attach_func), HEAP_ALIGN_4);
  if(ctx != NULL)
  {   
    ctx->prev = NULL;
    ctx->next = NULL;
    ctx->pid = RES_VOID;
    sem_lock(sem_usb_attach_func_list, SEM_INFINITY);
    if(first_usb_attach_func == NULL) 
        first_usb_attach_func = ctx;
    if(last_usb_attach_func == NULL)
        ctx->prev = NULL;
    else
    {
      last_usb_attach_func->next = ctx;
      ctx->prev = last_usb_attach_func;
    }
    last_usb_attach_func = ctx;
    ctx->next = NULL;
    sem_unlock(sem_usb_attach_func_list);
  }
  return ctx;
}
//=================================================================================================
void delete_usb_attach_func(s_list_usb_attach_func* ctx)
{
  if(ctx == NULL) return;
  sem_lock(sem_usb_attach_func_list, SEM_INFINITY);
  if(ctx->prev != NULL)
    ctx->prev->next = ctx->next;
  else
    first_usb_attach_func = ctx->next;
  if(ctx->next != NULL)
    ctx->next->prev = ctx->prev;
  else
    last_usb_attach_func = ctx->prev;
  heap_free(NULL, ctx);
  sem_unlock(sem_usb_attach_func_list);
}
//=================================================================================================
s_list_usb_attach_func* get_usb_attach_func(uint32 pid)
{
  sem_lock(sem_usb_attach_func_list, SEM_INFINITY);
  s_list_usb_attach_func* parse_ctx = first_usb_attach_func;
  //Перебираем весь список:
  while(parse_ctx != NULL)
  {
    //Если есть PID:
    if(parse_ctx->pid == pid) break;
    parse_ctx = parse_ctx->next;
  }
  sem_unlock(sem_usb_attach_func_list);
  return parse_ctx;
}

/**************************************************************************************************\
*   Незанятый адрес
*--------------------------------------------------------------------------------------------------
*       Описание: Возвращает первый свободный номер из заданного.
\***sss********************************************************************************************/
#define EMPTY_CELL      0xCB
#define FULL_CELL       0x3A
//=================================================================================================
int32   init_usb_address(s_empty_number* istruct, int32 imax_number)   
{
  istruct->tab_number =(uint8*) heap_alloc(NULL, imax_number, HEAP_ALIGN_4);
  if(istruct->tab_number == NULL) return OSE_NO_MEMORY;
  istruct->max_number = imax_number;
  memset(istruct->tab_number, EMPTY_CELL, imax_number);
  istruct->tab_number[0]=FULL_CELL;
  return 0;
}
//=================================================================================================
int32   deinit_usb_address(s_empty_number* istruct)    
{
  heap_free(NULL, istruct->tab_number);
  istruct->tab_number = NULL;
  return 0;
}
//=================================================================================================
int32   alloc_usb_address(s_empty_number* istruct)
{
  if(istruct->tab_number != NULL)
  {
    for(uint32 i=1; i < istruct->max_number; i++)
    {
      if(istruct->tab_number[i] == EMPTY_CELL) 
      {
        istruct->tab_number[i] = FULL_CELL;
        return i;
      }
    }
  }
  return  -1;    
}
//=================================================================================================
int32   free_usb_address(s_empty_number* istruct, int32 inumber)
{
  if(inumber==0x0)
    return -1;
  if( (inumber >= istruct->max_number)||(istruct->tab_number == NULL) ) 
    return -2;
  istruct->tab_number[inumber] = EMPTY_CELL;
  return 0;
}
