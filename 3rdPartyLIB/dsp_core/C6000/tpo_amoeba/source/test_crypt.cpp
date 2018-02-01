/**********************************************************************************************************************
*                                        (c) COPYRIGHT by ZAO RCZI FORT.                                             *
*        ..                                       All rights reserved.                                               *
***********************************************************************************************************************
* Module      : test_crypt.cpp
* Description : Функции Тестирования Аппаратного Шифратора.
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
#ifdef TPO7
#include "crypter_17.h"
#else
#include "crypter_15.h"
#endif

#include "test_crypt.h"
#include "soft_crypt.h"

#include "tpo.h"

#define	E_AB		0x00000001ull//Ошибка в теле текста
#define	E_AB_GAM	0x00000002ull//Ошибка в служебных данных
#define	E_AB_IMV	0x00000004ull//Ошибка имитовставки 
#define	E_UPZ		0x00000008ull//Ошибка имитовставки 

extern uint16 Start_tst_cr_ch;
extern EthCFG	to_from;
extern kdg_rez_test gl_result;
extern CryptErrors* EncryptDecryptErr;

extern uint32 Send_cmd_comm(uint32 n_comm, uint32 cmd);
extern void WriteDARAM(uint16 n_comm,uint16 addr,void* buf,uint16 len);


//----------------------------------------------------------------------------
#ifndef TPO7
char test_bp_gost[]=//Для канала 
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

#else
/*
char test_bp_alfa[]= //ALFA!!!!!!!!!!!!!!!!!!!!!
{
0x55,0x83,0x58,0x85,0x38,0x53,0x38,0x53,
0x33,0x4d,0x34,0x43,0xd4,0x3d,0xd4,0x3d,
0x99,0x67,0x96,0x69,0x76,0x97,0x76,0x97,
0x11,0xc0,0x1c,0xc1,0x0c,0x10,0x0c,0x10,
0xff,0x1c,0xf1,0x1f,0xc1,0xfc,0xc1,0xfc,
0x00,0xae,0x0a,0xa0,0xea,0x0e,0xea,0x0e,
0x88,0x28,0x82,0x28,0x82,0x88,0x82,0x88,
0xdd,0xb2,0xdb,0xbd,0x2b,0xd2,0x2b,0xd2,

0x66,0x06,0x60,0x06,0x60,0x66,0x60,0x66,
0x22,0xea,0x2e,0xe2,0xae,0x2a,0xae,0x2a,
0xee,0x59,0xe5,0x5e,0x95,0xe9,0x95,0xe9,
0xcc,0x7f,0xc7,0x7c,0xf7,0xcf,0xf7,0xcf,
0xbb,0x34,0xb3,0x3b,0x43,0xb4,0x43,0xb4,
0x77,0xf1,0x7f,0xf7,0x1f,0x71,0x1f,0x71,
0xaa,0x95,0xa9,0x9a,0x59,0xa5,0x59,0xA5,
0x44,0xdb,0x4d,0xd4,0xbd,0x4b,0xbd,0x4b
};
*/

char test_bp_alfa[]= //Блок подстановки для Альфы
{
0x41, 0x34, 0xA7, 0x2E, 0x4A, 0xA3, 0x49, 0xD9, 
0xC0, 0xD2, 0x3C, 0x34, 0xAF, 0xB6, 0xA2, 0x2F, 
0xDF, 0xA1, 0x96, 0x05, 0xF5, 0x59, 0xD1, 0x18, 
0x88, 0x09, 0x1D, 0x1A, 0xCE, 0xC0, 0xED, 0xBA, 
0x0B, 0x60, 0x7A, 0x51, 0x09, 0x8C, 0x05, 0x6C, 
0x5A, 0xEF, 0xBE, 0x42, 0xB2, 0x2F, 0xC4, 0x55, 
0xE7, 0x4D, 0x82, 0xBC, 0x66, 0x61, 0x6B, 0x4B, 
0xF6, 0xB8, 0x40, 0xEB, 0xD8, 0xD7, 0x9C, 0xAE, 

0x33, 0xF7, 0x69, 0xFD, 0x97, 0x48, 0xFF, 0xF2,
0xB9, 0x93, 0x28, 0xA9, 0x84, 0x92, 0x70, 0xC0,
0xA5, 0x2E, 0x04, 0x93, 0x10, 0x0B, 0x1A, 0x73,
0x94, 0x7B, 0x5F, 0x67, 0x5C, 0x1A, 0xB6, 0x36,
0x1E, 0xCC, 0xE1, 0xC6, 0x3B, 0x34, 0x57, 0x94,
0x2D, 0x16, 0xD3, 0xD8, 0x7D, 0x7E, 0x23, 0x0D,
0x6C, 0x5A, 0xC5, 0x70, 0xE3, 0xED, 0x3E, 0xE7,
0x72, 0x85, 0xFB, 0x8F, 0x21, 0xF5, 0x88, 0x81
};

