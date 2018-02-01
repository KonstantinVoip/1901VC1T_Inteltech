// ---------------------------------------------------------------------------
// tm* localtime_r( const time_t* timer, tm* result )
// ---------------------------------------------------------------------------
#include <rts.h>
// ---------------------------------------------------------------------------

extern int _rts_time__timezone;
extern tm* _comtime( time_t ltime, int dst, tm& tmX );

// ---------------------------------------------------------------------------
tm* localtime_r( const time_t* timer, tm* result )
{
  if( ( timer == NULL ) || ( result == NULL ) ) return NULL;
  if( ((int32)(*timer)) < _rts_time__timezone ) return NULL;
  return _comtime( ((int32)(*timer)) - _rts_time__timezone, 1, (*result) );
}
// ---------------------------------------------------------------------------
