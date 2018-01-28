//**************************************************************************************************
//                         Copyright (C) 2009 RCZI
//--------------------------------------------------------------------------------------------------
// FILENAME....... drv_lcd.cpp
// DATE CREATED... 15/10/2009
// LAST MODIFIED.. 03/11/2009
// DRIVER VERSION. 1.0
//--------------------------------------------------------------------------------------------------
//   Содержимое папки: /dev/
//               ..
//   <FILE>      lcd 
//--------------------------------------------------------------------------------------------------
//   Mass Production Code: PG240128LRS-ATA-H-SA
//--------------------------------------------------------------------------------------------------
//                   L C D    M O D U L E    D R I V E R
//-------------------------------------------------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
//
// !: codepage: cp1251 
//
// !: d: Драйвер дисплея "POWERTIP".<br>
// !: md: Дисплей (файл) в ОС связан с собственным файлом lcd. Путь к 
// !: md: устройству: "/dev/lcd". Драйвер реализует стандартный интерфейс 
// !: md: взаимодействия пользователя с устройством по средствам потокового 
// !: md: чтения из устройства (файла) и функции управляющих воздействий 
// !: md: на устройство.
// !: -:
//***sss********************************************************************************************
//#define     DRV_LCD_NEED_LOG
#include    <os.h>
#include    <rts.h>
#include    <mem_fpga.iface15.h>
#include    <drv_gpio.h>
#include    <drv_lcd.h>
#include    <drv_lcd_font.h>
//-------------------------------------------------------------------------------------------------
struct  s_color
{
  uint16      alpha;
  uint16      color;
};

struct  s_mode
{
  uint16      cursor_blink;
  uint16      cursor_display;
  uint16      text_display;
  uint16      graphic_display;
};

struct  s_display_mode
{
  uint16          seek;
  uint16          active_mode;
  s_mode          mode;
  s_color         fg;
  s_color         bg;
  s_display_axis  axis;  
};
//-------------------------------------------------------------------------------------------------
s_display_mode  gb_display;
//-------------------------------------------------------------------------------------------------
//      Stream function:
int32   lg_lcd_stream_output(s_display_mode* display, const void* buf, int32 length);  
//      I/O command function:
int32   lg_lcd_init_driver(s_os_driver_context* ctx);                                               
int32   lg_lcd_deinit_driver(s_os_driver_context* ctx);                                             
int32   lg_lcd_init_descriptor(s_os_driver_descriptor* d);                          
int32   lg_lcd_deinit_descriptor(s_os_driver_descriptor* d);                        
int32   lg_lcd_eof(s_display_mode* display, int32* vreturn);                       
int32   lg_lcd_seek(s_display_mode* display, int64 seek);                          
int32   lg_lcd_size(s_display_mode* display, int64* vreturn);                      
int32   lg_lcd_position(s_display_mode* display, int64* vreturn);                  
int32   lg_lcd_resize(s_display_mode* display);                                    
//      DRV command function:
int32   lg_lcd_set_mode(s_display_mode* display, int32 arg);                       
int32   lg_lcd_get_resolution(s_display_mode* display, s_display_axis* axis);      
int32   lg_lcd_set_cursor_visibility(s_display_mode* display, int32 enable);      
int32   lg_lcd_set_cursor_position(s_display_mode* display, s_display_axis* axis); 
int32   lg_lcd_set_cursor_height(s_display_mode* display, int32 line);            
int32   lg_lcd_set_foreground_color(s_display_mode* display, uint32 color);        
int32   lg_lcd_set_background_color(s_display_mode* display, uint32 color);        
int32   lg_lcd_load_keygen(s_display_mode* display, s_display_char* loadchar);     
int32   lg_lcd_load_keygen_buffer(s_display_mode* display, s_display_char_buffer* chars);

//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//
//          Интерфейсные функции драйвера
//
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO

//*************************************************************************************************
//       Открытие потока
//-------------------------------------------------------------------------------------------------
// !: fn: int32 lcd_open(s_os_driver_descriptor* d, uint16 access) 
//
// !: d: Функция открывает поток на запись.<br><br>
//
// !: d: Входные аргументы:<br>
// !: d: - *d - указатель на дескриптор драйвера, формируемый ОС;<br>
// !: d: - access - спецификатор доступа. Поддерживаемые значения: DRV_WR.<br><br>
//
// !: d: Возвращаемые значения:<br>
// !: d: - OSE_OK - если спецификатор доступа поддерживается;<br>
// !: d: - OSE_CANT_OPEN - если спецификатор доступа не поддерживается.<br>
// !: -:
//***sss********************************************************************************************
int32 lcd_open(s_os_driver_descriptor* d, uint16 access)
{
  switch(access & (DRV_WR | DRV_RD))
  {
    case (DRV_WR): d->access = DRV_WR | DRV_OPENED; break;
    default: return OSE_CANT_OPEN;
  }
  return  OSE_OK;
}
//*************************************************************************************************
//       Закрытие потока
//-------------------------------------------------------------------------------------------------
// !: fn: int32 lcd_close(s_os_driver_descriptor* d) 
//
// !: d: Функция закрывает открытый поток на чтение.<br><br>
//
// !: d: Входные аргументы:<br>
// !: d: - *d - указатель на дескриптор драйвера, формируемый ОС.<br><br>
//
// !: d: Возвращаемые значения:<br>
// !: d: - OSE_OK - если поток на чтение был открыт;<br>
// !: d: - OSE_CANT_OPEN - если поток на чтение не был открыт.<br>
// !: -:
//***sss********************************************************************************************
int32 lcd_close(s_os_driver_descriptor* d)
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
// !: fn: int32 lcd_read(s_os_driver_descriptor* d, void* buf, int32 length)
//
// !: d: Функция драйвером не поддерживаеться.<br> 
// !: -:
//***sss********************************************************************************************
int32 lcd_read(s_os_driver_descriptor* d, void* buf, int32 length)
{
  return OSE_PERMISSION_DENIED;
}
//**************************************************************************************************
//       Запись в поток
//-------------------------------------------------------------------------------------------------
// !: fn: int32 lcd_write(s_os_driver_descriptor* d, const void* buf, int32 length)
//
// !: d: Функция осуществляет не блокирующую потоковую запись в устройство.<br><br>
//
// !: d: Входные аргументы:<br>
// !: d: - *d - указатель на дескриптор драйвера, формируемый ОС;<br>
// !: d: - *buf - указатель на буфер вывода;<br>
// !: d: - length - записываемая длинна.<br><br>
//
// !: d: Возвращаемые значения:<br>
// !: d: Количество записанных байт.<br>
// !: -:
//***sss********************************************************************************************
int32 lcd_write(s_os_driver_descriptor* d, const void* buf, int32 length)
{
  if(d->access == DRV_WR | DRV_OPENED)
    return lg_lcd_stream_output((s_display_mode*)d->data,buf, length);
  return OSE_PERMISSION_DENIED;
}
//**************************************************************************************************
//       Управление вводом/выводом
//-------------------------------------------------------------------------------------------------
// !: fn: int32 lcd_ioctl(s_os_driver_descriptor* d, int32 cmd, const void* arg)
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
// !: d: - Стандартные коды ошибок ioctl.<br><br>
//
// !: d: Стандартные команды управления:<br>
// !: d: - IOC_INIT, IOC_DEINIT, IOC_INIT_DESCRIPTOR, IOC_DEINIT_DESCRIPTOR,
// !: d:   IOC_INODE_SELECT, IOC_EOF, IOC_SEEK, IOC_SIZE, 
// !: d:   IOC_POSITION, IOC_RESIZE.<br><br>  
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
// !: d:   DSPL_SET_MODE 
// !: d:   </td>
// !: d:   <td valign=top>
// !: d:   int32
// !: d:   </td>
// !: d:   <td valign=top>
// !: d:   Установка режима работы дисплея.<br>
// !: d:   Режимы работы:<br>
// !: d:   - MODE_DISPLAY_OFF - дисплей выключен;<br>
// !: d:   - MODE_DISPLAY_TEXT - текстовый режим дисплея;<br>
// !: d:   </td>
// !: d: </tr>
//
// !: d: <tr>
// !: d:   <td valign=top>
// !: d:   DSPL_GET_RESOLUTION
// !: d:   </td>
// !: d:   <td valign=top>
// !: d:   s_display_axis
// !: d:   </td>
// !: d:   <td valign=top>
// !: d:   Получение разрешения дисплея в зависимости
// !: d:   от режима его работы.<br>
// !: d:   </td>
// !: d: </tr>
//
// !: d: <tr>
// !: d:   <td valign=top>
// !: d:   DSPL_SET_CURSOR_VISIBILITY 
// !: d:   </td>
// !: d:   <td valign=top>
// !: d:   int32
// !: d:   </td>
// !: d:   <td valign=top>
// !: d:   Установка видимости курсора.<br>
// !: d:   Режим курсора:<br>
// !: d:   - CURSOR_ENABLE - курсор включен;<br>
// !: d:   - CURSOR_DISABLE - курсор выключен.<br>
// !: d:   </td>
// !: d: </tr>
//
// !: d: <tr>
// !: d:   <td valign=top>
// !: d:   DSPL_SET_CURSOR_POSITION 
// !: d:   </td>
// !: d:   <td valign=top>
// !: d:   s_display_axis
// !: d:   </td>
// !: d:   <td valign=top>
// !: d:   Установка позиции курсора.
// !: d:   </td>
// !: d: </tr>
//
// !: d: <tr>
// !: d:   <td valign=top>
// !: d:   DSPL_SET_CURSOR_HEIGHT 
// !: d:   </td>
// !: d:   <td valign=top>
// !: d:   int32
// !: d:   </td>
// !: d:   <td valign=top>
// !: d:   Установка высоты курсора. Высота может варьироваться от 1 до 8.
// !: d:   </td>
// !: d: </tr>
//
// !: d: <tr>
// !: d:   <td valign=top>
// !: d:   DSPL_SET_FOREGROUND_COLOR 
// !: d:   </td>
// !: d:   <td valign=top>
// !: d:   uint32
// !: d:   </td>
// !: d:   <td valign=top>
// !: d:   Установка цвета текста.<br>
// !: d:   Формат цвета:<br>
// !: d:   - ALPHA[31,24] - режим мигания. 0xFF - мигающий, 0x00 - немигающий;<br>
// !: d:   - COLOR[23,00] - цвет. 0xFFFFFF - белый, 0x000000 - черный.<br>
// !: d:   </td>
// !: d: </tr>
//
// !: d: <tr>
// !: d:   <td valign=top>
// !: d:   DSPL_SET_BACKGROUND_COLOR 
// !: d:   </td>
// !: d:   <td valign=top>
// !: d:   uint32
// !: d:   </td>
// !: d:   <td valign=top>
// !: d:   Установка цвета фона.<br>
// !: d:   Формат цвета:<br>
// !: d:   - ALPHA[31,24] - всегда равен 0x00;<br>
// !: d:   - COLOR[23,00] - цвет. 0xFFFFFF - белый, 0x000000 - черный.<br>
// !: d:   </td>
// !: d: </tr>
//
// !: d: <tr>
// !: d:   <td valign=top>
// !: d:   DSPL_LOAD_KEYGEN 
// !: d:   </td>
// !: d:   <td valign=top>
// !: d:   s_display_char
// !: d:   </td>
// !: d:   <td valign=top>
// !: d:   Загрузка символа в символ генератор.
// !: d:   Код символа устанавливается в диапазоне от 0x80 до 0xAF.<br>
// !: d:   </td>
// !: d: </tr>
//
// !: d: <tr>
// !: d:   <td valign=top>
// !: d:   DSPL_LOAD_KEYGEN_BUFFER 
// !: d:   </td>
// !: d:   <td valign=top>
// !: d:   s_display_char_buffer
// !: d:   </td>
// !: d:   <td valign=top>
// !: d:   Загрузка буфера в символ генератор.
// !: d:   Код символа устанавливается в диапазоне от 0x80 до 0xAF.
// !: d:   Размер буфера не должен превышать максимально загружаемой зоны<br>
// !: d:   </td>
// !: d: </tr>

