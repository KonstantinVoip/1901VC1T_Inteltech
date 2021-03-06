;******************************************************************************
;* TMS320C6x C/C++ Codegen                                         PC v6.1.22 *
;* Date/Time created: Mon Feb 05 10:17:17 2018                                *
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
	.dwattr $C$DW$CU, DW_AT_name("os_start_tpo_main.cpp")
	.dwattr $C$DW$CU, DW_AT_producer("TMS320C6x C/C++ Codegen PC v6.1.22 Copyright (c) 1996-2012 Texas Instruments Incorporated")
	.dwattr $C$DW$CU, DW_AT_TI_version(0x01)
	.dwattr $C$DW$CU, DW_AT_comp_dir("C:\1901VC1T_Inteltech\3rdPartyLIB\dsp_core\C6000\tpo_amoeba\source")

$C$DW$1	.dwtag  DW_TAG_subprogram, DW_AT_name("tpo_comm")
	.dwattr $C$DW$1, DW_AT_TI_symbol_name("_tpo_comm__FPvPc")
	.dwattr $C$DW$1, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$1, DW_AT_declaration
	.dwattr $C$DW$1, DW_AT_external
$C$DW$2	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$2, DW_AT_type(*$C$DW$T$3)
$C$DW$3	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$3, DW_AT_type(*$C$DW$T$80)
	.dwendtag $C$DW$1

$C$DW$137	.dwtag  DW_TAG_variable, DW_AT_name("__syscall_tab")
	.dwattr $C$DW$137, DW_AT_TI_symbol_name("___syscall_tab")
	.dwattr $C$DW$137, DW_AT_type(*$C$DW$T$438)
	.dwattr $C$DW$137, DW_AT_declaration
	.dwattr $C$DW$137, DW_AT_external
	.sect	".const:_hash_bp"
	.clink
	.align	8
_hash_bp:
	.field  	-389869675,32			; _hash_bp[0] @ 0
	.field  	795174144,32			; _hash_bp[1] @ 32
	.field  	298864268,32			; _hash_bp[2] @ 64
	.field  	-1237125953,32			; _hash_bp[3] @ 96
	.field  	-2074461959,32			; _hash_bp[4] @ 128
	.field  	11526990,32			; _hash_bp[5] @ 160
	.field  	-90338278,32			; _hash_bp[6] @ 192
	.field  	-1561252904,32			; _hash_bp[7] @ 224
	.field  	-1636251795,32			; _hash_bp[8] @ 256
	.field  	-583621916,32			; _hash_bp[9] @ 288
	.field  	1009193075,32			; _hash_bp[10] @ 320
	.field  	1505538475,32			; _hash_bp[11] @ 352
	.field  	-946964025,32			; _hash_bp[12] @ 384
	.field  	1661228582,32			; _hash_bp[13] @ 416
	.field  	2065406513,32			; _hash_bp[14] @ 448
	.field  	1172954450,32			; _hash_bp[15] @ 480

$C$DW$138	.dwtag  DW_TAG_variable, DW_AT_name("hash_bp")
	.dwattr $C$DW$138, DW_AT_TI_symbol_name("_hash_bp")
	.dwattr $C$DW$138, DW_AT_type(*$C$DW$T$456)
	.dwattr $C$DW$138, DW_AT_location[DW_OP_addr _hash_bp]
;	C:\Program Files (x86)\Texas Instruments\C6000 Code Generation Tools 6.1.22\bin\acp6x.exe -@C:\Users\shiluaev\AppData\Local\Temp\0577212 
	.sect	".text"
	.clink
	.global	_os_main__FPv

$C$DW$139	.dwtag  DW_TAG_subprogram, DW_AT_name("os_main")
	.dwattr $C$DW$139, DW_AT_low_pc(_os_main__FPv)
	.dwattr $C$DW$139, DW_AT_high_pc(0x00)
	.dwattr $C$DW$139, DW_AT_TI_symbol_name("_os_main__FPv")
	.dwattr $C$DW$139, DW_AT_external
	.dwattr $C$DW$139, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$139, DW_AT_TI_begin_file("os_start_tpo_main.cpp")
	.dwattr $C$DW$139, DW_AT_TI_begin_line(0x37)
	.dwattr $C$DW$139, DW_AT_TI_begin_column(0x05)
	.dwpsn	file "os_start_tpo_main.cpp",line 56,column 1,is_stmt,address _os_main__FPv

	.dwfde $C$DW$CIE, _os_main__FPv
$C$DW$140	.dwtag  DW_TAG_formal_parameter, DW_AT_name("arg")
	.dwattr $C$DW$140, DW_AT_TI_symbol_name("_arg")
	.dwattr $C$DW$140, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$140, DW_AT_location[DW_OP_reg4]
;----------------------------------------------------------------------
;  55 | Return Value: ����� ���� ����� os_main ��� ��                          
;----------------------------------------------------------------------

;******************************************************************************
;* FUNCTION NAME: os_main(void *)                                             *
;*                                                                            *
;*   Regs Modified     : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP,A16,A17,A18,A19,A20,A21,A22,A23,A24, *
;*                           A25,A26,A27,A28,A29,A30,A31,B16,B17,B18,B19,B20, *
;*                           B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31      *
;*   Regs Used         : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP,A16,A17,A18,A19,A20,A21,A22,A23,A24, *
;*                           A25,A26,A27,A28,A29,A30,A31,B16,B17,B18,B19,B20, *
;*                           B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31      *
;*   Local Frame Size  : 0 Args + 8 Auto + 4 Save = 12 byte                   *
;******************************************************************************
_os_main__FPv:
;** --------------------------------------------------------------------------*
;----------------------------------------------------------------------
;  56 | [IFACE ,MAIN � COMM �����������]                                       
;----------------------------------------------------------------------
	.dwcfi	cfa_offset, 0
	.dwcfi	save_reg_to_reg, 228, 19
           STW     .D2T2   B3,*SP--(16)      ; |56| 
	.dwcfi	cfa_offset, 16
	.dwcfi	save_reg_to_mem, 19, 0
$C$DW$141	.dwtag  DW_TAG_variable, DW_AT_name("arg")
	.dwattr $C$DW$141, DW_AT_TI_symbol_name("_arg")
	.dwattr $C$DW$141, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$141, DW_AT_location[DW_OP_breg31 4]
$C$DW$142	.dwtag  DW_TAG_variable, DW_AT_name("error")
	.dwattr $C$DW$142, DW_AT_TI_symbol_name("_error")
	.dwattr $C$DW$142, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$142, DW_AT_location[DW_OP_breg31 8]
           STW     .D2T1   A4,*+SP(4)        ; |56| 
	.dwpsn	file "os_start_tpo_main.cpp",line 57,column 7,is_stmt
;----------------------------------------------------------------------
;  57 | ***********************************************************************
;     | ****************************/                                          
;  58 | int os_main(void* arg)                                                 
;  60 | int error = 0;                                                         
;  63 |  //�������� ��                                                         
;  64 | �������                                                                
;----------------------------------------------------------------------
           ZERO    .L2     B4                ; |57| 
           STW     .D2T2   B4,*+SP(8)        ; |57| 
	.dwpsn	file "os_start_tpo_main.cpp",line 71,column 6,is_stmt
;----------------------------------------------------------------------
;  74 | //core_common\h\os_syscall.h  #define SYSCALL_CRYPTO_GOST_HASH_INIT
;     |                134                                                     
;  75 | cry_hash_init(hash_bp);   //��                                         
;  76 | ���� ����� ����� ������� SYSCALL ��                                    
;  78 | //                                                                     
;  79 |    #ifdef IFACE //�����������                                          
;  80 | �����                                                                  
;  81 |      if( OSE_OK == sys_chkname("iface") )                              
;  82 |        error = tpo_iface(arg);                                         
;  83 |    #endif                                                              
;  84 | //                                                                     
;----------------------------------------------------------------------
           MVKL    .S2     ___syscall_tab+536,B4
           MVKH    .S2     ___syscall_tab+536,B4
           LDW     .D2T2   *B4,B4            ; |71| 
           MVKL    .S2     _hash_bp,B5
           MVKH    .S2     _hash_bp,B5
           NOP             2
$C$DW$143	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$143, DW_AT_low_pc(0x00)
	.dwattr $C$DW$143, DW_AT_TI_call
	.dwattr $C$DW$143, DW_AT_TI_indirect
           CALL    .S2     B4                ; |71| 
           ADDKPC  .S2     $C$RL0,B3,3       ; |71| 
           MV      .L1X    B5,A4             ; |71| 
$C$RL0:    ; CALL OCCURS {B4} {0}            ; |71| 
	.dwpsn	file "os_start_tpo_main.cpp",line 85,column 3,is_stmt
;----------------------------------------------------------------------
;  85 | #ifdef MAIN  //����������� ��������� � ��� ������ ��� ���������� ��    
;  86 | � ���                                                                  
;----------------------------------------------------------------------
	.dwpsn	file "os_start_tpo_main.cpp",line 87,column 5,is_stmt
;----------------------------------------------------------------------
;  87 | if( OSE_OK == sys_chkname("main") )                                    
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+8,A3
           MVKH    .S1     ___syscall_tab+8,A3
           LDW     .D1T1   *A3,A3            ; |87| 
           MVKL    .S1     $C$SL1+0,A4       ; |87| 
           MVKH    .S1     $C$SL1+0,A4       ; |87| 
           NOP             2
$C$DW$144	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$144, DW_AT_low_pc(0x00)
	.dwattr $C$DW$144, DW_AT_TI_call
	.dwattr $C$DW$144, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |87| 
           ADDKPC  .S2     $C$RL1,B3,4       ; |87| 
$C$RL1:    ; CALL OCCURS {A3} {0}            ; |87| 
           CMPEQ   .L1     0,A4,A0           ; |87| 
   [!A0]   BNOP    .S1     $C$L1,5           ; |87| 
           ; BRANCHCC OCCURS {$C$L1}         ; |87| 
;** --------------------------------------------------------------------------*
	.dwpsn	file "os_start_tpo_main.cpp",line 88,column 7,is_stmt
;----------------------------------------------------------------------
;  88 | error = tpo_main(arg);                                                 
;  89 | #endif                                                                 
;----------------------------------------------------------------------
$C$DW$145	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$145, DW_AT_low_pc(0x00)
	.dwattr $C$DW$145, DW_AT_name("_tpo_comm__FPvPc")
	.dwattr $C$DW$145, DW_AT_TI_call
           CALL    .S1     _tpo_comm__FPvPc  ; |88| 
           LDW     .D2T1   *+SP(4),A4        ; |88| 
           MVKL    .S2     $C$SL1+0,B4       ; |88| 
           MVKH    .S2     $C$SL1+0,B4       ; |88| 
           ADDKPC  .S2     $C$RL2,B3,1       ; |88| 
$C$RL2:    ; CALL OCCURS {_tpo_comm__FPvPc} {0}  ; |88| 
           STW     .D2T1   A4,*+SP(8)        ; |88| 
;** --------------------------------------------------------------------------*
$C$L1:    
	.dwpsn	file "os_start_tpo_main.cpp",line 90,column 3,is_stmt
;----------------------------------------------------------------------
;  90 | //                                                                     
;  91 |     #ifdef COMM  //���������������� ����������  ���������� ���������� �
;     |  tpo.h                                                                 
;----------------------------------------------------------------------
	.dwpsn	file "os_start_tpo_main.cpp",line 92,column 5,is_stmt
;----------------------------------------------------------------------
;  92 | if((MIN_NUMBER_COMM < 1)&(NUMBER_COMM_DSP > 0))                        
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+8,A3
           MVKH    .S1     ___syscall_tab+8,A3
           LDW     .D1T1   *A3,A3            ; |92| 
           MVKL    .S1     $C$SL2+0,A4       ; |92| 
           MVKH    .S1     $C$SL2+0,A4       ; |92| 
           NOP             2
$C$DW$146	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$146, DW_AT_low_pc(0x00)
	.dwattr $C$DW$146, DW_AT_TI_call
	.dwattr $C$DW$146, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |92| 
           ADDKPC  .S2     $C$RL3,B3,4       ; |92| 
$C$RL3:    ; CALL OCCURS {A3} {0}            ; |92| 
           CMPEQ   .L1     0,A4,A0           ; |92| 
   [!A0]   BNOP    .S1     $C$L2,5           ; |92| 
           ; BRANCHCC OCCURS {$C$L2}         ; |92| 
;** --------------------------------------------------------------------------*
	.dwpsn	file "os_start_tpo_main.cpp",line 93,column 7,is_stmt
;----------------------------------------------------------------------
;  94 | if( OSE_OK == sys_chkname("comm0") )                                   
;----------------------------------------------------------------------
$C$DW$147	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$147, DW_AT_low_pc(0x00)
	.dwattr $C$DW$147, DW_AT_name("_tpo_comm__FPvPc")
	.dwattr $C$DW$147, DW_AT_TI_call
           CALL    .S1     _tpo_comm__FPvPc  ; |93| 
           LDW     .D2T1   *+SP(4),A4        ; |93| 
           MVKL    .S2     $C$SL2+0,B4       ; |93| 
           MVKH    .S2     $C$SL2+0,B4       ; |93| 
           ADDKPC  .S2     $C$RL4,B3,1       ; |93| 
$C$RL4:    ; CALL OCCURS {_tpo_comm__FPvPc} {0}  ; |93| 
           STW     .D2T1   A4,*+SP(8)        ; |93| 
	.dwpsn	file "os_start_tpo_main.cpp",line 95,column 3,is_stmt
;----------------------------------------------------------------------
;  95 | error = tpo_comm(arg, "comm0");                                        
;  97 | if((MIN_NUMBER_COMM < 2)&(NUMBER_COMM_DSP > 1))                        
;  99 | if( OSE_OK == sys_chkname("comm1") )                                   
; 100 | error = tpo_comm(arg, "comm1");                                        
; 102 | if((MIN_NUMBER_COMM < 3)&(NUMBER_COMM_DSP > 2))                        
; 104 |       if( OSE_OK == sys_chkname("comm2") )                             
; 105 |     error = tpo_comm(arg, "comm2");                                    
;----------------------------------------------------------------------
           BNOP    .S1     $C$L2,5           ; |95| 
           ; BRANCH OCCURS {$C$L2}           ; |95| 
;** --------------------------------------------------------------------------*
;** --------------------------------------------------------------------------*
$C$L2:    
	.dwpsn	file "os_start_tpo_main.cpp",line 108,column 1,is_stmt
;----------------------------------------------------------------------
; 108 | if((MIN_NUMBER_COMM < 4)&(NUMBER_COMM_DSP > 3))                        
;----------------------------------------------------------------------
           LDW     .D2T1   *+SP(8),A4        ; |108| 
           NOP             4
	.dwpsn	file "os_start_tpo_main.cpp",line 109,column 1,is_stmt
           LDW     .D2T2   *++SP(16),B3      ; |109| 
           NOP             4
	.dwcfi	cfa_offset, 0
	.dwcfi	restore_reg, 19
	.dwcfi	cfa_offset, 0
$C$DW$148	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$148, DW_AT_low_pc(0x00)
	.dwattr $C$DW$148, DW_AT_TI_return
           RETNOP  .S2     B3,5              ; |109| 
           ; BRANCH OCCURS {B3}              ; |109| 
	.dwattr $C$DW$139, DW_AT_TI_end_file("os_start_tpo_main.cpp")
	.dwattr $C$DW$139, DW_AT_TI_end_line(0x6d)
	.dwattr $C$DW$139, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$139

;******************************************************************************
;* STRINGS                                                                    *
;******************************************************************************
	.sect	".const:.string"
$C$SL1:	.string	"comm0",0
$C$SL2:	.string	"comm1",0
;*****************************************************************************
;* UNDEFINED EXTERNAL REFERENCES                                             *
;*****************************************************************************
	.global	_tpo_comm__FPvPc
	.global	___syscall_tab

;******************************************************************************
;* TYPE INFORMATION                                                           *
;******************************************************************************
$C$DW$T$3	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$3, DW_AT_address_class(0x20)

$C$DW$T$438	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$438, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$T$438, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$438, DW_AT_byte_size(0x2d0)
$C$DW$149	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$149, DW_AT_upper_bound(0xb3)
	.dwendtag $C$DW$T$438


$C$DW$T$21	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$21, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$T$211	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$211, DW_AT_type(*$C$DW$T$21)
	.dwattr $C$DW$T$211, DW_AT_address_class(0x20)

$C$DW$T$23	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$23, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$150	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$150, DW_AT_type(*$C$DW$T$22)
	.dwendtag $C$DW$T$23


$C$DW$T$25	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$25, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$151	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$151, DW_AT_type(*$C$DW$T$24)
	.dwendtag $C$DW$T$25


$C$DW$T$29	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$29, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$152	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$152, DW_AT_type(*$C$DW$T$28)
	.dwendtag $C$DW$T$29


$C$DW$T$31	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$31, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$153	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$153, DW_AT_type(*$C$DW$T$30)
	.dwendtag $C$DW$T$31


$C$DW$T$35	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$35, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$154	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$154, DW_AT_type(*$C$DW$T$34)
	.dwendtag $C$DW$T$35


$C$DW$T$38	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$38, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$155	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$155, DW_AT_type(*$C$DW$T$37)
	.dwendtag $C$DW$T$38


$C$DW$T$42	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$42, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$156	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$156, DW_AT_type(*$C$DW$T$41)
	.dwendtag $C$DW$T$42


$C$DW$T$44	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$44, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$157	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$157, DW_AT_type(*$C$DW$T$43)
	.dwendtag $C$DW$T$44


$C$DW$T$48	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$48, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$158	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$158, DW_AT_type(*$C$DW$T$47)
	.dwendtag $C$DW$T$48


$C$DW$T$50	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$50, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$159	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$159, DW_AT_type(*$C$DW$T$49)
	.dwendtag $C$DW$T$50


$C$DW$T$54	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$54, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$160	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$160, DW_AT_type(*$C$DW$T$53)
	.dwendtag $C$DW$T$54


$C$DW$T$57	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$57, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$161	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$161, DW_AT_type(*$C$DW$T$56)
	.dwendtag $C$DW$T$57


$C$DW$T$61	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$61, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$162	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$162, DW_AT_type(*$C$DW$T$60)
	.dwendtag $C$DW$T$61


$C$DW$T$63	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$63, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$163	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$163, DW_AT_type(*$C$DW$T$62)
	.dwendtag $C$DW$T$63


$C$DW$T$67	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$67, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$164	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$164, DW_AT_type(*$C$DW$T$66)
	.dwendtag $C$DW$T$67


$C$DW$T$69	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$69, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$165	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$165, DW_AT_type(*$C$DW$T$68)
	.dwendtag $C$DW$T$69


$C$DW$T$73	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$73, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$166	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$166, DW_AT_type(*$C$DW$T$72)
	.dwendtag $C$DW$T$73


$C$DW$T$76	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$76, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$167	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$167, DW_AT_type(*$C$DW$T$75)
	.dwendtag $C$DW$T$76

$C$DW$T$93	.dwtag  DW_TAG_const_type
$C$DW$T$94	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$94, DW_AT_type(*$C$DW$T$93)
	.dwattr $C$DW$T$94, DW_AT_address_class(0x20)

$C$DW$T$334	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$334, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$168	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$168, DW_AT_type(*$C$DW$T$3)
$C$DW$169	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$169, DW_AT_type(*$C$DW$T$10)
	.dwendtag $C$DW$T$334

$C$DW$T$335	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$335, DW_AT_type(*$C$DW$T$334)
	.dwattr $C$DW$T$335, DW_AT_address_class(0x20)

$C$DW$T$440	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$440, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$170	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$170, DW_AT_type(*$C$DW$T$10)
	.dwendtag $C$DW$T$440

$C$DW$T$441	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$441, DW_AT_type(*$C$DW$T$440)
	.dwattr $C$DW$T$441, DW_AT_address_class(0x20)
$C$DW$T$442	.dwtag  DW_TAG_typedef, DW_AT_name("EDMA_IntHandler")
	.dwattr $C$DW$T$442, DW_AT_type(*$C$DW$T$441)
	.dwattr $C$DW$T$442, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$T$4	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$4, DW_AT_encoding(DW_ATE_boolean)
	.dwattr $C$DW$T$4, DW_AT_name("bool")
	.dwattr $C$DW$T$4, DW_AT_byte_size(0x01)
$C$DW$T$5	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$5, DW_AT_encoding(DW_ATE_signed_char)
	.dwattr $C$DW$T$5, DW_AT_name("signed char")
	.dwattr $C$DW$T$5, DW_AT_byte_size(0x01)
$C$DW$T$445	.dwtag  DW_TAG_typedef, DW_AT_name("int8")
	.dwattr $C$DW$T$445, DW_AT_type(*$C$DW$T$5)
	.dwattr $C$DW$T$445, DW_AT_language(DW_LANG_C_plus_plus)
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
$C$DW$171	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$171, DW_AT_upper_bound(0x01)
	.dwendtag $C$DW$T$20


$C$DW$T$40	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$40, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$T$40, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$40, DW_AT_byte_size(0x04)
$C$DW$172	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$172, DW_AT_upper_bound(0x03)
	.dwendtag $C$DW$T$40


$C$DW$T$59	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$59, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$T$59, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$59, DW_AT_byte_size(0x08)
$C$DW$173	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$173, DW_AT_upper_bound(0x07)
	.dwendtag $C$DW$T$59


$C$DW$T$288	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$288, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$T$288, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$288, DW_AT_byte_size(0x10)
$C$DW$174	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$174, DW_AT_upper_bound(0x0f)
	.dwendtag $C$DW$T$288


$C$DW$T$301	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$301, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$T$301, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$301, DW_AT_byte_size(0x400)
$C$DW$175	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$175, DW_AT_upper_bound(0x3ff)
	.dwendtag $C$DW$T$301


$C$DW$T$302	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$302, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$T$302, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$302, DW_AT_byte_size(0x20)
$C$DW$176	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$176, DW_AT_upper_bound(0x1f)
	.dwendtag $C$DW$T$302

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
$C$DW$177	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$177, DW_AT_type(*$C$DW$T$86)
$C$DW$178	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$178, DW_AT_type(*$C$DW$T$28)
	.dwendtag $C$DW$T$87

$C$DW$T$88	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$88, DW_AT_type(*$C$DW$T$87)
	.dwattr $C$DW$T$88, DW_AT_address_class(0x20)

$C$DW$T$89	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$89, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$T$89, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$179	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$179, DW_AT_type(*$C$DW$T$86)
	.dwendtag $C$DW$T$89

$C$DW$T$90	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$90, DW_AT_type(*$C$DW$T$89)
	.dwattr $C$DW$T$90, DW_AT_address_class(0x20)

$C$DW$T$91	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$91, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$T$91, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$180	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$180, DW_AT_type(*$C$DW$T$86)
$C$DW$181	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$181, DW_AT_type(*$C$DW$T$3)
$C$DW$182	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$182, DW_AT_type(*$C$DW$T$41)
	.dwendtag $C$DW$T$91

$C$DW$T$92	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$92, DW_AT_type(*$C$DW$T$91)
	.dwattr $C$DW$T$92, DW_AT_address_class(0x20)

$C$DW$T$95	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$95, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$T$95, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$183	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$183, DW_AT_type(*$C$DW$T$86)
$C$DW$184	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$184, DW_AT_type(*$C$DW$T$94)
$C$DW$185	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$185, DW_AT_type(*$C$DW$T$41)
	.dwendtag $C$DW$T$95

$C$DW$T$96	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$96, DW_AT_type(*$C$DW$T$95)
	.dwattr $C$DW$T$96, DW_AT_address_class(0x20)

$C$DW$T$97	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$97, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$T$97, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$186	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$186, DW_AT_type(*$C$DW$T$86)
$C$DW$187	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$187, DW_AT_type(*$C$DW$T$41)
$C$DW$188	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$188, DW_AT_type(*$C$DW$T$94)
	.dwendtag $C$DW$T$97

$C$DW$T$98	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$98, DW_AT_type(*$C$DW$T$97)
	.dwattr $C$DW$T$98, DW_AT_address_class(0x20)
$C$DW$T$446	.dwtag  DW_TAG_typedef, DW_AT_name("ptrdiff_t")
	.dwattr $C$DW$T$446, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$T$446, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$T$449	.dwtag  DW_TAG_typedef, DW_AT_name("nothrow_t")
	.dwattr $C$DW$T$449, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$T$449, DW_AT_language(DW_LANG_C_plus_plus)
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
$C$DW$189	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$189, DW_AT_upper_bound(0x02)
	.dwendtag $C$DW$T$232


$C$DW$T$233	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$233, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$T$233, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$233, DW_AT_byte_size(0x40)
$C$DW$190	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$190, DW_AT_upper_bound(0x0f)
	.dwendtag $C$DW$T$233

$C$DW$T$454	.dwtag  DW_TAG_typedef, DW_AT_name("EDMA_Handle")
	.dwattr $C$DW$T$454, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$T$454, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$T$455	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$455, DW_AT_type(*$C$DW$T$47)

$C$DW$T$456	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$456, DW_AT_type(*$C$DW$T$455)
	.dwattr $C$DW$T$456, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$456, DW_AT_byte_size(0x40)
$C$DW$191	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$191, DW_AT_upper_bound(0x0f)
	.dwendtag $C$DW$T$456

$C$DW$T$453	.dwtag  DW_TAG_typedef, DW_AT_name("size_t")
	.dwattr $C$DW$T$453, DW_AT_type(*$C$DW$T$11)
	.dwattr $C$DW$T$453, DW_AT_language(DW_LANG_C_plus_plus)
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
$C$DW$T$458	.dwtag  DW_TAG_typedef, DW_AT_name("float32")
	.dwattr $C$DW$T$458, DW_AT_type(*$C$DW$T$16)
	.dwattr $C$DW$T$458, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$T$17	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$17, DW_AT_encoding(DW_ATE_float)
	.dwattr $C$DW$T$17, DW_AT_name("double")
	.dwattr $C$DW$T$17, DW_AT_byte_size(0x08)
$C$DW$T$18	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$18, DW_AT_encoding(DW_ATE_float)
	.dwattr $C$DW$T$18, DW_AT_name("long double")
	.dwattr $C$DW$T$18, DW_AT_byte_size(0x08)
$C$DW$T$459	.dwtag  DW_TAG_typedef, DW_AT_name("float64")
	.dwattr $C$DW$T$459, DW_AT_type(*$C$DW$T$18)
	.dwattr $C$DW$T$459, DW_AT_language(DW_LANG_C_plus_plus)

$C$DW$T$27	.dwtag  DW_TAG_class_type
	.dwattr $C$DW$T$27, DW_AT_name("int16le")
	.dwattr $C$DW$T$27, DW_AT_byte_size(0x02)
$C$DW$192	.dwtag  DW_TAG_member
	.dwattr $C$DW$192, DW_AT_type(*$C$DW$T$20)
	.dwattr $C$DW$192, DW_AT_name("a")
	.dwattr $C$DW$192, DW_AT_TI_symbol_name("_a")
	.dwattr $C$DW$192, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$192, DW_AT_accessibility(DW_ACCESS_private)

$C$DW$4	.dwtag  DW_TAG_subprogram, DW_AT_name("int16le")
	.dwattr $C$DW$4, DW_AT_declaration
	.dwattr $C$DW$4, DW_AT_TI_symbol_name("___ct__7int16leFv")
	.dwattr $C$DW$4, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$5	.dwtag  DW_TAG_subprogram, DW_AT_name("int16le")
	.dwattr $C$DW$5, DW_AT_declaration
	.dwattr $C$DW$5, DW_AT_TI_symbol_name("___ct__7int16leFs")
	.dwattr $C$DW$5, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$193	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$193, DW_AT_type(*$C$DW$T$22)
	.dwendtag $C$DW$5


$C$DW$6	.dwtag  DW_TAG_subprogram, DW_AT_name("int16le")
	.dwattr $C$DW$6, DW_AT_declaration
	.dwattr $C$DW$6, DW_AT_TI_symbol_name("___ct__7int16leFR7int16le")
	.dwattr $C$DW$6, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$194	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$194, DW_AT_type(*$C$DW$T$24)
	.dwendtag $C$DW$6


$C$DW$7	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$7, DW_AT_declaration
	.dwattr $C$DW$7, DW_AT_TI_symbol_name("___as__7int16leFs")
	.dwattr $C$DW$7, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$195	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$195, DW_AT_type(*$C$DW$T$22)
	.dwendtag $C$DW$7


$C$DW$8	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$8, DW_AT_declaration
	.dwattr $C$DW$8, DW_AT_TI_symbol_name("___as__7int16leFR7int16le")
	.dwattr $C$DW$8, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$196	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$196, DW_AT_type(*$C$DW$T$24)
	.dwendtag $C$DW$8


$C$DW$9	.dwtag  DW_TAG_subprogram, DW_AT_name("operator short")
	.dwattr $C$DW$9, DW_AT_declaration
	.dwattr $C$DW$9, DW_AT_TI_symbol_name("___ops__7int16leFv")
	.dwattr $C$DW$9, DW_AT_type(*$C$DW$T$22)
	.dwattr $C$DW$9, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag $C$DW$T$27

$C$DW$T$24	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$24, DW_AT_type(*$C$DW$T$27)
	.dwattr $C$DW$T$24, DW_AT_address_class(0x20)

$C$DW$T$33	.dwtag  DW_TAG_class_type
	.dwattr $C$DW$T$33, DW_AT_name("uint16le")
	.dwattr $C$DW$T$33, DW_AT_byte_size(0x02)
$C$DW$197	.dwtag  DW_TAG_member
	.dwattr $C$DW$197, DW_AT_type(*$C$DW$T$20)
	.dwattr $C$DW$197, DW_AT_name("a")
	.dwattr $C$DW$197, DW_AT_TI_symbol_name("_a")
	.dwattr $C$DW$197, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$197, DW_AT_accessibility(DW_ACCESS_private)

$C$DW$10	.dwtag  DW_TAG_subprogram, DW_AT_name("uint16le")
	.dwattr $C$DW$10, DW_AT_declaration
	.dwattr $C$DW$10, DW_AT_TI_symbol_name("___ct__8uint16leFv")
	.dwattr $C$DW$10, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$11	.dwtag  DW_TAG_subprogram, DW_AT_name("uint16le")
	.dwattr $C$DW$11, DW_AT_declaration
	.dwattr $C$DW$11, DW_AT_TI_symbol_name("___ct__8uint16leFUs")
	.dwattr $C$DW$11, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$198	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$198, DW_AT_type(*$C$DW$T$28)
	.dwendtag $C$DW$11


$C$DW$12	.dwtag  DW_TAG_subprogram, DW_AT_name("uint16le")
	.dwattr $C$DW$12, DW_AT_declaration
	.dwattr $C$DW$12, DW_AT_TI_symbol_name("___ct__8uint16leFR8uint16le")
	.dwattr $C$DW$12, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$199	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$199, DW_AT_type(*$C$DW$T$30)
	.dwendtag $C$DW$12


$C$DW$13	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$13, DW_AT_declaration
	.dwattr $C$DW$13, DW_AT_TI_symbol_name("___as__8uint16leFUs")
	.dwattr $C$DW$13, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$200	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$200, DW_AT_type(*$C$DW$T$28)
	.dwendtag $C$DW$13


$C$DW$14	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$14, DW_AT_declaration
	.dwattr $C$DW$14, DW_AT_TI_symbol_name("___as__8uint16leFR8uint16le")
	.dwattr $C$DW$14, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$201	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$201, DW_AT_type(*$C$DW$T$30)
	.dwendtag $C$DW$14


$C$DW$15	.dwtag  DW_TAG_subprogram, DW_AT_name("operator unsigned short")
	.dwattr $C$DW$15, DW_AT_declaration
	.dwattr $C$DW$15, DW_AT_TI_symbol_name("___opUs__8uint16leFv")
	.dwattr $C$DW$15, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$15, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag $C$DW$T$33

$C$DW$T$30	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$30, DW_AT_type(*$C$DW$T$33)
	.dwattr $C$DW$T$30, DW_AT_address_class(0x20)

$C$DW$T$36	.dwtag  DW_TAG_class_type
	.dwattr $C$DW$T$36, DW_AT_name("int16be")
	.dwattr $C$DW$T$36, DW_AT_byte_size(0x02)
$C$DW$202	.dwtag  DW_TAG_member
	.dwattr $C$DW$202, DW_AT_type(*$C$DW$T$20)
	.dwattr $C$DW$202, DW_AT_name("a")
	.dwattr $C$DW$202, DW_AT_TI_symbol_name("_a")
	.dwattr $C$DW$202, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$202, DW_AT_accessibility(DW_ACCESS_private)

$C$DW$16	.dwtag  DW_TAG_subprogram, DW_AT_name("int16be")
	.dwattr $C$DW$16, DW_AT_declaration
	.dwattr $C$DW$16, DW_AT_TI_symbol_name("___ct__7int16beFv")
	.dwattr $C$DW$16, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$17	.dwtag  DW_TAG_subprogram, DW_AT_name("int16be")
	.dwattr $C$DW$17, DW_AT_declaration
	.dwattr $C$DW$17, DW_AT_TI_symbol_name("___ct__7int16beFs")
	.dwattr $C$DW$17, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$203	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$203, DW_AT_type(*$C$DW$T$22)
	.dwendtag $C$DW$17


$C$DW$18	.dwtag  DW_TAG_subprogram, DW_AT_name("int16be")
	.dwattr $C$DW$18, DW_AT_declaration
	.dwattr $C$DW$18, DW_AT_TI_symbol_name("___ct__7int16beFR7int16be")
	.dwattr $C$DW$18, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$204	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$204, DW_AT_type(*$C$DW$T$34)
	.dwendtag $C$DW$18


$C$DW$19	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$19, DW_AT_declaration
	.dwattr $C$DW$19, DW_AT_TI_symbol_name("___as__7int16beFs")
	.dwattr $C$DW$19, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$205	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$205, DW_AT_type(*$C$DW$T$22)
	.dwendtag $C$DW$19


$C$DW$20	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$20, DW_AT_declaration
	.dwattr $C$DW$20, DW_AT_TI_symbol_name("___as__7int16beFR7int16be")
	.dwattr $C$DW$20, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$206	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$206, DW_AT_type(*$C$DW$T$34)
	.dwendtag $C$DW$20


$C$DW$21	.dwtag  DW_TAG_subprogram, DW_AT_name("operator short")
	.dwattr $C$DW$21, DW_AT_declaration
	.dwattr $C$DW$21, DW_AT_TI_symbol_name("___ops__7int16beFv")
	.dwattr $C$DW$21, DW_AT_type(*$C$DW$T$22)
	.dwattr $C$DW$21, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag $C$DW$T$36

$C$DW$T$34	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$34, DW_AT_type(*$C$DW$T$36)
	.dwattr $C$DW$T$34, DW_AT_address_class(0x20)

$C$DW$T$39	.dwtag  DW_TAG_class_type
	.dwattr $C$DW$T$39, DW_AT_name("uint16be")
	.dwattr $C$DW$T$39, DW_AT_byte_size(0x02)
$C$DW$207	.dwtag  DW_TAG_member
	.dwattr $C$DW$207, DW_AT_type(*$C$DW$T$20)
	.dwattr $C$DW$207, DW_AT_name("a")
	.dwattr $C$DW$207, DW_AT_TI_symbol_name("_a")
	.dwattr $C$DW$207, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$207, DW_AT_accessibility(DW_ACCESS_private)

$C$DW$22	.dwtag  DW_TAG_subprogram, DW_AT_name("uint16be")
	.dwattr $C$DW$22, DW_AT_declaration
	.dwattr $C$DW$22, DW_AT_TI_symbol_name("___ct__8uint16beFv")
	.dwattr $C$DW$22, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$23	.dwtag  DW_TAG_subprogram, DW_AT_name("uint16be")
	.dwattr $C$DW$23, DW_AT_declaration
	.dwattr $C$DW$23, DW_AT_TI_symbol_name("___ct__8uint16beFUs")
	.dwattr $C$DW$23, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$208	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$208, DW_AT_type(*$C$DW$T$28)
	.dwendtag $C$DW$23


