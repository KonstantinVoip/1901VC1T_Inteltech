;; -- DO NOT REMOVE ----------------------------------------------------------
;; !: arch: tms320c64xx
;; !: sarc: all
;; - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
;; !: codepage: cp866
;; !: d: Модуль содержит низкоуровневые функции работы с процессами и
;; !: d: низкоуровневый код инициализации аппаратного ядра.
;; !: -:
;; ---------------------------------------------------------------------------

; -- Definitions -------------------------------------------------------------

        .asg            b15, sp

; -- Import external symbols -------------------------------------------------

        .global         _v_os_interrupt_vector_01_NMI
        .global         _v_os_interrupt_vector_05
        .global         _v_os_interrupt_vector_06
        .global         _v_os_interrupt_vector_07
        .global         _v_os_interrupt_vector_08
        .global         _v_os_interrupt_vector_09
        .global         _v_os_interrupt_vector_10
        .global         _v_os_interrupt_vector_11
        .global         _v_os_interrupt_vector_12
        .global         _v_os_interrupt_vector_13
        .global         _v_os_interrupt_vector_14
        .global         _v_os_interrupt_vector_15
        .global         _v_os_current_process
        .global         _v_os_process_ring
        .global         _v_os_process_count
        .global         _v_os_core_call
        .global         _OS_STACK_END
        .global         _OS_ISTACK_END
        .global         _OS_NMISTACK_END
        .global         _v_os_irctx_nmi
        .global         _v_os_irctx
        .global         _v_os_core_heap
        
        .global         _os_process_switcher__Fv
        .global         _os_initialize_core__Fv
        .global         _os_interrupt_null_vector_ll__Fv

; -- Export local symbols ----------------------------------------------------

        .def            os_process_switch_ll
        .def            _os_process_yield_ll__Fv
        .def            _os_core_initialize_ll__Fv
        .def            _os_process_enable_ll__FUi
        .def            _os_process_disable_ll__Fv

        .sect           ".text"

;-----------------------------------------------------------------------------
;; !: fn: void os_process_switch_ll()
;; - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
;; !: d: Низкоуровневая функция переключения контекта процесса. Данная функция
;; !: d: не доступна пользователю. Время выполнения функции 71 такт (без
;; !: d: шедулера).
;; !: -:
;;-----------------------------------------------------------------------------
os_process_switch_ll:

        stdw    .d2     b1:b0, *sp--[1]                                 ; 0  0
        stdw    .d2     a1:a0, *sp--[1]                                 ; 0  1
     || nop             1                                               ; 0  2
     || nop             1                                               ; 0  3
     || nop             1                                               ; 0  4
     || nop             1                                               ; 0  5
     || nop             1                                               ; 0  6
     || nop             1                                               ; 0  7

