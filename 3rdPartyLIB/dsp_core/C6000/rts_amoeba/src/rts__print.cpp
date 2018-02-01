// ---------------------------------------------------------------------------
// int _printfi( char** _format, va_list _ap, void* _op, int (*_outc)( char, void* ), int (*_outs)( char*, void* ) )
// ---------------------------------------------------------------------------
#include <stdarg.h>
#include <stdint.h>
#include <limits.h>
#include <math.h>
#include <rts.h>
// ---------------------------------------------------------------------------

#define _PFMINUS                0x01
#define _PFPLUS                 0x02
#define _PFSPACE                0x04
#define _PFPOUND                0x08
#define _PFZERO                 0x10
#define _SFSTAR                 0x01
#define _SFCIRC                 0x02
#define _MFH                    0x20
#define _MFL                    0x40
#define _MFLD                   0x80
#define _MFLL                   0x100
#define _MFHH                   0x200
#define _ARSIZE                 400


// math.h std library parts
#define _LMAX	((unsigned short)0x7fff)
#define INIT(w0, w1)		{0, 0, 0, 0, 0, 0, w1, w0} // little-endian floating point
typedef union
	{	/* pun float types as integer array */
	unsigned short _Word[8];
	float _Float;
	double _Double;
	long double _Long_double;
	} _Dconst;
_Dconst _LInf = {INIT(_LMAX, 0x8000)};


struct _PFIELD
{
  unsigned int flags;
  int fwidth;
  int precision;
  char conv;
};

// ---------------------------------------------------------------------------

static uintmax_t _div( uintmax_t cvt, int base );
static int _ltostr( uintmax_t cvt, int base, char conv, char** a_it );
static uintmax_t _getarg_diouxp( _PFIELD* pfield, va_list* _ap );
static int _pproc_diouxp( _PFIELD* pfield, int* minus_flag, char** a_it, va_list* _ap );
static char* _mcpy( const char* tmpbuf, int dpt, int putdec, char** a_it );
static char* _ecpy( int exp, char letter, char** a_it );
static char* _fcpy( const char* tmpbuf, int dpt, int trail, int precision, char** a_it );
static void _pconv_g( long double cvt, _PFIELD* pfield, char** a_it );
static void _pconv_e( long double cvt, _PFIELD* pfield, char** a_it );
static void _pconv_f( long double cvt, _PFIELD* pfield, char** a_it );
static void _pproc_fge( _PFIELD* pfield, int* minus_flag, char** a_it, va_list* _ap );
static char* _setfield( _PFIELD* pfield, va_list* _ap );
static void _pproc_fflags( _PFIELD* pfield, char** it );
static void _pproc_fwp( _PFIELD* pfield, char** it, va_list* _ap );
static void _pproc_str( _PFIELD* pfield, void* _op, va_list* _ap, int* count, int (*_outs)( char*, void* ) );

// ---------------------------------------------------------------------------

#define SIGNED_CONV ( ( pfield->conv != 'u' ) && ( pfield->conv != 'o' ) && ( pfield->conv != 'x' ) && ( pfield->conv != 'X' ) )

#ifndef _SET
#  define _SET( _fp, _b ) ( (_fp)->flags ) |= (_b)
#endif

#ifndef _UNSET
#  define _UNSET( _fp, _b ) ( ( (_fp)->flags ) &= ~(_b) )
#endif

#ifndef _STCHK
#  define _STCHK( _fp, _b ) ( ( (_fp)->flags) & (_b) )
#endif

