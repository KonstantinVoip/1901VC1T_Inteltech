// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp1251
// !: d: Модуль содержит реализацию функций работы с модулем EMAC
// !: d: процессора tms320c6457.
// !: -: 
// ---------------------------------------------------------------------------
#include <drv_eth6457_emac.h>

#include <os.h>
#include <rts.h>


// Although the EMAC API is defined to support multiple device instances,
// this version supports a single device instance

// Local copy of the EMAC device instance
static uint32             openFlag = 0;

// Local copy of the EMAC device instance

// Local Helper Functions
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
    volatile uint32  *pRegAddr;

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
            pRegAddr = &EMAC_REGS->TX0HDP;
            *(pRegAddr + pdc->ChannelIndex) = (uint32)pDescOrg;
        }
    }
}

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
    volatile uint32  *pRegAddr;

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
    {
        pRegAddr = &EMAC_REGS->TX0HDP;
        *(pRegAddr + pdc->ChannelIndex) = (uint32)pdc->pDescRead;
    }
}

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
	EMAC_Device		*pDev = pdc->pd;
    volatile uint32  *pRegAddr;

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
    {
        pRegAddr = &EMAC_REGS->RX0HDP;
        *(pRegAddr + pdc->ChannelIndex)= (uint32)pdc->pDescRead;
    }
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
    volatile uint32  *pRegAddr;

    // Fill RX Packets /

        // Fill in the descriptor for this buffer /
        pDesc = pdc->pDescWrite;
        
        pPktNew->dev_desc = pDesc;
        
        int_lock( pdc->pd->rx_intrpt );
        
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
		EMAC_REGS->RX0FREEBUFFER = 1;
        
        // Push the packet buffer on the local descriptor queue /
        pqPush( &pdc->DescQueue, pPktNew );
        int_unlock( pdc->pd->rx_intrpt );
        
        // Make the previous buffer point to us /
        if( pDesc == pdc->pDescFirst )
             pdc->pDescLast->pNext = pDesc;
        else
            (pDesc-1)->pNext = pDesc;

    // Restart RX if we had ran out of descriptors and got some here /
    if( !CountOrg && pdc->DescCount )
    {
        pRegAddr = &EMAC_REGS->RX0HDP;
        *(pRegAddr + pdc->ChannelIndex) = (uint32)pdc->pDescRead;
    }
}

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
    volatile uint32  *pRegAddr;

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
        pRegAddr = &EMAC_REGS->RX0HDP;
        *(pRegAddr + pdc->ChannelIndex) = (uint32)pdc->pDescRead;
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
    openFlag = 1;

    startupEMAC( phEMAC );
    
    // Return Success /
    return( OSE_OK );
}

