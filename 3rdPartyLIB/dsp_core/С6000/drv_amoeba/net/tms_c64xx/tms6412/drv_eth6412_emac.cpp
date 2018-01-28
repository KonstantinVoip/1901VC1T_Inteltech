// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp1251
// !: d: Модуль содержит реализацию функций работы с модулем EMAC
// !: d: процессора tms320c6412.
// !: -: 
// ---------------------------------------------------------------------------
#include <drv_eth6412_emac.h>
#include <drv_eth6412_mdio.h>

#include <rts.h>




/*
// Although the EMAC API is defined to support multiple device instances,
// this version supports a single device instance
*/

/* Local copy of the EMAC device instance */
static uint32             openFlag = 0;
#define EMAC_NUMSTATS   36         /* The number of statistics regs */


// Local Helper Functions
static void emacUpdateStats( EMAC_Device *pd );
static void emacDequeueTx( EMAC_DescCh *pdc, EMAC_Desc *pDescLast );
static void emacEnqueueRx( EMAC_DescCh *pdc, uint32 fRestart );
static void emacDequeueRx( EMAC_DescCh *pdc, EMAC_Desc *pDescAck );



// ---------------------------------------------------------------------------
// !: fn: EMAC_Pkt *pqPop( PKTQ *pq )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция получает пакет EMAC_Pkt из очереди пакетов pq. <br>
// !: d: 
// !: d: Входные параметры: <br>
// !: d:   pq       - очередь, из которой берется пакет; <br>
// !: d: Возвращаемое значение: <br>
// !: d:   EMAC_Pkt - получаемый пакет. В случае отсутствия пакетов в очереди
// !: d:   возвращается 0. <br>
// !: d: 
// !: d: Данная функция не доступна пользователю.
// !: -:
// ---------------------------------------------------------------------------
EMAC_Pkt *pqPop( PKTQ *pq )
{
    EMAC_Pkt *pPktHdr;

    pPktHdr = pq->pHead;

    if( pPktHdr )
    {
        pq->pHead = pPktHdr->next;
        pq->Count--;
    }
    pPktHdr->next = 0;

    return( pPktHdr );
}

// ---------------------------------------------------------------------------
// !: fn: void pqPush( PKTQ *pq, EMAC_Pkt *pPktHdr )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция помещает пакет pPktHdrt в очередь пакетов pq. <br>
// !: d: 
// !: d: Входные параметры: <br>
// !: d:   pq       - очередь, в которую помещается пакет; <br>
// !: d:   pPktHdr  - пакет, помещаемый в очередь.  <br>
// !: d: Возвращаемое значение: <br>
// !: d:   нет. <br>
// !: d: 
// !: d: Данная функция не доступна пользователю.
// !: -:
// ---------------------------------------------------------------------------
void pqPush( PKTQ *pq, EMAC_Pkt *pPktHdr )
{
    pPktHdr->next = 0;

    if( !pq->pHead )
    {
        // Queue is empty - Initialize it with this one packet
        pq->pHead = pPktHdr;
        pq->pTail = pPktHdr;
    }
    else
    {
        // Queue is not empty - Push onto END
        pq->pTail->next = pPktHdr;
        pq->pTail        = pPktHdr;
    }
    pq->Count++;
}


/*--------------------------------------------------------------------*\
* emacUpdateStats()
*
* Update our local copy of the statistics
\*--------------------------------------------------------------------*/

// ---------------------------------------------------------------------------
// !: fn: static void emacUpdateStats( EMAC_Device *pd )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция обновляет статистику использования модуля EMAC. <br>
// !: d: Возвращаемое значение: <br>
// !: d:   нет. <br>
// !: d: 
// !: d: Данная функция не доступна пользователю.
// !: -:
// ---------------------------------------------------------------------------
static void emacUpdateStats( EMAC_Device *pd )
{
    int             i;
    volatile uint32 *pRegAddr;
    uint32          statval;

    pRegAddr = EMAC_ADDR(RXGOODFRAMES);

    // There are "EMAC_NUMSTATS" statistics registers
    // Note that when MIIEN is set in MACCONTROL, these registers
    // are "write to decrement".
    for( i=0; i<EMAC_NUMSTATS; i++ )
    {
        statval = *pRegAddr;
        *pRegAddr++ = statval;
    }
}

