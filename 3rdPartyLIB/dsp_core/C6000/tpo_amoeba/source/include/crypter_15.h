#ifndef __Crypter_15_H__
#define __Crypter_15_H__

#include <os_types.h>

void InitGPIO();

//int LoadPLISFromRAM();//Загрузка ПЛИС из ОЗУ
//int LoadPLISFromUSB();

void AbResetCrypter();
void AbLoadBP(void* bp);
void AbLoadKey(void* key);
void AbEncrypt(void* text,uint16 len);
void AbDecrypt(void* text,uint16 len);
uint32 AbImit(void* text,uint16 len);
void AbStartGamma(void* sync);
void AbContGamma(void* text, uint16 len);
void AbGamma(void* sync, void* text, uint16 len);

void UpzLoadBP(void* bp);
void UpzLoadKey(void* key);
void UpzEncrypt(void* text,uint16 len);

void ChStartMove( uint16 dst_pnum, uint16 dst_addr, uint16 src_pnum, uint16 src_addr, uint16 length );
void ChWaitEndMove();

void ChStartCrypt( uint16 dst_pnum, uint16 dst_addr, uint16 src_pnum, uint16 src_addr, uint16 length, uint16 keynum );
void ChWaitEndCrypt();

void ChStartDecrypt( uint16 dst_pnum, uint16 dst_addr, uint16 src_pnum, uint16 src_addr, uint16 length, uint16 keynum );
uint16 ChWaitEndDecrypt();

void ChCryptCP(uint16 dst_pnum, uint16 dst_addr, void *src_buf, uint16 length, uint16 keynum);

uint16 ChDecryptCP(uint16 src_pnum, uint16 src_addr, void *dst_buf, uint16 length, uint16 keynum);
uint16 ChDecryptService(uint16 src_pnum, uint16 src_addr,void* service,uint16 length_pack);//Длина всего пакета

void ChLoadBP( void* bp );
void ChSetKi( void* key );
void ChSetKb( uint16 keynum, void* key, uint64 h );
void ChSetAdd( uint64 add);
void ChSetStartSync(uint64 sync);

void ChLoadKbToCache( uint16 key_index );

void ChAbLoadKey(void* key);
void ChAbLoadSync(void* sync);
uint32 ChAbCrypt(uint16 dst_pnum, uint16 dst_addr, uint16 src_pnum, uint16 src_addr, uint16 length);
uint32 ChAbDecrypt(uint16 dst_pnum, uint16 dst_addr, uint16 src_pnum, uint16 src_addr, uint16 length);
uint32 ChAbCryptCP(uint16 src_pnum, uint16 src_addr, void *dst_buf, uint16 length);
uint32 ChAbDecryptCP(uint16 dst_pnum, uint16 dst_addr, void *src_buf, uint16 length);


//void CrypterInit();

#ifdef TPO6
void SLBLoadBP(void* bp);
void SLBLoadKey(void* key);
#endif



#endif


