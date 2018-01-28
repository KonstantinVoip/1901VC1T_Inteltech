#include <os_syscall.h>
#include <drv_dbgout.h>
#include <rts.h>
#include "drv_gpio.h"
#include "crypter_17.h"

extern uint16* ptr_crypt;//Начальный адресс файла ПЛИС в ОЗУ

#define CRYPT_AB_BASE              		0xA0000000
#define CRYPT_CH_BASE              		0xB0000000

#define IMIT_ERR				0x80//Ошибка имитовставки                                	
                                	
//-------------------Флаги абонентского шифратора-----------------------
#define CRYPT_AB_BUSY  				0x0000000000000001ull
#define CRYPT_AB_READY 				0x0000000000000002ull

//----------------Комманды для абонентского шифратора-------------------
#define CMD_RG_IS_SET          			0x0000000000000001ull
#define CMD_WR_AB_BP          			0x0000000000000020ull
#define CMD_WR_AB_KEY          			0x0000000000000040ull
#define CMD_AB_ENCRYPT         			0x0000000000000080ull
#define CMD_AB_DECRYPT         			0x0000000000000100ull
#define CMD_AB_IMIT         			0x0000000000000200ull
#define CMD_AB_GAMMA        			0x0000000000000400ull
#define CMD_AB_RESET          			0x0000000000000800ull
//--------------------------------------------------------------------

//-------------------Регистры абонентского шифратора-----------------------
#define RG_BP_AB				(*(uint64*)(CRYPT_AB_BASE+(0x4000)))//Регистр ввода подстановки 0x20-0x2F
#define RG_KEY_AB      				(*(uint64*)(CRYPT_AB_BASE+(0x4080)))//Регистр ввода ключа 0x10-0x13
#define RG_SP_AB       				(*(uint64*)(CRYPT_AB_BASE+(0x40A0)))//Регистр ввода синхропосылки
                                	
#define RG_CTRL_AB	    	    		(*(uint64*)(CRYPT_AB_BASE+(0x40A8)))//Регистр управления АБ                                	
#define RG_STATUS_AB	       			(*(uint64*)(CRYPT_AB_BASE+(0x40A8)))//Регистр состояния АБ                                	
                                	
#define RG_DATA_IN_AB       			(*(uint64*)(CRYPT_AB_BASE+(0x4400)))//Регистр входных данных
#define RG_DATA_OUT_AB      			(*(uint64*)(CRYPT_AB_BASE+(0x4600)))//Регистр обработанных данных
//--------------------------------------------------------------------

#define CH_RAM_BUSY				0x0000000000000001ull//ЦП неможет писать в шифратор пакет                   	
#define CH_BUF_READY				0x0000000000000002ull//Для ЦП есть пакет от шифратора

//---------------Комманды загрузки для канального шифратора-----------------
#define CMD_WR_CH_BP           			0x0000000000000003ull//Загрузить блок подстановки
#define CMD_WR_CH_KIKEY        			0x0000000000000005ull//Загрузить ключ КИ
#define CMD_WR_CH_SP	       			0x0000000000000007ull//Загрузить синхр. посылку
#define CMD_WR_CH_LABLE	       			0x0000000000000009ull//Загрузить мандатные метки
#define CMD_WR_CH_TRANSMIT     			0x000000000000000Bull//Отправить пакет в СП
#define CMD_WR_CH_CPMOVE       			0x000000000000000Full//Передать пакет из ЦП без шифрования

//--------------------Ошибки при работе шифратора---------------------
#define CH_ERROR				0x0000000000000001ull//Общий бит ошибки
#define CH_LOSTKEY_ERROR			0x0000000000000002ull//Ключ не найден
#define CH_IMIT_ERROR				0x0000000000000004ull
                                	
#define CH_MLABLE_ERROR				0x0000000000000011ull//Ошибка слитие по мандатной метке
#define CH_CMD_MLABEL_ERROR			0x0000000000000021ull//Ошибка команды управления от ЦП

#define CH_CTRLBYTE_ERROR			0x0000000000000011ull//Ошибка контрольного байта
#define CH_M_MORE_6_ERROR			0x0000000000000021ull//М интервал h больше чем 6
#define CH_M_LESS_12_ERROR			0x0000000000000031ull//М интервал h меньше чем 12
#define CH_KVARTAL_ERROR			0x0000000000000041ull//Номер блокнота не равен номеру из КЭШа
#define CH_ZEROBIT_ERROR			0x0000000000000051ull//Ошибка в нулевых битах h
#define CH_WINDOW_ERROR				0x0000000000000061ull//h не проходит "окно"
#define CH_MTU_ERROR                            0x0000000000000071ull//Ошибка MTU, загруженная длинна некорректная
#define CH_CMD_ERROR				0x00000000000000F1ull//Шифратор не воспринял команду!

//---------------------------------------------------------------------
#define CMD_RPT_FIND_KEY       			0x0000000000000004ull//Повторить поиск ключа в КЭШ
#define CMD_RESET_PACKET       			0x0000000000000008ull//Удалить пакет
#define CMD_STOP_CRYPTER           		0x0000000000000008ull//Остановить работу шифратора\расшифратора
//---------------------------------------------------------------------

