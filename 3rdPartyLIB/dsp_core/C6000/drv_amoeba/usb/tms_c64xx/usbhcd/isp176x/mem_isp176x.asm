;******************************************************************************
; 				          Copyright (C) 2009 RCZI
;------------------------------------------------------------------------------
; FILENAME...... mem_isp176x.asm
; DATE CREATED.. 05/02/2009
;------------------------------------------------------------------------------
;	Описание РЕГИСТРОВ контроллера USB ISP176x
;------------------------------------------------------------------------------
;; !: arch: tms320c64xx
;; !: sarc: all
;;
;; !: codepage: cp1251 
;;
;; !: d: Содержит регистры драйвера ISP 1760/1761 Hi-Speed Universal Serial Bus 
;; !: d: host controller, описанные в не загружаемой секции данных ".isp176x_reg". Низкоуровневые функции доступа к памяти хост контроллера.
;; !: -:
;***sss************************************************************************
 		.asg      0,QDMA_ENABLE  
 		   
		.def      _hc_write_reg
		.def      _hc_read_reg 
		.def      _hc_write_mem
		.def      _hc_read_mem 
		.def      _number_completed_ptd

		.if		    QDMA_ENABLE = 1
		.ref      _QDMA_memcpy
		.endif

		.global		_reg_isp176x
		.global		_mem_isp176x
			;EHCI capability register
		.global		_REG_CAPLENGTH	 
		.global		_REG_HCIVERSION	 	 
		.global		_REG_HCSPARAMS 	 		 
		.global		_REG_HCCPARAMS	 
			;EHCI operational register	  
		.global		_REG_USBCMD	  	  
		.global		_REG_USBSTS	  		  
		.global		_REG_USBINTR   		  
		.global		_REG_FRINDEX
		.global		_REG_CTRLDSSEGMENT   		  		  
		.global		_REG_CONFIGFLAG		  
		.global		_REG_PORTSC1   		  		  
		.global		_REG_ISO_PTD_Done_Map				
		.global		_REG_ISO_PTD_Skip_Map				
		.global		_REG_ISO_PTD_Last_PTD				
		.global		_REG_INT_PTD_Done_Map				
		.global		_REG_INT_PTD_Skip_Map				
		.global		_REG_INT_PTD_Last_PTD				
		.global		_REG_ATL_PTD_Done_Map				
		.global		_REG_ATL_PTD_Skip_Map				
		.global		_REG_ATL_PTD_Last_PTD
			;Configuration register
		.global		_REG_HW_Mode_Control			   
		.global		_REG_Chip_ID 	   			   
		.global		_REG_Scratch 	   			   
		.global		_REG_SW_Reset	   
		.global		_REG_DMA_Configuration 						
		.global		_REG_Buffer_Status 					
		.global		_REG_ATL_Done_Timeout				
		.global		_REG_Memory 							
		.global		_REG_Edge_Interrupt_Count   				
		.global		_REG_DMA_Start_Address	  								
		.global		_REG_Power_Down_Control	  								
		.global		_REG_Port_1_Control
			;OTG Controller registers
		.global		_REG_VendorID 								
		.global		_REG_ProductID								
		.global		_REG_OTG_Control_set						
		.global		_REG_OTG_Control_clear						
		.global		_REG_OTG_Status 							
		.global		_REG_OTG_Interrupt_Latch_set				
		.global		_REG_OTG_Interrupt_Latch_clear				
		.global		_REG_OTG_Interrupt_Enable_Fall_set		
		.global		_REG_OTG_Interrupt_Enable_Fall_clear	
		.global		_REG_OTG_Interrupt_Enable_Rise_set		
		.global		_REG_OTG_Interrupt_Enable_Rise_clear	
		.global		_REG_OTG_Timer_Lower_word_set			
		.global		_REG_OTG_Timer_Lower_word_clear			
		.global		_REG_OTG_Timer_Higher_word_set			
		.global		_REG_Timer_Higher_word_clear		  	  
			;Interrupt registers				
		.global		_REG_Interrupt 						
		.global		_REG_Interrupt_Enable				
		.global		_REG_ISO_IRQ_Mask_OR 				
		.global		_REG_INT_IRQ_Mask_OR 				
		.global		_REG_ATL_IRQ_Mask_OR 				
		.global		_REG_ISO_IRQ_Mask_AND				
		.global		_REG_INT_IRQ_Mask_AND				
		.global		_REG_ATL_IRQ_Mask_AND

		.if		ISP176_BUS_32=1
