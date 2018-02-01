;; -- DO NOT REMOVE ----------------------------------------------------------
;; !: arch: tms320c6457
;; !: sarc: all
;; - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
;; !: codepage: cp866
;; !: d: Модуль содержит исходный код первичного загрузчика операционной
;; !: d: системы для процессоров c6457.
;; !: -:
;; ---------------------------------------------------------------------------

        .sect           ".os_loader"

; -- Definitions -------------------------------------------------------------

        .asg            0x01845028, REG_L1PINV
        .asg            0x01845048, REG_L1DINV

        .asg            0x00900400, OS_ENTRY_POINT
        .asg            0xb0000000, OS_FWMEM_ADDRESS

        .asg            0x3046494c, LIF_ID
        .asg            0xff000001, LIF_CONTENT

        .def            _c_int00

; -- OS loader entry global entry point --------------------------------------

_c_int00:
os_loader_start:

        b       .s2     l_0                                             ; 0  0
        mvc     .s2     csr, b0                                         ; 0  1
        and     .d2     -2, b0, b0                                      ; 0  2
        mvc     .s2     b0, csr                                         ; 0  3
        nop             1                                               ; 0  4
        nop             1                                               ; 0  5
l_0:
        nop             1                                               ; 0  6
        nop             1                                               ; 0  7

; -- Entry point -------------------------------------------------------------

os_loader_entry_point:

        ; Clear registers
        mvk     .s1     0, a0                                           ; 1  0
;        mvc     .s2     a0, istp                                        ; 1  1
        nop             1                                               ; 1  1
        mvc     .s2     a0, amr                                         ; 1  2
        mvc     .s2     a0, ier                                         ; 1  3
        mvc     .s2     a0, irp                                         ; 1  4
        mvc     .s2     a0, nrp                                         ; 1  5
        mvk     .s1     -1, a0                                          ; 1  6
        mvc     .s2     a0, icr                                         ; 1  7

        ; Invalidate L1D and L1P caches
        mvkl    .s1     REG_L1PINV, a0                                  ; 2  0
     || mvkl    .s2     REG_L1DINV, b0                                  ; 2  1
        mvkh    .s1     REG_L1PINV, a0                                  ; 2  2
     || mvkh    .s2     REG_L1DINV, b0                                  ; 2  3
        mvk     .s1     1, a1                                           ; 2  4
     || mvk     .s2     1, b1                                           ; 2  5
        stw     .d1     a1, *a0                                         ; 2  6
     || stw     .d2     b1, *b0                                         ; 2  7

os_loader_cache_wait_invalidation:

        ; Waiting for invalidation were ended
        ldw     .d1     *a0, a1                                         ; 3  0
     || ldw     .d2     *b0, b1                                         ; 3  1
        nop             4                                               ; 3  2
   [a1] b       .s2     os_loader_cache_wait_invalidation               ; 3  3
   [b1] b       .s2     os_loader_cache_wait_invalidation               ; 3  4
        nop             2                                               ; 3  5
        nop             2                                               ; 3  6
        nop             1                                               ; 3  7
        
        ; Waiting ~100 million takts before PO loading
        mvkl    .s2     0x00000000, b0                                  ; 4  0
     || mvkl    .s1     os_loader_wait0, a0                             ; 4  1
        mvkh    .s2     0x01000000, b0                                  ; 4  2
     || mvkh    .s1     os_loader_wait0, a0                             ; 4  3
os_loader_wait0:
        addk    .s2     -1, b0                                          ; 4  4
   [b0] bnop    .s2     a0, 5                                           ; 4  5
        nop             1                                               ; 4  6
        nop             1                                               ; 4  7

        nop             1                                               ; 5  0
     || nop             1                                               ; 5  1
     || nop             1                                               ; 5  2
     || nop             1                                               ; 5  3
     || nop             1                                               ; 5  4
     || nop             1                                               ; 5  5
     || nop             1                                               ; 5  6
     || nop             1                                               ; 5  7

        nop             1                                               ; 6  0
     || nop             1                                               ; 6  1
     || nop             1                                               ; 6  2
     || nop             1                                               ; 6  3
     || nop             1                                               ; 6  4
     || nop             1                                               ; 6  5
     || nop             1                                               ; 6  6
     || nop             1                                               ; 6  7

        b       .s2     os_loader_load_core_file                        ; 7  0
        mvkl    .s2     os_loader_read_4b, b16                          ; 7  1
     || mvk     .s1     36, a12                                         ; 7  2
        mvkh    .s2     os_loader_read_4b, b16                          ; 7  3
     || mvk     .s1     16, a13                                         ; 7  4
        mvkl    .s2     OS_FWMEM_ADDRESS, b17                           ; 7  5
        mvkh    .s2     OS_FWMEM_ADDRESS, b17                           ; 7  6
        nop             1                                               ; 7  7

