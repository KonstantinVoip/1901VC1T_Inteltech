// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: all
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp866
// !: d: Модуль содержит прототипы и макросы вызова всех функций ядра ОС,
// !: d: доступных через таблицу системных вызовов (syscall).
// !: -:
// ---------------------------------------------------------------------------
#ifndef __OS_System_Call_H__
#define __OS_System_Call_H__

#define SYSCALL_SYS_SETNAME                             0
#define SYSCALL_SYS_GETNAME                             1
#define SYSCALL_SYS_CHKNAME                             2
#define SYSCALL_SYS_REGGET                              3
#define SYSCALL_SYS_REGSET                              4
#define SYSCALL_SYS_REGLOCK                             5
#define SYSCALL_SYS_REGUNLOCK                           6
#define SYSCALL_SYS_BUSLOCK                             7
#define SYSCALL_SYS_BUSUNLOCK                           8
#define SYSCALL_SYS_DEBUG                               9

#define SYSCALL_PRC_CREATE                              10
#define SYSCALL_PRC_EXIT                                11
#define SYSCALL_PRC_YIELD                               12
#define SYSCALL_PRC_ID                                  13
#define SYSCALL_PRC_PRIORITY                            14
#define SYSCALL_PRC_ARG                                 15
#define SYSCALL_PRC_ARG_LENGTH                          16
#define SYSCALL_PRC_HEAP                                17
#define SYSCALL_PRC_SWTO                                18
#define SYSCALL_PRC_SET_PRIORITY                        19
#define SYSCALL_PRC_SET_FLAGS                           20
#define SYSCALL_PRC_FLAGS                               21
#define SYSCALL_PRC_SYSTEM                              22
#define SYSCALL_PRC_DISABLE                             23
#define SYSCALL_PRC_ENABLE                              24
#define SYSCALL_PRC_JOIN                                25

#define SYSCALL_MEM_ALLOC                               26
#define SYSCALL_MEM_FREE                                27
#define SYSCALL_MEM_STAT                                28
#define SYSCALL_MEM_PTR                                 29

#define SYSCALL_HEAP_CREATE                             30
#define SYSCALL_HEAP_DESTROY                            31
#define SYSCALL_HEAP_INIT                               32
#define SYSCALL_HEAP_ALLOC                              33
#define SYSCALL_HEAP_FREE                               34
#define SYSCALL_HEAP_ISIN                               35
#define SYSCALL_HEAP_STAT                               36

#define SYSCALL_SEM_ALLOC                               37
#define SYSCALL_SEM_RESET                               38
#define SYSCALL_SEM_FREE                                39
#define SYSCALL_SEM_LOCK                                40
#define SYSCALL_SEM_UNLOCK                              41
#define SYSCALL_SEM_UNLOCK_SW                           42
#define SYSCALL_SEM_LOCKUNLOCK                          43
#define SYSCALL_SEM_LOCKED                              44
#define SYSCALL_SEM_VALUE                               45

#define SYSCALL_INT_ENABLE                              46
#define SYSCALL_INT_DISABLE                             47
#define SYSCALL_INT_LOCK                                48
#define SYSCALL_INT_UNLOCK                              49
#define SYSCALL_INT_ALLOC                               50
#define SYSCALL_INT_FREE                                51
#define SYSCALL_INT_SWTO                                52
#define SYSCALL_INT_CLEAR                               53
#define SYSCALL_INT_SET                                 54

#define SYSCALL_TIME_SET                                55
#define SYSCALL_TIME_S                                  56
#define SYSCALL_TIME_M                                  57
#define SYSCALL_TIME_U                                  58
#define SYSCALL_TIME_N                                  59
#define SYSCALL_TIME_CORE                               60
#define SYSCALL_TIME_CORE_N                             61

#define SYSCALL_SLEEP_S                                 62
#define SYSCALL_SLEEP_M                                 63
#define SYSCALL_SLEEP_U                                 64

#define SYSCALL_DRV_PLUG                                65
#define SYSCALL_DRV_UNPLUG                              66
#define SYSCALL_DRV_OPEN                                67
#define SYSCALL_DRV_CLOSE                               68
#define SYSCALL_DRV_READ                                69
#define SYSCALL_DRV_WRITE                               70
#define SYSCALL_DRV_IOCTL                               71
#define SYSCALL_DRV_SELECT                              72
#define SYSCALL_DRV_MKD                                 73
#define SYSCALL_DRV_RMD                                 74
#define SYSCALL_DRV_CREATE                              75
#define SYSCALL_DRV_INC                                 76
#define SYSCALL_DRV_DEC                                 77
#define SYSCALL_DRV_RFS                                 78
#define SYSCALL_DRV_LIST_DESTROY                        79
#define SYSCALL_DRV_LIST                                80
#define SYSCALL_DRV_REMOVE                              81
#define SYSCALL_DRV_RENAME                              82

#define SYSCALL_EXT_PLUG                                83
#define SYSCALL_EXT_UNPLUG                              84
#define SYSCALL_EXT_LOAD                                85
#define SYSCALL_EXT_UNLOAD                              86
#define SYSCALL_EXT_SYMBOL                              87

