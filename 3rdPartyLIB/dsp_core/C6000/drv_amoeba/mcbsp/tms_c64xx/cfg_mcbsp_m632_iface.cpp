#include <rts.h>
#include "os_csl_mcbsp.h"

//-------------------------------------------------------------------
//----------------Настройки MCBSP для приемного канала---------------
//-------------------------------------------------------------------
MCBSP_Config iface_in_mcbspCfg = {
    MCBSP_SPCR_RMK(
        MCBSP_SPCR_FREE_YES,
        MCBSP_SPCR_SOFT_YES,
        MCBSP_SPCR_FRST_YES,
        MCBSP_SPCR_GRST_YES,
        MCBSP_SPCR_XINTM_XRDY,
        MCBSP_SPCR_XSYNCERR_NO,
        MCBSP_SPCR_XRST_YES,
        MCBSP_SPCR_DLB_OFF,
        MCBSP_SPCR_RJUST_RZF,
        MCBSP_SPCR_CLKSTP_DISABLE,
        MCBSP_SPCR_DXENA_OFF,
        MCBSP_SPCR_RINTM_RRDY,
        MCBSP_SPCR_RSYNCERR_NO,
        MCBSP_SPCR_RRST_YES
    ),

  MCBSP_RCR_RMK(
    MCBSP_RCR_RPHASE_SINGLE,
    MCBSP_RCR_RFRLEN2_OF(0),
    MCBSP_RCR_RWDLEN2_8BIT,
    MCBSP_RCR_RCOMPAND_MSB,
    MCBSP_RCR_RFIG_YES,
    MCBSP_RCR_RDATDLY_1BIT,
    MCBSP_RCR_RFRLEN1_OF(0),
    MCBSP_RCR_RWDLEN1_32BIT,
    MCBSP_RCR_RWDREVRS_DISABLE
  ),

  MCBSP_XCR_RMK(
    MCBSP_XCR_XPHASE_SINGLE,
    MCBSP_XCR_XFRLEN2_OF(0),
    MCBSP_XCR_XWDLEN2_8BIT,
    MCBSP_XCR_XCOMPAND_MSB,
    MCBSP_XCR_XFIG_YES,
    MCBSP_XCR_XDATDLY_1BIT,
    MCBSP_XCR_XFRLEN1_OF(0),
    MCBSP_XCR_XWDLEN1_32BIT,
    MCBSP_XCR_XWDREVRS_DISABLE
  ),

  MCBSP_SRGR_RMK(
    MCBSP_SRGR_GSYNC_SYNC,
    MCBSP_SRGR_CLKSP_FALLING,//RISING
    MCBSP_SRGR_CLKSM_INTERNAL,
    MCBSP_SRGR_FSGM_DXR2XSR,
    MCBSP_SRGR_FPER_OF(15),
    MCBSP_SRGR_FWID_OF(0),
    MCBSP_SRGR_CLKGDV_OF(0)
  ),

  MCBSP_MCR_DEFAULT,
  MCBSP_RCERE0_DEFAULT,
  MCBSP_RCERE1_DEFAULT,
  MCBSP_RCERE2_DEFAULT,
  MCBSP_RCERE3_DEFAULT,
  MCBSP_XCERE0_DEFAULT,
  MCBSP_XCERE1_DEFAULT,
  MCBSP_XCERE2_DEFAULT,
  MCBSP_XCERE3_DEFAULT,

  MCBSP_PCR_RMK(
    MCBSP_PCR_XIOEN_SP,
    MCBSP_PCR_RIOEN_SP,
    MCBSP_PCR_FSXM_EXTERNAL,
    MCBSP_PCR_FSRM_EXTERNAL,
    MCBSP_PCR_CLKXM_INPUT,
    MCBSP_PCR_CLKRM_INPUT,
    MCBSP_PCR_CLKSSTAT_0,
    MCBSP_PCR_DXSTAT_0,
    MCBSP_PCR_FSXP_ACTIVEHIGH,
    MCBSP_PCR_FSRP_ACTIVEHIGH,
    MCBSP_PCR_CLKXP_RISING,
    MCBSP_PCR_CLKRP_FALLING
  )
};
//-------------------------------------------------------------------
//--------------Настройки MCBSP для передающего канала---------------
//-------------------------------------------------------------------
MCBSP_Config iface_out_mcbspCfg = {
  MCBSP_SPCR_RMK(
    MCBSP_SPCR_FREE_YES,
    MCBSP_SPCR_SOFT_YES,
    MCBSP_SPCR_FRST_YES,
    MCBSP_SPCR_GRST_YES,
    MCBSP_SPCR_XINTM_XRDY,
    MCBSP_SPCR_XSYNCERR_NO,
    MCBSP_SPCR_XRST_YES,
    MCBSP_SPCR_DLB_OFF,
    MCBSP_SPCR_RJUST_RZF,
    MCBSP_SPCR_CLKSTP_DISABLE,
    MCBSP_SPCR_DXENA_OFF,
    MCBSP_SPCR_RINTM_RRDY,
    MCBSP_SPCR_RSYNCERR_NO,
    MCBSP_SPCR_RRST_YES
  ),

  MCBSP_RCR_RMK(
    MCBSP_RCR_RPHASE_SINGLE,
    MCBSP_RCR_RFRLEN2_OF(0),
    MCBSP_RCR_RWDLEN2_8BIT,
    MCBSP_RCR_RCOMPAND_MSB,
    MCBSP_RCR_RFIG_NO,
    MCBSP_RCR_RDATDLY_1BIT,
    MCBSP_RCR_RFRLEN1_OF(0),
    MCBSP_RCR_RWDLEN1_32BIT,
    MCBSP_RCR_RWDREVRS_DISABLE
  ),

  MCBSP_XCR_RMK(
    MCBSP_XCR_XPHASE_SINGLE,
    MCBSP_XCR_XFRLEN2_OF(0),
    MCBSP_XCR_XWDLEN2_8BIT,
    MCBSP_XCR_XCOMPAND_MSB,
    MCBSP_XCR_XFIG_NO,
    MCBSP_XCR_XDATDLY_1BIT,
    MCBSP_XCR_XFRLEN1_OF(0),
    MCBSP_XCR_XWDLEN1_32BIT,
    MCBSP_XCR_XWDREVRS_DISABLE
  ),

  MCBSP_SRGR_RMK(
    MCBSP_SRGR_GSYNC_FREE,
    MCBSP_SRGR_CLKSP_RISING,
    MCBSP_SRGR_CLKSM_INTERNAL,
    MCBSP_SRGR_FSGM_DXR2XSR,
    MCBSP_SRGR_FPER_OF(15),
    MCBSP_SRGR_FWID_OF(0),
    MCBSP_SRGR_CLKGDV_OF(11)// 17 - 10Mhz, 11 - 15Mhz, 9 - 18Mhz
  ),

  MCBSP_MCR_DEFAULT,
  MCBSP_RCERE0_DEFAULT,
  MCBSP_RCERE1_DEFAULT,
  MCBSP_RCERE2_DEFAULT,
  MCBSP_RCERE3_DEFAULT,
  MCBSP_XCERE0_DEFAULT,
  MCBSP_XCERE1_DEFAULT,
  MCBSP_XCERE2_DEFAULT,
  MCBSP_XCERE3_DEFAULT,

  MCBSP_PCR_RMK(
    MCBSP_PCR_XIOEN_SP,
    MCBSP_PCR_RIOEN_SP,
    MCBSP_PCR_FSXM_INTERNAL,
    MCBSP_PCR_FSRM_EXTERNAL,
    MCBSP_PCR_CLKXM_OUTPUT,
    MCBSP_PCR_CLKRM_OUTPUT,//OUTPUT
    MCBSP_PCR_CLKSSTAT_0,
    MCBSP_PCR_DXSTAT_0,
    MCBSP_PCR_FSXP_ACTIVEHIGH,
    MCBSP_PCR_FSRP_ACTIVEHIGH,
    MCBSP_PCR_CLKXP_RISING,
    MCBSP_PCR_CLKRP_FALLING
  )
};