$C$DW$24	.dwtag  DW_TAG_subprogram, DW_AT_name("uint16be")
	.dwattr $C$DW$24, DW_AT_declaration
	.dwattr $C$DW$24, DW_AT_TI_symbol_name("___ct__8uint16beFR8uint16be")
	.dwattr $C$DW$24, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$209	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$209, DW_AT_type(*$C$DW$T$37)
	.dwendtag $C$DW$24


$C$DW$25	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$25, DW_AT_declaration
	.dwattr $C$DW$25, DW_AT_TI_symbol_name("___as__8uint16beFUs")
	.dwattr $C$DW$25, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$210	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$210, DW_AT_type(*$C$DW$T$28)
	.dwendtag $C$DW$25


$C$DW$26	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$26, DW_AT_declaration
	.dwattr $C$DW$26, DW_AT_TI_symbol_name("___as__8uint16beFR8uint16be")
	.dwattr $C$DW$26, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$211	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$211, DW_AT_type(*$C$DW$T$37)
	.dwendtag $C$DW$26


$C$DW$27	.dwtag  DW_TAG_subprogram, DW_AT_name("operator unsigned short")
	.dwattr $C$DW$27, DW_AT_declaration
	.dwattr $C$DW$27, DW_AT_TI_symbol_name("___opUs__8uint16beFv")
	.dwattr $C$DW$27, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$27, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag $C$DW$T$39

$C$DW$T$37	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$37, DW_AT_type(*$C$DW$T$39)
	.dwattr $C$DW$T$37, DW_AT_address_class(0x20)

$C$DW$T$46	.dwtag  DW_TAG_class_type
	.dwattr $C$DW$T$46, DW_AT_name("int32le")
	.dwattr $C$DW$T$46, DW_AT_byte_size(0x04)
$C$DW$212	.dwtag  DW_TAG_member
	.dwattr $C$DW$212, DW_AT_type(*$C$DW$T$40)
	.dwattr $C$DW$212, DW_AT_name("a")
	.dwattr $C$DW$212, DW_AT_TI_symbol_name("_a")
	.dwattr $C$DW$212, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$212, DW_AT_accessibility(DW_ACCESS_private)

$C$DW$28	.dwtag  DW_TAG_subprogram, DW_AT_name("int32le")
	.dwattr $C$DW$28, DW_AT_declaration
	.dwattr $C$DW$28, DW_AT_TI_symbol_name("___ct__7int32leFv")
	.dwattr $C$DW$28, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$29	.dwtag  DW_TAG_subprogram, DW_AT_name("int32le")
	.dwattr $C$DW$29, DW_AT_declaration
	.dwattr $C$DW$29, DW_AT_TI_symbol_name("___ct__7int32leFi")
	.dwattr $C$DW$29, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$213	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$213, DW_AT_type(*$C$DW$T$41)
	.dwendtag $C$DW$29


$C$DW$30	.dwtag  DW_TAG_subprogram, DW_AT_name("int32le")
	.dwattr $C$DW$30, DW_AT_declaration
	.dwattr $C$DW$30, DW_AT_TI_symbol_name("___ct__7int32leFR7int32le")
	.dwattr $C$DW$30, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$214	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$214, DW_AT_type(*$C$DW$T$43)
	.dwendtag $C$DW$30


$C$DW$31	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$31, DW_AT_declaration
	.dwattr $C$DW$31, DW_AT_TI_symbol_name("___as__7int32leFi")
	.dwattr $C$DW$31, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$215	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$215, DW_AT_type(*$C$DW$T$41)
	.dwendtag $C$DW$31


$C$DW$32	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$32, DW_AT_declaration
	.dwattr $C$DW$32, DW_AT_TI_symbol_name("___as__7int32leFR7int32le")
	.dwattr $C$DW$32, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$216	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$216, DW_AT_type(*$C$DW$T$43)
	.dwendtag $C$DW$32


$C$DW$33	.dwtag  DW_TAG_subprogram, DW_AT_name("operator int")
	.dwattr $C$DW$33, DW_AT_declaration
	.dwattr $C$DW$33, DW_AT_TI_symbol_name("___opi__7int32leFv")
	.dwattr $C$DW$33, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$33, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag $C$DW$T$46

$C$DW$T$43	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$43, DW_AT_type(*$C$DW$T$46)
	.dwattr $C$DW$T$43, DW_AT_address_class(0x20)

$C$DW$T$52	.dwtag  DW_TAG_class_type
	.dwattr $C$DW$T$52, DW_AT_name("uint32le")
	.dwattr $C$DW$T$52, DW_AT_byte_size(0x04)
$C$DW$217	.dwtag  DW_TAG_member
	.dwattr $C$DW$217, DW_AT_type(*$C$DW$T$40)
	.dwattr $C$DW$217, DW_AT_name("a")
	.dwattr $C$DW$217, DW_AT_TI_symbol_name("_a")
	.dwattr $C$DW$217, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$217, DW_AT_accessibility(DW_ACCESS_private)

$C$DW$34	.dwtag  DW_TAG_subprogram, DW_AT_name("uint32le")
	.dwattr $C$DW$34, DW_AT_declaration
	.dwattr $C$DW$34, DW_AT_TI_symbol_name("___ct__8uint32leFv")
	.dwattr $C$DW$34, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$35	.dwtag  DW_TAG_subprogram, DW_AT_name("uint32le")
	.dwattr $C$DW$35, DW_AT_declaration
	.dwattr $C$DW$35, DW_AT_TI_symbol_name("___ct__8uint32leFUi")
	.dwattr $C$DW$35, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$218	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$218, DW_AT_type(*$C$DW$T$47)
	.dwendtag $C$DW$35


$C$DW$36	.dwtag  DW_TAG_subprogram, DW_AT_name("uint32le")
	.dwattr $C$DW$36, DW_AT_declaration
	.dwattr $C$DW$36, DW_AT_TI_symbol_name("___ct__8uint32leFR8uint32le")
	.dwattr $C$DW$36, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$219	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$219, DW_AT_type(*$C$DW$T$49)
	.dwendtag $C$DW$36


$C$DW$37	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$37, DW_AT_declaration
	.dwattr $C$DW$37, DW_AT_TI_symbol_name("___as__8uint32leFUi")
	.dwattr $C$DW$37, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$220	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$220, DW_AT_type(*$C$DW$T$47)
	.dwendtag $C$DW$37


$C$DW$38	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$38, DW_AT_declaration
	.dwattr $C$DW$38, DW_AT_TI_symbol_name("___as__8uint32leFR8uint32le")
	.dwattr $C$DW$38, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$221	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$221, DW_AT_type(*$C$DW$T$49)
	.dwendtag $C$DW$38


$C$DW$39	.dwtag  DW_TAG_subprogram, DW_AT_name("operator unsigned int")
	.dwattr $C$DW$39, DW_AT_declaration
	.dwattr $C$DW$39, DW_AT_TI_symbol_name("___opUi__8uint32leFv")
	.dwattr $C$DW$39, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$39, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag $C$DW$T$52

$C$DW$T$49	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$49, DW_AT_type(*$C$DW$T$52)
	.dwattr $C$DW$T$49, DW_AT_address_class(0x20)

$C$DW$T$55	.dwtag  DW_TAG_class_type
	.dwattr $C$DW$T$55, DW_AT_name("int32be")
	.dwattr $C$DW$T$55, DW_AT_byte_size(0x04)
$C$DW$222	.dwtag  DW_TAG_member
	.dwattr $C$DW$222, DW_AT_type(*$C$DW$T$40)
	.dwattr $C$DW$222, DW_AT_name("a")
	.dwattr $C$DW$222, DW_AT_TI_symbol_name("_a")
	.dwattr $C$DW$222, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$222, DW_AT_accessibility(DW_ACCESS_private)

$C$DW$40	.dwtag  DW_TAG_subprogram, DW_AT_name("int32be")
	.dwattr $C$DW$40, DW_AT_declaration
	.dwattr $C$DW$40, DW_AT_TI_symbol_name("___ct__7int32beFv")
	.dwattr $C$DW$40, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$41	.dwtag  DW_TAG_subprogram, DW_AT_name("int32be")
	.dwattr $C$DW$41, DW_AT_declaration
	.dwattr $C$DW$41, DW_AT_TI_symbol_name("___ct__7int32beFi")
	.dwattr $C$DW$41, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$223	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$223, DW_AT_type(*$C$DW$T$41)
	.dwendtag $C$DW$41


$C$DW$42	.dwtag  DW_TAG_subprogram, DW_AT_name("int32be")
	.dwattr $C$DW$42, DW_AT_declaration
	.dwattr $C$DW$42, DW_AT_TI_symbol_name("___ct__7int32beFR7int32be")
	.dwattr $C$DW$42, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$224	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$224, DW_AT_type(*$C$DW$T$53)
	.dwendtag $C$DW$42


$C$DW$43	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$43, DW_AT_declaration
	.dwattr $C$DW$43, DW_AT_TI_symbol_name("___as__7int32beFi")
	.dwattr $C$DW$43, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$225	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$225, DW_AT_type(*$C$DW$T$41)
	.dwendtag $C$DW$43


$C$DW$44	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$44, DW_AT_declaration
	.dwattr $C$DW$44, DW_AT_TI_symbol_name("___as__7int32beFR7int32be")
	.dwattr $C$DW$44, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$226	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$226, DW_AT_type(*$C$DW$T$53)
	.dwendtag $C$DW$44


$C$DW$45	.dwtag  DW_TAG_subprogram, DW_AT_name("operator int")
	.dwattr $C$DW$45, DW_AT_declaration
	.dwattr $C$DW$45, DW_AT_TI_symbol_name("___opi__7int32beFv")
	.dwattr $C$DW$45, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$45, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag $C$DW$T$55

$C$DW$T$53	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$53, DW_AT_type(*$C$DW$T$55)
	.dwattr $C$DW$T$53, DW_AT_address_class(0x20)

$C$DW$T$58	.dwtag  DW_TAG_class_type
	.dwattr $C$DW$T$58, DW_AT_name("uint32be")
	.dwattr $C$DW$T$58, DW_AT_byte_size(0x04)
$C$DW$227	.dwtag  DW_TAG_member
	.dwattr $C$DW$227, DW_AT_type(*$C$DW$T$40)
	.dwattr $C$DW$227, DW_AT_name("a")
	.dwattr $C$DW$227, DW_AT_TI_symbol_name("_a")
	.dwattr $C$DW$227, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$227, DW_AT_accessibility(DW_ACCESS_private)

$C$DW$46	.dwtag  DW_TAG_subprogram, DW_AT_name("uint32be")
	.dwattr $C$DW$46, DW_AT_declaration
	.dwattr $C$DW$46, DW_AT_TI_symbol_name("___ct__8uint32beFv")
	.dwattr $C$DW$46, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$47	.dwtag  DW_TAG_subprogram, DW_AT_name("uint32be")
	.dwattr $C$DW$47, DW_AT_declaration
	.dwattr $C$DW$47, DW_AT_TI_symbol_name("___ct__8uint32beFUi")
	.dwattr $C$DW$47, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$228	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$228, DW_AT_type(*$C$DW$T$47)
	.dwendtag $C$DW$47


$C$DW$48	.dwtag  DW_TAG_subprogram, DW_AT_name("uint32be")
	.dwattr $C$DW$48, DW_AT_declaration
	.dwattr $C$DW$48, DW_AT_TI_symbol_name("___ct__8uint32beFR8uint32be")
	.dwattr $C$DW$48, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$229	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$229, DW_AT_type(*$C$DW$T$56)
	.dwendtag $C$DW$48


$C$DW$49	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$49, DW_AT_declaration
	.dwattr $C$DW$49, DW_AT_TI_symbol_name("___as__8uint32beFUi")
	.dwattr $C$DW$49, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$230	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$230, DW_AT_type(*$C$DW$T$47)
	.dwendtag $C$DW$49


$C$DW$50	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$50, DW_AT_declaration
	.dwattr $C$DW$50, DW_AT_TI_symbol_name("___as__8uint32beFR8uint32be")
	.dwattr $C$DW$50, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$231	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$231, DW_AT_type(*$C$DW$T$56)
	.dwendtag $C$DW$50


$C$DW$51	.dwtag  DW_TAG_subprogram, DW_AT_name("operator unsigned int")
	.dwattr $C$DW$51, DW_AT_declaration
	.dwattr $C$DW$51, DW_AT_TI_symbol_name("___opUi__8uint32beFv")
	.dwattr $C$DW$51, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$51, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag $C$DW$T$58

$C$DW$T$56	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$56, DW_AT_type(*$C$DW$T$58)
	.dwattr $C$DW$T$56, DW_AT_address_class(0x20)

$C$DW$T$65	.dwtag  DW_TAG_class_type
	.dwattr $C$DW$T$65, DW_AT_name("int64le")
	.dwattr $C$DW$T$65, DW_AT_byte_size(0x08)
$C$DW$232	.dwtag  DW_TAG_member
	.dwattr $C$DW$232, DW_AT_type(*$C$DW$T$59)
	.dwattr $C$DW$232, DW_AT_name("a")
	.dwattr $C$DW$232, DW_AT_TI_symbol_name("_a")
	.dwattr $C$DW$232, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$232, DW_AT_accessibility(DW_ACCESS_private)

$C$DW$52	.dwtag  DW_TAG_subprogram, DW_AT_name("int64le")
	.dwattr $C$DW$52, DW_AT_declaration
	.dwattr $C$DW$52, DW_AT_TI_symbol_name("___ct__7int64leFv")
	.dwattr $C$DW$52, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$53	.dwtag  DW_TAG_subprogram, DW_AT_name("int64le")
	.dwattr $C$DW$53, DW_AT_declaration
	.dwattr $C$DW$53, DW_AT_TI_symbol_name("___ct__7int64leFL")
	.dwattr $C$DW$53, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$233	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$233, DW_AT_type(*$C$DW$T$60)
	.dwendtag $C$DW$53


$C$DW$54	.dwtag  DW_TAG_subprogram, DW_AT_name("int64le")
	.dwattr $C$DW$54, DW_AT_declaration
	.dwattr $C$DW$54, DW_AT_TI_symbol_name("___ct__7int64leFR7int64le")
	.dwattr $C$DW$54, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$234	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$234, DW_AT_type(*$C$DW$T$62)
	.dwendtag $C$DW$54


$C$DW$55	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$55, DW_AT_declaration
	.dwattr $C$DW$55, DW_AT_TI_symbol_name("___as__7int64leFL")
	.dwattr $C$DW$55, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$235	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$235, DW_AT_type(*$C$DW$T$60)
	.dwendtag $C$DW$55


$C$DW$56	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$56, DW_AT_declaration
	.dwattr $C$DW$56, DW_AT_TI_symbol_name("___as__7int64leFR7int64le")
	.dwattr $C$DW$56, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$236	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$236, DW_AT_type(*$C$DW$T$62)
	.dwendtag $C$DW$56


$C$DW$57	.dwtag  DW_TAG_subprogram, DW_AT_name("operator long long")
	.dwattr $C$DW$57, DW_AT_declaration
	.dwattr $C$DW$57, DW_AT_TI_symbol_name("___opL__7int64leFv")
	.dwattr $C$DW$57, DW_AT_type(*$C$DW$T$60)
	.dwattr $C$DW$57, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag $C$DW$T$65

$C$DW$T$62	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$62, DW_AT_type(*$C$DW$T$65)
	.dwattr $C$DW$T$62, DW_AT_address_class(0x20)

$C$DW$T$71	.dwtag  DW_TAG_class_type
	.dwattr $C$DW$T$71, DW_AT_name("uint64le")
	.dwattr $C$DW$T$71, DW_AT_byte_size(0x08)
$C$DW$237	.dwtag  DW_TAG_member
	.dwattr $C$DW$237, DW_AT_type(*$C$DW$T$59)
	.dwattr $C$DW$237, DW_AT_name("a")
	.dwattr $C$DW$237, DW_AT_TI_symbol_name("_a")
	.dwattr $C$DW$237, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$237, DW_AT_accessibility(DW_ACCESS_private)

$C$DW$58	.dwtag  DW_TAG_subprogram, DW_AT_name("uint64le")
	.dwattr $C$DW$58, DW_AT_declaration
	.dwattr $C$DW$58, DW_AT_TI_symbol_name("___ct__8uint64leFv")
	.dwattr $C$DW$58, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$59	.dwtag  DW_TAG_subprogram, DW_AT_name("uint64le")
	.dwattr $C$DW$59, DW_AT_declaration
	.dwattr $C$DW$59, DW_AT_TI_symbol_name("___ct__8uint64leFUL")
	.dwattr $C$DW$59, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$238	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$238, DW_AT_type(*$C$DW$T$66)
	.dwendtag $C$DW$59


$C$DW$60	.dwtag  DW_TAG_subprogram, DW_AT_name("uint64le")
	.dwattr $C$DW$60, DW_AT_declaration
	.dwattr $C$DW$60, DW_AT_TI_symbol_name("___ct__8uint64leFR8uint64le")
	.dwattr $C$DW$60, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$239	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$239, DW_AT_type(*$C$DW$T$68)
	.dwendtag $C$DW$60


$C$DW$61	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$61, DW_AT_declaration
	.dwattr $C$DW$61, DW_AT_TI_symbol_name("___as__8uint64leFUL")
	.dwattr $C$DW$61, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$240	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$240, DW_AT_type(*$C$DW$T$66)
	.dwendtag $C$DW$61


$C$DW$62	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$62, DW_AT_declaration
	.dwattr $C$DW$62, DW_AT_TI_symbol_name("___as__8uint64leFR8uint64le")
	.dwattr $C$DW$62, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$241	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$241, DW_AT_type(*$C$DW$T$68)
	.dwendtag $C$DW$62


$C$DW$63	.dwtag  DW_TAG_subprogram, DW_AT_name("operator unsigned long long")
	.dwattr $C$DW$63, DW_AT_declaration
	.dwattr $C$DW$63, DW_AT_TI_symbol_name("___opUL__8uint64leFv")
	.dwattr $C$DW$63, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$63, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag $C$DW$T$71

$C$DW$T$68	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$68, DW_AT_type(*$C$DW$T$71)
	.dwattr $C$DW$T$68, DW_AT_address_class(0x20)

$C$DW$T$74	.dwtag  DW_TAG_class_type
	.dwattr $C$DW$T$74, DW_AT_name("int64be")
	.dwattr $C$DW$T$74, DW_AT_byte_size(0x08)
$C$DW$242	.dwtag  DW_TAG_member
	.dwattr $C$DW$242, DW_AT_type(*$C$DW$T$59)
	.dwattr $C$DW$242, DW_AT_name("a")
	.dwattr $C$DW$242, DW_AT_TI_symbol_name("_a")
	.dwattr $C$DW$242, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$242, DW_AT_accessibility(DW_ACCESS_private)

$C$DW$64	.dwtag  DW_TAG_subprogram, DW_AT_name("int64be")
	.dwattr $C$DW$64, DW_AT_declaration
	.dwattr $C$DW$64, DW_AT_TI_symbol_name("___ct__7int64beFv")
	.dwattr $C$DW$64, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$65	.dwtag  DW_TAG_subprogram, DW_AT_name("int64be")
	.dwattr $C$DW$65, DW_AT_declaration
	.dwattr $C$DW$65, DW_AT_TI_symbol_name("___ct__7int64beFL")
	.dwattr $C$DW$65, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$243	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$243, DW_AT_type(*$C$DW$T$60)
	.dwendtag $C$DW$65


$C$DW$66	.dwtag  DW_TAG_subprogram, DW_AT_name("int64be")
	.dwattr $C$DW$66, DW_AT_declaration
	.dwattr $C$DW$66, DW_AT_TI_symbol_name("___ct__7int64beFR7int64be")
	.dwattr $C$DW$66, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$244	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$244, DW_AT_type(*$C$DW$T$72)
	.dwendtag $C$DW$66


$C$DW$67	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$67, DW_AT_declaration
	.dwattr $C$DW$67, DW_AT_TI_symbol_name("___as__7int64beFL")
	.dwattr $C$DW$67, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$245	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$245, DW_AT_type(*$C$DW$T$60)
	.dwendtag $C$DW$67


$C$DW$68	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$68, DW_AT_declaration
	.dwattr $C$DW$68, DW_AT_TI_symbol_name("___as__7int64beFR7int64be")
	.dwattr $C$DW$68, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$246	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$246, DW_AT_type(*$C$DW$T$72)
	.dwendtag $C$DW$68


$C$DW$69	.dwtag  DW_TAG_subprogram, DW_AT_name("operator long long")
	.dwattr $C$DW$69, DW_AT_declaration
	.dwattr $C$DW$69, DW_AT_TI_symbol_name("___opL__7int64beFv")
	.dwattr $C$DW$69, DW_AT_type(*$C$DW$T$60)
	.dwattr $C$DW$69, DW_AT_accessibility(DW_ACCESS_public)
	.dwendtag $C$DW$T$74

$C$DW$T$72	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$72, DW_AT_type(*$C$DW$T$74)
	.dwattr $C$DW$T$72, DW_AT_address_class(0x20)

$C$DW$T$77	.dwtag  DW_TAG_class_type
	.dwattr $C$DW$T$77, DW_AT_name("uint64be")
	.dwattr $C$DW$T$77, DW_AT_byte_size(0x08)
$C$DW$247	.dwtag  DW_TAG_member
	.dwattr $C$DW$247, DW_AT_type(*$C$DW$T$59)
	.dwattr $C$DW$247, DW_AT_name("a")
	.dwattr $C$DW$247, DW_AT_TI_symbol_name("_a")
	.dwattr $C$DW$247, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$247, DW_AT_accessibility(DW_ACCESS_private)

$C$DW$70	.dwtag  DW_TAG_subprogram, DW_AT_name("uint64be")
	.dwattr $C$DW$70, DW_AT_declaration
	.dwattr $C$DW$70, DW_AT_TI_symbol_name("___ct__8uint64beFv")
	.dwattr $C$DW$70, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$71	.dwtag  DW_TAG_subprogram, DW_AT_name("uint64be")
	.dwattr $C$DW$71, DW_AT_declaration
	.dwattr $C$DW$71, DW_AT_TI_symbol_name("___ct__8uint64beFUL")
	.dwattr $C$DW$71, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$248	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$248, DW_AT_type(*$C$DW$T$66)
	.dwendtag $C$DW$71


$C$DW$72	.dwtag  DW_TAG_subprogram, DW_AT_name("uint64be")
	.dwattr $C$DW$72, DW_AT_declaration
	.dwattr $C$DW$72, DW_AT_TI_symbol_name("___ct__8uint64beFR8uint64be")
	.dwattr $C$DW$72, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$249	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$249, DW_AT_type(*$C$DW$T$75)
	.dwendtag $C$DW$72


$C$DW$73	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$73, DW_AT_declaration
	.dwattr $C$DW$73, DW_AT_TI_symbol_name("___as__8uint64beFUL")
	.dwattr $C$DW$73, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$250	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$250, DW_AT_type(*$C$DW$T$66)
	.dwendtag $C$DW$73


$C$DW$74	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$74, DW_AT_declaration
	.dwattr $C$DW$74, DW_AT_TI_symbol_name("___as__8uint64beFR8uint64be")
	.dwattr $C$DW$74, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$251	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$251, DW_AT_type(*$C$DW$T$75)
	.dwendtag $C$DW$74


$C$DW$75	.dwtag  DW_TAG_subprogram, DW_AT_name("operator unsigned long long")
	.dwattr $C$DW$75, DW_AT_declaration
	.dwattr $C$DW$75, DW_AT_TI_symbol_name("___opUL__8uint64beFv")
	.dwattr $C$DW$75, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$75, DW_AT_accessibility(DW_ACCESS_public)
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
$C$DW$T$460	.dwtag  DW_TAG_typedef, DW_AT_name("va_list")
	.dwattr $C$DW$T$460, DW_AT_type(*$C$DW$T$80)
	.dwattr $C$DW$T$460, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$T$110	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$110, DW_AT_type(*$C$DW$T$79)
$C$DW$T$111	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$111, DW_AT_type(*$C$DW$T$110)
	.dwattr $C$DW$T$111, DW_AT_address_class(0x20)

$C$DW$T$123	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$123, DW_AT_type(*$C$DW$T$79)
	.dwattr $C$DW$T$123, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$123, DW_AT_byte_size(0x18)
$C$DW$252	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$252, DW_AT_upper_bound(0x17)
	.dwendtag $C$DW$T$123


$C$DW$T$308	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$308, DW_AT_type(*$C$DW$T$79)
	.dwattr $C$DW$T$308, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$308, DW_AT_byte_size(0x100)
$C$DW$253	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$253, DW_AT_upper_bound(0xff)
	.dwendtag $C$DW$T$308


$C$DW$T$353	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$353, DW_AT_type(*$C$DW$T$79)
	.dwattr $C$DW$T$353, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$353, DW_AT_byte_size(0x0e)
$C$DW$254	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$254, DW_AT_upper_bound(0x0d)
	.dwendtag $C$DW$T$353


$C$DW$T$404	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$404, DW_AT_type(*$C$DW$T$79)
	.dwattr $C$DW$T$404, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$404, DW_AT_byte_size(0x0a)
$C$DW$255	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$255, DW_AT_upper_bound(0x09)
	.dwendtag $C$DW$T$404


$C$DW$T$405	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$405, DW_AT_type(*$C$DW$T$79)
	.dwattr $C$DW$T$405, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$405, DW_AT_byte_size(0x11)
$C$DW$256	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$256, DW_AT_upper_bound(0x10)
	.dwendtag $C$DW$T$405


$C$DW$T$406	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$406, DW_AT_type(*$C$DW$T$79)
	.dwattr $C$DW$T$406, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$406, DW_AT_byte_size(0x05)
$C$DW$257	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$257, DW_AT_upper_bound(0x04)
	.dwendtag $C$DW$T$406


$C$DW$T$407	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$407, DW_AT_type(*$C$DW$T$79)
	.dwattr $C$DW$T$407, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$407, DW_AT_byte_size(0x08)
$C$DW$258	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$258, DW_AT_upper_bound(0x07)
	.dwendtag $C$DW$T$407


$C$DW$T$85	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$85, DW_AT_name("s_os_driver_descriptor")
	.dwattr $C$DW$T$85, DW_AT_byte_size(0x18)
$C$DW$259	.dwtag  DW_TAG_member
	.dwattr $C$DW$259, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$259, DW_AT_name("id")
	.dwattr $C$DW$259, DW_AT_TI_symbol_name("_id")
	.dwattr $C$DW$259, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$259, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$260	.dwtag  DW_TAG_member
	.dwattr $C$DW$260, DW_AT_type(*$C$DW$T$78)
	.dwattr $C$DW$260, DW_AT_name("ctx")
	.dwattr $C$DW$260, DW_AT_TI_symbol_name("_ctx")
	.dwattr $C$DW$260, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$260, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$261	.dwtag  DW_TAG_member
	.dwattr $C$DW$261, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$261, DW_AT_name("own_process")
	.dwattr $C$DW$261, DW_AT_TI_symbol_name("_own_process")
	.dwattr $C$DW$261, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$261, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$262	.dwtag  DW_TAG_member
	.dwattr $C$DW$262, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$262, DW_AT_name("access")
	.dwattr $C$DW$262, DW_AT_TI_symbol_name("_access")
	.dwattr $C$DW$262, DW_AT_data_member_location[DW_OP_plus_uconst 0xa]
	.dwattr $C$DW$262, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$263	.dwtag  DW_TAG_member
	.dwattr $C$DW$263, DW_AT_type(*$C$DW$T$80)
	.dwattr $C$DW$263, DW_AT_name("path")
	.dwattr $C$DW$263, DW_AT_TI_symbol_name("_path")
	.dwattr $C$DW$263, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$263, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$264	.dwtag  DW_TAG_member
	.dwattr $C$DW$264, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$264, DW_AT_name("data")
	.dwattr $C$DW$264, DW_AT_TI_symbol_name("_data")
	.dwattr $C$DW$264, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$264, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$265	.dwtag  DW_TAG_member
	.dwattr $C$DW$265, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$265, DW_AT_name("sem")
	.dwattr $C$DW$265, DW_AT_TI_symbol_name("_sem")
	.dwattr $C$DW$265, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$265, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$76	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$76, DW_AT_declaration
	.dwattr $C$DW$76, DW_AT_TI_symbol_name("___as__22s_os_driver_descriptorFRC22s_os_driver_descriptor")
	.dwattr $C$DW$76, DW_AT_type(*$C$DW$T$81)
	.dwattr $C$DW$76, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$266	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$266, DW_AT_type(*$C$DW$T$83)
	.dwendtag $C$DW$76

	.dwendtag $C$DW$T$85

$C$DW$T$81	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$81, DW_AT_type(*$C$DW$T$85)
	.dwattr $C$DW$T$81, DW_AT_address_class(0x20)

$C$DW$T$84	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$84, DW_AT_type(*$C$DW$T$81)
	.dwattr $C$DW$T$84, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$267	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$267, DW_AT_type(*$C$DW$T$83)
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
$C$DW$268	.dwtag  DW_TAG_member
	.dwattr $C$DW$268, DW_AT_type(*$C$DW$T$78)
	.dwattr $C$DW$268, DW_AT_name("prev")
	.dwattr $C$DW$268, DW_AT_TI_symbol_name("_prev")
	.dwattr $C$DW$268, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$268, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$269	.dwtag  DW_TAG_member
	.dwattr $C$DW$269, DW_AT_type(*$C$DW$T$78)
	.dwattr $C$DW$269, DW_AT_name("next")
	.dwattr $C$DW$269, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$269, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$269, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$270	.dwtag  DW_TAG_member
	.dwattr $C$DW$270, DW_AT_type(*$C$DW$T$88)
	.dwattr $C$DW$270, DW_AT_name("open")
	.dwattr $C$DW$270, DW_AT_TI_symbol_name("_open")
	.dwattr $C$DW$270, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$270, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$271	.dwtag  DW_TAG_member
	.dwattr $C$DW$271, DW_AT_type(*$C$DW$T$90)
	.dwattr $C$DW$271, DW_AT_name("close")
	.dwattr $C$DW$271, DW_AT_TI_symbol_name("_close")
	.dwattr $C$DW$271, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$271, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$272	.dwtag  DW_TAG_member
	.dwattr $C$DW$272, DW_AT_type(*$C$DW$T$92)
	.dwattr $C$DW$272, DW_AT_name("read")
	.dwattr $C$DW$272, DW_AT_TI_symbol_name("_read")
	.dwattr $C$DW$272, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$272, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$273	.dwtag  DW_TAG_member
	.dwattr $C$DW$273, DW_AT_type(*$C$DW$T$96)
	.dwattr $C$DW$273, DW_AT_name("write")
	.dwattr $C$DW$273, DW_AT_TI_symbol_name("_write")
	.dwattr $C$DW$273, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$273, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$274	.dwtag  DW_TAG_member
	.dwattr $C$DW$274, DW_AT_type(*$C$DW$T$98)
	.dwattr $C$DW$274, DW_AT_name("ioctl")
	.dwattr $C$DW$274, DW_AT_TI_symbol_name("_ioctl")
	.dwattr $C$DW$274, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$274, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$275	.dwtag  DW_TAG_member
	.dwattr $C$DW$275, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$275, DW_AT_name("own_process")
	.dwattr $C$DW$275, DW_AT_TI_symbol_name("_own_process")
	.dwattr $C$DW$275, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr $C$DW$275, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$276	.dwtag  DW_TAG_member
	.dwattr $C$DW$276, DW_AT_type(*$C$DW$T$80)
	.dwattr $C$DW$276, DW_AT_name("name")
	.dwattr $C$DW$276, DW_AT_TI_symbol_name("_name")
	.dwattr $C$DW$276, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr $C$DW$276, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$277	.dwtag  DW_TAG_member
	.dwattr $C$DW$277, DW_AT_type(*$C$DW$T$80)
	.dwattr $C$DW$277, DW_AT_name("path")
	.dwattr $C$DW$277, DW_AT_TI_symbol_name("_path")
	.dwattr $C$DW$277, DW_AT_data_member_location[DW_OP_plus_uconst 0x24]
	.dwattr $C$DW$277, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$278	.dwtag  DW_TAG_member
	.dwattr $C$DW$278, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$278, DW_AT_name("data")
	.dwattr $C$DW$278, DW_AT_TI_symbol_name("_data")
	.dwattr $C$DW$278, DW_AT_data_member_location[DW_OP_plus_uconst 0x28]
	.dwattr $C$DW$278, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$279	.dwtag  DW_TAG_member
	.dwattr $C$DW$279, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$279, DW_AT_name("flags")
	.dwattr $C$DW$279, DW_AT_TI_symbol_name("_flags")
	.dwattr $C$DW$279, DW_AT_data_member_location[DW_OP_plus_uconst 0x2c]
	.dwattr $C$DW$279, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$77	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$77, DW_AT_declaration
	.dwattr $C$DW$77, DW_AT_TI_symbol_name("___as__19s_os_driver_contextFRC19s_os_driver_context")
	.dwattr $C$DW$77, DW_AT_type(*$C$DW$T$99)
	.dwattr $C$DW$77, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$280	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$280, DW_AT_type(*$C$DW$T$101)
	.dwendtag $C$DW$77

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
$C$DW$281	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$281, DW_AT_type(*$C$DW$T$101)
	.dwendtag $C$DW$T$102

$C$DW$T$100	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$100, DW_AT_type(*$C$DW$T$103)
$C$DW$T$101	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$101, DW_AT_type(*$C$DW$T$100)
	.dwattr $C$DW$T$101, DW_AT_address_class(0x20)

$C$DW$T$109	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$109, DW_AT_name("s_inode")
	.dwattr $C$DW$T$109, DW_AT_byte_size(0x28)
$C$DW$282	.dwtag  DW_TAG_member
	.dwattr $C$DW$282, DW_AT_type(*$C$DW$T$104)
	.dwattr $C$DW$282, DW_AT_name("prev")
	.dwattr $C$DW$282, DW_AT_TI_symbol_name("_prev")
	.dwattr $C$DW$282, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$282, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$283	.dwtag  DW_TAG_member
	.dwattr $C$DW$283, DW_AT_type(*$C$DW$T$104)
	.dwattr $C$DW$283, DW_AT_name("next")
	.dwattr $C$DW$283, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$283, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$283, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$284	.dwtag  DW_TAG_member
	.dwattr $C$DW$284, DW_AT_type(*$C$DW$T$80)
	.dwattr $C$DW$284, DW_AT_name("name")
	.dwattr $C$DW$284, DW_AT_TI_symbol_name("_name")
	.dwattr $C$DW$284, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$284, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$285	.dwtag  DW_TAG_member
	.dwattr $C$DW$285, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$285, DW_AT_name("size")
	.dwattr $C$DW$285, DW_AT_TI_symbol_name("_size")
	.dwattr $C$DW$285, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$285, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$286	.dwtag  DW_TAG_member
	.dwattr $C$DW$286, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$286, DW_AT_name("mktime")
	.dwattr $C$DW$286, DW_AT_TI_symbol_name("_mktime")
	.dwattr $C$DW$286, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$286, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$287	.dwtag  DW_TAG_member
	.dwattr $C$DW$287, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$287, DW_AT_name("own_user")
	.dwattr $C$DW$287, DW_AT_TI_symbol_name("_own_user")
	.dwattr $C$DW$287, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr $C$DW$287, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$288	.dwtag  DW_TAG_member
	.dwattr $C$DW$288, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$288, DW_AT_name("own_group")
	.dwattr $C$DW$288, DW_AT_TI_symbol_name("_own_group")
	.dwattr $C$DW$288, DW_AT_data_member_location[DW_OP_plus_uconst 0x1e]
	.dwattr $C$DW$288, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$289	.dwtag  DW_TAG_member
	.dwattr $C$DW$289, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$289, DW_AT_name("access")
	.dwattr $C$DW$289, DW_AT_TI_symbol_name("_access")
	.dwattr $C$DW$289, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr $C$DW$289, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$290	.dwtag  DW_TAG_member
	.dwattr $C$DW$290, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$290, DW_AT_name("type")
	.dwattr $C$DW$290, DW_AT_TI_symbol_name("_type")
	.dwattr $C$DW$290, DW_AT_data_member_location[DW_OP_plus_uconst 0x24]
	.dwattr $C$DW$290, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$78	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$78, DW_AT_declaration
	.dwattr $C$DW$78, DW_AT_TI_symbol_name("___as__7s_inodeFRC7s_inode")
	.dwattr $C$DW$78, DW_AT_type(*$C$DW$T$105)
	.dwattr $C$DW$78, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$291	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$291, DW_AT_type(*$C$DW$T$107)
	.dwendtag $C$DW$78

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
$C$DW$292	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$292, DW_AT_type(*$C$DW$T$107)
	.dwendtag $C$DW$T$108

