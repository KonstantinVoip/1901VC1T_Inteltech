// ---------------------------------------------------------------------------
// tm* _comtime( time_t ltime, int dst, tm& tmX )
// ---------------------------------------------------------------------------
#include <rts.h>
// ---------------------------------------------------------------------------

#define _isDST( a, b, c, d ) (0)

extern char _rts_time__Days[12];
extern int _rts_time__daylight;

// ---------------------------------------------------------------------------
tm* _comtime( time_t ltime, int dst, tm& tmX )
{
  unsigned long time;
  int hpery;
  unsigned i;
  unsigned cumdays;

  /* Perform all calculations using local tm structure (tmX), then
   * copy it to the thread's private tm structure before returing. */
  time = (unsigned long)ltime;
  tmX.tm_sec = (int)( time % 60 );
  time /= 60;                                   /* Time in minutes */
  tmX.tm_min = (int)( time % 60 );
  time /= 60;                                   /* Time in hours */
  i = (unsigned)( time / ( 1461L * 24L ) );     /* Number of 4 year blocks */
  tmX.tm_year = ( i << 2 );
  tmX.tm_year += 70;
  cumdays = 1461 * i;
  time %= 1461L * 24L;                          /* Hours since end of last 4 year block */

  for( ; ; )
  {
    hpery = 365 * 24;
    if( ( tmX.tm_year & 3 ) == 0 ) hpery += 24;
    if( time < hpery ) break;
    cumdays += hpery / 24;
    tmX.tm_year++;
    time -= hpery;
  }                                             /* at end, time is number of hours into current year */

  if( dst && _rts_time__daylight && _isDST( (int)( time % 24 ), (int)( time / 24 ), 0, tmX.tm_year - 70 ) )
  {
    time++;
    tmX.tm_isdst = 1;
  }
  else
  {
    tmX.tm_isdst = 0;
  }

  tmX.tm_hour = (int)( time % 24 );
  time /= 24;                                   /* Time in days */
  tmX.tm_yday = (int)time;
  cumdays += (int)time + 4;
  tmX.tm_wday = cumdays % 7;
  time++;

  if( ( tmX.tm_year & 3 ) == 0 )
  {
    if( time > 60 )
    {
      time--;
    }
    else
    {
      if( time == 60 )
      {
        tmX.tm_mon = 1;
        tmX.tm_mday = 29;
        return (&tmX);
      }
    }
  }

  for( tmX.tm_mon = 0; _rts_time__Days[tmX.tm_mon] < time; tmX.tm_mon++ ) time -= _rts_time__Days[tmX.tm_mon];
  tmX.tm_mday = (int)time;

  return (&tmX);
}
// ---------------------------------------------------------------------------
