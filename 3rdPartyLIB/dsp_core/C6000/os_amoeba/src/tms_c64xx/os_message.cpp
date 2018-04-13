/**********************************************************************************************************************
*                                        (c) COPYRIGHT by ZAO RCZI FORT.                                             *
*        ..                                       All rights reserved.                                               *
***********************************************************************************************************************
* Module      : os_message.cpp
* Description : Модуль содержит реализацию менеджера системного обмена.
* Author      : 
******************************************************************************
******************************************************************************
* Module's Description Record:
* ============================
* Module's revision history:
* ==========================
* --------- $Log:  $
* --------- [os_message.cpp]
******************************************************************************/
#define SYSCALL_DIRECT
#include <os.h>
// ---------------------------------------------------------------------------
#ifdef OS_SUPPORT_SYSLOG
static const char* os_module = { __FILE__ };
#endif
// ---------------------------------------------------------------------------

#define MSGT_DISCOVER_REQUEST   0xaf0000fa
#define MSGT_DISCOVER_REPLY     0xaf0110fa
#define MSGT_SEED               0xaf0220fa

#define USER_MESSAGE            ((s_message_pipe*)0x00000000)
#define SYSTEM_MESSAGE          ((s_message_pipe*)0xffffffff)

// ---------------------------------------------------------------------------

struct s_discover_request
{
  uint32                        type;
  uint32                        sender;
  uint32                        reqid;
  char                          name[24];
};

struct s_discover_reply
{
  uint32                        type;
  uint32                        sender;
  uint32                        reqid;
  uint32                        pid;
};

struct s_seed
{
  uint32                        type;
  uint32                        id;
  char                          name[24];
};

// ---------------------------------------------------------------------------

s_message_pipe* msg_pipe_ring;
static int32 msg_pipe_count;
static uint32 msg_pipe_sem;
static uint32 msg_reqid_sem;
static uint32 msg_reqid;

static uint32 msg_locker;

static uint32 msg_processor_id;
static uint32 msg_processor_max;

static s_message_pipe** msg_route_table;

static s_message_process_data* msg_process_list;
static uint32 msg_process_list_sem;
static int32 msg_process;

static bool msg_terminate;
static s_message_queue msg_inq;
static uint32 msg_limit_sem;

