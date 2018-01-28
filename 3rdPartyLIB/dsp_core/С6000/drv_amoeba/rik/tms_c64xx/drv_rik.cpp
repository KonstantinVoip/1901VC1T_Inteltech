//**************************************************************************************************
//                         Copyright (C) 2009 RCZI
//--------------------------------------------------------------------------------------------------
// FILENAME....... drv_rnd.cpp
// DATE CREATED... 05/10/2009
// LAST MODIFIED.. 15/02/2010
// DRIVER VERSION. 1.0
//--------------------------------------------------------------------------------------------------
//   Содержимое папки: /dev/rik
//               ..
//   <FILE>      rik1
//   <FILE>      rik2
//--------------------------------------------------------------------------------------------------
//              ДРАЙВЕР РОССИЙСКОЙ ИНТЕЛЛЕКТУАЛЬНОЙ КАРТЫ
//--------------------------------------------------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
//
// !: codepage: cp1251 
//
// !: d: Драйвер РИК.<br>
// !: md: Каждое устройство (файл) в ОС связанно с собственным файлом rik1, rik2. 
// !: md: Путь к устройству: "/dev/rik/rik1", "/dev/rik/rik2". Драйвер реализует 
// !: md: стандартный интерфейс взаимодействия пользователя с устройством по 
// !: md: средствам потокового чтения/записи в устройство (файл) и функции 
// !: md: управляющих воздействий на устройство.
// !: -:
//***sss********************************************************************************************
#include    <rts.h>
#include    <drv_gpio.h>
#include    <mem_fpga.iface15.h>
#include    <drv_rik.h>
#include    <drv_rik_redirect.h>
/**************************************************************************************************\
*       КОНСТАНТЫ
\**************************************************************************************************/
#define RIK_WRITE_CMD_LEN                   5
#define RIK_WRITE_CMD_MAX_RETRY             0xF0
//------------------ Команды РИК -----------------------------------------------
#define CMD_RIK_TRANSFER_START              0x0001
#define CMD_RIK_RESET                       0x0001
#define CMD_RIK_1_POWER_ON                  0x0001
#define CMD_RIK_1_POWER_OFF                 0x0010
#define CMD_RIK_2_POWER_ON                  0x0002
#define CMD_RIK_2_POWER_OFF                 0x0020
//Сброс битов регистра статуса:
#define CMD_RST_RIK_TRANSFER_COMPLETE       0x0001
#define CMD_RST_RIK_1_CHANGE                0x0008
#define CMD_RST_RIK_2_CHANGE                0x0010
#define CMD_RST_RIK_DOOR_CHANGE             0x0040
//------------------ Маски регистра статуса РИК --------------------------------
#define MASK_RIK_TRANSFER_COMPLETE          0x0001
//------------------ Константы РИК ---------------------------------------------
#define C_MAX_BLOCK_LENGTH                  64          //Макс. длина блока РИК в байтах
#define C_OK_CMD_9000                       0x9000      //Хорошая команда
#define C_OK_CMD_61XX                       0x6100      //Хорошая команда
#define C_ERR_TIME_OUT                      0x0100      //Ошибка таймаута
#define C_ERR_EVEN_PARITY                   0x0200      //Ошибка четности
#define C_ERR_PRD                           0x0300      //Ошибка при передачи
#define C_ERR_CARD_LOCK                     0x6983      //Карточка заблокированна
#define C_ERR_PASSWORD                      0x63C0      //Неверный пароль
// -- Путь ---------------------------------------------------------------------------------------------
#define DRV_ROOT_DIR                        0xD000
#define DRV_RIK0_FILE                       0xF000
#define DRV_RIK1_FILE                       0xF001
#define POWER_ON                            0x1
#define POWER_OFF                           0x0
/**************************************************************************************************\
*       СТРУКТУРЫ
\**************************************************************************************************/
struct s_drv_rik_plug_arg
{
  uint32          num_gpio_int;
  uint8           redirect;
};
/**************************************************************************************************\
*       ПРОТОТИПЫ
\**************************************************************************************************/
int   rik_prc_redirect(void* arg);
int32 rik_init(s_os_driver_context* ctx);
int32 rik_deinit(s_os_driver_context* ctx);
int32 rik_power(uint32 PowerCondition,uint32 n_reader);
int32 rik_check(s_drv_rik_var* rikdata);
int32 rik_reset(s_drv_rik_var* rikdata);
int32 rik_swrite(s_drv_rik_var* rikdata, uint8* buf, uint32 length);
int32 rik_sread(s_drv_rik_var* rikdata, uint8* buf, uint32 length);
int32 rik_ready();
int32 rik_open_door();
int32 rik_analysis_error(uint16 iByteLentg, s_drv_rik_var* rikdata);
int32 rik_verify_password(s_rik_password_arg* pas_struct, s_drv_rik_var* rikdata);
int32 rik_change_password(uint8* buf_pwd, s_drv_rik_var* rikdata);
int32 rik_last_errno(int32* errno, s_drv_rik_var* rikdata);
int32 rik_unlock(uint8* n_pwd, s_drv_rik_var* rikdata);
int32 rik_limit_rw(s_drv_rik_var* rikdata);
int32 rik_redirect_init(uint8 redirect);
int32 rik_redirect_deinit();
/**************************************************************************************************\
*       ГЛОБАЛЬНЫЕ ПЕРЕМЕННЫЕ
\**************************************************************************************************/
int32  pid_redirect_prc = 0x0;
int32  gb_exit_rik_prc_redirect = 0x0;
uint32 sem_rik;
void   (*user_rik_int_call_function)(uint16) = NULL;

