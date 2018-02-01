// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp1251
// !: d: Модуль содержит прототипы функций и описание структур для работы
// !: d: с модулем EMAC процессора tms320c6412
// !: -: 
// ---------------------------------------------------------------------------
#ifndef _ETH6412_EMAC_H
#define _ETH6412_EMAC_H_


#include <os.h>
#include <drv_eth6412_emachal.h>
#include <net_struct.h>

typedef void * Handle;

/*-----------------------------------------------------------------------*\
* STANDARD DATA STRUCTURES
\*-----------------------------------------------------------------------*/

/*-----------------------------------------------------------------------*\
* EMAC_Pkt
*
* The packet structure defines the basic unit of memory used to hold data
* packets for the EMAC device.
*
* A packet is comprised of one or more packet buffers. Each packet buffer
* contains a packet buffer header, and a pointer to the buffer data.
* The EMAC_Pkt structure defines the packet buffer header.
*
* The pDataBuffer field points to the packet data. This is set when the
* buffer is allocated, and is not altered.
*
* BufferLen holds the the total length of the data buffer that is used to
* store the packet (or packet fragment). This size is set by the entity
* that originally allocates the buffer, and is not altered.
*
* The Flags field contains additional information about the packet
*
* ValidLen holds the length of the valid data currently contained in the
* data buffer.
*
* DataOffset is the byte offset from the start of the data buffer to the
* first byte of valid data. Thus (ValidLen+DataOffet)<=BufferLen.
*
* Note that for receive buffer packets, the DataOffset field may be
* assigned before there is any valid data in the packet buffer. This allows
* the application to reserve space at the top of data buffer for private
* use. In all instances, the DataOffset field must be valid for all packets
* handled by EMAC.
*
* The data portion of the packet buffer represents a packet or a fragment
* of a larger packet. This is determined by the Flags parameter. At the
* start of every packet, the SOP bit is set in Flags. If the EOP bit is
* also set, then the packet is not fragmented. Otherwise; the next packet
* structure pointed to by the pNext field will contain the next fragment in
* the packet. On either type of buffer, when the SOP bit is set in Flags,
* then the PktChannel, PktLength, and PktFrags fields must also be valid.
* These fields contain additional information about the packet.
*
* The PktChannel field detetmines what channel the packet has arrived on,
* or what channel it should be transmitted on. The EMAC library supports
* only a single receive channel, but allows for up to eight transmit
* channels. Transmit channels can be treated as round-robin or priority
* queues.
*
* The PktLength field holds the size of the entire packet. On single frag
* packets (both SOP and EOP set in BufFlags), PktLength and ValidLen will
* be equal.
*
* The PktFrags field holds the number of fragments (EMAC_Pkt records) used
* to describe the packet. If more than 1 frag is present, the first record
* must have EMAC_PKT_FLAGS_SOP flag set, with corresponding fields validated.
* Each frag/record must be linked list using the pNext field, and the final
* frag/record must have EMAC_PKT_FLAGS_EOP flag set and pNext=0.
*
* In systems where the packet resides in cacheable memory, the data buffer
* must start on a cache line boundary and be an even multiple of cache
* lines in size. The EMAC_Pkt header must not appear in the same cache line
* as the data portion of the packet. On multi-fragment packets, some packet
* fragments may reside in cacheable memory where others do not.
*
* ** NOTE: It is up to the caller to assure that all packet buffers    **
* ** residing in cacheable memory are not currently stored in L1 or L2 **
* ** cache when passed to any EMAC function                             **
*
* Some of the packet Flags can only be set if the device is in the
* proper configuration to receive the corresponding frames. In order to
* enable these flags, the following modes must be set:
*       RxCrc Flag  : RXCRC Mode in EMAC_Config
*       RxErr Flags : PASSERROR Mode in EMAC_Config
*       RxCtl Flags : PASSCONTROL Mode in EMAC_Config
*       RxPrm Flag  : EMAC_RXFILTER_ALL in EMAC_setReceiveFilter()
*
\*-----------------------------------------------------------------------*/
/*typedef struct _EMAC_Pkt {
    uint32           AppPrivate;   // For use by the application            /
    struct _EMAC_Pkt *pPrev;       // Previous record                       /
    struct _EMAC_Pkt *pNext;       // Next record                           /
    uint8            *pDataBuffer; // Pointer to Data Buffer (read only)    /
    uint32          BufferLen;    // Physical Length of buffer (read only) /
    uint32          Flags;        // Packet Flags                          /
    uint32          ValidLen;     // Length of valid data in buffer        /
    uint32          DataOffset;   // Byte offset to valid data             /
    uint32          PktChannel;   // Tx/Rx Channel/Priority 0-7 (SOP only) /
    uint32          PktLength;    // Length of Packet (SOP only)           /
                                  // (same as ValidLen on single frag Pkt) /
    uint32          PktFrags;     // Number of frags in packet (SOP only)  /
                                   // (frag is EMAC_Pkt record - normally 1)/
    } EMAC_Pkt;
*/
typedef net_descriptor EMAC_Pkt;



