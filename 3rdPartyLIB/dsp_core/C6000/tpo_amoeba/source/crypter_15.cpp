/**********************************************************************************************************************
*                                        (c) COPYRIGHT by ZAO RCZI FORT.                                             *
*        ..                                       All rights reserved.                                               *
***********************************************************************************************************************
* Module      : crypter_15.cpp
* Description : ������� ������ � ���������� ���������� ��� ��-5 �� ����������� ����������.
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
#include <os_syscall.h>
#include <drv_dbgout.h>
//#include <drv_ipmp_dozu.h>
#include <rts.h>
#include "drv_usbhc.h"
#include "drv_usb.h"
#include "drv_usbms.h"
#include "drv_gpio.h"
#include "crypter_15.h"

extern uint16* ptr_crypt;//��������� ������ ����� ���� � ���

#define CRYPT_BASE              	0xA0000000

                                	
                                	

//----------------��� ���������� ������� ������-----------------------
#define CRYPT_UPZ_BUSY          	0x00000001
#define CRYPT_UPZ_HAVE_DATA     	0x00000002
                                	
#define RG_STATUS_UPZ           	(*(uint32*)(CRYPT_BASE+(0x624<<2)))//������� ���������  ���
                                	
#define RG_CODE_UPZ            		(*(uint32*)(CRYPT_BASE+(0x625<<2)))//������� ���������� ���
#define RG_RESET_UPZ            	(*(uint32*)(CRYPT_BASE+(0x626<<2)))//������� ������ ���
                                	
#define RG_KEY_UPZ         			(*(uint32*)(CRYPT_BASE+(0x600<<2)))//������� ����� �����

#define RG_BP_UPZ1					(*(uint32*)(CRYPT_BASE+(0x610<<2)))//������� ����� ������ �������� ����� ����������� 
#define RG_BP_UPZ2					(*(uint32*)(CRYPT_BASE+(0x660<<2)))//������� ����� ������ �������� ����� �����������

#define RG_DATA1_UPZ            	(*(uint32*)(CRYPT_BASE+(0x620<<2)))//������� ����� ������� ����� ������
#define RG_DATA2_UPZ            	(*(uint32*)(CRYPT_BASE+(0x621<<2)))//������� ����� ������� ����� ������
#define RG_DATA3_UPZ            	(*(uint32*)(CRYPT_BASE+(0x622<<2)))//������� ������ ������� ����� ������
#define RG_DATA4_UPZ            	(*(uint32*)(CRYPT_BASE+(0x623<<2)))//������� ������ ������� ����� ������

//--------------------------------------------------------------------

//-------------------��� ������������ ���������-----------------------

#define CRYPT_AB_BUSY          		0x00000004
#define CRYPT_AB_HAVE_DATA     		0x00000008

#define RG_STATUS_AB				(*(uint32*)(CRYPT_BASE+(0x52F<<2)))//������� ���������  ��
#define RG_RESET_AB					(*(uint32*)(CRYPT_BASE+(0x525<<2)))//������� ������ ��
#define RG_RST_BIT_AB				(*(uint32*)(CRYPT_BASE+(0x52A<<2)))//������� ������ ���� ����������
                                	
#define RG_CODE_AB					(*(uint32*)(CRYPT_BASE+(0x526<<2)))//������� ���������� ��
#define RG_DECODE_AB				(*(uint32*)(CRYPT_BASE+(0x527<<2)))//������� ������������ ��
#define RG_GAM_AB					(*(uint32*)(CRYPT_BASE+(0x528<<2)))//������� ������������ ��
#define RG_IMV_AB					(*(uint32*)(CRYPT_BASE+(0x529<<2)))//������� ��������� ��� 
                                	
#define RG_KEY_AB         			(*(uint32*)(CRYPT_BASE+(0x500<<2)))//������� ����� �����

#define RG_BP_AB1					(*(uint32*)(CRYPT_BASE+(0x510<<2)))//������� ����� ������ ����� ����� �����������
#define RG_BP_AB2					(*(uint32*)(CRYPT_BASE+(0x560<<2)))//������� ����� ������ ����� ����� �����������

#define RG_DATA1_AB            		(*(uint32*)(CRYPT_BASE+(0x52B<<2)))//������� ����� ������� ����� ������
#define RG_DATA2_AB            		(*(uint32*)(CRYPT_BASE+(0x52C<<2)))//������� ����� ������� ����� ������
#define RG_DATA3_AB            		(*(uint32*)(CRYPT_BASE+(0x52D<<2)))//������� ������ ������� ����� ������
#define RG_DATA4_AB            		(*(uint32*)(CRYPT_BASE+(0x52E<<2)))//������� ������ ������� ����� ������

//--------------------------------------------------------------------

//---------------------��� ���������� ���������-----------------------

#define CRYPT_CH_BUSY          		0x00000010
#define CRYPT_CH_HAVE_DATA     		0x00000020
#define CH_MOVE_DONE     			0x00000040
#define CH_DECODCONTRBYTE_DONE  	0x00000080
#define CH_CONTRBYTE_ERROR  		0x00000100
#define CH_IMV_ERROR  				0x00000200
#define CH_READY_CP_DATA			0x00000400


#define RG_STATUS_CH				(*(uint32*)(CRYPT_BASE+(0x228<<2)))//������� ���������  ���������� ���������
#define RG_CONST_CH					(*(uint32*)(CRYPT_BASE+(0x22F<<2)))//������� �������� ���������� ���������
                                	
#define RG_RESET_CH					(*(uint32*)(CRYPT_BASE+(0x238<<2)))//������� ������ ���������� ���������
#define RG_RST_BIT_CH				(*(uint32*)(CRYPT_BASE+(0x239<<2)))//������� ������ ���� ����������
                                	
#define RG_KI_KEY_CH     			(*(uint32*)(CRYPT_BASE+(0x200<<2)))//������� ����� ����� �� ���������� ���������

#define RG_BP_CH1					(*(uint32*)(CRYPT_BASE+(0x210<<2)))//������� ����� ������ ����� ����� ����������� ���������� ���������
#define RG_BP_CH2					(*(uint32*)(CRYPT_BASE+(0x260<<2)))//������� ����� ������ ����� ����������� ���������� ���������

#define RG_SYNC_CH					(*(uint32*)(CRYPT_BASE+(0x220<<2)))//������� ����� ������������� ���������� ���������
#define RG_ODD_BYTE_CH				(*(uint32*)(CRYPT_BASE+(0x222<<2)))//������� ����� ���������� ���� ���������� ���������
#define RG_DARAM_ADDR_CH			(*(uint32*)(CRYPT_BASE+(0x223<<2)))//������� ����� ������ ������ � ���� ������ ������ 

#define RG_LEN_CH					(*(uint32*)(CRYPT_BASE+(0x230<<2)))//������� ������ �������������� ������ ���������� ���������

#define RG_CRYPT_ODD_BYTE_CH1  		(*(uint32*)(CRYPT_BASE+(0x233<<2)))//������� ������ ������������� ���������� ���� ���������� ���������
#define RG_CRYPT_ODD_BYTE_CH2  		(*(uint32*)(CRYPT_BASE+(0x234<<2)))//������� ������ ������������� ���������� ���� ���������� ���������
#define RG_CRYPT_SYNC_CH1      		(*(uint32*)(CRYPT_BASE+(0x235<<2)))//������� ������ ������������� ������������� ���������� ���������
#define RG_CRYPT_SYNC_CH2      		(*(uint32*)(CRYPT_BASE+(0x236<<2)))//������� ������ ������������� ������������� ���������� ���������

#define RG_WORK_KEY_CH     			(*(uint32*)(CRYPT_BASE+(0x240<<2)))//������� ����� �������� ����� ���������� ���������
#define RG_H_CH	 	    			(*(uint32*)(CRYPT_BASE+(0x650<<2)))//������� ����� ����� h ���������� ���������

#define RG_DATA1_CH            		(*(uint32*)(CRYPT_BASE+(0x224<<2)))//������� ����� ������� ����� ������ ���������� ���������
#define RG_DATA2_CH            		(*(uint32*)(CRYPT_BASE+(0x225<<2)))//������� ����� ������� ����� ������ ���������� ���������

#define RG_DATA3_CH            		(*(uint32*)(CRYPT_BASE+(0x226<<2)))//������� ������ ������� ����� ������ ���������� ���������
#define RG_DATA4_CH            		(*(uint32*)(CRYPT_BASE+(0x227<<2)))//������� ������ ������� ����� ������ ���������� ���������


#define RG_MOVE_CH					(*(uint32*)(CRYPT_BASE+(0x229<<2)))//������� ��������� �� ���� � ����
#define RG_DECODCONTRBYTE_CH		(*(uint32*)(CRYPT_BASE+(0x22A<<2)))//������������� ��������� ������

#define RG_CODE_CP_DARAM_CH			(*(uint32*)(CRYPT_BASE+(0x22B<<2)))//���������� �� �� � ����
#define RG_DECODE_DARAM_CP_CH		(*(uint32*)(CRYPT_BASE+(0x22C<<2)))//������������� �� ���� � ��

#define RG_CODE_DARAM_DARAM_CH		(*(uint32*)(CRYPT_BASE+(0x22D<<2)))//���������� �� ���� � ����
#define RG_DECODE_DARAM_DARAM_CH	(*(uint32*)(CRYPT_BASE+(0x22E<<2)))//������������� �� ���� � ����


//--------------------��� ����������-���������� ���������-------------
#define RG_SYNC_ABCH				(*(uint32*)(CRYPT_BASE+(0x253<<2)))//������� ����� ������������� ����������� ���������
#define RG_KEY_ABCH	    			(*(uint32*)(CRYPT_BASE+(0x300<<2)))//������� ����� �������� ����� ������������ ���������

#define RG_IMV_ABCH					(*(uint32*)(CRYPT_BASE+(0x20A<<2)))//������� ����������� ���������� ���������

#define RG_CODE_DARAM_DARAM_ABCH	(*(uint32*)(CRYPT_BASE+(0x23A<<2)))//���������� �� ���� � ����
#define RG_DECODE_DARAM_DARAM_ABCH	(*(uint32*)(CRYPT_BASE+(0x23D<<2)))//������������� �� ���� � ����

#define RG_CODE_DARAM_CP_ABCH		(*(uint32*)(CRYPT_BASE+(0x23B<<2)))//���������� �� ���� � ��
#define RG_DECODE_CP_DARAM_ABCH		(*(uint32*)(CRYPT_BASE+(0x23E<<2)))//������������� �� �� � ����

#define RG_DATA1_ABCH				(*(uint32*)(CRYPT_BASE+(0x328<<2)))
#define RG_DATA2_ABCH				(*(uint32*)(CRYPT_BASE+(0x329<<2)))

//--------------------------------------------------------------------


#define PLIS_DONE 11 //GPIO_PIN11
#define PLIS_INIT 12 //GPIO_PIN12
#define PLIS_DIN  13 //GPIO_PIN13
#define PLIS_CLK  14 //GPIO_PIN14
#define PLIS_PROG 15 //GPIO_PIN15

#define FILE_LEN_PLIS     959128 

void plis_delay()
{
	for(int i=0;i<100;i++)
		asm("	nop");
}
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
//-------------������� ������ � ����������� ������� ������--------------------
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
void UpzLoadBP(void* bp)
{
	int len=32;
	uint32* t=(uint32*)bp;

	uint32 *addr_bp = &RG_BP_UPZ1;

	while(RG_STATUS_UPZ&CRYPT_UPZ_BUSY);
		
	while(len--)
	{
		if(len==15)addr_bp = &RG_BP_UPZ2;

		*addr_bp = _mem4(t++);
		addr_bp++;		
	}
}
//----------------------------------------------------------------------------
void UpzLoadKey(void* key)
{
	int len=8;
	uint32* t = (uint32*)key;

	uint32* addr_key = &RG_KEY_UPZ;

	while(RG_STATUS_UPZ&CRYPT_UPZ_BUSY);

	while(len--)
	{
		*addr_key = _mem4(t++);
		addr_key++;
	}
}
//----------------------------------------------------------------------------
void UpzEncrypt(void* text,uint16 len)
{
	uint32* t = (uint32*)text;
	
	while(RG_STATUS_UPZ&CRYPT_UPZ_BUSY);

	while(len--)
	{
		RG_DATA1_UPZ=_mem4(t);
		RG_DATA2_UPZ=_mem4(t+1);

		RG_CODE_UPZ = 1;

		while(!(RG_STATUS_UPZ&CRYPT_UPZ_HAVE_DATA));

		_mem4(t)=RG_DATA3_UPZ;
		_mem4(t+1)=RG_DATA4_UPZ;
		
		RG_RESET_UPZ = 1;		

		t+=2;

	}
}
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
//---------------������� ������ � ����������� ����������----------------------
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
void AbResetCrypter()
{

}
//----------------------------------------------------------------------------
void AbLoadBP(void* bp)
{
	int len=32;
	uint32* t=(uint32*)bp;
	
	uint32	*addr_bp = &RG_BP_AB1;

	while(RG_STATUS_AB&CRYPT_AB_BUSY);
		
	while(len--)
	{
		if(len==15)addr_bp = &RG_BP_AB2;

		*addr_bp = _mem4(t++);
		addr_bp++;		
	}

}
//----------------------------------------------------------------------------
void AbLoadKey(void* key)
{
	int len=8;
	uint32* t = (uint32*)key;

	uint32* addr_key = &RG_KEY_AB;

	while(RG_STATUS_AB&CRYPT_AB_BUSY);

	while(len--)
	{
		*addr_key = _mem4(t++);
		addr_key++;
	}

}
//----------------------------------------------------------------------------
void AbEncrypt(void* text,uint16 len)
{
	uint32* t = (uint32*)text;
	
	while(RG_STATUS_AB&CRYPT_AB_BUSY);
	RG_RESET_AB = 1;		

	while(len--)
	{
		RG_DATA1_AB=_mem4(t);
		RG_DATA2_AB=_mem4(t+1);

		RG_CODE_AB = 1;

		while(!(RG_STATUS_AB&CRYPT_AB_HAVE_DATA));

		_mem4(t)=RG_DATA3_AB;
		_mem4(t+1)=RG_DATA4_AB;
		
		RG_RST_BIT_AB = 1;		

		t+=2;
	}
}
//----------------------------------------------------------------------------
void AbDecrypt(void* text,uint16 len)
{
	uint32* t = (uint32*)text;
	
	while(RG_STATUS_AB&CRYPT_AB_BUSY);
    RG_RESET_AB = 1;		

	while(len--)
	{
		RG_DATA1_AB=_mem4(t);
		RG_DATA2_AB=_mem4(t+1);

		RG_DECODE_AB = 1;

		while(!(RG_STATUS_AB&CRYPT_AB_HAVE_DATA));

		_mem4(t)=RG_DATA3_AB;
		_mem4(t+1)=RG_DATA4_AB;
		
		RG_RST_BIT_AB = 1;		

		t+=2;
	}

}
//----------------------------------------------------------------------------
uint32 AbImit(void* text,uint16 len)
{
	uint32* t=(uint32*)text;
	int l=len/8;

	while(RG_STATUS_AB&CRYPT_AB_BUSY);
    RG_RESET_AB = 1;		

	while(l--)
	{
		RG_DATA1_AB=_mem4(t);
		RG_DATA2_AB=_mem4(t+1);

		RG_IMV_AB = 1;
		
		while(!(RG_STATUS_AB&CRYPT_AB_HAVE_DATA));

		RG_RST_BIT_AB = 1;		

		t+=2;
	}

	int ost=len&0x7;
	if(ost)
	{
		if(len>8)
		{
			uint32 tmp[2];
			memset(tmp,0,2);
			memset(tmp,0,sizeof(tmp));
			memcpy(tmp,t,ost);

			RG_DATA1_AB=_mem4(tmp);
			RG_DATA2_AB=_mem4(tmp+1);

			RG_IMV_AB = 1;
		
			while(!(RG_STATUS_AB&CRYPT_AB_HAVE_DATA));
		
			RG_RST_BIT_AB = 1;					
		}
		else
		{
			uint32 tmp[4];
			memset(tmp,0,sizeof(tmp));
			memcpy(tmp,t,ost);
			for(int i=0;i<4;i+=2)
			{
				RG_DATA1_AB=_mem4(&tmp[i]);
				RG_DATA2_AB=_mem4(&tmp[i+1]);

				RG_IMV_AB = 1;

				while(!(RG_STATUS_AB&CRYPT_AB_HAVE_DATA));
				
				RG_RST_BIT_AB = 1;		
			}	
		}
	}
	return RG_DATA4_AB;
}

void AbStartGamma(void* sync)
{
	uint32* s = (uint32*)sync;
	
	while(RG_STATUS_AB&CRYPT_AB_BUSY);
	RG_RESET_AB = 1;		

	RG_DATA1_AB=_mem4(s);
	RG_DATA2_AB=_mem4(s+1);

	RG_GAM_AB = 1;

	while(!(RG_STATUS_AB&CRYPT_AB_HAVE_DATA));
		
}
//----------------------------------------------------------------------------
void AbContGamma(void* text, uint16 len)
{
	uint32* t=(uint32*)text;
	int l=len;

	RG_RST_BIT_AB = 1;		
	
	while(l--)
	{ 
		RG_DATA1_AB=_mem4(t);
		RG_DATA2_AB=_mem4(t+1);

		RG_GAM_AB = 1;
		
		while(!(RG_STATUS_AB&CRYPT_AB_HAVE_DATA));

		_mem4(t)=RG_DATA3_AB;
		_mem4(t+1)=RG_DATA4_AB;
				
		RG_RST_BIT_AB = 1;		

		t+=2;
	}
/*
	int ost=len&0x7;
	if(ost)
	{
		uint32 tmp[2];
		memset(tmp,0,sizeof(tmp));
		memcpy(tmp,t,ost);

		RG_DATA1_AB=_mem4(tmp);
		RG_DATA2_AB=_mem4(tmp+1);

		RG_GAM_AB = 1;
		
		while(!(RG_STATUS_AB&CRYPT_AB_HAVE_DATA));

		_mem4(tmp)=RG_DATA3_AB;
		_mem4(tmp+1)=RG_DATA4_AB;
	
		memcpy(t,tmp,ost);		
	}*/
}
//----------------------------------------------------------------------------