// ---------------------------------------------------------------------------
// !: fn: void emacTxPutPkt( EMAC_DescCh *pdc, EMAC_Pkt *pPktNew )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция ставит свободный пакет pPktNew в приемную очередь канала pdc. <br>
// !: d: Входные параметры: <br>
// !: d:   pdc      - обрабатываемый приемный канал; <br>
// !: d:   pPktNew  - свободный пакет; <br>
// !: d: Возвращаемое значение: <br>
// !: d:   нет. <br>
// !: d: 
// !: d: Данная функция не доступна пользователю.
// !: -:
// ---------------------------------------------------------------------------
void emacTxPutPkt( EMAC_DescCh *pdc, EMAC_Pkt *pPktNew )
{
    EMAC_Desc   *pDescOrg,*pDescThis;
    uint32        CountOrg;

    // We just fill in as much packet descriptor stuff as we can.
    pDescOrg = pdc->pDescWrite;
    CountOrg = pdc->DescCount;

    // Try to post any waiting packets /
    {
        // The next packet will fit, post it. /

            // Assign the pointer to "this" desc /
            pDescThis = pdc->pDescWrite;
                        pPktNew->dev_desc = pDescThis;

            // Move the write pointer and bump count /
            if( pdc->pDescWrite == pdc->pDescLast )
                pdc->pDescWrite = pdc->pDescFirst;
            else
                pdc->pDescWrite++;
            pdc->DescCount++;

            // If this is the last frag, the forward pointer is NULL
            // Otherwise; this desc points to the next frag's desc
            pDescThis->pNext = 0;

            pDescThis->pBuffer   = pPktNew->data;
            pDescThis->BufOffLen = pPktNew->length;
            pDescThis->PktFlgLen = ((EMAC_PKT_FLAGS_SOP|EMAC_PKT_FLAGS_EOP)
                                      |pPktNew->length|EMAC_DSC_FLAG_OWNER);

            // Enqueue this frag onto the desc queue /
            pqPush( &pdc->DescQueue, pPktNew );
    }

    // If we posted anything, chain on the list or start the transmitter /
    if( CountOrg != pdc->DescCount )
    {
        if( CountOrg )
        {
            // Transmitter is already running. Just tack this packet on
            // to the end of the list (we need to "back up" one descriptor)
            if( pDescOrg == pdc->pDescFirst )
                pDescThis = pdc->pDescLast;
            else
                pDescThis = pDescOrg - 1;
            pDescThis->pNext = pDescOrg;
        }
        else
        {
            // Transmitter is not running, start it up /
            EMAC_RSETI( TXHDP, pdc->ChannelIndex, (uint32)pDescOrg );
        }
    }
}









/*--------------------------------------------------------------------*\
* emacDequeueTx()
*
* Dequeue all completed TX packets and return buffers to application
\*--------------------------------------------------------------------*/

// ---------------------------------------------------------------------------
// !: fn: static void emacDequeueTx( EMAC_DescCh *pdc, EMAC_Desc *pDescAck )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция обрабатывает передающий канал pdc: <br>
// !: d: - перемещает пакеты с переданными данными из передающей очереди в очередь ожидания; <br>
// !: d: - если остались не переданные пакеты и процесс передачи остановлен, перезапускает процесс передачи. <br>
// !: d: Входные параметры: <br>
// !: d:   pdc      - обрабатываемый канал; <br>
// !: d:   pDescAck - последний переданный пакет; <br>
// !: d: Возвращаемое значение: <br>
// !: d:   нет. <br>
// !: d: 
// !: d: Данная функция не доступна пользователю.
// !: -:
// ---------------------------------------------------------------------------
static void emacDequeueTx( EMAC_DescCh *pdc, EMAC_Desc *pDescAck )
{
    EMAC_Pkt     *pPkt;
    uint32      PktFlgLen;
    register uint32  i,j = (uint32)pdc->pDescRead;

    // Get the status of the ACK descriptor /
    PktFlgLen = pDescAck->PktFlgLen;

    // Calc the new "Read" descriptor /
    if( pDescAck == pdc->pDescLast )
        pdc->pDescRead = pdc->pDescFirst;
    else
        pdc->pDescRead = pDescAck+1;

    i = (uint32)pdc->pDescRead;

    // Turn i into a descriptor count /
    if( j < i )
        i = (i-j)/sizeof(EMAC_Desc);
    else
        i = pdc->DescMax - ((j-i)/sizeof(EMAC_Desc));

    pdc->DescCount-=i;

    // Pop & Free Buffers 'till the last Descriptor /
    while(i--)
    {
        // Recover the buffer and free it /
        pPkt = pqPop( &pdc->DescQueue );
        if( pPkt )
            pqPush( &pdc->pd->TxQueue, pPkt );
    }

    // If the transmitter stopped and we have more descriptors, then restart /
    if( (PktFlgLen & EMAC_DSC_FLAG_EOQ) && pdc->DescCount )
        EMAC_RSETI( TXHDP, pdc->ChannelIndex, (uint32)pdc->pDescRead );
}


/*--------------------------------------------------------------------*\
* emacEnqueueRx()
*
* Fill any empty RX descriptors with new buffers from the application
\*--------------------------------------------------------------------*/