// ---------------------------------------------------------------------------
int _printfi( char** _format, va_list _ap, void* _op, int (*_outc)( char, void* ), int (*_outs)( char*, void* ) )
{
  char* end = (*_format) + strlen(*_format);
  int count =  0;
  _PFIELD pfield;

  while( (*_format) < end )
  {
    pfield.flags = 0;
    pfield.fwidth = 0;
    pfield.precision = -1;
    pfield.conv = 0;

    for( ; ( (**_format) != '%' ) && ( (**_format) != '\0' ); _outc( *( (*_format)++ ), _op ), count++ );

    if( !(**_format) ) break;
    (*_format)++;

    _pproc_fflags( &pfield, _format );
    _pproc_fwp( &pfield, _format, &_ap );

    switch( (**_format) )
    {
      case 'L': _SET( &pfield, _MFLD ); (*_format)++; break;
      case 'h': _SET( &pfield, _MFH ); (*_format)++; break;
      case 'l':
      {
        (*_format)++; 
        if( (**_format) == 'l' )
        {
          _SET( &pfield, _MFLL );
          (*_format)++;
        }
        else
        {
          _SET( &pfield, _MFL );
        }
      }
    }

    pfield.conv = *( (*_format)++ );

    if( pfield.conv == 'n' )
    {
      switch (pfield.flags & (_MFLL | _MFL | _MFH))
      {
        case _MFLL: *( va_arg( _ap, long long* ) ) = (long long)count; break;
        case _MFL: *( va_arg( _ap, long* ) ) = (long)count; break;
        case _MFH: *( va_arg( _ap, short* ) ) = (short)count; break;
        default: *( va_arg( _ap, int* ) ) = (int)count; break;
      }
    }
    else if( pfield.conv == 's' )
    {
      _pproc_str( &pfield, _op, &_ap, &count, _outs );
    }
    else
    {
      count += _outs( _setfield( &pfield, &_ap ), _op );
    }
  }

  return count;
}
// ---------------------------------------------------------------------------
static void _pproc_fflags( _PFIELD* pfield, char** it )
{
  int flags_done = 0;

  while( !flags_done )
  {
    switch( (**it) )
    {
      case '-':
      {
        _SET( pfield, _PFMINUS );
        (*it)++;
      }
      break;   

      case '+':
      {
        _SET( pfield, _PFPLUS );
        (*it)++;
      }
      break;

      case ' ':
      {
        _SET( pfield, _PFSPACE );
        (*it)++;
      }
      break;

      case '#':
      {
        _SET( pfield, _PFPOUND );
        (*it)++;
      }
      break;

      case '0':
      {
        _SET( pfield, _PFZERO );
        (*it)++;
      }
      break;

      default: flags_done = 1;
    }
  }

}
// ---------------------------------------------------------------------------
static void _pproc_fwp( _PFIELD* pfield, char** it, va_list* _ap )
{
  char tmpstr[10];
  char* tmpptr;

  if( (**it) == '*' )
  {
    pfield->fwidth = va_arg( (*_ap), int );
    if( pfield->fwidth < 0 )
    {
      pfield->fwidth = -(pfield->fwidth);
      _SET( pfield, _PFMINUS );
    }
    (*it)++;
  }
  else
  {
    tmpptr = tmpstr;
    memset( tmpptr, '\0', 10 );
    while( ( (**it) >= '0' ) && ( (**it) <= '9' ) ) *(tmpptr++) = *((*it)++);
    if( (*tmpstr) != '\0' ) pfield->fwidth = atoi( tmpstr );
  }

  if( (**it) == '.' )
  {
    (*it)++;

    if( (**it) == '*' )
    {
      pfield->precision = va_arg( (*_ap), int );
      (*it)++;
    }
    else
    {
      tmpptr = tmpstr;
      memset( tmpptr, '\0', 10 );
      while( ( (**it) >= '0' ) && ( (**it) <= '9' ) ) *(tmpptr++) = *((*it)++);
      if( (*tmpstr) != '\0' )
      {
        pfield->precision = atoi( tmpstr );
      }
      else
      {
        pfield->precision = 0;
      }
    }
  }

}
// ---------------------------------------------------------------------------
static void _pproc_str( _PFIELD* pfield, void* _op, va_list* _ap, int* count, int (*_outs)( char*, void* ) )
{
  char* strbuf;
  char* tmpstr;
  char* tmpptr;
  int len, buflen;

  strbuf = va_arg( (*_ap), char* );

  if( strbuf == NULL )
  {
    _outs( "(null)", _op );
    return;
  }

  buflen = ( ( pfield->precision >= 0 ) && ( pfield->precision < strlen( strbuf ) ) ) ? pfield->precision : strlen( strbuf );
  len = ( pfield->fwidth > buflen ) ? pfield->fwidth : buflen;
  (*count) += len;

  if( !( tmpstr = (char*)malloc( len + 1 ) ) ) return;
  tmpptr = tmpstr;

  if( ( buflen < len ) && !_STCHK( pfield, _PFMINUS ) )
  {
    memset( tmpptr, ' ', len - buflen );
    tmpptr += len - buflen;
  }

  strncpy( tmpptr, strbuf, buflen );
  tmpptr += buflen;

  if( ( buflen < len ) && _STCHK( pfield, _PFMINUS ) )
  {
    memset( tmpptr, ' ', len - buflen );
    tmpptr += len - buflen;
  }

  *(tmpstr+len) = '\0';

  _outs( tmpstr, _op );

  free( tmpstr );
}
// ---------------------------------------------------------------------------
static char* _setfield( _PFIELD* pfield, va_list* _ap )
{
  static char fld[_ARSIZE];

  char* f_start = (char*)fld;
  char* f_end = f_start + pfield->fwidth;
  char* a_end = f_start + _ARSIZE - 1;
  char* a_it = a_end;
  char* where;
  int minus_flag = 0;
  int plus_flag = 0;

  memset( fld, ' ', _ARSIZE );
  *(a_it--) = '\0'; 

  switch( pfield->conv )
  {
    case 'd':
    case 'i':
    case 'o':
    case 'u':
    case 'x':
    case 'X':  
    case 'p':
      _pproc_diouxp( pfield, &minus_flag, &a_it, _ap );
      break;  

    case 'g':  
    case 'G': 
    case 'e':
    case 'E':
    case 'f':
      _pproc_fge( pfield, &minus_flag, &a_it, _ap );
      break;

    case 'c':
      *(a_it--) = va_arg( (*_ap), int );
      _UNSET( pfield, _PFPLUS );
      break;

    case '%':
      strcpy( f_start, "%" );
      return( (char*)fld );
  }

  plus_flag = ( _STCHK( pfield, _PFPLUS ) && SIGNED_CONV );

  if( minus_flag ) *(a_it--) = '-'; else if( plus_flag ) *(a_it--) = '+';
  if( !minus_flag && !plus_flag && _STCHK( pfield, _PFSPACE ) ) *(a_it--) = ' ';

  where = ( _STCHK( pfield, _PFMINUS ) ||
          ( ( a_end - a_it ) > pfield->fwidth ) ) ? f_start : ( f_end - ( a_end - a_it ) + 1 );

  a_it = (char*)memccpy( where, a_it + 1, '\0', _ARSIZE );

  if( a_it <= f_end )
  {
    memset( a_it - 1, ' ', f_end - a_it + 1 );
    (*f_end) = '\0';
  }

  if( _STCHK( pfield, _PFZERO ) )
  {
    memset( f_start, '0', where - f_start );

    if( ( minus_flag || plus_flag || _STCHK( pfield, _PFSPACE ) ) && ( where != f_start ) )
    {
      (*f_start) = (*where);
      (*where) = '0';
    }
  }
  else
  {
    memset( f_start, ' ', where - f_start );
  }

  return (char*)fld;
}
// ---------------------------------------------------------------------------
static void _pproc_fge( _PFIELD* pfield, int* minus_flag, char** a_it, va_list* _ap )
{
  long double cvt =  0;

  switch( _STCHK( pfield, _MFLD ) )
  {
    case 0:
      cvt = (double)va_arg( (*_ap), double );
      break;

    default:
      cvt = va_arg( (*_ap), long double );
  }

  if( ( (*minus_flag) = ( cvt < 0 ) ) != 0 ) cvt = -cvt;

  switch( pfield->conv )
  {
    case 'f':
      _pconv_f( cvt, pfield, a_it );
      break;
   
    case 'e':
    case 'E':
      _pconv_e( cvt, pfield, a_it );
      break;

    case 'g' :
    case 'G' :
      _pconv_g( cvt, pfield, a_it );
      break;
  }
}
// ---------------------------------------------------------------------------
static void _pconv_f( long double cvt, _PFIELD* pfield, char** a_it )
{
  char tmpbuf[400];
  char* frac_ptr;
  int dpt, sign, putdec;
  if( pfield->precision < 0 ) pfield->precision = 6;
  strcpy( tmpbuf, fcvt( cvt, pfield->precision, &dpt, &sign ) );
  frac_ptr = (*a_it);
  _fcpy( tmpbuf, dpt, 1, pfield->precision, a_it );
  putdec = ( ( frac_ptr != (*a_it) ) || _STCHK( pfield, _PFPOUND ) );
  _mcpy( tmpbuf, dpt, putdec, a_it );
}
// ---------------------------------------------------------------------------
static void _pconv_e( long double cvt, _PFIELD* pfield, char** a_it )
{
  char tmpbuf[100];
  int dpt, sign, putdec;
  int exp = 0;

  if( pfield->precision < 0 ) pfield->precision = 6;

  if( cvt >= HUGE_VALL ) cvt = HUGE_VALL;
  else if( cvt <= -HUGE_VALL ) cvt = -HUGE_VALL;

  if( cvt )
  {
    for( ; cvt < 1; cvt *= 10, exp-- );
    for( ; cvt >= 10; cvt /= 10, exp++ );
  }

  strcpy( tmpbuf, fcvt( cvt, pfield->precision, &dpt, &sign ) );
  if( dpt == 2 )
  {
    dpt--;
    exp++;
    tmpbuf[strlen(tmpbuf)-1] = 0;
  }
  _ecpy( exp, pfield->conv, a_it );
  _fcpy( tmpbuf, dpt, 1, pfield->precision, a_it );
  putdec = ( ( dpt != strlen( tmpbuf ) ) || _STCHK( pfield, _PFPOUND ) ) ? 1 : 0;
  _mcpy( tmpbuf, dpt, putdec, a_it );
}
// ---------------------------------------------------------------------------
static void _pconv_g( long double cvt, _PFIELD* pfield, char** a_it )
{
  char tmpbuf[100];
  char* check;
  int dpt, sign, putdec;
  int exp = 0;
  int change_test = 0;

  if( pfield->precision == 0 ) pfield->precision = 1;
  if( pfield->precision < 0 ) pfield->precision = 6;

  strcpy( tmpbuf, ecvt( cvt, pfield->precision, &dpt, &sign ) );

  if( ( dpt < -3 ) || ( dpt > pfield->precision ) )
  {
    for( ; dpt > 1; dpt--, exp++ );
    for( ; dpt < 1; dpt++, exp-- );
    _ecpy( exp, pfield->conv - 2, a_it );
  }

  check = (*a_it);
  _fcpy( tmpbuf, dpt, ( _STCHK( pfield, _PFPOUND ) ) ? 1 : 0, pfield->precision, a_it );
  change_test = ( check != (*a_it) );
  putdec = ( _STCHK( pfield, _PFPOUND ) || change_test ) ? 1 : 0;
  _mcpy( tmpbuf, dpt, putdec, a_it );
}
// ---------------------------------------------------------------------------
static char* _fcpy( const char* tmpbuf, int dpt, int trail, int precision, char** a_it )
{
  int i;
  char *tmpptr = (char*)tmpbuf + strlen( tmpbuf ) - 1;

  for( i = 0; ( i < precision ) && ( dpt > strlen( tmpbuf ) ) && trail; i++ ) *((*a_it)--) = '0';

  if( ( dpt < strlen( tmpbuf ) ) && ( dpt >= 0 ) )
  {
    i = strlen( tmpbuf ) - dpt;
    if( !trail ) for( ; ( i > 0 ) && ( (*tmpptr) == '0' ); tmpptr--, i-- );
    for( ; i > 0; tmpptr--, i-- ) *((*a_it)--) = (*tmpptr);
  }

  if( dpt < 0 )
  {
    if( -dpt < precision ) for( i = strlen( tmpbuf ); i > 0; tmpptr--, i--) *((*a_it)--) = (*tmpptr);
    if( -dpt > precision ) dpt = -precision;
    for( i = -dpt; i > 0; i-- ) *((*a_it)--) = '0';
  }

  return (*a_it);
}
// ---------------------------------------------------------------------------
static char* _ecpy( int exp, char letter, char** a_it )
{
  _ltostr( ( exp > 0 ) ? exp : -exp, 10, 'd', a_it );
  if( ( exp < 10 ) && ( exp > -10 ) ) *((*a_it)--) = '0';
  *((*a_it)--) = ( exp < 0 ) ? '-' : '+';
  *((*a_it)--) = letter;
  return (*a_it);
}
// ---------------------------------------------------------------------------
static char* _mcpy( const char* tmpbuf, int dpt, int putdec, char** a_it )
{
  int i;
  char* tmpptr = NULL;
  if( ( dpt > 0 ) && ( dpt <= strlen( tmpbuf ) ) ) tmpptr = (char*)tmpbuf + dpt -1;
  if( putdec ) *((*a_it)--) = '.';
  for( i = dpt; i > strlen( tmpbuf); i-- ) *((*a_it)--) = '0';
  if( i > 0 ) for( ; tmpptr >= tmpbuf; tmpptr-- ) *((*a_it)--) = (*tmpptr); else *((*a_it)--) = '0';
  return (*a_it);
}
// ---------------------------------------------------------------------------
static int _pproc_diouxp( _PFIELD* pfield, int* minus_flag, char** a_it, va_list* _ap )
{
  int digits = 0;
  int base = 10;
  uintmax_t cvt;

  if( pfield->precision < 0 ) pfield->precision = 1; else _UNSET( pfield, _PFZERO );

  switch( pfield->conv )
  {
    case 'p':
    case 'x':
    case 'X':
      base = 16;
      break;

    case 'o':
      base = 8;
      break;

    default:
    case 'u':
    case 'd':
    case 'i':
      base = 10;
      break;
  }  

  cvt = _getarg_diouxp( pfield, _ap );

  if( ( pfield->precision == 0 ) && ( cvt == 0 ) ) return 1;

  if( ( ( pfield->conv == 'd' ) || ( pfield->conv == 'i' ) ) && ( (intmax_t)cvt < 0 ) )
  {
    (*minus_flag) = 1;
    cvt = -(intmax_t)cvt;
  }

  digits += _ltostr( cvt, base, pfield->conv, a_it );
  while( digits++ < pfield->precision ) *((*a_it)--) = '0';

  if( ( ( pfield->conv == 'x' ) || ( pfield->conv == 'X' ) ) && _STCHK( pfield, _PFPOUND ) )
  {
    *((*a_it)--) = pfield->conv;
    *((*a_it)--) = '0';
  }

  if( ( pfield->conv == 'o' ) && _STCHK( pfield, _PFPOUND ) ) *((*a_it)--) = '0';

  return 0;
}
// ---------------------------------------------------------------------------
static uintmax_t _getarg_diouxp( _PFIELD* pfield, va_list* _ap )
{
  uintmax_t cvt = 0;

  if( pfield->conv == 'p' )
  {
    cvt = (uintmax_t)va_arg( (*_ap), void* );
  }
  else
  {
    switch( _STCHK( pfield, ( _MFH | _MFL | _MFLL ) ) )
    {
      case _MFH:
      {
        switch( pfield->conv )
        {
          case 'd':
          case 'i':
            cvt = va_arg( (*_ap), int );
            break;

          case 'o':
          case 'u':
          case 'x':
          case 'X':
            cvt = (unsigned short)va_arg( (*_ap), unsigned int );
        }
      }
      break;
  
      case _MFL:
      {
        switch( pfield->conv )
        {
          case 'd':
          case 'i':
            cvt = va_arg(*_ap, long int);
            break;
  
          case 'o':
          case 'u':
          case 'x':
          case 'X':
            cvt = va_arg( (*_ap), unsigned long int );
        }
      }
      break;
  
      case _MFLL:
      {
        switch( pfield->conv )
        {
          case 'd':
          case 'i':
            cvt = va_arg( (*_ap), long long int );
            break;

          case 'o':
          case 'u':
          case 'x':
          case 'X':
            cvt = va_arg( (*_ap), unsigned long long int );
        }
      }
      break;
  
      default:
      {
        switch( pfield->conv )
        {
          case 'd':
          case 'i':
            cvt = va_arg( (*_ap), int );
            break;
  
          case 'o':
          case 'u':
          case 'x':
          case 'X':
            cvt = va_arg( (*_ap), unsigned int );
        }
      }
      break;
    }
  }
 
  return cvt;
}
// ---------------------------------------------------------------------------
static int _ltostr( uintmax_t cvt, int base, char conv, char** a_it )
{
  uintmax_t quot, rem;
  char *bnum = "0123456789abcdef0123456789ABCDEF";

  if( !cvt ) *((*a_it)--) = '0';

  while( cvt )
  {
    quot = _div( cvt, base );
    rem = cvt - quot * base;
    if( conv == 'X' ) rem += 16;
    *((*a_it)--) = bnum[rem];
    cvt = quot;
  }

  return ( strlen( (*a_it) ) - 1 );
}
// ---------------------------------------------------------------------------
static uintmax_t _div( uintmax_t cvt, int base )
{
  switch( base )
  {
    case 8: return cvt >> 3;
    case 16: return cvt >> 4;
  }
  if( cvt < UINT_MAX ) return (unsigned int)cvt / base;
  else if( cvt < ULONG_MAX ) return (unsigned long)cvt / base;
  else return cvt / base;
}
// ---------------------------------------------------------------------------