// !: d: </table>
// !: -:
//***sss********************************************************************************************
int32 lcd_ioctl(s_os_driver_descriptor* d, int32 cmd, const void* arg)
{
  switch(cmd)
  {
    //===============================================================
    //Standard control command:
    //Инициализация:
    case IOC_INIT: return lg_lcd_init_driver((s_os_driver_context*)arg);
    //Деинициализация:
    case IOC_DEINIT: return lg_lcd_deinit_driver((s_os_driver_context*)arg);
    //Инициализация данных:
    case IOC_INIT_DESCRIPTOR: return lg_lcd_init_descriptor(d);
    //Деинициализация данных:
    case IOC_DEINIT_DESCRIPTOR: return lg_lcd_deinit_descriptor(d);
    //Переход по директориям в корне драйвера:
    case IOC_INODE_SELECT:      
    {   
      const char* recast_arg = (const char*) arg;
      if(d->access & DRV_OPENED) return OSE_STREAM_OPENED;
      if(!strcmp(recast_arg,".")) break;
      else if(!strcmp(recast_arg,".."))
      {
        drv_dec(d);
        drv_rfs(d);
      }
      else return OSE_NO_NODE;
    }
    break;
    //Анализ конца потока;
    case IOC_EOF: return  lg_lcd_eof((s_display_mode*)d->data, (int32*)arg);
    //Команда установки:
    case IOC_SEEK: return lg_lcd_seek((s_display_mode*)d->data, _mem8( (int64*)arg ));
    //Размер потока:
    case IOC_SIZE: return lg_lcd_size((s_display_mode*)d->data, (int64*)arg);
    //Текущая позиция в потоке:
    case IOC_POSITION: return lg_lcd_position((s_display_mode*)d->data, (int64*)arg);
    //Удаление данных из потока:
    case IOC_RESIZE: return lg_lcd_resize((s_display_mode*)d->data);

    //===============================================================
    //Driver self control command:
    //Режима дисплея:
    case DSPL_SET_MODE: return  lg_lcd_set_mode((s_display_mode*)d->data, *(int32*) arg);
    //Разрешение экрана:
    case DSPL_GET_RESOLUTION: return lg_lcd_get_resolution((s_display_mode*)d->data, (s_display_axis*)arg);
    //Видимость курсор:
    case DSPL_SET_CURSOR_VISIBILITY: return lg_lcd_set_cursor_visibility((s_display_mode*)d->data, *(int32*)arg);
    //Установить позицию курсора:
    case DSPL_SET_CURSOR_POSITION: return lg_lcd_set_cursor_position((s_display_mode*)d->data, (s_display_axis*)arg);               
    //Установить высоту курсора:
    case DSPL_SET_CURSOR_HEIGHT: return lg_lcd_set_cursor_height((s_display_mode*)d->data, *(int32*)arg);                        
    //Цвет текста:
    case DSPL_SET_FOREGROUND_COLOR: return lg_lcd_set_foreground_color((s_display_mode*)d->data, *(uint32*)arg);
    //Цвет заднего фона:
    case DSPL_SET_BACKGROUND_COLOR: return lg_lcd_set_background_color((s_display_mode*)d->data, *(uint32*)arg);
    //Загрузить символ в символ-генератор:
    case DSPL_LOAD_KEYGEN: return lg_lcd_load_keygen((s_display_mode*)d->data, (s_display_char*)arg);
    //Загрузить буфер в символ-генератор:
    case DSPL_LOAD_KEYGEN_BUFFER: return lg_lcd_load_keygen_buffer((s_display_mode*)d->data, (s_display_char_buffer*)arg);
    default: return OSE_BAD_CMD;
  }
  return OSE_OK;
}       
//**************************************************************************************************
//      Добавить драйвер в систему
//-------------------------------------------------------------------------------------------------
// !: fn: int32 drv_lcd_plug()
//
// !: d: Добавляет драйвер дисплея в систему<br><br> 
//
// !: d: Возвращаемые значения:<br>
// !: d: - Стандартные коды ошибок ioctl.<br>
//***sss********************************************************************************************
int32 drv_lcd_plug(uint32 number_gpio_interrupt)
{
  return drv_plug("/dev/lcd", INOT_FILE, &lcd_open, &lcd_close, &lcd_read, &lcd_write, &lcd_ioctl, &number_gpio_interrupt, sizeof(uint32));
}
//*************************************************************************************************
//      Удалить драйвер из системы 
//-------------------------------------------------------------------------------------------------
// !: fn: int32 drv_lcd_unplug()
//
// !: d: Удаляет драйвер дисплея из системы<br><br> 
//
// !: d: Возвращаемые значения:<br>
// !: d: - Стандартные коды ошибок ioctl.<br>
//***sss********************************************************************************************
int32 drv_lcd_unplug()
{
  return drv_unplug("lcd");
}
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//
//          Логические функции драйвера
//
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
#define OFF             0
#define TEXT            1
#define GRAPH           2
#define LCD_COLUMN      30
#define LCD_TEXT_ROW    16
#define LCD_GRAPH_ROW   128
#define LCD_EOF         1
#define LCD_TEXT_EOF    LCD_COLUMN * LCD_TEXT_ROW   //480
#define LCD_GRAPH_EOF   LCD_COLUMN * LCD_GRAPH_ROW  //3840

//-------------------------------------------------------------------------------------------------
void   displ_interrupt();
int32  ph_lcd_init_hardware();
int32  ph_lcd_clear_video_ram();
int32  ph_lcd_output_char(uint32 Address, uint8* Buf, uint32 Length, s_color* FG, s_color* BG);
int32  ph_lcd_output_data(uint32 Address, uint8* Buf, uint32 Length);
int32  ph_lcd_mode(s_mode* mode);
int32  ph_lcd_cursor_position(uint16 x, uint16 y);
int32  ph_lcd_cursor_height(uint8  number_line);
int32  ph_lcd_load_keygen(uint32 Address, uint8 CharCode, uint8* BufCharLine, int32 BufSize);
//-------------------------------------------------------------------------------------------------
//       ГЛОБАЛЬНЫЕ ПЕРЕМЕННЫЕ
//-------------------------------------------------------------------------------------------------
uint32 sem_lcd;
int8   lcd_driver_init = 0;