//-------------------------------------------------------------------
//---------------Настройки EDMA для передающего канала---------------
//-------------------------------------------------------------------
EDMA_Config iface_out_edmaCfg =
{
    //Making Options parameter register - EDMA_OPT
    EDMA_OPT_RMK
    (
        EDMA_OPT_PRI_URGENT,
        EDMA_OPT_ESIZE_32BIT,
        EDMA_OPT_2DS_NO,
        EDMA_OPT_SUM_INC,
        EDMA_OPT_2DD_NO,
        EDMA_OPT_DUM_NONE,
        EDMA_OPT_TCINT_YES,
        EDMA_OPT_TCC_OF(0),
        EDMA_OPT_TCCM_OF(0),
        EDMA_OPT_ATCINT_NO,
        EDMA_OPT_ATCC_OF(0),
        EDMA_OPT_PDTS_DISABLE,
        EDMA_OPT_PDTD_DISABLE,
        EDMA_OPT_LINK_YES,
        EDMA_OPT_FS_NO
    ),
    EDMA_SRC_OF(NULL),//Source address register 
    EDMA_CNT_OF(0),   //Transfer count parameter
    EDMA_DST_OF(NULL),      //Destination address parameter
    EDMA_IDX_OF(0x00000002),//Index parameter
    EDMA_RLD_OF(0x00000000) //Count reload/link parameter
};
//-------------------------------------------------------------------
//-----------------Настройки EDMA для приемного канала---------------
//-------------------------------------------------------------------
EDMA_Config iface_in_edmaCfg =
{
    //Making Options parameter register - EDMA_OPT
    EDMA_OPT_RMK
    (
        EDMA_OPT_PRI_URGENT,
        EDMA_OPT_ESIZE_32BIT,
        EDMA_OPT_2DS_NO,
        EDMA_OPT_SUM_NONE,
        EDMA_OPT_2DD_NO,
        EDMA_OPT_DUM_INC,
        EDMA_OPT_TCINT_YES,
        EDMA_OPT_TCC_OF(0),
        EDMA_OPT_TCCM_OF(0),
        EDMA_OPT_ATCINT_NO,
        EDMA_OPT_ATCC_OF(0),
        EDMA_OPT_PDTS_DISABLE,
        EDMA_OPT_PDTD_DISABLE,
        EDMA_OPT_LINK_YES,
        EDMA_OPT_FS_NO
    ),
    EDMA_SRC_OF(NULL),//Source address register 
    EDMA_CNT_OF(0),   //Transfer count parameter
    EDMA_DST_OF(NULL),      //Destination address parameter
    EDMA_IDX_OF(0x00000000),//Index parameter
    EDMA_RLD_OF(0x00000000) //Count reload/link parameter
};


