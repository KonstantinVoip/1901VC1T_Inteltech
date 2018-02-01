#include <os_syscall.h>
#include <drv_dbgout.h>
#include <rts.h>

#include "tests.h"
#include "tpo.h"
#include "tpo_hash.h"



#ifdef TPO5
#include <drv_eth6412.h>
#include <drv_eth6412_emac.h>
#include <drv_eth6412_mdio.h>
#include <net_struct.h>
#endif

#ifdef TPO7
	#include "fifo.h"
	#ifndef CHIP_6457
		#include <drv_dp83820.h>
	#else
		#include "qdma_rwrd.h"
		#include <drv_eth6457.h>
		//#include <drv_eth6457_etcl.h>
		#include <drv_eth6457_emac.h>
		//#include <drv_eth6457_emachal.h>
	    #include <drv_eth6457_sgmii.h>
		//#include <drv_eth6457_sgmiihal.h>
	    #include <net_struct.h>

	#endif

#endif

#ifdef TPO6
#ifndef CHIP_6457
#include <drv_dp83820.h>
#else
#include "qdma_rwrd.h"
#include <drv_eth6457.h>
//#include <drv_eth6457_etcl.h>
#include <drv_eth6457_emac.h>
//#include <drv_eth6457_emachal.h>
#include <drv_eth6457_sgmii.h>
//#include <drv_eth6457_sgmiihal.h>
#include <net_struct.h>

#endif

#endif

extern hash_window hwindow[];

extern void* sh_mem_write;    

extern void* sh_mem_read_proc;       //начло общей памяти на чтение из процессора 1
extern void* sh_mem_read_crypt;      //начло общей памяти на чтение из шифратора

extern void* sh_mem_read_proc2;       //начло общей памяти на чтение из процессора 2
extern void* sh_mem_read_crypt2;      //начло общей памяти на чтение из шифратора 2

extern kdg_rez_test gl_result;
extern uint16 Start_dozu_nagr;


#define TCCINTNUM_READ	7//Если изменить, то необходимо поменять регистр QOPT в EDMA_qdmaConfigArgs
#define TCCINTNUM_WRITE	6//Если изменить, то необходимо поменять регистр QOPT в EDMA_qdmaConfigArgs
/*
#ifdef TPO5
//----------------------------------------------------------------------------
void QDMA_Read(void* dst,void* src,uint16 len)
{
	uint16 l=len/4;
	int ost=len&0x3;

	if(l)
	{
		EDMA_intClear(TCCINTNUM_READ);
		EDMA_qdmaConfigArgs(0x01370000,(uint32)src,l,(uint32)dst,0);//Urgent priority 
//		EDMA_qdmaConfigArgs(0x21370000,(uint32)src,l,(uint32)dst,0);//High priority 
//		EDMA_qdmaConfigArgs(0x41370000,(uint32)src,l,(uint32)dst,0);//Medium priority 
//		EDMA_qdmaConfigArgs(0x61370000,(uint32)src,l,(uint32)dst,0);//Low priority 
		while(!EDMA_intTest(TCCINTNUM_READ));
	}
	if(ost)
		memcpy(((char*)dst+4*l),((char*)src+4*l),ost);
}
#else
*/
#ifdef CHIP_6412
//----------------------------------------------------------------------------
void QDMA_Read(void* dst,void* src,uint16 len)
{
	uint16 l=len/4;
	int ost=len&0x3;

	if(l)
	{
		EDMA_intClear(TCCINTNUM_READ);
		EDMA_qdmaConfigArgs(0x01370000,(uint32)src,l,(uint32)dst,0);//Urgent priority 
//		EDMA_qdmaConfigArgs(0x21370000,(uint32)src,l,(uint32)dst,0);//High priority 
//		EDMA_qdmaConfigArgs(0x41370000,(uint32)src,l,(uint32)dst,0);//Medium priority 
//		EDMA_qdmaConfigArgs(0x61370000,(uint32)src,l,(uint32)dst,0);//Low priority 
		while(!EDMA_intTest(TCCINTNUM_READ));
	}
	if(ost)
		memcpy(((char*)dst+4*l),((char*)src+4*l),ost);
}
#endif