/**************************************************************************************************\
*   Инициализация драйвера
\***sss********************************************************************************************/
int32 lg_lcd_init_driver(s_os_driver_context* ctx)
{
  int32 error;
  s_gpio_interrupt displ_gpio;
  uint32 file = RES_VOID;
  int32 complete_stage = 0;
  if(lcd_driver_init) 
  {
    #ifdef DRV_LCD_NEED_LOG
    syslog(LOG_ERR, "drv_lcd error: \n -cmd IOC_INIT \n -error %d", OSE_ALREADY_PLUGGED);
    #endif
    return OSE_ALREADY_PLUGGED;
  }

  //*** STAGE1 ***
  error = ph_lcd_init_hardware();
  if(error)
  {
    error = OSE_NO_DEVICE;
    goto m_return;
  }
  complete_stage++;

  //*** STAGE2 ***
  sem_lcd = sem_alloc(1,NULL);
  if(sem_lcd == RES_VOID)
  {
    error = OSE_CANT_CREATE_SEM;
    goto m_return;
  }
  complete_stage++;  

  //*** STAGE3 ***  
  file = drv_mkd("/dev/gpio");
  if(file == RES_VOID)
  {
    error = OSE_NOT_INITIALIZED;
    goto m_return;
  }
  complete_stage++;

  //*** STAGE4 ***  
  displ_gpio.number_gpio = *(uint32*)ctx->data;
  displ_gpio.call_functoin = &displ_interrupt;  
  error = drv_ioctl(file, GPIO_INT_ALLOC, &displ_gpio);
  if(error != OSE_OK)
  {
    goto m_return;
  }
  complete_stage++;  
  
  //*** STAGE5 ***    
  memset(&gb_display, 0x0, sizeof(s_display_mode));    
  error = lg_lcd_set_cursor_visibility(&gb_display, 0);
  if(error) goto m_return;
  
  error = lg_lcd_set_foreground_color(&gb_display, 0x00000000);
  if(error) goto m_return;
  
  error = lg_lcd_set_background_color(&gb_display, 0x00FFFFFF);
  if(error) goto m_return;
  
  error = lg_lcd_set_mode(&gb_display,TEXT);
  if(error) goto m_return;
  
  error = lg_lcd_set_cursor_position(&gb_display, &gb_display.axis);
  if(error) goto m_return;
  
  error = lg_lcd_set_cursor_height(&gb_display, 1);
  if(error) goto m_return;
  complete_stage++;      
  
  //*** STAGE COMPLETE ***   
  lcd_driver_init = 1;
  error = OSE_OK;
  
  m_return:
  switch(complete_stage)
  {
      case  4: drv_ioctl(file, GPIO_INT_FREE, &displ_gpio);
      case  3: drv_rmd(file);
      case  2: sem_free(sem_lcd);
      default: break;
  }
  return error;  
}
/**************************************************************************************************\
*   Деинициализация драйвера
\***sss********************************************************************************************/
int32 lg_lcd_deinit_driver(s_os_driver_context* ctx)
{
  int32 error;
  if(lcd_driver_init == 1)
  {
    s_gpio_interrupt    displ_gpio;
    uint32 file = drv_mkd("/dev/gpio");
    displ_gpio.number_gpio = *(uint32*)ctx->data;
    displ_gpio.call_functoin = &displ_interrupt;    
    error = drv_ioctl(file, GPIO_INT_FREE, &displ_gpio);
    drv_rmd(file);
    sem_free(sem_lcd);    
    lcd_driver_init = 0;
  }
  else error = OSE_DRIVER_UNLOADED;
  return error;
}

