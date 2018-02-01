// ---------------------------------------------------------------------------
// int _scanfi( void* inp, const char* _format, va_list _ap, int (*_chkmbc)( void**, char**, int* ), int (*_inpchar)( void** ), void (*_uninpchar)( void**, char ) )
// ---------------------------------------------------------------------------
#include <stdarg.h>
#include <rts.h>
// ---------------------------------------------------------------------------

struct _SFIELD
{
  unsigned int flags;
  int fwidth;
  int precision;
  char scanset[96];
  char conv;
};

#define _SET(_fp, _b)           (((_fp)->flags) |= (_b))
#define _STCHK(_fp, _b)         (((_fp)->flags) & (_b))

#define _SFSTAR                 0x01
#define _SFCIRC                 0x02

#define _MFH                    0x20
#define _MFL                    0x40
#define _MFLD                   0x80
#define _MFLL                   0x100
#define _MFHH                   0x200

// ---------------------------------------------------------------------------
static void _sset_arg( _SFIELD* sfield, va_list* _ap, char* tmpbuf )
{
  int base;

  if( ( tmpbuf[0] != '\0' ) && !_STCHK( sfield, _SFSTAR ) )
  {
    switch( sfield->conv )
    {
      case 'i':
      case 'd':
      {
        base = ( sfield->conv == 'd' ) ? 10 : 0;
  
        switch( _STCHK( sfield, ( _MFH | _MFHH | _MFL | _MFLL ) ) )
        {
          case _MFH:
          {
            (*(va_arg( *_ap, short int* ))) = (short int)strtol( tmpbuf, NULL, base );
          }
          break;

          case _MFHH:
          {
            (*(va_arg( *_ap, char* ))) = (char)strtol( tmpbuf, NULL, base );
          }
          break;

          case _MFL:
          {
            (*(va_arg( *_ap, long int* ))) = strtol( tmpbuf, NULL, base );
          }
          break;
          
          case _MFLL:
          {
            (*(va_arg( *_ap, long long int* ))) = strtoll( tmpbuf, NULL, base );
          }
          break;
          
          default:
          {
            (*(va_arg( *_ap, int* ))) = (int)strtol( tmpbuf, NULL, base );
          }
          break;
        }
      }
      break;

      case 'p':
      {
        (*(va_arg( *_ap, void** ))) = (void*)(unsigned int)strtoul( tmpbuf, NULL, 16 );
      }
      break;

      case 'x':
      case 'u':
      case 'o':
      {
        base = ( sfield->conv == 'u' ) ? 10 : ( ( sfield->conv == 'x' ) ? 16 : 8 );

        switch( _STCHK( sfield, ( _MFH | _MFHH | _MFL | _MFLL ) ) )
        {
          case _MFH:
          {
            (*(va_arg( *_ap, unsigned short int* ))) = (unsigned short int)strtoul( tmpbuf, NULL, base );
          }
          break;

          case _MFHH:
          {
            (*(va_arg( *_ap, unsigned char* ))) = (unsigned char)strtoul( tmpbuf, NULL, base );
          }
          break;

          case _MFL:
          {
            (*(va_arg( *_ap, unsigned long int* ))) = strtoul( tmpbuf, NULL, base );
          }
          break;
          
          case _MFLL:
          {
            (*(va_arg( *_ap, unsigned long long int* ))) = strtoull( tmpbuf, NULL, base );
          }
          break;
          
          default:
          {
            (*(va_arg( *_ap, unsigned int* ))) = (unsigned int)strtoul( tmpbuf, NULL, base );
          }
          break;
        }
      }
      break;

      case 'e':
      case 'f':
      case 'g':
      case 'E':
      case 'G':
      {
        switch( _STCHK( sfield, ( _MFL | _MFLD ) ) )
        {
          case _MFL:
          {
            (*(va_arg( *_ap, double* ))) = strtod( tmpbuf, NULL );
          }
          break;

          case _MFLD:
          {
            (*(va_arg(*_ap, long double* ))) = strtold( tmpbuf, NULL );
          }
          break;

          default:
          {
            (*(va_arg( *_ap, float* ))) = (float)strtod( tmpbuf, NULL );
          }
          break;
        }
      }
      break;
    }
  }
}
// ---------------------------------------------------------------------------
static int _sproc_lb( int (*_inpchar)( void** ), void (*_uninpchar)( void**, char ), char* tmpptr, _SFIELD* sfield, void** inp, int* num_read )
{
  signed char inchar;
  int bnum_read = (*num_read);
  int w_counter = sfield->fwidth;
  int test;

  inchar = _inpchar( inp );
  (*num_read)++;

  for( ; ( w_counter != 0 ) && ( inchar != EOF ); w_counter-- )
  {
    test = ( strrchr( sfield->scanset, inchar ) != NULL );
    if( _STCHK( sfield, _SFCIRC ) ) test = !test;

    if( test )
    {
      *(tmpptr++) = inchar;
      inchar = _inpchar( inp );
      (*num_read)++;
    }
    else
    {
      _uninpchar( inp, inchar );
      (*num_read)--;
      break;
    }
  }

  (*tmpptr) = '\0';

  if( bnum_read == (*num_read) ) return EOF;

  return 1;
}
// ---------------------------------------------------------------------------
static int _sproc_str( int w_counter, int (*_inpchar)( void** ), void (*_uninpchar)( void**, char ), char* tmpptr, char conv, void** inp, int* num_read )
{
  signed char inchar;
  int bnum_read = (*num_read);

  if( ( conv == 'c' ) && ( w_counter < 0 ) ) w_counter = 1;

  inchar = _inpchar( inp );
  (*num_read)++;

  while( ( ( conv == 'c' ) || !isspace( inchar ) ) && ( inchar != '\0' ) && ( inchar != EOF ) && w_counter-- )
  { 
    if( tmpptr ) *(tmpptr++) = inchar;
    inchar = _inpchar( inp);
    (*num_read)++;
  }
  
  if( ( conv == 's' ) && tmpptr ) (*tmpptr) = '\0';

  _uninpchar( inp, inchar );
  (*num_read)--;

  if( bnum_read == (*num_read) ) return EOF;

  return 1;
}
// ---------------------------------------------------------------------------
static int _sproc_float( int w_counter, int (*_inpchar)( void** ), void (*_uninpchar)( void**, char ), char* tmpptr, char conv, void** inp, int* num_read )
{
  signed char inchar;
  int invalid = 0;
  int bnum_read = (*num_read);
  int dec_flag = 0;
  int e_flag = 0;

  inchar = _inpchar( inp );
  (*num_read)++;

  if( ( ( inchar == '+' ) || ( inchar == '-' ) ) && ( w_counter != 0 ) )
  {
    *(tmpptr++) = inchar;
    inchar = _inpchar( inp );
    (*num_read)++;
    w_counter--;
  }

  while( ( ( inchar >= '0' ) && ( inchar <= '9' ) ) || ( inchar == '.' ) || ( inchar == 'e' ) || ( inchar == 'E' ) || ( inchar == '+' ) || ( inchar == '-' ) )
  {
    switch( inchar )
    {
       case '.':
       {
         if( dec_flag || e_flag )
         {
           invalid = 1;
           break;
         } 
         else
         {
           dec_flag = 1;
         }
       }
       break;

       case 'e':
       case 'E':
       {
         if( e_flag )
         {
           invalid = 1;
           break;
         }
         else
         {
           e_flag = 1;
         }
       }
       break;

       case '+':  
       case '-':
       {
         if( ( (*(tmpptr-1)) != 'E' ) && ( (*(tmpptr-1)) != 'e' ) )
         {
           invalid = 1;
           break;
         }
       }
       break;
    }

    if( invalid ) break;
    *(tmpptr++) = inchar;
    inchar = _inpchar( inp );
    if( inchar != EOF ) (*num_read)++;
    w_counter--;
  }

  _uninpchar( inp, inchar );
  if( inchar != EOF ) (*num_read)--;

  (*tmpptr) = '\0';

  if( bnum_read == (*num_read) ) return EOF;

  return 1;
}
// ---------------------------------------------------------------------------
static int _sproc_int( int w_counter, int (*_inpchar)( void** ), void (*_uninpchar)( void**, char ), char* tmpptr, char conv, void** inp, int* num_read )
{
  signed char inchar;
  int bnum_read = (*num_read);

  inchar = _inpchar( inp );
  (*num_read)++;

  if( ( ( inchar == '+' ) || ( inchar == '-' ) ) && w_counter != 0 )
  {
    *(tmpptr++) = inchar;
    inchar = _inpchar( inp );
    (*num_read)++;
    w_counter--;
  }

  if( ( ( conv == 'o' ) || ( conv == 'i' ) || ( conv =='x' ) || ( conv == 'p' ) ) && ( w_counter != 0 ) && ( inchar == '0' ) )
  {
    *(tmpptr++) = inchar;
    inchar = _inpchar( inp );
    (*num_read)++;
    w_counter--;
  }

  if( ( ( conv == 'x' ) || ( conv == 'p' ) || ( conv == 'i' ) ) && ( w_counter != 0 ) && ( ( inchar == 'x' ) || ( inchar == 'X' ) ) )
  {
    *(tmpptr++) = inchar;
    inchar = _inpchar( inp );
    (*num_read)++;
    w_counter--;
  }

  while( ( ( ( inchar >= '0' ) && ( inchar <= '9' ) ) || 
         ( ( ( conv == 'x' ) || ( conv == 'p' ) || ( conv == 'i' ) ) &&
           ( ( ( inchar >= 'A' ) && ( inchar <= 'F' ) ) ||
             ( ( inchar >= 'a' ) && ( inchar <= 'f' ) ) ) ) ) && ( w_counter != 0 ) )
  {
    *(tmpptr++) = inchar;
    inchar = _inpchar( inp );
    (*num_read)++;
    w_counter--;
  }

  _uninpchar( inp, inchar );
  (*num_read)--;

  (*tmpptr) = '\0';

  if( bnum_read == (*num_read) ) return EOF;

  return 1;
}
// ---------------------------------------------------------------------------
static int _sget_scanset( _SFIELD* sfield, char** _format )
{
  char* tmpptr = sfield->scanset;

  if( (**_format) == '^' )
  {
    _SET( sfield, _SFCIRC );
    (*_format)++;
  }

  if( (**_format) == ']' ) *(tmpptr++) = *((*_format)++);

  while( ( (**_format) != ']' ) && ( (**_format) != '\0' ) ) *(tmpptr++) = *((*_format)++);

  (*tmpptr) = '\0';
  if( (**_format) == ']' ) (*_format)++;
  if( (**_format) == '\0' ) return EOF;

  return 0;
}
// ---------------------------------------------------------------------------
static int _sget_conv( char** _format, _SFIELD* sfield )
{
  char tmpbuf[8], * tmpptr = tmpbuf, * strend = (*_format) + strlen(*_format);

  (*_format)++;

  if( (**_format) == '*' )
  {
    _SET( sfield, _SFSTAR );
    (*_format)++;
  }

  for( ; ( (**_format) >= '0' ) && ( (**_format) <= '9' ); *(tmpptr++) = *((*_format)++) );
  (*tmpptr) = '\0';

  if( strlen( tmpbuf ) ) sfield->fwidth = atoi( tmpbuf );

  switch( (**_format) )
  {
    case 'L':
    {
      _SET( sfield, _MFLD );
      (*_format)++;
    }
    break;

    case 'h':
    {
      (*_format)++;
      if( (**_format) == 'h' )
      {
        _SET( sfield, _MFHH );
        (*_format)++;
      }
      else
      {
        _SET( sfield, _MFH );
      }
    }
    break;

    case 'l': 
    {
      (*_format)++;
      if( (**_format) == 'l' )
      {
        _SET( sfield, _MFLL );
        (*_format)++;
      }
      else
      {
        _SET( sfield, _MFL );
      }
    }
    break;
  }

  sfield->conv = *((*_format)++);

  if( ( sfield->conv == '[' ) && _sget_scanset( sfield, _format ) ) return EOF;

  if( (*_format) > strend ) return EOF;
  
  return 0;
}
// ---------------------------------------------------------------------------
int _scanfi( void* inp, const char* _format, va_list _ap, int (*_chkmbc)( void**, char**, int* ), int (*_inpchar)( void** ), void (*_uninpchar)( void**, char ) )
{
  _SFIELD sfield;
  char tmpbuf[256], * tmpptr, * f_ptr = (char*)_format;
  int num_assigned = 0, inchar, num_read = 0, stat = 0;

  if( isspace( *f_ptr ) )
  {
    for( ; isspace( *f_ptr ); f_ptr++ );
    inchar = _inpchar( &inp );
    if( inchar == EOF ) return EOF;
    num_read++;
    for( ; isspace( inchar ); inchar = _inpchar( &inp ), num_read++ );
    _uninpchar( &inp, inchar );
    num_read--;
    if( inchar == EOF ) return EOF;
  }

  while( true )
  {
    memset( &sfield, 0, sizeof(_SFIELD) );
    sfield.fwidth = -1;

    switch( _chkmbc( &inp, &f_ptr, &num_read ) )
    {
      case EOF: return EOF;
      case 0: return num_assigned;
      case 1: _sget_conv( &f_ptr, &sfield );
    }
  
    tmpptr = tmpbuf;

    if( ( sfield.conv != '[' ) && ( sfield.conv != 'c' ) && ( sfield.conv != 'n' ) )
    {
      inchar = _inpchar( &inp );
      num_read++;
      for( ; isspace( inchar ); inchar = _inpchar( &inp ), num_read++ );
      _uninpchar( &inp, inchar );
      num_read--;
      if( ( inchar == EOF ) && ( num_read == 0 ) ) return EOF;
    }
    else
    {
      inchar = _inpchar( &inp );
      _uninpchar( &inp, inchar );
      if( ( inchar == EOF ) && ( num_read == 0 ) ) return EOF;
    }

    switch( sfield.conv )
    {
      case 'X': sfield.conv = 'x';
      case 'i':
      case 'p':  
      case 'x':
      case 'u':
      case 'o':
      case 'd':
      {
        stat = _sproc_int( sfield.fwidth, _inpchar, _uninpchar, tmpptr, sfield.conv, &inp, &num_read );
      }
      break;

      case 'f':
      case 'e':
      case 'E':
      case 'g':
      case 'G':
      {
        stat = _sproc_float( sfield.fwidth, _inpchar, _uninpchar, tmpptr, sfield.conv, &inp, &num_read );
      }
      break;

      case 'c':  
      case 's':
      {
        char* stptr = ( sfield.flags & _SFSTAR ) ? NULL : va_arg( _ap, char* );
        stat = _sproc_str( sfield.fwidth, _inpchar, _uninpchar, stptr, sfield.conv, &inp, &num_read );
        stat = ( stat != EOF );
        if( !( sfield.flags & _SFSTAR ) && stat ) num_assigned++;
      }
      break;

      case '[':
      {
        stat = _sproc_lb( _inpchar, _uninpchar, tmpptr, &sfield, &inp, &num_read );
      }
      break;
    }

    stat = ( stat != EOF );

    switch( sfield.conv )
    {
      case 'i':
      case 'd':  
      case 'x':
      case 'u':
      case 'o':  
      case 'p': 
      case 'e':
      case 'f':
      case 'g':
      case 'E':
      case 'G':
      {
        _sset_arg( &sfield, &_ap, tmpbuf );
        if( ( !( sfield.flags & _SFSTAR ) ) && stat ) num_assigned++;
      }
      break;

      case 'n': if( !( sfield.flags & _SFSTAR ) )
      {
        switch( sfield.flags & (_MFH | _MFHH | _MFL | _MFLL ) )
        {
          case _MFH:
          {
            (*(va_arg( _ap, short int* ))) = (short int)num_read;
          }
          break;

          case _MFHH:
          {
            (*(va_arg( _ap, char* ))) = (char)num_read;
          }
          break;

          case _MFL:
          {
            (*(va_arg( _ap, long int* ))) = (long int)num_read;
          }
          break;

          case _MFLL:
          {
            (*(va_arg( _ap, long long int* ))) = (long long int)num_read;
          }
          break;
                           
          default:
          {
            (*(va_arg( _ap, int* ))) = num_read;
          }
          break;
        }
      }
      break;

      case '%':
      {
        inchar = _inpchar( &inp );
        if( inchar != '%' ) return EOF; else num_read++;
      }
      break;
                           
      case '[':
      {
        if( ( !( sfield.flags & _SFSTAR ) ) && stat )
        {
          strcpy( va_arg( _ap, char* ), tmpbuf );
          num_assigned++;
        }
      }
      break;
    }
  }
}
// ---------------------------------------------------------------------------
