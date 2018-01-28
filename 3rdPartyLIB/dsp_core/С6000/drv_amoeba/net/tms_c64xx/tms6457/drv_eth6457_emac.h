// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp1251
// !: d: Модуль содержит прототипы функций и описание структур для работы
// !: d: с модулем EMAC процессора tms320c6457
// !: -: 
// ---------------------------------------------------------------------------
#ifndef _ETH6457_EMAC_H
#define _ETH6457_EMAC_H_


#include <drv_eth6457_emachal.h>
#include <drv_eth6457_ectl.h>
#include <drv_eth6457_sgmii.h>
#include <net_struct.h>


#define RX_BUFFER_OFFSET 0

//-**************************************************************************
// Peripheral Base Address
//-**************************************************************************
// EMAC Module registers
#define EMAC_REGS                 ((CSL_EmacRegs *)CSL_EMAC_0_REGS)

// EMAC Control Module registers
#define ECTL_REGS                 ((CSL_EctlRegs *)CSL_ECTL_0_REGS)

typedef void * Handle;


#define GPIO_1      (0x0002)    //  FAULT_IN
#define GPIO_2      (0x0004)    //  DETECT_IN 
#define GPIO_3      (0x0008)    //  SIGNAL_LOST_IN
#define GPIO_4      (0x0010)    //  TX_DISABLE_OUT
#define GPIO_5      (0x0020)    //  BOARD_GREEN_LED_OUT
#define GPIO_6      (0x0040)    //  BOARD_YELLOW_LED_OUT
#define GPIO_7      (0x0080)    //  TOGGLE_BACK_LED_OUT
#define GPIO_8      (0x0100)    //  ENABLE_BACL_LED_OUT

//
//  EMACPktFlags Packet Buffer Flags set in Flags
//
#define EMAC_PKT_FLAGS_SOP              0x80000000u     //< Start of packet
#define EMAC_PKT_FLAGS_EOP              0x40000000u     //< End of packet

//
//  RecvPktFlags    Receive Packet flags
// The Following Packet flags are set in Flags on RX packets only
//
#define EMAC_PKT_FLAGS_HASCRC           0x04000000u     //< RxCrc: PKT has 4byte CRC
#define EMAC_PKT_FLAGS_JABBER           0x02000000u     //< RxErr: Jabber
#define EMAC_PKT_FLAGS_OVERSIZE         0x01000000u     //< RxErr: Oversize
#define EMAC_PKT_FLAGS_FRAGMENT         0x00800000u     //< RxErr: Fragment
#define EMAC_PKT_FLAGS_UNDERSIZED       0x00400000u     //< RxErr: Undersized
#define EMAC_PKT_FLAGS_CONTROL          0x00200000u     //< RxCtl: Control Frame
#define EMAC_PKT_FLAGS_OVERRUN          0x00100000u     //< RxErr: Overrun
#define EMAC_PKT_FLAGS_CODEERROR        0x00080000u     //< RxErr: Code Error
#define EMAC_PKT_FLAGS_ALIGNERROR       0x00040000u     //< RxErr: Alignment Error
#define EMAC_PKT_FLAGS_CRCERROR         0x00020000u     //< RxErr: Bad CRC
#define EMAC_PKT_FLAGS_NOMATCH          0x00010000u     //< RxPrm: No Match

//
//  CfgModeFlags Configuration Mode Flags
//
#define EMAC_CONFIG_MODEFLG_CHPRIORITY          0x00001     //< Use Tx channel priority
#define EMAC_CONFIG_MODEFLG_MACLOOPBACK         0x00002     //< MAC internal loopback
#define EMAC_CONFIG_MODEFLG_RXCRC               0x00004     //< Include CRC in RX frames
#define EMAC_CONFIG_MODEFLG_TXCRC               0x00008     //< Tx frames include CRC
#define EMAC_CONFIG_MODEFLG_PASSERROR           0x00010     //< Pass error frames
#define EMAC_CONFIG_MODEFLG_PASSCONTROL         0x00020     //< Pass control frames
#define EMAC_CONFIG_MODEFLG_PASSALL             0x00040     //< pass all frames
#define EMAC_CONFIG_MODEFLG_RXQOS               0x00080     //< Enable QOS at receive side
#define EMAC_CONFIG_MODEFLG_RXNOCHAIN           0x00100     //< Select no buffer chaining
#define EMAC_CONFIG_MODEFLG_RXOFFLENBLOCK       0x00200     //< Enable offset/length blocking
#define EMAC_CONFIG_MODEFLG_RXOWNERSHIP         0x00400     //< Use ownership bit as 1
#define EMAC_CONFIG_MODEFLG_RXFIFOFLOWCNTL      0x00800     //< Enable rx fifo flow control
#define EMAC_CONFIG_MODEFLG_CMDIDLE             0x01000     //< Enable IDLE command
#define EMAC_CONFIG_MODEFLG_TXSHORTGAPEN        0x02000     //< Enable tx short gap
#define EMAC_CONFIG_MODEFLG_TXPACE              0x04000     //< Enable tx pacing
#define EMAC_CONFIG_MODEFLG_TXFLOWCNTL          0x08000     //< Enable tx flow control
#define EMAC_CONFIG_MODEFLG_RXBUFFERFLOWCNTL    0x10000     //< Enable rx buffer flow control
#define EMAC_CONFIG_MODEFLG_FULLDUPLEX          0x20000     //< Set full duplex mode
#define EMAC_CONFIG_MODEFLG_GIGABIT             0x40000     //< Set gigabit
#define EMAC_CONFIG_MODEFLG_EXTEN               0x80000     //< Set external enable bit


