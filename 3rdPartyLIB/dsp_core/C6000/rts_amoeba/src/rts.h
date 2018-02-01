#ifndef __OS_RTS_H__
#define __OS_RTS_H__

#include <stddef.h>
#include <stdarg.h>
#include <os.h>

#if defined(CHIP_6412) || defined(CHIP_6416)
#  include <rts_edma.h>
#elif defined(CHIP_6457)
#  include <rts_edma3.h>
#endif

#define off_t                   uint32
#define time_t                  uint32
#define dev_t                   uint32
#define ino_t                   uint32
#define mode_t                  uint32
#define nlink_t                 uint32
#define uid_t                   uint16
#define gid_t                   uint16
#define blksize_t               uint32
#define blkcnt_t                uint32

#ifdef CHAR_BIT
#  undef CHAR_BIT
#endif

#ifdef EPROTONOSUPPORT
#  undef EPROTONOSUPPORT
#endif
#ifdef EADDRNOTAVAIL
#  undef EADDRNOTAVAIL
#endif
#ifdef EAFNOSUPPORT
#  undef EAFNOSUPPORT
#endif
#ifdef ECONNABORTED
#  undef ECONNABORTED
#endif
#ifdef ECONNREFUSED
#  undef ECONNREFUSED
#endif
#ifdef EDESTADDRREQ
#  undef EDESTADDRREQ
#endif
#ifdef EHOSTUNREACH
#  undef EHOSTUNREACH
#endif
#ifdef EINPROGRESS
#  undef EINPROGRESS
#endif
#ifdef ENETUNREACH
#  undef ENETUNREACH
#endif
#ifdef ENOPROTOOPT
#  undef ENOPROTOOPT
#endif
#ifdef EADDRINUSE
#  undef EADDRINUSE
#endif
#ifdef ECONNRESET
#  undef ECONNRESET
#endif
#ifdef EOPNOTSUPP
#  undef EOPNOTSUPP
#endif
#ifdef EPROTOTYPE
#  undef EPROTOTYPE
#endif
#ifdef ETIMEDOUT
#  undef ETIMEDOUT
#endif
#ifdef EALREADY
#  undef EALREADY
#endif
#ifdef EMSGSIZE
#  undef EMSGSIZE
#endif
#ifdef ENETDOWN
#  undef ENETDOWN
#endif
#ifdef ENOTCONN
#  undef ENOTCONN
#endif
#ifdef ENOTSOCK
#  undef ENOTSOCK
#endif
#ifdef EISCONN
#  undef EISCONN
#endif
#ifdef EAGAIN
#  undef EAGAIN
#endif
#ifdef EINVAL
#  undef EINVAL
#endif
#ifdef ENOMEM
#  undef ENOMEM
#endif
#ifdef ENFILE
#  undef ENFILE
#endif
#ifdef EPROTO
#  undef EPROTO
#endif
#ifdef EBADF
#  undef EBADF
#endif
#ifdef EINTR
#  undef EINTR
#endif
#ifdef EPIPE
#  undef EPIPE
#endif
#ifdef EDOM
#  undef EDOM
#endif
#ifdef EWOULDBLOCK
#  undef EWOULDBLOCK
#endif
#ifdef ENOENT
#  undef ENOENT
#endif
#ifdef EIO
#  undef EIO
#endif
#ifdef EOVERFLOW
#  undef EOVERFLOW
#endif
#ifdef ERANGE
#  undef ERANGE
#endif
#ifdef ESPIPE
#  undef ESPIPE
#endif
#ifdef ENODEV
#  undef ENODEV
#endif
#ifdef ESEMDESTR
#  undef ESEMDESTR
#endif
#ifdef EDEADLK
#  undef EDEADLK
#endif
#ifdef ENOSPC
#  undef ENOSPC
#endif

#ifdef NAME_MAX
#  undef NAME_MAX
#endif

#ifdef EOF
#  undef EOF
#endif

#define CHAR_BIT                8

