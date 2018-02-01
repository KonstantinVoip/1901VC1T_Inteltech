// ---------------------------------------------------------------------------
// int sprintf( char* _string, const char* _format, ... )
// ---------------------------------------------------------------------------
#include <rts.h>
// ---------------------------------------------------------------------------
static int _outc( char c, void* _op )
{
  return *(*((char**)_op))++ = c;
}
// ---------------------------------------------------------------------------
static int _outs( char* s, void* _op )
{
  size_t len = strlen( s );
  memcpy(*((char **)_op), s, len);
  *((char **)_op) += len;
  return len;
}
// ---------------------------------------------------------------------------
int sprintf( char* _string, const char* _format, ... )
{
  va_list _ap;
  int rval;
  char* fptr = (char*)_format;
  char* out_end = _string;
  va_start( _ap, _format );
  rval = _printfi( &fptr, _ap, (void*)&out_end, _outc, _outs );
  va_end( _ap );
  (*out_end) = '\0';
  return rval;
}
// ---------------------------------------------------------------------------