/*
// Packet Buffer Flags set in Flags
*/
#define EMAC_PKT_FLAGS_SOP         0x80000000u /* Start of packet           */
#define EMAC_PKT_FLAGS_EOP         0x40000000u /* End of packet             */

/*
// The Following Packet flags are set in Flags on RX packets only
*/
#define EMAC_PKT_FLAGS_HASCRC      0x04000000u /* RxCrc: PKT has 4byte CRC  */
#define EMAC_PKT_FLAGS_JABBER      0x02000000u /* RxErr: Jabber             */
#define EMAC_PKT_FLAGS_OVERSIZE    0x01000000u /* RxErr: Oversize           */
#define EMAC_PKT_FLAGS_FRAGMENT    0x00800000u /* RxErr: Fragment           */
#define EMAC_PKT_FLAGS_UNDERSIZED  0x00400000u /* RxErr: Undersized         */
#define EMAC_PKT_FLAGS_CONTROL     0x00200000u /* RxCtl: Control Frame      */
#define EMAC_PKT_FLAGS_OVERRUN     0x00100000u /* RxErr: Overrun            */
#define EMAC_PKT_FLAGS_CODEERROR   0x00080000u /* RxErr: Code Error         */
#define EMAC_PKT_FLAGS_ALIGNERROR  0x00040000u /* RxErr: Alignment Error    */
#define EMAC_PKT_FLAGS_CRCERROR    0x00020000u /* RxErr: Bad CRC            */
#define EMAC_PKT_FLAGS_NOMATCH     0x00010000u /* RxPrm: No Match           */

/*
// Packet Queue
*/
typedef struct _pktq {
  uint32      Count;      // Number of packets in queue
  EMAC_Pkt    *pHead;     // Pointer to first packet
  EMAC_Pkt    *pTail;     // Pointer to last packet
} PKTQ;