#define EPROTONOSUPPORT         1
#define EADDRNOTAVAIL           2
#define EAFNOSUPPORT            3
#define ECONNABORTED            4
#define ECONNREFUSED            5
#define EDESTADDRREQ            6
#define EHOSTUNREACH            7
#define EINPROGRESS             8
#define ENETUNREACH             9
#define ENOPROTOOPT             10
#define EADDRINUSE              11
#define ECONNRESET              12
#define EOPNOTSUPP              13
#define EPROTOTYPE              14
#define ETIMEDOUT               15
#define EALREADY                16
#define EMSGSIZE                17
#define ENETDOWN                18
#define ENOTCONN                19
#define ENOTSOCK                20
#define EISCONN                 21
#define EAGAIN                  22
#define EINVAL                  23
#define ENOMEM                  24
#define ENFILE                  25
#define EPROTO                  26
#define EBADF                   27
#define EINTR                   28
#define EPIPE                   29
#define EDOM                    30
#define EWOULDBLOCK             31
#define ENOENT                  32
#define EIO                     33
#define EOVERFLOW               34
#define ERANGE                  35
#define ESPIPE                  36
#define ENODEV                  37
#define ESEMDESTR               38
#define EDEADLK                 39
#define ENOSPC                  40

#define RAND_MAX                65535
#define NAME_MAX                255
#define SEM_VALUE_MAX           2147483648

#define EOF                     -1
#define FILE_UNGETC_BUFSIZE     16

namespace std
{
  class bad_alloc {};
  typedef int nothrow_t;
  extern const nothrow_t nothrow;
}       

struct FILE
{
  uint32                        rid;
  uint8                         ungetc_buf[FILE_UNGETC_BUFSIZE];
  uint8                         ungetc_count;
};

struct BIT_FILE
{
  FILE*                         f;
  int32                         bpos;
  uint8                         b;
  uint8                         mode;
};

struct WLPK_FILE
{
  BIT_FILE*                     f;
  uint8                         w[1024];
  uint8                         b[32];
  int32                         wpos;
  int32                         blen;
  uint8                         mode;
};

#define DT_UNKNOWN              0
#define DT_DIR                  1
#define DT_REG                  2 // file
#define DT_LNK                  3

struct dirent
{
  char                          d_name[NAME_MAX+1];
  uint8                         d_type;
  uint64                        d_size;
};

struct DIR
{
  uint32                        rid;
  dirent                        d_rec;
  s_inode*                      d_list;
  s_inode*                      d_cnode;
};

struct sem_t
{
  uint32                        rid;
  int32                         nauna;
};

struct tm
{
  int                           tm_sec;
  int                           tm_min;
  int                           tm_hour;
  int                           tm_mday;
  int                           tm_mon;
  int                           tm_year;
  int                           tm_wday;
  int                           tm_yday;
  int                           tm_isdst;
};

struct stat
{
  dev_t                         st_dev;
  ino_t                         st_ino;
  mode_t                        st_mode;
  nlink_t                       st_nlink;
  uid_t                         st_uid;
  gid_t                         st_gid;
  dev_t                         st_rdev;
  off_t                         st_size;
  time_t                        st_atime;
  time_t                        st_mtime;
  time_t                        st_ctime;
  blksize_t                     st_blksize;
  blkcnt_t                      st_blocks;
};

#ifndef SEEK_SET
#  define SEEK_SET 0
#endif
#ifndef SEEK_CUR
#  define SEEK_CUR 1
#endif
#ifndef SEEK_END
#  define SEEK_END 2
#endif

enum an_error_code
{
  ec_none,
  ec_abort_header,
  ec_terminate_called,
  ec_terminate_returned,
  ec_already_marked_for_destruction,
  ec_main_called_more_than_once,
  ec_pure_virtual_called,
  ec_bad_cast,
  ec_bad_typeid,
  ec_array_not_from_vec_new,
  ec_last
};

struct s_rts_dtorlist
{
  struct s_rts_dtorlist*        next;
  void*                         object;
  union
  {
    void                        (*dtor)( void*, int );
    void                        (*dfun)();
  }
  fun;
};

struct timespec
{
  uint32                        tv_sec;
  int32                         tv_nsec;
};

extern     void*                __syscall_tab[];
#define errno                   v_os_errno