; -- Read 4 bytes from flash at address A16 to register A24 ------------------

os_loader_read_4b:

        clr     .s1     a16, 24, 31, a16                                ; 8  0
        shl     .s1     a16, 2, a16                                     ; 8  1
        or      .l1     a16, b17, a16                                   ; 8  2
        ldw     .d1     *+a16[0], a24                                   ; 8  3
        ldw     .d1     *+a16[1], a25                                   ; 8  4
        ldw     .d1     *+a16[2], a26                                   ; 8  5
        ldw     .d1     *+a16[3], a27                                   ; 8  6
        nop             1                                               ; 8  7

        clr     .s1     a24, 8,  31, a24                                ; 9  0
        clr     .s1     a25, 16, 31, a25                                ; 9  1
        clr     .s1     a26, 24, 31, a26                                ; 9  2
        clr     .s1     a27, 0,  23, a27                                ; 9  3
        b       .s2     b3                                              ; 9  4
        clr     .s1     a25, 0,  7,  a25                                ; 9  5
        clr     .s1     a26, 0,  15, a26                                ; 9  6
        or      .l1     a24, a25, a24                                   ; 9  7

        or      .l1     a26, a27, a26                                   ; 10 0
        or      .l1     a24, a26, a24                                   ; 10 1
        nop             1                                               ; 10 2
        nop             1                                               ; 10 3
        nop             1                                               ; 10 4
        nop             1                                               ; 10 5
        nop             1                                               ; 10 6
        nop             1                                               ; 10 7

        nop             1                                               ; 11 0
     || nop             1                                               ; 11 1
     || nop             1                                               ; 11 2
     || nop             1                                               ; 11 3
     || nop             1                                               ; 11 4
     || nop             1                                               ; 11 5
     || nop             1                                               ; 11 6
     || nop             1                                               ; 11 7

        nop             1                                               ; 12 0
     || nop             1                                               ; 12 1
     || nop             1                                               ; 12 2
     || nop             1                                               ; 12 3
     || nop             1                                               ; 12 4
     || nop             1                                               ; 12 5
     || nop             1                                               ; 12 6
     || nop             1                                               ; 12 7

        nop             1                                               ; 13 0
     || nop             1                                               ; 13 1
     || nop             1                                               ; 13 2
     || nop             1                                               ; 13 3
     || nop             1                                               ; 13 4
     || nop             1                                               ; 13 5
     || nop             1                                               ; 13 6
     || nop             1                                               ; 13 7

        nop             1                                               ; 14 0
     || nop             1                                               ; 14 1
     || nop             1                                               ; 14 2
     || nop             1                                               ; 14 3
     || nop             1                                               ; 14 4
     || nop             1                                               ; 14 5
     || nop             1                                               ; 14 6
     || nop             1                                               ; 14 7

; -- Load core-*.lif file ----------------------------------------------------

os_loader_load_core_file:

        ; Load start address of core image file
        mvkl    .s1     os_loader__core_file_ptr, a4                    ; 15 0
        mvkh    .s1     os_loader__core_file_ptr, a4                    ; 15 1
        ldw     .d1     *a4, a4                                         ; 15 2
        nop             4                                               ; 15 3
        ; Check file identificator and file data type
        add     .l1     a4, 0, a16 ; - - - - - - - - - - - - - - - - - -; 15 4
        b       .s2     b16 ;  - - - - - - - - - - - - - - - - - - - - -; 15 5
        addkpc  .s2     l_rd0, b3, 4 ; - - - - - - - - - - - - - - - - -; 15 6
l_rd0:  add     .l2     a24, 0, b5 ; - - - - - - - - - - - - - - - - - -; 15 7

        add     .l1     a4, 4, a16 ; - - - - - - - - - - - - - - - - - -; 16 0
        b       .s2     b16 ;  - - - - - - - - - - - - - - - - - - - - -; 16 1
        addkpc  .s2     l_rd1, b3, 4 ; - - - - - - - - - - - - - - - - -; 16 2
