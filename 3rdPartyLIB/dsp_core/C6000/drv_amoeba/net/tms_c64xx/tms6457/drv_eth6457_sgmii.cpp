
#include <drv_eth6457_sgmii.h>
#include <drv_eth6457_emac.h>


int32 SGMII_reset()
{

    uint64 tms = time_core();

    CSL_FINST( SGMII_REGS->SOFT_RESET, SGMII_SOFT_RESET_SOFT_RESET, YES );
    while( SGMII_REGS->SOFT_RESET != 0x00000000 )   // дождаться сброса sgmii
    {
        if( (time_core() - tms) > 10 )
    	{
            return OSE_TIMEOUT;
        }
    }

    return OSE_OK;
}

uint32 SGMII_config( SGMII_Config *config )
{
    volatile uint32 val, tempReg;

    if( config->loopbackEn )
    {
        CSL_FINS( SGMII_REGS->CONTROL, SGMII_CONTROL_MR_AN_ENABLE, 0 );
        CSL_FINST( SGMII_REGS->SOFT_RESET, SGMII_SOFT_RESET_RT_SOFT_RESET, YES );
        CSL_FINST( SGMII_REGS->CONTROL, SGMII_CONTROL_LOOPBACK, YES );
        CSL_FINST( SGMII_REGS->SOFT_RESET, SGMII_SOFT_RESET_RT_SOFT_RESET, NO );
    }
    else
    {
        if( (config->masterEn) && (config->modeOfOperation == SGMII_MODE_OF_OPERATION_WITH_AN) )
        {
            SGMII_REGS->MR_ADV_ABILITY = 0xD8A1;    //0x9801; /* Advertise fullduplex gigabit */
            SGMII_REGS->CONTROL = CSL_FMKT( SGMII_CONTROL_MASTER, MASTER ) |
                                  CSL_FMKT( SGMII_CONTROL_MR_AN_ENABLE, YES );
		    CSL_FINST( EMAC_REGS->MACCONTROL, EMAC_MACCONTROL_EXT_EN, ENABLE );
        }
        else if( (!(config->masterEn)) && (config->modeOfOperation == SGMII_MODE_OF_OPERATION_WITH_AN) )
        {
            SGMII_REGS->MR_ADV_ABILITY = 0x01; /* Advertise fullduplex gigabit */
            SGMII_REGS->CONTROL = CSL_FMKT( SGMII_CONTROL_MASTER, SLAVE ) |
                                  CSL_FMKT( SGMII_CONTROL_MR_AN_ENABLE, YES );
		    CSL_FINST( EMAC_REGS->MACCONTROL, EMAC_MACCONTROL_EXT_EN, ENABLE );
        }else if( (config->masterEn) && (config->modeOfOperation == SGMII_MODE_OF_OPERATION_WITHOUT_AN) )
        {
            SGMII_REGS->MR_ADV_ABILITY = 0xD8A1;    //0x9801; /* Advertise fullduplex gigabit */
            SGMII_REGS->CONTROL = CSL_FMKT( SGMII_CONTROL_MASTER, MASTER ) |
                                  CSL_FMK( SGMII_CONTROL_MR_AN_ENABLE, 0 );
		    CSL_FINST( EMAC_REGS->MACCONTROL, EMAC_MACCONTROL_EXT_EN, ENABLE );
        }
        else
        {
            SGMII_REGS->MR_ADV_ABILITY = 0x01; /* Advertise fullduplex gigabit */
            SGMII_REGS->CONTROL = CSL_FMKT( SGMII_CONTROL_MASTER, SLAVE ) |
                                  CSL_FMKT( SGMII_CONTROL_MR_AN_ENABLE, YES );
		    CSL_FINST( EMAC_REGS->MACCONTROL, EMAC_MACCONTROL_EXT_EN, ENABLE );
        }
    }

	SGMII_REGS->AUX_CFG = config->auxConfig;
	/* wait for 2 usfor PLL to lock */
	for( val = 0; val < 1000; val++ )
	    asm(" NOP 5 ");

    SGMII_REGS->TX_CFG = config->txConfig;

	/* Toggle ENFTP bit */
	SGMII_REGS->TX_CFG = config->txConfig | 0x1000;

	for( val = 0; val < 10; val++ )
	    asm(" NOP 5 ");

	SGMII_REGS->TX_CFG = config->txConfig & (~(1 << 12));

    SGMII_REGS->RX_CFG = config->rxConfig;

    return 0;
}


uint32 SGMII_getStatus( SGMII_Status *status )
{
    if( !status )
    {
        return SGMII_ERROR_INVALID;
    }
    status->txCfgStatus = SGMII_REGS->TX_CFG;
    status->rxCfgStatus = SGMII_REGS->RX_CFG;
    status->auxCfgStatus = SGMII_REGS->AUX_CFG;
    return 0;
}


uint32 SGMII_getLinkPartnerStatus()
{

    if( CSL_FEXT(SGMII_REGS->STATUS, SGMII_STATUS_MR_AN_COMPLETE) )
    {
        return( SGMII_REGS->MR_LP_ADV_ABILITY & 0xFFFF );
    }

    return SGMII_ERROR_DEVICE;
}


uint32 SGMII_getAnErrorStatus()
{
    return CSL_FEXT( SGMII_REGS->STATUS, SGMII_STATUS_AN_ERROR );
}


uint32 SGMII_getStatusReg()
{
    uint32 status;

    status = SGMII_REGS->STATUS;
    return status;
}



