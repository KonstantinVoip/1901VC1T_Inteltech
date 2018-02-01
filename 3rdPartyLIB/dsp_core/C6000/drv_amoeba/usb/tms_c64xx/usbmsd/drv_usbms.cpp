//**************************************************************************************************
//                         Copyright (C) 2009 RCZI
//--------------------------------------------------------------------------------------------------
// FILENAME....... drv_usbms.cpp
// DATE CREATED... 10/12/2009
// LAST MODIFIED.. 15/02/2010
// DRIVER VERSION. 1.1
//--------------------------------------------------------------------------------------------------
//                        Mass Storage Class Driver
//-------------------------------------------------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
//
// !: codepage: cp1251 
//
// !: d: Драйвер USB Mass Storage Device Class.<br>
// !: -:
// !: md: Драйвер USB флеш работает в составе операционной системы "ОС". 
// !: md: Он реализует обмен на уровне интерфейсного протокола 
// !: md: "Bulk-Only Transport" для устройств, класса "Mass Storage Class", 
// !: md: поддерживающих командные блоки стандарта "SCSI transparent command".<br> 
// !: md: Для каждого логического устройства USB флеш в ОС добавляется отдельный 
// !: md: драйвер. Путь к логическому устройству:"/dev/sdAuL" , где:<br> 
// !: md: - A - адрес физического устройства на шине от 1 до 127;<br>
// !: md: - L - номер логической устройства (LUN) от 0 до N.<br>
// !: md: Драйвер реализует стандартный интерфейс взаимодействия пользователя 
// !: md: с устройством по средствам потокового чтения/записи в устройство (файл) 
// !: md: и функции управляющих воздействий на устройство.
//***sss********************************************************************************************
#include    <rts.h>
#include    <drv_usbms.h>
#include    <scsi.h>
#ifdef CONSOLE_DEBUG
#  include  <drv_dbgout.h>
#endif
//-------------------------------------------------------------------------------------------------
//#define NEED_MSD_SYS_LOG

//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//
//          Интерфейсные функции драйвера
//
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
int32 lg_usbms_open(s_os_driver_descriptor* d);
int32 lg_usbms_close(s_os_driver_descriptor* d);
int32 lg_usbms_stream_write(s_os_driver_descriptor* d, void* data, int32 length);
int32 lg_usbms_stream_read(s_os_driver_descriptor* d, void* data, int32 length);
int32 lg_usbms_init_driver(s_os_driver_context* ctx);
int32 lg_usbms_deinit_driver(s_os_driver_context* ctx);
int32 lg_usbms_seek(s_os_driver_descriptor* d, int64* seek);
int32 lg_usbms_size(s_os_driver_descriptor* d, int64* steam_size);
int32 lg_usbms_eof(s_os_driver_descriptor* d, int32* vreturn);
int32 lg_usbms_position(s_os_driver_descriptor* d, int64* vreturn);

int32 lg_usbms_write(s_os_driver_descriptor* d, s_msd_io* iodata);
int32 lg_usbms_read(s_os_driver_descriptor* d, s_msd_io* iodata);
int32 lg_usbms_capacity(s_os_driver_descriptor* d, s_msd_capacity* capacity);
int32 lg_usbms_vendor(s_os_driver_descriptor* d, s_msd_vendor* capacity);
int32 lg_usbms_device_name(s_os_driver_descriptor* d, char* *str);
int32 lg_usbms_check_media_change(s_os_driver_descriptor* d, uint32* var);
int32 lg_usbms_clear_media_change(s_os_driver_descriptor* d);
//**************************************************************************************************
//       Открытие потока
//-------------------------------------------------------------------------------------------------
// !: fn: int32 usbms_open(s_os_driver_descriptor* d, uint16 access)
//
// !: d: Функция открывает поток в соответствии со спецификатором доступа: 
// !: d: на чтение (DRV_RD), на запись (DRV_WR) или совместно на чтение-запись. 
// !: -:
//***sss********************************************************************************************
int32 usbms_open(s_os_driver_descriptor* d, uint16 access)
{
  int32 error;
  error = lg_usbms_open(d);
  if(error) return error;

  switch (access & (DRV_WR | DRV_RD))
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
  return OSE_OK;
}
//**************************************************************************************************
//       Закрытие потока
//-------------------------------------------------------------------------------------------------
// !: fn: int32 usbms_close(s_os_driver_descriptor* d)
//
// !: d: Функция drv_close закрывает открытый поток.
// !: -:
//***sss********************************************************************************************
int32 usbms_close(s_os_driver_descriptor* d)
{
  if(d->access & DRV_OPENED){
    lg_usbms_close(d);
    d->access = 0;
    return  OSE_OK;
  }
  return OSE_STREAM_NOT_OPENED;
}
//**************************************************************************************************
//       Чтение из потока
//-------------------------------------------------------------------------------------------------
// !: fn: int32 usbms_read(s_os_driver_descriptor* d, void* buf, int32 length)
//
// !: d: Функция осуществляет не блокирующее потоковое чтение из устройства.
// !: -:
//***sss********************************************************************************************
int32 usbms_read(s_os_driver_descriptor* d, void* buf, int32 length)
{
  if(d->access == DRV_RD | DRV_OPENED)
  {
    if(length < 0) return OSE_BAD_PARAM;
    return lg_usbms_stream_read(d, (void*)buf, length);
  }
  return OSE_PERMISSION_DENIED;
}
//**************************************************************************************************
//       Запись в поток
//-------------------------------------------------------------------------------------------------
// !: fn: int32 usbms_write(s_os_driver_descriptor* d, const void* buf, int32 length)
//
// !: d: Функция осуществляет не блокирующую потоковую запись в устройство.
// !: -:
//***sss********************************************************************************************
int32 usbms_write(s_os_driver_descriptor* d, const void* buf, int32 length)
{
  if(d->access == DRV_WR | DRV_OPENED)
  {
    if(length < 0) return OSE_BAD_PARAM;
    return lg_usbms_stream_write(d, (void*)buf, length);
  }
  return OSE_PERMISSION_DENIED;
}
//**************************************************************************************************
//       Управление вводом/выводом
//-------------------------------------------------------------------------------------------------
// !: fn: int32 usbms_ioctl(s_os_driver_descriptor* d, int32 cmd, const void* arg)
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
// !: d:    <td colspan=2 align=center>
// !: d:    Резерв
// !: d:    </td>
// !: d:    <td align=center>
// !: d:      PHS_ST
// !: d:    </td>
// !: d:    <td align=center>
// !: d:      CMD_FLD
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
// !: d: - Стандартные коды ошибок ioctl;<br><br>
// !: d: - Аппаратные ошибки:<br>
// !: d:   - USB_ER_NAK - маска ошибки NAK;<br>
// !: d:   - USB_ER_STALL - маска ошибки STALL;<br>
// !: d:   - USB_ER_BABBLE - маска ошибки BABBLE;<br>
// !: d:   - USB_ER_PID - маска ошибки PID.<br><br>
// !: d: - Ошибки протокола "Bulk-Only Transport":<br>
// !: d:   - BOT_ER_CMD_FAILED - ошибка команды;<br>
// !: d:   - BOT_ER_PHASE_STATUS - ошибка последовательности.<br><br>
//
// !: d: Стандартные команды управления:<br>
// !: d: - IOC_INIT, IOC_DEINIT, IOC_INIT_DESCRIPTOR, IOC_DEINIT_DESCRIPTOR,
// !: d: IOC_SEEK, IOC_SIZE, IOC_EOF, IOC_POSITION, IOC_RESIZE.<br><br>
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
// !: d:   MSD_WRITE
// !: d:   </td> 
// !: d:   <td valign=top>
// !: d:   s_msd_io
// !: d:   </td> 
// !: d:   <td valign=top>
// !: d:   запись данных на USB флеш. 
// !: d:   </td>
// !: d: </tr>
//
// !: d: <tr>
// !: d:   <td valign=top>
// !: d:   MSD_READ 
// !: d:   </td> 
// !: d:   <td valign=top>
// !: d:   s_msd_io
// !: d:   </td> 
// !: d:   <td valign=top>
// !: d:   чтение данных с USB флеш.
// !: d:   </td>
// !: d: </tr>
//
// !: d: <tr>
// !: d:   <td valign=top>
// !: d:   MSD_CAPACITY 
// !: d:   </td> 
// !: d:   <td valign=top>
// !: d:   s_msd_capacity
// !: d:   </td> 
// !: d:   <td valign=top>
// !: d:   получение емкости ПЗУ USB флеш.
// !: d:   </td>
// !: d: </tr>
//
// !: d: <tr>
// !: d:   <td valign=top>
// !: d:   MSD_VENDOR
// !: d:   </td> 
// !: d:   <td valign=top>
// !: d:   s_msd_vendor
// !: d:   </td> 
// !: d:   <td valign=top>
// !: d:   получение данных о производителе USB флеш.
// !: d:   </td>
// !: d: </tr>
//
// !: d: <tr>
// !: d:   <td valign=top>
// !: d:   MSD_DEVICE_NAME
// !: d:   </td> 
// !: d:   <td valign=top>
// !: d:   char*
// !: d:   </td> 
// !: d:   <td valign=top>
// !: d:   получение имени физического устройства в среде ОС.
// !: d:   </td>
// !: d: </tr>
// !: d: </table>
//***sss********************************************************************************************
int32 usbms_ioctl(s_os_driver_descriptor* d, int32 cmd, const void* arg)
{
  switch(cmd)
  {
    //===============================================================
    //Standard control command:
    //Инициализация:
    case IOC_INIT:
      return lg_usbms_init_driver((s_os_driver_context*)arg);
    
    //Деинициализация:
    case IOC_DEINIT:
      return lg_usbms_deinit_driver((s_os_driver_context*)arg);
    
    //Инициализация данных:
    case IOC_INIT_DESCRIPTOR:
      return OSE_OK;
    
    //Деинициализация данных:
    case IOC_DEINIT_DESCRIPTOR: 
      return OSE_OK;
    
    //Установить смещение в пределах зоны:
    case IOC_SEEK:  
      return lg_usbms_seek(d, (int64*)arg);
    
    //Размер потока:
    case IOC_SIZE:
      return lg_usbms_size(d, (int64*)arg);
    
    //Анализ конца потока;
    case IOC_EOF:
      return  lg_usbms_eof(d, (int32*)arg);
    
    //Текущая позиция в потоке:
    case IOC_POSITION:
      return lg_usbms_position(d, (int64*)arg);
    
    //Удаление данных из потока:
    case IOC_RESIZE:
      return OSE_OK;
    
    //===============================================================
    //Driver control command:   
    case MSD_WRITE:
      return lg_usbms_write(d, (s_msd_io*)arg);

    case MSD_READ:
      return lg_usbms_read(d, (s_msd_io*)arg);

    case MSD_CAPACITY:
      return lg_usbms_capacity(d, (s_msd_capacity*)arg);

    case MSD_VENDOR:
      return lg_usbms_vendor(d, (s_msd_vendor*)arg);

    case MSD_DEVICE_NAME:
      return lg_usbms_device_name(d, (char**)arg);
      
    case MSD_CHECK_MEDIA_CHANGE:
      return lg_usbms_check_media_change(d, (uint32*)arg);
    
    case MSD_CLEAR_MEDIA_CHANGE:
      return lg_usbms_clear_media_change(d);

    default:
      return OSE_BAD_CMD;
  }
}

