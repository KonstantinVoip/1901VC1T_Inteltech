// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp1251
// !: d: ������ �������� ���������� ������� �������� �����
// !: d: ��������� ������� DS1302.
// !: -: 
// ---------------------------------------------------------------------------
#include <drv_rtc.h>
#include <os.h>
#include <rts.h>
#include <mem_fpga.iface15.h>

//************************************************
//       ������ ���������� ��������� �����
//************************************************
#define RG_SEC_WRITE         0x00000080
#define RG_SEC_READ          0x00000081
#define RG_MIN_WRITE         0x00000082
#define RG_MIN_READ          0x00000083
#define RG_HOUR_WRITE        0x00000084
#define RG_HOUR_READ         0x00000085
#define RG_DATE_WRITE        0x00000086
#define RG_DATE_READ         0x00000087
#define RG_MONTH_WRITE       0x00000088
#define RG_MONTH_READ        0x00000089
#define RG_DAY_WRITE         0x0000008A
#define RG_DAY_READ          0x0000008B
#define RG_YEAR_WRITE        0x0000008C
#define RG_YEAR_READ         0x0000008D


// ��������� ��� �������������� UNIX �������
#define UT_C1970        2440588L
#define UT_D0           1461L
#define UT_D1           146097L
#define UT_D2           1721119L

// ---------------------------------------------------------------------------
// !: sn: s_rtc_ctx
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sd: ��������� ��������� �������� ����� ��������� �������.
// !: sc: uint32, rtc_sem
// !: cd: ������������� �������� ����� ��������� �������
// ---------------------------------------------------------------------------
struct s_rtc_ctx
{
  uint32    rtc_sem;
};
// ---------------------------------------------------------------------------

//*******************************
//       ��������� �������
//*******************************
void time_unix2st( uint32 tunix, s_rtc_regs* tst );
void time_st2unix( s_rtc_regs& tst, uint32* tunix );

int32 settime( uint32* smfr, uint32* ut );
int32 gettime( uint32* smfr, uint32* ut );

int32 readst( uint32* smfr, s_rtc_regs* rg );
int32 writest( uint32* smfr, s_rtc_regs* rg );

int32 rtc_init( uint32* smphr );

int32 rtc_getSec( uint16* value );
int32 rtc_getMin( uint16* value );
int32 rtc_getHour( uint16* value );
int32 rtc_getDate( uint16* value );
int32 rtc_getMonth( uint16* value );
int32 rtc_getYear( uint16* value );

int32 rtc_setSec( uint16* value );
int32 rtc_setMin( uint16* value );
int32 rtc_setHour( uint16* value );
int32 rtc_setDate( uint16* value );
int32 rtc_setMonth( uint16* value );
int32 rtc_setYear( uint16* value );

int32 ds1302_read( uint16 address, uint16* value );
int32 ds1302_write( uint16 address, uint16* value );
// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------
// !: fn: int32 rtc_open (s_os_driver_descriptor* d, uint16 access)
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: ������� �� ������������. <br>
// !: d: � ������ ������, ���������� ����������� ��� ������ OSE_BAD_CMD.
// !: -:
// ---------------------------------------------------------------------------
int32 rtc_open (s_os_driver_descriptor* d, uint16 access)
{
  return OSE_BAD_CMD;
}

// ---------------------------------------------------------------------------
// !: fn: int32 rtc_close (s_os_driver_descriptor* d)
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: ������� �� ������������. <br>
// !: d: � ������ ������, ���������� ����������� ��� ������ OSE_BAD_CMD.
// !: -:
// ---------------------------------------------------------------------------
int32 rtc_close (s_os_driver_descriptor* d)
{
  return OSE_BAD_CMD;
}

// ---------------------------------------------------------------------------
// !: fn: int32 rtc_read (s_os_driver_descriptor* d, void* buf, int32 length)
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: ������� �� ������������. <br>
// !: d: � ������ ������, ���������� ����������� ��� ������ OSE_BAD_CMD.
// !: -:
// ---------------------------------------------------------------------------
int32 rtc_read (s_os_driver_descriptor* d, void* buf, int32 length)
{
  return OSE_BAD_CMD;
}