/**************************************************************************************************\
*   Инициализация дескриптора дисплея
\***sss********************************************************************************************/
int32 lg_lcd_init_descriptor(s_os_driver_descriptor* d)
{
  if(!lcd_driver_init)
  {
    #ifdef DRV_LCD_NEED_LOG
    syslog(LOG_ERR, "drv_lcd error: \n -cmd IOC_INIT_DESCRIPTOR \n -error %d", OSE_NO_DEVICE);
    #endif
    return OSE_NO_DEVICE;
  }
  d->data = &gb_display;
  return OSE_OK;
}
/**************************************************************************************************\
*   Деинициализация дескриптора дисплея
\***sss********************************************************************************************/
int32 lg_lcd_deinit_descriptor(s_os_driver_descriptor* d)
{
  d->data = NULL;
  return OSE_OK;
}
/**************************************************************************************************\
*   Потоковый вывод на дисплей
\***sss********************************************************************************************/
int32 lg_lcd_stream_output(s_display_mode* display, const void* buf, int32 length)
{
  if(display == NULL) return 0x0;
  uint32 output_byte = 0x0;
  sem_lock(sem_lcd,SEM_INFINITY);  
  switch(display->active_mode)
  {
    case TEXT:
    {
      output_byte = (display->seek+length<=LCD_TEXT_EOF) ? length : LCD_TEXT_EOF-display->seek;
      output_byte = ph_lcd_output_char(display->seek, (uint8*)buf, output_byte, &display->fg, &display->bg);
      display->seek += output_byte;
    }
    break;
    case GRAPH:
    {
      output_byte = (display->seek+length<=LCD_GRAPH_EOF) ? length : LCD_GRAPH_EOF-display->seek;
      output_byte = ph_lcd_output_data(display->seek, (uint8*)buf, output_byte);
      display->seek += output_byte;
    }
    break;
  }
  sem_unlock(sem_lcd);  
  return output_byte;
}
/**************************************************************************************************\
*   Анализ конца потока
\***sss********************************************************************************************/
int32 lg_lcd_eof(s_display_mode* display, int32* vreturn)
{
  if(display == NULL) return OSE_BAD_RDESC;
  sem_lock(sem_lcd,SEM_INFINITY);  
  switch (display->active_mode)
  {
    case TEXT:
    {
      if(display->seek == LCD_TEXT_EOF) *vreturn = LCD_EOF;
      else *vreturn = 0;
    }
    break;
    case GRAPH:
    {
      if(display->seek == LCD_GRAPH_EOF) *vreturn = LCD_EOF;
      else *vreturn = 0;
    }    
    break;
    default: *vreturn = LCD_EOF;
  }
  sem_unlock(sem_lcd);  
  return OSE_OK;
}
/**************************************************************************************************\
*   Команда установки
\***sss********************************************************************************************/
int32 lg_lcd_seek(s_display_mode* display, int64 seek)
{
  if(display == NULL) return OSE_BAD_RDESC;
  int32 error = OSE_OK;  
  sem_lock(sem_lcd,SEM_INFINITY);  
  switch (display->active_mode)
  {
    case TEXT:  display->seek = (seek>=LCD_TEXT_EOF) ? LCD_TEXT_EOF : (int16)seek;   break;
    case GRAPH: display->seek = (seek>=LCD_GRAPH_EOF) ? LCD_GRAPH_EOF : (int16)seek; break;
    default: error = OSE_BAD_PARAM;
  }
  sem_unlock(sem_lcd);  
  return error;
}
/**************************************************************************************************\
*   Размер потока
\***sss********************************************************************************************/
int32 lg_lcd_size(s_display_mode* display, int64* vreturn)
{
  if(display == NULL) return OSE_BAD_RDESC;
  sem_lock(sem_lcd,SEM_INFINITY);  
  switch (display->active_mode)
  {
    case TEXT:  *vreturn = LCD_TEXT_EOF;    break;
    case GRAPH: *vreturn = LCD_GRAPH_EOF;   break;
    default:    *vreturn = 0x0;
  }
  sem_unlock(sem_lcd);  
  return OSE_OK;
}
/**************************************************************************************************\
*   Текущая позиция в потоке
\***sss********************************************************************************************/
int32 lg_lcd_position(s_display_mode* display, int64* vreturn)
{
  if(display == NULL) return OSE_BAD_RDESC;
  sem_lock(sem_lcd,SEM_INFINITY);  
  *vreturn = display->seek;
  sem_unlock(sem_lcd);  
  return OSE_OK;
}
/**************************************************************************************************\
*   Удаление данных из потока
\***sss********************************************************************************************/
int32 lg_lcd_resize(s_display_mode* display)
{
  if(display == NULL) return OSE_BAD_RDESC;
  else return OSE_OK;
}
/**************************************************************************************************\
*   Режим дисплея
\***sss********************************************************************************************/
int32 lg_lcd_set_mode(s_display_mode* display, int32 mode)
{
  if(display == NULL) return OSE_BAD_RDESC;
  int32 error;
  sem_lock(sem_lcd,SEM_INFINITY);  
  switch (mode)
  {
    case OFF:
    {
      display->active_mode = OFF;
      display->mode.text_display    = 0;
      display->mode.graphic_display = 0;
    }
    break;
    case TEXT:   
    {
      display->active_mode = TEXT;
      display->mode.text_display    = 1;
      display->mode.graphic_display = 1;
    }
    break;
    case GRAPH:       
    {
      display->active_mode = GRAPH;
      display->mode.text_display    = 0;
      display->mode.graphic_display = 1;
    }
    break;
    default:
    {
      error = OSE_BAD_PARAM; 
      goto m_return;
    }
  }
  error = ph_lcd_clear_video_ram();
  if(error) goto m_return;
  
  error = ph_lcd_mode(&display->mode);
  if(error != OSE_OK) goto m_return;
  display->seek = 0;
  
  m_return:  
  sem_unlock(sem_lcd);   
  return error;
}
/**************************************************************************************************\
*   Разрешение дисплея
\***sss********************************************************************************************/
int32 lg_lcd_get_resolution(s_display_mode* display, s_display_axis* axis)
{
  if(display == NULL) return OSE_BAD_RDESC;
  sem_lock(sem_lcd,SEM_INFINITY);    
  switch (display->active_mode)
  {
    case TEXT:
    {
      //Максимальные координаты символов:
      axis->x = LCD_COLUMN;
      axis->y = LCD_TEXT_ROW; 
    }
    break;
    case GRAPH:
    {
      //Максимальные координаты точек:
      axis->x = LCD_COLUMN << 3;
      axis->y = LCD_GRAPH_ROW;  
    }
    break;
    default:
    {
      axis->x = 0x0;
      axis->y = 0x0;  
    }
  }
  sem_unlock(sem_lcd);   
  return OSE_OK;
}
/**************************************************************************************************\
*   Режим курсора дисплея
\***sss********************************************************************************************/
int32 lg_lcd_set_cursor_visibility(s_display_mode* display, int32 enable)
{
  if(display == NULL) return OSE_BAD_RDESC;
  sem_lock(sem_lcd,SEM_INFINITY);  
  if(enable & 0x1)
  {
    display->mode.cursor_blink    = 1;    
    display->mode.cursor_display  = 1;
  }
  else
  {
    display->mode.cursor_blink    = 0;    
    display->mode.cursor_display  = 0;
  }
  sem_unlock(sem_lcd);  
  return ph_lcd_mode(&display->mode);
}
/**************************************************************************************************\
*   Позиция курсора дисплея
\***sss********************************************************************************************/
int32 lg_lcd_set_cursor_position(s_display_mode* display, s_display_axis* axis)
{
  if(display == NULL) return OSE_BAD_RDESC;
  int32 error;
  sem_lock(sem_lcd,SEM_INFINITY);    
  switch (display->active_mode)
  {
    case TEXT:   
    {
      if((axis->x < LCD_COLUMN)&&(axis->y < LCD_TEXT_ROW)) 
      {
        display->axis.x = axis->x;
        display->axis.x = axis->y;        
        error = ph_lcd_cursor_position(axis->x, axis->y);
      }
      else 
      	error = OSE_BAD_PARAM;
    }
    break;
    case GRAPH: error = OSE_BAD_PARAM; break;
    default: error = OSE_NO_DEVICE;
  }
  sem_unlock(sem_lcd); 
  return error;
}
/**************************************************************************************************\
*   Высота курсора дисплея
\***sss********************************************************************************************/
int32 lg_lcd_set_cursor_height(s_display_mode* display, int32 line)
{
  if(display == NULL) return OSE_BAD_RDESC;
  int32 error;
  sem_lock(sem_lcd,SEM_INFINITY);
  switch (display->active_mode)
  {
    case TEXT:   
    {
      if((1<=line)&&(line<=8)) error = ph_lcd_cursor_height(line);
      else error = OSE_BAD_PARAM;
    }
    break;
    case GRAPH: error = OSE_BAD_PARAM; break;
    default: error = OSE_NO_DEVICE;
  }
  sem_unlock(sem_lcd); 
  return error;
}
/**************************************************************************************************\
*   Установка переднего фона
\***sss********************************************************************************************/
int32 lg_lcd_set_foreground_color(s_display_mode* display, uint32 color)
{
  if(display == NULL) return OSE_BAD_RDESC;
  int32 error = OSE_OK;
  sem_lock(sem_lcd,SEM_INFINITY);  
  //Установка цвета:
  if((color & 0x00FFFFFF)==0xFFFFFF)
    display->fg.color = 1;
  else
  if((color & 0x00FFFFFF)==0x000000)
    display->fg.color = 0;
  else
  {
    error = OSE_BAD_PARAM;
    goto m_return;
  }
  //Установка мигания:
  if(((color & 0xFF000000)>>24)==0xFF)
    display->fg.alpha = 1;
  else
  if(((color & 0xFF000000)>>24)==0x00)
    display->fg.alpha = 0;
  else
    error = OSE_BAD_PARAM;
  m_return:
  sem_unlock(sem_lcd);  
  return error;
}
/**************************************************************************************************\
*   Установка заднего фона
\***sss********************************************************************************************/
int32 lg_lcd_set_background_color(s_display_mode* display, uint32 color)
{
  if(display == NULL) return OSE_BAD_RDESC;
  int32 error = OSE_OK;
  sem_lock(sem_lcd,SEM_INFINITY);  
  //Установка цвета:
  if((color & 0x00FFFFFF)==0xFFFFFF)
    display->bg.color = 1;
  else
  if((color & 0x00FFFFFF)==0x000000)
    display->bg.color = 0;
  else
  {
    error = OSE_BAD_PARAM;
    goto m_return;
  }
  //Установка мигания:
  display->bg.alpha = 0;
  if(color & 0xFF000000)
    error = OSE_BAD_PARAM;
  m_return:
  sem_unlock(sem_lcd);  
  return error;
}
/**************************************************************************************************\
*   Загрузка символов в символ-генератор
\***sss********************************************************************************************/
int32 lg_lcd_load_keygen(s_display_mode* display, s_display_char* loadchar)
{
  if(display == NULL) return OSE_BAD_RDESC;
  int32 error;
  sem_lock(sem_lcd,SEM_INFINITY);    
  if((0x80<=loadchar->code)&&(loadchar->code<0xC0))
    error = ph_lcd_load_keygen(display->seek, loadchar->code, loadchar->line, sizeof(loadchar->line));
  else
    error = OSE_BAD_PARAM;
  sem_unlock(sem_lcd); 
  return error;
}
/**************************************************************************************************\
*   Загрузка буфера в символ-генератор
\***sss********************************************************************************************/
int32 lg_lcd_load_keygen_buffer(s_display_mode* display, s_display_char_buffer* chars)
{
  if(display == NULL) return OSE_BAD_RDESC;
  int32 error;
  sem_lock(sem_lcd,SEM_INFINITY);   
  if( !((0x80<=chars->code)&&(chars->code<0xC0)) ) error = OSE_BAD_PARAM;
  else if(chars->size & 0x7) error = OSE_BAD_PARAM;
  else if( chars->size > ((0xC0-chars->code)*0x8) ) error = OSE_BAD_PARAM;
  else error = ph_lcd_load_keygen(display->seek, chars->code, chars->buffer, chars->size);
  sem_unlock(sem_lcd); 
  return error;  
}
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//
//      Физический уровень драйвера 
//
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//Display memory:
#define START_ADR_TEXT_AREA         0x0000
#define START_ADR_GRAPH_AREA        0x0200
#define START_ADR_GGRAM_AREA        0xFC00
//Character attribute:
#define TEXT_NORMAL                 0x00
#define TEXT_REVERSE                0x05
#define TEXT_BLINK                  0x08

struct s_dspl_axis
{
  uint32          x;
  uint32          y;    
};

struct s_dspl_status
{
  uint32          cursor_lines;
  s_mode          mode;
  s_dspl_axis     cursor_axis;
  uint8           text[LCD_TEXT_EOF];
  uint8           graph[LCD_GRAPH_EOF];
  uint8           user_char_generator[64*8];
}dspl_status;

int32   tr_lcd_cursor_pointer_set(uint16 X,uint16 Y);
int32   tr_lcd_offset_register_set(uint8 Offset);                                            
int32   tr_lcd_address_pointer_set(uint16 Address);                                           
int32   tr_lcd_text_home_address_set(uint16 Address);
int32   tr_lcd_graphic_home_address_set(uint16 Address);
int32   tr_lcd_text_area_set(uint16 Columns);                                         
int32   tr_lcd_graphic_area_set(uint16 Columns);                                      
int32   tr_lcd_or_mode();
int32   tr_lcd_exor_mode();
int32   tr_lcd_and_mode();            
int32   tr_lcd_text_attribute_mode();
int32   tr_lcd_internal_cg_rom_mode();    
int32   tr_lcd_external_cg_ram_mode();
int32   tr_lcd_display_mode(uint8 Mode);
int32   tr_lcd_number_line_cursor(uint8 NumberLine);
int32   tr_lcd_data_write_inc(int8 Data); 
int32   tr_lcd_data_write_dec(int8 Data); 
int32   tr_lcd_data_write_non(int8 Data); 
int32   tr_lcd_data_auto_write(uint8* Buf, uint32 Length);
int32   tr_lcd_const_auto_write(uint8 Const, uint32 Length);