; -- Save current process context --------------------------------- [b13=RP] -

        mvkl    .s1     _v_os_current_process, a0                       ; 1  0
        mvkh    .s1     _v_os_current_process, a0                       ; 1  1
        ldw     .d1     *a0, a0                                         ; 1  2
        nop             4                                               ; 1  3
        ldw     .d1     *a0, a0                                         ; 1  4
        nop             4                                               ; 1  5
        add     .l2     a0, 8, b0                                       ; 1  6
     || add     .s2     a0, 8, b1                                       ; 1  7

        stdw    .d1     a3:a2, *++a0[2]                                 ; 2  0
     || stdw    .d2     b3:b2, *++b0[2]                                 ; 2  1
        stdw    .d1     a5:a4, *++a0[2]                                 ; 2  2
     || stdw    .d2     b5:b4, *++b0[2]                                 ; 2  3
     || add     .l1     b1, 0, a2                                       ; 2  4
     || add     .l2     b1, 0, b2                                       ; 2  5
        stdw    .d1     a7:a6, *++a2[5]                                 ; 2  6
     || stdw    .d2     b7:b6, *++b2[6]                                 ; 2  7

        stdw    .d1     a9:a8, *++a2[2]                                 ; 3  0
     || stdw    .d2     b9:b8, *++b2[2]                                 ; 3  1
     || add     .l1     sp, 0, a3                                       ; 3  2
     || add     .l2     sp, 0, b3                                       ; 3  3
        lddw    .d1     *+a3[1], a1:a0                                  ; 3  4
     || nop             1                                               ; 3  5
        lddw    .d2     *+b3[2], b1:b0                                  ; 3  6
     || addk    .s2     16, sp                                          ; 3  7

        stdw    .d1     a11:a10, *++a2[2]                               ; 4  0
     || stdw    .d2     b11:b10, *++b2[2]                               ; 4  1
     || add     .l1     b1, -8, a3                                      ; 4  2
     || add     .l2     b1, 0, b3                                       ; 4  3
        stdw    .d1     a13:a12, *++a2[2]                               ; 4  4
     || stw     .d2     b12, *++b2[4]                                   ; 4  5
        stdw    .d1     a15:a14, *++a2[2]                               ; 4  6
     || stdw    .d2     b15:b14, *++b2[2]                               ; 4  7

        stdw    .d1     a17:a16, *++a2[2]                               ; 5  0
     || stdw    .d2     b17:b16, *++b2[2]                               ; 5  1
        stdw    .d1     a1:a0, *+a3[0]                                  ; 5  2
     || stdw    .d2     b1:b0, *+b3[0]                                  ; 5  3
        stdw    .d1     a19:a18, *++a2[2]                               ; 5  4
     || stdw    .d2     b19:b18, *++b2[2]                               ; 5  5
     || addk    .s1     256, a3                                         ; 5  6
     || mvc     .s2     amr, b0                                         ; 5  7
     
        stdw    .d1     a21:a20, *++a2[2]                               ; 6  0
     || stdw    .d2     b21:b20, *++b2[2]                               ; 6  1
     || mvkl    .s1     0, a8                                           ; 6  2
     || mvkl    .s2     _OS_STACK_END, b15                              ; 6  3
        stdw    .d1     a23:a22, *++a2[2]                               ; 6  4
     || stdw    .d2     b23:b22, *++b2[2]                               ; 6  5
     || mvkh    .s1     0, a8                                           ; 6  6
     || mvkh    .s2     _OS_STACK_END, b15                              ; 6  7

        stdw    .d1     a25:a24, *++a2[2]                               ; 7  0
     || stdw    .d2     b25:b24, *++b2[2]                               ; 7  1
     || mvc     .s2     a8, amr                                         ; 7  2
     || b       .s1     _os_process_switcher__Fv                        ; 7  3
        stdw    .d1     a27:a26, *++a2[2]                               ; 7  4
     || stdw    .d2     b27:b26, *++b2[2]                               ; 7  5
        stdw    .d1     a29:a28, *++a2[2]                               ; 7  6
     || stdw    .d2     b29:b28, *++b2[2]                               ; 7  7

        stdw    .d1     a31:a30, *++a2[2]                               ; 8  0
     || stdw    .d2     b31:b30, *++b2[2]                               ; 8  1
        stw     .d1     b0, *+a3[0]                                     ; 8  2
     || sub     .l2     b15, 8, b15                                     ; 8  3
        addkpc  .s2     rl1, b3, 0                                      ; 8  4
     || nop             1                                               ; 8  5
     || nop             1                                               ; 8  6
     || nop             1                                               ; 8  7

; -- Restore current process context -----------------------------------------

