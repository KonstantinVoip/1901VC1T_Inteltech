#include <os.h>
#include <drv_dbgout.h>
#include <__fs.h>
#include <drv_usbms.h>
#include <rts.h>
#include <drv_vfat.h>


#include "tests.h"
#include "tpo.h"
#include "tpo_hash.h"
#include "mem_test.h"



#ifdef TPO5
#include <drv_dnsd.h>
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

//int F_test_ram();
int F_test_usbc();
int F_test_usb_flash1();


extern uint32 ResNTest;
extern uint16 Start_n_test;
extern uint16 Start_dozu_nagr;
extern uint16 Start_tst_rom;
extern uint16 Start_move;
	
extern uint32 ResAllTest;	
extern int NVRAM;
extern int SDRAM;
extern int SP;
extern int INTR;
extern int SK;
extern int DOZU;
extern int COMM_DOZU_COMM;
//extern int SPARKO; 
extern int SHIF;     
extern int USB;     


extern hash_window hwindow[];
extern comm_status pid_comm[NUMBER_COMM_DSP];
extern uint32 D;
extern kdg_rez_test gl_result;

//extern uint16 	Stop_cikl;
//extern uint16  	Next_cikl;

extern void* sh_mem_read[NUMBER_COMM_DSP];
extern void* sh_mem_write[NUMBER_COMM_DSP];


void nvram_l(uint16 N)
{
uint16* Lo = (uint16*)0x68000010;

*Lo = N;
}


//----------------------------------------------------------------------------
void ReadDARAM(uint16 n_comm,uint16 addr,void* buf,uint16 len)
{
	memcpy(buf,(char*)sh_mem_read[n_comm]+addr,len);
}

#ifdef TPO5
//----------------------------------------------------------------------------
void WriteDARAM(uint16 n_comm,uint16 addr,void* buf,uint16 len)
{
//memcpy((char*)sh_mem_write[n_comm]+addr,buf,len);

uint16 l=(len+3)>>2;
uint32* s=(uint32*)buf;
uint32* d=(uint32*)((char*)sh_mem_write[n_comm]+addr);
while(l--)
	_amem4(d++)=_mem4(s++);

}
#endif
#ifdef TPO6
void WriteDARAM(uint16 n_comm,uint16 addr,void* buf,uint16 len)
{
//memcpy((char*)sh_mem_write[n_comm]+addr,buf,len);

uint16 l=(len+7)>>3;
uint64* s=(uint64*)buf;
uint64* d=(uint64*)((char*)sh_mem_write[n_comm]+addr);
while(l--)
	_amem8(d++)=_mem8(s++);

}
#endif

#ifdef TPO7


const uint16 route_cmds[3+1]=
{
CMD_PUT_IN_NULL,
CMD_PUT_IN_SP0,
CMD_PUT_IN_SP1,
CMD_PUT_IN_SP2
};

uint16 RouteToCmd(int route)
{
route++;
return route_cmds[route];
}


void WriteDARAM(uint16 n_comm,uint16 addr,void* buf,uint16 len)
{
uint16 shift_ip = 0;
uint64 hdr[3];
memset(hdr, 0, sizeof(hdr));

if(n_comm > 1)
while(1);//????

ChMoveCP(hdr, buf, shift_ip, len, RouteToCmd(n_comm));
//ChMoveCP(hdr, buf, len, 1);
}
#endif

/*
void receive_res_comm(void* recev, uint32 n_comm)
{

kdg_rez_test* res = (kdg_rez_test*)recev;

while(pid_comm[n_comm].ask != res->n_test);

res->rez = pid_comm[n_comm].rez; 

//pid_comm[n_comm].ask = 0;
//pid_comm[n_comm].rez = 0;

//return TPO_OK;
}
*/

//----------------------------------------------------------------------------
int32 receive_msg_comm(void* recev, uint32* n_comm, int32 length, uint32 ms)
{
  s_message*  		msg_desc;
  int32 error;

  error = msg_recv( &msg_desc, ms);

  if( (error != OSE_OK)||(msg_desc == NULL) )
  {
//	gl_result.err = COMM_TIME_OUT + *n_comm;
    return MSG_ER_TIME_OUT;
  }
  if(msg_desc->length != length)
  {
    msg_free(msg_desc);
    return MSG_ER_SYNC;
  }

	for(int y = MIN_NUMBER_COMM; y < NUMBER_COMM_DSP; y++)
	{
	if(pid_comm[y].pid == msg_desc->from)
	*n_comm = y;
	}

  memcpy(recev, msg_desc->data, length);
  msg_free(msg_desc);
  return TPO_OK;

}


//----------------------------------------------------------------------------
uint32 Send_cmd_comm(uint32 n_comm, uint32 cmd)
{

kdg_cmd		to_comm;
kdg_cmd_ask	cdg_error;

memset(&cdg_error, 0, sizeof(kdg_cmd_ask));

uint32		N_comm = 0;
int32		error;

  to_comm.cmd = cmd;

  msg_send(pid_comm[n_comm].pid, &to_comm, sizeof(kdg_cmd));
  error = receive_msg_comm(&cdg_error, &N_comm, sizeof(kdg_cmd_ask), MSG_WAIT_10);

	if(error)
		return error;
	else
		return cdg_error.ask;

}

//----------------------------------------------------------------------------
uint32 Send_Start_N_Test(uint32 n_comm, uint32 n_test)
{
kdg_rez_test tst;
memset(&tst, 0, sizeof(kdg_rez_test));
uint32 res=0;

res = Send_cmd_comm(n_comm, N_TEST);
	if(res == TPO_OK)
	{
		tst.n_test = n_test;
		msg_send(pid_comm[n_comm].pid, &tst, sizeof(kdg_rez_test));
		prc_yield();
	}

return res;	
}

/*
int F_test_ram()
{
    uint32 res = 0;
    
//	F_TestProgress(1);

	uint32 ErrorsPositions;
	uint32 ErrorAddress;
//debug!!!!!!!!
//	res = uniTestSDRAM( &ErrorsPositions, &ErrorAddress);
//debug!!!!!!!!
//    res = ram_test_base();    
    
	return res == 0 ? 0 : 1;
}
*/

//----------------------------------------------------------------------------
int F_test_usbc()
{
    int res = 0;
    
//	F_TestProgress(1);

    res = usb_test_base();
    
	return res == 0 ? 0 : 1;
}

//----------------------------------------------------------------------------
int F_test_usb_flash1()
{
    int res = 0;

//	F_TestProgress(1);

    res = usb_test_rw(1);
    
	return res == 0 ? 0 : 1;
}




#ifdef TPO_M711B


//----------------------------------------------------------------------------
//#define FileBuffSizeFl 1024
int F_test_usb_flash3()
{
//	uint32 sHandler = 0;
	uint32 sFileHandler = 0, dFileHandler = 0;
	FRESULT res = FR_NOT_ENOUGH_MEMORY;
	uint16 Writed = 0;
	uint32 Num = 0;

    char	buf_wr[512];
    char	buf_rd[512];

	for(int i=0;i<sizeof(buf_wr);i++ )
	buf_wr[i]= i&0xFF;

	memset(buf_rd, 0, sizeof(buf_rd));

	TNetFSAPI *netfs = NULL;
	getNetFSAPI(&netfs);
	if(!netfs)
		return 1;

	res =  netfs->fopen(&sFileHandler, "FLASHDRIVE:/test03.bin", FA_CREATE_ALWAYS | FA_WRITE);
	if(res != FR_OK)
		return 1;

	Writed = 0;
	res = netfs->fwrite(sFileHandler, buf_wr, sizeof(buf_wr), &Writed);
	if(res != FR_OK)
		return 1;

	res =  netfs->fclose(sFileHandler);
	if(res != FR_OK)
		return 1;


	res =  netfs->fopen(&sFileHandler, "FLASHDRIVE:/test03.bin", FA_READ);
	if(res != FR_OK)
		return 1;

	Writed = 0;
	res = netfs->fread(sFileHandler, buf_rd, sizeof(buf_rd), &Writed);
	if(res != FR_OK)
		return 1;

	res =  netfs->fclose(sFileHandler);
	if(res != FR_OK)
		return 1;

	if(memcmp(buf_wr, buf_rd, sizeof(buf_rd)))
		return 1;

return 0;
}

