#ifndef __Crypter17_H__
#define __Crypter17_H__

#include <os_types.h>

#define CMD_PUT_IN_NULL		0x0000000000000000ull //����� �����
#define CMD_PUT_IN_SP0		0x0000000000000010ull//�������� ����� � ��0
#define CMD_PUT_IN_SP1		0x0000000000000020ull//�������� ����� � ��1
#define CMD_PUT_IN_SP2		0x0000000000000040ull//�������� ����� � ��2

//----------------------------------------------------------------------------------------------
#define CMD_CH_STOP_WORK	0x0000000000000001ull//������� ���������� ��������� ������� ����������
#define CMD_CH_REPEAT_FIND_KEY	0x0000000000000040ull//������� �� ��������� ����� ����� � ���
#define CMD_CH_RESET_PACKET	0x0000000000000080ull//������� �� �������� �������� ������
//----------------------------------------------------------------------------------------------

#define CH_ERR_LOSTKEY		0x0001ull//���� �� ������
#define CH_ERR_M_MORE6		0x0002ull//� �������� h ������ ��� 6
#define CH_ERR_M_LESS12		0x0004ull//� �������� h ������ ��� 12
#define CH_ERR_KVARTAL		0x0008ull//����� �������� �� ����� ������ �� ����
#define CH_ERR_ZEROBIT		0x0010ull//������ � ������� ����� h
#define CH_ERR_WINDOW		0x0020ull//h �� �������� "����"
#define CH_ERR_CTRLBYTE		0x0040ull//������ ������������ �����
#define CH_ERR_CMD		0x0080ull//�������� ����������� ��������� �������
#define CH_ERR_NOCMD		0x0100ull//�������� �� ��������� �������
#define CH_ERR_MTU		0x0200ull//������ MTU �� ������������

#define CH_IMIT_ERR         0x0080//������ ������������                                	
#define CH_HAVE_PACKET      0x0100//� ��������� ���� �����                                	
 
typedef struct _CryptIPRec
{
	uint32 ip;
	uint32 mask;
	uint32 n_key;
	uint16 m_lable;
	uint32 indx;

}CryptIPRec;

typedef struct _CryptKeyRec
{
	uint64 MKey[4];
	uint64 NKey[4];
	uint64 StartH; 
	uint64 CurH;

}CryptKeyRec;

typedef struct _DecryptKeyRec
{
	uint64 MKey[4];
	uint64 NKey[4];
	uint64 N1Key[4];
	uint64 Window[4];
	uint64 StartH; 
	uint64 CurH;

}DecryptKeyRec;



void InitGPIO();

int LoadPLISFromRAM();//�������� ���� �� ���
int LoadPLISFromUSB();

void CrypterInit();

void AbLoadBP(void* bp);
void AbLoadKey(void* key);
void AbEncrypt(void* text,uint16 len);
void AbDecrypt(void* text,uint16 len);
uint32 AbImit(void* text,uint16 len);
void AbStartGamma(void* sync);
void AbContGamma(void* text, uint16 len);
void AbGamma(void* sync, void* text, uint16 len);


