;******************************************************************************
;                                         Copyright (C) 2010 RCZI
;***sss************************************************************************
            .def            _aswap64dw__FPULUi

_aswap64dw__FPULUi:
            and             b4, ~0x7, b0                ; 0  0
    ||      cmpeq           b4, 0x8, b1                 ; 0  1
    ||      mv              a4, b4                      ; 0  2
    ||      add             a4, 0x8, a4                 ; 0  3
      [!b0] bnop            m_aswap64dw_return, 5       ; 0  4
mc_aswap64dw_new:                                       
            ldndw           *b4++[0x0], b7:b6           ; 0  5
      [!b1] ldndw           *a4++[0x0], a7:a6           ; 0  6
    ||      sub             b0, 16, b0                  ; 0  7
            nop             4                           ; 1  0
            mv              a7, a8                      ; 1  1
    ||      mv              b7, b8                      ; 1  2
            mv              a6, a9                      ; 1  3
    ||      mv              b6, b9                      ; 1  4
            stndw           b9:b8, *b4++[0x2]           ; 1  5
      [!b1] stndw           a9:a8, *a4++[0x2]           ; 1  6
    ||[ b1] zero            b0                          ; 1  7
      [ b0] bnop            mc_aswap64dw_new, 4         ; 2  0
            cmpeq           b0, 0x8, b1                 ; 2  1
m_aswap64dw_return:                                     
            b               b3                          ; 2  2                   
            nop             1                           ; 2  3
            nop             1                           ; 2  4
            nop             1                           ; 2  5
            nop             1                           ; 2  6
            nop             1                           ; 2  7


