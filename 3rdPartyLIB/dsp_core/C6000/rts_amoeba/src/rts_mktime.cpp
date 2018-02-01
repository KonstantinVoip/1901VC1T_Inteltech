// ---------------------------------------------------------------------------
// time_t mktime( tm* timeptr )
// ---------------------------------------------------------------------------
#include <rts.h>
// ---------------------------------------------------------------------------

#define _isDST( a, b, c, d ) (0)

extern char _rts_time__Days[12];
extern int _rts_time__YDays[13];
extern int _rts_time__timezone;
extern int _rts_time__daylight;

// ---------------------------------------------------------------------------
static time_t _totalsec( int year, int month, int day, int hour, int min, int sec, int dst_flag )
{
  int leaps;
  time_t days, secs;

  if( ( year < 70 ) || ( year > 138 ) ) return ((time_t)-1);

  min += sec / 60;
  sec %= 60;                                    /* Seconds are normalized */
  hour += min / 60;
  min %= 60;                                    /* Minutes are normalized */
  day += hour / 24;
  hour %= 24;                                   /* Hours are normalized   */

  year += month / 12;                           /* Normalize month (not necessarily final) */
  month %= 12;

  while( day >= _rts_time__Days[month] )
  {
    if( !( year & 3 ) && ( month == 1 ) )
    {
      if( day > 28 )
      {
        day -= 29;
        month++;
      }
      else
      {
        break;
      }
    }
    else
    {
      day -= _rts_time__Days[month];
      month++;
    }

    if( month >= 12 )                           /* Normalize month */
    {
      month -= 12;
      year++;
    }
  }

  year -= 70;
  leaps = ( year + 2 ) >> 2;

  if( !( ( year + 70 ) & 3 ) && ( month < 2 ) ) --leaps;
  days = year * 365L + leaps + _rts_time__YDays[month] + day;
  secs = days * 86400L + hour * 3600L + min * 60L + sec + _rts_time__timezone;

  if( dst_flag == -1 )
  {
    if( _rts_time__daylight && _isDST( hour, day, month + 1, year ) ) secs -= 3600;
  }
  else
  {
    secs -= dst_flag ? 3600 : 0;
  }

  return ( ( secs > 0 ) ? secs : (time_t)-1 );
}
// ---------------------------------------------------------------------------
time_t mktime( tm* timeptr )
{
  time_t secs;

  secs = _totalsec( timeptr->tm_year, timeptr->tm_mon, timeptr->tm_mday - 1,
                    timeptr->tm_hour, timeptr->tm_min, timeptr->tm_sec,
                    timeptr->tm_isdst );

  if( secs != (time_t)-1 ) (*timeptr) = (*localtime( &secs ));

  return secs;
}
// ---------------------------------------------------------------------------
