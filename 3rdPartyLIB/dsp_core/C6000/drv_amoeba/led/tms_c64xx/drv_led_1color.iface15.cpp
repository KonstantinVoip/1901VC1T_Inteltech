//**************************************************************************************************
//                         Copyright (C) 2009 RCZI
//--------------------------------------------------------------------------------------------------
// FILENAME....... drv_led.cpp
// DATE CREATED... 02/10/2009
// LAST MODIFIED.. 21/12/2009
// DRIVER VERSION. 1.0
//--------------------------------------------------------------------------------------------------
//  ���������� �����: /dev/led
//              ..
//  <FILE>      abonent
//  <FILE>      channel
//--------------------------------------------------------------------------------------------------
//                          L E D   D R I V E R
//-------------------------------------------------------------------------------------------------
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
// -- ������� ����� �������� LED ------------------------------------------------------------------
#define     LED_CHANNEL         0x0001
#define     LED_ABONENT         0x0002
// -- ���� ---------------------------------------------------------------------------------------------
#define     DRV_ROOT_DIR        (void*)0xD000
#define     DRV_CHANNEL_FILE    (void*)0xF001
#define     DRV_ABONENT_FILE    (void*)0xF002
#define     NUMBER_OF_LEDS      2
// -----------------------------------------------------------------------------------------------------
static int32 led_color_dist( int32 r1, int32 g1, int32 b1, int32 r2, int32 g2, int32 b2 );
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
        //���������������:
        case IOC_DEINIT:            
            break;

        //������������� ������:
        case IOC_INIT_DESCRIPTOR:
            d->data = DRV_ROOT_DIR;
            break;  

        //��������������� ������:
        case IOC_DEINIT_DESCRIPTOR: 
            d->data = NULL;
            break;

        //������� �� ����������� � ����� ��������:
        case IOC_INODE_SELECT:      
        {
            const char* recast_arg = (const char*) arg;
            if(!strcmp(recast_arg,"."))
                break;
            else
            if(!strcmp(recast_arg,".."))
            {
                drv_dec(d);
                if(d->data == DRV_ROOT_DIR)
                    drv_rfs(d);
                else
                    d->data = DRV_ROOT_DIR;
            }
            else 
            if(!strcmp(recast_arg,"channel") && d->data == DRV_ROOT_DIR)
            {
                drv_inc(d,"channel");
                d->data = DRV_CHANNEL_FILE;
            }
            else 
            if(!strcmp(recast_arg,"abonent") && d->data == DRV_ROOT_DIR)
            {
                drv_inc(d,"abonent");
                d->data = DRV_ABONENT_FILE;
            }
            else
                return  OSE_NO_NODE;
        }
        break;
        //��������� ������ ������:
        case IOC_INODE_LIST:
        {
            if(d->data != DRV_ROOT_DIR)
                return OSE_NO_NODE;
            s_inode*     node;
            s_inode*     first_node = NULL;
            s_inode*     last_node = NULL;

            for(int32 i=0; i<NUMBER_OF_LEDS; i++)
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
                if(i == 0) strcpy(node->name,"channel");
                if(i == 1) strcpy(node->name,"abonent");
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
        }
        break;
    //===============================================================
    //Driver self control command:
        case LED_SETCOLOR:
        {
          if( arg == NULL ) return OSE_NULL_PARAM;
          uint32& color = (*(uint32*)const_cast<void*>( arg ));
          int32 r, g, b;
          int32 d_green, d_black;
          r = (int32)( ( color >> 16 ) & 0x000000ff );
          g = (int32)( ( color >> 8 ) & 0x000000ff );
          b = (int32)( color & 0x000000ff );
          d_green = led_color_dist( r, g, b, 0, 255, 0 );
          d_black = led_color_dist( r, g, b, 0,   0, 0 );
          if( d_green <= d_black )
          {
            if(d->data == DRV_CHANNEL_FILE)
                REG_LED |= LED_CHANNEL;
            else if(d->data == DRV_ABONENT_FILE)
                REG_LED |= LED_ABONENT;
            else
                return  OSE_BAD_PARAM;     
          }
          else
          {
            if(d->data == DRV_CHANNEL_FILE)
                REG_LED &= ~LED_CHANNEL;
            else if(d->data == DRV_ABONENT_FILE)
                REG_LED &= ~LED_ABONENT;
            else
                return  OSE_BAD_PARAM;     
          }
        }
        break;

        case LED_GETCOLOR:
        {
          if( arg == NULL ) return OSE_NULL_PARAM;
          uint32& color = (*(uint32*)const_cast<void*>( arg ));

          if( d->data == DRV_CHANNEL_FILE )
              color = ( REG_LED & LED_CHANNEL ) ? 0x0000ff00 : 0x00000000;
          else if(d->data == DRV_ABONENT_FILE)
              color = ( REG_LED & LED_ABONENT ) ? 0x0000ff00 : 0x00000000;
          else
              return  OSE_BAD_PARAM;     

        }
        break;

        default:
            return OSE_BAD_PARAM;
    }   
    return OSE_OK;
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
//     ��������� ������� ��������
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
int32 led_color_dist( int32 r1, int32 g1, int32 b1, int32 r2, int32 g2, int32 b2 )
{
  register int32 dr = r1 - r2;
  register int32 dg = g1 - g2;
  register int32 db = b1 - b2;
  return dr * dr + dg * dg + db * db;
}
