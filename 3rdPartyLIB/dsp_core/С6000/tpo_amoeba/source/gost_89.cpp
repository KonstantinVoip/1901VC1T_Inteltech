/**********************************************************************************************************************
*                                        (c) COPYRIGHT by ZAO RCZI FORT.                                             *
*        ..                                       All rights reserved.                                               *
***********************************************************************************************************************
* Module      : gost_89.cpp
* Description : Аппаратная Реализация функций алгоритма ГОСТ 28147-89 на Центральном Процессоре.
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
#include "soft_crypt.h"
#include "gost_89.h"


#ifdef IFACE_PROCESSOR
extern uint16 SetProgressDot(uint32 cur_pos,uint32 total_pos);
#endif
//----------------------------------------------------------------------------
void GostCtxCreate(GOST_CTX* ctx,void* uz,void* key)
{
memcpy(ctx->uzb,uz,sizeof(ctx->uzb));

#if (NEED_CONVERT_ENDIAN)
CE_BUF_32(ctx->uzb,sizeof(ctx->uzb));
#endif

GostCtxSetKey(ctx,key);
}
//----------------------------------------------------------------------------
void GostCtxSetKey(GOST_CTX* ctx,void* key)
{
memcpy(ctx->key,key,sizeof(ctx->key));

#if (NEED_CONVERT_ENDIAN)
CE_KEY(ctx->key);
#endif
}
//----------------------------------------------------------------------------
static uint32 f(uint32 x,GOST_CTX* ctx)
{
uint32* p=ctx->uzb;


uint32 y =p[x&0xF]&0x0000000F;
x>>=4;
y|=p[x&0xF]&0x000000F0;
x>>=4;
y|=p[x&0xF]&0x00000F00;
x>>=4;
y|=p[x&0xF]&0x0000F000;
x>>=4;
y|=p[x&0xF]&0x000F0000;
x>>=4;
y|=p[x&0xF]&0x00F00000;
x>>=4;
y|=p[x&0xF]&0x0F000000;
x>>=4;
y|=p[x&0xF]&0xF0000000;


/*
uint32 mask=0xF;

for(int i=0;i<8;i++)
        {
        y|=ctx->uzb[x&0xF]&mask;
        x>>=4;
        mask<<=4;
        }
*/
return y<<11| y>>(32-11);
}
//----------------------------------------------------------------------------
void IterIncrement(uint32* n,GOST_CTX* ctx)
{
uint32* k=ctx->key;
uint32 n0=_mem4(&n[0]);
uint32 n1=_mem4(&n[1]);

n1 ^= f(n0+(*k++),ctx);
n0 ^= f(n1+(*k++),ctx);

n1 ^= f(n0+(*k++),ctx);
n0 ^= f(n1+(*k++),ctx);

n1 ^= f(n0+(*k++),ctx);
n0 ^= f(n1+(*k++),ctx);

n1 ^= f(n0+(*k++),ctx);
n0 ^= f(n1+(*k++),ctx);

_mem4(&n[0])=n0;
_mem4(&n[1])=n1;
}
//----------------------------------------------------------------------------
void IterDecrement(uint32* n,GOST_CTX* ctx)
{
uint32* k=ctx->key+7;
uint32 n0=_mem4(&n[0]);
uint32 n1=_mem4(&n[1]);

n1 ^= f(n0+(*k--),ctx);
n0 ^= f(n1+(*k--),ctx);
                     
n1 ^= f(n0+(*k--),ctx);
n0 ^= f(n1+(*k--),ctx);
                     
n1 ^= f(n0+(*k--),ctx);
n0 ^= f(n1+(*k--),ctx);
                     
n1 ^= f(n0+(*k--),ctx);
n0 ^= f(n1+(*k--),ctx);

_mem4(&n[0])=n0;
_mem4(&n[1])=n1;
}
//----------------------------------------------------------------------------
void GostEncryptBlock(GOST_CTX* ctx, uint32* text)
{
        IterIncrement(text,ctx);
        IterIncrement(text,ctx);
        IterIncrement(text,ctx);
        IterDecrement(text,ctx);

        uint32 tmp=_mem4(&text[0]);
        _mem4(&text[0])=_mem4(&text[1]);
        _mem4(&text[1])=tmp;
}
//----------------------------------------------------------------------------
void GostDecryptBlock(GOST_CTX* ctx, uint32* text)
{
        IterIncrement(text,ctx);
        IterDecrement(text,ctx);
        IterDecrement(text,ctx);
        IterDecrement(text,ctx);

        uint32 tmp=_mem4(&text[0]);
        _mem4(&text[0])=_mem4(&text[1]);
        _mem4(&text[1])=tmp;
}
//----------------------------------------------------------------------------
//длина в блоках по 64 бита
void GostEncrypt(GOST_CTX* ctx, void* t, uint32 len)
{
        register uint32 *text=(uint32*)t;

        while(len--)
        {
#if (NEED_CONVERT_ENDIAN)
        *text = CE_32(*text);
        text[1] = CE_32(text[1]);
#endif

        GostEncryptBlock(ctx, text);

#if (NEED_CONVERT_ENDIAN)
        *text++ = CE_32(*text);
        *text++ = CE_32(*text);
#else
        text+=2;
#endif
        }
}
//----------------------------------------------------------------------------
//длина в блоках по 64 бита
void GostDecrypt( GOST_CTX* ctx, void* t, uint32 len)
{
        register uint32 *text=(uint32*)t;

        while(len--)
        {
#if (NEED_CONVERT_ENDIAN)
        *text = CE_32(*text);
        text[1] = CE_32(text[1]);
#endif

        GostDecryptBlock(ctx, text);

#if (NEED_CONVERT_ENDIAN)
        *text++ = CE_32(*text);
        *text++ = CE_32(*text);
#else
        text+=2;
#endif
        }
}
//----------------------------------------------------------------------------
#define C1 0x01010104
#define C2 0x01010101

