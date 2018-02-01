#include <os_syscall.h>
#include <drv_dbgout.h>
#include <drv_ipmp.dsp-16.h>
#include <rts.h>
#include "drv_usbhc.h"
#include "drv_usb.h"
#include "drv_usbms.h"
#include "drv_gpio.h"
#include "crypter_15.h"

extern uint16* ptr_crypt;//оБЮБМШОЩК БДТЕУУ ЖБКМБ рмйу Ч пъх

uint16 total_decrypt_len = 0;

#define CRYPT_AB_BASE                   0xB0000000
#define CRYPT_CH_BASE                   0xB0000000

#define IMIT_ERR                        0x80//Ошибка имитовставки                                	
                                	

//----------------Флаги для устройства простой замены-------------------
#define CRYPT_UPZ_BUSY                  0x0000000000000001ull
#define CRYPT_UPZ_HAVE_DATA             0x0000000000000002ull
//----------------------------------------------------------------------
//----------------Комманды для устройства простой замены----------------
#define CMD_RG_IS_SET                   0x0000000000000001ull
#define CMD_WR_UPZ_BP                   0x0000000000000020ull
#define CMD_WR_UPZ_KEY                  0x0000000000000040ull
#define CMD_UPZ_ENCRYPT                 0x0000000000000080ull
#define CMD_UPZ_RESET                   0x0000000000000800ull
//----------------------------------------------------------------------
//-------------------Регистры устройства простой замены-----------------
#define RG_BP_UPZ                       (*(uint64*)(CRYPT_AB_BASE+(0x4800)))//Регистр ввода подстановки 0x20-0x2F для УПЗ
#define RG_KEY_UPZ                      (*(uint64*)(CRYPT_AB_BASE+(0x4880)))//Регистр ввода ключа 0x10-0x13 для УПЗ
                                	
#define RG_CTRL_UPZ                     (*(uint64*)(CRYPT_AB_BASE+(0x48A8)))//Регистр управления УПЗ                               	
#define RG_STATUS_UPZ                   (*(uint64*)(CRYPT_AB_BASE+(0x48A8)))//Регистр состояния УПЗ                                	
                                	
#define RG_DATA_IN_UPZ                  (*(uint64*)(CRYPT_AB_BASE+(0x4C00)))//Регистр входных данных в УПЗ
#define RG_DATA_OUT_UPZ                 (*(uint64*)(CRYPT_AB_BASE+(0x4E00)))//Регистр обработанных данных в УПЗ
//----------------------------------------------------------------------
//----------------------------------------------------------------------
//----------------------------------------------------------------------
//-------------------Флаги абонентского шифратора-----------------------
//----------------------------------------------------------------------
#define CRYPT_AB_BUSY                   0x0000000000000001ull
#define CRYPT_AB_READY                  0x0000000000000002ull
//----------------------------------------------------------------------
//----------------Комманды для абонентского шифратора-------------------
#define CMD_RG_IS_SET                   0x0000000000000001ull
#define CMD_WR_AB_BP                    0x0000000000000020ull
#define CMD_WR_AB_KEY                   0x0000000000000040ull
#define CMD_AB_ENCRYPT                  0x0000000000000080ull
#define CMD_AB_DECRYPT                  0x0000000000000100ull
#define CMD_AB_IMIT                     0x0000000000000200ull
#define CMD_AB_GAMMA                    0x0000000000000400ull
#define CMD_AB_RESET                    0x0000000000000800ull
//----------------------------------------------------------------------
//-------------------Регистры абонентского шифратора--------------------
#define RG_BP_AB                        (*(uint64*)(CRYPT_AB_BASE+(0x4000)))//Регистр ввода подстановки 0x20-0x2F
#define RG_KEY_AB                       (*(uint64*)(CRYPT_AB_BASE+(0x4080)))//Регистр ввода ключа 0x10-0x13
#define RG_SP_AB                        (*(uint64*)(CRYPT_AB_BASE+(0x40A0)))//Регистр ввода синхропосылки
                                	
#define RG_CTRL_AB                      (*(uint64*)(CRYPT_AB_BASE+(0x40A8)))//Регистр управления АБ                                	
#define RG_STATUS_AB                    (*(uint64*)(CRYPT_AB_BASE+(0x40A8)))//Регистр состояния АБ                                	
                                	
