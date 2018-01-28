//**************************************************************************************************
//                         Copyright (C) 2010 RCZI
//--------------------------------------------------------------------------------------------------
// FILENAME....... menu.cpp
// DATE CREATED... 19/02/2010
// LAST MODIFIED.. 16/09/2010
// VERSION........ 1.1
//--------------------------------------------------------------------------------------------------
//                                MENU CLASS
//--------------------------------------------------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
//
// !: codepage: cp1251 
//
// !: d: Класс меню.<br>
// !: md: Модуль содержит набор функций для динамического создания, удаления и работы с меню.
// !: -:
//***sss********************************************************************************************
#include    <rts.h>
#include    "console.h"
#include    "menu.h"

#define MENU_X_AXIS         1
#define MENU_Y_AXIS         4
#define MENU_LINES          10
#define PATH_Y_AXIS         2
#define PATH_LENGTH         30
#define CURSOR_LENGTH       28
#define NAME_LENGTH         22
#define MENU_Y_HELP         15

#define TYPE_LEAF           1
#define TYPE_SUBMENU        2
#define TYPE_CHECKBOX       3

/**************************************************************************************************\
*   Конструкторы
\***sss********************************************************************************************/
cs_menu::cs_menu()
{
  prev = NULL;
  next = NULL;
  child = NULL;
  parent = NULL;
  temp = NULL;
  funct = NULL;
  hidden_funct = NULL; 
  hidden_present = false;
  arg = NULL;
  hidden_arg = NULL;
  name = NULL;
  number_childs = 0;
  cursor_seek = 0;
  menu_seek = 0;
  type = 0;
  check = false;
}
cs_menu::~cs_menu()
{
  cs_menu *node, *temp_node;
  node = child;
  while(node != NULL)
  {
    temp_node = node;
    node = node->next;    
    remove(temp_node);    
  }
}
/**************************************************************************************************\
*   Добавление элемента
\***sss********************************************************************************************/
cs_menu* cs_menu::new_node(int32 itype)
{
  cs_menu* node;
  if(number_childs < 99) node = new cs_menu;
  else node = NULL;
  if(node != NULL)
  {
    if(child == NULL)
    {
      child = node;
      node->prev = NULL;
    }
    else
    {   
      cs_menu* last_child = child;
      do{
        if(last_child->next == NULL)
        {
          last_child->next = node;
          node->prev = last_child;
          break;
        }
        last_child = last_child->next;
      }while(true);
    }
    node->parent = this;
    node->type = itype;
    number_childs++;
    type = TYPE_SUBMENU;
  }
  return node;
}
/**************************************************************************************************\
*   Добавление элемента меню
\***sss********************************************************************************************/
cs_menu* cs_menu::create(void (*callfunct)(cs_menu*,void*), void* arg, char* name)
{
  cs_menu* node;
  node = new_node(TYPE_LEAF);
  if(node != NULL)
  {
    node->funct  = callfunct;
    node->arg    = arg; 
    node->name   = name;
  }
  return node; 
}
/**************************************************************************************************\
*   Добавление элемента меню 
\***sss********************************************************************************************/
cs_menu*  cs_menu::checkbox(void (*callfunct)(cs_menu*,void*), void* arg, bool* check, char* name)
{
  cs_menu* node;
  node = new_node(TYPE_CHECKBOX);
  if(node != NULL)
  {
    node->funct  = callfunct;
    node->arg    = arg; 
    node->name   = name;
    node->check  = check;
  }
  return node; 

}
/**************************************************************************************************\
*   Удаление элемента меню
\***sss********************************************************************************************/
bool cs_menu::remove(cs_menu* node)
{
  if(node == NULL) return false;
  
  cs_menu *temp_node = child;
  while(temp_node != NULL)
  {
    if(temp_node == node) break;
    temp_node = temp_node->next;
  }
  if(temp_node == NULL)
    return false;
      
  if(node->prev == NULL && node->next == NULL)
    child = NULL;
  else
  if(node->prev == NULL)
  {
    child = node->next;
    node->next->prev = NULL;
  }
  else
  if(node->next == NULL)
    node->prev->next = NULL;
  else
  {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }
  number_childs--;
  if(number_childs == 0) 
    type = TYPE_LEAF;
  delete node;
  return true;
}
/**************************************************************************************************\
*   Запуск меню
\***sss********************************************************************************************/
void cs_menu::run()
{
  bool        exit;
  int32       key;
  exit = false;
  while(exit==false)
  {
    put_menu();
    key = getch();
    if( ('1' <= key)&&(key <= '9') )
    {
      if( (key-'0') <= number_childs )
      {
        cursor_seek = key - '0' - 1;
        action();
      }
      continue;
    }
    switch(key)
    {
      case KEY_UP:
      {
        cursor_seek = (cursor_seek == 0) ? number_childs-1 : --cursor_seek;
      }
      break;
      case KEY_DOWN:
      {
        cursor_seek = (cursor_seek == number_childs-1) ? 0 : ++cursor_seek;
      }
      break;
      case KEY_ENTER:
      {
        action();
      }
      break;
      case KEY_ESC:
      {
        exit = true;
        clrscr();
      }
      break;
      case KEY_HIDDEN:
      {
        if(hidden_funct != NULL)
        {
          hidden_funct(this, hidden_present, this->hidden_arg);
          hidden_present = !hidden_present;
        }
      }
      break;
    }
  }
  cursor_seek = 0;
}
/**************************************************************************************************\
*   Добавление вызова скрытой функции
\***sss********************************************************************************************/
void cs_menu::hidden(void (*callfunct)(cs_menu*,bool,void*), void* ihidden_arg)
{
  hidden_funct = callfunct;
  hidden_arg = ihidden_arg;
}
/**************************************************************************************************\
*   Вызов функции
\***sss********************************************************************************************/
void cs_menu::action()
{
  int32     temp_cursor_seek;
  cs_menu*  node;
  temp_cursor_seek = cursor_seek;
  node = child;
  while(node != NULL)
  {       
    if(temp_cursor_seek == 0)
    {
      switch(node->type)
      {
        case TYPE_LEAF:
        {
          if(node->funct != NULL)
            node->funct(node, node->arg);                
        }
        return;
        case TYPE_SUBMENU:
        {
          node->run();
        }
        return;
        case TYPE_CHECKBOX:
        {
          *node->check = !*node->check;
          if(node->funct != NULL)
            node->funct(node, node->arg);                
        }
        return;
      }
    }
    temp_cursor_seek--;
    node = node->next;
  }
}
/**************************************************************************************************\
*   Вывести меню
\***sss********************************************************************************************/
void cs_menu::put_menu()
{
  cs_menu*    node;
  int32       select, dy;
  //Установка смешений курсора:
  if(cursor_seek >= number_childs)
    cursor_seek = number_childs-1;     
  //Установка смешения меню:
  if(menu_seek+MENU_LINES > number_childs)
    menu_seek -= menu_seek+MENU_LINES-number_childs;
  if(menu_seek < 0) 
    menu_seek = 0;
  if(cursor_seek >= menu_seek+MENU_LINES)
    menu_seek = cursor_seek-MENU_LINES+1;
  if(cursor_seek < menu_seek)
    menu_seek = cursor_seek;
  //Поиск первого отображаемого пункта меню:
  select = cursor_seek;
  node = child;
  for(int32 k=0; k<menu_seek; k++)
  {
    select--;
    node = node->next;
  }
  //Вывод индикаторов:
  clrscr();
  if(menu_seek>0)
  {
    gotoxy(MENU_X_AXIS+CURSOR_LENGTH/2-2, MENU_Y_AXIS-1);
    putstr("....");
  }
  if(menu_seek<number_childs-MENU_LINES)
  {
    gotoxy(MENU_X_AXIS+CURSOR_LENGTH/2-2, MENU_Y_AXIS+MENU_LINES);
    putstr("....");
  }
  //Вывод меню:    
  dy = 0;
  for(int32 i=menu_seek; i<MENU_LINES+menu_seek; i++)
  {
    if(i==number_childs+menu_seek) break;
      node->put_menu_line(MENU_Y_AXIS+dy, (select==0)?1:0, i+1);
    dy++;
    select--;
    node = node->next;
  }
  put_path();
}
/**************************************************************************************************\
*   Вывести строчку меню
\***sss********************************************************************************************/
void cs_menu::put_menu_line(int32 y, uint8 select, int32 number)
{
  char              line[CURSOR_LENGTH+1];
  char              num[4];
  register int32    length;
  register uint8    attr;
  
  attr = (select) ? ATTR_REVERSE : ATTR_NORMAL;
  memset(line,' ',sizeof(line));
  line[CURSOR_LENGTH] = 0;
  //Формирование номера меню:
  itoa(number, num);
  if(number < 10) memcpy(&line[2], num, 1);
  else memcpy(&line[1], num, 2);
  line[3] = '-';
  //Формирование название меню:  
  length = strlen(name);
  if(length<=NAME_LENGTH)
    memcpy(&line[4],name,length); 
  else
  {
    memcpy(&line[4],name,NAME_LENGTH-1);
    memset(&line[4+NAME_LENGTH-1],'}',1);
  }
  //Добавление флажков:
  if(select)
  {
    clrbar(MENU_Y_HELP, 30);
    gotoxy(0, MENU_Y_HELP);
  }
  switch(type)
  {
    case TYPE_LEAF:
    {
      if(select) putstr("<ENTER> - Выполнить");
    }
    break;
    case TYPE_SUBMENU:
    {
      if(select) putstr("<ENTER> - Выбрать");
    }
    break;
    case TYPE_CHECKBOX:
    {
      if(*check == true)
      {
        line[0] = CHAR_CHECKBOX;
        if(select) putstr("<ENTER> - Снять");
      }
      else
      {
        line[0] = CHAR_UNCHECKBOX;
        if(select) putstr("<ENTER> - Отметить");
      }
    }
    break;
  }
  if(select) set_text_attribute(0,MENU_Y_HELP,30,ATTR_REVERSE);
  //Вывод строчки:
  gotoxy(MENU_X_AXIS, y);
  putattrstr(attr, line);
}
/**************************************************************************************************\
*   Вывести путь меню
\***sss********************************************************************************************/
void cs_menu::put_path()
{
  cs_menu*  node;
  char      path[PATH_LENGTH+1];
  int32     point, count, length;
  memset(path,' ',sizeof(path));
  point = PATH_LENGTH+1;
  
  path[--point] = 0;
  memset(&path[--point],'>',1);
  
  if(name != NULL)
  {
    length = strlen(name);
    count = (length<=point) ? length : point;
    point -= count;
    memcpy(&path[point], &name[length-count], count);
    if(point == 0)
    {
      memcpy(path, "..", 2);
      goto m_print; 
    }
  }
  memset(&path[--point],'/',1);
  if(point == 0) goto m_print;  
  
  node = parent;
  while(node != NULL)
  {
    if(node->name != NULL)
    {
      length = strlen(node->name);
      count = (length<=point) ? length : point;
      point -= count;
      memcpy(&path[point], &node->name[length-count], count);
      if(point == 0)
      {
        memcpy(path, "..", 2);
        goto m_print;   
      }
      memset(&path[--point],'/',1);
      if(point == 0) goto m_print;  
    }
    node = node->parent;
  }
m_print:
  gotoxy(0, PATH_Y_AXIS);
  putstr(&path[point]);
}
/**************************************************************************************************\
*   Взятие флажка
\***sss********************************************************************************************/
bool cs_menu::getcheck()
{
  return *check;
}