// ---------------------------------------------------------------------------
// !: fn: static void emacEnqueueRx( EMAC_DescCh *pdc, uint32 fRestart )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция обрабатывает приемный канал pdc: <br>
// !: d: - перемещает пустые пакеты очереди свободных пакетов в приемную очередь; <br>
// !: d: - в зависимости от значения fRestart запускает процесс приема. <br>
// !: d: Входные параметры: <br>
// !: d:   pdc      - обрабатываемый приемный канал; <br>
// !: d: Возвращаемое значение: <br>
// !: d:   нет. <br>
// !: d: 
// !: d: Данная функция не доступна пользователю.
// !: -:
// ---------------------------------------------------------------------------
static void emacEnqueueRx( EMAC_DescCh *pdc, uint32 fRestart )
{
    EMAC_Pkt     *pPkt;
    EMAC_Desc   *pDesc;
    uint32        CountOrg;
        EMAC_Device             *pDev = pdc->pd;

    // Keep the old count around /
    CountOrg = pdc->DescCount;

    // Fill RX Packets Until Full /
    while( pdc->DescCount < pdc->DescMax )
    {
        // Get a buffer from the application /
        pPkt = pqPop( &pdc->pd->RxQueue );
        // If no more buffers are available, break out of loop /
        if( !pPkt )
            break;

        // Fill in the descriptor for this buffer /
        pDesc = pdc->pDescWrite;

        // Move the write pointer and bump count /
        if( pdc->pDescWrite == pdc->pDescLast )
            pdc->pDescWrite = pdc->pDescFirst;
        else
            pdc->pDescWrite++;
        pdc->DescCount++;

        // Supply buffer pointer with application supplied offset /
        pDesc->pNext     = 0;
        pDesc->pBuffer   = pPkt->data;
        pDesc->BufOffLen = pDev->PktMTU;
        pDesc->PktFlgLen = EMAC_DSC_FLAG_OWNER;

        pPkt->dev_desc = pDesc;
        
        // Make the previous buffer point to us /
        if( pDesc == pdc->pDescFirst )
             pdc->pDescLast->pNext = pDesc;
        else
            (pDesc-1)->pNext = pDesc;

        // Push the packet buffer on the local descriptor queue /
        pqPush( &pdc->DescQueue, pPkt );
    }

    // Restart RX if we had ran out of descriptors and got some here /
    if( fRestart && !CountOrg && pdc->DescCount )
        EMAC_RSET( RX0HDP, (uint32)pdc->pDescRead );
}



// ---------------------------------------------------------------------------
// !: fn: void emacRxPutPkt( EMAC_DescCh *pdc, EMAC_Pkt *pPktNew )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция ставит свободный пакет pPktNew в приемную очередь канала pdc. <br>
// !: d: Входные параметры: <br>
// !: d:   pdc      - приемный канал; <br>
// !: d:   pPktNew  - свободный пакет; <br>
// !: d: Возвращаемое значение: <br>
// !: d:   нет. <br>
// !: d: 
// !: d: Данная функция не доступна пользователю.
// !: -:
// ---------------------------------------------------------------------------
void emacRxPutPkt( EMAC_DescCh *pdc, EMAC_Pkt *pPktNew )
{
    EMAC_Desc   *pDesc;
    uint32        CountOrg;

    // Fill RX Packets /

        // Fill in the descriptor for this buffer /
        pDesc = pdc->pDescWrite;
        
        pPktNew->dev_desc = pDesc;
        
        int_lock( pdc->pd->intrpt );
        
        // Keep the old count around /
        CountOrg = pdc->DescCount;
        // Move the write pointer and bump count /
        if( pdc->pDescWrite == pdc->pDescLast )
            pdc->pDescWrite = pdc->pDescFirst;
        else
            pdc->pDescWrite++;
        pdc->DescCount++;
        
        // Supply buffer pointer with application supplied offset /
        pDesc->pNext     = 0;
        pDesc->pBuffer   = pPktNew->data;
        pDesc->BufOffLen = pdc->pd->PktMTU;
        pDesc->PktFlgLen = EMAC_DSC_FLAG_OWNER;

                // Add reclaimed buffers
//                EMAC_RSET( RX0FREEBUFFER, 1 );
        
        // Push the packet buffer on the local descriptor queue /
        pqPush( &pdc->DescQueue, pPktNew );
        int_unlock( pdc->pd->intrpt );
        
        // Make the previous buffer point to us /
        if( pDesc == pdc->pDescFirst )
             pdc->pDescLast->pNext = pDesc;
        else
            (pDesc-1)->pNext = pDesc;

    // Restart RX if we had ran out of descriptors and got some here /
    if( !CountOrg && pdc->DescCount )
    {
        EMAC_RSET( RX0HDP, (uint32)pdc->pDescRead );
    }
}


/*--------------------------------------------------------------------*\
* emacDequeueRx()
*
* Dequeue all completed RX packets and give buffers to application
\*--------------------------------------------------------------------*/

