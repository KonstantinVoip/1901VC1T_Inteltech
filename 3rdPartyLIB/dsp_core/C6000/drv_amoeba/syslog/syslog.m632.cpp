// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp1251
// !: d: Модуль содержит реализацию функций работы с системным логом.
// !: -: 
// ---------------------------------------------------------------------------
#include <os.h>
#include <rts.h>
#include <drv_fwmem.h>

#define LOG_SECTOR_START        62
#define LOG_SECTOR_END          69

#define LOG_MSG_LENGTH          512

#define LOG_SECTOR_SIZE         0x00010000
#define LOG_START_ADDR          0x00370000
#define LOG_END_ADDR            0x003effff





const uint32 log_sect_msg_qty = LOG_SECTOR_SIZE / LOG_MSG_LENGTH;
const uint32 log_sector_qty = LOG_SECTOR_END - LOG_SECTOR_START + 1;

static const char* month_name[12] =
{
  "Jan", "Feb", "Mar", "Apr", "May", "Jun",
  "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

// ---------------------------------------------------------------------------
// !: sn: s_log
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sd: Структура системного лога.
// !: sc: uint32, next_addr
// !: cd: адрес первой пустой записи в системном логе
// !: sc: uint32, fwmem_dscr
// !: cd: дескриптор памяти системного лога
// !: sc: uint32, msg_qty
// !: cd: количество сообщений в системном логе
// !: sc: int32, level
// !: cd: уровень приоритета сообщений системного лога
// ---------------------------------------------------------------------------
struct s_log
{
  uint32                        next_addr;
  uint32                        fwmem_dscr;
  uint32                        msg_qty;
  int32                         level;
};

struct s_syslog_callback
{
  s_syslog_callback*            prev;
  s_syslog_callback*            next;
  void                          (*cbfunc)( const char* m );
};

// ---------------------------------------------------------------------------

s_log sys_log = { 0, RES_VOID, 0, 0 };
static s_syslog_callback* syslog_cb_first = NULL;
static s_syslog_callback* syslog_cb_last = NULL;
static uint32 cblist_sem = RES_VOID;
static uint32 syslog_sem = RES_VOID;
static bool syslog_inialized = false;
static bool syslog_recurse = false;

// ---------------------------------------------------------------------------
// !: fn: int32 ext_syslog_init()
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция используется для инициализации системного лога. <br>
// !: d:
// !: d: Входные параметры: <br>
// !: d:    нет. <br>
// !: d: Возвращаемое значение: <br>
// !: d:    OSE_OK        - в случае успеха; <br>
// !: d:    OSE_NO_DEVICE - невозможно получить дескриптор флеш памяти. <br>
// !: d: 
// !: d: Данная функция доступна пользователю.
// !: -:
// ---------------------------------------------------------------------------
int32 ext_syslog_init()
{
    int32 error = 0;
    uint32 i = 0;
    uint32 j = 0;
    uint8 seek_read = 0;
    uint32 read_addr = 0;
    uint32 write_addr = 0;

    cblist_sem = sem_alloc( 1, NULL );
    if( cblist_sem == RES_VOID ) return OSE_CANT_CREATE_SEM;

    syslog_sem = sem_alloc( 1, NULL );
    if( syslog_sem == RES_VOID )
    {
      sem_free( cblist_sem );
      return OSE_CANT_CREATE_SEM;
    }

    sys_log.fwmem_dscr = drv_mkd( "/fwmem" );
    if( sys_log.fwmem_dscr == RES_VOID ) return OSE_NO_DEVICE;
    res_share(sys_log.fwmem_dscr);

    for( i = 1; i <= log_sector_qty; i++ )
    {
        read_addr = LOG_START_ADDR + i * LOG_SECTOR_SIZE - LOG_MSG_LENGTH;
        j = log_sect_msg_qty;
        do
        {
            error = drv_ioctl( sys_log.fwmem_dscr, FWMEM_SET_OFFSET, &read_addr );           //
            if( error != OSE_OK )        //
            {
                return error;
            }
            s_fwmem_rwbuf fwrw;
            fwrw.buffer = &seek_read;
            fwrw.length = 1;
            error = drv_ioctl( sys_log.fwmem_dscr, FWMEM_READ, &fwrw );
            if( error != OSE_OK )        //
            {
                return error;
            }
            if( seek_read != 0xFF )
            {
                sys_log.msg_qty += j;
                break; //  
            }
            read_addr -= LOG_MSG_LENGTH;
        }
        while( --j > 0 );
                
        if( (sys_log.next_addr == 0) && (j < log_sect_msg_qty) )
        {
            sys_log.next_addr = read_addr + LOG_MSG_LENGTH;
        }
    }

    if( sys_log.msg_qty == log_sect_msg_qty * log_sector_qty )  // если просмотрели всю память и не нашли свободного места
    {
        write_addr = LOG_SECTOR_START;
        error = drv_ioctl( sys_log.fwmem_dscr, FWMEM_SECTOR_CLEAR, &write_addr );     // стираем начальный сектор
        if (error != OSE_OK )   //
        {
            return error;
        }
        sys_log.msg_qty -= log_sect_msg_qty;
        sys_log.next_addr = LOG_START_ADDR;                     // будем писать с начала!
    }

    syslog_inialized = true;

    return OSE_OK;
}



// ---------------------------------------------------------------------------
// !: fn: int32 ext_syslog_level( int32 l )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция используется для установки уровня приоритета сообщений,
// !: d: записываемых в системный лог. <br>
// !: d:
// !: d: Входные параметры: <br>
// !: d:    нет. <br>
// !: d: Возвращаемое значение: <br>
// !: d:    OSE_OK - в случае успеха. <br>
// !: d: 
// !: d: Данная функция доступна пользователю.
// !: -:
// ---------------------------------------------------------------------------
int32 ext_syslog_level( int32 l )
{
  int32 old_level = sys_log.level;
  sys_log.level = ( l & 3 );
  return old_level;
}


// ---------------------------------------------------------------------------
// !: fn: int32 ext_syslog( int32 l, const char* fmt, ... )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция используется для записи в системный лог одного сообщения
// !: d: формата fmt с уровнем приоритета l. <br>
// !: d:
// !: d: Входные параметры: <br>
// !: d:    l   - уровень приоритета данного сообщения; <br>
// !: d:    fmt - формат сообщения. <br>
// !: d: Возвращаемое значение: <br>
// !: d:    OSE_OK - в случае успеха; <br>
// !: d:    OSE_NO_MEMORY - недостаточно памяти. <br>
// !: d: 
// !: d: Данная функция доступна пользователю.
// !: -:
// ---------------------------------------------------------------------------
int32 ext_syslog( int32 l, const char* fmt, ... )
{
    int32 error = OSE_OK;
    uint32 sector_num;
    uint32 ctime;
    tm s_time;
    uint32 i;
    char* str_buf;
    char sysname[32];
    s_syslog_callback* crec;
    
    if( !syslog_inialized ) return OSE_NOT_INITIALIZED;

    if( ( l & 3 ) <= sys_log.level )
    {
        str_buf = (char*)heap_alloc( NULL, LOG_MSG_LENGTH + 1, HEAP_ALIGN_4 );
        if( str_buf == NULL ) return OSE_NO_MEMORY;
        memset( str_buf, 0, LOG_MSG_LENGTH + 1 );

        syn_time_s( &ctime );
        localtime_r( &ctime, &s_time );
        sys_getname( sysname, 32 );

        sprintf( str_buf, "<%d>%s%3d %02d:%02d:%02d %s ", l, month_name[s_time.tm_mon], s_time.tm_mday,
                 s_time.tm_hour, s_time.tm_min, s_time.tm_sec, sysname );

        i = strlen( str_buf );

        va_list ap;
        va_start( ap, fmt );
        i = vsnprintf( str_buf + i, LOG_MSG_LENGTH - i - 2, fmt, ap );
        va_end( ap );

        i = strlen( str_buf );
        
        str_buf[i] = '\n';
        str_buf[i+1] = 0;

        sem_lock( syslog_sem, SEM_INFINITY );
        if( syslog_recurse ) goto l_fail_recurse;
        syslog_recurse = true;
        
        // Call all callbacks =) (too many 'all')
        sem_lock( cblist_sem, SEM_INFINITY );
        crec = syslog_cb_first;
        while( crec )
        {
          crec->cbfunc( str_buf );
          crec = crec->next;
        }
        sem_unlock( cblist_sem );

        error = drv_ioctl( sys_log.fwmem_dscr, FWMEM_SET_OFFSET, &sys_log.next_addr );     //  Установили указатель в памяти на свободную строку
        if( error != OSE_OK )        //
        {
            goto l_fail;
        }
        sys_log.msg_qty++;                // увеличили количество сообщений
        sys_log.next_addr += LOG_MSG_LENGTH;
        
        s_fwmem_rwbuf fwrw;
        fwrw.buffer = str_buf;
        fwrw.length = LOG_MSG_LENGTH;
        error = drv_ioctl( sys_log.fwmem_dscr, FWMEM_WRITE, &fwrw );
        if( error != OSE_OK )
        {
          goto l_fail;
        }

        //  Проверяем переход в следующий сектор
        if( (sys_log.next_addr % LOG_SECTOR_SIZE) == 0 )
        {
            if( sys_log.next_addr >= LOG_END_ADDR )
            {
                sys_log.next_addr = LOG_START_ADDR;
            }
            sector_num = sys_log.next_addr / LOG_SECTOR_SIZE + 7;
            error = drv_ioctl( sys_log.fwmem_dscr, FWMEM_SECTOR_CLEAR, &sector_num ); // стираем следующий сектор
            if (error != OSE_OK )   //
            {
                goto l_fail;
            }
            sys_log.msg_qty -= log_sect_msg_qty;
        }

      l_fail:

        syslog_recurse = false;

      l_fail_recurse:

        sem_unlock( syslog_sem );
        heap_free( NULL, str_buf );

    }

    return error;
}


// ---------------------------------------------------------------------------
// !: fn: int32 ext_syslog_count()
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция используется для получения количества сообщений в системном логе. <br>
// !: d:
// !: d: Входные параметры: <br>
// !: d:    нет. <br>
// !: d: Возвращаемое значение: <br>
// !: d:    количество сообщений. <br>
// !: d: 
// !: d: Данная функция доступна пользователю.
// !: -:
// ---------------------------------------------------------------------------
int32 ext_syslog_count()
{
    if( !syslog_inialized ) return 0;
    return sys_log.msg_qty;
}


// ---------------------------------------------------------------------------
// !: fn: int32 ext_syslog_read( int32 n, void* buf, int32 buflen )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция используется для чтения сообщения номер n из системного лога
// !: d: в буфер buf длинной buflen. <br>
// !: d:
// !: d: Входные параметры: <br>
// !: d:    n   - порядковый номер сообщения; <br>
// !: d:    buf - указатель на буфер, куда будет записано сообщение; <br>
// !: d:    buflen - длина буфера buf в байтах. <br>
// !: d: Возвращаемое значение: <br>
// !: d:    OSE_OK - в случае успеха; <br>
// !: d:    OSE_TOO_SHORT_BUFFER - недостаточная длинна буфера buf; <br>
// !: d:    OSE_BAD_PARAM - сообщения с таким порядковым номером не существует. <br>
// !: d: 
// !: d: Данная функция доступна пользователю.
// !: -:
// ---------------------------------------------------------------------------
int32 ext_syslog_read( int32 n, void* buf, int32 buflen )
{
    int32 error = OSE_OK;
    uint32 preset = 0;
    s_fwmem_rwbuf fwrw;
    
    if( !syslog_inialized ) return OSE_NOT_INITIALIZED;
    if( n >= sys_log.msg_qty )
    {
        return OSE_BAD_PARAM;
    }
    
    sem_lock( syslog_sem, SEM_INFINITY );

    preset = sys_log.next_addr - (sys_log.msg_qty - n) * LOG_MSG_LENGTH;
    if( preset < LOG_START_ADDR )
    {
        preset += LOG_SECTOR_SIZE * log_sector_qty;
    }
    error = drv_ioctl( sys_log.fwmem_dscr, FWMEM_SET_OFFSET, &preset );           //
    if( error != OSE_OK )        //
    {
        goto l_fail;
    }

    fwrw.length = LOG_MSG_LENGTH;
    fwrw.buffer = (uint8*)buf;
    error = drv_ioctl( sys_log.fwmem_dscr, FWMEM_READ, &fwrw );
        
  l_fail:

    sem_unlock( syslog_sem );
    
    return error;
}
// ---------------------------------------------------------------------------
int32 ext_syslog_cbadd( void (*cbf)(const char*) )
{
  s_syslog_callback* nrec;

  if( !syslog_inialized ) return OSE_NOT_INITIALIZED;
  if( cbf == NULL ) return OSE_NULL_PARAM;

  sem_lock( cblist_sem, SEM_INFINITY );

  nrec = syslog_cb_first;
  while( nrec )
  {
    if( nrec->cbfunc == cbf )
    {
      sem_unlock( cblist_sem );
      return OSE_OK;
    }
  }

  nrec = (s_syslog_callback*)heap_alloc( NULL, sizeof(s_syslog_callback), HEAP_ALIGN_4 );
  if( nrec == NULL )
  {
    sem_unlock( cblist_sem );
    return OSE_NO_MEMORY;
  }
  memset( nrec, 0, sizeof(s_syslog_callback) );

  nrec->cbfunc = cbf;

  if( syslog_cb_first == NULL )
  {
    syslog_cb_first = nrec;
    syslog_cb_last = nrec;
  }
  else
  {
    syslog_cb_last->next = nrec;
    nrec->prev = syslog_cb_last;
    syslog_cb_last = nrec;
  }

  sem_unlock( cblist_sem );

  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 ext_syslog_cbdel( void (*cbf)(const char*) )
{
  s_syslog_callback* crec;

  if( !syslog_inialized ) return OSE_NOT_INITIALIZED;
  if( cbf == NULL ) return OSE_NULL_PARAM;

  sem_lock( cblist_sem, SEM_INFINITY );
  crec = syslog_cb_first;
  while( crec )
  {
    if( crec->cbfunc == cbf )
    {
      if( crec->prev ) crec->prev->next = crec->next; else syslog_cb_first = crec->next;
      if( crec->next ) crec->next->prev = crec->prev; else syslog_cb_last = crec->prev;
      heap_free( NULL, crec );
      sem_unlock( cblist_sem );
      return OSE_OK;
    }
    crec = crec->next;
  }
  sem_unlock( cblist_sem );

  return OSE_NO_ELEMENT;
}
// ---------------------------------------------------------------------------

s_os_extension modsyslog;

s_os_extension_f modsyslog_f[] =
{
  { NULL, SYSCALL_SYSLOG_INIT,  (uint32)&ext_syslog_init  },
  { NULL, SYSCALL_SYSLOG,       (uint32)&ext_syslog       },
  { NULL, SYSCALL_SYSLOG_LEVEL, (uint32)&ext_syslog_level },
  { NULL, SYSCALL_SYSLOG_COUNT, (uint32)&ext_syslog_count },
  { NULL, SYSCALL_SYSLOG_READ,  (uint32)&ext_syslog_read  },
  { NULL, SYSCALL_SYSLOG_CBADD, (uint32)&ext_syslog_cbadd },
  { NULL, SYSCALL_SYSLOG_CBDEL, (uint32)&ext_syslog_cbdel }
};

// ---------------------------------------------------------------------------
OS_MODULE_INICIATOR( modsyslog )
{
  OS_MODULE_INIT( modsyslog )
  {
    modsyslog.name = "modsyslog.lif";
    modsyslog.f_count = sizeof(modsyslog_f) / sizeof(s_os_extension_f);
    modsyslog.f_tab = modsyslog_f;
    modsyslog.flags = EXT_F_STATIC;
    ext_plug( &modsyslog );
  }
  OS_MODULE_DEINIT( modsyslog ) { }
}
OS_MODULE_ACTIVATOR( modsyslog );
// ---------------------------------------------------------------------------