extern "C" void                 __abort_execution( an_error_code err_code );
extern "C" void                 __add_dtor( s_rts_dtorlist* dtor_entry );
extern "C" void                 __call_dtors();
extern     int                  _printfi( char** _format, va_list _ap, void* _op, int (*_outc)( char, void* ), int (*_outs)( char*, void* ) );
extern     int                  _scanfi( void* inp, const char* _format, va_list _ap, int (*_chkmbc)( void**, char**, int* ), int (*_inpchar)( void** ), void (*_uninpchar)( void**, char ) );
extern "C" int                  abs( int i );
extern "C" long                 labs( long i );
extern "C" long long            llabs( long long i );

#define                         __memzero memzero
extern     void                 abort();
extern     int                  atexit( void (*fun)() );
extern     int                  atoi( const char* st );
extern     void                 aswap16b( uint16* a, uint32 length );
extern     void                 aswap32b( uint32* a, uint32 length );
extern     void                 aswap32w( uint32* a, uint32 length );
extern     void                 aswap64b( uint64* a, uint32 length );
extern     void                 aswap64dw( uint64* a, uint32 length );
extern     void                 aswap64w( uint64* a, uint32 length );
extern     void                 bit_close( BIT_FILE* f );
extern     BIT_FILE*            bit_open( const char* fname, const char* mode );
extern     int32                bit_read( BIT_FILE* f, void* buf, int32 blen );
extern     int32                bit_write( BIT_FILE* f, const void* buf, int32 blen );
extern     void*                bsearch( register const void* key, register const void* base, size_t nmemb, size_t size, int (*compar)( const void*, const void* ) );
#define                         bzero memzero
extern     void*                calloc( size_t num, size_t size );
extern     int                  chdir( const char* path );
extern     int                  closedir( DIR* dirp );
extern     int32                close( int32 rid );
extern     float64              difftime( time_t time1, time_t time0 );
extern     char*                ecvt( long double value, register int ndigit, int *decpt, int* sign );
extern     void                 exit( int status );
extern     int                  fcntl( uint32 rid, int32 cmd, void* arg );
extern     int32                fclose( FILE* d );
extern     char*                fcvt( long double value, register int ndigit, int* decpt, int* sign );
extern     int                  feof( FILE* d );
extern     int                  fgetc( FILE* stream );
extern     int                  fgetpos( FILE* d, int64* offset );
extern     char*                fgets( char* s, int n, FILE* stream );
extern     uint32               fileno( FILE* f );
extern     FILE*                fopen( const char* path, const char* mode );
extern     int                  fprintf( FILE* _fp, const char* _format, ... );
extern     int                  fputc( int _c, FILE* _fp );
extern     int                  fputs( const char* _ptr, FILE* _fp );
extern     size_t               fread( void* buf, size_t l, size_t b, FILE* d );
extern     void                 free( void* packet );
extern     int                  fscanf( FILE* _fp, const char* _fmt, ... );
extern     int                  fseek( FILE* d, int32 offset, int whence );
extern     int                  fsetpos( FILE* d, const int64* offset );
extern     int32                fsize( FILE* d );
extern     int32                ftell( FILE* d );
extern     int                  ftruncate( uint32 d, off_t length );
extern     size_t               fwrite( const void* buf, size_t l, size_t b, FILE* d );
extern     char*                getcwd( char* buf, size_t size );
#define                         htonl swap32b
#define                         htons swap16b
extern     int32                ioctl( int32 rid, int32 request, void* arg );
extern     int                  isdigit( int c );
extern     int                  islower( int c );
extern     int                  isspace( int c );
extern     int                  isupper( int c );
extern     int                  isxdigit( int c );
extern     int                  itoa( int32 val, char* buffer );
extern     tm*                  localtime( const time_t* timer );
extern     tm*                  localtime_r( const time_t* timer, tm* result );
extern     int                  ltoa( long val, char* buffer );
extern     void*                malloc( size_t size );
extern "C" char*                memccpy( char* dest, const char* src, int ch, int cnt );
extern "C" int                  memcmp( const void* cs, const void* ct, size_t n );
extern "C" void*                memcpy( void* dst, const void* src, unsigned int len );
extern "C" void*                memmove( void* s1, const void* s2, size_t n );
extern "C" void*                memset( void* dst, int fill, size_t len );
extern "C" void                 memxor( void* dst, const void* src1, const void* src2, uint32 length );
extern "C" void                 memzero( void* buffer, size_t size );
extern     int                  mkdir( const char* path, mode_t mode );
extern     time_t               mktime( tm* timeptr );
#define                         ntohl swap32b
#define                         ntohs swap16b
extern     DIR*                 opendir( const char* dirname );
extern     void                 qsort( void* base, size_t nmemb, size_t size, int (*compar)( const void*, const void* ) );
extern     int                  rand();
extern     dirent*              readdir( DIR* dirp );
extern     int                  remove( const char* _file );
extern     int                  rename( const char* o_name, const char* n_name );
extern     int                  rmdir( const char* path );
extern     int32                scandir( DIR* dirp, dirent** r, int32 direction, bool nocasecmp );
extern     int                  sem_close( sem_t* sem );
extern     int                  sem_destroy( sem_t* sem );
extern     int                  sem_init( sem_t* sem, int pshared, unsigned int value );
extern     int                  sem_getvalue( sem_t* sem, int* sval );
//extern     sem_t*               sem_open( const char* name, int oflag, ... );
extern     int                  sem_post( sem_t* sem );
extern     int                  sem_timedwait( sem_t* sem, const timespec* abstime );
extern     int                  sem_trywait( sem_t* sem );
extern     int                  sem_wait( sem_t* sem );
extern     int                  sprintf( char* _string, const char* _format, ... );
extern     void                 srand( unsigned int seed );
extern     int                  sscanf( const char* _str, const char* _fmt, ... );
extern     int                  stat( const char* path, stat* buf );
extern     char*                strcat( char* string1, const char* string2 );
extern     char*                strchr( const char* string, int c );
extern     int                  strcmp( register const char* string1, register const char* string2 );
extern     char*                strcpy( register char* dest, register const char* src );
extern     size_t               strlen( const char* string );
extern "C" char*                strncat( char* dest, const char* src, register size_t n );
extern     int                  strncmp( const char* string1, const char* string2, size_t n );
extern     char*                strncpy( register char* dest, register const char* src, register size_t n );
extern "C" char*                strrchr( const char* string, int c );
extern "C" char*                strstr( register const char* string1, const char* string2 );
extern "C" double               strtod( const char* st, char** endptr );
extern "C" long                 strtol( const char* st, char** endptr, int base );
extern "C" long double          strtold( const char* st, char** endptr );
extern "C" long long            strtoll( const char* st, char** endptr, int base );
extern "C" unsigned long        strtoul( const char* st, char** endptr, int base );
extern "C" unsigned long long   strtoull( const char* st, char** endptr, int base );
extern     uint16               swap16b( uint16 a );
extern     uint32               swap32b( uint32 a );
extern     uint32               swap32w( uint32 a );
extern     uint64               swap64b( uint64 a );
extern     uint64               swap64dw( uint64 a );
extern     uint64               swap64w( uint64 a );
extern     time_t               time( time_t* timer );
extern     int                  tolower( int c );
extern     int                  toupper( int c );
extern     int                  ungetc( int c, FILE* stream );
extern     int                  vsnprintf( char* _string, size_t _n, const char* _format, va_list _ap );
extern     int                  vsprintf( char* _string, const char* _format, va_list _ap );