void initEMAC(EMAC_Config *pEMACConfig, EMAC_Device *phEMAC)
{
    int             i;
    volatile uint32 *pRegAddr;
    uint32          tmpval;
    uint32 utemp1;
    
    /*
    //  Initialize the EMAC and MDIO devices
    */

    /* Disable wrapper interrupt pacing */
	ECTL_REGS->INT_CONTROL = 0x00;
	/*Give soft reset to Wrapper*/
	ECTL_REGS->SOFT_RESET = 0x01;
	while (ECTL_REGS->SOFT_RESET != 0x00000000);  /* Wait until reset has occured */

	/* Give soft reset to EMAC */
	EMAC_REGS->SOFTRESET = 0x00000001;
	while (EMAC_REGS->SOFTRESET != 0x00000000); /* Wait until reset has occured */

//	if (phEMAC->Config.UseMdio)
		/* Start the MII Configuration */
//        MDIO_open( phEMAC->hMDIO, pEMACConfig->MdioModeFlags );


    // Set EMAC Priority to ”1”, allocation reqs ”3” /
//    EMAC_RSET( EWTRCTRL, 0x23 );

    // Set Interrupt Timer Count (CPUclk/4) /
//    EMAC_RSET( EWINTTCNT, 1500 );
//	EMAC_RSET( EWINTTCNT, 0 );

    /*
    //  Setup the EMAC
    */

    // Reset MAC Control /
    EMAC_REGS->MACCONTROL = 0 ;

    // Must manually init HDPs to NULL /
    pRegAddr = &EMAC_REGS->TX0HDP;
	for (i = 0; i < 8; i++)
	    *pRegAddr++ = 0;

	pRegAddr = &EMAC_REGS->RX0HDP;
	for (i = 0; i < 8; i++)
		*pRegAddr++ = 0;

    /*
	* While GMIIEN is clear in MACCONTROL, we can write directly to
	* the statistics registers (there are "EMAC_NUMSTATS" of them).
	*/
	pRegAddr = &EMAC_REGS->RXGOODFRAMES;
	for (i = 0; i < EMAC_NUMSTATS; i++)
	    *pRegAddr++ = 0;

	/* Initialize the RAM locations */
	for (i = 0; i < 32; i++) {
	    EMAC_REGS->MACINDEX = i;
		EMAC_REGS->MACADDRHI = 0;
		EMAC_REGS->MACADDRLO = 0;
	}

	/* find the Rx channel number as
	 * soc is single core one receive channel is enough
	 */
	tmpval = 0;
	tmpval = phEMAC->Config.ChannelInfo.RxChanEnable;
	for (utemp1 = 0; tmpval != 0; tmpval >>= 1, utemp1 += 1)
		if (tmpval & 0x1)
			break;


    // Setup device MAC address /
    EMAC_REGS->MACINDEX = 0;

    tmpval = 0;
    for (i = 3; i >= 0; i--)
        tmpval = (tmpval << 8) | phEMAC->ncfg.mac[i];

    EMAC_REGS->MACADDRHI = tmpval;

    tmpval = phEMAC->ncfg.mac[5];
    EMAC_REGS->MACADDRLO = CSL_FMKT(EMAC_MACADDRLO_VALID, VALID) |
                           CSL_FMKT(EMAC_MACADDRLO_MATCHFILT, MATCH) |
                           CSL_FMK(EMAC_MACADDRLO_CHANNEL, utemp1) |
                           (tmpval << 8) |
                           phEMAC->ncfg.mac[4];


    /*
    // Setup Special Receive Conditions (loopback, error frames, etc)
    */

    // For us buffer offset will always be zero /
    EMAC_REGS->RXBUFFEROFFSET = RX_BUFFER_OFFSET;

    // Reset RX (M)ulticast (B)roadcast (P)romiscuous Enable register /
    EMAC_REGS->RXMBPENABLE = 0;
	EMAC_REGS->MACHASH1 = 0;
	EMAC_REGS->MACHASH2 = 0;

    // Clear Unicast RX on channel 0-7 /
    EMAC_REGS->RXUNICASTCLEAR = 0xFF;

    // Set the pass RX CRC mode and adjust max buffer accordingly /
    if (phEMAC->Config.ModeFlags & EMAC_CONFIG_MODEFLG_RXCRC) {
		CSL_FINST(EMAC_REGS->RXMBPENABLE, EMAC_RXMBPENABLE_RXPASSCRC, INCLUDE);
        phEMAC->PktMTU = (pEMACConfig->PktMTU) + 4;
    }
    else
        phEMAC->PktMTU = (pEMACConfig->PktMTU);
    EMAC_REGS->RXMAXLEN = ((pEMACConfig->PktMTU) + 4);

    // Initialize flowthresh condition
//	EMAC_REGS->RX0FREEBUFFER = pEMACConfig->RxMaxPktPool;
//    EMAC_REGS->RX0FLOWTHRESH = 1;

    /* If PASSCONTROL is set, enable control frames */
	if (phEMAC->Config.ModeFlags & EMAC_CONFIG_MODEFLG_PASSCONTROL)
	    CSL_FINST(EMAC_REGS->RXMBPENABLE, EMAC_RXMBPENABLE_RXCMFEN, ENABLE);
	if (phEMAC->Config.ModeFlags & EMAC_CONFIG_MODEFLG_PASSALL)
	    CSL_FINST(EMAC_REGS->RXMBPENABLE, EMAC_RXMBPENABLE_RXCAFEN, ENABLE);
	if (phEMAC->Config.ModeFlags & EMAC_CONFIG_MODEFLG_RXQOS)
		CSL_FINST(EMAC_REGS->RXMBPENABLE, EMAC_RXMBPENABLE_RXQOSEN, ENABLE);
	if (phEMAC->Config.ModeFlags & EMAC_CONFIG_MODEFLG_RXNOCHAIN)
		CSL_FINST(EMAC_REGS->RXMBPENABLE, EMAC_RXMBPENABLE_RXNOCHAIN, ENABLE);

	/* Set the channel configuration to priority if requested */
	if (phEMAC->Config.ModeFlags & EMAC_CONFIG_MODEFLG_CHPRIORITY)
		CSL_FINST(EMAC_REGS->MACCONTROL, EMAC_MACCONTROL_TX_PTYPE, CHANNELPRI);

	/* Set MAC loopback if requested */
	if (phEMAC->Config.ModeFlags & EMAC_CONFIG_MODEFLG_MACLOOPBACK)
		CSL_FINST(EMAC_REGS->MACCONTROL, EMAC_MACCONTROL_LOOPBACK, ENABLE);
	/* Set full duplex mode if requested */
	if (phEMAC->Config.ModeFlags & EMAC_CONFIG_MODEFLG_FULLDUPLEX)
	    CSL_FINST(EMAC_REGS->MACCONTROL, EMAC_MACCONTROL_FULLDUPLEX, ENABLE);
	/* Enable gigabit transfer if requested */
	if (phEMAC->Config.ModeFlags & EMAC_CONFIG_MODEFLG_GIGABIT)
		CSL_FINST(EMAC_REGS->MACCONTROL, EMAC_MACCONTROL_GIG, ENABLE);
	/* Enable rx offset/length blocing if requested */
	if (phEMAC->Config.ModeFlags & EMAC_CONFIG_MODEFLG_RXOFFLENBLOCK)
	    CSL_FINST(EMAC_REGS->MACCONTROL, EMAC_MACCONTROL_RX_OFFLEN_BLOCK, BLOCK);
	/* Use rx owership one if requested */
	if (phEMAC->Config.ModeFlags & EMAC_CONFIG_MODEFLG_RXOWNERSHIP)
		CSL_FINST(EMAC_REGS->MACCONTROL, EMAC_MACCONTROL_RX_OWNERSHIP, ONE);
	/* Enable rx fifo flow control if requested */
	if (phEMAC->Config.ModeFlags & EMAC_CONFIG_MODEFLG_RXFIFOFLOWCNTL)
		CSL_FINST(EMAC_REGS->MACCONTROL, EMAC_MACCONTROL_RX_FIFO_FLOW_EN, ENABLE);
	/* Enable IDLE command bit if requested */
	if (phEMAC->Config.ModeFlags & EMAC_CONFIG_MODEFLG_CMDIDLE)
		CSL_FINST(EMAC_REGS->MACCONTROL, EMAC_MACCONTROL_CMD_IDLE, ENABLE);
	/* Enable tx short gap if requested */
	if (phEMAC->Config.ModeFlags & EMAC_CONFIG_MODEFLG_TXSHORTGAPEN)
		CSL_FINST(EMAC_REGS->MACCONTROL, EMAC_MACCONTROL_TX_SHORT_GAP_EN, ENABLE);
	/* Enable tx pace if requested */
	if (phEMAC->Config.ModeFlags & EMAC_CONFIG_MODEFLG_TXPACE)
		CSL_FINST(EMAC_REGS->MACCONTROL, EMAC_MACCONTROL_TX_PACE, ENABLE);
	/* Enable tx flow control */
	if (phEMAC->Config.ModeFlags & EMAC_CONFIG_MODEFLG_TXFLOWCNTL)
		CSL_FINST(EMAC_REGS->MACCONTROL, EMAC_MACCONTROL_TX_FLOW_EN, ENABLE);
	/* Enable rx  buffer flow control if requested */
	if (phEMAC->Config.ModeFlags & EMAC_CONFIG_MODEFLG_RXBUFFERFLOWCNTL)
		CSL_FINST(EMAC_REGS->MACCONTROL, EMAC_MACCONTROL_RX_BUFFER_FLOW_EN, ENABLE);
	if (phEMAC->Config.ModeFlags & EMAC_CONFIG_MODEFLG_EXTEN)
		CSL_FINST(EMAC_REGS->MACCONTROL, EMAC_MACCONTROL_EXT_EN, ENABLE);
    
    // Enable TX and RX channel interrupts (set mask bits)
    // Enable Host interrupts
    EMAC_REGS->RXINTMASKCLEAR = 0xFF;
	EMAC_REGS->TXINTMASKCLEAR = 0xFF;

	EMAC_REGS->RXINTMASKSET = phEMAC->Config.ChannelInfo.RxChanEnable;

	EMAC_REGS->TXINTMASKSET = phEMAC->Config.ChannelInfo.TxChanEnable;

	EMAC_REGS->MACINTMASKSET = CSL_FMK(EMAC_MACINTMASKSET_HOSTMASK, 0) |
                               CSL_FMK(EMAC_MACINTMASKSET_STATMASK, 0);
}




