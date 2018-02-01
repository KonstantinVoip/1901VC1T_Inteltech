// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: all
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp866
// !: d: Модуль содержит директивы препроцессора необходимые для сборки ядра.
// !: -:
// ---------------------------------------------------------------------------
#ifndef __OS_Definitions_H__
#define __OS_Definitions_H__

// -- All definitions only for internal usage --------------------------------

/*
// !!! Don't touch !!!
#define OS_SUPPORT_SYSLOG
#define OS_SUPPORT_SYNCHRONIZATION
// !!! Don't touch !!!
*/

#ifdef OS_SUPPORT_SYNCHRONIZATION
#  define OS_SUPPORT__syn_begin()                               syn_begin()
#  define OS_SUPPORT__syn_end()                                 syn_end()
#  define OS_SUPPORT__syn_time_s( v )                           syn_time_s( &v )
#  define OS_SUPPORT__syn_time_m( v )                           syn_time_m( &v )
#  define OS_SUPPORT__syn_time_u( v )                           syn_time_u( &v )
#  define OS_SUPPORT__syn_time_core( v )                        syn_time_core( &v )
#else
#  define OS_SUPPORT__syn_begin()
#  define OS_SUPPORT__syn_end()
#  define OS_SUPPORT__syn_time_s( v )                           v = time_s()
#  define OS_SUPPORT__syn_time_m( v )                           v = time_m()
#  define OS_SUPPORT__syn_time_u( v )                           v = time_u()
#  define OS_SUPPORT__syn_time_core( v )                        v = time_core()
#endif

#if defined(CHIP_6412) || defined(CHIP_6416) || defined(CHIP_6457)
#  define CHIP_DEFINED
#endif

#ifndef CHIP_DEFINED
#  define CHIP_6412
#  define CHIP_DEFINED
#endif

#endif