//----------------------------------------------------------------------------
//#define FileBuffSizeFl 1024
int F_test_SSD()
{
//	uint32 sHandler = 0;
	uint32 sFileHandler = 0, dFileHandler = 0;
	FRESULT res = FR_NOT_ENOUGH_MEMORY;
	uint16 Writed = 0;
	uint32 Num = 0;

    char	buf_wr[512];
    char	buf_rd[512];

		TDiskStatus stt;

	for(int i=0;i<sizeof(buf_wr);i++ )
	buf_wr[i]= i&0xFF;

	memset(buf_rd, 0, sizeof(buf_rd));


	TNetFSAPI *netfs = NULL;
	getNetFSAPI(&netfs);
	if(!netfs)
		return 1;

//			res = netfs->getDiskStatus("STORAGE:/", &stt);

	res =  netfs->fopen(&sFileHandler, "STORAGE:/testssd.bin", FA_CREATE_ALWAYS | FA_WRITE);
	if(res != FR_OK)
		return 1;

	Writed = 0;
	res = netfs->fwrite(sFileHandler, buf_wr, sizeof(buf_wr), &Writed);
	if(res != FR_OK)
		return 1;

	res =  netfs->fclose(sFileHandler);
	if(res != FR_OK)
		return 1;

	res =  netfs->fopen(&sFileHandler, "STORAGE:/testssd.bin", FA_READ);
	if(res != FR_OK)
		return 1;

	Writed = 0;
	res = netfs->fread(sFileHandler, buf_rd, sizeof(buf_rd), &Writed);
	if(res != FR_OK)
		return 1;

	res =  netfs->fclose(sFileHandler);
	if(res != FR_OK)
		return 1;

	if(memcmp(buf_wr, buf_rd, sizeof(buf_rd)))
		return 1;

return 0;
}

//----------------------------------------------------------------------------
//#define FileBuffSizeFl 1024
int F_test_CDROM()
{
//	uint32 sHandler = 0;
	uint32 sFileHandler = 0, dFileHandler = 0;
	FRESULT res = FR_NOT_ENOUGH_MEMORY;
	uint16 Writed = 0;
	uint32 Num = 0;

	TDiskStatus stt;

    char	buf_wr[512];
    char	buf_rd[512];

	for(int i=0;i<sizeof(buf_wr);i++ )
	buf_wr[i]= i&0xFF;

	memset(buf_rd, 0, sizeof(buf_rd));


	TNetFSAPI *netfs = NULL;
	getNetFSAPI(&netfs);
	if(!netfs)
		return 1;
//	res = netfs->getDiskStatus("CDDVD:/", &stt);
	res =  netfs->fopen(&sFileHandler, "CDDVD:/tstcdrom.bin", FA_READ);
//	res =  netfs->fopen(&sFileHandler, "CDDVD:/14000004.lst", FA_READ);
	if(res != FR_OK)
		return 1;

	Writed = 0;
	res = netfs->fread(sFileHandler, buf_rd, sizeof(buf_rd), &Writed);
	if(res != FR_OK)
		return 1;

	res =  netfs->fclose(sFileHandler);
	if(res != FR_OK)
		return 1;

	if(memcmp(buf_wr, buf_rd, sizeof(buf_rd)))
		return 1;

return 0;
}

//----------------------------------------------------------------------------
int F_celostnost_056()
{

	FRESULT res = FR_NOT_ENOUGH_MEMORY;
	TCalcHashResult hash;
	uint32 vector[8];
    memset(vector, 0, sizeof(vector));        

	TNetFSAPI *netfs = NULL;
	getNetFSAPI(&netfs);
	if(!netfs)
		return 1;


    res = netfs->getHash(board056, &hash, vector);
	if(res != FR_OK)
		return 1;
	else
    {
	    if(hash.Valid0 == 0)	return 1;
    	if(hash.Valid1 == 0) 	return 1;       
	}

return 0;
}

//----------------------------------------------------------------------------

int TestSDRAM_056()
{


return 0;
}



#endif

//#define NVRAM_START_ADDR    0x68000000  // Начальный адрес NVRAM
//#define NVRAM_SIZE          0x00100000  // Размер NVRAM в байтах. 0x00100000 = 1MB

//----------------------------------------------------------------------------
//нужно для теста сохранности
int32 tst_nvram_addr()
{
    uint8* addr = (uint8*)0x68000000;
    uint32 j;
//    for( i = 0; i < 8; i += 8 )
//    {
        for( j = 0; j < 8; j++ )
        {
            addr[j] = 0x01 << j;
        }
//    }
//    for( i = 8; i < 0x00100000; i += 8 )
//    {
        for( j = 0; j < 8; j++ )
        {
            if( addr[j] != (0x01 << j) )
            {
                return TPO_ERR;
            }
        }
//    }
    return TPO_OK;
}

//----------------------------------------------------------------------------
int TestNVRAM()
{

    uint32 res = 0;
//    uint32 res1 = 0;
    
//	F_TestProgress(1);

	uint64 ErrorsPositions;
	uint32 ErrorAddress;

	res = uniTestNVRAM( &ErrorsPositions, &ErrorAddress);


//	res1 = tst_nvram_addr();
//	res1++;
//		if(res1 == TPO_ERR)
			
	return res == 0 ? 0 : 1;

}
	