l_rd1:  add     .l2     a24, 0, b6 ; - - - - - - - - - - - - - - - - - -; 16 3

        mvkl    .s1     LIF_ID, a5                                      ; 16 4
        mvkh    .s1     LIF_ID, a5                                      ; 16 5
        
        mvkl    .s1     LIF_CONTENT, a6                                 ; 16 6
        mvkh    .s1     LIF_CONTENT, a6                                 ; 16 7
        cmpeq   .l1     a5, b5, a0                                      ; 17 0
        cmpeq   .l1     a6, b6, a1                                      ; 17 1
  [!a0] bnop    .s2     os_loader_fail, 5                               ; 17 2
  [!a1] bnop    .s2     os_loader_fail, 5                               ; 17 3
        ; Form start address for sections header
        mvk     .s1     128, a5                                         ; 17 4
        add     .l1     a5, a4, a5                                      ; 17 5

        ; Load section count
        add     .l1     a4, a12, a16 ; - - - - - - - - - - - - - - - - -; 17 6
        b       .s2     b16 ;  - - - - - - - - - - - - - - - - - - - - -; 17 7
        addkpc  .s2     l_rd2, b3, 4 ; - - - - - - - - - - - - - - - - -; 18 0
l_rd2:  add     .l2     a24, 0, b5 ; - - - - - - - - - - - - - - - - - -; 18 1

        add     .l1     0, b5, a0                                       ; 18 2
        ; Form start address for data
        shl     .s2     b5, 5, b6                                       ; 18 3
        add     .l1     a5, b6, a6                                      ; 18 4

os_loader_section_loop:

        ; Load current section length and physical address
        add     .l1     a5, 4, a16 ; - - - - - - - - - - - - - - - - - -; 18 5
        b       .s2     b16 ;  - - - - - - - - - - - - - - - - - - - - -; 18 6
        addkpc  .s2     l_rd3, b3, 4 ; - - - - - - - - - - - - - - - - -; 18 7
l_rd3:  add     .l2     a24, 0, b0 ; - - - - - - - - - - - - - - - - - -; 19 0

        add     .l1     a5, a13, a16 ; - - - - - - - - - - - - - - - - -; 19 1
        b       .s2     b16 ;  - - - - - - - - - - - - - - - - - - - - -; 19 2
        addkpc  .s2     l_rd4, b3, 4 ; - - - - - - - - - - - - - - - - -; 19 3
l_rd4:  add     .l2     a24, 0, b9 ; - - - - - - - - - - - - - - - - - -; 19 4
        
os_loader_data_loop:

        add     .l1     a6, 0, a16 ; - - - - - - - - - - - - - - - - - -; 19 5
        b       .s2     b16 ;  - - - - - - - - - - - - - - - - - - - - -; 19 6
        addkpc  .s2     l_rd5, b3, 4 ; - - - - - - - - - - - - - - - - -; 19 7
l_rd5:  add     .l1     a24, 0, a8 ; - - - - - - - - - - - - - - - - - -; 20 0
        addk    .s1     4, a6                                           ; 20 1

        stw     .d2     a8, *b9++[1]                                    ; 20 2
        sub     .d2     b0, 4, b0                                       ; 20 3
   [b0] bnop    .s2     os_loader_data_loop, 5                          ; 20 4
        addk    .s1     32, a5                                          ; 20 5
        sub     .d1     a0, 1, a0                                       ; 20 6
   [a0] bnop    .s2     os_loader_section_loop, 5                       ; 20 7

