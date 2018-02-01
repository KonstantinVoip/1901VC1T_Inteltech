#include <os_syscall.h>
#include <drv_dbgout.h>
#include <rts.h>


#include "sialp.h"
#include "tpo.h"

#include "drv_gpio.h"

#ifdef TPO5
#include "crypter_15.h"
#endif

#ifdef TPO6
#include "crypter_15.h"
#endif


#ifdef TPO7
#include "crypter_17.h"
#endif

#ifdef TPO_M711B
#include <drv_netfs.h>
#endif


#define		EN				(*(uint32 *)0x01B00000)
#define		DIR				(*(uint32 *)0x01B00004)
#define		VAL				(*(uint32 *)0x01B00008)
#define 	GPIO_PROG       ( 1 << 15 )


void si_ext_ram(int RW, uint16 num0, uint16 num1, int delay);
void si_int_ram(int RW, uint32 num0, uint32 num1, int delay);
void si_load_key(uint32 num0, uint32 num1, int delay);
void si_plis(uint32 num0, uint32 num1, int delay);
void si_crypto(uint32 num0, uint32 num1, int delay);

#ifdef TPO_M711B
void si_sata(uint32 num0, uint32 num1, int delay);
void si_usb3(uint32 num0, uint32 num1, int delay);
#endif

void alp_ext_ram(int RW, uint16 num0, uint16 num1, int delay);
void alp_int_ram(int RW, uint32 num0, uint32 num1, int delay);
void alp_plis(int RW, uint32 num0, uint32 num1, int delay);
void alp_load_key(uint32 num0, uint32 num1, int delay);
void alp_AbEncrypt(uint32 num0, uint32 num1, int delay);



char* tip[] = {"СИ ", "АЛП"};

struct kdg_sialp kdg = {0,0,10,0,0,0,};

uint16* ptr_crypt = (uint16*)0xA0000000;//Начальный адресс файла ПЛИС в ОЗУ

extern uint32  msg_pid_iface;

void delayyy()
{
uint32 y = 10000000;
while(y--);
}

