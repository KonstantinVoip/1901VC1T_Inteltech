;; -- DO NOT REMOVE ----------------------------------------------------------
;; !: arch: tms320c64xx
;; !: sarc: m448-15-comm, m448-15-main, m448-15-iface
;; - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
;; !: codepage: cp866
;; !: d: Модуль содержит исходный код первичного загрузчика операционной
;; !: d: системы.
;; !: -:
;; ---------------------------------------------------------------------------

; -- Void interrupt table ----------------------------------------------------

        .sect           ".os_loader"

        .def            _c_int00

; -- OS loader entry global entry point --------------------------------------

_c_int00:
os_loader_start:

        b       .s2     l_0                                             ; 0  0
        mvc     .s2     csr, b0                                         ; 0  1
        and     .d2     -2, b0, b0                                      ; 0  2
        mvc     .s2     b0, csr                                         ; 0  3
        mvkl    .s2     os_loader_entry_point, b0                       ; 0  4
        mvkh    .s2     os_loader_entry_point, b0                       ; 0  5

l_0:

        b       .s2     b0                                              ; 0  6
        nop             5                                               ; 0  7

        b       .s2     nrp                                             ; 1  0
        nop             1                                               ; 1  1
        nop             1                                               ; 1  2
        nop             1                                               ; 1  3
        nop             1                                               ; 1  4
        nop             1                                               ; 1  5
        nop             1                                               ; 1  6
        nop             1                                               ; 1  7

        b       .s2     irp                                             ; 2  0
        nop             1                                               ; 2  1
        nop             1                                               ; 2  2
        nop             1                                               ; 2  3
        nop             1                                               ; 2  4
        nop             1                                               ; 2  5
        nop             1                                               ; 2  6
        nop             1                                               ; 2  7

        b       .s2     irp                                             ; 3  0
        nop             1                                               ; 3  1
        nop             1                                               ; 3  2
        nop             1                                               ; 3  3
        nop             1                                               ; 3  4
        nop             1                                               ; 3  5
        nop             1                                               ; 3  6
        nop             1                                               ; 3  7

        b       .s2     irp                                             ; 4  0
        nop             1                                               ; 4  1
        nop             1                                               ; 4  2
        nop             1                                               ; 4  3
        nop             1                                               ; 4  4
        nop             1                                               ; 4  5
        nop             1                                               ; 4  6
        nop             1                                               ; 4  7

        b       .s2     irp                                             ; 5  0
        nop             1                                               ; 5  1
        nop             1                                               ; 5  2
        nop             1                                               ; 5  3
        nop             1                                               ; 5  4
        nop             1                                               ; 5  5
        nop             1                                               ; 5  6
        nop             1                                               ; 5  7

        b       .s2     irp                                             ; 6  0
        nop             1                                               ; 6  1
        nop             1                                               ; 6  2
        nop             1                                               ; 6  3
        nop             1                                               ; 6  4
        nop             1                                               ; 6  5
        nop             1                                               ; 6  6
        nop             1                                               ; 6  7

        b       .s2     irp                                             ; 7  0
        nop             1                                               ; 7  1
        nop             1                                               ; 7  2
        nop             1                                               ; 7  3
        nop             1                                               ; 7  4
        nop             1                                               ; 7  5
        nop             1                                               ; 7  6
        nop             1                                               ; 7  7

        b       .s2     irp                                             ; 8  0
        nop             1                                               ; 8  1
        nop             1                                               ; 8  2
        nop             1                                               ; 8  3
        nop             1                                               ; 8  4
        nop             1                                               ; 8  5
        nop             1                                               ; 8  6
        nop             1                                               ; 8  7

        b       .s2     irp                                             ; 9  0
        nop             1                                               ; 9  1
        nop             1                                               ; 9  2
        nop             1                                               ; 9  3
        nop             1                                               ; 9  4
        nop             1                                               ; 9  5
        nop             1                                               ; 9  6
        nop             1                                               ; 9  7

        b       .s2     irp                                             ; 10 0
        nop             1                                               ; 10 1
        nop             1                                               ; 10 2
        nop             1                                               ; 10 3
        nop             1                                               ; 10 4
        nop             1                                               ; 10 5
        nop             1                                               ; 10 6
        nop             1                                               ; 10 7

        b       .s2     irp                                             ; 11 0
        nop             1                                               ; 11 1
        nop             1                                               ; 11 2
        nop             1                                               ; 11 3
        nop             1                                               ; 11 4
        nop             1                                               ; 11 5
        nop             1                                               ; 11 6
        nop             1                                               ; 11 7

        b       .s2     irp                                             ; 12 0
        nop             1                                               ; 12 1
        nop             1                                               ; 12 2
        nop             1                                               ; 12 3
        nop             1                                               ; 12 4
        nop             1                                               ; 12 5
        nop             1                                               ; 12 6
        nop             1                                               ; 12 7

        b       .s2     irp                                             ; 13 0
        nop             1                                               ; 13 1
        nop             1                                               ; 13 2
        nop             1                                               ; 13 3
        nop             1                                               ; 13 4
        nop             1                                               ; 13 5
        nop             1                                               ; 13 6
        nop             1                                               ; 13 7

        b       .s2     irp                                             ; 14 0
        nop             1                                               ; 14 1
        nop             1                                               ; 14 2
        nop             1                                               ; 14 3
        nop             1                                               ; 14 4
        nop             1                                               ; 14 5
        nop             1                                               ; 14 6
        nop             1                                               ; 14 7

        b       .s2     irp                                             ; 15 0
        nop             1                                               ; 15 1
        nop             1                                               ; 15 2
        nop             1                                               ; 15 3
        nop             1                                               ; 15 4
        nop             1                                               ; 15 5
        nop             1                                               ; 15 6
        nop             1                                               ; 15 7