// ---------------------------------------------------------------------------
// !: fn: static void emacDequeueRx( EMAC_DescCh *pdc, EMAC_Desc *pDescAck )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: Функция обрабатывает приемный канал pdc: <br>
// !: d: - перемещает пакеты с принятыми данными из приемной очереди в очередь ожидания; <br>
// !: d: - если остались свободные пакеты и процесс приема остановлен, перезапускает процесс приема. <br>
// !: d: Входные параметры: <br>
// !: d:   pdc      - приемный канал; <br>
// !: d:   pDescAck - последний пакет с принятыми данными; <br>
// !: d: Возвращаемое значение: <br>
// !: d:   нет. <br>
// !: d: 
// !: d: Данная функция не доступна пользователю.
// !: -:
// ---------------------------------------------------------------------------
static void emacDequeueRx( EMAC_DescCh *pdc, EMAC_Desc *pDescAck )
{
    EMAC_Pkt     *pPkt;
    uint32        tmp;
    uint32      PktFlgLen;

    // Pop & Free Buffers 'till the last Descriptor
    // One thing we know for sure is that all the decriptors from
    // the read pointer to pDescAsk are linked to each other via
    // their pNext field.
    for( tmp=1; tmp; )
    {
        // Get the status of this descriptor /
        PktFlgLen = pdc->pDescRead->PktFlgLen;

        // Recover the buffer and free it /
        pPkt = pqPop( &pdc->DescQueue );
        if( pPkt )
        {
            // Fill in the necessary packet header fields /
            pPkt->size = NET_PACKET_SIZE;
            pPkt->length = PktFlgLen & 0x0000FFFF;

            // Pass the packet to the application /
            pqPush( &pdc->pd->RxQueue, pPkt );
        }

        // See if this was the last buffer /
        if( pdc->pDescRead == pDescAck )
            tmp = 0;

        // Move the read pointer and decrement count /
        if( pdc->pDescRead == pdc->pDescLast )
            pdc->pDescRead = pdc->pDescFirst;
        else
            pdc->pDescRead++;
        pdc->DescCount--;
    }
    
    // If the receiver stopped and we have more descriptors, then restart /
    if( (PktFlgLen & EMAC_DSC_FLAG_EOQ) && pdc->DescCount )
    {
        EMAC_RSET( RX0HDP, (uint32)pdc->pDescRead );
    }
}


/*-----------------------------------------------------------------------*\
* EMAC_open()
*
* Opens the EMAC peripheral at the given physical index and initializes
* it to an embryonic state.
*
* The calling application must supply a operating configuration that
* includes a callback function table. Data from this config structure is
* copied into the device's internal instance structure so the structure
* may be discarded after EMAC_open() returns. In order to change an item
* in the configuration, the the EMAC device must be closed and then
* re-opened with the new configuration.
*
* The application layer may pass in an hApplication callback handle,
* that will be supplied by the EMAC device when making calls to the
* application callback functions.
*
* An EMAC device handle is written to phEMAC. This handle must be saved
* by the caller and then passed to other EMAC device functions.
*
* The default receive filter prevents normal packets from being received
* until the receive filter is specified by calling EMAC_receiveFilter().
*
* A device reset is achieved by calling EMAC_close() followed by EMAC_open().
*
* The function returns zero on success, or an error code on failure.
*
* Possible error codes include:
*   OSE_ALREADY_PLUGGED   - The device is already open
*   OSE_BAD_PARAM   - A calling parameter is invalid
*   OSE_WRONG_QUEUE_SIZE
*
\*-----------------------------------------------------------------------*/
int32 EMAC_open( Handle hApplication,
                EMAC_Config *pEMACConfig, EMAC_Device *phEMAC )
{
    // If the device is already open, return an error /
    if( openFlag )
        return( OSE_ALREADY_PLUGGED );

    // Rx pool must be at least 8 to 192 /
    if( pEMACConfig->RxMaxPktPool < 1 || pEMACConfig->RxMaxPktPool > 192 )
        return( OSE_WRONG_QUEUE_SIZE );

    // Callback functions must be supplied /
    if( !pEMACConfig->pfcbGetPacket || !pEMACConfig->pfcbPutPacket )
        return( OSE_BAD_PARAM );

    // MDIO settings must be valid - at least one bit must be set /
/*    if( !(pEMACConfig->MdioModeFlags & ( MDIO_MODEFLG_AUTONEG |
                MDIO_MODEFLG_HD10  | MDIO_MODEFLG_FD10 |
                MDIO_MODEFLG_HD100 | MDIO_MODEFLG_FD100 )) )
        return( OSE_BAD_PARAM );
*/
    // Init the instance structure

    // Set the hApplication and RxFilter /
    phEMAC->hApplication = hApplication;
    phEMAC->RxFilter     = EMAC_RXFILTER_NOTHING;
    
    initEMAC( pEMACConfig, phEMAC );
    setupBuffers( phEMAC );

    // Set the open flag /
//    openFlag = 1;

//    startupEMAC( phEMAC );
    
    // Return Success /
    return( OSE_OK );
}