rl1:

        mvkl    .s1     _v_os_current_process, a0                       ; 9  0
        mvkh    .s1     _v_os_current_process, a0                       ; 9  1
        ldw     .d1     *a0, a0                                         ; 9  2
        nop             4                                               ; 9  3
        ldw     .d1     *a0, a0                                         ; 9  4
        nop             4                                               ; 9  5
        addk    .s1     240, a0                                         ; 9  6
        add     .s2     a0, 8, b0                                       ; 9  7

        nop             1                                               ; 10 0
     || ldw     .d2     *+b0[2], b16                                    ; 10 1
        lddw    .d1     *a0--[2], a31:a30                               ; 10 2
     || lddw    .d2     *b0--[2], b31:b30                               ; 10 3
        lddw    .d1     *a0--[2], a29:a28                               ; 10 4
     || lddw    .d2     *b0--[2], b29:b28                               ; 10 5
        lddw    .d1     *a0--[2], a27:a26                               ; 10 6
     || lddw    .d2     *b0--[2], b27:b26                               ; 10 7

        lddw    .d1     *a0--[2], a25:a24                               ; 11 0
     || lddw    .d2     *b0--[2], b25:b24                               ; 11 1
        lddw    .d1     *a0--[2], a23:a22                               ; 11 2
     || lddw    .d2     *b0--[2], b23:b22                               ; 11 3
     || mvc     .s2     b16, amr                                        ; 11 4
        lddw    .d1     *a0--[2], a21:a20                               ; 11 5
     || lddw    .d2     *b0--[2], b21:b20                               ; 11 6
     || nop             1                                               ; 11 7

        lddw    .d1     *a0--[2], a19:a18                               ; 12 0
     || lddw    .d2     *b0--[2], b19:b18                               ; 12 1
        lddw    .d1     *a0--[2], a17:a16                               ; 12 2
     || lddw    .d2     *b0--[2], b17:b16                               ; 12 3
        lddw    .d1     *a0--[2], a15:a14                               ; 12 4
     || lddw    .d2     *b0--[2], b15:b14                               ; 12 5
        lddw    .d1     *a0--[2], a13:a12                               ; 12 6
     || ldw     .d2     *b0--[4], b12                                   ; 12 7

        lddw    .d1     *a0--[2], a11:a10                               ; 13 0
     || lddw    .d2     *b0--[2], b11:b10                               ; 13 1
        lddw    .d1     *a0--[2], a9:a8                                 ; 13 2
     || lddw    .d2     *b0--[2], b9:b8                                 ; 13 3
        lddw    .d1     *a0--[2], a7:a6                                 ; 13 4
     || lddw    .d2     *b0--[2], b7:b6                                 ; 13 5
        lddw    .d1     *a0--[2], a5:a4                                 ; 13 6
     || lddw    .d2     *b0--[2], b5:b4                                 ; 13 7
        
        lddw    .d1     *a0--[2], a3:a2                                 ; 14 0
     || lddw    .d2     *b0--[2], b3:b2                                 ; 14 1
        b       .s2     b13                                             ; 14 2
        lddw    .d1     *a0--[2], a1:a0                                 ; 14 3
     || lddw    .d2     *b0--[2], b1:b0                                 ; 14 4
        nop             2                                               ; 14 5
        nop             1                                               ; 14 6
        nop             1                                               ; 14 7

;-----------------------------------------------------------------------------
;; !: fn: void os_process_yield_ll()
;; - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
;; !: d: Функция провоцирует ядро операционной системы, немедленно переключить
;; !: d: текущий процесс на следующий ожидающий исполнения. Функция доступна
;; !: d: пользователю под именем prc_yield. Длительность выполнения кода
;; !: d: функции 20 тактов.
;; !: -:
;-----------------------------------------------------------------------------
_os_process_yield_ll__Fv:

        b       .s2     l_process_yield_int_lock                        ; 0  0
        mvc     .s2     csr, b0                                         ; 0  1
        and     .s2     -2, b0, b0                                      ; 0  2
        mvc     .s2     b0, csr                                         ; 0  3
        nop             1                                               ; 0  4
        nop             1                                               ; 0  5
        nop             1                                               ; 0  6
        nop             1                                               ; 0  7

l_process_yield_int_lock:

        b       .s2     os_process_switch_ll                            ; 1  0
        addk    .s2     -16, sp                                         ; 1  1
        stw     .d2     b13, *+sp[2]                                    ; 1  2
        addkpc  .s2     l_process_yield_rp, b13, 0                      ; 1  3
        stw     .d2     b3, *+sp[3]                                     ; 1  4
        nop             1                                               ; 1  5
        nop             1                                               ; 1  6
        nop             1                                               ; 1  7

l_process_yield_rp:

        ldw     .d2     *+sp[3], b13                                    ; 2  0
        nop             4                                               ; 2  1
        b       .s2     b13                                             ; 2  2
        ldw     .d2     *+sp[2], b13                                    ; 2  3
        mvc     .s2     csr, b13                                        ; 2  4
        or      .s2     3, b13, b13                                     ; 2  5
        mvc     .s2     b13, csr                                        ; 2  6
        addk    .s2     16, sp                                          ; 2  7