#define RG_DATA_IN_AB                   (*(uint64*)(CRYPT_AB_BASE+(0x4400)))//Регистр входных данных
#define RG_DATA_OUT_AB                  (*(uint64*)(CRYPT_AB_BASE+(0x4600)))//Регистр обработанных данных
//----------------------------------------------------------------------
//----------------------------------------------------------------------
//----------------------------------------------------------------------
//----------------------------------------------------------------------
//---------------------Флаги для канального шифратора-------------------
//----------------------------------------------------------------------
#define CRYPT_CH_BUSY                   0x0000000000000001ull//Шифратор занят


#define CH_CODE_PACKET_DONE             0x0000000000000035ull//Зашифрование пакета закончено

#define CH_PUT_PACKET_DONE              0x0000000000000039ull//Шифратор отправил пакет на СП

#define CH_DECODE_PACKET_DONE           0x000000000000013Full//Расшифрование всего пакета закончено
#define CH_DECODE_IPHDR_DONE            0x000000000000013Full//Расшифрование первых 24 байт IP заголовка закончено
#define CH_IMIT_ERR                     0x000000000000033Full//Ошибка имитовставки

#define CH_MOVE_PACKET_DONE             0x0000000000000053ull//Передача без шифрования закончена
//----------------------------------------------------------------------
//---------------------Комманды для канального шифратора----------------
#define CH_LOAD_BP                      0x0000000000000003ull//Загрузка БП
#define CH_LOAD_KI                      0x0000000000000005ull//Загрузка КИ
#define CH_LOAD_DB                      0x0000000000000009ull//Загрузка добавочных байт
#define CH_LOAD_SP                      0x000000000000000Full//Загрузка синхропосылки


#define CH_CODE_PACKET                  0x0000000000000035ull//Зашифрование пакета
#define CH_PUT_PACKET                   0x0000000000000039ull//Шифратор отправил пакет на СП
#define CH_DECODE_PACKET                0x000000000000003Full//Расшифрование всего пакета
#define CH_MOVE_PACKET                  0x0000000000000053ull//Передача без шифрования

//----------------------------------------------------------------------
//-------------------Регистры канального шифратора----------------------
#define RG_CTRL_CH                      (*(uint64*)(CRYPT_CH_BASE+(0x2000)))//Регистр управления канальным шифратором
#define RG_STATUS_BUSY_CH               (*(uint64*)(CRYPT_CH_BASE+(0x2000)))//Регистр состояния  для  busy канального шифратора
#define RG_STATUS_READY_CH              (*(uint64*)(CRYPT_CH_BASE+(0x2100)))//Регистр состояния  флагов канального шифратора

#define RG_IN_DATA_CH                   (*(uint64*)(CRYPT_CH_BASE+(0x2008)))//Регистр ввода служебных данных канального шифратора
#define RG_OUT_SERVICE_CH               (*(uint64*)(CRYPT_CH_BASE+(0x2010)))//Регистр вывода служебных данных на КИ
#define RG_OUT_DATA_CH                  (*(uint64*)(CRYPT_CH_BASE+(0x2800)))//Регистр вывода данных пакета канального шифратора
#define RG_IN_CP_DATA_CH                (*(uint64*)(CRYPT_CH_BASE+(0x6000)))//Регистр ввода данных пакета канального шифратора
//----------------------------------------------------------------------
//----------------------------------------------------------------------
//----------------------------------------------------------------------
//---------------------Флаги для служебного шифратора-------------------
//----------------------------------------------------------------------
#define CRYPT_SLB_BUSY                   0x0000000000000001ull//Шифратор занят
#define SLB_DECRYPT_CB_DONE              0x0000000000000055ull//Расшифрование на КИ закончено
#define SLB_DECRYPT_CB_ERR               0x0000000000000155ull//Ошибка контрольного байта
//----------------------------------------------------------------------
//---------------------Комманды для служебного шифратора----------------
#define SLB_LOAD_BP                      0x0000000000000003ull//Загрузка БП
#define SLB_LOAD_KI                      0x0000000000000005ull//Загрузка КИ
#define SLB_DECRYPT_CB                   0x0000000000000055ull//Расшифрование на КИ
//----------------------------------------------------------------------
//-------------------Регистры служебного шифратора----------------------
#define RG_CTRL_SLB                      (*(uint64*)(CRYPT_CH_BASE+(0x3000)))//Регистр управления канальным шифратором
#define RG_STATUS_BUSY_SLB               (*(uint64*)(CRYPT_CH_BASE+(0x3000)))//Регистр состояния  для  busy канального шифратора
#define RG_STATUS_READY_SLB              (*(uint64*)(CRYPT_CH_BASE+(0x3008)))//Регистр состояния  флагов канального шифратора

