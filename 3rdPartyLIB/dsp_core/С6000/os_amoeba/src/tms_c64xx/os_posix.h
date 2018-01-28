#ifndef __OS_POSIX_Support_H__
#define __OS_POSIX_Support_H__

#include <os_types.h>

extern void                     os_posix_init_module( int32 stage );
extern int32&                   os_posix_errno();

#endif