//----------------------------------------------------------------------------
void ChSetCryptKi(void* key);
void ChLoadCryptBP(void* bp);
//----------------------------------------------------------------------------
void ChSetDecryptKi(void* key);
void ChLoadDecryptBP(void* bp);
//----------------------------------------------------------------------------
void ChSetStartSync(uint64 sync);
//----------------------------------------------------------------------------
void ChSetCryptCurM(uint32 CurM);
uint64* ChGetDecryptCurh(uint16 n_rec);
//----------------------------------------------------------------------------
uint16 ChSetCryptIPRec(uint16 n_rec,CryptIPRec *IPRec);
uint16 ChGetCryptIPRec(uint16 n_rec,uint32* indx,CryptIPRec *IPRec);
//----------------------------------------------------------------------------
uint16 ChSetDecryptIPRec(uint16 n_rec,CryptIPRec *IPRec);
uint16 ChGetDecryptIPRec(uint16 n_rec,uint32* indx,CryptIPRec *IPRec);
//----------------------------------------------------------------------------
uint16 ChSetCryptWKey(uint16 n_rec,CryptKeyRec *KeyRec);
uint16 ChSetDecryptWKey(uint16 n_rec,DecryptKeyRec *KeyRec);
//----------------------------------------------------------------------------
CryptKeyRec* ChGetCryptWKey(uint16 n_rec);
DecryptKeyRec* ChGetDecryptWKey(uint16 n_rec);
//----------------------------------------------------------------------------
uint16 ChCheckCryptFlag(uint64 *n_ip, uint64* h);
uint16 ChCheckDecryptFlag(uint64 *n_ip, uint64 *h, uint16 *n_addbyte);
//----------------------------------------------------------------------------
uint16 ChCheckCryptErFlag();
uint16 ChCheckDecryptErFlag();
//----------------------------------------------------------------------------
void ChSendCryptPacket(uint64 n_comm);
uint16 ChSendDecryptPacket(uint64 n_comm);
//----------------------------------------------------------------------------
void ChSetMTU(uint16 mtu,uint16 fpl);
void ChSetMCU(uint16 mcu1,uint16 mcu2,uint16 mcu3,uint16 mcu4);
//----------------------------------------------------------------------------
void ChSetMLable(uint8 ml_sp0,uint8 ml_sp1,uint8 ml_sp2, uint8 ml_cp);
//----------------------------------------------------------------------------
uint64 ChGetCurSync();
//----------------------------------------------------------------------------
void ChCryptCP(void *hdr,void *packet,uint16 shift_ip,uint16 p_len,uint16 fp);
//----------------------------------------------------------------------------
void ChMoveCP(void *eth_hdr,void *packet,uint16 shift_ip,uint16 p_len,uint64 n_comm);
//----------------------------------------------------------------------------
void ChGetCryptEthHeader(void *eth_hdr,uint16 flag);
void ChGetCryptIPHeader(void *ip_hdr,uint16 offset,uint16 len, uint16 flag);
//----------------------------------------------------------------------------
void ChGetDecryptEthHeader(void *eth_hdr,uint16 flag);
void ChGetDecryptIPHeader(void *ip_hdr, uint16 offset,uint16 len,uint16 flag);
//----------------------------------------------------------------------------
void ChSetCryptCtrlCmd(uint64 cmd);
//----------------------------------------------------------------------------
void ChSetDecryptCtrlCmd(uint64 cmd);
//----------------------------------------------------------------------------
void ChSetCryptEthHeader(void *eth_hdr,uint16 len);
//----------------------------------------------------------------------------
void ChSetDecryptEthHeader(void *eth_hdr,uint16 len);
//----------------------------------------------------------------------------
void ChStopCrypt();
//----------------------------------------------------------------------------
void ChStopDecrypt();
//----------------------------------------------------------------------------
void ChStartCrypt();
//----------------------------------------------------------------------------
void ChStartDecrypt(uint8 ml_sp0,uint8 ml_sp1,uint8 ml_sp2,uint8 ml_cp);
//----------------------------------------------------------------------------
uint16 ChReadyCryptCP();//1-������ ��� ���������� ������ CryptCP
//----------------------------------------------------------------------------
uint16 ChReadyMoveCP();// 1-������ ��� ���������� ������ MoveCP
//----------------------------------------------------------------------------
void ChCryptResetMask(void *mask);
//----------------------------------------------------------------------------
void ChDecryptResetMask(void *mask);
//----------------------------------------------------------------------------
void ChCryptLoadMask(uint16 offset,void *mask,uint16 len);////offset-�������� � ������ �� 8 ����
//----------------------------------------------------------------------------
void ChDecryptLoadMask(uint16 offset,void *mask,uint16 len);//offset-�������� � ������ �� 8 ����
//----------------------------------------------------------------------------
void WaitBusy();

#endif