extern     void                 wlpk_close( WLPK_FILE* f );
extern     WLPK_FILE*           wlpk_open( const char* fname, const char* mode );
extern     int32                wlpk_read( WLPK_FILE* f, const void* buf, int32 blen );
extern     int32                wlpk_write( WLPK_FILE* f, const void* buf, int32 blen );

extern     void                 operator delete( void* ptr );
extern     void                 operator delete[]( void* ptr );
extern     void                 operator delete( void* ptr, const std::nothrow_t& nothrow_arg );
extern     void                 operator delete[]( void* ptr, const std::nothrow_t& nothrow_arg );
extern     void                 operator delete( void*, void* );
extern     void                 operator delete[]( void*, void* );

extern     void*                operator new( size_t size );
extern     void*                operator new[]( size_t size );
extern     void*                operator new( size_t size, const std::nothrow_t& nothrow_arg );
extern     void*                operator new[]( size_t size, const std::nothrow_t& nothrow_arg );
extern     void*                operator new( size_t s, void* ptr );
extern     void*                operator new[]( size_t s, void* ptr );

// -- Static memory allocator ------------------------------------------------

extern     int                  smem_init( int bcount, int bsize );
extern     void*                smem_alloc();
extern     void                 smem_free( void* ptr );

// ---------------------------------------------------------------------------
//  TCP/IP
// ---------------------------------------------------------------------------

