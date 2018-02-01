//**************************************************************************************************
//                         Copyright (C) 2011 RCZI
//--------------------------------------------------------------------------------------------------
// FILENAME....... mem_upd720150.h
// DATE CREATED... 12/01/2011
// LAST MODIFIED.. 12/01/2011
//--------------------------------------------------------------------------------------------------
//               ÃŒƒ≈À‹ œ¿Ãﬂ“» NEC uPD720150 USB HOST CONTROLLER
//**************************************************************************************************
#ifndef __Driver_REG_NEC_uPD720150_HC_H__
#define __Driver_REG_NEC_uPD720150_HC_H__

#define MEM_BASE                     USBHC_ADDR
#define MEM_SHIFT                    0
#define NUM_PIPES                    9
#define NUM_USBHC_PORT               2
#define HCUSBP1                      0
#define HCUSBP2                      1

//--------------------------------------------------------------------------------------------------
#define REG_ID                        ( *(volatile uint16*)(MEM_BASE|0x000<<MEM_SHIFT) )
#define DREG_ID                       ( *(volatile uint16*)(MEM_BASE|0x000<<MEM_SHIFT) )

#define REG_SYSTEM_CONFIG             ( *(volatile uint16*)(MEM_BASE|0x002<<MEM_SHIFT) ) 
#define DREG_SYSTEM_CONFIG            ( *(volatile uint16*)(MEM_BASE|0x002<<MEM_SHIFT) ) 
#  define BM_B_ENDIAN                   0x8000
#  define BM_INT_POL                    0x0200
#  define BM_INT_SEL                    0x0100

#define REG_DMA_CONFIG                ( *(volatile uint16*)(MEM_BASE|0x004<<MEM_SHIFT) ) 
#define DREG_DMA_CONFIG               ( *(volatile uint16*)(MEM_BASE|0x004<<MEM_SHIFT) ) 
#  define BM_DACK2_POL                  0x2000
#  define BM_DREQ2_POL                  0x1000
#  define BM_DACK1_POL                  0x0200
#  define BM_DREQ1_POL                  0x0100
#  define BM_DMA_TYPE0                  0x0000
#  define BM_DMA_TYPE1                  0x0011
#  define BM_DMA_TYPE2                  0x0022

#define REG_USB_CONFIG                ( *(volatile uint16*)(MEM_BASE|0x006<<MEM_SHIFT) ) 
#define DREG_USB_CONFIG               ( *(volatile uint16*)(MEM_BASE|0x006<<MEM_SHIFT) ) 
#  define BM_NEC_PRIVATE                0x0200
#  define BM_PPC                        0x0080
#  define BM_P2RW_E                     0x0040
#  define BM_P1RW_E                     0x0020
#  define BM_P2_FSFIX                   0x0010
#  define BM_P1_FSFIX                   0x0008
#  define BM_P2_TYPE                    0x0004
#  define BM_P2_E                       0x0002
#  define BM_P1_E                       0x0001

#define REG_PIPE_CONFIG               ( *(volatile uint16*)(MEM_BASE|0x008<<MEM_SHIFT) )
#define DREG_PIPE_CONFIG              ( *(volatile uint16*)(MEM_BASE|0x008<<MEM_SHIFT) )
#  define BM_PIPE9TYPE                  0x0200
#  define BM_PIPE8TYPE                  0x0100
#  define BM_PIPE7TYPE                  0x0080
#  define BM_PIPE6TYPE                  0x0040
#  define BM_PIPE5TYPE                  0x0020
#  define BM_PIPE4TYPE                  0x0010
#  define BM_PIPE3TYPE                  0x0008
#  define BM_PIPE2TYPE                  0x0004
#  define BM_PIPE1TYPE                  0x0002
  
#define REG_POWER_CONTROL             ( *(volatile uint16*)(MEM_BASE|0x00A<<MEM_SHIFT) )   
#define DREG_POWER_CONTROL            ( *(volatile uint16*)(MEM_BASE|0x00A<<MEM_SHIFT) ) 
#  define BM_GSUSPEND                   0x0010
#  define BM_PWDOWN                     0x0008
#  define BM_HCRST                      0x0002
#  define BM_ALLRST                     0x0001
  
