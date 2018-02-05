;******************************************************************************
;* TMS320C6x C/C++ Codegen                                         PC v6.1.22 *
;* Date/Time created: Mon Feb 05 10:17:19 2018                                *
;******************************************************************************
	.compiler_opts --c64p_l1d_workaround=default --endian=little --hll_source=on --mem_model:code=near --mem_model:const=data --mem_model:data=far --silicon_version=6400 --symdebug:dwarf 

;******************************************************************************
;* GLOBAL FILE PARAMETERS                                                     *
;*                                                                            *
;*   Architecture      : TMS320C64xx                                          *
;*   Optimization      : Disabled                                             *
;*   Optimizing for    : Compile time, Ease of Development                    *
;*                       Based on options: no -o, no -ms                      *
;*   Endian            : Little                                               *
;*   Interrupt Thrshld : Disabled                                             *
;*   Data Access Model : Far                                                  *
;*   Pipelining        : Disabled                                             *
;*   Memory Aliases    : Presume are aliases (pessimistic)                    *
;*   Debug Info        : DWARF Debug                                          *
;*                                                                            *
;******************************************************************************

	.asg	A15, FP
	.asg	B14, DP
	.asg	B15, SP
	.global	$bss


$C$DW$CU	.dwtag  DW_TAG_compile_unit
	.dwattr $C$DW$CU, DW_AT_name("test_c.cpp")
	.dwattr $C$DW$CU, DW_AT_producer("TMS320C6x C/C++ Codegen PC v6.1.22 Copyright (c) 1996-2012 Texas Instruments Incorporated")
	.dwattr $C$DW$CU, DW_AT_TI_version(0x01)
	.dwattr $C$DW$CU, DW_AT_comp_dir("C:\1901VC1T_Inteltech\3rdPartyLIB\dsp_core\C6000\tpo_amoeba\source")

$C$DW$1	.dwtag  DW_TAG_subprogram, DW_AT_name("memcpy")
	.dwattr $C$DW$1, DW_AT_TI_symbol_name("_memcpy")
	.dwattr $C$DW$1, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$1, DW_AT_declaration
	.dwattr $C$DW$1, DW_AT_external
$C$DW$2	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$2, DW_AT_type(*$C$DW$T$3)
$C$DW$3	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$3, DW_AT_type(*$C$DW$T$94)
$C$DW$4	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$4, DW_AT_type(*$C$DW$T$11)
	.dwendtag $C$DW$1


$C$DW$172	.dwtag  DW_TAG_subprogram, DW_AT_name("_amem4")
	.dwattr $C$DW$172, DW_AT_TI_symbol_name("__amem4")
	.dwattr $C$DW$172, DW_AT_type(*$C$DW$T$751)
	.dwattr $C$DW$172, DW_AT_declaration
	.dwattr $C$DW$172, DW_AT_external
$C$DW$173	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$173, DW_AT_type(*$C$DW$T$3)
	.dwendtag $C$DW$172


$C$DW$174	.dwtag  DW_TAG_subprogram, DW_AT_name("_mem4")
	.dwattr $C$DW$174, DW_AT_TI_symbol_name("__mem4")
	.dwattr $C$DW$174, DW_AT_type(*$C$DW$T$751)
	.dwattr $C$DW$174, DW_AT_declaration
	.dwattr $C$DW$174, DW_AT_external
$C$DW$175	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$175, DW_AT_type(*$C$DW$T$3)
	.dwendtag $C$DW$174


$C$DW$176	.dwtag  DW_TAG_subprogram, DW_AT_name("memset")
	.dwattr $C$DW$176, DW_AT_TI_symbol_name("_memset")
	.dwattr $C$DW$176, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$176, DW_AT_declaration
	.dwattr $C$DW$176, DW_AT_external
$C$DW$177	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$177, DW_AT_type(*$C$DW$T$3)
$C$DW$178	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$178, DW_AT_type(*$C$DW$T$10)
$C$DW$179	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$179, DW_AT_type(*$C$DW$T$682)
	.dwendtag $C$DW$176


$C$DW$180	.dwtag  DW_TAG_subprogram, DW_AT_name("memcmp")
	.dwattr $C$DW$180, DW_AT_TI_symbol_name("_memcmp")
	.dwattr $C$DW$180, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$180, DW_AT_declaration
	.dwattr $C$DW$180, DW_AT_external
$C$DW$181	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$181, DW_AT_type(*$C$DW$T$94)
$C$DW$182	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$182, DW_AT_type(*$C$DW$T$94)
$C$DW$183	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$183, DW_AT_type(*$C$DW$T$682)
	.dwendtag $C$DW$180


$C$DW$184	.dwtag  DW_TAG_subprogram, DW_AT_name("EDMA_intClear")
	.dwattr $C$DW$184, DW_AT_TI_symbol_name("_EDMA_intClear__FUi")
	.dwattr $C$DW$184, DW_AT_declaration
	.dwattr $C$DW$184, DW_AT_external
$C$DW$185	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$185, DW_AT_type(*$C$DW$T$47)
	.dwendtag $C$DW$184


$C$DW$186	.dwtag  DW_TAG_subprogram, DW_AT_name("EDMA_intTest")
	.dwattr $C$DW$186, DW_AT_TI_symbol_name("_EDMA_intTest__FUi")
	.dwattr $C$DW$186, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$186, DW_AT_declaration
	.dwattr $C$DW$186, DW_AT_external
$C$DW$187	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$187, DW_AT_type(*$C$DW$T$47)
	.dwendtag $C$DW$186


$C$DW$188	.dwtag  DW_TAG_subprogram, DW_AT_name("EDMA_qdmaConfigArgs")
	.dwattr $C$DW$188, DW_AT_TI_symbol_name("_EDMA_qdmaConfigArgs__FUiN41")
	.dwattr $C$DW$188, DW_AT_declaration
	.dwattr $C$DW$188, DW_AT_external
$C$DW$189	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$189, DW_AT_type(*$C$DW$T$47)
$C$DW$190	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$190, DW_AT_type(*$C$DW$T$47)
$C$DW$191	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$191, DW_AT_type(*$C$DW$T$47)
$C$DW$192	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$192, DW_AT_type(*$C$DW$T$47)
$C$DW$193	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$193, DW_AT_type(*$C$DW$T$47)
	.dwendtag $C$DW$188


$C$DW$194	.dwtag  DW_TAG_subprogram, DW_AT_name("analysis_hash_fwmem")
	.dwattr $C$DW$194, DW_AT_TI_symbol_name("_analysis_hash_fwmem__FP11hash_window")
	.dwattr $C$DW$194, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$194, DW_AT_declaration
	.dwattr $C$DW$194, DW_AT_external
$C$DW$195	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$195, DW_AT_type(*$C$DW$T$733)
	.dwendtag $C$DW$194

$C$DW$196	.dwtag  DW_TAG_variable, DW_AT_name("__syscall_tab")
	.dwattr $C$DW$196, DW_AT_TI_symbol_name("___syscall_tab")
	.dwattr $C$DW$196, DW_AT_type(*$C$DW$T$680)
	.dwattr $C$DW$196, DW_AT_declaration
	.dwattr $C$DW$196, DW_AT_external
$C$DW$197	.dwtag  DW_TAG_variable, DW_AT_name("hwindow")
	.dwattr $C$DW$197, DW_AT_TI_symbol_name("_hwindow")
	.dwattr $C$DW$197, DW_AT_type(*$C$DW$T$772)
	.dwattr $C$DW$197, DW_AT_declaration
	.dwattr $C$DW$197, DW_AT_external
$C$DW$198	.dwtag  DW_TAG_variable, DW_AT_name("sh_mem_write")
	.dwattr $C$DW$198, DW_AT_TI_symbol_name("_sh_mem_write")
	.dwattr $C$DW$198, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$198, DW_AT_declaration
	.dwattr $C$DW$198, DW_AT_external
$C$DW$199	.dwtag  DW_TAG_variable, DW_AT_name("sh_mem_read_proc")
	.dwattr $C$DW$199, DW_AT_TI_symbol_name("_sh_mem_read_proc")
	.dwattr $C$DW$199, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$199, DW_AT_declaration
	.dwattr $C$DW$199, DW_AT_external
$C$DW$200	.dwtag  DW_TAG_variable, DW_AT_name("sh_mem_read_crypt")
	.dwattr $C$DW$200, DW_AT_TI_symbol_name("_sh_mem_read_crypt")
	.dwattr $C$DW$200, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$200, DW_AT_declaration
	.dwattr $C$DW$200, DW_AT_external
$C$DW$201	.dwtag  DW_TAG_variable, DW_AT_name("sh_mem_read_proc2")
	.dwattr $C$DW$201, DW_AT_TI_symbol_name("_sh_mem_read_proc2")
	.dwattr $C$DW$201, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$201, DW_AT_declaration
	.dwattr $C$DW$201, DW_AT_external
$C$DW$202	.dwtag  DW_TAG_variable, DW_AT_name("sh_mem_read_crypt2")
	.dwattr $C$DW$202, DW_AT_TI_symbol_name("_sh_mem_read_crypt2")
	.dwattr $C$DW$202, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$202, DW_AT_declaration
	.dwattr $C$DW$202, DW_AT_external
$C$DW$203	.dwtag  DW_TAG_variable, DW_AT_name("gl_result")
	.dwattr $C$DW$203, DW_AT_TI_symbol_name("_gl_result")
	.dwattr $C$DW$203, DW_AT_type(*$C$DW$T$398)
	.dwattr $C$DW$203, DW_AT_declaration
	.dwattr $C$DW$203, DW_AT_external
$C$DW$204	.dwtag  DW_TAG_variable, DW_AT_name("Start_dozu_nagr")
	.dwattr $C$DW$204, DW_AT_TI_symbol_name("_Start_dozu_nagr")
	.dwattr $C$DW$204, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$204, DW_AT_declaration
	.dwattr $C$DW$204, DW_AT_external
$C$DW$205	.dwtag  DW_TAG_variable, DW_AT_name("sv_msg_open")
	.dwattr $C$DW$205, DW_AT_TI_symbol_name("_sv_msg_open")
	.dwattr $C$DW$205, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$205, DW_AT_declaration
	.dwattr $C$DW$205, DW_AT_external
;	C:\Program Files (x86)\Texas Instruments\C6000 Code Generation Tools 6.1.22\bin\acp6x.exe -@C:\Users\shiluaev\AppData\Local\Temp\0520812 
	.sect	".text"
	.clink
	.global	_QDMA_Read__FPvT1Us

$C$DW$206	.dwtag  DW_TAG_subprogram, DW_AT_name("QDMA_Read")
	.dwattr $C$DW$206, DW_AT_low_pc(_QDMA_Read__FPvT1Us)
	.dwattr $C$DW$206, DW_AT_high_pc(0x00)
	.dwattr $C$DW$206, DW_AT_TI_symbol_name("_QDMA_Read__FPvT1Us")
	.dwattr $C$DW$206, DW_AT_external
	.dwattr $C$DW$206, DW_AT_TI_begin_file("test_c.cpp")
	.dwattr $C$DW$206, DW_AT_TI_begin_line(0x5d)
	.dwattr $C$DW$206, DW_AT_TI_begin_column(0x06)
	.dwpsn	file "test_c.cpp",line 94,column 1,is_stmt,address _QDMA_Read__FPvT1Us

	.dwfde $C$DW$CIE, _QDMA_Read__FPvT1Us
$C$DW$207	.dwtag  DW_TAG_formal_parameter, DW_AT_name("dst")
	.dwattr $C$DW$207, DW_AT_TI_symbol_name("_dst")
	.dwattr $C$DW$207, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$207, DW_AT_location[DW_OP_reg4]
$C$DW$208	.dwtag  DW_TAG_formal_parameter, DW_AT_name("src")
	.dwattr $C$DW$208, DW_AT_TI_symbol_name("_src")
	.dwattr $C$DW$208, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$208, DW_AT_location[DW_OP_reg20]
$C$DW$209	.dwtag  DW_TAG_formal_parameter, DW_AT_name("len")
	.dwattr $C$DW$209, DW_AT_TI_symbol_name("_len")
	.dwattr $C$DW$209, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$209, DW_AT_location[DW_OP_reg6]
;----------------------------------------------------------------------
;  93 | memcpy(((char*)dst+4*l),((char*)src+4*l),ost);                         
;----------------------------------------------------------------------

;******************************************************************************
;* FUNCTION NAME: QDMA_Read(void *, void *, unsigned short)                   *
;*                                                                            *
;*   Regs Modified     : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP,A16,A17,A18,A19,A20,A21,A22,A23,A24, *
;*                           A25,A26,A27,A28,A29,A30,A31,B16,B17,B18,B19,B20, *
;*                           B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31      *
;*   Regs Used         : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP,A16,A17,A18,A19,A20,A21,A22,A23,A24, *
;*                           A25,A26,A27,A28,A29,A30,A31,B16,B17,B18,B19,B20, *
;*                           B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31      *
;*   Local Frame Size  : 0 Args + 16 Auto + 4 Save = 20 byte                  *
;******************************************************************************
_QDMA_Read__FPvT1Us:
;** --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
	.dwcfi	save_reg_to_reg, 228, 19
           STW     .D2T2   B3,*SP--(24)      ; |94| 
	.dwcfi	cfa_offset, 24
	.dwcfi	save_reg_to_mem, 19, 0
$C$DW$210	.dwtag  DW_TAG_variable, DW_AT_name("dst")
	.dwattr $C$DW$210, DW_AT_TI_symbol_name("_dst")
	.dwattr $C$DW$210, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$210, DW_AT_location[DW_OP_breg31 4]
$C$DW$211	.dwtag  DW_TAG_variable, DW_AT_name("src")
	.dwattr $C$DW$211, DW_AT_TI_symbol_name("_src")
	.dwattr $C$DW$211, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$211, DW_AT_location[DW_OP_breg31 8]
$C$DW$212	.dwtag  DW_TAG_variable, DW_AT_name("len")
	.dwattr $C$DW$212, DW_AT_TI_symbol_name("_len")
	.dwattr $C$DW$212, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$212, DW_AT_location[DW_OP_breg31 12]
$C$DW$213	.dwtag  DW_TAG_variable, DW_AT_name("l")
	.dwattr $C$DW$213, DW_AT_TI_symbol_name("_l")
	.dwattr $C$DW$213, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$213, DW_AT_location[DW_OP_breg31 14]
$C$DW$214	.dwtag  DW_TAG_variable, DW_AT_name("ost")
	.dwattr $C$DW$214, DW_AT_TI_symbol_name("_ost")
	.dwattr $C$DW$214, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$214, DW_AT_location[DW_OP_breg31 16]
           STH     .D2T1   A6,*+SP(12)       ; |94| 
           STW     .D2T2   B4,*+SP(8)        ; |94| 
           STW     .D2T1   A4,*+SP(4)        ; |94| 
	.dwpsn	file "test_c.cpp",line 95,column 9,is_stmt
;----------------------------------------------------------------------
;  95 | #else                                                                  
;----------------------------------------------------------------------
           LDHU    .D2T2   *+SP(12),B4       ; |95| 
           NOP             4
           SHR     .S2     B4,1,B5           ; |95| 
           SHRU    .S2     B5,30,B5          ; |95| 
           ADD     .L2     B5,B4,B4          ; |95| 
           SHR     .S2     B4,2,B4           ; |95| 
           STH     .D2T2   B4,*+SP(14)       ; |95| 
	.dwpsn	file "test_c.cpp",line 96,column 6,is_stmt
;----------------------------------------------------------------------
;  96 | */                                                                     
;  97 | #ifdef CHIP_6412                                                       
;----------------------------------------------------------------------
           LDHU    .D2T2   *+SP(12),B4       ; |96| 
           NOP             4
           AND     .L2     3,B4,B4           ; |96| 
           STW     .D2T2   B4,*+SP(16)       ; |96| 
	.dwpsn	file "test_c.cpp",line 98,column 2,is_stmt
;----------------------------------------------------------------------
;  98 | //---------------------------------------------------------------------
;     | -------                                                                
;  99 | void QDMA_Read(void* dst,void* src,uint16 len)                         
;----------------------------------------------------------------------
           LDHU    .D2T2   *+SP(14),B0       ; |98| 
           NOP             4
   [!B0]   BNOP    .S1     $C$L2,5           ; |98| 
           ; BRANCHCC OCCURS {$C$L2}         ; |98| 
;** --------------------------------------------------------------------------*
	.dwpsn	file "test_c.cpp",line 100,column 3,is_stmt
$C$DW$215	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$215, DW_AT_low_pc(0x00)
	.dwattr $C$DW$215, DW_AT_name("_EDMA_intClear__FUi")
	.dwattr $C$DW$215, DW_AT_TI_call
           CALL    .S1     _EDMA_intClear__FUi ; |100| 
           ADDKPC  .S2     $C$RL0,B3,3       ; |100| 
           MVK     .L1     0x7,A4            ; |100| 
$C$RL0:    ; CALL OCCURS {_EDMA_intClear__FUi} {0}  ; |100| 
	.dwpsn	file "test_c.cpp",line 101,column 3,is_stmt
;----------------------------------------------------------------------
; 101 | uint16 l=len/4;                                                        
; 102 | int ost=len&0x3;                                                       
; 104 | if(l)                                                                  
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(4),B6        ; |101| 
$C$DW$216	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$216, DW_AT_low_pc(0x00)
	.dwattr $C$DW$216, DW_AT_name("_EDMA_qdmaConfigArgs__FUiN41")
	.dwattr $C$DW$216, DW_AT_TI_call

           CALL    .S1     _EDMA_qdmaConfigArgs__FUiN41 ; |101| 
||         LDHU    .D2T1   *+SP(14),A6       ; |101| 

           LDW     .D2T2   *+SP(8),B4        ; |101| 
           ZERO    .L1     A4                ; |101| 
           ADDKPC  .S2     $C$RL1,B3,1       ; |101| 

           MVKH    .S1     0x1370000,A4      ; |101| 
||         ZERO    .L1     A8                ; |101| 

$C$RL1:    ; CALL OCCURS {_EDMA_qdmaConfigArgs__FUiN41} {0}  ; |101| 
	.dwpsn	file "test_c.cpp",line 105,column 9,is_stmt
;----------------------------------------------------------------------
; 106 | EDMA_intClear(TCCINTNUM_READ);                                         
;----------------------------------------------------------------------
$C$DW$217	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$217, DW_AT_low_pc(0x00)
	.dwattr $C$DW$217, DW_AT_name("_EDMA_intTest__FUi")
	.dwattr $C$DW$217, DW_AT_TI_call
           CALL    .S1     _EDMA_intTest__FUi ; |105| 
           ADDKPC  .S2     $C$RL2,B3,3       ; |105| 
           MVK     .L1     0x7,A4            ; |105| 
$C$RL2:    ; CALL OCCURS {_EDMA_intTest__FUi} {0}  ; |105| 
           MV      .L1     A4,A0             ; |105| 
   [ A0]   BNOP    .S1     $C$L2,5           ; |105| 
           ; BRANCHCC OCCURS {$C$L2}         ; |105| 
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
$C$L1:    
$C$DW$L$_QDMA_Read__FPvT1Us$3$B:
$C$DW$218	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$218, DW_AT_low_pc(0x00)
	.dwattr $C$DW$218, DW_AT_name("_EDMA_intTest__FUi")
	.dwattr $C$DW$218, DW_AT_TI_call
           CALL    .S1     _EDMA_intTest__FUi ; |105| 
           ADDKPC  .S2     $C$RL3,B3,3       ; |105| 
           MVK     .L1     0x7,A4            ; |105| 
$C$RL3:    ; CALL OCCURS {_EDMA_intTest__FUi} {0}  ; |105| 
           MV      .L1     A4,A0             ; |105| 
   [!A0]   BNOP    .S1     $C$L1,5           ; |105| 
           ; BRANCHCC OCCURS {$C$L1}         ; |105| 
$C$DW$L$_QDMA_Read__FPvT1Us$3$E:
;** --------------------------------------------------------------------------*
$C$L2:    
	.dwpsn	file "test_c.cpp",line 107,column 2,is_stmt
;----------------------------------------------------------------------
; 107 | EDMA_qdmaConfigArgs(0x01370000,(uint32)src,l,(uint32)dst,0);//Urgent pr
;     | iority                                                                 
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(16),B0       ; |107| 
           NOP             4
   [!B0]   BNOP    .S1     $C$L3,5           ; |107| 
           ; BRANCHCC OCCURS {$C$L3}         ; |107| 
;** --------------------------------------------------------------------------*
	.dwpsn	file "test_c.cpp",line 108,column 3,is_stmt
;----------------------------------------------------------------------
; 108 | //              EDMA_qdmaConfigArgs(0x21370000,(uint32)src,l,(uint32)ds
;     | t,0);//High priority                                                   
;----------------------------------------------------------------------
           LDHU    .D2T2   *+SP(14),B6       ; |108| 
           LDW     .D2T2   *+SP(4),B7        ; |108| 
           LDHU    .D2T2   *+SP(14),B4       ; |108| 
$C$DW$219	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$219, DW_AT_low_pc(0x04)
	.dwattr $C$DW$219, DW_AT_name("_memcpy")
	.dwattr $C$DW$219, DW_AT_TI_call

           LDW     .D2T2   *+SP(8),B5        ; |108| 
||         CALL    .S1     _memcpy           ; |108| 

           LDW     .D2T1   *+SP(16),A6       ; |108| 
           ADDKPC  .S2     $C$RL4,B3,0       ; |108| 
           ADDAW   .D2     B7,B6,B6          ; |108| 
           NOP             1

           MV      .L1X    B6,A4             ; |108| 
||         ADDAW   .D2     B5,B4,B4          ; |108| 

$C$RL4:    ; CALL OCCURS {_memcpy} {0}       ; |108| 
	.dwpsn	file "test_c.cpp",line 109,column 1,is_stmt
;----------------------------------------------------------------------
; 109 | //              EDMA_qdmaConfigArgs(0x41370000,(uint32)src,l,(uint32)ds
;     | t,0);//Medium priority                                                 
;----------------------------------------------------------------------
;** --------------------------------------------------------------------------*
$C$L3:    
           LDW     .D2T2   *++SP(24),B3      ; |109| 
           NOP             4
	.dwcfi	cfa_offset, 0
	.dwcfi	restore_reg, 19
	.dwcfi	cfa_offset, 0
$C$DW$220	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$220, DW_AT_low_pc(0x00)
	.dwattr $C$DW$220, DW_AT_TI_return
           RETNOP  .S2     B3,5              ; |109| 
           ; BRANCH OCCURS {B3}              ; |109| 

$C$DW$221	.dwtag  DW_TAG_TI_loop
	.dwattr $C$DW$221, DW_AT_name("C:\1901VC1T_Inteltech\3rdPartyLIB\dsp_core\C6000\tpo_amoeba\source\test_c.asm:$C$L1:1:1517815039")
	.dwattr $C$DW$221, DW_AT_TI_begin_file("test_c.cpp")
	.dwattr $C$DW$221, DW_AT_TI_begin_line(0x69)
	.dwattr $C$DW$221, DW_AT_TI_end_line(0x69)
$C$DW$222	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$222, DW_AT_low_pc($C$DW$L$_QDMA_Read__FPvT1Us$3$B)
	.dwattr $C$DW$222, DW_AT_high_pc($C$DW$L$_QDMA_Read__FPvT1Us$3$E)
	.dwendtag $C$DW$221

	.dwattr $C$DW$206, DW_AT_TI_end_file("test_c.cpp")
	.dwattr $C$DW$206, DW_AT_TI_end_line(0x6d)
	.dwattr $C$DW$206, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$206

	.sect	".text"
	.clink
	.global	_ReadDARAM0__FUsPvT1

$C$DW$223	.dwtag  DW_TAG_subprogram, DW_AT_name("ReadDARAM0")
	.dwattr $C$DW$223, DW_AT_low_pc(_ReadDARAM0__FUsPvT1)
	.dwattr $C$DW$223, DW_AT_high_pc(0x00)
	.dwattr $C$DW$223, DW_AT_TI_symbol_name("_ReadDARAM0__FUsPvT1")
	.dwattr $C$DW$223, DW_AT_external
	.dwattr $C$DW$223, DW_AT_TI_begin_file("test_c.cpp")
	.dwattr $C$DW$223, DW_AT_TI_begin_line(0x95)
	.dwattr $C$DW$223, DW_AT_TI_begin_column(0x06)
	.dwpsn	file "test_c.cpp",line 150,column 1,is_stmt,address _ReadDARAM0__FUsPvT1

	.dwfde $C$DW$CIE, _ReadDARAM0__FUsPvT1
$C$DW$224	.dwtag  DW_TAG_formal_parameter, DW_AT_name("addr")
	.dwattr $C$DW$224, DW_AT_TI_symbol_name("_addr")
	.dwattr $C$DW$224, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$224, DW_AT_location[DW_OP_reg4]
$C$DW$225	.dwtag  DW_TAG_formal_parameter, DW_AT_name("buf")
	.dwattr $C$DW$225, DW_AT_TI_symbol_name("_buf")
	.dwattr $C$DW$225, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$225, DW_AT_location[DW_OP_reg20]
$C$DW$226	.dwtag  DW_TAG_formal_parameter, DW_AT_name("len")
	.dwattr $C$DW$226, DW_AT_TI_symbol_name("_len")
	.dwattr $C$DW$226, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$226, DW_AT_location[DW_OP_reg6]

;******************************************************************************
;* FUNCTION NAME: ReadDARAM0(unsigned short, void *, unsigned short)          *
;*                                                                            *
;*   Regs Modified     : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP,A16,A17,A18,A19,A20,A21,A22,A23,A24, *
;*                           A25,A26,A27,A28,A29,A30,A31,B16,B17,B18,B19,B20, *
;*                           B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31      *
;*   Regs Used         : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP,A16,A17,A18,A19,A20,A21,A22,A23,A24, *
;*                           A25,A26,A27,A28,A29,A30,A31,B16,B17,B18,B19,B20, *
;*                           B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31      *
;*   Local Frame Size  : 0 Args + 12 Auto + 4 Save = 16 byte                  *
;******************************************************************************
_ReadDARAM0__FUsPvT1:
;** --------------------------------------------------------------------------*
;----------------------------------------------------------------------
; 150 | sys_busunlock();                                                       
;----------------------------------------------------------------------
	.dwcfi	cfa_offset, 0
	.dwcfi	save_reg_to_reg, 228, 19
           STW     .D2T2   B3,*SP--(16)      ; |150| 
	.dwcfi	cfa_offset, 16
	.dwcfi	save_reg_to_mem, 19, 0
$C$DW$227	.dwtag  DW_TAG_variable, DW_AT_name("addr")
	.dwattr $C$DW$227, DW_AT_TI_symbol_name("_addr")
	.dwattr $C$DW$227, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$227, DW_AT_location[DW_OP_breg31 4]
$C$DW$228	.dwtag  DW_TAG_variable, DW_AT_name("buf")
	.dwattr $C$DW$228, DW_AT_TI_symbol_name("_buf")
	.dwattr $C$DW$228, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$228, DW_AT_location[DW_OP_breg31 8]
$C$DW$229	.dwtag  DW_TAG_variable, DW_AT_name("len")
	.dwattr $C$DW$229, DW_AT_TI_symbol_name("_len")
	.dwattr $C$DW$229, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$229, DW_AT_location[DW_OP_breg31 12]
           STH     .D2T1   A6,*+SP(12)       ; |150| 

           MV      .L2X    A4,B5             ; |150| 
||         STW     .D2T2   B4,*+SP(8)        ; |150| 

           STH     .D2T2   B5,*+SP(4)        ; |150| 
	.dwpsn	file "test_c.cpp",line 151,column 5,is_stmt
;----------------------------------------------------------------------
; 152 | #endif                                                                 
; 153 | */                                                                     
;----------------------------------------------------------------------
           MVKL    .S1     _sh_mem_read_proc,A3

           MVKH    .S1     _sh_mem_read_proc,A3
||         LDHU    .D2T1   *+SP(12),A6       ; |151| 

$C$DW$230	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$230, DW_AT_low_pc(0x08)
	.dwattr $C$DW$230, DW_AT_name("_QDMA_Read__FPvT1Us")
	.dwattr $C$DW$230, DW_AT_TI_call

           LDW     .D1T1   *A3,A3            ; |151| 
||         LDHU    .D2T2   *+SP(4),B4        ; |151| 
||         CALL    .S1     _QDMA_Read__FPvT1Us ; |151| 

           LDW     .D2T1   *+SP(8),A4        ; |151| 
           ADDKPC  .S2     $C$RL5,B3,2       ; |151| 
           ADD     .L2X    B4,A3,B4          ; |151| 
$C$RL5:    ; CALL OCCURS {_QDMA_Read__FPvT1Us} {0}  ; |151| 
	.dwpsn	file "test_c.cpp",line 154,column 1,is_stmt
;----------------------------------------------------------------------
; 154 | //---------------------------------------------------------------------
;     | -------                                                                
;----------------------------------------------------------------------
           LDW     .D2T2   *++SP(16),B3      ; |154| 
           NOP             4
	.dwcfi	cfa_offset, 0
	.dwcfi	restore_reg, 19
	.dwcfi	cfa_offset, 0
$C$DW$231	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$231, DW_AT_low_pc(0x00)
	.dwattr $C$DW$231, DW_AT_TI_return
           RETNOP  .S2     B3,5              ; |154| 
           ; BRANCH OCCURS {B3}              ; |154| 
	.dwattr $C$DW$223, DW_AT_TI_end_file("test_c.cpp")
	.dwattr $C$DW$223, DW_AT_TI_end_line(0x9a)
	.dwattr $C$DW$223, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$223

	.sect	".text"
	.clink
	.global	_ReadDARAM1__FUsPvT1

$C$DW$232	.dwtag  DW_TAG_subprogram, DW_AT_name("ReadDARAM1")
	.dwattr $C$DW$232, DW_AT_low_pc(_ReadDARAM1__FUsPvT1)
	.dwattr $C$DW$232, DW_AT_high_pc(0x00)
	.dwattr $C$DW$232, DW_AT_TI_symbol_name("_ReadDARAM1__FUsPvT1")
	.dwattr $C$DW$232, DW_AT_external
	.dwattr $C$DW$232, DW_AT_TI_begin_file("test_c.cpp")
	.dwattr $C$DW$232, DW_AT_TI_begin_line(0x9d)
	.dwattr $C$DW$232, DW_AT_TI_begin_column(0x06)
	.dwpsn	file "test_c.cpp",line 158,column 1,is_stmt,address _ReadDARAM1__FUsPvT1

	.dwfde $C$DW$CIE, _ReadDARAM1__FUsPvT1
$C$DW$233	.dwtag  DW_TAG_formal_parameter, DW_AT_name("addr")
	.dwattr $C$DW$233, DW_AT_TI_symbol_name("_addr")
	.dwattr $C$DW$233, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$233, DW_AT_location[DW_OP_reg4]
$C$DW$234	.dwtag  DW_TAG_formal_parameter, DW_AT_name("buf")
	.dwattr $C$DW$234, DW_AT_TI_symbol_name("_buf")
	.dwattr $C$DW$234, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$234, DW_AT_location[DW_OP_reg20]
$C$DW$235	.dwtag  DW_TAG_formal_parameter, DW_AT_name("len")
	.dwattr $C$DW$235, DW_AT_TI_symbol_name("_len")
	.dwattr $C$DW$235, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$235, DW_AT_location[DW_OP_reg6]
;----------------------------------------------------------------------
; 157 | QDMA_Read(buf,(char*)sh_mem_read_proc+addr, len);//mac+ip              
;----------------------------------------------------------------------

;******************************************************************************
;* FUNCTION NAME: ReadDARAM1(unsigned short, void *, unsigned short)          *
;*                                                                            *
;*   Regs Modified     : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP,A16,A17,A18,A19,A20,A21,A22,A23,A24, *
;*                           A25,A26,A27,A28,A29,A30,A31,B16,B17,B18,B19,B20, *
;*                           B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31      *
;*   Regs Used         : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP,A16,A17,A18,A19,A20,A21,A22,A23,A24, *
;*                           A25,A26,A27,A28,A29,A30,A31,B16,B17,B18,B19,B20, *
;*                           B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31      *
;*   Local Frame Size  : 0 Args + 12 Auto + 4 Save = 16 byte                  *
;******************************************************************************
_ReadDARAM1__FUsPvT1:
;** --------------------------------------------------------------------------*
;----------------------------------------------------------------------
; 158 | //      memcpy(buf,(char*)sh_mem_read_proc+addr, len);                 
;----------------------------------------------------------------------
	.dwcfi	cfa_offset, 0
	.dwcfi	save_reg_to_reg, 228, 19
           STW     .D2T2   B3,*SP--(16)      ; |158| 
	.dwcfi	cfa_offset, 16
	.dwcfi	save_reg_to_mem, 19, 0
$C$DW$236	.dwtag  DW_TAG_variable, DW_AT_name("addr")
	.dwattr $C$DW$236, DW_AT_TI_symbol_name("_addr")
	.dwattr $C$DW$236, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$236, DW_AT_location[DW_OP_breg31 4]
$C$DW$237	.dwtag  DW_TAG_variable, DW_AT_name("buf")
	.dwattr $C$DW$237, DW_AT_TI_symbol_name("_buf")
	.dwattr $C$DW$237, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$237, DW_AT_location[DW_OP_breg31 8]
$C$DW$238	.dwtag  DW_TAG_variable, DW_AT_name("len")
	.dwattr $C$DW$238, DW_AT_TI_symbol_name("_len")
	.dwattr $C$DW$238, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$238, DW_AT_location[DW_OP_breg31 12]
           STH     .D2T1   A6,*+SP(12)       ; |158| 

           MV      .L2X    A4,B5             ; |158| 
||         STW     .D2T2   B4,*+SP(8)        ; |158| 

           STH     .D2T2   B5,*+SP(4)        ; |158| 
	.dwpsn	file "test_c.cpp",line 159,column 5,is_stmt
           MVKL    .S1     _sh_mem_read_proc2,A3

           MVKH    .S1     _sh_mem_read_proc2,A3
||         LDHU    .D2T1   *+SP(12),A6       ; |159| 

$C$DW$239	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$239, DW_AT_low_pc(0x08)
	.dwattr $C$DW$239, DW_AT_name("_QDMA_Read__FPvT1Us")
	.dwattr $C$DW$239, DW_AT_TI_call

           LDW     .D1T1   *A3,A3            ; |159| 
||         LDHU    .D2T2   *+SP(4),B4        ; |159| 
||         CALL    .S1     _QDMA_Read__FPvT1Us ; |159| 

           LDW     .D2T1   *+SP(8),A4        ; |159| 
           ADDKPC  .S2     $C$RL6,B3,2       ; |159| 
           ADD     .L2X    B4,A3,B4          ; |159| 
$C$RL6:    ; CALL OCCURS {_QDMA_Read__FPvT1Us} {0}  ; |159| 
	.dwpsn	file "test_c.cpp",line 161,column 1,is_stmt
           LDW     .D2T2   *++SP(16),B3      ; |161| 
           NOP             4
	.dwcfi	cfa_offset, 0
	.dwcfi	restore_reg, 19
	.dwcfi	cfa_offset, 0
$C$DW$240	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$240, DW_AT_low_pc(0x00)
	.dwattr $C$DW$240, DW_AT_TI_return
           RETNOP  .S2     B3,5              ; |161| 
           ; BRANCH OCCURS {B3}              ; |161| 
	.dwattr $C$DW$232, DW_AT_TI_end_file("test_c.cpp")
	.dwattr $C$DW$232, DW_AT_TI_end_line(0xa1)
	.dwattr $C$DW$232, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$232

	.sect	".text"
	.clink
	.global	_WriteDARAM__FUsPvT1

$C$DW$241	.dwtag  DW_TAG_subprogram, DW_AT_name("WriteDARAM")
	.dwattr $C$DW$241, DW_AT_low_pc(_WriteDARAM__FUsPvT1)
	.dwattr $C$DW$241, DW_AT_high_pc(0x00)
	.dwattr $C$DW$241, DW_AT_TI_symbol_name("_WriteDARAM__FUsPvT1")
	.dwattr $C$DW$241, DW_AT_external
	.dwattr $C$DW$241, DW_AT_TI_begin_file("test_c.cpp")
	.dwattr $C$DW$241, DW_AT_TI_begin_line(0xa8)
	.dwattr $C$DW$241, DW_AT_TI_begin_column(0x06)
	.dwpsn	file "test_c.cpp",line 169,column 1,is_stmt,address _WriteDARAM__FUsPvT1

	.dwfde $C$DW$CIE, _WriteDARAM__FUsPvT1
$C$DW$242	.dwtag  DW_TAG_formal_parameter, DW_AT_name("addr")
	.dwattr $C$DW$242, DW_AT_TI_symbol_name("_addr")
	.dwattr $C$DW$242, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$242, DW_AT_location[DW_OP_reg4]
$C$DW$243	.dwtag  DW_TAG_formal_parameter, DW_AT_name("buf")
	.dwattr $C$DW$243, DW_AT_TI_symbol_name("_buf")
	.dwattr $C$DW$243, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$243, DW_AT_location[DW_OP_reg20]
$C$DW$244	.dwtag  DW_TAG_formal_parameter, DW_AT_name("len")
	.dwattr $C$DW$244, DW_AT_TI_symbol_name("_len")
	.dwattr $C$DW$244, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$244, DW_AT_location[DW_OP_reg6]

;******************************************************************************
;* FUNCTION NAME: WriteDARAM(unsigned short, void *, unsigned short)          *
;*                                                                            *
;*   Regs Modified     : A3,B0,B4,B5,B6,SP,B31                                *
;*   Regs Used         : A3,A4,A6,B0,B3,B4,B5,B6,SP,B31                       *
;*   Local Frame Size  : 0 Args + 20 Auto + 0 Save = 20 byte                  *
;******************************************************************************
_WriteDARAM__FUsPvT1:
;** --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
	.dwcfi	save_reg_to_reg, 228, 19
           SUB     .D2     SP,24,SP          ; |169| 
	.dwcfi	cfa_offset, 24
$C$DW$245	.dwtag  DW_TAG_variable, DW_AT_name("addr")
	.dwattr $C$DW$245, DW_AT_TI_symbol_name("_addr")
	.dwattr $C$DW$245, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$245, DW_AT_location[DW_OP_breg31 4]
$C$DW$246	.dwtag  DW_TAG_variable, DW_AT_name("buf")
	.dwattr $C$DW$246, DW_AT_TI_symbol_name("_buf")
	.dwattr $C$DW$246, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$246, DW_AT_location[DW_OP_breg31 8]
$C$DW$247	.dwtag  DW_TAG_variable, DW_AT_name("len")
	.dwattr $C$DW$247, DW_AT_TI_symbol_name("_len")
	.dwattr $C$DW$247, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$247, DW_AT_location[DW_OP_breg31 12]
$C$DW$248	.dwtag  DW_TAG_variable, DW_AT_name("l")
	.dwattr $C$DW$248, DW_AT_TI_symbol_name("_l")
	.dwattr $C$DW$248, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$248, DW_AT_location[DW_OP_breg31 14]
$C$DW$249	.dwtag  DW_TAG_variable, DW_AT_name("s")
	.dwattr $C$DW$249, DW_AT_TI_symbol_name("_s")
	.dwattr $C$DW$249, DW_AT_type(*$C$DW$T$732)
	.dwattr $C$DW$249, DW_AT_location[DW_OP_breg31 16]
$C$DW$250	.dwtag  DW_TAG_variable, DW_AT_name("d")
	.dwattr $C$DW$250, DW_AT_TI_symbol_name("_d")
	.dwattr $C$DW$250, DW_AT_type(*$C$DW$T$732)
	.dwattr $C$DW$250, DW_AT_location[DW_OP_breg31 20]
           STH     .D2T1   A6,*+SP(12)       ; |169| 
           STW     .D2T2   B4,*+SP(8)        ; |169| 
           STH     .D2T1   A4,*+SP(4)        ; |169| 
	.dwpsn	file "test_c.cpp",line 170,column 8,is_stmt
;----------------------------------------------------------------------
; 170 | //#ifdef TPO5                                                          
;----------------------------------------------------------------------
           LDHU    .D2T2   *+SP(12),B4       ; |170| 
           NOP             4
           ADD     .L2     3,B4,B4           ; |170| 
           SHR     .S2     B4,2,B4           ; |170| 
           STH     .D2T2   B4,*+SP(14)       ; |170| 
	.dwpsn	file "test_c.cpp",line 171,column 9,is_stmt
;----------------------------------------------------------------------
; 171 | #ifdef CHIP_6412                                                       
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(8),B4        ; |171| 
           NOP             4
           STW     .D2T2   B4,*+SP(16)       ; |171| 
	.dwpsn	file "test_c.cpp",line 172,column 9,is_stmt
           MVKL    .S1     _sh_mem_write,A3
           MVKH    .S1     _sh_mem_write,A3

           LDW     .D1T1   *A3,A3            ; |172| 
||         LDHU    .D2T2   *+SP(4),B4        ; |172| 

           NOP             4
           ADD     .L2X    B4,A3,B4          ; |172| 
           STW     .D2T2   B4,*+SP(20)       ; |172| 
	.dwpsn	file "test_c.cpp",line 173,column 2,is_stmt
;----------------------------------------------------------------------
; 173 | //---------------------------------------------------------------------
;     | -------                                                                
;----------------------------------------------------------------------
           LDHU    .D2T2   *+SP(14),B0       ; |173| 
           NOP             4
   [!B0]   BNOP    .S1     $C$L5,3           ; |173| 
           SUB     .L2     B0,1,B4           ; |173| 
           STH     .D2T2   B4,*+SP(14)       ; |173| 
           ; BRANCHCC OCCURS {$C$L5}         ; |173| 
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
$C$L4:    
$C$DW$L$_WriteDARAM__FUsPvT1$2$B:
	.dwpsn	file "test_c.cpp",line 174,column 3,is_stmt
;----------------------------------------------------------------------
; 174 | void WriteDARAM(uint16 addr,void* buf,uint16 len)                      
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(16),B4       ; |174| 
           LDW     .D2T2   *+SP(20),B5       ; |174| 
           NOP             3
           ADD     .L2     4,B4,B6           ; |174| 
           STW     .D2T2   B6,*+SP(16)       ; |174| 
           LDNW    .D2T2   *B4,B4            ; |174| 
           ADD     .L2     4,B5,B31          ; |174| 
           STW     .D2T2   B31,*+SP(20)      ; |174| 
           NOP             2
           STW     .D2T2   B4,*B5            ; |174| 
           LDHU    .D2T2   *+SP(14),B0       ; |174| 
           NOP             4
   [ B0]   BNOP    .S1     $C$L4,3           ; |174| 
           SUB     .L2     B0,1,B4           ; |174| 
           STH     .D2T2   B4,*+SP(14)       ; |174| 
           ; BRANCHCC OCCURS {$C$L4}         ; |174| 
$C$DW$L$_WriteDARAM__FUsPvT1$2$E:
;** --------------------------------------------------------------------------*
	.dwpsn	file "test_c.cpp",line 175,column 1,is_stmt
;** --------------------------------------------------------------------------*
$C$L5:    
           ADDK    .S2     24,SP             ; |175| 
	.dwcfi	cfa_offset, 0
	.dwcfi	cfa_offset, 0
$C$DW$251	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$251, DW_AT_low_pc(0x00)
	.dwattr $C$DW$251, DW_AT_TI_return
           RETNOP  .S2     B3,5              ; |175| 
           ; BRANCH OCCURS {B3}              ; |175| 

$C$DW$252	.dwtag  DW_TAG_TI_loop
	.dwattr $C$DW$252, DW_AT_name("C:\1901VC1T_Inteltech\3rdPartyLIB\dsp_core\C6000\tpo_amoeba\source\test_c.asm:$C$L4:1:1517815039")
	.dwattr $C$DW$252, DW_AT_TI_begin_file("test_c.cpp")
	.dwattr $C$DW$252, DW_AT_TI_begin_line(0xad)
	.dwattr $C$DW$252, DW_AT_TI_end_line(0xae)
$C$DW$253	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$253, DW_AT_low_pc($C$DW$L$_WriteDARAM__FUsPvT1$2$B)
	.dwattr $C$DW$253, DW_AT_high_pc($C$DW$L$_WriteDARAM__FUsPvT1$2$E)
	.dwendtag $C$DW$252

	.dwattr $C$DW$241, DW_AT_TI_end_file("test_c.cpp")
	.dwattr $C$DW$241, DW_AT_TI_end_line(0xaf)
	.dwattr $C$DW$241, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$241

	.sect	".text"
	.clink
	.global	_ReadDARAM_CRYPT0__FUsPvT1

$C$DW$254	.dwtag  DW_TAG_subprogram, DW_AT_name("ReadDARAM_CRYPT0")
	.dwattr $C$DW$254, DW_AT_low_pc(_ReadDARAM_CRYPT0__FUsPvT1)
	.dwattr $C$DW$254, DW_AT_high_pc(0x00)
	.dwattr $C$DW$254, DW_AT_TI_symbol_name("_ReadDARAM_CRYPT0__FUsPvT1")
	.dwattr $C$DW$254, DW_AT_external
	.dwattr $C$DW$254, DW_AT_TI_begin_file("test_c.cpp")
	.dwattr $C$DW$254, DW_AT_TI_begin_line(0xbd)
	.dwattr $C$DW$254, DW_AT_TI_begin_column(0x06)
	.dwpsn	file "test_c.cpp",line 190,column 1,is_stmt,address _ReadDARAM_CRYPT0__FUsPvT1

	.dwfde $C$DW$CIE, _ReadDARAM_CRYPT0__FUsPvT1
$C$DW$255	.dwtag  DW_TAG_formal_parameter, DW_AT_name("addr")
	.dwattr $C$DW$255, DW_AT_TI_symbol_name("_addr")
	.dwattr $C$DW$255, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$255, DW_AT_location[DW_OP_reg4]
$C$DW$256	.dwtag  DW_TAG_formal_parameter, DW_AT_name("buf")
	.dwattr $C$DW$256, DW_AT_TI_symbol_name("_buf")
	.dwattr $C$DW$256, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$256, DW_AT_location[DW_OP_reg20]
$C$DW$257	.dwtag  DW_TAG_formal_parameter, DW_AT_name("len")
	.dwattr $C$DW$257, DW_AT_TI_symbol_name("_len")
	.dwattr $C$DW$257, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$257, DW_AT_location[DW_OP_reg6]
;----------------------------------------------------------------------
; 189 | while(l--)                                                             
;----------------------------------------------------------------------

;******************************************************************************
;* FUNCTION NAME: ReadDARAM_CRYPT0(unsigned short, void *, unsigned short)    *
;*                                                                            *
;*   Regs Modified     : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP,A16,A17,A18,A19,A20,A21,A22,A23,A24, *
;*                           A25,A26,A27,A28,A29,A30,A31,B16,B17,B18,B19,B20, *
;*                           B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31      *
;*   Regs Used         : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP,A16,A17,A18,A19,A20,A21,A22,A23,A24, *
;*                           A25,A26,A27,A28,A29,A30,A31,B16,B17,B18,B19,B20, *
;*                           B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31      *
;*   Local Frame Size  : 0 Args + 12 Auto + 4 Save = 16 byte                  *
;******************************************************************************
_ReadDARAM_CRYPT0__FUsPvT1:
;** --------------------------------------------------------------------------*
;----------------------------------------------------------------------
; 190 | _amem8(d++)=_mem8(s++);                                                
;----------------------------------------------------------------------
	.dwcfi	cfa_offset, 0
	.dwcfi	save_reg_to_reg, 228, 19
           STW     .D2T2   B3,*SP--(16)      ; |190| 
	.dwcfi	cfa_offset, 16
	.dwcfi	save_reg_to_mem, 19, 0
$C$DW$258	.dwtag  DW_TAG_variable, DW_AT_name("addr")
	.dwattr $C$DW$258, DW_AT_TI_symbol_name("_addr")
	.dwattr $C$DW$258, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$258, DW_AT_location[DW_OP_breg31 4]
$C$DW$259	.dwtag  DW_TAG_variable, DW_AT_name("buf")
	.dwattr $C$DW$259, DW_AT_TI_symbol_name("_buf")
	.dwattr $C$DW$259, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$259, DW_AT_location[DW_OP_breg31 8]
$C$DW$260	.dwtag  DW_TAG_variable, DW_AT_name("len")
	.dwattr $C$DW$260, DW_AT_TI_symbol_name("_len")
	.dwattr $C$DW$260, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$260, DW_AT_location[DW_OP_breg31 12]
           STH     .D2T1   A6,*+SP(12)       ; |190| 

           MV      .L2X    A4,B5             ; |190| 
||         STW     .D2T2   B4,*+SP(8)        ; |190| 

           STH     .D2T2   B5,*+SP(4)        ; |190| 
	.dwpsn	file "test_c.cpp",line 192,column 5,is_stmt
;----------------------------------------------------------------------
; 192 | #endif                                                                 
;----------------------------------------------------------------------
           MVKL    .S1     _sh_mem_read_crypt,A3

           MVKH    .S1     _sh_mem_read_crypt,A3
||         LDHU    .D2T1   *+SP(12),A6       ; |192| 

$C$DW$261	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$261, DW_AT_low_pc(0x08)
	.dwattr $C$DW$261, DW_AT_name("_QDMA_Read__FPvT1Us")
	.dwattr $C$DW$261, DW_AT_TI_call

           LDW     .D1T1   *A3,A3            ; |192| 
||         LDHU    .D2T2   *+SP(4),B4        ; |192| 
||         CALL    .S1     _QDMA_Read__FPvT1Us ; |192| 

           LDW     .D2T1   *+SP(8),A4        ; |192| 
           ADDKPC  .S2     $C$RL7,B3,2       ; |192| 
           ADD     .L2X    B4,A3,B4          ; |192| 
$C$RL7:    ; CALL OCCURS {_QDMA_Read__FPvT1Us} {0}  ; |192| 
	.dwpsn	file "test_c.cpp",line 194,column 1,is_stmt
;----------------------------------------------------------------------
; 194 | //---------------------------------------------------------------------
;     | -------                                                                
;----------------------------------------------------------------------
           LDW     .D2T2   *++SP(16),B3      ; |194| 
           NOP             4
	.dwcfi	cfa_offset, 0
	.dwcfi	restore_reg, 19
	.dwcfi	cfa_offset, 0
$C$DW$262	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$262, DW_AT_low_pc(0x00)
	.dwattr $C$DW$262, DW_AT_TI_return
           RETNOP  .S2     B3,5              ; |194| 
           ; BRANCH OCCURS {B3}              ; |194| 
	.dwattr $C$DW$254, DW_AT_TI_end_file("test_c.cpp")
	.dwattr $C$DW$254, DW_AT_TI_end_line(0xc2)
	.dwattr $C$DW$254, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$254

	.sect	".text"
	.clink
	.global	_ReadDARAM_CRYPT1__FUsPvT1

$C$DW$263	.dwtag  DW_TAG_subprogram, DW_AT_name("ReadDARAM_CRYPT1")
	.dwattr $C$DW$263, DW_AT_low_pc(_ReadDARAM_CRYPT1__FUsPvT1)
	.dwattr $C$DW$263, DW_AT_high_pc(0x00)
	.dwattr $C$DW$263, DW_AT_TI_symbol_name("_ReadDARAM_CRYPT1__FUsPvT1")
	.dwattr $C$DW$263, DW_AT_external
	.dwattr $C$DW$263, DW_AT_TI_begin_file("test_c.cpp")
	.dwattr $C$DW$263, DW_AT_TI_begin_line(0xc5)
	.dwattr $C$DW$263, DW_AT_TI_begin_column(0x06)
	.dwpsn	file "test_c.cpp",line 198,column 1,is_stmt,address _ReadDARAM_CRYPT1__FUsPvT1

	.dwfde $C$DW$CIE, _ReadDARAM_CRYPT1__FUsPvT1
$C$DW$264	.dwtag  DW_TAG_formal_parameter, DW_AT_name("addr")
	.dwattr $C$DW$264, DW_AT_TI_symbol_name("_addr")
	.dwattr $C$DW$264, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$264, DW_AT_location[DW_OP_reg4]
$C$DW$265	.dwtag  DW_TAG_formal_parameter, DW_AT_name("buf")
	.dwattr $C$DW$265, DW_AT_TI_symbol_name("_buf")
	.dwattr $C$DW$265, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$265, DW_AT_location[DW_OP_reg20]
$C$DW$266	.dwtag  DW_TAG_formal_parameter, DW_AT_name("len")
	.dwattr $C$DW$266, DW_AT_TI_symbol_name("_len")
	.dwattr $C$DW$266, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$266, DW_AT_location[DW_OP_reg6]
;----------------------------------------------------------------------
; 197 | //      QDMA_Read(2, buf,  (char*)sh_mem_read_crypt+addr, len );       
;----------------------------------------------------------------------

;******************************************************************************
;* FUNCTION NAME: ReadDARAM_CRYPT1(unsigned short, void *, unsigned short)    *
;*                                                                            *
;*   Regs Modified     : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP,A16,A17,A18,A19,A20,A21,A22,A23,A24, *
;*                           A25,A26,A27,A28,A29,A30,A31,B16,B17,B18,B19,B20, *
;*                           B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31      *
;*   Regs Used         : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP,A16,A17,A18,A19,A20,A21,A22,A23,A24, *
;*                           A25,A26,A27,A28,A29,A30,A31,B16,B17,B18,B19,B20, *
;*                           B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31      *
;*   Local Frame Size  : 0 Args + 12 Auto + 4 Save = 16 byte                  *
;******************************************************************************
_ReadDARAM_CRYPT1__FUsPvT1:
;** --------------------------------------------------------------------------*
;----------------------------------------------------------------------
; 198 | QDMA_Read(buf,(char*)sh_mem_read_crypt+addr, len);//mac+ip             
;----------------------------------------------------------------------
	.dwcfi	cfa_offset, 0
	.dwcfi	save_reg_to_reg, 228, 19
           STW     .D2T2   B3,*SP--(16)      ; |198| 
	.dwcfi	cfa_offset, 16
	.dwcfi	save_reg_to_mem, 19, 0
$C$DW$267	.dwtag  DW_TAG_variable, DW_AT_name("addr")
	.dwattr $C$DW$267, DW_AT_TI_symbol_name("_addr")
	.dwattr $C$DW$267, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$267, DW_AT_location[DW_OP_breg31 4]
$C$DW$268	.dwtag  DW_TAG_variable, DW_AT_name("buf")
	.dwattr $C$DW$268, DW_AT_TI_symbol_name("_buf")
	.dwattr $C$DW$268, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$268, DW_AT_location[DW_OP_breg31 8]
$C$DW$269	.dwtag  DW_TAG_variable, DW_AT_name("len")
	.dwattr $C$DW$269, DW_AT_TI_symbol_name("_len")
	.dwattr $C$DW$269, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$269, DW_AT_location[DW_OP_breg31 12]
;----------------------------------------------------------------------
; 199 | //      memcpy(buf,(char*)sh_mem_read_crypt+addr, len);                
;----------------------------------------------------------------------
           STH     .D2T1   A6,*+SP(12)       ; |198| 

           MV      .L2X    A4,B5             ; |198| 
||         STW     .D2T2   B4,*+SP(8)        ; |198| 

           STH     .D2T2   B5,*+SP(4)        ; |198| 
	.dwpsn	file "test_c.cpp",line 200,column 5,is_stmt
           MVKL    .S1     _sh_mem_read_crypt2,A3

           MVKH    .S1     _sh_mem_read_crypt2,A3
||         LDHU    .D2T1   *+SP(12),A6       ; |200| 

$C$DW$270	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$270, DW_AT_low_pc(0x08)
	.dwattr $C$DW$270, DW_AT_name("_QDMA_Read__FPvT1Us")
	.dwattr $C$DW$270, DW_AT_TI_call

           LDW     .D1T1   *A3,A3            ; |200| 
||         LDHU    .D2T2   *+SP(4),B4        ; |200| 
||         CALL    .S1     _QDMA_Read__FPvT1Us ; |200| 

           LDW     .D2T1   *+SP(8),A4        ; |200| 
           ADDKPC  .S2     $C$RL8,B3,2       ; |200| 
           ADD     .L2X    B4,A3,B4          ; |200| 
$C$RL8:    ; CALL OCCURS {_QDMA_Read__FPvT1Us} {0}  ; |200| 
	.dwpsn	file "test_c.cpp",line 202,column 1,is_stmt
;----------------------------------------------------------------------
; 202 | //---------------------------------------------------------------------
;     | -------                                                                
;----------------------------------------------------------------------
           LDW     .D2T2   *++SP(16),B3      ; |202| 
           NOP             4
	.dwcfi	cfa_offset, 0
	.dwcfi	restore_reg, 19
	.dwcfi	cfa_offset, 0
$C$DW$271	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$271, DW_AT_low_pc(0x00)
	.dwattr $C$DW$271, DW_AT_TI_return
           RETNOP  .S2     B3,5              ; |202| 
           ; BRANCH OCCURS {B3}              ; |202| 
	.dwattr $C$DW$263, DW_AT_TI_end_file("test_c.cpp")
	.dwattr $C$DW$263, DW_AT_TI_end_line(0xca)
	.dwattr $C$DW$263, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$263

	.sect	".text"
	.clink
	.global	_TestCelostnost__Fv

$C$DW$272	.dwtag  DW_TAG_subprogram, DW_AT_name("TestCelostnost")
	.dwattr $C$DW$272, DW_AT_low_pc(_TestCelostnost__Fv)
	.dwattr $C$DW$272, DW_AT_high_pc(0x00)
	.dwattr $C$DW$272, DW_AT_TI_symbol_name("_TestCelostnost__Fv")
	.dwattr $C$DW$272, DW_AT_external
	.dwattr $C$DW$272, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$272, DW_AT_TI_begin_file("test_c.cpp")
	.dwattr $C$DW$272, DW_AT_TI_begin_line(0xcf)
	.dwattr $C$DW$272, DW_AT_TI_begin_column(0x08)
	.dwpsn	file "test_c.cpp",line 208,column 1,is_stmt,address _TestCelostnost__Fv

	.dwfde $C$DW$CIE, _TestCelostnost__Fv
;----------------------------------------------------------------------
; 207 | //      memcpy(buf,(char*)sh_mem_read_crypt2+addr, len);               
;----------------------------------------------------------------------

;******************************************************************************
;* FUNCTION NAME: TestCelostnost()                                            *
;*                                                                            *
;*   Regs Modified     : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP,A16,A17,A18,A19,A20,A21,A22,A23,A24, *
;*                           A25,A26,A27,A28,A29,A30,A31,B16,B17,B18,B19,B20, *
;*                           B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31      *
;*   Regs Used         : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP,A16,A17,A18,A19,A20,A21,A22,A23,A24, *
;*                           A25,A26,A27,A28,A29,A30,A31,B16,B17,B18,B19,B20, *
;*                           B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31      *
;*   Local Frame Size  : 0 Args + 4 Auto + 4 Save = 8 byte                    *
;******************************************************************************
_TestCelostnost__Fv:
;** --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
	.dwcfi	save_reg_to_reg, 228, 19
           STW     .D2T2   B3,*SP--(8)       ; |208| 
	.dwcfi	cfa_offset, 8
	.dwcfi	save_reg_to_mem, 19, 0
$C$DW$273	.dwtag  DW_TAG_variable, DW_AT_name("res")
	.dwattr $C$DW$273, DW_AT_TI_symbol_name("_res")
	.dwattr $C$DW$273, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$273, DW_AT_location[DW_OP_breg31 4]
	.dwpsn	file "test_c.cpp",line 209,column 8,is_stmt
           ZERO    .L2     B4                ; |209| 
           STW     .D2T2   B4,*+SP(4)        ; |209| 
	.dwpsn	file "test_c.cpp",line 211,column 1,is_stmt
;----------------------------------------------------------------------
; 212 | //---------------------------------------------------------------------
;     | -------                                                                
;----------------------------------------------------------------------
$C$DW$274	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$274, DW_AT_low_pc(0x00)
	.dwattr $C$DW$274, DW_AT_name("_analysis_hash_fwmem__FP11hash_window")
	.dwattr $C$DW$274, DW_AT_TI_call
           CALL    .S1     _analysis_hash_fwmem__FP11hash_window ; |211| 
           MVKL    .S1     _hwindow,A4
           ADDKPC  .S2     $C$RL9,B3,2       ; |211| 
           MVKH    .S1     _hwindow,A4
$C$RL9:    ; CALL OCCURS {_analysis_hash_fwmem__FP11hash_window} {0}  ; |211| 
           STW     .D2T1   A4,*+SP(4)        ; |211| 
	.dwpsn	file "test_c.cpp",line 213,column 1,is_stmt
;----------------------------------------------------------------------
; 213 | uint32 TestCelostnost()                                                
;----------------------------------------------------------------------
           MV      .L2X    A4,B0
   [!B0]   BNOP    .S1     $C$L6,4           ; |213| 
           ZERO    .L1     A4                ; |213| 
           ; BRANCHCC OCCURS {$C$L6}         ; |213| 
;** --------------------------------------------------------------------------*
           MVK     .L1     0x1,A4            ; |213| 
;** --------------------------------------------------------------------------*
$C$L6:    
	.dwpsn	file "test_c.cpp",line 214,column 1,is_stmt
           LDW     .D2T2   *++SP(8),B3       ; |214| 
           NOP             4
	.dwcfi	cfa_offset, 0
	.dwcfi	restore_reg, 19
	.dwcfi	cfa_offset, 0
$C$DW$275	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$275, DW_AT_low_pc(0x00)
	.dwattr $C$DW$275, DW_AT_TI_return
           RETNOP  .S2     B3,5              ; |214| 
           ; BRANCH OCCURS {B3}              ; |214| 
	.dwattr $C$DW$272, DW_AT_TI_end_file("test_c.cpp")
	.dwattr $C$DW$272, DW_AT_TI_end_line(0xd6)
	.dwattr $C$DW$272, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$272

	.sect	".text"
	.clink
	.global	_TestDozu__FP12kdg_rez_test

$C$DW$276	.dwtag  DW_TAG_subprogram, DW_AT_name("TestDozu")
	.dwattr $C$DW$276, DW_AT_low_pc(_TestDozu__FP12kdg_rez_test)
	.dwattr $C$DW$276, DW_AT_high_pc(0x00)
	.dwattr $C$DW$276, DW_AT_TI_symbol_name("_TestDozu__FP12kdg_rez_test")
	.dwattr $C$DW$276, DW_AT_external
	.dwattr $C$DW$276, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$276, DW_AT_TI_begin_file("test_c.cpp")
	.dwattr $C$DW$276, DW_AT_TI_begin_line(0xd9)
	.dwattr $C$DW$276, DW_AT_TI_begin_column(0x08)
	.dwpsn	file "test_c.cpp",line 218,column 1,is_stmt,address _TestDozu__FP12kdg_rez_test

	.dwfde $C$DW$CIE, _TestDozu__FP12kdg_rez_test
$C$DW$277	.dwtag  DW_TAG_formal_parameter, DW_AT_name("result")
	.dwattr $C$DW$277, DW_AT_TI_symbol_name("_result")
	.dwattr $C$DW$277, DW_AT_type(*$C$DW$T$696)
	.dwattr $C$DW$277, DW_AT_location[DW_OP_reg4]
;----------------------------------------------------------------------
; 217 | res = analysis_hash_fwmem(hwindow);                                    
;----------------------------------------------------------------------

;******************************************************************************
;* FUNCTION NAME: TestDozu(kdg_rez_test *)                                    *
;*                                                                            *
;*   Regs Modified     : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP,A16,A17,A18,A19,A20,A21,A22,A23,A24, *
;*                           A25,A26,A27,A28,A29,A30,A31,B16,B17,B18,B19,B20, *
;*                           B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31      *
;*   Regs Used         : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP,A16,A17,A18,A19,A20,A21,A22,A23,A24, *
;*                           A25,A26,A27,A28,A29,A30,A31,B16,B17,B18,B19,B20, *
;*                           B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31      *
;*   Local Frame Size  : 0 Args + 3604 Auto + 4 Save = 3608 byte              *
;******************************************************************************
_TestDozu__FP12kdg_rez_test:
;** --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
	.dwcfi	save_reg_to_reg, 228, 19
           ADDK    .S2     -3608,SP          ; |218| 
	.dwcfi	cfa_offset, 3608
           STW     .D2T2   B3,*+SP(3608)     ; |218| 
	.dwcfi	save_reg_to_mem, 19, 0
$C$DW$278	.dwtag  DW_TAG_variable, DW_AT_name("result")
	.dwattr $C$DW$278, DW_AT_TI_symbol_name("_result")
	.dwattr $C$DW$278, DW_AT_type(*$C$DW$T$696)
	.dwattr $C$DW$278, DW_AT_location[DW_OP_breg31 4]
$C$DW$279	.dwtag  DW_TAG_variable, DW_AT_name("sh_d")
	.dwattr $C$DW$279, DW_AT_TI_symbol_name("_sh_d")
	.dwattr $C$DW$279, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$279, DW_AT_location[DW_OP_breg31 8]
$C$DW$280	.dwtag  DW_TAG_variable, DW_AT_name("start_adr")
	.dwattr $C$DW$280, DW_AT_TI_symbol_name("_start_adr")
	.dwattr $C$DW$280, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$280, DW_AT_location[DW_OP_breg31 12]
$C$DW$281	.dwtag  DW_TAG_variable, DW_AT_name("buf")
	.dwattr $C$DW$281, DW_AT_TI_symbol_name("_buf")
	.dwattr $C$DW$281, DW_AT_type(*$C$DW$T$740)
	.dwattr $C$DW$281, DW_AT_location[DW_OP_breg31 16]
$C$DW$282	.dwtag  DW_TAG_variable, DW_AT_name("one")
	.dwattr $C$DW$282, DW_AT_TI_symbol_name("_one")
	.dwattr $C$DW$282, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$282, DW_AT_location[DW_OP_breg31 3600]
;----------------------------------------------------------------------
; 219 | return res == 0 ? 0 : 1;                                               
;----------------------------------------------------------------------
           STW     .D2T1   A4,*+SP(4)        ; |218| 
	.dwpsn	file "test_c.cpp",line 221,column 8,is_stmt
;----------------------------------------------------------------------
; 222 | //---------------------------------------------------------------------
;     | -------                                                                
; 223 | uint32 TestDozu(kdg_rez_test* result)                                  
;----------------------------------------------------------------------
           MVK     .L2     4,B4              ; |221| 
           STW     .D2T2   B4,*+SP(8)        ; |221| 
	.dwpsn	file "test_c.cpp",line 225,column 8,is_stmt
;----------------------------------------------------------------------
; 225 | //uint32 res = 0;                                                      
; 226 | //int error = 0;                                                       
; 227 | uint32 sh_d = SH_DOZU/8;                                               
; 228 | #ifdef TPO_M711B                                                       
; 229 | uint32 start_adr = 0x100;                                              
; 230 | #else                                                                  
; 231 | uint32 start_adr = 0;                                                  
; 232 | #endif                                                                 
;----------------------------------------------------------------------
           ZERO    .L1     A3                ; |225| 
           STW     .D2T1   A3,*+SP(12)       ; |225| 
	.dwpsn	file "test_c.cpp",line 234,column 8,is_stmt
;----------------------------------------------------------------------
; 236 | #ifdef TPO5                                                            
; 237 | uint32 buf[LEN_BUF_FOR_TEST_DOZU];                                     
; 238 | #define DAT555  0x55555555                                             
; 239 | #define DATAAA  0xAAAAAAAA                                             
; 240 | uint32 one = 1;                                                        
; 241 | #else                                                                  
; 242 | uint64 buf[LEN_BUF_FOR_TEST_DOZU];                                     
; 243 | #define DAT555  0x5555555555555555                                     
;----------------------------------------------------------------------
           MVK     .L1     1,A3              ; |234| 
           STW     .D2T1   A3,*+SP(3600)     ; |234| 
	.dwpsn	file "test_c.cpp",line 244,column 1,is_stmt
;----------------------------------------------------------------------
; 244 | #define DATAAA  0xAAAAAAAAAAAAAAAA                                     
; 245 | uint64 one = 1;                                                        
;----------------------------------------------------------------------
$C$DW$283	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$283, DW_AT_low_pc(0x00)
	.dwattr $C$DW$283, DW_AT_name("_ReadDARAM0__FUsPvT1")
	.dwattr $C$DW$283, DW_AT_TI_call
           CALL    .S1     _ReadDARAM0__FUsPvT1 ; |244| 
           LDHU    .D2T1   *+SP(12),A4       ; |244| 
           ADDKPC  .S2     $C$RL10,B3,2      ; |244| 

           ADD     .D2     SP,16,B4          ; |244| 
||         MVK     .S1     0xe00,A6          ; |244| 

$C$RL10:   ; CALL OCCURS {_ReadDARAM0__FUsPvT1} {0}  ; |244| 

$C$DW$284	.dwtag  DW_TAG_lexical_block, DW_AT_low_pc(0x00), DW_AT_high_pc(0x00)
$C$DW$285	.dwtag  DW_TAG_variable, DW_AT_name("i")
	.dwattr $C$DW$285, DW_AT_TI_symbol_name("_i")
	.dwattr $C$DW$285, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$285, DW_AT_location[DW_OP_breg31 3604]
	.dwpsn	file "test_c.cpp",line 246,column 11,is_stmt
;----------------------------------------------------------------------
; 246 | #endif                                                                 
;----------------------------------------------------------------------
           ZERO    .L2     B4                ; |246| 
           STW     .D2T2   B4,*+SP(3604)     ; |246| 
	.dwpsn	file "test_c.cpp",line 246,column 18,is_stmt
           MVK     .S2     32,B5             ; |246| 
           CMPLT   .L2     B4,B5,B0          ; |246| 
   [!B0]   BNOP    .S1     $C$L9,5           ; |246| 
           ; BRANCHCC OCCURS {$C$L9}         ; |246| 
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
$C$L7:    
$C$DW$L$_TestDozu__FP12kdg_rez_test$2$B:
	.dwpsn	file "test_c.cpp",line 248,column 4,is_stmt

           MV      .L2     B4,B5
||         ADDAW   .D2     SP,B4,B4          ; |248| 

           LDW     .D2T2   *+SP(3600),B6     ; |248| 
           LDW     .D2T2   *+B4(16),B7       ; |248| 
           NOP             3
           SHL     .S2     B6,B5,B4          ; |248| 
           CMPEQ   .L2     B7,B4,B0          ; |248| 
   [ B0]   BNOP    .S1     $C$L8,5           ; |248| 
           ; BRANCHCC OCCURS {$C$L8}         ; |248| 
$C$DW$L$_TestDozu__FP12kdg_rez_test$2$E:
;** --------------------------------------------------------------------------*
	.dwpsn	file "test_c.cpp",line 250,column 4,is_stmt
;----------------------------------------------------------------------
; 250 | ReadDARAM0(start_adr, buf, LEN_DUZU_FOR_TEST);                         
;----------------------------------------------------------------------
           MV      .L2     B5,B4
           ADDAW   .D2     SP,B4,B4          ; |250| 
           LDW     .D2T2   *+B4(16),B4       ; |250| 
           LDW     .D2T2   *+SP(4),B7        ; |250| 
           SHL     .S2     B6,B5,B5          ; |250| 
           NOP             2
           XOR     .L2     B5,B4,B4          ; |250| 
           STW     .D2T2   B4,*+B7(16)       ; |250| 
	.dwpsn	file "test_c.cpp",line 251,column 4,is_stmt
           LDW     .D2T2   *+SP(3604),B4     ; |251| 
           LDW     .D2T2   *+SP(8),B5        ; |251| 
           LDW     .D2T2   *+SP(4),B6        ; |251| 
           NOP             3
           MPYLH   .M2     B5,B4,B8          ; |251| 
           MPYLH   .M2     B4,B5,B7          ; |251| 
           MPYU    .M2     B5,B4,B5          ; |251| 
           ADD     .L2     B8,B7,B4          ; |251| 
           SHL     .S2     B4,16,B4          ; |251| 
           ADD     .L2     B5,B4,B4          ; |251| 
           STW     .D2T2   B4,*+B6(12)       ; |251| 
	.dwpsn	file "test_c.cpp",line 252,column 4,is_stmt
;----------------------------------------------------------------------
; 252 | for(int i = 0; i < SH_DOZU; i++)                                       
; 254 |         if(buf[i] != one << i)                                         
;----------------------------------------------------------------------
           BNOP    .S1     $C$L21,4          ; |252| 
           MVK     .L1     0x5,A4            ; |252| 
           ; BRANCH OCCURS {$C$L21}          ; |252| 
;** --------------------------------------------------------------------------*
$C$L8:    
$C$DW$L$_TestDozu__FP12kdg_rez_test$4$B:
	.dwpsn	file "test_c.cpp",line 246,column 31,is_stmt
           ADD     .L2     1,B5,B4           ; |246| 
           STW     .D2T2   B4,*+SP(3604)     ; |246| 
	.dwpsn	file "test_c.cpp",line 246,column 18,is_stmt
           MVK     .S2     32,B5             ; |246| 
           CMPLT   .L2     B4,B5,B0          ; |246| 
   [ B0]   BNOP    .S1     $C$L7,5           ; |246| 
           ; BRANCHCC OCCURS {$C$L7}         ; |246| 
$C$DW$L$_TestDozu__FP12kdg_rez_test$4$E:
;** --------------------------------------------------------------------------*
$C$L9:    
	.dwendtag $C$DW$284


$C$DW$286	.dwtag  DW_TAG_lexical_block, DW_AT_low_pc(0x00), DW_AT_high_pc(0x00)
$C$DW$287	.dwtag  DW_TAG_variable, DW_AT_name("i")
	.dwattr $C$DW$287, DW_AT_TI_symbol_name("_i")
	.dwattr $C$DW$287, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$287, DW_AT_location[DW_OP_breg31 3604]
	.dwpsn	file "test_c.cpp",line 256,column 11,is_stmt
;----------------------------------------------------------------------
; 256 | result->data = buf[i] ^ (one << i);                                    
;----------------------------------------------------------------------
           MVK     .S1     32,A3             ; |256| 
           STW     .D2T1   A3,*+SP(3604)     ; |256| 
	.dwpsn	file "test_c.cpp",line 256,column 24,is_stmt
;----------------------------------------------------------------------
; 257 | result->adrr = i * sh_d;                                               
;----------------------------------------------------------------------

           MV      .L2     B5,B4
||         MVK     .S2     896,B5            ; |256| 

           CMPLT   .L2     B4,B5,B0          ; |256| 
   [!B0]   BNOP    .S1     $C$L13,5          ; |256| 
           ; BRANCHCC OCCURS {$C$L13}        ; |256| 
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
$C$L10:    
$C$DW$L$_TestDozu__FP12kdg_rez_test$6$B:
	.dwpsn	file "test_c.cpp",line 258,column 4,is_stmt
;----------------------------------------------------------------------
; 258 | return ERR_DOZU_WRCP0_RDSP;                                            
;----------------------------------------------------------------------
           ADDAW   .D2     SP,B4,B4          ; |258| 
           LDW     .D2T2   *+B4(16),B4       ; |258| 
           MVKL    .S2     0x55555555,B5
           MVKH    .S2     0x55555555,B5
           NOP             2
           CMPEQ   .L2     B4,B5,B0          ; |258| 
   [ B0]   BNOP    .S1     $C$L11,5          ; |258| 
           ; BRANCHCC OCCURS {$C$L11}        ; |258| 
$C$DW$L$_TestDozu__FP12kdg_rez_test$6$E:
;** --------------------------------------------------------------------------*
	.dwpsn	file "test_c.cpp",line 260,column 4,is_stmt
           LDW     .D2T2   *+SP(3604),B4     ; |260| 
           LDW     .D2T2   *+SP(4),B31       ; |260| 
           NOP             3
           ADDAW   .D2     SP,B4,B4          ; |260| 
           LDW     .D2T2   *+B4(16),B6       ; |260| 
           NOP             4
           XOR     .L2     B5,B6,B5          ; |260| 
           STW     .D2T2   B5,*+B31(16)      ; |260| 
	.dwpsn	file "test_c.cpp",line 261,column 4,is_stmt
           LDW     .D2T2   *+SP(3604),B7     ; |261| 
           LDW     .D2T2   *+SP(8),B8        ; |261| 
           LDW     .D2T2   *+SP(4),B6        ; |261| 
           NOP             3
           MPYLH   .M2     B8,B7,B5          ; |261| 
           MPYLH   .M2     B7,B8,B4          ; |261| 
           MPYU    .M2     B8,B7,B30         ; |261| 
           ADD     .L2     B5,B4,B4          ; |261| 
           SHL     .S2     B4,16,B4          ; |261| 
           ADD     .L2     B30,B4,B4         ; |261| 
           STW     .D2T2   B4,*+B6(12)       ; |261| 
	.dwpsn	file "test_c.cpp",line 262,column 4,is_stmt
;----------------------------------------------------------------------
; 262 | for(int i = SH_DOZU; i < LEN_BUF_FOR_TEST_DOZU; i+=2)                  
; 264 |         if(buf[i] != DAT555)                                           
;----------------------------------------------------------------------
           BNOP    .S1     $C$L21,4          ; |262| 
           MVK     .L1     0x5,A4            ; |262| 
           ; BRANCH OCCURS {$C$L21}          ; |262| 
;** --------------------------------------------------------------------------*
$C$L11:    
$C$DW$L$_TestDozu__FP12kdg_rez_test$8$B:
	.dwpsn	file "test_c.cpp",line 265,column 4,is_stmt
;----------------------------------------------------------------------
; 266 | result->data = buf[i] ^ DAT555;                                        
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(3604),B4     ; |265| 
           MVKL    .S2     0xaaaaaaaa,B5
           MVKH    .S2     0xaaaaaaaa,B5
           NOP             2
           ADD     .L2     1,B4,B4           ; |265| 
           ADDAW   .D2     SP,B4,B4          ; |265| 
           LDW     .D2T2   *+B4(16),B4       ; |265| 
           NOP             4
           CMPEQ   .L2     B4,B5,B0          ; |265| 
   [ B0]   BNOP    .S1     $C$L12,5          ; |265| 
           ; BRANCHCC OCCURS {$C$L12}        ; |265| 
$C$DW$L$_TestDozu__FP12kdg_rez_test$8$E:
;** --------------------------------------------------------------------------*
	.dwpsn	file "test_c.cpp",line 267,column 4,is_stmt
;----------------------------------------------------------------------
; 267 | result->adrr = i * sh_d;                                               
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(3604),B4     ; |267| 
           LDW     .D2T2   *+SP(4),B31       ; |267| 
           NOP             3
           ADD     .L2     1,B4,B4           ; |267| 
           ADDAW   .D2     SP,B4,B4          ; |267| 
           LDW     .D2T2   *+B4(16),B6       ; |267| 
           NOP             4
           XOR     .L2     B5,B6,B5          ; |267| 
           STW     .D2T2   B5,*+B31(16)      ; |267| 
	.dwpsn	file "test_c.cpp",line 268,column 4,is_stmt
;----------------------------------------------------------------------
; 268 | return ERR_DOZU_WRCP0_RDSP;                                            
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(3604),B4     ; |268| 
           LDW     .D2T2   *+SP(8),B7        ; |268| 
           LDW     .D2T2   *+SP(4),B5        ; |268| 
           NOP             2
           ADD     .L2     1,B4,B6           ; |268| 
           MPYLH   .M2     B7,B6,B8          ; |268| 
           MPYLH   .M2     B6,B7,B4          ; |268| 
           MPYU    .M2     B7,B6,B6          ; |268| 
           ADD     .L2     B8,B4,B4          ; |268| 
           SHL     .S2     B4,16,B4          ; |268| 
           ADD     .L2     B6,B4,B4          ; |268| 
           STW     .D2T2   B4,*+B5(12)       ; |268| 
	.dwpsn	file "test_c.cpp",line 269,column 4,is_stmt
;----------------------------------------------------------------------
; 271 | if(buf[i+1] != DATAAA)                                                 
; 273 | result->data = buf[i+1] ^ DATAAA;                                      
;----------------------------------------------------------------------
           BNOP    .S1     $C$L21,4          ; |269| 
           MVK     .L1     0x5,A4            ; |269| 
           ; BRANCH OCCURS {$C$L21}          ; |269| 
;** --------------------------------------------------------------------------*
$C$L12:    
$C$DW$L$_TestDozu__FP12kdg_rez_test$10$B:
	.dwpsn	file "test_c.cpp",line 256,column 51,is_stmt
           LDW     .D2T2   *+SP(3604),B4     ; |256| 
           NOP             4
           ADD     .L2     2,B4,B4           ; |256| 
           STW     .D2T2   B4,*+SP(3604)     ; |256| 
	.dwpsn	file "test_c.cpp",line 256,column 24,is_stmt
           MVK     .S2     896,B5            ; |256| 
           CMPLT   .L2     B4,B5,B0          ; |256| 
   [ B0]   BNOP    .S1     $C$L10,5          ; |256| 
           ; BRANCHCC OCCURS {$C$L10}        ; |256| 
$C$DW$L$_TestDozu__FP12kdg_rez_test$10$E:
;** --------------------------------------------------------------------------*
$C$L13:    
	.dwendtag $C$DW$286

	.dwpsn	file "test_c.cpp",line 274,column 1,is_stmt
;----------------------------------------------------------------------
; 274 | result->adrr = (i+1) * sh_d;                                           
; 275 | return ERR_DOZU_WRCP0_RDSP;                                            
;----------------------------------------------------------------------
$C$DW$288	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$288, DW_AT_low_pc(0x00)
	.dwattr $C$DW$288, DW_AT_name("_ReadDARAM1__FUsPvT1")
	.dwattr $C$DW$288, DW_AT_TI_call
           CALL    .S1     _ReadDARAM1__FUsPvT1 ; |274| 
           LDHU    .D2T1   *+SP(12),A4       ; |274| 
           ADDKPC  .S2     $C$RL11,B3,2      ; |274| 

           ADD     .D2     SP,16,B4          ; |274| 
||         MVK     .S1     0xe00,A6          ; |274| 

$C$RL11:   ; CALL OCCURS {_ReadDARAM1__FUsPvT1} {0}  ; |274| 

$C$DW$289	.dwtag  DW_TAG_lexical_block, DW_AT_low_pc(0x00), DW_AT_high_pc(0x00)
$C$DW$290	.dwtag  DW_TAG_variable, DW_AT_name("i")
	.dwattr $C$DW$290, DW_AT_TI_symbol_name("_i")
	.dwattr $C$DW$290, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$290, DW_AT_location[DW_OP_breg31 3604]
	.dwpsn	file "test_c.cpp",line 276,column 11,is_stmt
           ZERO    .L2     B4                ; |276| 
           STW     .D2T2   B4,*+SP(3604)     ; |276| 
	.dwpsn	file "test_c.cpp",line 276,column 18,is_stmt
           MVK     .S2     32,B5             ; |276| 
           CMPLT   .L2     B4,B5,B0          ; |276| 
   [!B0]   BNOP    .S1     $C$L16,5          ; |276| 
           ; BRANCHCC OCCURS {$C$L16}        ; |276| 
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
$C$L14:    
$C$DW$L$_TestDozu__FP12kdg_rez_test$12$B:
	.dwpsn	file "test_c.cpp",line 278,column 4,is_stmt
           MV      .L2     B4,B6
           ADDAW   .D2     SP,B6,B6          ; |278| 

           MV      .L2     B4,B5
||         LDW     .D2T2   *+SP(3600),B4     ; |278| 

           LDW     .D2T2   *+B6(16),B6       ; |278| 
           NOP             3
           SHL     .S2     B4,B5,B4          ; |278| 
           CMPEQ   .L2     B6,B4,B0          ; |278| 
   [ B0]   BNOP    .S1     $C$L15,5          ; |278| 
           ; BRANCHCC OCCURS {$C$L15}        ; |278| 
$C$DW$L$_TestDozu__FP12kdg_rez_test$12$E:
;** --------------------------------------------------------------------------*
	.dwpsn	file "test_c.cpp",line 280,column 4,is_stmt
;----------------------------------------------------------------------
; 280 | ReadDARAM1(start_adr, buf, LEN_DUZU_FOR_TEST);                         
;----------------------------------------------------------------------
           MV      .L2     B5,B4
           ADDAW   .D2     SP,B4,B4          ; |280| 
           LDW     .D2T2   *+SP(3600),B6     ; |280| 
           LDW     .D2T2   *+B4(16),B4       ; |280| 
           LDW     .D2T2   *+SP(4),B7        ; |280| 
           NOP             2
           SHL     .S2     B6,B5,B5          ; |280| 
           XOR     .L2     B5,B4,B4          ; |280| 
           STW     .D2T2   B4,*+B7(16)       ; |280| 
	.dwpsn	file "test_c.cpp",line 281,column 4,is_stmt
           LDW     .D2T2   *+SP(8),B8        ; |281| 
           LDW     .D2T2   *+SP(3604),B4     ; |281| 
           LDW     .D2T2   *+SP(4),B7        ; |281| 
           NOP             3
           MPYLH   .M2     B8,B4,B5          ; |281| 
           MPYLH   .M2     B4,B8,B6          ; |281| 
           NOP             1

           ADD     .L2     B5,B6,B4          ; |281| 
||         MPYU    .M2     B8,B4,B5          ; |281| 

           SHL     .S2     B4,16,B4          ; |281| 
           ADD     .L2     B5,B4,B4          ; |281| 
           STW     .D2T2   B4,*+B7(12)       ; |281| 
	.dwpsn	file "test_c.cpp",line 282,column 4,is_stmt
;----------------------------------------------------------------------
; 282 | for(int i = 0; i < SH_DOZU; i++)                                       
; 284 |         if(buf[i] != one << i)                                         
;----------------------------------------------------------------------
           BNOP    .S1     $C$L21,4          ; |282| 
           MVK     .L1     0x6,A4            ; |282| 
           ; BRANCH OCCURS {$C$L21}          ; |282| 
;** --------------------------------------------------------------------------*
$C$L15:    
$C$DW$L$_TestDozu__FP12kdg_rez_test$14$B:
	.dwpsn	file "test_c.cpp",line 276,column 31,is_stmt
           ADD     .L2     1,B5,B4           ; |276| 
           STW     .D2T2   B4,*+SP(3604)     ; |276| 
	.dwpsn	file "test_c.cpp",line 276,column 18,is_stmt
           MVK     .S2     32,B5             ; |276| 
           CMPLT   .L2     B4,B5,B0          ; |276| 
   [ B0]   BNOP    .S1     $C$L14,5          ; |276| 
           ; BRANCHCC OCCURS {$C$L14}        ; |276| 
$C$DW$L$_TestDozu__FP12kdg_rez_test$14$E:
;** --------------------------------------------------------------------------*
$C$L16:    
	.dwendtag $C$DW$289


$C$DW$291	.dwtag  DW_TAG_lexical_block, DW_AT_low_pc(0x00), DW_AT_high_pc(0x00)
$C$DW$292	.dwtag  DW_TAG_variable, DW_AT_name("i")
	.dwattr $C$DW$292, DW_AT_TI_symbol_name("_i")
	.dwattr $C$DW$292, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$292, DW_AT_location[DW_OP_breg31 3604]
	.dwpsn	file "test_c.cpp",line 286,column 11,is_stmt
;----------------------------------------------------------------------
; 286 | result->data = buf[i] ^ (one << i);                                    
;----------------------------------------------------------------------
           MVK     .S1     32,A3             ; |286| 
           STW     .D2T1   A3,*+SP(3604)     ; |286| 
	.dwpsn	file "test_c.cpp",line 286,column 24,is_stmt
;----------------------------------------------------------------------
; 287 | result->adrr = i * sh_d;                                               
;----------------------------------------------------------------------

           MV      .L2     B5,B4
||         MVK     .S2     896,B5            ; |286| 

           CMPLT   .L2     B4,B5,B0          ; |286| 
   [!B0]   BNOP    .S1     $C$L20,5          ; |286| 
           ; BRANCHCC OCCURS {$C$L20}        ; |286| 
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
$C$L17:    
$C$DW$L$_TestDozu__FP12kdg_rez_test$16$B:
	.dwpsn	file "test_c.cpp",line 288,column 4,is_stmt
;----------------------------------------------------------------------
; 288 | return ERR_DOZU_WRCP1_RDSP;                                            
;----------------------------------------------------------------------
           ADDAW   .D2     SP,B4,B4          ; |288| 
           LDW     .D2T2   *+B4(16),B4       ; |288| 
           MVKL    .S2     0x55555555,B5
           MVKH    .S2     0x55555555,B5
           NOP             2
           CMPEQ   .L2     B4,B5,B0          ; |288| 
   [ B0]   BNOP    .S1     $C$L18,5          ; |288| 
           ; BRANCHCC OCCURS {$C$L18}        ; |288| 
$C$DW$L$_TestDozu__FP12kdg_rez_test$16$E:
;** --------------------------------------------------------------------------*
	.dwpsn	file "test_c.cpp",line 290,column 4,is_stmt
           LDW     .D2T2   *+SP(3604),B4     ; |290| 
           LDW     .D2T2   *+SP(4),B31       ; |290| 
           NOP             3
           ADDAW   .D2     SP,B4,B4          ; |290| 
           LDW     .D2T2   *+B4(16),B6       ; |290| 
           NOP             4
           XOR     .L2     B5,B6,B5          ; |290| 
           STW     .D2T2   B5,*+B31(16)      ; |290| 
	.dwpsn	file "test_c.cpp",line 291,column 4,is_stmt
           LDW     .D2T2   *+SP(3604),B4     ; |291| 
           LDW     .D2T2   *+SP(8),B6        ; |291| 
           LDW     .D2T2   *+SP(4),B5        ; |291| 
           NOP             3
           MPYLH   .M2     B6,B4,B8          ; |291| 
           MPYLH   .M2     B4,B6,B7          ; |291| 
           MPYU    .M2     B6,B4,B6          ; |291| 
           ADD     .L2     B8,B7,B4          ; |291| 
           SHL     .S2     B4,16,B4          ; |291| 
           ADD     .L2     B6,B4,B4          ; |291| 
           STW     .D2T2   B4,*+B5(12)       ; |291| 
	.dwpsn	file "test_c.cpp",line 292,column 4,is_stmt
;----------------------------------------------------------------------
; 292 | for(int i = SH_DOZU; i < LEN_BUF_FOR_TEST_DOZU; i+=2)                  
; 294 |         if(buf[i] != DAT555)                                           
;----------------------------------------------------------------------
           BNOP    .S1     $C$L21,4          ; |292| 
           MVK     .L1     0x6,A4            ; |292| 
           ; BRANCH OCCURS {$C$L21}          ; |292| 
;** --------------------------------------------------------------------------*
$C$L18:    
$C$DW$L$_TestDozu__FP12kdg_rez_test$18$B:
	.dwpsn	file "test_c.cpp",line 295,column 4,is_stmt
;----------------------------------------------------------------------
; 296 | result->data = buf[i] ^ DAT555;                                        
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(3604),B4     ; |295| 
           MVKL    .S2     0xaaaaaaaa,B5
           MVKH    .S2     0xaaaaaaaa,B5
           NOP             2
           ADD     .L2     1,B4,B4           ; |295| 
           ADDAW   .D2     SP,B4,B4          ; |295| 
           LDW     .D2T2   *+B4(16),B4       ; |295| 
           NOP             4
           CMPEQ   .L2     B4,B5,B0          ; |295| 
   [ B0]   BNOP    .S1     $C$L19,5          ; |295| 
           ; BRANCHCC OCCURS {$C$L19}        ; |295| 
$C$DW$L$_TestDozu__FP12kdg_rez_test$18$E:
;** --------------------------------------------------------------------------*
	.dwpsn	file "test_c.cpp",line 297,column 4,is_stmt
;----------------------------------------------------------------------
; 297 | result->adrr = i * sh_d;                                               
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(3604),B4     ; |297| 
           LDW     .D2T2   *+SP(4),B31       ; |297| 
           NOP             3
           ADD     .L2     1,B4,B4           ; |297| 
           ADDAW   .D2     SP,B4,B4          ; |297| 
           LDW     .D2T2   *+B4(16),B6       ; |297| 
           NOP             4
           XOR     .L2     B5,B6,B5          ; |297| 
           STW     .D2T2   B5,*+B31(16)      ; |297| 
	.dwpsn	file "test_c.cpp",line 298,column 4,is_stmt
;----------------------------------------------------------------------
; 298 | return ERR_DOZU_WRCP1_RDSP;                                            
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(3604),B4     ; |298| 
           LDW     .D2T2   *+SP(8),B5        ; |298| 
           LDW     .D2T2   *+SP(4),B7        ; |298| 
           NOP             2
           ADD     .L2     1,B4,B4           ; |298| 
           MPYLH   .M2     B4,B5,B8          ; |298| 
           MPYLH   .M2     B5,B4,B6          ; |298| 
           MPYU    .M2     B5,B4,B5          ; |298| 
           ADD     .L2     B6,B8,B4          ; |298| 
           SHL     .S2     B4,16,B4          ; |298| 
           ADD     .L2     B5,B4,B4          ; |298| 
           STW     .D2T2   B4,*+B7(12)       ; |298| 
	.dwpsn	file "test_c.cpp",line 299,column 4,is_stmt
;----------------------------------------------------------------------
; 301 | if(buf[i+1] != DATAAA)                                                 
;----------------------------------------------------------------------
           BNOP    .S1     $C$L21,4          ; |299| 
           MVK     .L1     0x6,A4            ; |299| 
           ; BRANCH OCCURS {$C$L21}          ; |299| 
;** --------------------------------------------------------------------------*
$C$L19:    
$C$DW$L$_TestDozu__FP12kdg_rez_test$20$B:
	.dwpsn	file "test_c.cpp",line 286,column 51,is_stmt
           LDW     .D2T2   *+SP(3604),B4     ; |286| 
           NOP             4
           ADD     .L2     2,B4,B4           ; |286| 
           STW     .D2T2   B4,*+SP(3604)     ; |286| 
	.dwpsn	file "test_c.cpp",line 286,column 24,is_stmt
           MVK     .S2     896,B5            ; |286| 
           CMPLT   .L2     B4,B5,B0          ; |286| 
   [ B0]   BNOP    .S1     $C$L17,5          ; |286| 
           ; BRANCHCC OCCURS {$C$L17}        ; |286| 
$C$DW$L$_TestDozu__FP12kdg_rez_test$20$E:
;** --------------------------------------------------------------------------*
$C$L20:    
	.dwendtag $C$DW$291

	.dwpsn	file "test_c.cpp",line 303,column 1,is_stmt
;----------------------------------------------------------------------
; 303 | result->data = buf[i+1] ^ DATAAA;                                      
; 304 | result->adrr = (i+1) * sh_d;                                           
;----------------------------------------------------------------------
$C$DW$293	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$293, DW_AT_low_pc(0x00)
	.dwattr $C$DW$293, DW_AT_name("_WriteDARAM__FUsPvT1")
	.dwattr $C$DW$293, DW_AT_TI_call
           CALL    .S1     _WriteDARAM__FUsPvT1 ; |303| 
           LDHU    .D2T1   *+SP(12),A4       ; |303| 
           ADDKPC  .S2     $C$RL12,B3,2      ; |303| 

           ADD     .D2     SP,16,B4          ; |303| 
||         MVK     .S1     0xe00,A6          ; |303| 

$C$RL12:   ; CALL OCCURS {_WriteDARAM__FUsPvT1} {0}  ; |303| 
	.dwpsn	file "test_c.cpp",line 305,column 1,is_stmt
;----------------------------------------------------------------------
; 305 | return ERR_DOZU_WRCP1_RDSP;                                            
;----------------------------------------------------------------------
           ZERO    .L1     A4                ; |305| 
;** --------------------------------------------------------------------------*
$C$L21:    
	.dwpsn	file "test_c.cpp",line 306,column 1,is_stmt
           LDW     .D2T2   *+SP(3608),B3     ; |306| 
           NOP             4
	.dwcfi	restore_reg, 19
           ADDK    .S2     3608,SP           ; |306| 
	.dwcfi	cfa_offset, 0
	.dwcfi	cfa_offset, 0
$C$DW$294	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$294, DW_AT_low_pc(0x00)
	.dwattr $C$DW$294, DW_AT_TI_return
           RETNOP  .S2     B3,5              ; |306| 
           ; BRANCH OCCURS {B3}              ; |306| 

$C$DW$295	.dwtag  DW_TAG_TI_loop
	.dwattr $C$DW$295, DW_AT_name("C:\1901VC1T_Inteltech\3rdPartyLIB\dsp_core\C6000\tpo_amoeba\source\test_c.asm:$C$L17:1:1517815039")
	.dwattr $C$DW$295, DW_AT_TI_begin_file("test_c.cpp")
	.dwattr $C$DW$295, DW_AT_TI_begin_line(0x11e)
	.dwattr $C$DW$295, DW_AT_TI_end_line(0x12d)
$C$DW$296	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$296, DW_AT_low_pc($C$DW$L$_TestDozu__FP12kdg_rez_test$16$B)
	.dwattr $C$DW$296, DW_AT_high_pc($C$DW$L$_TestDozu__FP12kdg_rez_test$16$E)
$C$DW$297	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$297, DW_AT_low_pc($C$DW$L$_TestDozu__FP12kdg_rez_test$18$B)
	.dwattr $C$DW$297, DW_AT_high_pc($C$DW$L$_TestDozu__FP12kdg_rez_test$18$E)
$C$DW$298	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$298, DW_AT_low_pc($C$DW$L$_TestDozu__FP12kdg_rez_test$20$B)
	.dwattr $C$DW$298, DW_AT_high_pc($C$DW$L$_TestDozu__FP12kdg_rez_test$20$E)
	.dwendtag $C$DW$295


$C$DW$299	.dwtag  DW_TAG_TI_loop
	.dwattr $C$DW$299, DW_AT_name("C:\1901VC1T_Inteltech\3rdPartyLIB\dsp_core\C6000\tpo_amoeba\source\test_c.asm:$C$L14:1:1517815039")
	.dwattr $C$DW$299, DW_AT_TI_begin_file("test_c.cpp")
	.dwattr $C$DW$299, DW_AT_TI_begin_line(0x114)
	.dwattr $C$DW$299, DW_AT_TI_end_line(0x11c)
$C$DW$300	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$300, DW_AT_low_pc($C$DW$L$_TestDozu__FP12kdg_rez_test$12$B)
	.dwattr $C$DW$300, DW_AT_high_pc($C$DW$L$_TestDozu__FP12kdg_rez_test$12$E)
$C$DW$301	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$301, DW_AT_low_pc($C$DW$L$_TestDozu__FP12kdg_rez_test$14$B)
	.dwattr $C$DW$301, DW_AT_high_pc($C$DW$L$_TestDozu__FP12kdg_rez_test$14$E)
	.dwendtag $C$DW$299


$C$DW$302	.dwtag  DW_TAG_TI_loop
	.dwattr $C$DW$302, DW_AT_name("C:\1901VC1T_Inteltech\3rdPartyLIB\dsp_core\C6000\tpo_amoeba\source\test_c.asm:$C$L10:1:1517815039")
	.dwattr $C$DW$302, DW_AT_TI_begin_file("test_c.cpp")
	.dwattr $C$DW$302, DW_AT_TI_begin_line(0x100)
	.dwattr $C$DW$302, DW_AT_TI_end_line(0x10f)
$C$DW$303	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$303, DW_AT_low_pc($C$DW$L$_TestDozu__FP12kdg_rez_test$6$B)
	.dwattr $C$DW$303, DW_AT_high_pc($C$DW$L$_TestDozu__FP12kdg_rez_test$6$E)
$C$DW$304	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$304, DW_AT_low_pc($C$DW$L$_TestDozu__FP12kdg_rez_test$8$B)
	.dwattr $C$DW$304, DW_AT_high_pc($C$DW$L$_TestDozu__FP12kdg_rez_test$8$E)
$C$DW$305	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$305, DW_AT_low_pc($C$DW$L$_TestDozu__FP12kdg_rez_test$10$B)
	.dwattr $C$DW$305, DW_AT_high_pc($C$DW$L$_TestDozu__FP12kdg_rez_test$10$E)
	.dwendtag $C$DW$302


$C$DW$306	.dwtag  DW_TAG_TI_loop
	.dwattr $C$DW$306, DW_AT_name("C:\1901VC1T_Inteltech\3rdPartyLIB\dsp_core\C6000\tpo_amoeba\source\test_c.asm:$C$L7:1:1517815039")
	.dwattr $C$DW$306, DW_AT_TI_begin_file("test_c.cpp")
	.dwattr $C$DW$306, DW_AT_TI_begin_line(0xf6)
	.dwattr $C$DW$306, DW_AT_TI_end_line(0xfe)
$C$DW$307	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$307, DW_AT_low_pc($C$DW$L$_TestDozu__FP12kdg_rez_test$2$B)
	.dwattr $C$DW$307, DW_AT_high_pc($C$DW$L$_TestDozu__FP12kdg_rez_test$2$E)
$C$DW$308	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$308, DW_AT_low_pc($C$DW$L$_TestDozu__FP12kdg_rez_test$4$B)
	.dwattr $C$DW$308, DW_AT_high_pc($C$DW$L$_TestDozu__FP12kdg_rez_test$4$E)
	.dwendtag $C$DW$306

	.dwattr $C$DW$276, DW_AT_TI_end_file("test_c.cpp")
	.dwattr $C$DW$276, DW_AT_TI_end_line(0x132)
	.dwattr $C$DW$276, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$276

	.sect	".text"
	.clink
	.global	_TestMove__Fv

$C$DW$309	.dwtag  DW_TAG_subprogram, DW_AT_name("TestMove")
	.dwattr $C$DW$309, DW_AT_low_pc(_TestMove__Fv)
	.dwattr $C$DW$309, DW_AT_high_pc(0x00)
	.dwattr $C$DW$309, DW_AT_TI_symbol_name("_TestMove__Fv")
	.dwattr $C$DW$309, DW_AT_external
	.dwattr $C$DW$309, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$309, DW_AT_TI_begin_file("test_c.cpp")
	.dwattr $C$DW$309, DW_AT_TI_begin_line(0x136)
	.dwattr $C$DW$309, DW_AT_TI_begin_column(0x08)
	.dwpsn	file "test_c.cpp",line 311,column 1,is_stmt,address _TestMove__Fv

	.dwfde $C$DW$CIE, _TestMove__Fv

;******************************************************************************
;* FUNCTION NAME: TestMove()                                                  *
;*                                                                            *
;*   Regs Modified     : A3,A4,A6,B0,B3,B4,B5,B6,SP,B31                       *
;*   Regs Used         : A3,A4,A6,B0,B3,B4,B5,B6,SP,B31                       *
;*   Local Frame Size  : 0 Args + 3596 Auto + 4 Save = 3600 byte              *
;******************************************************************************
_TestMove__Fv:
;** --------------------------------------------------------------------------*
;----------------------------------------------------------------------
; 311 | return TPO_OK;                                                         
; 315 | //---------------------------------------------------------------------
;     | -------                                                                
; 316 | uint32 TestMove()                                                      
;----------------------------------------------------------------------
	.dwcfi	cfa_offset, 0
	.dwcfi	save_reg_to_reg, 228, 19
           ADDK    .S2     -3600,SP          ; |311| 
	.dwcfi	cfa_offset, 3600
           STW     .D2T2   B3,*+SP(3600)     ; |311| 
	.dwcfi	save_reg_to_mem, 19, 0
$C$DW$310	.dwtag  DW_TAG_variable, DW_AT_name("start_adr")
	.dwattr $C$DW$310, DW_AT_TI_symbol_name("_start_adr")
	.dwattr $C$DW$310, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$310, DW_AT_location[DW_OP_breg31 4]
$C$DW$311	.dwtag  DW_TAG_variable, DW_AT_name("buf")
	.dwattr $C$DW$311, DW_AT_TI_symbol_name("_buf")
	.dwattr $C$DW$311, DW_AT_type(*$C$DW$T$740)
	.dwattr $C$DW$311, DW_AT_location[DW_OP_breg31 8]
$C$DW$312	.dwtag  DW_TAG_variable, DW_AT_name("one")
	.dwattr $C$DW$312, DW_AT_TI_symbol_name("_one")
	.dwattr $C$DW$312, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$312, DW_AT_location[DW_OP_breg31 3592]
	.dwpsn	file "test_c.cpp",line 317,column 8,is_stmt
;----------------------------------------------------------------------
; 318 | //uint32 res = 0;                                                      
; 319 | //int error = 0;                                                       
; 320 | #ifdef TPO_M711B                                                       
; 321 | uint32 start_adr = 0x100;                                              
; 322 | #else                                                                  
; 323 | uint32 start_adr = 0;                                                  
;----------------------------------------------------------------------
           ZERO    .L1     A3                ; |317| 
           STW     .D2T1   A3,*+SP(4)        ; |317| 
	.dwpsn	file "test_c.cpp",line 324,column 8,is_stmt
;----------------------------------------------------------------------
; 324 | #endif                                                                 
; 326 | #ifdef TPO5                                                            
; 327 | uint32 buf[LEN_BUF_FOR_TEST_DOZU];                                     
; 328 | #define DAT555  0x55555555                                             
; 329 | #define DATAAA  0xAAAAAAAA                                             
; 330 | uint32 one = 1;                                                        
; 331 | #else                                                                  
; 332 | uint64 buf[LEN_BUF_FOR_TEST_DOZU];                                     
; 333 | #define DAT555  0x5555555555555555                                     
;----------------------------------------------------------------------
           MVK     .L1     1,A3              ; |324| 
           STW     .D2T1   A3,*+SP(3592)     ; |324| 

$C$DW$313	.dwtag  DW_TAG_lexical_block, DW_AT_low_pc(0x00), DW_AT_high_pc(0x00)
$C$DW$314	.dwtag  DW_TAG_variable, DW_AT_name("i")
	.dwattr $C$DW$314, DW_AT_TI_symbol_name("_i")
	.dwattr $C$DW$314, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$314, DW_AT_location[DW_OP_breg31 3596]
	.dwpsn	file "test_c.cpp",line 334,column 10,is_stmt
;----------------------------------------------------------------------
; 334 | #define DATAAA  0xAAAAAAAAAAAAAAAA                                     
;----------------------------------------------------------------------
           ZERO    .L2     B4                ; |334| 
           STW     .D2T2   B4,*+SP(3596)     ; |334| 
	.dwpsn	file "test_c.cpp",line 334,column 17,is_stmt
           MVK     .S2     32,B5             ; |334| 
           CMPLT   .L2     B4,B5,B0          ; |334| 
   [!B0]   BNOP    .S1     $C$L23,5          ; |334| 
           ; BRANCHCC OCCURS {$C$L23}        ; |334| 
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
$C$L22:    
$C$DW$L$_TestMove__Fv$2$B:
	.dwpsn	file "test_c.cpp",line 335,column 3,is_stmt
;----------------------------------------------------------------------
; 335 | uint64 one = 1;                                                        
; 336 | #endif                                                                 
;----------------------------------------------------------------------

           MV      .L2     B4,B6
||         MV      .S2     B4,B5
||         LDW     .D2T2   *+SP(3592),B4     ; |335| 

           NOP             4

           SHL     .S2     B4,B6,B5          ; |335| 
||         ADDAW   .D2     SP,B5,B4          ; |335| 

           STW     .D2T2   B5,*+B4(8)        ; |335| 
	.dwpsn	file "test_c.cpp",line 334,column 30,is_stmt
           LDW     .D2T2   *+SP(3596),B4     ; |334| 
           NOP             4
           ADD     .L2     1,B4,B4           ; |334| 
           STW     .D2T2   B4,*+SP(3596)     ; |334| 
	.dwpsn	file "test_c.cpp",line 334,column 17,is_stmt
           MVK     .S2     32,B5             ; |334| 
           CMPLT   .L2     B4,B5,B0          ; |334| 
   [ B0]   BNOP    .S1     $C$L22,5          ; |334| 
           ; BRANCHCC OCCURS {$C$L22}        ; |334| 
$C$DW$L$_TestMove__Fv$2$E:
;** --------------------------------------------------------------------------*
$C$L23:    
	.dwendtag $C$DW$313


$C$DW$315	.dwtag  DW_TAG_lexical_block, DW_AT_low_pc(0x00), DW_AT_high_pc(0x00)
$C$DW$316	.dwtag  DW_TAG_variable, DW_AT_name("i")
	.dwattr $C$DW$316, DW_AT_TI_symbol_name("_i")
	.dwattr $C$DW$316, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$316, DW_AT_location[DW_OP_breg31 3596]
	.dwpsn	file "test_c.cpp",line 337,column 10,is_stmt
           MVK     .S1     32,A3             ; |337| 
           STW     .D2T1   A3,*+SP(3596)     ; |337| 
	.dwpsn	file "test_c.cpp",line 337,column 23,is_stmt

           MV      .L2     B5,B4
||         MVK     .S2     896,B5            ; |337| 

           CMPLT   .L2     B4,B5,B0          ; |337| 
   [!B0]   BNOP    .S1     $C$L25,5          ; |337| 
           ; BRANCHCC OCCURS {$C$L25}        ; |337| 
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
$C$L24:    
$C$DW$L$_TestMove__Fv$4$B:
	.dwpsn	file "test_c.cpp",line 339,column 3,is_stmt
           MVKL    .S1     0x55555555,A3

           MVKH    .S1     0x55555555,A3
||         ADDAW   .D2     SP,B4,B4          ; |339| 

           STW     .D2T1   A3,*+B4(8)        ; |339| 
	.dwpsn	file "test_c.cpp",line 340,column 3,is_stmt
;----------------------------------------------------------------------
; 340 | for(int i = 0; i < SH_DOZU; i++)                                       
; 341 |         buf[i] = one << i;                                             
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(3596),B5     ; |340| 
           MVKL    .S2     0xaaaaaaaa,B4
           MVKH    .S2     0xaaaaaaaa,B4
           NOP             2
           ADD     .L2     1,B5,B5           ; |340| 
           ADDAW   .D2     SP,B5,B5          ; |340| 
           STW     .D2T2   B4,*+B5(8)        ; |340| 
	.dwpsn	file "test_c.cpp",line 337,column 50,is_stmt
           LDW     .D2T2   *+SP(3596),B4     ; |337| 
           NOP             4
           ADD     .L2     2,B4,B4           ; |337| 
           STW     .D2T2   B4,*+SP(3596)     ; |337| 
	.dwpsn	file "test_c.cpp",line 337,column 23,is_stmt
           MVK     .S2     896,B5            ; |337| 
           CMPLT   .L2     B4,B5,B0          ; |337| 
   [ B0]   BNOP    .S1     $C$L24,5          ; |337| 
           ; BRANCHCC OCCURS {$C$L24}        ; |337| 
$C$DW$L$_TestMove__Fv$4$E:
;** --------------------------------------------------------------------------*
$C$L25:    
	.dwendtag $C$DW$315

	.dwpsn	file "test_c.cpp",line 343,column 2,is_stmt
;----------------------------------------------------------------------
; 343 | for(int i = SH_DOZU; i < LEN_BUF_FOR_TEST_DOZU; i+=2)                  
;----------------------------------------------------------------------
$C$DW$317	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$317, DW_AT_low_pc(0x00)
	.dwattr $C$DW$317, DW_AT_name("_WriteDARAM__FUsPvT1")
	.dwattr $C$DW$317, DW_AT_TI_call
           CALL    .S1     _WriteDARAM__FUsPvT1 ; |343| 
           LDHU    .D2T1   *+SP(4),A4        ; |343| 
           ADDKPC  .S2     $C$RL13,B3,2      ; |343| 

           ADD     .L2     8,SP,B4           ; |343| 
||         MVK     .S1     0xe00,A6          ; |343| 

$C$RL13:   ; CALL OCCURS {_WriteDARAM__FUsPvT1} {0}  ; |343| 
	.dwpsn	file "test_c.cpp",line 345,column 1,is_stmt
;----------------------------------------------------------------------
; 345 | buf[i] = DAT555;                                                       
;----------------------------------------------------------------------
           ZERO    .L1     A4                ; |345| 
	.dwpsn	file "test_c.cpp",line 346,column 1,is_stmt
;----------------------------------------------------------------------
; 346 | buf[i+1] = DATAAA;                                                     
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(3600),B3     ; |346| 
           NOP             4
	.dwcfi	restore_reg, 19
           ADDK    .S2     3600,SP           ; |346| 
	.dwcfi	cfa_offset, 0
	.dwcfi	cfa_offset, 0
$C$DW$318	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$318, DW_AT_low_pc(0x00)
	.dwattr $C$DW$318, DW_AT_TI_return
           RETNOP  .S2     B3,5              ; |346| 
           ; BRANCH OCCURS {B3}              ; |346| 

$C$DW$319	.dwtag  DW_TAG_TI_loop
	.dwattr $C$DW$319, DW_AT_name("C:\1901VC1T_Inteltech\3rdPartyLIB\dsp_core\C6000\tpo_amoeba\source\test_c.asm:$C$L24:1:1517815039")
	.dwattr $C$DW$319, DW_AT_TI_begin_file("test_c.cpp")
	.dwattr $C$DW$319, DW_AT_TI_begin_line(0x151)
	.dwattr $C$DW$319, DW_AT_TI_end_line(0x155)
$C$DW$320	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$320, DW_AT_low_pc($C$DW$L$_TestMove__Fv$4$B)
	.dwattr $C$DW$320, DW_AT_high_pc($C$DW$L$_TestMove__Fv$4$E)
	.dwendtag $C$DW$319


$C$DW$321	.dwtag  DW_TAG_TI_loop
	.dwattr $C$DW$321, DW_AT_name("C:\1901VC1T_Inteltech\3rdPartyLIB\dsp_core\C6000\tpo_amoeba\source\test_c.asm:$C$L22:1:1517815039")
	.dwattr $C$DW$321, DW_AT_TI_begin_file("test_c.cpp")
	.dwattr $C$DW$321, DW_AT_TI_begin_line(0x14e)
	.dwattr $C$DW$321, DW_AT_TI_end_line(0x14f)
$C$DW$322	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$322, DW_AT_low_pc($C$DW$L$_TestMove__Fv$2$B)
	.dwattr $C$DW$322, DW_AT_high_pc($C$DW$L$_TestMove__Fv$2$E)
	.dwendtag $C$DW$321

	.dwattr $C$DW$309, DW_AT_TI_end_file("test_c.cpp")
	.dwattr $C$DW$309, DW_AT_TI_end_line(0x15a)
	.dwattr $C$DW$309, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$309

	.sect	".text"
	.clink
	.global	_alp_sinhrosig_tst__Fv

$C$DW$323	.dwtag  DW_TAG_subprogram, DW_AT_name("alp_sinhrosig_tst")
	.dwattr $C$DW$323, DW_AT_low_pc(_alp_sinhrosig_tst__Fv)
	.dwattr $C$DW$323, DW_AT_high_pc(0x00)
	.dwattr $C$DW$323, DW_AT_TI_symbol_name("_alp_sinhrosig_tst__Fv")
	.dwattr $C$DW$323, DW_AT_external
	.dwattr $C$DW$323, DW_AT_TI_begin_file("test_c.cpp")
	.dwattr $C$DW$323, DW_AT_TI_begin_line(0x164)
	.dwattr $C$DW$323, DW_AT_TI_begin_column(0x06)
	.dwpsn	file "test_c.cpp",line 357,column 1,is_stmt,address _alp_sinhrosig_tst__Fv

	.dwfde $C$DW$CIE, _alp_sinhrosig_tst__Fv
;----------------------------------------------------------------------
; 356 | #define GPIO_OUT_DATA       (*(volatile uint32*)0x02b00014) // GPIO Out
;     | put Data register                                                      
;----------------------------------------------------------------------

;******************************************************************************
;* FUNCTION NAME: alp_sinhrosig_tst()                                         *
;*                                                                            *
;*   Regs Modified     : A3,B4,B5,B6,SP                                       *
;*   Regs Used         : A3,B3,B4,B5,B6,SP                                    *
;*   Local Frame Size  : 0 Args + 4 Auto + 0 Save = 4 byte                    *
;******************************************************************************
_alp_sinhrosig_tst__Fv:
;** --------------------------------------------------------------------------*
;----------------------------------------------------------------------
; 357 | #define GPIO_SET_DATA       (*(volatile uint32*)0x02b00018) // GPIO Set
;     |  Data register                                                         
;----------------------------------------------------------------------
	.dwcfi	cfa_offset, 0
	.dwcfi	save_reg_to_reg, 228, 19
           SUB     .L2     SP,8,SP           ; |357| 
	.dwcfi	cfa_offset, 8
$C$DW$324	.dwtag  DW_TAG_variable, DW_AT_name("res")
	.dwattr $C$DW$324, DW_AT_TI_symbol_name("_res")
	.dwattr $C$DW$324, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$324, DW_AT_location[DW_OP_breg31 4]
	.dwpsn	file "test_c.cpp",line 358,column 8,is_stmt
;----------------------------------------------------------------------
; 358 | #define GPIO_CLR_DATA       (*(volatile uint32*)0x02b0001c) // GPIO Cle
;     | ar Data Register                                                       
;----------------------------------------------------------------------
           MVKL    .S1     0x2b00010,A3
           MVKH    .S1     0x2b00010,A3
           LDW     .D1T1   *A3,A3            ; |358| 
           NOP             4
           STW     .D2T1   A3,*+SP(4)        ; |358| 
	.dwpsn	file "test_c.cpp",line 359,column 1,is_stmt
;----------------------------------------------------------------------
; 359 | #define GPIO_IN_DATA        (*(volatile uint32*)0x02b00020) // GPIO Inp
;     | ut Data Register                                                       
;----------------------------------------------------------------------
           MVKL    .S2     0xffdf,B5
           MVKL    .S2     0x2b00010,B6

           MVKH    .S2     0xffdf,B5
||         MV      .L2X    A3,B4

           AND     .L2     B5,B4,B4          ; |359| 
||         MVKH    .S2     0x2b00010,B6

           STW     .D2T2   B4,*B6            ; |359| 
	.dwpsn	file "test_c.cpp",line 361,column 1,is_stmt
;----------------------------------------------------------------------
; 362 | void alp_sinhrosig_tst()                                               
;----------------------------------------------------------------------

           MVK     .S1     32,A3             ; |361| 
||         ADD     .L2     8,B6,B4

           STW     .D2T1   A3,*B4            ; |361| 
	.dwpsn	file "test_c.cpp",line 363,column 1,is_stmt
 nop 
	.dwpsn	file "test_c.cpp",line 364,column 1,is_stmt
;----------------------------------------------------------------------
; 364 | uint32 res = GPIO_DIR;                                                 
;----------------------------------------------------------------------
 nop 
	.dwpsn	file "test_c.cpp",line 365,column 1,is_stmt
;----------------------------------------------------------------------
; 365 | GPIO_DIR = res & 0xFFDF;                                               
;----------------------------------------------------------------------
 nop 
	.dwpsn	file "test_c.cpp",line 366,column 1,is_stmt
 nop 
	.dwpsn	file "test_c.cpp",line 367,column 1,is_stmt
;----------------------------------------------------------------------
; 367 | GPIO_SET_DATA = 0x20;                                                  
;----------------------------------------------------------------------
 nop 
	.dwpsn	file "test_c.cpp",line 368,column 1,is_stmt
 nop 
	.dwpsn	file "test_c.cpp",line 369,column 1,is_stmt
;----------------------------------------------------------------------
; 369 | asm ( " nop " );                                                       
;----------------------------------------------------------------------
 nop 
	.dwpsn	file "test_c.cpp",line 370,column 1,is_stmt
;----------------------------------------------------------------------
; 370 | asm ( " nop " );                                                       
;----------------------------------------------------------------------
 nop 
	.dwpsn	file "test_c.cpp",line 371,column 1,is_stmt
;----------------------------------------------------------------------
; 371 | asm ( " nop " );                                                       
;----------------------------------------------------------------------
 nop 
	.dwpsn	file "test_c.cpp",line 372,column 1,is_stmt
;----------------------------------------------------------------------
; 372 | asm ( " nop " );                                                       
;----------------------------------------------------------------------
 nop 
	.dwpsn	file "test_c.cpp",line 373,column 1,is_stmt
;----------------------------------------------------------------------
; 373 | asm ( " nop " );                                                       
;----------------------------------------------------------------------
           ADD     .L2     4,B4,B4
           STW     .D2T1   A3,*B4            ; |373| 
	.dwpsn	file "test_c.cpp",line 374,column 1,is_stmt
;----------------------------------------------------------------------
; 374 | asm ( " nop " );                                                       
;----------------------------------------------------------------------
           ADD     .L2     8,SP,SP           ; |374| 
	.dwcfi	cfa_offset, 0
	.dwcfi	cfa_offset, 0
$C$DW$325	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$325, DW_AT_low_pc(0x00)
	.dwattr $C$DW$325, DW_AT_TI_return
           RETNOP  .S2     B3,5              ; |374| 
           ; BRANCH OCCURS {B3}              ; |374| 
	.dwattr $C$DW$323, DW_AT_TI_end_file("test_c.cpp")
	.dwattr $C$DW$323, DW_AT_TI_end_line(0x176)
	.dwattr $C$DW$323, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$323

	.sect	".text"
	.clink
	.global	_TestMove_ST1__FP12kdg_rez_test

$C$DW$326	.dwtag  DW_TAG_subprogram, DW_AT_name("TestMove_ST1")
	.dwattr $C$DW$326, DW_AT_low_pc(_TestMove_ST1__FP12kdg_rez_test)
	.dwattr $C$DW$326, DW_AT_high_pc(0x00)
	.dwattr $C$DW$326, DW_AT_TI_symbol_name("_TestMove_ST1__FP12kdg_rez_test")
	.dwattr $C$DW$326, DW_AT_external
	.dwattr $C$DW$326, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$326, DW_AT_TI_begin_file("test_c.cpp")
	.dwattr $C$DW$326, DW_AT_TI_begin_line(0x17e)
	.dwattr $C$DW$326, DW_AT_TI_begin_column(0x08)
	.dwpsn	file "test_c.cpp",line 383,column 1,is_stmt,address _TestMove_ST1__FP12kdg_rez_test

	.dwfde $C$DW$CIE, _TestMove_ST1__FP12kdg_rez_test
$C$DW$327	.dwtag  DW_TAG_formal_parameter, DW_AT_name("result")
	.dwattr $C$DW$327, DW_AT_TI_symbol_name("_result")
	.dwattr $C$DW$327, DW_AT_type(*$C$DW$T$696)
	.dwattr $C$DW$327, DW_AT_location[DW_OP_reg4]

;******************************************************************************
;* FUNCTION NAME: TestMove_ST1(kdg_rez_test *)                                *
;*                                                                            *
;*   Regs Modified     : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP,A16,A17,A18,A19,A20,A21,A22,A23,A24, *
;*                           A25,A26,A27,A28,A29,A30,A31,B16,B17,B18,B19,B20, *
;*                           B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31      *
;*   Regs Used         : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP,A16,A17,A18,A19,A20,A21,A22,A23,A24, *
;*                           A25,A26,A27,A28,A29,A30,A31,B16,B17,B18,B19,B20, *
;*                           B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31      *
;*   Local Frame Size  : 0 Args + 3604 Auto + 4 Save = 3608 byte              *
;******************************************************************************
_TestMove_ST1__FP12kdg_rez_test:
;** --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
	.dwcfi	save_reg_to_reg, 228, 19
           ADDK    .S2     -3608,SP          ; |383| 
	.dwcfi	cfa_offset, 3608
           STW     .D2T2   B3,*+SP(3608)     ; |383| 
	.dwcfi	save_reg_to_mem, 19, 0
$C$DW$328	.dwtag  DW_TAG_variable, DW_AT_name("result")
	.dwattr $C$DW$328, DW_AT_TI_symbol_name("_result")
	.dwattr $C$DW$328, DW_AT_type(*$C$DW$T$696)
	.dwattr $C$DW$328, DW_AT_location[DW_OP_breg31 4]
$C$DW$329	.dwtag  DW_TAG_variable, DW_AT_name("start_adr")
	.dwattr $C$DW$329, DW_AT_TI_symbol_name("_start_adr")
	.dwattr $C$DW$329, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$329, DW_AT_location[DW_OP_breg31 8]
$C$DW$330	.dwtag  DW_TAG_variable, DW_AT_name("sh_d")
	.dwattr $C$DW$330, DW_AT_TI_symbol_name("_sh_d")
	.dwattr $C$DW$330, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$330, DW_AT_location[DW_OP_breg31 12]
$C$DW$331	.dwtag  DW_TAG_variable, DW_AT_name("buf")
	.dwattr $C$DW$331, DW_AT_TI_symbol_name("_buf")
	.dwattr $C$DW$331, DW_AT_type(*$C$DW$T$740)
	.dwattr $C$DW$331, DW_AT_location[DW_OP_breg31 16]
$C$DW$332	.dwtag  DW_TAG_variable, DW_AT_name("one")
	.dwattr $C$DW$332, DW_AT_TI_symbol_name("_one")
	.dwattr $C$DW$332, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$332, DW_AT_location[DW_OP_breg31 3600]
           STW     .D2T1   A4,*+SP(4)        ; |383| 
	.dwpsn	file "test_c.cpp",line 387,column 8,is_stmt
;----------------------------------------------------------------------
; 387 | //---------------------------------------------------------------------
;     | -------                                                                
; 388 | uint32 TestMove_ST1(kdg_rez_test* result)                              
;----------------------------------------------------------------------
           ZERO    .L2     B4                ; |387| 
           STW     .D2T2   B4,*+SP(8)        ; |387| 
	.dwpsn	file "test_c.cpp",line 389,column 8,is_stmt
;----------------------------------------------------------------------
; 390 | #ifdef TPO_M711B                                                       
; 391 | uint32 start_adr = 0x100;                                              
; 392 | #else                                                                  
; 393 | uint32 start_adr = 0;                                                  
; 394 | #endif                                                                 
;----------------------------------------------------------------------
           MVK     .L1     4,A3              ; |389| 
           STW     .D2T1   A3,*+SP(12)       ; |389| 
	.dwpsn	file "test_c.cpp",line 395,column 8,is_stmt
;----------------------------------------------------------------------
; 395 | uint32 sh_d = SH_DOZU/8;                                               
; 397 | #ifdef TPO5                                                            
; 398 | uint32 buf[LEN_BUF_FOR_TEST_DOZU];                                     
; 399 | #define DAT555  0x55555555                                             
; 400 | #define DATAAA  0xAAAAAAAA                                             
; 401 | uint32 one = 1;                                                        
; 402 | #else                                                                  
;----------------------------------------------------------------------
           MVK     .L1     1,A3              ; |395| 
           STW     .D2T1   A3,*+SP(3600)     ; |395| 
	.dwpsn	file "test_c.cpp",line 403,column 1,is_stmt
;----------------------------------------------------------------------
; 403 | uint64 buf[LEN_BUF_FOR_TEST_DOZU+5];                                   
; 404 | #define DAT555  0x5555555555555555                                     
;----------------------------------------------------------------------
$C$DW$333	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$333, DW_AT_low_pc(0x00)
	.dwattr $C$DW$333, DW_AT_name("_ReadDARAM_CRYPT0__FUsPvT1")
	.dwattr $C$DW$333, DW_AT_TI_call
           CALL    .S1     _ReadDARAM_CRYPT0__FUsPvT1 ; |403| 
           LDHU    .D2T1   *+SP(8),A4        ; |403| 
           ADDKPC  .S2     $C$RL14,B3,2      ; |403| 

           ADD     .D2     SP,16,B4          ; |403| 
||         MVK     .S1     0xe00,A6          ; |403| 

$C$RL14:   ; CALL OCCURS {_ReadDARAM_CRYPT0__FUsPvT1} {0}  ; |403| 

$C$DW$334	.dwtag  DW_TAG_lexical_block, DW_AT_low_pc(0x00), DW_AT_high_pc(0x00)
$C$DW$335	.dwtag  DW_TAG_variable, DW_AT_name("i")
	.dwattr $C$DW$335, DW_AT_TI_symbol_name("_i")
	.dwattr $C$DW$335, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$335, DW_AT_location[DW_OP_breg31 3604]
	.dwpsn	file "test_c.cpp",line 405,column 11,is_stmt
;----------------------------------------------------------------------
; 405 | #define DATAAA  0xAAAAAAAAAAAAAAAA                                     
;----------------------------------------------------------------------
           ZERO    .L2     B4                ; |405| 
           STW     .D2T2   B4,*+SP(3604)     ; |405| 
	.dwpsn	file "test_c.cpp",line 405,column 18,is_stmt
;----------------------------------------------------------------------
; 406 | uint64 one = 1;                                                        
;----------------------------------------------------------------------
           MVK     .S2     32,B5             ; |405| 
           CMPLT   .L2     B4,B5,B0          ; |405| 
   [!B0]   BNOP    .S1     $C$L28,5          ; |405| 
           ; BRANCHCC OCCURS {$C$L28}        ; |405| 
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
$C$L26:    
$C$DW$L$_TestMove_ST1__FP12kdg_rez_test$2$B:
	.dwpsn	file "test_c.cpp",line 407,column 4,is_stmt
;----------------------------------------------------------------------
; 407 | #endif                                                                 
;----------------------------------------------------------------------

           MV      .L2     B4,B6
||         ADDAW   .D2     SP,B4,B4          ; |407| 

           LDW     .D2T2   *+SP(3600),B5     ; |407| 
           LDW     .D2T2   *+B4(16),B4       ; |407| 
           NOP             3
           SHL     .S2     B5,B6,B5          ; |407| 
           CMPEQ   .L2     B4,B5,B0          ; |407| 
   [ B0]   BNOP    .S1     $C$L27,5          ; |407| 
           ; BRANCHCC OCCURS {$C$L27}        ; |407| 
$C$DW$L$_TestMove_ST1__FP12kdg_rez_test$2$E:
;** --------------------------------------------------------------------------*
	.dwpsn	file "test_c.cpp",line 409,column 4,is_stmt
;----------------------------------------------------------------------
; 409 | ReadDARAM_CRYPT0(start_adr, buf, LEN_DUZU_FOR_TEST);                   
;----------------------------------------------------------------------

           MV      .L2     B6,B4
||         ADDAW   .D2     SP,B6,B6          ; |409| 

           LDW     .D2T2   *+SP(3600),B5     ; |409| 
           LDW     .D2T2   *+B6(16),B7       ; |409| 
           LDW     .D2T2   *+SP(4),B31       ; |409| 
           NOP             2
           SHL     .S2     B5,B4,B4          ; |409| 
           XOR     .L2     B4,B7,B4          ; |409| 
           STW     .D2T2   B4,*+B31(16)      ; |409| 
	.dwpsn	file "test_c.cpp",line 410,column 4,is_stmt
           LDW     .D2T2   *+SP(12),B4       ; |410| 
           LDW     .D2T2   *+SP(3604),B7     ; |410| 
           LDW     .D2T2   *+SP(8),B5        ; |410| 
           LDW     .D2T2   *+SP(4),B6        ; |410| 
           NOP             2
           MPYLH   .M2     B4,B7,B9          ; |410| 
           MPYLH   .M2     B7,B4,B8          ; |410| 
           MPYU    .M2     B4,B7,B7          ; |410| 
           ADD     .L2     B9,B8,B4          ; |410| 
           SHL     .S2     B4,16,B4          ; |410| 
           ADD     .L2     B7,B4,B4          ; |410| 
           ADD     .L2     B5,B4,B4          ; |410| 
           STW     .D2T2   B4,*+B6(12)       ; |410| 
	.dwpsn	file "test_c.cpp",line 411,column 4,is_stmt
;----------------------------------------------------------------------
; 411 | for(int i = 0; i < SH_DOZU; i++)                                       
; 413 |         if(buf[i] != one << i)                                         
;----------------------------------------------------------------------
           BNOP    .S1     $C$L33,4          ; |411| 
           MVK     .L1     0x1,A4            ; |411| 
           ; BRANCH OCCURS {$C$L33}          ; |411| 
;** --------------------------------------------------------------------------*
$C$L27:    
$C$DW$L$_TestMove_ST1__FP12kdg_rez_test$4$B:
	.dwpsn	file "test_c.cpp",line 405,column 31,is_stmt
           ADD     .L2     1,B6,B4           ; |405| 
           STW     .D2T2   B4,*+SP(3604)     ; |405| 
	.dwpsn	file "test_c.cpp",line 405,column 18,is_stmt
           MVK     .S2     32,B5             ; |405| 
           CMPLT   .L2     B4,B5,B0          ; |405| 
   [ B0]   BNOP    .S1     $C$L26,5          ; |405| 
           ; BRANCHCC OCCURS {$C$L26}        ; |405| 
$C$DW$L$_TestMove_ST1__FP12kdg_rez_test$4$E:
;** --------------------------------------------------------------------------*
$C$L28:    
	.dwendtag $C$DW$334


$C$DW$336	.dwtag  DW_TAG_lexical_block, DW_AT_low_pc(0x00), DW_AT_high_pc(0x00)
$C$DW$337	.dwtag  DW_TAG_variable, DW_AT_name("i")
	.dwattr $C$DW$337, DW_AT_TI_symbol_name("_i")
	.dwattr $C$DW$337, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$337, DW_AT_location[DW_OP_breg31 3604]
	.dwpsn	file "test_c.cpp",line 415,column 11,is_stmt
;----------------------------------------------------------------------
; 415 | result->data = buf[i] ^ (one << i);                                    
;----------------------------------------------------------------------
           MVK     .S1     32,A3             ; |415| 
           STW     .D2T1   A3,*+SP(3604)     ; |415| 
	.dwpsn	file "test_c.cpp",line 415,column 24,is_stmt
;----------------------------------------------------------------------
; 416 | result->adrr = (i * sh_d) + start_adr;                                 
;----------------------------------------------------------------------

           MV      .L2     B5,B4
||         MVK     .S2     896,B5            ; |415| 

           CMPLT   .L2     B4,B5,B0          ; |415| 
   [!B0]   BNOP    .S1     $C$L32,5          ; |415| 
           ; BRANCHCC OCCURS {$C$L32}        ; |415| 
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
$C$L29:    
$C$DW$L$_TestMove_ST1__FP12kdg_rez_test$6$B:
	.dwpsn	file "test_c.cpp",line 417,column 4,is_stmt
;----------------------------------------------------------------------
; 417 | return TPO_ERR;                                                        
;----------------------------------------------------------------------
           ADDAW   .D2     SP,B4,B4          ; |417| 
           LDW     .D2T2   *+B4(16),B4       ; |417| 
           MVKL    .S2     0x55555555,B5
           MVKH    .S2     0x55555555,B5
           NOP             2
           CMPEQ   .L2     B4,B5,B0          ; |417| 
   [ B0]   BNOP    .S1     $C$L30,5          ; |417| 
           ; BRANCHCC OCCURS {$C$L30}        ; |417| 
$C$DW$L$_TestMove_ST1__FP12kdg_rez_test$6$E:
;** --------------------------------------------------------------------------*
	.dwpsn	file "test_c.cpp",line 419,column 4,is_stmt
           LDW     .D2T2   *+SP(3604),B4     ; |419| 
           LDW     .D2T2   *+SP(4),B31       ; |419| 
           NOP             3
           ADDAW   .D2     SP,B4,B4          ; |419| 
           LDW     .D2T2   *+B4(16),B6       ; |419| 
           NOP             4
           XOR     .L2     B5,B6,B5          ; |419| 
           STW     .D2T2   B5,*+B31(16)      ; |419| 
	.dwpsn	file "test_c.cpp",line 420,column 4,is_stmt
           LDW     .D2T2   *+SP(3604),B4     ; |420| 
           LDW     .D2T2   *+SP(12),B6       ; |420| 
           LDW     .D2T2   *+SP(8),B7        ; |420| 
           LDW     .D2T2   *+SP(4),B5        ; |420| 
           NOP             2
           MPYLH   .M2     B6,B4,B9          ; |420| 
           MPYLH   .M2     B4,B6,B8          ; |420| 
           MPYU    .M2     B6,B4,B6          ; |420| 
           ADD     .L2     B9,B8,B4          ; |420| 
           SHL     .S2     B4,16,B4          ; |420| 
           ADD     .L2     B6,B4,B4          ; |420| 
           ADD     .L2     B7,B4,B4          ; |420| 
           STW     .D2T2   B4,*+B5(12)       ; |420| 
	.dwpsn	file "test_c.cpp",line 421,column 4,is_stmt
;----------------------------------------------------------------------
; 421 | for(int i = SH_DOZU; i < LEN_BUF_FOR_TEST_DOZU; i+=2)                  
; 423 |         if(buf[i] != DAT555)                                           
;----------------------------------------------------------------------
           BNOP    .S1     $C$L33,4          ; |421| 
           MVK     .L1     0x1,A4            ; |421| 
           ; BRANCH OCCURS {$C$L33}          ; |421| 
;** --------------------------------------------------------------------------*
$C$L30:    
$C$DW$L$_TestMove_ST1__FP12kdg_rez_test$8$B:
	.dwpsn	file "test_c.cpp",line 424,column 4,is_stmt
;----------------------------------------------------------------------
; 425 | result->data = buf[i] ^ DAT555;                                        
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(3604),B4     ; |424| 
           MVKL    .S2     0xaaaaaaaa,B5
           MVKH    .S2     0xaaaaaaaa,B5
           NOP             2
           ADD     .L2     1,B4,B4           ; |424| 
           ADDAW   .D2     SP,B4,B4          ; |424| 
           LDW     .D2T2   *+B4(16),B4       ; |424| 
           NOP             4
           CMPEQ   .L2     B4,B5,B0          ; |424| 
   [ B0]   BNOP    .S1     $C$L31,5          ; |424| 
           ; BRANCHCC OCCURS {$C$L31}        ; |424| 
$C$DW$L$_TestMove_ST1__FP12kdg_rez_test$8$E:
;** --------------------------------------------------------------------------*
	.dwpsn	file "test_c.cpp",line 426,column 4,is_stmt
;----------------------------------------------------------------------
; 426 | result->adrr = (i * sh_d) + start_adr;                                 
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(3604),B4     ; |426| 
           LDW     .D2T2   *+SP(4),B5        ; |426| 
           MVKL    .S2     0xaaaaaaaa,B6
           MVKH    .S2     0xaaaaaaaa,B6
           NOP             1
           ADD     .L2     1,B4,B4           ; |426| 
           ADDAW   .D2     SP,B4,B4          ; |426| 
           LDW     .D2T2   *+B4(16),B4       ; |426| 
           NOP             4
           XOR     .L2     B6,B4,B4          ; |426| 
           STW     .D2T2   B4,*+B5(16)       ; |426| 
	.dwpsn	file "test_c.cpp",line 427,column 4,is_stmt
;----------------------------------------------------------------------
; 427 | return TPO_ERR;                                                        
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(3604),B5     ; |427| 
           LDW     .D2T2   *+SP(12),B4       ; |427| 
           LDW     .D2T2   *+SP(8),B31       ; |427| 
           LDW     .D2T2   *+SP(4),B6        ; |427| 
           NOP             1
           ADD     .L2     1,B5,B7           ; |427| 
           MPYLH   .M2     B7,B4,B8          ; |427| 
           MPYLH   .M2     B4,B7,B9          ; |427| 
           MPYU    .M2     B4,B7,B7          ; |427| 
           ADD     .L2     B9,B8,B4          ; |427| 
           SHL     .S2     B4,16,B4          ; |427| 
           ADD     .L2     B7,B4,B4          ; |427| 
           ADD     .L2     B31,B4,B4         ; |427| 
           STW     .D2T2   B4,*+B6(12)       ; |427| 
	.dwpsn	file "test_c.cpp",line 428,column 4,is_stmt
;----------------------------------------------------------------------
; 430 | if(buf[i+1] != DATAAA)                                                 
; 432 | result->data = buf[i+1] ^ DATAAA;                                      
;----------------------------------------------------------------------
           BNOP    .S1     $C$L33,4          ; |428| 
           MVK     .L1     0x1,A4            ; |428| 
           ; BRANCH OCCURS {$C$L33}          ; |428| 
;** --------------------------------------------------------------------------*
$C$L31:    
$C$DW$L$_TestMove_ST1__FP12kdg_rez_test$10$B:
	.dwpsn	file "test_c.cpp",line 415,column 51,is_stmt
           LDW     .D2T2   *+SP(3604),B4     ; |415| 
           NOP             4
           ADD     .L2     2,B4,B4           ; |415| 
           STW     .D2T2   B4,*+SP(3604)     ; |415| 
	.dwpsn	file "test_c.cpp",line 415,column 24,is_stmt
           MVK     .S2     896,B5            ; |415| 
           CMPLT   .L2     B4,B5,B0          ; |415| 
   [ B0]   BNOP    .S1     $C$L29,5          ; |415| 
           ; BRANCHCC OCCURS {$C$L29}        ; |415| 
$C$DW$L$_TestMove_ST1__FP12kdg_rez_test$10$E:
;** --------------------------------------------------------------------------*
$C$L32:    
	.dwendtag $C$DW$336

	.dwpsn	file "test_c.cpp",line 433,column 1,is_stmt
;----------------------------------------------------------------------
; 433 | result->adrr = ((i+1) * sh_d) + start_adr;                             
;----------------------------------------------------------------------
           ZERO    .L1     A4                ; |433| 
;** --------------------------------------------------------------------------*
$C$L33:    
	.dwpsn	file "test_c.cpp",line 434,column 1,is_stmt
;----------------------------------------------------------------------
; 434 | return TPO_ERR;                                                        
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(3608),B3     ; |434| 
           NOP             4
	.dwcfi	restore_reg, 19
           ADDK    .S2     3608,SP           ; |434| 
	.dwcfi	cfa_offset, 0
	.dwcfi	cfa_offset, 0
$C$DW$338	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$338, DW_AT_low_pc(0x00)
	.dwattr $C$DW$338, DW_AT_TI_return
           RETNOP  .S2     B3,5              ; |434| 
           ; BRANCH OCCURS {B3}              ; |434| 

$C$DW$339	.dwtag  DW_TAG_TI_loop
	.dwattr $C$DW$339, DW_AT_name("C:\1901VC1T_Inteltech\3rdPartyLIB\dsp_core\C6000\tpo_amoeba\source\test_c.asm:$C$L29:1:1517815039")
	.dwattr $C$DW$339, DW_AT_TI_begin_file("test_c.cpp")
	.dwattr $C$DW$339, DW_AT_TI_begin_line(0x19f)
	.dwattr $C$DW$339, DW_AT_TI_end_line(0x1ae)
$C$DW$340	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$340, DW_AT_low_pc($C$DW$L$_TestMove_ST1__FP12kdg_rez_test$6$B)
	.dwattr $C$DW$340, DW_AT_high_pc($C$DW$L$_TestMove_ST1__FP12kdg_rez_test$6$E)
$C$DW$341	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$341, DW_AT_low_pc($C$DW$L$_TestMove_ST1__FP12kdg_rez_test$8$B)
	.dwattr $C$DW$341, DW_AT_high_pc($C$DW$L$_TestMove_ST1__FP12kdg_rez_test$8$E)
$C$DW$342	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$342, DW_AT_low_pc($C$DW$L$_TestMove_ST1__FP12kdg_rez_test$10$B)
	.dwattr $C$DW$342, DW_AT_high_pc($C$DW$L$_TestMove_ST1__FP12kdg_rez_test$10$E)
	.dwendtag $C$DW$339


$C$DW$343	.dwtag  DW_TAG_TI_loop
	.dwattr $C$DW$343, DW_AT_name("C:\1901VC1T_Inteltech\3rdPartyLIB\dsp_core\C6000\tpo_amoeba\source\test_c.asm:$C$L26:1:1517815039")
	.dwattr $C$DW$343, DW_AT_TI_begin_file("test_c.cpp")
	.dwattr $C$DW$343, DW_AT_TI_begin_line(0x195)
	.dwattr $C$DW$343, DW_AT_TI_end_line(0x19d)
$C$DW$344	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$344, DW_AT_low_pc($C$DW$L$_TestMove_ST1__FP12kdg_rez_test$2$B)
	.dwattr $C$DW$344, DW_AT_high_pc($C$DW$L$_TestMove_ST1__FP12kdg_rez_test$2$E)
$C$DW$345	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$345, DW_AT_low_pc($C$DW$L$_TestMove_ST1__FP12kdg_rez_test$4$B)
	.dwattr $C$DW$345, DW_AT_high_pc($C$DW$L$_TestMove_ST1__FP12kdg_rez_test$4$E)
	.dwendtag $C$DW$343

	.dwattr $C$DW$326, DW_AT_TI_end_file("test_c.cpp")
	.dwattr $C$DW$326, DW_AT_TI_end_line(0x1b2)
	.dwattr $C$DW$326, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$326

	.sect	".text"
	.clink
	.global	_Send_Recive_Packet__FUiPvT2T1

$C$DW$346	.dwtag  DW_TAG_subprogram, DW_AT_name("Send_Recive_Packet")
	.dwattr $C$DW$346, DW_AT_low_pc(_Send_Recive_Packet__FUiPvT2T1)
	.dwattr $C$DW$346, DW_AT_high_pc(0x00)
	.dwattr $C$DW$346, DW_AT_TI_symbol_name("_Send_Recive_Packet__FUiPvT2T1")
	.dwattr $C$DW$346, DW_AT_external
	.dwattr $C$DW$346, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$346, DW_AT_TI_begin_file("test_c.cpp")
	.dwattr $C$DW$346, DW_AT_TI_begin_line(0x1dc)
	.dwattr $C$DW$346, DW_AT_TI_begin_column(0x08)
	.dwpsn	file "test_c.cpp",line 477,column 1,is_stmt,address _Send_Recive_Packet__FUiPvT2T1

	.dwfde $C$DW$CIE, _Send_Recive_Packet__FUiPvT2T1
$C$DW$347	.dwtag  DW_TAG_formal_parameter, DW_AT_name("FileNet")
	.dwattr $C$DW$347, DW_AT_TI_symbol_name("_FileNet")
	.dwattr $C$DW$347, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$347, DW_AT_location[DW_OP_reg4]
$C$DW$348	.dwtag  DW_TAG_formal_parameter, DW_AT_name("Pack_wr")
	.dwattr $C$DW$348, DW_AT_TI_symbol_name("_Pack_wr")
	.dwattr $C$DW$348, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$348, DW_AT_location[DW_OP_reg20]
$C$DW$349	.dwtag  DW_TAG_formal_parameter, DW_AT_name("Pack_rd")
	.dwattr $C$DW$349, DW_AT_TI_symbol_name("_Pack_rd")
	.dwattr $C$DW$349, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$349, DW_AT_location[DW_OP_reg6]
$C$DW$350	.dwtag  DW_TAG_formal_parameter, DW_AT_name("len")
	.dwattr $C$DW$350, DW_AT_TI_symbol_name("_len")
	.dwattr $C$DW$350, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$350, DW_AT_location[DW_OP_reg22]

;******************************************************************************
;* FUNCTION NAME: Send_Recive_Packet(unsigned int, void *, void *, unsigned int)*
;*                                                                            *
;*   Regs Modified     : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP,A16,A17,A18,A19,A20,A21,A22,A23,A24, *
;*                           A25,A26,A27,A28,A29,A30,A31,B16,B17,B18,B19,B20, *
;*                           B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31      *
;*   Regs Used         : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP,A16,A17,A18,A19,A20,A21,A22,A23,A24, *
;*                           A25,A26,A27,A28,A29,A30,A31,B16,B17,B18,B19,B20, *
;*                           B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31      *
;*   Local Frame Size  : 0 Args + 28 Auto + 4 Save = 32 byte                  *
;******************************************************************************
_Send_Recive_Packet__FUiPvT2T1:
;** --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
	.dwcfi	save_reg_to_reg, 228, 19
           STW     .D2T2   B3,*SP--(32)      ; |477| 
	.dwcfi	cfa_offset, 32
	.dwcfi	save_reg_to_mem, 19, 0
$C$DW$351	.dwtag  DW_TAG_variable, DW_AT_name("FileNet")
	.dwattr $C$DW$351, DW_AT_TI_symbol_name("_FileNet")
	.dwattr $C$DW$351, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$351, DW_AT_location[DW_OP_breg31 4]
$C$DW$352	.dwtag  DW_TAG_variable, DW_AT_name("Pack_wr")
	.dwattr $C$DW$352, DW_AT_TI_symbol_name("_Pack_wr")
	.dwattr $C$DW$352, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$352, DW_AT_location[DW_OP_breg31 8]
$C$DW$353	.dwtag  DW_TAG_variable, DW_AT_name("Pack_rd")
	.dwattr $C$DW$353, DW_AT_TI_symbol_name("_Pack_rd")
	.dwattr $C$DW$353, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$353, DW_AT_location[DW_OP_breg31 12]
$C$DW$354	.dwtag  DW_TAG_variable, DW_AT_name("len")
	.dwattr $C$DW$354, DW_AT_TI_symbol_name("_len")
	.dwattr $C$DW$354, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$354, DW_AT_location[DW_OP_breg31 16]
$C$DW$355	.dwtag  DW_TAG_variable, DW_AT_name("p_txd")
	.dwattr $C$DW$355, DW_AT_TI_symbol_name("_p_txd")
	.dwattr $C$DW$355, DW_AT_type(*$C$DW$T$570)
	.dwattr $C$DW$355, DW_AT_location[DW_OP_breg31 20]
$C$DW$356	.dwtag  DW_TAG_variable, DW_AT_name("p_rxd")
	.dwattr $C$DW$356, DW_AT_TI_symbol_name("_p_rxd")
	.dwattr $C$DW$356, DW_AT_type(*$C$DW$T$570)
	.dwattr $C$DW$356, DW_AT_location[DW_OP_breg31 24]
$C$DW$357	.dwtag  DW_TAG_variable, DW_AT_name("tim")
	.dwattr $C$DW$357, DW_AT_TI_symbol_name("_tim")
	.dwattr $C$DW$357, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$357, DW_AT_location[DW_OP_breg31 28]
;----------------------------------------------------------------------
; 478 | return 0;                                                              
; 480 | */                                                                     
; 483 | uint32 Send_Recive_Packet(uint32 FileNet, void* Pack_wr, void* Pack_rd,
;     |  uint32 len)                                                           
;----------------------------------------------------------------------
           STW     .D2T2   B6,*+SP(16)       ; |477| 
           STW     .D2T1   A6,*+SP(12)       ; |477| 
           STW     .D2T2   B4,*+SP(8)        ; |477| 
           STW     .D2T1   A4,*+SP(4)        ; |477| 
	.dwpsn	file "test_c.cpp",line 486,column 17,is_stmt
           ZERO    .L2     B4                ; |486| 
           STW     .D2T2   B4,*+SP(20)       ; |486| 
	.dwpsn	file "test_c.cpp",line 487,column 17,is_stmt
           STW     .D2T2   B4,*+SP(24)       ; |487| 
	.dwpsn	file "test_c.cpp",line 489,column 8,is_stmt
           ZERO    .L1     A3                ; |489| 
           MVKH    .S1     0x500000,A3       ; |489| 
           STW     .D2T1   A3,*+SP(28)       ; |489| 
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
$C$L34:    
$C$DW$L$_Send_Recive_Packet__FUiPvT2T1$2$B:
	.dwpsn	file "test_c.cpp",line 492,column 3,is_stmt
           MVKL    .S1     ___syscall_tab+284,A3
           MVKH    .S1     ___syscall_tab+284,A3
           LDW     .D1T1   *A3,A3            ; |492| 
           LDW     .D2T1   *+SP(4),A4        ; |492| 
           ADD     .D2     SP,24,B5          ; |492| 
           MVK     .S2     0x1100,B4         ; |492| 
           MV      .L1X    B5,A6             ; |492| 
$C$DW$358	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$358, DW_AT_low_pc(0x00)
	.dwattr $C$DW$358, DW_AT_TI_call
	.dwattr $C$DW$358, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |492| 
           ADDKPC  .S2     $C$RL15,B3,4      ; |492| 
$C$RL15:   ; CALL OCCURS {A3} {0}            ; |492| 
           MV      .L1     A4,A0             ; |492| 
   [!A0]   BNOP    .S1     $C$L35,5          ; |492| 
           ; BRANCHCC OCCURS {$C$L35}        ; |492| 
$C$DW$L$_Send_Recive_Packet__FUiPvT2T1$2$E:
;** --------------------------------------------------------------------------*
	.dwpsn	file "test_c.cpp",line 493,column 4,is_stmt
;----------------------------------------------------------------------
; 493 | net_descriptor* p_txd = NULL;                                          
;----------------------------------------------------------------------
           BNOP    .S1     $C$L45,4          ; |493| 
           MVK     .L1     0x1,A4            ; |493| 
           ; BRANCH OCCURS {$C$L45}          ; |493| 
;** --------------------------------------------------------------------------*
$C$L35:    
$C$DW$L$_Send_Recive_Packet__FUiPvT2T1$4$B:
	.dwpsn	file "test_c.cpp",line 494,column 5,is_stmt
;----------------------------------------------------------------------
; 494 | net_descriptor* p_rxd = NULL;                                          
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(24),B0       ; |494| 
           NOP             4
   [!B0]   BNOP    .S1     $C$L36,5          ; |494| 
           ; BRANCHCC OCCURS {$C$L36}        ; |494| 
$C$DW$L$_Send_Recive_Packet__FUiPvT2T1$4$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_Send_Recive_Packet__FUiPvT2T1$5$B:
	.dwpsn	file "test_c.cpp",line 495,column 4,is_stmt
           MVKL    .S1     ___syscall_tab+284,A3
           MVKH    .S1     ___syscall_tab+284,A3
           LDW     .D1T1   *A3,A3            ; |495| 
           LDW     .D2T1   *+SP(4),A4        ; |495| 
           ADD     .D2     SP,24,B5          ; |495| 
           MVK     .S2     0x1101,B4         ; |495| 
           MV      .L1X    B5,A6             ; |495| 
$C$DW$359	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$359, DW_AT_low_pc(0x00)
	.dwattr $C$DW$359, DW_AT_TI_call
	.dwattr $C$DW$359, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |495| 
           ADDKPC  .S2     $C$RL16,B3,4      ; |495| 
$C$RL16:   ; CALL OCCURS {A3} {0}            ; |495| 
           MV      .L1     A4,A0             ; |495| 
   [!A0]   BNOP    .S1     $C$L36,5          ; |495| 
           ; BRANCHCC OCCURS {$C$L36}        ; |495| 
$C$DW$L$_Send_Recive_Packet__FUiPvT2T1$5$E:
;** --------------------------------------------------------------------------*
	.dwpsn	file "test_c.cpp",line 496,column 5,is_stmt
;----------------------------------------------------------------------
; 496 | uint32 tim = 0x500000;                                                 
;----------------------------------------------------------------------
           BNOP    .S1     $C$L45,4          ; |496| 
           MVK     .L1     0x1,A4            ; |496| 
           ; BRANCH OCCURS {$C$L45}          ; |496| 
;** --------------------------------------------------------------------------*
$C$L36:    
$C$DW$L$_Send_Recive_Packet__FUiPvT2T1$7$B:
	.dwpsn	file "test_c.cpp",line 497,column 9,is_stmt
;----------------------------------------------------------------------
; 497 | do//очистка приема                                                     
; 499 |         if( drv_ioctl( FileNet, NET_RECV_GET, &p_rxd ) != OSE_OK )     
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(24),B0       ; |497| 
           NOP             4
   [ B0]   BNOP    .S1     $C$L34,5          ; |497| 
           ; BRANCHCC OCCURS {$C$L34}        ; |497| 
$C$DW$L$_Send_Recive_Packet__FUiPvT2T1$7$E:
;** --------------------------------------------------------------------------*
	.dwpsn	file "test_c.cpp",line 500,column 3,is_stmt
;----------------------------------------------------------------------
; 500 | return TPO_ERR;                                                        
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+284,A3
           MVKH    .S1     ___syscall_tab+284,A3
           LDW     .D1T1   *A3,A3            ; |500| 
           LDW     .D2T1   *+SP(4),A4        ; |500| 
           ADD     .D2     SP,20,B5          ; |500| 
           MVK     .S2     0x1102,B4         ; |500| 
           MV      .L1X    B5,A6             ; |500| 
$C$DW$360	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$360, DW_AT_low_pc(0x00)
	.dwattr $C$DW$360, DW_AT_TI_call
	.dwattr $C$DW$360, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |500| 
           ADDKPC  .S2     $C$RL17,B3,4      ; |500| 
$C$RL17:   ; CALL OCCURS {A3} {0}            ; |500| 
           MV      .L1     A4,A0             ; |500| 
   [!A0]   BNOP    .S1     $C$L37,5          ; |500| 
           ; BRANCHCC OCCURS {$C$L37}        ; |500| 
;** --------------------------------------------------------------------------*
	.dwpsn	file "test_c.cpp",line 501,column 2,is_stmt
;----------------------------------------------------------------------
; 501 | if( p_rxd != NULL )                                                    
;----------------------------------------------------------------------
           BNOP    .S1     $C$L45,4          ; |501| 
           MVK     .L1     0x1,A4            ; |501| 
           ; BRANCH OCCURS {$C$L45}          ; |501| 
;** --------------------------------------------------------------------------*
$C$L37:    
	.dwpsn	file "test_c.cpp",line 502,column 3,is_stmt
;----------------------------------------------------------------------
; 502 | if( drv_ioctl( FileNet, NET_RECV_PUT, &p_rxd ) != OSE_OK )             
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(20),B0       ; |502| 
           NOP             4
   [ B0]   BNOP    .S1     $C$L38,5          ; |502| 
           ; BRANCHCC OCCURS {$C$L38}        ; |502| 
;** --------------------------------------------------------------------------*
	.dwpsn	file "test_c.cpp",line 503,column 2,is_stmt
;----------------------------------------------------------------------
; 503 | return TPO_ERR;                                                        
;----------------------------------------------------------------------
           BNOP    .S1     $C$L45,4          ; |503| 
           MVK     .L1     0x1,A4            ; |503| 
           ; BRANCH OCCURS {$C$L45}          ; |503| 
;** --------------------------------------------------------------------------*
$C$L38:    
	.dwpsn	file "test_c.cpp",line 504,column 3,is_stmt
;----------------------------------------------------------------------
; 504 | }while(p_rxd != NULL);                                                 
;----------------------------------------------------------------------
           MV      .L2     B0,B4
           LDW     .D2T2   *+B4(8),B5        ; |504| 
           MVK     .S2     140,B31           ; |504| 
           NOP             3
           CMPGTU  .L2     B31,B5,B0         ; |504| 
   [!B0]   BNOP    .S1     $C$L39,5          ; |504| 
           ; BRANCHCC OCCURS {$C$L39}        ; |504| 
;** --------------------------------------------------------------------------*
	.dwpsn	file "test_c.cpp",line 505,column 2,is_stmt
           BNOP    .S1     $C$L45,4          ; |505| 
           MVK     .L1     0x1,A4            ; |505| 
           ; BRANCH OCCURS {$C$L45}          ; |505| 
;** --------------------------------------------------------------------------*
$C$L39:    
	.dwpsn	file "test_c.cpp",line 507,column 2,is_stmt
;----------------------------------------------------------------------
; 507 | if( drv_ioctl( FileNet, NET_SEND_GET, &p_txd ) != OSE_OK )    //готовим
;     |  к отправке                                                            
; 508 |       return TPO_ERR;                                                  
; 509 | if( p_txd == NULL )                                                    
; 510 |       return TPO_ERR;                                                  
;----------------------------------------------------------------------
           MVKL    .S2     ___syscall_tab+252,B4
           MVKH    .S2     ___syscall_tab+252,B4
           LDW     .D2T2   *B4,B4            ; |507| 
           MVK     .S1     0x64,A4           ; |507| 
           NOP             3
$C$DW$361	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$361, DW_AT_low_pc(0x00)
	.dwattr $C$DW$361, DW_AT_TI_call
	.dwattr $C$DW$361, DW_AT_TI_indirect
           CALL    .S2     B4                ; |507| 
           ADDKPC  .S2     $C$RL18,B3,4      ; |507| 
$C$RL18:   ; CALL OCCURS {B4} {0}            ; |507| 
	.dwpsn	file "test_c.cpp",line 511,column 3,is_stmt
;----------------------------------------------------------------------
; 511 | if( LEN_BUF1_FOR_TEST_SK > p_txd->size )                               
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(20),B5       ; |511| 
           LDW     .D2T1   *+SP(16),A6       ; |511| 
           LDW     .D2T2   *+SP(8),B4        ; |511| 
           NOP             1
$C$DW$362	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$362, DW_AT_low_pc(0x00)
	.dwattr $C$DW$362, DW_AT_name("_memcpy")
	.dwattr $C$DW$362, DW_AT_TI_call
           CALL    .S1     _memcpy           ; |511| 
           LDW     .D2T1   *+B5(16),A4       ; |511| 
           ADDKPC  .S2     $C$RL19,B3,3      ; |511| 
$C$RL19:   ; CALL OCCURS {_memcpy} {0}       ; |511| 
	.dwpsn	file "test_c.cpp",line 512,column 3,is_stmt
;----------------------------------------------------------------------
; 512 | return TPO_ERR;                                                        
; 514 | sleep_m(100);                                                          
; 515 | //      sleep_m(50);                                                   
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(16),B4       ; |512| 
           LDW     .D2T1   *+SP(20),A3       ; |512| 
           NOP             4
           STW     .D1T2   B4,*+A3(12)       ; |512| 
	.dwpsn	file "test_c.cpp",line 516,column 3,is_stmt
;----------------------------------------------------------------------
; 516 | //while(tim--);                                                        
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+284,A3
           MVKH    .S1     ___syscall_tab+284,A3
           LDW     .D1T1   *A3,A3            ; |516| 
           LDW     .D2T1   *+SP(4),A4        ; |516| 
           ADD     .D2     SP,20,B5          ; |516| 
           MVK     .S2     0x1103,B4         ; |516| 
           MV      .L1X    B5,A6             ; |516| 
$C$DW$363	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$363, DW_AT_low_pc(0x00)
	.dwattr $C$DW$363, DW_AT_TI_call
	.dwattr $C$DW$363, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |516| 
           ADDKPC  .S2     $C$RL20,B3,4      ; |516| 
$C$RL20:   ; CALL OCCURS {A3} {0}            ; |516| 
           MV      .L1     A4,A0             ; |516| 
   [!A0]   BNOP    .S1     $C$L40,5          ; |516| 
           ; BRANCHCC OCCURS {$C$L40}        ; |516| 
;** --------------------------------------------------------------------------*
	.dwpsn	file "test_c.cpp",line 517,column 2,is_stmt
;----------------------------------------------------------------------
; 518 | memcpy( p_txd->data, Pack_wr, len );                                   
; 519 | p_txd->length = len;                                                   
; 521 | //res = VAL;                                                           
;----------------------------------------------------------------------
           BNOP    .S1     $C$L45,4          ; |517| 
           MVK     .L1     0x1,A4            ; |517| 
           ; BRANCH OCCURS {$C$L45}          ; |517| 
;** --------------------------------------------------------------------------*
$C$L40:    
	.dwpsn	file "test_c.cpp",line 522,column 2,is_stmt
;----------------------------------------------------------------------
; 522 | //VAL = res | 0x8;                                                     
; 523 | if( drv_ioctl( FileNet, NET_SEND_PUT, &p_txd ) != OSE_OK )    //отправл
; 524 | ем                                                                     
; 525 |       return TPO_ERR;                                                  
;----------------------------------------------------------------------
           MVKL    .S2     ___syscall_tab+252,B4
           MVKH    .S2     ___syscall_tab+252,B4
           LDW     .D2T2   *B4,B4            ; |522| 
           MVK     .S1     0x64,A4           ; |522| 
           NOP             3
$C$DW$364	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$364, DW_AT_low_pc(0x00)
	.dwattr $C$DW$364, DW_AT_TI_call
	.dwattr $C$DW$364, DW_AT_TI_indirect
           CALL    .S2     B4                ; |522| 
           ADDKPC  .S2     $C$RL21,B3,4      ; |522| 
$C$RL21:   ; CALL OCCURS {B4} {0}            ; |522| 
	.dwpsn	file "test_c.cpp",line 526,column 3,is_stmt
;----------------------------------------------------------------------
; 526 | //VAL = res & (~0x8);                                                  
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+284,A3
           MVKH    .S1     ___syscall_tab+284,A3
           LDW     .D1T1   *A3,A3            ; |526| 
           LDW     .D2T1   *+SP(4),A4        ; |526| 
           ADD     .D2     SP,24,B5          ; |526| 
           MVK     .S2     0x1100,B4         ; |526| 
           MV      .L1X    B5,A6             ; |526| 
$C$DW$365	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$365, DW_AT_low_pc(0x00)
	.dwattr $C$DW$365, DW_AT_TI_call
	.dwattr $C$DW$365, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |526| 
           ADDKPC  .S2     $C$RL22,B3,4      ; |526| 
$C$RL22:   ; CALL OCCURS {A3} {0}            ; |526| 
           MV      .L1     A4,A0             ; |526| 
   [!A0]   BNOP    .S1     $C$L41,5          ; |526| 
           ; BRANCHCC OCCURS {$C$L41}        ; |526| 
;** --------------------------------------------------------------------------*
	.dwpsn	file "test_c.cpp",line 527,column 2,is_stmt
           BNOP    .S1     $C$L45,4          ; |527| 
           MVK     .L1     0x1,A4            ; |527| 
           ; BRANCH OCCURS {$C$L45}          ; |527| 
;** --------------------------------------------------------------------------*
$C$L41:    
	.dwpsn	file "test_c.cpp",line 528,column 3,is_stmt
           LDW     .D2T2   *+SP(24),B0       ; |528| 
           NOP             4
   [ B0]   BNOP    .S1     $C$L42,5          ; |528| 
           ; BRANCHCC OCCURS {$C$L42}        ; |528| 
;** --------------------------------------------------------------------------*
	.dwpsn	file "test_c.cpp",line 529,column 2,is_stmt
           BNOP    .S1     $C$L45,4          ; |529| 
           MVK     .L1     0x1,A4            ; |529| 
           ; BRANCH OCCURS {$C$L45}          ; |529| 
;** --------------------------------------------------------------------------*
$C$L42:    
	.dwpsn	file "test_c.cpp",line 530,column 3,is_stmt
;----------------------------------------------------------------------
; 530 | sleep_m(100);                                                          
;----------------------------------------------------------------------

           MV      .L2     B0,B5
||         LDW     .D2T2   *+SP(16),B4       ; |530| 

           LDW     .D2T2   *+B5(12),B5       ; |530| 
           NOP             4
           CMPEQ   .L2     B5,B4,B0          ; |530| 
   [ B0]   BNOP    .S1     $C$L43,5          ; |530| 
           ; BRANCHCC OCCURS {$C$L43}        ; |530| 
;** --------------------------------------------------------------------------*
	.dwpsn	file "test_c.cpp",line 531,column 2,is_stmt
;----------------------------------------------------------------------
; 531 | //tim = 0x500000;                                                      
; 532 | //while(tim--);                                                        
;----------------------------------------------------------------------
           BNOP    .S1     $C$L45,4          ; |531| 
           MVK     .L1     0x1,A4            ; |531| 
           ; BRANCH OCCURS {$C$L45}          ; |531| 
;** --------------------------------------------------------------------------*
$C$L43:    
	.dwpsn	file "test_c.cpp",line 533,column 3,is_stmt
;----------------------------------------------------------------------
; 534 | if( drv_ioctl( FileNet, NET_RECV_GET, &p_rxd ) != OSE_OK )             
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(24),B4       ; |533| 
           LDW     .D2T1   *+SP(12),A4       ; |533| 
           NOP             3
$C$DW$366	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$366, DW_AT_low_pc(0x04)
	.dwattr $C$DW$366, DW_AT_name("_memcpy")
	.dwattr $C$DW$366, DW_AT_TI_call

           MV      .L1X    B4,A3             ; |533| 
||         CALL    .S1     _memcpy           ; |533| 

           LDW     .D2T1   *+B4(12),A6       ; |533| 
||         LDW     .D1T2   *+A3(16),B4       ; |533| 

           ADDKPC  .S2     $C$RL23,B3,3      ; |533| 
$C$RL23:   ; CALL OCCURS {_memcpy} {0}       ; |533| 
	.dwpsn	file "test_c.cpp",line 535,column 2,is_stmt
;----------------------------------------------------------------------
; 535 | return TPO_ERR;                                                        
; 536 | if( p_rxd == NULL )                                                    
; 537 | return TPO_ERR;                                                        
; 538 | if( p_rxd->length != len)                                              
;----------------------------------------------------------------------
           MVKL    .S2     ___syscall_tab+252,B4
           MVKH    .S2     ___syscall_tab+252,B4
           LDW     .D2T2   *B4,B4            ; |535| 
           MVK     .S1     0x64,A4           ; |535| 
           NOP             3
$C$DW$367	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$367, DW_AT_low_pc(0x00)
	.dwattr $C$DW$367, DW_AT_TI_call
	.dwattr $C$DW$367, DW_AT_TI_indirect
           CALL    .S2     B4                ; |535| 
           ADDKPC  .S2     $C$RL24,B3,4      ; |535| 
$C$RL24:   ; CALL OCCURS {B4} {0}            ; |535| 
	.dwpsn	file "test_c.cpp",line 539,column 3,is_stmt
;----------------------------------------------------------------------
; 539 | return TPO_ERR;                                                        
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+284,A3
           MVKH    .S1     ___syscall_tab+284,A3
           LDW     .D1T1   *A3,A3            ; |539| 
           LDW     .D2T1   *+SP(4),A4        ; |539| 
           ADD     .D2     SP,24,B4          ; |539| 
           NOP             2
$C$DW$368	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$368, DW_AT_low_pc(0x00)
	.dwattr $C$DW$368, DW_AT_TI_call
	.dwattr $C$DW$368, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |539| 
           MV      .L1X    B4,A6             ; |539| 
           MVK     .S2     0x1101,B4         ; |539| 
           ADDKPC  .S2     $C$RL25,B3,2      ; |539| 
$C$RL25:   ; CALL OCCURS {A3} {0}            ; |539| 
           MV      .L1     A4,A0             ; |539| 
   [!A0]   BNOP    .S1     $C$L44,5          ; |539| 
           ; BRANCHCC OCCURS {$C$L44}        ; |539| 
;** --------------------------------------------------------------------------*
	.dwpsn	file "test_c.cpp",line 540,column 2,is_stmt
;----------------------------------------------------------------------
; 541 | memcpy( Pack_rd, p_rxd->data, p_rxd->length );                         
;----------------------------------------------------------------------
           BNOP    .S1     $C$L45,4          ; |540| 
           MVK     .L1     0x1,A4            ; |540| 
           ; BRANCH OCCURS {$C$L45}          ; |540| 
;** --------------------------------------------------------------------------*
$C$L44:    
	.dwpsn	file "test_c.cpp",line 543,column 3,is_stmt
;----------------------------------------------------------------------
; 543 | sleep_m(100);                                                          
;----------------------------------------------------------------------
           ZERO    .L1     A4                ; |543| 
;** --------------------------------------------------------------------------*
$C$L45:    
	.dwpsn	file "test_c.cpp",line 544,column 1,is_stmt
;----------------------------------------------------------------------
; 544 | //tim = 0x500000;                                                      
;----------------------------------------------------------------------
           LDW     .D2T2   *++SP(32),B3      ; |544| 
           NOP             4
	.dwcfi	cfa_offset, 0
	.dwcfi	restore_reg, 19
	.dwcfi	cfa_offset, 0
$C$DW$369	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$369, DW_AT_low_pc(0x00)
	.dwattr $C$DW$369, DW_AT_TI_return
           RETNOP  .S2     B3,5              ; |544| 
           ; BRANCH OCCURS {B3}              ; |544| 

$C$DW$370	.dwtag  DW_TAG_TI_loop
	.dwattr $C$DW$370, DW_AT_name("C:\1901VC1T_Inteltech\3rdPartyLIB\dsp_core\C6000\tpo_amoeba\source\test_c.asm:$C$L34:1:1517815039")
	.dwattr $C$DW$370, DW_AT_TI_begin_file("test_c.cpp")
	.dwattr $C$DW$370, DW_AT_TI_begin_line(0x1ea)
	.dwattr $C$DW$370, DW_AT_TI_end_line(0x1f1)
$C$DW$371	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$371, DW_AT_low_pc($C$DW$L$_Send_Recive_Packet__FUiPvT2T1$2$B)
	.dwattr $C$DW$371, DW_AT_high_pc($C$DW$L$_Send_Recive_Packet__FUiPvT2T1$2$E)
$C$DW$372	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$372, DW_AT_low_pc($C$DW$L$_Send_Recive_Packet__FUiPvT2T1$4$B)
	.dwattr $C$DW$372, DW_AT_high_pc($C$DW$L$_Send_Recive_Packet__FUiPvT2T1$4$E)
$C$DW$373	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$373, DW_AT_low_pc($C$DW$L$_Send_Recive_Packet__FUiPvT2T1$5$B)
	.dwattr $C$DW$373, DW_AT_high_pc($C$DW$L$_Send_Recive_Packet__FUiPvT2T1$5$E)
$C$DW$374	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$374, DW_AT_low_pc($C$DW$L$_Send_Recive_Packet__FUiPvT2T1$7$B)
	.dwattr $C$DW$374, DW_AT_high_pc($C$DW$L$_Send_Recive_Packet__FUiPvT2T1$7$E)
	.dwendtag $C$DW$370

	.dwattr $C$DW$346, DW_AT_TI_end_file("test_c.cpp")
	.dwattr $C$DW$346, DW_AT_TI_end_line(0x220)
	.dwattr $C$DW$346, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$346

	.sect	".text"
	.clink
	.global	_Test_SK__Fv

$C$DW$375	.dwtag  DW_TAG_subprogram, DW_AT_name("Test_SK")
	.dwattr $C$DW$375, DW_AT_low_pc(_Test_SK__Fv)
	.dwattr $C$DW$375, DW_AT_high_pc(0x00)
	.dwattr $C$DW$375, DW_AT_TI_symbol_name("_Test_SK__Fv")
	.dwattr $C$DW$375, DW_AT_external
	.dwattr $C$DW$375, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$375, DW_AT_TI_begin_file("test_c.cpp")
	.dwattr $C$DW$375, DW_AT_TI_begin_line(0x228)
	.dwattr $C$DW$375, DW_AT_TI_begin_column(0x08)
	.dwpsn	file "test_c.cpp",line 553,column 1,is_stmt,address _Test_SK__Fv

	.dwfde $C$DW$CIE, _Test_SK__Fv

;******************************************************************************
;* FUNCTION NAME: Test_SK()                                                   *
;*                                                                            *
;*   Regs Modified     : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP,A16,A17,A18,A19,A20,A21,A22,A23,A24, *
;*                           A25,A26,A27,A28,A29,A30,A31,B16,B17,B18,B19,B20, *
;*                           B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31      *
;*   Regs Used         : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP,A16,A17,A18,A19,A20,A21,A22,A23,A24, *
;*                           A25,A26,A27,A28,A29,A30,A31,B16,B17,B18,B19,B20, *
;*                           B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31      *
;*   Local Frame Size  : 0 Args + 452 Auto + 4 Save = 456 byte                *
;******************************************************************************
_Test_SK__Fv:
;** --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
	.dwcfi	save_reg_to_reg, 228, 19
           ADDK    .S2     -456,SP           ; |553| 
	.dwcfi	cfa_offset, 456
           STW     .D2T2   B3,*+SP(456)      ; |553| 
	.dwcfi	save_reg_to_mem, 19, 0
$C$DW$376	.dwtag  DW_TAG_variable, DW_AT_name("res")
	.dwattr $C$DW$376, DW_AT_TI_symbol_name("_res")
	.dwattr $C$DW$376, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$376, DW_AT_location[DW_OP_breg31 4]
$C$DW$377	.dwtag  DW_TAG_variable, DW_AT_name("error")
	.dwattr $C$DW$377, DW_AT_TI_symbol_name("_error")
	.dwattr $C$DW$377, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$377, DW_AT_location[DW_OP_breg31 8]
$C$DW$378	.dwtag  DW_TAG_variable, DW_AT_name("id1")
	.dwattr $C$DW$378, DW_AT_TI_symbol_name("_id1")
	.dwattr $C$DW$378, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$378, DW_AT_location[DW_OP_breg31 12]
$C$DW$379	.dwtag  DW_TAG_variable, DW_AT_name("id2")
	.dwattr $C$DW$379, DW_AT_TI_symbol_name("_id2")
	.dwattr $C$DW$379, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$379, DW_AT_location[DW_OP_breg31 16]
$C$DW$380	.dwtag  DW_TAG_variable, DW_AT_name("link")
	.dwattr $C$DW$380, DW_AT_TI_symbol_name("_link")
	.dwattr $C$DW$380, DW_AT_type(*$C$DW$T$701)
	.dwattr $C$DW$380, DW_AT_location[DW_OP_breg31 20]
$C$DW$381	.dwtag  DW_TAG_variable, DW_AT_name("buf_big_wr")
	.dwattr $C$DW$381, DW_AT_TI_symbol_name("_buf_big_wr")
	.dwattr $C$DW$381, DW_AT_type(*$C$DW$T$705)
	.dwattr $C$DW$381, DW_AT_location[DW_OP_breg31 24]
$C$DW$382	.dwtag  DW_TAG_variable, DW_AT_name("buf_small_wr")
	.dwattr $C$DW$382, DW_AT_TI_symbol_name("_buf_small_wr")
	.dwattr $C$DW$382, DW_AT_type(*$C$DW$T$703)
	.dwattr $C$DW$382, DW_AT_location[DW_OP_breg31 168]
$C$DW$383	.dwtag  DW_TAG_variable, DW_AT_name("buf_big_rd")
	.dwattr $C$DW$383, DW_AT_TI_symbol_name("_buf_big_rd")
	.dwattr $C$DW$383, DW_AT_type(*$C$DW$T$705)
	.dwattr $C$DW$383, DW_AT_location[DW_OP_breg31 232]
$C$DW$384	.dwtag  DW_TAG_variable, DW_AT_name("buf_small_rd")
	.dwattr $C$DW$384, DW_AT_TI_symbol_name("_buf_small_rd")
	.dwattr $C$DW$384, DW_AT_type(*$C$DW$T$703)
	.dwattr $C$DW$384, DW_AT_location[DW_OP_breg31 376]
$C$DW$385	.dwtag  DW_TAG_variable, DW_AT_name("FileNet")
	.dwattr $C$DW$385, DW_AT_TI_symbol_name("_FileNet")
	.dwattr $C$DW$385, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$385, DW_AT_location[DW_OP_breg31 440]
$C$DW$386	.dwtag  DW_TAG_variable, DW_AT_name("phy_reg")
	.dwattr $C$DW$386, DW_AT_TI_symbol_name("_phy_reg")
	.dwattr $C$DW$386, DW_AT_type(*$C$DW$T$585)
	.dwattr $C$DW$386, DW_AT_location[DW_OP_breg31 444]
$C$DW$387	.dwtag  DW_TAG_label, DW_AT_name("end_tst_sk"), DW_AT_low_pc($C$L57)
	.dwattr $C$DW$387, DW_AT_TI_symbol_name("_end_tst_sk")
	.dwpsn	file "test_c.cpp",line 554,column 8,is_stmt
           ZERO    .L2     B4                ; |554| 
           STW     .D2T2   B4,*+SP(4)        ; |554| 
	.dwpsn	file "test_c.cpp",line 555,column 5,is_stmt
;----------------------------------------------------------------------
; 556 | //---------------------------------------------------------------------
;     | -------                                                                
; 557 | //#define ERR_RW_M              1//1 - ошибка общени                   
; 558 | с модулем или системна                                                 
;----------------------------------------------------------------------
           STW     .D2T2   B4,*+SP(8)        ; |555| 
	.dwpsn	file "test_c.cpp",line 559,column 8,is_stmt
           ZERO    .L1     A3                ; |559| 
           STW     .D2T1   A3,*+SP(12)       ; |559| 
	.dwpsn	file "test_c.cpp",line 560,column 8,is_stmt
;----------------------------------------------------------------------
; 560 | //#define ERR_LOOP_M            2//2 - ошибка LOOPBACK в модуле        
;----------------------------------------------------------------------
           STW     .D2T1   A3,*+SP(16)       ; |560| 
	.dwpsn	file "test_c.cpp",line 561,column 6,is_stmt
;----------------------------------------------------------------------
; 561 | //#define ERR_LOOP_PHY  4//4 - ошибка LOOPBACK в физической среде      
; 562 | uint32 Test_SK()                                                       
; 564 | uint32 res = 0;                                                        
; 565 | int error = 0;                                                         
; 567 | //uint32* reg_gpio = (uint32*)0x01B00008;                              
;----------------------------------------------------------------------
           STB     .D2T1   A3,*+SP(20)       ; |561| 
	.dwpsn	file "test_c.cpp",line 568,column 1,is_stmt
;----------------------------------------------------------------------
; 568 | //uint32 l = 0;                                                        
;----------------------------------------------------------------------
$C$DW$388	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$388, DW_AT_low_pc(0x00)
	.dwattr $C$DW$388, DW_AT_name("_memset")
	.dwattr $C$DW$388, DW_AT_TI_call
           CALL    .S1     _memset           ; |568| 
           ADD     .D2     SP,24,B5          ; |568| 
           MVK     .S2     0xaa,B4           ; |568| 
           MV      .L1X    B5,A4             ; |568| 
           ADDKPC  .S2     $C$RL26,B3,0      ; |568| 
           MVK     .S1     0x8c,A6           ; |568| 
$C$RL26:   ; CALL OCCURS {_memset} {0}       ; |568| 
	.dwpsn	file "test_c.cpp",line 569,column 1,is_stmt
;----------------------------------------------------------------------
; 569 | uint32 id1 = 0;                                                        
;----------------------------------------------------------------------
$C$DW$389	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$389, DW_AT_low_pc(0x00)
	.dwattr $C$DW$389, DW_AT_name("_memset")
	.dwattr $C$DW$389, DW_AT_TI_call
           CALL    .S1     _memset           ; |569| 
           ADDAD   .D2     SP,21,B5          ; |569| 
           MVK     .S2     0x55,B4           ; |569| 
           MV      .L1X    B5,A4             ; |569| 
           ADDKPC  .S2     $C$RL27,B3,0      ; |569| 
           MVK     .S1     0x40,A6           ; |569| 
$C$RL27:   ; CALL OCCURS {_memset} {0}       ; |569| 
	.dwpsn	file "test_c.cpp",line 570,column 1,is_stmt
;----------------------------------------------------------------------
; 570 | uint32 id2 = 0;                                                        
;----------------------------------------------------------------------
$C$DW$390	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$390, DW_AT_low_pc(0x00)
	.dwattr $C$DW$390, DW_AT_name("_memset")
	.dwattr $C$DW$390, DW_AT_TI_call
           CALL    .S1     _memset           ; |570| 
           ADDAD   .D2     SP,29,B4          ; |570| 
           ADDKPC  .S2     $C$RL28,B3,2      ; |570| 

           MVK     .S1     0x8c,A6           ; |570| 
||         MV      .L1X    B4,A4             ; |570| 
||         ZERO    .L2     B4                ; |570| 

$C$RL28:   ; CALL OCCURS {_memset} {0}       ; |570| 
	.dwpsn	file "test_c.cpp",line 571,column 1,is_stmt
;----------------------------------------------------------------------
; 571 | bool link = false;                                                     
;----------------------------------------------------------------------
$C$DW$391	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$391, DW_AT_low_pc(0x00)
	.dwattr $C$DW$391, DW_AT_name("_memset")
	.dwattr $C$DW$391, DW_AT_TI_call
           CALL    .S1     _memset           ; |571| 
           MVK     .S2     376,B4            ; |571| 
           ADD     .L2     B4,SP,B4          ; |571| 
           ADDKPC  .S2     $C$RL29,B3,1      ; |571| 

           MVK     .S1     0x40,A6           ; |571| 
||         MV      .L1X    B4,A4             ; |571| 
||         ZERO    .L2     B4                ; |571| 

$C$RL29:   ; CALL OCCURS {_memset} {0}       ; |571| 
	.dwpsn	file "test_c.cpp",line 573,column 8,is_stmt
;----------------------------------------------------------------------
; 573 | uint8 buf_big_wr[LEN_BUF1_FOR_TEST_SK]; //1514                         
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+292,A3
           MVKH    .S1     ___syscall_tab+292,A3
           LDW     .D1T1   *A3,A3            ; |573| 
           MVKL    .S1     $C$SL1+0,A4       ; |573| 
           MVKH    .S1     $C$SL1+0,A4       ; |573| 
           NOP             2
$C$DW$392	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$392, DW_AT_low_pc(0x00)
	.dwattr $C$DW$392, DW_AT_TI_call
	.dwattr $C$DW$392, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |573| 
           ADDKPC  .S2     $C$RL30,B3,4      ; |573| 
$C$RL30:   ; CALL OCCURS {A3} {0}            ; |573| 
           STW     .D2T1   A4,*+SP(440)      ; |573| 
	.dwpsn	file "test_c.cpp",line 574,column 2,is_stmt
;----------------------------------------------------------------------
; 574 | uint8 buf_small_wr[LEN_BUF2_FOR_TEST_SK];       //64                   
;----------------------------------------------------------------------
           MV      .L2X    A4,B0
   [ B0]   BNOP    .S1     $C$L46,5          ; |574| 
           ; BRANCHCC OCCURS {$C$L46}        ; |574| 
;** --------------------------------------------------------------------------*
	.dwpsn	file "test_c.cpp",line 575,column 3,is_stmt
;----------------------------------------------------------------------
; 575 | uint8 buf_big_rd[LEN_BUF1_FOR_TEST_SK]; //1514                         
; 576 | uint8 buf_small_rd[LEN_BUF2_FOR_TEST_SK];       //64                   
; 578 | memset(buf_big_wr, 0xAA, LEN_BUF1_FOR_TEST_SK);                        
; 579 | memset(buf_small_wr, 0x55, LEN_BUF2_FOR_TEST_SK);                      
; 580 | memset(buf_big_rd, 0, LEN_BUF1_FOR_TEST_SK);                           
;----------------------------------------------------------------------
           BNOP    .S1     $C$L58,4          ; |575| 
           MVK     .L1     0x1,A4            ; |575| 
           ; BRANCH OCCURS {$C$L58}          ; |575| 
;** --------------------------------------------------------------------------*
$C$L46:    
	.dwpsn	file "test_c.cpp",line 581,column 1,is_stmt
;----------------------------------------------------------------------
; 581 | memset(buf_small_rd, 0, LEN_BUF2_FOR_TEST_SK);                         
;----------------------------------------------------------------------
           MVK     .S2     4371,B4           ; |581| 
           STW     .D2T2   B4,*+SP(444)      ; |581| 
	.dwpsn	file "test_c.cpp",line 582,column 1,is_stmt
           MVK     .L2     2,B4              ; |582| 
           STW     .D2T2   B4,*+SP(448)      ; |582| 
	.dwpsn	file "test_c.cpp",line 583,column 1,is_stmt
;----------------------------------------------------------------------
; 583 | uint32 FileNet = drv_mkd("/dev/net/eth0");                             
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+284,A3
           MVKH    .S1     ___syscall_tab+284,A3
           LDW     .D1T1   *A3,A3            ; |583| 
           MVK     .S2     444,B4            ; |583| 
           ADD     .L2     B4,SP,B5          ; |583| 
           MVK     .S2     0x1110,B4         ; |583| 
           MV      .L1X    B5,A6             ; |583| 
$C$DW$393	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$393, DW_AT_low_pc(0x00)
	.dwattr $C$DW$393, DW_AT_TI_call
	.dwattr $C$DW$393, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |583| 
           ADDKPC  .S2     $C$RL31,B3,4      ; |583| 
$C$RL31:   ; CALL OCCURS {A3} {0}            ; |583| 
           STW     .D2T1   A4,*+SP(8)        ; |583| 
	.dwpsn	file "test_c.cpp",line 584,column 2,is_stmt
;----------------------------------------------------------------------
; 584 | if(FileNet == RES_VOID)                                                
; 585 |         return TPO_ERR;                                                
;----------------------------------------------------------------------
           MV      .L2X    A4,B0
   [!B0]   BNOP    .S1     $C$L47,5          ; |584| 
           ; BRANCHCC OCCURS {$C$L47}        ; |584| 
;** --------------------------------------------------------------------------*
	.dwpsn	file "test_c.cpp",line 586,column 3,is_stmt
           MVK     .L2     1,B4              ; |586| 
           STW     .D2T2   B4,*+SP(4)        ; |586| 
	.dwpsn	file "test_c.cpp",line 587,column 3,is_stmt
;----------------------------------------------------------------------
; 588 | #ifdef TPO5                                                            
;----------------------------------------------------------------------
           BNOP    .S1     $C$L57,5          ; |587| 
           ; BRANCH OCCURS {$C$L57}          ; |587| 
;** --------------------------------------------------------------------------*
$C$L47:    
	.dwpsn	file "test_c.cpp",line 589,column 1,is_stmt
;----------------------------------------------------------------------
; 589 | dev_reg phy_reg;                                                       
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(452),B4      ; |589| 
           NOP             4
           EXTU    .S2     B4,16,16,B4       ; |589| 
           STW     .D2T2   B4,*+SP(12)       ; |589| 
	.dwpsn	file "test_c.cpp",line 591,column 1,is_stmt
;----------------------------------------------------------------------
; 591 | phy_reg.device = PHY_RW_REG;                                           
;----------------------------------------------------------------------
           MVK     .L2     3,B4              ; |591| 
           STW     .D2T2   B4,*+SP(448)      ; |591| 
	.dwpsn	file "test_c.cpp",line 592,column 1,is_stmt
;----------------------------------------------------------------------
; 592 | phy_reg.reg = PHYREG_ID1;                                              
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+284,A3
           MVKH    .S1     ___syscall_tab+284,A3
           LDW     .D1T1   *A3,A3            ; |592| 
           LDW     .D2T1   *+SP(440),A4      ; |592| 
           MVK     .S2     444,B4            ; |592| 
           ADD     .L2     B4,SP,B5          ; |592| 
           MVK     .S2     0x1110,B4         ; |592| 
$C$DW$394	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$394, DW_AT_low_pc(0x00)
	.dwattr $C$DW$394, DW_AT_TI_call
	.dwattr $C$DW$394, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |592| 
           ADDKPC  .S2     $C$RL32,B3,3      ; |592| 
           MV      .L1X    B5,A6             ; |592| 
$C$RL32:   ; CALL OCCURS {A3} {0}            ; |592| 
           STW     .D2T1   A4,*+SP(8)        ; |592| 
	.dwpsn	file "test_c.cpp",line 593,column 2,is_stmt
;----------------------------------------------------------------------
; 593 | error = drv_ioctl(FileNet, NET_READ_REG, &phy_reg);                    
; 594 | if(error != OSE_OK)                                                    
;----------------------------------------------------------------------
           MV      .L2X    A4,B0
   [!B0]   BNOP    .S1     $C$L48,5          ; |593| 
           ; BRANCHCC OCCURS {$C$L48}        ; |593| 
;** --------------------------------------------------------------------------*
	.dwpsn	file "test_c.cpp",line 595,column 3,is_stmt
           MVK     .L2     1,B4              ; |595| 
           STW     .D2T2   B4,*+SP(4)        ; |595| 
	.dwpsn	file "test_c.cpp",line 596,column 3,is_stmt
;----------------------------------------------------------------------
; 596 | res = TPO_ERR;                                                         
; 597 | goto end_tst_sk;                                                       
;----------------------------------------------------------------------
           BNOP    .S1     $C$L57,5          ; |596| 
           ; BRANCH OCCURS {$C$L57}          ; |596| 
;** --------------------------------------------------------------------------*
$C$L48:    
	.dwpsn	file "test_c.cpp",line 598,column 1,is_stmt
;----------------------------------------------------------------------
; 599 | id1 = phy_reg.value & 0xFFFF;                                          
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(452),B4      ; |598| 
           ZERO    .L1     A3                ; |598| 
           SET     .S1     A3,0x8,0xf,A3     ; |598| 
           NOP             2
           AND     .L2X    A3,B4,B4          ; |598| 
           STW     .D2T2   B4,*+SP(16)       ; |598| 
	.dwpsn	file "test_c.cpp",line 600,column 1,is_stmt
           LDW     .D2T2   *+SP(12),B5       ; |600| 
           MVK     .S1     19,A3             ; |600| 
           MVK     .S2     30720,B31         ; |600| 
           CMPEQ   .L2     B4,B31,B4         ; |600| 
           NOP             1
           CMPEQ   .L2X    B5,A3,B6          ; |600| 
           AND     .L2     B6,B4,B0
   [ B0]   BNOP    .S1     $C$L49,5          ; |600| 
           ; BRANCHCC OCCURS {$C$L49}        ; |600| 
;** --------------------------------------------------------------------------*
	.dwpsn	file "test_c.cpp",line 601,column 2,is_stmt
;----------------------------------------------------------------------
; 601 | phy_reg.reg = PHYREG_ID2;                                              
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(16),B4       ; |601| 
           LDW     .D2T2   *+SP(12),B6       ; |601| 
           MVK     .S1     34,A3             ; |601| 
           MVK     .S2     5376,B5           ; |601| 
           NOP             1
           CMPEQ   .L2     B4,B5,B4          ; |601| 
           CMPEQ   .L2X    B6,A3,B5          ; |601| 
           AND     .L2     B5,B4,B0
   [ B0]   BNOP    .S1     $C$L49,5          ; |601| 
           ; BRANCHCC OCCURS {$C$L49}        ; |601| 
;** --------------------------------------------------------------------------*
	.dwpsn	file "test_c.cpp",line 602,column 2,is_stmt
;----------------------------------------------------------------------
; 602 | error = drv_ioctl(FileNet, NET_READ_REG, &phy_reg);                    
; 603 | if(error != OSE_OK)                                                    
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(4),B4        ; |602| 
           NOP             4
           OR      .L2     4,B4,B4           ; |602| 
           STW     .D2T2   B4,*+SP(4)        ; |602| 
;** --------------------------------------------------------------------------*
$C$L49:    
	.dwpsn	file "test_c.cpp",line 604,column 1,is_stmt
;----------------------------------------------------------------------
; 605 | res = TPO_ERR;                                                         
;----------------------------------------------------------------------
           ZERO    .L2     B4                ; |604| 
           STW     .D2T2   B4,*+SP(448)      ; |604| 
	.dwpsn	file "test_c.cpp",line 606,column 1,is_stmt
;----------------------------------------------------------------------
; 606 | goto end_tst_sk;                                                       
;----------------------------------------------------------------------
           MVKL    .S2     ___syscall_tab+284,B4
           MVKH    .S2     ___syscall_tab+284,B4
           LDW     .D2T2   *B4,B5            ; |606| 
           LDW     .D2T1   *+SP(440),A4      ; |606| 
           MVK     .S1     444,A3            ; |606| 
           MVK     .S2     0x1110,B4         ; |606| 
           ADD     .L1X    A3,SP,A6          ; |606| 
$C$DW$395	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$395, DW_AT_low_pc(0x00)
	.dwattr $C$DW$395, DW_AT_TI_call
	.dwattr $C$DW$395, DW_AT_TI_indirect
           CALL    .S2     B5                ; |606| 
           ADDKPC  .S2     $C$RL33,B3,4      ; |606| 
$C$RL33:   ; CALL OCCURS {B5} {0}            ; |606| 
           STW     .D2T1   A4,*+SP(8)        ; |606| 
	.dwpsn	file "test_c.cpp",line 608,column 1,is_stmt
;----------------------------------------------------------------------
; 608 | id2 = phy_reg.value & 0xFF00;                                          
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(452),B4      ; |608| 
           NOP             4
           SET     .S2     B4,14,14,B4       ; |608| 
           STW     .D2T2   B4,*+SP(452)      ; |608| 
	.dwpsn	file "test_c.cpp",line 609,column 1,is_stmt
           MVKL    .S1     ___syscall_tab+284,A3
           MVKH    .S1     ___syscall_tab+284,A3
           LDW     .D1T1   *A3,A3            ; |609| 
           LDW     .D2T1   *+SP(440),A4      ; |609| 
           MVK     .S2     444,B4            ; |609| 
           ADD     .L2     B4,SP,B5          ; |609| 
           MVK     .S2     0x1111,B4         ; |609| 
$C$DW$396	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$396, DW_AT_low_pc(0x00)
	.dwattr $C$DW$396, DW_AT_TI_call
	.dwattr $C$DW$396, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |609| 
           ADDKPC  .S2     $C$RL34,B3,3      ; |609| 
           MV      .L1X    B5,A6             ; |609| 
$C$RL34:   ; CALL OCCURS {A3} {0}            ; |609| 
           STW     .D2T1   A4,*+SP(8)        ; |609| 
	.dwpsn	file "test_c.cpp",line 610,column 2,is_stmt
;----------------------------------------------------------------------
; 610 | if((id1 != 0x0013)|(id2 != 0x7800))                                    
; 611 | if((id1 != 0x0022)|(id2 != 0x1500))                                    
;----------------------------------------------------------------------
           MV      .L2X    A4,B0
   [!B0]   BNOP    .S1     $C$L50,5          ; |610| 
           ; BRANCHCC OCCURS {$C$L50}        ; |610| 
;** --------------------------------------------------------------------------*
	.dwpsn	file "test_c.cpp",line 612,column 3,is_stmt
;----------------------------------------------------------------------
; 612 | res|=ERR_RW_LXT;                                                       
;----------------------------------------------------------------------
           MVK     .L2     1,B4              ; |612| 
           STW     .D2T2   B4,*+SP(4)        ; |612| 
	.dwpsn	file "test_c.cpp",line 613,column 3,is_stmt
;----------------------------------------------------------------------
; 614 | phy_reg.reg = PHYREG_CONTROL;                                          
;----------------------------------------------------------------------
           BNOP    .S1     $C$L57,5          ; |613| 
           ; BRANCH OCCURS {$C$L57}          ; |613| 
;** --------------------------------------------------------------------------*
$C$L50:    
	.dwpsn	file "test_c.cpp",line 616,column 1,is_stmt
;----------------------------------------------------------------------
; 616 | error = drv_ioctl(FileNet, NET_READ_REG, &phy_reg);                    
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+252,A3
           MVKH    .S1     ___syscall_tab+252,A3
           LDW     .D1T1   *A3,A3            ; |616| 
           MVK     .S1     0x64,A4           ; |616| 
           NOP             3
$C$DW$397	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$397, DW_AT_low_pc(0x00)
	.dwattr $C$DW$397, DW_AT_TI_call
	.dwattr $C$DW$397, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |616| 
           ADDKPC  .S2     $C$RL35,B3,4      ; |616| 
$C$RL35:   ; CALL OCCURS {A3} {0}            ; |616| 
	.dwpsn	file "test_c.cpp",line 618,column 1,is_stmt
;----------------------------------------------------------------------
; 618 | phy_reg.value |= PHYREG_CONTROL_LOOPBACK;               //загон        
;----------------------------------------------------------------------
$C$DW$398	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$398, DW_AT_low_pc(0x00)
	.dwattr $C$DW$398, DW_AT_name("_Send_Recive_Packet__FUiPvT2T1")
	.dwattr $C$DW$398, DW_AT_TI_call
           CALL    .S1     _Send_Recive_Packet__FUiPvT2T1 ; |618| 
           LDW     .D2T1   *+SP(440),A4      ; |618| 
           ADDAD   .D2     SP,29,B5          ; |618| 
           MVK     .S2     0x8c,B6           ; |618| 
           MV      .L1X    B5,A6             ; |618| 

           ADDKPC  .S2     $C$RL36,B3,0      ; |618| 
||         ADD     .D2     SP,24,B4          ; |618| 

$C$RL36:   ; CALL OCCURS {_Send_Recive_Packet__FUiPvT2T1} {0}  ; |618| 
           STW     .D2T1   A4,*+SP(8)        ; |618| 
	.dwpsn	file "test_c.cpp",line 619,column 2,is_stmt
;----------------------------------------------------------------------
; 619 | ем модуль в loopback                                                   
;----------------------------------------------------------------------
$C$DW$399	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$399, DW_AT_low_pc(0x00)
	.dwattr $C$DW$399, DW_AT_name("_memcmp")
	.dwattr $C$DW$399, DW_AT_TI_call
           CALL    .S1     _memcmp           ; |619| 
           ADD     .D2     SP,24,B4          ; |619| 
           ADDKPC  .S2     $C$RL37,B3,2      ; |619| 

           MVK     .S1     0x8c,A6           ; |619| 
||         MV      .L1X    B4,A4             ; |619| 
||         ADDAD   .D2     SP,29,B4          ; |619| 

$C$RL37:   ; CALL OCCURS {_memcmp} {0}       ; |619| 
           LDW     .D2T2   *+SP(8),B4        ; |619| 
           NOP             4
           CMPEQ   .L2     B4,1,B4           ; |619| 
           NOP             1
           OR      .L1X    A4,B4,A0          ; |619| 
   [!A0]   BNOP    .S1     $C$L51,5          ; |619| 
           ; BRANCHCC OCCURS {$C$L51}        ; |619| 
;** --------------------------------------------------------------------------*
	.dwpsn	file "test_c.cpp",line 620,column 3,is_stmt
;----------------------------------------------------------------------
; 620 | error = drv_ioctl(FileNet, NET_WRITE_REG, &phy_reg);                   
; 621 | if(error != OSE_OK)                                                    
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(4),B4        ; |620| 
           NOP             4
           SET     .S2     B4,4,4,B4         ; |620| 
           STW     .D2T2   B4,*+SP(4)        ; |620| 
;** --------------------------------------------------------------------------*
$C$L51:    
	.dwpsn	file "test_c.cpp",line 622,column 1,is_stmt
$C$DW$400	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$400, DW_AT_low_pc(0x00)
	.dwattr $C$DW$400, DW_AT_name("_Send_Recive_Packet__FUiPvT2T1")
	.dwattr $C$DW$400, DW_AT_TI_call
           CALL    .S1     _Send_Recive_Packet__FUiPvT2T1 ; |622| 
           LDW     .D2T1   *+SP(440),A4      ; |622| 
           MVK     .S2     376,B4            ; |622| 
           ADD     .L2     B4,SP,B5          ; |622| 
           MVK     .S2     0x40,B6           ; |622| 

           MV      .L1X    B5,A6             ; |622| 
||         ADDAD   .D2     SP,21,B4          ; |622| 
||         ADDKPC  .S2     $C$RL38,B3,0      ; |622| 

$C$RL38:   ; CALL OCCURS {_Send_Recive_Packet__FUiPvT2T1} {0}  ; |622| 
           STW     .D2T1   A4,*+SP(8)        ; |622| 
	.dwpsn	file "test_c.cpp",line 623,column 2,is_stmt
;----------------------------------------------------------------------
; 623 | res = TPO_ERR;                                                         
;----------------------------------------------------------------------
$C$DW$401	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$401, DW_AT_low_pc(0x00)
	.dwattr $C$DW$401, DW_AT_name("_memcmp")
	.dwattr $C$DW$401, DW_AT_TI_call
           CALL    .S1     _memcmp           ; |623| 
           MVK     .S1     376,A3            ; |623| 
           ADDAD   .D2     SP,21,B4          ; |623| 
           ADDKPC  .S2     $C$RL39,B3,1      ; |623| 

           MVK     .S1     0x40,A6           ; |623| 
||         MV      .L1X    B4,A4             ; |623| 
||         ADD     .L2X    A3,SP,B4          ; |623| 

$C$RL39:   ; CALL OCCURS {_memcmp} {0}       ; |623| 
           LDW     .D2T2   *+SP(8),B4        ; |623| 
           NOP             4
           CMPEQ   .L2     B4,1,B4           ; |623| 
           NOP             1
           OR      .L1X    A4,B4,A0          ; |623| 
   [!A0]   BNOP    .S1     $C$L52,5          ; |623| 
           ; BRANCHCC OCCURS {$C$L52}        ; |623| 
;** --------------------------------------------------------------------------*
	.dwpsn	file "test_c.cpp",line 624,column 3,is_stmt
;----------------------------------------------------------------------
; 624 | goto end_tst_sk;                                                       
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(4),B4        ; |624| 
           NOP             4
           SET     .S2     B4,4,4,B4         ; |624| 
           STW     .D2T2   B4,*+SP(4)        ; |624| 
;** --------------------------------------------------------------------------*
$C$L52:    
	.dwpsn	file "test_c.cpp",line 627,column 1,is_stmt
;----------------------------------------------------------------------
; 627 | sleep_m(100);//1000                                                    
;----------------------------------------------------------------------
           ZERO    .L2     B4                ; |627| 
           STW     .D2T2   B4,*+SP(448)      ; |627| 
	.dwpsn	file "test_c.cpp",line 628,column 1,is_stmt
           LDW     .D2T2   *+SP(452),B4      ; |628| 
           MVK     .S1     16384,A3          ; |628| 
           NOP             3
           XOR     .L1X    A3,B4,A3          ; |628| 
           STW     .D2T1   A3,*+SP(452)      ; |628| 
	.dwpsn	file "test_c.cpp",line 629,column 1,is_stmt
;----------------------------------------------------------------------
; 629 | error = Send_Recive_Packet(FileNet, buf_big_wr, buf_big_rd, LEN_BUF1_FO
;     | R_TEST_SK);                                                            
;----------------------------------------------------------------------

           MV      .L2X    A3,B4
||         MVK     .S2     8448,B5           ; |629| 

           OR      .L2     B5,B4,B4          ; |629| 
           STW     .D2T2   B4,*+SP(452)      ; |629| 
	.dwpsn	file "test_c.cpp",line 630,column 1,is_stmt
;----------------------------------------------------------------------
; 630 | if((error == TPO_ERR) | (memcmp(buf_big_wr, buf_big_rd, LEN_BUF1_FOR_TE
;     | ST_SK)))                                                               
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+284,A3
           MVKH    .S1     ___syscall_tab+284,A3
           LDW     .D1T1   *A3,A3            ; |630| 
           LDW     .D2T1   *+SP(440),A4      ; |630| 
           MVK     .S2     444,B4            ; |630| 
           ADD     .L2     B4,SP,B5          ; |630| 
           MVK     .S2     0x1111,B4         ; |630| 
$C$DW$402	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$402, DW_AT_low_pc(0x00)
	.dwattr $C$DW$402, DW_AT_TI_call
	.dwattr $C$DW$402, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |630| 
           ADDKPC  .S2     $C$RL40,B3,3      ; |630| 
           MV      .L1X    B5,A6             ; |630| 
$C$RL40:   ; CALL OCCURS {A3} {0}            ; |630| 
           STW     .D2T1   A4,*+SP(8)        ; |630| 
	.dwpsn	file "test_c.cpp",line 631,column 2,is_stmt
;----------------------------------------------------------------------
; 631 | res|=ERR_LOOP_LXT;                                                     
;----------------------------------------------------------------------
           MV      .L2X    A4,B0
   [!B0]   BNOP    .S1     $C$L53,5          ; |631| 
           ; BRANCHCC OCCURS {$C$L53}        ; |631| 
;** --------------------------------------------------------------------------*
	.dwpsn	file "test_c.cpp",line 633,column 3,is_stmt
;----------------------------------------------------------------------
; 633 | error = Send_Recive_Packet(FileNet, buf_small_wr, buf_small_rd, LEN_BUF
;     | 2_FOR_TEST_SK);                                                        
;----------------------------------------------------------------------
           MVK     .L2     1,B4              ; |633| 
           STW     .D2T2   B4,*+SP(4)        ; |633| 
	.dwpsn	file "test_c.cpp",line 634,column 3,is_stmt
;----------------------------------------------------------------------
; 634 | if((error == TPO_ERR) | (memcmp(buf_small_wr, buf_small_rd, LEN_BUF2_FO
;     | R_TEST_SK)))                                                           
; 635 |         res|=ERR_LOOP_LXT;                                             
; 638 | phy_reg.reg = PHYREG_CONTROL;                                          
;----------------------------------------------------------------------
           BNOP    .S1     $C$L57,5          ; |634| 
           ; BRANCH OCCURS {$C$L57}          ; |634| 
;** --------------------------------------------------------------------------*
$C$L53:    
	.dwpsn	file "test_c.cpp",line 639,column 1,is_stmt
;----------------------------------------------------------------------
; 639 | phy_reg.value ^= PHYREG_CONTROL_LOOPBACK;       //снимаем loopback     
;----------------------------------------------------------------------
$C$DW$403	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$403, DW_AT_low_pc(0x00)
	.dwattr $C$DW$403, DW_AT_name("_memset")
	.dwattr $C$DW$403, DW_AT_TI_call
           CALL    .S1     _memset           ; |639| 
           ADDAD   .D2     SP,29,B4          ; |639| 
           ADDKPC  .S2     $C$RL41,B3,2      ; |639| 

           MVK     .S1     0x8c,A6           ; |639| 
||         MV      .L1X    B4,A4             ; |639| 
||         ZERO    .L2     B4                ; |639| 

$C$RL41:   ; CALL OCCURS {_memset} {0}       ; |639| 
	.dwpsn	file "test_c.cpp",line 640,column 1,is_stmt
;----------------------------------------------------------------------
; 640 | phy_reg.value |= (PHYREG_CONTROL_SPEED100 | PHYREG_CONTROL_DUPLEXFULL);
;     |                                                                        
; 641 | error = drv_ioctl(FileNet, NET_WRITE_REG, &phy_reg);                   
; 642 | if(error != OSE_OK)                                                    
;----------------------------------------------------------------------
$C$DW$404	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$404, DW_AT_low_pc(0x00)
	.dwattr $C$DW$404, DW_AT_name("_memset")
	.dwattr $C$DW$404, DW_AT_TI_call
           CALL    .S1     _memset           ; |640| 
           MVK     .S1     376,A3            ; |640| 
           ADD     .L1X    A3,SP,A4          ; |640| 
           ADDKPC  .S2     $C$RL42,B3,1      ; |640| 

           ZERO    .L2     B4                ; |640| 
||         MVK     .S1     0x40,A6           ; |640| 

$C$RL42:   ; CALL OCCURS {_memset} {0}       ; |640| 
	.dwpsn	file "test_c.cpp",line 644,column 1,is_stmt
;----------------------------------------------------------------------
; 644 | res = TPO_ERR;                                                         
; 645 | goto end_tst_sk;                                                       
;----------------------------------------------------------------------
           MVKL    .S2     ___syscall_tab+252,B4
           MVKH    .S2     ___syscall_tab+252,B4
           LDW     .D2T2   *B4,B4            ; |644| 
           MVK     .S1     0x1f4,A4          ; |644| 
           NOP             3
$C$DW$405	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$405, DW_AT_low_pc(0x00)
	.dwattr $C$DW$405, DW_AT_TI_call
	.dwattr $C$DW$405, DW_AT_TI_indirect
           CALL    .S2     B4                ; |644| 
           ADDKPC  .S2     $C$RL43,B3,4      ; |644| 
$C$RL43:   ; CALL OCCURS {B4} {0}            ; |644| 
	.dwpsn	file "test_c.cpp",line 646,column 1,is_stmt
           MVKL    .S1     ___syscall_tab+284,A3
           MVKH    .S1     ___syscall_tab+284,A3
           LDW     .D1T1   *A3,A3            ; |646| 
           LDW     .D2T1   *+SP(440),A4      ; |646| 
           ADD     .D2     SP,20,B4          ; |646| 
           NOP             2
$C$DW$406	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$406, DW_AT_low_pc(0x00)
	.dwattr $C$DW$406, DW_AT_TI_call
	.dwattr $C$DW$406, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |646| 
           MV      .L1X    B4,A6             ; |646| 
           MVK     .S2     0x110f,B4         ; |646| 
           ADDKPC  .S2     $C$RL44,B3,2      ; |646| 
$C$RL44:   ; CALL OCCURS {A3} {0}            ; |646| 
           STW     .D2T1   A4,*+SP(8)        ; |646| 
	.dwpsn	file "test_c.cpp",line 647,column 2,is_stmt
           MV      .L2X    A4,B0
   [!B0]   BNOP    .S1     $C$L54,5          ; |647| 
           ; BRANCHCC OCCURS {$C$L54}        ; |647| 
;** --------------------------------------------------------------------------*
	.dwpsn	file "test_c.cpp",line 649,column 3,is_stmt
           MVK     .L2     1,B4              ; |649| 
           STW     .D2T2   B4,*+SP(4)        ; |649| 
	.dwpsn	file "test_c.cpp",line 650,column 3,is_stmt
;----------------------------------------------------------------------
; 650 | memset(buf_big_rd, 0, LEN_BUF1_FOR_TEST_SK);                           
; 651 | memset(buf_small_rd, 0, LEN_BUF2_FOR_TEST_SK);                         
; 652 | //#else                                                                
;----------------------------------------------------------------------
           BNOP    .S1     $C$L57,5          ; |650| 
           ; BRANCH OCCURS {$C$L57}          ; |650| 
;** --------------------------------------------------------------------------*
$C$L54:    
	.dwpsn	file "test_c.cpp",line 653,column 1,is_stmt
;----------------------------------------------------------------------
; 653 | #endif                                                                 
;----------------------------------------------------------------------
           LDB     .D2T2   *+SP(20),B0       ; |653| 
           NOP             4
   [!B0]   BNOP    .S1     $C$L56,5          ; |653| 
           ; BRANCHCC OCCURS {$C$L56}        ; |653| 
;** --------------------------------------------------------------------------*
	.dwpsn	file "test_c.cpp",line 655,column 1,is_stmt
;----------------------------------------------------------------------
; 655 | sleep_m(500);//1500                                                    
;----------------------------------------------------------------------
$C$DW$407	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$407, DW_AT_low_pc(0x00)
	.dwattr $C$DW$407, DW_AT_name("_Send_Recive_Packet__FUiPvT2T1")
	.dwattr $C$DW$407, DW_AT_TI_call
           CALL    .S1     _Send_Recive_Packet__FUiPvT2T1 ; |655| 
           LDW     .D2T1   *+SP(440),A4      ; |655| 
           ADDAD   .D2     SP,29,B5          ; |655| 
           MVK     .S2     0x8c,B6           ; |655| 
           MV      .L1X    B5,A6             ; |655| 

           ADDKPC  .S2     $C$RL45,B3,0      ; |655| 
||         ADD     .D2     SP,24,B4          ; |655| 

$C$RL45:   ; CALL OCCURS {_Send_Recive_Packet__FUiPvT2T1} {0}  ; |655| 
           STW     .D2T1   A4,*+SP(8)        ; |655| 
	.dwpsn	file "test_c.cpp",line 656,column 2,is_stmt
$C$DW$408	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$408, DW_AT_low_pc(0x00)
	.dwattr $C$DW$408, DW_AT_name("_memcmp")
	.dwattr $C$DW$408, DW_AT_TI_call
           CALL    .S1     _memcmp           ; |656| 
           ADD     .D2     SP,24,B4          ; |656| 
           ADDKPC  .S2     $C$RL46,B3,2      ; |656| 

           MVK     .S1     0x8c,A6           ; |656| 
||         MV      .L1X    B4,A4             ; |656| 
||         ADDAD   .D2     SP,29,B4          ; |656| 

$C$RL46:   ; CALL OCCURS {_memcmp} {0}       ; |656| 
           LDW     .D2T2   *+SP(8),B4        ; |656| 
           NOP             4
           CMPEQ   .L2     B4,1,B4           ; |656| 
           NOP             1
           OR      .L1X    A4,B4,A0          ; |656| 
   [!A0]   BNOP    .S1     $C$L55,5          ; |656| 
           ; BRANCHCC OCCURS {$C$L55}        ; |656| 
;** --------------------------------------------------------------------------*
	.dwpsn	file "test_c.cpp",line 657,column 3,is_stmt
;----------------------------------------------------------------------
; 657 | error = drv_ioctl(FileNet, NET_LINK, &link);                           
; 658 | if(error != OSE_OK)                                                    
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(4),B4        ; |657| 
           NOP             4
           SET     .S2     B4,5,5,B4         ; |657| 
           STW     .D2T2   B4,*+SP(4)        ; |657| 
;** --------------------------------------------------------------------------*
$C$L55:    
	.dwpsn	file "test_c.cpp",line 659,column 1,is_stmt
$C$DW$409	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$409, DW_AT_low_pc(0x00)
	.dwattr $C$DW$409, DW_AT_name("_Send_Recive_Packet__FUiPvT2T1")
	.dwattr $C$DW$409, DW_AT_TI_call
           CALL    .S1     _Send_Recive_Packet__FUiPvT2T1 ; |659| 
           LDW     .D2T1   *+SP(440),A4      ; |659| 
           MVK     .S2     376,B4            ; |659| 
           ADD     .L2     B4,SP,B5          ; |659| 
           MVK     .S2     0x40,B6           ; |659| 

           MV      .L1X    B5,A6             ; |659| 
||         ADDAD   .D2     SP,21,B4          ; |659| 
||         ADDKPC  .S2     $C$RL47,B3,0      ; |659| 

$C$RL47:   ; CALL OCCURS {_Send_Recive_Packet__FUiPvT2T1} {0}  ; |659| 
           STW     .D2T1   A4,*+SP(8)        ; |659| 
	.dwpsn	file "test_c.cpp",line 660,column 2,is_stmt
;----------------------------------------------------------------------
; 660 | res = TPO_ERR;                                                         
;----------------------------------------------------------------------
$C$DW$410	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$410, DW_AT_low_pc(0x00)
	.dwattr $C$DW$410, DW_AT_name("_memcmp")
	.dwattr $C$DW$410, DW_AT_TI_call
           CALL    .S1     _memcmp           ; |660| 
           MVK     .S1     376,A3            ; |660| 
           ADDAD   .D2     SP,21,B4          ; |660| 
           ADDKPC  .S2     $C$RL48,B3,1      ; |660| 

           MVK     .S1     0x40,A6           ; |660| 
||         MV      .L1X    B4,A4             ; |660| 
||         ADD     .L2X    A3,SP,B4          ; |660| 

$C$RL48:   ; CALL OCCURS {_memcmp} {0}       ; |660| 
           LDW     .D2T2   *+SP(8),B4        ; |660| 
           NOP             4
           CMPEQ   .L2     B4,1,B4           ; |660| 
           NOP             1
           OR      .L1X    A4,B4,A0          ; |660| 
   [!A0]   BNOP    .S1     $C$L57,5          ; |660| 
           ; BRANCHCC OCCURS {$C$L57}        ; |660| 
;** --------------------------------------------------------------------------*
	.dwpsn	file "test_c.cpp",line 661,column 3,is_stmt
;----------------------------------------------------------------------
; 661 | goto end_tst_sk;                                                       
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(4),B4        ; |661| 
           NOP             4
           SET     .S2     B4,5,5,B4         ; |661| 
           STW     .D2T2   B4,*+SP(4)        ; |661| 
	.dwpsn	file "test_c.cpp",line 662,column 1,is_stmt
           BNOP    .S1     $C$L57,5          ; |662| 
           ; BRANCH OCCURS {$C$L57}          ; |662| 
;** --------------------------------------------------------------------------*
$C$L56:    
	.dwpsn	file "test_c.cpp",line 664,column 1,is_stmt
;----------------------------------------------------------------------
; 664 | if(link)                                                               
; 666 | error = Send_Recive_Packet(FileNet, buf_big_wr, buf_big_rd, LEN_BUF1_FO
;     | R_TEST_SK);                                                            
; 667 | if((error == TPO_ERR) | (memcmp(buf_big_wr, buf_big_rd, LEN_BUF1_FOR_TE
;     | ST_SK)))                                                               
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(4),B4        ; |664| 
           NOP             4
           SET     .S2     B4,5,5,B4         ; |664| 
           STW     .D2T2   B4,*+SP(4)        ; |664| 
;** --------------------------------------------------------------------------*
$C$L57:    
	.dwpsn	file "test_c.cpp",line 668,column 1,is_stmt
;----------------------------------------------------------------------
; 668 | res|=ERR_LOOP_PHY;                                                     
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+296,A3
           MVKH    .S1     ___syscall_tab+296,A3
           LDW     .D1T1   *A3,A3            ; |668| 
           LDW     .D2T1   *+SP(440),A4      ; |668| 
           NOP             3
$C$DW$411	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$411, DW_AT_low_pc(0x00)
	.dwattr $C$DW$411, DW_AT_TI_call
	.dwattr $C$DW$411, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |668| 
           ADDKPC  .S2     $C$RL49,B3,4      ; |668| 
$C$RL49:   ; CALL OCCURS {A3} {0}            ; |668| 
	.dwpsn	file "test_c.cpp",line 670,column 1,is_stmt
;----------------------------------------------------------------------
; 670 | error = Send_Recive_Packet(FileNet, buf_small_wr, buf_small_rd, LEN_BUF
;     | 2_FOR_TEST_SK);                                                        
;----------------------------------------------------------------------
           LDW     .D2T1   *+SP(4),A4        ; |670| 
;** --------------------------------------------------------------------------*
$C$L58:    
	.dwpsn	file "test_c.cpp",line 671,column 1,is_stmt
;----------------------------------------------------------------------
; 671 | if((error == TPO_ERR) | (memcmp(buf_small_wr, buf_small_rd, LEN_BUF2_FO
;     | R_TEST_SK)))                                                           
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(456),B3      ; |671| 
           NOP             4
	.dwcfi	restore_reg, 19
           ADDK    .S2     456,SP            ; |671| 
	.dwcfi	cfa_offset, 0
	.dwcfi	cfa_offset, 0
$C$DW$412	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$412, DW_AT_low_pc(0x00)
	.dwattr $C$DW$412, DW_AT_TI_return
           RETNOP  .S2     B3,5              ; |671| 
           ; BRANCH OCCURS {B3}              ; |671| 
	.dwattr $C$DW$375, DW_AT_TI_end_file("test_c.cpp")
	.dwattr $C$DW$375, DW_AT_TI_end_line(0x29f)
	.dwattr $C$DW$375, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$375

	.sect	".text"
	.clink
	.global	_Start_Test_N__FP12kdg_rez_test

$C$DW$413	.dwtag  DW_TAG_subprogram, DW_AT_name("Start_Test_N")
	.dwattr $C$DW$413, DW_AT_low_pc(_Start_Test_N__FP12kdg_rez_test)
	.dwattr $C$DW$413, DW_AT_high_pc(0x00)
	.dwattr $C$DW$413, DW_AT_TI_symbol_name("_Start_Test_N__FP12kdg_rez_test")
	.dwattr $C$DW$413, DW_AT_external
	.dwattr $C$DW$413, DW_AT_TI_begin_file("test_c.cpp")
	.dwattr $C$DW$413, DW_AT_TI_begin_line(0x2a3)
	.dwattr $C$DW$413, DW_AT_TI_begin_column(0x06)
	.dwpsn	file "test_c.cpp",line 676,column 1,is_stmt,address _Start_Test_N__FP12kdg_rez_test

	.dwfde $C$DW$CIE, _Start_Test_N__FP12kdg_rez_test
$C$DW$414	.dwtag  DW_TAG_formal_parameter, DW_AT_name("result")
	.dwattr $C$DW$414, DW_AT_TI_symbol_name("_result")
	.dwattr $C$DW$414, DW_AT_type(*$C$DW$T$696)
	.dwattr $C$DW$414, DW_AT_location[DW_OP_reg4]
;----------------------------------------------------------------------
; 675 | res|=ERR_LOOP_PHY;                                                     
;----------------------------------------------------------------------

;******************************************************************************
;* FUNCTION NAME: Start_Test_N(kdg_rez_test *)                                *
;*                                                                            *
;*   Regs Modified     : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP,A16,A17,A18,A19,A20,A21,A22,A23,A24, *
;*                           A25,A26,A27,A28,A29,A30,A31,B16,B17,B18,B19,B20, *
;*                           B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31      *
;*   Regs Used         : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP,A16,A17,A18,A19,A20,A21,A22,A23,A24, *
;*                           A25,A26,A27,A28,A29,A30,A31,B16,B17,B18,B19,B20, *
;*                           B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31      *
;*   Local Frame Size  : 0 Args + 4 Auto + 4 Save = 8 byte                    *
;******************************************************************************
_Start_Test_N__FP12kdg_rez_test:
;** --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
	.dwcfi	save_reg_to_reg, 228, 19
           STW     .D2T2   B3,*SP--(8)       ; |676| 
	.dwcfi	cfa_offset, 8
	.dwcfi	save_reg_to_mem, 19, 0
$C$DW$415	.dwtag  DW_TAG_variable, DW_AT_name("result")
	.dwattr $C$DW$415, DW_AT_TI_symbol_name("_result")
	.dwattr $C$DW$415, DW_AT_type(*$C$DW$T$696)
	.dwattr $C$DW$415, DW_AT_location[DW_OP_breg31 4]
;----------------------------------------------------------------------
; 677 | end_tst_sk:                                                            
; 679 | drv_rmd(FileNet);                                                      
;----------------------------------------------------------------------
           STW     .D2T1   A4,*+SP(4)        ; |676| 
	.dwpsn	file "test_c.cpp",line 680,column 5,is_stmt
;----------------------------------------------------------------------
; 681 | return res;                                                            
;----------------------------------------------------------------------
           BNOP    .S1     $C$L65,5          ; |680| 
           ; BRANCH OCCURS {$C$L65}          ; |680| 
;** --------------------------------------------------------------------------*
;** --------------------------------------------------------------------------*
$C$L59:    
	.dwpsn	file "test_c.cpp",line 684,column 3,is_stmt
;----------------------------------------------------------------------
; 685 | //---------------------------------------------------------------------
;     | -------                                                                
;----------------------------------------------------------------------
$C$DW$416	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$416, DW_AT_low_pc(0x00)
	.dwattr $C$DW$416, DW_AT_name("_TestCelostnost__Fv")
	.dwattr $C$DW$416, DW_AT_TI_call
           CALL    .S1     _TestCelostnost__Fv ; |684| 
           ADDKPC  .S2     $C$RL50,B3,4      ; |684| 
$C$RL50:   ; CALL OCCURS {_TestCelostnost__Fv} {0}  ; |684| 
           LDW     .D2T2   *+SP(4),B4        ; |684| 
           NOP             4
           STW     .D2T1   A4,*+B4(8)        ; |684| 
	.dwpsn	file "test_c.cpp",line 686,column 12,is_stmt
;----------------------------------------------------------------------
; 686 | void Start_Test_N(kdg_rez_test* result)                                
;----------------------------------------------------------------------
           BNOP    .S1     $C$L66,5          ; |686| 
           ; BRANCH OCCURS {$C$L66}          ; |686| 
;** --------------------------------------------------------------------------*
$C$L60:    
	.dwpsn	file "test_c.cpp",line 690,column 3,is_stmt
;----------------------------------------------------------------------
; 691 | switch (result->n_test)                                                
;----------------------------------------------------------------------
$C$DW$417	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$417, DW_AT_low_pc(0x00)
	.dwattr $C$DW$417, DW_AT_name("_TestDozu__FP12kdg_rez_test")
	.dwattr $C$DW$417, DW_AT_TI_call
           CALL    .S1     _TestDozu__FP12kdg_rez_test ; |690| 
           ADDKPC  .S2     $C$RL51,B3,4      ; |690| 
$C$RL51:   ; CALL OCCURS {_TestDozu__FP12kdg_rez_test} {0}  ; |690| 
           LDW     .D2T2   *+SP(4),B4        ; |690| 
           NOP             4
           STW     .D2T1   A4,*+B4(8)        ; |690| 
	.dwpsn	file "test_c.cpp",line 692,column 12,is_stmt
;----------------------------------------------------------------------
; 693 | case CELOSTN:                                                          
; 695 |           result->rez = TestCelostnost();                              
;----------------------------------------------------------------------
           BNOP    .S1     $C$L66,5          ; |692| 
           ; BRANCH OCCURS {$C$L66}          ; |692| 
;** --------------------------------------------------------------------------*
$C$L61:    
	.dwpsn	file "test_c.cpp",line 696,column 3,is_stmt
;----------------------------------------------------------------------
; 697 | break;                                                                 
;----------------------------------------------------------------------
$C$DW$418	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$418, DW_AT_low_pc(0x00)
	.dwattr $C$DW$418, DW_AT_name("_TestMove__Fv")
	.dwattr $C$DW$418, DW_AT_TI_call
           CALL    .S1     _TestMove__Fv     ; |696| 
           ADDKPC  .S2     $C$RL52,B3,4      ; |696| 
$C$RL52:   ; CALL OCCURS {_TestMove__Fv} {0}  ; |696| 
           LDW     .D2T2   *+SP(4),B4        ; |696| 
           NOP             4
           STW     .D2T1   A4,*+B4(8)        ; |696| 
	.dwpsn	file "test_c.cpp",line 698,column 12,is_stmt
;----------------------------------------------------------------------
; 699 | case TEST_DOZU:           //управл                                     
; 700 | ет main                                                                
;----------------------------------------------------------------------
           BNOP    .S1     $C$L66,5          ; |698| 
           ; BRANCH OCCURS {$C$L66}          ; |698| 
;** --------------------------------------------------------------------------*
$C$L62:    
	.dwpsn	file "test_c.cpp",line 702,column 3,is_stmt
;----------------------------------------------------------------------
; 702 | result->rez = TestDozu(result);                                        
;----------------------------------------------------------------------
$C$DW$419	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$419, DW_AT_low_pc(0x00)
	.dwattr $C$DW$419, DW_AT_name("_TestMove_ST1__FP12kdg_rez_test")
	.dwattr $C$DW$419, DW_AT_TI_call
           CALL    .S1     _TestMove_ST1__FP12kdg_rez_test ; |702| 
           ADDKPC  .S2     $C$RL53,B3,4      ; |702| 
$C$RL53:   ; CALL OCCURS {_TestMove_ST1__FP12kdg_rez_test} {0}  ; |702| 
           LDW     .D2T2   *+SP(4),B4        ; |702| 
           NOP             4
           STW     .D2T1   A4,*+B4(8)        ; |702| 
	.dwpsn	file "test_c.cpp",line 704,column 12,is_stmt
;----------------------------------------------------------------------
; 704 | break;                                                                 
; 706 | case TEST_MOVE:           //управл                                     
; 707 | ет main                                                                
;----------------------------------------------------------------------
           BNOP    .S1     $C$L66,5          ; |704| 
           ; BRANCH OCCURS {$C$L66}          ; |704| 
;** --------------------------------------------------------------------------*
$C$L63:    
	.dwpsn	file "test_c.cpp",line 708,column 3,is_stmt
;----------------------------------------------------------------------
; 709 | result->rez = TestMove();                                              
;----------------------------------------------------------------------
$C$DW$420	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$420, DW_AT_low_pc(0x00)
	.dwattr $C$DW$420, DW_AT_name("_Test_SK__Fv")
	.dwattr $C$DW$420, DW_AT_TI_call
           CALL    .S1     _Test_SK__Fv      ; |708| 
           ADDKPC  .S2     $C$RL54,B3,4      ; |708| 
$C$RL54:   ; CALL OCCURS {_Test_SK__Fv} {0}  ; |708| 
           LDW     .D2T2   *+SP(4),B4        ; |708| 
           NOP             4
           STW     .D2T1   A4,*+B4(8)        ; |708| 
	.dwpsn	file "test_c.cpp",line 710,column 12,is_stmt
;----------------------------------------------------------------------
; 711 | break;                                                                 
; 713 | case TEST_MOVE_ST1:       //управл                                     
;----------------------------------------------------------------------
           BNOP    .S1     $C$L66,5          ; |710| 
           ; BRANCH OCCURS {$C$L66}          ; |710| 
;** --------------------------------------------------------------------------*
$C$L64:    
	.dwpsn	file "test_c.cpp",line 714,column 7,is_stmt
;----------------------------------------------------------------------
; 714 | ет main                                                                
; 716 | result->rez = TestMove_ST1(result);                                    
;----------------------------------------------------------------------

           MV      .L2X    A4,B4
||         MVK     .S2     1,B5              ; |714| 

           STW     .D2T2   B5,*+B4(8)        ; |714| 
	.dwpsn	file "test_c.cpp",line 717,column 7,is_stmt
;----------------------------------------------------------------------
; 718 | break;                                                                 
; 720 | case TEST_SK:                                                          
;----------------------------------------------------------------------
           BNOP    .S1     $C$L66,5          ; |717| 
           ; BRANCH OCCURS {$C$L66}          ; |717| 
;** --------------------------------------------------------------------------*
$C$L65:    
	.dwpsn	file "test_c.cpp",line 680,column 5,is_stmt
           MV      .L2X    A4,B4
           LDW     .D2T2   *+B4(4),B4        ; |680| 
           MVK     .S1     21,A3             ; |680| 
           MVK     .S2     32,B5             ; |680| 
           NOP             2
           CMPEQ   .L1X    B4,A3,A0          ; |680| 
   [ A0]   BNOP    .S1     $C$L59,3          ; |680| 
           SUB     .L2     B4,B5,B5          ; |680| 
           CMPGTU  .L2     B5,8,B0           ; |680| 
           ; BRANCHCC OCCURS {$C$L59}        ; |680| 
;** --------------------------------------------------------------------------*
   [ B0]   BNOP    .S1     $C$L64,5          ; |680| 
           ; BRANCHCC OCCURS {$C$L64} {-5}   ; |680| 
;** --------------------------------------------------------------------------*
           SHL     .S2     B4,2,B4           ; |680| 

           ADDK    .S2     -128,B4           ; |680| 
||         MVKL    .S1     $C$SW1,A3

           MVKH    .S1     $C$SW1,A3
           ADD     .L1X    A3,B4,A3          ; |680| 
           LDW     .D1T1   *A3,A3            ; |680| 
           NOP             4
           BNOP    .S2X    A3,5              ; |680| 
           ; BRANCH OCCURS {A3}              ; |680| 
	.sect	".switch"
	.clink
$C$SW1:	.word	$C$L60	; 32
	.word	$C$L64	; 0
	.word	$C$L64	; 0
	.word	$C$L64	; 0
	.word	$C$L61	; 36
	.word	$C$L62	; 37
	.word	$C$L64	; 0
	.word	$C$L64	; 0
	.word	$C$L63	; 40
	.sect	".text"
;** --------------------------------------------------------------------------*
;** --------------------------------------------------------------------------*
$C$L66:    
	.dwpsn	file "test_c.cpp",line 721,column 1,is_stmt
           LDW     .D2T2   *++SP(8),B3       ; |721| 
           NOP             4
	.dwcfi	cfa_offset, 0
	.dwcfi	restore_reg, 19
	.dwcfi	cfa_offset, 0
$C$DW$421	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$421, DW_AT_low_pc(0x00)
	.dwattr $C$DW$421, DW_AT_TI_return
           RETNOP  .S2     B3,5              ; |721| 
           ; BRANCH OCCURS {B3}              ; |721| 
	.dwattr $C$DW$413, DW_AT_TI_end_file("test_c.cpp")
	.dwattr $C$DW$413, DW_AT_TI_end_line(0x2d1)
	.dwattr $C$DW$413, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$413

	.sect	".text"
	.clink
	.global	_TestDOZU_Nagr__FPv

$C$DW$422	.dwtag  DW_TAG_subprogram, DW_AT_name("TestDOZU_Nagr")
	.dwattr $C$DW$422, DW_AT_low_pc(_TestDOZU_Nagr__FPv)
	.dwattr $C$DW$422, DW_AT_high_pc(0x00)
	.dwattr $C$DW$422, DW_AT_TI_symbol_name("_TestDOZU_Nagr__FPv")
	.dwattr $C$DW$422, DW_AT_external
	.dwattr $C$DW$422, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$422, DW_AT_TI_begin_file("test_c.cpp")
	.dwattr $C$DW$422, DW_AT_TI_begin_line(0x2d5)
	.dwattr $C$DW$422, DW_AT_TI_begin_column(0x05)
	.dwpsn	file "test_c.cpp",line 726,column 1,is_stmt,address _TestDOZU_Nagr__FPv

	.dwfde $C$DW$CIE, _TestDOZU_Nagr__FPv
$C$DW$423	.dwtag  DW_TAG_formal_parameter, DW_AT_name("arg")
	.dwattr $C$DW$423, DW_AT_TI_symbol_name("_arg")
	.dwattr $C$DW$423, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$423, DW_AT_location[DW_OP_reg4]

;******************************************************************************
;* FUNCTION NAME: TestDOZU_Nagr(void *)                                       *
;*                                                                            *
;*   Regs Modified     : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,B10,B11,SP,A16,A17,A18,A19,A20,A21,A22, *
;*                           A23,A24,A25,A26,A27,A28,A29,A30,A31,B16,B17,B18, *
;*                           B19,B20,B21,B22,B23,B24,B25,B26,B27,B28,B29,B30, *
;*                           B31                                              *
;*   Regs Used         : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,B10,B11,SP,A16,A17,A18,A19,A20,A21,A22, *
;*                           A23,A24,A25,A26,A27,A28,A29,A30,A31,B16,B17,B18, *
;*                           B19,B20,B21,B22,B23,B24,B25,B26,B27,B28,B29,B30, *
;*                           B31                                              *
;*   Local Frame Size  : 0 Args + 1556 Auto + 12 Save = 1568 byte             *
;******************************************************************************
_TestDOZU_Nagr__FPv:
;** --------------------------------------------------------------------------*
;----------------------------------------------------------------------
; 726 | default:                                                               
;----------------------------------------------------------------------
	.dwcfi	cfa_offset, 0
	.dwcfi	save_reg_to_reg, 228, 19
           ADDK    .S2     -1568,SP          ; |726| 
	.dwcfi	cfa_offset, 1568
           STW     .D2T2   B11,*+SP(1568)    ; |726| 
	.dwcfi	save_reg_to_mem, 27, 0
           STW     .D2T2   B10,*+SP(1564)    ; |726| 
	.dwcfi	save_reg_to_mem, 26, -4
           STW     .D2T2   B3,*+SP(1560)     ; |726| 
	.dwcfi	save_reg_to_mem, 19, -8
$C$DW$424	.dwtag  DW_TAG_variable, DW_AT_name("arg")
	.dwattr $C$DW$424, DW_AT_TI_symbol_name("_arg")
	.dwattr $C$DW$424, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$424, DW_AT_location[DW_OP_breg31 4]
$C$DW$425	.dwtag  DW_TAG_variable, DW_AT_name("error0")
	.dwattr $C$DW$425, DW_AT_TI_symbol_name("_error0")
	.dwattr $C$DW$425, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$425, DW_AT_location[DW_OP_breg31 8]
$C$DW$426	.dwtag  DW_TAG_variable, DW_AT_name("error1")
	.dwattr $C$DW$426, DW_AT_TI_symbol_name("_error1")
	.dwattr $C$DW$426, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$426, DW_AT_location[DW_OP_breg31 12]
$C$DW$427	.dwtag  DW_TAG_variable, DW_AT_name("buf0")
	.dwattr $C$DW$427, DW_AT_TI_symbol_name("_buf0")
	.dwattr $C$DW$427, DW_AT_type(*$C$DW$T$742)
	.dwattr $C$DW$427, DW_AT_location[DW_OP_breg31 16]
$C$DW$428	.dwtag  DW_TAG_variable, DW_AT_name("buf1")
	.dwattr $C$DW$428, DW_AT_TI_symbol_name("_buf1")
	.dwattr $C$DW$428, DW_AT_type(*$C$DW$T$742)
	.dwattr $C$DW$428, DW_AT_location[DW_OP_breg31 784]
$C$DW$429	.dwtag  DW_TAG_variable, DW_AT_name("X")
	.dwattr $C$DW$429, DW_AT_TI_symbol_name("_X")
	.dwattr $C$DW$429, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$429, DW_AT_location[DW_OP_breg31 1552]
$C$DW$430	.dwtag  DW_TAG_label, DW_AT_name("end_dozu_nagr"), DW_AT_low_pc($C$L77)
	.dwattr $C$DW$430, DW_AT_TI_symbol_name("_end_dozu_nagr")
;----------------------------------------------------------------------
; 728 | result->rez = TPO_ERR;                                                 
;----------------------------------------------------------------------
           STW     .D2T1   A4,*+SP(4)        ; |726| 
	.dwpsn	file "test_c.cpp",line 729,column 5,is_stmt
;----------------------------------------------------------------------
; 729 | //       cdg_error.ask = TPO_ERR;                                      
;----------------------------------------------------------------------
           ZERO    .L2     B4                ; |729| 
           STW     .D2T2   B4,*+SP(8)        ; |729| 
	.dwpsn	file "test_c.cpp",line 730,column 5,is_stmt
;----------------------------------------------------------------------
; 730 | //       msg_send(msg_desc->from, &cdg_error, sizeof(kdg_cmd_ask));    
; 731 | };                                                                     
; 734 | return;                                                                
;----------------------------------------------------------------------
           ZERO    .L1     A3                ; |730| 
           STW     .D2T1   A3,*+SP(12)       ; |730| 
	.dwpsn	file "test_c.cpp",line 735,column 8,is_stmt
           STW     .D2T2   B4,*+SP(1552)     ; |735| 
	.dwpsn	file "test_c.cpp",line 737,column 1,is_stmt
;----------------------------------------------------------------------
; 738 | //процесс - тест тока дл                                               
;----------------------------------------------------------------------
           MVKL    .S1     _sh_mem_write,A3
$C$DW$431	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$431, DW_AT_low_pc(0x04)
	.dwattr $C$DW$431, DW_AT_name("_memset")
	.dwattr $C$DW$431, DW_AT_TI_call

           MVKH    .S1     _sh_mem_write,A3
||         CALL    .S2     _memset           ; |737| 

           LDW     .D1T1   *A3,A4            ; |737| 
           ADDKPC  .S2     $C$RL55,B3,2      ; |737| 
           MVK     .S1     0x300,A6          ; |737| 
$C$RL55:   ; CALL OCCURS {_memset} {0}       ; |737| 
	.dwpsn	file "test_c.cpp",line 739,column 1,is_stmt
;----------------------------------------------------------------------
; 739 | 5ки                                                                    
;----------------------------------------------------------------------
           MVKL    .S2     0x5a5a5a5a,B4
           MVKH    .S2     0x5a5a5a5a,B4
           STW     .D2T2   B4,*+SP(16)       ; |739| 
	.dwpsn	file "test_c.cpp",line 740,column 1,is_stmt
;----------------------------------------------------------------------
; 740 | int TestDOZU_Nagr(void* arg)                                           
;----------------------------------------------------------------------
$C$DW$432	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$432, DW_AT_low_pc(0x00)
	.dwattr $C$DW$432, DW_AT_name("_WriteDARAM__FUsPvT1")
	.dwattr $C$DW$432, DW_AT_TI_call
           CALL    .S1     _WriteDARAM__FUsPvT1 ; |740| 
           ADDKPC  .S2     $C$RL56,B3,3      ; |740| 

           ADD     .D2     SP,16,B4          ; |740| 
||         ZERO    .L1     A4                ; |740| 
||         MVK     .S1     0x4,A6            ; |740| 

$C$RL56:   ; CALL OCCURS {_WriteDARAM__FUsPvT1} {0}  ; |740| 
	.dwpsn	file "test_c.cpp",line 742,column 1,is_stmt
;----------------------------------------------------------------------
; 742 | #define L 0x300/4                                                      
;----------------------------------------------------------------------
           ZERO    .L1     A3                ; |742| 
           STW     .D2T1   A3,*+SP(16)       ; |742| 
	.dwpsn	file "test_c.cpp",line 743,column 1,is_stmt
;----------------------------------------------------------------------
; 744 | int error0=0;                                                          
; 745 | int error1=0;                                                          
;----------------------------------------------------------------------
           MVKL    .S2     0x5a5a5a5a,B10

           ZERO    .L2     B4                ; |743| 
||         MVK     .S2     784,B11           ; |747| 

           STW     .D2T2   B4,*+SP(784)      ; |743| 
||         MVKH    .S2     0x5a5a5a5a,B10

;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
$C$L67:    
$C$DW$L$_TestDOZU_Nagr__FPv$2$B:
	.dwpsn	file "test_c.cpp",line 746,column 1,is_stmt
$C$DW$433	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$433, DW_AT_low_pc(0x00)
	.dwattr $C$DW$433, DW_AT_name("_ReadDARAM0__FUsPvT1")
	.dwattr $C$DW$433, DW_AT_TI_call
           CALL    .S1     _ReadDARAM0__FUsPvT1 ; |746| 
           ADDKPC  .S2     $C$RL57,B3,3      ; |746| 

           ZERO    .L1     A4                ; |746| 
||         ADD     .D2     SP,16,B4          ; |746| 
||         MVK     .S1     0x4,A6            ; |746| 

$C$RL57:   ; CALL OCCURS {_ReadDARAM0__FUsPvT1} {0}  ; |746| 
	.dwpsn	file "test_c.cpp",line 747,column 1,is_stmt
;----------------------------------------------------------------------
; 747 | uint32 buf0[L];                                                        
;----------------------------------------------------------------------
$C$DW$434	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$434, DW_AT_low_pc(0x00)
	.dwattr $C$DW$434, DW_AT_name("_ReadDARAM1__FUsPvT1")
	.dwattr $C$DW$434, DW_AT_TI_call
           CALL    .S1     _ReadDARAM1__FUsPvT1 ; |747| 
           ADDKPC  .S2     $C$RL58,B3,3      ; |747| 

           ZERO    .L1     A4                ; |747| 
||         ADD     .L2     B11,SP,B4         ; |747| 
||         MVK     .S1     0x4,A6            ; |747| 

$C$RL58:   ; CALL OCCURS {_ReadDARAM1__FUsPvT1} {0}  ; |747| 
	.dwpsn	file "test_c.cpp",line 748,column 1,is_stmt
;----------------------------------------------------------------------
; 748 | uint32 buf1[L];                                                        
; 750 | uint32 X=0;                                                            
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(784),B4      ; |748| 
           LDW     .D2T1   *+SP(16),A3       ; |748| 
           NOP             3
           CMPEQ   .L2     B4,B10,B5         ; |748| 
           CMPEQ   .L2X    A3,B10,B4         ; |748| 
           AND     .L2     B4,B5,B0
   [!B0]   BNOP    .S1     $C$L67,5          ; |748| 
           ; BRANCHCC OCCURS {$C$L67}        ; |748| 
$C$DW$L$_TestDOZU_Nagr__FPv$2$E:
;** --------------------------------------------------------------------------*
	.dwpsn	file "test_c.cpp",line 752,column 1,is_stmt
;----------------------------------------------------------------------
; 752 | memset(sh_mem_write,0,L*4);                                            
;----------------------------------------------------------------------
           MVKL    .S1     _Start_dozu_nagr,A3
           MVKH    .S1     _Start_dozu_nagr,A3
           LDHU    .D1T1   *A3,A0            ; |752| 
           NOP             4
   [!A0]   BNOP    .S1     $C$L77,5          ; |752| 
           ; BRANCHCC OCCURS {$C$L77}        ; |752| 
;** --------------------------------------------------------------------------*
;**   BEGIN LOOP $C$L68
;** --------------------------------------------------------------------------*
$C$L68:    
$C$DW$L$_TestDOZU_Nagr__FPv$4$B:
	.dwpsn	file "test_c.cpp",line 754,column 3,is_stmt
;----------------------------------------------------------------------
; 754 | buf0[0] = 0x5a5a5a5a;                                                  
; 755 | WriteDARAM(0,buf0,4);                                                  
;----------------------------------------------------------------------
$C$DW$435	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$435, DW_AT_low_pc(0x00)
	.dwattr $C$DW$435, DW_AT_name("_memset")
	.dwattr $C$DW$435, DW_AT_TI_call
           CALL    .S1     _memset           ; |754| 
           ADD     .D2     SP,16,B4          ; |754| 
           ADDKPC  .S2     $C$RL59,B3,2      ; |754| 

           MVK     .S1     0x300,A6          ; |754| 
||         MV      .L1X    B4,A4             ; |754| 
||         ZERO    .L2     B4                ; |754| 

$C$RL59:   ; CALL OCCURS {_memset} {0}       ; |754| 
	.dwpsn	file "test_c.cpp",line 756,column 3,is_stmt
;----------------------------------------------------------------------
; 757 | buf0[0] = 0;                                                           
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(1552),B4     ; |756| 
           NOP             4
           STW     .D2T2   B4,*+SP(20)       ; |756| 

$C$DW$436	.dwtag  DW_TAG_lexical_block, DW_AT_low_pc(0x00), DW_AT_high_pc(0x00)
$C$DW$437	.dwtag  DW_TAG_variable, DW_AT_name("i")
	.dwattr $C$DW$437, DW_AT_TI_symbol_name("_i")
	.dwattr $C$DW$437, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$437, DW_AT_location[DW_OP_breg31 1556]
	.dwpsn	file "test_c.cpp",line 758,column 12,is_stmt
;----------------------------------------------------------------------
; 758 | buf1[0] = 0;                                                           
;----------------------------------------------------------------------
           MVK     .L1     2,A3              ; |758| 
           STW     .D2T1   A3,*+SP(1556)     ; |758| 
	.dwpsn	file "test_c.cpp",line 758,column 16,is_stmt
;----------------------------------------------------------------------
; 759 | do                                                                     
;----------------------------------------------------------------------
           MVK     .S2     192,B5            ; |758| 
           CMPLT   .L2X    A3,B5,B0          ; |758| 
   [!B0]   BNOP    .S1     $C$L70,4          ; |758| 
           MV      .L2X    A3,B4
           ; BRANCHCC OCCURS {$C$L70}        ; |758| 
$C$DW$L$_TestDOZU_Nagr__FPv$4$E:
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
$C$L69:    
$C$DW$L$_TestDOZU_Nagr__FPv$5$B:
	.dwpsn	file "test_c.cpp",line 760,column 4,is_stmt
;----------------------------------------------------------------------
; 761 | ReadDARAM0(0,buf0,4);                                                  
; 762 | ReadDARAM1(0,buf1,4);                                                  
;----------------------------------------------------------------------
           SUB     .L2     B4,1,B4           ; |760| 
           ADDAW   .D2     SP,B4,B4          ; |760| 
           LDW     .D2T2   *+B4(16),B4       ; |760| 
           MVKL    .S2     0x66467329,B5
           MVKH    .S2     0x66467329,B5
           LDW     .D2T2   *+SP(1556),B6     ; |760| 
           MVKL    .S1     0xa6549873,A3
           MPYLH   .M2     B5,B4,B8          ; |760| 
           MPYLH   .M2     B4,B5,B7          ; |760| 
           MPYU    .M2     B5,B4,B5          ; |760| 
           ADD     .L2     B8,B7,B4          ; |760| 

           SHL     .S2     B4,16,B4          ; |760| 
||         MVKH    .S1     0xa6549873,A3

           ADD     .L2     B5,B4,B4          ; |760| 

           ADD     .L2X    A3,B4,B4          ; |760| 
||         ADDAW   .D2     SP,B6,B31         ; |760| 

           STW     .D2T2   B4,*+B31(16)      ; |760| 
	.dwpsn	file "test_c.cpp",line 758,column 20,is_stmt
           LDW     .D2T2   *+SP(1556),B4     ; |758| 
           NOP             4
           ADD     .L2     1,B4,B4           ; |758| 
           STW     .D2T2   B4,*+SP(1556)     ; |758| 
	.dwpsn	file "test_c.cpp",line 758,column 16,is_stmt
           MVK     .S2     192,B5            ; |758| 
           CMPLT   .L2     B4,B5,B0          ; |758| 
   [ B0]   BNOP    .S1     $C$L69,5          ; |758| 
           ; BRANCHCC OCCURS {$C$L69}        ; |758| 
$C$DW$L$_TestDOZU_Nagr__FPv$5$E:
;** --------------------------------------------------------------------------*
$C$L70:    
$C$DW$L$_TestDOZU_Nagr__FPv$6$B:
	.dwendtag $C$DW$436

	.dwpsn	file "test_c.cpp",line 763,column 3,is_stmt
$C$DW$438	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$438, DW_AT_low_pc(0x00)
	.dwattr $C$DW$438, DW_AT_name("_WriteDARAM__FUsPvT1")
	.dwattr $C$DW$438, DW_AT_TI_call
           CALL    .S1     _WriteDARAM__FUsPvT1 ; |763| 
           ADDKPC  .S2     $C$RL60,B3,3      ; |763| 

           ADD     .D2     SP,16,B4          ; |763| 
||         MVK     .L1     0x4,A4            ; |763| 
||         MVK     .S1     0x300,A6          ; |763| 

$C$RL60:   ; CALL OCCURS {_WriteDARAM__FUsPvT1} {0}  ; |763| 
	.dwpsn	file "test_c.cpp",line 764,column 3,is_stmt
;----------------------------------------------------------------------
; 764 | while((buf0[0] != 0x5a5a5a5a) | (buf1[0] != 0x5a5a5a5a));              
;----------------------------------------------------------------------
           MVK     .L2     1,B4              ; |764| 
           STW     .D2T2   B4,*+SP(16)       ; |764| 
	.dwpsn	file "test_c.cpp",line 765,column 3,is_stmt
;----------------------------------------------------------------------
; 767 | while(Start_dozu_nagr)                                                 
; 769 | memset(buf0,0,sizeof(buf0));                                           
;----------------------------------------------------------------------
$C$DW$439	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$439, DW_AT_low_pc(0x00)
	.dwattr $C$DW$439, DW_AT_name("_WriteDARAM__FUsPvT1")
	.dwattr $C$DW$439, DW_AT_TI_call
           CALL    .S1     _WriteDARAM__FUsPvT1 ; |765| 
           ADDKPC  .S2     $C$RL61,B3,3      ; |765| 

           MVK     .L1     0x4,A6            ; |765| 
||         ADD     .D2     SP,16,B4          ; |765| 

$C$RL61:   ; CALL OCCURS {_WriteDARAM__FUsPvT1} {0}  ; |765| 
$C$DW$L$_TestDOZU_Nagr__FPv$6$E:
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
$C$L71:    
$C$DW$L$_TestDOZU_Nagr__FPv$7$B:
	.dwpsn	file "test_c.cpp",line 770,column 3,is_stmt
           MVKL    .S1     _Start_dozu_nagr,A3
           MVKH    .S1     _Start_dozu_nagr,A3
           LDHU    .D1T1   *A3,A0            ; |770| 
           NOP             4
   [!A0]   BNOP    .S1     $C$L77,5          ; |770| 
           ; BRANCHCC OCCURS {$C$L77}        ; |770| 
$C$DW$L$_TestDOZU_Nagr__FPv$7$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_TestDOZU_Nagr__FPv$8$B:
	.dwpsn	file "test_c.cpp",line 771,column 3,is_stmt
;----------------------------------------------------------------------
; 771 | buf0[1]=X;                                                             
;----------------------------------------------------------------------
	.dwpsn	file "test_c.cpp",line 773,column 5,is_stmt
;----------------------------------------------------------------------
; 773 | for (int i=2;i<L;i++)                                                  
;----------------------------------------------------------------------
$C$DW$440	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$440, DW_AT_low_pc(0x00)
	.dwattr $C$DW$440, DW_AT_name("_ReadDARAM0__FUsPvT1")
	.dwattr $C$DW$440, DW_AT_TI_call
           CALL    .S1     _ReadDARAM0__FUsPvT1 ; |773| 
           ADDKPC  .S2     $C$RL62,B3,3      ; |773| 

           MVK     .L1     0x4,A4            ; |773| 
||         ADD     .D2     SP,16,B4          ; |773| 
||         MVK     .S1     0x4,A6            ; |773| 

$C$RL62:   ; CALL OCCURS {_ReadDARAM0__FUsPvT1} {0}  ; |773| 
	.dwpsn	file "test_c.cpp",line 774,column 5,is_stmt
$C$DW$441	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$441, DW_AT_low_pc(0x00)
	.dwattr $C$DW$441, DW_AT_name("_ReadDARAM1__FUsPvT1")
	.dwattr $C$DW$441, DW_AT_TI_call
           CALL    .S1     _ReadDARAM1__FUsPvT1 ; |774| 
           MVK     .S2     784,B4            ; |774| 
           ADDKPC  .S2     $C$RL63,B3,2      ; |774| 

           ADD     .L2     B4,SP,B4          ; |774| 
||         MVK     .L1     0x4,A4            ; |774| 
||         MVK     .S1     0x4,A6            ; |774| 

$C$RL63:   ; CALL OCCURS {_ReadDARAM1__FUsPvT1} {0}  ; |774| 
	.dwpsn	file "test_c.cpp",line 775,column 4,is_stmt
;----------------------------------------------------------------------
; 775 | buf0[i]=buf0[i-1]*0x66467329+0xA6549873;                               
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(16),B4       ; |775| 
           LDW     .D2T2   *+SP(784),B6      ; |775| 
           NOP             3
           CMPEQ   .L2     B4,0,B5           ; |775| 
           CMPEQ   .L2     B6,0,B4           ; |775| 
           OR      .L2     B4,B5,B0          ; |775| 
   [ B0]   BNOP    .S1     $C$L71,5          ; |775| 
           ; BRANCHCC OCCURS {$C$L71}        ; |775| 
$C$DW$L$_TestDOZU_Nagr__FPv$8$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_TestDOZU_Nagr__FPv$9$B:
	.dwpsn	file "test_c.cpp",line 778,column 3,is_stmt
;----------------------------------------------------------------------
; 778 | WriteDARAM(4,buf0,L*4);                                                
;----------------------------------------------------------------------
$C$DW$442	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$442, DW_AT_low_pc(0x00)
	.dwattr $C$DW$442, DW_AT_name("_ReadDARAM0__FUsPvT1")
	.dwattr $C$DW$442, DW_AT_TI_call
           CALL    .S1     _ReadDARAM0__FUsPvT1 ; |778| 
           ADDKPC  .S2     $C$RL64,B3,3      ; |778| 

           MVK     .L1     0x4,A4            ; |778| 
||         ADD     .D2     SP,16,B4          ; |778| 
||         MVK     .S1     0x300,A6          ; |778| 

$C$RL64:   ; CALL OCCURS {_ReadDARAM0__FUsPvT1} {0}  ; |778| 
	.dwpsn	file "test_c.cpp",line 779,column 3,is_stmt
;----------------------------------------------------------------------
; 779 | buf0[0]=1;                                                             
; 780 | WriteDARAM(4,buf0,4);                                                  
;----------------------------------------------------------------------
$C$DW$443	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$443, DW_AT_low_pc(0x00)
	.dwattr $C$DW$443, DW_AT_name("_ReadDARAM1__FUsPvT1")
	.dwattr $C$DW$443, DW_AT_TI_call
           CALL    .S1     _ReadDARAM1__FUsPvT1 ; |779| 
           MVK     .S1     784,A3            ; |779| 
           ADDKPC  .S2     $C$RL65,B3,2      ; |779| 

           MVK     .L1     0x4,A4            ; |779| 
||         MVK     .S1     0x300,A6          ; |779| 
||         ADD     .L2X    A3,SP,B4          ; |779| 

$C$RL65:   ; CALL OCCURS {_ReadDARAM1__FUsPvT1} {0}  ; |779| 

$C$DW$444	.dwtag  DW_TAG_lexical_block, DW_AT_low_pc(0x00), DW_AT_high_pc(0x00)
$C$DW$445	.dwtag  DW_TAG_variable, DW_AT_name("i")
	.dwattr $C$DW$445, DW_AT_TI_symbol_name("_i")
	.dwattr $C$DW$445, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$445, DW_AT_location[DW_OP_breg31 1556]
	.dwpsn	file "test_c.cpp",line 781,column 12,is_stmt
           MVK     .L2     2,B4              ; |781| 
           STW     .D2T2   B4,*+SP(1556)     ; |781| 
	.dwpsn	file "test_c.cpp",line 781,column 16,is_stmt
           MVK     .S2     190,B5            ; |781| 
           CMPLT   .L2     B4,B5,B0          ; |781| 
   [!B0]   BNOP    .S1     $C$L75,5          ; |781| 
           ; BRANCHCC OCCURS {$C$L75}        ; |781| 
$C$DW$L$_TestDOZU_Nagr__FPv$9$E:
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
$C$L72:    
$C$DW$L$_TestDOZU_Nagr__FPv$10$B:
	.dwpsn	file "test_c.cpp",line 783,column 4,is_stmt
;----------------------------------------------------------------------
; 783 | do                                                                     
;----------------------------------------------------------------------
           SUB     .L2     B4,1,B4           ; |783| 
           ADDAW   .D2     SP,B4,B4          ; |783| 
           LDW     .D2T2   *+B4(16),B4       ; |783| 
           LDW     .D2T2   *+SP(1556),B5     ; |783| 
           MVKL    .S2     0x66467329,B6
           MVKH    .S2     0x66467329,B6
           MVKL    .S1     0xa6549873,A3
           MPYLH   .M2     B6,B4,B8          ; |783| 
           MPYLH   .M2     B4,B6,B7          ; |783| 
           ADDAW   .D2     SP,B5,B5          ; |783| 

           MPYU    .M2     B6,B4,B6          ; |783| 
||         LDW     .D2T2   *+B5(16),B31      ; |783| 
||         ADD     .L2     B8,B7,B5          ; |783| 

           SHL     .S2     B5,16,B5          ; |783| 
           ADD     .L2     B6,B5,B5          ; |783| 
           MVKH    .S1     0xa6549873,A3
           ADD     .L1X    A3,B5,A3          ; |783| 
           CMPEQ   .L1X    B31,A3,A0         ; |783| 
   [ A0]   BNOP    .S1     $C$L73,5          ; |783| 
           ; BRANCHCC OCCURS {$C$L73}        ; |783| 
$C$DW$L$_TestDOZU_Nagr__FPv$10$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_TestDOZU_Nagr__FPv$11$B:
	.dwpsn	file "test_c.cpp",line 785,column 2,is_stmt
;----------------------------------------------------------------------
; 785 | if(!Start_dozu_nagr)                                                   
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(8),B4        ; |785| 
           NOP             4
           ADD     .L2     1,B4,B4           ; |785| 
           STW     .D2T2   B4,*+SP(8)        ; |785| 
	.dwpsn	file "test_c.cpp",line 786,column 5,is_stmt
;----------------------------------------------------------------------
; 786 | goto end_dozu_nagr;                                                    
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(1556),B4     ; |786| 
           LDW     .D2T2   *+SP(1556),B5     ; |786| 
           MVKL    .S2     0x66467329,B6
           MVKH    .S2     0x66467329,B6
           MVKL    .S1     0xa6549873,A3
           SUB     .L2     B4,1,B4           ; |786| 
           ADDAW   .D2     SP,B4,B4          ; |786| 
           ADDK    .S2     784,B4            ; |786| 
           LDW     .D2T2   *B4,B4            ; |786| 
           ADDAW   .D2     SP,B5,B5          ; |786| 
           ADDK    .S2     784,B5            ; |786| 
           LDW     .D2T2   *B5,B31           ; |786| 
           MVKH    .S1     0xa6549873,A3
           MPYLH   .M2     B6,B4,B7          ; |786| 
           MPYLH   .M2     B4,B6,B8          ; |786| 
           MPYU    .M2     B6,B4,B6          ; |786| 
           ADD     .L2     B7,B8,B5          ; |786| 
           SHL     .S2     B5,16,B5          ; |786| 
           ADD     .L2     B6,B5,B5          ; |786| 
           NOP             1
           ADD     .L1X    A3,B5,A3          ; |786| 
           CMPEQ   .L1X    B31,A3,A0         ; |786| 
   [ A0]   BNOP    .S1     $C$L74,5          ; |786| 
           ; BRANCHCC OCCURS {$C$L74}        ; |786| 
$C$DW$L$_TestDOZU_Nagr__FPv$11$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_TestDOZU_Nagr__FPv$12$B:
	.dwpsn	file "test_c.cpp",line 787,column 3,is_stmt
           LDW     .D2T2   *+SP(12),B4       ; |787| 
           NOP             4
           ADD     .L2     1,B4,B4           ; |787| 
           STW     .D2T2   B4,*+SP(12)       ; |787| 
	.dwpsn	file "test_c.cpp",line 788,column 3,is_stmt
;----------------------------------------------------------------------
; 788 | ReadDARAM0(4,buf0,4);                                                  
; 789 | ReadDARAM1(4,buf1,4);                                                  
;----------------------------------------------------------------------
           BNOP    .S1     $C$L74,5          ; |788| 
           ; BRANCH OCCURS {$C$L74}          ; |788| 
$C$DW$L$_TestDOZU_Nagr__FPv$12$E:
;** --------------------------------------------------------------------------*
$C$L73:    
$C$DW$L$_TestDOZU_Nagr__FPv$13$B:
	.dwpsn	file "test_c.cpp",line 790,column 4,is_stmt
           LDW     .D2T2   *+SP(1556),B4     ; |790| 
           NOP             4
           MV      .L2     B4,B5             ; |790| 
           ADDAW   .D2     SP,B5,B5          ; |790| 
           ADDAW   .D2     SP,B4,B4          ; |790| 

           ADDK    .S2     784,B4            ; |790| 
||         LDW     .D2T2   *+B5(16),B5       ; |790| 

           LDW     .D2T2   *B4,B4            ; |790| 
           NOP             4
           CMPEQ   .L2     B4,B5,B0          ; |790| 
   [ B0]   BNOP    .S1     $C$L74,5          ; |790| 
           ; BRANCHCC OCCURS {$C$L74}        ; |790| 
$C$DW$L$_TestDOZU_Nagr__FPv$13$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_TestDOZU_Nagr__FPv$14$B:
	.dwpsn	file "test_c.cpp",line 791,column 2,is_stmt
;----------------------------------------------------------------------
; 791 | while((buf0[0]==0) | (buf1[0]==0));                                    
; 793 | ReadDARAM0(4,buf0,L*4);                                                
; 794 | ReadDARAM1(4,buf1,L*4);                                                
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(12),B4       ; |791| 
           NOP             4
           ADD     .L2     1,B4,B4           ; |791| 
           STW     .D2T2   B4,*+SP(12)       ; |791| 
$C$DW$L$_TestDOZU_Nagr__FPv$14$E:
;** --------------------------------------------------------------------------*
$C$L74:    
$C$DW$L$_TestDOZU_Nagr__FPv$15$B:
	.dwpsn	file "test_c.cpp",line 781,column 24,is_stmt
           LDW     .D2T2   *+SP(1556),B4     ; |781| 
           NOP             4
           ADD     .L2     1,B4,B4           ; |781| 
           STW     .D2T2   B4,*+SP(1556)     ; |781| 
	.dwpsn	file "test_c.cpp",line 781,column 16,is_stmt
           MVK     .S2     190,B5            ; |781| 
           CMPLT   .L2     B4,B5,B0          ; |781| 
   [ B0]   BNOP    .S1     $C$L72,5          ; |781| 
           ; BRANCHCC OCCURS {$C$L72}        ; |781| 
$C$DW$L$_TestDOZU_Nagr__FPv$15$E:
;** --------------------------------------------------------------------------*
$C$L75:    
$C$DW$L$_TestDOZU_Nagr__FPv$16$B:
	.dwendtag $C$DW$444

	.dwpsn	file "test_c.cpp",line 795,column 3,is_stmt
           ZERO    .L2     B4                ; |795| 
           STW     .D2T2   B4,*+SP(16)       ; |795| 
	.dwpsn	file "test_c.cpp",line 796,column 3,is_stmt
;----------------------------------------------------------------------
; 796 | for (int i=2;i<(L-2);i++)                                              
; 798 |  if (buf0[i]!=buf0[i-1]*0x66467329+0xA6549873)                         
;----------------------------------------------------------------------
$C$DW$446	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$446, DW_AT_low_pc(0x00)
	.dwattr $C$DW$446, DW_AT_name("_WriteDARAM__FUsPvT1")
	.dwattr $C$DW$446, DW_AT_TI_call
           CALL    .S1     _WriteDARAM__FUsPvT1 ; |796| 
           ADDKPC  .S2     $C$RL66,B3,3      ; |796| 

           ADD     .D2     SP,16,B4          ; |796| 
||         MVK     .L1     0x4,A4            ; |796| 
||         MVK     .S1     0x4,A6            ; |796| 

$C$RL66:   ; CALL OCCURS {_WriteDARAM__FUsPvT1} {0}  ; |796| 
$C$DW$L$_TestDOZU_Nagr__FPv$16$E:
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
$C$L76:    
$C$DW$L$_TestDOZU_Nagr__FPv$17$B:
	.dwpsn	file "test_c.cpp",line 800,column 3,is_stmt
;----------------------------------------------------------------------
; 800 | error0++;                                                              
;----------------------------------------------------------------------
           MVKL    .S1     _Start_dozu_nagr,A3
           MVKH    .S1     _Start_dozu_nagr,A3
           LDHU    .D1T1   *A3,A0            ; |800| 
           NOP             4
   [!A0]   BNOP    .S1     $C$L77,5          ; |800| 
           ; BRANCHCC OCCURS {$C$L77}        ; |800| 
$C$DW$L$_TestDOZU_Nagr__FPv$17$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_TestDOZU_Nagr__FPv$18$B:
	.dwpsn	file "test_c.cpp",line 801,column 3,is_stmt
;----------------------------------------------------------------------
; 801 | if (buf1[i]!=buf1[i-1]*0x66467329+0xA6549873)                          
; 802 |      error1++;                                                         
;----------------------------------------------------------------------
	.dwpsn	file "test_c.cpp",line 803,column 4,is_stmt
$C$DW$447	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$447, DW_AT_low_pc(0x00)
	.dwattr $C$DW$447, DW_AT_name("_ReadDARAM0__FUsPvT1")
	.dwattr $C$DW$447, DW_AT_TI_call
           CALL    .S1     _ReadDARAM0__FUsPvT1 ; |803| 
           ADDKPC  .S2     $C$RL67,B3,3      ; |803| 

           MVK     .L1     0x4,A4            ; |803| 
||         ADD     .D2     SP,16,B4          ; |803| 
||         MVK     .S1     0x4,A6            ; |803| 

$C$RL67:   ; CALL OCCURS {_ReadDARAM0__FUsPvT1} {0}  ; |803| 
	.dwpsn	file "test_c.cpp",line 804,column 4,is_stmt
;----------------------------------------------------------------------
; 804 | else                                                                   
;----------------------------------------------------------------------
$C$DW$448	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$448, DW_AT_low_pc(0x00)
	.dwattr $C$DW$448, DW_AT_name("_ReadDARAM1__FUsPvT1")
	.dwattr $C$DW$448, DW_AT_TI_call
           CALL    .S1     _ReadDARAM1__FUsPvT1 ; |804| 
           MVK     .S2     784,B4            ; |804| 
           ADDKPC  .S2     $C$RL68,B3,2      ; |804| 

           ADD     .L2     B4,SP,B4          ; |804| 
||         MVK     .L1     0x4,A4            ; |804| 
||         MVK     .S1     0x4,A6            ; |804| 

$C$RL68:   ; CALL OCCURS {_ReadDARAM1__FUsPvT1} {0}  ; |804| 
	.dwpsn	file "test_c.cpp",line 805,column 3,is_stmt
;----------------------------------------------------------------------
; 805 | if (buf1[i]!=buf0[i])                                                  
; 806 |      error1++;                                                         
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(16),B4       ; |805| 
           LDW     .D2T2   *+SP(784),B5      ; |805| 
           NOP             3
           CMPEQ   .L2     B4,1,B4           ; |805| 
           CMPEQ   .L2     B5,1,B5           ; |805| 
           OR      .L2     B5,B4,B0          ; |805| 
   [ B0]   BNOP    .S1     $C$L76,5          ; |805| 
           ; BRANCHCC OCCURS {$C$L76}        ; |805| 
$C$DW$L$_TestDOZU_Nagr__FPv$18$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_TestDOZU_Nagr__FPv$19$B:
	.dwpsn	file "test_c.cpp",line 808,column 1,is_stmt
           LDW     .D2T2   *+SP(1552),B4     ; |808| 
           MVKL    .S2     _gl_result+4,B6
           MVKH    .S2     _gl_result+4,B6
           NOP             2
           ADD     .L2     1,B4,B5           ; |808| 
           STW     .D2T2   B5,*+SP(1552)     ; |808| 
           STW     .D2T2   B4,*B6            ; |808| 
	.dwpsn	file "test_c.cpp",line 810,column 1,is_stmt
;----------------------------------------------------------------------
; 810 | buf0[0]=0;                                                             
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(8),B4        ; |810| 
           ADD     .L1X    4,B6,A3
           NOP             3
           STW     .D1T2   B4,*A3            ; |810| 
	.dwpsn	file "test_c.cpp",line 811,column 1,is_stmt
;----------------------------------------------------------------------
; 811 | WriteDARAM(4,buf0,4);                                                  
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(12),B4       ; |811| 
           ADD     .L2     8,B6,B5
           NOP             3
           STW     .D2T2   B4,*B5            ; |811| 
	.dwpsn	file "test_c.cpp",line 812,column 1,is_stmt
$C$DW$449	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$449, DW_AT_low_pc(0x00)
	.dwattr $C$DW$449, DW_AT_name("_ReadDARAM0__FUsPvT1")
	.dwattr $C$DW$449, DW_AT_TI_call
           CALL    .S1     _ReadDARAM0__FUsPvT1 ; |812| 
           ADDKPC  .S2     $C$RL69,B3,3      ; |812| 

           ADD     .D2     SP,16,B4          ; |812| 
||         ZERO    .L1     A4                ; |812| 
||         MVK     .S1     0x4,A6            ; |812| 

$C$RL69:   ; CALL OCCURS {_ReadDARAM0__FUsPvT1} {0}  ; |812| 
	.dwpsn	file "test_c.cpp",line 813,column 1,is_stmt
;----------------------------------------------------------------------
; 813 | do                                                                     
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(16),B4       ; |813| 
           MVKL    .S1     _gl_result+16,A3
           MVKH    .S1     _gl_result+16,A3
           NOP             2
           STW     .D1T2   B4,*A3            ; |813| 
	.dwpsn	file "test_c.cpp",line 814,column 1,is_stmt
$C$DW$450	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$450, DW_AT_low_pc(0x00)
	.dwattr $C$DW$450, DW_AT_name("_ReadDARAM1__FUsPvT1")
	.dwattr $C$DW$450, DW_AT_TI_call
           CALL    .S1     _ReadDARAM1__FUsPvT1 ; |814| 
           MVK     .S2     784,B4            ; |814| 
           ADDKPC  .S2     $C$RL70,B3,2      ; |814| 

           ADD     .L2     B4,SP,B4          ; |814| 
||         ZERO    .L1     A4                ; |814| 
||         MVK     .S1     0x4,A6            ; |814| 

$C$RL70:   ; CALL OCCURS {_ReadDARAM1__FUsPvT1} {0}  ; |814| 
	.dwpsn	file "test_c.cpp",line 815,column 1,is_stmt
;----------------------------------------------------------------------
; 815 | if(!Start_dozu_nagr)                                                   
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(16),B4       ; |815| 
           MVKL    .S2     _gl_result+20,B5
           MVKH    .S2     _gl_result+20,B5
           NOP             2
           STW     .D2T2   B4,*B5            ; |815| 
	.dwpsn	file "test_c.cpp",line 816,column 1,is_stmt
;----------------------------------------------------------------------
; 816 | goto end_dozu_nagr;                                                    
; 818 | ReadDARAM0(4,buf0,4);                                                  
; 819 | ReadDARAM1(4,buf1,4);                                                  
;----------------------------------------------------------------------
           MVKL    .S1     _Start_dozu_nagr,A3
           MVKH    .S1     _Start_dozu_nagr,A3
           LDHU    .D1T1   *A3,A0            ; |816| 
           NOP             4
   [ A0]   BNOP    .S1     $C$L68,5          ; |816| 
           ; BRANCHCC OCCURS {$C$L68}        ; |816| 
$C$DW$L$_TestDOZU_Nagr__FPv$19$E:
;** --------------------------------------------------------------------------*
$C$L77:    
	.dwpsn	file "test_c.cpp",line 820,column 1,is_stmt
           MVKL    .S1     ___syscall_tab+44,A3
           MVKH    .S1     ___syscall_tab+44,A3
           LDW     .D1T1   *A3,A3            ; |820| 
           NOP             4
$C$DW$451	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$451, DW_AT_low_pc(0x00)
	.dwattr $C$DW$451, DW_AT_TI_call
	.dwattr $C$DW$451, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |820| 
           ADDKPC  .S2     $C$RL71,B3,4      ; |820| 
$C$RL71:   ; CALL OCCURS {A3} {0}            ; |820| 
	.dwpsn	file "test_c.cpp",line 821,column 7,is_stmt
;----------------------------------------------------------------------
; 821 | while((buf0[0]==1) |(buf1[0]==1));                                     
; 823 | gl_result.n_test = X++;                                                
;----------------------------------------------------------------------
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
$C$L78:    
$C$DW$L$_TestDOZU_Nagr__FPv$21$B:
           BNOP    .S1     $C$L78,5          ; |821| 
           ; BRANCH OCCURS {$C$L78}          ; |821| 
$C$DW$L$_TestDOZU_Nagr__FPv$21$E:
;** --------------------------------------------------------------------------*
	.dwcfi	restore_reg, 27
	.dwcfi	restore_reg, 26
	.dwcfi	restore_reg, 19
	.dwcfi	cfa_offset, 0
	.dwcfi	cfa_offset, 0

$C$DW$452	.dwtag  DW_TAG_TI_loop
	.dwattr $C$DW$452, DW_AT_name("C:\1901VC1T_Inteltech\3rdPartyLIB\dsp_core\C6000\tpo_amoeba\source\test_c.asm:$C$L78:1:1517815039")
	.dwattr $C$DW$452, DW_AT_TI_begin_file("test_c.cpp")
	.dwattr $C$DW$452, DW_AT_TI_begin_line(0x335)
	.dwattr $C$DW$452, DW_AT_TI_end_line(0x335)
$C$DW$453	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$453, DW_AT_low_pc($C$DW$L$_TestDOZU_Nagr__FPv$21$B)
	.dwattr $C$DW$453, DW_AT_high_pc($C$DW$L$_TestDOZU_Nagr__FPv$21$E)
	.dwendtag $C$DW$452


$C$DW$454	.dwtag  DW_TAG_TI_loop
	.dwattr $C$DW$454, DW_AT_name("C:\1901VC1T_Inteltech\3rdPartyLIB\dsp_core\C6000\tpo_amoeba\source\test_c.asm:$C$L68:1:1517815039")
	.dwattr $C$DW$454, DW_AT_TI_begin_file("test_c.cpp")
	.dwattr $C$DW$454, DW_AT_TI_begin_line(0x2f0)
	.dwattr $C$DW$454, DW_AT_TI_end_line(0x330)
$C$DW$455	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$455, DW_AT_low_pc($C$DW$L$_TestDOZU_Nagr__FPv$4$B)
	.dwattr $C$DW$455, DW_AT_high_pc($C$DW$L$_TestDOZU_Nagr__FPv$4$E)
$C$DW$456	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$456, DW_AT_low_pc($C$DW$L$_TestDOZU_Nagr__FPv$6$B)
	.dwattr $C$DW$456, DW_AT_high_pc($C$DW$L$_TestDOZU_Nagr__FPv$6$E)
$C$DW$457	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$457, DW_AT_low_pc($C$DW$L$_TestDOZU_Nagr__FPv$9$B)
	.dwattr $C$DW$457, DW_AT_high_pc($C$DW$L$_TestDOZU_Nagr__FPv$9$E)
$C$DW$458	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$458, DW_AT_low_pc($C$DW$L$_TestDOZU_Nagr__FPv$16$B)
	.dwattr $C$DW$458, DW_AT_high_pc($C$DW$L$_TestDOZU_Nagr__FPv$16$E)
$C$DW$459	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$459, DW_AT_low_pc($C$DW$L$_TestDOZU_Nagr__FPv$19$B)
	.dwattr $C$DW$459, DW_AT_high_pc($C$DW$L$_TestDOZU_Nagr__FPv$19$E)

$C$DW$460	.dwtag  DW_TAG_TI_loop
	.dwattr $C$DW$460, DW_AT_name("C:\1901VC1T_Inteltech\3rdPartyLIB\dsp_core\C6000\tpo_amoeba\source\test_c.asm:$C$L69:2:1517815039")
	.dwattr $C$DW$460, DW_AT_TI_begin_file("test_c.cpp")
	.dwattr $C$DW$460, DW_AT_TI_begin_line(0x2f6)
	.dwattr $C$DW$460, DW_AT_TI_end_line(0x2f9)
$C$DW$461	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$461, DW_AT_low_pc($C$DW$L$_TestDOZU_Nagr__FPv$5$B)
	.dwattr $C$DW$461, DW_AT_high_pc($C$DW$L$_TestDOZU_Nagr__FPv$5$E)
	.dwendtag $C$DW$460


$C$DW$462	.dwtag  DW_TAG_TI_loop
	.dwattr $C$DW$462, DW_AT_name("C:\1901VC1T_Inteltech\3rdPartyLIB\dsp_core\C6000\tpo_amoeba\source\test_c.asm:$C$L71:2:1517815039")
	.dwattr $C$DW$462, DW_AT_TI_begin_file("test_c.cpp")
	.dwattr $C$DW$462, DW_AT_TI_begin_line(0x300)
	.dwattr $C$DW$462, DW_AT_TI_end_line(0x307)
$C$DW$463	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$463, DW_AT_low_pc($C$DW$L$_TestDOZU_Nagr__FPv$7$B)
	.dwattr $C$DW$463, DW_AT_high_pc($C$DW$L$_TestDOZU_Nagr__FPv$7$E)
$C$DW$464	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$464, DW_AT_low_pc($C$DW$L$_TestDOZU_Nagr__FPv$8$B)
	.dwattr $C$DW$464, DW_AT_high_pc($C$DW$L$_TestDOZU_Nagr__FPv$8$E)
	.dwendtag $C$DW$462


$C$DW$465	.dwtag  DW_TAG_TI_loop
	.dwattr $C$DW$465, DW_AT_name("C:\1901VC1T_Inteltech\3rdPartyLIB\dsp_core\C6000\tpo_amoeba\source\test_c.asm:$C$L72:2:1517815039")
	.dwattr $C$DW$465, DW_AT_TI_begin_file("test_c.cpp")
	.dwattr $C$DW$465, DW_AT_TI_begin_line(0x30d)
	.dwattr $C$DW$465, DW_AT_TI_end_line(0x319)
$C$DW$466	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$466, DW_AT_low_pc($C$DW$L$_TestDOZU_Nagr__FPv$10$B)
	.dwattr $C$DW$466, DW_AT_high_pc($C$DW$L$_TestDOZU_Nagr__FPv$10$E)
$C$DW$467	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$467, DW_AT_low_pc($C$DW$L$_TestDOZU_Nagr__FPv$11$B)
	.dwattr $C$DW$467, DW_AT_high_pc($C$DW$L$_TestDOZU_Nagr__FPv$11$E)
$C$DW$468	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$468, DW_AT_low_pc($C$DW$L$_TestDOZU_Nagr__FPv$12$B)
	.dwattr $C$DW$468, DW_AT_high_pc($C$DW$L$_TestDOZU_Nagr__FPv$12$E)
$C$DW$469	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$469, DW_AT_low_pc($C$DW$L$_TestDOZU_Nagr__FPv$13$B)
	.dwattr $C$DW$469, DW_AT_high_pc($C$DW$L$_TestDOZU_Nagr__FPv$13$E)
$C$DW$470	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$470, DW_AT_low_pc($C$DW$L$_TestDOZU_Nagr__FPv$14$B)
	.dwattr $C$DW$470, DW_AT_high_pc($C$DW$L$_TestDOZU_Nagr__FPv$14$E)
$C$DW$471	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$471, DW_AT_low_pc($C$DW$L$_TestDOZU_Nagr__FPv$15$B)
	.dwattr $C$DW$471, DW_AT_high_pc($C$DW$L$_TestDOZU_Nagr__FPv$15$E)
	.dwendtag $C$DW$465


$C$DW$472	.dwtag  DW_TAG_TI_loop
	.dwattr $C$DW$472, DW_AT_name("C:\1901VC1T_Inteltech\3rdPartyLIB\dsp_core\C6000\tpo_amoeba\source\test_c.asm:$C$L76:2:1517815039")
	.dwattr $C$DW$472, DW_AT_TI_begin_file("test_c.cpp")
	.dwattr $C$DW$472, DW_AT_TI_begin_line(0x31e)
	.dwattr $C$DW$472, DW_AT_TI_end_line(0x325)
$C$DW$473	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$473, DW_AT_low_pc($C$DW$L$_TestDOZU_Nagr__FPv$17$B)
	.dwattr $C$DW$473, DW_AT_high_pc($C$DW$L$_TestDOZU_Nagr__FPv$17$E)
$C$DW$474	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$474, DW_AT_low_pc($C$DW$L$_TestDOZU_Nagr__FPv$18$B)
	.dwattr $C$DW$474, DW_AT_high_pc($C$DW$L$_TestDOZU_Nagr__FPv$18$E)
	.dwendtag $C$DW$472

	.dwendtag $C$DW$454


$C$DW$475	.dwtag  DW_TAG_TI_loop
	.dwattr $C$DW$475, DW_AT_name("C:\1901VC1T_Inteltech\3rdPartyLIB\dsp_core\C6000\tpo_amoeba\source\test_c.asm:$C$L67:1:1517815039")
	.dwattr $C$DW$475, DW_AT_TI_begin_file("test_c.cpp")
	.dwattr $C$DW$475, DW_AT_TI_begin_line(0x2e8)
	.dwattr $C$DW$475, DW_AT_TI_end_line(0x2ec)
$C$DW$476	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$476, DW_AT_low_pc($C$DW$L$_TestDOZU_Nagr__FPv$2$B)
	.dwattr $C$DW$476, DW_AT_high_pc($C$DW$L$_TestDOZU_Nagr__FPv$2$E)
	.dwendtag $C$DW$475

	.dwattr $C$DW$422, DW_AT_TI_end_file("test_c.cpp")
	.dwattr $C$DW$422, DW_AT_TI_end_line(0x338)
	.dwattr $C$DW$422, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$422

	.sect	".text"
	.clink
	.global	_Sv_Msg__FPv

$C$DW$477	.dwtag  DW_TAG_subprogram, DW_AT_name("Sv_Msg")
	.dwattr $C$DW$477, DW_AT_low_pc(_Sv_Msg__FPv)
	.dwattr $C$DW$477, DW_AT_high_pc(0x00)
	.dwattr $C$DW$477, DW_AT_TI_symbol_name("_Sv_Msg__FPv")
	.dwattr $C$DW$477, DW_AT_external
	.dwattr $C$DW$477, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$477, DW_AT_TI_begin_file("test_c.cpp")
	.dwattr $C$DW$477, DW_AT_TI_begin_line(0x340)
	.dwattr $C$DW$477, DW_AT_TI_begin_column(0x05)
	.dwpsn	file "test_c.cpp",line 833,column 1,is_stmt,address _Sv_Msg__FPv

	.dwfde $C$DW$CIE, _Sv_Msg__FPv
$C$DW$478	.dwtag  DW_TAG_formal_parameter, DW_AT_name("arg")
	.dwattr $C$DW$478, DW_AT_TI_symbol_name("_arg")
	.dwattr $C$DW$478, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$478, DW_AT_location[DW_OP_reg4]

;******************************************************************************
;* FUNCTION NAME: Sv_Msg(void *)                                              *
;*                                                                            *
;*   Regs Modified     : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP,A16,A17,A18,A19,A20,A21,A22,A23,A24, *
;*                           A25,A26,A27,A28,A29,A30,A31,B16,B17,B18,B19,B20, *
;*                           B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31      *
;*   Regs Used         : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP,A16,A17,A18,A19,A20,A21,A22,A23,A24, *
;*                           A25,A26,A27,A28,A29,A30,A31,B16,B17,B18,B19,B20, *
;*                           B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31      *
;*   Local Frame Size  : 0 Args + 9240 Auto + 4 Save = 9244 byte              *
;******************************************************************************
_Sv_Msg__FPv:
;** --------------------------------------------------------------------------*
;----------------------------------------------------------------------
; 833 | end_dozu_nagr:                                                         
;----------------------------------------------------------------------
	.dwcfi	cfa_offset, 0
	.dwcfi	save_reg_to_reg, 228, 19
           ADDK    .S2     -9248,SP          ; |833| 
	.dwcfi	cfa_offset, 9248
           STW     .D2T2   B3,*+SP(9248)     ; |833| 
	.dwcfi	save_reg_to_mem, 19, 0
$C$DW$479	.dwtag  DW_TAG_variable, DW_AT_name("arg")
	.dwattr $C$DW$479, DW_AT_TI_symbol_name("_arg")
	.dwattr $C$DW$479, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$479, DW_AT_location[DW_OP_breg31 4]
$C$DW$480	.dwtag  DW_TAG_variable, DW_AT_name("error")
	.dwattr $C$DW$480, DW_AT_TI_symbol_name("_error")
	.dwattr $C$DW$480, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$480, DW_AT_location[DW_OP_breg31 8]
$C$DW$481	.dwtag  DW_TAG_variable, DW_AT_name("msg_from")
	.dwattr $C$DW$481, DW_AT_TI_symbol_name("_msg_from")
	.dwattr $C$DW$481, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$481, DW_AT_location[DW_OP_breg31 12]
$C$DW$482	.dwtag  DW_TAG_variable, DW_AT_name("cdg_error")
	.dwattr $C$DW$482, DW_AT_TI_symbol_name("_cdg_error")
	.dwattr $C$DW$482, DW_AT_type(*$C$DW$T$393)
	.dwattr $C$DW$482, DW_AT_location[DW_OP_breg31 16]
$C$DW$483	.dwtag  DW_TAG_variable, DW_AT_name("msg_desc")
	.dwattr $C$DW$483, DW_AT_TI_symbol_name("_msg_desc")
	.dwattr $C$DW$483, DW_AT_type(*$C$DW$T$129)
	.dwattr $C$DW$483, DW_AT_location[DW_OP_breg31 24]
$C$DW$484	.dwtag  DW_TAG_variable, DW_AT_name("buf55")
	.dwattr $C$DW$484, DW_AT_TI_symbol_name("_buf55")
	.dwattr $C$DW$484, DW_AT_type(*$C$DW$T$744)
	.dwattr $C$DW$484, DW_AT_location[DW_OP_breg31 32]
$C$DW$485	.dwtag  DW_TAG_variable, DW_AT_name("bufAA")
	.dwattr $C$DW$485, DW_AT_TI_symbol_name("_bufAA")
	.dwattr $C$DW$485, DW_AT_type(*$C$DW$T$744)
	.dwattr $C$DW$485, DW_AT_location[DW_OP_breg31 1568]
$C$DW$486	.dwtag  DW_TAG_variable, DW_AT_name("buf1")
	.dwattr $C$DW$486, DW_AT_TI_symbol_name("_buf1")
	.dwattr $C$DW$486, DW_AT_type(*$C$DW$T$744)
	.dwattr $C$DW$486, DW_AT_location[DW_OP_breg31 3104]
$C$DW$487	.dwtag  DW_TAG_variable, DW_AT_name("buf2")
	.dwattr $C$DW$487, DW_AT_TI_symbol_name("_buf2")
	.dwattr $C$DW$487, DW_AT_type(*$C$DW$T$744)
	.dwattr $C$DW$487, DW_AT_location[DW_OP_breg31 4640]
$C$DW$488	.dwtag  DW_TAG_variable, DW_AT_name("buf11")
	.dwattr $C$DW$488, DW_AT_TI_symbol_name("_buf11")
	.dwattr $C$DW$488, DW_AT_type(*$C$DW$T$758)
	.dwattr $C$DW$488, DW_AT_location[DW_OP_breg31 6176]
$C$DW$489	.dwtag  DW_TAG_variable, DW_AT_name("buf22")
	.dwattr $C$DW$489, DW_AT_TI_symbol_name("_buf22")
	.dwattr $C$DW$489, DW_AT_type(*$C$DW$T$758)
	.dwattr $C$DW$489, DW_AT_location[DW_OP_breg31 7680]
$C$DW$490	.dwtag  DW_TAG_variable, DW_AT_name("FileNet")
	.dwattr $C$DW$490, DW_AT_TI_symbol_name("_FileNet")
	.dwattr $C$DW$490, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$490, DW_AT_location[DW_OP_breg31 9180]
$C$DW$491	.dwtag  DW_TAG_label, DW_AT_name("close_drv1"), DW_AT_low_pc($C$L103)
	.dwattr $C$DW$491, DW_AT_TI_symbol_name("_close_drv1")
$C$DW$492	.dwtag  DW_TAG_label, DW_AT_name("close_drv2"), DW_AT_low_pc($C$L110)
	.dwattr $C$DW$492, DW_AT_TI_symbol_name("_close_drv2")
;----------------------------------------------------------------------
; 835 | prc_exit();                                                            
; 836 | while(1);                                                              
; 845 | extern uint32 sv_msg_open;                                             
; 847 | int Sv_Msg(void* arg)                                                  
; 850 | int32               error;                                             
; 851 |     uint32          msg_from;                                          
;----------------------------------------------------------------------
           STW     .D2T1   A4,*+SP(4)        ; |833| 
	.dwpsn	file "test_c.cpp",line 852,column 8,is_stmt
;----------------------------------------------------------------------
; 852 | //      kdg_cmd         to_iface;                                      
; 853 | kdg_cmd_ask     cdg_error;                                             
;----------------------------------------------------------------------
           ZERO    .L2     B4                ; |852| 
           STW     .D2T2   B4,*+SP(9180)     ; |852| 
	.dwpsn	file "test_c.cpp",line 854,column 1,is_stmt
;----------------------------------------------------------------------
; 854 | s_message*  msg_desc;                                                  
;----------------------------------------------------------------------
$C$DW$493	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$493, DW_AT_low_pc(0x00)
	.dwattr $C$DW$493, DW_AT_name("_memset")
	.dwattr $C$DW$493, DW_AT_TI_call
           CALL    .S1     _memset           ; |854| 
           ADDAD   .D2     SP,4,B5           ; |854| 
           MVK     .S2     0x55,B4           ; |854| 
           MV      .L1X    B5,A4             ; |854| 
           ADDKPC  .S2     $C$RL72,B3,0      ; |854| 
           MVK     .S1     0x600,A6          ; |854| 
$C$RL72:   ; CALL OCCURS {_memset} {0}       ; |854| 
	.dwpsn	file "test_c.cpp",line 855,column 1,is_stmt
;----------------------------------------------------------------------
; 857 | uint32 buf55[LEN_MOVE/4];                                              
;----------------------------------------------------------------------
$C$DW$494	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$494, DW_AT_low_pc(0x00)
	.dwattr $C$DW$494, DW_AT_name("_memset")
	.dwattr $C$DW$494, DW_AT_TI_call
           CALL    .S1     _memset           ; |855| 
           MVK     .S2     1568,B4           ; |855| 
           ADD     .L2     B4,SP,B5          ; |855| 
           MVK     .S2     0xaa,B4           ; |855| 
           MV      .L1X    B5,A4             ; |855| 

           ADDKPC  .S2     $C$RL73,B3,0      ; |855| 
||         MVK     .S1     0x600,A6          ; |855| 

$C$RL73:   ; CALL OCCURS {_memset} {0}       ; |855| 
	.dwpsn	file "test_c.cpp",line 858,column 3,is_stmt
;----------------------------------------------------------------------
; 858 | uint32 bufAA[LEN_MOVE/4];                                              
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+376,A3
           MVKH    .S1     ___syscall_tab+376,A3
           LDW     .D1T1   *A3,A3            ; |858| 
           MVKL    .S1     $C$SL2+0,A4       ; |858| 
           MVKH    .S1     $C$SL2+0,A4       ; |858| 
           NOP             2
$C$DW$495	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$495, DW_AT_low_pc(0x00)
	.dwattr $C$DW$495, DW_AT_TI_call
	.dwattr $C$DW$495, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |858| 
           ADDKPC  .S2     $C$RL74,B3,4      ; |858| 
$C$RL74:   ; CALL OCCURS {A3} {0}            ; |858| 
           STW     .D2T1   A4,*+SP(8)        ; |858| 
	.dwpsn	file "test_c.cpp",line 859,column 3,is_stmt
;----------------------------------------------------------------------
; 859 | uint32 buf1[LEN_MOVE/4];                                               
;----------------------------------------------------------------------
           MV      .L2X    A4,B0
   [!B0]   BNOP    .S1     $C$L80,5          ; |859| 
           ; BRANCHCC OCCURS {$C$L80}        ; |859| 
;** --------------------------------------------------------------------------*
	.dwpsn	file "test_c.cpp",line 860,column 8,is_stmt
;----------------------------------------------------------------------
; 860 | uint32 buf2[LEN_MOVE/4];                                               
;----------------------------------------------------------------------
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
$C$L79:    
$C$DW$L$_Sv_Msg__FPv$3$B:
           BNOP    .S1     $C$L79,5          ; |860| 
           ; BRANCH OCCURS {$C$L79}          ; |860| 
$C$DW$L$_Sv_Msg__FPv$3$E:
;** --------------------------------------------------------------------------*
$C$L80:    
	.dwpsn	file "test_c.cpp",line 862,column 3,is_stmt
;----------------------------------------------------------------------
; 862 | char buf11[1500];                                                      
; 863 | char buf22[1500];                                                      
;----------------------------------------------------------------------
           MVKL    .S1     _sv_msg_open,A3
           MVKH    .S1     _sv_msg_open,A3
           LDW     .D1T1   *A3,A0            ; |862| 
           NOP             4
   [!A0]   BNOP    .S1     $C$L117,5         ; |862| 
           ; BRANCHCC OCCURS {$C$L117}       ; |862| 
;** --------------------------------------------------------------------------*
;**   BEGIN LOOP $C$L81
;** --------------------------------------------------------------------------*
$C$L81:    
$C$DW$L$_Sv_Msg__FPv$5$B:
	.dwpsn	file "test_c.cpp",line 865,column 2,is_stmt
;----------------------------------------------------------------------
; 865 | char buf12[1500];                                                      
;----------------------------------------------------------------------
           LDW     .D1T1   *A3,A0            ; |865| 
           NOP             4
   [!A0]   BNOP    .S1     $C$L117,5         ; |865| 
           ; BRANCHCC OCCURS {$C$L117}       ; |865| 
$C$DW$L$_Sv_Msg__FPv$5$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_Sv_Msg__FPv$6$B:
	.dwpsn	file "test_c.cpp",line 866,column 2,is_stmt
;----------------------------------------------------------------------
; 867 | uint32 FileNet = 0;                                                    
;----------------------------------------------------------------------
	.dwpsn	file "test_c.cpp",line 868,column 5,is_stmt
;----------------------------------------------------------------------
; 869 | memset(buf55, 0x55, sizeof(buf55));                                    
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+388,A3
           MVKH    .S1     ___syscall_tab+388,A3
           LDW     .D1T1   *A3,A3            ; |868| 
           ADD     .D2     SP,24,B5          ; |868| 
           MVK     .S2     0x2710,B4         ; |868| 
           MV      .L1X    B5,A4             ; |868| 
           NOP             1
$C$DW$496	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$496, DW_AT_low_pc(0x00)
	.dwattr $C$DW$496, DW_AT_TI_call
	.dwattr $C$DW$496, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |868| 
           ADDKPC  .S2     $C$RL75,B3,4      ; |868| 
$C$RL75:   ; CALL OCCURS {A3} {0}            ; |868| 
           STW     .D2T1   A4,*+SP(8)        ; |868| 
	.dwpsn	file "test_c.cpp",line 870,column 5,is_stmt
;----------------------------------------------------------------------
; 870 | memset(bufAA, 0xAA, sizeof(bufAA));                                    
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(24),B0       ; |870| 
           NOP             4
   [ B0]   BNOP    .S1     $C$L82,5          ; |870| 
           ; BRANCHCC OCCURS {$C$L82}        ; |870| 
$C$DW$L$_Sv_Msg__FPv$6$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_Sv_Msg__FPv$7$B:
	.dwpsn	file "test_c.cpp",line 872,column 2,is_stmt
           MVKL    .S1     ___syscall_tab+48,A3
           MVKH    .S1     ___syscall_tab+48,A3
           LDW     .D1T1   *A3,A3            ; |872| 
           NOP             4
$C$DW$497	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$497, DW_AT_low_pc(0x00)
	.dwattr $C$DW$497, DW_AT_TI_call
	.dwattr $C$DW$497, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |872| 
           ADDKPC  .S2     $C$RL76,B3,4      ; |872| 
$C$RL76:   ; CALL OCCURS {A3} {0}            ; |872| 
	.dwpsn	file "test_c.cpp",line 873,column 5,is_stmt
;----------------------------------------------------------------------
; 873 | error = msg_open("sv");                                                
; 874 | if(error != OSE_OK)                                                    
;----------------------------------------------------------------------
           BNOP    .S1     $C$L116,5         ; |873| 
           ; BRANCH OCCURS {$C$L116}         ; |873| 
$C$DW$L$_Sv_Msg__FPv$7$E:
;** --------------------------------------------------------------------------*
$C$L82:    
$C$DW$L$_Sv_Msg__FPv$8$B:
	.dwpsn	file "test_c.cpp",line 875,column 5,is_stmt
;----------------------------------------------------------------------
; 875 | while(1);                                                              
;----------------------------------------------------------------------
           MV      .L2     B0,B4
           LDW     .D2T2   *+B4(20),B4       ; |875| 
           NOP             4
           CMPEQ   .L2     B4,4,B0           ; |875| 
   [ B0]   BNOP    .S1     $C$L83,5          ; |875| 
           ; BRANCHCC OCCURS {$C$L83}        ; |875| 
$C$DW$L$_Sv_Msg__FPv$8$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_Sv_Msg__FPv$9$B:
	.dwpsn	file "test_c.cpp",line 877,column 7,is_stmt
;----------------------------------------------------------------------
; 877 | while(sv_msg_open)                                                     
;----------------------------------------------------------------------
           MVKL    .S2     0xd0026,B4
           MVKH    .S2     0xd0026,B4
           STW     .D2T2   B4,*+SP(16)       ; |877| 
	.dwpsn	file "test_c.cpp",line 878,column 7,is_stmt
           MVK     .L2     1,B4              ; |878| 
           STW     .D2T2   B4,*+SP(20)       ; |878| 
	.dwpsn	file "test_c.cpp",line 879,column 7,is_stmt
           MVKL    .S2     ___syscall_tab+384,B5
           MVKH    .S2     ___syscall_tab+384,B5
           LDW     .D2T2   *B5,B5            ; |879| 
           LDW     .D2T2   *+SP(24),B4       ; |879| 
           MVK     .L1     0x8,A6            ; |879| 
           NOP             2
$C$DW$498	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$498, DW_AT_low_pc(0x00)
	.dwattr $C$DW$498, DW_AT_TI_call
	.dwattr $C$DW$498, DW_AT_TI_indirect
           CALL    .S2     B5                ; |879| 
           LDW     .D2T1   *+B4(12),A4       ; |879| 
           ADDKPC  .S2     $C$RL77,B3,2      ; |879| 
           ADD     .D2     SP,16,B4          ; |879| 
$C$RL77:   ; CALL OCCURS {B5} {0}            ; |879| 
	.dwpsn	file "test_c.cpp",line 880,column 7,is_stmt
;----------------------------------------------------------------------
; 880 | if(sv_msg_open == 0)                                                   
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+404,A3
           MVKH    .S1     ___syscall_tab+404,A3
           LDW     .D1T1   *A3,A3            ; |880| 
           LDW     .D2T1   *+SP(24),A4       ; |880| 
           NOP             3
$C$DW$499	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$499, DW_AT_low_pc(0x00)
	.dwattr $C$DW$499, DW_AT_TI_call
	.dwattr $C$DW$499, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |880| 
           ADDKPC  .S2     $C$RL78,B3,4      ; |880| 
$C$RL78:   ; CALL OCCURS {A3} {0}            ; |880| 
	.dwpsn	file "test_c.cpp",line 881,column 7,is_stmt
;----------------------------------------------------------------------
; 881 | break;                                                                 
;----------------------------------------------------------------------
           BNOP    .S1     $C$L116,5         ; |881| 
           ; BRANCH OCCURS {$C$L116}         ; |881| 
$C$DW$L$_Sv_Msg__FPv$9$E:
;** --------------------------------------------------------------------------*
$C$L83:    
$C$DW$L$_Sv_Msg__FPv$10$B:
	.dwpsn	file "test_c.cpp",line 883,column 5,is_stmt
;----------------------------------------------------------------------
; 883 | error = msg_recv(&msg_desc, MSG_WAIT_10);                              
;----------------------------------------------------------------------
           LDW     .D2T1   *+SP(24),A3       ; |883| 
           NOP             4
           LDW     .D1T1   *+A3(12),A3       ; |883| 
           NOP             4
           STW     .D2T1   A3,*+SP(12)       ; |883| 
	.dwpsn	file "test_c.cpp",line 884,column 5,is_stmt
           LDW     .D2T2   *+SP(24),B4       ; |884| 
           NOP             4
           LDW     .D2T2   *+B4(24),B4       ; |884| 
           NOP             4
           LDW     .D2T2   *B4,B4            ; |884| 
           NOP             4
           STW     .D2T2   B4,*+SP(16)       ; |884| 
	.dwpsn	file "test_c.cpp",line 885,column 5,is_stmt
;----------------------------------------------------------------------
; 885 | if(msg_desc == NULL)                                                   
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+404,A3
           MVKH    .S1     ___syscall_tab+404,A3
           LDW     .D1T1   *A3,A3            ; |885| 
           LDW     .D2T1   *+SP(24),A4       ; |885| 
           NOP             3
$C$DW$500	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$500, DW_AT_low_pc(0x00)
	.dwattr $C$DW$500, DW_AT_TI_call
	.dwattr $C$DW$500, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |885| 
           ADDKPC  .S2     $C$RL79,B3,4      ; |885| 
$C$RL79:   ; CALL OCCURS {A3} {0}            ; |885| 
	.dwpsn	file "test_c.cpp",line 886,column 5,is_stmt
;----------------------------------------------------------------------
; 887 | prc_yield();                                                           
; 888 | continue;                                                              
;----------------------------------------------------------------------
           BNOP    .S1     $C$L115,5         ; |886| 
           ; BRANCH OCCURS {$C$L115}         ; |886| 
$C$DW$L$_Sv_Msg__FPv$10$E:
;** --------------------------------------------------------------------------*
;** --------------------------------------------------------------------------*
$C$L84:    
$C$DW$L$_Sv_Msg__FPv$12$B:

$C$DW$501	.dwtag  DW_TAG_lexical_block, DW_AT_low_pc(0x00), DW_AT_high_pc(0x00)
$C$DW$502	.dwtag  DW_TAG_variable, DW_AT_name("result")
	.dwattr $C$DW$502, DW_AT_TI_symbol_name("_result")
	.dwattr $C$DW$502, DW_AT_type(*$C$DW$T$398)
	.dwattr $C$DW$502, DW_AT_location[DW_OP_breg31 9184]
	.dwpsn	file "test_c.cpp",line 890,column 3,is_stmt
;----------------------------------------------------------------------
; 890 | if(msg_desc->length != sizeof(kdg_cmd))                                
;----------------------------------------------------------------------
           ZERO    .L2     B4                ; |890| 
           STW     .D2T2   B4,*+SP(20)       ; |890| 
	.dwpsn	file "test_c.cpp",line 891,column 9,is_stmt
;----------------------------------------------------------------------
; 892 | cdg_error.cmd = ERROR_CMD;                                             
; 893 | cdg_error.ask = TPO_ERR;                                               
; 894 | msg_send(msg_desc->from, &cdg_error, sizeof(kdg_cmd_ask));             
;----------------------------------------------------------------------
           MVKL    .S2     ___syscall_tab+384,B4
           MVKH    .S2     ___syscall_tab+384,B4
           LDW     .D2T2   *B4,B5            ; |891| 
           LDW     .D2T1   *+SP(12),A4       ; |891| 
           ADD     .D2     SP,16,B4          ; |891| 
           MVK     .L1     0x8,A6            ; |891| 
           NOP             1
$C$DW$503	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$503, DW_AT_low_pc(0x00)
	.dwattr $C$DW$503, DW_AT_TI_call
	.dwattr $C$DW$503, DW_AT_TI_indirect
           CALL    .S2     B5                ; |891| 
           ADDKPC  .S2     $C$RL80,B3,4      ; |891| 
$C$RL80:   ; CALL OCCURS {B5} {0}            ; |891| 
	.dwpsn	file "test_c.cpp",line 895,column 3,is_stmt
;----------------------------------------------------------------------
; 895 | msg_free(msg_desc);                                                    
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+388,A3
           MVKH    .S1     ___syscall_tab+388,A3
           LDW     .D1T1   *A3,A3            ; |895| 
           ADD     .D2     SP,24,B5          ; |895| 
           MVK     .S2     0x2710,B4         ; |895| 
           MV      .L1X    B5,A4             ; |895| 
           NOP             1
$C$DW$504	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$504, DW_AT_low_pc(0x00)
	.dwattr $C$DW$504, DW_AT_TI_call
	.dwattr $C$DW$504, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |895| 
           ADDKPC  .S2     $C$RL81,B3,4      ; |895| 
$C$RL81:   ; CALL OCCURS {A3} {0}            ; |895| 
           STW     .D2T1   A4,*+SP(8)        ; |895| 
	.dwpsn	file "test_c.cpp",line 896,column 6,is_stmt
;----------------------------------------------------------------------
; 896 | continue;                                                              
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(24),B0       ; |896| 
           NOP             4
   [!B0]   BNOP    .S1     $C$L116,5         ; |896| 
           ; BRANCHCC OCCURS {$C$L116}       ; |896| 
$C$DW$L$_Sv_Msg__FPv$12$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_Sv_Msg__FPv$13$B:
	.dwpsn	file "test_c.cpp",line 896,column 27,is_stmt
	.dwpsn	file "test_c.cpp",line 897,column 6,is_stmt
;----------------------------------------------------------------------
; 898 | msg_from = msg_desc->from;                                             
;----------------------------------------------------------------------
           MV      .L2     B0,B4
           LDW     .D2T2   *+B4(20),B4       ; |897| 
           MVK     .S2     60,B5             ; |897| 
           NOP             3
           CMPEQ   .L2     B4,B5,B0          ; |897| 
   [ B0]   BNOP    .S1     $C$L85,5          ; |897| 
           ; BRANCHCC OCCURS {$C$L85}        ; |897| 
$C$DW$L$_Sv_Msg__FPv$13$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_Sv_Msg__FPv$14$B:
	.dwpsn	file "test_c.cpp",line 899,column 8,is_stmt
;----------------------------------------------------------------------
; 899 | cdg_error.cmd = ((kdg_cmd*)msg_desc->data)->cmd;                       
;----------------------------------------------------------------------
           MVKL    .S2     0xd0026,B4
           MVKH    .S2     0xd0026,B4
           STW     .D2T2   B4,*+SP(16)       ; |899| 
	.dwpsn	file "test_c.cpp",line 900,column 5,is_stmt
;----------------------------------------------------------------------
; 900 | msg_free(msg_desc);                                                    
;----------------------------------------------------------------------
           MVK     .L2     1,B4              ; |900| 
           STW     .D2T2   B4,*+SP(20)       ; |900| 
	.dwpsn	file "test_c.cpp",line 901,column 8,is_stmt
;----------------------------------------------------------------------
; 901 | switch (cdg_error.cmd)                                                 
;----------------------------------------------------------------------
           MVKL    .S2     ___syscall_tab+384,B5
           MVKH    .S2     ___syscall_tab+384,B5
           LDW     .D2T2   *B5,B5            ; |901| 
           LDW     .D2T2   *+SP(24),B4       ; |901| 
           MVK     .L1     0x8,A6            ; |901| 
           NOP             2
$C$DW$505	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$505, DW_AT_low_pc(0x00)
	.dwattr $C$DW$505, DW_AT_TI_call
	.dwattr $C$DW$505, DW_AT_TI_indirect
           CALL    .S2     B5                ; |901| 
           LDW     .D2T1   *+B4(12),A4       ; |901| 
           ADDKPC  .S2     $C$RL82,B3,2      ; |901| 
           ADD     .D2     SP,16,B4          ; |901| 
$C$RL82:   ; CALL OCCURS {B5} {0}            ; |901| 
	.dwpsn	file "test_c.cpp",line 902,column 8,is_stmt
           MVKL    .S1     ___syscall_tab+404,A3
           MVKH    .S1     ___syscall_tab+404,A3
           LDW     .D1T1   *A3,A3            ; |902| 
           LDW     .D2T1   *+SP(24),A4       ; |902| 
           NOP             3
$C$DW$506	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$506, DW_AT_low_pc(0x00)
	.dwattr $C$DW$506, DW_AT_TI_call
	.dwattr $C$DW$506, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |902| 
           ADDKPC  .S2     $C$RL83,B3,4      ; |902| 
$C$RL83:   ; CALL OCCURS {A3} {0}            ; |902| 
	.dwpsn	file "test_c.cpp",line 903,column 8,is_stmt
;----------------------------------------------------------------------
; 903 | case N_TEST:                                                           
;----------------------------------------------------------------------
           BNOP    .S1     $C$L116,5         ; |903| 
           ; BRANCH OCCURS {$C$L116}         ; |903| 
$C$DW$L$_Sv_Msg__FPv$14$E:
;** --------------------------------------------------------------------------*
$C$L85:    
$C$DW$L$_Sv_Msg__FPv$15$B:
	.dwpsn	file "test_c.cpp",line 905,column 3,is_stmt
;----------------------------------------------------------------------
; 905 | cdg_error.ask = TPO_OK;                                                
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(24),B4       ; |905| 
           MVK     .S2     9184,B5           ; |905| 
           ADD     .L2     B5,SP,B5          ; |905| 
           MVK     .S1     0x3c,A6           ; |905| 
$C$DW$507	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$507, DW_AT_low_pc(0x00)
	.dwattr $C$DW$507, DW_AT_name("_memcpy")
	.dwattr $C$DW$507, DW_AT_TI_call
           CALL    .S1     _memcpy           ; |905| 
           LDW     .D2T2   *+B4(24),B4       ; |905| 
           MV      .L1X    B5,A4             ; |905| 
           ADDKPC  .S2     $C$RL84,B3,2      ; |905| 
$C$RL84:   ; CALL OCCURS {_memcpy} {0}       ; |905| 
	.dwpsn	file "test_c.cpp",line 906,column 6,is_stmt
;----------------------------------------------------------------------
; 906 | msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));                   
;----------------------------------------------------------------------
           MVKL    .S2     ___syscall_tab+404,B4
           MVKH    .S2     ___syscall_tab+404,B4
           LDW     .D2T2   *B4,B4            ; |906| 
           LDW     .D2T1   *+SP(24),A4       ; |906| 
           NOP             3
$C$DW$508	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$508, DW_AT_low_pc(0x00)
	.dwattr $C$DW$508, DW_AT_TI_call
	.dwattr $C$DW$508, DW_AT_TI_indirect
           CALL    .S2     B4                ; |906| 
           ADDKPC  .S2     $C$RL85,B3,4      ; |906| 
$C$RL85:   ; CALL OCCURS {B4} {0}            ; |906| 
	.dwpsn	file "test_c.cpp",line 908,column 9,is_stmt
;----------------------------------------------------------------------
; 908 | kdg_rez_test result;                                                   
;----------------------------------------------------------------------
$C$DW$509	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$509, DW_AT_low_pc(0x00)
	.dwattr $C$DW$509, DW_AT_name("_Start_Test_N__FP12kdg_rez_test")
	.dwattr $C$DW$509, DW_AT_TI_call
           CALL    .S1     _Start_Test_N__FP12kdg_rez_test ; |908| 
           MVK     .S1     9184,A3           ; |908| 
           ADD     .L1X    A3,SP,A4          ; |908| 
           ADDKPC  .S2     $C$RL86,B3,2      ; |908| 
$C$RL86:   ; CALL OCCURS {_Start_Test_N__FP12kdg_rez_test} {0}  ; |908| 
	.dwpsn	file "test_c.cpp",line 909,column 3,is_stmt
           MVKL    .S2     0xd0008,B4
           MVKH    .S2     0xd0008,B4
           STW     .D2T2   B4,*+SP(9184)     ; |909| 
	.dwpsn	file "test_c.cpp",line 910,column 9,is_stmt
;----------------------------------------------------------------------
; 910 | error = msg_recv(&msg_desc, MSG_WAIT_10);                              
; 911 | if(msg_desc == NULL) continue;                                         
; 912 | if(msg_desc->length != sizeof(kdg_rez_test))                           
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+384,A3
           MVKH    .S1     ___syscall_tab+384,A3
           LDW     .D1T1   *A3,A3            ; |910| 
           LDW     .D2T1   *+SP(12),A4       ; |910| 
           MVK     .S2     9184,B4           ; |910| 
           ADD     .L2     B4,SP,B4          ; |910| 
           MVK     .S1     0x3c,A6           ; |910| 
$C$DW$510	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$510, DW_AT_low_pc(0x00)
	.dwattr $C$DW$510, DW_AT_TI_call
	.dwattr $C$DW$510, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |910| 
           ADDKPC  .S2     $C$RL87,B3,4      ; |910| 
$C$RL87:   ; CALL OCCURS {A3} {0}            ; |910| 
	.dwendtag $C$DW$501

	.dwpsn	file "test_c.cpp",line 914,column 12,is_stmt
;----------------------------------------------------------------------
; 914 | cdg_error.cmd = ERROR_CMD;                                             
; 915 |     cdg_error.ask = TPO_ERR;                                           
; 916 | msg_send(msg_desc->from, &cdg_error, sizeof(kdg_cmd_ask));             
; 917 | msg_free(msg_desc);                                                    
;----------------------------------------------------------------------
           BNOP    .S1     $C$L116,5         ; |914| 
           ; BRANCH OCCURS {$C$L116}         ; |914| 
$C$DW$L$_Sv_Msg__FPv$15$E:
;** --------------------------------------------------------------------------*
$C$L86:    
$C$DW$L$_Sv_Msg__FPv$16$B:
	.dwpsn	file "test_c.cpp",line 918,column 3,is_stmt
;----------------------------------------------------------------------
; 918 | continue;                                                              
;----------------------------------------------------------------------
           MVKL    .S2     0xd001a,B4
           MVKH    .S2     0xd001a,B4
           STW     .D2T2   B4,*+SP(20)       ; |918| 
	.dwpsn	file "test_c.cpp",line 920,column 9,is_stmt
;----------------------------------------------------------------------
; 920 | memcpy(&result, msg_desc->data, sizeof(kdg_rez_test));                 
; 921 | msg_free(msg_desc);                                                    
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+384,A3
           MVKH    .S1     ___syscall_tab+384,A3
           LDW     .D1T1   *A3,A3            ; |920| 
           LDW     .D2T1   *+SP(12),A4       ; |920| 
           ADD     .D2     SP,16,B4          ; |920| 
           MVK     .L1     0x8,A6            ; |920| 
           NOP             1
$C$DW$511	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$511, DW_AT_low_pc(0x00)
	.dwattr $C$DW$511, DW_AT_TI_call
	.dwattr $C$DW$511, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |920| 
           ADDKPC  .S2     $C$RL88,B3,4      ; |920| 
$C$RL88:   ; CALL OCCURS {A3} {0}            ; |920| 
	.dwpsn	file "test_c.cpp",line 923,column 3,is_stmt
;----------------------------------------------------------------------
; 923 | Start_Test_N(&result);                                                 
;----------------------------------------------------------------------
$C$DW$512	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$512, DW_AT_low_pc(0x00)
	.dwattr $C$DW$512, DW_AT_name("_ReadDARAM_CRYPT0__FUsPvT1")
	.dwattr $C$DW$512, DW_AT_TI_call
           CALL    .S1     _ReadDARAM_CRYPT0__FUsPvT1 ; |923| 
           MVK     .S2     3104,B4           ; |923| 
           ADDKPC  .S2     $C$RL89,B3,2      ; |923| 

           ADD     .L2     B4,SP,B4          ; |923| 
||         ZERO    .L1     A4                ; |923| 
||         MVK     .S1     0x600,A6          ; |923| 

$C$RL89:   ; CALL OCCURS {_ReadDARAM_CRYPT0__FUsPvT1} {0}  ; |923| 
	.dwpsn	file "test_c.cpp",line 924,column 3,is_stmt
;----------------------------------------------------------------------
; 924 | result.cmd = RES_N_TEST;                                               
;----------------------------------------------------------------------
$C$DW$513	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$513, DW_AT_low_pc(0x00)
	.dwattr $C$DW$513, DW_AT_name("_ReadDARAM_CRYPT1__FUsPvT1")
	.dwattr $C$DW$513, DW_AT_TI_call
           CALL    .S1     _ReadDARAM_CRYPT1__FUsPvT1 ; |924| 
           MVK     .S2     4640,B4           ; |924| 
           ADDKPC  .S2     $C$RL90,B3,2      ; |924| 

           ADD     .L2     B4,SP,B4          ; |924| 
||         ZERO    .L1     A4                ; |924| 
||         MVK     .S1     0x600,A6          ; |924| 

$C$RL90:   ; CALL OCCURS {_ReadDARAM_CRYPT1__FUsPvT1} {0}  ; |924| 
	.dwpsn	file "test_c.cpp",line 925,column 3,is_stmt
;----------------------------------------------------------------------
; 925 | msg_send(msg_from, &result, sizeof(kdg_rez_test));                     
;----------------------------------------------------------------------
$C$DW$514	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$514, DW_AT_low_pc(0x00)
	.dwattr $C$DW$514, DW_AT_name("_WriteDARAM__FUsPvT1")
	.dwattr $C$DW$514, DW_AT_TI_call
           CALL    .S1     _WriteDARAM__FUsPvT1 ; |925| 
           MVK     .S2     1568,B4           ; |925| 
           ADDKPC  .S2     $C$RL91,B3,2      ; |925| 

           ADD     .L2     B4,SP,B4          ; |925| 
||         ZERO    .L1     A4                ; |925| 
||         MVK     .S1     0x600,A6          ; |925| 

$C$RL91:   ; CALL OCCURS {_WriteDARAM__FUsPvT1} {0}  ; |925| 
	.dwpsn	file "test_c.cpp",line 928,column 3,is_stmt
$C$DW$515	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$515, DW_AT_low_pc(0x00)
	.dwattr $C$DW$515, DW_AT_name("_memcmp")
	.dwattr $C$DW$515, DW_AT_TI_call
           CALL    .S1     _memcmp           ; |928| 
           ADDAD   .D2     SP,4,B4           ; |928| 
           MVK     .S2     3104,B5           ; |928| 
           MV      .L1X    B4,A4             ; |928| 
           ADD     .L2     B5,SP,B4          ; |928| 
           ADDKPC  .S2     $C$RL92,B3,0      ; |928| 
$C$RL92:   ; CALL OCCURS {_memcmp} {0}       ; |928| 
           MV      .L1     A4,A0             ; |928| 
   [!A0]   BNOP    .S1     $C$L87,5          ; |928| 
           ; BRANCHCC OCCURS {$C$L87}        ; |928| 
$C$DW$L$_Sv_Msg__FPv$16$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_Sv_Msg__FPv$17$B:
	.dwpsn	file "test_c.cpp",line 929,column 4,is_stmt
;----------------------------------------------------------------------
; 929 | break;                                                                 
;----------------------------------------------------------------------
           MVKL    .S1     _gl_result+16,A3
           MVKH    .S1     _gl_result+16,A3
           LDW     .D1T1   *A3,A4            ; |929| 
           NOP             4
           ADD     .L1     1,A4,A4           ; |929| 
           STW     .D1T1   A4,*A3            ; |929| 
$C$DW$L$_Sv_Msg__FPv$17$E:
;** --------------------------------------------------------------------------*
$C$L87:    
$C$DW$L$_Sv_Msg__FPv$18$B:
	.dwpsn	file "test_c.cpp",line 930,column 3,is_stmt
$C$DW$516	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$516, DW_AT_low_pc(0x00)
	.dwattr $C$DW$516, DW_AT_name("_memcmp")
	.dwattr $C$DW$516, DW_AT_TI_call
           CALL    .S1     _memcmp           ; |930| 
           ADDAD   .D2     SP,4,B4           ; |930| 
           MVK     .S2     4640,B5           ; |930| 
           MV      .L1X    B4,A4             ; |930| 
           ADD     .L2     B5,SP,B4          ; |930| 

           ADDKPC  .S2     $C$RL93,B3,0      ; |930| 
||         MVK     .S1     0x600,A6          ; |930| 

$C$RL93:   ; CALL OCCURS {_memcmp} {0}       ; |930| 
           MV      .L1     A4,A0             ; |930| 
   [!A0]   BNOP    .S1     $C$L88,5          ; |930| 
           ; BRANCHCC OCCURS {$C$L88}        ; |930| 
$C$DW$L$_Sv_Msg__FPv$18$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_Sv_Msg__FPv$19$B:
	.dwpsn	file "test_c.cpp",line 931,column 4,is_stmt
;----------------------------------------------------------------------
; 931 | case GOTOV_TEST_MOVE_15:                                               
;----------------------------------------------------------------------
           MVKL    .S1     _gl_result+20,A3
           MVKH    .S1     _gl_result+20,A3
           LDW     .D1T1   *A3,A4            ; |931| 
           NOP             4
           ADD     .L1     1,A4,A4           ; |931| 
           STW     .D1T1   A4,*A3            ; |931| 
$C$DW$L$_Sv_Msg__FPv$19$E:
;** --------------------------------------------------------------------------*
$C$L88:    
$C$DW$L$_Sv_Msg__FPv$20$B:
	.dwpsn	file "test_c.cpp",line 933,column 3,is_stmt
;----------------------------------------------------------------------
; 933 | cdg_error.ask = GOTOV_TEST_MOVE_15;                                    
; 935 | msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));                   
;----------------------------------------------------------------------
           MVKL    .S1     _gl_result+4,A3
           MVKH    .S1     _gl_result+4,A3
           LDW     .D1T1   *A3,A4            ; |933| 
           NOP             4
           ADD     .L1     1,A4,A4           ; |933| 
           STW     .D1T1   A4,*A3            ; |933| 
	.dwpsn	file "test_c.cpp",line 936,column 12,is_stmt
;----------------------------------------------------------------------
; 936 | //      prc_yield();                                                   
; 938 | ReadDARAM_CRYPT0(0,buf1,sizeof(buf1));                                 
; 939 | ReadDARAM_CRYPT1(0,buf2,sizeof(buf2));                                 
; 940 | WriteDARAM(0, bufAA, sizeof(bufAA));                                   
;----------------------------------------------------------------------
           BNOP    .S1     $C$L116,5         ; |936| 
           ; BRANCH OCCURS {$C$L116}         ; |936| 
$C$DW$L$_Sv_Msg__FPv$20$E:
;** --------------------------------------------------------------------------*
$C$L89:    
$C$DW$L$_Sv_Msg__FPv$21$B:
	.dwpsn	file "test_c.cpp",line 941,column 3,is_stmt
           MVKL    .S2     0xd001b,B4
           MVKH    .S2     0xd001b,B4
           STW     .D2T2   B4,*+SP(20)       ; |941| 
	.dwpsn	file "test_c.cpp",line 943,column 9,is_stmt
;----------------------------------------------------------------------
; 943 | if(memcmp(buf55, buf1, sizeof(buf1)))                                  
; 944 |         gl_result.data++;                                              
; 945 | if(memcmp(buf55, buf2, sizeof(buf2)))                                  
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+384,A3
           MVKH    .S1     ___syscall_tab+384,A3
           LDW     .D1T1   *A3,A3            ; |943| 
           LDW     .D2T1   *+SP(12),A4       ; |943| 
           ADD     .D2     SP,16,B4          ; |943| 
           MVK     .L1     0x8,A6            ; |943| 
           NOP             1
$C$DW$517	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$517, DW_AT_low_pc(0x00)
	.dwattr $C$DW$517, DW_AT_TI_call
	.dwattr $C$DW$517, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |943| 
           ADDKPC  .S2     $C$RL94,B3,4      ; |943| 
$C$RL94:   ; CALL OCCURS {A3} {0}            ; |943| 
	.dwpsn	file "test_c.cpp",line 946,column 3,is_stmt
;----------------------------------------------------------------------
; 946 | gl_result.data1++;                                                     
;----------------------------------------------------------------------
$C$DW$518	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$518, DW_AT_low_pc(0x00)
	.dwattr $C$DW$518, DW_AT_name("_ReadDARAM_CRYPT0__FUsPvT1")
	.dwattr $C$DW$518, DW_AT_TI_call
           CALL    .S1     _ReadDARAM_CRYPT0__FUsPvT1 ; |946| 
           MVK     .S2     3104,B4           ; |946| 
           ADDKPC  .S2     $C$RL95,B3,2      ; |946| 

           ADD     .L2     B4,SP,B4          ; |946| 
||         ZERO    .L1     A4                ; |946| 
||         MVK     .S1     0x600,A6          ; |946| 

$C$RL95:   ; CALL OCCURS {_ReadDARAM_CRYPT0__FUsPvT1} {0}  ; |946| 
	.dwpsn	file "test_c.cpp",line 947,column 3,is_stmt
$C$DW$519	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$519, DW_AT_low_pc(0x00)
	.dwattr $C$DW$519, DW_AT_name("_ReadDARAM_CRYPT1__FUsPvT1")
	.dwattr $C$DW$519, DW_AT_TI_call
           CALL    .S1     _ReadDARAM_CRYPT1__FUsPvT1 ; |947| 
           MVK     .S2     4640,B4           ; |947| 
           ADDKPC  .S2     $C$RL96,B3,2      ; |947| 

           ADD     .L2     B4,SP,B4          ; |947| 
||         ZERO    .L1     A4                ; |947| 
||         MVK     .S1     0x600,A6          ; |947| 

$C$RL96:   ; CALL OCCURS {_ReadDARAM_CRYPT1__FUsPvT1} {0}  ; |947| 
	.dwpsn	file "test_c.cpp",line 948,column 3,is_stmt
;----------------------------------------------------------------------
; 948 | gl_result.n_test++;                                                    
; 951 | break;                                                                 
;----------------------------------------------------------------------
$C$DW$520	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$520, DW_AT_low_pc(0x00)
	.dwattr $C$DW$520, DW_AT_name("_WriteDARAM__FUsPvT1")
	.dwattr $C$DW$520, DW_AT_TI_call
           CALL    .S1     _WriteDARAM__FUsPvT1 ; |948| 
           ADDKPC  .S2     $C$RL97,B3,3      ; |948| 

           ZERO    .L1     A4                ; |948| 
||         ADDAD   .D2     SP,4,B4           ; |948| 
||         MVK     .S1     0x600,A6          ; |948| 

$C$RL97:   ; CALL OCCURS {_WriteDARAM__FUsPvT1} {0}  ; |948| 
	.dwpsn	file "test_c.cpp",line 952,column 3,is_stmt
$C$DW$521	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$521, DW_AT_low_pc(0x00)
	.dwattr $C$DW$521, DW_AT_name("_memcmp")
	.dwattr $C$DW$521, DW_AT_TI_call
           CALL    .S1     _memcmp           ; |952| 
           MVK     .S2     1568,B4           ; |952| 
           ADD     .L2     B4,SP,B4          ; |952| 
           MVK     .S2     3104,B5           ; |952| 
           MV      .L1X    B4,A4             ; |952| 

           ADD     .L2     B5,SP,B4          ; |952| 
||         ADDKPC  .S2     $C$RL98,B3,0      ; |952| 

$C$RL98:   ; CALL OCCURS {_memcmp} {0}       ; |952| 
           MV      .L1     A4,A0             ; |952| 
   [!A0]   BNOP    .S1     $C$L90,5          ; |952| 
           ; BRANCHCC OCCURS {$C$L90}        ; |952| 
$C$DW$L$_Sv_Msg__FPv$21$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_Sv_Msg__FPv$22$B:
	.dwpsn	file "test_c.cpp",line 953,column 4,is_stmt
           MVKL    .S1     _gl_result+16,A3
           MVKH    .S1     _gl_result+16,A3
           LDW     .D1T1   *A3,A4            ; |953| 
           NOP             4
           ADD     .L1     1,A4,A4           ; |953| 
           STW     .D1T1   A4,*A3            ; |953| 
$C$DW$L$_Sv_Msg__FPv$22$E:
;** --------------------------------------------------------------------------*
$C$L90:    
$C$DW$L$_Sv_Msg__FPv$23$B:
	.dwpsn	file "test_c.cpp",line 954,column 3,is_stmt
;----------------------------------------------------------------------
; 954 | case GOTOV_TEST_MOVE_1A:                                               
;----------------------------------------------------------------------
$C$DW$522	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$522, DW_AT_low_pc(0x00)
	.dwattr $C$DW$522, DW_AT_name("_memcmp")
	.dwattr $C$DW$522, DW_AT_TI_call
           CALL    .S1     _memcmp           ; |954| 
           MVK     .S2     1568,B4           ; |954| 
           ADD     .L2     B4,SP,B4          ; |954| 
           MVK     .S1     4640,A3           ; |954| 
           MV      .L1X    B4,A4             ; |954| 

           ADD     .L2X    A3,SP,B4          ; |954| 
||         ADDKPC  .S2     $C$RL99,B3,0      ; |954| 
||         MVK     .S1     0x600,A6          ; |954| 

$C$RL99:   ; CALL OCCURS {_memcmp} {0}       ; |954| 
           MV      .L1     A4,A0             ; |954| 
   [!A0]   BNOP    .S1     $C$L91,5          ; |954| 
           ; BRANCHCC OCCURS {$C$L91}        ; |954| 
$C$DW$L$_Sv_Msg__FPv$23$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_Sv_Msg__FPv$24$B:
	.dwpsn	file "test_c.cpp",line 955,column 4,is_stmt
;----------------------------------------------------------------------
; 956 | cdg_error.ask = GOTOV_TEST_MOVE_1A;                                    
;----------------------------------------------------------------------
           MVKL    .S1     _gl_result+20,A3
           MVKH    .S1     _gl_result+20,A3
           LDW     .D1T1   *A3,A4            ; |955| 
           NOP             4
           ADD     .L1     1,A4,A4           ; |955| 
           STW     .D1T1   A4,*A3            ; |955| 
$C$DW$L$_Sv_Msg__FPv$24$E:
;** --------------------------------------------------------------------------*
$C$L91:    
$C$DW$L$_Sv_Msg__FPv$25$B:
	.dwpsn	file "test_c.cpp",line 957,column 3,is_stmt
;----------------------------------------------------------------------
; 958 | msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));                   
; 959 | //      prc_yield();                                                   
;----------------------------------------------------------------------
           MVKL    .S1     _gl_result+4,A3
           MVKH    .S1     _gl_result+4,A3
           LDW     .D1T1   *A3,A4            ; |957| 
           NOP             4
           ADD     .L1     1,A4,A4           ; |957| 
           STW     .D1T1   A4,*A3            ; |957| 
	.dwpsn	file "test_c.cpp",line 960,column 12,is_stmt
;----------------------------------------------------------------------
; 961 | ReadDARAM_CRYPT0(0,buf1,sizeof(buf1));                                 
; 962 | ReadDARAM_CRYPT1(0,buf2,sizeof(buf2));                                 
; 963 | WriteDARAM(0, buf55, sizeof(buf55));                                   
;----------------------------------------------------------------------
           BNOP    .S1     $C$L116,5         ; |960| 
           ; BRANCH OCCURS {$C$L116}         ; |960| 
$C$DW$L$_Sv_Msg__FPv$25$E:
;** --------------------------------------------------------------------------*
$C$L92:    
$C$DW$L$_Sv_Msg__FPv$26$B:
	.dwpsn	file "test_c.cpp",line 965,column 3,is_stmt
;----------------------------------------------------------------------
; 965 | //uint32 tsk = Test_SK();                                              
;----------------------------------------------------------------------
           MVKL    .S2     0xd001c,B4
           MVKH    .S2     0xd001c,B4
           STW     .D2T2   B4,*+SP(20)       ; |965| 
	.dwpsn	file "test_c.cpp",line 967,column 9,is_stmt
;----------------------------------------------------------------------
; 967 | if(memcmp(bufAA, buf1, sizeof(buf1)))                                  
; 968 |         gl_result.data++;                                              
; 969 | if(memcmp(bufAA, buf2, sizeof(buf2)))                                  
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+384,A3
           MVKH    .S1     ___syscall_tab+384,A3
           LDW     .D1T1   *A3,A3            ; |967| 
           LDW     .D2T1   *+SP(12),A4       ; |967| 
           ADD     .D2     SP,16,B4          ; |967| 
           MVK     .L1     0x8,A6            ; |967| 
           NOP             1
$C$DW$523	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$523, DW_AT_low_pc(0x00)
	.dwattr $C$DW$523, DW_AT_TI_call
	.dwattr $C$DW$523, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |967| 
           ADDKPC  .S2     $C$RL100,B3,4     ; |967| 
$C$RL100:  ; CALL OCCURS {A3} {0}            ; |967| 
	.dwpsn	file "test_c.cpp",line 970,column 3,is_stmt
;----------------------------------------------------------------------
; 970 | gl_result.data1++;                                                     
;----------------------------------------------------------------------
$C$DW$524	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$524, DW_AT_low_pc(0x00)
	.dwattr $C$DW$524, DW_AT_name("_ReadDARAM_CRYPT0__FUsPvT1")
	.dwattr $C$DW$524, DW_AT_TI_call
           CALL    .S1     _ReadDARAM_CRYPT0__FUsPvT1 ; |970| 
           MVK     .S2     3104,B4           ; |970| 
           MVK     .S1     0x600,A4          ; |970| 
           ADDKPC  .S2     $C$RL101,B3,1     ; |970| 

           ADD     .L2     B4,SP,B4          ; |970| 
||         MVK     .S1     0x600,A6          ; |970| 

$C$RL101:  ; CALL OCCURS {_ReadDARAM_CRYPT0__FUsPvT1} {0}  ; |970| 
	.dwpsn	file "test_c.cpp",line 971,column 3,is_stmt
$C$DW$525	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$525, DW_AT_low_pc(0x00)
	.dwattr $C$DW$525, DW_AT_name("_ReadDARAM_CRYPT1__FUsPvT1")
	.dwattr $C$DW$525, DW_AT_TI_call
           CALL    .S1     _ReadDARAM_CRYPT1__FUsPvT1 ; |971| 
           MVK     .S2     4640,B4           ; |971| 
           MVK     .S1     0x600,A4          ; |971| 
           ADDKPC  .S2     $C$RL102,B3,1     ; |971| 

           ADD     .L2     B4,SP,B4          ; |971| 
||         MVK     .S1     0x600,A6          ; |971| 

$C$RL102:  ; CALL OCCURS {_ReadDARAM_CRYPT1__FUsPvT1} {0}  ; |971| 
	.dwpsn	file "test_c.cpp",line 972,column 3,is_stmt
;----------------------------------------------------------------------
; 972 | gl_result.n_test++;                                                    
; 975 | break;                                                                 
;----------------------------------------------------------------------
$C$DW$526	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$526, DW_AT_low_pc(0x00)
	.dwattr $C$DW$526, DW_AT_name("_WriteDARAM__FUsPvT1")
	.dwattr $C$DW$526, DW_AT_TI_call
           CALL    .S1     _WriteDARAM__FUsPvT1 ; |972| 
           MVK     .S2     1568,B4           ; |972| 
           MVK     .S1     0x600,A4          ; |972| 
           ADDKPC  .S2     $C$RL103,B3,1     ; |972| 

           ADD     .L2     B4,SP,B4          ; |972| 
||         MVK     .S1     0x600,A6          ; |972| 

$C$RL103:  ; CALL OCCURS {_WriteDARAM__FUsPvT1} {0}  ; |972| 
	.dwpsn	file "test_c.cpp",line 976,column 3,is_stmt
$C$DW$527	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$527, DW_AT_low_pc(0x00)
	.dwattr $C$DW$527, DW_AT_name("_memcmp")
	.dwattr $C$DW$527, DW_AT_TI_call
           CALL    .S1     _memcmp           ; |976| 
           ADDAD   .D2     SP,4,B4           ; |976| 
           MVK     .S2     3104,B5           ; |976| 
           MV      .L1X    B4,A4             ; |976| 
           ADD     .L2     B5,SP,B4          ; |976| 
           ADDKPC  .S2     $C$RL104,B3,0     ; |976| 
$C$RL104:  ; CALL OCCURS {_memcmp} {0}       ; |976| 
           MV      .L1     A4,A0             ; |976| 
   [!A0]   BNOP    .S1     $C$L93,5          ; |976| 
           ; BRANCHCC OCCURS {$C$L93}        ; |976| 
$C$DW$L$_Sv_Msg__FPv$26$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_Sv_Msg__FPv$27$B:
	.dwpsn	file "test_c.cpp",line 977,column 4,is_stmt
           MVKL    .S1     _gl_result+16,A3
           MVKH    .S1     _gl_result+16,A3
           LDW     .D1T1   *A3,A4            ; |977| 
           NOP             4
           ADD     .L1     1,A4,A4           ; |977| 
           STW     .D1T1   A4,*A3            ; |977| 
$C$DW$L$_Sv_Msg__FPv$27$E:
;** --------------------------------------------------------------------------*
$C$L93:    
$C$DW$L$_Sv_Msg__FPv$28$B:
	.dwpsn	file "test_c.cpp",line 978,column 3,is_stmt
;----------------------------------------------------------------------
; 978 | case GOTOV_TEST_MOVE_25:                                               
;----------------------------------------------------------------------
$C$DW$528	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$528, DW_AT_low_pc(0x00)
	.dwattr $C$DW$528, DW_AT_name("_memcmp")
	.dwattr $C$DW$528, DW_AT_TI_call
           CALL    .S1     _memcmp           ; |978| 
           ADDAD   .D2     SP,4,B4           ; |978| 
           MVK     .S2     4640,B5           ; |978| 
           MV      .L1X    B4,A4             ; |978| 
           ADD     .L2     B5,SP,B4          ; |978| 

           ADDKPC  .S2     $C$RL105,B3,0     ; |978| 
||         MVK     .S1     0x600,A6          ; |978| 

$C$RL105:  ; CALL OCCURS {_memcmp} {0}       ; |978| 
           MV      .L1     A4,A0             ; |978| 
   [!A0]   BNOP    .S1     $C$L94,5          ; |978| 
           ; BRANCHCC OCCURS {$C$L94}        ; |978| 
$C$DW$L$_Sv_Msg__FPv$28$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_Sv_Msg__FPv$29$B:
	.dwpsn	file "test_c.cpp",line 979,column 4,is_stmt
;----------------------------------------------------------------------
; 980 | cdg_error.ask = GOTOV_TEST_MOVE_25;                                    
;----------------------------------------------------------------------
           MVKL    .S1     _gl_result+20,A3
           MVKH    .S1     _gl_result+20,A3
           LDW     .D1T1   *A3,A4            ; |979| 
           NOP             4
           ADD     .L1     1,A4,A4           ; |979| 
           STW     .D1T1   A4,*A3            ; |979| 
$C$DW$L$_Sv_Msg__FPv$29$E:
;** --------------------------------------------------------------------------*
$C$L94:    
$C$DW$L$_Sv_Msg__FPv$30$B:
	.dwpsn	file "test_c.cpp",line 981,column 3,is_stmt
;----------------------------------------------------------------------
; 982 | msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));                   
; 983 | //      prc_yield();                                                   
;----------------------------------------------------------------------
           MVKL    .S1     _gl_result+4,A3
           MVKH    .S1     _gl_result+4,A3
           LDW     .D1T1   *A3,A4            ; |981| 
           NOP             4
           ADD     .L1     1,A4,A4           ; |981| 
           STW     .D1T1   A4,*A3            ; |981| 
	.dwpsn	file "test_c.cpp",line 984,column 12,is_stmt
;----------------------------------------------------------------------
; 985 | ReadDARAM_CRYPT0(sizeof(buf1),buf1,sizeof(buf1));                      
; 986 | ReadDARAM_CRYPT1(sizeof(buf1),buf2,sizeof(buf2));                      
; 987 | WriteDARAM(sizeof(buf1), bufAA, sizeof(bufAA));                        
;----------------------------------------------------------------------
           BNOP    .S1     $C$L116,5         ; |984| 
           ; BRANCH OCCURS {$C$L116}         ; |984| 
$C$DW$L$_Sv_Msg__FPv$30$E:
;** --------------------------------------------------------------------------*
$C$L95:    
$C$DW$L$_Sv_Msg__FPv$31$B:
	.dwpsn	file "test_c.cpp",line 988,column 3,is_stmt
;----------------------------------------------------------------------
; 989 | //uint32 tsk = Test_SK();                                              
;----------------------------------------------------------------------
           MVKL    .S2     0xd001d,B4
           MVKH    .S2     0xd001d,B4
           STW     .D2T2   B4,*+SP(20)       ; |988| 
	.dwpsn	file "test_c.cpp",line 990,column 9,is_stmt
;----------------------------------------------------------------------
; 991 | if(memcmp(buf55, buf1, sizeof(buf1)))                                  
; 992 |         gl_result.data++;                                              
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+384,A3
           MVKH    .S1     ___syscall_tab+384,A3
           LDW     .D1T1   *A3,A3            ; |990| 
           LDW     .D2T1   *+SP(12),A4       ; |990| 
           ADD     .D2     SP,16,B4          ; |990| 
           MVK     .L1     0x8,A6            ; |990| 
           NOP             1
$C$DW$529	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$529, DW_AT_low_pc(0x00)
	.dwattr $C$DW$529, DW_AT_TI_call
	.dwattr $C$DW$529, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |990| 
           ADDKPC  .S2     $C$RL106,B3,4     ; |990| 
$C$RL106:  ; CALL OCCURS {A3} {0}            ; |990| 
	.dwpsn	file "test_c.cpp",line 993,column 3,is_stmt
;----------------------------------------------------------------------
; 993 | if(memcmp(buf55, buf2, sizeof(buf2)))                                  
;----------------------------------------------------------------------
$C$DW$530	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$530, DW_AT_low_pc(0x00)
	.dwattr $C$DW$530, DW_AT_name("_ReadDARAM_CRYPT0__FUsPvT1")
	.dwattr $C$DW$530, DW_AT_TI_call
           CALL    .S1     _ReadDARAM_CRYPT0__FUsPvT1 ; |993| 
           MVK     .S2     3104,B4           ; |993| 
           MVK     .S1     0x600,A4          ; |993| 
           ADDKPC  .S2     $C$RL107,B3,1     ; |993| 

           ADD     .L2     B4,SP,B4          ; |993| 
||         MVK     .S1     0x600,A6          ; |993| 

$C$RL107:  ; CALL OCCURS {_ReadDARAM_CRYPT0__FUsPvT1} {0}  ; |993| 
	.dwpsn	file "test_c.cpp",line 994,column 3,is_stmt
;----------------------------------------------------------------------
; 994 | gl_result.data1++;                                                     
;----------------------------------------------------------------------
$C$DW$531	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$531, DW_AT_low_pc(0x00)
	.dwattr $C$DW$531, DW_AT_name("_ReadDARAM_CRYPT1__FUsPvT1")
	.dwattr $C$DW$531, DW_AT_TI_call
           CALL    .S1     _ReadDARAM_CRYPT1__FUsPvT1 ; |994| 
           MVK     .S2     4640,B4           ; |994| 
           MVK     .S1     0x600,A4          ; |994| 
           ADDKPC  .S2     $C$RL108,B3,1     ; |994| 

           ADD     .L2     B4,SP,B4          ; |994| 
||         MVK     .S1     0x600,A6          ; |994| 

$C$RL108:  ; CALL OCCURS {_ReadDARAM_CRYPT1__FUsPvT1} {0}  ; |994| 
	.dwpsn	file "test_c.cpp",line 995,column 3,is_stmt
;----------------------------------------------------------------------
; 996 | gl_result.n_test++;                                                    
;----------------------------------------------------------------------
$C$DW$532	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$532, DW_AT_low_pc(0x00)
	.dwattr $C$DW$532, DW_AT_name("_WriteDARAM__FUsPvT1")
	.dwattr $C$DW$532, DW_AT_TI_call
           CALL    .S1     _WriteDARAM__FUsPvT1 ; |995| 
           MVK     .S1     0x600,A4          ; |995| 
           ADDKPC  .S2     $C$RL109,B3,2     ; |995| 

           ADDAD   .D2     SP,4,B4           ; |995| 
||         MVK     .S1     0x600,A6          ; |995| 

$C$RL109:  ; CALL OCCURS {_WriteDARAM__FUsPvT1} {0}  ; |995| 
	.dwpsn	file "test_c.cpp",line 999,column 3,is_stmt
;----------------------------------------------------------------------
; 999 | break;                                                                 
;----------------------------------------------------------------------
$C$DW$533	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$533, DW_AT_low_pc(0x00)
	.dwattr $C$DW$533, DW_AT_name("_memcmp")
	.dwattr $C$DW$533, DW_AT_TI_call
           CALL    .S1     _memcmp           ; |999| 
           MVK     .S2     1568,B4           ; |999| 
           ADD     .L2     B4,SP,B4          ; |999| 
           MVK     .S2     3104,B5           ; |999| 
           MV      .L1X    B4,A4             ; |999| 

           ADD     .L2     B5,SP,B4          ; |999| 
||         ADDKPC  .S2     $C$RL110,B3,0     ; |999| 

$C$RL110:  ; CALL OCCURS {_memcmp} {0}       ; |999| 
           MV      .L1     A4,A0             ; |999| 
   [!A0]   BNOP    .S1     $C$L96,5          ; |999| 
           ; BRANCHCC OCCURS {$C$L96}        ; |999| 
$C$DW$L$_Sv_Msg__FPv$31$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_Sv_Msg__FPv$32$B:
	.dwpsn	file "test_c.cpp",line 1000,column 4,is_stmt
           MVKL    .S1     _gl_result+16,A3
           MVKH    .S1     _gl_result+16,A3
           LDW     .D1T1   *A3,A4            ; |1000| 
           NOP             4
           ADD     .L1     1,A4,A4           ; |1000| 
           STW     .D1T1   A4,*A3            ; |1000| 
$C$DW$L$_Sv_Msg__FPv$32$E:
;** --------------------------------------------------------------------------*
$C$L96:    
$C$DW$L$_Sv_Msg__FPv$33$B:
	.dwpsn	file "test_c.cpp",line 1001,column 3,is_stmt
;----------------------------------------------------------------------
; 1001 | case GOTOV_TEST_MOVE_2A:                                               
;----------------------------------------------------------------------
$C$DW$534	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$534, DW_AT_low_pc(0x00)
	.dwattr $C$DW$534, DW_AT_name("_memcmp")
	.dwattr $C$DW$534, DW_AT_TI_call
           CALL    .S1     _memcmp           ; |1001| 
           MVK     .S2     1568,B4           ; |1001| 
           ADD     .L2     B4,SP,B4          ; |1001| 
           MVK     .S1     4640,A3           ; |1001| 
           MV      .L1X    B4,A4             ; |1001| 

           ADD     .L2X    A3,SP,B4          ; |1001| 
||         ADDKPC  .S2     $C$RL111,B3,0     ; |1001| 
||         MVK     .S1     0x600,A6          ; |1001| 

$C$RL111:  ; CALL OCCURS {_memcmp} {0}       ; |1001| 
           MV      .L1     A4,A0             ; |1001| 
   [!A0]   BNOP    .S1     $C$L97,5          ; |1001| 
           ; BRANCHCC OCCURS {$C$L97}        ; |1001| 
$C$DW$L$_Sv_Msg__FPv$33$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_Sv_Msg__FPv$34$B:
	.dwpsn	file "test_c.cpp",line 1002,column 4,is_stmt
;----------------------------------------------------------------------
; 1003 | cdg_error.ask = GOTOV_TEST_MOVE_2A;                                    
;----------------------------------------------------------------------
           MVKL    .S1     _gl_result+20,A3
           MVKH    .S1     _gl_result+20,A3
           LDW     .D1T1   *A3,A4            ; |1002| 
           NOP             4
           ADD     .L1     1,A4,A4           ; |1002| 
           STW     .D1T1   A4,*A3            ; |1002| 
$C$DW$L$_Sv_Msg__FPv$34$E:
;** --------------------------------------------------------------------------*
$C$L97:    
$C$DW$L$_Sv_Msg__FPv$35$B:
	.dwpsn	file "test_c.cpp",line 1004,column 3,is_stmt
;----------------------------------------------------------------------
; 1005 | msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));                   
; 1006 | //      prc_yield();                                                   
;----------------------------------------------------------------------
           MVKL    .S1     _gl_result+4,A3
           MVKH    .S1     _gl_result+4,A3
           LDW     .D1T1   *A3,A4            ; |1004| 
           NOP             4
           ADD     .L1     1,A4,A4           ; |1004| 
           STW     .D1T1   A4,*A3            ; |1004| 
	.dwpsn	file "test_c.cpp",line 1007,column 12,is_stmt
;----------------------------------------------------------------------
; 1008 | ReadDARAM_CRYPT0(sizeof(buf1),buf1,sizeof(buf1));                      
; 1009 | ReadDARAM_CRYPT1(sizeof(buf1),buf2,sizeof(buf2));                      
; 1010 | WriteDARAM(sizeof(buf1), buf55, sizeof(buf55));                        
;----------------------------------------------------------------------
           BNOP    .S1     $C$L116,5         ; |1007| 
           ; BRANCH OCCURS {$C$L116}         ; |1007| 
$C$DW$L$_Sv_Msg__FPv$35$E:
;** --------------------------------------------------------------------------*
$C$L98:    
$C$DW$L$_Sv_Msg__FPv$36$B:

$C$DW$535	.dwtag  DW_TAG_lexical_block, DW_AT_low_pc(0x00), DW_AT_high_pc(0x00)
$C$DW$536	.dwtag  DW_TAG_variable, DW_AT_name("lenn")
	.dwattr $C$DW$536, DW_AT_TI_symbol_name("_lenn")
	.dwattr $C$DW$536, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$536, DW_AT_location[DW_OP_breg31 9184]
$C$DW$537	.dwtag  DW_TAG_variable, DW_AT_name("p_txd")
	.dwattr $C$DW$537, DW_AT_TI_symbol_name("_p_txd")
	.dwattr $C$DW$537, DW_AT_type(*$C$DW$T$570)
	.dwattr $C$DW$537, DW_AT_location[DW_OP_breg31 9188]
$C$DW$538	.dwtag  DW_TAG_variable, DW_AT_name("rress")
	.dwattr $C$DW$538, DW_AT_TI_symbol_name("_rress")
	.dwattr $C$DW$538, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$538, DW_AT_location[DW_OP_breg31 9192]
$C$DW$539	.dwtag  DW_TAG_variable, DW_AT_name("lnk")
	.dwattr $C$DW$539, DW_AT_TI_symbol_name("_lnk")
	.dwattr $C$DW$539, DW_AT_type(*$C$DW$T$701)
	.dwattr $C$DW$539, DW_AT_location[DW_OP_breg31 9196]
	.dwpsn	file "test_c.cpp",line 1012,column 10,is_stmt
;----------------------------------------------------------------------
; 1012 | //uint32 tsk = Test_SK();                                              
;----------------------------------------------------------------------
           MVK     .S1     1420,A3           ; |1012| 
           STW     .D2T1   A3,*+SP(9184)     ; |1012| 
	.dwpsn	file "test_c.cpp",line 1013,column 19,is_stmt
           ZERO    .L1     A3                ; |1013| 
           STW     .D2T1   A3,*+SP(9188)     ; |1013| 
	.dwpsn	file "test_c.cpp",line 1014,column 10,is_stmt
;----------------------------------------------------------------------
; 1014 | if(memcmp(bufAA, buf1, sizeof(buf1)))                                  
; 1015 |         gl_result.data++;                                              
; 1016 | if(memcmp(bufAA, buf2, sizeof(buf2)))                                  
; 1017 |         gl_result.data1++;                                             
; 1019 | gl_result.n_test++;                                                    
;----------------------------------------------------------------------
           ZERO    .L2     B4                ; |1014| 
           STW     .D2T2   B4,*+SP(9192)     ; |1014| 
	.dwpsn	file "test_c.cpp",line 1021,column 3,is_stmt
$C$DW$540	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$540, DW_AT_low_pc(0x00)
	.dwattr $C$DW$540, DW_AT_name("_ReadDARAM_CRYPT0__FUsPvT1")
	.dwattr $C$DW$540, DW_AT_TI_call
           CALL    .S1     _ReadDARAM_CRYPT0__FUsPvT1 ; |1021| 
           LDHU    .D2T1   *+SP(9184),A6     ; |1021| 
           MVK     .S2     6176,B5           ; |1021| 
           ADD     .L2     B5,SP,B4          ; |1021| 
           ADDKPC  .S2     $C$RL112,B3,0     ; |1021| 
           ZERO    .L1     A4                ; |1021| 
$C$RL112:  ; CALL OCCURS {_ReadDARAM_CRYPT0__FUsPvT1} {0}  ; |1021| 
	.dwpsn	file "test_c.cpp",line 1022,column 3,is_stmt
;----------------------------------------------------------------------
; 1022 | break;                                                                 
;----------------------------------------------------------------------
$C$DW$541	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$541, DW_AT_low_pc(0x00)
	.dwattr $C$DW$541, DW_AT_name("_ReadDARAM_CRYPT1__FUsPvT1")
	.dwattr $C$DW$541, DW_AT_TI_call
           CALL    .S1     _ReadDARAM_CRYPT1__FUsPvT1 ; |1022| 
           LDHU    .D2T1   *+SP(9184),A6     ; |1022| 
           MVK     .S1     7680,A3           ; |1022| 
           ADDKPC  .S2     $C$RL113,B3,1     ; |1022| 

           ZERO    .L1     A4                ; |1022| 
||         ADD     .L2X    A3,SP,B4          ; |1022| 

$C$RL113:  ; CALL OCCURS {_ReadDARAM_CRYPT1__FUsPvT1} {0}  ; |1022| 
	.dwpsn	file "test_c.cpp",line 1024,column 3,is_stmt
;----------------------------------------------------------------------
; 1025 | case SEND_TEST_PACKET:                                                 
;----------------------------------------------------------------------
$C$DW$542	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$542, DW_AT_low_pc(0x00)
	.dwattr $C$DW$542, DW_AT_name("_memcmp")
	.dwattr $C$DW$542, DW_AT_TI_call
           CALL    .S1     _memcmp           ; |1024| 
           LDW     .D2T1   *+SP(9184),A6     ; |1024| 
           MVK     .S2     6176,B4           ; |1024| 

           ADD     .L2     B4,SP,B4          ; |1024| 
||         MVK     .S1     7680,A3           ; |1024| 

           ADDKPC  .S2     $C$RL114,B3,0     ; |1024| 

           MV      .L1X    B4,A4             ; |1024| 
||         ADD     .L2X    A3,SP,B4          ; |1024| 

$C$RL114:  ; CALL OCCURS {_memcmp} {0}       ; |1024| 
           MV      .L1     A4,A0             ; |1024| 
   [!A0]   BNOP    .S1     $C$L102,5         ; |1024| 
           ; BRANCHCC OCCURS {$C$L102}       ; |1024| 
$C$DW$L$_Sv_Msg__FPv$36$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_Sv_Msg__FPv$37$B:

$C$DW$543	.dwtag  DW_TAG_lexical_block, DW_AT_low_pc(0x00), DW_AT_high_pc(0x00)
$C$DW$544	.dwtag  DW_TAG_variable, DW_AT_name("t")
	.dwattr $C$DW$544, DW_AT_TI_symbol_name("_t")
	.dwattr $C$DW$544, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$544, DW_AT_location[DW_OP_breg31 9200]
	.dwpsn	file "test_c.cpp",line 1026,column 12,is_stmt
           ZERO    .L2     B4                ; |1026| 
           STW     .D2T2   B4,*+SP(9200)     ; |1026| 
	.dwpsn	file "test_c.cpp",line 1026,column 17,is_stmt
;----------------------------------------------------------------------
; 1027 | uint32 lenn = 1400+20;                                                 
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(9184),B4     ; |1026| 
           LDW     .D2T2   *+SP(9200),B5     ; |1026| 
           NOP             4
           CMPLTU  .L2     B5,B4,B0          ; |1026| 
   [!B0]   BNOP    .S1     $C$L101,5         ; |1026| 
           ; BRANCHCC OCCURS {$C$L101}       ; |1026| 
$C$DW$L$_Sv_Msg__FPv$37$E:
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
$C$L99:    
$C$DW$L$_Sv_Msg__FPv$38$B:
	.dwpsn	file "test_c.cpp",line 1028,column 5,is_stmt
;----------------------------------------------------------------------
; 1028 | net_descriptor* p_txd = NULL;                                          
; 1029 | uint32 rress=0;                                                        
; 1030 | bool lnk;                                                              
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(9200),B4     ; |1028| 
           MVK     .S2     7680,B5           ; |1028| 
           MVK     .S1     6176,A4           ; |1028| 
           NOP             2
           MV      .L1X    B4,A3             ; |1028| 

           ADD     .L1X    A3,SP,A3          ; |1028| 
||         ADD     .L2     B4,SP,B4          ; |1028| 

           LDB     .D1T1   *+A3[A4],A3       ; |1028| 
||         LDB     .D2T2   *+B4[B5],B4       ; |1028| 

           NOP             4
           CMPEQ   .L1X    A3,B4,A0          ; |1028| 
   [ A0]   BNOP    .S1     $C$L100,5         ; |1028| 
           ; BRANCHCC OCCURS {$C$L100}       ; |1028| 
$C$DW$L$_Sv_Msg__FPv$38$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_Sv_Msg__FPv$39$B:
	.dwpsn	file "test_c.cpp",line 1033,column 5,is_stmt
;----------------------------------------------------------------------
; 1033 | //uint32* tests = (uint32*)0xA0000FE0;                                 
; 1034 | //uint32* tests1 = (uint32*)0xB0000FE0;                                
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(9184),B4     ; |1033| 
           NOP             4
           ADD     .L2     1,B4,B4           ; |1033| 
           STW     .D2T2   B4,*+SP(9184)     ; |1033| 
	.dwpsn	file "test_c.cpp",line 1035,column 5,is_stmt
;----------------------------------------------------------------------
; 1036 | ReadDARAM_CRYPT0(0,buf11,lenn);                                        
; 1037 | ReadDARAM_CRYPT1(0,buf22,lenn);                                        
; 1039 | if(memcmp(buf11, buf22, lenn))                                         
;----------------------------------------------------------------------
           SUB     .L2     B4,1,B4           ; |1035| 
           STW     .D2T2   B4,*+SP(9184)     ; |1035| 
$C$DW$L$_Sv_Msg__FPv$39$E:
;** --------------------------------------------------------------------------*
$C$L100:    
$C$DW$L$_Sv_Msg__FPv$40$B:
	.dwpsn	file "test_c.cpp",line 1026,column 25,is_stmt
           LDW     .D2T2   *+SP(9200),B4     ; |1026| 
           NOP             4
           ADD     .L2     1,B4,B4           ; |1026| 
           STW     .D2T2   B4,*+SP(9200)     ; |1026| 
	.dwpsn	file "test_c.cpp",line 1026,column 17,is_stmt
           LDW     .D2T2   *+SP(9184),B4     ; |1026| 
           LDW     .D2T2   *+SP(9200),B5     ; |1026| 
           NOP             4
           CMPLTU  .L2     B5,B4,B0          ; |1026| 
   [ B0]   BNOP    .S1     $C$L99,5          ; |1026| 
           ; BRANCHCC OCCURS {$C$L99}        ; |1026| 
$C$DW$L$_Sv_Msg__FPv$40$E:
;** --------------------------------------------------------------------------*
$C$L101:    
$C$DW$L$_Sv_Msg__FPv$41$B:
	.dwendtag $C$DW$543

	.dwpsn	file "test_c.cpp",line 1040,column 3,is_stmt
           MVK     .L2     1,B4              ; |1040| 
           STW     .D2T2   B4,*+SP(20)       ; |1040| 
	.dwpsn	file "test_c.cpp",line 1041,column 9,is_stmt
;----------------------------------------------------------------------
; 1041 | for(int t=0; t<lenn; t++)                                              
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+384,A3
           MVKH    .S1     ___syscall_tab+384,A3
           LDW     .D1T1   *A3,A3            ; |1041| 
           LDW     .D2T1   *+SP(12),A4       ; |1041| 
           ADD     .D2     SP,16,B4          ; |1041| 
           MVK     .L1     0x8,A6            ; |1041| 
           NOP             1
$C$DW$545	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$545, DW_AT_low_pc(0x00)
	.dwattr $C$DW$545, DW_AT_TI_call
	.dwattr $C$DW$545, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |1041| 
           ADDKPC  .S2     $C$RL115,B3,4     ; |1041| 
$C$RL115:  ; CALL OCCURS {A3} {0}            ; |1041| 
	.dwpsn	file "test_c.cpp",line 1043,column 4,is_stmt
;----------------------------------------------------------------------
; 1043 | if(buf11[t]!=buf22[t])                                                 
; 1046 | //  REG_GPIO_DIR &= ~( 0x00000060 );                                   
;----------------------------------------------------------------------
           BNOP    .S1     $C$L116,5         ; |1043| 
           ; BRANCH OCCURS {$C$L116}         ; |1043| 
$C$DW$L$_Sv_Msg__FPv$41$E:
;** --------------------------------------------------------------------------*
$C$L102:    
$C$DW$L$_Sv_Msg__FPv$42$B:
	.dwpsn	file "test_c.cpp",line 1047,column 3,is_stmt
;----------------------------------------------------------------------
; 1047 | // REG_GPIO_CLR_DATA = 0x00000060;                                     
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+292,A3
           MVKH    .S1     ___syscall_tab+292,A3
           LDW     .D1T1   *A3,A3            ; |1047| 
           MVKL    .S1     $C$SL1+0,A4       ; |1047| 
           MVKH    .S1     $C$SL1+0,A4       ; |1047| 
           NOP             2
$C$DW$546	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$546, DW_AT_low_pc(0x00)
	.dwattr $C$DW$546, DW_AT_TI_call
	.dwattr $C$DW$546, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |1047| 
           ADDKPC  .S2     $C$RL116,B3,4     ; |1047| 
$C$RL116:  ; CALL OCCURS {A3} {0}            ; |1047| 
           STW     .D2T1   A4,*+SP(9180)     ; |1047| 
	.dwpsn	file "test_c.cpp",line 1048,column 3,is_stmt
;----------------------------------------------------------------------
; 1048 | lenn++;                                                                
;----------------------------------------------------------------------
           MV      .L2X    A4,B0
   [!B0]   BNOP    .S1     $C$L103,5         ; |1048| 
           ; BRANCHCC OCCURS {$C$L103}       ; |1048| 
$C$DW$L$_Sv_Msg__FPv$42$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_Sv_Msg__FPv$43$B:
	.dwpsn	file "test_c.cpp",line 1049,column 4,is_stmt
;----------------------------------------------------------------------
; 1049 | //sleep_m(100);                                                        
; 1050 | lenn--;                                                                
; 1051 | //  REG_GPIO_SET_DATA = 0x00000060;                                    
;----------------------------------------------------------------------
	.dwpsn	file "test_c.cpp",line 1052,column 3,is_stmt
           MVKL    .S1     ___syscall_tab+284,A3
           MVKH    .S1     ___syscall_tab+284,A3
           LDW     .D1T1   *A3,A3            ; |1052| 
           MVK     .S2     9188,B4           ; |1052| 
           ADD     .L2     B4,SP,B5          ; |1052| 
           MVK     .S2     0x1102,B4         ; |1052| 
           MV      .L1X    B5,A6             ; |1052| 
$C$DW$547	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$547, DW_AT_low_pc(0x00)
	.dwattr $C$DW$547, DW_AT_TI_call
	.dwattr $C$DW$547, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |1052| 
           ADDKPC  .S2     $C$RL117,B3,4     ; |1052| 
$C$RL117:  ; CALL OCCURS {A3} {0}            ; |1052| 
           MV      .L1     A4,A0             ; |1052| 
   [ A0]   BNOP    .S1     $C$L103,5         ; |1052| 
           ; BRANCHCC OCCURS {$C$L103}       ; |1052| 
$C$DW$L$_Sv_Msg__FPv$43$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_Sv_Msg__FPv$44$B:
	.dwpsn	file "test_c.cpp",line 1053,column 4,is_stmt
	.dwpsn	file "test_c.cpp",line 1054,column 3,is_stmt
           LDW     .D2T2   *+SP(9188),B0     ; |1054| 
           NOP             4
   [!B0]   BNOP    .S1     $C$L103,5         ; |1054| 
           ; BRANCHCC OCCURS {$C$L103}       ; |1054| 
$C$DW$L$_Sv_Msg__FPv$44$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_Sv_Msg__FPv$45$B:
	.dwpsn	file "test_c.cpp",line 1055,column 4,is_stmt
;----------------------------------------------------------------------
; 1055 | cdg_error.ask = TPO_ERR;                                               
; 1056 | msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));                   
;----------------------------------------------------------------------
	.dwpsn	file "test_c.cpp",line 1058,column 3,is_stmt
;----------------------------------------------------------------------
; 1058 | break;                                                                 
;----------------------------------------------------------------------
$C$DW$548	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$548, DW_AT_low_pc(0x04)
	.dwattr $C$DW$548, DW_AT_name("_memcpy")
	.dwattr $C$DW$548, DW_AT_TI_call

           MV      .L2     B0,B4
||         CALL    .S1     _memcpy           ; |1058| 
||         LDW     .D2T1   *+SP(9184),A6     ; |1058| 

           LDW     .D2T1   *+B4(16),A4       ; |1058| 
           MVK     .S2     6176,B31          ; |1058| 
           ADD     .L2     B31,SP,B4         ; |1058| 
           ADDKPC  .S2     $C$RL118,B3,1     ; |1058| 
$C$RL118:  ; CALL OCCURS {_memcpy} {0}       ; |1058| 
	.dwpsn	file "test_c.cpp",line 1059,column 3,is_stmt
           LDW     .D2T1   *+SP(9188),A3     ; |1059| 
           LDW     .D2T2   *+SP(9184),B4     ; |1059| 
           NOP             4
           STW     .D1T2   B4,*+A3(12)       ; |1059| 
	.dwpsn	file "test_c.cpp",line 1061,column 3,is_stmt
;----------------------------------------------------------------------
; 1062 | FileNet = drv_mkd("/dev/net/eth0");                                    
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+284,A3
           MVKH    .S1     ___syscall_tab+284,A3
           LDW     .D1T1   *A3,A3            ; |1061| 
           MVK     .S1     9196,A4           ; |1061| 
           ADD     .L1X    A4,SP,A6          ; |1061| 
           LDW     .D2T1   *+SP(9180),A4     ; |1061| 
           MVK     .S2     0x110f,B4         ; |1061| 
$C$DW$549	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$549, DW_AT_low_pc(0x00)
	.dwattr $C$DW$549, DW_AT_TI_call
	.dwattr $C$DW$549, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |1061| 
           ADDKPC  .S2     $C$RL119,B3,4     ; |1061| 
$C$RL119:  ; CALL OCCURS {A3} {0}            ; |1061| 
           STW     .D2T1   A4,*+SP(9192)     ; |1061| 
	.dwpsn	file "test_c.cpp",line 1063,column 3,is_stmt
;----------------------------------------------------------------------
; 1063 | if(FileNet == RES_VOID) // НУ не передастс                             
;----------------------------------------------------------------------
           LDB     .D2T2   *+SP(9196),B0     ; |1063| 
           NOP             4
   [!B0]   BNOP    .S1     $C$L103,5         ; |1063| 
           ; BRANCHCC OCCURS {$C$L103}       ; |1063| 
$C$DW$L$_Sv_Msg__FPv$45$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_Sv_Msg__FPv$46$B:
	.dwpsn	file "test_c.cpp",line 1064,column 3,is_stmt
;----------------------------------------------------------------------
; 1064 | ....                                                                   
; 1065 | goto close_drv1;                                                       
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+284,A3
           MVKH    .S1     ___syscall_tab+284,A3
           LDW     .D1T1   *A3,A3            ; |1064| 
           LDW     .D2T1   *+SP(9180),A4     ; |1064| 
           MVK     .S2     9188,B4           ; |1064| 
           ADD     .L2     B4,SP,B5          ; |1064| 
           MVK     .S2     0x1103,B4         ; |1064| 
$C$DW$550	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$550, DW_AT_low_pc(0x00)
	.dwattr $C$DW$550, DW_AT_TI_call
	.dwattr $C$DW$550, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |1064| 
           ADDKPC  .S2     $C$RL120,B3,3     ; |1064| 
           MV      .L1X    B5,A6             ; |1064| 
$C$RL120:  ; CALL OCCURS {A3} {0}            ; |1064| 
           STW     .D2T1   A4,*+SP(9192)     ; |1064| 
$C$DW$L$_Sv_Msg__FPv$46$E:
;** --------------------------------------------------------------------------*
$C$L103:    
$C$DW$L$_Sv_Msg__FPv$47$B:
	.dwpsn	file "test_c.cpp",line 1067,column 3,is_stmt
;----------------------------------------------------------------------
; 1068 | if(drv_ioctl( FileNet, NET_SEND_GET, &p_txd ) != OSE_OK )       //готов
;     | им к отправке                                                          
;----------------------------------------------------------------------
           MVKL    .S2     ___syscall_tab+296,B4
           MVKH    .S2     ___syscall_tab+296,B4
           LDW     .D2T2   *B4,B4            ; |1067| 
           LDW     .D2T1   *+SP(9180),A4     ; |1067| 
           NOP             3
$C$DW$551	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$551, DW_AT_low_pc(0x00)
	.dwattr $C$DW$551, DW_AT_TI_call
	.dwattr $C$DW$551, DW_AT_TI_indirect
           CALL    .S2     B4                ; |1067| 
           ADDKPC  .S2     $C$RL121,B3,4     ; |1067| 
$C$RL121:  ; CALL OCCURS {B4} {0}            ; |1067| 
	.dwpsn	file "test_c.cpp",line 1069,column 3,is_stmt
;----------------------------------------------------------------------
; 1069 | goto close_drv1;                                                       
;----------------------------------------------------------------------
           ZERO    .L2     B4                ; |1069| 
           STW     .D2T2   B4,*+SP(20)       ; |1069| 
	.dwpsn	file "test_c.cpp",line 1070,column 9,is_stmt
;----------------------------------------------------------------------
; 1070 | if( p_txd == NULL )                                                    
; 1071 |         goto close_drv1;                                               
; 1072 | //              sleep_m(10);                                           
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+384,A3
           MVKH    .S1     ___syscall_tab+384,A3
           LDW     .D1T1   *A3,A3            ; |1070| 
           LDW     .D2T1   *+SP(12),A4       ; |1070| 
           MVK     .L1     0x8,A6            ; |1070| 
           ADD     .D2     SP,16,B4          ; |1070| 
           NOP             1
$C$DW$552	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$552, DW_AT_low_pc(0x00)
	.dwattr $C$DW$552, DW_AT_TI_call
	.dwattr $C$DW$552, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |1070| 
           ADDKPC  .S2     $C$RL122,B3,4     ; |1070| 
$C$RL122:  ; CALL OCCURS {A3} {0}            ; |1070| 
	.dwendtag $C$DW$535

	.dwpsn	file "test_c.cpp",line 1073,column 14,is_stmt
;----------------------------------------------------------------------
; 1074 | memcpy( p_txd->data, buf11, lenn );                                    
; 1075 | p_txd->length = lenn;                                                  
; 1077 | rress = drv_ioctl( FileNet, NET_LINK, &lnk);    //отправл              
;----------------------------------------------------------------------
           BNOP    .S1     $C$L116,5         ; |1073| 
           ; BRANCH OCCURS {$C$L116}         ; |1073| 
$C$DW$L$_Sv_Msg__FPv$47$E:
;** --------------------------------------------------------------------------*
$C$L104:    
$C$DW$L$_Sv_Msg__FPv$48$B:

$C$DW$553	.dwtag  DW_TAG_lexical_block, DW_AT_low_pc(0x00), DW_AT_high_pc(0x00)
$C$DW$554	.dwtag  DW_TAG_variable, DW_AT_name("lenn")
	.dwattr $C$DW$554, DW_AT_TI_symbol_name("_lenn")
	.dwattr $C$DW$554, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$554, DW_AT_location[DW_OP_breg31 9184]
$C$DW$555	.dwtag  DW_TAG_variable, DW_AT_name("p_rxd")
	.dwattr $C$DW$555, DW_AT_TI_symbol_name("_p_rxd")
	.dwattr $C$DW$555, DW_AT_type(*$C$DW$T$570)
	.dwattr $C$DW$555, DW_AT_location[DW_OP_breg31 9188]
$C$DW$556	.dwtag  DW_TAG_variable, DW_AT_name("retry10")
	.dwattr $C$DW$556, DW_AT_TI_symbol_name("_retry10")
	.dwattr $C$DW$556, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$556, DW_AT_location[DW_OP_breg31 9192]
	.dwpsn	file "test_c.cpp",line 1078,column 10,is_stmt
;----------------------------------------------------------------------
; 1078 | ем                                                                     
;----------------------------------------------------------------------
           MVK     .S2     1420,B4           ; |1078| 
           STW     .D2T2   B4,*+SP(9184)     ; |1078| 
	.dwpsn	file "test_c.cpp",line 1079,column 19,is_stmt
;----------------------------------------------------------------------
; 1080 | if(lnk)                                                                
;----------------------------------------------------------------------
           ZERO    .L2     B4                ; |1079| 
           STW     .D2T2   B4,*+SP(9188)     ; |1079| 
	.dwpsn	file "test_c.cpp",line 1081,column 10,is_stmt
;----------------------------------------------------------------------
; 1081 | rress = drv_ioctl( FileNet, NET_SEND_PUT, &p_txd );     //отправл      
; 1082 | ем                                                                     
;----------------------------------------------------------------------
           MVK     .L2     5,B4              ; |1081| 
           STW     .D2T2   B4,*+SP(9192)     ; |1081| 
	.dwpsn	file "test_c.cpp",line 1084,column 3,is_stmt
;----------------------------------------------------------------------
; 1084 | close_drv1:                                                            
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+292,A3
           MVKH    .S1     ___syscall_tab+292,A3
           LDW     .D1T1   *A3,A3            ; |1084| 
           MVKL    .S1     $C$SL1+0,A4       ; |1084| 
           MVKH    .S1     $C$SL1+0,A4       ; |1084| 
           NOP             2
$C$DW$557	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$557, DW_AT_low_pc(0x00)
	.dwattr $C$DW$557, DW_AT_TI_call
	.dwattr $C$DW$557, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |1084| 
           ADDKPC  .S2     $C$RL123,B3,4     ; |1084| 
$C$RL123:  ; CALL OCCURS {A3} {0}            ; |1084| 
           STW     .D2T1   A4,*+SP(9180)     ; |1084| 
	.dwpsn	file "test_c.cpp",line 1085,column 3,is_stmt
;----------------------------------------------------------------------
; 1085 | drv_rmd(FileNet);                                                      
;----------------------------------------------------------------------
           MV      .L2X    A4,B0
   [!B0]   BNOP    .S1     $C$L110,5         ; |1085| 
           ; BRANCHCC OCCURS {$C$L110}       ; |1085| 
$C$DW$L$_Sv_Msg__FPv$48$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_Sv_Msg__FPv$49$B:
	.dwpsn	file "test_c.cpp",line 1086,column 4,is_stmt
;----------------------------------------------------------------------
; 1087 | cdg_error.ask = TPO_OK;                                                
; 1088 | msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));                   
;----------------------------------------------------------------------
	.dwpsn	file "test_c.cpp",line 1090,column 3,is_stmt
;----------------------------------------------------------------------
; 1091 | break;                                                                 
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(9192),B0     ; |1090| 
           NOP             4
   [!B0]   BNOP    .S1     $C$L108,3         ; |1090| 
           SUB     .L2     B0,1,B4           ; |1090| 
           STW     .D2T2   B4,*+SP(9192)     ; |1090| 
           ; BRANCHCC OCCURS {$C$L108}       ; |1090| 
$C$DW$L$_Sv_Msg__FPv$49$E:
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
$C$L105:    
$C$DW$L$_Sv_Msg__FPv$50$B:
	.dwpsn	file "test_c.cpp",line 1092,column 5,is_stmt
           MVKL    .S1     ___syscall_tab+284,A3
           MVKH    .S1     ___syscall_tab+284,A3
           LDW     .D1T1   *A3,A3            ; |1092| 
           LDW     .D2T1   *+SP(9180),A4     ; |1092| 
           MVK     .S2     9188,B4           ; |1092| 
           ADD     .L2     B4,SP,B5          ; |1092| 
           MVK     .S2     0x1100,B4         ; |1092| 
$C$DW$558	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$558, DW_AT_low_pc(0x00)
	.dwattr $C$DW$558, DW_AT_TI_call
	.dwattr $C$DW$558, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |1092| 
           ADDKPC  .S2     $C$RL124,B3,3     ; |1092| 
           MV      .L1X    B5,A6             ; |1092| 
$C$RL124:  ; CALL OCCURS {A3} {0}            ; |1092| 
           MV      .L1     A4,A0             ; |1092| 
   [ A0]   BNOP    .S1     $C$L107,5         ; |1092| 
           ; BRANCHCC OCCURS {$C$L107}       ; |1092| 
$C$DW$L$_Sv_Msg__FPv$50$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_Sv_Msg__FPv$51$B:
	.dwpsn	file "test_c.cpp",line 1093,column 4,is_stmt
;----------------------------------------------------------------------
; 1093 | case RECV_TEST_PACKET:                                                 
;----------------------------------------------------------------------
	.dwpsn	file "test_c.cpp",line 1094,column 5,is_stmt
           LDW     .D2T2   *+SP(9188),B0     ; |1094| 
           NOP             4
   [!B0]   BNOP    .S1     $C$L107,5         ; |1094| 
           ; BRANCHCC OCCURS {$C$L107}       ; |1094| 
$C$DW$L$_Sv_Msg__FPv$51$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_Sv_Msg__FPv$52$B:
	.dwpsn	file "test_c.cpp",line 1095,column 4,is_stmt
	.dwpsn	file "test_c.cpp",line 1096,column 5,is_stmt
;----------------------------------------------------------------------
; 1096 | uint32 lenn = 1400+20;                                                 
; 1097 | net_descriptor* p_rxd = NULL;                                          
;----------------------------------------------------------------------

           MV      .L2     B0,B4
||         LDW     .D2T2   *+SP(9184),B5     ; |1096| 

           LDW     .D2T2   *+B4(12),B4       ; |1096| 
           NOP             4
           CMPEQ   .L2     B4,B5,B0          ; |1096| 
   [ B0]   BNOP    .S1     $C$L106,5         ; |1096| 
           ; BRANCHCC OCCURS {$C$L106}       ; |1096| 
$C$DW$L$_Sv_Msg__FPv$52$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_Sv_Msg__FPv$53$B:
	.dwpsn	file "test_c.cpp",line 1098,column 4,is_stmt
;----------------------------------------------------------------------
; 1098 | //              uint32 res = 0;                                        
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+284,A3
           MVKH    .S1     ___syscall_tab+284,A3
           LDW     .D1T1   *A3,A3            ; |1098| 
           LDW     .D2T1   *+SP(9180),A4     ; |1098| 
           MVK     .S2     9188,B4           ; |1098| 
           ADD     .L2     B4,SP,B5          ; |1098| 
           MVK     .S2     0x1101,B4         ; |1098| 
$C$DW$559	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$559, DW_AT_low_pc(0x00)
	.dwattr $C$DW$559, DW_AT_TI_call
	.dwattr $C$DW$559, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |1098| 
           ADDKPC  .S2     $C$RL125,B3,3     ; |1098| 
           MV      .L1X    B5,A6             ; |1098| 
$C$RL125:  ; CALL OCCURS {A3} {0}            ; |1098| 
	.dwpsn	file "test_c.cpp",line 1099,column 6,is_stmt
;----------------------------------------------------------------------
; 1099 | uint32 retry10 = 5;                                                    
; 1102 | FileNet = drv_mkd("/dev/net/eth0");                                    
;----------------------------------------------------------------------
           BNOP    .S1     $C$L107,5         ; |1099| 
           ; BRANCH OCCURS {$C$L107}         ; |1099| 
$C$DW$L$_Sv_Msg__FPv$53$E:
;** --------------------------------------------------------------------------*
;** --------------------------------------------------------------------------*
$C$L106:    
$C$DW$L$_Sv_Msg__FPv$55$B:
	.dwpsn	file "test_c.cpp",line 1103,column 5,is_stmt
;----------------------------------------------------------------------
; 1103 | if(FileNet == RES_VOID)                                                
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(9192),B4     ; |1103| 
           NOP             4
           ADD     .L2     1,B4,B4           ; |1103| 
           STW     .D2T2   B4,*+SP(9192)     ; |1103| 
	.dwpsn	file "test_c.cpp",line 1104,column 5,is_stmt
;----------------------------------------------------------------------
; 1104 | goto close_drv2;                                                       
;----------------------------------------------------------------------
           BNOP    .S1     $C$L108,5         ; |1104| 
           ; BRANCH OCCURS {$C$L108}         ; |1104| 
$C$DW$L$_Sv_Msg__FPv$55$E:
;** --------------------------------------------------------------------------*
$C$L107:    
$C$DW$L$_Sv_Msg__FPv$56$B:
	.dwpsn	file "test_c.cpp",line 1106,column 3,is_stmt
           LDW     .D2T2   *+SP(9192),B0     ; |1106| 
           NOP             4
   [ B0]   BNOP    .S1     $C$L105,3         ; |1106| 
           SUB     .L2     B0,1,B4           ; |1106| 
           STW     .D2T2   B4,*+SP(9192)     ; |1106| 
           ; BRANCHCC OCCURS {$C$L105}       ; |1106| 
$C$DW$L$_Sv_Msg__FPv$56$E:
;** --------------------------------------------------------------------------*
$C$L108:    
$C$DW$L$_Sv_Msg__FPv$57$B:
	.dwpsn	file "test_c.cpp",line 1108,column 3,is_stmt
;----------------------------------------------------------------------
; 1108 | while(retry10--)                                                       
;----------------------------------------------------------------------
           MV      .L2     B4,B0
   [ B0]   BNOP    .S1     $C$L109,5         ; |1108| 
           ; BRANCHCC OCCURS {$C$L109}       ; |1108| 
$C$DW$L$_Sv_Msg__FPv$57$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_Sv_Msg__FPv$58$B:
	.dwpsn	file "test_c.cpp",line 1110,column 3,is_stmt
;----------------------------------------------------------------------
; 1110 | if( drv_ioctl( FileNet, NET_RECV_GET, &p_rxd ) != OSE_OK )             
;----------------------------------------------------------------------
           MVK     .L2     1,B4              ; |1110| 
           STW     .D2T2   B4,*+SP(20)       ; |1110| 
	.dwpsn	file "test_c.cpp",line 1111,column 9,is_stmt
;----------------------------------------------------------------------
; 1111 | continue;                                                              
; 1112 | if( p_rxd == NULL )                                                    
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+384,A3
           MVKH    .S1     ___syscall_tab+384,A3
           LDW     .D1T1   *A3,A3            ; |1111| 
           LDW     .D2T1   *+SP(12),A4       ; |1111| 
           ADD     .D2     SP,16,B4          ; |1111| 
           MVK     .L1     0x8,A6            ; |1111| 
           NOP             1
$C$DW$560	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$560, DW_AT_low_pc(0x00)
	.dwattr $C$DW$560, DW_AT_TI_call
	.dwattr $C$DW$560, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |1111| 
           ADDKPC  .S2     $C$RL126,B3,4     ; |1111| 
$C$RL126:  ; CALL OCCURS {A3} {0}            ; |1111| 
	.dwpsn	file "test_c.cpp",line 1113,column 3,is_stmt
;----------------------------------------------------------------------
; 1113 | continue;                                                              
; 1114 | if( p_rxd->length != lenn)                                             
; 1116 | drv_ioctl( FileNet, NET_RECV_PUT, &p_rxd );                            
;----------------------------------------------------------------------
           BNOP    .S1     $C$L110,5         ; |1113| 
           ; BRANCH OCCURS {$C$L110}         ; |1113| 
$C$DW$L$_Sv_Msg__FPv$58$E:
;** --------------------------------------------------------------------------*
$C$L109:    
$C$DW$L$_Sv_Msg__FPv$59$B:
	.dwpsn	file "test_c.cpp",line 1117,column 3,is_stmt
;----------------------------------------------------------------------
; 1117 | continue;                                                              
; 1119 | else                                                                   
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(9188),B4     ; |1117| 
           ZERO    .L1     A4                ; |1117| 
           NOP             3
$C$DW$561	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$561, DW_AT_low_pc(0x04)
	.dwattr $C$DW$561, DW_AT_name("_WriteDARAM__FUsPvT1")
	.dwattr $C$DW$561, DW_AT_TI_call

           MV      .L1X    B4,A3             ; |1117| 
||         CALL    .S1     _WriteDARAM__FUsPvT1 ; |1117| 

           LDHU    .D2T1   *+B4(12),A6       ; |1117| 
||         LDW     .D1T2   *+A3(16),B4       ; |1117| 

           ADDKPC  .S2     $C$RL127,B3,3     ; |1117| 
$C$RL127:  ; CALL OCCURS {_WriteDARAM__FUsPvT1} {0}  ; |1117| 
	.dwpsn	file "test_c.cpp",line 1121,column 3,is_stmt
;----------------------------------------------------------------------
; 1121 | retry10++;                                                             
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+284,A3
           MVKH    .S1     ___syscall_tab+284,A3
           LDW     .D1T1   *A3,A3            ; |1121| 
           LDW     .D2T1   *+SP(9180),A4     ; |1121| 
           MVK     .S2     9188,B4           ; |1121| 
           ADD     .L2     B4,SP,B5          ; |1121| 
           MVK     .S2     0x1101,B4         ; |1121| 
$C$DW$562	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$562, DW_AT_low_pc(0x00)
	.dwattr $C$DW$562, DW_AT_TI_call
	.dwattr $C$DW$562, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |1121| 
           ADDKPC  .S2     $C$RL128,B3,3     ; |1121| 
           MV      .L1X    B5,A6             ; |1121| 
$C$RL128:  ; CALL OCCURS {A3} {0}            ; |1121| 
           MV      .L1     A4,A0             ; |1121| 
   [ A0]   BNOP    .S1     $C$L110,5         ; |1121| 
           ; BRANCHCC OCCURS {$C$L110}       ; |1121| 
$C$DW$L$_Sv_Msg__FPv$59$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_Sv_Msg__FPv$60$B:
	.dwpsn	file "test_c.cpp",line 1122,column 4,is_stmt
;----------------------------------------------------------------------
; 1122 | break;                                                                 
;----------------------------------------------------------------------
	.dwpsn	file "test_c.cpp",line 1125,column 3,is_stmt
           ZERO    .L2     B4                ; |1125| 
           STW     .D2T2   B4,*+SP(20)       ; |1125| 
	.dwpsn	file "test_c.cpp",line 1126,column 9,is_stmt
;----------------------------------------------------------------------
; 1126 | if(!retry10)                                                           
; 1128 | cdg_error.ask = TPO_ERR;                                               
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+384,A3
           MVKH    .S1     ___syscall_tab+384,A3
           LDW     .D1T1   *A3,A3            ; |1126| 
           LDW     .D2T1   *+SP(12),A4       ; |1126| 
           ADD     .D2     SP,16,B4          ; |1126| 
           MVK     .L1     0x8,A6            ; |1126| 
           NOP             1
$C$DW$563	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$563, DW_AT_low_pc(0x00)
	.dwattr $C$DW$563, DW_AT_TI_call
	.dwattr $C$DW$563, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |1126| 
           ADDKPC  .S2     $C$RL129,B3,4     ; |1126| 
$C$RL129:  ; CALL OCCURS {A3} {0}            ; |1126| 
$C$DW$L$_Sv_Msg__FPv$60$E:
;** --------------------------------------------------------------------------*
$C$L110:    
$C$DW$L$_Sv_Msg__FPv$61$B:
	.dwpsn	file "test_c.cpp",line 1129,column 3,is_stmt
;----------------------------------------------------------------------
; 1129 | msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));                   
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+296,A3
           MVKH    .S1     ___syscall_tab+296,A3
           LDW     .D1T1   *A3,A3            ; |1129| 
           LDW     .D2T1   *+SP(9180),A4     ; |1129| 
           NOP             3
$C$DW$564	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$564, DW_AT_low_pc(0x00)
	.dwattr $C$DW$564, DW_AT_TI_call
	.dwattr $C$DW$564, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |1129| 
           ADDKPC  .S2     $C$RL130,B3,4     ; |1129| 
$C$RL130:  ; CALL OCCURS {A3} {0}            ; |1129| 
	.dwendtag $C$DW$553

	.dwpsn	file "test_c.cpp",line 1131,column 8,is_stmt
;----------------------------------------------------------------------
; 1131 | goto close_drv2;                                                       
; 1134 | //              memcpy( buf1, p_rxd->data, p_rxd->length );            
; 1135 | WriteDARAM(0, p_rxd->data, p_rxd->length);                             
; 1137 | //              sleep_m(50);                                           
;----------------------------------------------------------------------
           BNOP    .S1     $C$L116,5         ; |1131| 
           ; BRANCH OCCURS {$C$L116}         ; |1131| 
$C$DW$L$_Sv_Msg__FPv$61$E:
;** --------------------------------------------------------------------------*
$C$L111:    
$C$DW$L$_Sv_Msg__FPv$62$B:

$C$DW$565	.dwtag  DW_TAG_lexical_block, DW_AT_low_pc(0x00), DW_AT_high_pc(0x00)
$C$DW$566	.dwtag  DW_TAG_variable, DW_AT_name("p_rxd")
	.dwattr $C$DW$566, DW_AT_TI_symbol_name("_p_rxd")
	.dwattr $C$DW$566, DW_AT_type(*$C$DW$T$570)
	.dwattr $C$DW$566, DW_AT_location[DW_OP_breg31 9184]
	.dwpsn	file "test_c.cpp",line 1138,column 19,is_stmt
           ZERO    .L2     B4                ; |1138| 
           STW     .D2T2   B4,*+SP(9184)     ; |1138| 
	.dwpsn	file "test_c.cpp",line 1139,column 3,is_stmt
;----------------------------------------------------------------------
; 1139 | if(drv_ioctl( FileNet, NET_RECV_PUT, &p_rxd ) != OSE_OK)               
; 1140 |         goto close_drv2;                                               
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+292,A3
           MVKH    .S1     ___syscall_tab+292,A3
           LDW     .D1T1   *A3,A3            ; |1139| 
           MVKL    .S1     $C$SL1+0,A4       ; |1139| 
           MVKH    .S1     $C$SL1+0,A4       ; |1139| 
           NOP             2
$C$DW$567	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$567, DW_AT_low_pc(0x00)
	.dwattr $C$DW$567, DW_AT_TI_call
	.dwattr $C$DW$567, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |1139| 
           ADDKPC  .S2     $C$RL131,B3,4     ; |1139| 
$C$RL131:  ; CALL OCCURS {A3} {0}            ; |1139| 
           STW     .D2T1   A4,*+SP(9180)     ; |1139| 
$C$DW$L$_Sv_Msg__FPv$62$E:
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
$C$L112:    
$C$DW$L$_Sv_Msg__FPv$63$B:
	.dwpsn	file "test_c.cpp",line 1143,column 6,is_stmt
;----------------------------------------------------------------------
; 1143 | cdg_error.ask = TPO_OK;                                                
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+284,A3
           MVKH    .S1     ___syscall_tab+284,A3
           LDW     .D1T1   *A3,A3            ; |1143| 
           LDW     .D2T1   *+SP(9180),A4     ; |1143| 
           MVK     .S2     9184,B4           ; |1143| 
           ADD     .L2     B4,SP,B5          ; |1143| 
           MVK     .S2     0x1100,B4         ; |1143| 
$C$DW$568	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$568, DW_AT_low_pc(0x00)
	.dwattr $C$DW$568, DW_AT_TI_call
	.dwattr $C$DW$568, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |1143| 
           ADDKPC  .S2     $C$RL132,B3,3     ; |1143| 
           MV      .L1X    B5,A6             ; |1143| 
$C$RL132:  ; CALL OCCURS {A3} {0}            ; |1143| 
	.dwpsn	file "test_c.cpp",line 1144,column 7,is_stmt
;----------------------------------------------------------------------
; 1144 | msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));                   
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(9184),B0     ; |1144| 
           NOP             4
   [!B0]   BNOP    .S1     $C$L113,5         ; |1144| 
           ; BRANCHCC OCCURS {$C$L113}       ; |1144| 
$C$DW$L$_Sv_Msg__FPv$63$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_Sv_Msg__FPv$64$B:
	.dwpsn	file "test_c.cpp",line 1145,column 6,is_stmt
           MVKL    .S1     ___syscall_tab+284,A3
           MVKH    .S1     ___syscall_tab+284,A3
           LDW     .D1T1   *A3,A3            ; |1145| 
           LDW     .D2T1   *+SP(9180),A4     ; |1145| 
           MVK     .S2     9184,B4           ; |1145| 
           ADD     .L2     B4,SP,B5          ; |1145| 
           MVK     .S2     0x1101,B4         ; |1145| 
$C$DW$569	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$569, DW_AT_low_pc(0x00)
	.dwattr $C$DW$569, DW_AT_TI_call
	.dwattr $C$DW$569, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |1145| 
           ADDKPC  .S2     $C$RL133,B3,3     ; |1145| 
           MV      .L1X    B5,A6             ; |1145| 
$C$RL133:  ; CALL OCCURS {A3} {0}            ; |1145| 
$C$DW$L$_Sv_Msg__FPv$64$E:
;** --------------------------------------------------------------------------*
$C$L113:    
$C$DW$L$_Sv_Msg__FPv$65$B:
	.dwpsn	file "test_c.cpp",line 1146,column 11,is_stmt
;----------------------------------------------------------------------
; 1146 | close_drv2:                                                            
; 1147 | drv_rmd(FileNet);                                                      
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(9184),B0     ; |1146| 
           NOP             4
   [ B0]   BNOP    .S1     $C$L112,5         ; |1146| 
           ; BRANCHCC OCCURS {$C$L112}       ; |1146| 
$C$DW$L$_Sv_Msg__FPv$65$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_Sv_Msg__FPv$66$B:
	.dwpsn	file "test_c.cpp",line 1149,column 4,is_stmt
;----------------------------------------------------------------------
; 1149 | break;                                                                 
;----------------------------------------------------------------------
           MVKL    .S2     ___syscall_tab+296,B4
           MVKH    .S2     ___syscall_tab+296,B4
           LDW     .D2T2   *B4,B4            ; |1149| 
           LDW     .D2T1   *+SP(9180),A4     ; |1149| 
           NOP             3
$C$DW$570	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$570, DW_AT_low_pc(0x00)
	.dwattr $C$DW$570, DW_AT_TI_call
	.dwattr $C$DW$570, DW_AT_TI_indirect
           CALL    .S2     B4                ; |1149| 
           ADDKPC  .S2     $C$RL134,B3,4     ; |1149| 
$C$RL134:  ; CALL OCCURS {B4} {0}            ; |1149| 
	.dwpsn	file "test_c.cpp",line 1151,column 4,is_stmt
           ZERO    .L2     B4                ; |1151| 
           STW     .D2T2   B4,*+SP(20)       ; |1151| 
	.dwpsn	file "test_c.cpp",line 1152,column 10,is_stmt
;----------------------------------------------------------------------
; 1153 | case CLEAR_TEST_PACKET:                                                
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+384,A3
           MVKH    .S1     ___syscall_tab+384,A3
           LDW     .D1T1   *A3,A3            ; |1152| 
           LDW     .D2T1   *+SP(12),A4       ; |1152| 
           MVK     .L1     0x8,A6            ; |1152| 
           ADD     .D2     SP,16,B4          ; |1152| 
           NOP             1
$C$DW$571	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$571, DW_AT_low_pc(0x00)
	.dwattr $C$DW$571, DW_AT_TI_call
	.dwattr $C$DW$571, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |1152| 
           ADDKPC  .S2     $C$RL135,B3,4     ; |1152| 
$C$RL135:  ; CALL OCCURS {A3} {0}            ; |1152| 
	.dwendtag $C$DW$565

	.dwpsn	file "test_c.cpp",line 1155,column 8,is_stmt
;----------------------------------------------------------------------
; 1156 | net_descriptor* p_rxd = NULL;                                          
; 1157 | FileNet = drv_mkd("/dev/net/eth0");                                    
; 1159 |         do//очистка приема                                             
;----------------------------------------------------------------------
           BNOP    .S1     $C$L116,5         ; |1155| 
           ; BRANCH OCCURS {$C$L116}         ; |1155| 
$C$DW$L$_Sv_Msg__FPv$66$E:
;** --------------------------------------------------------------------------*
$C$L114:    
$C$DW$L$_Sv_Msg__FPv$67$B:
	.dwpsn	file "test_c.cpp",line 1161,column 8,is_stmt
;----------------------------------------------------------------------
; 1161 | drv_ioctl( FileNet, NET_RECV_GET, &p_rxd );                            
;----------------------------------------------------------------------
           MVKL    .S2     0xd0026,B4
           MVKH    .S2     0xd0026,B4
           STW     .D2T2   B4,*+SP(16)       ; |1161| 
	.dwpsn	file "test_c.cpp",line 1162,column 8,is_stmt
;----------------------------------------------------------------------
; 1162 | if( p_rxd != NULL )                                                    
;----------------------------------------------------------------------
           MVK     .L2     1,B4              ; |1162| 
           STW     .D2T2   B4,*+SP(20)       ; |1162| 
	.dwpsn	file "test_c.cpp",line 1163,column 8,is_stmt
;----------------------------------------------------------------------
; 1163 | drv_ioctl( FileNet, NET_RECV_PUT, &p_rxd );                            
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+384,A3
           MVKH    .S1     ___syscall_tab+384,A3
           LDW     .D1T1   *A3,A3            ; |1163| 
           LDW     .D2T2   *+SP(24),B4       ; |1163| 
           MVK     .L1     0x8,A6            ; |1163| 
           NOP             2
$C$DW$572	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$572, DW_AT_low_pc(0x00)
	.dwattr $C$DW$572, DW_AT_TI_call
	.dwattr $C$DW$572, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |1163| 
           LDW     .D2T1   *+B4(12),A4       ; |1163| 
           ADDKPC  .S2     $C$RL136,B3,2     ; |1163| 
           ADD     .D2     SP,16,B4          ; |1163| 
$C$RL136:  ; CALL OCCURS {A3} {0}            ; |1163| 
	.dwpsn	file "test_c.cpp",line 1164,column 7,is_stmt
;----------------------------------------------------------------------
; 1164 | }while(p_rxd != NULL);                                                 
; 1167 | drv_rmd(FileNet);                                                      
;----------------------------------------------------------------------
           BNOP    .S1     $C$L116,5         ; |1164| 
           ; BRANCH OCCURS {$C$L116}         ; |1164| 
$C$DW$L$_Sv_Msg__FPv$67$E:
;** --------------------------------------------------------------------------*
$C$L115:    
$C$DW$L$_Sv_Msg__FPv$68$B:
	.dwpsn	file "test_c.cpp",line 886,column 5,is_stmt
           LDW     .D2T2   *+SP(16),B4       ; |886| 
           MVKL    .S2     0xd0005,B5
           MVKH    .S2     0xd0005,B5
           NOP             2
           CMPEQ   .L2     B4,B5,B0          ; |886| 
   [ B0]   BNOP    .S1     $C$L84,5          ; |886| 
           ; BRANCHCC OCCURS {$C$L84}        ; |886| 
$C$DW$L$_Sv_Msg__FPv$68$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_Sv_Msg__FPv$69$B:
           MVKL    .S2     0xd0016,B5
           MVKH    .S2     0xd0016,B5
           SUB     .L2     B4,B5,B5          ; |886| 
           CMPGTU  .L2     B5,7,B0           ; |886| 
   [ B0]   BNOP    .S1     $C$L114,5         ; |886| 
           ; BRANCHCC OCCURS {$C$L114} {-8}  ; |886| 
$C$DW$L$_Sv_Msg__FPv$69$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_Sv_Msg__FPv$70$B:
           MVKL    .S1     0x340058,A3

           MVKH    .S1     0x340058,A3
||         MVKL    .S2     $C$SW3,B5

           SHL     .S2     B4,2,B4           ; |886| 

           SUB     .L2X    B4,A3,B4          ; |886| 
||         MVKH    .S2     $C$SW3,B5

           ADD     .L2     B5,B4,B4          ; |886| 
           LDW     .D2T2   *B4,B4            ; |886| 
           NOP             4
           BNOP    .S2     B4,5              ; |886| 
           ; BRANCH OCCURS {B4}              ; |886| 
	.sect	".switch"
	.clink
$C$SW3:	.word	$C$L111	; 851990
	.word	$C$L104	; 851991
	.word	$C$L98	; 851992
	.word	$C$L114	; 0
	.word	$C$L86	; 851994
	.word	$C$L89	; 851995
	.word	$C$L92	; 851996
	.word	$C$L95	; 851997
	.sect	".text"
$C$DW$L$_Sv_Msg__FPv$70$E:
;** --------------------------------------------------------------------------*
$C$L116:    
$C$DW$L$_Sv_Msg__FPv$71$B:
	.dwpsn	file "test_c.cpp",line 1168,column 3,is_stmt
;----------------------------------------------------------------------
; 1169 | cdg_error.ask = TPO_OK;                                                
;----------------------------------------------------------------------
           MVKL    .S1     _sv_msg_open,A3
           MVKH    .S1     _sv_msg_open,A3
           LDW     .D1T1   *A3,A0            ; |1168| 
           NOP             4
   [ A0]   BNOP    .S1     $C$L81,5          ; |1168| 
           ; BRANCHCC OCCURS {$C$L81}        ; |1168| 
$C$DW$L$_Sv_Msg__FPv$71$E:
;** --------------------------------------------------------------------------*
$C$L117:    
	.dwpsn	file "test_c.cpp",line 1170,column 1,is_stmt
;----------------------------------------------------------------------
; 1170 | msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));                   
;----------------------------------------------------------------------
           MVKL    .S2     ___syscall_tab+380,B4
           MVKH    .S2     ___syscall_tab+380,B4
           LDW     .D2T2   *B4,B4            ; |1170| 
           NOP             4
$C$DW$573	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$573, DW_AT_low_pc(0x00)
	.dwattr $C$DW$573, DW_AT_TI_call
	.dwattr $C$DW$573, DW_AT_TI_indirect
           CALL    .S2     B4                ; |1170| 
           ADDKPC  .S2     $C$RL137,B3,4     ; |1170| 
$C$RL137:  ; CALL OCCURS {B4} {0}            ; |1170| 
	.dwpsn	file "test_c.cpp",line 1171,column 1,is_stmt
           MVKL    .S1     ___syscall_tab+44,A3
           MVKH    .S1     ___syscall_tab+44,A3
           LDW     .D1T1   *A3,A3            ; |1171| 
           NOP             4
$C$DW$574	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$574, DW_AT_low_pc(0x00)
	.dwattr $C$DW$574, DW_AT_TI_call
	.dwattr $C$DW$574, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |1171| 
           ADDKPC  .S2     $C$RL138,B3,4     ; |1171| 
$C$RL138:  ; CALL OCCURS {A3} {0}            ; |1171| 
	.dwpsn	file "test_c.cpp",line 1172,column 7,is_stmt
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
$C$L118:    
$C$DW$L$_Sv_Msg__FPv$73$B:
           BNOP    .S1     $C$L118,5         ; |1172| 
           ; BRANCH OCCURS {$C$L118}         ; |1172| 
$C$DW$L$_Sv_Msg__FPv$73$E:
;** --------------------------------------------------------------------------*
	.dwcfi	restore_reg, 19
	.dwcfi	cfa_offset, 0
	.dwcfi	cfa_offset, 0

$C$DW$575	.dwtag  DW_TAG_TI_loop
	.dwattr $C$DW$575, DW_AT_name("C:\1901VC1T_Inteltech\3rdPartyLIB\dsp_core\C6000\tpo_amoeba\source\test_c.asm:$C$L118:1:1517815039")
	.dwattr $C$DW$575, DW_AT_TI_begin_file("test_c.cpp")
	.dwattr $C$DW$575, DW_AT_TI_begin_line(0x494)
	.dwattr $C$DW$575, DW_AT_TI_end_line(0x494)
$C$DW$576	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$576, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$73$B)
	.dwattr $C$DW$576, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$73$E)
	.dwendtag $C$DW$575


$C$DW$577	.dwtag  DW_TAG_TI_loop
	.dwattr $C$DW$577, DW_AT_name("C:\1901VC1T_Inteltech\3rdPartyLIB\dsp_core\C6000\tpo_amoeba\source\test_c.asm:$C$L81:1:1517815039")
	.dwattr $C$DW$577, DW_AT_TI_begin_file("test_c.cpp")
	.dwattr $C$DW$577, DW_AT_TI_begin_line(0x35e)
	.dwattr $C$DW$577, DW_AT_TI_end_line(0x490)
$C$DW$578	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$578, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$5$B)
	.dwattr $C$DW$578, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$5$E)
$C$DW$579	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$579, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$62$B)
	.dwattr $C$DW$579, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$62$E)
$C$DW$580	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$580, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$49$B)
	.dwattr $C$DW$580, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$49$E)
$C$DW$581	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$581, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$55$B)
	.dwattr $C$DW$581, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$55$E)
$C$DW$582	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$582, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$57$B)
	.dwattr $C$DW$582, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$57$E)
$C$DW$583	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$583, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$48$B)
	.dwattr $C$DW$583, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$48$E)
$C$DW$584	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$584, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$58$B)
	.dwattr $C$DW$584, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$58$E)
$C$DW$585	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$585, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$59$B)
	.dwattr $C$DW$585, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$59$E)
$C$DW$586	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$586, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$60$B)
	.dwattr $C$DW$586, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$60$E)
$C$DW$587	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$587, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$42$B)
	.dwattr $C$DW$587, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$42$E)
$C$DW$588	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$588, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$43$B)
	.dwattr $C$DW$588, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$43$E)
$C$DW$589	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$589, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$44$B)
	.dwattr $C$DW$589, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$44$E)
$C$DW$590	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$590, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$45$B)
	.dwattr $C$DW$590, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$45$E)
$C$DW$591	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$591, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$46$B)
	.dwattr $C$DW$591, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$46$E)
$C$DW$592	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$592, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$36$B)
	.dwattr $C$DW$592, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$36$E)
$C$DW$593	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$593, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$37$B)
	.dwattr $C$DW$593, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$37$E)
$C$DW$594	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$594, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$31$B)
	.dwattr $C$DW$594, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$31$E)
$C$DW$595	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$595, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$32$B)
	.dwattr $C$DW$595, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$32$E)
$C$DW$596	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$596, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$33$B)
	.dwattr $C$DW$596, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$33$E)
$C$DW$597	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$597, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$34$B)
	.dwattr $C$DW$597, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$34$E)
$C$DW$598	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$598, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$26$B)
	.dwattr $C$DW$598, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$26$E)
$C$DW$599	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$599, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$27$B)
	.dwattr $C$DW$599, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$27$E)
$C$DW$600	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$600, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$28$B)
	.dwattr $C$DW$600, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$28$E)
$C$DW$601	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$601, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$29$B)
	.dwattr $C$DW$601, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$29$E)
$C$DW$602	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$602, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$21$B)
	.dwattr $C$DW$602, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$21$E)
$C$DW$603	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$603, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$22$B)
	.dwattr $C$DW$603, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$22$E)
$C$DW$604	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$604, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$23$B)
	.dwattr $C$DW$604, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$23$E)
$C$DW$605	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$605, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$24$B)
	.dwattr $C$DW$605, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$24$E)
$C$DW$606	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$606, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$69$B)
	.dwattr $C$DW$606, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$69$E)
$C$DW$607	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$607, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$70$B)
	.dwattr $C$DW$607, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$70$E)
$C$DW$608	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$608, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$16$B)
	.dwattr $C$DW$608, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$16$E)
$C$DW$609	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$609, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$17$B)
	.dwattr $C$DW$609, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$17$E)
$C$DW$610	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$610, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$18$B)
	.dwattr $C$DW$610, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$18$E)
$C$DW$611	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$611, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$19$B)
	.dwattr $C$DW$611, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$19$E)
$C$DW$612	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$612, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$13$B)
	.dwattr $C$DW$612, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$13$E)
$C$DW$613	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$613, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$10$B)
	.dwattr $C$DW$613, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$10$E)
$C$DW$614	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$614, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$68$B)
	.dwattr $C$DW$614, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$68$E)
$C$DW$615	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$615, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$8$B)
	.dwattr $C$DW$615, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$8$E)
$C$DW$616	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$616, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$6$B)
	.dwattr $C$DW$616, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$6$E)
$C$DW$617	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$617, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$7$B)
	.dwattr $C$DW$617, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$7$E)
$C$DW$618	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$618, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$9$B)
	.dwattr $C$DW$618, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$9$E)
$C$DW$619	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$619, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$12$B)
	.dwattr $C$DW$619, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$12$E)
$C$DW$620	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$620, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$14$B)
	.dwattr $C$DW$620, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$14$E)
$C$DW$621	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$621, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$15$B)
	.dwattr $C$DW$621, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$15$E)
$C$DW$622	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$622, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$20$B)
	.dwattr $C$DW$622, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$20$E)
$C$DW$623	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$623, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$25$B)
	.dwattr $C$DW$623, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$25$E)
$C$DW$624	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$624, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$30$B)
	.dwattr $C$DW$624, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$30$E)
$C$DW$625	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$625, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$35$B)
	.dwattr $C$DW$625, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$35$E)
$C$DW$626	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$626, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$41$B)
	.dwattr $C$DW$626, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$41$E)
$C$DW$627	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$627, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$47$B)
	.dwattr $C$DW$627, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$47$E)
$C$DW$628	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$628, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$61$B)
	.dwattr $C$DW$628, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$61$E)
$C$DW$629	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$629, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$66$B)
	.dwattr $C$DW$629, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$66$E)
$C$DW$630	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$630, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$67$B)
	.dwattr $C$DW$630, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$67$E)
$C$DW$631	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$631, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$71$B)
	.dwattr $C$DW$631, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$71$E)

$C$DW$632	.dwtag  DW_TAG_TI_loop
	.dwattr $C$DW$632, DW_AT_name("C:\1901VC1T_Inteltech\3rdPartyLIB\dsp_core\C6000\tpo_amoeba\source\test_c.asm:$C$L112:2:1517815039")
	.dwattr $C$DW$632, DW_AT_TI_begin_file("test_c.cpp")
	.dwattr $C$DW$632, DW_AT_TI_begin_line(0x475)
	.dwattr $C$DW$632, DW_AT_TI_end_line(0x47a)
$C$DW$633	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$633, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$63$B)
	.dwattr $C$DW$633, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$63$E)
$C$DW$634	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$634, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$64$B)
	.dwattr $C$DW$634, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$64$E)
$C$DW$635	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$635, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$65$B)
	.dwattr $C$DW$635, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$65$E)
	.dwendtag $C$DW$632


$C$DW$636	.dwtag  DW_TAG_TI_loop
	.dwattr $C$DW$636, DW_AT_name("C:\1901VC1T_Inteltech\3rdPartyLIB\dsp_core\C6000\tpo_amoeba\source\test_c.asm:$C$L105:2:1517815039")
	.dwattr $C$DW$636, DW_AT_TI_begin_file("test_c.cpp")
	.dwattr $C$DW$636, DW_AT_TI_begin_line(0x442)
	.dwattr $C$DW$636, DW_AT_TI_end_line(0x452)
$C$DW$637	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$637, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$50$B)
	.dwattr $C$DW$637, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$50$E)
$C$DW$638	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$638, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$52$B)
	.dwattr $C$DW$638, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$52$E)
$C$DW$639	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$639, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$51$B)
	.dwattr $C$DW$639, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$51$E)
$C$DW$640	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$640, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$53$B)
	.dwattr $C$DW$640, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$53$E)
$C$DW$641	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$641, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$56$B)
	.dwattr $C$DW$641, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$56$E)
	.dwendtag $C$DW$636


$C$DW$642	.dwtag  DW_TAG_TI_loop
	.dwattr $C$DW$642, DW_AT_name("C:\1901VC1T_Inteltech\3rdPartyLIB\dsp_core\C6000\tpo_amoeba\source\test_c.asm:$C$L99:2:1517815039")
	.dwattr $C$DW$642, DW_AT_TI_begin_file("test_c.cpp")
	.dwattr $C$DW$642, DW_AT_TI_begin_line(0x402)
	.dwattr $C$DW$642, DW_AT_TI_end_line(0x40e)
$C$DW$643	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$643, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$38$B)
	.dwattr $C$DW$643, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$38$E)
$C$DW$644	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$644, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$39$B)
	.dwattr $C$DW$644, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$39$E)
$C$DW$645	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$645, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$40$B)
	.dwattr $C$DW$645, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$40$E)
	.dwendtag $C$DW$642

	.dwendtag $C$DW$577


$C$DW$646	.dwtag  DW_TAG_TI_loop
	.dwattr $C$DW$646, DW_AT_name("C:\1901VC1T_Inteltech\3rdPartyLIB\dsp_core\C6000\tpo_amoeba\source\test_c.asm:$C$L79:1:1517815039")
	.dwattr $C$DW$646, DW_AT_TI_begin_file("test_c.cpp")
	.dwattr $C$DW$646, DW_AT_TI_begin_line(0x35c)
	.dwattr $C$DW$646, DW_AT_TI_end_line(0x35c)
$C$DW$647	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$647, DW_AT_low_pc($C$DW$L$_Sv_Msg__FPv$3$B)
	.dwattr $C$DW$647, DW_AT_high_pc($C$DW$L$_Sv_Msg__FPv$3$E)
	.dwendtag $C$DW$646

	.dwattr $C$DW$477, DW_AT_TI_end_file("test_c.cpp")
	.dwattr $C$DW$477, DW_AT_TI_end_line(0x495)
	.dwattr $C$DW$477, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$477

;******************************************************************************
;* STRINGS                                                                    *
;******************************************************************************
	.sect	".const:.string"
$C$SL1:	.string	"/dev/net/eth0",0
$C$SL2:	.string	"sv",0
;*****************************************************************************
;* UNDEFINED EXTERNAL REFERENCES                                             *
;*****************************************************************************
	.global	_memset
	.global	_memcmp
	.global	_EDMA_intClear__FUi
	.global	_EDMA_intTest__FUi
	.global	_EDMA_qdmaConfigArgs__FUiN41
	.global	_analysis_hash_fwmem__FP11hash_window
	.global	___syscall_tab
	.global	_hwindow
	.global	_sh_mem_write
	.global	_sh_mem_read_proc
	.global	_sh_mem_read_crypt
	.global	_sh_mem_read_proc2
	.global	_sh_mem_read_crypt2
	.global	_gl_result
	.global	_Start_dozu_nagr
	.global	_sv_msg_open
	.global	_memcpy

;******************************************************************************
;* TYPE INFORMATION                                                           *
;******************************************************************************
$C$DW$T$3	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$3, DW_AT_address_class(0x20)
$C$DW$T$604	.dwtag  DW_TAG_typedef, DW_AT_name("Handle")
	.dwattr $C$DW$T$604, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$T$604, DW_AT_language(DW_LANG_C_plus_plus)

$C$DW$T$680	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$680, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$T$680, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$680, DW_AT_byte_size(0x2d0)
$C$DW$648	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$648, DW_AT_upper_bound(0xb3)
	.dwendtag $C$DW$T$680


$C$DW$T$21	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$21, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$T$211	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$211, DW_AT_type(*$C$DW$T$21)
	.dwattr $C$DW$T$211, DW_AT_address_class(0x20)

$C$DW$T$23	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$23, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$649	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$649, DW_AT_type(*$C$DW$T$22)
	.dwendtag $C$DW$T$23


$C$DW$T$25	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$25, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$650	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$650, DW_AT_type(*$C$DW$T$24)
	.dwendtag $C$DW$T$25


$C$DW$T$29	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$29, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$651	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$651, DW_AT_type(*$C$DW$T$28)
	.dwendtag $C$DW$T$29


$C$DW$T$31	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$31, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$652	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$652, DW_AT_type(*$C$DW$T$30)
	.dwendtag $C$DW$T$31


$C$DW$T$35	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$35, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$653	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$653, DW_AT_type(*$C$DW$T$34)
	.dwendtag $C$DW$T$35


$C$DW$T$38	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$38, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$654	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$654, DW_AT_type(*$C$DW$T$37)
	.dwendtag $C$DW$T$38


$C$DW$T$42	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$42, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$655	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$655, DW_AT_type(*$C$DW$T$41)
	.dwendtag $C$DW$T$42


$C$DW$T$44	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$44, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$656	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$656, DW_AT_type(*$C$DW$T$43)
	.dwendtag $C$DW$T$44


$C$DW$T$48	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$48, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$657	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$657, DW_AT_type(*$C$DW$T$47)
	.dwendtag $C$DW$T$48


$C$DW$T$50	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$50, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$658	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$658, DW_AT_type(*$C$DW$T$49)
	.dwendtag $C$DW$T$50


$C$DW$T$54	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$54, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$659	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$659, DW_AT_type(*$C$DW$T$53)
	.dwendtag $C$DW$T$54


$C$DW$T$57	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$57, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$660	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$660, DW_AT_type(*$C$DW$T$56)
	.dwendtag $C$DW$T$57


$C$DW$T$61	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$61, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$661	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$661, DW_AT_type(*$C$DW$T$60)
	.dwendtag $C$DW$T$61


$C$DW$T$63	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$63, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$662	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$662, DW_AT_type(*$C$DW$T$62)
	.dwendtag $C$DW$T$63


$C$DW$T$67	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$67, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$663	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$663, DW_AT_type(*$C$DW$T$66)
	.dwendtag $C$DW$T$67


$C$DW$T$69	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$69, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$664	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$664, DW_AT_type(*$C$DW$T$68)
	.dwendtag $C$DW$T$69


$C$DW$T$73	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$73, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$665	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$665, DW_AT_type(*$C$DW$T$72)
	.dwendtag $C$DW$T$73


$C$DW$T$76	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$76, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$666	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$666, DW_AT_type(*$C$DW$T$75)
	.dwendtag $C$DW$T$76

$C$DW$T$93	.dwtag  DW_TAG_const_type
$C$DW$T$94	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$94, DW_AT_type(*$C$DW$T$93)
	.dwattr $C$DW$T$94, DW_AT_address_class(0x20)

$C$DW$T$334	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$334, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$667	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$667, DW_AT_type(*$C$DW$T$3)
$C$DW$668	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$668, DW_AT_type(*$C$DW$T$10)
	.dwendtag $C$DW$T$334

$C$DW$T$335	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$335, DW_AT_type(*$C$DW$T$334)
	.dwattr $C$DW$T$335, DW_AT_address_class(0x20)

$C$DW$T$609	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$609, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$669	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$669, DW_AT_type(*$C$DW$T$604)
$C$DW$670	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$670, DW_AT_type(*$C$DW$T$606)
$C$DW$671	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$671, DW_AT_type(*$C$DW$T$598)
	.dwendtag $C$DW$T$609

$C$DW$T$610	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$610, DW_AT_type(*$C$DW$T$609)
	.dwattr $C$DW$T$610, DW_AT_address_class(0x20)

$C$DW$T$619	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$619, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$672	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$672, DW_AT_type(*$C$DW$T$111)
$C$DW$673	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$673, DW_AT_type(*$C$DW$T$618)
	.dwendtag $C$DW$T$619

$C$DW$T$620	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$620, DW_AT_type(*$C$DW$T$619)
	.dwattr $C$DW$T$620, DW_AT_address_class(0x20)

$C$DW$T$687	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$687, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$674	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$674, DW_AT_type(*$C$DW$T$10)
	.dwendtag $C$DW$T$687

$C$DW$T$688	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$688, DW_AT_type(*$C$DW$T$687)
	.dwattr $C$DW$T$688, DW_AT_address_class(0x20)
$C$DW$T$689	.dwtag  DW_TAG_typedef, DW_AT_name("EDMA_IntHandler")
	.dwattr $C$DW$T$689, DW_AT_type(*$C$DW$T$688)
	.dwattr $C$DW$T$689, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$T$4	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$4, DW_AT_encoding(DW_ATE_boolean)
	.dwattr $C$DW$T$4, DW_AT_name("bool")
	.dwattr $C$DW$T$4, DW_AT_byte_size(0x01)
$C$DW$T$5	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$5, DW_AT_encoding(DW_ATE_signed_char)
	.dwattr $C$DW$T$5, DW_AT_name("signed char")
	.dwattr $C$DW$T$5, DW_AT_byte_size(0x01)
$C$DW$T$702	.dwtag  DW_TAG_typedef, DW_AT_name("int8")
	.dwattr $C$DW$T$702, DW_AT_type(*$C$DW$T$5)
	.dwattr $C$DW$T$702, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$T$6	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$6, DW_AT_encoding(DW_ATE_unsigned_char)
	.dwattr $C$DW$T$6, DW_AT_name("unsigned char")
	.dwattr $C$DW$T$6, DW_AT_byte_size(0x01)
$C$DW$T$19	.dwtag  DW_TAG_typedef, DW_AT_name("uint8")
	.dwattr $C$DW$T$19, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$T$19, DW_AT_language(DW_LANG_C_plus_plus)

$C$DW$T$20	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$20, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$T$20, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$20, DW_AT_byte_size(0x02)
$C$DW$675	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$675, DW_AT_upper_bound(0x01)
	.dwendtag $C$DW$T$20


$C$DW$T$40	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$40, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$T$40, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$40, DW_AT_byte_size(0x04)
$C$DW$676	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$676, DW_AT_upper_bound(0x03)
	.dwendtag $C$DW$T$40


$C$DW$T$59	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$59, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$T$59, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$59, DW_AT_byte_size(0x08)
$C$DW$677	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$677, DW_AT_upper_bound(0x07)
	.dwendtag $C$DW$T$59


$C$DW$T$288	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$288, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$T$288, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$288, DW_AT_byte_size(0x10)
$C$DW$678	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$678, DW_AT_upper_bound(0x0f)
	.dwendtag $C$DW$T$288


$C$DW$T$301	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$301, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$T$301, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$301, DW_AT_byte_size(0x400)
$C$DW$679	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$679, DW_AT_upper_bound(0x3ff)
	.dwendtag $C$DW$T$301


$C$DW$T$302	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$302, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$T$302, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$302, DW_AT_byte_size(0x20)
$C$DW$680	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$680, DW_AT_upper_bound(0x1f)
	.dwendtag $C$DW$T$302


$C$DW$T$459	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$459, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$T$459, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$459, DW_AT_byte_size(0x06)
$C$DW$681	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$681, DW_AT_upper_bound(0x05)
	.dwendtag $C$DW$T$459


$C$DW$T$525	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$525, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$T$525, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$525, DW_AT_byte_size(0x03)
$C$DW$682	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$682, DW_AT_upper_bound(0x02)
	.dwendtag $C$DW$T$525

$C$DW$T$536	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$536, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$T$536, DW_AT_address_class(0x20)

$C$DW$T$703	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$703, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$T$703, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$703, DW_AT_byte_size(0x40)
$C$DW$683	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$683, DW_AT_upper_bound(0x3f)
	.dwendtag $C$DW$T$703


$C$DW$T$705	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$705, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$T$705, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$705, DW_AT_byte_size(0x8c)
$C$DW$684	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$684, DW_AT_upper_bound(0x8b)
	.dwendtag $C$DW$T$705

$C$DW$T$7	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$7, DW_AT_encoding(DW_ATE_signed_char)
	.dwattr $C$DW$T$7, DW_AT_name("wchar_t")
	.dwattr $C$DW$T$7, DW_AT_byte_size(0x02)
$C$DW$T$8	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$8, DW_AT_encoding(DW_ATE_signed)
	.dwattr $C$DW$T$8, DW_AT_name("short")
	.dwattr $C$DW$T$8, DW_AT_byte_size(0x02)
$C$DW$T$22	.dwtag  DW_TAG_typedef, DW_AT_name("int16")
	.dwattr $C$DW$T$22, DW_AT_type(*$C$DW$T$8)
	.dwattr $C$DW$T$22, DW_AT_language(DW_LANG_C_plus_plus)

$C$DW$T$26	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$26, DW_AT_type(*$C$DW$T$22)
	.dwattr $C$DW$T$26, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$T$9	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$9, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr $C$DW$T$9, DW_AT_name("unsigned short")
	.dwattr $C$DW$T$9, DW_AT_byte_size(0x02)
$C$DW$T$28	.dwtag  DW_TAG_typedef, DW_AT_name("uint16")
	.dwattr $C$DW$T$28, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$T$28, DW_AT_language(DW_LANG_C_plus_plus)

$C$DW$T$32	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$32, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$T$32, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$T$352	.dwtag  DW_TAG_typedef, DW_AT_name("sa_family_t")
	.dwattr $C$DW$T$352, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$T$352, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$T$10	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$10, DW_AT_encoding(DW_ATE_signed)
	.dwattr $C$DW$T$10, DW_AT_name("int")
	.dwattr $C$DW$T$10, DW_AT_byte_size(0x04)
$C$DW$T$41	.dwtag  DW_TAG_typedef, DW_AT_name("int32")
	.dwattr $C$DW$T$41, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$T$41, DW_AT_language(DW_LANG_C_plus_plus)

$C$DW$T$45	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$45, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$T$45, DW_AT_language(DW_LANG_C_plus_plus)

$C$DW$T$87	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$87, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$T$87, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$685	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$685, DW_AT_type(*$C$DW$T$86)
$C$DW$686	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$686, DW_AT_type(*$C$DW$T$28)
	.dwendtag $C$DW$T$87

$C$DW$T$88	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$88, DW_AT_type(*$C$DW$T$87)
	.dwattr $C$DW$T$88, DW_AT_address_class(0x20)

$C$DW$T$89	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$89, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$T$89, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$687	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$687, DW_AT_type(*$C$DW$T$86)
	.dwendtag $C$DW$T$89

$C$DW$T$90	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$90, DW_AT_type(*$C$DW$T$89)
	.dwattr $C$DW$T$90, DW_AT_address_class(0x20)

$C$DW$T$91	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$91, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$T$91, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$688	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$688, DW_AT_type(*$C$DW$T$86)
$C$DW$689	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$689, DW_AT_type(*$C$DW$T$3)
$C$DW$690	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$690, DW_AT_type(*$C$DW$T$41)
	.dwendtag $C$DW$T$91

$C$DW$T$92	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$92, DW_AT_type(*$C$DW$T$91)
	.dwattr $C$DW$T$92, DW_AT_address_class(0x20)

$C$DW$T$95	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$95, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$T$95, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$691	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$691, DW_AT_type(*$C$DW$T$86)
$C$DW$692	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$692, DW_AT_type(*$C$DW$T$94)
$C$DW$693	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$693, DW_AT_type(*$C$DW$T$41)
	.dwendtag $C$DW$T$95

$C$DW$T$96	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$96, DW_AT_type(*$C$DW$T$95)
	.dwattr $C$DW$T$96, DW_AT_address_class(0x20)

$C$DW$T$97	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$97, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$T$97, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$694	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$694, DW_AT_type(*$C$DW$T$86)
$C$DW$695	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$695, DW_AT_type(*$C$DW$T$41)
$C$DW$696	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$696, DW_AT_type(*$C$DW$T$94)
	.dwendtag $C$DW$T$97

$C$DW$T$98	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$98, DW_AT_type(*$C$DW$T$97)
	.dwattr $C$DW$T$98, DW_AT_address_class(0x20)
$C$DW$T$707	.dwtag  DW_TAG_typedef, DW_AT_name("ptrdiff_t")
	.dwattr $C$DW$T$707, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$T$707, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$T$722	.dwtag  DW_TAG_typedef, DW_AT_name("nothrow_t")
	.dwattr $C$DW$T$722, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$T$722, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$T$11	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$11, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr $C$DW$T$11, DW_AT_name("unsigned int")
	.dwattr $C$DW$T$11, DW_AT_byte_size(0x04)
$C$DW$T$47	.dwtag  DW_TAG_typedef, DW_AT_name("uint32")
	.dwattr $C$DW$T$47, DW_AT_type(*$C$DW$T$11)
	.dwattr $C$DW$T$47, DW_AT_language(DW_LANG_C_plus_plus)

$C$DW$T$51	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$51, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$T$51, DW_AT_language(DW_LANG_C_plus_plus)

$C$DW$T$232	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$232, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$T$232, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$232, DW_AT_byte_size(0x0c)
$C$DW$697	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$697, DW_AT_upper_bound(0x02)
	.dwendtag $C$DW$T$232


$C$DW$T$233	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$233, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$T$233, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$233, DW_AT_byte_size(0x40)
$C$DW$698	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$698, DW_AT_upper_bound(0x0f)
	.dwendtag $C$DW$T$233


$C$DW$T$438	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$438, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$T$438, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$438, DW_AT_byte_size(0x20)
$C$DW$699	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$699, DW_AT_upper_bound(0x07)
	.dwendtag $C$DW$T$438

$C$DW$T$727	.dwtag  DW_TAG_typedef, DW_AT_name("EDMA_Handle")
	.dwattr $C$DW$T$727, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$T$727, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$T$732	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$732, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$T$732, DW_AT_address_class(0x20)

$C$DW$T$740	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$740, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$T$740, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$740, DW_AT_byte_size(0xe00)
$C$DW$700	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$700, DW_AT_upper_bound(0x37f)
	.dwendtag $C$DW$T$740


$C$DW$T$742	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$742, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$T$742, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$742, DW_AT_byte_size(0x300)
$C$DW$701	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$701, DW_AT_upper_bound(0xbf)
	.dwendtag $C$DW$T$742


$C$DW$T$744	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$744, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$T$744, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$744, DW_AT_byte_size(0x600)
$C$DW$702	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$702, DW_AT_upper_bound(0x17f)
	.dwendtag $C$DW$T$744

$C$DW$T$682	.dwtag  DW_TAG_typedef, DW_AT_name("size_t")
	.dwattr $C$DW$T$682, DW_AT_type(*$C$DW$T$11)
	.dwattr $C$DW$T$682, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$T$751	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$751, DW_AT_type(*$C$DW$T$11)
	.dwattr $C$DW$T$751, DW_AT_address_class(0x20)
$C$DW$T$12	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$12, DW_AT_encoding(DW_ATE_signed)
	.dwattr $C$DW$T$12, DW_AT_name("long")
	.dwattr $C$DW$T$12, DW_AT_byte_size(0x08)
	.dwattr $C$DW$T$12, DW_AT_bit_size(0x28)
	.dwattr $C$DW$T$12, DW_AT_bit_offset(0x18)
$C$DW$T$13	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$13, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr $C$DW$T$13, DW_AT_name("unsigned long")
	.dwattr $C$DW$T$13, DW_AT_byte_size(0x08)
	.dwattr $C$DW$T$13, DW_AT_bit_size(0x28)
	.dwattr $C$DW$T$13, DW_AT_bit_offset(0x18)
$C$DW$T$14	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$14, DW_AT_encoding(DW_ATE_signed)
	.dwattr $C$DW$T$14, DW_AT_name("long long")
	.dwattr $C$DW$T$14, DW_AT_byte_size(0x08)
$C$DW$T$60	.dwtag  DW_TAG_typedef, DW_AT_name("int64")
	.dwattr $C$DW$T$60, DW_AT_type(*$C$DW$T$14)
	.dwattr $C$DW$T$60, DW_AT_language(DW_LANG_C_plus_plus)

$C$DW$T$64	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$64, DW_AT_type(*$C$DW$T$60)
	.dwattr $C$DW$T$64, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$T$15	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$15, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr $C$DW$T$15, DW_AT_name("unsigned long long")
	.dwattr $C$DW$T$15, DW_AT_byte_size(0x08)
$C$DW$T$66	.dwtag  DW_TAG_typedef, DW_AT_name("uint64")
	.dwattr $C$DW$T$66, DW_AT_type(*$C$DW$T$15)
	.dwattr $C$DW$T$66, DW_AT_language(DW_LANG_C_plus_plus)

$C$DW$T$70	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$70, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$T$70, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$T$16	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$16, DW_AT_encoding(DW_ATE_float)
	.dwattr $C$DW$T$16, DW_AT_name("float")
	.dwattr $C$DW$T$16, DW_AT_byte_size(0x04)
$C$DW$T$755	.dwtag  DW_TAG_typedef, DW_AT_name("float32")
	.dwattr $C$DW$T$755, DW_AT_type(*$C$DW$T$16)
	.dwattr $C$DW$T$755, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$T$17	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$17, DW_AT_encoding(DW_ATE_float)
	.dwattr $C$DW$T$17, DW_AT_name("double")
	.dwattr $C$DW$T$17, DW_AT_byte_size(0x08)
$C$DW$T$18	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$18, DW_AT_encoding(DW_ATE_float)
	.dwattr $C$DW$T$18, DW_AT_name("long double")
	.dwattr $C$DW$T$18, DW_AT_byte_size(0x08)
$C$DW$T$756	.dwtag  DW_TAG_typedef, DW_AT_name("float64")
	.dwattr $C$DW$T$756, DW_AT_type(*$C$DW$T$18)
	.dwattr $C$DW$T$756, DW_AT_language(DW_LANG_C_plus_plus)

$C$DW$T$27	.dwtag  DW_TAG_class_type
	.dwattr $C$DW$T$27, DW_AT_name("int16le")
	.dwattr $C$DW$T$27, DW_AT_byte_size(0x02)
$C$DW$703	.dwtag  DW_TAG_member
	.dwattr $C$DW$703, DW_AT_type(*$C$DW$T$20)
	.dwattr $C$DW$703, DW_AT_name("a")
	.dwattr $C$DW$703, DW_AT_TI_symbol_name("_a")
	.dwattr $C$DW$703, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$703, DW_AT_accessibility(DW_ACCESS_private)

$C$DW$5	.dwtag  DW_TAG_subprogram, DW_AT_name("int16le")
	.dwattr $C$DW$5, DW_AT_declaration
	.dwattr $C$DW$5, DW_AT_TI_symbol_name("___ct__7int16leFv")
	.dwattr $C$DW$5, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$6	.dwtag  DW_TAG_subprogram, DW_AT_name("int16le")
	.dwattr $C$DW$6, DW_AT_declaration
	.dwattr $C$DW$6, DW_AT_TI_symbol_name("___ct__7int16leFs")
	.dwattr $C$DW$6, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$704	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$704, DW_AT_type(*$C$DW$T$22)
	.dwendtag $C$DW$6


$C$DW$7	.dwtag  DW_TAG_subprogram, DW_AT_name("int16le")
	.dwattr $C$DW$7, DW_AT_declaration
	.dwattr $C$DW$7, DW_AT_TI_symbol_name("___ct__7int16leFR7int16le")
	.dwattr $C$DW$7, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$705	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$705, DW_AT_type(*$C$DW$T$24)
	.dwendtag $C$DW$7


$C$DW$8	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$8, DW_AT_declaration
	.dwattr $C$DW$8, DW_AT_TI_symbol_name("___as__7int16leFs")
	.dwattr $C$DW$8, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$706	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$706, DW_AT_type(*$C$DW$T$22)
	.dwendtag $C$DW$8


$C$DW$9	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$9, DW_AT_declaration
	.dwattr $C$DW$9, DW_AT_TI_symbol_name("___as__7int16leFR7int16le")
	.dwattr $C$DW$9, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$707	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$707, DW_AT_type(*$C$DW$T$24)
	.dwendtag $C$DW$9


$C$DW$10	.dwtag  DW_TAG_subprogram, DW_AT_name("operator short")
	.dwattr $C$DW$10, DW_AT_declaration
	.dwattr $C$DW$10, DW_AT_TI_symbol_name("___ops__7int16leFv")
	.dwattr $C$DW$10, DW_AT_type(*$C$DW$T$22)
	.dwattr $C$DW$10, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag $C$DW$T$27

$C$DW$T$24	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$24, DW_AT_type(*$C$DW$T$27)
	.dwattr $C$DW$T$24, DW_AT_address_class(0x20)

$C$DW$T$33	.dwtag  DW_TAG_class_type
	.dwattr $C$DW$T$33, DW_AT_name("uint16le")
	.dwattr $C$DW$T$33, DW_AT_byte_size(0x02)
$C$DW$708	.dwtag  DW_TAG_member
	.dwattr $C$DW$708, DW_AT_type(*$C$DW$T$20)
	.dwattr $C$DW$708, DW_AT_name("a")
	.dwattr $C$DW$708, DW_AT_TI_symbol_name("_a")
	.dwattr $C$DW$708, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$708, DW_AT_accessibility(DW_ACCESS_private)

$C$DW$11	.dwtag  DW_TAG_subprogram, DW_AT_name("uint16le")
	.dwattr $C$DW$11, DW_AT_declaration
	.dwattr $C$DW$11, DW_AT_TI_symbol_name("___ct__8uint16leFv")
	.dwattr $C$DW$11, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$12	.dwtag  DW_TAG_subprogram, DW_AT_name("uint16le")
	.dwattr $C$DW$12, DW_AT_declaration
	.dwattr $C$DW$12, DW_AT_TI_symbol_name("___ct__8uint16leFUs")
	.dwattr $C$DW$12, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$709	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$709, DW_AT_type(*$C$DW$T$28)
	.dwendtag $C$DW$12


$C$DW$13	.dwtag  DW_TAG_subprogram, DW_AT_name("uint16le")
	.dwattr $C$DW$13, DW_AT_declaration
	.dwattr $C$DW$13, DW_AT_TI_symbol_name("___ct__8uint16leFR8uint16le")
	.dwattr $C$DW$13, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$710	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$710, DW_AT_type(*$C$DW$T$30)
	.dwendtag $C$DW$13


$C$DW$14	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$14, DW_AT_declaration
	.dwattr $C$DW$14, DW_AT_TI_symbol_name("___as__8uint16leFUs")
	.dwattr $C$DW$14, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$711	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$711, DW_AT_type(*$C$DW$T$28)
	.dwendtag $C$DW$14


$C$DW$15	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$15, DW_AT_declaration
	.dwattr $C$DW$15, DW_AT_TI_symbol_name("___as__8uint16leFR8uint16le")
	.dwattr $C$DW$15, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$712	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$712, DW_AT_type(*$C$DW$T$30)
	.dwendtag $C$DW$15


$C$DW$16	.dwtag  DW_TAG_subprogram, DW_AT_name("operator unsigned short")
	.dwattr $C$DW$16, DW_AT_declaration
	.dwattr $C$DW$16, DW_AT_TI_symbol_name("___opUs__8uint16leFv")
	.dwattr $C$DW$16, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$16, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag $C$DW$T$33

$C$DW$T$30	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$30, DW_AT_type(*$C$DW$T$33)
	.dwattr $C$DW$T$30, DW_AT_address_class(0x20)

$C$DW$T$36	.dwtag  DW_TAG_class_type
	.dwattr $C$DW$T$36, DW_AT_name("int16be")
	.dwattr $C$DW$T$36, DW_AT_byte_size(0x02)
$C$DW$713	.dwtag  DW_TAG_member
	.dwattr $C$DW$713, DW_AT_type(*$C$DW$T$20)
	.dwattr $C$DW$713, DW_AT_name("a")
	.dwattr $C$DW$713, DW_AT_TI_symbol_name("_a")
	.dwattr $C$DW$713, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$713, DW_AT_accessibility(DW_ACCESS_private)

$C$DW$17	.dwtag  DW_TAG_subprogram, DW_AT_name("int16be")
	.dwattr $C$DW$17, DW_AT_declaration
	.dwattr $C$DW$17, DW_AT_TI_symbol_name("___ct__7int16beFv")
	.dwattr $C$DW$17, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$18	.dwtag  DW_TAG_subprogram, DW_AT_name("int16be")
	.dwattr $C$DW$18, DW_AT_declaration
	.dwattr $C$DW$18, DW_AT_TI_symbol_name("___ct__7int16beFs")
	.dwattr $C$DW$18, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$714	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$714, DW_AT_type(*$C$DW$T$22)
	.dwendtag $C$DW$18


$C$DW$19	.dwtag  DW_TAG_subprogram, DW_AT_name("int16be")
	.dwattr $C$DW$19, DW_AT_declaration
	.dwattr $C$DW$19, DW_AT_TI_symbol_name("___ct__7int16beFR7int16be")
	.dwattr $C$DW$19, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$715	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$715, DW_AT_type(*$C$DW$T$34)
	.dwendtag $C$DW$19


$C$DW$20	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$20, DW_AT_declaration
	.dwattr $C$DW$20, DW_AT_TI_symbol_name("___as__7int16beFs")
	.dwattr $C$DW$20, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$716	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$716, DW_AT_type(*$C$DW$T$22)
	.dwendtag $C$DW$20


$C$DW$21	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$21, DW_AT_declaration
	.dwattr $C$DW$21, DW_AT_TI_symbol_name("___as__7int16beFR7int16be")
	.dwattr $C$DW$21, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$717	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$717, DW_AT_type(*$C$DW$T$34)
	.dwendtag $C$DW$21


$C$DW$22	.dwtag  DW_TAG_subprogram, DW_AT_name("operator short")
	.dwattr $C$DW$22, DW_AT_declaration
	.dwattr $C$DW$22, DW_AT_TI_symbol_name("___ops__7int16beFv")
	.dwattr $C$DW$22, DW_AT_type(*$C$DW$T$22)
	.dwattr $C$DW$22, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag $C$DW$T$36

$C$DW$T$34	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$34, DW_AT_type(*$C$DW$T$36)
	.dwattr $C$DW$T$34, DW_AT_address_class(0x20)

$C$DW$T$39	.dwtag  DW_TAG_class_type
	.dwattr $C$DW$T$39, DW_AT_name("uint16be")
	.dwattr $C$DW$T$39, DW_AT_byte_size(0x02)
$C$DW$718	.dwtag  DW_TAG_member
	.dwattr $C$DW$718, DW_AT_type(*$C$DW$T$20)
	.dwattr $C$DW$718, DW_AT_name("a")
	.dwattr $C$DW$718, DW_AT_TI_symbol_name("_a")
	.dwattr $C$DW$718, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$718, DW_AT_accessibility(DW_ACCESS_private)

$C$DW$23	.dwtag  DW_TAG_subprogram, DW_AT_name("uint16be")
	.dwattr $C$DW$23, DW_AT_declaration
	.dwattr $C$DW$23, DW_AT_TI_symbol_name("___ct__8uint16beFv")
	.dwattr $C$DW$23, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$24	.dwtag  DW_TAG_subprogram, DW_AT_name("uint16be")
	.dwattr $C$DW$24, DW_AT_declaration
	.dwattr $C$DW$24, DW_AT_TI_symbol_name("___ct__8uint16beFUs")
	.dwattr $C$DW$24, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$719	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$719, DW_AT_type(*$C$DW$T$28)
	.dwendtag $C$DW$24


$C$DW$25	.dwtag  DW_TAG_subprogram, DW_AT_name("uint16be")
	.dwattr $C$DW$25, DW_AT_declaration
	.dwattr $C$DW$25, DW_AT_TI_symbol_name("___ct__8uint16beFR8uint16be")
	.dwattr $C$DW$25, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$720	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$720, DW_AT_type(*$C$DW$T$37)
	.dwendtag $C$DW$25


$C$DW$26	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$26, DW_AT_declaration
	.dwattr $C$DW$26, DW_AT_TI_symbol_name("___as__8uint16beFUs")
	.dwattr $C$DW$26, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$721	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$721, DW_AT_type(*$C$DW$T$28)
	.dwendtag $C$DW$26


$C$DW$27	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$27, DW_AT_declaration
	.dwattr $C$DW$27, DW_AT_TI_symbol_name("___as__8uint16beFR8uint16be")
	.dwattr $C$DW$27, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$722	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$722, DW_AT_type(*$C$DW$T$37)
	.dwendtag $C$DW$27


$C$DW$28	.dwtag  DW_TAG_subprogram, DW_AT_name("operator unsigned short")
	.dwattr $C$DW$28, DW_AT_declaration
	.dwattr $C$DW$28, DW_AT_TI_symbol_name("___opUs__8uint16beFv")
	.dwattr $C$DW$28, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$28, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag $C$DW$T$39

$C$DW$T$37	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$37, DW_AT_type(*$C$DW$T$39)
	.dwattr $C$DW$T$37, DW_AT_address_class(0x20)

$C$DW$T$46	.dwtag  DW_TAG_class_type
	.dwattr $C$DW$T$46, DW_AT_name("int32le")
	.dwattr $C$DW$T$46, DW_AT_byte_size(0x04)
$C$DW$723	.dwtag  DW_TAG_member
	.dwattr $C$DW$723, DW_AT_type(*$C$DW$T$40)
	.dwattr $C$DW$723, DW_AT_name("a")
	.dwattr $C$DW$723, DW_AT_TI_symbol_name("_a")
	.dwattr $C$DW$723, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$723, DW_AT_accessibility(DW_ACCESS_private)

$C$DW$29	.dwtag  DW_TAG_subprogram, DW_AT_name("int32le")
	.dwattr $C$DW$29, DW_AT_declaration
	.dwattr $C$DW$29, DW_AT_TI_symbol_name("___ct__7int32leFv")
	.dwattr $C$DW$29, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$30	.dwtag  DW_TAG_subprogram, DW_AT_name("int32le")
	.dwattr $C$DW$30, DW_AT_declaration
	.dwattr $C$DW$30, DW_AT_TI_symbol_name("___ct__7int32leFi")
	.dwattr $C$DW$30, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$724	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$724, DW_AT_type(*$C$DW$T$41)
	.dwendtag $C$DW$30


$C$DW$31	.dwtag  DW_TAG_subprogram, DW_AT_name("int32le")
	.dwattr $C$DW$31, DW_AT_declaration
	.dwattr $C$DW$31, DW_AT_TI_symbol_name("___ct__7int32leFR7int32le")
	.dwattr $C$DW$31, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$725	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$725, DW_AT_type(*$C$DW$T$43)
	.dwendtag $C$DW$31


$C$DW$32	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$32, DW_AT_declaration
	.dwattr $C$DW$32, DW_AT_TI_symbol_name("___as__7int32leFi")
	.dwattr $C$DW$32, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$726	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$726, DW_AT_type(*$C$DW$T$41)
	.dwendtag $C$DW$32


$C$DW$33	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$33, DW_AT_declaration
	.dwattr $C$DW$33, DW_AT_TI_symbol_name("___as__7int32leFR7int32le")
	.dwattr $C$DW$33, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$727	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$727, DW_AT_type(*$C$DW$T$43)
	.dwendtag $C$DW$33


$C$DW$34	.dwtag  DW_TAG_subprogram, DW_AT_name("operator int")
	.dwattr $C$DW$34, DW_AT_declaration
	.dwattr $C$DW$34, DW_AT_TI_symbol_name("___opi__7int32leFv")
	.dwattr $C$DW$34, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$34, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag $C$DW$T$46

$C$DW$T$43	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$43, DW_AT_type(*$C$DW$T$46)
	.dwattr $C$DW$T$43, DW_AT_address_class(0x20)

$C$DW$T$52	.dwtag  DW_TAG_class_type
	.dwattr $C$DW$T$52, DW_AT_name("uint32le")
	.dwattr $C$DW$T$52, DW_AT_byte_size(0x04)
$C$DW$728	.dwtag  DW_TAG_member
	.dwattr $C$DW$728, DW_AT_type(*$C$DW$T$40)
	.dwattr $C$DW$728, DW_AT_name("a")
	.dwattr $C$DW$728, DW_AT_TI_symbol_name("_a")
	.dwattr $C$DW$728, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$728, DW_AT_accessibility(DW_ACCESS_private)

$C$DW$35	.dwtag  DW_TAG_subprogram, DW_AT_name("uint32le")
	.dwattr $C$DW$35, DW_AT_declaration
	.dwattr $C$DW$35, DW_AT_TI_symbol_name("___ct__8uint32leFv")
	.dwattr $C$DW$35, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$36	.dwtag  DW_TAG_subprogram, DW_AT_name("uint32le")
	.dwattr $C$DW$36, DW_AT_declaration
	.dwattr $C$DW$36, DW_AT_TI_symbol_name("___ct__8uint32leFUi")
	.dwattr $C$DW$36, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$729	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$729, DW_AT_type(*$C$DW$T$47)
	.dwendtag $C$DW$36


$C$DW$37	.dwtag  DW_TAG_subprogram, DW_AT_name("uint32le")
	.dwattr $C$DW$37, DW_AT_declaration
	.dwattr $C$DW$37, DW_AT_TI_symbol_name("___ct__8uint32leFR8uint32le")
	.dwattr $C$DW$37, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$730	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$730, DW_AT_type(*$C$DW$T$49)
	.dwendtag $C$DW$37


$C$DW$38	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$38, DW_AT_declaration
	.dwattr $C$DW$38, DW_AT_TI_symbol_name("___as__8uint32leFUi")
	.dwattr $C$DW$38, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$731	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$731, DW_AT_type(*$C$DW$T$47)
	.dwendtag $C$DW$38


$C$DW$39	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$39, DW_AT_declaration
	.dwattr $C$DW$39, DW_AT_TI_symbol_name("___as__8uint32leFR8uint32le")
	.dwattr $C$DW$39, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$732	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$732, DW_AT_type(*$C$DW$T$49)
	.dwendtag $C$DW$39


$C$DW$40	.dwtag  DW_TAG_subprogram, DW_AT_name("operator unsigned int")
	.dwattr $C$DW$40, DW_AT_declaration
	.dwattr $C$DW$40, DW_AT_TI_symbol_name("___opUi__8uint32leFv")
	.dwattr $C$DW$40, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$40, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag $C$DW$T$52

$C$DW$T$49	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$49, DW_AT_type(*$C$DW$T$52)
	.dwattr $C$DW$T$49, DW_AT_address_class(0x20)

$C$DW$T$55	.dwtag  DW_TAG_class_type
	.dwattr $C$DW$T$55, DW_AT_name("int32be")
	.dwattr $C$DW$T$55, DW_AT_byte_size(0x04)
$C$DW$733	.dwtag  DW_TAG_member
	.dwattr $C$DW$733, DW_AT_type(*$C$DW$T$40)
	.dwattr $C$DW$733, DW_AT_name("a")
	.dwattr $C$DW$733, DW_AT_TI_symbol_name("_a")
	.dwattr $C$DW$733, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$733, DW_AT_accessibility(DW_ACCESS_private)

$C$DW$41	.dwtag  DW_TAG_subprogram, DW_AT_name("int32be")
	.dwattr $C$DW$41, DW_AT_declaration
	.dwattr $C$DW$41, DW_AT_TI_symbol_name("___ct__7int32beFv")
	.dwattr $C$DW$41, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$42	.dwtag  DW_TAG_subprogram, DW_AT_name("int32be")
	.dwattr $C$DW$42, DW_AT_declaration
	.dwattr $C$DW$42, DW_AT_TI_symbol_name("___ct__7int32beFi")
	.dwattr $C$DW$42, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$734	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$734, DW_AT_type(*$C$DW$T$41)
	.dwendtag $C$DW$42


$C$DW$43	.dwtag  DW_TAG_subprogram, DW_AT_name("int32be")
	.dwattr $C$DW$43, DW_AT_declaration
	.dwattr $C$DW$43, DW_AT_TI_symbol_name("___ct__7int32beFR7int32be")
	.dwattr $C$DW$43, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$735	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$735, DW_AT_type(*$C$DW$T$53)
	.dwendtag $C$DW$43


$C$DW$44	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$44, DW_AT_declaration
	.dwattr $C$DW$44, DW_AT_TI_symbol_name("___as__7int32beFi")
	.dwattr $C$DW$44, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$736	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$736, DW_AT_type(*$C$DW$T$41)
	.dwendtag $C$DW$44


$C$DW$45	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$45, DW_AT_declaration
	.dwattr $C$DW$45, DW_AT_TI_symbol_name("___as__7int32beFR7int32be")
	.dwattr $C$DW$45, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$737	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$737, DW_AT_type(*$C$DW$T$53)
	.dwendtag $C$DW$45


$C$DW$46	.dwtag  DW_TAG_subprogram, DW_AT_name("operator int")
	.dwattr $C$DW$46, DW_AT_declaration
	.dwattr $C$DW$46, DW_AT_TI_symbol_name("___opi__7int32beFv")
	.dwattr $C$DW$46, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$46, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag $C$DW$T$55

$C$DW$T$53	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$53, DW_AT_type(*$C$DW$T$55)
	.dwattr $C$DW$T$53, DW_AT_address_class(0x20)

$C$DW$T$58	.dwtag  DW_TAG_class_type
	.dwattr $C$DW$T$58, DW_AT_name("uint32be")
	.dwattr $C$DW$T$58, DW_AT_byte_size(0x04)
$C$DW$738	.dwtag  DW_TAG_member
	.dwattr $C$DW$738, DW_AT_type(*$C$DW$T$40)
	.dwattr $C$DW$738, DW_AT_name("a")
	.dwattr $C$DW$738, DW_AT_TI_symbol_name("_a")
	.dwattr $C$DW$738, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$738, DW_AT_accessibility(DW_ACCESS_private)

$C$DW$47	.dwtag  DW_TAG_subprogram, DW_AT_name("uint32be")
	.dwattr $C$DW$47, DW_AT_declaration
	.dwattr $C$DW$47, DW_AT_TI_symbol_name("___ct__8uint32beFv")
	.dwattr $C$DW$47, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$48	.dwtag  DW_TAG_subprogram, DW_AT_name("uint32be")
	.dwattr $C$DW$48, DW_AT_declaration
	.dwattr $C$DW$48, DW_AT_TI_symbol_name("___ct__8uint32beFUi")
	.dwattr $C$DW$48, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$739	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$739, DW_AT_type(*$C$DW$T$47)
	.dwendtag $C$DW$48


$C$DW$49	.dwtag  DW_TAG_subprogram, DW_AT_name("uint32be")
	.dwattr $C$DW$49, DW_AT_declaration
	.dwattr $C$DW$49, DW_AT_TI_symbol_name("___ct__8uint32beFR8uint32be")
	.dwattr $C$DW$49, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$740	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$740, DW_AT_type(*$C$DW$T$56)
	.dwendtag $C$DW$49


$C$DW$50	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$50, DW_AT_declaration
	.dwattr $C$DW$50, DW_AT_TI_symbol_name("___as__8uint32beFUi")
	.dwattr $C$DW$50, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$741	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$741, DW_AT_type(*$C$DW$T$47)
	.dwendtag $C$DW$50


$C$DW$51	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$51, DW_AT_declaration
	.dwattr $C$DW$51, DW_AT_TI_symbol_name("___as__8uint32beFR8uint32be")
	.dwattr $C$DW$51, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$742	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$742, DW_AT_type(*$C$DW$T$56)
	.dwendtag $C$DW$51


$C$DW$52	.dwtag  DW_TAG_subprogram, DW_AT_name("operator unsigned int")
	.dwattr $C$DW$52, DW_AT_declaration
	.dwattr $C$DW$52, DW_AT_TI_symbol_name("___opUi__8uint32beFv")
	.dwattr $C$DW$52, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$52, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag $C$DW$T$58

$C$DW$T$56	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$56, DW_AT_type(*$C$DW$T$58)
	.dwattr $C$DW$T$56, DW_AT_address_class(0x20)

$C$DW$T$65	.dwtag  DW_TAG_class_type
	.dwattr $C$DW$T$65, DW_AT_name("int64le")
	.dwattr $C$DW$T$65, DW_AT_byte_size(0x08)
$C$DW$743	.dwtag  DW_TAG_member
	.dwattr $C$DW$743, DW_AT_type(*$C$DW$T$59)
	.dwattr $C$DW$743, DW_AT_name("a")
	.dwattr $C$DW$743, DW_AT_TI_symbol_name("_a")
	.dwattr $C$DW$743, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$743, DW_AT_accessibility(DW_ACCESS_private)

$C$DW$53	.dwtag  DW_TAG_subprogram, DW_AT_name("int64le")
	.dwattr $C$DW$53, DW_AT_declaration
	.dwattr $C$DW$53, DW_AT_TI_symbol_name("___ct__7int64leFv")
	.dwattr $C$DW$53, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$54	.dwtag  DW_TAG_subprogram, DW_AT_name("int64le")
	.dwattr $C$DW$54, DW_AT_declaration
	.dwattr $C$DW$54, DW_AT_TI_symbol_name("___ct__7int64leFL")
	.dwattr $C$DW$54, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$744	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$744, DW_AT_type(*$C$DW$T$60)
	.dwendtag $C$DW$54


$C$DW$55	.dwtag  DW_TAG_subprogram, DW_AT_name("int64le")
	.dwattr $C$DW$55, DW_AT_declaration
	.dwattr $C$DW$55, DW_AT_TI_symbol_name("___ct__7int64leFR7int64le")
	.dwattr $C$DW$55, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$745	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$745, DW_AT_type(*$C$DW$T$62)
	.dwendtag $C$DW$55


$C$DW$56	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$56, DW_AT_declaration
	.dwattr $C$DW$56, DW_AT_TI_symbol_name("___as__7int64leFL")
	.dwattr $C$DW$56, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$746	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$746, DW_AT_type(*$C$DW$T$60)
	.dwendtag $C$DW$56


$C$DW$57	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$57, DW_AT_declaration
	.dwattr $C$DW$57, DW_AT_TI_symbol_name("___as__7int64leFR7int64le")
	.dwattr $C$DW$57, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$747	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$747, DW_AT_type(*$C$DW$T$62)
	.dwendtag $C$DW$57


$C$DW$58	.dwtag  DW_TAG_subprogram, DW_AT_name("operator long long")
	.dwattr $C$DW$58, DW_AT_declaration
	.dwattr $C$DW$58, DW_AT_TI_symbol_name("___opL__7int64leFv")
	.dwattr $C$DW$58, DW_AT_type(*$C$DW$T$60)
	.dwattr $C$DW$58, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag $C$DW$T$65

$C$DW$T$62	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$62, DW_AT_type(*$C$DW$T$65)
	.dwattr $C$DW$T$62, DW_AT_address_class(0x20)

$C$DW$T$71	.dwtag  DW_TAG_class_type
	.dwattr $C$DW$T$71, DW_AT_name("uint64le")
	.dwattr $C$DW$T$71, DW_AT_byte_size(0x08)
$C$DW$748	.dwtag  DW_TAG_member
	.dwattr $C$DW$748, DW_AT_type(*$C$DW$T$59)
	.dwattr $C$DW$748, DW_AT_name("a")
	.dwattr $C$DW$748, DW_AT_TI_symbol_name("_a")
	.dwattr $C$DW$748, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$748, DW_AT_accessibility(DW_ACCESS_private)

$C$DW$59	.dwtag  DW_TAG_subprogram, DW_AT_name("uint64le")
	.dwattr $C$DW$59, DW_AT_declaration
	.dwattr $C$DW$59, DW_AT_TI_symbol_name("___ct__8uint64leFv")
	.dwattr $C$DW$59, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$60	.dwtag  DW_TAG_subprogram, DW_AT_name("uint64le")
	.dwattr $C$DW$60, DW_AT_declaration
	.dwattr $C$DW$60, DW_AT_TI_symbol_name("___ct__8uint64leFUL")
	.dwattr $C$DW$60, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$749	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$749, DW_AT_type(*$C$DW$T$66)
	.dwendtag $C$DW$60


$C$DW$61	.dwtag  DW_TAG_subprogram, DW_AT_name("uint64le")
	.dwattr $C$DW$61, DW_AT_declaration
	.dwattr $C$DW$61, DW_AT_TI_symbol_name("___ct__8uint64leFR8uint64le")
	.dwattr $C$DW$61, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$750	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$750, DW_AT_type(*$C$DW$T$68)
	.dwendtag $C$DW$61


$C$DW$62	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$62, DW_AT_declaration
	.dwattr $C$DW$62, DW_AT_TI_symbol_name("___as__8uint64leFUL")
	.dwattr $C$DW$62, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$751	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$751, DW_AT_type(*$C$DW$T$66)
	.dwendtag $C$DW$62


$C$DW$63	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$63, DW_AT_declaration
	.dwattr $C$DW$63, DW_AT_TI_symbol_name("___as__8uint64leFR8uint64le")
	.dwattr $C$DW$63, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$752	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$752, DW_AT_type(*$C$DW$T$68)
	.dwendtag $C$DW$63


$C$DW$64	.dwtag  DW_TAG_subprogram, DW_AT_name("operator unsigned long long")
	.dwattr $C$DW$64, DW_AT_declaration
	.dwattr $C$DW$64, DW_AT_TI_symbol_name("___opUL__8uint64leFv")
	.dwattr $C$DW$64, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$64, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag $C$DW$T$71

$C$DW$T$68	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$68, DW_AT_type(*$C$DW$T$71)
	.dwattr $C$DW$T$68, DW_AT_address_class(0x20)

$C$DW$T$74	.dwtag  DW_TAG_class_type
	.dwattr $C$DW$T$74, DW_AT_name("int64be")
	.dwattr $C$DW$T$74, DW_AT_byte_size(0x08)
$C$DW$753	.dwtag  DW_TAG_member
	.dwattr $C$DW$753, DW_AT_type(*$C$DW$T$59)
	.dwattr $C$DW$753, DW_AT_name("a")
	.dwattr $C$DW$753, DW_AT_TI_symbol_name("_a")
	.dwattr $C$DW$753, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$753, DW_AT_accessibility(DW_ACCESS_private)

$C$DW$65	.dwtag  DW_TAG_subprogram, DW_AT_name("int64be")
	.dwattr $C$DW$65, DW_AT_declaration
	.dwattr $C$DW$65, DW_AT_TI_symbol_name("___ct__7int64beFv")
	.dwattr $C$DW$65, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$66	.dwtag  DW_TAG_subprogram, DW_AT_name("int64be")
	.dwattr $C$DW$66, DW_AT_declaration
	.dwattr $C$DW$66, DW_AT_TI_symbol_name("___ct__7int64beFL")
	.dwattr $C$DW$66, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$754	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$754, DW_AT_type(*$C$DW$T$60)
	.dwendtag $C$DW$66


$C$DW$67	.dwtag  DW_TAG_subprogram, DW_AT_name("int64be")
	.dwattr $C$DW$67, DW_AT_declaration
	.dwattr $C$DW$67, DW_AT_TI_symbol_name("___ct__7int64beFR7int64be")
	.dwattr $C$DW$67, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$755	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$755, DW_AT_type(*$C$DW$T$72)
	.dwendtag $C$DW$67


$C$DW$68	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$68, DW_AT_declaration
	.dwattr $C$DW$68, DW_AT_TI_symbol_name("___as__7int64beFL")
	.dwattr $C$DW$68, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$756	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$756, DW_AT_type(*$C$DW$T$60)
	.dwendtag $C$DW$68


$C$DW$69	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$69, DW_AT_declaration
	.dwattr $C$DW$69, DW_AT_TI_symbol_name("___as__7int64beFR7int64be")
	.dwattr $C$DW$69, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$757	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$757, DW_AT_type(*$C$DW$T$72)
	.dwendtag $C$DW$69


$C$DW$70	.dwtag  DW_TAG_subprogram, DW_AT_name("operator long long")
	.dwattr $C$DW$70, DW_AT_declaration
	.dwattr $C$DW$70, DW_AT_TI_symbol_name("___opL__7int64beFv")
	.dwattr $C$DW$70, DW_AT_type(*$C$DW$T$60)
	.dwattr $C$DW$70, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag $C$DW$T$74

$C$DW$T$72	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$72, DW_AT_type(*$C$DW$T$74)
	.dwattr $C$DW$T$72, DW_AT_address_class(0x20)

$C$DW$T$77	.dwtag  DW_TAG_class_type
	.dwattr $C$DW$T$77, DW_AT_name("uint64be")
	.dwattr $C$DW$T$77, DW_AT_byte_size(0x08)
$C$DW$758	.dwtag  DW_TAG_member
	.dwattr $C$DW$758, DW_AT_type(*$C$DW$T$59)
	.dwattr $C$DW$758, DW_AT_name("a")
	.dwattr $C$DW$758, DW_AT_TI_symbol_name("_a")
	.dwattr $C$DW$758, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$758, DW_AT_accessibility(DW_ACCESS_private)

$C$DW$71	.dwtag  DW_TAG_subprogram, DW_AT_name("uint64be")
	.dwattr $C$DW$71, DW_AT_declaration
	.dwattr $C$DW$71, DW_AT_TI_symbol_name("___ct__8uint64beFv")
	.dwattr $C$DW$71, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$72	.dwtag  DW_TAG_subprogram, DW_AT_name("uint64be")
	.dwattr $C$DW$72, DW_AT_declaration
	.dwattr $C$DW$72, DW_AT_TI_symbol_name("___ct__8uint64beFUL")
	.dwattr $C$DW$72, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$759	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$759, DW_AT_type(*$C$DW$T$66)
	.dwendtag $C$DW$72


$C$DW$73	.dwtag  DW_TAG_subprogram, DW_AT_name("uint64be")
	.dwattr $C$DW$73, DW_AT_declaration
	.dwattr $C$DW$73, DW_AT_TI_symbol_name("___ct__8uint64beFR8uint64be")
	.dwattr $C$DW$73, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$760	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$760, DW_AT_type(*$C$DW$T$75)
	.dwendtag $C$DW$73


$C$DW$74	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$74, DW_AT_declaration
	.dwattr $C$DW$74, DW_AT_TI_symbol_name("___as__8uint64beFUL")
	.dwattr $C$DW$74, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$761	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$761, DW_AT_type(*$C$DW$T$66)
	.dwendtag $C$DW$74


$C$DW$75	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$75, DW_AT_declaration
	.dwattr $C$DW$75, DW_AT_TI_symbol_name("___as__8uint64beFR8uint64be")
	.dwattr $C$DW$75, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$762	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$762, DW_AT_type(*$C$DW$T$75)
	.dwendtag $C$DW$75


$C$DW$76	.dwtag  DW_TAG_subprogram, DW_AT_name("operator unsigned long long")
	.dwattr $C$DW$76, DW_AT_declaration
	.dwattr $C$DW$76, DW_AT_TI_symbol_name("___opUL__8uint64beFv")
	.dwattr $C$DW$76, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$76, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag $C$DW$T$77

$C$DW$T$75	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$75, DW_AT_type(*$C$DW$T$77)
	.dwattr $C$DW$T$75, DW_AT_address_class(0x20)
$C$DW$T$79	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$79, DW_AT_encoding(DW_ATE_signed_char)
	.dwattr $C$DW$T$79, DW_AT_name("signed char")
	.dwattr $C$DW$T$79, DW_AT_byte_size(0x01)
$C$DW$T$80	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$80, DW_AT_type(*$C$DW$T$79)
	.dwattr $C$DW$T$80, DW_AT_address_class(0x20)
$C$DW$T$757	.dwtag  DW_TAG_typedef, DW_AT_name("va_list")
	.dwattr $C$DW$T$757, DW_AT_type(*$C$DW$T$80)
	.dwattr $C$DW$T$757, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$T$110	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$110, DW_AT_type(*$C$DW$T$79)
$C$DW$T$111	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$111, DW_AT_type(*$C$DW$T$110)
	.dwattr $C$DW$T$111, DW_AT_address_class(0x20)

$C$DW$T$123	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$123, DW_AT_type(*$C$DW$T$79)
	.dwattr $C$DW$T$123, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$123, DW_AT_byte_size(0x18)
$C$DW$763	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$763, DW_AT_upper_bound(0x17)
	.dwendtag $C$DW$T$123


$C$DW$T$308	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$308, DW_AT_type(*$C$DW$T$79)
	.dwattr $C$DW$T$308, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$308, DW_AT_byte_size(0x100)
$C$DW$764	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$764, DW_AT_upper_bound(0xff)
	.dwendtag $C$DW$T$308


$C$DW$T$353	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$353, DW_AT_type(*$C$DW$T$79)
	.dwattr $C$DW$T$353, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$353, DW_AT_byte_size(0x0e)
$C$DW$765	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$765, DW_AT_upper_bound(0x0d)
	.dwendtag $C$DW$T$353


$C$DW$T$404	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$404, DW_AT_type(*$C$DW$T$79)
	.dwattr $C$DW$T$404, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$404, DW_AT_byte_size(0x0a)
$C$DW$766	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$766, DW_AT_upper_bound(0x09)
	.dwendtag $C$DW$T$404


$C$DW$T$405	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$405, DW_AT_type(*$C$DW$T$79)
	.dwattr $C$DW$T$405, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$405, DW_AT_byte_size(0x11)
$C$DW$767	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$767, DW_AT_upper_bound(0x10)
	.dwendtag $C$DW$T$405


$C$DW$T$406	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$406, DW_AT_type(*$C$DW$T$79)
	.dwattr $C$DW$T$406, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$406, DW_AT_byte_size(0x05)
$C$DW$768	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$768, DW_AT_upper_bound(0x04)
	.dwendtag $C$DW$T$406


$C$DW$T$407	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$407, DW_AT_type(*$C$DW$T$79)
	.dwattr $C$DW$T$407, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$407, DW_AT_byte_size(0x08)
$C$DW$769	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$769, DW_AT_upper_bound(0x07)
	.dwendtag $C$DW$T$407


$C$DW$T$758	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$758, DW_AT_type(*$C$DW$T$79)
	.dwattr $C$DW$T$758, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$758, DW_AT_byte_size(0x5dc)
$C$DW$770	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$770, DW_AT_upper_bound(0x5db)
	.dwendtag $C$DW$T$758


$C$DW$T$85	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$85, DW_AT_name("s_os_driver_descriptor")
	.dwattr $C$DW$T$85, DW_AT_byte_size(0x18)
$C$DW$771	.dwtag  DW_TAG_member
	.dwattr $C$DW$771, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$771, DW_AT_name("id")
	.dwattr $C$DW$771, DW_AT_TI_symbol_name("_id")
	.dwattr $C$DW$771, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$771, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$772	.dwtag  DW_TAG_member
	.dwattr $C$DW$772, DW_AT_type(*$C$DW$T$78)
	.dwattr $C$DW$772, DW_AT_name("ctx")
	.dwattr $C$DW$772, DW_AT_TI_symbol_name("_ctx")
	.dwattr $C$DW$772, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$772, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$773	.dwtag  DW_TAG_member
	.dwattr $C$DW$773, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$773, DW_AT_name("own_process")
	.dwattr $C$DW$773, DW_AT_TI_symbol_name("_own_process")
	.dwattr $C$DW$773, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$773, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$774	.dwtag  DW_TAG_member
	.dwattr $C$DW$774, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$774, DW_AT_name("access")
	.dwattr $C$DW$774, DW_AT_TI_symbol_name("_access")
	.dwattr $C$DW$774, DW_AT_data_member_location[DW_OP_plus_uconst 0xa]
	.dwattr $C$DW$774, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$775	.dwtag  DW_TAG_member
	.dwattr $C$DW$775, DW_AT_type(*$C$DW$T$80)
	.dwattr $C$DW$775, DW_AT_name("path")
	.dwattr $C$DW$775, DW_AT_TI_symbol_name("_path")
	.dwattr $C$DW$775, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$775, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$776	.dwtag  DW_TAG_member
	.dwattr $C$DW$776, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$776, DW_AT_name("data")
	.dwattr $C$DW$776, DW_AT_TI_symbol_name("_data")
	.dwattr $C$DW$776, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$776, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$777	.dwtag  DW_TAG_member
	.dwattr $C$DW$777, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$777, DW_AT_name("sem")
	.dwattr $C$DW$777, DW_AT_TI_symbol_name("_sem")
	.dwattr $C$DW$777, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$777, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$77	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$77, DW_AT_declaration
	.dwattr $C$DW$77, DW_AT_TI_symbol_name("___as__22s_os_driver_descriptorFRC22s_os_driver_descriptor")
	.dwattr $C$DW$77, DW_AT_type(*$C$DW$T$81)
	.dwattr $C$DW$77, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$778	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$778, DW_AT_type(*$C$DW$T$83)
	.dwendtag $C$DW$77

	.dwendtag $C$DW$T$85

$C$DW$T$81	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$81, DW_AT_type(*$C$DW$T$85)
	.dwattr $C$DW$T$81, DW_AT_address_class(0x20)

$C$DW$T$84	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$84, DW_AT_type(*$C$DW$T$81)
	.dwattr $C$DW$T$84, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$779	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$779, DW_AT_type(*$C$DW$T$83)
	.dwendtag $C$DW$T$84

$C$DW$T$82	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$82, DW_AT_type(*$C$DW$T$85)
$C$DW$T$83	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$83, DW_AT_type(*$C$DW$T$82)
	.dwattr $C$DW$T$83, DW_AT_address_class(0x20)
$C$DW$T$86	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$86, DW_AT_type(*$C$DW$T$85)
	.dwattr $C$DW$T$86, DW_AT_address_class(0x20)

$C$DW$T$103	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$103, DW_AT_name("s_os_driver_context")
	.dwattr $C$DW$T$103, DW_AT_byte_size(0x30)
$C$DW$780	.dwtag  DW_TAG_member
	.dwattr $C$DW$780, DW_AT_type(*$C$DW$T$78)
	.dwattr $C$DW$780, DW_AT_name("prev")
	.dwattr $C$DW$780, DW_AT_TI_symbol_name("_prev")
	.dwattr $C$DW$780, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$780, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$781	.dwtag  DW_TAG_member
	.dwattr $C$DW$781, DW_AT_type(*$C$DW$T$78)
	.dwattr $C$DW$781, DW_AT_name("next")
	.dwattr $C$DW$781, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$781, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$781, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$782	.dwtag  DW_TAG_member
	.dwattr $C$DW$782, DW_AT_type(*$C$DW$T$88)
	.dwattr $C$DW$782, DW_AT_name("open")
	.dwattr $C$DW$782, DW_AT_TI_symbol_name("_open")
	.dwattr $C$DW$782, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$782, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$783	.dwtag  DW_TAG_member
	.dwattr $C$DW$783, DW_AT_type(*$C$DW$T$90)
	.dwattr $C$DW$783, DW_AT_name("close")
	.dwattr $C$DW$783, DW_AT_TI_symbol_name("_close")
	.dwattr $C$DW$783, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$783, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$784	.dwtag  DW_TAG_member
	.dwattr $C$DW$784, DW_AT_type(*$C$DW$T$92)
	.dwattr $C$DW$784, DW_AT_name("read")
	.dwattr $C$DW$784, DW_AT_TI_symbol_name("_read")
	.dwattr $C$DW$784, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$784, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$785	.dwtag  DW_TAG_member
	.dwattr $C$DW$785, DW_AT_type(*$C$DW$T$96)
	.dwattr $C$DW$785, DW_AT_name("write")
	.dwattr $C$DW$785, DW_AT_TI_symbol_name("_write")
	.dwattr $C$DW$785, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$785, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$786	.dwtag  DW_TAG_member
	.dwattr $C$DW$786, DW_AT_type(*$C$DW$T$98)
	.dwattr $C$DW$786, DW_AT_name("ioctl")
	.dwattr $C$DW$786, DW_AT_TI_symbol_name("_ioctl")
	.dwattr $C$DW$786, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$786, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$787	.dwtag  DW_TAG_member
	.dwattr $C$DW$787, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$787, DW_AT_name("own_process")
	.dwattr $C$DW$787, DW_AT_TI_symbol_name("_own_process")
	.dwattr $C$DW$787, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr $C$DW$787, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$788	.dwtag  DW_TAG_member
	.dwattr $C$DW$788, DW_AT_type(*$C$DW$T$80)
	.dwattr $C$DW$788, DW_AT_name("name")
	.dwattr $C$DW$788, DW_AT_TI_symbol_name("_name")
	.dwattr $C$DW$788, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr $C$DW$788, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$789	.dwtag  DW_TAG_member
	.dwattr $C$DW$789, DW_AT_type(*$C$DW$T$80)
	.dwattr $C$DW$789, DW_AT_name("path")
	.dwattr $C$DW$789, DW_AT_TI_symbol_name("_path")
	.dwattr $C$DW$789, DW_AT_data_member_location[DW_OP_plus_uconst 0x24]
	.dwattr $C$DW$789, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$790	.dwtag  DW_TAG_member
	.dwattr $C$DW$790, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$790, DW_AT_name("data")
	.dwattr $C$DW$790, DW_AT_TI_symbol_name("_data")
	.dwattr $C$DW$790, DW_AT_data_member_location[DW_OP_plus_uconst 0x28]
	.dwattr $C$DW$790, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$791	.dwtag  DW_TAG_member
	.dwattr $C$DW$791, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$791, DW_AT_name("flags")
	.dwattr $C$DW$791, DW_AT_TI_symbol_name("_flags")
	.dwattr $C$DW$791, DW_AT_data_member_location[DW_OP_plus_uconst 0x2c]
	.dwattr $C$DW$791, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$78	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$78, DW_AT_declaration
	.dwattr $C$DW$78, DW_AT_TI_symbol_name("___as__19s_os_driver_contextFRC19s_os_driver_context")
	.dwattr $C$DW$78, DW_AT_type(*$C$DW$T$99)
	.dwattr $C$DW$78, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$792	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$792, DW_AT_type(*$C$DW$T$101)
	.dwendtag $C$DW$78

	.dwendtag $C$DW$T$103

$C$DW$T$78	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$78, DW_AT_type(*$C$DW$T$103)
	.dwattr $C$DW$T$78, DW_AT_address_class(0x20)
$C$DW$T$99	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$99, DW_AT_type(*$C$DW$T$103)
	.dwattr $C$DW$T$99, DW_AT_address_class(0x20)

$C$DW$T$102	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$102, DW_AT_type(*$C$DW$T$99)
	.dwattr $C$DW$T$102, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$793	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$793, DW_AT_type(*$C$DW$T$101)
	.dwendtag $C$DW$T$102

$C$DW$T$100	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$100, DW_AT_type(*$C$DW$T$103)
$C$DW$T$101	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$101, DW_AT_type(*$C$DW$T$100)
	.dwattr $C$DW$T$101, DW_AT_address_class(0x20)

$C$DW$T$109	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$109, DW_AT_name("s_inode")
	.dwattr $C$DW$T$109, DW_AT_byte_size(0x28)
$C$DW$794	.dwtag  DW_TAG_member
	.dwattr $C$DW$794, DW_AT_type(*$C$DW$T$104)
	.dwattr $C$DW$794, DW_AT_name("prev")
	.dwattr $C$DW$794, DW_AT_TI_symbol_name("_prev")
	.dwattr $C$DW$794, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$794, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$795	.dwtag  DW_TAG_member
	.dwattr $C$DW$795, DW_AT_type(*$C$DW$T$104)
	.dwattr $C$DW$795, DW_AT_name("next")
	.dwattr $C$DW$795, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$795, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$795, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$796	.dwtag  DW_TAG_member
	.dwattr $C$DW$796, DW_AT_type(*$C$DW$T$80)
	.dwattr $C$DW$796, DW_AT_name("name")
	.dwattr $C$DW$796, DW_AT_TI_symbol_name("_name")
	.dwattr $C$DW$796, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$796, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$797	.dwtag  DW_TAG_member
	.dwattr $C$DW$797, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$797, DW_AT_name("size")
	.dwattr $C$DW$797, DW_AT_TI_symbol_name("_size")
	.dwattr $C$DW$797, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$797, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$798	.dwtag  DW_TAG_member
	.dwattr $C$DW$798, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$798, DW_AT_name("mktime")
	.dwattr $C$DW$798, DW_AT_TI_symbol_name("_mktime")
	.dwattr $C$DW$798, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$798, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$799	.dwtag  DW_TAG_member
	.dwattr $C$DW$799, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$799, DW_AT_name("own_user")
	.dwattr $C$DW$799, DW_AT_TI_symbol_name("_own_user")
	.dwattr $C$DW$799, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr $C$DW$799, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$800	.dwtag  DW_TAG_member
	.dwattr $C$DW$800, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$800, DW_AT_name("own_group")
	.dwattr $C$DW$800, DW_AT_TI_symbol_name("_own_group")
	.dwattr $C$DW$800, DW_AT_data_member_location[DW_OP_plus_uconst 0x1e]
	.dwattr $C$DW$800, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$801	.dwtag  DW_TAG_member
	.dwattr $C$DW$801, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$801, DW_AT_name("access")
	.dwattr $C$DW$801, DW_AT_TI_symbol_name("_access")
	.dwattr $C$DW$801, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr $C$DW$801, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$802	.dwtag  DW_TAG_member
	.dwattr $C$DW$802, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$802, DW_AT_name("type")
	.dwattr $C$DW$802, DW_AT_TI_symbol_name("_type")
	.dwattr $C$DW$802, DW_AT_data_member_location[DW_OP_plus_uconst 0x24]
	.dwattr $C$DW$802, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$79	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$79, DW_AT_declaration
	.dwattr $C$DW$79, DW_AT_TI_symbol_name("___as__7s_inodeFRC7s_inode")
	.dwattr $C$DW$79, DW_AT_type(*$C$DW$T$105)
	.dwattr $C$DW$79, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$803	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$803, DW_AT_type(*$C$DW$T$107)
	.dwendtag $C$DW$79

	.dwendtag $C$DW$T$109

$C$DW$T$104	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$104, DW_AT_type(*$C$DW$T$109)
	.dwattr $C$DW$T$104, DW_AT_address_class(0x20)
$C$DW$T$105	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$105, DW_AT_type(*$C$DW$T$109)
	.dwattr $C$DW$T$105, DW_AT_address_class(0x20)

$C$DW$T$108	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$108, DW_AT_type(*$C$DW$T$105)
	.dwattr $C$DW$T$108, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$804	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$804, DW_AT_type(*$C$DW$T$107)
	.dwendtag $C$DW$T$108

$C$DW$T$106	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$106, DW_AT_type(*$C$DW$T$109)
$C$DW$T$107	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$107, DW_AT_type(*$C$DW$T$106)
	.dwattr $C$DW$T$107, DW_AT_address_class(0x20)

$C$DW$T$116	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$116, DW_AT_name("s_inode_create")
	.dwattr $C$DW$T$116, DW_AT_byte_size(0x08)
$C$DW$805	.dwtag  DW_TAG_member
	.dwattr $C$DW$805, DW_AT_type(*$C$DW$T$111)
	.dwattr $C$DW$805, DW_AT_name("name")
	.dwattr $C$DW$805, DW_AT_TI_symbol_name("_name")
	.dwattr $C$DW$805, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$805, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$806	.dwtag  DW_TAG_member
	.dwattr $C$DW$806, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$806, DW_AT_name("type")
	.dwattr $C$DW$806, DW_AT_TI_symbol_name("_type")
	.dwattr $C$DW$806, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$806, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$80	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$80, DW_AT_declaration
	.dwattr $C$DW$80, DW_AT_TI_symbol_name("___as__14s_inode_createFRC14s_inode_create")
	.dwattr $C$DW$80, DW_AT_type(*$C$DW$T$112)
	.dwattr $C$DW$80, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$807	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$807, DW_AT_type(*$C$DW$T$114)
	.dwendtag $C$DW$80

	.dwendtag $C$DW$T$116

$C$DW$T$112	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$112, DW_AT_type(*$C$DW$T$116)
	.dwattr $C$DW$T$112, DW_AT_address_class(0x20)

$C$DW$T$115	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$115, DW_AT_type(*$C$DW$T$112)
	.dwattr $C$DW$T$115, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$808	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$808, DW_AT_type(*$C$DW$T$114)
	.dwendtag $C$DW$T$115

$C$DW$T$113	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$113, DW_AT_type(*$C$DW$T$116)
$C$DW$T$114	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$114, DW_AT_type(*$C$DW$T$113)
	.dwattr $C$DW$T$114, DW_AT_address_class(0x20)

$C$DW$T$121	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$121, DW_AT_name("s_ipmp_stat")
	.dwattr $C$DW$T$121, DW_AT_byte_size(0x38)
$C$DW$809	.dwtag  DW_TAG_member
	.dwattr $C$DW$809, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$809, DW_AT_name("rx_count")
	.dwattr $C$DW$809, DW_AT_TI_symbol_name("_rx_count")
	.dwattr $C$DW$809, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$809, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$810	.dwtag  DW_TAG_member
	.dwattr $C$DW$810, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$810, DW_AT_name("rx_bytes")
	.dwattr $C$DW$810, DW_AT_TI_symbol_name("_rx_bytes")
	.dwattr $C$DW$810, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$810, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$811	.dwtag  DW_TAG_member
	.dwattr $C$DW$811, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$811, DW_AT_name("rx_drop")
	.dwattr $C$DW$811, DW_AT_TI_symbol_name("_rx_drop")
	.dwattr $C$DW$811, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$811, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$812	.dwtag  DW_TAG_member
	.dwattr $C$DW$812, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$812, DW_AT_name("rx_drop_mem")
	.dwattr $C$DW$812, DW_AT_TI_symbol_name("_rx_drop_mem")
	.dwattr $C$DW$812, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$812, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$813	.dwtag  DW_TAG_member
	.dwattr $C$DW$813, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$813, DW_AT_name("rx_drop_hash")
	.dwattr $C$DW$813, DW_AT_TI_symbol_name("_rx_drop_hash")
	.dwattr $C$DW$813, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr $C$DW$813, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$814	.dwtag  DW_TAG_member
	.dwattr $C$DW$814, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$814, DW_AT_name("tx_count")
	.dwattr $C$DW$814, DW_AT_TI_symbol_name("_tx_count")
	.dwattr $C$DW$814, DW_AT_data_member_location[DW_OP_plus_uconst 0x28]
	.dwattr $C$DW$814, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$815	.dwtag  DW_TAG_member
	.dwattr $C$DW$815, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$815, DW_AT_name("tx_bytes")
	.dwattr $C$DW$815, DW_AT_TI_symbol_name("_tx_bytes")
	.dwattr $C$DW$815, DW_AT_data_member_location[DW_OP_plus_uconst 0x30]
	.dwattr $C$DW$815, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$81	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$81, DW_AT_declaration
	.dwattr $C$DW$81, DW_AT_TI_symbol_name("___as__11s_ipmp_statFRC11s_ipmp_stat")
	.dwattr $C$DW$81, DW_AT_type(*$C$DW$T$117)
	.dwattr $C$DW$81, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$816	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$816, DW_AT_type(*$C$DW$T$119)
	.dwendtag $C$DW$81

	.dwendtag $C$DW$T$121

$C$DW$T$117	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$117, DW_AT_type(*$C$DW$T$121)
	.dwattr $C$DW$T$117, DW_AT_address_class(0x20)

$C$DW$T$120	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$120, DW_AT_type(*$C$DW$T$117)
	.dwattr $C$DW$T$120, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$817	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$817, DW_AT_type(*$C$DW$T$119)
	.dwendtag $C$DW$T$120

$C$DW$T$118	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$118, DW_AT_type(*$C$DW$T$121)
$C$DW$T$119	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$119, DW_AT_type(*$C$DW$T$118)
	.dwattr $C$DW$T$119, DW_AT_address_class(0x20)

$C$DW$T$128	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$128, DW_AT_name("s_message_link")
	.dwattr $C$DW$T$128, DW_AT_byte_size(0x24)
$C$DW$818	.dwtag  DW_TAG_member
	.dwattr $C$DW$818, DW_AT_type(*$C$DW$T$122)
	.dwattr $C$DW$818, DW_AT_name("next")
	.dwattr $C$DW$818, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$818, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$818, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$819	.dwtag  DW_TAG_member
	.dwattr $C$DW$819, DW_AT_type(*$C$DW$T$122)
	.dwattr $C$DW$819, DW_AT_name("prev")
	.dwattr $C$DW$819, DW_AT_TI_symbol_name("_prev")
	.dwattr $C$DW$819, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$819, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$820	.dwtag  DW_TAG_member
	.dwattr $C$DW$820, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$820, DW_AT_name("id")
	.dwattr $C$DW$820, DW_AT_TI_symbol_name("_id")
	.dwattr $C$DW$820, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$820, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$821	.dwtag  DW_TAG_member
	.dwattr $C$DW$821, DW_AT_type(*$C$DW$T$123)
	.dwattr $C$DW$821, DW_AT_name("name")
	.dwattr $C$DW$821, DW_AT_TI_symbol_name("_name")
	.dwattr $C$DW$821, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$821, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$82	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$82, DW_AT_declaration
	.dwattr $C$DW$82, DW_AT_TI_symbol_name("___as__14s_message_linkFRC14s_message_link")
	.dwattr $C$DW$82, DW_AT_type(*$C$DW$T$124)
	.dwattr $C$DW$82, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$822	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$822, DW_AT_type(*$C$DW$T$126)
	.dwendtag $C$DW$82

	.dwendtag $C$DW$T$128

$C$DW$T$122	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$122, DW_AT_type(*$C$DW$T$128)
	.dwattr $C$DW$T$122, DW_AT_address_class(0x20)
$C$DW$T$124	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$124, DW_AT_type(*$C$DW$T$128)
	.dwattr $C$DW$T$124, DW_AT_address_class(0x20)

$C$DW$T$127	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$127, DW_AT_type(*$C$DW$T$124)
	.dwattr $C$DW$T$127, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$823	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$823, DW_AT_type(*$C$DW$T$126)
	.dwendtag $C$DW$T$127

$C$DW$T$125	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$125, DW_AT_type(*$C$DW$T$128)
$C$DW$T$126	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$126, DW_AT_type(*$C$DW$T$125)
	.dwattr $C$DW$T$126, DW_AT_address_class(0x20)

$C$DW$T$134	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$134, DW_AT_name("s_message_queue")
	.dwattr $C$DW$T$134, DW_AT_byte_size(0x10)
$C$DW$824	.dwtag  DW_TAG_member
	.dwattr $C$DW$824, DW_AT_type(*$C$DW$T$129)
	.dwattr $C$DW$824, DW_AT_name("first")
	.dwattr $C$DW$824, DW_AT_TI_symbol_name("_first")
	.dwattr $C$DW$824, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$824, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$825	.dwtag  DW_TAG_member
	.dwattr $C$DW$825, DW_AT_type(*$C$DW$T$129)
	.dwattr $C$DW$825, DW_AT_name("last")
	.dwattr $C$DW$825, DW_AT_TI_symbol_name("_last")
	.dwattr $C$DW$825, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$825, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$826	.dwtag  DW_TAG_member
	.dwattr $C$DW$826, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$826, DW_AT_name("syn_sem")
	.dwattr $C$DW$826, DW_AT_TI_symbol_name("_syn_sem")
	.dwattr $C$DW$826, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$826, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$827	.dwtag  DW_TAG_member
	.dwattr $C$DW$827, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$827, DW_AT_name("count_sem")
	.dwattr $C$DW$827, DW_AT_TI_symbol_name("_count_sem")
	.dwattr $C$DW$827, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$827, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$83	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$83, DW_AT_declaration
	.dwattr $C$DW$83, DW_AT_TI_symbol_name("___as__15s_message_queueFRC15s_message_queue")
	.dwattr $C$DW$83, DW_AT_type(*$C$DW$T$130)
	.dwattr $C$DW$83, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$828	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$828, DW_AT_type(*$C$DW$T$132)
	.dwendtag $C$DW$83

	.dwendtag $C$DW$T$134

$C$DW$T$130	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$130, DW_AT_type(*$C$DW$T$134)
	.dwattr $C$DW$T$130, DW_AT_address_class(0x20)

$C$DW$T$133	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$133, DW_AT_type(*$C$DW$T$130)
	.dwattr $C$DW$T$133, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$829	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$829, DW_AT_type(*$C$DW$T$132)
	.dwendtag $C$DW$T$133

$C$DW$T$131	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$131, DW_AT_type(*$C$DW$T$134)
$C$DW$T$132	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$132, DW_AT_type(*$C$DW$T$131)
	.dwattr $C$DW$T$132, DW_AT_address_class(0x20)
$C$DW$T$136	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$136, DW_AT_type(*$C$DW$T$134)
	.dwattr $C$DW$T$136, DW_AT_address_class(0x20)

$C$DW$T$141	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$141, DW_AT_name("s_message_pipe")
	.dwattr $C$DW$T$141, DW_AT_byte_size(0x18)
$C$DW$830	.dwtag  DW_TAG_member
	.dwattr $C$DW$830, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$830, DW_AT_name("next")
	.dwattr $C$DW$830, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$830, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$830, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$831	.dwtag  DW_TAG_member
	.dwattr $C$DW$831, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$831, DW_AT_name("prev")
	.dwattr $C$DW$831, DW_AT_TI_symbol_name("_prev")
	.dwattr $C$DW$831, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$831, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$832	.dwtag  DW_TAG_member
	.dwattr $C$DW$832, DW_AT_type(*$C$DW$T$122)
	.dwattr $C$DW$832, DW_AT_name("route")
	.dwattr $C$DW$832, DW_AT_TI_symbol_name("_route")
	.dwattr $C$DW$832, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$832, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$833	.dwtag  DW_TAG_member
	.dwattr $C$DW$833, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$833, DW_AT_name("route_count")
	.dwattr $C$DW$833, DW_AT_TI_symbol_name("_route_count")
	.dwattr $C$DW$833, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$833, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$834	.dwtag  DW_TAG_member
	.dwattr $C$DW$834, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$834, DW_AT_name("limit_sem")
	.dwattr $C$DW$834, DW_AT_TI_symbol_name("_limit_sem")
	.dwattr $C$DW$834, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$834, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$835	.dwtag  DW_TAG_member
	.dwattr $C$DW$835, DW_AT_type(*$C$DW$T$136)
	.dwattr $C$DW$835, DW_AT_name("outq")
	.dwattr $C$DW$835, DW_AT_TI_symbol_name("_outq")
	.dwattr $C$DW$835, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$835, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$84	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$84, DW_AT_declaration
	.dwattr $C$DW$84, DW_AT_TI_symbol_name("___as__14s_message_pipeFRC14s_message_pipe")
	.dwattr $C$DW$84, DW_AT_type(*$C$DW$T$137)
	.dwattr $C$DW$84, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$836	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$836, DW_AT_type(*$C$DW$T$139)
	.dwendtag $C$DW$84

	.dwendtag $C$DW$T$141

$C$DW$T$135	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$135, DW_AT_type(*$C$DW$T$141)
	.dwattr $C$DW$T$135, DW_AT_address_class(0x20)
$C$DW$T$137	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$137, DW_AT_type(*$C$DW$T$141)
	.dwattr $C$DW$T$137, DW_AT_address_class(0x20)

$C$DW$T$140	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$140, DW_AT_type(*$C$DW$T$137)
	.dwattr $C$DW$T$140, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$837	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$837, DW_AT_type(*$C$DW$T$139)
	.dwendtag $C$DW$T$140

$C$DW$T$138	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$138, DW_AT_type(*$C$DW$T$141)
$C$DW$T$139	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$139, DW_AT_type(*$C$DW$T$138)
	.dwattr $C$DW$T$139, DW_AT_address_class(0x20)

$C$DW$T$146	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$146, DW_AT_name("s_message")
	.dwattr $C$DW$T$146, DW_AT_byte_size(0x1c)
$C$DW$838	.dwtag  DW_TAG_member
	.dwattr $C$DW$838, DW_AT_type(*$C$DW$T$129)
	.dwattr $C$DW$838, DW_AT_name("prev")
	.dwattr $C$DW$838, DW_AT_TI_symbol_name("_prev")
	.dwattr $C$DW$838, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$838, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$839	.dwtag  DW_TAG_member
	.dwattr $C$DW$839, DW_AT_type(*$C$DW$T$129)
	.dwattr $C$DW$839, DW_AT_name("next")
	.dwattr $C$DW$839, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$839, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$839, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$840	.dwtag  DW_TAG_member
	.dwattr $C$DW$840, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$840, DW_AT_name("pipe")
	.dwattr $C$DW$840, DW_AT_TI_symbol_name("_pipe")
	.dwattr $C$DW$840, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$840, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$841	.dwtag  DW_TAG_member
	.dwattr $C$DW$841, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$841, DW_AT_name("from")
	.dwattr $C$DW$841, DW_AT_TI_symbol_name("_from")
	.dwattr $C$DW$841, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$841, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$842	.dwtag  DW_TAG_member
	.dwattr $C$DW$842, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$842, DW_AT_name("to")
	.dwattr $C$DW$842, DW_AT_TI_symbol_name("_to")
	.dwattr $C$DW$842, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$842, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$843	.dwtag  DW_TAG_member
	.dwattr $C$DW$843, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$843, DW_AT_name("length")
	.dwattr $C$DW$843, DW_AT_TI_symbol_name("_length")
	.dwattr $C$DW$843, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$843, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$844	.dwtag  DW_TAG_member
	.dwattr $C$DW$844, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$844, DW_AT_name("data")
	.dwattr $C$DW$844, DW_AT_TI_symbol_name("_data")
	.dwattr $C$DW$844, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$844, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$85	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$85, DW_AT_declaration
	.dwattr $C$DW$85, DW_AT_TI_symbol_name("___as__9s_messageFRC9s_message")
	.dwattr $C$DW$85, DW_AT_type(*$C$DW$T$142)
	.dwattr $C$DW$85, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$845	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$845, DW_AT_type(*$C$DW$T$144)
	.dwendtag $C$DW$85

	.dwendtag $C$DW$T$146

$C$DW$T$129	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$129, DW_AT_type(*$C$DW$T$146)
	.dwattr $C$DW$T$129, DW_AT_address_class(0x20)
$C$DW$T$142	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$142, DW_AT_type(*$C$DW$T$146)
	.dwattr $C$DW$T$142, DW_AT_address_class(0x20)

$C$DW$T$145	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$145, DW_AT_type(*$C$DW$T$142)
	.dwattr $C$DW$T$145, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$846	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$846, DW_AT_type(*$C$DW$T$144)
	.dwendtag $C$DW$T$145

$C$DW$T$143	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$143, DW_AT_type(*$C$DW$T$146)
$C$DW$T$144	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$144, DW_AT_type(*$C$DW$T$143)
	.dwattr $C$DW$T$144, DW_AT_address_class(0x20)

$C$DW$T$151	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$151, DW_AT_name("s_message_context")
	.dwattr $C$DW$T$151, DW_AT_byte_size(0x0c)
$C$DW$847	.dwtag  DW_TAG_member
	.dwattr $C$DW$847, DW_AT_type(*$C$DW$T$136)
	.dwattr $C$DW$847, DW_AT_name("inq")
	.dwattr $C$DW$847, DW_AT_TI_symbol_name("_inq")
	.dwattr $C$DW$847, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$847, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$848	.dwtag  DW_TAG_member
	.dwattr $C$DW$848, DW_AT_type(*$C$DW$T$136)
	.dwattr $C$DW$848, DW_AT_name("outq")
	.dwattr $C$DW$848, DW_AT_TI_symbol_name("_outq")
	.dwattr $C$DW$848, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$848, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$849	.dwtag  DW_TAG_member
	.dwattr $C$DW$849, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$849, DW_AT_name("pipe")
	.dwattr $C$DW$849, DW_AT_TI_symbol_name("_pipe")
	.dwattr $C$DW$849, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$849, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$86	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$86, DW_AT_declaration
	.dwattr $C$DW$86, DW_AT_TI_symbol_name("___as__17s_message_contextFRC17s_message_context")
	.dwattr $C$DW$86, DW_AT_type(*$C$DW$T$147)
	.dwattr $C$DW$86, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$850	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$850, DW_AT_type(*$C$DW$T$149)
	.dwendtag $C$DW$86

	.dwendtag $C$DW$T$151

$C$DW$T$147	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$147, DW_AT_type(*$C$DW$T$151)
	.dwattr $C$DW$T$147, DW_AT_address_class(0x20)

$C$DW$T$150	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$150, DW_AT_type(*$C$DW$T$147)
	.dwattr $C$DW$T$150, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$851	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$851, DW_AT_type(*$C$DW$T$149)
	.dwendtag $C$DW$T$150

$C$DW$T$148	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$148, DW_AT_type(*$C$DW$T$151)
$C$DW$T$149	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$149, DW_AT_type(*$C$DW$T$148)
	.dwattr $C$DW$T$149, DW_AT_address_class(0x20)

$C$DW$T$156	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$156, DW_AT_name("s_os_register")
	.dwattr $C$DW$T$156, DW_AT_byte_size(0x104)
$C$DW$852	.dwtag  DW_TAG_member
	.dwattr $C$DW$852, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$852, DW_AT_name("a0")
	.dwattr $C$DW$852, DW_AT_TI_symbol_name("_a0")
	.dwattr $C$DW$852, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$852, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$853	.dwtag  DW_TAG_member
	.dwattr $C$DW$853, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$853, DW_AT_name("a1")
	.dwattr $C$DW$853, DW_AT_TI_symbol_name("_a1")
	.dwattr $C$DW$853, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$853, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$854	.dwtag  DW_TAG_member
	.dwattr $C$DW$854, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$854, DW_AT_name("b0")
	.dwattr $C$DW$854, DW_AT_TI_symbol_name("_b0")
	.dwattr $C$DW$854, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$854, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$855	.dwtag  DW_TAG_member
	.dwattr $C$DW$855, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$855, DW_AT_name("b1")
	.dwattr $C$DW$855, DW_AT_TI_symbol_name("_b1")
	.dwattr $C$DW$855, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$855, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$856	.dwtag  DW_TAG_member
	.dwattr $C$DW$856, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$856, DW_AT_name("a2")
	.dwattr $C$DW$856, DW_AT_TI_symbol_name("_a2")
	.dwattr $C$DW$856, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$856, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$857	.dwtag  DW_TAG_member
	.dwattr $C$DW$857, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$857, DW_AT_name("a3")
	.dwattr $C$DW$857, DW_AT_TI_symbol_name("_a3")
	.dwattr $C$DW$857, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$857, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$858	.dwtag  DW_TAG_member
	.dwattr $C$DW$858, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$858, DW_AT_name("b2")
	.dwattr $C$DW$858, DW_AT_TI_symbol_name("_b2")
	.dwattr $C$DW$858, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$858, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$859	.dwtag  DW_TAG_member
	.dwattr $C$DW$859, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$859, DW_AT_name("b3")
	.dwattr $C$DW$859, DW_AT_TI_symbol_name("_b3")
	.dwattr $C$DW$859, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr $C$DW$859, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$860	.dwtag  DW_TAG_member
	.dwattr $C$DW$860, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$860, DW_AT_name("a4")
	.dwattr $C$DW$860, DW_AT_TI_symbol_name("_a4")
	.dwattr $C$DW$860, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr $C$DW$860, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$861	.dwtag  DW_TAG_member
	.dwattr $C$DW$861, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$861, DW_AT_name("a5")
	.dwattr $C$DW$861, DW_AT_TI_symbol_name("_a5")
	.dwattr $C$DW$861, DW_AT_data_member_location[DW_OP_plus_uconst 0x24]
	.dwattr $C$DW$861, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$862	.dwtag  DW_TAG_member
	.dwattr $C$DW$862, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$862, DW_AT_name("b4")
	.dwattr $C$DW$862, DW_AT_TI_symbol_name("_b4")
	.dwattr $C$DW$862, DW_AT_data_member_location[DW_OP_plus_uconst 0x28]
	.dwattr $C$DW$862, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$863	.dwtag  DW_TAG_member
	.dwattr $C$DW$863, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$863, DW_AT_name("b5")
	.dwattr $C$DW$863, DW_AT_TI_symbol_name("_b5")
	.dwattr $C$DW$863, DW_AT_data_member_location[DW_OP_plus_uconst 0x2c]
	.dwattr $C$DW$863, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$864	.dwtag  DW_TAG_member
	.dwattr $C$DW$864, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$864, DW_AT_name("a6")
	.dwattr $C$DW$864, DW_AT_TI_symbol_name("_a6")
	.dwattr $C$DW$864, DW_AT_data_member_location[DW_OP_plus_uconst 0x30]
	.dwattr $C$DW$864, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$865	.dwtag  DW_TAG_member
	.dwattr $C$DW$865, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$865, DW_AT_name("a7")
	.dwattr $C$DW$865, DW_AT_TI_symbol_name("_a7")
	.dwattr $C$DW$865, DW_AT_data_member_location[DW_OP_plus_uconst 0x34]
	.dwattr $C$DW$865, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$866	.dwtag  DW_TAG_member
	.dwattr $C$DW$866, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$866, DW_AT_name("b6")
	.dwattr $C$DW$866, DW_AT_TI_symbol_name("_b6")
	.dwattr $C$DW$866, DW_AT_data_member_location[DW_OP_plus_uconst 0x38]
	.dwattr $C$DW$866, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$867	.dwtag  DW_TAG_member
	.dwattr $C$DW$867, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$867, DW_AT_name("b7")
	.dwattr $C$DW$867, DW_AT_TI_symbol_name("_b7")
	.dwattr $C$DW$867, DW_AT_data_member_location[DW_OP_plus_uconst 0x3c]
	.dwattr $C$DW$867, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$868	.dwtag  DW_TAG_member
	.dwattr $C$DW$868, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$868, DW_AT_name("a8")
	.dwattr $C$DW$868, DW_AT_TI_symbol_name("_a8")
	.dwattr $C$DW$868, DW_AT_data_member_location[DW_OP_plus_uconst 0x40]
	.dwattr $C$DW$868, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$869	.dwtag  DW_TAG_member
	.dwattr $C$DW$869, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$869, DW_AT_name("a9")
	.dwattr $C$DW$869, DW_AT_TI_symbol_name("_a9")
	.dwattr $C$DW$869, DW_AT_data_member_location[DW_OP_plus_uconst 0x44]
	.dwattr $C$DW$869, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$870	.dwtag  DW_TAG_member
	.dwattr $C$DW$870, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$870, DW_AT_name("b8")
	.dwattr $C$DW$870, DW_AT_TI_symbol_name("_b8")
	.dwattr $C$DW$870, DW_AT_data_member_location[DW_OP_plus_uconst 0x48]
	.dwattr $C$DW$870, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$871	.dwtag  DW_TAG_member
	.dwattr $C$DW$871, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$871, DW_AT_name("b9")
	.dwattr $C$DW$871, DW_AT_TI_symbol_name("_b9")
	.dwattr $C$DW$871, DW_AT_data_member_location[DW_OP_plus_uconst 0x4c]
	.dwattr $C$DW$871, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$872	.dwtag  DW_TAG_member
	.dwattr $C$DW$872, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$872, DW_AT_name("a10")
	.dwattr $C$DW$872, DW_AT_TI_symbol_name("_a10")
	.dwattr $C$DW$872, DW_AT_data_member_location[DW_OP_plus_uconst 0x50]
	.dwattr $C$DW$872, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$873	.dwtag  DW_TAG_member
	.dwattr $C$DW$873, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$873, DW_AT_name("a11")
	.dwattr $C$DW$873, DW_AT_TI_symbol_name("_a11")
	.dwattr $C$DW$873, DW_AT_data_member_location[DW_OP_plus_uconst 0x54]
	.dwattr $C$DW$873, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$874	.dwtag  DW_TAG_member
	.dwattr $C$DW$874, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$874, DW_AT_name("b10")
	.dwattr $C$DW$874, DW_AT_TI_symbol_name("_b10")
	.dwattr $C$DW$874, DW_AT_data_member_location[DW_OP_plus_uconst 0x58]
	.dwattr $C$DW$874, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$875	.dwtag  DW_TAG_member
	.dwattr $C$DW$875, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$875, DW_AT_name("b11")
	.dwattr $C$DW$875, DW_AT_TI_symbol_name("_b11")
	.dwattr $C$DW$875, DW_AT_data_member_location[DW_OP_plus_uconst 0x5c]
	.dwattr $C$DW$875, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$876	.dwtag  DW_TAG_member
	.dwattr $C$DW$876, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$876, DW_AT_name("a12")
	.dwattr $C$DW$876, DW_AT_TI_symbol_name("_a12")
	.dwattr $C$DW$876, DW_AT_data_member_location[DW_OP_plus_uconst 0x60]
	.dwattr $C$DW$876, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$877	.dwtag  DW_TAG_member
	.dwattr $C$DW$877, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$877, DW_AT_name("a13")
	.dwattr $C$DW$877, DW_AT_TI_symbol_name("_a13")
	.dwattr $C$DW$877, DW_AT_data_member_location[DW_OP_plus_uconst 0x64]
	.dwattr $C$DW$877, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$878	.dwtag  DW_TAG_member
	.dwattr $C$DW$878, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$878, DW_AT_name("b12")
	.dwattr $C$DW$878, DW_AT_TI_symbol_name("_b12")
	.dwattr $C$DW$878, DW_AT_data_member_location[DW_OP_plus_uconst 0x68]
	.dwattr $C$DW$878, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$879	.dwtag  DW_TAG_member
	.dwattr $C$DW$879, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$879, DW_AT_name("_b13")
	.dwattr $C$DW$879, DW_AT_TI_symbol_name("__b13")
	.dwattr $C$DW$879, DW_AT_data_member_location[DW_OP_plus_uconst 0x6c]
	.dwattr $C$DW$879, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$880	.dwtag  DW_TAG_member
	.dwattr $C$DW$880, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$880, DW_AT_name("a14")
	.dwattr $C$DW$880, DW_AT_TI_symbol_name("_a14")
	.dwattr $C$DW$880, DW_AT_data_member_location[DW_OP_plus_uconst 0x70]
	.dwattr $C$DW$880, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$881	.dwtag  DW_TAG_member
	.dwattr $C$DW$881, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$881, DW_AT_name("a15")
	.dwattr $C$DW$881, DW_AT_TI_symbol_name("_a15")
	.dwattr $C$DW$881, DW_AT_data_member_location[DW_OP_plus_uconst 0x74]
	.dwattr $C$DW$881, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$882	.dwtag  DW_TAG_member
	.dwattr $C$DW$882, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$882, DW_AT_name("b14")
	.dwattr $C$DW$882, DW_AT_TI_symbol_name("_b14")
	.dwattr $C$DW$882, DW_AT_data_member_location[DW_OP_plus_uconst 0x78]
	.dwattr $C$DW$882, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$883	.dwtag  DW_TAG_member
	.dwattr $C$DW$883, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$883, DW_AT_name("b15")
	.dwattr $C$DW$883, DW_AT_TI_symbol_name("_b15")
	.dwattr $C$DW$883, DW_AT_data_member_location[DW_OP_plus_uconst 0x7c]
	.dwattr $C$DW$883, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$884	.dwtag  DW_TAG_member
	.dwattr $C$DW$884, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$884, DW_AT_name("a16")
	.dwattr $C$DW$884, DW_AT_TI_symbol_name("_a16")
	.dwattr $C$DW$884, DW_AT_data_member_location[DW_OP_plus_uconst 0x80]
	.dwattr $C$DW$884, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$885	.dwtag  DW_TAG_member
	.dwattr $C$DW$885, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$885, DW_AT_name("a17")
	.dwattr $C$DW$885, DW_AT_TI_symbol_name("_a17")
	.dwattr $C$DW$885, DW_AT_data_member_location[DW_OP_plus_uconst 0x84]
	.dwattr $C$DW$885, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$886	.dwtag  DW_TAG_member
	.dwattr $C$DW$886, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$886, DW_AT_name("b16")
	.dwattr $C$DW$886, DW_AT_TI_symbol_name("_b16")
	.dwattr $C$DW$886, DW_AT_data_member_location[DW_OP_plus_uconst 0x88]
	.dwattr $C$DW$886, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$887	.dwtag  DW_TAG_member
	.dwattr $C$DW$887, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$887, DW_AT_name("b17")
	.dwattr $C$DW$887, DW_AT_TI_symbol_name("_b17")
	.dwattr $C$DW$887, DW_AT_data_member_location[DW_OP_plus_uconst 0x8c]
	.dwattr $C$DW$887, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$888	.dwtag  DW_TAG_member
	.dwattr $C$DW$888, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$888, DW_AT_name("a18")
	.dwattr $C$DW$888, DW_AT_TI_symbol_name("_a18")
	.dwattr $C$DW$888, DW_AT_data_member_location[DW_OP_plus_uconst 0x90]
	.dwattr $C$DW$888, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$889	.dwtag  DW_TAG_member
	.dwattr $C$DW$889, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$889, DW_AT_name("a19")
	.dwattr $C$DW$889, DW_AT_TI_symbol_name("_a19")
	.dwattr $C$DW$889, DW_AT_data_member_location[DW_OP_plus_uconst 0x94]
	.dwattr $C$DW$889, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$890	.dwtag  DW_TAG_member
	.dwattr $C$DW$890, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$890, DW_AT_name("b18")
	.dwattr $C$DW$890, DW_AT_TI_symbol_name("_b18")
	.dwattr $C$DW$890, DW_AT_data_member_location[DW_OP_plus_uconst 0x98]
	.dwattr $C$DW$890, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$891	.dwtag  DW_TAG_member
	.dwattr $C$DW$891, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$891, DW_AT_name("b19")
	.dwattr $C$DW$891, DW_AT_TI_symbol_name("_b19")
	.dwattr $C$DW$891, DW_AT_data_member_location[DW_OP_plus_uconst 0x9c]
	.dwattr $C$DW$891, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$892	.dwtag  DW_TAG_member
	.dwattr $C$DW$892, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$892, DW_AT_name("a20")
	.dwattr $C$DW$892, DW_AT_TI_symbol_name("_a20")
	.dwattr $C$DW$892, DW_AT_data_member_location[DW_OP_plus_uconst 0xa0]
	.dwattr $C$DW$892, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$893	.dwtag  DW_TAG_member
	.dwattr $C$DW$893, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$893, DW_AT_name("a21")
	.dwattr $C$DW$893, DW_AT_TI_symbol_name("_a21")
	.dwattr $C$DW$893, DW_AT_data_member_location[DW_OP_plus_uconst 0xa4]
	.dwattr $C$DW$893, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$894	.dwtag  DW_TAG_member
	.dwattr $C$DW$894, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$894, DW_AT_name("b20")
	.dwattr $C$DW$894, DW_AT_TI_symbol_name("_b20")
	.dwattr $C$DW$894, DW_AT_data_member_location[DW_OP_plus_uconst 0xa8]
	.dwattr $C$DW$894, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$895	.dwtag  DW_TAG_member
	.dwattr $C$DW$895, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$895, DW_AT_name("b21")
	.dwattr $C$DW$895, DW_AT_TI_symbol_name("_b21")
	.dwattr $C$DW$895, DW_AT_data_member_location[DW_OP_plus_uconst 0xac]
	.dwattr $C$DW$895, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$896	.dwtag  DW_TAG_member
	.dwattr $C$DW$896, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$896, DW_AT_name("a22")
	.dwattr $C$DW$896, DW_AT_TI_symbol_name("_a22")
	.dwattr $C$DW$896, DW_AT_data_member_location[DW_OP_plus_uconst 0xb0]
	.dwattr $C$DW$896, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$897	.dwtag  DW_TAG_member
	.dwattr $C$DW$897, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$897, DW_AT_name("a23")
	.dwattr $C$DW$897, DW_AT_TI_symbol_name("_a23")
	.dwattr $C$DW$897, DW_AT_data_member_location[DW_OP_plus_uconst 0xb4]
	.dwattr $C$DW$897, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$898	.dwtag  DW_TAG_member
	.dwattr $C$DW$898, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$898, DW_AT_name("b22")
	.dwattr $C$DW$898, DW_AT_TI_symbol_name("_b22")
	.dwattr $C$DW$898, DW_AT_data_member_location[DW_OP_plus_uconst 0xb8]
	.dwattr $C$DW$898, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$899	.dwtag  DW_TAG_member
	.dwattr $C$DW$899, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$899, DW_AT_name("b23")
	.dwattr $C$DW$899, DW_AT_TI_symbol_name("_b23")
	.dwattr $C$DW$899, DW_AT_data_member_location[DW_OP_plus_uconst 0xbc]
	.dwattr $C$DW$899, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$900	.dwtag  DW_TAG_member
	.dwattr $C$DW$900, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$900, DW_AT_name("a24")
	.dwattr $C$DW$900, DW_AT_TI_symbol_name("_a24")
	.dwattr $C$DW$900, DW_AT_data_member_location[DW_OP_plus_uconst 0xc0]
	.dwattr $C$DW$900, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$901	.dwtag  DW_TAG_member
	.dwattr $C$DW$901, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$901, DW_AT_name("a25")
	.dwattr $C$DW$901, DW_AT_TI_symbol_name("_a25")
	.dwattr $C$DW$901, DW_AT_data_member_location[DW_OP_plus_uconst 0xc4]
	.dwattr $C$DW$901, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$902	.dwtag  DW_TAG_member
	.dwattr $C$DW$902, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$902, DW_AT_name("b24")
	.dwattr $C$DW$902, DW_AT_TI_symbol_name("_b24")
	.dwattr $C$DW$902, DW_AT_data_member_location[DW_OP_plus_uconst 0xc8]
	.dwattr $C$DW$902, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$903	.dwtag  DW_TAG_member
	.dwattr $C$DW$903, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$903, DW_AT_name("b25")
	.dwattr $C$DW$903, DW_AT_TI_symbol_name("_b25")
	.dwattr $C$DW$903, DW_AT_data_member_location[DW_OP_plus_uconst 0xcc]
	.dwattr $C$DW$903, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$904	.dwtag  DW_TAG_member
	.dwattr $C$DW$904, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$904, DW_AT_name("a26")
	.dwattr $C$DW$904, DW_AT_TI_symbol_name("_a26")
	.dwattr $C$DW$904, DW_AT_data_member_location[DW_OP_plus_uconst 0xd0]
	.dwattr $C$DW$904, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$905	.dwtag  DW_TAG_member
	.dwattr $C$DW$905, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$905, DW_AT_name("a27")
	.dwattr $C$DW$905, DW_AT_TI_symbol_name("_a27")
	.dwattr $C$DW$905, DW_AT_data_member_location[DW_OP_plus_uconst 0xd4]
	.dwattr $C$DW$905, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$906	.dwtag  DW_TAG_member
	.dwattr $C$DW$906, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$906, DW_AT_name("b26")
	.dwattr $C$DW$906, DW_AT_TI_symbol_name("_b26")
	.dwattr $C$DW$906, DW_AT_data_member_location[DW_OP_plus_uconst 0xd8]
	.dwattr $C$DW$906, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$907	.dwtag  DW_TAG_member
	.dwattr $C$DW$907, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$907, DW_AT_name("b27")
	.dwattr $C$DW$907, DW_AT_TI_symbol_name("_b27")
	.dwattr $C$DW$907, DW_AT_data_member_location[DW_OP_plus_uconst 0xdc]
	.dwattr $C$DW$907, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$908	.dwtag  DW_TAG_member
	.dwattr $C$DW$908, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$908, DW_AT_name("a28")
	.dwattr $C$DW$908, DW_AT_TI_symbol_name("_a28")
	.dwattr $C$DW$908, DW_AT_data_member_location[DW_OP_plus_uconst 0xe0]
	.dwattr $C$DW$908, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$909	.dwtag  DW_TAG_member
	.dwattr $C$DW$909, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$909, DW_AT_name("a29")
	.dwattr $C$DW$909, DW_AT_TI_symbol_name("_a29")
	.dwattr $C$DW$909, DW_AT_data_member_location[DW_OP_plus_uconst 0xe4]
	.dwattr $C$DW$909, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$910	.dwtag  DW_TAG_member
	.dwattr $C$DW$910, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$910, DW_AT_name("b28")
	.dwattr $C$DW$910, DW_AT_TI_symbol_name("_b28")
	.dwattr $C$DW$910, DW_AT_data_member_location[DW_OP_plus_uconst 0xe8]
	.dwattr $C$DW$910, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$911	.dwtag  DW_TAG_member
	.dwattr $C$DW$911, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$911, DW_AT_name("b29")
	.dwattr $C$DW$911, DW_AT_TI_symbol_name("_b29")
	.dwattr $C$DW$911, DW_AT_data_member_location[DW_OP_plus_uconst 0xec]
	.dwattr $C$DW$911, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$912	.dwtag  DW_TAG_member
	.dwattr $C$DW$912, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$912, DW_AT_name("a30")
	.dwattr $C$DW$912, DW_AT_TI_symbol_name("_a30")
	.dwattr $C$DW$912, DW_AT_data_member_location[DW_OP_plus_uconst 0xf0]
	.dwattr $C$DW$912, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$913	.dwtag  DW_TAG_member
	.dwattr $C$DW$913, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$913, DW_AT_name("a31")
	.dwattr $C$DW$913, DW_AT_TI_symbol_name("_a31")
	.dwattr $C$DW$913, DW_AT_data_member_location[DW_OP_plus_uconst 0xf4]
	.dwattr $C$DW$913, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$914	.dwtag  DW_TAG_member
	.dwattr $C$DW$914, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$914, DW_AT_name("b30")
	.dwattr $C$DW$914, DW_AT_TI_symbol_name("_b30")
	.dwattr $C$DW$914, DW_AT_data_member_location[DW_OP_plus_uconst 0xf8]
	.dwattr $C$DW$914, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$915	.dwtag  DW_TAG_member
	.dwattr $C$DW$915, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$915, DW_AT_name("b31")
	.dwattr $C$DW$915, DW_AT_TI_symbol_name("_b31")
	.dwattr $C$DW$915, DW_AT_data_member_location[DW_OP_plus_uconst 0xfc]
	.dwattr $C$DW$915, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$916	.dwtag  DW_TAG_member
	.dwattr $C$DW$916, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$916, DW_AT_name("amr")
	.dwattr $C$DW$916, DW_AT_TI_symbol_name("_amr")
	.dwattr $C$DW$916, DW_AT_data_member_location[DW_OP_plus_uconst 0x100]
	.dwattr $C$DW$916, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$87	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$87, DW_AT_declaration
	.dwattr $C$DW$87, DW_AT_TI_symbol_name("___as__13s_os_registerFRC13s_os_register")
	.dwattr $C$DW$87, DW_AT_type(*$C$DW$T$152)
	.dwattr $C$DW$87, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$917	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$917, DW_AT_type(*$C$DW$T$154)
	.dwendtag $C$DW$87

	.dwendtag $C$DW$T$156

$C$DW$T$152	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$152, DW_AT_type(*$C$DW$T$156)
	.dwattr $C$DW$T$152, DW_AT_address_class(0x20)

$C$DW$T$155	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$155, DW_AT_type(*$C$DW$T$152)
	.dwattr $C$DW$T$155, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$918	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$918, DW_AT_type(*$C$DW$T$154)
	.dwendtag $C$DW$T$155

$C$DW$T$153	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$153, DW_AT_type(*$C$DW$T$156)
$C$DW$T$154	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$154, DW_AT_type(*$C$DW$T$153)
	.dwattr $C$DW$T$154, DW_AT_address_class(0x20)
$C$DW$T$194	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$194, DW_AT_type(*$C$DW$T$156)
	.dwattr $C$DW$T$194, DW_AT_address_class(0x20)

$C$DW$T$163	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$163, DW_AT_name("s_os_locker")
	.dwattr $C$DW$T$163, DW_AT_byte_size(0x20)
$C$DW$919	.dwtag  DW_TAG_member
	.dwattr $C$DW$919, DW_AT_type(*$C$DW$T$157)
	.dwattr $C$DW$919, DW_AT_name("p")
	.dwattr $C$DW$919, DW_AT_TI_symbol_name("_p")
	.dwattr $C$DW$919, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$919, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$920	.dwtag  DW_TAG_member
	.dwattr $C$DW$920, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$920, DW_AT_name("s")
	.dwattr $C$DW$920, DW_AT_TI_symbol_name("_s")
	.dwattr $C$DW$920, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$920, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$921	.dwtag  DW_TAG_member
	.dwattr $C$DW$921, DW_AT_type(*$C$DW$T$158)
	.dwattr $C$DW$921, DW_AT_name("next")
	.dwattr $C$DW$921, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$921, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$921, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$922	.dwtag  DW_TAG_member
	.dwattr $C$DW$922, DW_AT_type(*$C$DW$T$158)
	.dwattr $C$DW$922, DW_AT_name("prev")
	.dwattr $C$DW$922, DW_AT_TI_symbol_name("_prev")
	.dwattr $C$DW$922, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$922, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$923	.dwtag  DW_TAG_member
	.dwattr $C$DW$923, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$923, DW_AT_name("state")
	.dwattr $C$DW$923, DW_AT_TI_symbol_name("_state")
	.dwattr $C$DW$923, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$923, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$924	.dwtag  DW_TAG_member
	.dwattr $C$DW$924, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$924, DW_AT_name("unlock_at")
	.dwattr $C$DW$924, DW_AT_TI_symbol_name("_unlock_at")
	.dwattr $C$DW$924, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$924, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$88	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$88, DW_AT_declaration
	.dwattr $C$DW$88, DW_AT_TI_symbol_name("___as__11s_os_lockerFRC11s_os_locker")
	.dwattr $C$DW$88, DW_AT_type(*$C$DW$T$159)
	.dwattr $C$DW$88, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$925	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$925, DW_AT_type(*$C$DW$T$161)
	.dwendtag $C$DW$88

	.dwendtag $C$DW$T$163

$C$DW$T$158	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$158, DW_AT_type(*$C$DW$T$163)
	.dwattr $C$DW$T$158, DW_AT_address_class(0x20)
$C$DW$T$159	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$159, DW_AT_type(*$C$DW$T$163)
	.dwattr $C$DW$T$159, DW_AT_address_class(0x20)

$C$DW$T$162	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$162, DW_AT_type(*$C$DW$T$159)
	.dwattr $C$DW$T$162, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$926	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$926, DW_AT_type(*$C$DW$T$161)
	.dwendtag $C$DW$T$162

$C$DW$T$160	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$160, DW_AT_type(*$C$DW$T$163)
$C$DW$T$161	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$161, DW_AT_type(*$C$DW$T$160)
	.dwattr $C$DW$T$161, DW_AT_address_class(0x20)

$C$DW$T$169	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$169, DW_AT_name("s_os_mem_block")
	.dwattr $C$DW$T$169, DW_AT_byte_size(0x10)
$C$DW$927	.dwtag  DW_TAG_member
	.dwattr $C$DW$927, DW_AT_type(*$C$DW$T$164)
	.dwattr $C$DW$927, DW_AT_name("prev")
	.dwattr $C$DW$927, DW_AT_TI_symbol_name("_prev")
	.dwattr $C$DW$927, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$927, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$928	.dwtag  DW_TAG_member
	.dwattr $C$DW$928, DW_AT_type(*$C$DW$T$164)
	.dwattr $C$DW$928, DW_AT_name("next")
	.dwattr $C$DW$928, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$928, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$928, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$929	.dwtag  DW_TAG_member
	.dwattr $C$DW$929, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$929, DW_AT_name("length")
	.dwattr $C$DW$929, DW_AT_TI_symbol_name("_length")
	.dwattr $C$DW$929, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$929, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$930	.dwtag  DW_TAG_member
	.dwattr $C$DW$930, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$930, DW_AT_name("pid")
	.dwattr $C$DW$930, DW_AT_TI_symbol_name("_pid")
	.dwattr $C$DW$930, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$930, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$931	.dwtag  DW_TAG_member
	.dwattr $C$DW$931, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$931, DW_AT_name("flags")
	.dwattr $C$DW$931, DW_AT_TI_symbol_name("_flags")
	.dwattr $C$DW$931, DW_AT_data_member_location[DW_OP_plus_uconst 0xe]
	.dwattr $C$DW$931, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$89	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$89, DW_AT_declaration
	.dwattr $C$DW$89, DW_AT_TI_symbol_name("___as__14s_os_mem_blockFRC14s_os_mem_block")
	.dwattr $C$DW$89, DW_AT_type(*$C$DW$T$165)
	.dwattr $C$DW$89, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$932	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$932, DW_AT_type(*$C$DW$T$167)
	.dwendtag $C$DW$89

	.dwendtag $C$DW$T$169

$C$DW$T$164	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$164, DW_AT_type(*$C$DW$T$169)
	.dwattr $C$DW$T$164, DW_AT_address_class(0x20)
$C$DW$T$255	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$255, DW_AT_type(*$C$DW$T$164)
	.dwattr $C$DW$T$255, DW_AT_address_class(0x20)
$C$DW$T$165	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$165, DW_AT_type(*$C$DW$T$169)
	.dwattr $C$DW$T$165, DW_AT_address_class(0x20)

$C$DW$T$168	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$168, DW_AT_type(*$C$DW$T$165)
	.dwattr $C$DW$T$168, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$933	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$933, DW_AT_type(*$C$DW$T$167)
	.dwendtag $C$DW$T$168

$C$DW$T$166	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$166, DW_AT_type(*$C$DW$T$169)
$C$DW$T$167	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$167, DW_AT_type(*$C$DW$T$166)
	.dwattr $C$DW$T$167, DW_AT_address_class(0x20)

$C$DW$T$175	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$175, DW_AT_name("s_os_heap")
	.dwattr $C$DW$T$175, DW_AT_byte_size(0x10)
$C$DW$934	.dwtag  DW_TAG_member
	.dwattr $C$DW$934, DW_AT_type(*$C$DW$T$170)
	.dwattr $C$DW$934, DW_AT_name("prev")
	.dwattr $C$DW$934, DW_AT_TI_symbol_name("_prev")
	.dwattr $C$DW$934, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$934, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$935	.dwtag  DW_TAG_member
	.dwattr $C$DW$935, DW_AT_type(*$C$DW$T$170)
	.dwattr $C$DW$935, DW_AT_name("next")
	.dwattr $C$DW$935, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$935, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$935, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$936	.dwtag  DW_TAG_member
	.dwattr $C$DW$936, DW_AT_type(*$C$DW$T$164)
	.dwattr $C$DW$936, DW_AT_name("block")
	.dwattr $C$DW$936, DW_AT_TI_symbol_name("_block")
	.dwattr $C$DW$936, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$936, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$937	.dwtag  DW_TAG_member
	.dwattr $C$DW$937, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$937, DW_AT_name("flags")
	.dwattr $C$DW$937, DW_AT_TI_symbol_name("_flags")
	.dwattr $C$DW$937, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$937, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$90	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$90, DW_AT_declaration
	.dwattr $C$DW$90, DW_AT_TI_symbol_name("___as__9s_os_heapFRC9s_os_heap")
	.dwattr $C$DW$90, DW_AT_type(*$C$DW$T$171)
	.dwattr $C$DW$90, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$938	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$938, DW_AT_type(*$C$DW$T$173)
	.dwendtag $C$DW$90

	.dwendtag $C$DW$T$175

$C$DW$T$170	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$170, DW_AT_type(*$C$DW$T$175)
	.dwattr $C$DW$T$170, DW_AT_address_class(0x20)
$C$DW$T$171	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$171, DW_AT_type(*$C$DW$T$175)
	.dwattr $C$DW$T$171, DW_AT_address_class(0x20)

$C$DW$T$174	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$174, DW_AT_type(*$C$DW$T$171)
	.dwattr $C$DW$T$174, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$939	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$939, DW_AT_type(*$C$DW$T$173)
	.dwendtag $C$DW$T$174

$C$DW$T$172	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$172, DW_AT_type(*$C$DW$T$175)
$C$DW$T$173	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$173, DW_AT_type(*$C$DW$T$172)
	.dwattr $C$DW$T$173, DW_AT_address_class(0x20)

$C$DW$T$180	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$180, DW_AT_name("s_os_extension_f")
	.dwattr $C$DW$T$180, DW_AT_byte_size(0x0c)
$C$DW$940	.dwtag  DW_TAG_member
	.dwattr $C$DW$940, DW_AT_type(*$C$DW$T$111)
	.dwattr $C$DW$940, DW_AT_name("f_name")
	.dwattr $C$DW$940, DW_AT_TI_symbol_name("_f_name")
	.dwattr $C$DW$940, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$940, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$941	.dwtag  DW_TAG_member
	.dwattr $C$DW$941, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$941, DW_AT_name("f_syscall_index")
	.dwattr $C$DW$941, DW_AT_TI_symbol_name("_f_syscall_index")
	.dwattr $C$DW$941, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$941, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$942	.dwtag  DW_TAG_member
	.dwattr $C$DW$942, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$942, DW_AT_name("f_ptr")
	.dwattr $C$DW$942, DW_AT_TI_symbol_name("_f_ptr")
	.dwattr $C$DW$942, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$942, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$91	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$91, DW_AT_declaration
	.dwattr $C$DW$91, DW_AT_TI_symbol_name("___as__16s_os_extension_fFRC16s_os_extension_f")
	.dwattr $C$DW$91, DW_AT_type(*$C$DW$T$176)
	.dwattr $C$DW$91, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$943	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$943, DW_AT_type(*$C$DW$T$178)
	.dwendtag $C$DW$91

	.dwendtag $C$DW$T$180

$C$DW$T$176	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$176, DW_AT_type(*$C$DW$T$180)
	.dwattr $C$DW$T$176, DW_AT_address_class(0x20)

$C$DW$T$179	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$179, DW_AT_type(*$C$DW$T$176)
	.dwattr $C$DW$T$179, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$944	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$944, DW_AT_type(*$C$DW$T$178)
	.dwendtag $C$DW$T$179

$C$DW$T$177	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$177, DW_AT_type(*$C$DW$T$180)
$C$DW$T$178	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$178, DW_AT_type(*$C$DW$T$177)
	.dwattr $C$DW$T$178, DW_AT_address_class(0x20)
$C$DW$T$182	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$182, DW_AT_type(*$C$DW$T$180)
	.dwattr $C$DW$T$182, DW_AT_address_class(0x20)

$C$DW$T$187	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$187, DW_AT_name("s_os_extension")
	.dwattr $C$DW$T$187, DW_AT_byte_size(0x28)
$C$DW$945	.dwtag  DW_TAG_member
	.dwattr $C$DW$945, DW_AT_type(*$C$DW$T$181)
	.dwattr $C$DW$945, DW_AT_name("next")
	.dwattr $C$DW$945, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$945, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$945, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$946	.dwtag  DW_TAG_member
	.dwattr $C$DW$946, DW_AT_type(*$C$DW$T$181)
	.dwattr $C$DW$946, DW_AT_name("prev")
	.dwattr $C$DW$946, DW_AT_TI_symbol_name("_prev")
	.dwattr $C$DW$946, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$946, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$947	.dwtag  DW_TAG_member
	.dwattr $C$DW$947, DW_AT_type(*$C$DW$T$111)
	.dwattr $C$DW$947, DW_AT_name("name")
	.dwattr $C$DW$947, DW_AT_TI_symbol_name("_name")
	.dwattr $C$DW$947, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$947, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$948	.dwtag  DW_TAG_member
	.dwattr $C$DW$948, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$948, DW_AT_name("f_count")
	.dwattr $C$DW$948, DW_AT_TI_symbol_name("_f_count")
	.dwattr $C$DW$948, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$948, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$949	.dwtag  DW_TAG_member
	.dwattr $C$DW$949, DW_AT_type(*$C$DW$T$182)
	.dwattr $C$DW$949, DW_AT_name("f_tab")
	.dwattr $C$DW$949, DW_AT_TI_symbol_name("_f_tab")
	.dwattr $C$DW$949, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$949, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$950	.dwtag  DW_TAG_member
	.dwattr $C$DW$950, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$950, DW_AT_name("usage")
	.dwattr $C$DW$950, DW_AT_TI_symbol_name("_usage")
	.dwattr $C$DW$950, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$950, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$951	.dwtag  DW_TAG_member
	.dwattr $C$DW$951, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$951, DW_AT_name("lacc")
	.dwattr $C$DW$951, DW_AT_TI_symbol_name("_lacc")
	.dwattr $C$DW$951, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$951, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$952	.dwtag  DW_TAG_member
	.dwattr $C$DW$952, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$952, DW_AT_name("flags")
	.dwattr $C$DW$952, DW_AT_TI_symbol_name("_flags")
	.dwattr $C$DW$952, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr $C$DW$952, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$953	.dwtag  DW_TAG_member
	.dwattr $C$DW$953, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$953, DW_AT_name("own_process")
	.dwattr $C$DW$953, DW_AT_TI_symbol_name("_own_process")
	.dwattr $C$DW$953, DW_AT_data_member_location[DW_OP_plus_uconst 0x24]
	.dwattr $C$DW$953, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$92	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$92, DW_AT_declaration
	.dwattr $C$DW$92, DW_AT_TI_symbol_name("___as__14s_os_extensionFRC14s_os_extension")
	.dwattr $C$DW$92, DW_AT_type(*$C$DW$T$183)
	.dwattr $C$DW$92, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$954	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$954, DW_AT_type(*$C$DW$T$185)
	.dwendtag $C$DW$92

	.dwendtag $C$DW$T$187

$C$DW$T$181	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$181, DW_AT_type(*$C$DW$T$187)
	.dwattr $C$DW$T$181, DW_AT_address_class(0x20)
$C$DW$T$183	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$183, DW_AT_type(*$C$DW$T$187)
	.dwattr $C$DW$T$183, DW_AT_address_class(0x20)

$C$DW$T$186	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$186, DW_AT_type(*$C$DW$T$183)
	.dwattr $C$DW$T$186, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$955	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$955, DW_AT_type(*$C$DW$T$185)
	.dwendtag $C$DW$T$186

$C$DW$T$184	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$184, DW_AT_type(*$C$DW$T$187)
$C$DW$T$185	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$185, DW_AT_type(*$C$DW$T$184)
	.dwattr $C$DW$T$185, DW_AT_address_class(0x20)

$C$DW$T$193	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$193, DW_AT_name("s_os_extension_link")
	.dwattr $C$DW$T$193, DW_AT_byte_size(0x0c)
$C$DW$956	.dwtag  DW_TAG_member
	.dwattr $C$DW$956, DW_AT_type(*$C$DW$T$188)
	.dwattr $C$DW$956, DW_AT_name("prev")
	.dwattr $C$DW$956, DW_AT_TI_symbol_name("_prev")
	.dwattr $C$DW$956, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$956, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$957	.dwtag  DW_TAG_member
	.dwattr $C$DW$957, DW_AT_type(*$C$DW$T$188)
	.dwattr $C$DW$957, DW_AT_name("next")
	.dwattr $C$DW$957, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$957, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$957, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$958	.dwtag  DW_TAG_member
	.dwattr $C$DW$958, DW_AT_type(*$C$DW$T$181)
	.dwattr $C$DW$958, DW_AT_name("e")
	.dwattr $C$DW$958, DW_AT_TI_symbol_name("_e")
	.dwattr $C$DW$958, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$958, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$93	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$93, DW_AT_declaration
	.dwattr $C$DW$93, DW_AT_TI_symbol_name("___as__19s_os_extension_linkFRC19s_os_extension_link")
	.dwattr $C$DW$93, DW_AT_type(*$C$DW$T$189)
	.dwattr $C$DW$93, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$959	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$959, DW_AT_type(*$C$DW$T$191)
	.dwendtag $C$DW$93

	.dwendtag $C$DW$T$193

$C$DW$T$188	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$188, DW_AT_type(*$C$DW$T$193)
	.dwattr $C$DW$T$188, DW_AT_address_class(0x20)
$C$DW$T$189	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$189, DW_AT_type(*$C$DW$T$193)
	.dwattr $C$DW$T$189, DW_AT_address_class(0x20)

$C$DW$T$192	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$192, DW_AT_type(*$C$DW$T$189)
	.dwattr $C$DW$T$192, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$960	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$960, DW_AT_type(*$C$DW$T$191)
	.dwendtag $C$DW$T$192

$C$DW$T$190	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$190, DW_AT_type(*$C$DW$T$193)
$C$DW$T$191	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$191, DW_AT_type(*$C$DW$T$190)
	.dwattr $C$DW$T$191, DW_AT_address_class(0x20)

$C$DW$T$199	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$199, DW_AT_name("s_os_process_context")
	.dwattr $C$DW$T$199, DW_AT_byte_size(0x88)
$C$DW$961	.dwtag  DW_TAG_member
	.dwattr $C$DW$961, DW_AT_type(*$C$DW$T$194)
	.dwattr $C$DW$961, DW_AT_name("reg")
	.dwattr $C$DW$961, DW_AT_TI_symbol_name("_reg")
	.dwattr $C$DW$961, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$961, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$962	.dwtag  DW_TAG_member
	.dwattr $C$DW$962, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$962, DW_AT_name("id")
	.dwattr $C$DW$962, DW_AT_TI_symbol_name("_id")
	.dwattr $C$DW$962, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$962, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$963	.dwtag  DW_TAG_member
	.dwattr $C$DW$963, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$963, DW_AT_name("pflags")
	.dwattr $C$DW$963, DW_AT_TI_symbol_name("_pflags")
	.dwattr $C$DW$963, DW_AT_data_member_location[DW_OP_plus_uconst 0x6]
	.dwattr $C$DW$963, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$964	.dwtag  DW_TAG_member
	.dwattr $C$DW$964, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$964, DW_AT_name("peff")
	.dwattr $C$DW$964, DW_AT_TI_symbol_name("_peff")
	.dwattr $C$DW$964, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$964, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$965	.dwtag  DW_TAG_member
	.dwattr $C$DW$965, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$965, DW_AT_name("pcnt")
	.dwattr $C$DW$965, DW_AT_TI_symbol_name("_pcnt")
	.dwattr $C$DW$965, DW_AT_data_member_location[DW_OP_plus_uconst 0xa]
	.dwattr $C$DW$965, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$966	.dwtag  DW_TAG_member
	.dwattr $C$DW$966, DW_AT_type(*$C$DW$T$157)
	.dwattr $C$DW$966, DW_AT_name("next")
	.dwattr $C$DW$966, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$966, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$966, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$967	.dwtag  DW_TAG_member
	.dwattr $C$DW$967, DW_AT_type(*$C$DW$T$157)
	.dwattr $C$DW$967, DW_AT_name("prev")
	.dwattr $C$DW$967, DW_AT_TI_symbol_name("_prev")
	.dwattr $C$DW$967, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$967, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$968	.dwtag  DW_TAG_member
	.dwattr $C$DW$968, DW_AT_type(*$C$DW$T$163)
	.dwattr $C$DW$968, DW_AT_name("locker")
	.dwattr $C$DW$968, DW_AT_TI_symbol_name("_locker")
	.dwattr $C$DW$968, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$968, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$969	.dwtag  DW_TAG_member
	.dwattr $C$DW$969, DW_AT_type(*$C$DW$T$170)
	.dwattr $C$DW$969, DW_AT_name("heap")
	.dwattr $C$DW$969, DW_AT_TI_symbol_name("_heap")
	.dwattr $C$DW$969, DW_AT_data_member_location[DW_OP_plus_uconst 0x38]
	.dwattr $C$DW$969, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$970	.dwtag  DW_TAG_member
	.dwattr $C$DW$970, DW_AT_type(*$C$DW$T$164)
	.dwattr $C$DW$970, DW_AT_name("stack")
	.dwattr $C$DW$970, DW_AT_TI_symbol_name("_stack")
	.dwattr $C$DW$970, DW_AT_data_member_location[DW_OP_plus_uconst 0x3c]
	.dwattr $C$DW$970, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$971	.dwtag  DW_TAG_member
	.dwattr $C$DW$971, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$971, DW_AT_name("arg")
	.dwattr $C$DW$971, DW_AT_TI_symbol_name("_arg")
	.dwattr $C$DW$971, DW_AT_data_member_location[DW_OP_plus_uconst 0x40]
	.dwattr $C$DW$971, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$972	.dwtag  DW_TAG_member
	.dwattr $C$DW$972, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$972, DW_AT_name("arglen")
	.dwattr $C$DW$972, DW_AT_TI_symbol_name("_arglen")
	.dwattr $C$DW$972, DW_AT_data_member_location[DW_OP_plus_uconst 0x44]
	.dwattr $C$DW$972, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$973	.dwtag  DW_TAG_member
	.dwattr $C$DW$973, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$973, DW_AT_name("sfault_code")
	.dwattr $C$DW$973, DW_AT_TI_symbol_name("_sfault_code")
	.dwattr $C$DW$973, DW_AT_data_member_location[DW_OP_plus_uconst 0x48]
	.dwattr $C$DW$973, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$974	.dwtag  DW_TAG_member
	.dwattr $C$DW$974, DW_AT_type(*$C$DW$T$157)
	.dwattr $C$DW$974, DW_AT_name("parent")
	.dwattr $C$DW$974, DW_AT_TI_symbol_name("_parent")
	.dwattr $C$DW$974, DW_AT_data_member_location[DW_OP_plus_uconst 0x4c]
	.dwattr $C$DW$974, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$975	.dwtag  DW_TAG_member
	.dwattr $C$DW$975, DW_AT_type(*$C$DW$T$205)
	.dwattr $C$DW$975, DW_AT_name("msg")
	.dwattr $C$DW$975, DW_AT_TI_symbol_name("_msg")
	.dwattr $C$DW$975, DW_AT_data_member_location[DW_OP_plus_uconst 0x50]
	.dwattr $C$DW$975, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$976	.dwtag  DW_TAG_member
	.dwattr $C$DW$976, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$976, DW_AT_name("errno")
	.dwattr $C$DW$976, DW_AT_TI_symbol_name("_errno")
	.dwattr $C$DW$976, DW_AT_data_member_location[DW_OP_plus_uconst 0x78]
	.dwattr $C$DW$976, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$977	.dwtag  DW_TAG_member
	.dwattr $C$DW$977, DW_AT_type(*$C$DW$T$188)
	.dwattr $C$DW$977, DW_AT_name("ext_used")
	.dwattr $C$DW$977, DW_AT_TI_symbol_name("_ext_used")
	.dwattr $C$DW$977, DW_AT_data_member_location[DW_OP_plus_uconst 0x7c]
	.dwattr $C$DW$977, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$978	.dwtag  DW_TAG_member
	.dwattr $C$DW$978, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$978, DW_AT_name("join_sem")
	.dwattr $C$DW$978, DW_AT_TI_symbol_name("_join_sem")
	.dwattr $C$DW$978, DW_AT_data_member_location[DW_OP_plus_uconst 0x80]
	.dwattr $C$DW$978, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$94	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$94, DW_AT_declaration
	.dwattr $C$DW$94, DW_AT_TI_symbol_name("___as__20s_os_process_contextFRC20s_os_process_context")
	.dwattr $C$DW$94, DW_AT_type(*$C$DW$T$195)
	.dwattr $C$DW$94, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$979	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$979, DW_AT_type(*$C$DW$T$197)
	.dwendtag $C$DW$94

	.dwendtag $C$DW$T$199

$C$DW$T$157	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$157, DW_AT_type(*$C$DW$T$199)
	.dwattr $C$DW$T$157, DW_AT_address_class(0x20)
$C$DW$T$195	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$195, DW_AT_type(*$C$DW$T$199)
	.dwattr $C$DW$T$195, DW_AT_address_class(0x20)

$C$DW$T$198	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$198, DW_AT_type(*$C$DW$T$195)
	.dwattr $C$DW$T$198, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$980	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$980, DW_AT_type(*$C$DW$T$197)
	.dwendtag $C$DW$T$198

$C$DW$T$196	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$196, DW_AT_type(*$C$DW$T$199)
$C$DW$T$197	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$197, DW_AT_type(*$C$DW$T$196)
	.dwattr $C$DW$T$197, DW_AT_address_class(0x20)

$C$DW$T$205	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$205, DW_AT_name("s_message_process_data")
	.dwattr $C$DW$T$205, DW_AT_byte_size(0x28)
$C$DW$981	.dwtag  DW_TAG_member
	.dwattr $C$DW$981, DW_AT_type(*$C$DW$T$200)
	.dwattr $C$DW$981, DW_AT_name("prev")
	.dwattr $C$DW$981, DW_AT_TI_symbol_name("_prev")
	.dwattr $C$DW$981, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$981, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$982	.dwtag  DW_TAG_member
	.dwattr $C$DW$982, DW_AT_type(*$C$DW$T$200)
	.dwattr $C$DW$982, DW_AT_name("next")
	.dwattr $C$DW$982, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$982, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$982, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$983	.dwtag  DW_TAG_member
	.dwattr $C$DW$983, DW_AT_type(*$C$DW$T$157)
	.dwattr $C$DW$983, DW_AT_name("p")
	.dwattr $C$DW$983, DW_AT_TI_symbol_name("_p")
	.dwattr $C$DW$983, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$983, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$984	.dwtag  DW_TAG_member
	.dwattr $C$DW$984, DW_AT_type(*$C$DW$T$80)
	.dwattr $C$DW$984, DW_AT_name("name")
	.dwattr $C$DW$984, DW_AT_TI_symbol_name("_name")
	.dwattr $C$DW$984, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$984, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$985	.dwtag  DW_TAG_member
	.dwattr $C$DW$985, DW_AT_type(*$C$DW$T$134)
	.dwattr $C$DW$985, DW_AT_name("inq")
	.dwattr $C$DW$985, DW_AT_TI_symbol_name("_inq")
	.dwattr $C$DW$985, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$985, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$986	.dwtag  DW_TAG_member
	.dwattr $C$DW$986, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$986, DW_AT_name("avg_ppid")
	.dwattr $C$DW$986, DW_AT_TI_symbol_name("_avg_ppid")
	.dwattr $C$DW$986, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr $C$DW$986, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$987	.dwtag  DW_TAG_member
	.dwattr $C$DW$987, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$987, DW_AT_name("avg_reqid")
	.dwattr $C$DW$987, DW_AT_TI_symbol_name("_avg_reqid")
	.dwattr $C$DW$987, DW_AT_data_member_location[DW_OP_plus_uconst 0x24]
	.dwattr $C$DW$987, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$95	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$95, DW_AT_declaration
	.dwattr $C$DW$95, DW_AT_TI_symbol_name("___as__22s_message_process_dataFRC22s_message_process_data")
	.dwattr $C$DW$95, DW_AT_type(*$C$DW$T$201)
	.dwattr $C$DW$95, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$988	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$988, DW_AT_type(*$C$DW$T$203)
	.dwendtag $C$DW$95

	.dwendtag $C$DW$T$205

$C$DW$T$200	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$200, DW_AT_type(*$C$DW$T$205)
	.dwattr $C$DW$T$200, DW_AT_address_class(0x20)
$C$DW$T$201	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$201, DW_AT_type(*$C$DW$T$205)
	.dwattr $C$DW$T$201, DW_AT_address_class(0x20)

$C$DW$T$204	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$204, DW_AT_type(*$C$DW$T$201)
	.dwattr $C$DW$T$204, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$989	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$989, DW_AT_type(*$C$DW$T$203)
	.dwendtag $C$DW$T$204

$C$DW$T$202	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$202, DW_AT_type(*$C$DW$T$205)
$C$DW$T$203	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$203, DW_AT_type(*$C$DW$T$202)
	.dwattr $C$DW$T$203, DW_AT_address_class(0x20)

$C$DW$T$210	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$210, DW_AT_name("s_os_core_init")
	.dwattr $C$DW$T$210, DW_AT_byte_size(0x14)
$C$DW$990	.dwtag  DW_TAG_member
	.dwattr $C$DW$990, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$990, DW_AT_name("core_heap_len")
	.dwattr $C$DW$990, DW_AT_TI_symbol_name("_core_heap_len")
	.dwattr $C$DW$990, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$990, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$991	.dwtag  DW_TAG_member
	.dwattr $C$DW$991, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$991, DW_AT_name("sys_quant")
	.dwattr $C$DW$991, DW_AT_TI_symbol_name("_sys_quant")
	.dwattr $C$DW$991, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$991, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$992	.dwtag  DW_TAG_member
	.dwattr $C$DW$992, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$992, DW_AT_name("sem_list_len")
	.dwattr $C$DW$992, DW_AT_TI_symbol_name("_sem_list_len")
	.dwattr $C$DW$992, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$992, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$993	.dwtag  DW_TAG_member
	.dwattr $C$DW$993, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$993, DW_AT_name("extram_start")
	.dwattr $C$DW$993, DW_AT_TI_symbol_name("_extram_start")
	.dwattr $C$DW$993, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$993, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$994	.dwtag  DW_TAG_member
	.dwattr $C$DW$994, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$994, DW_AT_name("extram_end")
	.dwattr $C$DW$994, DW_AT_TI_symbol_name("_extram_end")
	.dwattr $C$DW$994, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$994, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$96	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$96, DW_AT_declaration
	.dwattr $C$DW$96, DW_AT_TI_symbol_name("___as__14s_os_core_initFRC14s_os_core_init")
	.dwattr $C$DW$96, DW_AT_type(*$C$DW$T$206)
	.dwattr $C$DW$96, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$995	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$995, DW_AT_type(*$C$DW$T$208)
	.dwendtag $C$DW$96

	.dwendtag $C$DW$T$210

$C$DW$T$206	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$206, DW_AT_type(*$C$DW$T$210)
	.dwattr $C$DW$T$206, DW_AT_address_class(0x20)

$C$DW$T$209	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$209, DW_AT_type(*$C$DW$T$206)
	.dwattr $C$DW$T$209, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$996	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$996, DW_AT_type(*$C$DW$T$208)
	.dwendtag $C$DW$T$209

$C$DW$T$207	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$207, DW_AT_type(*$C$DW$T$210)
$C$DW$T$208	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$208, DW_AT_type(*$C$DW$T$207)
	.dwattr $C$DW$T$208, DW_AT_address_class(0x20)

$C$DW$T$216	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$216, DW_AT_name("s_prc_attr")
	.dwattr $C$DW$T$216, DW_AT_byte_size(0x14)
$C$DW$997	.dwtag  DW_TAG_member
	.dwattr $C$DW$997, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$997, DW_AT_name("stack")
	.dwattr $C$DW$997, DW_AT_TI_symbol_name("_stack")
	.dwattr $C$DW$997, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$997, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$998	.dwtag  DW_TAG_member
	.dwattr $C$DW$998, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$998, DW_AT_name("heap")
	.dwattr $C$DW$998, DW_AT_TI_symbol_name("_heap")
	.dwattr $C$DW$998, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$998, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$999	.dwtag  DW_TAG_member
	.dwattr $C$DW$999, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$999, DW_AT_name("priority")
	.dwattr $C$DW$999, DW_AT_TI_symbol_name("_priority")
	.dwattr $C$DW$999, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$999, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1000	.dwtag  DW_TAG_member
	.dwattr $C$DW$1000, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1000, DW_AT_name("bss")
	.dwattr $C$DW$1000, DW_AT_TI_symbol_name("_bss")
	.dwattr $C$DW$1000, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$1000, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1001	.dwtag  DW_TAG_member
	.dwattr $C$DW$1001, DW_AT_type(*$C$DW$T$211)
	.dwattr $C$DW$1001, DW_AT_name("exit_vector")
	.dwattr $C$DW$1001, DW_AT_TI_symbol_name("_exit_vector")
	.dwattr $C$DW$1001, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$1001, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$97	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$97, DW_AT_declaration
	.dwattr $C$DW$97, DW_AT_TI_symbol_name("___as__10s_prc_attrFRC10s_prc_attr")
	.dwattr $C$DW$97, DW_AT_type(*$C$DW$T$212)
	.dwattr $C$DW$97, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1002	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1002, DW_AT_type(*$C$DW$T$214)
	.dwendtag $C$DW$97

	.dwendtag $C$DW$T$216

$C$DW$T$212	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$212, DW_AT_type(*$C$DW$T$216)
	.dwattr $C$DW$T$212, DW_AT_address_class(0x20)

$C$DW$T$215	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$215, DW_AT_type(*$C$DW$T$212)
	.dwattr $C$DW$T$215, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1003	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1003, DW_AT_type(*$C$DW$T$214)
	.dwendtag $C$DW$T$215

$C$DW$T$213	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$213, DW_AT_type(*$C$DW$T$216)
$C$DW$T$214	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$214, DW_AT_type(*$C$DW$T$213)
	.dwattr $C$DW$T$214, DW_AT_address_class(0x20)

$C$DW$T$221	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$221, DW_AT_name("s_os_mem_stat")
	.dwattr $C$DW$T$221, DW_AT_byte_size(0x40)
$C$DW$1004	.dwtag  DW_TAG_member
	.dwattr $C$DW$1004, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$1004, DW_AT_name("total")
	.dwattr $C$DW$1004, DW_AT_TI_symbol_name("_total")
	.dwattr $C$DW$1004, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1004, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1005	.dwtag  DW_TAG_member
	.dwattr $C$DW$1005, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$1005, DW_AT_name("used")
	.dwattr $C$DW$1005, DW_AT_TI_symbol_name("_used")
	.dwattr $C$DW$1005, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1005, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1006	.dwtag  DW_TAG_member
	.dwattr $C$DW$1006, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$1006, DW_AT_name("free")
	.dwattr $C$DW$1006, DW_AT_TI_symbol_name("_free")
	.dwattr $C$DW$1006, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$1006, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1007	.dwtag  DW_TAG_member
	.dwattr $C$DW$1007, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1007, DW_AT_name("c_desc")
	.dwattr $C$DW$1007, DW_AT_TI_symbol_name("_c_desc")
	.dwattr $C$DW$1007, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$1007, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1008	.dwtag  DW_TAG_member
	.dwattr $C$DW$1008, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1008, DW_AT_name("c_16_64")
	.dwattr $C$DW$1008, DW_AT_TI_symbol_name("_c_16_64")
	.dwattr $C$DW$1008, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr $C$DW$1008, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1009	.dwtag  DW_TAG_member
	.dwattr $C$DW$1009, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1009, DW_AT_name("c_64_256")
	.dwattr $C$DW$1009, DW_AT_TI_symbol_name("_c_64_256")
	.dwattr $C$DW$1009, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr $C$DW$1009, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1010	.dwtag  DW_TAG_member
	.dwattr $C$DW$1010, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1010, DW_AT_name("c_256_1k")
	.dwattr $C$DW$1010, DW_AT_TI_symbol_name("_c_256_1k")
	.dwattr $C$DW$1010, DW_AT_data_member_location[DW_OP_plus_uconst 0x24]
	.dwattr $C$DW$1010, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1011	.dwtag  DW_TAG_member
	.dwattr $C$DW$1011, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1011, DW_AT_name("c_1k_4k")
	.dwattr $C$DW$1011, DW_AT_TI_symbol_name("_c_1k_4k")
	.dwattr $C$DW$1011, DW_AT_data_member_location[DW_OP_plus_uconst 0x28]
	.dwattr $C$DW$1011, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1012	.dwtag  DW_TAG_member
	.dwattr $C$DW$1012, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1012, DW_AT_name("c_4k_16k")
	.dwattr $C$DW$1012, DW_AT_TI_symbol_name("_c_4k_16k")
	.dwattr $C$DW$1012, DW_AT_data_member_location[DW_OP_plus_uconst 0x2c]
	.dwattr $C$DW$1012, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1013	.dwtag  DW_TAG_member
	.dwattr $C$DW$1013, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1013, DW_AT_name("c_16k_64k")
	.dwattr $C$DW$1013, DW_AT_TI_symbol_name("_c_16k_64k")
	.dwattr $C$DW$1013, DW_AT_data_member_location[DW_OP_plus_uconst 0x30]
	.dwattr $C$DW$1013, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1014	.dwtag  DW_TAG_member
	.dwattr $C$DW$1014, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1014, DW_AT_name("c_64k_256k")
	.dwattr $C$DW$1014, DW_AT_TI_symbol_name("_c_64k_256k")
	.dwattr $C$DW$1014, DW_AT_data_member_location[DW_OP_plus_uconst 0x34]
	.dwattr $C$DW$1014, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1015	.dwtag  DW_TAG_member
	.dwattr $C$DW$1015, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1015, DW_AT_name("c_256k_1m")
	.dwattr $C$DW$1015, DW_AT_TI_symbol_name("_c_256k_1m")
	.dwattr $C$DW$1015, DW_AT_data_member_location[DW_OP_plus_uconst 0x38]
	.dwattr $C$DW$1015, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1016	.dwtag  DW_TAG_member
	.dwattr $C$DW$1016, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1016, DW_AT_name("c_1m_inf")
	.dwattr $C$DW$1016, DW_AT_TI_symbol_name("_c_1m_inf")
	.dwattr $C$DW$1016, DW_AT_data_member_location[DW_OP_plus_uconst 0x3c]
	.dwattr $C$DW$1016, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$98	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$98, DW_AT_declaration
	.dwattr $C$DW$98, DW_AT_TI_symbol_name("___as__13s_os_mem_statFRC13s_os_mem_stat")
	.dwattr $C$DW$98, DW_AT_type(*$C$DW$T$217)
	.dwattr $C$DW$98, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1017	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1017, DW_AT_type(*$C$DW$T$219)
	.dwendtag $C$DW$98

	.dwendtag $C$DW$T$221

$C$DW$T$217	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$217, DW_AT_type(*$C$DW$T$221)
	.dwattr $C$DW$T$217, DW_AT_address_class(0x20)

$C$DW$T$220	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$220, DW_AT_type(*$C$DW$T$217)
	.dwattr $C$DW$T$220, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1018	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1018, DW_AT_type(*$C$DW$T$219)
	.dwendtag $C$DW$T$220

$C$DW$T$218	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$218, DW_AT_type(*$C$DW$T$221)
$C$DW$T$219	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$219, DW_AT_type(*$C$DW$T$218)
	.dwattr $C$DW$T$219, DW_AT_address_class(0x20)

$C$DW$T$226	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$226, DW_AT_name("s_os_heap_stat")
	.dwattr $C$DW$T$226, DW_AT_byte_size(0x3c)
$C$DW$1019	.dwtag  DW_TAG_member
	.dwattr $C$DW$1019, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1019, DW_AT_name("total")
	.dwattr $C$DW$1019, DW_AT_TI_symbol_name("_total")
	.dwattr $C$DW$1019, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1019, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1020	.dwtag  DW_TAG_member
	.dwattr $C$DW$1020, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1020, DW_AT_name("used")
	.dwattr $C$DW$1020, DW_AT_TI_symbol_name("_used")
	.dwattr $C$DW$1020, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1020, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1021	.dwtag  DW_TAG_member
	.dwattr $C$DW$1021, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1021, DW_AT_name("free")
	.dwattr $C$DW$1021, DW_AT_TI_symbol_name("_free")
	.dwattr $C$DW$1021, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1021, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1022	.dwtag  DW_TAG_member
	.dwattr $C$DW$1022, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1022, DW_AT_name("c_desc")
	.dwattr $C$DW$1022, DW_AT_TI_symbol_name("_c_desc")
	.dwattr $C$DW$1022, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$1022, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1023	.dwtag  DW_TAG_member
	.dwattr $C$DW$1023, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1023, DW_AT_name("c_0")
	.dwattr $C$DW$1023, DW_AT_TI_symbol_name("_c_0")
	.dwattr $C$DW$1023, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$1023, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1024	.dwtag  DW_TAG_member
	.dwattr $C$DW$1024, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1024, DW_AT_name("c_4_16")
	.dwattr $C$DW$1024, DW_AT_TI_symbol_name("_c_4_16")
	.dwattr $C$DW$1024, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$1024, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1025	.dwtag  DW_TAG_member
	.dwattr $C$DW$1025, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1025, DW_AT_name("c_16_64")
	.dwattr $C$DW$1025, DW_AT_TI_symbol_name("_c_16_64")
	.dwattr $C$DW$1025, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$1025, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1026	.dwtag  DW_TAG_member
	.dwattr $C$DW$1026, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1026, DW_AT_name("c_64_256")
	.dwattr $C$DW$1026, DW_AT_TI_symbol_name("_c_64_256")
	.dwattr $C$DW$1026, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr $C$DW$1026, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1027	.dwtag  DW_TAG_member
	.dwattr $C$DW$1027, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1027, DW_AT_name("c_256_1k")
	.dwattr $C$DW$1027, DW_AT_TI_symbol_name("_c_256_1k")
	.dwattr $C$DW$1027, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr $C$DW$1027, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1028	.dwtag  DW_TAG_member
	.dwattr $C$DW$1028, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1028, DW_AT_name("c_1k_4k")
	.dwattr $C$DW$1028, DW_AT_TI_symbol_name("_c_1k_4k")
	.dwattr $C$DW$1028, DW_AT_data_member_location[DW_OP_plus_uconst 0x24]
	.dwattr $C$DW$1028, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1029	.dwtag  DW_TAG_member
	.dwattr $C$DW$1029, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1029, DW_AT_name("c_4k_16k")
	.dwattr $C$DW$1029, DW_AT_TI_symbol_name("_c_4k_16k")
	.dwattr $C$DW$1029, DW_AT_data_member_location[DW_OP_plus_uconst 0x28]
	.dwattr $C$DW$1029, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1030	.dwtag  DW_TAG_member
	.dwattr $C$DW$1030, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1030, DW_AT_name("c_16k_64k")
	.dwattr $C$DW$1030, DW_AT_TI_symbol_name("_c_16k_64k")
	.dwattr $C$DW$1030, DW_AT_data_member_location[DW_OP_plus_uconst 0x2c]
	.dwattr $C$DW$1030, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1031	.dwtag  DW_TAG_member
	.dwattr $C$DW$1031, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1031, DW_AT_name("c_64k_256k")
	.dwattr $C$DW$1031, DW_AT_TI_symbol_name("_c_64k_256k")
	.dwattr $C$DW$1031, DW_AT_data_member_location[DW_OP_plus_uconst 0x30]
	.dwattr $C$DW$1031, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1032	.dwtag  DW_TAG_member
	.dwattr $C$DW$1032, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1032, DW_AT_name("c_256k_1m")
	.dwattr $C$DW$1032, DW_AT_TI_symbol_name("_c_256k_1m")
	.dwattr $C$DW$1032, DW_AT_data_member_location[DW_OP_plus_uconst 0x34]
	.dwattr $C$DW$1032, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1033	.dwtag  DW_TAG_member
	.dwattr $C$DW$1033, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1033, DW_AT_name("c_1m_inf")
	.dwattr $C$DW$1033, DW_AT_TI_symbol_name("_c_1m_inf")
	.dwattr $C$DW$1033, DW_AT_data_member_location[DW_OP_plus_uconst 0x38]
	.dwattr $C$DW$1033, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$99	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$99, DW_AT_declaration
	.dwattr $C$DW$99, DW_AT_TI_symbol_name("___as__14s_os_heap_statFRC14s_os_heap_stat")
	.dwattr $C$DW$99, DW_AT_type(*$C$DW$T$222)
	.dwattr $C$DW$99, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1034	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1034, DW_AT_type(*$C$DW$T$224)
	.dwendtag $C$DW$99

	.dwendtag $C$DW$T$226

$C$DW$T$222	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$222, DW_AT_type(*$C$DW$T$226)
	.dwattr $C$DW$T$222, DW_AT_address_class(0x20)

$C$DW$T$225	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$225, DW_AT_type(*$C$DW$T$222)
	.dwattr $C$DW$T$225, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1035	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1035, DW_AT_type(*$C$DW$T$224)
	.dwendtag $C$DW$T$225

$C$DW$T$223	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$223, DW_AT_type(*$C$DW$T$226)
$C$DW$T$224	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$224, DW_AT_type(*$C$DW$T$223)
	.dwattr $C$DW$T$224, DW_AT_address_class(0x20)

$C$DW$T$231	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$231, DW_AT_name("s_os_semaphore")
	.dwattr $C$DW$T$231, DW_AT_byte_size(0x18)
$C$DW$1036	.dwtag  DW_TAG_member
	.dwattr $C$DW$1036, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1036, DW_AT_name("id")
	.dwattr $C$DW$1036, DW_AT_TI_symbol_name("_id")
	.dwattr $C$DW$1036, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1036, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1037	.dwtag  DW_TAG_member
	.dwattr $C$DW$1037, DW_AT_type(*$C$DW$T$80)
	.dwattr $C$DW$1037, DW_AT_name("name")
	.dwattr $C$DW$1037, DW_AT_TI_symbol_name("_name")
	.dwattr $C$DW$1037, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1037, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1038	.dwtag  DW_TAG_member
	.dwattr $C$DW$1038, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$1038, DW_AT_name("v")
	.dwattr $C$DW$1038, DW_AT_TI_symbol_name("_v")
	.dwattr $C$DW$1038, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1038, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1039	.dwtag  DW_TAG_member
	.dwattr $C$DW$1039, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$1039, DW_AT_name("w")
	.dwattr $C$DW$1039, DW_AT_TI_symbol_name("_w")
	.dwattr $C$DW$1039, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$1039, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1040	.dwtag  DW_TAG_member
	.dwattr $C$DW$1040, DW_AT_type(*$C$DW$T$158)
	.dwattr $C$DW$1040, DW_AT_name("first")
	.dwattr $C$DW$1040, DW_AT_TI_symbol_name("_first")
	.dwattr $C$DW$1040, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$1040, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1041	.dwtag  DW_TAG_member
	.dwattr $C$DW$1041, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1041, DW_AT_name("own_process")
	.dwattr $C$DW$1041, DW_AT_TI_symbol_name("_own_process")
	.dwattr $C$DW$1041, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$1041, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$100	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$100, DW_AT_declaration
	.dwattr $C$DW$100, DW_AT_TI_symbol_name("___as__14s_os_semaphoreFRC14s_os_semaphore")
	.dwattr $C$DW$100, DW_AT_type(*$C$DW$T$227)
	.dwattr $C$DW$100, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1042	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1042, DW_AT_type(*$C$DW$T$229)
	.dwendtag $C$DW$100

	.dwendtag $C$DW$T$231

$C$DW$T$227	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$227, DW_AT_type(*$C$DW$T$231)
	.dwattr $C$DW$T$227, DW_AT_address_class(0x20)

$C$DW$T$230	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$230, DW_AT_type(*$C$DW$T$227)
	.dwattr $C$DW$T$230, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1043	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1043, DW_AT_type(*$C$DW$T$229)
	.dwendtag $C$DW$T$230

$C$DW$T$228	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$228, DW_AT_type(*$C$DW$T$231)
$C$DW$T$229	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$229, DW_AT_type(*$C$DW$T$228)
	.dwattr $C$DW$T$229, DW_AT_address_class(0x20)

$C$DW$T$238	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$238, DW_AT_name("s_lif_header")
	.dwattr $C$DW$T$238, DW_AT_byte_size(0x80)
$C$DW$1044	.dwtag  DW_TAG_member
	.dwattr $C$DW$1044, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1044, DW_AT_name("magic")
	.dwattr $C$DW$1044, DW_AT_TI_symbol_name("_magic")
	.dwattr $C$DW$1044, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1044, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1045	.dwtag  DW_TAG_member
	.dwattr $C$DW$1045, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1045, DW_AT_name("type")
	.dwattr $C$DW$1045, DW_AT_TI_symbol_name("_type")
	.dwattr $C$DW$1045, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1045, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1046	.dwtag  DW_TAG_member
	.dwattr $C$DW$1046, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1046, DW_AT_name("target")
	.dwattr $C$DW$1046, DW_AT_TI_symbol_name("_target")
	.dwattr $C$DW$1046, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1046, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1047	.dwtag  DW_TAG_member
	.dwattr $C$DW$1047, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1047, DW_AT_name("length")
	.dwattr $C$DW$1047, DW_AT_TI_symbol_name("_length")
	.dwattr $C$DW$1047, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$1047, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1048	.dwtag  DW_TAG_member
	.dwattr $C$DW$1048, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1048, DW_AT_name("vepoint_offset")
	.dwattr $C$DW$1048, DW_AT_TI_symbol_name("_vepoint_offset")
	.dwattr $C$DW$1048, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$1048, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1049	.dwtag  DW_TAG_member
	.dwattr $C$DW$1049, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1049, DW_AT_name("vepoint_snum")
	.dwattr $C$DW$1049, DW_AT_TI_symbol_name("_vepoint_snum")
	.dwattr $C$DW$1049, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$1049, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1050	.dwtag  DW_TAG_member
	.dwattr $C$DW$1050, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1050, DW_AT_name("version")
	.dwattr $C$DW$1050, DW_AT_TI_symbol_name("_version")
	.dwattr $C$DW$1050, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$1050, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1051	.dwtag  DW_TAG_member
	.dwattr $C$DW$1051, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1051, DW_AT_name("revision")
	.dwattr $C$DW$1051, DW_AT_TI_symbol_name("_revision")
	.dwattr $C$DW$1051, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr $C$DW$1051, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1052	.dwtag  DW_TAG_member
	.dwattr $C$DW$1052, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1052, DW_AT_name("flags")
	.dwattr $C$DW$1052, DW_AT_TI_symbol_name("_flags")
	.dwattr $C$DW$1052, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr $C$DW$1052, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1053	.dwtag  DW_TAG_member
	.dwattr $C$DW$1053, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1053, DW_AT_name("scount")
	.dwattr $C$DW$1053, DW_AT_TI_symbol_name("_scount")
	.dwattr $C$DW$1053, DW_AT_data_member_location[DW_OP_plus_uconst 0x24]
	.dwattr $C$DW$1053, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1054	.dwtag  DW_TAG_member
	.dwattr $C$DW$1054, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1054, DW_AT_name("stack")
	.dwattr $C$DW$1054, DW_AT_TI_symbol_name("_stack")
	.dwattr $C$DW$1054, DW_AT_data_member_location[DW_OP_plus_uconst 0x28]
	.dwattr $C$DW$1054, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1055	.dwtag  DW_TAG_member
	.dwattr $C$DW$1055, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1055, DW_AT_name("symcount")
	.dwattr $C$DW$1055, DW_AT_TI_symbol_name("_symcount")
	.dwattr $C$DW$1055, DW_AT_data_member_location[DW_OP_plus_uconst 0x2c]
	.dwattr $C$DW$1055, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1056	.dwtag  DW_TAG_member
	.dwattr $C$DW$1056, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1056, DW_AT_name("btime")
	.dwattr $C$DW$1056, DW_AT_TI_symbol_name("_btime")
	.dwattr $C$DW$1056, DW_AT_data_member_location[DW_OP_plus_uconst 0x30]
	.dwattr $C$DW$1056, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1057	.dwtag  DW_TAG_member
	.dwattr $C$DW$1057, DW_AT_type(*$C$DW$T$232)
	.dwattr $C$DW$1057, DW_AT_name("reserved")
	.dwattr $C$DW$1057, DW_AT_TI_symbol_name("_reserved")
	.dwattr $C$DW$1057, DW_AT_data_member_location[DW_OP_plus_uconst 0x34]
	.dwattr $C$DW$1057, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1058	.dwtag  DW_TAG_member
	.dwattr $C$DW$1058, DW_AT_type(*$C$DW$T$233)
	.dwattr $C$DW$1058, DW_AT_name("chk")
	.dwattr $C$DW$1058, DW_AT_TI_symbol_name("_chk")
	.dwattr $C$DW$1058, DW_AT_data_member_location[DW_OP_plus_uconst 0x40]
	.dwattr $C$DW$1058, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$101	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$101, DW_AT_declaration
	.dwattr $C$DW$101, DW_AT_TI_symbol_name("___as__12s_lif_headerFRC12s_lif_header")
	.dwattr $C$DW$101, DW_AT_type(*$C$DW$T$234)
	.dwattr $C$DW$101, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1059	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1059, DW_AT_type(*$C$DW$T$236)
	.dwendtag $C$DW$101

	.dwendtag $C$DW$T$238

$C$DW$T$234	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$234, DW_AT_type(*$C$DW$T$238)
	.dwattr $C$DW$T$234, DW_AT_address_class(0x20)

$C$DW$T$237	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$237, DW_AT_type(*$C$DW$T$234)
	.dwattr $C$DW$T$237, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1060	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1060, DW_AT_type(*$C$DW$T$236)
	.dwendtag $C$DW$T$237

$C$DW$T$235	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$235, DW_AT_type(*$C$DW$T$238)
$C$DW$T$236	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$236, DW_AT_type(*$C$DW$T$235)
	.dwattr $C$DW$T$236, DW_AT_address_class(0x20)

$C$DW$T$243	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$243, DW_AT_name("s_lif_section")
	.dwattr $C$DW$T$243, DW_AT_byte_size(0x20)
$C$DW$1061	.dwtag  DW_TAG_member
	.dwattr $C$DW$1061, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1061, DW_AT_name("magic")
	.dwattr $C$DW$1061, DW_AT_TI_symbol_name("_magic")
	.dwattr $C$DW$1061, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1061, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1062	.dwtag  DW_TAG_member
	.dwattr $C$DW$1062, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1062, DW_AT_name("size")
	.dwattr $C$DW$1062, DW_AT_TI_symbol_name("_size")
	.dwattr $C$DW$1062, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1062, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1063	.dwtag  DW_TAG_member
	.dwattr $C$DW$1063, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1063, DW_AT_name("length")
	.dwattr $C$DW$1063, DW_AT_TI_symbol_name("_length")
	.dwattr $C$DW$1063, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1063, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1064	.dwtag  DW_TAG_member
	.dwattr $C$DW$1064, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1064, DW_AT_name("vaddr")
	.dwattr $C$DW$1064, DW_AT_TI_symbol_name("_vaddr")
	.dwattr $C$DW$1064, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$1064, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1065	.dwtag  DW_TAG_member
	.dwattr $C$DW$1065, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1065, DW_AT_name("paddr")
	.dwattr $C$DW$1065, DW_AT_TI_symbol_name("_paddr")
	.dwattr $C$DW$1065, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$1065, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1066	.dwtag  DW_TAG_member
	.dwattr $C$DW$1066, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1066, DW_AT_name("pcount")
	.dwattr $C$DW$1066, DW_AT_TI_symbol_name("_pcount")
	.dwattr $C$DW$1066, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$1066, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1067	.dwtag  DW_TAG_member
	.dwattr $C$DW$1067, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1067, DW_AT_name("flags")
	.dwattr $C$DW$1067, DW_AT_TI_symbol_name("_flags")
	.dwattr $C$DW$1067, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$1067, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1068	.dwtag  DW_TAG_member
	.dwattr $C$DW$1068, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1068, DW_AT_name("reserved")
	.dwattr $C$DW$1068, DW_AT_TI_symbol_name("_reserved")
	.dwattr $C$DW$1068, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr $C$DW$1068, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$102	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$102, DW_AT_declaration
	.dwattr $C$DW$102, DW_AT_TI_symbol_name("___as__13s_lif_sectionFRC13s_lif_section")
	.dwattr $C$DW$102, DW_AT_type(*$C$DW$T$239)
	.dwattr $C$DW$102, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1069	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1069, DW_AT_type(*$C$DW$T$241)
	.dwendtag $C$DW$102

	.dwendtag $C$DW$T$243

$C$DW$T$239	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$239, DW_AT_type(*$C$DW$T$243)
	.dwattr $C$DW$T$239, DW_AT_address_class(0x20)

$C$DW$T$242	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$242, DW_AT_type(*$C$DW$T$239)
	.dwattr $C$DW$T$242, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1070	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1070, DW_AT_type(*$C$DW$T$241)
	.dwendtag $C$DW$T$242

$C$DW$T$240	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$240, DW_AT_type(*$C$DW$T$243)
$C$DW$T$241	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$241, DW_AT_type(*$C$DW$T$240)
	.dwattr $C$DW$T$241, DW_AT_address_class(0x20)

$C$DW$T$248	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$248, DW_AT_name("s_lif_patch")
	.dwattr $C$DW$T$248, DW_AT_byte_size(0x14)
$C$DW$1071	.dwtag  DW_TAG_member
	.dwattr $C$DW$1071, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1071, DW_AT_name("method")
	.dwattr $C$DW$1071, DW_AT_TI_symbol_name("_method")
	.dwattr $C$DW$1071, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1071, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1072	.dwtag  DW_TAG_member
	.dwattr $C$DW$1072, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1072, DW_AT_name("offset")
	.dwattr $C$DW$1072, DW_AT_TI_symbol_name("_offset")
	.dwattr $C$DW$1072, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1072, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1073	.dwtag  DW_TAG_member
	.dwattr $C$DW$1073, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1073, DW_AT_name("v")
	.dwattr $C$DW$1073, DW_AT_TI_symbol_name("_v")
	.dwattr $C$DW$1073, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1073, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1074	.dwtag  DW_TAG_member
	.dwattr $C$DW$1074, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1074, DW_AT_name("a")
	.dwattr $C$DW$1074, DW_AT_TI_symbol_name("_a")
	.dwattr $C$DW$1074, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$1074, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1075	.dwtag  DW_TAG_member
	.dwattr $C$DW$1075, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1075, DW_AT_name("b")
	.dwattr $C$DW$1075, DW_AT_TI_symbol_name("_b")
	.dwattr $C$DW$1075, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$1075, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$103	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$103, DW_AT_declaration
	.dwattr $C$DW$103, DW_AT_TI_symbol_name("___as__11s_lif_patchFRC11s_lif_patch")
	.dwattr $C$DW$103, DW_AT_type(*$C$DW$T$244)
	.dwattr $C$DW$103, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1076	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1076, DW_AT_type(*$C$DW$T$246)
	.dwendtag $C$DW$103

	.dwendtag $C$DW$T$248

$C$DW$T$244	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$244, DW_AT_type(*$C$DW$T$248)
	.dwattr $C$DW$T$244, DW_AT_address_class(0x20)

$C$DW$T$247	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$247, DW_AT_type(*$C$DW$T$244)
	.dwattr $C$DW$T$247, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1077	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1077, DW_AT_type(*$C$DW$T$246)
	.dwendtag $C$DW$T$247

$C$DW$T$245	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$245, DW_AT_type(*$C$DW$T$248)
$C$DW$T$246	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$246, DW_AT_type(*$C$DW$T$245)
	.dwattr $C$DW$T$246, DW_AT_address_class(0x20)

$C$DW$T$253	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$253, DW_AT_name("s_lif_symbol")
	.dwattr $C$DW$T$253, DW_AT_byte_size(0x08)
$C$DW$1078	.dwtag  DW_TAG_member
	.dwattr $C$DW$1078, DW_AT_type(*$C$DW$T$80)
	.dwattr $C$DW$1078, DW_AT_name("name")
	.dwattr $C$DW$1078, DW_AT_TI_symbol_name("_name")
	.dwattr $C$DW$1078, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1078, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1079	.dwtag  DW_TAG_member
	.dwattr $C$DW$1079, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1079, DW_AT_name("address")
	.dwattr $C$DW$1079, DW_AT_TI_symbol_name("_address")
	.dwattr $C$DW$1079, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1079, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$104	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$104, DW_AT_declaration
	.dwattr $C$DW$104, DW_AT_TI_symbol_name("___as__12s_lif_symbolFRC12s_lif_symbol")
	.dwattr $C$DW$104, DW_AT_type(*$C$DW$T$249)
	.dwattr $C$DW$104, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1080	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1080, DW_AT_type(*$C$DW$T$251)
	.dwendtag $C$DW$104

	.dwendtag $C$DW$T$253

$C$DW$T$249	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$249, DW_AT_type(*$C$DW$T$253)
	.dwattr $C$DW$T$249, DW_AT_address_class(0x20)

$C$DW$T$252	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$252, DW_AT_type(*$C$DW$T$249)
	.dwattr $C$DW$T$252, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1081	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1081, DW_AT_type(*$C$DW$T$251)
	.dwendtag $C$DW$T$252

$C$DW$T$250	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$250, DW_AT_type(*$C$DW$T$253)
$C$DW$T$251	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$251, DW_AT_type(*$C$DW$T$250)
	.dwattr $C$DW$T$251, DW_AT_address_class(0x20)
$C$DW$T$254	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$254, DW_AT_type(*$C$DW$T$253)
	.dwattr $C$DW$T$254, DW_AT_address_class(0x20)

$C$DW$T$260	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$260, DW_AT_name("s_lif_overlay")
	.dwattr $C$DW$T$260, DW_AT_byte_size(0x1c)
$C$DW$1082	.dwtag  DW_TAG_member
	.dwattr $C$DW$1082, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1082, DW_AT_name("entry_point")
	.dwattr $C$DW$1082, DW_AT_TI_symbol_name("_entry_point")
	.dwattr $C$DW$1082, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1082, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1083	.dwtag  DW_TAG_member
	.dwattr $C$DW$1083, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1083, DW_AT_name("bss_point")
	.dwattr $C$DW$1083, DW_AT_TI_symbol_name("_bss_point")
	.dwattr $C$DW$1083, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1083, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1084	.dwtag  DW_TAG_member
	.dwattr $C$DW$1084, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1084, DW_AT_name("stack_size")
	.dwattr $C$DW$1084, DW_AT_TI_symbol_name("_stack_size")
	.dwattr $C$DW$1084, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1084, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1085	.dwtag  DW_TAG_member
	.dwattr $C$DW$1085, DW_AT_type(*$C$DW$T$254)
	.dwattr $C$DW$1085, DW_AT_name("symbol")
	.dwattr $C$DW$1085, DW_AT_TI_symbol_name("_symbol")
	.dwattr $C$DW$1085, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$1085, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1086	.dwtag  DW_TAG_member
	.dwattr $C$DW$1086, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1086, DW_AT_name("symbol_count")
	.dwattr $C$DW$1086, DW_AT_TI_symbol_name("_symbol_count")
	.dwattr $C$DW$1086, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$1086, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1087	.dwtag  DW_TAG_member
	.dwattr $C$DW$1087, DW_AT_type(*$C$DW$T$255)
	.dwattr $C$DW$1087, DW_AT_name("page")
	.dwattr $C$DW$1087, DW_AT_TI_symbol_name("_page")
	.dwattr $C$DW$1087, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$1087, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1088	.dwtag  DW_TAG_member
	.dwattr $C$DW$1088, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1088, DW_AT_name("page_count")
	.dwattr $C$DW$1088, DW_AT_TI_symbol_name("_page_count")
	.dwattr $C$DW$1088, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$1088, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$105	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$105, DW_AT_declaration
	.dwattr $C$DW$105, DW_AT_TI_symbol_name("___as__13s_lif_overlayFRC13s_lif_overlay")
	.dwattr $C$DW$105, DW_AT_type(*$C$DW$T$256)
	.dwattr $C$DW$105, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1089	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1089, DW_AT_type(*$C$DW$T$258)
	.dwendtag $C$DW$105

	.dwendtag $C$DW$T$260

$C$DW$T$256	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$256, DW_AT_type(*$C$DW$T$260)
	.dwattr $C$DW$T$256, DW_AT_address_class(0x20)

$C$DW$T$259	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$259, DW_AT_type(*$C$DW$T$256)
	.dwattr $C$DW$T$259, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1090	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1090, DW_AT_type(*$C$DW$T$258)
	.dwendtag $C$DW$T$259

$C$DW$T$257	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$257, DW_AT_type(*$C$DW$T$260)
$C$DW$T$258	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$258, DW_AT_type(*$C$DW$T$257)
	.dwattr $C$DW$T$258, DW_AT_address_class(0x20)

$C$DW$T$265	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$265, DW_AT_name("s_os_interrupt")
	.dwattr $C$DW$T$265, DW_AT_byte_size(0x10)
$C$DW$1091	.dwtag  DW_TAG_member
	.dwattr $C$DW$1091, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1091, DW_AT_name("id")
	.dwattr $C$DW$1091, DW_AT_TI_symbol_name("_id")
	.dwattr $C$DW$1091, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1091, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1092	.dwtag  DW_TAG_member
	.dwattr $C$DW$1092, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1092, DW_AT_name("vector")
	.dwattr $C$DW$1092, DW_AT_TI_symbol_name("_vector")
	.dwattr $C$DW$1092, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1092, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1093	.dwtag  DW_TAG_member
	.dwattr $C$DW$1093, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1093, DW_AT_name("source")
	.dwattr $C$DW$1093, DW_AT_TI_symbol_name("_source")
	.dwattr $C$DW$1093, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1093, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1094	.dwtag  DW_TAG_member
	.dwattr $C$DW$1094, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1094, DW_AT_name("own_process")
	.dwattr $C$DW$1094, DW_AT_TI_symbol_name("_own_process")
	.dwattr $C$DW$1094, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$1094, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$106	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$106, DW_AT_declaration
	.dwattr $C$DW$106, DW_AT_TI_symbol_name("___as__14s_os_interruptFRC14s_os_interrupt")
	.dwattr $C$DW$106, DW_AT_type(*$C$DW$T$261)
	.dwattr $C$DW$106, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1095	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1095, DW_AT_type(*$C$DW$T$263)
	.dwendtag $C$DW$106

	.dwendtag $C$DW$T$265

$C$DW$T$261	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$261, DW_AT_type(*$C$DW$T$265)
	.dwattr $C$DW$T$261, DW_AT_address_class(0x20)

$C$DW$T$264	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$264, DW_AT_type(*$C$DW$T$261)
	.dwattr $C$DW$T$264, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1096	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1096, DW_AT_type(*$C$DW$T$263)
	.dwendtag $C$DW$T$264

$C$DW$T$262	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$262, DW_AT_type(*$C$DW$T$265)
$C$DW$T$263	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$263, DW_AT_type(*$C$DW$T$262)
	.dwattr $C$DW$T$263, DW_AT_address_class(0x20)

$C$DW$T$271	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$271, DW_AT_name("s_os_console")
	.dwattr $C$DW$T$271, DW_AT_byte_size(0x0c)
$C$DW$1097	.dwtag  DW_TAG_member
	.dwattr $C$DW$1097, DW_AT_type(*$C$DW$T$266)
	.dwattr $C$DW$1097, DW_AT_name("next")
	.dwattr $C$DW$1097, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$1097, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1097, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1098	.dwtag  DW_TAG_member
	.dwattr $C$DW$1098, DW_AT_type(*$C$DW$T$266)
	.dwattr $C$DW$1098, DW_AT_name("prev")
	.dwattr $C$DW$1098, DW_AT_TI_symbol_name("_prev")
	.dwattr $C$DW$1098, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1098, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1099	.dwtag  DW_TAG_member
	.dwattr $C$DW$1099, DW_AT_type(*$C$DW$T$80)
	.dwattr $C$DW$1099, DW_AT_name("path")
	.dwattr $C$DW$1099, DW_AT_TI_symbol_name("_path")
	.dwattr $C$DW$1099, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1099, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$107	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$107, DW_AT_declaration
	.dwattr $C$DW$107, DW_AT_TI_symbol_name("___as__12s_os_consoleFRC12s_os_console")
	.dwattr $C$DW$107, DW_AT_type(*$C$DW$T$267)
	.dwattr $C$DW$107, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1100	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1100, DW_AT_type(*$C$DW$T$269)
	.dwendtag $C$DW$107

	.dwendtag $C$DW$T$271

$C$DW$T$266	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$266, DW_AT_type(*$C$DW$T$271)
	.dwattr $C$DW$T$266, DW_AT_address_class(0x20)
$C$DW$T$267	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$267, DW_AT_type(*$C$DW$T$271)
	.dwattr $C$DW$T$267, DW_AT_address_class(0x20)

$C$DW$T$270	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$270, DW_AT_type(*$C$DW$T$267)
	.dwattr $C$DW$T$270, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1101	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1101, DW_AT_type(*$C$DW$T$269)
	.dwendtag $C$DW$T$270

$C$DW$T$268	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$268, DW_AT_type(*$C$DW$T$271)
$C$DW$T$269	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$269, DW_AT_type(*$C$DW$T$268)
	.dwattr $C$DW$T$269, DW_AT_address_class(0x20)

$C$DW$T$277	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$277, DW_AT_name("s_os_iodevice")
	.dwattr $C$DW$T$277, DW_AT_byte_size(0x14)
$C$DW$1102	.dwtag  DW_TAG_member
	.dwattr $C$DW$1102, DW_AT_type(*$C$DW$T$272)
	.dwattr $C$DW$1102, DW_AT_name("next")
	.dwattr $C$DW$1102, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$1102, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1102, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1103	.dwtag  DW_TAG_member
	.dwattr $C$DW$1103, DW_AT_type(*$C$DW$T$272)
	.dwattr $C$DW$1103, DW_AT_name("prev")
	.dwattr $C$DW$1103, DW_AT_TI_symbol_name("_prev")
	.dwattr $C$DW$1103, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1103, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1104	.dwtag  DW_TAG_member
	.dwattr $C$DW$1104, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1104, DW_AT_name("con_count")
	.dwattr $C$DW$1104, DW_AT_TI_symbol_name("_con_count")
	.dwattr $C$DW$1104, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1104, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1105	.dwtag  DW_TAG_member
	.dwattr $C$DW$1105, DW_AT_type(*$C$DW$T$266)
	.dwattr $C$DW$1105, DW_AT_name("active")
	.dwattr $C$DW$1105, DW_AT_TI_symbol_name("_active")
	.dwattr $C$DW$1105, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$1105, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1106	.dwtag  DW_TAG_member
	.dwattr $C$DW$1106, DW_AT_type(*$C$DW$T$80)
	.dwattr $C$DW$1106, DW_AT_name("path")
	.dwattr $C$DW$1106, DW_AT_TI_symbol_name("_path")
	.dwattr $C$DW$1106, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$1106, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$108	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$108, DW_AT_declaration
	.dwattr $C$DW$108, DW_AT_TI_symbol_name("___as__13s_os_iodeviceFRC13s_os_iodevice")
	.dwattr $C$DW$108, DW_AT_type(*$C$DW$T$273)
	.dwattr $C$DW$108, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1107	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1107, DW_AT_type(*$C$DW$T$275)
	.dwendtag $C$DW$108

	.dwendtag $C$DW$T$277

$C$DW$T$272	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$272, DW_AT_type(*$C$DW$T$277)
	.dwattr $C$DW$T$272, DW_AT_address_class(0x20)
$C$DW$T$273	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$273, DW_AT_type(*$C$DW$T$277)
	.dwattr $C$DW$T$273, DW_AT_address_class(0x20)

$C$DW$T$276	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$276, DW_AT_type(*$C$DW$T$273)
	.dwattr $C$DW$T$276, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1108	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1108, DW_AT_type(*$C$DW$T$275)
	.dwendtag $C$DW$T$276

$C$DW$T$274	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$274, DW_AT_type(*$C$DW$T$277)
$C$DW$T$275	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$275, DW_AT_type(*$C$DW$T$274)
	.dwattr $C$DW$T$275, DW_AT_address_class(0x20)

$C$DW$T$282	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$282, DW_AT_name("EDMA_Config")
	.dwattr $C$DW$T$282, DW_AT_byte_size(0x18)
$C$DW$1109	.dwtag  DW_TAG_member
	.dwattr $C$DW$1109, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1109, DW_AT_name("opt")
	.dwattr $C$DW$1109, DW_AT_TI_symbol_name("_opt")
	.dwattr $C$DW$1109, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1109, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1110	.dwtag  DW_TAG_member
	.dwattr $C$DW$1110, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1110, DW_AT_name("src")
	.dwattr $C$DW$1110, DW_AT_TI_symbol_name("_src")
	.dwattr $C$DW$1110, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1110, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1111	.dwtag  DW_TAG_member
	.dwattr $C$DW$1111, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1111, DW_AT_name("cnt")
	.dwattr $C$DW$1111, DW_AT_TI_symbol_name("_cnt")
	.dwattr $C$DW$1111, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1111, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1112	.dwtag  DW_TAG_member
	.dwattr $C$DW$1112, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1112, DW_AT_name("dst")
	.dwattr $C$DW$1112, DW_AT_TI_symbol_name("_dst")
	.dwattr $C$DW$1112, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$1112, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1113	.dwtag  DW_TAG_member
	.dwattr $C$DW$1113, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1113, DW_AT_name("idx")
	.dwattr $C$DW$1113, DW_AT_TI_symbol_name("_idx")
	.dwattr $C$DW$1113, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$1113, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1114	.dwtag  DW_TAG_member
	.dwattr $C$DW$1114, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1114, DW_AT_name("rld")
	.dwattr $C$DW$1114, DW_AT_TI_symbol_name("_rld")
	.dwattr $C$DW$1114, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$1114, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$109	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$109, DW_AT_declaration
	.dwattr $C$DW$109, DW_AT_TI_symbol_name("___as__11EDMA_ConfigFRC11EDMA_Config")
	.dwattr $C$DW$109, DW_AT_type(*$C$DW$T$278)
	.dwattr $C$DW$109, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1115	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1115, DW_AT_type(*$C$DW$T$280)
	.dwendtag $C$DW$109

	.dwendtag $C$DW$T$282

$C$DW$T$278	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$278, DW_AT_type(*$C$DW$T$282)
	.dwattr $C$DW$T$278, DW_AT_address_class(0x20)

$C$DW$T$281	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$281, DW_AT_type(*$C$DW$T$278)
	.dwattr $C$DW$T$281, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1116	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1116, DW_AT_type(*$C$DW$T$280)
	.dwendtag $C$DW$T$281

$C$DW$T$279	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$279, DW_AT_type(*$C$DW$T$282)
$C$DW$T$280	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$280, DW_AT_type(*$C$DW$T$279)
	.dwattr $C$DW$T$280, DW_AT_address_class(0x20)
$C$DW$T$761	.dwtag  DW_TAG_typedef, DW_AT_name("EDMA_Config")
	.dwattr $C$DW$T$761, DW_AT_type(*$C$DW$T$282)
	.dwattr $C$DW$T$761, DW_AT_language(DW_LANG_C_plus_plus)

$C$DW$T$287	.dwtag  DW_TAG_class_type
	.dwattr $C$DW$T$287, DW_AT_name("bad_alloc")
	.dwattr $C$DW$T$287, DW_AT_byte_size(0x01)

$C$DW$110	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$110, DW_AT_declaration
	.dwattr $C$DW$110, DW_AT_TI_symbol_name("___as__Q2_3std9bad_allocFRCQ2_3std9bad_alloc")
	.dwattr $C$DW$110, DW_AT_type(*$C$DW$T$283)
	.dwattr $C$DW$110, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1117	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1117, DW_AT_type(*$C$DW$T$285)
	.dwendtag $C$DW$110

	.dwendtag $C$DW$T$287

$C$DW$T$283	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$283, DW_AT_type(*$C$DW$T$287)
	.dwattr $C$DW$T$283, DW_AT_address_class(0x20)

$C$DW$T$286	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$286, DW_AT_type(*$C$DW$T$283)
	.dwattr $C$DW$T$286, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1118	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1118, DW_AT_type(*$C$DW$T$285)
	.dwendtag $C$DW$T$286

$C$DW$T$284	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$284, DW_AT_type(*$C$DW$T$287)
$C$DW$T$285	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$285, DW_AT_type(*$C$DW$T$284)
	.dwattr $C$DW$T$285, DW_AT_address_class(0x20)

$C$DW$T$293	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$293, DW_AT_name("FILE")
	.dwattr $C$DW$T$293, DW_AT_byte_size(0x18)
$C$DW$1119	.dwtag  DW_TAG_member
	.dwattr $C$DW$1119, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1119, DW_AT_name("rid")
	.dwattr $C$DW$1119, DW_AT_TI_symbol_name("_rid")
	.dwattr $C$DW$1119, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1119, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1120	.dwtag  DW_TAG_member
	.dwattr $C$DW$1120, DW_AT_type(*$C$DW$T$288)
	.dwattr $C$DW$1120, DW_AT_name("ungetc_buf")
	.dwattr $C$DW$1120, DW_AT_TI_symbol_name("_ungetc_buf")
	.dwattr $C$DW$1120, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1120, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1121	.dwtag  DW_TAG_member
	.dwattr $C$DW$1121, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$1121, DW_AT_name("ungetc_count")
	.dwattr $C$DW$1121, DW_AT_TI_symbol_name("_ungetc_count")
	.dwattr $C$DW$1121, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$1121, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$111	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$111, DW_AT_declaration
	.dwattr $C$DW$111, DW_AT_TI_symbol_name("___as__4FILEFRC4FILE")
	.dwattr $C$DW$111, DW_AT_type(*$C$DW$T$289)
	.dwattr $C$DW$111, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1122	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1122, DW_AT_type(*$C$DW$T$291)
	.dwendtag $C$DW$111

	.dwendtag $C$DW$T$293

$C$DW$T$289	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$289, DW_AT_type(*$C$DW$T$293)
	.dwattr $C$DW$T$289, DW_AT_address_class(0x20)

$C$DW$T$292	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$292, DW_AT_type(*$C$DW$T$289)
	.dwattr $C$DW$T$292, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1123	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1123, DW_AT_type(*$C$DW$T$291)
	.dwendtag $C$DW$T$292

$C$DW$T$290	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$290, DW_AT_type(*$C$DW$T$293)
$C$DW$T$291	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$291, DW_AT_type(*$C$DW$T$290)
	.dwattr $C$DW$T$291, DW_AT_address_class(0x20)
$C$DW$T$294	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$294, DW_AT_type(*$C$DW$T$293)
	.dwattr $C$DW$T$294, DW_AT_address_class(0x20)

$C$DW$T$299	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$299, DW_AT_name("BIT_FILE")
	.dwattr $C$DW$T$299, DW_AT_byte_size(0x0c)
$C$DW$1124	.dwtag  DW_TAG_member
	.dwattr $C$DW$1124, DW_AT_type(*$C$DW$T$294)
	.dwattr $C$DW$1124, DW_AT_name("f")
	.dwattr $C$DW$1124, DW_AT_TI_symbol_name("_f")
	.dwattr $C$DW$1124, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1124, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1125	.dwtag  DW_TAG_member
	.dwattr $C$DW$1125, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$1125, DW_AT_name("bpos")
	.dwattr $C$DW$1125, DW_AT_TI_symbol_name("_bpos")
	.dwattr $C$DW$1125, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1125, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1126	.dwtag  DW_TAG_member
	.dwattr $C$DW$1126, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$1126, DW_AT_name("b")
	.dwattr $C$DW$1126, DW_AT_TI_symbol_name("_b")
	.dwattr $C$DW$1126, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1126, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1127	.dwtag  DW_TAG_member
	.dwattr $C$DW$1127, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$1127, DW_AT_name("mode")
	.dwattr $C$DW$1127, DW_AT_TI_symbol_name("_mode")
	.dwattr $C$DW$1127, DW_AT_data_member_location[DW_OP_plus_uconst 0x9]
	.dwattr $C$DW$1127, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$112	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$112, DW_AT_declaration
	.dwattr $C$DW$112, DW_AT_TI_symbol_name("___as__8BIT_FILEFRC8BIT_FILE")
	.dwattr $C$DW$112, DW_AT_type(*$C$DW$T$295)
	.dwattr $C$DW$112, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1128	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1128, DW_AT_type(*$C$DW$T$297)
	.dwendtag $C$DW$112

	.dwendtag $C$DW$T$299

$C$DW$T$295	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$295, DW_AT_type(*$C$DW$T$299)
	.dwattr $C$DW$T$295, DW_AT_address_class(0x20)

$C$DW$T$298	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$298, DW_AT_type(*$C$DW$T$295)
	.dwattr $C$DW$T$298, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1129	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1129, DW_AT_type(*$C$DW$T$297)
	.dwendtag $C$DW$T$298

$C$DW$T$296	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$296, DW_AT_type(*$C$DW$T$299)
$C$DW$T$297	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$297, DW_AT_type(*$C$DW$T$296)
	.dwattr $C$DW$T$297, DW_AT_address_class(0x20)
$C$DW$T$300	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$300, DW_AT_type(*$C$DW$T$299)
	.dwattr $C$DW$T$300, DW_AT_address_class(0x20)

$C$DW$T$307	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$307, DW_AT_name("WLPK_FILE")
	.dwattr $C$DW$T$307, DW_AT_byte_size(0x430)
$C$DW$1130	.dwtag  DW_TAG_member
	.dwattr $C$DW$1130, DW_AT_type(*$C$DW$T$300)
	.dwattr $C$DW$1130, DW_AT_name("f")
	.dwattr $C$DW$1130, DW_AT_TI_symbol_name("_f")
	.dwattr $C$DW$1130, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1130, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1131	.dwtag  DW_TAG_member
	.dwattr $C$DW$1131, DW_AT_type(*$C$DW$T$301)
	.dwattr $C$DW$1131, DW_AT_name("w")
	.dwattr $C$DW$1131, DW_AT_TI_symbol_name("_w")
	.dwattr $C$DW$1131, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1131, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1132	.dwtag  DW_TAG_member
	.dwattr $C$DW$1132, DW_AT_type(*$C$DW$T$302)
	.dwattr $C$DW$1132, DW_AT_name("b")
	.dwattr $C$DW$1132, DW_AT_TI_symbol_name("_b")
	.dwattr $C$DW$1132, DW_AT_data_member_location[DW_OP_plus_uconst 0x404]
	.dwattr $C$DW$1132, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1133	.dwtag  DW_TAG_member
	.dwattr $C$DW$1133, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$1133, DW_AT_name("wpos")
	.dwattr $C$DW$1133, DW_AT_TI_symbol_name("_wpos")
	.dwattr $C$DW$1133, DW_AT_data_member_location[DW_OP_plus_uconst 0x424]
	.dwattr $C$DW$1133, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1134	.dwtag  DW_TAG_member
	.dwattr $C$DW$1134, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$1134, DW_AT_name("blen")
	.dwattr $C$DW$1134, DW_AT_TI_symbol_name("_blen")
	.dwattr $C$DW$1134, DW_AT_data_member_location[DW_OP_plus_uconst 0x428]
	.dwattr $C$DW$1134, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1135	.dwtag  DW_TAG_member
	.dwattr $C$DW$1135, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$1135, DW_AT_name("mode")
	.dwattr $C$DW$1135, DW_AT_TI_symbol_name("_mode")
	.dwattr $C$DW$1135, DW_AT_data_member_location[DW_OP_plus_uconst 0x42c]
	.dwattr $C$DW$1135, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$113	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$113, DW_AT_declaration
	.dwattr $C$DW$113, DW_AT_TI_symbol_name("___as__9WLPK_FILEFRC9WLPK_FILE")
	.dwattr $C$DW$113, DW_AT_type(*$C$DW$T$303)
	.dwattr $C$DW$113, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1136	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1136, DW_AT_type(*$C$DW$T$305)
	.dwendtag $C$DW$113

	.dwendtag $C$DW$T$307

$C$DW$T$303	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$303, DW_AT_type(*$C$DW$T$307)
	.dwattr $C$DW$T$303, DW_AT_address_class(0x20)

$C$DW$T$306	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$306, DW_AT_type(*$C$DW$T$303)
	.dwattr $C$DW$T$306, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1137	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1137, DW_AT_type(*$C$DW$T$305)
	.dwendtag $C$DW$T$306

$C$DW$T$304	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$304, DW_AT_type(*$C$DW$T$307)
$C$DW$T$305	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$305, DW_AT_type(*$C$DW$T$304)
	.dwattr $C$DW$T$305, DW_AT_address_class(0x20)

$C$DW$T$313	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$313, DW_AT_name("dirent")
	.dwattr $C$DW$T$313, DW_AT_byte_size(0x110)
$C$DW$1138	.dwtag  DW_TAG_member
	.dwattr $C$DW$1138, DW_AT_type(*$C$DW$T$308)
	.dwattr $C$DW$1138, DW_AT_name("d_name")
	.dwattr $C$DW$1138, DW_AT_TI_symbol_name("_d_name")
	.dwattr $C$DW$1138, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1138, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1139	.dwtag  DW_TAG_member
	.dwattr $C$DW$1139, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$1139, DW_AT_name("d_type")
	.dwattr $C$DW$1139, DW_AT_TI_symbol_name("_d_type")
	.dwattr $C$DW$1139, DW_AT_data_member_location[DW_OP_plus_uconst 0x100]
	.dwattr $C$DW$1139, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1140	.dwtag  DW_TAG_member
	.dwattr $C$DW$1140, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$1140, DW_AT_name("d_size")
	.dwattr $C$DW$1140, DW_AT_TI_symbol_name("_d_size")
	.dwattr $C$DW$1140, DW_AT_data_member_location[DW_OP_plus_uconst 0x108]
	.dwattr $C$DW$1140, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$114	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$114, DW_AT_declaration
	.dwattr $C$DW$114, DW_AT_TI_symbol_name("___as__6direntFRC6dirent")
	.dwattr $C$DW$114, DW_AT_type(*$C$DW$T$309)
	.dwattr $C$DW$114, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1141	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1141, DW_AT_type(*$C$DW$T$311)
	.dwendtag $C$DW$114

	.dwendtag $C$DW$T$313

$C$DW$T$309	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$309, DW_AT_type(*$C$DW$T$313)
	.dwattr $C$DW$T$309, DW_AT_address_class(0x20)

$C$DW$T$312	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$312, DW_AT_type(*$C$DW$T$309)
	.dwattr $C$DW$T$312, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1142	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1142, DW_AT_type(*$C$DW$T$311)
	.dwendtag $C$DW$T$312

$C$DW$T$310	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$310, DW_AT_type(*$C$DW$T$313)
$C$DW$T$311	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$311, DW_AT_type(*$C$DW$T$310)
	.dwattr $C$DW$T$311, DW_AT_address_class(0x20)

$C$DW$T$318	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$318, DW_AT_name("DIR")
	.dwattr $C$DW$T$318, DW_AT_byte_size(0x120)
$C$DW$1143	.dwtag  DW_TAG_member
	.dwattr $C$DW$1143, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1143, DW_AT_name("rid")
	.dwattr $C$DW$1143, DW_AT_TI_symbol_name("_rid")
	.dwattr $C$DW$1143, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1143, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1144	.dwtag  DW_TAG_member
	.dwattr $C$DW$1144, DW_AT_type(*$C$DW$T$313)
	.dwattr $C$DW$1144, DW_AT_name("d_rec")
	.dwattr $C$DW$1144, DW_AT_TI_symbol_name("_d_rec")
	.dwattr $C$DW$1144, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1144, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1145	.dwtag  DW_TAG_member
	.dwattr $C$DW$1145, DW_AT_type(*$C$DW$T$104)
	.dwattr $C$DW$1145, DW_AT_name("d_list")
	.dwattr $C$DW$1145, DW_AT_TI_symbol_name("_d_list")
	.dwattr $C$DW$1145, DW_AT_data_member_location[DW_OP_plus_uconst 0x118]
	.dwattr $C$DW$1145, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1146	.dwtag  DW_TAG_member
	.dwattr $C$DW$1146, DW_AT_type(*$C$DW$T$104)
	.dwattr $C$DW$1146, DW_AT_name("d_cnode")
	.dwattr $C$DW$1146, DW_AT_TI_symbol_name("_d_cnode")
	.dwattr $C$DW$1146, DW_AT_data_member_location[DW_OP_plus_uconst 0x11c]
	.dwattr $C$DW$1146, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$115	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$115, DW_AT_declaration
	.dwattr $C$DW$115, DW_AT_TI_symbol_name("___as__3DIRFRC3DIR")
	.dwattr $C$DW$115, DW_AT_type(*$C$DW$T$314)
	.dwattr $C$DW$115, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1147	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1147, DW_AT_type(*$C$DW$T$316)
	.dwendtag $C$DW$115

	.dwendtag $C$DW$T$318

$C$DW$T$314	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$314, DW_AT_type(*$C$DW$T$318)
	.dwattr $C$DW$T$314, DW_AT_address_class(0x20)

$C$DW$T$317	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$317, DW_AT_type(*$C$DW$T$314)
	.dwattr $C$DW$T$317, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1148	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1148, DW_AT_type(*$C$DW$T$316)
	.dwendtag $C$DW$T$317

$C$DW$T$315	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$315, DW_AT_type(*$C$DW$T$318)
$C$DW$T$316	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$316, DW_AT_type(*$C$DW$T$315)
	.dwattr $C$DW$T$316, DW_AT_address_class(0x20)

$C$DW$T$323	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$323, DW_AT_name("sem_t")
	.dwattr $C$DW$T$323, DW_AT_byte_size(0x08)
$C$DW$1149	.dwtag  DW_TAG_member
	.dwattr $C$DW$1149, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1149, DW_AT_name("rid")
	.dwattr $C$DW$1149, DW_AT_TI_symbol_name("_rid")
	.dwattr $C$DW$1149, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1149, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1150	.dwtag  DW_TAG_member
	.dwattr $C$DW$1150, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$1150, DW_AT_name("nauna")
	.dwattr $C$DW$1150, DW_AT_TI_symbol_name("_nauna")
	.dwattr $C$DW$1150, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1150, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$116	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$116, DW_AT_declaration
	.dwattr $C$DW$116, DW_AT_TI_symbol_name("___as__5sem_tFRC5sem_t")
	.dwattr $C$DW$116, DW_AT_type(*$C$DW$T$319)
	.dwattr $C$DW$116, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1151	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1151, DW_AT_type(*$C$DW$T$321)
	.dwendtag $C$DW$116

	.dwendtag $C$DW$T$323

$C$DW$T$319	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$319, DW_AT_type(*$C$DW$T$323)
	.dwattr $C$DW$T$319, DW_AT_address_class(0x20)

$C$DW$T$322	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$322, DW_AT_type(*$C$DW$T$319)
	.dwattr $C$DW$T$322, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1152	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1152, DW_AT_type(*$C$DW$T$321)
	.dwendtag $C$DW$T$322

$C$DW$T$320	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$320, DW_AT_type(*$C$DW$T$323)
$C$DW$T$321	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$321, DW_AT_type(*$C$DW$T$320)
	.dwattr $C$DW$T$321, DW_AT_address_class(0x20)

$C$DW$T$328	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$328, DW_AT_name("tm")
	.dwattr $C$DW$T$328, DW_AT_byte_size(0x24)
$C$DW$1153	.dwtag  DW_TAG_member
	.dwattr $C$DW$1153, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$1153, DW_AT_name("tm_sec")
	.dwattr $C$DW$1153, DW_AT_TI_symbol_name("_tm_sec")
	.dwattr $C$DW$1153, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1153, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1154	.dwtag  DW_TAG_member
	.dwattr $C$DW$1154, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$1154, DW_AT_name("tm_min")
	.dwattr $C$DW$1154, DW_AT_TI_symbol_name("_tm_min")
	.dwattr $C$DW$1154, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1154, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1155	.dwtag  DW_TAG_member
	.dwattr $C$DW$1155, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$1155, DW_AT_name("tm_hour")
	.dwattr $C$DW$1155, DW_AT_TI_symbol_name("_tm_hour")
	.dwattr $C$DW$1155, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1155, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1156	.dwtag  DW_TAG_member
	.dwattr $C$DW$1156, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$1156, DW_AT_name("tm_mday")
	.dwattr $C$DW$1156, DW_AT_TI_symbol_name("_tm_mday")
	.dwattr $C$DW$1156, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$1156, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1157	.dwtag  DW_TAG_member
	.dwattr $C$DW$1157, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$1157, DW_AT_name("tm_mon")
	.dwattr $C$DW$1157, DW_AT_TI_symbol_name("_tm_mon")
	.dwattr $C$DW$1157, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$1157, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1158	.dwtag  DW_TAG_member
	.dwattr $C$DW$1158, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$1158, DW_AT_name("tm_year")
	.dwattr $C$DW$1158, DW_AT_TI_symbol_name("_tm_year")
	.dwattr $C$DW$1158, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$1158, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1159	.dwtag  DW_TAG_member
	.dwattr $C$DW$1159, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$1159, DW_AT_name("tm_wday")
	.dwattr $C$DW$1159, DW_AT_TI_symbol_name("_tm_wday")
	.dwattr $C$DW$1159, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$1159, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1160	.dwtag  DW_TAG_member
	.dwattr $C$DW$1160, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$1160, DW_AT_name("tm_yday")
	.dwattr $C$DW$1160, DW_AT_TI_symbol_name("_tm_yday")
	.dwattr $C$DW$1160, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr $C$DW$1160, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1161	.dwtag  DW_TAG_member
	.dwattr $C$DW$1161, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$1161, DW_AT_name("tm_isdst")
	.dwattr $C$DW$1161, DW_AT_TI_symbol_name("_tm_isdst")
	.dwattr $C$DW$1161, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr $C$DW$1161, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$117	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$117, DW_AT_declaration
	.dwattr $C$DW$117, DW_AT_TI_symbol_name("___as__2tmFRC2tm")
	.dwattr $C$DW$117, DW_AT_type(*$C$DW$T$324)
	.dwattr $C$DW$117, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1162	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1162, DW_AT_type(*$C$DW$T$326)
	.dwendtag $C$DW$117

	.dwendtag $C$DW$T$328

$C$DW$T$324	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$324, DW_AT_type(*$C$DW$T$328)
	.dwattr $C$DW$T$324, DW_AT_address_class(0x20)

$C$DW$T$327	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$327, DW_AT_type(*$C$DW$T$324)
	.dwattr $C$DW$T$327, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1163	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1163, DW_AT_type(*$C$DW$T$326)
	.dwendtag $C$DW$T$327

$C$DW$T$325	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$325, DW_AT_type(*$C$DW$T$328)
$C$DW$T$326	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$326, DW_AT_type(*$C$DW$T$325)
	.dwattr $C$DW$T$326, DW_AT_address_class(0x20)

$C$DW$T$333	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$333, DW_AT_name("stat")
	.dwattr $C$DW$T$333, DW_AT_byte_size(0x30)
$C$DW$1164	.dwtag  DW_TAG_member
	.dwattr $C$DW$1164, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1164, DW_AT_name("st_dev")
	.dwattr $C$DW$1164, DW_AT_TI_symbol_name("_st_dev")
	.dwattr $C$DW$1164, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1164, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1165	.dwtag  DW_TAG_member
	.dwattr $C$DW$1165, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1165, DW_AT_name("st_ino")
	.dwattr $C$DW$1165, DW_AT_TI_symbol_name("_st_ino")
	.dwattr $C$DW$1165, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1165, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1166	.dwtag  DW_TAG_member
	.dwattr $C$DW$1166, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1166, DW_AT_name("st_mode")
	.dwattr $C$DW$1166, DW_AT_TI_symbol_name("_st_mode")
	.dwattr $C$DW$1166, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1166, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1167	.dwtag  DW_TAG_member
	.dwattr $C$DW$1167, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1167, DW_AT_name("st_nlink")
	.dwattr $C$DW$1167, DW_AT_TI_symbol_name("_st_nlink")
	.dwattr $C$DW$1167, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$1167, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1168	.dwtag  DW_TAG_member
	.dwattr $C$DW$1168, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1168, DW_AT_name("st_uid")
	.dwattr $C$DW$1168, DW_AT_TI_symbol_name("_st_uid")
	.dwattr $C$DW$1168, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$1168, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1169	.dwtag  DW_TAG_member
	.dwattr $C$DW$1169, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1169, DW_AT_name("st_gid")
	.dwattr $C$DW$1169, DW_AT_TI_symbol_name("_st_gid")
	.dwattr $C$DW$1169, DW_AT_data_member_location[DW_OP_plus_uconst 0x12]
	.dwattr $C$DW$1169, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1170	.dwtag  DW_TAG_member
	.dwattr $C$DW$1170, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1170, DW_AT_name("st_rdev")
	.dwattr $C$DW$1170, DW_AT_TI_symbol_name("_st_rdev")
	.dwattr $C$DW$1170, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$1170, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1171	.dwtag  DW_TAG_member
	.dwattr $C$DW$1171, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1171, DW_AT_name("st_size")
	.dwattr $C$DW$1171, DW_AT_TI_symbol_name("_st_size")
	.dwattr $C$DW$1171, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$1171, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1172	.dwtag  DW_TAG_member
	.dwattr $C$DW$1172, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1172, DW_AT_name("st_atime")
	.dwattr $C$DW$1172, DW_AT_TI_symbol_name("_st_atime")
	.dwattr $C$DW$1172, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr $C$DW$1172, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1173	.dwtag  DW_TAG_member
	.dwattr $C$DW$1173, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1173, DW_AT_name("st_mtime")
	.dwattr $C$DW$1173, DW_AT_TI_symbol_name("_st_mtime")
	.dwattr $C$DW$1173, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr $C$DW$1173, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1174	.dwtag  DW_TAG_member
	.dwattr $C$DW$1174, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1174, DW_AT_name("st_ctime")
	.dwattr $C$DW$1174, DW_AT_TI_symbol_name("_st_ctime")
	.dwattr $C$DW$1174, DW_AT_data_member_location[DW_OP_plus_uconst 0x24]
	.dwattr $C$DW$1174, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1175	.dwtag  DW_TAG_member
	.dwattr $C$DW$1175, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1175, DW_AT_name("st_blksize")
	.dwattr $C$DW$1175, DW_AT_TI_symbol_name("_st_blksize")
	.dwattr $C$DW$1175, DW_AT_data_member_location[DW_OP_plus_uconst 0x28]
	.dwattr $C$DW$1175, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1176	.dwtag  DW_TAG_member
	.dwattr $C$DW$1176, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1176, DW_AT_name("st_blocks")
	.dwattr $C$DW$1176, DW_AT_TI_symbol_name("_st_blocks")
	.dwattr $C$DW$1176, DW_AT_data_member_location[DW_OP_plus_uconst 0x2c]
	.dwattr $C$DW$1176, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$118	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$118, DW_AT_declaration
	.dwattr $C$DW$118, DW_AT_TI_symbol_name("___as__4statFRC4stat")
	.dwattr $C$DW$118, DW_AT_type(*$C$DW$T$329)
	.dwattr $C$DW$118, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1177	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1177, DW_AT_type(*$C$DW$T$331)
	.dwendtag $C$DW$118

	.dwendtag $C$DW$T$333

$C$DW$T$329	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$329, DW_AT_type(*$C$DW$T$333)
	.dwattr $C$DW$T$329, DW_AT_address_class(0x20)

$C$DW$T$332	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$332, DW_AT_type(*$C$DW$T$329)
	.dwattr $C$DW$T$332, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1178	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1178, DW_AT_type(*$C$DW$T$331)
	.dwendtag $C$DW$T$332

$C$DW$T$330	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$330, DW_AT_type(*$C$DW$T$333)
$C$DW$T$331	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$331, DW_AT_type(*$C$DW$T$330)
	.dwattr $C$DW$T$331, DW_AT_address_class(0x20)

$C$DW$T$340	.dwtag  DW_TAG_union_type
	.dwattr $C$DW$T$340, DW_AT_byte_size(0x04)
$C$DW$1179	.dwtag  DW_TAG_member
	.dwattr $C$DW$1179, DW_AT_type(*$C$DW$T$335)
	.dwattr $C$DW$1179, DW_AT_name("dtor")
	.dwattr $C$DW$1179, DW_AT_TI_symbol_name("_dtor")
	.dwattr $C$DW$1179, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1179, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1180	.dwtag  DW_TAG_member
	.dwattr $C$DW$1180, DW_AT_type(*$C$DW$T$211)
	.dwattr $C$DW$1180, DW_AT_name("dfun")
	.dwattr $C$DW$1180, DW_AT_TI_symbol_name("_dfun")
	.dwattr $C$DW$1180, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1180, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$119	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$119, DW_AT_declaration
	.dwattr $C$DW$119, DW_AT_TI_symbol_name("___as__Q2_14s_rts_dtorlist4__C1FRCQ2_14s_rts_dtorlist4__C1")
	.dwattr $C$DW$119, DW_AT_type(*$C$DW$T$336)
	.dwattr $C$DW$119, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1181	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1181, DW_AT_type(*$C$DW$T$338)
	.dwendtag $C$DW$119

	.dwendtag $C$DW$T$340

$C$DW$T$336	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$336, DW_AT_type(*$C$DW$T$340)
	.dwattr $C$DW$T$336, DW_AT_address_class(0x20)

$C$DW$T$339	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$339, DW_AT_type(*$C$DW$T$336)
	.dwattr $C$DW$T$339, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1182	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1182, DW_AT_type(*$C$DW$T$338)
	.dwendtag $C$DW$T$339

$C$DW$T$337	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$337, DW_AT_type(*$C$DW$T$340)
$C$DW$T$338	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$338, DW_AT_type(*$C$DW$T$337)
	.dwattr $C$DW$T$338, DW_AT_address_class(0x20)

$C$DW$T$346	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$346, DW_AT_name("s_rts_dtorlist")
	.dwattr $C$DW$T$346, DW_AT_byte_size(0x0c)
$C$DW$1183	.dwtag  DW_TAG_member
	.dwattr $C$DW$1183, DW_AT_type(*$C$DW$T$341)
	.dwattr $C$DW$1183, DW_AT_name("next")
	.dwattr $C$DW$1183, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$1183, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1183, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1184	.dwtag  DW_TAG_member
	.dwattr $C$DW$1184, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$1184, DW_AT_name("object")
	.dwattr $C$DW$1184, DW_AT_TI_symbol_name("_object")
	.dwattr $C$DW$1184, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1184, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1185	.dwtag  DW_TAG_member
	.dwattr $C$DW$1185, DW_AT_type(*$C$DW$T$340)
	.dwattr $C$DW$1185, DW_AT_name("fun")
	.dwattr $C$DW$1185, DW_AT_TI_symbol_name("_fun")
	.dwattr $C$DW$1185, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1185, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$120	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$120, DW_AT_declaration
	.dwattr $C$DW$120, DW_AT_TI_symbol_name("___as__14s_rts_dtorlistFRC14s_rts_dtorlist")
	.dwattr $C$DW$120, DW_AT_type(*$C$DW$T$342)
	.dwattr $C$DW$120, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1186	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1186, DW_AT_type(*$C$DW$T$344)
	.dwendtag $C$DW$120

	.dwendtag $C$DW$T$346

$C$DW$T$341	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$341, DW_AT_type(*$C$DW$T$346)
	.dwattr $C$DW$T$341, DW_AT_address_class(0x20)
$C$DW$T$342	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$342, DW_AT_type(*$C$DW$T$346)
	.dwattr $C$DW$T$342, DW_AT_address_class(0x20)

$C$DW$T$345	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$345, DW_AT_type(*$C$DW$T$342)
	.dwattr $C$DW$T$345, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1187	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1187, DW_AT_type(*$C$DW$T$344)
	.dwendtag $C$DW$T$345

$C$DW$T$343	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$343, DW_AT_type(*$C$DW$T$346)
$C$DW$T$344	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$344, DW_AT_type(*$C$DW$T$343)
	.dwattr $C$DW$T$344, DW_AT_address_class(0x20)

$C$DW$T$351	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$351, DW_AT_name("timespec")
	.dwattr $C$DW$T$351, DW_AT_byte_size(0x08)
$C$DW$1188	.dwtag  DW_TAG_member
	.dwattr $C$DW$1188, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1188, DW_AT_name("tv_sec")
	.dwattr $C$DW$1188, DW_AT_TI_symbol_name("_tv_sec")
	.dwattr $C$DW$1188, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1188, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1189	.dwtag  DW_TAG_member
	.dwattr $C$DW$1189, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$1189, DW_AT_name("tv_nsec")
	.dwattr $C$DW$1189, DW_AT_TI_symbol_name("_tv_nsec")
	.dwattr $C$DW$1189, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1189, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$121	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$121, DW_AT_declaration
	.dwattr $C$DW$121, DW_AT_TI_symbol_name("___as__8timespecFRC8timespec")
	.dwattr $C$DW$121, DW_AT_type(*$C$DW$T$347)
	.dwattr $C$DW$121, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1190	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1190, DW_AT_type(*$C$DW$T$349)
	.dwendtag $C$DW$121

	.dwendtag $C$DW$T$351

$C$DW$T$347	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$347, DW_AT_type(*$C$DW$T$351)
	.dwattr $C$DW$T$347, DW_AT_address_class(0x20)

$C$DW$T$350	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$350, DW_AT_type(*$C$DW$T$347)
	.dwattr $C$DW$T$350, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1191	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1191, DW_AT_type(*$C$DW$T$349)
	.dwendtag $C$DW$T$350

$C$DW$T$348	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$348, DW_AT_type(*$C$DW$T$351)
$C$DW$T$349	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$349, DW_AT_type(*$C$DW$T$348)
	.dwattr $C$DW$T$349, DW_AT_address_class(0x20)

$C$DW$T$358	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$358, DW_AT_name("sockaddr")
	.dwattr $C$DW$T$358, DW_AT_byte_size(0x10)
$C$DW$1192	.dwtag  DW_TAG_member
	.dwattr $C$DW$1192, DW_AT_type(*$C$DW$T$352)
	.dwattr $C$DW$1192, DW_AT_name("sa_family")
	.dwattr $C$DW$1192, DW_AT_TI_symbol_name("_sa_family")
	.dwattr $C$DW$1192, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1192, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1193	.dwtag  DW_TAG_member
	.dwattr $C$DW$1193, DW_AT_type(*$C$DW$T$353)
	.dwattr $C$DW$1193, DW_AT_name("sa_data")
	.dwattr $C$DW$1193, DW_AT_TI_symbol_name("_sa_data")
	.dwattr $C$DW$1193, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr $C$DW$1193, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$122	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$122, DW_AT_declaration
	.dwattr $C$DW$122, DW_AT_TI_symbol_name("___as__8sockaddrFRC8sockaddr")
	.dwattr $C$DW$122, DW_AT_type(*$C$DW$T$354)
	.dwattr $C$DW$122, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1194	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1194, DW_AT_type(*$C$DW$T$356)
	.dwendtag $C$DW$122

	.dwendtag $C$DW$T$358

$C$DW$T$354	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$354, DW_AT_type(*$C$DW$T$358)
	.dwattr $C$DW$T$354, DW_AT_address_class(0x20)

$C$DW$T$357	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$357, DW_AT_type(*$C$DW$T$354)
	.dwattr $C$DW$T$357, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1195	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1195, DW_AT_type(*$C$DW$T$356)
	.dwendtag $C$DW$T$357

$C$DW$T$355	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$355, DW_AT_type(*$C$DW$T$358)
$C$DW$T$356	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$356, DW_AT_type(*$C$DW$T$355)
	.dwattr $C$DW$T$356, DW_AT_address_class(0x20)

$C$DW$T$363	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$363, DW_AT_name("in_addr")
	.dwattr $C$DW$T$363, DW_AT_byte_size(0x04)
$C$DW$1196	.dwtag  DW_TAG_member
	.dwattr $C$DW$1196, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1196, DW_AT_name("s_addr")
	.dwattr $C$DW$1196, DW_AT_TI_symbol_name("_s_addr")
	.dwattr $C$DW$1196, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1196, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$123	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$123, DW_AT_declaration
	.dwattr $C$DW$123, DW_AT_TI_symbol_name("___as__7in_addrFRC7in_addr")
	.dwattr $C$DW$123, DW_AT_type(*$C$DW$T$359)
	.dwattr $C$DW$123, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1197	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1197, DW_AT_type(*$C$DW$T$361)
	.dwendtag $C$DW$123

	.dwendtag $C$DW$T$363

$C$DW$T$359	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$359, DW_AT_type(*$C$DW$T$363)
	.dwattr $C$DW$T$359, DW_AT_address_class(0x20)

$C$DW$T$362	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$362, DW_AT_type(*$C$DW$T$359)
	.dwattr $C$DW$T$362, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1198	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1198, DW_AT_type(*$C$DW$T$361)
	.dwendtag $C$DW$T$362

$C$DW$T$360	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$360, DW_AT_type(*$C$DW$T$363)
$C$DW$T$361	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$361, DW_AT_type(*$C$DW$T$360)
	.dwattr $C$DW$T$361, DW_AT_address_class(0x20)

$C$DW$T$368	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$368, DW_AT_name("sockaddr_in")
	.dwattr $C$DW$T$368, DW_AT_byte_size(0x10)
$C$DW$1199	.dwtag  DW_TAG_member
	.dwattr $C$DW$1199, DW_AT_type(*$C$DW$T$352)
	.dwattr $C$DW$1199, DW_AT_name("sin_family")
	.dwattr $C$DW$1199, DW_AT_TI_symbol_name("_sin_family")
	.dwattr $C$DW$1199, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1199, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1200	.dwtag  DW_TAG_member
	.dwattr $C$DW$1200, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1200, DW_AT_name("sin_port")
	.dwattr $C$DW$1200, DW_AT_TI_symbol_name("_sin_port")
	.dwattr $C$DW$1200, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr $C$DW$1200, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1201	.dwtag  DW_TAG_member
	.dwattr $C$DW$1201, DW_AT_type(*$C$DW$T$363)
	.dwattr $C$DW$1201, DW_AT_name("sin_addr")
	.dwattr $C$DW$1201, DW_AT_TI_symbol_name("_sin_addr")
	.dwattr $C$DW$1201, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1201, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1202	.dwtag  DW_TAG_member
	.dwattr $C$DW$1202, DW_AT_type(*$C$DW$T$59)
	.dwattr $C$DW$1202, DW_AT_name("pad")
	.dwattr $C$DW$1202, DW_AT_TI_symbol_name("_pad")
	.dwattr $C$DW$1202, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1202, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$124	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$124, DW_AT_declaration
	.dwattr $C$DW$124, DW_AT_TI_symbol_name("___as__11sockaddr_inFRC11sockaddr_in")
	.dwattr $C$DW$124, DW_AT_type(*$C$DW$T$364)
	.dwattr $C$DW$124, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1203	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1203, DW_AT_type(*$C$DW$T$366)
	.dwendtag $C$DW$124

	.dwendtag $C$DW$T$368

$C$DW$T$364	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$364, DW_AT_type(*$C$DW$T$368)
	.dwattr $C$DW$T$364, DW_AT_address_class(0x20)

$C$DW$T$367	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$367, DW_AT_type(*$C$DW$T$364)
	.dwattr $C$DW$T$367, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1204	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1204, DW_AT_type(*$C$DW$T$366)
	.dwendtag $C$DW$T$367

$C$DW$T$365	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$365, DW_AT_type(*$C$DW$T$368)
$C$DW$T$366	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$366, DW_AT_type(*$C$DW$T$365)
	.dwattr $C$DW$T$366, DW_AT_address_class(0x20)

$C$DW$T$373	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$373, DW_AT_name("route_add_parms")
	.dwattr $C$DW$T$373, DW_AT_byte_size(0x14)
$C$DW$1205	.dwtag  DW_TAG_member
	.dwattr $C$DW$1205, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1205, DW_AT_name("network")
	.dwattr $C$DW$1205, DW_AT_TI_symbol_name("_network")
	.dwattr $C$DW$1205, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1205, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1206	.dwtag  DW_TAG_member
	.dwattr $C$DW$1206, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1206, DW_AT_name("mask")
	.dwattr $C$DW$1206, DW_AT_TI_symbol_name("_mask")
	.dwattr $C$DW$1206, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1206, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1207	.dwtag  DW_TAG_member
	.dwattr $C$DW$1207, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1207, DW_AT_name("gateway")
	.dwattr $C$DW$1207, DW_AT_TI_symbol_name("_gateway")
	.dwattr $C$DW$1207, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1207, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1208	.dwtag  DW_TAG_member
	.dwattr $C$DW$1208, DW_AT_type(*$C$DW$T$111)
	.dwattr $C$DW$1208, DW_AT_name("name")
	.dwattr $C$DW$1208, DW_AT_TI_symbol_name("_name")
	.dwattr $C$DW$1208, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$1208, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1209	.dwtag  DW_TAG_member
	.dwattr $C$DW$1209, DW_AT_type(*$C$DW$T$79)
	.dwattr $C$DW$1209, DW_AT_name("isdef")
	.dwattr $C$DW$1209, DW_AT_TI_symbol_name("_isdef")
	.dwattr $C$DW$1209, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$1209, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$125	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$125, DW_AT_declaration
	.dwattr $C$DW$125, DW_AT_TI_symbol_name("___as__15route_add_parmsFRC15route_add_parms")
	.dwattr $C$DW$125, DW_AT_type(*$C$DW$T$369)
	.dwattr $C$DW$125, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1210	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1210, DW_AT_type(*$C$DW$T$371)
	.dwendtag $C$DW$125

	.dwendtag $C$DW$T$373

$C$DW$T$369	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$369, DW_AT_type(*$C$DW$T$373)
	.dwattr $C$DW$T$369, DW_AT_address_class(0x20)

$C$DW$T$372	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$372, DW_AT_type(*$C$DW$T$369)
	.dwattr $C$DW$T$372, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1211	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1211, DW_AT_type(*$C$DW$T$371)
	.dwendtag $C$DW$T$372

$C$DW$T$370	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$370, DW_AT_type(*$C$DW$T$373)
$C$DW$T$371	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$371, DW_AT_type(*$C$DW$T$370)
	.dwattr $C$DW$T$371, DW_AT_address_class(0x20)

$C$DW$T$378	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$378, DW_AT_name("change_ip_parms")
	.dwattr $C$DW$T$378, DW_AT_byte_size(0x0c)
$C$DW$1212	.dwtag  DW_TAG_member
	.dwattr $C$DW$1212, DW_AT_type(*$C$DW$T$111)
	.dwattr $C$DW$1212, DW_AT_name("name")
	.dwattr $C$DW$1212, DW_AT_TI_symbol_name("_name")
	.dwattr $C$DW$1212, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1212, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1213	.dwtag  DW_TAG_member
	.dwattr $C$DW$1213, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1213, DW_AT_name("new_ip")
	.dwattr $C$DW$1213, DW_AT_TI_symbol_name("_new_ip")
	.dwattr $C$DW$1213, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1213, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1214	.dwtag  DW_TAG_member
	.dwattr $C$DW$1214, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1214, DW_AT_name("mask")
	.dwattr $C$DW$1214, DW_AT_TI_symbol_name("_mask")
	.dwattr $C$DW$1214, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1214, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$126	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$126, DW_AT_declaration
	.dwattr $C$DW$126, DW_AT_TI_symbol_name("___as__15change_ip_parmsFRC15change_ip_parms")
	.dwattr $C$DW$126, DW_AT_type(*$C$DW$T$374)
	.dwattr $C$DW$126, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1215	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1215, DW_AT_type(*$C$DW$T$376)
	.dwendtag $C$DW$126

	.dwendtag $C$DW$T$378

$C$DW$T$374	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$374, DW_AT_type(*$C$DW$T$378)
	.dwattr $C$DW$T$374, DW_AT_address_class(0x20)

$C$DW$T$377	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$377, DW_AT_type(*$C$DW$T$374)
	.dwattr $C$DW$T$377, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1216	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1216, DW_AT_type(*$C$DW$T$376)
	.dwendtag $C$DW$T$377

$C$DW$T$375	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$375, DW_AT_type(*$C$DW$T$378)
$C$DW$T$376	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$376, DW_AT_type(*$C$DW$T$375)
	.dwattr $C$DW$T$376, DW_AT_address_class(0x20)

$C$DW$T$383	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$383, DW_AT_name("linger")
	.dwattr $C$DW$T$383, DW_AT_byte_size(0x04)
$C$DW$1217	.dwtag  DW_TAG_member
	.dwattr $C$DW$1217, DW_AT_type(*$C$DW$T$22)
	.dwattr $C$DW$1217, DW_AT_name("l_onoff")
	.dwattr $C$DW$1217, DW_AT_TI_symbol_name("_l_onoff")
	.dwattr $C$DW$1217, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1217, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1218	.dwtag  DW_TAG_member
	.dwattr $C$DW$1218, DW_AT_type(*$C$DW$T$22)
	.dwattr $C$DW$1218, DW_AT_name("l_linger")
	.dwattr $C$DW$1218, DW_AT_TI_symbol_name("_l_linger")
	.dwattr $C$DW$1218, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr $C$DW$1218, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$127	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$127, DW_AT_declaration
	.dwattr $C$DW$127, DW_AT_TI_symbol_name("___as__6lingerFRC6linger")
	.dwattr $C$DW$127, DW_AT_type(*$C$DW$T$379)
	.dwattr $C$DW$127, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1219	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1219, DW_AT_type(*$C$DW$T$381)
	.dwendtag $C$DW$127

	.dwendtag $C$DW$T$383

$C$DW$T$379	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$379, DW_AT_type(*$C$DW$T$383)
	.dwattr $C$DW$T$379, DW_AT_address_class(0x20)

$C$DW$T$382	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$382, DW_AT_type(*$C$DW$T$379)
	.dwattr $C$DW$T$382, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1220	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1220, DW_AT_type(*$C$DW$T$381)
	.dwendtag $C$DW$T$382

$C$DW$T$380	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$380, DW_AT_type(*$C$DW$T$383)
$C$DW$T$381	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$381, DW_AT_type(*$C$DW$T$380)
	.dwattr $C$DW$T$381, DW_AT_address_class(0x20)

$C$DW$T$388	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$388, DW_AT_name("kdg_cmd")
	.dwattr $C$DW$T$388, DW_AT_byte_size(0x04)
$C$DW$1221	.dwtag  DW_TAG_member
	.dwattr $C$DW$1221, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1221, DW_AT_name("cmd")
	.dwattr $C$DW$1221, DW_AT_TI_symbol_name("_cmd")
	.dwattr $C$DW$1221, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1221, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$128	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$128, DW_AT_declaration
	.dwattr $C$DW$128, DW_AT_TI_symbol_name("___as__7kdg_cmdFRC7kdg_cmd")
	.dwattr $C$DW$128, DW_AT_type(*$C$DW$T$384)
	.dwattr $C$DW$128, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1222	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1222, DW_AT_type(*$C$DW$T$386)
	.dwendtag $C$DW$128

	.dwendtag $C$DW$T$388

$C$DW$T$384	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$384, DW_AT_type(*$C$DW$T$388)
	.dwattr $C$DW$T$384, DW_AT_address_class(0x20)

$C$DW$T$387	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$387, DW_AT_type(*$C$DW$T$384)
	.dwattr $C$DW$T$387, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1223	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1223, DW_AT_type(*$C$DW$T$386)
	.dwendtag $C$DW$T$387

$C$DW$T$385	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$385, DW_AT_type(*$C$DW$T$388)
$C$DW$T$386	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$386, DW_AT_type(*$C$DW$T$385)
	.dwattr $C$DW$T$386, DW_AT_address_class(0x20)

$C$DW$T$393	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$393, DW_AT_name("kdg_cmd_ask")
	.dwattr $C$DW$T$393, DW_AT_byte_size(0x08)
$C$DW$1224	.dwtag  DW_TAG_member
	.dwattr $C$DW$1224, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1224, DW_AT_name("cmd")
	.dwattr $C$DW$1224, DW_AT_TI_symbol_name("_cmd")
	.dwattr $C$DW$1224, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1224, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1225	.dwtag  DW_TAG_member
	.dwattr $C$DW$1225, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1225, DW_AT_name("ask")
	.dwattr $C$DW$1225, DW_AT_TI_symbol_name("_ask")
	.dwattr $C$DW$1225, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1225, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$129	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$129, DW_AT_declaration
	.dwattr $C$DW$129, DW_AT_TI_symbol_name("___as__11kdg_cmd_askFRC11kdg_cmd_ask")
	.dwattr $C$DW$129, DW_AT_type(*$C$DW$T$389)
	.dwattr $C$DW$129, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1226	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1226, DW_AT_type(*$C$DW$T$391)
	.dwendtag $C$DW$129

	.dwendtag $C$DW$T$393

$C$DW$T$389	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$389, DW_AT_type(*$C$DW$T$393)
	.dwattr $C$DW$T$389, DW_AT_address_class(0x20)

$C$DW$T$392	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$392, DW_AT_type(*$C$DW$T$389)
	.dwattr $C$DW$T$392, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1227	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1227, DW_AT_type(*$C$DW$T$391)
	.dwendtag $C$DW$T$392

$C$DW$T$390	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$390, DW_AT_type(*$C$DW$T$393)
$C$DW$T$391	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$391, DW_AT_type(*$C$DW$T$390)
	.dwattr $C$DW$T$391, DW_AT_address_class(0x20)

$C$DW$T$398	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$398, DW_AT_name("kdg_rez_test")
	.dwattr $C$DW$T$398, DW_AT_byte_size(0x3c)
$C$DW$1228	.dwtag  DW_TAG_member
	.dwattr $C$DW$1228, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1228, DW_AT_name("cmd")
	.dwattr $C$DW$1228, DW_AT_TI_symbol_name("_cmd")
	.dwattr $C$DW$1228, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1228, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1229	.dwtag  DW_TAG_member
	.dwattr $C$DW$1229, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1229, DW_AT_name("n_test")
	.dwattr $C$DW$1229, DW_AT_TI_symbol_name("_n_test")
	.dwattr $C$DW$1229, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1229, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1230	.dwtag  DW_TAG_member
	.dwattr $C$DW$1230, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1230, DW_AT_name("rez")
	.dwattr $C$DW$1230, DW_AT_TI_symbol_name("_rez")
	.dwattr $C$DW$1230, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1230, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1231	.dwtag  DW_TAG_member
	.dwattr $C$DW$1231, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1231, DW_AT_name("adrr")
	.dwattr $C$DW$1231, DW_AT_TI_symbol_name("_adrr")
	.dwattr $C$DW$1231, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$1231, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1232	.dwtag  DW_TAG_member
	.dwattr $C$DW$1232, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1232, DW_AT_name("data")
	.dwattr $C$DW$1232, DW_AT_TI_symbol_name("_data")
	.dwattr $C$DW$1232, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$1232, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1233	.dwtag  DW_TAG_member
	.dwattr $C$DW$1233, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1233, DW_AT_name("data1")
	.dwattr $C$DW$1233, DW_AT_TI_symbol_name("_data1")
	.dwattr $C$DW$1233, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$1233, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1234	.dwtag  DW_TAG_member
	.dwattr $C$DW$1234, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1234, DW_AT_name("err")
	.dwattr $C$DW$1234, DW_AT_TI_symbol_name("_err")
	.dwattr $C$DW$1234, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$1234, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1235	.dwtag  DW_TAG_member
	.dwattr $C$DW$1235, DW_AT_type(*$C$DW$T$302)
	.dwattr $C$DW$1235, DW_AT_name("buf")
	.dwattr $C$DW$1235, DW_AT_TI_symbol_name("_buf")
	.dwattr $C$DW$1235, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr $C$DW$1235, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$130	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$130, DW_AT_declaration
	.dwattr $C$DW$130, DW_AT_TI_symbol_name("___as__12kdg_rez_testFRC12kdg_rez_test")
	.dwattr $C$DW$130, DW_AT_type(*$C$DW$T$394)
	.dwattr $C$DW$130, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1236	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1236, DW_AT_type(*$C$DW$T$396)
	.dwendtag $C$DW$130

	.dwendtag $C$DW$T$398

$C$DW$T$394	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$394, DW_AT_type(*$C$DW$T$398)
	.dwattr $C$DW$T$394, DW_AT_address_class(0x20)

$C$DW$T$397	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$397, DW_AT_type(*$C$DW$T$394)
	.dwattr $C$DW$T$397, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1237	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1237, DW_AT_type(*$C$DW$T$396)
	.dwendtag $C$DW$T$397

$C$DW$T$395	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$395, DW_AT_type(*$C$DW$T$398)
$C$DW$T$396	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$396, DW_AT_type(*$C$DW$T$395)
	.dwattr $C$DW$T$396, DW_AT_address_class(0x20)
$C$DW$T$696	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$696, DW_AT_type(*$C$DW$T$398)
	.dwattr $C$DW$T$696, DW_AT_address_class(0x20)

$C$DW$T$403	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$403, DW_AT_name("rez_test")
	.dwattr $C$DW$T$403, DW_AT_byte_size(0x10)
$C$DW$1238	.dwtag  DW_TAG_member
	.dwattr $C$DW$1238, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1238, DW_AT_name("cmd")
	.dwattr $C$DW$1238, DW_AT_TI_symbol_name("_cmd")
	.dwattr $C$DW$1238, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1238, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1239	.dwtag  DW_TAG_member
	.dwattr $C$DW$1239, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1239, DW_AT_name("n_test")
	.dwattr $C$DW$1239, DW_AT_TI_symbol_name("_n_test")
	.dwattr $C$DW$1239, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1239, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1240	.dwtag  DW_TAG_member
	.dwattr $C$DW$1240, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1240, DW_AT_name("rez0")
	.dwattr $C$DW$1240, DW_AT_TI_symbol_name("_rez0")
	.dwattr $C$DW$1240, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1240, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1241	.dwtag  DW_TAG_member
	.dwattr $C$DW$1241, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1241, DW_AT_name("rez1")
	.dwattr $C$DW$1241, DW_AT_TI_symbol_name("_rez1")
	.dwattr $C$DW$1241, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$1241, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$131	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$131, DW_AT_declaration
	.dwattr $C$DW$131, DW_AT_TI_symbol_name("___as__8rez_testFRC8rez_test")
	.dwattr $C$DW$131, DW_AT_type(*$C$DW$T$399)
	.dwattr $C$DW$131, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1242	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1242, DW_AT_type(*$C$DW$T$401)
	.dwendtag $C$DW$131

	.dwendtag $C$DW$T$403

$C$DW$T$399	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$399, DW_AT_type(*$C$DW$T$403)
	.dwattr $C$DW$T$399, DW_AT_address_class(0x20)

$C$DW$T$402	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$402, DW_AT_type(*$C$DW$T$399)
	.dwattr $C$DW$T$402, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1243	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1243, DW_AT_type(*$C$DW$T$401)
	.dwendtag $C$DW$T$402

$C$DW$T$400	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$400, DW_AT_type(*$C$DW$T$403)
$C$DW$T$401	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$401, DW_AT_type(*$C$DW$T$400)
	.dwattr $C$DW$T$401, DW_AT_address_class(0x20)

$C$DW$T$412	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$412, DW_AT_name("about_usb")
	.dwattr $C$DW$T$412, DW_AT_byte_size(0x38)
$C$DW$1244	.dwtag  DW_TAG_member
	.dwattr $C$DW$1244, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1244, DW_AT_name("enable")
	.dwattr $C$DW$1244, DW_AT_TI_symbol_name("_enable")
	.dwattr $C$DW$1244, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1244, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1245	.dwtag  DW_TAG_member
	.dwattr $C$DW$1245, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1245, DW_AT_name("block_length")
	.dwattr $C$DW$1245, DW_AT_TI_symbol_name("_block_length")
	.dwattr $C$DW$1245, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1245, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1246	.dwtag  DW_TAG_member
	.dwattr $C$DW$1246, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$1246, DW_AT_name("flash_capacity")
	.dwattr $C$DW$1246, DW_AT_TI_symbol_name("_flash_capacity")
	.dwattr $C$DW$1246, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1246, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1247	.dwtag  DW_TAG_member
	.dwattr $C$DW$1247, DW_AT_type(*$C$DW$T$404)
	.dwattr $C$DW$1247, DW_AT_name("vendor_identification")
	.dwattr $C$DW$1247, DW_AT_TI_symbol_name("_vendor_identification")
	.dwattr $C$DW$1247, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$1247, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1248	.dwtag  DW_TAG_member
	.dwattr $C$DW$1248, DW_AT_type(*$C$DW$T$405)
	.dwattr $C$DW$1248, DW_AT_name("product_identification")
	.dwattr $C$DW$1248, DW_AT_TI_symbol_name("_product_identification")
	.dwattr $C$DW$1248, DW_AT_data_member_location[DW_OP_plus_uconst 0x1a]
	.dwattr $C$DW$1248, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1249	.dwtag  DW_TAG_member
	.dwattr $C$DW$1249, DW_AT_type(*$C$DW$T$406)
	.dwattr $C$DW$1249, DW_AT_name("product_revision_level")
	.dwattr $C$DW$1249, DW_AT_TI_symbol_name("_product_revision_level")
	.dwattr $C$DW$1249, DW_AT_data_member_location[DW_OP_plus_uconst 0x2b]
	.dwattr $C$DW$1249, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1250	.dwtag  DW_TAG_member
	.dwattr $C$DW$1250, DW_AT_type(*$C$DW$T$407)
	.dwattr $C$DW$1250, DW_AT_name("fstr")
	.dwattr $C$DW$1250, DW_AT_TI_symbol_name("_fstr")
	.dwattr $C$DW$1250, DW_AT_data_member_location[DW_OP_plus_uconst 0x30]
	.dwattr $C$DW$1250, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$132	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$132, DW_AT_declaration
	.dwattr $C$DW$132, DW_AT_TI_symbol_name("___as__9about_usbFRC9about_usb")
	.dwattr $C$DW$132, DW_AT_type(*$C$DW$T$408)
	.dwattr $C$DW$132, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1251	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1251, DW_AT_type(*$C$DW$T$410)
	.dwendtag $C$DW$132

	.dwendtag $C$DW$T$412

$C$DW$T$408	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$408, DW_AT_type(*$C$DW$T$412)
	.dwattr $C$DW$T$408, DW_AT_address_class(0x20)

$C$DW$T$411	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$411, DW_AT_type(*$C$DW$T$408)
	.dwattr $C$DW$T$411, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1252	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1252, DW_AT_type(*$C$DW$T$410)
	.dwendtag $C$DW$T$411

$C$DW$T$409	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$409, DW_AT_type(*$C$DW$T$412)
$C$DW$T$410	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$410, DW_AT_type(*$C$DW$T$409)
	.dwattr $C$DW$T$410, DW_AT_address_class(0x20)

$C$DW$T$417	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$417, DW_AT_name("comm_status")
	.dwattr $C$DW$T$417, DW_AT_byte_size(0x08)
$C$DW$1253	.dwtag  DW_TAG_member
	.dwattr $C$DW$1253, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1253, DW_AT_name("N")
	.dwattr $C$DW$1253, DW_AT_TI_symbol_name("_N")
	.dwattr $C$DW$1253, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1253, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1254	.dwtag  DW_TAG_member
	.dwattr $C$DW$1254, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1254, DW_AT_name("pid")
	.dwattr $C$DW$1254, DW_AT_TI_symbol_name("_pid")
	.dwattr $C$DW$1254, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1254, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$133	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$133, DW_AT_declaration
	.dwattr $C$DW$133, DW_AT_TI_symbol_name("___as__11comm_statusFRC11comm_status")
	.dwattr $C$DW$133, DW_AT_type(*$C$DW$T$413)
	.dwattr $C$DW$133, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1255	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1255, DW_AT_type(*$C$DW$T$415)
	.dwendtag $C$DW$133

	.dwendtag $C$DW$T$417

$C$DW$T$413	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$413, DW_AT_type(*$C$DW$T$417)
	.dwattr $C$DW$T$413, DW_AT_address_class(0x20)

$C$DW$T$416	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$416, DW_AT_type(*$C$DW$T$413)
	.dwattr $C$DW$T$416, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1256	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1256, DW_AT_type(*$C$DW$T$415)
	.dwendtag $C$DW$T$416

$C$DW$T$414	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$414, DW_AT_type(*$C$DW$T$417)
$C$DW$T$415	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$415, DW_AT_type(*$C$DW$T$414)
	.dwattr $C$DW$T$415, DW_AT_address_class(0x20)

$C$DW$T$422	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$422, DW_AT_name("_SkEthTestRes")
	.dwattr $C$DW$T$422, DW_AT_byte_size(0x14)
$C$DW$1257	.dwtag  DW_TAG_member
	.dwattr $C$DW$1257, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1257, DW_AT_name("errRegDP")
	.dwattr $C$DW$1257, DW_AT_TI_symbol_name("_errRegDP")
	.dwattr $C$DW$1257, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1257, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1258	.dwtag  DW_TAG_member
	.dwattr $C$DW$1258, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1258, DW_AT_name("errRegLX")
	.dwattr $C$DW$1258, DW_AT_TI_symbol_name("_errRegLX")
	.dwattr $C$DW$1258, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1258, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1259	.dwtag  DW_TAG_member
	.dwattr $C$DW$1259, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1259, DW_AT_name("errSP_DP")
	.dwattr $C$DW$1259, DW_AT_TI_symbol_name("_errSP_DP")
	.dwattr $C$DW$1259, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1259, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1260	.dwtag  DW_TAG_member
	.dwattr $C$DW$1260, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1260, DW_AT_name("errSP_LX")
	.dwattr $C$DW$1260, DW_AT_TI_symbol_name("_errSP_LX")
	.dwattr $C$DW$1260, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$1260, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1261	.dwtag  DW_TAG_member
	.dwattr $C$DW$1261, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1261, DW_AT_name("errSP_TR")
	.dwattr $C$DW$1261, DW_AT_TI_symbol_name("_errSP_TR")
	.dwattr $C$DW$1261, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$1261, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$134	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$134, DW_AT_declaration
	.dwattr $C$DW$134, DW_AT_TI_symbol_name("___as__13_SkEthTestResFRC13_SkEthTestRes")
	.dwattr $C$DW$134, DW_AT_type(*$C$DW$T$418)
	.dwattr $C$DW$134, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1262	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1262, DW_AT_type(*$C$DW$T$420)
	.dwendtag $C$DW$134

	.dwendtag $C$DW$T$422

$C$DW$T$418	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$418, DW_AT_type(*$C$DW$T$422)
	.dwattr $C$DW$T$418, DW_AT_address_class(0x20)

$C$DW$T$421	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$421, DW_AT_type(*$C$DW$T$418)
	.dwattr $C$DW$T$421, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1263	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1263, DW_AT_type(*$C$DW$T$420)
	.dwendtag $C$DW$T$421

$C$DW$T$419	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$419, DW_AT_type(*$C$DW$T$422)
$C$DW$T$420	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$420, DW_AT_type(*$C$DW$T$419)
	.dwattr $C$DW$T$420, DW_AT_address_class(0x20)
$C$DW$T$768	.dwtag  DW_TAG_typedef, DW_AT_name("SkEthTestRes")
	.dwattr $C$DW$T$768, DW_AT_type(*$C$DW$T$422)
	.dwattr $C$DW$T$768, DW_AT_language(DW_LANG_C_plus_plus)

$C$DW$T$427	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$427, DW_AT_name("_TestDnsdRes")
	.dwattr $C$DW$T$427, DW_AT_byte_size(0x0c)
$C$DW$1264	.dwtag  DW_TAG_member
	.dwattr $C$DW$1264, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1264, DW_AT_name("errTimeout")
	.dwattr $C$DW$1264, DW_AT_TI_symbol_name("_errTimeout")
	.dwattr $C$DW$1264, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1264, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1265	.dwtag  DW_TAG_member
	.dwattr $C$DW$1265, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1265, DW_AT_name("errReadC0")
	.dwattr $C$DW$1265, DW_AT_TI_symbol_name("_errReadC0")
	.dwattr $C$DW$1265, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1265, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1266	.dwtag  DW_TAG_member
	.dwattr $C$DW$1266, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1266, DW_AT_name("errTrigger")
	.dwattr $C$DW$1266, DW_AT_TI_symbol_name("_errTrigger")
	.dwattr $C$DW$1266, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1266, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$135	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$135, DW_AT_declaration
	.dwattr $C$DW$135, DW_AT_TI_symbol_name("___as__12_TestDnsdResFRC12_TestDnsdRes")
	.dwattr $C$DW$135, DW_AT_type(*$C$DW$T$423)
	.dwattr $C$DW$135, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1267	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1267, DW_AT_type(*$C$DW$T$425)
	.dwendtag $C$DW$135

	.dwendtag $C$DW$T$427

$C$DW$T$423	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$423, DW_AT_type(*$C$DW$T$427)
	.dwattr $C$DW$T$423, DW_AT_address_class(0x20)

$C$DW$T$426	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$426, DW_AT_type(*$C$DW$T$423)
	.dwattr $C$DW$T$426, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1268	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1268, DW_AT_type(*$C$DW$T$425)
	.dwendtag $C$DW$T$426

$C$DW$T$424	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$424, DW_AT_type(*$C$DW$T$427)
$C$DW$T$425	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$425, DW_AT_type(*$C$DW$T$424)
	.dwattr $C$DW$T$425, DW_AT_address_class(0x20)
$C$DW$T$769	.dwtag  DW_TAG_typedef, DW_AT_name("TestDnsdRes")
	.dwattr $C$DW$T$769, DW_AT_type(*$C$DW$T$427)
	.dwattr $C$DW$T$769, DW_AT_language(DW_LANG_C_plus_plus)

$C$DW$T$432	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$432, DW_AT_name("_EthCFG")
	.dwattr $C$DW$T$432, DW_AT_byte_size(0x04)
$C$DW$1269	.dwtag  DW_TAG_member
	.dwattr $C$DW$1269, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1269, DW_AT_name("eth_send")
	.dwattr $C$DW$1269, DW_AT_TI_symbol_name("_eth_send")
	.dwattr $C$DW$1269, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1269, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1270	.dwtag  DW_TAG_member
	.dwattr $C$DW$1270, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1270, DW_AT_name("eth_recv")
	.dwattr $C$DW$1270, DW_AT_TI_symbol_name("_eth_recv")
	.dwattr $C$DW$1270, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr $C$DW$1270, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$136	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$136, DW_AT_declaration
	.dwattr $C$DW$136, DW_AT_TI_symbol_name("___as__7_EthCFGFRC7_EthCFG")
	.dwattr $C$DW$136, DW_AT_type(*$C$DW$T$428)
	.dwattr $C$DW$136, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1271	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1271, DW_AT_type(*$C$DW$T$430)
	.dwendtag $C$DW$136

	.dwendtag $C$DW$T$432

$C$DW$T$428	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$428, DW_AT_type(*$C$DW$T$432)
	.dwattr $C$DW$T$428, DW_AT_address_class(0x20)

$C$DW$T$431	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$431, DW_AT_type(*$C$DW$T$428)
	.dwattr $C$DW$T$431, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1272	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1272, DW_AT_type(*$C$DW$T$430)
	.dwendtag $C$DW$T$431

$C$DW$T$429	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$429, DW_AT_type(*$C$DW$T$432)
$C$DW$T$430	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$430, DW_AT_type(*$C$DW$T$429)
	.dwattr $C$DW$T$430, DW_AT_address_class(0x20)
$C$DW$T$770	.dwtag  DW_TAG_typedef, DW_AT_name("EthCFG")
	.dwattr $C$DW$T$770, DW_AT_type(*$C$DW$T$432)
	.dwattr $C$DW$T$770, DW_AT_language(DW_LANG_C_plus_plus)

$C$DW$T$437	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$437, DW_AT_name("_CryptErrors")
	.dwattr $C$DW$T$437, DW_AT_byte_size(0x18)
$C$DW$1273	.dwtag  DW_TAG_member
	.dwattr $C$DW$1273, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1273, DW_AT_name("NumPack")
	.dwattr $C$DW$1273, DW_AT_TI_symbol_name("_NumPack")
	.dwattr $C$DW$1273, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1273, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1274	.dwtag  DW_TAG_member
	.dwattr $C$DW$1274, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1274, DW_AT_name("BodyErr")
	.dwattr $C$DW$1274, DW_AT_TI_symbol_name("_BodyErr")
	.dwattr $C$DW$1274, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1274, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1275	.dwtag  DW_TAG_member
	.dwattr $C$DW$1275, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1275, DW_AT_name("ImvErr")
	.dwattr $C$DW$1275, DW_AT_TI_symbol_name("_ImvErr")
	.dwattr $C$DW$1275, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1275, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1276	.dwtag  DW_TAG_member
	.dwattr $C$DW$1276, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1276, DW_AT_name("CtrBErr")
	.dwattr $C$DW$1276, DW_AT_TI_symbol_name("_CtrBErr")
	.dwattr $C$DW$1276, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$1276, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1277	.dwtag  DW_TAG_member
	.dwattr $C$DW$1277, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1277, DW_AT_name("LostPack")
	.dwattr $C$DW$1277, DW_AT_TI_symbol_name("_LostPack")
	.dwattr $C$DW$1277, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$1277, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1278	.dwtag  DW_TAG_member
	.dwattr $C$DW$1278, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1278, DW_AT_name("CMPerr")
	.dwattr $C$DW$1278, DW_AT_TI_symbol_name("_CMPerr")
	.dwattr $C$DW$1278, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$1278, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$137	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$137, DW_AT_declaration
	.dwattr $C$DW$137, DW_AT_TI_symbol_name("___as__12_CryptErrorsFRC12_CryptErrors")
	.dwattr $C$DW$137, DW_AT_type(*$C$DW$T$433)
	.dwattr $C$DW$137, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1279	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1279, DW_AT_type(*$C$DW$T$435)
	.dwendtag $C$DW$137

	.dwendtag $C$DW$T$437

$C$DW$T$433	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$433, DW_AT_type(*$C$DW$T$437)
	.dwattr $C$DW$T$433, DW_AT_address_class(0x20)

$C$DW$T$436	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$436, DW_AT_type(*$C$DW$T$433)
	.dwattr $C$DW$T$436, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1280	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1280, DW_AT_type(*$C$DW$T$435)
	.dwendtag $C$DW$T$436

$C$DW$T$434	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$434, DW_AT_type(*$C$DW$T$437)
$C$DW$T$435	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$435, DW_AT_type(*$C$DW$T$434)
	.dwattr $C$DW$T$435, DW_AT_address_class(0x20)
$C$DW$T$771	.dwtag  DW_TAG_typedef, DW_AT_name("CryptErrors")
	.dwattr $C$DW$T$771, DW_AT_type(*$C$DW$T$437)
	.dwattr $C$DW$T$771, DW_AT_language(DW_LANG_C_plus_plus)

$C$DW$T$443	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$443, DW_AT_name("s_hash")
	.dwattr $C$DW$T$443, DW_AT_byte_size(0x44)
$C$DW$1281	.dwtag  DW_TAG_member
	.dwattr $C$DW$1281, DW_AT_type(*$C$DW$T$438)
	.dwattr $C$DW$1281, DW_AT_name("h")
	.dwattr $C$DW$1281, DW_AT_TI_symbol_name("_h")
	.dwattr $C$DW$1281, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1281, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1282	.dwtag  DW_TAG_member
	.dwattr $C$DW$1282, DW_AT_type(*$C$DW$T$438)
	.dwattr $C$DW$1282, DW_AT_name("e")
	.dwattr $C$DW$1282, DW_AT_TI_symbol_name("_e")
	.dwattr $C$DW$1282, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr $C$DW$1282, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1283	.dwtag  DW_TAG_member
	.dwattr $C$DW$1283, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1283, DW_AT_name("len")
	.dwattr $C$DW$1283, DW_AT_TI_symbol_name("_len")
	.dwattr $C$DW$1283, DW_AT_data_member_location[DW_OP_plus_uconst 0x40]
	.dwattr $C$DW$1283, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$138	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$138, DW_AT_declaration
	.dwattr $C$DW$138, DW_AT_TI_symbol_name("___as__6s_hashFRC6s_hash")
	.dwattr $C$DW$138, DW_AT_type(*$C$DW$T$439)
	.dwattr $C$DW$138, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1284	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1284, DW_AT_type(*$C$DW$T$441)
	.dwendtag $C$DW$138

	.dwendtag $C$DW$T$443

$C$DW$T$439	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$439, DW_AT_type(*$C$DW$T$443)
	.dwattr $C$DW$T$439, DW_AT_address_class(0x20)

$C$DW$T$442	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$442, DW_AT_type(*$C$DW$T$439)
	.dwattr $C$DW$T$442, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1285	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1285, DW_AT_type(*$C$DW$T$441)
	.dwendtag $C$DW$T$442

$C$DW$T$440	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$440, DW_AT_type(*$C$DW$T$443)
$C$DW$T$441	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$441, DW_AT_type(*$C$DW$T$440)
	.dwattr $C$DW$T$441, DW_AT_address_class(0x20)

$C$DW$T$448	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$448, DW_AT_name("fwmem_rwbuf")
	.dwattr $C$DW$T$448, DW_AT_byte_size(0x08)
$C$DW$1286	.dwtag  DW_TAG_member
	.dwattr $C$DW$1286, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$1286, DW_AT_name("buffer")
	.dwattr $C$DW$1286, DW_AT_TI_symbol_name("_buffer")
	.dwattr $C$DW$1286, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1286, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1287	.dwtag  DW_TAG_member
	.dwattr $C$DW$1287, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1287, DW_AT_name("length")
	.dwattr $C$DW$1287, DW_AT_TI_symbol_name("_length")
	.dwattr $C$DW$1287, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1287, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$139	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$139, DW_AT_declaration
	.dwattr $C$DW$139, DW_AT_TI_symbol_name("___as__11fwmem_rwbufFRC11fwmem_rwbuf")
	.dwattr $C$DW$139, DW_AT_type(*$C$DW$T$444)
	.dwattr $C$DW$139, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1288	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1288, DW_AT_type(*$C$DW$T$446)
	.dwendtag $C$DW$139

	.dwendtag $C$DW$T$448

$C$DW$T$444	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$444, DW_AT_type(*$C$DW$T$448)
	.dwattr $C$DW$T$444, DW_AT_address_class(0x20)

$C$DW$T$447	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$447, DW_AT_type(*$C$DW$T$444)
	.dwattr $C$DW$T$447, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1289	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1289, DW_AT_type(*$C$DW$T$446)
	.dwendtag $C$DW$T$447

$C$DW$T$445	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$445, DW_AT_type(*$C$DW$T$448)
$C$DW$T$446	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$446, DW_AT_type(*$C$DW$T$445)
	.dwattr $C$DW$T$446, DW_AT_address_class(0x20)

$C$DW$T$453	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$453, DW_AT_name("msg_hash_fwm")
	.dwattr $C$DW$T$453, DW_AT_byte_size(0x8c)
$C$DW$1290	.dwtag  DW_TAG_member
	.dwattr $C$DW$1290, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$1290, DW_AT_name("akn")
	.dwattr $C$DW$1290, DW_AT_TI_symbol_name("_akn")
	.dwattr $C$DW$1290, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1290, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1291	.dwtag  DW_TAG_member
	.dwattr $C$DW$1291, DW_AT_type(*$C$DW$T$443)
	.dwattr $C$DW$1291, DW_AT_name("hash")
	.dwattr $C$DW$1291, DW_AT_TI_symbol_name("_hash")
	.dwattr $C$DW$1291, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1291, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1292	.dwtag  DW_TAG_member
	.dwattr $C$DW$1292, DW_AT_type(*$C$DW$T$443)
	.dwattr $C$DW$1292, DW_AT_name("hash_fwm")
	.dwattr $C$DW$1292, DW_AT_TI_symbol_name("_hash_fwm")
	.dwattr $C$DW$1292, DW_AT_data_member_location[DW_OP_plus_uconst 0x48]
	.dwattr $C$DW$1292, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$140	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$140, DW_AT_declaration
	.dwattr $C$DW$140, DW_AT_TI_symbol_name("___as__12msg_hash_fwmFRC12msg_hash_fwm")
	.dwattr $C$DW$140, DW_AT_type(*$C$DW$T$449)
	.dwattr $C$DW$140, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1293	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1293, DW_AT_type(*$C$DW$T$451)
	.dwendtag $C$DW$140

	.dwendtag $C$DW$T$453

$C$DW$T$449	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$449, DW_AT_type(*$C$DW$T$453)
	.dwattr $C$DW$T$449, DW_AT_address_class(0x20)

$C$DW$T$452	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$452, DW_AT_type(*$C$DW$T$449)
	.dwattr $C$DW$T$452, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1294	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1294, DW_AT_type(*$C$DW$T$451)
	.dwendtag $C$DW$T$452

$C$DW$T$450	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$450, DW_AT_type(*$C$DW$T$453)
$C$DW$T$451	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$451, DW_AT_type(*$C$DW$T$450)
	.dwattr $C$DW$T$451, DW_AT_address_class(0x20)

$C$DW$T$458	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$458, DW_AT_name("hash_window")
	.dwattr $C$DW$T$458, DW_AT_byte_size(0x08)
$C$DW$1295	.dwtag  DW_TAG_member
	.dwattr $C$DW$1295, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1295, DW_AT_name("start_addr")
	.dwattr $C$DW$1295, DW_AT_TI_symbol_name("_start_addr")
	.dwattr $C$DW$1295, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1295, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1296	.dwtag  DW_TAG_member
	.dwattr $C$DW$1296, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1296, DW_AT_name("end_addr")
	.dwattr $C$DW$1296, DW_AT_TI_symbol_name("_end_addr")
	.dwattr $C$DW$1296, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1296, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$141	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$141, DW_AT_declaration
	.dwattr $C$DW$141, DW_AT_TI_symbol_name("___as__11hash_windowFRC11hash_window")
	.dwattr $C$DW$141, DW_AT_type(*$C$DW$T$454)
	.dwattr $C$DW$141, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1297	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1297, DW_AT_type(*$C$DW$T$456)
	.dwendtag $C$DW$141

	.dwendtag $C$DW$T$458

$C$DW$T$454	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$454, DW_AT_type(*$C$DW$T$458)
	.dwattr $C$DW$T$454, DW_AT_address_class(0x20)

$C$DW$T$457	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$457, DW_AT_type(*$C$DW$T$454)
	.dwattr $C$DW$T$457, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1298	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1298, DW_AT_type(*$C$DW$T$456)
	.dwendtag $C$DW$T$457

$C$DW$T$455	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$455, DW_AT_type(*$C$DW$T$458)
$C$DW$T$456	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$456, DW_AT_type(*$C$DW$T$455)
	.dwattr $C$DW$T$456, DW_AT_address_class(0x20)
$C$DW$T$733	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$733, DW_AT_type(*$C$DW$T$458)
	.dwattr $C$DW$T$733, DW_AT_address_class(0x20)

$C$DW$T$772	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$772, DW_AT_type(*$C$DW$T$458)
	.dwattr $C$DW$T$772, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1299	.dwtag  DW_TAG_subrange_type
	.dwendtag $C$DW$T$772


$C$DW$T$464	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$464, DW_AT_name("net_eth")
	.dwattr $C$DW$T$464, DW_AT_byte_size(0x0e)
$C$DW$1300	.dwtag  DW_TAG_member
	.dwattr $C$DW$1300, DW_AT_type(*$C$DW$T$459)
	.dwattr $C$DW$1300, DW_AT_name("dst")
	.dwattr $C$DW$1300, DW_AT_TI_symbol_name("_dst")
	.dwattr $C$DW$1300, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1300, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1301	.dwtag  DW_TAG_member
	.dwattr $C$DW$1301, DW_AT_type(*$C$DW$T$459)
	.dwattr $C$DW$1301, DW_AT_name("src")
	.dwattr $C$DW$1301, DW_AT_TI_symbol_name("_src")
	.dwattr $C$DW$1301, DW_AT_data_member_location[DW_OP_plus_uconst 0x6]
	.dwattr $C$DW$1301, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1302	.dwtag  DW_TAG_member
	.dwattr $C$DW$1302, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1302, DW_AT_name("protocol")
	.dwattr $C$DW$1302, DW_AT_TI_symbol_name("_protocol")
	.dwattr $C$DW$1302, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$1302, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$142	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$142, DW_AT_declaration
	.dwattr $C$DW$142, DW_AT_TI_symbol_name("___as__7net_ethFRC7net_eth")
	.dwattr $C$DW$142, DW_AT_type(*$C$DW$T$460)
	.dwattr $C$DW$142, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1303	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1303, DW_AT_type(*$C$DW$T$462)
	.dwendtag $C$DW$142

	.dwendtag $C$DW$T$464

$C$DW$T$460	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$460, DW_AT_type(*$C$DW$T$464)
	.dwattr $C$DW$T$460, DW_AT_address_class(0x20)

$C$DW$T$463	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$463, DW_AT_type(*$C$DW$T$460)
	.dwattr $C$DW$T$463, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1304	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1304, DW_AT_type(*$C$DW$T$462)
	.dwendtag $C$DW$T$463

$C$DW$T$461	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$461, DW_AT_type(*$C$DW$T$464)
$C$DW$T$462	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$462, DW_AT_type(*$C$DW$T$461)
	.dwattr $C$DW$T$462, DW_AT_address_class(0x20)
$C$DW$T$537	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$537, DW_AT_type(*$C$DW$T$464)
	.dwattr $C$DW$T$537, DW_AT_address_class(0x20)

$C$DW$T$469	.dwtag  DW_TAG_union_type
	.dwattr $C$DW$T$469, DW_AT_byte_size(0x04)
$C$DW$1305	.dwtag  DW_TAG_member
	.dwattr $C$DW$1305, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1305, DW_AT_name("src_ip")
	.dwattr $C$DW$1305, DW_AT_TI_symbol_name("_src_ip")
	.dwattr $C$DW$1305, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1305, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1306	.dwtag  DW_TAG_member
	.dwattr $C$DW$1306, DW_AT_type(*$C$DW$T$40)
	.dwattr $C$DW$1306, DW_AT_name("src_ip_char")
	.dwattr $C$DW$1306, DW_AT_TI_symbol_name("_src_ip_char")
	.dwattr $C$DW$1306, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1306, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$143	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$143, DW_AT_declaration
	.dwattr $C$DW$143, DW_AT_TI_symbol_name("___as__Q2_6net_ip4__C1FRCQ2_6net_ip4__C1")
	.dwattr $C$DW$143, DW_AT_type(*$C$DW$T$465)
	.dwattr $C$DW$143, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1307	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1307, DW_AT_type(*$C$DW$T$467)
	.dwendtag $C$DW$143

	.dwendtag $C$DW$T$469

$C$DW$T$465	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$465, DW_AT_type(*$C$DW$T$469)
	.dwattr $C$DW$T$465, DW_AT_address_class(0x20)

$C$DW$T$468	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$468, DW_AT_type(*$C$DW$T$465)
	.dwattr $C$DW$T$468, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1308	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1308, DW_AT_type(*$C$DW$T$467)
	.dwendtag $C$DW$T$468

$C$DW$T$466	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$466, DW_AT_type(*$C$DW$T$469)
$C$DW$T$467	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$467, DW_AT_type(*$C$DW$T$466)
	.dwattr $C$DW$T$467, DW_AT_address_class(0x20)

$C$DW$T$474	.dwtag  DW_TAG_union_type
	.dwattr $C$DW$T$474, DW_AT_byte_size(0x04)
$C$DW$1309	.dwtag  DW_TAG_member
	.dwattr $C$DW$1309, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1309, DW_AT_name("dst_ip")
	.dwattr $C$DW$1309, DW_AT_TI_symbol_name("_dst_ip")
	.dwattr $C$DW$1309, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1309, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1310	.dwtag  DW_TAG_member
	.dwattr $C$DW$1310, DW_AT_type(*$C$DW$T$40)
	.dwattr $C$DW$1310, DW_AT_name("dst_ip_char")
	.dwattr $C$DW$1310, DW_AT_TI_symbol_name("_dst_ip_char")
	.dwattr $C$DW$1310, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1310, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$144	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$144, DW_AT_declaration
	.dwattr $C$DW$144, DW_AT_TI_symbol_name("___as__Q2_6net_ip4__C2FRCQ2_6net_ip4__C2")
	.dwattr $C$DW$144, DW_AT_type(*$C$DW$T$470)
	.dwattr $C$DW$144, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1311	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1311, DW_AT_type(*$C$DW$T$472)
	.dwendtag $C$DW$144

	.dwendtag $C$DW$T$474

$C$DW$T$470	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$470, DW_AT_type(*$C$DW$T$474)
	.dwattr $C$DW$T$470, DW_AT_address_class(0x20)

$C$DW$T$473	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$473, DW_AT_type(*$C$DW$T$470)
	.dwattr $C$DW$T$473, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1312	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1312, DW_AT_type(*$C$DW$T$472)
	.dwendtag $C$DW$T$473

$C$DW$T$471	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$471, DW_AT_type(*$C$DW$T$474)
$C$DW$T$472	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$472, DW_AT_type(*$C$DW$T$471)
	.dwattr $C$DW$T$472, DW_AT_address_class(0x20)

$C$DW$T$479	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$479, DW_AT_name("net_ip")
	.dwattr $C$DW$T$479, DW_AT_byte_size(0x14)
$C$DW$1313	.dwtag  DW_TAG_member
	.dwattr $C$DW$1313, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$1313, DW_AT_name("version_ihl")
	.dwattr $C$DW$1313, DW_AT_TI_symbol_name("_version_ihl")
	.dwattr $C$DW$1313, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1313, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1314	.dwtag  DW_TAG_member
	.dwattr $C$DW$1314, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$1314, DW_AT_name("type_of_service")
	.dwattr $C$DW$1314, DW_AT_TI_symbol_name("_type_of_service")
	.dwattr $C$DW$1314, DW_AT_data_member_location[DW_OP_plus_uconst 0x1]
	.dwattr $C$DW$1314, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1315	.dwtag  DW_TAG_member
	.dwattr $C$DW$1315, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1315, DW_AT_name("total_length")
	.dwattr $C$DW$1315, DW_AT_TI_symbol_name("_total_length")
	.dwattr $C$DW$1315, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr $C$DW$1315, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1316	.dwtag  DW_TAG_member
	.dwattr $C$DW$1316, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1316, DW_AT_name("id")
	.dwattr $C$DW$1316, DW_AT_TI_symbol_name("_id")
	.dwattr $C$DW$1316, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1316, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1317	.dwtag  DW_TAG_member
	.dwattr $C$DW$1317, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1317, DW_AT_name("flags_offset")
	.dwattr $C$DW$1317, DW_AT_TI_symbol_name("_flags_offset")
	.dwattr $C$DW$1317, DW_AT_data_member_location[DW_OP_plus_uconst 0x6]
	.dwattr $C$DW$1317, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1318	.dwtag  DW_TAG_member
	.dwattr $C$DW$1318, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$1318, DW_AT_name("ttl")
	.dwattr $C$DW$1318, DW_AT_TI_symbol_name("_ttl")
	.dwattr $C$DW$1318, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1318, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1319	.dwtag  DW_TAG_member
	.dwattr $C$DW$1319, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$1319, DW_AT_name("protocol")
	.dwattr $C$DW$1319, DW_AT_TI_symbol_name("_protocol")
	.dwattr $C$DW$1319, DW_AT_data_member_location[DW_OP_plus_uconst 0x9]
	.dwattr $C$DW$1319, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1320	.dwtag  DW_TAG_member
	.dwattr $C$DW$1320, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1320, DW_AT_name("checksumm")
	.dwattr $C$DW$1320, DW_AT_TI_symbol_name("_checksumm")
	.dwattr $C$DW$1320, DW_AT_data_member_location[DW_OP_plus_uconst 0xa]
	.dwattr $C$DW$1320, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1321	.dwtag  DW_TAG_member
	.dwattr $C$DW$1321, DW_AT_type(*$C$DW$T$469)
	.dwattr $C$DW$1321, DW_AT_name("$P$T0")
	.dwattr $C$DW$1321, DW_AT_TI_symbol_name("_$P$T0")
	.dwattr $C$DW$1321, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$1321, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1322	.dwtag  DW_TAG_member
	.dwattr $C$DW$1322, DW_AT_type(*$C$DW$T$474)
	.dwattr $C$DW$1322, DW_AT_name("$P$T1")
	.dwattr $C$DW$1322, DW_AT_TI_symbol_name("_$P$T1")
	.dwattr $C$DW$1322, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$1322, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$145	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$145, DW_AT_declaration
	.dwattr $C$DW$145, DW_AT_TI_symbol_name("___as__6net_ipFRC6net_ip")
	.dwattr $C$DW$145, DW_AT_type(*$C$DW$T$475)
	.dwattr $C$DW$145, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1323	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1323, DW_AT_type(*$C$DW$T$477)
	.dwendtag $C$DW$145

	.dwendtag $C$DW$T$479

$C$DW$T$475	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$475, DW_AT_type(*$C$DW$T$479)
	.dwattr $C$DW$T$475, DW_AT_address_class(0x20)

$C$DW$T$478	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$478, DW_AT_type(*$C$DW$T$475)
	.dwattr $C$DW$T$478, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1324	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1324, DW_AT_type(*$C$DW$T$477)
	.dwendtag $C$DW$T$478

$C$DW$T$476	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$476, DW_AT_type(*$C$DW$T$479)
$C$DW$T$477	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$477, DW_AT_type(*$C$DW$T$476)
	.dwattr $C$DW$T$477, DW_AT_address_class(0x20)
$C$DW$T$543	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$543, DW_AT_type(*$C$DW$T$479)
	.dwattr $C$DW$T$543, DW_AT_address_class(0x20)

$C$DW$T$484	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$484, DW_AT_name("net_arp")
	.dwattr $C$DW$T$484, DW_AT_byte_size(0x1c)
$C$DW$1325	.dwtag  DW_TAG_member
	.dwattr $C$DW$1325, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1325, DW_AT_name("hrd_addr_fmt")
	.dwattr $C$DW$1325, DW_AT_TI_symbol_name("_hrd_addr_fmt")
	.dwattr $C$DW$1325, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1325, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1326	.dwtag  DW_TAG_member
	.dwattr $C$DW$1326, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1326, DW_AT_name("proto_addr_fmt")
	.dwattr $C$DW$1326, DW_AT_TI_symbol_name("_proto_addr_fmt")
	.dwattr $C$DW$1326, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr $C$DW$1326, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1327	.dwtag  DW_TAG_member
	.dwattr $C$DW$1327, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$1327, DW_AT_name("hdr_addr_len")
	.dwattr $C$DW$1327, DW_AT_TI_symbol_name("_hdr_addr_len")
	.dwattr $C$DW$1327, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1327, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1328	.dwtag  DW_TAG_member
	.dwattr $C$DW$1328, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$1328, DW_AT_name("proto_addr_len")
	.dwattr $C$DW$1328, DW_AT_TI_symbol_name("_proto_addr_len")
	.dwattr $C$DW$1328, DW_AT_data_member_location[DW_OP_plus_uconst 0x5]
	.dwattr $C$DW$1328, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1329	.dwtag  DW_TAG_member
	.dwattr $C$DW$1329, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1329, DW_AT_name("opcode")
	.dwattr $C$DW$1329, DW_AT_TI_symbol_name("_opcode")
	.dwattr $C$DW$1329, DW_AT_data_member_location[DW_OP_plus_uconst 0x6]
	.dwattr $C$DW$1329, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1330	.dwtag  DW_TAG_member
	.dwattr $C$DW$1330, DW_AT_type(*$C$DW$T$459)
	.dwattr $C$DW$1330, DW_AT_name("sender_mac")
	.dwattr $C$DW$1330, DW_AT_TI_symbol_name("_sender_mac")
	.dwattr $C$DW$1330, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1330, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1331	.dwtag  DW_TAG_member
	.dwattr $C$DW$1331, DW_AT_type(*$C$DW$T$40)
	.dwattr $C$DW$1331, DW_AT_name("sender_ip")
	.dwattr $C$DW$1331, DW_AT_TI_symbol_name("_sender_ip")
	.dwattr $C$DW$1331, DW_AT_data_member_location[DW_OP_plus_uconst 0xe]
	.dwattr $C$DW$1331, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1332	.dwtag  DW_TAG_member
	.dwattr $C$DW$1332, DW_AT_type(*$C$DW$T$459)
	.dwattr $C$DW$1332, DW_AT_name("target_mac")
	.dwattr $C$DW$1332, DW_AT_TI_symbol_name("_target_mac")
	.dwattr $C$DW$1332, DW_AT_data_member_location[DW_OP_plus_uconst 0x12]
	.dwattr $C$DW$1332, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1333	.dwtag  DW_TAG_member
	.dwattr $C$DW$1333, DW_AT_type(*$C$DW$T$40)
	.dwattr $C$DW$1333, DW_AT_name("target_ip")
	.dwattr $C$DW$1333, DW_AT_TI_symbol_name("_target_ip")
	.dwattr $C$DW$1333, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$1333, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$146	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$146, DW_AT_declaration
	.dwattr $C$DW$146, DW_AT_TI_symbol_name("___as__7net_arpFRC7net_arp")
	.dwattr $C$DW$146, DW_AT_type(*$C$DW$T$480)
	.dwattr $C$DW$146, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1334	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1334, DW_AT_type(*$C$DW$T$482)
	.dwendtag $C$DW$146

	.dwendtag $C$DW$T$484

$C$DW$T$480	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$480, DW_AT_type(*$C$DW$T$484)
	.dwattr $C$DW$T$480, DW_AT_address_class(0x20)

$C$DW$T$483	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$483, DW_AT_type(*$C$DW$T$480)
	.dwattr $C$DW$T$483, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1335	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1335, DW_AT_type(*$C$DW$T$482)
	.dwendtag $C$DW$T$483

$C$DW$T$481	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$481, DW_AT_type(*$C$DW$T$484)
$C$DW$T$482	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$482, DW_AT_type(*$C$DW$T$481)
	.dwattr $C$DW$T$482, DW_AT_address_class(0x20)
$C$DW$T$544	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$544, DW_AT_type(*$C$DW$T$484)
	.dwattr $C$DW$T$544, DW_AT_address_class(0x20)

$C$DW$T$489	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$489, DW_AT_name("net_udp")
	.dwattr $C$DW$T$489, DW_AT_byte_size(0x08)
$C$DW$1336	.dwtag  DW_TAG_member
	.dwattr $C$DW$1336, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1336, DW_AT_name("src_port")
	.dwattr $C$DW$1336, DW_AT_TI_symbol_name("_src_port")
	.dwattr $C$DW$1336, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1336, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1337	.dwtag  DW_TAG_member
	.dwattr $C$DW$1337, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1337, DW_AT_name("dst_port")
	.dwattr $C$DW$1337, DW_AT_TI_symbol_name("_dst_port")
	.dwattr $C$DW$1337, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr $C$DW$1337, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1338	.dwtag  DW_TAG_member
	.dwattr $C$DW$1338, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1338, DW_AT_name("length")
	.dwattr $C$DW$1338, DW_AT_TI_symbol_name("_length")
	.dwattr $C$DW$1338, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1338, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1339	.dwtag  DW_TAG_member
	.dwattr $C$DW$1339, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1339, DW_AT_name("checksumm")
	.dwattr $C$DW$1339, DW_AT_TI_symbol_name("_checksumm")
	.dwattr $C$DW$1339, DW_AT_data_member_location[DW_OP_plus_uconst 0x6]
	.dwattr $C$DW$1339, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$147	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$147, DW_AT_declaration
	.dwattr $C$DW$147, DW_AT_TI_symbol_name("___as__7net_udpFRC7net_udp")
	.dwattr $C$DW$147, DW_AT_type(*$C$DW$T$485)
	.dwattr $C$DW$147, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1340	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1340, DW_AT_type(*$C$DW$T$487)
	.dwendtag $C$DW$147

	.dwendtag $C$DW$T$489

$C$DW$T$485	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$485, DW_AT_type(*$C$DW$T$489)
	.dwattr $C$DW$T$485, DW_AT_address_class(0x20)

$C$DW$T$488	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$488, DW_AT_type(*$C$DW$T$485)
	.dwattr $C$DW$T$488, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1341	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1341, DW_AT_type(*$C$DW$T$487)
	.dwendtag $C$DW$T$488

$C$DW$T$486	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$486, DW_AT_type(*$C$DW$T$489)
$C$DW$T$487	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$487, DW_AT_type(*$C$DW$T$486)
	.dwattr $C$DW$T$487, DW_AT_address_class(0x20)
$C$DW$T$551	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$551, DW_AT_type(*$C$DW$T$489)
	.dwattr $C$DW$T$551, DW_AT_address_class(0x20)

$C$DW$T$494	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$494, DW_AT_name("net_tcp")
	.dwattr $C$DW$T$494, DW_AT_byte_size(0x14)
$C$DW$1342	.dwtag  DW_TAG_member
	.dwattr $C$DW$1342, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1342, DW_AT_name("src_port")
	.dwattr $C$DW$1342, DW_AT_TI_symbol_name("_src_port")
	.dwattr $C$DW$1342, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1342, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1343	.dwtag  DW_TAG_member
	.dwattr $C$DW$1343, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1343, DW_AT_name("dst_port")
	.dwattr $C$DW$1343, DW_AT_TI_symbol_name("_dst_port")
	.dwattr $C$DW$1343, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr $C$DW$1343, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1344	.dwtag  DW_TAG_member
	.dwattr $C$DW$1344, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1344, DW_AT_name("sequence_number")
	.dwattr $C$DW$1344, DW_AT_TI_symbol_name("_sequence_number")
	.dwattr $C$DW$1344, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1344, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1345	.dwtag  DW_TAG_member
	.dwattr $C$DW$1345, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1345, DW_AT_name("acknowledgement_number")
	.dwattr $C$DW$1345, DW_AT_TI_symbol_name("_acknowledgement_number")
	.dwattr $C$DW$1345, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1345, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1346	.dwtag  DW_TAG_member
	.dwattr $C$DW$1346, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$1346, DW_AT_name("offset_rsvd")
	.dwattr $C$DW$1346, DW_AT_TI_symbol_name("_offset_rsvd")
	.dwattr $C$DW$1346, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$1346, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1347	.dwtag  DW_TAG_member
	.dwattr $C$DW$1347, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$1347, DW_AT_name("rsvd_flags")
	.dwattr $C$DW$1347, DW_AT_TI_symbol_name("_rsvd_flags")
	.dwattr $C$DW$1347, DW_AT_data_member_location[DW_OP_plus_uconst 0xd]
	.dwattr $C$DW$1347, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1348	.dwtag  DW_TAG_member
	.dwattr $C$DW$1348, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1348, DW_AT_name("window")
	.dwattr $C$DW$1348, DW_AT_TI_symbol_name("_window")
	.dwattr $C$DW$1348, DW_AT_data_member_location[DW_OP_plus_uconst 0xe]
	.dwattr $C$DW$1348, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1349	.dwtag  DW_TAG_member
	.dwattr $C$DW$1349, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1349, DW_AT_name("checksumm")
	.dwattr $C$DW$1349, DW_AT_TI_symbol_name("_checksumm")
	.dwattr $C$DW$1349, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$1349, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1350	.dwtag  DW_TAG_member
	.dwattr $C$DW$1350, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1350, DW_AT_name("urgent_point")
	.dwattr $C$DW$1350, DW_AT_TI_symbol_name("_urgent_point")
	.dwattr $C$DW$1350, DW_AT_data_member_location[DW_OP_plus_uconst 0x12]
	.dwattr $C$DW$1350, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$148	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$148, DW_AT_declaration
	.dwattr $C$DW$148, DW_AT_TI_symbol_name("___as__7net_tcpFRC7net_tcp")
	.dwattr $C$DW$148, DW_AT_type(*$C$DW$T$490)
	.dwattr $C$DW$148, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1351	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1351, DW_AT_type(*$C$DW$T$492)
	.dwendtag $C$DW$148

	.dwendtag $C$DW$T$494

$C$DW$T$490	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$490, DW_AT_type(*$C$DW$T$494)
	.dwattr $C$DW$T$490, DW_AT_address_class(0x20)

$C$DW$T$493	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$493, DW_AT_type(*$C$DW$T$490)
	.dwattr $C$DW$T$493, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1352	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1352, DW_AT_type(*$C$DW$T$492)
	.dwendtag $C$DW$T$493

$C$DW$T$491	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$491, DW_AT_type(*$C$DW$T$494)
$C$DW$T$492	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$492, DW_AT_type(*$C$DW$T$491)
	.dwattr $C$DW$T$492, DW_AT_address_class(0x20)
$C$DW$T$550	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$550, DW_AT_type(*$C$DW$T$494)
	.dwattr $C$DW$T$550, DW_AT_address_class(0x20)

$C$DW$T$499	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$499, DW_AT_byte_size(0x04)
$C$DW$1353	.dwtag  DW_TAG_member
	.dwattr $C$DW$1353, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1353, DW_AT_name("id")
	.dwattr $C$DW$1353, DW_AT_TI_symbol_name("_id")
	.dwattr $C$DW$1353, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1353, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1354	.dwtag  DW_TAG_member
	.dwattr $C$DW$1354, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1354, DW_AT_name("sequence")
	.dwattr $C$DW$1354, DW_AT_TI_symbol_name("_sequence")
	.dwattr $C$DW$1354, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr $C$DW$1354, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$149	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$149, DW_AT_declaration
	.dwattr $C$DW$149, DW_AT_TI_symbol_name("___as__Q3_8net_icmp4__C14__C1FRCQ3_8net_icmp4__C14__C1")
	.dwattr $C$DW$149, DW_AT_type(*$C$DW$T$495)
	.dwattr $C$DW$149, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1355	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1355, DW_AT_type(*$C$DW$T$497)
	.dwendtag $C$DW$149

	.dwendtag $C$DW$T$499

$C$DW$T$495	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$495, DW_AT_type(*$C$DW$T$499)
	.dwattr $C$DW$T$495, DW_AT_address_class(0x20)

$C$DW$T$498	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$498, DW_AT_type(*$C$DW$T$495)
	.dwattr $C$DW$T$498, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1356	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1356, DW_AT_type(*$C$DW$T$497)
	.dwendtag $C$DW$T$498

$C$DW$T$496	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$496, DW_AT_type(*$C$DW$T$499)
$C$DW$T$497	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$497, DW_AT_type(*$C$DW$T$496)
	.dwattr $C$DW$T$497, DW_AT_address_class(0x20)

$C$DW$T$504	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$504, DW_AT_byte_size(0x04)
$C$DW$1357	.dwtag  DW_TAG_member
	.dwattr $C$DW$1357, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1357, DW_AT_name("__unused")
	.dwattr $C$DW$1357, DW_AT_TI_symbol_name("___unused")
	.dwattr $C$DW$1357, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1357, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1358	.dwtag  DW_TAG_member
	.dwattr $C$DW$1358, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1358, DW_AT_name("mtu")
	.dwattr $C$DW$1358, DW_AT_TI_symbol_name("_mtu")
	.dwattr $C$DW$1358, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr $C$DW$1358, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$150	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$150, DW_AT_declaration
	.dwattr $C$DW$150, DW_AT_TI_symbol_name("___as__Q3_8net_icmp4__C14__C2FRCQ3_8net_icmp4__C14__C2")
	.dwattr $C$DW$150, DW_AT_type(*$C$DW$T$500)
	.dwattr $C$DW$150, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1359	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1359, DW_AT_type(*$C$DW$T$502)
	.dwendtag $C$DW$150

	.dwendtag $C$DW$T$504

$C$DW$T$500	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$500, DW_AT_type(*$C$DW$T$504)
	.dwattr $C$DW$T$500, DW_AT_address_class(0x20)

$C$DW$T$503	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$503, DW_AT_type(*$C$DW$T$500)
	.dwattr $C$DW$T$503, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1360	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1360, DW_AT_type(*$C$DW$T$502)
	.dwendtag $C$DW$T$503

$C$DW$T$501	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$501, DW_AT_type(*$C$DW$T$504)
$C$DW$T$502	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$502, DW_AT_type(*$C$DW$T$501)
	.dwattr $C$DW$T$502, DW_AT_address_class(0x20)

$C$DW$T$509	.dwtag  DW_TAG_union_type
	.dwattr $C$DW$T$509, DW_AT_byte_size(0x04)
$C$DW$1361	.dwtag  DW_TAG_member
	.dwattr $C$DW$1361, DW_AT_type(*$C$DW$T$499)
	.dwattr $C$DW$1361, DW_AT_name("echo")
	.dwattr $C$DW$1361, DW_AT_TI_symbol_name("_echo")
	.dwattr $C$DW$1361, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1361, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1362	.dwtag  DW_TAG_member
	.dwattr $C$DW$1362, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1362, DW_AT_name("gateway")
	.dwattr $C$DW$1362, DW_AT_TI_symbol_name("_gateway")
	.dwattr $C$DW$1362, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1362, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1363	.dwtag  DW_TAG_member
	.dwattr $C$DW$1363, DW_AT_type(*$C$DW$T$504)
	.dwattr $C$DW$1363, DW_AT_name("frag")
	.dwattr $C$DW$1363, DW_AT_TI_symbol_name("_frag")
	.dwattr $C$DW$1363, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1363, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$151	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$151, DW_AT_declaration
	.dwattr $C$DW$151, DW_AT_TI_symbol_name("___as__Q2_8net_icmp4__C1FRCQ2_8net_icmp4__C1")
	.dwattr $C$DW$151, DW_AT_type(*$C$DW$T$505)
	.dwattr $C$DW$151, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1364	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1364, DW_AT_type(*$C$DW$T$507)
	.dwendtag $C$DW$151

	.dwendtag $C$DW$T$509

$C$DW$T$505	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$505, DW_AT_type(*$C$DW$T$509)
	.dwattr $C$DW$T$505, DW_AT_address_class(0x20)

$C$DW$T$508	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$508, DW_AT_type(*$C$DW$T$505)
	.dwattr $C$DW$T$508, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1365	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1365, DW_AT_type(*$C$DW$T$507)
	.dwendtag $C$DW$T$508

$C$DW$T$506	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$506, DW_AT_type(*$C$DW$T$509)
$C$DW$T$507	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$507, DW_AT_type(*$C$DW$T$506)
	.dwattr $C$DW$T$507, DW_AT_address_class(0x20)

$C$DW$T$514	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$514, DW_AT_name("net_icmp")
	.dwattr $C$DW$T$514, DW_AT_byte_size(0x08)
$C$DW$1366	.dwtag  DW_TAG_member
	.dwattr $C$DW$1366, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$1366, DW_AT_name("type")
	.dwattr $C$DW$1366, DW_AT_TI_symbol_name("_type")
	.dwattr $C$DW$1366, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1366, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1367	.dwtag  DW_TAG_member
	.dwattr $C$DW$1367, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$1367, DW_AT_name("code")
	.dwattr $C$DW$1367, DW_AT_TI_symbol_name("_code")
	.dwattr $C$DW$1367, DW_AT_data_member_location[DW_OP_plus_uconst 0x1]
	.dwattr $C$DW$1367, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1368	.dwtag  DW_TAG_member
	.dwattr $C$DW$1368, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1368, DW_AT_name("checksum")
	.dwattr $C$DW$1368, DW_AT_TI_symbol_name("_checksum")
	.dwattr $C$DW$1368, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr $C$DW$1368, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1369	.dwtag  DW_TAG_member
	.dwattr $C$DW$1369, DW_AT_type(*$C$DW$T$509)
	.dwattr $C$DW$1369, DW_AT_name("un")
	.dwattr $C$DW$1369, DW_AT_TI_symbol_name("_un")
	.dwattr $C$DW$1369, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1369, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$152	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$152, DW_AT_declaration
	.dwattr $C$DW$152, DW_AT_TI_symbol_name("___as__8net_icmpFRC8net_icmp")
	.dwattr $C$DW$152, DW_AT_type(*$C$DW$T$510)
	.dwattr $C$DW$152, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1370	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1370, DW_AT_type(*$C$DW$T$512)
	.dwendtag $C$DW$152

	.dwendtag $C$DW$T$514

$C$DW$T$510	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$510, DW_AT_type(*$C$DW$T$514)
	.dwattr $C$DW$T$510, DW_AT_address_class(0x20)

$C$DW$T$513	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$513, DW_AT_type(*$C$DW$T$510)
	.dwattr $C$DW$T$513, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1371	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1371, DW_AT_type(*$C$DW$T$512)
	.dwendtag $C$DW$T$513

$C$DW$T$511	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$511, DW_AT_type(*$C$DW$T$514)
$C$DW$T$512	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$512, DW_AT_type(*$C$DW$T$511)
	.dwattr $C$DW$T$512, DW_AT_address_class(0x20)
$C$DW$T$552	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$552, DW_AT_type(*$C$DW$T$514)
	.dwattr $C$DW$T$552, DW_AT_address_class(0x20)

$C$DW$T$519	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$519, DW_AT_name("net_igmp_v2")
	.dwattr $C$DW$T$519, DW_AT_byte_size(0x08)
$C$DW$1372	.dwtag  DW_TAG_member
	.dwattr $C$DW$1372, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$1372, DW_AT_name("type")
	.dwattr $C$DW$1372, DW_AT_TI_symbol_name("_type")
	.dwattr $C$DW$1372, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1372, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1373	.dwtag  DW_TAG_member
	.dwattr $C$DW$1373, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$1373, DW_AT_name("max_response_time")
	.dwattr $C$DW$1373, DW_AT_TI_symbol_name("_max_response_time")
	.dwattr $C$DW$1373, DW_AT_data_member_location[DW_OP_plus_uconst 0x1]
	.dwattr $C$DW$1373, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1374	.dwtag  DW_TAG_member
	.dwattr $C$DW$1374, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1374, DW_AT_name("check_summ")
	.dwattr $C$DW$1374, DW_AT_TI_symbol_name("_check_summ")
	.dwattr $C$DW$1374, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr $C$DW$1374, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1375	.dwtag  DW_TAG_member
	.dwattr $C$DW$1375, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1375, DW_AT_name("group_address")
	.dwattr $C$DW$1375, DW_AT_TI_symbol_name("_group_address")
	.dwattr $C$DW$1375, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1375, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$153	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$153, DW_AT_declaration
	.dwattr $C$DW$153, DW_AT_TI_symbol_name("___as__11net_igmp_v2FRC11net_igmp_v2")
	.dwattr $C$DW$153, DW_AT_type(*$C$DW$T$515)
	.dwattr $C$DW$153, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1376	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1376, DW_AT_type(*$C$DW$T$517)
	.dwendtag $C$DW$153

	.dwendtag $C$DW$T$519

$C$DW$T$515	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$515, DW_AT_type(*$C$DW$T$519)
	.dwattr $C$DW$T$515, DW_AT_address_class(0x20)

$C$DW$T$518	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$518, DW_AT_type(*$C$DW$T$515)
	.dwattr $C$DW$T$518, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1377	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1377, DW_AT_type(*$C$DW$T$517)
	.dwendtag $C$DW$T$518

$C$DW$T$516	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$516, DW_AT_type(*$C$DW$T$519)
$C$DW$T$517	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$517, DW_AT_type(*$C$DW$T$516)
	.dwattr $C$DW$T$517, DW_AT_address_class(0x20)

$C$DW$T$524	.dwtag  DW_TAG_union_type
	.dwattr $C$DW$T$524, DW_AT_name("net_igmp")
	.dwattr $C$DW$T$524, DW_AT_byte_size(0x08)
$C$DW$1378	.dwtag  DW_TAG_member
	.dwattr $C$DW$1378, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$1378, DW_AT_name("type")
	.dwattr $C$DW$1378, DW_AT_TI_symbol_name("_type")
	.dwattr $C$DW$1378, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1378, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1379	.dwtag  DW_TAG_member
	.dwattr $C$DW$1379, DW_AT_type(*$C$DW$T$519)
	.dwattr $C$DW$1379, DW_AT_name("v2")
	.dwattr $C$DW$1379, DW_AT_TI_symbol_name("_v2")
	.dwattr $C$DW$1379, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1379, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$154	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$154, DW_AT_declaration
	.dwattr $C$DW$154, DW_AT_TI_symbol_name("___as__8net_igmpFRC8net_igmp")
	.dwattr $C$DW$154, DW_AT_type(*$C$DW$T$520)
	.dwattr $C$DW$154, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1380	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1380, DW_AT_type(*$C$DW$T$522)
	.dwendtag $C$DW$154

	.dwendtag $C$DW$T$524

$C$DW$T$520	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$520, DW_AT_type(*$C$DW$T$524)
	.dwattr $C$DW$T$520, DW_AT_address_class(0x20)

$C$DW$T$523	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$523, DW_AT_type(*$C$DW$T$520)
	.dwattr $C$DW$T$523, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1381	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1381, DW_AT_type(*$C$DW$T$522)
	.dwendtag $C$DW$T$523

$C$DW$T$521	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$521, DW_AT_type(*$C$DW$T$524)
$C$DW$T$522	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$522, DW_AT_type(*$C$DW$T$521)
	.dwattr $C$DW$T$522, DW_AT_address_class(0x20)
$C$DW$T$553	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$553, DW_AT_type(*$C$DW$T$524)
	.dwattr $C$DW$T$553, DW_AT_address_class(0x20)

$C$DW$T$530	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$530, DW_AT_name("net_snap")
	.dwattr $C$DW$T$530, DW_AT_byte_size(0x08)
$C$DW$1382	.dwtag  DW_TAG_member
	.dwattr $C$DW$1382, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$1382, DW_AT_name("dsap")
	.dwattr $C$DW$1382, DW_AT_TI_symbol_name("_dsap")
	.dwattr $C$DW$1382, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1382, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1383	.dwtag  DW_TAG_member
	.dwattr $C$DW$1383, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$1383, DW_AT_name("ssap")
	.dwattr $C$DW$1383, DW_AT_TI_symbol_name("_ssap")
	.dwattr $C$DW$1383, DW_AT_data_member_location[DW_OP_plus_uconst 0x1]
	.dwattr $C$DW$1383, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1384	.dwtag  DW_TAG_member
	.dwattr $C$DW$1384, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$1384, DW_AT_name("ctrl")
	.dwattr $C$DW$1384, DW_AT_TI_symbol_name("_ctrl")
	.dwattr $C$DW$1384, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr $C$DW$1384, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1385	.dwtag  DW_TAG_member
	.dwattr $C$DW$1385, DW_AT_type(*$C$DW$T$525)
	.dwattr $C$DW$1385, DW_AT_name("out_id")
	.dwattr $C$DW$1385, DW_AT_TI_symbol_name("_out_id")
	.dwattr $C$DW$1385, DW_AT_data_member_location[DW_OP_plus_uconst 0x3]
	.dwattr $C$DW$1385, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1386	.dwtag  DW_TAG_member
	.dwattr $C$DW$1386, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1386, DW_AT_name("h_proto")
	.dwattr $C$DW$1386, DW_AT_TI_symbol_name("_h_proto")
	.dwattr $C$DW$1386, DW_AT_data_member_location[DW_OP_plus_uconst 0x6]
	.dwattr $C$DW$1386, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$155	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$155, DW_AT_declaration
	.dwattr $C$DW$155, DW_AT_TI_symbol_name("___as__8net_snapFRC8net_snap")
	.dwattr $C$DW$155, DW_AT_type(*$C$DW$T$526)
	.dwattr $C$DW$155, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1387	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1387, DW_AT_type(*$C$DW$T$528)
	.dwendtag $C$DW$155

	.dwendtag $C$DW$T$530

$C$DW$T$526	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$526, DW_AT_type(*$C$DW$T$530)
	.dwattr $C$DW$T$526, DW_AT_address_class(0x20)

$C$DW$T$529	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$529, DW_AT_type(*$C$DW$T$526)
	.dwattr $C$DW$T$529, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1388	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1388, DW_AT_type(*$C$DW$T$528)
	.dwendtag $C$DW$T$529

$C$DW$T$527	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$527, DW_AT_type(*$C$DW$T$530)
$C$DW$T$528	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$528, DW_AT_type(*$C$DW$T$527)
	.dwattr $C$DW$T$528, DW_AT_address_class(0x20)
$C$DW$T$559	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$559, DW_AT_type(*$C$DW$T$530)
	.dwattr $C$DW$T$559, DW_AT_address_class(0x20)

$C$DW$T$535	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$535, DW_AT_name("net_8021q")
	.dwattr $C$DW$T$535, DW_AT_byte_size(0x04)
$C$DW$1389	.dwtag  DW_TAG_member
	.dwattr $C$DW$1389, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1389, DW_AT_name("flags")
	.dwattr $C$DW$1389, DW_AT_TI_symbol_name("_flags")
	.dwattr $C$DW$1389, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1389, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1390	.dwtag  DW_TAG_member
	.dwattr $C$DW$1390, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1390, DW_AT_name("h_proto")
	.dwattr $C$DW$1390, DW_AT_TI_symbol_name("_h_proto")
	.dwattr $C$DW$1390, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr $C$DW$1390, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$156	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$156, DW_AT_declaration
	.dwattr $C$DW$156, DW_AT_TI_symbol_name("___as__9net_8021qFRC9net_8021q")
	.dwattr $C$DW$156, DW_AT_type(*$C$DW$T$531)
	.dwattr $C$DW$156, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1391	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1391, DW_AT_type(*$C$DW$T$533)
	.dwendtag $C$DW$156

	.dwendtag $C$DW$T$535

$C$DW$T$531	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$531, DW_AT_type(*$C$DW$T$535)
	.dwattr $C$DW$T$531, DW_AT_address_class(0x20)

$C$DW$T$534	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$534, DW_AT_type(*$C$DW$T$531)
	.dwattr $C$DW$T$534, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1392	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1392, DW_AT_type(*$C$DW$T$533)
	.dwendtag $C$DW$T$534

$C$DW$T$532	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$532, DW_AT_type(*$C$DW$T$535)
$C$DW$T$533	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$533, DW_AT_type(*$C$DW$T$532)
	.dwattr $C$DW$T$533, DW_AT_address_class(0x20)

$C$DW$T$542	.dwtag  DW_TAG_union_type
	.dwattr $C$DW$T$542, DW_AT_byte_size(0x04)
$C$DW$1393	.dwtag  DW_TAG_member
	.dwattr $C$DW$1393, DW_AT_type(*$C$DW$T$536)
	.dwattr $C$DW$1393, DW_AT_name("channel_p")
	.dwattr $C$DW$1393, DW_AT_TI_symbol_name("_channel_p")
	.dwattr $C$DW$1393, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1393, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1394	.dwtag  DW_TAG_member
	.dwattr $C$DW$1394, DW_AT_type(*$C$DW$T$537)
	.dwattr $C$DW$1394, DW_AT_name("eth")
	.dwattr $C$DW$1394, DW_AT_TI_symbol_name("_eth")
	.dwattr $C$DW$1394, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1394, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$157	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$157, DW_AT_declaration
	.dwattr $C$DW$157, DW_AT_TI_symbol_name("___as__Q2_10net_packet4__C1FRCQ2_10net_packet4__C1")
	.dwattr $C$DW$157, DW_AT_type(*$C$DW$T$538)
	.dwattr $C$DW$157, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1395	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1395, DW_AT_type(*$C$DW$T$540)
	.dwendtag $C$DW$157

	.dwendtag $C$DW$T$542

$C$DW$T$538	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$538, DW_AT_type(*$C$DW$T$542)
	.dwattr $C$DW$T$538, DW_AT_address_class(0x20)

$C$DW$T$541	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$541, DW_AT_type(*$C$DW$T$538)
	.dwattr $C$DW$T$541, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1396	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1396, DW_AT_type(*$C$DW$T$540)
	.dwendtag $C$DW$T$541

$C$DW$T$539	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$539, DW_AT_type(*$C$DW$T$542)
$C$DW$T$540	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$540, DW_AT_type(*$C$DW$T$539)
	.dwattr $C$DW$T$540, DW_AT_address_class(0x20)

$C$DW$T$549	.dwtag  DW_TAG_union_type
	.dwattr $C$DW$T$549, DW_AT_byte_size(0x04)
$C$DW$1397	.dwtag  DW_TAG_member
	.dwattr $C$DW$1397, DW_AT_type(*$C$DW$T$536)
	.dwattr $C$DW$1397, DW_AT_name("net_p")
	.dwattr $C$DW$1397, DW_AT_TI_symbol_name("_net_p")
	.dwattr $C$DW$1397, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1397, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1398	.dwtag  DW_TAG_member
	.dwattr $C$DW$1398, DW_AT_type(*$C$DW$T$543)
	.dwattr $C$DW$1398, DW_AT_name("ip")
	.dwattr $C$DW$1398, DW_AT_TI_symbol_name("_ip")
	.dwattr $C$DW$1398, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1398, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1399	.dwtag  DW_TAG_member
	.dwattr $C$DW$1399, DW_AT_type(*$C$DW$T$544)
	.dwattr $C$DW$1399, DW_AT_name("arp")
	.dwattr $C$DW$1399, DW_AT_TI_symbol_name("_arp")
	.dwattr $C$DW$1399, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1399, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$158	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$158, DW_AT_declaration
	.dwattr $C$DW$158, DW_AT_TI_symbol_name("___as__Q2_10net_packet4__C2FRCQ2_10net_packet4__C2")
	.dwattr $C$DW$158, DW_AT_type(*$C$DW$T$545)
	.dwattr $C$DW$158, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1400	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1400, DW_AT_type(*$C$DW$T$547)
	.dwendtag $C$DW$158

	.dwendtag $C$DW$T$549

$C$DW$T$545	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$545, DW_AT_type(*$C$DW$T$549)
	.dwattr $C$DW$T$545, DW_AT_address_class(0x20)

$C$DW$T$548	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$548, DW_AT_type(*$C$DW$T$545)
	.dwattr $C$DW$T$548, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1401	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1401, DW_AT_type(*$C$DW$T$547)
	.dwendtag $C$DW$T$548

$C$DW$T$546	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$546, DW_AT_type(*$C$DW$T$549)
$C$DW$T$547	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$547, DW_AT_type(*$C$DW$T$546)
	.dwattr $C$DW$T$547, DW_AT_address_class(0x20)

$C$DW$T$558	.dwtag  DW_TAG_union_type
	.dwattr $C$DW$T$558, DW_AT_byte_size(0x04)
$C$DW$1402	.dwtag  DW_TAG_member
	.dwattr $C$DW$1402, DW_AT_type(*$C$DW$T$536)
	.dwattr $C$DW$1402, DW_AT_name("transp_p")
	.dwattr $C$DW$1402, DW_AT_TI_symbol_name("_transp_p")
	.dwattr $C$DW$1402, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1402, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1403	.dwtag  DW_TAG_member
	.dwattr $C$DW$1403, DW_AT_type(*$C$DW$T$550)
	.dwattr $C$DW$1403, DW_AT_name("tcp")
	.dwattr $C$DW$1403, DW_AT_TI_symbol_name("_tcp")
	.dwattr $C$DW$1403, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1403, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1404	.dwtag  DW_TAG_member
	.dwattr $C$DW$1404, DW_AT_type(*$C$DW$T$551)
	.dwattr $C$DW$1404, DW_AT_name("udp")
	.dwattr $C$DW$1404, DW_AT_TI_symbol_name("_udp")
	.dwattr $C$DW$1404, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1404, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1405	.dwtag  DW_TAG_member
	.dwattr $C$DW$1405, DW_AT_type(*$C$DW$T$552)
	.dwattr $C$DW$1405, DW_AT_name("icmp")
	.dwattr $C$DW$1405, DW_AT_TI_symbol_name("_icmp")
	.dwattr $C$DW$1405, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1405, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1406	.dwtag  DW_TAG_member
	.dwattr $C$DW$1406, DW_AT_type(*$C$DW$T$553)
	.dwattr $C$DW$1406, DW_AT_name("igmp")
	.dwattr $C$DW$1406, DW_AT_TI_symbol_name("_igmp")
	.dwattr $C$DW$1406, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1406, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$159	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$159, DW_AT_declaration
	.dwattr $C$DW$159, DW_AT_TI_symbol_name("___as__Q2_10net_packet4__C3FRCQ2_10net_packet4__C3")
	.dwattr $C$DW$159, DW_AT_type(*$C$DW$T$554)
	.dwattr $C$DW$159, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1407	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1407, DW_AT_type(*$C$DW$T$556)
	.dwendtag $C$DW$159

	.dwendtag $C$DW$T$558

$C$DW$T$554	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$554, DW_AT_type(*$C$DW$T$558)
	.dwattr $C$DW$T$554, DW_AT_address_class(0x20)

$C$DW$T$557	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$557, DW_AT_type(*$C$DW$T$554)
	.dwattr $C$DW$T$557, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1408	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1408, DW_AT_type(*$C$DW$T$556)
	.dwendtag $C$DW$T$557

$C$DW$T$555	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$555, DW_AT_type(*$C$DW$T$558)
$C$DW$T$556	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$556, DW_AT_type(*$C$DW$T$555)
	.dwattr $C$DW$T$556, DW_AT_address_class(0x20)

$C$DW$T$564	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$564, DW_AT_name("net_packet")
	.dwattr $C$DW$T$564, DW_AT_byte_size(0x1c)
$C$DW$1409	.dwtag  DW_TAG_member
	.dwattr $C$DW$1409, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1409, DW_AT_name("net_p_type")
	.dwattr $C$DW$1409, DW_AT_TI_symbol_name("_net_p_type")
	.dwattr $C$DW$1409, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1409, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1410	.dwtag  DW_TAG_member
	.dwattr $C$DW$1410, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1410, DW_AT_name("transp_p_type")
	.dwattr $C$DW$1410, DW_AT_TI_symbol_name("_transp_p_type")
	.dwattr $C$DW$1410, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr $C$DW$1410, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1411	.dwtag  DW_TAG_member
	.dwattr $C$DW$1411, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1411, DW_AT_name("protocol")
	.dwattr $C$DW$1411, DW_AT_TI_symbol_name("_protocol")
	.dwattr $C$DW$1411, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1411, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1412	.dwtag  DW_TAG_member
	.dwattr $C$DW$1412, DW_AT_type(*$C$DW$T$542)
	.dwattr $C$DW$1412, DW_AT_name("$P$T2")
	.dwattr $C$DW$1412, DW_AT_TI_symbol_name("_$P$T2")
	.dwattr $C$DW$1412, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1412, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1413	.dwtag  DW_TAG_member
	.dwattr $C$DW$1413, DW_AT_type(*$C$DW$T$549)
	.dwattr $C$DW$1413, DW_AT_name("$P$T3")
	.dwattr $C$DW$1413, DW_AT_TI_symbol_name("_$P$T3")
	.dwattr $C$DW$1413, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$1413, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1414	.dwtag  DW_TAG_member
	.dwattr $C$DW$1414, DW_AT_type(*$C$DW$T$558)
	.dwattr $C$DW$1414, DW_AT_name("$P$T4")
	.dwattr $C$DW$1414, DW_AT_TI_symbol_name("_$P$T4")
	.dwattr $C$DW$1414, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$1414, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1415	.dwtag  DW_TAG_member
	.dwattr $C$DW$1415, DW_AT_type(*$C$DW$T$559)
	.dwattr $C$DW$1415, DW_AT_name("snap")
	.dwattr $C$DW$1415, DW_AT_TI_symbol_name("_snap")
	.dwattr $C$DW$1415, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$1415, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1416	.dwtag  DW_TAG_member
	.dwattr $C$DW$1416, DW_AT_type(*$C$DW$T$536)
	.dwattr $C$DW$1416, DW_AT_name("uplevel_p")
	.dwattr $C$DW$1416, DW_AT_TI_symbol_name("_uplevel_p")
	.dwattr $C$DW$1416, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$1416, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$160	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$160, DW_AT_declaration
	.dwattr $C$DW$160, DW_AT_TI_symbol_name("___as__10net_packetFRC10net_packet")
	.dwattr $C$DW$160, DW_AT_type(*$C$DW$T$560)
	.dwattr $C$DW$160, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1417	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1417, DW_AT_type(*$C$DW$T$562)
	.dwendtag $C$DW$160

	.dwendtag $C$DW$T$564

$C$DW$T$560	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$560, DW_AT_type(*$C$DW$T$564)
	.dwattr $C$DW$T$560, DW_AT_address_class(0x20)

$C$DW$T$563	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$563, DW_AT_type(*$C$DW$T$560)
	.dwattr $C$DW$T$563, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1418	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1418, DW_AT_type(*$C$DW$T$562)
	.dwendtag $C$DW$T$563

$C$DW$T$561	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$561, DW_AT_type(*$C$DW$T$564)
$C$DW$T$562	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$562, DW_AT_type(*$C$DW$T$561)
	.dwattr $C$DW$T$562, DW_AT_address_class(0x20)

$C$DW$T$569	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$569, DW_AT_name("net_config")
	.dwattr $C$DW$T$569, DW_AT_byte_size(0x18)
$C$DW$1419	.dwtag  DW_TAG_member
	.dwattr $C$DW$1419, DW_AT_type(*$C$DW$T$459)
	.dwattr $C$DW$1419, DW_AT_name("mac")
	.dwattr $C$DW$1419, DW_AT_TI_symbol_name("_mac")
	.dwattr $C$DW$1419, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1419, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1420	.dwtag  DW_TAG_member
	.dwattr $C$DW$1420, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1420, DW_AT_name("flags")
	.dwattr $C$DW$1420, DW_AT_TI_symbol_name("_flags")
	.dwattr $C$DW$1420, DW_AT_data_member_location[DW_OP_plus_uconst 0x6]
	.dwattr $C$DW$1420, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1421	.dwtag  DW_TAG_member
	.dwattr $C$DW$1421, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1421, DW_AT_name("ip4")
	.dwattr $C$DW$1421, DW_AT_TI_symbol_name("_ip4")
	.dwattr $C$DW$1421, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1421, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1422	.dwtag  DW_TAG_member
	.dwattr $C$DW$1422, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1422, DW_AT_name("mask4")
	.dwattr $C$DW$1422, DW_AT_TI_symbol_name("_mask4")
	.dwattr $C$DW$1422, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$1422, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1423	.dwtag  DW_TAG_member
	.dwattr $C$DW$1423, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1423, DW_AT_name("gateway4")
	.dwattr $C$DW$1423, DW_AT_TI_symbol_name("_gateway4")
	.dwattr $C$DW$1423, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$1423, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1424	.dwtag  DW_TAG_member
	.dwattr $C$DW$1424, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1424, DW_AT_name("mtu")
	.dwattr $C$DW$1424, DW_AT_TI_symbol_name("_mtu")
	.dwattr $C$DW$1424, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$1424, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$161	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$161, DW_AT_declaration
	.dwattr $C$DW$161, DW_AT_TI_symbol_name("___as__10net_configFRC10net_config")
	.dwattr $C$DW$161, DW_AT_type(*$C$DW$T$565)
	.dwattr $C$DW$161, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1425	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1425, DW_AT_type(*$C$DW$T$567)
	.dwendtag $C$DW$161

	.dwendtag $C$DW$T$569

$C$DW$T$565	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$565, DW_AT_type(*$C$DW$T$569)
	.dwattr $C$DW$T$565, DW_AT_address_class(0x20)

$C$DW$T$568	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$568, DW_AT_type(*$C$DW$T$565)
	.dwattr $C$DW$T$568, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1426	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1426, DW_AT_type(*$C$DW$T$567)
	.dwendtag $C$DW$T$568

$C$DW$T$566	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$566, DW_AT_type(*$C$DW$T$569)
$C$DW$T$567	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$567, DW_AT_type(*$C$DW$T$566)
	.dwattr $C$DW$T$567, DW_AT_address_class(0x20)
$C$DW$T$618	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$618, DW_AT_type(*$C$DW$T$569)
	.dwattr $C$DW$T$618, DW_AT_address_class(0x20)

$C$DW$T$575	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$575, DW_AT_name("net_descriptor")
	.dwattr $C$DW$T$575, DW_AT_byte_size(0x38)
$C$DW$1427	.dwtag  DW_TAG_member
	.dwattr $C$DW$1427, DW_AT_type(*$C$DW$T$570)
	.dwattr $C$DW$1427, DW_AT_name("prev")
	.dwattr $C$DW$1427, DW_AT_TI_symbol_name("_prev")
	.dwattr $C$DW$1427, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1427, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1428	.dwtag  DW_TAG_member
	.dwattr $C$DW$1428, DW_AT_type(*$C$DW$T$570)
	.dwattr $C$DW$1428, DW_AT_name("next")
	.dwattr $C$DW$1428, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$1428, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1428, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1429	.dwtag  DW_TAG_member
	.dwattr $C$DW$1429, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1429, DW_AT_name("size")
	.dwattr $C$DW$1429, DW_AT_TI_symbol_name("_size")
	.dwattr $C$DW$1429, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1429, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1430	.dwtag  DW_TAG_member
	.dwattr $C$DW$1430, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1430, DW_AT_name("length")
	.dwattr $C$DW$1430, DW_AT_TI_symbol_name("_length")
	.dwattr $C$DW$1430, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$1430, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1431	.dwtag  DW_TAG_member
	.dwattr $C$DW$1431, DW_AT_type(*$C$DW$T$536)
	.dwattr $C$DW$1431, DW_AT_name("data")
	.dwattr $C$DW$1431, DW_AT_TI_symbol_name("_data")
	.dwattr $C$DW$1431, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$1431, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1432	.dwtag  DW_TAG_member
	.dwattr $C$DW$1432, DW_AT_type(*$C$DW$T$564)
	.dwattr $C$DW$1432, DW_AT_name("pkt")
	.dwattr $C$DW$1432, DW_AT_TI_symbol_name("_pkt")
	.dwattr $C$DW$1432, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$1432, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1433	.dwtag  DW_TAG_member
	.dwattr $C$DW$1433, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$1433, DW_AT_name("dev_desc")
	.dwattr $C$DW$1433, DW_AT_TI_symbol_name("_dev_desc")
	.dwattr $C$DW$1433, DW_AT_data_member_location[DW_OP_plus_uconst 0x30]
	.dwattr $C$DW$1433, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1434	.dwtag  DW_TAG_member
	.dwattr $C$DW$1434, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$1434, DW_AT_name("usr_desc")
	.dwattr $C$DW$1434, DW_AT_TI_symbol_name("_usr_desc")
	.dwattr $C$DW$1434, DW_AT_data_member_location[DW_OP_plus_uconst 0x34]
	.dwattr $C$DW$1434, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$162	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$162, DW_AT_declaration
	.dwattr $C$DW$162, DW_AT_TI_symbol_name("___as__14net_descriptorFRC14net_descriptor")
	.dwattr $C$DW$162, DW_AT_type(*$C$DW$T$571)
	.dwattr $C$DW$162, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1435	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1435, DW_AT_type(*$C$DW$T$573)
	.dwendtag $C$DW$162

	.dwendtag $C$DW$T$575

$C$DW$T$570	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$570, DW_AT_type(*$C$DW$T$575)
	.dwattr $C$DW$T$570, DW_AT_address_class(0x20)
$C$DW$T$571	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$571, DW_AT_type(*$C$DW$T$575)
	.dwattr $C$DW$T$571, DW_AT_address_class(0x20)

$C$DW$T$574	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$574, DW_AT_type(*$C$DW$T$571)
	.dwattr $C$DW$T$574, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1436	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1436, DW_AT_type(*$C$DW$T$573)
	.dwendtag $C$DW$T$574

$C$DW$T$572	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$572, DW_AT_type(*$C$DW$T$575)
$C$DW$T$573	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$573, DW_AT_type(*$C$DW$T$572)
	.dwattr $C$DW$T$573, DW_AT_address_class(0x20)
$C$DW$T$597	.dwtag  DW_TAG_typedef, DW_AT_name("EMAC_Pkt")
	.dwattr $C$DW$T$597, DW_AT_type(*$C$DW$T$575)
	.dwattr $C$DW$T$597, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$T$598	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$598, DW_AT_type(*$C$DW$T$597)
	.dwattr $C$DW$T$598, DW_AT_address_class(0x20)

$C$DW$T$607	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$607, DW_AT_type(*$C$DW$T$598)
	.dwattr $C$DW$T$607, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1437	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1437, DW_AT_type(*$C$DW$T$604)
$C$DW$1438	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1438, DW_AT_type(*$C$DW$T$606)
	.dwendtag $C$DW$T$607

$C$DW$T$608	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$608, DW_AT_type(*$C$DW$T$607)
	.dwattr $C$DW$T$608, DW_AT_address_class(0x20)

$C$DW$T$580	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$580, DW_AT_name("net_send")
	.dwattr $C$DW$T$580, DW_AT_byte_size(0x08)
$C$DW$1439	.dwtag  DW_TAG_member
	.dwattr $C$DW$1439, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1439, DW_AT_name("length")
	.dwattr $C$DW$1439, DW_AT_TI_symbol_name("_length")
	.dwattr $C$DW$1439, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1439, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1440	.dwtag  DW_TAG_member
	.dwattr $C$DW$1440, DW_AT_type(*$C$DW$T$536)
	.dwattr $C$DW$1440, DW_AT_name("data")
	.dwattr $C$DW$1440, DW_AT_TI_symbol_name("_data")
	.dwattr $C$DW$1440, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1440, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$163	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$163, DW_AT_declaration
	.dwattr $C$DW$163, DW_AT_TI_symbol_name("___as__8net_sendFRC8net_send")
	.dwattr $C$DW$163, DW_AT_type(*$C$DW$T$576)
	.dwattr $C$DW$163, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1441	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1441, DW_AT_type(*$C$DW$T$578)
	.dwendtag $C$DW$163

	.dwendtag $C$DW$T$580

$C$DW$T$576	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$576, DW_AT_type(*$C$DW$T$580)
	.dwattr $C$DW$T$576, DW_AT_address_class(0x20)

$C$DW$T$579	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$579, DW_AT_type(*$C$DW$T$576)
	.dwattr $C$DW$T$579, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1442	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1442, DW_AT_type(*$C$DW$T$578)
	.dwendtag $C$DW$T$579

$C$DW$T$577	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$577, DW_AT_type(*$C$DW$T$580)
$C$DW$T$578	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$578, DW_AT_type(*$C$DW$T$577)
	.dwattr $C$DW$T$578, DW_AT_address_class(0x20)

$C$DW$T$585	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$585, DW_AT_name("dev_reg")
	.dwattr $C$DW$T$585, DW_AT_byte_size(0x0c)
$C$DW$1443	.dwtag  DW_TAG_member
	.dwattr $C$DW$1443, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1443, DW_AT_name("device")
	.dwattr $C$DW$1443, DW_AT_TI_symbol_name("_device")
	.dwattr $C$DW$1443, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1443, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1444	.dwtag  DW_TAG_member
	.dwattr $C$DW$1444, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1444, DW_AT_name("reg")
	.dwattr $C$DW$1444, DW_AT_TI_symbol_name("_reg")
	.dwattr $C$DW$1444, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1444, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1445	.dwtag  DW_TAG_member
	.dwattr $C$DW$1445, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1445, DW_AT_name("value")
	.dwattr $C$DW$1445, DW_AT_TI_symbol_name("_value")
	.dwattr $C$DW$1445, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1445, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$164	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$164, DW_AT_declaration
	.dwattr $C$DW$164, DW_AT_TI_symbol_name("___as__7dev_regFRC7dev_reg")
	.dwattr $C$DW$164, DW_AT_type(*$C$DW$T$581)
	.dwattr $C$DW$164, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1446	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1446, DW_AT_type(*$C$DW$T$583)
	.dwendtag $C$DW$164

	.dwendtag $C$DW$T$585

$C$DW$T$581	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$581, DW_AT_type(*$C$DW$T$585)
	.dwattr $C$DW$T$581, DW_AT_address_class(0x20)

$C$DW$T$584	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$584, DW_AT_type(*$C$DW$T$581)
	.dwattr $C$DW$T$584, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1447	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1447, DW_AT_type(*$C$DW$T$583)
	.dwendtag $C$DW$T$584

$C$DW$T$582	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$582, DW_AT_type(*$C$DW$T$585)
$C$DW$T$583	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$583, DW_AT_type(*$C$DW$T$582)
	.dwattr $C$DW$T$583, DW_AT_address_class(0x20)

$C$DW$T$590	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$590, DW_AT_name("new_queue")
	.dwattr $C$DW$T$590, DW_AT_byte_size(0x08)
$C$DW$1448	.dwtag  DW_TAG_member
	.dwattr $C$DW$1448, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1448, DW_AT_name("rx_count")
	.dwattr $C$DW$1448, DW_AT_TI_symbol_name("_rx_count")
	.dwattr $C$DW$1448, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1448, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1449	.dwtag  DW_TAG_member
	.dwattr $C$DW$1449, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1449, DW_AT_name("tx_count")
	.dwattr $C$DW$1449, DW_AT_TI_symbol_name("_tx_count")
	.dwattr $C$DW$1449, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1449, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$165	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$165, DW_AT_declaration
	.dwattr $C$DW$165, DW_AT_TI_symbol_name("___as__9new_queueFRC9new_queue")
	.dwattr $C$DW$165, DW_AT_type(*$C$DW$T$586)
	.dwattr $C$DW$165, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1450	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1450, DW_AT_type(*$C$DW$T$588)
	.dwendtag $C$DW$165

	.dwendtag $C$DW$T$590

$C$DW$T$586	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$586, DW_AT_type(*$C$DW$T$590)
	.dwattr $C$DW$T$586, DW_AT_address_class(0x20)

$C$DW$T$589	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$589, DW_AT_type(*$C$DW$T$586)
	.dwattr $C$DW$T$589, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1451	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1451, DW_AT_type(*$C$DW$T$588)
	.dwendtag $C$DW$T$589

$C$DW$T$587	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$587, DW_AT_type(*$C$DW$T$590)
$C$DW$T$588	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$588, DW_AT_type(*$C$DW$T$587)
	.dwattr $C$DW$T$588, DW_AT_address_class(0x20)

$C$DW$T$596	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$596, DW_AT_name("_EMAC_Desc")
	.dwattr $C$DW$T$596, DW_AT_byte_size(0x10)
$C$DW$1452	.dwtag  DW_TAG_member
	.dwattr $C$DW$1452, DW_AT_type(*$C$DW$T$591)
	.dwattr $C$DW$1452, DW_AT_name("pNext")
	.dwattr $C$DW$1452, DW_AT_TI_symbol_name("_pNext")
	.dwattr $C$DW$1452, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1452, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1453	.dwtag  DW_TAG_member
	.dwattr $C$DW$1453, DW_AT_type(*$C$DW$T$536)
	.dwattr $C$DW$1453, DW_AT_name("pBuffer")
	.dwattr $C$DW$1453, DW_AT_TI_symbol_name("_pBuffer")
	.dwattr $C$DW$1453, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1453, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1454	.dwtag  DW_TAG_member
	.dwattr $C$DW$1454, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1454, DW_AT_name("BufOffLen")
	.dwattr $C$DW$1454, DW_AT_TI_symbol_name("_BufOffLen")
	.dwattr $C$DW$1454, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1454, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1455	.dwtag  DW_TAG_member
	.dwattr $C$DW$1455, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1455, DW_AT_name("PktFlgLen")
	.dwattr $C$DW$1455, DW_AT_TI_symbol_name("_PktFlgLen")
	.dwattr $C$DW$1455, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$1455, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$166	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$166, DW_AT_declaration
	.dwattr $C$DW$166, DW_AT_TI_symbol_name("___as__10_EMAC_DescFRC10_EMAC_Desc")
	.dwattr $C$DW$166, DW_AT_type(*$C$DW$T$592)
	.dwattr $C$DW$166, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1456	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1456, DW_AT_type(*$C$DW$T$594)
	.dwendtag $C$DW$166

	.dwendtag $C$DW$T$596

$C$DW$T$591	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$591, DW_AT_type(*$C$DW$T$596)
	.dwattr $C$DW$T$591, DW_AT_address_class(0x20)
$C$DW$T$592	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$592, DW_AT_type(*$C$DW$T$596)
	.dwattr $C$DW$T$592, DW_AT_address_class(0x20)

$C$DW$T$595	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$595, DW_AT_type(*$C$DW$T$592)
	.dwattr $C$DW$T$595, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1457	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1457, DW_AT_type(*$C$DW$T$594)
	.dwendtag $C$DW$T$595

$C$DW$T$593	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$593, DW_AT_type(*$C$DW$T$596)
$C$DW$T$594	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$594, DW_AT_type(*$C$DW$T$593)
	.dwattr $C$DW$T$594, DW_AT_address_class(0x20)
$C$DW$T$627	.dwtag  DW_TAG_typedef, DW_AT_name("EMAC_Desc")
	.dwattr $C$DW$T$627, DW_AT_type(*$C$DW$T$596)
	.dwattr $C$DW$T$627, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$T$628	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$628, DW_AT_type(*$C$DW$T$627)
	.dwattr $C$DW$T$628, DW_AT_address_class(0x20)

$C$DW$T$603	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$603, DW_AT_name("_pktq")
	.dwattr $C$DW$T$603, DW_AT_byte_size(0x0c)
$C$DW$1458	.dwtag  DW_TAG_member
	.dwattr $C$DW$1458, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1458, DW_AT_name("Count")
	.dwattr $C$DW$1458, DW_AT_TI_symbol_name("_Count")
	.dwattr $C$DW$1458, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1458, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1459	.dwtag  DW_TAG_member
	.dwattr $C$DW$1459, DW_AT_type(*$C$DW$T$598)
	.dwattr $C$DW$1459, DW_AT_name("pHead")
	.dwattr $C$DW$1459, DW_AT_TI_symbol_name("_pHead")
	.dwattr $C$DW$1459, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1459, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1460	.dwtag  DW_TAG_member
	.dwattr $C$DW$1460, DW_AT_type(*$C$DW$T$598)
	.dwattr $C$DW$1460, DW_AT_name("pTail")
	.dwattr $C$DW$1460, DW_AT_TI_symbol_name("_pTail")
	.dwattr $C$DW$1460, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1460, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$167	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$167, DW_AT_declaration
	.dwattr $C$DW$167, DW_AT_TI_symbol_name("___as__5_pktqFRC5_pktq")
	.dwattr $C$DW$167, DW_AT_type(*$C$DW$T$599)
	.dwattr $C$DW$167, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1461	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1461, DW_AT_type(*$C$DW$T$601)
	.dwendtag $C$DW$167

	.dwendtag $C$DW$T$603

$C$DW$T$599	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$599, DW_AT_type(*$C$DW$T$603)
	.dwattr $C$DW$T$599, DW_AT_address_class(0x20)

$C$DW$T$602	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$602, DW_AT_type(*$C$DW$T$599)
	.dwattr $C$DW$T$602, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1462	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1462, DW_AT_type(*$C$DW$T$601)
	.dwendtag $C$DW$T$602

$C$DW$T$600	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$600, DW_AT_type(*$C$DW$T$603)
$C$DW$T$601	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$601, DW_AT_type(*$C$DW$T$600)
	.dwattr $C$DW$T$601, DW_AT_address_class(0x20)
$C$DW$T$605	.dwtag  DW_TAG_typedef, DW_AT_name("PKTQ")
	.dwattr $C$DW$T$605, DW_AT_type(*$C$DW$T$603)
	.dwattr $C$DW$T$605, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$T$606	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$606, DW_AT_type(*$C$DW$T$605)
	.dwattr $C$DW$T$606, DW_AT_address_class(0x20)

$C$DW$T$615	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$615, DW_AT_name("_EMAC_Config")
	.dwattr $C$DW$T$615, DW_AT_byte_size(0x1c)
$C$DW$1463	.dwtag  DW_TAG_member
	.dwattr $C$DW$1463, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1463, DW_AT_name("ModeFlags")
	.dwattr $C$DW$1463, DW_AT_TI_symbol_name("_ModeFlags")
	.dwattr $C$DW$1463, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1463, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1464	.dwtag  DW_TAG_member
	.dwattr $C$DW$1464, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1464, DW_AT_name("MdioModeFlags")
	.dwattr $C$DW$1464, DW_AT_TI_symbol_name("_MdioModeFlags")
	.dwattr $C$DW$1464, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1464, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1465	.dwtag  DW_TAG_member
	.dwattr $C$DW$1465, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1465, DW_AT_name("TxChannels")
	.dwattr $C$DW$1465, DW_AT_TI_symbol_name("_TxChannels")
	.dwattr $C$DW$1465, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1465, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1466	.dwtag  DW_TAG_member
	.dwattr $C$DW$1466, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1466, DW_AT_name("RxMaxPktPool")
	.dwattr $C$DW$1466, DW_AT_TI_symbol_name("_RxMaxPktPool")
	.dwattr $C$DW$1466, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$1466, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1467	.dwtag  DW_TAG_member
	.dwattr $C$DW$1467, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1467, DW_AT_name("TxMaxPktPool")
	.dwattr $C$DW$1467, DW_AT_TI_symbol_name("_TxMaxPktPool")
	.dwattr $C$DW$1467, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$1467, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1468	.dwtag  DW_TAG_member
	.dwattr $C$DW$1468, DW_AT_type(*$C$DW$T$608)
	.dwattr $C$DW$1468, DW_AT_name("pfcbGetPacket")
	.dwattr $C$DW$1468, DW_AT_TI_symbol_name("_pfcbGetPacket")
	.dwattr $C$DW$1468, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$1468, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1469	.dwtag  DW_TAG_member
	.dwattr $C$DW$1469, DW_AT_type(*$C$DW$T$610)
	.dwattr $C$DW$1469, DW_AT_name("pfcbPutPacket")
	.dwattr $C$DW$1469, DW_AT_TI_symbol_name("_pfcbPutPacket")
	.dwattr $C$DW$1469, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$1469, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$168	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$168, DW_AT_declaration
	.dwattr $C$DW$168, DW_AT_TI_symbol_name("___as__12_EMAC_ConfigFRC12_EMAC_Config")
	.dwattr $C$DW$168, DW_AT_type(*$C$DW$T$611)
	.dwattr $C$DW$168, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1470	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1470, DW_AT_type(*$C$DW$T$613)
	.dwendtag $C$DW$168

	.dwendtag $C$DW$T$615

$C$DW$T$611	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$611, DW_AT_type(*$C$DW$T$615)
	.dwattr $C$DW$T$611, DW_AT_address_class(0x20)

$C$DW$T$614	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$614, DW_AT_type(*$C$DW$T$611)
	.dwattr $C$DW$T$614, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1471	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1471, DW_AT_type(*$C$DW$T$613)
	.dwendtag $C$DW$T$614

$C$DW$T$612	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$612, DW_AT_type(*$C$DW$T$615)
$C$DW$T$613	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$613, DW_AT_type(*$C$DW$T$612)
	.dwattr $C$DW$T$613, DW_AT_address_class(0x20)
$C$DW$T$616	.dwtag  DW_TAG_typedef, DW_AT_name("EMAC_Config")
	.dwattr $C$DW$T$616, DW_AT_type(*$C$DW$T$615)
	.dwattr $C$DW$T$616, DW_AT_language(DW_LANG_C_plus_plus)

$C$DW$T$625	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$625, DW_AT_name("_EMAC_Device")
	.dwattr $C$DW$T$625, DW_AT_byte_size(0xf4)
$C$DW$1472	.dwtag  DW_TAG_member
	.dwattr $C$DW$1472, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1472, DW_AT_name("hGPIO")
	.dwattr $C$DW$1472, DW_AT_TI_symbol_name("_hGPIO")
	.dwattr $C$DW$1472, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1472, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1473	.dwtag  DW_TAG_member
	.dwattr $C$DW$1473, DW_AT_type(*$C$DW$T$569)
	.dwattr $C$DW$1473, DW_AT_name("ncfg")
	.dwattr $C$DW$1473, DW_AT_TI_symbol_name("_ncfg")
	.dwattr $C$DW$1473, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1473, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1474	.dwtag  DW_TAG_member
	.dwattr $C$DW$1474, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1474, DW_AT_name("intrpt")
	.dwattr $C$DW$1474, DW_AT_TI_symbol_name("_intrpt")
	.dwattr $C$DW$1474, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr $C$DW$1474, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1475	.dwtag  DW_TAG_member
	.dwattr $C$DW$1475, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1475, DW_AT_name("smphr")
	.dwattr $C$DW$1475, DW_AT_TI_symbol_name("_smphr")
	.dwattr $C$DW$1475, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr $C$DW$1475, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1476	.dwtag  DW_TAG_member
	.dwattr $C$DW$1476, DW_AT_type(*$C$DW$T$604)
	.dwattr $C$DW$1476, DW_AT_name("hApplication")
	.dwattr $C$DW$1476, DW_AT_TI_symbol_name("_hApplication")
	.dwattr $C$DW$1476, DW_AT_data_member_location[DW_OP_plus_uconst 0x24]
	.dwattr $C$DW$1476, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1477	.dwtag  DW_TAG_member
	.dwattr $C$DW$1477, DW_AT_type(*$C$DW$T$604)
	.dwattr $C$DW$1477, DW_AT_name("hMDIO")
	.dwattr $C$DW$1477, DW_AT_TI_symbol_name("_hMDIO")
	.dwattr $C$DW$1477, DW_AT_data_member_location[DW_OP_plus_uconst 0x28]
	.dwattr $C$DW$1477, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1478	.dwtag  DW_TAG_member
	.dwattr $C$DW$1478, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1478, DW_AT_name("RxFilter")
	.dwattr $C$DW$1478, DW_AT_TI_symbol_name("_RxFilter")
	.dwattr $C$DW$1478, DW_AT_data_member_location[DW_OP_plus_uconst 0x2c]
	.dwattr $C$DW$1478, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1479	.dwtag  DW_TAG_member
	.dwattr $C$DW$1479, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1479, DW_AT_name("PktMTU")
	.dwattr $C$DW$1479, DW_AT_TI_symbol_name("_PktMTU")
	.dwattr $C$DW$1479, DW_AT_data_member_location[DW_OP_plus_uconst 0x30]
	.dwattr $C$DW$1479, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1480	.dwtag  DW_TAG_member
	.dwattr $C$DW$1480, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1480, DW_AT_name("MacHash1")
	.dwattr $C$DW$1480, DW_AT_TI_symbol_name("_MacHash1")
	.dwattr $C$DW$1480, DW_AT_data_member_location[DW_OP_plus_uconst 0x34]
	.dwattr $C$DW$1480, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1481	.dwtag  DW_TAG_member
	.dwattr $C$DW$1481, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1481, DW_AT_name("MacHash2")
	.dwattr $C$DW$1481, DW_AT_TI_symbol_name("_MacHash2")
	.dwattr $C$DW$1481, DW_AT_data_member_location[DW_OP_plus_uconst 0x38]
	.dwattr $C$DW$1481, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1482	.dwtag  DW_TAG_member
	.dwattr $C$DW$1482, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1482, DW_AT_name("FatalError")
	.dwattr $C$DW$1482, DW_AT_TI_symbol_name("_FatalError")
	.dwattr $C$DW$1482, DW_AT_data_member_location[DW_OP_plus_uconst 0x3c]
	.dwattr $C$DW$1482, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1483	.dwtag  DW_TAG_member
	.dwattr $C$DW$1483, DW_AT_type(*$C$DW$T$598)
	.dwattr $C$DW$1483, DW_AT_name("pkt_rx")
	.dwattr $C$DW$1483, DW_AT_TI_symbol_name("_pkt_rx")
	.dwattr $C$DW$1483, DW_AT_data_member_location[DW_OP_plus_uconst 0x40]
	.dwattr $C$DW$1483, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1484	.dwtag  DW_TAG_member
	.dwattr $C$DW$1484, DW_AT_type(*$C$DW$T$598)
	.dwattr $C$DW$1484, DW_AT_name("pkt_tx")
	.dwattr $C$DW$1484, DW_AT_TI_symbol_name("_pkt_tx")
	.dwattr $C$DW$1484, DW_AT_data_member_location[DW_OP_plus_uconst 0x44]
	.dwattr $C$DW$1484, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1485	.dwtag  DW_TAG_member
	.dwattr $C$DW$1485, DW_AT_type(*$C$DW$T$536)
	.dwattr $C$DW$1485, DW_AT_name("pkt_data")
	.dwattr $C$DW$1485, DW_AT_TI_symbol_name("_pkt_data")
	.dwattr $C$DW$1485, DW_AT_data_member_location[DW_OP_plus_uconst 0x48]
	.dwattr $C$DW$1485, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1486	.dwtag  DW_TAG_member
	.dwattr $C$DW$1486, DW_AT_type(*$C$DW$T$605)
	.dwattr $C$DW$1486, DW_AT_name("RxQueue")
	.dwattr $C$DW$1486, DW_AT_TI_symbol_name("_RxQueue")
	.dwattr $C$DW$1486, DW_AT_data_member_location[DW_OP_plus_uconst 0x4c]
	.dwattr $C$DW$1486, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1487	.dwtag  DW_TAG_member
	.dwattr $C$DW$1487, DW_AT_type(*$C$DW$T$605)
	.dwattr $C$DW$1487, DW_AT_name("TxQueue")
	.dwattr $C$DW$1487, DW_AT_TI_symbol_name("_TxQueue")
	.dwattr $C$DW$1487, DW_AT_data_member_location[DW_OP_plus_uconst 0x58]
	.dwattr $C$DW$1487, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1488	.dwtag  DW_TAG_member
	.dwattr $C$DW$1488, DW_AT_type(*$C$DW$T$616)
	.dwattr $C$DW$1488, DW_AT_name("Config")
	.dwattr $C$DW$1488, DW_AT_TI_symbol_name("_Config")
	.dwattr $C$DW$1488, DW_AT_data_member_location[DW_OP_plus_uconst 0x64]
	.dwattr $C$DW$1488, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1489	.dwtag  DW_TAG_member
	.dwattr $C$DW$1489, DW_AT_type(*$C$DW$T$617)
	.dwattr $C$DW$1489, DW_AT_name("RxCh")
	.dwattr $C$DW$1489, DW_AT_TI_symbol_name("_RxCh")
	.dwattr $C$DW$1489, DW_AT_data_member_location[DW_OP_plus_uconst 0x80]
	.dwattr $C$DW$1489, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1490	.dwtag  DW_TAG_member
	.dwattr $C$DW$1490, DW_AT_type(*$C$DW$T$617)
	.dwattr $C$DW$1490, DW_AT_name("TxCh")
	.dwattr $C$DW$1490, DW_AT_TI_symbol_name("_TxCh")
	.dwattr $C$DW$1490, DW_AT_data_member_location[DW_OP_plus_uconst 0xb8]
	.dwattr $C$DW$1490, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1491	.dwtag  DW_TAG_member
	.dwattr $C$DW$1491, DW_AT_type(*$C$DW$T$620)
	.dwattr $C$DW$1491, DW_AT_name("callback")
	.dwattr $C$DW$1491, DW_AT_TI_symbol_name("_callback")
	.dwattr $C$DW$1491, DW_AT_data_member_location[DW_OP_plus_uconst 0xf0]
	.dwattr $C$DW$1491, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$169	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$169, DW_AT_declaration
	.dwattr $C$DW$169, DW_AT_TI_symbol_name("___as__12_EMAC_DeviceFRC12_EMAC_Device")
	.dwattr $C$DW$169, DW_AT_type(*$C$DW$T$621)
	.dwattr $C$DW$169, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1492	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1492, DW_AT_type(*$C$DW$T$623)
	.dwendtag $C$DW$169

	.dwendtag $C$DW$T$625

$C$DW$T$621	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$621, DW_AT_type(*$C$DW$T$625)
	.dwattr $C$DW$T$621, DW_AT_address_class(0x20)

$C$DW$T$624	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$624, DW_AT_type(*$C$DW$T$621)
	.dwattr $C$DW$T$624, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1493	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1493, DW_AT_type(*$C$DW$T$623)
	.dwendtag $C$DW$T$624

$C$DW$T$622	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$622, DW_AT_type(*$C$DW$T$625)
$C$DW$T$623	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$623, DW_AT_type(*$C$DW$T$622)
	.dwattr $C$DW$T$623, DW_AT_address_class(0x20)
$C$DW$T$626	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$626, DW_AT_type(*$C$DW$T$625)
	.dwattr $C$DW$T$626, DW_AT_address_class(0x20)
$C$DW$T$773	.dwtag  DW_TAG_typedef, DW_AT_name("EMAC_Device")
	.dwattr $C$DW$T$773, DW_AT_type(*$C$DW$T$625)
	.dwattr $C$DW$T$773, DW_AT_language(DW_LANG_C_plus_plus)

$C$DW$T$633	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$633, DW_AT_name("_EMAC_DescCh")
	.dwattr $C$DW$T$633, DW_AT_byte_size(0x38)
$C$DW$1494	.dwtag  DW_TAG_member
	.dwattr $C$DW$1494, DW_AT_type(*$C$DW$T$626)
	.dwattr $C$DW$1494, DW_AT_name("pd")
	.dwattr $C$DW$1494, DW_AT_TI_symbol_name("_pd")
	.dwattr $C$DW$1494, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1494, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1495	.dwtag  DW_TAG_member
	.dwattr $C$DW$1495, DW_AT_type(*$C$DW$T$605)
	.dwattr $C$DW$1495, DW_AT_name("DescQueue")
	.dwattr $C$DW$1495, DW_AT_TI_symbol_name("_DescQueue")
	.dwattr $C$DW$1495, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1495, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1496	.dwtag  DW_TAG_member
	.dwattr $C$DW$1496, DW_AT_type(*$C$DW$T$605)
	.dwattr $C$DW$1496, DW_AT_name("WaitQueue")
	.dwattr $C$DW$1496, DW_AT_TI_symbol_name("_WaitQueue")
	.dwattr $C$DW$1496, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$1496, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1497	.dwtag  DW_TAG_member
	.dwattr $C$DW$1497, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1497, DW_AT_name("ChannelIndex")
	.dwattr $C$DW$1497, DW_AT_TI_symbol_name("_ChannelIndex")
	.dwattr $C$DW$1497, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr $C$DW$1497, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1498	.dwtag  DW_TAG_member
	.dwattr $C$DW$1498, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1498, DW_AT_name("DescMax")
	.dwattr $C$DW$1498, DW_AT_TI_symbol_name("_DescMax")
	.dwattr $C$DW$1498, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr $C$DW$1498, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1499	.dwtag  DW_TAG_member
	.dwattr $C$DW$1499, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1499, DW_AT_name("DescCount")
	.dwattr $C$DW$1499, DW_AT_TI_symbol_name("_DescCount")
	.dwattr $C$DW$1499, DW_AT_data_member_location[DW_OP_plus_uconst 0x24]
	.dwattr $C$DW$1499, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1500	.dwtag  DW_TAG_member
	.dwattr $C$DW$1500, DW_AT_type(*$C$DW$T$628)
	.dwattr $C$DW$1500, DW_AT_name("pDescFirst")
	.dwattr $C$DW$1500, DW_AT_TI_symbol_name("_pDescFirst")
	.dwattr $C$DW$1500, DW_AT_data_member_location[DW_OP_plus_uconst 0x28]
	.dwattr $C$DW$1500, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1501	.dwtag  DW_TAG_member
	.dwattr $C$DW$1501, DW_AT_type(*$C$DW$T$628)
	.dwattr $C$DW$1501, DW_AT_name("pDescLast")
	.dwattr $C$DW$1501, DW_AT_TI_symbol_name("_pDescLast")
	.dwattr $C$DW$1501, DW_AT_data_member_location[DW_OP_plus_uconst 0x2c]
	.dwattr $C$DW$1501, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1502	.dwtag  DW_TAG_member
	.dwattr $C$DW$1502, DW_AT_type(*$C$DW$T$628)
	.dwattr $C$DW$1502, DW_AT_name("pDescRead")
	.dwattr $C$DW$1502, DW_AT_TI_symbol_name("_pDescRead")
	.dwattr $C$DW$1502, DW_AT_data_member_location[DW_OP_plus_uconst 0x30]
	.dwattr $C$DW$1502, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1503	.dwtag  DW_TAG_member
	.dwattr $C$DW$1503, DW_AT_type(*$C$DW$T$628)
	.dwattr $C$DW$1503, DW_AT_name("pDescWrite")
	.dwattr $C$DW$1503, DW_AT_TI_symbol_name("_pDescWrite")
	.dwattr $C$DW$1503, DW_AT_data_member_location[DW_OP_plus_uconst 0x34]
	.dwattr $C$DW$1503, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$170	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$170, DW_AT_declaration
	.dwattr $C$DW$170, DW_AT_TI_symbol_name("___as__12_EMAC_DescChFRC12_EMAC_DescCh")
	.dwattr $C$DW$170, DW_AT_type(*$C$DW$T$629)
	.dwattr $C$DW$170, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1504	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1504, DW_AT_type(*$C$DW$T$631)
	.dwendtag $C$DW$170

	.dwendtag $C$DW$T$633

$C$DW$T$617	.dwtag  DW_TAG_typedef, DW_AT_name("EMAC_DescCh")
	.dwattr $C$DW$T$617, DW_AT_type(*$C$DW$T$633)
	.dwattr $C$DW$T$617, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$T$629	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$629, DW_AT_type(*$C$DW$T$633)
	.dwattr $C$DW$T$629, DW_AT_address_class(0x20)

$C$DW$T$632	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$632, DW_AT_type(*$C$DW$T$629)
	.dwattr $C$DW$T$632, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1505	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1505, DW_AT_type(*$C$DW$T$631)
	.dwendtag $C$DW$T$632

$C$DW$T$630	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$630, DW_AT_type(*$C$DW$T$633)
$C$DW$T$631	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$631, DW_AT_type(*$C$DW$T$630)
	.dwattr $C$DW$T$631, DW_AT_address_class(0x20)

$C$DW$T$638	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$638, DW_AT_name("_MDIO_Device")
	.dwattr $C$DW$T$638, DW_AT_byte_size(0x14)
$C$DW$1506	.dwtag  DW_TAG_member
	.dwattr $C$DW$1506, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1506, DW_AT_name("ModeFlags")
	.dwattr $C$DW$1506, DW_AT_TI_symbol_name("_ModeFlags")
	.dwattr $C$DW$1506, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1506, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1507	.dwtag  DW_TAG_member
	.dwattr $C$DW$1507, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1507, DW_AT_name("phyAddr")
	.dwattr $C$DW$1507, DW_AT_TI_symbol_name("_phyAddr")
	.dwattr $C$DW$1507, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1507, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1508	.dwtag  DW_TAG_member
	.dwattr $C$DW$1508, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1508, DW_AT_name("phyState")
	.dwattr $C$DW$1508, DW_AT_TI_symbol_name("_phyState")
	.dwattr $C$DW$1508, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1508, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1509	.dwtag  DW_TAG_member
	.dwattr $C$DW$1509, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1509, DW_AT_name("LinkStatus")
	.dwattr $C$DW$1509, DW_AT_TI_symbol_name("_LinkStatus")
	.dwattr $C$DW$1509, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$1509, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1510	.dwtag  DW_TAG_member
	.dwattr $C$DW$1510, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1510, DW_AT_name("control_reg")
	.dwattr $C$DW$1510, DW_AT_TI_symbol_name("_control_reg")
	.dwattr $C$DW$1510, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$1510, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$171	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$171, DW_AT_declaration
	.dwattr $C$DW$171, DW_AT_TI_symbol_name("___as__12_MDIO_DeviceFRC12_MDIO_Device")
	.dwattr $C$DW$171, DW_AT_type(*$C$DW$T$634)
	.dwattr $C$DW$171, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1511	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1511, DW_AT_type(*$C$DW$T$636)
	.dwendtag $C$DW$171

	.dwendtag $C$DW$T$638

$C$DW$T$634	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$634, DW_AT_type(*$C$DW$T$638)
	.dwattr $C$DW$T$634, DW_AT_address_class(0x20)

$C$DW$T$637	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$637, DW_AT_type(*$C$DW$T$634)
	.dwattr $C$DW$T$637, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1512	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1512, DW_AT_type(*$C$DW$T$636)
	.dwendtag $C$DW$T$637

$C$DW$T$635	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$635, DW_AT_type(*$C$DW$T$638)
$C$DW$T$636	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$636, DW_AT_type(*$C$DW$T$635)
	.dwattr $C$DW$T$636, DW_AT_address_class(0x20)
$C$DW$T$774	.dwtag  DW_TAG_typedef, DW_AT_name("MDIO_Device")
	.dwattr $C$DW$T$774, DW_AT_type(*$C$DW$T$638)
	.dwattr $C$DW$T$774, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$T$701	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$701, DW_AT_encoding(DW_ATE_boolean)
	.dwattr $C$DW$T$701, DW_AT_name("bool")
	.dwattr $C$DW$T$701, DW_AT_byte_size(0x01)

$C$DW$T$760	.dwtag  DW_TAG_enumeration_type
	.dwattr $C$DW$T$760, DW_AT_name("Error")
	.dwattr $C$DW$T$760, DW_AT_byte_size(0x04)
$C$DW$1513	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_OK"), DW_AT_const_value(0x00)
$C$DW$1514	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NO_MEMORY"), DW_AT_const_value(-1)
$C$DW$1515	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NO_DEVICE"), DW_AT_const_value(-2)
$C$DW$1516	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_BAD_RDESC"), DW_AT_const_value(-3)
$C$DW$1517	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_BAD_PARAM"), DW_AT_const_value(-4)
$C$DW$1518	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NULL_PARAM"), DW_AT_const_value(-5)
$C$DW$1519	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_CANT_OPEN"), DW_AT_const_value(-6)
$C$DW$1520	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_CANT_READ"), DW_AT_const_value(-7)
$C$DW$1521	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_CANT_WRITE"), DW_AT_const_value(-8)
$C$DW$1522	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_CANT_CREATE_HEAP"), DW_AT_const_value(-9)
$C$DW$1523	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_CANT_CREATE_STACK"), DW_AT_const_value(-10)
$C$DW$1524	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_MSG_ALLREADY_STARTED"), DW_AT_const_value(-11)
$C$DW$1525	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_LIF_BAD_HEADER"), DW_AT_const_value(-12)
$C$DW$1526	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_LIF_WRONG_TARGET_CPU"), DW_AT_const_value(-13)
$C$DW$1527	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_LIF_BAD_SECTION_HEADER"), DW_AT_const_value(-14)
$C$DW$1528	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_LIF_CANT_APPLY_PATCH"), DW_AT_const_value(-15)
$C$DW$1529	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_TOO_LONG_STRING"), DW_AT_const_value(-16)
$C$DW$1530	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_ALLREADY_NAMED"), DW_AT_const_value(-17)
$C$DW$1531	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_TOO_SHORT_BUFFER"), DW_AT_const_value(-18)
$C$DW$1532	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_FAIL"), DW_AT_const_value(-19)
$C$DW$1533	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_CANT_CREATE_SEM"), DW_AT_const_value(-20)
$C$DW$1534	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_MSG_STREAM_NOT_OPENED"), DW_AT_const_value(-21)
$C$DW$1535	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_MSG_BAD_DST_ADDRESS"), DW_AT_const_value(-22)
$C$DW$1536	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_VOID_RESOURCE"), DW_AT_const_value(-23)
$C$DW$1537	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_SEM_DESTROYED"), DW_AT_const_value(-24)
$C$DW$1538	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_SEM_NOT_REGISTERED"), DW_AT_const_value(-25)
$C$DW$1539	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_TIMEOUT"), DW_AT_const_value(-26)
$C$DW$1540	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_SEM_LOCKED"), DW_AT_const_value(-27)
$C$DW$1541	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_SEM_UNLOCKED"), DW_AT_const_value(-28)
$C$DW$1542	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NO_EXTENSION"), DW_AT_const_value(-29)
$C$DW$1543	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_EXTENSION_PLUGGED"), DW_AT_const_value(-30)
$C$DW$1544	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_EXTENSION_BAD_HEADER"), DW_AT_const_value(-31)
$C$DW$1545	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_EXTENSION_F_PLUGGED"), DW_AT_const_value(-32)
$C$DW$1546	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_CANT_CREATE_PROCESS"), DW_AT_const_value(-33)
$C$DW$1547	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_BAD_DCTX"), DW_AT_const_value(-34)
$C$DW$1548	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_PERMISSION_DENIED"), DW_AT_const_value(-35)
$C$DW$1549	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_BAD_DATA"), DW_AT_const_value(-36)
$C$DW$1550	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_ALREADY_PLUGGED"), DW_AT_const_value(-37)
$C$DW$1551	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_CANT_CREATE_INTERRUPT"), DW_AT_const_value(-38)
$C$DW$1552	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_SIDE_TEST_ERROR"), DW_AT_const_value(-39)
$C$DW$1553	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_DATA_TEST_ERROR"), DW_AT_const_value(-40)
$C$DW$1554	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_ADDRESS_TEST_ERROR"), DW_AT_const_value(-41)
$C$DW$1555	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_TOO_MANY_DATA"), DW_AT_const_value(-42)
$C$DW$1556	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_DIFFERENT_LENGTH"), DW_AT_const_value(-43)
$C$DW$1557	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_DATA_ALIGNED"), DW_AT_const_value(-44)
$C$DW$1558	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_CANT_LOCK_SEM"), DW_AT_const_value(-45)
$C$DW$1559	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NO_ELEMENT"), DW_AT_const_value(-46)
$C$DW$1560	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_BAD_CMD"), DW_AT_const_value(-47)
$C$DW$1561	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NO_NODE"), DW_AT_const_value(-48)
$C$DW$1562	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_CANT_RESET_PARAM"), DW_AT_const_value(-49)
$C$DW$1563	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NO_PROCESS"), DW_AT_const_value(-50)
$C$DW$1564	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_BAD_RESOURCE_TYPE"), DW_AT_const_value(-51)
$C$DW$1565	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_ALREADY_ADDED"), DW_AT_const_value(-52)
$C$DW$1566	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NO_ROUTE"), DW_AT_const_value(-53)
$C$DW$1567	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_SYN_FAIL"), DW_AT_const_value(-54)
$C$DW$1568	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NOT_ENOUGHT_DATA"), DW_AT_const_value(-55)
$C$DW$1569	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_ALLREADY_SET"), DW_AT_const_value(-56)
$C$DW$1570	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_DROPPED"), DW_AT_const_value(-57)
$C$DW$1571	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_STREAM_OPENED"), DW_AT_const_value(-58)
$C$DW$1572	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_STREAM_NOT_OPENED"), DW_AT_const_value(-59)
$C$DW$1573	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NOT_INITIALIZED"), DW_AT_const_value(-60)
$C$DW$1574	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_TOO_BIG_PROCESS_ID"), DW_AT_const_value(-61)
$C$DW$1575	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_BAD_ACTION"), DW_AT_const_value(-62)
$C$DW$1576	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_OUT_OF_A_RANGE"), DW_AT_const_value(-63)
$C$DW$1577	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_SYN_TIMEOUT"), DW_AT_const_value(-64)
$C$DW$1578	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_DRIVER_UNLOADED"), DW_AT_const_value(-65)
$C$DW$1579	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NO_DRIVER"), DW_AT_const_value(-66)
$C$DW$1580	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NODE_EXISTS"), DW_AT_const_value(-67)
$C$DW$1581	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_LOOPBACK_PHY"), DW_AT_const_value(-68)
$C$DW$1582	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_WRONG_QUEUE_SIZE"), DW_AT_const_value(-69)
$C$DW$1583	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_RTC_WRITE"), DW_AT_const_value(-70)
$C$DW$1584	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_RTC_READ"), DW_AT_const_value(-71)
$C$DW$1585	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_RTC_TEST"), DW_AT_const_value(-72)
$C$DW$1586	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_RTC_TICK"), DW_AT_const_value(-73)
$C$DW$1587	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NO_PHY"), DW_AT_const_value(-74)
$C$DW$1588	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_PHY_ERROR"), DW_AT_const_value(-75)
$C$DW$1589	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_LINK_TEST"), DW_AT_const_value(-76)
$C$DW$1590	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NAME_EXISTS"), DW_AT_const_value(-77)
$C$DW$1591	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_BAD_NAME"), DW_AT_const_value(-78)
$C$DW$1592	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_RESOURCE_BUSY"), DW_AT_const_value(-79)
$C$DW$1593	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_RESOURCE_POOL_BUSY"), DW_AT_const_value(-80)
$C$DW$1594	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_RESOURCE_LIMIT_REACHED"), DW_AT_const_value(-81)
$C$DW$1595	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_BAD_RESOURCE_INDEX"), DW_AT_const_value(-82)
$C$DW$1596	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NO_DATA"), DW_AT_const_value(-83)
	.dwendtag $C$DW$T$760


$C$DW$T$762	.dwtag  DW_TAG_enumeration_type
	.dwattr $C$DW$T$762, DW_AT_name("an_error_code")
	.dwattr $C$DW$T$762, DW_AT_byte_size(0x04)
$C$DW$1597	.dwtag  DW_TAG_enumerator, DW_AT_name("ec_none"), DW_AT_const_value(0x00)
$C$DW$1598	.dwtag  DW_TAG_enumerator, DW_AT_name("ec_abort_header"), DW_AT_const_value(0x01)
$C$DW$1599	.dwtag  DW_TAG_enumerator, DW_AT_name("ec_terminate_called"), DW_AT_const_value(0x02)
$C$DW$1600	.dwtag  DW_TAG_enumerator, DW_AT_name("ec_terminate_returned"), DW_AT_const_value(0x03)
$C$DW$1601	.dwtag  DW_TAG_enumerator, DW_AT_name("ec_already_marked_for_destruction"), DW_AT_const_value(0x04)
$C$DW$1602	.dwtag  DW_TAG_enumerator, DW_AT_name("ec_main_called_more_than_once"), DW_AT_const_value(0x05)
$C$DW$1603	.dwtag  DW_TAG_enumerator, DW_AT_name("ec_pure_virtual_called"), DW_AT_const_value(0x06)
$C$DW$1604	.dwtag  DW_TAG_enumerator, DW_AT_name("ec_bad_cast"), DW_AT_const_value(0x07)
$C$DW$1605	.dwtag  DW_TAG_enumerator, DW_AT_name("ec_bad_typeid"), DW_AT_const_value(0x08)
$C$DW$1606	.dwtag  DW_TAG_enumerator, DW_AT_name("ec_array_not_from_vec_new"), DW_AT_const_value(0x09)
$C$DW$1607	.dwtag  DW_TAG_enumerator, DW_AT_name("ec_last"), DW_AT_const_value(0x0a)
	.dwendtag $C$DW$T$762


$C$DW$T$763	.dwtag  DW_TAG_enumeration_type
	.dwattr $C$DW$T$763, DW_AT_byte_size(0x04)
$C$DW$1608	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_IP"), DW_AT_const_value(0x00)
$C$DW$1609	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_ICMP"), DW_AT_const_value(0x01)
$C$DW$1610	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_IGMP"), DW_AT_const_value(0x02)
$C$DW$1611	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_IPIP"), DW_AT_const_value(0x04)
$C$DW$1612	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_TCP"), DW_AT_const_value(0x06)
$C$DW$1613	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_EGP"), DW_AT_const_value(0x08)
$C$DW$1614	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_PUP"), DW_AT_const_value(0x0c)
$C$DW$1615	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_UDP"), DW_AT_const_value(0x11)
$C$DW$1616	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_IDP"), DW_AT_const_value(0x16)
$C$DW$1617	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_DCCP"), DW_AT_const_value(0x21)
$C$DW$1618	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_RSVP"), DW_AT_const_value(0x2e)
$C$DW$1619	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_GRE"), DW_AT_const_value(0x2f)
$C$DW$1620	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_IPV6"), DW_AT_const_value(0x29)
$C$DW$1621	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_ESP"), DW_AT_const_value(0x32)
$C$DW$1622	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_AH"), DW_AT_const_value(0x33)
$C$DW$1623	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_BEETPH"), DW_AT_const_value(0x5e)
$C$DW$1624	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_PIM"), DW_AT_const_value(0x67)
$C$DW$1625	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_COMP"), DW_AT_const_value(0x6c)
$C$DW$1626	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_SCTP"), DW_AT_const_value(0x84)
$C$DW$1627	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_UDPLITE"), DW_AT_const_value(0x88)
$C$DW$1628	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_RAW"), DW_AT_const_value(0xff)
$C$DW$1629	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_MAX"), DW_AT_const_value(0x100)
	.dwendtag $C$DW$T$763


$C$DW$T$764	.dwtag  DW_TAG_enumeration_type
	.dwattr $C$DW$T$764, DW_AT_name("sock_type")
	.dwattr $C$DW$T$764, DW_AT_byte_size(0x04)
$C$DW$1630	.dwtag  DW_TAG_enumerator, DW_AT_name("SOCK_STREAM"), DW_AT_const_value(0x01)
$C$DW$1631	.dwtag  DW_TAG_enumerator, DW_AT_name("SOCK_DGRAM"), DW_AT_const_value(0x02)
$C$DW$1632	.dwtag  DW_TAG_enumerator, DW_AT_name("SOCK_RAW"), DW_AT_const_value(0x03)
$C$DW$1633	.dwtag  DW_TAG_enumerator, DW_AT_name("SOCK_RDM"), DW_AT_const_value(0x04)
$C$DW$1634	.dwtag  DW_TAG_enumerator, DW_AT_name("SOCK_SEQPACKET"), DW_AT_const_value(0x05)
$C$DW$1635	.dwtag  DW_TAG_enumerator, DW_AT_name("SOCK_DCCP"), DW_AT_const_value(0x06)
$C$DW$1636	.dwtag  DW_TAG_enumerator, DW_AT_name("SOCK_PACKET"), DW_AT_const_value(0x0a)
	.dwendtag $C$DW$T$764


$C$DW$T$765	.dwtag  DW_TAG_enumeration_type
	.dwattr $C$DW$T$765, DW_AT_byte_size(0x04)
$C$DW$1637	.dwtag  DW_TAG_enumerator, DW_AT_name("START"), DW_AT_const_value(0xd0000)
$C$DW$1638	.dwtag  DW_TAG_enumerator, DW_AT_name("START_SIALP"), DW_AT_const_value(0xd0001)
$C$DW$1639	.dwtag  DW_TAG_enumerator, DW_AT_name("START_CIKL"), DW_AT_const_value(0xd0002)
$C$DW$1640	.dwtag  DW_TAG_enumerator, DW_AT_name("GOTOV_PP"), DW_AT_const_value(0xd0003)
$C$DW$1641	.dwtag  DW_TAG_enumerator, DW_AT_name("STOP_CIKL"), DW_AT_const_value(0xd0004)
$C$DW$1642	.dwtag  DW_TAG_enumerator, DW_AT_name("N_TEST"), DW_AT_const_value(0xd0005)
$C$DW$1643	.dwtag  DW_TAG_enumerator, DW_AT_name("GOTOV_TEST"), DW_AT_const_value(0xd0006)
$C$DW$1644	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_NOT_READY"), DW_AT_const_value(0xd0007)
$C$DW$1645	.dwtag  DW_TAG_enumerator, DW_AT_name("RES_N_TEST"), DW_AT_const_value(0xd0008)
$C$DW$1646	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_SDRAM_FULL"), DW_AT_const_value(0xd0009)
$C$DW$1647	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_NVRAM_FULL"), DW_AT_const_value(0xd000a)
$C$DW$1648	.dwtag  DW_TAG_enumerator, DW_AT_name("START_TEST_DOZU_NAGR"), DW_AT_const_value(0xd000b)
$C$DW$1649	.dwtag  DW_TAG_enumerator, DW_AT_name("RES_TEST_DOZU_NAGR"), DW_AT_const_value(0xd000c)
$C$DW$1650	.dwtag  DW_TAG_enumerator, DW_AT_name("STOP_TEST_DOZU_NAGR"), DW_AT_const_value(0xd000d)
$C$DW$1651	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_CR_SERVISE"), DW_AT_const_value(0xd000e)
$C$DW$1652	.dwtag  DW_TAG_enumerator, DW_AT_name("START_TEST_ROM"), DW_AT_const_value(0xd000f)
$C$DW$1653	.dwtag  DW_TAG_enumerator, DW_AT_name("RES_TEST_ROM_CP0"), DW_AT_const_value(0xd0010)
$C$DW$1654	.dwtag  DW_TAG_enumerator, DW_AT_name("RES_TEST_ROM_CP1"), DW_AT_const_value(0xd0011)
$C$DW$1655	.dwtag  DW_TAG_enumerator, DW_AT_name("STOP_TEST_ROM"), DW_AT_const_value(0xd0012)
$C$DW$1656	.dwtag  DW_TAG_enumerator, DW_AT_name("START_TEST_CR_CH"), DW_AT_const_value(0xd0013)
$C$DW$1657	.dwtag  DW_TAG_enumerator, DW_AT_name("RES_TEST_CR_CH"), DW_AT_const_value(0xd0014)
$C$DW$1658	.dwtag  DW_TAG_enumerator, DW_AT_name("STOP_TEST_CR_CH"), DW_AT_const_value(0xd0015)
$C$DW$1659	.dwtag  DW_TAG_enumerator, DW_AT_name("CLEAR_TEST_PACKET"), DW_AT_const_value(0xd0016)
$C$DW$1660	.dwtag  DW_TAG_enumerator, DW_AT_name("RECV_TEST_PACKET"), DW_AT_const_value(0xd0017)
$C$DW$1661	.dwtag  DW_TAG_enumerator, DW_AT_name("SEND_TEST_PACKET"), DW_AT_const_value(0xd0018)
$C$DW$1662	.dwtag  DW_TAG_enumerator, DW_AT_name("START_TEST_MOVE"), DW_AT_const_value(0xd0019)
$C$DW$1663	.dwtag  DW_TAG_enumerator, DW_AT_name("GOTOV_TEST_MOVE_15"), DW_AT_const_value(0xd001a)
$C$DW$1664	.dwtag  DW_TAG_enumerator, DW_AT_name("GOTOV_TEST_MOVE_1A"), DW_AT_const_value(0xd001b)
$C$DW$1665	.dwtag  DW_TAG_enumerator, DW_AT_name("GOTOV_TEST_MOVE_25"), DW_AT_const_value(0xd001c)
$C$DW$1666	.dwtag  DW_TAG_enumerator, DW_AT_name("GOTOV_TEST_MOVE_2A"), DW_AT_const_value(0xd001d)
$C$DW$1667	.dwtag  DW_TAG_enumerator, DW_AT_name("RES_TEST_MOVE"), DW_AT_const_value(0xd001e)
$C$DW$1668	.dwtag  DW_TAG_enumerator, DW_AT_name("STOP_TEST_MOVE"), DW_AT_const_value(0xd001f)
$C$DW$1669	.dwtag  DW_TAG_enumerator, DW_AT_name("GET_RES_FROM_DOZU"), DW_AT_const_value(0xd0020)
$C$DW$1670	.dwtag  DW_TAG_enumerator, DW_AT_name("INF_ABOUT_USB"), DW_AT_const_value(0xd0021)
$C$DW$1671	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_IPMP"), DW_AT_const_value(0xd0022)
$C$DW$1672	.dwtag  DW_TAG_enumerator, DW_AT_name("ASK_CMD"), DW_AT_const_value(0xd0023)
$C$DW$1673	.dwtag  DW_TAG_enumerator, DW_AT_name("OPEN_SV_MSG"), DW_AT_const_value(0xd0024)
$C$DW$1674	.dwtag  DW_TAG_enumerator, DW_AT_name("CLOSE_SV_MSG"), DW_AT_const_value(0xd0025)
$C$DW$1675	.dwtag  DW_TAG_enumerator, DW_AT_name("ERROR_CMD"), DW_AT_const_value(0xd0026)
$C$DW$1676	.dwtag  DW_TAG_enumerator, DW_AT_name("STOP_TX"), DW_AT_const_value(0xd0027)
$C$DW$1677	.dwtag  DW_TAG_enumerator, DW_AT_name("EXIT_TPO"), DW_AT_const_value(0xd0028)
$C$DW$1678	.dwtag  DW_TAG_enumerator, DW_AT_name("LOAD_LIF"), DW_AT_const_value(0xd0029)
$C$DW$1679	.dwtag  DW_TAG_enumerator, DW_AT_name("START_LIF"), DW_AT_const_value(0xd002a)
$C$DW$1680	.dwtag  DW_TAG_enumerator, DW_AT_name("START_LOAD_PO"), DW_AT_const_value(0xd002b)
$C$DW$1681	.dwtag  DW_TAG_enumerator, DW_AT_name("WRITE_PO_TO_FLASH"), DW_AT_const_value(0xd002c)
	.dwendtag $C$DW$T$765


$C$DW$T$766	.dwtag  DW_TAG_enumeration_type
	.dwattr $C$DW$T$766, DW_AT_byte_size(0x04)
$C$DW$1682	.dwtag  DW_TAG_enumerator, DW_AT_name("CELOSTN"), DW_AT_const_value(0x15)
$C$DW$1683	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_SDRAM"), DW_AT_const_value(0x1a)
$C$DW$1684	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_NVRAM"), DW_AT_const_value(0x1b)
$C$DW$1685	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_USB_CONTR"), DW_AT_const_value(0x1d)
$C$DW$1686	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_USB_FLASH"), DW_AT_const_value(0x1e)
$C$DW$1687	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_DOZU"), DW_AT_const_value(0x20)
$C$DW$1688	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_DOZU_ST1"), DW_AT_const_value(0x21)
$C$DW$1689	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_DOZU_ST2"), DW_AT_const_value(0x22)
$C$DW$1690	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_DOZU_ST3"), DW_AT_const_value(0x23)
$C$DW$1691	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_MOVE"), DW_AT_const_value(0x24)
$C$DW$1692	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_MOVE_ST1"), DW_AT_const_value(0x25)
$C$DW$1693	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_MOVE_ST2"), DW_AT_const_value(0x26)
$C$DW$1694	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_MOVE_ST3"), DW_AT_const_value(0x27)
$C$DW$1695	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_SK"), DW_AT_const_value(0x28)
$C$DW$1696	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_SK1"), DW_AT_const_value(0x29)
$C$DW$1697	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_SK2"), DW_AT_const_value(0x2a)
$C$DW$1698	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_SK3"), DW_AT_const_value(0x2b)
$C$DW$1699	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_DNSD_CRC"), DW_AT_const_value(0x2c)
$C$DW$1700	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_DNSD_VD10"), DW_AT_const_value(0x2d)
$C$DW$1701	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_DNSD_VD11"), DW_AT_const_value(0x2e)
$C$DW$1702	.dwtag  DW_TAG_enumerator, DW_AT_name("ZAVESTI_DNSD"), DW_AT_const_value(0x2f)
$C$DW$1703	.dwtag  DW_TAG_enumerator, DW_AT_name("PROCHITAT"), DW_AT_const_value(0x30)
$C$DW$1704	.dwtag  DW_TAG_enumerator, DW_AT_name("VKL_VD10"), DW_AT_const_value(0x31)
$C$DW$1705	.dwtag  DW_TAG_enumerator, DW_AT_name("VKL_VD11"), DW_AT_const_value(0x32)
$C$DW$1706	.dwtag  DW_TAG_enumerator, DW_AT_name("VIKL_VD11"), DW_AT_const_value(0x33)
$C$DW$1707	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_DNSD_OSVESCH"), DW_AT_const_value(0x34)
$C$DW$1708	.dwtag  DW_TAG_enumerator, DW_AT_name("MAGIC_NUMBER"), DW_AT_const_value(0x35)
$C$DW$1709	.dwtag  DW_TAG_enumerator, DW_AT_name("CELOSTN_PP056"), DW_AT_const_value(0x36)
$C$DW$1710	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_CDROM"), DW_AT_const_value(0x37)
$C$DW$1711	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_RAID"), DW_AT_const_value(0x38)
$C$DW$1712	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_USB3"), DW_AT_const_value(0x39)
$C$DW$1713	.dwtag  DW_TAG_enumerator, DW_AT_name("CIKL"), DW_AT_const_value(0x64)
$C$DW$1714	.dwtag  DW_TAG_enumerator, DW_AT_name("CIKL_NOT_READY"), DW_AT_const_value(0x65)
	.dwendtag $C$DW$T$766


$C$DW$T$767	.dwtag  DW_TAG_enumeration_type
	.dwattr $C$DW$T$767, DW_AT_byte_size(0x04)
$C$DW$1715	.dwtag  DW_TAG_enumerator, DW_AT_name("MAIN_TIME_OUT"), DW_AT_const_value(0x00)
$C$DW$1716	.dwtag  DW_TAG_enumerator, DW_AT_name("COMM_TIME_OUT"), DW_AT_const_value(0x01)
$C$DW$1717	.dwtag  DW_TAG_enumerator, DW_AT_name("COMM1_TIME_OUT"), DW_AT_const_value(0x02)
$C$DW$1718	.dwtag  DW_TAG_enumerator, DW_AT_name("COMM2_TIME_OUT"), DW_AT_const_value(0x03)
$C$DW$1719	.dwtag  DW_TAG_enumerator, DW_AT_name("COMM3_TIME_OUT"), DW_AT_const_value(0x04)
$C$DW$1720	.dwtag  DW_TAG_enumerator, DW_AT_name("MAIN_ERR_MSG"), DW_AT_const_value(0x05)
$C$DW$1721	.dwtag  DW_TAG_enumerator, DW_AT_name("MAIN_ERR_MSG_CICL_RES"), DW_AT_const_value(0x06)
$C$DW$1722	.dwtag  DW_TAG_enumerator, DW_AT_name("COMM_ERR_MSG"), DW_AT_const_value(0x07)
$C$DW$1723	.dwtag  DW_TAG_enumerator, DW_AT_name("COMM1_ERR_MSG"), DW_AT_const_value(0x08)
$C$DW$1724	.dwtag  DW_TAG_enumerator, DW_AT_name("COMM2_ERR_MSG"), DW_AT_const_value(0x09)
$C$DW$1725	.dwtag  DW_TAG_enumerator, DW_AT_name("COMM3_ERR_MSG"), DW_AT_const_value(0x0a)
$C$DW$1726	.dwtag  DW_TAG_enumerator, DW_AT_name("DRV_ERR"), DW_AT_const_value(0x0b)
$C$DW$1727	.dwtag  DW_TAG_enumerator, DW_AT_name("ERR_MSG_OPEN"), DW_AT_const_value(0x0c)
$C$DW$1728	.dwtag  DW_TAG_enumerator, DW_AT_name("NO_MEM_COMM"), DW_AT_const_value(0x0d)
$C$DW$1729	.dwtag  DW_TAG_enumerator, DW_AT_name("NO_MEM_COMM1"), DW_AT_const_value(0x0e)
$C$DW$1730	.dwtag  DW_TAG_enumerator, DW_AT_name("NO_MEM_MAIN"), DW_AT_const_value(0x0f)
$C$DW$1731	.dwtag  DW_TAG_enumerator, DW_AT_name("NO_MEM_IFACE"), DW_AT_const_value(0x10)
	.dwendtag $C$DW$T$767

$C$DW$T$777	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$777, DW_AT_encoding(DW_ATE_signed_char)
	.dwattr $C$DW$T$777, DW_AT_name("signed char")
	.dwattr $C$DW$T$777, DW_AT_byte_size(0x01)
	.dwattr $C$DW$CU, DW_AT_language(DW_LANG_C_plus_plus)

;***************************************************************
;* DWARF CIE ENTRIES                                           *
;***************************************************************

$C$DW$CIE	.dwcie 228
	.dwcfi	cfa_register, 31
	.dwcfi	cfa_offset, 0
	.dwcfi	undefined, 0
	.dwcfi	undefined, 1
	.dwcfi	undefined, 2
	.dwcfi	undefined, 3
	.dwcfi	undefined, 4
	.dwcfi	undefined, 5
	.dwcfi	undefined, 6
	.dwcfi	undefined, 7
	.dwcfi	undefined, 8
	.dwcfi	undefined, 9
	.dwcfi	same_value, 10
	.dwcfi	same_value, 11
	.dwcfi	same_value, 12
	.dwcfi	same_value, 13
	.dwcfi	same_value, 14
	.dwcfi	same_value, 15
	.dwcfi	undefined, 16
	.dwcfi	undefined, 17
	.dwcfi	undefined, 18
	.dwcfi	undefined, 19
	.dwcfi	undefined, 20
	.dwcfi	undefined, 21
	.dwcfi	undefined, 22
	.dwcfi	undefined, 23
	.dwcfi	undefined, 24
	.dwcfi	undefined, 25
	.dwcfi	same_value, 26
	.dwcfi	same_value, 27
	.dwcfi	same_value, 28
	.dwcfi	same_value, 29
	.dwcfi	same_value, 30
	.dwcfi	same_value, 31
	.dwcfi	same_value, 32
	.dwcfi	undefined, 33
	.dwcfi	undefined, 34
	.dwcfi	undefined, 35
	.dwcfi	undefined, 36
	.dwcfi	undefined, 37
	.dwcfi	undefined, 38
	.dwcfi	undefined, 39
	.dwcfi	undefined, 40
	.dwcfi	undefined, 41
	.dwcfi	undefined, 42
	.dwcfi	undefined, 43
	.dwcfi	undefined, 44
	.dwcfi	undefined, 45
	.dwcfi	undefined, 46
	.dwcfi	undefined, 47
	.dwcfi	undefined, 48
	.dwcfi	undefined, 49
	.dwcfi	undefined, 50
	.dwcfi	undefined, 51
	.dwcfi	undefined, 52
	.dwcfi	undefined, 53
	.dwcfi	undefined, 54
	.dwcfi	undefined, 55
	.dwcfi	undefined, 56
	.dwcfi	undefined, 57
	.dwcfi	undefined, 58
	.dwcfi	undefined, 59
	.dwcfi	undefined, 60
	.dwcfi	undefined, 61
	.dwcfi	undefined, 62
	.dwcfi	undefined, 63
	.dwcfi	undefined, 64
	.dwcfi	undefined, 65
	.dwcfi	undefined, 66
	.dwcfi	undefined, 67
	.dwcfi	undefined, 68
	.dwcfi	undefined, 69
	.dwcfi	undefined, 70
	.dwcfi	undefined, 71
	.dwcfi	undefined, 72
	.dwcfi	undefined, 73
	.dwcfi	undefined, 74
	.dwcfi	undefined, 75
	.dwcfi	undefined, 76
	.dwcfi	undefined, 77
	.dwcfi	undefined, 78
	.dwcfi	undefined, 79
	.dwcfi	undefined, 80
	.dwcfi	undefined, 81
	.dwcfi	undefined, 82
	.dwcfi	undefined, 83
	.dwcfi	undefined, 84
	.dwcfi	undefined, 85
	.dwcfi	undefined, 86
	.dwcfi	undefined, 87
	.dwcfi	undefined, 88
	.dwcfi	undefined, 89
	.dwcfi	undefined, 90
	.dwcfi	undefined, 91
	.dwcfi	undefined, 92
	.dwcfi	undefined, 93
	.dwcfi	undefined, 94
	.dwcfi	undefined, 95
	.dwcfi	undefined, 96
	.dwcfi	undefined, 97
	.dwcfi	undefined, 98
	.dwcfi	undefined, 99
	.dwcfi	undefined, 100
	.dwcfi	undefined, 101
	.dwcfi	undefined, 102
	.dwcfi	undefined, 103
	.dwcfi	undefined, 104
	.dwcfi	undefined, 105
	.dwcfi	undefined, 106
	.dwcfi	undefined, 107
	.dwcfi	undefined, 108
	.dwcfi	undefined, 109
	.dwcfi	undefined, 110
	.dwcfi	undefined, 111
	.dwcfi	undefined, 112
	.dwcfi	undefined, 113
	.dwcfi	undefined, 114
	.dwcfi	undefined, 115
	.dwcfi	undefined, 116
	.dwcfi	undefined, 117
	.dwcfi	undefined, 118
	.dwcfi	undefined, 119
	.dwcfi	undefined, 120
	.dwcfi	undefined, 121
	.dwcfi	undefined, 122
	.dwcfi	undefined, 123
	.dwcfi	undefined, 124
	.dwcfi	undefined, 125
	.dwcfi	undefined, 126
	.dwcfi	undefined, 127
	.dwcfi	undefined, 128
	.dwcfi	undefined, 129
	.dwcfi	undefined, 130
	.dwcfi	undefined, 131
	.dwcfi	undefined, 132
	.dwcfi	undefined, 133
	.dwcfi	undefined, 134
	.dwcfi	undefined, 135
	.dwcfi	undefined, 136
	.dwcfi	undefined, 137
	.dwcfi	undefined, 138
	.dwcfi	undefined, 139
	.dwcfi	undefined, 140
	.dwcfi	undefined, 141
	.dwcfi	undefined, 142
	.dwcfi	undefined, 143
	.dwcfi	undefined, 144
	.dwcfi	undefined, 145
	.dwcfi	undefined, 146
	.dwcfi	undefined, 147
	.dwcfi	undefined, 148
	.dwcfi	undefined, 149
	.dwcfi	undefined, 150
	.dwcfi	undefined, 151
	.dwcfi	undefined, 152
	.dwcfi	undefined, 153
	.dwcfi	undefined, 154
	.dwcfi	undefined, 155
	.dwcfi	undefined, 156
	.dwcfi	undefined, 157
	.dwcfi	undefined, 158
	.dwcfi	undefined, 159
	.dwcfi	undefined, 160
	.dwcfi	undefined, 161
	.dwcfi	undefined, 162
	.dwcfi	undefined, 163
	.dwcfi	undefined, 164
	.dwcfi	undefined, 165
	.dwcfi	undefined, 166
	.dwcfi	undefined, 167
	.dwcfi	undefined, 168
	.dwcfi	undefined, 169
	.dwcfi	undefined, 170
	.dwcfi	undefined, 171
	.dwcfi	undefined, 172
	.dwcfi	undefined, 173
	.dwcfi	undefined, 174
	.dwcfi	undefined, 175
	.dwcfi	undefined, 176
	.dwcfi	undefined, 177
	.dwcfi	undefined, 178
	.dwcfi	undefined, 179
	.dwcfi	undefined, 180
	.dwcfi	undefined, 181
	.dwcfi	undefined, 182
	.dwcfi	undefined, 183
	.dwcfi	undefined, 184
	.dwcfi	undefined, 185
	.dwcfi	undefined, 186
	.dwcfi	undefined, 187
	.dwcfi	undefined, 188
	.dwcfi	undefined, 189
	.dwcfi	undefined, 190
	.dwcfi	undefined, 191
	.dwcfi	undefined, 192
	.dwcfi	undefined, 193
	.dwcfi	undefined, 194
	.dwcfi	undefined, 195
	.dwcfi	undefined, 196
	.dwcfi	undefined, 197
	.dwcfi	undefined, 198
	.dwcfi	undefined, 199
	.dwcfi	undefined, 200
	.dwcfi	undefined, 201
	.dwcfi	undefined, 202
	.dwcfi	undefined, 203
	.dwcfi	undefined, 204
	.dwcfi	undefined, 205
	.dwcfi	undefined, 206
	.dwcfi	undefined, 207
	.dwcfi	undefined, 208
	.dwcfi	undefined, 209
	.dwcfi	undefined, 210
	.dwcfi	undefined, 211
	.dwcfi	undefined, 212
	.dwcfi	undefined, 213
	.dwcfi	undefined, 214
	.dwcfi	undefined, 215
	.dwcfi	undefined, 216
	.dwcfi	undefined, 217
	.dwcfi	undefined, 218
	.dwcfi	undefined, 219
	.dwcfi	undefined, 220
	.dwcfi	undefined, 221
	.dwcfi	undefined, 222
	.dwcfi	undefined, 223
	.dwcfi	undefined, 224
	.dwcfi	undefined, 225
	.dwcfi	undefined, 226
	.dwcfi	undefined, 227
	.dwcfi	undefined, 228
	.dwendentry

;***************************************************************
;* DWARF REGISTER MAP                                          *
;***************************************************************

$C$DW$1732	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A0")
	.dwattr $C$DW$1732, DW_AT_location[DW_OP_reg0]
$C$DW$1733	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A1")
	.dwattr $C$DW$1733, DW_AT_location[DW_OP_reg1]
$C$DW$1734	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A2")
	.dwattr $C$DW$1734, DW_AT_location[DW_OP_reg2]
$C$DW$1735	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A3")
	.dwattr $C$DW$1735, DW_AT_location[DW_OP_reg3]
$C$DW$1736	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A4")
	.dwattr $C$DW$1736, DW_AT_location[DW_OP_reg4]
$C$DW$1737	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A5")
	.dwattr $C$DW$1737, DW_AT_location[DW_OP_reg5]
$C$DW$1738	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A6")
	.dwattr $C$DW$1738, DW_AT_location[DW_OP_reg6]
$C$DW$1739	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A7")
	.dwattr $C$DW$1739, DW_AT_location[DW_OP_reg7]
$C$DW$1740	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A8")
	.dwattr $C$DW$1740, DW_AT_location[DW_OP_reg8]
$C$DW$1741	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A9")
	.dwattr $C$DW$1741, DW_AT_location[DW_OP_reg9]
$C$DW$1742	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A10")
	.dwattr $C$DW$1742, DW_AT_location[DW_OP_reg10]
$C$DW$1743	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A11")
	.dwattr $C$DW$1743, DW_AT_location[DW_OP_reg11]
$C$DW$1744	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A12")
	.dwattr $C$DW$1744, DW_AT_location[DW_OP_reg12]
$C$DW$1745	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A13")
	.dwattr $C$DW$1745, DW_AT_location[DW_OP_reg13]
$C$DW$1746	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A14")
	.dwattr $C$DW$1746, DW_AT_location[DW_OP_reg14]
$C$DW$1747	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A15")
	.dwattr $C$DW$1747, DW_AT_location[DW_OP_reg15]
$C$DW$1748	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B0")
	.dwattr $C$DW$1748, DW_AT_location[DW_OP_reg16]
$C$DW$1749	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B1")
	.dwattr $C$DW$1749, DW_AT_location[DW_OP_reg17]
$C$DW$1750	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B2")
	.dwattr $C$DW$1750, DW_AT_location[DW_OP_reg18]
$C$DW$1751	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B3")
	.dwattr $C$DW$1751, DW_AT_location[DW_OP_reg19]
$C$DW$1752	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B4")
	.dwattr $C$DW$1752, DW_AT_location[DW_OP_reg20]
$C$DW$1753	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B5")
	.dwattr $C$DW$1753, DW_AT_location[DW_OP_reg21]
$C$DW$1754	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B6")
	.dwattr $C$DW$1754, DW_AT_location[DW_OP_reg22]
$C$DW$1755	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B7")
	.dwattr $C$DW$1755, DW_AT_location[DW_OP_reg23]
$C$DW$1756	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B8")
	.dwattr $C$DW$1756, DW_AT_location[DW_OP_reg24]
$C$DW$1757	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B9")
	.dwattr $C$DW$1757, DW_AT_location[DW_OP_reg25]
$C$DW$1758	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B10")
	.dwattr $C$DW$1758, DW_AT_location[DW_OP_reg26]
$C$DW$1759	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B11")
	.dwattr $C$DW$1759, DW_AT_location[DW_OP_reg27]
$C$DW$1760	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B12")
	.dwattr $C$DW$1760, DW_AT_location[DW_OP_reg28]
$C$DW$1761	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B13")
	.dwattr $C$DW$1761, DW_AT_location[DW_OP_reg29]
$C$DW$1762	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("DP")
	.dwattr $C$DW$1762, DW_AT_location[DW_OP_reg30]
$C$DW$1763	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("SP")
	.dwattr $C$DW$1763, DW_AT_location[DW_OP_reg31]
$C$DW$1764	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("FP")
	.dwattr $C$DW$1764, DW_AT_location[DW_OP_regx 0x20]
$C$DW$1765	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("PC")
	.dwattr $C$DW$1765, DW_AT_location[DW_OP_regx 0x21]
$C$DW$1766	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("IRP")
	.dwattr $C$DW$1766, DW_AT_location[DW_OP_regx 0x22]
$C$DW$1767	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("IFR")
	.dwattr $C$DW$1767, DW_AT_location[DW_OP_regx 0x23]
$C$DW$1768	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("NRP")
	.dwattr $C$DW$1768, DW_AT_location[DW_OP_regx 0x24]
$C$DW$1769	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A16")
	.dwattr $C$DW$1769, DW_AT_location[DW_OP_regx 0x25]
$C$DW$1770	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A17")
	.dwattr $C$DW$1770, DW_AT_location[DW_OP_regx 0x26]
$C$DW$1771	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A18")
	.dwattr $C$DW$1771, DW_AT_location[DW_OP_regx 0x27]
$C$DW$1772	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A19")
	.dwattr $C$DW$1772, DW_AT_location[DW_OP_regx 0x28]
$C$DW$1773	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A20")
	.dwattr $C$DW$1773, DW_AT_location[DW_OP_regx 0x29]
$C$DW$1774	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A21")
	.dwattr $C$DW$1774, DW_AT_location[DW_OP_regx 0x2a]
$C$DW$1775	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A22")
	.dwattr $C$DW$1775, DW_AT_location[DW_OP_regx 0x2b]
$C$DW$1776	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A23")
	.dwattr $C$DW$1776, DW_AT_location[DW_OP_regx 0x2c]
$C$DW$1777	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A24")
	.dwattr $C$DW$1777, DW_AT_location[DW_OP_regx 0x2d]
$C$DW$1778	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A25")
	.dwattr $C$DW$1778, DW_AT_location[DW_OP_regx 0x2e]
$C$DW$1779	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A26")
	.dwattr $C$DW$1779, DW_AT_location[DW_OP_regx 0x2f]
$C$DW$1780	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A27")
	.dwattr $C$DW$1780, DW_AT_location[DW_OP_regx 0x30]
$C$DW$1781	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A28")
	.dwattr $C$DW$1781, DW_AT_location[DW_OP_regx 0x31]
$C$DW$1782	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A29")
	.dwattr $C$DW$1782, DW_AT_location[DW_OP_regx 0x32]
$C$DW$1783	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A30")
	.dwattr $C$DW$1783, DW_AT_location[DW_OP_regx 0x33]
$C$DW$1784	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A31")
	.dwattr $C$DW$1784, DW_AT_location[DW_OP_regx 0x34]
$C$DW$1785	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B16")
	.dwattr $C$DW$1785, DW_AT_location[DW_OP_regx 0x35]
$C$DW$1786	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B17")
	.dwattr $C$DW$1786, DW_AT_location[DW_OP_regx 0x36]
$C$DW$1787	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B18")
	.dwattr $C$DW$1787, DW_AT_location[DW_OP_regx 0x37]
$C$DW$1788	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B19")
	.dwattr $C$DW$1788, DW_AT_location[DW_OP_regx 0x38]
$C$DW$1789	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B20")
	.dwattr $C$DW$1789, DW_AT_location[DW_OP_regx 0x39]
$C$DW$1790	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B21")
	.dwattr $C$DW$1790, DW_AT_location[DW_OP_regx 0x3a]
$C$DW$1791	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B22")
	.dwattr $C$DW$1791, DW_AT_location[DW_OP_regx 0x3b]
$C$DW$1792	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B23")
	.dwattr $C$DW$1792, DW_AT_location[DW_OP_regx 0x3c]
$C$DW$1793	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B24")
	.dwattr $C$DW$1793, DW_AT_location[DW_OP_regx 0x3d]
$C$DW$1794	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B25")
	.dwattr $C$DW$1794, DW_AT_location[DW_OP_regx 0x3e]
$C$DW$1795	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B26")
	.dwattr $C$DW$1795, DW_AT_location[DW_OP_regx 0x3f]
$C$DW$1796	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B27")
	.dwattr $C$DW$1796, DW_AT_location[DW_OP_regx 0x40]
$C$DW$1797	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B28")
	.dwattr $C$DW$1797, DW_AT_location[DW_OP_regx 0x41]
$C$DW$1798	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B29")
	.dwattr $C$DW$1798, DW_AT_location[DW_OP_regx 0x42]
$C$DW$1799	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B30")
	.dwattr $C$DW$1799, DW_AT_location[DW_OP_regx 0x43]
$C$DW$1800	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B31")
	.dwattr $C$DW$1800, DW_AT_location[DW_OP_regx 0x44]
$C$DW$1801	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AMR")
	.dwattr $C$DW$1801, DW_AT_location[DW_OP_regx 0x45]
$C$DW$1802	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("CSR")
	.dwattr $C$DW$1802, DW_AT_location[DW_OP_regx 0x46]
$C$DW$1803	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ISR")
	.dwattr $C$DW$1803, DW_AT_location[DW_OP_regx 0x47]
$C$DW$1804	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ICR")
	.dwattr $C$DW$1804, DW_AT_location[DW_OP_regx 0x48]
$C$DW$1805	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("IER")
	.dwattr $C$DW$1805, DW_AT_location[DW_OP_regx 0x49]
$C$DW$1806	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ISTP")
	.dwattr $C$DW$1806, DW_AT_location[DW_OP_regx 0x4a]
$C$DW$1807	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("IN")
	.dwattr $C$DW$1807, DW_AT_location[DW_OP_regx 0x4b]
$C$DW$1808	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("OUT")
	.dwattr $C$DW$1808, DW_AT_location[DW_OP_regx 0x4c]
$C$DW$1809	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ACR")
	.dwattr $C$DW$1809, DW_AT_location[DW_OP_regx 0x4d]
$C$DW$1810	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ADR")
	.dwattr $C$DW$1810, DW_AT_location[DW_OP_regx 0x4e]
$C$DW$1811	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("FADCR")
	.dwattr $C$DW$1811, DW_AT_location[DW_OP_regx 0x4f]
$C$DW$1812	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("FAUCR")
	.dwattr $C$DW$1812, DW_AT_location[DW_OP_regx 0x50]
$C$DW$1813	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("FMCR")
	.dwattr $C$DW$1813, DW_AT_location[DW_OP_regx 0x51]
$C$DW$1814	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("GFPGFR")
	.dwattr $C$DW$1814, DW_AT_location[DW_OP_regx 0x52]
$C$DW$1815	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("DIER")
	.dwattr $C$DW$1815, DW_AT_location[DW_OP_regx 0x53]
$C$DW$1816	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("REP")
	.dwattr $C$DW$1816, DW_AT_location[DW_OP_regx 0x54]
$C$DW$1817	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("TSCL")
	.dwattr $C$DW$1817, DW_AT_location[DW_OP_regx 0x55]
$C$DW$1818	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("TSCH")
	.dwattr $C$DW$1818, DW_AT_location[DW_OP_regx 0x56]
$C$DW$1819	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ARP")
	.dwattr $C$DW$1819, DW_AT_location[DW_OP_regx 0x57]
$C$DW$1820	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ILC")
	.dwattr $C$DW$1820, DW_AT_location[DW_OP_regx 0x58]
$C$DW$1821	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("RILC")
	.dwattr $C$DW$1821, DW_AT_location[DW_OP_regx 0x59]
$C$DW$1822	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("DNUM")
	.dwattr $C$DW$1822, DW_AT_location[DW_OP_regx 0x5a]
$C$DW$1823	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("SSR")
	.dwattr $C$DW$1823, DW_AT_location[DW_OP_regx 0x5b]
$C$DW$1824	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("GPLYA")
	.dwattr $C$DW$1824, DW_AT_location[DW_OP_regx 0x5c]
$C$DW$1825	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("GPLYB")
	.dwattr $C$DW$1825, DW_AT_location[DW_OP_regx 0x5d]
$C$DW$1826	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("TSR")
	.dwattr $C$DW$1826, DW_AT_location[DW_OP_regx 0x5e]
$C$DW$1827	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ITSR")
	.dwattr $C$DW$1827, DW_AT_location[DW_OP_regx 0x5f]
$C$DW$1828	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("NTSR")
	.dwattr $C$DW$1828, DW_AT_location[DW_OP_regx 0x60]
$C$DW$1829	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("EFR")
	.dwattr $C$DW$1829, DW_AT_location[DW_OP_regx 0x61]
$C$DW$1830	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ECR")
	.dwattr $C$DW$1830, DW_AT_location[DW_OP_regx 0x62]
$C$DW$1831	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("IERR")
	.dwattr $C$DW$1831, DW_AT_location[DW_OP_regx 0x63]
$C$DW$1832	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("DMSG")
	.dwattr $C$DW$1832, DW_AT_location[DW_OP_regx 0x64]
$C$DW$1833	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("CMSG")
	.dwattr $C$DW$1833, DW_AT_location[DW_OP_regx 0x65]
$C$DW$1834	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("DT_DMA_ADDR")
	.dwattr $C$DW$1834, DW_AT_location[DW_OP_regx 0x66]
$C$DW$1835	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("DT_DMA_DATA")
	.dwattr $C$DW$1835, DW_AT_location[DW_OP_regx 0x67]
$C$DW$1836	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("DT_DMA_CNTL")
	.dwattr $C$DW$1836, DW_AT_location[DW_OP_regx 0x68]
$C$DW$1837	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("TCU_CNTL")
	.dwattr $C$DW$1837, DW_AT_location[DW_OP_regx 0x69]
$C$DW$1838	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("RTDX_REC_CNTL")
	.dwattr $C$DW$1838, DW_AT_location[DW_OP_regx 0x6a]
$C$DW$1839	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("RTDX_XMT_CNTL")
	.dwattr $C$DW$1839, DW_AT_location[DW_OP_regx 0x6b]
$C$DW$1840	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("RTDX_CFG")
	.dwattr $C$DW$1840, DW_AT_location[DW_OP_regx 0x6c]
$C$DW$1841	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("RTDX_RDATA")
	.dwattr $C$DW$1841, DW_AT_location[DW_OP_regx 0x6d]
$C$DW$1842	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("RTDX_WDATA")
	.dwattr $C$DW$1842, DW_AT_location[DW_OP_regx 0x6e]
$C$DW$1843	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("RTDX_RADDR")
	.dwattr $C$DW$1843, DW_AT_location[DW_OP_regx 0x6f]
$C$DW$1844	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("RTDX_WADDR")
	.dwattr $C$DW$1844, DW_AT_location[DW_OP_regx 0x70]
$C$DW$1845	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("MFREG0")
	.dwattr $C$DW$1845, DW_AT_location[DW_OP_regx 0x71]
$C$DW$1846	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("DBG_STAT")
	.dwattr $C$DW$1846, DW_AT_location[DW_OP_regx 0x72]
$C$DW$1847	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("BRK_EN")
	.dwattr $C$DW$1847, DW_AT_location[DW_OP_regx 0x73]
$C$DW$1848	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("HWBP0_CNT")
	.dwattr $C$DW$1848, DW_AT_location[DW_OP_regx 0x74]
$C$DW$1849	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("HWBP0")
	.dwattr $C$DW$1849, DW_AT_location[DW_OP_regx 0x75]
$C$DW$1850	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("HWBP1")
	.dwattr $C$DW$1850, DW_AT_location[DW_OP_regx 0x76]
$C$DW$1851	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("HWBP2")
	.dwattr $C$DW$1851, DW_AT_location[DW_OP_regx 0x77]
$C$DW$1852	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("HWBP3")
	.dwattr $C$DW$1852, DW_AT_location[DW_OP_regx 0x78]
$C$DW$1853	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("OVERLAY")
	.dwattr $C$DW$1853, DW_AT_location[DW_OP_regx 0x79]
$C$DW$1854	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("PC_PROF")
	.dwattr $C$DW$1854, DW_AT_location[DW_OP_regx 0x7a]
$C$DW$1855	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ATSR")
	.dwattr $C$DW$1855, DW_AT_location[DW_OP_regx 0x7b]
$C$DW$1856	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("TRR")
	.dwattr $C$DW$1856, DW_AT_location[DW_OP_regx 0x7c]
$C$DW$1857	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("TCRR")
	.dwattr $C$DW$1857, DW_AT_location[DW_OP_regx 0x7d]
$C$DW$1858	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("DESR")
	.dwattr $C$DW$1858, DW_AT_location[DW_OP_regx 0x7e]
$C$DW$1859	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("DETR")
	.dwattr $C$DW$1859, DW_AT_location[DW_OP_regx 0x7f]
$C$DW$1860	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("CIE_RETA")
	.dwattr $C$DW$1860, DW_AT_location[DW_OP_regx 0xe4]
	.dwendtag $C$DW$CU

