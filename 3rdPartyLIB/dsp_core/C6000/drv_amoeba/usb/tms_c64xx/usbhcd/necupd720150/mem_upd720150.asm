;******************************************************************************
; 				          Copyright (C) 2009 RCZI
;------------------------------------------------------------------------------
; FILENAME...... mem_pd720150.asm
; DATE CREATED.. 05/02/2009
;------------------------------------------------------------------------------
;	Описание РЕГИСТРОВ контроллера USB  NEC uPD720150
;------------------------------------------------------------------------------
;; !: arch: tms320c64xx
;; !: sarc: all
;;
;; !: codepage: cp1251 
;;
;; !: d: Содержит регистры контроллера USB  NEC uPD720150 Hi-Speed Universal Serial Bus 
;; !: d: host controller, описанные в не загружаемой секции данных ".pd720150_reg". Низкоуровневые функции доступа к памяти хост контроллера.
;; !: -:
;***sss************************************************************************
  .global _REG_ID  
  .global _REG_SYSTEM_CONFIG
  .global _REG_DMA_CONFIG
  .global _REG_USB_CONFIG
  .global _REG_PIPE_CONFIG
  .global _REG_POWER_CONTROL
  .global _REG_INT_STATUS
  .global _REG_INT_ENABLE
  .global _REG_DMA1_CONTROL
  .global _REG_DMA2_CONTROL
  .global _REG_GPIO_CONTROL
  .global _REG_HCUSB_FRAMENUM
  .global _REG_HCUSBP1_STATUS
  .global _REG_HCUSBP1_INTSTATUS
  .global _REG_HCUSBP1_INTENABLE
  .global _REG_HCUSBP2_STATUS
  .global _REG_HCUSBP2_INTSTATUS
  .global _REG_HCUSBP2_INTENABLE
  .global _REG_HCEP0_CONFIG
  .global _REG_HCEP0_CONTROL
  .global _REG_HCEP0_USBREQ
  .global _REG_HCEP0_USBVALUE
  .global _REG_HCEP0_USBINDEX
  .global _REG_HCEP0_USBLENGTH
  .global _REG_HCEP0_DEVINFO
  .global _REG_HCEP0_HUBINFO
  .global _REG_HCEP0_LENGTH
  .global _REG_HCEP0_TBT
  .global _REG_HCEP0_BUFPORT
  .global _REG_HCEP0_STATUS
  .global _REG_HCEP0_INTSTATUS
  .global _REG_HCEP0_INTENABLE
  .global _REG_SCRATCHPAD

  .eval   1, p
  .loop   9
  .global _REG_PIPE_CONFIG1_:p:
  .global _REG_PIPE_CONFIG2_:p:
  .global _REG_PIPE_CONTROL1_:p:
  .global _REG_PIPE_CONTROL2_:p:
  .global _REG_PIPE_DEVINFO_:p:
  .global _REG_PIPE_HUBINFO_:p:
  .global _REG_PIPE_LENGTH_:p:
  .global _REG_PIPE_TBT_:p:
  .global _REG_PIPE_BUFPORT_:p:
  .global _REG_PIPE_STATUS_:p:
  .global _REG_PIPE_INTSTATUS_:p:
  .global _REG_PIPE_INTENABLE_:p:
  .eval   p+1, p
  .endloop

  .sect ".pd720150_reg"
;----------	EHCI capability register ------------	
_REG_ID                  .half  0
_REG_SYSTEM_CONFIG       .half  0
_REG_DMA_CONFIG          .half  0
_REG_USB_CONFIG          .half  0
_REG_PIPE_CONFIG         .half  0
_REG_POWER_CONTROL       .half  0
_REG_INT_STATUS          .half  0
_REG_INT_ENABLE          .half  0
_REG_DMA1_CONTROL        .half  0
_REG_DMA2_CONTROL        .half  0
_REG_GPIO_CONTROL        .half  0
                         .space 0x0a
_REG_HCUSB_FRAMENUM      .half  0
_REG_HCUSBP1_STATUS      .half  0
_REG_HCUSBP1_INTSTATUS   .half  0
_REG_HCUSBP1_INTENABLE   .half  0
_REG_HCUSBP2_STATUS      .half  0
_REG_HCUSBP2_INTSTATUS   .half  0
_REG_HCUSBP2_INTENABLE   .half  0
                         .space 0x12
_REG_HCEP0_CONFIG        .half  0
_REG_HCEP0_CONTROL       .half  0
_REG_HCEP0_USBREQ        .half  0
_REG_HCEP0_USBVALUE      .half  0
_REG_HCEP0_USBINDEX      .half  0
_REG_HCEP0_USBLENGTH     .half  0
_REG_HCEP0_DEVINFO       .half  0
_REG_HCEP0_HUBINFO       .half  0
_REG_HCEP0_LENGTH        .half  0
_REG_HCEP0_TBT           .half  0
_REG_HCEP0_BUFPORT       .half  0
_REG_HCEP0_STATUS        .half  0
_REG_HCEP0_INTSTATUS     .half  0
_REG_HCEP0_INTENABLE     .half  0
                         .space 0x24 
  .eval  1, p
  .loop  9
_REG_PIPE_CONFIG1_:p:    .half  0
_REG_PIPE_CONFIG2_:p:    .half  0
                         .space 0x02 
_REG_PIPE_CONTROL1_:p:   .half  0
_REG_PIPE_CONTROL2_:p:   .half  0
_REG_PIPE_DEVINFO_:p:    .half  0
_REG_PIPE_HUBINFO_:p:    .half  0
_REG_PIPE_LENGTH_:p:     .half  0
_REG_PIPE_TBT_:p:        .half  0
_REG_PIPE_BUFPORT_:p:    .half  0
_REG_PIPE_STATUS_:p:     .half  0
_REG_PIPE_INTSTATUS_:p:  .half  0
_REG_PIPE_INTENABLE_:p:  .half  0
                         .space 0x06
  .eval  p+1, p
  .endloop
                         .space 0x10
_REG_SCRATCHPAD          .half  0