void Test_sialp()
{

	uint32		msg_from;
//	kdg_cmd		to_iface;
	kdg_cmd_ask	cdg_error;
	s_message*  msg_desc;
	kdg_sialp	par;



  while(true)
  {
	if(msg_recv( &msg_desc, MSG_WAIT_5) != OSE_OK)

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
	      case CP_EXT_RAM:
		  {
			uint16 num0 = (par.val_1<<8)|par.val_1;
			uint16 num1 = (par.val_2<<8)|par.val_2;

			cdg_error.cmd = START_SIALP;
			cdg_error.ask = TPO_OK;
			msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
			delayyy();
			si_ext_ram(0, num0, num1, par.time_ms);	

		  }
	      break;

	      case CP_INT_RAM1:
		  {

			uint32 num0;
			uint32 num1;

			memset(&num0, par.val_1, sizeof(num0));
			memset(&num1, par.val_2, sizeof(num1));

			cdg_error.cmd = START_SIALP;
			cdg_error.ask = TPO_OK;
			msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
			delayyy();
			si_int_ram(0, num0, num1, par.time_ms);	
			
		  }
	      break;

		  case CP_INT_RAM2:
		  {

			uint32 num0;
			uint32 num1;

			memset(&num0, par.val_1, sizeof(num0));
			memset(&num1, par.val_2, sizeof(num1));

			cdg_error.cmd = START_SIALP;
			cdg_error.ask = TPO_OK;
			msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
			delayyy();
			si_int_ram(1, num0, num1, par.time_ms);	
			
		  }
	      break;

		  case CP_INT_RAM3:
		  {

			uint32 num0;
			uint32 num1;

			memset(&num0, par.val_1, sizeof(num0));
			memset(&num1, par.val_2, sizeof(num1));

			cdg_error.cmd = START_SIALP;
			cdg_error.ask = TPO_OK;
			msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
			delayyy();
			si_int_ram(2, num0, num1, par.time_ms);	
			
		  }
	      break;

	      case CP_PLIS:
		  {
			uint32 num0;
			uint32 num1;

			memset(&num0, par.val_1, sizeof(num0));
			memset(&num1, par.val_2, sizeof(num1));

			cdg_error.cmd = START_SIALP;
			cdg_error.ask = TPO_OK;
			msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
			delayyy();
			si_load_key(num0, num1, par.time_ms);

		  }
	      break;

	      case CRYPTO:
		  {
			uint32 num0;
			uint32 num1;

			memset(&num0, par.val_1, sizeof(num0));
			memset(&num1, par.val_2, sizeof(num1));

			cdg_error.cmd = START_SIALP;
			cdg_error.ask = TPO_OK;
			msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
//			delayyy();
//			si_crypto(num0, num1, par.time_ms);
		  }
	      break;

	      case PLIS_SI:
		  {
			uint32 num0;
			uint32 num1;

			memset(&num0, par.val_1, sizeof(num0));
			memset(&num1, par.val_2, sizeof(num1));

			cdg_error.cmd = START_SIALP;
			cdg_error.ask = TPO_OK;
			msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
			delayyy();
			si_plis(num0, num1, par.time_ms);
		  }
	      break;

#ifdef TPO_M711B
	      case SATA_SI:
		  {
			uint32 num0;
			uint32 num1;

			memset(&num0, par.val_1, sizeof(num0));
			memset(&num1, par.val_2, sizeof(num1));

			cdg_error.cmd = START_SIALP;
			cdg_error.ask = TPO_OK;
			msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
			delayyy();
			si_sata(num0, num1, par.time_ms);
		  }
	      break;

	      case USB3_SI:
		  {
			uint32 num0;
			uint32 num1;

			memset(&num0, par.val_1, sizeof(num0));
			memset(&num1, par.val_2, sizeof(num1));

			cdg_error.cmd = START_SIALP;
			cdg_error.ask = TPO_OK;
			msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
			delayyy();
			si_usb3(num0, num1, par.time_ms);
		  }
	      break;
#endif

/*
	      case ETHERNET:
		  {
			cdg_error.cmd = START_SIALP;
			cdg_error.ask = ASK_OK;
			msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
		  }
	      break;
*/
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
	      case CP_EXT_RAM:
		  {
			uint16 num0 = (par.val_1<<8)|par.val_1;
			uint16 num1 = (par.val_2<<8)|par.val_2;

			cdg_error.cmd = START_SIALP;
			cdg_error.ask = TPO_OK;
			msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));

			alp_ext_ram(0, num0, num1, par.time_ms);	

		  }
	      break;

	      case CP_INT_RAM1:
		  {

			uint32 num0;
			uint32 num1;

			memset(&num0, 0, sizeof(num0));
			memset(&num1, 0x00, sizeof(num1));

			cdg_error.cmd = START_SIALP;
			cdg_error.ask = TPO_OK;
			msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
			delayyy();
			alp_int_ram(1, num0, num1, par.time_ms);	
			
		  }
	      break;

	      case CP_INT_RAM2:
		  {

			uint32 num0;
			uint32 num1;

			memset(&num0, 0, sizeof(num0));
			memset(&num1, 0x00, sizeof(num1));

			cdg_error.cmd = START_SIALP;
			cdg_error.ask = TPO_OK;
			msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
			delayyy();
			alp_int_ram(2, num0, num1, par.time_ms);	
			
		  }
	      break;

	      case CP_INT_RAM3:
		  {

			uint32 num0;
			uint32 num1;

			if(par.val_1)
			memset(&num0, par.val_1, sizeof(num0));
			else
			memset(&num0, 0x00, sizeof(num0));

			memset(&num1, 0x00, sizeof(num1));

			cdg_error.cmd = START_SIALP;
			cdg_error.ask = TPO_OK;
			msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
			delayyy();
			alp_int_ram(3, num0, num1, par.time_ms);	
			
		  }
	      break;

	      case CP_PLIS:
		  {
			uint32 num0;
			uint32 num1;

			memset(&num0, par.val_1, sizeof(num0));
			memset(&num1, par.val_2, sizeof(num1));

			cdg_error.cmd = START_SIALP;
			cdg_error.ask = TPO_OK;
			msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
			delayyy();
			alp_load_key(num0, num1, par.time_ms);

		  }
	      break;
	      case CRYPTO:
		  {
			uint32 num0;
			uint32 num1;

			memset(&num0, par.val_1, sizeof(num0));
			memset(&num1, par.val_2, sizeof(num1));
			cdg_error.cmd = START_SIALP;
			cdg_error.ask = TPO_OK;
			msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
			delayyy();
			alp_AbEncrypt(num0, num1, par.time_ms);


		  }
	      break;


	      case SP_PLIS:	//stop plis
		  {

			cdg_error.cmd = START_SIALP;
			cdg_error.ask = TPO_OK;

			EN |= GPIO_PROG;
			DIR |= GPIO_PROG;
			VAL = 0;
			delayyy();
			VAL |= GPIO_PROG;



			msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
			delayyy();
			delayyy();

			uint32 r = prc_disable();
		  }
	      break;

		  case PLIS_SI:
		  {
			uint32 num0;
			uint32 num1;

			memset(&num0, par.val_1, sizeof(num0));
			memset(&num1, par.val_2, sizeof(num1));

			cdg_error.cmd = START_SIALP;
			cdg_error.ask = TPO_OK;
			msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
			delayyy();
			si_plis(num0, 0, par.time_ms);
		  }
	      break;