#define SYSCALL_RES_SHARE                               88
#define SYSCALL_RES_UNSHARE                             89
#define SYSCALL_RES_SHARED                              90
#define SYSCALL_RES_CHOWN                               91

#define SYSCALL_MSG_START                               92
#define SYSCALL_MSG_END                                 93
#define SYSCALL_MSG_OPEN                                94
#define SYSCALL_MSG_CLOSE                               95
#define SYSCALL_MSG_SEND                                96
#define SYSCALL_MSG_RECV                                97
#define SYSCALL_MSG_HAVE                                98
#define SYSCALL_MSG_DISCOVER                            99
#define SYSCALL_MSG_PID                                 100
#define SYSCALL_MSG_FREE                                101
#define SYSCALL_MSG_ALLOC                               102
#define SYSCALL_MSG_QUEUE_INIT                          103
#define SYSCALL_MSG_QUEUE_PUSH                          104
#define SYSCALL_MSG_QUEUE_POP                           105
#define SYSCALL_MSG_QUEUE_DEINIT                        106
#define SYSCALL_MSG_REGPIPE                             107

#define SYSCALL_LIF_LOAD                                108
#define SYSCALL_LIF_UNLOAD                              109
#define SYSCALL_LIF_FREE                                110

#define SYSCALL_SYSLOG_INIT                             111
#define SYSCALL_SYSLOG                                  112
#define SYSCALL_SYSLOG_LEVEL                            113
#define SYSCALL_SYSLOG_COUNT                            114
#define SYSCALL_SYSLOG_READ                             115
#define SYSCALL_SYSLOG_CBADD                            116
#define SYSCALL_SYSLOG_CBDEL                            117

#define SYSCALL_SYN_INIT                                118
#define SYSCALL_SYN_OPEN                                119
#define SYSCALL_SYN_CLOSE                               120
#define SYSCALL_SYN_BEGIN                               121
#define SYSCALL_SYN_END                                 122
#define SYSCALL_SYN_TIME_S                              123
#define SYSCALL_SYN_TIME_M                              124
#define SYSCALL_SYN_TIME_U                              125
#define SYSCALL_SYN_TIME_CORE                           126
#define SYSCALL_SYN_READ_OSTS                           127
#define SYSCALL_SYN_DATA                                128
#define SYSCALL_SYN_ERROR                               129
#define SYSCALL_SYN_WAIT_TM                             130

#define SYSCALL_EMIF_INIT                               131

#define SYSCALL_CRYPTO_CRC16                            132
#define SYSCALL_CRYPTO_CRC32                            133
#define SYSCALL_CRYPTO_GOST_HASH_INIT                   134
#define SYSCALL_CRYPTO_GOST_HASH_START                  135
#define SYSCALL_CRYPTO_GOST_HASH_CONT                   136
#define SYSCALL_CRYPTO_GOST_HASH_END                    137
#define SYSCALL_CRYPTO_GOST_HASH                        138
#define SYSCALL_CRYPTO_GOST89_LOAD_BP                   139
#define SYSCALL_CRYPTO_GOST89_LOAD_KEY                  140
#define SYSCALL_CRYPTO_GOST89_START_GAMMA               141
#define SYSCALL_CRYPTO_GOST89_CONT_GAMMA                142
#define SYSCALL_CRYPTO_GOST89_GAMMA                     143
#define SYSCALL_CRYPTO_GOST89_IMIT                      144
#define SYSCALL_CRYPTO_GOST89_IMIT_BLOCKS               145
#define SYSCALL_CRYPTO_GOST89_ENCRYPT_BLOCKS            146
#define SYSCALL_CRYPTO_GOST89_DECRYPT_BLOCKS            147

#define SYSCALL_SOCKET                                  160
#define SYSCALL_BIND                                    161
#define SYSCALL_CONNECT                                 162
#define SYSCALL_ACCEPT                                  163
#define SYSCALL_LISTEN                                  164
#define SYSCALL_GETPEERNAME                             165
#define SYSCALL_GETSOCKNAME                             166
#define SYSCALL_GETSOCKOPT                              167
#define SYSCALL_RECVFROM                                168
#define SYSCALL_RECV                                    169
#define SYSCALL_SENDTO                                  170
#define SYSCALL_SEND                                    171
#define SYSCALL_SETSOCKOPT                              172
#define SYSCALL_SOCKET_INIT                             173
#define SYSCALL_SOCKET_DEINIT                           174
#define SYSCALL_SOCKET_IOCTL                            175
#define SYSCALL_SOCKET_CLOSE                            176

#define SYSCALL_LIF_LOAD_FIXED                          177
#define SYSCALL_SYS_CACHE_CLEAR                         178
#define SYSCALL_VNET_ETH_INIT                           179

#define SYSCALL__COUNT__                                180