#define RG_IN_DATA_SLB                   (*(uint64*)(CRYPT_CH_BASE+(0x3008)))//Регистр ввода служебных данных канального шифратора
#define RG_OUT_SERVICE_SLB               (*(uint64*)(CRYPT_CH_BASE+(0x3010)))//Регистр вывода служебных данных на КИ

#define RG_CONST_CH                      (*(uint64*)(CRYPT_CH_BASE+(0x7FF8)))//Регистр для константы шифратора//???

//--------------------------------------------------------------------
#define PLIS_DONE                       11//GPIO_PIN11
#define PLIS_INIT                       12//GPIO_PIN12
#define PLIS_DIN                        13//GPIO_PIN13
#define PLIS_CLK                        14//GPIO_PIN14
#define PLIS_PROG                       15//GPIO_PIN15

#define FILE_LEN_PLIS                   3640576 

//extern void QDMA_Read(void* dst,void* src,uint16 len);

//----------------------------------------------------------------------------
void plis_delay() 
{                 
    for(int i=0;i<100;i++)
        asm("	nop");
}
//----------------------------------------------------------------------------
void DebugPin(int32 value)
{
    register int is = int_disable();
    REG_GPEN |= 2;
    REG_GPDIR |= 2;
    if(value)
        REG_GPVAL |= 2;
    else
        REG_GPVAL &= ~2;
    int_enable(is);
}
//----------------------------------------------------------------------------
uint64 mem=0;
uint64 crypt_param=0;
uint64 decrypt_param=0;
/*
//----------------------------------------------------------------------------
int LoadPLISFromUSB(const char* name)
{
    FILE* f = fopen(name,"rb");
    if(f==NULL)
        return -4;

    int n = fread(ptr_crypt,1,FILE_LEN_PLIS,f);

    fclose(f);

    if(n != FILE_LEN_PLIS)
    {
        return -5;
    }
    
    return LoadPLISFromRAM();
}
//----------------------------------------------------------------------------
int LoadPLISFromRAM()
{
    int32 res;
    uint32 comm0, comm1, comm2;

    comm0 = drv_mkd( "/dev/ipmp/ipmp1" );
    comm1 = drv_mkd( "/dev/ipmp/ipmp2" );
    comm2 = drv_mkd( "/dev/ipmp/ipmp3" );

    if( ( comm0 == RES_VOID ) || ( comm1 == RES_VOID ) || ( comm2 == RES_VOID ) )
    {
        drv_rmd( comm0 );
        drv_rmd( comm1 );
        drv_rmd( comm2 );
        return OSE_NO_DEVICE;
    }

    drv_ioctl( comm0, IPMP_PAUSE, NULL );
    drv_ioctl( comm1, IPMP_PAUSE, NULL );
    drv_ioctl( comm2, IPMP_PAUSE, NULL );

    res = drv_ioctl( comm0, IPMP_LOAD_PLIS, ptr_crypt );

    drv_ioctl( comm2, IPMP_CONTINUE, NULL );
    drv_ioctl( comm1, IPMP_CONTINUE, NULL );
    drv_ioctl( comm0, IPMP_CONTINUE, NULL );

    drv_rmd( comm0 );
    drv_rmd( comm1 );
    drv_rmd( comm2 );
    
    return res;
}
//--------------------------------------------------------------------
int DropPLIS()
{
	return LoadPLISFromUSB("/vfat/a/sv6.bin");
}
//--------------------------------------------------------------------
//----------------------------------------------------------------------------
void CrypterInit()
{

}
//----------------------------------------------------------------------------
void ResetPLIS()
{

}

*/
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
//-------------Функции работы с устройством простой замены--------------------
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
void UpzLoadBP(void* bp)
{
    while(RG_STATUS_UPZ&CRYPT_UPZ_BUSY);

    memcpy(&RG_BP_UPZ,bp,128);

    RG_CTRL_UPZ = CMD_WR_UPZ_BP|CMD_RG_IS_SET;	
}
//----------------------------------------------------------------------------
void UpzLoadKey(void* key)
{
    while(RG_STATUS_UPZ&CRYPT_UPZ_BUSY);

    memcpy(&RG_KEY_UPZ,key,32);

    RG_CTRL_UPZ = CMD_WR_UPZ_KEY|CMD_RG_IS_SET;
}
//----------------------------------------------------------------------------
void UpzOperateBlock(void* text,uint16 blk, uint64 cmd)//blk-количество 8 байтовых блоков
{
    while(RG_STATUS_UPZ&CRYPT_UPZ_BUSY);

    memcpy(&RG_DATA_IN_UPZ,text,blk*8);

    RG_CTRL_UPZ = ((uint64)(blk-1)<<16)|cmd|CMD_RG_IS_SET;

    while(!(RG_STATUS_UPZ&CRYPT_UPZ_HAVE_DATA));

    memcpy(text,&RG_DATA_OUT_UPZ,blk*8);
}
//----------------------------------------------------------------------------
void UpzEncrypt(void* text,uint16 len)
{
    uint16 blk64 = len/64;

    uint64* t = (uint64*)text;	

    while(RG_STATUS_UPZ&CRYPT_UPZ_BUSY);
    RG_CTRL_UPZ = ((uint64)(63)<<16)|CMD_UPZ_RESET|CMD_RG_IS_SET;
    while(RG_STATUS_UPZ&CRYPT_UPZ_BUSY);

    while(blk64--)
    {
        UpzOperateBlock(t,64,CMD_UPZ_ENCRYPT);
        t+=64;
    }

    int ost=len&63;

    if(ost)
        UpzOperateBlock(t,ost,CMD_UPZ_ENCRYPT);
}
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
//---------------Функции работы с абонентским шифратором----------------------
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
        AbOperateBlock(t,ost,CMD_AB_ENCRYPT);
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
        AbOperateBlock(t,ost,CMD_AB_DECRYPT);
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
void ChLoadBP(void* bp)
{
    while(RG_STATUS_BUSY_CH&CRYPT_CH_BUSY);

    memcpy(&RG_IN_DATA_CH,bp,128);

    RG_CTRL_CH = CH_LOAD_BP;	
}
//----------------------------------------------------------------------------
void ChSetStartSync(uint64 sync)
{
    while(RG_STATUS_BUSY_CH&CRYPT_CH_BUSY);

    memcpy(&RG_IN_DATA_CH,&sync,8);

    RG_CTRL_CH = CH_LOAD_SP;
}
//----------------------------------------------------------------------------
void ChSetAdd(uint64 add)
{
    while(RG_STATUS_BUSY_CH&CRYPT_CH_BUSY);

    memcpy(&RG_IN_DATA_CH,&add,8);

    RG_CTRL_CH = CH_LOAD_DB;
}
//----------------------------------------------------------------------------
void ChSetKi(void* key)
{
    while(RG_STATUS_BUSY_CH&CRYPT_CH_BUSY);

    memcpy(&RG_IN_DATA_CH,key,32);

    RG_CTRL_CH = CH_LOAD_KI;
}
//----------------------------------------------------------------------------
//char ch_int_kb[40];//32b - key and 8b - h
uint64 ch_int_kb[5];//32b - key and 8b - h
//----------------------------------------------------------------------------
void ChSetKb( uint16 keynum, void* key, uint64 h)
{
    memcpy(ch_int_kb,key,32);
    memcpy(((char*)ch_int_kb+32),&h,8);
}
//----------------------------------------------------------------------------
void ChStartMove(uint16 dst_pnum, uint16 dst_addr, uint16 src_pnum, uint16 src_addr, uint16 length)
{
    length &= 0x0fff;

    uint64 src = (0x2000*src_pnum) + src_addr;
    uint64 dst = (0x2000*dst_pnum) + dst_addr;

    while(RG_STATUS_BUSY_CH&CRYPT_CH_BUSY);

    RG_CTRL_CH = (dst << 48)|((uint64)length << 32)|(src << 16)|CH_MOVE_PACKET;	
}
//----------------------------------------------------------------------------
void ChWaitEndMove()
{
    while(RG_STATUS_BUSY_CH&CRYPT_CH_BUSY);
    while(!((RG_STATUS_READY_CH&0xFF)==CH_MOVE_PACKET_DONE));
    RG_STATUS_READY_CH = 0;
}
//----------------------------------------------------------------------------
void ChStartCryptBuf(uint16 src_pnum, uint16 src_addr, uint16 length, uint16 keynum)
{
    length &= 0x0fff;

    uint64 src = (0x2000*src_pnum) + src_addr;

    while(RG_STATUS_BUSY_CH&CRYPT_CH_BUSY);

//    QDMA_Read(&RG_IN_DATA_CH,ch_int_kb,40);//Загрузка рабочего ключа!!!!
    memcpy(&RG_IN_DATA_CH,ch_int_kb,40);//Загрузка рабочего ключа!!!!

    RG_STATUS_READY_CH = 0;

    RG_CTRL_CH = ((uint64)length << 32)|(src << 16)|CH_CODE_PACKET;
}
//----------------------------------------------------------------------------
void ChStartCrypt( uint16 dst_pnum, uint16 dst_addr, uint16 src_pnum, uint16 src_addr, uint16 length, uint16 keynum )
{
    length &= 0x0fff;
    
    uint64 dst = (0x2000*dst_pnum) + dst_addr;

    crypt_param = ((uint64)(length+20) << 32)|(dst << 16);
}
//----------------------------------------------------------------------------
void ChWaitEndCrypt()
{
    while(RG_STATUS_BUSY_CH&CRYPT_CH_BUSY);
    while(!((RG_STATUS_READY_CH&0xFF)==CH_CODE_PACKET_DONE));

    RG_CTRL_CH = crypt_param|CH_PUT_PACKET;

//    while(RG_STATUS_BUSY_CH&CRYPT_CH_BUSY);
//    while(!((RG_STATUS_READY_CH&0xFF)==CH_PUT_PACKET_DONE));

//    RG_STATUS_READY_CH = 0;
}
//----------------------------------------------------------------------------
void ChStartDecryptBuf(uint16 src_pnum, uint16 src_addr, uint16 length, uint16 keynum)
{
    length &= 0x0FFF;

    uint64 src = (0x2000*src_pnum) + src_addr;
 
    while(RG_STATUS_BUSY_CH&CRYPT_CH_BUSY);

    //QDMA_Read(&RG_IN_DATA_CH,ch_int_kb,40);//Загрузка рабочего ключа!!!!
    memcpy(&RG_IN_DATA_CH,ch_int_kb,40);//Загрузка рабочего ключа!!!!

    RG_STATUS_READY_CH = 0;

    RG_CTRL_CH = ((uint64)(length) << 32)|(src << 16)|CH_DECODE_PACKET;
}
//----------------------------------------------------------------------------
void ChStartDecrypt( uint16 dst_pnum, uint16 dst_addr, uint16 src_pnum, uint16 src_addr, uint16 length, uint16 keynum )
{
    length &= 0x0fff;

    uint64 dst = (0x2000*dst_pnum) + dst_addr;

    decrypt_param = ((uint64)(length) << 32)|(dst << 16);
}
//----------------------------------------------------------------------------
uint16 ChWaitEndDecrypt()
{

    while(RG_STATUS_BUSY_CH&CRYPT_CH_BUSY);
    while(!((RG_STATUS_READY_CH&0x1FF)==CH_DECODE_PACKET_DONE));


    if((RG_STATUS_READY_CH&0x3FF)==CH_IMIT_ERR)
    {
        RG_STATUS_READY_CH = 0;
        return IMIT_ERR;
    }
      
    RG_CTRL_CH = decrypt_param|CH_PUT_PACKET;

//    while(RG_STATUS_BUSY_CH&CRYPT_CH_BUSY);
//    while(!((RG_STATUS_READY_CH&0xFF)==CH_PUT_PACKET_DONE));

//    RG_STATUS_READY_CH = 0;
    return 0;
}
//----------------------------------------------------------------------------
void ChCryptCP(uint16 dst_pnum, uint16 dst_addr, void *src_buf, uint16 length, uint16 keynum)
{
    length &= 0x0fff;

    uint64 src = 0x6000;
    uint64 dst = (0x2000*dst_pnum) + dst_addr;

    while(RG_STATUS_BUSY_CH&CRYPT_CH_BUSY);

    //QDMA_Read(&RG_IN_DATA_CH,ch_int_kb,40);//Загрузка рабочего ключа!!!!
    memcpy(&RG_IN_DATA_CH,ch_int_kb,40);//Загрузка рабочего ключа!!!!

//    QDMA_Read(&RG_IN_CP_DATA_CH,src_buf,length);
    //memcpy(&RG_IN_CP_DATA_CH,src_buf,length);
    for(int i=0;i<=length/sizeof(uint64);i++)
	{
	   _amem8(&RG_IN_CP_DATA_CH+i) = _mem8(((uint64*)src_buf)+i);
	}
    
    RG_CTRL_CH = ((uint64)(length) << 32)|(src << 16)|CH_CODE_PACKET;

    crypt_param = ((uint64)(length+20) << 32)|(dst << 16);

    ChWaitEndCrypt();
}
//----------------------------------------------------------------------------
uint16 ChDecryptCP(uint16 src_pnum, uint16 src_addr, void *dst_buf, uint16 length, uint16 keynum )
{
    length &= 0x0fff;

    ChStartDecryptBuf(src_pnum,src_addr,length,keynum);

    while(RG_STATUS_BUSY_CH&CRYPT_CH_BUSY);
    while(!((RG_STATUS_READY_CH&0x1FF)==CH_DECODE_PACKET_DONE));

    //QDMA_Read(dst_buf,&RG_OUT_DATA_CH,length);
    memcpy(dst_buf,&RG_OUT_DATA_CH,length);

    if((RG_STATUS_READY_CH&0x3FF)==CH_IMIT_ERR)
    {
        RG_STATUS_READY_CH = 0;
        return IMIT_ERR;
    }

    RG_STATUS_READY_CH = 0;
    	
    return 0;
}
//----------------------------------------------------------------------------
void ChDecryptIPHeader(uint16 src_pnum, uint16 src_addr, void *dst_buf, uint16 length, uint16 keynum )
{

//    while(RG_STATUS_BUSY_CH&CRYPT_CH_BUSY);
    while(!((RG_STATUS_READY_CH&0x1FF)==CH_DECODE_IPHDR_DONE));
//    sleep_u(1);//1

    //QDMA_Read(dst_buf,&RG_OUT_DATA_CH,24);
    memcpy(dst_buf,&RG_OUT_DATA_CH,24);
}

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
//----------------Функции работы со служебным шифратором----------------------
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
void SLBLoadBP(void* bp)
{
    while(RG_STATUS_BUSY_SLB&CRYPT_SLB_BUSY);

    memcpy(&RG_IN_DATA_SLB,bp,128);

    RG_CTRL_SLB = SLB_LOAD_BP;	

}
//----------------------------------------------------------------------------
void SLBLoadKey(void* key)
{
    while(RG_STATUS_BUSY_SLB&CRYPT_SLB_BUSY);

    memcpy(&RG_IN_DATA_SLB,key,32);

    RG_CTRL_SLB = SLB_LOAD_KI;
}
//----------------------------------------------------------------------------
void ChStartDecryptService(uint16 src_pnum, uint16 src_addr,uint16 length_pack)
{
    length_pack &= 0x0fff;

    uint64 src = (0x2000*src_pnum) + src_addr;

    while(RG_STATUS_BUSY_SLB&CRYPT_SLB_BUSY);

    RG_STATUS_READY_SLB = 0;

    RG_CTRL_SLB = ((uint64)(length_pack+20) << 32)|(src << 16)|SLB_DECRYPT_CB;
}

//----------------------------------------------------------------------------
uint16 ChWaitDecryptService(void* service)
{	
    while(RG_STATUS_BUSY_SLB&CRYPT_SLB_BUSY);
    while(!((RG_STATUS_READY_SLB&0xFF)==SLB_DECRYPT_CB_DONE));

    memcpy(service,&RG_OUT_SERVICE_SLB,16);

    if((RG_STATUS_READY_SLB&0x1FF)==SLB_DECRYPT_CB_ERR)
    {
        RG_STATUS_READY_SLB = 0;
        return IMIT_ERR;
    }

    RG_STATUS_READY_SLB = 0;
 
    return 0;
}
//----------------------------------------------------------------------------
uint16 ChDecryptService(uint16 src_pnum, uint16 src_addr,void* service,uint16 length_pack)
{
    ChStartDecryptService(src_pnum, src_addr,length_pack);
    return ChWaitDecryptService(service);
}
//----------------------------------------------------------------------------
void ChAbLoadKey(void* key)
{
}
//----------------------------------------------------------------------------
void ChAbLoadSync(void* sync)
{
}
//----------------------------------------------------------------------------


