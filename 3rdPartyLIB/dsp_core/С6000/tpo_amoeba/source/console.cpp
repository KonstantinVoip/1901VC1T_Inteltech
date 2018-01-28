//**************************************************************************************************
//                         Copyright (C) 2010 RCZI
//--------------------------------------------------------------------------------------------------
// FILENAME....... console.cpp
// DATE CREATED... 15/02/2010
// LAST MODIFIED.. 16/09/2010
// VERSION........ 1.1
//--------------------------------------------------------------------------------------------------
//                                  CONSOLE
//--------------------------------------------------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
//
// !: codepage: cp1251 
//
// !: d: Управление консолью.<br>
// !: md: API функции работы с дисплеем и клавиатурой.
// !: -:
//***sss********************************************************************************************
#include <rts.h>
#include <drv_lcd.h>
#include <drv_kbd_4x6.h>
#include "console.h"
//-------------------------------------------------------------------------------------------------
static volatile bool            fg_con_init = false;
static volatile uint32          kbd_file;
static s_display_axis           console_axis;
//-------------------------------------------------------------------------------------------------
static const char  sios_char[] = 
{
 0x00, 0x00, 0x07, 0x08, 0x10, 0x20, 0x20, 0x20, //0x80  CHAR_LEFT_UP_CORNER   
 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, //0x81  CHAR_UP_BORDER        
 0x00, 0x00, 0xE0, 0x10, 0x08, 0x04, 0x04, 0x04, //0x82  CHAR_RIGHT_UP_CORNER  
 0x20, 0x20, 0x20, 0x10, 0x08, 0x07, 0x00, 0x00, //0x83  CHAR_LEFT_DOWN_CORNER 
 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, //0x84  CHAR_DOWN_BORDER      
 0x04, 0x04, 0x04, 0x08, 0x10, 0xE0, 0x00, 0x00, //0x85  CHAR_RIGHT_DOWN_CORNER
 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, //0x86  CHAR_LEFT_BORDER      
 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, //0x87  CHAR_RIGHT_BORDER     

// 0x00, 0x03, 0x0F, 0x1F, 0x1E, 0x3C, 0x3C, 0x3C, //0x88  CHAR_ICO0             
// 0x1F, 0xC7, 0x81, 0x01, 0x00, 0x00, 0x02, 0x06, //0x89  CHAR_ICO1             
// 0x3C, 0x3E, 0x7F, 0xFF, 0xFF, 0xFF, 0xFC, 0xF8, //0x8A  CHAR_ICO2             
// 0x0E, 0x1E, 0xFC, 0xFC, 0xF9, 0xE1, 0x07, 0x3F, //0x8B  CHAR_ICO3             
 

 0x07, 0x1F, 0x3F, 0x7F, 0xFF, 0xC1, 0x00, 0x00, //0x88  CHAR_ICO0             
 0x3F, 0xCF, 0xE3, 0xF8, 0xFE, 0xFF, 0xFF, 0xFF, //0x89  CHAR_ICO1             
 0x00, 0x00, 0x00, 0x01, 0x1F, 0x3F, 0x1F, 0x00, //0x8A  CHAR_ICO2             
 0xFF, 0xFF, 0xFF, 0xFE, 0xF8, 0xF3, 0xCF, 0x3F, //0x8B  CHAR_ICO3             

 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, //0x8C  CHAR_DOT for tpo
// 0x00, 0x00, 0x00, 0x18, 0x3C, 0x3C, 0x18, 0x00, //0x8C  CHAR_DOT

 0xFF, 0xFC, 0xF8, 0xF8, 0xF0, 0xF0, 0xE0, 0x80, //0x8D  CHAR_HEAD

 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, //0x8E  CHAR_BIG_DOT
// 0x00, 0x18, 0x3C, 0x7E, 0x7E, 0x3C, 0x18, 0x00, //0x8E  CHAR_BIG_DOT

 0x00, 0x00, 0x18, 0x3C, 0x3C, 0x18, 0x00, 0x00, //0x8F  CHAR_SMALL_DOT

 

 
 0xFF, 0xF8, 0xF7, 0xEF, 0x1F, 0xFE, 0xFE, 0xFE, //0x90  CHAR_LEFT_UP_WIND   
 0xFF, 0x3F, 0xDF, 0xEF, 0x9F, 0x7F, 0xFF, 0xFF, //0x91  CHAR_UP_WIND        
 0xFE, 0xFE, 0xFF, 0x1F, 0xE7, 0xFB, 0xFC, 0xFF, //0x92  CHAR_RIGHT_UP_WIND  
 0xFF, 0xC7, 0x3B, 0xF7, 0xEF, 0xDF, 0x3F, 0xFF, //0x93  CHAR_LEFT_DOWN_WIND


 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, //0x94  CHAR_DOWN_WIND      
 0x01, 0x02, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, //0x95  CHAR_RIGHT_DOWN_WIND
 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, //0x96  CHAR_LEFT_WIND      
 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, //0x97  CHAR_RIGHT_WIND
 
 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x20, 0x20, //0x98  CHAR_UP_CROSS_TBL
 0x20, 0x20, 0x20, 0x20, 0x20, 0xFF, 0x20, 0x20, //0x99  CHAR_CROSS_TBL
 0x20, 0x20, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, //0x9A  CHAR_DOWN_CROSS_TBL
 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x20, 0x20, //0x9B  CHAR_LEFT_UP_CORNER_TBL
 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x20, 0x20, //0x9C  CHAR_RIGHT_UP_CORNER_TBL
 0x20, 0x20, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, //0x9D  CHAR_LEFT_DOWN_CORNER_TBL
 0x20, 0x20, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, //0x9E  CHAR_RIGHT_DOWN_CORNER_TBL
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //0x9F  
 
 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, //0xA0
 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, //0xA1
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //0xA2
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //0xA3
 
 //FOR PROGRESS BAR:
 0xFF, 0x00, 0x00, 0x24, 0x08, 0x10, 0x24, 0xFF, //0xA4 PRGSS_PC_EMPTY
 0xFF,~0x00,~0x00,~0x24,~0x08,~0x10,~0x24, 0xFF, //0xA5 PRGSS_PC_FULL
 
 0xFF,~0x00,~0x3C,~0x24,~0x24,~0x24,~0x3C, 0xFF, //0xA6 PRGSS_0_FULL
 0xFF,~0x00,~0x0C,~0x04,~0x04,~0x04,~0x04, 0xFF, //0xA7 PRGSS_1_FULL
 0xFF,~0x00,~0x3C,~0x04,~0x3C,~0x20,~0x3C, 0xFF, //0xA8 PRGSS_2_FULL
 0xFF,~0x00,~0x3C,~0x04,~0x1C,~0x04,~0x3C, 0xFF, //0xA9 PRGSS_3_FULL
 0xFF,~0x00,~0x24,~0x24,~0x3C,~0x04,~0x04, 0xFF, //0xAA PRGSS_4_FULL
 0xFF,~0x00,~0x3C,~0x20,~0x3C,~0x04,~0x3C, 0xFF, //0xAB PRGSS_5_FULL
 0xFF,~0x00,~0x3C,~0x20,~0x3C,~0x24,~0x3C, 0xFF, //0xAC PRGSS_6_FULL
 0xFF,~0x00,~0x3C,~0x04,~0x04,~0x04,~0x04, 0xFF, //0xAD PRGSS_7_FULL
 0xFF,~0x00,~0x3C,~0x24,~0x3C,~0x24,~0x3C, 0xFF, //0xAE PRGSS_8_FULL
 0xFF,~0x00,~0x3C,~0x24,~0x3C,~0x04,~0x3C, 0xFF, //0xAF PRGSS_9_FULL

 0x0F, 0x30, 0x40, 0x80, 0x80, 0x40, 0x30, 0x0F, //0xB0 PRGSS_L_EMPTY
 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, //0xB1 PRGSS_C_EMPTY
 0xF0, 0x0C, 0x02, 0x01, 0x01, 0x02, 0x0C, 0xF0, //0xB2 PRGSS_R_EMPTY
 0x0F, 0x3F, 0x7F, 0xFF, 0xFF, 0x7F, 0x3F, 0x0F, //0xB3 PRGSS_L_FULL
 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //0xB4 PRGSS_C_FULL
 0xF0, 0xFC, 0xFE, 0xFF, 0xFF, 0xFE, 0xFC, 0xF0, //0xB5 PRGSS_R_FULL
 
 0x34, 0x30, 0x34, 0x70, 0x74, 0xF0, 0xF4, 0x68, //0xB6 BEAR_DOWN_FOREFOOT
 0x34, 0x30, 0x34, 0x70, 0x73, 0xF7, 0xF7, 0x63, //0xB7 BEAR_DOWN_DOBLEFOOT_1
 0x04, 0x3A, 0x7D, 0xFC, 0xFD, 0xFC, 0xFA, 0xF0, //0xB8 BEAR_DOWN_DOBLEFOOT_2
 0x68, 0xF4, 0xF0, 0x74, 0x70, 0x34, 0x30, 0x34, //0xB9 BEAR_UP_FOREFOOT
 0x63, 0xF7, 0xF7, 0x73, 0x70, 0x34, 0x30, 0x34, //0xBA BEAR_UP_DOBLEFOOT_1
 0xF0, 0xFA, 0xFC, 0xFD, 0xFC, 0x7D, 0x3A, 0x04, //0xBB BEAR_UP_DOBLEFOOT_2

 0xFF, 0x00, 0x3C, 0x20, 0x3C, 0x24, 0x3C, 0xFF, //0xBC PRGSS_6_EMPTY
 0xFF, 0x00, 0x3C, 0x04, 0x04, 0x04, 0x04, 0xFF, //0xBD PRGSS_7_EMPTY
 0xFF, 0x00, 0x3C, 0x24, 0x3C, 0x24, 0x3C, 0xFF, //0xBE PRGSS_8_EMPTY
 0xFF, 0x00, 0x3C, 0x24, 0x3C, 0x04, 0x3C, 0xFF  //0xBF PRGSS_9_EMPTY
};                                         
//-------------------------------------------------------------------------------------------------
int32 con_write(int32 con_type, const char *str, int32 length, uint8 attr);
int32 con_write_attr(int32 con_type, int32 length, uint8 attr);
void  con_clear(int32 con_type);
void  con_clear_position(int32 con_type, int32 length);
int64 con_position(int32 con_type);
void  con_seek(int32 con_type, int64 seek);
void  con_cursor_visibility(int32 enable);
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//
//      API Функции работы с дисплеем
//
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
/**************************************************************************************************\
*  
\**************************************************************************************************/
//-------------------------------------------------------------------------------------------------
static volatile bool    fg_con_roll_init = false;
static volatile bool    exit_con_roll_refresh_prc;
static volatile bool    exit_con_roll_getch_prc;
static volatile uint32  pid_roll_refresh_prc;
static volatile uint32  pid_roll_getch_prc;
struct s_con_roll_buf
{
  char*            buf;
  char*            begin;
  int64            scrn_buf_num;
  int64            scrn_buf_len;
  int64            roll_buf_len;
  int64            seek;
  int32            y;
  int32            key;
  int32            exit_key;
  int32            print_roll;
  uint32           sem_out;
  uint32           sem_synh;
  uint32           sem_getch;
}con_roll;
//-------------------------------------------------------------------------------------------------
int   con_roll_refresh_prc(void* arg);
int   con_roll_getch_prc(void* arg);
int32 con_roll_write(const char *str, int32 length);
void  con_roll_crlf();
int64 con_roll_position();
void  con_roll_seek(int64 seek);

