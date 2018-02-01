//*************************************************************************************************
//                        Copyright (C) 2009 RCZI
//-------------------------------------------------------------------------------------------------
// FILENAME....... drv_kbd_4x6.u32.cpp
// DATE CREATED... 22/03/2011
// LAST MODIFIED.. 22/03/2011
// DRIVER VERSION. 3.0
//-------------------------------------------------------------------------------------------------
//  ���������� �����: /dev/
//              ..
//  <FILE>      kbd[0-127]
//-------------------------------------------------------------------------------------------------
//  Mass Production Code: ����.468318.078
//-------------------------------------------------------------------------------------------------
//          4 x 6    K E Y S    K E Y B O A R D    D R I V E R
//-------------------------------------------------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
//
// !: codepage: cp1251 
//
// !: d: ������� ���������� (24 �������).<br>
// !: md: ���������� (����) � �� ������ � ����������� ������ kbdN,
// !: md: ��� N ��������� �������� �� 0 �� 127. ���� � ����������: 
// !: md: "/dev/kbd0", ���� ������� ��� ������ ����������� ��������� 
// !: md: ���������� � �������. ������� ��������� ����������� ��������� 
// !: md: �������������� ������������ � ����������� �� ��������� 
// !: md: ���������� ������ �� ���������� (�����) � ������� ����������� 
// !: md: ����������� �� ����������.<br>
// !: -:
//***sss********************************************************************************************
#include    <os.h>
#include    <rts.h>
#include    <drv_gpio.h>
#include    <mem_fpga.iface15.h>
#include    <drv_kbd_4x6.h>

#define NUM_KEY_IN_BUF   32
//I/O command function:
int32   kbd_4x6_init_driver(s_os_driver_context* ctx);                                               
int32   kbd_4x6_deinit_driver(s_os_driver_context* ctx);                                             
int32   kbd_4x6_init_descriptor();                           
int32   kbd_4x6_deinit_descriptor();                     
//DRV command function:
int32   kbd_4x6_get_key(uint32* key);
int32   kbd_4x6_imitation_press_key(uint32* key);
int32   kbd_4x6_probe_key(uint32* key);
//Kbd event function:
void    kbd_4x6_interrupt();

char    kbd_4x6_name[10];
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//
//          ������������ ������� ��������
//
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO

//**************************************************************************************************
//      �������� ������
//-------------------------------------------------------------------------------------------------
// !: fn: int32 kbd_4x6_open(s_os_driver_descriptor* d, uint16 access) 
//
// !: d: ������� ��������� �� ���������������.<br> 
// !: -:
//***sss********************************************************************************************
int32 kbd_4x6_open(s_os_driver_descriptor* d, uint16 access)
{
  return OSE_CANT_OPEN;
}
//**************************************************************************************************
//      �������� ������
//-------------------------------------------------------------------------------------------------
// !: fn: int32 kbd_4x6_close(s_os_driver_descriptor* d) 
//
//
// !: d: ������� ��������� �� ���������������.<br> 
// !: -:
//***sss********************************************************************************************
int32 kbd_4x6_close(s_os_driver_descriptor* d)
{
  return OSE_STREAM_NOT_OPENED;
}
//**************************************************************************************************
//      ������ �� ������
//-------------------------------------------------------------------------------------------------
// !: fn: int32 kbd_4x6_read(s_os_driver_descriptor* d, void* buf, int32 length) 
//
//
// !: d: ������� ��������� �� ���������������.<br> 
// !: -:
//***sss********************************************************************************************
int32 kbd_4x6_read(s_os_driver_descriptor* d, void* buf, int32 length)
{
  return OSE_PERMISSION_DENIED;
}
//**************************************************************************************************
//       ������ � �����
//-------------------------------------------------------------------------------------------------
// !: fn: int32 kbd_4x6_write(s_os_driver_descriptor* d, const void* buf, int32 length)
//
// !: d: ������� ��������� �� ���������������.<br> 
// !: -:
//***sss********************************************************************************************
int32 kbd_4x6_write(s_os_driver_descriptor* d, const void* buf, int32 length)
{
  return OSE_CANT_WRITE;
}
//**************************************************************************************************
//      ���������� ������/�������
//-------------------------------------------------------------------------------------------------
// !: fn: int32 kbd_4x6_ioctl(s_os_driver_descriptor* d, int32 cmd, const void* arg)
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
// !: d: - ����������� ���� ������ ioctl. ����������� �������� ������� KBD_HAVE_KEY.<br><br>
//
// !: d: ����������� ������� ����������:<br>
// !: d: - IOC_INIT, IOC_DEINIT, IOC_INIT_DESCRIPTOR, IOC_DEINIT_DESCRIPTOR,
// !: d:   IOC_INODE_SELECT.<br><br>
//
// !: d: �������������� ������� ����������:<br>
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
// !: d:   HID_GETEVENT
// !: d:   </td> 
// !: d:   <td valign=top>
// !: d:   uint32 
// !: d:   </td>
// !: d:   <td valign=top>
// !: d:   ������� ������� �������. ���������� ��� ������� ����������� 
// !: d:   �� ������, ����������� � ���������.
// !: d:   </td>
// !: d: </tr>
//
// !: d: <tr>
// !: d:   <td valign=top>
// !: d:   HID_IMTEVENT 
// !: d:   </td>
// !: d:   <td valign=top>
// !: d:   uint32 
// !: d:   </td>
// !: d:   <td valign=top>
// !: d:   ��������� ������� �������. ������������ 
// !: d:   ��� ����� � ��������� ����� �������� ����������, ������� � 
// !: d:   ������ ����������� � ���������.
// !: d:   </td>
// !: d: </tr>
//
// !: d: <tr>
// !: d:   <td valign=top>
// !: d:   HID_PRBEVENT
// !: d:   </td>
// !: d:   <td valign=top>
// !: d:   uint32
// !: d:   </td>
// !: d:   <td valign=top>
// !: d:   ��������� ������� ���� ������� � ��������� 
// !: d:   ������ �������� ����������. ���� ��� ����, ������� ��������� 
// !: d:   ��� �� ������, ����������� � ���������, ����� ��������� 0.<br>
// !: d:   </td>
// !: d: </tr>
// !: d: </table>
// !: -:
//***sss********************************************************************************************
int32 kbd_4x6_ioctl(s_os_driver_descriptor* d, int32 cmd, const void* arg)
{
  switch(cmd)
  {
    //Standard control command:
    case IOC_INIT: return kbd_4x6_init_driver((s_os_driver_context*)arg);
    case IOC_DEINIT: return kbd_4x6_deinit_driver((s_os_driver_context*)arg);
    case IOC_INIT_DESCRIPTOR: return kbd_4x6_init_descriptor();
    case IOC_DEINIT_DESCRIPTOR: return kbd_4x6_deinit_descriptor();
    case IOC_INODE_SELECT:      
    {   
      if(d->access & DRV_OPENED) return OSE_STREAM_OPENED;
      if(!strcmp((const char*)arg,".")) break;
      else if(!strcmp((const char*)arg,".."))
      {
        drv_dec(d);
        drv_rfs(d);
      }
      else return  OSE_NO_NODE;
    }
    break;
  
    //Driver self control command:
    case HID_GETEVENT: return kbd_4x6_get_key((uint32*)arg);
    case HID_IMTEVENT: return kbd_4x6_imitation_press_key((uint32*)arg);
    case HID_PRBEVENT: return kbd_4x6_probe_key((uint32*)arg);
    default: return OSE_BAD_CMD;
  }
  return OSE_OK;
}      
//**************************************************************************************************
//      �������� ������� � �������
//-------------------------------------------------------------------------------------------------
// !: fn: int32 drv_kbd_4x6_plug(uint32 number_gpio_interrupt)
//
// !: d: ��������� ������� ���������� � �������<br><br> 
//
// !: d: ������� ���������:<br>
// !: d: - number_gpio_interrupt - ����� GPIO - ��������� ����������.<br><br>
//
// !: d: ������������ ��������:<br>
// !: d: - ����������� ���� ������ ioctl.<br>
//***sss********************************************************************************************
int32 drv_kbd_4x6_plug(uint32 number_gpio_interrupt)
{
  int32   plug;
  char    path[20], number[5];
  for(int32 i=0;i<128;i++)
  {
    itoa(i, number);
    strcpy(path, "/dev/kbd");
    strcpy(kbd_4x6_name, "kbd");
    strcat(path, number);
    strcat(kbd_4x6_name, number);
    plug = drv_plug(path, INOT_FILE, &kbd_4x6_open, &kbd_4x6_close, &kbd_4x6_read, &kbd_4x6_write, &kbd_4x6_ioctl, &number_gpio_interrupt, sizeof(uint32));
    if(plug == 0x00) break;
  }
  return plug;
}
//**************************************************************************************************
//      ������� ������� �� ������� 
//-------------------------------------------------------------------------------------------------
// !: fn: int32 drv_kbd_4x6_unplug()
//
// !: d: ������� ������� ���������� �� �������.<br><br>
//
// !: d: ������������ ��������:<br>
// !: d: - ����������� ���� ������ ioctl.<br>
//***sss********************************************************************************************
int32 drv_kbd_4x6_unplug()
{
  return drv_unplug(kbd_4x6_name);
} 