//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//          Интерфейсные функции драйвера
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//*************************************************************************************************
//       Открытие потока
//-------------------------------------------------------------------------------------------------
// !: fn: int32 rik_open(s_os_driver_descriptor* d, uint16 access) 
//
// !: d: Функция открывает поток в соответствии со спецификатором доступа: 
// !: d: на чтение (DRV_RD), на запись (DRV_WR) или совместно на чтение-запись.<br><br>
//
// !: d: Входные аргументы:<br>
// !: d: - d - указатель на дескриптор драйвера, формируемый ОС;<br>
// !: d: - access - спецификатор доступа. Поддерживаемые значения: DRV_RD, DRV_WR.<br><br>
//
// !: d: Возвращаемые значения:<br>
// !: d: - OSE_OK - если спецификатор доступа поддерживается;<br>
// !: d: - OSE_CANT_OPEN - если спецификатор доступа не поддерживается.<br>
// !: -:
//***sss********************************************************************************************
int32 rik_open(s_os_driver_descriptor* d, uint16 access)
{
  int32 error;
  error = rik_check((s_drv_rik_var*)d->data);
  if(error) return error;

  switch  (access & (DRV_WR | DRV_RD))
  {
    case (DRV_RD):
      d->access = DRV_RD | DRV_OPENED;
      break;
    case (DRV_WR):
      d->access = DRV_WR | DRV_OPENED;
      break;
    case (DRV_WR|DRV_RD):
      d->access = DRV_WR | DRV_RD | DRV_OPENED;
      break;
    default:
      return OSE_CANT_OPEN;
  }
  return  OSE_OK;
}
//**************************************************************************************************
//       Закрытие потока
//-------------------------------------------------------------------------------------------------
// !: fn: int32 rik_close(s_os_driver_descriptor* d)
//
// !: d: Функция закрывает открытый поток на чтение.<br><br>
//
// !: d: Входные аргументы:<br>
// !: d: - d - указатель на дескриптор драйвера, формируемый ОС.<br><br>
//
// !: d: Возвращаемые значения:<br>
// !: d: - OSE_OK - если поток на чтение был открыт;<br>
// !: d: - OSE_STREAM_NOT_OPENED - если поток на чтение не был открыт.<br>
// !: -:
//***sss********************************************************************************************
int32 rik_close(s_os_driver_descriptor* d)
{
  if(d->access & DRV_OPENED){
    d->access = 0;
    return  OSE_OK;
  }
  return OSE_STREAM_NOT_OPENED;
}
//**************************************************************************************************
//       Чтение из потока
//-------------------------------------------------------------------------------------------------
// !: fn: int32 rik_read(s_os_driver_descriptor* d, void* buf, int32 length)
//
// !: d: Функция осуществляет не блокирующее потоковое чтение из устройства.<br><br> 
//
// !: d: Входные аргументы:<br>
// !: d: - d - указатель на дескриптор драйвера, формируемый ОС;<br>
// !: d: - buf - указатель на буфер ввода;<br>
// !: d: - length - вычитываемая длинна.<br><br>
//
// !: d: Возвращаемые значения:<br>
// !: d: - Количество прочитанных байт.<br>
// !: -:
//***sss********************************************************************************************
int32 rik_read(s_os_driver_descriptor* d, void* buf, int32 length)
{
  if(d->access == DRV_RD | DRV_OPENED)
    return rik_sread((s_drv_rik_var*)d->data,(uint8*)buf,length);
  return OSE_PERMISSION_DENIED;
}
//*************************************************************************************************
//       Запись в поток
//-------------------------------------------------------------------------------------------------
// !: fn: int32 rik_write(s_os_driver_descriptor* d, const void* buf, int32 length)
//
// !: d: Функция осуществляет не блокирующую потоковую запись в устройство.<br><br>
//
// !: d: Входные аргументы:<br>
// !: d: - d - указатель на дескриптор драйвера, формируемый ОС;<br>
// !: d: - buf - указатель на буфер вывода;<br>
// !: d: - length - записываемая длинна.<br><br>
//
// !: d: Возвращаемые значения:<br>
// !: d: - Количество записанных байт.<br>
// !: -:
//***sss********************************************************************************************
int32 rik_write(s_os_driver_descriptor* d, const void* buf, int32 length)
{
  if(d->access == DRV_WR | DRV_OPENED)
    return rik_swrite((s_drv_rik_var*)d->data,(uint8*)buf,length);
  return OSE_PERMISSION_DENIED;
}
//**************************************************************************************************
//       Управление вводом/выводом
//-------------------------------------------------------------------------------------------------
// !: fn: int32 rik_ioctl(s_os_driver_descriptor* d, int32 cmd, const void* arg)
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
// !: d: - Стандартные коды ошибок ioctl.<br>
// !: d: - RIK_ER_UNKNOWN - неизвестная ошибка.<br>       
// !: d: - RIK_ER_PARITY - ошибка четности РИК.<br>
// !: d: - RIK_ER_TIMEOUT - ошибка таймаута РИК.<br>
// !: d: - RIK_ER_DATA - недопустимые данные.<br>
// !: d: - RIK_ER_NO_CARD - карточка отсутствует.<br>
// !: d: - RIK_ER_BLOCK_CARD - карточка заблокирована.<br>
// !: d: - RIK_ER_NO_ANSWER - карточка не отвечает.<br>
// !: d: - RIK_ER_PASSWORD - неверный пароль. Биты с 4 по 31 - код ошибки, 
// !: d:   с 0 по 3 - количество оставшихся попыток.<br>
// !: d: - RIK_ER_NOT_CLOSE_DOOR - незакрыта крышка отсека РИК.<br><br>
//
// !: d: Стандартные команды управления:<br>
// !: d: - IOC_INIT, IOC_DEINIT, IOC_INIT_DESCRIPTOR, IOC_DEINIT_DESCRIPTOR,
// !: d:   IOC_INODE_SELECT, IOC_INODE_LIST, IOC_RESIZE, IOC_SEEK.<br><br>
//
// !: d: Команды управления:<br>
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
// !: d:   RIK_USER_INT_FUNC 
// !: d:   </td>
// !: d:   <td valign=top>
// !: d:   s_rik_int_func
// !: d:   </td>
// !: d:   <td valign=top>
// !: d:   Установка адреса функции вызываемой при возникновении прерывания от 
// !: d:   контроллера РИКов. Для удаления адреса функции следует передавать 
// !: d:   указатель NULL. Функция будет вызвана из процедуры обработки 
// !: d:   прерывания.<br>
// !: d:   Вызываемая функция имеет прототип:<br>
// !: d:   void functoin( uint16 status )<br>
// !: d:   Входной аргумент status функции имеет следующий формат:<br>
// !: d:   - RS1[1] = 1 - карточка вставлена в считыватель РИК1<br>
// !: d:   - RS2[2] = 1 - карточка вставлена в считыватель РИК2<br>
// !: d:   - RС1[3] = 1 - было изменение в считывателе РИК1<br>
// !: d:   - RС2[4] = 1 - было изменение в считывателе РИК2<br>
// !: d:   - DR[5] = 1 - крышка РИК открыта<br>
// !: d:   - CDR[6] = 1 - была открыта/закрыта крышка РИК<br>
// !: d:   Для обработки событий, переданных в аргументе, используются 
// !: d:   предопределенные битовые маски, описанные в файле rik.h
// !: d:   </td>
// !: d: </tr>
//
// !: d: <tr>
// !: d:   <td valign=top>
// !: d:   RIK_SET_ZONE 
// !: d:   </td>
// !: d:   <td valign=top>
// !: d:   uint16
// !: d:   </td>
// !: d:   <td valign=top>
// !: d:   Установка номера зоны РИК.
// !: d:   </td>
// !: d: </tr>
//
// !: d: <tr>
// !: d:   <td valign=top>
// !: d:   RIK_SET_OFFSET 
// !: d:   </td>
// !: d:   <td valign=top>
// !: d:   uint16
// !: d:   </td>
// !: d:   <td valign=top>
// !: d:   Установка байтного смещения в зоне.
// !: d:   </td>
// !: d: </tr>
//
// !: d: <tr>
// !: d:   <td valign=top>
// !: d:   RIK_GET_RESET_STRUCT 
// !: d:   </td>
// !: d:   <td valign=top>
// !: d:   s_rik_reset
// !: d:   </td>
// !: d:   <td valign=top>
// !: d:   Получение структуры s_rik_reset.
// !: d:   </td>
// !: d: </tr>
//
// !: d: <tr>
// !: d:   <td valign=top>
// !: d:   RIK_VERIFY_PASSWORD 
// !: d:   </td>
// !: d:   <td valign=top>
// !: d:   s_rik_password_arg
// !: d:   </td>
// !: d:   <td valign=top>
// !: d:   Предъявление пароля.
// !: d:   </td>
// !: d: </tr>
//
// !: d: <tr>
// !: d:   <td valign=top>
// !: d:   RIK_CHANGE_PASSWORD 
// !: d:   </td>
// !: d:   <td valign=top>
// !: d:   uint8
// !: d:   </td>
// !: d:   <td valign=top>
// !: d:   Смена пароля. Входной аргумент функции должен 
// !: d:   указывать на буфер содержащий пароль.
// !: d:   </td>
// !: d: </tr>
//
// !: d: <tr>
// !: d:   <td valign=top>
// !: d:   RIK_UNLOCK_CARD 
// !: d:   </td>
// !: d:   <td valign=top>
// !: d:   uint8
// !: d:   </td>
// !: d:   <td valign=top>
// !: d:   Разблокировка РИК. Входной аргумент должен указывать
// !: d:   на номер файла ключей.
// !: d:   </td>
// !: d: </tr>
// !: d: </table>
// !: -:
//***sss********************************************************************************************
int32 rik_ioctl(s_os_driver_descriptor* d, int32 cmd, const void* arg)
{
  s_drv_rik_var* rikdata = (s_drv_rik_var*)d->data;
  switch(cmd)
  {
    //===============================================================
    //Standard control command:
    //Инициализация драйвера:
    case IOC_INIT: return rik_init((s_os_driver_context*)arg);
    
    //Деинициализация драйвера:
    case IOC_DEINIT: return rik_deinit((s_os_driver_context*)arg);
    
    //Инициализация данных:
    case IOC_INIT_DESCRIPTOR:
    {
      d->data = heap_alloc(NULL,sizeof(s_drv_rik_var),HEAP_ALIGN_4);
      if(!d->data) return OSE_NO_MEMORY;  
      rikdata = (s_drv_rik_var*)d->data;
      memset(rikdata,0x0,sizeof(s_drv_rik_var));
      rikdata->dir_pointer = DRV_ROOT_DIR;
    }
    break;
    //Деинициализация данных:
    case IOC_DEINIT_DESCRIPTOR:
    {
      if(d->data != NULL)
      {
        heap_free(NULL,d->data);
        d->data = NULL;
      }
    }
    break;
    //Переход по директориям в корне драйвера:
    case IOC_INODE_SELECT:      
    {   
      const char* recast_arg = (const char*) arg;
      if(d->access & DRV_OPENED) return OSE_STREAM_OPENED;
      //---------------------------------------------
      if(!strcmp(recast_arg,".")) break;
      //---------------------------------------------
      else if(!strcmp(recast_arg,".."))
      {
        drv_dec(d);
        if(rikdata->dir_pointer == DRV_ROOT_DIR)
          drv_rfs(d);
        else
          rikdata->dir_pointer = DRV_ROOT_DIR;
      }
      //---------------------------------------------
      else if(!strcmp(recast_arg,"rik1") && rikdata->dir_pointer == DRV_ROOT_DIR)
      {
        drv_inc(d,"rik1");
        rikdata->dir_pointer = DRV_RIK0_FILE;
        rikdata->select_reader = 0x0;
        rik_power(POWER_ON, rikdata->select_reader);
      }
      //---------------------------------------------
      else if(!strcmp(recast_arg,"rik2") && rikdata->dir_pointer == DRV_ROOT_DIR)
      {
        drv_inc(d,"rik2");
        rikdata->dir_pointer = DRV_RIK1_FILE;
        rikdata->select_reader = 0x1;
        rik_power(POWER_ON, rikdata->select_reader);
      }
      //---------------------------------------------
      else return  OSE_NO_MEMORY;
    }
    break;
    //Получение списка файлов:
    case IOC_INODE_LIST:
    {
      if(rikdata->dir_pointer != DRV_ROOT_DIR) return OSE_NO_NODE;
      char      rik_name[5];
      char      rik_number[2];
      s_inode*  node;
      s_inode*  first_node = NULL;;
      s_inode*  last_node = NULL;
      
      for(int32 i=0; i<2; i++)
      {
        node = new s_inode;
        if( node == NULL ) return OSE_NO_MEMORY;
        
        node->name = new char[sizeof(rik_name)];
        if(node->name == NULL)
        {
          delete node;
          return OSE_NO_MEMORY;
        }
        
        node->prev = NULL;
        node->next = NULL;
        strcpy(rik_name,"rik");
        itoa(i+1,rik_number);
        strcat(rik_name, rik_number);
        strcpy(node->name, rik_name);
        node->size = sizeof(s_drv_rik_var);
        node->mktime = 0;
        node->own_user = 0;
        node->own_group = 0;
        node->access = ACC_FULL_FILE;
        node->type = INOT_FILE;
        
        if(first_node == NULL) 
            first_node = node;
        if(last_node == NULL)
            node->prev = NULL;
        else
        {
            last_node->next = node;
            node->prev = last_node;
        }
        last_node = node;
        node->next = NULL;
      }
      *((s_inode**)arg) = first_node;
    }
    break;
    //Удаление данных из потока:
    case IOC_RESIZE:            break;
    //===============================================================
    //Driver self control command:
    case RIK_USER_INT_FUNC:
    {
      if(rikdata->dir_pointer != DRV_ROOT_DIR)
        return OSE_NO_NODE;
      user_rik_int_call_function = ((s_rik_int_func*)arg)->func;
    }
    break;
    
    //Установить смещение в пределах зоны:
    case IOC_SEEK:
    case RIK_SET_OFFSET:
    {
      if(rikdata->dir_pointer == DRV_ROOT_DIR)
        return OSE_BAD_PARAM;
      rikdata->offset = *(uint16*)arg;
    }
    break;
    //Установить номер зоны РИК:
    case RIK_SET_ZONE:
    {   
      if(rikdata->dir_pointer == DRV_ROOT_DIR)
        return OSE_BAD_PARAM;        
      rikdata->zone = *(uint16*)arg;
    }
    break;
    //Получить структуру сброса:  
    case RIK_GET_RESET_STRUCT:
    {
      if(rikdata->dir_pointer == DRV_ROOT_DIR)
        return OSE_BAD_PARAM;
      int32 error;
      error = rik_reset(rikdata);
      if(!error) memcpy((uint8*)arg,&rikdata->card_data,sizeof(s_rik_reset));
      return error;
    }
    //Предъявление пароля:
    case RIK_VERIFY_PASSWORD:
    {
      if(rikdata->dir_pointer == DRV_ROOT_DIR)
        return OSE_BAD_PARAM;
      return rik_verify_password((s_rik_password_arg*)arg,rikdata);
    }
    //Изменение пароля:
    case RIK_CHANGE_PASSWORD:
    {
      if(rikdata->dir_pointer == DRV_ROOT_DIR)
        return OSE_BAD_PARAM;
      return rik_change_password((uint8*)arg,rikdata);
    }
    //Разблокировка РИК:
    case RIK_UNLOCK_CARD:
    {
      if(rikdata->dir_pointer == DRV_ROOT_DIR)
        return OSE_BAD_PARAM;
      return rik_unlock((uint8*)arg,rikdata);
    }
    //Анализ открытия крышки РИК:
    case RIK_CHECK_DOOR:
    {
      if(rikdata->dir_pointer != DRV_ROOT_DIR)
        return OSE_NO_NODE;        
      return rik_open_door();
    }
    case RIK_ERRNO:
    {
      return rik_last_errno((int32*)arg, rikdata);
    }
    default: return OSE_BAD_CMD;
  }
  return OSE_OK;
}       
//**************************************************************************************************
//       Добавить драйвер в систему
//-------------------------------------------------------------------------------------------------
// !: fn: int32 drv_rik_plug(uint32 number_gpio_interrupt)
//
// !: d: Добавляет драйвер РИК в систему<br><br> 
//
// !: d: Входные аргументы:<br>
// !: d: - number_gpio_interrupt - номер GPIO - источника прерывания.<br><br>
//
// !: d: Возвращаемые значения:<br>
// !: d: - Стандартные коды ошибок ioctl.<br>
//***sss********************************************************************************************
int32 drv_rik_plug(uint32 number_gpio_interrupt)
{
  s_drv_rik_plug_arg  arg;
  arg.num_gpio_int = number_gpio_interrupt;
  arg.redirect = 0;
  return drv_plug("/dev/rik", INOT_FOLDER, &rik_open, &rik_close, &rik_read, &rik_write, &rik_ioctl, &arg, sizeof(s_drv_rik_plug_arg));
}
//-------------------------------------------------------------------------------------------------
int32 drv_rik_plug(uint32 number_gpio_interrupt, uint8 redirect)
{
  s_drv_rik_plug_arg  arg;
  arg.num_gpio_int = number_gpio_interrupt;
  arg.redirect = redirect;
  return drv_plug("/dev/rik", INOT_FOLDER, &rik_open, &rik_close, &rik_read, &rik_write, &rik_ioctl, &arg, sizeof(s_drv_rik_plug_arg));
}
//**************************************************************************************************
//      Удалить драйвер из системы 
//-------------------------------------------------------------------------------------------------
// !: fn: int32 drv_rik_unplug()
//
// !: d: Удаляет драйвер РИК из системы<br><br> 
//
// !: d: Возвращаемые значения:<br>
// !: d: - Стандартные коды ошибок ioctl.<br>
//***sss********************************************************************************************
int32 drv_rik_unplug()
{
  return drv_unplug("rik");
}
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//          Внутренние функции драйвера
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
/**************************************************************************************************\
*   Обработчик прерывания РИК
\***sss********************************************************************************************/
void rik_interrupt()
{
  uint16  rik_event = REG_RIK_STATUS;
  //====== ИЗМЕНЕНИЯ В РИК1: ==================
  if(rik_event & MASK_RIK_1_INSERT_CHANGE)
  {
    REG_RIK_RESET_STATUS = CMD_RST_RIK_1_CHANGE;
    //РИК1 ПОДКЛЮЧЕНА:
    if(rik_event & MASK_RIK_1_INSERT)
      rik_power(POWER_ON, 0);
    //РИК1 ОТКЛЮЧЕНА:
    else
      rik_power(POWER_OFF, 0);    
  }
  //====== ИЗМЕНЕНИЯ В РИК2: ==================
  if(rik_event & MASK_RIK_2_INSERT_CHANGE)
  {
    REG_RIK_RESET_STATUS = CMD_RST_RIK_2_CHANGE;
    //РИК2 ПОДКЛЮЧЕНА:
    if(rik_event & MASK_RIK_2_INSERT)
      rik_power(POWER_ON, 1);
    //РИК2 ОТКЛЮЧЕНА:
    else
      rik_power(POWER_OFF, 1);
  }
  //====== ИЗМЕНЕНИЯ В КРЫШКИ РИК: ============
  if(rik_event & MASK_RIK_DOOR_CHANGE)
  {
    REG_RIK_RESET_STATUS = CMD_RST_RIK_DOOR_CHANGE;
    //КРЫШКА РИК ОТКРЫТА:
    if(rik_event & MASK_RIK_DOOR_OPEN)
      asm(" nop");
    //КРЫШКА РИК ЗАКРЫТА:
    else
      asm(" nop");
  }
  if(user_rik_int_call_function != NULL)
    user_rik_int_call_function(rik_event&(~0x1));
}
/**************************************************************************************************\
*   Инициализация РИК
\***sss********************************************************************************************/
int32 rik_init(s_os_driver_context* ctx)
{
  int32               error;
  uint32              file = RES_VOID;
  s_gpio_interrupt    rik_gpio;
  s_drv_rik_plug_arg* arg = (s_drv_rik_plug_arg*)ctx->data;
  int32               complete_stage = 0;

  //*** STAGE1 ***
  sem_rik = sem_alloc(1,NULL);
  if(sem_rik == RES_VOID)
  {
    error = OSE_CANT_CREATE_SEM;
    goto m_return;
  }
  complete_stage++;

  //*** STAGE2 ***  
  file = drv_mkd("/dev/gpio");
  if(file == RES_VOID)
  {
    error = OSE_NOT_INITIALIZED;
    goto m_return;
  }
  complete_stage++;

  //*** STAGE3 ***  
  rik_gpio.number_gpio = arg->num_gpio_int;
  rik_gpio.call_functoin = &rik_interrupt; 
  error = drv_ioctl(file, GPIO_INT_ALLOC, &rik_gpio);
  if(error != OSE_OK)
  {
    goto m_return;
  }
  complete_stage++; 

  //*** STAGE4 ***
  error = rik_redirect_init(arg->redirect);
  if(error != OSE_OK)
  {
    goto m_return;
  }
  complete_stage++; 

  //*** STAGE5 ***
  REG_RIK_RESET_STATUS = CMD_RST_RIK_DOOR_CHANGE|CMD_RST_RIK_2_CHANGE|CMD_RST_RIK_1_CHANGE|CMD_RST_RIK_TRANSFER_COMPLETE;
  complete_stage++;

  m_return:
  switch(complete_stage)
  {
    case  4: 
    case  3: drv_ioctl(file, GPIO_INT_FREE, &rik_gpio);
    case  2: drv_rmd(file);
    case  1: sem_free(sem_rik);
    default: break;
  }
  return error;
}
/**************************************************************************************************\
*   Денициализация РИК
\***sss********************************************************************************************/
int32 rik_deinit(s_os_driver_context* ctx)
{
  int32               error;
  s_gpio_interrupt    rik_gpio;
  s_drv_rik_plug_arg* arg = (s_drv_rik_plug_arg*)ctx->data;    
  sem_free(sem_rik);

  rik_gpio.number_gpio = arg->num_gpio_int;
  rik_gpio.call_functoin = &rik_interrupt;
  uint32 file = drv_mkd("/dev/gpio");
  error = drv_ioctl(file,GPIO_INT_FREE,&rik_gpio);
  drv_rmd(file);
  rik_redirect_deinit();
  return error;
}
/**************************************************************************************************\
*   Инициализация редиректора
\***sss********************************************************************************************/
int32 rik_redirect_init(uint8 redirect)
{
  if(redirect == 0) return OSE_OK;
  s_prc_attr  prc_attr;
  gb_exit_rik_prc_redirect = 0;
  memset(&prc_attr, 0x0, sizeof(prc_attr));
  prc_attr.stack = 2048;
  pid_redirect_prc = prc_create(&rik_prc_redirect, NULL, 0x0, &prc_attr);
  if(pid_redirect_prc > 0) return OSE_OK;
  else return OSE_CANT_CREATE_PROCESS;
}
/**************************************************************************************************\
*   Деинициализация редиректора
\***sss********************************************************************************************/
int32 rik_redirect_deinit()
{
  if(pid_redirect_prc > 0)
  {
    gb_exit_rik_prc_redirect = 1;
    prc_join(pid_redirect_prc);   
    return OSE_OK;     
  }
  else return OSE_NO_PROCESS;
}
/**************************************************************************************************\
*  Переключение состояния
\***sss********************************************************************************************/
static bool switch_mstate(s_msg_cmd* msg_cmd, uint32* msg_from)
{
  register int32  error;
  s_message*      msg_desc;
  error = msg_recv( &msg_desc, SEM_INFINITY );
  if( (error == OSE_OK)&&(msg_desc != NULL) )
  {
    if(msg_desc->length == sizeof(s_msg_cmd))
    {
      *msg_from = msg_desc->from;
      memcpy(msg_cmd, msg_desc->data, sizeof(s_msg_cmd));
      msg_free(msg_desc);
      return true;
    }
    else
    {
      msg_free(msg_desc);
      return false;
    }
  }
  else return false;
}
/**************************************************************************************************\
*  Прием данных
\***sss********************************************************************************************/
static int32 msg_recv_data(void* data, int32 length, uint32 ms)
{
  register int32    error;
  s_message*        msg_desc;

  error = msg_recv( &msg_desc, ms);
  if( (error == OSE_OK)&&(msg_desc != NULL) )
  {
    if(msg_desc->length == length) memcpy(data, msg_desc->data, length);
    else error = OSE_DIFFERENT_LENGTH;
    msg_free(msg_desc);
  }
  return error;
}
/**************************************************************************************************\
*   Процесс редиректора
\***sss********************************************************************************************/
int rik_prc_redirect(void* arg)
{
  uint32       msg_from;
  s_msg_cmd    msg_cmd;
  int32        error;
  error = msg_open("drv_rik_redirector");
  if(error != OSE_OK)
  {
    while(gb_exit_rik_prc_redirect == 1);
    return error;
  }
  while(true)
  {
    if( switch_mstate(&msg_cmd, &msg_from) == false) continue;
    switch (msg_cmd.cmd)
    {
      //---------------------------------------------------      
      case MSG_RIK_WRITE:
      {
        s_msg_akn_rw  res;
        uint32        length;
        uint8*        buf;
        res.len = 0x0;
        res.akn = msg_recv_data(&length, sizeof(uint32), SEM_INFINITY);
        if(res.akn == OSE_OK)
        {
          buf = (uint8*)heap_alloc(NULL, length, HEAP_ALIGN_4);        
          if(buf != NULL)
          {
            res.akn = msg_recv_data(buf, length, SEM_INFINITY);        
            if(res.akn == OSE_OK)            
              res.len = rik_swrite(&msg_cmd.rikdata, buf, length);
          }
          else res.akn = OSE_NO_MEMORY;
        }
        res.rw_cmd_left = msg_cmd.rikdata.rw_cmd_left;
        msg_send(msg_from, &res, sizeof(s_msg_akn_rw));
        if(buf != NULL) heap_free(NULL, buf);
      }
      break;
      //---------------------------------------------------      
      case MSG_RIK_READ:
      {
        s_msg_akn_rw  res;
        uint32        length;
        uint8*        buf = NULL;
        res.len = 0x0;
        res.akn = msg_recv_data(&length, sizeof(uint32), SEM_INFINITY);
        if(res.akn == OSE_OK)
        {
          buf = (uint8*)heap_alloc(NULL, length, HEAP_ALIGN_4);
          if(buf != NULL)
          {
            res.len = rik_sread(&msg_cmd.rikdata, buf, length);
          }
          else res.akn = OSE_NO_MEMORY;
        }
        res.rw_cmd_left = msg_cmd.rikdata.rw_cmd_left;
        msg_send(msg_from, &res, sizeof(s_msg_akn_rw));
        if( (res.akn == OSE_OK)&&(res.len!=0x0) )
          msg_send(msg_from, buf, res.len);
        if(buf != NULL) heap_free(NULL, buf);
      }
      break;
      //---------------------------------------------------      
      case MSG_RIK_GET_RESET_STRUCT:
      {
        s_msg_akn_reset res;
        res.akn = rik_reset(&msg_cmd.rikdata);
        if(res.akn == OSE_OK)
        { 
          memcpy((uint8*)&res.reset, &msg_cmd.rikdata.card_data, sizeof(s_rik_reset));
          res.rw_cmd_left = msg_cmd.rikdata.rw_cmd_left;
        }
        msg_send(msg_from, &res, sizeof(s_msg_akn_reset));
      }
      break;      
      //---------------------------------------------------      
      case MSG_RIK_VERIFY_PASSWORD:
      {
        s_msg_akn           res;
        s_msg_password      msg_psw;
        s_rik_password_arg  pas_struct;
        res.akn = msg_recv_data(&msg_psw, sizeof(s_msg_password), SEM_INFINITY);        
        if(res.akn == OSE_OK)
        {
          pas_struct.n_pwd = msg_psw.n_pwd;
          pas_struct.pwd = msg_psw.pwd;
          res.akn = rik_verify_password(&pas_struct, &msg_cmd.rikdata);
          res.rw_cmd_left = msg_cmd.rikdata.rw_cmd_left;
        }
        msg_send(msg_from, &res, sizeof(s_msg_akn));
      }
      break;      
      //---------------------------------------------------      
      case MSG_RIK_CHANGE_PASSWORD:
      {
        s_msg_akn  res;
        uint8      buf[8];
        res.akn = msg_recv_data(buf, sizeof(buf), SEM_INFINITY);
        if(res.akn == OSE_OK)
          res.akn = rik_change_password(buf, &msg_cmd.rikdata);
        res.rw_cmd_left = msg_cmd.rikdata.rw_cmd_left;
        msg_send(msg_from, &res, sizeof(s_msg_akn));
      }
      break;      
      //---------------------------------------------------      
      case MSG_RIK_UNLOCK_CARD:
      {
        s_msg_akn  res;
        uint8      n_pwd;
        res.akn = msg_recv_data(&n_pwd, sizeof(uint8), SEM_INFINITY);
        if(res.akn == OSE_OK)
          res.akn = rik_unlock(&n_pwd, &msg_cmd.rikdata);
        res.rw_cmd_left = msg_cmd.rikdata.rw_cmd_left;
        msg_send(msg_from, &res, sizeof(s_msg_akn));
      }
      break;      
      //---------------------------------------------------
      case MSG_RIK_CHECK_DOOR:
      {
        s_msg_akn res;
        res.akn = rik_open_door();
        res.rw_cmd_left = msg_cmd.rikdata.rw_cmd_left;
        msg_send(msg_from, &res, sizeof(s_msg_akn));
      }
      break;
      //---------------------------------------------------
      case MSG_RIK_CHECK:
      {
        s_msg_akn res;
        res.akn = rik_check(&msg_cmd.rikdata);
        res.rw_cmd_left = msg_cmd.rikdata.rw_cmd_left;
        msg_send(msg_from, &res, sizeof(s_msg_akn));
      }
      break;      
      //---------------------------------------------------
      case MSG_RIK_EXIT:
      {
        return OSE_OK;
      }      
    }
  }  
}
/**************************************************************************************************\
*   Питание РИК
\***sss********************************************************************************************/
int32 rik_power(uint32 PowerCondition, uint32 n_reader)
{
  switch (PowerCondition)
  {
    case POWER_ON:
    {
      switch(n_reader)
      {
        case 0: REG_RIK_POWER = CMD_RIK_1_POWER_ON; break;
        case 1: REG_RIK_POWER = CMD_RIK_2_POWER_ON; break;
      }       
    }
    break;
    case POWER_OFF:
    {
      switch(n_reader)
      {
        case 0: REG_RIK_POWER = CMD_RIK_1_POWER_OFF; break;
        case 1: REG_RIK_POWER = CMD_RIK_2_POWER_OFF; break;
      }       
    }
    break;
  }
  return OSE_OK;
}
/**************************************************************************************************\
*   Проверка наличия РИК
\***sss********************************************************************************************/
int32  rik_check(s_drv_rik_var* rikdata)
{
  uint16 CheckStatus;
  switch(rikdata->select_reader)
  {
    case 0: CheckStatus = REG_RIK_STATUS & MASK_RIK_1_INSERT; break;
    case 1: CheckStatus = REG_RIK_STATUS & MASK_RIK_2_INSERT; break;
  }
  if(CheckStatus) return rik_open_door();
  else return RIK_ER_NO_CARD;
}
/**************************************************************************************************\
*   Сброс РИК
\***sss********************************************************************************************/
int32 rik_reset(s_drv_rik_var* rikdata)
{
  sem_lock(sem_rik,SEM_INFINITY);
  int32    error;
  uint16   pReturnErrorLeft = 3;
  volatile uint16   i = 4;
  volatile uint16* BufPrmPrdRIK = &REG_RIK_BUFPRMPRD;
  REG_RIK_SELECT = rikdata->select_reader;
  do{
    if (error = rik_check(rikdata)) break;
    REG_RIK_RESET_STATUS = CMD_RST_RIK_TRANSFER_COMPLETE;
    REG_RIK_RESET = CMD_RIK_RESET;
    if(error = rik_ready()) break;
    if(!(--pReturnErrorLeft))
    {
      error = RIK_ER_NO_ANSWER;     
      break;
    }
  }while(!(BufPrmPrdRIK[0] == 0x3B && BufPrmPrdRIK[1] == 0x6E));
  
  if(!error)
  {
    rikdata->card_data.year      = (BufPrmPrdRIK[i]<<0x8) | (BufPrmPrdRIK[i+1]); i += 2;
    rikdata->card_data.code1     = (BufPrmPrdRIK[i]<<0x8) | (BufPrmPrdRIK[i+1]); i += 2;
    rikdata->card_data.code2     = (BufPrmPrdRIK[i]<<0x8) | (BufPrmPrdRIK[i+1]); i += 2;
    rikdata->card_data.serial[0] = (BufPrmPrdRIK[i]<<0x8) | (BufPrmPrdRIK[i+1]); i += 2;
    rikdata->card_data.serial[1] = (BufPrmPrdRIK[i]<<0x8) | (BufPrmPrdRIK[i+1]); i += 2;
    rikdata->card_data.type      = (BufPrmPrdRIK[i]<<0x8) | (BufPrmPrdRIK[i+1]); i += 2;
    rikdata->card_data.status    = (BufPrmPrdRIK[i]<<0x8) | (BufPrmPrdRIK[i+1]); 
    rikdata->rw_cmd_left         = RIK_WRITE_CMD_MAX_RETRY;
  }
  sem_unlock(sem_rik);
  return error;
}
/**************************************************************************************************\
*                   Запись данных в РИК
*--------------------------------------------------------------------------------------------------
* uint32 RikWrite(void* buf,uint16 n_zone, uint16 offset,uint16 len);
* Где:  buf    - адр. данных, 
*       n_zone - номер зоны,
*       offset - смещение, 
*       lenb   - длина в байтах
\***sss********************************************************************************************/
int32 rik_swrite(s_drv_rik_var* rikdata, uint8* WriteBUF, uint32 length)
{
  sem_lock(sem_rik,SEM_INFINITY);
  volatile uint16* BufPrmPrdRIK     = &REG_RIK_BUFPRMPRD;
  volatile uint16* BufPrmPrdDataRIK = &REG_RIK_BUFPRMPRD + RIK_WRITE_CMD_LEN;
  uint16   pTotalLengthLeft, pLength, Nout, Nin;

  pTotalLengthLeft = length;//Задаем длину
  Nin = 0;

  REG_RIK_SELECT = rikdata->select_reader;
  while(pTotalLengthLeft)
  {
    //Проверка лимита записи:
    if(rik_limit_rw(rikdata)) break;
    //Проверка крышки и наличие РИК:
    if (rik_check(rikdata)) break;
  
    //Анализ длины передаваемого буфера:
    if(pTotalLengthLeft > C_MAX_BLOCK_LENGTH)
      pLength = C_MAX_BLOCK_LENGTH;
    else
      pLength = pTotalLengthLeft;
        
    //Подготовка 5 байт команды:
    BufPrmPrdRIK[0] = 0x90;
    BufPrmPrdRIK[1] = 0xD6;
    BufPrmPrdRIK[2] = (rikdata->zone<<4)|(rikdata->offset>>8);
    BufPrmPrdRIK[3] = rikdata->offset & 0xFF;
    BufPrmPrdRIK[4] = pLength;
  
    //Подготовка передаваемого буфера:
    Nout = 0;
    for(uint16 i=0; i<pLength; i++)
      BufPrmPrdDataRIK[Nout++] = WriteBUF[Nin++] & 0xFF;
  
    //Запись передаваемого буфера:
    REG_RIK_RESET_STATUS = CMD_RST_RIK_TRANSFER_COMPLETE;
    REG_RIK_PRD_DATA = CMD_RIK_TRANSFER_START;
    if(rik_ready()) break;
    if(rik_analysis_error(pLength, rikdata)) break;
  
    rikdata->offset += pLength;
    pTotalLengthLeft -= pLength;
  }
  sem_unlock(sem_rik);
  return length - pTotalLengthLeft;
}
/**************************************************************************************************\
*                   Чтение данных из РИК
*------------------------------------------------------------------------------
*uint16   RikRead(void* buf,uint16 n_zone, uint16 offset,uint16 len);
* Где:  A4 = buf    - адр. данных, 
*       B4 = n_zone - номер зоны,
*       A6 = offset - смещение, 
*       B6 = lenb   - длина в байтах
\***sss********************************************************************************************/
int32 rik_sread( s_drv_rik_var* rikdata, uint8* ReadBUF, uint32 length)
{
  sem_lock(sem_rik,SEM_INFINITY);
  volatile uint16* BufPrmPrdRIK     = &REG_RIK_BUFPRMPRD;
  volatile uint16* BufPrmPrdDataRIK = &REG_RIK_BUFPRMPRD + RIK_WRITE_CMD_LEN;
  uint16  pTotalLengthLeft, pLength, Nout, Nin;
  
  pTotalLengthLeft = length;//Задаем длину
  Nin = 0;
  
  REG_RIK_SELECT = rikdata->select_reader;
  while(pTotalLengthLeft)
  {
    //Проверка лимита чтения:
    if(rik_limit_rw(rikdata)) break;
    //Проверка крышки РИК:
    if (rik_check(rikdata)) break;
  
    //============================================
    //Анализ длины передаваемого буфера:
    if(pTotalLengthLeft > C_MAX_BLOCK_LENGTH)
      pLength = C_MAX_BLOCK_LENGTH;
    else
      pLength = pTotalLengthLeft;
        
    //Подготовка 5 байт команды:
    BufPrmPrdRIK[0] = 0x90;
    BufPrmPrdRIK[1] = 0xB0;
    BufPrmPrdRIK[2] = (rikdata->zone<<4)|(rikdata->offset>>8);
    BufPrmPrdRIK[3] = rikdata->offset & 0xFF;
    BufPrmPrdRIK[4] = pLength;
  
    //Подготовка передаваемого буфера 0xAA:
    Nout = 0;
    for(uint16 i=0; i<(pLength); i++)
      BufPrmPrdDataRIK[Nout++] = 0xAA;
  
    //Запись передаваемого буфера:
    REG_RIK_RESET_STATUS = CMD_RST_RIK_TRANSFER_COMPLETE;
    REG_RIK_PRD_DATA = CMD_RIK_TRANSFER_START;
    if(rik_ready()) break;
    if(rik_analysis_error(pLength, rikdata)) break;
    
    //============================================
    //Подготовка 5 байт команды:
    BufPrmPrdRIK[0] = 0x00;
    BufPrmPrdRIK[1] = 0xC0;
    BufPrmPrdRIK[2] = 0x00;
    BufPrmPrdRIK[3] = 0x00;
    BufPrmPrdRIK[4] = pLength;
  
    //Чтение буфера:
    REG_RIK_RESET_STATUS = CMD_RST_RIK_TRANSFER_COMPLETE;
    REG_RIK_PRM_DATA = CMD_RIK_TRANSFER_START;
    if(rik_ready()) break;
    if(rik_analysis_error(pLength, rikdata)) break;
  
    //Чтение принятых данных в буфер:
    Nout = 0;
    for(uint16 i=0; i<(pLength); i++)
      ReadBUF[Nin++]  = (BufPrmPrdRIK[Nout++] & 0xFF);
  
    rikdata->offset += pLength;
    pTotalLengthLeft -= pLength;
  }
  sem_unlock(sem_rik);
  return length - pTotalLengthLeft;
}
/**************************************************************************************************\
*                   Предъявление пароля РИК
*--------------------------------------------------------------------------------------------------
*uint16     RikVerifyPassword(uint16 n_pwd,void* buf);
* Где:  n_pwd - номер файла ключей,  
*       *buf  - указатель на пароль (8 байт)
\***sss********************************************************************************************/
int32   rik_verify_password(s_rik_password_arg*  pas_struct, s_drv_rik_var* rikdata)
{
  sem_lock(sem_rik,SEM_INFINITY);
  volatile uint16* BufPrmPrdRIK     = &REG_RIK_BUFPRMPRD;
  volatile uint16* BufPrmPrdDataRIK = &REG_RIK_BUFPRMPRD + RIK_WRITE_CMD_LEN;
  uint8*  WriteBUF = (uint8*) pas_struct->pwd;   
  uint16  pLength  = 0x08;
  uint16  Error, Nout, Nin;
  
  //Проверка лимита записи:
  if(Error = rik_limit_rw(rikdata))
    goto mReturn;
  //Проверка крышки РИК:
  if (Error = rik_check(rikdata))  
    goto mReturn;
  
  //Подготовка 5 байт команды:
  BufPrmPrdRIK[0] = 0x00;
  BufPrmPrdRIK[1] = 0x22;
  BufPrmPrdRIK[2] = 0x00;
  BufPrmPrdRIK[3] = (pas_struct->n_pwd)&0xFF;
  BufPrmPrdRIK[4] = pLength;
  
  //Подготовка передаваемого буфера:
  Nout = 0;
  Nin  = 0;
  for(uint16 i=0; i<pLength; i++)
    BufPrmPrdDataRIK[Nout++] = WriteBUF[Nin++] & 0xFF;
  
  //Запись передаваемого буфера:
  REG_RIK_RESET_STATUS = CMD_RST_RIK_TRANSFER_COMPLETE;
  REG_RIK_PRD_DATA = CMD_RIK_TRANSFER_START;
  if(Error = rik_ready())
    goto mReturn;
  Error = rik_analysis_error(pLength, rikdata);
  mReturn:
  sem_unlock(sem_rik);
  return Error;
}
/**************************************************************************************************\
*                   Смена пароля РИК
*------------------------------------------------------------------------------
*uint16     RikChangePwd(uint16 n_pwd,void* buf);
* Где   n_pwd - номер файла ключей - НЕИСПОЛЬЗУЕТСЯ,  
*       *buf  - указатель на пароль (8 байт)
\***sss********************************************************************************************/
int32 rik_change_password(uint8* buf_pwd, s_drv_rik_var* rikdata)
{
  sem_lock(sem_rik,SEM_INFINITY);
  volatile uint16* BufPrmPrdRIK     = &REG_RIK_BUFPRMPRD;
  volatile uint16* BufPrmPrdDataRIK = &REG_RIK_BUFPRMPRD + RIK_WRITE_CMD_LEN;
  uint8*  WriteBUF = buf_pwd;   
  uint16  pLength  = 0x08;
  uint16  Error, Nout, Nin;
  //Проверка лимита записи:
  if(Error = rik_limit_rw(rikdata))
    goto mReturn;
  //Проверка крышки РИК:
  if(Error = rik_check(rikdata))  
    goto mReturn;

  //Подготовка 5 байт команды:
  BufPrmPrdRIK[0] = 0x00;
  BufPrmPrdRIK[1] = 0xDC;
  BufPrmPrdRIK[2] = 0x00;
  BufPrmPrdRIK[3] = 0x00;
  BufPrmPrdRIK[4] = pLength;

  //Подготовка передаваемого буфера:
  Nout = 0;
  Nin  = 0;
  for(uint16 i=0; i<pLength; i++)
    BufPrmPrdDataRIK[Nout++] = WriteBUF[Nin++] & 0xFF;

  //Запись передаваемого буфера:
  REG_RIK_RESET_STATUS = CMD_RST_RIK_TRANSFER_COMPLETE;
  REG_RIK_PRD_DATA = CMD_RIK_TRANSFER_START;
  if(Error = rik_ready())
    goto mReturn;
  Error = rik_analysis_error(pLength, rikdata);
  mReturn:
  sem_unlock(sem_rik);
  return Error;
}
/**************************************************************************************************\
*                   Разблокировать РИК
\***sss********************************************************************************************/
int32 rik_unlock(uint8* n_pwd, s_drv_rik_var* rikdata)
{
  sem_lock(sem_rik,SEM_INFINITY);
  volatile uint16* BufPrmPrdRIK     = &REG_RIK_BUFPRMPRD;
  uint16  Error;

  //Проверка лимита записи:
  if(Error = rik_limit_rw(rikdata))
    goto mReturn;
  //Проверка крышки РИК:
  if (Error = rik_check(rikdata))  
    goto mReturn;

  //Подготовка 5 байт команды:
  BufPrmPrdRIK[0] = 0x90;
  BufPrmPrdRIK[1] = 0x46;
  BufPrmPrdRIK[2] = 0x00;
  BufPrmPrdRIK[3] = (*n_pwd)&0xFF;
  BufPrmPrdRIK[4] = 0x00;

  //Запись передаваемого буфера:
  REG_RIK_RESET_STATUS = CMD_RST_RIK_TRANSFER_COMPLETE;
  REG_RIK_PRD_DATA = CMD_RIK_TRANSFER_START;
  if(Error = rik_ready())
    goto mReturn;
  Error = rik_analysis_error(0, rikdata);
  mReturn:
  sem_unlock(sem_rik);
  return Error;
}