void AbGamma(void* sync, void* text, uint16 len)
{
	AbStartGamma(sync);
	AbContGamma(text,len);	
}


//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
//-------------------������� ������ � ��������� ����������--------------------
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
void ChLoadBP(void* bp)
{
	int len=32;
	uint32* t=(uint32*)bp;
	
	uint32	*addr_bp = &RG_BP_CH1;

	while(RG_STATUS_CH&CRYPT_CH_BUSY);
		
	while(len--)
	{
		if(len==15)addr_bp = &RG_BP_CH2;

		*addr_bp = _mem4(t++);
		addr_bp++;		
	}

}
//----------------------------------------------------------------------------
void ChSetStartSync(uint64 sync)
{
	uint32	*addr_sync = &RG_SYNC_CH;

	while(RG_STATUS_CH&CRYPT_CH_BUSY);

	*addr_sync = (uint32)sync;
	*(addr_sync+1) = (uint32)(sync>>32);

}
//----------------------------------------------------------------------------
void ChSetAdd(uint64 add)
{
	while(RG_STATUS_CH&CRYPT_CH_BUSY);
	RG_ODD_BYTE_CH = (uint32)add;
}

//----------------------------------------------------------------------------
void ChSetKi(void* key)
{
	int len=8;
	uint32* t = (uint32*)key;
	
	uint32* addr_key = &RG_KI_KEY_CH;

	while(RG_STATUS_CH&CRYPT_CH_BUSY);

	while(len--)
	{		 
		*addr_key = _mem4(t++);
		addr_key++;
	}
}
//----------------------------------------------------------------------------
void ChSetKb( uint16 keynum, void* key, uint64 h)
{
	int len=8;
	uint32 m_h[2];
	uint32* t = (uint32*)key;

	uint32* addr_h = &RG_H_CH;
	uint32* addr_key = &RG_WORK_KEY_CH;

	memset(m_h,0,sizeof(m_h));
	memcpy(m_h,&h,sizeof(h));

	while(RG_STATUS_CH&CRYPT_CH_BUSY);

	while(len--)
	{
		*addr_key = _mem4(t++);
		addr_key++;
	}

	while(RG_STATUS_CH&CRYPT_CH_BUSY);

	*addr_h 	= (m_h[0]);
	*(addr_h+1) = (m_h[1]);
	
}
//----------------------------------------------------------------------------
void ChStartMove(uint16 dst_pnum, uint16 dst_addr, uint16 src_pnum, uint16 src_addr, uint16 length)
{
	uint16 dst=0,src=0;

	length &= 0x0fff;

	if(dst_pnum == 0)dst = dst_addr >> 2;
	else dst = (0x1000+dst_addr) >> 2;

	if(src_pnum == 0)src = src_addr >> 2;
	else src = (0x1000+src_addr) >> 2;	
	
	while(RG_STATUS_CH&CRYPT_CH_BUSY);
	RG_RESET_CH = 1;		
	
	RG_DARAM_ADDR_CH = ((uint32)dst << 11)|((uint32)src);	

	RG_LEN_CH = (uint32)length;  

	RG_MOVE_CH = 1;
}
//----------------------------------------------------------------------------
void ChWaitEndMove()
{
	while(!(RG_STATUS_CH&CH_MOVE_DONE));
}
//----------------------------------------------------------------------------
void ChStartCrypt( uint16 dst_pnum, uint16 dst_addr, uint16 src_pnum, uint16 src_addr, uint16 length, uint16 keynum)
{
	uint16 dst=0,src=0;

	length &= 0x0fff;

	if(dst_pnum == 0)dst = dst_addr >> 2;
	else dst = (0x1000+dst_addr) >> 2;

	if(src_pnum == 0)src = src_addr >> 2;
	else src = (0x1000+src_addr) >> 2;	

	while(RG_STATUS_CH&CRYPT_CH_BUSY);
	RG_RESET_CH = 1;		

	RG_DARAM_ADDR_CH = ((uint32)dst << 11)|((uint32)src);	

	RG_LEN_CH = (uint32)length;

	RG_CODE_DARAM_DARAM_CH = 0;


}
//----------------------------------------------------------------------------
void ChWaitEndCrypt()
{
	while(!(RG_STATUS_CH&CRYPT_CH_HAVE_DATA));
}
//----------------------------------------------------------------------------
void ChStartDecrypt(uint16 dst_pnum, uint16 dst_addr, uint16 src_pnum, uint16 src_addr, uint16 length, uint16 keynum)
{
	uint16 dst=0,src=0;

	length &= 0x0fff;

	if(dst_pnum == 0)dst = dst_addr >> 2;
	else dst = (0x1000+dst_addr) >> 2;

	if(src_pnum == 0)src = src_addr >> 2;
	else src = (0x1000+src_addr) >> 2;	

	while(RG_STATUS_CH&CRYPT_CH_BUSY);
	RG_RESET_CH = 1;		
	RG_RST_BIT_CH = 1;

	RG_DARAM_ADDR_CH = ((uint32)dst << 11)|((uint32)src);	

	RG_LEN_CH = (uint32)length;

	RG_DECODE_DARAM_DARAM_CH = 0;

}
//----------------------------------------------------------------------------
uint16 ChWaitEndDecrypt()
{
	while(!(RG_STATUS_CH&CRYPT_CH_HAVE_DATA));	

	if((RG_STATUS_CH&CH_IMV_ERROR)!=0)return CH_IMV_ERROR;

	return 0;
}
//----------------------------------------------------------------------------
uint16 ChDecryptService(uint16 src_pnum, uint16 src_addr,void* service,uint16 length_pack)
{
	uint16 src=0,dst=0;
	uint32* srv=(uint32*)service;

	dst = 0x0;

	length_pack &= 0x0fff;

	if(src_pnum == 0)src = src_addr >> 2;
	else src = (0x1000+src_addr) >> 2;	

	while(RG_STATUS_CH&CRYPT_CH_BUSY);
	RG_RESET_CH = 1;		

	RG_DARAM_ADDR_CH = ((uint32)dst << 11)|((uint32)src);	

	RG_LEN_CH = (uint32)length_pack;

	RG_DECODCONTRBYTE_CH = 0;

	while(!(RG_STATUS_CH&CH_DECODCONTRBYTE_DONE));

//	if((RG_STATUS_CH&CH_CONTRBYTE_ERROR)!=0)return CH_CONTRBYTE_ERROR;

	_mem4(srv)=RG_CRYPT_ODD_BYTE_CH1;
	_mem4(srv+1)=RG_CRYPT_ODD_BYTE_CH2;

	_mem4(srv+2)=RG_CRYPT_SYNC_CH1;
	_mem4(srv+3)=RG_CRYPT_SYNC_CH2;

	if((RG_STATUS_CH&CH_CONTRBYTE_ERROR)!=0)return CH_CONTRBYTE_ERROR;

	return 0;
}
//----------------------------------------------------------------------------
void ChCryptCP(uint16 dst_pnum, uint16 dst_addr, void *src_buf, uint16 length, uint16 keynum)
{
	uint16 src=0,dst=0;
	uint32* s=(uint32*)src_buf;

	length &= 0x0fff;
	uint16 len = length/8;
	
	if(dst_pnum == 0)dst = dst_addr >> 2;
	else dst = (0x1000+dst_addr) >> 2;

	while(RG_STATUS_CH&CRYPT_CH_BUSY);
	RG_RESET_CH = 1;		

	RG_DARAM_ADDR_CH = ((uint32)dst << 11)|((uint32)src);	

	RG_LEN_CH = (uint32)length;
	
	while(len--)
	{
		RG_DATA1_CH=_mem4(s);
		RG_DATA2_CH=_mem4(s+1);
		
		RG_CODE_CP_DARAM_CH = 0;
	
		while(!(RG_STATUS_CH&CRYPT_CH_HAVE_DATA));
				
		RG_RST_BIT_CH = 1;		

		s+=2;

	}
	int ost=length&0x7;
	if(ost)
	{
		uint32 tmp[2];
		memset(tmp,0,sizeof(tmp));
		memcpy(tmp,s,ost);

		RG_DATA1_CH=_mem4(tmp);
		RG_DATA2_CH=_mem4(tmp+1);

		RG_CODE_CP_DARAM_CH = 0;
		
		while(!(RG_STATUS_CH&CRYPT_CH_HAVE_DATA));
	}

}
//----------------------------------------------------------------------------
uint16 ChDecryptCP(uint16 src_pnum, uint16 src_addr, void *dst_buf, uint16 length, uint16 keynum)
{
	uint16 src=0,dst=0;
	uint32* d=(uint32*)dst_buf;
  	uint16 len;

	dst = 0x8000;

	length &= 0x0fff;
	len = length/8;
	
	if(src_pnum == 0)src = src_addr >> 2;
	else src = (0x1000+src_addr) >> 2;	

	while(RG_STATUS_CH&CRYPT_CH_BUSY);
	RG_RESET_CH = 1;		

	RG_DARAM_ADDR_CH = ((uint32)dst << 11)|((uint32)src);	

	RG_LEN_CH = (uint32)length;

	while(len--)
	{
		RG_DECODE_DARAM_CP_CH = 0;

		while(!(RG_STATUS_CH&CRYPT_CH_HAVE_DATA));

		_mem4(d) = RG_DATA3_CH;
		_mem4(d+1) = RG_DATA4_CH;
		
		RG_RST_BIT_CH = 1;		

		d+=2;
	}

	int ost=length&0x7;
	if(ost)
	{
		uint32 tmp[2];
		memset(tmp,0,sizeof(tmp));

		RG_DECODE_DARAM_CP_CH = 0;

		while(!(RG_STATUS_CH&CRYPT_CH_HAVE_DATA));

		_mem4(tmp) = RG_DATA3_CH;
		_mem4(tmp+1) = RG_DATA4_CH;


		memcpy(d,tmp,ost);
				
	}
	

	if((RG_STATUS_CH&CH_IMV_ERROR)!=0)return CH_IMV_ERROR;

	return 0;
}
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
//------------������� ������ � ����������-��������� ����������----------------
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
void ChAbLoadKey(void* key)
{
	int len=8;
	uint32* t = (uint32*)key;

	uint32* addr_key = &RG_KEY_ABCH;

	while(RG_STATUS_CH&CRYPT_AB_BUSY);

	while(len--)
	{
		*addr_key = _mem4(t++);
		addr_key++;
	}

}
//----------------------------------------------------------------------------
void ChAbLoadSync(void* sync)
{
	uint32* s=(uint32*)sync;

	uint32	*addr_sync = &RG_SYNC_ABCH;

	while(RG_STATUS_CH&CRYPT_CH_BUSY);

	*addr_sync = _mem4(s);
	*(addr_sync+1) = _mem4(s+1);
	
}
//----------------------------------------------------------------------------
uint32 ChAbCrypt(uint16 dst_pnum, uint16 dst_addr, uint16 src_pnum, uint16 src_addr, uint16 length)
{
	uint32 imv=0;

	uint16 dst=0,src=0;

	length &= 0x0fff;

	if(dst_pnum == 0)dst = dst_addr >> 2;
	else dst = (0x1000+dst_addr) >> 2;

	if(src_pnum == 0)src = src_addr >> 2;
	else src = (0x1000+src_addr) >> 2;	

	while(RG_STATUS_CH&CRYPT_CH_BUSY);
	RG_RESET_CH = 1;		

	RG_DARAM_ADDR_CH = ((uint32)dst << 11)|((uint32)src);	

	RG_LEN_CH = (uint32)length;

	RG_CODE_DARAM_DARAM_ABCH = 2;

	while(!(RG_STATUS_CH&CRYPT_CH_HAVE_DATA));

	imv = RG_IMV_ABCH;

	return imv;

}
//----------------------------------------------------------------------------
uint32 ChAbDecrypt(uint16 dst_pnum, uint16 dst_addr, uint16 src_pnum, uint16 src_addr, uint16 length)
{
	uint32 imv=0;

	uint16 dst=0,src=0;

	length &= 0x0fff;

	if(dst_pnum == 0)dst = dst_addr >> 2;
	else dst = (0x1000+dst_addr) >> 2;

	if(src_pnum == 0)src = src_addr >> 2;
	else src = (0x1000+src_addr) >> 2;	

	while(RG_STATUS_CH&CRYPT_CH_BUSY);
	RG_RESET_CH = 1;		

	RG_DARAM_ADDR_CH = ((uint32)dst << 11)|((uint32)src);	

	RG_LEN_CH = (uint32)length;

	RG_DECODE_DARAM_DARAM_ABCH = 2;

	while(!(RG_STATUS_CH&CRYPT_CH_HAVE_DATA));	

	imv = RG_IMV_ABCH;

	return imv;
}
//----------------------------------------------------------------------------
uint32 ChAbCryptCP(uint16 src_pnum, uint16 src_addr, void *dst_buf, uint16 length)
{
	uint32 imv=0;
	uint16 src=0,dst;
	uint32* d=(uint32*)dst_buf;
  	uint16 len;

	dst = 0;

	length &= 0x0fff;
	len = length/8;
	
	if(src_pnum == 0)src = src_addr >> 2;
	else src = (0x1000+src_addr) >> 2;	

	while(RG_STATUS_CH&CRYPT_CH_BUSY);
	RG_RESET_CH = 1;		

	RG_DARAM_ADDR_CH = ((uint32)dst << 11)|((uint32)src);	

	RG_LEN_CH = (uint32)length;

	int ost=length&0x7;

	while(len--)
	{
		RG_CODE_DARAM_CP_ABCH = 2;

		while(!(RG_STATUS_CH&CRYPT_CH_HAVE_DATA));

		_mem4(d) = RG_DATA3_CH;
		_mem4(d+1) = RG_DATA4_CH;

		RG_RST_BIT_CH = 1;		

		d+=2;
	}

	if(ost)
	{
		uint32 tmp[2];
		memset(tmp,0,sizeof(tmp));

		RG_CODE_DARAM_CP_ABCH = 2;

		while(!(RG_STATUS_CH&CRYPT_CH_HAVE_DATA));

		_mem4(tmp) = RG_DATA1_ABCH;
		_mem4(tmp+1) = RG_DATA2_ABCH;

		memcpy(d,tmp,ost);				
	}
	
	imv = RG_IMV_ABCH;

	return imv;
}
//----------------------------------------------------------------------------
uint32 ChAbDecryptCP(uint16 dst_pnum, uint16 dst_addr, void *src_buf, uint16 length)
{
	uint32 imv = 0;
	
	uint32 tmp[4];

	uint16 src,dst=0;
	uint32* s=(uint32*)src_buf;
  	uint16 len;

	src = 0;

	length &= 0x0fff;

	len = length/8;

	
	if(dst_pnum == 0)dst = dst_addr >> 2;
	else dst = (0x1000+dst_addr) >> 2;	

	while(RG_STATUS_CH&CRYPT_CH_BUSY);
	RG_RESET_CH = 1;		

	RG_DARAM_ADDR_CH = ((uint32)dst << 11)|((uint32)src);	

	RG_LEN_CH = (uint32)length;
	
	while(len--)
	{
		RG_DATA1_CH = _mem4(s);
		RG_DATA2_CH = _mem4(s+1);

		RG_DECODE_CP_DARAM_ABCH = 2;
		
		while(!(RG_STATUS_CH&CRYPT_CH_HAVE_DATA));
					
		RG_RST_BIT_CH = 1;		

		s+=2;
	}

	int ost=length&0x7;
	if(ost)
	{
		memset(tmp,0,sizeof(tmp));
		memcpy(tmp,s,ost);

		RG_DATA1_CH = _mem4(tmp);
		RG_DATA2_CH = _mem4(tmp+1);
	
		RG_DECODE_CP_DARAM_ABCH = 2;

		while(!(RG_STATUS_CH&CRYPT_CH_HAVE_DATA));				
	}
	
	imv = RG_IMV_ABCH;

	return imv;

}
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