void setupBuffers(EMAC_Device *phEMAC)
{
    int             i;
//    uint32            utemp1;
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
    pDesc = (EMAC_Desc *)CSL_EMAC_DSC_BASE_ADDR;

    // Number of descriptors for RX channel /
//    utemp1 = phEMAC->Config.RxMaxPktPool;
    /* Number of descriptors for RX channel 64 per channel */
//    utemp1 = 64 - (phEMAC->Config.RxMaxPktPool); 

    /* Init all Rx channels in use */
	for (i = 0; i < 8; i++)
    {
		if((1 << i) & (phEMAC->Config.ChannelInfo.RxChanEnable))
        {
			phEMAC->RxCh[i].pd         = phEMAC;
			phEMAC->RxCh[i].DescMax    = (phEMAC->Config.RxMaxPktPool);
			phEMAC->RxCh[i].pDescFirst = pDesc;
			phEMAC->RxCh[i].pDescLast  = pDesc + ((phEMAC->Config.RxMaxPktPool)- 1);
			phEMAC->RxCh[i].pDescRead  = pDesc;
			phEMAC->RxCh[i].pDescWrite = pDesc;

			/* Fill the descriptor table */
			emacEnqueueRx(&phEMAC->RxCh[i], 0);

            pDesc += (phEMAC->Config.RxMaxPktPool + phEMAC->Config.TxMaxPktPool);
		}
    }


    /*
    // Setup Transmit Buffers
    */

    // Pointer to first descriptor to use on TX /
//    pDesc += utemp1;
    
    // Number of descriptors for TX channel /
//    utemp1 = (CSL_EDMA_DSC_ENTRY_COUNT - utemp1)/index;

    // Init all TX channels in use /
    for (i = 0; i < 8; i++)
    {
		if((1<<i) & (phEMAC->Config.ChannelInfo.TxChanEnable))
        {
				phEMAC->TxCh[i].pd         = phEMAC;
				phEMAC->TxCh[i].DescMax    = phEMAC->Config.TxMaxPktPool;
				/*Pointer for first TX desc = pointer to RX + num of RX desc.*/
				pDesc = (phEMAC->RxCh[i].pDescFirst + (phEMAC->Config.RxMaxPktPool));
				phEMAC->TxCh[i].pDescFirst = pDesc;
				phEMAC->TxCh[i].pDescLast  = pDesc + ((phEMAC->Config.TxMaxPktPool) - 1);
				phEMAC->TxCh[i].pDescRead  = pDesc;
				phEMAC->TxCh[i].pDescWrite = pDesc;
		}
	}
}

