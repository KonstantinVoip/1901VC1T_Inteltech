;******************************************************************************
;                                         Copyright (C) 2010 RCZI
;***sss************************************************************************
        .def        _swap64w__FUL

_swap64w__FUL:
        b           b3                  ; 0  0
        mv          a5, b4              ; 0  1
        swap2       a4, a4              ; 0  2
     || swap2       b4, b4              ; 0  3
        mv          a4, a5              ; 0  4
        mv          b4, a4              ; 0  5
        nop         1                   ; 0  6
        nop         1                   ; 0  7

 