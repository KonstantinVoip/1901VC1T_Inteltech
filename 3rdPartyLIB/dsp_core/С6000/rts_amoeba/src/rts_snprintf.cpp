// ---------------------------------------------------------------------------
#include <rts.h>
// ---------------------------------------------------------------------------
struct holder
{
  char*                         out_end;
  size_t                        n;
  size_t                        written;
};
// ---------------------------------------------------------------------------
static int _outc( char c, void* _op )
{
  holder* hld = (holder*)_op;
  if( hld->written < hld->n ) *hld->out_end++ = c;
  hld->written++;
  return c;
}
// ---------------------------------------------------------------------------
static int _outs( char* s, void* _op )
{
  holder* hld = (holder*)_op;
  size_t len = strlen( s );
  if( hld->written < hld->n )
  {
    size_t space = hld->n - hld->written;
    size_t use = len > space ? space : len;
    memcpy( hld->out_end, s, use );
    hld->out_end += use;
  }
  hld->written += len;
  return len;
}
// ---------------------------------------------------------------------------
int snprintf( char* _string, size_t _n, const char* _format, ... )
{
  va_list _ap;
  int rval;
  char* fptr = (char*)_format;
  holder hld;

  hld.out_end = _string;
  hld.n = _n;
  hld.written = 0;

  va_start( _ap, _format );
  rval = _printfi( &fptr, _ap, (void*)&hld, _outc, _outs );
  va_end( _ap );

  if( _n ) *hld.out_end = '\0';

  return rval;
}
// ---------------------------------------------------------------------------