// ---------------------------------------------------------------------------
// !: fn: int32 rtc_write (s_os_driver_descriptor* d, const void* buf, int32 length)
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: ������� �� ������������. <br>
// !: d: � ������ ������, ���������� ����������� ��� ������ OSE_BAD_CMD.
// !: -:
// ---------------------------------------------------------------------------
int32 rtc_write (s_os_driver_descriptor* d, const void* buf, int32 length)
{
  return OSE_BAD_CMD;
}

// ---------------------------------------------------------------------------
// !: fn: int32 rtc_ioctl( s_os_driver_descriptor* d, int32 cmd, const void* arg )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: ������� ������������ ��� ���������� ����������� ����������� cmd
// !: d: ��� ��������� ����� ��������� �������. <br>
// !: d:
// !: d: �������������� ����������� ����������� �����������: <br>
// !: d: IOC_INIT, IOC_DEINIT, IOC_INODE_SELECT, IOC_SHUTDOWN. <br>
// !: d: ��������� ����������� ����������� ����������� �� ��������������. <br>
// !: d: 
// !: d: ����� �����������, ������� ������������ ����������� �����������
// !: d: �����������: <br>
// !: d: RTC_SET_TIME   - ���������� ����� arg, �������� � UNIX �������; <br>
// !: d: RTC_GET_TIME   - �������� ������� ����� arg � UNIX �������; <br>
// !: d: RTC_SET_TIME_STRUCT - ���������� ����� arg, �������� � ������� ���������; <br>
// !: d: RTC_GET_TIME_STRUCT - �������� ������� ����� arg � ������� ���������. <br>
// !: d: 
// !: d: � ������ ������ ���������� OSE_OK, �����, ����� ����������� ������: <br>
// !: d: OSE_RTC_TICK  - ���� ��������� ������� ����������� � �� �����������; <br>
// !: d: OSE_RTC_TEST  - ������ �������� ������ � ����; <br>
// !: d: OSE_RTC_WRITE - ������ ������ � ����; <br>
// !: d: OSE_RTC_READ  - ������ ������ �� �����. <br>
// !: d: 
// !: d: ������ ������� �������� ������������.
// !: -:
// ---------------------------------------------------------------------------
int32 rtc_ioctl( s_os_driver_descriptor* d, int32 cmd, const void* arg )
{
    static bool flag_shutdown = false;
    int32 error = OSE_OK;
    //*********************************
    //    Check shutdown condition
    //---------------------------------
    if( flag_shutdown )
        return OSE_OK;

    switch(cmd)
    {
        //================================
        //Standard control command:
        //================================
        case IOC_INIT_DESCRIPTOR:
		case IOC_DEINIT_DESCRIPTOR:
			break;
        
        case IOC_INIT:
        {
            s_os_driver_context* dctx = (s_os_driver_context*)const_cast<void*>( arg );
            s_rtc_ctx* rctx = (s_rtc_ctx*)dctx->data;
            rctx->rtc_sem = sem_alloc( 1, NULL );
            if( rctx->rtc_sem == RES_VOID )
            {
                return OSE_CANT_CREATE_SEM;
            }
            error = rtc_init( &rctx->rtc_sem );
        }
          break;

        case IOC_DEINIT:
        {
            s_os_driver_context* dctx = (s_os_driver_context*)const_cast<void*>( arg );
            s_rtc_ctx* rctx = (s_rtc_ctx*)dctx->data;
            if( rctx->rtc_sem != RES_VOID )
            {
                sem_free( rctx->rtc_sem );
                rctx->rtc_sem = 0;
            }
        }
          break;

        case IOC_SHUTDOWN:
        {
            flag_shutdown = true;
        }
          break;

        case IOC_INODE_SELECT:
        {
            if( arg == NULL ) return OSE_NULL_PARAM;

            char* dst = (char*)const_cast<void*>( arg );
      
            if( strcmp( dst, "." ) == 0 ) break;
            if( strcmp( dst, ".." ) != 0 ) return OSE_NO_NODE;
            drv_dec( d );
            drv_rfs( d );
        }
          break;


        //===============================================================
        //Driver control command:
        //===============================================================
        case RTC_SET_TIME:                  //      ���������� �����/����
        {
            if( arg == NULL ) return OSE_NULL_PARAM;
            if( d->ctx->data == NULL ) return OSE_BAD_DCTX;
            s_rtc_ctx* dctxdata = (s_rtc_ctx*)d->ctx->data;
            uint32 get_t = 0;
            
            // �������� ����� � ����
            error = settime( &dctxdata->rtc_sem, (uint32*)arg );
            if( error != OSE_OK ) break;
            // ��������� ���������� �����
            error = gettime( &dctxdata->rtc_sem, &get_t );
            if( error != OSE_OK ) break;
            
            // ��������� ���������� � ����������� �������� ����� �� ����������� � >2 ���
            if( (get_t < *(uint32*)arg) || ((get_t - *(uint32*)arg) > 2) )
            {
                error = OSE_RTC_TEST;
            }
        }
          break;
        case RTC_GET_TIME:                  //      ��������� �����/����
        {
            if( arg == NULL ) return OSE_NULL_PARAM;
            if( d->ctx->data == NULL ) return OSE_BAD_DCTX;
            s_rtc_ctx* dctxdata = (s_rtc_ctx*)d->ctx->data;
            
            error = gettime( &dctxdata->rtc_sem, (uint32*)arg );
        }
          break;
        
        case RTC_SET_TIME_STRUCT:           //      ���������� �����/����
        {
            if( arg == NULL ) return OSE_NULL_PARAM;
            if( d->ctx->data == NULL ) return OSE_BAD_DCTX;
            s_rtc_ctx* dctxdata = (s_rtc_ctx*)d->ctx->data;
            s_rtc_regs* tstr = (s_rtc_regs*)arg;
            
            if( tstr->sec > 59 ) return OSE_BAD_PARAM;
            if( tstr->min > 59 ) return OSE_BAD_PARAM;
            if( tstr->hour > 23 ) return OSE_BAD_PARAM;
            if( ( tstr->day == 0 ) || ( tstr->day > 31 ) ) return OSE_BAD_PARAM;
            if( ( tstr->month == 0  ) || ( tstr->month > 12 ) ) return OSE_BAD_PARAM;
            if( ( tstr->year < 1970 ) || ( tstr->year > 2069 ) ) return OSE_BAD_PARAM;
            
            // �������� ����� � ����
            error = writest( &dctxdata->rtc_sem, (s_rtc_regs*)arg );
        }
          break;
        case RTC_GET_TIME_STRUCT:             //      ��������� �����/����
        {
            if( arg == NULL ) return OSE_NULL_PARAM;
            if( d->ctx->data == NULL ) return OSE_BAD_DCTX;
            s_rtc_ctx* dctxdata = (s_rtc_ctx*)d->ctx->data;
            // ��������� �����
            error = readst( &dctxdata->rtc_sem, (s_rtc_regs*)arg );
        }
          break;

        default:
          return OSE_BAD_CMD;
    }
    return error;
}

