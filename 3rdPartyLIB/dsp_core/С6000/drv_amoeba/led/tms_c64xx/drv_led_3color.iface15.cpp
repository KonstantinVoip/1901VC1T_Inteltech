//**************************************************************************************************
//                         Copyright (C) 2010 RCZI
//--------------------------------------------------------------------------------------------------
// FILENAME....... drv_led.h
// DATE CREATED... 15/04/2010
// LAST MODIFIED.. 15/04/2010
// DRIVER VERSION. 1.0
//--------------------------------------------------------------------------------------------------
//  Содержимое папки: /dev/led
//              ..
//  <FILE>      abonent
//  <FILE>      channel
//--------------------------------------------------------------------------------------------------
//                   3   C O L O R   L E D   D R I V E R
//--------------------------------------------------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: Переферийная плата M-448-1.5
//
// !: codepage: cp1251 
//
// !: d: Драйвер трехцветных светодиодов.<br>
// !: -:
// !: md: Устройство (файл) светодиод в ОС связан с собственным файлом. 
// !: md: Путь к устройству: "/dev/led/abonent", "/dev/led/channel". 
// !: md: Драйвер реализует стандартный интерфейс взаимодействия пользователя 
// !: md: с устройством по средствам потокового чтения из устройства (файла).
//***sss********************************************************************************************
#include    <rts.h>
#include    <mem_fpga.iface15.h>
//--------------------------------------------------------------------------------------------------
int32 led_init_driver();
int32 led_deinit_driver();
int32 led_init_descriptor(s_os_driver_descriptor* d);
int32 led_deinit_descriptor(s_os_driver_descriptor* d);
int32 led_inode_select(s_os_driver_descriptor* d, char* name);
int32 led_inode_list(s_os_driver_descriptor* d, s_inode* *arg);
int32 led_set_color(s_os_driver_descriptor* d, uint32* color);
int32 led_get_color(s_os_driver_descriptor* d, uint32* color);

//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//          Интерфейсные функции драйвера
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//**************************************************************************************************
//       Открытие потока
//-------------------------------------------------------------------------------------------------
// !: fn: int32 led_open(s_os_driver_descriptor* d, uint16 access)
//
// !: d: Функция драйвером не поддерживаеться.<br> 
// !: -:
//***sss********************************************************************************************
int32 led_open(s_os_driver_descriptor* d, uint16 access)
{
  return -1;
}
//**************************************************************************************************
//       Закрытие потока
//-------------------------------------------------------------------------------------------------
// !: fn: int32 led_close(s_os_driver_descriptor* d)
//
// !: d: Функция драйвером не поддерживаеться.<br> 
// !: -:
//***sss********************************************************************************************
int32 led_close(s_os_driver_descriptor* d)
{
  return -1;
}
//**************************************************************************************************
//       Чтение из потока
//-------------------------------------------------------------------------------------------------
// !: fn: int32 led_read(s_os_driver_descriptor* d, void* buf, int32 length)
//
// !: d: Функция драйвером не поддерживаеться.<br> 
// !: -:
//***sss********************************************************************************************
int32 led_read(s_os_driver_descriptor* d, void* buf, int32 length)
{
  return -1;
}
//**************************************************************************************************
//       Запись в поток
//-------------------------------------------------------------------------------------------------
// !: fn: int32 led_write(s_os_driver_descriptor* d, const void* buf, int32 length)
//
// !: d: Функция драйвером не поддерживаеться.<br> 
// !: -:
//***sss********************************************************************************************
int32 led_write(s_os_driver_descriptor* d, const void* buf, int32 length)
{
  return -1;
}
//**************************************************************************************************
//       Управление вводом/выводом
//-------------------------------------------------------------------------------------------------
// !: fn: int32 led_ioctl(s_os_driver_descriptor* d, int32 cmd, const void* arg)
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
// !: d:   IOC_INODE_SELECT, IOC_INODE_LIST.<br><br>  
//
// !: d: Дополнительные команды управления:<br><br>
// !: d: 
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
// !: d:   LED_SETCOLOR
// !: d:   </td> 
// !: d:   <td valign=top>
// !: d:   uint32
// !: d:   </td> 
// !: d:   <td valign=top>
// !: d:   Установка цвета светодиода. Аргумент функции - указатель на uint32, содержащий 8-битную политру цвета в формате RRGGBBh.
// !: d:   </td>
//
// !: d: <tr>
// !: d:   <td valign=top>
// !: d:   LED_GETCOLOR
// !: d:   </td> 
// !: d:   <td valign=top>
// !: d:   uint32
// !: d:   </td> 
// !: d:   <td valign=top>
// !: d:   Взятие цвета светодиода.
// !: d:   </td>
// !: d: </tr>
//
// !: d: </table>
// !: -:
//***sss********************************************************************************************
int32 led_ioctl(s_os_driver_descriptor* d, int32 cmd, const void* arg)
{
  switch( cmd )
  {
    //===============================================================
    //Standard control command:
    //Инициализация:
    case IOC_INIT:  
      return led_init_driver();

    //Деинициализация:
    case IOC_DEINIT:            
      return led_deinit_driver();

    //Инициализация данных:
    case IOC_INIT_DESCRIPTOR:
      return led_init_descriptor(d);
      

    //Деинициализация данных:
    case IOC_DEINIT_DESCRIPTOR: 
      return led_deinit_descriptor(d);

    //Переход по директориям в корне драйвера:
    case IOC_INODE_SELECT:      
      return led_inode_select(d, (char*)arg);
     
    //Получение списка файлов:
    case IOC_INODE_LIST:
      return led_inode_list(d, (s_inode**)arg);
    
    //===============================================================
    //Driver self control command:
    case LED_SETCOLOR:
      return led_set_color(d, (uint32*)arg);

    case LED_GETCOLOR:
      return led_get_color(d, (uint32*)arg);
    
    default: return OSE_BAD_PARAM;
  } 
}       
//**************************************************************************************************
//      Добавить драйвер в систему
//-------------------------------------------------------------------------------------------------
// !: fn: int32 drv_led_plug()
//
// !: d: Добавляет драйвер дисплея в систему<br><br> 
//
// !: d: Возвращаемые значения:<br>
// !: d: - Стандартные коды ошибок ioctl.<br>
//***sss********************************************************************************************
int32 drv_led_plug()
{
  return drv_plug("/dev/led", INOT_FOLDER, &led_open, &led_close, &led_read, &led_write, &led_ioctl, NULL, 0);
}
//*************************************************************************************************
//      Удалить драйвер из системы 
//-------------------------------------------------------------------------------------------------
// !: fn: int32 drv_led_unplug()
//
// !: d: Удаляет драйвер дисплея из системы<br><br> 
//
// !: d: Возвращаемые значения:<br>
// !: d: - Стандартные коды ошибок ioctl.<br>
//***sss********************************************************************************************
int32 drv_led_unplug()
{
  return drv_unplug("led");
}
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//     Внутренние функции драйвера
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
#define NUMBER_LEDS        2
#define ABONENT_NUM        0
#define CHANNEL_NUM        1