//----------------------------------------------------------------------------
int TestSDRAM()
{

    uint32 res = 0;
    
//	F_TestProgress(1);

//	uint32 ErrorsPositions;
//	uint32 ErrorAddress;
//debug!!!!!!!!
//	res = uniTestSDRAM( &ErrorsPositions, &ErrorAddress);
//debug!!!!!!!!
	res = sdram_test_base();

	return res == 0 ? 0 : 1;

}
#ifdef TPO5
	/*****************************************************************************
	Syntax:  void F_test_dnsd_crc(kdg_rez_test* result) 	    
	Remarks:			    
	*******************************************************************************/
	void F_test_dnsd_crc(kdg_rez_test* result)
	{

	    //uint32 res = 0;
		uint32 err = 0;
		uint32 dnsd = drv_mkd( "/dev/dnsd" );
			
		//	err = drv_ioctl( dnsd, DNSD_READ_CRC, &res );
		//	result->rez = err;
		err = drv_ioctl( dnsd, DNSD_READ_CRC, &result->rez );
		err = drv_ioctl( dnsd, DNSD_READ_ADC, &result->data );

		drv_rmd(dnsd);
		//	return res;
	}
    
	/*****************************************************************************
	Syntax:  void F_zavesti_dnsd(kdg_rez_test* result) 	    
	Remarks:			    
	*******************************************************************************/
	void F_zavesti_dnsd(kdg_rez_test* result)
	{

		//uint32 res = 0;
		uint32 err = 0;
		uint8 K0K1[64];
		uint8 K0[32];
		uint32 resultat;

		uint32 dnsd = drv_mkd( "/dev/dnsd" );
			
		memset( K0K1, 0, sizeof( K0K1 ) );
		memset( K0, 0x00, sizeof( K0 ) );

		for(uint8 g=0; g<64; g++)
		K0K1[g]=g;
			
		//	err = drv_ioctl( dnsd, DNSD_READ_CRC, &res );
		//	result->rez = err;

		err = drv_ioctl( dnsd, DNSD_K0K1_WRITE, &K0K1 );
		if( err )
			result->rez|=ERR_DNSD_TIMEOUT;
		sleep_s( 3 );

		err = drv_ioctl( dnsd, DNSD_INIT, 0 );
		if( err )
			result->rez|=ERR_DNSD_TIMEOUT;
		sleep_s( 3 );

		drv_rmd(dnsd);
	//	return res;

	}
	/*****************************************************************************
	Syntax:  void F_dnsd_prochitat(kdg_rez_test* result)	    
	Remarks:			    
	*******************************************************************************/
	void F_dnsd_prochitat(kdg_rez_test* result)
	{

		uint32 err = 0;
		uint32 resultat;
		uint8 K0[32];
		memset( K0, 0x00, sizeof( K0 ) );

		uint32 dnsd = drv_mkd( "/dev/dnsd" );
			
			
	//	err = drv_ioctl( dnsd, DNSD_READ_CRC, &res );
	//	result->rez = err;

		err = drv_ioctl( dnsd, DNSD_K0_READ, &K0 );
		if( err )
			resultat|=ERR_DNSD_TIMEOUT;

		memcpy( result->buf, K0, sizeof( K0 ) );

		drv_rmd(dnsd);
	//	return res;

	}
    /*****************************************************************************
	Syntax:  int F_test_dnsd_vd(uint32 cik, kdg_rez_test* result)	    
	Remarks:			    
	*******************************************************************************/
	int F_test_dnsd_vd(uint32 cik, kdg_rez_test* result)
	{

		uint32 res = 0;
		uint32 err = 0;


		uint8 K0K1[64];
		uint8 K0[32];
		uint8 Err_time[32];
		uint32 resultat;

		uint32 dnsd = drv_mkd( "/dev/dnsd" );
			

		memset( K0K1, 0x55, sizeof( K0K1 ) );
		memset( K0K1, 0xAA, sizeof( K0 ) );
		memset( K0, 0x00, sizeof( K0 ) );
		memset( Err_time, 0xFF, sizeof( K0 ) );

		err = drv_ioctl( dnsd, DNSD_K0K1_WRITE, &K0K1 );
		if( err )
			res|=ERR_DNSD_TIMEOUT;
		sleep_s( 1 );//3

		// Read K0 and compare with K0
		err = drv_ioctl( dnsd, DNSD_K0_READ, &K0 );
		if( !memcmp( &K0, &Err_time, sizeof( K0 ) ) )
			res|=ERR_DNSD_TIMEOUT;
		if( memcmp( &K0, &K0K1, sizeof( K0 ) ) )
		{
			res|=ERR_DNSD_READ_C0;
			memcpy( result->buf, K0, sizeof( K0 ) );

		}

		if(cik==2)//в цыклах выход.
			if(res)
				return 1;
			else
				return 0;

		err = drv_ioctl( dnsd, DNSD_INIT, 0 );
		if( err )
			res|=ERR_DNSD_TIMEOUT;
		sleep_s( 1 );
		// Read K0 and compare with K0
		memset( K0, 0x00, sizeof( K0 ) );
		err = drv_ioctl( dnsd, DNSD_K0_READ, &K0 );
		if( !memcmp( &K0, &Err_time, sizeof( K0 ) ) )
			res|=ERR_DNSD_TIMEOUT;
		if( memcmp( &K0, &K0K1, sizeof( K0 ) ) )
		{
			res|=ERR_DNSD_READ_C0;
			memcpy( result->buf, K0, sizeof( K0 ) );

		}


		// Plate LED ON
		if(cik==0)
		{
			err = drv_ioctl( dnsd, DNSD_LED_ON, 0 );
			if( err )
			res|=ERR_DNSD_TIMEOUT;
			sleep_s( 3 );
		}
		else
		{
			err = drv_ioctl( dnsd, DNSD_PlateLED_ON, 0 );
			if( err )
				res|=ERR_DNSD_TIMEOUT;
			sleep_s( 2 );
			// Plate LED OFF
			err = drv_ioctl( dnsd, DNSD_PlateLED_OFF, 0 );
			if( err )
			res|=ERR_DNSD_TIMEOUT;
			sleep_s( 1 );
		}
		// Read K0 & compare with K1
		memset( K0, 0x00, sizeof( K0 ) );
		err = drv_ioctl( dnsd, DNSD_K0_READ, &K0 );
		if( !memcmp( &K0, &Err_time, sizeof( K0 ) ) )
			res|=ERR_DNSD_TIMEOUT;
	//    if(!memcmp( &K0, &K0K1 + sizeof( K0 ), sizeof( K0 ) ) )
		if(memcmp( &K0, &K0K1[32], sizeof( K0 ) ) )
			res|=ERR_DNSD_TRIGGER;


		drv_rmd(dnsd);
		return res;

	}

    	}
    /*****************************************************************************
	Syntax:  int F_dnsd_vkl_vd(uint32 n)	    
	Remarks:			    
	*******************************************************************************/
	int F_dnsd_vkl_vd(uint32 n)
	{
		uint32 res = 0;
		uint32 err = 0;

		uint32 dnsd = drv_mkd( "/dev/dnsd" );

		if(n==0)
		{
			err = drv_ioctl( dnsd, DNSD_LED_ON, 0 );
			if( err )
			res|=ERR_DNSD_TIMEOUT;
	//    	sleep_s( 3 );
		}
		else
		{
			err = drv_ioctl( dnsd, DNSD_PlateLED_ON, 0 );
			if( err )
				res|=ERR_DNSD_TIMEOUT;
	//	    sleep_s( 1 );
			// Plate LED OFF
	//	    err = drv_ioctl( dnsd, DNSD_PlateLED_OFF, 0 );
	//    	if( err )
	//		res|=ERR_DNSD_TIMEOUT;
	//    	sleep_s(  );
		}


	drv_rmd(dnsd);

	}

    /*****************************************************************************
	Syntax:  int F_dnsd_vikl_vd(uint32 n)	    
	Remarks:			    
	*******************************************************************************/
	int F_dnsd_vikl_vd(uint32 n)
	{
		uint32 res = 0;
		uint32 err = 0;

	    uint32 dnsd = drv_mkd( "/dev/dnsd" );

		// Plate LED OFF
		err = drv_ioctl( dnsd, DNSD_PlateLED_OFF, 0 );
		if( err )
		res|=ERR_DNSD_TIMEOUT;


	    drv_rmd(dnsd);

	}

    /*****************************************************************************
	Syntax:  void F_test_dnsd_lux(kdg_rez_test* result)	    
	Remarks:			    
	*******************************************************************************/
	void F_test_dnsd_lux(kdg_rez_test* result)
	{

	//    uint32 res = 0;
		uint32 err = 0;
		uint32 dnsd = drv_mkd( "/dev/dnsd" );
			
	//	err = drv_ioctl( dnsd, DNSD_READ_CRC, &res );
	//	result->rez = err;
		err = drv_ioctl( dnsd, DNSD_LUX, &result->rez );

		drv_rmd(dnsd);
	//	return res;

	}

	/*****************************************************************************
	Syntax:  void F_test_dnsd_magic(kdg_rez_test* result)	    
	Remarks:			    
	*******************************************************************************/

	void F_test_dnsd_magic(kdg_rez_test* result)
	{

	//    uint32 res = 0;
		uint32 err = 0;
		uint32 dnsd = drv_mkd( "/dev/dnsd" );
			
	//	err = drv_ioctl( dnsd, DNSD_READ_CRC, &res );
	//	result->rez = err;
		err = drv_ioctl( dnsd, DNSD_MAGIC, &result->rez );

		drv_rmd(dnsd);
	//	return res;

	}



#endif   //ENDIF TPO5