void initEMAC(EMAC_Config *pEMACConfig, EMAC_Device *phEMAC)
{
    int             i;
    volatile uint32 *pRegAddr;
    uint32          tmpval;
    
    /*
    //  Initialize the EMAC and MDIO devices
    */

    // Globally disable EMAC/MDIO interrupts in wrapper and put both
    // EMAC and MDIO modules into reset
    EMAC_RSET( EWCTL, EMAC_FMKS( EWCTL, INTEN, DISABLE ) |
                      EMAC_FMKS( EWCTL, EMACRST, YES ) |
                      EMAC_FMKS( EWCTL, MDIORST, YES ) );

    // Wait about 100 cycles /
    for( i=0; i<5; i++ )
        tmpval = EMAC_RGET( EWCTL );

    // Leave EMAC/MDIO interrupts disabled and take both
    // EMAC and MDIO modules out of reset 
    EMAC_RSET( EWCTL, EMAC_FMKS( EWCTL, INTEN, DISABLE ) |
                      EMAC_FMKS( EWCTL, EMACRST, NO ) |
                      EMAC_FMKS( EWCTL, MDIORST, NO ) );

    // Wait about 100 cycles /
    for( i=0; i<5; i++ )
        tmpval = EMAC_RGET( EWCTL );

    // Set EMAC Priority to ”1”, allocation reqs ”3” /
    EMAC_RSET( EWTRCTRL, 0x23 );

    // Set Interrupt Timer Count (CPUclk/4) /
//    EMAC_RSET( EWINTTCNT, 1500 );
        EMAC_RSET( EWINTTCNT, 0 );

    // Start the MII Configuration /
    MDIO_open( phEMAC->hMDIO, pEMACConfig->MdioModeFlags );

    /*
    //  Setup the EMAC
    */

    // Reset MAC Control /
    EMAC_RSET( MACCONTROL, 0 );

    // Must manually init HDPs to NULL /
    pRegAddr = EMAC_ADDR(TX0HDP);
    for( i=0; i<8; i++ )
        *pRegAddr++ = 0;
    pRegAddr = EMAC_ADDR(RX0HDP);
    for( i=0; i<8; i++ )
        *pRegAddr++ = 0;

    // While MIIEN is clear in MACCONTROL, we can write directly to
    // the statistics registers (there are "EMAC_NUMSTATS" of them).
    pRegAddr = EMAC_ADDR(RXGOODFRAMES);
    for( i=0; i<EMAC_NUMSTATS; i++ )
        *pRegAddr++ = 0;

    // Setup device MAC address /
    EMAC_RSET( MACADDRL0, phEMAC->ncfg.mac[5] );
    EMAC_RSET( MACADDRM, phEMAC->ncfg.mac[4] );
    tmpval = 0;
    for( i=3; i>=0; i-- )
        tmpval = (tmpval<<8) | phEMAC->ncfg.mac[i];
    EMAC_RSET( MACADDRH, tmpval );

    /*
    // Setup Special Receive Conditions (loopback, error frames, etc)
    */

    // For us buffer offset will always be zero /
    EMAC_RSET( RXBUFFEROFFSET, 0 );

    // Reset RX (M)ulticast (B)roadcast (P)romiscuous Enable register /
    EMAC_RSET( RXMBPENABLE, 0 );
    EMAC_RSET( MACHASH1, 0 );
    EMAC_RSET( MACHASH2, 0 );

    // Clear Unicast RX on channel 0-7 /
    EMAC_RSET( RXUNICASTCLEAR, 0xFF );

    // Set the pass RX CRC mode and adjust max buffer accordingly /
    if( phEMAC->Config.ModeFlags & EMAC_CONFIG_MODEFLG_RXCRC )
    {
        EMAC_FSETS( RXMBPENABLE, RXPASSCRC, INCLUDE );
        phEMAC->PktMTU = 1518;
    }
    else
        phEMAC->PktMTU = 1514;

    // Initialize flowthresh condition
//    EMAC_RSET( RX0FREEBUFFER, pEMACConfig->RxMaxPktPool );
//    EMAC_RSET( RX0FLOWTHRESH, 1 );

        
    // Set MAC fullduplex /
    EMAC_FSETS( MACCONTROL, FULLDUPLEX, ENABLE );

//        EMAC_FSETS( MACCONTROL, TXFLOWEN, ENABLE );
//        EMAC_FSETS( MACCONTROL, RXFLOWEN, ENABLE );

    // If PASSERROR is set, enable both ERROR and short frames /
    if( phEMAC->Config.ModeFlags & EMAC_CONFIG_MODEFLG_PASSERROR )
    {
        EMAC_FSETS( RXMBPENABLE, RXCEFEN, ENABLE );
        EMAC_FSETS( RXMBPENABLE, RXCSFEN, ENABLE );
    }

    // If PASSCONTROL is set, enable control frames /
    if( phEMAC->Config.ModeFlags & EMAC_CONFIG_MODEFLG_PASSCONTROL )
        EMAC_FSETS( RXMBPENABLE, RXCMFEN, ENABLE );

    // Set the channel configuration to priority if requested /
    if( phEMAC->Config.ModeFlags & EMAC_CONFIG_MODEFLG_CHPRIORITY )
        EMAC_FSETS( MACCONTROL, TXPTYPE, CHANNELPRI );

    // Set MAC loopback if requested /
    if( phEMAC->Config.ModeFlags & EMAC_CONFIG_MODEFLG_MACLOOPBACK )
        EMAC_FSETS( MACCONTROL, LOOPBACK, ENABLE );

    // Enable TX and RX channel interrupts (set mask bits)
    // Enable Host interrupts
    EMAC_RSET( RXINTMASKCLEAR, 0xFF );
    EMAC_RSET( TXINTMASKCLEAR, 0xFF );
    EMAC_RSET( RXINTMASKSET, 1 );
//    for(i=0; i<phEMAC->Config.TxChannels; i++)
//        EMAC_RSET( TXINTMASKSET, (1<<i) );
    EMAC_RSET( TXINTMASKSET, (1<<0) );
    
    EMAC_RSET( MACINTMASKSET, EMAC_FMK(MACINTMASKSET,HOSTERRINT,1) |
                              EMAC_FMK(MACINTMASKSET,STATINT,1) );
}