/*
	      case ETHERNET:
		  {
			cdg_error.cmd = START_SIALP;
			cdg_error.ask = TPO_OK;
			msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));
		  }
	      break;
*/
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






void si_ext_ram(int RW, uint16 num0, uint16 num1, int delay)	
{

uint16* addr = (uint16*)0x68000000;	//NVRAM
uint16* addr1 = (uint16*)0x68000004;	//NVRAM
uint64 CurTime;
uint64 Time = 10000000;
uint16 ch;

uint32 r = prc_disable();


if(RW==0)	//read
{

	while(true)
	{
	*addr = num0;
	*addr1 = num1;
	CurTime=Time;	
		while(CurTime--)
		{
		ch = *addr;
		ch = *addr1;
		}

	*addr = num1;
	CurTime=Time;	
		while(CurTime--)
		{
		ch = *addr;
		ch = *addr1;
		}

	}
}
else		//write
{

	while(true)
	{
	CurTime=Time;	
		while(CurTime--)
		{
		*addr  = num0;
		*addr1 = num1;
		}

	CurTime=Time;	
		while(CurTime--)
		{
		*addr  = num1;
		*addr1 = num1;
		}

	}


}

}



extern "C" {
    extern void asm_si_acc_ram(void);
    extern void asm_si_ram_acc_ext(void);  
    extern void asm_si_ram_acc_int1(void);  
    extern void asm_si_ram_acc_int2(void);  

    int number;
    uint32 *test_addr1;
    uint32 *test_addr2;
    uint32 *test_addr3;
    uint32 *test_addr4;

}


void si_int_ram(int RW, uint32 num0, uint32 num1, int delay)	
{

uint64 CurTime;
uint64 Time = 35000000;
//uint16 ch;


EN = 0x4000;
DIR = 0x4000;


test_addr1 = (uint32 *) (0x00000000+0x30);
test_addr2 = (uint32 *) (0x00000004+0x30);
test_addr3 = (uint32 *) (0x00000008+0x30);
test_addr4 = (uint32 *) (0x0000000C+0x30);

uint32 r = prc_disable();

	*test_addr1 =num0;
	*test_addr2 =num0;
	*test_addr3 =num1;
	*test_addr4 =num1;

	if(RW == 0)
	{
		while(1)
		{
		VAL = 0x4000;
		asm_si_ram_acc_int1();
		VAL = 0;
		asm_si_ram_acc_int2();
		}
	}

	if(RW == 1)
	{
		while(1)
		{
		VAL = 0;
		asm_si_ram_acc_int1();
		VAL = 0;
		asm_si_ram_acc_int2();
		}
	}

	if(RW == 2)
	{
	while(true)
	{
	CurTime=Time;	

	VAL = 0x4000;
		while(CurTime--)
		{
		VAL = 0x4000;
		asm_si_ram_acc_int1();
		VAL = 0x4000;
		asm_si_ram_acc_int2();
		}
	VAL = 0;

	CurTime=Time*5;	
		while(CurTime--);
	}
	}
}


