;******************************************************************************
;                                         Copyright (C) 2010 RCZI
;***sss************************************************************************
            .def            _aswap64w__FPULUi

_aswap64w__FPULUi:
            and             b4, ~0x7, b0                ; 0  0
    ||      cmpeq           b4, 0x8, b1                 ; 0  1
    ||      mv              a4, b4                      ; 0  2
    ||      add             a4, 0x8, a4                 ; 0  3
      [!b0] bnop            m_aswap64w_return, 5        ; 0  4
mc_aswap64w_new:                                        
            ldndw           *b4++[0x0], b7:b6           ; 0  5
      [!b1] ldndw           *a4++[0x0], a7:a6           ; 0  6
    ||      sub             b0, 16, b0                  ; 0  7
            nop             4                           ; 1  0
            swap2           b7, b7                      ; 1  1
    ||[!b1] swap2           a7, a7                      ; 1  2
            swap2           b6, b6                      ; 1  3
    ||[!b1] swap2           a6, a6                      ; 1  4
            mv              a7, a8                      ; 1  5
    ||      mv              b7, b8                      ; 1  6
            mv              a6, a9                      ; 1  7
    ||      mv              b6, b9                      ; 2  0
            stndw           b9:b8, *b4++[0x2]           ; 2  1
      [!b1] stndw           a9:a8, *a4++[0x2]           ; 2  2
    ||[ b1] zero            b0                          ; 2  3
      [ b0] bnop            mc_aswap64w_new, 4          ; 2  4
            cmpeq           b0, 0x8, b1                 ; 2  5
m_aswap64w_return:                                      
            b               b3                          ; 2  6                   
            nop             5                           ; 2  7