//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//
//          Логические функции драйвера
//
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
#define MSD_BLOCK_LENGTH                            0x200
#define POWER_OF_MSD_BLOCK_LENGTH                   9
//===== Command Block Status Values =======================
#define BOT_GOOD_STATUS                             0x00
#define BOT_COMMAND_FAILED                          0x01
#define BOT_PHASE_ERROR_STATUS                      0x02
//Command Block Wrapper:
struct s_usb_bot_cbw
{
  uint32le        cbw_signature;       
  uint32le        cbw_tag;         
  uint32le        cbw_data_transfer_length;
  uint8           cbw_flags;       
  uint8           cbw_lun;         
  uint8           cbw_cb_length;
  uint8           cbw_cb[16];
};              
//Command Status Wrapper:
struct s_usb_bot_csw
{
  uint32le        csw_signature;       
  uint32le        csw_tag;         
  uint32le        csw_data_residue;
  uint8           csw_status;      
};
//MSD info:
struct s_usb_msd_data
{
  s_usb_msd_data*         prev;
  s_usb_msd_data*         next;
  char                    name[16];
  uint32                  file_usbd;
  uint8                   unit_attention;
  uint8                   lun;
  uint8                   interface_number;
  uint8                   interface_sub_class;
  uint8                   interface_protocol;
  uint8                   in_endpoint;
  uint8*                  in_data_toggle;
  uint8                   out_endpoint;
  uint8*                  out_data_toggle;
  uint32                  media_change;
  s_msd_capacity          capacity;
  s_msd_vendor            vendor;
  s_usb_bot_cbw           cbw;
  s_usb_bot_csw           csw;
  s_scsi_sense_data       sense;
  uint32                  sem;
};
//MSD stream info:
struct s_usb_msd_stream
{
  uint64                  seek;
  void*                   scratch;
};
s_usb_msd_data*     first_msd_device = NULL;
s_usb_msd_data*     last_msd_device = NULL;
int32               prc_msd_check_media_process_exit = 0;
//-------------------------------------------------------------------------------------------------
int32               init_msd_list();
void                deinit_msd_list();
s_usb_msd_data*     create_msd();
void                add_msd(s_usb_msd_data* msd);
void                delete_msd(s_usb_msd_data* msd);
void                clear_device(s_usb_msd_data* msd);
//-------------------------------------------------------------------------------------------------
void  msd_check_media_process();
int32 msd_init(s_usb_msd_data* msd);
int32 msd_fixed_error(s_usb_msd_data* msd, int32 error);