$C$DW$T$106	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$106, DW_AT_type(*$C$DW$T$109)
$C$DW$T$107	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$107, DW_AT_type(*$C$DW$T$106)
	.dwattr $C$DW$T$107, DW_AT_address_class(0x20)

$C$DW$T$116	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$116, DW_AT_name("s_inode_create")
	.dwattr $C$DW$T$116, DW_AT_byte_size(0x08)
$C$DW$293	.dwtag  DW_TAG_member
	.dwattr $C$DW$293, DW_AT_type(*$C$DW$T$111)
	.dwattr $C$DW$293, DW_AT_name("name")
	.dwattr $C$DW$293, DW_AT_TI_symbol_name("_name")
	.dwattr $C$DW$293, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$293, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$294	.dwtag  DW_TAG_member
	.dwattr $C$DW$294, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$294, DW_AT_name("type")
	.dwattr $C$DW$294, DW_AT_TI_symbol_name("_type")
	.dwattr $C$DW$294, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$294, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$79	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$79, DW_AT_declaration
	.dwattr $C$DW$79, DW_AT_TI_symbol_name("___as__14s_inode_createFRC14s_inode_create")
	.dwattr $C$DW$79, DW_AT_type(*$C$DW$T$112)
	.dwattr $C$DW$79, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$295	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$295, DW_AT_type(*$C$DW$T$114)
	.dwendtag $C$DW$79

	.dwendtag $C$DW$T$116

$C$DW$T$112	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$112, DW_AT_type(*$C$DW$T$116)
	.dwattr $C$DW$T$112, DW_AT_address_class(0x20)

$C$DW$T$115	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$115, DW_AT_type(*$C$DW$T$112)
	.dwattr $C$DW$T$115, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$296	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$296, DW_AT_type(*$C$DW$T$114)
	.dwendtag $C$DW$T$115

$C$DW$T$113	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$113, DW_AT_type(*$C$DW$T$116)
$C$DW$T$114	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$114, DW_AT_type(*$C$DW$T$113)
	.dwattr $C$DW$T$114, DW_AT_address_class(0x20)

$C$DW$T$121	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$121, DW_AT_name("s_ipmp_stat")
	.dwattr $C$DW$T$121, DW_AT_byte_size(0x38)
$C$DW$297	.dwtag  DW_TAG_member
	.dwattr $C$DW$297, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$297, DW_AT_name("rx_count")
	.dwattr $C$DW$297, DW_AT_TI_symbol_name("_rx_count")
	.dwattr $C$DW$297, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$297, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$298	.dwtag  DW_TAG_member
	.dwattr $C$DW$298, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$298, DW_AT_name("rx_bytes")
	.dwattr $C$DW$298, DW_AT_TI_symbol_name("_rx_bytes")
	.dwattr $C$DW$298, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$298, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$299	.dwtag  DW_TAG_member
	.dwattr $C$DW$299, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$299, DW_AT_name("rx_drop")
	.dwattr $C$DW$299, DW_AT_TI_symbol_name("_rx_drop")
	.dwattr $C$DW$299, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$299, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$300	.dwtag  DW_TAG_member
	.dwattr $C$DW$300, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$300, DW_AT_name("rx_drop_mem")
	.dwattr $C$DW$300, DW_AT_TI_symbol_name("_rx_drop_mem")
	.dwattr $C$DW$300, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$300, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$301	.dwtag  DW_TAG_member
	.dwattr $C$DW$301, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$301, DW_AT_name("rx_drop_hash")
	.dwattr $C$DW$301, DW_AT_TI_symbol_name("_rx_drop_hash")
	.dwattr $C$DW$301, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr $C$DW$301, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$302	.dwtag  DW_TAG_member
	.dwattr $C$DW$302, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$302, DW_AT_name("tx_count")
	.dwattr $C$DW$302, DW_AT_TI_symbol_name("_tx_count")
	.dwattr $C$DW$302, DW_AT_data_member_location[DW_OP_plus_uconst 0x28]
	.dwattr $C$DW$302, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$303	.dwtag  DW_TAG_member
	.dwattr $C$DW$303, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$303, DW_AT_name("tx_bytes")
	.dwattr $C$DW$303, DW_AT_TI_symbol_name("_tx_bytes")
	.dwattr $C$DW$303, DW_AT_data_member_location[DW_OP_plus_uconst 0x30]
	.dwattr $C$DW$303, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$80	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$80, DW_AT_declaration
	.dwattr $C$DW$80, DW_AT_TI_symbol_name("___as__11s_ipmp_statFRC11s_ipmp_stat")
	.dwattr $C$DW$80, DW_AT_type(*$C$DW$T$117)
	.dwattr $C$DW$80, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$304	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$304, DW_AT_type(*$C$DW$T$119)
	.dwendtag $C$DW$80

	.dwendtag $C$DW$T$121

$C$DW$T$117	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$117, DW_AT_type(*$C$DW$T$121)
	.dwattr $C$DW$T$117, DW_AT_address_class(0x20)

$C$DW$T$120	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$120, DW_AT_type(*$C$DW$T$117)
	.dwattr $C$DW$T$120, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$305	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$305, DW_AT_type(*$C$DW$T$119)
	.dwendtag $C$DW$T$120

$C$DW$T$118	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$118, DW_AT_type(*$C$DW$T$121)
$C$DW$T$119	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$119, DW_AT_type(*$C$DW$T$118)
	.dwattr $C$DW$T$119, DW_AT_address_class(0x20)

$C$DW$T$128	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$128, DW_AT_name("s_message_link")
	.dwattr $C$DW$T$128, DW_AT_byte_size(0x24)
$C$DW$306	.dwtag  DW_TAG_member
	.dwattr $C$DW$306, DW_AT_type(*$C$DW$T$122)
	.dwattr $C$DW$306, DW_AT_name("next")
	.dwattr $C$DW$306, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$306, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$306, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$307	.dwtag  DW_TAG_member
	.dwattr $C$DW$307, DW_AT_type(*$C$DW$T$122)
	.dwattr $C$DW$307, DW_AT_name("prev")
	.dwattr $C$DW$307, DW_AT_TI_symbol_name("_prev")
	.dwattr $C$DW$307, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$307, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$308	.dwtag  DW_TAG_member
	.dwattr $C$DW$308, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$308, DW_AT_name("id")
	.dwattr $C$DW$308, DW_AT_TI_symbol_name("_id")
	.dwattr $C$DW$308, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$308, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$309	.dwtag  DW_TAG_member
	.dwattr $C$DW$309, DW_AT_type(*$C$DW$T$123)
	.dwattr $C$DW$309, DW_AT_name("name")
	.dwattr $C$DW$309, DW_AT_TI_symbol_name("_name")
	.dwattr $C$DW$309, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$309, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$81	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$81, DW_AT_declaration
	.dwattr $C$DW$81, DW_AT_TI_symbol_name("___as__14s_message_linkFRC14s_message_link")
	.dwattr $C$DW$81, DW_AT_type(*$C$DW$T$124)
	.dwattr $C$DW$81, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$310	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$310, DW_AT_type(*$C$DW$T$126)
	.dwendtag $C$DW$81

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
$C$DW$311	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$311, DW_AT_type(*$C$DW$T$126)
	.dwendtag $C$DW$T$127

$C$DW$T$125	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$125, DW_AT_type(*$C$DW$T$128)
$C$DW$T$126	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$126, DW_AT_type(*$C$DW$T$125)
	.dwattr $C$DW$T$126, DW_AT_address_class(0x20)

$C$DW$T$134	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$134, DW_AT_name("s_message_queue")
	.dwattr $C$DW$T$134, DW_AT_byte_size(0x10)
$C$DW$312	.dwtag  DW_TAG_member
	.dwattr $C$DW$312, DW_AT_type(*$C$DW$T$129)
	.dwattr $C$DW$312, DW_AT_name("first")
	.dwattr $C$DW$312, DW_AT_TI_symbol_name("_first")
	.dwattr $C$DW$312, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$312, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$313	.dwtag  DW_TAG_member
	.dwattr $C$DW$313, DW_AT_type(*$C$DW$T$129)
	.dwattr $C$DW$313, DW_AT_name("last")
	.dwattr $C$DW$313, DW_AT_TI_symbol_name("_last")
	.dwattr $C$DW$313, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$313, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$314	.dwtag  DW_TAG_member
	.dwattr $C$DW$314, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$314, DW_AT_name("syn_sem")
	.dwattr $C$DW$314, DW_AT_TI_symbol_name("_syn_sem")
	.dwattr $C$DW$314, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$314, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$315	.dwtag  DW_TAG_member
	.dwattr $C$DW$315, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$315, DW_AT_name("count_sem")
	.dwattr $C$DW$315, DW_AT_TI_symbol_name("_count_sem")
	.dwattr $C$DW$315, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$315, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$82	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$82, DW_AT_declaration
	.dwattr $C$DW$82, DW_AT_TI_symbol_name("___as__15s_message_queueFRC15s_message_queue")
	.dwattr $C$DW$82, DW_AT_type(*$C$DW$T$130)
	.dwattr $C$DW$82, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$316	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$316, DW_AT_type(*$C$DW$T$132)
	.dwendtag $C$DW$82

	.dwendtag $C$DW$T$134

$C$DW$T$130	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$130, DW_AT_type(*$C$DW$T$134)
	.dwattr $C$DW$T$130, DW_AT_address_class(0x20)

$C$DW$T$133	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$133, DW_AT_type(*$C$DW$T$130)
	.dwattr $C$DW$T$133, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$317	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$317, DW_AT_type(*$C$DW$T$132)
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
$C$DW$318	.dwtag  DW_TAG_member
	.dwattr $C$DW$318, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$318, DW_AT_name("next")
	.dwattr $C$DW$318, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$318, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$318, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$319	.dwtag  DW_TAG_member
	.dwattr $C$DW$319, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$319, DW_AT_name("prev")
	.dwattr $C$DW$319, DW_AT_TI_symbol_name("_prev")
	.dwattr $C$DW$319, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$319, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$320	.dwtag  DW_TAG_member
	.dwattr $C$DW$320, DW_AT_type(*$C$DW$T$122)
	.dwattr $C$DW$320, DW_AT_name("route")
	.dwattr $C$DW$320, DW_AT_TI_symbol_name("_route")
	.dwattr $C$DW$320, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$320, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$321	.dwtag  DW_TAG_member
	.dwattr $C$DW$321, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$321, DW_AT_name("route_count")
	.dwattr $C$DW$321, DW_AT_TI_symbol_name("_route_count")
	.dwattr $C$DW$321, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$321, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$322	.dwtag  DW_TAG_member
	.dwattr $C$DW$322, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$322, DW_AT_name("limit_sem")
	.dwattr $C$DW$322, DW_AT_TI_symbol_name("_limit_sem")
	.dwattr $C$DW$322, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$322, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$323	.dwtag  DW_TAG_member
	.dwattr $C$DW$323, DW_AT_type(*$C$DW$T$136)
	.dwattr $C$DW$323, DW_AT_name("outq")
	.dwattr $C$DW$323, DW_AT_TI_symbol_name("_outq")
	.dwattr $C$DW$323, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$323, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$83	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$83, DW_AT_declaration
	.dwattr $C$DW$83, DW_AT_TI_symbol_name("___as__14s_message_pipeFRC14s_message_pipe")
	.dwattr $C$DW$83, DW_AT_type(*$C$DW$T$137)
	.dwattr $C$DW$83, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$324	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$324, DW_AT_type(*$C$DW$T$139)
	.dwendtag $C$DW$83

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
$C$DW$325	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$325, DW_AT_type(*$C$DW$T$139)
	.dwendtag $C$DW$T$140

$C$DW$T$138	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$138, DW_AT_type(*$C$DW$T$141)
$C$DW$T$139	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$139, DW_AT_type(*$C$DW$T$138)
	.dwattr $C$DW$T$139, DW_AT_address_class(0x20)

$C$DW$T$146	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$146, DW_AT_name("s_message")
	.dwattr $C$DW$T$146, DW_AT_byte_size(0x1c)
$C$DW$326	.dwtag  DW_TAG_member
	.dwattr $C$DW$326, DW_AT_type(*$C$DW$T$129)
	.dwattr $C$DW$326, DW_AT_name("prev")
	.dwattr $C$DW$326, DW_AT_TI_symbol_name("_prev")
	.dwattr $C$DW$326, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$326, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$327	.dwtag  DW_TAG_member
	.dwattr $C$DW$327, DW_AT_type(*$C$DW$T$129)
	.dwattr $C$DW$327, DW_AT_name("next")
	.dwattr $C$DW$327, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$327, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$327, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$328	.dwtag  DW_TAG_member
	.dwattr $C$DW$328, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$328, DW_AT_name("pipe")
	.dwattr $C$DW$328, DW_AT_TI_symbol_name("_pipe")
	.dwattr $C$DW$328, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$328, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$329	.dwtag  DW_TAG_member
	.dwattr $C$DW$329, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$329, DW_AT_name("from")
	.dwattr $C$DW$329, DW_AT_TI_symbol_name("_from")
	.dwattr $C$DW$329, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$329, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$330	.dwtag  DW_TAG_member
	.dwattr $C$DW$330, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$330, DW_AT_name("to")
	.dwattr $C$DW$330, DW_AT_TI_symbol_name("_to")
	.dwattr $C$DW$330, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$330, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$331	.dwtag  DW_TAG_member
	.dwattr $C$DW$331, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$331, DW_AT_name("length")
	.dwattr $C$DW$331, DW_AT_TI_symbol_name("_length")
	.dwattr $C$DW$331, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$331, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$332	.dwtag  DW_TAG_member
	.dwattr $C$DW$332, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$332, DW_AT_name("data")
	.dwattr $C$DW$332, DW_AT_TI_symbol_name("_data")
	.dwattr $C$DW$332, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$332, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$84	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$84, DW_AT_declaration
	.dwattr $C$DW$84, DW_AT_TI_symbol_name("___as__9s_messageFRC9s_message")
	.dwattr $C$DW$84, DW_AT_type(*$C$DW$T$142)
	.dwattr $C$DW$84, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$333	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$333, DW_AT_type(*$C$DW$T$144)
	.dwendtag $C$DW$84

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
$C$DW$334	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$334, DW_AT_type(*$C$DW$T$144)
	.dwendtag $C$DW$T$145

$C$DW$T$143	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$143, DW_AT_type(*$C$DW$T$146)
$C$DW$T$144	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$144, DW_AT_type(*$C$DW$T$143)
	.dwattr $C$DW$T$144, DW_AT_address_class(0x20)

$C$DW$T$151	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$151, DW_AT_name("s_message_context")
	.dwattr $C$DW$T$151, DW_AT_byte_size(0x0c)
$C$DW$335	.dwtag  DW_TAG_member
	.dwattr $C$DW$335, DW_AT_type(*$C$DW$T$136)
	.dwattr $C$DW$335, DW_AT_name("inq")
	.dwattr $C$DW$335, DW_AT_TI_symbol_name("_inq")
	.dwattr $C$DW$335, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$335, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$336	.dwtag  DW_TAG_member
	.dwattr $C$DW$336, DW_AT_type(*$C$DW$T$136)
	.dwattr $C$DW$336, DW_AT_name("outq")
	.dwattr $C$DW$336, DW_AT_TI_symbol_name("_outq")
	.dwattr $C$DW$336, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$336, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$337	.dwtag  DW_TAG_member
	.dwattr $C$DW$337, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$337, DW_AT_name("pipe")
	.dwattr $C$DW$337, DW_AT_TI_symbol_name("_pipe")
	.dwattr $C$DW$337, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$337, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$85	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$85, DW_AT_declaration
	.dwattr $C$DW$85, DW_AT_TI_symbol_name("___as__17s_message_contextFRC17s_message_context")
	.dwattr $C$DW$85, DW_AT_type(*$C$DW$T$147)
	.dwattr $C$DW$85, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$338	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$338, DW_AT_type(*$C$DW$T$149)
	.dwendtag $C$DW$85

	.dwendtag $C$DW$T$151

$C$DW$T$147	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$147, DW_AT_type(*$C$DW$T$151)
	.dwattr $C$DW$T$147, DW_AT_address_class(0x20)

$C$DW$T$150	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$150, DW_AT_type(*$C$DW$T$147)
	.dwattr $C$DW$T$150, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$339	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$339, DW_AT_type(*$C$DW$T$149)
	.dwendtag $C$DW$T$150

$C$DW$T$148	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$148, DW_AT_type(*$C$DW$T$151)
$C$DW$T$149	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$149, DW_AT_type(*$C$DW$T$148)
	.dwattr $C$DW$T$149, DW_AT_address_class(0x20)

$C$DW$T$156	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$156, DW_AT_name("s_os_register")
	.dwattr $C$DW$T$156, DW_AT_byte_size(0x104)
$C$DW$340	.dwtag  DW_TAG_member
	.dwattr $C$DW$340, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$340, DW_AT_name("a0")
	.dwattr $C$DW$340, DW_AT_TI_symbol_name("_a0")
	.dwattr $C$DW$340, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$340, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$341	.dwtag  DW_TAG_member
	.dwattr $C$DW$341, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$341, DW_AT_name("a1")
	.dwattr $C$DW$341, DW_AT_TI_symbol_name("_a1")
	.dwattr $C$DW$341, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$341, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$342	.dwtag  DW_TAG_member
	.dwattr $C$DW$342, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$342, DW_AT_name("b0")
	.dwattr $C$DW$342, DW_AT_TI_symbol_name("_b0")
	.dwattr $C$DW$342, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$342, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$343	.dwtag  DW_TAG_member
	.dwattr $C$DW$343, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$343, DW_AT_name("b1")
	.dwattr $C$DW$343, DW_AT_TI_symbol_name("_b1")
	.dwattr $C$DW$343, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$343, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$344	.dwtag  DW_TAG_member
	.dwattr $C$DW$344, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$344, DW_AT_name("a2")
	.dwattr $C$DW$344, DW_AT_TI_symbol_name("_a2")
	.dwattr $C$DW$344, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$344, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$345	.dwtag  DW_TAG_member
	.dwattr $C$DW$345, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$345, DW_AT_name("a3")
	.dwattr $C$DW$345, DW_AT_TI_symbol_name("_a3")
	.dwattr $C$DW$345, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$345, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$346	.dwtag  DW_TAG_member
	.dwattr $C$DW$346, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$346, DW_AT_name("b2")
	.dwattr $C$DW$346, DW_AT_TI_symbol_name("_b2")
	.dwattr $C$DW$346, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$346, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$347	.dwtag  DW_TAG_member
	.dwattr $C$DW$347, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$347, DW_AT_name("b3")
	.dwattr $C$DW$347, DW_AT_TI_symbol_name("_b3")
	.dwattr $C$DW$347, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr $C$DW$347, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$348	.dwtag  DW_TAG_member
	.dwattr $C$DW$348, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$348, DW_AT_name("a4")
	.dwattr $C$DW$348, DW_AT_TI_symbol_name("_a4")
	.dwattr $C$DW$348, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr $C$DW$348, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$349	.dwtag  DW_TAG_member
	.dwattr $C$DW$349, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$349, DW_AT_name("a5")
	.dwattr $C$DW$349, DW_AT_TI_symbol_name("_a5")
	.dwattr $C$DW$349, DW_AT_data_member_location[DW_OP_plus_uconst 0x24]
	.dwattr $C$DW$349, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$350	.dwtag  DW_TAG_member
	.dwattr $C$DW$350, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$350, DW_AT_name("b4")
	.dwattr $C$DW$350, DW_AT_TI_symbol_name("_b4")
	.dwattr $C$DW$350, DW_AT_data_member_location[DW_OP_plus_uconst 0x28]
	.dwattr $C$DW$350, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$351	.dwtag  DW_TAG_member
	.dwattr $C$DW$351, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$351, DW_AT_name("b5")
	.dwattr $C$DW$351, DW_AT_TI_symbol_name("_b5")
	.dwattr $C$DW$351, DW_AT_data_member_location[DW_OP_plus_uconst 0x2c]
	.dwattr $C$DW$351, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$352	.dwtag  DW_TAG_member
	.dwattr $C$DW$352, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$352, DW_AT_name("a6")
	.dwattr $C$DW$352, DW_AT_TI_symbol_name("_a6")
	.dwattr $C$DW$352, DW_AT_data_member_location[DW_OP_plus_uconst 0x30]
	.dwattr $C$DW$352, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$353	.dwtag  DW_TAG_member
	.dwattr $C$DW$353, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$353, DW_AT_name("a7")
	.dwattr $C$DW$353, DW_AT_TI_symbol_name("_a7")
	.dwattr $C$DW$353, DW_AT_data_member_location[DW_OP_plus_uconst 0x34]
	.dwattr $C$DW$353, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$354	.dwtag  DW_TAG_member
	.dwattr $C$DW$354, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$354, DW_AT_name("b6")
	.dwattr $C$DW$354, DW_AT_TI_symbol_name("_b6")
	.dwattr $C$DW$354, DW_AT_data_member_location[DW_OP_plus_uconst 0x38]
	.dwattr $C$DW$354, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$355	.dwtag  DW_TAG_member
	.dwattr $C$DW$355, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$355, DW_AT_name("b7")
	.dwattr $C$DW$355, DW_AT_TI_symbol_name("_b7")
	.dwattr $C$DW$355, DW_AT_data_member_location[DW_OP_plus_uconst 0x3c]
	.dwattr $C$DW$355, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$356	.dwtag  DW_TAG_member
	.dwattr $C$DW$356, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$356, DW_AT_name("a8")
	.dwattr $C$DW$356, DW_AT_TI_symbol_name("_a8")
	.dwattr $C$DW$356, DW_AT_data_member_location[DW_OP_plus_uconst 0x40]
	.dwattr $C$DW$356, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$357	.dwtag  DW_TAG_member
	.dwattr $C$DW$357, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$357, DW_AT_name("a9")
	.dwattr $C$DW$357, DW_AT_TI_symbol_name("_a9")
	.dwattr $C$DW$357, DW_AT_data_member_location[DW_OP_plus_uconst 0x44]
	.dwattr $C$DW$357, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$358	.dwtag  DW_TAG_member
	.dwattr $C$DW$358, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$358, DW_AT_name("b8")
	.dwattr $C$DW$358, DW_AT_TI_symbol_name("_b8")
	.dwattr $C$DW$358, DW_AT_data_member_location[DW_OP_plus_uconst 0x48]
	.dwattr $C$DW$358, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$359	.dwtag  DW_TAG_member
	.dwattr $C$DW$359, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$359, DW_AT_name("b9")
	.dwattr $C$DW$359, DW_AT_TI_symbol_name("_b9")
	.dwattr $C$DW$359, DW_AT_data_member_location[DW_OP_plus_uconst 0x4c]
	.dwattr $C$DW$359, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$360	.dwtag  DW_TAG_member
	.dwattr $C$DW$360, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$360, DW_AT_name("a10")
	.dwattr $C$DW$360, DW_AT_TI_symbol_name("_a10")
	.dwattr $C$DW$360, DW_AT_data_member_location[DW_OP_plus_uconst 0x50]
	.dwattr $C$DW$360, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$361	.dwtag  DW_TAG_member
	.dwattr $C$DW$361, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$361, DW_AT_name("a11")
	.dwattr $C$DW$361, DW_AT_TI_symbol_name("_a11")
	.dwattr $C$DW$361, DW_AT_data_member_location[DW_OP_plus_uconst 0x54]
	.dwattr $C$DW$361, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$362	.dwtag  DW_TAG_member
	.dwattr $C$DW$362, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$362, DW_AT_name("b10")
	.dwattr $C$DW$362, DW_AT_TI_symbol_name("_b10")
	.dwattr $C$DW$362, DW_AT_data_member_location[DW_OP_plus_uconst 0x58]
	.dwattr $C$DW$362, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$363	.dwtag  DW_TAG_member
	.dwattr $C$DW$363, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$363, DW_AT_name("b11")
	.dwattr $C$DW$363, DW_AT_TI_symbol_name("_b11")
	.dwattr $C$DW$363, DW_AT_data_member_location[DW_OP_plus_uconst 0x5c]
	.dwattr $C$DW$363, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$364	.dwtag  DW_TAG_member
	.dwattr $C$DW$364, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$364, DW_AT_name("a12")
	.dwattr $C$DW$364, DW_AT_TI_symbol_name("_a12")
	.dwattr $C$DW$364, DW_AT_data_member_location[DW_OP_plus_uconst 0x60]
	.dwattr $C$DW$364, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$365	.dwtag  DW_TAG_member
	.dwattr $C$DW$365, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$365, DW_AT_name("a13")
	.dwattr $C$DW$365, DW_AT_TI_symbol_name("_a13")
	.dwattr $C$DW$365, DW_AT_data_member_location[DW_OP_plus_uconst 0x64]
	.dwattr $C$DW$365, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$366	.dwtag  DW_TAG_member
	.dwattr $C$DW$366, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$366, DW_AT_name("b12")
	.dwattr $C$DW$366, DW_AT_TI_symbol_name("_b12")
	.dwattr $C$DW$366, DW_AT_data_member_location[DW_OP_plus_uconst 0x68]
	.dwattr $C$DW$366, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$367	.dwtag  DW_TAG_member
	.dwattr $C$DW$367, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$367, DW_AT_name("_b13")
	.dwattr $C$DW$367, DW_AT_TI_symbol_name("__b13")
	.dwattr $C$DW$367, DW_AT_data_member_location[DW_OP_plus_uconst 0x6c]
	.dwattr $C$DW$367, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$368	.dwtag  DW_TAG_member
	.dwattr $C$DW$368, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$368, DW_AT_name("a14")
	.dwattr $C$DW$368, DW_AT_TI_symbol_name("_a14")
	.dwattr $C$DW$368, DW_AT_data_member_location[DW_OP_plus_uconst 0x70]
	.dwattr $C$DW$368, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$369	.dwtag  DW_TAG_member
	.dwattr $C$DW$369, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$369, DW_AT_name("a15")
	.dwattr $C$DW$369, DW_AT_TI_symbol_name("_a15")
	.dwattr $C$DW$369, DW_AT_data_member_location[DW_OP_plus_uconst 0x74]
	.dwattr $C$DW$369, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$370	.dwtag  DW_TAG_member
	.dwattr $C$DW$370, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$370, DW_AT_name("b14")
	.dwattr $C$DW$370, DW_AT_TI_symbol_name("_b14")
	.dwattr $C$DW$370, DW_AT_data_member_location[DW_OP_plus_uconst 0x78]
	.dwattr $C$DW$370, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$371	.dwtag  DW_TAG_member
	.dwattr $C$DW$371, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$371, DW_AT_name("b15")
	.dwattr $C$DW$371, DW_AT_TI_symbol_name("_b15")
	.dwattr $C$DW$371, DW_AT_data_member_location[DW_OP_plus_uconst 0x7c]
	.dwattr $C$DW$371, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$372	.dwtag  DW_TAG_member
	.dwattr $C$DW$372, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$372, DW_AT_name("a16")
	.dwattr $C$DW$372, DW_AT_TI_symbol_name("_a16")
	.dwattr $C$DW$372, DW_AT_data_member_location[DW_OP_plus_uconst 0x80]
	.dwattr $C$DW$372, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$373	.dwtag  DW_TAG_member
	.dwattr $C$DW$373, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$373, DW_AT_name("a17")
	.dwattr $C$DW$373, DW_AT_TI_symbol_name("_a17")
	.dwattr $C$DW$373, DW_AT_data_member_location[DW_OP_plus_uconst 0x84]
	.dwattr $C$DW$373, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$374	.dwtag  DW_TAG_member
	.dwattr $C$DW$374, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$374, DW_AT_name("b16")
	.dwattr $C$DW$374, DW_AT_TI_symbol_name("_b16")
	.dwattr $C$DW$374, DW_AT_data_member_location[DW_OP_plus_uconst 0x88]
	.dwattr $C$DW$374, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$375	.dwtag  DW_TAG_member
	.dwattr $C$DW$375, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$375, DW_AT_name("b17")
	.dwattr $C$DW$375, DW_AT_TI_symbol_name("_b17")
	.dwattr $C$DW$375, DW_AT_data_member_location[DW_OP_plus_uconst 0x8c]
	.dwattr $C$DW$375, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$376	.dwtag  DW_TAG_member
	.dwattr $C$DW$376, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$376, DW_AT_name("a18")
	.dwattr $C$DW$376, DW_AT_TI_symbol_name("_a18")
	.dwattr $C$DW$376, DW_AT_data_member_location[DW_OP_plus_uconst 0x90]
	.dwattr $C$DW$376, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$377	.dwtag  DW_TAG_member
	.dwattr $C$DW$377, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$377, DW_AT_name("a19")
	.dwattr $C$DW$377, DW_AT_TI_symbol_name("_a19")
	.dwattr $C$DW$377, DW_AT_data_member_location[DW_OP_plus_uconst 0x94]
	.dwattr $C$DW$377, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$378	.dwtag  DW_TAG_member
	.dwattr $C$DW$378, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$378, DW_AT_name("b18")
	.dwattr $C$DW$378, DW_AT_TI_symbol_name("_b18")
	.dwattr $C$DW$378, DW_AT_data_member_location[DW_OP_plus_uconst 0x98]
	.dwattr $C$DW$378, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$379	.dwtag  DW_TAG_member
	.dwattr $C$DW$379, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$379, DW_AT_name("b19")
	.dwattr $C$DW$379, DW_AT_TI_symbol_name("_b19")
	.dwattr $C$DW$379, DW_AT_data_member_location[DW_OP_plus_uconst 0x9c]
	.dwattr $C$DW$379, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$380	.dwtag  DW_TAG_member
	.dwattr $C$DW$380, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$380, DW_AT_name("a20")
	.dwattr $C$DW$380, DW_AT_TI_symbol_name("_a20")
	.dwattr $C$DW$380, DW_AT_data_member_location[DW_OP_plus_uconst 0xa0]
	.dwattr $C$DW$380, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$381	.dwtag  DW_TAG_member
	.dwattr $C$DW$381, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$381, DW_AT_name("a21")
	.dwattr $C$DW$381, DW_AT_TI_symbol_name("_a21")
	.dwattr $C$DW$381, DW_AT_data_member_location[DW_OP_plus_uconst 0xa4]
	.dwattr $C$DW$381, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$382	.dwtag  DW_TAG_member
	.dwattr $C$DW$382, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$382, DW_AT_name("b20")
	.dwattr $C$DW$382, DW_AT_TI_symbol_name("_b20")
	.dwattr $C$DW$382, DW_AT_data_member_location[DW_OP_plus_uconst 0xa8]
	.dwattr $C$DW$382, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$383	.dwtag  DW_TAG_member
	.dwattr $C$DW$383, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$383, DW_AT_name("b21")
	.dwattr $C$DW$383, DW_AT_TI_symbol_name("_b21")
	.dwattr $C$DW$383, DW_AT_data_member_location[DW_OP_plus_uconst 0xac]
	.dwattr $C$DW$383, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$384	.dwtag  DW_TAG_member
	.dwattr $C$DW$384, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$384, DW_AT_name("a22")
	.dwattr $C$DW$384, DW_AT_TI_symbol_name("_a22")
	.dwattr $C$DW$384, DW_AT_data_member_location[DW_OP_plus_uconst 0xb0]
	.dwattr $C$DW$384, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$385	.dwtag  DW_TAG_member
	.dwattr $C$DW$385, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$385, DW_AT_name("a23")
	.dwattr $C$DW$385, DW_AT_TI_symbol_name("_a23")
	.dwattr $C$DW$385, DW_AT_data_member_location[DW_OP_plus_uconst 0xb4]
	.dwattr $C$DW$385, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$386	.dwtag  DW_TAG_member
	.dwattr $C$DW$386, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$386, DW_AT_name("b22")
	.dwattr $C$DW$386, DW_AT_TI_symbol_name("_b22")
	.dwattr $C$DW$386, DW_AT_data_member_location[DW_OP_plus_uconst 0xb8]
	.dwattr $C$DW$386, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$387	.dwtag  DW_TAG_member
	.dwattr $C$DW$387, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$387, DW_AT_name("b23")
	.dwattr $C$DW$387, DW_AT_TI_symbol_name("_b23")
	.dwattr $C$DW$387, DW_AT_data_member_location[DW_OP_plus_uconst 0xbc]
	.dwattr $C$DW$387, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$388	.dwtag  DW_TAG_member
	.dwattr $C$DW$388, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$388, DW_AT_name("a24")
	.dwattr $C$DW$388, DW_AT_TI_symbol_name("_a24")
	.dwattr $C$DW$388, DW_AT_data_member_location[DW_OP_plus_uconst 0xc0]
	.dwattr $C$DW$388, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$389	.dwtag  DW_TAG_member
	.dwattr $C$DW$389, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$389, DW_AT_name("a25")
	.dwattr $C$DW$389, DW_AT_TI_symbol_name("_a25")
	.dwattr $C$DW$389, DW_AT_data_member_location[DW_OP_plus_uconst 0xc4]
	.dwattr $C$DW$389, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$390	.dwtag  DW_TAG_member
	.dwattr $C$DW$390, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$390, DW_AT_name("b24")
	.dwattr $C$DW$390, DW_AT_TI_symbol_name("_b24")
	.dwattr $C$DW$390, DW_AT_data_member_location[DW_OP_plus_uconst 0xc8]
	.dwattr $C$DW$390, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$391	.dwtag  DW_TAG_member
	.dwattr $C$DW$391, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$391, DW_AT_name("b25")
	.dwattr $C$DW$391, DW_AT_TI_symbol_name("_b25")
	.dwattr $C$DW$391, DW_AT_data_member_location[DW_OP_plus_uconst 0xcc]
	.dwattr $C$DW$391, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$392	.dwtag  DW_TAG_member
	.dwattr $C$DW$392, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$392, DW_AT_name("a26")
	.dwattr $C$DW$392, DW_AT_TI_symbol_name("_a26")
	.dwattr $C$DW$392, DW_AT_data_member_location[DW_OP_plus_uconst 0xd0]
	.dwattr $C$DW$392, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$393	.dwtag  DW_TAG_member
	.dwattr $C$DW$393, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$393, DW_AT_name("a27")
	.dwattr $C$DW$393, DW_AT_TI_symbol_name("_a27")
	.dwattr $C$DW$393, DW_AT_data_member_location[DW_OP_plus_uconst 0xd4]
	.dwattr $C$DW$393, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$394	.dwtag  DW_TAG_member
	.dwattr $C$DW$394, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$394, DW_AT_name("b26")
	.dwattr $C$DW$394, DW_AT_TI_symbol_name("_b26")
	.dwattr $C$DW$394, DW_AT_data_member_location[DW_OP_plus_uconst 0xd8]
	.dwattr $C$DW$394, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$395	.dwtag  DW_TAG_member
	.dwattr $C$DW$395, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$395, DW_AT_name("b27")
	.dwattr $C$DW$395, DW_AT_TI_symbol_name("_b27")
	.dwattr $C$DW$395, DW_AT_data_member_location[DW_OP_plus_uconst 0xdc]
	.dwattr $C$DW$395, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$396	.dwtag  DW_TAG_member
	.dwattr $C$DW$396, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$396, DW_AT_name("a28")
	.dwattr $C$DW$396, DW_AT_TI_symbol_name("_a28")
	.dwattr $C$DW$396, DW_AT_data_member_location[DW_OP_plus_uconst 0xe0]
	.dwattr $C$DW$396, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$397	.dwtag  DW_TAG_member
	.dwattr $C$DW$397, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$397, DW_AT_name("a29")
	.dwattr $C$DW$397, DW_AT_TI_symbol_name("_a29")
	.dwattr $C$DW$397, DW_AT_data_member_location[DW_OP_plus_uconst 0xe4]
	.dwattr $C$DW$397, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$398	.dwtag  DW_TAG_member
	.dwattr $C$DW$398, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$398, DW_AT_name("b28")
	.dwattr $C$DW$398, DW_AT_TI_symbol_name("_b28")
	.dwattr $C$DW$398, DW_AT_data_member_location[DW_OP_plus_uconst 0xe8]
	.dwattr $C$DW$398, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$399	.dwtag  DW_TAG_member
	.dwattr $C$DW$399, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$399, DW_AT_name("b29")
	.dwattr $C$DW$399, DW_AT_TI_symbol_name("_b29")
	.dwattr $C$DW$399, DW_AT_data_member_location[DW_OP_plus_uconst 0xec]
	.dwattr $C$DW$399, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$400	.dwtag  DW_TAG_member
	.dwattr $C$DW$400, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$400, DW_AT_name("a30")
	.dwattr $C$DW$400, DW_AT_TI_symbol_name("_a30")
	.dwattr $C$DW$400, DW_AT_data_member_location[DW_OP_plus_uconst 0xf0]
	.dwattr $C$DW$400, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$401	.dwtag  DW_TAG_member
	.dwattr $C$DW$401, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$401, DW_AT_name("a31")
	.dwattr $C$DW$401, DW_AT_TI_symbol_name("_a31")
	.dwattr $C$DW$401, DW_AT_data_member_location[DW_OP_plus_uconst 0xf4]
	.dwattr $C$DW$401, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$402	.dwtag  DW_TAG_member
	.dwattr $C$DW$402, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$402, DW_AT_name("b30")
	.dwattr $C$DW$402, DW_AT_TI_symbol_name("_b30")
	.dwattr $C$DW$402, DW_AT_data_member_location[DW_OP_plus_uconst 0xf8]
	.dwattr $C$DW$402, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$403	.dwtag  DW_TAG_member
	.dwattr $C$DW$403, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$403, DW_AT_name("b31")
	.dwattr $C$DW$403, DW_AT_TI_symbol_name("_b31")
	.dwattr $C$DW$403, DW_AT_data_member_location[DW_OP_plus_uconst 0xfc]
	.dwattr $C$DW$403, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$404	.dwtag  DW_TAG_member
	.dwattr $C$DW$404, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$404, DW_AT_name("amr")
	.dwattr $C$DW$404, DW_AT_TI_symbol_name("_amr")
	.dwattr $C$DW$404, DW_AT_data_member_location[DW_OP_plus_uconst 0x100]
	.dwattr $C$DW$404, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$86	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$86, DW_AT_declaration
	.dwattr $C$DW$86, DW_AT_TI_symbol_name("___as__13s_os_registerFRC13s_os_register")
	.dwattr $C$DW$86, DW_AT_type(*$C$DW$T$152)
	.dwattr $C$DW$86, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$405	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$405, DW_AT_type(*$C$DW$T$154)
	.dwendtag $C$DW$86

	.dwendtag $C$DW$T$156