#define SOCKET_ERROR    0xffffffff

typedef uint16  sa_family_t;

struct sockaddr 
{
        sa_family_t     sa_family;      // address family, AF_xxx        
        char sa_data[14];               // 14 bytes of protocol address  
};

struct in_addr {uint32  s_addr;};

struct sockaddr_in 
{
        sa_family_t     sin_family;     /* Address family               */
        uint16          sin_port;       /* Port number                  */
        in_addr         sin_addr;       /* Internet address             */
        uint8           pad[8];         /* Pad to size of `struct sockaddr'. */
};

// Supported address families.  
#define AF_INET         2       // Internet IP Protocol          
#define PF_INET         AF_INET

// Standard well-defined IP protocols.   
enum 
{
        IPPROTO_IP = 0,         // Dummy protocol for TCP                
        IPPROTO_ICMP = 1,       // Internet Control Message Protocol     
        IPPROTO_IGMP = 2,       // Internet Group Management Protocol    
        IPPROTO_IPIP = 4,       // IPIP tunnels (older KA9Q tunnels use 94)  
        IPPROTO_TCP = 6,        // Transmission Control Protocol         
        IPPROTO_EGP = 8,        // Exterior Gateway Protocol             
        IPPROTO_PUP = 12,       // PUP protocol                          
        IPPROTO_UDP = 17,       // User Datagram Protocol                
        IPPROTO_IDP = 22,       // XNS IDP protocol                      
        IPPROTO_DCCP = 33,      // Datagram Congestion Control Protocol  
        IPPROTO_RSVP = 46,      // RSVP protocol                         
        IPPROTO_GRE = 47,       // Cisco GRE tunnels (rfc 1701,1702)     
        IPPROTO_IPV6 = 41,      // IPv6-in-IPv4 tunnelling               
        IPPROTO_ESP = 50,       // Encapsulation Security Payload protocol  
        IPPROTO_AH = 51,        // Authentication Header protocol        
        IPPROTO_BEETPH = 94,    // IP option pseudo header for BEET  
        IPPROTO_PIM = 103,      // Protocol Independent Multicast        
        IPPROTO_COMP = 108,     // Compression Header protocol  
        IPPROTO_SCTP = 132,     // Stream Control Transport Protocol     
        IPPROTO_UDPLITE = 136,  // UDP-Lite (RFC 3828)                   
        IPPROTO_RAW = 255,      // Raw IP packets                        
        IPPROTO_MAX
};
// Flags we can use with send/ and recv. 
// Added those for 1003.1g not all are supported yet
#define MSG_OOB         1
#define MSG_PEEK        2
#define MSG_DONTROUTE   4
#define MSG_CTRUNC      8
#define MSG_PROBE       0x10    // Do not send. Only probe path f.e. for MTU  
#define MSG_TRUNC       0x20
#define MSG_DONTWAIT    0x40    // Nonblocking io                 
#define MSG_EOR         0x80    // End of record  
#define MSG_WAITALL     0x100   // Wait for a full request  
#define MSG_FIN         0x200
#define MSG_SYN         0x400
#define MSG_CONFIRM     0x800   // Confirm path validity  
#define MSG_RST         0x1000
#define MSG_ERRQUEUE    0x2000  // Fetch message from error queue  
#define MSG_NOSIGNAL    0x4000  // Do not generate SIGPIPE  
#define MSG_MORE        0x8000  // Sender will send more  