/*
#ifdef TPO6
#define QDMA_CHANNEL_RD            2
extern CSL_Edma3ParamSetup param_rd;

void QDMA_Read(void* dst,void* src,uint16 len)
{	
//	CSL_Edma3ParamSetup param_rd;

    uint16 l=len/4;
    int ost=len&0x3;
  
    sys_buslock();
      
    if(l)
    {
        param_rd.srcAddr     = (uint32)src;
        param_rd.aCntbCnt    = CSL_EDMA3_CNT_MAKE(len,1);
        param_rd.dstAddr     = (uint32)dst;
        param_rd.srcDstBidx  = CSL_EDMA3_BIDX_MAKE(0,0);
        param_rd.linkBcntrld = CSL_EDMA3_LINKBCNTRLD_MAKE(CSL_EDMA3_LINK_DEFAULT,0);
        param_rd.srcDstCidx  = CSL_EDMA3_CIDX_MAKE(0,0);
        param_rd.cCnt        = 1;
        
        EDMA3_qdmaIntClear( QDMA_CHANNEL_RD );
	    EDMA3_qdmaConfigArgs( 4, &param_rd );
        while(!EDMA3_qdmaIntTest(QDMA_CHANNEL_RD));

    }
    if(ost)
        memcpy(((char*)dst+4*l),((char*)src+4*l),ost);

    sys_busunlock();
}
#endif
*/
//----------------------------------------------------------------------------
void ReadDARAM0(uint16 addr,void* buf,uint16 len)
{
    QDMA_Read(buf,(char*)sh_mem_read_proc+addr, len);//mac+ip
//	memcpy(buf,(char*)sh_mem_read_proc+addr, len);

}

//----------------------------------------------------------------------------
void ReadDARAM1(uint16 addr,void* buf,uint16 len)
{
    QDMA_Read(buf,(char*)sh_mem_read_proc2+addr, len);//mac+ip
//	memcpy(buf,(char*)sh_mem_read_proc2+addr, len);
}


//#ifdef TPO5
#ifdef CHIP_6412

//----------------------------------------------------------------------------
void WriteDARAM(uint16 addr,void* buf,uint16 len)
{
uint16 l=(len+3)>>2;
uint32* s=(uint32*)buf;
uint32* d=(uint32*)((char*)sh_mem_write+addr);
	while(l--)
		_amem4(d++)=_mem4(s++);
}
#else

void WriteDARAM(uint16 addr,void* buf,uint16 len)
{
uint16 l=(len+7)>>3;
uint64* s=(uint64*)buf;
uint64* d=(uint64*)((char*)sh_mem_write+addr);
while(l--)
	_amem8(d++)=_mem8(s++);
}
#endif

//----------------------------------------------------------------------------
void ReadDARAM_CRYPT0(uint16 addr,void* buf,uint16 len)
{
//	QDMA_Read(2, buf,  (char*)sh_mem_read_crypt+addr, len );
    QDMA_Read(buf,(char*)sh_mem_read_crypt+addr, len);//mac+ip
//	memcpy(buf,(char*)sh_mem_read_crypt+addr, len);
}

//----------------------------------------------------------------------------
void ReadDARAM_CRYPT1(uint16 addr,void* buf,uint16 len)
{
//	QDMA_Read(2, buf,  (char*)sh_mem_read_crypt2+addr, len );
    QDMA_Read(buf,(char*)sh_mem_read_crypt2+addr, len);//mac+ip
//	memcpy(buf,(char*)sh_mem_read_crypt2+addr, len);
}



//----------------------------------------------------------------------------
uint32 TestCelostnost()
{
uint32 res = 0;

res = analysis_hash_fwmem(hwindow);

return res == 0 ? 0 : 1;
}