void setupBuffers(EMAC_Device *phEMAC)
{
//    int             i;
    uint32            utemp1;
    EMAC_Desc       *pDesc;
    
    /*
    // Setup Receive Buffers
    */

    // We give the first descriptors to RX The rest of the descriptors
    // will be divided evenly among the TX channels. Odds are this
    // will leave TX with a very large number of TX descriptors, but
    // we'll only use what we need (driven from the application send
    // requests). The RX descriptors are always kept fully populated.

    // Pointer to first descriptor to use on RX /
    pDesc = (EMAC_Desc *)_EMAC_DSC_BASE_ADDR;

    // Number of descriptors for RX channel /
    utemp1 = phEMAC->Config.RxMaxPktPool;

    // Init Rx /
    phEMAC->RxCh.pd         = phEMAC;
    phEMAC->RxCh.DescMax    = utemp1;
    phEMAC->RxCh.pDescFirst = pDesc;
    phEMAC->RxCh.pDescLast  = pDesc + (utemp1 - 1);
    phEMAC->RxCh.pDescRead  = pDesc;
    phEMAC->RxCh.pDescWrite = pDesc;

    // Fill the descriptor table /
    emacEnqueueRx( &phEMAC->RxCh, 0 );

    /*
    // Setup Transmit Buffers
    */

    // Pointer to first descriptor to use on TX /
    pDesc += utemp1;
    
    // Number of descriptors for TX channel /
    utemp1 = phEMAC->Config.TxMaxPktPool;

    // Init all TX channels in use /
/*
    for( i=0; i<(int)phEMAC->Config.TxChannels; i++)
    {
        phEMAC->TxCh[i].pd         = phEMAC;
        phEMAC->TxCh[i].ChannelIndex    = 0;
        phEMAC->TxCh[i].DescMax    = utemp1;
        phEMAC->TxCh[i].pDescFirst = pDesc;
        phEMAC->TxCh[i].pDescLast  = pDesc + (utemp1 - 1);
        phEMAC->TxCh[i].pDescRead  = pDesc;
        phEMAC->TxCh[i].pDescWrite = pDesc;

        pDesc += utemp1;
    }
*/
    phEMAC->TxCh.pd         = phEMAC;
    phEMAC->TxCh.ChannelIndex    = 0;
    phEMAC->TxCh.DescMax    = utemp1;
    phEMAC->TxCh.pDescFirst = pDesc;
    phEMAC->TxCh.pDescLast  = pDesc + (utemp1 - 1);
    phEMAC->TxCh.pDescRead  = pDesc;
    phEMAC->TxCh.pDescWrite = pDesc;

    pDesc += utemp1;
}

void startupEMAC( EMAC_Device *phEMAC )
{
   /*
    // Enable RX, TX, and MII
    */
    // Note in full duplex mode we also need to set the FULLDUPLEX
    // bit in MACCRONTROL. However, we don't know what to set until
    // we have a link. Also, we must be able to dynamically change
    // this bit if the cable is unplugged and re-linked with a different
    // duplex.
    EMAC_FSETS( TXCONTROL, TXEN, ENABLE );
    EMAC_FSETS( RXCONTROL, RXEN, ENABLE );
    EMAC_FSETS( MACCONTROL, MIIEN, ENABLE );

    // Startup RX /
    EMAC_RSET( RX0HDP, (uint32)phEMAC->RxCh.pDescRead );

    // Enable global interrupt in wrapper /
    EMAC_FSETS( EWCTL, INTEN, ENABLE );

    // Set the open flag /
    openFlag = 1;
}


/*-----------------------------------------------------------------------*\
* EMAC_close()
*
* Closed the EMAC peripheral indicated by the supplied instance handle.
* When called, the EMAC device will shutdown both send and receive
* operations, and free all pending transmit and receive packets.
*
* The function returns zero on success, or an error code on failure.
*
* Possible error code include:
*   EMAC_ERROR_INVALID   - A calling parameter is invalid
*
\*-----------------------------------------------------------------------*/
void EMAC_close( EMAC_Device  *pd )
{
    if(!openFlag)
	  return;

    EMAC_stop( pd );
    
    // Clear MACCONTROL /
    EMAC_RSET( MACCONTROL, 0 );
    
    // Close the MDIO Module /
    MDIO_close( &pd->hMDIO );

    // Clear the open flag /
    openFlag = 0;
}


