/**********************************************************************************************************************
*                                        (c) COPYRIGHT by ZAO RCZI FORT.                                             *
*        ..                                       All rights reserved.                                               *
***********************************************************************************************************************
* Module      : __fs_utils.cpp
* Description : 
* Author      : 
******************************************************************************
******************************************************************************
* Module's Description Record:
* ============================
* Module's revision history:
* ==========================
* --------- $Log:  $
* --------- Initial revision
******************************************************************************/


#include <__fs.h>
#include <rts.h>
// ---------------------------------------------------------------------------

void (*fs_vfat_rnd_func)( void* data, FS_UINT32 length ) = NULL;

// ---------------------------------------------------------------------------
void fsUtils::setRandFunc( void (*f)(void*,FS_UINT32) )
{
  fs_vfat_rnd_func = f;
}
// ---------------------------------------------------------------------------
void fsUtils::rnd( void* data, FS_UINT32 length )
{
  if( fs_vfat_rnd_func == NULL )
  {
    memset( data, 0, length );
  }
  else
  {
    fs_vfat_rnd_func( data, length );
  }
}
// ---------------------------------------------------------------------------
FS_CHAR fsUtils::upCase( FS_CHAR ch )
{
  if( ( ch >= 0x61 ) && ( ch <= 0x7a ) ) return ( ch ^ 0x20 );
  if( ch >= 0xe0 ) return ( ch ^ 0x20 );
  return ch;
}
// ---------------------------------------------------------------------------
FS_BOOL fsUtils::cmpL( FS_CHAR* str1, FS_CHAR* str2, FS_UINT16 length )
{
  FS_UINT16 i, stl1, stl2;
  stl1 = strlen( str1 );
  stl2 = strlen( str2 );
  if( ( stl1 < length ) || ( stl2 < length ) ) return FS_FALSE;
  for( i = 0; i < length; i++ ) if( str1[i] != str2[i] ) return FS_FALSE;
  return FS_TRUE;
}
// ---------------------------------------------------------------------------
FS_BOOL fsUtils::upCaseCmp( FS_CHAR* str1, FS_CHAR* str2 )
{
  FS_INT16 i;
  FS_INT16 stl1 = strlen( str1 );
  if( stl1 != strlen( str2 ) ) return FS_FALSE;
  for( i = 0; i < stl1; i++ ) if( upCase( str1[i] ) != upCase( str2[i] ) ) return FS_FALSE;
  return FS_TRUE;
}
// ---------------------------------------------------------------------------
FS_BOOL fsUtils::upCaseMaskCmp( FS_CHAR* mask, FS_CHAR* str )
{
  FS_INT32 lmask, lstr, i, str_addr;
  lmask = strlen( mask );
  lstr = strlen( str );
  str_addr = 0;
  for( i = 0; ( i < lmask ) && ( str_addr < lstr ); i++ )
  {
    switch( mask[i] )
    {
      case '?':
      {
        str_addr++;
      }
      break;
      case '*':
      {
        if( (++i) == lmask ) return FS_TRUE;
        if( ( mask[i] == '?' ) || ( mask[i] == '*' ) ) str_addr--;
        while( FS_TRUE )
        {
          if( str_addr >= lstr ) return FS_FALSE;
          if( upCase( mask[i] ) == upCase( str[++str_addr] ) ) { str_addr++; break; }
        }
      }
      break;
      default:
      {
        if( upCase( mask[i] ) != upCase( str[str_addr] ) ) return FS_FALSE;
        str_addr++;
      }
      break;
    }
  }
  if( ( i != lmask ) || ( str_addr != lstr ) ) return FS_FALSE;
  return FS_TRUE;
}
// ---------------------------------------------------------------------------
FS_BOOL fsUtils::maskCmp( FS_CHAR* mask, FS_CHAR* str )
{
  FS_INT16 lmask, lstr, i, str_addr;
  lmask = strlen( mask );
  lstr = strlen( str );
  str_addr = 0;
  for( i = 0; ( i < lmask ) && ( str_addr < lstr ); i++ )
  {
    switch( mask[i] )
    {
      case '?':
      {
        str_addr++;
      }
      break;
      case '*':
      {
        if( (++i) == lmask ) return FS_TRUE;
        if( (mask[i] == '?' ) || ( mask[i] == '*' ) ) str_addr--;
        while( FS_TRUE )
        {
          if( str_addr >= lstr ) return FS_FALSE;
          if( mask[i] == str[++str_addr] ) { str_addr++; break; }
        }
      }
      break;
      default:
      {
        if( mask[i] != str[str_addr] ) return FS_FALSE;
        str_addr++;
      }
      break;
    }
  }
  if( ( i != lmask ) || ( str_addr != lstr ) ) return FS_FALSE;
  return FS_TRUE;
}
// ---------------------------------------------------------------------------
FS_BOOL fsUtils::maskCmpEndChar( FS_CHAR* mask, FS_CHAR* str, FS_CHAR endChar )
{
  FS_INT16 p, stl;
  FS_BOOL res;
  stl = strlen( str );
  for( p = 0; p < stl; p++ ) if( str[p] == endChar ) break;
  if( p == stl ) endChar = 0;
  str[p] = 0;
  res = maskCmp( mask, str );
  str[p] = endChar;
  return res;
}
// ---------------------------------------------------------------------------
FS_UINT16 fsUtils::findChar( FS_CHAR* str, FS_CHAR ch )
{
  FS_UINT16 i, stl, res;
  stl = strlen( str );
  for( i = 0; i < stl; i++ ) if( str[i] == ch ) { res = i; break; }
  if( i == stl ) res = 0xffff;
  return res;
}
// ---------------------------------------------------------------------------
FS_UINT32 fsUtils::crc32( FS_CHAR* str )
{
  FS_UINT32 res;
  FS_UINT16 i, j, stl = strlen( str );
  FS_UINT32 hiBit;
  for( res = 0, i = 0; i < stl; i++ )
  {
    res ^= (FS_UINT32) str[i] << 24;
    for( j = 0; j < 8; j++ )
    {
      hiBit = res & 0x80000000;
      res <<= 1;
      if( hiBit ) res ^= 0x04c11db7;
    }
  }
  return res;
}
// ---------------------------------------------------------------------------
FS_BOOL fsUtils::aGb( FS_CHAR* a, FS_CHAR* b )
{
  FS_UINT16 stl_a;
  FS_UINT16 stl_b;
  if( a == NULL ) stl_a = 0; else stl_a = strlen( a );
  if( b == NULL ) stl_b = 0; else stl_b = strlen( b );
  FS_UINT16 stl_min = ( stl_a < stl_b ) ? stl_a : stl_b;
  for( FS_UINT16 i = 0; i < stl_min; i++ )
  {
    if( a[i] == b[i] ) continue;
    if( a[i] > b[i] ) return FS_TRUE; else return FS_FALSE;
  }
  if( stl_a <= stl_b ) return FS_FALSE;
  return FS_TRUE;
}
// ---------------------------------------------------------------------------
FS_UINT32 fsUtils::fsMod( FS_UINT32 a, FS_UINT32 b )
{
  return a - ( a / b ) * b;
}
// ---------------------------------------------------------------------------
void fsUtils::timeDos2Unix( FS_UINT16 ymd, FS_UINT16 hms, FS_UINT32* tunix )
{
  FS_UINT32 tst_month, tst_year, tst_day, tst_hour, tst_min, tst_sec;
  FS_UINT32 century, xyear, month, date, year;
  FS_UINT32 dayspast;
  tst_year = 1980 + ( ymd >> 9 );
  tst_month = ( ymd >> 5 ) & 0x000f;
  if( tst_month == 0 ) tst_month = 1;
  tst_day = ymd & 0x001f;
  if( tst_day == 0 ) tst_day = 1;
  tst_hour = hms >> 11;
  tst_min = ( hms >> 5 ) & 0x003f;
  tst_sec = ( hms & 0x001f ) << 1;
  month = tst_month;
  year = tst_year;
  if( month <= 2 ) { year--; month += 12; }
  month -= 3;
  century = year / 100;
  xyear = fsMod( year, 100 );
  century = ( century * 146097 ) >> 2;
  xyear = ( xyear * 1461 ) >> 2;
  date = ( month * 153 + 2 ) / 5 + tst_day + 1721119 + xyear + century;
  dayspast = date - 2440588;
  (*tunix) = dayspast * 86400;
  (*tunix) += tst_hour * 3600 + tst_min * 60 + tst_sec;
}
// ---------------------------------------------------------------------------
void fsUtils::timeUnix2Dos( FS_UINT32 tunix, FS_UINT16* ymd, FS_UINT16* hms )
{
  FS_UINT32 date, time, temp;
  FS_UINT32 xyear, yyear, ymonth, yday;
  FS_UINT32 tst_month, tst_year, tst_day, tst_hour, tst_min, tst_sec;
  date = tunix / 86400 + 2440588;
  time = fsMod( tunix, 86400 );
  temp = ( ( date - 1721119 ) << 2 ) - 1;
  xyear = fsMod( temp, 146097 ) | 3;
  date = temp / 146097;
  yyear = xyear / 1461;
  temp = ( ( fsMod( xyear, 1461 ) + 4 ) >> 2 ) * 5 - 3;
  ymonth = temp / 153;
  if( ymonth >= 10 ) { yyear++; ymonth -= 12; }
  tst_month = ymonth + 3;
  yday = fsMod( temp, 153 );
  tst_day = ( yday + 5 ) / 5;
  tst_year = yyear + ( date * 100 );
  tst_hour = time / 3600;
  time = fsMod( time, 3600 );
  tst_min = time / 60;
  tst_sec = fsMod( time, 60 );
  (*hms) = ( tst_sec >> 1 ) + ( tst_min << 5 ) + ( tst_hour << 11 );
  (*ymd) = tst_day + ( tst_month << 5 ) + ( ( tst_year - 1980 ) << 9 );
}
// ---------------------------------------------------------------------------
const unsigned short int unicode_up[128] =
{
  0x0402, 0x0403, 0x201A, 0x0453, 0x201E, 0x2026, 0x2020, 0x2021,
  0x0000, 0x2030, 0x0409, 0x2039, 0x040A, 0x040C, 0x040B, 0x040F,
  0x0452, 0x2018, 0x2019, 0x201C, 0x201D, 0x2022, 0x2013, 0x2014,
  0x0000, 0x2122, 0x0459, 0x203A, 0x045A, 0x045C, 0x045B, 0x045F,
  0x00A0, 0x040E, 0x045E, 0x0408, 0x00A4, 0x0490, 0x00A6, 0x00A7,
  0x0401, 0x00A9, 0x0404, 0x00AB, 0x00AC, 0x00AD, 0x00AE, 0x0407,
  0x00B0, 0x00B1, 0x0406, 0x0456, 0x0491, 0x00B5, 0x00B6, 0x00B7,
  0x0451, 0x2116, 0x0454, 0x00BB, 0x0458, 0x0405, 0x0455, 0x0457,
  0x0410, 0x0411, 0x0412, 0x0413, 0x0414, 0x0415, 0x0416, 0x0417,
  0x0418, 0x0419, 0x041A, 0x041B, 0x041C, 0x041D, 0x041E, 0x041F,
  0x0420, 0x0421, 0x0422, 0x0423, 0x0424, 0x0425, 0x0426, 0x0427,
  0x0428, 0x0429, 0x042A, 0x042B, 0x042C, 0x042D, 0x042E, 0x042F,
  0x0430, 0x0431, 0x0432, 0x0433, 0x0434, 0x0435, 0x0436, 0x0437,
  0x0438, 0x0439, 0x043A, 0x043B, 0x043C, 0x043D, 0x043E, 0x043F,
  0x0440, 0x0441, 0x0442, 0x0443, 0x0444, 0x0445, 0x0446, 0x0447,
  0x0448, 0x0449, 0x044A, 0x044B, 0x044C, 0x044D, 0x044E, 0x044F
};
// ---------------------------------------------------------------------------
const unsigned char koi8r_up[32] =
{
  225, 226, 247, 231, 228, 229, 246, 250,
  233, 234, 235, 236, 237, 238, 239, 240,
  242, 243, 244, 245, 230, 232, 227, 254,
  251, 253, 255, 249, 248, 252, 224, 241
};
// ---------------------------------------------------------------------------
const unsigned char koi8r_down[32] =
{
  193, 194, 215, 199, 196, 197, 214, 218,
  201, 202, 203, 204, 205, 206, 207, 208,
  210, 211, 212, 213, 198, 200, 195, 222,
  219, 221, 223, 217, 216, 220, 192, 209
};
// ---------------------------------------------------------------------------
unsigned short int cp1251_to_unicode( unsigned char c )
{
  c &= 0xff;
  if( c < 128 ) return (unsigned short int)c;
  return unicode_up[c-128];
}
// ---------------------------------------------------------------------------
unsigned char unicode_to_cp1251( unsigned short int c )
{
  unsigned short int i;
  if( c < 128 ) return (unsigned char)c & 0x00ff;
  for( i = 0; i < 128; i++ ) if( unicode_up[i] == c ) break;
  if( i == 128 )
  {
    if( c == 0x0200 ) return 0;
    else return '?';
  }
  return (unsigned char)( i + 128 );
}
// ---------------------------------------------------------------------------
unsigned char cp1251_to_cp866( unsigned char c )
{
  c &= 0xff;
  if( c < 128 ) return c;
  if( ( c >= 0xc0 ) && ( c <= 0xdf ) ) return ( c - 0x40 );
  if( ( c >= 0xe0 ) && ( c <= 0xef ) ) return ( c - 0x40 );
  if( ( c >= 0xf0 ) && ( c <= 0xff ) ) return ( c - 0x10 );
  if( c == 0xb8 ) return 0xf1;
  if( c == 0xa8 ) return 0xf0;
  return c;
}
// ---------------------------------------------------------------------------
unsigned char cp866_to_cp1251( unsigned char c )
{
  c &= 0xff;
  if( c < 128 ) return c;
  if( ( c >= 0x80 ) && ( c <= 0x9f ) ) return ( c + 0x40 );
  if( ( c >= 0xa0 ) && ( c <= 0xaf ) ) return ( c + 0x40 );
  if( ( c >= 0xe0 ) && ( c <= 0xef ) ) return ( c + 0x10 );
  if( c == 0xf1 ) return 0xb8;
  if( c == 0xf0 ) return 0xa8;
  return c;
}
// ---------------------------------------------------------------------------
unsigned char cp1251_to_koi8r( unsigned char c )
{
  c &= 0xff;
  if( c < 128 ) return c;
  if( ( c >= 192 ) && ( c <= 223 ) ) return koi8r_up[c-192];
  if( ( c >= 224 ) && ( c <= 255 ) ) return koi8r_down[c-224];
  if( c == 168 ) return 179;
  if( c == 184 ) return 163;
  if( c == 185 ) return 191;
  return '?';
}
// ---------------------------------------------------------------------------
unsigned char koi8r_to_cp1251( unsigned char c )
{
  c &= 0xff;
  if( c < 128 ) return c;
  for( int i = 0; i < 32; i++ )
  {
    if( koi8r_up[i] == c ) return ( i + 192 );
    if( koi8r_down[i] == c ) return ( i + 224 );
  }
  if( c == 179 ) return 168;
  if( c == 163 ) return 184;
  if( c == 191 ) return 185;
  return '?';
}
// ---------------------------------------------------------------------------
unsigned char koi8r_to_cp866( unsigned char c )
{
  return cp1251_to_cp866( koi8r_to_cp1251( c ) );
}
// ---------------------------------------------------------------------------
unsigned char cp866_to_koi8r( unsigned char c )
{
  return cp1251_to_koi8r( cp866_to_cp1251( c ) );
}
// ---------------------------------------------------------------------------
void chs_recode( char* str, int from_chs, int to_chs )
{
  chs_mem_recode( str, strlen( str ), from_chs, to_chs );
}
// ---------------------------------------------------------------------------
void chs_mem_recode( void* vbuf, int len, unsigned short int from_chs, unsigned short int to_chs )
{
  int i;
  unsigned char* buf = (unsigned char*)vbuf;
  
  if( buf == NULL ) return;
  if( ( from_chs == CHS_NONE ) || ( to_chs == CHS_NONE ) || ( from_chs == to_chs ) ) return;
  if( ( from_chs == CHS_RU_UNICODE ) || ( to_chs == CHS_RU_UNICODE ) ) return;

  switch( from_chs )
  {
    case CHS_CP1251:
    {
      switch( to_chs )
      {
        case CHS_CP866:
        {
          for( i = 0; i < len; i++ ) buf[i] = cp1251_to_cp866( buf[i] );
        }
        break;
        case CHS_KOI8R:
        {
          for( i = 0; i < len; i++ ) buf[i] = cp1251_to_koi8r( buf[i] );
        }
        break;
      }
    }
    break;

    case CHS_CP866:
    {
      switch( to_chs )
      {
        case CHS_KOI8R:
        {
          for( i = 0; i < len; i++ ) buf[i] = cp866_to_koi8r( buf[i] );
        }
        break;
        case CHS_CP1251:
        {
          for( i = 0; i < len; i++ ) buf[i] = cp866_to_cp1251( buf[i] );
        }
        break;
      }
    }
    break;

    case CHS_KOI8R:
    {
      switch( to_chs )
      {
        case CHS_CP866:
        {
          for( i = 0; i < len; i++ ) buf[i] = koi8r_to_cp866( buf[i] );
        }
        break;
        case CHS_CP1251:
        {
          for( i = 0; i < len; i++ ) buf[i] = koi8r_to_cp1251( buf[i] );
        }
        break;
      }
    }
    break;
  }

}
// ---------------------------------------------------------------------------
void* fs_alloc( FS_INT32 s )
{
  return heap_alloc( NULL, s, HEAP_ALIGN_4 );
}
// ---------------------------------------------------------------------------
void fs_free( void* p )
{
  heap_free( NULL, p );
}
// ---------------------------------------------------------------------------