//----------------------------------------------------------------------------
uint32 TestDozu(kdg_rez_test* result)
{
//uint32 res = 0;
//int error = 0;
uint32 sh_d = SH_DOZU/8;
#ifdef TPO_M711B
uint32 start_adr = 0x100;
#else
uint32 start_adr = 0;
#endif



#ifdef TPO5
uint32 buf[LEN_BUF_FOR_TEST_DOZU];
#define	DAT555	0x55555555
#define	DATAAA	0xAAAAAAAA
uint32 one = 1;
#else
uint64 buf[LEN_BUF_FOR_TEST_DOZU];
#define	DAT555	0x5555555555555555
#define	DATAAA	0xAAAAAAAAAAAAAAAA
uint64 one = 1;
#endif



ReadDARAM0(start_adr, buf, LEN_DUZU_FOR_TEST);

		for(int i = 0; i < SH_DOZU; i++)
		{
			if(buf[i] != one << i)
			{
			result->data = buf[i] ^ (one << i);
			result->adrr = i * sh_d;
			return ERR_DOZU_WRCP0_RDSP;
			}
		}

		for(int i = SH_DOZU; i < LEN_BUF_FOR_TEST_DOZU; i+=2)
		{
			if(buf[i] != DAT555)
			{
			result->data = buf[i] ^ DAT555;
			result->adrr = i * sh_d;
			return ERR_DOZU_WRCP0_RDSP;
			}

			if(buf[i+1] != DATAAA)
			{
			result->data = buf[i+1] ^ DATAAA;
			result->adrr = (i+1) * sh_d;
			return ERR_DOZU_WRCP0_RDSP;
			}
		}


ReadDARAM1(start_adr, buf, LEN_DUZU_FOR_TEST);

		for(int i = 0; i < SH_DOZU; i++)
		{
			if(buf[i] != one << i)
			{
			result->data = buf[i] ^ (one << i);
			result->adrr = i * sh_d;
			return ERR_DOZU_WRCP1_RDSP;
			}
		}

		for(int i = SH_DOZU; i < LEN_BUF_FOR_TEST_DOZU; i+=2)
		{
			if(buf[i] != DAT555)
			{
			result->data = buf[i] ^ DAT555;
			result->adrr = i * sh_d;
			return ERR_DOZU_WRCP1_RDSP;
			}

			if(buf[i+1] != DATAAA)
			{
			result->data = buf[i+1] ^ DATAAA;
			result->adrr = (i+1) * sh_d;
			return ERR_DOZU_WRCP1_RDSP;
			}
		}

WriteDARAM(start_adr, buf, LEN_DUZU_FOR_TEST);

return TPO_OK;
}


//----------------------------------------------------------------------------
uint32 TestMove()
{
//uint32 res = 0;
//int error = 0;
#ifdef TPO_M711B
uint32 start_adr = 0x100;
#else
uint32 start_adr = 0;
#endif

#ifdef TPO5
uint32 buf[LEN_BUF_FOR_TEST_DOZU];
#define	DAT555	0x55555555
#define	DATAAA	0xAAAAAAAA
uint32 one = 1;
#else
uint64 buf[LEN_BUF_FOR_TEST_DOZU];
#define	DAT555	0x5555555555555555
#define	DATAAA	0xAAAAAAAAAAAAAAAA
uint64 one = 1;
#endif



	for(int i = 0; i < SH_DOZU; i++)
		buf[i] = one << i;

	for(int i = SH_DOZU; i < LEN_BUF_FOR_TEST_DOZU; i+=2)
	{
		buf[i] = DAT555;
		buf[i+1] = DATAAA;
	}

	WriteDARAM(start_adr, buf, LEN_DUZU_FOR_TEST);

return TPO_OK;
}


#define GPIO_DIR            (*(volatile uint32*)0x02b00010) // GPIO Direction Register
#define GPIO_OUT_DATA       (*(volatile uint32*)0x02b00014) // GPIO Output Data register
#define GPIO_SET_DATA       (*(volatile uint32*)0x02b00018) // GPIO Set Data register
#define GPIO_CLR_DATA       (*(volatile uint32*)0x02b0001c) // GPIO Clear Data Register
#define GPIO_IN_DATA        (*(volatile uint32*)0x02b00020) // GPIO Input Data Register


void alp_sinhrosig_tst()
{
uint32 res = GPIO_DIR;
GPIO_DIR = res & 0xFFDF;

GPIO_SET_DATA = 0x20;

asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
GPIO_CLR_DATA = 0x20;
}






//----------------------------------------------------------------------------
uint32 TestMove_ST1(kdg_rez_test* result)
{
#ifdef TPO_M711B
uint32 start_adr = 0x100;
#else
uint32 start_adr = 0;
#endif
uint32 sh_d = SH_DOZU/8;

#ifdef TPO5
uint32 buf[LEN_BUF_FOR_TEST_DOZU];
#define	DAT555	0x55555555
#define	DATAAA	0xAAAAAAAA
uint32 one = 1;
#else
uint64 buf[LEN_BUF_FOR_TEST_DOZU+5];
#define	DAT555	0x5555555555555555
#define	DATAAA	0xAAAAAAAAAAAAAAAA
uint64 one = 1;
#endif

ReadDARAM_CRYPT0(start_adr, buf, LEN_DUZU_FOR_TEST);

		for(int i = 0; i < SH_DOZU; i++)
		{
			if(buf[i] != one << i)
			{
			result->data = buf[i] ^ (one << i);
			result->adrr = (i * sh_d) + start_adr;
			return TPO_ERR;
			}
		}

		for(int i = SH_DOZU; i < LEN_BUF_FOR_TEST_DOZU; i+=2)
		{
			if(buf[i] != DAT555)
			{
			result->data = buf[i] ^ DAT555;
			result->adrr = (i * sh_d) + start_adr;
			return TPO_ERR;
			}

			if(buf[i+1] != DATAAA)
			{
			result->data = buf[i+1] ^ DATAAA;
			result->adrr = ((i+1) * sh_d) + start_adr;
			return TPO_ERR;
			}
		}


return TPO_OK;
}

