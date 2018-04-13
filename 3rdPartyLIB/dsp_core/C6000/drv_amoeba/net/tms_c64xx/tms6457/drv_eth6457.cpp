// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp1251
// !: d: Модуль содержит реализацию функций драйвера сетевого контроллера.
// !: -:[drv_eth6457.cpp] 
// ---------------------------------------------------------------------------
#include <drv_eth6457.h>
#include <drv_eth6457_emac.h>
#include <drv_eth6457_sgmii.h>

#include <net_packet_parser.h>

#include <rts.h>

// ---------------------------------------------------------------------------

//************************************************
//       
//************************************************
#define FRAME_SIZE 2048

#pragma DATA_SECTION(".netcard")
char sgmii_mem[sizeof(SGMII_Config)]; 

#pragma DATA_SECTION(".netcard")
char pkt_rx_mem[sizeof(EMAC_Pkt)*64];

#pragma DATA_SECTION(".netcard")
char pkt_tx_mem[sizeof(EMAC_Pkt)*64];

#pragma DATA_SECTION(".netcard")
char net_buf[0x41000];


Handle hEMAC = NULL;
// ---------------------------------------------------------------------------

//*******************************
//       Прототипы функций
//*******************************
int32 NetcardInit(EMAC_Device *pd);

static EMAC_Pkt *Queue_pop( uint32 *pintrpt, PKTQ *pq );
static void Queue_push( uint32 *pintrpt, PKTQ *pq, EMAC_Pkt *pPktHdr );

int32 lbk_test( EMAC_Device * pd, uint8 value );
void emac_deinit( EMAC_Device *pd );

void HwRxInt(void);
void HwTxInt(void);
void T1Int(void);

// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------
// !: fn: int32 eth6457_open ( s_os_driver_descriptor* d, uint16 access )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция не используется. <br>
// !: d: В случае вызова, возвращает стандартный код ошибки OSE_BAD_CMD.
// !: -:
// ---------------------------------------------------------------------------
int32 eth6457_open ( s_os_driver_descriptor* d, uint16 access )
{
  return OSE_BAD_CMD;
}

// ---------------------------------------------------------------------------
// !: fn: int32 eth6457_close ( s_os_driver_descriptor* d )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция не используется. <br>
// !: d: В случае вызова, возвращает стандартный код ошибки OSE_BAD_CMD.
// !: -:
// ---------------------------------------------------------------------------
int32 eth6457_close ( s_os_driver_descriptor* d )
{
  return OSE_BAD_CMD;
}

// ---------------------------------------------------------------------------
// !: fn: int32 eth6457_read ( s_os_driver_descriptor* d, void* buf, int32 length )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция не используется. <br>
// !: d: В случае вызова, возвращает стандартный код ошибки OSE_BAD_CMD.
// !: -:
// ---------------------------------------------------------------------------
int32 eth6457_read ( s_os_driver_descriptor* d, void* buf, int32 length )
{
  return OSE_BAD_CMD;
}

// ---------------------------------------------------------------------------
// !: fn: int32 eth6457_write ( s_os_driver_descriptor* d, const void* buf, int32 length )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция не используется. <br>
// !: d: В случае вызова, возвращает стандартный код ошибки OSE_BAD_CMD.
// !: -:
// ---------------------------------------------------------------------------
int32 eth6457_write ( s_os_driver_descriptor* d, const void* buf, int32 length )
{
  return OSE_BAD_CMD;
}

