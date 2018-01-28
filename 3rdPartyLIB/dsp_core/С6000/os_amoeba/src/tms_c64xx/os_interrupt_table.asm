;; -- DO NOT REMOVE ----------------------------------------------------------
;; !: arch: tms320c64xx
;; !: sarc: all
;; - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
;; !: codepage: cp866
;; !: d: ����� ᮤ�ন� ⠡���� ��ࠡ��稪�� ���뢠���.
;; !: -:
;; ---------------------------------------------------------------------------

        .sect           ".os_ivect"

; -- Defines -----------------------------------------------------------------

        .asg            b15, sp

; -- Import global variables -------------------------------------------------

        .global         os_process_switch_ll
        .global         _os_interrupt_nmi_trigger_ll__Fv
        .global         _os_interrupt_trigger_ll__Fv
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

; -- Global symbols for touching ---------------------------------------------

        .def            ___os_touch____Fv

___os_touch____Fv:

; ----------------------------------------------------------------------------
; Reload OS if reset
; ----------------------------------------------------------------------------
os_int00:
 

        b       .s2     l_os_int00                                      ; 0  0
        mvc     .s2     csr, b0                                         ; 0  1
        and     .d2     -2, b0, b0                                      ; 0  2
        mvc     .s2     b0, csr                                         ; 0  3
        mvkl    .s2     0x0400, b0                                      ; 0  4
        mvkh    .s2     0x0000, b0                                      ; 0  5

l_os_int00:

        b       .s2     b0                                              ; 0  6
        nop             5                                               ; 0  7

; ----------------------------------------------------------------------------
; NMI vector handler
; ----------------------------------------------------------------------------
os_int01_nmi:

        b       .s2     _os_interrupt_nmi_trigger_ll__Fv                ; 0  0
        nop             1                                               ; 0  1
        nop             1                                               ; 0  2
        nop             1                                               ; 0  3
        nop             1                                               ; 0  4
        nop             1                                               ; 0  5
        nop             1                                               ; 0  6
        nop             1                                               ; 0  7

; ----------------------------------------------------------------------------
; This vector is reserved
; ----------------------------------------------------------------------------
os_int02:

        b       .s2     irp                                             ; 0  0
        nop             1                                               ; 0  1
        nop             1                                               ; 0  2
        nop             1                                               ; 0  3
        nop             1                                               ; 0  4
        nop             1                                               ; 0  5
        nop             1                                               ; 0  6
        nop             1                                               ; 0  7

; ----------------------------------------------------------------------------
; This vector is reserved (used for interrupt 4 return code)
; ----------------------------------------------------------------------------
os_int03:
os_int04_end:

        ldw     .d2     *+sp[3], b13                                    ; 0  0
        nop             3                                               ; 0  1
        ldw     .d2     *+sp[2], b13                                    ; 0  2
        mvc     .s2     b13, irp                                        ; 0  3
        b       .s2     irp                                             ; 0  4
        addk    .s2     16, sp                                          ; 0  5
        nop             2                                               ; 0  6
        nop             2                                               ; 0  7

; ----------------------------------------------------------------------------
; Interrupt 04 (Mapped timer interrupt vector handler) { 18t }
; ----------------------------------------------------------------------------
os_int04:

        b       .s2     os_process_switch_ll                            ; 0  0
        addk    .s2     -16, sp                                         ; 0  1
        stw     .d2     b13, *+sp[2]                                    ; 0  2
        mvc     .s2     irp, b13                                        ; 0  3
        stw     .d2     b13, *+sp[3]                                    ; 0  4
        addkpc  .s2     os_int04_end, b13, 0                            ; 0  5
        nop             1                                               ; 0  6
        nop             1                                               ; 0  7

; ----------------------------------------------------------------------------
; Interrupt 05 vector handler
; ----------------------------------------------------------------------------
os_int05:

        b       .s2     _os_interrupt_trigger_ll__Fv                    ; 0  0
        addk    .s2     -16, sp                                         ; 0  1
        stw     .d2     b13, *+sp[2]                                    ; 0  2
        mvkl    .s2     _v_os_interrupt_vector_05, b13                  ; 0  3
        mvkh    .s2     _v_os_interrupt_vector_05, b13                  ; 0  4
        nop             1                                               ; 0  5
        nop             1                                               ; 0  6
        nop             1                                               ; 0  7

; ----------------------------------------------------------------------------
; Interrupt 06 vector handler
; ----------------------------------------------------------------------------
os_int06:

        b       .s2     _os_interrupt_trigger_ll__Fv                    ; 0  0
        addk    .s2     -16, sp                                         ; 0  1
        stw     .d2     b13, *+sp[2]                                    ; 0  2
        mvkl    .s2     _v_os_interrupt_vector_06, b13                  ; 0  3
        mvkh    .s2     _v_os_interrupt_vector_06, b13                  ; 0  4
        nop             1                                               ; 0  5
        nop             1                                               ; 0  6
        nop             1                                               ; 0  7

; ----------------------------------------------------------------------------
; Interrupt 07 vector handler
; ----------------------------------------------------------------------------
os_int07:

        b       .s2     _os_interrupt_trigger_ll__Fv                    ; 0  0
        addk    .s2     -16, sp                                         ; 0  1
        stw     .d2     b13, *+sp[2]                                    ; 0  2
        mvkl    .s2     _v_os_interrupt_vector_07, b13                  ; 0  3
        mvkh    .s2     _v_os_interrupt_vector_07, b13                  ; 0  4
        nop             1                                               ; 0  5
        nop             1                                               ; 0  6
        nop             1                                               ; 0  7