char test_bp[]= 
{
0x41, 0x34, 0xA7, 0x2E, 0x4A, 0xA3, 0x49, 0xD9, 
0xC0, 0xD2, 0x3C, 0x34, 0xAF, 0xB6, 0xA2, 0x2F, 
0xDF, 0xA1, 0x96, 0x05, 0xF5, 0x59, 0xD1, 0x18, 
0x88, 0x09, 0x1D, 0x1A, 0xCE, 0xC0, 0xED, 0xBA, 
0x0B, 0x60, 0x7A, 0x51, 0x09, 0x8C, 0x05, 0x6C, 
0x5A, 0xEF, 0xBE, 0x42, 0xB2, 0x2F, 0xC4, 0x55, 
0xE7, 0x4D, 0x82, 0xBC, 0x66, 0x61, 0x6B, 0x4B, 
0xF6, 0xB8, 0x40, 0xEB, 0xD8, 0xD7, 0x9C, 0xAE, 

0x41, 0x34, 0xA7, 0x2E, 0x4A, 0xA3, 0x49, 0xD9, 
0xC0, 0xD2, 0x3C, 0x34, 0xAF, 0xB6, 0xA2, 0x2F, 
0xDF, 0xA1, 0x96, 0x05, 0xF5, 0x59, 0xD1, 0x18, 
0x88, 0x09, 0x1D, 0x1A, 0xCE, 0xC0, 0xED, 0xBA, 
0x0B, 0x60, 0x7A, 0x51, 0x09, 0x8C, 0x05, 0x6C, 
0x5A, 0xEF, 0xBE, 0x42, 0xB2, 0x2F, 0xC4, 0x55, 
0xE7, 0x4D, 0x82, 0xBC, 0x66, 0x61, 0x6B, 0x4B, 
0xF6, 0xB8, 0x40, 0xEB, 0xD8, 0xD7, 0x9C, 0xAE, 

};

void WriteDARAM_si(uint16 addr,void* buf,uint16 len)
{
//memcpy((char*)sh_mem_write[n_comm]+addr,buf,len);

uint16 l=(len+3)>>2;
uint32* s=(uint32*)buf;
uint32* d=(uint32*)(0xA0000000+addr);
while(l--)
	_amem8(d++)=_mem8(s++);

}



uint32* REGe = (uint32*)0x01800000;

void si_load_key(uint32 num0, uint32 num1, int delay)
{

uint64 CurTime;

#ifdef TPO5
uint32 test_key0[2000];
//uint32 test_key1[8];
#else 
uint64 test_key0[4000];
//uint64 test_key1[4];
//uint8* n0 = (uint8*)&num0;
//uint8* n1 = (uint8*)&num1;
#endif

uint32* chan = (uint32*)0x01940000;

if(!(*chan & 0x8))
while(1);

AbLoadBP(test_bp);

uint32 u;
u = *REGe;			// Меняю делиель на EMIF CLKOUT2 - так не дергается сигнал относительно синхры
*REGe = u & 0xFFF3FFFF;


uint32 r = prc_disable();

#ifdef TPO5
uint32* adr= (uint32*)0xA0000000;
#else 
uint64* adr= (uint64*)0xb0000000;
#endif

	while(true)
	{
	CurTime=15000;	
#ifdef TPO5
for(int y=0; y<2000; y=y+2)
{
test_key0[y]=num0;
test_key0[y+1]=num1;
}
//#endif
#else
for(int y=0; y<4000; y=y+2)
{
test_key0[y]=0xFFFFFFFFFFFFFFFF;
test_key0[y+1]=num0;
test_key0[y+1]=num0 | (test_key0[y+1]<<32);
}
#endif

		while(CurTime--)
		{
		WriteDARAM_si(0,test_key0,sizeof(test_key0));

		}

if(num1 == 0)
{
#ifdef TPO5
for(int y=0; y<2000; y++)
{
test_key0[y]=num1;
}
//#endif
#else 

for(int y=0; y<4000; y++)
{
test_key0[y]=0xFFFFFFFFFFFFFFFF;
}

#endif
	CurTime=15000;	
		while(CurTime--)
		{
		WriteDARAM_si(0,test_key0,sizeof(test_key0));
		}
}
	}
}

