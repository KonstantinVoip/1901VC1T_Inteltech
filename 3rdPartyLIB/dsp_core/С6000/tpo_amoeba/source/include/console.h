//**************************************************************************************************
//                         Copyright (C) 2010 RCZI
//--------------------------------------------------------------------------------------------------
// FILENAME....... console.h
//--------------------------------------------------------------------------------------------------
//                                  CONSOLE
//--------------------------------------------------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
//
// !: codepage: cp1251 
//
// !: d: Управление консолью.<br>
// !: md: Прототипы API функций работы с дисплеем и клавиатурой. Набор предопределенных констант.
// !: -:
//***sss********************************************************************************************
#ifndef     __BIOS_Console_H__
#define     __BIOS_Console_H__
#include    <os_types.h>

#define KEY_ENTER                   0x10
#define KEY_ESC                     0x11
#define KEY_UP                      0x12
#define KEY_DOWN                    0x13
#define KEY_LEFT                    0x14
#define KEY_RIGHT                   0x15
#define KEY_DEL                     0x16
#define KEY_SHIFT                   0x19
#define KEY_HIDDEN                  0x1F

#define ATTR_NORMAL                 0x00
#define ATTR_REVERSE                0x05
#define ATTR_BLINK_NORMAL           0x08
#define ATTR_BLINK_REVERSE          0x0D

#define SYS_CON     				0
#define USER_CON    				1

#define clrscr()                    con_clrscr(USER_CON)
#define clrbar(Y,DY)                con_clrbar(USER_CON,Y,DY)
#define gotoxy(X,Y)                 con_gotoxy(USER_CON,X,Y)
#define putch(C)                    con_putch(USER_CON,C)
#define putstr(STR)                 con_putstr(USER_CON,STR)
#define putattrstr(ATTR,STR)        con_putstr(USER_CON,ATTR,STR)
#define set_text_attribute(X,Y,L,A) con_set_text_attribute(USER_CON,X,Y,L,A);

#define cursor_enable				con_cursor_enable
#define cursor_disable				con_cursor_disable
int32   cprintf(const char *format,...);
int32	cprintf(uint8 attr, const char *format,...);

int32   con_init();
void    con_deinit();
void    con_clrscr(int32 con_type);
void    con_clrbar(int32 con_type, uint32 y, uint32 d_y);
void    con_gotoxy(int32 con_type, uint32 x, uint32 y);
void    con_putch(int32 con_type, int c);
void    con_putch(int32 con_type, uint8 attr, int c);
int32   con_putstr(int32 con_type, const char *str);
int32   con_putstr(int32 con_type, uint8 attr, const char *str);
int32   con_cprintf(int32 con_type, const char *format,...);
int32   con_cprintf(int32 con_type, uint8 attr, const char *format,...);
void    con_set_text_attribute(int32 con_type, uint32 x, uint32 y, uint32 length, uint8 attr);
void    con_cursor_enable();
void    con_cursor_disable();
int32   con_roll_open(int32 print_roll, int32 y, int32 scrn_line_num, int32 scrn_buf_num);
void    con_roll_close(int32 exit_key);
void    con_roll_reset();
int32   con_roll_putstr(int32 sleep_ms, const char* str);
int32   con_roll_getch();
int32   con_roll_kbhit();

int32   kb_hit();
int32   getch();

#define CHAR_LEFT_UP_CORNER         0x80
#define CHAR_UP_BORDER              0x81
#define CHAR_RIGHT_UP_CORNER        0x82
#define CHAR_LEFT_DOWN_CORNER       0x83
#define CHAR_DOWN_BORDER            0x84
#define CHAR_RIGHT_DOWN_CORNER      0x85
#define CHAR_LEFT_BORDER            0x86
#define CHAR_RIGHT_BORDER           0x87

#define CHAR_ICO0                   0x88
#define CHAR_ICO1                   0x89
#define CHAR_ICO2                   0x8A
#define CHAR_ICO3                   0x8B

#define CHAR_DOT                    0x8C
#define CHAR_HEAD                   0x8D
#define CHAR_BIG_DOT                0x8E  
#define CHAR_SMALL_DOT              0x8F  
#define STR_CHAR_BIG_DOT            "\x8E"
#define STR_CHAR_SMALL_DOT          "\x8F" 