//----------------------Регистры расшифратора-------------------------
#define RG_CTRL_CH_DECRYPT			(*(uint64*)(CRYPT_CH_BASE+(0x0000)))//Регистр управления канального расшифратора
#define RG_STAT_CH_DECRYPT			(*(uint64*)(CRYPT_CH_BASE+(0x0008)))//Регистр управления канального расшифратора
#define RG_NUM_ADD_BYTE				(*(uint64*)(CRYPT_CH_BASE+(0x0010)))//Регистр числа добавленных байт
#define RG_LOAD_CH_DECRYPT         		(*(uint64*)(CRYPT_CH_BASE+(0x00F8)))//Регистр загрузки канального расшифратора
#define RG_MLABLE_ERR_CH_DECRYPT    		(*(uint64*)(CRYPT_CH_BASE+(0x0018)))//Регистр загрузки канального расшифратора

#define RG_DECRYPT_LOAD_MASK			(*(uint64*)(CRYPT_CH_BASE+0x800))//Регистр для Маски 2048 байт

#define RG_BASE_CRYPT_PACKET			(*(uint64*)(CRYPT_CH_BASE+(0x1000)))//Регистр начала расшифрованного пакета
#define RG_DECRYPT_PACKET			(*(uint64*)(CRYPT_CH_BASE+(0x1800)))//Регистр начала исходного пакета записанного СП
#define RG_CACHE_DECRYPT			(*(uint64*)(CRYPT_CH_BASE+(0x2000)))//Регистр для КЭШа канального шифратора
//--------------------------------------------------------------------
//---------------------Регистры КЭШа расшифратора-----------------------------
#define RG_CTRL_CACHE_DECRYPT			(*(uint64*)(CRYPT_CH_BASE+0x2000))//Регистр для КЭШа управление\состояние 8 байт
#define RG_LCHECK_CACHE_DECRYPT			(*(uint64*)(CRYPT_CH_BASE+0x2008))//Регистр для КЭШа загружаемые проверки 16 байт
#define RG_KIKEY_CACHE_DECRYPT			(*(uint64*)(CRYPT_CH_BASE+0x2020))//Регистр для КЭШа ключ КИ 32 байта
#define RG_IPTABLE_CACHE_DECRYPT		(*(uint64*)(CRYPT_CH_BASE+0x2040))//Регистр для КЭШа IP таблица 128 байт
#define RG_SLB_CACHE_DECRYPT			(*(uint64*)(CRYPT_CH_BASE+0x2800))//Регистр для КЭШа служебные данные 	24 байта
#define RG_WKEYS_CACHE_DECRYPT			(*(uint64*)(CRYPT_CH_BASE+0x3000))//Регистр для КЭШа Ключи 2048 байт

#define RG_HALF_PART_IPREC_DECRYPT		(*(uint64*)(CRYPT_CH_BASE+0x1FC0))//Регистр старшая часть IP записи на которой расшифрован текущий пакет
#define RG_H_DECRYPTED_PACK			(*(uint64*)(CRYPT_CH_BASE+0x1FB8))//Регистр счетчика h текущего расшифрованного пакета

//--------------------------------------------------------------------

//----------------------Регистры зашифратора--------------------------
#define RG_CTRL_CH_CRYPT			(*(uint64*)(CRYPT_CH_BASE+(0x4000)))//Регистр управления канального зашифратора
#define RG_STAT_CH_CRYPT			(*(uint64*)(CRYPT_CH_BASE+(0x4008)))//Регистр управления канального зашифратора
#define RG_LOAD_CH_CRYPT			(*(uint64*)(CRYPT_CH_BASE+(0x40F8)))//Регистр загрузки канального зашифратора

#define RG_CRYPT_LOAD_MASK			(*(uint64*)(CRYPT_CH_BASE+0x4800))//Регистр для Маски 2048 байт

#define RG_BASE_DECRYPT_PACKET			(*(uint64*)(CRYPT_CH_BASE+(0x5000)))//Регистр начала зашифрованного пакета
#define RG_CRYPT_PACKET				(*(uint64*)(CRYPT_CH_BASE+(0x5800)))//Регистр начала исходного пакета записанного СП
#define RG_CACHE_CRYPT				(*(uint64*)(CRYPT_CH_BASE+(0x6000)))//Регистр для КЭШа канального шифратора
//--------------------------------------------------------------------
//---------------------Регистры КЭШа зашифратора-----------------------------
#define RG_CTRL_CACHE_CRYPT			(*(uint64*)(CRYPT_CH_BASE+0x6000))//Регистр для КЭШа управление\состояние 8 байт
#define RG_LCHECK_CACHE_CRYPT			(*(uint64*)(CRYPT_CH_BASE+0x6008))//Регистр для КЭШа загружаемые проверки 16 байт
#define RG_MTULEN_CACHE_CRYPT			(*(uint64*)(CRYPT_CH_BASE+0x6020))//Регистр для КЭШа ключ КИ 32 байта
#define RG_IPTABLE_CACHE_CRYPT			(*(uint64*)(CRYPT_CH_BASE+0x6040))//Регистр для КЭШа IP таблица 128 байт
#define RG_SLB_CACHE_CRYPT			(*(uint64*)(CRYPT_CH_BASE+0x6800))//Регистр для КЭШа служебные данные 24 байта
#define RG_WKEYS_CACHE_CRYPT			(*(uint64*)(CRYPT_CH_BASE+0x7000))//Регистр для КЭШа Ключи 2048 байт

#define RG_H_CRYPTED_PACK			(*(uint64*)(CRYPT_CH_BASE+0x5FC0))//Регистр счетчика h текущего зашифрованного пакета
#define RG_HALF_PART_IPREC_CRYPT		(*(uint64*)(CRYPT_CH_BASE+0x5FC8))//Регистр старшая часть IP записи на которой зашифрован текущий пакет