// ---------------------------------------------------------------------------
// !: fn: int32 eth6457_ioctl ( s_os_driver_descriptor* d, int32 cmd, const void* arg )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция используется для выполнения управляющих воздействий
// !: d: над драйвером сетевого контроллера. <br>
// !: d:
// !: d: Поддерживаются стандартные управляющие воздействия cmd: <br>
// !: d: IOC_INIT, IOC_DEINIT, IOC_INODE_SELECT. <br>
// !: d: Остальные стандартные управляющие воздействия не поддерживаются. <br>
// !: d: 
// !: d: Кроме стандартных, функция поддерживает собственные управляющие
// !: d: воздействия: <br>
// !: d: NET_READ_REG    - ; <br>
// !: d: NET_WRITE_REG   - ; <br>
// !: d: EMAC_RW_REG     - ; <br>
// !: d: PHY_RW_REG      - . <br>
// !: d: 
// !: d: В случае успеха возвращает OSE_OK, иначе, кроме стандартных ошибок: <br>
// !: d: ERROR_NO_PHY       - отсутствует связь с сетевым контроллером; <br>
// !: d: ERROR_RESET_PHY    - ; <br>
// !: d: ERROR_TIMEOUT_PHY  - ; <br>
// !: d: ERROR_LOOPBACK_PHY - ; <br>
// !: d: ERROR_READ_PHY     - ; <br>
// !: d: ERROR_WRITE_PHY    - ; <br>
// !: d: ERROR_TEST_LINK    - ; <br>
// !: d: 
// !: d: Данная функция доступна пользователю.
// !: -:
// ---------------------------------------------------------------------------
int32 eth6457_ioctl ( s_os_driver_descriptor* d, int32 cmd, const void* arg )
{
    int32 error = OSE_OK;

    switch(cmd)
    {
        //================================
        //Standard control command:
        //================================
        case IOC_INIT_DESCRIPTOR:
        case IOC_DEINIT_DESCRIPTOR:
        break;

        case IOC_INIT:
        {
            uint32 i;
            uint32 quant_value;

            //------------------------------------
            s_os_driver_context* dctx = (s_os_driver_context*)const_cast<void*>( arg );
            EMAC_Device* pdev = (EMAC_Device*)dctx->data;
            EMAC_Config* econf = &pdev->Config;

            pdev->old_link = false;
            pdev->pkt_prznt = false;
            //------------------------------------
            if( (econf->RxMaxPktPool == 0) || (econf->TxMaxPktPool == 0) )
            {
                return OSE_BAD_PARAM;
            }

            //  GPIO config
            REG_GPIO_DIR |= ( GPIO_1 | GPIO_2 | GPIO_3 );

            REG_GPIO_CLR_DATA = GPIO_7;
            REG_GPIO_SET_DATA = ( GPIO_4 | GPIO_8 );
            
            REG_GPIO_DIR &= ~( GPIO_4 | GPIO_7 | GPIO_8 );

            if( (REG_GPIO_IN_DATA & GPIO_2) != 0x0 )
            {
                return OSE_NO_DEVICE;
            }

            //  Allocate Semaphore
            pdev->smphr = sem_alloc( 1, NULL );
            if( pdev->smphr == RES_VOID )
            {
                error = OSE_CANT_CREATE_SEM;
                goto net_init_fail;
            }
            //  Allocate Rx Interrupt
            pdev->rx_intrpt = int_alloc( INT_MACRXINT, &HwRxInt );
            if (pdev->rx_intrpt == RES_VOID)
            {
                error = OSE_CANT_CREATE_INTERRUPT;
                goto net_init_fail;
            }
            //  Allocate Tx Interrupt
            pdev->tx_intrpt = int_alloc( INT_MACTXINT, &HwTxInt );
            if (pdev->tx_intrpt == RES_VOID)
            {
                error = OSE_CANT_CREATE_INTERRUPT;
                goto net_init_fail;
            }
            //  Allocate Timer1 Interrupt
            pdev->t1_intrpt = int_alloc( INT_TINTLO1, &T1Int );
            if (pdev->t1_intrpt == RES_VOID)
            {
                error = OSE_CANT_CREATE_INTERRUPT;
                goto net_init_fail;
            }

            //------------------------------------
            //  Allocate Memory
            pdev->hSgmii = (SGMII_Config*)sgmii_mem;
            pdev->pkt_rx = (EMAC_Pkt*)pkt_rx_mem; 
            pdev->pkt_tx = (EMAC_Pkt*)pkt_tx_mem;
			/*
            pdev->hSgmii = (SGMII_Config*)heap_alloc( NULL, sizeof(SGMII_Config), HEAP_ALIGN_8 );
            if( !pdev->hSgmii ) 
            {
                error = OSE_NO_MEMORY;
                goto net_init_fail;
            }
                       
            pdev->pkt_rx = (EMAC_Pkt*)heap_alloc( NULL, sizeof(EMAC_Pkt) * econf->RxMaxPktPool, HEAP_ALIGN_8 );
            if( pdev->pkt_rx == NULL )
            {
                error = OSE_NO_MEMORY;
                goto net_init_fail;
            }
            pdev->pkt_tx = (EMAC_Pkt*)heap_alloc( NULL, sizeof(EMAC_Pkt) * econf->TxMaxPktPool, HEAP_ALIGN_8 );
            if( pdev->pkt_tx == NULL )
            {
                error = OSE_NO_MEMORY;
                goto net_init_fail;
            }
			*/
          
            pdev->pkt_data = (uint8*)net_buf;
/*
            pdev->pkt_data = (uint8*)heap_alloc( NULL, FRAME_SIZE * (econf->RxMaxPktPool + econf->TxMaxPktPool ), HEAP_ALIGN_8 );
            if( pdev->pkt_data == NULL )
            {
                error = OSE_NO_MEMORY;
                goto net_init_fail;
            }
*/
           
            //  clear all allocated memory
            memset( pdev->pkt_rx, 0, sizeof(EMAC_Pkt) * econf->RxMaxPktPool );
            memset( pdev->pkt_tx, 0, sizeof(EMAC_Pkt) * econf->TxMaxPktPool );
            memset( pdev->pkt_data, 0, FRAME_SIZE * ( econf->RxMaxPktPool + econf->TxMaxPktPool ) );

            //------------------------------------
            // Queue up some initialized receive buffers /
            for( i=0; i < (econf->RxMaxPktPool); i++ )
            {
                pdev->pkt_rx[i].prev = pdev->pkt_rx;
                                pdev->pkt_rx[i].size = 1514;
                pdev->pkt_rx[i].data = &pdev->pkt_data[i * FRAME_SIZE];
                Queue_push( &pdev->rx_intrpt, &pdev->RxQueue, &pdev->pkt_rx[i] );
            }
            // Queue up some transmit buffers /
            for( i=0; i < (pdev->Config.TxMaxPktPool); i++ )
            {
                pdev->pkt_tx[i].prev = pdev->pkt_tx;
                                pdev->pkt_tx[i].size = 1514;
                pdev->pkt_tx[i].data = &pdev->pkt_data[(econf->RxMaxPktPool + i) * FRAME_SIZE];
                Queue_push( &pdev->tx_intrpt, &pdev->TxQueue, &pdev->pkt_tx[i] );
            }

            //**************************************************
            // Initialize EMAC setup  /
            //
            //Configuration Mode Flags:
            //CfgModeFlags Configuration Mode Flags
			// EMAC_CONFIG_MODEFLG_CHPRIORITY          0x00001     // Use Tx channel priority
			// EMAC_CONFIG_MODEFLG_MACLOOPBACK         0x00002     // MAC internal loopback
			// EMAC_CONFIG_MODEFLG_RXCRC               0x00004     // Include CRC in RX frames
			// EMAC_CONFIG_MODEFLG_TXCRC               0x00008     // Tx frames include CRC
			// EMAC_CONFIG_MODEFLG_PASSERROR           0x00010     // Pass error frames
			// EMAC_CONFIG_MODEFLG_PASSCONTROL         0x00020     // Pass control frames
			// EMAC_CONFIG_MODEFLG_PASSALL             0x00040     // pass all frames
			// EMAC_CONFIG_MODEFLG_RXQOS               0x00080     // Enable QOS at receive side
			// EMAC_CONFIG_MODEFLG_RXNOCHAIN           0x00100     // Select no buffer chaining
			// EMAC_CONFIG_MODEFLG_RXOFFLENBLOCK       0x00200     // Enable offset/length blocking
			// EMAC_CONFIG_MODEFLG_RXOWNERSHIP         0x00400     // Use ownership bit as 1
			// EMAC_CONFIG_MODEFLG_RXFIFOFLOWCNTL      0x00800     // Enable rx fifo flow control
			// EMAC_CONFIG_MODEFLG_CMDIDLE             0x01000     // Enable IDLE command
			// EMAC_CONFIG_MODEFLG_TXSHORTGAPEN        0x02000     // Enable tx short gap
			// EMAC_CONFIG_MODEFLG_TXPACE              0x04000     // Enable tx pacing
			// EMAC_CONFIG_MODEFLG_TXFLOWCNTL          0x08000     // Enable tx flow control
			// EMAC_CONFIG_MODEFLG_RXBUFFERFLOWCNTL    0x10000     // Enable rx buffer flow control
			// EMAC_CONFIG_MODEFLG_FULLDUPLEX          0x20000     // Set full duplex mode
			// EMAC_CONFIG_MODEFLG_GIGABIT             0x40000     // Set gigabit
			// EMAC_CONFIG_MODEFLG_EXTEN               0x80000     // Set external enable bit

            econf->ModeFlags = EMAC_CONFIG_MODEFLG_RXNOCHAIN | EMAC_CONFIG_MODEFLG_PASSALL
                             | EMAC_CONFIG_MODEFLG_FULLDUPLEX | EMAC_CONFIG_MODEFLG_MACLOOPBACK
                             | EMAC_CONFIG_MODEFLG_GIGABIT;
            econf->PktMTU = 1514;

            //--------------------------------------------------
            
            //**************************************************
            error = EMAC_open( (Handle)dctx->name, econf, pdev );
            if( error != OSE_OK )
            {
                goto net_init_fail;     // printf("EMAC OPEN Returned error \n");
            }
            
            hEMAC = pdev;
            //  Setup receive filter
            EMAC_setReceiveFilter( pdev, EMAC_RXFILTER_ALL );

            REG_GPIO_CLR_DATA = ( GPIO_4 );

            if( SGMII_reset() != OSE_OK )
            {
                error = OSE_TIMEOUT;
                goto net_init_fail;
            }

            pdev->hSgmii->masterEn   = 0x1;
            pdev->hSgmii->loopbackEn = 0x0;//this is for external loop back, for internal pass 1
            pdev->hSgmii->txConfig   = 0x00000e21;
            pdev->hSgmii->rxConfig   = 0x00081021;
            pdev->hSgmii->auxConfig  = 0x0000000b;
            pdev->hSgmii->modeOfOperation = SGMII_MODE_OF_OPERATION_WITH_AN;

            SGMII_config( pdev->hSgmii );

            SGMII_REGS->CONTROL |= 0x1; // Loopback mode is selected

//            SGMII_REGS->MR_ADV_ABILITY = 0x9801;  // full dupex and Gig bits are set

            sys_regget( OSSYSQUANT, &quant_value );

            REG_PRDLO1 = quant_value * 100;
            REG_TCR1 = TCR_ENAMODE_LO_ENABLED | TCR_CLKSRC_LO_INTERNAL | TCR_CP_LO_PULSE | TCR_PWID_LO_1 |
                       TCR_ENAMODE_HI_DISABLED;
            REG_TGCR1 = TGCR_TIMMODE_32UNCHAINED | TGCR_TIMLORS;


            //  @b Interrupt_init
            //  Registering Interrupts and Enabling global interrupts.
            res_share( pdev->rx_intrpt );
            res_share( pdev->tx_intrpt );
            int_unlock( pdev->rx_intrpt );
            int_unlock( pdev->tx_intrpt );
            int_unlock( pdev->t1_intrpt );

            if( econf->ModeFlags & EMAC_CONFIG_MODEFLG_MACLOOPBACK )
            {

                //----------------------------------------
                error = lbk_test( pdev, 0x55 );
                if( error != OSE_OK )
                    goto net_init_fail;
                //----------------------------------------
                error = lbk_test( pdev, 0xAA );
                if( error != OSE_OK )
                    goto net_init_fail;
                //----------------------------------------            
                error = lbk_test( pdev, 0xFF );
                if( error != OSE_OK )
                    goto net_init_fail;
                //----------------------------------------            

                // Отключение loopbak и включение нормальной работы
                econf->ModeFlags &= ~EMAC_CONFIG_MODEFLG_MACLOOPBACK;      // Configuation Mode Flags
                CSL_FINST(EMAC_REGS->MACCONTROL, EMAC_MACCONTROL_LOOPBACK, DISABLE);
            }

net_init_fail:
            if( error )
            {
                emac_deinit( pdev );
            }
                //------------------------------------
        }
        break;

        case IOC_DEINIT:
        {
            //------------------------------------
            EMAC_Device* pdev = (EMAC_Device*)d->ctx->data;
            
            emac_deinit( pdev );
        }
        break;
        
        case IOC_INODE_SELECT:
        {
            if( arg == NULL ) return OSE_NULL_PARAM;

            char* dst = (char*)const_cast<void*>( arg );
      
            if( strcmp( dst, "." ) == 0 ) break;
            if( strcmp( dst, ".." ) != 0 ) return OSE_NO_NODE;
            drv_dec( d );
            drv_rfs( d );
        }
        break;


        //===============================================================
        //Driver control command:
        //===============================================================
        case NET_RECV_GET:                      //      Забрать принятый пакет
        {
            if( arg == NULL ) return OSE_NULL_PARAM;
            if( d->ctx->data == NULL ) return OSE_BAD_DCTX;
            EMAC_Device* dctxdata = (EMAC_Device*)d->ctx->data;
            EMAC_Pkt **pPktRx = (EMAC_Pkt **)const_cast<void*>(arg);
            *pPktRx = NULL;

            if( dctxdata->RxQueue.Count > 0 )
            {
//extern uint32 hgpio1;
//extern void DebugPin(uint32 hgpio,int32 num_gpio,int32 value);
//DebugPin(hgpio1,0,1);

                sem_lock( dctxdata->smphr, SEM_INFINITY );

                *pPktRx = Queue_pop( &dctxdata->rx_intrpt, &dctxdata->RxQueue );
                if( netpp_parse( dctxdata->ncfg, (net_descriptor*)*pPktRx ) != NETPP_OK )
                {
                    emacRxPutPkt( &dctxdata->RxCh[0], *pPktRx );
                    *pPktRx = NULL;
                }
                sem_unlock( dctxdata->smphr );                        
//DebugPin(hgpio1,0,0);
            }
        }
        break;
        
        
        case NET_RECV_PUT:                      //      Поставить свободный пакет на прием
        {
            if( arg == NULL ) return OSE_NULL_PARAM;
            if( d->ctx->data == NULL ) return OSE_BAD_DCTX;
            EMAC_Device* dctxdata = (EMAC_Device*)d->ctx->data;
            EMAC_Pkt **pPktRx = (EMAC_Pkt **)const_cast<void*>(arg);
            if( *pPktRx == NULL ) return OSE_BAD_PARAM;    //  Проверить наличие пакета

            sem_lock( dctxdata->smphr, SEM_INFINITY );
//            int_lock( dctxdata->intrpt );
            emacRxPutPkt( &dctxdata->RxCh[0], *pPktRx );
//            int_unlock( dctxdata->intrpt );
            sem_unlock( dctxdata->smphr );
        }
        break;


        case NET_SEND_GET:                      //      Получить свободный пакет на передачу
        {
            if( arg == NULL ) return OSE_NULL_PARAM;
            if( d->ctx->data == NULL ) return OSE_BAD_DCTX;
            EMAC_Device* dctxdata = (EMAC_Device*)d->ctx->data;
            EMAC_Pkt **pPktTx = (EMAC_Pkt **)const_cast<void*>(arg);
            *pPktTx = NULL;

            if( dctxdata->TxQueue.Count > 0 )
            {
                sem_lock( dctxdata->smphr, SEM_INFINITY );
                *pPktTx = Queue_pop( &dctxdata->tx_intrpt, &dctxdata->TxQueue );
                sem_unlock( dctxdata->smphr ); 
            }
        }
        break;


        case NET_SEND_RETURN:                   //  Вернуть пакет на передачу в очередь ожидания
        {
            if( arg == NULL ) return OSE_NULL_PARAM;
            if( d->ctx->data == NULL ) return OSE_BAD_DCTX;
            EMAC_Device* dctxdata = (EMAC_Device*)d->ctx->data;
            EMAC_Pkt **pPktTx = (EMAC_Pkt **)const_cast<void*>(arg);
            if( (*pPktTx == NULL) || ((*pPktTx)->data == NULL) ) return OSE_BAD_PARAM;      //  Проверить наличие пакета

            sem_lock( dctxdata->smphr, SEM_INFINITY );
            Queue_push( &dctxdata->tx_intrpt, &dctxdata->TxQueue, *pPktTx );
            sem_unlock( dctxdata->smphr );

        }
        break;


        case NET_SEND_PUT:                      //      Передать новый пакет
        {
            if( arg == NULL ) return OSE_NULL_PARAM;
            if( d->ctx->data == NULL ) return OSE_BAD_DCTX;
            EMAC_Device* dctxdata = (EMAC_Device*)d->ctx->data;
            EMAC_Pkt **pPktTx = (EMAC_Pkt **)const_cast<void*>(arg);
            if( (*pPktTx == NULL) || ((*pPktTx)->data == NULL) ) return OSE_BAD_PARAM;      //  Проверить наличие пакета

//extern uint32 hgpio1;
//extern void DebugPin(uint32 hgpio,int32 num_gpio,int32 value);

//DebugPin(hgpio1,3,0);
            sem_lock( dctxdata->smphr, SEM_INFINITY );
//DebugPin(hgpio1,3,1);
            if( (*pPktTx)->length > dctxdata->PktMTU )
            {
//DebugPin(hgpio1,3,0);
                Queue_push( &dctxdata->tx_intrpt, &dctxdata->TxQueue, *pPktTx );
                error = OSE_BAD_PARAM;
//DebugPin(hgpio1,3,1);
            }
            else
            {
//DebugPin(hgpio1,3,0);
                if( (dctxdata->ncfg.flags & NETCFG_PROMISCUOUSE) == 0 )
                {
                    memcpy( ((*pPktTx)->data + 6), &dctxdata->ncfg.mac, 6 );
                }
                EMAC_sendPacket( dctxdata, *pPktTx );
//DebugPin(hgpio1,3,1);
            }
            sem_unlock( dctxdata->smphr );
//DebugPin(hgpio1,3,0);
        }
        break;


        case NET_SEND_PACKET:                   //      Передать новый пакет
        {
            //break;
            if( arg == NULL ) return OSE_NULL_PARAM;
            if( d->ctx->data == NULL ) return OSE_BAD_DCTX;
            EMAC_Device* dctxdata = (EMAC_Device*)d->ctx->data;
            net_send *pSend = (net_send *)const_cast<void*>(arg);
            EMAC_Pkt *pPktTx = NULL;
            if( pSend == NULL ) return OSE_BAD_PARAM;      //  Проверить наличие пакета

            sem_lock( dctxdata->smphr, SEM_INFINITY );
            if( dctxdata->TxQueue.Count == 0 )
            {
                error = OSE_RESOURCE_BUSY;
            }
            else
            {
                if( (pSend->data == NULL) || (pSend->length > dctxdata->PktMTU) )
                {
                    error = OSE_BAD_PARAM;
                }
                else
                {
                    pPktTx = Queue_pop( &dctxdata->tx_intrpt, &dctxdata->TxQueue );
                    memcpy( pPktTx->data, pSend->data, pSend->length );
                    pPktTx->length = pSend->length;
                    if( (dctxdata->ncfg.flags & NETCFG_PROMISCUOUSE) == 0 )
                    {
                        memcpy( (pPktTx->data + 6), &dctxdata->ncfg.mac, 6 );
                    }
                    EMAC_sendPacket( dctxdata, pPktTx );
                }
            }
            sem_unlock( dctxdata->smphr );
        }
        break;

        case NET_READ_REG:
        {
            if( arg == NULL ) return OSE_NULL_PARAM;
            if( d->ctx->data == NULL ) return OSE_BAD_DCTX;
            dev_reg *pdr = (dev_reg *)const_cast<void*>(arg);

            switch( pdr->device)
            {
                case EMAC_RW_REG:
                {
                    pdr->value = *(volatile uint32*)(pdr->reg);
                }
                  break;
                default:
                    error = OSE_BAD_PARAM;
            }
        }
        break;
        
        case NET_WRITE_REG:
        {
            if( arg == NULL ) return OSE_NULL_PARAM;
            if( d->ctx->data == NULL ) return OSE_BAD_DCTX;
            dev_reg *pdr = (dev_reg *)const_cast<void*>(arg);

            switch( pdr->device)
            {
                case EMAC_RW_REG:
                {
                    *(volatile uint32*)(pdr->reg) = pdr->value;
                }
                  break;
                default:
                    error = OSE_BAD_PARAM;
            }
        }
        break;
        

        case NET_SET_CONFIG:
        {
            if( arg == NULL ) return OSE_NULL_PARAM;
            if( d->ctx->data == NULL ) return OSE_BAD_DCTX;
            EMAC_Device* dctxdata = (EMAC_Device*)d->ctx->data;

            net_config *new_cfg = (net_config *)const_cast<void*>(arg);

            uint32 tmpval;
            uint32 utemp1;

            sem_lock( dctxdata->smphr, SEM_INFINITY );
            int_lock( dctxdata->rx_intrpt );
            int_lock( dctxdata->tx_intrpt );
            
            memcpy( &dctxdata->ncfg, new_cfg, sizeof(net_config) );            

            // Disable EMAC/MDIO interrupts /
            ECTL_REGS->TX_EN = 0x0;
            ECTL_REGS->RX_EN = 0x0;
            ECTL_REGS->RX_THRESH_EN = 0;
            ECTL_REGS->MISC_EN = 0x0;

            tmpval = dctxdata->Config.ChannelInfo.RxChanEnable;
            for (utemp1 = 0; tmpval != 0; tmpval >>= 1, utemp1 += 1)
                if (tmpval & 0x1)
                    break;

            // Setup device MAC address /
            EMAC_REGS->MACINDEX = 0;

            tmpval = 0;
            for( int32 i = 3; i >= 0; i-- )
                tmpval = (tmpval << 8) | new_cfg->mac[i];

            EMAC_REGS->MACADDRHI = tmpval;

            tmpval = new_cfg->mac[5];
            EMAC_REGS->MACADDRLO = CSL_FMKT(EMAC_MACADDRLO_VALID, VALID) |
                                   CSL_FMKT(EMAC_MACADDRLO_MATCHFILT, MATCH) |
                                   CSL_FMK(EMAC_MACADDRLO_CHANNEL, utemp1) |
                                   (tmpval << 8) |
                                   new_cfg->mac[4];

            if( dctxdata->callback ) dctxdata->callback( d->ctx->name, &dctxdata->ncfg );
            
            // Enable EMAC/MDIO interrupts /
            ECTL_REGS->TX_EN = 0x01;
            ECTL_REGS->RX_EN = 0x01;
            ECTL_REGS->RX_THRESH_EN = 0x00;
            ECTL_REGS->MISC_EN = 0x0;

            int_unlock( dctxdata->rx_intrpt );
            int_unlock( dctxdata->tx_intrpt );
            sem_unlock( dctxdata->smphr );
        }
        break;
        
        case NET_SET_CONFIG_CALLBACK:
        {
            if( arg == NULL ) return OSE_NULL_PARAM;
            if( d->ctx->data == NULL ) return OSE_BAD_DCTX;
            EMAC_Device* dctxdata = (EMAC_Device*)d->ctx->data;
            if( dctxdata->callback ) return OSE_ALLREADY_SET;
            dctxdata->callback = ((void(*)(const char*,net_config*))((uint32)const_cast<void*>( arg )));
        }
        break;
        
        case NET_GET_CONFIG:
        {
            if( arg == NULL ) return OSE_NULL_PARAM;
            if( d->ctx->data == NULL ) return OSE_BAD_DCTX;
            EMAC_Device* dctxdata = (EMAC_Device*)d->ctx->data;
            net_config *get_cfg = (net_config *)const_cast<void*>(arg);
            memcpy( get_cfg, &dctxdata->ncfg, sizeof(net_config) );
        }
        break;
        
        
        case NET_LINK:
        {
            if( arg == NULL ) return OSE_NULL_PARAM;
            if( d->ctx->data == NULL ) return OSE_BAD_DCTX;
            EMAC_Device* dctxdata = (EMAC_Device*)d->ctx->data;

            if( dctxdata->FatalError )
            {
                error = NetcardInit( dctxdata );
                if( error != OSE_OK )
                    break;
            }
            
            (*(bool*)const_cast<void*>( arg )) = dctxdata->old_link;

        }
        break;
        
        default:
         return OSE_BAD_CMD;
    }
    return error;
}