int32 msd_write(s_usb_msd_data* msd, void* data, uint32 size, uint32 lba, uint32* size_transfer);
int32 msd_read(s_usb_msd_data* msd, void* data, uint32 size, uint32 lba, uint32* size_transfer);
int32 msd_pre_fetch(s_usb_msd_data* msd, uint32 size, uint32 lba);
int32 msd_read_capacity(s_usb_msd_data* msd, int32 lba, s_msd_capacity* capacity);
int32 msd_vendor(s_usb_msd_data* msd, s_msd_vendor* vendor);
int32 msd_start_media(s_usb_msd_data* msd);
int32 msd_stop_media(s_usb_msd_data* msd);
int32 msd_request_sense(s_usb_msd_data* msd, s_scsi_sense_data* sense, bool lock);
int32 msd_test_unit_ready(s_usb_msd_data* msd);
/**************************************************************************************************\
*   Инициализация драйвера
\***sss********************************************************************************************/
int32 lg_usbms_init_driver(s_os_driver_context* ctx)
{
  int32                       error;
  s_usb_msd_data*             msd;
  int32                       complete_stage = 0;    
  s_usb_class_driver_context* drv_ctx = (s_usb_class_driver_context*)ctx->data;
  drv_ctx->endpoint = (s_usb_endpoints*)((int8*)(&drv_ctx->endpoint)+sizeof(s_usb_endpoints*));
  //*** STAGE1 ***
  //Инициализация списка:
  error = init_msd_list();
  if(error != OSE_OK)
  {
    goto m_return;
  }
  complete_stage++;
  #ifdef MSD_MULTI_LUNS
  //Создание процесса анализа наличия карты памяти:
  if( (first_msd_device==NULL)&&(last_msd_device==NULL) )
  {
    prc_msd_check_media_process_exit = 0;
    prc_create(&msd_check_media_process,NULL,0,0,2048,0);
  }
  #endif
  //*** STAGE2 ***
  //Выделение памяти под структуру данных MSD:
  drv_ctx->data = (s_usb_msd_data*)heap_alloc(NULL, sizeof(s_usb_msd_data), HEAP_ALIGN_4);
  if(drv_ctx->data==NULL)
  {
    error = OSE_NO_MEMORY;
    goto m_return;
  }
  complete_stage++;    
  clear_device((s_usb_msd_data*)drv_ctx->data);
  //Заполнение структуры данных MSD:    
  msd = (s_usb_msd_data*)drv_ctx->data;
  //*** STAGE3 ***
  msd->file_usbd = drv_mkd(drv_ctx->path_usbd);
  if(msd->file_usbd == RES_VOID)
  {
    error = OSE_NO_DEVICE;
    goto m_return;
  }
  res_share(msd->file_usbd);
  complete_stage++;    
  //*** STAGE4 ***
  strcpy(msd->name, strchr(ctx->path, 's'));
  msd->unit_attention = 0x0;
  msd->lun = atoi(strchr(ctx->name, 'u')+0x1);
  msd->interface_number = drv_ctx->interface_number;
  msd->interface_sub_class = drv_ctx->interface_sub_class;
  msd->interface_protocol = drv_ctx->interface_protocol;
  for(int32 i=0; i<drv_ctx->number_endpoints; i++)
  {
    if(drv_ctx->endpoint[i].attributes == EP_BULK_TYPE)
    {
      if(drv_ctx->endpoint[i].endpoint_number & 0x80)
      {
        msd->in_endpoint = drv_ctx->endpoint[i].endpoint_number;
        msd->in_data_toggle = drv_ctx->endpoint[i].data_toggle;
      }
      else
      {
        msd->out_endpoint = drv_ctx->endpoint[i].endpoint_number;        
        msd->out_data_toggle = drv_ctx->endpoint[i].data_toggle;
      }
    }
  }
  if( (msd->out_data_toggle == NULL)||(msd->in_data_toggle == NULL) )
  {
    error = OSE_NO_DRIVER;
    goto m_return;
  }
  complete_stage++;    
  //*** STAGE5 ***
  msd->sem = sem_alloc(1,NULL);
  if(msd->sem == RES_VOID) 
  {
    error = OSE_CANT_CREATE_SEM;
    goto m_return;
  }
  complete_stage++; 
  //*** STAGE6 ***
  error = msd_init(msd);
  if(error) 
  {
    goto m_return;
  }
  complete_stage++; 
  //*** STAGE COMPLETE ***
  add_msd(msd);
  #ifdef CONSOLE_DEBUG
  {
    FILE* dbgout = fopen( "/dev/dbgout", "w" );
    char vendor_identification[8+4];
    char product_identification[16+3];
    char product_revision_level[4+3];
    strcpy(vendor_identification, msd->vendor.vendor_identification);
    strcat(vendor_identification, " ");
    strcpy(product_identification, msd->vendor.product_identification);
    strcat(product_identification, " ");
    strcpy(product_revision_level, msd->vendor.product_revision_level);
    strcat(product_revision_level, "\n");
    fprintf(dbgout,vendor_identification);
    fprintf(dbgout,product_identification);
    fprintf(dbgout,product_revision_level);
    #ifndef MSD_MULTI_LUNS
    fprintf(dbgout,"Носитель подключен: ёмкость %4dМБ\n", _mem8(&msd->capacity.flash_capacity)/(1024*1024));
    #endif
    fclose(dbgout);
  }
  #endif
  error = OSE_OK;
  complete_stage++;
  m_return:
  switch(complete_stage)
  {
    case  6: //msd_init//
    case  5: sem_free(msd->sem);
    case  4:
    case  3: res_unshare(msd->file_usbd);
             drv_rmd(msd->file_usbd);
    case  2: heap_free(NULL, drv_ctx->data);
    case  1: 
             #ifdef MSD_MULTI_LUNS    
             //Удаление процесса анализа наличия карты памяти:
             if( (first_msd_device==NULL)&&(last_msd_device==NULL) )
             prc_msd_check_media_process_exit = 1;   
             #endif
             deinit_msd_list();
    default: break;                
  }
  return error;
}
/**************************************************************************************************\
*   Деинициализация драйвера
\***sss********************************************************************************************/
int32 lg_usbms_deinit_driver(s_os_driver_context* ctx)
{
  s_usb_class_driver_context* drv_ctx = (s_usb_class_driver_context*)ctx->data;
  s_usb_msd_data* msd = (s_usb_msd_data*)drv_ctx->data;
  sem_free(msd->sem);
  res_unshare(msd->file_usbd);
  drv_rmd(msd->file_usbd);
  delete_msd(msd);
  heap_free(NULL, drv_ctx->data);    
  #ifdef MSD_MULTI_LUNS
  //Удаление процесса анализа наличия карты памяти:
  if( (first_msd_device==NULL)&&(last_msd_device==NULL) )
    prc_msd_check_media_process_exit = 1;
  #endif
  deinit_msd_list();
  return OSE_OK;
}
/**************************************************************************************************\
*   Открытие потокового чтения/записи
\***sss********************************************************************************************/
int32 lg_usbms_open(s_os_driver_descriptor* d)
{
  s_usb_msd_stream*   msd_strm; 
  s_usb_msd_data*     msd = (s_usb_msd_data*)( (s_usb_class_driver_context*)d->ctx->data )->data;
  d->data = heap_alloc(NULL, sizeof(s_usb_msd_stream), HEAP_ALIGN_4);
  if(d->data==NULL) return OSE_NO_MEMORY;
  msd_strm = (s_usb_msd_stream*)d->data;
  msd_strm->scratch = heap_alloc(NULL, msd->capacity.block_length, HEAP_ALIGN_4);
  if(msd_strm->scratch==NULL)
  {
    heap_free(NULL, msd_strm);
    return OSE_NO_MEMORY;
  }
  _mem8(&msd_strm->seek) = 0x0;
  return OSE_OK;
}
/**************************************************************************************************\
*   Закрытие потокового чтения/записи
\***sss********************************************************************************************/
int32 lg_usbms_close(s_os_driver_descriptor* d)
{
  s_usb_msd_stream*   msd_strm = (s_usb_msd_stream*)d->data;
  heap_free(NULL, msd_strm->scratch);
  heap_free(NULL, msd_strm);
  d->data = NULL;
  return OSE_OK;
}
/**************************************************************************************************\
*   Потоковая запись на флеш
\***sss********************************************************************************************/
int32 lg_usbms_stream_write(s_os_driver_descriptor* d, void* data, int32 length)
{
  int32   error, lba, seek_lba, size_transfer, size;
  s_usb_msd_stream*   msd_strm = (s_usb_msd_stream*)d->data;
  s_usb_msd_data*     msd = (s_usb_msd_data*)( (s_usb_class_driver_context*)d->ctx->data )->data;
  if(msd->capacity.block_length != MSD_BLOCK_LENGTH) return OSE_CANT_WRITE;
  size_transfer = 0x0;
  //Если смещение некратно размеру логического блока:
  seek_lba = _mem8(&msd_strm->seek)&(msd->capacity.block_length - 1);
  if(seek_lba != 0x0)
  {
    //Начальный логический блок:
    lba = _mem8(&msd_strm->seek)>>POWER_OF_MSD_BLOCK_LENGTH;
    //Вычитываем "неполый" блок:
    error = msd_read(msd, msd_strm->scratch, msd->capacity.block_length, lba, NULL);
    if(error) return size_transfer;
    size = (length>msd->capacity.block_length-seek_lba)?msd->capacity.block_length-seek_lba:length;
    memcpy((void*)( (uint32)msd_strm->scratch+seek_lba ),data, size);
    //Пишем неполный блок:
    error = msd_write(msd, msd_strm->scratch, msd->capacity.block_length, lba, NULL);
    if(error) return size_transfer;
    length -= size;
    data = (void*)( (uint32)data + size );
    size_transfer += size;
    _mem8(&msd_strm->seek) = _mem8(&msd_strm->seek) + size_transfer;
  }
  if(length == 0x0) return size_transfer;
  //Если смещение кратно размеру логического блока:
  seek_lba = _mem8(&msd_strm->seek)&(msd->capacity.block_length - 1);
  if(seek_lba == 0x0)
  {
    uint32 prc_size_transfer;
    //Если длинна кратна размеру логического блока:
    size = length & ~(msd->capacity.block_length - 1);
    if(size)
    {
      //Начальный логический блок:
      lba = _mem8(&msd_strm->seek)>>POWER_OF_MSD_BLOCK_LENGTH;
      //Пишем последовательность "полных" блоков:
      error = msd_write(msd, data, size, lba, (uint32*)&prc_size_transfer);
      data = (void*)( (uint32)data + prc_size_transfer );
      size_transfer += prc_size_transfer;
      _mem8(&msd_strm->seek) = _mem8(&msd_strm->seek) + prc_size_transfer;
      if(error) return size_transfer;
    }
    //Если длинна некратна размеру логического блока:
    size = length & (msd->capacity.block_length - 1);
    if(size)
    {
      //Начальный логический блок:
      lba = _mem8(&msd_strm->seek)>>POWER_OF_MSD_BLOCK_LENGTH;
      //Вычитываем "неполый" блок:
      error = msd_read(msd, msd_strm->scratch, msd->capacity.block_length, lba, NULL);
      if(error) return size_transfer;
      memcpy(msd_strm->scratch, data, size);
      //Пишем неполный блок:
      error = msd_write(msd, msd_strm->scratch, msd->capacity.block_length, lba, NULL);
      if(!error)
      {
        size_transfer += size;
        _mem8(&msd_strm->seek) = _mem8(&msd_strm->seek) + size;
      }
    }
  }
  return size_transfer;
}
/**************************************************************************************************\
*   Потокове чтение с флеш
\***sss********************************************************************************************/
int32 lg_usbms_stream_read(s_os_driver_descriptor* d, void* data, int32 length)
{
  int32   error, lba, seek_lba, size_transfer, size;
  s_usb_msd_stream*   msd_strm = (s_usb_msd_stream*)d->data;
  s_usb_msd_data*     msd = (s_usb_msd_data*)( (s_usb_class_driver_context*)d->ctx->data )->data;
  if(msd->capacity.block_length != MSD_BLOCK_LENGTH) return OSE_CANT_READ;
  size_transfer = 0x0;
  //Если смещение некратно размеру логического блока:
  seek_lba = _mem8(&msd_strm->seek)&(msd->capacity.block_length - 1);
  if(seek_lba != 0x0)
  {
    //Начальный логический блок:
    lba = _mem8(&msd_strm->seek)>>POWER_OF_MSD_BLOCK_LENGTH;
    //Вычитываем "неполый" блок:
    error = msd_read(msd, msd_strm->scratch, msd->capacity.block_length, lba, NULL);
    if(error) return size_transfer;
    size = (length>msd->capacity.block_length-seek_lba)?msd->capacity.block_length-seek_lba:length;
    memcpy(data, (void*)( (uint32)msd_strm->scratch+seek_lba ), size);
    length -= size;
    data = (void*)( (uint32)data + size );
    size_transfer += size;
    _mem8(&msd_strm->seek) = _mem8(&msd_strm->seek) + size_transfer;
  }
  if(length == 0x0) return size_transfer;
  //Если смещение кратно размеру логического блока:
  seek_lba = _mem8(&msd_strm->seek)&(msd->capacity.block_length - 1);
  if(seek_lba == 0x0)
  {
    uint32 prc_size_transfer;
    //Если длинна кратна размеру логического блока:
    size = length & ~(msd->capacity.block_length - 1);
    if(size)
    {
      //Начальный логический блок:
      lba = _mem8(&msd_strm->seek)>>POWER_OF_MSD_BLOCK_LENGTH;
      //Читаем последовательность "полных" блоков:
      error = msd_read(msd, data, size, lba, (uint32*)&prc_size_transfer);
      data = (void*)( (uint32)data + prc_size_transfer );
      size_transfer += prc_size_transfer;
      _mem8(&msd_strm->seek) = _mem8(&msd_strm->seek) + prc_size_transfer;
      if(error) return size_transfer;
    }
    //Если длинна некратна размеру логического блока:
    size = length & (msd->capacity.block_length - 1);
    if(size)
    {
      //Начальный логический блок:
      lba = _mem8(&msd_strm->seek)>>POWER_OF_MSD_BLOCK_LENGTH;
      //Вычитываем "неполый" блок:
      error = msd_read(msd, msd_strm->scratch, msd->capacity.block_length, lba, NULL);
      if(!error)
      {
        memcpy(data, msd_strm->scratch, size);
        size_transfer += size;
        _mem8(&msd_strm->seek) = _mem8(&msd_strm->seek) + size;
      }
    }
  }
  return size_transfer;
}
/**************************************************************************************************\
*   Установка смещения
\***sss********************************************************************************************/
int32 lg_usbms_seek(s_os_driver_descriptor* d, int64* seek)
{
  if(d->data == NULL) return OSE_STREAM_NOT_OPENED;
  s_usb_msd_stream*   msd_strm = (s_usb_msd_stream*)d->data;
  s_usb_msd_data*     msd = (s_usb_msd_data*)( (s_usb_class_driver_context*)d->ctx->data )->data;
  if(_mem8(seek) < _mem8(&msd->capacity.flash_capacity))
  {
    _mem8(&msd_strm->seek) = *seek;
    return OSE_OK;
  }
  return OSE_BAD_PARAM;
}
/**************************************************************************************************\
*   Размер потока
\***sss********************************************************************************************/
int32 lg_usbms_size(s_os_driver_descriptor* d, int64* steam_size)
{
  if(d->data == NULL) return OSE_STREAM_NOT_OPENED;
  s_usb_msd_data* msd = (s_usb_msd_data*)( (s_usb_class_driver_context*)d->ctx->data )->data;
  *steam_size = _mem8(&msd->capacity.flash_capacity);
  return OSE_OK;
}
/**************************************************************************************************\
*   Анализ конца потока
\***sss********************************************************************************************/
int32 lg_usbms_eof(s_os_driver_descriptor* d, int32* vreturn)
{
  if(d->data == NULL) return OSE_STREAM_NOT_OPENED;
  s_usb_msd_stream*   msd_strm = (s_usb_msd_stream*)d->data;
  s_usb_msd_data*     msd = (s_usb_msd_data*)( (s_usb_class_driver_context*)d->ctx->data )->data;
  if(_mem8(&msd_strm->seek) == _mem8(&msd->capacity.flash_capacity))
    *vreturn = 1;
  else
    *vreturn = 0;
  return OSE_OK;
}
/**************************************************************************************************\
*   Текущая позиция в потоке
\***sss********************************************************************************************/
int32 lg_usbms_position(s_os_driver_descriptor* d, int64* vreturn)
{
  if(d->data == NULL) return OSE_STREAM_NOT_OPENED;
  s_usb_msd_stream*   msd_strm = (s_usb_msd_stream*)d->data;
  *vreturn = _mem8(&msd_strm->seek);
  return OSE_OK;
}
/**************************************************************************************************\
*   Запись на флеш
\***sss********************************************************************************************/
int32 lg_usbms_write(s_os_driver_descriptor* d, s_msd_io* iodata)
{
  int32           error;
  s_usb_msd_data* msd = (s_usb_msd_data*)( (s_usb_class_driver_context*)d->ctx->data )->data;
  error = msd_write(msd, iodata->data, iodata->size*msd->capacity.block_length, iodata->lba, NULL);
  #ifdef NEED_MSD_SYS_LOG
  if(error < 0) return error;
  else if (error > 0) return MSD_ER_BASE-error;
  else return OSE_OK;
  #else
  return error;
  #endif
}
/**************************************************************************************************\
*   Чтение с флеш
\***sss********************************************************************************************/
int32 lg_usbms_read(s_os_driver_descriptor* d, s_msd_io* iodata)
{
  int32           error;
  s_usb_msd_data* msd = (s_usb_msd_data*)( (s_usb_class_driver_context*)d->ctx->data )->data;
  error = msd_read(msd, iodata->data, iodata->size*msd->capacity.block_length, iodata->lba, NULL);
  #ifdef NEED_MSD_SYS_LOG
  if(error < 0) return error;
  else if (error > 0) return MSD_ER_BASE-error;
  else return OSE_OK;
  #else
  return error;
  #endif
}
/**************************************************************************************************\
*   Емкость флеш
\***sss********************************************************************************************/
int32 lg_usbms_capacity(s_os_driver_descriptor* d, s_msd_capacity* capacity)
{
  int32                       error;
  s_usb_msd_data* msd = (s_usb_msd_data*)( (s_usb_class_driver_context*)d->ctx->data )->data;
  error = msd_read_capacity(msd, 0x0, capacity);
  #ifdef NEED_MSD_SYS_LOG
  if(error < 0) return error;
  else if (error > 0) return MSD_ER_BASE-error;
  else return OSE_OK;
  #else
  return error;
  #endif
}
/**************************************************************************************************\
*   Производитель
\***sss********************************************************************************************/
int32 lg_usbms_vendor(s_os_driver_descriptor* d, s_msd_vendor* vendor)
{
  int32 error;
  s_usb_msd_data* msd = (s_usb_msd_data*)( (s_usb_class_driver_context*)d->ctx->data )->data;
  error = msd_vendor(msd, vendor);
  #ifdef NEED_MSD_SYS_LOG
  if(error < 0) return error;
  else if (error > 0) return MSD_ER_BASE-error;
  else return OSE_OK;
  #else
  return error;
  #endif
}
/**************************************************************************************************\
*   Взять имя устройства
\***sss********************************************************************************************/
int32 lg_usbms_device_name(s_os_driver_descriptor* d, char* *str)
{
  s_usb_class_driver_context* drv_ctx = (s_usb_class_driver_context*)d->ctx->data;
  *str = drv_ctx->device_name;
  return OSE_OK;
}
/**************************************************************************************************\
*   
\***sss********************************************************************************************/
int32 lg_usbms_check_media_change(s_os_driver_descriptor* d, uint32* var)
{
  s_usb_msd_data* msd = (s_usb_msd_data*)( (s_usb_class_driver_context*)d->ctx->data )->data;
  int32 error = msd_test_unit_ready(msd);  
  *var = msd->media_change;
  return error;
}
/**************************************************************************************************\
*   
\***sss********************************************************************************************/
int32 lg_usbms_clear_media_change(s_os_driver_descriptor* d)
{
  s_usb_msd_data* msd = (s_usb_msd_data*)( (s_usb_class_driver_context*)d->ctx->data )->data;
  msd->media_change = 0;
  return OSE_OK;
}

