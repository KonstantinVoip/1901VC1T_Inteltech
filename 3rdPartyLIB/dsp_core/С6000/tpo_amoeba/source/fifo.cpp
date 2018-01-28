#include "fifo.h"
//#include "utils.h"
#include <rts.h>
#include "qdma_rwrd.h"

#define SPARCA

#define FIFO_BASE_IN                    0xA0000000
#define FIFO_BASE_OUT_1                 0xC0000000
#define FIFO_BASE_OUT_2                 0xD0000000

//-----------------------------------------------------------------------------------------------------------
//---------Флаги для работы с FIFO---------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
#define FIFO_NOTREADY_FOR_WRITE         0x0000000000000001ull
#define FIFO_READY_FOR_READ             0x0000000000000002ull
#define CRYPTER_IMIT_ERROR              0x0000000000000010ull
//-----------------------------------------------------------------------------------------------------------
//---------Комманды для работы с FIFO------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
#define CMD_SP_READ_PACKET              0x0000000000000000ull
#define CMD_SP_WRITE_PACKET             0x0000000000000001ull
//-----------------------------------------------------------------------------------------------------------
//---------Регистры для работы с FIFO------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
#define VADR64( a )                     ((uint64*)(a))
#define VREG64( a )                     (*(volatile uint64*)(a))

#define RG_CTRL_FIFO_WR                 VREG64(0xA0000000)//Регистр управления FIFO на запись в шифратор
#define RG_STAT_FIFO_WR_1               VREG64(0xC0000000)//Регистр состояния FIFO на запись в шифратор
#define RG_STAT_FIFO_WR_2               VREG64(0xD0000000)//Регистр состояния FIFO на запись в шифратор

#define RG_CTRL_FIFO_RD_1               VREG64(0xC0000800)//Регистр управления FIFO на чтение из шифратора
#define RG_CTRL_FIFO_RD_2               VREG64(0xD0000800)//Регистр управления FIFO на чтение из шифратора

#define RG_HDR_IN                       VREG64(0xA0000008)//Регистр служебных данных 24 байта
#define RG_HDR_NUM                      VREG64(0xC0000018)//Регистр c номером пакета
#define RG_PACKET_IN                    VREG64(0xD0000020)//Регистр начала пакета без eth

#define RG_HDR_OUT_1                    VREG64(0xC0000808)//Регистр служебных данных 24 байта
#define RG_PACKET_OUT_1                 VREG64(0xC0000820)//Регистр начала пакета без eth

#define RG_HDR_OUT_2                    VREG64(0xD0000808)//Регистр служебных данных 24 байта
#define RG_PACKET_OUT_2                 VREG64(0xD0000820)//Регистр начала пакета без eth
//-----------------------------------------------------------------------------------------------------------
#define ADR_HDR_IN                      VADR64(0xA0000008)//Адрес служебных данных 24 байта
#define ADR_PACKET_IN                   VADR64(0xA0000020)//Адрес начала пакета без eth

#define ADR_HDR_OUT_1                   VADR64(0xC0000808)//Адрес служебных данных 24 байта
#define ADR_PACKET_OUT_1                VADR64(0xC0000820)//Адрес начала пакета без eth

#define ADR_HDR_OUT_2                   VADR64(0xD0000808)//Адрес служебных данных 24 байта
#define ADR_PACKET_OUT_2                VADR64(0xD0000820)//Адрес начала пакета без eth

#define ADR_PACK_RD_IN1                 VADR64(0xC0000008)//Адрес начала пакета записанного в FIFO для проверки 1канала
#define ADR_PACK_RD_IN2                 VADR64(0xD0000008)//Адрес начала пакета записанного в FIFO для проверки 2канала

#define RG_CONST_CH1                    VREG64(0xC0003ff8)//Регистр константы
#define RG_CONST_CH2                    VREG64(0xD0003ff8)//Регистр константы
//-----------------------------------------------------------------------------------------------------------
#define C_ALFA2006                      0x414c464132303036//Константа ALFA2006
#define C_GOST2006                      0x474f535432303036//Константа GOST2006
//-----------------------------------------------------------------------------------------------------------
uint64 wr_check_buf1[2048/sizeof(uint64)];
uint64 wr_check_buf2[2048/sizeof(uint64)];
//-----------------------------------------------------------------------------------------------------------
uint16 shift_ip_write;
uint16 plen_write;
uint32 bad_offset = 0;

volatile uint64 wr_packet_num = 0;

typedef uint64 cmp_unit;

extern uint8 check_buf[2048/sizeof(uint8)];


uint64 *check_pkt;