$C$DW$T$152	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$152, DW_AT_type(*$C$DW$T$156)
	.dwattr $C$DW$T$152, DW_AT_address_class(0x20)

$C$DW$T$155	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$155, DW_AT_type(*$C$DW$T$152)
	.dwattr $C$DW$T$155, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$406	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$406, DW_AT_type(*$C$DW$T$154)
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
$C$DW$407	.dwtag  DW_TAG_member
	.dwattr $C$DW$407, DW_AT_type(*$C$DW$T$157)
	.dwattr $C$DW$407, DW_AT_name("p")
	.dwattr $C$DW$407, DW_AT_TI_symbol_name("_p")
	.dwattr $C$DW$407, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$407, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$408	.dwtag  DW_TAG_member
	.dwattr $C$DW$408, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$408, DW_AT_name("s")
	.dwattr $C$DW$408, DW_AT_TI_symbol_name("_s")
	.dwattr $C$DW$408, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$408, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$409	.dwtag  DW_TAG_member
	.dwattr $C$DW$409, DW_AT_type(*$C$DW$T$158)
	.dwattr $C$DW$409, DW_AT_name("next")
	.dwattr $C$DW$409, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$409, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$409, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$410	.dwtag  DW_TAG_member
	.dwattr $C$DW$410, DW_AT_type(*$C$DW$T$158)
	.dwattr $C$DW$410, DW_AT_name("prev")
	.dwattr $C$DW$410, DW_AT_TI_symbol_name("_prev")
	.dwattr $C$DW$410, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$410, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$411	.dwtag  DW_TAG_member
	.dwattr $C$DW$411, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$411, DW_AT_name("state")
	.dwattr $C$DW$411, DW_AT_TI_symbol_name("_state")
	.dwattr $C$DW$411, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$411, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$412	.dwtag  DW_TAG_member
	.dwattr $C$DW$412, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$412, DW_AT_name("unlock_at")
	.dwattr $C$DW$412, DW_AT_TI_symbol_name("_unlock_at")
	.dwattr $C$DW$412, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$412, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$87	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$87, DW_AT_declaration
	.dwattr $C$DW$87, DW_AT_TI_symbol_name("___as__11s_os_lockerFRC11s_os_locker")
	.dwattr $C$DW$87, DW_AT_type(*$C$DW$T$159)
	.dwattr $C$DW$87, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$413	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$413, DW_AT_type(*$C$DW$T$161)
	.dwendtag $C$DW$87

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
$C$DW$414	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$414, DW_AT_type(*$C$DW$T$161)
	.dwendtag $C$DW$T$162

$C$DW$T$160	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$160, DW_AT_type(*$C$DW$T$163)
$C$DW$T$161	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$161, DW_AT_type(*$C$DW$T$160)
	.dwattr $C$DW$T$161, DW_AT_address_class(0x20)

$C$DW$T$169	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$169, DW_AT_name("s_os_mem_block")
	.dwattr $C$DW$T$169, DW_AT_byte_size(0x10)
$C$DW$415	.dwtag  DW_TAG_member
	.dwattr $C$DW$415, DW_AT_type(*$C$DW$T$164)
	.dwattr $C$DW$415, DW_AT_name("prev")
	.dwattr $C$DW$415, DW_AT_TI_symbol_name("_prev")
	.dwattr $C$DW$415, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$415, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$416	.dwtag  DW_TAG_member
	.dwattr $C$DW$416, DW_AT_type(*$C$DW$T$164)
	.dwattr $C$DW$416, DW_AT_name("next")
	.dwattr $C$DW$416, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$416, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$416, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$417	.dwtag  DW_TAG_member
	.dwattr $C$DW$417, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$417, DW_AT_name("length")
	.dwattr $C$DW$417, DW_AT_TI_symbol_name("_length")
	.dwattr $C$DW$417, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$417, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$418	.dwtag  DW_TAG_member
	.dwattr $C$DW$418, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$418, DW_AT_name("pid")
	.dwattr $C$DW$418, DW_AT_TI_symbol_name("_pid")
	.dwattr $C$DW$418, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$418, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$419	.dwtag  DW_TAG_member
	.dwattr $C$DW$419, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$419, DW_AT_name("flags")
	.dwattr $C$DW$419, DW_AT_TI_symbol_name("_flags")
	.dwattr $C$DW$419, DW_AT_data_member_location[DW_OP_plus_uconst 0xe]
	.dwattr $C$DW$419, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$88	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$88, DW_AT_declaration
	.dwattr $C$DW$88, DW_AT_TI_symbol_name("___as__14s_os_mem_blockFRC14s_os_mem_block")
	.dwattr $C$DW$88, DW_AT_type(*$C$DW$T$165)
	.dwattr $C$DW$88, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$420	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$420, DW_AT_type(*$C$DW$T$167)
	.dwendtag $C$DW$88

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
$C$DW$421	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$421, DW_AT_type(*$C$DW$T$167)
	.dwendtag $C$DW$T$168

$C$DW$T$166	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$166, DW_AT_type(*$C$DW$T$169)
$C$DW$T$167	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$167, DW_AT_type(*$C$DW$T$166)
	.dwattr $C$DW$T$167, DW_AT_address_class(0x20)

$C$DW$T$175	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$175, DW_AT_name("s_os_heap")
	.dwattr $C$DW$T$175, DW_AT_byte_size(0x10)
$C$DW$422	.dwtag  DW_TAG_member
	.dwattr $C$DW$422, DW_AT_type(*$C$DW$T$170)
	.dwattr $C$DW$422, DW_AT_name("prev")
	.dwattr $C$DW$422, DW_AT_TI_symbol_name("_prev")
	.dwattr $C$DW$422, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$422, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$423	.dwtag  DW_TAG_member
	.dwattr $C$DW$423, DW_AT_type(*$C$DW$T$170)
	.dwattr $C$DW$423, DW_AT_name("next")
	.dwattr $C$DW$423, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$423, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$423, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$424	.dwtag  DW_TAG_member
	.dwattr $C$DW$424, DW_AT_type(*$C$DW$T$164)
	.dwattr $C$DW$424, DW_AT_name("block")
	.dwattr $C$DW$424, DW_AT_TI_symbol_name("_block")
	.dwattr $C$DW$424, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$424, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$425	.dwtag  DW_TAG_member
	.dwattr $C$DW$425, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$425, DW_AT_name("flags")
	.dwattr $C$DW$425, DW_AT_TI_symbol_name("_flags")
	.dwattr $C$DW$425, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$425, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$89	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$89, DW_AT_declaration
	.dwattr $C$DW$89, DW_AT_TI_symbol_name("___as__9s_os_heapFRC9s_os_heap")
	.dwattr $C$DW$89, DW_AT_type(*$C$DW$T$171)
	.dwattr $C$DW$89, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$426	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$426, DW_AT_type(*$C$DW$T$173)
	.dwendtag $C$DW$89

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
$C$DW$427	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$427, DW_AT_type(*$C$DW$T$173)
	.dwendtag $C$DW$T$174

$C$DW$T$172	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$172, DW_AT_type(*$C$DW$T$175)
$C$DW$T$173	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$173, DW_AT_type(*$C$DW$T$172)
	.dwattr $C$DW$T$173, DW_AT_address_class(0x20)

$C$DW$T$180	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$180, DW_AT_name("s_os_extension_f")
	.dwattr $C$DW$T$180, DW_AT_byte_size(0x0c)
$C$DW$428	.dwtag  DW_TAG_member
	.dwattr $C$DW$428, DW_AT_type(*$C$DW$T$111)
	.dwattr $C$DW$428, DW_AT_name("f_name")
	.dwattr $C$DW$428, DW_AT_TI_symbol_name("_f_name")
	.dwattr $C$DW$428, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$428, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$429	.dwtag  DW_TAG_member
	.dwattr $C$DW$429, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$429, DW_AT_name("f_syscall_index")
	.dwattr $C$DW$429, DW_AT_TI_symbol_name("_f_syscall_index")
	.dwattr $C$DW$429, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$429, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$430	.dwtag  DW_TAG_member
	.dwattr $C$DW$430, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$430, DW_AT_name("f_ptr")
	.dwattr $C$DW$430, DW_AT_TI_symbol_name("_f_ptr")
	.dwattr $C$DW$430, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$430, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$90	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$90, DW_AT_declaration
	.dwattr $C$DW$90, DW_AT_TI_symbol_name("___as__16s_os_extension_fFRC16s_os_extension_f")
	.dwattr $C$DW$90, DW_AT_type(*$C$DW$T$176)
	.dwattr $C$DW$90, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$431	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$431, DW_AT_type(*$C$DW$T$178)
	.dwendtag $C$DW$90

	.dwendtag $C$DW$T$180

$C$DW$T$176	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$176, DW_AT_type(*$C$DW$T$180)
	.dwattr $C$DW$T$176, DW_AT_address_class(0x20)

$C$DW$T$179	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$179, DW_AT_type(*$C$DW$T$176)
	.dwattr $C$DW$T$179, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$432	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$432, DW_AT_type(*$C$DW$T$178)
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
$C$DW$433	.dwtag  DW_TAG_member
	.dwattr $C$DW$433, DW_AT_type(*$C$DW$T$181)
	.dwattr $C$DW$433, DW_AT_name("next")
	.dwattr $C$DW$433, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$433, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$433, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$434	.dwtag  DW_TAG_member
	.dwattr $C$DW$434, DW_AT_type(*$C$DW$T$181)
	.dwattr $C$DW$434, DW_AT_name("prev")
	.dwattr $C$DW$434, DW_AT_TI_symbol_name("_prev")
	.dwattr $C$DW$434, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$434, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$435	.dwtag  DW_TAG_member
	.dwattr $C$DW$435, DW_AT_type(*$C$DW$T$111)
	.dwattr $C$DW$435, DW_AT_name("name")
	.dwattr $C$DW$435, DW_AT_TI_symbol_name("_name")
	.dwattr $C$DW$435, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$435, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$436	.dwtag  DW_TAG_member
	.dwattr $C$DW$436, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$436, DW_AT_name("f_count")
	.dwattr $C$DW$436, DW_AT_TI_symbol_name("_f_count")
	.dwattr $C$DW$436, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$436, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$437	.dwtag  DW_TAG_member
	.dwattr $C$DW$437, DW_AT_type(*$C$DW$T$182)
	.dwattr $C$DW$437, DW_AT_name("f_tab")
	.dwattr $C$DW$437, DW_AT_TI_symbol_name("_f_tab")
	.dwattr $C$DW$437, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$437, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$438	.dwtag  DW_TAG_member
	.dwattr $C$DW$438, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$438, DW_AT_name("usage")
	.dwattr $C$DW$438, DW_AT_TI_symbol_name("_usage")
	.dwattr $C$DW$438, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$438, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$439	.dwtag  DW_TAG_member
	.dwattr $C$DW$439, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$439, DW_AT_name("lacc")
	.dwattr $C$DW$439, DW_AT_TI_symbol_name("_lacc")
	.dwattr $C$DW$439, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$439, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$440	.dwtag  DW_TAG_member
	.dwattr $C$DW$440, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$440, DW_AT_name("flags")
	.dwattr $C$DW$440, DW_AT_TI_symbol_name("_flags")
	.dwattr $C$DW$440, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr $C$DW$440, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$441	.dwtag  DW_TAG_member
	.dwattr $C$DW$441, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$441, DW_AT_name("own_process")
	.dwattr $C$DW$441, DW_AT_TI_symbol_name("_own_process")
	.dwattr $C$DW$441, DW_AT_data_member_location[DW_OP_plus_uconst 0x24]
	.dwattr $C$DW$441, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$91	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$91, DW_AT_declaration
	.dwattr $C$DW$91, DW_AT_TI_symbol_name("___as__14s_os_extensionFRC14s_os_extension")
	.dwattr $C$DW$91, DW_AT_type(*$C$DW$T$183)
	.dwattr $C$DW$91, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$442	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$442, DW_AT_type(*$C$DW$T$185)
	.dwendtag $C$DW$91

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
$C$DW$443	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$443, DW_AT_type(*$C$DW$T$185)
	.dwendtag $C$DW$T$186

$C$DW$T$184	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$184, DW_AT_type(*$C$DW$T$187)
$C$DW$T$185	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$185, DW_AT_type(*$C$DW$T$184)
	.dwattr $C$DW$T$185, DW_AT_address_class(0x20)

$C$DW$T$193	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$193, DW_AT_name("s_os_extension_link")
	.dwattr $C$DW$T$193, DW_AT_byte_size(0x0c)
$C$DW$444	.dwtag  DW_TAG_member
	.dwattr $C$DW$444, DW_AT_type(*$C$DW$T$188)
	.dwattr $C$DW$444, DW_AT_name("prev")
	.dwattr $C$DW$444, DW_AT_TI_symbol_name("_prev")
	.dwattr $C$DW$444, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$444, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$445	.dwtag  DW_TAG_member
	.dwattr $C$DW$445, DW_AT_type(*$C$DW$T$188)
	.dwattr $C$DW$445, DW_AT_name("next")
	.dwattr $C$DW$445, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$445, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$445, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$446	.dwtag  DW_TAG_member
	.dwattr $C$DW$446, DW_AT_type(*$C$DW$T$181)
	.dwattr $C$DW$446, DW_AT_name("e")
	.dwattr $C$DW$446, DW_AT_TI_symbol_name("_e")
	.dwattr $C$DW$446, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$446, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$92	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$92, DW_AT_declaration
	.dwattr $C$DW$92, DW_AT_TI_symbol_name("___as__19s_os_extension_linkFRC19s_os_extension_link")
	.dwattr $C$DW$92, DW_AT_type(*$C$DW$T$189)
	.dwattr $C$DW$92, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$447	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$447, DW_AT_type(*$C$DW$T$191)
	.dwendtag $C$DW$92

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
$C$DW$448	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$448, DW_AT_type(*$C$DW$T$191)
	.dwendtag $C$DW$T$192

$C$DW$T$190	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$190, DW_AT_type(*$C$DW$T$193)
$C$DW$T$191	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$191, DW_AT_type(*$C$DW$T$190)
	.dwattr $C$DW$T$191, DW_AT_address_class(0x20)

$C$DW$T$199	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$199, DW_AT_name("s_os_process_context")
	.dwattr $C$DW$T$199, DW_AT_byte_size(0x88)
$C$DW$449	.dwtag  DW_TAG_member
	.dwattr $C$DW$449, DW_AT_type(*$C$DW$T$194)
	.dwattr $C$DW$449, DW_AT_name("reg")
	.dwattr $C$DW$449, DW_AT_TI_symbol_name("_reg")
	.dwattr $C$DW$449, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$449, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$450	.dwtag  DW_TAG_member
	.dwattr $C$DW$450, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$450, DW_AT_name("id")
	.dwattr $C$DW$450, DW_AT_TI_symbol_name("_id")
	.dwattr $C$DW$450, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$450, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$451	.dwtag  DW_TAG_member
	.dwattr $C$DW$451, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$451, DW_AT_name("pflags")
	.dwattr $C$DW$451, DW_AT_TI_symbol_name("_pflags")
	.dwattr $C$DW$451, DW_AT_data_member_location[DW_OP_plus_uconst 0x6]
	.dwattr $C$DW$451, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$452	.dwtag  DW_TAG_member
	.dwattr $C$DW$452, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$452, DW_AT_name("peff")
	.dwattr $C$DW$452, DW_AT_TI_symbol_name("_peff")
	.dwattr $C$DW$452, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$452, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$453	.dwtag  DW_TAG_member
	.dwattr $C$DW$453, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$453, DW_AT_name("pcnt")
	.dwattr $C$DW$453, DW_AT_TI_symbol_name("_pcnt")
	.dwattr $C$DW$453, DW_AT_data_member_location[DW_OP_plus_uconst 0xa]
	.dwattr $C$DW$453, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$454	.dwtag  DW_TAG_member
	.dwattr $C$DW$454, DW_AT_type(*$C$DW$T$157)
	.dwattr $C$DW$454, DW_AT_name("next")
	.dwattr $C$DW$454, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$454, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$454, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$455	.dwtag  DW_TAG_member
	.dwattr $C$DW$455, DW_AT_type(*$C$DW$T$157)
	.dwattr $C$DW$455, DW_AT_name("prev")
	.dwattr $C$DW$455, DW_AT_TI_symbol_name("_prev")
	.dwattr $C$DW$455, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$455, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$456	.dwtag  DW_TAG_member
	.dwattr $C$DW$456, DW_AT_type(*$C$DW$T$163)
	.dwattr $C$DW$456, DW_AT_name("locker")
	.dwattr $C$DW$456, DW_AT_TI_symbol_name("_locker")
	.dwattr $C$DW$456, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$456, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$457	.dwtag  DW_TAG_member
	.dwattr $C$DW$457, DW_AT_type(*$C$DW$T$170)
	.dwattr $C$DW$457, DW_AT_name("heap")
	.dwattr $C$DW$457, DW_AT_TI_symbol_name("_heap")
	.dwattr $C$DW$457, DW_AT_data_member_location[DW_OP_plus_uconst 0x38]
	.dwattr $C$DW$457, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$458	.dwtag  DW_TAG_member
	.dwattr $C$DW$458, DW_AT_type(*$C$DW$T$164)
	.dwattr $C$DW$458, DW_AT_name("stack")
	.dwattr $C$DW$458, DW_AT_TI_symbol_name("_stack")
	.dwattr $C$DW$458, DW_AT_data_member_location[DW_OP_plus_uconst 0x3c]
	.dwattr $C$DW$458, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$459	.dwtag  DW_TAG_member
	.dwattr $C$DW$459, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$459, DW_AT_name("arg")
	.dwattr $C$DW$459, DW_AT_TI_symbol_name("_arg")
	.dwattr $C$DW$459, DW_AT_data_member_location[DW_OP_plus_uconst 0x40]
	.dwattr $C$DW$459, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$460	.dwtag  DW_TAG_member
	.dwattr $C$DW$460, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$460, DW_AT_name("arglen")
	.dwattr $C$DW$460, DW_AT_TI_symbol_name("_arglen")
	.dwattr $C$DW$460, DW_AT_data_member_location[DW_OP_plus_uconst 0x44]
	.dwattr $C$DW$460, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$461	.dwtag  DW_TAG_member
	.dwattr $C$DW$461, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$461, DW_AT_name("sfault_code")
	.dwattr $C$DW$461, DW_AT_TI_symbol_name("_sfault_code")
	.dwattr $C$DW$461, DW_AT_data_member_location[DW_OP_plus_uconst 0x48]
	.dwattr $C$DW$461, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$462	.dwtag  DW_TAG_member
	.dwattr $C$DW$462, DW_AT_type(*$C$DW$T$157)
	.dwattr $C$DW$462, DW_AT_name("parent")
	.dwattr $C$DW$462, DW_AT_TI_symbol_name("_parent")
	.dwattr $C$DW$462, DW_AT_data_member_location[DW_OP_plus_uconst 0x4c]
	.dwattr $C$DW$462, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$463	.dwtag  DW_TAG_member
	.dwattr $C$DW$463, DW_AT_type(*$C$DW$T$205)
	.dwattr $C$DW$463, DW_AT_name("msg")
	.dwattr $C$DW$463, DW_AT_TI_symbol_name("_msg")
	.dwattr $C$DW$463, DW_AT_data_member_location[DW_OP_plus_uconst 0x50]
	.dwattr $C$DW$463, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$464	.dwtag  DW_TAG_member
	.dwattr $C$DW$464, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$464, DW_AT_name("errno")
	.dwattr $C$DW$464, DW_AT_TI_symbol_name("_errno")
	.dwattr $C$DW$464, DW_AT_data_member_location[DW_OP_plus_uconst 0x78]
	.dwattr $C$DW$464, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$465	.dwtag  DW_TAG_member
	.dwattr $C$DW$465, DW_AT_type(*$C$DW$T$188)
	.dwattr $C$DW$465, DW_AT_name("ext_used")
	.dwattr $C$DW$465, DW_AT_TI_symbol_name("_ext_used")
	.dwattr $C$DW$465, DW_AT_data_member_location[DW_OP_plus_uconst 0x7c]
	.dwattr $C$DW$465, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$466	.dwtag  DW_TAG_member
	.dwattr $C$DW$466, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$466, DW_AT_name("join_sem")
	.dwattr $C$DW$466, DW_AT_TI_symbol_name("_join_sem")
	.dwattr $C$DW$466, DW_AT_data_member_location[DW_OP_plus_uconst 0x80]
	.dwattr $C$DW$466, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$93	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$93, DW_AT_declaration
	.dwattr $C$DW$93, DW_AT_TI_symbol_name("___as__20s_os_process_contextFRC20s_os_process_context")
	.dwattr $C$DW$93, DW_AT_type(*$C$DW$T$195)
	.dwattr $C$DW$93, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$467	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$467, DW_AT_type(*$C$DW$T$197)
	.dwendtag $C$DW$93

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
$C$DW$468	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$468, DW_AT_type(*$C$DW$T$197)
	.dwendtag $C$DW$T$198

$C$DW$T$196	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$196, DW_AT_type(*$C$DW$T$199)
$C$DW$T$197	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$197, DW_AT_type(*$C$DW$T$196)
	.dwattr $C$DW$T$197, DW_AT_address_class(0x20)

$C$DW$T$205	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$205, DW_AT_name("s_message_process_data")
	.dwattr $C$DW$T$205, DW_AT_byte_size(0x28)
$C$DW$469	.dwtag  DW_TAG_member
	.dwattr $C$DW$469, DW_AT_type(*$C$DW$T$200)
	.dwattr $C$DW$469, DW_AT_name("prev")
	.dwattr $C$DW$469, DW_AT_TI_symbol_name("_prev")
	.dwattr $C$DW$469, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$469, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$470	.dwtag  DW_TAG_member
	.dwattr $C$DW$470, DW_AT_type(*$C$DW$T$200)
	.dwattr $C$DW$470, DW_AT_name("next")
	.dwattr $C$DW$470, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$470, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$470, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$471	.dwtag  DW_TAG_member
	.dwattr $C$DW$471, DW_AT_type(*$C$DW$T$157)
	.dwattr $C$DW$471, DW_AT_name("p")
	.dwattr $C$DW$471, DW_AT_TI_symbol_name("_p")
	.dwattr $C$DW$471, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$471, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$472	.dwtag  DW_TAG_member
	.dwattr $C$DW$472, DW_AT_type(*$C$DW$T$80)
	.dwattr $C$DW$472, DW_AT_name("name")
	.dwattr $C$DW$472, DW_AT_TI_symbol_name("_name")
	.dwattr $C$DW$472, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$472, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$473	.dwtag  DW_TAG_member
	.dwattr $C$DW$473, DW_AT_type(*$C$DW$T$134)
	.dwattr $C$DW$473, DW_AT_name("inq")
	.dwattr $C$DW$473, DW_AT_TI_symbol_name("_inq")
	.dwattr $C$DW$473, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$473, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$474	.dwtag  DW_TAG_member
	.dwattr $C$DW$474, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$474, DW_AT_name("avg_ppid")
	.dwattr $C$DW$474, DW_AT_TI_symbol_name("_avg_ppid")
	.dwattr $C$DW$474, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr $C$DW$474, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$475	.dwtag  DW_TAG_member
	.dwattr $C$DW$475, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$475, DW_AT_name("avg_reqid")
	.dwattr $C$DW$475, DW_AT_TI_symbol_name("_avg_reqid")
	.dwattr $C$DW$475, DW_AT_data_member_location[DW_OP_plus_uconst 0x24]
	.dwattr $C$DW$475, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$94	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$94, DW_AT_declaration
	.dwattr $C$DW$94, DW_AT_TI_symbol_name("___as__22s_message_process_dataFRC22s_message_process_data")
	.dwattr $C$DW$94, DW_AT_type(*$C$DW$T$201)
	.dwattr $C$DW$94, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$476	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$476, DW_AT_type(*$C$DW$T$203)
	.dwendtag $C$DW$94

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
$C$DW$477	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$477, DW_AT_type(*$C$DW$T$203)
	.dwendtag $C$DW$T$204

$C$DW$T$202	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$202, DW_AT_type(*$C$DW$T$205)
$C$DW$T$203	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$203, DW_AT_type(*$C$DW$T$202)
	.dwattr $C$DW$T$203, DW_AT_address_class(0x20)

$C$DW$T$210	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$210, DW_AT_name("s_os_core_init")
	.dwattr $C$DW$T$210, DW_AT_byte_size(0x14)
$C$DW$478	.dwtag  DW_TAG_member
	.dwattr $C$DW$478, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$478, DW_AT_name("core_heap_len")
	.dwattr $C$DW$478, DW_AT_TI_symbol_name("_core_heap_len")
	.dwattr $C$DW$478, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$478, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$479	.dwtag  DW_TAG_member
	.dwattr $C$DW$479, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$479, DW_AT_name("sys_quant")
	.dwattr $C$DW$479, DW_AT_TI_symbol_name("_sys_quant")
	.dwattr $C$DW$479, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$479, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$480	.dwtag  DW_TAG_member
	.dwattr $C$DW$480, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$480, DW_AT_name("sem_list_len")
	.dwattr $C$DW$480, DW_AT_TI_symbol_name("_sem_list_len")
	.dwattr $C$DW$480, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$480, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$481	.dwtag  DW_TAG_member
	.dwattr $C$DW$481, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$481, DW_AT_name("extram_start")
	.dwattr $C$DW$481, DW_AT_TI_symbol_name("_extram_start")
	.dwattr $C$DW$481, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$481, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$482	.dwtag  DW_TAG_member
	.dwattr $C$DW$482, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$482, DW_AT_name("extram_end")
	.dwattr $C$DW$482, DW_AT_TI_symbol_name("_extram_end")
	.dwattr $C$DW$482, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$482, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$95	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$95, DW_AT_declaration
	.dwattr $C$DW$95, DW_AT_TI_symbol_name("___as__14s_os_core_initFRC14s_os_core_init")
	.dwattr $C$DW$95, DW_AT_type(*$C$DW$T$206)
	.dwattr $C$DW$95, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$483	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$483, DW_AT_type(*$C$DW$T$208)
	.dwendtag $C$DW$95

	.dwendtag $C$DW$T$210

$C$DW$T$206	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$206, DW_AT_type(*$C$DW$T$210)
	.dwattr $C$DW$T$206, DW_AT_address_class(0x20)

$C$DW$T$209	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$209, DW_AT_type(*$C$DW$T$206)
	.dwattr $C$DW$T$209, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$484	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$484, DW_AT_type(*$C$DW$T$208)
	.dwendtag $C$DW$T$209

$C$DW$T$207	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$207, DW_AT_type(*$C$DW$T$210)
$C$DW$T$208	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$208, DW_AT_type(*$C$DW$T$207)
	.dwattr $C$DW$T$208, DW_AT_address_class(0x20)

$C$DW$T$216	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$216, DW_AT_name("s_prc_attr")
	.dwattr $C$DW$T$216, DW_AT_byte_size(0x14)
$C$DW$485	.dwtag  DW_TAG_member
	.dwattr $C$DW$485, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$485, DW_AT_name("stack")
	.dwattr $C$DW$485, DW_AT_TI_symbol_name("_stack")
	.dwattr $C$DW$485, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$485, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$486	.dwtag  DW_TAG_member
	.dwattr $C$DW$486, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$486, DW_AT_name("heap")
	.dwattr $C$DW$486, DW_AT_TI_symbol_name("_heap")
	.dwattr $C$DW$486, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$486, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$487	.dwtag  DW_TAG_member
	.dwattr $C$DW$487, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$487, DW_AT_name("priority")
	.dwattr $C$DW$487, DW_AT_TI_symbol_name("_priority")
	.dwattr $C$DW$487, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$487, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$488	.dwtag  DW_TAG_member
	.dwattr $C$DW$488, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$488, DW_AT_name("bss")
	.dwattr $C$DW$488, DW_AT_TI_symbol_name("_bss")
	.dwattr $C$DW$488, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$488, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$489	.dwtag  DW_TAG_member
	.dwattr $C$DW$489, DW_AT_type(*$C$DW$T$211)
	.dwattr $C$DW$489, DW_AT_name("exit_vector")
	.dwattr $C$DW$489, DW_AT_TI_symbol_name("_exit_vector")
	.dwattr $C$DW$489, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$489, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$96	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$96, DW_AT_declaration
	.dwattr $C$DW$96, DW_AT_TI_symbol_name("___as__10s_prc_attrFRC10s_prc_attr")
	.dwattr $C$DW$96, DW_AT_type(*$C$DW$T$212)
	.dwattr $C$DW$96, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$490	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$490, DW_AT_type(*$C$DW$T$214)
	.dwendtag $C$DW$96

	.dwendtag $C$DW$T$216

$C$DW$T$212	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$212, DW_AT_type(*$C$DW$T$216)
	.dwattr $C$DW$T$212, DW_AT_address_class(0x20)

$C$DW$T$215	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$215, DW_AT_type(*$C$DW$T$212)
	.dwattr $C$DW$T$215, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$491	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$491, DW_AT_type(*$C$DW$T$214)
	.dwendtag $C$DW$T$215

$C$DW$T$213	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$213, DW_AT_type(*$C$DW$T$216)
$C$DW$T$214	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$214, DW_AT_type(*$C$DW$T$213)
	.dwattr $C$DW$T$214, DW_AT_address_class(0x20)

$C$DW$T$221	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$221, DW_AT_name("s_os_mem_stat")
	.dwattr $C$DW$T$221, DW_AT_byte_size(0x40)
$C$DW$492	.dwtag  DW_TAG_member
	.dwattr $C$DW$492, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$492, DW_AT_name("total")
	.dwattr $C$DW$492, DW_AT_TI_symbol_name("_total")
	.dwattr $C$DW$492, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$492, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$493	.dwtag  DW_TAG_member
	.dwattr $C$DW$493, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$493, DW_AT_name("used")
	.dwattr $C$DW$493, DW_AT_TI_symbol_name("_used")
	.dwattr $C$DW$493, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$493, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$494	.dwtag  DW_TAG_member
	.dwattr $C$DW$494, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$494, DW_AT_name("free")
	.dwattr $C$DW$494, DW_AT_TI_symbol_name("_free")
	.dwattr $C$DW$494, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$494, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$495	.dwtag  DW_TAG_member
	.dwattr $C$DW$495, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$495, DW_AT_name("c_desc")
	.dwattr $C$DW$495, DW_AT_TI_symbol_name("_c_desc")
	.dwattr $C$DW$495, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$495, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$496	.dwtag  DW_TAG_member
	.dwattr $C$DW$496, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$496, DW_AT_name("c_16_64")
	.dwattr $C$DW$496, DW_AT_TI_symbol_name("_c_16_64")
	.dwattr $C$DW$496, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr $C$DW$496, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$497	.dwtag  DW_TAG_member
	.dwattr $C$DW$497, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$497, DW_AT_name("c_64_256")
	.dwattr $C$DW$497, DW_AT_TI_symbol_name("_c_64_256")
	.dwattr $C$DW$497, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr $C$DW$497, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$498	.dwtag  DW_TAG_member
	.dwattr $C$DW$498, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$498, DW_AT_name("c_256_1k")
	.dwattr $C$DW$498, DW_AT_TI_symbol_name("_c_256_1k")
	.dwattr $C$DW$498, DW_AT_data_member_location[DW_OP_plus_uconst 0x24]
	.dwattr $C$DW$498, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$499	.dwtag  DW_TAG_member
	.dwattr $C$DW$499, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$499, DW_AT_name("c_1k_4k")
	.dwattr $C$DW$499, DW_AT_TI_symbol_name("_c_1k_4k")
	.dwattr $C$DW$499, DW_AT_data_member_location[DW_OP_plus_uconst 0x28]
	.dwattr $C$DW$499, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$500	.dwtag  DW_TAG_member
	.dwattr $C$DW$500, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$500, DW_AT_name("c_4k_16k")
	.dwattr $C$DW$500, DW_AT_TI_symbol_name("_c_4k_16k")
	.dwattr $C$DW$500, DW_AT_data_member_location[DW_OP_plus_uconst 0x2c]
	.dwattr $C$DW$500, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$501	.dwtag  DW_TAG_member
	.dwattr $C$DW$501, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$501, DW_AT_name("c_16k_64k")
	.dwattr $C$DW$501, DW_AT_TI_symbol_name("_c_16k_64k")
	.dwattr $C$DW$501, DW_AT_data_member_location[DW_OP_plus_uconst 0x30]
	.dwattr $C$DW$501, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$502	.dwtag  DW_TAG_member
	.dwattr $C$DW$502, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$502, DW_AT_name("c_64k_256k")
	.dwattr $C$DW$502, DW_AT_TI_symbol_name("_c_64k_256k")
	.dwattr $C$DW$502, DW_AT_data_member_location[DW_OP_plus_uconst 0x34]
	.dwattr $C$DW$502, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$503	.dwtag  DW_TAG_member
	.dwattr $C$DW$503, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$503, DW_AT_name("c_256k_1m")
	.dwattr $C$DW$503, DW_AT_TI_symbol_name("_c_256k_1m")
	.dwattr $C$DW$503, DW_AT_data_member_location[DW_OP_plus_uconst 0x38]
	.dwattr $C$DW$503, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$504	.dwtag  DW_TAG_member
	.dwattr $C$DW$504, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$504, DW_AT_name("c_1m_inf")
	.dwattr $C$DW$504, DW_AT_TI_symbol_name("_c_1m_inf")
	.dwattr $C$DW$504, DW_AT_data_member_location[DW_OP_plus_uconst 0x3c]
	.dwattr $C$DW$504, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$97	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$97, DW_AT_declaration
	.dwattr $C$DW$97, DW_AT_TI_symbol_name("___as__13s_os_mem_statFRC13s_os_mem_stat")
	.dwattr $C$DW$97, DW_AT_type(*$C$DW$T$217)
	.dwattr $C$DW$97, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$505	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$505, DW_AT_type(*$C$DW$T$219)
	.dwendtag $C$DW$97

	.dwendtag $C$DW$T$221