// ---------------------------------------------------------------------------
// !: fn: int32 drv_rtc_plug( const char* path )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: ������� ��������� ������� ����� ��������� �������
// !: d: � ����� ������������ path. <br>
// !: d: ������ ������� �������� ������������.
// !: -:
// ---------------------------------------------------------------------------
int32 drv_rtc_plug( const char* path )
{
    s_rtc_ctx ctx;
    memset( &ctx, 0, sizeof(s_rtc_ctx) );
    return drv_plug( path, INOT_FILE, &rtc_open, &rtc_close, &rtc_read, &rtc_write, &rtc_ioctl, &ctx, sizeof(s_rtc_ctx) );
}

// ---------------------------------------------------------------------------
// !: fn: int32 drv_rtc_unplug( const char* name )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: ������� ������� ������� ����� ��������� ������� � ������ name. <br>
// !: d: ������ ������� �������� ������������.
// !: -:
// ---------------------------------------------------------------------------
int32 drv_rtc_unplug( const char* name )
{
    return drv_unplug( name );
}


// ---------------------------------------------------------------------------
// !: fn: void time_unix2st(uint32 tunix, s_rtc_regs* tst)
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: ������� ����������� ����� tunix �� UNIX ������� � ��������� tst. <br>
// !: d: ������ ������� �� �������� ������������.
// !: -:
// ---------------------------------------------------------------------------
void time_unix2st(uint32 tunix, s_rtc_regs* tst)
{
  uint32 date,time,temp;
  uint32 xyear,yyear,ymonth,yday;

  date = tunix/86400+UT_C1970;
  time = tunix%86400;
  temp = ((date-UT_D2)<<2)-1;
  xyear = (temp%UT_D1)|3;
  date = temp/UT_D1;
  yyear = xyear/UT_D0;
  temp = (((xyear%UT_D0)+4)>>2)*5-3;
  ymonth = temp/153;
  if(ymonth>=10){
    yyear++;
    ymonth -= 12;
  }
  tst->month = ymonth+3;
  yday = temp%153;
  tst->day = (yday+5)/5;
  tst->year = yyear+(date*100);
  tst->hour = time/3600;
  time %= 3600;
  tst->min = time/60;
  tst->sec = time%60;
}