USB_MEM_SHIFT	.set  1
divisor       .set  1
		.elseif ISP176_BUS_32=0
USB_MEM_SHIFT	.set  0
divisor       .set  2
    .else
              .emsg   "ERROR: ISP176_BUS_32 неверно определен"
USB_MEM_SHIFT .set  0
divisor       .set  2
    .endif

		.sect	".isp176x_reg"
;----------	EHCI capability register ------------	
_REG_CAPLENGTH			.byte	0
_REG_HCIVERSION			.half	0
				.align	0x08	/divisor
_REG_HCSPARAMS 			.word	0
				.align	0x08	/divisor
_REG_HCCPARAMS			.word	0
;----------	EHCI operational register -----------	
				.align	0x40	/divisor
_REG_USBCMD				.word	0
				.align	0x08	/divisor
_REG_USBSTS				.word	0
				.align	0x08	/divisor
_REG_USBINTR 			.word	0
				.align	0x08	/divisor
_REG_FRINDEX 			.word	0
				.align	0x08	/divisor
_REG_CTRLDSSEGMENT		.word	0
				.align	0x80	/divisor
				.space	0x40	/divisor
_REG_CONFIGFLAG			.word	0
				.align	0x08	/divisor
_REG_PORTSC1 			.word	0
				.align	0x200	/divisor
				.space	0x60	/divisor
_REG_ISO_PTD_Done_Map	.word	0
				.align	0x08	/divisor
_REG_ISO_PTD_Skip_Map 	.word	0
				.align	0x08	/divisor
_REG_ISO_PTD_Last_PTD 	.word	0 	
				.align	0x10	/divisor
_REG_INT_PTD_Done_Map 	.word	0 
				.align	0x08	/divisor
_REG_INT_PTD_Skip_Map 	.word	0 
				.align	0x08	/divisor
_REG_INT_PTD_Last_PTD  	.word	0
				.align	0x10	/divisor
_REG_ATL_PTD_Done_Map  	.word	0
				.align	0x08	/divisor
_REG_ATL_PTD_Skip_Map  	.word	0
				.align	0x08	/divisor
_REG_ATL_PTD_Last_PTD  	.word	0
;----------	Configuration register (begin...) ---
				.align	0x400	/divisor
				.space	0x200	/divisor
_REG_HW_Mode_Control 	.word	0
				.align	0x08	/divisor
_REG_Chip_ID 		  	.word	0
				.align	0x08	/divisor
_REG_Scratch 		  	.word	0
				.align	0x08	/divisor
_REG_SW_Reset		  	.word	0
;----------	Interrupt registers -----------------
				.align	0x08	/divisor
_REG_Interrupt 		  	.word	0
				.align	0x08	/divisor
_REG_Interrupt_Enable  	.word	0
				.align	0x08	/divisor
_REG_ISO_IRQ_Mask_OR   	.word	0
				.align	0x08	/divisor
_REG_INT_IRQ_Mask_OR   	.word	0
				.align	0x08	/divisor
_REG_ATL_IRQ_Mask_OR   	.word	0
				.align	0x08	/divisor
_REG_ISO_IRQ_Mask_AND  	.word	0
				.align	0x08	/divisor
_REG_INT_IRQ_Mask_AND  	.word	0
				.align	0x08	/divisor
_REG_ATL_IRQ_Mask_AND  	.word	0
;----------	Configuration register (...end) -----
				.align	0x08	/divisor
_REG_DMA_Configuration 	.word	0
				.align	0x08	/divisor
_REG_Buffer_Status 	  	.word	0
				.align	0x08	/divisor
