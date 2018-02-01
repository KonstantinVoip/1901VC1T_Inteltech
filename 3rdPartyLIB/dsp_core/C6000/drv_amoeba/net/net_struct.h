// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: all
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d:
// !: -:
// ---------------------------------------------------------------------------
#ifndef __Driver_Net_Structures_H__
#define __Driver_Net_Structures_H__

#include <os_types.h>

// -- Standard packet buffer size --------------------------------------------

#define NET_PACKET_SIZE         1536

// -- Configuration interface flags ------------------------------------------

#define NETCFG_PROMISCUOUSE     0x0001
#define NETCFG_NOARP            0x0002
#define NETCFG_DROPBCAST        0x0004
#define NETCFG_DROPMCAST        0x0008
#define NETCFG_NETFSDEV         0x0010
// -- Macroses ---------------------------------------------------------------

#define NET_IP4( a, b, c, d )   ( ( (uint32)(a) & 0x000000ff ) + ( ( (uint32)(b) & 0x000000ff ) << 8 ) + ( ( (uint32)(c) & 0x000000ff ) << 16 ) + ( ( (uint32)(d) & 0x000000ff ) << 24 ) )

// -- Structures for packet parser -------------------------------------------
/* Do not forget that all data fields in big endian format */

struct net_eth
{
  uint8                         dst[6];
  uint8                         src[6];
  uint16                        protocol;
};

struct net_ip
{
  uint8                         version_ihl;
  uint8                         type_of_service;
  uint16                        total_length;
  uint16                        id;
  uint16                        flags_offset;
  uint8                         ttl;
  uint8                         protocol;
  uint16                        checksumm;
  union
  {
    uint32                      src_ip;
    uint8                       src_ip_char[4];
  };
  union
  {
    uint32                      dst_ip;
    uint8                       dst_ip_char[4];
  };
};

struct net_arp
{
  uint16                        hrd_addr_fmt;
  uint16                        proto_addr_fmt;
  uint8                         hdr_addr_len;
  uint8                         proto_addr_len;
  uint16                        opcode;
  // Ethernet fields
  uint8                         sender_mac[6];
  uint8                         sender_ip[4];
  uint8                         target_mac[6];
  uint8                         target_ip[4];
};

struct net_udp
{
  uint16                        src_port;
  uint16                        dst_port;
  uint16                        length;
  uint16                        checksumm;
};

struct net_tcp
{
  uint16                        src_port;
  uint16                        dst_port;
  uint32                        sequence_number;
  uint32                        acknowledgement_number;
  uint8                         offset_rsvd;
  uint8                         rsvd_flags;
  uint16                        window;
  uint16                        checksumm;
  uint16                        urgent_point;
};

struct net_icmp
{
  uint8                         type;
  uint8                         code;
  uint16                        checksum;
  union
  {
    struct
    {
      uint16                    id;
      uint16                    sequence;
    }
    echo;

    uint32                      gateway;
    
    struct
    {
      uint16                    __unused;
      uint16                    mtu;
    }
    frag;
  }
  un;
};

struct net_igmp_v2
{
  uint8                         type;
  uint8                         max_response_time;
  uint16                        check_summ;
  uint32                        group_address;
};

union net_igmp
{
  uint8                         type;
  net_igmp_v2                   v2;
};

struct net_snap
{
  uint8                         dsap;
  uint8                         ssap;
  uint8                         ctrl;
  uint8                         out_id[3];
  uint16                        h_proto;
};

struct net_8021q
{
  uint16                        flags;
  uint16                        h_proto;
};

struct net_packet
{
  uint16                        net_p_type;
  uint16                        transp_p_type;
  uint32                        protocol;
  union
  {
    uint8*                      channel_p;
    net_eth*                    eth;
  };
  union
  {
    uint8*                      net_p;
    net_ip*                     ip;
    net_arp*                    arp;
  };
  union
  {
    uint8*                      transp_p;
    net_tcp*                    tcp;
    net_udp*                    udp;
    net_icmp*                   icmp;
    net_igmp*                   igmp;
  };
  net_snap*                     snap;
  uint8*                        uplevel_p;
};

// -- Standard structures for network driver ---------------------------------

struct net_config
{
  uint8                         mac[6];         // MAC address of network device
  uint16                        flags;          // Flags
  uint32                        ip4;            // IPv4 address of network device
  uint32                        mask4;          // IPv4 network mask
  uint32                        gateway4;       // IPv4 default gateway for network device
  uint32                        mtu;            // Maximum transfer unit
};

struct net_descriptor
{
  net_descriptor*               prev;
  net_descriptor*               next;
  uint32                        size;           // Size of <data> buffer
  uint32                        length;         // Packet length
  uint8*                        data;           // Packet data
  net_packet                    pkt;            // Parsed packet structure
  void*                         dev_desc;       // Device data pointer
  void*                         usr_desc;       // User data pointer
};

struct net_send
{
  uint32                        length;         // Packet length
  uint8*                        data;           // Packet data
};

#endif
