// ---------------------------------------------------------------------------
// int fprintf( FILE* _fp, const char* _format, ... )
// ---------------------------------------------------------------------------
#include <rts.h>
// ---------------------------------------------------------------------------
static int _outc( char c, void* _op )
{
  return fputc( c, (FILE*)_op );
}
// ---------------------------------------------------------------------------
static int _outs( char* s, void* _op )
{
  return fputs( s, (FILE*)_op );
}
// ---------------------------------------------------------------------------
int fprintf( FILE* _fp, const char* _format, ... )
{
  va_list _ap;
  int rval;
  if( _fp == NULL ) return -1;
  char* fptr = (char*)_format;
  va_start( _ap, _format );
  rval = _printfi( &fptr, _ap, (void*)_fp, _outc, _outs );
  va_end( _ap );
  return rval;
}
// ---------------------------------------------------------------------------