//----------------------------------------------------------------------------
/*
int sdram_test_base(void)
{

uint32 a = SDRAM_START_ADDR;				
uint32* addr = (uint32*)a;

*addr = 0x55555555;
	if(*addr != 0x55555555)
		return TPO_ERR;
*addr = 0xAAAAAAAA;
	if(*addr != 0xAAAAAAAA)
		return TPO_ERR;

for(int i = 0; i < SDRAM_LEN/SDRAM_WIDTH; i++)
{
addr[i] = i & 0xFFFFFFFF;
}

for(int i = 0; i < SDRAM_LEN/SDRAM_WIDTH; i++)
{
	if(addr[i] != i & 0xFFFFFFFF)
	return TPO_ERR;
}

return TPO_OK;
}    
*/


#ifdef TPO5
int sdram_test_base(void)
{

uint32 save_buf[SDRAM_BLOK_LEN/SDRAM_WIDTH];
uint32 a = SDRAM_START_ADDR;				
uint32* addr = (uint32*)a;
uint32* save_addr;
uint32 int_old = 0;

int i = 0;

int_old = int_disable();
save_addr = addr;
memcpy(save_buf, save_addr, sizeof(save_buf));

*addr = 0x55555555;
	if(*addr != 0x55555555)
		goto sdram_error;
*addr = 0xAAAAAAAA;
	if(*addr != 0xAAAAAAAA)
		goto sdram_error;

memcpy(save_addr, save_buf,sizeof(save_buf));
int_enable(int_old);	

	for(i = 0; i < (SDRAM_LEN/SDRAM_BLOK_LEN); i++)
	{
		int_old = int_disable();
		save_addr = addr + (i * sizeof(save_buf))/SDRAM_WIDTH;
		memcpy(save_buf, save_addr, sizeof(save_buf));

		for(int j = i*(SDRAM_BLOK_LEN/SDRAM_WIDTH); j < ((i+1)*(SDRAM_BLOK_LEN/SDRAM_WIDTH)); j++)
		{
		addr[j] = j & 0xFFFFFFFF;
		}

		for(int j = i*(SDRAM_BLOK_LEN/SDRAM_WIDTH); j < ((i+1)*(SDRAM_BLOK_LEN/SDRAM_WIDTH)); j++)
		{
			if(addr[j] != j & 0xFFFFFFFF)
			goto sdram_error;
		}

		memcpy(save_addr, save_buf,sizeof(save_buf));
		int_enable(int_old);	
	}

return TPO_OK;

sdram_error:

	memcpy(save_addr, save_buf,sizeof(save_buf));
	int_enable(int_old);	
	return TPO_ERR;
}    

#else

int sdram_test_base(void)
{

uint64 save_buf[SDRAM_BLOK_LEN/SDRAM_WIDTH];
uint32 a = SDRAM_START_ADDR;				
uint64* addr = (uint64*)a;
uint64* save_addr;
uint32 int_old = 0;

int i = 0;

int_old = int_disable();
save_addr = addr;
memcpy(save_buf, save_addr, sizeof(save_buf));

*addr = 0x5555555555555555;
	if(*addr != 0x5555555555555555)
		goto sdram_error;
*addr = 0xAAAAAAAAAAAAAAAA;
	if(*addr != 0xAAAAAAAAAAAAAAAA)
		goto sdram_error;

memcpy(save_addr, save_buf,sizeof(save_buf));
int_enable(int_old);	

	for(i = 0; i < (SDRAM_LEN/SDRAM_BLOK_LEN); i++)
	{
		int_old = int_disable();
		save_addr = addr + (i * sizeof(save_buf))/SDRAM_WIDTH;
		memcpy(save_buf, save_addr, sizeof(save_buf));

		for(int j = i*(SDRAM_BLOK_LEN/SDRAM_WIDTH); j < ((i+1)*(SDRAM_BLOK_LEN/SDRAM_WIDTH)); j++)
		{
		addr[j] = j & 0xFFFFFFFFFFFFFFFF;
		}

		for(int j = i*(SDRAM_BLOK_LEN/SDRAM_WIDTH); j < ((i+1)*(SDRAM_BLOK_LEN/SDRAM_WIDTH)); j++)
		{
			if(addr[j] != j & 0xFFFFFFFFFFFFFFFF)
			goto sdram_error;
		}

		memcpy(save_addr, save_buf,sizeof(save_buf));
		int_enable(int_old);	
	}

return TPO_OK;

sdram_error:

	memcpy(save_addr, save_buf,sizeof(save_buf));
	int_enable(int_old);	
	return TPO_ERR;
}    
#endif


//----------------------------------------------------------------------------
int usb_test_base()
{

uint32 error;

uint64 bits_error;

uint16 *addr_chip_id_nec   = (uint16*)0x60000000;
uint16 addr_scretch_reg_nec = 0x600001B0;

uint32 *addr_chip_id    = (uint32*)0x60000304;
uint32 addr_scretch_reg = 0x60000308;

if(*addr_chip_id_nec == 0x0120)
	error = uniMemoryCellTest(addr_scretch_reg_nec , &bits_error, 16);
		if(!error)		
			return 0; 


if(*addr_chip_id != 0x11761)
return 1; 

error = uniMemoryCellTest(addr_scretch_reg , &bits_error, 32);
if(error)		//если ошибка
	return 1; 



return 0;
}




//----------------------------------------------------------------------------
int usb_test_rw(uint32 dev)
{

    char	file_path[32];
    FILE*	file;

    char	buf_wr[512];
    char	buf_rd[512];

	for(int i=0;i<sizeof(buf_wr);i++ )
	buf_wr[i]= i&0xFF;

	memset(buf_rd, 0, sizeof(buf_rd));

	if(dev == 1)
    	strcpy(file_path, "/vfat/a/test.bin");
	if(dev == 2)
    	strcpy(file_path, "/vfat/b/test.bin");

    file = fopen(file_path, "w");
    if(file == NULL) 
		return 1;

    if(sizeof(buf_wr) != fwrite(buf_wr, 1, sizeof(buf_wr), file))
		return 2;

	fclose(file);


    file = fopen(file_path, "r");
    if(file == NULL) 
		return 1;

    if(sizeof(buf_rd) != fread(buf_rd, 1, sizeof(buf_rd), file))
		return 2;

	fclose(file);

//	for(int i=0;i<sizeof(buf_rd);i++ )
//		if(buf_rd[i] != i&0xFF)
	if(memcmp(buf_wr, buf_rd, sizeof(buf_rd)))
		return 3;
return 0;
}

/*****************************************************************************
Syntax:  uint32 TestCelostnost()  
Remarks: Sparka est D			    
*******************************************************************************/
uint32 TestCelostnost()
{

int error = 0;
kdg_rez_test result;
uint32 n_comm = 0;
uint32 res = 0;

//nvram_l(0);

//return 0;

if(D)
{
	for(int i = MIN_NUMBER_COMM; i<NUMBER_COMM_DSP ; i++)
	{
	error = Send_Start_N_Test(i, CELOSTN);
		if(error == MSG_ER_TIME_OUT)
		{
			gl_result.err = COMM_TIME_OUT + n_comm;
			return error;
		}
		if(error == MSG_ER_SYNC)
		{
			gl_result.err = COMM_ERR_MSG + n_comm;
			return error;
		}
	}
}


/*
int32	ret = 3;

ret_hash3:
//syn_begin();
//syn_end();
ret--;

	res = analysis_hash_fwmem_main(hwindow);
	res = (res == 0 ? 0 : 1);
//	if(res)
//	{
//		syslog(110,"analysis_hash ret = %d ", ret);
//		syslog(110,"analysis_hash res = %d ", res);
//	}
//
if(syn_data(&res, sizeof(uint32), 0) != OSE_OK)
{

		syslog(111,"syn_data err ret = %d ", ret);
		syslog(111,"syn_data err res = %d ", res);


	if(ret > 0) 
		goto ret_hash3;
	else
		res = 1;
}
else
{

	if(res)
	{
		syslog(112,"syn_data ok ret = %d ", ret);
		syslog(112,"syn_data ok res = %d ", res);
		if(ret > 0) 
			goto ret_hash3;
	}
}


//syn_begin();
//syn_end();

*/




//долгий syn_begin() дает развал спарки!!!!!!
//syn_begin();
//syn_end();
	res = analysis_hash_fwmem(hwindow);

//	if(res)
//	syslog(110,"analysis_hash res = %d ", res);

	res = (res == 0 ? 0 : 1);



if(D)
{

	for(int i = MIN_NUMBER_COMM; i<NUMBER_COMM_DSP ; i++)
	{
	error = receive_msg_comm(&result, &n_comm, sizeof(kdg_rez_test), MSG_WAIT_10);
		if(error == MSG_ER_TIME_OUT)
		{
			gl_result.err = COMM_TIME_OUT + n_comm;
			return error;
		}
		if(error == MSG_ER_SYNC)
		{
			gl_result.err = COMM_ERR_MSG + n_comm;
			return error;
		}

		if(result.rez != 0)
			res = res | (1 << (n_comm+1));
		
	}
}
//nvram_l(3);
return res & 0x1F;

}