#define REG_INT_STATUS                ( *(volatile uint16*)(MEM_BASE|0x00C<<MEM_SHIFT) )   
#define DREG_INT_STATUS               ( *(volatile uint16*)(MEM_BASE|0x00C<<MEM_SHIFT) ) 
#  define BM_INT_STATUS_CLR_ALL         0x4000
#  define BM_HCSOFINT                   0x4000
#  define BM_PIPE9INT                   0x2000
#  define BM_PIPE8INT                   0x1000
#  define BM_PIPE7INT                   0x0800
#  define BM_PIPE6INT                   0x0400
#  define BM_PIPE5INT                   0x0200
#  define BM_PIPE4INT                   0x0100
#  define BM_PIPE3INT                   0x0080
#  define BM_PIPE2INT                   0x0040
#  define BM_PIPE1INT                   0x0020
#  define BM_HCEP0INT                   0x0008
#  define BM_PORT2INT                   0x0002
#  define BM_PORT1INT                   0x0001

#define REG_INT_ENABLE                ( *(volatile uint16*)(MEM_BASE|0x00E<<MEM_SHIFT) ) 
#define DREG_INT_ENABLE               ( *(volatile uint16*)(MEM_BASE|0x00E<<MEM_SHIFT) ) 
#  define BM_HCSOFINT_E                 0x4000
#  define BM_PIPE9INT_E                 0x2000
#  define BM_PIPE8INT_E                 0x1000
#  define BM_PIPE7INT_E                 0x0800
#  define BM_PIPE6INT_E                 0x0400
#  define BM_PIPE5INT_E                 0x0200
#  define BM_PIPE4INT_E                 0x0100
#  define BM_PIPE3INT_E                 0x0080
#  define BM_PIPE2INT_E                 0x0040
#  define BM_PIPE1INT_E                 0x0020
#  define BM_HCEP0INT_E                 0x0008
#  define BM_PORT2INT_E                 0x0002
#  define BM_PORT1INT_E                 0x0001
  
#define REG_DMA1_CONTROL              ( *(volatile uint16*)(MEM_BASE|0x010<<MEM_SHIFT) ) 
#define REG_DMA2_CONTROL              ( *(volatile uint16*)(MEM_BASE|0x012<<MEM_SHIFT) )   
#define DREG_DMA1_CONTROL             ( *(volatile uint16*)(MEM_BASE|0x010<<MEM_SHIFT) ) 
#define DREG_DMA2_CONTROL             ( *(volatile uint16*)(MEM_BASE|0x012<<MEM_SHIFT) ) 
#  define BM_DMASTART                   0x8000
#  define BM_PIPE_NUM_1                 0x0100
#  define BM_PIPE_NUM_2                 0x0200
#  define BM_CONTINUE                   0x0080
#  define BM_BUS_SEL_8                  0x0020
#  define BM_BUS_SEL_16                 0x0000
#  define BM_DMAMODE_SINGLE             0x0000
#  define BM_DMAMODE_BARST1             0x0002
#  define BM_DMAMODE_BARST2             0x0003

#define REG_GPIO_CONTROL              ( *(volatile uint16*)(MEM_BASE|0x014<<MEM_SHIFT) ) 
#define DREG_GPIO_CONTROL             ( *(volatile uint16*)(MEM_BASE|0x014<<MEM_SHIFT) ) 
#  define BM_GPIO4_WR                   0x1000
#  define BM_GPIO5_WR                   0x2000
#  define BM_GPIO3_WR                   0x0800
#  define BM_GPIO2_WR                   0x0400
#  define BM_GPIO1_WR                   0x0200
#  define BM_GPIO0_WR                   0x0100
#  define BM_GPIO5                      0x0020
#  define BM_GPIO4                      0x0010
#  define BM_GPIO3                      0x0008
#  define BM_GPIO2                      0x0004
#  define BM_GPIO1                      0x0002
#  define BM_GPIO0                      0x0001

#define REG_HCUSB_FRAMENUM            ( *(volatile uint16*)(MEM_BASE|0x020<<MEM_SHIFT) ) 
#define DREG_HCUSB_FRAMENUM           ( *(volatile uint16*)(MEM_BASE|0x020<<MEM_SHIFT) ) 