/**************************************************************************************************\
*   Обработка прерывания от датчика дисплея
\***sss********************************************************************************************/
void displ_interrupt()
{
  register int32 error;
  //Set TEXT:
  error = tr_lcd_text_home_address_set(START_ADR_TEXT_AREA);
  if(error) return;
  error = tr_lcd_text_area_set(LCD_COLUMN);
  if(error) return;    

  //Set GRAPHIC:
  error = tr_lcd_graphic_home_address_set(START_ADR_GRAPH_AREA);
  if(error) return;
  error = tr_lcd_graphic_area_set(LCD_COLUMN);
  if(error) return;    

  //Recovery LCD memory:
  error = tr_lcd_address_pointer_set(START_ADR_TEXT_AREA);
  if(error) return;
  error = tr_lcd_data_auto_write(dspl_status.text, LCD_TEXT_EOF);    
  if(error != LCD_TEXT_EOF) return;    
  
  error = tr_lcd_address_pointer_set(START_ADR_GRAPH_AREA);
  if(error) return;
  error = tr_lcd_data_auto_write(dspl_status.graph, LCD_GRAPH_EOF);        
  if(error != LCD_GRAPH_EOF) return;    

  //Set Char Generation:
  error = tr_lcd_address_pointer_set(START_ADR_GGRAM_AREA);
  if(error) return;
  //User char area:
  error = tr_lcd_data_auto_write(dspl_status.user_char_generator, sizeof(dspl_status.user_char_generator));
  if(error != sizeof(dspl_status.user_char_generator)) return;
  
  //System char and Russian ASCII area:
  error = tr_lcd_data_auto_write((uint8*)system_char_generator, sizeof(system_char_generator));
  if(error != sizeof(system_char_generator)) return;
  error = tr_lcd_offset_register_set((((uint16) START_ADR_GGRAM_AREA)>>11)&0x1F);
  if(error) return;
        
        //Recovery LCD mode:
        error = ph_lcd_mode(&dspl_status.mode);
  if(error) return;
        error = ph_lcd_cursor_position(dspl_status.cursor_axis.x, dspl_status.cursor_axis.y);
  if(error) return;
  ph_lcd_cursor_height(dspl_status.cursor_lines);
}
/**************************************************************************************************\
*   Инициализация дисплея
*--------------------------------------------------------------------------------------------------
*           RAM Interface:
*            ___________
*   0x0000  |           |
*           | TEXT AREA | (256 * 128) / (8 * 8) = 512 byte = 0x200
*           |___________| char font = 8 * 8 dots
*   0x0200  |           |
*           |  GRAPHIC  |  (256 * 128) / 8 dot = 4096 byte = 0x1000
*           |   AREA    |  graph unit = 8 * 1 dots
*           |___________|
*   0x1200  |\\\\\\\\\\\|
*           |  RESERVE  |
*           |___________|
*   0xFС00  |           |
*           |CGRAM AREA |
*   0xFFFF  |___________|
*
\***sss********************************************************************************************/
int32   ph_lcd_init_hardware()
{
  int32   error, size, ret_size;
  memset(&dspl_status, 0x0, sizeof(s_dspl_status));   
  //Set TEXT:
  error = tr_lcd_text_home_address_set(START_ADR_TEXT_AREA);
  if(error) return error;
  error = tr_lcd_text_area_set(LCD_COLUMN);
  if(error) return error;    

  //Set GRAPHIC:
  error = tr_lcd_graphic_home_address_set(START_ADR_GRAPH_AREA);
  if(error) return error;    
  error = tr_lcd_graphic_area_set(LCD_COLUMN);
  if(error) return error;    

  //Clear LCD memory:
  error = tr_lcd_address_pointer_set(0x0000);
  if(error) return error;
  error = tr_lcd_const_auto_write(0x0, 0xFFFF);
  if(error != 0xFFFF) return -1;

  //Set Char Generation:
  error = tr_lcd_address_pointer_set(START_ADR_GGRAM_AREA);
  if(error) return error;    
  //User char area:
  size = sizeof(dspl_status.user_char_generator);
  ret_size = tr_lcd_data_auto_write(dspl_status.user_char_generator, size);
  if(ret_size != size) return -1;
  //System char and Russian ASCII area:
  size = sizeof(system_char_generator);
  ret_size = tr_lcd_data_auto_write((uint8*)system_char_generator, size);
  if(ret_size != size) return -1;
  error = tr_lcd_offset_register_set((((uint16) START_ADR_GGRAM_AREA)>>11)&0x1F);
  if(error) return error;    

  //Set address pointer:
  error = tr_lcd_address_pointer_set(0x0000);
  if(error) return error;    

  //Text mode:
  error = tr_lcd_display_mode(0xC);
  if(error) return error;    
  error = tr_lcd_text_attribute_mode();
  return error;
}
/**************************************************************************************************\
*   Вывод символов на дисплей
\***sss********************************************************************************************/
int32 ph_lcd_clear_video_ram()
{
  int32 error;
  error = tr_lcd_address_pointer_set(START_ADR_TEXT_AREA);
  if(error) return error;
  error = tr_lcd_const_auto_write(0x00, LCD_TEXT_EOF);    
  if(error != LCD_TEXT_EOF) return DSPL_ER_DATA_AUTO_WRITE-error;    
  
  error = tr_lcd_address_pointer_set(START_ADR_GRAPH_AREA);
  if(error) return error;
  error = tr_lcd_const_auto_write(0x00, LCD_GRAPH_EOF);        
  if(error != LCD_GRAPH_EOF) return DSPL_ER_DATA_AUTO_WRITE-error;
  else return OSE_OK;
}
/**************************************************************************************************\
*   Вывод символов на дисплей
\***sss********************************************************************************************/
int32 ph_lcd_output_char(uint32 Address, uint8* Buf, uint32 Length, s_color* FG, s_color* BG)
{
  uint8   attribut, character;
  int32   output_char, output_attr, error;
  //Вывод аттрибутов:
  error = tr_lcd_address_pointer_set(START_ADR_GRAPH_AREA + Address);
  if(error) return 0;
  attribut  = (BG->color) ? TEXT_NORMAL : TEXT_REVERSE;
  attribut |= (FG->alpha) ? TEXT_BLINK  : 0;
  output_attr = tr_lcd_const_auto_write(attribut, Length);
  memset(&dspl_status.graph[Address], attribut, Length);
  if(output_attr != Length) return 0;
  //Вывод текста:
  error = tr_lcd_address_pointer_set(Address);
  if(error) return 0;
  character = (FG->color ^ BG->color) ? 1 : 0;
  if(character)   
  {
    for(int32 i=0 ; i<Length; i++)
    {
      if (Buf[i] < 0x20)     
        dspl_status.text[Address+i] =  Buf[i] + 0x60;
      else 
      if (Buf[i] < 0x80)    
        dspl_status.text[Address+i] =  Buf[i] - 0x20;
      else                    
        dspl_status.text[Address+i] =  Buf[i];
    }
    output_char = tr_lcd_data_auto_write(&dspl_status.text[Address], Length);
  }
  else
  {            
    memset(&dspl_status.text[Address], character, output_char);
    output_char = tr_lcd_const_auto_write(character, Length);
  }
  return  output_char;
}
/**************************************************************************************************\
*   Вывод символов на дисплей
\***sss********************************************************************************************/
int32 ph_lcd_output_data(uint32 Address, uint8* Buf, uint32 Length)
{
  int32 error;
  error = tr_lcd_address_pointer_set(START_ADR_GRAPH_AREA + Address);
  if(error) return 0;
  memcpy(&dspl_status.graph[Address], Buf, Length);
  return tr_lcd_data_auto_write(Buf, Length);
}
/**************************************************************************************************\
*   Установка режима дисплея
\***sss********************************************************************************************/
int32   ph_lcd_mode(s_mode* mode)
{
  int32 error;
  memcpy(&dspl_status.mode, mode, sizeof(s_mode));
  error = tr_lcd_display_mode(mode->graphic_display<<3|mode->text_display<<2|mode->cursor_display<<1|mode->cursor_blink);
  if(error) return error;
  switch ((mode->text_display<<1)|mode->graphic_display)
  {
    case 1: error = tr_lcd_or_mode(); break;
    case 2: error = tr_lcd_text_attribute_mode(); break;
    case 3: error = tr_lcd_text_attribute_mode(); break;
  }
  return error;
}
/**************************************************************************************************\
*   Установка позицию курсора
\***sss********************************************************************************************/
int32   ph_lcd_cursor_position(uint16 x, uint16 y)
{
  dspl_status.cursor_axis.x = x;
  dspl_status.cursor_axis.y = y;
  return tr_lcd_cursor_pointer_set(x, y);
}
/**************************************************************************************************\
*   Установка высоту курсора
\***sss********************************************************************************************/
int32   ph_lcd_cursor_height(uint8  number_line)
{
  dspl_status.cursor_lines = number_line;
  return tr_lcd_number_line_cursor(number_line);
}
/**************************************************************************************************\
*   Загрузка символов в символ-генератор
\***sss********************************************************************************************/
int32   ph_lcd_load_keygen(uint32 Address, uint8 CharCode, uint8* BufCharLine, int32 BufSize)
{
  int32 error;
  uint16 offset, size;
  offset = (CharCode - 0x80)<<3;
  error  = tr_lcd_address_pointer_set(START_ADR_GGRAM_AREA + offset);
  if(error) return error;
  size   = tr_lcd_data_auto_write(BufCharLine, BufSize);
  if(size != BufSize) return DSPL_ER_DATA_AUTO_WRITE-size;
  memcpy(&dspl_status.user_char_generator[offset], BufCharLine, BufSize);
  error  = tr_lcd_address_pointer_set(Address);
  return error;
}
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//
//      Транспортный уровень драйвера   
//
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
#define MASK_DISPLAY_REDY                   (0x1)
#define MASK_DISPLAY_POWER                  (0x4)
#define DISPLAY_READY                       (REG_DEVICE_STATUS & MASK_DISPLAY_REDY)
#define DISPLAY_POWER                       (REG_DEVICE_STATUS & MASK_DISPLAY_POWER)