#define CRYPT_BASE              	0xA0000000

#define CRYPT_AB_BUSY          		0x00000004
#define CRYPT_AB_HAVE_DATA     		0x00000008


#define RG_STATUS_AB				(*(uint32*)(CRYPT_BASE+(0x52F<<2)))//Регистр состояния  АБ
#define RG_RESET_AB					(*(uint32*)(CRYPT_BASE+(0x525<<2)))//Регистр сброса АБ
#define RG_RST_BIT_AB				(*(uint32*)(CRYPT_BASE+(0x52A<<2)))//Регистр сброса бита готовности
                                	
#define RG_CODE_AB					(*(uint32*)(CRYPT_BASE+(0x526<<2)))//Регистр шифрования АБ
#define RG_DECODE_AB				(*(uint32*)(CRYPT_BASE+(0x527<<2)))//Регистр дешифрования АБ
#define RG_GAM_AB					(*(uint32*)(CRYPT_BASE+(0x528<<2)))//Регистр гаммирования АБ
#define RG_IMV_AB					(*(uint32*)(CRYPT_BASE+(0x529<<2)))//Регистр выработки имв 
                                	
#define RG_KEY_AB         			(*(uint32*)(CRYPT_BASE+(0x500<<2)))//Регистр ввода ключа




void si_cry()
{
uint64 CurTime;
uint32 LokTime;

uint32 Timet=65;
uint32 Timett=3600000;

//uint8 testbuf[500];
uint32 nn=0;

	while(RG_STATUS_AB&CRYPT_AB_BUSY);
	RG_RESET_AB = 1;		

CurTime=Timett;	
while(CurTime--)
{
	nn=0;
	RG_CODE_AB = 1;

	LokTime=Timet;
	while(LokTime--)
	{
	asm("nop");
	}
/*
		if(RG_STATUS_AB&CRYPT_AB_HAVE_DATA)
		testbuf[nn++]=1;
		else
		testbuf[nn++]=0;
*/
	RG_RST_BIT_AB = 1;		

}

}

void si_crypto(uint32 num0, uint32 num1, int delay)
{


uint32 test_key0[8];
uint32 test_key1[8];


memset(test_key0, num0, sizeof(test_key0));
memset(test_key1, num1, sizeof(test_key1));

AbLoadBP(test_bp);


uint32 r = prc_disable();

	while(1)
	{
	AbLoadKey(test_key0);
	si_cry();
	sleep_s( 6 );
//	AbLoadKey(test_key1);
//	si_cry();
//	sleep_s( 3*6 );

	}
}

#ifdef TPO5
#define PLIS_LENGTH         959128
#else
#define PLIS_LENGTH			3640576
#endif

void reload_plis_for_sialp()
{
#ifdef TPO5
uint32 d = drv_mkd( "/vfat/a/sv5_si.bin" );
#else
uint32 d = drv_mkd( "/vfat/a/sv6_si.bin" );
#endif

    if( d == RES_VOID )
     while(1);

    if( drv_open( d, DRV_RD ) != OSE_OK )
    {
      drv_rmd( d );
      while(1);
    }
    s_os_mem_block* block = mem_alloc( PLIS_LENGTH, 1 );
    if( block == NULL )
    {
      drv_rmd( d );
      while(1);
    }
    void* ptr = mem_ptr( block );
    int32 res = drv_read( d, ptr, PLIS_LENGTH );
    drv_rmd( d );
    if( res != PLIS_LENGTH )
    {
      mem_free( block );
      while(1);
    }
//while(1)
/*
    res = ipmp_dsp15_load_plis( ptr );
    mem_free( block );
    if( res != OSE_OK )
      while(1);
*/
  int32 r;
  uint32 dd;
  s_gpio_load_plis lplis;

  if( ( dd = drv_mkd( "/dev/gpio" ) ) == RES_VOID ) 
      while(1);

  lplis.data = ptr;
  lplis.size = PLIS_LENGTH;
  lplis.gpio_prog = 15;
  lplis.gpio_init = 12;
  lplis.gpio_clk = 14;
  lplis.gpio_dout = 13;
  lplis.gpio_done = 11;

//#ifdef TPO5
r = drv_ioctl( dd, GPIO_LOAD_PLIS, &lplis );
//#else
//r = drv_ioctl( dd, GPIO_LOAD_PLIS, ptr );
//#endif


  drv_rmd( dd );

  mem_free( block );

}


