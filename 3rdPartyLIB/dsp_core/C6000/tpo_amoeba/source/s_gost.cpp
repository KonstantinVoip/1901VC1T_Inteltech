/**********************************************************************************************************************
*                                        (c) COPYRIGHT by ZAO RCZI FORT.                                             *
*        ..                                       All rights reserved.                                               *
***********************************************************************************************************************
* Module      : s_gost.cpp
* Description : Программная Реализация Алгоритмов Шифрования на Центральном Процессоре.
* Author      : 
******************************************************************************
******************************************************************************
* Module's Description Record:
* ============================
* Module's revision history:
* ==========================
* --------- $Log:  $
* --------- Initial revision
******************************************************************************/











#include <rts.h>
#include <gost_89.h>
#include "soft_crypt.h"

extern void ReadDARAM(uint16 n_comm,uint16 addr,void* buf,uint16 len);
//----------------------------------------------------------------------------
extern void WriteDARAM(uint16 n_comm,uint16 addr,void* buf,uint16 len);

uint64 ch_h;
uint64 ch_add;
char ch_buf[2048];
char slb_buf[16];

GOST_CTX ab_ctx;
GOST_CTX upz_ctx;
GOST_CTX ch_ctx;
GOST_CTX ki_ctx;

//---------------------------------------------------------------------------------------------------------------
void xor_n(void* key,uint64 t)
{
uint64* k=(uint64*)key;

//t=swab64(t);
t=swap64b(t);
_mem8(k)=_mem8(k)^t;
k++;
_mem8(k)=_mem8(k)^t;
k++;
_mem8(k)=_mem8(k)^t;
k++;
_mem8(k)=_mem8(k)^t;
}
//---------------------------------------------------------------------------------------------------------------
uint64 h2uint(uint16* h)
{
uint64 t=(((uint64)h[0])<<32)+((uint64)h[1]<<16)+(uint64)h[2];
return t;
}
//---------------------------------------------------------------------------------------------------------------
void sModS(uint64 t,void* work_key)
{
	KEY T,K;

	//uint64 t=h2uint(h);
	t&=(~0x7ull);
	memcpy(T,work_key,sizeof(KEY));
	xor_n(T,t);

	memcpy(K, (unsigned char*)work_key+2, 30);//<<16
	memcpy((char*)K+30, (unsigned char*)work_key, 2);
	xor_n(K,t);

	sUpzLoadKey(K);
	sUpzEncrypt(T,32);

	memcpy(work_key,T,sizeof(KEY));
}

//---------------------------------------------------------------------------------------------------------------
void sUpzLoadBP(void* bp)
{
	memcpy(&upz_ctx.uzb,bp,sizeof(upz_ctx.uzb));
}
//---------------------------------------------------------------------------------------------------------------
void sUpzLoadKey(void* key)
{
	GostCtxSetKey(&upz_ctx,key);
}
//---------------------------------------------------------------------------------------------------------------
void sUpzEncrypt(void* text,uint16 len)
{
	GostEncrypt(&upz_ctx,text,len/8);
}
//---------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------
void sAbLoadBP(void* bp)
{
	memcpy(&ab_ctx.uzb,bp,sizeof(ab_ctx.uzb));
}
//---------------------------------------------------------------------------------------------------------------
void sAbLoadKey(void* key)
{
	GostCtxSetKey(&ab_ctx,key);
}
//---------------------------------------------------------------------------------------------------------------
void sAbEncrypt(void* text,uint16 len)
{
	GostEncrypt(&ab_ctx,text,len/8);
}
//---------------------------------------------------------------------------------------------------------------
void sAbDecrypt(void* text,uint16 len)
{
	GostDecrypt(&ab_ctx,text,len/8);
}
//---------------------------------------------------------------------------------------------------------------
uint32 sAbImit(void* text,uint16 len)
{
	uint32 imv;
	imv = GostCreateImit(&ab_ctx,text,&imv,len);

	return imv;
}
//---------------------------------------------------------------------------------------------------------------
void sAbGamma(void* sync, void* text, uint16 len)
{
	GostGamma(&ab_ctx,sync,text,len);
}