$C$DW$T$217	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$217, DW_AT_type(*$C$DW$T$221)
	.dwattr $C$DW$T$217, DW_AT_address_class(0x20)

$C$DW$T$220	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$220, DW_AT_type(*$C$DW$T$217)
	.dwattr $C$DW$T$220, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$506	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$506, DW_AT_type(*$C$DW$T$219)
	.dwendtag $C$DW$T$220

$C$DW$T$218	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$218, DW_AT_type(*$C$DW$T$221)
$C$DW$T$219	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$219, DW_AT_type(*$C$DW$T$218)
	.dwattr $C$DW$T$219, DW_AT_address_class(0x20)

$C$DW$T$226	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$226, DW_AT_name("s_os_heap_stat")
	.dwattr $C$DW$T$226, DW_AT_byte_size(0x3c)
$C$DW$507	.dwtag  DW_TAG_member
	.dwattr $C$DW$507, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$507, DW_AT_name("total")
	.dwattr $C$DW$507, DW_AT_TI_symbol_name("_total")
	.dwattr $C$DW$507, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$507, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$508	.dwtag  DW_TAG_member
	.dwattr $C$DW$508, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$508, DW_AT_name("used")
	.dwattr $C$DW$508, DW_AT_TI_symbol_name("_used")
	.dwattr $C$DW$508, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$508, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$509	.dwtag  DW_TAG_member
	.dwattr $C$DW$509, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$509, DW_AT_name("free")
	.dwattr $C$DW$509, DW_AT_TI_symbol_name("_free")
	.dwattr $C$DW$509, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$509, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$510	.dwtag  DW_TAG_member
	.dwattr $C$DW$510, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$510, DW_AT_name("c_desc")
	.dwattr $C$DW$510, DW_AT_TI_symbol_name("_c_desc")
	.dwattr $C$DW$510, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$510, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$511	.dwtag  DW_TAG_member
	.dwattr $C$DW$511, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$511, DW_AT_name("c_0")
	.dwattr $C$DW$511, DW_AT_TI_symbol_name("_c_0")
	.dwattr $C$DW$511, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$511, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$512	.dwtag  DW_TAG_member
	.dwattr $C$DW$512, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$512, DW_AT_name("c_4_16")
	.dwattr $C$DW$512, DW_AT_TI_symbol_name("_c_4_16")
	.dwattr $C$DW$512, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$512, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$513	.dwtag  DW_TAG_member
	.dwattr $C$DW$513, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$513, DW_AT_name("c_16_64")
	.dwattr $C$DW$513, DW_AT_TI_symbol_name("_c_16_64")
	.dwattr $C$DW$513, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$513, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$514	.dwtag  DW_TAG_member
	.dwattr $C$DW$514, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$514, DW_AT_name("c_64_256")
	.dwattr $C$DW$514, DW_AT_TI_symbol_name("_c_64_256")
	.dwattr $C$DW$514, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr $C$DW$514, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$515	.dwtag  DW_TAG_member
	.dwattr $C$DW$515, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$515, DW_AT_name("c_256_1k")
	.dwattr $C$DW$515, DW_AT_TI_symbol_name("_c_256_1k")
	.dwattr $C$DW$515, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr $C$DW$515, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$516	.dwtag  DW_TAG_member
	.dwattr $C$DW$516, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$516, DW_AT_name("c_1k_4k")
	.dwattr $C$DW$516, DW_AT_TI_symbol_name("_c_1k_4k")
	.dwattr $C$DW$516, DW_AT_data_member_location[DW_OP_plus_uconst 0x24]
	.dwattr $C$DW$516, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$517	.dwtag  DW_TAG_member
	.dwattr $C$DW$517, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$517, DW_AT_name("c_4k_16k")
	.dwattr $C$DW$517, DW_AT_TI_symbol_name("_c_4k_16k")
	.dwattr $C$DW$517, DW_AT_data_member_location[DW_OP_plus_uconst 0x28]
	.dwattr $C$DW$517, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$518	.dwtag  DW_TAG_member
	.dwattr $C$DW$518, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$518, DW_AT_name("c_16k_64k")
	.dwattr $C$DW$518, DW_AT_TI_symbol_name("_c_16k_64k")
	.dwattr $C$DW$518, DW_AT_data_member_location[DW_OP_plus_uconst 0x2c]
	.dwattr $C$DW$518, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$519	.dwtag  DW_TAG_member
	.dwattr $C$DW$519, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$519, DW_AT_name("c_64k_256k")
	.dwattr $C$DW$519, DW_AT_TI_symbol_name("_c_64k_256k")
	.dwattr $C$DW$519, DW_AT_data_member_location[DW_OP_plus_uconst 0x30]
	.dwattr $C$DW$519, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$520	.dwtag  DW_TAG_member
	.dwattr $C$DW$520, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$520, DW_AT_name("c_256k_1m")
	.dwattr $C$DW$520, DW_AT_TI_symbol_name("_c_256k_1m")
	.dwattr $C$DW$520, DW_AT_data_member_location[DW_OP_plus_uconst 0x34]
	.dwattr $C$DW$520, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$521	.dwtag  DW_TAG_member
	.dwattr $C$DW$521, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$521, DW_AT_name("c_1m_inf")
	.dwattr $C$DW$521, DW_AT_TI_symbol_name("_c_1m_inf")
	.dwattr $C$DW$521, DW_AT_data_member_location[DW_OP_plus_uconst 0x38]
	.dwattr $C$DW$521, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$98	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$98, DW_AT_declaration
	.dwattr $C$DW$98, DW_AT_TI_symbol_name("___as__14s_os_heap_statFRC14s_os_heap_stat")
	.dwattr $C$DW$98, DW_AT_type(*$C$DW$T$222)
	.dwattr $C$DW$98, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$522	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$522, DW_AT_type(*$C$DW$T$224)
	.dwendtag $C$DW$98

	.dwendtag $C$DW$T$226

$C$DW$T$222	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$222, DW_AT_type(*$C$DW$T$226)
	.dwattr $C$DW$T$222, DW_AT_address_class(0x20)

$C$DW$T$225	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$225, DW_AT_type(*$C$DW$T$222)
	.dwattr $C$DW$T$225, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$523	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$523, DW_AT_type(*$C$DW$T$224)
	.dwendtag $C$DW$T$225

$C$DW$T$223	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$223, DW_AT_type(*$C$DW$T$226)
$C$DW$T$224	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$224, DW_AT_type(*$C$DW$T$223)
	.dwattr $C$DW$T$224, DW_AT_address_class(0x20)

$C$DW$T$231	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$231, DW_AT_name("s_os_semaphore")
	.dwattr $C$DW$T$231, DW_AT_byte_size(0x18)
$C$DW$524	.dwtag  DW_TAG_member
	.dwattr $C$DW$524, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$524, DW_AT_name("id")
	.dwattr $C$DW$524, DW_AT_TI_symbol_name("_id")
	.dwattr $C$DW$524, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$524, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$525	.dwtag  DW_TAG_member
	.dwattr $C$DW$525, DW_AT_type(*$C$DW$T$80)
	.dwattr $C$DW$525, DW_AT_name("name")
	.dwattr $C$DW$525, DW_AT_TI_symbol_name("_name")
	.dwattr $C$DW$525, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$525, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$526	.dwtag  DW_TAG_member
	.dwattr $C$DW$526, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$526, DW_AT_name("v")
	.dwattr $C$DW$526, DW_AT_TI_symbol_name("_v")
	.dwattr $C$DW$526, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$526, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$527	.dwtag  DW_TAG_member
	.dwattr $C$DW$527, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$527, DW_AT_name("w")
	.dwattr $C$DW$527, DW_AT_TI_symbol_name("_w")
	.dwattr $C$DW$527, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$527, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$528	.dwtag  DW_TAG_member
	.dwattr $C$DW$528, DW_AT_type(*$C$DW$T$158)
	.dwattr $C$DW$528, DW_AT_name("first")
	.dwattr $C$DW$528, DW_AT_TI_symbol_name("_first")
	.dwattr $C$DW$528, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$528, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$529	.dwtag  DW_TAG_member
	.dwattr $C$DW$529, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$529, DW_AT_name("own_process")
	.dwattr $C$DW$529, DW_AT_TI_symbol_name("_own_process")
	.dwattr $C$DW$529, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$529, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$99	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$99, DW_AT_declaration
	.dwattr $C$DW$99, DW_AT_TI_symbol_name("___as__14s_os_semaphoreFRC14s_os_semaphore")
	.dwattr $C$DW$99, DW_AT_type(*$C$DW$T$227)
	.dwattr $C$DW$99, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$530	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$530, DW_AT_type(*$C$DW$T$229)
	.dwendtag $C$DW$99

	.dwendtag $C$DW$T$231

$C$DW$T$227	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$227, DW_AT_type(*$C$DW$T$231)
	.dwattr $C$DW$T$227, DW_AT_address_class(0x20)

$C$DW$T$230	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$230, DW_AT_type(*$C$DW$T$227)
	.dwattr $C$DW$T$230, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$531	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$531, DW_AT_type(*$C$DW$T$229)
	.dwendtag $C$DW$T$230

$C$DW$T$228	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$228, DW_AT_type(*$C$DW$T$231)
$C$DW$T$229	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$229, DW_AT_type(*$C$DW$T$228)
	.dwattr $C$DW$T$229, DW_AT_address_class(0x20)

$C$DW$T$238	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$238, DW_AT_name("s_lif_header")
	.dwattr $C$DW$T$238, DW_AT_byte_size(0x80)
$C$DW$532	.dwtag  DW_TAG_member
	.dwattr $C$DW$532, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$532, DW_AT_name("magic")
	.dwattr $C$DW$532, DW_AT_TI_symbol_name("_magic")
	.dwattr $C$DW$532, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$532, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$533	.dwtag  DW_TAG_member
	.dwattr $C$DW$533, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$533, DW_AT_name("type")
	.dwattr $C$DW$533, DW_AT_TI_symbol_name("_type")
	.dwattr $C$DW$533, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$533, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$534	.dwtag  DW_TAG_member
	.dwattr $C$DW$534, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$534, DW_AT_name("target")
	.dwattr $C$DW$534, DW_AT_TI_symbol_name("_target")
	.dwattr $C$DW$534, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$534, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$535	.dwtag  DW_TAG_member
	.dwattr $C$DW$535, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$535, DW_AT_name("length")
	.dwattr $C$DW$535, DW_AT_TI_symbol_name("_length")
	.dwattr $C$DW$535, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$535, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$536	.dwtag  DW_TAG_member
	.dwattr $C$DW$536, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$536, DW_AT_name("vepoint_offset")
	.dwattr $C$DW$536, DW_AT_TI_symbol_name("_vepoint_offset")
	.dwattr $C$DW$536, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$536, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$537	.dwtag  DW_TAG_member
	.dwattr $C$DW$537, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$537, DW_AT_name("vepoint_snum")
	.dwattr $C$DW$537, DW_AT_TI_symbol_name("_vepoint_snum")
	.dwattr $C$DW$537, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$537, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$538	.dwtag  DW_TAG_member
	.dwattr $C$DW$538, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$538, DW_AT_name("version")
	.dwattr $C$DW$538, DW_AT_TI_symbol_name("_version")
	.dwattr $C$DW$538, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$538, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$539	.dwtag  DW_TAG_member
	.dwattr $C$DW$539, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$539, DW_AT_name("revision")
	.dwattr $C$DW$539, DW_AT_TI_symbol_name("_revision")
	.dwattr $C$DW$539, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr $C$DW$539, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$540	.dwtag  DW_TAG_member
	.dwattr $C$DW$540, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$540, DW_AT_name("flags")
	.dwattr $C$DW$540, DW_AT_TI_symbol_name("_flags")
	.dwattr $C$DW$540, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr $C$DW$540, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$541	.dwtag  DW_TAG_member
	.dwattr $C$DW$541, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$541, DW_AT_name("scount")
	.dwattr $C$DW$541, DW_AT_TI_symbol_name("_scount")
	.dwattr $C$DW$541, DW_AT_data_member_location[DW_OP_plus_uconst 0x24]
	.dwattr $C$DW$541, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$542	.dwtag  DW_TAG_member
	.dwattr $C$DW$542, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$542, DW_AT_name("stack")
	.dwattr $C$DW$542, DW_AT_TI_symbol_name("_stack")
	.dwattr $C$DW$542, DW_AT_data_member_location[DW_OP_plus_uconst 0x28]
	.dwattr $C$DW$542, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$543	.dwtag  DW_TAG_member
	.dwattr $C$DW$543, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$543, DW_AT_name("symcount")
	.dwattr $C$DW$543, DW_AT_TI_symbol_name("_symcount")
	.dwattr $C$DW$543, DW_AT_data_member_location[DW_OP_plus_uconst 0x2c]
	.dwattr $C$DW$543, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$544	.dwtag  DW_TAG_member
	.dwattr $C$DW$544, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$544, DW_AT_name("btime")
	.dwattr $C$DW$544, DW_AT_TI_symbol_name("_btime")
	.dwattr $C$DW$544, DW_AT_data_member_location[DW_OP_plus_uconst 0x30]
	.dwattr $C$DW$544, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$545	.dwtag  DW_TAG_member
	.dwattr $C$DW$545, DW_AT_type(*$C$DW$T$232)
	.dwattr $C$DW$545, DW_AT_name("reserved")
	.dwattr $C$DW$545, DW_AT_TI_symbol_name("_reserved")
	.dwattr $C$DW$545, DW_AT_data_member_location[DW_OP_plus_uconst 0x34]
	.dwattr $C$DW$545, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$546	.dwtag  DW_TAG_member
	.dwattr $C$DW$546, DW_AT_type(*$C$DW$T$233)
	.dwattr $C$DW$546, DW_AT_name("chk")
	.dwattr $C$DW$546, DW_AT_TI_symbol_name("_chk")
	.dwattr $C$DW$546, DW_AT_data_member_location[DW_OP_plus_uconst 0x40]
	.dwattr $C$DW$546, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$100	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$100, DW_AT_declaration
	.dwattr $C$DW$100, DW_AT_TI_symbol_name("___as__12s_lif_headerFRC12s_lif_header")
	.dwattr $C$DW$100, DW_AT_type(*$C$DW$T$234)
	.dwattr $C$DW$100, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$547	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$547, DW_AT_type(*$C$DW$T$236)
	.dwendtag $C$DW$100

	.dwendtag $C$DW$T$238

$C$DW$T$234	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$234, DW_AT_type(*$C$DW$T$238)
	.dwattr $C$DW$T$234, DW_AT_address_class(0x20)

$C$DW$T$237	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$237, DW_AT_type(*$C$DW$T$234)
	.dwattr $C$DW$T$237, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$548	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$548, DW_AT_type(*$C$DW$T$236)
	.dwendtag $C$DW$T$237

$C$DW$T$235	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$235, DW_AT_type(*$C$DW$T$238)
$C$DW$T$236	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$236, DW_AT_type(*$C$DW$T$235)
	.dwattr $C$DW$T$236, DW_AT_address_class(0x20)

$C$DW$T$243	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$243, DW_AT_name("s_lif_section")
	.dwattr $C$DW$T$243, DW_AT_byte_size(0x20)
$C$DW$549	.dwtag  DW_TAG_member
	.dwattr $C$DW$549, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$549, DW_AT_name("magic")
	.dwattr $C$DW$549, DW_AT_TI_symbol_name("_magic")
	.dwattr $C$DW$549, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$549, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$550	.dwtag  DW_TAG_member
	.dwattr $C$DW$550, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$550, DW_AT_name("size")
	.dwattr $C$DW$550, DW_AT_TI_symbol_name("_size")
	.dwattr $C$DW$550, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$550, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$551	.dwtag  DW_TAG_member
	.dwattr $C$DW$551, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$551, DW_AT_name("length")
	.dwattr $C$DW$551, DW_AT_TI_symbol_name("_length")
	.dwattr $C$DW$551, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$551, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$552	.dwtag  DW_TAG_member
	.dwattr $C$DW$552, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$552, DW_AT_name("vaddr")
	.dwattr $C$DW$552, DW_AT_TI_symbol_name("_vaddr")
	.dwattr $C$DW$552, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$552, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$553	.dwtag  DW_TAG_member
	.dwattr $C$DW$553, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$553, DW_AT_name("paddr")
	.dwattr $C$DW$553, DW_AT_TI_symbol_name("_paddr")
	.dwattr $C$DW$553, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$553, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$554	.dwtag  DW_TAG_member
	.dwattr $C$DW$554, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$554, DW_AT_name("pcount")
	.dwattr $C$DW$554, DW_AT_TI_symbol_name("_pcount")
	.dwattr $C$DW$554, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$554, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$555	.dwtag  DW_TAG_member
	.dwattr $C$DW$555, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$555, DW_AT_name("flags")
	.dwattr $C$DW$555, DW_AT_TI_symbol_name("_flags")
	.dwattr $C$DW$555, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$555, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$556	.dwtag  DW_TAG_member
	.dwattr $C$DW$556, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$556, DW_AT_name("reserved")
	.dwattr $C$DW$556, DW_AT_TI_symbol_name("_reserved")
	.dwattr $C$DW$556, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr $C$DW$556, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$101	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$101, DW_AT_declaration
	.dwattr $C$DW$101, DW_AT_TI_symbol_name("___as__13s_lif_sectionFRC13s_lif_section")
	.dwattr $C$DW$101, DW_AT_type(*$C$DW$T$239)
	.dwattr $C$DW$101, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$557	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$557, DW_AT_type(*$C$DW$T$241)
	.dwendtag $C$DW$101

	.dwendtag $C$DW$T$243

$C$DW$T$239	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$239, DW_AT_type(*$C$DW$T$243)
	.dwattr $C$DW$T$239, DW_AT_address_class(0x20)

$C$DW$T$242	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$242, DW_AT_type(*$C$DW$T$239)
	.dwattr $C$DW$T$242, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$558	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$558, DW_AT_type(*$C$DW$T$241)
	.dwendtag $C$DW$T$242

$C$DW$T$240	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$240, DW_AT_type(*$C$DW$T$243)
$C$DW$T$241	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$241, DW_AT_type(*$C$DW$T$240)
	.dwattr $C$DW$T$241, DW_AT_address_class(0x20)

$C$DW$T$248	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$248, DW_AT_name("s_lif_patch")
	.dwattr $C$DW$T$248, DW_AT_byte_size(0x14)
$C$DW$559	.dwtag  DW_TAG_member
	.dwattr $C$DW$559, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$559, DW_AT_name("method")
	.dwattr $C$DW$559, DW_AT_TI_symbol_name("_method")
	.dwattr $C$DW$559, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$559, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$560	.dwtag  DW_TAG_member
	.dwattr $C$DW$560, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$560, DW_AT_name("offset")
	.dwattr $C$DW$560, DW_AT_TI_symbol_name("_offset")
	.dwattr $C$DW$560, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$560, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$561	.dwtag  DW_TAG_member
	.dwattr $C$DW$561, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$561, DW_AT_name("v")
	.dwattr $C$DW$561, DW_AT_TI_symbol_name("_v")
	.dwattr $C$DW$561, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$561, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$562	.dwtag  DW_TAG_member
	.dwattr $C$DW$562, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$562, DW_AT_name("a")
	.dwattr $C$DW$562, DW_AT_TI_symbol_name("_a")
	.dwattr $C$DW$562, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$562, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$563	.dwtag  DW_TAG_member
	.dwattr $C$DW$563, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$563, DW_AT_name("b")
	.dwattr $C$DW$563, DW_AT_TI_symbol_name("_b")
	.dwattr $C$DW$563, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$563, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$102	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$102, DW_AT_declaration
	.dwattr $C$DW$102, DW_AT_TI_symbol_name("___as__11s_lif_patchFRC11s_lif_patch")
	.dwattr $C$DW$102, DW_AT_type(*$C$DW$T$244)
	.dwattr $C$DW$102, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$564	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$564, DW_AT_type(*$C$DW$T$246)
	.dwendtag $C$DW$102

	.dwendtag $C$DW$T$248

$C$DW$T$244	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$244, DW_AT_type(*$C$DW$T$248)
	.dwattr $C$DW$T$244, DW_AT_address_class(0x20)

$C$DW$T$247	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$247, DW_AT_type(*$C$DW$T$244)
	.dwattr $C$DW$T$247, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$565	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$565, DW_AT_type(*$C$DW$T$246)
	.dwendtag $C$DW$T$247

$C$DW$T$245	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$245, DW_AT_type(*$C$DW$T$248)
$C$DW$T$246	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$246, DW_AT_type(*$C$DW$T$245)
	.dwattr $C$DW$T$246, DW_AT_address_class(0x20)

$C$DW$T$253	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$253, DW_AT_name("s_lif_symbol")
	.dwattr $C$DW$T$253, DW_AT_byte_size(0x08)
$C$DW$566	.dwtag  DW_TAG_member
	.dwattr $C$DW$566, DW_AT_type(*$C$DW$T$80)
	.dwattr $C$DW$566, DW_AT_name("name")
	.dwattr $C$DW$566, DW_AT_TI_symbol_name("_name")
	.dwattr $C$DW$566, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$566, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$567	.dwtag  DW_TAG_member
	.dwattr $C$DW$567, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$567, DW_AT_name("address")
	.dwattr $C$DW$567, DW_AT_TI_symbol_name("_address")
	.dwattr $C$DW$567, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$567, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$103	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$103, DW_AT_declaration
	.dwattr $C$DW$103, DW_AT_TI_symbol_name("___as__12s_lif_symbolFRC12s_lif_symbol")
	.dwattr $C$DW$103, DW_AT_type(*$C$DW$T$249)
	.dwattr $C$DW$103, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$568	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$568, DW_AT_type(*$C$DW$T$251)
	.dwendtag $C$DW$103

	.dwendtag $C$DW$T$253

$C$DW$T$249	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$249, DW_AT_type(*$C$DW$T$253)
	.dwattr $C$DW$T$249, DW_AT_address_class(0x20)

$C$DW$T$252	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$252, DW_AT_type(*$C$DW$T$249)
	.dwattr $C$DW$T$252, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$569	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$569, DW_AT_type(*$C$DW$T$251)
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
$C$DW$570	.dwtag  DW_TAG_member
	.dwattr $C$DW$570, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$570, DW_AT_name("entry_point")
	.dwattr $C$DW$570, DW_AT_TI_symbol_name("_entry_point")
	.dwattr $C$DW$570, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$570, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$571	.dwtag  DW_TAG_member
	.dwattr $C$DW$571, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$571, DW_AT_name("bss_point")
	.dwattr $C$DW$571, DW_AT_TI_symbol_name("_bss_point")
	.dwattr $C$DW$571, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$571, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$572	.dwtag  DW_TAG_member
	.dwattr $C$DW$572, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$572, DW_AT_name("stack_size")
	.dwattr $C$DW$572, DW_AT_TI_symbol_name("_stack_size")
	.dwattr $C$DW$572, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$572, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$573	.dwtag  DW_TAG_member
	.dwattr $C$DW$573, DW_AT_type(*$C$DW$T$254)
	.dwattr $C$DW$573, DW_AT_name("symbol")
	.dwattr $C$DW$573, DW_AT_TI_symbol_name("_symbol")
	.dwattr $C$DW$573, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$573, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$574	.dwtag  DW_TAG_member
	.dwattr $C$DW$574, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$574, DW_AT_name("symbol_count")
	.dwattr $C$DW$574, DW_AT_TI_symbol_name("_symbol_count")
	.dwattr $C$DW$574, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$574, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$575	.dwtag  DW_TAG_member
	.dwattr $C$DW$575, DW_AT_type(*$C$DW$T$255)
	.dwattr $C$DW$575, DW_AT_name("page")
	.dwattr $C$DW$575, DW_AT_TI_symbol_name("_page")
	.dwattr $C$DW$575, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$575, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$576	.dwtag  DW_TAG_member
	.dwattr $C$DW$576, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$576, DW_AT_name("page_count")
	.dwattr $C$DW$576, DW_AT_TI_symbol_name("_page_count")
	.dwattr $C$DW$576, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$576, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$104	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$104, DW_AT_declaration
	.dwattr $C$DW$104, DW_AT_TI_symbol_name("___as__13s_lif_overlayFRC13s_lif_overlay")
	.dwattr $C$DW$104, DW_AT_type(*$C$DW$T$256)
	.dwattr $C$DW$104, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$577	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$577, DW_AT_type(*$C$DW$T$258)
	.dwendtag $C$DW$104

	.dwendtag $C$DW$T$260

$C$DW$T$256	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$256, DW_AT_type(*$C$DW$T$260)
	.dwattr $C$DW$T$256, DW_AT_address_class(0x20)

$C$DW$T$259	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$259, DW_AT_type(*$C$DW$T$256)
	.dwattr $C$DW$T$259, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$578	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$578, DW_AT_type(*$C$DW$T$258)
	.dwendtag $C$DW$T$259

$C$DW$T$257	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$257, DW_AT_type(*$C$DW$T$260)
$C$DW$T$258	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$258, DW_AT_type(*$C$DW$T$257)
	.dwattr $C$DW$T$258, DW_AT_address_class(0x20)

$C$DW$T$265	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$265, DW_AT_name("s_os_interrupt")
	.dwattr $C$DW$T$265, DW_AT_byte_size(0x10)
$C$DW$579	.dwtag  DW_TAG_member
	.dwattr $C$DW$579, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$579, DW_AT_name("id")
	.dwattr $C$DW$579, DW_AT_TI_symbol_name("_id")
	.dwattr $C$DW$579, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$579, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$580	.dwtag  DW_TAG_member
	.dwattr $C$DW$580, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$580, DW_AT_name("vector")
	.dwattr $C$DW$580, DW_AT_TI_symbol_name("_vector")
	.dwattr $C$DW$580, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$580, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$581	.dwtag  DW_TAG_member
	.dwattr $C$DW$581, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$581, DW_AT_name("source")
	.dwattr $C$DW$581, DW_AT_TI_symbol_name("_source")
	.dwattr $C$DW$581, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$581, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$582	.dwtag  DW_TAG_member
	.dwattr $C$DW$582, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$582, DW_AT_name("own_process")
	.dwattr $C$DW$582, DW_AT_TI_symbol_name("_own_process")
	.dwattr $C$DW$582, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$582, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$105	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$105, DW_AT_declaration
	.dwattr $C$DW$105, DW_AT_TI_symbol_name("___as__14s_os_interruptFRC14s_os_interrupt")
	.dwattr $C$DW$105, DW_AT_type(*$C$DW$T$261)
	.dwattr $C$DW$105, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$583	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$583, DW_AT_type(*$C$DW$T$263)
	.dwendtag $C$DW$105

	.dwendtag $C$DW$T$265

$C$DW$T$261	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$261, DW_AT_type(*$C$DW$T$265)
	.dwattr $C$DW$T$261, DW_AT_address_class(0x20)

$C$DW$T$264	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$264, DW_AT_type(*$C$DW$T$261)
	.dwattr $C$DW$T$264, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$584	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$584, DW_AT_type(*$C$DW$T$263)
	.dwendtag $C$DW$T$264

$C$DW$T$262	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$262, DW_AT_type(*$C$DW$T$265)
$C$DW$T$263	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$263, DW_AT_type(*$C$DW$T$262)
	.dwattr $C$DW$T$263, DW_AT_address_class(0x20)

$C$DW$T$271	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$271, DW_AT_name("s_os_console")
	.dwattr $C$DW$T$271, DW_AT_byte_size(0x0c)
$C$DW$585	.dwtag  DW_TAG_member
	.dwattr $C$DW$585, DW_AT_type(*$C$DW$T$266)
	.dwattr $C$DW$585, DW_AT_name("next")
	.dwattr $C$DW$585, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$585, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$585, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$586	.dwtag  DW_TAG_member
	.dwattr $C$DW$586, DW_AT_type(*$C$DW$T$266)
	.dwattr $C$DW$586, DW_AT_name("prev")
	.dwattr $C$DW$586, DW_AT_TI_symbol_name("_prev")
	.dwattr $C$DW$586, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$586, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$587	.dwtag  DW_TAG_member
	.dwattr $C$DW$587, DW_AT_type(*$C$DW$T$80)
	.dwattr $C$DW$587, DW_AT_name("path")
	.dwattr $C$DW$587, DW_AT_TI_symbol_name("_path")
	.dwattr $C$DW$587, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$587, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$106	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$106, DW_AT_declaration
	.dwattr $C$DW$106, DW_AT_TI_symbol_name("___as__12s_os_consoleFRC12s_os_console")
	.dwattr $C$DW$106, DW_AT_type(*$C$DW$T$267)
	.dwattr $C$DW$106, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$588	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$588, DW_AT_type(*$C$DW$T$269)
	.dwendtag $C$DW$106

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
$C$DW$589	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$589, DW_AT_type(*$C$DW$T$269)
	.dwendtag $C$DW$T$270

$C$DW$T$268	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$268, DW_AT_type(*$C$DW$T$271)
$C$DW$T$269	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$269, DW_AT_type(*$C$DW$T$268)
	.dwattr $C$DW$T$269, DW_AT_address_class(0x20)

$C$DW$T$277	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$277, DW_AT_name("s_os_iodevice")
	.dwattr $C$DW$T$277, DW_AT_byte_size(0x14)
$C$DW$590	.dwtag  DW_TAG_member
	.dwattr $C$DW$590, DW_AT_type(*$C$DW$T$272)
	.dwattr $C$DW$590, DW_AT_name("next")
	.dwattr $C$DW$590, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$590, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$590, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$591	.dwtag  DW_TAG_member
	.dwattr $C$DW$591, DW_AT_type(*$C$DW$T$272)
	.dwattr $C$DW$591, DW_AT_name("prev")
	.dwattr $C$DW$591, DW_AT_TI_symbol_name("_prev")
	.dwattr $C$DW$591, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$591, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$592	.dwtag  DW_TAG_member
	.dwattr $C$DW$592, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$592, DW_AT_name("con_count")
	.dwattr $C$DW$592, DW_AT_TI_symbol_name("_con_count")
	.dwattr $C$DW$592, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$592, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$593	.dwtag  DW_TAG_member
	.dwattr $C$DW$593, DW_AT_type(*$C$DW$T$266)
	.dwattr $C$DW$593, DW_AT_name("active")
	.dwattr $C$DW$593, DW_AT_TI_symbol_name("_active")
	.dwattr $C$DW$593, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$593, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$594	.dwtag  DW_TAG_member
	.dwattr $C$DW$594, DW_AT_type(*$C$DW$T$80)
	.dwattr $C$DW$594, DW_AT_name("path")
	.dwattr $C$DW$594, DW_AT_TI_symbol_name("_path")
	.dwattr $C$DW$594, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$594, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$107	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$107, DW_AT_declaration
	.dwattr $C$DW$107, DW_AT_TI_symbol_name("___as__13s_os_iodeviceFRC13s_os_iodevice")
	.dwattr $C$DW$107, DW_AT_type(*$C$DW$T$273)
	.dwattr $C$DW$107, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$595	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$595, DW_AT_type(*$C$DW$T$275)
	.dwendtag $C$DW$107

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
$C$DW$596	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$596, DW_AT_type(*$C$DW$T$275)
	.dwendtag $C$DW$T$276

$C$DW$T$274	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$274, DW_AT_type(*$C$DW$T$277)
$C$DW$T$275	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$275, DW_AT_type(*$C$DW$T$274)
	.dwattr $C$DW$T$275, DW_AT_address_class(0x20)

$C$DW$T$282	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$282, DW_AT_name("EDMA_Config")
	.dwattr $C$DW$T$282, DW_AT_byte_size(0x18)
$C$DW$597	.dwtag  DW_TAG_member
	.dwattr $C$DW$597, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$597, DW_AT_name("opt")
	.dwattr $C$DW$597, DW_AT_TI_symbol_name("_opt")
	.dwattr $C$DW$597, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$597, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$598	.dwtag  DW_TAG_member
	.dwattr $C$DW$598, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$598, DW_AT_name("src")
	.dwattr $C$DW$598, DW_AT_TI_symbol_name("_src")
	.dwattr $C$DW$598, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$598, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$599	.dwtag  DW_TAG_member
	.dwattr $C$DW$599, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$599, DW_AT_name("cnt")
	.dwattr $C$DW$599, DW_AT_TI_symbol_name("_cnt")
	.dwattr $C$DW$599, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$599, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$600	.dwtag  DW_TAG_member
	.dwattr $C$DW$600, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$600, DW_AT_name("dst")
	.dwattr $C$DW$600, DW_AT_TI_symbol_name("_dst")
	.dwattr $C$DW$600, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$600, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$601	.dwtag  DW_TAG_member
	.dwattr $C$DW$601, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$601, DW_AT_name("idx")
	.dwattr $C$DW$601, DW_AT_TI_symbol_name("_idx")
	.dwattr $C$DW$601, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$601, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$602	.dwtag  DW_TAG_member
	.dwattr $C$DW$602, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$602, DW_AT_name("rld")
	.dwattr $C$DW$602, DW_AT_TI_symbol_name("_rld")
	.dwattr $C$DW$602, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$602, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$108	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$108, DW_AT_declaration
	.dwattr $C$DW$108, DW_AT_TI_symbol_name("___as__11EDMA_ConfigFRC11EDMA_Config")
	.dwattr $C$DW$108, DW_AT_type(*$C$DW$T$278)
	.dwattr $C$DW$108, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$603	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$603, DW_AT_type(*$C$DW$T$280)
	.dwendtag $C$DW$108

	.dwendtag $C$DW$T$282

$C$DW$T$278	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$278, DW_AT_type(*$C$DW$T$282)
	.dwattr $C$DW$T$278, DW_AT_address_class(0x20)

$C$DW$T$281	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$281, DW_AT_type(*$C$DW$T$278)
	.dwattr $C$DW$T$281, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$604	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$604, DW_AT_type(*$C$DW$T$280)
	.dwendtag $C$DW$T$281

$C$DW$T$279	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$279, DW_AT_type(*$C$DW$T$282)
$C$DW$T$280	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$280, DW_AT_type(*$C$DW$T$279)
	.dwattr $C$DW$T$280, DW_AT_address_class(0x20)
