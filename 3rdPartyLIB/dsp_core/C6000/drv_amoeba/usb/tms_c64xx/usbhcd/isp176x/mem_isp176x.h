//**************************************************************************************************
//                         Copyright (C) 2009 RCZI
//--------------------------------------------------------------------------------------------------
// FILENAME....... mem_isp176x.h
// DATE CREATED... 26/02/2009
// LAST MODIFIED.. 19/11/2009
// DRIVER VERSION. OS.1.0
//--------------------------------------------------------------------------------------------------
//               МОДЕЛЬ ПАМЯТИ ISP176x USB HOST CONTROLLER
//-------------------------------------------------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
//
// !: codepage: cp1251 
//
// !: d: Содержит таблицы распределения памяти драйвера ISP 1760/1761 
// !: d: Hi-Speed Universal Serial Bus host controller, описанные в не 
// !: d: загружаемой секции данных ".isp176x_mem".
// !: -:
//**************************************************************************************************
#ifndef __Driver_ISP176x_HC_H__
#define __Driver_ISP176x_HC_H__

#include    <os_types.h>
//
#ifndef ISP176_BUS_32
  #error "ERROR: ISP176_BUS_32 неопределен"
#endif
/**************************************************************************************************\
*                               Asynchronous Transfer List
\**************************************************************************************************/
        //HIGH-SPEED BULK TRANSACTION//
//DW3:
#define    HS_BULK_A        (uint32) 1
#define    HS_BULK_H        (uint32) 0
#define    HS_BULK_B        (uint32) 0
#define    HS_BULK_X        (uint32) 0
#define    HS_BULK_CERR     (uint32) 3       
#define    HS_BULK_NACCNT   (uint32) 1
//DW2:
#define    HS_BULK_RL       (uint32) 1
//DW1:
#define    HS_BULK_S        (uint32) 0
//DW0:
#define    HS_BULK_MULT     (uint32) 1
#define    HS_BULK_V        (uint32) 1
//Константы DW:
#define    HS_BULK_DW7      (0x00000000)
#define    HS_BULK_DW6      (0x00000000)
#define    HS_BULK_DW5      (0x00000000)
#define    HS_BULK_DW4      (0x00000000)
#define    HS_BULK_DW3      ((HS_BULK_A<<31)|(HS_BULK_H<<30)|(HS_BULK_B<<29)|(HS_BULK_X<<28)|(HS_BULK_CERR<<23)|(HS_BULK_NACCNT<<19))
#define    HS_BULK_DW2      ((HS_BULK_RL<<25))
#define    HS_BULK_DW1      ((HS_BULK_S<<14))
#define    HS_BULK_DW0      ((HS_BULK_MULT<<29)|(HS_BULK_V))
        //START-COMPLETE SPLIT BULK TRANSACTION//
//DW3:
#define    CS_BULK_A        (uint32) 1
#define    CS_BULK_H        (uint32) 0
#define    CS_BULK_B        (uint32) 0
#define    CS_BULK_X        (uint32) 0
#define    CS_BULK_SC       (uint32) 0
#define    CS_BULK_CERR     (uint32) 3       
#define    CS_BULK_NACCNT   (uint32) 0
//DW2:
#define    CS_BULK_RL       (uint32) 0
//DW1:
#define    CS_BULK_S        (uint32) 1
//DW0:
#define    CS_BULK_V        (uint32) 1
//Константы DW:
#define    CS_BULK_DW7      (0x00000000)
#define    CS_BULK_DW6      (0x00000000)
#define    CS_BULK_DW5      (0x00000000)
#define    CS_BULK_DW4      (0x00000000)
#define    CS_BULK_DW3      ((CS_BULK_A<<31)|(CS_BULK_H<<30)|(CS_BULK_B<<29)|(CS_BULK_X<<28)|(CS_BULK_X<<27)|(CS_BULK_CERR<<23)|(CS_BULK_NACCNT<<19))
#define    CS_BULK_DW2      ((CS_BULK_RL<<25))
#define    CS_BULK_DW1      ((CS_BULK_S<<14))
#define    CS_BULK_DW0      ((CS_BULK_V))

/**************************************************************************************************\
*                               Interrupt Transfer List
\**************************************************************************************************/
        //HIGH-SPEED INTERRUPT TRANSACTION//