#define		EN				(*(uint32 *)0x01B00000)
#define		DIR				(*(uint32 *)0x01B00004)
#define		VAL				(*(uint32 *)0x01B00008)
/*
uint32 Send_Recive_Packet(uint32 FileNet, void* Pack_wr, void* Pack_rd, uint32 len)
{


net_descriptor* p_txd = NULL;
net_descriptor* p_rxd = NULL;

//uint32 tim = 0x500000;

while(1)
{
  if( drv_ioctl( FileNet, NET_SEND_GET, &p_txd ) != OSE_OK ) 	//готовим к отправке
	return TPO_ERR;
  if( p_txd == NULL ) 
	return TPO_ERR;
  if( LEN_BUF1_FOR_TEST_SK > p_txd->size )
	return TPO_ERR;

//	sleep_m(50);
//while(tim--);

  memcpy( p_txd->data, Pack_wr, len );
  p_txd->length = len;


  if( drv_ioctl( FileNet, NET_SEND_PUT, &p_txd ) != OSE_OK ) 	//отправляем
	return TPO_ERR;
}



  return 0;
}
*/


uint32 Send_Recive_Packet(uint32 FileNet, void* Pack_wr, void* Pack_rd, uint32 len)
{
/*
uint32 res = EN;
EN = res | 0x8;
res = DIR;
DIR = res | 0x8;
*/


net_descriptor* p_txd = NULL;
net_descriptor* p_rxd = NULL;

uint32 tim = 0x500000;
	do//очистка приема
	{
		if( drv_ioctl( FileNet, NET_RECV_GET, &p_rxd ) != OSE_OK )
			return TPO_ERR;
  		if( p_rxd != NULL )
			if( drv_ioctl( FileNet, NET_RECV_PUT, &p_rxd ) != OSE_OK )
				return TPO_ERR;
	}while(p_rxd != NULL);


  if( drv_ioctl( FileNet, NET_SEND_GET, &p_txd ) != OSE_OK ) 	//готовим к отправке
	return TPO_ERR;
  if( p_txd == NULL ) 
	return TPO_ERR;
  if( LEN_BUF1_FOR_TEST_SK > p_txd->size )
	return TPO_ERR;

	sleep_m(100);
//	sleep_m(50);
//while(tim--);

  memcpy( p_txd->data, Pack_wr, len );
  p_txd->length = len;

//res = VAL;
//VAL = res | 0x8;
  if( drv_ioctl( FileNet, NET_SEND_PUT, &p_txd ) != OSE_OK ) 	//отправляем
	return TPO_ERR;
//VAL = res & (~0x8);


	
	sleep_m(100);
//tim = 0x500000;
//while(tim--);

  if( drv_ioctl( FileNet, NET_RECV_GET, &p_rxd ) != OSE_OK )
	return TPO_ERR;
  if( p_rxd == NULL )
	return TPO_ERR;
  if( p_rxd->length != len)
	return TPO_ERR;

  memcpy( Pack_rd, p_rxd->data, p_rxd->length );

	sleep_m(100);
//tim = 0x500000;
//while(tim--);

  if( drv_ioctl( FileNet, NET_RECV_PUT, &p_rxd ) != OSE_OK )
	return TPO_ERR;


  return 0;
}



