#include <os_syscall.h>
//#include <drv_dbgout.h>
#include <rts.h>
#include "drv_gpio.h"
#include "sialp.h"
#include "tpo.h"



#ifdef TPO5
	#include "net_struct.h"
	#include "drv_eth6412.h"
#endif

#ifdef TPO7
     		#include "net_struct.h"
	     	#include "drv_eth6457.h" 
            //#include <drv_dp83820.h>  //такого уже нет видимо старые платы
#endif


#ifdef TPO6
	    	#include "net_struct.h"
	    	#include "drv_eth6457.h" 
	       //#include <drv_dp83820.h>  //такого уже нет видимо старые платы
#endif


//Из Глубин Сознания Пашки
extern uint32 Send_Recive_Packet(uint32 FileNet, void* Pack_wr, void* Pack_rd, uint32 len);


#define EMIFA_GLBCONT        (*(volatile uint32*)0x01800000) 
#define EMIFA_CESEC0        (*(volatile uint32*)0x01800048) 
#define EMIFA_CECTL0        (*(volatile uint32*)0x01800008) 

char* tip[] = {"СИ ", "АЛП"};
struct kdg_sialp kdg = {0,0,10,0,0,0,};



/**************************************************************************************************
Syntax:    void Test_sialp() 		
Return Value:	
***************************************************************************************************/
void Test_sialp()
{

	uint32		msg_from;
	//kdg_cmd		to_iface;
	kdg_cmd_ask	cdg_error;
	s_message*  msg_desc;
	kdg_sialp	par;
	//int32 error;

  while(true)
  {
	if(msg_recv( &msg_desc, SEM_INFINITY) != OSE_OK)
		return;

    if(msg_desc == NULL) continue;
    if(msg_desc->length !=sizeof(kdg_sialp))
    {
      cdg_error.cmd = ERROR_CMD;
      cdg_error.ask = TPO_ERR;
      msg_send(msg_desc->from, &cdg_error, sizeof(kdg_cmd_ask));  
      msg_free(msg_desc);      
      continue;
    }

    msg_from = msg_desc->from;
	memcpy(&par, msg_desc->data, msg_desc->length);
    msg_free(msg_desc);      

	if(par.tiptest==TIP_SI) //Тесты СИ:
	{
	    switch (par.kodtest)
	    {

	      case ETHERNET:
		  {
			cdg_error.cmd = START_SIALP;
			cdg_error.ask = TPO_OK;
			msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
			si_eth(par.time_ms, par.val_1);	//start stop trancemiter

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
	else
	{
	 if(par.tiptest==TIP_ALP)	//Тесты АЛП:
	 {
	    switch (par.kodtest)
	    {
	      case ETHERNET:
		  {
			cdg_error.cmd = START_SIALP;
			cdg_error.ask = TPO_OK;
			msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
			sleep_s(1);
			//alp_to_plis(par.val_1);
			#ifdef CHIP_6457
			alp_eth_6457(10, par.val_1);	//start stop trancemiter
			#else
			alp_eth_6412(10, par.val_1);
			#endif
		  }
	      break;
          //
	      case SP_PLIS:
		  {
			cdg_error.cmd = START_SIALP;
			cdg_error.ask = TPO_OK;
			msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
			sleep_s(1);
			#ifdef CHIP_6457
			alp_to_plis_6457(par.val_1);
			#else
			alp_to_plis_6412(par.val_1);
			#endif
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
	 else
	 {
       cdg_error.cmd = ERROR_CMD;
       cdg_error.ask = TPO_ERR;
       msg_send(msg_desc->from, &cdg_error, sizeof(kdg_cmd_ask));  
     }
	}
  }
}



/**************************************************************************************************
Syntax	    :    void si_eth(int delay, uint8 num0) 		
Return Value:Start stop trancemiter	
***************************************************************************************************/
void si_eth(int delay, uint8 num0)	
{


	/*
	net_config cfg;
	cfg.mac[0]=0x33;
	cfg.mac[1]=0x33;
	cfg.mac[2]=0x33;
	cfg.mac[3]=0x33;
	cfg.mac[4]=0x33;
	cfg.mac[5]=0x33;
	cfg.flags=0;
	cfg.ip4=0x01234567;
	cfg.mask4=0x12345678;
	cfg.gateway4=0x23456789;
	cfg.mtu=1524;
	*/


	int32 error;
	uint32 file_eth;
	uint32 reg;
	uint64 CurTime;

	dev_reg phy;
	phy.device = PHY_RW_REG;
	phy.reg = 0x10;


	//error = drv_eth6412_plug ( "/dev/net/eth0", cfg, 4, 4 );
  	  file_eth = drv_mkd("/dev/net/eth0");

	#ifdef TPO5   //Start TPO 5	
		if(num0)
		 while(1);

		error =	drv_ioctl(file_eth, NET_READ_REG, &phy);
		if(error)
		    asm( " nop" );

		reg = phy.value;
		//while (!kb_hit())

		while (1)
		{
			phy.value=reg;//вкл
			error =	drv_ioctl(file_eth, NET_WRITE_REG, &phy);
			if(error)
			    asm( " nop" );
			CurTime = time_m() + delay*1000;
				while (time_m() < CurTime);
			phy.value=reg|0x2000;//выкл
			error =	drv_ioctl(file_eth, NET_WRITE_REG, &phy);
			if(error)
			    asm( " nop" );
			CurTime = time_m() + delay*1000;
			while (time_m() < CurTime);
		}
	#else    //else TPO 5

		uint8 buf[1400];
		memset(buf, num0, sizeof(buf));
		net_descriptor* p_txd = NULL;
		//net_descriptor* p_rxd = NULL;

		while(1)
		{

			do
			  drv_ioctl( file_eth, NET_SEND_GET, &p_txd ); 	//готовим к отправке
			while(p_txd == NULL);

			  memcpy( p_txd->data, buf, sizeof(buf) );
			  p_txd->length = sizeof(buf);

			  drv_ioctl( file_eth, NET_SEND_PUT, &p_txd ); 	//отправляем
			  sleep_m(20);
		}
	#endif

}


/**************************************************************************************************
Syntax	    :    void si_stop_tx(int delay)		
Return Value:Start stop trancemiter	
***************************************************************************************************/
void si_stop_tx(int delay)	
{
	int32 error;
	uint32 file_eth;
	uint32 reg;
	dev_reg phy;

	phy.device = PHY_RW_REG;
	phy.reg = 0x10;

	file_eth = drv_mkd("/dev/net/eth0");

	error =	drv_ioctl(file_eth, NET_READ_REG, &phy);
	if(error)
	    asm( " nop" );
	reg = phy.value;

	//while (!kb_hit())
	phy.value=reg|0x2000;//выкл
	error =	drv_ioctl(file_eth, NET_WRITE_REG, &phy);
	if(error)
	    asm( " nop" );

}





#ifdef CHIP_6457

	#define GPIO_DIR            (*(volatile uint32*)0x02b00010) // GPIO Direction Register
	#define GPIO_OUT_DATA       (*(volatile uint32*)0x02b00014) // GPIO Output Data register
	#define GPIO_SET_DATA       (*(volatile uint32*)0x02b00018) // GPIO Set Data register
	#define GPIO_CLR_DATA       (*(volatile uint32*)0x02b0001c) // GPIO Clear Data Register
	#define GPIO_IN_DATA        (*(volatile uint32*)0x02b00020) // GPIO Input Data Register


	/**************************************************************************************************
	Syntax	    :    void alp_sinhrosig()	
	Return Value:
	***************************************************************************************************/
	void alp_sinhrosig()
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
#endif //end CHIP_6457

#ifdef CHIP_6412  ///////////////////////////////////////////////////////////////////////////////////////

	#define		EN				(*(uint32 *)0x01B00000)
	#define		DIR				(*(uint32 *)0x01B00004)
	#define		VAL				(*(uint32 *)0x01B00008)

	//-------------------------------------------------------------
	//------------------------АЛП
	//-------------------------------------------------------------


	/**************************************************************************************************
	Syntax	    :    void alp_sinhrosig()	
	Return Value:
	***************************************************************************************************/
	void alp_sinhrosig()
	{
		uint32 res = EN;

		EN = res | 0x8;
		res = DIR;
		DIR = res | 0x8;
		res = VAL;
		VAL = res | 0x8;

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
		VAL = res & (~0x8);
	}


	/**************************************************************************************************
	Syntax	    :    void alp_eth_6412(int delay, uint8 num0)	
	Return Value:
	***************************************************************************************************/
	void alp_eth_6412(int delay, uint8 num0)
	{
		int32 error;
		uint32 file_eth;

		uint32 reg;
		uint64 CurTime;

		dev_reg phy;

		phy.device = PHY_RW_REG;
		phy.reg = 0x10;
		uint8 buf[1400];
		uint8 buf_rd[100];

		memset(buf, 0xFF,sizeof(buf));
		memset(buf, 0x00, 200);

		//error = drv_eth6412_plug ( "/dev/net/eth0", cfg, 4, 4 );

		file_eth = drv_mkd("/dev/net/eth0");
		uint32 r = prc_disable();
		uint32 u = 333;

		while(1)
		{
			/*
			u = 800;
			while(u--)
			{
			asm ( " nop " );
			asm ( " nop " );
			asm ( " nop " );
			asm ( " nop " );
			asm ( " nop " );
			asm ( " nop " );
			asm ( " nop " );
			asm ( " nop " );
			}

			alp_sinhrosig();

			u = 400;
			while(u--)
			{
			asm ( " nop " );
			asm ( " nop " );
			asm ( " nop " );
			asm ( " nop " );
			asm ( " nop " );
			asm ( " nop " );
			asm ( " nop " );
			asm ( " nop " );
			}
			*/
			error = Send_Recive_Packet(file_eth, buf, buf_rd, sizeof(buf));
		} //end while
	}


	/**************************************************************************************************
	Syntax	    :    void alp_to_plis_6412(uint8 num0)	
	Return Value:    синхра на RN46, крайняя, ближе к ЦП - 
					 данные на RN60, любая 
	***************************************************************************************************/
	void alp_to_plis_6412(uint8 num0)
	{

		uint32* addr= (uint32*)0x8000FFFC;
		uint32* addr1= (uint32*)0x8001FFFF;
		uint32 det = 0;
		uint32		b = 1;


		det = EMIFA_CECTL0;
		EMIFA_CECTL0 = (det & 0xFFFFFF0F) | (0xFFC00020);
		det = EMIFA_CESEC0;
		EMIFA_CESEC0 = det | (b << 6);

		uint32 buf[100];
		memset(&det, num0, 4);
		memset(buf, 0xff, sizeof(buf));
		buf[99]=det; 
		//det = num0 | (det<<32);

		uint32 u = 333;
		uint32 r = prc_disable();

		while(true)
		{
		u = 700;
			while(u--)
			{
			asm ( " nop " );
			asm ( " nop " );
			asm ( " nop " );
			asm ( " nop " );
			asm ( " nop " );
			asm ( " nop " );
			asm ( " nop " );
			asm ( " nop " );
			} //end while u
		//u = 400;
		*addr = 0xFFFFFFFF;
		*addr1 = 0xFFFFFFFF;
		*addr1 = 0xFFFFFFFF;
		*addr1 = 0xFFFFFFFF;
		*addr1 = 0xFFFFFFFF;
		*addr1 = 0xFFFFFFFF;
		*addr1 = 0xFFFFFFFF;
		*addr1 = 0xFFFFFFFF;
		*addr1 = 0xFFFFFFFF;
		*addr1 = 0xFFFFFFFF;
		*addr1 = 0xFFFFFFFF;
		*addr1 = 0xFFFFFFFF;
		*addr1 = 0xFFFFFFFF;
		*addr1 = 0xFFFFFFFF;
		*addr1 = 0xFFFFFFFF;
		*addr1 = 0xFFFFFFFF;
		*addr1 = 0xFFFFFFFF;
		*addr1 = det;
		//while(u--);
		//*addr1 = det;
		//memcpy(addr, buf, 400);
		} //end while

	}


#else  //NON_CHIP_6412  _and 6457  vidimo chip 6416

	//uint32* REGe = (uint32*)0x01800000;
	/**************************************************************************************************
	Syntax	    :    void alp_to_plis_6457(uint8 num0)
	Return Value:    
	***************************************************************************************************/
	void alp_to_plis_6457(uint8 num0)
	{

		uint32 res = GPIO_DIR;
		GPIO_DIR = res & 0xFF1F;

		uint64* addr= (uint64*)0xC000FFF0;
		uint64* addr1= (uint64*)0xC000FFFF;
		uint64 det = 0;
		memset(&det, num0, 8);
		//det = num0 | (det<<32);

		uint32 u = 333;
		uint32 r = prc_disable();

		while(true)
		{
		u = 800;
			while(u--)
			{
				asm ( " nop " );
				asm ( " nop " );
				asm ( " nop " );
				asm ( " nop " );
				asm ( " nop " );
				asm ( " nop " );
				asm ( " nop " );
				asm ( " nop " );
			}
		u = 20;
		*addr = 0xFFFFFFFFFFFFFFFF;


			while(u--)
			{
			*addr1 = 0xFFFFFFFFFFFFFFFF;
			*addr1 = 0xFFFFFFFFFFFFFFFF;
			*addr1 = 0xFFFFFFFFFFFFFFFF;
			*addr1 = 0xFFFFFFFFFFFFFFFF;
			*addr1 = 0xFFFFFFFFFFFFFFFF;
			*addr1 = 0xFFFFFFFFFFFFFFFF;
			*addr1 = 0xFFFFFFFFFFFFFFFF;
			*addr1 = 0xFFFFFFFFFFFFFFFF;
			*addr1 = 0xFFFFFFFFFFFFFFFF;
			*addr1 = 0xFFFFFFFFFFFFFFFF;
			*addr1 = 0xFFFFFFFFFFFFFFFF;
			*addr1 = 0xFFFFFFFFFFFFFFFF;
			*addr1 = 0xFFFFFFFFFFFFFFFF;
			*addr1 = 0xFFFFFFFFFFFFFFFF;
			*addr1 = 0xFFFFFFFFFFFFFFFF;
			*addr1 = 0xFFFFFFFFFFFFFFFF;
			*addr1 = 0xFFFFFFFFFFFFFFFF;
			*addr1 = 0xFFFFFFFFFFFFFFFF;
			*addr1 = 0xFFFFFFFFFFFFFFFF;
			*addr1 = 0xFFFFFFFFFFFFFFFF;
			*addr1 = 0xFFFFFFFFFFFFFFFF;
			}
	*addr1 = det;
		}//end while true

	}//end function



	/**************************************************************************************************
	Syntax	    :    void alp_eth_6457(int delay, uint8 num0)
	Return Value:    
	***************************************************************************************************/
	void alp_eth_6457(int delay, uint8 num0)
	{

		uint32 res = 0;
		int error = 0;
		uint32 u = 333;


		uint32* regtx = (uint32*)0x02C40030;
		uint32  regdat=0;

		regdat = *regtx;
		regdat = regdat & 0xFFFFFFFE;


		while(1)
		{

			*regtx = regdat;


			u = 800;
			while(u--)
			{
				asm ( " nop " );
				asm ( " nop " );
				asm ( " nop " );
				asm ( " nop " );
				asm ( " nop " );
				asm ( " nop " );
				asm ( " nop " );
				asm ( " nop " );
			}

			alp_sinhrosig();

			u = 500;
			while(u--)
			{
				asm ( " nop " );
				asm ( " nop " );
				asm ( " nop " );
				asm ( " nop " );
				asm ( " nop " );
				asm ( " nop " );
			}

			if(num0)
			*regtx = regdat | 1;

			u = 50;

			while(u--)
			{
				asm ( " nop " );
			}

	    } //end while(1)


		/*
		//uint32* reg_gpio = (uint32*)0x01B00008;
		//uint32 l = 0;
		uint32 id1 = 0;
		uint32 id2 = 0;
		bool link = false;

		uint32 u = 333;


		//uint8 buf_big_wr[LEN_BUF1_FOR_TEST_SK];	//1514
		uint8 buf_small_wr[LEN_BUF2_FOR_TEST_SK];	//64
		//uint8 buf_big_rd[LEN_BUF1_FOR_TEST_SK];	//1514
		uint8 buf_small_rd[LEN_BUF2_FOR_TEST_SK];	//64

		//memset(buf_big_wr, num0, LEN_BUF1_FOR_TEST_SK);
		memset(buf_small_wr, num0, LEN_BUF2_FOR_TEST_SK);
		//memset(buf_big_rd, 0, LEN_BUF1_FOR_TEST_SK);
		memset(buf_small_rd, 0, LEN_BUF2_FOR_TEST_SK);

		uint32 FileNet = drv_mkd("/dev/net/eth0");
		uint32 FileNet1 = 0;

		sleep_m(160);

		error = drv_ioctl(FileNet, NET_LINK, &link);

		while(1)
		{
		u = 800;
		while(u--)
		{
		asm ( " nop " );
		asm ( " nop " );
		asm ( " nop " );
		asm ( " nop " );
		asm ( " nop " );
		asm ( " nop " );
		asm ( " nop " );
		asm ( " nop " );
		}

		alp_sinhrosig();

		u = 500;
		while(u--)
		{
		asm ( " nop " );
		asm ( " nop " );
		asm ( " nop " );
		asm ( " nop " );
		asm ( " nop " );
		asm ( " nop " );
		}


		if(link)
		{
		FileNet1=FileNet;
		error = Send_Recive_Packet(FileNet1, buf_small_wr, buf_small_rd, LEN_BUF2_FOR_TEST_SK);
		//	if((error == TPO_ERR) | (memcmp(buf_big_wr, buf_big_rd, LEN_BUF1_FOR_TEST_SK)))
		//		res|=ERR_LOOP_PHY;

		}

		}

		drv_rmd(FileNet);
		*/

	} //////////End function

#endif



/*
void alp_to_plis_6457(uint8 num0)
{

uint32 res = GPIO_DIR;
GPIO_DIR = res & 0xFF1F;


uint64* addr= (uint64*)0xC000FFF0;
uint64* addr1= (uint64*)0xC000FFFF;
uint64 det = 0;
memset(&det, num0, 8);
//det = num0 | (det<<32);

uint32 u = 333;


uint32 r = prc_disable();


while(true)
{
u = 800;
while(u--)
{
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
}
u = 20;

GPIO_SET_DATA = 0xE0;
*addr = 0xFFFFFFFFFFFFFFFF;


while(u--)
{
*addr1 = 0xFFFFFFFFFFFFFFFF;
*addr1 = 0xFFFFFFFFFFFFFFFF;
*addr1 = 0xFFFFFFFFFFFFFFFF;
*addr1 = 0xFFFFFFFFFFFFFFFF;
*addr1 = 0xFFFFFFFFFFFFFFFF;
*addr1 = 0xFFFFFFFFFFFFFFFF;
*addr1 = 0xFFFFFFFFFFFFFFFF;
*addr1 = 0xFFFFFFFFFFFFFFFF;
*addr1 = 0xFFFFFFFFFFFFFFFF;
*addr1 = 0xFFFFFFFFFFFFFFFF;
*addr1 = 0xFFFFFFFFFFFFFFFF;
*addr1 = 0xFFFFFFFFFFFFFFFF;
*addr1 = 0xFFFFFFFFFFFFFFFF;
*addr1 = 0xFFFFFFFFFFFFFFFF;
*addr1 = 0xFFFFFFFFFFFFFFFF;
*addr1 = 0xFFFFFFFFFFFFFFFF;
*addr1 = 0xFFFFFFFFFFFFFFFF;
*addr1 = 0xFFFFFFFFFFFFFFFF;
*addr1 = 0xFFFFFFFFFFFFFFFF;
*addr1 = 0xFFFFFFFFFFFFFFFF;
*addr1 = 0xFFFFFFFFFFFFFFFF;
}
*addr1 = 0xFFFFFFFFFFFFFFFF;





u = 800;
while(u--)
{
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
asm ( " nop " );
}
u = 20;

GPIO_CLR_DATA = 0xE0;
*addr = 0xFFFFFFFFFFFFFFFF;


while(u--)
{
*addr1 = 0xFFFFFFFFFFFFFFFF;
*addr1 = 0xFFFFFFFFFFFFFFFF;
*addr1 = 0xFFFFFFFFFFFFFFFF;
*addr1 = 0xFFFFFFFFFFFFFFFF;
*addr1 = 0xFFFFFFFFFFFFFFFF;
*addr1 = 0xFFFFFFFFFFFFFFFF;
*addr1 = 0xFFFFFFFFFFFFFFFF;
*addr1 = 0xFFFFFFFFFFFFFFFF;
*addr1 = 0xFFFFFFFFFFFFFFFF;
*addr1 = 0xFFFFFFFFFFFFFFFF;
*addr1 = 0xFFFFFFFFFFFFFFFF;
*addr1 = 0xFFFFFFFFFFFFFFFF;
*addr1 = 0xFFFFFFFFFFFFFFFF;
*addr1 = 0xFFFFFFFFFFFFFFFF;
*addr1 = 0xFFFFFFFFFFFFFFFF;
*addr1 = 0xFFFFFFFFFFFFFFFF;
*addr1 = 0xFFFFFFFFFFFFFFFF;
*addr1 = 0xFFFFFFFFFFFFFFFF;
*addr1 = 0xFFFFFFFFFFFFFFFF;
*addr1 = 0xFFFFFFFFFFFFFFFF;
*addr1 = 0xFFFFFFFFFFFFFFFF;
}
*addr1 = det;

}

}
*/









