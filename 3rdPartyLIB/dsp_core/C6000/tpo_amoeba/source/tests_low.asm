	.text

    .global _number
    .global _test_addr1
    .global _test_addr2
    .global _test_addr3
    .global _test_addr4

    .def _asm_si_acc_ram
_asm_si_acc_ram:

		mvk  .l2 0, B0
		mvkl  .s2 _number, B1
		mvkh  .s2 _number, B1
		ldw	 .d2 *B1, A0
		nop
		nop
		nop
		nop
		nop
		stw  .d2 A0, *B0		
		b		.s2 B3
		nop
		nop
		nop
		nop
		nop
    .def _asm_si_ram_acc_ext
_asm_si_ram_acc_ext:


		mvkl		.S2 68000000h, B0
		mvkh		.s2 68000000h, B0
		mvkl		.S2 68000004h, B1
		mvkh		.s2 68000004h, B1
		ldw		.d2 *B0, A0	
		ldw		.d2 *B1, A0	
	
		b		.s2 B3

    .def _asm_si_ram_acc_int1
_asm_si_ram_acc_int1:


		mvkl		.S2 00000030h, B0
		mvkh		.s2 00000030h, B0
		mvkl		.S2 00000034h, B1
		mvkh		.s2 00000034h, B1
		ldw		.d2 *B0, A3	
		ldw		.d2 *B1, A3	
	
		b		.s2 B3
		nop
		nop
		nop


    .def _asm_si_ram_acc_int2
_asm_si_ram_acc_int2:


		mvkl		.S2 00000038h, B0
		mvkh		.s2 00000038h, B0
		mvkl		.S2 0000003Ch, B1
		mvkh		.s2 0000003Ch, B1
		ldw		.d2 *B0, A3	
		ldw		.d2 *B1, A3	
	
		b		.s2 B3
		nop
		nop
		nop