_REG_ATL_Done_Timeout  	.word	0
				.align	0x08	/divisor
_REG_Memory 			.word	0
				.align	0x08	/divisor
_REG_Edge_Interrupt_Count.word	0
				.align	0x08	/divisor
_REG_DMA_Start_Address	.word	0
				.align	0x20	/divisor
				.space	0x08	/divisor
_REG_Power_Down_Control	.word	0
;----------	OTG Controller registers ------------
				.align	0x20				/divisor
				.space	0x20				/divisor
	;Device ID registers
_REG_VendorID 							.half	0
_REG_ProductID							.half	0
	;OTG Control register
				.align	0x08				/divisor
_REG_Port_1_Control
_REG_OTG_Control_set					.half	0
_REG_OTG_Control_clear					.half	0
	;OTG Interrupt registers
				.align	0x08				/divisor
_REG_OTG_Status 						.half	0
										.half	0
				.align	0x08				/divisor
_REG_OTG_Interrupt_Latch_set			.half	0
_REG_OTG_Interrupt_Latch_clear			.half	0
				.align	0x08				/divisor
_REG_OTG_Interrupt_Enable_Fall_set		.half	0
_REG_OTG_Interrupt_Enable_Fall_clear	.half	0
				.align	0x08				/divisor
_REG_OTG_Interrupt_Enable_Rise_set		.half	0
_REG_OTG_Interrupt_Enable_Rise_clear	.half	0
	;OTG Timer register
				.align	0x08				/divisor
_REG_OTG_Timer_Lower_word_set			.half	0
_REG_OTG_Timer_Lower_word_clear			.half	0
				.align	0x08				/divisor
_REG_OTG_Timer_Higher_word_set			.half	0
_REG_OTG_Timer_Higher_word_clear		.half	0

;----------	ISO,INT,ALT,Payload memory ----------
				.align	0x800				/divisor

;==================================================================================================
FP  .set    A15 ;Frame pointer  
DP  .set    B14 ;Data Page pointer  
SP  .set    B15 ;Stack pointer
SD  .set    A15
;--- Задержка в микросекундах ---
hcdelay		.macro		mks
			mvk			mks,A0
			shl			A0,7,A0
mcDeley?
	[A0]	bdec		mcDeley?,A0
			nop	5
	        .endm
;--- Возврат из процидуры ---
; used B3
ret         .macro      
            b       .s2 B3
            nop 5
            .endm
;--- Поместить в СТЕК ---
push        .macro
            stw .d2     FP,*SP--[0x2]
            stw .d2     DP,*SP--[0x2]
            stw .d2     B3,*SP--[0x2]
            .endm
;--- Взять из стека ---
pop         .macro
            ldw .d2     *++SP[0x2],B3
            ldw .d2     *++SP[0x2],DP
            ldw .d2     *++SP[0x2],FP
            nop 4
            .endm


			.sect	".text"
;**************************************************************************************************\
;       Установка регистра контроллера
; void    HostWriteReg_32Bit(void* isp_internal_address,int value);
;**************************************************************************************************/
_hc_write_reg:
			stw		B4,*A4++[0x0]
			ret
;**************************************************************************************************\
;       Чтение регистра контроллера
; int     HostReadReg_32Bit (void* isp_internal_address);
;**************************************************************************************************/
_hc_read_reg:
		;Note that the timing between the rising edge of WR_N 
		;and the falling edge of RD_N must be more than 36 ns.
		;Но даже 100 нс неработает!!!
			hcdelay		1
			ldw			*A4++[0x0],A4
			nop	4
			ret
;**************************************************************************************************
;		Запись буфера в память контроллера
;--------------------------------------------------------------------------------------------------
; void	HostWriteMem_32Bit(void* dst_usb, void* src_mem, int size_in_byte)
;**************************************************************************************************
_hc_write_mem:
			push
			.if			QDMA_ENABLE = 1
            cmpltu      A6,0x4,A0
      [ A0] bnop        mNoQDMATransfer,5
			mv			A4,A10
	||		mv			B4,B10
			mv			A6,A11

    ;=======================================================================
    ;                   A4          B4          A6          B6          A8
    ;QDMA_memcpy(uint32 opt, uint32 src, uint32 cnt, uint32 dst, uint32 idx)
	||		and			A6,~0x3,A6		;cnt