//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//
//          Функции драйвера Mass Storage Device
//
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//===== Mass Storage Transport Protocol ===================
#define USB_MSD_CBI_COMMAND_COMPLETION_PROTOCOL     0x00
#define USB_MSD_CBI_NO_COMMAND_COMPLETION_PROTOCOL  0x01
#define USB_MSD_BULK_ONLY_PROTOCOL                  0x50
//===== Command Block Specification =======================
#define USB_MSD_RBC_COMMAND_BLOCK                   0x01
#define USB_MSD_SFF_8020_COMMAND_BLOCK              0x02
#define USB_MSD_QIC_157_COMMAND_BLOCK               0x03
#define USB_MSD_UFI_COMMAND_BLOCK                   0x04
#define USB_MSD_SFF_8070_COMMAND_BLOCK              0x05
#define USB_MSD_SCSI_COMMAND_BLOCK                  0x06
//========================================================= 
int32   bot_data_in_transport(s_usb_msd_data* msd, void* data, uint32 size);
int32   bot_data_out_transport(s_usb_msd_data* msd, void* data, uint32 size);
int32   bot_status_transport(s_usb_msd_data* msd);
/**************************************************************************************************\
*   Анализ наличия карты памяти
\***sss********************************************************************************************/
#ifdef MSD_MULTI_LUNS
void msd_check_media_process()
{
  int32               error;
  s_usb_msd_data*     msd;
  while(!prc_msd_check_media_process_exit)
  {
    msd = first_msd_device;
    //Проверка всех флешек:
    while(msd != NULL)
    {
      error = msd_test_unit_ready(msd);
      if(error == BOT_COMMAND_FAILED<<4)
      {
        error = msd_request_sense(msd, &msd->sense, true);
        if(!error)
        {
          error = (msd->sense.additional_sense_code<<8)|(msd->sense.additional_sense_code_qualifier);
          //Память отключена
          if(MEDIUM_NOT_PRESENT==error)
          {
            msd->unit_attention = 0;
          }
          //Память подключена
          else
          if(NOT_READY_TO_READY_CHANGE_MEDIUM_MAY_HAVE_CHANGED == error)
          {
            error = msd_read_capacity(msd, 0x0, &msd->capacity);
            #ifdef CONSOLE_DEBUG
            {FILE* dbgout = fopen( "/dev/dbgout", "w" );
            fprintf(dbgout,"Носитель подключен: ёмкость %4dМБ\n", _mem8(&msd->capacity.flash_capacity)/(1024*1024));
            fclose(dbgout);}
            #endif
            msd->unit_attention = 1;
          }
        }
      }
      msd = msd->next;
    }
    sleep_m(1000);  //1 sec sleep 
  }
}
#endif
/**************************************************************************************************\
*   Чтение с флеш
\***sss********************************************************************************************/
int32 msd_init(s_usb_msd_data* msd)
{
  int32 error;
  error = msd_vendor(msd, &msd->vendor);
  if(error) return error;
  #ifndef MSD_MULTI_LUNS
  error = msd_start_media(msd);
  if(error) return error;  
  error = msd_test_unit_ready(msd);
  //if(error) return error;
  error = msd_read_capacity(msd, 0x0, &msd->capacity);
  #endif
  return error;
}
/**************************************************************************************************\
*   Фиксация ошибки
\***sss********************************************************************************************/
int32 msd_fixed_error(s_usb_msd_data* msd, int32 error)
{
  if(!(error == BOT_COMMAND_FAILED<<4)) return error;
  error = msd_request_sense(msd, &msd->sense, false);
  if(!error)
  {
    error = (msd->sense.additional_sense_code<<8)|(msd->sense.additional_sense_code_qualifier);
    switch(error)
    {
      case MEDIUM_NOT_PRESENT:
      case NOT_READY_TO_READY_CHANGE_MEDIUM_MAY_HAVE_CHANGED:
      case LOGICAL_UNIT_IS_IN_PROCESS_OF_BECOMING_READY:
      {
        msd->media_change |= 1;
        return 0x0;
      }
    }
  }
  return error;
}
/**************************************************************************************************\
*   Запись на флеш
\***sss********************************************************************************************/
int32 msd_write(s_usb_msd_data* msd, void* data, uint32 size, uint32 lba, uint32* size_transfer)
{
  switch(msd->interface_protocol)
  {
    case USB_MSD_BULK_ONLY_PROTOCOL:
    {
      register int32      error;
      sem_lock(msd->sem, SEM_INFINITY);
      switch(msd->interface_sub_class)
      {
        case USB_MSD_SCSI_COMMAND_BLOCK:
          scsi_write_10(&msd->cbw.cbw_cb,lba,size/msd->capacity.block_length,0,0,0,0,0,0);
          break;
        default:                        
          error = OSE_NOT_INITIALIZED;
          goto m_end_bot_case;
      }
      error = bot_data_out_transport(msd, data, size);
      if(error) msd_fixed_error(msd, error);      
      if(size_transfer != NULL)
          *size_transfer = size - msd->csw.csw_data_residue;
      #ifdef CONSOLE_DEBUG
      if(error)
      {
        {FILE* dbgout = fopen( "/dev/dbgout", "w" );
        fprintf(dbgout,"ОШИБКА 0x%4.4x: записи флэш\n", error);
        fclose(dbgout);}
      }
      #endif
      m_end_bot_case:
      sem_unlock(msd->sem);
      return error;
    }
  }
  return OSE_NOT_INITIALIZED; 
}
/**************************************************************************************************\
*   Чтение с флеш
\***sss********************************************************************************************/
int32 msd_read(s_usb_msd_data* msd, void* data, uint32 size, uint32 lba, uint32* size_transfer)
{
  switch(msd->interface_protocol)
  {
    case USB_MSD_BULK_ONLY_PROTOCOL:
    {
      register int32      error;       
      sem_lock(msd->sem, SEM_INFINITY);
      switch(msd->interface_sub_class)
      {
        case USB_MSD_SCSI_COMMAND_BLOCK:
          scsi_read_10(&msd->cbw.cbw_cb,lba,size/msd->capacity.block_length,0,0,0,0,0,0);
          break;
        default:                        
          error = OSE_NOT_INITIALIZED;
          goto m_end_bot_case;
      }
      error = bot_data_in_transport(msd, data, size);
      if(error) msd_fixed_error(msd, error);
      if(size_transfer != NULL)
        *size_transfer = size - msd->csw.csw_data_residue;
      #ifdef CONSOLE_DEBUG
      if(error) 
      {
        {FILE* dbgout = fopen( "/dev/dbgout", "w" );
        fprintf(dbgout,"ОШИБКА 0x%4.4x: чтения флэш\n", error);
        fclose(dbgout);}
      }
      #endif
      m_end_bot_case:
      sem_unlock(msd->sem);
      return error;
    }
  }
  return OSE_NOT_INITIALIZED; 
}
/**************************************************************************************************\
*   КЭШировение данных;
\***sss********************************************************************************************/
int32 msd_pre_fetch(s_usb_msd_data* msd, uint32 size, uint32 lba)
{
  switch(msd->interface_protocol)
  {
    case USB_MSD_BULK_ONLY_PROTOCOL:
    {
      register int32      error;       
      sem_lock(msd->sem, SEM_INFINITY);
      switch(msd->interface_sub_class)
      {
        case USB_MSD_SCSI_COMMAND_BLOCK:
          scsi_pre_fetch_10(&msd->cbw.cbw_cb,lba,size/msd->capacity.block_length,0,0);
          break;
        default:                        
          error = OSE_NOT_INITIALIZED;
          goto m_end_bot_case;
      }
      error = bot_status_transport(msd);
      if(error) msd_fixed_error(msd, error);      
      m_end_bot_case:
      sem_unlock(msd->sem);
      return error;
    }
  }
  return OSE_NOT_INITIALIZED; 
}
/**************************************************************************************************\
*   Разрешить передачу
\***sss********************************************************************************************/
int32 msd_start_media(s_usb_msd_data* msd)
{
  switch(msd->interface_protocol)
  {
    case USB_MSD_BULK_ONLY_PROTOCOL:
    {
      register int32      error;
      sem_lock(msd->sem, SEM_INFINITY);
      switch(msd->interface_sub_class)
      {
        case USB_MSD_SCSI_COMMAND_BLOCK:
          scsi_start_stot_unit(&msd->cbw.cbw_cb,0,0,0,1,0); 
          break;
        default:                        
          error = OSE_NOT_INITIALIZED;
          goto m_end_bot_case;
      }
      error = bot_status_transport(msd);
      if(error) msd_fixed_error(msd, error);      
      m_end_bot_case:
      sem_unlock(msd->sem);
      return error;
    }
  }
  return OSE_NOT_INITIALIZED; 
}
/**************************************************************************************************\
*   Запретить передачу
\***sss********************************************************************************************/
int32 msd_stop_media(s_usb_msd_data* msd)
{
  switch(msd->interface_protocol)
  {
    case USB_MSD_BULK_ONLY_PROTOCOL:
    {
      register int32      error;       
      sem_lock(msd->sem, SEM_INFINITY);
      switch(msd->interface_sub_class)
      {
        case USB_MSD_SCSI_COMMAND_BLOCK:
          scsi_start_stot_unit(&msd->cbw.cbw_cb,0,0,0,0,0); 
          break;
        default:                        
          error = OSE_NOT_INITIALIZED;
          goto m_end_bot_case;
      }
      error = bot_status_transport(msd);
      if(error) msd_fixed_error(msd, error);      
      m_end_bot_case:
      sem_unlock(msd->sem);
      return error;
    }
  }
  return OSE_NOT_INITIALIZED; 
}
/**************************************************************************************************\
*   Емкость флеш
\***sss********************************************************************************************/
int32 msd_read_capacity(s_usb_msd_data* msd, int32 lba, s_msd_capacity* capacity)
{
  switch(msd->interface_protocol)
  {
    case USB_MSD_BULK_ONLY_PROTOCOL:
    {
      register int32      error;
      uint8  capacity_data[8];
      sem_lock(msd->sem, SEM_INFINITY);
      switch(msd->interface_sub_class)
      {
        case USB_MSD_SCSI_COMMAND_BLOCK:
          scsi_read_capacity(&msd->cbw.cbw_cb, lba, 1, 0x0);
          break;
        default:                        
          error = OSE_NOT_INITIALIZED;
          goto m_end_bot_case;
      }
      error = bot_data_in_transport(msd, capacity_data, sizeof(capacity_data));
      if(error) msd_fixed_error(msd, error);      
      else
      {
        capacity->last_lba = ((capacity_data[0]<<24)|(capacity_data[1]<<16)|(capacity_data[2]<<8)|(capacity_data[3]));
        capacity->block_length = ((capacity_data[4]<<24)|(capacity_data[5]<<16)|(capacity_data[6]<<8)|capacity_data[7]);
        _mem8(&capacity->flash_capacity) = ((uint64)msd->capacity.last_lba + 1) * (uint64)msd->capacity.block_length;
      }
      m_end_bot_case:
      sem_unlock(msd->sem);
      return error;
    }
  }
  return OSE_NOT_INITIALIZED; 
}
/**************************************************************************************************\
*   REQUEST SENSE
*   return 18 byte sense buffer
\***sss********************************************************************************************/
int32 msd_request_sense(s_usb_msd_data* msd, s_scsi_sense_data* sense, bool lock)
{
  switch(msd->interface_protocol)
  {
    case USB_MSD_BULK_ONLY_PROTOCOL:
    {
      register int32  error;
      uint8           sense_data[18];
      if(lock) sem_lock(msd->sem, SEM_INFINITY);
      switch(msd->interface_sub_class)
      {
        case USB_MSD_SCSI_COMMAND_BLOCK:
          scsi_request_sense(&msd->cbw.cbw_cb, 0x0, sizeof(sense_data),0x0);
          break;
        default:                        
          error = OSE_NOT_INITIALIZED;
          goto m_end_bot_case;
      }
      error = bot_data_in_transport(msd, sense_data, sizeof(sense_data));
      if(error) msd_fixed_error(msd, error);      
      else
      {
        sense->valid = (sense_data[0]>>7)&0x1;
        sense->response_code = sense_data[0]&0x7F;
        sense->filemark = (sense_data[2]>>7)&0x1;
        sense->eom = (sense_data[2]>>6)&0x1;
        sense->ili = (sense_data[2]>>5)&0x1;
        sense->sense_key = sense_data[2]&0xF;
        memcpy(sense->information, &sense_data[3], 4);
        sense->additional_sense_length = sense_data[7];
        memcpy(sense->command_specific_information, &sense_data[8], 4);
        sense->additional_sense_code = sense_data[12];
        sense->additional_sense_code_qualifier = sense_data[13];
        sense->field_replaceable_unit_code = sense_data[14];
        sense->sksv = (sense_data[15]>>7)&0x1;
        sense->sense_key_specific[0] = sense_data[15]&0x7F;
        sense->sense_key_specific[1] = sense_data[16];
        sense->sense_key_specific[2] = sense_data[17];
      }
      m_end_bot_case:
      if(lock) sem_unlock(msd->sem);
      return error;
    }
  }
  return OSE_NOT_INITIALIZED; 
}
/**************************************************************************************************\
*   TEST UNIT READY
\***sss********************************************************************************************/
int32 msd_test_unit_ready(s_usb_msd_data* msd)
{
  switch(msd->interface_protocol)
  {
    case USB_MSD_BULK_ONLY_PROTOCOL:
    {
      register int32      error;
      sem_lock(msd->sem, SEM_INFINITY);
      switch(msd->interface_sub_class)
      {
        case USB_MSD_SCSI_COMMAND_BLOCK:
          scsi_test_unit_ready(&msd->cbw.cbw_cb);
          break;
        default:                        
          error = OSE_NOT_INITIALIZED;
          goto m_end_bot_case;
      }
      error = bot_status_transport(msd);
      if(error) msd_fixed_error(msd, error);
      m_end_bot_case:
      sem_unlock(msd->sem);
      return error;
    }
  }
  return OSE_NOT_INITIALIZED; 
}
/**************************************************************************************************\
*   INQUIRY
\***sss********************************************************************************************/
int32 msd_vendor(s_usb_msd_data* msd, s_msd_vendor* vendor)
{
  switch(msd->interface_protocol)
  {
    case USB_MSD_BULK_ONLY_PROTOCOL:
    {
      register int32      error;       
      uint8  inquiry_data[36];
      sem_lock(msd->sem, SEM_INFINITY);
      switch(msd->interface_sub_class)
      {
        case USB_MSD_SCSI_COMMAND_BLOCK:
          scsi_inquiry(&msd->cbw.cbw_cb,0x0,0x0,sizeof(inquiry_data),0x0);
          break;
        default:                        
          error = OSE_NOT_INITIALIZED;
          goto m_end_bot_case;
      }
      error = bot_data_in_transport(msd, inquiry_data, sizeof(inquiry_data));
      if(error) msd_fixed_error(msd, error);
      else
      {
        memset(vendor->vendor_identification, 0x0, sizeof(vendor->vendor_identification));
        memset(vendor->product_identification, 0x0, sizeof(vendor->product_identification));
        memset(vendor->product_revision_level, 0x0, sizeof(vendor->product_revision_level));
      
        memcpy(vendor->vendor_identification, &inquiry_data[8], 8);
        memcpy(vendor->product_identification,&inquiry_data[16],16);
        memcpy(vendor->product_revision_level, &inquiry_data[32],4);
      }
      m_end_bot_case:
      sem_unlock(msd->sem);
      return error;
    }
  }
  return OSE_NOT_INITIALIZED; 
}
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//
//          Bulk Only Transport protocol
//
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
#define CMD_BLOCK_SIZE                              12
#define USB_CBW_FLAG_DATA_OUT                       0x00
#define USB_CBW_FLAG_DATA_IN                        0x80
//=========================================================
//transport:
int32   bot_command_stage(s_usb_msd_data* msd);
int32   bot_data_stage(s_usb_msd_data* msd, void* data);
int32   bot_status_stage(s_usb_msd_data* msd);
//endpoint 0 request:
int32   bot_reset_recovery(s_usb_msd_data* msd);
int32   bot_mass_storage_reset(s_usb_msd_data* msd);
int32   bot_clear_feature_halt_in_endpoint(s_usb_msd_data* msd);
int32   bot_clear_feature_halt_out_endpoint(s_usb_msd_data* msd);