//=================================================================================================
int32 con_roll_open(int32 print_roll, int32 y, int32 scrn_line_num, int32 scrn_buf_num)
{
  int32        error, stage;
  s_prc_attr   prc_attr;

  if(fg_con_roll_init == true) return OSE_CANT_OPEN;
  memset(&con_roll, 0x0, sizeof(s_con_roll_buf));

  con_roll.print_roll = print_roll;
  con_roll.y = y;
  con_roll.scrn_buf_num = scrn_buf_num;
  con_roll.scrn_buf_len = scrn_line_num*console_axis.width;
  con_roll.roll_buf_len = con_roll.scrn_buf_len*con_roll.scrn_buf_num;

  stage = 0;
  //*** STAGE1 ***
  con_roll.buf = new char[con_roll.roll_buf_len];
  if(con_roll.buf==NULL)
  {
    stage = 0;
    error = OSE_NO_MEMORY;
    goto m_return;
  }
  memset(con_roll.buf, 0x0, con_roll.roll_buf_len);   
  con_roll.begin = con_roll.buf;
  //*** STAGE2 ***
  //Регистрируем семафор:
  con_roll.sem_out = sem_alloc(0, NULL);
  if(con_roll.sem_out == RES_VOID) 
  {
    stage = 1;
    error = OSE_CANT_CREATE_SEM;
    goto m_return;
  }
  //*** STAGE3***
  //Регистрируем семафор:
  con_roll.sem_synh = sem_alloc(1, NULL);
  if(con_roll.sem_synh == RES_VOID) 
  {
    stage = 2;
    error = OSE_CANT_CREATE_SEM;
    goto m_return;
  }
  //*** STAGE4***
  //Регистрируем семафор:
  con_roll.sem_getch = sem_alloc(0, NULL);
  if(con_roll.sem_getch == RES_VOID) 
  {
    stage = 3;
    error = OSE_CANT_CREATE_SEM;
    goto m_return;
  }
  //*** STAGE5 ***
  //Создание процесса:
  exit_con_roll_refresh_prc = false;
  memset(&prc_attr, 0x0, sizeof(s_prc_attr));
  prc_attr.exit_vector = NULL;
  prc_attr.stack = 1024;
  pid_roll_refresh_prc = prc_create(&con_roll_refresh_prc, NULL, 0, &prc_attr);
  if(( (int32)pid_roll_refresh_prc ) <= 0x0)
  {
    stage = 4;
    error = OSE_NO_MEMORY;
    goto m_return;
  }
  //*** STAGE6 ***
  //Создание процесса:
  exit_con_roll_getch_prc = false;
  memset(&prc_attr, 0x0, sizeof(s_prc_attr));
  prc_attr.exit_vector = NULL;
  prc_attr.stack = 1024;
  pid_roll_getch_prc = prc_create(&con_roll_getch_prc, NULL, 0, &prc_attr);
  if(( (int32)pid_roll_getch_prc ) <= 0x0)
  {
    stage = 5;
    error = OSE_NO_MEMORY;
    goto m_return;
  }

  error = OSE_OK;
  fg_con_roll_init = true;
m_return:
  switch(stage)
  {
    case 5:    exit_con_roll_refresh_prc = true;
               sem_unlock(con_roll.sem_out);
               prc_join(pid_roll_refresh_prc);
    case 4:    sem_free(con_roll.sem_getch);               
    case 3:    sem_free(con_roll.sem_synh);
    case 2:    sem_free(con_roll.sem_out);
    case 1:    delete con_roll.buf;
  }
  return error;

}
//=================================================================================================
void con_roll_close(int32 exit_key)
{
  if(fg_con_roll_init==false) return;

  con_roll.exit_key = exit_key;
  exit_con_roll_getch_prc = true;
  prc_join(pid_roll_getch_prc);  
  
  exit_con_roll_refresh_prc = true;
  sem_unlock(con_roll.sem_out);
  prc_join(pid_roll_refresh_prc);
  
  sem_free(con_roll.sem_getch);
  sem_free(con_roll.sem_synh);
  sem_free(con_roll.sem_out);
  delete con_roll.buf;
  fg_con_roll_init = false;
}
//=================================================================================================
void con_roll_reset()
{
  if(fg_con_roll_init==false) return;
  sem_lock(con_roll.sem_synh, SEM_INFINITY);
  con_roll.begin = con_roll.buf;
  con_roll.seek = 0x0;
  memset(con_roll.buf, 0x0, con_roll.roll_buf_len);
  sem_unlock(con_roll.sem_synh);  
}
//=================================================================================================
int con_roll_refresh_prc(void* arg)
{
  while(true)
  {
    sem_lock(con_roll.sem_out, SEM_INFINITY);
    if(exit_con_roll_refresh_prc == true) break;
    con_seek(USER_CON, con_roll.y*console_axis.width);
    con_write(USER_CON, con_roll.begin, con_roll.scrn_buf_len, ATTR_NORMAL);
  }
  con_seek(USER_CON, con_roll.y*console_axis.width);
  con_write(USER_CON, con_roll.begin, con_roll.scrn_buf_len, ATTR_NORMAL);
  return 0;
}
//=================================================================================================
int con_roll_getch_prc(void* arg)
{
  int32 key;
  char* begin;
  while(true)
  {
    key = kb_hit();
    if(key != 0x0)
    {
      key = getch();
      con_roll.key = key;
      sem_unlock(con_roll.sem_getch);
    }  
    switch(key)
    {
      case KEY_UP:
      {
        sem_lock(con_roll.sem_synh, SEM_INFINITY);
        begin = con_roll.begin;
        begin -= console_axis.width;
        if(begin >= con_roll.buf)
          con_roll.begin = begin;
        sem_unlock(con_roll.sem_out);
        sem_unlock(con_roll.sem_synh);
      }
      break;
      case KEY_DOWN:
      {
        sem_lock(con_roll.sem_synh, SEM_INFINITY);
        begin = con_roll.begin;        
        begin += console_axis.width;
        if(begin <= (con_roll.buf+((con_roll.seek/console_axis.width)*console_axis.width+console_axis.width)-con_roll.scrn_buf_len))
          con_roll.begin = begin;        
        sem_unlock(con_roll.sem_out);
        sem_unlock(con_roll.sem_synh);
      }
      break;
      default:
      {
        if(exit_con_roll_getch_prc == true)
        {
          if(0x0 == con_roll.exit_key)
            goto m_return;
          if(key == con_roll.exit_key)
            goto m_return;
        }
      }
    }
    prc_yield();
  }
m_return:
  return 0;
}
//=================================================================================================
int32 con_roll_getch()
{
  sem_lock(con_roll.sem_getch, SEM_INFINITY);
  return con_roll.key; 
}
//=================================================================================================
int32 con_roll_kbhit()
{
  int32 val;
  sem_value(con_roll.sem_getch, &val);
  if(val != 0)
    return 1;
  else
    return 0; 
}
//=================================================================================================
int32 con_roll_putstr(int32 sleep_ms, const char* str)
{
  if(fg_con_roll_init==false) return 0;
  int32   size = 0x0;
  char*   begin = (char*)str; 
  char*   crlf = strchr(begin,'\n');
  while(crlf != NULL)
  {
    size += con_roll_write(begin, (int32)(crlf-begin));
    con_roll_crlf();
    begin = crlf + 0x1;
    crlf = strchr(begin,'\n');
  }
  size += con_roll_write(begin, strlen(begin));
  sleep_m(sleep_ms);
  return size;
}
//=================================================================================================
int32 con_roll_write(const char *str, int32 length)
{
  int64  seek;
  int32  size, len, char_in_line;
  len = length;
  sem_lock(con_roll.sem_synh, SEM_INFINITY);
  while(len)
  {
    char_in_line = ((con_roll.seek/console_axis.width)*console_axis.width+console_axis.width) - con_roll.seek;
    size = (len<=char_in_line) ? len : char_in_line;
    memcpy(&con_roll.buf[con_roll.seek], &str[length-len], size);
    if(size >= char_in_line) con_roll_crlf();
    else con_roll.seek += size;
    len -= size;
  }
  seek = (con_roll.seek/console_axis.width)*console_axis.width+console_axis.width;
  if(con_roll.print_roll)
  {
    if((con_roll.scrn_buf_len<seek)&&(seek<=con_roll.roll_buf_len))
      con_roll.begin = con_roll.buf + seek - con_roll.scrn_buf_len;
  }
  sem_unlock(con_roll.sem_out);
  sem_unlock(con_roll.sem_synh);
  return length;
}
//=================================================================================================
void con_roll_crlf()
{
  int64 seek = (con_roll.seek/console_axis.width)*console_axis.width+console_axis.width;
  if(seek<con_roll.roll_buf_len)
  {
    con_roll.seek = seek;
  }
  else
  {
    memcpy(con_roll.buf, &con_roll.buf[console_axis.width], con_roll.roll_buf_len-console_axis.width);
    memset(&con_roll.buf[con_roll.roll_buf_len-console_axis.width], 0x0, console_axis.width);
    con_roll.seek = con_roll.roll_buf_len-console_axis.width;
  }
}
/**************************************************************************************************\
*  Вывод строки с параметрами
\**************************************************************************************************/
int32 con_cprintf(int32 con_type, const char *format,...)
{
    char buffer[80];
    va_list argptr;
    int cnt;

    va_start(argptr, format);
    cnt = vsprintf(buffer, format, argptr);
    va_end(argptr);

    con_putstr(con_type, buffer);

    return cnt;
}
int32   con_cprintf(int32 con_type, uint8 attr, const char *format,...)
{
    char buffer[80];
    va_list argptr;
    int cnt;

    va_start(argptr, format);
    cnt = vsprintf(buffer, format, argptr);
    va_end(argptr);

    con_putstr(con_type, attr, buffer);

    return cnt;
}
int32   cprintf(const char *format,...)
{
    char buffer[80];
    va_list argptr;
    int cnt;

    va_start(argptr, format);
    cnt = vsprintf(buffer, format, argptr);
    va_end(argptr);

    con_putstr(USER_CON, buffer);

    return cnt;
}
int32   cprintf(uint8 attr, const char *format,...)
{
    char buffer[80];
    va_list argptr;
    int cnt;

    va_start(argptr, format);
    cnt = vsprintf(buffer, format, argptr);
    va_end(argptr);

    con_putstr(USER_CON, attr, buffer);

    return cnt;
}
/**************************************************************************************************\
*  Вывод символа
\**************************************************************************************************/
void con_putch(int32 con_type, int c)
{
    char character[2];
    character[0]=c;
    character[1]=0;
    con_putstr(con_type, character);
}
void con_putch(int32 con_type, uint8 attr, int c)
{
    char character[2];
    character[0]=c;
    character[1]=0;
    con_putstr(con_type, attr, character);
}
/**************************************************************************************************\
* Функция выводит строку, адрекуемую параметром str, на экран
\***sss********************************************************************************************/
int32   con_putstr(int32 con_type, const char *str)
{
    int32   size;
    int64   seek;
    char    *begin, *crlf;
    size = 0x0;
    begin = (char*)str;
    crlf = strchr(begin,'\n');
    while(crlf != NULL)
    {
        size += con_write(con_type, begin, (int32)(crlf-begin), ATTR_NORMAL);
        seek = (con_position(con_type)/console_axis.width)*console_axis.width+console_axis.width;
        con_seek(con_type, seek);
        begin = crlf + 0x1;
        crlf = strchr(begin,'\n');
    }
    size += con_write(con_type, begin, strlen(begin), ATTR_NORMAL);
    return size;
}
int32   con_putstr(int32 con_type, uint8 attr, const char *str)
{
    int32   size;
    int64   seek;
    char    *begin, *crlf;
    size = 0x0;
    begin = (char*)str;
    crlf = strchr(begin,'\n');
    while(crlf != NULL)
    {
        size += con_write(con_type, begin, (int32)(crlf-begin), attr);
        seek = (con_position(con_type)/console_axis.width)*console_axis.width+console_axis.width;
        con_seek(con_type, seek);
        begin = crlf + 0x1;
        crlf = strchr(begin,'\n');
    }
    size += con_write(con_type, begin, strlen(begin), attr);
    return size;
}
/**************************************************************************************************\
* Отчистка экрана
\***sss********************************************************************************************/
void con_clrscr(int32 con_type)
{
    con_clear(con_type);
}
/**************************************************************************************************\
* Отчистка символов
\***sss********************************************************************************************/
void con_clrbar(int32 con_type, uint32 y, uint32 d_y)
{
    con_gotoxy(con_type, 0, y);
    con_clear_position(con_type, d_y);
}
/**************************************************************************************************\
*          Функция GOTOXY()
*--------------------------------------
* Перемешает "курсор" по заданным координатам
* X[0;31]   +-->(x)
* Y[0;15]   |
*           |(y)
\***sss********************************************************************************************/
void con_gotoxy(int32 con_type, uint32 x, uint32 y)
{
    int64 seek;
    seek = (y * console_axis.width) + x; 
    con_seek(con_type, seek);
}
/**************************************************************************************************\
*       Установка аттрибутов тексту
\***sss********************************************************************************************/
void con_set_text_attribute(int32 con_type, uint32 x, uint32 y, uint32 length, uint8 attr)
{
    con_gotoxy(con_type, x, y);
    con_write_attr(con_type, length, attr);
}
/**************************************************************************************************\
*       Включение/Выключение курсора
\***sss********************************************************************************************/
void con_cursor_enable()
{
    con_cursor_visibility(1);
}
void con_cursor_disable()
{
    con_cursor_visibility(0);
}
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//
//      API Функции работы с клавиатурой
//
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
/**************************************************************************************************\
*          Функция GETCH()
*--------------------------------------
* Возвращает значение нажатой клавиши в младшем байте
\***sss********************************************************************************************/
int32 getch()
{
    if(fg_con_init==false) return 0x0;
    int32   error, inkey;
    uint32  key[2];
    error  = drv_ioctl(kbd_file, HID_GETEVENT, &key[0]);
    error |= drv_ioctl(kbd_file, HID_GETEVENT, &key[1]);
    if(error!=OSE_OK) return 0x0;
    switch ( HID_KEYBOARD_SCANCODE(key[0]) )
    {
        case KB_0: inkey = '0'; break;
        case KB_1: inkey = '1'; break;
        case KB_2: inkey = '2'; break;
        case KB_3: inkey = '3'; break;
        case KB_4: inkey = '4'; break;
        case KB_5: inkey = '5'; break;
        case KB_6: inkey = '6'; break;
        case KB_7: inkey = '7'; break;
        case KB_8: inkey = '8'; break;
        case KB_9: inkey = '9'; break;
        case KB_A: inkey = 'a'; break;
        case KB_B: inkey = 'b'; break;
        case KB_C: inkey = 'c'; break;
        case KB_D: inkey = 'd'; break;
        case KB_E: inkey = 'e'; break;
        case KB_F: inkey = 'f'; break;

        case KB_ESCAPE     : inkey = KEY_ESC;     break;         
        case KB_ENTER      : inkey = KEY_ENTER;   break;      
        case KB_LEFT_SHIFT : inkey = KEY_SHIFT;   break;    
        case KB_BACKSPACE  : inkey = KEY_DEL;     break;    
        case KB_LEFT_ARROW : inkey = KEY_LEFT;    break;    
        case KB_DOWN_ARROW : inkey = KEY_DOWN;    break;    
        case KB_RIGHT_ARROW: inkey = KEY_RIGHT;   break;      
        case KB_UP_ARROW   : inkey = KEY_UP;      break;         
        case KB_SYS_HIDDEN : inkey = KEY_HIDDEN;  break;         
    }                                                 
    return inkey;
}
/**************************************************************************************************\
*          Функция KBHIT()
*--------------------------------------
* Возвращает значение последней нажатой клавиши
* Если ни чего не нажимали, то возвращает 0
\***sss********************************************************************************************/
int32 kb_hit()
{
    int32  key;
    uint32 get_key;
    if(fg_con_init==false) return 0x0;
    if( drv_ioctl(kbd_file, HID_PRBEVENT, &get_key) != OSE_OK) return 0x0;
    switch (HID_KEYBOARD_SCANCODE(get_key))
    {
        case KB_0: key = '0'; break;
        case KB_1: key = '1'; break;
        case KB_2: key = '2'; break;
        case KB_3: key = '3'; break;
        case KB_4: key = '4'; break;
        case KB_5: key = '5'; break;
        case KB_6: key = '6'; break;
        case KB_7: key = '7'; break;
        case KB_8: key = '8'; break;
        case KB_9: key = '9'; break;
        case KB_A: key = 'a'; break;
        case KB_B: key = 'b'; break;
        case KB_C: key = 'c'; break;
        case KB_D: key = 'd'; break;
        case KB_E: key = 'e'; break;
        case KB_F: key = 'f'; break;

        case KB_ESCAPE     : key = KEY_ESC;    break;         
        case KB_ENTER      : key = KEY_ENTER;  break;      
        case KB_LEFT_SHIFT : key = KEY_SHIFT;  break;    
        case KB_BACKSPACE  : key = KEY_DEL;    break;    
        case KB_LEFT_ARROW : key = KEY_LEFT;   break;    
        case KB_DOWN_ARROW : key = KEY_DOWN;   break;    
        case KB_RIGHT_ARROW: key = KEY_RIGHT;  break;      
        case KB_UP_ARROW   : key = KEY_UP;     break;
        case KB_SYS_HIDDEN : key = KEY_HIDDEN; break; 
        default: key = 0x00;
    }                                                 
    return key;
}
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//
//      Функции управления консолью
//
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
#define NUMBER_CONSOLE  2
struct  s_console
{
    int64       seek;
    char*       character;
    uint8*      attribute;
}; 