//DW7, DW6, DW5
#define    HS_INT_INT_IN_7  (uint32) 0
#define    HS_INT_INT_IN_6  (uint32) 0
#define    HS_INT_INT_IN_5  (uint32) 0
#define    HS_INT_INT_IN_4  (uint32) 0
#define    HS_INT_INT_IN_3  (uint32) 0
#define    HS_INT_INT_IN_2  (uint32) 0
#define    HS_INT_INT_IN_1  (uint32) 0
#define    HS_INT_INT_IN_0  (uint32) 0
//DW4
#define    HS_INT_Status7   (uint32) 0
#define    HS_INT_Status6   (uint32) 0
#define    HS_INT_Status5   (uint32) 0
#define    HS_INT_Status4   (uint32) 0
#define    HS_INT_Status3   (uint32) 0
#define    HS_INT_Status2   (uint32) 0
#define    HS_INT_Status1   (uint32) 0
#define    HS_INT_Status0   (uint32) 0
//DW3:
#define    HS_INT_A         (uint32) 1
#define    HS_INT_H         (uint32) 0
#define    HS_INT_CERR      (uint32) 3       
//DW1:
#define    HS_INT_S         (uint32) 0
//DW0:
#define    HS_INT_MULT      (uint32) 1
#define    HS_INT_V         (uint32) 1
//Константы DW:
#define    HS_INT_DW7       ((HS_INT_INT_IN_7<<20)|(HS_INT_INT_IN_6<<8)|(HS_INT_INT_IN_5>>4))
#define    HS_INT_DW6       (((HS_INT_INT_IN_5&0xF)<<2)|(HS_INT_INT_IN_4<<16)|(HS_INT_INT_IN_3<<4)|(HS_INT_INT_IN_2>>8))
#define    HS_INT_DW5       (((HS_INT_INT_IN_2&0xFF)<<24)|(HS_INT_INT_IN_1<<12)|(HS_INT_INT_IN_0))
#define    HS_INT_DW4       ((HS_INT_Status7<<29)|(HS_INT_Status6<<26)|(HS_INT_Status5<<23)|(HS_INT_Status4<<20)|(HS_INT_Status3<<17)|(HS_INT_Status2<<14)|(HS_INT_Status1<<11)|(HS_INT_Status0<<8))
#define    HS_INT_DW3       ((HS_INT_A<<31)|(HS_INT_H<<30)|(HS_INT_CERR<<23))
#define    HS_INT_DW2       (0x00000000 )
#define    HS_INT_DW1       ((HS_INT_S<<14))
#define    HS_INT_DW0       ((HS_INT_MULT<<29)|(HS_INT_V))
        //START-COMPLETE SPLIT INTERRUPT TRANSACTION//
//DW7, DW6, DW5
#define    SC_INT_INT_IN_7  (uint32) 0
#define    SC_INT_INT_IN_6  (uint32) 0
#define    SC_INT_INT_IN_5  (uint32) 0
#define    SC_INT_INT_IN_4  (uint32) 0
#define    SC_INT_INT_IN_3  (uint32) 0
#define    SC_INT_INT_IN_2  (uint32) 0
#define    SC_INT_INT_IN_1  (uint32) 0
#define    SC_INT_INT_IN_0  (uint32) 0
//DW4
#define    SC_INT_Status7   (uint32) 0
#define    SC_INT_Status6   (uint32) 0
#define    SC_INT_Status5   (uint32) 0
#define    SC_INT_Status4   (uint32) 0
#define    SC_INT_Status3   (uint32) 0
#define    SC_INT_Status2   (uint32) 0
#define    SC_INT_Status1   (uint32) 0
#define    SC_INT_Status0   (uint32) 0
//DW3:
#define    SC_INT_A         (uint32) 1
#define    SC_INT_H         (uint32) 0
#define    SC_INT_B         (uint32) 0
#define    SC_INT_X         (uint32) 0
#define    SC_INT_SC        (uint32) 0
#define    SC_INT_CERR      (uint32) 3       
//DW1:
#define    SC_INT_S         (uint32) 1
//DW0:
#define    SC_INT_V         (uint32) 1
//Константы DW:
#define    SC_INT_DW7       ((SC_INT_INT_IN_7))
#define    SC_INT_DW6       ((SC_INT_INT_IN_6<<24)|(SC_INT_INT_IN_5<<16)|(SC_INT_INT_IN_4<<8)|(SC_INT_INT_IN_3))
#define    SC_INT_DW5       ((SC_INT_INT_IN_2<<24)|(SC_INT_INT_IN_1<<16)|(SC_INT_INT_IN_0<<8))
#define    SC_INT_DW4       ((SC_INT_Status7<<29)|(SC_INT_Status6<<26)|(SC_INT_Status5<<23)|(SC_INT_Status4<<20)|(SC_INT_Status3<<17)|(SC_INT_Status2<<14)|(SC_INT_Status1<<11)|(SC_INT_Status0<<8))
#define    SC_INT_DW3       ((SC_INT_A<<31)|(SC_INT_H<<30)|(SC_INT_B<<29)|(SC_INT_X<<28)|(SC_INT_SC<<27)|(SC_INT_CERR<<23))
#define    SC_INT_DW2       (0x00000000)
#define    SC_INT_DW1       ((SC_INT_S<<14))
#define    SC_INT_DW0       ((SC_INT_V))

/**************************************************************************************************\
*       Настройка
\**************************************************************************************************/
#if     ISP176_BUS_32==1
    #define USB_MEM_SHIFT                   (0x1)
#elif   ISP176_BUS_32==0
    #define USB_MEM_SHIFT                   (0x0)