//
//  Descriptor memory selection Flags
//
#define EMAC_DESC_BASE_L2          0x00001      //< Use L2 as Descriptor memory
#define EMAC_DESC_BASE_CPPI        0x00002      //< Use CPPI RAM as desriptor memory
#define EMAC_DESC_BASE_DDR         0x00004      //< Use DDR as descriptor memory



#define EMAC_TEARDOWN_CHANNEL(x)    (1 << x)    //< Macro to tear down selective Rx/Tx channels

//
//  PktFiltering Packet Filtering Settings (cumulative)
//
#define EMAC_RXFILTER_NOTHING           0	//< Receive filter set to Nothing
#define EMAC_RXFILTER_DIRECT            1   //< Receive filter set to Direct
#define EMAC_RXFILTER_BROADCAST         2   //< Receive filter set to Broadcast
#define EMAC_RXFILTER_MULTICAST         3   //< Receive filter set to Multicast
#define EMAC_RXFILTER_ALLMULTICAST      4   //< Receive filter set to All Mcast
#define EMAC_RXFILTER_ALL               5   //< Receive filter set to All

//
//  STANDARD ERROR CODES
//
#define EMAC_ERROR_ALREADY              1   //< Operation has already been started
#define EMAC_ERROR_NOTREADY             2   //< Device is not open or not ready
#define EMAC_ERROR_DEVICE               3   //< Device hardware error
#define EMAC_ERROR_INVALID              4   //< Function or calling parameter is invalid
#define EMAC_ERROR_BADPACKET            5   //< Supplied packet was invalid
#define EMAC_ERROR_MACFATAL             6   //< Fatal Error - EMAC_close() required

#define EMAC_DEVMAGIC   0x0aceface      //< Device Magic number
#define EMAC_NUMSTATS   36              //< Number of statistics regs


//-----------------------------------------------------------------------
// STANDARD DATA STRUCTURES
//-----------------------------------------------------------------------

typedef net_descriptor EMAC_Pkt;

// Packet Queue
typedef struct _pktq {
  uint32      Count;      // Number of packets in queue
  EMAC_Pkt    *pHead;     // Pointer to first packet
  EMAC_Pkt    *pTail;     // Pointer to last packet
} PKTQ;


// Transmit/Receive Descriptor Channel Structure
// (One receive and up to 8 transmit in this driver)
typedef struct _EMAC_DescCh {
    struct _EMAC_Device *pd;      // Pointer to parent structure   /
    PKTQ            DescQueue;    // Packets queued as desc        /
    PKTQ            WaitQueue;    // Packets waiting for TX desc   /
    uint32          ChannelIndex; // Channel index 0-7             /
    uint32          DescMax;      // Max number of desc (buffs)    /
    uint32          DescCount;    // Current number of desc        /
    EMAC_Desc       *pDescFirst;  // First desc location           /
    EMAC_Desc       *pDescLast;   // Last desc location            /
    EMAC_Desc       *pDescRead;   // Location to read next desc    /
    EMAC_Desc       *pDescWrite;  // Location to write nest desc   /
} EMAC_DescCh;



//  Transmit/Receive Channel info Structure
//  (one receive and up to 8 transmit per core in this example)
typedef struct _EMAC_ChannelInfo {
    uint32    TxChanEnable;
    /**< Which specific Tx Channels(0-7) to use
      * if TxChannels = 0 does not allocate the Tx channels for the core
      * if TxChannels = 1, 2, 4, 8, ... allocates which specific TxChannels to use
	  * 0x01: channel 0, 0x02: channel 1, 0x04: channel 2, 0x80: channel 7
      * User has to take care of allocating a portion from total allocation
      * for the cores */
    uint32    RxChanEnable;
    /**< Which specific Rx Channels(0-7) to use
      *  if RxChannel = 0 does not allocate the Rx channel for the core
      *  if RxChannel = 1, 2,4,8,... which specific channel to use for the core
	  * 0x01: channel 0, 0x02: channel 1, 0x04: channel 2, 0x80: channel 7 */
} EMAC_ChannelInfo;