// ---------------------------------------------------------------------------
// !: fn: int32 drv_eth6457_plug ( const char* path, net_config& cfg, uint32 rxd_count, uint32 txd_count )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция добавляет драйвер сетевого контроллера в точку монтирования path. <br>
// !: d: 
// !: d: Входные параметры: <br>
// !: d:   path     - точка монтирования драйвера; <br>
// !: d:   cfg      - конфигурационные параметры драйвера; <br>
// !: d:   rxd_count - задание количества пакетов в приемной очереди; <br>
// !: d:   txd_count - задание количества пакетов в передающей очереди; <br>
// !: d: 
// !: d: В случае успеха возвращает OSE_OK, иначе - стандартный код ошибки. <br>
// !: d: 
// !: d: Данная функция доступна пользователю.
// !: -:
// ---------------------------------------------------------------------------
int32 drv_eth6457_plug ( const char* path, net_config& cfg, uint32 rxd_count, uint32 txd_count )
{
  EMAC_Device pdev;
  EMAC_Config *ecfg = NULL;
  memset( &pdev, 0, sizeof(EMAC_Device) );

  memcpy( &pdev.ncfg, &cfg, sizeof(net_config) );
  ecfg = &pdev.Config;
  ecfg->RxMaxPktPool = rxd_count;
  ecfg->TxMaxPktPool = txd_count;

  ecfg->ChannelInfo.RxChanEnable = 1;
  ecfg->ChannelInfo.TxChanEnable = 1;

  return drv_plug( path, INOT_FILE, &eth6457_open, &eth6457_close, &eth6457_read, &eth6457_write, &eth6457_ioctl, &pdev, sizeof(EMAC_Device));
}