uint32          dspl_file;
uint32          console_sem;
int64           console_eof;
uint32          console_cursor_enable;
s_console       console[NUMBER_CONSOLE];
char*           dspl_char;
uint8*          dspl_attr;

void dspl_refresh(int64 seek, int32 length);
void dspl_set_cursor(int64 seek);
/**************************************************************************************************\
*   Инициализация
\***sss********************************************************************************************/
int32 con_init()
{
    int32   error, stage;
    uint32  mode;
    s_display_char_buffer chars;

    stage = 0;
    //========================================================================
    //*** STAGE1 ***
    dspl_file = drv_mkd("/dev/lcd"); 
    if(dspl_file == RES_VOID)
    {
        stage = 1;
        error = OSE_NO_NODE;
        goto m_return;
    }  
    res_share(dspl_file);
    //*** STAGE2 ***
    console_sem = sem_alloc(1,NULL);    
    if(console_sem == RES_VOID)
    {
        stage = 2;
        error = OSE_CANT_CREATE_SEM;
        goto m_return;
    }
    //*** STAGE3 ***
    chars.code = 0x80;
    chars.buffer = (uint8*)sios_char;
    chars.size = sizeof(sios_char);
    error  = drv_ioctl(dspl_file, DSPL_LOAD_KEYGEN_BUFFER , &chars);
    
    mode   = MODE_DISPLAY_TEXT;
    error |= drv_ioctl(dspl_file, DSPL_SET_MODE, &mode);
    
    mode   = CURSOR_DISABLE;
    error |= drv_ioctl(dspl_file, DSPL_SET_CURSOR_VISIBILITY, &mode);
    
    console_cursor_enable = 0;
    error |= drv_ioctl(dspl_file, DSPL_GET_RESOLUTION, &console_axis);
    
    console_eof = console_axis.x*console_axis.y;
    error |= drv_open(dspl_file, DRV_WR);
    
    if(error)
    {
        stage = 3;
        goto m_return;
    }
    //*** STAGE4 ***
    dspl_char = new char[console_eof];
    dspl_attr = new uint8[console_eof];
    if(dspl_char == NULL||dspl_attr == NULL)
    {
        stage = 4;
        error = OSE_NO_MEMORY;
        goto m_return;
    }
    //*** STAGE5 ***
    for(int32 i=0; i<NUMBER_CONSOLE; i++)
    {
        console[i].seek = 0x0;
        console[i].character = NULL;
        console[i].attribute = NULL;
    }
    for(int32 i=0; i<NUMBER_CONSOLE; i++)
    {       
        console[i].character = new char[console_eof];
        console[i].attribute = new uint8[console_eof];
        if(console[i].character == NULL||console[i].attribute == NULL)
        {
            stage = 5;
            error = OSE_NO_MEMORY;
            goto m_return;
        }
        else
        {
            memset(console[i].character, 0x00, console_eof);    
            memset(console[i].attribute, 0xFF, console_eof);    
        }
    }
    //========================================================================
    //*** STAGE6 ***
    kbd_file = drv_mkd("/dev/kbd0"); 
    if(kbd_file == RES_VOID)
    {
        stage = 6;
        error = OSE_NO_NODE;
        goto m_return;
    }  
    res_share(kbd_file);
    fg_con_init = true;
    error = OSE_OK;
m_return:
    switch(stage)
    {
        case 6:     drv_rmd(kbd_file);
        case 5:     for(int32 i=0; i<NUMBER_CONSOLE; i++)
                    {
                        delete console[i].character;
                        delete console[i].attribute;
                    }
        case 4:     delete dspl_char;
                    delete dspl_attr;
        case 3:     drv_close(dspl_file);
        case 2:     sem_free(console_sem);
        case 1:     drv_rmd(dspl_file);
    }
    return error;
}
/**************************************************************************************************\
*   Деинициализация
\***sss********************************************************************************************/
void con_deinit()
{
    if(fg_con_init == true)
    {
        fg_con_init = false;
        drv_rmd(kbd_file);    
        for(int32 i=0; i<NUMBER_CONSOLE; i++)    
        {    
            delete console[i].character;    
            delete console[i].attribute;    
        }    
        delete dspl_char;    
        delete dspl_attr;    
        drv_close(dspl_file);    
        sem_free(console_sem);    
        drv_rmd(dspl_file);    
    }
}
/**************************************************************************************************\
*   Вывод на консоль
\***sss********************************************************************************************/
int32 con_write(int32 con_type, const char *str, int32 length, uint8 attr)
{
    if(fg_con_init==false) return 0;
    int32       size;
    s_console*  con = &console[con_type];
    sem_lock(console_sem, SEM_INFINITY);
    size = (con->seek+length<=console_eof) ? length : console_eof-con->seek;
    memcpy(&con->character[con->seek], str, size);
    memset(&con->attribute[con->seek], attr, size);
    dspl_refresh(con->seek, size);
    con->seek += size;
    dspl_set_cursor(console[USER_CON].seek);
    sem_unlock(console_sem);
    return size;
}
/**************************************************************************************************\
*   Вывод на консоль
\***sss********************************************************************************************/
int32 con_write_attr(int32 con_type, int32 length, uint8 attr)
{
    if(fg_con_init==false) return 0;
    int32       size;
    s_console*  con = &console[con_type];
    sem_lock(console_sem, SEM_INFINITY);
    size = (con->seek+length<=console_eof) ? length : console_eof-con->seek;
    memset(&con->attribute[con->seek], attr, size);
    dspl_refresh(con->seek, size);
    con->seek += size;
    sem_unlock(console_sem);
    return size;
}
/**************************************************************************************************\
*   Отчистка консоли
\***sss********************************************************************************************/
void con_clear(int32 con_type)
{
    if(fg_con_init==false) return;
    s_console*  con = &console[con_type];
    sem_lock(console_sem, SEM_INFINITY);
    memset(con->character, 0x00, console_eof);
    memset(con->attribute, 0xFF, console_eof);
    con->seek = 0x0;
    dspl_refresh(con->seek, console_eof);
    dspl_set_cursor(console[USER_CON].seek);
    sem_unlock(console_sem);
}
/**************************************************************************************************\
*   Вывод на консоль
\***sss********************************************************************************************/
void con_clear_position(int32 con_type, int32 length)
{
    if(fg_con_init==false) return;
    int32       size;
    s_console*  con = &console[con_type];
    sem_lock(console_sem, SEM_INFINITY);
    size = (con->seek+length<=console_eof) ? length : console_eof-con->seek;
    memset(&con->character[con->seek], 0x00, size);
    memset(&con->attribute[con->seek], 0xFF, size);
    dspl_refresh(con->seek, size);
    con->seek += size;
    dspl_set_cursor(console[USER_CON].seek);
    sem_unlock(console_sem);
}
/**************************************************************************************************\
*   Видимость курсора
\***sss********************************************************************************************/
void con_cursor_visibility(int32 enable)
{
    if(fg_con_init==false) return;
    drv_ioctl(dspl_file, DSPL_SET_CURSOR_VISIBILITY, &enable);  
    console_cursor_enable = enable;
    dspl_set_cursor(console[USER_CON].seek);
}
/**************************************************************************************************\
*   Позиция смещения
\***sss********************************************************************************************/
int64 con_position(int32 con_type)
{
    if(fg_con_init==false) return 0;
    return console[con_type].seek;
}
/**************************************************************************************************\
*   Установка смещения
\***sss********************************************************************************************/
void con_seek(int32 con_type, int64 seek)
{
    if(fg_con_init==false) return;
    sem_lock(console_sem, SEM_INFINITY);
    console[con_type].seek = (seek>=console_eof) ? console_eof : seek;
    dspl_set_cursor(console[USER_CON].seek);
    sem_unlock(console_sem);
}
/**************************************************************************************************\
*   Обновить дисплей
\***sss********************************************************************************************/
void dspl_refresh(int64 seek, int32 length)
{
    uint32 fg_color, bg_color, size, attr;
    for(int32 i=0; i<console_eof; i++)
    {
        dspl_char[i] = (console[SYS_CON].character[i]==0x00)?console[USER_CON].character[i]:console[SYS_CON].character[i];
        dspl_attr[i] = (console[SYS_CON].attribute[i]==0xFF)?console[USER_CON].attribute[i]:console[SYS_CON].attribute[i];
        dspl_char[i] = (dspl_char[i]==0x00)?' ':dspl_char[i];
        dspl_char[i] = (dspl_char[i]==0xFF)?ATTR_NORMAL:dspl_char[i];        
    }

    drv_ioctl(dspl_file, IOC_SEEK, &seek);      
    while(length)
    {
        attr = dspl_attr[seek];
        size = 0x0;
        for(int64 i=seek; i<seek+length; i++)
        {
            if(dspl_attr[i]!=attr)  break;
            size++;
        }

        switch(attr)
        {
            default:
            case ATTR_NORMAL:
                fg_color = 0x00000000;
                bg_color = 0x00FFFFFF;
                break;
            case ATTR_REVERSE:
                fg_color = 0x00FFFFFF;
                bg_color = 0x00000000;
                break;
            case ATTR_BLINK_NORMAL:  
                fg_color = 0xFF000000;
                bg_color = 0x00FFFFFF;
                break;
            case ATTR_BLINK_REVERSE:
                fg_color = 0xFFFFFFFF;
                bg_color = 0x00000000;
                break;
        }
        drv_ioctl(dspl_file, DSPL_SET_FOREGROUND_COLOR, &fg_color); 
        drv_ioctl(dspl_file, DSPL_SET_BACKGROUND_COLOR, &bg_color);

        drv_write(dspl_file, &dspl_char[seek], size);
        seek += size;
        length -= size;
    }
}
/**************************************************************************************************\
*   Установка курсора
\***sss********************************************************************************************/
void dspl_set_cursor(int64 seek)
{
    if(console_cursor_enable)
    {
        s_display_axis  curs_axis;
        curs_axis.x = seek%console_axis.width;
        curs_axis.y = seek/console_axis.width;
        drv_ioctl(dspl_file, DSPL_SET_CURSOR_POSITION, &curs_axis); 
    }
}