//extern CREGISTER volatile unsigned int CSR;       

void si_plis(uint32 num0, uint32 num1, int delay)
{


uint32* chan = (uint32*)0x01940000;

uint32 r = 0;



//CSR = CSR & 0xFFFFFFFE;


#ifdef TPO5
uint32* comand = (uint32*)0x90000000;
#else
uint32* comand = (uint32*)0xB0000000;
#endif

reload_plis_for_sialp();



//asm("cli");

if(!(*chan & 0x8))
{
r = int_disable();
while(1);
}

r = int_disable();

*comand = num0 & 0x000000FF;

while(1);
}


/*
	File or Dir name = "DiskName/subdir1/subdir2/file"
	DiskNames:
		"STORAGE:" - raid massive
		"FLASHDRIVE:" - usb flash drive
		"CDDVD:"	- cddvd
		"EEPROM.056:"	- eeprom memory on external board
		
	examples:
		"STORAGE:/TestFile.bin"
		"FLASHDRIVE:/subdir1/subdir2/TestFile.bin"
		"CDDVD:/dir"
*/


#ifdef TPO_M711B


#define FileBuffSize 32768
//#define FileBuffSize 1024
void si_sata(uint32 num0, uint32 num1, int delay)
{
//	uint32 sHandler = 0;
	uint32 sFileHandler = 0, dFileHandler = 0;
	FRESULT res = FR_NOT_ENOUGH_MEMORY;
	uint8 *buf = NULL;
//	uint8 buf[1024];
	uint16 Writed = 0;
	uint16 Num = 0;

		buf = (uint8*)malloc(FileBuffSize);
		if(!buf)
		{
			res = FR_NOT_ENOUGH_MEMORY;
		while(1);
		}


	TNetFSAPI *netfs = NULL;
	getNetFSAPI(&netfs);
	if(!netfs)
		while(1);

//	FRESULT (*runTest)(TBoard board, TTestType TestType, uint32 TestTimeS,
//						uint32 ActivePeriodMs, uint32 SilentPeriodMs);
/*
if(num0)
	res = netfs->runTest(board056, ttCDDVDSataFlood, 0x7FFFFFFF, 0xB00, 0xB00);
else
	res = netfs->runTest(board056, ttCDDVDSataFlood, 0x7FFFFFFF, 0x7FFFFFFF, 0x0);
*/
trewq:

//	NetFS_getDiskStatus,//(char *DiskName, TDiskStatus *DiskStatus);
	TDiskStatus stat;

	res =netfs->getDiskStatus("STORAGE:", &stat);
	res =netfs->getDiskStatus("CDDVD:", &stat);
	res =netfs->getDiskStatus("FLASHDRIVE:", &stat);


	res =  netfs->fopen(&sFileHandler, "STORAGE:/sitest00.bin", FA_READ);
	if(res != FR_OK)
		while(1);

Writed = 1;
while(Writed)
{
	res = netfs->fread(sFileHandler, buf, FileBuffSize, &Writed);
	if(res != FR_OK)
		while(1);

//	res = netfs->fseek(sFileHandler, 0);
//	if(res != FR_OK)
//		while(1);
Num++;
if(Num == 1024)
break;

}

	res =  netfs->fclose(sFileHandler);
	if(res != FR_OK)
		while(1);

goto trewq;


while(1);
}