// ---------------------------------------------------------------------------
// !: fn: int32 drv_eth6457_unplug( const char* name )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция удаляет драйвер сетевого контроллера с именем name. <br>
// !: d: В случае успеха возвращает OSE_OK, иначе - стандартный код ошибки. <br>
// !: d: Данная функция доступна пользователю.
// !: -:
// ---------------------------------------------------------------------------
int32 drv_eth6457_unplug( const char* name )
{
  return drv_unplug( name );
}

// ---------------------------------------------------------------------------
// !: fn: int32 NetcardInit( EMAC_Device* pd )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция производит инициализацию и тест сетевого контроллера. <br>
// !: d: В случае успеха возвращает OSE_OK, иначе, кроме стандартных ошибок:
// !: d: OSE_NO_DEVICE - не подключен драйвер GPIO; <br>
// !: d: ERROR_NO_PHY - нет связи с сетевым контроллером. <br>
// !: d: 
// !: d: Данная функция не доступна пользователю.
// !: -:
// ---------------------------------------------------------------------------
int32 NetcardInit( EMAC_Device* pd )
{
    uint32 rcvFilter = 0;
    EMAC_getReceiveFilter( pd, &rcvFilter );

    pd->FatalError = 0;
    initEMAC( &pd->Config, pd );
    startupEMAC( pd );
    //  Setup receive filter
    EMAC_setReceiveFilter( pd, rcvFilter );
    return 0;
}

