;******************************************************************************
;                                         Copyright (C) 2010 RCZI
;***sss************************************************************************
            .def            _aswap32w__FPUiUi

_aswap32w__FPUiUi:
            and             b4, ~0x3, b0                ; 0  0
    ||      cmpeq           b4, 0x4, b1                 ; 0  1
    ||      mv              a4, b4                      ; 0  2
    ||      add             a4, 0x4, a4                 ; 0  3
      [!b0] bnop            m_aswap32w_return, 5        ; 0  4
mc_aswap32w_new:                                        
            ldnw             *b4++[0x0], b5             ; 0  5
      [!b1] ldnw             *a4++[0x0], a5             ; 0  6
    ||      sub             b0, 8, b0                   ; 0  7
            nop             4                           ; 1  0
            swap2           b5, b5                      ; 1  1
    ||[!b1] swap2           a5, a5                      ; 1  2
            stnw            b5, *b4++[0x2]              ; 1  3
      [!b1] stnw            a5, *a4++[0x2]              ; 1  4
    ||[ b1] zero            b0                          ; 1  5
      [ b0] bnop            mc_aswap32w_new, 4          ; 1  6 
            cmpeq           b0, 0x4, b1                 ; 1  7
m_aswap32w_return:                              
            b               b3                          ; 2  0                      
            nop             1                           ; 2  1
            nop             1                           ; 2  2
            nop             1                           ; 2  3 
            nop             1                           ; 2  4
            nop             1                           ; 2  5
            nop             1                           ; 2  6
            nop             1                           ; 2  7

 