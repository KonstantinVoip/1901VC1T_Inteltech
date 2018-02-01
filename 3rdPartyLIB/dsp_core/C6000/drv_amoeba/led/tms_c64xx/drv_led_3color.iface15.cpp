//**************************************************************************************************
//                         Copyright (C) 2010 RCZI
//--------------------------------------------------------------------------------------------------
// FILENAME....... drv_led.h
// DATE CREATED... 15/04/2010
// LAST MODIFIED.. 15/04/2010
// DRIVER VERSION. 1.0
//--------------------------------------------------------------------------------------------------
//  ���������� �����: /dev/led
//              ..
//  <FILE>      abonent
//  <FILE>      channel
//--------------------------------------------------------------------------------------------------
//                   3   C O L O R   L E D   D R I V E R
//--------------------------------------------------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: ������������ ����� M-448-1.5
//
// !: codepage: cp1251 
//
// !: d: ������� ����������� �����������.<br>
// !: -:
// !: md: ���������� (����) ��������� � �� ������ � ����������� ������. 
// !: md: ���� � ����������: "/dev/led/abonent", "/dev/led/channel". 
// !: md: ������� ��������� ����������� ��������� �������������� ������������ 
// !: md: � ����������� �� ��������� ���������� ������ �� ���������� (�����).
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
//          ������������ ������� ��������
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//**************************************************************************************************
//       �������� ������
//-------------------------------------------------------------------------------------------------
// !: fn: int32 led_open(s_os_driver_descriptor* d, uint16 access)
//
// !: d: ������� ��������� �� ���������������.<br> 
// !: -:
//***sss********************************************************************************************
int32 led_open(s_os_driver_descriptor* d, uint16 access)
{
  return -1;
}
//**************************************************************************************************
//       �������� ������
//-------------------------------------------------------------------------------------------------
// !: fn: int32 led_close(s_os_driver_descriptor* d)
//
// !: d: ������� ��������� �� ���������������.<br> 
// !: -:
//***sss********************************************************************************************
int32 led_close(s_os_driver_descriptor* d)
{
  return -1;
}
//**************************************************************************************************
//       ������ �� ������
//-------------------------------------------------------------------------------------------------
// !: fn: int32 led_read(s_os_driver_descriptor* d, void* buf, int32 length)
//
// !: d: ������� ��������� �� ���������������.<br> 
// !: -:
//***sss********************************************************************************************
int32 led_read(s_os_driver_descriptor* d, void* buf, int32 length)
{
  return -1;
}
//**************************************************************************************************
//       ������ � �����
//-------------------------------------------------------------------------------------------------
// !: fn: int32 led_write(s_os_driver_descriptor* d, const void* buf, int32 length)
//
// !: d: ������� ��������� �� ���������������.<br> 
// !: -:
//***sss********************************************************************************************
int32 led_write(s_os_driver_descriptor* d, const void* buf, int32 length)
{
  return -1;
}
//**************************************************************************************************
//       ���������� ������/�������
//-------------------------------------------------------------------------------------------------
// !: fn: int32 led_ioctl(s_os_driver_descriptor* d, int32 cmd, const void* arg)
//
// !: d: ������� ��������� ����������� ����������� �� ����������
// !: d: � ������������ � �������� ��������.<br><br> 
//
// !: d: ������� ���������:<br>
// !: d: - d - ��������� �� ���������� ��������, ����������� ��;<br>
// !: d: - cmd - ������� ����������;<br>
// !: d: - arg - ��������.<br><br>
//
// !: d: ������������ ��������:<br>
// !: d: - ����������� ���� ������ ioctl.<br><br>
//
// !: d: ����������� ������� ����������:<br>
// !: d: - IOC_INIT, IOC_DEINIT, IOC_INIT_DESCRIPTOR, IOC_DEINIT_DESCRIPTOR,
// !: d:   IOC_INODE_SELECT, IOC_INODE_LIST.<br><br>  
//
// !: d: �������������� ������� ����������:<br><br>
// !: d: 
// !: d: <table cellpadding=10 cellspacing=0 border=0>
// !: d: <tr>
// !: d:   <td valign=top>
// !: d:   �������:
// !: d:   </td> 
// !: d:   <td valign=top>
// !: d:   ���&nbsp;���������:
// !: d:   </td>
// !: d:   <td valign=top>
// !: d:   ��������:
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
// !: d:   ��������� ����� ����������. �������� ������� - ��������� �� uint32, ���������� 8-������ ������� ����� � ������� RRGGBBh.
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
// !: d:   ������ ����� ����������.
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
    //�������������:
    case IOC_INIT:  
      return led_init_driver();

    //���������������:
    case IOC_DEINIT:            
      return led_deinit_driver();

    //������������� ������:
    case IOC_INIT_DESCRIPTOR:
      return led_init_descriptor(d);
      

    //��������������� ������:
    case IOC_DEINIT_DESCRIPTOR: 
      return led_deinit_descriptor(d);

    //������� �� ����������� � ����� ��������:
    case IOC_INODE_SELECT:      
      return led_inode_select(d, (char*)arg);
     
    //��������� ������ ������:
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
//      �������� ������� � �������
//-------------------------------------------------------------------------------------------------
// !: fn: int32 drv_led_plug()
//
// !: d: ��������� ������� ������� � �������<br><br> 
//
// !: d: ������������ ��������:<br>
// !: d: - ����������� ���� ������ ioctl.<br>
//***sss********************************************************************************************
int32 drv_led_plug()
{
  return drv_plug("/dev/led", INOT_FOLDER, &led_open, &led_close, &led_read, &led_write, &led_ioctl, NULL, 0);
}
//*************************************************************************************************
//      ������� ������� �� ������� 
//-------------------------------------------------------------------------------------------------
// !: fn: int32 drv_led_unplug()
//
// !: d: ������� ������� ������� �� �������<br><br> 
//
// !: d: ������������ ��������:<br>
// !: d: - ����������� ���� ������ ioctl.<br>
//***sss********************************************************************************************
int32 drv_led_unplug()
{
  return drv_unplug("led");
}
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//     ���������� ������� ��������
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
*   ������������� ��������
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
*   ��������������� ��������
\***sss********************************************************************************************/
int32 led_deinit_driver()
{
    led_driver_init = false;
    return OSE_OK;
}
/**************************************************************************************************\
*   ������������� �����������
\***sss********************************************************************************************/
int32 led_init_descriptor(s_os_driver_descriptor* d)
{
  d->data = NULL;
  return OSE_OK;
}
/**************************************************************************************************\
*   ��������������� �����������
\***sss********************************************************************************************/
int32 led_deinit_descriptor(s_os_driver_descriptor* d)
{
  d->data = NULL;
  return OSE_OK;
}
/**************************************************************************************************\
*   ������� �� ����������� � ����� ��������
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
*   ��������� ������ ������
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
*   ���������� ���� ����������
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
*   �������� ���� ����������
\***sss********************************************************************************************/
int32 led_get_color(s_os_driver_descriptor* d, uint32* color)
{
  if(d->data == NULL) return OSE_NO_NODE;
  if(color == NULL) return OSE_BAD_PARAM;
  *color = ((s_led_descriptor*)d->data)->color;
  return OSE_OK;
}
/**************************************************************************************************\
*   ��������� ���������
\***sss********************************************************************************************/
void led_off(s_led_descriptor* led)
{
  uint16 reg_led = REG_LED;
  reg_led &= ~(0x3<<led->shift);
  reg_led |= (LED_COLOR_OFF<<led->shift);
  REG_LED = reg_led;
}
/**************************************************************************************************\
*   �������� ������� ���������
\***sss********************************************************************************************/
void led_red(s_led_descriptor* led)
{
  uint16 reg_led = REG_LED;
  reg_led &= ~(0x3<<led->shift);
  reg_led |= (LED_COLOR_RED<<led->shift);
  REG_LED = reg_led;
}
/**************************************************************************************************\
*   �������� ������� ���������
\***sss********************************************************************************************/
void led_green(s_led_descriptor* led)
{
  uint16 reg_led = REG_LED;
  reg_led &= ~(0x3<<led->shift);
  reg_led |= (LED_COLOR_GREEN<<led->shift);
  REG_LED = reg_led;
}
/**************************************************************************************************\
*   �������� ��������� ���������
\***sss********************************************************************************************/
void led_orange(s_led_descriptor* led)
{
  uint16 reg_led = REG_LED;
  reg_led &= ~(0x3<<led->shift);
  reg_led |= (LED_COLOR_ORANGE<<led->shift);
  REG_LED = reg_led;
}
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//     ��������� ������� ��������
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
static int32 led_color_dist( int32 r1, int32 g1, int32 b1, int32 r2, int32 g2, int32 b2 )
{
  register int32 dr = r1 - r2;
  register int32 dg = g1 - g2;
  register int32 db = b1 - b2;
  return dr * dr + dg * dg + db * db;
}
/**************************************************************************************************\
*   ������ ����� LED
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
*   ����� �������� LED
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

