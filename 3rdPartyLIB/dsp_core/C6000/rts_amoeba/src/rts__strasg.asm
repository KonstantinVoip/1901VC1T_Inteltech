;******************************************************************************
;* strasg  v5.1.0                                                             *
;* Copyright (c) 1998-2005  Texas Instruments Incorporated                    *
;******************************************************************************
;        .include c60asm.i

;******************************************************************************
;* TMS320C6x ANSI C Codegen                              Version 2.00         *
;* Date/Time created: Fri Feb 13 11:12:13 1998                                *
;******************************************************************************

; void _strasg(int *dst, const int *src, unsigned cnt)
; {
;     int i;
; 
;     cnt /= 4;
; 
;     _nassert(cnt >= 7);
; 
;     for (i=0;i<cnt;i++)
;       *dst++ = *src++;
; }

;******************************************************************************
;* GLOBAL FILE PARAMETERS                                                     *
;*                                                                            *
;*   Architecture        : TMS320C6200                                        *
;*   Endian              : Little                                             *
;*   Interrupt Threshold : Disabled                                           *
;*   Memory Model        : Small                                              *
;*   Speculative Load    : Threshold = 0                                      *
;*   Redundant Loops     : Enabled                                            *
;*   Pipelining          : Enabled                                            *
;*   Debug Info          : No Debug Info                                      *
;*                                                                            *
;******************************************************************************

FP      .set    A15
DP      .set    B14
SP      .set    B15

        .clink
        .global __strasg

;******************************************************************************
;* FUNCTION NAME: __strasg                                                    *
;*                                                                            *
;*   Regs Modified     : A0,A3,B0,B4,B5,B6                                    *
;*   Regs Used         : A0,A3,A4,A6,B0,B3,B4,B5,B6                           *
;*   Local Frame Size  : 0 Args + 0 Auto + 0 Save = 0 byte                    *
;******************************************************************************
__strasg:  .asmfunc
;** --------------------------------------------------------------------------*
           MVC     .S2     CSR,B6       ; |9| 
||         MV      .L2X    A4,B4        ; |2| 
||         MV      .L1X    B4,A0        ; |2| 

           AND     .L2     -2,B6,B5     ; |9| 
||         SHR     .S2X    A6,2,B0      ; |9| 

           MVC     .S2     B5,CSR       ; |9| 
||         SUB     .L2     B0,6,B0      ; |9| 

;** --------------------------------------------------------------------------*
L2:        ; PIPED LOOP PROLOG

   [ B0]   SUB     .S2     B0,1,B0      ; |9| 
||         LDW     .D1T1   *A0++,A3     ; |10| 

   [ B0]   B       .S1     L3           ; |9| 
|| [ B0]   SUB     .S2     B0,1,B0      ;@ |9| 
||         LDW     .D1T1   *A0++,A3     ;@ |10| 

   [ B0]   B       .S1     L3           ;@ |9| 
|| [ B0]   SUB     .S2     B0,1,B0      ;@@ |9| 
||         LDW     .D1T1   *A0++,A3     ;@@ |10| 

   [ B0]   B       .S1     L3           ;@@ |9| 
|| [ B0]   SUB     .S2     B0,1,B0      ;@@@ |9| 
||         LDW     .D1T1   *A0++,A3     ;@@@ |10| 

   [ B0]   B       .S1     L3           ;@@@ |9| 
|| [ B0]   SUB     .S2     B0,1,B0      ;@@@@ |9| 
||         LDW     .D1T1   *A0++,A3     ;@@@@ |10| 

           MV      .L2X    A3,B5        ; |2| 
|| [ B0]   B       .S1     L3           ;@@@@ |9| 
|| [ B0]   SUB     .S2     B0,1,B0      ;@@@@@ |9| 
||         LDW     .D1T1   *A0++,A3     ;@@@@@ |10| 

;** --------------------------------------------------------------------------*
L3:        ; PIPED LOOP KERNEL

           STW     .D2T2   B5,*B4++     ; |10| 
||         MV      .L2X    A3,B5        ;@ |2| 
|| [ B0]   B       .S1     L3           ;@@@@@ |9| 
|| [ B0]   SUB     .S2     B0,1,B0      ;@@@@@@ |9| 
||         LDW     .D1T1   *A0++,A3     ;@@@@@@ |10| 

;** --------------------------------------------------------------------------*
L4:        ; PIPED LOOP EPILOG

           STW     .D2T2   B5,*B4++     ;@ |10| 
||         MV      .L2X    A3,B5        ;@@ |2| 
||         RET     .S2     B3           

           STW     .D2T2   B5,*B4++     ;@@ |10| 
||         MV      .L2X    A3,B5        ;@@@ |2| 

           STW     .D2T2   B5,*B4++     ;@@@ |10| 
||         MV      .L2X    A3,B5        ;@@@@ |2| 

           STW     .D2T2   B5,*B4++     ;@@@@ |10| 
||         MV      .L2X    A3,B5        ;@@@@@ |2| 

           STW     .D2T2   B5,*B4++     ;@@@@@ |10| 
||         MV      .L2X    A3,B5        ;@@@@@@ |2| 

           STW     .D2T2   B5,*B4++     ;@@@@@@ |10| 
||         MVC     .S2     B6,CSR       
        .endasmfunc

