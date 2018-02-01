// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: all
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d:
// !: -:
// ---------------------------------------------------------------------------
#ifndef __Network_Packet_Parser_H__
#define __Network_Packet_Parser_H__

#include <net_struct.h>

// -- Standard error codes ---------------------------------------------------

#define NETPP_OK                0
#define NETPP_DROP              -1
#define NETPP_WRONG_MAC         -2
#define NETPP_WRONG_SNAP        -3
#define NETPP_WRONG_ARP_FORMAT  -4
#define NETPP_WRONG_MCAST       -5
#define NETPP_WRONG_PROTOCOL    -6

// -- Protocol types ---------------------------------------------------------

#define NETPP_P_UNKNOWN         0
#define NETPP_P_ETHER           1
#define NETPP_P_ARP             2
#define NETPP_P_IP              3
#define NETPP_P_ICMP            4
#define NETPP_P_UDP             5
#define NETPP_P_TCP             6
#define NETPP_P_IGMP            7

#define NETPP_ETH_P_8021Q       0x8100
#define NETPP_ETH_P_ARP         0x0806
#define NETPP_ETH_P_IP          0x0800

#define NETPP_IP_P_ICMP         0x01
#define NETPP_IP_P_IGMP         0x02
#define NETPP_IP_P_TCP          0x06
#define NETPP_IP_P_UDP          0x11

// -- Functions --------------------------------------------------------------

extern int32 netpp_parse( net_config& cfg, net_descriptor* packet );
extern bool netpp_is_bcast( net_packet& pkti );
extern bool netpp_is_mcast( net_packet& pkti );
extern int32 netpp_ipchk( void* packet );

#endif