;-----------------------------------------------------------------------------
;; !: fn: uint32 os_process_disable_ll()
;; - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
;; !: d: Функция запрещает переключение процессов (по таймеру) и возвращает
;; !: d: предыдущее состояние переключателя. Функция доступна пользователю под
;; !: d: именем prc_disable. Функция выполняется за 10 тактов. Внимание: когда
;; !: d: переключение процессов запрещено, функции time_s, time_m и time_core
;; !: d: будут возвращать значение времени зафиксированное на момент запрета
;; !: d: переключения процессов. Адекватное значение времени будет возвращать
;; !: d: только функция time_u, которая самостоятельно провоцирует систему на
;; !: d: обновление счетчиков времени. Так же вызов функций sleep_s и sleep_m
;; !: d: может привести к зависанию всей системы. Данная функция
;; !: d: привелегированная и в системах, где это возможно, доступна только
;; !: d: драйверам и ядру операционной системы.
;; !: -:
;-----------------------------------------------------------------------------
_os_process_disable_ll__Fv:

        b       .s2     l_prcd_0                                        ; 0  0
        mvc     .s2     csr, b1                                         ; 0  1
        and     .d2     -2, b1, b0                                      ; 0  2
        mvc     .s2     b0, csr                                         ; 0  3
        mvc     .s2     ier, b0                                         ; 0  4
     || mvk     .s1     16, a0                                          ; 0  5
        and     .d1     b0, a0, a1                                      ; 0  6
     || mvk     .s1     0, a4                                           ; 0  7

l_prcd_0:

        b       .s2     b3                                              ; 1  0
     || mvk     .s1     -20, a0                                         ; 1  1
   [a1] mvk     .s1     1, a4                                           ; 1  2
        and     .d2     b0, a0, b0                                      ; 1  3
        mvc     .s2     b0, ier                                         ; 1  4
        mvc     .s2     b1, csr                                         ; 1  5
        nop             1                                               ; 1  6
        nop             1                                               ; 1  7

;-----------------------------------------------------------------------------
;; !: fn: void os_process_enable_ll( uint32 state )
;; - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
;; !: d: Функция разрешает переключение процессов, если переменная state равна
;; !: d: 1, иначе состояние переключателя не изменяется. Функция доступна
;; !: d: пользователю под именем prc_enable. Функция выполняется за 10 тактов.
;; !: -:
;-----------------------------------------------------------------------------
_os_process_enable_ll__FUi:

        b       .s2     l_prce_0                                        ; 0  0
        mvc     .s2     csr, b1                                         ; 0  1
        and     .d2     -2, b1, b0                                      ; 0  2
        mvc     .s2     b0, csr                                         ; 0  3
        mvc     .s2     ier, b0                                         ; 0  4
     || mvk     .s1     19, a0                                          ; 0  5
     || add     .d1     a4, 0, a1                                       ; 0  6
   [a1] or      .d2     b0, a0, b0                                      ; 0  7

l_prce_0:

        b       .s2     b3                                              ; 1  0
        mvc     .s2     b0, ier                                         ; 1  1
        mvc     .s2     b1, csr                                         ; 1  2
        nop             1                                               ; 1  3
        nop             1                                               ; 1  4
        nop             1                                               ; 1  5
        nop             1                                               ; 1  6
        nop             1                                               ; 1  7

;-----------------------------------------------------------------------------
;; !: fn: void os_core_initialize_ll()
;; - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
;; !: d: Функция низкоуровневой инициализации системы. В этой функции
;; !: d: инициализируются регистры процессора и некоторые переменные ядра
;; !: d: операционной системы.
;; !: -:
;-----------------------------------------------------------------------------

        .sect           ".os_init_ep"