//--------------------------------------------------------------------------------------------------
#define REG_HCUSBP1_STATUS            ( *(volatile uint16*)(MEM_BASE|0x022<<MEM_SHIFT) ) 
#define REG_HCUSBP2_STATUS            ( *(volatile uint16*)(MEM_BASE|0x028<<MEM_SHIFT) ) 
#define DREG_HCUSBP1_STATUS           ( *(volatile uint16*)(MEM_BASE|0x022<<MEM_SHIFT) ) 
#define DREG_HCUSBP2_STATUS           ( *(volatile uint16*)(MEM_BASE|0x028<<MEM_SHIFT) ) 
#  define BM_USBTEST_NORM               0x0000
#  define BM_USBTEST_TEST_J             0x1000
#  define BM_USBTEST_TEST_K             0x2000
#  define BM_USBTEST_TEST_SE0_NAK       0x3000
#  define BM_USBTEST_TEST_PACKET        0x4000
#  define BM_USBTEST_TEST_FORCE_ENABLE  0x5000
#  define BM_HSDA                       0x0400
#  define BM_LSDA                       0x0200
#  define BM_PP                         0x0100
#  define BM_PR                         0x0010
#  define BM_OCA                        0x0008
#  define BM_SUSPEND                    0x0004
#  define BM_PES                        0x0002
#  define BM_CCS                        0x0001
  
#define REG_HCUSBP1_INTSTATUS         ( *(volatile uint16*)(MEM_BASE|0x024<<MEM_SHIFT) ) 
#define REG_HCUSBP2_INTSTATUS         ( *(volatile uint16*)(MEM_BASE|0x02A<<MEM_SHIFT) )   
#define DREG_HCUSBP1_INTSTATUS        ( *(volatile uint16*)(MEM_BASE|0x024<<MEM_SHIFT) ) 
#define DREG_HCUSBP2_INTSTATUS        ( *(volatile uint16*)(MEM_BASE|0x02A<<MEM_SHIFT) ) 
#  define BM_HCUSBP1_INTSTATUS_CLR_ALL  0x001F
#  define BM_HCUSBP2_INTSTATUS_CLR_ALL  0x001F
#  define BM_PRSC                       0x0010
#  define BM_OCIC                       0x0008
#  define BM_SUSPENDC                   0x0004
#  define BM_PESC                       0x0002
#  define BM_CSC                        0x0001

#define REG_HCUSBP1_INTENABLE         ( *(volatile uint16*)(MEM_BASE|0x026<<MEM_SHIFT) ) 
#define REG_HCUSBP2_INTENABLE         ( *(volatile uint16*)(MEM_BASE|0x02C<<MEM_SHIFT) ) 
#define DREG_HCUSBP1_INTENABLE        ( *(volatile uint16*)(MEM_BASE|0x026<<MEM_SHIFT) ) 
#define DREG_HCUSBP2_INTENABLE        ( *(volatile uint16*)(MEM_BASE|0x02C<<MEM_SHIFT) ) 
#  define BM_PRSC_E                     0x0010
#  define BM_OCIC_E                     0x0008
#  define BM_SUSPENDC_E                 0x0004
#  define BM_PESC_E                     0x0002
#  define BM_CSC_E                      0x0001

//--------------------------------------------------------------------------------------------------
#define REG_HCEP0_CONFIG              ( *(volatile uint16*)(MEM_BASE|0x040<<MEM_SHIFT) ) 
#define DREG_HCEP0_CONFIG             ( *(volatile uint16*)(MEM_BASE|0x040<<MEM_SHIFT) ) 
#  define BM_SET                        0x8000
#  define BM_SPEED_LS                   0x0000
#  define BM_SPEED_FS                   0x1000
#  define BM_SPEED_HS                   0x2000
#  define BM_MPS_8                      0x0008
#  define BM_MPS_16                     0x0010
#  define BM_MPS_32                     0x0020
#  define BM_MPS_64                     0x0040

#define REG_HCEP0_CONTROL             ( *(volatile uint16*)(MEM_BASE|0x042<<MEM_SHIFT) ) 
#define DREG_HCEP0_CONTROL            ( *(volatile uint16*)(MEM_BASE|0x042<<MEM_SHIFT) ) 
#  define BM_EP0C_ACTIVE                0x8000
#  define BM_EP0C_INACTIVE              0x4000
#  define BM_EP0C_NULL                  0x0400
#  define BM_EP0C_DPID_SET              0x0200
#  define BM_EP0C_DEND                  0x0080
#  define BM_EP0C_DPID_CLR              0x0010
#  define BM_EP0C_PID_SETUP             0x0008
#  define BM_EP0C_PID_IN                0x0004
#  define BM_EP0C_PID_OUT               0x0000

