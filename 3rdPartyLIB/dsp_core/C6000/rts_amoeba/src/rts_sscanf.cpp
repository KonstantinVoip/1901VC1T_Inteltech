// ---------------------------------------------------------------------------
// int sscanf( const char* _str, const char* _fmt, ... )
// ---------------------------------------------------------------------------
#include <stdarg.h>
#include <rts.h>
// ---------------------------------------------------------------------------
static int _inpchar( void** inp )
{
  char result;
  char* buf = (char*)(*inp);
  result = *(buf++);
  (*inp) = (void*)buf;  
  return ( ( result == '\0' ) ? EOF : result );
}
// ---------------------------------------------------------------------------
static void _uninpchar( void** inp, char outchar )
{
  char* buf = (char*)(*inp);
  buf--;
  (*inp) = (void*)buf;  
}
// ---------------------------------------------------------------------------
static int _chkmbc( void** inp, char** _format, int* num_read )
{
  char* buf = (char*)(*inp);

  while( isspace( (**_format) ) )
  {
    for( ; isspace( (*buf) ); buf++ ) (*num_read)++;
    (*_format)++;
  }

  for( ; ( (**_format) != '%') && ( (**_format) != '\0'); )
  {
    if( *((*_format)++) != *(buf++) ) return 0; else (*num_read)++;
  }

  if( (**_format) == '%' )
  {
    (*inp) = (void*)buf;
    return 1;
  }
  
  return 0;
}
// ---------------------------------------------------------------------------
int sscanf( const char* _str, const char* _fmt, ... )
{
  va_list _ap;
  va_start( _ap, _fmt );
  return _scanfi( (void*)_str, _fmt, _ap, _chkmbc, _inpchar, _uninpchar );
}
// ---------------------------------------------------------------------------