/**************************************************************************************************\
*   Data-IN transport
\***sss********************************************************************************************/
int32 bot_data_in_transport(s_usb_msd_data* msd, void* data, uint32 size)
{
  register int32  error;
  msd->cbw.cbw_signature              = 0x43425355;
  msd->cbw.cbw_tag                    = msd->cbw.cbw_tag+1;
  msd->cbw.cbw_data_transfer_length   = size;
  msd->cbw.cbw_flags                  = USB_CBW_FLAG_DATA_IN;
  msd->cbw.cbw_lun                    = msd->lun;
  msd->cbw.cbw_cb_length              = CMD_BLOCK_SIZE;
  //Передача команды:
  if( error = bot_command_stage(msd) ) return error;
  //Прием данных:
  error = bot_data_stage(msd, data);
  //Получение статуса:
  if( error = bot_status_stage(msd) ) return error;
  else return msd->csw.csw_status<<4;
}
/**************************************************************************************************\
*   Data-OUT transport
\***sss********************************************************************************************/
int32 bot_data_out_transport(s_usb_msd_data* msd, void* data, uint32 size)
{
  register int32  error;
  msd->cbw.cbw_signature              = 0x43425355;
  msd->cbw.cbw_tag                    = msd->cbw.cbw_tag+1;
  msd->cbw.cbw_data_transfer_length   = size;
  msd->cbw.cbw_flags                  = USB_CBW_FLAG_DATA_OUT;
  msd->cbw.cbw_lun                    = msd->lun;
  msd->cbw.cbw_cb_length              = CMD_BLOCK_SIZE;
  //Передача команды:
  if( error = bot_command_stage(msd) ) return error;
  //Передача данных:
  error = bot_data_stage(msd, data);
  //Получение статуса:
  if( error = bot_status_stage(msd) ) return error;
  else return msd->csw.csw_status<<4;
}
/**************************************************************************************************\
*   Status transport
\***sss********************************************************************************************/
int32 bot_status_transport(s_usb_msd_data* msd)
{
  register int32  error;
  msd->cbw.cbw_signature              = 0x43425355;
  msd->cbw.cbw_tag                    = msd->cbw.cbw_tag+1;
  msd->cbw.cbw_data_transfer_length   = 0x0;
  msd->cbw.cbw_flags                  = USB_CBW_FLAG_DATA_OUT;
  msd->cbw.cbw_lun                    = msd->lun;
  msd->cbw.cbw_cb_length              = CMD_BLOCK_SIZE;
  //Передача команды:
  if( error = bot_command_stage(msd) ) return error;
  //Получение статуса:
  if( error = bot_status_stage(msd) ) return error;
  else return error = msd->csw.csw_status<<4;
}
/**************************************************************************************************\
*   Передача Command Block Wrapper (CBW)
\***sss********************************************************************************************/
int32 bot_command_stage(s_usb_msd_data* msd)
{
  int32       error;
  s_usb_bulk  bulk;
  
  bulk.data = &msd->cbw; 
  bulk.size = sizeof(s_usb_bot_cbw);
  bulk.endpoit_number = msd->out_endpoint;
  
  error = drv_ioctl(msd->file_usbd, USB_BULK_TRANSFER, &bulk);   
  
  if(error == USB_ER_STALL)
      bot_reset_recovery(msd);
  return error;
}
/**************************************************************************************************\
*   Прием/Передача данных
\***sss********************************************************************************************/
int32 bot_data_stage(s_usb_msd_data* msd, void* data)
{
  int         error;
  s_usb_bulk  bulk;

  bulk.data = data; 
  bulk.size = msd->cbw.cbw_data_transfer_length;
  switch(msd->cbw.cbw_flags)
  {
      case USB_CBW_FLAG_DATA_IN:  bulk.endpoit_number = msd->in_endpoint; break;
      case USB_CBW_FLAG_DATA_OUT: bulk.endpoit_number = msd->out_endpoint; break;
  }
  error = drv_ioctl(msd->file_usbd, USB_BULK_TRANSFER, &bulk);
  if(error == USB_ER_STALL)
  {    
      switch(msd->cbw.cbw_flags)
      {    
          case USB_CBW_FLAG_DATA_IN:  bot_clear_feature_halt_in_endpoint(msd); break;
          case USB_CBW_FLAG_DATA_OUT: bot_clear_feature_halt_out_endpoint(msd); break;            
      }
  }
  return error;
}
/**************************************************************************************************\
*   Прием Command Status Wrapper (CSW)
\***sss********************************************************************************************/
int32 bot_status_stage(s_usb_msd_data* msd)
{
  register int32      error;
  register int32      retry_read_csw = 1;   //Одна попытка повтора
  s_usb_bulk          bulk;
  
  bulk.data = &msd->csw; 
  bulk.size = sizeof(s_usb_bot_csw);
  bulk.endpoit_number = msd->in_endpoint;
  
  do{
    if(!retry_read_csw)
    {
      //Clear the STALL condition:    
      error = bot_clear_feature_halt_in_endpoint(msd);
    }
    error = drv_ioctl(msd->file_usbd, USB_BULK_TRANSFER, &bulk);   
  }while((error == USB_ER_STALL)&&(retry_read_csw--));
  //Если STALL не отчищен:
  if(error == USB_ER_STALL)
    bot_reset_recovery(msd);
  //CSW Valid:
  if((msd->cbw.cbw_tag != msd->csw.csw_tag)||(msd->csw.csw_signature != 0x53425355))
    bot_reset_recovery(msd);
  //Phase Error Status:
  if(msd->csw.csw_status == BOT_PHASE_ERROR_STATUS)
    bot_reset_recovery(msd);
  //Phase command faild:
  if(msd->csw.csw_status == BOT_COMMAND_FAILED)    
    asm(" nop");
  return error;
}
/**************************************************************************************************\
*   Восстановление носителя
\***sss********************************************************************************************/
int32 bot_reset_recovery(s_usb_msd_data* msd)
{
  int32           error;
  //Bulk-Only Mass Storage Reset:
  error = bot_mass_storage_reset(msd);
  if(error) return error;    

  //Сlear feature in endpoint halt:
  error = bot_clear_feature_halt_in_endpoint(msd);
  if(error) return error;    

  //Сlear feature out endpoint halt:
  error = bot_clear_feature_halt_out_endpoint(msd);
  return error;
}
/**************************************************************************************************\
*   Bulk-Only Mass Storage Reset
\***sss********************************************************************************************/
int32   bot_mass_storage_reset(s_usb_msd_data* msd)
{
  int32           error;
  s_usb_control   control;
  // Настройка Запроса Bulk-Only Mass Storage Reset:
  control.request.request_type = USB_REQUEST_TYPE_HOST_DEV|USB_REQUEST_TYPE_CLASS|USB_REQUEST_TYPE_INTERFACE;
  control.request.request      = 0xFF;
  control.request.value        = 0x0000;
  control.request.index        = msd->interface_number;
  control.request.length       = 0x0000;
  control.data                 = NULL;
  error = drv_ioctl(msd->file_usbd, USB_CONTROL_TRANSFER, &control);   
  if(!error)
    sleep_m(100);
  return error;    
}
/**************************************************************************************************\
*   Clear Feature HALT to the Bulk-In endpoint
\***sss********************************************************************************************/
int32   bot_clear_feature_halt_in_endpoint(s_usb_msd_data* msd)
{
  int32           error;
  s_usb_control   control;
  // Настройка Запроса clear feature in endpoint halt:
  control.request.request_type = USB_REQUEST_TYPE_HOST_DEV|USB_REQUEST_TYPE_STANDARD|USB_REQUEST_TYPE_ENDPOINT;
  control.request.request      = USB_REQUEST_CLEAR_FEATURE;
  control.request.value        = FEATURE_ENDPOINT_HALT;
  control.request.index        = msd->in_endpoint;
  control.request.length       = 0x0000;
  control.data                 = NULL;
  error = drv_ioctl(msd->file_usbd, USB_CONTROL_TRANSFER, &control);   
  if(!error)
  {
    *msd->in_data_toggle  = 0x0;
    sleep_m(100);
  }
  return error;    
}
/**************************************************************************************************\
*   Clear Feature HALT to the Bulk-Out endpoint
\***sss********************************************************************************************/
int32   bot_clear_feature_halt_out_endpoint(s_usb_msd_data* msd)
{
  int32           error;
  s_usb_control   control;
  // Настройка Запроса clear feature in endpoint halt:
  control.request.request_type = USB_REQUEST_TYPE_HOST_DEV|USB_REQUEST_TYPE_STANDARD|USB_REQUEST_TYPE_ENDPOINT;
  control.request.request      = USB_REQUEST_CLEAR_FEATURE;
  control.request.value        = FEATURE_ENDPOINT_HALT;
  control.request.index        = msd->out_endpoint;
  control.request.length       = 0x0000;
  control.data                 = NULL;
  error = drv_ioctl(msd->file_usbd, USB_CONTROL_TRANSFER, &control);   
  if(!error)
  {
    *msd->out_data_toggle  = 0x0;
    sleep_m(100);
  }
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
uint32              sem_msd_list;
//=================================================================================================
int32 init_msd_list()
{
  if( (first_msd_device==NULL)&&(last_msd_device==NULL) )
  {
    sem_msd_list = sem_alloc(1,NULL);
    if(sem_msd_list != RES_VOID) 
      return OSE_OK;
    else
      return OSE_CANT_CREATE_SEM;
  }
  return OSE_OK;
}
//=================================================================================================
void deinit_msd_list()
{
  if( (first_msd_device==NULL)&&(last_msd_device==NULL) )
  {
    sem_free(sem_msd_list);
  }
}
//=================================================================================================
s_usb_msd_data* create_msd()
{
  s_usb_msd_data* msd;
  msd = (s_usb_msd_data*)heap_alloc(NULL, sizeof(s_usb_msd_data), HEAP_ALIGN_4);
  if(msd != NULL)
  {   
    clear_device(msd);
    sem_lock(sem_msd_list, SEM_INFINITY);
    if(first_msd_device == NULL) 
      first_msd_device = msd;
    if(last_msd_device == NULL)
      msd->prev = NULL;
    else
    {
      last_msd_device->next = msd;
      msd->prev = last_msd_device;
    }
    last_msd_device = msd;
    msd->next = NULL;
    sem_unlock(sem_msd_list);
  }
  return msd;
}
//=================================================================================================
void add_msd(s_usb_msd_data* msd)
{
  if(msd != NULL)
  {   
    sem_lock(sem_msd_list, SEM_INFINITY);
    if(first_msd_device == NULL) 
      first_msd_device = msd;
    if(last_msd_device == NULL)
      msd->prev = NULL;
    else
    {
      last_msd_device->next = msd;
      msd->prev = last_msd_device;
    }
    last_msd_device = msd;
    msd->next = NULL;
    sem_unlock(sem_msd_list);
  }
}
//=================================================================================================
void delete_msd(s_usb_msd_data* msd)
{
  if(msd == NULL) return;
  sem_lock(sem_msd_list, SEM_INFINITY);
  if(msd->prev != NULL)
    msd->prev->next = msd->next;
  else
    first_msd_device = msd->next;
  if(msd->next != NULL)
    msd->next->prev = msd->prev;
  else
    last_msd_device = msd->prev;
  clear_device(msd);
  heap_free(NULL, msd);
  sem_unlock(sem_msd_list);
}
//=================================================================================================
void clear_device(s_usb_msd_data* msd)
{
  msd->prev = NULL;
  msd->next = NULL;
  msd->file_usbd = 0x0;
  msd->unit_attention = 0x0;
  msd->lun = 0x0;
  msd->interface_number = 0x0;
  msd->interface_sub_class = 0x0;
  msd->interface_protocol = 0x0;
  msd->in_endpoint = 0x0;
  msd->in_data_toggle = NULL;
  msd->out_endpoint = 0x0;
  msd->out_data_toggle = NULL;   
  msd->media_change = 0x0;
  memset(&msd->capacity, 0x0, sizeof(s_msd_capacity));
  memset(&msd->vendor, 0x0, sizeof(s_msd_vendor));
  memset(&msd->cbw, 0x0, sizeof(s_usb_bot_cbw));
  memset(&msd->csw, 0x0, sizeof(s_usb_bot_csw));
  memset(&msd->sense, 0x0, sizeof(s_scsi_sense_data));
  msd->sem = RES_VOID;
}