// ---------------------------------------------------------------------------
// !: fn: int32 lbk_test( EMAC_Device * pd, uint8 value )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция получает текущее значение секунд value
// !: d: из соответствующего регистра часов реального времени. <br>
// !: d: В случае успеха возвращает 0, иначе: <br>
// !: d: ERROR_RTC_ACK - таймаут ожидания ответа от часов. <br>
// !: d: 
// !: d: Данная функция не доступна пользователю.
// !: -:
// ---------------------------------------------------------------------------
int32 lbk_test( EMAC_Device *pd, uint8 value )
{
    EMAC_Pkt *pPktTx = NULL;
    EMAC_Pkt *pPktRx = NULL;
    int32 error = OSE_OK;


    pPktTx = Queue_pop( &pd->tx_intrpt, &pd->TxQueue );   // получить свободный пакет на передачу
    pPktTx->length = pd->PktMTU;
    memset( pPktTx->data, value, pd->PktMTU ); // сформировать тестовый пакет
    EMAC_sendPacket( pd, pPktTx );    // послать тестовый пакет

    uint64 tms = time_core();
    while( pd->RxQueue.Count == 0 )   // дождаться приема тестового пакета
    {
        if( (time_core() - tms) > 5 )
        {
            return OSE_TIMEOUT;
        }
    }
    pPktRx = Queue_pop( &pd->rx_intrpt, &pd->RxQueue );   // получить принятый пакет
    for( uint32 i = 0; i < (pd->PktMTU - RX_BUFFER_OFFSET); i++ )     // сравнить посланный и принятый пакеты
    {
        if( pPktRx->data[i + RX_BUFFER_OFFSET] != pPktTx->data[i] )
        {
            error = OSE_LOOPBACK_PHY;
            break;
        }
    }
    emacRxPutPkt( &pd->RxCh[0], pPktRx );    // вернуть пакет в очередь приема
    return error;
}

