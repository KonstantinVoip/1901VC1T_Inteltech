// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp1251
// !: d: Модуль содержит реализацию функций драйвера сетевого контроллера.
// !: -: 
// ---------------------------------------------------------------------------
#include <drv_eth6412.h>
#include <drv_eth6412_emac.h>
#include <drv_eth6412_mdio.h>

#include <net_packet_parser.h>

#include <os.h>
#include <rts.h>

#include <drv_gpio.h>
// ---------------------------------------------------------------------------

//************************************************
//       
//************************************************
#define PHYREG_CONTROL              0
#define PHYREG_STATUS               1
#define PHYREG_ID1                  2
#define PHYREG_ID2                  3
#define PHYREG_ADVERTISE            4
#define PHYREG_PARTNER              5
#define PHYREG_LEDCONFIG           20

//uint32 send_intrpt = 0;
//uint32 recv_intrpt = 0;
//uint32 work_intrpt = 0;

char* net_data_ptr;
s_os_mem_block* net_mem_page;

Handle hEMAC = NULL;
// ---------------------------------------------------------------------------

//*******************************
//       Прототипы функций
//*******************************

int32 NetcardInit(EMAC_Device *pd);
int32 reset_phy( EMAC_Device *pd );

static EMAC_Pkt *Queue_pop( uint32 *pintrpt, PKTQ *pq );
static void Queue_push( uint32 *pintrpt, PKTQ *pq, EMAC_Pkt *pPktHdr );

static EMAC_Pkt *GetPacket( Handle hApplication, PKTQ *pPktQueue );
static void PutPacket(Handle hApplication, PKTQ *pPktQueue, EMAC_Pkt *cslPkt);

int32 lbk_test( EMAC_Device * pd, uint8 value );
void emac_deinit( EMAC_Device *pd );

int32 emac_requeue( EMAC_Device *pd, new_queue *nq );

uint32 get_alloc_mem_size(EMAC_Config* econf);

void HwInt(void);

// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------
// !: fn: int32 eth6412_open ( s_os_driver_descriptor* d, uint16 access )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция не используется. <br>
// !: d: В случае вызова, возвращает стандартный код ошибки OSE_BAD_CMD.
// !: -:
// ---------------------------------------------------------------------------
int32 eth6412_open ( s_os_driver_descriptor* d, uint16 access )
{
  return OSE_BAD_CMD;
}

// ---------------------------------------------------------------------------
// !: fn: int32 eth6412_close ( s_os_driver_descriptor* d )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция не используется. <br>
// !: d: В случае вызова, возвращает стандартный код ошибки OSE_BAD_CMD.
// !: -:
// ---------------------------------------------------------------------------
int32 eth6412_close ( s_os_driver_descriptor* d )
{
  return OSE_BAD_CMD;
}

// ---------------------------------------------------------------------------
// !: fn: int32 eth6412_read ( s_os_driver_descriptor* d, void* buf, int32 length )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция не используется. <br>
// !: d: В случае вызова, возвращает стандартный код ошибки OSE_BAD_CMD.
// !: -:
// ---------------------------------------------------------------------------
int32 eth6412_read ( s_os_driver_descriptor* d, void* buf, int32 length )
{
  return OSE_BAD_CMD;
}

// ---------------------------------------------------------------------------
// !: fn: int32 eth6412_write ( s_os_driver_descriptor* d, const void* buf, int32 length )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция не используется. <br>
// !: d: В случае вызова, возвращает стандартный код ошибки OSE_BAD_CMD.
// !: -:
// ---------------------------------------------------------------------------
int32 eth6412_write ( s_os_driver_descriptor* d, const void* buf, int32 length )
{
  return OSE_BAD_CMD;
}