//#define FileBuffSizeFl 32768
#define FileBuffSizeFl 1024
void si_usb3(uint32 num0, uint32 num1, int delay)
{
//	uint32 sHandler = 0;
	uint32 sFileHandler = 0, dFileHandler = 0;
	FRESULT res = FR_NOT_ENOUGH_MEMORY;
	uint8 *buf = NULL;
//	uint8 buf[1024];
	uint16 Writed = 0;
	uint32 Num = 0;

		buf = (uint8*)malloc(FileBuffSizeFl);
		if(!buf)
		{
			res = FR_NOT_ENOUGH_MEMORY;
		while(1);
		}



		memset(buf, num0, FileBuffSizeFl);

	TNetFSAPI *netfs = NULL;
	getNetFSAPI(&netfs);
	if(!netfs)
		while(1);

/*
	res =  netfs->fopen(&sFileHandler, "FLASHDRIVE:/sitest00.bin", FA_OPEN_ALWAYS | FA_WRITE);
	if(res != FR_OK)
		while(1);

Num = 1024*1024;
while(Num--)
{
	Writed = 1;
	res = netfs->fwrite(sFileHandler, buf, FileBuffSizeFl, &Writed);
	if(res != FR_OK)
		while(1);
}

	res =  netfs->fclose(sFileHandler);
	if(res != FR_OK)
		while(1);


while(1);
*/






	res =  netfs->fopen(&sFileHandler, "FLASHDRIVE:/sitest00.bin", FA_READ);
	if(res != FR_OK)
		while(1);

Writed = 1;
while(Writed)
{
	res = netfs->fread(sFileHandler, buf, FileBuffSizeFl, &Writed);
	if(res != FR_OK)
		while(1);
/*

	res = netfs->fseek(sFileHandler, 0);
	if(res != FR_OK)
		while(1);
*/
Num++;
}




	res =  netfs->fclose(sFileHandler);
	if(res != FR_OK)
		while(1);


while(1);
}


#endif


//-------------------------------------------------------------
//------------------------АЛП
//-------------------------------------------------------------
#ifdef TPO5
void alp_sinhrosig()
{
uint32 res = EN;

EN = res | 0x4000;
res = DIR;
DIR = res | 0x4000;
res = VAL;
VAL = res | 0x4000;

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
VAL = res & (~0x4000);
}

void alp_sinhrosig1()
{
uint32 res = EN;

EN = res | 0x2000;
res = DIR;
DIR = res | 0x2000;
res = VAL;
VAL = res | 0x2000;

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
VAL = res & (~0x2000);
}

void alp_sinhrosig2()
{
uint32 res = EN;

EN = res | 0x2000;
res = DIR;
DIR = res | 0x2000;
res = VAL;
VAL = res & (~0x2000);

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
VAL = res & (~0x2000);
}

//#endif

#else 
void alp_sinhrosig()
{
uint32 res = EN;

EN = res | 0x40;
res = DIR;
DIR = res | 0x40;
res = VAL;
VAL = res | 0x40;

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
VAL = res & (~0x40);
}

void alp_sinhrosig1()
{
uint32 res = EN;

EN = res | 0x10;
res = DIR;
DIR = res | 0x10;
res = VAL;
VAL = res | 0x10;

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
VAL = res & (~0x10);
}


void alp_sinhrosig2()
{
uint32 res = EN;

EN = res | 0x10;
res = DIR;
DIR = res | 0x10;
res = VAL;
VAL = res & (~0x10);

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
VAL = res & (~0x10);
}
#endif

//-------------------------------------------------------------
//-------------------------------------------------------------
void alp_ext_ram(int RW, uint16 num0, uint16 num1, int delay)	
{

uint16* addr = (uint16*)0x68000000;	//NVRAM
//uint16* addr1 = (uint16*)0x68000004;	//NVRAM
//uint16 ch;
uint32 u = 333;


uint32 r = prc_disable();

while(true)
{
//sleep_u( delay );
u = 256;
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


u = 450;
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

	*addr = num0;

}

}