//--------------------------------------------------------------------
//-------------------Региистры для шифрования из ЦП-------------------
#define CMD_CP_WRITE_PACKET			0x0000000000000001ull//ЦП записал пакет в память шифратора

#define RG_CUR_SYNC				(*(uint64*)(CRYPT_CH_BASE+(0x6008)))//Регистр начала текущей синхропосылки

#define RG_CTRL_CP_CRYPT			(*(uint64*)(CRYPT_AB_BASE+(0x4800)))//Регистр управления при шифр. из ЦП
#define RG_HDR_CP_IN				(*(uint64*)(CRYPT_AB_BASE+(0x4808)))//Регистр служебных данных при шифр. из ЦП
#define RG_PACKET_CP_IN				(*(uint64*)(CRYPT_AB_BASE+(0x4820)))//Регистр начала IP заголовка при шифр. из ЦП                                	
//--------------------------------------------------------------------

//--------------------Регистры ключей расшифратора-----------------------------
#define RG_DECRYPT_MKEY				(*(uint64*)(CRYPT_CH_BASE+0x3000))//Модификация ключа M-интервал 32 байта
#define RG_DECRYPT_NKEY				(*(uint64*)(CRYPT_CH_BASE+0x3020))//Модификация ключа N-интервал 32 байта
#define RG_DECRYPT_N1KEY			(*(uint64*)(CRYPT_CH_BASE+0x3040))//Модификация ключа (N-1)-интервал 32 байта
#define RG_DECRYPT_WINDOW			(*(uint64*)(CRYPT_CH_BASE+0x3060))//Окно пакетов
#define RG_DECRYPT_HS				(*(uint64*)(CRYPT_CH_BASE+0x3080))//Начальный H 8 байт
#define RG_DECRYPT_HC				(*(uint64*)(CRYPT_CH_BASE+0x3088))//Текущий H   8 байт

//--------------------Регистры ключей зашифратора-----------------------------
#define RG_CRYPT_MKEY				(*(uint64*)(CRYPT_CH_BASE+0x7000))//Модификация ключа M-интервал 32 байта
#define RG_CRYPT_NKEY				(*(uint64*)(CRYPT_CH_BASE+0x7020))//Модификация ключа N-интервал 32 байта
#define RG_CRYPT_HS				(*(uint64*)(CRYPT_CH_BASE+0x7040))//Начальный H 8 байт
#define RG_CRYPT_HC				(*(uint64*)(CRYPT_CH_BASE+0x7048))//Текущий H   8 байт
//-----------------------------------------------------------------------------

#define RG_CONST_CH				(*(uint64*)(CRYPT_AB_BASE+(0x7FF8)))

#define PLIS_DONE 				11 //GPIO_PIN11
#define PLIS_INIT 				12 //GPIO_PIN12
#define PLIS_DIN  				13 //GPIO_PIN13
#define PLIS_CLK  				14 //GPIO_PIN14
#define PLIS_PROG 				15 //GPIO_PIN15

#define FILE_LEN_PLIS  				3640576 
                                 

void CrypterInit()
{
}

uint64 mem=0;
uint64 crypt_param=0;
uint64 decrypt_param=0;

