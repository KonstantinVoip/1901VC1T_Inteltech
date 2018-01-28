//**************************************************************************************************
//                         Copyright (C) 2009 RCZI
//--------------------------------------------------------------------------------------------------
// FILENAME....... drv_lcd.h
// DATE CREATED... 15/10/2009
// LAST MODIFIED.. 15/10/2009
//-------------------------------------------------------------------------------------------------
//				L C D    M O D U L E    D R I V E R
//-------------------------------------------------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
//
// !: codepage: cp1251 
//
// !: d: Описание кодов ошибок, внутренних управляющих команд, структуры 
// !: d: драйвера дисплея "POWERTIP"..
// !: -:
//***sss********************************************************************************************
#ifndef     __Driver_LCD_H__
#define     __Driver_LCD_H__
#include	<os_types.h>

//--- Display driver control command codes ------------------------------------
#define DSPL_SET_MODE                 0x10000
#define DSPL_GET_RESOLUTION           0x10001
#define DSPL_SET_CURSOR_VISIBILITY    0x10002
#define DSPL_SET_CURSOR_POSITION      0x10003
#define DSPL_SET_CURSOR_HEIGHT        0x10004
#define DSPL_SET_FOREGROUND_COLOR     0x10005
#define DSPL_SET_BACKGROUND_COLOR     0x10006
#define DSPL_LOAD_KEYGEN              0x10007
#define DSPL_LOAD_KEYGEN_BUFFER       0x10008

#define DSPL_DRAW_PIXEL						0x10010
#define DSPL_DRAW_LINE						0x10011
#define DSPL_DRAW_HLINE						0x10012
#define DSPL_DRAW_VLINE						0x10013
#define DSPL_DRAW_MOVETO					0x10014
#define DSPL_DRAW_LINETO					0x10015
#define DSPL_DRAW_RECT						0x10016
#define DSPL_DRAW_FRECT						0x10017
#define DSPL_DRAW_TEXT						0x10018
#define DSPL_DRAW_IMAGE						0x10019
#define DSPL_DRAW_COLOR						0x1001A
#define DSPL_DRAW_VGRAD						0x1001B
#define DSPL_DRAW_HGRAD						0x1001C

//--- Display driver error code ---------------------------------------------------
#define DSPL_ER_CURSOR_POINTER_SET          -10000
#define DSPL_ER_OFFSET_REGISTER_SET         -20000
#define DSPL_ER_ADDRESS_POINTER_SET         -30000

#define DSPL_ER_TEXT_HOME_ADDRESS_SET       -40000
#define DSPL_ER_TEXT_AREA_SET               -50000
#define DSPL_ER_GRAPHIC_HOME_ADDRESS_SET    -60000
#define DSPL_ER_GRAPHIC_AREA_SET            -70000

#define DSPL_ER_OR_MODE_SET                 -80000
#define DSPL_ER_EXOR_MODE_SET               -90000
#define DSPL_ER_AND_MODE_SET                -100000
#define DSPL_ER_TEXT_ATTR_MODE_SET          -110000
#define DSPL_ER_INT_CG_ROM_MODE_SET         -120000
#define DSPL_ER_EXT_CG_RAM_MODE_SET         -130000

#define DSPL_ER_DISPLAY_MODE                -140000
#define DSPL_ER_CURSOR_PATTERN_SELECT       -150000

#define DSPL_ER_DATA_AUTO_WRITE             -160000

#define DSPL_ER_DATA_WRITE_INC              -170000
#define DSPL_ER_DATA_WRITE_DEC              -180000
#define DSPL_ER_DATA_WRITE_NON              -190000

//--- Display driver constant -------------------------------------------------
//SET_MODE:										
#define	MODE_DISPLAY_OFF                    0
#define	MODE_DISPLAY_TEXT                   1
#define	MODE_DISPLAY_GRAPH                  2
//SET_CURSOR_VISIBILITY:
#define CURSOR_ENABLE                       1
#define CURSOR_DISABLE                      0

//--- Display driver structur -------------------------------------------------
// ---------------------------------------------------------------------------
// !: sn: s_display_axis
// !: sd: Структура координат дисплея.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: uint32,         x
// !: cd: X координата
// !: sc: uint32,         y
// !: cd: Y координата
// ---------------------------------------------------------------------------
// !: sn: s_display_axis
// !: sd: Структура сброса РИК.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: uint32,     width
// !: cd: ширина
// !: sc: uint32,     height
// !: cd: высота
// ---------------------------------------------------------------------------
struct s_display_axis
{
  union 
  {
    uint32  x;
    uint32  width;
  };
   union
  {
    uint32  y;
    uint32  height;
  };
};
// ---------------------------------------------------------------------------
// !: sn: s_display_char
// !: sd: Структура загрузки символа 8х8 пикселей в дисплей.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: uint8,          code
// !: cd: код символа
// !: sc: uint8[8],       line
// !: cd: таблица пикселей символа
// ---------------------------------------------------------------------------
struct s_display_char
{
  uint8   code;
  uint8   line[8];
};
// ---------------------------------------------------------------------------
// !: sn: s_display_char_buffer
// !: sd: Структура загрузки буфера символов 8х8 пикселей в дисплей.
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sc: uint8,          code
// !: cd: код первого символа
// !: sc: uint8*,         buffer
// !: cd: Указатель на буфер с символами
// !: sc: uint32,         size
// !: cd: размер буфера
// ---------------------------------------------------------------------------
struct s_display_char_buffer
{
  uint8     code;
  uint8*    buffer;
  uint32    size;
};
// -- For system calls only ---------------------------------------------------
extern int32     drv_lcd_plug(uint32 number_gpio_interrupt);
extern int32     drv_lcd_unplug();
  // For direct display access:
extern void      drv_lcd_direct_set_graph_mode();
extern void      drv_lcd_direct_set_graph_text_mode();
extern void      drv_lcd_direct_out_frame(void*);
extern void      drv_lcd_direct_out_frame(void*, const char*);
#endif //__Driver_LCD_H__