#define CHAR_LEFT_UP_WIND           0x90   
#define CHAR_UP_WIND                0x91
#define CHAR_RIGHT_UP_WIND          0x92
#define CHAR_LEFT_DOWN_WIND         0x93
#define CHAR_DOWN_WIND              0x94
#define CHAR_RIGHT_DOWN_WIND        0x95
#define CHAR_LEFT_WIND              0x96
#define CHAR_RIGHT_WIND             0x97

#define CHAR_UP_CROSS_TBL           0x98  
#define CHAR_CROSS_TBL              0x99  
#define CHAR_DOWN_CROSS_TBL         0x9A
#define CHAR_LEFT_UP_CORNER_TBL     0x9B  
#define CHAR_RIGHT_UP_CORNER_TBL    0x9C  
#define CHAR_LEFT_DOWN_CORNER_TBL   0x9D  
#define CHAR_RIGHT_DOWN_CORNER_TBL  0x9E

#define CHAR_CHECKBOX               0xA2 
#define CHAR_UNCHECKBOX             0xA3 

//FOR PROGRESS BAR:
#define PRGSS_PC_EMPTY              0xA4
#define PRGSS_PC_FULL               0xA5

#define PRGSS_0_FULL                0xA6
#define PRGSS_1_FULL                0xA7
#define PRGSS_2_FULL                0xA8
#define PRGSS_3_FULL                0xA9
#define PRGSS_4_FULL                0xAA
#define PRGSS_5_FULL                0xAB
#define PRGSS_6_FULL                0xAC
#define PRGSS_7_FULL                0xAD
#define PRGSS_8_FULL                0xAE
#define PRGSS_9_FULL                0xAF

#define PRGSS_L_EMPTY               0xB0
#define PRGSS_C_EMPTY               0xB1
#define PRGSS_R_EMPTY               0xB2
#define PRGSS_L_FULL                0xB3
#define PRGSS_C_FULL                0xB4
#define PRGSS_R_FULL                0xB5

#define BEAR_DOWN_FOREFOOT          0xB6
#define BEAR_DOWN_DOBLEFOOT_1       0xB7
#define BEAR_DOWN_DOBLEFOOT_2       0xB8

#define BEAR_UP_FOREFOOT            0xB9
#define BEAR_UP_DOBLEFOOT_1         0xBA
#define BEAR_UP_DOBLEFOOT_2         0xBB

#define PRGSS_6_EMPTY               0xBC
#define PRGSS_7_EMPTY               0xBD
#define PRGSS_8_EMPTY               0xBE
#define PRGSS_9_EMPTY               0xBF

#define STR_PRGSS_PC_EMPTY          "\xA4"
#define STR_PRGSS_PC_FULL           "\xA5"

#define STR_PRGSS_0_FULL            "\xA6"
#define STR_PRGSS_1_FULL            "\xA7"
#define STR_PRGSS_2_FULL            "\xA8"
#define STR_PRGSS_3_FULL            "\xA9"
#define STR_PRGSS_4_FULL            "\xAA"
#define STR_PRGSS_5_FULL            "\xAB"
#define STR_PRGSS_6_FULL            "\xAC"
#define STR_PRGSS_7_FULL            "\xAD"
#define STR_PRGSS_8_FULL            "\xAE"
#define STR_PRGSS_9_FULL            "\xAF"

#define STR_PRGSS_L_EMPTY           "\xB0"
#define STR_PRGSS_C_EMPTY           "\xB1"
#define STR_PRGSS_R_EMPTY           "\xB2"
#define STR_PRGSS_L_FULL            "\xB3"
#define STR_PRGSS_C_FULL            "\xB4"
#define STR_PRGSS_R_FULL            "\xB5"

#define STR_PRGSS_0_EMPTY           "\xB6"
#define STR_PRGSS_1_EMPTY           "\xB7"
#define STR_PRGSS_2_EMPTY           "\xB8"
#define STR_PRGSS_3_EMPTY           "\xB9"
#define STR_PRGSS_4_EMPTY           "\xBA"
#define STR_PRGSS_5_EMPTY           "\xBB"
#define STR_PRGSS_6_EMPTY           "\xBC"
#define STR_PRGSS_7_EMPTY           "\xBD"
#define STR_PRGSS_8_EMPTY           "\xBE"
#define STR_PRGSS_9_EMPTY           "\xBF"

#endif //__BIOS_Console_H__