//  MAC addresses configuration Structure
typedef struct _EMAC_AddrConfig {
	uint8 Addr[6];  	// MAC address specific to channel
} EMAC_AddrConfig;


//  EMAC_Config
/*
 *  The config structure defines how the EMAC device should operate. It is
 *  passed to the device when the device is opened, and remains in effect
 *  until the device is closed.
 *
 *  The following is a short description of the configuration fields:
 *
 *  UseMdio      - Uses MDIO configuration if required. In case of SGMII
 *                 MAC to MAC communication MDIO is not required. If this
 *                 field is one (1) configures MDIO
 *                          zero (0) does not configure MDIO
 *
 *  ModeFlags    - Specify the Fixed Operating Mode of the Device:
 *      - EMAC_CONFIG_MODEFLG_CHPRIORITY  - Treat TX channels as Priority Levels
 *                                   (Channel 7 is highest, 0 is lowest)
 *      - EMAC_CONFIG_MODEFLG_MACLOOPBACK - Set MAC in Internal Loopback for
 *                                          Testing
 *      - EMAC_CONFIG_MODEFLG_RXCRC       - Include the 4 byte EtherCRC in RX
 *                                          frames
 *      - EMAC_CONFIG_MODEFLG_TXCRC       - Assume TX Frames Include 4 byte
 *                                          EtherCRC
 *      - EMAC_CONFIG_MODEFLG_PASSERROR   - Receive Error Frames for Testing
 *      - EMAC_CONFIG_MODEFLG_PASSCONTROL - Receive Control Frames for
 *                                          Testing
 *
 *  MdioModeFlags - Specify the MDIO/PHY Operation (See csl_MDIO.H)
 *
 *  TxChannels    - Number of TX Channels to use (1-8, usually 1)
 *
 *  MacAddr       - Device MAC address
 *
 *  RxMaxPktPool  - Max Rx packet buffers to get from pool
 *                  (Must be in the range of 8 to 192)
 *
 *  A list of callback functions is used to register callback functions with
 *  a particular instance of the EMAC peripheral. Callback functions are
 *  used by EMAC to communicate with the application. These functions are
 *  REQUIRED for operation. The same callback table can be used for multiple
 *  driver instances.
 *
 *  The callback functions can be used by EMAC during any EMAC function, but
 *  mostly occur during calls to EMAC_statusIsr() and EMAC_statusPoll().
 *
 *  <b>pfcbGetPacket </b> -  Called by EMAC to get a free packet buffer from
 *                   the application layer for receive data. This function
 *                   should return NULL is no free packets are available.
 *                   The size of the packet buffer must be large enough
 *                   to accommodate a full sized packet (1514 or 1518
 *                   depending on the EMAC_CONFIG_MODEFLG_RXCRC flag), plus
 *                   any application buffer padding (DataOffset).
 *
 *  <b>pfcbFreePacket </b> - Called by EMAC to give a free packet buffer back
 *                   to the application layer. This function is used to
 *                   return transmit packets. Note that at the time of the
 *                   call, structure fields other than pDataBuffer and
 *                   BufferLen are in an undefined state.
 *
 *  <b>pfcbRxPacket </b>   - Called to give a received data packet to the
 *                   application layer. The applicaiton must accept the packet.
 *                   When the application is finished with the packet, it
 *                   can return it to its own free queue. This function also
 *                   returns a pointer to a free packet to replace the received
 *                   packet on the EMAC free list. It returns NULL when no free
 *                   packets are available. The return packet is the same as
 *                   would be returned by pfcbGetPacket. Thus if a newly
 *                   received packet is not desired, it can simply be returned
 *                   to EMAC via the return value.
 *
 *  <b>pfcbStatus </b>     - Called to indicate to the application that it
 *                   should call EMAC_getStatus() to read the current
 *                   device status. This call is made when device status
 *                   changes.
 *
 *  <b>pfcbStatistics </b> - Called to indicate to the application that it
 *                   should call EMAC_getStatistics() to read the
 *                   current Ethernet statistics. Called when the
 *                   statistic counters are to the point of overflow.
 *
 *  The hApplication calling calling argument is the application's handle
 *  as supplied to the EMAC device in the EMAC_open() function.
 */