#define CMD_SET_CURSOR_POINTER              0x21
#define CMD_SET_OFFSET_REGISTER             0x22
#define CMD_SET_ADDRESS_POINTER             0x24

#define CMD_SET_TEXT_HOME_ADDRESS           0x40
#define CMD_SET_TEXT_AREA                   0x41
#define CMD_SET_GRAPHIC_HOME_ADDRESS        0x42
#define CMD_SET_GRAPHIC_AREA                0x43

#define CMD_OR_MODE                         0x80
#define CMD_EXOR_MODE                       0x81
#define CMD_AND_MODE                        0x83
#define CMD_TEXT_ATTRIBUTE_MODE             0x84
#define CMD_INTERNAL_CG_ROM_MODE            0x80
#define CMD_EXTERNAL_CG_RAM_MODE            0x88

#define CMD_DISPLAY_MODE                    0x90
#define CMD_DISPLAY_OFF                     0x90
#define CMD_CURSOR_ON_BLINK_OFF             0x92
#define CMD_CURSOR_ON_BLINK_ON              0x93
#define CMD_TEXT_ON_GRAPHIC_OFF             0x94
#define CMD_TEXT_OFF_GRAPHIC_ON             0x98
#define CMD_TEXT_ON_GRAPHIC_ON              0x9C

#define CMD_LINE_1_CURSOR                   0xA0
#define CMD_LINE_2_CURSOR                   0xA1
#define CMD_LINE_3_CURSOR                   0xA2
#define CMD_LINE_4_CURSOR                   0xA3
#define CMD_LINE_5_CURSOR                   0xA4
#define CMD_LINE_6_CURSOR                   0xA5
#define CMD_LINE_7_CURSOR                   0xA6
#define CMD_LINE_8_CURSOR                   0xA7

#define CMD_SET_DATA_AUTO_WRITE             0xB0
#define CMD_SET_DATA_AUTO_READ              0xB1
#define CMD_AUTO_RESET                      0xB2

#define CMD_DATA_WRITE_AND_INCREMENT_ADP    0xC0
#define CMD_DATA_READ_AND_INCREMENT_ADP     0xC1
#define CMD_DATA_WRITE_AND_DECREMENT_ADP    0xC2
#define CMD_DATA_READ_AND_DECREMENT_ADP     0xC3
#define CMD_DATA_WRITE_AND_NONVARIABLE_ADP  0xC4
#define CMD_DATA_READ_AND_NONVARIABLE_ADP   0xC5

#define CMD_SCREEN_PEEK                     0xE0
#define CMD_SCREEN_COPY                     0xE8

int32   status_check()
{
  if(!DISPLAY_POWER) return 0x0;
  register uint64   current_time, limit_time;
  register uint32   device_status;
  register uint32   time_out = 0;
  
  limit_time = time_core()+1500;
  while(true)
  {
    device_status = REG_DEVICE_STATUS;
    if(time_out == 1) break;
    if(device_status & MASK_DISPLAY_REDY) break;
    
    current_time = time_core();
    if(current_time >= limit_time)
    {
      time_out = 1;
      #ifdef DRV_LCD_NEED_LOG
      syslog(LOG_ERR, "drv_lcd error: no display status \nLT:0x%016llX \nCT:0x%016llX \nREG_DEVICE_STATUS: 0x%04X", limit_time, current_time, device_status);
      #endif
    }
  }
  return time_out;
}
//----  Register set ------------------------------------------------------------------------------
#ifdef DRV_LCD_NEED_LOG
const char* _drv_lcd_str__cursor_pointer_set = "drv_lcd error: cursor pointer set";
#endif
int32 tr_lcd_cursor_pointer_set(uint16 X,uint16 Y)                                          
{   
  register int32 error;
  error = status_check(); REG_DISPL_DATA = X;
  if(error)
  {
    #ifdef DRV_LCD_NEED_LOG
    syslog(LOG_ERR, _drv_lcd_str__cursor_pointer_set);
    #endif
    return DSPL_ER_CURSOR_POINTER_SET;
  }
  error = status_check(); REG_DISPL_DATA = Y;                                 
  if(error)
  {
    #ifdef DRV_LCD_NEED_LOG
    syslog(LOG_ERR, _drv_lcd_str__cursor_pointer_set);
    #endif
    return DSPL_ER_CURSOR_POINTER_SET;
  }
  error = status_check(); REG_DISPL_COMMAND = CMD_SET_CURSOR_POINTER;
  if(error)
  {
    #ifdef DRV_LCD_NEED_LOG
    syslog(LOG_ERR, _drv_lcd_str__cursor_pointer_set);
    #endif
    return DSPL_ER_CURSOR_POINTER_SET;
  }
  else return OSE_OK;
}
#ifdef DRV_LCD_NEED_LOG
const char* _drv_lcd_str__offset_register_set = "drv_lcd error: offset register set";
#endif
int32 tr_lcd_offset_register_set(uint8 Offset)                                             
{
  register int32 error;                                                                                                                                         
  error = status_check(); REG_DISPL_DATA = Offset&0xFF;
  if(error) 
  {
    #ifdef DRV_LCD_NEED_LOG
    syslog(LOG_ERR, _drv_lcd_str__offset_register_set);
    #endif
    return DSPL_ER_OFFSET_REGISTER_SET;
  }
  error = status_check(); REG_DISPL_DATA = 0x00;
  if(error) 
  {
    #ifdef DRV_LCD_NEED_LOG
    syslog(LOG_ERR, _drv_lcd_str__offset_register_set);
    #endif
    return DSPL_ER_OFFSET_REGISTER_SET;
  }
  error = status_check(); REG_DISPL_COMMAND = CMD_SET_OFFSET_REGISTER;        
  if(error) 
  {
    #ifdef DRV_LCD_NEED_LOG
    syslog(LOG_ERR, _drv_lcd_str__offset_register_set);
    #endif
    return DSPL_ER_OFFSET_REGISTER_SET;
  }
  else return OSE_OK;
}
#ifdef DRV_LCD_NEED_LOG
const char* _drv_lcd_str__address_pointer_set = "drv_lcd error: address pointer set";
#endif
int32 tr_lcd_address_pointer_set(uint16 Address)                                            
{
  register int32 error;                                                                      
  error = status_check(); REG_DISPL_DATA = Address&0xFF;                      
  if(error) 
  {
    #ifdef DRV_LCD_NEED_LOG
    syslog(LOG_ERR, _drv_lcd_str__address_pointer_set);
    #endif
    return DSPL_ER_ADDRESS_POINTER_SET;
  }      
  error = status_check(); REG_DISPL_DATA = (Address>>0x8)&0xFF;               
  if(error) 
  { 
    #ifdef DRV_LCD_NEED_LOG
    syslog(LOG_ERR, _drv_lcd_str__address_pointer_set);
    #endif
    return DSPL_ER_ADDRESS_POINTER_SET;
  }      
  error = status_check(); REG_DISPL_COMMAND = CMD_SET_ADDRESS_POINTER;        
  if(error) 
  {
    #ifdef DRV_LCD_NEED_LOG
    syslog(LOG_ERR, _drv_lcd_str__address_pointer_set);
    #endif
    return DSPL_ER_ADDRESS_POINTER_SET;
  }      
  else return OSE_OK; 
}