; -- Clear all registers -----------------------------------------------------

        mvk     .s1     0, a0                                           ; 21 0
     || mvk     .s2     0, b0                                           ; 21 1
        mvk     .s1     0, a1                                           ; 21 2
     || mvk     .s2     0, b1                                           ; 21 3
        mvk     .s1     0, a2                                           ; 21 4
     || mvk     .s2     0, b2                                           ; 21 5
        mvk     .s1     0, a3                                           ; 21 6
     || nop             1                                               ; 21 7

        mvk     .s1     0, a4                                           ; 22 0
     || mvk     .s2     0, b4                                           ; 22 1
        mvk     .s1     0, a5                                           ; 22 2
     || mvk     .s2     0, b5                                           ; 22 3
        mvk     .s1     0, a6                                           ; 22 4
     || mvk     .s2     0, b6                                           ; 22 5
        mvk     .s1     0, a7                                           ; 22 6
     || mvk     .s2     0, b7                                           ; 22 7

        mvk     .s1     0, a8                                           ; 23 0
     || mvk     .s2     0, b8                                           ; 23 1
        mvk     .s1     0, a9                                           ; 23 2
     || mvk     .s2     0, b9                                           ; 23 3
        mvk     .s1     0, a10                                          ; 23 4
     || mvk     .s2     0, b10                                          ; 23 5
        mvk     .s1     0, a11                                          ; 23 6
     || mvk     .s2     0, b11                                          ; 23 7

        mvk     .s1     0, a12                                          ; 24 0
     || mvk     .s2     0, b12                                          ; 24 1
        mvk     .s1     0, a13                                          ; 24 2
     || mvk     .s2     0, b13                                          ; 24 3
        mvk     .s1     0, a14                                          ; 24 4
     || mvk     .s2     0, b14                                          ; 24 5
        mvk     .s1     0, a15                                          ; 24 6
     || mvk     .s2     0, b15                                          ; 24 7

        mvk     .s1     0, a16                                          ; 25 0
     || mvk     .s2     0, b16                                          ; 25 1
        mvk     .s1     0, a17                                          ; 25 2
     || mvk     .s2     0, b17                                          ; 25 3
        mvk     .s1     0, a18                                          ; 25 4
     || mvk     .s2     0, b18                                          ; 25 5
        mvk     .s1     0, a19                                          ; 25 6
     || mvk     .s2     0, b19                                          ; 25 7

        mvk     .s1     0, a20                                          ; 26 0
     || mvk     .s2     0, b20                                          ; 26 1
        mvk     .s1     0, a21                                          ; 26 2
     || mvk     .s2     0, b21                                          ; 26 3
        mvk     .s1     0, a22                                          ; 26 4
     || mvk     .s2     0, b22                                          ; 26 5
        mvk     .s1     0, a23                                          ; 26 6
     || mvk     .s2     0, b23                                          ; 26 7

        mvk     .s1     0, a24                                          ; 27 0
     || mvk     .s2     0, b24                                          ; 27 1
        mvk     .s1     0, a25                                          ; 27 2
     || mvk     .s2     0, b25                                          ; 27 3
        mvk     .s1     0, a26                                          ; 27 4
     || mvk     .s2     0, b26                                          ; 27 5
        mvk     .s1     0, a27                                          ; 27 6
     || mvk     .s2     0, b27                                          ; 27 7

        mvk     .s1     0, a28                                          ; 28 0
     || mvk     .s2     0, b28                                          ; 28 1
        mvk     .s1     0, a29                                          ; 28 2
     || mvk     .s2     0, b29                                          ; 28 3
        mvk     .s1     0, a30                                          ; 28 4
     || mvk     .s2     0, b30                                          ; 28 5
        mvk     .s1     0, a31                                          ; 28 6
     || mvk     .s2     0, b31                                          ; 28 7

; -- Jump to OS entry point --------------------------------------------------

        mvkl    .s2     OS_ENTRY_POINT, b3                              ; 29 0
        mvkh    .s2     OS_ENTRY_POINT, b3                              ; 29 1
        b       .s2     b3                                              ; 29 2
        mvk     .s2     0, b3                                           ; 29 3
        nop             1                                               ; 29 4
        nop             1                                               ; 29 5
        nop             1                                               ; 29 6
        nop             1                                               ; 29 7

; -- Loading fail code -------------------------------------------------------

os_loader_fail:

        idle                                                            ; 30 0
        b       .s2     os_loader_fail                                  ; 30 1
        nop             1                                               ; 30 2
        nop             1                                               ; 30 3
        nop             1                                               ; 30 4
        nop             1                                               ; 30 5
        nop             1                                               ; 30 6
        nop             1                                               ; 30 7

; -- Firmware location info --------------------------------------------------

        nop             1                                               ; 31 0
        nop             1                                               ; 31 1
        nop             1                                               ; 31 2
        nop             1                                               ; 31 3
        nop             1                                               ; 31 4
        nop             1                                               ; 31 5
        nop             1                                               ; 31 6

os_loader__core_file_ptr:

        nop             1                                               ; 31 7

