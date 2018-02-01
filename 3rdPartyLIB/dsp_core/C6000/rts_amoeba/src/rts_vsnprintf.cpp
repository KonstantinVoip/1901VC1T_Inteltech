// ---------------------------------------------------------------------------
// int vsnprintf( char* _string, size_t _n, const char* _format, va_list _ap )
// ---------------------------------------------------------------------------
#include <rts.h>
// ---------------------------------------------------------------------------

struct holder
{
  char* out_end;
  size_t n;
  size_t written;
};

// ---------------------------------------------------------------------------
static int _outc( char c, void* _op )
{
  holder* h = (holder*)_op;
  if( h->written < h->n ) *h->out_end++ = c;
  h->written++;
  return c;
}
// ---------------------------------------------------------------------------
static int _outs( char* s, void* _op )
{
  holder* h = (holder*)_op;
  size_t len = strlen( s );
  if( h->written < h->n )
  {
    size_t space = h->n - h->written;
    size_t use = len > space ? space : len;
    memcpy( h->out_end, s, use );
    h->out_end += use;
  }
  h->written += len;
  return len;
}
// ---------------------------------------------------------------------------
int vsnprintf( char* _string, size_t _n, const char* _format, va_list _ap )
{
  int rval;
  char* fptr = (char*)_format;
  holder h; 
  h.out_end = _string;
  h.n = _n;
  h.written = 0;
  rval = _printfi( &fptr, _ap, (void*)&h, _outc, _outs );
  if( _n ) *h.out_end = '\0';
  return rval;
}
// ---------------------------------------------------------------------------