// ---------------------------------------------------------------------------
// !: fn: void time_st2unix(s_rtc_regs& tst, uint32* tunix)
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: ������� ����������� ����� tst �� ��������� � UNIX ������ tunix. <br>
// !: d: ������ ������� �� �������� ������������.
// !: -:
// ---------------------------------------------------------------------------
void time_st2unix(s_rtc_regs& tst, uint32* tunix)
{
  uint32 century,xyear,month,date,year;
  uint32 dayspast;

  month = tst.month;
  year = tst.year;
  if(month<=2)
  {
    year--;
    month+=12;
  }
  month-=3;
  century = year/100;
  xyear = year%100;
  century = (century*UT_D1)>>2;
  xyear = (xyear*UT_D0)>>2;
  date = (month*153+2)/5+tst.day+UT_D2+xyear+century;
  dayspast = date-UT_C1970;
  *tunix = dayspast*86400;
  *tunix += (uint32)tst.hour*3600+(uint32)tst.min*60+(uint32)tst.sec;
}

// ---------------------------------------------------------------------------
// !: fn: int32 settime( uint32* smphr, uint32* ut )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: ������� ���������� �������� ����� ut � UNIX ������� � ����
// !: d: ��������� �������.  <br>
// !: d: � ������ ������ ���������� OSE_OK, �����: <br>
// !: d: OSE_RTC_WRITE - ������ ������ � ����. <br>
// !: d: 
// !: d: ������ ������� �� �������� ������������.
// !: -:
// ---------------------------------------------------------------------------
int32 settime( uint32* smphr, uint32* ut )
{
    s_rtc_regs srg;
    // convert unixtime to struct
    time_unix2st( *ut, &srg );
    return writest( smphr, &srg );
}