void alp_int_ram(int RW, uint32 num0, uint32 num1, int delay)	
{


EN |= 0x20;
DIR |= 0x20;
//VAL |= 0x20;


//test_addr1 = (uint32 *) (0x00000000);

uint32* chan = (uint32*)0x01940000;

uint32 r = 0;

if(!(*chan & 0x8)) //на 6-ке в 0 канале - 1. в 1 канале - 0.
{
r = int_disable();
while(1);
}

number=num0;

uint32 u = 333;

r = prc_disable();


while(1)
{
//*test_addr1 =num1;
//*test_addr2 =num1;
//asm_si_ram_acc_int1();

*test_addr1 =0xFFFFFFFF;
*test_addr2 =0xFFFFFFFF;
VAL |= 0x20;
alp_sinhrosig();

//u = 1024; //16micra
u = 615; 
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

//sleep_u( 10 );
switch(RW)
{
 case 1:
 {
 alp_sinhrosig1();
 asm_si_ram_acc_int1();
 alp_sinhrosig1();
 } 
 break;

 case 2:
 {
 alp_sinhrosig2();
 asm_si_ram_acc_int1();
 alp_sinhrosig1();
 } 
 break;

 case 3:
 {
 alp_sinhrosig2();
 asm_si_ram_acc_int1();
 alp_sinhrosig2();
 } 
 break;

}


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


*test_addr1 =num0;
*test_addr2 =num0;
VAL ^= 0x20;
alp_sinhrosig();

//u = 1024; //16micra
u = 615; 
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

//sleep_u( 10 );
switch(RW)
{
 case 1:
 {
 alp_sinhrosig1();
 asm_si_ram_acc_int1();
 alp_sinhrosig1();
 } 
 break;

 case 2:
 {
 alp_sinhrosig2();
 asm_si_ram_acc_int1();
 alp_sinhrosig1();
 } 
 break;

 case 3:
 {
 alp_sinhrosig2();
 asm_si_ram_acc_int1();
 alp_sinhrosig2();
 } 
 break;

}


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

}
}


void alp_load_key(uint32 num0, uint32 num1, int delay)
{

#ifdef TPO5
uint32* addr= (uint32*)0xa0000000;
uint32 det = num0;
#else 
uint64* addr= (uint64*)0xb0000000;
uint64 det = num0;
det = num0 | (det<<32);
#endif

uint32 u = 333;

AbLoadBP(test_bp);


u = *REGe;			// Меняю делиель на EMIF CLKOUT2 - так не дергается сигнал относительно синхры
*REGe = u & 0xFFF3FFFF;

uint32 r = prc_disable();

while(true)
{
u = 615;
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

u = 1230;
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

*addr = det;


}

}


//----------------------------------------------------------------------------
void alp_AbEncrypt(uint32 num0, uint32 num1, int delay)
{

#ifdef TPO5
uint32 test_key[8];

uint32 u = 333;

	AbLoadBP(test_bp);

for(int y=0; y<8; y++)
test_key[y]=num0;

AbLoadKey(test_key);

uint32 r = prc_disable();


uint32 text[8];
for(int y=0; y<8; y++)
text[y]=num1;


while(1)
{


u = 256;
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

u = 450;
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
}
#else TPO7


uint32 test_key[8];

uint32 u = 333;

	AbLoadBP(test_bp);

for(int y=0; y<8; y++)
test_key[y]=num0;

AbLoadKey(test_key);

uint32 r = prc_disable();


uint32 text[128];
for(int y=0; y<128; y++)
text[y]=num0;


while(1)
{


u = 150;
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

for(int y=0; y<128; y++)
text[y]=num0;

AbLoadKey(test_key);

alp_sinhrosig();
u = 1200;
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
AbEncrypt(text,512);
alp_sinhrosig();



/*
for(int y=0; y<8; y++)
test_key[y]=num0;

AbLoadKey(test_key);

uint32 text[8];
for(int y=0; y<8; y++)
text[y]=num1;
#endif


AbEncrypt(text,4);
}
*/

}
#endif

}
//----------------------------------------------------------------------------
