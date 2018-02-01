// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: all
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp866
// !: d: Модуль содержит ссылки на вспомогательные функций операционной
// !: d: системы и описание вспомогательных классов-оболочек для работы
// !: d: со стандартными типами в формате LE и BE (int16le, int16be, uint16le,
// !: d: uint16be, int32le, int32be, uint32le, uint32be, int64le, int64be,
// !: d: uint64le, uint64be).
// !: -:
// ---------------------------------------------------------------------------
#ifndef __OS_Utils_H__
#define __OS_Utils_H__

#include <os_types.h>

extern "C" void* memcpy( void* dst, const void* src, unsigned int len );
extern "C" void* memset( void *dst, int fill, size_t len );
extern "C" int memcmp( const void* cs, const void* ct, size_t n );

extern char* strcat( char* string1, const char* string2 );
extern int strcmp( register const char* string1, register const char* string2 );
extern char* strcpy( register char* dest, register const char* src );
extern size_t strlen( const char* string );

#define U_LE_TEMPLATE( type, size ) \
class type##le \
{ \
  private: \
\
    uint8 a[size]; \
\
  public: \
\
    type##le() { } \
    type##le( type n ) { for( int i = 0; i < size; i++ ) { a[i] = n & 0xff; n >>= 8; } } \
    type##le( type##le& n ) { memcpy( a, n.a, sizeof(a) ); } \
    void operator =( type n ) { for( int i = 0; i < size; i++ ) { a[i] = n & 0xff; n >>= 8; } } \
    void operator =( type##le& n ) { memcpy( a, n.a, sizeof(a) ); } \
    operator type() { type r; for( int i = size - 1; i >= 0; i-- ) { r <<= 8; r |= (type)a[i] & 0xff; } return r; } \
\
}

#define U_BE_TEMPLATE( type, size ) \
class type##be \
{ \
  private: \
\
    uint8 a[size]; \
\
  public: \
\
    type##be() { } \
    type##be( type n ) { for( int i = size - 1; i >= 0; i-- ) { a[i] = n & 0xff; n >>= 8; } } \
    type##be( type##be& n ) { memcpy( a, n.a, sizeof(a) ); } \
    void operator =( type n ) { for( int i = size - 1; i >= 0; i-- ) { a[i] = n & 0xff; n >>= 8; } } \
    void operator =( type##be& n ) { memcpy( a, n.a, sizeof(a) ); } \
    operator type() { type r; for( int i = 0; i < size; i++ ) { r <<= 8; r |= (type)a[i] & 0xff; } return r; } \
\
}

U_LE_TEMPLATE( int16,  2 ); // int16le
U_LE_TEMPLATE( uint16, 2 ); // uint16le
U_BE_TEMPLATE( int16,  2 ); // int16be
U_BE_TEMPLATE( uint16, 2 ); // uint16be

U_LE_TEMPLATE( int32,  4 ); // int32le
U_LE_TEMPLATE( uint32, 4 ); // uint32le
U_BE_TEMPLATE( int32,  4 ); // int32be
U_BE_TEMPLATE( uint32, 4 ); // uint32be

U_LE_TEMPLATE( int64,  8 ); // int64le
U_LE_TEMPLATE( uint64, 8 ); // uint64le
U_BE_TEMPLATE( int64,  8 ); // int64be
U_BE_TEMPLATE( uint64, 8 ); // uint64be

#endif