; ----------------------------------------------------------------------------
; Interrupt 08 vector handler
; ----------------------------------------------------------------------------
os_int08:

        b       .s2     _os_interrupt_trigger_ll__Fv                    ; 0  0
        addk    .s2     -16, sp                                         ; 0  1
        stw     .d2     b13, *+sp[2]                                    ; 0  2
        mvkl    .s2     _v_os_interrupt_vector_08, b13                  ; 0  3
        mvkh    .s2     _v_os_interrupt_vector_08, b13                  ; 0  4
        nop             1                                               ; 0  5
        nop             1                                               ; 0  6
        nop             1                                               ; 0  7

; ----------------------------------------------------------------------------
; Interrupt 09 vector handler
; ----------------------------------------------------------------------------
os_int09:

        b       .s2     _os_interrupt_trigger_ll__Fv                    ; 0  0
        addk    .s2     -16, sp                                         ; 0  1
        stw     .d2     b13, *+sp[2]                                    ; 0  2
        mvkl    .s2     _v_os_interrupt_vector_09, b13                  ; 0  3
        mvkh    .s2     _v_os_interrupt_vector_09, b13                  ; 0  4
        nop             1                                               ; 0  5
        nop             1                                               ; 0  6
        nop             1                                               ; 0  7

; ----------------------------------------------------------------------------
; Interrupt 10 vector handler
; ----------------------------------------------------------------------------
os_int10:

        b       .s2     _os_interrupt_trigger_ll__Fv                    ; 0  0
        addk    .s2     -16, sp                                         ; 0  1
        stw     .d2     b13, *+sp[2]                                    ; 0  2
        mvkl    .s2     _v_os_interrupt_vector_10, b13                  ; 0  3
        mvkh    .s2     _v_os_interrupt_vector_10, b13                  ; 0  4
        nop             1                                               ; 0  5
        nop             1                                               ; 0  6
        nop             1                                               ; 0  7

; ----------------------------------------------------------------------------
; Interrupt 11 vector handler
; ----------------------------------------------------------------------------
os_int11:

        b       .s2     _os_interrupt_trigger_ll__Fv                    ; 0  0
        addk    .s2     -16, sp                                         ; 0  1
        stw     .d2     b13, *+sp[2]                                    ; 0  2
        mvkl    .s2     _v_os_interrupt_vector_11, b13                  ; 0  3
        mvkh    .s2     _v_os_interrupt_vector_11, b13                  ; 0  4
        nop             1                                               ; 0  5
        nop             1                                               ; 0  6
        nop             1                                               ; 0  7

; ----------------------------------------------------------------------------
; Interrupt 12 vector handler
; ----------------------------------------------------------------------------
os_int12:

        b       .s2     _os_interrupt_trigger_ll__Fv                    ; 0  0
        addk    .s2     -16, sp                                         ; 0  1
        stw     .d2     b13, *+sp[2]                                    ; 0  2
        mvkl    .s2     _v_os_interrupt_vector_12, b13                  ; 0  3
        mvkh    .s2     _v_os_interrupt_vector_12, b13                  ; 0  4
        nop             1                                               ; 0  5
        nop             1                                               ; 0  6
        nop             1                                               ; 0  7

; ----------------------------------------------------------------------------
; Interrupt 13 vector handler
; ----------------------------------------------------------------------------
os_int13:

        b       .s2     _os_interrupt_trigger_ll__Fv                    ; 0  0
        addk    .s2     -16, sp                                         ; 0  1
        stw     .d2     b13, *+sp[2]                                    ; 0  2
        mvkl    .s2     _v_os_interrupt_vector_13, b13                  ; 0  3
        mvkh    .s2     _v_os_interrupt_vector_13, b13                  ; 0  4
        nop             1                                               ; 0  5
        nop             1                                               ; 0  6
        nop             1                                               ; 0  7

; ----------------------------------------------------------------------------
; Interrupt 14 vector handler
; ----------------------------------------------------------------------------
os_int14:

        b       .s2     _os_interrupt_trigger_ll__Fv                    ; 0  0
        addk    .s2     -16, sp                                         ; 0  1
        stw     .d2     b13, *+sp[2]                                    ; 0  2
        mvkl    .s2     _v_os_interrupt_vector_14, b13                  ; 0  3
        mvkh    .s2     _v_os_interrupt_vector_14, b13                  ; 0  4
        nop             1                                               ; 0  5
        nop             1                                               ; 0  6
        nop             1                                               ; 0  7

; ----------------------------------------------------------------------------
; Interrupt 15 vector handler
; ----------------------------------------------------------------------------
os_int15:

        b       .s2     _os_interrupt_trigger_ll__Fv                    ; 0  0
        addk    .s2     -16, sp                                         ; 0  1
        stw     .d2     b13, *+sp[2]                                    ; 0  2
        mvkl    .s2     _v_os_interrupt_vector_15, b13                  ; 0  3
        mvkh    .s2     _v_os_interrupt_vector_15, b13                  ; 0  4
        nop             1                                               ; 0  5
        nop             1                                               ; 0  6
        nop             1                                               ; 0  7