//----- Control Word Set --------------------------------------------------------------------------
#ifdef DRV_LCD_NEED_LOG
const char* _drv_lcd_str__text_home_address_set = "drv_lcd error: text home address set";
#endif
int32 tr_lcd_text_home_address_set(uint16 Address)                                          
{
  register int32 error;                                                                      
  error = status_check(); REG_DISPL_DATA = Address&0xFF;                      
  if(error) 
  {
    #ifdef DRV_LCD_NEED_LOG
    syslog(LOG_ERR, _drv_lcd_str__text_home_address_set);
    #endif
    return DSPL_ER_TEXT_HOME_ADDRESS_SET;
  }
  error = status_check(); REG_DISPL_DATA = (Address>>0x8)&0xFF;               
  if(error) 
  {
    #ifdef DRV_LCD_NEED_LOG
    syslog(LOG_ERR, _drv_lcd_str__text_home_address_set);
    #endif
    return DSPL_ER_TEXT_HOME_ADDRESS_SET;
  }
  error = status_check(); REG_DISPL_COMMAND = CMD_SET_TEXT_HOME_ADDRESS;      
  if(error) 
  {
    #ifdef DRV_LCD_NEED_LOG
    syslog(LOG_ERR, _drv_lcd_str__text_home_address_set);
    #endif
    return DSPL_ER_TEXT_HOME_ADDRESS_SET;
  }
  else return OSE_OK;
}
#ifdef DRV_LCD_NEED_LOG
const char* _drv_lcd_str__text_area_set = "drv_lcd error: text area set";
#endif
int32 tr_lcd_text_area_set(uint16 Columns)                                                  
{                                                                       
  register int32 error;                                                                      
  error = status_check(); REG_DISPL_DATA = Columns&0xFF;                      
  if(error) 
  {
    #ifdef DRV_LCD_NEED_LOG
    syslog(LOG_ERR, _drv_lcd_str__text_area_set);
    #endif
    return DSPL_ER_TEXT_AREA_SET;
  }      
  error = status_check(); REG_DISPL_DATA = 0x00;                              
  if(error) 
  {
    #ifdef DRV_LCD_NEED_LOG
    syslog(LOG_ERR, _drv_lcd_str__text_area_set);
    #endif
    return DSPL_ER_TEXT_AREA_SET;
  }      
  error = status_check(); REG_DISPL_COMMAND = CMD_SET_TEXT_AREA;              
  if(error) 
  {
    #ifdef DRV_LCD_NEED_LOG
    syslog(LOG_ERR, _drv_lcd_str__text_area_set);
    #endif
    return DSPL_ER_TEXT_AREA_SET;
  }      
  else return OSE_OK;
}
#ifdef DRV_LCD_NEED_LOG
const char* _drv_lcd_str__graphic_home_address_set = "drv_lcd error: graphic home address set";
#endif
int32 tr_lcd_graphic_home_address_set(uint16 Address)                                       
{                                                                       
  register int32 error;                                                                      
  error = status_check(); REG_DISPL_DATA = Address&0xFF;                      
  if(error) 
  {
    #ifdef DRV_LCD_NEED_LOG
    syslog(LOG_ERR, _drv_lcd_str__graphic_home_address_set);
    #endif
    return DSPL_ER_GRAPHIC_HOME_ADDRESS_SET;
  }
  error = status_check(); REG_DISPL_DATA = (Address>>0x8)&0xFF;               
  if(error) 
  {
    #ifdef DRV_LCD_NEED_LOG
    syslog(LOG_ERR, _drv_lcd_str__graphic_home_address_set);
    #endif
    return DSPL_ER_GRAPHIC_HOME_ADDRESS_SET;
  }
  error = status_check(); REG_DISPL_COMMAND = CMD_SET_GRAPHIC_HOME_ADDRESS;   
  if(error) 
  {
    #ifdef DRV_LCD_NEED_LOG
    syslog(LOG_ERR, _drv_lcd_str__graphic_home_address_set);
    #endif
    return DSPL_ER_GRAPHIC_HOME_ADDRESS_SET;
  }
  else return OSE_OK;
}
#ifdef DRV_LCD_NEED_LOG
const char* _drv_lcd_str__graphic_area_set = "drv_lcd error: graphic area set";
#endif
int32 tr_lcd_graphic_area_set(uint16 Columns)                                               
{                                                                       
  register int32 error;                                                                      
  error = status_check(); REG_DISPL_DATA = Columns&0xFF;                      
  if(error) 
  {
    #ifdef DRV_LCD_NEED_LOG
    syslog(LOG_ERR, _drv_lcd_str__graphic_area_set);
    #endif
    return DSPL_ER_GRAPHIC_AREA_SET;
  }
  error = status_check(); REG_DISPL_DATA = 0x00;                              
  if(error) 
  {
    #ifdef DRV_LCD_NEED_LOG
    syslog(LOG_ERR, _drv_lcd_str__graphic_area_set);
    #endif
    return DSPL_ER_GRAPHIC_AREA_SET;
  }
  error = status_check(); REG_DISPL_COMMAND = CMD_SET_GRAPHIC_AREA;           
  if(error) 
  {
    #ifdef DRV_LCD_NEED_LOG
    syslog(LOG_ERR, _drv_lcd_str__graphic_area_set);
    #endif
    return DSPL_ER_GRAPHIC_AREA_SET;
  }
  else return OSE_OK;
}

//----- Mode set ----------------------------------------------------------------------------------
#ifdef DRV_LCD_NEED_LOG
const char* _drv_lcd_str__or_mode_set = "drv_lcd error: or mode set";
#endif
int32 tr_lcd_or_mode()              
{
  register int32 error;                                                                      
  error = status_check(); REG_DISPL_COMMAND = CMD_OR_MODE; 
  if(error) 
  {
    #ifdef DRV_LCD_NEED_LOG
    syslog(LOG_ERR, _drv_lcd_str__or_mode_set);
    #endif
    return DSPL_ER_OR_MODE_SET;
  }
  else return OSE_OK;
}
#ifdef DRV_LCD_NEED_LOG
const char* _drv_lcd_str__exor_mode_set = "drv_lcd error: exor mode set";
#endif
int32 tr_lcd_exor_mode()            
{
  register int32 error;                                                                      
  error = status_check(); REG_DISPL_COMMAND = CMD_EXOR_MODE; 
  if(error) 
  {
    #ifdef DRV_LCD_NEED_LOG
    syslog(LOG_ERR, _drv_lcd_str__exor_mode_set);
    #endif
    return DSPL_ER_EXOR_MODE_SET;
  }
  else return OSE_OK;
}
#ifdef DRV_LCD_NEED_LOG
const char* _drv_lcd_str__and_mode_set = "drv_lcd error: and mode set";
#endif
int32 tr_lcd_and_mode()             
{
  register int32 error;                                                                      
  error = status_check(); REG_DISPL_COMMAND = CMD_AND_MODE; 
  if(error) 
  {
    #ifdef DRV_LCD_NEED_LOG
    syslog(LOG_ERR, _drv_lcd_str__and_mode_set);
    #endif
    return DSPL_ER_AND_MODE_SET;
  }
  else return OSE_OK;
}
#ifdef DRV_LCD_NEED_LOG
const char* _drv_lcd_str__text_attribute_mode_set = "drv_lcd error: text attribute mode set";
#endif
int32 tr_lcd_text_attribute_mode()  
{
  register int32 error;                                                                      
  error = status_check(); REG_DISPL_COMMAND = CMD_TEXT_ATTRIBUTE_MODE; 
  if(error) 
  {
    #ifdef DRV_LCD_NEED_LOG
    syslog(LOG_ERR, _drv_lcd_str__text_attribute_mode_set);
    #endif
    return DSPL_ER_TEXT_ATTR_MODE_SET;
  }
  else return OSE_OK;
}
#ifdef DRV_LCD_NEED_LOG
const char* _drv_lcd_str__internal_cg_rom_mode_set = "drv_lcd error: internal cg rom mode set";
#endif
int32 tr_lcd_internal_cg_rom_mode() 
{
  register int32 error;                                                                      
  error = status_check(); REG_DISPL_COMMAND = CMD_INTERNAL_CG_ROM_MODE; 
  if(error) 
  {
    #ifdef DRV_LCD_NEED_LOG
    syslog(LOG_ERR, _drv_lcd_str__internal_cg_rom_mode_set);
    #endif
    return DSPL_ER_INT_CG_ROM_MODE_SET;
  }
  else return OSE_OK;
}
#ifdef DRV_LCD_NEED_LOG
const char* _drv_lcd_str__external_cg_ram_mode_set = "drv_lcd error: external cg ram mode set";
#endif
int32 tr_lcd_external_cg_ram_mode() 
{
  register int32 error;                                                                      
  error = status_check(); REG_DISPL_COMMAND = CMD_EXTERNAL_CG_RAM_MODE; 
  if(error) 
  {
    #ifdef DRV_LCD_NEED_LOG
    syslog(LOG_ERR, _drv_lcd_str__external_cg_ram_mode_set);
    #endif
    return DSPL_ER_EXT_CG_RAM_MODE_SET;
  }
  else return OSE_OK;
}

//----- Display Mode ------------------------------------------------------------------------------
#ifdef DRV_LCD_NEED_LOG
const char* _drv_lcd_str__display_mode_set = "drv_lcd error: display mode set";
#endif
int32 tr_lcd_display_mode(uint8 Mode)
{
  register int32 error;                                                                      
  error = status_check(); REG_DISPL_COMMAND = CMD_DISPLAY_MODE | Mode;
  if(error) 
  {
    #ifdef DRV_LCD_NEED_LOG
    syslog(LOG_ERR, _drv_lcd_str__display_mode_set);
    #endif
    return DSPL_ER_DISPLAY_MODE;
  }
  else return OSE_OK;
}

//----- Cursor Patter Select ----------------------------------------------------------------------
#ifdef DRV_LCD_NEED_LOG
const char* _drv_lcd_str__cursor_pattern_select = "drv_lcd error: cursor pattern select";
#endif
int32 tr_lcd_number_line_cursor(uint8 NumberLine)                                                  
{                                                                               
  register int32 error;                                                                      
  register int32 NumLine = NumberLine;                                                   
  switch(NumLine)                                                             
  {                                                                           
      case 1:  error = status_check(); REG_DISPL_COMMAND = CMD_LINE_1_CURSOR; break;  
      case 2:  error = status_check(); REG_DISPL_COMMAND = CMD_LINE_2_CURSOR; break;  
      case 3:  error = status_check(); REG_DISPL_COMMAND = CMD_LINE_3_CURSOR; break;  
      case 4:  error = status_check(); REG_DISPL_COMMAND = CMD_LINE_4_CURSOR; break;  
      case 5:  error = status_check(); REG_DISPL_COMMAND = CMD_LINE_5_CURSOR; break;  
      case 6:  error = status_check(); REG_DISPL_COMMAND = CMD_LINE_6_CURSOR; break;  
      case 7:  error = status_check(); REG_DISPL_COMMAND = CMD_LINE_7_CURSOR; break;  
      case 8:  error = status_check(); REG_DISPL_COMMAND = CMD_LINE_8_CURSOR; break;  
      default: error = status_check(); REG_DISPL_COMMAND = CMD_LINE_1_CURSOR; break;  
  }
  if(error) 
  { 
    #ifdef DRV_LCD_NEED_LOG
    syslog(LOG_ERR, _drv_lcd_str__cursor_pattern_select);
    #endif
    return DSPL_ER_CURSOR_PATTERN_SELECT;
  }
  else return OSE_OK;
}