char test_key_alfa[]= //Базовый ключ
{
0xDD,0xF6,0xA4,0xF0,0xF5,0xD6,0xCC,0xA6,
0x81,0xB6,0x43,0xC5,0x31,0x50,0xAA,0x48,
0x43,0xCB,0x5E,0x3F,0x1A,0x6A,0x34,0x1C,
0x10,0xD0,0x23,0xB4,0x43,0x42,0x47,0x70   
};

char test_ki_alfa[]= //Ключ КИ
{
0xD6,0xD1,0xFC,0xCA,0xC0,0xCC,0xC7,0xEC,
0x78,0x29,0x68,0xDD,0x08,0xFF,0xE3,0xB1,
0x1A,0x04,0x42,0x0B,0x03,0x20,0x8A,0x7C,
0xB9,0xA6,0x26,0xD8,0x75,0x9E,0x52,0x3A   
};

char sync_alfa[]=  //Синхропосылка
{
0x50,0x00,0x67,0xC6,0x69,0x73,0x51,0xFF
};


#endif
/*
char test_key_alfa[]= //Tї¬к¦Єv• ·vжв
{
0x01,0x23,0x45,0x67,0x89,0xab,0xcd,0xef,
0xfe,0xdc,0xba,0x98,0x76,0x54,0x32,0x10,
0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,
0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55   
};

char synxro_alfa[]=  //T°¤¬и¦ ¦¬vv·Ё
{
0xfd,0xf2,0xee,0x20,0xf1,0xe8,0xed,0xf0
};

char sync_alfa[]=  //Синхропосылка
{
0x50,0x00,0x67,0xC6,0x69,0x73,0x51,0xFF
};
*/


char test_key_gost[]=
{
0x04,0x75,0xf6,0xe0,0x50,0x38,0xfb,0xfa,
0xd2,0xc7,0xc3,0x90,0xed,0xb3,0xca,0x3d,
0x15,0x47,0x12,0x42,0x91,0xae,0x1e,0x8a,
0x2f,0x79,0xcd,0x9e,0xd2,0xbc,0xef,0xbd
};

char test_ki_gost[]=
{
0x75,0x5B,0x4D,0xCD,0x55,0x47,0x47,0x28,
0x1B,0xE9,0x65,0xA6,0x4F,0x2F,0xAA,0x9F,
0xCF,0x68,0x37,0x37,0x8D,0x6A,0x07,0x68,
0xBC,0xF9,0x92,0x55,0xCA,0x4F,0x06,0xD9
};

char synxro_gost[]=//Синхропосылка для абонентского шифрования
{
0x2a,0x80,0xa7,0xc3,0xff,0xa8,0xe3,0x47
};

char tst_sync_gost[]=//Синхропосылка для  канала
{
0x50,0x00,0x71,0x71,0x71,0x71,0x71,0x00
};

char txt_e_gost[]=
{
0xd9,0xbe,0x1e,0x40,0x7d,0xd7,0xf5,0x56,
0x03,0x05,0x79,0x4e,0x18,0x01,0xfe,0x73,
0x0e,0x49,0xf2,0x74,0xdd,0x31,0x6f,0x2f,
0xb1,0x97,0x50,0xa7,0xd5,0x24,0x7b,0xa6
};
#ifndef TPO7
uint16 TestUpz(void *bp, void *key, void *text1,void *text2,uint16 len)
{
	uint16 res=0;
	UpzLoadBP(bp);
	UpzLoadKey(key);
	UpzEncrypt(text1,len/8);

	sUpzLoadBP(bp);
	sUpzLoadKey(key);
	sUpzEncrypt(text2,len);

	res = memcmp(text1,text2,len);

	if(res)
	return res;
	else
	return 0;
}
#endif
uint16 TestAbGamma(void *bp, void *key, void *synxro, void *text1, void *text2, uint16 len)
{
	uint16 res=0;

	AbGamma(synxro,text1,len/8);//в блоках по 8 байт

	sAbLoadBP(bp);
	sAbLoadKey(key);
	sAbGamma(synxro,text2,len);//в блоках по 8 байт

	res = memcmp(text1,text2,len);
	if(res)
		return res;

	AbGamma(synxro,text1,len/8);//в блоках по 8 байт

	sAbLoadBP(bp);
	sAbLoadKey(key);
	sAbGamma(synxro,text2,len);//в блоках по 8 байт

	res = memcmp(text1,text2,len);
	return res;	
}