//----------------------------------------------------------------------------
#define TCCINTNUM_READ	7
//----------------------------------------------------------------------------
void QDMA_Read(void* dst,void* src,uint16 len)
{
	uint16 l=len/4;
	int ost=len&0x3;

	if(l)
	{
		EDMA_intClear(TCCINTNUM_READ);
		EDMA_qdmaConfigArgs(0x01370000,(uint32)src,l,(uint32)dst,0);//Urgent priority 
		while(!EDMA_intTest(TCCINTNUM_READ));
	}
	if(ost)
		memcpy(((char*)dst+4*l),((char*)src+4*l),ost);
}
//----------------------------------------------------------------------------
void WriteRAM(uint32 addr,void* buf,uint16 len)
{
uint16 l=(len+7)>>3;
uint64* s = (uint64*)buf;
uint64* d = (uint64*)addr;
	while(l--)
		_amem8(d++)=_mem8(s++);
}
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
//---------------Функции работы с абонентским шифратором----------------------
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
void AbLoadBP(void* bp)
{
	while(RG_STATUS_AB&CRYPT_AB_BUSY);

	memcpy(&RG_BP_AB,bp,128);

	RG_CTRL_AB = CMD_WR_AB_BP|CMD_RG_IS_SET;	
}
//----------------------------------------------------------------------------
void AbLoadKey(void* key)
{

	while(RG_STATUS_AB&CRYPT_AB_BUSY);

	memcpy(&RG_KEY_AB,key,32);

	RG_CTRL_AB = CMD_WR_AB_KEY|CMD_RG_IS_SET;
}
//----------------------------------------------------------------------------
void AbResetCrypter()
{
	while(RG_STATUS_AB&CRYPT_AB_BUSY);
	RG_CTRL_AB = ((uint64)(63)<<16)|CMD_AB_RESET|CMD_RG_IS_SET;
	while(RG_STATUS_AB&CRYPT_AB_BUSY);
}
//----------------------------------------------------------------------------
void AbOperateBlock(void* text,uint16 blk, uint64 cmd)//blk-количество 8 байтовых блоков
{
	while(RG_STATUS_AB&CRYPT_AB_BUSY);

	memcpy(&RG_DATA_IN_AB,text,blk*8);

	RG_CTRL_AB = ((uint64)(blk-1)<<16)|cmd|CMD_RG_IS_SET;

	while(!(RG_STATUS_AB&CRYPT_AB_READY));
	if(cmd!=CMD_AB_IMIT)
		memcpy(text,&RG_DATA_OUT_AB,blk*8);
}
//----------------------------------------------------------------------------
void AbEncrypt(void* text,uint16 len)
{
	uint16 blk64 = len/64;

	uint64* t = (uint64*)text;	

	AbResetCrypter();

	while(blk64--)
	{
		AbOperateBlock(t,64,CMD_AB_ENCRYPT);
		t+=64;
	}

	int ost=len&63;

	if(ost)
	{
		AbOperateBlock(t,ost,CMD_AB_ENCRYPT);
	}
}
//----------------------------------------------------------------------------
void AbDecrypt(void* text,uint16 len)
{
	uint16 blk64 = len/64;

	uint64* t = (uint64*)text;	

	AbResetCrypter();

	while(blk64--)
	{
		AbOperateBlock(t,64,CMD_AB_DECRYPT);
		t+=64;
	}

	int ost=len&63;

	if(ost)
	{
		AbOperateBlock(t,ost,CMD_AB_DECRYPT);
	}

}
//----------------------------------------------------------------------------
uint32 AbImit(void* text,uint16 len)
{
	uint16 blk64 = (len/8)/64;
	uint64* t = (uint64*)text;

	AbResetCrypter();
	
	while(blk64--)
	{
		AbOperateBlock(t,64,CMD_AB_IMIT);
		t+=64;
	}

	blk64 = (len/8)/64;
	int ost = (len/8)&63;

	if(ost)
	{
		uint64 *tmp64 = new uint64[64];
		
		memset(tmp64,0,512);
		memcpy(tmp64,t,ost*8+(len&0x7));

		if(len&0x7)
			ost++;

		AbOperateBlock(tmp64,ost,CMD_AB_IMIT);

		delete tmp64;
	}
	else
	{
		int ost8 = len&0x7;

		if(ost8)
		{	
			uint64 *tmp64 = new uint64[2];

			memset(tmp64,0,16);		
			memcpy(tmp64,t,ost8);

			if(blk64)
				AbOperateBlock(tmp64,1,CMD_AB_IMIT);
			else
				AbOperateBlock(tmp64,2,CMD_AB_IMIT);
			delete tmp64;
		}
	}
	return RG_DATA_OUT_AB;

}
//----------------------------------------------------------------------------
void AbStartGamma(void* sync)
{	
	AbResetCrypter();

	while(RG_STATUS_AB&CRYPT_AB_BUSY);

	memcpy(&RG_SP_AB,sync,8);
		
}
//----------------------------------------------------------------------------
void AbContGamma(void* text, uint16 len)
{
	uint16 blk64 = len/64;
	uint64* t = (uint64*)text;
	
	while(blk64--)
	{
		AbOperateBlock(t,64,CMD_AB_GAMMA);
		t+=64;
	}

	blk64 = len/64;


	int ost=len&63;

	if(ost)
	{
		AbOperateBlock(t,ost,CMD_AB_GAMMA);
	}
}
//----------------------------------------------------------------------------
void AbGamma(void* sync, void* text, uint16 len)
{
	AbStartGamma(sync);
	AbContGamma(text,len);	
}