#ifdef SYSCALL_DIRECT
#
#  define syscall_init                  os_syscall_copy_table
#
#  define sys_setname                   os_system_setname
#  define sys_getname                   os_system_getname
#  define sys_chkname                   os_system_chkname
#  define sys_regget                    os_system_regget
#  define sys_regset                    os_system_regset
#  define sys_reglock                   os_system_reglock
#  define sys_regunlock                 os_system_regunlock
#  define sys_buslock                   os_system_buslock
#  define sys_busunlock                 os_system_busunlock
#  define sys_debug                     os_system_debug
#  define sys_cache_clear               os_cache_writeback_invalidate
#
#  define prc_create                    os_process_create
#  define prc_exit                      os_process_exit
#  define prc_yield                     os_process_yield_ll
#  define prc_id                        os_process_id
#  define prc_priority                  os_process_priority
#  define prc_arg                       os_process_arg
#  define prc_arg_length                os_process_arg_length
#  define prc_heap                      os_process_heap
#  define prc_swto                      os_process_switch_to
#  define prc_set_priority              os_process_set_priority
#  define prc_set_flags                 os_process_set_flags
#  define prc_flags                     os_process_flags
#  define prc_system                    os_process_system
#  define prc_disable                   os_process_disable_ll
#  define prc_enable                    os_process_enable_ll
#  define prc_join                      os_process_join
#
#  define mem_alloc                     os_mem_alloc
#  define mem_free                      os_mem_free
#  define mem_stat                      os_mem_stat
#  define mem_ptr                       os_mem_ptr
#
#  define heap_create                   os_heap_create
#  define heap_destroy                  os_heap_destroy
#  define heap_init                     os_heap_init
#  define heap_alloc                    os_heap_alloc
#  define heap_free                     os_heap_free
#  define heap_isin                     os_heap_isin
#  define heap_stat                     os_heap_stat
#
#  define sem_alloc                     os_semaphore_alloc
#  define sem_reset                     os_semaphore_reset
#  define sem_free                      os_semaphore_free
#  define sem_lock                      os_semaphore_lock
#  define sem_unlock                    os_semaphore_unlock
#  define sem_unlock_sw                 os_semaphore_unlock_sw
#  define sem_lockunlock                os_semaphore_lockunlock
#  define sem_locked                    os_semaphore_locked
#  define sem_value                     os_semaphore_value
#
#  define int_enable                    os_interrupt_enable_ll
#  define int_disable                   os_interrupt_disable_ll
#  define int_lock                      os_interrupt_lock
#  define int_unlock                    os_interrupt_unlock
#  define int_alloc                     os_interrupt_alloc
#  define int_free                      os_interrupt_free
#  define int_swto                      os_interrupt_switch_to
#  define int_clear                     os_interrupt_clear
#  define int_set                       os_interrupt_set
#
#  define time_set                      os_time_set
#  define time_s                        os_time_s
#  define time_m                        os_time_m
#  define time_u                        os_time_u
#  define time_n                        os_time_n
#  define time_core                     os_time_core
#  define time_core_n                   os_time_core_n
#
#  define sleep_s                       os_sleep_s
#  define sleep_m                       os_sleep_m
#  define sleep_u                       os_sleep_u
#
#  define drv_plug                      os_driver_plug
#  define drv_unplug                    os_driver_unplug
#  define drv_open                      os_driver_open
#  define drv_close                     os_driver_close
#  define drv_read                      os_driver_read
#  define drv_write                     os_driver_write
#  define drv_ioctl                     os_driver_ioctl
#  define drv_select                    os_driver_select
#  define drv_mkd                       os_driver_mkd
#  define drv_rmd                       os_driver_rmd
#  define drv_create                    os_driver_create
#  define drv_inc                       os_driver_inc_path
#  define drv_dec                       os_driver_dec_path
#  define drv_rfs                       os_driver_return_to_rfs
#  define drv_list_destroy              os_driver_list_destroy
#  define drv_list                      os_driver_list
#  define drv_remove                    os_driver_remove
#  define drv_rename                    os_driver_rename
#
#  define ext_plug                      os_extension_plug
#  define ext_unplug                    os_extension_unplug
#  define ext_load                      os_extension_load
#  define ext_unload                    os_extension_unload
#  define ext_symbol                    os_extension_symbol
#
#  define res_share                     os_resource_share
#  define res_unshare                   os_resource_unshare
#  define res_shared                    os_resource_shared
#  define res_chown                     os_resource_chown
#
#  define msg_start                     os_message_start
#  define msg_end                       os_message_end
#  define msg_open                      os_message_open
#  define msg_close                     os_message_close
#  define msg_send                      os_message_send
#  define msg_recv                      os_message_recv
#  define msg_have                      os_message_have
#  define msg_discover                  os_message_discover
#  define msg_pid                       os_message_pid
#  define msg_free                      os_message_free
#  define msg_wait                      os_message_wait
#  define msg_alloc                     os_message_alloc
#  define msg_queue_init                os_message_queue_init
#  define msg_queue_push                os_message_queue_push
#  define msg_queue_pop                 os_message_queue_pop
#  define msg_queue_deinit              os_message_queue_deinit
#  define msg_regpipe                   os_message_regpipe
#
#  define lif_load                      os_lif_load
#  define lif_unload                    os_lif_unload
#  define lif_free                      os_lif_free
#
#  define lif_load_fixed                os_lif_load_fixed
#
#else
#  // SSS NOTE: WTF?.. These definitions depend on a linker memory map.
#  if defined(CHIP_6412) || defined(CHIP_6416)
#    define syscall_init                ((void(*)(void*,int32))(uint32)0x00000f80)
#  endif
#  if defined(CHIP_6457)
#    define syscall_init                ((void(*)(void*,int32))(uint32)0x00900f80)
#  endif
#  if defined(CHIP_1808)
#    define syscall_init                ((void(*)(void*,int32))(uint32)0x00000f80)
#  endif
#
#  define sys_setname                   ((int32(*)(const char*))(uint32)__syscall_tab[SYSCALL_SYS_SETNAME])
#  define sys_getname                   ((int32(*)(char*,uint32))(uint32)__syscall_tab[SYSCALL_SYS_GETNAME])
#  define sys_chkname                   ((int32(*)(const char*))(uint32)__syscall_tab[SYSCALL_SYS_CHKNAME])
#  define sys_regget                    ((int32(*)(uint32,uint32*))(uint32)__syscall_tab[SYSCALL_SYS_REGGET])
#  define sys_regset                    ((int32(*)(uint32,uint32))(uint32)__syscall_tab[SYSCALL_SYS_REGSET])
#  define sys_reglock                   ((int32(*)())(uint32)__syscall_tab[SYSCALL_SYS_REGLOCK])
#  define sys_regunlock                 ((int32(*)())(uint32)__syscall_tab[SYSCALL_SYS_REGUNLOCK])
#  define sys_buslock                   ((int32(*)())(uint32)__syscall_tab[SYSCALL_SYS_BUSLOCK])
#  define sys_busunlock                 ((int32(*)())(uint32)__syscall_tab[SYSCALL_SYS_BUSUNLOCK])
#  define sys_debug                     ((void(*)(uint32))(uint32)__syscall_tab[SYSCALL_SYS_DEBUG])
#  define sys_cache_clear               ((void(*)(uint32,uint32))(uint32)__syscall_tab[SYSCALL_SYS_CACHE_CLEAR])
#
#  define prc_create                    ((int32(*)(int(*)(void*),void*,int32,s_prc_attr*))(uint32)__syscall_tab[SYSCALL_PRC_CREATE])
#  define prc_exit                      ((void(*)())(uint32)__syscall_tab[SYSCALL_PRC_EXIT])
#  define prc_yield                     ((void(*)())(uint32)__syscall_tab[SYSCALL_PRC_YIELD])
#  define prc_id                        ((uint16(*)())(uint32)__syscall_tab[SYSCALL_PRC_ID])
#  define prc_priority                  ((uint16(*)())(uint32)__syscall_tab[SYSCALL_PRC_PRIORITY])
#  define prc_arg                       ((void*(*)())(uint32)__syscall_tab[SYSCALL_PRC_ARG])
#  define prc_arg_length                ((int32(*)())(uint32)__syscall_tab[SYSCALL_PRC_ARG_LENGTH])
#  define prc_heap                      ((s_os_heap*(*)())(uint32)__syscall_tab[SYSCALL_PRC_HEAP])
#  define prc_swto                      ((void(*)(uint16))(uint32)__syscall_tab[SYSCALL_PRC_SWTO])
#  define prc_set_priority              ((int32(*)(int32))(uint32)__syscall_tab[SYSCALL_PRC_SET_PRIORITY])
#  define prc_set_flags                 ((void(*)(uint16))(uint32)__syscall_tab[SYSCALL_PRC_SET_FLAGS])
#  define prc_flags                     ((uint16(*)())(uint32)__syscall_tab[SYSCALL_PRC_FLAGS])
#  define prc_system                    ((void(*)())(uint32)__syscall_tab[SYSCALL_PRC_SYSTEM])
#  define prc_disable                   ((uint32(*)())(uint32)__syscall_tab[SYSCALL_PRC_DISABLE])
#  define prc_enable                    ((void(*)(uint32))(uint32)__syscall_tab[SYSCALL_PRC_ENABLE])
#  define prc_join                      ((int32(*)(uint16))(uint32)__syscall_tab[SYSCALL_PRC_JOIN])
#
#  define mem_alloc                     ((s_os_mem_block*(*)(int32,uint32))(uint32)__syscall_tab[SYSCALL_MEM_ALLOC])
#  define mem_free                      ((void(*)(s_os_mem_block*))(uint32)__syscall_tab[SYSCALL_MEM_FREE])
#  define mem_stat                      ((void(*)(s_os_mem_stat*))(uint32)__syscall_tab[SYSCALL_MEM_STAT])
#  define mem_ptr                       ((void*(*)(s_os_mem_block*))(uint32)__syscall_tab[SYSCALL_MEM_PTR])
#
#  define heap_create                   ((s_os_heap*(*)(int32))(uint32)__syscall_tab[SYSCALL_HEAP_CREATE])
#  define heap_destroy                  ((void(*)(s_os_heap*))(uint32)__syscall_tab[SYSCALL_HEAP_DESTROY])
#  define heap_init                     ((void(*)(s_os_heap*))(uint32)__syscall_tab[SYSCALL_HEAP_INIT])
#  define heap_alloc                    ((void*(*)(s_os_heap*,int32,int32))(uint32)__syscall_tab[SYSCALL_HEAP_ALLOC])
#  define heap_free                     ((void(*)(s_os_heap*,void*))(uint32)__syscall_tab[SYSCALL_HEAP_FREE])
#  define heap_isin                     ((bool(*)(s_os_heap*,void*))(uint32)__syscall_tab[SYSCALL_HEAP_ISIN])
#  define heap_stat                     ((void(*)(s_os_heap*,s_os_heap_stat*))(uint32)__syscall_tab[SYSCALL_HEAP_STAT])
#
#  define sem_alloc                     ((uint32(*)(int32,const char*))(uint32)__syscall_tab[SYSCALL_SEM_ALLOC])
#  define sem_reset                     ((uint32(*)(uint32,int32))(uint32)__syscall_tab[SYSCALL_SEM_RESET])
#  define sem_free                      ((uint32(*)(uint32))(uint32)__syscall_tab[SYSCALL_SEM_FREE])
#  define sem_lock                      ((uint32(*)(uint32,uint32))(uint32)__syscall_tab[SYSCALL_SEM_LOCK])
#  define sem_unlock                    ((uint32(*)(uint32))(uint32)__syscall_tab[SYSCALL_SEM_UNLOCK])
#  define sem_unlock_sw                 ((uint32(*)(uint32))(uint32)__syscall_tab[SYSCALL_SEM_UNLOCK_SW])
#  define sem_lockunlock                ((uint32(*)(uint32,uint32,uint32))(uint32)__syscall_tab[SYSCALL_SEM_LOCKUNLOCK])
#  define sem_locked                    ((uint32(*)(uint32))(uint32)__syscall_tab[SYSCALL_SEM_LOCKED])
#  define sem_value                     ((uint32(*)(uint32,int32*))(uint32)__syscall_tab[SYSCALL_SEM_VALUE])
#
#  define int_enable                    ((void(*)(uint32))(uint32)__syscall_tab[SYSCALL_INT_ENABLE])
#  define int_disable                   ((uint32(*)())(uint32)__syscall_tab[SYSCALL_INT_DISABLE])
#  define int_lock                      ((int32(*)(uint32))(uint32)__syscall_tab[SYSCALL_INT_LOCK])
#  define int_unlock                    ((int32(*)(uint32))(uint32)__syscall_tab[SYSCALL_INT_UNLOCK])
#  define int_alloc                     ((uint32(*)(uint32,void(*)()))(uint32)__syscall_tab[SYSCALL_INT_ALLOC])
#  define int_free                      ((int32(*)(uint32))(uint32)__syscall_tab[SYSCALL_INT_FREE])
#  define int_swto                      ((void(*)(uint16))(uint32)__syscall_tab[SYSCALL_INT_SWTO])
#  define int_clear                     ((int32(*)(uint32))(uint32)__syscall_tab[SYSCALL_INT_CLEAR])
#  define int_set                       ((int32(*)(uint32))(uint32)__syscall_tab[SYSCALL_INT_SET])
#
#  define time_set                      ((void(*)(uint32))(uint32)__syscall_tab[SYSCALL_TIME_SET])
#  define time_s                        ((uint32(*)())(uint32)__syscall_tab[SYSCALL_TIME_S])
#  define time_m                        ((uint64(*)())(uint32)__syscall_tab[SYSCALL_TIME_M])
#  define time_u                        ((uint64(*)())(uint32)__syscall_tab[SYSCALL_TIME_U])
#  define time_n                        ((uint64(*)())(uint32)__syscall_tab[SYSCALL_TIME_N])
#  define time_core                     ((uint64(*)())(uint32)__syscall_tab[SYSCALL_TIME_CORE])
#  define time_core_n                   ((uint64(*)())(uint32)__syscall_tab[SYSCALL_TIME_CORE_N])
#
#  define sleep_s                       ((void(*)(uint32))(uint32)__syscall_tab[SYSCALL_SLEEP_S])
#  define sleep_m                       ((void(*)(uint32))(uint32)__syscall_tab[SYSCALL_SLEEP_M])
#  define sleep_u                       ((void(*)(uint32))(uint32)__syscall_tab[SYSCALL_SLEEP_U])
#
#  define drv_plug                      ((int32(*)(const char*,uint8,int32(*)(s_os_driver_descriptor*,uint16),int32(*)(s_os_driver_descriptor*),int32(*)(s_os_driver_descriptor*,void*,int32),int32(*)(s_os_driver_descriptor*,const void*,int32),int32(*)(s_os_driver_descriptor*,int32,const void*),void*,int32))(uint32)__syscall_tab[SYSCALL_DRV_PLUG])
#  define drv_unplug                    ((int32(*)(const char*))(uint32)__syscall_tab[SYSCALL_DRV_UNPLUG])
#  define drv_open                      ((int32(*)(uint32,uint16))(uint32)__syscall_tab[SYSCALL_DRV_OPEN])
#  define drv_close                     ((int32(*)(uint32))(uint32)__syscall_tab[SYSCALL_DRV_CLOSE])
#  define drv_read                      ((int32(*)(uint32,void*,int32))(uint32)__syscall_tab[SYSCALL_DRV_READ])
#  define drv_write                     ((int32(*)(uint32,const void*,int32))(uint32)__syscall_tab[SYSCALL_DRV_WRITE])
#  define drv_ioctl                     ((int32(*)(uint32,int32,const void*))(uint32)__syscall_tab[SYSCALL_DRV_IOCTL])
#  define drv_select                    ((int32(*)(uint32,const char*))(uint32)__syscall_tab[SYSCALL_DRV_SELECT])
#  define drv_mkd                       ((uint32(*)(const char*))(uint32)__syscall_tab[SYSCALL_DRV_MKD])
#  define drv_rmd                       ((int32(*)(uint32))(uint32)__syscall_tab[SYSCALL_DRV_RMD])
#  define drv_create                    ((int32(*)(uint32,const char*,uint8))(uint32)__syscall_tab[SYSCALL_DRV_CREATE])
#  define drv_inc                       ((bool(*)(s_os_driver_descriptor*,const char*))(uint32)__syscall_tab[SYSCALL_DRV_INC])
#  define drv_dec                       ((bool(*)(s_os_driver_descriptor*))(uint32)__syscall_tab[SYSCALL_DRV_DEC])
#  define drv_rfs                       ((bool(*)(s_os_driver_descriptor*))(uint32)__syscall_tab[SYSCALL_DRV_RFS])
#  define drv_list_destroy              ((void(*)(s_inode*))(uint32)__syscall_tab[SYSCALL_DRV_LIST_DESTROY])
#  define drv_list                      ((int32(*)(uint32,s_inode**))(uint32)__syscall_tab[SYSCALL_DRV_LIST])
#  define drv_remove                    ((int32(*)(uint32,const char*))(uint32)__syscall_tab[SYSCALL_DRV_REMOVE])
#  define drv_rename                    ((int32(*)(uint32,const char*))(uint32)__syscall_tab[SYSCALL_DRV_RENAME])
#
#  define ext_plug                      ((int32(*)(s_os_extension*))(uint32)__syscall_tab[SYSCALL_EXT_PLUG])
#  define ext_unplug                    ((int32(*)(s_os_extension*))(uint32)__syscall_tab[SYSCALL_EXT_UNPLUG])
#  define ext_load                      ((int32(*)(const char*))(uint32)__syscall_tab[SYSCALL_EXT_LOAD])
#  define ext_unload                    ((int32(*)(const char*))(uint32)__syscall_tab[SYSCALL_EXT_UNLOAD])
#  define ext_symbol                    ((void*(*)(const char*))(uint32)__syscall_tab[SYSCALL_EXT_SYMBOL])
#
#  define res_share                     ((uint32(*)(uint32))(uint32)__syscall_tab[SYSCALL_RES_SHARE])
#  define res_unshare                   ((uint32(*)(uint32))(uint32)__syscall_tab[SYSCALL_RES_UNSHARE])
#  define res_shared                    ((uint32(*)(uint32))(uint32)__syscall_tab[SYSCALL_RES_SHARED])
#  define res_chown                     ((uint32(*)(uint32,uint16))(uint32)__syscall_tab[SYSCALL_RES_CHOWN])
#
#  define msg_start                     ((int32(*)(uint32,int32))(uint32)__syscall_tab[SYSCALL_MSG_START])
#  define msg_end                       ((int32(*)())(uint32)__syscall_tab[SYSCALL_MSG_END])
#  define msg_open                      ((int32(*)(const char*))(uint32)__syscall_tab[SYSCALL_MSG_OPEN])
#  define msg_close                     ((int32(*)())(uint32)__syscall_tab[SYSCALL_MSG_CLOSE])
#  define msg_send                      ((int32(*)(uint32,const void*,int32))(uint32)__syscall_tab[SYSCALL_MSG_SEND])
#  define msg_recv                      ((int32(*)(s_message**,uint32))(uint32)__syscall_tab[SYSCALL_MSG_RECV])
#  define msg_have                      ((int32(*)())(uint32)__syscall_tab[SYSCALL_MSG_HAVE])
#  define msg_discover                  ((uint32(*)(const char*,const char*,uint32))(uint32)__syscall_tab[SYSCALL_MSG_DISCOVER])
#  define msg_pid                       ((uint32(*)())(uint32)__syscall_tab[SYSCALL_MSG_PID])
#  define msg_free                      ((int32(*)(s_message*))(uint32)__syscall_tab[SYSCALL_MSG_FREE])
#  define msg_alloc                     ((s_message*(*)(uint32,s_message_pipe*))(uint32)__syscall_tab[SYSCALL_MSG_ALLOC])
#  define msg_queue_init                ((int32(*)(s_message_queue*))(uint32)__syscall_tab[SYSCALL_MSG_QUEUE_INIT])
#  define msg_queue_push                ((int32(*)(s_message_queue*,s_message*))(uint32)__syscall_tab[SYSCALL_MSG_QUEUE_PUSH])
#  define msg_queue_pop                 ((int32(*)(s_message_queue*,s_message**,uint32))(uint32)__syscall_tab[SYSCALL_MSG_QUEUE_POP])
#  define msg_queue_deinit              ((int32(*)(s_message_queue*))(uint32)__syscall_tab[SYSCALL_MSG_QUEUE_DEINIT])
#  define msg_regpipe                   ((int32(*)(s_message_context*,int32))(uint32)__syscall_tab[SYSCALL_MSG_REGPIPE])
#
#  define lif_load                      ((int32(*)(const char*,const char*,uint32,s_lif_overlay*))(uint32)__syscall_tab[SYSCALL_LIF_LOAD])
#  define lif_unload                    ((int32(*)(s_lif_overlay*))(uint32)__syscall_tab[SYSCALL_LIF_UNLOAD])
#  define lif_free                      ((int32(*)(s_lif_overlay*))(uint32)__syscall_tab[SYSCALL_LIF_FREE])
#
#  define lif_load_fixed                ((int32(*)(const char*,void*,const char*,uint32,uint32,uint32))(uint32)__syscall_tab[SYSCALL_LIF_LOAD_FIXED])
#
#endif
#
# // -------------------------------------------------------------------------
# // Extensions can be called only throw syscall table
# // -------------------------------------------------------------------------
#
# /* Syslog module */
#
#define syslog_init                     ((int32(*)())(uint32)__syscall_tab[SYSCALL_SYSLOG_INIT])
#define syslog                          ((int32(*)(int32,const char*,...))(uint32)__syscall_tab[SYSCALL_SYSLOG])
#define syslog_level                    ((int32(*)(int32))(uint32)__syscall_tab[SYSCALL_SYSLOG_LEVEL])
#define syslog_count                    ((int32(*)())(uint32)__syscall_tab[SYSCALL_SYSLOG_COUNT])
#define syslog_read                     ((int32(*)(int32,void*,int32))(uint32)__syscall_tab[SYSCALL_SYSLOG_READ])
#define syslog_cbadd                    ((int32(*)(void(*)(const char*)))(uint32)__syscall_tab[SYSCALL_SYSLOG_CBADD])
#define syslog_cbdel                    ((int32(*)(void(*)(const char*)))(uint32)__syscall_tab[SYSCALL_SYSLOG_CBDEL])
#
#  /* Interprocessor synchronization module */
#
#define syn_init                        ((int32(*)(int32,uint32,void(*)(int32)))(uint32)__syscall_tab[SYSCALL_SYN_INIT])
#define syn_open                        ((int32(*)(uint16))(uint32)__syscall_tab[SYSCALL_SYN_OPEN])
#define syn_close                       ((int32(*)(uint16))(uint32)__syscall_tab[SYSCALL_SYN_CLOSE])
#define syn_begin                       ((int32(*)())(uint32)__syscall_tab[SYSCALL_SYN_BEGIN])
#define syn_end                         ((int32(*)())(uint32)__syscall_tab[SYSCALL_SYN_END])
#define syn_time_s                      ((int32(*)(uint32*))(uint32)__syscall_tab[SYSCALL_SYN_TIME_S])
#define syn_time_m                      ((int32(*)(uint64*))(uint32)__syscall_tab[SYSCALL_SYN_TIME_M])
#define syn_time_u                      ((int32(*)(uint64*))(uint32)__syscall_tab[SYSCALL_SYN_TIME_U])
#define syn_time_core                   ((int32(*)(uint64*))(uint32)__syscall_tab[SYSCALL_SYN_TIME_CORE])
#define syn_read_osts                   ((int32(*)(uint32*,uint32*,uint32*,uint32*))(uint32)__syscall_tab[SYSCALL_SYN_READ_OSTS])
#define syn_data                        ((int32(*)(void*,uint32,int32))(uint32)__syscall_tab[SYSCALL_SYN_DATA])
#define syn_error                       ((int32(*)(int32))(uint32)__syscall_tab[SYSCALL_SYN_ERROR])
#define syn_wait_tm                     ((int32(*)(uint64))(uint32)__syscall_tab[SYSCALL_SYN_WAIT_TM])
#
# /* Different hardware relative initializations */
#
#define emif_init                       ((void(*)())(uint32)__syscall_tab[SYSCALL_EMIF_INIT])
#
# /* Crypto module */
#
#define cry_crc16                       ((uint16(*)(const void*,uint32,uint16))(uint32)__syscall_tab[SYSCALL_CRYPTO_CRC16])
#define cry_crc32                       ((uint32(*)(const void*,uint32,uint32))(uint32)__syscall_tab[SYSCALL_CRYPTO_CRC32])
#
#define cry_hash_init                   ((void(*)(const void*))(uint32)__syscall_tab[SYSCALL_CRYPTO_GOST_HASH_INIT])
#define cry_hash_start                  ((void(*)(s_hash*,void*))(uint32)__syscall_tab[SYSCALL_CRYPTO_GOST_HASH_START])
#define cry_hash_cont                   ((void(*)(s_hash*,void*,uint32))(uint32)__syscall_tab[SYSCALL_CRYPTO_GOST_HASH_CONT])
#define cry_hash_end                    ((void*(*)(s_hash*))(uint32)__syscall_tab[SYSCALL_CRYPTO_GOST_HASH_END])
#define cry_hash                        ((void*(*)(s_hash*,void*,void*,uint32))(uint32)__syscall_tab[SYSCALL_CRYPTO_GOST_HASH])
#
#define cry_gost89_load_bp              ((void(*)(s_gost89*,void*))(uint32)__syscall_tab[SYSCALL_CRYPTO_GOST89_LOAD_BP])
#define cry_gost89_load_key             ((void(*)(s_gost89*,void*))(uint32)__syscall_tab[SYSCALL_CRYPTO_GOST89_LOAD_KEY])
#define cry_gost89_start_gamma          ((void(*)(s_gost89*,void*))(uint32)__syscall_tab[SYSCALL_CRYPTO_GOST89_START_GAMMA])
#define cry_gost89_cont_gamma           ((void(*)(s_gost89*,void*,uint32))(uint32)__syscall_tab[SYSCALL_CRYPTO_GOST89_CONT_GAMMA])
#define cry_gost89_gamma                ((void(*)(s_gost89*,void*,void*,uint32))(uint32)__syscall_tab[SYSCALL_CRYPTO_GOST89_GAMMA])
#define cry_gost89_imit                 ((uint32(*)(s_gost89*,void*,uint32))(uint32)__syscall_tab[SYSCALL_CRYPTO_GOST89_IMIT])   
#define cry_gost89_imit_blocks          ((uint32(*)(s_gost89*,void*,uint32,bool))(uint32)__syscall_tab[SYSCALL_CRYPTO_GOST89_IMIT_BLOCKS])
#define cry_gost89_upz_encrypt          ((void(*)(s_gost89*,void*,uint32))(uint32)__syscall_tab[SYSCALL_CRYPTO_GOST89_ENCRYPT_BLOCKS])
#define cry_gost89_upz_decrypt          ((void(*)(s_gost89*,void*,uint32))(uint32)__syscall_tab[SYSCALL_CRYPTO_GOST89_DECRYPT_BLOCKS])
#
# /* TCP/IP stack module */
#
#define socket_init                     ((int32(*)(uint16))(uint32)__syscall_tab[SYSCALL_SOCKET_INIT])
#define socket_deinit                   ((int32(*)())(uint32)__syscall_tab[SYSCALL_SOCKET_DEINIT])
#define socket                          ((int32(*)(int32,int32,int32))(uint32)__syscall_tab[SYSCALL_SOCKET])
#define bind                            ((int32(*)(int32,const sockaddr*,int32))(uint32)__syscall_tab[SYSCALL_BIND])
#define connect                         ((int32(*)(int32,const sockaddr*,int32))(uint32)__syscall_tab[SYSCALL_CONNECT])
#define accept                          ((int32(*)(int32,sockaddr*,int32*))(uint32)__syscall_tab[SYSCALL_ACCEPT])
#define listen                          ((int32(*)(int32,int32))(uint32)__syscall_tab[SYSCALL_LISTEN])
#define getpeername                     ((int32(*)(int32,sockaddr*,int32*))(uint32)__syscall_tab[SYSCALL_GETPEERNAME])
#define getsockname                     ((int32(*)(int32,sockaddr*,int32*))(uint32)__syscall_tab[SYSCALL_GETSOCKNAME])
#define getsockopt                      ((int32(*)(int32,int32,int32,void*,int32*))(uint32)__syscall_tab[SYSCALL_GETSOCKOPT])
#define recvfrom                        ((int32(*)(int32,void*,uint32,int32,sockaddr*,int32*))(uint32)__syscall_tab[SYSCALL_RECVFROM])
#define recv                            ((int32(*)(int32,void*,uint32,int32))(uint32)__syscall_tab[SYSCALL_RECV])
#define sendto                          ((int32(*)(int32,const void*,uint32,uint32,const sockaddr*,int32))(uint32)__syscall_tab[SYSCALL_SENDTO])
#define send                            ((int32(*)(int32,const void*,uint32,uint32))(uint32)__syscall_tab[SYSCALL_SEND])
#define setsockopt                      ((int32(*)(int32,int32,int32,const void*,int32))(uint32)__syscall_tab[SYSCALL_SETSOCKOPT])
#define socket_ioctl                    ((int32(*)(int32,int32,void*))(uint32)__syscall_tab[SYSCALL_SOCKET_IOCTL])
#define socket_close                    ((int32(*)(int32))(uint32)__syscall_tab[SYSCALL_SOCKET_CLOSE])
#
#/* VNET_ETH module */
#define vnet_eth_init                   ((int32(*)(uint8))(uint32)__syscall_tab[SYSCALL_VNET_ETH_INIT])
# // -------------------------------------------------------------------------

extern void*                            __syscall_tab[SYSCALL__COUNT__];

#endif