void EMAC_stop( EMAC_Device  *pd )
{
    uint32      tmp;
    EMAC_Pkt    *pPkt;

    // Disable EMAC/MDIO interrupts in wrapper /
    EMAC_FSETS( EWCTL, INTEN, DISABLE );

    /*
    // The close process consists of tearing down all the active
    // channels (RX and TX) and then waiting for the teardown
    // complete indication from the MAC. Then, all queued packets
    // will be returned.
    */
        // Teardown RX /
        EMAC_RSET( RXTEARDOWN, 0 );

        // Teardown TX channels in use /
        EMAC_RSET( TXTEARDOWN, 0 );

    // Only check teardown status if there was no fatal error         /
    // Otherwise; the EMAC is halted and can’t be shutdown gracefully /
    if( !pd->FatalError )
    {
        // Wait for the teardown to complete /
        for( tmp=0; tmp!=0xFFFFFFFC; tmp=EMAC_RGET(RX0INTACK) );
        EMAC_RSET( RX0INTACK, tmp );

        for( tmp=0; tmp!=0xFFFFFFFC; tmp=EMAC_RGETI(TXINTACK,0) );
        EMAC_RSETI( TXINTACK, 0, tmp );
    }
    
    // Disable RX, TX /
    EMAC_FSETS( TXCONTROL, TXEN, DISABLE );
    EMAC_FSETS( RXCONTROL, RXEN, DISABLE );
    
    // Free all RX buffers /
    while( pPkt = pqPop( &(pd->RxCh.DescQueue) ) )
	{
		if( pPkt != NULL )
		{
	        pqPush( &pd->RxQueue, pPkt );
			pd->RxCh.DescCount--;
		}
	}
	while( pPkt = pqPop( &(pd->RxQueue) ) );

    // Free all TX buffers /
    while( pPkt = pqPop( &pd->TxCh.DescQueue ) )
	{
		if( pPkt != NULL )
		{
	        pqPush( &pd->TxQueue, pPkt );
			pd->TxCh.DescCount--;
		}
	}
    while( pPkt = pqPop( &pd->TxCh.WaitQueue ) )
	{
		if( pPkt != NULL )
		{
	        pqPush( &pd->TxQueue, pPkt );
			pd->TxCh.DescCount--;
		}
	}

	while( pPkt = pqPop( &pd->TxQueue ) );
}



/*-----------------------------------------------------------------------*\
* EMAC_setReceiveFilter()
*
* Called to set the packet filter for received packets. The filtering
* level is inclusive, so BROADCAST would include both BROADCAST and
* DIRECTED (UNICAST) packets.
*
* Available filtering modes include the following:
*  EMAC_RXFILTER_NOTHING      - Receive nothing
*  EMAC_RXFILTER_DIRECT       - Receive only Unicast to local MAC addr
*  EMAC_RXFILTER_BROADCAST    - Receive direct and Broadcast
*  EMAC_RXFILTER_MULTICAST    - Receive above plus multicast in mcast list
*  EMAC_RXFILTER_ALLMULTICAST - Receive above plus all multicast
*  EMAC_RXFILTER_ALL          - Receive all packets
*
* Note that if error frames and control frames are desired, reception of
* these must be specified in the device configuration.
*
\*-----------------------------------------------------------------------*/
void EMAC_setReceiveFilter( Handle hEMAC, uint32 ReceiveFilter )
{
    EMAC_Device  *pd = (EMAC_Device *)hEMAC;

    /*
    // The following code relies on the numberic relation of the filter
    // value such that the higher filter values receive more types of
    // packets.
    */

    // Disable Section /
    if( ReceiveFilter < EMAC_RXFILTER_ALL )
        EMAC_FSETS( RXMBPENABLE, RXCAFEN, DISABLE );
    if( ReceiveFilter < EMAC_RXFILTER_ALLMULTICAST )
    {
        EMAC_RSET( MACHASH1, pd->MacHash1 );
        EMAC_RSET( MACHASH2, pd->MacHash2 );
    }
    if( ReceiveFilter < EMAC_RXFILTER_MULTICAST )
        EMAC_FSETS( RXMBPENABLE, MULTEN, DISABLE );
    if( ReceiveFilter < EMAC_RXFILTER_BROADCAST )
        EMAC_FSETS( RXMBPENABLE, BROADEN, DISABLE );
    if( ReceiveFilter < EMAC_RXFILTER_DIRECT )
        EMAC_RSET( RXUNICASTCLEAR, 1 );

    // Enable Section /
    if( ReceiveFilter >= EMAC_RXFILTER_DIRECT )
        EMAC_RSET( RXUNICASTSET, 1 );
    if( ReceiveFilter >= EMAC_RXFILTER_BROADCAST )
        EMAC_FSETS( RXMBPENABLE, BROADEN, ENABLE );
    if( ReceiveFilter >= EMAC_RXFILTER_MULTICAST )
        EMAC_FSETS( RXMBPENABLE, MULTEN, ENABLE );
    if( ReceiveFilter >= EMAC_RXFILTER_ALLMULTICAST )
    {
        EMAC_RSET( MACHASH1, 0xffffffff );
        EMAC_RSET( MACHASH1, 0xffffffff );
    }
    if( ReceiveFilter == EMAC_RXFILTER_ALL )
        EMAC_FSETS( RXMBPENABLE, RXCAFEN, ENABLE );

    pd->RxFilter = ReceiveFilter;
}


/*-----------------------------------------------------------------------*\
* EMAC_getReceiveFilter()
*
* Called to get the current packet filter setting for received packets.
* The filter values are the same as those used in EMAC_setReceiveFilter().
*
* The current filter value is writter to the pointer supplied in
* pReceiveFilter.
*
* The function returns zero on success, or an error code on failure.
*
* Possible error code include:
*   EMAC_ERROR_INVALID   - A calling parameter is invalid
*
\*-----------------------------------------------------------------------*/
uint32 EMAC_getReceiveFilter( Handle hEMAC, uint32 *pReceiveFilter )
{
    EMAC_Device  *pd = (EMAC_Device *)hEMAC;

    *pReceiveFilter = pd->RxFilter;
    return(0);
}