$C$DW$T$464	.dwtag  DW_TAG_typedef, DW_AT_name("EDMA_Config")
	.dwattr $C$DW$T$464, DW_AT_type(*$C$DW$T$282)
	.dwattr $C$DW$T$464, DW_AT_language(DW_LANG_C_plus_plus)

$C$DW$T$287	.dwtag  DW_TAG_class_type
	.dwattr $C$DW$T$287, DW_AT_name("bad_alloc")
	.dwattr $C$DW$T$287, DW_AT_byte_size(0x01)

$C$DW$109	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$109, DW_AT_declaration
	.dwattr $C$DW$109, DW_AT_TI_symbol_name("___as__Q2_3std9bad_allocFRCQ2_3std9bad_alloc")
	.dwattr $C$DW$109, DW_AT_type(*$C$DW$T$283)
	.dwattr $C$DW$109, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$605	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$605, DW_AT_type(*$C$DW$T$285)
	.dwendtag $C$DW$109

	.dwendtag $C$DW$T$287

$C$DW$T$283	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$283, DW_AT_type(*$C$DW$T$287)
	.dwattr $C$DW$T$283, DW_AT_address_class(0x20)

$C$DW$T$286	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$286, DW_AT_type(*$C$DW$T$283)
	.dwattr $C$DW$T$286, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$606	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$606, DW_AT_type(*$C$DW$T$285)
	.dwendtag $C$DW$T$286

$C$DW$T$284	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$284, DW_AT_type(*$C$DW$T$287)
$C$DW$T$285	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$285, DW_AT_type(*$C$DW$T$284)
	.dwattr $C$DW$T$285, DW_AT_address_class(0x20)

$C$DW$T$293	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$293, DW_AT_name("FILE")
	.dwattr $C$DW$T$293, DW_AT_byte_size(0x18)
$C$DW$607	.dwtag  DW_TAG_member
	.dwattr $C$DW$607, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$607, DW_AT_name("rid")
	.dwattr $C$DW$607, DW_AT_TI_symbol_name("_rid")
	.dwattr $C$DW$607, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$607, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$608	.dwtag  DW_TAG_member
	.dwattr $C$DW$608, DW_AT_type(*$C$DW$T$288)
	.dwattr $C$DW$608, DW_AT_name("ungetc_buf")
	.dwattr $C$DW$608, DW_AT_TI_symbol_name("_ungetc_buf")
	.dwattr $C$DW$608, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$608, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$609	.dwtag  DW_TAG_member
	.dwattr $C$DW$609, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$609, DW_AT_name("ungetc_count")
	.dwattr $C$DW$609, DW_AT_TI_symbol_name("_ungetc_count")
	.dwattr $C$DW$609, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$609, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$110	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$110, DW_AT_declaration
	.dwattr $C$DW$110, DW_AT_TI_symbol_name("___as__4FILEFRC4FILE")
	.dwattr $C$DW$110, DW_AT_type(*$C$DW$T$289)
	.dwattr $C$DW$110, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$610	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$610, DW_AT_type(*$C$DW$T$291)
	.dwendtag $C$DW$110

	.dwendtag $C$DW$T$293

$C$DW$T$289	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$289, DW_AT_type(*$C$DW$T$293)
	.dwattr $C$DW$T$289, DW_AT_address_class(0x20)

$C$DW$T$292	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$292, DW_AT_type(*$C$DW$T$289)
	.dwattr $C$DW$T$292, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$611	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$611, DW_AT_type(*$C$DW$T$291)
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
$C$DW$612	.dwtag  DW_TAG_member
	.dwattr $C$DW$612, DW_AT_type(*$C$DW$T$294)
	.dwattr $C$DW$612, DW_AT_name("f")
	.dwattr $C$DW$612, DW_AT_TI_symbol_name("_f")
	.dwattr $C$DW$612, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$612, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$613	.dwtag  DW_TAG_member
	.dwattr $C$DW$613, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$613, DW_AT_name("bpos")
	.dwattr $C$DW$613, DW_AT_TI_symbol_name("_bpos")
	.dwattr $C$DW$613, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$613, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$614	.dwtag  DW_TAG_member
	.dwattr $C$DW$614, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$614, DW_AT_name("b")
	.dwattr $C$DW$614, DW_AT_TI_symbol_name("_b")
	.dwattr $C$DW$614, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$614, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$615	.dwtag  DW_TAG_member
	.dwattr $C$DW$615, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$615, DW_AT_name("mode")
	.dwattr $C$DW$615, DW_AT_TI_symbol_name("_mode")
	.dwattr $C$DW$615, DW_AT_data_member_location[DW_OP_plus_uconst 0x9]
	.dwattr $C$DW$615, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$111	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$111, DW_AT_declaration
	.dwattr $C$DW$111, DW_AT_TI_symbol_name("___as__8BIT_FILEFRC8BIT_FILE")
	.dwattr $C$DW$111, DW_AT_type(*$C$DW$T$295)
	.dwattr $C$DW$111, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$616	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$616, DW_AT_type(*$C$DW$T$297)
	.dwendtag $C$DW$111

	.dwendtag $C$DW$T$299

$C$DW$T$295	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$295, DW_AT_type(*$C$DW$T$299)
	.dwattr $C$DW$T$295, DW_AT_address_class(0x20)

$C$DW$T$298	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$298, DW_AT_type(*$C$DW$T$295)
	.dwattr $C$DW$T$298, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$617	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$617, DW_AT_type(*$C$DW$T$297)
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
$C$DW$618	.dwtag  DW_TAG_member
	.dwattr $C$DW$618, DW_AT_type(*$C$DW$T$300)
	.dwattr $C$DW$618, DW_AT_name("f")
	.dwattr $C$DW$618, DW_AT_TI_symbol_name("_f")
	.dwattr $C$DW$618, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$618, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$619	.dwtag  DW_TAG_member
	.dwattr $C$DW$619, DW_AT_type(*$C$DW$T$301)
	.dwattr $C$DW$619, DW_AT_name("w")
	.dwattr $C$DW$619, DW_AT_TI_symbol_name("_w")
	.dwattr $C$DW$619, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$619, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$620	.dwtag  DW_TAG_member
	.dwattr $C$DW$620, DW_AT_type(*$C$DW$T$302)
	.dwattr $C$DW$620, DW_AT_name("b")
	.dwattr $C$DW$620, DW_AT_TI_symbol_name("_b")
	.dwattr $C$DW$620, DW_AT_data_member_location[DW_OP_plus_uconst 0x404]
	.dwattr $C$DW$620, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$621	.dwtag  DW_TAG_member
	.dwattr $C$DW$621, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$621, DW_AT_name("wpos")
	.dwattr $C$DW$621, DW_AT_TI_symbol_name("_wpos")
	.dwattr $C$DW$621, DW_AT_data_member_location[DW_OP_plus_uconst 0x424]
	.dwattr $C$DW$621, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$622	.dwtag  DW_TAG_member
	.dwattr $C$DW$622, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$622, DW_AT_name("blen")
	.dwattr $C$DW$622, DW_AT_TI_symbol_name("_blen")
	.dwattr $C$DW$622, DW_AT_data_member_location[DW_OP_plus_uconst 0x428]
	.dwattr $C$DW$622, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$623	.dwtag  DW_TAG_member
	.dwattr $C$DW$623, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$623, DW_AT_name("mode")
	.dwattr $C$DW$623, DW_AT_TI_symbol_name("_mode")
	.dwattr $C$DW$623, DW_AT_data_member_location[DW_OP_plus_uconst 0x42c]
	.dwattr $C$DW$623, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$112	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$112, DW_AT_declaration
	.dwattr $C$DW$112, DW_AT_TI_symbol_name("___as__9WLPK_FILEFRC9WLPK_FILE")
	.dwattr $C$DW$112, DW_AT_type(*$C$DW$T$303)
	.dwattr $C$DW$112, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$624	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$624, DW_AT_type(*$C$DW$T$305)
	.dwendtag $C$DW$112

	.dwendtag $C$DW$T$307

$C$DW$T$303	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$303, DW_AT_type(*$C$DW$T$307)
	.dwattr $C$DW$T$303, DW_AT_address_class(0x20)

$C$DW$T$306	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$306, DW_AT_type(*$C$DW$T$303)
	.dwattr $C$DW$T$306, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$625	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$625, DW_AT_type(*$C$DW$T$305)
	.dwendtag $C$DW$T$306

$C$DW$T$304	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$304, DW_AT_type(*$C$DW$T$307)
$C$DW$T$305	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$305, DW_AT_type(*$C$DW$T$304)
	.dwattr $C$DW$T$305, DW_AT_address_class(0x20)

$C$DW$T$313	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$313, DW_AT_name("dirent")
	.dwattr $C$DW$T$313, DW_AT_byte_size(0x110)
$C$DW$626	.dwtag  DW_TAG_member
	.dwattr $C$DW$626, DW_AT_type(*$C$DW$T$308)
	.dwattr $C$DW$626, DW_AT_name("d_name")
	.dwattr $C$DW$626, DW_AT_TI_symbol_name("_d_name")
	.dwattr $C$DW$626, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$626, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$627	.dwtag  DW_TAG_member
	.dwattr $C$DW$627, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$627, DW_AT_name("d_type")
	.dwattr $C$DW$627, DW_AT_TI_symbol_name("_d_type")
	.dwattr $C$DW$627, DW_AT_data_member_location[DW_OP_plus_uconst 0x100]
	.dwattr $C$DW$627, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$628	.dwtag  DW_TAG_member
	.dwattr $C$DW$628, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$628, DW_AT_name("d_size")
	.dwattr $C$DW$628, DW_AT_TI_symbol_name("_d_size")
	.dwattr $C$DW$628, DW_AT_data_member_location[DW_OP_plus_uconst 0x108]
	.dwattr $C$DW$628, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$113	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$113, DW_AT_declaration
	.dwattr $C$DW$113, DW_AT_TI_symbol_name("___as__6direntFRC6dirent")
	.dwattr $C$DW$113, DW_AT_type(*$C$DW$T$309)
	.dwattr $C$DW$113, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$629	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$629, DW_AT_type(*$C$DW$T$311)
	.dwendtag $C$DW$113

	.dwendtag $C$DW$T$313

$C$DW$T$309	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$309, DW_AT_type(*$C$DW$T$313)
	.dwattr $C$DW$T$309, DW_AT_address_class(0x20)

$C$DW$T$312	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$312, DW_AT_type(*$C$DW$T$309)
	.dwattr $C$DW$T$312, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$630	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$630, DW_AT_type(*$C$DW$T$311)
	.dwendtag $C$DW$T$312

$C$DW$T$310	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$310, DW_AT_type(*$C$DW$T$313)
$C$DW$T$311	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$311, DW_AT_type(*$C$DW$T$310)
	.dwattr $C$DW$T$311, DW_AT_address_class(0x20)

$C$DW$T$318	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$318, DW_AT_name("DIR")
	.dwattr $C$DW$T$318, DW_AT_byte_size(0x120)
$C$DW$631	.dwtag  DW_TAG_member
	.dwattr $C$DW$631, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$631, DW_AT_name("rid")
	.dwattr $C$DW$631, DW_AT_TI_symbol_name("_rid")
	.dwattr $C$DW$631, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$631, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$632	.dwtag  DW_TAG_member
	.dwattr $C$DW$632, DW_AT_type(*$C$DW$T$313)
	.dwattr $C$DW$632, DW_AT_name("d_rec")
	.dwattr $C$DW$632, DW_AT_TI_symbol_name("_d_rec")
	.dwattr $C$DW$632, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$632, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$633	.dwtag  DW_TAG_member
	.dwattr $C$DW$633, DW_AT_type(*$C$DW$T$104)
	.dwattr $C$DW$633, DW_AT_name("d_list")
	.dwattr $C$DW$633, DW_AT_TI_symbol_name("_d_list")
	.dwattr $C$DW$633, DW_AT_data_member_location[DW_OP_plus_uconst 0x118]
	.dwattr $C$DW$633, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$634	.dwtag  DW_TAG_member
	.dwattr $C$DW$634, DW_AT_type(*$C$DW$T$104)
	.dwattr $C$DW$634, DW_AT_name("d_cnode")
	.dwattr $C$DW$634, DW_AT_TI_symbol_name("_d_cnode")
	.dwattr $C$DW$634, DW_AT_data_member_location[DW_OP_plus_uconst 0x11c]
	.dwattr $C$DW$634, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$114	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$114, DW_AT_declaration
	.dwattr $C$DW$114, DW_AT_TI_symbol_name("___as__3DIRFRC3DIR")
	.dwattr $C$DW$114, DW_AT_type(*$C$DW$T$314)
	.dwattr $C$DW$114, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$635	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$635, DW_AT_type(*$C$DW$T$316)
	.dwendtag $C$DW$114

	.dwendtag $C$DW$T$318

$C$DW$T$314	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$314, DW_AT_type(*$C$DW$T$318)
	.dwattr $C$DW$T$314, DW_AT_address_class(0x20)

$C$DW$T$317	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$317, DW_AT_type(*$C$DW$T$314)
	.dwattr $C$DW$T$317, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$636	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$636, DW_AT_type(*$C$DW$T$316)
	.dwendtag $C$DW$T$317

$C$DW$T$315	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$315, DW_AT_type(*$C$DW$T$318)
$C$DW$T$316	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$316, DW_AT_type(*$C$DW$T$315)
	.dwattr $C$DW$T$316, DW_AT_address_class(0x20)

$C$DW$T$323	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$323, DW_AT_name("sem_t")
	.dwattr $C$DW$T$323, DW_AT_byte_size(0x08)
$C$DW$637	.dwtag  DW_TAG_member
	.dwattr $C$DW$637, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$637, DW_AT_name("rid")
	.dwattr $C$DW$637, DW_AT_TI_symbol_name("_rid")
	.dwattr $C$DW$637, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$637, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$638	.dwtag  DW_TAG_member
	.dwattr $C$DW$638, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$638, DW_AT_name("nauna")
	.dwattr $C$DW$638, DW_AT_TI_symbol_name("_nauna")
	.dwattr $C$DW$638, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$638, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$115	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$115, DW_AT_declaration
	.dwattr $C$DW$115, DW_AT_TI_symbol_name("___as__5sem_tFRC5sem_t")
	.dwattr $C$DW$115, DW_AT_type(*$C$DW$T$319)
	.dwattr $C$DW$115, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$639	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$639, DW_AT_type(*$C$DW$T$321)
	.dwendtag $C$DW$115

	.dwendtag $C$DW$T$323

$C$DW$T$319	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$319, DW_AT_type(*$C$DW$T$323)
	.dwattr $C$DW$T$319, DW_AT_address_class(0x20)

$C$DW$T$322	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$322, DW_AT_type(*$C$DW$T$319)
	.dwattr $C$DW$T$322, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$640	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$640, DW_AT_type(*$C$DW$T$321)
	.dwendtag $C$DW$T$322

$C$DW$T$320	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$320, DW_AT_type(*$C$DW$T$323)
$C$DW$T$321	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$321, DW_AT_type(*$C$DW$T$320)
	.dwattr $C$DW$T$321, DW_AT_address_class(0x20)

$C$DW$T$328	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$328, DW_AT_name("tm")
	.dwattr $C$DW$T$328, DW_AT_byte_size(0x24)
$C$DW$641	.dwtag  DW_TAG_member
	.dwattr $C$DW$641, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$641, DW_AT_name("tm_sec")
	.dwattr $C$DW$641, DW_AT_TI_symbol_name("_tm_sec")
	.dwattr $C$DW$641, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$641, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$642	.dwtag  DW_TAG_member
	.dwattr $C$DW$642, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$642, DW_AT_name("tm_min")
	.dwattr $C$DW$642, DW_AT_TI_symbol_name("_tm_min")
	.dwattr $C$DW$642, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$642, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$643	.dwtag  DW_TAG_member
	.dwattr $C$DW$643, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$643, DW_AT_name("tm_hour")
	.dwattr $C$DW$643, DW_AT_TI_symbol_name("_tm_hour")
	.dwattr $C$DW$643, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$643, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$644	.dwtag  DW_TAG_member
	.dwattr $C$DW$644, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$644, DW_AT_name("tm_mday")
	.dwattr $C$DW$644, DW_AT_TI_symbol_name("_tm_mday")
	.dwattr $C$DW$644, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$644, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$645	.dwtag  DW_TAG_member
	.dwattr $C$DW$645, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$645, DW_AT_name("tm_mon")
	.dwattr $C$DW$645, DW_AT_TI_symbol_name("_tm_mon")
	.dwattr $C$DW$645, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$645, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$646	.dwtag  DW_TAG_member
	.dwattr $C$DW$646, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$646, DW_AT_name("tm_year")
	.dwattr $C$DW$646, DW_AT_TI_symbol_name("_tm_year")
	.dwattr $C$DW$646, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$646, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$647	.dwtag  DW_TAG_member
	.dwattr $C$DW$647, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$647, DW_AT_name("tm_wday")
	.dwattr $C$DW$647, DW_AT_TI_symbol_name("_tm_wday")
	.dwattr $C$DW$647, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$647, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$648	.dwtag  DW_TAG_member
	.dwattr $C$DW$648, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$648, DW_AT_name("tm_yday")
	.dwattr $C$DW$648, DW_AT_TI_symbol_name("_tm_yday")
	.dwattr $C$DW$648, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr $C$DW$648, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$649	.dwtag  DW_TAG_member
	.dwattr $C$DW$649, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$649, DW_AT_name("tm_isdst")
	.dwattr $C$DW$649, DW_AT_TI_symbol_name("_tm_isdst")
	.dwattr $C$DW$649, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr $C$DW$649, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$116	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$116, DW_AT_declaration
	.dwattr $C$DW$116, DW_AT_TI_symbol_name("___as__2tmFRC2tm")
	.dwattr $C$DW$116, DW_AT_type(*$C$DW$T$324)
	.dwattr $C$DW$116, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$650	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$650, DW_AT_type(*$C$DW$T$326)
	.dwendtag $C$DW$116

	.dwendtag $C$DW$T$328

$C$DW$T$324	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$324, DW_AT_type(*$C$DW$T$328)
	.dwattr $C$DW$T$324, DW_AT_address_class(0x20)

$C$DW$T$327	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$327, DW_AT_type(*$C$DW$T$324)
	.dwattr $C$DW$T$327, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$651	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$651, DW_AT_type(*$C$DW$T$326)
	.dwendtag $C$DW$T$327

$C$DW$T$325	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$325, DW_AT_type(*$C$DW$T$328)
$C$DW$T$326	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$326, DW_AT_type(*$C$DW$T$325)
	.dwattr $C$DW$T$326, DW_AT_address_class(0x20)

$C$DW$T$333	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$333, DW_AT_name("stat")
	.dwattr $C$DW$T$333, DW_AT_byte_size(0x30)
$C$DW$652	.dwtag  DW_TAG_member
	.dwattr $C$DW$652, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$652, DW_AT_name("st_dev")
	.dwattr $C$DW$652, DW_AT_TI_symbol_name("_st_dev")
	.dwattr $C$DW$652, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$652, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$653	.dwtag  DW_TAG_member
	.dwattr $C$DW$653, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$653, DW_AT_name("st_ino")
	.dwattr $C$DW$653, DW_AT_TI_symbol_name("_st_ino")
	.dwattr $C$DW$653, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$653, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$654	.dwtag  DW_TAG_member
	.dwattr $C$DW$654, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$654, DW_AT_name("st_mode")
	.dwattr $C$DW$654, DW_AT_TI_symbol_name("_st_mode")
	.dwattr $C$DW$654, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$654, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$655	.dwtag  DW_TAG_member
	.dwattr $C$DW$655, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$655, DW_AT_name("st_nlink")
	.dwattr $C$DW$655, DW_AT_TI_symbol_name("_st_nlink")
	.dwattr $C$DW$655, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$655, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$656	.dwtag  DW_TAG_member
	.dwattr $C$DW$656, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$656, DW_AT_name("st_uid")
	.dwattr $C$DW$656, DW_AT_TI_symbol_name("_st_uid")
	.dwattr $C$DW$656, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$656, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$657	.dwtag  DW_TAG_member
	.dwattr $C$DW$657, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$657, DW_AT_name("st_gid")
	.dwattr $C$DW$657, DW_AT_TI_symbol_name("_st_gid")
	.dwattr $C$DW$657, DW_AT_data_member_location[DW_OP_plus_uconst 0x12]
	.dwattr $C$DW$657, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$658	.dwtag  DW_TAG_member
	.dwattr $C$DW$658, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$658, DW_AT_name("st_rdev")
	.dwattr $C$DW$658, DW_AT_TI_symbol_name("_st_rdev")
	.dwattr $C$DW$658, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$658, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$659	.dwtag  DW_TAG_member
	.dwattr $C$DW$659, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$659, DW_AT_name("st_size")
	.dwattr $C$DW$659, DW_AT_TI_symbol_name("_st_size")
	.dwattr $C$DW$659, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$659, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$660	.dwtag  DW_TAG_member
	.dwattr $C$DW$660, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$660, DW_AT_name("st_atime")
	.dwattr $C$DW$660, DW_AT_TI_symbol_name("_st_atime")
	.dwattr $C$DW$660, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr $C$DW$660, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$661	.dwtag  DW_TAG_member
	.dwattr $C$DW$661, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$661, DW_AT_name("st_mtime")
	.dwattr $C$DW$661, DW_AT_TI_symbol_name("_st_mtime")
	.dwattr $C$DW$661, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr $C$DW$661, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$662	.dwtag  DW_TAG_member
	.dwattr $C$DW$662, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$662, DW_AT_name("st_ctime")
	.dwattr $C$DW$662, DW_AT_TI_symbol_name("_st_ctime")
	.dwattr $C$DW$662, DW_AT_data_member_location[DW_OP_plus_uconst 0x24]
	.dwattr $C$DW$662, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$663	.dwtag  DW_TAG_member
	.dwattr $C$DW$663, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$663, DW_AT_name("st_blksize")
	.dwattr $C$DW$663, DW_AT_TI_symbol_name("_st_blksize")
	.dwattr $C$DW$663, DW_AT_data_member_location[DW_OP_plus_uconst 0x28]
	.dwattr $C$DW$663, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$664	.dwtag  DW_TAG_member
	.dwattr $C$DW$664, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$664, DW_AT_name("st_blocks")
	.dwattr $C$DW$664, DW_AT_TI_symbol_name("_st_blocks")
	.dwattr $C$DW$664, DW_AT_data_member_location[DW_OP_plus_uconst 0x2c]
	.dwattr $C$DW$664, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$117	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$117, DW_AT_declaration
	.dwattr $C$DW$117, DW_AT_TI_symbol_name("___as__4statFRC4stat")
	.dwattr $C$DW$117, DW_AT_type(*$C$DW$T$329)
	.dwattr $C$DW$117, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$665	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$665, DW_AT_type(*$C$DW$T$331)
	.dwendtag $C$DW$117

	.dwendtag $C$DW$T$333

$C$DW$T$329	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$329, DW_AT_type(*$C$DW$T$333)
	.dwattr $C$DW$T$329, DW_AT_address_class(0x20)

$C$DW$T$332	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$332, DW_AT_type(*$C$DW$T$329)
	.dwattr $C$DW$T$332, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$666	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$666, DW_AT_type(*$C$DW$T$331)
	.dwendtag $C$DW$T$332

$C$DW$T$330	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$330, DW_AT_type(*$C$DW$T$333)
$C$DW$T$331	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$331, DW_AT_type(*$C$DW$T$330)
	.dwattr $C$DW$T$331, DW_AT_address_class(0x20)

$C$DW$T$340	.dwtag  DW_TAG_union_type
	.dwattr $C$DW$T$340, DW_AT_byte_size(0x04)
$C$DW$667	.dwtag  DW_TAG_member
	.dwattr $C$DW$667, DW_AT_type(*$C$DW$T$335)
	.dwattr $C$DW$667, DW_AT_name("dtor")
	.dwattr $C$DW$667, DW_AT_TI_symbol_name("_dtor")
	.dwattr $C$DW$667, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$667, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$668	.dwtag  DW_TAG_member
	.dwattr $C$DW$668, DW_AT_type(*$C$DW$T$211)
	.dwattr $C$DW$668, DW_AT_name("dfun")
	.dwattr $C$DW$668, DW_AT_TI_symbol_name("_dfun")
	.dwattr $C$DW$668, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$668, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$118	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$118, DW_AT_declaration
	.dwattr $C$DW$118, DW_AT_TI_symbol_name("___as__Q2_14s_rts_dtorlist4__C1FRCQ2_14s_rts_dtorlist4__C1")
	.dwattr $C$DW$118, DW_AT_type(*$C$DW$T$336)
	.dwattr $C$DW$118, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$669	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$669, DW_AT_type(*$C$DW$T$338)
	.dwendtag $C$DW$118

	.dwendtag $C$DW$T$340

$C$DW$T$336	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$336, DW_AT_type(*$C$DW$T$340)
	.dwattr $C$DW$T$336, DW_AT_address_class(0x20)

$C$DW$T$339	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$339, DW_AT_type(*$C$DW$T$336)
	.dwattr $C$DW$T$339, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$670	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$670, DW_AT_type(*$C$DW$T$338)
	.dwendtag $C$DW$T$339

$C$DW$T$337	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$337, DW_AT_type(*$C$DW$T$340)
$C$DW$T$338	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$338, DW_AT_type(*$C$DW$T$337)
	.dwattr $C$DW$T$338, DW_AT_address_class(0x20)

$C$DW$T$346	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$346, DW_AT_name("s_rts_dtorlist")
	.dwattr $C$DW$T$346, DW_AT_byte_size(0x0c)
$C$DW$671	.dwtag  DW_TAG_member
	.dwattr $C$DW$671, DW_AT_type(*$C$DW$T$341)
	.dwattr $C$DW$671, DW_AT_name("next")
	.dwattr $C$DW$671, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$671, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$671, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$672	.dwtag  DW_TAG_member
	.dwattr $C$DW$672, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$672, DW_AT_name("object")
	.dwattr $C$DW$672, DW_AT_TI_symbol_name("_object")
	.dwattr $C$DW$672, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$672, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$673	.dwtag  DW_TAG_member
	.dwattr $C$DW$673, DW_AT_type(*$C$DW$T$340)
	.dwattr $C$DW$673, DW_AT_name("fun")
	.dwattr $C$DW$673, DW_AT_TI_symbol_name("_fun")
	.dwattr $C$DW$673, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$673, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$119	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$119, DW_AT_declaration
	.dwattr $C$DW$119, DW_AT_TI_symbol_name("___as__14s_rts_dtorlistFRC14s_rts_dtorlist")
	.dwattr $C$DW$119, DW_AT_type(*$C$DW$T$342)
	.dwattr $C$DW$119, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$674	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$674, DW_AT_type(*$C$DW$T$344)
	.dwendtag $C$DW$119

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
$C$DW$675	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$675, DW_AT_type(*$C$DW$T$344)
	.dwendtag $C$DW$T$345

$C$DW$T$343	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$343, DW_AT_type(*$C$DW$T$346)
$C$DW$T$344	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$344, DW_AT_type(*$C$DW$T$343)
	.dwattr $C$DW$T$344, DW_AT_address_class(0x20)

$C$DW$T$351	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$351, DW_AT_name("timespec")
	.dwattr $C$DW$T$351, DW_AT_byte_size(0x08)
$C$DW$676	.dwtag  DW_TAG_member
	.dwattr $C$DW$676, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$676, DW_AT_name("tv_sec")
	.dwattr $C$DW$676, DW_AT_TI_symbol_name("_tv_sec")
	.dwattr $C$DW$676, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$676, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$677	.dwtag  DW_TAG_member
	.dwattr $C$DW$677, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$677, DW_AT_name("tv_nsec")
	.dwattr $C$DW$677, DW_AT_TI_symbol_name("_tv_nsec")
	.dwattr $C$DW$677, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$677, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$120	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$120, DW_AT_declaration
	.dwattr $C$DW$120, DW_AT_TI_symbol_name("___as__8timespecFRC8timespec")
	.dwattr $C$DW$120, DW_AT_type(*$C$DW$T$347)
	.dwattr $C$DW$120, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$678	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$678, DW_AT_type(*$C$DW$T$349)
	.dwendtag $C$DW$120

	.dwendtag $C$DW$T$351

$C$DW$T$347	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$347, DW_AT_type(*$C$DW$T$351)
	.dwattr $C$DW$T$347, DW_AT_address_class(0x20)

$C$DW$T$350	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$350, DW_AT_type(*$C$DW$T$347)
	.dwattr $C$DW$T$350, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$679	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$679, DW_AT_type(*$C$DW$T$349)
	.dwendtag $C$DW$T$350

$C$DW$T$348	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$348, DW_AT_type(*$C$DW$T$351)
$C$DW$T$349	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$349, DW_AT_type(*$C$DW$T$348)
	.dwattr $C$DW$T$349, DW_AT_address_class(0x20)

$C$DW$T$358	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$358, DW_AT_name("sockaddr")
	.dwattr $C$DW$T$358, DW_AT_byte_size(0x10)
$C$DW$680	.dwtag  DW_TAG_member
	.dwattr $C$DW$680, DW_AT_type(*$C$DW$T$352)
	.dwattr $C$DW$680, DW_AT_name("sa_family")
	.dwattr $C$DW$680, DW_AT_TI_symbol_name("_sa_family")
	.dwattr $C$DW$680, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$680, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$681	.dwtag  DW_TAG_member
	.dwattr $C$DW$681, DW_AT_type(*$C$DW$T$353)
	.dwattr $C$DW$681, DW_AT_name("sa_data")
	.dwattr $C$DW$681, DW_AT_TI_symbol_name("_sa_data")
	.dwattr $C$DW$681, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr $C$DW$681, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$121	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$121, DW_AT_declaration
	.dwattr $C$DW$121, DW_AT_TI_symbol_name("___as__8sockaddrFRC8sockaddr")
	.dwattr $C$DW$121, DW_AT_type(*$C$DW$T$354)
	.dwattr $C$DW$121, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$682	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$682, DW_AT_type(*$C$DW$T$356)
	.dwendtag $C$DW$121

	.dwendtag $C$DW$T$358

$C$DW$T$354	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$354, DW_AT_type(*$C$DW$T$358)
	.dwattr $C$DW$T$354, DW_AT_address_class(0x20)

$C$DW$T$357	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$357, DW_AT_type(*$C$DW$T$354)
	.dwattr $C$DW$T$357, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$683	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$683, DW_AT_type(*$C$DW$T$356)
	.dwendtag $C$DW$T$357

$C$DW$T$355	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$355, DW_AT_type(*$C$DW$T$358)
$C$DW$T$356	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$356, DW_AT_type(*$C$DW$T$355)
	.dwattr $C$DW$T$356, DW_AT_address_class(0x20)

$C$DW$T$363	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$363, DW_AT_name("in_addr")
	.dwattr $C$DW$T$363, DW_AT_byte_size(0x04)
$C$DW$684	.dwtag  DW_TAG_member
	.dwattr $C$DW$684, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$684, DW_AT_name("s_addr")
	.dwattr $C$DW$684, DW_AT_TI_symbol_name("_s_addr")
	.dwattr $C$DW$684, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$684, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$122	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$122, DW_AT_declaration
	.dwattr $C$DW$122, DW_AT_TI_symbol_name("___as__7in_addrFRC7in_addr")
	.dwattr $C$DW$122, DW_AT_type(*$C$DW$T$359)
	.dwattr $C$DW$122, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$685	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$685, DW_AT_type(*$C$DW$T$361)
	.dwendtag $C$DW$122

	.dwendtag $C$DW$T$363

$C$DW$T$359	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$359, DW_AT_type(*$C$DW$T$363)
	.dwattr $C$DW$T$359, DW_AT_address_class(0x20)

$C$DW$T$362	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$362, DW_AT_type(*$C$DW$T$359)
	.dwattr $C$DW$T$362, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$686	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$686, DW_AT_type(*$C$DW$T$361)
	.dwendtag $C$DW$T$362

$C$DW$T$360	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$360, DW_AT_type(*$C$DW$T$363)
$C$DW$T$361	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$361, DW_AT_type(*$C$DW$T$360)
	.dwattr $C$DW$T$361, DW_AT_address_class(0x20)

$C$DW$T$368	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$368, DW_AT_name("sockaddr_in")
	.dwattr $C$DW$T$368, DW_AT_byte_size(0x10)
$C$DW$687	.dwtag  DW_TAG_member
	.dwattr $C$DW$687, DW_AT_type(*$C$DW$T$352)
	.dwattr $C$DW$687, DW_AT_name("sin_family")
	.dwattr $C$DW$687, DW_AT_TI_symbol_name("_sin_family")
	.dwattr $C$DW$687, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$687, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$688	.dwtag  DW_TAG_member
	.dwattr $C$DW$688, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$688, DW_AT_name("sin_port")
	.dwattr $C$DW$688, DW_AT_TI_symbol_name("_sin_port")
	.dwattr $C$DW$688, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr $C$DW$688, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$689	.dwtag  DW_TAG_member
	.dwattr $C$DW$689, DW_AT_type(*$C$DW$T$363)
	.dwattr $C$DW$689, DW_AT_name("sin_addr")
	.dwattr $C$DW$689, DW_AT_TI_symbol_name("_sin_addr")
	.dwattr $C$DW$689, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$689, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$690	.dwtag  DW_TAG_member
	.dwattr $C$DW$690, DW_AT_type(*$C$DW$T$59)
	.dwattr $C$DW$690, DW_AT_name("pad")
	.dwattr $C$DW$690, DW_AT_TI_symbol_name("_pad")
	.dwattr $C$DW$690, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$690, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$123	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$123, DW_AT_declaration
	.dwattr $C$DW$123, DW_AT_TI_symbol_name("___as__11sockaddr_inFRC11sockaddr_in")
	.dwattr $C$DW$123, DW_AT_type(*$C$DW$T$364)
	.dwattr $C$DW$123, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$691	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$691, DW_AT_type(*$C$DW$T$366)
	.dwendtag $C$DW$123

	.dwendtag $C$DW$T$368

$C$DW$T$364	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$364, DW_AT_type(*$C$DW$T$368)
	.dwattr $C$DW$T$364, DW_AT_address_class(0x20)

$C$DW$T$367	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$367, DW_AT_type(*$C$DW$T$364)
	.dwattr $C$DW$T$367, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$692	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$692, DW_AT_type(*$C$DW$T$366)
	.dwendtag $C$DW$T$367

$C$DW$T$365	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$365, DW_AT_type(*$C$DW$T$368)
$C$DW$T$366	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$366, DW_AT_type(*$C$DW$T$365)
	.dwattr $C$DW$T$366, DW_AT_address_class(0x20)

$C$DW$T$373	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$373, DW_AT_name("route_add_parms")
	.dwattr $C$DW$T$373, DW_AT_byte_size(0x14)
$C$DW$693	.dwtag  DW_TAG_member
	.dwattr $C$DW$693, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$693, DW_AT_name("network")
	.dwattr $C$DW$693, DW_AT_TI_symbol_name("_network")
	.dwattr $C$DW$693, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$693, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$694	.dwtag  DW_TAG_member
	.dwattr $C$DW$694, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$694, DW_AT_name("mask")
	.dwattr $C$DW$694, DW_AT_TI_symbol_name("_mask")
	.dwattr $C$DW$694, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$694, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$695	.dwtag  DW_TAG_member
	.dwattr $C$DW$695, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$695, DW_AT_name("gateway")
	.dwattr $C$DW$695, DW_AT_TI_symbol_name("_gateway")
	.dwattr $C$DW$695, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$695, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$696	.dwtag  DW_TAG_member
	.dwattr $C$DW$696, DW_AT_type(*$C$DW$T$111)
	.dwattr $C$DW$696, DW_AT_name("name")
	.dwattr $C$DW$696, DW_AT_TI_symbol_name("_name")
	.dwattr $C$DW$696, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$696, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$697	.dwtag  DW_TAG_member
	.dwattr $C$DW$697, DW_AT_type(*$C$DW$T$79)
	.dwattr $C$DW$697, DW_AT_name("isdef")
	.dwattr $C$DW$697, DW_AT_TI_symbol_name("_isdef")
	.dwattr $C$DW$697, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$697, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$124	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$124, DW_AT_declaration
	.dwattr $C$DW$124, DW_AT_TI_symbol_name("___as__15route_add_parmsFRC15route_add_parms")
	.dwattr $C$DW$124, DW_AT_type(*$C$DW$T$369)
	.dwattr $C$DW$124, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$698	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$698, DW_AT_type(*$C$DW$T$371)
	.dwendtag $C$DW$124

	.dwendtag $C$DW$T$373