// ---------------------------------------------------------------------------
// !: fn: static EMAC_Pkt *Queue_pop( uint32 *pintrpt, PKTQ *pq )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция получает пакет EMAC_Pkt из очереди пакетов pq
// !: d: при запрещенном прерывании pintrpt от модуля EMAC. <br>
// !: d: 
// !: d: Входные параметры: <br>
// !: d:   pintrpt  - идентификатор запрещаемого прерывания; <br>
// !: d:   pq       - очередь, из которой берется пакет; <br>
// !: d: Возвращаемое значение: <br>
// !: d:   EMAC_Pkt - получаемый пакет. В случае отсутствия пакетов в очереди
// !: d:   возвращается 0. <br>
// !: d: 
// !: d: Данная функция не доступна пользователю.
// !: -:
// ---------------------------------------------------------------------------
static EMAC_Pkt *Queue_pop( uint32 *pintrpt, PKTQ *pq )
{
    EMAC_Pkt *pPktHdr = NULL;
//  Disable_DSP_Interrupt
    int_lock( *pintrpt );
    
    pPktHdr = pqPop( pq );
    
//  Enable_DSP_Interrupt
    int_unlock( *pintrpt );
    
    return( pPktHdr );
}

// ---------------------------------------------------------------------------
// !: fn: static void Queue_push( uint32 *pintrpt, PKTQ *pq, EMAC_Pkt *pPktHdr )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция помещает пакет pPktHdr в очередь пакетов pq
// !: d: при запрещенном прерывании pintrpt от модуля EMAC. <br>
// !: d: 
// !: d: Входные параметры: <br>
// !: d:   pintrpt  - идентификатор запрещаемого прерывания; <br>
// !: d:   pq       - очередь, в которую помещается пакет; <br>
// !: d:   pPktHdr  - пакет, помещаемый в очередь.  <br>
// !: d: Возвращаемое значение: <br>
// !: d:   нет. <br>
// !: d: 
// !: d: Данная функция не доступна пользователю.
// !: -:
// ---------------------------------------------------------------------------
static void Queue_push( uint32 *pintrpt, PKTQ *pq, EMAC_Pkt *pPktHdr )
{
//  Disable_DSP_Interrupt
    int_lock( *pintrpt );
    
    pqPush( pq, pPktHdr );
    
//  Enable_DSP_Interrupt
    int_unlock( *pintrpt );
}