// ---------------------------------------------------------------------------
// !: fn: int32 writest( uint32* smfr, s_rtc_regs* rg )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: ������� ���������� �������� ����� rg � ������� ��������� � ����
// !: d: ��������� �������.  <br>
// !: d: � ������ ������ ���������� OSE_OK, �����: <br>
// !: d: OSE_RTC_WRITE - ������ ������ � ����. <br>
// !: d: 
// !: d: ������ ������� �� �������� ������������.
// !: -:
// ---------------------------------------------------------------------------
int32 writest( uint32* smfr, s_rtc_regs* rg )
{
    int32 error = OSE_OK;
    sem_lock( *smfr, SEM_INFINITY );
    //  write struct to regs
    if( rtc_setSec( &rg->sec )     != OSE_OK ) error = OSE_RTC_WRITE;
    if( rtc_setMin( &rg->min )     != OSE_OK ) error = OSE_RTC_WRITE;
    if( rtc_setHour( &rg->hour )   != OSE_OK ) error = OSE_RTC_WRITE;
    if( rtc_setDate( &rg->day )    != OSE_OK ) error = OSE_RTC_WRITE;
    if( rtc_setMonth( &rg->month ) != OSE_OK ) error = OSE_RTC_WRITE;
    if( rtc_setYear( &rg->year)    != OSE_OK ) error = OSE_RTC_WRITE;

    sem_unlock( *smfr );
    return error;
}

// ---------------------------------------------------------------------------
// !: fn: int32 gettime( uint32* smphr, uint32* ut )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: ������� �������� �� ����� ��������� ������� ����� ut � UNIX �������. <br>
// !: d: � ������ ������ ���������� OSE_OK, �����: <br>
// !: d: OSE_RTC_READ - ������ ������ �� �����. <br>
// !: d: 
// !: d: ������ ������� �� �������� ������������.
// !: -:
// ---------------------------------------------------------------------------
int32 gettime( uint32* smphr, uint32* ut )
{
    s_rtc_regs srg;
    int32 error = readst( smphr, &srg );
    // convert struct to unix time
    time_st2unix( srg, ut );
    return error;
}

// ---------------------------------------------------------------------------
// !: fn: int32 readst( uint32* smfr, s_rtc_regs* rg )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: ������� �������� �� ����� ��������� ������� ����� rg � �������
// !: d: ���������.  <br>
// !: d: � ������ ������ ���������� OSE_OK, �����: <br>
// !: d: OSE_RTC_READ - ������ ������ �� �����. <br>
// !: d: 
// !: d: ������ ������� �� �������� ������������.
// !: -:
// ---------------------------------------------------------------------------
int32 readst( uint32* smfr, s_rtc_regs* rg )
{
    int32 error = OSE_OK;
    sem_lock( *smfr, SEM_INFINITY );
    //  read regs to struct
    if( rtc_getSec( &rg->sec )     != OSE_OK ) error = OSE_RTC_READ;
    if( rtc_getMin( &rg->min )     != OSE_OK ) error = OSE_RTC_READ;
    if( rtc_getHour( &rg->hour )   != OSE_OK ) error = OSE_RTC_READ;
    if( rtc_getDate( &rg->day )    != OSE_OK ) error = OSE_RTC_READ;
    if( rtc_getMonth( &rg->month ) != OSE_OK ) error = OSE_RTC_READ;
    if( rtc_getYear( &rg->year )   != OSE_OK ) error = OSE_RTC_READ;
    sem_unlock( *smfr );
    return error;
}

// ---------------------------------------------------------------------------
// !: fn: int32 rtc_init( uint32* smphr )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: ������� ���������� ������������� � ���� ����� ��������� �������. <br>
// !: d: � ������ ������ ���������� OSE_OK, �����: <br>
// !: d: OSE_RTC_READ - ������ ������ �� �����; <br>
// !: d: OSE_RTC_TICK - ���� �����, �� "������". <br>
// !: d: 
// !: d: ������ ������� �� �������� ������������.
// !: -:
// ---------------------------------------------------------------------------
int32 rtc_init( uint32* smphr )
{
    uint32 rzrv = 0;
    uint32 get_t;
    uint16 temp = 0;

    // ��������� �������� �������
    if( ds1302_read( RG_SEC_READ, &temp ) != OSE_OK ) return OSE_RTC_READ;
    // ���������, ��� ��� �������� �������
    if( temp & 0x80 )
    {
        temp ^=0x80;    // ���� ���������� ��� �������� - �������� ���.
        ds1302_write( RG_SEC_WRITE, &temp );
    }

    // ��������� � ��������� ����� � ������
    if( gettime( smphr, &rzrv ) != OSE_OK ) return OSE_RTC_READ;
    //  ������� �� 2 ���
    sleep_s( 2 );
    // ���������, ��� ������ 2 ���
    if( gettime( smphr, &get_t) != OSE_OK ) return OSE_RTC_READ;
    if( (get_t - rzrv) < 2 ) return OSE_RTC_TICK;
    return OSE_OK;
}