// ---------------------------------------------------------------------------
// !: fn: void os_message_init_module()
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция инициализирует модуль системного обмена. Функция не доступна
// !: d: пользователю.
// ---------------------------------------------------------------------------
void os_message_init_module()
{
  int32 r = msg_queue_init( &msg_inq );

  msg_limit_sem = sem_alloc( 1, NULL );

  msg_processor_id = 0xffffffff;
  msg_processor_max = 0;

  msg_pipe_ring = NULL;
  msg_pipe_count = 0;
  msg_pipe_sem = sem_alloc( 1, NULL );
  
  msg_route_table = NULL;
  
  msg_process_list = NULL;
  msg_process_list_sem = sem_alloc( 1, NULL );
  msg_process = 0;

  msg_terminate = false;

  msg_locker = sem_alloc( 0, NULL );

  msg_reqid_sem = sem_alloc( 1, NULL );
  msg_reqid = 0;

  if( ( msg_locker == RES_VOID ) || ( msg_pipe_sem == RES_VOID ) ||
      ( msg_process_list_sem == RES_VOID ) || ( msg_limit_sem == RES_VOID ) ||
      ( msg_reqid_sem == RES_VOID ) || ( r != OSE_OK ) )
  {
    while( true )
      asm( " nop " );
  }
}
// ---------------------------------------------------------------------------
// !: fn: void os_message_cleanup()
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция завершает системный обмен завершающегося процесса. Функция не
// !: d: доступна пользователю.
// ---------------------------------------------------------------------------
void os_message_cleanup()
{
  os_message_close();
}
// ---------------------------------------------------------------------------
static uint32 msgll_reqid()
{
  uint32 r;
  sem_lock( msg_reqid_sem, SEM_INFINITY );
  if( msg_reqid == 0 ) msg_reqid++;
  r = msg_reqid;
  msg_reqid++;
  sem_unlock( msg_reqid_sem );
  return r;
}
// ---------------------------------------------------------------------------
static int32 msgll_drvctx_add( s_message_context* ctx, int32 limit )
{
  s_message_pipe* npipe;

  npipe = (s_message_pipe*)heap_alloc( NULL, sizeof(s_message_pipe), HEAP_ALIGN_4 );
  if( npipe == NULL ) return OSE_NO_MEMORY;
  memset( npipe, 0, sizeof(s_message_pipe) );
  
  if( ( npipe->limit_sem = sem_alloc( limit, NULL ) ) == RES_VOID )
  {
    heap_free( NULL, npipe );
    return OSE_CANT_CREATE_SEM;
  }

  OS_SUPPORT__syn_begin();
  sem_lock( msg_pipe_sem, SEM_INFINITY );

  if( msg_pipe_ring == NULL )
  {
    npipe->next = npipe;
    npipe->prev = npipe;
    msg_pipe_ring = npipe;
  }
  else
  {
    npipe->next = msg_pipe_ring;
    npipe->prev = msg_pipe_ring->prev;
    msg_pipe_ring->prev->next = npipe;
    msg_pipe_ring->prev = npipe;
  }
  msg_pipe_count++;

  npipe->outq = ctx->outq;
  ctx->inq = &msg_inq;
  ctx->pipe = npipe;

  sem_unlock( msg_pipe_sem );
  OS_SUPPORT__syn_end();

  return OSE_OK;
}
// ---------------------------------------------------------------------------
static int32 msgll_rebuild_route_table()
{
  uint32 k;
  int32 i, j;
  s_message_pipe* p;
  s_message_link* l;

  heap_free( NULL, msg_route_table );

  // Find maximal value of processors id
  for( msg_processor_max = 0, p = msg_pipe_ring, i = 0; i < msg_pipe_count; i++ )
  {
    for( l = p->route, j = 0; j < p->route_count; j++ )
    {
      if( l->id > msg_processor_max ) msg_processor_max = l->id;
      l = l->next;
    }
    p = p->next;
  }

  // Allocate new route table
  k = ( msg_processor_max >> 16 ) + 1;
  msg_route_table = (s_message_pipe**)heap_alloc( NULL, sizeof(s_message_pipe*) * k, HEAP_ALIGN_4 );
  if( msg_route_table == NULL ) return OSE_NO_MEMORY;
  memset( msg_route_table, 0, sizeof(s_message_link*) * k );
  
  // Fill route table
  for( p = msg_pipe_ring, i = 0; i < msg_pipe_count; i++ )
  {
    for( l = p->route, j = 0; j < p->route_count; j++ )
    {
      msg_route_table[l->id>>16] = p;
      l = l->next;
    }
    p = p->next;
  }

  return OSE_OK;
}
// ---------------------------------------------------------------------------
static int32 msgll_link_add( s_message_pipe* p, uint32 id, const char* name )
{
  s_message_link* nlink;
  s_message_link* clink;
  int32 i;

  nlink = (s_message_link*)heap_alloc( NULL, sizeof(s_message_link), HEAP_ALIGN_4 );
  if( nlink == NULL ) return OSE_NO_MEMORY;
  memset( nlink, 0, sizeof(s_message_link) );

  nlink->id = id;
  strcpy( nlink->name, name );

  OS_SUPPORT__syn_begin();
  sem_lock( msg_pipe_sem, SEM_INFINITY );

  clink = p->route;
  for( i = 0; i < p->route_count; i++ )
  {
    if( strcmp( clink->name, nlink->name ) == 0 )
    {
      heap_free( NULL, nlink );
      
      sem_unlock( msg_pipe_sem );
      OS_SUPPORT__syn_end();

      return OSE_ALREADY_ADDED;
    }
    clink = clink->next;
  }

  if( p->route == NULL )
  {
    nlink->next = nlink;
    nlink->prev = nlink;
    p->route = nlink;
  }
  else
  {
    nlink->next = p->route;
    nlink->prev = p->route->prev;
    p->route->prev->next = nlink;
    p->route->prev = nlink;
  }
  p->route_count++;
  
  sem_unlock( msg_pipe_sem );
  OS_SUPPORT__syn_end();

  return msgll_rebuild_route_table();
}
// ---------------------------------------------------------------------------
static void msgll_process_del( s_message_process_data* p )
{
  char* pname;

  OS_SUPPORT__syn_begin();
  sem_lock( msg_process_list_sem, SEM_INFINITY );

  if( msg_process_list == p )
  {
    msg_process_list = p->next;
    if( msg_process_list ) msg_process_list->prev = NULL;
  }
  else
  {
    if( p->next ) p->next->prev = p->prev;
    if( p->prev ) p->prev->next = p->next;
  }
  p->prev = NULL;
  p->next = NULL;
  p->avg_ppid = 0;
  pname = p->name;
  p->name = NULL;

  sem_unlock( msg_process_list_sem );
  OS_SUPPORT__syn_end();

  heap_free( NULL, pname );
  msg_queue_deinit( &p->inq );
}
// ---------------------------------------------------------------------------
// !: fn: int32 os_message_open( const char* name )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall псевдоним:</b><br>
// !: d: <br>
// !: d: msg_open<br>
// !: d: <br>
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция сообщает системе о намерении текущего процесса учавствовать в
// !: d: системном обмене. Переменная name указывает на желаемое
// !: d: регистрационное имя процесса.<br>
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: В случае успеха функция возвращает OSE_OK, иначе одну из ошибок:<br><br>
// !: d: <table cellpadding=2 cellspacing=2 border=0>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_NULL_PARAM</td>
// !: d: <td> - </td>
// !: d: <td>указатель на имя процесса name равен нулю;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_TOO_LONG_STRING</td>
// !: d: <td> - </td>
// !: d: <td>желаемое имя процесса слишком длинное;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_NO_MEMORY</td>
// !: d: <td> - </td>
// !: d: <td>недостаточно памяти для регистрации процесса в менеджере системного обмена;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_CANT_CREATE_SEM</td>
// !: d: <td> - </td>
// !: d: <td>ошибка создания одного из семафоров, необходимых для регистрации процесса.</td>
// !: d: </tr>
// !: d: </table><br>
// ---------------------------------------------------------------------------
int32 os_message_open( const char* name )
{
  int32 r;
  s_message_process_data* p;
  s_message_process_data* curp;

  sem_lock( msg_locker, SEM_INFINITY );
  sem_unlock( msg_locker );

  if( name == NULL ) return OSE_NULL_PARAM;
  if( strlen( name ) > 23 ) return OSE_TOO_LONG_STRING;
  if( v_os_current_process->msg.name != NULL )
  {
    if( strcmp( v_os_current_process->msg.name, name ) == 0 ) return OSE_OK;
        return OSE_BAD_NAME;
  }

  p = &v_os_current_process->msg;
  p->name = (char*)heap_alloc( NULL, strlen( name ) + 1, HEAP_ALIGN_4 );
  if( p->name == NULL ) return OSE_NO_MEMORY;
  if( ( r = msg_queue_init( &p->inq ) ) != OSE_OK )
  {
    heap_free( NULL, p->name );
    p->name = NULL;
    return r;
  }
  strcpy( p->name, name );

  OS_SUPPORT__syn_begin();
  sem_lock( msg_process_list_sem, SEM_INFINITY );

  curp = msg_process_list;
  while( curp )
  {
    if( strcmp( curp->name, name ) == 0 )
    {
      sem_unlock( msg_process_list_sem );
      OS_SUPPORT__syn_end();
      heap_free( NULL, p->name );
      p->name = NULL;
      return OSE_NAME_EXISTS;
    }
    curp = curp->next;
  }

  p->prev = NULL;
  if( msg_process_list == NULL )
  {
    p->next = NULL;
  }
  else
  {
    p->next = msg_process_list;
    msg_process_list->prev = p;
  }
  msg_process_list = p;

  sem_unlock( msg_process_list_sem );
  OS_SUPPORT__syn_end();

  return OSE_OK;
}
// ---------------------------------------------------------------------------
// !: fn: int32 os_message_close()
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall псевдоним:</b><br>
// !: d: <br>
// !: d: msg_close<br>
// !: d: <br>
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция сообщает системе о намерении текущего процесса прекратить
// !: d: системный обмен.<br>
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: Функция всегда возвращает OSE_OK.
// ---------------------------------------------------------------------------
int32 os_message_close()
{
  s_message_process_data* p = &v_os_current_process->msg;
  if( p->name == NULL ) return OSE_OK;
  msgll_process_del( p );
  return OSE_OK;
}
// ---------------------------------------------------------------------------
// !: fn: uint32 os_message_discover( const char* hname, const char* pname, uint32 tm_m )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall псевдоним:</b><br>
// !: d: <br>
// !: d: msg_discover<br>
// !: d: <br>
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция пытается определить адрес процесса с именем pname на процессоре
// !: d: (хосте) hname в течении tm_m милисекунд.<br>
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: В случае успеха функция возвращает идентификатор процесса в адресном
// !: d: пространстве системного обмена, иначе RES_VOID.
// ---------------------------------------------------------------------------
uint32 os_message_discover( const char* hname, const char* pname, uint32 tm_m )
{
  s_message_pipe* p;
  s_message_link* l;
  s_message_process_data* pr;
  volatile uint32 r;
  s_discover_request* sm;
  s_message* m;
  uint64 stm, etm, stm2, etm2;
  volatile uint32 ans;
  register uint32 tavgid;
  register uint32 tavgpid;

  if( ( hname == NULL ) || ( pname == NULL ) ) return RES_VOID;
  if( v_os_current_process->msg.name == NULL ) return RES_VOID;
  if( strlen( pname ) > 23 ) return RES_VOID;

  if( tm_m != SEM_INFINITY ) OS_SUPPORT__syn_time_core( stm );

  while( true )
  {
    if( sys_chkname( hname ) == 0 )
    {
      OS_SUPPORT__syn_begin();
      sem_lock( msg_process_list_sem, SEM_INFINITY );
      
      pr = msg_process_list;
      while( pr )
      {
        if( strcmp( pr->name, pname ) == 0 )
        {
          r = RES_T_MSGPIPE | msg_processor_id | (uint32)pr->p->id;

          sem_unlock( msg_process_list_sem );
          OS_SUPPORT__syn_end();
          
          return r;
        }
        pr = pr->next;
      }
    
      sem_unlock( msg_process_list_sem );
      OS_SUPPORT__syn_end();
    }
    else
    {

    l_retry2:

      if( ( m = msg_alloc( sizeof(s_discover_request), USER_MESSAGE ) ) == NULL ) return RES_VOID;

      OS_SUPPORT__syn_begin();
      sem_lock( msg_pipe_sem, SEM_INFINITY );
      
      p = msg_pipe_ring;
      for( int32 p_i = 0; p_i < msg_pipe_count; p_i++ )
      {
        l = p->route;
        for( int32 l_i = 0; l_i < p->route_count; l_i++ )
        {
          if( strcmp( hname, l->name ) == 0 )
          {
            // Form discover request message
            m->from = RES_T_MSGPIPE | msg_processor_id;
            m->to = RES_T_MSGPIPE | l->id;
            sm = (s_discover_request*)m->data;
            sm->type = MSGT_DISCOVER_REQUEST;
            sm->sender = (uint32)v_os_current_process->id;
            ans = msgll_reqid();
            sm->reqid = ans;
            memset( sm->name, 0, sizeof(sm->type) );
            strcpy( sm->name, pname );

            // Send discover request
            v_os_current_process->msg.avg_reqid = 0;
            if( msg_queue_push( &msg_inq, m ) != OSE_OK ) msg_free( m );

            sem_unlock( msg_pipe_sem );
            OS_SUPPORT__syn_end();

            // Waiting for reply
            OS_SUPPORT__syn_time_core( stm2 );
            while( true )
            {
              OS_SUPPORT__syn_time_core( etm2 );

              // Check for global timeout
              if( tm_m != SEM_INFINITY )
              {
                etm = etm2;
                if( ( etm - stm ) >= (uint64)tm_m ) return RES_VOID;
              }

              OS_SUPPORT__syn_begin();
              tavgid = v_os_current_process->msg.avg_reqid;
              tavgpid = v_os_current_process->msg.avg_ppid;
              OS_SUPPORT__syn_end();

              if( ( tavgid == ans ) && ( tavgpid != RES_VOID ) ) break;

              // Check for local timeout
              if( ( etm2 - stm2 ) >= 500llu ) goto l_retry2;

              sleep_m( 10 );
            }
    
            return tavgpid;
          }
          l = l->next;
        }
        p = p->next;
      }
      
      sem_unlock( msg_pipe_sem );
      OS_SUPPORT__syn_end();

      msg_free( m );
    }
    
    if( tm_m == SEM_INFINITY )
    {
      sleep_m( 10 );
      continue;
    }
    else
    {
      OS_SUPPORT__syn_time_core( etm );
      if( ( etm - stm ) < (uint64)tm_m )
      {
        sleep_m( 10 );
        continue;
      }
    }

    break;
  }

  return RES_VOID;
}
// ---------------------------------------------------------------------------
// !: fn: uint32 os_message_pid()
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall псевдоним:</b><br>
// !: d: <br>
// !: d: msg_pid<br>
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: Функция возвращает адрес текущего процесса в адресном пространстве
// !: d: системного обмена.
// ---------------------------------------------------------------------------
uint32 os_message_pid()
{
  if( v_os_current_process->msg.name == NULL ) return RES_VOID;
  return RES_T_MSGPIPE | msg_processor_id | (uint32)v_os_current_process->id;
}
// ---------------------------------------------------------------------------
// !: fn: int32 os_message_have()
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall псевдоним:</b><br>
// !: d: <br>
// !: d: msg_have<br>
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: Функция возвращает 0 если очередь приема пуста, иначе есть сообщения
// !: d: для приема.
// ---------------------------------------------------------------------------
int32 os_message_have()
{
  if( v_os_current_process->msg.name == NULL ) return 0;
  return ( sem_locked( v_os_current_process->msg.inq.count_sem ) == SEM_LOCKED ) ? 0 : 1;
}
// ---------------------------------------------------------------------------
// !: fn: int32 os_message_recv( s_message** m, uint32 tm_m )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall псевдоним:</b><br>
// !: d: <br>
// !: d: msg_recv<br>
// !: d: <br>
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция получает сообщение, адресованное текущему процессу. Если в
// !: d: очереди сообщений нет, функция блокируется на tm_m милисекунд в
// !: d: ожидании сообщения. Для бесконечного ожидания переменная tm_m
// !: d: должна быть установлена в значение SEM_INFINITY.<br>
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: В случае успеха функция возвращает указатель на сообщение, иначе
// !: d: NULL.
// ---------------------------------------------------------------------------
int32 os_message_recv( s_message** m, uint32 tm_m )
{
  if( m == NULL ) return OSE_NULL_PARAM;
  (*m) = NULL;
  if( v_os_current_process->msg.name == NULL ) return OSE_MSG_STREAM_NOT_OPENED;
  return msg_queue_pop( &v_os_current_process->msg.inq, m, tm_m );
}
// ---------------------------------------------------------------------------
// !: fn: int32 os_message_free( s_message* msg )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall псевдоним:</b><br>
// !: d: <br>
// !: d: msg_free<br>
// !: d: <br>
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция освобождает сообщение, полученное функцией msg_recv.<br>
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: В случае успеха функция возвращает OSE_OK, иначе одну из ошибок:<br><br>
// !: d: <table cellpadding=2 cellspacing=2 border=0>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_NULL_PARAM</td>
// !: d: <td> - </td>
// !: d: <td>указатель msg равен нулю.</td>
// !: d: </tr>
// !: d: </table><br>
// ---------------------------------------------------------------------------
int32 os_message_free( s_message* msg )
{
  if( msg == NULL ) return OSE_NULL_PARAM;
  if( msg->pipe != SYSTEM_MESSAGE ) sem_unlock( msg->pipe ? msg->pipe->limit_sem : msg_limit_sem );
  heap_free( NULL, msg->data );
  heap_free( NULL, msg );
  return OSE_OK;
}
// ---------------------------------------------------------------------------
// !: fn: s_message* os_message_alloc( uint32 length, s_message_pipe* p )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall псевдоним:</b><br>
// !: d: <br>
// !: d: msg_alloc<br>
// !: d: <br>
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция создает пустое сообщение с заданной длиной данных length.
// !: d: Буфер под данные не очищается.<br>
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: В случае успеха функция возвращает указатель на новое сообщение, иначе NULL.<br><br>
// ---------------------------------------------------------------------------
/*#define FIFO_LEN 12
int32 sss_sem_min_val = 100;
int32 sss_el = 0;
struct 
{
  s_os_process_context* process;
  uint64                time;
  
}sss_message_fifo[FIFO_LEN];
*/
void os_message_alloc_debug()
{
  int32 value;
  sem_value(msg_limit_sem, &value);
  if(value < 0)
  {
    #ifdef OS_SUPPORT_SYSLOG
    syslog( 4, "%s:%d: \"msg_limit_sem\" is locked", os_module, __LINE__ );    
    #endif  
  }
/*
  //Минимальное значение:
  int32 value;
  sem_value(msg_limit_sem, &value);
  sss_sem_min_val = (value < sss_sem_min_val) ? value : sss_sem_min_val;
  //FIFO входящих процессов:
  sss_message_fifo[sss_el].time = time_n();
  sss_message_fifo[sss_el].process = v_os_current_process;
  sss_el = (sss_el == FIFO_LEN-1) ? 0 : sss_el+1;  
*/
}
// ---------------------------------------------------------------------------
s_message* os_message_alloc( uint32 length, s_message_pipe* p )
{
  s_message* r;
  uint32 limit_sem;
  
  if( p == SYSTEM_MESSAGE )
  {
    if( (int32)v_os_current_process->id != msg_process ) return NULL;
    limit_sem = RES_VOID;
  }
  else
  {
    os_message_alloc_debug();
    limit_sem = p ? p->limit_sem : msg_limit_sem;
    if( sem_lock( limit_sem, SEM_INFINITY ) != SEM_OK ) return NULL;
  }
  r = (s_message*)heap_alloc( NULL, sizeof(s_message), HEAP_ALIGN_4 );
  if( r == NULL )
  {
    sem_unlock( limit_sem );
    return NULL;
  }
  memset( r, 0, sizeof(s_message) );
  r->data = heap_alloc( NULL, length, HEAP_ALIGN_4 );
  if( r->data == NULL )
  {
    heap_free( NULL, r );
    sem_unlock( limit_sem );
    return NULL;
  }
  r->length = length;
  r->pipe = p;
  #ifdef OS_SUPPORT_SYNCHRONIZATION
  memset( r->data, 0, length );
  #endif

  return r;
}
// ---------------------------------------------------------------------------
/*
static void os_message_pipe_del( s_message_pipe* p )
{
  sem_lock( msg_pipe_ring_sem, SEM_INFINITY );

  if( msg_pipe_count == 1 )
  {
    msg_pipe_count = 0;
    delete p;
    msg_pipe_ring = NULL;
  }
  else
  {
    p->prev->next = p->next;
    p->next->prev = p->prev;
    if( msg_pipe_ring == p ) msg_pipe_ring = msg_pipe_ring->next;
    if( p->route )
    {
      for( int32 i = 0; i < p->route_count; i++ )
      {
        s_message_link* clink = p->route;
        delete[] clink->name;
        delete clink;
        p->route = p->route->next;
      }
    }
    delete p;
    msg_pipe_count--;
  }
  
  sem_unlock( msg_pipe_ring_sem );

  msgll_rebuild_route_table();
}
*/
// ---------------------------------------------------------------------------
/*
void os_message_link_del( s_message_pipe* p, s_message_link* l )
{
  sem_lock( msg_pipe_ring_sem, SEM_INFINITY );
  if( p->route_count == 1 )
  {
    p->route_count = 0;
    delete l;
    p->route = NULL;
  }
  else
  {
    l->prev->next = l->next;
    l->next->prev = l->prev;
    if( p->route == l ) p->route = p->route->next;
    delete l;
    p->route_count--;
  }
  sem_unlock( msg_pipe_ring_sem );

  msgll_rebuild_route_table();
}
*/
// ---------------------------------------------------------------------------
// !: fn: int32 os_message_send( uint32 to, const void* msg, int32 length )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall псевдоним:</b><br>
// !: d: <br>
// !: d: msg_send<br>
// !: d: <br>
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция отправляет сообщение msg длиной length процессу, на который
// !: d: ссылается идентификатор ресурса to.<br>
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: В случае успеха функция возвращает OSE_OK, иначе одну из ошибок:<br><br>
// !: d: <table cellpadding=2 cellspacing=2 border=0>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_MSG_STREAM_NOT_OPENED</td>
// !: d: <td> - </td>
// !: d: <td>текущий процесс не изъявил свое желание учавствовать в системном обмене, вызовом функции msg_open;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_MSG_BAD_DST_ADDRESS</td>
// !: d: <td> - </td>
// !: d: <td>идентификатор процесса назначения to некорректен;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_NO_MEMORY</td>
// !: d: <td> - </td>
// !: d: <td>недостаточно памяти для регистрации сообщения в системе.</td>
// !: d: </tr>
// !: d: </table><br>
// ---------------------------------------------------------------------------
int32 os_message_send( uint32 to, const void* msg, int32 length )
{
  s_message* nmsg;
  if( v_os_current_process->msg.name == NULL ) return OSE_MSG_STREAM_NOT_OPENED;
  if( ( to == RES_VOID ) || ( ( to & RES_T_MASK ) != RES_T_MSGPIPE ) ) return OSE_MSG_BAD_DST_ADDRESS;
  
  OS_SUPPORT__syn_begin();
  nmsg = msg_alloc( length, USER_MESSAGE );
  if( nmsg == NULL ) 
  {
    OS_SUPPORT__syn_end();    
    return OSE_NO_MEMORY;
  }
  
  nmsg->from = RES_T_MSGPIPE | msg_processor_id | (uint32)v_os_current_process->id;
  nmsg->to = to;
  memcpy( nmsg->data, msg, length );

  if( msg_queue_push( &msg_inq, nmsg ) != OSE_OK ) msg_free( nmsg );
  OS_SUPPORT__syn_end();  
  
  return OSE_OK;
}
// ---------------------------------------------------------------------------
static void msgll_broadcast( s_message* m )
{
  s_message_pipe* p;
  int32 i, li;
  s_message* outm;

  OS_SUPPORT__syn_begin();
  sem_lock( msg_pipe_sem, SEM_INFINITY );

  if( m->pipe == USER_MESSAGE )
  {
    goto l_end;
  }
  else if( m->pipe == SYSTEM_MESSAGE )
  {
    li = msg_pipe_count;
    p = msg_pipe_ring;
  }
  else
  {
    li = msg_pipe_count - 1;
    p = m->pipe->next;
  }
  
  for( i = 0; i < li; i++, p = p->next )
  {
    if( ( outm = msg_alloc( m->length, SYSTEM_MESSAGE ) ) == NULL )
    {
      prc_yield();
      if( ( outm = msg_alloc( m->length, SYSTEM_MESSAGE ) ) == NULL )
      {
        #ifdef OS_SUPPORT_SYSLOG
        syslog( 4, "%s:%d: Can't create message", os_module, __LINE__ );
        #endif
        goto l_end;
      }
    }
    outm->from = m->from;
    outm->to = m->to;
    memcpy( outm->data, m->data, outm->length );

    if( msg_queue_push( p->outq, outm ) != OSE_OK ) msg_free( outm );
  }

l_end:

  sem_unlock( msg_pipe_sem );
  OS_SUPPORT__syn_end();

  msg_free( m );
}
// ---------------------------------------------------------------------------
static void msgll_route( s_message* m )
{
  bool r = false;
  s_message_pipe* p;

  uint32 idx = m->to & MFD_HID;
  if( idx > msg_processor_max ) goto l_fail;
  if( msg_route_table == NULL ) goto l_fail;
  idx >>= 16;
  p = msg_route_table[idx];
  if( p == NULL ) goto l_fail;
  if( msg_queue_push( p->outq, m ) != OSE_OK ) goto l_fail;
  r = true;

l_fail:

  if( !r ) msg_free( m );
}
// ---------------------------------------------------------------------------
void msgll_discover_request( s_message* m )
{
  s_discover_request& req = (*(s_discover_request*)m->data);
  register uint32 mfrom = m->from;
  s_message_process_data* p;
  uint32 id = RES_VOID;
  s_message* outm;
  s_discover_reply* r;
  uint32 req_reqid;
  uint32 req_sender;

  OS_SUPPORT__syn_begin();
  sem_lock( msg_process_list_sem, SEM_INFINITY );

  p = msg_process_list;
  while( p )
  {
    if( p->name )
    {
      if( strcmp( p->name, req.name ) == 0 )
      {
        id = (uint32)p->p->id;
        break;
      }
    }
    p = p->next;
  }

  sem_unlock( msg_process_list_sem );
  OS_SUPPORT__syn_end();
  
  req_reqid = req.reqid;
  req_sender = req.sender;
  msg_free( m );

  if( ( outm = msg_alloc( sizeof(s_discover_reply), SYSTEM_MESSAGE ) ) == NULL )
  {
    #ifdef OS_SUPPORT_SYSLOG
    syslog( 4, "%s:%d: Can't create message", os_module, __LINE__ );
    #endif
    return;
  }

  r = (s_discover_reply*)outm->data;
  r->type = MSGT_DISCOVER_REPLY;
  if( id == RES_VOID ) r->pid = RES_VOID; else r->pid = RES_T_MSGPIPE | msg_processor_id | id;
  r->reqid = req_reqid;
  r->sender = req_sender;
  outm->from = RES_T_MSGPIPE | msg_processor_id;
  outm->to = mfrom;

  msgll_route( outm );
}
// ---------------------------------------------------------------------------
void msgll_discover_reply( s_message* m )
{
  s_message_process_data* p;
  s_discover_reply* r = (s_discover_reply*)m->data;

  OS_SUPPORT__syn_begin();
  sem_lock( msg_process_list_sem, SEM_INFINITY );

  p = msg_process_list;
  while( p )
  {
    if( (uint32)p->p->id == ( r->sender & MFD_PID ) )
    {
      p->avg_ppid = r->pid;
      p->avg_reqid = r->reqid;
      break;
    }
    p = p->next;
  }

  sem_unlock( msg_process_list_sem );
  OS_SUPPORT__syn_end();

  msg_free( m );
}
// ---------------------------------------------------------------------------
static void msgll_seed( s_message* m )
{
  int32 r;
  s_seed& sm = (*(s_seed*)m->data);

  if( sm.id == msg_processor_id ) return;

  r = msgll_link_add( m->pipe, sm.id, sm.name );
  if( r != OSE_OK )
  {
    #ifdef OS_SUPPORT_SYSLOG
    syslog( 4, "%s:%d: (%d) Can't add new message pipe", os_module, __LINE__, r );
    #endif
    return;
  }

  r = msgll_rebuild_route_table();
  if( r != OSE_OK )
  {
    #ifdef OS_SUPPORT_SYSLOG
    syslog( 4, "%s:%d: (%d) Can't rebuild message route table", os_module, __LINE__, r );
    #endif
    return;
  }
}
// ---------------------------------------------------------------------------
void msgll_bcastseed()
{
  s_message* m;
  s_seed* seed;

  if( ( m = msg_alloc( sizeof(s_seed), SYSTEM_MESSAGE ) ) == NULL )
  {
    #ifdef OS_SUPPORT_SYSLOG
    syslog( 4, "%s:%d: Can't create message", os_module, __LINE__ );
    #endif
    return;
  }

  seed = (s_seed*)m->data;
  seed->type = MSGT_SEED;
  seed->id = msg_processor_id;
  sys_getname( seed->name, sizeof(seed->name) );
  m->from = RES_T_MSGPIPE | msg_processor_id;
  m->to = RES_T_MSGPIPE;

  if( msg_queue_push( &msg_inq, m ) != OSE_OK ) msg_free( m );
}
// ---------------------------------------------------------------------------
int os_message_router( void* args )
{
  s_message* m;
  register uint32 mto;
  register uint32 mtopid;
  register uint32 mtohid;
  int32 r;
  
  sem_lock( msg_locker, SEM_INFINITY );
  sem_unlock( msg_locker );

  // Broadcast seed
  msgll_bcastseed();

  // Message processing
  while( true )
  {
    r = msg_queue_pop( &msg_inq, &m, SEM_INFINITY );
    if( ( r != OSE_OK ) && ( r != OSE_NO_ELEMENT ) )
    {
      #ifdef OS_SUPPORT_SYSLOG
      syslog( 4, "%s:%d: (%d) Can't pop message from incoming queue", os_module, __LINE__, r );
      #endif
      break;
    }

    if( msg_terminate )
    {
      if( m != NULL ) msg_free( m );
      break;
    }

    if( r == OSE_NO_ELEMENT )
    {
      #ifdef OS_SUPPORT_SYSLOG
      syslog( 4, "%s:%d: (%d) Can't pop message from incoming queue", os_module, __LINE__, r );
      #endif
      break;
    }

    if( m == NULL )
    {
      #ifdef OS_SUPPORT_SYSLOG
      syslog( 4, "%s:%d: Null message", os_module, __LINE__ );
      #endif
      continue;
    }
    
    mto = m->to;
    mtopid = mto & MFD_PID;
    mtohid = mto & MFD_HID;

    if( mtopid == 0 ) // system
    {
      if( mtohid == 0 ) // system, broadcast (seed)
      {
        uint32& type = (*(uint32*)m->data);
        if( type == MSGT_SEED )
        {
          msgll_seed( m );
        }
        else
        {
          #ifdef OS_SUPPORT_SYSLOG
          syslog( 4, "%s:%d: Bad message type (src=%08x dst=%08x type=%08x)", os_module, __LINE__, m->from, m->to, type );
          #endif
          msg_free( m );
          continue;
        }
        msgll_broadcast( m );
      }
      else if( mtohid == msg_processor_id ) // system, self (discover_request,discover_reply)
      {
        uint32& type = (*(uint32*)m->data);
        if( type == MSGT_DISCOVER_REQUEST )
        {
          msgll_discover_request( m );
        }
        else if( type == MSGT_DISCOVER_REPLY )
        {
          msgll_discover_reply( m );
        }
        else
        {
          #ifdef OS_SUPPORT_SYSLOG
          syslog( 4, "%s:%d: Bad message type (src=%08x dst=%08x type=%08x)", os_module, __LINE__, m->from, m->to, type );
          #endif
          msg_free( m );
        }
      }
      else // system, transite
      {
        msgll_route( m );
      }
    }
    else // not system
    {
      if( mtohid == 0 ) // not system, broadcast
      {
        msg_free( m );
      }
      else if( mtohid == msg_processor_id ) // not system, self
      {
        OS_SUPPORT__syn_begin();
        sem_lock( msg_process_list_sem, SEM_INFINITY );

        s_message_process_data* p = msg_process_list;
        while( p )
        {
          if( (uint32)p->p->id == mtopid ) break;
          p = p->next;
        }
        if( p )
        {
          if( msg_queue_push( &p->inq, m ) != OSE_OK )
          {
            #ifdef OS_SUPPORT_SYSLOG
            syslog( 4, "%s:%d: Can't push message into outgoing queue", os_module, __LINE__ );
            #endif
            msg_free( m );
          }
        }
        else
        {
          msg_free( m );
        }
        
        sem_unlock( msg_process_list_sem );
        OS_SUPPORT__syn_end();
      }
      else // not system, transite
      {
        msgll_route( m );
      }
    }
  }
  
  return 0;
}
// ---------------------------------------------------------------------------
// !: fn: int32 os_message_start( uint32 id, int32 msg_limit )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall псевдоним:</b><br>
// !: d: <br>
// !: d: msg_start<br>
// !: d: <br>
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция инициализирует и запускает процесс межпроцессорно-процессного
// !: d: обмена. Переменная id указывает на уникальный номер процессора в
// !: d: системе (от 0 до 255). Переменная msg_limit указывает на количество
// !: d: пакетов сообщений которые могут одновременно существовать в системе.
// !: d: Эта функция привелегированная и не доступна пользовательским процессам.<br>
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: В случае успеха функция возвращает OSE_OK, иначе одну из ошибок:<br><br>
// !: d: <table cellpadding=2 cellspacing=2 border=0>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_MSG_ALLREADY_STARTED</td>
// !: d: <td> - </td>
// !: d: <td>системный обмен уже запущен;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_CANT_CREATE_PROCESS</td>
// !: d: <td> - </td>
// !: d: <td>ошибка при создании процесса.</td>
// !: d: </tr>
// !: d: </table><br>
// ---------------------------------------------------------------------------
int32 os_message_start( uint32 id, int32 limit )
{
  s_prc_attr pattr;
  uint32 t;

  if( msg_processor_id != 0xffffffff ) 
  {
  	return OSE_MSG_ALLREADY_STARTED;
  }
  t = ( id << 16 ) & MFD_HID;
  
  if( ( t != ( id << 16 ) ) || ( id == 0 ) ) 
  {
  	return OSE_BAD_PARAM;
  }
  
  if( limit < 1 ) limit = 1;
  sem_reset( msg_limit_sem, limit );
  
  memset( &pattr, 0, sizeof(pattr) );
  pattr.stack = 1024;
  if( ( msg_process = prc_create( &os_message_router, 0, NULL, &pattr ) ) < 0 )
  {
    msg_queue_deinit( &msg_inq );
    return OSE_CANT_CREATE_PROCESS;
  }

  msg_processor_id = t;

  // Unlock all message operations
  sem_unlock( msg_locker );

  return OSE_OK;
}
// ---------------------------------------------------------------------------
// !: fn: int32 os_message_end()
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall псевдоним:</b><br>
// !: d: <br>
// !: d: msg_end<br>
// !: d: <br>
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция завершает системный обмен. После вызова этой функции
// !: d: межпроцессорно-процессный обмен будет невозможен. Это
// !: d: привелегированная функция и не доступна пользовательским процессам.<br>
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: В случае успеха функция возвращает OSE_OK, иначе одну из ошибок:<br><br>
// !: d: <table cellpadding=2 cellspacing=2 border=0>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_MSG_ALLREADY_STARTED</td>
// !: d: <td> - </td>
// !: d: <td>системный обмен уже запущен;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_CANT_CREATE_PROCESS</td>
// !: d: <td> - </td>
// !: d: <td>недостаточно памяти для запуска процесса.</td>
// !: d: </tr>
// !: d: </table><br>
// ---------------------------------------------------------------------------
int32 os_message_end()
{
  sem_lock( msg_locker, SEM_INFINITY );

  msg_terminate = true;
  sem_unlock_sw( msg_inq.count_sem );
  prc_join( msg_process );

  // todo: cleanup all data
  // todo: clear processor id
  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 os_message_queue_init( s_message_queue* q )
{
  if( q == NULL ) return OSE_BAD_PARAM;

  q->first = NULL;
  q->last = NULL;
  q->syn_sem = sem_alloc( 1, NULL );
  q->count_sem = sem_alloc( 0, NULL );

  if( ( q->syn_sem == RES_VOID ) || ( q->count_sem == RES_VOID ) )
  {
    sem_free( q->syn_sem );
    sem_free( q->count_sem );
    return OSE_CANT_CREATE_SEM;
  }
  
  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 os_message_queue_push( s_message_queue* q, s_message* m )
{
  if( ( q == NULL ) || ( m == NULL ) ) return OSE_BAD_PARAM;
  
  OS_SUPPORT__syn_begin();
  if( sem_lock( q->syn_sem, SEM_INFINITY ) != SEM_OK )
  {
    OS_SUPPORT__syn_end();
    return OSE_CANT_LOCK_SEM;
  }

  m->next = NULL;
  if( q->last == NULL )
  {
    m->prev = NULL;
    q->first = m;
    q->last = m;
  }
  else
  {
    m->prev = q->last;
    q->last->next = m;
    q->last = m;
  }

  sem_unlock( q->syn_sem );
  OS_SUPPORT__syn_end();

  sem_unlock( q->count_sem );
//  sem_unlock_sw( q->count_sem );

  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 os_message_queue_pop( s_message_queue* q, s_message** m, uint32 tm_m )
{
  if( ( q == NULL ) || ( m == NULL ) ) return OSE_BAD_PARAM;

  if( sem_lock( q->count_sem, tm_m ) != SEM_OK ) return OSE_CANT_LOCK_SEM;
  if( sem_lock( q->syn_sem, SEM_INFINITY ) != SEM_OK ) return OSE_CANT_LOCK_SEM;

  if( ( (*m) = q->first ) == NULL )
  {
    sem_unlock( q->syn_sem );
    return OSE_NO_ELEMENT;
  }

  if( q->first == q->last )
  {
    q->first = NULL;
    q->last = NULL;
  }
  else
  {
    q->first = q->first->next;
    q->first->prev = NULL;
    (*m)->next = NULL;
  }

  sem_unlock( q->syn_sem );
  
  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 os_message_queue_deinit( s_message_queue* q )
{
  register s_message* cmsg;
  register s_message* tmsg;

  if( q == NULL ) return OSE_BAD_PARAM;

  if( sem_lock( q->syn_sem, SEM_INFINITY ) != SEM_OK ) return OSE_CANT_LOCK_SEM;

  cmsg = q->first;
  while( cmsg )
  {
    tmsg = cmsg;
    cmsg = cmsg->next;
    msg_free( tmsg );
  }
  
  sem_free( q->count_sem );
  sem_free( q->syn_sem );

  memset( q, 0, sizeof(s_message_queue) );
  q->syn_sem = RES_VOID;
  q->count_sem = RES_VOID;

  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 os_message_regpipe( s_message_context* q, int32 limit )
{
  int32 r;
  if( q == NULL ) return OSE_NULL_PARAM;
  if( limit < 1 ) limit = 1;
  if( ( r = msgll_drvctx_add( q, limit ) ) != OSE_OK ) return r;
  return OSE_OK;
}
// ---------------------------------------------------------------------------