//uint32 Cmp_



//----------------------------------------------------------------------------
uint32 TestObmenDOZU_N_SP(uint32 n_comm, kdg_rez_test* result)
{

int error = 0;
uint32 sh_d = SH_DOZU/8;

#ifdef TPO_M711B
uint32 start_adr = 0x100;
#else
uint32 start_adr = 0;
#endif
uint32 n_c;

#ifdef TPO5
uint32 buf_wr[LEN_BUF_FOR_TEST_DOZU];
uint32 buf_rd[LEN_BUF_FOR_TEST_DOZU];
#define	DAT555	0x55555555
#define	DATAAA	0xAAAAAAAA
uint32 one = 1;
#else
uint64 buf_wr[LEN_BUF_FOR_TEST_DOZU];
uint64 buf_rd[LEN_BUF_FOR_TEST_DOZU];
#define	DAT555	0x5555555555555555
#define	DATAAA	0xAAAAAAAAAAAAAAAA
uint64 one = 1;
#endif
	for(int i = 0; i < SH_DOZU; i++)
		buf_wr[i] = one << i;

	for(int i = SH_DOZU; i < LEN_BUF_FOR_TEST_DOZU; i+=2)
	{
		buf_wr[i] = DAT555;
		buf_wr[i+1] = DATAAA;
	}

	WriteDARAM(n_comm, start_adr, buf_wr, LEN_DUZU_FOR_TEST);

	
	error = Send_Start_N_Test(n_comm, TEST_DOZU);
	if(error == MSG_ER_TIME_OUT)
	{
		gl_result.err = COMM_TIME_OUT + n_comm;
		return error;
	}
	if(error == MSG_ER_SYNC)
	{
		gl_result.err = COMM_ERR_MSG + n_comm;
		return error;
	}

	error = receive_msg_comm(result, &n_c, sizeof(kdg_rez_test), MSG_WAIT_10);
	if(error == MSG_ER_TIME_OUT)
	{
		gl_result.err = COMM_TIME_OUT + n_comm;
		return error;
	}
	if(error == MSG_ER_SYNC)
	{
		gl_result.err = COMM_ERR_MSG + n_comm;
		return error;
	}

	if( result->rez != TPO_OK )
		return	result->rez;

//define ERR_DOZU_WRCP_RDSP	2// ошибка записи ЦП? чтения СП
//#define ERR_DOZU_WRSP_RDCP	3// ошибка записи СП? чтения ЦП

	ReadDARAM(n_comm, start_adr, buf_rd, LEN_DUZU_FOR_TEST);

	for(int i = 0; i < SH_DOZU; i++)
	{
		if(buf_rd[i] != one << i)
		{
		result->data = buf_rd[i] ^ buf_wr[i];
		result->adrr = (i * sh_d) + start_adr;
		return	ERR_DOZU_WRSP_RDCP;
		}
	}

	for(int i = SH_DOZU; i < LEN_BUF_FOR_TEST_DOZU; i+=2)
	{
		if(buf_rd[i] != DAT555)
		{
		result->data = buf_rd[i] ^ buf_wr[i];
		result->adrr = (i * sh_d) + start_adr;
		return	ERR_DOZU_WRSP_RDCP;
		}
		if(buf_rd[i+1] != DATAAA)
		{
		result->data = buf_rd[i+1] ^ buf_wr[i+1];
		result->adrr = ((i+1) * sh_d) + start_adr;
		return	ERR_DOZU_WRSP_RDCP;
		}
	}

/*	if(memcmp(buf_wr, buf_rd, LEN_DUZU_FOR_TEST))
		return	TPO_ERR;
*/
return	TPO_OK;
}



//----------------------------------------------------------------------------
uint32 TestObmenDOZU()
{

uint32 res = 0;
kdg_rez_test result;
memset(&result, 0, sizeof(kdg_rez_test));

//#ifdef TPO7		//Debug	ДОЗУ пока нет
//return 0;
//#endif

//nvram_l(4);

	if(D)
	{
		for(uint32 i = MIN_NUMBER_COMM; i<NUMBER_COMM_DSP ; i++)
		{
			if(TestObmenDOZU_N_SP(i, &result))
			res |= 1 << i;		
		}
	}
	else
	{
		for(uint32 i = MIN_NUMBER_COMM; i<NUMBER_COMM_DSP ; i++)
		res |= 1 << i;		
	}

return res;
//nvram_l(5);

}



//----------------------------------------------------------------------------
uint32 TestMoveDOZU_N_SP(uint32 n_comm, kdg_rez_test* result)
{

int error = 0;
//kdg_rez_test result;
#ifdef TPO_M711B
uint32 start_adr = 0x100;
#else
uint32 start_adr = 0;
#endif
uint32 n_c = 0;
/*
#ifdef TPO7
return 0;
#endif
*/
	error = Send_Start_N_Test(n_comm, TEST_MOVE);
	if(error == MSG_ER_TIME_OUT)
	{
		gl_result.err = COMM_TIME_OUT + n_comm;
		return error;
	}
	if(error == MSG_ER_SYNC)
	{
		gl_result.err = COMM_ERR_MSG + n_comm;
		return error;
	}

	error = receive_msg_comm(result, &n_c, sizeof(kdg_rez_test), MSG_WAIT_10);
	if(error == MSG_ER_TIME_OUT)
	{
		gl_result.err = COMM_TIME_OUT + n_comm;
		return error;
	}
	if(error == MSG_ER_SYNC)
	{
		gl_result.err = COMM_ERR_MSG + n_comm;
		return error;
	}

	if( result->rez != 0 )
		return	TPO_ERR;

#ifndef TPO7
	ChStartMove(n_comm, start_adr, n_comm, start_adr, LEN_DUZU_FOR_TEST);
	ChWaitEndMove();
#endif

	error = Send_Start_N_Test(n_comm, TEST_MOVE_ST1);
	if(error == MSG_ER_TIME_OUT)
	{
		gl_result.err = COMM_TIME_OUT + n_comm;
		return error;
	}
	if(error == MSG_ER_SYNC)
	{
		gl_result.err = COMM_ERR_MSG + n_comm;
		return error;
	}

	error = receive_msg_comm(result, &n_c, sizeof(kdg_rez_test), MSG_WAIT_10);
	if(error == MSG_ER_TIME_OUT)
	{
		gl_result.err = COMM_TIME_OUT + n_comm;
		return error;
	}
	if(error == MSG_ER_SYNC)
	{
		gl_result.err = COMM_ERR_MSG + n_comm;
		return error;
	}

	if( result->rez != 0 )
		return	ERR_DOZUMOVE_WRSP_RDSH;

return	TPO_OK;
}