#define REG_HCEP0_USBREQ              ( *(volatile uint16*)(MEM_BASE|0x044<<MEM_SHIFT) ) 
#define REG_HCEP0_USBVALUE            ( *(volatile uint16*)(MEM_BASE|0x046<<MEM_SHIFT) ) 
#define REG_HCEP0_USBINDEX            ( *(volatile uint16*)(MEM_BASE|0x048<<MEM_SHIFT) ) 
#define REG_HCEP0_USBLENGTH           ( *(volatile uint16*)(MEM_BASE|0x04A<<MEM_SHIFT) ) 
#define REG_HCEP0_DEVINFO             ( *(volatile uint16*)(MEM_BASE|0x04C<<MEM_SHIFT) ) 
#define REG_HCEP0_HUBINFO             ( *(volatile uint16*)(MEM_BASE|0x04E<<MEM_SHIFT) ) 
#define REG_HCEP0_LENGTH              ( *(volatile uint16*)(MEM_BASE|0x050<<MEM_SHIFT) ) 
#define REG_HCEP0_TBT                 ( *(volatile uint16*)(MEM_BASE|0x052<<MEM_SHIFT) ) 
#define REG_HCEP0_BUFPORT             ( *(volatile uint16*)(MEM_BASE|0x054<<MEM_SHIFT) ) 
#define DREG_HCEP0_USBREQ             ( *(volatile uint16*)(MEM_BASE|0x044<<MEM_SHIFT) ) 
#define DREG_HCEP0_USBVALUE           ( *(volatile uint16*)(MEM_BASE|0x046<<MEM_SHIFT) ) 
#define DREG_HCEP0_USBINDEX           ( *(volatile uint16*)(MEM_BASE|0x048<<MEM_SHIFT) ) 
#define DREG_HCEP0_USBLENGTH          ( *(volatile uint16*)(MEM_BASE|0x04A<<MEM_SHIFT) ) 
#define DREG_HCEP0_DEVINFO            ( *(volatile uint16*)(MEM_BASE|0x04C<<MEM_SHIFT) ) 
#define DREG_HCEP0_HUBINFO            ( *(volatile uint16*)(MEM_BASE|0x04E<<MEM_SHIFT) ) 
#define DREG_HCEP0_LENGTH             ( *(volatile uint16*)(MEM_BASE|0x050<<MEM_SHIFT) ) 
#define DREG_HCEP0_TBT                ( *(volatile uint16*)(MEM_BASE|0x052<<MEM_SHIFT) ) 
#define DREG_HCEP0_BUFPORT            ( *(volatile uint16*)(MEM_BASE|0x054<<MEM_SHIFT) ) 

#define REG_HCEP0_STATUS              ( *(volatile uint16*)(MEM_BASE|0x056<<MEM_SHIFT) ) 
#define DREG_HCEP0_STATUS             ( *(volatile uint16*)(MEM_BASE|0x056<<MEM_SHIFT) ) 
#  define BM_EP0S_CONF                  0x8000
#  define BM_EP0S_ACTIVE                0x0020
#  define BM_EP0S_DPID                  0x0010
#  define BM_EP0S_BUF_STA               0x0002
  
#define REG_HCEP0_INTSTATUS           ( *(volatile uint16*)(MEM_BASE|0x058<<MEM_SHIFT) )   
#define DREG_HCEP0_INTSTATUS          ( *(volatile uint16*)(MEM_BASE|0x058<<MEM_SHIFT) ) 
#  define BM_HCEP0_INTSTATUS_CLR_ALL    0xFFFF
#  define BM_EP0IS_HALT                 0x2000
#  define BM_EP0IS_NULL                 0x1000
#  define BM_EP0IS_ORUN                 0x0800
#  define BM_EP0IS_SHORT                0x0400
#  define BM_EP0IS_COMPLETE             0x0020
#  define BM_EP0IS_OUTDT                0x0010
#  define BM_EP0IS_STALL                0x0008
#  define BM_EP0IS_INDT                 0x0001

