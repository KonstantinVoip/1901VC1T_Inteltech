#ifndef __test_crypt_H__
#define __test_crypt_H__
/*
typedef struct _CryptErrors
{
	uint32 NumPack;	//Количество пакетов
	uint32 BodyErr;	//Ошибок в теле текста
	uint32 SlbErr;  //Ошибок в служебных данных
	uint32 ImvErr;  //Ошибок имитовставки
	uint32 CtrBErr; //Ошибок контрольного байта
	uint32 LostPack; //Потерено пакетов
	uint32 CRCerr; //Ошибок CRC
}CryptErrors;
*/
typedef struct _SrcDstConfig
{
	uint16 len;		//Длина исходного текста
	uint16 fill;	//Заполнение исходного текста
	uint16 src_num; //Номер интерфейса источника
	uint16 dst_num; //Номер интерфейса получателя
	uint32 src_addr;//Адрес источника
	uint32 dst_addr;//Адрес получателя

}SrcDstConfig;

typedef struct _CryptStart
{
	char bp[128];	//Блок подстановки
	char ki[32];	//Ключ КИ
	uint64 ms;		//Добавочные байты
	char wk[32];	//Рабочий ключ
	char sync[8];	//Стартовая синхропосылка	
	uint64 h;		//Число h

}CryptStart;

uint32 TestGostAB(uint16 num);

void TestLoadChWKey();

void CrypterChTestLoop();

#endif

