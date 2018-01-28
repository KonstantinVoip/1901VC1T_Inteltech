// ---------------------------------------------------------------------------
// int fscanf( FILE* _fp, const char* _fmt, ... )
// ---------------------------------------------------------------------------
#include <rts.h>
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
static int _inpchar( void** inp )
{
  return fgetc( (FILE*)(*inp) );
}
// ---------------------------------------------------------------------------
static void _uninpchar( void** inp, char outchar )
{ 
  ungetc( outchar, (FILE*)(*inp) );
}
// ---------------------------------------------------------------------------
static int _chkmbc( void** inp, char** _format, int* num_read )
{
  FILE* _fp = (FILE*)(*inp);
  signed char c;

  while( isspace( (**_format) ) )
  {
    for( c = fgetc( _fp ); isspace( c ); c = fgetc( _fp ) ) (*num_read)++;
    ungetc( c, _fp );
    (*_format)++;
  }

  for( ; ( (**_format) != '%' ) && ( (**_format) != '\0' ); )
  {
    if( (*((*_format)++)) != ( c = fgetc( _fp ) ) )
    {
      ungetc( c, _fp );
      return ( ( c == EOF ) ? EOF : 0 );
    }
    else (*num_read)++;
  }

  if( (**_format) == '%' ) return 1;
  
  return 0;
}
// ---------------------------------------------------------------------------
int fscanf( FILE* _fp, const char* _fmt, ... )
{
  va_list _ap;
  va_start( _ap, _fmt );
  if( _fp->rid == RES_VOID ) { errno = EINVAL; return 0; }
  return _scanfi( (void*)_fp, _fmt, _ap, _chkmbc, _inpchar, _uninpchar );
}
// ---------------------------------------------------------------------------