#define REG_HCEP0_INTENABLE           ( *(volatile uint16*)(MEM_BASE|0x05A<<MEM_SHIFT) ) 
#define DREG_HCEP0_INTENABLE          ( *(volatile uint16*)(MEM_BASE|0x05A<<MEM_SHIFT) ) 
#  define BM_HCEP0_INTENABLE_ALL_DIS    0x0000
#  define BM_EP0IE_HALT_E               0x2000
#  define BM_EP0IE_NULL_E               0x1000
#  define BM_EP0IE_ORUN_E               0x0800
#  define BM_EP0IE_SHORT_E              0x0400
#  define BM_EP0IE_COMPLETE_E           0x0020
#  define BM_EP0IE_OUTDT_E              0x0010
#  define BM_EP0IE_STALL_E              0x0008
#  define BM_EP0IE_INDT_E               0x0001

//--------------------------------------------------------------------------------------------------
#define DREG_PIPE_CONFIG1( n )       ( (volatile uint16*)(MEM_BASE|(0x080+0x20*(n))<<MEM_SHIFT) ) 
#  define BM_BUFTYPE_W                 0x4000
#  define BM_BUFTYPE_S                 0x0000
#  define BM_TR_TYPE_ISO               0x0004
#  define BM_TR_TYPE_BLK               0x0008
#  define BM_TR_TYPE_INT               0x000C
#  define BM_DIR_OUT                   0x0000
#  define BM_DIR_IN                    0x0002
#  define BM_PIPE_DIS                  0x0000
#  define BM_PIPE_EN                   0x0001
  
#define DREG_PIPE_CONFIG2( n )       ( (volatile uint16*)(MEM_BASE|(0x082+0x20*(n))<<MEM_SHIFT) ) 
#  define BM_PIPE_SPEED_LS             0x0000
#  define BM_PIPE_SPEED_FS             0x1000
#  define BM_PIPE_SPEED_HS             0x2000
#  define BM_PIPE_MPS_8                0x0008
#  define BM_PIPE_MPS_64               0x0040
#  define BM_PIPE_MPS_512              0x0200
  
#define DREG_PIPE_CONTROL1( n )      ( (volatile uint16*)(MEM_BASE|(0x086+0x20*(n))<<MEM_SHIFT) ) 
#  define BM_PIPE_AUTO                 0x0001

#define DREG_PIPE_CONTROL2( n )      ( (volatile uint16*)(MEM_BASE|(0x088+0x20*(n))<<MEM_SHIFT) ) 
#  define BM_PIPE_ACTIVE               0x8000
#  define BM_PIPE_INACTIVE             0x4000
#  define BM_PIPE_AUTO_NULL            0x0800
#  define BM_PIPE_NULL                 0x0400
#  define BM_PIPE_DPID_SET             0x0200
#  define BM_PIPE_DEND                 0x0080
#  define BM_PIPE_BYTE_SET             0x0020
#  define BM_PIPE_DPID_CLR             0x0010

#define DREG_PIPE_DEVINFO( n )       ( (volatile uint16*)(MEM_BASE|(0x08A+0x20*(n))<<MEM_SHIFT) ) 
#define DREG_PIPE_HUBINFO( n )       ( (volatile uint16*)(MEM_BASE|(0x08C+0x20*(n))<<MEM_SHIFT) ) 
#define DREG_PIPE_LENGTH( n )        ( (volatile uint16*)(MEM_BASE|(0x08E + 0x20*(n))<<MEM_SHIFT) ) 
#define DREG_PIPE_TBT( n )           ( (volatile uint16*)(MEM_BASE|(0x090+0x20*(n))<<MEM_SHIFT) ) 
#define DREG_PIPE_BUFPORT( n )       ( (volatile uint16*)(MEM_BASE|(0x092+0x20*(n))<<MEM_SHIFT) ) 

#define DREG_PIPE_STATUS( n )        ( (volatile uint16*)(MEM_BASE|(0x094+0x20*(n))<<MEM_SHIFT) ) 
#  define BM_PIPEST_SCH_ERR            0x8000
#  define BM_PIPEST_MAP_ERR            0x4000
#  define BM_PIPEST_ISO_NOTKN          0x1000
#  define BM_PIPEST_ISO_ORUN           0x0800
#  define BM_PIPEST_ACTIVE             0x0020
#  define BM_PIPEST_DPID               0x0010
#  define BM_PIPEST_BUF_STA            0x0003