#else
    #error "ERROR: ISP176_BUS_32 неверно определен"
#endif
/**************************************************************************************************\
*       ISP register address
\**************************************************************************************************/
extern far uint32 reg_isp176x;
extern far uint32 mem_isp176x;
//EHCI capability register
extern far uint32 REG_CAPLENGTH;    
extern far uint32 REG_HCIVERSION;       
extern far uint32 REG_HCSPARAMS;            
extern far uint32 REG_HCCPARAMS;    
//EHCI operational register   
extern far uint32 REG_USBCMD;        
extern far uint32 REG_USBSTS;            
extern far uint32 REG_USBINTR;           
extern far uint32 REG_FRINDEX;
extern far uint32 REG_CTRLDSSEGMENT;                     
extern far uint32 REG_CONFIGFLAG;        
extern far uint32 REG_PORTSC1;                   
extern far uint32 REG_ISO_PTD_Done_Map;
extern far uint32 REG_ISO_PTD_Skip_Map;                
extern far uint32 REG_ISO_PTD_Last_PTD;                
extern far uint32 REG_INT_PTD_Done_Map;                
extern far uint32 REG_INT_PTD_Skip_Map;                
extern far uint32 REG_INT_PTD_Last_PTD;                
extern far uint32 REG_ATL_PTD_Done_Map;                
extern far uint32 REG_ATL_PTD_Skip_Map;                
extern far uint32 REG_ATL_PTD_Last_PTD;
//Configuration register
extern far uint32 REG_HW_Mode_Control;            
extern far uint32 REG_Chip_ID;                    
extern far uint32 REG_Scratch;                    
extern far uint32 REG_SW_Reset;       
extern far uint32 REG_DMA_Configuration;
extern far uint32 REG_Buffer_Status;                   
extern far uint32 REG_ATL_Done_Timeout;                
extern far uint32 REG_Memory;                          
extern far uint32 REG_Edge_Interrupt_Count;
extern far uint32 REG_DMA_Start_Address;                                   
extern far uint32 REG_Power_Down_Control;                                  
//extern far int Port_1_Control;
//OTG Controller registers
extern far uint16 REG_VendorID;                      
extern far uint16 REG_ProductID;
extern far uint16 REG_Port_1_Control;                        
extern far uint16 REG_OTG_Control_set;
extern far uint16 REG_OTG_Control_clear;             
extern far uint16 REG_OTG_Status;                    
extern far uint16 REG_OTG_Interrupt_Latch_set;       
extern far uint16 REG_OTG_Interrupt_Latch_clear;     
extern far uint16 REG_OTG_Interrupt_Enable_Fall_set; 
extern far uint16 REG_OTG_Interrupt_Enable_Fall_clear;
extern far uint16 REG_OTG_Interrupt_Enable_Rise_set; 
extern far uint16 REG_OTG_Interrupt_Enable_Rise_clear;
extern far uint16 REG_OTG_Timer_Lower_word_set;      
extern far uint16 REG_OTG_Timer_Lower_word_clear;        
extern far uint16 REG_OTG_Timer_Higher_word_set;     
extern far uint16 REG_OTG_Timer_Higher_word_clear;         
//Interrupt registers               
extern far uint32 REG_Interrupt;                       
extern far uint32 REG_Interrupt_Enable;
extern far uint32 REG_ISO_IRQ_Mask_OR;                 
extern far uint32 REG_INT_IRQ_Mask_OR;                 
extern far uint32 REG_ATL_IRQ_Mask_OR;                 
extern far uint32 REG_ISO_IRQ_Mask_AND;                
extern far uint32 REG_INT_IRQ_Mask_AND;                
extern far uint32 REG_ATL_IRQ_Mask_AND;

#define MAX_ISO_PTD                         32
#define MAX_INT_PTD                         32
#define MAX_ATL_PTD                         32

#define MAX_PL64                            32
#define MAX_PL512                           116

#define ELEMENT_PL64                        64
#define ELEMENT_PL512                       512

#pragma DATA_SECTION (".isp176x_mem");
uint32 MEM_IsoPTD      [MAX_ISO_PTD][8<<USB_MEM_SHIFT]; 
#pragma DATA_SECTION (".isp176x_mem");
uint32 MEM_IntPTD      [MAX_INT_PTD][8<<USB_MEM_SHIFT];
#pragma DATA_SECTION (".isp176x_mem");
uint32 MEM_AtlPTD      [MAX_ATL_PTD][8<<USB_MEM_SHIFT];
//                        /-> Количество POOL-ов
//                       /         /-> Количество WORD-ов
#pragma DATA_SECTION (".isp176x_mem");
uint32 MEM_Payload64   [MAX_PL64][ELEMENT_PL64/4<<USB_MEM_SHIFT];
#pragma DATA_SECTION (".isp176x_mem");
uint32 MEM_Payload512  [MAX_PL512][ELEMENT_PL512/4<<USB_MEM_SHIFT];

#endif //__Driver_ISP176x_HC_H__