int memcmp_xor(void* src1,void* src2,uint32 len)
{
    register cmp_unit* s1=(cmp_unit*)src1;
    register cmp_unit* s2=(cmp_unit*)src2;

    uint32 l=len/sizeof(cmp_unit);

    while(l--)
//      if(_amem4(s1++)^_amem4(s2++))
    if(_mem8(s1++)^_amem8(s2++))
        return 1;

    uint32 ost=len&(sizeof(cmp_unit)-1);

    if(ost)
        return memcmp(s1,s2,ost);

    return 0;
}
//----------------------------------------------------------------------------
void FIFO_FreeRD()
{
    RG_CTRL_FIFO_RD_1 = CMD_SP_READ_PACKET;
    RG_CTRL_FIFO_RD_2 = CMD_SP_READ_PACKET;
}
//----------------------------------------------------------------------------
void WriteFIFO(uint32 addr,void* buf,uint16 len)
{
    uint32 l=(len+7)>>3;
    uint64* s = (uint64*)buf;
    uint64* d = (uint64*)addr;

    while(l--)
#ifndef EMULATOR
    _amem8(d++)=_mem8(s++);
#else
    *(d++) = *(s++);
#endif
}
//----------------------------------------------------------------------------
int FIFO_inIsReady()
{

#ifndef SPARCA
    if(RG_STAT_FIFO_WR_1&FIFO_NOTREADY_FOR_WRITE)
        return 0;//FIFO для записи не готово 
    else
        return 1;//В FIFO можно писать пакет
#else
    if((RG_STAT_FIFO_WR_1&FIFO_NOTREADY_FOR_WRITE)
     &&(RG_STAT_FIFO_WR_2&FIFO_NOTREADY_FOR_WRITE))
        return 0;//FIFO для записи не готово
    else	
        return 1;//В FIFO можно писать пакет
#endif

}
//----------------------------------------------------------------------------
uint16 FIFO_outIsReady()
{
    uint64 freg1, freg2;
//    uint64 const1, const2;

#ifndef SPARCA

    if(RG_CTRL_FIFO_RD_1&FIFO_READY_FOR_READ)
    {
        uint16 len = ((RG_CTRL_FIFO_RD_1&0x00000000FFF0000)>>16)-8-24;
        if(len>1560)
        {

//            InternalError(1);
        }
        else 
            return ((RG_CTRL_FIFO_RD_1&0x00000000FFF0000)>>16)-8-24;//длина пакета с IP заголовком		
    }
    else	
        return 0;//В FIFO нет пакета для чтения
#else
    uint16 len1,len2;

    freg1 = RG_CTRL_FIFO_RD_1;
    freg2 = RG_CTRL_FIFO_RD_2;

    if((freg1&FIFO_READY_FOR_READ)&&(freg2&FIFO_READY_FOR_READ))
    {
//        const1 = RG_CONST_CH1;
//        const2 = RG_CONST_CH2;
//        if(((const1 != C_GOST2006)&&(const1 != C_ALFA2006))||((const2 != C_GOST2006)&&(const2 != C_ALFA2006)))
//           return 0;
        freg1 = RG_CTRL_FIFO_RD_1;
        freg2 = RG_CTRL_FIFO_RD_2;

        len1 = ((freg1&0x00000000FFF0000)>>16)-8-24;
        len2 = ((freg2&0x00000000FFF0000)>>16)-8-24;

        if((len1 != len2)||(len1 > 1560)||(len2 > 1560))
        {
            syslog(1,"len1 = %d  len2 = %d",len1,len2);
            syslog(1,"freg1= %lu  freg2= %lu",len1,len2);

            FIFO_DropPacket();//Сливаем пакет из FIFO;
			return 0;
            //InternalError(2);
        }
        else 
            return len1;//длина пакета с IP заголовком			
    }
    else	
        return 0;//В FIFO нет пакета для чтения
#endif
return 0;
}
//----------------------------------------------------------------------------
uint16 FIFO_WritePacket(void *hdr,void *packet,uint16 shift_ip, uint16 p_len)
{
    char *h = (char*)hdr;
    char *p = (char*)packet;

//	WriteFIFO((uint64)&RG_HDR_IN,h,24);
    QDMA_Write(ADR_HDR_IN,h,24);

//	WriteFIFO((uint64)&RG_PACKET_IN,p,p_len+shift_ip);
    QDMA_Write(ADR_PACKET_IN,p,p_len+shift_ip);

    RG_CTRL_FIFO_WR =  ((uint64)(8+24+shift_ip)<<8)|CMD_SP_WRITE_PACKET;

    return 0;
}
//----------------------------------------------------------------------------
uint64 old_value2 = 0;
void FIFO_StartWritePacket(void *hdr,void *packet,uint16 shift_ip, uint16 p_len)
{
    char *h = (char*)hdr;
    char *p = (char*)packet;

    shift_ip_write = shift_ip;
/*	
	if((!os_system_chkname("comm2")) && ((p_len) > 600) )
	{
		if(old_value2 == *(uint64*)(p+160))
		{
			while(1)
				asm(" nop");
		}
		old_value2 = *(uint64*)(p+160);
	}
*/
//    plen_write = p_len+shift_ip;
    QDMA_Write(ADR_HDR_IN,h,24);
    QDMA_StartWrite(ADR_PACKET_IN,p,p_len+shift_ip);
//    while(!QDMA_CheckEndWrite());
/*
    if(CheckWritePacket())
    {
        asm("  nop");
        InternalError();
    }
*/
//    RG_CTRL_FIFO_WR = ((uint64)(8+24+shift_ip_write)<<8)|CMD_SP_WRITE_PACKET;	
}
//----------------------------------------------------------------------------
int FIFO_EndWritePacket()
{
//   return 1;
//	uint64 tmpr;

    if(!QDMA_CheckEndWrite())
	 	return 0;
/*
	wr_packet_num++;

	tmpr = (wr_packet_num<<16)|(RG_HDR_NUM);
	
	memcpy((ADR_HDR_IN+2),&tmpr,sizeof(wr_packet_num));
*/
    RG_CTRL_FIFO_WR = ((uint64)(8+24+shift_ip_write)<<8)|CMD_SP_WRITE_PACKET;	
    return 1;
}
//----------------------------------------------------------------------------
int FIFO_ReadHdr(void *hdr)
{
    uint64 *h = (uint64*)hdr;
#ifdef SPARCA
    QDMA_StartRead2Ch(h,check_buf,ADR_HDR_OUT_1,ADR_HDR_OUT_2,24);
    while(!QDMA_EndRead2Ch());
/*
    memcpy(hdr,ADR_HDR_OUT_1,24);
    memcpy(check_buf,ADR_HDR_OUT_2,24);
*/
    if(memcmp_xor(hdr,check_buf,24))
        return 1;
#else
    QDMA_Read(h,ADR_HDR_OUT_1,24);
#endif
    return 0;
}
//----------------------------------------------------------------------------
uint16 rd_pack_len;
//----------------------------------------------------------------------------
void FIFO_StartReadPacket(void *packet,uint16 lan, uint16 len)
{
    uint64 *p   = (uint64*)packet;
//    uint64 *out1 = ADR_HDR_OUT_1;//ADR_PACKET_OUT_1;
//   uint64 *out2 = ADR_HDR_OUT_2;//ADR_PACKET_OUT_2;
    uint64 *out1 = ADR_PACKET_OUT_1;
    uint64 *out2 = ADR_PACKET_OUT_2;

#ifdef SPARCA
    
    check_pkt = p;

    rd_pack_len	= len;

    QDMA_StartRead2Ch(p,check_buf,out1,out2,len);
#else
    QDMA_StartRead(p,out1,len);
#endif
}
//----------------------------------------------------------------------------
int FIFO_EndReadPacket()
{
#ifdef SPARCA
    if(!QDMA_EndRead2Ch())
        return 0;

//    RG_CTRL_FIFO_RD_1 = CMD_SP_READ_PACKET;
//    RG_CTRL_FIFO_RD_2 = CMD_SP_READ_PACKET;

//    if(memcmp_xor(check_pkt,check_buf,rd_pack_len))
//        InternalError();//SPARCA ERROR*/

    RG_CTRL_FIFO_RD_1 = CMD_SP_READ_PACKET;
    RG_CTRL_FIFO_RD_2 = CMD_SP_READ_PACKET;
	
#else
    if(!QDMA_CheckEndRead())
        return 0;
    RG_CTRL_FIFO_RD_1 = CMD_SP_READ_PACKET;
#endif
    return 1;
}
//----------------------------------------------------------------------------
void FIFO_DropPacket()
{
    RG_CTRL_FIFO_RD_1 = CMD_SP_READ_PACKET;
#ifdef SPARCA
    RG_CTRL_FIFO_RD_2 = CMD_SP_READ_PACKET;
#endif
}
//----------------------------------------------------------------------------

uint16 CheckWritePacket()
{
    QDMA_Read(wr_check_buf1,ADR_PACK_RD_IN1,24+plen_write);
    QDMA_Read(wr_check_buf2,ADR_PACK_RD_IN2,24+plen_write);

    if(memcmp_xor(wr_check_buf1,wr_check_buf2,24+plen_write))
        return 1;
    else
        return 0;
}


