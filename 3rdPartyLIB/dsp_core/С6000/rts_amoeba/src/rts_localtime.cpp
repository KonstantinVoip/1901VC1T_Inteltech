// ---------------------------------------------------------------------------
// tm* localtime( const time_t* timer );
// ---------------------------------------------------------------------------
#include <rts.h>
// ---------------------------------------------------------------------------

extern int _rts_time__timezone;
extern tm* _comtime( time_t ltime, int dst, tm& tmX );

static tm tmstr;

// ---------------------------------------------------------------------------
tm* localtime( const time_t* timer )
{
  if( timer == NULL ) return NULL;
  if( ((int32)(*timer)) < _rts_time__timezone ) return NULL;
  return _comtime( ((int32)(*timer)) - _rts_time__timezone, 1, tmstr );
}
// ---------------------------------------------------------------------------