//----------------------------------------------------------------------------
//#define ERR_RW_M		1//1 - ошибка общения с модулем или системная
//#define ERR_LOOP_M		2//2 - ошибка LOOPBACK в модуле
//#define ERR_LOOP_PHY	4//4 - ошибка LOOPBACK в физической среде
uint32 Test_SK()
{
uint32 res = 0;
int error = 0;

//uint32* reg_gpio = (uint32*)0x01B00008;
//uint32 l = 0;
uint32 id1 = 0;
uint32 id2 = 0;
bool link = false;

uint8 buf_big_wr[LEN_BUF1_FOR_TEST_SK];	//1514
uint8 buf_small_wr[LEN_BUF2_FOR_TEST_SK];	//64
uint8 buf_big_rd[LEN_BUF1_FOR_TEST_SK];	//1514
uint8 buf_small_rd[LEN_BUF2_FOR_TEST_SK];	//64

memset(buf_big_wr, 0xAA, LEN_BUF1_FOR_TEST_SK);
memset(buf_small_wr, 0x55, LEN_BUF2_FOR_TEST_SK);
memset(buf_big_rd, 0, LEN_BUF1_FOR_TEST_SK);
memset(buf_small_rd, 0, LEN_BUF2_FOR_TEST_SK);

uint32 FileNet = drv_mkd("/dev/net/eth0");
	if(FileNet == RES_VOID)
		return TPO_ERR;


#ifdef TPO5
dev_reg phy_reg;

phy_reg.device = PHY_RW_REG;
phy_reg.reg = PHYREG_ID1;
error = drv_ioctl(FileNet, NET_READ_REG, &phy_reg);
	if(error != OSE_OK)
	{
		res = TPO_ERR;
		goto end_tst_sk;	
	}
id1 = phy_reg.value & 0xFFFF;

phy_reg.reg = PHYREG_ID2;
error = drv_ioctl(FileNet, NET_READ_REG, &phy_reg);
	if(error != OSE_OK)
	{
		res = TPO_ERR;
		goto end_tst_sk;	
	}
id2 = phy_reg.value & 0xFF00;

if((id1 != 0x0013)|(id2 != 0x7800))
 if((id1 != 0x0022)|(id2 != 0x1500))
	res|=ERR_RW_LXT;

phy_reg.reg = PHYREG_CONTROL;

error = drv_ioctl(FileNet, NET_READ_REG, &phy_reg);

phy_reg.value |= PHYREG_CONTROL_LOOPBACK;		//загоняем модуль в loopback
error = drv_ioctl(FileNet, NET_WRITE_REG, &phy_reg);
	if(error != OSE_OK)
	{
		res = TPO_ERR;
		goto end_tst_sk;	
	}

sleep_m(100);//1000

error = Send_Recive_Packet(FileNet, buf_big_wr, buf_big_rd, LEN_BUF1_FOR_TEST_SK);	
	if((error == TPO_ERR) | (memcmp(buf_big_wr, buf_big_rd, LEN_BUF1_FOR_TEST_SK)))
		res|=ERR_LOOP_LXT;

error = Send_Recive_Packet(FileNet, buf_small_wr, buf_small_rd, LEN_BUF2_FOR_TEST_SK);
	if((error == TPO_ERR) | (memcmp(buf_small_wr, buf_small_rd, LEN_BUF2_FOR_TEST_SK)))
		res|=ERR_LOOP_LXT;


phy_reg.reg = PHYREG_CONTROL;
phy_reg.value ^= PHYREG_CONTROL_LOOPBACK;	//снимаем loopback
phy_reg.value |= (PHYREG_CONTROL_SPEED100 | PHYREG_CONTROL_DUPLEXFULL);	
error = drv_ioctl(FileNet, NET_WRITE_REG, &phy_reg);
	if(error != OSE_OK)
	{
		res = TPO_ERR;
		goto end_tst_sk;	
	}



memset(buf_big_rd, 0, LEN_BUF1_FOR_TEST_SK);
memset(buf_small_rd, 0, LEN_BUF2_FOR_TEST_SK);
//#else
#endif

sleep_m(500);//1500

error = drv_ioctl(FileNet, NET_LINK, &link);
	if(error != OSE_OK)
	{
		res = TPO_ERR;
		goto end_tst_sk;	
	}

if(link)
{
error = Send_Recive_Packet(FileNet, buf_big_wr, buf_big_rd, LEN_BUF1_FOR_TEST_SK);
	if((error == TPO_ERR) | (memcmp(buf_big_wr, buf_big_rd, LEN_BUF1_FOR_TEST_SK)))
		res|=ERR_LOOP_PHY;

error = Send_Recive_Packet(FileNet, buf_small_wr, buf_small_rd, LEN_BUF2_FOR_TEST_SK);
	if((error == TPO_ERR) | (memcmp(buf_small_wr, buf_small_rd, LEN_BUF2_FOR_TEST_SK)))
		res|=ERR_LOOP_PHY;
}
else
res|=ERR_LOOP_PHY;

end_tst_sk:

drv_rmd(FileNet);

return res;
}