//----------------------------------------------------------------------------
uint32 TestMoveDOZU()
{

uint32 res = 0;
kdg_rez_test result;
memset(&result, 0, sizeof(kdg_rez_test));

/*
#ifdef TPO7		//Debug	ДОЗУ пока нет
return 0;
#endif
*/
	if(D)
	{
		for(int i = MIN_NUMBER_COMM; i<NUMBER_COMM_DSP ; i++)
		{
			if(TestMoveDOZU_N_SP(i, &result))
			res |= 1 << i;		
		}
	}
	else
	{
		for(int i = MIN_NUMBER_COMM; i<NUMBER_COMM_DSP ; i++)
		res |= 1 << i;		
	}

return res;

}



uint32 TestSK_N_SP(uint32 n_comm)
{

int error = 0;
kdg_rez_test result;
uint32 n_c;

	error = Send_Start_N_Test(n_comm, TEST_SK);
	if(error == MSG_ER_TIME_OUT)
	{
		gl_result.err = COMM_TIME_OUT + n_comm;
		return error;
	}
	if(error == MSG_ER_SYNC)
	{
		gl_result.err = COMM_ERR_MSG + n_comm;
		return error;
	}

	error = receive_msg_comm(&result, &n_c, sizeof(kdg_rez_test), MSG_WAIT_10);
	if(error == MSG_ER_TIME_OUT)
	{
		gl_result.err = COMM_TIME_OUT + n_comm;
		return error;
	}
	if(error == MSG_ER_SYNC)
	{
		gl_result.err = COMM_ERR_MSG + n_comm;
		return error;
	}

	if( result.rez != 0 )
		return	result.rez;

return	TPO_OK;

}

uint32 TestSK()
{

uint32 res = 0;

	if(D)
	{
#ifndef TPO_M711B
		for(int i = MIN_NUMBER_COMM; i<NUMBER_COMM_DSP ; i++)
		{
			if(TestSK_N_SP(i))
			res |= 1 << i;		
		}

#else
		for(int i = MIN_NUMBER_COMM; i<(NUMBER_COMM_DSP-1) ; i++)
		{
			if(TestSK_N_SP(i))
			res |= 1 << i;		
		}

#endif	
	}
	else
	{
		for(int i = MIN_NUMBER_COMM; i<NUMBER_COMM_DSP ; i++)
		res |= 1 << i;		
	}

return res;

}



//----------------------------------------------------------------------------
//циклич тесты
void BeginTest(uint32 Dnsd, uint32 Count)
//void BeginTest(uint32 Dnsd)
{
//uint32 Count = 1;//!!!!!!!!!!!1

	int res=0;
	SP=0;
	SK=0;
	INTR=0;
	DOZU=0;
	COMM_DOZU_COMM=0;
	NVRAM=0;
	SDRAM=0;
	USB=0;
	ResAllTest=0;

	kdg_rez_test result237;
	memset(&result237, 0, sizeof(kdg_rez_test));        
//!!!!!!!!!!!!!!!!!!!!
//return;

syn_begin();
syn_end();
	res = TestCelostnost();
	ResAllTest |= (res & 0x1F);


syn_begin();
syn_end();
	res = TestSDRAM();
	SDRAM = res;
	res = (res << 5) & 0x20;
	ResAllTest |= res;


syn_begin();
syn_end();
	res = TestNVRAM();
	NVRAM = res;
	res = (res << 6) & 0xC0;
	ResAllTest |= res;

syn_begin();
syn_end();
	res = F_test_usbc();
	USB = res;
	res = (res << 8) & 0x100;
	ResAllTest |= res;



syn_begin();
syn_end();


	if((Count<10)||((Count&0x7)==0))
		res = F_test_usb_flash1();
	else
		res = 0;
	
	USB |= (res << 1);
	res = (res << 9) & 0x200;
	ResAllTest |= res;

#ifndef TPO7

//nvram_l(10);
syn_begin();
syn_end();
	res = TestObmenDOZU();
	DOZU = res;
	res = (res << 11) & 0x7800;
	ResAllTest |= res;


syn_begin();
syn_end();
	res = TestMoveDOZU();
	COMM_DOZU_COMM = res;
	res = (res << 15) & 0x78000;
	ResAllTest |= res;


#endif

syn_begin();
syn_end();
	res = TestSK();
	SK = res;
	res = (res << 19 )& 0x780000;
	ResAllTest |= res;

#ifdef TPO5
if(Dnsd & 0x1)
{
syn_begin();
syn_end();
	res = F_test_dnsd_vd(2, &result237);
//	SK = res;
	res = (res << 23 )& 0x800000;
	ResAllTest |= res;
}
#endif

#ifdef TPO_M711B

if(Dnsd & 0x2)
{
syn_begin();
syn_end();

	if((Count<10)||((Count&0x7)==0))
		res = F_test_usb_flash3();
	else
		res = 0;
	res = (res << 23 )& 0x800000;
	ResAllTest |= res;


syn_begin();
syn_end();
	if((Count<10)||((Count&0x7)==0))
		res = F_test_CDROM();
	else
		res = 0;
	res = (res << 25 )& 0x2000000;
	ResAllTest |= res;


}

syn_begin();
syn_end();
	if((Count<10)||((Count&0x7)==0))
		res = F_test_SSD();
	else
		res = 0;
	res = (res << 24 )& 0x1000000;
	ResAllTest |= res;


syn_begin();
syn_end();
	res = F_celostnost_056();
	res = (res << 26 )& 0x4000000;
	ResAllTest |= res;

syn_begin();
syn_end();
	res = TestSDRAM_056();
	res = (res << 27) & 0x8000000;
	ResAllTest |= res;

#endif


/*
	if(status_sparca&PLIS_IS_LOAD)
	{
		res = TestGostAB(5);//Тест шины ЦП-Ш
		if(res) res=(1<<2);
		ResAllTest|=res;
	}
*/

/*
	TestSparca6412();
	tst=(tst<<22)&0x3C00000;
	ResAllTest|=tst;

	StartSynced();
	ResAllTest=ResAllTest<<16|ResAllTest>>16;
	EndSynced();
*/
//end_cikl:

return;
}


/*****************************************************************************
Syntax:  void Start_Test_N(kdg_rez_test* result)	    
Remarks:			    
*******************************************************************************/