// ---------------------------------------------------------------------------
// !: fn: void emac_deinit( EMAC_Device *pd )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция получает текущее значение секунд value
// !: d: из соответствующего регистра часов реального времени. <br>
// !: d: В случае успеха возвращает 0, иначе: <br>
// !: d: ERROR_RTC_ACK - таймаут ожидания ответа от часов. <br>
// !: d: 
// !: d: Данная функция не доступна пользователю.
// !: -:
// ---------------------------------------------------------------------------
void emac_deinit( EMAC_Device *pd )
{
    if( pd != NULL )
    {
        EMAC_close( pd );

        REG_GPIO_CLR_DATA = ( GPIO_7 );
        REG_GPIO_SET_DATA = ( GPIO_8 );
         
        if( pd->smphr != RES_VOID )
            sem_free( pd->smphr );
        if( pd->rx_intrpt != RES_VOID )
            int_free( pd->rx_intrpt );
        if( pd->tx_intrpt != RES_VOID )
            int_free( pd->tx_intrpt );
//        if( pd->t1_intrpt != RES_VOID )
//            int_free( pd->t1_intrpt );
        pd->pkt_data = RES_VOID;
        pd->pkt_tx = RES_VOID;
        pd->pkt_rx = RES_VOID;
        pd->hSgmii = RES_VOID;
        pd->smphr = RES_VOID;
        pd->rx_intrpt = RES_VOID;
        pd->tx_intrpt = RES_VOID;
        pd->t1_intrpt = RES_VOID;
    }
}