/*-----------------------------------------------------------------------*\
* EMAC_sendPacket()
*
* Sends a Ethernet data packet out the EMAC device. On a non-error return,
* the EMAC device takes ownership of the packet. The packet is returned
* to the application's free pool once it has been transmitted.
*
\*-----------------------------------------------------------------------*/
void EMAC_sendPacket( Handle hEMAC, EMAC_Pkt *pPkt )
{
    EMAC_Device  *pd = (EMAC_Device *)hEMAC;
//    EMAC_DescCh  *pdc;
//    static int32 i = 0;

    // Now pad for 60 byte min size. We only pad the last fragment /
    if( pPkt->length < 60 )
    {
        pPkt->length = 60;
    }

    // Get a local pointer to the descriptor channel /
//    pdc = &(pd->TxCh);

    int_lock( pd->intrpt );
    emacTxPutPkt( &(pd->TxCh), pPkt );
    int_unlock( pd->intrpt );
}


/*-----------------------------------------------------------------------*\
* EMAC_serviceCheck()
*
* This function should be called every time there is an EMAC device
* interrupt. It maintains the status the EMAC.
*
* Note that the application has the responsibility for mapping the
* physical device index to the correct EMAC_serviceCheck() function. If
* more than one EMAC device is on the same interrupt, the function must be
* called for each device.
*
* Possible error codes include:
*   EMAC_ERROR_INVALID   - A calling parameter is invalid
*   EMAC_ERROR_MACFATAL  - Fatal error in the MAC - Call EMAC_close()
*
\*-----------------------------------------------------------------------*/
uint32 EMAC_serviceCheck( Handle hEMAC )
{
    EMAC_Device  *pd = (EMAC_Device *)hEMAC;
    uint32      intflags,Desc;

    // Disable EMAC/MDIO interrupts /
    EMAC_FSETS( EWCTL, INTEN, DISABLE );

    // Read the interrupt cause /
    intflags = EMAC_RGET( MACINVECTOR );

    // Look for fatal errors first /
    if( intflags & EMAC_FMK( MACINVECTOR, HOSTPEND, 1 ) )
    {
        // Read the error status - we'll decode it by hand /
        pd->FatalError = EMAC_RGET( MACSTATUS );

        // return with interrupt disabled in the wrapper /
        return( EMAC_ERROR_MACFATAL );
    }

    // Look for link change interrupt /
    if( intflags & EMAC_FMK( MACINVECTOR, LINKINT, 1 ) )
    {
        // Clear the link change flag so we can detect a "re-link" later /
        MDIO_RSET( LINKINTRAW, 1 );
        if( MDIO_RGET( LINK ) )
        {
            ((MDIO_Device*)pd->hMDIO)->phyState = 4;    //  PHYSTATE_LINKED;
        }
        else
        {
            ((MDIO_Device*)pd->hMDIO)->phyState = 3;    //  PHYSTATE_LINKWAIT;
        }
    }
    
    // Look for statistics interrupt /
    if( intflags & EMAC_FMK( MACINVECTOR, STATPEND, 1 ) )
    {
        // Read the stats and reset to zero         /
        // This is necessary to clear the interrupt /
        emacUpdateStats( pd );

    }

    // Look for TX interrupt (channel 0-max) /
/*    for( tmp=0; tmp<pd->Config.TxChannels; tmp++ )
    {
        mask = EMAC_FMK( MACINVECTOR, TXPEND, 1<<tmp );
        if( intflags & mask )
        {
            //
            // For multichannel operation, we need to
            // apply an errata workaround.
            //
            do
            {
                Desc = EMAC_RGETI( TXINTACK, tmp );
                EMAC_RSETI( TXINTACK, tmp, Desc );
            } while( pd->Config.TxChannels>1 && (EMAC_RGET(MACINVECTOR)&mask) );

            emacDequeueTx( &pd->TxCh[tmp], (EMAC_Desc *)Desc );
        }
    }
*/
    // Look for TX interrupt (channel 0) /
    if( intflags & EMAC_FMK( MACINVECTOR, TXPEND, 1<<0 ) )
    {
        Desc = EMAC_RGETI( TXINTACK, 0 );
        EMAC_RSETI( TXINTACK, 0, Desc );

        emacDequeueTx( &pd->TxCh, (EMAC_Desc *)Desc );
    }


    // Look for RX interrupt (channel 0) /
    if( intflags & EMAC_FMK( MACINVECTOR, RXPEND, 1<<0 ) )
    {
        /*
        // For multichannel operation, we need to apply the
        // same errata workaround as TX. However this driver
        // example only supports one RX channel.
        */
        Desc = EMAC_RGET( RX0INTACK );
        EMAC_RSET( RX0INTACK, Desc );

        emacDequeueRx( &pd->RxCh, (EMAC_Desc *)Desc );
    }

    // Enable EMAC/MDIO interrupts in wrapper /
    EMAC_FSETS( EWCTL, INTEN, ENABLE );

    return(0);
}