// ---------------------------------------------------------------------------
// !: fn: int32 rtc_getSec( uint16* value )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: ������� �������� ������� �������� ������ value
// !: d: �� ���������������� �������� ����� ��������� �������. <br>
// !: d: � ������ ������ ���������� OSE_OK, �����: <br>
// !: d: OSE_TIMEOUT - ������� �������� ������ �� �����. <br>
// !: d: 
// !: d: ������ ������� �� �������� ������������.
// !: -:
// ---------------------------------------------------------------------------
int32 rtc_getSec( uint16* value )
{
    uint16 temp;
    if( ds1302_read( RG_SEC_READ, &temp ) != 0 ) return OSE_TIMEOUT;
    *value = (temp & 0x000f) + ((temp >> 4) & 0x0007) * 10;
    return OSE_OK;
}

// ---------------------------------------------------------------------------
// !: fn: int32 rtc_getMin( uint16* value )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: ������� �������� ������� �������� ����� value
// !: d: �� ���������������� �������� ����� ��������� �������. <br>
// !: d: � ������ ������ ���������� OSE_OK, �����: <br>
// !: d: OSE_TIMEOUT - ������� �������� ������ �� �����. <br>
// !: d: 
// !: d: ������ ������� �� �������� ������������.
// !: -:
// ---------------------------------------------------------------------------
int32 rtc_getMin( uint16* value )
{
    uint16 temp;
    if( ds1302_read( RG_MIN_READ, &temp ) != 0 ) return OSE_TIMEOUT;
    *value = (temp & 0x000f) + ((temp >> 4) & 0x0007) * 10;
    return OSE_OK;
}

// ---------------------------------------------------------------------------
// !: fn: int32 rtc_getHour( uint16* value )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: ������� �������� ������� �������� ���� value
// !: d: �� ���������������� �������� ����� ��������� �������. <br>
// !: d: � ������ ������ ���������� OSE_OK, �����: <br>
// !: d: OSE_TIMEOUT - ������� �������� ������ �� �����. <br>
// !: d: 
// !: d: ������ ������� �� �������� ������������.
// !: -:
// ---------------------------------------------------------------------------
int32 rtc_getHour( uint16* value )
{
    uint16 temp;
    if( ds1302_read( RG_HOUR_READ, &temp ) != 0 ) return OSE_TIMEOUT;
    *value = (temp & 0x000f) + ((temp >> 4) & 0x0003) * 10;
    return OSE_OK;
}

// ---------------------------------------------------------------------------
// !: fn: int32 rtc_getDate( uint16* value )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: ������� �������� ������� �������� ���� value
// !: d: �� ���������������� �������� ����� ��������� �������. <br>
// !: d: � ������ ������ ���������� OSE_OK, �����: <br>
// !: d: OSE_TIMEOUT - ������� �������� ������ �� �����. <br>
// !: d: 
// !: d: ������ ������� �� �������� ������������.
// !: -:
// ---------------------------------------------------------------------------
int32 rtc_getDate( uint16* value )
{
    uint16 temp;
    if( ds1302_read( RG_DATE_READ, &temp ) != 0 ) return OSE_TIMEOUT;
    *value = (temp & 0x000f) + ((temp >> 4) & 0x0003) * 10;
    return OSE_OK;
}