//----------------------------------------------------------------------------
void Start_Test_N(kdg_rez_test* result)
{



    switch (result->n_test)
    {
      case CELOSTN:
	  {
		result->rez = TestCelostnost();
	  }
      break;

      case TEST_DOZU:		//управляет main
	  {
		result->rez = TestDozu(result);
	  }
      break;

      case TEST_MOVE:		//управляет main
	  {
		result->rez = TestMove();
	  }
      break;

      case TEST_MOVE_ST1:	//управляет main
	  {
		result->rez = TestMove_ST1(result);
	  }
      break;

      case TEST_SK:
	  {
		result->rez = Test_SK();
	  }
      break;

	  default:
      {
      result->rez = TPO_ERR;
//       cdg_error.ask = TPO_ERR;
//       msg_send(msg_desc->from, &cdg_error, sizeof(kdg_cmd_ask));  
      };

	}
return;
}


//процесс - тест тока для 5ки
int TestDOZU_Nagr(void* arg)
{
#define L 0x300/4

int error0=0;
int error1=0;

uint32 buf0[L]; 
uint32 buf1[L]; 

uint32 X=0;

memset(sh_mem_write,0,L*4);

buf0[0] = 0x5a5a5a5a;
WriteDARAM(0,buf0,4);

buf0[0] = 0;
buf1[0] = 0;
do
{
ReadDARAM0(0,buf0,4);
ReadDARAM1(0,buf1,4);
}
while((buf0[0] != 0x5a5a5a5a) | (buf1[0] != 0x5a5a5a5a));


while(Start_dozu_nagr)
{
  memset(buf0,0,sizeof(buf0));

  buf0[1]=X;

  for (int i=2;i<L;i++)
  {
   buf0[i]=buf0[i-1]*0x66467329+0xA6549873;
  }

  WriteDARAM(4,buf0,L*4);
  buf0[0]=1;
  WriteDARAM(4,buf0,4);


	do
  	{
		if(!Start_dozu_nagr)
		goto end_dozu_nagr;

   	ReadDARAM0(4,buf0,4);
   	ReadDARAM1(4,buf1,4);
  	}
  	while((buf0[0]==0) | (buf1[0]==0));

  ReadDARAM0(4,buf0,L*4);
  ReadDARAM1(4,buf1,L*4);

  for (int i=2;i<(L-2);i++)
  {
   if (buf0[i]!=buf0[i-1]*0x66467329+0xA6549873)
   {
	error0++;
	   if (buf1[i]!=buf1[i-1]*0x66467329+0xA6549873)
		error1++;
  }
  else
   if (buf1[i]!=buf0[i])
	error1++;

  }

  buf0[0]=0;
  WriteDARAM(4,buf0,4);

  do
  {
		if(!Start_dozu_nagr)
		goto end_dozu_nagr;

   ReadDARAM0(4,buf0,4);
   ReadDARAM1(4,buf1,4);
  }
  while((buf0[0]==1) |(buf1[0]==1));

gl_result.n_test = X++;
//X++;
gl_result.rez = error0;
gl_result.adrr = error1;
ReadDARAM0(0,buf0,4);
gl_result.data = buf0[0];
ReadDARAM1(0,buf1,4);
gl_result.data1 = buf0[0];
}

end_dozu_nagr:

prc_exit();
while(1);


}





extern uint32 sv_msg_open;

