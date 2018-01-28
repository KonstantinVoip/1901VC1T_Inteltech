// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: all
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp866
// !: d: Общий заголовочный файл, подключающий все стандартные модули
// !: d: операционной системы.
// !: -:
// ---------------------------------------------------------------------------
#ifndef __OS_H__
#define __OS_H__

#include <os_types.h>
#include <os_ioctl.h>
#include <os_syscall.h>
#include <os_utils.h>
#include <os_core.h>
#include <os_semaphore.h>
#include <os_driver.h>
#include <os_extension.h>
#include <os_message.h>
#include <os_lif.h>
#include <os_resource.h>
#include <os_interrupt.h>
#include <os_time.h>
#include <os_iodevice.h>
#include <os_error.h>
#include <os_system.h>
#include <os_cache.h>

#if defined(CHIP_6457)
#  include <os_pll.h>
#endif

#define OS_MODULE_INICIATOR( a ) \
  class __os_iniciator__##a

#define OS_MODULE_INIT( a ) \
  public: \
  __os_iniciator__##a()

#define OS_MODULE_DEINIT( a ) \
  public: \
  ~__os_iniciator__##a()

#define OS_MODULE_ACTIVATOR( a ) \
  __os_activator__##a

#endif