// ---------------------------------------------------------------------------
// !: fn: int32 rtc_getMonth( uint16* value )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: ������� �������� ������� �������� ������ value
// !: d: �� ���������������� �������� ����� ��������� �������. <br>
// !: d: � ������ ������ ���������� OSE_OK, �����: <br>
// !: d: OSE_TIMEOUT - ������� �������� ������ �� �����. <br>
// !: d: 
// !: d: ������ ������� �� �������� ������������.
// !: -:
// ---------------------------------------------------------------------------
int32 rtc_getMonth( uint16* value )
{
    uint16 temp;
    if( ds1302_read( RG_MONTH_READ, &temp ) != 0 ) return OSE_TIMEOUT;
    *value = (temp & 0x000f) + ((temp >> 4) & 0x0001) * 10;
    return OSE_OK;
}

// ---------------------------------------------------------------------------
// !: fn: int32 rtc_getYear( uint16* value )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: ������� �������� ������� �������� ���� value
// !: d: �� ���������������� �������� ����� ��������� �������. <br>
// !: d: � ������ ������ ���������� OSE_OK, �����: <br>
// !: d: OSE_TIMEOUT - ������� �������� ������ �� �����. <br>
// !: d: 
// !: d: ������ ������� �� �������� ������������.
// !: -:
// ---------------------------------------------------------------------------
int32 rtc_getYear( uint16* value )
{
    uint16 temp;
    if( ds1302_read( RG_YEAR_READ, &temp ) != 0 ) return OSE_TIMEOUT;
    uint16 rvalue = 1900 + (temp & 0x000f) + ((temp >> 4) & 0x000f) * 10;
    if( rvalue < 1970 ) rvalue += 100;
    *value = rvalue;
    return OSE_OK;
}

// ---------------------------------------------------------------------------
// !: fn: int32 rtc_setSec( uint16* value )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: ������� ���������� �������� �������� ������ value
// !: d: � ��������������� ������� ����� ��������� �������. <br>
// !: d: � ������ ������ ���������� OSE_OK, �����: <br>
// !: d: OSE_TIMEOUT - ������� �������� ������ �� �����. <br>
// !: d: 
// !: d: ������ ������� �� �������� ������������.
// !: -:
// ---------------------------------------------------------------------------
int32 rtc_setSec( uint16* value )
{
    uint16 rvalue = *value%10 + ((*value / 10) << 4);
    return ds1302_write( RG_SEC_WRITE, &rvalue );
}

// ---------------------------------------------------------------------------
// !: fn: int32 rtc_setMin( uint16* value )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: ������� ���������� �������� �������� ����� value
// !: d: � ��������������� ������� ����� ��������� �������. <br>
// !: d: � ������ ������ ���������� OSE_OK, �����: <br>
// !: d: OSE_TIMEOUT - ������� �������� ������ �� �����. <br>
// !: d: 
// !: d: ������ ������� �� �������� ������������.
// !: -:
// ---------------------------------------------------------------------------
int32 rtc_setMin( uint16* value )
{
    uint16 rvalue = *value%10 + ((*value / 10) << 4);
    return ds1302_write( RG_MIN_WRITE, &rvalue );
}

// ---------------------------------------------------------------------------
// !: fn: int32 rtc_setHour( uint16* value )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: ������� ���������� �������� �������� ���� value
// !: d: � ��������������� ������� ����� ��������� �������. <br>
// !: d: � ������ ������ ���������� OSE_OK, �����: <br>
// !: d: OSE_TIMEOUT - ������� �������� ������ �� �����. <br>
// !: d: 
// !: d: ������ ������� �� �������� ������������.
// !: -:
// ---------------------------------------------------------------------------
int32 rtc_setHour( uint16* value )
{
    uint16 rvalue = *value%10 + ((*value / 10) << 4);
    return ds1302_write( RG_HOUR_WRITE, &rvalue );
}