int Sv_Msg(void* arg)
{

    int32		error;
	uint32		msg_from;
//	kdg_cmd		to_iface;
	kdg_cmd_ask	cdg_error;
	s_message*  msg_desc;


uint32 buf55[LEN_MOVE/4];
uint32 bufAA[LEN_MOVE/4];
uint32 buf1[LEN_MOVE/4];
uint32 buf2[LEN_MOVE/4];

char buf11[1500];
char buf22[1500];

char buf12[1500];

uint32 FileNet = 0;

memset(buf55, 0x55, sizeof(buf55));
memset(bufAA, 0xAA, sizeof(bufAA));


  error = msg_open("sv");
  if(error != OSE_OK)
	while(1);

  while(sv_msg_open)
  {

	if(sv_msg_open == 0)
	break;

    error = msg_recv(&msg_desc, MSG_WAIT_10);

    if(msg_desc == NULL)
    {
	prc_yield();
    continue;
	}
    if(msg_desc->length != sizeof(kdg_cmd))
    {
      cdg_error.cmd = ERROR_CMD;
      cdg_error.ask = TPO_ERR;
      msg_send(msg_desc->from, &cdg_error, sizeof(kdg_cmd_ask));  
      msg_free(msg_desc);      
      continue;
    }
    msg_from = msg_desc->from;
    cdg_error.cmd = ((kdg_cmd*)msg_desc->data)->cmd;
    msg_free(msg_desc);      
    switch (cdg_error.cmd)
    {
      case N_TEST:
	  {
		cdg_error.ask = TPO_OK;
        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));

		kdg_rez_test result;        

		error = msg_recv(&msg_desc, MSG_WAIT_10);
	    if(msg_desc == NULL) continue;
	    if(msg_desc->length != sizeof(kdg_rez_test))
	    {
	      cdg_error.cmd = ERROR_CMD;
		  cdg_error.ask = TPO_ERR;
	      msg_send(msg_desc->from, &cdg_error, sizeof(kdg_cmd_ask));  
	      msg_free(msg_desc);      
 	     continue;
	    }
		memcpy(&result, msg_desc->data, sizeof(kdg_rez_test));
	    msg_free(msg_desc);      

        Start_Test_N(&result);
		result.cmd = RES_N_TEST;
        msg_send(msg_from, &result, sizeof(kdg_rez_test));

		
	  }
      break;
      
      case GOTOV_TEST_MOVE_15:
      {
		cdg_error.ask = GOTOV_TEST_MOVE_15;

        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
//	prc_yield();

		ReadDARAM_CRYPT0(0,buf1,sizeof(buf1));
		ReadDARAM_CRYPT1(0,buf2,sizeof(buf2));
		WriteDARAM(0, bufAA, sizeof(bufAA));


		if(memcmp(buf55, buf1, sizeof(buf1)))
			gl_result.data++;
		if(memcmp(buf55, buf2, sizeof(buf2)))
			gl_result.data1++;

		gl_result.n_test++;
		
	  }
      break;


      case GOTOV_TEST_MOVE_1A:
      {
		cdg_error.ask = GOTOV_TEST_MOVE_1A;

        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
//	prc_yield();

		ReadDARAM_CRYPT0(0,buf1,sizeof(buf1));
		ReadDARAM_CRYPT1(0,buf2,sizeof(buf2));
		WriteDARAM(0, buf55, sizeof(buf55));
		
//uint32 tsk = Test_SK();

		if(memcmp(bufAA, buf1, sizeof(buf1)))
			gl_result.data++;
		if(memcmp(bufAA, buf2, sizeof(buf2)))
			gl_result.data1++;

		gl_result.n_test++;
		
	  }
      break;


      case GOTOV_TEST_MOVE_25:
      {
		cdg_error.ask = GOTOV_TEST_MOVE_25;

        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
//	prc_yield();

		ReadDARAM_CRYPT0(sizeof(buf1),buf1,sizeof(buf1));
		ReadDARAM_CRYPT1(sizeof(buf1),buf2,sizeof(buf2));
		WriteDARAM(sizeof(buf1), bufAA, sizeof(bufAA));

//uint32 tsk = Test_SK();

		if(memcmp(buf55, buf1, sizeof(buf1)))
			gl_result.data++;
		if(memcmp(buf55, buf2, sizeof(buf2)))
			gl_result.data1++;

		gl_result.n_test++;
		
	  }
      break;

      case GOTOV_TEST_MOVE_2A:
      {
		cdg_error.ask = GOTOV_TEST_MOVE_2A;

        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
//	prc_yield();

		ReadDARAM_CRYPT0(sizeof(buf1),buf1,sizeof(buf1));
		ReadDARAM_CRYPT1(sizeof(buf1),buf2,sizeof(buf2));
		WriteDARAM(sizeof(buf1), buf55, sizeof(buf55));
		
//uint32 tsk = Test_SK();

		if(memcmp(bufAA, buf1, sizeof(buf1)))
			gl_result.data++;
		if(memcmp(bufAA, buf2, sizeof(buf2)))
			gl_result.data1++;

		gl_result.n_test++;
		
	  }
      break;

 
      case SEND_TEST_PACKET:
      {
		uint32 lenn = 1400+20;
		net_descriptor* p_txd = NULL;
		uint32 rress=0;
		bool lnk;


//uint32* tests = (uint32*)0xA0000FE0;
//uint32* tests1 = (uint32*)0xB0000FE0;

		ReadDARAM_CRYPT0(0,buf11,lenn);
		ReadDARAM_CRYPT1(0,buf22,lenn);

		if(memcmp(buf11, buf22, lenn))
		{
			for(int t=0; t<lenn; t++)
			{
				if(buf11[t]!=buf22[t])
				{

//  REG_GPIO_DIR &= ~( 0x00000060 );
// REG_GPIO_CLR_DATA = 0x00000060;
				lenn++;
//sleep_m(100);
				lenn--;
//  REG_GPIO_SET_DATA = 0x00000060; 
				}
			}

		cdg_error.ask = TPO_ERR;
        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));

 		break;
		}


		FileNet = drv_mkd("/dev/net/eth0");
		if(FileNet == RES_VOID) // НУ не передастся....
			goto close_drv1;


		if(drv_ioctl( FileNet, NET_SEND_GET, &p_txd ) != OSE_OK ) 	//готовим к отправке
			goto close_drv1;
		if( p_txd == NULL ) 
			goto close_drv1;