void startupEMAC( EMAC_Device *phEMAC )
{
    volatile uint32 *pRegAddr;
    uint32 i;
    
    /*
    // Enable RX, TX, and MII
    */
    
    // Note in full duplex mode we also need to set the FULLDUPLEX
    // bit in MACCRONTROL. However, we don't know what to set until
    // we have a link. Also, we must be able to dynamically change
    // this bit if the cable is unplugged and re-linked with a different
    // duplex.
    CSL_FINST(EMAC_REGS->TXCONTROL, EMAC_TXCONTROL_TXEN, ENABLE);
	CSL_FINST(EMAC_REGS->RXCONTROL, EMAC_RXCONTROL_RXEN, ENABLE);
	CSL_FINST(EMAC_REGS->MACCONTROL, EMAC_MACCONTROL_GMII_EN, ENABLE);

    // Startup RX /
    for (i = 0; i < 8; i++)
    {
		if ((1 << i) & (phEMAC->Config.ChannelInfo.RxChanEnable))
        {
			pRegAddr = &EMAC_REGS->RX0HDP;
			*(pRegAddr + i) = (uint32)phEMAC->RxCh[i].pDescRead;
		}
	}

    // Enable global interrupt in wrapper /
//    EMAC_FSETS( EWCTL, INTEN, ENABLE );
    /* Enable interrupts in ECTL module */
	ECTL_REGS->RX_EN = phEMAC->Config.ChannelInfo.RxChanEnable;
	ECTL_REGS->TX_EN = phEMAC->Config.ChannelInfo.TxChanEnable;
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
//    EMAC_Device     *pd = (EMAC_Device *)hEMAC;
    uint32          tmp, index;
    EMAC_Pkt        *pPkt;
    volatile uint32 *pRegAddr;

    // Disable EMAC/MDIO interrupts in wrapper /
    ECTL_REGS->INT_CONTROL = 0x00000000; /*Disable Wrapper interrupts pacing */
    ECTL_REGS->RX_EN = 0x00;/*Disable all Rx channels */
	ECTL_REGS->TX_EN = 0x00;/*Disable all Tx channels */

    // The close process consists of tearing down all the active
    // channels (RX and TX) and then waiting for the teardown
    // complete indication from the MAC. Then, all queued packets
    // will be returned.

    /* Teardown RX channels in use */
	for (index = 0; index < 8; index++)
	    if ((1 << index) & (pd->Config.ChannelInfo.RxChanEnable))
		    EMAC_REGS->RXTEARDOWN = index;

	/* Teardown TX channels in use */
	for (index = 0; index < 8; index++)
    	if ((1 << index) & (pd->Config.ChannelInfo.TxChanEnable))
	           EMAC_REGS->TXTEARDOWN = index;

    // Only check teardown status if there was no fatal error         /
    // Otherwise; the EMAC is halted and can’t be shutdown gracefully /
    if (!pd->FatalError) 
    {
		/* Wait for the teardown to complete */
	    pRegAddr = &EMAC_REGS->RX0CP;
	    for (index = 0; index < 8; index++)
        {
			if ((1 << index) & (pd->Config.ChannelInfo.RxChanEnable))
            {
				for (tmp = 0; tmp != 0xFFFFFFFC; tmp = *(pRegAddr + index));
					*(pRegAddr + index) = tmp;
			}
	    }

		pRegAddr = &EMAC_REGS->TX0CP;
	    for (index=0; index<8; index++)
        {
			if ((1 << index) & (pd->Config.ChannelInfo.TxChanEnable))
            {
				for (tmp = 0; tmp != 0xFFFFFFFC; tmp = *(pRegAddr + index));
					*(pRegAddr + index) = tmp;
			}
	    }
	}

	// Put TX and RX into reset state
	CSL_SgmiiRegs* pSGMII = (CSL_SgmiiRegs*)(0x02C40000);
	pSGMII->SOFT_RESET = 0x02;

	REG_GPIO_SET_DATA = ( GPIO_4 );

    // Disable RX, TX, and Clear MACCONTROL /
    CSL_FINST(EMAC_REGS->TXCONTROL, EMAC_TXCONTROL_TXEN, DISABLE);
	CSL_FINST(EMAC_REGS->RXCONTROL, EMAC_RXCONTROL_RXEN, DISABLE);
	EMAC_REGS->MACCONTROL = 0;

    // Free all RX buffers /
//    while( pPkt = pqPop( &(pd->RxCh.DescQueue) ) )
//        pqPush( &pd->RxQueue, pPkt );
    for (index = 0; index < 8; index++)
    {
		if ((1 << index) & (pd->Config.ChannelInfo.RxChanEnable))
        {
			while (pPkt = pqPop( &pd->RxCh[index].DescQueue))
                pqPush( &pd->RxQueue, pPkt );
		}
	}

    // Free all TX buffers /
/*
    while( pPkt = pqPop( &pd->TxCh.DescQueue ) )
        pqPush( &pd->TxQueue, pPkt );
    while( pPkt = pqPop( &pd->TxCh.WaitQueue ) )
        pqPush( &pd->TxQueue, pPkt );
*/
    for (index = 0; index < 8; index++)
    {
		if ((1 << index) & (pd->Config.ChannelInfo.TxChanEnable))
        {
			while (pPkt = pqPop( &pd->TxCh[index].DescQueue))
				pqPush( &pd->TxQueue, pPkt );
			while (pPkt = pqPop(&pd->TxCh[index].WaitQueue))
				pqPush( &pd->TxQueue, pPkt );
 		}
	}
    
//    if (pd->Config.UseMdio)
		/* Close the MDIO Module */
//         MDIO_close( pd->hMDIO );

    // Clear the open flag /
    openFlag = 0;

    /* Exit with interrupts still disabled in the wrapper */
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
    uint8 EnabledRxChannel, EnabledRxChannelNum=0;

    EnabledRxChannel = pd->Config.ChannelInfo.RxChanEnable;
    /*
    // The following code relies on the numberic relation of the filter
    // value such that the higher filter values receive more types of
    // packets.
    */

    /* Disable Section */
    if (ReceiveFilter < EMAC_RXFILTER_ALL)
        CSL_FINST(EMAC_REGS->RXMBPENABLE, EMAC_RXMBPENABLE_RXCAFEN, DISABLE);
    if (ReceiveFilter < EMAC_RXFILTER_ALLMULTICAST) {
        EMAC_REGS->MACHASH1 = pd->MacHash1;
        EMAC_REGS->MACHASH2 = pd->MacHash2;
    }
    if (ReceiveFilter < EMAC_RXFILTER_MULTICAST)
        CSL_FINST(EMAC_REGS->RXMBPENABLE, EMAC_RXMBPENABLE_RXMULTEN, DISABLE);
    if (ReceiveFilter < EMAC_RXFILTER_BROADCAST)
        CSL_FINST(EMAC_REGS->RXMBPENABLE, EMAC_RXMBPENABLE_RXBROADEN, DISABLE);
    if (ReceiveFilter < EMAC_RXFILTER_DIRECT) {
        EMAC_REGS->RXUNICASTCLEAR = EnabledRxChannel;
    }

    /* Enable Section */
    if (ReceiveFilter >= EMAC_RXFILTER_DIRECT) {
        EMAC_REGS->RXUNICASTSET = EnabledRxChannel;
    }

	/*find the Rx channels number */
	for (EnabledRxChannelNum = 0; EnabledRxChannel != 0; EnabledRxChannel >>= 1, EnabledRxChannelNum += 1)
		if (EnabledRxChannel & 01)
			break;

    if (ReceiveFilter >= EMAC_RXFILTER_BROADCAST) {
        CSL_FINST(EMAC_REGS->RXMBPENABLE, EMAC_RXMBPENABLE_RXBROADEN, ENABLE);
        /*Only one channel can receive broadcast frames, set it to be a master*/
		CSL_FINS(EMAC_REGS->RXMBPENABLE, EMAC_RXMBPENABLE_RXBROADCH, EnabledRxChannelNum);
	}
    if (ReceiveFilter >= EMAC_RXFILTER_MULTICAST) {
        CSL_FINST(EMAC_REGS->RXMBPENABLE, EMAC_RXMBPENABLE_RXMULTEN, ENABLE);
        /*Only one channel can receive multicast frames, set it to be a master*/
		CSL_FINS(EMAC_REGS->RXMBPENABLE, EMAC_RXMBPENABLE_RXMULTCH, EnabledRxChannelNum);
	}
    if (ReceiveFilter >= EMAC_RXFILTER_ALLMULTICAST) {
        EMAC_REGS->MACHASH1 = 0xffffffff;
        EMAC_REGS->MACHASH2 = 0xffffffff;
    }
    if (ReceiveFilter == EMAC_RXFILTER_ALL) {
        CSL_FINST(EMAC_REGS->RXMBPENABLE, EMAC_RXMBPENABLE_RXCAFEN, ENABLE);
		CSL_FINS(EMAC_REGS->RXMBPENABLE, EMAC_RXMBPENABLE_RXPROMCH, EnabledRxChannelNum);
	}

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

    int_lock( pd->tx_intrpt );
    emacTxPutPkt( &(pd->TxCh[0]), pPkt );

    int_unlock( pd->tx_intrpt );
}