// ---------------------------------------------------------------------------
// !: fn: int32 eth6412_ioctl ( s_os_driver_descriptor* d, int32 cmd, const void* arg )
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
int32 eth6412_ioctl ( s_os_driver_descriptor* d, int32 cmd, const void* arg )
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
          //------------------------------------
           s_os_driver_context* dctx = (s_os_driver_context*)const_cast<void*>( arg );
           EMAC_Device* pdev = (EMAC_Device*)dctx->data;
           EMAC_Config* econf = &pdev->Config;

           uint32 hsize = get_alloc_mem_size(econf);
           net_mem_page = mem_alloc( hsize,1 );
           if( net_mem_page == NULL )
             return OSE_NO_MEMORY;
           net_data_ptr = (char*)net_mem_page + ((sizeof(s_os_mem_block)+0x3f)&~0x3f);
           //clear all allocated memory
           memset(net_data_ptr,0,(hsize-((sizeof(s_os_mem_block)+0x3f)&~0x3f)));

           //------------------------------------
           if( (econf->RxMaxPktPool == 0) || (econf->TxMaxPktPool == 0) )
           {
             return OSE_BAD_PARAM;
           }
           //mkd GPIO
           pdev->hGPIO = drv_mkd( "/dev/gpio" );
           if( pdev->hGPIO == RES_VOID )
           {
             return OSE_NO_DEVICE;
           }
           res_share( pdev->hGPIO );
            
            //  Allocate Semaphore
           pdev->smphr = sem_alloc( 1, NULL );
           if( pdev->smphr == RES_VOID )
           {
             error = OSE_CANT_CREATE_SEM;
             goto net_init_fail;
           }
            //  Allocate Interrupt
           pdev->intrpt = int_alloc( INT_EMAC_MDIO, &HwInt );
           if (pdev->intrpt == RES_VOID)
           {
             error = OSE_CANT_CREATE_INTERRUPT;
             goto net_init_fail;
           }
            //  Reset PHY
           error = reset_phy( pdev );
           if( error != OSE_OK )
           {
             goto net_init_fail;
           }
           //------------------------------------

            //  Allocate Memory
           pdev->hMDIO = heap_alloc( NULL, sizeof(MDIO_Device), HEAP_ALIGN_8 );
           if( !pdev->hMDIO ) 
           {
             error = OSE_NO_MEMORY;
             goto net_init_fail;
           }

           uint32 shift_ptr1,shift_ptr2;

           shift_ptr1 = (sizeof(EMAC_Pkt) * econf->RxMaxPktPool) + (8-(sizeof(EMAC_Pkt) * econf->RxMaxPktPool)&0x7);
           shift_ptr2 = shift_ptr1+(sizeof(EMAC_Pkt) * econf->TxMaxPktPool) + (8-(sizeof(EMAC_Pkt) * econf->TxMaxPktPool)&0x7);

           pdev->pkt_rx   = (EMAC_Pkt*)net_data_ptr;
           pdev->pkt_tx   = (EMAC_Pkt*)(net_data_ptr + shift_ptr1);
           pdev->pkt_data = (uint8*)(net_data_ptr+shift_ptr2);
                        
            //------------------------------------
            // Queue up some initialized receive buffers /
           for( i=0; i < (econf->RxMaxPktPool); i++ )
           {
             pdev->pkt_rx[i].prev = pdev->pkt_rx;
             pdev->pkt_rx[i].size = 1514;
             pdev->pkt_rx[i].data = &pdev->pkt_data[i * NET_PACKET_SIZE];
             Queue_push( &pdev->intrpt, &pdev->RxQueue, &pdev->pkt_rx[i] );
           }
            // Queue up some transmit buffers /
           for( i=0; i < (pdev->Config.TxMaxPktPool); i++ )
           {
             pdev->pkt_tx[i].prev = pdev->pkt_tx;
             pdev->pkt_tx[i].size = 1514;
             pdev->pkt_tx[i].data = &pdev->pkt_data[(econf->RxMaxPktPool + i) * NET_PACKET_SIZE];
             Queue_push( &pdev->intrpt, &pdev->TxQueue, &pdev->pkt_tx[i] );
           }
            
           //**************************************************
           // Initialize EMAC setup  /
           //
           //Configuration Mode Flags:
           //EMAC_CONFIG_MODEFLG_CHPRIORITY  /* Use Tx channel priority  */
           //EMAC_CONFIG_MODEFLG_MACLOOPBACK /* MAC internal loopback    */
           //EMAC_CONFIG_MODEFLG_RXCRC       /* Include CRC in RX frames */
           //EMAC_CONFIG_MODEFLG_TXCRC       /* Tx frames include CRC    */
           //EMAC_CONFIG_MODEFLG_PASSERROR   /* Pass error frames        */
           //EMAC_CONFIG_MODEFLG_PASSCONTROL /* Pass control frames      */

           //econf->ModeFlags = EMAC_CONFIG_MODEFLG_PASSCONTROL;      // Configuation Mode Flags
           econf->MdioModeFlags = MDIO_MODEFLG_FD100 | MDIO_MODEFLG_LOOPBACK; 	//  MDIO_MODEFLG_AUTONEG;	// MDIO Mode Flags
           econf->TxChannels = 1;			// Number of Tx Channels to use (1-8)

           econf->pfcbGetPacket = &GetPacket;
           econf->pfcbPutPacket = &PutPacket;
           //--------------------------------------------------
            
           //**************************************************
           error = EMAC_open( (Handle)dctx->name, econf, pdev );
           if( error != OSE_OK )
           {
             goto net_init_fail;//printf("EMAC OPEN Returned error \n");
           }
            
           hEMAC = pdev;
           //Setup receive filter
           EMAC_setReceiveFilter( pdev, EMAC_RXFILTER_ALL );
           sleep_m( 60 );
           error = MDIO_findPHY( pdev->hMDIO );
           sleep_m( 60 );
           if( error != OSE_OK )
           {
             goto net_init_fail;
           }

           startupEMAC( pdev );
            
           //@b Interrupt_init
           //Registering Interrupts and Enabling global interrupts.
           res_share( pdev->intrpt );
           int_unlock( pdev->intrpt );

           if( econf->MdioModeFlags & MDIO_MODEFLG_LOOPBACK )
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
             econf->MdioModeFlags &= ~MDIO_MODEFLG_LOOPBACK;      // Configuation Mode Flags
             MDIO_phyRegWrite( ((MDIO_Device*)pdev->hMDIO)->phyAddr, PHYREG_CONTROL, (uint16)((MDIO_Device*)pdev->hMDIO)->control_reg );
             /*
             MDIO_phyRegRead( ((MDIO_Device*)pdev->hMDIO)->phyAddr, PHYREG_CONTROL, (uint16*)&i );
             i = PHYREG_CONTROL_SPEED100 | PHYREG_CONTROL_DUPLEXFULL;
             MDIO_phyRegWrite( ((MDIO_Device*)pdev->hMDIO)->phyAddr, PHYREG_CONTROL, (uint16)i );
             i |= PHYREG_CONTROL_AUTONEGEN;
             MDIO_phyRegWrite( ((MDIO_Device*)pdev->hMDIO)->phyAddr, PHYREG_CONTROL, (uint16)i );
             */
             MDIO_phyRegRead( ((MDIO_Device*)pdev->hMDIO)->phyAddr, PHYREG_CONTROL, (uint16*)&i );
           }
           s_gpio_operation sgop;
           sgop.number_gpio = 9;
           sgop.value_gpio = 0;
           //sleep while link gain stability
           sleep_m( 1500 );

           error = drv_ioctl( pdev->hGPIO, GPIO_VALUE, &sgop );
           if( error == OSE_OK ) 
           {
             i = ( MDIO_RGET( LINK ) >> ((MDIO_Device*)pdev->hMDIO)->phyAddr ) * 0x01;
             if( (sgop.value_gpio & 0x01) ^ i ) 
             {
               error = OSE_LINK_TEST;
             }
           }