//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
//-------------------Функции работы с канальным шифратором--------------------
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
void ChLoadCryptBP(void* bp)
{
	while(RG_CTRL_CH_CRYPT&CH_RAM_BUSY);

	memcpy(&RG_LOAD_CH_CRYPT,bp,128);

	RG_CTRL_CH_CRYPT = CMD_WR_CH_BP;	
}
//----------------------------------------------------------------------------
void ChLoadDecryptBP(void* bp)
{
	while(RG_CTRL_CH_DECRYPT&CH_RAM_BUSY);

	memcpy(&RG_LOAD_CH_DECRYPT,bp,128);

	RG_CTRL_CH_DECRYPT = CMD_WR_CH_BP;	

}
//----------------------------------------------------------------------------
void ChSetStartSync(uint64 sync)
{
	while(RG_CTRL_CH_CRYPT&CH_RAM_BUSY);
	memcpy(&RG_LOAD_CH_CRYPT,&sync,8);
	RG_CTRL_CH_CRYPT = CMD_WR_CH_SP;	

	while(RG_CTRL_CH_DECRYPT&CH_RAM_BUSY);
	memcpy(&RG_LOAD_CH_DECRYPT,&sync,8);
	RG_CTRL_CH_DECRYPT = CMD_WR_CH_SP;	
}
//----------------------------------------------------------------------------
void ChSetCryptKi(void* key)
{
	while(RG_CTRL_CH_CRYPT&CH_RAM_BUSY);
	memcpy(&RG_LOAD_CH_CRYPT,key,32);
//	memcpy(&RG_KIKEY_CACHE_CRYPT,key,32);

	RG_CTRL_CH_CRYPT = CMD_WR_CH_KIKEY;
}
//----------------------------------------------------------------------------
void ChSetDecryptKi(void* key)
{
	while(RG_CTRL_CH_DECRYPT&CH_RAM_BUSY);
	memcpy(&RG_LOAD_CH_DECRYPT,key,32);
	memcpy(&RG_KIKEY_CACHE_DECRYPT,key,32);

	RG_CTRL_CH_DECRYPT = CMD_WR_CH_KIKEY;
}
//----------------------------------------------------------------------------
uint16 ChSetCryptIPRec(uint16 n_rec,CryptIPRec *IPRec)
{
	uint64* addr_rec = &RG_IPTABLE_CACHE_CRYPT;

	if(n_rec > 16)return 1;
	
	*(addr_rec+n_rec*2)   = (((uint64)IPRec->mask)<<32)|(IPRec->ip);
	*(addr_rec+n_rec*2+1) = (((uint64)IPRec->indx)<<33)|((uint64)(IPRec->m_lable&0x1)<<32)|(0x1000+0x100*IPRec->n_key);
	
	return 0;
}
//----------------------------------------------------------------------------
uint16 ChSetDecryptIPRec(uint16 n_rec,CryptIPRec *IPRec)
{
	uint64* addr_rec = &RG_IPTABLE_CACHE_DECRYPT;

	if(n_rec > 16)return 1;
	
	*(addr_rec+n_rec*2)   = (((uint64)IPRec->mask)<<32)|(IPRec->ip);
	*(addr_rec+n_rec*2+1) = (((uint64)IPRec->indx)<<33)|((uint64)(IPRec->m_lable&0x1)<<32)|(0x1000+0x100*IPRec->n_key);
	
	return 0;
}
//----------------------------------------------------------------------------
/*uint16 ChGetCryptIPRec(uint16 n_rec,uint32* indx,CryptIPRec *IPRec)
{
	uint64* addr_rec = &RG_IPTABLE_CACHE_CRYPT;

	if(n_rec > 16)return 1;
	
	IPRec->mask     = (*(addr_rec+n_rec*16))>>32;
	IPRec->ip       = (*(addr_rec+n_rec*16))&0xFFFFFFFF;

	IPRec->m_lable  = ((*(addr_rec+n_rec*16+8))>>32)&0x01;       

	IPRec->n_key    = (*(addr_rec+n_rec*16+8))&0xFFFFFFFF;	

	*indx            = ((*(addr_rec+n_rec*16+8))>>33)&0xFFFFFFFF;
		
	return 0;
}
//----------------------------------------------------------------------------
uint16 ChGetDecryptIPRec(uint16 n_rec,uint32* indx,CryptIPRec *IPRec)
{
	uint64* addr_rec = &RG_IPTABLE_CACHE_DECRYPT;

	if(n_rec > 16)return 1;
	
	IPRec->mask    = (*(addr_rec+n_rec*16))>>32;
	IPRec->ip      = (*(addr_rec+n_rec*16))&0xFFFFFFFF;

	IPRec->m_lable = ((*(addr_rec+n_rec*16+8))>>32)&0x01;       

	IPRec->n_key   = (*(addr_rec+n_rec*16+8))&0xFFFFFFFF;	

	*indx           = ((*(addr_rec+n_rec*16+8))>>33)&0xFFFFFFFF;
	
	return 0;
}*/
//----------------------------------------------------------------------------
/*
char base_key[32]={
0xDD,0xF6,0xA4,0xF0,0xF5,0xD6,0xCC,0xA6,
0x81,0xB6,0x43,0xC5,0x31,0x50,0xAA,0x48,
0x43,0xCB,0x5E,0x3F,0x1A,0x6A,0x34,0x1C,
0x10,0xD0,0x23,0xB4,0x43,0x42,0x47,0x70   
};

char base_m[32]={
0x5E,0x47,0xC0,0x5D,0x41,0x7E,0x16,0x60,
0x91,0x19,0xAF,0x0B,0xAB,0x68,0xB8,0x50,
0xDB,0x1D,0xA0,0x10,0x21,0x25,0xC6,0x65,
0xDB,0xDF,0x18,0x41,0xF1,0xEE,0xDC,0xBC   
};

char mn_key[32]={
0xE4,0xF7,0xC0,0x39,0x56,0x80,0xE5,0x6A,
0xE4,0xA1,0x76,0xDC,0xB2,0x8B,0x73,0xDC,
0x65,0x16,0x0A,0x30,0x2B,0x34,0x00,0xF8,
0x20,0x4C,0x32,0xE5,0x31,0xD1,0xB6,0xA5   
};

void ChSetCryptCurM(uint32 CurM);
*/
uint16 ChSetCryptWKey(uint16 n_rec,CryptKeyRec *KeyRec)
{
//    uint64 M,N;

	if(n_rec > 16)return 1;	

	uint64* addr_key = &RG_WKEYS_CACHE_CRYPT;

	addr_key += (0x100/8)*n_rec;
/*
    N = 0x02;
    M = 0x1E;

    ChSetCryptCurM(M);

	memset(KeyRec,0,sizeof(KeyRec));
	memcpy(KeyRec->MKey,base_m,32);
	memcpy(KeyRec->NKey,mn_key,32);
	KeyRec->CurH   = ((uint64)M<<27)|((uint64)N<<12);

    N = 0x01;
    M = 0x1E;
    KeyRec->StartH = ((uint64)M<<27)|((uint64)N<<12);; 
*/
	memcpy(addr_key,KeyRec,sizeof(CryptKeyRec));

	return 0;
}
//----------------------------------------------------------------------------
CryptKeyRec* ChGetCryptWKey(uint16 n_rec)
{
	uint64* addr_key = &RG_WKEYS_CACHE_CRYPT;

	addr_key += (0x100/8)*n_rec;

	return (CryptKeyRec*)addr_key;
}
//----------------------------------------------------------------------------
uint16 ChSetDecryptWKey(uint16 n_rec,DecryptKeyRec *KeyRec)
{
	if(n_rec > 16)return 1;	

	uint64* addr_key = &RG_WKEYS_CACHE_DECRYPT;

	addr_key += (0x100/8)*n_rec;

	memcpy(addr_key,KeyRec,sizeof(DecryptKeyRec));

	return 0;
}
//----------------------------------------------------------------------------
DecryptKeyRec* ChGetDecryptWKey(uint16 n_rec)
{
	uint64* addr_key = &RG_WKEYS_CACHE_DECRYPT;

	addr_key += (0x100/8)*n_rec;

	return (DecryptKeyRec*)addr_key;
}
//----------------------------------------------------------------------------
uint64* ChGetDecryptCurh(uint16 n_rec)
{
	uint64* addr_key = &RG_WKEYS_CACHE_DECRYPT;

	addr_key += (0x100/8)*n_rec+17;
	
	return addr_key;
}
//----------------------------------------------------------------------------
void ChSetCryptCurM(uint32 CurM)
{
	RG_LCHECK_CACHE_CRYPT = CurM;
}
//----------------------------------------------------------------------------
uint16 ChCheckCryptFlag(uint64 *n_ip, uint64* h)
{
	if((RG_CTRL_CH_CRYPT&CH_RAM_BUSY))
		return 0;

	if(RG_STAT_CH_CRYPT&CH_BUF_READY)
	{
                *n_ip = RG_HALF_PART_IPREC_CRYPT;

                *h = RG_H_CRYPTED_PACK;

		return 1;
	}
	else
		return 0;

}
//----------------------------------------------------------------------------
uint16 ChCheckDecryptFlag(uint64 *n_ip, uint64 *h, uint16 *n_addbyte)
{
	if((RG_CTRL_CH_DECRYPT&CH_RAM_BUSY))
		return 0;

	if(RG_STAT_CH_DECRYPT&CH_BUF_READY)
	{
                *n_ip = RG_HALF_PART_IPREC_DECRYPT;

                *h = RG_H_DECRYPTED_PACK;

		*n_addbyte = (((RG_NUM_ADD_BYTE&0xFFFF)>>8)|((RG_NUM_ADD_BYTE&0xFFFF)<<8))&0xFFF;

                if(RG_STAT_CH_DECRYPT&CH_IMIT_ERROR)
                   return CH_IMIT_ERR;
		else
		   return CH_HAVE_PACKET;
	}
	else
		return 0;

}
//----------------------------------------------------------------------------
uint16 ChCheckCryptErFlag()
{
	if(RG_CTRL_CACHE_CRYPT&CH_ERROR)
	{
		if(RG_CTRL_CACHE_CRYPT&CH_LOSTKEY_ERROR)
			return CH_ERR_LOSTKEY;
	
		if((RG_CTRL_CACHE_CRYPT&0xFF)==CH_MTU_ERROR)
			return CH_ERR_MTU;

		if((RG_CTRL_CACHE_CRYPT&0xFF)==CH_CMD_ERROR)
			return CH_ERR_CMD;//Ошибка команды

		return CH_ERR_NOCMD;//Ошибка нет команды
	}
		
	return 0;
}
//----------------------------------------------------------------------------
uint16 ChCheckDecryptErFlag()
{
	if(RG_CTRL_CACHE_DECRYPT&CH_ERROR)
	{
		
		if(RG_CTRL_CACHE_DECRYPT&CH_LOSTKEY_ERROR)
			return CH_ERR_LOSTKEY;//Ключ не найден
	                         	
		if((RG_CTRL_CACHE_DECRYPT&0xFF)==CH_CTRLBYTE_ERROR)
			return CH_ERR_CTRLBYTE;//Ошибка контрольного байта

		if((RG_CTRL_CACHE_DECRYPT&0xFF)==CH_M_MORE_6_ERROR)
			return CH_ERR_M_MORE6;//М интервал h больше чем 6

		if((RG_CTRL_CACHE_DECRYPT&0xFF)==CH_M_LESS_12_ERROR)
			return CH_ERR_M_LESS12;//М интервал h меньше чем 12

		if((RG_CTRL_CACHE_DECRYPT&0xFF)==CH_KVARTAL_ERROR)
			return CH_ERR_KVARTAL;//Номер блокнота не равен номеру из КЭШа

		if((RG_CTRL_CACHE_DECRYPT&0xFF)==CH_ZEROBIT_ERROR)
			return CH_ERR_ZEROBIT;//Ошибка в нулевых битах h

		if((RG_CTRL_CACHE_DECRYPT&0xFF)==CH_WINDOW_ERROR)
			return CH_ERR_WINDOW;//h не проходит "окно"

		if((RG_CTRL_CACHE_DECRYPT&0xFF)==CH_CMD_ERROR)
			return CH_ERR_CMD;//Ошибка команды

		return CH_ERR_NOCMD;//Ошибка нет команды
	}
	return 0;
}
//----------------------------------------------------------------------------
void ChSetCryptCtrlCmd(uint64 cmd)
{
	RG_CTRL_CACHE_CRYPT = cmd;
}
//----------------------------------------------------------------------------
void ChSetDecryptCtrlCmd(uint64 cmd)
{
	RG_CTRL_CACHE_DECRYPT = cmd;
}
//----------------------------------------------------------------------------
void ChSendCryptPacket(uint64 n_comm)
{
	while((RG_CTRL_CH_CRYPT&CH_RAM_BUSY));

	RG_CTRL_CH_CRYPT = (n_comm)|CMD_WR_CH_TRANSMIT;
}
//----------------------------------------------------------------------------
uint16 ChSendDecryptPacket(uint64 n_comm)
{
	uint64 tmp_reg;//DEBUG	

	while((RG_CTRL_CH_DECRYPT&CH_RAM_BUSY));
	
	RG_CTRL_CH_DECRYPT = (n_comm)|CMD_WR_CH_TRANSMIT;

	tmp_reg = RG_CTRL_CH_DECRYPT;//DEBUG
	if(tmp_reg!=((n_comm)|CMD_WR_CH_TRANSMIT))//DEBUG
		asm(" nop");//DEBUG

	while((RG_CTRL_CH_DECRYPT&CH_RAM_BUSY));
	
	if(RG_MLABLE_ERR_CH_DECRYPT==CH_MLABLE_ERROR)
		return 1;	

	if(RG_MLABLE_ERR_CH_DECRYPT==CH_CMD_MLABEL_ERROR)
	{
		if(tmp_reg!=((n_comm)|CMD_WR_CH_TRANSMIT))//DEBUG
			asm(" nop");//DEBUG
		return 2;		
	}

	return 0;
}
//----------------------------------------------------------------------------
void ChSetMLable(uint8 ml_sp0,uint8 ml_sp1,uint8 ml_sp2,uint8 ml_cp)
{

	while(RG_CTRL_CH_DECRYPT&CH_RAM_BUSY);
	RG_LOAD_CH_DECRYPT = ((uint64)(ml_sp2&0x0F)<<20)|
	                   ((uint64)(ml_sp1&0x0F)<<12)|
	                   ((uint64)(ml_sp0&0x0F)<<4); 
	RG_CTRL_CH_DECRYPT = CMD_WR_CH_LABLE;	



	*(&RG_LCHECK_CACHE_CRYPT+1) = ((uint64)(ml_cp &0x0F)<<28)|					  
								  ((uint64)(ml_sp2&0x0F)<<20)|
								  ((uint64)(ml_sp1&0x0F)<<12)|
							      ((uint64)(ml_sp0&0x0F)<<4);

}
//----------------------------------------------------------------------------
void ChSetMCU(uint16 mcu1,uint16 mcu2,uint16 mcu3,uint16 mcu4)
{
	RG_MTULEN_CACHE_CRYPT = ((uint64)(mcu4)<<48)|((uint64)(mcu3)<<32)|((uint64)(mcu2)<<16)|((uint64)(mcu1));
}
//----------------------------------------------------------------------------
void ChSetMTU(uint16 mtu,uint16 fpl)
{
if(mtu)
	*(&RG_LCHECK_CACHE_CRYPT+2) = (((uint64)(fpl)<<24))|1;
else
	*(&RG_LCHECK_CACHE_CRYPT+2) = 0;
}
//----------------------------------------------------------------------------
void ChCryptCP(void *hdr,void *packet,uint16 shift_ip,uint16 p_len,uint16 fp)
{
	char *h = (char*)hdr;
	char *p = (char*)packet;

	while(RG_CTRL_CP_CRYPT&CH_RAM_BUSY);
	
	WriteRAM((uint64)&RG_HDR_CP_IN,h,24);

	WriteRAM((uint64)&RG_PACKET_CP_IN,p,p_len+shift_ip);

	RG_CTRL_CP_CRYPT = (((uint64)(fp)<<60))|((uint64)(8+24+shift_ip)<<8)|CMD_CP_WRITE_PACKET;
}
//----------------------------------------------------------------------------
uint64 ChGetCurSync()
{
	return RG_CUR_SYNC;	
}
//----------------------------------------------------------------------------
//При flag=1 на если была ошибка 
//При flag=0 на если ошибки не было
//----------------------------------------------------------------------------
void ChGetCryptEthHeader(void *eth_hdr,uint16 flag)
{
	char *hdr = (char*)eth_hdr;
	
	if(flag)
	{
		uint64* p_addr = &RG_SLB_CACHE_CRYPT;
		//memcpy(hdr,p_addr+1,24);
		QDMA_Read(hdr,p_addr+1,24);
	}
	else
	{
		uint64* p_addr = &RG_BASE_DECRYPT_PACKET;
		//memcpy(hdr,p_addr+1,24);
	    QDMA_Read(hdr,p_addr+1,24);
	}
}
//----------------------------------------------------------------------------
//При flag=1 на если была ошибка 
//При flag=0 на если ошибки не было
//----------------------------------------------------------------------------
void memcpy_dst_a(void* dst,void* src,int len)
{
uint64* d=(uint64*)dst;
uint64* s=(uint64*)src;

int l=len>>3;
int ost=len&7;

while(l--)
	_amem8(d++)=_mem8(s++);

if(ost)
	memcpy(d,s,ost);
}
//----------------------------------------------------------------------------
void ChGetCryptIPHeader(void *ip_hdr,uint16 offset,uint16 len, uint16 flag)
{
	char *hdr = (char*)ip_hdr;

	if(flag)
	{
		uint64* p_addr = &RG_SLB_CACHE_CRYPT;
		memcpy(hdr,(char*)p_addr+32+offset,len);
		//QDMA_Read(hdr,(char*)p_addr+32+offset,len);
	}
	else
	{
		uint64* p_addr = &RG_BASE_DECRYPT_PACKET;;
		memcpy(hdr,(char*)p_addr+32+offset,len);//+4
        //QDMA_Read(hdr,(char*)p_addr+32+offset,len);
	}
}
//----------------------------------------------------------------------------
//При flag=1 если была ошибка 
//При flag=0 если ошибки не было
//----------------------------------------------------------------------------
void ChGetDecryptEthHeader(void *eth_hdr,uint16 flag)
{
	char *hdr = (char*)eth_hdr;
	
	if(flag)
	{
		uint64* p_addr = &RG_SLB_CACHE_DECRYPT;
		//memcpy(hdr,p_addr+1,24);
        QDMA_Read(hdr,p_addr+1,24);
	}
	else
	{
		uint64* p_addr = &RG_BASE_CRYPT_PACKET;
		//memcpy(hdr,p_addr+1,24);
        QDMA_Read(hdr,p_addr+1,24);
	}
}
//При flag=1 если была ошибка
//При flag=0 если ошибки не было
//----------------------------------------------------------------------------
void ChGetDecryptIPHeader(void *ip_hdr,uint16 offset, uint16 len, uint16 flag)
{
	char *hdr = (char*)ip_hdr;

	if(flag)
	{
		uint64* p_addr = &RG_SLB_CACHE_DECRYPT;
		memcpy(hdr,(char*)p_addr+32+offset,len);
	}
	else
	{
		uint64* p_addr = &RG_DECRYPT_PACKET;
		memcpy(hdr,(char*)p_addr+32+offset+20,len);
	}
}
//----------------------------------------------------------------------------
void ChSetCryptEthHeader(void *eth_hdr,uint16 len)
{
	char *hdr = (char*)eth_hdr;

	uint64* p_addr = &RG_CRYPT_PACKET;	

	memcpy_dst_a((p_addr+1),hdr,len);

}
//----------------------------------------------------------------------------
void ChSetDecryptEthHeader(void *eth_hdr,uint16 len)
{
	char *hdr = (char*)eth_hdr;

	uint64* p_addr = &RG_DECRYPT_PACKET;	

	memcpy_dst_a((p_addr+1),hdr,len);
	
}
//----------------------------------------------------------------------------
void ChMoveCP(void *hdr,void *packet,uint16 shift_ip,uint16 p_len,uint64 n_comm)
{

	char *h = (char*)hdr;
	char *p = (char*)packet;
				
	while(RG_CTRL_CH_DECRYPT&CH_RAM_BUSY);

	WriteRAM((uint64)&RG_LOAD_CH_DECRYPT,h,24);

	WriteRAM(((uint64)(&RG_LOAD_CH_DECRYPT+3))+16,p-4,p_len+shift_ip+4);

	RG_CTRL_CH_DECRYPT = ((32+20+p_len+shift_ip)<<8)|n_comm|CMD_WR_CH_CPMOVE;

}
//----------------------------------------------------------------------------
void ChStopCrypt()
{
	while(RG_CTRL_CH_CRYPT&CH_RAM_BUSY);

	RG_LOAD_CH_CRYPT = CMD_CH_STOP_WORK;

	RG_CTRL_CH_CRYPT = CMD_WR_CH_LABLE;	
	
}
//----------------------------------------------------------------------------
void ChStopDecrypt()
{
	while(RG_CTRL_CH_DECRYPT&CH_RAM_BUSY);

	RG_LOAD_CH_DECRYPT = CMD_CH_STOP_WORK;

	RG_CTRL_CH_DECRYPT = CMD_WR_CH_LABLE;	

}
//----------------------------------------------------------------------------
void ChStartCrypt()
{
	while(RG_CTRL_CH_CRYPT&CH_RAM_BUSY);

	RG_LOAD_CH_CRYPT = 0;

	RG_CTRL_CH_CRYPT = CMD_WR_CH_LABLE;	
}
//----------------------------------------------------------------------------
void ChStartDecrypt(uint8 ml_sp0,uint8 ml_sp1,uint8 ml_sp2,uint8 ml_cp)
{
	while(RG_CTRL_CH_DECRYPT&CH_RAM_BUSY);
	RG_LOAD_CH_DECRYPT = ((uint64)(ml_sp2&0x0F)<<20)|
	                   ((uint64)(ml_sp1&0x0F)<<12)|
	                   ((uint64)(ml_sp0&0x0F)<<4); 

	RG_CTRL_CH_DECRYPT = CMD_WR_CH_LABLE;	
}
//----------------------------------------------------------------------------
uint16 ChReadyCryptCP()
{
	if(RG_CTRL_CP_CRYPT&CH_RAM_BUSY)
		return 0;
	else
		return 1;
}
//----------------------------------------------------------------------------
uint16 ChReadyMoveCP()
{
	if(RG_CTRL_CH_DECRYPT&CH_RAM_BUSY)
		return 0;
	else
		return 1;
}
//----------------------------------------------------------------------------
void ChCryptResetMask(void *mask)
{
	uint64* m_addr = &RG_CRYPT_LOAD_MASK;
	memset(m_addr,0,4096);	
}
//----------------------------------------------------------------------------
void ChDecryptResetMask(void *mask)
{
	uint64* m_addr = &RG_DECRYPT_LOAD_MASK;
	memset(m_addr,0,4096);
}
//----------------------------------------------------------------------------
void ChCryptLoadMask(uint16 offset,void *mask,uint16 len)//offset-смещение в блоках по 8 байт
{
	uint64* m_addr = &RG_CRYPT_LOAD_MASK;
	memcpy(m_addr+offset,mask,len);
}
//----------------------------------------------------------------------------
void ChDecryptLoadMask(uint16 offset,void *mask,uint16 len)//offset-смещение в блоках по 8 байт
{
	uint64* m_addr = &RG_DECRYPT_LOAD_MASK;
	memcpy(m_addr+offset,mask,len);	
}
//----------------------------------------------------------------------------
void ResetPLIS()
{

}
//----------------------------------------------------------------------------
void WaitBusy()
{
	while(RG_CTRL_CH_DECRYPT&CH_RAM_BUSY);
}