uint32 EMAC_RxServiceCheck(Handle hEMAC)
{
    EMAC_Device     *pd = (EMAC_Device *)hEMAC;
    uint32          intflags,Desc; //,mask;
    volatile uint32 *pRegAddr;
    int             i;

    // Read the interrupt cause
    intflags = EMAC_REGS->MACINVECTOR;

    // Look for fatal errors first
    if (intflags & CSL_FMK(EMAC_MACINVECTOR_HOSTPEND, 1))
    {
        // Read the error status - we'll decode it by hand
        pd->FatalError = EMAC_REGS->MACSTATUS;

        // Tell the application
//        (*localDev.Config.pfcbStatus)(pd->hApplication);

        // return with interrupt disabled in the wrapper
        return (EMAC_ERROR_MACFATAL);
    }

    pRegAddr = &EMAC_REGS->RX0CP;

    // Look for Rx interrupt
    for (i = 0; i < 8; i++)
    {
        if ((1 << i) & (pd->Config.ChannelInfo.RxChanEnable))   // find out which channel is enabled
        {
            if (intflags & CSL_FMK(EMAC_MACINVECTOR_RXPEND, 1 << i))    // find out if interrupt happend
            {
                pd->pkt_prznt = true;
                Desc = *(pRegAddr + i);
                *(pRegAddr + i) = Desc;

                pd->RxCh[i].ChannelIndex = i;
                emacDequeueRx(&pd->RxCh[i], (EMAC_Desc *)Desc);
            }

            // Re-fill Rx buffer queue if needed
//            if (pd->RxCh[i].DescCount != pd->RxCh[i].DescMax)
//                emacEnqueueRx(&pd->RxCh[i], 1);
          }
    }

    EMAC_REGS->MACEOIVECTOR = 0x01;     // core 0, C0_RX_PULSE = 0x01

    return(0);
}


