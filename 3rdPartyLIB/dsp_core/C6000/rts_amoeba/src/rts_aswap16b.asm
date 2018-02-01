;******************************************************************************
;                                         Copyright (C) 2010 RCZI
;***sss************************************************************************
            .def            _aswap16b__FPUsUi

_aswap16b__FPUsUi:
            and             b4, ~0x1, b0                ; 0  0
    ||      cmpeq           b4, 0x2, b1                 ; 0  1
    ||      mv              a4, b4                      ; 0  2
    ||      add             a4, 0x2, a4                 ; 0  3
      [!b0] bnop            m_aswap16b_return, 5        ; 0  4
mc_aswap16b_new:                                        
            ldhu            *b4++[0x0], b5              ; 0  5
    ||[!b1] ldhu            *a4++[0x0], a5              ; 0  6
    ||      sub             b0, 4, b0                   ; 0  7
            nop             4                           ; 1  0
            swap4           b5, b5                      ; 1  1
    ||[!b1] swap4           a5, a5                      ; 1  2
            sth             b5, *b4++[0x2]              ; 1  3
    ||[!b1] sth             a5, *a4++[0x2]              ; 1  4
    ||[ b1] zero            b0                          ; 1  5
      [ b0] bnop            mc_aswap16b_new, 4          ; 1  6 
            cmpeq           b0, 0x2, b1                 ; 1  7
m_aswap16b_return:                              
            b               b3                          ; 2  0                      
            nop             1                           ; 2  1
            nop             1                           ; 2  2
            nop             1                           ; 2  3
            nop             1                           ; 2  4
            nop             1                           ; 2  5
            nop             1                           ; 2  6
            nop             1                           ; 2  7
