// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp1251
// !: d: Модуль содержит реализацию функций менеджера для создания виртуальных сетевых карт 
// !: d: на одном физическом сетевом контроллере.
// !: -: 
// ---------------------------------------------------------------------------
#include <os.h>
#include <rts.h>
#include <drv_vrnet.h>
#include <net_struct.h>
#include <vnet_eth.h>
#ifdef CHIP_6457 
#include <drv_eth6457.h>
#else
#include <drv_eth6412.h>
#endif

#define NETPP_ETH_P_ARP         0x0806
#define NETPP_ETH_P_IP          0x0800
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
uint32 os_eth_handle = 0;
// ---------------------------------------------------------------------------
uint8 vnet_dev_list_size = 0;
// ---------------------------------------------------------------------------
VNET_DEV *vnet_dev_list;
// ---------------------------------------------------------------------------
void netcfg_change_callback(char *dev_name,net_config *cfg)
{
  for(uint8 i = 0; i < vnet_dev_list_size; i++)
  {
    if(!strcmp(vnet_dev_list[i].name,dev_name))
    {
      sem_lock(vnet_dev_list[i].dev_sem,SEM_INFINITY);
      memcpy(&vnet_dev_list[i].vn_cfg,cfg,sizeof(net_config));
      sem_unlock(vnet_dev_list[i].dev_sem);
      return;
    }
  }    
}  
// ---------------------------------------------------------------------------
int32 vnet_dev_list_create(uint8 v_num)
{ 
  char path[15];
  memset(&path,0,sizeof(path));

  if( v_num > 9 ) 
    return OSE_BAD_PARAM;

  if(vnet_dev_list_size != 0)
    return OSE_ALREADY_PLUGGED;  

  if(v_num > 4)
    return OSE_BAD_PARAM;

  vnet_dev_list_size = v_num;

  vnet_dev_list = (VNET_DEV*)heap_alloc(NULL, v_num*sizeof(VNET_DEV),HEAP_ALIGN_4);
  if(vnet_dev_list == NULL)
    return OSE_NO_MEMORY;

  strcpy(path,"/dev/net/vnet");
    
  for(uint8 i = 0; i < vnet_dev_list_size; i++)
  {

    memset(&vnet_dev_list[i],0,sizeof(VNET_DEV));  

	vnet_dev_list[i].vn_cfg.ip4   = NET_IP4( 192, 168, i, 1 );

    vnet_dev_list[i].vn_cfg.mask4 = NET_IP4( 255, 255, 255, 0 );
    memset(&vnet_dev_list[i].vn_cfg.mac,i,6);
    vnet_dev_list[i].vn_cfg.flags = NETCFG_PROMISCUOUSE;

    path[13] = '0' + i;
	path[14] = 0;
    if(drv_vrnet_plug(path,vnet_dev_list[i].vn_cfg,2,2) != OSE_OK)
    {
      REG_OSTS0 |= OSTS0_NETCARD_FAIL;
      return OSE_FAIL;
    }

    vnet_dev_list[i].handle  = drv_mkd(path);
    if(vnet_dev_list[i].handle == RES_VOID)
      return OSE_NO_DEVICE;
    res_share(vnet_dev_list[i].handle);

    vnet_dev_list[i].dev_sem  = sem_alloc(1,0);
    if(vnet_dev_list[i].dev_sem == RES_VOID)
      return OSE_CANT_CREATE_SEM;

    // Replacing of sprintf(vnet_dev_list[i].name,"vnet%d",i);
    char num[2];
    num[0] = (char)i + '0';
    num[1] = 0;
    strcpy(vnet_dev_list[i].name, "vnet");
    strcat(vnet_dev_list[i].name, num);

    if(i == 0)
      vnet_dev_list[i].vn_type = NETCFG_NETFSDEV;

    if(drv_ioctl(vnet_dev_list[i].handle,NET_SET_CONFIG_CALLBACK,(void*)(uint32)&netcfg_change_callback) != OSE_OK)
      return OSE_FAIL;
  }

  return OSE_OK;  
}
// ---------------------------------------------------------------------------
void vnet_dev_list_destroy()
{
  for(uint8 i = 0;i < vnet_dev_list_size; i++)
  {
    drv_rmd(vnet_dev_list[i].handle);
    sem_free(vnet_dev_list[i].dev_sem);
    memset(&vnet_dev_list[i],0,sizeof(VNET_DEV));  
  } 
  vnet_dev_list_size = 0;
}
// ---------------------------------------------------------------------------
int32 EthHavePacket(void** packet, net_descriptor** eth_rxd)
{
  if( drv_ioctl( os_eth_handle, NET_RECV_GET, eth_rxd ) != OSE_OK ) return 0;
  if( *eth_rxd == NULL ) return 0;
  (*packet) = (*eth_rxd)->data;
  return (*eth_rxd)->length;
}
// ---------------------------------------------------------------------------
int32 EthFreePacket(net_descriptor** eth_rxd)
{
  if( *eth_rxd == NULL ) return 1;
  if( drv_ioctl( os_eth_handle, NET_RECV_PUT, eth_rxd ) != OSE_OK ) return 2;
  *eth_rxd = NULL;
  return 0;
}
// ---------------------------------------------------------------------------
int32 PutPacketInVnet(uint32 handle, void *pack,uint16 len)
{
  volatile net_descriptor* desc = NULL;

  while(!desc)
  {
    drv_ioctl(handle, NET_HOST_RECV_GET, &desc);
    if(!desc)
      prc_yield();
  }
  
  desc->length = len;
  memcpy(desc->data,pack,len);
  drv_ioctl(handle, NET_HOST_RECV_PUT, &desc);
   
  return 0;
}
// ---------------------------------------------------------------------------
int CheckEth()
{
   uint16 len;
   uint32* pack;   
   net_descriptor* eth_rxd = NULL;

//   len = EthHavePacket((void**)pack, &eth_rxd);
   len = EthHavePacket((void**)&pack, &eth_rxd);
   if(!len)
     return -1;

  net_eth *eth_hdr = (net_eth*)(pack);
  uint16 proto = htons(eth_hdr->protocol);

  int vi = -1;

  for(uint8 i = 0; i < vnet_dev_list_size; i++)
  {
    if(proto == NETPP_ETH_P_ARP)
    {
      net_arp *arp_hdr = (net_arp*)( ((uint8*)pack) + sizeof(net_eth));
      sem_lock(vnet_dev_list[i].dev_sem,SEM_INFINITY);
      if(!memcmp(&arp_hdr->target_ip,&vnet_dev_list[i].vn_cfg.ip4,4))
      {
	    vi = i;
        sem_unlock(vnet_dev_list[i].dev_sem);
        break;
      }
      sem_unlock(vnet_dev_list[i].dev_sem);
	  continue;
    }
    if(proto == NETPP_ETH_P_IP)
    {
      sem_lock(vnet_dev_list[i].dev_sem,SEM_INFINITY);
      if(!memcmp( eth_hdr->dst,&vnet_dev_list[i].vn_cfg.mac, 6))
      {
	    vi = i;
        sem_unlock(vnet_dev_list[i].dev_sem);
        break;
      }
      sem_unlock(vnet_dev_list[i].dev_sem);
    }
  }  

  if(vi >= 0)
    PutPacketInVnet(vnet_dev_list[vi].handle,(void*)pack,len);  

  EthFreePacket(&eth_rxd);

  return 0;
}
// ---------------------------------------------------------------------------
int CheckVnetList()
{
  uint8 i = 0;

  net_send ns_eth;
  int res = -1;
  for(i = 0; i < vnet_dev_list_size; i++)
  {
    net_descriptor* desc = NULL;
    if( drv_ioctl(vnet_dev_list[i].handle, NET_HOST_SEND_GET, &desc ) != OSE_OK) 
      while(1);//Вообще такого быть не должно!
 
    if(desc == NULL)
      continue;
    else
    {
      ns_eth.data   = desc->data;
      ns_eth.length = desc->length;

      while(drv_ioctl(os_eth_handle, NET_SEND_PACKET, &ns_eth))
        prc_yield();      

      drv_ioctl(vnet_dev_list[i].handle, NET_HOST_SEND_PUT, &desc);
	  res = 0;
    }    
  }
  return res;
}
// ---------------------------------------------------------------------------
extern int EthProcess(void *arg)
{
  while(1)
  {  
    if( CheckEth() < 0)
    	prc_yield();
  }
  return 0;
}
// ---------------------------------------------------------------------------
extern int VnetProcess(void *arg)
{
  while(1)
  {  
    if( CheckVnetList() < 0)
    	prc_yield();
  }
  return 0;
}
// ---------------------------------------------------------------------------
int32 _vnet_eth_init(uint8 vnum)
{
  int32 res;
  s_prc_attr pattr;

  os_eth_handle = drv_mkd("/dev/net/eth0");
  if(os_eth_handle == RES_VOID)
    return OSE_VOID_RESOURCE;

  res_share(os_eth_handle);//???

  res = vnet_dev_list_create(vnum);
  if(res != OSE_OK)
    return res;
  
  memset( &pattr, 0, sizeof(pattr) );
  pattr.priority = 0;
  pattr.stack = 512;//1024;//2048
  res = prc_create(EthProcess,NULL,0,&pattr);
  if(res < 0)
  {
    vnet_dev_list_destroy();
    return OSE_CANT_CREATE_PROCESS;  
  }
  res = prc_create(VnetProcess,NULL,0,&pattr);
  if(res < 0)
  {
    vnet_dev_list_destroy();
    return OSE_CANT_CREATE_PROCESS;  
  }
  return OSE_OK;
}
// ---------------------------------------------------------------------------
s_os_extension vnet_eth_ext;

s_os_extension_f vnet_eth_ext_f[] =
{
  {NULL, SYSCALL_VNET_ETH_INIT,(uint32)&_vnet_eth_init}
};
// -----------------------------------------------------------------------------
OS_MODULE_INICIATOR(vnet_eth_ext)
{
  OS_MODULE_INIT(vnet_eth_ext)
  {
    vnet_eth_ext.name = "vnet_eth.lif";
    vnet_eth_ext.f_count = sizeof(vnet_eth_ext_f) / sizeof(s_os_extension_f);
    vnet_eth_ext.f_tab = vnet_eth_ext_f;
    vnet_eth_ext.flags = EXT_F_STATIC;
    ext_plug(&vnet_eth_ext);
  }
  OS_MODULE_DEINIT(vnet_eth_ext) {}
}
OS_MODULE_ACTIVATOR(vnet_eth_ext);
// -----------------------------------------------------------------------------