uint32 EMAC_TxServiceCheck(Handle hEMAC)
{
    EMAC_Device     *pd = (EMAC_Device *)hEMAC;
    uint32          intflags,Desc; //,mask;
    uint32          i;
    volatile uint32 *pRegAddr;

    // Read the interrupt cause
    intflags = EMAC_REGS->MACINVECTOR;

    // Look for fatal errors first
    if (intflags & CSL_FMK(EMAC_MACINVECTOR_HOSTPEND, 1))
    {
        // Read the error status - we'll decode it by hand
        pd->FatalError = EMAC_REGS->MACSTATUS;

        // Tell the application
//        (*localDev.Config.pfcbStatus)(pd->hApplication);

        // return with interrupt disabled in the wrapper
        return (EMAC_ERROR_MACFATAL);
    }

    pRegAddr = &EMAC_REGS->TX0CP;

    // Look for Tx interrupt
    for (i = 0; i < 8; i++)
    {
        if ((1 << i) & (pd->Config.ChannelInfo.TxChanEnable))   // find out which channel is enabled
        {
            if (intflags & CSL_FMK(EMAC_MACINVECTOR_TXPEND, 1 << i))    // find out if interrupt happend
            {

                pd->pkt_prznt = true;
                Desc = *(pRegAddr + i);
                *(pRegAddr + i) = Desc;

                pd->TxCh[i].ChannelIndex = i;
                emacDequeueTx(&pd->TxCh[i], (EMAC_Desc *)Desc);
            }
        }
    }

    EMAC_REGS->MACEOIVECTOR = 0x02;     // core 0, C0_TX_PULSE = 0x02

    return (0);
}



