; -- Entry point -------------------------------------------------------------

os_loader_entry_point:

        ; Clear registers
        mvk     .s1     0, a0                                           ; 0  0
        mvc     .s2     a0, istp                                        ; 0  1
        mvc     .s2     a0, amr                                         ; 0  2
        mvc     .s2     a0, ier                                         ; 0  3
        mvc     .s2     a0, irp                                         ; 0  4
        mvc     .s2     a0, nrp                                         ; 0  5
        mvk     .s1     -1, a0                                          ; 0  6
        mvc     .s2     a0, icr                                         ; 0  7

        ; Invalidate L1D and L1P caches
        mvkl    .s2     0x00000000, b0                                  ; 1  0
     || mvk     .s1     0x0300, a0                                      ; 1  1
        mvkh    .s2     0x01840000, b0                                  ; 1  2
        stw     .d2     a0, *b0                                         ; 1  3
        nop             4                                               ; 1  4
        nop             4                                               ; 1  5
        nop             4                                               ; 1  6
        nop             4                                               ; 1  7

        ; Waiting ~100 million takts before PO loading
        mvkl    .s2     0x00000000, b0                                  ; 2  0
     || mvkl    .s1     os_loader_wait0, a0                             ; 2  1
        mvkh    .s2     0x01000000, b0                                  ; 2  2
     || mvkh    .s1     os_loader_wait0, a0                             ; 2  3

os_loader_wait0:

        addk    .s2     -1, b0                                          ; 2  4
   [b0] bnop    .s2     a0, 5                                           ; 2  5
        nop             1                                               ; 2  6
        nop             1                                               ; 2  7

        nop             1                                               ; 3  0
     || nop             1                                               ; 3  1
     || nop             1                                               ; 3  2
     || nop             1                                               ; 3  3
     || nop             1                                               ; 3  4
     || nop             1                                               ; 3  5
     || nop             1                                               ; 3  6
     || nop             1                                               ; 3  7

        nop             1                                               ; 4  0
     || nop             1                                               ; 4  1
     || nop             1                                               ; 4  2
     || nop             1                                               ; 4  3
     || nop             1                                               ; 4  4
     || nop             1                                               ; 4  5
     || nop             1                                               ; 4  6
     || nop             1                                               ; 4  7

os_loader_load_core_file:

        ; Load start address of core image file
        mvkl    .s1     os_loader__core_file_ptr, a4                    ; 5  0
        mvkh    .s1     os_loader__core_file_ptr, a4                    ; 5  1
        ldw     .d1     *a4, a4                                         ; 5  2
        nop             4                                               ; 5  3
        ; Check file identificator and file data type
        ldw     .d1     *+a4[0], b5                                     ; 5  4
        ldw     .d1     *+a4[1], b6                                     ; 5  5
        mvkl    .s1     0x494c, a5                                      ; 5  6
        mvkh    .s1     0x3046494c, a5                                  ; 5  7
        
        mvkl    .s1     0x0001, a6                                      ; 6  0
        mvkh    .s1     0xff000001, a6                                  ; 6  1
        cmpeq   .l1     a5, b5, a0                                      ; 6  2
        cmpeq   .l1     a6, b6, a1                                      ; 6  3
  [!a0] bnop    .s2     os_loader_fail, 5                               ; 6  4
  [!a1] bnop    .s2     os_loader_fail, 5                               ; 6  5
        ; Form start address for sections header
        mvk     .s1     128, a5                                         ; 6  6
        add     .l1     a5, a4, a5                                      ; 6  7

        ; Load section count
        ldw     .d1     *+a4[9], b5                                     ; 7  0
        nop             4                                               ; 7  1
        add     .l1     0, b5, a0                                       ; 7  2
        ; Form start address for data
        shl     .s2     b5, 5, b6                                       ; 7  3
        add     .l1     a5, b6, a6                                      ; 7  4

