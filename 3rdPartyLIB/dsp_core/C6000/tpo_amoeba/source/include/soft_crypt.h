#ifndef __soft_crypt_H__
#define __soft_crypt_H__

#include <crypto_gost89.h>

typedef uint16 KEY[16];

void xor_n(void* key,uint64 t);
//---------------------------------------------------------------------------------------------------------------
void sModS(uint64 t,void* work_key);
//---------------------------------------------------------------------------------------------------------------
//uint64 inline h2uint(uint16* h);
uint64 h2uint(uint16* h);
//---------------------------------------------------------------------------------------------------------------

extern "C" 
{

void sCrypterInit();

void sAbLoadBP(void* bp);
void sAbLoadKey(void* key);
void sAbEncrypt(void* text,uint16 len);
void sAbDecrypt(void* text,uint16 len);

uint32 sAbImit(void* text,uint16 len);

void sAbStartGamma(void* sync);
void sAbContGamma(void* text, uint16 len);
void sAbGamma(void* sync, void* text, uint16 len);

void sUpzLoadBP(void* bp);
void sUpzLoadKey(void* key);
void sUpzEncrypt(void* text,uint16 len);


void sChReset();
void sChMove( uint16 dst_pnum, uint16 dst_addr, uint16 src_pnum, uint16 src_addr, uint16 length );
void sChCrypt( uint16 dst_pnum, uint16 dst_addr, uint16 src_pnum, uint16 src_addr, uint16 length, uint16 keynum );
void sChCryptCP(uint16 dst_pnum, uint16 dst_addr, void *src_buf, uint16 length, uint16 keynum);

uint16 sChDecryptCP(uint16 src_pnum, uint16 src_addr, void *dst_buf, uint16 length, uint16 keynum);
uint16 sChDecrypt(uint16 dst_pnum, uint16 dst_addr, uint16 src_pnum, uint16 src_addr, uint16 length, uint16 keynum );
uint16 sChDecryptService(uint16 src_pnum, uint16 src_addr,void* service,uint16 length_pack);//Длина всего пакета

void sChLoadBP( void* bp );
void sChSetKi( void* key );
void sChSetKb( uint16 keynum, void* key, uint64 h );
void sChSetAdd( uint64 add);
void sChSetStartSync(uint64 sync);
}

#endif