#define LED_COLOR_OFF      0
#define LED_COLOR_GREEN    1 
#define LED_COLOR_RED      2
#define LED_COLOR_ORANGE   3
//--------------------------------------------------------------------------------------------------
struct s_led_descriptor
{
   char     name[8];
   uint32   shift;
   uint32   color;
};
//--------------------------------------------------------------------------------------------------
static volatile bool     led_driver_init = false;
static s_led_descriptor  led[NUMBER_LEDS];
//--------------------------------------------------------------------------------------------------
int32              led_color_analysis(uint32 r, uint32 g, uint32 b);
s_led_descriptor*  get_led(const char* name);

void led_off(s_led_descriptor* led);
void led_red(s_led_descriptor* led);
void led_green(s_led_descriptor* led);
void led_orange(s_led_descriptor* led);
/**************************************************************************************************\
*   Инициализация драйвера
\***sss********************************************************************************************/
int32 led_init_driver()
{
  if(led_driver_init == false)
  {
    REG_LED = 0x0;
    strcpy(led[ABONENT_NUM].name, "abonent");
    strcpy(led[CHANNEL_NUM].name, "channel");
    led[ABONENT_NUM].shift = 0;
    led[CHANNEL_NUM].shift = 2;
    led[ABONENT_NUM].color = 0;
    led[CHANNEL_NUM].color = 0;
    led_driver_init = true;
    return OSE_OK;
  }
  else
    return OSE_NO_DEVICE;
}
/**************************************************************************************************\
*   Деинициализация драйвера
\***sss********************************************************************************************/
int32 led_deinit_driver()
{
    led_driver_init = false;
    return OSE_OK;
}
/**************************************************************************************************\
*   Инициализация дескриптора
\***sss********************************************************************************************/
int32 led_init_descriptor(s_os_driver_descriptor* d)
{
  d->data = NULL;
  return OSE_OK;
}
/**************************************************************************************************\
*   Деинициализация дескриптора
\***sss********************************************************************************************/
int32 led_deinit_descriptor(s_os_driver_descriptor* d)
{
  d->data = NULL;
  return OSE_OK;
}
/**************************************************************************************************\
*   Переход по директориям в корне драйвера
\***sss********************************************************************************************/
int32 led_inode_select(s_os_driver_descriptor* d, char* name)
{
    s_led_descriptor* led; 
    
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
    if( ( (led = get_led(name)) != NULL ) && (d->data == NULL) )
    {
        drv_inc(d, name);
        d->data = led;
    }
    else
        return  OSE_NO_NODE;

    return OSE_OK;
}
/**************************************************************************************************\
*   Получение списка файлов
\***sss********************************************************************************************/
int32 led_inode_list(s_os_driver_descriptor* d, s_inode* *arg)
{
  if(d->data != NULL)
    return OSE_NO_NODE;
  s_inode*     node;
  s_inode*     first_node = NULL;
  s_inode*     last_node = NULL;
  
  for(int32 i=0; i<NUMBER_LEDS; i++)
  {
    node = new s_inode;
    if( node == NULL )
      return OSE_NO_MEMORY;
  
    node->name = new char[8];
    if(node->name == NULL)
    {
      delete node;
      return OSE_NO_MEMORY;
    }
  
    node->prev = NULL;
    node->next = NULL;
    strcpy(node->name, led[i].name);
    node->size = sizeof(void*);
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
  return OSE_OK;
}
/**************************************************************************************************\
*   Установить цвет светодиода
\***sss********************************************************************************************/
int32 led_set_color(s_os_driver_descriptor* d, uint32* color)
{
  if(d->data == NULL) return OSE_NO_NODE;
  if(color == NULL) return OSE_BAD_PARAM;
  int32  light;
  uint32 r, g, b;
  s_led_descriptor* led = (s_led_descriptor*)d->data;
  led->color = *color;
  r = (uint32)( (*color >> 16) & 0x000000FF );
  g = (int32)( (*color >> 8) & 0x000000FF );
  b = (int32)( *color & 0x000000FF );
  light = led_color_analysis(r, g, b);
  switch(light)
  {
    case LED_COLOR_OFF:    led_off(led);    break;
    case LED_COLOR_RED:    led_red(led);    break;
    case LED_COLOR_GREEN:  led_green(led);  break;
    case LED_COLOR_ORANGE: led_orange(led); break;
  }
  return OSE_OK;
}
/**************************************************************************************************\
*   Получить цвет светодиода
\***sss********************************************************************************************/
int32 led_get_color(s_os_driver_descriptor* d, uint32* color)
{
  if(d->data == NULL) return OSE_NO_NODE;
  if(color == NULL) return OSE_BAD_PARAM;
  *color = ((s_led_descriptor*)d->data)->color;
  return OSE_OK;
}
/**************************************************************************************************\
*   Выключить светодиод
\***sss********************************************************************************************/
void led_off(s_led_descriptor* led)
{
  uint16 reg_led = REG_LED;
  reg_led &= ~(0x3<<led->shift);
  reg_led |= (LED_COLOR_OFF<<led->shift);
  REG_LED = reg_led;
}
/**************************************************************************************************\
*   Включить красный светодиод
\***sss********************************************************************************************/
void led_red(s_led_descriptor* led)
{
  uint16 reg_led = REG_LED;
  reg_led &= ~(0x3<<led->shift);
  reg_led |= (LED_COLOR_RED<<led->shift);
  REG_LED = reg_led;
}
/**************************************************************************************************\
*   Включить зеленый светодиод
\***sss********************************************************************************************/
void led_green(s_led_descriptor* led)
{
  uint16 reg_led = REG_LED;
  reg_led &= ~(0x3<<led->shift);
  reg_led |= (LED_COLOR_GREEN<<led->shift);
  REG_LED = reg_led;
}
/**************************************************************************************************\
*   Включить оранжевый светодиод
\***sss********************************************************************************************/
void led_orange(s_led_descriptor* led)
{
  uint16 reg_led = REG_LED;
  reg_led &= ~(0x3<<led->shift);
  reg_led |= (LED_COLOR_ORANGE<<led->shift);
  REG_LED = reg_led;
}
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//     Сервисные функции драйвера
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
static int32 led_color_dist( int32 r1, int32 g1, int32 b1, int32 r2, int32 g2, int32 b2 )
{
  register int32 dr = r1 - r2;
  register int32 dg = g1 - g2;
  register int32 db = b1 - b2;
  return dr * dr + dg * dg + db * db;
}
/**************************************************************************************************\
*   Анализ цвета LED
\***sss********************************************************************************************/
int32 led_color_analysis(uint32 r, uint32 g, uint32 b)
{
  register int32  min;
  uint32          color[4];
  color[LED_COLOR_OFF] = led_color_dist( r, g, b, 0, 0, 0 );
  color[LED_COLOR_RED] = led_color_dist( r, g, b, 255, 0, 0 );
  color[LED_COLOR_GREEN] = led_color_dist( r, g, b, 0, 255, 0 );
  color[LED_COLOR_ORANGE] = led_color_dist( r, g, b, 255, 128, 0 );
  for(register int32 i=0; i<4; i++)
  {
    if(i != 0) 
    {
      if(color[i] < color[min])
        min = i;
    }
    else min = i;
  }
  return min;
}
/**************************************************************************************************\
*   Взять контекст LED
\***sss********************************************************************************************/
s_led_descriptor* get_led(const char* name)
{
  for(int32 i=0; i<NUMBER_LEDS; i++)
  {
    if(!strcmp(name, led[i].name))
      return &led[i];
  }
  return NULL;
}