#define DREG_PIPE_INTSTATUS( n )     ( (volatile uint16*)(MEM_BASE|(0x096+0x20*(n))<<MEM_SHIFT) ) 
#define REG_PIPE_INTSTATUS_1          *DREG_PIPE_INTSTATUS( 0 )
#define REG_PIPE_INTSTATUS_2          *DREG_PIPE_INTSTATUS( 1 )
#define REG_PIPE_INTSTATUS_3          *DREG_PIPE_INTSTATUS( 2 )
#define REG_PIPE_INTSTATUS_4          *DREG_PIPE_INTSTATUS( 3 )
#define REG_PIPE_INTSTATUS_5          *DREG_PIPE_INTSTATUS( 4 )
#define REG_PIPE_INTSTATUS_6          *DREG_PIPE_INTSTATUS( 5 )
#define REG_PIPE_INTSTATUS_7          *DREG_PIPE_INTSTATUS( 6 )
#define REG_PIPE_INTSTATUS_8          *DREG_PIPE_INTSTATUS( 7 )
#define REG_PIPE_INTSTATUS_9          *DREG_PIPE_INTSTATUS( 8 )
#  define BM_PIPEIS_INTSTATUS_CLR_ALL  0xFFFF
#  define BM_PIPEIS_SM_ERR             0x8000
#  define BM_PIPEIS_BYTE               0x4000
#  define BM_PIPEIS_HALT               0x2000
#  define BM_PIPEIS_NULL               0x1000
#  define BM_PIPEIS_ORUN               0x0800
#  define BM_PIPEIS_SHORT              0x0400
#  define BM_PIPEIS_SM_CONF            0x0200
#  define BM_PIPEIS_DA_DONE            0x0080
#  define BM_PIPEIS_COMPLETE           0x0020
#  define BM_PIPEIS_OUTDT              0x0010
#  define BM_PIPEIS_STALL              0x0008
#  define BM_PIPEIS_INDT               0x0001

#define DREG_PIPE_INTENABLE( n )     ( (volatile uint16*)(MEM_BASE|(0x098+0x20*(n))<<MEM_SHIFT) ) 
#define REG_PIPE_INTENABLE_1          *DREG_PIPE_INTENABLE( 0 )
#define REG_PIPE_INTENABLE_2          *DREG_PIPE_INTENABLE( 1 )
#define REG_PIPE_INTENABLE_3          *DREG_PIPE_INTENABLE( 2 )
#define REG_PIPE_INTENABLE_4          *DREG_PIPE_INTENABLE( 3 )
#define REG_PIPE_INTENABLE_5          *DREG_PIPE_INTENABLE( 4 )
#define REG_PIPE_INTENABLE_6          *DREG_PIPE_INTENABLE( 5 )
#define REG_PIPE_INTENABLE_7          *DREG_PIPE_INTENABLE( 6 )
#define REG_PIPE_INTENABLE_8          *DREG_PIPE_INTENABLE( 7 )
#define REG_PIPE_INTENABLE_9          *DREG_PIPE_INTENABLE( 8 )
#  define BM_PIPEIE_SM_ERR_E           0x8000
#  define BM_PIPEIE_BYTE_E             0x4000
#  define BM_PIPEIE_HALT_E             0x2000
#  define BM_PIPEIE_NULL_E             0x1000
#  define BM_PIPEIE_ORUN_E             0x0800
#  define BM_PIPEIE_SHORT_E            0x0400
#  define BM_PIPEIE_SM_CONF_E          0x0200
#  define BM_PIPEIE_DA_DONE_E          0x0080
#  define BM_PIPEIE_COMPLETE_E         0x0020
#  define BM_PIPEIE_OUTDT_E            0x0010
#  define BM_PIPEIE_STALL_E            0x0008
#  define BM_PIPEIE_INDT_E             0x0001

#define REG_SCRATCHPAD              ( *(volatile uint16*)(MEM_BASE|0x1B0<<MEM_SHIFT) ) 
#define DREG_SCRATCHPAD             ( *(volatile uint16*)(MEM_BASE|0x1B0<<MEM_SHIFT) ) 

#endif //__Driver_REG_NEC_uPD720150_HC_H__