void GostStartGamma(GOST_CTX* ctx, void* sync )
{
#if (NEED_CONVERT_ENDIAN)
        ctx->sync[0]=CE_32(sync[0]);
        ctx->sync[1]=CE_32(sync[1]);
#else
        memcpy(ctx->sync,sync,sizeof(ctx->sync));
//      ctx->sync[0]=((uint32*)sync)[0];
//      ctx->sync[1]=((uint32*)sync)[1];
#endif
        GostEncryptBlock(ctx, ctx->sync);
}
//----------------------------------------------------------------------------
void GostContGamma(GOST_CTX* ctx, void* t, uint32 len)
{
	uint32 pos,total;
	uint32 gamma[2];
	uint32* text=(uint32*)t;

	pos = 0;
	total = len;

	while (len--) 
	{
                ctx->sync[0] += C2;

                ctx->sync[1] += C1;
                if (ctx->sync[1] < C1)       /* Wrap modulo 2^32? */
                        ctx->sync[1]++;      /* Make it modulo 2^32-1 */

                memcpy(gamma,ctx->sync,sizeof(gamma));
                GostEncryptBlock(ctx, gamma);

                _mem4(text) = _mem4(text)^gamma[0];
                text++;
                _mem4(text) = _mem4(text)^gamma[1];
                text++;

#ifdef IFACE_PROCESSOR
				SetProgressDot(pos,total);
				pos++;
#endif
        }
}
//----------------------------------------------------------------------------
void GostGamma(GOST_CTX* ctx, void* sync ,void* text, uint32 len)
{
uint32 l=len&(~(64/CHAR_BIT-1));
char t[64/CHAR_BIT];
uint16 ost=len&(64/CHAR_BIT-1);

GostStartGamma(ctx,sync );
GostContGamma(ctx, text, len/(64/CHAR_BIT));

if(ost)
        {
        memset(t,0,sizeof(t));
        memcpy(t,(char*)text+l,ost);
        GostContGamma(ctx, t, 1);

        for(int i=0;i<ost;i++)
                *((char*)text+l+i)=t[i];
        }
}
//----------------------------------------------------------------------------
//длина в 64 битных блоках
void GostImit(GOST_CTX* ctx, void* t, uint32 len)
{
	uint32 pos,total;
	uint32* text=(uint32*)t;

#if (NEED_CONVERT_ENDIAN)
        ctx->imv[0] = CE_32(ctx->imv[0]);
        ctx->imv[1] = CE_32(ctx->imv[1]);
#endif
	pos = 0;
	total = len;

	while (len--)
    {

#if (NEED_CONVERT_ENDIAN)
		ctx->imv[0] ^= CE_32(*text++);
		ctx->imv[1] ^= CE_32(*text++);
#else   
		ctx->imv[0] ^= _mem4(&text[0]);
		ctx->imv[1] ^= _mem4(&text[1]);
		text+=2;
#endif

		IterIncrement(ctx->imv,ctx);
		IterIncrement(ctx->imv,ctx);

#ifdef IFACE_PROCESSOR
		SetProgressDot(pos,total);
		pos++;        
#endif
	}

#if (NEED_CONVERT_ENDIAN)
        ctx->imv[0]=CE_32(ctx->imv[0]);
        ctx->imv[1]=CE_32(ctx->imv[1]);
#endif
}
//----------------------------------------------------------------------------
//длина в char'ах
uint32 GostImitChar(GOST_CTX* ctx, void* text, uint32 len)
{
uint32 im2[4];
memset(ctx->imv,0,sizeof(ctx->imv));
memset(im2,0,sizeof(im2));

if (len<(128/CHAR_BIT))
        {
        memcpy(im2,text,len);
        GostImit(ctx, im2, 2);
        }
else
        {
        GostImit(ctx, text, len/(64/CHAR_BIT));

        if (len%(64/CHAR_BIT))
                {
                uint32 l=len&(~(64/CHAR_BIT-1));
                memcpy(im2,(char*)text+l,len&(64/CHAR_BIT-1));
                GostImit(ctx, im2,1);
                }
        }

return *ctx->imv;
}
//----------------------------------------------------------------------------
uint32 GostCheckImit(GOST_CTX* ctx, void* text, void* imit, uint32 len)
{
return _mem4(imit)^GostImitChar(ctx, text, len);
}
//----------------------------------------------------------------------------
uint32 GostCreateImit(GOST_CTX* ctx, void* text, void* imit, uint32 len)
{
return _mem4(imit) = GostImitChar(ctx, text, len);
}
//----------------------------------------------------------------------------
//
uint32 GostCreateImitBlock(GOST_CTX* ctx, void* text, void* imit, uint32 len, int fcont)
{
 uint32 im2[4];
 memset(im2,0,sizeof(im2));

 if (!fcont)
 {
   memset(ctx->imv,0,sizeof(ctx->imv));

   if (len<(128/CHAR_BIT))
   {          
     memcpy(im2,text,len);
     GostImit(ctx, im2, 2); 
     return _mem4(imit) = *ctx->imv;
   }
 }

 GostImit(ctx, text, len/(64/CHAR_BIT));
 if (len&(64/CHAR_BIT-1))
 {
    uint32 l=len&(~(64/CHAR_BIT-1));
    memcpy(im2,(char*)text+l,len&(64/CHAR_BIT-1));
    GostImit(ctx, im2,1);
 }

 return _mem4(imit) = *ctx->imv;
}
//----------------------------------------------------------------------------