void Start_Test_N(kdg_rez_test* result)
{
    switch (result->n_test)
    {
      case CELOSTN:
	  {
		result->rez = analysis_hash_fwmem(hwindow);
		return;
	  }

      case TEST_SDRAM:
	  {
		result->rez = TestSDRAM();
		return;
	  }

      case TEST_NVRAM:
	  {
		result->rez = TestNVRAM();
		return;
	  }

      case TEST_USB_CONTR:
	  {
		result->rez = F_test_usbc();
		return;
	  }

      case TEST_USB_FLASH:
	  {
		result->rez = F_test_usb_flash1();
		return;
	  }
#ifdef TPO5
      case TEST_DNSD_CRC:
	  {
		//result->rez = 
		F_test_dnsd_crc(result);
		return;
	  }

      case TEST_DNSD_VD10:
	  {
		result->rez = F_test_dnsd_vd(0, result);
		return;
	  }

	  case TEST_DNSD_VD11:
	  {
		result->rez = F_test_dnsd_vd(1, result);
		return;
	  }

	  case ZAVESTI_DNSD:
	  {
		F_zavesti_dnsd(result);
		return;
	  }

      case PROCHITAT:
	  {
		F_dnsd_prochitat(result);
		return;
	  }

      case VKL_VD10:
	  {
		F_dnsd_vkl_vd(0);
		return;
	  }

	  case VKL_VD11:
	  {
		F_dnsd_vkl_vd(1);
		return;
	  }

	  case VIKL_VD11:
	  {
		F_dnsd_vikl_vd(1);
		return;
	  }

	  case TEST_DNSD_OSVESCH:
	  {
		F_test_dnsd_lux(result);
		return;
	  }
	  case MAGIC_NUMBER:
	  {
		F_test_dnsd_magic(result);
		return;
	  }

#endif
      case TEST_DOZU:
	  {
		ResNTest = 0;
		Start_n_test = TEST_DOZU;
		while(Start_n_test == TEST_DOZU);
		memcpy(result, &gl_result, sizeof(kdg_rez_test));
		result->rez = ResNTest;
		result->n_test = TEST_DOZU;
		return;
	  }

	  case TEST_DOZU_ST1:
	  {
		ResNTest = 0;
		Start_n_test = TEST_DOZU_ST1;
		while(Start_n_test == TEST_DOZU_ST1);
		memcpy(result, &gl_result, sizeof(kdg_rez_test));
		result->rez = ResNTest;
		result->n_test = TEST_DOZU_ST1;
		return;
	  }

	  case TEST_DOZU_ST2:
	  {
		ResNTest = 0;
		Start_n_test = TEST_DOZU_ST2;
		while(Start_n_test == TEST_DOZU_ST2);
		memcpy(result, &gl_result, sizeof(kdg_rez_test));
		result->rez = ResNTest;
		result->n_test = TEST_DOZU_ST2;
		return;
	  }

      case TEST_MOVE:
	  {
		ResNTest = 0;
		Start_n_test = TEST_MOVE;
		while(Start_n_test == TEST_MOVE);
		memcpy(result, &gl_result, sizeof(kdg_rez_test));
		result->rez = ResNTest;
		result->n_test = TEST_MOVE;
		return;
	  }

	  case TEST_MOVE_ST1:
	  {
		ResNTest = 0;
		Start_n_test = TEST_MOVE_ST1;
		while(Start_n_test == TEST_MOVE_ST1);
		memcpy(result, &gl_result, sizeof(kdg_rez_test));
		result->rez = ResNTest;
		result->n_test = TEST_MOVE_ST1;
		return;
	  }

	  case TEST_MOVE_ST2:
	  {
		ResNTest = 0;
		Start_n_test = TEST_MOVE_ST2;
		while(Start_n_test == TEST_MOVE_ST2);
		memcpy(result, &gl_result, sizeof(kdg_rez_test));
		result->rez = ResNTest;
		result->n_test = TEST_MOVE_ST2;
		return;
	  }

#ifdef TPO_M711B
	  case CELOSTN_PP056:
	  {
		result->rez = F_celostnost_056();
		return;
	  }
	  case TEST_USB3:
	  {
		result->rez = F_test_usb_flash3();
		return;
	  }
	  case TEST_CDROM:
	  {
		result->rez = F_test_CDROM();
		return;
	  }
	  case TEST_RAID:
	  {
		result->rez = F_test_SSD();
		return;
	  }
#endif // TPO_M711B


	  default:
		result->rez = TPO_ERR;
		return;
	}
}





uint32 Chek_usb_dev(uint32 dev)
{

char devv[16];

uint32 file;

//if(dev == 1)
//strcpy(devv,"/vfat/a");

//if(dev == 2)
strcpy(devv,"/vfat/a");


file = drv_mkd(devv);
 if(file != RES_VOID)
 {
	drv_rmd(file);
	return TPO_OK;
 }

drv_rmd(file);
return TPO_ERR;
}

/*
uint32 Chek_usb_dev(uint32 dev)
{

char devv[6];

//uint16 KEY;
uint32 ms;
uint32 res;
s_inode* 		list;

if(dev == 1)
strcpy(devv,"msd12");

if(dev == 2)
strcpy(devv,"msd13");

ms = drv_mkd("/dev/usb");
//ms = drv_mkd("/dev");
if(ms != NULL)
{
res = drv_ioctl(ms, IOC_INODE_LIST, &list);
drv_rmd(ms);

  if(res == OSE_OK)
  {
	if(list->next != NULL)
	{
		if(!(memcmp(list->next->name, devv, 5)))
			return TPO_OK;
		if(list->next->next != NULL)
		{
			if(!(memcmp(list->next->next->name, devv, 5)))
				return TPO_OK;
		}
	}
  }
}

return TPO_ERR;
}
*/

void About_usb()
{

	char devv[6];
	char* name;

	uint32 d = 0;
	s_vfat_info info;
	
	uint32 ms;
	s_msd_capacity  capacity;
    s_msd_vendor    vendor;

	about_usb str_flash;

	memset(&str_flash, 0, sizeof(about_usb));
	memset(&capacity, 0, sizeof(s_msd_capacity));
	memset(&vendor, 0, sizeof(s_msd_vendor));

	uint32 device_id = 2;

	uint16 *ne = (uint16*)0x60000000;  
	uint16 nec = *ne;  

	if(Chek_usb_dev(device_id) == TPO_OK) 
	{

//	    if(device_id == 1)
//		{
//		   	strcpy(file_path, "/vfat/a/test1.bin");
			if(nec == 0x0120)
			strcpy(devv,"msd11");
			else
			strcpy(devv,"msd13");
    		d = drv_mkd( "/vfat/a" );
//		}
//	    if(device_id == 2)
//		{
//	    	strcpy(file_path, "/vfat/b/test1.bin");
//			strcpy(devv,"msd13");
//  		d = drv_mkd( "/vfat/b" );
//		}


   		ms = drv_mkd("/dev/sd2u0");
	    drv_ioctl(ms, MSD_DEVICE_NAME, &name);

		if(memcmp(name, devv, 5))
		{
   			drv_rmd(ms);
	   		ms = drv_mkd("/dev/sd3u0");
		}

					
	    drv_ioctl(ms, MSD_VENDOR, &vendor);
		drv_ioctl(ms, MSD_CAPACITY, &capacity);
		drv_rmd(ms);

//для определения ФС

		if( d != RES_VOID )
		{
			if( drv_ioctl( d, FSI_TYPE, &info ) != OSE_OK )
			info.type = 0xFF;

			drv_rmd(d);
		}

		switch( info.type )
		{
			case FS_NO:	  strcpy(str_flash.fstr,"НЕТ");
						  break;					    
			case FS_FAT12:strcpy(str_flash.fstr,"FAT12");
						  break;
			case FS_FAT16:strcpy(str_flash.fstr,"FAT16");
						  break;	
			case FS_FAT32:strcpy(str_flash.fstr,"FAT32");
						  break;
			default:strcpy(str_flash.fstr,"ERROR");

		}
	str_flash.enable = ENABLE_FLASH;
	}
	else
	str_flash.enable = DISABLE_FLASH;

	memcpy(	str_flash.vendor_identification, vendor.vendor_identification, (sizeof(vendor.vendor_identification)));
	memcpy(	str_flash.product_identification, vendor.product_identification, (sizeof(vendor.product_identification)));
	memcpy(	str_flash.product_revision_level, vendor.product_revision_level, (sizeof(vendor.product_revision_level)));

	str_flash.block_length = capacity.block_length;
	str_flash.flash_capacity = capacity.flash_capacity;

	WriteDARAM(MIN_NUMBER_COMM, 0, &str_flash, sizeof(about_usb));

}


