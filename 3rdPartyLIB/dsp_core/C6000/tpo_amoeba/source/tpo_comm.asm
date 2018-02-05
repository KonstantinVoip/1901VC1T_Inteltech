;******************************************************************************
;* TMS320C6x C/C++ Codegen                                         PC v6.1.22 *
;* Date/Time created: Mon Feb 05 10:17:20 2018                                *
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
	.dwattr $C$DW$CU, DW_AT_name("tpo_comm.cpp")
	.dwattr $C$DW$CU, DW_AT_producer("TMS320C6x C/C++ Codegen PC v6.1.22 Copyright (c) 1996-2012 Texas Instruments Incorporated")
	.dwattr $C$DW$CU, DW_AT_TI_version(0x01)
	.dwattr $C$DW$CU, DW_AT_comp_dir("C:\1901VC1T_Inteltech\3rdPartyLIB\dsp_core\C6000\tpo_amoeba\source")
;*****************************************************************************
;* CINIT RECORDS                                                             *
;*****************************************************************************
	.sect	".cinit"
	.align	8
	.field  	$C$IR_1,32
	.field  	_hwindow+0,32
	.field  	0,32			; _hwindow[0]._start_addr @ 0
	.field  	3604479,32			; _hwindow[0]._end_addr @ 32
	.field  	4128768,32			; _hwindow[1]._start_addr @ 64
	.field  	4194239,32			; _hwindow[1]._end_addr @ 96
	.field  	0,32			; _hwindow[2]._start_addr @ 128
	.field  	0,32			; _hwindow[2]._end_addr @ 160
$C$IR_1:	.set	24

	.sect	".cinit"
	.align	8
	.field  	4,32
	.field  	_sv_msg_open+0,32
	.field  	0,32			; _sv_msg_open @ 0

	.sect	".cinit"
	.align	8
	.field  	4,32
	.field  	_read_res_fifo+0,32
	.field  	0,32			; _read_res_fifo @ 0

	.sect	".cinit"
	.align	8
	.field  	4,32
	.field  	_sh_mem_write+0,32
	.field  	-2147483648,32			; _sh_mem_write @ 0

	.sect	".cinit"
	.align	8
	.field  	4,32
	.field  	_sh_mem_read_proc+0,32
	.field  	-1610612736,32			; _sh_mem_read_proc @ 0

	.sect	".cinit"
	.align	8
	.field  	4,32
	.field  	_sh_mem_read_crypt+0,32
	.field  	-1610608640,32			; _sh_mem_read_crypt @ 0

	.sect	".cinit"
	.align	8
	.field  	4,32
	.field  	_sh_mem_read_proc2+0,32
	.field  	-1342177280,32			; _sh_mem_read_proc2 @ 0

	.sect	".cinit"
	.align	8
	.field  	4,32
	.field  	_sh_mem_read_crypt2+0,32
	.field  	-1342173184,32			; _sh_mem_read_crypt2 @ 0

	.sect	".cinit"
	.align	8
	.field  	2,32
	.field  	_Start_dozu_nagr+0,32
	.field  	0,16			; _Start_dozu_nagr @ 0


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


$C$DW$173	.dwtag  DW_TAG_subprogram, DW_AT_name("memset")
	.dwattr $C$DW$173, DW_AT_TI_symbol_name("_memset")
	.dwattr $C$DW$173, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$173, DW_AT_declaration
	.dwattr $C$DW$173, DW_AT_external
$C$DW$174	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$174, DW_AT_type(*$C$DW$T$3)
$C$DW$175	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$175, DW_AT_type(*$C$DW$T$10)
$C$DW$176	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$176, DW_AT_type(*$C$DW$T$662)
	.dwendtag $C$DW$173


$C$DW$177	.dwtag  DW_TAG_subprogram, DW_AT_name("memcmp")
	.dwattr $C$DW$177, DW_AT_TI_symbol_name("_memcmp")
	.dwattr $C$DW$177, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$177, DW_AT_declaration
	.dwattr $C$DW$177, DW_AT_external
$C$DW$178	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$178, DW_AT_type(*$C$DW$T$94)
$C$DW$179	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$179, DW_AT_type(*$C$DW$T$94)
$C$DW$180	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$180, DW_AT_type(*$C$DW$T$662)
	.dwendtag $C$DW$177


$C$DW$181	.dwtag  DW_TAG_subprogram, DW_AT_name("Sv_Msg")
	.dwattr $C$DW$181, DW_AT_TI_symbol_name("_Sv_Msg__FPv")
	.dwattr $C$DW$181, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$181, DW_AT_declaration
	.dwattr $C$DW$181, DW_AT_external
$C$DW$182	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$182, DW_AT_type(*$C$DW$T$3)
	.dwendtag $C$DW$181


$C$DW$183	.dwtag  DW_TAG_subprogram, DW_AT_name("TestDOZU_Nagr")
	.dwattr $C$DW$183, DW_AT_TI_symbol_name("_TestDOZU_Nagr__FPv")
	.dwattr $C$DW$183, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$183, DW_AT_declaration
	.dwattr $C$DW$183, DW_AT_external
$C$DW$184	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$184, DW_AT_type(*$C$DW$T$3)
	.dwendtag $C$DW$183


$C$DW$185	.dwtag  DW_TAG_subprogram, DW_AT_name("Start_Test_N")
	.dwattr $C$DW$185, DW_AT_TI_symbol_name("_Start_Test_N__FP12kdg_rez_test")
	.dwattr $C$DW$185, DW_AT_declaration
	.dwattr $C$DW$185, DW_AT_external
$C$DW$186	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$186, DW_AT_type(*$C$DW$T$672)
	.dwendtag $C$DW$185


$C$DW$187	.dwtag  DW_TAG_subprogram, DW_AT_name("Test_sialp")
	.dwattr $C$DW$187, DW_AT_TI_symbol_name("_Test_sialp__Fv")
	.dwattr $C$DW$187, DW_AT_declaration
	.dwattr $C$DW$187, DW_AT_external

$C$DW$188	.dwtag  DW_TAG_subprogram, DW_AT_name("si_stop_tx")
	.dwattr $C$DW$188, DW_AT_TI_symbol_name("_si_stop_tx__Fi")
	.dwattr $C$DW$188, DW_AT_declaration
	.dwattr $C$DW$188, DW_AT_external
$C$DW$189	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$189, DW_AT_type(*$C$DW$T$10)
	.dwendtag $C$DW$188


$C$DW$190	.dwtag  DW_TAG_subprogram, DW_AT_name("ReadDARAM0")
	.dwattr $C$DW$190, DW_AT_TI_symbol_name("_ReadDARAM0__FUsPvT1")
	.dwattr $C$DW$190, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$190, DW_AT_declaration
	.dwattr $C$DW$190, DW_AT_external
$C$DW$191	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$191, DW_AT_type(*$C$DW$T$28)
$C$DW$192	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$192, DW_AT_type(*$C$DW$T$3)
$C$DW$193	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$193, DW_AT_type(*$C$DW$T$28)
	.dwendtag $C$DW$190


$C$DW$194	.dwtag  DW_TAG_subprogram, DW_AT_name("ReadDARAM1")
	.dwattr $C$DW$194, DW_AT_TI_symbol_name("_ReadDARAM1__FUsPvT1")
	.dwattr $C$DW$194, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$194, DW_AT_declaration
	.dwattr $C$DW$194, DW_AT_external
$C$DW$195	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$195, DW_AT_type(*$C$DW$T$28)
$C$DW$196	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$196, DW_AT_type(*$C$DW$T$3)
$C$DW$197	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$197, DW_AT_type(*$C$DW$T$28)
	.dwendtag $C$DW$194


$C$DW$198	.dwtag  DW_TAG_subprogram, DW_AT_name("WriteDARAM")
	.dwattr $C$DW$198, DW_AT_TI_symbol_name("_WriteDARAM__FUsPvT1")
	.dwattr $C$DW$198, DW_AT_declaration
	.dwattr $C$DW$198, DW_AT_external
$C$DW$199	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$199, DW_AT_type(*$C$DW$T$28)
$C$DW$200	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$200, DW_AT_type(*$C$DW$T$3)
$C$DW$201	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$201, DW_AT_type(*$C$DW$T$28)
	.dwendtag $C$DW$198


$C$DW$202	.dwtag  DW_TAG_subprogram, DW_AT_name("load_lif")
	.dwattr $C$DW$202, DW_AT_TI_symbol_name("_load_lif__FPv")
	.dwattr $C$DW$202, DW_AT_declaration
	.dwattr $C$DW$202, DW_AT_external
$C$DW$203	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$203, DW_AT_type(*$C$DW$T$3)
	.dwendtag $C$DW$202


$C$DW$204	.dwtag  DW_TAG_subprogram, DW_AT_name("Load_lif_from_usb")
	.dwattr $C$DW$204, DW_AT_TI_symbol_name("_Load_lif_from_usb__Fv")
	.dwattr $C$DW$204, DW_AT_declaration
	.dwattr $C$DW$204, DW_AT_external
$C$DW$205	.dwtag  DW_TAG_variable, DW_AT_name("__syscall_tab")
	.dwattr $C$DW$205, DW_AT_TI_symbol_name("___syscall_tab")
	.dwattr $C$DW$205, DW_AT_type(*$C$DW$T$660)
	.dwattr $C$DW$205, DW_AT_declaration
	.dwattr $C$DW$205, DW_AT_external
	.global	_hwindow
_hwindow:	.usect	".far",24,8
$C$DW$206	.dwtag  DW_TAG_variable, DW_AT_name("hwindow")
	.dwattr $C$DW$206, DW_AT_TI_symbol_name("_hwindow")
	.dwattr $C$DW$206, DW_AT_location[DW_OP_addr _hwindow]
	.dwattr $C$DW$206, DW_AT_type(*$C$DW$T$741)
	.dwattr $C$DW$206, DW_AT_external
	.global	_sv_msg_open
_sv_msg_open:	.usect	".far",4,4
$C$DW$207	.dwtag  DW_TAG_variable, DW_AT_name("sv_msg_open")
	.dwattr $C$DW$207, DW_AT_TI_symbol_name("_sv_msg_open")
	.dwattr $C$DW$207, DW_AT_location[DW_OP_addr _sv_msg_open]
	.dwattr $C$DW$207, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$207, DW_AT_external
	.global	_read_res_fifo
_read_res_fifo:	.usect	".far",4,4
$C$DW$208	.dwtag  DW_TAG_variable, DW_AT_name("read_res_fifo")
	.dwattr $C$DW$208, DW_AT_TI_symbol_name("_read_res_fifo")
	.dwattr $C$DW$208, DW_AT_location[DW_OP_addr _read_res_fifo]
	.dwattr $C$DW$208, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$208, DW_AT_external
	.global	_sh_mem_write
_sh_mem_write:	.usect	".far",4,4
$C$DW$209	.dwtag  DW_TAG_variable, DW_AT_name("sh_mem_write")
	.dwattr $C$DW$209, DW_AT_TI_symbol_name("_sh_mem_write")
	.dwattr $C$DW$209, DW_AT_location[DW_OP_addr _sh_mem_write]
	.dwattr $C$DW$209, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$209, DW_AT_external
	.global	_sh_mem_read_proc
_sh_mem_read_proc:	.usect	".far",4,4
$C$DW$210	.dwtag  DW_TAG_variable, DW_AT_name("sh_mem_read_proc")
	.dwattr $C$DW$210, DW_AT_TI_symbol_name("_sh_mem_read_proc")
	.dwattr $C$DW$210, DW_AT_location[DW_OP_addr _sh_mem_read_proc]
	.dwattr $C$DW$210, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$210, DW_AT_external
	.global	_sh_mem_read_crypt
_sh_mem_read_crypt:	.usect	".far",4,4
$C$DW$211	.dwtag  DW_TAG_variable, DW_AT_name("sh_mem_read_crypt")
	.dwattr $C$DW$211, DW_AT_TI_symbol_name("_sh_mem_read_crypt")
	.dwattr $C$DW$211, DW_AT_location[DW_OP_addr _sh_mem_read_crypt]
	.dwattr $C$DW$211, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$211, DW_AT_external
	.global	_sh_mem_read_proc2
_sh_mem_read_proc2:	.usect	".far",4,4
$C$DW$212	.dwtag  DW_TAG_variable, DW_AT_name("sh_mem_read_proc2")
	.dwattr $C$DW$212, DW_AT_TI_symbol_name("_sh_mem_read_proc2")
	.dwattr $C$DW$212, DW_AT_location[DW_OP_addr _sh_mem_read_proc2]
	.dwattr $C$DW$212, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$212, DW_AT_external
	.global	_sh_mem_read_crypt2
_sh_mem_read_crypt2:	.usect	".far",4,4
$C$DW$213	.dwtag  DW_TAG_variable, DW_AT_name("sh_mem_read_crypt2")
	.dwattr $C$DW$213, DW_AT_TI_symbol_name("_sh_mem_read_crypt2")
	.dwattr $C$DW$213, DW_AT_location[DW_OP_addr _sh_mem_read_crypt2]
	.dwattr $C$DW$213, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$213, DW_AT_external
	.global	_Start_dozu_nagr
_Start_dozu_nagr:	.usect	".far",2,2
$C$DW$214	.dwtag  DW_TAG_variable, DW_AT_name("Start_dozu_nagr")
	.dwattr $C$DW$214, DW_AT_TI_symbol_name("_Start_dozu_nagr")
	.dwattr $C$DW$214, DW_AT_location[DW_OP_addr _Start_dozu_nagr]
	.dwattr $C$DW$214, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$214, DW_AT_external
	.global	_gl_result
_gl_result:	.usect	".far",60,4
$C$DW$215	.dwtag  DW_TAG_variable, DW_AT_name("gl_result")
	.dwattr $C$DW$215, DW_AT_TI_symbol_name("_gl_result")
	.dwattr $C$DW$215, DW_AT_location[DW_OP_addr _gl_result]
	.dwattr $C$DW$215, DW_AT_type(*$C$DW$T$438)
	.dwattr $C$DW$215, DW_AT_external
;	C:\Program Files (x86)\Texas Instruments\C6000 Code Generation Tools 6.1.22\bin\acp6x.exe -@C:\Users\shiluaev\AppData\Local\Temp\0116812 
	.sect	".text"
	.clink
	.global	_flash_chip_clear__Fv

$C$DW$216	.dwtag  DW_TAG_subprogram, DW_AT_name("flash_chip_clear")
	.dwattr $C$DW$216, DW_AT_low_pc(_flash_chip_clear__Fv)
	.dwattr $C$DW$216, DW_AT_high_pc(0x00)
	.dwattr $C$DW$216, DW_AT_TI_symbol_name("_flash_chip_clear__Fv")
	.dwattr $C$DW$216, DW_AT_external
	.dwattr $C$DW$216, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$216, DW_AT_TI_begin_file("tpo_comm.cpp")
	.dwattr $C$DW$216, DW_AT_TI_begin_line(0x88)
	.dwattr $C$DW$216, DW_AT_TI_begin_column(0x07)
	.dwpsn	file "tpo_comm.cpp",line 137,column 1,is_stmt,address _flash_chip_clear__Fv

	.dwfde $C$DW$CIE, _flash_chip_clear__Fv
;----------------------------------------------------------------------
; 136 | #define EMAC_PKT_FLAGS_EOP              0x40000000u     //< End of pack
;     | et                                                                     
;----------------------------------------------------------------------

;******************************************************************************
;* FUNCTION NAME: flash_chip_clear()                                          *
;*                                                                            *
;*   Regs Modified     : A0,A3,A4,B0,B4,B5,SP,B31                             *
;*   Regs Used         : A0,A3,A4,B0,B3,B4,B5,SP,B31                          *
;*   Local Frame Size  : 0 Args + 16 Auto + 0 Save = 16 byte                  *
;******************************************************************************
_flash_chip_clear__Fv:
;** --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
	.dwcfi	save_reg_to_reg, 228, 19
           SUB     .D2     SP,16,SP          ; |137| 
	.dwcfi	cfa_offset, 16
$C$DW$217	.dwtag  DW_TAG_variable, DW_AT_name("REG_555")
	.dwattr $C$DW$217, DW_AT_TI_symbol_name("_REG_555")
	.dwattr $C$DW$217, DW_AT_type(*$C$DW$T$682)
	.dwattr $C$DW$217, DW_AT_location[DW_OP_breg31 4]
$C$DW$218	.dwtag  DW_TAG_variable, DW_AT_name("REG_AAA")
	.dwattr $C$DW$218, DW_AT_TI_symbol_name("_REG_AAA")
	.dwattr $C$DW$218, DW_AT_type(*$C$DW$T$682)
	.dwattr $C$DW$218, DW_AT_location[DW_OP_breg31 8]
$C$DW$219	.dwtag  DW_TAG_variable, DW_AT_name("tgl0")
	.dwattr $C$DW$219, DW_AT_TI_symbol_name("_tgl0")
	.dwattr $C$DW$219, DW_AT_type(*$C$DW$T$681)
	.dwattr $C$DW$219, DW_AT_location[DW_OP_breg31 12]
$C$DW$220	.dwtag  DW_TAG_variable, DW_AT_name("tgl1")
	.dwattr $C$DW$220, DW_AT_TI_symbol_name("_tgl1")
	.dwattr $C$DW$220, DW_AT_type(*$C$DW$T$681)
	.dwattr $C$DW$220, DW_AT_location[DW_OP_breg31 13]
$C$DW$221	.dwtag  DW_TAG_variable, DW_AT_name("REG_DATA")
	.dwattr $C$DW$221, DW_AT_TI_symbol_name("_REG_DATA")
	.dwattr $C$DW$221, DW_AT_type(*$C$DW$T$682)
	.dwattr $C$DW$221, DW_AT_location[DW_OP_breg31 16]
	.dwpsn	file "tpo_comm.cpp",line 138,column 19,is_stmt
           MVKL    .S1     0x90000555,A3
           MVKH    .S1     0x90000555,A3
           STW     .D2T1   A3,*+SP(4)        ; |138| 
	.dwpsn	file "tpo_comm.cpp",line 139,column 19,is_stmt
           MVKL    .S2     0x90000aaa,B4
           MVKH    .S2     0x90000aaa,B4
           STW     .D2T2   B4,*+SP(8)        ; |139| 
	.dwpsn	file "tpo_comm.cpp",line 143,column 3,is_stmt

           MV      .L1X    B4,A3
||         MVK     .S2     170,B4            ; |143| 

           STB     .D1T2   B4,*A3            ; |143| 
	.dwpsn	file "tpo_comm.cpp",line 144,column 3,is_stmt
;----------------------------------------------------------------------
; 144 | int32 flash_chip_clear()                                               
;----------------------------------------------------------------------
           LDW     .D2T1   *+SP(4),A3        ; |144| 
           MVK     .S1     85,A4             ; |144| 
           NOP             3
           STB     .D1T1   A4,*A3            ; |144| 
	.dwpsn	file "tpo_comm.cpp",line 145,column 3,is_stmt
           LDW     .D2T1   *+SP(8),A3        ; |145| 
           MVK     .S2     128,B4            ; |145| 
           NOP             3
           STB     .D1T2   B4,*A3            ; |145| 
	.dwpsn	file "tpo_comm.cpp",line 146,column 3,is_stmt
;----------------------------------------------------------------------
; 146 | volatile uint8& REG_555 = (*(uint8*)(0x90000000 + 0x00000555 ));       
;----------------------------------------------------------------------
           LDW     .D2T1   *+SP(8),A3        ; |146| 
           MVK     .S1     170,A4            ; |146| 
           NOP             3
           STB     .D1T1   A4,*A3            ; |146| 
	.dwpsn	file "tpo_comm.cpp",line 147,column 3,is_stmt
;----------------------------------------------------------------------
; 147 | volatile uint8& REG_AAA = (*(uint8*)(0x90000000 + 0x00000aaa ));       
;----------------------------------------------------------------------
           LDW     .D2T1   *+SP(4),A3        ; |147| 
           MVK     .S2     85,B4             ; |147| 
           NOP             3
           STB     .D1T2   B4,*A3            ; |147| 
	.dwpsn	file "tpo_comm.cpp",line 148,column 3,is_stmt
;----------------------------------------------------------------------
; 148 | uint32 offset;                                                         
; 149 | volatile uint8 tgl0, tgl1;                                             
;----------------------------------------------------------------------
           LDW     .D2T1   *+SP(8),A3        ; |148| 
           MVK     .S1     16,A4             ; |148| 
           NOP             3
           STB     .D1T1   A4,*A3            ; |148| 
	.dwpsn	file "tpo_comm.cpp",line 150,column 19,is_stmt
;----------------------------------------------------------------------
; 151 | REG_AAA = 0xaa;                                                        
;----------------------------------------------------------------------
           ZERO    .L2     B4                ; |150| 
           MVKH    .S2     0x90000000,B4     ; |150| 
           STW     .D2T2   B4,*+SP(16)       ; |150| 
	.dwpsn	file "tpo_comm.cpp",line 152,column 3,is_stmt
;----------------------------------------------------------------------
; 152 | REG_555 = 0x55;                                                        
;----------------------------------------------------------------------
           LDBU    .D2T2   *B4,B4            ; |152| 
           MVK     .S1     40,A3             ; |157| 
           MVK     .S2     68,B31            ; |156| 
           NOP             2
           STB     .D2T2   B4,*+SP(13)       ; |152| 
	.dwpsn	file "tpo_comm.cpp",line 153,column 10,is_stmt
;----------------------------------------------------------------------
; 153 | REG_AAA = 0x80;                                                        
; 154 | REG_AAA = 0xaa;                                                        
;----------------------------------------------------------------------
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
$C$L1:    
$C$DW$L$_flash_chip_clear__Fv$2$B:
	.dwpsn	file "tpo_comm.cpp",line 155,column 5,is_stmt
;----------------------------------------------------------------------
; 155 | REG_555 = 0x55;                                                        
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(16),B4       ; |155| 
           NOP             4
           LDBU    .D2T2   *B4,B4            ; |155| 
           NOP             4
           STB     .D2T2   B4,*+SP(12)       ; |155| 
	.dwpsn	file "tpo_comm.cpp",line 156,column 5,is_stmt
;----------------------------------------------------------------------
; 156 | REG_AAA = 0x10;                                                        
;----------------------------------------------------------------------
           LDBU    .D2T2   *+SP(12),B4       ; |156| 
           LDBU    .D2T2   *+SP(13),B5       ; |156| 
           NOP             4
           XOR     .L2     B5,B4,B4          ; |156| 
           AND     .L2     B31,B4,B0         ; |156| 
   [!B0]   BNOP    .S1     $C$L3,5           ; |156| 
           ; BRANCHCC OCCURS {$C$L3}         ; |156| 
$C$DW$L$_flash_chip_clear__Fv$2$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_flash_chip_clear__Fv$3$B:
	.dwpsn	file "tpo_comm.cpp",line 156,column 46,is_stmt
	.dwpsn	file "tpo_comm.cpp",line 157,column 5,is_stmt
;----------------------------------------------------------------------
; 158 | volatile uint8& REG_DATA = (*(uint8*)0x90000000);                      
;----------------------------------------------------------------------
           LDBU    .D2T2   *+SP(12),B4       ; |157| 
           MVK     .S2     40,B5             ; |157| 
           NOP             3
           AND     .L2     B5,B4,B4          ; |157| 
           NOP             1
           CMPEQ   .L1X    B4,A3,A0          ; |157| 
   [!A0]   BNOP    .S1     $C$L2,5           ; |157| 
           ; BRANCHCC OCCURS {$C$L2}         ; |157| 
$C$DW$L$_flash_chip_clear__Fv$3$E:
;** --------------------------------------------------------------------------*
	.dwpsn	file "tpo_comm.cpp",line 159,column 7,is_stmt
           LDW     .D2T1   *+SP(16),A3       ; |159| 
           NOP             4
           LDBU    .D1T1   *A3,A3            ; |159| 
           NOP             4
           STB     .D2T1   A3,*+SP(13)       ; |159| 
	.dwpsn	file "tpo_comm.cpp",line 160,column 7,is_stmt
;----------------------------------------------------------------------
; 160 | tgl1 = REG_DATA;                                                       
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(16),B4       ; |160| 
           NOP             4
           LDBU    .D2T2   *B4,B4            ; |160| 
           NOP             4
           STB     .D2T2   B4,*+SP(12)       ; |160| 
	.dwpsn	file "tpo_comm.cpp",line 161,column 7,is_stmt
;----------------------------------------------------------------------
; 161 | while( true )                                                          
;----------------------------------------------------------------------
           LDBU    .D2T2   *+SP(12),B4       ; |161| 
           LDBU    .D2T2   *+SP(13),B5       ; |161| 
           MVK     .S2     68,B31            ; |161| 
           NOP             3
           XOR     .L2     B5,B4,B4          ; |161| 
           AND     .L2     B31,B4,B0         ; |161| 
   [!B0]   BNOP    .S1     $C$L3,5           ; |161| 
           ; BRANCHCC OCCURS {$C$L3}         ; |161| 
;** --------------------------------------------------------------------------*
	.dwpsn	file "tpo_comm.cpp",line 161,column 48,is_stmt
	.dwpsn	file "tpo_comm.cpp",line 162,column 7,is_stmt
           LDW     .D2T2   *+SP(16),B5       ; |162| 
           MVK     .S2     240,B4            ; |162| 
           NOP             3
           STB     .D2T2   B4,*B5            ; |162| 
	.dwpsn	file "tpo_comm.cpp",line 163,column 7,is_stmt
;----------------------------------------------------------------------
; 163 | tgl0 = REG_DATA;                                                       
; 164 | if( ( ( tgl0 ^ tgl1 ) & 0x44 ) == 0x00 ) break;                        
;----------------------------------------------------------------------
           BNOP    .S1     $C$L4,4           ; |163| 
           MVK     .L1     0x1,A4            ; |163| 
           ; BRANCH OCCURS {$C$L4}           ; |163| 
;** --------------------------------------------------------------------------*
$C$L2:    
$C$DW$L$_flash_chip_clear__Fv$6$B:
	.dwpsn	file "tpo_comm.cpp",line 165,column 5,is_stmt
;----------------------------------------------------------------------
; 165 | if( ( tgl0 & 0x28 ) == 0x28 )                                          
; 167 |   tgl1 = REG_DATA;                                                     
;----------------------------------------------------------------------
           LDBU    .D2T2   *+SP(12),B4       ; |165| 
           NOP             4
           STB     .D2T2   B4,*+SP(13)       ; |165| 
	.dwpsn	file "tpo_comm.cpp",line 153,column 10,is_stmt
           BNOP    .S1     $C$L1,5           ; |153| 
           ; BRANCH OCCURS {$C$L1}           ; |153| 
$C$DW$L$_flash_chip_clear__Fv$6$E:
;** --------------------------------------------------------------------------*
$C$L3:    
	.dwpsn	file "tpo_comm.cpp",line 168,column 3,is_stmt
;----------------------------------------------------------------------
; 168 | tgl0 = REG_DATA;                                                       
;----------------------------------------------------------------------
           ZERO    .L1     A4                ; |168| 
;** --------------------------------------------------------------------------*
$C$L4:    
	.dwpsn	file "tpo_comm.cpp",line 169,column 1,is_stmt
;----------------------------------------------------------------------
; 169 | if( ( ( tgl0 ^ tgl1 ) & 0x44 ) == 0x00 ) break;                        
;----------------------------------------------------------------------
           ADDK    .S2     16,SP             ; |169| 
	.dwcfi	cfa_offset, 0
	.dwcfi	cfa_offset, 0
$C$DW$222	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$222, DW_AT_low_pc(0x00)
	.dwattr $C$DW$222, DW_AT_TI_return
           RETNOP  .S2     B3,5              ; |169| 
           ; BRANCH OCCURS {B3}              ; |169| 

$C$DW$223	.dwtag  DW_TAG_TI_loop
	.dwattr $C$DW$223, DW_AT_name("C:\1901VC1T_Inteltech\3rdPartyLIB\dsp_core\C6000\tpo_amoeba\source\tpo_comm.asm:$C$L1:1:1517815040")
	.dwattr $C$DW$223, DW_AT_TI_begin_file("tpo_comm.cpp")
	.dwattr $C$DW$223, DW_AT_TI_begin_line(0x99)
	.dwattr $C$DW$223, DW_AT_TI_end_line(0xa6)
$C$DW$224	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$224, DW_AT_low_pc($C$DW$L$_flash_chip_clear__Fv$2$B)
	.dwattr $C$DW$224, DW_AT_high_pc($C$DW$L$_flash_chip_clear__Fv$2$E)
$C$DW$225	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$225, DW_AT_low_pc($C$DW$L$_flash_chip_clear__Fv$3$B)
	.dwattr $C$DW$225, DW_AT_high_pc($C$DW$L$_flash_chip_clear__Fv$3$E)
$C$DW$226	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$226, DW_AT_low_pc($C$DW$L$_flash_chip_clear__Fv$6$B)
	.dwattr $C$DW$226, DW_AT_high_pc($C$DW$L$_flash_chip_clear__Fv$6$E)
	.dwendtag $C$DW$223

	.dwattr $C$DW$216, DW_AT_TI_end_file("tpo_comm.cpp")
	.dwattr $C$DW$216, DW_AT_TI_end_line(0xa9)
	.dwattr $C$DW$216, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$216

	.sect	".text"
	.clink
	.global	_Load_po_flash__Fv

$C$DW$227	.dwtag  DW_TAG_subprogram, DW_AT_name("Load_po_flash")
	.dwattr $C$DW$227, DW_AT_low_pc(_Load_po_flash__Fv)
	.dwattr $C$DW$227, DW_AT_high_pc(0x00)
	.dwattr $C$DW$227, DW_AT_TI_symbol_name("_Load_po_flash__Fv")
	.dwattr $C$DW$227, DW_AT_external
	.dwattr $C$DW$227, DW_AT_TI_begin_file("tpo_comm.cpp")
	.dwattr $C$DW$227, DW_AT_TI_begin_line(0xaf)
	.dwattr $C$DW$227, DW_AT_TI_begin_column(0x06)
	.dwpsn	file "tpo_comm.cpp",line 176,column 1,is_stmt,address _Load_po_flash__Fv

	.dwfde $C$DW$CIE, _Load_po_flash__Fv

;******************************************************************************
;* FUNCTION NAME: Load_po_flash()                                             *
;*                                                                            *
;*   Regs Modified     : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP,A16,A17,A18,A19,A20,A21,A22,A23,A24, *
;*                           A25,A26,A27,A28,A29,A30,A31,B16,B17,B18,B19,B20, *
;*                           B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31      *
;*   Regs Used         : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP,A16,A17,A18,A19,A20,A21,A22,A23,A24, *
;*                           A25,A26,A27,A28,A29,A30,A31,B16,B17,B18,B19,B20, *
;*                           B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31      *
;*   Local Frame Size  : 0 Args + 1060 Auto + 4 Save = 1064 byte              *
;******************************************************************************
_Load_po_flash__Fv:
;** --------------------------------------------------------------------------*
;----------------------------------------------------------------------
; 176 | return OSE_OK;                                                         
;----------------------------------------------------------------------
	.dwcfi	cfa_offset, 0
	.dwcfi	save_reg_to_reg, 228, 19
           ADDK    .S2     -1064,SP          ; |176| 
	.dwcfi	cfa_offset, 1064
           STW     .D2T2   B3,*+SP(1064)     ; |176| 
	.dwcfi	save_reg_to_mem, 19, 0
$C$DW$228	.dwtag  DW_TAG_variable, DW_AT_name("msg_from")
	.dwattr $C$DW$228, DW_AT_TI_symbol_name("_msg_from")
	.dwattr $C$DW$228, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$228, DW_AT_location[DW_OP_breg31 4]
$C$DW$229	.dwtag  DW_TAG_variable, DW_AT_name("cdg_error")
	.dwattr $C$DW$229, DW_AT_TI_symbol_name("_cdg_error")
	.dwattr $C$DW$229, DW_AT_type(*$C$DW$T$433)
	.dwattr $C$DW$229, DW_AT_location[DW_OP_breg31 8]
$C$DW$230	.dwtag  DW_TAG_variable, DW_AT_name("msg_desc")
	.dwattr $C$DW$230, DW_AT_TI_symbol_name("_msg_desc")
	.dwattr $C$DW$230, DW_AT_type(*$C$DW$T$129)
	.dwattr $C$DW$230, DW_AT_location[DW_OP_breg31 16]
$C$DW$231	.dwtag  DW_TAG_variable, DW_AT_name("buf")
	.dwattr $C$DW$231, DW_AT_TI_symbol_name("_buf")
	.dwattr $C$DW$231, DW_AT_type(*$C$DW$T$301)
	.dwattr $C$DW$231, DW_AT_location[DW_OP_breg31 24]
$C$DW$232	.dwtag  DW_TAG_variable, DW_AT_name("flesh_offset")
	.dwattr $C$DW$232, DW_AT_TI_symbol_name("_flesh_offset")
	.dwattr $C$DW$232, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$232, DW_AT_location[DW_OP_breg31 1048]
$C$DW$233	.dwtag  DW_TAG_variable, DW_AT_name("fwm_file")
	.dwattr $C$DW$233, DW_AT_TI_symbol_name("_fwm_file")
	.dwattr $C$DW$233, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$233, DW_AT_location[DW_OP_breg31 1052]
$C$DW$234	.dwtag  DW_TAG_variable, DW_AT_name("fwrw")
	.dwattr $C$DW$234, DW_AT_TI_symbol_name("_fwrw")
	.dwattr $C$DW$234, DW_AT_type(*$C$DW$T$423)
	.dwattr $C$DW$234, DW_AT_location[DW_OP_breg31 1056]
	.dwpsn	file "tpo_comm.cpp",line 183,column 10,is_stmt
;----------------------------------------------------------------------
; 183 | void Load_po_flash()                                                   
;----------------------------------------------------------------------
           ZERO    .L1     A3                ; |183| 
           STW     .D2T1   A3,*+SP(1048)     ; |183| 
	.dwpsn	file "tpo_comm.cpp",line 184,column 14,is_stmt
;----------------------------------------------------------------------
; 186 | uint32          msg_from;                                              
;----------------------------------------------------------------------
           ZERO    .L2     B4                ; |184| 
           STW     .D2T2   B4,*+SP(1052)     ; |184| 
	.dwpsn	file "tpo_comm.cpp",line 187,column 2,is_stmt
;----------------------------------------------------------------------
; 187 | //      kdg_cmd         to_iface;                                      
;----------------------------------------------------------------------
           ADD     .D2     SP,24,B4          ; |187| 
           STW     .D2T2   B4,*+SP(1056)     ; |187| 
	.dwpsn	file "tpo_comm.cpp",line 188,column 2,is_stmt
;----------------------------------------------------------------------
; 188 | kdg_cmd_ask     cdg_error;                                             
; 189 | s_message*  msg_desc;                                                  
; 190 | uint8   buf[1024];                                                     
;----------------------------------------------------------------------
           MVK     .S2     1024,B4           ; |188| 
           STW     .D2T2   B4,*+SP(1060)     ; |188| 
	.dwpsn	file "tpo_comm.cpp",line 191,column 2,is_stmt
;----------------------------------------------------------------------
; 191 | uint32          flesh_offset = 0;                                      
; 192 | uint32      fwm_file = RES_VOID;                                       
; 193 | s_fwmem_rwbuf        fwrw;                                             
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+292,A3
           MVKH    .S1     ___syscall_tab+292,A3
           LDW     .D1T1   *A3,A3            ; |191| 
           MVKL    .S1     $C$SL1+0,A4       ; |191| 
           MVKH    .S1     $C$SL1+0,A4       ; |191| 
           NOP             2
$C$DW$235	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$235, DW_AT_low_pc(0x00)
	.dwattr $C$DW$235, DW_AT_TI_call
	.dwattr $C$DW$235, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |191| 
           ADDKPC  .S2     $C$RL0,B3,4       ; |191| 
$C$RL0:    ; CALL OCCURS {A3} {0}            ; |191| 
           STW     .D2T1   A4,*+SP(1052)     ; |191| 
	.dwpsn	file "tpo_comm.cpp",line 194,column 9,is_stmt
;----------------------------------------------------------------------
; 195 | fwrw.buffer = buf;                                                     
;----------------------------------------------------------------------
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
$C$L5:    
$C$DW$L$_Load_po_flash__Fv$2$B:
	.dwpsn	file "tpo_comm.cpp",line 196,column 2,is_stmt
;----------------------------------------------------------------------
; 196 | fwrw.length = 1024;                                                    
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+388,A3
           MVKH    .S1     ___syscall_tab+388,A3
           LDW     .D1T1   *A3,A3            ; |196| 
           ADD     .D2     SP,16,B5          ; |196| 
           MVK     .S2     0x2710,B4         ; |196| 
           MV      .L1X    B5,A4             ; |196| 
           NOP             1
$C$DW$236	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$236, DW_AT_low_pc(0x00)
	.dwattr $C$DW$236, DW_AT_TI_call
	.dwattr $C$DW$236, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |196| 
           ADDKPC  .S2     $C$RL1,B3,4       ; |196| 
$C$RL1:    ; CALL OCCURS {A3} {0}            ; |196| 
           MV      .L1     A4,A0             ; |196| 
   [!A0]   BNOP    .S1     $C$L6,5           ; |196| 
           ; BRANCHCC OCCURS {$C$L6}         ; |196| 
$C$DW$L$_Load_po_flash__Fv$2$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_Load_po_flash__Fv$3$B:
	.dwpsn	file "tpo_comm.cpp",line 198,column 5,is_stmt
           LDW     .D2T2   *+SP(16),B0       ; |198| 
           NOP             4
   [!B0]   BNOP    .S1     $C$L5,5           ; |198| 
           ; BRANCHCC OCCURS {$C$L5}         ; |198| 
$C$DW$L$_Load_po_flash__Fv$3$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_Load_po_flash__Fv$4$B:
	.dwpsn	file "tpo_comm.cpp",line 198,column 26,is_stmt
$C$DW$L$_Load_po_flash__Fv$4$E:
;** --------------------------------------------------------------------------*
$C$L6:    
$C$DW$L$_Load_po_flash__Fv$5$B:
	.dwpsn	file "tpo_comm.cpp",line 199,column 2,is_stmt
;----------------------------------------------------------------------
; 199 | fwm_file = drv_mkd("/fwmem");                                          
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(16),B4       ; |199| 
           MVK     .S2     1024,B5           ; |199| 
           NOP             3
           LDW     .D2T2   *+B4(20),B4       ; |199| 
           NOP             4
           CMPLT   .L2     B4,B5,B0          ; |199| 
   [ B0]   BNOP    .S1     $C$L7,5           ; |199| 
           ; BRANCHCC OCCURS {$C$L7}         ; |199| 
$C$DW$L$_Load_po_flash__Fv$5$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_Load_po_flash__Fv$6$B:
	.dwpsn	file "tpo_comm.cpp",line 199,column 30,is_stmt
	.dwpsn	file "tpo_comm.cpp",line 201,column 5,is_stmt
           LDW     .D2T1   *+SP(16),A3       ; |201| 
           NOP             4
           LDW     .D1T1   *+A3(12),A3       ; |201| 
           NOP             4
           STW     .D2T1   A3,*+SP(4)        ; |201| 
	.dwpsn	file "tpo_comm.cpp",line 202,column 2,is_stmt
;----------------------------------------------------------------------
; 202 | while(true)                                                            
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(16),B4       ; |202| 
           ADD     .D2     SP,24,B31         ; |202| 
           NOP             3
$C$DW$237	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$237, DW_AT_low_pc(0x04)
	.dwattr $C$DW$237, DW_AT_name("_memcpy")
	.dwattr $C$DW$237, DW_AT_TI_call

           MV      .L1X    B4,A3             ; |202| 
||         CALL    .S1     _memcpy           ; |202| 

           LDW     .D2T1   *+B4(20),A6       ; |202| 
||         LDW     .D1T2   *+A3(24),B4       ; |202| 

           MV      .L1X    B31,A4            ; |202| 
           ADDKPC  .S2     $C$RL2,B3,2       ; |202| 
$C$RL2:    ; CALL OCCURS {_memcpy} {0}       ; |202| 
	.dwpsn	file "tpo_comm.cpp",line 203,column 5,is_stmt
;----------------------------------------------------------------------
; 204 | if(msg_recv( &msg_desc, MSG_WAIT_10) != OSE_OK)                        
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+404,A3
           MVKH    .S1     ___syscall_tab+404,A3
           LDW     .D1T1   *A3,A3            ; |203| 
           LDW     .D2T1   *+SP(16),A4       ; |203| 
           NOP             3
$C$DW$238	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$238, DW_AT_low_pc(0x00)
	.dwattr $C$DW$238, DW_AT_TI_call
	.dwattr $C$DW$238, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |203| 
           ADDKPC  .S2     $C$RL3,B3,4       ; |203| 
$C$RL3:    ; CALL OCCURS {A3} {0}            ; |203| 
	.dwpsn	file "tpo_comm.cpp",line 205,column 2,is_stmt
;----------------------------------------------------------------------
; 206 | if(msg_desc == NULL) continue;                                         
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+284,A3
           MVKH    .S1     ___syscall_tab+284,A3
           LDW     .D1T1   *A3,A3            ; |205| 
           LDW     .D2T1   *+SP(1052),A4     ; |205| 
           MVK     .S2     1056,B4           ; |205| 
           ADD     .L2     B4,SP,B4          ; |205| 
           NOP             1
$C$DW$239	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$239, DW_AT_low_pc(0x00)
	.dwattr $C$DW$239, DW_AT_TI_call
	.dwattr $C$DW$239, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |205| 
           MV      .L1X    B4,A6             ; |205| 
           MVK     .S2     0x1204,B4         ; |205| 
           ADDKPC  .S2     $C$RL4,B3,2       ; |205| 
$C$RL4:    ; CALL OCCURS {A3} {0}            ; |205| 
	.dwpsn	file "tpo_comm.cpp",line 207,column 2,is_stmt
;----------------------------------------------------------------------
; 207 | if(msg_desc->length < 1024) break;                                     
;----------------------------------------------------------------------
           MVKL    .S2     0xd002b,B4
           MVKH    .S2     0xd002b,B4
           STW     .D2T2   B4,*+SP(8)        ; |207| 
	.dwpsn	file "tpo_comm.cpp",line 208,column 2,is_stmt
           ZERO    .L2     B4                ; |208| 
           STW     .D2T2   B4,*+SP(12)       ; |208| 
	.dwpsn	file "tpo_comm.cpp",line 209,column 2,is_stmt
;----------------------------------------------------------------------
; 209 | msg_from = msg_desc->from;                                             
; 210 |     memcpy(buf, msg_desc->data, msg_desc->length);                     
; 211 | msg_free(msg_desc);                                                    
; 213 |     drv_ioctl(fwm_file, FWMEM_WRITE, &fwrw);                           
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+384,A3
           MVKH    .S1     ___syscall_tab+384,A3
           LDW     .D1T1   *A3,A3            ; |209| 
           LDW     .D2T1   *+SP(4),A4        ; |209| 
           MVK     .L1     0x8,A6            ; |209| 
           ADD     .L2     8,SP,B4           ; |209| 
           NOP             1
$C$DW$240	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$240, DW_AT_low_pc(0x00)
	.dwattr $C$DW$240, DW_AT_TI_call
	.dwattr $C$DW$240, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |209| 
           ADDKPC  .S2     $C$RL5,B3,4       ; |209| 
$C$RL5:    ; CALL OCCURS {A3} {0}            ; |209| 
	.dwpsn	file "tpo_comm.cpp",line 194,column 9,is_stmt
           BNOP    .S1     $C$L5,5           ; |194| 
           ; BRANCH OCCURS {$C$L5}           ; |194| 
$C$DW$L$_Load_po_flash__Fv$6$E:
;** --------------------------------------------------------------------------*
$C$L7:    
	.dwpsn	file "tpo_comm.cpp",line 214,column 2,is_stmt
;----------------------------------------------------------------------
; 215 | cdg_error.cmd = START_LOAD_PO;                                         
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+296,A3
           MVKH    .S1     ___syscall_tab+296,A3
           LDW     .D1T1   *A3,A3            ; |214| 
           LDW     .D2T1   *+SP(1052),A4     ; |214| 
           NOP             3
$C$DW$241	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$241, DW_AT_low_pc(0x00)
	.dwattr $C$DW$241, DW_AT_TI_call
	.dwattr $C$DW$241, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |214| 
           ADDKPC  .S2     $C$RL6,B3,4       ; |214| 
$C$RL6:    ; CALL OCCURS {A3} {0}            ; |214| 
	.dwpsn	file "tpo_comm.cpp",line 216,column 1,is_stmt
;----------------------------------------------------------------------
; 216 | cdg_error.ask = TPO_OK;                                                
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(1064),B3     ; |216| 
           NOP             4
	.dwcfi	restore_reg, 19
           ADDK    .S2     1064,SP           ; |216| 
	.dwcfi	cfa_offset, 0
	.dwcfi	cfa_offset, 0
$C$DW$242	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$242, DW_AT_low_pc(0x00)
	.dwattr $C$DW$242, DW_AT_TI_return
           RETNOP  .S2     B3,5              ; |216| 
           ; BRANCH OCCURS {B3}              ; |216| 

$C$DW$243	.dwtag  DW_TAG_TI_loop
	.dwattr $C$DW$243, DW_AT_name("C:\1901VC1T_Inteltech\3rdPartyLIB\dsp_core\C6000\tpo_amoeba\source\tpo_comm.asm:$C$L5:1:1517815040")
	.dwattr $C$DW$243, DW_AT_TI_begin_file("tpo_comm.cpp")
	.dwattr $C$DW$243, DW_AT_TI_begin_line(0xc2)
	.dwattr $C$DW$243, DW_AT_TI_end_line(0xd3)
$C$DW$244	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$244, DW_AT_low_pc($C$DW$L$_Load_po_flash__Fv$2$B)
	.dwattr $C$DW$244, DW_AT_high_pc($C$DW$L$_Load_po_flash__Fv$2$E)
$C$DW$245	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$245, DW_AT_low_pc($C$DW$L$_Load_po_flash__Fv$4$B)
	.dwattr $C$DW$245, DW_AT_high_pc($C$DW$L$_Load_po_flash__Fv$4$E)
$C$DW$246	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$246, DW_AT_low_pc($C$DW$L$_Load_po_flash__Fv$5$B)
	.dwattr $C$DW$246, DW_AT_high_pc($C$DW$L$_Load_po_flash__Fv$5$E)
$C$DW$247	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$247, DW_AT_low_pc($C$DW$L$_Load_po_flash__Fv$6$B)
	.dwattr $C$DW$247, DW_AT_high_pc($C$DW$L$_Load_po_flash__Fv$6$E)
$C$DW$248	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$248, DW_AT_low_pc($C$DW$L$_Load_po_flash__Fv$3$B)
	.dwattr $C$DW$248, DW_AT_high_pc($C$DW$L$_Load_po_flash__Fv$3$E)
	.dwendtag $C$DW$243

	.dwattr $C$DW$227, DW_AT_TI_end_file("tpo_comm.cpp")
	.dwattr $C$DW$227, DW_AT_TI_end_line(0xd8)
	.dwattr $C$DW$227, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$227

	.sect	".text"
	.clink
	.global	_tpo_comm__FPvPc

$C$DW$249	.dwtag  DW_TAG_subprogram, DW_AT_name("tpo_comm")
	.dwattr $C$DW$249, DW_AT_low_pc(_tpo_comm__FPvPc)
	.dwattr $C$DW$249, DW_AT_high_pc(0x00)
	.dwattr $C$DW$249, DW_AT_TI_symbol_name("_tpo_comm__FPvPc")
	.dwattr $C$DW$249, DW_AT_external
	.dwattr $C$DW$249, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$249, DW_AT_TI_begin_file("tpo_comm.cpp")
	.dwattr $C$DW$249, DW_AT_TI_begin_line(0xdf)
	.dwattr $C$DW$249, DW_AT_TI_begin_column(0x05)
	.dwpsn	file "tpo_comm.cpp",line 224,column 1,is_stmt,address _tpo_comm__FPvPc

	.dwfde $C$DW$CIE, _tpo_comm__FPvPc
$C$DW$250	.dwtag  DW_TAG_formal_parameter, DW_AT_name("arg")
	.dwattr $C$DW$250, DW_AT_TI_symbol_name("_arg")
	.dwattr $C$DW$250, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$250, DW_AT_location[DW_OP_reg4]
$C$DW$251	.dwtag  DW_TAG_formal_parameter, DW_AT_name("sys_name")
	.dwattr $C$DW$251, DW_AT_TI_symbol_name("_sys_name")
	.dwattr $C$DW$251, DW_AT_type(*$C$DW$T$80)
	.dwattr $C$DW$251, DW_AT_location[DW_OP_reg20]

;******************************************************************************
;* FUNCTION NAME: tpo_comm(void *, char *)                                    *
;*                                                                            *
;*   Regs Modified     : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP,A16,A17,A18,A19,A20,A21,A22,A23,A24, *
;*                           A25,A26,A27,A28,A29,A30,A31,B16,B17,B18,B19,B20, *
;*                           B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31      *
;*   Regs Used         : A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,B0,B1,B2,B3,B4,B5,B6,  *
;*                           B7,B8,B9,SP,A16,A17,A18,A19,A20,A21,A22,A23,A24, *
;*                           A25,A26,A27,A28,A29,A30,A31,B16,B17,B18,B19,B20, *
;*                           B21,B22,B23,B24,B25,B26,B27,B28,B29,B30,B31      *
;*   Local Frame Size  : 0 Args + 2140 Auto + 4 Save = 2144 byte              *
;******************************************************************************
_tpo_comm__FPvPc:
;** --------------------------------------------------------------------------*
	.dwcfi	cfa_offset, 0
	.dwcfi	save_reg_to_reg, 228, 19
           ADDK    .S2     -2144,SP          ; |224| 
	.dwcfi	cfa_offset, 2144
           STW     .D2T2   B3,*+SP(2144)     ; |224| 
	.dwcfi	save_reg_to_mem, 19, 0
$C$DW$252	.dwtag  DW_TAG_variable, DW_AT_name("arg")
	.dwattr $C$DW$252, DW_AT_TI_symbol_name("_arg")
	.dwattr $C$DW$252, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$252, DW_AT_location[DW_OP_breg31 4]
$C$DW$253	.dwtag  DW_TAG_variable, DW_AT_name("sys_name")
	.dwattr $C$DW$253, DW_AT_TI_symbol_name("_sys_name")
	.dwattr $C$DW$253, DW_AT_type(*$C$DW$T$80)
	.dwattr $C$DW$253, DW_AT_location[DW_OP_breg31 8]
$C$DW$254	.dwtag  DW_TAG_variable, DW_AT_name("error")
	.dwattr $C$DW$254, DW_AT_TI_symbol_name("_error")
	.dwattr $C$DW$254, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$254, DW_AT_location[DW_OP_breg31 12]
$C$DW$255	.dwtag  DW_TAG_variable, DW_AT_name("msg_from")
	.dwattr $C$DW$255, DW_AT_TI_symbol_name("_msg_from")
	.dwattr $C$DW$255, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$255, DW_AT_location[DW_OP_breg31 16]
$C$DW$256	.dwtag  DW_TAG_variable, DW_AT_name("cdg_error")
	.dwattr $C$DW$256, DW_AT_TI_symbol_name("_cdg_error")
	.dwattr $C$DW$256, DW_AT_type(*$C$DW$T$433)
	.dwattr $C$DW$256, DW_AT_location[DW_OP_breg31 20]
$C$DW$257	.dwtag  DW_TAG_variable, DW_AT_name("msg_desc")
	.dwattr $C$DW$257, DW_AT_TI_symbol_name("_msg_desc")
	.dwattr $C$DW$257, DW_AT_type(*$C$DW$T$129)
	.dwattr $C$DW$257, DW_AT_location[DW_OP_breg31 28]
$C$DW$258	.dwtag  DW_TAG_variable, DW_AT_name("FileNet")
	.dwattr $C$DW$258, DW_AT_TI_symbol_name("_FileNet")
	.dwattr $C$DW$258, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$258, DW_AT_location[DW_OP_breg31 32]
$C$DW$259	.dwtag  DW_TAG_variable, DW_AT_name("netcfg")
	.dwattr $C$DW$259, DW_AT_TI_symbol_name("_netcfg")
	.dwattr $C$DW$259, DW_AT_type(*$C$DW$T$614)
	.dwattr $C$DW$259, DW_AT_location[DW_OP_breg31 36]
$C$DW$260	.dwtag  DW_TAG_variable, DW_AT_name("atr")
	.dwattr $C$DW$260, DW_AT_TI_symbol_name("_atr")
	.dwattr $C$DW$260, DW_AT_type(*$C$DW$T$216)
	.dwattr $C$DW$260, DW_AT_location[DW_OP_breg31 60]
;----------------------------------------------------------------------
; 231 | int tpo_comm(void* arg, char* sys_name)                                
; 234 | int32       error;                                                     
; 235 |     uint32          msg_from;                                          
; 236 |     kdg_cmd         to_iface;                                          
; 237 |     kdg_cmd_ask     cdg_error;                                         
; 238 |     s_message*  msg_desc;                                              
; 241 |     #ifdef CHIP_6457                                                   
; 242 |     QDMA_init();                                                       
; 243 |     #endif                                                             
; 247 |     //Load_lif_from_usb();                                             
;----------------------------------------------------------------------

           MV      .L2X    A4,B5             ; |224| 
||         STW     .D2T2   B4,*+SP(8)        ; |224| 

           STW     .D2T2   B5,*+SP(4)        ; |224| 
	.dwpsn	file "tpo_comm.cpp",line 250,column 10,is_stmt
;----------------------------------------------------------------------
; 253 | //alp_to_plis_6457(0);                                                 
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+292,A3
           MVKH    .S1     ___syscall_tab+292,A3
           LDW     .D1T1   *A3,A3            ; |250| 
           MVKL    .S1     $C$SL2+0,A4       ; |250| 
           MVKH    .S1     $C$SL2+0,A4       ; |250| 
           NOP             2
$C$DW$261	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$261, DW_AT_low_pc(0x00)
	.dwattr $C$DW$261, DW_AT_TI_call
	.dwattr $C$DW$261, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |250| 
           ADDKPC  .S2     $C$RL7,B3,4       ; |250| 
$C$RL7:    ; CALL OCCURS {A3} {0}            ; |250| 
           MV      .L2X    A4,B4             ; |250| 
           STW     .D2T2   B4,*+SP(32)       ; |250| 
	.dwpsn	file "tpo_comm.cpp",line 255,column 3,is_stmt
           MVKL    .S1     ___syscall_tab+284,A3
           MVKH    .S1     ___syscall_tab+284,A3
           LDW     .D1T1   *A3,A3            ; |255| 
           ADDAW   .D2     SP,9,B5           ; |255| 
           MVK     .S2     0x110c,B4         ; |255| 
           MV      .L1X    B5,A6             ; |255| 
           NOP             1
$C$DW$262	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$262, DW_AT_low_pc(0x00)
	.dwattr $C$DW$262, DW_AT_TI_call
	.dwattr $C$DW$262, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |255| 
           ADDKPC  .S2     $C$RL8,B3,4       ; |255| 
$C$RL8:    ; CALL OCCURS {A3} {0}            ; |255| 
           STW     .D2T1   A4,*+SP(12)       ; |255| 
	.dwpsn	file "tpo_comm.cpp",line 256,column 3,is_stmt
           LDHU    .D2T2   *+SP(42),B4       ; |256| 
           NOP             4
           OR      .L2     1,B4,B4           ; |256| 
           STH     .D2T2   B4,*+SP(42)       ; |256| 
	.dwpsn	file "tpo_comm.cpp",line 257,column 3,is_stmt
;----------------------------------------------------------------------
; 257 | //#ifdef TPO7                                                          
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+284,A3
           MVKH    .S1     ___syscall_tab+284,A3
           LDW     .D1T1   *A3,A3            ; |257| 
           LDW     .D2T1   *+SP(32),A4       ; |257| 
           ADDAW   .D2     SP,9,B5           ; |257| 
           MVK     .S2     0x110a,B4         ; |257| 
           MV      .L1X    B5,A6             ; |257| 
$C$DW$263	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$263, DW_AT_low_pc(0x00)
	.dwattr $C$DW$263, DW_AT_TI_call
	.dwattr $C$DW$263, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |257| 
           ADDKPC  .S2     $C$RL9,B3,4       ; |257| 
$C$RL9:    ; CALL OCCURS {A3} {0}            ; |257| 
           STW     .D2T1   A4,*+SP(12)       ; |257| 
	.dwpsn	file "tpo_comm.cpp",line 258,column 3,is_stmt
;----------------------------------------------------------------------
; 258 | uint32 FileNet = drv_mkd("/dev/net/eth0");                             
; 259 | //if(FileNet == RES_VOID)                                              
; 260 | //while(1);                                                            
;----------------------------------------------------------------------
           MVKL    .S2     ___syscall_tab+296,B4
           MVKH    .S2     ___syscall_tab+296,B4
           LDW     .D2T2   *B4,B4            ; |258| 
           LDW     .D2T1   *+SP(32),A4       ; |258| 
           NOP             3
$C$DW$264	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$264, DW_AT_low_pc(0x00)
	.dwattr $C$DW$264, DW_AT_TI_call
	.dwattr $C$DW$264, DW_AT_TI_indirect
           CALL    .S2     B4                ; |258| 
           ADDKPC  .S2     $C$RL10,B3,4      ; |258| 
$C$RL10:   ; CALL OCCURS {B4} {0}            ; |258| 
	.dwpsn	file "tpo_comm.cpp",line 262,column 4,is_stmt
;----------------------------------------------------------------------
; 262 | net_config netcfg;                                                     
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+376,A3
           MVKH    .S1     ___syscall_tab+376,A3
           LDW     .D1T1   *A3,A3            ; |262| 
           MVKL    .S1     $C$SL3+0,A4       ; |262| 
           MVKH    .S1     $C$SL3+0,A4       ; |262| 
           NOP             2
$C$DW$265	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$265, DW_AT_low_pc(0x00)
	.dwattr $C$DW$265, DW_AT_TI_call
	.dwattr $C$DW$265, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |262| 
           ADDKPC  .S2     $C$RL11,B3,4      ; |262| 
$C$RL11:   ; CALL OCCURS {A3} {0}            ; |262| 
           MV      .L2X    A4,B4             ; |262| 
           STW     .D2T2   B4,*+SP(12)       ; |262| 
	.dwpsn	file "tpo_comm.cpp",line 263,column 4,is_stmt
;----------------------------------------------------------------------
; 263 | error = drv_ioctl(FileNet, NET_GET_CONFIG, &netcfg ); //нужно дл       
;----------------------------------------------------------------------
           MV      .L2     B4,B0
   [!B0]   BNOP    .S1     $C$L8,5           ; |263| 
           ; BRANCHCC OCCURS {$C$L8}         ; |263| 
;** --------------------------------------------------------------------------*
	.dwpsn	file "tpo_comm.cpp",line 264,column 3,is_stmt
;----------------------------------------------------------------------
; 264 | теста                                                                  
; 265 |         netcfg.flags |= NETCFG_PROMISCUOUSE;                           
;----------------------------------------------------------------------
           BNOP    .S1     $C$L43,4          ; |264| 
           MVK     .L1     0xffffffff,A4     ; |264| 
           ; BRANCH OCCURS {$C$L43}          ; |264| 
;** --------------------------------------------------------------------------*
$C$L8:    
	.dwpsn	file "tpo_comm.cpp",line 266,column 3,is_stmt
;----------------------------------------------------------------------
; 266 | error = drv_ioctl(FileNet, NET_SET_CONFIG, &netcfg );                  
; 267 | drv_rmd(FileNet);                                                      
;----------------------------------------------------------------------
           MVKL    .S2     _sv_msg_open,B4

           MVKH    .S2     _sv_msg_open,B4
||         MVK     .L1     1,A3              ; |266| 

           STW     .D2T1   A3,*B4            ; |266| 
	.dwpsn	file "tpo_comm.cpp",line 268,column 3,is_stmt
;----------------------------------------------------------------------
; 268 | //#endif                                                               
;----------------------------------------------------------------------
$C$DW$266	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$266, DW_AT_low_pc(0x00)
	.dwattr $C$DW$266, DW_AT_name("_memset")
	.dwattr $C$DW$266, DW_AT_TI_call
           CALL    .S1     _memset           ; |268| 
           ADDAW   .D2     SP,15,B4          ; |268| 
           ADDKPC  .S2     $C$RL12,B3,2      ; |268| 

           MVK     .S1     0x14,A6           ; |268| 
||         MV      .L1X    B4,A4             ; |268| 
||         ZERO    .L2     B4                ; |268| 

$C$RL12:   ; CALL OCCURS {_memset} {0}       ; |268| 
	.dwpsn	file "tpo_comm.cpp",line 269,column 3,is_stmt
           MVK     .S2     12288,B4          ; |269| 
           STW     .D2T2   B4,*+SP(60)       ; |269| 
	.dwpsn	file "tpo_comm.cpp",line 270,column 3,is_stmt
;----------------------------------------------------------------------
; 271 | error = msg_open("tpo");                                               
; 272 | if(error != OSE_OK)                                                    
; 273 |       return -1;                                                       
; 275 |       sv_msg_open = 1;                                                 
; 276 |       s_prc_attr atr;                                                  
; 277 |       memset( &atr, 0, sizeof(atr) );                                  
; 278 |       atr.stack = 4096*3;                                              
; 279 |       prc_create( &Sv_Msg, NULL, 0, &atr );                            
; 281 |       #ifdef TPO7                                                      
; 282 |       #ifdef CHIP_6457                                                 
; 284 |       s_prc_attr atr1;                                                 
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+40,A3
           MVKH    .S1     ___syscall_tab+40,A3
           LDW     .D1T1   *A3,A3            ; |270| 
           MVKL    .S1     _Sv_Msg__FPv,A4   ; |270| 
           MVKH    .S1     _Sv_Msg__FPv,A4   ; |270| 
           ADDAW   .D2     SP,15,B6          ; |270| 
           ZERO    .L1     A6                ; |270| 
$C$DW$267	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$267, DW_AT_low_pc(0x00)
	.dwattr $C$DW$267, DW_AT_TI_call
	.dwattr $C$DW$267, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |270| 
           ZERO    .L2     B4                ; |270| 
           ADDKPC  .S2     $C$RL13,B3,3      ; |270| 
$C$RL13:   ; CALL OCCURS {A3} {0}            ; |270| 
	.dwpsn	file "tpo_comm.cpp",line 285,column 9,is_stmt
;----------------------------------------------------------------------
; 285 | memset( &atr1, 0, sizeof(atr1) );                                      
; 286 | atr1.stack = 4048;                                                     
;----------------------------------------------------------------------
;** --------------------------------------------------------------------------*
;**   BEGIN LOOP $C$L9
;** --------------------------------------------------------------------------*
$C$L9:    
$C$DW$L$_tpo_comm__FPvPc$4$B:
	.dwpsn	file "tpo_comm.cpp",line 287,column 5,is_stmt
;----------------------------------------------------------------------
; 287 | prc_create( &Read_Res_Fifo, NULL, 0, &atr1 );                          
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+388,A3
           MVKH    .S1     ___syscall_tab+388,A3
           LDW     .D1T1   *A3,A3            ; |287| 
           ADD     .D2     SP,28,B5          ; |287| 
           MVK     .S2     0x1388,B4         ; |287| 
           MV      .L1X    B5,A4             ; |287| 
           NOP             1
$C$DW$268	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$268, DW_AT_low_pc(0x00)
	.dwattr $C$DW$268, DW_AT_TI_call
	.dwattr $C$DW$268, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |287| 
           ADDKPC  .S2     $C$RL14,B3,4      ; |287| 
$C$RL14:   ; CALL OCCURS {A3} {0}            ; |287| 
           STW     .D2T1   A4,*+SP(12)       ; |287| 
	.dwpsn	file "tpo_comm.cpp",line 288,column 5,is_stmt
;----------------------------------------------------------------------
; 289 | #endif                                                                 
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(28),B0       ; |288| 
           NOP             4
   [ B0]   BNOP    .S1     $C$L10,5          ; |288| 
           ; BRANCHCC OCCURS {$C$L10}        ; |288| 
$C$DW$L$_tpo_comm__FPvPc$4$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_tpo_comm__FPvPc$5$B:
	.dwpsn	file "tpo_comm.cpp",line 290,column 2,is_stmt
;----------------------------------------------------------------------
; 290 | #endif                                                                 
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+48,A3
           MVKH    .S1     ___syscall_tab+48,A3
           LDW     .D1T1   *A3,A3            ; |290| 
           NOP             4
$C$DW$269	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$269, DW_AT_low_pc(0x00)
	.dwattr $C$DW$269, DW_AT_TI_call
	.dwattr $C$DW$269, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |290| 
           ADDKPC  .S2     $C$RL15,B3,4      ; |290| 
$C$RL15:   ; CALL OCCURS {A3} {0}            ; |290| 
	.dwpsn	file "tpo_comm.cpp",line 291,column 5,is_stmt
           BNOP    .S1     $C$L9,5           ; |291| 
           ; BRANCH OCCURS {$C$L9}           ; |291| 
$C$DW$L$_tpo_comm__FPvPc$5$E:
;** --------------------------------------------------------------------------*
$C$L10:    
$C$DW$L$_tpo_comm__FPvPc$6$B:
	.dwpsn	file "tpo_comm.cpp",line 293,column 5,is_stmt
;----------------------------------------------------------------------
; 294 | while(true)                                                            
;----------------------------------------------------------------------
           MV      .L2     B0,B4
           LDW     .D2T2   *+B4(20),B4       ; |293| 
           NOP             4
           CMPEQ   .L2     B4,4,B0           ; |293| 
   [ B0]   BNOP    .S1     $C$L11,5          ; |293| 
           ; BRANCHCC OCCURS {$C$L11}        ; |293| 
$C$DW$L$_tpo_comm__FPvPc$6$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_tpo_comm__FPvPc$7$B:
	.dwpsn	file "tpo_comm.cpp",line 295,column 7,is_stmt
           MVKL    .S2     0xd0026,B4
           MVKH    .S2     0xd0026,B4
           STW     .D2T2   B4,*+SP(20)       ; |295| 
	.dwpsn	file "tpo_comm.cpp",line 296,column 7,is_stmt
;----------------------------------------------------------------------
; 296 | error = msg_recv(&msg_desc, MSG_WAIT_5);                               
;----------------------------------------------------------------------
           MVK     .L2     1,B4              ; |296| 
           STW     .D2T2   B4,*+SP(24)       ; |296| 
	.dwpsn	file "tpo_comm.cpp",line 297,column 7,is_stmt
;----------------------------------------------------------------------
; 297 | if(msg_desc == NULL)                                                   
;----------------------------------------------------------------------
           MVKL    .S2     ___syscall_tab+384,B5
           MVKH    .S2     ___syscall_tab+384,B5
           LDW     .D2T2   *B5,B5            ; |297| 
           LDW     .D2T2   *+SP(28),B4       ; |297| 
           MVK     .L1     0x8,A6            ; |297| 
           NOP             2
$C$DW$270	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$270, DW_AT_low_pc(0x00)
	.dwattr $C$DW$270, DW_AT_TI_call
	.dwattr $C$DW$270, DW_AT_TI_indirect
           CALL    .S2     B5                ; |297| 
           LDW     .D2T1   *+B4(12),A4       ; |297| 
           ADDKPC  .S2     $C$RL16,B3,2      ; |297| 
           ADD     .D2     SP,20,B4          ; |297| 
$C$RL16:   ; CALL OCCURS {B5} {0}            ; |297| 
	.dwpsn	file "tpo_comm.cpp",line 298,column 7,is_stmt
           MVKL    .S1     ___syscall_tab+404,A3
           MVKH    .S1     ___syscall_tab+404,A3
           LDW     .D1T1   *A3,A3            ; |298| 
           LDW     .D2T1   *+SP(28),A4       ; |298| 
           NOP             3
$C$DW$271	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$271, DW_AT_low_pc(0x00)
	.dwattr $C$DW$271, DW_AT_TI_call
	.dwattr $C$DW$271, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |298| 
           ADDKPC  .S2     $C$RL17,B3,4      ; |298| 
$C$RL17:   ; CALL OCCURS {A3} {0}            ; |298| 
	.dwpsn	file "tpo_comm.cpp",line 299,column 7,is_stmt
;----------------------------------------------------------------------
; 299 | prc_yield();                                                           
; 300 | continue;                                                              
;----------------------------------------------------------------------
           BNOP    .S1     $C$L9,5           ; |299| 
           ; BRANCH OCCURS {$C$L9}           ; |299| 
$C$DW$L$_tpo_comm__FPvPc$7$E:
;** --------------------------------------------------------------------------*
$C$L11:    
$C$DW$L$_tpo_comm__FPvPc$8$B:
	.dwpsn	file "tpo_comm.cpp",line 301,column 5,is_stmt
           LDW     .D2T1   *+SP(28),A3       ; |301| 
           NOP             4
           LDW     .D1T1   *+A3(12),A3       ; |301| 
           NOP             4
           STW     .D2T1   A3,*+SP(16)       ; |301| 
	.dwpsn	file "tpo_comm.cpp",line 302,column 5,is_stmt
;----------------------------------------------------------------------
; 302 | if(msg_desc->length != sizeof(kdg_cmd))                                
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(28),B4       ; |302| 
           NOP             4
           LDW     .D2T2   *+B4(24),B4       ; |302| 
           NOP             4
           LDW     .D2T2   *B4,B4            ; |302| 
           NOP             4
           STW     .D2T2   B4,*+SP(20)       ; |302| 
	.dwpsn	file "tpo_comm.cpp",line 303,column 5,is_stmt
           MVKL    .S1     ___syscall_tab+404,A3
           MVKH    .S1     ___syscall_tab+404,A3
           LDW     .D1T1   *A3,A3            ; |303| 
           LDW     .D2T1   *+SP(28),A4       ; |303| 
           NOP             3
$C$DW$272	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$272, DW_AT_low_pc(0x00)
	.dwattr $C$DW$272, DW_AT_TI_call
	.dwattr $C$DW$272, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |303| 
           ADDKPC  .S2     $C$RL18,B3,4      ; |303| 
$C$RL18:   ; CALL OCCURS {A3} {0}            ; |303| 
	.dwpsn	file "tpo_comm.cpp",line 304,column 5,is_stmt
;----------------------------------------------------------------------
; 304 | cdg_error.cmd = ERROR_CMD;                                             
; 305 | cdg_error.ask = TPO_ERR;                                               
; 306 | msg_send(msg_desc->from, &cdg_error, sizeof(kdg_cmd_ask));             
; 307 | msg_free(msg_desc);                                                    
; 308 | continue;                                                              
;----------------------------------------------------------------------
           BNOP    .S1     $C$L42,5          ; |304| 
           ; BRANCH OCCURS {$C$L42}          ; |304| 
$C$DW$L$_tpo_comm__FPvPc$8$E:
;** --------------------------------------------------------------------------*
;** --------------------------------------------------------------------------*
$C$L12:    
$C$DW$L$_tpo_comm__FPvPc$10$B:
	.dwpsn	file "tpo_comm.cpp",line 310,column 3,is_stmt
;----------------------------------------------------------------------
; 310 | msg_from = msg_desc->from;                                             
;----------------------------------------------------------------------
           ZERO    .L2     B4                ; |310| 
           STW     .D2T2   B4,*+SP(24)       ; |310| 
	.dwpsn	file "tpo_comm.cpp",line 311,column 9,is_stmt
;----------------------------------------------------------------------
; 311 | cdg_error.cmd = ((kdg_cmd*)msg_desc->data)->cmd;                       
; 312 | msg_free(msg_desc);                                                    
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+384,A3
           MVKH    .S1     ___syscall_tab+384,A3
           LDW     .D1T1   *A3,A3            ; |311| 
           LDW     .D2T1   *+SP(16),A4       ; |311| 
           ADD     .D2     SP,20,B4          ; |311| 
           MVK     .L1     0x8,A6            ; |311| 
           NOP             1
$C$DW$273	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$273, DW_AT_low_pc(0x00)
	.dwattr $C$DW$273, DW_AT_TI_call
	.dwattr $C$DW$273, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |311| 
           ADDKPC  .S2     $C$RL19,B3,4      ; |311| 
$C$RL19:   ; CALL OCCURS {A3} {0}            ; |311| 
	.dwpsn	file "tpo_comm.cpp",line 313,column 9,is_stmt
;----------------------------------------------------------------------
; 313 | switch (cdg_error.cmd)                                                 
;----------------------------------------------------------------------
$C$DW$274	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$274, DW_AT_low_pc(0x00)
	.dwattr $C$DW$274, DW_AT_name("_Test_sialp__Fv")
	.dwattr $C$DW$274, DW_AT_TI_call
           CALL    .S1     _Test_sialp__Fv   ; |313| 
           ADDKPC  .S2     $C$RL20,B3,4      ; |313| 
$C$RL20:   ; CALL OCCURS {_Test_sialp__Fv} {0}  ; |313| 
	.dwpsn	file "tpo_comm.cpp",line 315,column 12,is_stmt
;----------------------------------------------------------------------
; 315 | //Тесты СИ АЛП:                                                        
; 316 | case START_SIALP:                                                      
; 318 |   //cdg_error.cmd = START_SIALP;                                       
;----------------------------------------------------------------------
           BNOP    .S1     $C$L9,5           ; |315| 
           ; BRANCH OCCURS {$C$L9}           ; |315| 
$C$DW$L$_tpo_comm__FPvPc$10$E:
;** --------------------------------------------------------------------------*
$C$L13:    
$C$DW$L$_tpo_comm__FPvPc$11$B:

$C$DW$275	.dwtag  DW_TAG_lexical_block, DW_AT_low_pc(0x00), DW_AT_high_pc(0x00)
$C$DW$276	.dwtag  DW_TAG_variable, DW_AT_name("result")
	.dwattr $C$DW$276, DW_AT_TI_symbol_name("_result")
	.dwattr $C$DW$276, DW_AT_type(*$C$DW$T$438)
	.dwattr $C$DW$276, DW_AT_location[DW_OP_breg31 80]
	.dwpsn	file "tpo_comm.cpp",line 319,column 3,is_stmt
;----------------------------------------------------------------------
; 319 | cdg_error.ask = TPO_OK;                                                
;----------------------------------------------------------------------
           ZERO    .L2     B4                ; |319| 
           STW     .D2T2   B4,*+SP(24)       ; |319| 
	.dwpsn	file "tpo_comm.cpp",line 320,column 9,is_stmt
;----------------------------------------------------------------------
; 320 | msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));                   
; 321 | //debug!!!!!!!!                                                        
; 322 | Test_sialp();                                                          
;----------------------------------------------------------------------
           MVKL    .S2     ___syscall_tab+384,B4
           MVKH    .S2     ___syscall_tab+384,B4
           LDW     .D2T2   *B4,B5            ; |320| 
           LDW     .D2T1   *+SP(16),A4       ; |320| 
           ADD     .D2     SP,20,B4          ; |320| 
           MVK     .L1     0x8,A6            ; |320| 
           NOP             1
$C$DW$277	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$277, DW_AT_low_pc(0x00)
	.dwattr $C$DW$277, DW_AT_TI_call
	.dwattr $C$DW$277, DW_AT_TI_indirect
           CALL    .S2     B5                ; |320| 
           ADDKPC  .S2     $C$RL21,B3,4      ; |320| 
$C$RL21:   ; CALL OCCURS {B5} {0}            ; |320| 
	.dwpsn	file "tpo_comm.cpp",line 324,column 3,is_stmt
;----------------------------------------------------------------------
; 324 | break;                                                                 
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+388,A3
           MVKH    .S1     ___syscall_tab+388,A3
           LDW     .D1T1   *A3,A3            ; |324| 
           ADD     .D2     SP,28,B5          ; |324| 
           MVK     .S2     0x2710,B4         ; |324| 
           MV      .L1X    B5,A4             ; |324| 
           NOP             1
$C$DW$278	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$278, DW_AT_low_pc(0x00)
	.dwattr $C$DW$278, DW_AT_TI_call
	.dwattr $C$DW$278, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |324| 
           ADDKPC  .S2     $C$RL22,B3,4      ; |324| 
$C$RL22:   ; CALL OCCURS {A3} {0}            ; |324| 
           STW     .D2T1   A4,*+SP(12)       ; |324| 
	.dwpsn	file "tpo_comm.cpp",line 325,column 6,is_stmt
;----------------------------------------------------------------------
; 325 | //                                                                     
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(28),B0       ; |325| 
           NOP             4
   [!B0]   BNOP    .S1     $C$L9,5           ; |325| 
           ; BRANCHCC OCCURS {$C$L9}         ; |325| 
$C$DW$L$_tpo_comm__FPvPc$11$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_tpo_comm__FPvPc$12$B:
	.dwpsn	file "tpo_comm.cpp",line 325,column 27,is_stmt
	.dwpsn	file "tpo_comm.cpp",line 326,column 6,is_stmt
;----------------------------------------------------------------------
; 326 | case N_TEST:                                                           
;----------------------------------------------------------------------
           MV      .L2     B0,B4
           LDW     .D2T2   *+B4(20),B4       ; |326| 
           MVK     .S2     60,B5             ; |326| 
           NOP             3
           CMPEQ   .L2     B4,B5,B0          ; |326| 
   [ B0]   BNOP    .S1     $C$L14,5          ; |326| 
           ; BRANCHCC OCCURS {$C$L14}        ; |326| 
$C$DW$L$_tpo_comm__FPvPc$12$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_tpo_comm__FPvPc$13$B:
	.dwpsn	file "tpo_comm.cpp",line 328,column 8,is_stmt
;----------------------------------------------------------------------
; 328 | cdg_error.ask = TPO_OK;                                                
;----------------------------------------------------------------------
           MVKL    .S2     0xd0026,B4
           MVKH    .S2     0xd0026,B4
           STW     .D2T2   B4,*+SP(20)       ; |328| 
	.dwpsn	file "tpo_comm.cpp",line 329,column 5,is_stmt
;----------------------------------------------------------------------
; 329 | msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));                   
;----------------------------------------------------------------------
           MVK     .L2     1,B4              ; |329| 
           STW     .D2T2   B4,*+SP(24)       ; |329| 
	.dwpsn	file "tpo_comm.cpp",line 330,column 8,is_stmt
           MVKL    .S2     ___syscall_tab+384,B5
           MVKH    .S2     ___syscall_tab+384,B5
           LDW     .D2T2   *B5,B5            ; |330| 
           LDW     .D2T2   *+SP(28),B4       ; |330| 
           MVK     .L1     0x8,A6            ; |330| 
           NOP             2
$C$DW$279	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$279, DW_AT_low_pc(0x00)
	.dwattr $C$DW$279, DW_AT_TI_call
	.dwattr $C$DW$279, DW_AT_TI_indirect
           CALL    .S2     B5                ; |330| 
           LDW     .D2T1   *+B4(12),A4       ; |330| 
           ADDKPC  .S2     $C$RL23,B3,2      ; |330| 
           ADD     .D2     SP,20,B4          ; |330| 
$C$RL23:   ; CALL OCCURS {B5} {0}            ; |330| 
	.dwpsn	file "tpo_comm.cpp",line 331,column 8,is_stmt
;----------------------------------------------------------------------
; 331 | kdg_rez_test result;                                                   
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+404,A3
           MVKH    .S1     ___syscall_tab+404,A3
           LDW     .D1T1   *A3,A3            ; |331| 
           LDW     .D2T1   *+SP(28),A4       ; |331| 
           NOP             3
$C$DW$280	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$280, DW_AT_low_pc(0x00)
	.dwattr $C$DW$280, DW_AT_TI_call
	.dwattr $C$DW$280, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |331| 
           ADDKPC  .S2     $C$RL24,B3,4      ; |331| 
$C$RL24:   ; CALL OCCURS {A3} {0}            ; |331| 
	.dwpsn	file "tpo_comm.cpp",line 332,column 8,is_stmt
;----------------------------------------------------------------------
; 333 | error = msg_recv(&msg_desc, MSG_WAIT_10);                              
;----------------------------------------------------------------------
           BNOP    .S1     $C$L9,5           ; |332| 
           ; BRANCH OCCURS {$C$L9}           ; |332| 
$C$DW$L$_tpo_comm__FPvPc$13$E:
;** --------------------------------------------------------------------------*
$C$L14:    
$C$DW$L$_tpo_comm__FPvPc$14$B:
	.dwpsn	file "tpo_comm.cpp",line 334,column 3,is_stmt
;----------------------------------------------------------------------
; 334 | if(msg_desc == NULL) continue;                                         
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(28),B4       ; |334| 
           ADDAD   .D2     SP,10,B5          ; |334| 
           MVK     .S1     0x3c,A6           ; |334| 
           MV      .L1X    B5,A4             ; |334| 
$C$DW$281	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$281, DW_AT_low_pc(0x00)
	.dwattr $C$DW$281, DW_AT_name("_memcpy")
	.dwattr $C$DW$281, DW_AT_TI_call
           CALL    .S1     _memcpy           ; |334| 
           LDW     .D2T2   *+B4(24),B4       ; |334| 
           ADDKPC  .S2     $C$RL25,B3,3      ; |334| 
$C$RL25:   ; CALL OCCURS {_memcpy} {0}       ; |334| 
	.dwpsn	file "tpo_comm.cpp",line 335,column 6,is_stmt
;----------------------------------------------------------------------
; 335 | if(msg_desc->length != sizeof(kdg_rez_test))                           
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+404,A3
           MVKH    .S1     ___syscall_tab+404,A3
           LDW     .D1T1   *A3,A3            ; |335| 
           LDW     .D2T1   *+SP(28),A4       ; |335| 
           NOP             3
$C$DW$282	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$282, DW_AT_low_pc(0x00)
	.dwattr $C$DW$282, DW_AT_TI_call
	.dwattr $C$DW$282, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |335| 
           ADDKPC  .S2     $C$RL26,B3,4      ; |335| 
$C$RL26:   ; CALL OCCURS {A3} {0}            ; |335| 
	.dwpsn	file "tpo_comm.cpp",line 337,column 9,is_stmt
;----------------------------------------------------------------------
; 337 | cdg_error.cmd = ERROR_CMD;                                             
;----------------------------------------------------------------------
$C$DW$283	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$283, DW_AT_low_pc(0x00)
	.dwattr $C$DW$283, DW_AT_name("_Start_Test_N__FP12kdg_rez_test")
	.dwattr $C$DW$283, DW_AT_TI_call
           CALL    .S1     _Start_Test_N__FP12kdg_rez_test ; |337| 
           ADDAD   .D2     SP,10,B4          ; |337| 
           ADDKPC  .S2     $C$RL27,B3,2      ; |337| 
           MV      .L1X    B4,A4             ; |337| 
$C$RL27:   ; CALL OCCURS {_Start_Test_N__FP12kdg_rez_test} {0}  ; |337| 
	.dwpsn	file "tpo_comm.cpp",line 338,column 3,is_stmt
;----------------------------------------------------------------------
; 338 | cdg_error.ask = TPO_ERR;                                               
;----------------------------------------------------------------------
           MVKL    .S2     0xd0008,B4
           MVKH    .S2     0xd0008,B4
           STW     .D2T2   B4,*+SP(80)       ; |338| 
	.dwpsn	file "tpo_comm.cpp",line 339,column 9,is_stmt
;----------------------------------------------------------------------
; 339 | msg_send(msg_desc->from, &cdg_error, sizeof(kdg_cmd_ask));             
; 340 | msg_free(msg_desc);                                                    
;----------------------------------------------------------------------
           MVKL    .S2     ___syscall_tab+384,B4
           MVKH    .S2     ___syscall_tab+384,B4
           LDW     .D2T2   *B4,B5            ; |339| 
           LDW     .D2T1   *+SP(16),A4       ; |339| 
           ADDAD   .D2     SP,10,B4          ; |339| 
           MVK     .S1     0x3c,A6           ; |339| 
           NOP             1
$C$DW$284	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$284, DW_AT_low_pc(0x00)
	.dwattr $C$DW$284, DW_AT_TI_call
	.dwattr $C$DW$284, DW_AT_TI_indirect
           CALL    .S2     B5                ; |339| 
           ADDKPC  .S2     $C$RL28,B3,4      ; |339| 
$C$RL28:   ; CALL OCCURS {B5} {0}            ; |339| 
	.dwendtag $C$DW$275

	.dwpsn	file "tpo_comm.cpp",line 341,column 12,is_stmt
;----------------------------------------------------------------------
; 341 | continue;                                                              
; 343 |   memcpy(&result, msg_desc->data, sizeof(kdg_rez_test));               
; 344 | msg_free(msg_desc);                                                    
;----------------------------------------------------------------------
           BNOP    .S1     $C$L9,5           ; |341| 
           ; BRANCH OCCURS {$C$L9}           ; |341| 
$C$DW$L$_tpo_comm__FPvPc$14$E:
;** --------------------------------------------------------------------------*
$C$L15:    
$C$DW$L$_tpo_comm__FPvPc$15$B:
	.dwpsn	file "tpo_comm.cpp",line 345,column 3,is_stmt
           MVKL    .S1     _Start_dozu_nagr,A4

           MVKH    .S1     _Start_dozu_nagr,A4
||         MVK     .L1     1,A3              ; |345| 

           STH     .D1T1   A3,*A4            ; |345| 
	.dwpsn	file "tpo_comm.cpp",line 346,column 3,is_stmt
;----------------------------------------------------------------------
; 346 | Start_Test_N(&result);                                                 
;----------------------------------------------------------------------
           MVKL    .S2     0xd000b,B4
           MVKH    .S2     0xd000b,B4
           STW     .D2T2   B4,*+SP(24)       ; |346| 
	.dwpsn	file "tpo_comm.cpp",line 347,column 9,is_stmt
;----------------------------------------------------------------------
; 347 | result.cmd = RES_N_TEST;                                               
; 348 | msg_send(msg_from, &result, sizeof(kdg_rez_test));                     
;----------------------------------------------------------------------
           MVKL    .S2     ___syscall_tab+384,B4
           MVKH    .S2     ___syscall_tab+384,B4
           LDW     .D2T2   *B4,B5            ; |347| 
           LDW     .D2T1   *+SP(16),A4       ; |347| 
           ADD     .D2     SP,20,B4          ; |347| 
           MVK     .L1     0x8,A6            ; |347| 
           NOP             1
$C$DW$285	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$285, DW_AT_low_pc(0x00)
	.dwattr $C$DW$285, DW_AT_TI_call
	.dwattr $C$DW$285, DW_AT_TI_indirect
           CALL    .S2     B5                ; |347| 
           ADDKPC  .S2     $C$RL29,B3,4      ; |347| 
$C$RL29:   ; CALL OCCURS {B5} {0}            ; |347| 
	.dwpsn	file "tpo_comm.cpp",line 349,column 3,is_stmt
;----------------------------------------------------------------------
; 350 | break;                                                                 
;----------------------------------------------------------------------
$C$DW$286	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$286, DW_AT_low_pc(0x00)
	.dwattr $C$DW$286, DW_AT_name("_memset")
	.dwattr $C$DW$286, DW_AT_TI_call
           CALL    .S1     _memset           ; |349| 
           MVKL    .S1     _gl_result,A4
           MVK     .S1     0x3c,A6           ; |349| 
           ADDKPC  .S2     $C$RL30,B3,1      ; |349| 

           MVKH    .S1     _gl_result,A4
||         ZERO    .L2     B4                ; |349| 

$C$RL30:   ; CALL OCCURS {_memset} {0}       ; |349| 
	.dwpsn	file "tpo_comm.cpp",line 351,column 3,is_stmt
;----------------------------------------------------------------------
; 351 | //                                                                     
;----------------------------------------------------------------------
$C$DW$287	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$287, DW_AT_low_pc(0x00)
	.dwattr $C$DW$287, DW_AT_name("_memset")
	.dwattr $C$DW$287, DW_AT_TI_call
           CALL    .S1     _memset           ; |351| 
           ADDAW   .D2     SP,15,B4          ; |351| 
           ADDKPC  .S2     $C$RL31,B3,2      ; |351| 

           MVK     .S1     0x14,A6           ; |351| 
||         MV      .L1X    B4,A4             ; |351| 
||         ZERO    .L2     B4                ; |351| 

$C$RL31:   ; CALL OCCURS {_memset} {0}       ; |351| 
	.dwpsn	file "tpo_comm.cpp",line 352,column 3,is_stmt
;----------------------------------------------------------------------
; 352 | case START_TEST_DOZU_NAGR:                                             
;----------------------------------------------------------------------
           MVK     .S2     12144,B4          ; |352| 
           STW     .D2T2   B4,*+SP(60)       ; |352| 
	.dwpsn	file "tpo_comm.cpp",line 353,column 3,is_stmt
;----------------------------------------------------------------------
; 354 | Start_dozu_nagr = 1;                                                   
; 355 | cdg_error.ask = START_TEST_DOZU_NAGR;                                  
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+40,A3
           MVKH    .S1     ___syscall_tab+40,A3
           LDW     .D1T1   *A3,A3            ; |353| 
           MVKL    .S1     _TestDOZU_Nagr__FPv,A4 ; |353| 
           MVKH    .S1     _TestDOZU_Nagr__FPv,A4 ; |353| 
           ADDAW   .D2     SP,15,B6          ; |353| 
           ZERO    .L1     A6                ; |353| 
$C$DW$288	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$288, DW_AT_low_pc(0x00)
	.dwattr $C$DW$288, DW_AT_TI_call
	.dwattr $C$DW$288, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |353| 
           ZERO    .L2     B4                ; |353| 
           ADDKPC  .S2     $C$RL32,B3,3      ; |353| 
$C$RL32:   ; CALL OCCURS {A3} {0}            ; |353| 
	.dwpsn	file "tpo_comm.cpp",line 356,column 12,is_stmt
;----------------------------------------------------------------------
; 356 | msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));                   
; 358 |         memset( &gl_result, 0, sizeof(gl_result) );                    
;----------------------------------------------------------------------
           BNOP    .S1     $C$L9,5           ; |356| 
           ; BRANCH OCCURS {$C$L9}           ; |356| 
$C$DW$L$_tpo_comm__FPvPc$15$E:
;** --------------------------------------------------------------------------*
$C$L16:    
$C$DW$L$_tpo_comm__FPvPc$16$B:

$C$DW$289	.dwtag  DW_TAG_lexical_block, DW_AT_low_pc(0x00), DW_AT_high_pc(0x00)
$C$DW$290	.dwtag  DW_TAG_variable, DW_AT_name("result")
	.dwattr $C$DW$290, DW_AT_TI_symbol_name("_result")
	.dwattr $C$DW$290, DW_AT_type(*$C$DW$T$438)
	.dwattr $C$DW$290, DW_AT_location[DW_OP_breg31 80]
	.dwpsn	file "tpo_comm.cpp",line 360,column 3,is_stmt
;----------------------------------------------------------------------
; 360 | memset( &atr, 0, sizeof(atr) );                                        
;----------------------------------------------------------------------
           MVKL    .S2     0xd000c,B4
           MVKH    .S2     0xd000c,B4
           STW     .D2T2   B4,*+SP(24)       ; |360| 
	.dwpsn	file "tpo_comm.cpp",line 361,column 9,is_stmt
;----------------------------------------------------------------------
; 361 | atr.stack = 4048*3;                                                    
; 362 | prc_create( &TestDOZU_Nagr, NULL, 0, &atr );                           
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+384,A3
           MVKH    .S1     ___syscall_tab+384,A3
           LDW     .D1T1   *A3,A3            ; |361| 
           LDW     .D2T1   *+SP(16),A4       ; |361| 
           ADD     .D2     SP,20,B4          ; |361| 
           MVK     .L1     0x8,A6            ; |361| 
           NOP             1
$C$DW$291	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$291, DW_AT_low_pc(0x00)
	.dwattr $C$DW$291, DW_AT_TI_call
	.dwattr $C$DW$291, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |361| 
           ADDKPC  .S2     $C$RL33,B3,4      ; |361| 
$C$RL33:   ; CALL OCCURS {A3} {0}            ; |361| 
	.dwpsn	file "tpo_comm.cpp",line 364,column 3,is_stmt
;----------------------------------------------------------------------
; 365 | break;                                                                 
;----------------------------------------------------------------------
$C$DW$292	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$292, DW_AT_low_pc(0x00)
	.dwattr $C$DW$292, DW_AT_name("__strasgi")
	.dwattr $C$DW$292, DW_AT_TI_call
           CALL    .S1     __strasgi         ; |364| 
           ADDAD   .D2     SP,10,B5          ; |364| 
           MVKL    .S2     _gl_result,B4
           MVKH    .S2     _gl_result,B4
           MV      .L1X    B5,A4             ; |364| 

           ADDKPC  .S2     $C$RL34,B3,0      ; |364| 
||         MVK     .S1     0x3c,A6           ; |364| 

$C$RL34:   ; CALL OCCURS {__strasgi} {0}     ; |364| 
	.dwpsn	file "tpo_comm.cpp",line 366,column 3,is_stmt
;----------------------------------------------------------------------
; 366 | //                                                                     
; 367 |     case RES_TEST_DOZU_NAGR:                                           
;----------------------------------------------------------------------
           MVKL    .S1     0xd000c,A3
           MVKH    .S1     0xd000c,A3
           STW     .D2T1   A3,*+SP(80)       ; |366| 
	.dwpsn	file "tpo_comm.cpp",line 368,column 4,is_stmt
;----------------------------------------------------------------------
; 369 | cdg_error.ask = RES_TEST_DOZU_NAGR;                                    
;----------------------------------------------------------------------
           MVKL    .S2     _gl_result+24,B4
           MVKH    .S2     _gl_result+24,B4
           LDW     .D2T2   *B4,B0            ; |368| 
           NOP             4
   [!B0]   BNOP    .S1     $C$L17,5          ; |368| 
           ; BRANCHCC OCCURS {$C$L17}        ; |368| 
$C$DW$L$_tpo_comm__FPvPc$16$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_tpo_comm__FPvPc$17$B:
	.dwpsn	file "tpo_comm.cpp",line 370,column 3,is_stmt
;----------------------------------------------------------------------
; 370 | msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));                   
;----------------------------------------------------------------------
           MV      .L1X    B4,A3
           LDW     .D1T1   *A3,A3            ; |370| 
           NOP             4
           STW     .D2T1   A3,*+SP(104)      ; |370| 
	.dwpsn	file "tpo_comm.cpp",line 371,column 3,is_stmt
;----------------------------------------------------------------------
; 372 | kdg_rez_test result;                                                   
;----------------------------------------------------------------------

           MV      .L2     B4,B5
||         ZERO    .S2     B4                ; |371| 

           STW     .D2T2   B4,*B5            ; |371| 
$C$DW$L$_tpo_comm__FPvPc$17$E:
;** --------------------------------------------------------------------------*
$C$L17:    
$C$DW$L$_tpo_comm__FPvPc$18$B:
	.dwpsn	file "tpo_comm.cpp",line 373,column 9,is_stmt
;----------------------------------------------------------------------
; 373 | memcpy(&result, &gl_result, sizeof(kdg_rez_test));                     
; 375 | result.cmd = RES_TEST_DOZU_NAGR;                                       
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+384,A3
           MVKH    .S1     ___syscall_tab+384,A3
           LDW     .D1T1   *A3,A3            ; |373| 
           LDW     .D2T1   *+SP(16),A4       ; |373| 
           ADDAD   .D2     SP,10,B4          ; |373| 
           MVK     .S1     0x3c,A6           ; |373| 
           NOP             1
$C$DW$293	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$293, DW_AT_low_pc(0x00)
	.dwattr $C$DW$293, DW_AT_TI_call
	.dwattr $C$DW$293, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |373| 
           ADDKPC  .S2     $C$RL35,B3,4      ; |373| 
$C$RL35:   ; CALL OCCURS {A3} {0}            ; |373| 
	.dwendtag $C$DW$289

	.dwpsn	file "tpo_comm.cpp",line 376,column 12,is_stmt
;----------------------------------------------------------------------
; 377 | if(gl_result.err != TPO_OK)                                            
; 379 | result.err = gl_result.err;                                            
;----------------------------------------------------------------------
           BNOP    .S1     $C$L9,5           ; |376| 
           ; BRANCH OCCURS {$C$L9}           ; |376| 
$C$DW$L$_tpo_comm__FPvPc$18$E:
;** --------------------------------------------------------------------------*
$C$L18:    
$C$DW$L$_tpo_comm__FPvPc$19$B:
	.dwpsn	file "tpo_comm.cpp",line 380,column 3,is_stmt
;----------------------------------------------------------------------
; 380 | gl_result.err = 0;                                                     
;----------------------------------------------------------------------
           MVKL    .S1     _Start_dozu_nagr,A4

           MVKH    .S1     _Start_dozu_nagr,A4
||         ZERO    .L1     A3                ; |380| 

           STH     .D1T1   A3,*A4            ; |380| 
	.dwpsn	file "tpo_comm.cpp",line 381,column 3,is_stmt
           MVKL    .S2     0xd000d,B4
           MVKH    .S2     0xd000d,B4
           STW     .D2T2   B4,*+SP(24)       ; |381| 
	.dwpsn	file "tpo_comm.cpp",line 382,column 9,is_stmt
;----------------------------------------------------------------------
; 382 | msg_send(msg_from, &result, sizeof(kdg_rez_test));                     
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+384,A3
           MVKH    .S1     ___syscall_tab+384,A3
           LDW     .D1T1   *A3,A3            ; |382| 
           LDW     .D2T1   *+SP(16),A4       ; |382| 
           ADD     .D2     SP,20,B4          ; |382| 
           MVK     .L1     0x8,A6            ; |382| 
           NOP             1
$C$DW$294	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$294, DW_AT_low_pc(0x00)
	.dwattr $C$DW$294, DW_AT_TI_call
	.dwattr $C$DW$294, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |382| 
           ADDKPC  .S2     $C$RL36,B3,4      ; |382| 
$C$RL36:   ; CALL OCCURS {A3} {0}            ; |382| 
	.dwpsn	file "tpo_comm.cpp",line 384,column 12,is_stmt
;----------------------------------------------------------------------
; 385 | break;                                                                 
; 386 | //                                                                     
; 387 |     case STOP_TEST_DOZU_NAGR:                                          
;----------------------------------------------------------------------
           BNOP    .S1     $C$L9,5           ; |384| 
           ; BRANCH OCCURS {$C$L9}           ; |384| 
$C$DW$L$_tpo_comm__FPvPc$19$E:
;** --------------------------------------------------------------------------*
$C$L19:    
$C$DW$L$_tpo_comm__FPvPc$20$B:

$C$DW$295	.dwtag  DW_TAG_lexical_block, DW_AT_low_pc(0x00), DW_AT_high_pc(0x00)
$C$DW$296	.dwtag  DW_TAG_variable, DW_AT_name("result")
	.dwattr $C$DW$296, DW_AT_TI_symbol_name("_result")
	.dwattr $C$DW$296, DW_AT_type(*$C$DW$T$438)
	.dwattr $C$DW$296, DW_AT_location[DW_OP_breg31 80]
	.dwpsn	file "tpo_comm.cpp",line 388,column 3,is_stmt
           MVKL    .S1     0xd0010,A3
           MVKH    .S1     0xd0010,A3
           STW     .D2T1   A3,*+SP(24)       ; |388| 
	.dwpsn	file "tpo_comm.cpp",line 389,column 9,is_stmt
;----------------------------------------------------------------------
; 389 | Start_dozu_nagr = 0;                                                   
; 390 | cdg_error.ask = STOP_TEST_DOZU_NAGR;                                   
; 391 | msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));                   
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+384,A3
           MVKH    .S1     ___syscall_tab+384,A3
           LDW     .D1T1   *A3,A3            ; |389| 
           LDW     .D2T1   *+SP(16),A4       ; |389| 
           ADD     .D2     SP,20,B4          ; |389| 
           MVK     .L1     0x8,A6            ; |389| 
           NOP             1
$C$DW$297	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$297, DW_AT_low_pc(0x00)
	.dwattr $C$DW$297, DW_AT_TI_call
	.dwattr $C$DW$297, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |389| 
           ADDKPC  .S2     $C$RL37,B3,4      ; |389| 
$C$RL37:   ; CALL OCCURS {A3} {0}            ; |389| 
	.dwpsn	file "tpo_comm.cpp",line 392,column 3,is_stmt
;----------------------------------------------------------------------
; 393 | break;                                                                 
;----------------------------------------------------------------------
$C$DW$298	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$298, DW_AT_low_pc(0x00)
	.dwattr $C$DW$298, DW_AT_name("_memset")
	.dwattr $C$DW$298, DW_AT_TI_call
           CALL    .S1     _memset           ; |392| 
           ADDAD   .D2     SP,10,B4          ; |392| 
           ADDKPC  .S2     $C$RL38,B3,2      ; |392| 

           MVK     .S1     0x3c,A6           ; |392| 
||         MV      .L1X    B4,A4             ; |392| 
||         ZERO    .L2     B4                ; |392| 

$C$RL38:   ; CALL OCCURS {_memset} {0}       ; |392| 
	.dwpsn	file "tpo_comm.cpp",line 394,column 3,is_stmt
;----------------------------------------------------------------------
; 394 | //                                                                     
;----------------------------------------------------------------------
           MVKL    .S2     0xd0010,B4
           MVKH    .S2     0xd0010,B4
           STW     .D2T2   B4,*+SP(80)       ; |394| 
	.dwpsn	file "tpo_comm.cpp",line 395,column 3,is_stmt
;----------------------------------------------------------------------
; 395 | case RES_TEST_ROM_CP0:                                                 
;----------------------------------------------------------------------
$C$DW$299	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$299, DW_AT_low_pc(0x00)
	.dwattr $C$DW$299, DW_AT_name("_ReadDARAM0__FUsPvT1")
	.dwattr $C$DW$299, DW_AT_TI_call
           CALL    .S1     _ReadDARAM0__FUsPvT1 ; |395| 
           ADDKPC  .S2     $C$RL39,B3,3      ; |395| 

           ZERO    .L1     A4                ; |395| 
||         MVK     .S1     0x4,A6            ; |395| 
||         ADDAW   .D2     SP,21,B4          ; |395| 

$C$RL39:   ; CALL OCCURS {_ReadDARAM0__FUsPvT1} {0}  ; |395| 
	.dwpsn	file "tpo_comm.cpp",line 396,column 3,is_stmt
$C$DW$300	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$300, DW_AT_low_pc(0x00)
	.dwattr $C$DW$300, DW_AT_name("_ReadDARAM0__FUsPvT1")
	.dwattr $C$DW$300, DW_AT_TI_call
           CALL    .S1     _ReadDARAM0__FUsPvT1 ; |396| 
           ADDKPC  .S2     $C$RL40,B3,3      ; |396| 

           MVK     .L1     0x4,A4            ; |396| 
||         ADDAD   .D2     SP,11,B4          ; |396| 
||         MVK     .S1     0x4,A6            ; |396| 

$C$RL40:   ; CALL OCCURS {_ReadDARAM0__FUsPvT1} {0}  ; |396| 
	.dwpsn	file "tpo_comm.cpp",line 397,column 3,is_stmt
;----------------------------------------------------------------------
; 397 | cdg_error.ask = RES_TEST_ROM_CP0;                                      
;----------------------------------------------------------------------
$C$DW$301	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$301, DW_AT_low_pc(0x00)
	.dwattr $C$DW$301, DW_AT_name("_ReadDARAM0__FUsPvT1")
	.dwattr $C$DW$301, DW_AT_TI_call
           CALL    .S1     _ReadDARAM0__FUsPvT1 ; |397| 
           ADDKPC  .S2     $C$RL41,B3,3      ; |397| 

           MVK     .L1     0x8,A4            ; |397| 
||         ADDAW   .D2     SP,23,B4          ; |397| 
||         MVK     .S1     0x4,A6            ; |397| 

$C$RL41:   ; CALL OCCURS {_ReadDARAM0__FUsPvT1} {0}  ; |397| 
	.dwpsn	file "tpo_comm.cpp",line 398,column 3,is_stmt
;----------------------------------------------------------------------
; 398 | msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));                   
;----------------------------------------------------------------------
$C$DW$302	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$302, DW_AT_low_pc(0x00)
	.dwattr $C$DW$302, DW_AT_name("_ReadDARAM0__FUsPvT1")
	.dwattr $C$DW$302, DW_AT_TI_call
           CALL    .S1     _ReadDARAM0__FUsPvT1 ; |398| 
           ADDKPC  .S2     $C$RL42,B3,3      ; |398| 

           MVK     .L1     0xc,A4            ; |398| 
||         ADDAD   .D2     SP,12,B4          ; |398| 
||         MVK     .S1     0x4,A6            ; |398| 

$C$RL42:   ; CALL OCCURS {_ReadDARAM0__FUsPvT1} {0}  ; |398| 
	.dwpsn	file "tpo_comm.cpp",line 400,column 4,is_stmt
;----------------------------------------------------------------------
; 400 | kdg_rez_test result;                                                   
; 401 | memset(&result, 0, sizeof(kdg_rez_test));                              
;----------------------------------------------------------------------
           MVKL    .S2     _gl_result+24,B4
           MVKH    .S2     _gl_result+24,B4
           LDW     .D2T2   *B4,B0            ; |400| 
           NOP             4
   [!B0]   BNOP    .S1     $C$L20,5          ; |400| 
           ; BRANCHCC OCCURS {$C$L20}        ; |400| 
$C$DW$L$_tpo_comm__FPvPc$20$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_tpo_comm__FPvPc$21$B:
	.dwpsn	file "tpo_comm.cpp",line 402,column 3,is_stmt
           MV      .L1X    B4,A3
           LDW     .D1T1   *A3,A3            ; |402| 
           NOP             4
           STW     .D2T1   A3,*+SP(104)      ; |402| 
	.dwpsn	file "tpo_comm.cpp",line 403,column 3,is_stmt
;----------------------------------------------------------------------
; 403 | result.cmd = RES_TEST_ROM_CP0;                                         
; 404 | ReadDARAM0(0,&result.n_test,4);                                        
;----------------------------------------------------------------------

           MV      .L2     B4,B5
||         ZERO    .S2     B4                ; |403| 

           STW     .D2T2   B4,*B5            ; |403| 
$C$DW$L$_tpo_comm__FPvPc$21$E:
;** --------------------------------------------------------------------------*
$C$L20:    
$C$DW$L$_tpo_comm__FPvPc$22$B:
	.dwpsn	file "tpo_comm.cpp",line 405,column 9,is_stmt
;----------------------------------------------------------------------
; 405 | ReadDARAM0(4,&result.rez,4);                                           
; 406 | ReadDARAM0(8,&result.adrr,4);                                          
; 407 | ReadDARAM0(0xc,&result.data,4);                                        
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+384,A3
           MVKH    .S1     ___syscall_tab+384,A3
           LDW     .D1T1   *A3,A3            ; |405| 
           LDW     .D2T1   *+SP(16),A4       ; |405| 
           ADDAD   .D2     SP,10,B4          ; |405| 
           MVK     .S1     0x3c,A6           ; |405| 
           NOP             1
$C$DW$303	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$303, DW_AT_low_pc(0x00)
	.dwattr $C$DW$303, DW_AT_TI_call
	.dwattr $C$DW$303, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |405| 
           ADDKPC  .S2     $C$RL43,B3,4      ; |405| 
$C$RL43:   ; CALL OCCURS {A3} {0}            ; |405| 
	.dwendtag $C$DW$295

	.dwpsn	file "tpo_comm.cpp",line 408,column 12,is_stmt
;----------------------------------------------------------------------
; 409 | if(gl_result.err != TPO_OK)                                            
; 411 | result.err = gl_result.err;                                            
;----------------------------------------------------------------------
           BNOP    .S1     $C$L9,5           ; |408| 
           ; BRANCH OCCURS {$C$L9}           ; |408| 
$C$DW$L$_tpo_comm__FPvPc$22$E:
;** --------------------------------------------------------------------------*
$C$L21:    
$C$DW$L$_tpo_comm__FPvPc$23$B:

$C$DW$304	.dwtag  DW_TAG_lexical_block, DW_AT_low_pc(0x00), DW_AT_high_pc(0x00)
$C$DW$305	.dwtag  DW_TAG_variable, DW_AT_name("result")
	.dwattr $C$DW$305, DW_AT_TI_symbol_name("_result")
	.dwattr $C$DW$305, DW_AT_type(*$C$DW$T$438)
	.dwattr $C$DW$305, DW_AT_location[DW_OP_breg31 80]
	.dwpsn	file "tpo_comm.cpp",line 412,column 3,is_stmt
;----------------------------------------------------------------------
; 412 | gl_result.err = 0;                                                     
;----------------------------------------------------------------------
           MVKL    .S1     0xd0011,A3
           MVKH    .S1     0xd0011,A3
           STW     .D2T1   A3,*+SP(24)       ; |412| 
	.dwpsn	file "tpo_comm.cpp",line 413,column 9,is_stmt
;----------------------------------------------------------------------
; 414 | msg_send(msg_from, &result, sizeof(kdg_rez_test));                     
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+384,A3
           MVKH    .S1     ___syscall_tab+384,A3
           LDW     .D1T1   *A3,A3            ; |413| 
           LDW     .D2T1   *+SP(16),A4       ; |413| 
           ADD     .D2     SP,20,B4          ; |413| 
           MVK     .L1     0x8,A6            ; |413| 
           NOP             1
$C$DW$306	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$306, DW_AT_low_pc(0x00)
	.dwattr $C$DW$306, DW_AT_TI_call
	.dwattr $C$DW$306, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |413| 
           ADDKPC  .S2     $C$RL44,B3,4      ; |413| 
$C$RL44:   ; CALL OCCURS {A3} {0}            ; |413| 
	.dwpsn	file "tpo_comm.cpp",line 416,column 3,is_stmt
;----------------------------------------------------------------------
; 417 | break;                                                                 
;----------------------------------------------------------------------
$C$DW$307	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$307, DW_AT_low_pc(0x00)
	.dwattr $C$DW$307, DW_AT_name("_memset")
	.dwattr $C$DW$307, DW_AT_TI_call
           CALL    .S1     _memset           ; |416| 
           ADDAD   .D2     SP,10,B4          ; |416| 
           ADDKPC  .S2     $C$RL45,B3,2      ; |416| 

           MVK     .S1     0x3c,A6           ; |416| 
||         MV      .L1X    B4,A4             ; |416| 
||         ZERO    .L2     B4                ; |416| 

$C$RL45:   ; CALL OCCURS {_memset} {0}       ; |416| 
	.dwpsn	file "tpo_comm.cpp",line 418,column 3,is_stmt
;----------------------------------------------------------------------
; 418 | //                                                                     
;----------------------------------------------------------------------
           MVKL    .S2     0xd0011,B4
           MVKH    .S2     0xd0011,B4
           STW     .D2T2   B4,*+SP(80)       ; |418| 
	.dwpsn	file "tpo_comm.cpp",line 419,column 3,is_stmt
;----------------------------------------------------------------------
; 419 | case RES_TEST_ROM_CP1:                                                 
;----------------------------------------------------------------------
$C$DW$308	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$308, DW_AT_low_pc(0x00)
	.dwattr $C$DW$308, DW_AT_name("_ReadDARAM1__FUsPvT1")
	.dwattr $C$DW$308, DW_AT_TI_call
           CALL    .S1     _ReadDARAM1__FUsPvT1 ; |419| 
           ADDKPC  .S2     $C$RL46,B3,3      ; |419| 

           ZERO    .L1     A4                ; |419| 
||         MVK     .S1     0x4,A6            ; |419| 
||         ADDAW   .D2     SP,21,B4          ; |419| 

$C$RL46:   ; CALL OCCURS {_ReadDARAM1__FUsPvT1} {0}  ; |419| 
	.dwpsn	file "tpo_comm.cpp",line 420,column 3,is_stmt
$C$DW$309	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$309, DW_AT_low_pc(0x00)
	.dwattr $C$DW$309, DW_AT_name("_ReadDARAM1__FUsPvT1")
	.dwattr $C$DW$309, DW_AT_TI_call
           CALL    .S1     _ReadDARAM1__FUsPvT1 ; |420| 
           ADDKPC  .S2     $C$RL47,B3,3      ; |420| 

           MVK     .L1     0x4,A4            ; |420| 
||         ADDAD   .D2     SP,11,B4          ; |420| 
||         MVK     .S1     0x4,A6            ; |420| 

$C$RL47:   ; CALL OCCURS {_ReadDARAM1__FUsPvT1} {0}  ; |420| 
	.dwpsn	file "tpo_comm.cpp",line 421,column 3,is_stmt
;----------------------------------------------------------------------
; 421 | cdg_error.ask = RES_TEST_ROM_CP1;                                      
;----------------------------------------------------------------------
$C$DW$310	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$310, DW_AT_low_pc(0x00)
	.dwattr $C$DW$310, DW_AT_name("_ReadDARAM1__FUsPvT1")
	.dwattr $C$DW$310, DW_AT_TI_call
           CALL    .S1     _ReadDARAM1__FUsPvT1 ; |421| 
           ADDKPC  .S2     $C$RL48,B3,3      ; |421| 

           MVK     .L1     0x8,A4            ; |421| 
||         ADDAW   .D2     SP,23,B4          ; |421| 
||         MVK     .S1     0x4,A6            ; |421| 

$C$RL48:   ; CALL OCCURS {_ReadDARAM1__FUsPvT1} {0}  ; |421| 
	.dwpsn	file "tpo_comm.cpp",line 422,column 3,is_stmt
;----------------------------------------------------------------------
; 422 | msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));                   
;----------------------------------------------------------------------
$C$DW$311	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$311, DW_AT_low_pc(0x00)
	.dwattr $C$DW$311, DW_AT_name("_ReadDARAM1__FUsPvT1")
	.dwattr $C$DW$311, DW_AT_TI_call
           CALL    .S1     _ReadDARAM1__FUsPvT1 ; |422| 
           ADDKPC  .S2     $C$RL49,B3,3      ; |422| 

           MVK     .L1     0xc,A4            ; |422| 
||         ADDAD   .D2     SP,12,B4          ; |422| 
||         MVK     .S1     0x4,A6            ; |422| 

$C$RL49:   ; CALL OCCURS {_ReadDARAM1__FUsPvT1} {0}  ; |422| 
	.dwpsn	file "tpo_comm.cpp",line 424,column 4,is_stmt
;----------------------------------------------------------------------
; 424 | kdg_rez_test result;                                                   
; 425 | memset(&result, 0, sizeof(kdg_rez_test));                              
;----------------------------------------------------------------------
           MVKL    .S2     _gl_result+24,B4
           MVKH    .S2     _gl_result+24,B4
           LDW     .D2T2   *B4,B0            ; |424| 
           NOP             4
   [!B0]   BNOP    .S1     $C$L22,5          ; |424| 
           ; BRANCHCC OCCURS {$C$L22}        ; |424| 
$C$DW$L$_tpo_comm__FPvPc$23$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_tpo_comm__FPvPc$24$B:
	.dwpsn	file "tpo_comm.cpp",line 426,column 3,is_stmt
           MV      .L1X    B4,A3
           LDW     .D1T1   *A3,A3            ; |426| 
           NOP             4
           STW     .D2T1   A3,*+SP(104)      ; |426| 
	.dwpsn	file "tpo_comm.cpp",line 427,column 3,is_stmt
;----------------------------------------------------------------------
; 427 | result.cmd = RES_TEST_ROM_CP1;                                         
; 428 | ReadDARAM1(0,&result.n_test,4);                                        
;----------------------------------------------------------------------

           MV      .L2     B4,B5
||         ZERO    .S2     B4                ; |427| 

           STW     .D2T2   B4,*B5            ; |427| 
$C$DW$L$_tpo_comm__FPvPc$24$E:
;** --------------------------------------------------------------------------*
$C$L22:    
$C$DW$L$_tpo_comm__FPvPc$25$B:
	.dwpsn	file "tpo_comm.cpp",line 429,column 9,is_stmt
;----------------------------------------------------------------------
; 429 | ReadDARAM1(4,&result.rez,4);                                           
; 430 | ReadDARAM1(8,&result.adrr,4);                                          
; 431 | ReadDARAM1(0xc,&result.data,4);                                        
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+384,A3
           MVKH    .S1     ___syscall_tab+384,A3
           LDW     .D1T1   *A3,A3            ; |429| 
           LDW     .D2T1   *+SP(16),A4       ; |429| 
           ADDAD   .D2     SP,10,B4          ; |429| 
           MVK     .S1     0x3c,A6           ; |429| 
           NOP             1
$C$DW$312	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$312, DW_AT_low_pc(0x00)
	.dwattr $C$DW$312, DW_AT_TI_call
	.dwattr $C$DW$312, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |429| 
           ADDKPC  .S2     $C$RL50,B3,4      ; |429| 
$C$RL50:   ; CALL OCCURS {A3} {0}            ; |429| 
	.dwendtag $C$DW$304

	.dwpsn	file "tpo_comm.cpp",line 432,column 12,is_stmt
;----------------------------------------------------------------------
; 433 | if(gl_result.err != TPO_OK)                                            
; 435 | result.err = gl_result.err;                                            
;----------------------------------------------------------------------
           BNOP    .S1     $C$L9,5           ; |432| 
           ; BRANCH OCCURS {$C$L9}           ; |432| 
$C$DW$L$_tpo_comm__FPvPc$25$E:
;** --------------------------------------------------------------------------*
$C$L23:    
$C$DW$L$_tpo_comm__FPvPc$26$B:

$C$DW$313	.dwtag  DW_TAG_lexical_block, DW_AT_low_pc(0x00), DW_AT_high_pc(0x00)
$C$DW$314	.dwtag  DW_TAG_variable, DW_AT_name("CrTestRes")
	.dwattr $C$DW$314, DW_AT_TI_symbol_name("_CrTestRes")
	.dwattr $C$DW$314, DW_AT_type(*$C$DW$T$740)
	.dwattr $C$DW$314, DW_AT_location[DW_OP_breg31 80]
	.dwpsn	file "tpo_comm.cpp",line 436,column 3,is_stmt
;----------------------------------------------------------------------
; 436 | gl_result.err = 0;                                                     
;----------------------------------------------------------------------
           MVKL    .S2     0xd0014,B4
           MVKH    .S2     0xd0014,B4
           STW     .D2T2   B4,*+SP(24)       ; |436| 
	.dwpsn	file "tpo_comm.cpp",line 437,column 9,is_stmt
;----------------------------------------------------------------------
; 438 | msg_send(msg_from, &result, sizeof(kdg_rez_test));                     
;----------------------------------------------------------------------
           MVKL    .S2     ___syscall_tab+384,B4
           MVKH    .S2     ___syscall_tab+384,B4
           LDW     .D2T2   *B4,B5            ; |437| 
           LDW     .D2T1   *+SP(16),A4       ; |437| 
           ADD     .D2     SP,20,B4          ; |437| 
           MVK     .L1     0x8,A6            ; |437| 
           NOP             1
$C$DW$315	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$315, DW_AT_low_pc(0x00)
	.dwattr $C$DW$315, DW_AT_TI_call
	.dwattr $C$DW$315, DW_AT_TI_indirect
           CALL    .S2     B5                ; |437| 
           ADDKPC  .S2     $C$RL51,B3,4      ; |437| 
$C$RL51:   ; CALL OCCURS {B5} {0}            ; |437| 
	.dwpsn	file "tpo_comm.cpp",line 440,column 3,is_stmt
;----------------------------------------------------------------------
; 441 | break;                                                                 
;----------------------------------------------------------------------
$C$DW$316	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$316, DW_AT_low_pc(0x00)
	.dwattr $C$DW$316, DW_AT_name("_memset")
	.dwattr $C$DW$316, DW_AT_TI_call
           CALL    .S1     _memset           ; |440| 
           ADDAD   .D2     SP,10,B4          ; |440| 
           ADDKPC  .S2     $C$RL52,B3,2      ; |440| 

           MVK     .S1     0x30,A6           ; |440| 
||         MV      .L1X    B4,A4             ; |440| 
||         ZERO    .L2     B4                ; |440| 

$C$RL52:   ; CALL OCCURS {_memset} {0}       ; |440| 
	.dwpsn	file "tpo_comm.cpp",line 442,column 3,is_stmt
;----------------------------------------------------------------------
; 442 | //                                                                     
;----------------------------------------------------------------------
$C$DW$317	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$317, DW_AT_low_pc(0x00)
	.dwattr $C$DW$317, DW_AT_name("_ReadDARAM0__FUsPvT1")
	.dwattr $C$DW$317, DW_AT_TI_call
           CALL    .S1     _ReadDARAM0__FUsPvT1 ; |442| 
           ADDKPC  .S2     $C$RL53,B3,3      ; |442| 

           ZERO    .L1     A4                ; |442| 
||         ADDAD   .D2     SP,10,B4          ; |442| 
||         MVK     .S1     0x18,A6           ; |442| 

$C$RL53:   ; CALL OCCURS {_ReadDARAM0__FUsPvT1} {0}  ; |442| 
	.dwpsn	file "tpo_comm.cpp",line 443,column 3,is_stmt
;----------------------------------------------------------------------
; 443 | case RES_TEST_CR_CH:                                                   
;----------------------------------------------------------------------
$C$DW$318	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$318, DW_AT_low_pc(0x00)
	.dwattr $C$DW$318, DW_AT_name("_ReadDARAM1__FUsPvT1")
	.dwattr $C$DW$318, DW_AT_TI_call
           CALL    .S1     _ReadDARAM1__FUsPvT1 ; |443| 
           ADDKPC  .S2     $C$RL54,B3,3      ; |443| 

           ZERO    .L1     A4                ; |443| 
||         ADDAD   .D2     SP,13,B4          ; |443| 
||         MVK     .S1     0x18,A6           ; |443| 

$C$RL54:   ; CALL OCCURS {_ReadDARAM1__FUsPvT1} {0}  ; |443| 
	.dwpsn	file "tpo_comm.cpp",line 445,column 9,is_stmt
;----------------------------------------------------------------------
; 445 | cdg_error.ask = RES_TEST_CR_CH;                                        
; 446 | msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));                   
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+384,A3
           MVKH    .S1     ___syscall_tab+384,A3
           LDW     .D1T1   *A3,A3            ; |445| 
           LDW     .D2T1   *+SP(16),A4       ; |445| 
           ADDAD   .D2     SP,10,B4          ; |445| 
           MVK     .S1     0x30,A6           ; |445| 
           NOP             1
$C$DW$319	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$319, DW_AT_low_pc(0x00)
	.dwattr $C$DW$319, DW_AT_TI_call
	.dwattr $C$DW$319, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |445| 
           ADDKPC  .S2     $C$RL55,B3,4      ; |445| 
$C$RL55:   ; CALL OCCURS {A3} {0}            ; |445| 
	.dwendtag $C$DW$313

	.dwpsn	file "tpo_comm.cpp",line 448,column 12,is_stmt
;----------------------------------------------------------------------
; 448 | CryptErrors CrTestRes[2];                                              
; 449 | memset(CrTestRes, 0, sizeof(CryptErrors)*2);                           
; 451 | ReadDARAM0(0,&CrTestRes[0],sizeof(CryptErrors));                       
; 452 | ReadDARAM1(0,&CrTestRes[1],sizeof(CryptErrors));                       
;----------------------------------------------------------------------
           BNOP    .S1     $C$L9,5           ; |448| 
           ; BRANCH OCCURS {$C$L9}           ; |448| 
$C$DW$L$_tpo_comm__FPvPc$26$E:
;** --------------------------------------------------------------------------*
$C$L24:    
$C$DW$L$_tpo_comm__FPvPc$27$B:

$C$DW$320	.dwtag  DW_TAG_lexical_block, DW_AT_low_pc(0x00), DW_AT_high_pc(0x00)
$C$DW$321	.dwtag  DW_TAG_variable, DW_AT_name("recb")
	.dwattr $C$DW$321, DW_AT_TI_symbol_name("_recb")
	.dwattr $C$DW$321, DW_AT_type(*$C$DW$T$684)
	.dwattr $C$DW$321, DW_AT_location[DW_OP_breg31 80]
$C$DW$322	.dwtag  DW_TAG_variable, DW_AT_name("result")
	.dwattr $C$DW$322, DW_AT_TI_symbol_name("_result")
	.dwattr $C$DW$322, DW_AT_type(*$C$DW$T$719)
	.dwattr $C$DW$322, DW_AT_location[DW_OP_breg31 480]
$C$DW$323	.dwtag  DW_TAG_variable, DW_AT_name("gotov")
	.dwattr $C$DW$323, DW_AT_TI_symbol_name("_gotov")
	.dwattr $C$DW$323, DW_AT_type(*$C$DW$T$438)
	.dwattr $C$DW$323, DW_AT_location[DW_OP_breg31 496]
	.dwpsn	file "tpo_comm.cpp",line 453,column 3,is_stmt
;----------------------------------------------------------------------
; 454 | msg_send(msg_from, CrTestRes, sizeof(CryptErrors)*2);                  
;----------------------------------------------------------------------
$C$DW$324	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$324, DW_AT_low_pc(0x00)
	.dwattr $C$DW$324, DW_AT_name("_memset")
	.dwattr $C$DW$324, DW_AT_TI_call
           CALL    .S1     _memset           ; |453| 
           ADDAD   .D2     SP,10,B4          ; |453| 
           ADDKPC  .S2     $C$RL56,B3,2      ; |453| 

           MVK     .S1     0x190,A6          ; |453| 
||         MV      .L1X    B4,A4             ; |453| 
||         ZERO    .L2     B4                ; |453| 

$C$RL56:   ; CALL OCCURS {_memset} {0}       ; |453| 
	.dwpsn	file "tpo_comm.cpp",line 455,column 3,is_stmt
           MVKL    .S2     0xd0003,B4
           MVKH    .S2     0xd0003,B4
           STW     .D2T2   B4,*+SP(24)       ; |455| 
	.dwpsn	file "tpo_comm.cpp",line 457,column 3,is_stmt
;----------------------------------------------------------------------
; 457 | break;                                                                 
;----------------------------------------------------------------------
$C$DW$325	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$325, DW_AT_low_pc(0x00)
	.dwattr $C$DW$325, DW_AT_name("_memset")
	.dwattr $C$DW$325, DW_AT_TI_call
           CALL    .S1     _memset           ; |457| 
           MVK     .S2     496,B4            ; |457| 
           ADD     .L2     B4,SP,B4          ; |457| 
           ADDKPC  .S2     $C$RL57,B3,1      ; |457| 

           MVK     .S1     0x3c,A6           ; |457| 
||         MV      .L1X    B4,A4             ; |457| 
||         ZERO    .L2     B4                ; |457| 

$C$RL57:   ; CALL OCCURS {_memset} {0}       ; |457| 
	.dwpsn	file "tpo_comm.cpp",line 458,column 9,is_stmt
;----------------------------------------------------------------------
; 458 | //                                                                     
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+384,A3
           MVKH    .S1     ___syscall_tab+384,A3
           LDW     .D1T1   *A3,A3            ; |458| 
           LDW     .D2T1   *+SP(16),A4       ; |458| 
           ADD     .D2     SP,20,B4          ; |458| 
           MVK     .L1     0x8,A6            ; |458| 
           NOP             1
$C$DW$326	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$326, DW_AT_low_pc(0x00)
	.dwattr $C$DW$326, DW_AT_TI_call
	.dwattr $C$DW$326, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |458| 
           ADDKPC  .S2     $C$RL58,B3,4      ; |458| 
$C$RL58:   ; CALL OCCURS {A3} {0}            ; |458| 
	.dwpsn	file "tpo_comm.cpp",line 459,column 3,is_stmt
;----------------------------------------------------------------------
; 459 | case GOTOV_PP:                                                         
; 461 |       uint8 recb[400];                                                 
;----------------------------------------------------------------------
           MVKL    .S1     0xd0008,A3
           MVKH    .S1     0xd0008,A3
           STW     .D2T1   A3,*+SP(496)      ; |459| 
	.dwpsn	file "tpo_comm.cpp",line 462,column 3,is_stmt
;----------------------------------------------------------------------
; 462 | memset(recb, 0, sizeof(recb));                                         
;----------------------------------------------------------------------
$C$DW$327	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$327, DW_AT_low_pc(0x00)
	.dwattr $C$DW$327, DW_AT_name("_ReadDARAM0__FUsPvT1")
	.dwattr $C$DW$327, DW_AT_TI_call
           CALL    .S1     _ReadDARAM0__FUsPvT1 ; |462| 
           MVK     .S2     480,B4            ; |462| 
           ADDKPC  .S2     $C$RL59,B3,2      ; |462| 

           ADD     .L2     B4,SP,B4          ; |462| 
||         MVK     .S1     0xf00,A4          ; |462| 
||         MVK     .L1     0x8,A6            ; |462| 

$C$RL59:   ; CALL OCCURS {_ReadDARAM0__FUsPvT1} {0}  ; |462| 
	.dwpsn	file "tpo_comm.cpp",line 463,column 3,is_stmt
;----------------------------------------------------------------------
; 463 | uint32 result[2][2];                                                   
;----------------------------------------------------------------------
$C$DW$328	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$328, DW_AT_low_pc(0x00)
	.dwattr $C$DW$328, DW_AT_name("_ReadDARAM1__FUsPvT1")
	.dwattr $C$DW$328, DW_AT_TI_call
           CALL    .S1     _ReadDARAM1__FUsPvT1 ; |463| 
           MVK     .S1     488,A3            ; |463| 
           ADDKPC  .S2     $C$RL60,B3,2      ; |463| 

           MVK     .S1     0xf00,A4          ; |463| 
||         MVK     .L1     0x8,A6            ; |463| 
||         ADD     .L2X    A3,SP,B4          ; |463| 

$C$RL60:   ; CALL OCCURS {_ReadDARAM1__FUsPvT1} {0}  ; |463| 
	.dwpsn	file "tpo_comm.cpp",line 464,column 3,is_stmt
;----------------------------------------------------------------------
; 464 | cdg_error.ask = GOTOV_PP;                                              
; 465 | kdg_rez_test gotov;                                                    
; 466 | memset(&gotov, 0, sizeof(kdg_rez_test));                               
; 467 | msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));                   
; 468 | gotov.cmd = RES_N_TEST;                                                
; 470 | #ifndef TPO7                                                           
; 471 | ReadDARAM0(0xF00,&result[0],8);                                        
; 472 | ReadDARAM1(0xF00,&result[1],8);                                        
; 473 | if((result[0][1] == 0x12345678) | (result[1][1] == 0x12345678))        
; 475 | #else                                                                  
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(484),B5      ; |464| 
           LDW     .D2T2   *+SP(492),B4      ; |464| 
           MVKL    .S2     0x12345678,B7
           MVKH    .S2     0x12345678,B7
           NOP             1
           CMPEQ   .L2     B5,B7,B5          ; |464| 
           CMPEQ   .L2     B4,B7,B4          ; |464| 
           OR      .L2     B4,B5,B0          ; |464| 
   [!B0]   BNOP    .S1     $C$L25,5          ; |464| 
           ; BRANCHCC OCCURS {$C$L25}        ; |464| 
$C$DW$L$_tpo_comm__FPvPc$27$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_tpo_comm__FPvPc$28$B:
	.dwpsn	file "tpo_comm.cpp",line 476,column 3,is_stmt
;----------------------------------------------------------------------
; 476 | uint16  res12 = FIFO_outIsReady();                                     
;----------------------------------------------------------------------
           MVK     .S2     100,B4            ; |476| 
           STW     .D2T2   B4,*+SP(500)      ; |476| 
	.dwpsn	file "tpo_comm.cpp",line 477,column 3,is_stmt
;----------------------------------------------------------------------
; 477 | if(res12 != 0)                                                         
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(480),B4      ; |477| 
           NOP             4
           STW     .D2T2   B4,*+SP(512)      ; |477| 
	.dwpsn	file "tpo_comm.cpp",line 478,column 3,is_stmt
;----------------------------------------------------------------------
; 479 | FIFO_StartReadPacket(&recb,0, 8 + 20); //20 ???? 8-0                   
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(488),B4      ; |478| 
           NOP             4
           STW     .D2T2   B4,*+SP(516)      ; |478| 
	.dwpsn	file "tpo_comm.cpp",line 480,column 3,is_stmt
;----------------------------------------------------------------------
; 480 | sleep_m(100);                                                          
; 481 | memcpy(&result[0],&recb[20],8);                                        
; 482 | memcpy(&result[1],&check_buf[20],8);                                   
; 483 | FIFO_EndReadPacket();                                                  
; 484 | #endif                                                                 
;----------------------------------------------------------------------
           BNOP    .S1     $C$L26,5          ; |480| 
           ; BRANCH OCCURS {$C$L26}          ; |480| 
$C$DW$L$_tpo_comm__FPvPc$28$E:
;** --------------------------------------------------------------------------*
$C$L25:    
$C$DW$L$_tpo_comm__FPvPc$29$B:
	.dwpsn	file "tpo_comm.cpp",line 485,column 3,is_stmt
;----------------------------------------------------------------------
; 485 | gotov.n_test = CIKL;                                                   
;----------------------------------------------------------------------
           MVK     .S2     101,B4            ; |485| 
           STW     .D2T2   B4,*+SP(500)      ; |485| 
	.dwpsn	file "tpo_comm.cpp",line 486,column 3,is_stmt
;----------------------------------------------------------------------
; 486 | gotov.data  = result[0][0];                                            
;----------------------------------------------------------------------
           ZERO    .L2     B4                ; |486| 
           STW     .D2T2   B4,*+SP(512)      ; |486| 
	.dwpsn	file "tpo_comm.cpp",line 487,column 3,is_stmt
;----------------------------------------------------------------------
; 487 | gotov.data1 = result[1][0];                                            
; 491 | //еще не закончен цикл                                                 
; 492 | else                                                                   
; 494 | gotov.n_test = CIKL_NOT_READY;                                         
; 495 | gotov.data  = 0;                                                       
; 496 | gotov.data1 = 0;                                                       
;----------------------------------------------------------------------
           STW     .D2T2   B4,*+SP(516)      ; |487| 
$C$DW$L$_tpo_comm__FPvPc$29$E:
;** --------------------------------------------------------------------------*
$C$L26:    
$C$DW$L$_tpo_comm__FPvPc$30$B:
	.dwpsn	file "tpo_comm.cpp",line 497,column 9,is_stmt
           MVKL    .S1     ___syscall_tab+384,A3
           MVKH    .S1     ___syscall_tab+384,A3
           LDW     .D1T1   *A3,A3            ; |497| 
           LDW     .D2T1   *+SP(16),A4       ; |497| 
           MVK     .S2     496,B4            ; |497| 
           ADD     .L2     B4,SP,B4          ; |497| 
           MVK     .S1     0x3c,A6           ; |497| 
$C$DW$329	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$329, DW_AT_low_pc(0x00)
	.dwattr $C$DW$329, DW_AT_TI_call
	.dwattr $C$DW$329, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |497| 
           ADDKPC  .S2     $C$RL61,B3,4      ; |497| 
$C$RL61:   ; CALL OCCURS {A3} {0}            ; |497| 
	.dwendtag $C$DW$320

	.dwpsn	file "tpo_comm.cpp",line 500,column 12,is_stmt
           BNOP    .S1     $C$L9,5           ; |500| 
           ; BRANCH OCCURS {$C$L9}           ; |500| 
$C$DW$L$_tpo_comm__FPvPc$30$E:
;** --------------------------------------------------------------------------*
$C$L27:    
$C$DW$L$_tpo_comm__FPvPc$31$B:

$C$DW$330	.dwtag  DW_TAG_lexical_block, DW_AT_low_pc(0x00), DW_AT_high_pc(0x00)
$C$DW$331	.dwtag  DW_TAG_variable, DW_AT_name("buf")
	.dwattr $C$DW$331, DW_AT_TI_symbol_name("_buf")
	.dwattr $C$DW$331, DW_AT_type(*$C$DW$T$722)
	.dwattr $C$DW$331, DW_AT_location[DW_OP_breg31 80]
	.dwpsn	file "tpo_comm.cpp",line 504,column 3,is_stmt
           MVKL    .S2     0xd0019,B4
           MVKH    .S2     0xd0019,B4
           STW     .D2T2   B4,*+SP(24)       ; |504| 
	.dwpsn	file "tpo_comm.cpp",line 506,column 3,is_stmt
;----------------------------------------------------------------------
; 506 | msg_send(msg_from, &gotov, sizeof(kdg_rez_test));                      
; 509 | break;                                                                 
; 511 |   case START_TEST_MOVE:                                                
; 513 |         cdg_error.ask = START_TEST_MOVE;                               
; 514 |         uint32 buf[LEN_MOVE/4];                                        
; 515 |         memset(buf, 0x55, sizeof(buf));                                
;----------------------------------------------------------------------
$C$DW$332	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$332, DW_AT_low_pc(0x00)
	.dwattr $C$DW$332, DW_AT_name("_memset")
	.dwattr $C$DW$332, DW_AT_TI_call
           CALL    .S1     _memset           ; |506| 
           ADDAD   .D2     SP,10,B5          ; |506| 
           MVK     .S2     0x55,B4           ; |506| 
           MV      .L1X    B5,A4             ; |506| 
           ADDKPC  .S2     $C$RL62,B3,0      ; |506| 
           MVK     .S1     0x600,A6          ; |506| 
$C$RL62:   ; CALL OCCURS {_memset} {0}       ; |506| 
	.dwpsn	file "tpo_comm.cpp",line 529,column 3,is_stmt
$C$DW$333	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$333, DW_AT_low_pc(0x00)
	.dwattr $C$DW$333, DW_AT_name("_WriteDARAM__FUsPvT1")
	.dwattr $C$DW$333, DW_AT_TI_call
           CALL    .S1     _WriteDARAM__FUsPvT1 ; |529| 
           ADDKPC  .S2     $C$RL63,B3,3      ; |529| 

           ZERO    .L1     A4                ; |529| 
||         ADDAD   .D2     SP,10,B4          ; |529| 
||         MVK     .S1     0x600,A6          ; |529| 

$C$RL63:   ; CALL OCCURS {_WriteDARAM__FUsPvT1} {0}  ; |529| 
	.dwpsn	file "tpo_comm.cpp",line 530,column 3,is_stmt
$C$DW$334	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$334, DW_AT_low_pc(0x00)
	.dwattr $C$DW$334, DW_AT_name("_WriteDARAM__FUsPvT1")
	.dwattr $C$DW$334, DW_AT_TI_call
           CALL    .S1     _WriteDARAM__FUsPvT1 ; |530| 
           MVK     .S1     0x600,A4          ; |530| 
           ADDKPC  .S2     $C$RL64,B3,2      ; |530| 

           ADDAD   .D2     SP,10,B4          ; |530| 
||         MVK     .S1     0x600,A6          ; |530| 

$C$RL64:   ; CALL OCCURS {_WriteDARAM__FUsPvT1} {0}  ; |530| 
	.dwpsn	file "tpo_comm.cpp",line 532,column 3,is_stmt
$C$DW$335	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$335, DW_AT_low_pc(0x00)
	.dwattr $C$DW$335, DW_AT_name("_memset")
	.dwattr $C$DW$335, DW_AT_TI_call
           CALL    .S1     _memset           ; |532| 
           MVKL    .S2     _gl_result,B4
           MVKH    .S2     _gl_result,B4
           ADDKPC  .S2     $C$RL65,B3,1      ; |532| 

           MVK     .S1     0x3c,A6           ; |532| 
||         MV      .L1X    B4,A4             ; |532| 
||         ZERO    .L2     B4                ; |532| 

$C$RL65:   ; CALL OCCURS {_memset} {0}       ; |532| 
	.dwpsn	file "tpo_comm.cpp",line 533,column 9,is_stmt
           MVKL    .S1     ___syscall_tab+384,A3
           MVKH    .S1     ___syscall_tab+384,A3
           LDW     .D1T1   *A3,A3            ; |533| 
           LDW     .D2T1   *+SP(16),A4       ; |533| 
           ADD     .D2     SP,20,B4          ; |533| 
           MVK     .L1     0x8,A6            ; |533| 
           NOP             1
$C$DW$336	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$336, DW_AT_low_pc(0x00)
	.dwattr $C$DW$336, DW_AT_TI_call
	.dwattr $C$DW$336, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |533| 
           ADDKPC  .S2     $C$RL66,B3,4      ; |533| 
$C$RL66:   ; CALL OCCURS {A3} {0}            ; |533| 
	.dwendtag $C$DW$330

	.dwpsn	file "tpo_comm.cpp",line 536,column 12,is_stmt
;----------------------------------------------------------------------
; 538 | WriteDARAM(0, buf, sizeof(buf));                                       
; 539 | WriteDARAM(sizeof(buf), buf, sizeof(buf));                             
;----------------------------------------------------------------------
           BNOP    .S1     $C$L9,5           ; |536| 
           ; BRANCH OCCURS {$C$L9}           ; |536| 
$C$DW$L$_tpo_comm__FPvPc$31$E:
;** --------------------------------------------------------------------------*
$C$L28:    
$C$DW$L$_tpo_comm__FPvPc$32$B:

$C$DW$337	.dwtag  DW_TAG_lexical_block, DW_AT_low_pc(0x00), DW_AT_high_pc(0x00)
$C$DW$338	.dwtag  DW_TAG_variable, DW_AT_name("result")
	.dwattr $C$DW$338, DW_AT_TI_symbol_name("_result")
	.dwattr $C$DW$338, DW_AT_type(*$C$DW$T$443)
	.dwattr $C$DW$338, DW_AT_location[DW_OP_breg31 80]
	.dwpsn	file "tpo_comm.cpp",line 541,column 3,is_stmt
;----------------------------------------------------------------------
; 541 | memset(&gl_result, 0, sizeof(gl_result));                              
;----------------------------------------------------------------------
           MVKL    .S1     0xd001e,A3
           MVKH    .S1     0xd001e,A3
           STW     .D2T1   A3,*+SP(24)       ; |541| 
	.dwpsn	file "tpo_comm.cpp",line 542,column 9,is_stmt
;----------------------------------------------------------------------
; 542 | msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));                   
; 545 | break;                                                                 
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+384,A3
           MVKH    .S1     ___syscall_tab+384,A3
           LDW     .D1T1   *A3,A3            ; |542| 
           LDW     .D2T1   *+SP(16),A4       ; |542| 
           ADD     .D2     SP,20,B4          ; |542| 
           MVK     .L1     0x8,A6            ; |542| 
           NOP             1
$C$DW$339	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$339, DW_AT_low_pc(0x00)
	.dwattr $C$DW$339, DW_AT_TI_call
	.dwattr $C$DW$339, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |542| 
           ADDKPC  .S2     $C$RL67,B3,4      ; |542| 
$C$RL67:   ; CALL OCCURS {A3} {0}            ; |542| 
	.dwpsn	file "tpo_comm.cpp",line 546,column 3,is_stmt
           MVKL    .S2     0xd001e,B4
           MVKH    .S2     0xd001e,B4
           STW     .D2T2   B4,*+SP(80)       ; |546| 
	.dwpsn	file "tpo_comm.cpp",line 547,column 3,is_stmt
           MVKL    .S2     _gl_result+4,B4
           MVKH    .S2     _gl_result+4,B4
           LDW     .D2T2   *B4,B4            ; |547| 
           NOP             4
           STW     .D2T2   B4,*+SP(84)       ; |547| 
	.dwpsn	file "tpo_comm.cpp",line 548,column 3,is_stmt
;----------------------------------------------------------------------
; 548 | case RES_TEST_MOVE:                                                    
;----------------------------------------------------------------------
           MVKL    .S1     _gl_result+16,A3
           MVKH    .S1     _gl_result+16,A3
           LDW     .D1T1   *A3,A3            ; |548| 
           NOP             4
           STW     .D2T1   A3,*+SP(88)       ; |548| 
	.dwpsn	file "tpo_comm.cpp",line 549,column 3,is_stmt
;----------------------------------------------------------------------
; 550 | cdg_error.ask = RES_TEST_MOVE;                                         
;----------------------------------------------------------------------
           MVKL    .S2     _gl_result+20,B4
           MVKH    .S2     _gl_result+20,B4
           LDW     .D2T2   *B4,B4            ; |549| 
           NOP             4
           STW     .D2T2   B4,*+SP(92)       ; |549| 
	.dwpsn	file "tpo_comm.cpp",line 551,column 9,is_stmt
;----------------------------------------------------------------------
; 551 | msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));                   
; 553 |         rez_test result;                                               
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+384,A3
           MVKH    .S1     ___syscall_tab+384,A3
           LDW     .D1T1   *A3,A3            ; |551| 
           LDW     .D2T1   *+SP(16),A4       ; |551| 
           MVK     .S1     0x10,A6           ; |551| 
           ADDAD   .D2     SP,10,B4          ; |551| 
           NOP             1
$C$DW$340	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$340, DW_AT_low_pc(0x00)
	.dwattr $C$DW$340, DW_AT_TI_call
	.dwattr $C$DW$340, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |551| 
           ADDKPC  .S2     $C$RL68,B3,4      ; |551| 
$C$RL68:   ; CALL OCCURS {A3} {0}            ; |551| 
	.dwendtag $C$DW$337

	.dwpsn	file "tpo_comm.cpp",line 554,column 12,is_stmt
;----------------------------------------------------------------------
; 555 | result.cmd = RES_TEST_MOVE;                                            
; 556 | result.n_test = gl_result.n_test;                                      
; 557 | result.rez0 = gl_result.data;                                          
; 558 | result.rez1 = gl_result.data1;                                         
;----------------------------------------------------------------------
           BNOP    .S1     $C$L9,5           ; |554| 
           ; BRANCH OCCURS {$C$L9}           ; |554| 
$C$DW$L$_tpo_comm__FPvPc$32$E:
;** --------------------------------------------------------------------------*
$C$L29:    
$C$DW$L$_tpo_comm__FPvPc$33$B:

$C$DW$341	.dwtag  DW_TAG_lexical_block, DW_AT_low_pc(0x00), DW_AT_high_pc(0x00)
$C$DW$342	.dwtag  DW_TAG_variable, DW_AT_name("result")
	.dwattr $C$DW$342, DW_AT_TI_symbol_name("_result")
	.dwattr $C$DW$342, DW_AT_type(*$C$DW$T$438)
	.dwattr $C$DW$342, DW_AT_location[DW_OP_breg31 80]
$C$DW$343	.dwtag  DW_TAG_variable, DW_AT_name("result1")
	.dwattr $C$DW$343, DW_AT_TI_symbol_name("_result1")
	.dwattr $C$DW$343, DW_AT_type(*$C$DW$T$438)
	.dwattr $C$DW$343, DW_AT_location[DW_OP_breg31 140]
$C$DW$344	.dwtag  DW_TAG_variable, DW_AT_name("res12")
	.dwattr $C$DW$344, DW_AT_TI_symbol_name("_res12")
	.dwattr $C$DW$344, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$344, DW_AT_location[DW_OP_breg31 200]
$C$DW$345	.dwtag  DW_TAG_variable, DW_AT_name("recb")
	.dwattr $C$DW$345, DW_AT_TI_symbol_name("_recb")
	.dwattr $C$DW$345, DW_AT_type(*$C$DW$T$684)
	.dwattr $C$DW$345, DW_AT_location[DW_OP_breg31 208]
	.dwpsn	file "tpo_comm.cpp",line 560,column 3,is_stmt
;----------------------------------------------------------------------
; 560 | msg_send(msg_from, &result, sizeof(result));                           
;----------------------------------------------------------------------
           MVKL    .S1     0xd0020,A3
           MVKH    .S1     0xd0020,A3
           STW     .D2T1   A3,*+SP(24)       ; |560| 
	.dwpsn	file "tpo_comm.cpp",line 561,column 9,is_stmt
;----------------------------------------------------------------------
; 563 | break;                                                                 
;----------------------------------------------------------------------
           MVKL    .S2     ___syscall_tab+384,B4
           MVKH    .S2     ___syscall_tab+384,B4
           LDW     .D2T2   *B4,B5            ; |561| 
           LDW     .D2T1   *+SP(16),A4       ; |561| 
           ADD     .D2     SP,20,B4          ; |561| 
           MVK     .L1     0x8,A6            ; |561| 
           NOP             1
$C$DW$346	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$346, DW_AT_low_pc(0x00)
	.dwattr $C$DW$346, DW_AT_TI_call
	.dwattr $C$DW$346, DW_AT_TI_indirect
           CALL    .S2     B5                ; |561| 
           ADDKPC  .S2     $C$RL69,B3,4      ; |561| 
$C$RL69:   ; CALL OCCURS {B5} {0}            ; |561| 
	.dwpsn	file "tpo_comm.cpp",line 564,column 3,is_stmt
;----------------------------------------------------------------------
; 565 | case GET_RES_FROM_DOZU:                                                
;----------------------------------------------------------------------
$C$DW$347	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$347, DW_AT_low_pc(0x00)
	.dwattr $C$DW$347, DW_AT_name("_memset")
	.dwattr $C$DW$347, DW_AT_TI_call
           CALL    .S1     _memset           ; |564| 
           ADDAD   .D2     SP,10,B4          ; |564| 
           ADDKPC  .S2     $C$RL70,B3,2      ; |564| 

           MVK     .S1     0x3c,A6           ; |564| 
||         MV      .L1X    B4,A4             ; |564| 
||         ZERO    .L2     B4                ; |564| 

$C$RL70:   ; CALL OCCURS {_memset} {0}       ; |564| 
	.dwpsn	file "tpo_comm.cpp",line 566,column 3,is_stmt
$C$DW$348	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$348, DW_AT_low_pc(0x00)
	.dwattr $C$DW$348, DW_AT_name("_memset")
	.dwattr $C$DW$348, DW_AT_TI_call
           CALL    .S1     _memset           ; |566| 
           MVK     .S2     140,B4            ; |566| 
           ADD     .L2     B4,SP,B4          ; |566| 
           ADDKPC  .S2     $C$RL71,B3,1      ; |566| 

           MVK     .S1     0x3c,A6           ; |566| 
||         MV      .L1X    B4,A4             ; |566| 
||         ZERO    .L2     B4                ; |566| 

$C$RL71:   ; CALL OCCURS {_memset} {0}       ; |566| 
	.dwpsn	file "tpo_comm.cpp",line 567,column 10,is_stmt
           ZERO    .L1     A3                ; |567| 
           STH     .D2T1   A3,*+SP(200)      ; |567| 
	.dwpsn	file "tpo_comm.cpp",line 569,column 3,is_stmt
;----------------------------------------------------------------------
; 569 | cdg_error.ask = GET_RES_FROM_DOZU;                                     
; 570 | msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));                   
;----------------------------------------------------------------------
$C$DW$349	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$349, DW_AT_low_pc(0x00)
	.dwattr $C$DW$349, DW_AT_name("_memset")
	.dwattr $C$DW$349, DW_AT_TI_call
           CALL    .S1     _memset           ; |569| 
           ADDAD   .D2     SP,26,B4          ; |569| 
           ADDKPC  .S2     $C$RL72,B3,2      ; |569| 

           MVK     .S1     0x190,A6          ; |569| 
||         MV      .L1X    B4,A4             ; |569| 
||         ZERO    .L2     B4                ; |569| 

$C$RL72:   ; CALL OCCURS {_memset} {0}       ; |569| 
	.dwpsn	file "tpo_comm.cpp",line 571,column 3,is_stmt
;----------------------------------------------------------------------
; 572 | kdg_rez_test result;                                                   
; 573 | memset(&result, 0, sizeof(kdg_rez_test));                              
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+252,A3
           MVKH    .S1     ___syscall_tab+252,A3
           LDW     .D1T1   *A3,A3            ; |571| 
           MVK     .S1     0x64,A4           ; |571| 
           NOP             3
$C$DW$350	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$350, DW_AT_low_pc(0x00)
	.dwattr $C$DW$350, DW_AT_TI_call
	.dwattr $C$DW$350, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |571| 
           ADDKPC  .S2     $C$RL73,B3,4      ; |571| 
$C$RL73:   ; CALL OCCURS {A3} {0}            ; |571| 
	.dwpsn	file "tpo_comm.cpp",line 574,column 3,is_stmt
;----------------------------------------------------------------------
; 574 | kdg_rez_test result1;                                                  
;----------------------------------------------------------------------
$C$DW$351	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$351, DW_AT_low_pc(0x00)
	.dwattr $C$DW$351, DW_AT_name("_ReadDARAM0__FUsPvT1")
	.dwattr $C$DW$351, DW_AT_TI_call
           CALL    .S1     _ReadDARAM0__FUsPvT1 ; |574| 
           ADDKPC  .S2     $C$RL74,B3,3      ; |574| 

           ADDAD   .D2     SP,10,B4          ; |574| 
||         MVK     .S1     0x3c,A6           ; |574| 
||         ZERO    .L1     A4                ; |574| 

$C$RL74:   ; CALL OCCURS {_ReadDARAM0__FUsPvT1} {0}  ; |574| 
	.dwpsn	file "tpo_comm.cpp",line 575,column 9,is_stmt
;----------------------------------------------------------------------
; 575 | memset(&result1, 0, sizeof(kdg_rez_test));                             
; 576 | uint16 res12=0;                                                        
;----------------------------------------------------------------------
           MVKL    .S2     ___syscall_tab+384,B4
           MVKH    .S2     ___syscall_tab+384,B4
           LDW     .D2T2   *B4,B5            ; |575| 
           LDW     .D2T1   *+SP(16),A4       ; |575| 
           ADDAD   .D2     SP,10,B4          ; |575| 
           MVK     .S1     0x3c,A6           ; |575| 
           NOP             1
$C$DW$352	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$352, DW_AT_low_pc(0x00)
	.dwattr $C$DW$352, DW_AT_TI_call
	.dwattr $C$DW$352, DW_AT_TI_indirect
           CALL    .S2     B5                ; |575| 
           ADDKPC  .S2     $C$RL75,B3,4      ; |575| 
$C$RL75:   ; CALL OCCURS {B5} {0}            ; |575| 
	.dwpsn	file "tpo_comm.cpp",line 577,column 3,is_stmt
;----------------------------------------------------------------------
; 577 | uint8 recb[400];                                                       
;----------------------------------------------------------------------
$C$DW$353	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$353, DW_AT_low_pc(0x00)
	.dwattr $C$DW$353, DW_AT_name("_ReadDARAM1__FUsPvT1")
	.dwattr $C$DW$353, DW_AT_TI_call
           CALL    .S1     _ReadDARAM1__FUsPvT1 ; |577| 
           MVK     .S2     140,B4            ; |577| 
           ADDKPC  .S2     $C$RL76,B3,2      ; |577| 

           ADD     .L2     B4,SP,B4          ; |577| 
||         ZERO    .L1     A4                ; |577| 
||         MVK     .S1     0x3c,A6           ; |577| 

$C$RL76:   ; CALL OCCURS {_ReadDARAM1__FUsPvT1} {0}  ; |577| 
	.dwpsn	file "tpo_comm.cpp",line 578,column 9,is_stmt
;----------------------------------------------------------------------
; 578 | memset(recb, 0, sizeof(recb));                                         
; 580 | sleep_m(100);                                                          
; 582 | #ifndef TPO7                                                           
; 583 | ReadDARAM0(0,&result, sizeof(kdg_rez_test));                           
; 584 | msg_send(msg_from, &result, sizeof(result));                           
; 586 | ReadDARAM1(0,&result1, sizeof(kdg_rez_test));                          
; 587 | msg_send(msg_from, &result, sizeof(result));                           
; 588 | #else                                                                  
; 590 | res12 = FIFO_outIsReady();                                             
; 592 | FIFO_StartReadPacket(&recb,0, sizeof(kdg_rez_test)+20); //20 ???? 8-0  
; 593 | sleep_m(100);                                                          
; 594 | memcpy(&result,&recb[20],sizeof(kdg_rez_test));                        
; 595 | memcpy(&result1,&check_buf[20],sizeof(kdg_rez_test));                  
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+384,A3
           MVKH    .S1     ___syscall_tab+384,A3
           LDW     .D1T1   *A3,A3            ; |578| 
           LDW     .D2T1   *+SP(16),A4       ; |578| 
           ADDAD   .D2     SP,10,B4          ; |578| 
           MVK     .S1     0x3c,A6           ; |578| 
           NOP             1
$C$DW$354	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$354, DW_AT_low_pc(0x00)
	.dwattr $C$DW$354, DW_AT_TI_call
	.dwattr $C$DW$354, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |578| 
           ADDKPC  .S2     $C$RL77,B3,4      ; |578| 
$C$RL77:   ; CALL OCCURS {A3} {0}            ; |578| 
	.dwendtag $C$DW$341

	.dwpsn	file "tpo_comm.cpp",line 596,column 12,is_stmt
;----------------------------------------------------------------------
; 596 | FIFO_EndReadPacket();                                                  
; 598 | msg_send(msg_from, &result, sizeof(result));                           
; 599 | msg_send(msg_from, &result1, sizeof(result));                          
;----------------------------------------------------------------------
           BNOP    .S1     $C$L9,5           ; |596| 
           ; BRANCH OCCURS {$C$L9}           ; |596| 
$C$DW$L$_tpo_comm__FPvPc$33$E:
;** --------------------------------------------------------------------------*
$C$L30:    
$C$DW$L$_tpo_comm__FPvPc$34$B:

$C$DW$355	.dwtag  DW_TAG_lexical_block, DW_AT_low_pc(0x00), DW_AT_high_pc(0x00)
$C$DW$356	.dwtag  DW_TAG_variable, DW_AT_name("res12")
	.dwattr $C$DW$356, DW_AT_TI_symbol_name("_res12")
	.dwattr $C$DW$356, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$356, DW_AT_location[DW_OP_breg31 80]
$C$DW$357	.dwtag  DW_TAG_variable, DW_AT_name("usb_cp")
	.dwattr $C$DW$357, DW_AT_TI_symbol_name("_usb_cp")
	.dwattr $C$DW$357, DW_AT_type(*$C$DW$T$735)
	.dwattr $C$DW$357, DW_AT_location[DW_OP_breg31 88]
$C$DW$358	.dwtag  DW_TAG_variable, DW_AT_name("recb")
	.dwattr $C$DW$358, DW_AT_TI_symbol_name("_recb")
	.dwattr $C$DW$358, DW_AT_type(*$C$DW$T$684)
	.dwattr $C$DW$358, DW_AT_location[DW_OP_breg31 200]
	.dwpsn	file "tpo_comm.cpp",line 601,column 12,is_stmt
;----------------------------------------------------------------------
; 601 | #endif                                                                 
;----------------------------------------------------------------------
           ZERO    .L1     A3                ; |601| 
           STH     .D2T1   A3,*+SP(80)       ; |601| 
	.dwpsn	file "tpo_comm.cpp",line 602,column 5,is_stmt
           MVKL    .S2     0xd0021,B4
           MVKH    .S2     0xd0021,B4
           STW     .D2T2   B4,*+SP(24)       ; |602| 
	.dwpsn	file "tpo_comm.cpp",line 603,column 11,is_stmt
;----------------------------------------------------------------------
; 605 | break;                                                                 
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+384,A3
           MVKH    .S1     ___syscall_tab+384,A3
           LDW     .D1T1   *A3,A3            ; |603| 
           LDW     .D2T1   *+SP(16),A4       ; |603| 
           ADD     .D2     SP,20,B4          ; |603| 
           MVK     .L1     0x8,A6            ; |603| 
           NOP             1
$C$DW$359	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$359, DW_AT_low_pc(0x00)
	.dwattr $C$DW$359, DW_AT_TI_call
	.dwattr $C$DW$359, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |603| 
           ADDKPC  .S2     $C$RL78,B3,4      ; |603| 
$C$RL78:   ; CALL OCCURS {A3} {0}            ; |603| 
	.dwpsn	file "tpo_comm.cpp",line 606,column 5,is_stmt
;----------------------------------------------------------------------
; 607 | case INF_ABOUT_USB:                                                    
;----------------------------------------------------------------------
$C$DW$360	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$360, DW_AT_low_pc(0x00)
	.dwattr $C$DW$360, DW_AT_name("_memset")
	.dwattr $C$DW$360, DW_AT_TI_call
           CALL    .S1     _memset           ; |606| 
           ADDAD   .D2     SP,11,B4          ; |606| 
           ADDKPC  .S2     $C$RL79,B3,2      ; |606| 

           MVK     .S1     0x70,A6           ; |606| 
||         MV      .L1X    B4,A4             ; |606| 
||         ZERO    .L2     B4                ; |606| 

$C$RL79:   ; CALL OCCURS {_memset} {0}       ; |606| 
	.dwpsn	file "tpo_comm.cpp",line 609,column 5,is_stmt
;----------------------------------------------------------------------
; 610 | uint16 res12=0;                                                        
;----------------------------------------------------------------------
$C$DW$361	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$361, DW_AT_low_pc(0x00)
	.dwattr $C$DW$361, DW_AT_name("_memset")
	.dwattr $C$DW$361, DW_AT_TI_call
           CALL    .S1     _memset           ; |609| 
           ADDAD   .D2     SP,25,B4          ; |609| 
           ADDKPC  .S2     $C$RL80,B3,2      ; |609| 

           MVK     .S1     0x190,A6          ; |609| 
||         MV      .L1X    B4,A4             ; |609| 
||         ZERO    .L2     B4                ; |609| 

$C$RL80:   ; CALL OCCURS {_memset} {0}       ; |609| 
	.dwpsn	file "tpo_comm.cpp",line 611,column 5,is_stmt
;----------------------------------------------------------------------
; 611 | cdg_error.ask = INF_ABOUT_USB;                                         
; 612 | msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));                   
;----------------------------------------------------------------------
           MVKL    .S2     ___syscall_tab+252,B4
           MVKH    .S2     ___syscall_tab+252,B4
           LDW     .D2T2   *B4,B4            ; |611| 
           MVK     .S1     0x64,A4           ; |611| 
           NOP             3
$C$DW$362	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$362, DW_AT_low_pc(0x00)
	.dwattr $C$DW$362, DW_AT_TI_call
	.dwattr $C$DW$362, DW_AT_TI_indirect
           CALL    .S2     B4                ; |611| 
           ADDKPC  .S2     $C$RL81,B3,4      ; |611| 
$C$RL81:   ; CALL OCCURS {B4} {0}            ; |611| 
	.dwpsn	file "tpo_comm.cpp",line 614,column 5,is_stmt
;----------------------------------------------------------------------
; 614 | about_usb usb_cp[2];                                                   
;----------------------------------------------------------------------
$C$DW$363	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$363, DW_AT_low_pc(0x00)
	.dwattr $C$DW$363, DW_AT_name("_ReadDARAM0__FUsPvT1")
	.dwattr $C$DW$363, DW_AT_TI_call
           CALL    .S1     _ReadDARAM0__FUsPvT1 ; |614| 
           ADDKPC  .S2     $C$RL82,B3,3      ; |614| 

           MVK     .S1     0x38,A6           ; |614| 
||         ADDAD   .D2     SP,11,B4          ; |614| 
||         ZERO    .L1     A4                ; |614| 

$C$RL82:   ; CALL OCCURS {_ReadDARAM0__FUsPvT1} {0}  ; |614| 
	.dwpsn	file "tpo_comm.cpp",line 615,column 5,is_stmt
;----------------------------------------------------------------------
; 615 | memset(usb_cp, 0, sizeof(about_usb)*2);                                
; 617 | uint8 recb[400];                                                       
; 618 | memset(recb, 0, sizeof(recb));                                         
; 620 | sleep_m(100);                                                          
; 622 | #ifndef TPO7                                                           
; 623 | ReadDARAM0(0,&usb_cp[0], sizeof(about_usb));                           
;----------------------------------------------------------------------
$C$DW$364	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$364, DW_AT_low_pc(0x00)
	.dwattr $C$DW$364, DW_AT_name("_ReadDARAM1__FUsPvT1")
	.dwattr $C$DW$364, DW_AT_TI_call
           CALL    .S1     _ReadDARAM1__FUsPvT1 ; |615| 
           ADDKPC  .S2     $C$RL83,B3,3      ; |615| 

           ZERO    .L1     A4                ; |615| 
||         ADDAD   .D2     SP,18,B4          ; |615| 
||         MVK     .S1     0x38,A6           ; |615| 

$C$RL83:   ; CALL OCCURS {_ReadDARAM1__FUsPvT1} {0}  ; |615| 
	.dwpsn	file "tpo_comm.cpp",line 624,column 11,is_stmt
;----------------------------------------------------------------------
; 624 | ReadDARAM1(0,&usb_cp[1], sizeof(about_usb));                           
; 625 | #else                                                                  
; 626 | res12 = FIFO_outIsReady();                                             
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+384,A3
           MVKH    .S1     ___syscall_tab+384,A3
           LDW     .D1T1   *A3,A3            ; |624| 
           LDW     .D2T1   *+SP(16),A4       ; |624| 
           ADDAD   .D2     SP,11,B4          ; |624| 
           MVK     .S1     0x70,A6           ; |624| 
           NOP             1
$C$DW$365	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$365, DW_AT_low_pc(0x00)
	.dwattr $C$DW$365, DW_AT_TI_call
	.dwattr $C$DW$365, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |624| 
           ADDKPC  .S2     $C$RL84,B3,4      ; |624| 
$C$RL84:   ; CALL OCCURS {A3} {0}            ; |624| 
	.dwendtag $C$DW$355

	.dwpsn	file "tpo_comm.cpp",line 627,column 12,is_stmt
;----------------------------------------------------------------------
; 627 | FIFO_StartReadPacket(&recb,0, sizeof(about_usb)+20); //20 ???? 8-0     
; 628 | sleep_m(100);                                                          
; 629 | memcpy(&usb_cp[0],&recb[20],sizeof(about_usb));                        
; 630 | memcpy(&usb_cp[1],&check_buf[20],sizeof(about_usb));                   
; 631 | FIFO_EndReadPacket();                                                  
; 632 | #endif                                                                 
; 633 | msg_send(msg_from, usb_cp, sizeof(about_usb)*2);                       
;----------------------------------------------------------------------
           BNOP    .S1     $C$L9,5           ; |627| 
           ; BRANCH OCCURS {$C$L9}           ; |627| 
$C$DW$L$_tpo_comm__FPvPc$34$E:
;** --------------------------------------------------------------------------*
$C$L31:    
$C$DW$L$_tpo_comm__FPvPc$35$B:

$C$DW$366	.dwtag  DW_TAG_lexical_block, DW_AT_low_pc(0x00), DW_AT_high_pc(0x00)
$C$DW$367	.dwtag  DW_TAG_variable, DW_AT_name("buf_wr")
	.dwattr $C$DW$367, DW_AT_TI_symbol_name("_buf_wr")
	.dwattr $C$DW$367, DW_AT_type(*$C$DW$T$687)
	.dwattr $C$DW$367, DW_AT_location[DW_OP_breg31 80]
$C$DW$368	.dwtag  DW_TAG_variable, DW_AT_name("buf_rd")
	.dwattr $C$DW$368, DW_AT_TI_symbol_name("_buf_rd")
	.dwattr $C$DW$368, DW_AT_type(*$C$DW$T$687)
	.dwattr $C$DW$368, DW_AT_location[DW_OP_breg31 1112]
	.dwpsn	file "tpo_comm.cpp",line 635,column 3,is_stmt
;----------------------------------------------------------------------
; 636 | break;                                                                 
;----------------------------------------------------------------------
$C$DW$369	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$369, DW_AT_low_pc(0x00)
	.dwattr $C$DW$369, DW_AT_name("_memset")
	.dwattr $C$DW$369, DW_AT_TI_call
           CALL    .S1     _memset           ; |635| 
           MVK     .S1     1112,A3           ; |635| 
           ADD     .L1X    A3,SP,A4          ; |635| 
           ADDKPC  .S2     $C$RL85,B3,1      ; |635| 

           ZERO    .L2     B4                ; |635| 
||         MVK     .S1     0x402,A6          ; |635| 

$C$RL85:   ; CALL OCCURS {_memset} {0}       ; |635| 

$C$DW$370	.dwtag  DW_TAG_lexical_block, DW_AT_low_pc(0x00), DW_AT_high_pc(0x00)
$C$DW$371	.dwtag  DW_TAG_variable, DW_AT_name("i")
	.dwattr $C$DW$371, DW_AT_TI_symbol_name("_i")
	.dwattr $C$DW$371, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$371, DW_AT_location[DW_OP_breg31 2140]
	.dwpsn	file "tpo_comm.cpp",line 637,column 14,is_stmt
           MVK     .L1     1,A3              ; |637| 
           STH     .D2T1   A3,*+SP(2140)     ; |637| 
	.dwpsn	file "tpo_comm.cpp",line 637,column 21,is_stmt
           LDHU    .D2T2   *+SP(2140),B4     ; |637| 
           MVK     .S2     513,B5            ; |637| 
           NOP             3
           CMPLTU  .L2     B4,B5,B0          ; |637| 
   [!B0]   BNOP    .S1     $C$L33,5          ; |637| 
           ; BRANCHCC OCCURS {$C$L33}        ; |637| 
$C$DW$L$_tpo_comm__FPvPc$35$E:
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
$C$L32:    
$C$DW$L$_tpo_comm__FPvPc$36$B:
	.dwpsn	file "tpo_comm.cpp",line 638,column 3,is_stmt
;----------------------------------------------------------------------
; 639 | case TEST_IPMP:                                                        
;----------------------------------------------------------------------
           LDHU    .D2T2   *+SP(2140),B5     ; |638| 
           LDHU    .D2T2   *+SP(2140),B4     ; |638| 
           NOP             3
           ADDAH   .D2     SP,B5,B5          ; |638| 
           ADDK    .S2     80,B5             ; |638| 
           STH     .D2T2   B4,*B5            ; |638| 
	.dwpsn	file "tpo_comm.cpp",line 637,column 32,is_stmt
           LDHU    .D2T2   *+SP(2140),B4     ; |637| 
           NOP             4
           ADD     .L2     1,B4,B4           ; |637| 
           STH     .D2T2   B4,*+SP(2140)     ; |637| 
	.dwpsn	file "tpo_comm.cpp",line 637,column 21,is_stmt
           LDHU    .D2T2   *+SP(2140),B4     ; |637| 
           MVK     .S2     513,B5            ; |637| 
           NOP             3
           CMPLTU  .L2     B4,B5,B0          ; |637| 
   [ B0]   BNOP    .S1     $C$L32,5          ; |637| 
           ; BRANCHCC OCCURS {$C$L32}        ; |637| 
$C$DW$L$_tpo_comm__FPvPc$36$E:
;** --------------------------------------------------------------------------*
$C$L33:    
$C$DW$L$_tpo_comm__FPvPc$37$B:
	.dwendtag $C$DW$370

	.dwpsn	file "tpo_comm.cpp",line 640,column 3,is_stmt
           MVKL    .S1     0xd0022,A3
           MVKH    .S1     0xd0022,A3
           STW     .D2T1   A3,*+SP(24)       ; |640| 
	.dwpsn	file "tpo_comm.cpp",line 641,column 9,is_stmt
;----------------------------------------------------------------------
; 641 | uint16 buf_wr[0x201];                                                  
; 642 | uint16 buf_rd[0x201];                                                  
;----------------------------------------------------------------------
           MVKL    .S2     ___syscall_tab+384,B4
           MVKH    .S2     ___syscall_tab+384,B4
           LDW     .D2T2   *B4,B5            ; |641| 
           LDW     .D2T1   *+SP(16),A4       ; |641| 
           ADD     .D2     SP,20,B4          ; |641| 
           MVK     .L1     0x8,A6            ; |641| 
           NOP             1
$C$DW$372	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$372, DW_AT_low_pc(0x00)
	.dwattr $C$DW$372, DW_AT_TI_call
	.dwattr $C$DW$372, DW_AT_TI_indirect
           CALL    .S2     B5                ; |641| 
           ADDKPC  .S2     $C$RL86,B3,4      ; |641| 
$C$RL86:   ; CALL OCCURS {B5} {0}            ; |641| 
	.dwpsn	file "tpo_comm.cpp",line 643,column 3,is_stmt
           MVKL    .S1     ___syscall_tab+388,A3
           MVKH    .S1     ___syscall_tab+388,A3
           LDW     .D1T1   *A3,A3            ; |643| 
           ADD     .D2     SP,28,B5          ; |643| 
           MVK     .S2     0x2710,B4         ; |643| 
           MV      .L1X    B5,A4             ; |643| 
           NOP             1
$C$DW$373	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$373, DW_AT_low_pc(0x00)
	.dwattr $C$DW$373, DW_AT_TI_call
	.dwattr $C$DW$373, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |643| 
           ADDKPC  .S2     $C$RL87,B3,4      ; |643| 
$C$RL87:   ; CALL OCCURS {A3} {0}            ; |643| 
           STW     .D2T1   A4,*+SP(12)       ; |643| 
	.dwpsn	file "tpo_comm.cpp",line 644,column 6,is_stmt
;----------------------------------------------------------------------
; 644 | memset(buf_rd, 0, sizeof(buf_rd));                                     
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(28),B0       ; |644| 
           NOP             4
   [!B0]   BNOP    .S1     $C$L9,5           ; |644| 
           ; BRANCHCC OCCURS {$C$L9}         ; |644| 
$C$DW$L$_tpo_comm__FPvPc$37$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_tpo_comm__FPvPc$38$B:
	.dwpsn	file "tpo_comm.cpp",line 644,column 27,is_stmt
	.dwpsn	file "tpo_comm.cpp",line 646,column 3,is_stmt
;----------------------------------------------------------------------
; 646 | for(uint16 i = 1; i < 0x201; i++)                                      
;----------------------------------------------------------------------
$C$DW$374	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$374, DW_AT_low_pc(0x04)
	.dwattr $C$DW$374, DW_AT_name("_memcpy")
	.dwattr $C$DW$374, DW_AT_TI_call

           MV      .L2     B0,B4
||         CALL    .S1     _memcpy           ; |646| 

           LDW     .D2T2   *+B4(24),B4       ; |646| 
           MVK     .S2     1112,B5           ; |646| 
           ADD     .L2     B5,SP,B5          ; |646| 
           ADDKPC  .S2     $C$RL88,B3,0      ; |646| 

           MVK     .S1     0x402,A6          ; |646| 
||         MV      .L1X    B5,A4             ; |646| 

$C$RL88:   ; CALL OCCURS {_memcpy} {0}       ; |646| 
	.dwpsn	file "tpo_comm.cpp",line 647,column 6,is_stmt
;----------------------------------------------------------------------
; 647 | buf_wr[i] = i;                                                         
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+404,A3
           MVKH    .S1     ___syscall_tab+404,A3
           LDW     .D1T1   *A3,A3            ; |647| 
           LDW     .D2T1   *+SP(28),A4       ; |647| 
           NOP             3
$C$DW$375	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$375, DW_AT_low_pc(0x00)
	.dwattr $C$DW$375, DW_AT_TI_call
	.dwattr $C$DW$375, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |647| 
           ADDKPC  .S2     $C$RL89,B3,4      ; |647| 
$C$RL89:   ; CALL OCCURS {A3} {0}            ; |647| 
	.dwpsn	file "tpo_comm.cpp",line 649,column 3,is_stmt
;----------------------------------------------------------------------
; 649 | cdg_error.ask = TEST_IPMP;                                             
;----------------------------------------------------------------------
$C$DW$376	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$376, DW_AT_low_pc(0x00)
	.dwattr $C$DW$376, DW_AT_name("_memcmp")
	.dwattr $C$DW$376, DW_AT_TI_call
           CALL    .S1     _memcmp           ; |649| 
           MVK     .S2     82,B4             ; |649| 
           MVK     .S1     1114,A3           ; |649| 
           ADD     .L1X    A3,SP,A4          ; |649| 
           ADDKPC  .S2     $C$RL90,B3,0      ; |649| 

           ADD     .L2     B4,SP,B4          ; |649| 
||         MVK     .S1     0x400,A6          ; |649| 

$C$RL90:   ; CALL OCCURS {_memcmp} {0}       ; |649| 
           MV      .L1     A4,A0             ; |649| 
   [!A0]   BNOP    .S1     $C$L34,5          ; |649| 
           ; BRANCHCC OCCURS {$C$L34}        ; |649| 
$C$DW$L$_tpo_comm__FPvPc$38$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_tpo_comm__FPvPc$39$B:
	.dwpsn	file "tpo_comm.cpp",line 650,column 4,is_stmt
;----------------------------------------------------------------------
; 650 | msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));                   
;----------------------------------------------------------------------
           BNOP    .S1     $C$L35,3          ; |650| 
           MVK     .L2     1,B4              ; |650| 
           STH     .D2T2   B4,*+SP(80)       ; |650| 
           ; BRANCH OCCURS {$C$L35}          ; |650| 
$C$DW$L$_tpo_comm__FPvPc$39$E:
;** --------------------------------------------------------------------------*
$C$L34:    
$C$DW$L$_tpo_comm__FPvPc$40$B:
	.dwpsn	file "tpo_comm.cpp",line 652,column 4,is_stmt
;----------------------------------------------------------------------
; 652 | error = msg_recv(&msg_desc, MSG_WAIT_10);                              
; 653 | if(msg_desc == NULL) continue;                                         
;----------------------------------------------------------------------
           ZERO    .L2     B4                ; |652| 
           STH     .D2T2   B4,*+SP(80)       ; |652| 
$C$DW$L$_tpo_comm__FPvPc$40$E:
;** --------------------------------------------------------------------------*
$C$L35:    
$C$DW$L$_tpo_comm__FPvPc$41$B:
	.dwpsn	file "tpo_comm.cpp",line 654,column 9,is_stmt
;----------------------------------------------------------------------
; 655 | memcpy(buf_rd, msg_desc->data, sizeof(buf_rd));                        
; 656 | msg_free(msg_desc);                                                    
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+384,A3
           MVKH    .S1     ___syscall_tab+384,A3
           LDW     .D1T1   *A3,A3            ; |654| 
           LDW     .D2T1   *+SP(16),A4       ; |654| 
           ADDAD   .D2     SP,10,B4          ; |654| 
           MVK     .S1     0x402,A6          ; |654| 
           NOP             1
$C$DW$377	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$377, DW_AT_low_pc(0x00)
	.dwattr $C$DW$377, DW_AT_TI_call
	.dwattr $C$DW$377, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |654| 
           ADDKPC  .S2     $C$RL91,B3,4      ; |654| 
$C$RL91:   ; CALL OCCURS {A3} {0}            ; |654| 
	.dwendtag $C$DW$366

	.dwpsn	file "tpo_comm.cpp",line 657,column 12,is_stmt
;----------------------------------------------------------------------
; 658 | if(memcmp(&buf_rd[1], &buf_wr[1], sizeof(buf_wr)-2))                   
; 659 |         buf_wr[0]=TPO_ERR;                                             
; 660 | else                                                                   
; 661 |         buf_wr[0]=TPO_OK;                                              
;----------------------------------------------------------------------
           BNOP    .S1     $C$L9,5           ; |657| 
           ; BRANCH OCCURS {$C$L9}           ; |657| 
$C$DW$L$_tpo_comm__FPvPc$41$E:
;** --------------------------------------------------------------------------*
$C$L36:    
$C$DW$L$_tpo_comm__FPvPc$42$B:
	.dwpsn	file "tpo_comm.cpp",line 662,column 3,is_stmt
           MVKL    .S2     0xd0027,B4
           MVKH    .S2     0xd0027,B4
           STW     .D2T2   B4,*+SP(24)       ; |662| 
	.dwpsn	file "tpo_comm.cpp",line 663,column 9,is_stmt
;----------------------------------------------------------------------
; 663 | msg_send(msg_from, buf_wr, sizeof(buf_wr));                            
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+384,A3
           MVKH    .S1     ___syscall_tab+384,A3
           LDW     .D1T1   *A3,A3            ; |663| 
           LDW     .D2T1   *+SP(16),A4       ; |663| 
           ADD     .D2     SP,20,B4          ; |663| 
           MVK     .L1     0x8,A6            ; |663| 
           NOP             1
$C$DW$378	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$378, DW_AT_low_pc(0x00)
	.dwattr $C$DW$378, DW_AT_TI_call
	.dwattr $C$DW$378, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |663| 
           ADDKPC  .S2     $C$RL92,B3,4      ; |663| 
$C$RL92:   ; CALL OCCURS {A3} {0}            ; |663| 
	.dwpsn	file "tpo_comm.cpp",line 666,column 5,is_stmt
;----------------------------------------------------------------------
; 666 | break;                                                                 
; 669 |     case STOP_TX:                                                      
; 671 |           cdg_error.ask = STOP_TX;                                     
; 672 |   msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));                 
; 674 |           #ifdef TPO5                                                  
; 675 |                           si_stop_tx(5);  //start stop trancemiter     
; 676 |           #else                                                        
; 677 |           uint32* regtx = (uint32*)0x02C40030;                         
;----------------------------------------------------------------------
$C$DW$379	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$379, DW_AT_low_pc(0x00)
	.dwattr $C$DW$379, DW_AT_name("_si_stop_tx__Fi")
	.dwattr $C$DW$379, DW_AT_TI_call
           CALL    .S1     _si_stop_tx__Fi   ; |666| 
           ADDKPC  .S2     $C$RL93,B3,3      ; |666| 
           MVK     .L1     0x5,A4            ; |666| 
$C$RL93:   ; CALL OCCURS {_si_stop_tx__Fi} {0}  ; |666| 
	.dwpsn	file "tpo_comm.cpp",line 678,column 12,is_stmt
;----------------------------------------------------------------------
; 678 | uint32  regdat=0;                                                      
; 679 | regdat = *regtx;                                                       
; 680 | regdat = regdat & 0xFFFFFFFE;                                          
; 681 | uint32 dg = 10000000;                                                  
;----------------------------------------------------------------------
           BNOP    .S1     $C$L9,5           ; |678| 
           ; BRANCH OCCURS {$C$L9}           ; |678| 
$C$DW$L$_tpo_comm__FPvPc$42$E:
;** --------------------------------------------------------------------------*
$C$L37:    
$C$DW$L$_tpo_comm__FPvPc$43$B:
	.dwpsn	file "tpo_comm.cpp",line 682,column 3,is_stmt
;----------------------------------------------------------------------
; 682 | while(dg--);                                                           
;----------------------------------------------------------------------
$C$DW$380	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$380, DW_AT_low_pc(0x00)
	.dwattr $C$DW$380, DW_AT_name("_flash_chip_clear__Fv")
	.dwattr $C$DW$380, DW_AT_TI_call
           CALL    .S1     _flash_chip_clear__Fv ; |682| 
           ADDKPC  .S2     $C$RL94,B3,4      ; |682| 
$C$RL94:   ; CALL OCCURS {_flash_chip_clear__Fv} {0}  ; |682| 
	.dwpsn	file "tpo_comm.cpp",line 683,column 3,is_stmt
;----------------------------------------------------------------------
; 683 | uint32 rui = prc_disable();                                            
;----------------------------------------------------------------------
           MVKL    .S2     0xd002b,B4
           MVKH    .S2     0xd002b,B4
           STW     .D2T2   B4,*+SP(24)       ; |683| 
	.dwpsn	file "tpo_comm.cpp",line 684,column 9,is_stmt
;----------------------------------------------------------------------
; 684 | #endif                                                                 
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+384,A3
           MVKH    .S1     ___syscall_tab+384,A3
           LDW     .D1T1   *A3,A3            ; |684| 
           LDW     .D2T1   *+SP(16),A4       ; |684| 
           ADD     .D2     SP,20,B4          ; |684| 
           MVK     .L1     0x8,A6            ; |684| 
           NOP             1
$C$DW$381	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$381, DW_AT_low_pc(0x00)
	.dwattr $C$DW$381, DW_AT_TI_call
	.dwattr $C$DW$381, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |684| 
           ADDKPC  .S2     $C$RL95,B3,4      ; |684| 
$C$RL95:   ; CALL OCCURS {A3} {0}            ; |684| 
	.dwpsn	file "tpo_comm.cpp",line 685,column 3,is_stmt
$C$DW$382	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$382, DW_AT_low_pc(0x00)
	.dwattr $C$DW$382, DW_AT_name("_Load_po_flash__Fv")
	.dwattr $C$DW$382, DW_AT_TI_call
           CALL    .S1     _Load_po_flash__Fv ; |685| 
           ADDKPC  .S2     $C$RL96,B3,4      ; |685| 
$C$RL96:   ; CALL OCCURS {_Load_po_flash__Fv} {0}  ; |685| 
	.dwpsn	file "tpo_comm.cpp",line 687,column 12,is_stmt
;----------------------------------------------------------------------
; 687 | break;                                                                 
; 688 | //                                                                     
; 689 |     case START_LOAD_PO:                                                
;----------------------------------------------------------------------
           BNOP    .S1     $C$L9,5           ; |687| 
           ; BRANCH OCCURS {$C$L9}           ; |687| 
$C$DW$L$_tpo_comm__FPvPc$43$E:
;** --------------------------------------------------------------------------*
$C$L38:    
	.dwpsn	file "tpo_comm.cpp",line 691,column 3,is_stmt
;----------------------------------------------------------------------
; 691 | flash_chip_clear();                                                    
;----------------------------------------------------------------------
           MVKL    .S1     _sv_msg_open,A4

           MVKH    .S1     _sv_msg_open,A4
||         ZERO    .L1     A3                ; |691| 

           STW     .D1T1   A3,*A4            ; |691| 
	.dwpsn	file "tpo_comm.cpp",line 692,column 3,is_stmt
;----------------------------------------------------------------------
; 692 | cdg_error.ask = START_LOAD_PO;                                         
;----------------------------------------------------------------------
           MVKL    .S2     0xd0028,B4
           MVKH    .S2     0xd0028,B4
           STW     .D2T2   B4,*+SP(24)       ; |692| 
	.dwpsn	file "tpo_comm.cpp",line 693,column 9,is_stmt
;----------------------------------------------------------------------
; 693 | msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));                   
;----------------------------------------------------------------------
           MVKL    .S2     ___syscall_tab+384,B4
           MVKH    .S2     ___syscall_tab+384,B4
           LDW     .D2T2   *B4,B5            ; |693| 
           LDW     .D2T1   *+SP(16),A4       ; |693| 
           ADD     .D2     SP,20,B4          ; |693| 
           MVK     .L1     0x8,A6            ; |693| 
           NOP             1
$C$DW$383	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$383, DW_AT_low_pc(0x00)
	.dwattr $C$DW$383, DW_AT_TI_call
	.dwattr $C$DW$383, DW_AT_TI_indirect
           CALL    .S2     B5                ; |693| 
           ADDKPC  .S2     $C$RL97,B3,4      ; |693| 
$C$RL97:   ; CALL OCCURS {B5} {0}            ; |693| 
	.dwpsn	file "tpo_comm.cpp",line 694,column 3,is_stmt
;----------------------------------------------------------------------
; 694 | Load_po_flash();                                                       
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+252,A3
           MVKH    .S1     ___syscall_tab+252,A3
           LDW     .D1T1   *A3,A3            ; |694| 
           MVK     .S1     0x3e8,A4          ; |694| 
           NOP             3
$C$DW$384	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$384, DW_AT_low_pc(0x00)
	.dwattr $C$DW$384, DW_AT_TI_call
	.dwattr $C$DW$384, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |694| 
           ADDKPC  .S2     $C$RL98,B3,4      ; |694| 
$C$RL98:   ; CALL OCCURS {A3} {0}            ; |694| 
	.dwpsn	file "tpo_comm.cpp",line 695,column 3,is_stmt
$C$DW$385	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$385, DW_AT_low_pc(0x00)
	.dwattr $C$DW$385, DW_AT_name("_load_lif__FPv")
	.dwattr $C$DW$385, DW_AT_TI_call
           CALL    .S1     _load_lif__FPv    ; |695| 
           ADDKPC  .S2     $C$RL99,B3,3      ; |695| 
           ZERO    .L1     A4                ; |695| 
$C$RL99:   ; CALL OCCURS {_load_lif__FPv} {0}  ; |695| 
	.dwpsn	file "tpo_comm.cpp",line 696,column 3,is_stmt
;----------------------------------------------------------------------
; 696 | break;                                                                 
;----------------------------------------------------------------------
           MVKL    .S2     ___syscall_tab+252,B4
           MVKH    .S2     ___syscall_tab+252,B4
           LDW     .D2T2   *B4,B4            ; |696| 
           MVK     .S1     0x1b58,A4         ; |696| 
           NOP             3
$C$DW$386	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$386, DW_AT_low_pc(0x00)
	.dwattr $C$DW$386, DW_AT_TI_call
	.dwattr $C$DW$386, DW_AT_TI_indirect
           CALL    .S2     B4                ; |696| 
           ADDKPC  .S2     $C$RL100,B3,4     ; |696| 
$C$RL100:  ; CALL OCCURS {B4} {0}            ; |696| 
	.dwpsn	file "tpo_comm.cpp",line 697,column 3,is_stmt
;----------------------------------------------------------------------
; 697 | //                                                                     
; 698 | case EXIT_TPO:                                                         
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+380,A3
           MVKH    .S1     ___syscall_tab+380,A3
           LDW     .D1T1   *A3,A3            ; |697| 
           NOP             4
$C$DW$387	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$387, DW_AT_low_pc(0x00)
	.dwattr $C$DW$387, DW_AT_TI_call
	.dwattr $C$DW$387, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |697| 
           ADDKPC  .S2     $C$RL101,B3,4     ; |697| 
$C$RL101:  ; CALL OCCURS {A3} {0}            ; |697| 
	.dwpsn	file "tpo_comm.cpp",line 700,column 3,is_stmt
;----------------------------------------------------------------------
; 700 | sv_msg_open = 0;                                                       
; 701 | cdg_error.ask = EXIT_TPO;                                              
; 702 | msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));                   
; 703 | sleep_m(1000);                                                         
; 704 | load_lif(NULL);                                                        
;----------------------------------------------------------------------
           BNOP    .S1     $C$L43,4          ; |700| 
           ZERO    .L1     A4                ; |700| 
           ; BRANCH OCCURS {$C$L43}          ; |700| 
;** --------------------------------------------------------------------------*
$C$L39:    
	.dwpsn	file "tpo_comm.cpp",line 705,column 3,is_stmt
;----------------------------------------------------------------------
; 705 | sleep_m(7000);                                                         
;----------------------------------------------------------------------
           MVKL    .S1     _sv_msg_open,A4

           MVKH    .S1     _sv_msg_open,A4
||         ZERO    .L1     A3                ; |705| 

           STW     .D1T1   A3,*A4            ; |705| 
	.dwpsn	file "tpo_comm.cpp",line 706,column 3,is_stmt
;----------------------------------------------------------------------
; 706 | msg_close();                                                           
;----------------------------------------------------------------------
           MVKL    .S2     0xd0029,B4
           MVKH    .S2     0xd0029,B4
           STW     .D2T2   B4,*+SP(24)       ; |706| 
	.dwpsn	file "tpo_comm.cpp",line 707,column 9,is_stmt
;----------------------------------------------------------------------
; 707 | //              prc_exit();                                            
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+384,A3
           MVKH    .S1     ___syscall_tab+384,A3
           LDW     .D1T1   *A3,A3            ; |707| 
           LDW     .D2T1   *+SP(16),A4       ; |707| 
           ADD     .D2     SP,20,B4          ; |707| 
           MVK     .L1     0x8,A6            ; |707| 
           NOP             1
$C$DW$388	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$388, DW_AT_low_pc(0x00)
	.dwattr $C$DW$388, DW_AT_TI_call
	.dwattr $C$DW$388, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |707| 
           ADDKPC  .S2     $C$RL102,B3,4     ; |707| 
$C$RL102:  ; CALL OCCURS {A3} {0}            ; |707| 
	.dwpsn	file "tpo_comm.cpp",line 708,column 3,is_stmt
;----------------------------------------------------------------------
; 708 | //              while(1);                                              
;----------------------------------------------------------------------
$C$DW$389	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$389, DW_AT_low_pc(0x00)
	.dwattr $C$DW$389, DW_AT_name("_Load_lif_from_usb__Fv")
	.dwattr $C$DW$389, DW_AT_TI_call
           CALL    .S1     _Load_lif_from_usb__Fv ; |708| 
           ADDKPC  .S2     $C$RL103,B3,4     ; |708| 
$C$RL103:  ; CALL OCCURS {_Load_lif_from_usb__Fv} {0}  ; |708| 
	.dwpsn	file "tpo_comm.cpp",line 709,column 3,is_stmt
;----------------------------------------------------------------------
; 709 | return 0;                                                              
;----------------------------------------------------------------------
           MVKL    .S2     ___syscall_tab+252,B4
           MVKH    .S2     ___syscall_tab+252,B4
           LDW     .D2T2   *B4,B4            ; |709| 
           MVK     .S1     0x3e8,A4          ; |709| 
           NOP             3
$C$DW$390	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$390, DW_AT_low_pc(0x00)
	.dwattr $C$DW$390, DW_AT_TI_call
	.dwattr $C$DW$390, DW_AT_TI_indirect
           CALL    .S2     B4                ; |709| 
           ADDKPC  .S2     $C$RL104,B3,4     ; |709| 
$C$RL104:  ; CALL OCCURS {B4} {0}            ; |709| 
	.dwpsn	file "tpo_comm.cpp",line 710,column 3,is_stmt
$C$DW$391	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$391, DW_AT_low_pc(0x00)
	.dwattr $C$DW$391, DW_AT_name("_load_lif__FPv")
	.dwattr $C$DW$391, DW_AT_TI_call
           CALL    .S1     _load_lif__FPv    ; |710| 
           ADDKPC  .S2     $C$RL105,B3,3     ; |710| 
           ZERO    .L1     A4                ; |710| 
$C$RL105:  ; CALL OCCURS {_load_lif__FPv} {0}  ; |710| 
	.dwpsn	file "tpo_comm.cpp",line 711,column 3,is_stmt
;----------------------------------------------------------------------
; 711 | //                                                                     
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+252,A3
           MVKH    .S1     ___syscall_tab+252,A3
           LDW     .D1T1   *A3,A3            ; |711| 
           MVK     .S1     0x1b58,A4         ; |711| 
           NOP             3
$C$DW$392	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$392, DW_AT_low_pc(0x00)
	.dwattr $C$DW$392, DW_AT_TI_call
	.dwattr $C$DW$392, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |711| 
           ADDKPC  .S2     $C$RL106,B3,4     ; |711| 
$C$RL106:  ; CALL OCCURS {A3} {0}            ; |711| 
	.dwpsn	file "tpo_comm.cpp",line 712,column 3,is_stmt
;----------------------------------------------------------------------
; 712 | case LOAD_LIF:                                                         
;----------------------------------------------------------------------
           MVKL    .S2     ___syscall_tab+380,B4
           MVKH    .S2     ___syscall_tab+380,B4
           LDW     .D2T2   *B4,B4            ; |712| 
           NOP             4
$C$DW$393	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$393, DW_AT_low_pc(0x00)
	.dwattr $C$DW$393, DW_AT_TI_call
	.dwattr $C$DW$393, DW_AT_TI_indirect
           CALL    .S2     B4                ; |712| 
           ADDKPC  .S2     $C$RL107,B3,4     ; |712| 
$C$RL107:  ; CALL OCCURS {B4} {0}            ; |712| 
	.dwpsn	file "tpo_comm.cpp",line 713,column 3,is_stmt
           MVKL    .S1     ___syscall_tab+44,A3
           MVKH    .S1     ___syscall_tab+44,A3
           LDW     .D1T1   *A3,A3            ; |713| 
           NOP             4
$C$DW$394	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$394, DW_AT_low_pc(0x00)
	.dwattr $C$DW$394, DW_AT_TI_call
	.dwattr $C$DW$394, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |713| 
           ADDKPC  .S2     $C$RL108,B3,4     ; |713| 
$C$RL108:  ; CALL OCCURS {A3} {0}            ; |713| 
	.dwpsn	file "tpo_comm.cpp",line 714,column 9,is_stmt
;----------------------------------------------------------------------
; 714 | sv_msg_open = 0;                                                       
; 715 | cdg_error.ask = LOAD_LIF;                                              
; 716 | msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));                   
; 717 | Load_lif_from_usb();                                                   
; 718 | sleep_m(1000);                                                         
;----------------------------------------------------------------------
;*----------------------------------------------------------------------------*
;*   SOFTWARE PIPELINE INFORMATION
;*      Disqualified loop: Software pipelining disabled
;*----------------------------------------------------------------------------*
$C$L40:    
$C$DW$L$_tpo_comm__FPvPc$46$B:
           BNOP    .S1     $C$L40,5          ; |714| 
           ; BRANCH OCCURS {$C$L40}          ; |714| 
$C$DW$L$_tpo_comm__FPvPc$46$E:
;** --------------------------------------------------------------------------*
$C$L41:    
$C$DW$L$_tpo_comm__FPvPc$47$B:
	.dwpsn	file "tpo_comm.cpp",line 719,column 8,is_stmt
;----------------------------------------------------------------------
; 719 | load_lif(NULL);                                                        
;----------------------------------------------------------------------
           MVKL    .S2     0xd0026,B4
           MVKH    .S2     0xd0026,B4
           STW     .D2T2   B4,*+SP(20)       ; |719| 
	.dwpsn	file "tpo_comm.cpp",line 720,column 8,is_stmt
;----------------------------------------------------------------------
; 720 | sleep_m(7000);                                                         
;----------------------------------------------------------------------
           MVK     .L2     1,B4              ; |720| 
           STW     .D2T2   B4,*+SP(24)       ; |720| 
	.dwpsn	file "tpo_comm.cpp",line 721,column 8,is_stmt
;----------------------------------------------------------------------
; 721 | msg_close();                                                           
;----------------------------------------------------------------------
           MVKL    .S1     ___syscall_tab+384,A3
           MVKH    .S1     ___syscall_tab+384,A3
           LDW     .D1T1   *A3,A3            ; |721| 
           LDW     .D2T2   *+SP(28),B4       ; |721| 
           MVK     .L1     0x8,A6            ; |721| 
           NOP             2
$C$DW$395	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$395, DW_AT_low_pc(0x00)
	.dwattr $C$DW$395, DW_AT_TI_call
	.dwattr $C$DW$395, DW_AT_TI_indirect
           CALL    .S2X    A3                ; |721| 
           LDW     .D2T1   *+B4(12),A4       ; |721| 
           ADDKPC  .S2     $C$RL109,B3,2     ; |721| 
           ADD     .D2     SP,20,B4          ; |721| 
$C$RL109:  ; CALL OCCURS {A3} {0}            ; |721| 
	.dwpsn	file "tpo_comm.cpp",line 722,column 7,is_stmt
;----------------------------------------------------------------------
; 722 | prc_exit();                                                            
; 723 | while(1);                                                              
;----------------------------------------------------------------------
           BNOP    .S1     $C$L9,5           ; |722| 
           ; BRANCH OCCURS {$C$L9}           ; |722| 
$C$DW$L$_tpo_comm__FPvPc$47$E:
;** --------------------------------------------------------------------------*
$C$L42:    
$C$DW$L$_tpo_comm__FPvPc$48$B:
	.dwpsn	file "tpo_comm.cpp",line 304,column 5,is_stmt
           LDW     .D2T2   *+SP(20),B4       ; |304| 
           MVKL    .S2     0xd0001,B5
           MVKH    .S2     0xd0001,B5
           MVK     .S1     42,A3             ; |304| 
           NOP             1
           SUB     .L2     B4,B5,B5          ; |304| 
           NOP             1
           CMPGTU  .L1X    B5,A3,A0          ; |304| 
   [ A0]   BNOP    .S1     $C$L41,5          ; |304| 
           ; BRANCHCC OCCURS {$C$L41} {-19}  ; |304| 
$C$DW$L$_tpo_comm__FPvPc$48$E:
;** --------------------------------------------------------------------------*
$C$DW$L$_tpo_comm__FPvPc$49$B:
           MVKL    .S1     0x340004,A3

           MVKH    .S1     0x340004,A3
||         MVKL    .S2     $C$SW1,B5

           SHL     .S2     B4,2,B4           ; |304| 

           SUB     .L2X    B4,A3,B4          ; |304| 
||         MVKH    .S2     $C$SW1,B5

           ADD     .L2     B5,B4,B4          ; |304| 
           LDW     .D2T2   *B4,B4            ; |304| 
           NOP             4
           BNOP    .S2     B4,5              ; |304| 
           ; BRANCH OCCURS {B4}              ; |304| 
	.sect	".switch"
	.clink
$C$SW1:	.word	$C$L12	; 851969
	.word	$C$L41	; 0
	.word	$C$L24	; 851971
	.word	$C$L41	; 0
	.word	$C$L13	; 851973
	.word	$C$L41	; 0
	.word	$C$L41	; 0
	.word	$C$L41	; 0
	.word	$C$L41	; 0
	.word	$C$L41	; 0
	.word	$C$L15	; 851979
	.word	$C$L16	; 851980
	.word	$C$L18	; 851981
	.word	$C$L41	; 0
	.word	$C$L41	; 0
	.word	$C$L19	; 851984
	.word	$C$L21	; 851985
	.word	$C$L41	; 0
	.word	$C$L41	; 0
	.word	$C$L23	; 851988
	.word	$C$L41	; 0
	.word	$C$L41	; 0
	.word	$C$L41	; 0
	.word	$C$L41	; 0
	.word	$C$L27	; 851993
	.word	$C$L41	; 0
	.word	$C$L41	; 0
	.word	$C$L41	; 0
	.word	$C$L41	; 0
	.word	$C$L28	; 851998
	.word	$C$L41	; 0
	.word	$C$L29	; 852000
	.word	$C$L30	; 852001
	.word	$C$L31	; 852002
	.word	$C$L41	; 0
	.word	$C$L41	; 0
	.word	$C$L41	; 0
	.word	$C$L41	; 0
	.word	$C$L36	; 852007
	.word	$C$L38	; 852008
	.word	$C$L39	; 852009
	.word	$C$L41	; 0
	.word	$C$L37	; 852011
	.sect	".text"
$C$DW$L$_tpo_comm__FPvPc$49$E:
;** --------------------------------------------------------------------------*
;** --------------------------------------------------------------------------*
$C$L43:    
	.dwpsn	file "tpo_comm.cpp",line 725,column 1,is_stmt
;----------------------------------------------------------------------
; 725 | //                                                                     
;----------------------------------------------------------------------
           LDW     .D2T2   *+SP(2144),B3     ; |725| 
           NOP             4
	.dwcfi	restore_reg, 19
           ADDK    .S2     2144,SP           ; |725| 
	.dwcfi	cfa_offset, 0
	.dwcfi	cfa_offset, 0
$C$DW$396	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$396, DW_AT_low_pc(0x00)
	.dwattr $C$DW$396, DW_AT_TI_return
           RETNOP  .S2     B3,5              ; |725| 
           ; BRANCH OCCURS {B3}              ; |725| 

$C$DW$397	.dwtag  DW_TAG_TI_loop
	.dwattr $C$DW$397, DW_AT_name("C:\1901VC1T_Inteltech\3rdPartyLIB\dsp_core\C6000\tpo_amoeba\source\tpo_comm.asm:$C$L40:1:1517815040")
	.dwattr $C$DW$397, DW_AT_TI_begin_file("tpo_comm.cpp")
	.dwattr $C$DW$397, DW_AT_TI_begin_line(0x2ca)
	.dwattr $C$DW$397, DW_AT_TI_end_line(0x2ca)
$C$DW$398	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$398, DW_AT_low_pc($C$DW$L$_tpo_comm__FPvPc$46$B)
	.dwattr $C$DW$398, DW_AT_high_pc($C$DW$L$_tpo_comm__FPvPc$46$E)
	.dwendtag $C$DW$397


$C$DW$399	.dwtag  DW_TAG_TI_loop
	.dwattr $C$DW$399, DW_AT_name("C:\1901VC1T_Inteltech\3rdPartyLIB\dsp_core\C6000\tpo_amoeba\source\tpo_comm.asm:$C$L9:1:1517815040")
	.dwattr $C$DW$399, DW_AT_TI_begin_file("tpo_comm.cpp")
	.dwattr $C$DW$399, DW_AT_TI_begin_line(0x11d)
	.dwattr $C$DW$399, DW_AT_TI_end_line(0x2d4)
$C$DW$400	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$400, DW_AT_low_pc($C$DW$L$_tpo_comm__FPvPc$4$B)
	.dwattr $C$DW$400, DW_AT_high_pc($C$DW$L$_tpo_comm__FPvPc$4$E)
$C$DW$401	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$401, DW_AT_low_pc($C$DW$L$_tpo_comm__FPvPc$38$B)
	.dwattr $C$DW$401, DW_AT_high_pc($C$DW$L$_tpo_comm__FPvPc$38$E)
$C$DW$402	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$402, DW_AT_low_pc($C$DW$L$_tpo_comm__FPvPc$39$B)
	.dwattr $C$DW$402, DW_AT_high_pc($C$DW$L$_tpo_comm__FPvPc$39$E)
$C$DW$403	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$403, DW_AT_low_pc($C$DW$L$_tpo_comm__FPvPc$40$B)
	.dwattr $C$DW$403, DW_AT_high_pc($C$DW$L$_tpo_comm__FPvPc$40$E)
$C$DW$404	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$404, DW_AT_low_pc($C$DW$L$_tpo_comm__FPvPc$35$B)
	.dwattr $C$DW$404, DW_AT_high_pc($C$DW$L$_tpo_comm__FPvPc$35$E)
$C$DW$405	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$405, DW_AT_low_pc($C$DW$L$_tpo_comm__FPvPc$27$B)
	.dwattr $C$DW$405, DW_AT_high_pc($C$DW$L$_tpo_comm__FPvPc$27$E)
$C$DW$406	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$406, DW_AT_low_pc($C$DW$L$_tpo_comm__FPvPc$28$B)
	.dwattr $C$DW$406, DW_AT_high_pc($C$DW$L$_tpo_comm__FPvPc$28$E)
$C$DW$407	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$407, DW_AT_low_pc($C$DW$L$_tpo_comm__FPvPc$29$B)
	.dwattr $C$DW$407, DW_AT_high_pc($C$DW$L$_tpo_comm__FPvPc$29$E)
$C$DW$408	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$408, DW_AT_low_pc($C$DW$L$_tpo_comm__FPvPc$23$B)
	.dwattr $C$DW$408, DW_AT_high_pc($C$DW$L$_tpo_comm__FPvPc$23$E)
$C$DW$409	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$409, DW_AT_low_pc($C$DW$L$_tpo_comm__FPvPc$24$B)
	.dwattr $C$DW$409, DW_AT_high_pc($C$DW$L$_tpo_comm__FPvPc$24$E)
$C$DW$410	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$410, DW_AT_low_pc($C$DW$L$_tpo_comm__FPvPc$20$B)
	.dwattr $C$DW$410, DW_AT_high_pc($C$DW$L$_tpo_comm__FPvPc$20$E)
$C$DW$411	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$411, DW_AT_low_pc($C$DW$L$_tpo_comm__FPvPc$21$B)
	.dwattr $C$DW$411, DW_AT_high_pc($C$DW$L$_tpo_comm__FPvPc$21$E)
$C$DW$412	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$412, DW_AT_low_pc($C$DW$L$_tpo_comm__FPvPc$16$B)
	.dwattr $C$DW$412, DW_AT_high_pc($C$DW$L$_tpo_comm__FPvPc$16$E)
$C$DW$413	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$413, DW_AT_low_pc($C$DW$L$_tpo_comm__FPvPc$17$B)
	.dwattr $C$DW$413, DW_AT_high_pc($C$DW$L$_tpo_comm__FPvPc$17$E)
$C$DW$414	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$414, DW_AT_low_pc($C$DW$L$_tpo_comm__FPvPc$12$B)
	.dwattr $C$DW$414, DW_AT_high_pc($C$DW$L$_tpo_comm__FPvPc$12$E)
$C$DW$415	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$415, DW_AT_low_pc($C$DW$L$_tpo_comm__FPvPc$8$B)
	.dwattr $C$DW$415, DW_AT_high_pc($C$DW$L$_tpo_comm__FPvPc$8$E)
$C$DW$416	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$416, DW_AT_low_pc($C$DW$L$_tpo_comm__FPvPc$48$B)
	.dwattr $C$DW$416, DW_AT_high_pc($C$DW$L$_tpo_comm__FPvPc$48$E)
$C$DW$417	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$417, DW_AT_low_pc($C$DW$L$_tpo_comm__FPvPc$49$B)
	.dwattr $C$DW$417, DW_AT_high_pc($C$DW$L$_tpo_comm__FPvPc$49$E)
$C$DW$418	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$418, DW_AT_low_pc($C$DW$L$_tpo_comm__FPvPc$6$B)
	.dwattr $C$DW$418, DW_AT_high_pc($C$DW$L$_tpo_comm__FPvPc$6$E)
$C$DW$419	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$419, DW_AT_low_pc($C$DW$L$_tpo_comm__FPvPc$47$B)
	.dwattr $C$DW$419, DW_AT_high_pc($C$DW$L$_tpo_comm__FPvPc$47$E)
$C$DW$420	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$420, DW_AT_low_pc($C$DW$L$_tpo_comm__FPvPc$43$B)
	.dwattr $C$DW$420, DW_AT_high_pc($C$DW$L$_tpo_comm__FPvPc$43$E)
$C$DW$421	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$421, DW_AT_low_pc($C$DW$L$_tpo_comm__FPvPc$42$B)
	.dwattr $C$DW$421, DW_AT_high_pc($C$DW$L$_tpo_comm__FPvPc$42$E)
$C$DW$422	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$422, DW_AT_low_pc($C$DW$L$_tpo_comm__FPvPc$41$B)
	.dwattr $C$DW$422, DW_AT_high_pc($C$DW$L$_tpo_comm__FPvPc$41$E)
$C$DW$423	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$423, DW_AT_low_pc($C$DW$L$_tpo_comm__FPvPc$37$B)
	.dwattr $C$DW$423, DW_AT_high_pc($C$DW$L$_tpo_comm__FPvPc$37$E)
$C$DW$424	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$424, DW_AT_low_pc($C$DW$L$_tpo_comm__FPvPc$34$B)
	.dwattr $C$DW$424, DW_AT_high_pc($C$DW$L$_tpo_comm__FPvPc$34$E)
$C$DW$425	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$425, DW_AT_low_pc($C$DW$L$_tpo_comm__FPvPc$33$B)
	.dwattr $C$DW$425, DW_AT_high_pc($C$DW$L$_tpo_comm__FPvPc$33$E)
$C$DW$426	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$426, DW_AT_low_pc($C$DW$L$_tpo_comm__FPvPc$32$B)
	.dwattr $C$DW$426, DW_AT_high_pc($C$DW$L$_tpo_comm__FPvPc$32$E)
$C$DW$427	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$427, DW_AT_low_pc($C$DW$L$_tpo_comm__FPvPc$31$B)
	.dwattr $C$DW$427, DW_AT_high_pc($C$DW$L$_tpo_comm__FPvPc$31$E)
$C$DW$428	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$428, DW_AT_low_pc($C$DW$L$_tpo_comm__FPvPc$30$B)
	.dwattr $C$DW$428, DW_AT_high_pc($C$DW$L$_tpo_comm__FPvPc$30$E)
$C$DW$429	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$429, DW_AT_low_pc($C$DW$L$_tpo_comm__FPvPc$26$B)
	.dwattr $C$DW$429, DW_AT_high_pc($C$DW$L$_tpo_comm__FPvPc$26$E)
$C$DW$430	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$430, DW_AT_low_pc($C$DW$L$_tpo_comm__FPvPc$25$B)
	.dwattr $C$DW$430, DW_AT_high_pc($C$DW$L$_tpo_comm__FPvPc$25$E)
$C$DW$431	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$431, DW_AT_low_pc($C$DW$L$_tpo_comm__FPvPc$22$B)
	.dwattr $C$DW$431, DW_AT_high_pc($C$DW$L$_tpo_comm__FPvPc$22$E)
$C$DW$432	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$432, DW_AT_low_pc($C$DW$L$_tpo_comm__FPvPc$19$B)
	.dwattr $C$DW$432, DW_AT_high_pc($C$DW$L$_tpo_comm__FPvPc$19$E)
$C$DW$433	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$433, DW_AT_low_pc($C$DW$L$_tpo_comm__FPvPc$18$B)
	.dwattr $C$DW$433, DW_AT_high_pc($C$DW$L$_tpo_comm__FPvPc$18$E)
$C$DW$434	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$434, DW_AT_low_pc($C$DW$L$_tpo_comm__FPvPc$15$B)
	.dwattr $C$DW$434, DW_AT_high_pc($C$DW$L$_tpo_comm__FPvPc$15$E)
$C$DW$435	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$435, DW_AT_low_pc($C$DW$L$_tpo_comm__FPvPc$14$B)
	.dwattr $C$DW$435, DW_AT_high_pc($C$DW$L$_tpo_comm__FPvPc$14$E)
$C$DW$436	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$436, DW_AT_low_pc($C$DW$L$_tpo_comm__FPvPc$13$B)
	.dwattr $C$DW$436, DW_AT_high_pc($C$DW$L$_tpo_comm__FPvPc$13$E)
$C$DW$437	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$437, DW_AT_low_pc($C$DW$L$_tpo_comm__FPvPc$11$B)
	.dwattr $C$DW$437, DW_AT_high_pc($C$DW$L$_tpo_comm__FPvPc$11$E)
$C$DW$438	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$438, DW_AT_low_pc($C$DW$L$_tpo_comm__FPvPc$10$B)
	.dwattr $C$DW$438, DW_AT_high_pc($C$DW$L$_tpo_comm__FPvPc$10$E)
$C$DW$439	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$439, DW_AT_low_pc($C$DW$L$_tpo_comm__FPvPc$7$B)
	.dwattr $C$DW$439, DW_AT_high_pc($C$DW$L$_tpo_comm__FPvPc$7$E)
$C$DW$440	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$440, DW_AT_low_pc($C$DW$L$_tpo_comm__FPvPc$5$B)
	.dwattr $C$DW$440, DW_AT_high_pc($C$DW$L$_tpo_comm__FPvPc$5$E)

$C$DW$441	.dwtag  DW_TAG_TI_loop
	.dwattr $C$DW$441, DW_AT_name("C:\1901VC1T_Inteltech\3rdPartyLIB\dsp_core\C6000\tpo_amoeba\source\tpo_comm.asm:$C$L32:2:1517815040")
	.dwattr $C$DW$441, DW_AT_TI_begin_file("tpo_comm.cpp")
	.dwattr $C$DW$441, DW_AT_TI_begin_line(0x27d)
	.dwattr $C$DW$441, DW_AT_TI_end_line(0x27e)
$C$DW$442	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$442, DW_AT_low_pc($C$DW$L$_tpo_comm__FPvPc$36$B)
	.dwattr $C$DW$442, DW_AT_high_pc($C$DW$L$_tpo_comm__FPvPc$36$E)
	.dwendtag $C$DW$441

	.dwendtag $C$DW$399

	.dwattr $C$DW$249, DW_AT_TI_end_file("tpo_comm.cpp")
	.dwattr $C$DW$249, DW_AT_TI_end_line(0x2d5)
	.dwattr $C$DW$249, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$249

;******************************************************************************
;* STRINGS                                                                    *
;******************************************************************************
	.sect	".const:.string"
$C$SL1:	.string	"/fwmem",0
$C$SL2:	.string	"/dev/net/eth0",0
$C$SL3:	.string	"tpo",0
;*****************************************************************************
;* UNDEFINED EXTERNAL REFERENCES                                             *
;*****************************************************************************
	.global	_memset
	.global	_memcmp
	.global	_Sv_Msg__FPv
	.global	_TestDOZU_Nagr__FPv
	.global	_Start_Test_N__FP12kdg_rez_test
	.global	_Test_sialp__Fv
	.global	_si_stop_tx__Fi
	.global	_ReadDARAM0__FUsPvT1
	.global	_ReadDARAM1__FUsPvT1
	.global	_WriteDARAM__FUsPvT1
	.global	_load_lif__FPv
	.global	_Load_lif_from_usb__Fv
	.global	___syscall_tab
	.global	_memcpy
	.global	__strasgi

;******************************************************************************
;* TYPE INFORMATION                                                           *
;******************************************************************************
$C$DW$T$3	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$3, DW_AT_address_class(0x20)

$C$DW$T$660	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$660, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$T$660, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$660, DW_AT_byte_size(0x2d0)
$C$DW$443	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$443, DW_AT_upper_bound(0xb3)
	.dwendtag $C$DW$T$660


$C$DW$T$21	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$21, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$T$211	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$211, DW_AT_type(*$C$DW$T$21)
	.dwattr $C$DW$T$211, DW_AT_address_class(0x20)

$C$DW$T$23	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$23, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$444	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$444, DW_AT_type(*$C$DW$T$22)
	.dwendtag $C$DW$T$23


$C$DW$T$25	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$25, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$445	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$445, DW_AT_type(*$C$DW$T$24)
	.dwendtag $C$DW$T$25


$C$DW$T$29	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$29, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$446	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$446, DW_AT_type(*$C$DW$T$28)
	.dwendtag $C$DW$T$29


$C$DW$T$31	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$31, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$447	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$447, DW_AT_type(*$C$DW$T$30)
	.dwendtag $C$DW$T$31


$C$DW$T$35	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$35, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$448	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$448, DW_AT_type(*$C$DW$T$34)
	.dwendtag $C$DW$T$35


$C$DW$T$38	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$38, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$449	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$449, DW_AT_type(*$C$DW$T$37)
	.dwendtag $C$DW$T$38


$C$DW$T$42	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$42, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$450	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$450, DW_AT_type(*$C$DW$T$41)
	.dwendtag $C$DW$T$42


$C$DW$T$44	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$44, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$451	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$451, DW_AT_type(*$C$DW$T$43)
	.dwendtag $C$DW$T$44


$C$DW$T$48	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$48, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$452	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$452, DW_AT_type(*$C$DW$T$47)
	.dwendtag $C$DW$T$48


$C$DW$T$50	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$50, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$453	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$453, DW_AT_type(*$C$DW$T$49)
	.dwendtag $C$DW$T$50


$C$DW$T$54	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$54, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$454	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$454, DW_AT_type(*$C$DW$T$53)
	.dwendtag $C$DW$T$54


$C$DW$T$57	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$57, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$455	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$455, DW_AT_type(*$C$DW$T$56)
	.dwendtag $C$DW$T$57


$C$DW$T$61	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$61, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$456	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$456, DW_AT_type(*$C$DW$T$60)
	.dwendtag $C$DW$T$61


$C$DW$T$63	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$63, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$457	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$457, DW_AT_type(*$C$DW$T$62)
	.dwendtag $C$DW$T$63


$C$DW$T$67	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$67, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$458	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$458, DW_AT_type(*$C$DW$T$66)
	.dwendtag $C$DW$T$67


$C$DW$T$69	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$69, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$459	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$459, DW_AT_type(*$C$DW$T$68)
	.dwendtag $C$DW$T$69


$C$DW$T$73	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$73, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$460	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$460, DW_AT_type(*$C$DW$T$72)
	.dwendtag $C$DW$T$73


$C$DW$T$76	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$76, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$461	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$461, DW_AT_type(*$C$DW$T$75)
	.dwendtag $C$DW$T$76

$C$DW$T$93	.dwtag  DW_TAG_const_type
$C$DW$T$94	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$94, DW_AT_type(*$C$DW$T$93)
	.dwattr $C$DW$T$94, DW_AT_address_class(0x20)

$C$DW$T$334	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$334, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$462	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$462, DW_AT_type(*$C$DW$T$3)
$C$DW$463	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$463, DW_AT_type(*$C$DW$T$10)
	.dwendtag $C$DW$T$334

$C$DW$T$335	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$335, DW_AT_type(*$C$DW$T$334)
	.dwattr $C$DW$T$335, DW_AT_address_class(0x20)

$C$DW$T$667	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$667, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$464	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$464, DW_AT_type(*$C$DW$T$10)
	.dwendtag $C$DW$T$667

$C$DW$T$668	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$668, DW_AT_type(*$C$DW$T$667)
	.dwattr $C$DW$T$668, DW_AT_address_class(0x20)
$C$DW$T$669	.dwtag  DW_TAG_typedef, DW_AT_name("EDMA_IntHandler")
	.dwattr $C$DW$T$669, DW_AT_type(*$C$DW$T$668)
	.dwattr $C$DW$T$669, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$T$4	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$4, DW_AT_encoding(DW_ATE_boolean)
	.dwattr $C$DW$T$4, DW_AT_name("bool")
	.dwattr $C$DW$T$4, DW_AT_byte_size(0x01)
$C$DW$T$5	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$5, DW_AT_encoding(DW_ATE_signed_char)
	.dwattr $C$DW$T$5, DW_AT_name("signed char")
	.dwattr $C$DW$T$5, DW_AT_byte_size(0x01)
$C$DW$T$679	.dwtag  DW_TAG_typedef, DW_AT_name("int8")
	.dwattr $C$DW$T$679, DW_AT_type(*$C$DW$T$5)
	.dwattr $C$DW$T$679, DW_AT_language(DW_LANG_C_plus_plus)
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
$C$DW$465	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$465, DW_AT_upper_bound(0x01)
	.dwendtag $C$DW$T$20


$C$DW$T$40	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$40, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$T$40, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$40, DW_AT_byte_size(0x04)
$C$DW$466	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$466, DW_AT_upper_bound(0x03)
	.dwendtag $C$DW$T$40


$C$DW$T$59	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$59, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$T$59, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$59, DW_AT_byte_size(0x08)
$C$DW$467	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$467, DW_AT_upper_bound(0x07)
	.dwendtag $C$DW$T$59


$C$DW$T$288	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$288, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$T$288, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$288, DW_AT_byte_size(0x10)
$C$DW$468	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$468, DW_AT_upper_bound(0x0f)
	.dwendtag $C$DW$T$288


$C$DW$T$301	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$301, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$T$301, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$301, DW_AT_byte_size(0x400)
$C$DW$469	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$469, DW_AT_upper_bound(0x3ff)
	.dwendtag $C$DW$T$301


$C$DW$T$302	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$302, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$T$302, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$302, DW_AT_byte_size(0x20)
$C$DW$470	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$470, DW_AT_upper_bound(0x1f)
	.dwendtag $C$DW$T$302


$C$DW$T$504	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$504, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$T$504, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$504, DW_AT_byte_size(0x06)
$C$DW$471	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$471, DW_AT_upper_bound(0x05)
	.dwendtag $C$DW$T$504


$C$DW$T$570	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$570, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$T$570, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$570, DW_AT_byte_size(0x03)
$C$DW$472	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$472, DW_AT_upper_bound(0x02)
	.dwendtag $C$DW$T$570

$C$DW$T$581	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$581, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$T$581, DW_AT_address_class(0x20)
$C$DW$T$681	.dwtag  DW_TAG_volatile_type
	.dwattr $C$DW$T$681, DW_AT_type(*$C$DW$T$19)
$C$DW$T$682	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$682, DW_AT_type(*$C$DW$T$681)
	.dwattr $C$DW$T$682, DW_AT_address_class(0x20)

$C$DW$T$684	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$684, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$T$684, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$684, DW_AT_byte_size(0x190)
$C$DW$473	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$473, DW_AT_upper_bound(0x18f)
	.dwendtag $C$DW$T$684

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

$C$DW$T$687	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$687, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$T$687, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$687, DW_AT_byte_size(0x402)
$C$DW$474	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$474, DW_AT_upper_bound(0x200)
	.dwendtag $C$DW$T$687

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
$C$DW$475	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$475, DW_AT_type(*$C$DW$T$86)
$C$DW$476	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$476, DW_AT_type(*$C$DW$T$28)
	.dwendtag $C$DW$T$87

$C$DW$T$88	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$88, DW_AT_type(*$C$DW$T$87)
	.dwattr $C$DW$T$88, DW_AT_address_class(0x20)

$C$DW$T$89	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$89, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$T$89, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$477	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$477, DW_AT_type(*$C$DW$T$86)
	.dwendtag $C$DW$T$89

$C$DW$T$90	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$90, DW_AT_type(*$C$DW$T$89)
	.dwattr $C$DW$T$90, DW_AT_address_class(0x20)

$C$DW$T$91	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$91, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$T$91, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$478	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$478, DW_AT_type(*$C$DW$T$86)
$C$DW$479	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$479, DW_AT_type(*$C$DW$T$3)
$C$DW$480	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$480, DW_AT_type(*$C$DW$T$41)
	.dwendtag $C$DW$T$91

$C$DW$T$92	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$92, DW_AT_type(*$C$DW$T$91)
	.dwattr $C$DW$T$92, DW_AT_address_class(0x20)

$C$DW$T$95	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$95, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$T$95, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$481	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$481, DW_AT_type(*$C$DW$T$86)
$C$DW$482	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$482, DW_AT_type(*$C$DW$T$94)
$C$DW$483	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$483, DW_AT_type(*$C$DW$T$41)
	.dwendtag $C$DW$T$95

$C$DW$T$96	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$96, DW_AT_type(*$C$DW$T$95)
	.dwattr $C$DW$T$96, DW_AT_address_class(0x20)

$C$DW$T$97	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$97, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$T$97, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$484	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$484, DW_AT_type(*$C$DW$T$86)
$C$DW$485	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$485, DW_AT_type(*$C$DW$T$41)
$C$DW$486	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$486, DW_AT_type(*$C$DW$T$94)
	.dwendtag $C$DW$T$97

$C$DW$T$98	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$98, DW_AT_type(*$C$DW$T$97)
	.dwattr $C$DW$T$98, DW_AT_address_class(0x20)

$C$DW$T$390	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$390, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$T$390, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$487	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$487, DW_AT_type(*$C$DW$T$389)
	.dwendtag $C$DW$T$390

$C$DW$T$391	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$391, DW_AT_type(*$C$DW$T$390)
	.dwattr $C$DW$T$391, DW_AT_address_class(0x20)

$C$DW$T$393	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$393, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$T$393, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$488	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$488, DW_AT_type(*$C$DW$T$389)
$C$DW$489	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$489, DW_AT_type(*$C$DW$T$392)
	.dwendtag $C$DW$T$393

$C$DW$T$394	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$394, DW_AT_type(*$C$DW$T$393)
	.dwattr $C$DW$T$394, DW_AT_address_class(0x20)

$C$DW$T$396	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$396, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$T$396, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$490	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$490, DW_AT_type(*$C$DW$T$389)
$C$DW$491	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$491, DW_AT_type(*$C$DW$T$395)
	.dwendtag $C$DW$T$396

$C$DW$T$397	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$397, DW_AT_type(*$C$DW$T$396)
	.dwattr $C$DW$T$397, DW_AT_address_class(0x20)

$C$DW$T$398	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$398, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$T$398, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$492	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$492, DW_AT_type(*$C$DW$T$389)
$C$DW$493	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$493, DW_AT_type(*$C$DW$T$47)
	.dwendtag $C$DW$T$398

$C$DW$T$399	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$399, DW_AT_type(*$C$DW$T$398)
	.dwattr $C$DW$T$399, DW_AT_address_class(0x20)

$C$DW$T$400	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$400, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$T$400, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$494	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$494, DW_AT_type(*$C$DW$T$389)
$C$DW$495	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$495, DW_AT_type(*$C$DW$T$47)
$C$DW$496	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$496, DW_AT_type(*$C$DW$T$3)
$C$DW$497	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$497, DW_AT_type(*$C$DW$T$47)
	.dwendtag $C$DW$T$400

$C$DW$T$401	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$401, DW_AT_type(*$C$DW$T$400)
	.dwattr $C$DW$T$401, DW_AT_address_class(0x20)
$C$DW$T$689	.dwtag  DW_TAG_typedef, DW_AT_name("ptrdiff_t")
	.dwattr $C$DW$T$689, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$T$689, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$T$709	.dwtag  DW_TAG_typedef, DW_AT_name("nothrow_t")
	.dwattr $C$DW$T$709, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$T$709, DW_AT_language(DW_LANG_C_plus_plus)
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
$C$DW$498	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$498, DW_AT_upper_bound(0x02)
	.dwendtag $C$DW$T$232


$C$DW$T$233	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$233, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$T$233, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$233, DW_AT_byte_size(0x40)
$C$DW$499	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$499, DW_AT_upper_bound(0x0f)
	.dwendtag $C$DW$T$233

$C$DW$T$392	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$392, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$T$392, DW_AT_address_class(0x20)

$C$DW$T$478	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$478, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$T$478, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$478, DW_AT_byte_size(0x20)
$C$DW$500	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$500, DW_AT_upper_bound(0x07)
	.dwendtag $C$DW$T$478

$C$DW$T$715	.dwtag  DW_TAG_typedef, DW_AT_name("EDMA_Handle")
	.dwattr $C$DW$T$715, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$T$715, DW_AT_language(DW_LANG_C_plus_plus)

$C$DW$T$718	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$718, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$T$718, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$718, DW_AT_byte_size(0x08)
$C$DW$501	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$501, DW_AT_upper_bound(0x01)
	.dwendtag $C$DW$T$718


$C$DW$T$719	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$719, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$T$719, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$719, DW_AT_byte_size(0x10)
$C$DW$502	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$502, DW_AT_upper_bound(0x01)
$C$DW$503	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$503, DW_AT_upper_bound(0x01)
	.dwendtag $C$DW$T$719


$C$DW$T$722	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$722, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$T$722, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$722, DW_AT_byte_size(0x600)
$C$DW$504	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$504, DW_AT_upper_bound(0x17f)
	.dwendtag $C$DW$T$722

$C$DW$T$662	.dwtag  DW_TAG_typedef, DW_AT_name("size_t")
	.dwattr $C$DW$T$662, DW_AT_type(*$C$DW$T$11)
	.dwattr $C$DW$T$662, DW_AT_language(DW_LANG_C_plus_plus)
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
$C$DW$T$724	.dwtag  DW_TAG_typedef, DW_AT_name("float32")
	.dwattr $C$DW$T$724, DW_AT_type(*$C$DW$T$16)
	.dwattr $C$DW$T$724, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$T$17	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$17, DW_AT_encoding(DW_ATE_float)
	.dwattr $C$DW$T$17, DW_AT_name("double")
	.dwattr $C$DW$T$17, DW_AT_byte_size(0x08)
$C$DW$T$18	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$18, DW_AT_encoding(DW_ATE_float)
	.dwattr $C$DW$T$18, DW_AT_name("long double")
	.dwattr $C$DW$T$18, DW_AT_byte_size(0x08)
$C$DW$T$725	.dwtag  DW_TAG_typedef, DW_AT_name("float64")
	.dwattr $C$DW$T$725, DW_AT_type(*$C$DW$T$18)
	.dwattr $C$DW$T$725, DW_AT_language(DW_LANG_C_plus_plus)

$C$DW$T$27	.dwtag  DW_TAG_class_type
	.dwattr $C$DW$T$27, DW_AT_name("int16le")
	.dwattr $C$DW$T$27, DW_AT_byte_size(0x02)
$C$DW$505	.dwtag  DW_TAG_member
	.dwattr $C$DW$505, DW_AT_type(*$C$DW$T$20)
	.dwattr $C$DW$505, DW_AT_name("a")
	.dwattr $C$DW$505, DW_AT_TI_symbol_name("_a")
	.dwattr $C$DW$505, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$505, DW_AT_accessibility(DW_ACCESS_private)

$C$DW$5	.dwtag  DW_TAG_subprogram, DW_AT_name("int16le")
	.dwattr $C$DW$5, DW_AT_declaration
	.dwattr $C$DW$5, DW_AT_TI_symbol_name("___ct__7int16leFv")
	.dwattr $C$DW$5, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$6	.dwtag  DW_TAG_subprogram, DW_AT_name("int16le")
	.dwattr $C$DW$6, DW_AT_declaration
	.dwattr $C$DW$6, DW_AT_TI_symbol_name("___ct__7int16leFs")
	.dwattr $C$DW$6, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$506	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$506, DW_AT_type(*$C$DW$T$22)
	.dwendtag $C$DW$6


$C$DW$7	.dwtag  DW_TAG_subprogram, DW_AT_name("int16le")
	.dwattr $C$DW$7, DW_AT_declaration
	.dwattr $C$DW$7, DW_AT_TI_symbol_name("___ct__7int16leFR7int16le")
	.dwattr $C$DW$7, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$507	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$507, DW_AT_type(*$C$DW$T$24)
	.dwendtag $C$DW$7


$C$DW$8	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$8, DW_AT_declaration
	.dwattr $C$DW$8, DW_AT_TI_symbol_name("___as__7int16leFs")
	.dwattr $C$DW$8, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$508	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$508, DW_AT_type(*$C$DW$T$22)
	.dwendtag $C$DW$8


$C$DW$9	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$9, DW_AT_declaration
	.dwattr $C$DW$9, DW_AT_TI_symbol_name("___as__7int16leFR7int16le")
	.dwattr $C$DW$9, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$509	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$509, DW_AT_type(*$C$DW$T$24)
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
$C$DW$510	.dwtag  DW_TAG_member
	.dwattr $C$DW$510, DW_AT_type(*$C$DW$T$20)
	.dwattr $C$DW$510, DW_AT_name("a")
	.dwattr $C$DW$510, DW_AT_TI_symbol_name("_a")
	.dwattr $C$DW$510, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$510, DW_AT_accessibility(DW_ACCESS_private)

$C$DW$11	.dwtag  DW_TAG_subprogram, DW_AT_name("uint16le")
	.dwattr $C$DW$11, DW_AT_declaration
	.dwattr $C$DW$11, DW_AT_TI_symbol_name("___ct__8uint16leFv")
	.dwattr $C$DW$11, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$12	.dwtag  DW_TAG_subprogram, DW_AT_name("uint16le")
	.dwattr $C$DW$12, DW_AT_declaration
	.dwattr $C$DW$12, DW_AT_TI_symbol_name("___ct__8uint16leFUs")
	.dwattr $C$DW$12, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$511	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$511, DW_AT_type(*$C$DW$T$28)
	.dwendtag $C$DW$12


$C$DW$13	.dwtag  DW_TAG_subprogram, DW_AT_name("uint16le")
	.dwattr $C$DW$13, DW_AT_declaration
	.dwattr $C$DW$13, DW_AT_TI_symbol_name("___ct__8uint16leFR8uint16le")
	.dwattr $C$DW$13, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$512	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$512, DW_AT_type(*$C$DW$T$30)
	.dwendtag $C$DW$13


$C$DW$14	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$14, DW_AT_declaration
	.dwattr $C$DW$14, DW_AT_TI_symbol_name("___as__8uint16leFUs")
	.dwattr $C$DW$14, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$513	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$513, DW_AT_type(*$C$DW$T$28)
	.dwendtag $C$DW$14


$C$DW$15	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$15, DW_AT_declaration
	.dwattr $C$DW$15, DW_AT_TI_symbol_name("___as__8uint16leFR8uint16le")
	.dwattr $C$DW$15, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$514	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$514, DW_AT_type(*$C$DW$T$30)
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
$C$DW$515	.dwtag  DW_TAG_member
	.dwattr $C$DW$515, DW_AT_type(*$C$DW$T$20)
	.dwattr $C$DW$515, DW_AT_name("a")
	.dwattr $C$DW$515, DW_AT_TI_symbol_name("_a")
	.dwattr $C$DW$515, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$515, DW_AT_accessibility(DW_ACCESS_private)

$C$DW$17	.dwtag  DW_TAG_subprogram, DW_AT_name("int16be")
	.dwattr $C$DW$17, DW_AT_declaration
	.dwattr $C$DW$17, DW_AT_TI_symbol_name("___ct__7int16beFv")
	.dwattr $C$DW$17, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$18	.dwtag  DW_TAG_subprogram, DW_AT_name("int16be")
	.dwattr $C$DW$18, DW_AT_declaration
	.dwattr $C$DW$18, DW_AT_TI_symbol_name("___ct__7int16beFs")
	.dwattr $C$DW$18, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$516	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$516, DW_AT_type(*$C$DW$T$22)
	.dwendtag $C$DW$18


$C$DW$19	.dwtag  DW_TAG_subprogram, DW_AT_name("int16be")
	.dwattr $C$DW$19, DW_AT_declaration
	.dwattr $C$DW$19, DW_AT_TI_symbol_name("___ct__7int16beFR7int16be")
	.dwattr $C$DW$19, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$517	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$517, DW_AT_type(*$C$DW$T$34)
	.dwendtag $C$DW$19


$C$DW$20	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$20, DW_AT_declaration
	.dwattr $C$DW$20, DW_AT_TI_symbol_name("___as__7int16beFs")
	.dwattr $C$DW$20, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$518	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$518, DW_AT_type(*$C$DW$T$22)
	.dwendtag $C$DW$20


$C$DW$21	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$21, DW_AT_declaration
	.dwattr $C$DW$21, DW_AT_TI_symbol_name("___as__7int16beFR7int16be")
	.dwattr $C$DW$21, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$519	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$519, DW_AT_type(*$C$DW$T$34)
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
$C$DW$520	.dwtag  DW_TAG_member
	.dwattr $C$DW$520, DW_AT_type(*$C$DW$T$20)
	.dwattr $C$DW$520, DW_AT_name("a")
	.dwattr $C$DW$520, DW_AT_TI_symbol_name("_a")
	.dwattr $C$DW$520, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$520, DW_AT_accessibility(DW_ACCESS_private)

$C$DW$23	.dwtag  DW_TAG_subprogram, DW_AT_name("uint16be")
	.dwattr $C$DW$23, DW_AT_declaration
	.dwattr $C$DW$23, DW_AT_TI_symbol_name("___ct__8uint16beFv")
	.dwattr $C$DW$23, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$24	.dwtag  DW_TAG_subprogram, DW_AT_name("uint16be")
	.dwattr $C$DW$24, DW_AT_declaration
	.dwattr $C$DW$24, DW_AT_TI_symbol_name("___ct__8uint16beFUs")
	.dwattr $C$DW$24, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$521	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$521, DW_AT_type(*$C$DW$T$28)
	.dwendtag $C$DW$24


$C$DW$25	.dwtag  DW_TAG_subprogram, DW_AT_name("uint16be")
	.dwattr $C$DW$25, DW_AT_declaration
	.dwattr $C$DW$25, DW_AT_TI_symbol_name("___ct__8uint16beFR8uint16be")
	.dwattr $C$DW$25, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$522	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$522, DW_AT_type(*$C$DW$T$37)
	.dwendtag $C$DW$25


$C$DW$26	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$26, DW_AT_declaration
	.dwattr $C$DW$26, DW_AT_TI_symbol_name("___as__8uint16beFUs")
	.dwattr $C$DW$26, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$523	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$523, DW_AT_type(*$C$DW$T$28)
	.dwendtag $C$DW$26


$C$DW$27	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$27, DW_AT_declaration
	.dwattr $C$DW$27, DW_AT_TI_symbol_name("___as__8uint16beFR8uint16be")
	.dwattr $C$DW$27, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$524	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$524, DW_AT_type(*$C$DW$T$37)
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
$C$DW$525	.dwtag  DW_TAG_member
	.dwattr $C$DW$525, DW_AT_type(*$C$DW$T$40)
	.dwattr $C$DW$525, DW_AT_name("a")
	.dwattr $C$DW$525, DW_AT_TI_symbol_name("_a")
	.dwattr $C$DW$525, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$525, DW_AT_accessibility(DW_ACCESS_private)

$C$DW$29	.dwtag  DW_TAG_subprogram, DW_AT_name("int32le")
	.dwattr $C$DW$29, DW_AT_declaration
	.dwattr $C$DW$29, DW_AT_TI_symbol_name("___ct__7int32leFv")
	.dwattr $C$DW$29, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$30	.dwtag  DW_TAG_subprogram, DW_AT_name("int32le")
	.dwattr $C$DW$30, DW_AT_declaration
	.dwattr $C$DW$30, DW_AT_TI_symbol_name("___ct__7int32leFi")
	.dwattr $C$DW$30, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$526	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$526, DW_AT_type(*$C$DW$T$41)
	.dwendtag $C$DW$30


$C$DW$31	.dwtag  DW_TAG_subprogram, DW_AT_name("int32le")
	.dwattr $C$DW$31, DW_AT_declaration
	.dwattr $C$DW$31, DW_AT_TI_symbol_name("___ct__7int32leFR7int32le")
	.dwattr $C$DW$31, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$527	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$527, DW_AT_type(*$C$DW$T$43)
	.dwendtag $C$DW$31


$C$DW$32	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$32, DW_AT_declaration
	.dwattr $C$DW$32, DW_AT_TI_symbol_name("___as__7int32leFi")
	.dwattr $C$DW$32, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$528	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$528, DW_AT_type(*$C$DW$T$41)
	.dwendtag $C$DW$32


$C$DW$33	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$33, DW_AT_declaration
	.dwattr $C$DW$33, DW_AT_TI_symbol_name("___as__7int32leFR7int32le")
	.dwattr $C$DW$33, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$529	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$529, DW_AT_type(*$C$DW$T$43)
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
$C$DW$530	.dwtag  DW_TAG_member
	.dwattr $C$DW$530, DW_AT_type(*$C$DW$T$40)
	.dwattr $C$DW$530, DW_AT_name("a")
	.dwattr $C$DW$530, DW_AT_TI_symbol_name("_a")
	.dwattr $C$DW$530, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$530, DW_AT_accessibility(DW_ACCESS_private)

$C$DW$35	.dwtag  DW_TAG_subprogram, DW_AT_name("uint32le")
	.dwattr $C$DW$35, DW_AT_declaration
	.dwattr $C$DW$35, DW_AT_TI_symbol_name("___ct__8uint32leFv")
	.dwattr $C$DW$35, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$36	.dwtag  DW_TAG_subprogram, DW_AT_name("uint32le")
	.dwattr $C$DW$36, DW_AT_declaration
	.dwattr $C$DW$36, DW_AT_TI_symbol_name("___ct__8uint32leFUi")
	.dwattr $C$DW$36, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$531	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$531, DW_AT_type(*$C$DW$T$47)
	.dwendtag $C$DW$36


$C$DW$37	.dwtag  DW_TAG_subprogram, DW_AT_name("uint32le")
	.dwattr $C$DW$37, DW_AT_declaration
	.dwattr $C$DW$37, DW_AT_TI_symbol_name("___ct__8uint32leFR8uint32le")
	.dwattr $C$DW$37, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$532	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$532, DW_AT_type(*$C$DW$T$49)
	.dwendtag $C$DW$37


$C$DW$38	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$38, DW_AT_declaration
	.dwattr $C$DW$38, DW_AT_TI_symbol_name("___as__8uint32leFUi")
	.dwattr $C$DW$38, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$533	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$533, DW_AT_type(*$C$DW$T$47)
	.dwendtag $C$DW$38


$C$DW$39	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$39, DW_AT_declaration
	.dwattr $C$DW$39, DW_AT_TI_symbol_name("___as__8uint32leFR8uint32le")
	.dwattr $C$DW$39, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$534	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$534, DW_AT_type(*$C$DW$T$49)
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
$C$DW$535	.dwtag  DW_TAG_member
	.dwattr $C$DW$535, DW_AT_type(*$C$DW$T$40)
	.dwattr $C$DW$535, DW_AT_name("a")
	.dwattr $C$DW$535, DW_AT_TI_symbol_name("_a")
	.dwattr $C$DW$535, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$535, DW_AT_accessibility(DW_ACCESS_private)

$C$DW$41	.dwtag  DW_TAG_subprogram, DW_AT_name("int32be")
	.dwattr $C$DW$41, DW_AT_declaration
	.dwattr $C$DW$41, DW_AT_TI_symbol_name("___ct__7int32beFv")
	.dwattr $C$DW$41, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$42	.dwtag  DW_TAG_subprogram, DW_AT_name("int32be")
	.dwattr $C$DW$42, DW_AT_declaration
	.dwattr $C$DW$42, DW_AT_TI_symbol_name("___ct__7int32beFi")
	.dwattr $C$DW$42, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$536	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$536, DW_AT_type(*$C$DW$T$41)
	.dwendtag $C$DW$42


$C$DW$43	.dwtag  DW_TAG_subprogram, DW_AT_name("int32be")
	.dwattr $C$DW$43, DW_AT_declaration
	.dwattr $C$DW$43, DW_AT_TI_symbol_name("___ct__7int32beFR7int32be")
	.dwattr $C$DW$43, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$537	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$537, DW_AT_type(*$C$DW$T$53)
	.dwendtag $C$DW$43


$C$DW$44	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$44, DW_AT_declaration
	.dwattr $C$DW$44, DW_AT_TI_symbol_name("___as__7int32beFi")
	.dwattr $C$DW$44, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$538	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$538, DW_AT_type(*$C$DW$T$41)
	.dwendtag $C$DW$44


$C$DW$45	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$45, DW_AT_declaration
	.dwattr $C$DW$45, DW_AT_TI_symbol_name("___as__7int32beFR7int32be")
	.dwattr $C$DW$45, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$539	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$539, DW_AT_type(*$C$DW$T$53)
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
$C$DW$540	.dwtag  DW_TAG_member
	.dwattr $C$DW$540, DW_AT_type(*$C$DW$T$40)
	.dwattr $C$DW$540, DW_AT_name("a")
	.dwattr $C$DW$540, DW_AT_TI_symbol_name("_a")
	.dwattr $C$DW$540, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$540, DW_AT_accessibility(DW_ACCESS_private)

$C$DW$47	.dwtag  DW_TAG_subprogram, DW_AT_name("uint32be")
	.dwattr $C$DW$47, DW_AT_declaration
	.dwattr $C$DW$47, DW_AT_TI_symbol_name("___ct__8uint32beFv")
	.dwattr $C$DW$47, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$48	.dwtag  DW_TAG_subprogram, DW_AT_name("uint32be")
	.dwattr $C$DW$48, DW_AT_declaration
	.dwattr $C$DW$48, DW_AT_TI_symbol_name("___ct__8uint32beFUi")
	.dwattr $C$DW$48, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$541	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$541, DW_AT_type(*$C$DW$T$47)
	.dwendtag $C$DW$48


$C$DW$49	.dwtag  DW_TAG_subprogram, DW_AT_name("uint32be")
	.dwattr $C$DW$49, DW_AT_declaration
	.dwattr $C$DW$49, DW_AT_TI_symbol_name("___ct__8uint32beFR8uint32be")
	.dwattr $C$DW$49, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$542	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$542, DW_AT_type(*$C$DW$T$56)
	.dwendtag $C$DW$49


$C$DW$50	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$50, DW_AT_declaration
	.dwattr $C$DW$50, DW_AT_TI_symbol_name("___as__8uint32beFUi")
	.dwattr $C$DW$50, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$543	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$543, DW_AT_type(*$C$DW$T$47)
	.dwendtag $C$DW$50


$C$DW$51	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$51, DW_AT_declaration
	.dwattr $C$DW$51, DW_AT_TI_symbol_name("___as__8uint32beFR8uint32be")
	.dwattr $C$DW$51, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$544	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$544, DW_AT_type(*$C$DW$T$56)
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
$C$DW$545	.dwtag  DW_TAG_member
	.dwattr $C$DW$545, DW_AT_type(*$C$DW$T$59)
	.dwattr $C$DW$545, DW_AT_name("a")
	.dwattr $C$DW$545, DW_AT_TI_symbol_name("_a")
	.dwattr $C$DW$545, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$545, DW_AT_accessibility(DW_ACCESS_private)

$C$DW$53	.dwtag  DW_TAG_subprogram, DW_AT_name("int64le")
	.dwattr $C$DW$53, DW_AT_declaration
	.dwattr $C$DW$53, DW_AT_TI_symbol_name("___ct__7int64leFv")
	.dwattr $C$DW$53, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$54	.dwtag  DW_TAG_subprogram, DW_AT_name("int64le")
	.dwattr $C$DW$54, DW_AT_declaration
	.dwattr $C$DW$54, DW_AT_TI_symbol_name("___ct__7int64leFL")
	.dwattr $C$DW$54, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$546	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$546, DW_AT_type(*$C$DW$T$60)
	.dwendtag $C$DW$54


$C$DW$55	.dwtag  DW_TAG_subprogram, DW_AT_name("int64le")
	.dwattr $C$DW$55, DW_AT_declaration
	.dwattr $C$DW$55, DW_AT_TI_symbol_name("___ct__7int64leFR7int64le")
	.dwattr $C$DW$55, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$547	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$547, DW_AT_type(*$C$DW$T$62)
	.dwendtag $C$DW$55


$C$DW$56	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$56, DW_AT_declaration
	.dwattr $C$DW$56, DW_AT_TI_symbol_name("___as__7int64leFL")
	.dwattr $C$DW$56, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$548	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$548, DW_AT_type(*$C$DW$T$60)
	.dwendtag $C$DW$56


$C$DW$57	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$57, DW_AT_declaration
	.dwattr $C$DW$57, DW_AT_TI_symbol_name("___as__7int64leFR7int64le")
	.dwattr $C$DW$57, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$549	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$549, DW_AT_type(*$C$DW$T$62)
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
$C$DW$550	.dwtag  DW_TAG_member
	.dwattr $C$DW$550, DW_AT_type(*$C$DW$T$59)
	.dwattr $C$DW$550, DW_AT_name("a")
	.dwattr $C$DW$550, DW_AT_TI_symbol_name("_a")
	.dwattr $C$DW$550, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$550, DW_AT_accessibility(DW_ACCESS_private)

$C$DW$59	.dwtag  DW_TAG_subprogram, DW_AT_name("uint64le")
	.dwattr $C$DW$59, DW_AT_declaration
	.dwattr $C$DW$59, DW_AT_TI_symbol_name("___ct__8uint64leFv")
	.dwattr $C$DW$59, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$60	.dwtag  DW_TAG_subprogram, DW_AT_name("uint64le")
	.dwattr $C$DW$60, DW_AT_declaration
	.dwattr $C$DW$60, DW_AT_TI_symbol_name("___ct__8uint64leFUL")
	.dwattr $C$DW$60, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$551	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$551, DW_AT_type(*$C$DW$T$66)
	.dwendtag $C$DW$60


$C$DW$61	.dwtag  DW_TAG_subprogram, DW_AT_name("uint64le")
	.dwattr $C$DW$61, DW_AT_declaration
	.dwattr $C$DW$61, DW_AT_TI_symbol_name("___ct__8uint64leFR8uint64le")
	.dwattr $C$DW$61, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$552	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$552, DW_AT_type(*$C$DW$T$68)
	.dwendtag $C$DW$61


$C$DW$62	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$62, DW_AT_declaration
	.dwattr $C$DW$62, DW_AT_TI_symbol_name("___as__8uint64leFUL")
	.dwattr $C$DW$62, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$553	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$553, DW_AT_type(*$C$DW$T$66)
	.dwendtag $C$DW$62


$C$DW$63	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$63, DW_AT_declaration
	.dwattr $C$DW$63, DW_AT_TI_symbol_name("___as__8uint64leFR8uint64le")
	.dwattr $C$DW$63, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$554	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$554, DW_AT_type(*$C$DW$T$68)
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
$C$DW$555	.dwtag  DW_TAG_member
	.dwattr $C$DW$555, DW_AT_type(*$C$DW$T$59)
	.dwattr $C$DW$555, DW_AT_name("a")
	.dwattr $C$DW$555, DW_AT_TI_symbol_name("_a")
	.dwattr $C$DW$555, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$555, DW_AT_accessibility(DW_ACCESS_private)

$C$DW$65	.dwtag  DW_TAG_subprogram, DW_AT_name("int64be")
	.dwattr $C$DW$65, DW_AT_declaration
	.dwattr $C$DW$65, DW_AT_TI_symbol_name("___ct__7int64beFv")
	.dwattr $C$DW$65, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$66	.dwtag  DW_TAG_subprogram, DW_AT_name("int64be")
	.dwattr $C$DW$66, DW_AT_declaration
	.dwattr $C$DW$66, DW_AT_TI_symbol_name("___ct__7int64beFL")
	.dwattr $C$DW$66, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$556	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$556, DW_AT_type(*$C$DW$T$60)
	.dwendtag $C$DW$66


$C$DW$67	.dwtag  DW_TAG_subprogram, DW_AT_name("int64be")
	.dwattr $C$DW$67, DW_AT_declaration
	.dwattr $C$DW$67, DW_AT_TI_symbol_name("___ct__7int64beFR7int64be")
	.dwattr $C$DW$67, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$557	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$557, DW_AT_type(*$C$DW$T$72)
	.dwendtag $C$DW$67


$C$DW$68	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$68, DW_AT_declaration
	.dwattr $C$DW$68, DW_AT_TI_symbol_name("___as__7int64beFL")
	.dwattr $C$DW$68, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$558	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$558, DW_AT_type(*$C$DW$T$60)
	.dwendtag $C$DW$68


$C$DW$69	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$69, DW_AT_declaration
	.dwattr $C$DW$69, DW_AT_TI_symbol_name("___as__7int64beFR7int64be")
	.dwattr $C$DW$69, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$559	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$559, DW_AT_type(*$C$DW$T$72)
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
$C$DW$560	.dwtag  DW_TAG_member
	.dwattr $C$DW$560, DW_AT_type(*$C$DW$T$59)
	.dwattr $C$DW$560, DW_AT_name("a")
	.dwattr $C$DW$560, DW_AT_TI_symbol_name("_a")
	.dwattr $C$DW$560, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$560, DW_AT_accessibility(DW_ACCESS_private)

$C$DW$71	.dwtag  DW_TAG_subprogram, DW_AT_name("uint64be")
	.dwattr $C$DW$71, DW_AT_declaration
	.dwattr $C$DW$71, DW_AT_TI_symbol_name("___ct__8uint64beFv")
	.dwattr $C$DW$71, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$72	.dwtag  DW_TAG_subprogram, DW_AT_name("uint64be")
	.dwattr $C$DW$72, DW_AT_declaration
	.dwattr $C$DW$72, DW_AT_TI_symbol_name("___ct__8uint64beFUL")
	.dwattr $C$DW$72, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$561	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$561, DW_AT_type(*$C$DW$T$66)
	.dwendtag $C$DW$72


$C$DW$73	.dwtag  DW_TAG_subprogram, DW_AT_name("uint64be")
	.dwattr $C$DW$73, DW_AT_declaration
	.dwattr $C$DW$73, DW_AT_TI_symbol_name("___ct__8uint64beFR8uint64be")
	.dwattr $C$DW$73, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$562	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$562, DW_AT_type(*$C$DW$T$75)
	.dwendtag $C$DW$73


$C$DW$74	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$74, DW_AT_declaration
	.dwattr $C$DW$74, DW_AT_TI_symbol_name("___as__8uint64beFUL")
	.dwattr $C$DW$74, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$563	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$563, DW_AT_type(*$C$DW$T$66)
	.dwendtag $C$DW$74


$C$DW$75	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$75, DW_AT_declaration
	.dwattr $C$DW$75, DW_AT_TI_symbol_name("___as__8uint64beFR8uint64be")
	.dwattr $C$DW$75, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$564	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$564, DW_AT_type(*$C$DW$T$75)
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
$C$DW$T$726	.dwtag  DW_TAG_typedef, DW_AT_name("va_list")
	.dwattr $C$DW$T$726, DW_AT_type(*$C$DW$T$80)
	.dwattr $C$DW$T$726, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$T$110	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$110, DW_AT_type(*$C$DW$T$79)
$C$DW$T$111	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$111, DW_AT_type(*$C$DW$T$110)
	.dwattr $C$DW$T$111, DW_AT_address_class(0x20)

$C$DW$T$123	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$123, DW_AT_type(*$C$DW$T$79)
	.dwattr $C$DW$T$123, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$123, DW_AT_byte_size(0x18)
$C$DW$565	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$565, DW_AT_upper_bound(0x17)
	.dwendtag $C$DW$T$123


$C$DW$T$308	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$308, DW_AT_type(*$C$DW$T$79)
	.dwattr $C$DW$T$308, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$308, DW_AT_byte_size(0x100)
$C$DW$566	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$566, DW_AT_upper_bound(0xff)
	.dwendtag $C$DW$T$308


$C$DW$T$353	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$353, DW_AT_type(*$C$DW$T$79)
	.dwattr $C$DW$T$353, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$353, DW_AT_byte_size(0x0e)
$C$DW$567	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$567, DW_AT_upper_bound(0x0d)
	.dwendtag $C$DW$T$353


$C$DW$T$413	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$413, DW_AT_type(*$C$DW$T$79)
	.dwattr $C$DW$T$413, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$413, DW_AT_byte_size(0x20)
$C$DW$568	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$568, DW_AT_upper_bound(0x1f)
	.dwendtag $C$DW$T$413


$C$DW$T$444	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$444, DW_AT_type(*$C$DW$T$79)
	.dwattr $C$DW$T$444, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$444, DW_AT_byte_size(0x0a)
$C$DW$569	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$569, DW_AT_upper_bound(0x09)
	.dwendtag $C$DW$T$444


$C$DW$T$445	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$445, DW_AT_type(*$C$DW$T$79)
	.dwattr $C$DW$T$445, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$445, DW_AT_byte_size(0x11)
$C$DW$570	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$570, DW_AT_upper_bound(0x10)
	.dwendtag $C$DW$T$445


$C$DW$T$446	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$446, DW_AT_type(*$C$DW$T$79)
	.dwattr $C$DW$T$446, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$446, DW_AT_byte_size(0x05)
$C$DW$571	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$571, DW_AT_upper_bound(0x04)
	.dwendtag $C$DW$T$446


$C$DW$T$447	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$447, DW_AT_type(*$C$DW$T$79)
	.dwattr $C$DW$T$447, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$447, DW_AT_byte_size(0x08)
$C$DW$572	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$572, DW_AT_upper_bound(0x07)
	.dwendtag $C$DW$T$447


$C$DW$T$85	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$85, DW_AT_name("s_os_driver_descriptor")
	.dwattr $C$DW$T$85, DW_AT_byte_size(0x18)
$C$DW$573	.dwtag  DW_TAG_member
	.dwattr $C$DW$573, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$573, DW_AT_name("id")
	.dwattr $C$DW$573, DW_AT_TI_symbol_name("_id")
	.dwattr $C$DW$573, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$573, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$574	.dwtag  DW_TAG_member
	.dwattr $C$DW$574, DW_AT_type(*$C$DW$T$78)
	.dwattr $C$DW$574, DW_AT_name("ctx")
	.dwattr $C$DW$574, DW_AT_TI_symbol_name("_ctx")
	.dwattr $C$DW$574, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$574, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$575	.dwtag  DW_TAG_member
	.dwattr $C$DW$575, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$575, DW_AT_name("own_process")
	.dwattr $C$DW$575, DW_AT_TI_symbol_name("_own_process")
	.dwattr $C$DW$575, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$575, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$576	.dwtag  DW_TAG_member
	.dwattr $C$DW$576, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$576, DW_AT_name("access")
	.dwattr $C$DW$576, DW_AT_TI_symbol_name("_access")
	.dwattr $C$DW$576, DW_AT_data_member_location[DW_OP_plus_uconst 0xa]
	.dwattr $C$DW$576, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$577	.dwtag  DW_TAG_member
	.dwattr $C$DW$577, DW_AT_type(*$C$DW$T$80)
	.dwattr $C$DW$577, DW_AT_name("path")
	.dwattr $C$DW$577, DW_AT_TI_symbol_name("_path")
	.dwattr $C$DW$577, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$577, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$578	.dwtag  DW_TAG_member
	.dwattr $C$DW$578, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$578, DW_AT_name("data")
	.dwattr $C$DW$578, DW_AT_TI_symbol_name("_data")
	.dwattr $C$DW$578, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$578, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$579	.dwtag  DW_TAG_member
	.dwattr $C$DW$579, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$579, DW_AT_name("sem")
	.dwattr $C$DW$579, DW_AT_TI_symbol_name("_sem")
	.dwattr $C$DW$579, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$579, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$77	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$77, DW_AT_declaration
	.dwattr $C$DW$77, DW_AT_TI_symbol_name("___as__22s_os_driver_descriptorFRC22s_os_driver_descriptor")
	.dwattr $C$DW$77, DW_AT_type(*$C$DW$T$81)
	.dwattr $C$DW$77, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$580	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$580, DW_AT_type(*$C$DW$T$83)
	.dwendtag $C$DW$77

	.dwendtag $C$DW$T$85

$C$DW$T$81	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$81, DW_AT_type(*$C$DW$T$85)
	.dwattr $C$DW$T$81, DW_AT_address_class(0x20)

$C$DW$T$84	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$84, DW_AT_type(*$C$DW$T$81)
	.dwattr $C$DW$T$84, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$581	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$581, DW_AT_type(*$C$DW$T$83)
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
$C$DW$582	.dwtag  DW_TAG_member
	.dwattr $C$DW$582, DW_AT_type(*$C$DW$T$78)
	.dwattr $C$DW$582, DW_AT_name("prev")
	.dwattr $C$DW$582, DW_AT_TI_symbol_name("_prev")
	.dwattr $C$DW$582, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$582, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$583	.dwtag  DW_TAG_member
	.dwattr $C$DW$583, DW_AT_type(*$C$DW$T$78)
	.dwattr $C$DW$583, DW_AT_name("next")
	.dwattr $C$DW$583, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$583, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$583, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$584	.dwtag  DW_TAG_member
	.dwattr $C$DW$584, DW_AT_type(*$C$DW$T$88)
	.dwattr $C$DW$584, DW_AT_name("open")
	.dwattr $C$DW$584, DW_AT_TI_symbol_name("_open")
	.dwattr $C$DW$584, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$584, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$585	.dwtag  DW_TAG_member
	.dwattr $C$DW$585, DW_AT_type(*$C$DW$T$90)
	.dwattr $C$DW$585, DW_AT_name("close")
	.dwattr $C$DW$585, DW_AT_TI_symbol_name("_close")
	.dwattr $C$DW$585, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$585, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$586	.dwtag  DW_TAG_member
	.dwattr $C$DW$586, DW_AT_type(*$C$DW$T$92)
	.dwattr $C$DW$586, DW_AT_name("read")
	.dwattr $C$DW$586, DW_AT_TI_symbol_name("_read")
	.dwattr $C$DW$586, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$586, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$587	.dwtag  DW_TAG_member
	.dwattr $C$DW$587, DW_AT_type(*$C$DW$T$96)
	.dwattr $C$DW$587, DW_AT_name("write")
	.dwattr $C$DW$587, DW_AT_TI_symbol_name("_write")
	.dwattr $C$DW$587, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$587, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$588	.dwtag  DW_TAG_member
	.dwattr $C$DW$588, DW_AT_type(*$C$DW$T$98)
	.dwattr $C$DW$588, DW_AT_name("ioctl")
	.dwattr $C$DW$588, DW_AT_TI_symbol_name("_ioctl")
	.dwattr $C$DW$588, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$588, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$589	.dwtag  DW_TAG_member
	.dwattr $C$DW$589, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$589, DW_AT_name("own_process")
	.dwattr $C$DW$589, DW_AT_TI_symbol_name("_own_process")
	.dwattr $C$DW$589, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr $C$DW$589, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$590	.dwtag  DW_TAG_member
	.dwattr $C$DW$590, DW_AT_type(*$C$DW$T$80)
	.dwattr $C$DW$590, DW_AT_name("name")
	.dwattr $C$DW$590, DW_AT_TI_symbol_name("_name")
	.dwattr $C$DW$590, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr $C$DW$590, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$591	.dwtag  DW_TAG_member
	.dwattr $C$DW$591, DW_AT_type(*$C$DW$T$80)
	.dwattr $C$DW$591, DW_AT_name("path")
	.dwattr $C$DW$591, DW_AT_TI_symbol_name("_path")
	.dwattr $C$DW$591, DW_AT_data_member_location[DW_OP_plus_uconst 0x24]
	.dwattr $C$DW$591, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$592	.dwtag  DW_TAG_member
	.dwattr $C$DW$592, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$592, DW_AT_name("data")
	.dwattr $C$DW$592, DW_AT_TI_symbol_name("_data")
	.dwattr $C$DW$592, DW_AT_data_member_location[DW_OP_plus_uconst 0x28]
	.dwattr $C$DW$592, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$593	.dwtag  DW_TAG_member
	.dwattr $C$DW$593, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$593, DW_AT_name("flags")
	.dwattr $C$DW$593, DW_AT_TI_symbol_name("_flags")
	.dwattr $C$DW$593, DW_AT_data_member_location[DW_OP_plus_uconst 0x2c]
	.dwattr $C$DW$593, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$78	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$78, DW_AT_declaration
	.dwattr $C$DW$78, DW_AT_TI_symbol_name("___as__19s_os_driver_contextFRC19s_os_driver_context")
	.dwattr $C$DW$78, DW_AT_type(*$C$DW$T$99)
	.dwattr $C$DW$78, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$594	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$594, DW_AT_type(*$C$DW$T$101)
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
$C$DW$595	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$595, DW_AT_type(*$C$DW$T$101)
	.dwendtag $C$DW$T$102

$C$DW$T$100	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$100, DW_AT_type(*$C$DW$T$103)
$C$DW$T$101	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$101, DW_AT_type(*$C$DW$T$100)
	.dwattr $C$DW$T$101, DW_AT_address_class(0x20)

$C$DW$T$109	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$109, DW_AT_name("s_inode")
	.dwattr $C$DW$T$109, DW_AT_byte_size(0x28)
$C$DW$596	.dwtag  DW_TAG_member
	.dwattr $C$DW$596, DW_AT_type(*$C$DW$T$104)
	.dwattr $C$DW$596, DW_AT_name("prev")
	.dwattr $C$DW$596, DW_AT_TI_symbol_name("_prev")
	.dwattr $C$DW$596, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$596, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$597	.dwtag  DW_TAG_member
	.dwattr $C$DW$597, DW_AT_type(*$C$DW$T$104)
	.dwattr $C$DW$597, DW_AT_name("next")
	.dwattr $C$DW$597, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$597, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$597, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$598	.dwtag  DW_TAG_member
	.dwattr $C$DW$598, DW_AT_type(*$C$DW$T$80)
	.dwattr $C$DW$598, DW_AT_name("name")
	.dwattr $C$DW$598, DW_AT_TI_symbol_name("_name")
	.dwattr $C$DW$598, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$598, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$599	.dwtag  DW_TAG_member
	.dwattr $C$DW$599, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$599, DW_AT_name("size")
	.dwattr $C$DW$599, DW_AT_TI_symbol_name("_size")
	.dwattr $C$DW$599, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$599, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$600	.dwtag  DW_TAG_member
	.dwattr $C$DW$600, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$600, DW_AT_name("mktime")
	.dwattr $C$DW$600, DW_AT_TI_symbol_name("_mktime")
	.dwattr $C$DW$600, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$600, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$601	.dwtag  DW_TAG_member
	.dwattr $C$DW$601, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$601, DW_AT_name("own_user")
	.dwattr $C$DW$601, DW_AT_TI_symbol_name("_own_user")
	.dwattr $C$DW$601, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr $C$DW$601, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$602	.dwtag  DW_TAG_member
	.dwattr $C$DW$602, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$602, DW_AT_name("own_group")
	.dwattr $C$DW$602, DW_AT_TI_symbol_name("_own_group")
	.dwattr $C$DW$602, DW_AT_data_member_location[DW_OP_plus_uconst 0x1e]
	.dwattr $C$DW$602, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$603	.dwtag  DW_TAG_member
	.dwattr $C$DW$603, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$603, DW_AT_name("access")
	.dwattr $C$DW$603, DW_AT_TI_symbol_name("_access")
	.dwattr $C$DW$603, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr $C$DW$603, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$604	.dwtag  DW_TAG_member
	.dwattr $C$DW$604, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$604, DW_AT_name("type")
	.dwattr $C$DW$604, DW_AT_TI_symbol_name("_type")
	.dwattr $C$DW$604, DW_AT_data_member_location[DW_OP_plus_uconst 0x24]
	.dwattr $C$DW$604, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$79	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$79, DW_AT_declaration
	.dwattr $C$DW$79, DW_AT_TI_symbol_name("___as__7s_inodeFRC7s_inode")
	.dwattr $C$DW$79, DW_AT_type(*$C$DW$T$105)
	.dwattr $C$DW$79, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$605	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$605, DW_AT_type(*$C$DW$T$107)
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
$C$DW$606	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$606, DW_AT_type(*$C$DW$T$107)
	.dwendtag $C$DW$T$108

$C$DW$T$106	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$106, DW_AT_type(*$C$DW$T$109)
$C$DW$T$107	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$107, DW_AT_type(*$C$DW$T$106)
	.dwattr $C$DW$T$107, DW_AT_address_class(0x20)

$C$DW$T$116	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$116, DW_AT_name("s_inode_create")
	.dwattr $C$DW$T$116, DW_AT_byte_size(0x08)
$C$DW$607	.dwtag  DW_TAG_member
	.dwattr $C$DW$607, DW_AT_type(*$C$DW$T$111)
	.dwattr $C$DW$607, DW_AT_name("name")
	.dwattr $C$DW$607, DW_AT_TI_symbol_name("_name")
	.dwattr $C$DW$607, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$607, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$608	.dwtag  DW_TAG_member
	.dwattr $C$DW$608, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$608, DW_AT_name("type")
	.dwattr $C$DW$608, DW_AT_TI_symbol_name("_type")
	.dwattr $C$DW$608, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$608, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$80	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$80, DW_AT_declaration
	.dwattr $C$DW$80, DW_AT_TI_symbol_name("___as__14s_inode_createFRC14s_inode_create")
	.dwattr $C$DW$80, DW_AT_type(*$C$DW$T$112)
	.dwattr $C$DW$80, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$609	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$609, DW_AT_type(*$C$DW$T$114)
	.dwendtag $C$DW$80

	.dwendtag $C$DW$T$116

$C$DW$T$112	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$112, DW_AT_type(*$C$DW$T$116)
	.dwattr $C$DW$T$112, DW_AT_address_class(0x20)

$C$DW$T$115	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$115, DW_AT_type(*$C$DW$T$112)
	.dwattr $C$DW$T$115, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$610	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$610, DW_AT_type(*$C$DW$T$114)
	.dwendtag $C$DW$T$115

$C$DW$T$113	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$113, DW_AT_type(*$C$DW$T$116)
$C$DW$T$114	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$114, DW_AT_type(*$C$DW$T$113)
	.dwattr $C$DW$T$114, DW_AT_address_class(0x20)

$C$DW$T$121	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$121, DW_AT_name("s_ipmp_stat")
	.dwattr $C$DW$T$121, DW_AT_byte_size(0x38)
$C$DW$611	.dwtag  DW_TAG_member
	.dwattr $C$DW$611, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$611, DW_AT_name("rx_count")
	.dwattr $C$DW$611, DW_AT_TI_symbol_name("_rx_count")
	.dwattr $C$DW$611, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$611, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$612	.dwtag  DW_TAG_member
	.dwattr $C$DW$612, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$612, DW_AT_name("rx_bytes")
	.dwattr $C$DW$612, DW_AT_TI_symbol_name("_rx_bytes")
	.dwattr $C$DW$612, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$612, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$613	.dwtag  DW_TAG_member
	.dwattr $C$DW$613, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$613, DW_AT_name("rx_drop")
	.dwattr $C$DW$613, DW_AT_TI_symbol_name("_rx_drop")
	.dwattr $C$DW$613, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$613, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$614	.dwtag  DW_TAG_member
	.dwattr $C$DW$614, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$614, DW_AT_name("rx_drop_mem")
	.dwattr $C$DW$614, DW_AT_TI_symbol_name("_rx_drop_mem")
	.dwattr $C$DW$614, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$614, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$615	.dwtag  DW_TAG_member
	.dwattr $C$DW$615, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$615, DW_AT_name("rx_drop_hash")
	.dwattr $C$DW$615, DW_AT_TI_symbol_name("_rx_drop_hash")
	.dwattr $C$DW$615, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr $C$DW$615, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$616	.dwtag  DW_TAG_member
	.dwattr $C$DW$616, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$616, DW_AT_name("tx_count")
	.dwattr $C$DW$616, DW_AT_TI_symbol_name("_tx_count")
	.dwattr $C$DW$616, DW_AT_data_member_location[DW_OP_plus_uconst 0x28]
	.dwattr $C$DW$616, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$617	.dwtag  DW_TAG_member
	.dwattr $C$DW$617, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$617, DW_AT_name("tx_bytes")
	.dwattr $C$DW$617, DW_AT_TI_symbol_name("_tx_bytes")
	.dwattr $C$DW$617, DW_AT_data_member_location[DW_OP_plus_uconst 0x30]
	.dwattr $C$DW$617, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$81	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$81, DW_AT_declaration
	.dwattr $C$DW$81, DW_AT_TI_symbol_name("___as__11s_ipmp_statFRC11s_ipmp_stat")
	.dwattr $C$DW$81, DW_AT_type(*$C$DW$T$117)
	.dwattr $C$DW$81, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$618	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$618, DW_AT_type(*$C$DW$T$119)
	.dwendtag $C$DW$81

	.dwendtag $C$DW$T$121

$C$DW$T$117	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$117, DW_AT_type(*$C$DW$T$121)
	.dwattr $C$DW$T$117, DW_AT_address_class(0x20)

$C$DW$T$120	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$120, DW_AT_type(*$C$DW$T$117)
	.dwattr $C$DW$T$120, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$619	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$619, DW_AT_type(*$C$DW$T$119)
	.dwendtag $C$DW$T$120

$C$DW$T$118	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$118, DW_AT_type(*$C$DW$T$121)
$C$DW$T$119	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$119, DW_AT_type(*$C$DW$T$118)
	.dwattr $C$DW$T$119, DW_AT_address_class(0x20)

$C$DW$T$128	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$128, DW_AT_name("s_message_link")
	.dwattr $C$DW$T$128, DW_AT_byte_size(0x24)
$C$DW$620	.dwtag  DW_TAG_member
	.dwattr $C$DW$620, DW_AT_type(*$C$DW$T$122)
	.dwattr $C$DW$620, DW_AT_name("next")
	.dwattr $C$DW$620, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$620, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$620, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$621	.dwtag  DW_TAG_member
	.dwattr $C$DW$621, DW_AT_type(*$C$DW$T$122)
	.dwattr $C$DW$621, DW_AT_name("prev")
	.dwattr $C$DW$621, DW_AT_TI_symbol_name("_prev")
	.dwattr $C$DW$621, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$621, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$622	.dwtag  DW_TAG_member
	.dwattr $C$DW$622, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$622, DW_AT_name("id")
	.dwattr $C$DW$622, DW_AT_TI_symbol_name("_id")
	.dwattr $C$DW$622, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$622, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$623	.dwtag  DW_TAG_member
	.dwattr $C$DW$623, DW_AT_type(*$C$DW$T$123)
	.dwattr $C$DW$623, DW_AT_name("name")
	.dwattr $C$DW$623, DW_AT_TI_symbol_name("_name")
	.dwattr $C$DW$623, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$623, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$82	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$82, DW_AT_declaration
	.dwattr $C$DW$82, DW_AT_TI_symbol_name("___as__14s_message_linkFRC14s_message_link")
	.dwattr $C$DW$82, DW_AT_type(*$C$DW$T$124)
	.dwattr $C$DW$82, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$624	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$624, DW_AT_type(*$C$DW$T$126)
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
$C$DW$625	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$625, DW_AT_type(*$C$DW$T$126)
	.dwendtag $C$DW$T$127

$C$DW$T$125	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$125, DW_AT_type(*$C$DW$T$128)
$C$DW$T$126	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$126, DW_AT_type(*$C$DW$T$125)
	.dwattr $C$DW$T$126, DW_AT_address_class(0x20)

$C$DW$T$134	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$134, DW_AT_name("s_message_queue")
	.dwattr $C$DW$T$134, DW_AT_byte_size(0x10)
$C$DW$626	.dwtag  DW_TAG_member
	.dwattr $C$DW$626, DW_AT_type(*$C$DW$T$129)
	.dwattr $C$DW$626, DW_AT_name("first")
	.dwattr $C$DW$626, DW_AT_TI_symbol_name("_first")
	.dwattr $C$DW$626, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$626, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$627	.dwtag  DW_TAG_member
	.dwattr $C$DW$627, DW_AT_type(*$C$DW$T$129)
	.dwattr $C$DW$627, DW_AT_name("last")
	.dwattr $C$DW$627, DW_AT_TI_symbol_name("_last")
	.dwattr $C$DW$627, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$627, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$628	.dwtag  DW_TAG_member
	.dwattr $C$DW$628, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$628, DW_AT_name("syn_sem")
	.dwattr $C$DW$628, DW_AT_TI_symbol_name("_syn_sem")
	.dwattr $C$DW$628, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$628, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$629	.dwtag  DW_TAG_member
	.dwattr $C$DW$629, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$629, DW_AT_name("count_sem")
	.dwattr $C$DW$629, DW_AT_TI_symbol_name("_count_sem")
	.dwattr $C$DW$629, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$629, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$83	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$83, DW_AT_declaration
	.dwattr $C$DW$83, DW_AT_TI_symbol_name("___as__15s_message_queueFRC15s_message_queue")
	.dwattr $C$DW$83, DW_AT_type(*$C$DW$T$130)
	.dwattr $C$DW$83, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$630	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$630, DW_AT_type(*$C$DW$T$132)
	.dwendtag $C$DW$83

	.dwendtag $C$DW$T$134

$C$DW$T$130	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$130, DW_AT_type(*$C$DW$T$134)
	.dwattr $C$DW$T$130, DW_AT_address_class(0x20)

$C$DW$T$133	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$133, DW_AT_type(*$C$DW$T$130)
	.dwattr $C$DW$T$133, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$631	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$631, DW_AT_type(*$C$DW$T$132)
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
$C$DW$632	.dwtag  DW_TAG_member
	.dwattr $C$DW$632, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$632, DW_AT_name("next")
	.dwattr $C$DW$632, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$632, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$632, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$633	.dwtag  DW_TAG_member
	.dwattr $C$DW$633, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$633, DW_AT_name("prev")
	.dwattr $C$DW$633, DW_AT_TI_symbol_name("_prev")
	.dwattr $C$DW$633, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$633, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$634	.dwtag  DW_TAG_member
	.dwattr $C$DW$634, DW_AT_type(*$C$DW$T$122)
	.dwattr $C$DW$634, DW_AT_name("route")
	.dwattr $C$DW$634, DW_AT_TI_symbol_name("_route")
	.dwattr $C$DW$634, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$634, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$635	.dwtag  DW_TAG_member
	.dwattr $C$DW$635, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$635, DW_AT_name("route_count")
	.dwattr $C$DW$635, DW_AT_TI_symbol_name("_route_count")
	.dwattr $C$DW$635, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$635, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$636	.dwtag  DW_TAG_member
	.dwattr $C$DW$636, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$636, DW_AT_name("limit_sem")
	.dwattr $C$DW$636, DW_AT_TI_symbol_name("_limit_sem")
	.dwattr $C$DW$636, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$636, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$637	.dwtag  DW_TAG_member
	.dwattr $C$DW$637, DW_AT_type(*$C$DW$T$136)
	.dwattr $C$DW$637, DW_AT_name("outq")
	.dwattr $C$DW$637, DW_AT_TI_symbol_name("_outq")
	.dwattr $C$DW$637, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$637, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$84	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$84, DW_AT_declaration
	.dwattr $C$DW$84, DW_AT_TI_symbol_name("___as__14s_message_pipeFRC14s_message_pipe")
	.dwattr $C$DW$84, DW_AT_type(*$C$DW$T$137)
	.dwattr $C$DW$84, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$638	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$638, DW_AT_type(*$C$DW$T$139)
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
$C$DW$639	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$639, DW_AT_type(*$C$DW$T$139)
	.dwendtag $C$DW$T$140

$C$DW$T$138	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$138, DW_AT_type(*$C$DW$T$141)
$C$DW$T$139	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$139, DW_AT_type(*$C$DW$T$138)
	.dwattr $C$DW$T$139, DW_AT_address_class(0x20)

$C$DW$T$146	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$146, DW_AT_name("s_message")
	.dwattr $C$DW$T$146, DW_AT_byte_size(0x1c)
$C$DW$640	.dwtag  DW_TAG_member
	.dwattr $C$DW$640, DW_AT_type(*$C$DW$T$129)
	.dwattr $C$DW$640, DW_AT_name("prev")
	.dwattr $C$DW$640, DW_AT_TI_symbol_name("_prev")
	.dwattr $C$DW$640, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$640, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$641	.dwtag  DW_TAG_member
	.dwattr $C$DW$641, DW_AT_type(*$C$DW$T$129)
	.dwattr $C$DW$641, DW_AT_name("next")
	.dwattr $C$DW$641, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$641, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$641, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$642	.dwtag  DW_TAG_member
	.dwattr $C$DW$642, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$642, DW_AT_name("pipe")
	.dwattr $C$DW$642, DW_AT_TI_symbol_name("_pipe")
	.dwattr $C$DW$642, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$642, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$643	.dwtag  DW_TAG_member
	.dwattr $C$DW$643, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$643, DW_AT_name("from")
	.dwattr $C$DW$643, DW_AT_TI_symbol_name("_from")
	.dwattr $C$DW$643, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$643, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$644	.dwtag  DW_TAG_member
	.dwattr $C$DW$644, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$644, DW_AT_name("to")
	.dwattr $C$DW$644, DW_AT_TI_symbol_name("_to")
	.dwattr $C$DW$644, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$644, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$645	.dwtag  DW_TAG_member
	.dwattr $C$DW$645, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$645, DW_AT_name("length")
	.dwattr $C$DW$645, DW_AT_TI_symbol_name("_length")
	.dwattr $C$DW$645, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$645, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$646	.dwtag  DW_TAG_member
	.dwattr $C$DW$646, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$646, DW_AT_name("data")
	.dwattr $C$DW$646, DW_AT_TI_symbol_name("_data")
	.dwattr $C$DW$646, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$646, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$85	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$85, DW_AT_declaration
	.dwattr $C$DW$85, DW_AT_TI_symbol_name("___as__9s_messageFRC9s_message")
	.dwattr $C$DW$85, DW_AT_type(*$C$DW$T$142)
	.dwattr $C$DW$85, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$647	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$647, DW_AT_type(*$C$DW$T$144)
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
$C$DW$648	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$648, DW_AT_type(*$C$DW$T$144)
	.dwendtag $C$DW$T$145

$C$DW$T$143	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$143, DW_AT_type(*$C$DW$T$146)
$C$DW$T$144	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$144, DW_AT_type(*$C$DW$T$143)
	.dwattr $C$DW$T$144, DW_AT_address_class(0x20)

$C$DW$T$151	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$151, DW_AT_name("s_message_context")
	.dwattr $C$DW$T$151, DW_AT_byte_size(0x0c)
$C$DW$649	.dwtag  DW_TAG_member
	.dwattr $C$DW$649, DW_AT_type(*$C$DW$T$136)
	.dwattr $C$DW$649, DW_AT_name("inq")
	.dwattr $C$DW$649, DW_AT_TI_symbol_name("_inq")
	.dwattr $C$DW$649, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$649, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$650	.dwtag  DW_TAG_member
	.dwattr $C$DW$650, DW_AT_type(*$C$DW$T$136)
	.dwattr $C$DW$650, DW_AT_name("outq")
	.dwattr $C$DW$650, DW_AT_TI_symbol_name("_outq")
	.dwattr $C$DW$650, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$650, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$651	.dwtag  DW_TAG_member
	.dwattr $C$DW$651, DW_AT_type(*$C$DW$T$135)
	.dwattr $C$DW$651, DW_AT_name("pipe")
	.dwattr $C$DW$651, DW_AT_TI_symbol_name("_pipe")
	.dwattr $C$DW$651, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$651, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$86	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$86, DW_AT_declaration
	.dwattr $C$DW$86, DW_AT_TI_symbol_name("___as__17s_message_contextFRC17s_message_context")
	.dwattr $C$DW$86, DW_AT_type(*$C$DW$T$147)
	.dwattr $C$DW$86, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$652	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$652, DW_AT_type(*$C$DW$T$149)
	.dwendtag $C$DW$86

	.dwendtag $C$DW$T$151

$C$DW$T$147	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$147, DW_AT_type(*$C$DW$T$151)
	.dwattr $C$DW$T$147, DW_AT_address_class(0x20)

$C$DW$T$150	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$150, DW_AT_type(*$C$DW$T$147)
	.dwattr $C$DW$T$150, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$653	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$653, DW_AT_type(*$C$DW$T$149)
	.dwendtag $C$DW$T$150

$C$DW$T$148	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$148, DW_AT_type(*$C$DW$T$151)
$C$DW$T$149	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$149, DW_AT_type(*$C$DW$T$148)
	.dwattr $C$DW$T$149, DW_AT_address_class(0x20)

$C$DW$T$156	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$156, DW_AT_name("s_os_register")
	.dwattr $C$DW$T$156, DW_AT_byte_size(0x104)
$C$DW$654	.dwtag  DW_TAG_member
	.dwattr $C$DW$654, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$654, DW_AT_name("a0")
	.dwattr $C$DW$654, DW_AT_TI_symbol_name("_a0")
	.dwattr $C$DW$654, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$654, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$655	.dwtag  DW_TAG_member
	.dwattr $C$DW$655, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$655, DW_AT_name("a1")
	.dwattr $C$DW$655, DW_AT_TI_symbol_name("_a1")
	.dwattr $C$DW$655, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$655, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$656	.dwtag  DW_TAG_member
	.dwattr $C$DW$656, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$656, DW_AT_name("b0")
	.dwattr $C$DW$656, DW_AT_TI_symbol_name("_b0")
	.dwattr $C$DW$656, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$656, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$657	.dwtag  DW_TAG_member
	.dwattr $C$DW$657, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$657, DW_AT_name("b1")
	.dwattr $C$DW$657, DW_AT_TI_symbol_name("_b1")
	.dwattr $C$DW$657, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$657, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$658	.dwtag  DW_TAG_member
	.dwattr $C$DW$658, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$658, DW_AT_name("a2")
	.dwattr $C$DW$658, DW_AT_TI_symbol_name("_a2")
	.dwattr $C$DW$658, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$658, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$659	.dwtag  DW_TAG_member
	.dwattr $C$DW$659, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$659, DW_AT_name("a3")
	.dwattr $C$DW$659, DW_AT_TI_symbol_name("_a3")
	.dwattr $C$DW$659, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$659, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$660	.dwtag  DW_TAG_member
	.dwattr $C$DW$660, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$660, DW_AT_name("b2")
	.dwattr $C$DW$660, DW_AT_TI_symbol_name("_b2")
	.dwattr $C$DW$660, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$660, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$661	.dwtag  DW_TAG_member
	.dwattr $C$DW$661, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$661, DW_AT_name("b3")
	.dwattr $C$DW$661, DW_AT_TI_symbol_name("_b3")
	.dwattr $C$DW$661, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr $C$DW$661, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$662	.dwtag  DW_TAG_member
	.dwattr $C$DW$662, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$662, DW_AT_name("a4")
	.dwattr $C$DW$662, DW_AT_TI_symbol_name("_a4")
	.dwattr $C$DW$662, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr $C$DW$662, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$663	.dwtag  DW_TAG_member
	.dwattr $C$DW$663, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$663, DW_AT_name("a5")
	.dwattr $C$DW$663, DW_AT_TI_symbol_name("_a5")
	.dwattr $C$DW$663, DW_AT_data_member_location[DW_OP_plus_uconst 0x24]
	.dwattr $C$DW$663, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$664	.dwtag  DW_TAG_member
	.dwattr $C$DW$664, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$664, DW_AT_name("b4")
	.dwattr $C$DW$664, DW_AT_TI_symbol_name("_b4")
	.dwattr $C$DW$664, DW_AT_data_member_location[DW_OP_plus_uconst 0x28]
	.dwattr $C$DW$664, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$665	.dwtag  DW_TAG_member
	.dwattr $C$DW$665, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$665, DW_AT_name("b5")
	.dwattr $C$DW$665, DW_AT_TI_symbol_name("_b5")
	.dwattr $C$DW$665, DW_AT_data_member_location[DW_OP_plus_uconst 0x2c]
	.dwattr $C$DW$665, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$666	.dwtag  DW_TAG_member
	.dwattr $C$DW$666, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$666, DW_AT_name("a6")
	.dwattr $C$DW$666, DW_AT_TI_symbol_name("_a6")
	.dwattr $C$DW$666, DW_AT_data_member_location[DW_OP_plus_uconst 0x30]
	.dwattr $C$DW$666, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$667	.dwtag  DW_TAG_member
	.dwattr $C$DW$667, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$667, DW_AT_name("a7")
	.dwattr $C$DW$667, DW_AT_TI_symbol_name("_a7")
	.dwattr $C$DW$667, DW_AT_data_member_location[DW_OP_plus_uconst 0x34]
	.dwattr $C$DW$667, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$668	.dwtag  DW_TAG_member
	.dwattr $C$DW$668, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$668, DW_AT_name("b6")
	.dwattr $C$DW$668, DW_AT_TI_symbol_name("_b6")
	.dwattr $C$DW$668, DW_AT_data_member_location[DW_OP_plus_uconst 0x38]
	.dwattr $C$DW$668, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$669	.dwtag  DW_TAG_member
	.dwattr $C$DW$669, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$669, DW_AT_name("b7")
	.dwattr $C$DW$669, DW_AT_TI_symbol_name("_b7")
	.dwattr $C$DW$669, DW_AT_data_member_location[DW_OP_plus_uconst 0x3c]
	.dwattr $C$DW$669, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$670	.dwtag  DW_TAG_member
	.dwattr $C$DW$670, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$670, DW_AT_name("a8")
	.dwattr $C$DW$670, DW_AT_TI_symbol_name("_a8")
	.dwattr $C$DW$670, DW_AT_data_member_location[DW_OP_plus_uconst 0x40]
	.dwattr $C$DW$670, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$671	.dwtag  DW_TAG_member
	.dwattr $C$DW$671, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$671, DW_AT_name("a9")
	.dwattr $C$DW$671, DW_AT_TI_symbol_name("_a9")
	.dwattr $C$DW$671, DW_AT_data_member_location[DW_OP_plus_uconst 0x44]
	.dwattr $C$DW$671, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$672	.dwtag  DW_TAG_member
	.dwattr $C$DW$672, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$672, DW_AT_name("b8")
	.dwattr $C$DW$672, DW_AT_TI_symbol_name("_b8")
	.dwattr $C$DW$672, DW_AT_data_member_location[DW_OP_plus_uconst 0x48]
	.dwattr $C$DW$672, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$673	.dwtag  DW_TAG_member
	.dwattr $C$DW$673, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$673, DW_AT_name("b9")
	.dwattr $C$DW$673, DW_AT_TI_symbol_name("_b9")
	.dwattr $C$DW$673, DW_AT_data_member_location[DW_OP_plus_uconst 0x4c]
	.dwattr $C$DW$673, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$674	.dwtag  DW_TAG_member
	.dwattr $C$DW$674, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$674, DW_AT_name("a10")
	.dwattr $C$DW$674, DW_AT_TI_symbol_name("_a10")
	.dwattr $C$DW$674, DW_AT_data_member_location[DW_OP_plus_uconst 0x50]
	.dwattr $C$DW$674, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$675	.dwtag  DW_TAG_member
	.dwattr $C$DW$675, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$675, DW_AT_name("a11")
	.dwattr $C$DW$675, DW_AT_TI_symbol_name("_a11")
	.dwattr $C$DW$675, DW_AT_data_member_location[DW_OP_plus_uconst 0x54]
	.dwattr $C$DW$675, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$676	.dwtag  DW_TAG_member
	.dwattr $C$DW$676, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$676, DW_AT_name("b10")
	.dwattr $C$DW$676, DW_AT_TI_symbol_name("_b10")
	.dwattr $C$DW$676, DW_AT_data_member_location[DW_OP_plus_uconst 0x58]
	.dwattr $C$DW$676, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$677	.dwtag  DW_TAG_member
	.dwattr $C$DW$677, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$677, DW_AT_name("b11")
	.dwattr $C$DW$677, DW_AT_TI_symbol_name("_b11")
	.dwattr $C$DW$677, DW_AT_data_member_location[DW_OP_plus_uconst 0x5c]
	.dwattr $C$DW$677, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$678	.dwtag  DW_TAG_member
	.dwattr $C$DW$678, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$678, DW_AT_name("a12")
	.dwattr $C$DW$678, DW_AT_TI_symbol_name("_a12")
	.dwattr $C$DW$678, DW_AT_data_member_location[DW_OP_plus_uconst 0x60]
	.dwattr $C$DW$678, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$679	.dwtag  DW_TAG_member
	.dwattr $C$DW$679, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$679, DW_AT_name("a13")
	.dwattr $C$DW$679, DW_AT_TI_symbol_name("_a13")
	.dwattr $C$DW$679, DW_AT_data_member_location[DW_OP_plus_uconst 0x64]
	.dwattr $C$DW$679, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$680	.dwtag  DW_TAG_member
	.dwattr $C$DW$680, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$680, DW_AT_name("b12")
	.dwattr $C$DW$680, DW_AT_TI_symbol_name("_b12")
	.dwattr $C$DW$680, DW_AT_data_member_location[DW_OP_plus_uconst 0x68]
	.dwattr $C$DW$680, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$681	.dwtag  DW_TAG_member
	.dwattr $C$DW$681, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$681, DW_AT_name("_b13")
	.dwattr $C$DW$681, DW_AT_TI_symbol_name("__b13")
	.dwattr $C$DW$681, DW_AT_data_member_location[DW_OP_plus_uconst 0x6c]
	.dwattr $C$DW$681, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$682	.dwtag  DW_TAG_member
	.dwattr $C$DW$682, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$682, DW_AT_name("a14")
	.dwattr $C$DW$682, DW_AT_TI_symbol_name("_a14")
	.dwattr $C$DW$682, DW_AT_data_member_location[DW_OP_plus_uconst 0x70]
	.dwattr $C$DW$682, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$683	.dwtag  DW_TAG_member
	.dwattr $C$DW$683, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$683, DW_AT_name("a15")
	.dwattr $C$DW$683, DW_AT_TI_symbol_name("_a15")
	.dwattr $C$DW$683, DW_AT_data_member_location[DW_OP_plus_uconst 0x74]
	.dwattr $C$DW$683, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$684	.dwtag  DW_TAG_member
	.dwattr $C$DW$684, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$684, DW_AT_name("b14")
	.dwattr $C$DW$684, DW_AT_TI_symbol_name("_b14")
	.dwattr $C$DW$684, DW_AT_data_member_location[DW_OP_plus_uconst 0x78]
	.dwattr $C$DW$684, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$685	.dwtag  DW_TAG_member
	.dwattr $C$DW$685, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$685, DW_AT_name("b15")
	.dwattr $C$DW$685, DW_AT_TI_symbol_name("_b15")
	.dwattr $C$DW$685, DW_AT_data_member_location[DW_OP_plus_uconst 0x7c]
	.dwattr $C$DW$685, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$686	.dwtag  DW_TAG_member
	.dwattr $C$DW$686, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$686, DW_AT_name("a16")
	.dwattr $C$DW$686, DW_AT_TI_symbol_name("_a16")
	.dwattr $C$DW$686, DW_AT_data_member_location[DW_OP_plus_uconst 0x80]
	.dwattr $C$DW$686, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$687	.dwtag  DW_TAG_member
	.dwattr $C$DW$687, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$687, DW_AT_name("a17")
	.dwattr $C$DW$687, DW_AT_TI_symbol_name("_a17")
	.dwattr $C$DW$687, DW_AT_data_member_location[DW_OP_plus_uconst 0x84]
	.dwattr $C$DW$687, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$688	.dwtag  DW_TAG_member
	.dwattr $C$DW$688, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$688, DW_AT_name("b16")
	.dwattr $C$DW$688, DW_AT_TI_symbol_name("_b16")
	.dwattr $C$DW$688, DW_AT_data_member_location[DW_OP_plus_uconst 0x88]
	.dwattr $C$DW$688, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$689	.dwtag  DW_TAG_member
	.dwattr $C$DW$689, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$689, DW_AT_name("b17")
	.dwattr $C$DW$689, DW_AT_TI_symbol_name("_b17")
	.dwattr $C$DW$689, DW_AT_data_member_location[DW_OP_plus_uconst 0x8c]
	.dwattr $C$DW$689, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$690	.dwtag  DW_TAG_member
	.dwattr $C$DW$690, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$690, DW_AT_name("a18")
	.dwattr $C$DW$690, DW_AT_TI_symbol_name("_a18")
	.dwattr $C$DW$690, DW_AT_data_member_location[DW_OP_plus_uconst 0x90]
	.dwattr $C$DW$690, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$691	.dwtag  DW_TAG_member
	.dwattr $C$DW$691, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$691, DW_AT_name("a19")
	.dwattr $C$DW$691, DW_AT_TI_symbol_name("_a19")
	.dwattr $C$DW$691, DW_AT_data_member_location[DW_OP_plus_uconst 0x94]
	.dwattr $C$DW$691, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$692	.dwtag  DW_TAG_member
	.dwattr $C$DW$692, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$692, DW_AT_name("b18")
	.dwattr $C$DW$692, DW_AT_TI_symbol_name("_b18")
	.dwattr $C$DW$692, DW_AT_data_member_location[DW_OP_plus_uconst 0x98]
	.dwattr $C$DW$692, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$693	.dwtag  DW_TAG_member
	.dwattr $C$DW$693, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$693, DW_AT_name("b19")
	.dwattr $C$DW$693, DW_AT_TI_symbol_name("_b19")
	.dwattr $C$DW$693, DW_AT_data_member_location[DW_OP_plus_uconst 0x9c]
	.dwattr $C$DW$693, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$694	.dwtag  DW_TAG_member
	.dwattr $C$DW$694, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$694, DW_AT_name("a20")
	.dwattr $C$DW$694, DW_AT_TI_symbol_name("_a20")
	.dwattr $C$DW$694, DW_AT_data_member_location[DW_OP_plus_uconst 0xa0]
	.dwattr $C$DW$694, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$695	.dwtag  DW_TAG_member
	.dwattr $C$DW$695, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$695, DW_AT_name("a21")
	.dwattr $C$DW$695, DW_AT_TI_symbol_name("_a21")
	.dwattr $C$DW$695, DW_AT_data_member_location[DW_OP_plus_uconst 0xa4]
	.dwattr $C$DW$695, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$696	.dwtag  DW_TAG_member
	.dwattr $C$DW$696, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$696, DW_AT_name("b20")
	.dwattr $C$DW$696, DW_AT_TI_symbol_name("_b20")
	.dwattr $C$DW$696, DW_AT_data_member_location[DW_OP_plus_uconst 0xa8]
	.dwattr $C$DW$696, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$697	.dwtag  DW_TAG_member
	.dwattr $C$DW$697, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$697, DW_AT_name("b21")
	.dwattr $C$DW$697, DW_AT_TI_symbol_name("_b21")
	.dwattr $C$DW$697, DW_AT_data_member_location[DW_OP_plus_uconst 0xac]
	.dwattr $C$DW$697, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$698	.dwtag  DW_TAG_member
	.dwattr $C$DW$698, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$698, DW_AT_name("a22")
	.dwattr $C$DW$698, DW_AT_TI_symbol_name("_a22")
	.dwattr $C$DW$698, DW_AT_data_member_location[DW_OP_plus_uconst 0xb0]
	.dwattr $C$DW$698, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$699	.dwtag  DW_TAG_member
	.dwattr $C$DW$699, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$699, DW_AT_name("a23")
	.dwattr $C$DW$699, DW_AT_TI_symbol_name("_a23")
	.dwattr $C$DW$699, DW_AT_data_member_location[DW_OP_plus_uconst 0xb4]
	.dwattr $C$DW$699, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$700	.dwtag  DW_TAG_member
	.dwattr $C$DW$700, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$700, DW_AT_name("b22")
	.dwattr $C$DW$700, DW_AT_TI_symbol_name("_b22")
	.dwattr $C$DW$700, DW_AT_data_member_location[DW_OP_plus_uconst 0xb8]
	.dwattr $C$DW$700, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$701	.dwtag  DW_TAG_member
	.dwattr $C$DW$701, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$701, DW_AT_name("b23")
	.dwattr $C$DW$701, DW_AT_TI_symbol_name("_b23")
	.dwattr $C$DW$701, DW_AT_data_member_location[DW_OP_plus_uconst 0xbc]
	.dwattr $C$DW$701, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$702	.dwtag  DW_TAG_member
	.dwattr $C$DW$702, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$702, DW_AT_name("a24")
	.dwattr $C$DW$702, DW_AT_TI_symbol_name("_a24")
	.dwattr $C$DW$702, DW_AT_data_member_location[DW_OP_plus_uconst 0xc0]
	.dwattr $C$DW$702, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$703	.dwtag  DW_TAG_member
	.dwattr $C$DW$703, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$703, DW_AT_name("a25")
	.dwattr $C$DW$703, DW_AT_TI_symbol_name("_a25")
	.dwattr $C$DW$703, DW_AT_data_member_location[DW_OP_plus_uconst 0xc4]
	.dwattr $C$DW$703, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$704	.dwtag  DW_TAG_member
	.dwattr $C$DW$704, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$704, DW_AT_name("b24")
	.dwattr $C$DW$704, DW_AT_TI_symbol_name("_b24")
	.dwattr $C$DW$704, DW_AT_data_member_location[DW_OP_plus_uconst 0xc8]
	.dwattr $C$DW$704, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$705	.dwtag  DW_TAG_member
	.dwattr $C$DW$705, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$705, DW_AT_name("b25")
	.dwattr $C$DW$705, DW_AT_TI_symbol_name("_b25")
	.dwattr $C$DW$705, DW_AT_data_member_location[DW_OP_plus_uconst 0xcc]
	.dwattr $C$DW$705, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$706	.dwtag  DW_TAG_member
	.dwattr $C$DW$706, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$706, DW_AT_name("a26")
	.dwattr $C$DW$706, DW_AT_TI_symbol_name("_a26")
	.dwattr $C$DW$706, DW_AT_data_member_location[DW_OP_plus_uconst 0xd0]
	.dwattr $C$DW$706, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$707	.dwtag  DW_TAG_member
	.dwattr $C$DW$707, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$707, DW_AT_name("a27")
	.dwattr $C$DW$707, DW_AT_TI_symbol_name("_a27")
	.dwattr $C$DW$707, DW_AT_data_member_location[DW_OP_plus_uconst 0xd4]
	.dwattr $C$DW$707, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$708	.dwtag  DW_TAG_member
	.dwattr $C$DW$708, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$708, DW_AT_name("b26")
	.dwattr $C$DW$708, DW_AT_TI_symbol_name("_b26")
	.dwattr $C$DW$708, DW_AT_data_member_location[DW_OP_plus_uconst 0xd8]
	.dwattr $C$DW$708, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$709	.dwtag  DW_TAG_member
	.dwattr $C$DW$709, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$709, DW_AT_name("b27")
	.dwattr $C$DW$709, DW_AT_TI_symbol_name("_b27")
	.dwattr $C$DW$709, DW_AT_data_member_location[DW_OP_plus_uconst 0xdc]
	.dwattr $C$DW$709, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$710	.dwtag  DW_TAG_member
	.dwattr $C$DW$710, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$710, DW_AT_name("a28")
	.dwattr $C$DW$710, DW_AT_TI_symbol_name("_a28")
	.dwattr $C$DW$710, DW_AT_data_member_location[DW_OP_plus_uconst 0xe0]
	.dwattr $C$DW$710, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$711	.dwtag  DW_TAG_member
	.dwattr $C$DW$711, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$711, DW_AT_name("a29")
	.dwattr $C$DW$711, DW_AT_TI_symbol_name("_a29")
	.dwattr $C$DW$711, DW_AT_data_member_location[DW_OP_plus_uconst 0xe4]
	.dwattr $C$DW$711, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$712	.dwtag  DW_TAG_member
	.dwattr $C$DW$712, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$712, DW_AT_name("b28")
	.dwattr $C$DW$712, DW_AT_TI_symbol_name("_b28")
	.dwattr $C$DW$712, DW_AT_data_member_location[DW_OP_plus_uconst 0xe8]
	.dwattr $C$DW$712, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$713	.dwtag  DW_TAG_member
	.dwattr $C$DW$713, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$713, DW_AT_name("b29")
	.dwattr $C$DW$713, DW_AT_TI_symbol_name("_b29")
	.dwattr $C$DW$713, DW_AT_data_member_location[DW_OP_plus_uconst 0xec]
	.dwattr $C$DW$713, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$714	.dwtag  DW_TAG_member
	.dwattr $C$DW$714, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$714, DW_AT_name("a30")
	.dwattr $C$DW$714, DW_AT_TI_symbol_name("_a30")
	.dwattr $C$DW$714, DW_AT_data_member_location[DW_OP_plus_uconst 0xf0]
	.dwattr $C$DW$714, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$715	.dwtag  DW_TAG_member
	.dwattr $C$DW$715, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$715, DW_AT_name("a31")
	.dwattr $C$DW$715, DW_AT_TI_symbol_name("_a31")
	.dwattr $C$DW$715, DW_AT_data_member_location[DW_OP_plus_uconst 0xf4]
	.dwattr $C$DW$715, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$716	.dwtag  DW_TAG_member
	.dwattr $C$DW$716, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$716, DW_AT_name("b30")
	.dwattr $C$DW$716, DW_AT_TI_symbol_name("_b30")
	.dwattr $C$DW$716, DW_AT_data_member_location[DW_OP_plus_uconst 0xf8]
	.dwattr $C$DW$716, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$717	.dwtag  DW_TAG_member
	.dwattr $C$DW$717, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$717, DW_AT_name("b31")
	.dwattr $C$DW$717, DW_AT_TI_symbol_name("_b31")
	.dwattr $C$DW$717, DW_AT_data_member_location[DW_OP_plus_uconst 0xfc]
	.dwattr $C$DW$717, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$718	.dwtag  DW_TAG_member
	.dwattr $C$DW$718, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$718, DW_AT_name("amr")
	.dwattr $C$DW$718, DW_AT_TI_symbol_name("_amr")
	.dwattr $C$DW$718, DW_AT_data_member_location[DW_OP_plus_uconst 0x100]
	.dwattr $C$DW$718, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$87	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$87, DW_AT_declaration
	.dwattr $C$DW$87, DW_AT_TI_symbol_name("___as__13s_os_registerFRC13s_os_register")
	.dwattr $C$DW$87, DW_AT_type(*$C$DW$T$152)
	.dwattr $C$DW$87, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$719	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$719, DW_AT_type(*$C$DW$T$154)
	.dwendtag $C$DW$87

	.dwendtag $C$DW$T$156

$C$DW$T$152	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$152, DW_AT_type(*$C$DW$T$156)
	.dwattr $C$DW$T$152, DW_AT_address_class(0x20)

$C$DW$T$155	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$155, DW_AT_type(*$C$DW$T$152)
	.dwattr $C$DW$T$155, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$720	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$720, DW_AT_type(*$C$DW$T$154)
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
$C$DW$721	.dwtag  DW_TAG_member
	.dwattr $C$DW$721, DW_AT_type(*$C$DW$T$157)
	.dwattr $C$DW$721, DW_AT_name("p")
	.dwattr $C$DW$721, DW_AT_TI_symbol_name("_p")
	.dwattr $C$DW$721, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$721, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$722	.dwtag  DW_TAG_member
	.dwattr $C$DW$722, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$722, DW_AT_name("s")
	.dwattr $C$DW$722, DW_AT_TI_symbol_name("_s")
	.dwattr $C$DW$722, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$722, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$723	.dwtag  DW_TAG_member
	.dwattr $C$DW$723, DW_AT_type(*$C$DW$T$158)
	.dwattr $C$DW$723, DW_AT_name("next")
	.dwattr $C$DW$723, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$723, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$723, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$724	.dwtag  DW_TAG_member
	.dwattr $C$DW$724, DW_AT_type(*$C$DW$T$158)
	.dwattr $C$DW$724, DW_AT_name("prev")
	.dwattr $C$DW$724, DW_AT_TI_symbol_name("_prev")
	.dwattr $C$DW$724, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$724, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$725	.dwtag  DW_TAG_member
	.dwattr $C$DW$725, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$725, DW_AT_name("state")
	.dwattr $C$DW$725, DW_AT_TI_symbol_name("_state")
	.dwattr $C$DW$725, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$725, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$726	.dwtag  DW_TAG_member
	.dwattr $C$DW$726, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$726, DW_AT_name("unlock_at")
	.dwattr $C$DW$726, DW_AT_TI_symbol_name("_unlock_at")
	.dwattr $C$DW$726, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$726, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$88	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$88, DW_AT_declaration
	.dwattr $C$DW$88, DW_AT_TI_symbol_name("___as__11s_os_lockerFRC11s_os_locker")
	.dwattr $C$DW$88, DW_AT_type(*$C$DW$T$159)
	.dwattr $C$DW$88, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$727	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$727, DW_AT_type(*$C$DW$T$161)
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
$C$DW$728	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$728, DW_AT_type(*$C$DW$T$161)
	.dwendtag $C$DW$T$162

$C$DW$T$160	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$160, DW_AT_type(*$C$DW$T$163)
$C$DW$T$161	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$161, DW_AT_type(*$C$DW$T$160)
	.dwattr $C$DW$T$161, DW_AT_address_class(0x20)

$C$DW$T$169	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$169, DW_AT_name("s_os_mem_block")
	.dwattr $C$DW$T$169, DW_AT_byte_size(0x10)
$C$DW$729	.dwtag  DW_TAG_member
	.dwattr $C$DW$729, DW_AT_type(*$C$DW$T$164)
	.dwattr $C$DW$729, DW_AT_name("prev")
	.dwattr $C$DW$729, DW_AT_TI_symbol_name("_prev")
	.dwattr $C$DW$729, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$729, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$730	.dwtag  DW_TAG_member
	.dwattr $C$DW$730, DW_AT_type(*$C$DW$T$164)
	.dwattr $C$DW$730, DW_AT_name("next")
	.dwattr $C$DW$730, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$730, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$730, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$731	.dwtag  DW_TAG_member
	.dwattr $C$DW$731, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$731, DW_AT_name("length")
	.dwattr $C$DW$731, DW_AT_TI_symbol_name("_length")
	.dwattr $C$DW$731, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$731, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$732	.dwtag  DW_TAG_member
	.dwattr $C$DW$732, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$732, DW_AT_name("pid")
	.dwattr $C$DW$732, DW_AT_TI_symbol_name("_pid")
	.dwattr $C$DW$732, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$732, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$733	.dwtag  DW_TAG_member
	.dwattr $C$DW$733, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$733, DW_AT_name("flags")
	.dwattr $C$DW$733, DW_AT_TI_symbol_name("_flags")
	.dwattr $C$DW$733, DW_AT_data_member_location[DW_OP_plus_uconst 0xe]
	.dwattr $C$DW$733, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$89	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$89, DW_AT_declaration
	.dwattr $C$DW$89, DW_AT_TI_symbol_name("___as__14s_os_mem_blockFRC14s_os_mem_block")
	.dwattr $C$DW$89, DW_AT_type(*$C$DW$T$165)
	.dwattr $C$DW$89, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$734	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$734, DW_AT_type(*$C$DW$T$167)
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
$C$DW$735	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$735, DW_AT_type(*$C$DW$T$167)
	.dwendtag $C$DW$T$168

$C$DW$T$166	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$166, DW_AT_type(*$C$DW$T$169)
$C$DW$T$167	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$167, DW_AT_type(*$C$DW$T$166)
	.dwattr $C$DW$T$167, DW_AT_address_class(0x20)

$C$DW$T$175	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$175, DW_AT_name("s_os_heap")
	.dwattr $C$DW$T$175, DW_AT_byte_size(0x10)
$C$DW$736	.dwtag  DW_TAG_member
	.dwattr $C$DW$736, DW_AT_type(*$C$DW$T$170)
	.dwattr $C$DW$736, DW_AT_name("prev")
	.dwattr $C$DW$736, DW_AT_TI_symbol_name("_prev")
	.dwattr $C$DW$736, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$736, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$737	.dwtag  DW_TAG_member
	.dwattr $C$DW$737, DW_AT_type(*$C$DW$T$170)
	.dwattr $C$DW$737, DW_AT_name("next")
	.dwattr $C$DW$737, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$737, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$737, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$738	.dwtag  DW_TAG_member
	.dwattr $C$DW$738, DW_AT_type(*$C$DW$T$164)
	.dwattr $C$DW$738, DW_AT_name("block")
	.dwattr $C$DW$738, DW_AT_TI_symbol_name("_block")
	.dwattr $C$DW$738, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$738, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$739	.dwtag  DW_TAG_member
	.dwattr $C$DW$739, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$739, DW_AT_name("flags")
	.dwattr $C$DW$739, DW_AT_TI_symbol_name("_flags")
	.dwattr $C$DW$739, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$739, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$90	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$90, DW_AT_declaration
	.dwattr $C$DW$90, DW_AT_TI_symbol_name("___as__9s_os_heapFRC9s_os_heap")
	.dwattr $C$DW$90, DW_AT_type(*$C$DW$T$171)
	.dwattr $C$DW$90, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$740	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$740, DW_AT_type(*$C$DW$T$173)
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
$C$DW$741	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$741, DW_AT_type(*$C$DW$T$173)
	.dwendtag $C$DW$T$174

$C$DW$T$172	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$172, DW_AT_type(*$C$DW$T$175)
$C$DW$T$173	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$173, DW_AT_type(*$C$DW$T$172)
	.dwattr $C$DW$T$173, DW_AT_address_class(0x20)

$C$DW$T$180	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$180, DW_AT_name("s_os_extension_f")
	.dwattr $C$DW$T$180, DW_AT_byte_size(0x0c)
$C$DW$742	.dwtag  DW_TAG_member
	.dwattr $C$DW$742, DW_AT_type(*$C$DW$T$111)
	.dwattr $C$DW$742, DW_AT_name("f_name")
	.dwattr $C$DW$742, DW_AT_TI_symbol_name("_f_name")
	.dwattr $C$DW$742, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$742, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$743	.dwtag  DW_TAG_member
	.dwattr $C$DW$743, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$743, DW_AT_name("f_syscall_index")
	.dwattr $C$DW$743, DW_AT_TI_symbol_name("_f_syscall_index")
	.dwattr $C$DW$743, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$743, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$744	.dwtag  DW_TAG_member
	.dwattr $C$DW$744, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$744, DW_AT_name("f_ptr")
	.dwattr $C$DW$744, DW_AT_TI_symbol_name("_f_ptr")
	.dwattr $C$DW$744, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$744, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$91	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$91, DW_AT_declaration
	.dwattr $C$DW$91, DW_AT_TI_symbol_name("___as__16s_os_extension_fFRC16s_os_extension_f")
	.dwattr $C$DW$91, DW_AT_type(*$C$DW$T$176)
	.dwattr $C$DW$91, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$745	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$745, DW_AT_type(*$C$DW$T$178)
	.dwendtag $C$DW$91

	.dwendtag $C$DW$T$180

$C$DW$T$176	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$176, DW_AT_type(*$C$DW$T$180)
	.dwattr $C$DW$T$176, DW_AT_address_class(0x20)

$C$DW$T$179	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$179, DW_AT_type(*$C$DW$T$176)
	.dwattr $C$DW$T$179, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$746	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$746, DW_AT_type(*$C$DW$T$178)
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
$C$DW$747	.dwtag  DW_TAG_member
	.dwattr $C$DW$747, DW_AT_type(*$C$DW$T$181)
	.dwattr $C$DW$747, DW_AT_name("next")
	.dwattr $C$DW$747, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$747, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$747, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$748	.dwtag  DW_TAG_member
	.dwattr $C$DW$748, DW_AT_type(*$C$DW$T$181)
	.dwattr $C$DW$748, DW_AT_name("prev")
	.dwattr $C$DW$748, DW_AT_TI_symbol_name("_prev")
	.dwattr $C$DW$748, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$748, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$749	.dwtag  DW_TAG_member
	.dwattr $C$DW$749, DW_AT_type(*$C$DW$T$111)
	.dwattr $C$DW$749, DW_AT_name("name")
	.dwattr $C$DW$749, DW_AT_TI_symbol_name("_name")
	.dwattr $C$DW$749, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$749, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$750	.dwtag  DW_TAG_member
	.dwattr $C$DW$750, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$750, DW_AT_name("f_count")
	.dwattr $C$DW$750, DW_AT_TI_symbol_name("_f_count")
	.dwattr $C$DW$750, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$750, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$751	.dwtag  DW_TAG_member
	.dwattr $C$DW$751, DW_AT_type(*$C$DW$T$182)
	.dwattr $C$DW$751, DW_AT_name("f_tab")
	.dwattr $C$DW$751, DW_AT_TI_symbol_name("_f_tab")
	.dwattr $C$DW$751, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$751, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$752	.dwtag  DW_TAG_member
	.dwattr $C$DW$752, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$752, DW_AT_name("usage")
	.dwattr $C$DW$752, DW_AT_TI_symbol_name("_usage")
	.dwattr $C$DW$752, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$752, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$753	.dwtag  DW_TAG_member
	.dwattr $C$DW$753, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$753, DW_AT_name("lacc")
	.dwattr $C$DW$753, DW_AT_TI_symbol_name("_lacc")
	.dwattr $C$DW$753, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$753, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$754	.dwtag  DW_TAG_member
	.dwattr $C$DW$754, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$754, DW_AT_name("flags")
	.dwattr $C$DW$754, DW_AT_TI_symbol_name("_flags")
	.dwattr $C$DW$754, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr $C$DW$754, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$755	.dwtag  DW_TAG_member
	.dwattr $C$DW$755, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$755, DW_AT_name("own_process")
	.dwattr $C$DW$755, DW_AT_TI_symbol_name("_own_process")
	.dwattr $C$DW$755, DW_AT_data_member_location[DW_OP_plus_uconst 0x24]
	.dwattr $C$DW$755, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$92	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$92, DW_AT_declaration
	.dwattr $C$DW$92, DW_AT_TI_symbol_name("___as__14s_os_extensionFRC14s_os_extension")
	.dwattr $C$DW$92, DW_AT_type(*$C$DW$T$183)
	.dwattr $C$DW$92, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$756	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$756, DW_AT_type(*$C$DW$T$185)
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
$C$DW$757	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$757, DW_AT_type(*$C$DW$T$185)
	.dwendtag $C$DW$T$186

$C$DW$T$184	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$184, DW_AT_type(*$C$DW$T$187)
$C$DW$T$185	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$185, DW_AT_type(*$C$DW$T$184)
	.dwattr $C$DW$T$185, DW_AT_address_class(0x20)

$C$DW$T$193	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$193, DW_AT_name("s_os_extension_link")
	.dwattr $C$DW$T$193, DW_AT_byte_size(0x0c)
$C$DW$758	.dwtag  DW_TAG_member
	.dwattr $C$DW$758, DW_AT_type(*$C$DW$T$188)
	.dwattr $C$DW$758, DW_AT_name("prev")
	.dwattr $C$DW$758, DW_AT_TI_symbol_name("_prev")
	.dwattr $C$DW$758, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$758, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$759	.dwtag  DW_TAG_member
	.dwattr $C$DW$759, DW_AT_type(*$C$DW$T$188)
	.dwattr $C$DW$759, DW_AT_name("next")
	.dwattr $C$DW$759, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$759, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$759, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$760	.dwtag  DW_TAG_member
	.dwattr $C$DW$760, DW_AT_type(*$C$DW$T$181)
	.dwattr $C$DW$760, DW_AT_name("e")
	.dwattr $C$DW$760, DW_AT_TI_symbol_name("_e")
	.dwattr $C$DW$760, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$760, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$93	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$93, DW_AT_declaration
	.dwattr $C$DW$93, DW_AT_TI_symbol_name("___as__19s_os_extension_linkFRC19s_os_extension_link")
	.dwattr $C$DW$93, DW_AT_type(*$C$DW$T$189)
	.dwattr $C$DW$93, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$761	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$761, DW_AT_type(*$C$DW$T$191)
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
$C$DW$762	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$762, DW_AT_type(*$C$DW$T$191)
	.dwendtag $C$DW$T$192

$C$DW$T$190	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$190, DW_AT_type(*$C$DW$T$193)
$C$DW$T$191	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$191, DW_AT_type(*$C$DW$T$190)
	.dwattr $C$DW$T$191, DW_AT_address_class(0x20)

$C$DW$T$199	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$199, DW_AT_name("s_os_process_context")
	.dwattr $C$DW$T$199, DW_AT_byte_size(0x88)
$C$DW$763	.dwtag  DW_TAG_member
	.dwattr $C$DW$763, DW_AT_type(*$C$DW$T$194)
	.dwattr $C$DW$763, DW_AT_name("reg")
	.dwattr $C$DW$763, DW_AT_TI_symbol_name("_reg")
	.dwattr $C$DW$763, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$763, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$764	.dwtag  DW_TAG_member
	.dwattr $C$DW$764, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$764, DW_AT_name("id")
	.dwattr $C$DW$764, DW_AT_TI_symbol_name("_id")
	.dwattr $C$DW$764, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$764, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$765	.dwtag  DW_TAG_member
	.dwattr $C$DW$765, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$765, DW_AT_name("pflags")
	.dwattr $C$DW$765, DW_AT_TI_symbol_name("_pflags")
	.dwattr $C$DW$765, DW_AT_data_member_location[DW_OP_plus_uconst 0x6]
	.dwattr $C$DW$765, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$766	.dwtag  DW_TAG_member
	.dwattr $C$DW$766, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$766, DW_AT_name("peff")
	.dwattr $C$DW$766, DW_AT_TI_symbol_name("_peff")
	.dwattr $C$DW$766, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$766, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$767	.dwtag  DW_TAG_member
	.dwattr $C$DW$767, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$767, DW_AT_name("pcnt")
	.dwattr $C$DW$767, DW_AT_TI_symbol_name("_pcnt")
	.dwattr $C$DW$767, DW_AT_data_member_location[DW_OP_plus_uconst 0xa]
	.dwattr $C$DW$767, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$768	.dwtag  DW_TAG_member
	.dwattr $C$DW$768, DW_AT_type(*$C$DW$T$157)
	.dwattr $C$DW$768, DW_AT_name("next")
	.dwattr $C$DW$768, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$768, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$768, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$769	.dwtag  DW_TAG_member
	.dwattr $C$DW$769, DW_AT_type(*$C$DW$T$157)
	.dwattr $C$DW$769, DW_AT_name("prev")
	.dwattr $C$DW$769, DW_AT_TI_symbol_name("_prev")
	.dwattr $C$DW$769, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$769, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$770	.dwtag  DW_TAG_member
	.dwattr $C$DW$770, DW_AT_type(*$C$DW$T$163)
	.dwattr $C$DW$770, DW_AT_name("locker")
	.dwattr $C$DW$770, DW_AT_TI_symbol_name("_locker")
	.dwattr $C$DW$770, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$770, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$771	.dwtag  DW_TAG_member
	.dwattr $C$DW$771, DW_AT_type(*$C$DW$T$170)
	.dwattr $C$DW$771, DW_AT_name("heap")
	.dwattr $C$DW$771, DW_AT_TI_symbol_name("_heap")
	.dwattr $C$DW$771, DW_AT_data_member_location[DW_OP_plus_uconst 0x38]
	.dwattr $C$DW$771, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$772	.dwtag  DW_TAG_member
	.dwattr $C$DW$772, DW_AT_type(*$C$DW$T$164)
	.dwattr $C$DW$772, DW_AT_name("stack")
	.dwattr $C$DW$772, DW_AT_TI_symbol_name("_stack")
	.dwattr $C$DW$772, DW_AT_data_member_location[DW_OP_plus_uconst 0x3c]
	.dwattr $C$DW$772, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$773	.dwtag  DW_TAG_member
	.dwattr $C$DW$773, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$773, DW_AT_name("arg")
	.dwattr $C$DW$773, DW_AT_TI_symbol_name("_arg")
	.dwattr $C$DW$773, DW_AT_data_member_location[DW_OP_plus_uconst 0x40]
	.dwattr $C$DW$773, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$774	.dwtag  DW_TAG_member
	.dwattr $C$DW$774, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$774, DW_AT_name("arglen")
	.dwattr $C$DW$774, DW_AT_TI_symbol_name("_arglen")
	.dwattr $C$DW$774, DW_AT_data_member_location[DW_OP_plus_uconst 0x44]
	.dwattr $C$DW$774, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$775	.dwtag  DW_TAG_member
	.dwattr $C$DW$775, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$775, DW_AT_name("sfault_code")
	.dwattr $C$DW$775, DW_AT_TI_symbol_name("_sfault_code")
	.dwattr $C$DW$775, DW_AT_data_member_location[DW_OP_plus_uconst 0x48]
	.dwattr $C$DW$775, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$776	.dwtag  DW_TAG_member
	.dwattr $C$DW$776, DW_AT_type(*$C$DW$T$157)
	.dwattr $C$DW$776, DW_AT_name("parent")
	.dwattr $C$DW$776, DW_AT_TI_symbol_name("_parent")
	.dwattr $C$DW$776, DW_AT_data_member_location[DW_OP_plus_uconst 0x4c]
	.dwattr $C$DW$776, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$777	.dwtag  DW_TAG_member
	.dwattr $C$DW$777, DW_AT_type(*$C$DW$T$205)
	.dwattr $C$DW$777, DW_AT_name("msg")
	.dwattr $C$DW$777, DW_AT_TI_symbol_name("_msg")
	.dwattr $C$DW$777, DW_AT_data_member_location[DW_OP_plus_uconst 0x50]
	.dwattr $C$DW$777, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$778	.dwtag  DW_TAG_member
	.dwattr $C$DW$778, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$778, DW_AT_name("errno")
	.dwattr $C$DW$778, DW_AT_TI_symbol_name("_errno")
	.dwattr $C$DW$778, DW_AT_data_member_location[DW_OP_plus_uconst 0x78]
	.dwattr $C$DW$778, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$779	.dwtag  DW_TAG_member
	.dwattr $C$DW$779, DW_AT_type(*$C$DW$T$188)
	.dwattr $C$DW$779, DW_AT_name("ext_used")
	.dwattr $C$DW$779, DW_AT_TI_symbol_name("_ext_used")
	.dwattr $C$DW$779, DW_AT_data_member_location[DW_OP_plus_uconst 0x7c]
	.dwattr $C$DW$779, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$780	.dwtag  DW_TAG_member
	.dwattr $C$DW$780, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$780, DW_AT_name("join_sem")
	.dwattr $C$DW$780, DW_AT_TI_symbol_name("_join_sem")
	.dwattr $C$DW$780, DW_AT_data_member_location[DW_OP_plus_uconst 0x80]
	.dwattr $C$DW$780, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$94	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$94, DW_AT_declaration
	.dwattr $C$DW$94, DW_AT_TI_symbol_name("___as__20s_os_process_contextFRC20s_os_process_context")
	.dwattr $C$DW$94, DW_AT_type(*$C$DW$T$195)
	.dwattr $C$DW$94, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$781	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$781, DW_AT_type(*$C$DW$T$197)
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
$C$DW$782	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$782, DW_AT_type(*$C$DW$T$197)
	.dwendtag $C$DW$T$198

$C$DW$T$196	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$196, DW_AT_type(*$C$DW$T$199)
$C$DW$T$197	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$197, DW_AT_type(*$C$DW$T$196)
	.dwattr $C$DW$T$197, DW_AT_address_class(0x20)

$C$DW$T$205	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$205, DW_AT_name("s_message_process_data")
	.dwattr $C$DW$T$205, DW_AT_byte_size(0x28)
$C$DW$783	.dwtag  DW_TAG_member
	.dwattr $C$DW$783, DW_AT_type(*$C$DW$T$200)
	.dwattr $C$DW$783, DW_AT_name("prev")
	.dwattr $C$DW$783, DW_AT_TI_symbol_name("_prev")
	.dwattr $C$DW$783, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$783, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$784	.dwtag  DW_TAG_member
	.dwattr $C$DW$784, DW_AT_type(*$C$DW$T$200)
	.dwattr $C$DW$784, DW_AT_name("next")
	.dwattr $C$DW$784, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$784, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$784, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$785	.dwtag  DW_TAG_member
	.dwattr $C$DW$785, DW_AT_type(*$C$DW$T$157)
	.dwattr $C$DW$785, DW_AT_name("p")
	.dwattr $C$DW$785, DW_AT_TI_symbol_name("_p")
	.dwattr $C$DW$785, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$785, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$786	.dwtag  DW_TAG_member
	.dwattr $C$DW$786, DW_AT_type(*$C$DW$T$80)
	.dwattr $C$DW$786, DW_AT_name("name")
	.dwattr $C$DW$786, DW_AT_TI_symbol_name("_name")
	.dwattr $C$DW$786, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$786, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$787	.dwtag  DW_TAG_member
	.dwattr $C$DW$787, DW_AT_type(*$C$DW$T$134)
	.dwattr $C$DW$787, DW_AT_name("inq")
	.dwattr $C$DW$787, DW_AT_TI_symbol_name("_inq")
	.dwattr $C$DW$787, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$787, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$788	.dwtag  DW_TAG_member
	.dwattr $C$DW$788, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$788, DW_AT_name("avg_ppid")
	.dwattr $C$DW$788, DW_AT_TI_symbol_name("_avg_ppid")
	.dwattr $C$DW$788, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr $C$DW$788, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$789	.dwtag  DW_TAG_member
	.dwattr $C$DW$789, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$789, DW_AT_name("avg_reqid")
	.dwattr $C$DW$789, DW_AT_TI_symbol_name("_avg_reqid")
	.dwattr $C$DW$789, DW_AT_data_member_location[DW_OP_plus_uconst 0x24]
	.dwattr $C$DW$789, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$95	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$95, DW_AT_declaration
	.dwattr $C$DW$95, DW_AT_TI_symbol_name("___as__22s_message_process_dataFRC22s_message_process_data")
	.dwattr $C$DW$95, DW_AT_type(*$C$DW$T$201)
	.dwattr $C$DW$95, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$790	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$790, DW_AT_type(*$C$DW$T$203)
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
$C$DW$791	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$791, DW_AT_type(*$C$DW$T$203)
	.dwendtag $C$DW$T$204

$C$DW$T$202	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$202, DW_AT_type(*$C$DW$T$205)
$C$DW$T$203	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$203, DW_AT_type(*$C$DW$T$202)
	.dwattr $C$DW$T$203, DW_AT_address_class(0x20)

$C$DW$T$210	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$210, DW_AT_name("s_os_core_init")
	.dwattr $C$DW$T$210, DW_AT_byte_size(0x14)
$C$DW$792	.dwtag  DW_TAG_member
	.dwattr $C$DW$792, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$792, DW_AT_name("core_heap_len")
	.dwattr $C$DW$792, DW_AT_TI_symbol_name("_core_heap_len")
	.dwattr $C$DW$792, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$792, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$793	.dwtag  DW_TAG_member
	.dwattr $C$DW$793, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$793, DW_AT_name("sys_quant")
	.dwattr $C$DW$793, DW_AT_TI_symbol_name("_sys_quant")
	.dwattr $C$DW$793, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$793, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$794	.dwtag  DW_TAG_member
	.dwattr $C$DW$794, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$794, DW_AT_name("sem_list_len")
	.dwattr $C$DW$794, DW_AT_TI_symbol_name("_sem_list_len")
	.dwattr $C$DW$794, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$794, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$795	.dwtag  DW_TAG_member
	.dwattr $C$DW$795, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$795, DW_AT_name("extram_start")
	.dwattr $C$DW$795, DW_AT_TI_symbol_name("_extram_start")
	.dwattr $C$DW$795, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$795, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$796	.dwtag  DW_TAG_member
	.dwattr $C$DW$796, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$796, DW_AT_name("extram_end")
	.dwattr $C$DW$796, DW_AT_TI_symbol_name("_extram_end")
	.dwattr $C$DW$796, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$796, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$96	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$96, DW_AT_declaration
	.dwattr $C$DW$96, DW_AT_TI_symbol_name("___as__14s_os_core_initFRC14s_os_core_init")
	.dwattr $C$DW$96, DW_AT_type(*$C$DW$T$206)
	.dwattr $C$DW$96, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$797	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$797, DW_AT_type(*$C$DW$T$208)
	.dwendtag $C$DW$96

	.dwendtag $C$DW$T$210

$C$DW$T$206	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$206, DW_AT_type(*$C$DW$T$210)
	.dwattr $C$DW$T$206, DW_AT_address_class(0x20)

$C$DW$T$209	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$209, DW_AT_type(*$C$DW$T$206)
	.dwattr $C$DW$T$209, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$798	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$798, DW_AT_type(*$C$DW$T$208)
	.dwendtag $C$DW$T$209

$C$DW$T$207	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$207, DW_AT_type(*$C$DW$T$210)
$C$DW$T$208	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$208, DW_AT_type(*$C$DW$T$207)
	.dwattr $C$DW$T$208, DW_AT_address_class(0x20)

$C$DW$T$216	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$216, DW_AT_name("s_prc_attr")
	.dwattr $C$DW$T$216, DW_AT_byte_size(0x14)
$C$DW$799	.dwtag  DW_TAG_member
	.dwattr $C$DW$799, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$799, DW_AT_name("stack")
	.dwattr $C$DW$799, DW_AT_TI_symbol_name("_stack")
	.dwattr $C$DW$799, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$799, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$800	.dwtag  DW_TAG_member
	.dwattr $C$DW$800, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$800, DW_AT_name("heap")
	.dwattr $C$DW$800, DW_AT_TI_symbol_name("_heap")
	.dwattr $C$DW$800, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$800, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$801	.dwtag  DW_TAG_member
	.dwattr $C$DW$801, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$801, DW_AT_name("priority")
	.dwattr $C$DW$801, DW_AT_TI_symbol_name("_priority")
	.dwattr $C$DW$801, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$801, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$802	.dwtag  DW_TAG_member
	.dwattr $C$DW$802, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$802, DW_AT_name("bss")
	.dwattr $C$DW$802, DW_AT_TI_symbol_name("_bss")
	.dwattr $C$DW$802, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$802, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$803	.dwtag  DW_TAG_member
	.dwattr $C$DW$803, DW_AT_type(*$C$DW$T$211)
	.dwattr $C$DW$803, DW_AT_name("exit_vector")
	.dwattr $C$DW$803, DW_AT_TI_symbol_name("_exit_vector")
	.dwattr $C$DW$803, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$803, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$97	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$97, DW_AT_declaration
	.dwattr $C$DW$97, DW_AT_TI_symbol_name("___as__10s_prc_attrFRC10s_prc_attr")
	.dwattr $C$DW$97, DW_AT_type(*$C$DW$T$212)
	.dwattr $C$DW$97, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$804	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$804, DW_AT_type(*$C$DW$T$214)
	.dwendtag $C$DW$97

	.dwendtag $C$DW$T$216

$C$DW$T$212	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$212, DW_AT_type(*$C$DW$T$216)
	.dwattr $C$DW$T$212, DW_AT_address_class(0x20)

$C$DW$T$215	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$215, DW_AT_type(*$C$DW$T$212)
	.dwattr $C$DW$T$215, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$805	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$805, DW_AT_type(*$C$DW$T$214)
	.dwendtag $C$DW$T$215

$C$DW$T$213	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$213, DW_AT_type(*$C$DW$T$216)
$C$DW$T$214	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$214, DW_AT_type(*$C$DW$T$213)
	.dwattr $C$DW$T$214, DW_AT_address_class(0x20)

$C$DW$T$221	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$221, DW_AT_name("s_os_mem_stat")
	.dwattr $C$DW$T$221, DW_AT_byte_size(0x40)
$C$DW$806	.dwtag  DW_TAG_member
	.dwattr $C$DW$806, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$806, DW_AT_name("total")
	.dwattr $C$DW$806, DW_AT_TI_symbol_name("_total")
	.dwattr $C$DW$806, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$806, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$807	.dwtag  DW_TAG_member
	.dwattr $C$DW$807, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$807, DW_AT_name("used")
	.dwattr $C$DW$807, DW_AT_TI_symbol_name("_used")
	.dwattr $C$DW$807, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$807, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$808	.dwtag  DW_TAG_member
	.dwattr $C$DW$808, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$808, DW_AT_name("free")
	.dwattr $C$DW$808, DW_AT_TI_symbol_name("_free")
	.dwattr $C$DW$808, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$808, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$809	.dwtag  DW_TAG_member
	.dwattr $C$DW$809, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$809, DW_AT_name("c_desc")
	.dwattr $C$DW$809, DW_AT_TI_symbol_name("_c_desc")
	.dwattr $C$DW$809, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$809, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$810	.dwtag  DW_TAG_member
	.dwattr $C$DW$810, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$810, DW_AT_name("c_16_64")
	.dwattr $C$DW$810, DW_AT_TI_symbol_name("_c_16_64")
	.dwattr $C$DW$810, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr $C$DW$810, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$811	.dwtag  DW_TAG_member
	.dwattr $C$DW$811, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$811, DW_AT_name("c_64_256")
	.dwattr $C$DW$811, DW_AT_TI_symbol_name("_c_64_256")
	.dwattr $C$DW$811, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr $C$DW$811, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$812	.dwtag  DW_TAG_member
	.dwattr $C$DW$812, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$812, DW_AT_name("c_256_1k")
	.dwattr $C$DW$812, DW_AT_TI_symbol_name("_c_256_1k")
	.dwattr $C$DW$812, DW_AT_data_member_location[DW_OP_plus_uconst 0x24]
	.dwattr $C$DW$812, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$813	.dwtag  DW_TAG_member
	.dwattr $C$DW$813, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$813, DW_AT_name("c_1k_4k")
	.dwattr $C$DW$813, DW_AT_TI_symbol_name("_c_1k_4k")
	.dwattr $C$DW$813, DW_AT_data_member_location[DW_OP_plus_uconst 0x28]
	.dwattr $C$DW$813, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$814	.dwtag  DW_TAG_member
	.dwattr $C$DW$814, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$814, DW_AT_name("c_4k_16k")
	.dwattr $C$DW$814, DW_AT_TI_symbol_name("_c_4k_16k")
	.dwattr $C$DW$814, DW_AT_data_member_location[DW_OP_plus_uconst 0x2c]
	.dwattr $C$DW$814, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$815	.dwtag  DW_TAG_member
	.dwattr $C$DW$815, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$815, DW_AT_name("c_16k_64k")
	.dwattr $C$DW$815, DW_AT_TI_symbol_name("_c_16k_64k")
	.dwattr $C$DW$815, DW_AT_data_member_location[DW_OP_plus_uconst 0x30]
	.dwattr $C$DW$815, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$816	.dwtag  DW_TAG_member
	.dwattr $C$DW$816, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$816, DW_AT_name("c_64k_256k")
	.dwattr $C$DW$816, DW_AT_TI_symbol_name("_c_64k_256k")
	.dwattr $C$DW$816, DW_AT_data_member_location[DW_OP_plus_uconst 0x34]
	.dwattr $C$DW$816, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$817	.dwtag  DW_TAG_member
	.dwattr $C$DW$817, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$817, DW_AT_name("c_256k_1m")
	.dwattr $C$DW$817, DW_AT_TI_symbol_name("_c_256k_1m")
	.dwattr $C$DW$817, DW_AT_data_member_location[DW_OP_plus_uconst 0x38]
	.dwattr $C$DW$817, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$818	.dwtag  DW_TAG_member
	.dwattr $C$DW$818, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$818, DW_AT_name("c_1m_inf")
	.dwattr $C$DW$818, DW_AT_TI_symbol_name("_c_1m_inf")
	.dwattr $C$DW$818, DW_AT_data_member_location[DW_OP_plus_uconst 0x3c]
	.dwattr $C$DW$818, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$98	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$98, DW_AT_declaration
	.dwattr $C$DW$98, DW_AT_TI_symbol_name("___as__13s_os_mem_statFRC13s_os_mem_stat")
	.dwattr $C$DW$98, DW_AT_type(*$C$DW$T$217)
	.dwattr $C$DW$98, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$819	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$819, DW_AT_type(*$C$DW$T$219)
	.dwendtag $C$DW$98

	.dwendtag $C$DW$T$221

$C$DW$T$217	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$217, DW_AT_type(*$C$DW$T$221)
	.dwattr $C$DW$T$217, DW_AT_address_class(0x20)

$C$DW$T$220	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$220, DW_AT_type(*$C$DW$T$217)
	.dwattr $C$DW$T$220, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$820	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$820, DW_AT_type(*$C$DW$T$219)
	.dwendtag $C$DW$T$220

$C$DW$T$218	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$218, DW_AT_type(*$C$DW$T$221)
$C$DW$T$219	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$219, DW_AT_type(*$C$DW$T$218)
	.dwattr $C$DW$T$219, DW_AT_address_class(0x20)

$C$DW$T$226	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$226, DW_AT_name("s_os_heap_stat")
	.dwattr $C$DW$T$226, DW_AT_byte_size(0x3c)
$C$DW$821	.dwtag  DW_TAG_member
	.dwattr $C$DW$821, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$821, DW_AT_name("total")
	.dwattr $C$DW$821, DW_AT_TI_symbol_name("_total")
	.dwattr $C$DW$821, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$821, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$822	.dwtag  DW_TAG_member
	.dwattr $C$DW$822, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$822, DW_AT_name("used")
	.dwattr $C$DW$822, DW_AT_TI_symbol_name("_used")
	.dwattr $C$DW$822, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$822, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$823	.dwtag  DW_TAG_member
	.dwattr $C$DW$823, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$823, DW_AT_name("free")
	.dwattr $C$DW$823, DW_AT_TI_symbol_name("_free")
	.dwattr $C$DW$823, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$823, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$824	.dwtag  DW_TAG_member
	.dwattr $C$DW$824, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$824, DW_AT_name("c_desc")
	.dwattr $C$DW$824, DW_AT_TI_symbol_name("_c_desc")
	.dwattr $C$DW$824, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$824, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$825	.dwtag  DW_TAG_member
	.dwattr $C$DW$825, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$825, DW_AT_name("c_0")
	.dwattr $C$DW$825, DW_AT_TI_symbol_name("_c_0")
	.dwattr $C$DW$825, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$825, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$826	.dwtag  DW_TAG_member
	.dwattr $C$DW$826, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$826, DW_AT_name("c_4_16")
	.dwattr $C$DW$826, DW_AT_TI_symbol_name("_c_4_16")
	.dwattr $C$DW$826, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$826, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$827	.dwtag  DW_TAG_member
	.dwattr $C$DW$827, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$827, DW_AT_name("c_16_64")
	.dwattr $C$DW$827, DW_AT_TI_symbol_name("_c_16_64")
	.dwattr $C$DW$827, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$827, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$828	.dwtag  DW_TAG_member
	.dwattr $C$DW$828, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$828, DW_AT_name("c_64_256")
	.dwattr $C$DW$828, DW_AT_TI_symbol_name("_c_64_256")
	.dwattr $C$DW$828, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr $C$DW$828, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$829	.dwtag  DW_TAG_member
	.dwattr $C$DW$829, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$829, DW_AT_name("c_256_1k")
	.dwattr $C$DW$829, DW_AT_TI_symbol_name("_c_256_1k")
	.dwattr $C$DW$829, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr $C$DW$829, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$830	.dwtag  DW_TAG_member
	.dwattr $C$DW$830, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$830, DW_AT_name("c_1k_4k")
	.dwattr $C$DW$830, DW_AT_TI_symbol_name("_c_1k_4k")
	.dwattr $C$DW$830, DW_AT_data_member_location[DW_OP_plus_uconst 0x24]
	.dwattr $C$DW$830, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$831	.dwtag  DW_TAG_member
	.dwattr $C$DW$831, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$831, DW_AT_name("c_4k_16k")
	.dwattr $C$DW$831, DW_AT_TI_symbol_name("_c_4k_16k")
	.dwattr $C$DW$831, DW_AT_data_member_location[DW_OP_plus_uconst 0x28]
	.dwattr $C$DW$831, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$832	.dwtag  DW_TAG_member
	.dwattr $C$DW$832, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$832, DW_AT_name("c_16k_64k")
	.dwattr $C$DW$832, DW_AT_TI_symbol_name("_c_16k_64k")
	.dwattr $C$DW$832, DW_AT_data_member_location[DW_OP_plus_uconst 0x2c]
	.dwattr $C$DW$832, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$833	.dwtag  DW_TAG_member
	.dwattr $C$DW$833, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$833, DW_AT_name("c_64k_256k")
	.dwattr $C$DW$833, DW_AT_TI_symbol_name("_c_64k_256k")
	.dwattr $C$DW$833, DW_AT_data_member_location[DW_OP_plus_uconst 0x30]
	.dwattr $C$DW$833, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$834	.dwtag  DW_TAG_member
	.dwattr $C$DW$834, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$834, DW_AT_name("c_256k_1m")
	.dwattr $C$DW$834, DW_AT_TI_symbol_name("_c_256k_1m")
	.dwattr $C$DW$834, DW_AT_data_member_location[DW_OP_plus_uconst 0x34]
	.dwattr $C$DW$834, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$835	.dwtag  DW_TAG_member
	.dwattr $C$DW$835, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$835, DW_AT_name("c_1m_inf")
	.dwattr $C$DW$835, DW_AT_TI_symbol_name("_c_1m_inf")
	.dwattr $C$DW$835, DW_AT_data_member_location[DW_OP_plus_uconst 0x38]
	.dwattr $C$DW$835, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$99	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$99, DW_AT_declaration
	.dwattr $C$DW$99, DW_AT_TI_symbol_name("___as__14s_os_heap_statFRC14s_os_heap_stat")
	.dwattr $C$DW$99, DW_AT_type(*$C$DW$T$222)
	.dwattr $C$DW$99, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$836	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$836, DW_AT_type(*$C$DW$T$224)
	.dwendtag $C$DW$99

	.dwendtag $C$DW$T$226

$C$DW$T$222	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$222, DW_AT_type(*$C$DW$T$226)
	.dwattr $C$DW$T$222, DW_AT_address_class(0x20)

$C$DW$T$225	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$225, DW_AT_type(*$C$DW$T$222)
	.dwattr $C$DW$T$225, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$837	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$837, DW_AT_type(*$C$DW$T$224)
	.dwendtag $C$DW$T$225

$C$DW$T$223	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$223, DW_AT_type(*$C$DW$T$226)
$C$DW$T$224	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$224, DW_AT_type(*$C$DW$T$223)
	.dwattr $C$DW$T$224, DW_AT_address_class(0x20)

$C$DW$T$231	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$231, DW_AT_name("s_os_semaphore")
	.dwattr $C$DW$T$231, DW_AT_byte_size(0x18)
$C$DW$838	.dwtag  DW_TAG_member
	.dwattr $C$DW$838, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$838, DW_AT_name("id")
	.dwattr $C$DW$838, DW_AT_TI_symbol_name("_id")
	.dwattr $C$DW$838, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$838, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$839	.dwtag  DW_TAG_member
	.dwattr $C$DW$839, DW_AT_type(*$C$DW$T$80)
	.dwattr $C$DW$839, DW_AT_name("name")
	.dwattr $C$DW$839, DW_AT_TI_symbol_name("_name")
	.dwattr $C$DW$839, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$839, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$840	.dwtag  DW_TAG_member
	.dwattr $C$DW$840, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$840, DW_AT_name("v")
	.dwattr $C$DW$840, DW_AT_TI_symbol_name("_v")
	.dwattr $C$DW$840, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$840, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$841	.dwtag  DW_TAG_member
	.dwattr $C$DW$841, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$841, DW_AT_name("w")
	.dwattr $C$DW$841, DW_AT_TI_symbol_name("_w")
	.dwattr $C$DW$841, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$841, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$842	.dwtag  DW_TAG_member
	.dwattr $C$DW$842, DW_AT_type(*$C$DW$T$158)
	.dwattr $C$DW$842, DW_AT_name("first")
	.dwattr $C$DW$842, DW_AT_TI_symbol_name("_first")
	.dwattr $C$DW$842, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$842, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$843	.dwtag  DW_TAG_member
	.dwattr $C$DW$843, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$843, DW_AT_name("own_process")
	.dwattr $C$DW$843, DW_AT_TI_symbol_name("_own_process")
	.dwattr $C$DW$843, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$843, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$100	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$100, DW_AT_declaration
	.dwattr $C$DW$100, DW_AT_TI_symbol_name("___as__14s_os_semaphoreFRC14s_os_semaphore")
	.dwattr $C$DW$100, DW_AT_type(*$C$DW$T$227)
	.dwattr $C$DW$100, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$844	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$844, DW_AT_type(*$C$DW$T$229)
	.dwendtag $C$DW$100

	.dwendtag $C$DW$T$231

$C$DW$T$227	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$227, DW_AT_type(*$C$DW$T$231)
	.dwattr $C$DW$T$227, DW_AT_address_class(0x20)

$C$DW$T$230	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$230, DW_AT_type(*$C$DW$T$227)
	.dwattr $C$DW$T$230, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$845	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$845, DW_AT_type(*$C$DW$T$229)
	.dwendtag $C$DW$T$230

$C$DW$T$228	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$228, DW_AT_type(*$C$DW$T$231)
$C$DW$T$229	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$229, DW_AT_type(*$C$DW$T$228)
	.dwattr $C$DW$T$229, DW_AT_address_class(0x20)

$C$DW$T$238	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$238, DW_AT_name("s_lif_header")
	.dwattr $C$DW$T$238, DW_AT_byte_size(0x80)
$C$DW$846	.dwtag  DW_TAG_member
	.dwattr $C$DW$846, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$846, DW_AT_name("magic")
	.dwattr $C$DW$846, DW_AT_TI_symbol_name("_magic")
	.dwattr $C$DW$846, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$846, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$847	.dwtag  DW_TAG_member
	.dwattr $C$DW$847, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$847, DW_AT_name("type")
	.dwattr $C$DW$847, DW_AT_TI_symbol_name("_type")
	.dwattr $C$DW$847, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$847, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$848	.dwtag  DW_TAG_member
	.dwattr $C$DW$848, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$848, DW_AT_name("target")
	.dwattr $C$DW$848, DW_AT_TI_symbol_name("_target")
	.dwattr $C$DW$848, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$848, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$849	.dwtag  DW_TAG_member
	.dwattr $C$DW$849, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$849, DW_AT_name("length")
	.dwattr $C$DW$849, DW_AT_TI_symbol_name("_length")
	.dwattr $C$DW$849, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$849, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$850	.dwtag  DW_TAG_member
	.dwattr $C$DW$850, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$850, DW_AT_name("vepoint_offset")
	.dwattr $C$DW$850, DW_AT_TI_symbol_name("_vepoint_offset")
	.dwattr $C$DW$850, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$850, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$851	.dwtag  DW_TAG_member
	.dwattr $C$DW$851, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$851, DW_AT_name("vepoint_snum")
	.dwattr $C$DW$851, DW_AT_TI_symbol_name("_vepoint_snum")
	.dwattr $C$DW$851, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$851, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$852	.dwtag  DW_TAG_member
	.dwattr $C$DW$852, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$852, DW_AT_name("version")
	.dwattr $C$DW$852, DW_AT_TI_symbol_name("_version")
	.dwattr $C$DW$852, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$852, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$853	.dwtag  DW_TAG_member
	.dwattr $C$DW$853, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$853, DW_AT_name("revision")
	.dwattr $C$DW$853, DW_AT_TI_symbol_name("_revision")
	.dwattr $C$DW$853, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr $C$DW$853, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$854	.dwtag  DW_TAG_member
	.dwattr $C$DW$854, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$854, DW_AT_name("flags")
	.dwattr $C$DW$854, DW_AT_TI_symbol_name("_flags")
	.dwattr $C$DW$854, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr $C$DW$854, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$855	.dwtag  DW_TAG_member
	.dwattr $C$DW$855, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$855, DW_AT_name("scount")
	.dwattr $C$DW$855, DW_AT_TI_symbol_name("_scount")
	.dwattr $C$DW$855, DW_AT_data_member_location[DW_OP_plus_uconst 0x24]
	.dwattr $C$DW$855, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$856	.dwtag  DW_TAG_member
	.dwattr $C$DW$856, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$856, DW_AT_name("stack")
	.dwattr $C$DW$856, DW_AT_TI_symbol_name("_stack")
	.dwattr $C$DW$856, DW_AT_data_member_location[DW_OP_plus_uconst 0x28]
	.dwattr $C$DW$856, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$857	.dwtag  DW_TAG_member
	.dwattr $C$DW$857, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$857, DW_AT_name("symcount")
	.dwattr $C$DW$857, DW_AT_TI_symbol_name("_symcount")
	.dwattr $C$DW$857, DW_AT_data_member_location[DW_OP_plus_uconst 0x2c]
	.dwattr $C$DW$857, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$858	.dwtag  DW_TAG_member
	.dwattr $C$DW$858, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$858, DW_AT_name("btime")
	.dwattr $C$DW$858, DW_AT_TI_symbol_name("_btime")
	.dwattr $C$DW$858, DW_AT_data_member_location[DW_OP_plus_uconst 0x30]
	.dwattr $C$DW$858, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$859	.dwtag  DW_TAG_member
	.dwattr $C$DW$859, DW_AT_type(*$C$DW$T$232)
	.dwattr $C$DW$859, DW_AT_name("reserved")
	.dwattr $C$DW$859, DW_AT_TI_symbol_name("_reserved")
	.dwattr $C$DW$859, DW_AT_data_member_location[DW_OP_plus_uconst 0x34]
	.dwattr $C$DW$859, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$860	.dwtag  DW_TAG_member
	.dwattr $C$DW$860, DW_AT_type(*$C$DW$T$233)
	.dwattr $C$DW$860, DW_AT_name("chk")
	.dwattr $C$DW$860, DW_AT_TI_symbol_name("_chk")
	.dwattr $C$DW$860, DW_AT_data_member_location[DW_OP_plus_uconst 0x40]
	.dwattr $C$DW$860, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$101	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$101, DW_AT_declaration
	.dwattr $C$DW$101, DW_AT_TI_symbol_name("___as__12s_lif_headerFRC12s_lif_header")
	.dwattr $C$DW$101, DW_AT_type(*$C$DW$T$234)
	.dwattr $C$DW$101, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$861	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$861, DW_AT_type(*$C$DW$T$236)
	.dwendtag $C$DW$101

	.dwendtag $C$DW$T$238

$C$DW$T$234	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$234, DW_AT_type(*$C$DW$T$238)
	.dwattr $C$DW$T$234, DW_AT_address_class(0x20)

$C$DW$T$237	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$237, DW_AT_type(*$C$DW$T$234)
	.dwattr $C$DW$T$237, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$862	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$862, DW_AT_type(*$C$DW$T$236)
	.dwendtag $C$DW$T$237

$C$DW$T$235	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$235, DW_AT_type(*$C$DW$T$238)
$C$DW$T$236	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$236, DW_AT_type(*$C$DW$T$235)
	.dwattr $C$DW$T$236, DW_AT_address_class(0x20)

$C$DW$T$243	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$243, DW_AT_name("s_lif_section")
	.dwattr $C$DW$T$243, DW_AT_byte_size(0x20)
$C$DW$863	.dwtag  DW_TAG_member
	.dwattr $C$DW$863, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$863, DW_AT_name("magic")
	.dwattr $C$DW$863, DW_AT_TI_symbol_name("_magic")
	.dwattr $C$DW$863, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$863, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$864	.dwtag  DW_TAG_member
	.dwattr $C$DW$864, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$864, DW_AT_name("size")
	.dwattr $C$DW$864, DW_AT_TI_symbol_name("_size")
	.dwattr $C$DW$864, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$864, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$865	.dwtag  DW_TAG_member
	.dwattr $C$DW$865, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$865, DW_AT_name("length")
	.dwattr $C$DW$865, DW_AT_TI_symbol_name("_length")
	.dwattr $C$DW$865, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$865, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$866	.dwtag  DW_TAG_member
	.dwattr $C$DW$866, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$866, DW_AT_name("vaddr")
	.dwattr $C$DW$866, DW_AT_TI_symbol_name("_vaddr")
	.dwattr $C$DW$866, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$866, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$867	.dwtag  DW_TAG_member
	.dwattr $C$DW$867, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$867, DW_AT_name("paddr")
	.dwattr $C$DW$867, DW_AT_TI_symbol_name("_paddr")
	.dwattr $C$DW$867, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$867, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$868	.dwtag  DW_TAG_member
	.dwattr $C$DW$868, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$868, DW_AT_name("pcount")
	.dwattr $C$DW$868, DW_AT_TI_symbol_name("_pcount")
	.dwattr $C$DW$868, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$868, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$869	.dwtag  DW_TAG_member
	.dwattr $C$DW$869, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$869, DW_AT_name("flags")
	.dwattr $C$DW$869, DW_AT_TI_symbol_name("_flags")
	.dwattr $C$DW$869, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$869, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$870	.dwtag  DW_TAG_member
	.dwattr $C$DW$870, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$870, DW_AT_name("reserved")
	.dwattr $C$DW$870, DW_AT_TI_symbol_name("_reserved")
	.dwattr $C$DW$870, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr $C$DW$870, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$102	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$102, DW_AT_declaration
	.dwattr $C$DW$102, DW_AT_TI_symbol_name("___as__13s_lif_sectionFRC13s_lif_section")
	.dwattr $C$DW$102, DW_AT_type(*$C$DW$T$239)
	.dwattr $C$DW$102, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$871	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$871, DW_AT_type(*$C$DW$T$241)
	.dwendtag $C$DW$102

	.dwendtag $C$DW$T$243

$C$DW$T$239	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$239, DW_AT_type(*$C$DW$T$243)
	.dwattr $C$DW$T$239, DW_AT_address_class(0x20)

$C$DW$T$242	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$242, DW_AT_type(*$C$DW$T$239)
	.dwattr $C$DW$T$242, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$872	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$872, DW_AT_type(*$C$DW$T$241)
	.dwendtag $C$DW$T$242

$C$DW$T$240	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$240, DW_AT_type(*$C$DW$T$243)
$C$DW$T$241	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$241, DW_AT_type(*$C$DW$T$240)
	.dwattr $C$DW$T$241, DW_AT_address_class(0x20)

$C$DW$T$248	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$248, DW_AT_name("s_lif_patch")
	.dwattr $C$DW$T$248, DW_AT_byte_size(0x14)
$C$DW$873	.dwtag  DW_TAG_member
	.dwattr $C$DW$873, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$873, DW_AT_name("method")
	.dwattr $C$DW$873, DW_AT_TI_symbol_name("_method")
	.dwattr $C$DW$873, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$873, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$874	.dwtag  DW_TAG_member
	.dwattr $C$DW$874, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$874, DW_AT_name("offset")
	.dwattr $C$DW$874, DW_AT_TI_symbol_name("_offset")
	.dwattr $C$DW$874, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$874, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$875	.dwtag  DW_TAG_member
	.dwattr $C$DW$875, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$875, DW_AT_name("v")
	.dwattr $C$DW$875, DW_AT_TI_symbol_name("_v")
	.dwattr $C$DW$875, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$875, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$876	.dwtag  DW_TAG_member
	.dwattr $C$DW$876, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$876, DW_AT_name("a")
	.dwattr $C$DW$876, DW_AT_TI_symbol_name("_a")
	.dwattr $C$DW$876, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$876, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$877	.dwtag  DW_TAG_member
	.dwattr $C$DW$877, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$877, DW_AT_name("b")
	.dwattr $C$DW$877, DW_AT_TI_symbol_name("_b")
	.dwattr $C$DW$877, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$877, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$103	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$103, DW_AT_declaration
	.dwattr $C$DW$103, DW_AT_TI_symbol_name("___as__11s_lif_patchFRC11s_lif_patch")
	.dwattr $C$DW$103, DW_AT_type(*$C$DW$T$244)
	.dwattr $C$DW$103, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$878	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$878, DW_AT_type(*$C$DW$T$246)
	.dwendtag $C$DW$103

	.dwendtag $C$DW$T$248

$C$DW$T$244	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$244, DW_AT_type(*$C$DW$T$248)
	.dwattr $C$DW$T$244, DW_AT_address_class(0x20)

$C$DW$T$247	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$247, DW_AT_type(*$C$DW$T$244)
	.dwattr $C$DW$T$247, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$879	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$879, DW_AT_type(*$C$DW$T$246)
	.dwendtag $C$DW$T$247

$C$DW$T$245	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$245, DW_AT_type(*$C$DW$T$248)
$C$DW$T$246	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$246, DW_AT_type(*$C$DW$T$245)
	.dwattr $C$DW$T$246, DW_AT_address_class(0x20)

$C$DW$T$253	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$253, DW_AT_name("s_lif_symbol")
	.dwattr $C$DW$T$253, DW_AT_byte_size(0x08)
$C$DW$880	.dwtag  DW_TAG_member
	.dwattr $C$DW$880, DW_AT_type(*$C$DW$T$80)
	.dwattr $C$DW$880, DW_AT_name("name")
	.dwattr $C$DW$880, DW_AT_TI_symbol_name("_name")
	.dwattr $C$DW$880, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$880, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$881	.dwtag  DW_TAG_member
	.dwattr $C$DW$881, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$881, DW_AT_name("address")
	.dwattr $C$DW$881, DW_AT_TI_symbol_name("_address")
	.dwattr $C$DW$881, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$881, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$104	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$104, DW_AT_declaration
	.dwattr $C$DW$104, DW_AT_TI_symbol_name("___as__12s_lif_symbolFRC12s_lif_symbol")
	.dwattr $C$DW$104, DW_AT_type(*$C$DW$T$249)
	.dwattr $C$DW$104, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$882	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$882, DW_AT_type(*$C$DW$T$251)
	.dwendtag $C$DW$104

	.dwendtag $C$DW$T$253

$C$DW$T$249	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$249, DW_AT_type(*$C$DW$T$253)
	.dwattr $C$DW$T$249, DW_AT_address_class(0x20)

$C$DW$T$252	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$252, DW_AT_type(*$C$DW$T$249)
	.dwattr $C$DW$T$252, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$883	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$883, DW_AT_type(*$C$DW$T$251)
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
$C$DW$884	.dwtag  DW_TAG_member
	.dwattr $C$DW$884, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$884, DW_AT_name("entry_point")
	.dwattr $C$DW$884, DW_AT_TI_symbol_name("_entry_point")
	.dwattr $C$DW$884, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$884, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$885	.dwtag  DW_TAG_member
	.dwattr $C$DW$885, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$885, DW_AT_name("bss_point")
	.dwattr $C$DW$885, DW_AT_TI_symbol_name("_bss_point")
	.dwattr $C$DW$885, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$885, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$886	.dwtag  DW_TAG_member
	.dwattr $C$DW$886, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$886, DW_AT_name("stack_size")
	.dwattr $C$DW$886, DW_AT_TI_symbol_name("_stack_size")
	.dwattr $C$DW$886, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$886, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$887	.dwtag  DW_TAG_member
	.dwattr $C$DW$887, DW_AT_type(*$C$DW$T$254)
	.dwattr $C$DW$887, DW_AT_name("symbol")
	.dwattr $C$DW$887, DW_AT_TI_symbol_name("_symbol")
	.dwattr $C$DW$887, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$887, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$888	.dwtag  DW_TAG_member
	.dwattr $C$DW$888, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$888, DW_AT_name("symbol_count")
	.dwattr $C$DW$888, DW_AT_TI_symbol_name("_symbol_count")
	.dwattr $C$DW$888, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$888, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$889	.dwtag  DW_TAG_member
	.dwattr $C$DW$889, DW_AT_type(*$C$DW$T$255)
	.dwattr $C$DW$889, DW_AT_name("page")
	.dwattr $C$DW$889, DW_AT_TI_symbol_name("_page")
	.dwattr $C$DW$889, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$889, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$890	.dwtag  DW_TAG_member
	.dwattr $C$DW$890, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$890, DW_AT_name("page_count")
	.dwattr $C$DW$890, DW_AT_TI_symbol_name("_page_count")
	.dwattr $C$DW$890, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$890, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$105	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$105, DW_AT_declaration
	.dwattr $C$DW$105, DW_AT_TI_symbol_name("___as__13s_lif_overlayFRC13s_lif_overlay")
	.dwattr $C$DW$105, DW_AT_type(*$C$DW$T$256)
	.dwattr $C$DW$105, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$891	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$891, DW_AT_type(*$C$DW$T$258)
	.dwendtag $C$DW$105

	.dwendtag $C$DW$T$260

$C$DW$T$256	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$256, DW_AT_type(*$C$DW$T$260)
	.dwattr $C$DW$T$256, DW_AT_address_class(0x20)

$C$DW$T$259	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$259, DW_AT_type(*$C$DW$T$256)
	.dwattr $C$DW$T$259, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$892	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$892, DW_AT_type(*$C$DW$T$258)
	.dwendtag $C$DW$T$259

$C$DW$T$257	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$257, DW_AT_type(*$C$DW$T$260)
$C$DW$T$258	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$258, DW_AT_type(*$C$DW$T$257)
	.dwattr $C$DW$T$258, DW_AT_address_class(0x20)

$C$DW$T$265	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$265, DW_AT_name("s_os_interrupt")
	.dwattr $C$DW$T$265, DW_AT_byte_size(0x10)
$C$DW$893	.dwtag  DW_TAG_member
	.dwattr $C$DW$893, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$893, DW_AT_name("id")
	.dwattr $C$DW$893, DW_AT_TI_symbol_name("_id")
	.dwattr $C$DW$893, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$893, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$894	.dwtag  DW_TAG_member
	.dwattr $C$DW$894, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$894, DW_AT_name("vector")
	.dwattr $C$DW$894, DW_AT_TI_symbol_name("_vector")
	.dwattr $C$DW$894, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$894, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$895	.dwtag  DW_TAG_member
	.dwattr $C$DW$895, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$895, DW_AT_name("source")
	.dwattr $C$DW$895, DW_AT_TI_symbol_name("_source")
	.dwattr $C$DW$895, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$895, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$896	.dwtag  DW_TAG_member
	.dwattr $C$DW$896, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$896, DW_AT_name("own_process")
	.dwattr $C$DW$896, DW_AT_TI_symbol_name("_own_process")
	.dwattr $C$DW$896, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$896, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$106	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$106, DW_AT_declaration
	.dwattr $C$DW$106, DW_AT_TI_symbol_name("___as__14s_os_interruptFRC14s_os_interrupt")
	.dwattr $C$DW$106, DW_AT_type(*$C$DW$T$261)
	.dwattr $C$DW$106, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$897	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$897, DW_AT_type(*$C$DW$T$263)
	.dwendtag $C$DW$106

	.dwendtag $C$DW$T$265

$C$DW$T$261	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$261, DW_AT_type(*$C$DW$T$265)
	.dwattr $C$DW$T$261, DW_AT_address_class(0x20)

$C$DW$T$264	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$264, DW_AT_type(*$C$DW$T$261)
	.dwattr $C$DW$T$264, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$898	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$898, DW_AT_type(*$C$DW$T$263)
	.dwendtag $C$DW$T$264

$C$DW$T$262	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$262, DW_AT_type(*$C$DW$T$265)
$C$DW$T$263	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$263, DW_AT_type(*$C$DW$T$262)
	.dwattr $C$DW$T$263, DW_AT_address_class(0x20)

$C$DW$T$271	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$271, DW_AT_name("s_os_console")
	.dwattr $C$DW$T$271, DW_AT_byte_size(0x0c)
$C$DW$899	.dwtag  DW_TAG_member
	.dwattr $C$DW$899, DW_AT_type(*$C$DW$T$266)
	.dwattr $C$DW$899, DW_AT_name("next")
	.dwattr $C$DW$899, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$899, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$899, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$900	.dwtag  DW_TAG_member
	.dwattr $C$DW$900, DW_AT_type(*$C$DW$T$266)
	.dwattr $C$DW$900, DW_AT_name("prev")
	.dwattr $C$DW$900, DW_AT_TI_symbol_name("_prev")
	.dwattr $C$DW$900, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$900, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$901	.dwtag  DW_TAG_member
	.dwattr $C$DW$901, DW_AT_type(*$C$DW$T$80)
	.dwattr $C$DW$901, DW_AT_name("path")
	.dwattr $C$DW$901, DW_AT_TI_symbol_name("_path")
	.dwattr $C$DW$901, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$901, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$107	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$107, DW_AT_declaration
	.dwattr $C$DW$107, DW_AT_TI_symbol_name("___as__12s_os_consoleFRC12s_os_console")
	.dwattr $C$DW$107, DW_AT_type(*$C$DW$T$267)
	.dwattr $C$DW$107, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$902	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$902, DW_AT_type(*$C$DW$T$269)
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
$C$DW$903	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$903, DW_AT_type(*$C$DW$T$269)
	.dwendtag $C$DW$T$270

$C$DW$T$268	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$268, DW_AT_type(*$C$DW$T$271)
$C$DW$T$269	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$269, DW_AT_type(*$C$DW$T$268)
	.dwattr $C$DW$T$269, DW_AT_address_class(0x20)

$C$DW$T$277	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$277, DW_AT_name("s_os_iodevice")
	.dwattr $C$DW$T$277, DW_AT_byte_size(0x14)
$C$DW$904	.dwtag  DW_TAG_member
	.dwattr $C$DW$904, DW_AT_type(*$C$DW$T$272)
	.dwattr $C$DW$904, DW_AT_name("next")
	.dwattr $C$DW$904, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$904, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$904, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$905	.dwtag  DW_TAG_member
	.dwattr $C$DW$905, DW_AT_type(*$C$DW$T$272)
	.dwattr $C$DW$905, DW_AT_name("prev")
	.dwattr $C$DW$905, DW_AT_TI_symbol_name("_prev")
	.dwattr $C$DW$905, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$905, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$906	.dwtag  DW_TAG_member
	.dwattr $C$DW$906, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$906, DW_AT_name("con_count")
	.dwattr $C$DW$906, DW_AT_TI_symbol_name("_con_count")
	.dwattr $C$DW$906, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$906, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$907	.dwtag  DW_TAG_member
	.dwattr $C$DW$907, DW_AT_type(*$C$DW$T$266)
	.dwattr $C$DW$907, DW_AT_name("active")
	.dwattr $C$DW$907, DW_AT_TI_symbol_name("_active")
	.dwattr $C$DW$907, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$907, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$908	.dwtag  DW_TAG_member
	.dwattr $C$DW$908, DW_AT_type(*$C$DW$T$80)
	.dwattr $C$DW$908, DW_AT_name("path")
	.dwattr $C$DW$908, DW_AT_TI_symbol_name("_path")
	.dwattr $C$DW$908, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$908, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$108	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$108, DW_AT_declaration
	.dwattr $C$DW$108, DW_AT_TI_symbol_name("___as__13s_os_iodeviceFRC13s_os_iodevice")
	.dwattr $C$DW$108, DW_AT_type(*$C$DW$T$273)
	.dwattr $C$DW$108, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$909	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$909, DW_AT_type(*$C$DW$T$275)
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
$C$DW$910	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$910, DW_AT_type(*$C$DW$T$275)
	.dwendtag $C$DW$T$276

$C$DW$T$274	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$274, DW_AT_type(*$C$DW$T$277)
$C$DW$T$275	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$275, DW_AT_type(*$C$DW$T$274)
	.dwattr $C$DW$T$275, DW_AT_address_class(0x20)

$C$DW$T$282	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$282, DW_AT_name("EDMA_Config")
	.dwattr $C$DW$T$282, DW_AT_byte_size(0x18)
$C$DW$911	.dwtag  DW_TAG_member
	.dwattr $C$DW$911, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$911, DW_AT_name("opt")
	.dwattr $C$DW$911, DW_AT_TI_symbol_name("_opt")
	.dwattr $C$DW$911, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$911, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$912	.dwtag  DW_TAG_member
	.dwattr $C$DW$912, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$912, DW_AT_name("src")
	.dwattr $C$DW$912, DW_AT_TI_symbol_name("_src")
	.dwattr $C$DW$912, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$912, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$913	.dwtag  DW_TAG_member
	.dwattr $C$DW$913, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$913, DW_AT_name("cnt")
	.dwattr $C$DW$913, DW_AT_TI_symbol_name("_cnt")
	.dwattr $C$DW$913, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$913, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$914	.dwtag  DW_TAG_member
	.dwattr $C$DW$914, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$914, DW_AT_name("dst")
	.dwattr $C$DW$914, DW_AT_TI_symbol_name("_dst")
	.dwattr $C$DW$914, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$914, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$915	.dwtag  DW_TAG_member
	.dwattr $C$DW$915, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$915, DW_AT_name("idx")
	.dwattr $C$DW$915, DW_AT_TI_symbol_name("_idx")
	.dwattr $C$DW$915, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$915, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$916	.dwtag  DW_TAG_member
	.dwattr $C$DW$916, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$916, DW_AT_name("rld")
	.dwattr $C$DW$916, DW_AT_TI_symbol_name("_rld")
	.dwattr $C$DW$916, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$916, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$109	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$109, DW_AT_declaration
	.dwattr $C$DW$109, DW_AT_TI_symbol_name("___as__11EDMA_ConfigFRC11EDMA_Config")
	.dwattr $C$DW$109, DW_AT_type(*$C$DW$T$278)
	.dwattr $C$DW$109, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$917	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$917, DW_AT_type(*$C$DW$T$280)
	.dwendtag $C$DW$109

	.dwendtag $C$DW$T$282

$C$DW$T$278	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$278, DW_AT_type(*$C$DW$T$282)
	.dwattr $C$DW$T$278, DW_AT_address_class(0x20)

$C$DW$T$281	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$281, DW_AT_type(*$C$DW$T$278)
	.dwattr $C$DW$T$281, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$918	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$918, DW_AT_type(*$C$DW$T$280)
	.dwendtag $C$DW$T$281

$C$DW$T$279	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$279, DW_AT_type(*$C$DW$T$282)
$C$DW$T$280	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$280, DW_AT_type(*$C$DW$T$279)
	.dwattr $C$DW$T$280, DW_AT_address_class(0x20)
$C$DW$T$728	.dwtag  DW_TAG_typedef, DW_AT_name("EDMA_Config")
	.dwattr $C$DW$T$728, DW_AT_type(*$C$DW$T$282)
	.dwattr $C$DW$T$728, DW_AT_language(DW_LANG_C_plus_plus)

$C$DW$T$287	.dwtag  DW_TAG_class_type
	.dwattr $C$DW$T$287, DW_AT_name("bad_alloc")
	.dwattr $C$DW$T$287, DW_AT_byte_size(0x01)

$C$DW$110	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$110, DW_AT_declaration
	.dwattr $C$DW$110, DW_AT_TI_symbol_name("___as__Q2_3std9bad_allocFRCQ2_3std9bad_alloc")
	.dwattr $C$DW$110, DW_AT_type(*$C$DW$T$283)
	.dwattr $C$DW$110, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$919	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$919, DW_AT_type(*$C$DW$T$285)
	.dwendtag $C$DW$110

	.dwendtag $C$DW$T$287

$C$DW$T$283	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$283, DW_AT_type(*$C$DW$T$287)
	.dwattr $C$DW$T$283, DW_AT_address_class(0x20)

$C$DW$T$286	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$286, DW_AT_type(*$C$DW$T$283)
	.dwattr $C$DW$T$286, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$920	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$920, DW_AT_type(*$C$DW$T$285)
	.dwendtag $C$DW$T$286

$C$DW$T$284	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$284, DW_AT_type(*$C$DW$T$287)
$C$DW$T$285	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$285, DW_AT_type(*$C$DW$T$284)
	.dwattr $C$DW$T$285, DW_AT_address_class(0x20)

$C$DW$T$293	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$293, DW_AT_name("FILE")
	.dwattr $C$DW$T$293, DW_AT_byte_size(0x18)
$C$DW$921	.dwtag  DW_TAG_member
	.dwattr $C$DW$921, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$921, DW_AT_name("rid")
	.dwattr $C$DW$921, DW_AT_TI_symbol_name("_rid")
	.dwattr $C$DW$921, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$921, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$922	.dwtag  DW_TAG_member
	.dwattr $C$DW$922, DW_AT_type(*$C$DW$T$288)
	.dwattr $C$DW$922, DW_AT_name("ungetc_buf")
	.dwattr $C$DW$922, DW_AT_TI_symbol_name("_ungetc_buf")
	.dwattr $C$DW$922, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$922, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$923	.dwtag  DW_TAG_member
	.dwattr $C$DW$923, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$923, DW_AT_name("ungetc_count")
	.dwattr $C$DW$923, DW_AT_TI_symbol_name("_ungetc_count")
	.dwattr $C$DW$923, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$923, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$111	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$111, DW_AT_declaration
	.dwattr $C$DW$111, DW_AT_TI_symbol_name("___as__4FILEFRC4FILE")
	.dwattr $C$DW$111, DW_AT_type(*$C$DW$T$289)
	.dwattr $C$DW$111, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$924	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$924, DW_AT_type(*$C$DW$T$291)
	.dwendtag $C$DW$111

	.dwendtag $C$DW$T$293

$C$DW$T$289	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$289, DW_AT_type(*$C$DW$T$293)
	.dwattr $C$DW$T$289, DW_AT_address_class(0x20)

$C$DW$T$292	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$292, DW_AT_type(*$C$DW$T$289)
	.dwattr $C$DW$T$292, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$925	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$925, DW_AT_type(*$C$DW$T$291)
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
$C$DW$926	.dwtag  DW_TAG_member
	.dwattr $C$DW$926, DW_AT_type(*$C$DW$T$294)
	.dwattr $C$DW$926, DW_AT_name("f")
	.dwattr $C$DW$926, DW_AT_TI_symbol_name("_f")
	.dwattr $C$DW$926, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$926, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$927	.dwtag  DW_TAG_member
	.dwattr $C$DW$927, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$927, DW_AT_name("bpos")
	.dwattr $C$DW$927, DW_AT_TI_symbol_name("_bpos")
	.dwattr $C$DW$927, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$927, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$928	.dwtag  DW_TAG_member
	.dwattr $C$DW$928, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$928, DW_AT_name("b")
	.dwattr $C$DW$928, DW_AT_TI_symbol_name("_b")
	.dwattr $C$DW$928, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$928, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$929	.dwtag  DW_TAG_member
	.dwattr $C$DW$929, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$929, DW_AT_name("mode")
	.dwattr $C$DW$929, DW_AT_TI_symbol_name("_mode")
	.dwattr $C$DW$929, DW_AT_data_member_location[DW_OP_plus_uconst 0x9]
	.dwattr $C$DW$929, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$112	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$112, DW_AT_declaration
	.dwattr $C$DW$112, DW_AT_TI_symbol_name("___as__8BIT_FILEFRC8BIT_FILE")
	.dwattr $C$DW$112, DW_AT_type(*$C$DW$T$295)
	.dwattr $C$DW$112, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$930	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$930, DW_AT_type(*$C$DW$T$297)
	.dwendtag $C$DW$112

	.dwendtag $C$DW$T$299

$C$DW$T$295	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$295, DW_AT_type(*$C$DW$T$299)
	.dwattr $C$DW$T$295, DW_AT_address_class(0x20)

$C$DW$T$298	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$298, DW_AT_type(*$C$DW$T$295)
	.dwattr $C$DW$T$298, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$931	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$931, DW_AT_type(*$C$DW$T$297)
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
$C$DW$932	.dwtag  DW_TAG_member
	.dwattr $C$DW$932, DW_AT_type(*$C$DW$T$300)
	.dwattr $C$DW$932, DW_AT_name("f")
	.dwattr $C$DW$932, DW_AT_TI_symbol_name("_f")
	.dwattr $C$DW$932, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$932, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$933	.dwtag  DW_TAG_member
	.dwattr $C$DW$933, DW_AT_type(*$C$DW$T$301)
	.dwattr $C$DW$933, DW_AT_name("w")
	.dwattr $C$DW$933, DW_AT_TI_symbol_name("_w")
	.dwattr $C$DW$933, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$933, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$934	.dwtag  DW_TAG_member
	.dwattr $C$DW$934, DW_AT_type(*$C$DW$T$302)
	.dwattr $C$DW$934, DW_AT_name("b")
	.dwattr $C$DW$934, DW_AT_TI_symbol_name("_b")
	.dwattr $C$DW$934, DW_AT_data_member_location[DW_OP_plus_uconst 0x404]
	.dwattr $C$DW$934, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$935	.dwtag  DW_TAG_member
	.dwattr $C$DW$935, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$935, DW_AT_name("wpos")
	.dwattr $C$DW$935, DW_AT_TI_symbol_name("_wpos")
	.dwattr $C$DW$935, DW_AT_data_member_location[DW_OP_plus_uconst 0x424]
	.dwattr $C$DW$935, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$936	.dwtag  DW_TAG_member
	.dwattr $C$DW$936, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$936, DW_AT_name("blen")
	.dwattr $C$DW$936, DW_AT_TI_symbol_name("_blen")
	.dwattr $C$DW$936, DW_AT_data_member_location[DW_OP_plus_uconst 0x428]
	.dwattr $C$DW$936, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$937	.dwtag  DW_TAG_member
	.dwattr $C$DW$937, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$937, DW_AT_name("mode")
	.dwattr $C$DW$937, DW_AT_TI_symbol_name("_mode")
	.dwattr $C$DW$937, DW_AT_data_member_location[DW_OP_plus_uconst 0x42c]
	.dwattr $C$DW$937, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$113	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$113, DW_AT_declaration
	.dwattr $C$DW$113, DW_AT_TI_symbol_name("___as__9WLPK_FILEFRC9WLPK_FILE")
	.dwattr $C$DW$113, DW_AT_type(*$C$DW$T$303)
	.dwattr $C$DW$113, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$938	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$938, DW_AT_type(*$C$DW$T$305)
	.dwendtag $C$DW$113

	.dwendtag $C$DW$T$307

$C$DW$T$303	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$303, DW_AT_type(*$C$DW$T$307)
	.dwattr $C$DW$T$303, DW_AT_address_class(0x20)

$C$DW$T$306	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$306, DW_AT_type(*$C$DW$T$303)
	.dwattr $C$DW$T$306, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$939	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$939, DW_AT_type(*$C$DW$T$305)
	.dwendtag $C$DW$T$306

$C$DW$T$304	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$304, DW_AT_type(*$C$DW$T$307)
$C$DW$T$305	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$305, DW_AT_type(*$C$DW$T$304)
	.dwattr $C$DW$T$305, DW_AT_address_class(0x20)

$C$DW$T$313	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$313, DW_AT_name("dirent")
	.dwattr $C$DW$T$313, DW_AT_byte_size(0x110)
$C$DW$940	.dwtag  DW_TAG_member
	.dwattr $C$DW$940, DW_AT_type(*$C$DW$T$308)
	.dwattr $C$DW$940, DW_AT_name("d_name")
	.dwattr $C$DW$940, DW_AT_TI_symbol_name("_d_name")
	.dwattr $C$DW$940, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$940, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$941	.dwtag  DW_TAG_member
	.dwattr $C$DW$941, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$941, DW_AT_name("d_type")
	.dwattr $C$DW$941, DW_AT_TI_symbol_name("_d_type")
	.dwattr $C$DW$941, DW_AT_data_member_location[DW_OP_plus_uconst 0x100]
	.dwattr $C$DW$941, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$942	.dwtag  DW_TAG_member
	.dwattr $C$DW$942, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$942, DW_AT_name("d_size")
	.dwattr $C$DW$942, DW_AT_TI_symbol_name("_d_size")
	.dwattr $C$DW$942, DW_AT_data_member_location[DW_OP_plus_uconst 0x108]
	.dwattr $C$DW$942, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$114	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$114, DW_AT_declaration
	.dwattr $C$DW$114, DW_AT_TI_symbol_name("___as__6direntFRC6dirent")
	.dwattr $C$DW$114, DW_AT_type(*$C$DW$T$309)
	.dwattr $C$DW$114, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$943	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$943, DW_AT_type(*$C$DW$T$311)
	.dwendtag $C$DW$114

	.dwendtag $C$DW$T$313

$C$DW$T$309	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$309, DW_AT_type(*$C$DW$T$313)
	.dwattr $C$DW$T$309, DW_AT_address_class(0x20)

$C$DW$T$312	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$312, DW_AT_type(*$C$DW$T$309)
	.dwattr $C$DW$T$312, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$944	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$944, DW_AT_type(*$C$DW$T$311)
	.dwendtag $C$DW$T$312

$C$DW$T$310	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$310, DW_AT_type(*$C$DW$T$313)
$C$DW$T$311	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$311, DW_AT_type(*$C$DW$T$310)
	.dwattr $C$DW$T$311, DW_AT_address_class(0x20)

$C$DW$T$318	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$318, DW_AT_name("DIR")
	.dwattr $C$DW$T$318, DW_AT_byte_size(0x120)
$C$DW$945	.dwtag  DW_TAG_member
	.dwattr $C$DW$945, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$945, DW_AT_name("rid")
	.dwattr $C$DW$945, DW_AT_TI_symbol_name("_rid")
	.dwattr $C$DW$945, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$945, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$946	.dwtag  DW_TAG_member
	.dwattr $C$DW$946, DW_AT_type(*$C$DW$T$313)
	.dwattr $C$DW$946, DW_AT_name("d_rec")
	.dwattr $C$DW$946, DW_AT_TI_symbol_name("_d_rec")
	.dwattr $C$DW$946, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$946, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$947	.dwtag  DW_TAG_member
	.dwattr $C$DW$947, DW_AT_type(*$C$DW$T$104)
	.dwattr $C$DW$947, DW_AT_name("d_list")
	.dwattr $C$DW$947, DW_AT_TI_symbol_name("_d_list")
	.dwattr $C$DW$947, DW_AT_data_member_location[DW_OP_plus_uconst 0x118]
	.dwattr $C$DW$947, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$948	.dwtag  DW_TAG_member
	.dwattr $C$DW$948, DW_AT_type(*$C$DW$T$104)
	.dwattr $C$DW$948, DW_AT_name("d_cnode")
	.dwattr $C$DW$948, DW_AT_TI_symbol_name("_d_cnode")
	.dwattr $C$DW$948, DW_AT_data_member_location[DW_OP_plus_uconst 0x11c]
	.dwattr $C$DW$948, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$115	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$115, DW_AT_declaration
	.dwattr $C$DW$115, DW_AT_TI_symbol_name("___as__3DIRFRC3DIR")
	.dwattr $C$DW$115, DW_AT_type(*$C$DW$T$314)
	.dwattr $C$DW$115, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$949	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$949, DW_AT_type(*$C$DW$T$316)
	.dwendtag $C$DW$115

	.dwendtag $C$DW$T$318

$C$DW$T$314	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$314, DW_AT_type(*$C$DW$T$318)
	.dwattr $C$DW$T$314, DW_AT_address_class(0x20)

$C$DW$T$317	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$317, DW_AT_type(*$C$DW$T$314)
	.dwattr $C$DW$T$317, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$950	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$950, DW_AT_type(*$C$DW$T$316)
	.dwendtag $C$DW$T$317

$C$DW$T$315	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$315, DW_AT_type(*$C$DW$T$318)
$C$DW$T$316	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$316, DW_AT_type(*$C$DW$T$315)
	.dwattr $C$DW$T$316, DW_AT_address_class(0x20)

$C$DW$T$323	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$323, DW_AT_name("sem_t")
	.dwattr $C$DW$T$323, DW_AT_byte_size(0x08)
$C$DW$951	.dwtag  DW_TAG_member
	.dwattr $C$DW$951, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$951, DW_AT_name("rid")
	.dwattr $C$DW$951, DW_AT_TI_symbol_name("_rid")
	.dwattr $C$DW$951, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$951, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$952	.dwtag  DW_TAG_member
	.dwattr $C$DW$952, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$952, DW_AT_name("nauna")
	.dwattr $C$DW$952, DW_AT_TI_symbol_name("_nauna")
	.dwattr $C$DW$952, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$952, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$116	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$116, DW_AT_declaration
	.dwattr $C$DW$116, DW_AT_TI_symbol_name("___as__5sem_tFRC5sem_t")
	.dwattr $C$DW$116, DW_AT_type(*$C$DW$T$319)
	.dwattr $C$DW$116, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$953	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$953, DW_AT_type(*$C$DW$T$321)
	.dwendtag $C$DW$116

	.dwendtag $C$DW$T$323

$C$DW$T$319	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$319, DW_AT_type(*$C$DW$T$323)
	.dwattr $C$DW$T$319, DW_AT_address_class(0x20)

$C$DW$T$322	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$322, DW_AT_type(*$C$DW$T$319)
	.dwattr $C$DW$T$322, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$954	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$954, DW_AT_type(*$C$DW$T$321)
	.dwendtag $C$DW$T$322

$C$DW$T$320	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$320, DW_AT_type(*$C$DW$T$323)
$C$DW$T$321	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$321, DW_AT_type(*$C$DW$T$320)
	.dwattr $C$DW$T$321, DW_AT_address_class(0x20)

$C$DW$T$328	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$328, DW_AT_name("tm")
	.dwattr $C$DW$T$328, DW_AT_byte_size(0x24)
$C$DW$955	.dwtag  DW_TAG_member
	.dwattr $C$DW$955, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$955, DW_AT_name("tm_sec")
	.dwattr $C$DW$955, DW_AT_TI_symbol_name("_tm_sec")
	.dwattr $C$DW$955, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$955, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$956	.dwtag  DW_TAG_member
	.dwattr $C$DW$956, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$956, DW_AT_name("tm_min")
	.dwattr $C$DW$956, DW_AT_TI_symbol_name("_tm_min")
	.dwattr $C$DW$956, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$956, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$957	.dwtag  DW_TAG_member
	.dwattr $C$DW$957, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$957, DW_AT_name("tm_hour")
	.dwattr $C$DW$957, DW_AT_TI_symbol_name("_tm_hour")
	.dwattr $C$DW$957, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$957, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$958	.dwtag  DW_TAG_member
	.dwattr $C$DW$958, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$958, DW_AT_name("tm_mday")
	.dwattr $C$DW$958, DW_AT_TI_symbol_name("_tm_mday")
	.dwattr $C$DW$958, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$958, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$959	.dwtag  DW_TAG_member
	.dwattr $C$DW$959, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$959, DW_AT_name("tm_mon")
	.dwattr $C$DW$959, DW_AT_TI_symbol_name("_tm_mon")
	.dwattr $C$DW$959, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$959, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$960	.dwtag  DW_TAG_member
	.dwattr $C$DW$960, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$960, DW_AT_name("tm_year")
	.dwattr $C$DW$960, DW_AT_TI_symbol_name("_tm_year")
	.dwattr $C$DW$960, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$960, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$961	.dwtag  DW_TAG_member
	.dwattr $C$DW$961, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$961, DW_AT_name("tm_wday")
	.dwattr $C$DW$961, DW_AT_TI_symbol_name("_tm_wday")
	.dwattr $C$DW$961, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$961, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$962	.dwtag  DW_TAG_member
	.dwattr $C$DW$962, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$962, DW_AT_name("tm_yday")
	.dwattr $C$DW$962, DW_AT_TI_symbol_name("_tm_yday")
	.dwattr $C$DW$962, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr $C$DW$962, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$963	.dwtag  DW_TAG_member
	.dwattr $C$DW$963, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$963, DW_AT_name("tm_isdst")
	.dwattr $C$DW$963, DW_AT_TI_symbol_name("_tm_isdst")
	.dwattr $C$DW$963, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr $C$DW$963, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$117	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$117, DW_AT_declaration
	.dwattr $C$DW$117, DW_AT_TI_symbol_name("___as__2tmFRC2tm")
	.dwattr $C$DW$117, DW_AT_type(*$C$DW$T$324)
	.dwattr $C$DW$117, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$964	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$964, DW_AT_type(*$C$DW$T$326)
	.dwendtag $C$DW$117

	.dwendtag $C$DW$T$328

$C$DW$T$324	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$324, DW_AT_type(*$C$DW$T$328)
	.dwattr $C$DW$T$324, DW_AT_address_class(0x20)

$C$DW$T$327	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$327, DW_AT_type(*$C$DW$T$324)
	.dwattr $C$DW$T$327, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$965	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$965, DW_AT_type(*$C$DW$T$326)
	.dwendtag $C$DW$T$327

$C$DW$T$325	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$325, DW_AT_type(*$C$DW$T$328)
$C$DW$T$326	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$326, DW_AT_type(*$C$DW$T$325)
	.dwattr $C$DW$T$326, DW_AT_address_class(0x20)

$C$DW$T$333	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$333, DW_AT_name("stat")
	.dwattr $C$DW$T$333, DW_AT_byte_size(0x30)
$C$DW$966	.dwtag  DW_TAG_member
	.dwattr $C$DW$966, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$966, DW_AT_name("st_dev")
	.dwattr $C$DW$966, DW_AT_TI_symbol_name("_st_dev")
	.dwattr $C$DW$966, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$966, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$967	.dwtag  DW_TAG_member
	.dwattr $C$DW$967, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$967, DW_AT_name("st_ino")
	.dwattr $C$DW$967, DW_AT_TI_symbol_name("_st_ino")
	.dwattr $C$DW$967, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$967, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$968	.dwtag  DW_TAG_member
	.dwattr $C$DW$968, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$968, DW_AT_name("st_mode")
	.dwattr $C$DW$968, DW_AT_TI_symbol_name("_st_mode")
	.dwattr $C$DW$968, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$968, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$969	.dwtag  DW_TAG_member
	.dwattr $C$DW$969, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$969, DW_AT_name("st_nlink")
	.dwattr $C$DW$969, DW_AT_TI_symbol_name("_st_nlink")
	.dwattr $C$DW$969, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$969, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$970	.dwtag  DW_TAG_member
	.dwattr $C$DW$970, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$970, DW_AT_name("st_uid")
	.dwattr $C$DW$970, DW_AT_TI_symbol_name("_st_uid")
	.dwattr $C$DW$970, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$970, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$971	.dwtag  DW_TAG_member
	.dwattr $C$DW$971, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$971, DW_AT_name("st_gid")
	.dwattr $C$DW$971, DW_AT_TI_symbol_name("_st_gid")
	.dwattr $C$DW$971, DW_AT_data_member_location[DW_OP_plus_uconst 0x12]
	.dwattr $C$DW$971, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$972	.dwtag  DW_TAG_member
	.dwattr $C$DW$972, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$972, DW_AT_name("st_rdev")
	.dwattr $C$DW$972, DW_AT_TI_symbol_name("_st_rdev")
	.dwattr $C$DW$972, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$972, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$973	.dwtag  DW_TAG_member
	.dwattr $C$DW$973, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$973, DW_AT_name("st_size")
	.dwattr $C$DW$973, DW_AT_TI_symbol_name("_st_size")
	.dwattr $C$DW$973, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$973, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$974	.dwtag  DW_TAG_member
	.dwattr $C$DW$974, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$974, DW_AT_name("st_atime")
	.dwattr $C$DW$974, DW_AT_TI_symbol_name("_st_atime")
	.dwattr $C$DW$974, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr $C$DW$974, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$975	.dwtag  DW_TAG_member
	.dwattr $C$DW$975, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$975, DW_AT_name("st_mtime")
	.dwattr $C$DW$975, DW_AT_TI_symbol_name("_st_mtime")
	.dwattr $C$DW$975, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr $C$DW$975, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$976	.dwtag  DW_TAG_member
	.dwattr $C$DW$976, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$976, DW_AT_name("st_ctime")
	.dwattr $C$DW$976, DW_AT_TI_symbol_name("_st_ctime")
	.dwattr $C$DW$976, DW_AT_data_member_location[DW_OP_plus_uconst 0x24]
	.dwattr $C$DW$976, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$977	.dwtag  DW_TAG_member
	.dwattr $C$DW$977, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$977, DW_AT_name("st_blksize")
	.dwattr $C$DW$977, DW_AT_TI_symbol_name("_st_blksize")
	.dwattr $C$DW$977, DW_AT_data_member_location[DW_OP_plus_uconst 0x28]
	.dwattr $C$DW$977, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$978	.dwtag  DW_TAG_member
	.dwattr $C$DW$978, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$978, DW_AT_name("st_blocks")
	.dwattr $C$DW$978, DW_AT_TI_symbol_name("_st_blocks")
	.dwattr $C$DW$978, DW_AT_data_member_location[DW_OP_plus_uconst 0x2c]
	.dwattr $C$DW$978, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$118	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$118, DW_AT_declaration
	.dwattr $C$DW$118, DW_AT_TI_symbol_name("___as__4statFRC4stat")
	.dwattr $C$DW$118, DW_AT_type(*$C$DW$T$329)
	.dwattr $C$DW$118, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$979	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$979, DW_AT_type(*$C$DW$T$331)
	.dwendtag $C$DW$118

	.dwendtag $C$DW$T$333

$C$DW$T$329	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$329, DW_AT_type(*$C$DW$T$333)
	.dwattr $C$DW$T$329, DW_AT_address_class(0x20)

$C$DW$T$332	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$332, DW_AT_type(*$C$DW$T$329)
	.dwattr $C$DW$T$332, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$980	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$980, DW_AT_type(*$C$DW$T$331)
	.dwendtag $C$DW$T$332

$C$DW$T$330	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$330, DW_AT_type(*$C$DW$T$333)
$C$DW$T$331	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$331, DW_AT_type(*$C$DW$T$330)
	.dwattr $C$DW$T$331, DW_AT_address_class(0x20)

$C$DW$T$340	.dwtag  DW_TAG_union_type
	.dwattr $C$DW$T$340, DW_AT_byte_size(0x04)
$C$DW$981	.dwtag  DW_TAG_member
	.dwattr $C$DW$981, DW_AT_type(*$C$DW$T$335)
	.dwattr $C$DW$981, DW_AT_name("dtor")
	.dwattr $C$DW$981, DW_AT_TI_symbol_name("_dtor")
	.dwattr $C$DW$981, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$981, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$982	.dwtag  DW_TAG_member
	.dwattr $C$DW$982, DW_AT_type(*$C$DW$T$211)
	.dwattr $C$DW$982, DW_AT_name("dfun")
	.dwattr $C$DW$982, DW_AT_TI_symbol_name("_dfun")
	.dwattr $C$DW$982, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$982, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$119	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$119, DW_AT_declaration
	.dwattr $C$DW$119, DW_AT_TI_symbol_name("___as__Q2_14s_rts_dtorlist4__C1FRCQ2_14s_rts_dtorlist4__C1")
	.dwattr $C$DW$119, DW_AT_type(*$C$DW$T$336)
	.dwattr $C$DW$119, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$983	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$983, DW_AT_type(*$C$DW$T$338)
	.dwendtag $C$DW$119

	.dwendtag $C$DW$T$340

$C$DW$T$336	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$336, DW_AT_type(*$C$DW$T$340)
	.dwattr $C$DW$T$336, DW_AT_address_class(0x20)

$C$DW$T$339	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$339, DW_AT_type(*$C$DW$T$336)
	.dwattr $C$DW$T$339, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$984	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$984, DW_AT_type(*$C$DW$T$338)
	.dwendtag $C$DW$T$339

$C$DW$T$337	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$337, DW_AT_type(*$C$DW$T$340)
$C$DW$T$338	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$338, DW_AT_type(*$C$DW$T$337)
	.dwattr $C$DW$T$338, DW_AT_address_class(0x20)

$C$DW$T$346	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$346, DW_AT_name("s_rts_dtorlist")
	.dwattr $C$DW$T$346, DW_AT_byte_size(0x0c)
$C$DW$985	.dwtag  DW_TAG_member
	.dwattr $C$DW$985, DW_AT_type(*$C$DW$T$341)
	.dwattr $C$DW$985, DW_AT_name("next")
	.dwattr $C$DW$985, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$985, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$985, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$986	.dwtag  DW_TAG_member
	.dwattr $C$DW$986, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$986, DW_AT_name("object")
	.dwattr $C$DW$986, DW_AT_TI_symbol_name("_object")
	.dwattr $C$DW$986, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$986, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$987	.dwtag  DW_TAG_member
	.dwattr $C$DW$987, DW_AT_type(*$C$DW$T$340)
	.dwattr $C$DW$987, DW_AT_name("fun")
	.dwattr $C$DW$987, DW_AT_TI_symbol_name("_fun")
	.dwattr $C$DW$987, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$987, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$120	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$120, DW_AT_declaration
	.dwattr $C$DW$120, DW_AT_TI_symbol_name("___as__14s_rts_dtorlistFRC14s_rts_dtorlist")
	.dwattr $C$DW$120, DW_AT_type(*$C$DW$T$342)
	.dwattr $C$DW$120, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$988	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$988, DW_AT_type(*$C$DW$T$344)
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
$C$DW$989	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$989, DW_AT_type(*$C$DW$T$344)
	.dwendtag $C$DW$T$345

$C$DW$T$343	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$343, DW_AT_type(*$C$DW$T$346)
$C$DW$T$344	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$344, DW_AT_type(*$C$DW$T$343)
	.dwattr $C$DW$T$344, DW_AT_address_class(0x20)

$C$DW$T$351	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$351, DW_AT_name("timespec")
	.dwattr $C$DW$T$351, DW_AT_byte_size(0x08)
$C$DW$990	.dwtag  DW_TAG_member
	.dwattr $C$DW$990, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$990, DW_AT_name("tv_sec")
	.dwattr $C$DW$990, DW_AT_TI_symbol_name("_tv_sec")
	.dwattr $C$DW$990, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$990, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$991	.dwtag  DW_TAG_member
	.dwattr $C$DW$991, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$991, DW_AT_name("tv_nsec")
	.dwattr $C$DW$991, DW_AT_TI_symbol_name("_tv_nsec")
	.dwattr $C$DW$991, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$991, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$121	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$121, DW_AT_declaration
	.dwattr $C$DW$121, DW_AT_TI_symbol_name("___as__8timespecFRC8timespec")
	.dwattr $C$DW$121, DW_AT_type(*$C$DW$T$347)
	.dwattr $C$DW$121, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$992	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$992, DW_AT_type(*$C$DW$T$349)
	.dwendtag $C$DW$121

	.dwendtag $C$DW$T$351

$C$DW$T$347	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$347, DW_AT_type(*$C$DW$T$351)
	.dwattr $C$DW$T$347, DW_AT_address_class(0x20)

$C$DW$T$350	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$350, DW_AT_type(*$C$DW$T$347)
	.dwattr $C$DW$T$350, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$993	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$993, DW_AT_type(*$C$DW$T$349)
	.dwendtag $C$DW$T$350

$C$DW$T$348	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$348, DW_AT_type(*$C$DW$T$351)
$C$DW$T$349	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$349, DW_AT_type(*$C$DW$T$348)
	.dwattr $C$DW$T$349, DW_AT_address_class(0x20)

$C$DW$T$358	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$358, DW_AT_name("sockaddr")
	.dwattr $C$DW$T$358, DW_AT_byte_size(0x10)
$C$DW$994	.dwtag  DW_TAG_member
	.dwattr $C$DW$994, DW_AT_type(*$C$DW$T$352)
	.dwattr $C$DW$994, DW_AT_name("sa_family")
	.dwattr $C$DW$994, DW_AT_TI_symbol_name("_sa_family")
	.dwattr $C$DW$994, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$994, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$995	.dwtag  DW_TAG_member
	.dwattr $C$DW$995, DW_AT_type(*$C$DW$T$353)
	.dwattr $C$DW$995, DW_AT_name("sa_data")
	.dwattr $C$DW$995, DW_AT_TI_symbol_name("_sa_data")
	.dwattr $C$DW$995, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr $C$DW$995, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$122	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$122, DW_AT_declaration
	.dwattr $C$DW$122, DW_AT_TI_symbol_name("___as__8sockaddrFRC8sockaddr")
	.dwattr $C$DW$122, DW_AT_type(*$C$DW$T$354)
	.dwattr $C$DW$122, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$996	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$996, DW_AT_type(*$C$DW$T$356)
	.dwendtag $C$DW$122

	.dwendtag $C$DW$T$358

$C$DW$T$354	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$354, DW_AT_type(*$C$DW$T$358)
	.dwattr $C$DW$T$354, DW_AT_address_class(0x20)

$C$DW$T$357	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$357, DW_AT_type(*$C$DW$T$354)
	.dwattr $C$DW$T$357, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$997	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$997, DW_AT_type(*$C$DW$T$356)
	.dwendtag $C$DW$T$357

$C$DW$T$355	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$355, DW_AT_type(*$C$DW$T$358)
$C$DW$T$356	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$356, DW_AT_type(*$C$DW$T$355)
	.dwattr $C$DW$T$356, DW_AT_address_class(0x20)

$C$DW$T$363	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$363, DW_AT_name("in_addr")
	.dwattr $C$DW$T$363, DW_AT_byte_size(0x04)
$C$DW$998	.dwtag  DW_TAG_member
	.dwattr $C$DW$998, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$998, DW_AT_name("s_addr")
	.dwattr $C$DW$998, DW_AT_TI_symbol_name("_s_addr")
	.dwattr $C$DW$998, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$998, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$123	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$123, DW_AT_declaration
	.dwattr $C$DW$123, DW_AT_TI_symbol_name("___as__7in_addrFRC7in_addr")
	.dwattr $C$DW$123, DW_AT_type(*$C$DW$T$359)
	.dwattr $C$DW$123, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$999	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$999, DW_AT_type(*$C$DW$T$361)
	.dwendtag $C$DW$123

	.dwendtag $C$DW$T$363

$C$DW$T$359	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$359, DW_AT_type(*$C$DW$T$363)
	.dwattr $C$DW$T$359, DW_AT_address_class(0x20)

$C$DW$T$362	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$362, DW_AT_type(*$C$DW$T$359)
	.dwattr $C$DW$T$362, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1000	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1000, DW_AT_type(*$C$DW$T$361)
	.dwendtag $C$DW$T$362

$C$DW$T$360	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$360, DW_AT_type(*$C$DW$T$363)
$C$DW$T$361	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$361, DW_AT_type(*$C$DW$T$360)
	.dwattr $C$DW$T$361, DW_AT_address_class(0x20)

$C$DW$T$368	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$368, DW_AT_name("sockaddr_in")
	.dwattr $C$DW$T$368, DW_AT_byte_size(0x10)
$C$DW$1001	.dwtag  DW_TAG_member
	.dwattr $C$DW$1001, DW_AT_type(*$C$DW$T$352)
	.dwattr $C$DW$1001, DW_AT_name("sin_family")
	.dwattr $C$DW$1001, DW_AT_TI_symbol_name("_sin_family")
	.dwattr $C$DW$1001, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1001, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1002	.dwtag  DW_TAG_member
	.dwattr $C$DW$1002, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1002, DW_AT_name("sin_port")
	.dwattr $C$DW$1002, DW_AT_TI_symbol_name("_sin_port")
	.dwattr $C$DW$1002, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr $C$DW$1002, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1003	.dwtag  DW_TAG_member
	.dwattr $C$DW$1003, DW_AT_type(*$C$DW$T$363)
	.dwattr $C$DW$1003, DW_AT_name("sin_addr")
	.dwattr $C$DW$1003, DW_AT_TI_symbol_name("_sin_addr")
	.dwattr $C$DW$1003, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1003, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1004	.dwtag  DW_TAG_member
	.dwattr $C$DW$1004, DW_AT_type(*$C$DW$T$59)
	.dwattr $C$DW$1004, DW_AT_name("pad")
	.dwattr $C$DW$1004, DW_AT_TI_symbol_name("_pad")
	.dwattr $C$DW$1004, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1004, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$124	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$124, DW_AT_declaration
	.dwattr $C$DW$124, DW_AT_TI_symbol_name("___as__11sockaddr_inFRC11sockaddr_in")
	.dwattr $C$DW$124, DW_AT_type(*$C$DW$T$364)
	.dwattr $C$DW$124, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1005	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1005, DW_AT_type(*$C$DW$T$366)
	.dwendtag $C$DW$124

	.dwendtag $C$DW$T$368

$C$DW$T$364	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$364, DW_AT_type(*$C$DW$T$368)
	.dwattr $C$DW$T$364, DW_AT_address_class(0x20)

$C$DW$T$367	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$367, DW_AT_type(*$C$DW$T$364)
	.dwattr $C$DW$T$367, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1006	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1006, DW_AT_type(*$C$DW$T$366)
	.dwendtag $C$DW$T$367

$C$DW$T$365	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$365, DW_AT_type(*$C$DW$T$368)
$C$DW$T$366	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$366, DW_AT_type(*$C$DW$T$365)
	.dwattr $C$DW$T$366, DW_AT_address_class(0x20)

$C$DW$T$373	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$373, DW_AT_name("route_add_parms")
	.dwattr $C$DW$T$373, DW_AT_byte_size(0x14)
$C$DW$1007	.dwtag  DW_TAG_member
	.dwattr $C$DW$1007, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1007, DW_AT_name("network")
	.dwattr $C$DW$1007, DW_AT_TI_symbol_name("_network")
	.dwattr $C$DW$1007, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1007, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1008	.dwtag  DW_TAG_member
	.dwattr $C$DW$1008, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1008, DW_AT_name("mask")
	.dwattr $C$DW$1008, DW_AT_TI_symbol_name("_mask")
	.dwattr $C$DW$1008, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1008, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1009	.dwtag  DW_TAG_member
	.dwattr $C$DW$1009, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1009, DW_AT_name("gateway")
	.dwattr $C$DW$1009, DW_AT_TI_symbol_name("_gateway")
	.dwattr $C$DW$1009, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1009, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1010	.dwtag  DW_TAG_member
	.dwattr $C$DW$1010, DW_AT_type(*$C$DW$T$111)
	.dwattr $C$DW$1010, DW_AT_name("name")
	.dwattr $C$DW$1010, DW_AT_TI_symbol_name("_name")
	.dwattr $C$DW$1010, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$1010, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1011	.dwtag  DW_TAG_member
	.dwattr $C$DW$1011, DW_AT_type(*$C$DW$T$79)
	.dwattr $C$DW$1011, DW_AT_name("isdef")
	.dwattr $C$DW$1011, DW_AT_TI_symbol_name("_isdef")
	.dwattr $C$DW$1011, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$1011, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$125	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$125, DW_AT_declaration
	.dwattr $C$DW$125, DW_AT_TI_symbol_name("___as__15route_add_parmsFRC15route_add_parms")
	.dwattr $C$DW$125, DW_AT_type(*$C$DW$T$369)
	.dwattr $C$DW$125, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1012	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1012, DW_AT_type(*$C$DW$T$371)
	.dwendtag $C$DW$125

	.dwendtag $C$DW$T$373

$C$DW$T$369	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$369, DW_AT_type(*$C$DW$T$373)
	.dwattr $C$DW$T$369, DW_AT_address_class(0x20)

$C$DW$T$372	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$372, DW_AT_type(*$C$DW$T$369)
	.dwattr $C$DW$T$372, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1013	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1013, DW_AT_type(*$C$DW$T$371)
	.dwendtag $C$DW$T$372

$C$DW$T$370	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$370, DW_AT_type(*$C$DW$T$373)
$C$DW$T$371	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$371, DW_AT_type(*$C$DW$T$370)
	.dwattr $C$DW$T$371, DW_AT_address_class(0x20)

$C$DW$T$378	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$378, DW_AT_name("change_ip_parms")
	.dwattr $C$DW$T$378, DW_AT_byte_size(0x0c)
$C$DW$1014	.dwtag  DW_TAG_member
	.dwattr $C$DW$1014, DW_AT_type(*$C$DW$T$111)
	.dwattr $C$DW$1014, DW_AT_name("name")
	.dwattr $C$DW$1014, DW_AT_TI_symbol_name("_name")
	.dwattr $C$DW$1014, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1014, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1015	.dwtag  DW_TAG_member
	.dwattr $C$DW$1015, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1015, DW_AT_name("new_ip")
	.dwattr $C$DW$1015, DW_AT_TI_symbol_name("_new_ip")
	.dwattr $C$DW$1015, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1015, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1016	.dwtag  DW_TAG_member
	.dwattr $C$DW$1016, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1016, DW_AT_name("mask")
	.dwattr $C$DW$1016, DW_AT_TI_symbol_name("_mask")
	.dwattr $C$DW$1016, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1016, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$126	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$126, DW_AT_declaration
	.dwattr $C$DW$126, DW_AT_TI_symbol_name("___as__15change_ip_parmsFRC15change_ip_parms")
	.dwattr $C$DW$126, DW_AT_type(*$C$DW$T$374)
	.dwattr $C$DW$126, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1017	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1017, DW_AT_type(*$C$DW$T$376)
	.dwendtag $C$DW$126

	.dwendtag $C$DW$T$378

$C$DW$T$374	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$374, DW_AT_type(*$C$DW$T$378)
	.dwattr $C$DW$T$374, DW_AT_address_class(0x20)

$C$DW$T$377	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$377, DW_AT_type(*$C$DW$T$374)
	.dwattr $C$DW$T$377, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1018	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1018, DW_AT_type(*$C$DW$T$376)
	.dwendtag $C$DW$T$377

$C$DW$T$375	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$375, DW_AT_type(*$C$DW$T$378)
$C$DW$T$376	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$376, DW_AT_type(*$C$DW$T$375)
	.dwattr $C$DW$T$376, DW_AT_address_class(0x20)

$C$DW$T$383	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$383, DW_AT_name("linger")
	.dwattr $C$DW$T$383, DW_AT_byte_size(0x04)
$C$DW$1019	.dwtag  DW_TAG_member
	.dwattr $C$DW$1019, DW_AT_type(*$C$DW$T$22)
	.dwattr $C$DW$1019, DW_AT_name("l_onoff")
	.dwattr $C$DW$1019, DW_AT_TI_symbol_name("_l_onoff")
	.dwattr $C$DW$1019, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1019, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1020	.dwtag  DW_TAG_member
	.dwattr $C$DW$1020, DW_AT_type(*$C$DW$T$22)
	.dwattr $C$DW$1020, DW_AT_name("l_linger")
	.dwattr $C$DW$1020, DW_AT_TI_symbol_name("_l_linger")
	.dwattr $C$DW$1020, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr $C$DW$1020, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$127	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$127, DW_AT_declaration
	.dwattr $C$DW$127, DW_AT_TI_symbol_name("___as__6lingerFRC6linger")
	.dwattr $C$DW$127, DW_AT_type(*$C$DW$T$379)
	.dwattr $C$DW$127, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1021	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1021, DW_AT_type(*$C$DW$T$381)
	.dwendtag $C$DW$127

	.dwendtag $C$DW$T$383

$C$DW$T$379	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$379, DW_AT_type(*$C$DW$T$383)
	.dwattr $C$DW$T$379, DW_AT_address_class(0x20)

$C$DW$T$382	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$382, DW_AT_type(*$C$DW$T$379)
	.dwattr $C$DW$T$382, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1022	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1022, DW_AT_type(*$C$DW$T$381)
	.dwendtag $C$DW$T$382

$C$DW$T$380	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$380, DW_AT_type(*$C$DW$T$383)
$C$DW$T$381	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$381, DW_AT_type(*$C$DW$T$380)
	.dwattr $C$DW$T$381, DW_AT_address_class(0x20)

$C$DW$T$388	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$388, DW_AT_name("s_fwmem_sector_size")
	.dwattr $C$DW$T$388, DW_AT_byte_size(0x08)
$C$DW$1023	.dwtag  DW_TAG_member
	.dwattr $C$DW$1023, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1023, DW_AT_name("n")
	.dwattr $C$DW$1023, DW_AT_TI_symbol_name("_n")
	.dwattr $C$DW$1023, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1023, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1024	.dwtag  DW_TAG_member
	.dwattr $C$DW$1024, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1024, DW_AT_name("size")
	.dwattr $C$DW$1024, DW_AT_TI_symbol_name("_size")
	.dwattr $C$DW$1024, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1024, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$128	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$128, DW_AT_declaration
	.dwattr $C$DW$128, DW_AT_TI_symbol_name("___as__19s_fwmem_sector_sizeFRC19s_fwmem_sector_size")
	.dwattr $C$DW$128, DW_AT_type(*$C$DW$T$384)
	.dwattr $C$DW$128, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1025	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1025, DW_AT_type(*$C$DW$T$386)
	.dwendtag $C$DW$128

	.dwendtag $C$DW$T$388

$C$DW$T$384	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$384, DW_AT_type(*$C$DW$T$388)
	.dwattr $C$DW$T$384, DW_AT_address_class(0x20)

$C$DW$T$387	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$387, DW_AT_type(*$C$DW$T$384)
	.dwattr $C$DW$T$387, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1026	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1026, DW_AT_type(*$C$DW$T$386)
	.dwendtag $C$DW$T$387

$C$DW$T$385	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$385, DW_AT_type(*$C$DW$T$388)
$C$DW$T$386	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$386, DW_AT_type(*$C$DW$T$385)
	.dwattr $C$DW$T$386, DW_AT_address_class(0x20)
$C$DW$T$395	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$395, DW_AT_type(*$C$DW$T$388)
	.dwattr $C$DW$T$395, DW_AT_address_class(0x20)

$C$DW$T$406	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$406, DW_AT_name("s_fwmem_selector")
	.dwattr $C$DW$T$406, DW_AT_byte_size(0x20)
$C$DW$1027	.dwtag  DW_TAG_member
	.dwattr $C$DW$1027, DW_AT_type(*$C$DW$T$391)
	.dwattr $C$DW$1027, DW_AT_name("init")
	.dwattr $C$DW$1027, DW_AT_TI_symbol_name("_init")
	.dwattr $C$DW$1027, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1027, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1028	.dwtag  DW_TAG_member
	.dwattr $C$DW$1028, DW_AT_type(*$C$DW$T$391)
	.dwattr $C$DW$1028, DW_AT_name("deinit")
	.dwattr $C$DW$1028, DW_AT_TI_symbol_name("_deinit")
	.dwattr $C$DW$1028, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1028, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1029	.dwtag  DW_TAG_member
	.dwattr $C$DW$1029, DW_AT_type(*$C$DW$T$394)
	.dwattr $C$DW$1029, DW_AT_name("sector_count")
	.dwattr $C$DW$1029, DW_AT_TI_symbol_name("_sector_count")
	.dwattr $C$DW$1029, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1029, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1030	.dwtag  DW_TAG_member
	.dwattr $C$DW$1030, DW_AT_type(*$C$DW$T$397)
	.dwattr $C$DW$1030, DW_AT_name("sector_size")
	.dwattr $C$DW$1030, DW_AT_TI_symbol_name("_sector_size")
	.dwattr $C$DW$1030, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$1030, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1031	.dwtag  DW_TAG_member
	.dwattr $C$DW$1031, DW_AT_type(*$C$DW$T$399)
	.dwattr $C$DW$1031, DW_AT_name("sector_clear")
	.dwattr $C$DW$1031, DW_AT_TI_symbol_name("_sector_clear")
	.dwattr $C$DW$1031, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$1031, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1032	.dwtag  DW_TAG_member
	.dwattr $C$DW$1032, DW_AT_type(*$C$DW$T$401)
	.dwattr $C$DW$1032, DW_AT_name("write_buffer")
	.dwattr $C$DW$1032, DW_AT_TI_symbol_name("_write_buffer")
	.dwattr $C$DW$1032, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$1032, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1033	.dwtag  DW_TAG_member
	.dwattr $C$DW$1033, DW_AT_type(*$C$DW$T$401)
	.dwattr $C$DW$1033, DW_AT_name("read_buffer")
	.dwattr $C$DW$1033, DW_AT_TI_symbol_name("_read_buffer")
	.dwattr $C$DW$1033, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$1033, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1034	.dwtag  DW_TAG_member
	.dwattr $C$DW$1034, DW_AT_type(*$C$DW$T$394)
	.dwattr $C$DW$1034, DW_AT_name("size")
	.dwattr $C$DW$1034, DW_AT_TI_symbol_name("_size")
	.dwattr $C$DW$1034, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr $C$DW$1034, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$129	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$129, DW_AT_declaration
	.dwattr $C$DW$129, DW_AT_TI_symbol_name("___as__16s_fwmem_selectorFRC16s_fwmem_selector")
	.dwattr $C$DW$129, DW_AT_type(*$C$DW$T$402)
	.dwattr $C$DW$129, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1035	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1035, DW_AT_type(*$C$DW$T$404)
	.dwendtag $C$DW$129

	.dwendtag $C$DW$T$406

$C$DW$T$402	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$402, DW_AT_type(*$C$DW$T$406)
	.dwattr $C$DW$T$402, DW_AT_address_class(0x20)

$C$DW$T$405	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$405, DW_AT_type(*$C$DW$T$402)
	.dwattr $C$DW$T$405, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1036	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1036, DW_AT_type(*$C$DW$T$404)
	.dwendtag $C$DW$T$405

$C$DW$T$403	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$403, DW_AT_type(*$C$DW$T$406)
$C$DW$T$404	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$404, DW_AT_type(*$C$DW$T$403)
	.dwattr $C$DW$T$404, DW_AT_address_class(0x20)
$C$DW$T$407	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$407, DW_AT_type(*$C$DW$T$406)
	.dwattr $C$DW$T$407, DW_AT_address_class(0x20)

$C$DW$T$412	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$412, DW_AT_name("s_fwmem_context")
	.dwattr $C$DW$T$412, DW_AT_byte_size(0x14)
$C$DW$1037	.dwtag  DW_TAG_member
	.dwattr $C$DW$1037, DW_AT_type(*$C$DW$T$407)
	.dwattr $C$DW$1037, DW_AT_name("wctx")
	.dwattr $C$DW$1037, DW_AT_TI_symbol_name("_wctx")
	.dwattr $C$DW$1037, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1037, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1038	.dwtag  DW_TAG_member
	.dwattr $C$DW$1038, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1038, DW_AT_name("address")
	.dwattr $C$DW$1038, DW_AT_TI_symbol_name("_address")
	.dwattr $C$DW$1038, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1038, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1039	.dwtag  DW_TAG_member
	.dwattr $C$DW$1039, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1039, DW_AT_name("arg0")
	.dwattr $C$DW$1039, DW_AT_TI_symbol_name("_arg0")
	.dwattr $C$DW$1039, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1039, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1040	.dwtag  DW_TAG_member
	.dwattr $C$DW$1040, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1040, DW_AT_name("arg1")
	.dwattr $C$DW$1040, DW_AT_TI_symbol_name("_arg1")
	.dwattr $C$DW$1040, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$1040, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1041	.dwtag  DW_TAG_member
	.dwattr $C$DW$1041, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1041, DW_AT_name("sem")
	.dwattr $C$DW$1041, DW_AT_TI_symbol_name("_sem")
	.dwattr $C$DW$1041, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$1041, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$130	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$130, DW_AT_declaration
	.dwattr $C$DW$130, DW_AT_TI_symbol_name("___as__15s_fwmem_contextFRC15s_fwmem_context")
	.dwattr $C$DW$130, DW_AT_type(*$C$DW$T$408)
	.dwattr $C$DW$130, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1042	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1042, DW_AT_type(*$C$DW$T$410)
	.dwendtag $C$DW$130

	.dwendtag $C$DW$T$412

$C$DW$T$389	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$389, DW_AT_type(*$C$DW$T$412)
	.dwattr $C$DW$T$389, DW_AT_address_class(0x20)
$C$DW$T$408	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$408, DW_AT_type(*$C$DW$T$412)
	.dwattr $C$DW$T$408, DW_AT_address_class(0x20)

$C$DW$T$411	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$411, DW_AT_type(*$C$DW$T$408)
	.dwattr $C$DW$T$411, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1043	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1043, DW_AT_type(*$C$DW$T$410)
	.dwendtag $C$DW$T$411

$C$DW$T$409	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$409, DW_AT_type(*$C$DW$T$412)
$C$DW$T$410	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$410, DW_AT_type(*$C$DW$T$409)
	.dwattr $C$DW$T$410, DW_AT_address_class(0x20)

$C$DW$T$418	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$418, DW_AT_name("s_fwmem_record")
	.dwattr $C$DW$T$418, DW_AT_byte_size(0x40)
$C$DW$1044	.dwtag  DW_TAG_member
	.dwattr $C$DW$1044, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1044, DW_AT_name("magic")
	.dwattr $C$DW$1044, DW_AT_TI_symbol_name("_magic")
	.dwattr $C$DW$1044, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1044, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1045	.dwtag  DW_TAG_member
	.dwattr $C$DW$1045, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1045, DW_AT_name("prev_shift")
	.dwattr $C$DW$1045, DW_AT_TI_symbol_name("_prev_shift")
	.dwattr $C$DW$1045, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1045, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1046	.dwtag  DW_TAG_member
	.dwattr $C$DW$1046, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1046, DW_AT_name("next_shift")
	.dwattr $C$DW$1046, DW_AT_TI_symbol_name("_next_shift")
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
	.dwattr $C$DW$1048, DW_AT_name("mktime")
	.dwattr $C$DW$1048, DW_AT_TI_symbol_name("_mktime")
	.dwattr $C$DW$1048, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$1048, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1049	.dwtag  DW_TAG_member
	.dwattr $C$DW$1049, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1049, DW_AT_name("access")
	.dwattr $C$DW$1049, DW_AT_TI_symbol_name("_access")
	.dwattr $C$DW$1049, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$1049, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1050	.dwtag  DW_TAG_member
	.dwattr $C$DW$1050, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1050, DW_AT_name("own_user")
	.dwattr $C$DW$1050, DW_AT_TI_symbol_name("_own_user")
	.dwattr $C$DW$1050, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$1050, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1051	.dwtag  DW_TAG_member
	.dwattr $C$DW$1051, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1051, DW_AT_name("own_group")
	.dwattr $C$DW$1051, DW_AT_TI_symbol_name("_own_group")
	.dwattr $C$DW$1051, DW_AT_data_member_location[DW_OP_plus_uconst 0x1a]
	.dwattr $C$DW$1051, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1052	.dwtag  DW_TAG_member
	.dwattr $C$DW$1052, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1052, DW_AT_name("reserved_0")
	.dwattr $C$DW$1052, DW_AT_TI_symbol_name("_reserved_0")
	.dwattr $C$DW$1052, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr $C$DW$1052, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1053	.dwtag  DW_TAG_member
	.dwattr $C$DW$1053, DW_AT_type(*$C$DW$T$413)
	.dwattr $C$DW$1053, DW_AT_name("name")
	.dwattr $C$DW$1053, DW_AT_TI_symbol_name("_name")
	.dwattr $C$DW$1053, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr $C$DW$1053, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$131	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$131, DW_AT_declaration
	.dwattr $C$DW$131, DW_AT_TI_symbol_name("___as__14s_fwmem_recordFRC14s_fwmem_record")
	.dwattr $C$DW$131, DW_AT_type(*$C$DW$T$414)
	.dwattr $C$DW$131, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1054	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1054, DW_AT_type(*$C$DW$T$416)
	.dwendtag $C$DW$131

	.dwendtag $C$DW$T$418

$C$DW$T$414	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$414, DW_AT_type(*$C$DW$T$418)
	.dwattr $C$DW$T$414, DW_AT_address_class(0x20)

$C$DW$T$417	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$417, DW_AT_type(*$C$DW$T$414)
	.dwattr $C$DW$T$417, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1055	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1055, DW_AT_type(*$C$DW$T$416)
	.dwendtag $C$DW$T$417

$C$DW$T$415	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$415, DW_AT_type(*$C$DW$T$418)
$C$DW$T$416	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$416, DW_AT_type(*$C$DW$T$415)
	.dwattr $C$DW$T$416, DW_AT_address_class(0x20)

$C$DW$T$423	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$423, DW_AT_name("s_fwmem_rwbuf")
	.dwattr $C$DW$T$423, DW_AT_byte_size(0x08)
$C$DW$1056	.dwtag  DW_TAG_member
	.dwattr $C$DW$1056, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$1056, DW_AT_name("buffer")
	.dwattr $C$DW$1056, DW_AT_TI_symbol_name("_buffer")
	.dwattr $C$DW$1056, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1056, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1057	.dwtag  DW_TAG_member
	.dwattr $C$DW$1057, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1057, DW_AT_name("length")
	.dwattr $C$DW$1057, DW_AT_TI_symbol_name("_length")
	.dwattr $C$DW$1057, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1057, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$132	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$132, DW_AT_declaration
	.dwattr $C$DW$132, DW_AT_TI_symbol_name("___as__13s_fwmem_rwbufFRC13s_fwmem_rwbuf")
	.dwattr $C$DW$132, DW_AT_type(*$C$DW$T$419)
	.dwattr $C$DW$132, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1058	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1058, DW_AT_type(*$C$DW$T$421)
	.dwendtag $C$DW$132

	.dwendtag $C$DW$T$423

$C$DW$T$419	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$419, DW_AT_type(*$C$DW$T$423)
	.dwattr $C$DW$T$419, DW_AT_address_class(0x20)

$C$DW$T$422	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$422, DW_AT_type(*$C$DW$T$419)
	.dwattr $C$DW$T$422, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1059	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1059, DW_AT_type(*$C$DW$T$421)
	.dwendtag $C$DW$T$422

$C$DW$T$420	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$420, DW_AT_type(*$C$DW$T$423)
$C$DW$T$421	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$421, DW_AT_type(*$C$DW$T$420)
	.dwattr $C$DW$T$421, DW_AT_address_class(0x20)

$C$DW$T$428	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$428, DW_AT_name("kdg_cmd")
	.dwattr $C$DW$T$428, DW_AT_byte_size(0x04)
$C$DW$1060	.dwtag  DW_TAG_member
	.dwattr $C$DW$1060, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1060, DW_AT_name("cmd")
	.dwattr $C$DW$1060, DW_AT_TI_symbol_name("_cmd")
	.dwattr $C$DW$1060, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1060, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$133	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$133, DW_AT_declaration
	.dwattr $C$DW$133, DW_AT_TI_symbol_name("___as__7kdg_cmdFRC7kdg_cmd")
	.dwattr $C$DW$133, DW_AT_type(*$C$DW$T$424)
	.dwattr $C$DW$133, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1061	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1061, DW_AT_type(*$C$DW$T$426)
	.dwendtag $C$DW$133

	.dwendtag $C$DW$T$428

$C$DW$T$424	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$424, DW_AT_type(*$C$DW$T$428)
	.dwattr $C$DW$T$424, DW_AT_address_class(0x20)

$C$DW$T$427	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$427, DW_AT_type(*$C$DW$T$424)
	.dwattr $C$DW$T$427, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1062	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1062, DW_AT_type(*$C$DW$T$426)
	.dwendtag $C$DW$T$427

$C$DW$T$425	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$425, DW_AT_type(*$C$DW$T$428)
$C$DW$T$426	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$426, DW_AT_type(*$C$DW$T$425)
	.dwattr $C$DW$T$426, DW_AT_address_class(0x20)

$C$DW$T$433	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$433, DW_AT_name("kdg_cmd_ask")
	.dwattr $C$DW$T$433, DW_AT_byte_size(0x08)
$C$DW$1063	.dwtag  DW_TAG_member
	.dwattr $C$DW$1063, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1063, DW_AT_name("cmd")
	.dwattr $C$DW$1063, DW_AT_TI_symbol_name("_cmd")
	.dwattr $C$DW$1063, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1063, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1064	.dwtag  DW_TAG_member
	.dwattr $C$DW$1064, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1064, DW_AT_name("ask")
	.dwattr $C$DW$1064, DW_AT_TI_symbol_name("_ask")
	.dwattr $C$DW$1064, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1064, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$134	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$134, DW_AT_declaration
	.dwattr $C$DW$134, DW_AT_TI_symbol_name("___as__11kdg_cmd_askFRC11kdg_cmd_ask")
	.dwattr $C$DW$134, DW_AT_type(*$C$DW$T$429)
	.dwattr $C$DW$134, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1065	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1065, DW_AT_type(*$C$DW$T$431)
	.dwendtag $C$DW$134

	.dwendtag $C$DW$T$433

$C$DW$T$429	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$429, DW_AT_type(*$C$DW$T$433)
	.dwattr $C$DW$T$429, DW_AT_address_class(0x20)

$C$DW$T$432	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$432, DW_AT_type(*$C$DW$T$429)
	.dwattr $C$DW$T$432, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1066	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1066, DW_AT_type(*$C$DW$T$431)
	.dwendtag $C$DW$T$432

$C$DW$T$430	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$430, DW_AT_type(*$C$DW$T$433)
$C$DW$T$431	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$431, DW_AT_type(*$C$DW$T$430)
	.dwattr $C$DW$T$431, DW_AT_address_class(0x20)

$C$DW$T$438	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$438, DW_AT_name("kdg_rez_test")
	.dwattr $C$DW$T$438, DW_AT_byte_size(0x3c)
$C$DW$1067	.dwtag  DW_TAG_member
	.dwattr $C$DW$1067, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1067, DW_AT_name("cmd")
	.dwattr $C$DW$1067, DW_AT_TI_symbol_name("_cmd")
	.dwattr $C$DW$1067, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1067, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1068	.dwtag  DW_TAG_member
	.dwattr $C$DW$1068, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1068, DW_AT_name("n_test")
	.dwattr $C$DW$1068, DW_AT_TI_symbol_name("_n_test")
	.dwattr $C$DW$1068, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1068, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1069	.dwtag  DW_TAG_member
	.dwattr $C$DW$1069, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1069, DW_AT_name("rez")
	.dwattr $C$DW$1069, DW_AT_TI_symbol_name("_rez")
	.dwattr $C$DW$1069, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1069, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1070	.dwtag  DW_TAG_member
	.dwattr $C$DW$1070, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1070, DW_AT_name("adrr")
	.dwattr $C$DW$1070, DW_AT_TI_symbol_name("_adrr")
	.dwattr $C$DW$1070, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$1070, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1071	.dwtag  DW_TAG_member
	.dwattr $C$DW$1071, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1071, DW_AT_name("data")
	.dwattr $C$DW$1071, DW_AT_TI_symbol_name("_data")
	.dwattr $C$DW$1071, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$1071, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1072	.dwtag  DW_TAG_member
	.dwattr $C$DW$1072, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1072, DW_AT_name("data1")
	.dwattr $C$DW$1072, DW_AT_TI_symbol_name("_data1")
	.dwattr $C$DW$1072, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$1072, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1073	.dwtag  DW_TAG_member
	.dwattr $C$DW$1073, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1073, DW_AT_name("err")
	.dwattr $C$DW$1073, DW_AT_TI_symbol_name("_err")
	.dwattr $C$DW$1073, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$1073, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1074	.dwtag  DW_TAG_member
	.dwattr $C$DW$1074, DW_AT_type(*$C$DW$T$302)
	.dwattr $C$DW$1074, DW_AT_name("buf")
	.dwattr $C$DW$1074, DW_AT_TI_symbol_name("_buf")
	.dwattr $C$DW$1074, DW_AT_data_member_location[DW_OP_plus_uconst 0x1c]
	.dwattr $C$DW$1074, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$135	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$135, DW_AT_declaration
	.dwattr $C$DW$135, DW_AT_TI_symbol_name("___as__12kdg_rez_testFRC12kdg_rez_test")
	.dwattr $C$DW$135, DW_AT_type(*$C$DW$T$434)
	.dwattr $C$DW$135, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1075	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1075, DW_AT_type(*$C$DW$T$436)
	.dwendtag $C$DW$135

	.dwendtag $C$DW$T$438

$C$DW$T$434	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$434, DW_AT_type(*$C$DW$T$438)
	.dwattr $C$DW$T$434, DW_AT_address_class(0x20)

$C$DW$T$437	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$437, DW_AT_type(*$C$DW$T$434)
	.dwattr $C$DW$T$437, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1076	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1076, DW_AT_type(*$C$DW$T$436)
	.dwendtag $C$DW$T$437

$C$DW$T$435	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$435, DW_AT_type(*$C$DW$T$438)
$C$DW$T$436	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$436, DW_AT_type(*$C$DW$T$435)
	.dwattr $C$DW$T$436, DW_AT_address_class(0x20)
$C$DW$T$672	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$672, DW_AT_type(*$C$DW$T$438)
	.dwattr $C$DW$T$672, DW_AT_address_class(0x20)

$C$DW$T$443	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$443, DW_AT_name("rez_test")
	.dwattr $C$DW$T$443, DW_AT_byte_size(0x10)
$C$DW$1077	.dwtag  DW_TAG_member
	.dwattr $C$DW$1077, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1077, DW_AT_name("cmd")
	.dwattr $C$DW$1077, DW_AT_TI_symbol_name("_cmd")
	.dwattr $C$DW$1077, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1077, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1078	.dwtag  DW_TAG_member
	.dwattr $C$DW$1078, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1078, DW_AT_name("n_test")
	.dwattr $C$DW$1078, DW_AT_TI_symbol_name("_n_test")
	.dwattr $C$DW$1078, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1078, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1079	.dwtag  DW_TAG_member
	.dwattr $C$DW$1079, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1079, DW_AT_name("rez0")
	.dwattr $C$DW$1079, DW_AT_TI_symbol_name("_rez0")
	.dwattr $C$DW$1079, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1079, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1080	.dwtag  DW_TAG_member
	.dwattr $C$DW$1080, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1080, DW_AT_name("rez1")
	.dwattr $C$DW$1080, DW_AT_TI_symbol_name("_rez1")
	.dwattr $C$DW$1080, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$1080, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$136	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$136, DW_AT_declaration
	.dwattr $C$DW$136, DW_AT_TI_symbol_name("___as__8rez_testFRC8rez_test")
	.dwattr $C$DW$136, DW_AT_type(*$C$DW$T$439)
	.dwattr $C$DW$136, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1081	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1081, DW_AT_type(*$C$DW$T$441)
	.dwendtag $C$DW$136

	.dwendtag $C$DW$T$443

$C$DW$T$439	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$439, DW_AT_type(*$C$DW$T$443)
	.dwattr $C$DW$T$439, DW_AT_address_class(0x20)

$C$DW$T$442	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$442, DW_AT_type(*$C$DW$T$439)
	.dwattr $C$DW$T$442, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1082	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1082, DW_AT_type(*$C$DW$T$441)
	.dwendtag $C$DW$T$442

$C$DW$T$440	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$440, DW_AT_type(*$C$DW$T$443)
$C$DW$T$441	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$441, DW_AT_type(*$C$DW$T$440)
	.dwattr $C$DW$T$441, DW_AT_address_class(0x20)

$C$DW$T$452	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$452, DW_AT_name("about_usb")
	.dwattr $C$DW$T$452, DW_AT_byte_size(0x38)
$C$DW$1083	.dwtag  DW_TAG_member
	.dwattr $C$DW$1083, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1083, DW_AT_name("enable")
	.dwattr $C$DW$1083, DW_AT_TI_symbol_name("_enable")
	.dwattr $C$DW$1083, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1083, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1084	.dwtag  DW_TAG_member
	.dwattr $C$DW$1084, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1084, DW_AT_name("block_length")
	.dwattr $C$DW$1084, DW_AT_TI_symbol_name("_block_length")
	.dwattr $C$DW$1084, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1084, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1085	.dwtag  DW_TAG_member
	.dwattr $C$DW$1085, DW_AT_type(*$C$DW$T$66)
	.dwattr $C$DW$1085, DW_AT_name("flash_capacity")
	.dwattr $C$DW$1085, DW_AT_TI_symbol_name("_flash_capacity")
	.dwattr $C$DW$1085, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1085, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1086	.dwtag  DW_TAG_member
	.dwattr $C$DW$1086, DW_AT_type(*$C$DW$T$444)
	.dwattr $C$DW$1086, DW_AT_name("vendor_identification")
	.dwattr $C$DW$1086, DW_AT_TI_symbol_name("_vendor_identification")
	.dwattr $C$DW$1086, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$1086, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1087	.dwtag  DW_TAG_member
	.dwattr $C$DW$1087, DW_AT_type(*$C$DW$T$445)
	.dwattr $C$DW$1087, DW_AT_name("product_identification")
	.dwattr $C$DW$1087, DW_AT_TI_symbol_name("_product_identification")
	.dwattr $C$DW$1087, DW_AT_data_member_location[DW_OP_plus_uconst 0x1a]
	.dwattr $C$DW$1087, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1088	.dwtag  DW_TAG_member
	.dwattr $C$DW$1088, DW_AT_type(*$C$DW$T$446)
	.dwattr $C$DW$1088, DW_AT_name("product_revision_level")
	.dwattr $C$DW$1088, DW_AT_TI_symbol_name("_product_revision_level")
	.dwattr $C$DW$1088, DW_AT_data_member_location[DW_OP_plus_uconst 0x2b]
	.dwattr $C$DW$1088, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1089	.dwtag  DW_TAG_member
	.dwattr $C$DW$1089, DW_AT_type(*$C$DW$T$447)
	.dwattr $C$DW$1089, DW_AT_name("fstr")
	.dwattr $C$DW$1089, DW_AT_TI_symbol_name("_fstr")
	.dwattr $C$DW$1089, DW_AT_data_member_location[DW_OP_plus_uconst 0x30]
	.dwattr $C$DW$1089, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$137	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$137, DW_AT_declaration
	.dwattr $C$DW$137, DW_AT_TI_symbol_name("___as__9about_usbFRC9about_usb")
	.dwattr $C$DW$137, DW_AT_type(*$C$DW$T$448)
	.dwattr $C$DW$137, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1090	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1090, DW_AT_type(*$C$DW$T$450)
	.dwendtag $C$DW$137

	.dwendtag $C$DW$T$452

$C$DW$T$448	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$448, DW_AT_type(*$C$DW$T$452)
	.dwattr $C$DW$T$448, DW_AT_address_class(0x20)

$C$DW$T$451	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$451, DW_AT_type(*$C$DW$T$448)
	.dwattr $C$DW$T$451, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1091	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1091, DW_AT_type(*$C$DW$T$450)
	.dwendtag $C$DW$T$451

$C$DW$T$449	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$449, DW_AT_type(*$C$DW$T$452)
$C$DW$T$450	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$450, DW_AT_type(*$C$DW$T$449)
	.dwattr $C$DW$T$450, DW_AT_address_class(0x20)

$C$DW$T$735	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$735, DW_AT_type(*$C$DW$T$452)
	.dwattr $C$DW$T$735, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$735, DW_AT_byte_size(0x70)
$C$DW$1092	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$1092, DW_AT_upper_bound(0x01)
	.dwendtag $C$DW$T$735


$C$DW$T$457	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$457, DW_AT_name("comm_status")
	.dwattr $C$DW$T$457, DW_AT_byte_size(0x08)
$C$DW$1093	.dwtag  DW_TAG_member
	.dwattr $C$DW$1093, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1093, DW_AT_name("N")
	.dwattr $C$DW$1093, DW_AT_TI_symbol_name("_N")
	.dwattr $C$DW$1093, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1093, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1094	.dwtag  DW_TAG_member
	.dwattr $C$DW$1094, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1094, DW_AT_name("pid")
	.dwattr $C$DW$1094, DW_AT_TI_symbol_name("_pid")
	.dwattr $C$DW$1094, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1094, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$138	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$138, DW_AT_declaration
	.dwattr $C$DW$138, DW_AT_TI_symbol_name("___as__11comm_statusFRC11comm_status")
	.dwattr $C$DW$138, DW_AT_type(*$C$DW$T$453)
	.dwattr $C$DW$138, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1095	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1095, DW_AT_type(*$C$DW$T$455)
	.dwendtag $C$DW$138

	.dwendtag $C$DW$T$457

$C$DW$T$453	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$453, DW_AT_type(*$C$DW$T$457)
	.dwattr $C$DW$T$453, DW_AT_address_class(0x20)

$C$DW$T$456	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$456, DW_AT_type(*$C$DW$T$453)
	.dwattr $C$DW$T$456, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1096	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1096, DW_AT_type(*$C$DW$T$455)
	.dwendtag $C$DW$T$456

$C$DW$T$454	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$454, DW_AT_type(*$C$DW$T$457)
$C$DW$T$455	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$455, DW_AT_type(*$C$DW$T$454)
	.dwattr $C$DW$T$455, DW_AT_address_class(0x20)

$C$DW$T$462	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$462, DW_AT_name("_SkEthTestRes")
	.dwattr $C$DW$T$462, DW_AT_byte_size(0x14)
$C$DW$1097	.dwtag  DW_TAG_member
	.dwattr $C$DW$1097, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1097, DW_AT_name("errRegDP")
	.dwattr $C$DW$1097, DW_AT_TI_symbol_name("_errRegDP")
	.dwattr $C$DW$1097, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1097, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1098	.dwtag  DW_TAG_member
	.dwattr $C$DW$1098, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1098, DW_AT_name("errRegLX")
	.dwattr $C$DW$1098, DW_AT_TI_symbol_name("_errRegLX")
	.dwattr $C$DW$1098, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1098, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1099	.dwtag  DW_TAG_member
	.dwattr $C$DW$1099, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1099, DW_AT_name("errSP_DP")
	.dwattr $C$DW$1099, DW_AT_TI_symbol_name("_errSP_DP")
	.dwattr $C$DW$1099, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1099, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1100	.dwtag  DW_TAG_member
	.dwattr $C$DW$1100, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1100, DW_AT_name("errSP_LX")
	.dwattr $C$DW$1100, DW_AT_TI_symbol_name("_errSP_LX")
	.dwattr $C$DW$1100, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$1100, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1101	.dwtag  DW_TAG_member
	.dwattr $C$DW$1101, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1101, DW_AT_name("errSP_TR")
	.dwattr $C$DW$1101, DW_AT_TI_symbol_name("_errSP_TR")
	.dwattr $C$DW$1101, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$1101, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$139	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$139, DW_AT_declaration
	.dwattr $C$DW$139, DW_AT_TI_symbol_name("___as__13_SkEthTestResFRC13_SkEthTestRes")
	.dwattr $C$DW$139, DW_AT_type(*$C$DW$T$458)
	.dwattr $C$DW$139, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1102	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1102, DW_AT_type(*$C$DW$T$460)
	.dwendtag $C$DW$139

	.dwendtag $C$DW$T$462

$C$DW$T$458	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$458, DW_AT_type(*$C$DW$T$462)
	.dwattr $C$DW$T$458, DW_AT_address_class(0x20)

$C$DW$T$461	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$461, DW_AT_type(*$C$DW$T$458)
	.dwattr $C$DW$T$461, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1103	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1103, DW_AT_type(*$C$DW$T$460)
	.dwendtag $C$DW$T$461

$C$DW$T$459	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$459, DW_AT_type(*$C$DW$T$462)
$C$DW$T$460	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$460, DW_AT_type(*$C$DW$T$459)
	.dwattr $C$DW$T$460, DW_AT_address_class(0x20)
$C$DW$T$736	.dwtag  DW_TAG_typedef, DW_AT_name("SkEthTestRes")
	.dwattr $C$DW$T$736, DW_AT_type(*$C$DW$T$462)
	.dwattr $C$DW$T$736, DW_AT_language(DW_LANG_C_plus_plus)

$C$DW$T$467	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$467, DW_AT_name("_TestDnsdRes")
	.dwattr $C$DW$T$467, DW_AT_byte_size(0x0c)
$C$DW$1104	.dwtag  DW_TAG_member
	.dwattr $C$DW$1104, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1104, DW_AT_name("errTimeout")
	.dwattr $C$DW$1104, DW_AT_TI_symbol_name("_errTimeout")
	.dwattr $C$DW$1104, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1104, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1105	.dwtag  DW_TAG_member
	.dwattr $C$DW$1105, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1105, DW_AT_name("errReadC0")
	.dwattr $C$DW$1105, DW_AT_TI_symbol_name("_errReadC0")
	.dwattr $C$DW$1105, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1105, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1106	.dwtag  DW_TAG_member
	.dwattr $C$DW$1106, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1106, DW_AT_name("errTrigger")
	.dwattr $C$DW$1106, DW_AT_TI_symbol_name("_errTrigger")
	.dwattr $C$DW$1106, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1106, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$140	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$140, DW_AT_declaration
	.dwattr $C$DW$140, DW_AT_TI_symbol_name("___as__12_TestDnsdResFRC12_TestDnsdRes")
	.dwattr $C$DW$140, DW_AT_type(*$C$DW$T$463)
	.dwattr $C$DW$140, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1107	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1107, DW_AT_type(*$C$DW$T$465)
	.dwendtag $C$DW$140

	.dwendtag $C$DW$T$467

$C$DW$T$463	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$463, DW_AT_type(*$C$DW$T$467)
	.dwattr $C$DW$T$463, DW_AT_address_class(0x20)

$C$DW$T$466	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$466, DW_AT_type(*$C$DW$T$463)
	.dwattr $C$DW$T$466, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1108	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1108, DW_AT_type(*$C$DW$T$465)
	.dwendtag $C$DW$T$466

$C$DW$T$464	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$464, DW_AT_type(*$C$DW$T$467)
$C$DW$T$465	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$465, DW_AT_type(*$C$DW$T$464)
	.dwattr $C$DW$T$465, DW_AT_address_class(0x20)
$C$DW$T$737	.dwtag  DW_TAG_typedef, DW_AT_name("TestDnsdRes")
	.dwattr $C$DW$T$737, DW_AT_type(*$C$DW$T$467)
	.dwattr $C$DW$T$737, DW_AT_language(DW_LANG_C_plus_plus)

$C$DW$T$472	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$472, DW_AT_name("_EthCFG")
	.dwattr $C$DW$T$472, DW_AT_byte_size(0x04)
$C$DW$1109	.dwtag  DW_TAG_member
	.dwattr $C$DW$1109, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1109, DW_AT_name("eth_send")
	.dwattr $C$DW$1109, DW_AT_TI_symbol_name("_eth_send")
	.dwattr $C$DW$1109, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1109, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1110	.dwtag  DW_TAG_member
	.dwattr $C$DW$1110, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1110, DW_AT_name("eth_recv")
	.dwattr $C$DW$1110, DW_AT_TI_symbol_name("_eth_recv")
	.dwattr $C$DW$1110, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr $C$DW$1110, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$141	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$141, DW_AT_declaration
	.dwattr $C$DW$141, DW_AT_TI_symbol_name("___as__7_EthCFGFRC7_EthCFG")
	.dwattr $C$DW$141, DW_AT_type(*$C$DW$T$468)
	.dwattr $C$DW$141, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1111	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1111, DW_AT_type(*$C$DW$T$470)
	.dwendtag $C$DW$141

	.dwendtag $C$DW$T$472

$C$DW$T$468	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$468, DW_AT_type(*$C$DW$T$472)
	.dwattr $C$DW$T$468, DW_AT_address_class(0x20)

$C$DW$T$471	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$471, DW_AT_type(*$C$DW$T$468)
	.dwattr $C$DW$T$471, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1112	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1112, DW_AT_type(*$C$DW$T$470)
	.dwendtag $C$DW$T$471

$C$DW$T$469	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$469, DW_AT_type(*$C$DW$T$472)
$C$DW$T$470	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$470, DW_AT_type(*$C$DW$T$469)
	.dwattr $C$DW$T$470, DW_AT_address_class(0x20)
$C$DW$T$738	.dwtag  DW_TAG_typedef, DW_AT_name("EthCFG")
	.dwattr $C$DW$T$738, DW_AT_type(*$C$DW$T$472)
	.dwattr $C$DW$T$738, DW_AT_language(DW_LANG_C_plus_plus)

$C$DW$T$477	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$477, DW_AT_name("_CryptErrors")
	.dwattr $C$DW$T$477, DW_AT_byte_size(0x18)
$C$DW$1113	.dwtag  DW_TAG_member
	.dwattr $C$DW$1113, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1113, DW_AT_name("NumPack")
	.dwattr $C$DW$1113, DW_AT_TI_symbol_name("_NumPack")
	.dwattr $C$DW$1113, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1113, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1114	.dwtag  DW_TAG_member
	.dwattr $C$DW$1114, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1114, DW_AT_name("BodyErr")
	.dwattr $C$DW$1114, DW_AT_TI_symbol_name("_BodyErr")
	.dwattr $C$DW$1114, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1114, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1115	.dwtag  DW_TAG_member
	.dwattr $C$DW$1115, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1115, DW_AT_name("ImvErr")
	.dwattr $C$DW$1115, DW_AT_TI_symbol_name("_ImvErr")
	.dwattr $C$DW$1115, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1115, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1116	.dwtag  DW_TAG_member
	.dwattr $C$DW$1116, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1116, DW_AT_name("CtrBErr")
	.dwattr $C$DW$1116, DW_AT_TI_symbol_name("_CtrBErr")
	.dwattr $C$DW$1116, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$1116, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1117	.dwtag  DW_TAG_member
	.dwattr $C$DW$1117, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1117, DW_AT_name("LostPack")
	.dwattr $C$DW$1117, DW_AT_TI_symbol_name("_LostPack")
	.dwattr $C$DW$1117, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$1117, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1118	.dwtag  DW_TAG_member
	.dwattr $C$DW$1118, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1118, DW_AT_name("CMPerr")
	.dwattr $C$DW$1118, DW_AT_TI_symbol_name("_CMPerr")
	.dwattr $C$DW$1118, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$1118, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$142	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$142, DW_AT_declaration
	.dwattr $C$DW$142, DW_AT_TI_symbol_name("___as__12_CryptErrorsFRC12_CryptErrors")
	.dwattr $C$DW$142, DW_AT_type(*$C$DW$T$473)
	.dwattr $C$DW$142, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1119	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1119, DW_AT_type(*$C$DW$T$475)
	.dwendtag $C$DW$142

	.dwendtag $C$DW$T$477

$C$DW$T$473	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$473, DW_AT_type(*$C$DW$T$477)
	.dwattr $C$DW$T$473, DW_AT_address_class(0x20)

$C$DW$T$476	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$476, DW_AT_type(*$C$DW$T$473)
	.dwattr $C$DW$T$476, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1120	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1120, DW_AT_type(*$C$DW$T$475)
	.dwendtag $C$DW$T$476

$C$DW$T$474	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$474, DW_AT_type(*$C$DW$T$477)
$C$DW$T$475	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$475, DW_AT_type(*$C$DW$T$474)
	.dwattr $C$DW$T$475, DW_AT_address_class(0x20)
$C$DW$T$739	.dwtag  DW_TAG_typedef, DW_AT_name("CryptErrors")
	.dwattr $C$DW$T$739, DW_AT_type(*$C$DW$T$477)
	.dwattr $C$DW$T$739, DW_AT_language(DW_LANG_C_plus_plus)

$C$DW$T$740	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$740, DW_AT_type(*$C$DW$T$739)
	.dwattr $C$DW$T$740, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$740, DW_AT_byte_size(0x30)
$C$DW$1121	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$1121, DW_AT_upper_bound(0x01)
	.dwendtag $C$DW$T$740


$C$DW$T$483	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$483, DW_AT_name("s_hash")
	.dwattr $C$DW$T$483, DW_AT_byte_size(0x44)
$C$DW$1122	.dwtag  DW_TAG_member
	.dwattr $C$DW$1122, DW_AT_type(*$C$DW$T$478)
	.dwattr $C$DW$1122, DW_AT_name("h")
	.dwattr $C$DW$1122, DW_AT_TI_symbol_name("_h")
	.dwattr $C$DW$1122, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1122, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1123	.dwtag  DW_TAG_member
	.dwattr $C$DW$1123, DW_AT_type(*$C$DW$T$478)
	.dwattr $C$DW$1123, DW_AT_name("e")
	.dwattr $C$DW$1123, DW_AT_TI_symbol_name("_e")
	.dwattr $C$DW$1123, DW_AT_data_member_location[DW_OP_plus_uconst 0x20]
	.dwattr $C$DW$1123, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1124	.dwtag  DW_TAG_member
	.dwattr $C$DW$1124, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1124, DW_AT_name("len")
	.dwattr $C$DW$1124, DW_AT_TI_symbol_name("_len")
	.dwattr $C$DW$1124, DW_AT_data_member_location[DW_OP_plus_uconst 0x40]
	.dwattr $C$DW$1124, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$143	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$143, DW_AT_declaration
	.dwattr $C$DW$143, DW_AT_TI_symbol_name("___as__6s_hashFRC6s_hash")
	.dwattr $C$DW$143, DW_AT_type(*$C$DW$T$479)
	.dwattr $C$DW$143, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1125	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1125, DW_AT_type(*$C$DW$T$481)
	.dwendtag $C$DW$143

	.dwendtag $C$DW$T$483

$C$DW$T$479	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$479, DW_AT_type(*$C$DW$T$483)
	.dwattr $C$DW$T$479, DW_AT_address_class(0x20)

$C$DW$T$482	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$482, DW_AT_type(*$C$DW$T$479)
	.dwattr $C$DW$T$482, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1126	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1126, DW_AT_type(*$C$DW$T$481)
	.dwendtag $C$DW$T$482

$C$DW$T$480	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$480, DW_AT_type(*$C$DW$T$483)
$C$DW$T$481	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$481, DW_AT_type(*$C$DW$T$480)
	.dwattr $C$DW$T$481, DW_AT_address_class(0x20)

$C$DW$T$488	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$488, DW_AT_name("fwmem_rwbuf")
	.dwattr $C$DW$T$488, DW_AT_byte_size(0x08)
$C$DW$1127	.dwtag  DW_TAG_member
	.dwattr $C$DW$1127, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$1127, DW_AT_name("buffer")
	.dwattr $C$DW$1127, DW_AT_TI_symbol_name("_buffer")
	.dwattr $C$DW$1127, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1127, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1128	.dwtag  DW_TAG_member
	.dwattr $C$DW$1128, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1128, DW_AT_name("length")
	.dwattr $C$DW$1128, DW_AT_TI_symbol_name("_length")
	.dwattr $C$DW$1128, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1128, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$144	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$144, DW_AT_declaration
	.dwattr $C$DW$144, DW_AT_TI_symbol_name("___as__11fwmem_rwbufFRC11fwmem_rwbuf")
	.dwattr $C$DW$144, DW_AT_type(*$C$DW$T$484)
	.dwattr $C$DW$144, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1129	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1129, DW_AT_type(*$C$DW$T$486)
	.dwendtag $C$DW$144

	.dwendtag $C$DW$T$488

$C$DW$T$484	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$484, DW_AT_type(*$C$DW$T$488)
	.dwattr $C$DW$T$484, DW_AT_address_class(0x20)

$C$DW$T$487	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$487, DW_AT_type(*$C$DW$T$484)
	.dwattr $C$DW$T$487, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1130	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1130, DW_AT_type(*$C$DW$T$486)
	.dwendtag $C$DW$T$487

$C$DW$T$485	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$485, DW_AT_type(*$C$DW$T$488)
$C$DW$T$486	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$486, DW_AT_type(*$C$DW$T$485)
	.dwattr $C$DW$T$486, DW_AT_address_class(0x20)

$C$DW$T$493	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$493, DW_AT_name("msg_hash_fwm")
	.dwattr $C$DW$T$493, DW_AT_byte_size(0x8c)
$C$DW$1131	.dwtag  DW_TAG_member
	.dwattr $C$DW$1131, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$1131, DW_AT_name("akn")
	.dwattr $C$DW$1131, DW_AT_TI_symbol_name("_akn")
	.dwattr $C$DW$1131, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1131, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1132	.dwtag  DW_TAG_member
	.dwattr $C$DW$1132, DW_AT_type(*$C$DW$T$483)
	.dwattr $C$DW$1132, DW_AT_name("hash")
	.dwattr $C$DW$1132, DW_AT_TI_symbol_name("_hash")
	.dwattr $C$DW$1132, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1132, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1133	.dwtag  DW_TAG_member
	.dwattr $C$DW$1133, DW_AT_type(*$C$DW$T$483)
	.dwattr $C$DW$1133, DW_AT_name("hash_fwm")
	.dwattr $C$DW$1133, DW_AT_TI_symbol_name("_hash_fwm")
	.dwattr $C$DW$1133, DW_AT_data_member_location[DW_OP_plus_uconst 0x48]
	.dwattr $C$DW$1133, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$145	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$145, DW_AT_declaration
	.dwattr $C$DW$145, DW_AT_TI_symbol_name("___as__12msg_hash_fwmFRC12msg_hash_fwm")
	.dwattr $C$DW$145, DW_AT_type(*$C$DW$T$489)
	.dwattr $C$DW$145, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1134	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1134, DW_AT_type(*$C$DW$T$491)
	.dwendtag $C$DW$145

	.dwendtag $C$DW$T$493

$C$DW$T$489	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$489, DW_AT_type(*$C$DW$T$493)
	.dwattr $C$DW$T$489, DW_AT_address_class(0x20)

$C$DW$T$492	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$492, DW_AT_type(*$C$DW$T$489)
	.dwattr $C$DW$T$492, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1135	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1135, DW_AT_type(*$C$DW$T$491)
	.dwendtag $C$DW$T$492

$C$DW$T$490	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$490, DW_AT_type(*$C$DW$T$493)
$C$DW$T$491	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$491, DW_AT_type(*$C$DW$T$490)
	.dwattr $C$DW$T$491, DW_AT_address_class(0x20)

$C$DW$T$498	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$498, DW_AT_name("hash_window")
	.dwattr $C$DW$T$498, DW_AT_byte_size(0x08)
$C$DW$1136	.dwtag  DW_TAG_member
	.dwattr $C$DW$1136, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1136, DW_AT_name("start_addr")
	.dwattr $C$DW$1136, DW_AT_TI_symbol_name("_start_addr")
	.dwattr $C$DW$1136, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1136, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1137	.dwtag  DW_TAG_member
	.dwattr $C$DW$1137, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1137, DW_AT_name("end_addr")
	.dwattr $C$DW$1137, DW_AT_TI_symbol_name("_end_addr")
	.dwattr $C$DW$1137, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1137, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$146	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$146, DW_AT_declaration
	.dwattr $C$DW$146, DW_AT_TI_symbol_name("___as__11hash_windowFRC11hash_window")
	.dwattr $C$DW$146, DW_AT_type(*$C$DW$T$494)
	.dwattr $C$DW$146, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1138	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1138, DW_AT_type(*$C$DW$T$496)
	.dwendtag $C$DW$146

	.dwendtag $C$DW$T$498

$C$DW$T$494	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$494, DW_AT_type(*$C$DW$T$498)
	.dwattr $C$DW$T$494, DW_AT_address_class(0x20)

$C$DW$T$497	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$497, DW_AT_type(*$C$DW$T$494)
	.dwattr $C$DW$T$497, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1139	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1139, DW_AT_type(*$C$DW$T$496)
	.dwendtag $C$DW$T$497

$C$DW$T$495	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$495, DW_AT_type(*$C$DW$T$498)
$C$DW$T$496	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$496, DW_AT_type(*$C$DW$T$495)
	.dwattr $C$DW$T$496, DW_AT_address_class(0x20)

$C$DW$T$741	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$741, DW_AT_type(*$C$DW$T$498)
	.dwattr $C$DW$T$741, DW_AT_language(DW_LANG_C_plus_plus)
	.dwattr $C$DW$T$741, DW_AT_byte_size(0x18)
$C$DW$1140	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$1140, DW_AT_upper_bound(0x02)
	.dwendtag $C$DW$T$741


$C$DW$T$503	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$503, DW_AT_name("kdg_sialp")
	.dwattr $C$DW$T$503, DW_AT_byte_size(0x08)
$C$DW$1141	.dwtag  DW_TAG_member
	.dwattr $C$DW$1141, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$1141, DW_AT_name("tiptest")
	.dwattr $C$DW$1141, DW_AT_TI_symbol_name("_tiptest")
	.dwattr $C$DW$1141, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1141, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1142	.dwtag  DW_TAG_member
	.dwattr $C$DW$1142, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$1142, DW_AT_name("kodtest")
	.dwattr $C$DW$1142, DW_AT_TI_symbol_name("_kodtest")
	.dwattr $C$DW$1142, DW_AT_data_member_location[DW_OP_plus_uconst 0x1]
	.dwattr $C$DW$1142, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1143	.dwtag  DW_TAG_member
	.dwattr $C$DW$1143, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1143, DW_AT_name("time_ms")
	.dwattr $C$DW$1143, DW_AT_TI_symbol_name("_time_ms")
	.dwattr $C$DW$1143, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr $C$DW$1143, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1144	.dwtag  DW_TAG_member
	.dwattr $C$DW$1144, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$1144, DW_AT_name("val_1")
	.dwattr $C$DW$1144, DW_AT_TI_symbol_name("_val_1")
	.dwattr $C$DW$1144, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1144, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1145	.dwtag  DW_TAG_member
	.dwattr $C$DW$1145, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$1145, DW_AT_name("val_2")
	.dwattr $C$DW$1145, DW_AT_TI_symbol_name("_val_2")
	.dwattr $C$DW$1145, DW_AT_data_member_location[DW_OP_plus_uconst 0x5]
	.dwattr $C$DW$1145, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1146	.dwtag  DW_TAG_member
	.dwattr $C$DW$1146, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1146, DW_AT_name("channel")
	.dwattr $C$DW$1146, DW_AT_TI_symbol_name("_channel")
	.dwattr $C$DW$1146, DW_AT_data_member_location[DW_OP_plus_uconst 0x6]
	.dwattr $C$DW$1146, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$147	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$147, DW_AT_declaration
	.dwattr $C$DW$147, DW_AT_TI_symbol_name("___as__9kdg_sialpFRC9kdg_sialp")
	.dwattr $C$DW$147, DW_AT_type(*$C$DW$T$499)
	.dwattr $C$DW$147, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1147	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1147, DW_AT_type(*$C$DW$T$501)
	.dwendtag $C$DW$147

	.dwendtag $C$DW$T$503

$C$DW$T$499	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$499, DW_AT_type(*$C$DW$T$503)
	.dwattr $C$DW$T$499, DW_AT_address_class(0x20)

$C$DW$T$502	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$502, DW_AT_type(*$C$DW$T$499)
	.dwattr $C$DW$T$502, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1148	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1148, DW_AT_type(*$C$DW$T$501)
	.dwendtag $C$DW$T$502

$C$DW$T$500	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$500, DW_AT_type(*$C$DW$T$503)
$C$DW$T$501	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$501, DW_AT_type(*$C$DW$T$500)
	.dwattr $C$DW$T$501, DW_AT_address_class(0x20)

$C$DW$T$509	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$509, DW_AT_name("net_eth")
	.dwattr $C$DW$T$509, DW_AT_byte_size(0x0e)
$C$DW$1149	.dwtag  DW_TAG_member
	.dwattr $C$DW$1149, DW_AT_type(*$C$DW$T$504)
	.dwattr $C$DW$1149, DW_AT_name("dst")
	.dwattr $C$DW$1149, DW_AT_TI_symbol_name("_dst")
	.dwattr $C$DW$1149, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1149, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1150	.dwtag  DW_TAG_member
	.dwattr $C$DW$1150, DW_AT_type(*$C$DW$T$504)
	.dwattr $C$DW$1150, DW_AT_name("src")
	.dwattr $C$DW$1150, DW_AT_TI_symbol_name("_src")
	.dwattr $C$DW$1150, DW_AT_data_member_location[DW_OP_plus_uconst 0x6]
	.dwattr $C$DW$1150, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1151	.dwtag  DW_TAG_member
	.dwattr $C$DW$1151, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1151, DW_AT_name("protocol")
	.dwattr $C$DW$1151, DW_AT_TI_symbol_name("_protocol")
	.dwattr $C$DW$1151, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$1151, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$148	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$148, DW_AT_declaration
	.dwattr $C$DW$148, DW_AT_TI_symbol_name("___as__7net_ethFRC7net_eth")
	.dwattr $C$DW$148, DW_AT_type(*$C$DW$T$505)
	.dwattr $C$DW$148, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1152	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1152, DW_AT_type(*$C$DW$T$507)
	.dwendtag $C$DW$148

	.dwendtag $C$DW$T$509

$C$DW$T$505	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$505, DW_AT_type(*$C$DW$T$509)
	.dwattr $C$DW$T$505, DW_AT_address_class(0x20)

$C$DW$T$508	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$508, DW_AT_type(*$C$DW$T$505)
	.dwattr $C$DW$T$508, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1153	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1153, DW_AT_type(*$C$DW$T$507)
	.dwendtag $C$DW$T$508

$C$DW$T$506	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$506, DW_AT_type(*$C$DW$T$509)
$C$DW$T$507	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$507, DW_AT_type(*$C$DW$T$506)
	.dwattr $C$DW$T$507, DW_AT_address_class(0x20)
$C$DW$T$582	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$582, DW_AT_type(*$C$DW$T$509)
	.dwattr $C$DW$T$582, DW_AT_address_class(0x20)

$C$DW$T$514	.dwtag  DW_TAG_union_type
	.dwattr $C$DW$T$514, DW_AT_byte_size(0x04)
$C$DW$1154	.dwtag  DW_TAG_member
	.dwattr $C$DW$1154, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1154, DW_AT_name("src_ip")
	.dwattr $C$DW$1154, DW_AT_TI_symbol_name("_src_ip")
	.dwattr $C$DW$1154, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1154, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1155	.dwtag  DW_TAG_member
	.dwattr $C$DW$1155, DW_AT_type(*$C$DW$T$40)
	.dwattr $C$DW$1155, DW_AT_name("src_ip_char")
	.dwattr $C$DW$1155, DW_AT_TI_symbol_name("_src_ip_char")
	.dwattr $C$DW$1155, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1155, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$149	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$149, DW_AT_declaration
	.dwattr $C$DW$149, DW_AT_TI_symbol_name("___as__Q2_6net_ip4__C1FRCQ2_6net_ip4__C1")
	.dwattr $C$DW$149, DW_AT_type(*$C$DW$T$510)
	.dwattr $C$DW$149, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1156	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1156, DW_AT_type(*$C$DW$T$512)
	.dwendtag $C$DW$149

	.dwendtag $C$DW$T$514

$C$DW$T$510	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$510, DW_AT_type(*$C$DW$T$514)
	.dwattr $C$DW$T$510, DW_AT_address_class(0x20)

$C$DW$T$513	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$513, DW_AT_type(*$C$DW$T$510)
	.dwattr $C$DW$T$513, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1157	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1157, DW_AT_type(*$C$DW$T$512)
	.dwendtag $C$DW$T$513

$C$DW$T$511	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$511, DW_AT_type(*$C$DW$T$514)
$C$DW$T$512	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$512, DW_AT_type(*$C$DW$T$511)
	.dwattr $C$DW$T$512, DW_AT_address_class(0x20)

$C$DW$T$519	.dwtag  DW_TAG_union_type
	.dwattr $C$DW$T$519, DW_AT_byte_size(0x04)
$C$DW$1158	.dwtag  DW_TAG_member
	.dwattr $C$DW$1158, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1158, DW_AT_name("dst_ip")
	.dwattr $C$DW$1158, DW_AT_TI_symbol_name("_dst_ip")
	.dwattr $C$DW$1158, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1158, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1159	.dwtag  DW_TAG_member
	.dwattr $C$DW$1159, DW_AT_type(*$C$DW$T$40)
	.dwattr $C$DW$1159, DW_AT_name("dst_ip_char")
	.dwattr $C$DW$1159, DW_AT_TI_symbol_name("_dst_ip_char")
	.dwattr $C$DW$1159, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1159, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$150	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$150, DW_AT_declaration
	.dwattr $C$DW$150, DW_AT_TI_symbol_name("___as__Q2_6net_ip4__C2FRCQ2_6net_ip4__C2")
	.dwattr $C$DW$150, DW_AT_type(*$C$DW$T$515)
	.dwattr $C$DW$150, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1160	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1160, DW_AT_type(*$C$DW$T$517)
	.dwendtag $C$DW$150

	.dwendtag $C$DW$T$519

$C$DW$T$515	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$515, DW_AT_type(*$C$DW$T$519)
	.dwattr $C$DW$T$515, DW_AT_address_class(0x20)

$C$DW$T$518	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$518, DW_AT_type(*$C$DW$T$515)
	.dwattr $C$DW$T$518, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1161	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1161, DW_AT_type(*$C$DW$T$517)
	.dwendtag $C$DW$T$518

$C$DW$T$516	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$516, DW_AT_type(*$C$DW$T$519)
$C$DW$T$517	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$517, DW_AT_type(*$C$DW$T$516)
	.dwattr $C$DW$T$517, DW_AT_address_class(0x20)

$C$DW$T$524	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$524, DW_AT_name("net_ip")
	.dwattr $C$DW$T$524, DW_AT_byte_size(0x14)
$C$DW$1162	.dwtag  DW_TAG_member
	.dwattr $C$DW$1162, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$1162, DW_AT_name("version_ihl")
	.dwattr $C$DW$1162, DW_AT_TI_symbol_name("_version_ihl")
	.dwattr $C$DW$1162, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1162, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1163	.dwtag  DW_TAG_member
	.dwattr $C$DW$1163, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$1163, DW_AT_name("type_of_service")
	.dwattr $C$DW$1163, DW_AT_TI_symbol_name("_type_of_service")
	.dwattr $C$DW$1163, DW_AT_data_member_location[DW_OP_plus_uconst 0x1]
	.dwattr $C$DW$1163, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1164	.dwtag  DW_TAG_member
	.dwattr $C$DW$1164, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1164, DW_AT_name("total_length")
	.dwattr $C$DW$1164, DW_AT_TI_symbol_name("_total_length")
	.dwattr $C$DW$1164, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr $C$DW$1164, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1165	.dwtag  DW_TAG_member
	.dwattr $C$DW$1165, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1165, DW_AT_name("id")
	.dwattr $C$DW$1165, DW_AT_TI_symbol_name("_id")
	.dwattr $C$DW$1165, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1165, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1166	.dwtag  DW_TAG_member
	.dwattr $C$DW$1166, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1166, DW_AT_name("flags_offset")
	.dwattr $C$DW$1166, DW_AT_TI_symbol_name("_flags_offset")
	.dwattr $C$DW$1166, DW_AT_data_member_location[DW_OP_plus_uconst 0x6]
	.dwattr $C$DW$1166, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1167	.dwtag  DW_TAG_member
	.dwattr $C$DW$1167, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$1167, DW_AT_name("ttl")
	.dwattr $C$DW$1167, DW_AT_TI_symbol_name("_ttl")
	.dwattr $C$DW$1167, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1167, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1168	.dwtag  DW_TAG_member
	.dwattr $C$DW$1168, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$1168, DW_AT_name("protocol")
	.dwattr $C$DW$1168, DW_AT_TI_symbol_name("_protocol")
	.dwattr $C$DW$1168, DW_AT_data_member_location[DW_OP_plus_uconst 0x9]
	.dwattr $C$DW$1168, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1169	.dwtag  DW_TAG_member
	.dwattr $C$DW$1169, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1169, DW_AT_name("checksumm")
	.dwattr $C$DW$1169, DW_AT_TI_symbol_name("_checksumm")
	.dwattr $C$DW$1169, DW_AT_data_member_location[DW_OP_plus_uconst 0xa]
	.dwattr $C$DW$1169, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1170	.dwtag  DW_TAG_member
	.dwattr $C$DW$1170, DW_AT_type(*$C$DW$T$514)
	.dwattr $C$DW$1170, DW_AT_name("$P$T0")
	.dwattr $C$DW$1170, DW_AT_TI_symbol_name("_$P$T0")
	.dwattr $C$DW$1170, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$1170, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1171	.dwtag  DW_TAG_member
	.dwattr $C$DW$1171, DW_AT_type(*$C$DW$T$519)
	.dwattr $C$DW$1171, DW_AT_name("$P$T1")
	.dwattr $C$DW$1171, DW_AT_TI_symbol_name("_$P$T1")
	.dwattr $C$DW$1171, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$1171, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$151	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$151, DW_AT_declaration
	.dwattr $C$DW$151, DW_AT_TI_symbol_name("___as__6net_ipFRC6net_ip")
	.dwattr $C$DW$151, DW_AT_type(*$C$DW$T$520)
	.dwattr $C$DW$151, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1172	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1172, DW_AT_type(*$C$DW$T$522)
	.dwendtag $C$DW$151

	.dwendtag $C$DW$T$524

$C$DW$T$520	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$520, DW_AT_type(*$C$DW$T$524)
	.dwattr $C$DW$T$520, DW_AT_address_class(0x20)

$C$DW$T$523	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$523, DW_AT_type(*$C$DW$T$520)
	.dwattr $C$DW$T$523, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1173	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1173, DW_AT_type(*$C$DW$T$522)
	.dwendtag $C$DW$T$523

$C$DW$T$521	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$521, DW_AT_type(*$C$DW$T$524)
$C$DW$T$522	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$522, DW_AT_type(*$C$DW$T$521)
	.dwattr $C$DW$T$522, DW_AT_address_class(0x20)
$C$DW$T$588	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$588, DW_AT_type(*$C$DW$T$524)
	.dwattr $C$DW$T$588, DW_AT_address_class(0x20)

$C$DW$T$529	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$529, DW_AT_name("net_arp")
	.dwattr $C$DW$T$529, DW_AT_byte_size(0x1c)
$C$DW$1174	.dwtag  DW_TAG_member
	.dwattr $C$DW$1174, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1174, DW_AT_name("hrd_addr_fmt")
	.dwattr $C$DW$1174, DW_AT_TI_symbol_name("_hrd_addr_fmt")
	.dwattr $C$DW$1174, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1174, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1175	.dwtag  DW_TAG_member
	.dwattr $C$DW$1175, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1175, DW_AT_name("proto_addr_fmt")
	.dwattr $C$DW$1175, DW_AT_TI_symbol_name("_proto_addr_fmt")
	.dwattr $C$DW$1175, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr $C$DW$1175, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1176	.dwtag  DW_TAG_member
	.dwattr $C$DW$1176, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$1176, DW_AT_name("hdr_addr_len")
	.dwattr $C$DW$1176, DW_AT_TI_symbol_name("_hdr_addr_len")
	.dwattr $C$DW$1176, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1176, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1177	.dwtag  DW_TAG_member
	.dwattr $C$DW$1177, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$1177, DW_AT_name("proto_addr_len")
	.dwattr $C$DW$1177, DW_AT_TI_symbol_name("_proto_addr_len")
	.dwattr $C$DW$1177, DW_AT_data_member_location[DW_OP_plus_uconst 0x5]
	.dwattr $C$DW$1177, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1178	.dwtag  DW_TAG_member
	.dwattr $C$DW$1178, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1178, DW_AT_name("opcode")
	.dwattr $C$DW$1178, DW_AT_TI_symbol_name("_opcode")
	.dwattr $C$DW$1178, DW_AT_data_member_location[DW_OP_plus_uconst 0x6]
	.dwattr $C$DW$1178, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1179	.dwtag  DW_TAG_member
	.dwattr $C$DW$1179, DW_AT_type(*$C$DW$T$504)
	.dwattr $C$DW$1179, DW_AT_name("sender_mac")
	.dwattr $C$DW$1179, DW_AT_TI_symbol_name("_sender_mac")
	.dwattr $C$DW$1179, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1179, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1180	.dwtag  DW_TAG_member
	.dwattr $C$DW$1180, DW_AT_type(*$C$DW$T$40)
	.dwattr $C$DW$1180, DW_AT_name("sender_ip")
	.dwattr $C$DW$1180, DW_AT_TI_symbol_name("_sender_ip")
	.dwattr $C$DW$1180, DW_AT_data_member_location[DW_OP_plus_uconst 0xe]
	.dwattr $C$DW$1180, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1181	.dwtag  DW_TAG_member
	.dwattr $C$DW$1181, DW_AT_type(*$C$DW$T$504)
	.dwattr $C$DW$1181, DW_AT_name("target_mac")
	.dwattr $C$DW$1181, DW_AT_TI_symbol_name("_target_mac")
	.dwattr $C$DW$1181, DW_AT_data_member_location[DW_OP_plus_uconst 0x12]
	.dwattr $C$DW$1181, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1182	.dwtag  DW_TAG_member
	.dwattr $C$DW$1182, DW_AT_type(*$C$DW$T$40)
	.dwattr $C$DW$1182, DW_AT_name("target_ip")
	.dwattr $C$DW$1182, DW_AT_TI_symbol_name("_target_ip")
	.dwattr $C$DW$1182, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$1182, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$152	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$152, DW_AT_declaration
	.dwattr $C$DW$152, DW_AT_TI_symbol_name("___as__7net_arpFRC7net_arp")
	.dwattr $C$DW$152, DW_AT_type(*$C$DW$T$525)
	.dwattr $C$DW$152, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1183	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1183, DW_AT_type(*$C$DW$T$527)
	.dwendtag $C$DW$152

	.dwendtag $C$DW$T$529

$C$DW$T$525	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$525, DW_AT_type(*$C$DW$T$529)
	.dwattr $C$DW$T$525, DW_AT_address_class(0x20)

$C$DW$T$528	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$528, DW_AT_type(*$C$DW$T$525)
	.dwattr $C$DW$T$528, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1184	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1184, DW_AT_type(*$C$DW$T$527)
	.dwendtag $C$DW$T$528

$C$DW$T$526	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$526, DW_AT_type(*$C$DW$T$529)
$C$DW$T$527	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$527, DW_AT_type(*$C$DW$T$526)
	.dwattr $C$DW$T$527, DW_AT_address_class(0x20)
$C$DW$T$589	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$589, DW_AT_type(*$C$DW$T$529)
	.dwattr $C$DW$T$589, DW_AT_address_class(0x20)

$C$DW$T$534	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$534, DW_AT_name("net_udp")
	.dwattr $C$DW$T$534, DW_AT_byte_size(0x08)
$C$DW$1185	.dwtag  DW_TAG_member
	.dwattr $C$DW$1185, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1185, DW_AT_name("src_port")
	.dwattr $C$DW$1185, DW_AT_TI_symbol_name("_src_port")
	.dwattr $C$DW$1185, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1185, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1186	.dwtag  DW_TAG_member
	.dwattr $C$DW$1186, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1186, DW_AT_name("dst_port")
	.dwattr $C$DW$1186, DW_AT_TI_symbol_name("_dst_port")
	.dwattr $C$DW$1186, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr $C$DW$1186, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1187	.dwtag  DW_TAG_member
	.dwattr $C$DW$1187, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1187, DW_AT_name("length")
	.dwattr $C$DW$1187, DW_AT_TI_symbol_name("_length")
	.dwattr $C$DW$1187, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1187, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1188	.dwtag  DW_TAG_member
	.dwattr $C$DW$1188, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1188, DW_AT_name("checksumm")
	.dwattr $C$DW$1188, DW_AT_TI_symbol_name("_checksumm")
	.dwattr $C$DW$1188, DW_AT_data_member_location[DW_OP_plus_uconst 0x6]
	.dwattr $C$DW$1188, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$153	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$153, DW_AT_declaration
	.dwattr $C$DW$153, DW_AT_TI_symbol_name("___as__7net_udpFRC7net_udp")
	.dwattr $C$DW$153, DW_AT_type(*$C$DW$T$530)
	.dwattr $C$DW$153, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1189	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1189, DW_AT_type(*$C$DW$T$532)
	.dwendtag $C$DW$153

	.dwendtag $C$DW$T$534

$C$DW$T$530	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$530, DW_AT_type(*$C$DW$T$534)
	.dwattr $C$DW$T$530, DW_AT_address_class(0x20)

$C$DW$T$533	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$533, DW_AT_type(*$C$DW$T$530)
	.dwattr $C$DW$T$533, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1190	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1190, DW_AT_type(*$C$DW$T$532)
	.dwendtag $C$DW$T$533

$C$DW$T$531	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$531, DW_AT_type(*$C$DW$T$534)
$C$DW$T$532	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$532, DW_AT_type(*$C$DW$T$531)
	.dwattr $C$DW$T$532, DW_AT_address_class(0x20)
$C$DW$T$596	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$596, DW_AT_type(*$C$DW$T$534)
	.dwattr $C$DW$T$596, DW_AT_address_class(0x20)

$C$DW$T$539	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$539, DW_AT_name("net_tcp")
	.dwattr $C$DW$T$539, DW_AT_byte_size(0x14)
$C$DW$1191	.dwtag  DW_TAG_member
	.dwattr $C$DW$1191, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1191, DW_AT_name("src_port")
	.dwattr $C$DW$1191, DW_AT_TI_symbol_name("_src_port")
	.dwattr $C$DW$1191, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1191, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1192	.dwtag  DW_TAG_member
	.dwattr $C$DW$1192, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1192, DW_AT_name("dst_port")
	.dwattr $C$DW$1192, DW_AT_TI_symbol_name("_dst_port")
	.dwattr $C$DW$1192, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr $C$DW$1192, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1193	.dwtag  DW_TAG_member
	.dwattr $C$DW$1193, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1193, DW_AT_name("sequence_number")
	.dwattr $C$DW$1193, DW_AT_TI_symbol_name("_sequence_number")
	.dwattr $C$DW$1193, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1193, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1194	.dwtag  DW_TAG_member
	.dwattr $C$DW$1194, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1194, DW_AT_name("acknowledgement_number")
	.dwattr $C$DW$1194, DW_AT_TI_symbol_name("_acknowledgement_number")
	.dwattr $C$DW$1194, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1194, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1195	.dwtag  DW_TAG_member
	.dwattr $C$DW$1195, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$1195, DW_AT_name("offset_rsvd")
	.dwattr $C$DW$1195, DW_AT_TI_symbol_name("_offset_rsvd")
	.dwattr $C$DW$1195, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$1195, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1196	.dwtag  DW_TAG_member
	.dwattr $C$DW$1196, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$1196, DW_AT_name("rsvd_flags")
	.dwattr $C$DW$1196, DW_AT_TI_symbol_name("_rsvd_flags")
	.dwattr $C$DW$1196, DW_AT_data_member_location[DW_OP_plus_uconst 0xd]
	.dwattr $C$DW$1196, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1197	.dwtag  DW_TAG_member
	.dwattr $C$DW$1197, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1197, DW_AT_name("window")
	.dwattr $C$DW$1197, DW_AT_TI_symbol_name("_window")
	.dwattr $C$DW$1197, DW_AT_data_member_location[DW_OP_plus_uconst 0xe]
	.dwattr $C$DW$1197, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1198	.dwtag  DW_TAG_member
	.dwattr $C$DW$1198, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1198, DW_AT_name("checksumm")
	.dwattr $C$DW$1198, DW_AT_TI_symbol_name("_checksumm")
	.dwattr $C$DW$1198, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$1198, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1199	.dwtag  DW_TAG_member
	.dwattr $C$DW$1199, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1199, DW_AT_name("urgent_point")
	.dwattr $C$DW$1199, DW_AT_TI_symbol_name("_urgent_point")
	.dwattr $C$DW$1199, DW_AT_data_member_location[DW_OP_plus_uconst 0x12]
	.dwattr $C$DW$1199, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$154	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$154, DW_AT_declaration
	.dwattr $C$DW$154, DW_AT_TI_symbol_name("___as__7net_tcpFRC7net_tcp")
	.dwattr $C$DW$154, DW_AT_type(*$C$DW$T$535)
	.dwattr $C$DW$154, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1200	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1200, DW_AT_type(*$C$DW$T$537)
	.dwendtag $C$DW$154

	.dwendtag $C$DW$T$539

$C$DW$T$535	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$535, DW_AT_type(*$C$DW$T$539)
	.dwattr $C$DW$T$535, DW_AT_address_class(0x20)

$C$DW$T$538	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$538, DW_AT_type(*$C$DW$T$535)
	.dwattr $C$DW$T$538, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1201	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1201, DW_AT_type(*$C$DW$T$537)
	.dwendtag $C$DW$T$538

$C$DW$T$536	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$536, DW_AT_type(*$C$DW$T$539)
$C$DW$T$537	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$537, DW_AT_type(*$C$DW$T$536)
	.dwattr $C$DW$T$537, DW_AT_address_class(0x20)
$C$DW$T$595	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$595, DW_AT_type(*$C$DW$T$539)
	.dwattr $C$DW$T$595, DW_AT_address_class(0x20)

$C$DW$T$544	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$544, DW_AT_byte_size(0x04)
$C$DW$1202	.dwtag  DW_TAG_member
	.dwattr $C$DW$1202, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1202, DW_AT_name("id")
	.dwattr $C$DW$1202, DW_AT_TI_symbol_name("_id")
	.dwattr $C$DW$1202, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1202, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1203	.dwtag  DW_TAG_member
	.dwattr $C$DW$1203, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1203, DW_AT_name("sequence")
	.dwattr $C$DW$1203, DW_AT_TI_symbol_name("_sequence")
	.dwattr $C$DW$1203, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr $C$DW$1203, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$155	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$155, DW_AT_declaration
	.dwattr $C$DW$155, DW_AT_TI_symbol_name("___as__Q3_8net_icmp4__C14__C1FRCQ3_8net_icmp4__C14__C1")
	.dwattr $C$DW$155, DW_AT_type(*$C$DW$T$540)
	.dwattr $C$DW$155, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1204	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1204, DW_AT_type(*$C$DW$T$542)
	.dwendtag $C$DW$155

	.dwendtag $C$DW$T$544

$C$DW$T$540	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$540, DW_AT_type(*$C$DW$T$544)
	.dwattr $C$DW$T$540, DW_AT_address_class(0x20)

$C$DW$T$543	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$543, DW_AT_type(*$C$DW$T$540)
	.dwattr $C$DW$T$543, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1205	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1205, DW_AT_type(*$C$DW$T$542)
	.dwendtag $C$DW$T$543

$C$DW$T$541	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$541, DW_AT_type(*$C$DW$T$544)
$C$DW$T$542	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$542, DW_AT_type(*$C$DW$T$541)
	.dwattr $C$DW$T$542, DW_AT_address_class(0x20)

$C$DW$T$549	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$549, DW_AT_byte_size(0x04)
$C$DW$1206	.dwtag  DW_TAG_member
	.dwattr $C$DW$1206, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1206, DW_AT_name("__unused")
	.dwattr $C$DW$1206, DW_AT_TI_symbol_name("___unused")
	.dwattr $C$DW$1206, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1206, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1207	.dwtag  DW_TAG_member
	.dwattr $C$DW$1207, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1207, DW_AT_name("mtu")
	.dwattr $C$DW$1207, DW_AT_TI_symbol_name("_mtu")
	.dwattr $C$DW$1207, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr $C$DW$1207, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$156	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$156, DW_AT_declaration
	.dwattr $C$DW$156, DW_AT_TI_symbol_name("___as__Q3_8net_icmp4__C14__C2FRCQ3_8net_icmp4__C14__C2")
	.dwattr $C$DW$156, DW_AT_type(*$C$DW$T$545)
	.dwattr $C$DW$156, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1208	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1208, DW_AT_type(*$C$DW$T$547)
	.dwendtag $C$DW$156

	.dwendtag $C$DW$T$549

$C$DW$T$545	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$545, DW_AT_type(*$C$DW$T$549)
	.dwattr $C$DW$T$545, DW_AT_address_class(0x20)

$C$DW$T$548	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$548, DW_AT_type(*$C$DW$T$545)
	.dwattr $C$DW$T$548, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1209	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1209, DW_AT_type(*$C$DW$T$547)
	.dwendtag $C$DW$T$548

$C$DW$T$546	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$546, DW_AT_type(*$C$DW$T$549)
$C$DW$T$547	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$547, DW_AT_type(*$C$DW$T$546)
	.dwattr $C$DW$T$547, DW_AT_address_class(0x20)

$C$DW$T$554	.dwtag  DW_TAG_union_type
	.dwattr $C$DW$T$554, DW_AT_byte_size(0x04)
$C$DW$1210	.dwtag  DW_TAG_member
	.dwattr $C$DW$1210, DW_AT_type(*$C$DW$T$544)
	.dwattr $C$DW$1210, DW_AT_name("echo")
	.dwattr $C$DW$1210, DW_AT_TI_symbol_name("_echo")
	.dwattr $C$DW$1210, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1210, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1211	.dwtag  DW_TAG_member
	.dwattr $C$DW$1211, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1211, DW_AT_name("gateway")
	.dwattr $C$DW$1211, DW_AT_TI_symbol_name("_gateway")
	.dwattr $C$DW$1211, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1211, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1212	.dwtag  DW_TAG_member
	.dwattr $C$DW$1212, DW_AT_type(*$C$DW$T$549)
	.dwattr $C$DW$1212, DW_AT_name("frag")
	.dwattr $C$DW$1212, DW_AT_TI_symbol_name("_frag")
	.dwattr $C$DW$1212, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1212, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$157	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$157, DW_AT_declaration
	.dwattr $C$DW$157, DW_AT_TI_symbol_name("___as__Q2_8net_icmp4__C1FRCQ2_8net_icmp4__C1")
	.dwattr $C$DW$157, DW_AT_type(*$C$DW$T$550)
	.dwattr $C$DW$157, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1213	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1213, DW_AT_type(*$C$DW$T$552)
	.dwendtag $C$DW$157

	.dwendtag $C$DW$T$554

$C$DW$T$550	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$550, DW_AT_type(*$C$DW$T$554)
	.dwattr $C$DW$T$550, DW_AT_address_class(0x20)

$C$DW$T$553	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$553, DW_AT_type(*$C$DW$T$550)
	.dwattr $C$DW$T$553, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1214	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1214, DW_AT_type(*$C$DW$T$552)
	.dwendtag $C$DW$T$553

$C$DW$T$551	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$551, DW_AT_type(*$C$DW$T$554)
$C$DW$T$552	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$552, DW_AT_type(*$C$DW$T$551)
	.dwattr $C$DW$T$552, DW_AT_address_class(0x20)

$C$DW$T$559	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$559, DW_AT_name("net_icmp")
	.dwattr $C$DW$T$559, DW_AT_byte_size(0x08)
$C$DW$1215	.dwtag  DW_TAG_member
	.dwattr $C$DW$1215, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$1215, DW_AT_name("type")
	.dwattr $C$DW$1215, DW_AT_TI_symbol_name("_type")
	.dwattr $C$DW$1215, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1215, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1216	.dwtag  DW_TAG_member
	.dwattr $C$DW$1216, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$1216, DW_AT_name("code")
	.dwattr $C$DW$1216, DW_AT_TI_symbol_name("_code")
	.dwattr $C$DW$1216, DW_AT_data_member_location[DW_OP_plus_uconst 0x1]
	.dwattr $C$DW$1216, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1217	.dwtag  DW_TAG_member
	.dwattr $C$DW$1217, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1217, DW_AT_name("checksum")
	.dwattr $C$DW$1217, DW_AT_TI_symbol_name("_checksum")
	.dwattr $C$DW$1217, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr $C$DW$1217, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1218	.dwtag  DW_TAG_member
	.dwattr $C$DW$1218, DW_AT_type(*$C$DW$T$554)
	.dwattr $C$DW$1218, DW_AT_name("un")
	.dwattr $C$DW$1218, DW_AT_TI_symbol_name("_un")
	.dwattr $C$DW$1218, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1218, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$158	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$158, DW_AT_declaration
	.dwattr $C$DW$158, DW_AT_TI_symbol_name("___as__8net_icmpFRC8net_icmp")
	.dwattr $C$DW$158, DW_AT_type(*$C$DW$T$555)
	.dwattr $C$DW$158, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1219	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1219, DW_AT_type(*$C$DW$T$557)
	.dwendtag $C$DW$158

	.dwendtag $C$DW$T$559

$C$DW$T$555	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$555, DW_AT_type(*$C$DW$T$559)
	.dwattr $C$DW$T$555, DW_AT_address_class(0x20)

$C$DW$T$558	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$558, DW_AT_type(*$C$DW$T$555)
	.dwattr $C$DW$T$558, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1220	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1220, DW_AT_type(*$C$DW$T$557)
	.dwendtag $C$DW$T$558

$C$DW$T$556	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$556, DW_AT_type(*$C$DW$T$559)
$C$DW$T$557	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$557, DW_AT_type(*$C$DW$T$556)
	.dwattr $C$DW$T$557, DW_AT_address_class(0x20)
$C$DW$T$597	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$597, DW_AT_type(*$C$DW$T$559)
	.dwattr $C$DW$T$597, DW_AT_address_class(0x20)

$C$DW$T$564	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$564, DW_AT_name("net_igmp_v2")
	.dwattr $C$DW$T$564, DW_AT_byte_size(0x08)
$C$DW$1221	.dwtag  DW_TAG_member
	.dwattr $C$DW$1221, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$1221, DW_AT_name("type")
	.dwattr $C$DW$1221, DW_AT_TI_symbol_name("_type")
	.dwattr $C$DW$1221, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1221, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1222	.dwtag  DW_TAG_member
	.dwattr $C$DW$1222, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$1222, DW_AT_name("max_response_time")
	.dwattr $C$DW$1222, DW_AT_TI_symbol_name("_max_response_time")
	.dwattr $C$DW$1222, DW_AT_data_member_location[DW_OP_plus_uconst 0x1]
	.dwattr $C$DW$1222, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1223	.dwtag  DW_TAG_member
	.dwattr $C$DW$1223, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1223, DW_AT_name("check_summ")
	.dwattr $C$DW$1223, DW_AT_TI_symbol_name("_check_summ")
	.dwattr $C$DW$1223, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr $C$DW$1223, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1224	.dwtag  DW_TAG_member
	.dwattr $C$DW$1224, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1224, DW_AT_name("group_address")
	.dwattr $C$DW$1224, DW_AT_TI_symbol_name("_group_address")
	.dwattr $C$DW$1224, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1224, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$159	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$159, DW_AT_declaration
	.dwattr $C$DW$159, DW_AT_TI_symbol_name("___as__11net_igmp_v2FRC11net_igmp_v2")
	.dwattr $C$DW$159, DW_AT_type(*$C$DW$T$560)
	.dwattr $C$DW$159, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1225	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1225, DW_AT_type(*$C$DW$T$562)
	.dwendtag $C$DW$159

	.dwendtag $C$DW$T$564

$C$DW$T$560	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$560, DW_AT_type(*$C$DW$T$564)
	.dwattr $C$DW$T$560, DW_AT_address_class(0x20)

$C$DW$T$563	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$563, DW_AT_type(*$C$DW$T$560)
	.dwattr $C$DW$T$563, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1226	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1226, DW_AT_type(*$C$DW$T$562)
	.dwendtag $C$DW$T$563

$C$DW$T$561	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$561, DW_AT_type(*$C$DW$T$564)
$C$DW$T$562	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$562, DW_AT_type(*$C$DW$T$561)
	.dwattr $C$DW$T$562, DW_AT_address_class(0x20)

$C$DW$T$569	.dwtag  DW_TAG_union_type
	.dwattr $C$DW$T$569, DW_AT_name("net_igmp")
	.dwattr $C$DW$T$569, DW_AT_byte_size(0x08)
$C$DW$1227	.dwtag  DW_TAG_member
	.dwattr $C$DW$1227, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$1227, DW_AT_name("type")
	.dwattr $C$DW$1227, DW_AT_TI_symbol_name("_type")
	.dwattr $C$DW$1227, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1227, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1228	.dwtag  DW_TAG_member
	.dwattr $C$DW$1228, DW_AT_type(*$C$DW$T$564)
	.dwattr $C$DW$1228, DW_AT_name("v2")
	.dwattr $C$DW$1228, DW_AT_TI_symbol_name("_v2")
	.dwattr $C$DW$1228, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1228, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$160	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$160, DW_AT_declaration
	.dwattr $C$DW$160, DW_AT_TI_symbol_name("___as__8net_igmpFRC8net_igmp")
	.dwattr $C$DW$160, DW_AT_type(*$C$DW$T$565)
	.dwattr $C$DW$160, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1229	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1229, DW_AT_type(*$C$DW$T$567)
	.dwendtag $C$DW$160

	.dwendtag $C$DW$T$569

$C$DW$T$565	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$565, DW_AT_type(*$C$DW$T$569)
	.dwattr $C$DW$T$565, DW_AT_address_class(0x20)

$C$DW$T$568	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$568, DW_AT_type(*$C$DW$T$565)
	.dwattr $C$DW$T$568, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1230	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1230, DW_AT_type(*$C$DW$T$567)
	.dwendtag $C$DW$T$568

$C$DW$T$566	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$566, DW_AT_type(*$C$DW$T$569)
$C$DW$T$567	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$567, DW_AT_type(*$C$DW$T$566)
	.dwattr $C$DW$T$567, DW_AT_address_class(0x20)
$C$DW$T$598	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$598, DW_AT_type(*$C$DW$T$569)
	.dwattr $C$DW$T$598, DW_AT_address_class(0x20)

$C$DW$T$575	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$575, DW_AT_name("net_snap")
	.dwattr $C$DW$T$575, DW_AT_byte_size(0x08)
$C$DW$1231	.dwtag  DW_TAG_member
	.dwattr $C$DW$1231, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$1231, DW_AT_name("dsap")
	.dwattr $C$DW$1231, DW_AT_TI_symbol_name("_dsap")
	.dwattr $C$DW$1231, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1231, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1232	.dwtag  DW_TAG_member
	.dwattr $C$DW$1232, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$1232, DW_AT_name("ssap")
	.dwattr $C$DW$1232, DW_AT_TI_symbol_name("_ssap")
	.dwattr $C$DW$1232, DW_AT_data_member_location[DW_OP_plus_uconst 0x1]
	.dwattr $C$DW$1232, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1233	.dwtag  DW_TAG_member
	.dwattr $C$DW$1233, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$1233, DW_AT_name("ctrl")
	.dwattr $C$DW$1233, DW_AT_TI_symbol_name("_ctrl")
	.dwattr $C$DW$1233, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr $C$DW$1233, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1234	.dwtag  DW_TAG_member
	.dwattr $C$DW$1234, DW_AT_type(*$C$DW$T$570)
	.dwattr $C$DW$1234, DW_AT_name("out_id")
	.dwattr $C$DW$1234, DW_AT_TI_symbol_name("_out_id")
	.dwattr $C$DW$1234, DW_AT_data_member_location[DW_OP_plus_uconst 0x3]
	.dwattr $C$DW$1234, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1235	.dwtag  DW_TAG_member
	.dwattr $C$DW$1235, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1235, DW_AT_name("h_proto")
	.dwattr $C$DW$1235, DW_AT_TI_symbol_name("_h_proto")
	.dwattr $C$DW$1235, DW_AT_data_member_location[DW_OP_plus_uconst 0x6]
	.dwattr $C$DW$1235, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$161	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$161, DW_AT_declaration
	.dwattr $C$DW$161, DW_AT_TI_symbol_name("___as__8net_snapFRC8net_snap")
	.dwattr $C$DW$161, DW_AT_type(*$C$DW$T$571)
	.dwattr $C$DW$161, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1236	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1236, DW_AT_type(*$C$DW$T$573)
	.dwendtag $C$DW$161

	.dwendtag $C$DW$T$575

$C$DW$T$571	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$571, DW_AT_type(*$C$DW$T$575)
	.dwattr $C$DW$T$571, DW_AT_address_class(0x20)

$C$DW$T$574	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$574, DW_AT_type(*$C$DW$T$571)
	.dwattr $C$DW$T$574, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1237	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1237, DW_AT_type(*$C$DW$T$573)
	.dwendtag $C$DW$T$574

$C$DW$T$572	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$572, DW_AT_type(*$C$DW$T$575)
$C$DW$T$573	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$573, DW_AT_type(*$C$DW$T$572)
	.dwattr $C$DW$T$573, DW_AT_address_class(0x20)
$C$DW$T$604	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$604, DW_AT_type(*$C$DW$T$575)
	.dwattr $C$DW$T$604, DW_AT_address_class(0x20)

$C$DW$T$580	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$580, DW_AT_name("net_8021q")
	.dwattr $C$DW$T$580, DW_AT_byte_size(0x04)
$C$DW$1238	.dwtag  DW_TAG_member
	.dwattr $C$DW$1238, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1238, DW_AT_name("flags")
	.dwattr $C$DW$1238, DW_AT_TI_symbol_name("_flags")
	.dwattr $C$DW$1238, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1238, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1239	.dwtag  DW_TAG_member
	.dwattr $C$DW$1239, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1239, DW_AT_name("h_proto")
	.dwattr $C$DW$1239, DW_AT_TI_symbol_name("_h_proto")
	.dwattr $C$DW$1239, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr $C$DW$1239, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$162	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$162, DW_AT_declaration
	.dwattr $C$DW$162, DW_AT_TI_symbol_name("___as__9net_8021qFRC9net_8021q")
	.dwattr $C$DW$162, DW_AT_type(*$C$DW$T$576)
	.dwattr $C$DW$162, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1240	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1240, DW_AT_type(*$C$DW$T$578)
	.dwendtag $C$DW$162

	.dwendtag $C$DW$T$580

$C$DW$T$576	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$576, DW_AT_type(*$C$DW$T$580)
	.dwattr $C$DW$T$576, DW_AT_address_class(0x20)

$C$DW$T$579	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$579, DW_AT_type(*$C$DW$T$576)
	.dwattr $C$DW$T$579, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1241	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1241, DW_AT_type(*$C$DW$T$578)
	.dwendtag $C$DW$T$579

$C$DW$T$577	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$577, DW_AT_type(*$C$DW$T$580)
$C$DW$T$578	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$578, DW_AT_type(*$C$DW$T$577)
	.dwattr $C$DW$T$578, DW_AT_address_class(0x20)

$C$DW$T$587	.dwtag  DW_TAG_union_type
	.dwattr $C$DW$T$587, DW_AT_byte_size(0x04)
$C$DW$1242	.dwtag  DW_TAG_member
	.dwattr $C$DW$1242, DW_AT_type(*$C$DW$T$581)
	.dwattr $C$DW$1242, DW_AT_name("channel_p")
	.dwattr $C$DW$1242, DW_AT_TI_symbol_name("_channel_p")
	.dwattr $C$DW$1242, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1242, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1243	.dwtag  DW_TAG_member
	.dwattr $C$DW$1243, DW_AT_type(*$C$DW$T$582)
	.dwattr $C$DW$1243, DW_AT_name("eth")
	.dwattr $C$DW$1243, DW_AT_TI_symbol_name("_eth")
	.dwattr $C$DW$1243, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1243, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$163	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$163, DW_AT_declaration
	.dwattr $C$DW$163, DW_AT_TI_symbol_name("___as__Q2_10net_packet4__C1FRCQ2_10net_packet4__C1")
	.dwattr $C$DW$163, DW_AT_type(*$C$DW$T$583)
	.dwattr $C$DW$163, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1244	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1244, DW_AT_type(*$C$DW$T$585)
	.dwendtag $C$DW$163

	.dwendtag $C$DW$T$587

$C$DW$T$583	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$583, DW_AT_type(*$C$DW$T$587)
	.dwattr $C$DW$T$583, DW_AT_address_class(0x20)

$C$DW$T$586	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$586, DW_AT_type(*$C$DW$T$583)
	.dwattr $C$DW$T$586, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1245	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1245, DW_AT_type(*$C$DW$T$585)
	.dwendtag $C$DW$T$586

$C$DW$T$584	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$584, DW_AT_type(*$C$DW$T$587)
$C$DW$T$585	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$585, DW_AT_type(*$C$DW$T$584)
	.dwattr $C$DW$T$585, DW_AT_address_class(0x20)

$C$DW$T$594	.dwtag  DW_TAG_union_type
	.dwattr $C$DW$T$594, DW_AT_byte_size(0x04)
$C$DW$1246	.dwtag  DW_TAG_member
	.dwattr $C$DW$1246, DW_AT_type(*$C$DW$T$581)
	.dwattr $C$DW$1246, DW_AT_name("net_p")
	.dwattr $C$DW$1246, DW_AT_TI_symbol_name("_net_p")
	.dwattr $C$DW$1246, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1246, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1247	.dwtag  DW_TAG_member
	.dwattr $C$DW$1247, DW_AT_type(*$C$DW$T$588)
	.dwattr $C$DW$1247, DW_AT_name("ip")
	.dwattr $C$DW$1247, DW_AT_TI_symbol_name("_ip")
	.dwattr $C$DW$1247, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1247, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1248	.dwtag  DW_TAG_member
	.dwattr $C$DW$1248, DW_AT_type(*$C$DW$T$589)
	.dwattr $C$DW$1248, DW_AT_name("arp")
	.dwattr $C$DW$1248, DW_AT_TI_symbol_name("_arp")
	.dwattr $C$DW$1248, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1248, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$164	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$164, DW_AT_declaration
	.dwattr $C$DW$164, DW_AT_TI_symbol_name("___as__Q2_10net_packet4__C2FRCQ2_10net_packet4__C2")
	.dwattr $C$DW$164, DW_AT_type(*$C$DW$T$590)
	.dwattr $C$DW$164, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1249	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1249, DW_AT_type(*$C$DW$T$592)
	.dwendtag $C$DW$164

	.dwendtag $C$DW$T$594

$C$DW$T$590	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$590, DW_AT_type(*$C$DW$T$594)
	.dwattr $C$DW$T$590, DW_AT_address_class(0x20)

$C$DW$T$593	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$593, DW_AT_type(*$C$DW$T$590)
	.dwattr $C$DW$T$593, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1250	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1250, DW_AT_type(*$C$DW$T$592)
	.dwendtag $C$DW$T$593

$C$DW$T$591	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$591, DW_AT_type(*$C$DW$T$594)
$C$DW$T$592	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$592, DW_AT_type(*$C$DW$T$591)
	.dwattr $C$DW$T$592, DW_AT_address_class(0x20)

$C$DW$T$603	.dwtag  DW_TAG_union_type
	.dwattr $C$DW$T$603, DW_AT_byte_size(0x04)
$C$DW$1251	.dwtag  DW_TAG_member
	.dwattr $C$DW$1251, DW_AT_type(*$C$DW$T$581)
	.dwattr $C$DW$1251, DW_AT_name("transp_p")
	.dwattr $C$DW$1251, DW_AT_TI_symbol_name("_transp_p")
	.dwattr $C$DW$1251, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1251, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1252	.dwtag  DW_TAG_member
	.dwattr $C$DW$1252, DW_AT_type(*$C$DW$T$595)
	.dwattr $C$DW$1252, DW_AT_name("tcp")
	.dwattr $C$DW$1252, DW_AT_TI_symbol_name("_tcp")
	.dwattr $C$DW$1252, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1252, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1253	.dwtag  DW_TAG_member
	.dwattr $C$DW$1253, DW_AT_type(*$C$DW$T$596)
	.dwattr $C$DW$1253, DW_AT_name("udp")
	.dwattr $C$DW$1253, DW_AT_TI_symbol_name("_udp")
	.dwattr $C$DW$1253, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1253, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1254	.dwtag  DW_TAG_member
	.dwattr $C$DW$1254, DW_AT_type(*$C$DW$T$597)
	.dwattr $C$DW$1254, DW_AT_name("icmp")
	.dwattr $C$DW$1254, DW_AT_TI_symbol_name("_icmp")
	.dwattr $C$DW$1254, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1254, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1255	.dwtag  DW_TAG_member
	.dwattr $C$DW$1255, DW_AT_type(*$C$DW$T$598)
	.dwattr $C$DW$1255, DW_AT_name("igmp")
	.dwattr $C$DW$1255, DW_AT_TI_symbol_name("_igmp")
	.dwattr $C$DW$1255, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1255, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$165	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$165, DW_AT_declaration
	.dwattr $C$DW$165, DW_AT_TI_symbol_name("___as__Q2_10net_packet4__C3FRCQ2_10net_packet4__C3")
	.dwattr $C$DW$165, DW_AT_type(*$C$DW$T$599)
	.dwattr $C$DW$165, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1256	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1256, DW_AT_type(*$C$DW$T$601)
	.dwendtag $C$DW$165

	.dwendtag $C$DW$T$603

$C$DW$T$599	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$599, DW_AT_type(*$C$DW$T$603)
	.dwattr $C$DW$T$599, DW_AT_address_class(0x20)

$C$DW$T$602	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$602, DW_AT_type(*$C$DW$T$599)
	.dwattr $C$DW$T$602, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1257	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1257, DW_AT_type(*$C$DW$T$601)
	.dwendtag $C$DW$T$602

$C$DW$T$600	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$600, DW_AT_type(*$C$DW$T$603)
$C$DW$T$601	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$601, DW_AT_type(*$C$DW$T$600)
	.dwattr $C$DW$T$601, DW_AT_address_class(0x20)

$C$DW$T$609	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$609, DW_AT_name("net_packet")
	.dwattr $C$DW$T$609, DW_AT_byte_size(0x1c)
$C$DW$1258	.dwtag  DW_TAG_member
	.dwattr $C$DW$1258, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1258, DW_AT_name("net_p_type")
	.dwattr $C$DW$1258, DW_AT_TI_symbol_name("_net_p_type")
	.dwattr $C$DW$1258, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1258, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1259	.dwtag  DW_TAG_member
	.dwattr $C$DW$1259, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1259, DW_AT_name("transp_p_type")
	.dwattr $C$DW$1259, DW_AT_TI_symbol_name("_transp_p_type")
	.dwattr $C$DW$1259, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr $C$DW$1259, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1260	.dwtag  DW_TAG_member
	.dwattr $C$DW$1260, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1260, DW_AT_name("protocol")
	.dwattr $C$DW$1260, DW_AT_TI_symbol_name("_protocol")
	.dwattr $C$DW$1260, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1260, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1261	.dwtag  DW_TAG_member
	.dwattr $C$DW$1261, DW_AT_type(*$C$DW$T$587)
	.dwattr $C$DW$1261, DW_AT_name("$P$T2")
	.dwattr $C$DW$1261, DW_AT_TI_symbol_name("_$P$T2")
	.dwattr $C$DW$1261, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1261, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1262	.dwtag  DW_TAG_member
	.dwattr $C$DW$1262, DW_AT_type(*$C$DW$T$594)
	.dwattr $C$DW$1262, DW_AT_name("$P$T3")
	.dwattr $C$DW$1262, DW_AT_TI_symbol_name("_$P$T3")
	.dwattr $C$DW$1262, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$1262, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1263	.dwtag  DW_TAG_member
	.dwattr $C$DW$1263, DW_AT_type(*$C$DW$T$603)
	.dwattr $C$DW$1263, DW_AT_name("$P$T4")
	.dwattr $C$DW$1263, DW_AT_TI_symbol_name("_$P$T4")
	.dwattr $C$DW$1263, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$1263, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1264	.dwtag  DW_TAG_member
	.dwattr $C$DW$1264, DW_AT_type(*$C$DW$T$604)
	.dwattr $C$DW$1264, DW_AT_name("snap")
	.dwattr $C$DW$1264, DW_AT_TI_symbol_name("_snap")
	.dwattr $C$DW$1264, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$1264, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1265	.dwtag  DW_TAG_member
	.dwattr $C$DW$1265, DW_AT_type(*$C$DW$T$581)
	.dwattr $C$DW$1265, DW_AT_name("uplevel_p")
	.dwattr $C$DW$1265, DW_AT_TI_symbol_name("_uplevel_p")
	.dwattr $C$DW$1265, DW_AT_data_member_location[DW_OP_plus_uconst 0x18]
	.dwattr $C$DW$1265, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$166	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$166, DW_AT_declaration
	.dwattr $C$DW$166, DW_AT_TI_symbol_name("___as__10net_packetFRC10net_packet")
	.dwattr $C$DW$166, DW_AT_type(*$C$DW$T$605)
	.dwattr $C$DW$166, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1266	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1266, DW_AT_type(*$C$DW$T$607)
	.dwendtag $C$DW$166

	.dwendtag $C$DW$T$609

$C$DW$T$605	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$605, DW_AT_type(*$C$DW$T$609)
	.dwattr $C$DW$T$605, DW_AT_address_class(0x20)

$C$DW$T$608	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$608, DW_AT_type(*$C$DW$T$605)
	.dwattr $C$DW$T$608, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1267	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1267, DW_AT_type(*$C$DW$T$607)
	.dwendtag $C$DW$T$608

$C$DW$T$606	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$606, DW_AT_type(*$C$DW$T$609)
$C$DW$T$607	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$607, DW_AT_type(*$C$DW$T$606)
	.dwattr $C$DW$T$607, DW_AT_address_class(0x20)

$C$DW$T$614	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$614, DW_AT_name("net_config")
	.dwattr $C$DW$T$614, DW_AT_byte_size(0x18)
$C$DW$1268	.dwtag  DW_TAG_member
	.dwattr $C$DW$1268, DW_AT_type(*$C$DW$T$504)
	.dwattr $C$DW$1268, DW_AT_name("mac")
	.dwattr $C$DW$1268, DW_AT_TI_symbol_name("_mac")
	.dwattr $C$DW$1268, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1268, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1269	.dwtag  DW_TAG_member
	.dwattr $C$DW$1269, DW_AT_type(*$C$DW$T$28)
	.dwattr $C$DW$1269, DW_AT_name("flags")
	.dwattr $C$DW$1269, DW_AT_TI_symbol_name("_flags")
	.dwattr $C$DW$1269, DW_AT_data_member_location[DW_OP_plus_uconst 0x6]
	.dwattr $C$DW$1269, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1270	.dwtag  DW_TAG_member
	.dwattr $C$DW$1270, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1270, DW_AT_name("ip4")
	.dwattr $C$DW$1270, DW_AT_TI_symbol_name("_ip4")
	.dwattr $C$DW$1270, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1270, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1271	.dwtag  DW_TAG_member
	.dwattr $C$DW$1271, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1271, DW_AT_name("mask4")
	.dwattr $C$DW$1271, DW_AT_TI_symbol_name("_mask4")
	.dwattr $C$DW$1271, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$1271, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1272	.dwtag  DW_TAG_member
	.dwattr $C$DW$1272, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1272, DW_AT_name("gateway4")
	.dwattr $C$DW$1272, DW_AT_TI_symbol_name("_gateway4")
	.dwattr $C$DW$1272, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$1272, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1273	.dwtag  DW_TAG_member
	.dwattr $C$DW$1273, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1273, DW_AT_name("mtu")
	.dwattr $C$DW$1273, DW_AT_TI_symbol_name("_mtu")
	.dwattr $C$DW$1273, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$1273, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$167	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$167, DW_AT_declaration
	.dwattr $C$DW$167, DW_AT_TI_symbol_name("___as__10net_configFRC10net_config")
	.dwattr $C$DW$167, DW_AT_type(*$C$DW$T$610)
	.dwattr $C$DW$167, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1274	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1274, DW_AT_type(*$C$DW$T$612)
	.dwendtag $C$DW$167

	.dwendtag $C$DW$T$614

$C$DW$T$610	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$610, DW_AT_type(*$C$DW$T$614)
	.dwattr $C$DW$T$610, DW_AT_address_class(0x20)

$C$DW$T$613	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$613, DW_AT_type(*$C$DW$T$610)
	.dwattr $C$DW$T$613, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1275	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1275, DW_AT_type(*$C$DW$T$612)
	.dwendtag $C$DW$T$613

$C$DW$T$611	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$611, DW_AT_type(*$C$DW$T$614)
$C$DW$T$612	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$612, DW_AT_type(*$C$DW$T$611)
	.dwattr $C$DW$T$612, DW_AT_address_class(0x20)

$C$DW$T$620	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$620, DW_AT_name("net_descriptor")
	.dwattr $C$DW$T$620, DW_AT_byte_size(0x38)
$C$DW$1276	.dwtag  DW_TAG_member
	.dwattr $C$DW$1276, DW_AT_type(*$C$DW$T$615)
	.dwattr $C$DW$1276, DW_AT_name("prev")
	.dwattr $C$DW$1276, DW_AT_TI_symbol_name("_prev")
	.dwattr $C$DW$1276, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1276, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1277	.dwtag  DW_TAG_member
	.dwattr $C$DW$1277, DW_AT_type(*$C$DW$T$615)
	.dwattr $C$DW$1277, DW_AT_name("next")
	.dwattr $C$DW$1277, DW_AT_TI_symbol_name("_next")
	.dwattr $C$DW$1277, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1277, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1278	.dwtag  DW_TAG_member
	.dwattr $C$DW$1278, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1278, DW_AT_name("size")
	.dwattr $C$DW$1278, DW_AT_TI_symbol_name("_size")
	.dwattr $C$DW$1278, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1278, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1279	.dwtag  DW_TAG_member
	.dwattr $C$DW$1279, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1279, DW_AT_name("length")
	.dwattr $C$DW$1279, DW_AT_TI_symbol_name("_length")
	.dwattr $C$DW$1279, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$1279, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1280	.dwtag  DW_TAG_member
	.dwattr $C$DW$1280, DW_AT_type(*$C$DW$T$581)
	.dwattr $C$DW$1280, DW_AT_name("data")
	.dwattr $C$DW$1280, DW_AT_TI_symbol_name("_data")
	.dwattr $C$DW$1280, DW_AT_data_member_location[DW_OP_plus_uconst 0x10]
	.dwattr $C$DW$1280, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1281	.dwtag  DW_TAG_member
	.dwattr $C$DW$1281, DW_AT_type(*$C$DW$T$609)
	.dwattr $C$DW$1281, DW_AT_name("pkt")
	.dwattr $C$DW$1281, DW_AT_TI_symbol_name("_pkt")
	.dwattr $C$DW$1281, DW_AT_data_member_location[DW_OP_plus_uconst 0x14]
	.dwattr $C$DW$1281, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1282	.dwtag  DW_TAG_member
	.dwattr $C$DW$1282, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$1282, DW_AT_name("dev_desc")
	.dwattr $C$DW$1282, DW_AT_TI_symbol_name("_dev_desc")
	.dwattr $C$DW$1282, DW_AT_data_member_location[DW_OP_plus_uconst 0x30]
	.dwattr $C$DW$1282, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1283	.dwtag  DW_TAG_member
	.dwattr $C$DW$1283, DW_AT_type(*$C$DW$T$3)
	.dwattr $C$DW$1283, DW_AT_name("usr_desc")
	.dwattr $C$DW$1283, DW_AT_TI_symbol_name("_usr_desc")
	.dwattr $C$DW$1283, DW_AT_data_member_location[DW_OP_plus_uconst 0x34]
	.dwattr $C$DW$1283, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$168	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$168, DW_AT_declaration
	.dwattr $C$DW$168, DW_AT_TI_symbol_name("___as__14net_descriptorFRC14net_descriptor")
	.dwattr $C$DW$168, DW_AT_type(*$C$DW$T$616)
	.dwattr $C$DW$168, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1284	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1284, DW_AT_type(*$C$DW$T$618)
	.dwendtag $C$DW$168

	.dwendtag $C$DW$T$620

$C$DW$T$615	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$615, DW_AT_type(*$C$DW$T$620)
	.dwattr $C$DW$T$615, DW_AT_address_class(0x20)
$C$DW$T$616	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$616, DW_AT_type(*$C$DW$T$620)
	.dwattr $C$DW$T$616, DW_AT_address_class(0x20)

$C$DW$T$619	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$619, DW_AT_type(*$C$DW$T$616)
	.dwattr $C$DW$T$619, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1285	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1285, DW_AT_type(*$C$DW$T$618)
	.dwendtag $C$DW$T$619

$C$DW$T$617	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$617, DW_AT_type(*$C$DW$T$620)
$C$DW$T$618	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$618, DW_AT_type(*$C$DW$T$617)
	.dwattr $C$DW$T$618, DW_AT_address_class(0x20)

$C$DW$T$625	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$625, DW_AT_name("net_send")
	.dwattr $C$DW$T$625, DW_AT_byte_size(0x08)
$C$DW$1286	.dwtag  DW_TAG_member
	.dwattr $C$DW$1286, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1286, DW_AT_name("length")
	.dwattr $C$DW$1286, DW_AT_TI_symbol_name("_length")
	.dwattr $C$DW$1286, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1286, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1287	.dwtag  DW_TAG_member
	.dwattr $C$DW$1287, DW_AT_type(*$C$DW$T$581)
	.dwattr $C$DW$1287, DW_AT_name("data")
	.dwattr $C$DW$1287, DW_AT_TI_symbol_name("_data")
	.dwattr $C$DW$1287, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1287, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$169	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$169, DW_AT_declaration
	.dwattr $C$DW$169, DW_AT_TI_symbol_name("___as__8net_sendFRC8net_send")
	.dwattr $C$DW$169, DW_AT_type(*$C$DW$T$621)
	.dwattr $C$DW$169, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1288	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1288, DW_AT_type(*$C$DW$T$623)
	.dwendtag $C$DW$169

	.dwendtag $C$DW$T$625

$C$DW$T$621	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$621, DW_AT_type(*$C$DW$T$625)
	.dwattr $C$DW$T$621, DW_AT_address_class(0x20)

$C$DW$T$624	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$624, DW_AT_type(*$C$DW$T$621)
	.dwattr $C$DW$T$624, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1289	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1289, DW_AT_type(*$C$DW$T$623)
	.dwendtag $C$DW$T$624

$C$DW$T$622	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$622, DW_AT_type(*$C$DW$T$625)
$C$DW$T$623	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$623, DW_AT_type(*$C$DW$T$622)
	.dwattr $C$DW$T$623, DW_AT_address_class(0x20)

$C$DW$T$630	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$630, DW_AT_name("dev_reg")
	.dwattr $C$DW$T$630, DW_AT_byte_size(0x0c)
$C$DW$1290	.dwtag  DW_TAG_member
	.dwattr $C$DW$1290, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1290, DW_AT_name("device")
	.dwattr $C$DW$1290, DW_AT_TI_symbol_name("_device")
	.dwattr $C$DW$1290, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1290, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1291	.dwtag  DW_TAG_member
	.dwattr $C$DW$1291, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1291, DW_AT_name("reg")
	.dwattr $C$DW$1291, DW_AT_TI_symbol_name("_reg")
	.dwattr $C$DW$1291, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1291, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1292	.dwtag  DW_TAG_member
	.dwattr $C$DW$1292, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1292, DW_AT_name("value")
	.dwattr $C$DW$1292, DW_AT_TI_symbol_name("_value")
	.dwattr $C$DW$1292, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1292, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$170	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$170, DW_AT_declaration
	.dwattr $C$DW$170, DW_AT_TI_symbol_name("___as__7dev_regFRC7dev_reg")
	.dwattr $C$DW$170, DW_AT_type(*$C$DW$T$626)
	.dwattr $C$DW$170, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1293	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1293, DW_AT_type(*$C$DW$T$628)
	.dwendtag $C$DW$170

	.dwendtag $C$DW$T$630

$C$DW$T$626	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$626, DW_AT_type(*$C$DW$T$630)
	.dwattr $C$DW$T$626, DW_AT_address_class(0x20)

$C$DW$T$629	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$629, DW_AT_type(*$C$DW$T$626)
	.dwattr $C$DW$T$629, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1294	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1294, DW_AT_type(*$C$DW$T$628)
	.dwendtag $C$DW$T$629

$C$DW$T$627	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$627, DW_AT_type(*$C$DW$T$630)
$C$DW$T$628	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$628, DW_AT_type(*$C$DW$T$627)
	.dwattr $C$DW$T$628, DW_AT_address_class(0x20)

$C$DW$T$635	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$635, DW_AT_name("new_queue")
	.dwattr $C$DW$T$635, DW_AT_byte_size(0x08)
$C$DW$1295	.dwtag  DW_TAG_member
	.dwattr $C$DW$1295, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1295, DW_AT_name("rx_count")
	.dwattr $C$DW$1295, DW_AT_TI_symbol_name("_rx_count")
	.dwattr $C$DW$1295, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1295, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1296	.dwtag  DW_TAG_member
	.dwattr $C$DW$1296, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1296, DW_AT_name("tx_count")
	.dwattr $C$DW$1296, DW_AT_TI_symbol_name("_tx_count")
	.dwattr $C$DW$1296, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1296, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$171	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$171, DW_AT_declaration
	.dwattr $C$DW$171, DW_AT_TI_symbol_name("___as__9new_queueFRC9new_queue")
	.dwattr $C$DW$171, DW_AT_type(*$C$DW$T$631)
	.dwattr $C$DW$171, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1297	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1297, DW_AT_type(*$C$DW$T$633)
	.dwendtag $C$DW$171

	.dwendtag $C$DW$T$635

$C$DW$T$631	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$631, DW_AT_type(*$C$DW$T$635)
	.dwattr $C$DW$T$631, DW_AT_address_class(0x20)

$C$DW$T$634	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$634, DW_AT_type(*$C$DW$T$631)
	.dwattr $C$DW$T$634, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1298	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1298, DW_AT_type(*$C$DW$T$633)
	.dwendtag $C$DW$T$634

$C$DW$T$632	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$632, DW_AT_type(*$C$DW$T$635)
$C$DW$T$633	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$633, DW_AT_type(*$C$DW$T$632)
	.dwattr $C$DW$T$633, DW_AT_address_class(0x20)

$C$DW$T$641	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$641, DW_AT_name("_EMAC_Desc")
	.dwattr $C$DW$T$641, DW_AT_byte_size(0x10)
$C$DW$1299	.dwtag  DW_TAG_member
	.dwattr $C$DW$1299, DW_AT_type(*$C$DW$T$636)
	.dwattr $C$DW$1299, DW_AT_name("pNext")
	.dwattr $C$DW$1299, DW_AT_TI_symbol_name("_pNext")
	.dwattr $C$DW$1299, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$1299, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1300	.dwtag  DW_TAG_member
	.dwattr $C$DW$1300, DW_AT_type(*$C$DW$T$581)
	.dwattr $C$DW$1300, DW_AT_name("pBuffer")
	.dwattr $C$DW$1300, DW_AT_TI_symbol_name("_pBuffer")
	.dwattr $C$DW$1300, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$1300, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1301	.dwtag  DW_TAG_member
	.dwattr $C$DW$1301, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1301, DW_AT_name("BufOffLen")
	.dwattr $C$DW$1301, DW_AT_TI_symbol_name("_BufOffLen")
	.dwattr $C$DW$1301, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$1301, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1302	.dwtag  DW_TAG_member
	.dwattr $C$DW$1302, DW_AT_type(*$C$DW$T$47)
	.dwattr $C$DW$1302, DW_AT_name("PktFlgLen")
	.dwattr $C$DW$1302, DW_AT_TI_symbol_name("_PktFlgLen")
	.dwattr $C$DW$1302, DW_AT_data_member_location[DW_OP_plus_uconst 0xc]
	.dwattr $C$DW$1302, DW_AT_accessibility(DW_ACCESS_public)

$C$DW$172	.dwtag  DW_TAG_subprogram, DW_AT_name("operator =")
	.dwattr $C$DW$172, DW_AT_declaration
	.dwattr $C$DW$172, DW_AT_TI_symbol_name("___as__10_EMAC_DescFRC10_EMAC_Desc")
	.dwattr $C$DW$172, DW_AT_type(*$C$DW$T$637)
	.dwattr $C$DW$172, DW_AT_accessibility(DW_ACCESS_public)
$C$DW$1303	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1303, DW_AT_type(*$C$DW$T$639)
	.dwendtag $C$DW$172

	.dwendtag $C$DW$T$641

$C$DW$T$636	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$636, DW_AT_type(*$C$DW$T$641)
	.dwattr $C$DW$T$636, DW_AT_address_class(0x20)
$C$DW$T$637	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$637, DW_AT_type(*$C$DW$T$641)
	.dwattr $C$DW$T$637, DW_AT_address_class(0x20)

$C$DW$T$640	.dwtag  DW_TAG_subroutine_type
	.dwattr $C$DW$T$640, DW_AT_type(*$C$DW$T$637)
	.dwattr $C$DW$T$640, DW_AT_language(DW_LANG_C_plus_plus)
$C$DW$1304	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$1304, DW_AT_type(*$C$DW$T$639)
	.dwendtag $C$DW$T$640

$C$DW$T$638	.dwtag  DW_TAG_const_type
	.dwattr $C$DW$T$638, DW_AT_type(*$C$DW$T$641)
$C$DW$T$639	.dwtag  DW_TAG_reference_type
	.dwattr $C$DW$T$639, DW_AT_type(*$C$DW$T$638)
	.dwattr $C$DW$T$639, DW_AT_address_class(0x20)
$C$DW$T$743	.dwtag  DW_TAG_typedef, DW_AT_name("EMAC_Desc")
	.dwattr $C$DW$T$743, DW_AT_type(*$C$DW$T$641)
	.dwattr $C$DW$T$743, DW_AT_language(DW_LANG_C_plus_plus)

$C$DW$T$727	.dwtag  DW_TAG_enumeration_type
	.dwattr $C$DW$T$727, DW_AT_name("Error")
	.dwattr $C$DW$T$727, DW_AT_byte_size(0x04)
$C$DW$1305	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_OK"), DW_AT_const_value(0x00)
$C$DW$1306	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NO_MEMORY"), DW_AT_const_value(-1)
$C$DW$1307	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NO_DEVICE"), DW_AT_const_value(-2)
$C$DW$1308	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_BAD_RDESC"), DW_AT_const_value(-3)
$C$DW$1309	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_BAD_PARAM"), DW_AT_const_value(-4)
$C$DW$1310	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NULL_PARAM"), DW_AT_const_value(-5)
$C$DW$1311	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_CANT_OPEN"), DW_AT_const_value(-6)
$C$DW$1312	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_CANT_READ"), DW_AT_const_value(-7)
$C$DW$1313	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_CANT_WRITE"), DW_AT_const_value(-8)
$C$DW$1314	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_CANT_CREATE_HEAP"), DW_AT_const_value(-9)
$C$DW$1315	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_CANT_CREATE_STACK"), DW_AT_const_value(-10)
$C$DW$1316	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_MSG_ALLREADY_STARTED"), DW_AT_const_value(-11)
$C$DW$1317	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_LIF_BAD_HEADER"), DW_AT_const_value(-12)
$C$DW$1318	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_LIF_WRONG_TARGET_CPU"), DW_AT_const_value(-13)
$C$DW$1319	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_LIF_BAD_SECTION_HEADER"), DW_AT_const_value(-14)
$C$DW$1320	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_LIF_CANT_APPLY_PATCH"), DW_AT_const_value(-15)
$C$DW$1321	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_TOO_LONG_STRING"), DW_AT_const_value(-16)
$C$DW$1322	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_ALLREADY_NAMED"), DW_AT_const_value(-17)
$C$DW$1323	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_TOO_SHORT_BUFFER"), DW_AT_const_value(-18)
$C$DW$1324	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_FAIL"), DW_AT_const_value(-19)
$C$DW$1325	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_CANT_CREATE_SEM"), DW_AT_const_value(-20)
$C$DW$1326	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_MSG_STREAM_NOT_OPENED"), DW_AT_const_value(-21)
$C$DW$1327	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_MSG_BAD_DST_ADDRESS"), DW_AT_const_value(-22)
$C$DW$1328	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_VOID_RESOURCE"), DW_AT_const_value(-23)
$C$DW$1329	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_SEM_DESTROYED"), DW_AT_const_value(-24)
$C$DW$1330	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_SEM_NOT_REGISTERED"), DW_AT_const_value(-25)
$C$DW$1331	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_TIMEOUT"), DW_AT_const_value(-26)
$C$DW$1332	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_SEM_LOCKED"), DW_AT_const_value(-27)
$C$DW$1333	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_SEM_UNLOCKED"), DW_AT_const_value(-28)
$C$DW$1334	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NO_EXTENSION"), DW_AT_const_value(-29)
$C$DW$1335	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_EXTENSION_PLUGGED"), DW_AT_const_value(-30)
$C$DW$1336	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_EXTENSION_BAD_HEADER"), DW_AT_const_value(-31)
$C$DW$1337	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_EXTENSION_F_PLUGGED"), DW_AT_const_value(-32)
$C$DW$1338	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_CANT_CREATE_PROCESS"), DW_AT_const_value(-33)
$C$DW$1339	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_BAD_DCTX"), DW_AT_const_value(-34)
$C$DW$1340	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_PERMISSION_DENIED"), DW_AT_const_value(-35)
$C$DW$1341	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_BAD_DATA"), DW_AT_const_value(-36)
$C$DW$1342	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_ALREADY_PLUGGED"), DW_AT_const_value(-37)
$C$DW$1343	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_CANT_CREATE_INTERRUPT"), DW_AT_const_value(-38)
$C$DW$1344	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_SIDE_TEST_ERROR"), DW_AT_const_value(-39)
$C$DW$1345	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_DATA_TEST_ERROR"), DW_AT_const_value(-40)
$C$DW$1346	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_ADDRESS_TEST_ERROR"), DW_AT_const_value(-41)
$C$DW$1347	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_TOO_MANY_DATA"), DW_AT_const_value(-42)
$C$DW$1348	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_DIFFERENT_LENGTH"), DW_AT_const_value(-43)
$C$DW$1349	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_DATA_ALIGNED"), DW_AT_const_value(-44)
$C$DW$1350	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_CANT_LOCK_SEM"), DW_AT_const_value(-45)
$C$DW$1351	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NO_ELEMENT"), DW_AT_const_value(-46)
$C$DW$1352	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_BAD_CMD"), DW_AT_const_value(-47)
$C$DW$1353	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NO_NODE"), DW_AT_const_value(-48)
$C$DW$1354	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_CANT_RESET_PARAM"), DW_AT_const_value(-49)
$C$DW$1355	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NO_PROCESS"), DW_AT_const_value(-50)
$C$DW$1356	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_BAD_RESOURCE_TYPE"), DW_AT_const_value(-51)
$C$DW$1357	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_ALREADY_ADDED"), DW_AT_const_value(-52)
$C$DW$1358	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NO_ROUTE"), DW_AT_const_value(-53)
$C$DW$1359	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_SYN_FAIL"), DW_AT_const_value(-54)
$C$DW$1360	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NOT_ENOUGHT_DATA"), DW_AT_const_value(-55)
$C$DW$1361	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_ALLREADY_SET"), DW_AT_const_value(-56)
$C$DW$1362	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_DROPPED"), DW_AT_const_value(-57)
$C$DW$1363	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_STREAM_OPENED"), DW_AT_const_value(-58)
$C$DW$1364	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_STREAM_NOT_OPENED"), DW_AT_const_value(-59)
$C$DW$1365	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NOT_INITIALIZED"), DW_AT_const_value(-60)
$C$DW$1366	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_TOO_BIG_PROCESS_ID"), DW_AT_const_value(-61)
$C$DW$1367	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_BAD_ACTION"), DW_AT_const_value(-62)
$C$DW$1368	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_OUT_OF_A_RANGE"), DW_AT_const_value(-63)
$C$DW$1369	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_SYN_TIMEOUT"), DW_AT_const_value(-64)
$C$DW$1370	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_DRIVER_UNLOADED"), DW_AT_const_value(-65)
$C$DW$1371	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NO_DRIVER"), DW_AT_const_value(-66)
$C$DW$1372	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NODE_EXISTS"), DW_AT_const_value(-67)
$C$DW$1373	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_LOOPBACK_PHY"), DW_AT_const_value(-68)
$C$DW$1374	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_WRONG_QUEUE_SIZE"), DW_AT_const_value(-69)
$C$DW$1375	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_RTC_WRITE"), DW_AT_const_value(-70)
$C$DW$1376	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_RTC_READ"), DW_AT_const_value(-71)
$C$DW$1377	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_RTC_TEST"), DW_AT_const_value(-72)
$C$DW$1378	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_RTC_TICK"), DW_AT_const_value(-73)
$C$DW$1379	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NO_PHY"), DW_AT_const_value(-74)
$C$DW$1380	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_PHY_ERROR"), DW_AT_const_value(-75)
$C$DW$1381	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_LINK_TEST"), DW_AT_const_value(-76)
$C$DW$1382	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NAME_EXISTS"), DW_AT_const_value(-77)
$C$DW$1383	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_BAD_NAME"), DW_AT_const_value(-78)
$C$DW$1384	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_RESOURCE_BUSY"), DW_AT_const_value(-79)
$C$DW$1385	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_RESOURCE_POOL_BUSY"), DW_AT_const_value(-80)
$C$DW$1386	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_RESOURCE_LIMIT_REACHED"), DW_AT_const_value(-81)
$C$DW$1387	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_BAD_RESOURCE_INDEX"), DW_AT_const_value(-82)
$C$DW$1388	.dwtag  DW_TAG_enumerator, DW_AT_name("OSE_NO_DATA"), DW_AT_const_value(-83)
	.dwendtag $C$DW$T$727


$C$DW$T$729	.dwtag  DW_TAG_enumeration_type
	.dwattr $C$DW$T$729, DW_AT_name("an_error_code")
	.dwattr $C$DW$T$729, DW_AT_byte_size(0x04)
$C$DW$1389	.dwtag  DW_TAG_enumerator, DW_AT_name("ec_none"), DW_AT_const_value(0x00)
$C$DW$1390	.dwtag  DW_TAG_enumerator, DW_AT_name("ec_abort_header"), DW_AT_const_value(0x01)
$C$DW$1391	.dwtag  DW_TAG_enumerator, DW_AT_name("ec_terminate_called"), DW_AT_const_value(0x02)
$C$DW$1392	.dwtag  DW_TAG_enumerator, DW_AT_name("ec_terminate_returned"), DW_AT_const_value(0x03)
$C$DW$1393	.dwtag  DW_TAG_enumerator, DW_AT_name("ec_already_marked_for_destruction"), DW_AT_const_value(0x04)
$C$DW$1394	.dwtag  DW_TAG_enumerator, DW_AT_name("ec_main_called_more_than_once"), DW_AT_const_value(0x05)
$C$DW$1395	.dwtag  DW_TAG_enumerator, DW_AT_name("ec_pure_virtual_called"), DW_AT_const_value(0x06)
$C$DW$1396	.dwtag  DW_TAG_enumerator, DW_AT_name("ec_bad_cast"), DW_AT_const_value(0x07)
$C$DW$1397	.dwtag  DW_TAG_enumerator, DW_AT_name("ec_bad_typeid"), DW_AT_const_value(0x08)
$C$DW$1398	.dwtag  DW_TAG_enumerator, DW_AT_name("ec_array_not_from_vec_new"), DW_AT_const_value(0x09)
$C$DW$1399	.dwtag  DW_TAG_enumerator, DW_AT_name("ec_last"), DW_AT_const_value(0x0a)
	.dwendtag $C$DW$T$729


$C$DW$T$730	.dwtag  DW_TAG_enumeration_type
	.dwattr $C$DW$T$730, DW_AT_byte_size(0x04)
$C$DW$1400	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_IP"), DW_AT_const_value(0x00)
$C$DW$1401	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_ICMP"), DW_AT_const_value(0x01)
$C$DW$1402	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_IGMP"), DW_AT_const_value(0x02)
$C$DW$1403	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_IPIP"), DW_AT_const_value(0x04)
$C$DW$1404	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_TCP"), DW_AT_const_value(0x06)
$C$DW$1405	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_EGP"), DW_AT_const_value(0x08)
$C$DW$1406	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_PUP"), DW_AT_const_value(0x0c)
$C$DW$1407	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_UDP"), DW_AT_const_value(0x11)
$C$DW$1408	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_IDP"), DW_AT_const_value(0x16)
$C$DW$1409	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_DCCP"), DW_AT_const_value(0x21)
$C$DW$1410	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_RSVP"), DW_AT_const_value(0x2e)
$C$DW$1411	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_GRE"), DW_AT_const_value(0x2f)
$C$DW$1412	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_IPV6"), DW_AT_const_value(0x29)
$C$DW$1413	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_ESP"), DW_AT_const_value(0x32)
$C$DW$1414	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_AH"), DW_AT_const_value(0x33)
$C$DW$1415	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_BEETPH"), DW_AT_const_value(0x5e)
$C$DW$1416	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_PIM"), DW_AT_const_value(0x67)
$C$DW$1417	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_COMP"), DW_AT_const_value(0x6c)
$C$DW$1418	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_SCTP"), DW_AT_const_value(0x84)
$C$DW$1419	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_UDPLITE"), DW_AT_const_value(0x88)
$C$DW$1420	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_RAW"), DW_AT_const_value(0xff)
$C$DW$1421	.dwtag  DW_TAG_enumerator, DW_AT_name("IPPROTO_MAX"), DW_AT_const_value(0x100)
	.dwendtag $C$DW$T$730


$C$DW$T$731	.dwtag  DW_TAG_enumeration_type
	.dwattr $C$DW$T$731, DW_AT_name("sock_type")
	.dwattr $C$DW$T$731, DW_AT_byte_size(0x04)
$C$DW$1422	.dwtag  DW_TAG_enumerator, DW_AT_name("SOCK_STREAM"), DW_AT_const_value(0x01)
$C$DW$1423	.dwtag  DW_TAG_enumerator, DW_AT_name("SOCK_DGRAM"), DW_AT_const_value(0x02)
$C$DW$1424	.dwtag  DW_TAG_enumerator, DW_AT_name("SOCK_RAW"), DW_AT_const_value(0x03)
$C$DW$1425	.dwtag  DW_TAG_enumerator, DW_AT_name("SOCK_RDM"), DW_AT_const_value(0x04)
$C$DW$1426	.dwtag  DW_TAG_enumerator, DW_AT_name("SOCK_SEQPACKET"), DW_AT_const_value(0x05)
$C$DW$1427	.dwtag  DW_TAG_enumerator, DW_AT_name("SOCK_DCCP"), DW_AT_const_value(0x06)
$C$DW$1428	.dwtag  DW_TAG_enumerator, DW_AT_name("SOCK_PACKET"), DW_AT_const_value(0x0a)
	.dwendtag $C$DW$T$731


$C$DW$T$732	.dwtag  DW_TAG_enumeration_type
	.dwattr $C$DW$T$732, DW_AT_byte_size(0x04)
$C$DW$1429	.dwtag  DW_TAG_enumerator, DW_AT_name("START"), DW_AT_const_value(0xd0000)
$C$DW$1430	.dwtag  DW_TAG_enumerator, DW_AT_name("START_SIALP"), DW_AT_const_value(0xd0001)
$C$DW$1431	.dwtag  DW_TAG_enumerator, DW_AT_name("START_CIKL"), DW_AT_const_value(0xd0002)
$C$DW$1432	.dwtag  DW_TAG_enumerator, DW_AT_name("GOTOV_PP"), DW_AT_const_value(0xd0003)
$C$DW$1433	.dwtag  DW_TAG_enumerator, DW_AT_name("STOP_CIKL"), DW_AT_const_value(0xd0004)
$C$DW$1434	.dwtag  DW_TAG_enumerator, DW_AT_name("N_TEST"), DW_AT_const_value(0xd0005)
$C$DW$1435	.dwtag  DW_TAG_enumerator, DW_AT_name("GOTOV_TEST"), DW_AT_const_value(0xd0006)
$C$DW$1436	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_NOT_READY"), DW_AT_const_value(0xd0007)
$C$DW$1437	.dwtag  DW_TAG_enumerator, DW_AT_name("RES_N_TEST"), DW_AT_const_value(0xd0008)
$C$DW$1438	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_SDRAM_FULL"), DW_AT_const_value(0xd0009)
$C$DW$1439	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_NVRAM_FULL"), DW_AT_const_value(0xd000a)
$C$DW$1440	.dwtag  DW_TAG_enumerator, DW_AT_name("START_TEST_DOZU_NAGR"), DW_AT_const_value(0xd000b)
$C$DW$1441	.dwtag  DW_TAG_enumerator, DW_AT_name("RES_TEST_DOZU_NAGR"), DW_AT_const_value(0xd000c)
$C$DW$1442	.dwtag  DW_TAG_enumerator, DW_AT_name("STOP_TEST_DOZU_NAGR"), DW_AT_const_value(0xd000d)
$C$DW$1443	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_CR_SERVISE"), DW_AT_const_value(0xd000e)
$C$DW$1444	.dwtag  DW_TAG_enumerator, DW_AT_name("START_TEST_ROM"), DW_AT_const_value(0xd000f)
$C$DW$1445	.dwtag  DW_TAG_enumerator, DW_AT_name("RES_TEST_ROM_CP0"), DW_AT_const_value(0xd0010)
$C$DW$1446	.dwtag  DW_TAG_enumerator, DW_AT_name("RES_TEST_ROM_CP1"), DW_AT_const_value(0xd0011)
$C$DW$1447	.dwtag  DW_TAG_enumerator, DW_AT_name("STOP_TEST_ROM"), DW_AT_const_value(0xd0012)
$C$DW$1448	.dwtag  DW_TAG_enumerator, DW_AT_name("START_TEST_CR_CH"), DW_AT_const_value(0xd0013)
$C$DW$1449	.dwtag  DW_TAG_enumerator, DW_AT_name("RES_TEST_CR_CH"), DW_AT_const_value(0xd0014)
$C$DW$1450	.dwtag  DW_TAG_enumerator, DW_AT_name("STOP_TEST_CR_CH"), DW_AT_const_value(0xd0015)
$C$DW$1451	.dwtag  DW_TAG_enumerator, DW_AT_name("CLEAR_TEST_PACKET"), DW_AT_const_value(0xd0016)
$C$DW$1452	.dwtag  DW_TAG_enumerator, DW_AT_name("RECV_TEST_PACKET"), DW_AT_const_value(0xd0017)
$C$DW$1453	.dwtag  DW_TAG_enumerator, DW_AT_name("SEND_TEST_PACKET"), DW_AT_const_value(0xd0018)
$C$DW$1454	.dwtag  DW_TAG_enumerator, DW_AT_name("START_TEST_MOVE"), DW_AT_const_value(0xd0019)
$C$DW$1455	.dwtag  DW_TAG_enumerator, DW_AT_name("GOTOV_TEST_MOVE_15"), DW_AT_const_value(0xd001a)
$C$DW$1456	.dwtag  DW_TAG_enumerator, DW_AT_name("GOTOV_TEST_MOVE_1A"), DW_AT_const_value(0xd001b)
$C$DW$1457	.dwtag  DW_TAG_enumerator, DW_AT_name("GOTOV_TEST_MOVE_25"), DW_AT_const_value(0xd001c)
$C$DW$1458	.dwtag  DW_TAG_enumerator, DW_AT_name("GOTOV_TEST_MOVE_2A"), DW_AT_const_value(0xd001d)
$C$DW$1459	.dwtag  DW_TAG_enumerator, DW_AT_name("RES_TEST_MOVE"), DW_AT_const_value(0xd001e)
$C$DW$1460	.dwtag  DW_TAG_enumerator, DW_AT_name("STOP_TEST_MOVE"), DW_AT_const_value(0xd001f)
$C$DW$1461	.dwtag  DW_TAG_enumerator, DW_AT_name("GET_RES_FROM_DOZU"), DW_AT_const_value(0xd0020)
$C$DW$1462	.dwtag  DW_TAG_enumerator, DW_AT_name("INF_ABOUT_USB"), DW_AT_const_value(0xd0021)
$C$DW$1463	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_IPMP"), DW_AT_const_value(0xd0022)
$C$DW$1464	.dwtag  DW_TAG_enumerator, DW_AT_name("ASK_CMD"), DW_AT_const_value(0xd0023)
$C$DW$1465	.dwtag  DW_TAG_enumerator, DW_AT_name("OPEN_SV_MSG"), DW_AT_const_value(0xd0024)
$C$DW$1466	.dwtag  DW_TAG_enumerator, DW_AT_name("CLOSE_SV_MSG"), DW_AT_const_value(0xd0025)
$C$DW$1467	.dwtag  DW_TAG_enumerator, DW_AT_name("ERROR_CMD"), DW_AT_const_value(0xd0026)
$C$DW$1468	.dwtag  DW_TAG_enumerator, DW_AT_name("STOP_TX"), DW_AT_const_value(0xd0027)
$C$DW$1469	.dwtag  DW_TAG_enumerator, DW_AT_name("EXIT_TPO"), DW_AT_const_value(0xd0028)
$C$DW$1470	.dwtag  DW_TAG_enumerator, DW_AT_name("LOAD_LIF"), DW_AT_const_value(0xd0029)
$C$DW$1471	.dwtag  DW_TAG_enumerator, DW_AT_name("START_LIF"), DW_AT_const_value(0xd002a)
$C$DW$1472	.dwtag  DW_TAG_enumerator, DW_AT_name("START_LOAD_PO"), DW_AT_const_value(0xd002b)
$C$DW$1473	.dwtag  DW_TAG_enumerator, DW_AT_name("WRITE_PO_TO_FLASH"), DW_AT_const_value(0xd002c)
	.dwendtag $C$DW$T$732


$C$DW$T$733	.dwtag  DW_TAG_enumeration_type
	.dwattr $C$DW$T$733, DW_AT_byte_size(0x04)
$C$DW$1474	.dwtag  DW_TAG_enumerator, DW_AT_name("CELOSTN"), DW_AT_const_value(0x15)
$C$DW$1475	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_SDRAM"), DW_AT_const_value(0x1a)
$C$DW$1476	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_NVRAM"), DW_AT_const_value(0x1b)
$C$DW$1477	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_USB_CONTR"), DW_AT_const_value(0x1d)
$C$DW$1478	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_USB_FLASH"), DW_AT_const_value(0x1e)
$C$DW$1479	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_DOZU"), DW_AT_const_value(0x20)
$C$DW$1480	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_DOZU_ST1"), DW_AT_const_value(0x21)
$C$DW$1481	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_DOZU_ST2"), DW_AT_const_value(0x22)
$C$DW$1482	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_DOZU_ST3"), DW_AT_const_value(0x23)
$C$DW$1483	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_MOVE"), DW_AT_const_value(0x24)
$C$DW$1484	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_MOVE_ST1"), DW_AT_const_value(0x25)
$C$DW$1485	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_MOVE_ST2"), DW_AT_const_value(0x26)
$C$DW$1486	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_MOVE_ST3"), DW_AT_const_value(0x27)
$C$DW$1487	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_SK"), DW_AT_const_value(0x28)
$C$DW$1488	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_SK1"), DW_AT_const_value(0x29)
$C$DW$1489	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_SK2"), DW_AT_const_value(0x2a)
$C$DW$1490	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_SK3"), DW_AT_const_value(0x2b)
$C$DW$1491	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_DNSD_CRC"), DW_AT_const_value(0x2c)
$C$DW$1492	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_DNSD_VD10"), DW_AT_const_value(0x2d)
$C$DW$1493	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_DNSD_VD11"), DW_AT_const_value(0x2e)
$C$DW$1494	.dwtag  DW_TAG_enumerator, DW_AT_name("ZAVESTI_DNSD"), DW_AT_const_value(0x2f)
$C$DW$1495	.dwtag  DW_TAG_enumerator, DW_AT_name("PROCHITAT"), DW_AT_const_value(0x30)
$C$DW$1496	.dwtag  DW_TAG_enumerator, DW_AT_name("VKL_VD10"), DW_AT_const_value(0x31)
$C$DW$1497	.dwtag  DW_TAG_enumerator, DW_AT_name("VKL_VD11"), DW_AT_const_value(0x32)
$C$DW$1498	.dwtag  DW_TAG_enumerator, DW_AT_name("VIKL_VD11"), DW_AT_const_value(0x33)
$C$DW$1499	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_DNSD_OSVESCH"), DW_AT_const_value(0x34)
$C$DW$1500	.dwtag  DW_TAG_enumerator, DW_AT_name("MAGIC_NUMBER"), DW_AT_const_value(0x35)
$C$DW$1501	.dwtag  DW_TAG_enumerator, DW_AT_name("CELOSTN_PP056"), DW_AT_const_value(0x36)
$C$DW$1502	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_CDROM"), DW_AT_const_value(0x37)
$C$DW$1503	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_RAID"), DW_AT_const_value(0x38)
$C$DW$1504	.dwtag  DW_TAG_enumerator, DW_AT_name("TEST_USB3"), DW_AT_const_value(0x39)
$C$DW$1505	.dwtag  DW_TAG_enumerator, DW_AT_name("CIKL"), DW_AT_const_value(0x64)
$C$DW$1506	.dwtag  DW_TAG_enumerator, DW_AT_name("CIKL_NOT_READY"), DW_AT_const_value(0x65)
	.dwendtag $C$DW$T$733


$C$DW$T$734	.dwtag  DW_TAG_enumeration_type
	.dwattr $C$DW$T$734, DW_AT_byte_size(0x04)
$C$DW$1507	.dwtag  DW_TAG_enumerator, DW_AT_name("MAIN_TIME_OUT"), DW_AT_const_value(0x00)
$C$DW$1508	.dwtag  DW_TAG_enumerator, DW_AT_name("COMM_TIME_OUT"), DW_AT_const_value(0x01)
$C$DW$1509	.dwtag  DW_TAG_enumerator, DW_AT_name("COMM1_TIME_OUT"), DW_AT_const_value(0x02)
$C$DW$1510	.dwtag  DW_TAG_enumerator, DW_AT_name("COMM2_TIME_OUT"), DW_AT_const_value(0x03)
$C$DW$1511	.dwtag  DW_TAG_enumerator, DW_AT_name("COMM3_TIME_OUT"), DW_AT_const_value(0x04)
$C$DW$1512	.dwtag  DW_TAG_enumerator, DW_AT_name("MAIN_ERR_MSG"), DW_AT_const_value(0x05)
$C$DW$1513	.dwtag  DW_TAG_enumerator, DW_AT_name("MAIN_ERR_MSG_CICL_RES"), DW_AT_const_value(0x06)
$C$DW$1514	.dwtag  DW_TAG_enumerator, DW_AT_name("COMM_ERR_MSG"), DW_AT_const_value(0x07)
$C$DW$1515	.dwtag  DW_TAG_enumerator, DW_AT_name("COMM1_ERR_MSG"), DW_AT_const_value(0x08)
$C$DW$1516	.dwtag  DW_TAG_enumerator, DW_AT_name("COMM2_ERR_MSG"), DW_AT_const_value(0x09)
$C$DW$1517	.dwtag  DW_TAG_enumerator, DW_AT_name("COMM3_ERR_MSG"), DW_AT_const_value(0x0a)
$C$DW$1518	.dwtag  DW_TAG_enumerator, DW_AT_name("DRV_ERR"), DW_AT_const_value(0x0b)
$C$DW$1519	.dwtag  DW_TAG_enumerator, DW_AT_name("ERR_MSG_OPEN"), DW_AT_const_value(0x0c)
$C$DW$1520	.dwtag  DW_TAG_enumerator, DW_AT_name("NO_MEM_COMM"), DW_AT_const_value(0x0d)
$C$DW$1521	.dwtag  DW_TAG_enumerator, DW_AT_name("NO_MEM_COMM1"), DW_AT_const_value(0x0e)
$C$DW$1522	.dwtag  DW_TAG_enumerator, DW_AT_name("NO_MEM_MAIN"), DW_AT_const_value(0x0f)
$C$DW$1523	.dwtag  DW_TAG_enumerator, DW_AT_name("NO_MEM_IFACE"), DW_AT_const_value(0x10)
	.dwendtag $C$DW$T$734


$C$DW$T$742	.dwtag  DW_TAG_enumeration_type
	.dwattr $C$DW$T$742, DW_AT_byte_size(0x04)
$C$DW$1524	.dwtag  DW_TAG_enumerator, DW_AT_name("RIK"), DW_AT_const_value(0x01)
$C$DW$1525	.dwtag  DW_TAG_enumerator, DW_AT_name("PP_PLIS"), DW_AT_const_value(0x02)
$C$DW$1526	.dwtag  DW_TAG_enumerator, DW_AT_name("MCBSP"), DW_AT_const_value(0x03)
$C$DW$1527	.dwtag  DW_TAG_enumerator, DW_AT_name("CP_EXT_RAM"), DW_AT_const_value(0x04)
$C$DW$1528	.dwtag  DW_TAG_enumerator, DW_AT_name("CP_INT_RAM1"), DW_AT_const_value(0x05)
$C$DW$1529	.dwtag  DW_TAG_enumerator, DW_AT_name("CP_INT_RAM2"), DW_AT_const_value(0x06)
$C$DW$1530	.dwtag  DW_TAG_enumerator, DW_AT_name("CP_INT_RAM3"), DW_AT_const_value(0x07)
$C$DW$1531	.dwtag  DW_TAG_enumerator, DW_AT_name("CP_PLIS"), DW_AT_const_value(0x08)
$C$DW$1532	.dwtag  DW_TAG_enumerator, DW_AT_name("CRYPTO"), DW_AT_const_value(0x09)
$C$DW$1533	.dwtag  DW_TAG_enumerator, DW_AT_name("ETHERNET"), DW_AT_const_value(0x0a)
$C$DW$1534	.dwtag  DW_TAG_enumerator, DW_AT_name("DISPLEY"), DW_AT_const_value(0x0b)
$C$DW$1535	.dwtag  DW_TAG_enumerator, DW_AT_name("RESET_PLIS"), DW_AT_const_value(0x0c)
$C$DW$1536	.dwtag  DW_TAG_enumerator, DW_AT_name("SP_PLIS"), DW_AT_const_value(0x0d)
$C$DW$1537	.dwtag  DW_TAG_enumerator, DW_AT_name("PLIS_SI"), DW_AT_const_value(0x0e)
$C$DW$1538	.dwtag  DW_TAG_enumerator, DW_AT_name("SATA_SI"), DW_AT_const_value(0x0f)
$C$DW$1539	.dwtag  DW_TAG_enumerator, DW_AT_name("USB3_SI"), DW_AT_const_value(0x10)
	.dwendtag $C$DW$T$742

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

$C$DW$1540	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A0")
	.dwattr $C$DW$1540, DW_AT_location[DW_OP_reg0]
$C$DW$1541	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A1")
	.dwattr $C$DW$1541, DW_AT_location[DW_OP_reg1]
$C$DW$1542	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A2")
	.dwattr $C$DW$1542, DW_AT_location[DW_OP_reg2]
$C$DW$1543	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A3")
	.dwattr $C$DW$1543, DW_AT_location[DW_OP_reg3]
$C$DW$1544	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A4")
	.dwattr $C$DW$1544, DW_AT_location[DW_OP_reg4]
$C$DW$1545	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A5")
	.dwattr $C$DW$1545, DW_AT_location[DW_OP_reg5]
$C$DW$1546	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A6")
	.dwattr $C$DW$1546, DW_AT_location[DW_OP_reg6]
$C$DW$1547	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A7")
	.dwattr $C$DW$1547, DW_AT_location[DW_OP_reg7]
$C$DW$1548	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A8")
	.dwattr $C$DW$1548, DW_AT_location[DW_OP_reg8]
$C$DW$1549	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A9")
	.dwattr $C$DW$1549, DW_AT_location[DW_OP_reg9]
$C$DW$1550	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A10")
	.dwattr $C$DW$1550, DW_AT_location[DW_OP_reg10]
$C$DW$1551	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A11")
	.dwattr $C$DW$1551, DW_AT_location[DW_OP_reg11]
$C$DW$1552	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A12")
	.dwattr $C$DW$1552, DW_AT_location[DW_OP_reg12]
$C$DW$1553	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A13")
	.dwattr $C$DW$1553, DW_AT_location[DW_OP_reg13]
$C$DW$1554	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A14")
	.dwattr $C$DW$1554, DW_AT_location[DW_OP_reg14]
$C$DW$1555	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A15")
	.dwattr $C$DW$1555, DW_AT_location[DW_OP_reg15]
$C$DW$1556	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B0")
	.dwattr $C$DW$1556, DW_AT_location[DW_OP_reg16]
$C$DW$1557	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B1")
	.dwattr $C$DW$1557, DW_AT_location[DW_OP_reg17]
$C$DW$1558	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B2")
	.dwattr $C$DW$1558, DW_AT_location[DW_OP_reg18]
$C$DW$1559	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B3")
	.dwattr $C$DW$1559, DW_AT_location[DW_OP_reg19]
$C$DW$1560	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B4")
	.dwattr $C$DW$1560, DW_AT_location[DW_OP_reg20]
$C$DW$1561	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B5")
	.dwattr $C$DW$1561, DW_AT_location[DW_OP_reg21]
$C$DW$1562	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B6")
	.dwattr $C$DW$1562, DW_AT_location[DW_OP_reg22]
$C$DW$1563	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B7")
	.dwattr $C$DW$1563, DW_AT_location[DW_OP_reg23]
$C$DW$1564	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B8")
	.dwattr $C$DW$1564, DW_AT_location[DW_OP_reg24]
$C$DW$1565	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B9")
	.dwattr $C$DW$1565, DW_AT_location[DW_OP_reg25]
$C$DW$1566	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B10")
	.dwattr $C$DW$1566, DW_AT_location[DW_OP_reg26]
$C$DW$1567	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B11")
	.dwattr $C$DW$1567, DW_AT_location[DW_OP_reg27]
$C$DW$1568	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B12")
	.dwattr $C$DW$1568, DW_AT_location[DW_OP_reg28]
$C$DW$1569	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B13")
	.dwattr $C$DW$1569, DW_AT_location[DW_OP_reg29]
$C$DW$1570	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("DP")
	.dwattr $C$DW$1570, DW_AT_location[DW_OP_reg30]
$C$DW$1571	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("SP")
	.dwattr $C$DW$1571, DW_AT_location[DW_OP_reg31]
$C$DW$1572	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("FP")
	.dwattr $C$DW$1572, DW_AT_location[DW_OP_regx 0x20]
$C$DW$1573	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("PC")
	.dwattr $C$DW$1573, DW_AT_location[DW_OP_regx 0x21]
$C$DW$1574	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("IRP")
	.dwattr $C$DW$1574, DW_AT_location[DW_OP_regx 0x22]
$C$DW$1575	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("IFR")
	.dwattr $C$DW$1575, DW_AT_location[DW_OP_regx 0x23]
$C$DW$1576	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("NRP")
	.dwattr $C$DW$1576, DW_AT_location[DW_OP_regx 0x24]
$C$DW$1577	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A16")
	.dwattr $C$DW$1577, DW_AT_location[DW_OP_regx 0x25]
$C$DW$1578	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A17")
	.dwattr $C$DW$1578, DW_AT_location[DW_OP_regx 0x26]
$C$DW$1579	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A18")
	.dwattr $C$DW$1579, DW_AT_location[DW_OP_regx 0x27]
$C$DW$1580	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A19")
	.dwattr $C$DW$1580, DW_AT_location[DW_OP_regx 0x28]
$C$DW$1581	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A20")
	.dwattr $C$DW$1581, DW_AT_location[DW_OP_regx 0x29]
$C$DW$1582	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A21")
	.dwattr $C$DW$1582, DW_AT_location[DW_OP_regx 0x2a]
$C$DW$1583	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A22")
	.dwattr $C$DW$1583, DW_AT_location[DW_OP_regx 0x2b]
$C$DW$1584	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A23")
	.dwattr $C$DW$1584, DW_AT_location[DW_OP_regx 0x2c]
$C$DW$1585	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A24")
	.dwattr $C$DW$1585, DW_AT_location[DW_OP_regx 0x2d]
$C$DW$1586	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A25")
	.dwattr $C$DW$1586, DW_AT_location[DW_OP_regx 0x2e]
$C$DW$1587	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A26")
	.dwattr $C$DW$1587, DW_AT_location[DW_OP_regx 0x2f]
$C$DW$1588	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A27")
	.dwattr $C$DW$1588, DW_AT_location[DW_OP_regx 0x30]
$C$DW$1589	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A28")
	.dwattr $C$DW$1589, DW_AT_location[DW_OP_regx 0x31]
$C$DW$1590	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A29")
	.dwattr $C$DW$1590, DW_AT_location[DW_OP_regx 0x32]
$C$DW$1591	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A30")
	.dwattr $C$DW$1591, DW_AT_location[DW_OP_regx 0x33]
$C$DW$1592	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("A31")
	.dwattr $C$DW$1592, DW_AT_location[DW_OP_regx 0x34]
$C$DW$1593	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B16")
	.dwattr $C$DW$1593, DW_AT_location[DW_OP_regx 0x35]
$C$DW$1594	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B17")
	.dwattr $C$DW$1594, DW_AT_location[DW_OP_regx 0x36]
$C$DW$1595	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B18")
	.dwattr $C$DW$1595, DW_AT_location[DW_OP_regx 0x37]
$C$DW$1596	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B19")
	.dwattr $C$DW$1596, DW_AT_location[DW_OP_regx 0x38]
$C$DW$1597	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B20")
	.dwattr $C$DW$1597, DW_AT_location[DW_OP_regx 0x39]
$C$DW$1598	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B21")
	.dwattr $C$DW$1598, DW_AT_location[DW_OP_regx 0x3a]
$C$DW$1599	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B22")
	.dwattr $C$DW$1599, DW_AT_location[DW_OP_regx 0x3b]
$C$DW$1600	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B23")
	.dwattr $C$DW$1600, DW_AT_location[DW_OP_regx 0x3c]
$C$DW$1601	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B24")
	.dwattr $C$DW$1601, DW_AT_location[DW_OP_regx 0x3d]
$C$DW$1602	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B25")
	.dwattr $C$DW$1602, DW_AT_location[DW_OP_regx 0x3e]
$C$DW$1603	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B26")
	.dwattr $C$DW$1603, DW_AT_location[DW_OP_regx 0x3f]
$C$DW$1604	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B27")
	.dwattr $C$DW$1604, DW_AT_location[DW_OP_regx 0x40]
$C$DW$1605	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B28")
	.dwattr $C$DW$1605, DW_AT_location[DW_OP_regx 0x41]
$C$DW$1606	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B29")
	.dwattr $C$DW$1606, DW_AT_location[DW_OP_regx 0x42]
$C$DW$1607	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B30")
	.dwattr $C$DW$1607, DW_AT_location[DW_OP_regx 0x43]
$C$DW$1608	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("B31")
	.dwattr $C$DW$1608, DW_AT_location[DW_OP_regx 0x44]
$C$DW$1609	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AMR")
	.dwattr $C$DW$1609, DW_AT_location[DW_OP_regx 0x45]
$C$DW$1610	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("CSR")
	.dwattr $C$DW$1610, DW_AT_location[DW_OP_regx 0x46]
$C$DW$1611	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ISR")
	.dwattr $C$DW$1611, DW_AT_location[DW_OP_regx 0x47]
$C$DW$1612	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ICR")
	.dwattr $C$DW$1612, DW_AT_location[DW_OP_regx 0x48]
$C$DW$1613	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("IER")
	.dwattr $C$DW$1613, DW_AT_location[DW_OP_regx 0x49]
$C$DW$1614	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ISTP")
	.dwattr $C$DW$1614, DW_AT_location[DW_OP_regx 0x4a]
$C$DW$1615	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("IN")
	.dwattr $C$DW$1615, DW_AT_location[DW_OP_regx 0x4b]
$C$DW$1616	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("OUT")
	.dwattr $C$DW$1616, DW_AT_location[DW_OP_regx 0x4c]
$C$DW$1617	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ACR")
	.dwattr $C$DW$1617, DW_AT_location[DW_OP_regx 0x4d]
$C$DW$1618	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ADR")
	.dwattr $C$DW$1618, DW_AT_location[DW_OP_regx 0x4e]
$C$DW$1619	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("FADCR")
	.dwattr $C$DW$1619, DW_AT_location[DW_OP_regx 0x4f]
$C$DW$1620	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("FAUCR")
	.dwattr $C$DW$1620, DW_AT_location[DW_OP_regx 0x50]
$C$DW$1621	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("FMCR")
	.dwattr $C$DW$1621, DW_AT_location[DW_OP_regx 0x51]
$C$DW$1622	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("GFPGFR")
	.dwattr $C$DW$1622, DW_AT_location[DW_OP_regx 0x52]
$C$DW$1623	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("DIER")
	.dwattr $C$DW$1623, DW_AT_location[DW_OP_regx 0x53]
$C$DW$1624	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("REP")
	.dwattr $C$DW$1624, DW_AT_location[DW_OP_regx 0x54]
$C$DW$1625	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("TSCL")
	.dwattr $C$DW$1625, DW_AT_location[DW_OP_regx 0x55]
$C$DW$1626	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("TSCH")
	.dwattr $C$DW$1626, DW_AT_location[DW_OP_regx 0x56]
$C$DW$1627	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ARP")
	.dwattr $C$DW$1627, DW_AT_location[DW_OP_regx 0x57]
$C$DW$1628	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ILC")
	.dwattr $C$DW$1628, DW_AT_location[DW_OP_regx 0x58]
$C$DW$1629	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("RILC")
	.dwattr $C$DW$1629, DW_AT_location[DW_OP_regx 0x59]
$C$DW$1630	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("DNUM")
	.dwattr $C$DW$1630, DW_AT_location[DW_OP_regx 0x5a]
$C$DW$1631	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("SSR")
	.dwattr $C$DW$1631, DW_AT_location[DW_OP_regx 0x5b]
$C$DW$1632	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("GPLYA")
	.dwattr $C$DW$1632, DW_AT_location[DW_OP_regx 0x5c]
$C$DW$1633	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("GPLYB")
	.dwattr $C$DW$1633, DW_AT_location[DW_OP_regx 0x5d]
$C$DW$1634	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("TSR")
	.dwattr $C$DW$1634, DW_AT_location[DW_OP_regx 0x5e]
$C$DW$1635	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ITSR")
	.dwattr $C$DW$1635, DW_AT_location[DW_OP_regx 0x5f]
$C$DW$1636	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("NTSR")
	.dwattr $C$DW$1636, DW_AT_location[DW_OP_regx 0x60]
$C$DW$1637	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("EFR")
	.dwattr $C$DW$1637, DW_AT_location[DW_OP_regx 0x61]
$C$DW$1638	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ECR")
	.dwattr $C$DW$1638, DW_AT_location[DW_OP_regx 0x62]
$C$DW$1639	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("IERR")
	.dwattr $C$DW$1639, DW_AT_location[DW_OP_regx 0x63]
$C$DW$1640	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("DMSG")
	.dwattr $C$DW$1640, DW_AT_location[DW_OP_regx 0x64]
$C$DW$1641	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("CMSG")
	.dwattr $C$DW$1641, DW_AT_location[DW_OP_regx 0x65]
$C$DW$1642	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("DT_DMA_ADDR")
	.dwattr $C$DW$1642, DW_AT_location[DW_OP_regx 0x66]
$C$DW$1643	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("DT_DMA_DATA")
	.dwattr $C$DW$1643, DW_AT_location[DW_OP_regx 0x67]
$C$DW$1644	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("DT_DMA_CNTL")
	.dwattr $C$DW$1644, DW_AT_location[DW_OP_regx 0x68]
$C$DW$1645	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("TCU_CNTL")
	.dwattr $C$DW$1645, DW_AT_location[DW_OP_regx 0x69]
$C$DW$1646	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("RTDX_REC_CNTL")
	.dwattr $C$DW$1646, DW_AT_location[DW_OP_regx 0x6a]
$C$DW$1647	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("RTDX_XMT_CNTL")
	.dwattr $C$DW$1647, DW_AT_location[DW_OP_regx 0x6b]
$C$DW$1648	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("RTDX_CFG")
	.dwattr $C$DW$1648, DW_AT_location[DW_OP_regx 0x6c]
$C$DW$1649	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("RTDX_RDATA")
	.dwattr $C$DW$1649, DW_AT_location[DW_OP_regx 0x6d]
$C$DW$1650	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("RTDX_WDATA")
	.dwattr $C$DW$1650, DW_AT_location[DW_OP_regx 0x6e]
$C$DW$1651	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("RTDX_RADDR")
	.dwattr $C$DW$1651, DW_AT_location[DW_OP_regx 0x6f]
$C$DW$1652	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("RTDX_WADDR")
	.dwattr $C$DW$1652, DW_AT_location[DW_OP_regx 0x70]
$C$DW$1653	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("MFREG0")
	.dwattr $C$DW$1653, DW_AT_location[DW_OP_regx 0x71]
$C$DW$1654	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("DBG_STAT")
	.dwattr $C$DW$1654, DW_AT_location[DW_OP_regx 0x72]
$C$DW$1655	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("BRK_EN")
	.dwattr $C$DW$1655, DW_AT_location[DW_OP_regx 0x73]
$C$DW$1656	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("HWBP0_CNT")
	.dwattr $C$DW$1656, DW_AT_location[DW_OP_regx 0x74]
$C$DW$1657	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("HWBP0")
	.dwattr $C$DW$1657, DW_AT_location[DW_OP_regx 0x75]
$C$DW$1658	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("HWBP1")
	.dwattr $C$DW$1658, DW_AT_location[DW_OP_regx 0x76]
$C$DW$1659	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("HWBP2")
	.dwattr $C$DW$1659, DW_AT_location[DW_OP_regx 0x77]
$C$DW$1660	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("HWBP3")
	.dwattr $C$DW$1660, DW_AT_location[DW_OP_regx 0x78]
$C$DW$1661	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("OVERLAY")
	.dwattr $C$DW$1661, DW_AT_location[DW_OP_regx 0x79]
$C$DW$1662	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("PC_PROF")
	.dwattr $C$DW$1662, DW_AT_location[DW_OP_regx 0x7a]
$C$DW$1663	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ATSR")
	.dwattr $C$DW$1663, DW_AT_location[DW_OP_regx 0x7b]
$C$DW$1664	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("TRR")
	.dwattr $C$DW$1664, DW_AT_location[DW_OP_regx 0x7c]
$C$DW$1665	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("TCRR")
	.dwattr $C$DW$1665, DW_AT_location[DW_OP_regx 0x7d]
$C$DW$1666	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("DESR")
	.dwattr $C$DW$1666, DW_AT_location[DW_OP_regx 0x7e]
$C$DW$1667	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("DETR")
	.dwattr $C$DW$1667, DW_AT_location[DW_OP_regx 0x7f]
$C$DW$1668	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("CIE_RETA")
	.dwattr $C$DW$1668, DW_AT_location[DW_OP_regx 0xe4]
	.dwendtag $C$DW$CU