//---------------------------------------------------------------------------------------------------------------
void sChLoadBP( void* bp )
{
	memcpy(&ch_ctx.uzb,bp,sizeof(ch_ctx.uzb));
	memcpy(&ki_ctx.uzb,bp,sizeof(ki_ctx.uzb));
}
//---------------------------------------------------------------------------------------------------------------
void sChSetKi( void* key )
{
	GostCtxSetKey(&ki_ctx,key);
}
//---------------------------------------------------------------------------------------------------------------
void sChSetKb( uint16 keynum, void* key, uint64 h )
{
	memcpy(&ch_h,&h,sizeof(h));
	GostCtxSetKey(&ch_ctx,key);
}
//---------------------------------------------------------------------------------------------------------------
void sChSetAdd( uint64 add)
{
	memcpy(&ch_add,&add,sizeof(add));
}
//---------------------------------------------------------------------------------------------------------------
void sChSetStartSync(uint64 sync)
{
	memcpy(ch_ctx.sync,&sync,sizeof(sync));
}
//---------------------------------------------------------------------------------------------------------------
void sChCrypt( uint16 dst_pnum, uint16 dst_addr, uint16 src_pnum, uint16 src_addr, uint16 length, uint16 keynum )
{
	uint64 ch_sync;
	uint64 f_block=0;
	uint32 ch_imv = 0;
	char slb_data[16];
	
	memset(ch_buf,0,sizeof(ch_buf));

	memcpy(ch_buf,&ch_ctx.sync,8);//Копирование в ch_buf sync
	memcpy(&ch_sync,&ch_ctx.sync,8);

	ReadDARAM(src_pnum,src_addr,(ch_buf+8),length);

	ch_imv = GostCreateImit(&ch_ctx,ch_buf,&ch_imv,length+8);

	GostGamma(&ch_ctx,&ch_sync,(ch_buf+8),length);

//	ch_h = swab64(ch_h);
	ch_h = swap64b(ch_h);
	
	f_block = ((ch_h&0xFFFFFFFFFFFF0000)>>16)|((ch_add&0xFF0000)<<40)|(ch_sync&0x00FF000000000000);
	
	memcpy((slb_data),&f_block,8);
	memcpy((slb_data+8),&ch_sync,8);//Копирование из ch_buf sync
	memxor(slb_data,slb_data,(ch_buf+8),8);

	GostEncrypt(&ki_ctx,slb_data,2);

	memcpy((ch_buf+8+length),slb_data,16);
	memcpy((ch_buf+8+length+16),&ch_imv,4);

	WriteDARAM(dst_pnum,dst_addr,(ch_buf+8),length+20);
}
//---------------------------------------------------------------------------------------------------------------
void sChCryptCP(uint16 dst_pnum, uint16 dst_addr, void *src_buf, uint16 length, uint16 keynum)
{
	uint64 ch_sync;
	uint64 f_block=0;
	uint32 ch_imv = 0;
	char slb_data[16];

	memcpy(ch_buf,&ch_ctx.sync,8);//Копирование в ch_buf sync
	memcpy(&ch_sync,&ch_ctx.sync,8);
	memcpy((ch_buf+8),src_buf,length);//Копирование src_buf в ch_buf

	ch_imv = GostCreateImit(&ch_ctx,ch_buf,&ch_imv,length+8);

	GostGamma(&ch_ctx,&ch_sync,(ch_buf+8),length);

//	ch_h = swab64(ch_h);
	ch_h = swap64b(ch_h);
	
	f_block = ((ch_h&0xFFFFFFFFFFFF0000)>>16)|((ch_add&0xFF0000)<<40)|(ch_sync&0x00FF000000000000);
	
	memcpy((slb_data),&f_block,8);
	memcpy((slb_data+8),&ch_sync,8);//Копирование из ch_buf sync
	memxor(slb_data,slb_data,(ch_buf+8),8);

	GostEncrypt(&ki_ctx,slb_data,2);

	memcpy((ch_buf+8+length),slb_data,16);
	memcpy((ch_buf+8+length+16),&ch_imv,4);

	WriteDARAM(dst_pnum,dst_addr,(ch_buf+8),length+20+1);
}

//---------------------------------------------------------------------------------------------------------------
uint16 sChDecryptCP(uint16 src_pnum, uint16 src_addr, void *dst_buf, uint16 length, uint16 keynum)
{
	uint64 ch_sync;
	uint32 ch_imv = 0;

	memset(ch_buf,0,sizeof(ch_buf));
	memcpy(slb_buf,&ch_ctx.sync,8);
	memcpy(&ch_sync,&ch_ctx.sync,8);

	ReadDARAM(src_pnum,src_addr,(ch_buf+8),length+20);

	GostGamma(&ch_ctx,&ch_sync,(ch_buf+8),length);
	
	ch_imv = GostCreateImit(&ch_ctx,ch_buf,&ch_imv,length+8);

	memcpy(dst_buf,(ch_buf+8),length);

	if(memcmp(&ch_imv,(ch_buf+8+length+16),4))
		return 0xFF;
	else 
		return 0;
}
//---------------------------------------------------------------------------------------------------------------
uint16 sChDecrypt(uint16 dst_pnum, uint16 dst_addr, uint16 src_pnum, uint16 src_addr, uint16 length, uint16 keynum )
{
	uint64 ch_sync;
	uint32 ch_imv = 0;

	memset(ch_buf,0,sizeof(ch_buf));
	memcpy(slb_buf,&ch_ctx.sync,8);
	memcpy(&ch_sync,&ch_ctx.sync,8);

	ReadDARAM(src_pnum,src_addr,(ch_buf+8),length+20);

	GostGamma(&ch_ctx,&ch_sync,(ch_buf+8),length);
	
	ch_imv = GostCreateImit(&ch_ctx,ch_buf,&ch_imv,length+8);

	WriteDARAM(dst_pnum,dst_addr,(ch_buf+8),length);

	if(memcmp(&ch_imv,(ch_buf+8+length+16),4))
		return 0xFF;
	else 
		return 0;
}
//---------------------------------------------------------------------------------------------------------------
uint16 sChDecryptService(uint16 src_pnum, uint16 src_addr,void* service,uint16 length_pack)
{	
	ReadDARAM(src_pnum,src_addr,ch_buf,8);
	ReadDARAM(src_pnum,(src_addr+length_pack),slb_buf,16);

	GostDecrypt(&ki_ctx,slb_buf,2);
	memxor(slb_buf,slb_buf,(ch_buf),8);
	memcpy(service,slb_buf,16);		
	memcpy(&ch_ctx.sync,(slb_buf+8),8);
	return 0;	
}

//---------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------