// ---------------------------------------------------------------------------
// !: fn: void HwInt(void)
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция обработки прерывания от модуля EMAC. < br>
// !: d: 
// !: d: Данная функция не доступна пользователю.
// !: -:
// ---------------------------------------------------------------------------
void HwRxInt(void)
{
    if( hEMAC )
    {
        EMAC_RxServiceCheck(hEMAC);
    }
    return;
}

// ---------------------------------------------------------------------------
// !: fn: void HwInt(void)
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция обработки прерывания от модуля EMAC. < br>
// !: d: 
// !: d: Данная функция не доступна пользователю.
// !: -:
// ---------------------------------------------------------------------------
void HwTxInt(void)
{
    if( hEMAC )
    {
        EMAC_TxServiceCheck(hEMAC);
    }
    return;
}



// ---------------------------------------------------------------------------
// !: fn: void T1Int(void)
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция обработки прерывания от таймера T1. < br>
// !: d: 
// !: d: Данная функция не доступна пользователю.
// !: -:
// ---------------------------------------------------------------------------
uint32 count_down = 0;

void T1Int(void)
{
	CSL_SgmiiRegs* pSGMII = (CSL_SgmiiRegs*)(0x02C40000);

    if( hEMAC )
    {
        EMAC_Device* pd = (EMAC_Device*)hEMAC;

        if( pSGMII->STATUS & CSL_SGMII_STATUS_LINK_UP )
        {
            REG_GPIO_CLR_DATA = ( GPIO_8 );
            if( pd->old_link == false )
            {
                pSGMII->MR_ADV_ABILITY |= 0xD801;
            }
            pd->old_link = true;
        }
        else
        {
            REG_GPIO_CLR_DATA = ( GPIO_7 );
            REG_GPIO_SET_DATA = ( GPIO_8 );
            pd->pkt_prznt = false;
//			if( pd->old_link )

			if( !(REG_GPIO_IN_DATA & GPIO_3) )
			{
				if( count_down > 20 )
				{
					pSGMII->CONTROL = 0x0;
					pSGMII->MR_ADV_ABILITY = 0x0;
					pSGMII->CONTROL = 0x21;
					count_down = 0;

					pSGMII->MR_ADV_ABILITY = pSGMII->MR_LP_ADV_ABILITY;
				}

				else
				{
					count_down++;
				}

			}
            pd->old_link = false;

//			pSGMII->MR_ADV_ABILITY = pSGMII->MR_LP_ADV_ABILITY;

            return;
        }

        if( REG_GPIO_OUT_DATA & GPIO_7 )
        {
            REG_GPIO_CLR_DATA = ( GPIO_7 );
            pd->pkt_prznt = false;
        }
        else
        {
            if( pd->pkt_prznt )
            {
                REG_GPIO_SET_DATA = ( GPIO_7 );
            }
        }

    }
    return;
}