;           mv          B10,B4			;src
			mvk			0x8,A8			;idx
    ||      mv          A10,B6			;dst
            mvkl        0x01700001,A4	;opt
            mvkh        0x01700001,A4	;opt
			shru		A6,0x2,A6
			call		_QDMA_memcpy
            shl         A4,0x2,A0
			sub			A11,A0,A6
			mv			A10,A4
	||		mv			B10,B4
    		.if		    ISP176_BUS_32=1
            shl         A0,USB_MEM_SHIFT,A0
   			.endif
            add         A4,A0,A4
    ||      add         B4,A0,B4
mNoQDMATransfer:
			.endif
			and			A6,0x3,A0
	||		mv			A6,B0
			sub			B0,A0,B0
	||		and			B4,0x3,A1 ;проверка на выравневание адреса получателя
;--------------------------------------
; Подготовка:
;	А4,B4 - адреса	src_mem
;	А5,B5 - адреса	dst_usb
			mv			A4,B5
	||		mv			B4,A4
	||		add			B4,0x4,B4
			mv			B5,A5
	||		add			B5,(0x4<<USB_MEM_SHIFT),B5
	||		zero		B1
	  [!B0]	bnop		mCopyBytesW,5
	  [ A1]	bnop		mCopyNonAlignedWordsW,5
;======================================
; Пословное ВЫРАВНЕННОЕ копирование:
mCopyAlignedWordsW:
mcWriteNewAlignedWords:
			cmpeq		B0,4,B1			;if (B0 = 4) B1 = 1; else B1 = 0;
			ldw			*A4++[0x2],A7
	||[!B1]	ldw			*B4++[0x2],B7
			nop	4
			stw			A7,*A5++[0x2<<USB_MEM_SHIFT]
	||[!B1]	stw			B7,*B5++[0x2<<USB_MEM_SHIFT]
	  [!B1]	sub			B0,8,B0
	||[ B1] zero		B0
	  [ B0]	bnop		mcWriteNewAlignedWords,5
			bnop		mCopyBytesW,5		
;======================================
; Пословное НЕВЫРАВНЕННОЕ копирование:
mCopyNonAlignedWordsW:
mcWriteNewNonAlignedWords:
			cmpeq		B0,4,B1			;if (B0 = 4) B1 = 1; else B1 = 0;
			ldnw		*A4++[0x2],A7
	  [!B1]	ldnw		*B4++[0x2],B7
			nop	4
			stw			A7,*A5++[0x2<<USB_MEM_SHIFT]
	||[!B1]	stw			B7,*B5++[0x2<<USB_MEM_SHIFT]
	  [!B1]	sub			B0,8,B0
	||[ B1] zero		B0
	  [ B0]	bnop		mcWriteNewNonAlignedWords,5
;======================================
; Побайтное копирование:
mCopyBytesW:
	  [!A0]	bnop		mCopyEndW,5
	; Если В1 = 0 скопированно  четное  количество слов
	; Если В1 = 1 скопированно нечетное количество слов
	  [ B1]	mv			B4,A4
	  [ B1]	mv			B5,A5
			zero		A16
	||		zero		A17
	||		zero		A18
mcWriteNewBytes:
			ldbu		*A4++[0x1],A17
			nop	4
			shl			A17,A18,A17
			or			A16,A17,A16
			add			A18,8,A18
			sub			A0,1,A0
	  [ A0]	bnop		mcWriteNewBytes,5
			stw			A16,*A5++[0x0]
mCopyEndW:
			pop
			ret

;**************************************************************************************************
;		Чтение буфера из памяти контроллера
;--------------------------------------------------------------------------------------------------
; void	HostReadMem_32Bit(void* dst_mem, void* src_usb, int size_in_byte)
;**************************************************************************************************
_hc_read_mem:
			push
