#ifndef GOST_89_H
#define GOST_89_H

/** @file
@brief Шифрование по ГОСТ.28147-89
*/

typedef struct _GOST_CTX
{
uint32 uzb[16];
uint32 key[8];
uint32 sync[2];
uint32 imv[2];
}GOST_CTX;

void GostCtxCreate(GOST_CTX* ctx,void* uz,void* key);
void GostCtxSetKey(GOST_CTX* ctx,void* key);

//for hash (no endian support)
void GostEncryptBlock(GOST_CTX* ctx, uint32* text);

void GostEncrypt(GOST_CTX* ctx, void* text, uint32 len);
void GostDecrypt(GOST_CTX* ctx, void* text, uint32 len);

void GostStartGamma(GOST_CTX* ctx,void* sync); 
void GostContGamma(GOST_CTX* ctx, void* text, uint32 len);
void GostGamma(GOST_CTX* ctx ,void* sync,void* text, uint32 len);

void GostImit(GOST_CTX* ctx, void* text, uint32 len);
uint32 GostCreateImit(GOST_CTX* ctx, void* text, void* imit, uint32 len );
uint32 GostCreateImitBlock(GOST_CTX* ctx, void* text, void* imit, uint32 len, int fcont );
uint32 GostCheckImit(GOST_CTX* ctx, void* text, void* imit, uint32 len );

#endif //GOST_89_H