$C$DW$T$369	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$369, DW_AT_type(*$C$DW$T$373)
	.dwattr $C$DW$T$369, DW_AT_address_class(0x20)

$C$DW$T$372	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$372, DW_AT_type(*$C$DW$T$369)
	.dwattr $C$DW$T$372, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$699	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$699, DW_AT_type(*$C$DW$T$371)
	.dwendtag $C$DW$T$372

$C$DW$T$370	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$370, DW_AT_type(*$C$DW$T$373)
$C$DW$T$371	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$371, DW_AT_type(*$C$DW$T$370)
	.dwattr $C$DW$T$371, DW_AT_address_class(0x20)

$C$DW$T$378	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$378, DW_AT_name("change_ip_parms")
	.dwattr $C$DW$T$378, DW_AT_byte_size(0x0c)
$C$DW$700	.dwtag  DW_TAG_member
	.dwattr $C$DW$700, DW_AT_type(*$C$DW$T$111)
	.dwattr $C$DW$700, DW_AT_name("name")
	.dwattr $C$DW$700, DW_AT_TI_symbol_name("_name")
	.dwattr $C$DW$700, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$700, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$701	.dwtag  DW_TAG_member
	.dwattr $C$DW$701, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$701, DW_AT_name("new_ip")
	.dwattr $C$DW$701, DW_AT_TI_symbol_name("_new_ip")
	.dwattr $C$DW$701, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$701, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$702	.dwtag  DW_TAG_member
	.dwattr $C$DW$702, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$702, DW_AT_name("mask")
	.dwattr $C$DW$702, DW_AT_TI_symbol_name("_mask")
	.dwattr $C$DW$702, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$702, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$125	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$125, DW_AT_declaration
	.dwattr $C$DW$125, DW_AT_TI_symbol_name("___as__15change_ip_parmsFRC15change_ip_parms")
	.dwattr $C$DW$125, DW_AT_type(*$C$DW$T$374)
	.dwattr $C$DW$125, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$703	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$703, DW_AT_type(*$C$DW$T$376)
	.dwendtag $C$DW$125

	.dwendtag $C$DW$T$378

$C$DW$T$374	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$374, DW_AT_type(*$C$DW$T$378)
	.dwattr $C$DW$T$374, DW_AT_address_class(0x20)

$C$DW$T$377	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$377, DW_AT_type(*$C$DW$T$374)
	.dwattr $C$DW$T$377, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$704	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$704, DW_AT_type(*$C$DW$T$376)
	.dwendtag $C$DW$T$377

$C$DW$T$375	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$375, DW_AT_type(*$C$DW$T$378)
$C$DW$T$376	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$376, DW_AT_type(*$C$DW$T$375)
	.dwattr $C$DW$T$376, DW_AT_address_class(0x20)

$C$DW$T$383	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$383, DW_AT_name("linger")
	.dwattr $C$DW$T$383, DW_AT_byte_size(0x04)
$C$DW$705	.dwtag  DW_TAG_member
	.dwattr $C$DW$705, DW_AT_type(*$C$DW$T$22)
	.dwattr $C$DW$705, DW_AT_name("l_onoff")
	.dwattr $C$DW$705, DW_AT_TI_symbol_name("_l_onoff")
	.dwattr $C$DW$705, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$705, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$706	.dwtag  DW_TAG_member
	.dwattr $C$DW$706, DW_AT_type(*$C$DW$T$22)
	.dwattr $C$DW$706, DW_AT_name("l_linger")
	.dwattr $C$DW$706, DW_AT_TI_symbol_name("_l_linger")
	.dwattr $C$DW$706, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr $C$DW$706, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$126	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$126, DW_AT_declaration
	.dwattr $C$DW$126, DW_AT_TI_symbol_name("___as__6lingerFRC6linger")
	.dwattr $C$DW$126, DW_AT_type(*$C$DW$T$379)
	.dwattr $C$DW$126, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$707	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$707, DW_AT_type(*$C$DW$T$381)
	.dwendtag $C$DW$126

	.dwendtag $C$DW$T$383

$C$DW$T$379	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$379, DW_AT_type(*$C$DW$T$383)
	.dwattr $C$DW$T$379, DW_AT_address_class(0x20)

$C$DW$T$382	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$382, DW_AT_type(*$C$DW$T$379)
	.dwattr $C$DW$T$382, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$708	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$708, DW_AT_type(*$C$DW$T$381)
	.dwendtag $C$DW$T$382

$C$DW$T$380	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$380, DW_AT_type(*$C$DW$T$383)
$C$DW$T$381	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$381, DW_AT_type(*$C$DW$T$380)
	.dwattr $C$DW$T$381, DW_AT_address_class(0x20)

$C$DW$T$388	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$388, DW_AT_name("kdg_cmd")
	.dwattr $C$DW$T$388, DW_AT_byte_size(0x04)
$C$DW$709	.dwtag  DW_TAG_member
	.dwattr $C$DW$709, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$709, DW_AT_name("cmd")
	.dwattr $C$DW$709, DW_AT_TI_symbol_name("_cmd")
	.dwattr $C$DW$709, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$709, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$127	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$127, DW_AT_declaration
	.dwattr $C$DW$127, DW_AT_TI_symbol_name("___as__7kdg_cmdFRC7kdg_cmd")
	.dwattr $C$DW$127, DW_AT_type(*$C$DW$T$384)
	.dwattr $C$DW$127, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$710	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$710, DW_AT_type(*$C$DW$T$386)
	.dwendtag $C$DW$127

	.dwendtag $C$DW$T$388

$C$DW$T$384	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$384, DW_AT_type(*$C$DW$T$388)
	.dwattr $C$DW$T$384, DW_AT_address_class(0x20)

$C$DW$T$387	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$387, DW_AT_type(*$C$DW$T$384)
	.dwattr $C$DW$T$387, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$711	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$711, DW_AT_type(*$C$DW$T$386)
	.dwendtag $C$DW$T$387

$C$DW$T$385	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$385, DW_AT_type(*$C$DW$T$388)
$C$DW$T$386	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$386, DW_AT_type(*$C$DW$T$385)
	.dwattr $C$DW$T$386, DW_AT_address_class(0x20)

$C$DW$T$393	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$393, DW_AT_name("kdg_cmd_ask")
	.dwattr $C$DW$T$393, DW_AT_byte_size(0x08)
$C$DW$712	.dwtag  DW_TAG_member
	.dwattr $C$DW$712, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$712, DW_AT_name("cmd")
	.dwattr $C$DW$712, DW_AT_TI_symbol_name("_cmd")
	.dwattr $C$DW$712, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$712, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$713	.dwtag  DW_TAG_member
	.dwattr $C$DW$713, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$713, DW_AT_name("ask")
	.dwattr $C$DW$713, DW_AT_TI_symbol_name("_ask")
	.dwattr $C$DW$713, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$713, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$128	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$128, DW_AT_declaration
	.dwattr $C$DW$128, DW_AT_TI_symbol_name("___as__11kdg_cmd_askFRC11kdg_cmd_ask")
	.dwattr $C$DW$128, DW_AT_type(*$C$DW$T$389)
	.dwattr $C$DW$128, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$714	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$714, DW_AT_type(*$C$DW$T$391)
	.dwendtag $C$DW$128

	.dwendtag $C$DW$T$393

$C$DW$T$389	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$389, DW_AT_type(*$C$DW$T$393)
	.dwattr $C$DW$T$389, DW_AT_address_class(0x20)

$C$DW$T$392	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$392, DW_AT_type(*$C$DW$T$389)
	.dwattr $C$DW$T$392, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$715	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$715, DW_AT_type(*$C$DW$T$391)
	.dwendtag $C$DW$T$392

$C$DW$T$390	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$390, DW_AT_type(*$C$DW$T$393)
$C$DW$T$391	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$391, DW_AT_type(*$C$DW$T$390)
	.dwattr $C$DW$T$391, DW_AT_address_class(0x20)

$C$DW$T$398	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$398, DW_AT_name("kdg_rez_test")
	.dwattr $C$DW$T$398, DW_AT_byte_size(0x3c)
$C$DW$716	.dwtag  DW_TAG_member
	.dwattr $C$DW$716, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$716, DW_AT_name("cmd")
	.dwattr $C$DW$716, DW_AT_TI_symbol_name("_cmd")
	.dwattr $C$DW$716, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$716, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$717	.dwtag  DW_TAG_member
	.dwattr $C$DW$717, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$717, DW_AT_name("n_test")
	.dwattr $C$DW$717, DW_AT_TI_symbol_name("_n_test")
	.dwattr $C$DW$717, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$717, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$718	.dwtag  DW_TAG_member
	.dwattr $C$DW$718, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$718, DW_AT_name("rez")
	.dwattr $C$DW$718, DW_AT_TI_symbol_name("_rez")
	.dwattr $C$DW$718, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$718, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$719	.dwtag  DW_TAG_member
	.dwattr $C$DW$719, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$719, DW_AT_name("adrr")
	.dwattr $C$DW$719, DW_AT_TI_symbol_name("_adrr")
	.dwattr $C$DW$719, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$719, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$720	.dwtag  DW_TAG_member
	.dwattr $C$DW$720, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$720, DW_AT_name("data")
	.dwattr $C$DW$720, DW_AT_TI_symbol_name("_data")
	.dwattr $C$DW$720, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$720, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$721	.dwtag  DW_TAG_member
	.dwattr $C$DW$721, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$721, DW_AT_name("data1")
	.dwattr $C$DW$721, DW_AT_TI_symbol_name("_data1")
	.dwattr $C$DW$721, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$721, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$722	.dwtag  DW_TAG_member
	.dwattr $C$DW$722, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$722, DW_AT_name("err")
	.dwattr $C$DW$722, DW_AT_TI_symbol_name("_err")
	.dwattr $C$DW$722, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$722, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$723	.dwtag  DW_TAG_member
	.dwattr $C$DW$723, DW_AT_type(*$C$DW$T$302)
	.dwattr $C$DW$723, DW_AT_name("buf")
	.dwattr $C$DW$723, DW_AT_TI_symbol_name("_buf")
	.dwattr $C$DW$723, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr $C$DW$723, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$129	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$129, DW_AT_declaration
	.dwattr $C$DW$129, DW_AT_TI_symbol_name("___as__12kdg_rez_testFRC12kdg_rez_test")
	.dwattr $C$DW$129, DW_AT_type(*$C$DW$T$394)
	.dwattr $C$DW$129, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$724	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$724, DW_AT_type(*$C$DW$T$396)
	.dwendtag $C$DW$129

	.dwendtag $C$DW$T$398

$C$DW$T$394	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$394, DW_AT_type(*$C$DW$T$398)
	.dwattr $C$DW$T$394, DW_AT_address_class(0x20)

$C$DW$T$397	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$397, DW_AT_type(*$C$DW$T$394)
	.dwattr $C$DW$T$397, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$725	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$725, DW_AT_type(*$C$DW$T$396)
	.dwendtag $C$DW$T$397

$C$DW$T$395	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$395, DW_AT_type(*$C$DW$T$398)
$C$DW$T$396	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$396, DW_AT_type(*$C$DW$T$395)
	.dwattr $C$DW$T$396, DW_AT_address_class(0x20)

$C$DW$T$403	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$403, DW_AT_name("rez_test")
	.dwattr $C$DW$T$403, DW_AT_byte_size(0x10)
$C$DW$726	.dwtag  DW_TAG_member
	.dwattr $C$DW$726, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$726, DW_AT_name("cmd")
	.dwattr $C$DW$726, DW_AT_TI_symbol_name("_cmd")
	.dwattr $C$DW$726, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$726, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$727	.dwtag  DW_TAG_member
	.dwattr $C$DW$727, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$727, DW_AT_name("n_test")
	.dwattr $C$DW$727, DW_AT_TI_symbol_name("_n_test")
	.dwattr $C$DW$727, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$727, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$728	.dwtag  DW_TAG_member
	.dwattr $C$DW$728, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$728, DW_AT_name("rez0")
	.dwattr $C$DW$728, DW_AT_TI_symbol_name("_rez0")
	.dwattr $C$DW$728, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$728, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$729	.dwtag  DW_TAG_member
	.dwattr $C$DW$729, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$729, DW_AT_name("rez1")
	.dwattr $C$DW$729, DW_AT_TI_symbol_name("_rez1")
	.dwattr $C$DW$729, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$729, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$130	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$130, DW_AT_declaration
	.dwattr $C$DW$130, DW_AT_TI_symbol_name("___as__8rez_testFRC8rez_test")
	.dwattr $C$DW$130, DW_AT_type(*$C$DW$T$399)
	.dwattr $C$DW$130, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$730	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$730, DW_AT_type(*$C$DW$T$401)
	.dwendtag $C$DW$130

	.dwendtag $C$DW$T$403

$C$DW$T$399	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$399, DW_AT_type(*$C$DW$T$403)
	.dwattr $C$DW$T$399, DW_AT_address_class(0x20)

$C$DW$T$402	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$402, DW_AT_type(*$C$DW$T$399)
	.dwattr $C$DW$T$402, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$731	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$731, DW_AT_type(*$C$DW$T$401)
	.dwendtag $C$DW$T$402

$C$DW$T$400	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$400, DW_AT_type(*$C$DW$T$403)
$C$DW$T$401	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$401, DW_AT_type(*$C$DW$T$400)
	.dwattr $C$DW$T$401, DW_AT_address_class(0x20)

$C$DW$T$412	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$412, DW_AT_name("about_usb")
	.dwattr $C$DW$T$412, DW_AT_byte_size(0x38)
$C$DW$732	.dwtag  DW_TAG_member
	.dwattr $C$DW$732, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$732, DW_AT_name("enable")
	.dwattr $C$DW$732, DW_AT_TI_symbol_name("_enable")
	.dwattr $C$DW$732, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$732, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$733	.dwtag  DW_TAG_member
	.dwattr $C$DW$733, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$733, DW_AT_name("block_length")
	.dwattr $C$DW$733, DW_AT_TI_symbol_name("_block_length")
	.dwattr $C$DW$733, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$733, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$734	.dwtag  DW_TAG_member
	.dwattr $C$DW$734, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$734, DW_AT_name("flash_capacity")
	.dwattr $C$DW$734, DW_AT_TI_symbol_name("_flash_capacity")
	.dwattr $C$DW$734, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$734, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$735	.dwtag  DW_TAG_member
	.dwattr $C$DW$735, DW_AT_type(*$C$DW$T$404)
	.dwattr $C$DW$735, DW_AT_name("vendor_identification")
	.dwattr $C$DW$735, DW_AT_TI_symbol_name("_vendor_identification")
	.dwattr $C$DW$735, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$735, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$736	.dwtag  DW_TAG_member
	.dwattr $C$DW$736, DW_AT_type(*$C$DW$T$405)
	.dwattr $C$DW$736, DW_AT_name("product_identification")
	.dwattr $C$DW$736, DW_AT_TI_symbol_name("_product_identification")
	.dwattr $C$DW$736, DW_AT_data_member_location[DW_OP_plus_uconst 0x1a]
	.dwattr $C$DW$736, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$737	.dwtag  DW_TAG_member
	.dwattr $C$DW$737, DW_AT_type(*$C$DW$T$406)
	.dwattr $C$DW$737, DW_AT_name("product_revision_level")
	.dwattr $C$DW$737, DW_AT_TI_symbol_name("_product_revision_level")
	.dwattr $C$DW$737, DW_AT_data_member_location[DW_OP_plus_uconst 0x2b]
	.dwattr $C$DW$737, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$738	.dwtag  DW_TAG_member
	.dwattr $C$DW$738, DW_AT_type(*$C$DW$T$407)
	.dwattr $C$DW$738, DW_AT_name("fstr")
	.dwattr $C$DW$738, DW_AT_TI_symbol_name("_fstr")
	.dwattr $C$DW$738, DW_AT_data_member_location[DW_OP_plus_uconst 0x30]
	.dwattr $C$DW$738, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$131	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$131, DW_AT_declaration
	.dwattr $C$DW$131, DW_AT_TI_symbol_name("___as__9about_usbFRC9about_usb")
	.dwattr $C$DW$131, DW_AT_type(*$C$DW$T$408)
	.dwattr $C$DW$131, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$739	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$739, DW_AT_type(*$C$DW$T$410)
	.dwendtag $C$DW$131

	.dwendtag $C$DW$T$412

$C$DW$T$408	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$408, DW_AT_type(*$C$DW$T$412)
	.dwattr $C$DW$T$408, DW_AT_address_class(0x20)

$C$DW$T$411	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$411, DW_AT_type(*$C$DW$T$408)
	.dwattr $C$DW$T$411, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$740	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$740, DW_AT_type(*$C$DW$T$410)
	.dwendtag $C$DW$T$411

$C$DW$T$409	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$409, DW_AT_type(*$C$DW$T$412)
$C$DW$T$410	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$410, DW_AT_type(*$C$DW$T$409)
	.dwattr $C$DW$T$410, DW_AT_address_class(0x20)

$C$DW$T$417	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$417, DW_AT_name("comm_status")
	.dwattr $C$DW$T$417, DW_AT_byte_size(0x08)
$C$DW$741	.dwtag  DW_TAG_member
	.dwattr $C$DW$741, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$741, DW_AT_name("N")
	.dwattr $C$DW$741, DW_AT_TI_symbol_name("_N")
	.dwattr $C$DW$741, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$741, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$742	.dwtag  DW_TAG_member
	.dwattr $C$DW$742, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$742, DW_AT_name("pid")
	.dwattr $C$DW$742, DW_AT_TI_symbol_name("_pid")
	.dwattr $C$DW$742, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$742, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$132	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$132, DW_AT_declaration
	.dwattr $C$DW$132, DW_AT_TI_symbol_name("___as__11comm_statusFRC11comm_status")
	.dwattr $C$DW$132, DW_AT_type(*$C$DW$T$413)
	.dwattr $C$DW$132, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$743	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$743, DW_AT_type(*$C$DW$T$415)
	.dwendtag $C$DW$132

	.dwendtag $C$DW$T$417

$C$DW$T$413	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$413, DW_AT_type(*$C$DW$T$417)
	.dwattr $C$DW$T$413, DW_AT_address_class(0x20)

$C$DW$T$416	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$416, DW_AT_type(*$C$DW$T$413)
	.dwattr $C$DW$T$416, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$744	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$744, DW_AT_type(*$C$DW$T$415)
	.dwendtag $C$DW$T$416

$C$DW$T$414	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$414, DW_AT_type(*$C$DW$T$417)
$C$DW$T$415	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$415, DW_AT_type(*$C$DW$T$414)
	.dwattr $C$DW$T$415, DW_AT_address_class(0x20)

$C$DW$T$422	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$422, DW_AT_name("_SkEthTestRes")
	.dwattr $C$DW$T$422, DW_AT_byte_size(0x14)
$C$DW$745	.dwtag  DW_TAG_member
	.dwattr $C$DW$745, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$745, DW_AT_name("errRegDP")
	.dwattr $C$DW$745, DW_AT_TI_symbol_name("_errRegDP")
	.dwattr $C$DW$745, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$745, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$746	.dwtag  DW_TAG_member
	.dwattr $C$DW$746, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$746, DW_AT_name("errRegLX")
	.dwattr $C$DW$746, DW_AT_TI_symbol_name("_errRegLX")
	.dwattr $C$DW$746, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$746, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$747	.dwtag  DW_TAG_member
	.dwattr $C$DW$747, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$747, DW_AT_name("errSP_DP")
	.dwattr $C$DW$747, DW_AT_TI_symbol_name("_errSP_DP")
	.dwattr $C$DW$747, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$747, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$748	.dwtag  DW_TAG_member
	.dwattr $C$DW$748, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$748, DW_AT_name("errSP_LX")
	.dwattr $C$DW$748, DW_AT_TI_symbol_name("_errSP_LX")
	.dwattr $C$DW$748, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$748, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$749	.dwtag  DW_TAG_member
	.dwattr $C$DW$749, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$749, DW_AT_name("errSP_TR")
	.dwattr $C$DW$749, DW_AT_TI_symbol_name("_errSP_TR")
	.dwattr $C$DW$749, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$749, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$133	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$133, DW_AT_declaration
	.dwattr $C$DW$133, DW_AT_TI_symbol_name("___as__13_SkEthTestResFRC13_SkEthTestRes")
	.dwattr $C$DW$133, DW_AT_type(*$C$DW$T$418)
	.dwattr $C$DW$133, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$750	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$750, DW_AT_type(*$C$DW$T$420)
	.dwendtag $C$DW$133

	.dwendtag $C$DW$T$422

$C$DW$T$418	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$418, DW_AT_type(*$C$DW$T$422)
	.dwattr $C$DW$T$418, DW_AT_address_class(0x20)

$C$DW$T$421	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$421, DW_AT_type(*$C$DW$T$418)
	.dwattr $C$DW$T$421, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$751	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$751, DW_AT_type(*$C$DW$T$420)
	.dwendtag $C$DW$T$421

$C$DW$T$419	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$419, DW_AT_type(*$C$DW$T$422)
$C$DW$T$420	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$420, DW_AT_type(*$C$DW$T$419)
	.dwattr $C$DW$T$420, DW_AT_address_class(0x20)
$C$DW$T$471	.dwtag  DW_TAG_typedef, DW_AT_name("SkEthTestRes")
	.dwattr $C$DW$T$471, DW_AT_type(*$C$DW$T$422)
	.dwattr $C$DW$T$471, DW_AT_language(DW_LANG_C_plus_plus)

$C$DW$T$427	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$427, DW_AT_name("_TestDnsdRes")
	.dwattr $C$DW$T$427, DW_AT_byte_size(0x0c)
$C$DW$752	.dwtag  DW_TAG_member
	.dwattr $C$DW$752, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$752, DW_AT_name("errTimeout")
	.dwattr $C$DW$752, DW_AT_TI_symbol_name("_errTimeout")
	.dwattr $C$DW$752, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$752, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$753	.dwtag  DW_TAG_member
	.dwattr $C$DW$753, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$753, DW_AT_name("errReadC0")
	.dwattr $C$DW$753, DW_AT_TI_symbol_name("_errReadC0")
	.dwattr $C$DW$753, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$753, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$754	.dwtag  DW_TAG_member
	.dwattr $C$DW$754, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$754, DW_AT_name("errTrigger")
	.dwattr $C$DW$754, DW_AT_TI_symbol_name("_errTrigger")
	.dwattr $C$DW$754, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$754, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$134	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$134, DW_AT_declaration
	.dwattr $C$DW$134, DW_AT_TI_symbol_name("___as__12_TestDnsdResFRC12_TestDnsdRes")
	.dwattr $C$DW$134, DW_AT_type(*$C$DW$T$423)
	.dwattr $C$DW$134, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$755	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$755, DW_AT_type(*$C$DW$T$425)
	.dwendtag $C$DW$134

	.dwendtag $C$DW$T$427

$C$DW$T$423	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$423, DW_AT_type(*$C$DW$T$427)
	.dwattr $C$DW$T$423, DW_AT_address_class(0x20)

$C$DW$T$426	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$426, DW_AT_type(*$C$DW$T$423)
	.dwattr $C$DW$T$426, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$756	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$756, DW_AT_type(*$C$DW$T$425)
	.dwendtag $C$DW$T$426

$C$DW$T$424	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$424, DW_AT_type(*$C$DW$T$427)
$C$DW$T$425	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$425, DW_AT_type(*$C$DW$T$424)
	.dwattr $C$DW$T$425, DW_AT_address_class(0x20)
$C$DW$T$472	.dwtag  DW_TAG_typedef, DW_AT_name("TestDnsdRes")
	.dwattr $C$DW$T$472, DW_AT_type(*$C$DW$T$427)
	.dwattr $C$DW$T$472, DW_AT_language(DW_LANG_C_plus_plus)

$C$DW$T$432	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$432, DW_AT_name("_EthCFG")
	.dwattr $C$DW$T$432, DW_AT_byte_size(0x04)
$C$DW$757	.dwtag  DW_TAG_member
	.dwattr $C$DW$757, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$757, DW_AT_name("eth_send")
	.dwattr $C$DW$757, DW_AT_TI_symbol_name("_eth_send")
	.dwattr $C$DW$757, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$757, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$758	.dwtag  DW_TAG_member
	.dwattr $C$DW$758, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$758, DW_AT_name("eth_recv")
	.dwattr $C$DW$758, DW_AT_TI_symbol_name("_eth_recv")
	.dwattr $C$DW$758, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr $C$DW$758, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$135	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$135, DW_AT_declaration
	.dwattr $C$DW$135, DW_AT_TI_symbol_name("___as__7_EthCFGFRC7_EthCFG")
	.dwattr $C$DW$135, DW_AT_type(*$C$DW$T$428)
	.dwattr $C$DW$135, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$759	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$759, DW_AT_type(*$C$DW$T$430)
	.dwendtag $C$DW$135

	.dwendtag $C$DW$T$432

$C$DW$T$428	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$428, DW_AT_type(*$C$DW$T$432)
	.dwattr $C$DW$T$428, DW_AT_address_class(0x20)

$C$DW$T$431	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$431, DW_AT_type(*$C$DW$T$428)
	.dwattr $C$DW$T$431, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$760	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$760, DW_AT_type(*$C$DW$T$430)
	.dwendtag $C$DW$T$431

$C$DW$T$429	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$429, DW_AT_type(*$C$DW$T$432)
$C$DW$T$430	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$430, DW_AT_type(*$C$DW$T$429)
	.dwattr $C$DW$T$430, DW_AT_address_class(0x20)
$C$DW$T$473	.dwtag  DW_TAG_typedef, DW_AT_name("EthCFG")
	.dwattr $C$DW$T$473, DW_AT_type(*$C$DW$T$432)
	.dwattr $C$DW$T$473, DW_AT_language(DW_LANG_C_plus_plus)

$C$DW$T$437	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$437, DW_AT_name("_CryptErrors")
	.dwattr $C$DW$T$437, DW_AT_byte_size(0x18)
$C$DW$761	.dwtag  DW_TAG_member
	.dwattr $C$DW$761, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$761, DW_AT_name("NumPack")
	.dwattr $C$DW$761, DW_AT_TI_symbol_name("_NumPack")
	.dwattr $C$DW$761, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$761, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$762	.dwtag  DW_TAG_member
	.dwattr $C$DW$762, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$762, DW_AT_name("BodyErr")
	.dwattr $C$DW$762, DW_AT_TI_symbol_name("_BodyErr")
	.dwattr $C$DW$762, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$762, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$763	.dwtag  DW_TAG_member
	.dwattr $C$DW$763, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$763, DW_AT_name("ImvErr")
	.dwattr $C$DW$763, DW_AT_TI_symbol_name("_ImvErr")
	.dwattr $C$DW$763, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$763, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$764	.dwtag  DW_TAG_member
	.dwattr $C$DW$764, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$764, DW_AT_name("CtrBErr")
	.dwattr $C$DW$764, DW_AT_TI_symbol_name("_CtrBErr")
	.dwattr $C$DW$764, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$764, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$765	.dwtag  DW_TAG_member
	.dwattr $C$DW$765, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$765, DW_AT_name("LostPack")
	.dwattr $C$DW$765, DW_AT_TI_symbol_name("_LostPack")
	.dwattr $C$DW$765, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$765, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$766	.dwtag  DW_TAG_member
	.dwattr $C$DW$766, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$766, DW_AT_name("CMPerr")
	.dwattr $C$DW$766, DW_AT_TI_symbol_name("_CMPerr")
	.dwattr $C$DW$766, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$766, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$136	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$136, DW_AT_declaration
	.dwattr $C$DW$136, DW_AT_TI_symbol_name("___as__12_CryptErrorsFRC12_CryptErrors")
	.dwattr $C$DW$136, DW_AT_type(*$C$DW$T$433)
	.dwattr $C$DW$136, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$767	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$767, DW_AT_type(*$C$DW$T$435)
	.dwendtag $C$DW$136

	.dwendtag $C$DW$T$437

$C$DW$T$433	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$433, DW_AT_type(*$C$DW$T$437)
	.dwattr $C$DW$T$433, DW_AT_address_class(0x20)

$C$DW$T$436	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$436, DW_AT_type(*$C$DW$T$433)
	.dwattr $C$DW$T$436, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$768	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$768, DW_AT_type(*$C$DW$T$435)
	.dwendtag $C$DW$T$436

$C$DW$T$434	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$434, DW_AT_type(*$C$DW$T$437)
$C$DW$T$435	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$435, DW_AT_type(*$C$DW$T$434)
	.dwattr $C$DW$T$435, DW_AT_address_class(0x20)
$C$DW$T$474	.dwtag  DW_TAG_typedef, DW_AT_name("CryptErrors")
	.dwattr $C$DW$T$474, DW_AT_type(*$C$DW$T$437)
	.dwattr $C$DW$T$474, DW_AT_language(DW_LANG_C_plus_plus)

$C$DW$T$463	.dwtag  DW_TAG_enumeration_type
	.dwattr $C$DW$T$463, DW_AT_name("Error")
	.dwattr $C$DW$T$463, DW_AT_byte_size(0x04)
$C$DW$769	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_OK"), DW_AT_const_value(0x00)
$C$DW$770	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NO_MEMORY"), DW_AT_const_value(-1)
$C$DW$771	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NO_DEVICE"), DW_AT_const_value(-2)
$C$DW$772	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_BAD_RDESC"), DW_AT_const_value(-3)
$C$DW$773	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_BAD_PARAM"), DW_AT_const_value(-4)
$C$DW$774	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NULL_PARAM"), DW_AT_const_value(-5)
$C$DW$775	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_CANT_OPEN"), DW_AT_const_value(-6)
$C$DW$776	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_CANT_READ"), DW_AT_const_value(-7)
$C$DW$777	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_CANT_WRITE"), DW_AT_const_value(-8)
$C$DW$778	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_CANT_CREATE_HEAP"), DW_AT_const_value(-9)
$C$DW$779	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_CANT_CREATE_STACK"), DW_AT_const_value(-10)
$C$DW$780	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_MSG_ALLREADY_STARTED"), DW_AT_const_value(-11)
$C$DW$781	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_LIF_BAD_HEADER"), DW_AT_const_value(-12)
$C$DW$782	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_LIF_WRONG_TARGET_CPU"), DW_AT_const_value(-13)
$C$DW$783	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_LIF_BAD_SECTION_HEADER"), DW_AT_const_value(-14)
$C$DW$784	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_LIF_CANT_APPLY_PATCH"), DW_AT_const_value(-15)
$C$DW$785	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_TOO_LONG_STRING"), DW_AT_const_value(-16)
$C$DW$786	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_ALLREADY_NAMED"), DW_AT_const_value(-17)
$C$DW$787	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_TOO_SHORT_BUFFER"), DW_AT_const_value(-18)
$C$DW$788	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_FAIL"), DW_AT_const_value(-19)
$C$DW$789	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_CANT_CREATE_SEM"), DW_AT_const_value(-20)
$C$DW$790	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_MSG_STREAM_NOT_OPENED"), DW_AT_const_value(-21)
$C$DW$791	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_MSG_BAD_DST_ADDRESS"), DW_AT_const_value(-22)
$C$DW$792	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_VOID_RESOURCE"), DW_AT_const_value(-23)
$C$DW$793	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_SEM_DESTROYED"), DW_AT_const_value(-24)
$C$DW$794	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_SEM_NOT_REGISTERED"), DW_AT_const_value(-25)
$C$DW$795	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_TIMEOUT"), DW_AT_const_value(-26)
$C$DW$796	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_SEM_LOCKED"), DW_AT_const_value(-27)
$C$DW$797	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_SEM_UNLOCKED"), DW_AT_const_value(-28)
$C$DW$798	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NO_EXTENSION"), DW_AT_const_value(-29)
$C$DW$799	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_EXTENSION_PLUGGED"), DW_AT_const_value(-30)
$C$DW$800	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_EXTENSION_BAD_HEADER"), DW_AT_const_value(-31)
$C$DW$801	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_EXTENSION_F_PLUGGED"), DW_AT_const_value(-32)
$C$DW$802	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_CANT_CREATE_PROCESS"), DW_AT_const_value(-33)
$C$DW$803	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_BAD_DCTX"), DW_AT_const_value(-34)
$C$DW$804	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_PERMISSION_DENIED"), DW_AT_const_value(-35)
$C$DW$805	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_BAD_DATA"), DW_AT_const_value(-36)
$C$DW$806	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_ALREADY_PLUGGED"), DW_AT_const_value(-37)
$C$DW$807	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_CANT_CREATE_INTERRUPT"), DW_AT_const_value(-38)
$C$DW$808	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_SIDE_TEST_ERROR"), DW_AT_const_value(-39)
$C$DW$809	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_DATA_TEST_ERROR"), DW_AT_const_value(-40)
$C$DW$810	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_ADDRESS_TEST_ERROR"), DW_AT_const_value(-41)
$C$DW$811	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_TOO_MANY_DATA"), DW_AT_const_value(-42)
$C$DW$812	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_DIFFERENT_LENGTH"), DW_AT_const_value(-43)
$C$DW$813	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_DATA_ALIGNED"), DW_AT_const_value(-44)
$C$DW$814	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_CANT_LOCK_SEM"), DW_AT_const_value(-45)
$C$DW$815	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NO_ELEMENT"), DW_AT_const_value(-46)
$C$DW$816	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_BAD_CMD"), DW_AT_const_value(-47)
$C$DW$817	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NO_NODE"), DW_AT_const_value(-48)
$C$DW$818	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_CANT_RESET_PARAM"), DW_AT_const_value(-49)
$C$DW$819	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NO_PROCESS"), DW_AT_const_value(-50)
$C$DW$820	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_BAD_RESOURCE_TYPE"), DW_AT_const_value(-51)
$C$DW$821	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_ALREADY_ADDED"), DW_AT_const_value(-52)
$C$DW$822	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NO_ROUTE"), DW_AT_const_value(-53)
$C$DW$823	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_SYN_FAIL"), DW_AT_const_value(-54)
$C$DW$824	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NOT_ENOUGHT_DATA"), DW_AT_const_value(-55)
$C$DW$825	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_ALLREADY_SET"), DW_AT_const_value(-56)
$C$DW$826	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_DROPPED"), DW_AT_const_value(-57)
$C$DW$827	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_STREAM_OPENED"), DW_AT_const_value(-58)
$C$DW$828	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_STREAM_NOT_OPENED"), DW_AT_const_value(-59)
$C$DW$829	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NOT_INITIALIZED"), DW_AT_const_value(-60)
$C$DW$830	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_TOO_BIG_PROCESS_ID"), DW_AT_const_value(-61)
$C$DW$831	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_BAD_ACTION"), DW_AT_const_value(-62)
$C$DW$832	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_OUT_OF_A_RANGE"), DW_AT_const_value(-63)
$C$DW$833	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_SYN_TIMEOUT"), DW_AT_const_value(-64)
$C$DW$834	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_DRIVER_UNLOADED"), DW_AT_const_value(-65)
$C$DW$835	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NO_DRIVER"), DW_AT_const_value(-66)
$C$DW$836	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NODE_EXISTS"), DW_AT_const_value(-67)
$C$DW$837	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_LOOPBACK_PHY"), DW_AT_const_value(-68)
$C$DW$838	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_WRONG_QUEUE_SIZE"), DW_AT_const_value(-69)
$C$DW$839	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_RTC_WRITE"), DW_AT_const_value(-70)
$C$DW$840	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_RTC_READ"), DW_AT_const_value(-71)
$C$DW$841	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_RTC_TEST"), DW_AT_const_value(-72)
$C$DW$842	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_RTC_TICK"), DW_AT_const_value(-73)
$C$DW$843	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NO_PHY"), DW_AT_const_value(-74)
$C$DW$844	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_PHY_ERROR"), DW_AT_const_value(-75)
$C$DW$845	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_LINK_TEST"), DW_AT_const_value(-76)
$C$DW$846	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NAME_EXISTS"), DW_AT_const_value(-77)
$C$DW$847	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_BAD_NAME"), DW_AT_const_value(-78)
$C$DW$848	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_RESOURCE_BUSY"), DW_AT_const_value(-79)
$C$DW$849	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_RESOURCE_POOL_BUSY"), DW_AT_const_value(-80)
$C$DW$850	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_RESOURCE_LIMIT_REACHED"), DW_AT_const_value(-81)
$C$DW$851	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_BAD_RESOURCE_INDEX"), DW_AT_const_value(-82)
$C$DW$852	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NO_DATA"), DW_AT_const_value(-83)
	.dwendtag $C$DW$T$463