#ifdef TPO5
//тест тока для 5ки
void TestDOZU_Nagr() 
{
//memset(&gl_result, 0, sizeof(gl_result));
#define L 0x300/4

uint32 error0=0;
uint32 error1=0;

uint32 buf0[L]; 
uint32 buf1[L]; 

//unsigned char X = 0;
  memset(buf0,0,sizeof(buf0));
  memset(buf1,0,sizeof(buf1));

//  WriteDARAM_test(0,0,buf0,32*4);
//  WriteDARAM_test(1,0,buf0,32*4);

//memcpy((uint32*)0x80000000,buf0,32*4);

WriteDARAM(0,4,buf0,4);
WriteDARAM(1,4,buf1,4);
do
{
ReadDARAM(0,0,buf0,4);
ReadDARAM(1,0,buf1,4);
}
while((buf0[0] != 0x5a5a5a5a) | (buf1[0] != 0x5a5a5a5a));

WriteDARAM(0,0,buf0,4);
WriteDARAM(1,0,buf1,4);

while(Start_dozu_nagr)
{

  memset(buf0,0,sizeof(buf0));
  memset(buf1,0,sizeof(buf1));
  do
  {
	if(!Start_dozu_nagr)
		return;
   ReadDARAM(0,4,buf0,4);
   ReadDARAM(1,4,buf1,4);
  }
  while((buf0[0]==0)|(buf1[0]==0));

syn_begin();

  ReadDARAM(0,4,buf0,L*4);
  ReadDARAM(1,4,buf1,L*4);

syn_end();
//  WriteDARAM(0,buf,64);
//  X=buf[1];

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

  WriteDARAM(0,0,&error0,4);
  WriteDARAM(1,0,&error1,4);

  for (int i=2;i<L;i++)
   buf0[i]=buf0[i-1]*0x66467329+0xA6549873;

   memcpy(buf1, buf0, sizeof(buf1));

syn_begin();

buf0[0]=0;
buf1[0]=0;
  WriteDARAM(0,4,buf0,L*4);
  WriteDARAM(1,4,buf1,L*4);
buf0[0]=1;
buf1[0]=1;
  WriteDARAM(0,4,buf0,4);
  WriteDARAM(1,4,buf1,4);

syn_end();


  do
  {
	if(!Start_dozu_nagr)
		return;
   ReadDARAM(0,4,buf0,4);
   ReadDARAM(1,4,buf1,4);
  }
  while((buf0[0]==1)|(buf1[0]==1));

buf0[0]=0;
buf1[0]=0;
  WriteDARAM(0,4,buf0,4);
  WriteDARAM(1,4,buf1,4);

}

}
#else
void TestDOZU_Nagr() 
{
return;
}
#endif

#ifndef TPO7
//-------------------------------------------------------------------------
void Test_ROM() 
{
#define LO 512

int32   fwm_file, error;
//uint32  length;
fwmem_rwbuf fwrw;

uint32 N = 0;
uint32 error0=0;
uint32 error1=0;
uint32 error_cpy=0;

uint8 buf0[LO]; 
uint8 buf1[LO]; 

  WriteDARAM(0,0,&error0,4);
  WriteDARAM(0,4,&error1,4);
  WriteDARAM(0,8,&error1,4);
  WriteDARAM(0,0xc,&error1,4);

  memset(buf0,0,sizeof(buf0));
  memset(buf1,0,sizeof(buf1));

  fwm_file = drv_mkd("/fwmem");

  
//debug!!!!!!!!!!
uint32 n=0;
char	file_path[32];
FILE*	file;
//debug!!!!!!!!!!
uint8* rom = (uint8*)0x64000000; 
uint32* emiBfcegtl1 = (uint32*)0x1A80004;

uint32 data=*emiBfcegtl1;
data = 0x2520CA03; 
*emiBfcegtl1 = data;

uint32 gpv1 = 0;
uint32 gpv2 = 0;
uint32 gpv3 = 0;

while(Start_tst_rom)
{

	for(uint32 i=0; i < 0x400000; i+=LO)
	{
	gpv1 = REG_GPVAL;
    error = drv_ioctl(fwm_file, FWMEM_SET_OFFSET, &i);
    fwrw.buffer = buf0;
    fwrw.length = sizeof(buf0);
    error = drv_ioctl(fwm_file, FWMEM_READ, &fwrw);

	gpv2 = REG_GPVAL;

    error = drv_ioctl(fwm_file, FWMEM_SET_OFFSET, &i);
    fwrw.buffer = buf1;
    fwrw.length = sizeof(buf1);
    error = drv_ioctl(fwm_file, FWMEM_READ, &fwrw);

	gpv3 = REG_GPVAL;

	if(memcmp(buf0,buf1,sizeof(buf0)))
	{

   	sprintf(file_path, "/vfat/a/buf0_%d_%x_%x_%x_%x.bin",N,i,gpv1,gpv2,gpv3);
    file = fopen(file_path, "w");
    fwrite(buf0, 1, sizeof(buf0), file);
	fclose(file);

   	sprintf(file_path, "/vfat/a/buf1_%d_%x.bin",N,i);
    file = fopen(file_path, "w");
    fwrite(buf1, 1, sizeof(buf1), file);
	fclose(file);
	n++;

	error0++;
	}
/*
    register uint32 is = int_disable();
	memcpy(buf0,rom+i,sizeof(buf0));
	memcpy(buf1,rom+i,sizeof(buf1));
    int_enable( is );

	if(memcmp(buf0,buf1,sizeof(buf0)))
	{
   	sprintf(file_path, "/vfat/a/buf0cpy_%d_%x.bin",N,i);
    file = fopen(file_path, "w");
    fwrite(buf0, 1, sizeof(buf0), file);
	fclose(file);

   	sprintf(file_path, "/vfat/a/buf1cpy_%d_%x.bin",N,i);
    file = fopen(file_path, "w");
    fwrite(buf1, 1, sizeof(buf1), file);
	fclose(file);
	n++;

	error_cpy++;
	}
*/
	}	


//	if(analysis_hash_fwmem(hwindow))
//	error1++;

syn_begin();

  N++;
  WriteDARAM(0,0,&N,4);
  WriteDARAM(0,4,&error0,4);
  WriteDARAM(0,8,&error1,4);
  WriteDARAM(0,0xc,&error_cpy,4);

syn_end();


}

drv_rmd(fwm_file);
}



//#define LEN_MOVE 0x800

void Test_MOVE()
{
uint32 res = 0;

while(Start_move)
{

//	for(int i = MIN_NUMBER_COMM; i<NUMBER_COMM_DSP ; i++)
//	{
	ChStartMove(1, 0, 0, 0, LEN_MOVE);
ChWaitEndMove();
	ChStartMove(0, 0, 1, 0, LEN_MOVE);
	res = Send_cmd_comm(1, GOTOV_TEST_MOVE_15);
	res = Send_cmd_comm(0, GOTOV_TEST_MOVE_15);
ChWaitEndMove();

	ChStartMove(1, LEN_MOVE, 0, LEN_MOVE, LEN_MOVE);
ChWaitEndMove();
	ChStartMove(0, LEN_MOVE, 1, LEN_MOVE, LEN_MOVE);
	res = Send_cmd_comm(1, GOTOV_TEST_MOVE_25);
	res = Send_cmd_comm(0, GOTOV_TEST_MOVE_25);
ChWaitEndMove();
//	}

//	for(int i = MIN_NUMBER_COMM; i<NUMBER_COMM_DSP ; i++)
//	{
	ChStartMove(1, 0, 0, 0, LEN_MOVE);
ChWaitEndMove();
	ChStartMove(0, 0, 1, 0, LEN_MOVE);
	res = Send_cmd_comm(1, GOTOV_TEST_MOVE_1A);
	res = Send_cmd_comm(0, GOTOV_TEST_MOVE_1A);
ChWaitEndMove();

	ChStartMove(1, LEN_MOVE, 0, LEN_MOVE, LEN_MOVE);
ChWaitEndMove();
	ChStartMove(0, LEN_MOVE, 1, LEN_MOVE, LEN_MOVE);
	res = Send_cmd_comm(1, GOTOV_TEST_MOVE_2A);
	res = Send_cmd_comm(0, GOTOV_TEST_MOVE_2A);
ChWaitEndMove();

//	}
//	for(int i = MIN_NUMBER_COMM; i<NUMBER_COMM_DSP ; i++)
//	{
//prc_yield();
//	}
}
}
#endif