uint16 TestAbCrypt(void *bp, void *key, void *text1, void *text2, uint16 len)
{
	uint16 res=0;

	AbEncrypt(text1,len/8);//В блоках

	sAbLoadBP(bp);
	sAbLoadKey(key);
	sAbEncrypt(text2,len);//В байтах

	res = memcmp(text1,text2,len);
	if(res)
		return res;

	AbDecrypt(text1,len/8);

	sAbLoadBP(bp);
	sAbLoadKey(key);
	sAbDecrypt(text2,len);

	res = memcmp(text1,text2,len);
		return res;	
} 

uint16 TestAbImv(void *bp, void *key, void *text, uint16 len)
{
	uint16 res=0;
	uint32 Imv1=0,Imv2=0;

	Imv1 = AbImit(text,len);

	sAbLoadBP(bp);
	sAbLoadKey(key);
	Imv2 = sAbImit(text,len);

	res = memcmp(&Imv1,&Imv2,4);
	if(res)
		return res;
	else
		return 0;
}

#ifndef TPO7
uint32 TestGostAB(uint16 num)
{
	char src[512];
	char buf1[512];
	char buf2[512];

	uint16 res,len;
	uint16 cr_err,upz_err,imv_err,gam_err;

	uint32 cycle=0;
	uint32 all_err = 0;

	cr_err=upz_err=imv_err=gam_err=0;

	AbLoadBP(test_bp_gost);
	AbLoadKey(test_key_gost);

//#ifndef TPO7
	UpzLoadBP(test_bp_gost);
	UpzLoadKey(test_key_gost);
//#endif

	for(uint16 i=0;i<512;i++)
		src[i] = i;
	
	while(cycle<num)
	{
		res = 0;
		len = 512;

//#ifndef TPO7
		memcpy(buf1,src,len);
		memcpy(buf2,src,len);
		res = TestUpz(test_bp_gost,test_key_gost,buf1,buf2,len);
		if(res)
			upz_err++;

		AbResetCrypter();
//#endif
		memcpy(buf1,src,len);
		memcpy(buf2,src,len);
		res = TestAbGamma(test_bp_gost,test_key_gost,synxro_gost,buf1,buf2,len);
		memcpy(buf1,src,len);
		memcpy(buf2,src,len);
		res = TestAbGamma(test_bp_gost,test_key_gost,synxro_gost,buf1,buf2,len);
		if(res)
			gam_err++;

		memcpy(buf1,src,len);
		res = TestAbImv(test_bp_gost,test_key_gost,buf1,len);
		if(res)
			imv_err++;		

		memcpy(buf1,src,len);
		memcpy(buf2,src,len);
		res = TestAbCrypt(test_bp_gost,test_key_gost,buf1,buf2,len);
		if(res)
			cr_err++;

		cycle++;
	}

	if(cr_err)
		all_err|=E_AB;
	if(gam_err)
		all_err|=E_AB_GAM;
	if(imv_err)
		all_err|=E_AB_IMV;
	if(upz_err)
		all_err|=E_UPZ;
	
	return all_err;
}
#endif

#ifdef TPO7

// ---------------------------------------------------------------------------
uint32 TestAlfaAB( uint16 num )
{
	char src[512];
	char buf1[512];
	char buf2[512];

	uint16 res,len;
	uint16 cr_err, imv_err, gam_err;

	uint32 cycle = 0;
	uint32 all_err = 0;

	cr_err = imv_err = gam_err = 0;

//	CrypterInit();

	AbLoadBP( test_bp_alfa );
	AbLoadKey( test_key_alfa );

	for( uint16 i = 0; i < 256; i++ )
		src[i] = i;

	memset( buf1, 0, sizeof(buf1) );
	memset( buf2, 0, sizeof(buf2) );
//	memset( src, 0x12, sizeof(src) );
		res = 0;
		len = 512;

	while(cycle<num)
//	while( 1 )
	{
		
		memcpy( buf1, src, len );
		memcpy( buf2, src, len );
		res = TestAbGamma( test_bp_alfa, test_key_alfa, sync_alfa, buf1, buf2, len );
		memcpy( buf1, src, len );
		memcpy( buf2, src, len );
		res = TestAbGamma( test_bp_alfa, test_key_alfa, sync_alfa, buf1, buf2, len );
		if( res )
			gam_err++;


		memcpy( buf1, src, len );
		res = TestAbImv( test_bp_alfa, test_key_alfa, buf1, len );
		if( res )
			imv_err++;		

		memcpy( buf1, src, len );
		memcpy( buf2, src, len );
		res = TestAbCrypt( test_bp_alfa, test_key_alfa, buf1, buf2, len );
		if( res )
			cr_err++;

		len += 8;
		if( len == 2048 )
			len = 16;
		
		cycle++;
	}

	if(cr_err)
		all_err|=E_AB;
	if(gam_err)
		all_err|=E_AB_GAM;
	if(imv_err)
		all_err|=E_AB_IMV;
	
	return all_err;

}
// ---------------------------------------------------------------------------
#endif