//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//
//          ������� ��������
//
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
struct s_kbd_circ_buf
{
  uint32              count;  //������� ���������� ����;
  uint32              busy;   //������ ������� �������
  uint32              free;   //������ ��������� �������
  uint32              size;   //������ ������ � ������
  uint32*             buf;    //��������� �� �����
  uint32              sem;    //������� ������
};
struct s_kbd_inkey
{
  uint32      press_code;    
  uint32      unpress_code;
  uint32      sys_press_code;    
  uint32      sys_unpress_code;
};
//-------------------------------------------------------------------------------------------------
uint32                          sem_kbd;
s_kbd_circ_buf                  kbd_circ;
uint32                          kbd_sys_buf[3];
uint32                          kbd_driver_init = 0;
uint32                          kbd_descriptor_init = 0;
//-------------------------------------------------------------------------------------------------
uint32 sysb_kbd_analys(register uint32 key);
/**************************************************************************************************\
*   ������������� ��������
\***sss********************************************************************************************/
int32   kbd_4x6_init_driver(s_os_driver_context* ctx)
{
  if(!kbd_driver_init)
  {
    int32               error, stage; 
    uint32              file;
    s_gpio_interrupt    kbdgpio;
    stage = 0;
    //*** STAGE 1 ***
    //������������� ��������:
    sem_kbd = sem_alloc(1,NULL);
    if(sem_kbd == RES_VOID)
    {
      error = OSE_CANT_CREATE_SEM;
      stage = 1;
      goto m_return;
    }
    //*** STAGE 2,3 ***
    //������������� ���������� �� GPIO:
    kbdgpio.number_gpio = *(uint32*)ctx->data;
    kbdgpio.call_functoin = &kbd_4x6_interrupt;
    
    file = drv_mkd("/dev/gpio");
    if(file == RES_VOID)
    {
      error = OSE_NO_DEVICE;
      stage = 2;
      goto m_return;
    }
    
    error = drv_ioctl(file,GPIO_INT_ALLOC,&kbdgpio);
    drv_rmd(file);
    if(error)
    {
      stage = 3;
      goto m_return;
    }
    //*** STAGE 4,5 ***
    //������������� ������������ ������ ����������:
    kbd_circ.sem = sem_alloc(0,NULL);
    if(kbd_circ.sem == RES_VOID)
    {
      error = OSE_CANT_CREATE_SEM;
      stage = 4;
      goto m_return;
    }
    kbd_circ.buf = (uint32*)heap_alloc(NULL, sizeof(uint32)*NUM_KEY_IN_BUF, HEAP_ALIGN_4);
    if(kbd_circ.buf == NULL)
    {
      stage = 5;
      goto m_return;
    }
    kbd_circ.size  = NUM_KEY_IN_BUF;
    kbd_circ.count = 0;
    kbd_circ.busy  = 0;
    kbd_circ.free  = 0;
    //*** STAGE 6 ***
    //������������� ���������� ������ ����������:
    memset(kbd_sys_buf, 0x0, sizeof(kbd_sys_buf));
    
    kbd_driver_init = 1;
    error = OSE_OK;

    m_return:
    switch(stage)
    {
      case 5:
      case 4: sem_free(kbd_circ.sem);
      case 3: drv_ioctl(file,GPIO_INT_FREE,&kbdgpio);                   
      case 2: drv_rmd(file);
      case 1: sem_free(sem_kbd);
    }
    return error;
  }
  else return OSE_ALREADY_PLUGGED;
}
/**************************************************************************************************\
*   ��������������� ��������
\***sss********************************************************************************************/
int32   kbd_4x6_deinit_driver(s_os_driver_context* ctx)
{
  int32               error;
  s_gpio_interrupt    kbdgpio;
  //��������������� ���������� �� GPIO:
  kbdgpio.number_gpio = *(uint32*)ctx->data;
  kbdgpio.call_functoin = &kbd_4x6_interrupt;
  uint32 file = drv_mkd("/dev/gpio");
  error = drv_ioctl(file,GPIO_INT_FREE,&kbdgpio);
  drv_rmd(file);
  //��������������� ������������ ������ ����������:
  sem_free(kbd_circ.sem);
  heap_free(NULL,kbd_circ.buf);
  //��������������� ��������: 
  sem_free(sem_kbd);
  return error;
}
/**************************************************************************************************\
*   ������������� ����������� ����������
\***sss********************************************************************************************/
int32   kbd_4x6_init_descriptor()
{
  int32  error;
  if(!kbd_driver_init) return OSE_NO_DEVICE;
  sem_lock(sem_kbd,SEM_INFINITY);
  if(!kbd_descriptor_init)
  {
    kbd_descriptor_init = 1;
    error = OSE_OK;
  }
  else error = OSE_NO_DEVICE;
  sem_unlock(sem_kbd);
  return error;
}
/**************************************************************************************************\
*   ��������������� ����������� ����������
\***sss********************************************************************************************/
int32   kbd_4x6_deinit_descriptor()
{
  kbd_descriptor_init = 0;
  return OSE_OK;
}
/**************************************************************************************************\
*   ��������� ���������� �� ����������
\***sss********************************************************************************************/
void    kbd_4x6_interrupt()
{
  if(!kbd_descriptor_init) return;

  s_kbd_inkey       inkey;
  register uint32   size_keycode;
  register uint32   key = REG_KEYBOARD_KEY;
  switch (key & 0xFF)
  {
    case 0x07: inkey.press_code = HID_DEVICE_KEYBOARD|KB_0;             break;
    case 0x06: inkey.press_code = HID_DEVICE_KEYBOARD|KB_1;             break;
    case 0x05: inkey.press_code = HID_DEVICE_KEYBOARD|KB_2;             break;
    case 0x04: inkey.press_code = HID_DEVICE_KEYBOARD|KB_3;             break;
    case 0x0B: inkey.press_code = HID_DEVICE_KEYBOARD|KB_4;             break;
    case 0x0A: inkey.press_code = HID_DEVICE_KEYBOARD|KB_5;             break;
    case 0x09: inkey.press_code = HID_DEVICE_KEYBOARD|KB_6;             break;
    case 0x08: inkey.press_code = HID_DEVICE_KEYBOARD|KB_7;             break;
    case 0x13: inkey.press_code = HID_DEVICE_KEYBOARD|KB_8;             break;
    case 0x12: inkey.press_code = HID_DEVICE_KEYBOARD|KB_9;             break;
    case 0x11: inkey.press_code = HID_DEVICE_KEYBOARD|KB_A;             break;
    case 0x10: inkey.press_code = HID_DEVICE_KEYBOARD|KB_B;             break;
    case 0x23: inkey.press_code = HID_DEVICE_KEYBOARD|KB_C;             break;
    case 0x22: inkey.press_code = HID_DEVICE_KEYBOARD|KB_D;             break;
    case 0x21: inkey.press_code = HID_DEVICE_KEYBOARD|KB_E;             break;
    case 0x20: inkey.press_code = HID_DEVICE_KEYBOARD|KB_F;             break;

    case 0x43: inkey.press_code = HID_DEVICE_KEYBOARD|KB_ESCAPE;        break;
    case 0x80: inkey.press_code = HID_DEVICE_KEYBOARD|KB_ENTER;         break;
    case 0x41: inkey.press_code = HID_DEVICE_KEYBOARD|KB_LEFT_SHIFT;    break;
    case 0x40: inkey.press_code = HID_DEVICE_KEYBOARD|KB_BACKSPACE;     break;
    case 0x83: inkey.press_code = HID_DEVICE_KEYBOARD|KB_LEFT_ARROW;    break;
    case 0x82: inkey.press_code = HID_DEVICE_KEYBOARD|KB_DOWN_ARROW;    break;
    case 0x81: inkey.press_code = HID_DEVICE_KEYBOARD|KB_RIGHT_ARROW;   break;
    case 0x42: inkey.press_code = HID_DEVICE_KEYBOARD|KB_UP_ARROW;      break;
    default: return;
  }
  inkey.unpress_code = HID_KEYBOARD_RELEASE|inkey.press_code;
  
  inkey.sys_press_code = sysb_kbd_analys(inkey.press_code);
  inkey.sys_unpress_code = HID_KEYBOARD_RELEASE|inkey.sys_press_code;
  
  size_keycode = (inkey.sys_press_code != 0) ? sizeof(s_kbd_inkey)>>2 : (sizeof(inkey.press_code)+sizeof(inkey.unpress_code))>>2;
  //���������� ����� ������ � ����������� �����:
  if( size_keycode <= (kbd_circ.size - kbd_circ.count) )
  {
    register uint32* recast_inkey = (uint32*)&inkey;
    for(register int32 i=0; i<size_keycode; i++)
    {
      kbd_circ.buf[kbd_circ.free] = recast_inkey[i];
      kbd_circ.free++;
      kbd_circ.free = (kbd_circ.free == kbd_circ.size) ? 0x0 : kbd_circ.free;
      kbd_circ.count++;
      sem_unlock_sw(kbd_circ.sem);
    }
  }
}
/**************************************************************************************************\
    ������ ������� ��������� ���������� ������
\***sss********************************************************************************************/
uint32   sysb_kbd_analys(register uint32 key)
{
  kbd_sys_buf[2] = kbd_sys_buf[1];
  kbd_sys_buf[1] = kbd_sys_buf[0];
  kbd_sys_buf[0] = key;
  if(((HID_DEVICE_KEYBOARD|KB_F)==kbd_sys_buf[2])&&
     ((HID_DEVICE_KEYBOARD|KB_RIGHT_ARROW)==kbd_sys_buf[1])&&
     ((HID_DEVICE_KEYBOARD|KB_D)==kbd_sys_buf[0]))
    return HID_DEVICE_KEYBOARD|KB_SYS_HIDDEN;       
  else
    return 0x0000;
}
/**************************************************************************************************\
*   ����� ��� �������
\***sss********************************************************************************************/
int32   kbd_4x6_get_key(uint32* key)
{
  sem_lock(sem_kbd, SEM_INFINITY);
  sem_lock(kbd_circ.sem, SEM_INFINITY);
  *key = kbd_circ.buf[kbd_circ.busy];
  kbd_circ.busy++;
  kbd_circ.busy = (kbd_circ.busy == kbd_circ.size) ? 0x0 : kbd_circ.busy;
  kbd_circ.count--;
  sem_unlock(sem_kbd);
  return OSE_OK;
}
/**************************************************************************************************\
*   ����������� ������� �������
\***sss********************************************************************************************/
int32   kbd_4x6_imitation_press_key(uint32* key)
{
  //���������� ����� ������ � ����������� �����:
  if( (kbd_circ.size - kbd_circ.count) != 0x0 )
  {
    register uint32 is = int_disable();
    kbd_circ.buf[kbd_circ.free] = *key;
    kbd_circ.free++;
    kbd_circ.free = (kbd_circ.free == kbd_circ.size) ? 0x0 : kbd_circ.free;
    kbd_circ.count++;
    sem_unlock(kbd_circ.sem);          
    int_enable(is);
    return OSE_OK;
  }
  else return OSE_NO_MEMORY;
}
/**************************************************************************************************\
    �������� ������� ���� ������� �������
\***sss********************************************************************************************/
int32   kbd_4x6_probe_key(uint32* key)
{
  sem_lock(sem_kbd,SEM_INFINITY);
  if( kbd_circ.count > 0x0 )
    *key = kbd_circ.buf[kbd_circ.busy];
  else
    *key = 0x0000;
  sem_unlock(sem_kbd);
  return OSE_OK;
}