//----- Data Auto Read/Write ----------------------------------------------------------------------
int32   tr_lcd_data_auto_write(uint8* Buf, uint32 Length)
{
  #ifdef DRV_LCD_NEED_LOG
  register uint8 before_data = 0xBB;
  #endif
  register int32 error;
  register int32 i = 0;
  error = status_check(); REG_DISPL_COMMAND = CMD_SET_DATA_AUTO_WRITE;
  if(error) return i;
  for(;i<Length; i++)
  {
    error = status_check(); REG_DISPL_DATA = Buf[i];
    if(error) 
    {
      #ifdef DRV_LCD_NEED_LOG
      syslog(LOG_ERR, "drv_lcd error: data auto write after %d bytes, on 0x%02X data", i, before_data);
      #endif
      break;
    }
    #ifdef DRV_LCD_NEED_LOG
    before_data = Buf[i];  
    #endif      
  }
  status_check(); REG_DISPL_COMMAND = CMD_AUTO_RESET;
  return i;
}

int32   tr_lcd_const_auto_write(uint8 Const, uint32 Length)
{
  #ifdef DRV_LCD_NEED_LOG
  register uint8  before_const = 0xBB;
  #endif
  register int32  error;
  register int32  i = 0;
  error = status_check(); REG_DISPL_COMMAND = CMD_SET_DATA_AUTO_WRITE;
  if(error) return i;
  for(; i<Length; i++)
  {
    error = status_check(); REG_DISPL_DATA = Const;
    if(error) 
    {
      #ifdef DRV_LCD_NEED_LOG
      syslog(LOG_ERR, "drv_lcd error: const auto write after %d bytes, on 0x%02X data", i, before_const);
      #endif
      break;
    }
    #ifdef DRV_LCD_NEED_LOG
    before_const = Const;
    #endif
  }
  status_check(); REG_DISPL_COMMAND = CMD_AUTO_RESET;
  return i;
}
//----- Data Read/Write ---------------------------------------------------------------------------
#ifdef DRV_LCD_NEED_LOG
const char* _drv_lcd_str__data_write_inc = "drv_lcd error: data write and inc address";
#endif
int32 tr_lcd_data_write_inc(int8 Data)  
{
  register int32 error;                                                                      
  error = status_check(); REG_DISPL_DATA = Data&0xFF; 
  if(error)
  {
    #ifdef DRV_LCD_NEED_LOG
    syslog(LOG_ERR, _drv_lcd_str__data_write_inc);        
    #endif
    return DSPL_ER_DATA_WRITE_INC;
  }
  error = status_check(); REG_DISPL_COMMAND = CMD_DATA_WRITE_AND_INCREMENT_ADP;
  if(error)
  {
    #ifdef DRV_LCD_NEED_LOG 
    syslog(LOG_ERR, _drv_lcd_str__data_write_inc);        
    #endif
    return DSPL_ER_DATA_WRITE_INC;
  }
  else return OSE_OK;
}
#ifdef DRV_LCD_NEED_LOG
const char* _drv_lcd_str__data_write_dec = "drv_lcd error: data write and dec address";
#endif
int32 tr_lcd_data_write_dec(int8 Data)  
{
  register int32 error;                                                                      
  error = status_check(); REG_DISPL_DATA = Data&0xFF; 
  if(error)
  {
    #ifdef DRV_LCD_NEED_LOG
    syslog(LOG_ERR, _drv_lcd_str__data_write_dec);        
    #endif
    return DSPL_ER_DATA_WRITE_DEC;
  }
  error = status_check(); REG_DISPL_COMMAND = CMD_DATA_WRITE_AND_DECREMENT_ADP;
  if(error)
  {
    #ifdef DRV_LCD_NEED_LOG
    syslog(LOG_ERR, _drv_lcd_str__data_write_dec);        
    #endif
    return DSPL_ER_DATA_WRITE_DEC;
  }
  else return OSE_OK;
}
#ifdef DRV_LCD_NEED_LOG
const char* _drv_lcd_str__data_write_non = "drv_lcd error: data write";
#endif
int32 tr_lcd_data_write_non(int8 Data)  
{
  register int32 error;                                                                      
  error  = status_check(); REG_DISPL_DATA = Data&0xFF; 
  if(error) 
  {
    #ifdef DRV_LCD_NEED_LOG
    syslog(LOG_ERR, _drv_lcd_str__data_write_non);        
    #endif
    return DSPL_ER_DATA_WRITE_NON;
  }      
  error = status_check(); REG_DISPL_COMMAND = CMD_DATA_WRITE_AND_NONVARIABLE_ADP;
  if(error) 
  {
    #ifdef DRV_LCD_NEED_LOG
    syslog(LOG_ERR, _drv_lcd_str__data_write_non);        
    #endif
    return DSPL_ER_DATA_WRITE_NON;
  }      
  else return OSE_OK;
}
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//
//      Функции прямого доступа к дисплею   
//
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
static const char  gen_char[] = 
{
 0x00, 0x00, 0x07, 0x08, 0x10, 0x20, 0x20, 0x20, //0x80  CHAR_LEFT_UP_CORNER   
 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, //0x81  CHAR_UP_BORDER        
 0x00, 0x00, 0xE0, 0x10, 0x08, 0x04, 0x04, 0x04, //0x82  CHAR_RIGHT_UP_CORNER  
 0x20, 0x20, 0x20, 0x10, 0x08, 0x07, 0x00, 0x00, //0x83  CHAR_LEFT_DOWN_CORNER 
 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, //0x84  CHAR_DOWN_BORDER      
 0x04, 0x04, 0x04, 0x08, 0x10, 0xE0, 0x00, 0x00, //0x85  CHAR_RIGHT_DOWN_CORNER
 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, //0x86  CHAR_LEFT_BORDER      
 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04  //0x87  CHAR_RIGHT_BORDER     
};
/**************************************************************************************************\
*   Установка графического режима
\***sss********************************************************************************************/
void drv_lcd_direct_set_graph_mode()
{
  tr_lcd_display_mode(0x8);
  tr_lcd_or_mode();
}
/**************************************************************************************************\
*   Установка графического и текстового режима
\***sss********************************************************************************************/
void drv_lcd_direct_set_graph_text_mode()
{
  tr_lcd_display_mode(0xC);
  tr_lcd_exor_mode();
  //Clear LCD memory:
  tr_lcd_address_pointer_set(0x0000);
  tr_lcd_const_auto_write(0x0, 0x200);
  ph_lcd_load_keygen(0x0, 0x80, (uint8*)gen_char, sizeof(gen_char));
}
/**************************************************************************************************\
*   Вывод одного кадра 240х128 px (3840 Байт)
\***sss********************************************************************************************/
void drv_lcd_direct_out_frame(void* buf)
{
  tr_lcd_address_pointer_set(START_ADR_GRAPH_AREA);
  tr_lcd_data_auto_write((uint8*)buf, 3840);
}
/**************************************************************************************************\
*   Вывод одного кадра 240х128 px (3840 Байт)
\***sss********************************************************************************************/
static void drv_lcd_direct_print_str(const char* str, int32 addr)
{
  uint8* recast_str = (uint8*) str;
  int32 len = strlen(str);
  tr_lcd_address_pointer_set(addr);
  for(int32 i=0 ; i<len; i++)
  {
    if (recast_str[i] < 0x20) dspl_status.text[addr+i] = recast_str[i] + 0x60;
    else if (recast_str[i] < 0x80) dspl_status.text[addr+i] = recast_str[i] - 0x20;
    else dspl_status.text[addr+i] = recast_str[i];
  }
  tr_lcd_data_auto_write(&dspl_status.text[addr], len);
}
/*================================================================================================*/
void drv_lcd_direct_out_frame(void* buf, const char* str)
{
  char  up_line[24], down_line[24], text_line[24];
  
  tr_lcd_address_pointer_set(START_ADR_GRAPH_AREA);
  tr_lcd_data_auto_write((uint8*)buf, 3840);
  //set up line:
  up_line[0] = 0x80;
  memset(&up_line[1], 0x81, sizeof(up_line)-1-2);
  up_line[sizeof(up_line)-1-1] = 0x82;
  up_line[sizeof(up_line)-1] = 0x0;
  //set down line:
  down_line[0] = 0x83;
  memset(&down_line[1], 0x84, sizeof(down_line)-1-2);
  down_line[sizeof(down_line)-1-1] = 0x85;
  down_line[sizeof(down_line)-1] = 0x0;
  //set text line:
  text_line[0] = 0x86;
  memset(&text_line[1], ' ', sizeof(text_line)-1-2);
  memcpy(&text_line[(sizeof(text_line)>>1)-(strlen(str)>>1)-1], str, strlen(str));
  text_line[sizeof(text_line)-1-1] = 0x87;
  text_line[sizeof(text_line)-1] = 0x0;  

  drv_lcd_direct_print_str(up_line, 390);
  drv_lcd_direct_print_str(text_line, 420);
  drv_lcd_direct_print_str(down_line, 450);
}
#ifdef DRV_LCD_NEED_LOG
#undef DRV_LCD_NEED_LOG
#endif

