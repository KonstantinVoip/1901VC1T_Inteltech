#ifndef __test_crypt_H__
#define __test_crypt_H__
/*
typedef struct _CryptErrors
{
	uint32 NumPack;	//������⢮ ����⮢
	uint32 BodyErr;	//�訡�� � ⥫� ⥪��
	uint32 SlbErr;  //�訡�� � �㦥���� ������
	uint32 ImvErr;  //�訡�� ���⮢�⠢��
	uint32 CtrBErr; //�訡�� ����஫쭮�� ����
	uint32 LostPack; //���७� ����⮢
	uint32 CRCerr; //�訡�� CRC
}CryptErrors;
*/
typedef struct _SrcDstConfig
{
	uint16 len;		//����� ��室���� ⥪��
	uint16 fill;	//���������� ��室���� ⥪��
	uint16 src_num; //����� ����䥩� ���筨��
	uint16 dst_num; //����� ����䥩� �����⥫�
	uint32 src_addr;//���� ���筨��
	uint32 dst_addr;//���� �����⥫�

}SrcDstConfig;

typedef struct _CryptStart
{
	char bp[128];	//���� ����⠭����
	char ki[32];	//���� ��
	uint64 ms;		//�������� �����
	char wk[32];	//����稩 ����
	char sync[8];	//���⮢�� ᨭ�ய��뫪�	
	uint64 h;		//��᫮ h

}CryptStart;

uint32 TestGostAB(uint16 num);

void TestLoadChWKey();

void CrypterChTestLoop();

#endif