_os_core_initialize_ll__Fv:

        mvk     .s1     0, a0                                           ; 0  0
        mvc     .s2     a0, istp                                        ; 0  1
        mvc     .s2     a0, amr                                         ; 0  2
        mvc     .s2     a0, ier                                         ; 0  3
        mvc     .s2     a0, irp                                         ; 0  4
        mvc     .s2     a0, nrp                                         ; 0  5
        mvk     .s1     -1, a0                                          ; 0  6
        mvc     .s2     a0, icr                                         ; 0  7

        mvkl    .s2     0x00000000, b0                                  ; 1  0
     || mvk     .s1     0x0300, a0                                      ; 1  1
        mvkh    .s2     0x01840000, b0                                  ; 1  2
        stw     .d2     a0, *b0                                         ; 1  3
        nop             4                                               ; 1  4
        nop             4                                               ; 1  5
        nop             4                                               ; 1  6
        nop             4                                               ; 1  7

        ; Initialize OS core variables
        mvkl    .s1     _os_interrupt_null_vector_ll__Fv, a0            ; 0  0
     || mvkl    .s2     _v_os_interrupt_vector_01_NMI, b0               ; 0  1
        mvkh    .s1     _os_interrupt_null_vector_ll__Fv, a0            ; 0  2
     || mvkh    .s2     _v_os_interrupt_vector_01_NMI, b0               ; 0  3
        stw     .d2     a0, *b0                                         ; 0  4
        mvkl    .s2     _v_os_interrupt_vector_05, b0                   ; 0  5
        mvkh    .s2     _v_os_interrupt_vector_05, b0                   ; 0  6
        stw     .d2     a0, *b0                                         ; 0  7
        mvkl    .s2     _v_os_interrupt_vector_06, b0                   ; 1  0
        mvkh    .s2     _v_os_interrupt_vector_06, b0                   ; 1  1
        stw     .d2     a0, *b0                                         ; 1  2
        mvkl    .s2     _v_os_interrupt_vector_07, b0                   ; 1  3
        mvkh    .s2     _v_os_interrupt_vector_07, b0                   ; 1  4
        stw     .d2     a0, *b0                                         ; 1  5
        mvkl    .s2     _v_os_interrupt_vector_08, b0                   ; 1  6
        mvkh    .s2     _v_os_interrupt_vector_08, b0                   ; 1  7
        stw     .d2     a0, *b0                                         ; 2  0
        mvkl    .s2     _v_os_interrupt_vector_09, b0                   ; 2  1
        mvkh    .s2     _v_os_interrupt_vector_09, b0                   ; 2  2
        stw     .d2     a0, *b0                                         ; 2  3
        mvkl    .s2     _v_os_interrupt_vector_10, b0                   ; 2  4
        mvkh    .s2     _v_os_interrupt_vector_10, b0                   ; 2  5
        stw     .d2     a0, *b0                                         ; 2  6
        mvkl    .s2     _v_os_interrupt_vector_11, b0                   ; 2  7
        mvkh    .s2     _v_os_interrupt_vector_11, b0                   ; 3  0
        stw     .d2     a0, *b0                                         ; 3  1
        mvkl    .s2     _v_os_interrupt_vector_12, b0                   ; 3  2
        mvkh    .s2     _v_os_interrupt_vector_12, b0                   ; 3  3
        stw     .d2     a0, *b0                                         ; 3  4
        mvkl    .s2     _v_os_interrupt_vector_13, b0                   ; 3  5
        mvkh    .s2     _v_os_interrupt_vector_13, b0                   ; 3  6
        stw     .d2     a0, *b0                                         ; 3  7
        mvkl    .s2     _v_os_interrupt_vector_14, b0                   ; 4  0
        mvkh    .s2     _v_os_interrupt_vector_14, b0                   ; 4  1
        stw     .d2     a0, *b0                                         ; 4  2
        mvkl    .s2     _v_os_interrupt_vector_15, b0                   ; 4  3
        mvkh    .s2     _v_os_interrupt_vector_15, b0                   ; 4  4
        stw     .d2     a0, *b0                                         ; 4  5
        mvkl    .s1     0x0000, a0                                      ; 4  6
     || mvkl    .s2     _v_os_current_process, b0                       ; 4  7
        mvkh    .s1     0x0000, a0                                      ; 5  0
     || mvkh    .s2     _v_os_current_process, b0                       ; 5  1
        stw     .d2     a0, *b0                                         ; 5  2
        mvkl    .s2     _v_os_process_ring, b0                          ; 5  3
        mvkh    .s2     _v_os_process_ring, b0                          ; 5  4
        stw     .d2     a0, *b0                                         ; 5  5
        mvkl    .s2     _v_os_core_call, b0                             ; 5  6
        mvkh    .s2     _v_os_core_call, b0                             ; 5  7
        stw     .d2     a0, *b0                                         ; 6  0
        mvkl    .s2     _v_os_process_count, b0                         ; 6  1
        mvkh    .s2     _v_os_process_count, b0                         ; 6  2
        stw     .d2     a0, *b0                                         ; 6  3
        mvkl    .s2     _v_os_core_heap, b0                             ; 6  4
        mvkh    .s2     _v_os_core_heap, b0                             ; 6  5
        stw     .d2     a0, *b0                                         ; 6  6
     || nop             1                                               ; 6  7
        
        ; Setup OS core stack pointer
        mvkl    .s2     _OS_STACK_END, b15                              ; 7  0
        mvkh    .s2     _OS_STACK_END, b15                              ; 7  1
        sub     .d2     b15, 8, b15                                     ; 7  2

        ; Call hi level initialization
        mvkl    .s2     _os_initialize_core__Fv, b3                     ; 7  3
        mvkh    .s2     _os_initialize_core__Fv, b3                     ; 7  4
        b       .s2     b3                                              ; 7  5
        nop             4                                               ; 7  6
        nop             1                                               ; 7  7

;-----------------------------------------------------------------------------
