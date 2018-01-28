// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: all
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d:
// !: -:
// ---------------------------------------------------------------------------
#include <net_packet_parser.h>
#include <os.h>
#include <rts.h>
// ---------------------------------------------------------------------------
bool netpp_is_bcast( net_packet& pkti )
{
  return ( ( pkti.eth->dst[0] & pkti.eth->dst[1] & pkti.eth->dst[2] & pkti.eth->dst[3] & pkti.eth->dst[4] & pkti.eth->dst[5] ) == 0xff );
}
// ---------------------------------------------------------------------------
bool netpp_is_mcast( net_packet& pkti )
{
  if( pkti.eth->dst[0] != 0x01 ) return false;
  return true;
}
// ---------------------------------------------------------------------------
int32 netpp_parse( net_config& cfg, net_descriptor* packet )
{
  bool bcast, mcast, not_pmode;
  net_packet& pkti = packet->pkt;
  int32 r;
  net_8021q* qos;
  
  memset( &pkti, 0, sizeof(net_packet) );

  pkti.eth = (net_eth*)packet->data;
  not_pmode = ( ( cfg.flags & NETCFG_PROMISCUOUSE ) == 0 );

  if( not_pmode )
  {
    mcast = netpp_is_mcast( pkti );
    bcast = netpp_is_bcast( pkti );
    if( mcast )
    {
      if( cfg.flags & NETCFG_DROPMCAST )
      {
        r = NETPP_DROP;
        goto l_fail;
      }
    }
    else if( bcast )
    {
      if( cfg.flags & NETCFG_DROPBCAST )
      {
        r = NETPP_DROP;
        goto l_fail;
      }
    }
    else
    {
      if( memcmp( pkti.eth->dst, cfg.mac, 6 ) != 0 )
      {
        r = NETPP_WRONG_MAC;
        goto l_fail;
      }
    }
  }
  pkti.net_p_type = htons( pkti.eth->protocol );
  pkti.net_p = packet->data + sizeof(net_eth);
  pkti.protocol = NETPP_P_ETHER;

  if( pkti.net_p_type == NETPP_ETH_P_8021Q )
  {
    qos = (net_8021q*)pkti.net_p;
    pkti.net_p += 4;
    pkti.net_p_type = htons( qos->h_proto );
  }
  else if( pkti.net_p_type < 1500 )
  {
    pkti.snap = (net_snap*)( packet->data + sizeof(net_eth) );
    if( ( cfg.flags & NETCFG_PROMISCUOUSE ) == 0 )
    {
      if( ( pkti.snap->dsap != 0xaa ) || ( pkti.snap->ssap != 0xaa ) || ( pkti.snap->ctrl != 0x03 ) )
      {
        r = NETPP_WRONG_SNAP;
        goto l_fail;
      }
    }
    pkti.net_p_type = htons( pkti.snap->h_proto );
    pkti.net_p += sizeof(net_snap);
  }

  switch( pkti.net_p_type )
  {
    case NETPP_ETH_P_ARP:
    {
      if( not_pmode )
      {
        if( ( htons( pkti.arp->hrd_addr_fmt ) != 1 ) ||
            ( htons( pkti.arp->proto_addr_fmt ) != NETPP_ETH_P_IP ) ||
            ( pkti.arp->hdr_addr_len != 6 ) ||
            ( pkti.arp->proto_addr_len != 4 ) )
        {
          r = NETPP_WRONG_ARP_FORMAT;
          goto l_fail;
        }
      }
      pkti.protocol = NETPP_P_ARP;
    }
    return NETPP_OK;

    case NETPP_ETH_P_IP:
    {
      pkti.transp_p_type = pkti.ip->protocol;
      pkti.transp_p = pkti.net_p + ( ( pkti.ip->version_ihl & 0x0f ) << 2 );
      pkti.protocol = NETPP_P_IP;

      if( not_pmode )
      {
        if( mcast )
        {
          if( ( pkti.eth->dst[1] != 0x00 ) ||
              ( pkti.eth->dst[2] != 0x5e ) ||
              ( pkti.eth->dst[3] != ( pkti.ip->dst_ip_char[1] & 0x7f ) ) ||
              ( pkti.eth->dst[4] != pkti.ip->dst_ip_char[2] ) ||
              ( pkti.eth->dst[5] != pkti.ip->dst_ip_char[3] ) )
          {
            r = NETPP_WRONG_MCAST;
            goto l_fail;
          }
        }
      }

      switch( pkti.transp_p_type )
      {
        case NETPP_IP_P_TCP:
        {
          pkti.uplevel_p = pkti.transp_p + ( ( pkti.tcp->offset_rsvd >> 1 ) & 0x7f );
          pkti.protocol = NETPP_P_TCP;
        }
        break;

        case NETPP_IP_P_UDP:
        {
          pkti.uplevel_p = pkti.transp_p + 8;
          pkti.protocol = NETPP_P_UDP;
        }
        break;

        case NETPP_IP_P_ICMP:
        {
          pkti.protocol = NETPP_P_ICMP;
        }
        break;

        case NETPP_IP_P_IGMP:
        {
          pkti.protocol = NETPP_P_IGMP;
        }
        break;
      }
    
    }
    break;

    default:
    {
      if( not_pmode )
      {
        r = NETPP_WRONG_PROTOCOL;
        goto l_fail;
      }
    }
    break;
  }

  return NETPP_OK;

l_fail:

  memset( &pkti, 0, sizeof(net_packet) );

  return r;
}
// ---------------------------------------------------------------------------
uint16 netpp_calc_ipchk( void* buf, uint16 len )
{
  uint8* p = (uint8*)buf;
  uint64 cs = 0;
  while( len >= 4 )
  {
    cs += _mem4( p );
    p += 4;
    len -= 4;
  }
  if( len & 2 )
  {
    cs += (*(uint16*)p);
    p += 2;
  }
  if( len & 1 ) cs += (*p);
  cs = ( ( cs & 0xffff ) + ( ( cs >> 16 ) & 0xffff ) + ( cs >> 32 ) );
  cs += cs >> 16;
  return ~((uint16)cs);
}
// ---------------------------------------------------------------------------
int32 netpp_ipchk( void* packet )
{
  net_packet pkti;
  
  // Initial test
  pkti.eth = (net_eth*)packet;
  pkti.net_p_type = htons( pkti.eth->protocol );
  pkti.net_p = (uint8*)packet + sizeof(net_eth);
  // Channel layer
  if( pkti.net_p_type == NETPP_ETH_P_8021Q )
  {
    pkti.net_p += 2;
  }
  else if( pkti.net_p_type < 1500 )
  {
    pkti.snap = (net_snap*)( (char*)packet + sizeof(net_eth) );
    pkti.net_p_type = htons( pkti.snap->h_proto );
    pkti.net_p += sizeof(net_snap);
  }

  if( pkti.net_p_type != NETPP_ETH_P_IP ) return NETPP_WRONG_PROTOCOL;

  // Clear check summ
  uint16* iphdr = (uint16*)pkti.net_p;
  iphdr[5] = 0;
  // Set check summ
  iphdr[5] = netpp_calc_ipchk( iphdr, ( pkti.ip->version_ihl & 15 ) << 2 );

  return NETPP_OK;
}
// ---------------------------------------------------------------------------