os_loader_section_loop:

        ; Load current section length and physical address
        ldw     .d1     *+a5[1], b0                                     ; 7  5
        ldw     .d1     *+a5[4], b9                                     ; 7  6
        nop             4                                               ; 7  7
        
os_loader_data_loop:

        ldw     .d1     *a6++[1], a8                                    ; 8  0
        nop             4                                               ; 8  1
        stw     .d2     a8, *b9++[1]                                    ; 8  2
        sub     .d2     b0, 4, b0                                       ; 8  3
   [b0] bnop    .s2     os_loader_data_loop, 5                          ; 8  4
        addk    .s1     32, a5                                          ; 8  5
        sub     .d1     a0, 1, a0                                       ; 8  6
   [a0] bnop    .s2     os_loader_section_loop, 5                       ; 8  7

; -- Clear first 16 registers ------------------------------------------------

        mvk     .s1     0, a0                                           ; 9  0
        mvk     .s1     0, a1                                           ; 9  1
        mvk     .s1     0, a2                                           ; 9  2
        mvk     .s1     0, a3                                           ; 9  3
        mvk     .s1     0, a4                                           ; 9  4
        mvk     .s1     0, a5                                           ; 9  5
        mvk     .s1     0, a6                                           ; 9  6
        mvk     .s1     0, a7                                           ; 9  7

        mvk     .s1     0, a8                                           ; 10 0
        mvk     .s1     0, a9                                           ; 10 1
        mvk     .s1     0, a10                                          ; 10 2
        mvk     .s1     0, a11                                          ; 10 3
        mvk     .s1     0, a12                                          ; 10 4
        mvk     .s1     0, a13                                          ; 10 5
        mvk     .s1     0, a14                                          ; 10 6
        mvk     .s1     0, a15                                          ; 10 7

        mvk     .s2     0, b0                                           ; 11 0
        mvk     .s2     0, b1                                           ; 11 1
        mvk     .s2     0, b2                                           ; 11 2
        nop             1                                               ; 11 3
        mvk     .s2     0, b4                                           ; 11 4
        mvk     .s2     0, b5                                           ; 11 5
        mvk     .s2     0, b6                                           ; 11 6
        mvk     .s2     0, b7                                           ; 11 7

        mvk     .s2     0, b8                                           ; 12 0
        mvk     .s2     0, b9                                           ; 12 1
        mvk     .s2     0, b10                                          ; 12 2
        mvk     .s2     0, b11                                          ; 12 3
        mvk     .s2     0, b12                                          ; 12 4
        mvk     .s2     0, b13                                          ; 12 5
        mvk     .s2     0, b14                                          ; 12 6
        mvk     .s2     0, b15                                          ; 12 7

; -- Jump to OS entry point --------------------------------------------------

        mvkl    .s2     0x0400, b3                                      ; 13 0
        mvkh    .s2     0x0000, b3                                      ; 13 1
        b       .s2     b3                                              ; 13 2
        mvk     .s2     0, b3                                           ; 13 3
        nop             1                                               ; 13 4
        nop             1                                               ; 13 5
        nop             1                                               ; 13 6
        nop             1                                               ; 13 7

; -- Loading fail code -------------------------------------------------------

os_loader_fail:

        idle                                                            ; 14 0
        b       .s2     os_loader_fail                                  ; 14 1
        nop             1                                               ; 14 2
        nop             1                                               ; 14 3
        nop             1                                               ; 14 4
        nop             1                                               ; 14 5
        nop             1                                               ; 14 6
        nop             1                                               ; 14 7

; -- Firmware location info --------------------------------------------------

        nop             1                                               ; 15 0
        nop             1                                               ; 15 1
        nop             1                                               ; 15 2
        nop             1                                               ; 15 3
        nop             1                                               ; 15 4
        nop             1                                               ; 15 5
        nop             1                                               ; 15 6

os_loader__core_file_ptr:

        nop             1                                               ; 15 7

