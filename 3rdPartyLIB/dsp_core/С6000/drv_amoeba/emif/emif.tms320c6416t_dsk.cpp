// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: tms320c6416t_dsk
// !: codepage: cp1251
// !: d: Модуль содержит реализацию функции инициализации шины EMIF для
// !: d: отладочной платы tms320c6416t_dsk.
// ---------------------------------------------------------------------------
#include <os.h>
#include <emif.h>

//============================================================================
//                      External Memory Interface A
//============================================================================
    //Global Control:
#define EA_GBL_CTL_NOHOLD      GBLCTL_ENABLE
#define EA_GBL_CTL_CLK4EN      GBLCTL_ENABLE
#define EA_GBL_CTL_CLK6EN      GBLCTL_ENABLE
#define EA_GBL_CTL_EK1EN       GBLCTL_ENABLE
#define EA_GBL_CTL_EK2EN       GBLCTL_ENABLE
#define EA_GBL_CTL_EK1HZ       GBLCTL_HIGHZ
#define EA_GBL_CTL_EK2HZ       GBLCTL_CLK
#define EA_GBL_CTL_EK2RATE     GBLCTL_QUARCLK
#define EA_GBL_CTL_BRMODE      GBLCTL_MRSTATUS
#define EA_GBL_CTL_BUSREQ      0                //R
#define EA_GBL_CTL_ARDY        0                //R
#define EA_GBL_CTL_HOLD        0                //R
#define EA_GBL_CTL_HOLDA       0                //R

    //CE0 Space:
#define EA_CE_CTL_0_MTYPE      CECTL_SDRAM64
#define EA_CE_CTL_0_RDSTRB     3
#define EA_CE_CTL_0_RDSETUP    0
#define EA_CE_CTL_0_RDHLD      0
#define EA_CE_CTL_0_WRSTRB     3
#define EA_CE_CTL_0_WRSETUP    0    
#define EA_CE_CTL_0_WRHLD      0
#define EA_CE_CTL_0_WRHLDMSB   0
#define EA_CE_CTL_0_TA         1
#define EA_CE_SEC_0_SYNCRL     CESEC_1CYCLE
#define EA_CE_SEC_0_SYNCWL     CESEC_0CYCLE
#define EA_CE_SEC_0_CEEXT      CESEC_ACTIVE
#define EA_CE_SEC_0_RENEN      CESEC_ADS
#define EA_CE_SEC_0_SNCCLK     CESEC_ECLKOUT2
    
    //CE1 Space:
#define EA_CE_CTL_1_MTYPE      CECTL_ASYNC8
#define EA_CE_CTL_1_RDSTRB     5
#define EA_CE_CTL_1_RDSETUP    0
#define EA_CE_CTL_1_RDHLD      3
#define EA_CE_CTL_1_WRSTRB     5
#define EA_CE_CTL_1_WRSETUP    0    
#define EA_CE_CTL_1_WRHLD      3
#define EA_CE_CTL_1_WRHLDMSB   0
#define EA_CE_CTL_1_TA         3
#define EA_CE_SEC_1_SYNCRL     CESEC_2CYCLE
#define EA_CE_SEC_1_SYNCWL     CESEC_0CYCLE
#define EA_CE_SEC_1_CEEXT      CESEC_INACTIVE
#define EA_CE_SEC_1_RENEN      CESEC_ADS
#define EA_CE_SEC_1_SNCCLK     CESEC_ECLKOUT1
    
    //CE2 Space:
#define EA_CE_CTL_2_MTYPE      CECTL_SYNC32
#define EA_CE_CTL_2_RDSTRB     3
#define EA_CE_CTL_2_RDSETUP    0
#define EA_CE_CTL_2_RDHLD      0
#define EA_CE_CTL_2_WRSTRB     3
#define EA_CE_CTL_2_WRSETUP    0   
#define EA_CE_CTL_2_WRHLD      0
#define EA_CE_CTL_2_WRHLDMSB   0
#define EA_CE_CTL_2_TA         1
#define EA_CE_SEC_2_SYNCRL     CESEC_1CYCLE
#define EA_CE_SEC_2_SYNCWL     CESEC_0CYCLE
#define EA_CE_SEC_2_CEEXT      CESEC_ACTIVE
#define EA_CE_SEC_2_RENEN      CESEC_ADS
#define EA_CE_SEC_2_SNCCLK     CESEC_ECLKOUT2
    
    //CE3 Space:
#define EA_CE_CTL_3_MTYPE      CECTL_SYNC32
#define EA_CE_CTL_3_RDSTRB     1
#define EA_CE_CTL_3_RDSETUP    0
#define EA_CE_CTL_3_RDHLD      0
#define EA_CE_CTL_3_WRSTRB     1
#define EA_CE_CTL_3_WRSETUP    0   
#define EA_CE_CTL_3_WRHLD      0
#define EA_CE_CTL_3_WRHLDMSB   0
#define EA_CE_CTL_3_TA         1
#define EA_CE_SEC_3_SYNCRL     CESEC_1CYCLE
#define EA_CE_SEC_3_SYNCWL     CESEC_0CYCLE
#define EA_CE_SEC_3_CEEXT      CESEC_ACTIVE
#define EA_CE_SEC_3_RENEN      CESEC_ADS
#define EA_CE_SEC_3_SNCCLK     CESEC_ECLKOUT2
    
    //SDRAM Control:
#define EA_SDRAM_CTL_TRC       15
#define EA_SDRAM_CTL_TRP       8
#define EA_SDRAM_CTL_TRCD      4
#define EA_SDRAM_CTL_INITI     SDCTL_YES 
#define EA_SDRAM_CTL_RFEN      SDCTL_DISABLE 
#define EA_SDRAM_CTL_SDCSZ     SDCTL_9COL 
#define EA_SDRAM_CTL_SDRSZ     SDCTL_11ROW 
#define EA_SDRAM_CTL_SDBSZ     SDCTL_2BANKS 
#define EA_SDRAM_CTL_SLFRFR    SDCTL_DISABLE
#define EA_SDRAM_TIM_CNTR      0                //R
#define EA_SDRAM_TIM_PERIOD    1500
#define EA_SDRAM_TIM_XRFR      SDTIM_2REFR_1h
    
    //SDRAM More Options:
#define EA_SDRAM_EXT_TCL       3
#define EA_SDRAM_EXT_TRAS      8
#define EA_SDRAM_EXT_TRRD      3 
#define EA_SDRAM_EXT_TWR       2
#define EA_SDRAM_EXT_THZP      3
#define EA_SDRAM_EXT_RD2RD     2
#define EA_SDRAM_EXT_RD2DEAC   4
#define EA_SDRAM_EXT_RD2WR     6
#define EA_SDRAM_EXT_R2WDQM    3
#define EA_SDRAM_EXT_WR2WR     2
#define EA_SDRAM_EXT_WR2DEAC   2
#define EA_SDRAM_EXT_WR2RD     2

//============================================================================
//                      External Memory Interface B
//============================================================================
    //Global Control:
#define EB_GBL_CTL_NOHOLD      GBLCTL_ENABLE
#define EB_GBL_CTL_CLK4EN      GBLCTL_ENABLE
#define EB_GBL_CTL_CLK6EN      GBLCTL_ENABLE
#define EB_GBL_CTL_EK1EN       GBLCTL_ENABLE
#define EB_GBL_CTL_EK2EN       GBLCTL_ENABLE
#define EB_GBL_CTL_EK1HZ       GBLCTL_HIGHZ
#define EB_GBL_CTL_EK2HZ       GBLCTL_CLK
#define EB_GBL_CTL_EK2RATE     GBLCTL_QUARCLK
#define EB_GBL_CTL_BRMODE      GBLCTL_MRSTATUS
#define EB_GBL_CTL_BUSREQ      0                //R
#define EB_GBL_CTL_ARDY        0                //R
#define EB_GBL_CTL_HOLD        0                //R
#define EB_GBL_CTL_HOLDA       0                //R
    
    //CE0 Space:
#define EB_CE_CTL_0_MTYPE      CECTL_ASYNC16
#define EB_CE_CTL_0_RDSTRB     6
#define EB_CE_CTL_0_RDSETUP    1
#define EB_CE_CTL_0_RDHLD      2
#define EB_CE_CTL_0_WRSTRB     6
#define EB_CE_CTL_0_WRSETUP    1    
#define EB_CE_CTL_0_WRHLD      2
#define EB_CE_CTL_0_WRHLDMSB   0
#define EB_CE_CTL_0_TA         2
#define EB_CE_SEC_0_SYNCRL     CESEC_1CYCLE
#define EB_CE_SEC_0_SYNCWL     CESEC_1CYCLE
#define EB_CE_SEC_0_CEEXT      CESEC_ACTIVE
#define EB_CE_SEC_0_RENEN      CESEC_ADS
#define EB_CE_SEC_0_SNCCLK     CESEC_ECLKOUT1
    
    //CE1 Space:
#define EB_CE_CTL_1_MTYPE      CECTL_ASYNC8
#define EB_CE_CTL_1_RDSTRB     10
#define EB_CE_CTL_1_RDSETUP    2
#define EB_CE_CTL_1_RDHLD      2
#define EB_CE_CTL_1_WRSTRB     10
#define EB_CE_CTL_1_WRSETUP    2    
#define EB_CE_CTL_1_WRHLD      2
#define EB_CE_CTL_1_WRHLDMSB   0
#define EB_CE_CTL_1_TA         3
#define EB_CE_SEC_1_SYNCRL     CESEC_2CYCLE
#define EB_CE_SEC_1_SYNCWL     CESEC_0CYCLE
#define EB_CE_SEC_1_CEEXT      CESEC_INACTIVE
#define EB_CE_SEC_1_RENEN      CESEC_ADS
#define EB_CE_SEC_1_SNCCLK     CESEC_ECLKOUT1
    
    //CE2 Space:
#define EB_CE_CTL_2_MTYPE      CECTL_ASYNC8
#define EB_CE_CTL_2_RDSTRB     30
#define EB_CE_CTL_2_RDSETUP    5
#define EB_CE_CTL_2_RDHLD      3
#define EB_CE_CTL_2_WRSTRB     30
#define EB_CE_CTL_2_WRSETUP    5    
#define EB_CE_CTL_2_WRHLD      3
#define EB_CE_CTL_2_WRHLDMSB   0
#define EB_CE_CTL_2_TA         3
#define EB_CE_SEC_2_SYNCRL     CESEC_1CYCLE
#define EB_CE_SEC_2_SYNCWL     CESEC_1CYCLE
#define EB_CE_SEC_2_CEEXT      CESEC_INACTIVE
#define EB_CE_SEC_2_RENEN      CESEC_ADS
#define EB_CE_SEC_2_SNCCLK     CESEC_ECLKOUT1
    
    //CE3 Space:
#define EB_CE_CTL_3_MTYPE      CECTL_ASYNC8
#define EB_CE_CTL_3_RDSTRB     63
#define EB_CE_CTL_3_RDSETUP    15
#define EB_CE_CTL_3_RDHLD      3
#define EB_CE_CTL_3_WRSTRB     63
#define EB_CE_CTL_3_WRSETUP    15   
#define EB_CE_CTL_3_WRHLD      3
#define EB_CE_CTL_3_WRHLDMSB   0
#define EB_CE_CTL_3_TA         3
#define EB_CE_SEC_3_SYNCRL     CESEC_2CYCLE
#define EB_CE_SEC_3_SYNCWL     CESEC_0CYCLE
#define EB_CE_SEC_3_CEEXT      CESEC_INACTIVE
#define EB_CE_SEC_3_RENEN      CESEC_ADS
#define EB_CE_SEC_3_SNCCLK     CESEC_ECLKOUT1
    
    //SDRAM Control:
#define EB_SDRAM_CTL_TRC       15
#define EB_SDRAM_CTL_TRP       8
#define EB_SDRAM_CTL_TRCD      4
#define EB_SDRAM_CTL_INITI     SDCTL_YES 
#define EB_SDRAM_CTL_RFEN      SDCTL_ENABLE 
#define EB_SDRAM_CTL_SDCSZ     SDCTL_9COL 
#define EB_SDRAM_CTL_SDRSZ     SDCTL_11ROW 
#define EB_SDRAM_CTL_SDBSZ     SDCTL_2BANKS 
#define EB_SDRAM_CTL_SLFRFR    SDCTL_DISABLE
#define EB_SDRAM_TIM_CNTR      0                //R
#define EB_SDRAM_TIM_PERIOD    1500
#define EB_SDRAM_TIM_XRFR      SDTIM_2REFR_1h
    
    //SDRAM More Options:
#define EB_SDRAM_EXT_TCL       3
#define EB_SDRAM_EXT_TRAS      8
#define EB_SDRAM_EXT_TRRD      3 
#define EB_SDRAM_EXT_TWR       2
#define EB_SDRAM_EXT_THZP      3
#define EB_SDRAM_EXT_RD2RD     2
#define EB_SDRAM_EXT_RD2DEAC   4
#define EB_SDRAM_EXT_RD2WR     6
#define EB_SDRAM_EXT_R2WDQM    3
#define EB_SDRAM_EXT_WR2WR     2
#define EB_SDRAM_EXT_WR2DEAC   2
#define EB_SDRAM_EXT_WR2RD     2

// ---------------------------------------------------------------------------

s_os_extension emif_e_init;

// ---------------------------------------------------------------------------
void emif_m448_15_comm_init()
{
// --- External Memory Interface A -------------------------------------------
    //EMIF Global Control Register (GBLCTL):
    REG_EMIFA_GBLCTL=((EA_GBL_CTL_EK2RATE&0x3)<<18)|((EA_GBL_CTL_EK2HZ&0x1)<<17)|((EA_GBL_CTL_EK2EN&0x1)<<16)|((EA_GBL_CTL_BRMODE&0x1)<<13)|((EA_GBL_CTL_BUSREQ&0x1)<<11)|((EA_GBL_CTL_ARDY&0x1)<<10)|((EA_GBL_CTL_HOLD&0x1)<<9)|((EA_GBL_CTL_HOLDA&0x1)<<8)|((EA_GBL_CTL_NOHOLD&0x1)<<7)|((EA_GBL_CTL_EK1HZ&0x1)<<6)|((EA_GBL_CTL_EK1EN&0x1)<<5)|((EA_GBL_CTL_CLK4EN&0x1)<<4)|((EA_GBL_CTL_CLK6EN&0x1)<<3);
    //EMIF CE Space Control Registers (CECTL0-3):
    REG_EMIFA_CECTL0=((EA_CE_CTL_0_WRSETUP&0xF)<<28)|((EA_CE_CTL_0_WRSTRB&0x3F)<<22)|((EA_CE_CTL_0_WRHLD&0x3)<<20)|((EA_CE_CTL_0_RDSETUP&0xF)<<16)|((EA_CE_CTL_0_TA&0x3)<<14)|((EA_CE_CTL_0_RDSTRB&0x3F)<<8)|((EA_CE_CTL_0_MTYPE&0xF)<<4)|((EA_CE_CTL_0_WRHLDMSB&0x1)<<3)|(EA_CE_CTL_0_RDHLD&0x7);
    REG_EMIFA_CECTL1=((EA_CE_CTL_1_WRSETUP&0xF)<<28)|((EA_CE_CTL_1_WRSTRB&0x3F)<<22)|((EA_CE_CTL_1_WRHLD&0x3)<<20)|((EA_CE_CTL_1_RDSETUP&0xF)<<16)|((EA_CE_CTL_1_TA&0x3)<<14)|((EA_CE_CTL_1_RDSTRB&0x3F)<<8)|((EA_CE_CTL_1_MTYPE&0xF)<<4)|((EA_CE_CTL_1_WRHLDMSB&0x1)<<3)|(EA_CE_CTL_1_RDHLD&0x7);
    REG_EMIFA_CECTL2=((EA_CE_CTL_2_WRSETUP&0xF)<<28)|((EA_CE_CTL_2_WRSTRB&0x3F)<<22)|((EA_CE_CTL_2_WRHLD&0x3)<<20)|((EA_CE_CTL_2_RDSETUP&0xF)<<16)|((EA_CE_CTL_2_TA&0x3)<<14)|((EA_CE_CTL_2_RDSTRB&0x3F)<<8)|((EA_CE_CTL_2_MTYPE&0xF)<<4)|((EA_CE_CTL_2_WRHLDMSB&0x1)<<3)|(EA_CE_CTL_2_RDHLD&0x7);
    REG_EMIFA_CECTL3=((EA_CE_CTL_3_WRSETUP&0xF)<<28)|((EA_CE_CTL_3_WRSTRB&0x3F)<<22)|((EA_CE_CTL_3_WRHLD&0x3)<<20)|((EA_CE_CTL_3_RDSETUP&0xF)<<16)|((EA_CE_CTL_3_TA&0x3)<<14)|((EA_CE_CTL_3_RDSTRB&0x3F)<<8)|((EA_CE_CTL_3_MTYPE&0xF)<<4)|((EA_CE_CTL_3_WRHLDMSB&0x1)<<3)|(EA_CE_CTL_3_RDHLD&0x7);
    //EMIF CE Space Secondary Control Registers (CESEC0-3):
    REG_EMIFA_CESEC0=((EA_CE_SEC_0_SNCCLK&0x1)<<6)|((EA_CE_SEC_0_RENEN&0x1)<<5)|((EA_CE_SEC_0_CEEXT&0x1)<<4)|((EA_CE_SEC_0_SYNCWL&0x3)<<2)|(EA_CE_SEC_0_SYNCRL&0x3);
    REG_EMIFA_CESEC1=((EA_CE_SEC_1_SNCCLK&0x1)<<6)|((EA_CE_SEC_1_RENEN&0x1)<<5)|((EA_CE_SEC_1_CEEXT&0x1)<<4)|((EA_CE_SEC_1_SYNCWL&0x3)<<2)|(EA_CE_SEC_1_SYNCRL&0x3);
    REG_EMIFA_CESEC2=((EA_CE_SEC_2_SNCCLK&0x1)<<6)|((EA_CE_SEC_2_RENEN&0x1)<<5)|((EA_CE_SEC_2_CEEXT&0x1)<<4)|((EA_CE_SEC_2_SYNCWL&0x3)<<2)|(EA_CE_SEC_2_SYNCRL&0x3);
    REG_EMIFA_CESEC3=((EA_CE_SEC_3_SNCCLK&0x1)<<6)|((EA_CE_SEC_3_RENEN&0x1)<<5)|((EA_CE_SEC_3_CEEXT&0x1)<<4)|((EA_CE_SEC_3_SYNCWL&0x3)<<2)|(EA_CE_SEC_3_SYNCRL&0x3);
    //EMIF SDRAM Control Register (SDCTL):
    REG_EMIFA_SDCTL=((EA_SDRAM_CTL_SDBSZ&0x1)<<30)|((EA_SDRAM_CTL_SDRSZ&0x3)<<28)|((EA_SDRAM_CTL_SDCSZ&0x3)<<26)|((EA_SDRAM_CTL_RFEN&0x1)<<25)|((EA_SDRAM_CTL_INITI&0x1)<<24)|((EA_SDRAM_CTL_TRCD&0xF)<<20)|((EA_SDRAM_CTL_TRP&0xF)<<16)|((EA_SDRAM_CTL_TRC&0xF)<<12)|(EA_SDRAM_CTL_SLFRFR&0x1);
    //EMIF SDRAM Timing Register (SDTIM):
    REG_EMIFA_SDTIM=((EA_SDRAM_TIM_XRFR&0x3)<<24)|((EA_SDRAM_TIM_CNTR&0xFFF)<<12)|(EA_SDRAM_TIM_PERIOD&0xFFF);
    //EMIF SDRAM Extension Register (SDEXT):
    REG_EMIFA_SDEXT=((EA_SDRAM_EXT_WR2RD&0x1)<<20)|((EA_SDRAM_EXT_WR2DEAC&0x3)<<18)|((EA_SDRAM_EXT_WR2WR&0x1)<<17)|((EA_SDRAM_EXT_R2WDQM&0x3)<<15)|((EA_SDRAM_EXT_RD2WR&0x7)<<12)|((EA_SDRAM_EXT_RD2DEAC&0x3)<<10)|((EA_SDRAM_EXT_RD2RD&0x1)<<9)|((EA_SDRAM_EXT_THZP&0x3)<<7)|((EA_SDRAM_EXT_TWR&0x3)<<5)|((EA_SDRAM_EXT_TRRD&0x1)<<4)|((EA_SDRAM_EXT_TRAS&0x7)<<1)|(EA_SDRAM_EXT_TCL&0x1);


// --- External Memory Interface B -------------------------------------------
    //EMIF Global Control Register (GBLCTL):
    REG_EMIFB_GBLCTL=((EB_GBL_CTL_EK2RATE&0x3)<<18)|((EB_GBL_CTL_EK2HZ&0x1)<<17)|((EB_GBL_CTL_EK2EN&0x1)<<16)|((EB_GBL_CTL_BRMODE&0x1)<<13)|((EB_GBL_CTL_BUSREQ&0x1)<<11)|((EB_GBL_CTL_ARDY&0x1)<<10)|((EB_GBL_CTL_HOLD&0x1)<<9)|((EB_GBL_CTL_HOLDA&0x1)<<8)|((EB_GBL_CTL_NOHOLD&0x1)<<7)|((EB_GBL_CTL_EK1HZ&0x1)<<6)|((EB_GBL_CTL_EK1EN&0x1)<<5)|((EB_GBL_CTL_CLK4EN&0x1)<<4)|((EB_GBL_CTL_CLK6EN&0x1)<<3);
    //EMIF CE Space Control Registers (CECTL0-3):
    REG_EMIFB_CECTL0=((EB_CE_CTL_0_WRSETUP&0xF)<<28)|((EB_CE_CTL_0_WRSTRB&0x3F)<<22)|((EB_CE_CTL_0_WRHLD&0x3)<<20)|((EB_CE_CTL_0_RDSETUP&0xF)<<16)|((EB_CE_CTL_0_TA&0x3)<<14)|((EB_CE_CTL_0_RDSTRB&0x3F)<<8)|((EB_CE_CTL_0_MTYPE&0xF)<<4)|((EB_CE_CTL_0_WRHLDMSB&0x1)<<3)|(EB_CE_CTL_0_RDHLD&0x7);
    REG_EMIFB_CECTL1=((EB_CE_CTL_1_WRSETUP&0xF)<<28)|((EB_CE_CTL_1_WRSTRB&0x3F)<<22)|((EB_CE_CTL_1_WRHLD&0x3)<<20)|((EB_CE_CTL_1_RDSETUP&0xF)<<16)|((EB_CE_CTL_1_TA&0x3)<<14)|((EB_CE_CTL_1_RDSTRB&0x3F)<<8)|((EB_CE_CTL_1_MTYPE&0xF)<<4)|((EB_CE_CTL_1_WRHLDMSB&0x1)<<3)|(EB_CE_CTL_1_RDHLD&0x7);
    REG_EMIFB_CECTL2=((EB_CE_CTL_2_WRSETUP&0xF)<<28)|((EB_CE_CTL_2_WRSTRB&0x3F)<<22)|((EB_CE_CTL_2_WRHLD&0x3)<<20)|((EB_CE_CTL_2_RDSETUP&0xF)<<16)|((EB_CE_CTL_2_TA&0x3)<<14)|((EB_CE_CTL_2_RDSTRB&0x3F)<<8)|((EB_CE_CTL_2_MTYPE&0xF)<<4)|((EB_CE_CTL_2_WRHLDMSB&0x1)<<3)|(EB_CE_CTL_2_RDHLD&0x7);
    REG_EMIFB_CECTL3=((EB_CE_CTL_3_WRSETUP&0xF)<<28)|((EB_CE_CTL_3_WRSTRB&0x3F)<<22)|((EB_CE_CTL_3_WRHLD&0x3)<<20)|((EB_CE_CTL_3_RDSETUP&0xF)<<16)|((EB_CE_CTL_3_TA&0x3)<<14)|((EB_CE_CTL_3_RDSTRB&0x3F)<<8)|((EB_CE_CTL_3_MTYPE&0xF)<<4)|((EB_CE_CTL_3_WRHLDMSB&0x1)<<3)|(EB_CE_CTL_3_RDHLD&0x7);
    //EMIF CE Space Secondary Control Registers (CESEC0-3):
    REG_EMIFB_CESEC0=((EB_CE_SEC_0_SNCCLK&0x1)<<6)|((EB_CE_SEC_0_RENEN&0x1)<<5)|((EB_CE_SEC_0_CEEXT&0x1)<<4)|((EB_CE_SEC_0_SYNCWL&0x3)<<2)|(EB_CE_SEC_0_SYNCRL&0x3);
    REG_EMIFB_CESEC1=((EB_CE_SEC_1_SNCCLK&0x1)<<6)|((EB_CE_SEC_1_RENEN&0x1)<<5)|((EB_CE_SEC_1_CEEXT&0x1)<<4)|((EB_CE_SEC_1_SYNCWL&0x3)<<2)|(EB_CE_SEC_1_SYNCRL&0x3);
    REG_EMIFB_CESEC2=((EB_CE_SEC_2_SNCCLK&0x1)<<6)|((EB_CE_SEC_2_RENEN&0x1)<<5)|((EB_CE_SEC_2_CEEXT&0x1)<<4)|((EB_CE_SEC_2_SYNCWL&0x3)<<2)|(EB_CE_SEC_2_SYNCRL&0x3);
    REG_EMIFB_CESEC3=((EB_CE_SEC_3_SNCCLK&0x1)<<6)|((EB_CE_SEC_3_RENEN&0x1)<<5)|((EB_CE_SEC_3_CEEXT&0x1)<<4)|((EB_CE_SEC_3_SYNCWL&0x3)<<2)|(EB_CE_SEC_3_SYNCRL&0x3);
    //EMIF SDRAM Control Register (SDCTL):
    REG_EMIFB_SDCTL=((EB_SDRAM_CTL_SDBSZ&0x1)<<30)|((EB_SDRAM_CTL_SDRSZ&0x3)<<28)|((EB_SDRAM_CTL_SDCSZ&0x3)<<26)|((EB_SDRAM_CTL_RFEN&0x1)<<25)|((EB_SDRAM_CTL_INITI&0x1)<<24)|((EB_SDRAM_CTL_TRCD&0xF)<<20)|((EB_SDRAM_CTL_TRP&0xF)<<16)|((EB_SDRAM_CTL_TRC&0xF)<<12)|(EB_SDRAM_CTL_SLFRFR&0x1);
    //EMIF SDRAM Timing Register (SDTIM):
    REG_EMIFB_SDTIM=((EB_SDRAM_TIM_XRFR&0x3)<<24)|((EB_SDRAM_TIM_CNTR&0xFFF)<<12)|(EB_SDRAM_TIM_PERIOD&0xFFF);
    //EMIF SDRAM Extension Register (SDEXT):
    REG_EMIFB_SDEXT=((EB_SDRAM_EXT_WR2RD&0x1)<<20)|((EB_SDRAM_EXT_WR2DEAC&0x3)<<18)|((EB_SDRAM_EXT_WR2WR&0x1)<<17)|((EB_SDRAM_EXT_R2WDQM&0x3)<<15)|((EB_SDRAM_EXT_RD2WR&0x7)<<12)|((EB_SDRAM_EXT_RD2DEAC&0x3)<<10)|((EB_SDRAM_EXT_RD2RD&0x1)<<9)|((EB_SDRAM_EXT_THZP&0x3)<<7)|((EB_SDRAM_EXT_TWR&0x3)<<5)|((EB_SDRAM_EXT_TRRD&0x1)<<4)|((EB_SDRAM_EXT_TRAS&0x7)<<1)|(EB_SDRAM_EXT_TCL&0x1);
}
// ---------------------------------------------------------------------------
OS_MODULE_INICIATOR( emif )
{
  OS_MODULE_INIT( emif )
  {
    ext_plug( &emif_e_init, SYSCALL_EMIF_INIT, (void*)(uint32)&emif_m448_15_comm_init );
  }
  OS_MODULE_DEINIT( emif ) { }
}
OS_MODULE_ACTIVATOR( emif );
// ---------------------------------------------------------------------------