net_init_fail:
            if( error )
            {
              emac_deinit( pdev );
            }
         }
    	 break;

    case IOC_DEINIT:
         {
           
           s_os_driver_context* dctx = (s_os_driver_context*)const_cast<void*>( arg );
           EMAC_Device* pdev = (EMAC_Device*)dctx->data;            
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
    case NET_RECV_GET://Забрать принятый пакет
         {
           if( arg == NULL ) return OSE_NULL_PARAM;
           if( d->ctx->data == NULL ) return OSE_BAD_DCTX;
           EMAC_Device* dctxdata = (EMAC_Device*)d->ctx->data;
           EMAC_Pkt **pPktRx = (EMAC_Pkt **)const_cast<void*>(arg);
           *pPktRx = NULL;

           if( dctxdata->RxQueue.Count > 0 )
           {
             sem_lock( dctxdata->smphr, SEM_INFINITY );

             *pPktRx = Queue_pop( &dctxdata->intrpt, &dctxdata->RxQueue );
             if( netpp_parse( dctxdata->ncfg, (net_descriptor*)*pPktRx ) != NETPP_OK )
             {
               emacRxPutPkt( &dctxdata->RxCh, *pPktRx );
               *pPktRx = NULL;
             }
             sem_unlock( dctxdata->smphr );
           }
         }
         break;
        
        
    case NET_RECV_PUT://Поставить свободный пакет на прием
         {
           if( arg == NULL ) return OSE_NULL_PARAM;
           if( d->ctx->data == NULL ) return OSE_BAD_DCTX;
           EMAC_Device* dctxdata = (EMAC_Device*)d->ctx->data;
           EMAC_Pkt **pPktRx = (EMAC_Pkt **)const_cast<void*>(arg);
           if( *pPktRx == NULL ) return OSE_BAD_PARAM;//Проверить наличие пакета
            
           sem_lock( dctxdata->smphr, SEM_INFINITY );
           //int_lock( dctxdata->intrpt );
           emacRxPutPkt( &dctxdata->RxCh, *pPktRx );
           //int_unlock( dctxdata->intrpt );
           sem_unlock( dctxdata->smphr );
         }
         break;


    case NET_SEND_GET://Получить свободный пакет на передачу
         {
            if( arg == NULL ) return OSE_NULL_PARAM;
            if( d->ctx->data == NULL ) return OSE_BAD_DCTX;
            EMAC_Device* dctxdata = (EMAC_Device*)d->ctx->data;
            EMAC_Pkt **pPktTx = (EMAC_Pkt **)const_cast<void*>(arg);
            *pPktTx = NULL;

            if( dctxdata->TxQueue.Count > 0 )
            {
              sem_lock( dctxdata->smphr, SEM_INFINITY );
              *pPktTx = Queue_pop( &dctxdata->intrpt, &dctxdata->TxQueue );
              sem_unlock( dctxdata->smphr ); 
            }
         }
         break;


    case NET_SEND_PUT://Передать новый пакет
         {
           if( arg == NULL ) return OSE_NULL_PARAM;
           if( d->ctx->data == NULL ) return OSE_BAD_DCTX;
           EMAC_Device* dctxdata = (EMAC_Device*)d->ctx->data;
           EMAC_Pkt **pPktTx = (EMAC_Pkt **)const_cast<void*>(arg);
           if( *pPktTx == NULL ) return OSE_BAD_PARAM;//Проверить наличие пакета


           sem_lock( dctxdata->smphr, SEM_INFINITY );
           if( ((*pPktTx)->data == NULL) || ((*pPktTx)->length > dctxdata->PktMTU) )
           {
             Queue_push( &dctxdata->intrpt, &dctxdata->TxQueue, *pPktTx );
             error = OSE_BAD_PARAM;
           }
           else
           {
             if( (dctxdata->ncfg.flags & NETCFG_PROMISCUOUSE) == 0 )
             {
               memcpy( ((*pPktTx)->data + 6), &dctxdata->ncfg.mac, 6 );
             }
             EMAC_sendPacket( dctxdata, *pPktTx );
           }
           sem_unlock( dctxdata->smphr );
         }
         break;
        
    case NET_SEND_PACKET://Передать новый пакет
         {
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
               pPktTx = Queue_pop( &dctxdata->intrpt, &dctxdata->TxQueue );
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
           EMAC_Device* dctxdata = (EMAC_Device*)d->ctx->data;
           dev_reg *pdr = (dev_reg *)const_cast<void*>(arg);

           switch( pdr->device)
           {
             case EMAC_RW_REG:
                  {
                    pdr->value = *(volatile uint32*)(pdr->reg);
                  }
                  break;
             case PHY_RW_REG:
                  {
                    if( !MDIO_phyRegRead( ((MDIO_Device*)dctxdata->hMDIO)->phyAddr, pdr->reg, (uint16*)&pdr->value ) )
                      error = OSE_CANT_READ;
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
           EMAC_Device* dctxdata = (EMAC_Device*)d->ctx->data;
           dev_reg *pdr = (dev_reg *)const_cast<void*>(arg);

           switch( pdr->device)
           {
             case EMAC_RW_REG:
                  {
                    *(volatile uint32*)(pdr->reg) = pdr->value;
                  }
                  break;
             case PHY_RW_REG:
                  {
                    if( !MDIO_phyRegWrite( ((MDIO_Device*)dctxdata->hMDIO)->phyAddr, pdr->reg, (uint16)pdr->value ) )
                      error = OSE_CANT_WRITE;
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

           sem_lock( dctxdata->smphr, SEM_INFINITY );
           int_lock( dctxdata->intrpt );
            
           memcpy( &dctxdata->ncfg, new_cfg, sizeof(net_config) );            

            // Disable EMAC/MDIO interrupts /
           EMAC_FSETS( EWCTL, INTEN, DISABLE );

            // Setup device MAC address /
           EMAC_RSET( MACADDRL0, new_cfg->mac[5] );
           EMAC_RSET( MACADDRM, new_cfg->mac[4] );
            
           int i;
           uint32 tmpval = 0;
           for( i=3; i>=0; i-- )
             tmpval = (tmpval<<8) | dctxdata->ncfg.mac[i];
           EMAC_RSET( MACADDRH, tmpval );
            
           if( dctxdata->callback ) dctxdata->callback( d->ctx->name, &dctxdata->ncfg );
            
           // Enable EMAC/MDIO interrupts /
           EMAC_FSETS( EWCTL, INTEN, ENABLE );

           int_unlock( dctxdata->intrpt );
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
        
    case NET_REINIT_QUEUE:
         {
           if( arg == NULL ) return OSE_NULL_PARAM;
           if( d->ctx->data == NULL ) return OSE_BAD_DCTX;
           EMAC_Device* dctxdata = (EMAC_Device*)d->ctx->data;
           new_queue *nq = (new_queue *)const_cast<void*>(arg);
           error = emac_requeue( dctxdata, nq );
         }
         break;
        
        
    case NET_LINK:
         {
           if( arg == NULL ) return OSE_NULL_PARAM;
           if( d->ctx->data == NULL ) return OSE_BAD_DCTX;
           EMAC_Device* dctxdata = (EMAC_Device*)d->ctx->data;
            
           if( dctxdata->hGPIO == NULL )
           {
             return OSE_NO_DEVICE;
           }
           if( dctxdata->FatalError )
           {
             error = NetcardInit( dctxdata );
             if( error != OSE_OK )
               break;
           }
            
           s_gpio_operation sgop;
           sgop.number_gpio = 9;
           sgop.value_gpio = 0;

           error = drv_ioctl( dctxdata->hGPIO, GPIO_VALUE, &sgop );
           if( error == OSE_OK ) 
           {
             (*(bool*)const_cast<void*>( arg )) = ( sgop.value_gpio & 0x01 ) ? true : false;
           }
         }
         break;
        
    default:
         return OSE_BAD_CMD;
  }
  return error;
}

// ---------------------------------------------------------------------------
// !: fn: int32 drv_eth6412_plug ( const char* path, net_config& cfg, uint32 rxd_count, uint32 txd_count )
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
int32 drv_eth6412_plug ( const char* path, net_config& cfg, uint32 rxd_count, uint32 txd_count )
{
  EMAC_Device pdev;
  EMAC_Config *ecfg = NULL;
  memset( &pdev, 0, sizeof(EMAC_Device) );

  memcpy( &pdev.ncfg, &cfg, sizeof(net_config) );
  ecfg = &pdev.Config;
  ecfg->RxMaxPktPool = rxd_count;
  ecfg->TxMaxPktPool = txd_count;

  return drv_plug( path, INOT_FILE, &eth6412_open, &eth6412_close, &eth6412_read, &eth6412_write, &eth6412_ioctl, &pdev, sizeof(EMAC_Device));
}

// ---------------------------------------------------------------------------
// !: fn: int32 drv_eth6412_unplug( const char* name )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция удаляет драйвер сетевого контроллера с именем name. <br>
// !: d: В случае успеха возвращает OSE_OK, иначе - стандартный код ошибки. <br>
// !: d: Данная функция доступна пользователю.
// !: -:
// ---------------------------------------------------------------------------
int32 drv_eth6412_unplug( const char* name )
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
  //hw reset
  int32 error = reset_phy( pd );
  if( error != OSE_OK )
    return error;

  pd->FatalError = 0;
  initEMAC( &pd->Config, pd );
  startupEMAC( pd );
  //Setup receive filter
  EMAC_setReceiveFilter( pd, rcvFilter );
  return MDIO_findPHY( pd->hMDIO );
}

// ---------------------------------------------------------------------------
// !: fn: int32 reset_phy(EMAC_Device *pd)
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция производит сброс сетевого контроллера. <br>
// !: d: В случае успеха возвращает OSE_OK, иначе, кроме стандартных ошибок: <br>
// !: d: OSE_NO_DEVICE - не подключен драйвер GPIO. <br>
// !: d: 
// !: d: Данная функция не доступна пользователю.
// !: -:
// ---------------------------------------------------------------------------
int32 reset_phy(EMAC_Device *pd)
{
  int32 error = OSE_OK;
  s_gpio_operation sgop;
  sgop.number_gpio = 11;
  sgop.value_gpio = 0;
  if( pd->hGPIO == NULL )
  {
    return OSE_NO_DEVICE;
  }
    
  error = drv_ioctl( pd->hGPIO, GPIO_PULL, &sgop );
  if( error == OSE_OK ) 
  {
    sgop.value_gpio = 1;
    error = drv_ioctl( pd->hGPIO, GPIO_PULL, &sgop );
    sgop.number_gpio = 12;
    sgop.value_gpio = 0;
    error = drv_ioctl( pd->hGPIO, GPIO_PULL, &sgop );
  }
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
  //Disable_DSP_Interrupt
  int_lock( *pintrpt );
    
  pPktHdr = pqPop( pq );
    
  //Enable_DSP_Interrupt
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
  //Disable_DSP_Interrupt
  int_lock( *pintrpt );
    
  pqPush( pq, pPktHdr );
    
  //Enable_DSP_Interrupt
  int_unlock( *pintrpt );
}


/***	GetPacket
 *      Returns a packet from the RxQueue.
 *
 *  @param[in]  hApplication - Driver's handle.
 *  @retval		EMAC_Pkt pointer of a packet with buffer to replenish CSL.
 */

// ---------------------------------------------------------------------------
// !: fn: static EMAC_Pkt *GetPacket( Handle hApplication, PKTQ *pPktQueue )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция получает текущее значение секунд value
// !: d: из соответствующего регистра часов реального времени. <br>
// !: d: В случае успеха возвращает 0, иначе: <br>
// !: d: ERROR_RTC_ACK - таймаут ожидания ответа от часов. <br>
// !: d: 
// !: d: Данная функция не доступна пользователю.
// !: -:
// ---------------------------------------------------------------------------
static EMAC_Pkt *GetPacket( Handle hApplication, PKTQ *pPktQueue )
{
  EMAC_Pkt *pPkt = NULL;
  EMAC_Device *pd = (EMAC_Device*)hApplication;
    
  pPkt = Queue_pop( &pd->intrpt, &pd->RxQueue );
    
  return( pPkt );
}


/***	RxPacket
 *      Function called by CSL to pass the received packet to the driver.
 *
 *  @param[in]  hApplication - Driver's handle.
 *  @param[in]  cslPkt - EMAC_Pkt type packet passed by CSL.
 *
 *  @retval	- EMAC_Pkt pointer of a packet with buffer to replenish CSL.
 */

// ---------------------------------------------------------------------------
// !: fn: int32 rtc_getSec( uint16* value )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция получает текущее значение секунд value
// !: d: из соответствующего регистра часов реального времени. <br>
// !: d: В случае успеха возвращает 0, иначе: <br>
// !: d: ERROR_RTC_ACK - таймаут ожидания ответа от часов. <br>
// !: d: 
// !: d: Данная функция не доступна пользователю.
// !: -:
// ---------------------------------------------------------------------------
static void PutPacket(Handle hApplication, PKTQ *pPktQueue, EMAC_Pkt *cslPkt)
{
  EMAC_Device *pd = (EMAC_Device*)hApplication;
    
  Queue_push( &pd->intrpt, pPktQueue, cslPkt );
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


  pPktTx = Queue_pop( &pd->intrpt, &pd->TxQueue );//получить свободный пакет на передачу
  pPktTx->length = pd->PktMTU;
  memset( pPktTx->data, value, pd->PktMTU );//сформировать тестовый пакет
  EMAC_sendPacket( pd, pPktTx );//послать тестовый пакет

  uint64 tms = time_core();
  while( pd->RxQueue.Count == 0 )//дождаться приема тестового пакета
  {
    if( (time_core() - tms) > 15 )
    {
      return OSE_TIMEOUT;
    }
  }
  pPktRx = Queue_pop( &pd->intrpt, &pd->RxQueue );//получить принятый пакет
  for( uint32 i = 0; i < pd->PktMTU; i++ )//сравнить посланный и принятый пакеты
  {
    if( pPktRx->data[i] != pPktTx->data[i] )
    {
      error = OSE_LOOPBACK_PHY;
      break;
    }
  }
  emacRxPutPkt( &pd->RxCh, pPktRx );//вернуть пакет в очередь приема
  return error;
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
    if( pd->hMDIO != NULL )
      heap_free( NULL, pd->hMDIO );
    if( pd->smphr != RES_VOID )
      sem_free( pd->smphr );
    if( pd->intrpt != RES_VOID )
      int_free( pd->intrpt );
    if( pd->hGPIO != NULL )
      drv_rmd( pd->hGPIO );

    mem_free(net_mem_page);

    pd->pkt_data = RES_VOID;
    pd->pkt_tx = RES_VOID;
    pd->pkt_rx = RES_VOID;
    pd->hMDIO = RES_VOID;
    pd->smphr = RES_VOID;
    pd->intrpt = RES_VOID;
    pd->hGPIO = RES_VOID;
  }
}


// ---------------------------------------------------------------------------
// !: fn: void emac_requeue( EMAC_Device *pd )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция получает текущее значение секунд value
// !: d: из соответствующего регистра часов реального времени. <br>
// !: d: В случае успеха возвращает 0, иначе: <br>
// !: d: ERROR_RTC_ACK - таймаут ожидания ответа от часов. <br>
// !: d: 
// !: d: Данная функция не доступна пользователю.
// !: -:
// ---------------------------------------------------------------------------
int32 emac_requeue( EMAC_Device *pd, new_queue *nq )
{
  EMAC_Config* econf = &pd->Config;
  int32 error = OSE_OK;

  if( pd != NULL )
  {
    EMAC_stop( pd );

    sleep_m(1000);

    pd->pkt_tx   = RES_VOID;
    pd->pkt_rx   = RES_VOID;
    pd->pkt_data = RES_VOID;

    mem_free(net_mem_page);

    //Allocate Memory
    econf->RxMaxPktPool = nq->rx_count;
    econf->TxMaxPktPool = nq->tx_count;

    uint32 hsize = get_alloc_mem_size(econf);
    net_mem_page = mem_alloc( hsize,1 );
    if( net_mem_page == NULL )
      return OSE_NO_MEMORY;
    net_data_ptr = (char*)net_mem_page + ((sizeof(s_os_mem_block)+0x3f)&~0x3f);
    //clear all allocated memory
    //memset(net_data_ptr,0,hsize-((sizeof(s_os_mem_block)+0x3f)&~0x3f));

    uint32 shift_ptr1,shift_ptr2;

    shift_ptr1 = (sizeof(EMAC_Pkt) * econf->RxMaxPktPool) + (8-(sizeof(EMAC_Pkt) * econf->RxMaxPktPool)&0x7);
    shift_ptr2 = shift_ptr1+(sizeof(EMAC_Pkt) * econf->TxMaxPktPool) + (8-(sizeof(EMAC_Pkt) * econf->TxMaxPktPool)&0x7);

    pd->pkt_rx   = (EMAC_Pkt*)net_data_ptr;
    pd->pkt_tx   = (EMAC_Pkt*)(net_data_ptr + shift_ptr1);
    pd->pkt_data = (uint8*)(net_data_ptr+shift_ptr2);       
    //------------------------------------
    // Queue up some initialized receive buffers //
    for( uint32 i=0; i < (econf->RxMaxPktPool); i++ )
    {
      pd->pkt_rx[i].prev = pd->pkt_rx;
      pd->pkt_rx[i].size = 1514;
      pd->pkt_rx[i].data = &pd->pkt_data[i * NET_PACKET_SIZE];
      Queue_push( &pd->intrpt, &pd->RxQueue, &pd->pkt_rx[i] );
    }
    // Queue up some transmit buffers /
    for( uint32 i=0; i < (pd->Config.TxMaxPktPool); i++ )
    {
      pd->pkt_tx[i].prev = pd->pkt_tx;
      pd->pkt_tx[i].size = 1514;
      pd->pkt_tx[i].data = &pd->pkt_data[(econf->RxMaxPktPool + i) * NET_PACKET_SIZE];
      Queue_push( &pd->intrpt, &pd->TxQueue, &pd->pkt_tx[i] );
    }
        
    setupBuffers( pd );
    startupEMAC( pd );
  }

heap_alloc_fail:
  if( error )
  {
    pd->pkt_tx   = RES_VOID;
    pd->pkt_rx   = RES_VOID;
    pd->pkt_data = RES_VOID;
    econf->RxMaxPktPool = 0;
    econf->TxMaxPktPool = 0;
	    
    mem_free(net_mem_page);
  }
  return error;
}

// ---------------------------------------------------------------------------
// !: fn: void HwInt(void)
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция обработки прерывания от модуля EMAC. < br>
// !: d: 
// !: d: Данная функция не доступна пользователю.
// !: -:
// ---------------------------------------------------------------------------
void HwInt(void)
{
  if ( hEMAC )
  {
    EMAC_serviceCheck(hEMAC);
  }
  return;
}
// ---------------------------------------------------------------------------
uint32 get_alloc_mem_size(EMAC_Config* econf)
{
  uint32 msize = ((sizeof(s_os_mem_block)+0x3f)&~0x3f)+
                 (sizeof(EMAC_Pkt) * econf->TxMaxPktPool)+(8-(sizeof(EMAC_Pkt) * econf->TxMaxPktPool)&0x7)+ 
                 (sizeof(EMAC_Pkt) * econf->RxMaxPktPool)+(8-(sizeof(EMAC_Pkt) * econf->RxMaxPktPool)&0x7)+
                 (NET_PACKET_SIZE * ( econf->RxMaxPktPool + econf->TxMaxPktPool ));
 
  return msize;
}
// ---------------------------------------------------------------------------