;======================================
; Memory = ((int)src_usb & ~_reg_isp176x)>>USB_MEM_SHIFT;
			mv			B4,B8
			mvkl		_reg_isp176x,B9
	||		mvkl		_REG_Memory,A8
			mvkh		_reg_isp176x,B9				
	||		mvkh		_REG_Memory,A8
			not			B9,B9
			and			B8,B9,B8
			shru		B8,USB_MEM_SHIFT,B8
			stw			B8,*A8++[0x0]
;======================================
; delay_mks(100);
			hcdelay		1
;======================================
			and			A6,0x3,A0
	||		mv			A6,B0
			sub			B0,A0,B0
	||		and			A4,0x3,A1 ;проверка на выравневание адреса получателя
;--------------------------------------
; Подготовка:
;	А4,B4 - адреса	src_mem
;	А5,B5 - адреса	dst_usb
			mv			A4,B5
	||		mv			B4,A4
	||		add			B4,0x4<<USB_MEM_SHIFT,B4
			mv			B5,A5
	||		add			B5,0x4,B5
	||		zero		B1
	  [!B0]	bnop		mCopyBytesR,5
	  [ A1]	bnop		mCopyNonAlignedWordsR,5
;======================================
; Пословное ВЫРАВНЕННОЕ копирование:
mCopyAlignedWordsR:
mcReadNewAlignedWords:
			cmpeq		B0,4,B1			;if (B0 = 4) B1 = 1; else B1 = 0;
			ldw			*A4++[0x2<<USB_MEM_SHIFT],A7
	||[!B1]	ldw			*B4++[0x2<<USB_MEM_SHIFT],B7
			nop	4
			stw			A7,*A5++[0x2]
	||[!B1]	stw			B7,*B5++[0x2]
	  [!B1]	sub			B0,8,B0
	||[ B1] zero		B0
	  [ B0]	bnop		mcReadNewAlignedWords,5
			bnop		mCopyBytesR,5		
;======================================
; Пословное НЕВЫРАВНЕННОЕ копирование:
mCopyNonAlignedWordsR:
mcReadNewNonAlignedWords:
			cmpeq		B0,4,B1			;if (B0 = 4) B1 = 1; else B1 = 0;
			ldw			*A4++[0x2<<USB_MEM_SHIFT],A7
	||[!B1]	ldw			*B4++[0x2<<USB_MEM_SHIFT],B7
			nop	4
			stnw		A7,*A5++[0x2]
	  [!B1]	stnw		B7,*B5++[0x2]
	  [!B1]	sub			B0,8,B0
	||[ B1] zero		B0
	  [ B0]	bnop		mcReadNewNonAlignedWords,5
;======================================
; Побайтное копирование:
mCopyBytesR:
	  [!A0]	bnop		mCopyEndR,5
	; Если В1 = 0 скопированно  четное  количество слов
	; Если В1 = 1 скопированно нечетное количество слов
	  [ B1]	mv			B4,A4
	  [ B1]	mv			B5,A5
			ldw			*A4++[0x0],A16
			zero		A16
	||		mvk			0xFF,A17
			nop	3
mcReadNewBytes:
			and			A16,A17,A18
			shru		A16,8,A16
			stb			A18,*A5++[0x1]
			sub			A0,1,A0
			nop	
	  [ A0]	bnop		mcReadNewBytes,5
mCopyEndR:
			pop
			ret

;**************************************************************************************************
;       Номер выполненной PTD
;***sss********************************************************************************************
_number_completed_ptd:
			push
			zero	A0		;рег сравнения
		||	zero	A1		;рег результата
		||	mvk		32,A2		
mcNewBit:
			and		A4,0x1,A0
	 [!A2]	bnop	mErrEndNumberPosition,5
	 [!A0]	bnop	mcNewBit,2
			shru	A4,0x1,A4
			add		A1,0x1,A1
			sub		A2,0x1,A2
mOkEndNumberPosition:
			sub		A1,0x1,A1
mErrEndNumberPosition:
			mv		A1,A4
			pop
			ret
