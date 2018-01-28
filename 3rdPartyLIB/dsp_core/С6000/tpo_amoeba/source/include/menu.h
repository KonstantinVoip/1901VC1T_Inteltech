//**************************************************************************************************
//                         Copyright (C) 2010 RCZI
//--------------------------------------------------------------------------------------------------
// FILENAME....... menu.h
// DATE CREATED... 19/02/2010
//--------------------------------------------------------------------------------------------------
//                                MENU CLASS
//--------------------------------------------------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
//
// !: codepage: cp1251 
//
// !: d: Класс меню.<br>
// !: md: Модуль содержит описание класса меню.
// !: -:
//***sss********************************************************************************************
#ifndef     __Menu_class_H__
#define     __Menu_class_H__
#include    <os_types.h>
class cs_menu
{
  private:
    void           (*funct)(cs_menu*,void*); 
    void           (*hidden_funct)(cs_menu*,bool,void*); 
    void*          arg;
    void*          hidden_arg;
    bool*          check;
    bool           hidden_present;
    int32          number_childs;
    int32          cursor_seek;
    int32          menu_seek;
    int32          type;
    cs_menu*       new_node(int32 itype);
    void           action();
    void           put_menu();
    void           put_menu_line(int32 y, uint8 select, int32 number);
    void           put_path();
  public:
    cs_menu();
    ~cs_menu();
    cs_menu*       prev;
    cs_menu*       next;
    cs_menu*       child;
    cs_menu*       parent;
    cs_menu*       temp;
    char*          name;
    cs_menu*       create(void (*callfunct)(cs_menu*,void*), void* arg, char* name);
    cs_menu*       checkbox(void (*callfunct)(cs_menu*,void*), void* arg, bool* check, char* name);
    bool           remove(cs_menu* item);
    void           run();
    void           hidden(void (*callfunct)(cs_menu*,bool,void*), void* ihidden_arg);
    bool           getcheck();
};
#endif //__Menu_class_H__