#define INADDR_ANY      0

#define MSG_EOF         MSG_FIN

// Setsockoptions(2) level. Thanks to BSD these must match IPPROTO_xxx  
#define SOL_SOCKET      1
#define SOL_IP          0
#define SOL_TCP         6
#define SOL_UDP         17
#define SOL_RAW         255

#define SO_DEBUG        1
#define SO_REUSEADDR    2
#define SO_TYPE         3
#define SO_ERROR        4
#define SO_DONTROUTE    5
#define SO_BROADCAST    6
#define SO_SNDBUF       7
#define SO_RCVBUF       8
#define SO_SNDBUFFORCE  32
#define SO_RCVBUFFORCE  33
#define SO_KEEPALIVE    9
#define SO_OOBINLINE    10
#define SO_NO_CHECK     11
#define SO_PRIORITY     12
#define SO_LINGER       13
#define SO_BSDCOMPAT    14
#define SO_REUSEPORT    15
#define SO_PASSCRED     16
#define SO_PEERCRED     17
#define SO_RCVLOWAT     18
#define SO_SNDLOWAT     19
#define SO_RCVTIMEO     20
#define SO_SNDTIMEO     21

enum sock_type 
{
        SOCK_STREAM     = 1,
        SOCK_DGRAM      = 2,
        SOCK_RAW        = 3,
        SOCK_RDM        = 4,
        SOCK_SEQPACKET  = 5,
        SOCK_DCCP       = 6,
        SOCK_PACKET     = 10
};

#define IOCTL_SETFLAG   1
 #define O_CLOEXEC       1
 #define O_NONBLOCK      2

#define IOCTL_ROUTEADD  2

struct route_add_parms
{
        uint32  network;        // Добавляемая подсеть XXX.XXX...0
        uint32  mask;           // Её маска     255.255...0
        uint32  gateway;        // Шлюз в эту подсеть, может быть равен нулю (если мы одним из адаптеров туда торчим)
        const char  *name;      // Имя адаптера без пути ( "eth0","eth1"...)
        char    isdef;          // Сюда шлём если ничего более подходящего не нашли
};

#define IOCTL_CHANGE_IP 3
struct change_ip_parms
{
        const char  *name;      // Имя адаптера без пути ( "eth0","eth1"...)
        uint32  new_ip;         // Новый IP адрес
        uint32  mask;           // маска
};

struct linger 
{
        int16           l_onoff;        // Linger active                 
        int16           l_linger;       // How long to linger for        
};


#ifndef __Extension_SysLog_H__
#define __Extension_SysLog_H__

#define LOG_EMERG               0
#define LOG_ALERT               1
#define LOG_CRIT                2
#define LOG_ERR                 3
#define LOG_WARNING             4
#define LOG_NOTICE              5
#define LOG_INFO                6
#define LOG_DEBUG               7

#define LOG_PRIMASK     0x07

#define LOG_PRI(p)      ((p) & LOG_PRIMASK)
#define LOG_MAKEPRI(fac, pri)   (((fac) << 3) | (pri))

#define LOG_KERN        (0<<3)
#define LOG_USER        (1<<3)
#define LOG_MAIL        (2<<3)
#define LOG_DAEMON      (3<<3)
#define LOG_AUTH        (4<<3)
#define LOG_SYSLOG      (5<<3)
#define LOG_LPR         (6<<3)
#define LOG_NEWS        (7<<3)
#define LOG_UUCP        (8<<3)
#define LOG_CRON        (9<<3)
#define LOG_AUTHPRIV    (10<<3)
#define LOG_FTP         (11<<3)

/* Codes through 15 are reserved for system use */
#define LOG_LOCAL0      (16<<3)
#define LOG_LOCAL1      (17<<3)
#define LOG_LOCAL2      (18<<3)
#define LOG_LOCAL3      (19<<3)
#define LOG_LOCAL4      (20<<3)
#define LOG_LOCAL5      (21<<3)
#define LOG_LOCAL6      (22<<3)
#define LOG_LOCAL7      (23<<3)

#endif

#endif