// ---------------------------------------------------------------------------
// !: fn: int32 rtc_setDate( uint16* value )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: ������� ���������� �������� �������� ���� value
// !: d: � ��������������� ������� ����� ��������� �������. <br>
// !: d: � ������ ������ ���������� OSE_OK, �����: <br>
// !: d: OSE_TIMEOUT - ������� �������� ������ �� �����. <br>
// !: d: 
// !: d: ������ ������� �� �������� ������������.
// !: -:
// ---------------------------------------------------------------------------
int32 rtc_setDate( uint16* value )
{
    uint16 rvalue = *value%10 + (( *value / 10) << 4);
    return ds1302_write( RG_DATE_WRITE, &rvalue );
}

// ---------------------------------------------------------------------------
// !: fn: int32 rtc_setMonth( uint16* value )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: ������� ���������� �������� �������� ������ value
// !: d: � ��������������� ������� ����� ��������� �������. <br>
// !: d: � ������ ������ ���������� OSE_OK, �����: <br>
// !: d: OSE_TIMEOUT - ������� �������� ������ �� �����. <br>
// !: d: 
// !: d: ������ ������� �� �������� ������������.
// !: -:
// ---------------------------------------------------------------------------
int32 rtc_setMonth( uint16* value )
{
    uint16 rvalue = *value%10 + ((*value / 10) << 4);
    return ds1302_write( RG_MONTH_WRITE, &rvalue );
}

// ---------------------------------------------------------------------------
// !: fn: int32 rtc_setYear( uint16* value )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: ������� ���������� �������� �������� ���� value
// !: d: � ��������������� ������� ����� ��������� �������. <br>
// !: d: � ������ ������ ���������� OSE_OK, �����: <br>
// !: d: OSE_TIMEOUT - ������� �������� ������ �� �����. <br>
// !: d: 
// !: d: ������ ������� �� �������� ������������.
// !: -:
// ---------------------------------------------------------------------------
int32 rtc_setYear( uint16* value )
{
    *value = (*value - 1900)%100;
    uint16 rvalue = *value%10 + ((*value / 10) << 4);
    return ds1302_write( RG_YEAR_WRITE, &rvalue );
}

// ---------------------------------------------------------------------------
// !: fn: int32 ds1302_read( uint16 address, uint16* value )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: ������� �������� �������� value �� �������� address
// !: d: ����� ��������� �������. <br>
// !: d: � ������ ������ ���������� OSE_OK, �����: <br>
// !: d: OSE_TIMEOUT - ������� �������� ������ �� �����. <br>
// !: d: 
// !: d: ������ ������� �� �������� ������������.
// !: -:
// ---------------------------------------------------------------------------
int32 ds1302_read( uint16 address, uint16* value )
{
    uint64 tms = time_core();
    while( REG_DS_STATUS & 0x1 )
    {
        if ( (time_core() - tms) >= 10 )
            return OSE_TIMEOUT;
    };
    REG_DS_RECEIVE = (address & 0xFF) << 8;

    tms = time_core();
    while( REG_DS_STATUS & 0x1 )
    {
        if( (time_core() - tms) >= 10 )
            return OSE_TIMEOUT;
    };
    *value = REG_DS_RECEIVE & 0xFF;
    return OSE_OK;
}

// ---------------------------------------------------------------------------
// !: fn: int32 ds1302_write( uint16 address, uint16* value )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: ������� ���������� �������� �������� value
// !: d: � ������� address ����� ��������� �������. <br>
// !: d: � ������ ������ ���������� OSE_OK, �����: <br>
// !: d: OSE_TIMEOUT - ������� �������� ������ �� �����. <br>
// !: d: 
// !: d: ������ ������� �� �������� ������������.
// !: -:
// ---------------------------------------------------------------------------
int32 ds1302_write( uint16 address, uint16* value )
{
    uint16 Value = (address << 8) + *value;
    uint64 tms = time_core();
    while( REG_DS_STATUS & 0x1 )
    {
        if( (time_core() - tms) >= 10 )
            return OSE_TIMEOUT;
    };
    REG_DS_TRANSMIT = Value;
    return OSE_OK;
}

// ---------------------------------------------------------------------------