//---------------------------------------------------------------
void CryptDecryptChLoop2(CryptStart *m_crypt,SrcDstConfig *m_cfg)
{
	uint32 res=0;

	char buf1[1500];
	char buf2[1500];

//	ChLoadBP(m_crypt->bp); для теста 6-ки закоментил. может нуно доя 5

//	ChSetKi(m_crypt->ki);
//	ChSetStartSync(_mem8(m_crypt_gost.sync));

			
	ChSetStartSync(_mem8(m_crypt->sync));

	memset(buf1,m_cfg->fill,m_cfg->len);
	memset(buf2,0xFF,m_cfg->len);

//	NetCard = 0;

syn_begin();
	ChSetAdd(m_crypt->ms);
	ChSetKb(0,m_crypt->wk,m_crypt->h);
	ChCryptCP(m_cfg->dst_num,m_cfg->dst_addr,buf1,m_cfg->len,0);
syn_end();

	res = Send_cmd_comm(m_cfg->dst_num, SEND_TEST_PACKET);

	if(res != TPO_OK)// если не ответил, то пришли разные пакеты из ЦП0 и ЦП1
	{
		gl_result.err++;
		goto write_err_dozu;

	}
	else
	{
		res = Send_cmd_comm(m_cfg->src_num, RECV_TEST_PACKET);
			if(res != TPO_OK)// eсли не ответил, то потрерял пакет
			{
				gl_result.rez++;
				goto write_err_dozu;
			}
	}


	if(ChDecryptService(m_cfg->src_num,m_cfg->src_addr,buf2,m_cfg->len))
		EncryptDecryptErr->CtrBErr++;
	
	ChSetKb(0,m_crypt->wk,m_crypt->h);

	if(ChDecryptCP(m_cfg->src_num,m_cfg->src_addr,buf2,m_cfg->len,0))
		EncryptDecryptErr->ImvErr++;

	if(memcmp(buf1,buf2,m_cfg->len))
		EncryptDecryptErr->BodyErr++;


write_err_dozu:


	EncryptDecryptErr->NumPack++;	
	EncryptDecryptErr->LostPack = gl_result.rez;
	EncryptDecryptErr->CMPerr = gl_result.err;


}


//------------------------------------------------------------------------

void FillCryptStart(CryptStart *m_crypt_gost)
{
	memcpy(m_crypt_gost->bp,test_bp_gost,sizeof(test_bp_gost));
	memcpy(m_crypt_gost->ki,test_ki_gost,sizeof(test_ki_gost));
	m_crypt_gost->ms = 0x060050;
	memcpy(m_crypt_gost->wk,test_key_gost,sizeof(test_key_gost));
	memcpy(m_crypt_gost->sync,tst_sync_gost,sizeof(tst_sync_gost));
	m_crypt_gost->h = 0x1400ul;
//	m_crypt_gost->h = 0x123456789ABCul;
}
int ette = 0;
void CrypterChTestLoop()
{
	CryptStart m_crypt_gost;
	CryptErrors EncrDecrErr;
	memset(&EncrDecrErr, 0, sizeof(CryptErrors));
	EncryptDecryptErr = &EncrDecrErr;

//etCard = 0;

	FillCryptStart(&m_crypt_gost);

	SrcDstConfig m_cfg_gost;

	m_cfg_gost.len 		= 1400;
	m_cfg_gost.fill		= 0x55;
	m_cfg_gost.src_num 	= to_from.eth_recv;
	m_cfg_gost.dst_num 	= to_from.eth_send;
	m_cfg_gost.src_addr	= 0;
	m_cfg_gost.dst_addr	= 0;

	WriteDARAM(m_cfg_gost.dst_num, 0, &EncrDecrErr, sizeof(CryptErrors));




	ChLoadBP(m_crypt_gost.bp);
	ChSetKi(m_crypt_gost.ki);
	ChSetStartSync(_mem8(m_crypt_gost.sync));


//	ChSetAdd(m_crypt_gost.ms);
//	ChSetKb(0,m_crypt_gost.wk,m_crypt_gost.h);


#ifdef	TPO6
if(!ette)
{
	SLBLoadBP(m_crypt_gost.bp);
	SLBLoadKey(m_crypt_gost.ki);
ette=1;
}
#endif


	Send_cmd_comm(m_cfg_gost.src_num, CLEAR_TEST_PACKET);

	while(Start_tst_cr_ch)
	{

	CryptDecryptChLoop2(&m_crypt_gost,&m_cfg_gost);


//syn_begin();
	WriteDARAM(m_cfg_gost.dst_num, 0, &EncrDecrErr, sizeof(CryptErrors));
//syn_end();

		if(EncrDecrErr.NumPack%2)
			m_cfg_gost.fill = 0xAA;
		else
			m_cfg_gost.fill = 0x55;
	}
}