typedef struct _EMAC_Config {
    uint8       UseMdio;           // MDIO Configuation select. User has to pass one (1) if MDIO Configuration  is needed, if not should pass zero (0)
    uint32      ModeFlags;         // Configuation Mode Flags
//    uint32      MdioModeFlags;     // CSL_MDIO Mode Flags (see CSL_MDIO.H)
//    uint8       DescBase;          // This member is for descriptor memory selction to place the EMAC descriptors in CPPI RAM or  L2 RAM or DDR memory
    EMAC_ChannelInfo ChannelInfo;  // Tx and Rx Channels information for the one core to use
//	  uint8 TotalNumOfMacAddrs;      // Total number of MAC addresses to be assigned for all receive channels
//    EMAC_AddrConfig **MacAddr;     // Mac Addresses structure
    uint32      RxMaxPktPool;      // Max Rx packet buffers to get from pool
    uint32      TxMaxPktPool;      // Max Rx packet buffers to get from pool /
    uint32      PktMTU;            // Max physical packet size
} EMAC_Config;


//-----------------------------------------------------------------------*\
// EMAC_Config
//-----------------------------------------------------------------------*/
/*
typedef struct _EMAC_Config {
    uint32        ModeFlags;      // Configuation Mode Flags
    uint32        MdioModeFlags;  // CSL_MDIO Mode Flags (see CSL_MDIO.H)
    uint32        TxChannels;     // Number of Tx Channels to use (1-8)
//    uint8       MacAddr[6];     // Mac Address
    uint32        RxMaxPktPool;   // Max Rx packet buffers to get from pool
    uint32        TxMaxPktPool;   // Max Rx packet buffers to get from pool
    EMAC_Pkt *  (*pfcbGetPacket)(Handle hApplication, PKTQ *pPktQueue);
    void        (*pfcbPutPacket)(Handle hApplication, PKTQ *pPktQueue, EMAC_Pkt *pPacket);
} EMAC_Config;
*/


//  Configuration Mode Flags
#define EMAC_CONFIG_MODEFLG_PROMISCUOUS 0x0001 //   /


//  EMAC_Status
//  The status structure contains information about the MAC's run-time
//  status.
/*
 *  The following is a short description of the configuration fields:
 *
 *  MdioLinkStatus - Current link stat (non-zero on link; see CSL_MDIO.H)
 *  PhyDev         - Current PHY device in use (0-31)
 *  RxPktHeld      - Current number of Rx packets held by the EMAC device
 *  TxPktHeld      - Current number of Tx packets held by the EMAC device
 *  FatalError     - Fatal Error Code (TBD)
 */
typedef struct _EMAC_Status {
    uint32      MdioLinkStatus;     //< CSL_MDIO Link status (see csl_mdio.h)
    uint32      PhyDev;             //< Current PHY device in use (0-31)
    uint32      RxPktHeld;          //< Number of packets held for Rx
    uint32      TxPktHeld;          //< Number of packets held for Tx
    uint32      FatalError;         //< Fatal Error when non-zero
} EMAC_Status;


//   EMAC Main Device Instance Structure
typedef struct _EMAC_Device
{
net_config      ncfg;
uint32          rx_intrpt;    // EMAC RX interrupt             /
uint32          tx_intrpt;    // EMAC TX interrupt             /
uint32          t1_intrpt;    // Timer 1 interrupt             /
uint32          smphr;        // EMAC semaphore                /
    Handle          hApplication;   //< Calling Application's Handle
	SGMII_Config *  hSgmii;          //< Handle to Sgmii Module
    uint32          RxFilter;       //< Current RX filter value
    uint32          PktMTU;         //< Max physical packet size
    uint32          MacHash1;       //< Hash value cache
    uint32          MacHash2;       //< Hash value cache
    uint32          FatalError;     //< Fatal Error Code
EMAC_Pkt*       pkt_rx;       //                               /
EMAC_Pkt*       pkt_tx;       //                               /
uint8*          pkt_data;
PKTQ	        RxQueue;	  // Packet Queue for Receive      /
PKTQ	        TxQueue;      // Packet Queue for Transmit     /
    EMAC_Config     Config;         //< Original User Configuration
//    EMAC_Statistics Stats;          //< Current running statistics
    EMAC_DescCh     RxCh[8];        //< Receive channel status
    EMAC_DescCh     TxCh[8];        //< Transmit channel status
bool    old_link;
bool    pkt_prznt;
void            (*callback)( const char* iname, net_config* cfg );
} EMAC_Device;



// Main Device Instance Structure
/*
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
    EMAC_DescCh     RxCh;         // Receive channel status        /
    EMAC_DescCh     TxCh;      // Transmit channel status       /
    void            (*callback)( const char* iname, net_config* cfg );
} EMAC_Device;
*/




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
* EMAC_RxServiceCheck()
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
extern "C" uint32 EMAC_RxServiceCheck( Handle hEMAC );

/*-----------------------------------------------------------------------*\
* EMAC_TxServiceCheck()
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
extern "C" uint32 EMAC_TxServiceCheck( Handle hEMAC );


#endif /* _ETH6457_EMAC_H_ */

