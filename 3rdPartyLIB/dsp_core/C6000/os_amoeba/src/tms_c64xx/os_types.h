/** 
 * System and drivers standart types.
 * 
 * @copyright 2012-2015 RCZI
 */
#ifndef OS_TYPES_H_
#define OS_TYPES_H_

#include <stddef.h>
#include <os_defs.h>

#ifndef __cplusplus
#  error "Please do not use C style sources with OS sources!"
#endif

typedef signed char int8;
typedef unsigned char uint8;
typedef signed short int16;
typedef unsigned short uint16;
typedef signed int int32;
typedef unsigned int uint32;
typedef signed long long int64;
typedef unsigned long long uint64;
typedef float float32;
typedef long double float64;

#endif //OS_TYPES_H_