$C$DW$T$465	.dwtag  DW_TAG_enumeration_type
	.dwattr $C$DW$T$465, DW_AT_name("an_error_code")
	.dwattr $C$DW$T$465, DW_AT_byte_size(0x04)
$C$DW$853	.dwtag  DW_TAG_enumerator, DW_AT_name("ec_none"), DW_AT_const_value(0x00)
$C$DW$854	.dwtag  DW_TAG_enumerator, DW_AT_name("ec_abort_header"), DW_AT_const_value(0x01)
$C$DW$855	.dwtag  DW_TAG_enumerator, DW_AT_name("ec_terminate_called"), DW_AT_const_value(0x02)
$C$DW$856	.dwtag  DW_TAG_enumerator, DW_AT_name("ec_terminate_returned"), DW_AT_const_value(0x03)
$C$DW$857	.dwtag  DW_TAG_enumerator, DW_AT_name("ec_already_marked_for_destruction"), DW_AT_const_value(0x04)
$C$DW$858	.dwtag  DW_TAG_enumerator, DW_AT_name("ec_main_called_more_than_once"), DW_AT_const_value(0x05)
$C$DW$859	.dwtag  DW_TAG_enumerator, DW_AT_name("ec_pure_virtual_called"), DW_AT_const_value(0x06)
$C$DW$860	.dwtag  DW_TAG_enumerator, DW_AT_name("ec_bad_cast"), DW_AT_const_value(0x07)
$C$DW$861	.dwtag  DW_TAG_enumerator, DW_AT_name("ec_bad_typeid"), DW_AT_const_value(0x08)
$C$DW$862	.dwtag  DW_TAG_enumerator, DW_AT_name("ec_array_not_from_vec_new"), DW_AT_const_value(0x09)
$C$DW$863	.dwtag  DW_TAG_enumerator, DW_AT_name("ec_last"), DW_AT_const_value(0x0a)
	.dwendtag $C$DW$T$465


$C$DW$T$466	.dwtag  DW_TAG_enumeration_type
	.dwattr $C$DW$T$466, DW_AT_byte_size(0x04)
$C$DW$864	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_IP"), DW_AT_const_value(0x00)
$C$DW$865	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_ICMP"), DW_AT_const_value(0x01)
$C$DW$866	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_IGMP"), DW_AT_const_value(0x02)
$C$DW$867	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_IPIP"), DW_AT_const_value(0x04)
$C$DW$868	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_TCP"), DW_AT_const_value(0x06)
$C$DW$869	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_EGP"), DW_AT_const_value(0x08)
$C$DW$870	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_PUP"), DW_AT_const_value(0x0c)
$C$DW$871	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_UDP"), DW_AT_const_value(0x11)
$C$DW$872	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_IDP"), DW_AT_const_value(0x16)
$C$DW$873	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_DCCP"), DW_AT_const_value(0x21)
$C$DW$874	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_RSVP"), DW_AT_const_value(0x2e)
$C$DW$875	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_GRE"), DW_AT_const_value(0x2f)
$C$DW$876	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_IPV6"), DW_AT_const_value(0x29)
$C$DW$877	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_ESP"), DW_AT_const_value(0x32)
$C$DW$878	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_AH"), DW_AT_const_value(0x33)
$C$DW$879	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_BEETPH"), DW_AT_const_value(0x5e)
$C$DW$880	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_PIM"), DW_AT_const_value(0x67)
$C$DW$881	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_COMP"), DW_AT_const_value(0x6c)
$C$DW$882	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_SCTP"), DW_AT_const_value(0x84)
$C$DW$883	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_UDPLITE"), DW_AT_const_value(0x88)
$C$DW$884	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_RAW"), DW_AT_const_value(0xff)
$C$DW$885	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_MAX"), DW_AT_const_value(0x100)
	.dwendtag $C$DW$T$466


$C$DW$T$467	.dwtag  DW_TAG_enumeration_type
	.dwattr $C$DW$T$467, DW_AT_name("sock_type")
	.dwattr $C$DW$T$467, DW_AT_byte_size(0x04)
$C$DW$886	.dwtag  DW_TAG_enumerator, DW_AT_name("SOCK_STREAM"), DW_AT_const_value(0x01)
$C$DW$887	.dwtag  DW_TAG_enumerator, DW_AT_name("SOCK_DGRAM"), DW_AT_const_value(0x02)
$C$DW$888	.dwtag  DW_TAG_enumerator, DW_AT_name("SOCK_RAW"), DW_AT_const_value(0x03)
$C$DW$889	.dwtag  DW_TAG_enumerator, DW_AT_name("SOCK_RDM"), DW_AT_const_value(0x04)
$C$DW$890	.dwtag  DW_TAG_enumerator, DW_AT_name("SOCK_SEQPACKET"), DW_AT_const_value(0x05)
$C$DW$891	.dwtag  DW_TAG_enumerator, DW_AT_name("SOCK_DCCP"), DW_AT_const_value(0x06)
$C$DW$892	.dwtag  DW_TAG_enumerator, DW_AT_name("SOCK_PACKET"), DW_AT_const_value(0x0a)
	.dwendtag $C$DW$T$467


$C$DW$T$468	.dwtag  DW_TAG_enumeration_type
	.dwattr $C$DW$T$468, DW_AT_byte_size(0x04)
$C$DW$893	.dwtag  DW_TAG_enumerator, DW_AT_name("START"), DW_AT_const_value(0xd0000)
$C$DW$894	.dwtag  DW_TAG_enumerator, DW_AT_name("START_SIALP"), DW_AT_const_value(0xd0001)
$C$DW$895	.dwtag  DW_TAG_enumerator, DW_AT_name("START_CIKL"), DW_AT_const_value(0xd0002)
$C$DW$896	.dwtag  DW_TAG_enumerator, DW_AT_name("GOTOV_PP"), DW_AT_const_value(0xd0003)
$C$DW$897	.dwtag  DW_TAG_enumerator, DW_AT_name("STOP_CIKL"), DW_AT_const_value(0xd0004)
$C$DW$898	.dwtag  DW_TAG_enumerator, DW_AT_name("N_TEST"), DW_AT_const_value(0xd0005)
$C$DW$899	.dwtag  DW_TAG_enumerator, DW_AT_name("GOTOV_TEST"), DW_AT_const_value(0xd0006)
$C$DW$900	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_NOT_READY"), DW_AT_const_value(0xd0007)
$C$DW$901	.dwtag  DW_TAG_enumerator, DW_AT_name("RES_N_TEST"), DW_AT_const_value(0xd0008)
$C$DW$902	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_SDRAM_FULL"), DW_AT_const_value(0xd0009)
$C$DW$903	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_NVRAM_FULL"), DW_AT_const_value(0xd000a)
$C$DW$904	.dwtag  DW_TAG_enumerator, DW_AT_name("START_TEST_DOZU_NAGR"), DW_AT_const_value(0xd000b)
$C$DW$905	.dwtag  DW_TAG_enumerator, DW_AT_name("RES_TEST_DOZU_NAGR"), DW_AT_const_value(0xd000c)
$C$DW$906	.dwtag  DW_TAG_enumerator, DW_AT_name("STOP_TEST_DOZU_NAGR"), DW_AT_const_value(0xd000d)
$C$DW$907	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_CR_SERVISE"), DW_AT_const_value(0xd000e)
$C$DW$908	.dwtag  DW_TAG_enumerator, DW_AT_name("START_TEST_ROM"), DW_AT_const_value(0xd000f)
$C$DW$909	.dwtag  DW_TAG_enumerator, DW_AT_name("RES_TEST_ROM_CP0"), DW_AT_const_value(0xd0010)
$C$DW$910	.dwtag  DW_TAG_enumerator, DW_AT_name("RES_TEST_ROM_CP1"), DW_AT_const_value(0xd0011)
$C$DW$911	.dwtag  DW_TAG_enumerator, DW_AT_name("STOP_TEST_ROM"), DW_AT_const_value(0xd0012)
$C$DW$912	.dwtag  DW_TAG_enumerator, DW_AT_name("START_TEST_CR_CH"), DW_AT_const_value(0xd0013)
$C$DW$913	.dwtag  DW_TAG_enumerator, DW_AT_name("RES_TEST_CR_CH"), DW_AT_const_value(0xd0014)
$C$DW$914	.dwtag  DW_TAG_enumerator, DW_AT_name("STOP_TEST_CR_CH"), DW_AT_const_value(0xd0015)
$C$DW$915	.dwtag  DW_TAG_enumerator, DW_AT_name("CLEAR_TEST_PACKET"), DW_AT_const_value(0xd0016)
$C$DW$916	.dwtag  DW_TAG_enumerator, DW_AT_name("RECV_TEST_PACKET"), DW_AT_const_value(0xd0017)
$C$DW$917	.dwtag  DW_TAG_enumerator, DW_AT_name("SEND_TEST_PACKET"), DW_AT_const_value(0xd0018)
$C$DW$918	.dwtag  DW_TAG_enumerator, DW_AT_name("START_TEST_MOVE"), DW_AT_const_value(0xd0019)
$C$DW$919	.dwtag  DW_TAG_enumerator, DW_AT_name("GOTOV_TEST_MOVE_15"), DW_AT_const_value(0xd001a)
$C$DW$920	.dwtag  DW_TAG_enumerator, DW_AT_name("GOTOV_TEST_MOVE_1A"), DW_AT_const_value(0xd001b)
$C$DW$921	.dwtag  DW_TAG_enumerator, DW_AT_name("GOTOV_TEST_MOVE_25"), DW_AT_const_value(0xd001c)
$C$DW$922	.dwtag  DW_TAG_enumerator, DW_AT_name("GOTOV_TEST_MOVE_2A"), DW_AT_const_value(0xd001d)
$C$DW$923	.dwtag  DW_TAG_enumerator, DW_AT_name("RES_TEST_MOVE"), DW_AT_const_value(0xd001e)
$C$DW$924	.dwtag  DW_TAG_enumerator, DW_AT_name("STOP_TEST_MOVE"), DW_AT_const_value(0xd001f)
$C$DW$925	.dwtag  DW_TAG_enumerator, DW_AT_name("GET_RES_FROM_DOZU"), DW_AT_const_value(0xd0020)
$C$DW$926	.dwtag  DW_TAG_enumerator, DW_AT_name("INF_ABOUT_USB"), DW_AT_const_value(0xd0021)
$C$DW$927	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_IPMP"), DW_AT_const_value(0xd0022)
$C$DW$928	.dwtag  DW_TAG_enumerator, DW_AT_name("ASK_CMD"), DW_AT_const_value(0xd0023)
$C$DW$929	.dwtag  DW_TAG_enumerator, DW_AT_name("OPEN_SV_MSG"), DW_AT_const_value(0xd0024)
$C$DW$930	.dwtag  DW_TAG_enumerator, DW_AT_name("CLOSE_SV_MSG"), DW_AT_const_value(0xd0025)
$C$DW$931	.dwtag  DW_TAG_enumerator, DW_AT_name("ERROR_CMD"), DW_AT_const_value(0xd0026)
$C$DW$932	.dwtag  DW_TAG_enumerator, DW_AT_name("STOP_TX"), DW_AT_const_value(0xd0027)
$C$DW$933	.dwtag  DW_TAG_enumerator, DW_AT_name("EXIT_TPO"), DW_AT_const_value(0xd0028)
$C$DW$934	.dwtag  DW_TAG_enumerator, DW_AT_name("LOAD_LIF"), DW_AT_const_value(0xd0029)
$C$DW$935	.dwtag  DW_TAG_enumerator, DW_AT_name("START_LIF"), DW_AT_const_value(0xd002a)
$C$DW$936	.dwtag  DW_TAG_enumerator, DW_AT_name("START_LOAD_PO"), DW_AT_const_value(0xd002b)
$C$DW$937	.dwtag  DW_TAG_enumerator, DW_AT_name("WRITE_PO_TO_FLASH"), DW_AT_const_value(0xd002c)
	.dwendtag $C$DW$T$468


$C$DW$T$469	.dwtag  DW_TAG_enumeration_type
	.dwattr $C$DW$T$469, DW_AT_byte_size(0x04)
$C$DW$938	.dwtag  DW_TAG_enumerator, DW_AT_name("CELOSTN"), DW_AT_const_value(0x15)
$C$DW$939	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_SDRAM"), DW_AT_const_value(0x1a)
$C$DW$940	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_NVRAM"), DW_AT_const_value(0x1b)
$C$DW$941	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_USB_CONTR"), DW_AT_const_value(0x1d)
$C$DW$942	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_USB_FLASH"), DW_AT_const_value(0x1e)
$C$DW$943	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_DOZU"), DW_AT_const_value(0x20)
$C$DW$944	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_DOZU_ST1"), DW_AT_const_value(0x21)
$C$DW$945	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_DOZU_ST2"), DW_AT_const_value(0x22)
$C$DW$946	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_DOZU_ST3"), DW_AT_const_value(0x23)
$C$DW$947	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_MOVE"), DW_AT_const_value(0x24)
$C$DW$948	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_MOVE_ST1"), DW_AT_const_value(0x25)
$C$DW$949	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_MOVE_ST2"), DW_AT_const_value(0x26)
$C$DW$950	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_MOVE_ST3"), DW_AT_const_value(0x27)
$C$DW$951	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_SK"), DW_AT_const_value(0x28)
$C$DW$952	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_SK1"), DW_AT_const_value(0x29)
$C$DW$953	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_SK2"), DW_AT_const_value(0x2a)
$C$DW$954	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_SK3"), DW_AT_const_value(0x2b)
$C$DW$955	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_DNSD_CRC"), DW_AT_const_value(0x2c)
$C$DW$956	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_DNSD_VD10"), DW_AT_const_value(0x2d)
$C$DW$957	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_DNSD_VD11"), DW_AT_const_value(0x2e)
$C$DW$958	.dwtag  DW_TAG_enumerator, DW_AT_name("ZAVESTI_DNSD"), DW_AT_const_value(0x2f)
$C$DW$959	.dwtag  DW_TAG_enumerator, DW_AT_name("PROCHITAT"), DW_AT_const_value(0x30)
$C$DW$960	.dwtag  DW_TAG_enumerator, DW_AT_name("VKL_VD10"), DW_AT_const_value(0x31)
$C$DW$961	.dwtag  DW_TAG_enumerator, DW_AT_name("VKL_VD11"), DW_AT_const_value(0x32)
$C$DW$962	.dwtag  DW_TAG_enumerator, DW_AT_name("VIKL_VD11"), DW_AT_const_value(0x33)
$C$DW$963	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_DNSD_OSVESCH"), DW_AT_const_value(0x34)
$C$DW$964	.dwtag  DW_TAG_enumerator, DW_AT_name("MAGIC_NUMBER"), DW_AT_const_value(0x35)
$C$DW$965	.dwtag  DW_TAG_enumerator, DW_AT_name("CELOSTN_PP056"), DW_AT_const_value(0x36)
$C$DW$966	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_CDROM"), DW_AT_const_value(0x37)
$C$DW$967	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_RAID"), DW_AT_const_value(0x38)
$C$DW$968	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_USB3"), DW_AT_const_value(0x39)
$C$DW$969	.dwtag  DW_TAG_enumerator, DW_AT_name("CIKL"), DW_AT_const_value(0x64)
$C$DW$970	.dwtag  DW_TAG_enumerator, DW_AT_name("CIKL_NOT_READY"), DW_AT_const_value(0x65)
	.dwendtag $C$DW$T$469


$C$DW$T$470	.dwtag  DW_TAG_enumeration_type
	.dwattr $C$DW$T$470, DW_AT_byte_size(0x04)
$C$DW$971	.dwtag  DW_TAG_enumerator, DW_AT_name("MAIN_TIME_OUT"), DW_AT_const_value(0x00)
$C$DW$972	.dwtag  DW_TAG_enumerator, DW_AT_name("COMM_TIME_OUT"), DW_AT_const_value(0x01)
$C$DW$973	.dwtag  DW_TAG_enumerator, DW_AT_name("COMM1_TIME_OUT"), DW_AT_const_value(0x02)
$C$DW$974	.dwtag  DW_TAG_enumerator, DW_AT_name("COMM2_TIME_OUT"), DW_AT_const_value(0x03)
$C$DW$975	.dwtag  DW_TAG_enumerator, DW_AT_name("COMM3_TIME_OUT"), DW_AT_const_value(0x04)
$C$DW$976	.dwtag  DW_TAG_enumerator, DW_AT_name("MAIN_ERR_MSG"), DW_AT_const_value(0x05)
$C$DW$977	.dwtag  DW_TAG_enumerator, DW_AT_name("MAIN_ERR_MSG_CICL_RES"), DW_AT_const_value(0x06)
$C$DW$978	.dwtag  DW_TAG_enumerator, DW_AT_name("COMM_ERR_MSG"), DW_AT_const_value(0x07)
$C$DW$979	.dwtag  DW_TAG_enumerator, DW_AT_name("COMM1_ERR_MSG"), DW_AT_const_value(0x08)
$C$DW$980	.dwtag  DW_TAG_enumerator, DW_AT_name("COMM2_ERR_MSG"), DW_AT_const_value(0x09)
$C$DW$981	.dwtag  DW_TAG_enumerator, DW_AT_name("COMM3_ERR_MSG"), DW_AT_const_value(0x0a)
$C$DW$982	.dwtag  DW_TAG_enumerator, DW_AT_name("DRV_ERR"), DW_AT_const_value(0x0b)
$C$DW$983	.dwtag  DW_TAG_enumerator, DW_AT_name("ERR_MSG_OPEN"), DW_AT_const_value(0x0c)
$C$DW$984	.dwtag  DW_TAG_enumerator, DW_AT_name("NO_MEM_COMM"), DW_AT_const_value(0x0d)
$C$DW$985	.dwtag  DW_TAG_enumerator, DW_AT_name("NO_MEM_COMM1"), DW_AT_const_value(0x0e)
$C$DW$986	.dwtag  DW_TAG_enumerator, DW_AT_name("NO_MEM_MAIN"), DW_AT_const_value(0x0f)
$C$DW$987	.dwtag  DW_TAG_enumerator, DW_AT_name("NO_MEM_IFACE"), DW_AT_const_value(0x10)
	.dwendtag $C$DW$T$470

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

$C$DW$988	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A0")
	.dwattr $C$DW$988, DW_AT_location[DW_OP_reg0]
$C$DW$989	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A1")
	.dwattr $C$DW$989, DW_AT_location[DW_OP_reg1]
$C$DW$990	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A2")
	.dwattr $C$DW$990, DW_AT_location[DW_OP_reg2]
$C$DW$991	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A3")
	.dwattr $C$DW$991, DW_AT_location[DW_OP_reg3]
$C$DW$992	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A4")
	.dwattr $C$DW$992, DW_AT_location[DW_OP_reg4]
$C$DW$993	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A5")
	.dwattr $C$DW$993, DW_AT_location[DW_OP_reg5]
$C$DW$994	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A6")
	.dwattr $C$DW$994, DW_AT_location[DW_OP_reg6]
$C$DW$995	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A7")
	.dwattr $C$DW$995, DW_AT_location[DW_OP_reg7]
$C$DW$996	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A8")
	.dwattr $C$DW$996, DW_AT_location[DW_OP_reg8]
$C$DW$997	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A9")
	.dwattr $C$DW$997, DW_AT_location[DW_OP_reg9]
$C$DW$998	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A10")
	.dwattr $C$DW$998, DW_AT_location[DW_OP_reg10]
$C$DW$999	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A11")
	.dwattr $C$DW$999, DW_AT_location[DW_OP_reg11]
$C$DW$1000	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A12")
	.dwattr $C$DW$1000, DW_AT_location[DW_OP_reg12]
$C$DW$1001	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A13")
	.dwattr $C$DW$1001, DW_AT_location[DW_OP_reg13]
$C$DW$1002	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A14")
	.dwattr $C$DW$1002, DW_AT_location[DW_OP_reg14]
$C$DW$1003	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A15")
	.dwattr $C$DW$1003, DW_AT_location[DW_OP_reg15]
$C$DW$1004	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B0")
	.dwattr $C$DW$1004, DW_AT_location[DW_OP_reg16]
$C$DW$1005	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B1")
	.dwattr $C$DW$1005, DW_AT_location[DW_OP_reg17]
$C$DW$1006	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B2")
	.dwattr $C$DW$1006, DW_AT_location[DW_OP_reg18]
$C$DW$1007	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B3")
	.dwattr $C$DW$1007, DW_AT_location[DW_OP_reg19]
$C$DW$1008	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B4")
	.dwattr $C$DW$1008, DW_AT_location[DW_OP_reg20]
$C$DW$1009	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B5")
	.dwattr $C$DW$1009, DW_AT_location[DW_OP_reg21]
$C$DW$1010	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B6")
	.dwattr $C$DW$1010, DW_AT_location[DW_OP_reg22]
$C$DW$1011	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B7")
	.dwattr $C$DW$1011, DW_AT_location[DW_OP_reg23]
$C$DW$1012	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B8")
	.dwattr $C$DW$1012, DW_AT_location[DW_OP_reg24]
$C$DW$1013	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B9")
	.dwattr $C$DW$1013, DW_AT_location[DW_OP_reg25]
$C$DW$1014	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B10")
	.dwattr $C$DW$1014, DW_AT_location[DW_OP_reg26]
$C$DW$1015	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B11")
	.dwattr $C$DW$1015, DW_AT_location[DW_OP_reg27]
$C$DW$1016	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B12")
	.dwattr $C$DW$1016, DW_AT_location[DW_OP_reg28]
$C$DW$1017	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B13")
	.dwattr $C$DW$1017, DW_AT_location[DW_OP_reg29]
$C$DW$1018	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("DP")
	.dwattr $C$DW$1018, DW_AT_location[DW_OP_reg30]
$C$DW$1019	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("SP")
	.dwattr $C$DW$1019, DW_AT_location[DW_OP_reg31]
$C$DW$1020	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("FP")
	.dwattr $C$DW$1020, DW_AT_location[DW_OP_regx 0x20]
$C$DW$1021	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("PC")
	.dwattr $C$DW$1021, DW_AT_location[DW_OP_regx 0x21]
$C$DW$1022	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("IRP")
	.dwattr $C$DW$1022, DW_AT_location[DW_OP_regx 0x22]
$C$DW$1023	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("IFR")
	.dwattr $C$DW$1023, DW_AT_location[DW_OP_regx 0x23]
$C$DW$1024	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("NRP")
	.dwattr $C$DW$1024, DW_AT_location[DW_OP_regx 0x24]
$C$DW$1025	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A16")
	.dwattr $C$DW$1025, DW_AT_location[DW_OP_regx 0x25]
$C$DW$1026	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A17")
	.dwattr $C$DW$1026, DW_AT_location[DW_OP_regx 0x26]
$C$DW$1027	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A18")
	.dwattr $C$DW$1027, DW_AT_location[DW_OP_regx 0x27]
$C$DW$1028	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A19")
	.dwattr $C$DW$1028, DW_AT_location[DW_OP_regx 0x28]
$C$DW$1029	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A20")
	.dwattr $C$DW$1029, DW_AT_location[DW_OP_regx 0x29]
$C$DW$1030	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A21")
	.dwattr $C$DW$1030, DW_AT_location[DW_OP_regx 0x2a]
$C$DW$1031	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A22")
	.dwattr $C$DW$1031, DW_AT_location[DW_OP_regx 0x2b]
$C$DW$1032	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A23")
	.dwattr $C$DW$1032, DW_AT_location[DW_OP_regx 0x2c]
$C$DW$1033	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A24")
	.dwattr $C$DW$1033, DW_AT_location[DW_OP_regx 0x2d]
$C$DW$1034	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A25")
	.dwattr $C$DW$1034, DW_AT_location[DW_OP_regx 0x2e]
$C$DW$1035	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A26")
	.dwattr $C$DW$1035, DW_AT_location[DW_OP_regx 0x2f]
$C$DW$1036	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A27")
	.dwattr $C$DW$1036, DW_AT_location[DW_OP_regx 0x30]
$C$DW$1037	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A28")
	.dwattr $C$DW$1037, DW_AT_location[DW_OP_regx 0x31]
$C$DW$1038	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A29")
	.dwattr $C$DW$1038, DW_AT_location[DW_OP_regx 0x32]
$C$DW$1039	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A30")
	.dwattr $C$DW$1039, DW_AT_location[DW_OP_regx 0x33]
$C$DW$1040	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A31")
	.dwattr $C$DW$1040, DW_AT_location[DW_OP_regx 0x34]
$C$DW$1041	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B16")
	.dwattr $C$DW$1041, DW_AT_location[DW_OP_regx 0x35]
$C$DW$1042	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B17")
	.dwattr $C$DW$1042, DW_AT_location[DW_OP_regx 0x36]
$C$DW$1043	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B18")
	.dwattr $C$DW$1043, DW_AT_location[DW_OP_regx 0x37]
$C$DW$1044	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B19")
	.dwattr $C$DW$1044, DW_AT_location[DW_OP_regx 0x38]
$C$DW$1045	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B20")
	.dwattr $C$DW$1045, DW_AT_location[DW_OP_regx 0x39]
$C$DW$1046	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B21")
	.dwattr $C$DW$1046, DW_AT_location[DW_OP_regx 0x3a]
$C$DW$1047	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B22")
	.dwattr $C$DW$1047, DW_AT_location[DW_OP_regx 0x3b]
$C$DW$1048	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B23")
	.dwattr $C$DW$1048, DW_AT_location[DW_OP_regx 0x3c]
$C$DW$1049	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B24")
	.dwattr $C$DW$1049, DW_AT_location[DW_OP_regx 0x3d]
$C$DW$1050	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B25")
	.dwattr $C$DW$1050, DW_AT_location[DW_OP_regx 0x3e]
$C$DW$1051	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B26")
	.dwattr $C$DW$1051, DW_AT_location[DW_OP_regx 0x3f]
$C$DW$1052	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B27")
	.dwattr $C$DW$1052, DW_AT_location[DW_OP_regx 0x40]
$C$DW$1053	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B28")
	.dwattr $C$DW$1053, DW_AT_location[DW_OP_regx 0x41]
$C$DW$1054	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B29")
	.dwattr $C$DW$1054, DW_AT_location[DW_OP_regx 0x42]
$C$DW$1055	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B30")
	.dwattr $C$DW$1055, DW_AT_location[DW_OP_regx 0x43]
$C$DW$1056	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B31")
	.dwattr $C$DW$1056, DW_AT_location[DW_OP_regx 0x44]
$C$DW$1057	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AMR")
	.dwattr $C$DW$1057, DW_AT_location[DW_OP_regx 0x45]
$C$DW$1058	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("CSR")
	.dwattr $C$DW$1058, DW_AT_location[DW_OP_regx 0x46]
$C$DW$1059	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ISR")
	.dwattr $C$DW$1059, DW_AT_location[DW_OP_regx 0x47]
$C$DW$1060	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ICR")
	.dwattr $C$DW$1060, DW_AT_location[DW_OP_regx 0x48]
$C$DW$1061	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("IER")
	.dwattr $C$DW$1061, DW_AT_location[DW_OP_regx 0x49]
$C$DW$1062	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ISTP")
	.dwattr $C$DW$1062, DW_AT_location[DW_OP_regx 0x4a]
$C$DW$1063	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("IN")
	.dwattr $C$DW$1063, DW_AT_location[DW_OP_regx 0x4b]
$C$DW$1064	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("OUT")
	.dwattr $C$DW$1064, DW_AT_location[DW_OP_regx 0x4c]
$C$DW$1065	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ACR")
	.dwattr $C$DW$1065, DW_AT_location[DW_OP_regx 0x4d]
$C$DW$1066	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ADR")
	.dwattr $C$DW$1066, DW_AT_location[DW_OP_regx 0x4e]
$C$DW$1067	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("FADCR")
	.dwattr $C$DW$1067, DW_AT_location[DW_OP_regx 0x4f]
$C$DW$1068	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("FAUCR")
	.dwattr $C$DW$1068, DW_AT_location[DW_OP_regx 0x50]
$C$DW$1069	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("FMCR")
	.dwattr $C$DW$1069, DW_AT_location[DW_OP_regx 0x51]
$C$DW$1070	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("GFPGFR")
	.dwattr $C$DW$1070, DW_AT_location[DW_OP_regx 0x52]
$C$DW$1071	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("DIER")
	.dwattr $C$DW$1071, DW_AT_location[DW_OP_regx 0x53]
$C$DW$1072	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("REP")
	.dwattr $C$DW$1072, DW_AT_location[DW_OP_regx 0x54]
$C$DW$1073	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("TSCL")
	.dwattr $C$DW$1073, DW_AT_location[DW_OP_regx 0x55]
$C$DW$1074	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("TSCH")
	.dwattr $C$DW$1074, DW_AT_location[DW_OP_regx 0x56]
$C$DW$1075	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ARP")
	.dwattr $C$DW$1075, DW_AT_location[DW_OP_regx 0x57]
$C$DW$1076	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ILC")
	.dwattr $C$DW$1076, DW_AT_location[DW_OP_regx 0x58]
$C$DW$1077	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("RILC")
	.dwattr $C$DW$1077, DW_AT_location[DW_OP_regx 0x59]
$C$DW$1078	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("DNUM")
	.dwattr $C$DW$1078, DW_AT_location[DW_OP_regx 0x5a]
$C$DW$1079	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("SSR")
	.dwattr $C$DW$1079, DW_AT_location[DW_OP_regx 0x5b]
$C$DW$1080	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("GPLYA")
	.dwattr $C$DW$1080, DW_AT_location[DW_OP_regx 0x5c]
$C$DW$1081	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("GPLYB")
	.dwattr $C$DW$1081, DW_AT_location[DW_OP_regx 0x5d]
$C$DW$1082	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("TSR")
	.dwattr $C$DW$1082, DW_AT_location[DW_OP_regx 0x5e]
$C$DW$1083	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ITSR")
	.dwattr $C$DW$1083, DW_AT_location[DW_OP_regx 0x5f]
$C$DW$1084	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("NTSR")
	.dwattr $C$DW$1084, DW_AT_location[DW_OP_regx 0x60]
$C$DW$1085	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("EFR")
	.dwattr $C$DW$1085, DW_AT_location[DW_OP_regx 0x61]
$C$DW$1086	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ECR")
	.dwattr $C$DW$1086, DW_AT_location[DW_OP_regx 0x62]
$C$DW$1087	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("IERR")
	.dwattr $C$DW$1087, DW_AT_location[DW_OP_regx 0x63]
$C$DW$1088	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("DMSG")
	.dwattr $C$DW$1088, DW_AT_location[DW_OP_regx 0x64]
$C$DW$1089	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("CMSG")
	.dwattr $C$DW$1089, DW_AT_location[DW_OP_regx 0x65]
$C$DW$1090	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("DT_DMA_ADDR")
	.dwattr $C$DW$1090, DW_AT_location[DW_OP_regx 0x66]
$C$DW$1091	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("DT_DMA_DATA")
	.dwattr $C$DW$1091, DW_AT_location[DW_OP_regx 0x67]
$C$DW$1092	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("DT_DMA_CNTL")
	.dwattr $C$DW$1092, DW_AT_location[DW_OP_regx 0x68]
$C$DW$1093	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("TCU_CNTL")
	.dwattr $C$DW$1093, DW_AT_location[DW_OP_regx 0x69]
$C$DW$1094	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("RTDX_REC_CNTL")
	.dwattr $C$DW$1094, DW_AT_location[DW_OP_regx 0x6a]
$C$DW$1095	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("RTDX_XMT_CNTL")
	.dwattr $C$DW$1095, DW_AT_location[DW_OP_regx 0x6b]
$C$DW$1096	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("RTDX_CFG")
	.dwattr $C$DW$1096, DW_AT_location[DW_OP_regx 0x6c]
$C$DW$1097	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("RTDX_RDATA")
	.dwattr $C$DW$1097, DW_AT_location[DW_OP_regx 0x6d]
$C$DW$1098	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("RTDX_WDATA")
	.dwattr $C$DW$1098, DW_AT_location[DW_OP_regx 0x6e]
$C$DW$1099	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("RTDX_RADDR")
	.dwattr $C$DW$1099, DW_AT_location[DW_OP_regx 0x6f]
$C$DW$1100	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("RTDX_WADDR")
	.dwattr $C$DW$1100, DW_AT_location[DW_OP_regx 0x70]
$C$DW$1101	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("MFREG0")
	.dwattr $C$DW$1101, DW_AT_location[DW_OP_regx 0x71]
$C$DW$1102	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("DBG_STAT")
	.dwattr $C$DW$1102, DW_AT_location[DW_OP_regx 0x72]
$C$DW$1103	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("BRK_EN")
	.dwattr $C$DW$1103, DW_AT_location[DW_OP_regx 0x73]
$C$DW$1104	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("HWBP0_CNT")
	.dwattr $C$DW$1104, DW_AT_location[DW_OP_regx 0x74]
$C$DW$1105	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("HWBP0")
	.dwattr $C$DW$1105, DW_AT_location[DW_OP_regx 0x75]
$C$DW$1106	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("HWBP1")
	.dwattr $C$DW$1106, DW_AT_location[DW_OP_regx 0x76]
$C$DW$1107	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("HWBP2")
	.dwattr $C$DW$1107, DW_AT_location[DW_OP_regx 0x77]
$C$DW$1108	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("HWBP3")
	.dwattr $C$DW$1108, DW_AT_location[DW_OP_regx 0x78]
$C$DW$1109	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("OVERLAY")
	.dwattr $C$DW$1109, DW_AT_location[DW_OP_regx 0x79]
$C$DW$1110	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("PC_PROF")
	.dwattr $C$DW$1110, DW_AT_location[DW_OP_regx 0x7a]
$C$DW$1111	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ATSR")
	.dwattr $C$DW$1111, DW_AT_location[DW_OP_regx 0x7b]
$C$DW$1112	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("TRR")
	.dwattr $C$DW$1112, DW_AT_location[DW_OP_regx 0x7c]
$C$DW$1113	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("TCRR")
	.dwattr $C$DW$1113, DW_AT_location[DW_OP_regx 0x7d]
$C$DW$1114	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("DESR")
	.dwattr $C$DW$1114, DW_AT_location[DW_OP_regx 0x7e]
$C$DW$1115	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("DETR")
	.dwattr $C$DW$1115, DW_AT_location[DW_OP_regx 0x7f]
$C$DW$1116	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("CIE_RETA")
	.dwattr $C$DW$1116, DW_AT_location[DW_OP_regx 0xe4]
	.dwendtag $C$DW$CU