/*-----------------------------------------------------------------------*\
* EMAC_Config
*
* The config structure defines how the EMAC device should operate. It is
* passed to the device when the device is opened, and remains in effect
* until the device is closed.
*
* The following is a short description of the configuration fields:
*
* ModeFlags    - Specify the Fixed Operating Mode of the Device
* EMAC_CONFIG_MODEFLG_CHPRIORITY  - Treat TX channels as Priority Levels
*                                  (Channel 7 is highest, 0 is lowest)
* EMAC_CONFIG_MODEFLG_MACLOOPBACK - Set MAC in Internal Loopback for Testing
* EMAC_CONFIG_MODEFLG_RXCRC       - Include the 4 byte EtherCRC in RX frames
* EMAC_CONFIG_MODEFLG_TXCRC       - Assume TX Frames Include 4 byte EtherCRC
* EMAC_CONFIG_MODEFLG_PASSERROR   - Receive Error Frames for Testing
* EMAC_CONFIG_MODEFLG_PASSCONTROL - Receive Control Frames for Testing
*
* MdioModeFlags - Specify the MDIO/PHY Operation (See EMACMDIO.H)
*
* TxChannels    - Number of TX Channels to use (1-8, usually 1)
*
* MacAddr       - Device MAC address
*
* RxMaxPktPool  - Max Rx packet buffers to get from pool
*                 (Must be in the range of 8 to 192)
*
* A list of callback functions is used to register callback functions with
* a particular instance of the EMAC peripheral. Callback functions are
* used by EMAC to communicate with the application. These functions are
* REQUIRED for operation. The same callback table can be used for multiple
* driver instances.
*
* The callback functions can be used by EMAC during any EMAC function, but
* mostly occur during calls to EMAC_statusIsr() and EMAC_statusPoll().
*
* pfcbGetPacket -  Called by EMAC to get a free packet buffer from the
*                  application layer for receive data. This function
*                  should return NULL is no free packets are available.
*                  The size of the packet buffer must be large enough
*                  to accommodate a full sized packet (1514 or 1518
*                  depending on the EMAC_CONFIG_MODEFLG_RXCRC flag), plus
*                  any application buffer padding (DataOffset).
*
* pfcbRxPacket   - Called to give a received data packet to the application
*                  layer. The applicaiton must accept the packet.
*                  When the application is finished with the packet, it
*                  can return it to its own free queue.
*
*                  This function also returns a pointer to a free packet to
*                  replace the received packet on the EMAC free list. It
*                  returns NULL when no free packets are available. The
*                  return packet is the same as would be returned by
*                  pfcbGetPacket.
*
*                  Thus if a newly received packet is not desired, it can
*                  simply be returned to EMAC via the return value.
*
* pfcbStatus     - Called to indicate to the application that it
*                  should call EMAC_getStatus() to read the current
*                  device status. This call is made when device status
*                  changes.
*
* pfcbStatistics - Called to indicate to the application that it
*                  should call EMAC_getStatistics() to read the
*                  current Ethernet statistics. Called when the
*                  statistic counters are to the point of overflow.
*
* The hApplication calling calling argument is the application's handle
* as supplied to the EMAC device in the EMAC_open() function.
\*-----------------------------------------------------------------------*/
typedef struct _EMAC_Config {
    uint32        ModeFlags;      /* Configuation Mode Flags                */
    uint32        MdioModeFlags;  /* CSL_MDIO Mode Flags (see CSL_MDIO.H)   */
    uint32        TxChannels;     /* Number of Tx Channels to use (1-8)     */
//    uint8       MacAddr[6];     /* Mac Address                            */
    uint32        RxMaxPktPool;   /* Max Rx packet buffers to get from pool */
    uint32        TxMaxPktPool;   /* Max Rx packet buffers to get from pool */
    EMAC_Pkt *  (*pfcbGetPacket)(Handle hApplication, PKTQ *pPktQueue);
    void        (*pfcbPutPacket)(Handle hApplication, PKTQ *pPktQueue, EMAC_Pkt *pPacket);
} EMAC_Config;

/*
//  Configuration Mode Flags
*/
#define EMAC_CONFIG_MODEFLG_PROMISCUOUS 0x0001 /*   */
#define EMAC_CONFIG_MODEFLG_MACLOOPBACK 0x0002 /* MAC internal loopback    */
#define EMAC_CONFIG_MODEFLG_RXCRC       0x0004 /* Include CRC in RX frames */
#define EMAC_CONFIG_MODEFLG_TXCRC       0x0008 /* Tx frames include CRC    */
#define EMAC_CONFIG_MODEFLG_PASSERROR   0x0010 /* Pass error frames        */
#define EMAC_CONFIG_MODEFLG_PASSCONTROL 0x0020 /* Pass control frames      */
#define EMAC_CONFIG_MODEFLG_CHPRIORITY  0x0040 /* Use Tx channel priority  */