/**************************************************************************************************\
*   Анализ открытия крышки РИК
\***sss********************************************************************************************/
int32  rik_open_door()
{
  uint16 DoorOpen = REG_RIK_STATUS & MASK_RIK_DOOR_OPEN;
  if (DoorOpen) return RIK_ER_NOT_CLOSE_DOOR;
  return OSE_OK;
}
/**************************************************************************************************\
*   Получение последней ошибки РИК
\***sss********************************************************************************************/
int32 rik_to_os_error(uint16 Error, uint16 iByteLentg)
{
  //Хорошая команда 9000:
  if(Error == C_OK_CMD_9000)
    return OSE_OK;
  //Хорошая команда 61ХХ:
  else if(Error == (C_OK_CMD_61XX | iByteLentg))
    return OSE_OK;
  //Ошибка 6982, карточка заблокированна:
  else if(Error == C_ERR_CARD_LOCK)
    return RIK_ER_BLOCK_CARD;
  //Ошибка 63CX, неверный пароль:
  else if((Error & (~0xF)) == C_ERR_PASSWORD)
    return RIK_ER_PASSWORD | (Error & 0xF);
  //Ошибка 0x0100, ошибка таймаут: 
  else if(Error == C_ERR_TIME_OUT)
    return RIK_ER_TIMEOUT;
  //Ошибка 0x0200, ошибка четности:
  else if(Error == C_ERR_EVEN_PARITY)
    return RIK_ER_PARITY;
  //Ошибка 0x0300, ошибка при передачи: 
  else if(Error == C_ERR_PRD)
    return RIK_ER_DATA;
  //Ошибка неустановленна:
  else
    return RIK_ER_UNKNOWN;  
}
/**************************************************************************************************\
*   Получение последней ошибки РИК
\***sss********************************************************************************************/
int32 rik_last_errno(int32* errno, s_drv_rik_var* rikdata)
{
  *errno = rik_to_os_error(rikdata->error.code, rikdata->error.length);
  return OSE_OK;
}
/**************************************************************************************************\
*   Анализ ошибок РИК
\***sss********************************************************************************************/
int32 rik_analysis_error(uint16 iByteLentg, s_drv_rik_var* rikdata)
{
  uint16 Error = REG_RIK_ERROR;
  rikdata->error.code = Error;
  rikdata->error.length = iByteLentg;
  return rik_to_os_error(Error, iByteLentg);
}
/**************************************************************************************************\
*   Анализ лимита команд на запись
\***sss********************************************************************************************/
int32 rik_limit_rw(s_drv_rik_var* rikdata)
{
  uint16  pRikError, pReturnErrorLeft;
  volatile uint16* BufPrmPrdRIK;

  if(!rikdata->rw_cmd_left)
  {
    pReturnErrorLeft = 3;
    BufPrmPrdRIK = &REG_RIK_BUFPRMPRD;
    REG_RIK_SELECT = rikdata->select_reader;
    do{
      REG_RIK_RESET_STATUS = CMD_RST_RIK_TRANSFER_COMPLETE;
      REG_RIK_RESET = CMD_RIK_RESET;
      if(pRikError = rik_ready())
        return  pRikError;
      if(!(--pReturnErrorLeft))
        return  RIK_ER_NO_ANSWER;     
    }while(!(BufPrmPrdRIK[0] == 0x3B && BufPrmPrdRIK[1] == 0x6E));
    rikdata->rw_cmd_left = RIK_WRITE_CMD_MAX_RETRY;
  }
  else rikdata->rw_cmd_left--;        
  return OSE_OK;  
}
/**************************************************************************************************\
*   Ожидание готовности РИК
\***sss********************************************************************************************/
int32 rik_ready()
{
  uint64 limit_time = time_core()+5000;
  uint32 time_out = 0;

  while(((REG_RIK_STATUS & MASK_RIK_TRANSFER_COMPLETE)==0) && (time_out==0))
  {
    prc_yield();
    if(time_core()>=limit_time)
      time_out = 1;
  }
  if(!time_out) return OSE_OK;
  else return RIK_ER_TIMEOUT;
}