//		sleep_m(10);

		memcpy( p_txd->data, buf11, lenn );
		p_txd->length = lenn;

		rress = drv_ioctl( FileNet, NET_LINK, &lnk); 	//отправляем

		if(lnk)
		rress = drv_ioctl( FileNet, NET_SEND_PUT, &p_txd ); 	//отправляем
				
close_drv1:
		drv_rmd(FileNet);

		cdg_error.ask = TPO_OK;
        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));

		}
       	break;
        
        case RECV_TEST_PACKET:
        {

		uint32 lenn = 1400+20;
		net_descriptor* p_rxd = NULL;
//		uint32 res = 0;
		uint32 retry10 = 5;


		FileNet = drv_mkd("/dev/net/eth0");
		if(FileNet == RES_VOID)
			goto close_drv2;



		while(retry10--)
		{
		  if( drv_ioctl( FileNet, NET_RECV_GET, &p_rxd ) != OSE_OK )
			continue;
		  if( p_rxd == NULL )
			continue;
		  if( p_rxd->length != lenn)
		  {
			drv_ioctl( FileNet, NET_RECV_PUT, &p_rxd );
		  	continue;
		  }
		  else
		  {	
		  retry10++;
		  break;
		  }
		}

		if(!retry10)
		{
		cdg_error.ask = TPO_ERR;
        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));

		goto close_drv2;
		}

//		memcpy( buf1, p_rxd->data, p_rxd->length );
		WriteDARAM(0, p_rxd->data, p_rxd->length);

//		sleep_m(50);

		if(drv_ioctl( FileNet, NET_RECV_PUT, &p_rxd ) != OSE_OK)
			goto close_drv2;


		cdg_error.ask = TPO_OK;
        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));

close_drv2:
		drv_rmd(FileNet);
   		}
		break;



        case CLEAR_TEST_PACKET:
        {

		net_descriptor* p_rxd = NULL;
		FileNet = drv_mkd("/dev/net/eth0");

			do//очистка приема
			{
					drv_ioctl( FileNet, NET_RECV_GET, &p_rxd );
		  		if( p_rxd != NULL )
					drv_ioctl( FileNet, NET_RECV_PUT, &p_rxd );
			}while(p_rxd != NULL);


			drv_rmd(FileNet);

			cdg_error.ask = TPO_OK;
	        msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
		
   		}
		break;


					
      default:
      {
       cdg_error.cmd = ERROR_CMD;
       cdg_error.ask = TPO_ERR;
       msg_send(msg_desc->from, &cdg_error, sizeof(kdg_cmd_ask));  
      }


	}
  }

msg_close();
prc_exit();
while(1);
}

#ifdef TPO7
#ifdef CHIP_6457
extern uint32 read_res_fifo;

int Read_Res_Fifo(void* arg)
{

uint32 pack1[30];
uint32 pack2[30];
uint32 *chnl;
uint16 res=0;


while(1)
{
	if(read_res_fifo)
	{
	res = FIFO_outIsReady();
		switch(res)
		{
			case 0:
			prc_yield();
			break;

			case 1:
			while(1);
			break;

			default:
			{
			 
//!!!!?????????			res = FIFO_ReadPacket( pack1, pack2, chnl, 0);
			while(1);
			}
		}
	
	
	
	}
	else
	prc_yield();
}

}
#endif
#endif