/*-----------------------------------------------------------------------*\
* EMAC_Statistics
*
* The statistics structure is the used to retrieve the current count
* of various packet events in the system. These values represent the
* delta values from the last time the statistics were read.
\*-----------------------------------------------------------------------*/
/*
typedef struct _EMAC_Statistics {
    uint32 RxGoodFrames;     // Good Frames Received                         /
    uint32 RxBCastFrames;    // Good Broadcast Frames Received               /
    uint32 RxMCastFrames;    // Good Multicast Frames Received               /
    uint32 RxPauseFrames;    // PauseRx Frames Received                      /
    uint32 RxCRCErrors;      // Frames Received with CRC Errors              /
    uint32 RxAlignCodeErrors;// Frames Received with Alignment/Code Errors   /
    uint32 RxOversized;      // Oversized Frames Received                    /
    uint32 RxJabber;         // Jabber Frames Received                       /
    uint32 RxUndersized;     // Undersized Frames Received                   /
    uint32 RxFragments;      // Rx Frame Fragments Received                  /
    uint32 RxFiltered;       // Rx Frames Filtered Based on Address          /
    uint32 RxQOSFiltered;    // Rx Frames Filtered Based on QoS Filtering    /
    uint32 RxOctets;         // Total Received Bytes in Good Frames          /
    uint32 TxGoodFrames;     // Good Frames Sent                             /
    uint32 TxBCastFrames;    // Good Broadcast Frames Sent                   /
    uint32 TxMCastFrames;    // Good Multicast Frames Sent                   /
    uint32 TxPauseFrames;    // PauseTx Frames Sent                          /
    uint32 TxDeferred;       // Frames Where Transmission was Deferred       /
    uint32 TxCollision;      // Total Frames Sent With Collision             /
    uint32 TxSingleColl;     // Frames Sent with Exactly One Collision       /
    uint32 TxMultiColl;      // Frames Sent with Multiple Colisions          /
    uint32 TxExcessiveColl;  // Tx Frames Lost Due to Excessive Collisions   /
    uint32 TxLateColl;       // Tx Frames Lost Due to a Late Collision       /
    uint32 TxUnderrun;       // Tx Frames Lost with Transmit Underrun Error  /
    uint32 TxCarrierSLoss;   // Tx Frames Lost Due to Carrier Sense Loss     /
    uint32 TxOctets;         // Total Transmitted Bytes in Good Frames       /
    uint32 Frame64;          // Total Tx&Rx with Octet Size of 64            /
    uint32 Frame65t127;      // Total Tx&Rx with Octet Size of 65 to 127     /
    uint32 Frame128t255;     // Total Tx&Rx with Octet Size of 128 to 255    /
    uint32 Frame256t511;     // Total Tx&Rx with Octet Size of 256 to 511    /
    uint32 Frame512t1023;    // Total Tx&Rx with Octet Size of 512 to 1023   /
    uint32 Frame1024tUp;     // Total Tx&Rx with Octet Size of >=1024        /
    uint32 NetOctets;        // Sum of all Octets Tx or Rx on the Network    /
    uint32 RxSOFOverruns;    // Total Rx Start of Frame Overruns             /
    uint32 RxMOFOverruns;    // Total Rx Middle of Frame Overruns            /
    uint32 RxDMAOverruns;    // Total Rx DMA Overruns                        /
} EMAC_Statistics;
*/



/*
// Transmit/Receive Descriptor Channel Structure
// (One receive and up to 8 transmit in this driver)
*/
typedef struct _EMAC_DescCh {
    struct _EMAC_Device *pd;      /* Pointer to parent structure   */
    PKTQ            DescQueue;    /* Packets queued as desc        */
    PKTQ            WaitQueue;    /* Packets waiting for TX desc   */
    uint32            ChannelIndex; /* Channel index 0-7             */
    uint32            DescMax;      /* Max number of desc (buffs)    */
    uint32            DescCount;    /* Current number of desc        */
    EMAC_Desc       *pDescFirst;  /* First desc location           */
    EMAC_Desc       *pDescLast;   /* Last desc location            */
    EMAC_Desc       *pDescRead;   /* Location to read next desc    */
    EMAC_Desc       *pDescWrite;  /* Location to write nest desc   */
} EMAC_DescCh;


/*
// Main Device Instance Structure
*/
typedef struct _EMAC_Device {
    uint32          hGPIO;        // GPIO descr. for this instance /
    net_config      ncfg;
    uint32          intrpt;       // EMAC/MDIO interrupt           /
    uint32          smphr;        // EMAC/MDIO semaphore           /
    Handle          hApplication; // Calling Application's Handle  /
    Handle			hMDIO;        // Handle to MDIO Module         /
    uint32          RxFilter;     // Current RX filter value       /
    uint32          PktMTU;       // Max physical packet size      /
    uint32          MacHash1;     // Hash value cache              /
    uint32          MacHash2;     // Hash value cache              /
    uint32          FatalError;   // Fatal Error Code              /
    EMAC_Pkt*       pkt_rx;       //                               /
    EMAC_Pkt*       pkt_tx;       //                               /
    uint8*          pkt_data;
    PKTQ	        RxQueue;	  // Packet Queue for Receive      /
    PKTQ	        TxQueue;      // Packet Queue for Transmit     /
    EMAC_Config     Config;       // Original User Configuration   /
//    EMAC_Statistics Stats;        / Current running statistics    /
    EMAC_DescCh     RxCh;         // Receive channel status        /
    EMAC_DescCh     TxCh;      // Transmit channel status       /
    void            (*callback)( const char* iname, net_config* cfg );
} EMAC_Device;




/*-----------------------------------------------------------------------*\
* Packet Filtering
*
* Packet Filtering Settings (cumulative)
\*-----------------------------------------------------------------------*/
#define EMAC_RXFILTER_NOTHING      0
#define EMAC_RXFILTER_DIRECT       1
#define EMAC_RXFILTER_BROADCAST    2
#define EMAC_RXFILTER_MULTICAST    3
#define EMAC_RXFILTER_ALLMULTICAST 4
#define EMAC_RXFILTER_ALL          5

/*-----------------------------------------------------------------------*\
* STANDARD EMAC ERROR CODES
\*-----------------------------------------------------------------------*/
#define EMAC_ERROR_ALREADY   0x10001   /* Operation has already been started        */
#define EMAC_ERROR_NOTREADY  0x10002   /* Device is not open or not ready           */
#define EMAC_ERROR_DEVICE    0x10003   /* Device hardware error                     */
#define EMAC_ERROR_INVALID   0x10004   /* Function or calling parameter is invalid  */
#define EMAC_ERROR_BADPACKET 0x10005   /* Supplied packet was invalid               */
#define EMAC_ERROR_MACFATAL  0x10006   /* Fatal Error in MAC - EMAC_close() required */

/*-----------------------------------------------------------------------*\
* STANDARD API FUNCTIONS
*
* IMPORTANT NOTE
* --------------
*   The application is charged with verifying that only one of the
* following API calls may only be executing at a given time across
* all threads and all interrupt functions.
*
\*-----------------------------------------------------------------------*/


/*
// Queue Helper Functions
*/
extern "C" EMAC_Pkt *pqPop( PKTQ *pq );
extern "C" void pqPush( PKTQ *pq, EMAC_Pkt *pPktHdr );

extern "C" void emacTxPutPkt( EMAC_DescCh *pdc, EMAC_Pkt *pPktNew );
extern "C" EMAC_Pkt* emacRxGetPkt( EMAC_DescCh *pdc );
extern "C" void emacRxPutPkt( EMAC_DescCh *pdc, EMAC_Pkt *pPktNew );

extern "C" EMAC_Pkt* emacRxGetPkt( EMAC_DescCh *pdc );
extern "C" void emacRxPutPkt( EMAC_DescCh *pdc, EMAC_Pkt *pPktNew );


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
*   EMAC_ERROR_ALREADY   - The device is already open
*   EMAC_ERROR_INVALID   - A calling parameter is invalid
*
\*-----------------------------------------------------------------------*/
extern "C" int32 EMAC_open( Handle hApplication,
                       EMAC_Config *pEMACConfig, EMAC_Device *phEMAC );


extern "C" void initEMAC(EMAC_Config *pEMACConfig, EMAC_Device *phEMAC);
extern "C" void setupBuffers(EMAC_Device *phEMAC);
extern "C" void startupEMAC( EMAC_Device *phEMAC );

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
extern "C" void EMAC_close( EMAC_Device  *pd );

extern "C" void EMAC_stop( EMAC_Device  *pd );

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
extern "C" void EMAC_setReceiveFilter( Handle hEMAC, uint32 ReceiveFilter );


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
extern "C" uint32 EMAC_getReceiveFilter( Handle hEMAC, uint32 *pReceiveFilter );



/*-----------------------------------------------------------------------*\
* EMAC_sendPacket()
*
* Sends a Ethernet data packet out the EMAC device. On a non-error return,
* the EMAC device takes ownership of the packet. The packet is returned
* to the application's free pool once it has been transmitted.
*
* The function returns zero on success, or an error code on failure.
* When an error code is returned, the EMAC device has not taken ownership
* of the packet.
*
* Possible error codes include:
*   EMAC_ERROR_INVALID   - A calling parameter is invalid
*   EMAC_ERROR_BADPACKET - The packet structure is invalid
*
\*-----------------------------------------------------------------------*/
extern "C" void EMAC_sendPacket( Handle hEMAC, EMAC_Pkt *pPacket );


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
extern "C" uint32 EMAC_serviceCheck( Handle hEMAC );


#endif /* _ETH6412_EMAC_H_ */

