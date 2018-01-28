//**************************************************************************************************
//                         Copyright (C) 2010 RCZI
//--------------------------------------------------------------------------------------------------
// FILENAME....... crypto_gost89.cpp
// DATE CREATED... 08/04/2010
// LAST MODIFIED.. 08/04/2010
// VERSION........ 1.0
//--------------------------------------------------------------------------------------------------
//                             ГОСТ 28147-89
//--------------------------------------------------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
//
// !: codepage: cp1251 
//
// !: d: ГОСТ 28147-89.<br>
// !: md: Функции для работы с алгоритмами ГОСТ 28147-89.
// !: -:
//***sss********************************************************************************************
#include <rts.h>
#include <crypto_gost89.h>
//-------------------------------------------------------------------------------------------------
#define C1      0x01010104
#define C2      0x01010101
//-------------------------------------------------------------------------------------------------
static void modgost89_upz_encrypt_block(s_gost89* ctx, uint32* text);
static void modgost89_upz_decrypt_block(s_gost89* ctx, uint32* text);
static void modgost89_imit_bolck(s_gost89* ctx, void* text, uint32 blocks);
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//          Внешнии функции
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
void modgost89_load_bp(s_gost89* ctx, void* bp)
{
  memcpy(ctx->bp, bp, sizeof(ctx->bp));
}
//-------------------------------------------------------------------------------------------------
void modgost89_load_key(s_gost89* ctx, void* key)
{
  memcpy(ctx->key, key, sizeof(ctx->key));
}
//-------------------------------------------------------------------------------------------------
void modgost89_start_gamma(s_gost89* ctx, void* sync)
{
  memcpy(ctx->sync, sync, sizeof(ctx->sync));
  modgost89_upz_encrypt_block(ctx, ctx->sync);
}
//-------------------------------------------------------------------------------------------------
void modgost89_cont_gamma(s_gost89* ctx, void* text, uint32 length)
{
  uint32   gamma[2];
  uint32   blocks = length>>3;
  uint32*  txt = (uint32*)text;

  while(blocks--) 
  {
    //Модификация синхропосылки:
    ctx->sync[0] += C2;
    ctx->sync[1] += C1;
    if(ctx->sync[1] < C1)  // Wrap modulo 2^32? 
      ctx->sync[1]++;      // Make it modulo 2^32-1 
    //Выработка гаммы:
    memcpy(gamma, ctx->sync, sizeof(gamma));
    modgost89_upz_encrypt_block(ctx, gamma);   
    //XOR гаммы с данными:
    _mem4(txt) = _mem4(txt)^gamma[0];
    txt++;
    _mem4(txt) = _mem4(txt)^gamma[1]; 
    txt++;
  }
  if(length & 0x7)
  {
    uint32   temp[2];
    temp[0] = 0x0;
    temp[1] = 0x0;    
    memcpy(temp, txt, length&0x7);
    //Модификация синхропосылки:
    ctx->sync[0] += C2;
    ctx->sync[1] += C1;
    if(ctx->sync[1] < C1)  // Wrap modulo 2^32? 
      ctx->sync[1]++;      // Make it modulo 2^32-1 
    //Выработка гаммы:
    memcpy(gamma, ctx->sync, sizeof(gamma));
    modgost89_upz_encrypt_block(ctx, gamma);   
    //XOR гаммы с данными:
    temp[0] = temp[0]^gamma[0];
    temp[1] = temp[1]^gamma[1];
    memcpy(txt, temp, length&0x7);  
  }
}
//-------------------------------------------------------------------------------------------------
void modgost89_gamma(s_gost89* ctx ,void* sync, void* text, uint32 length)
{
  modgost89_start_gamma(ctx, sync);
  modgost89_cont_gamma(ctx, text, length);
}
//-------------------------------------------------------------------------------------------------
uint32 modgost89_imit(s_gost89* ctx, void* text, uint32 length)
{
  memset(ctx->imit, 0x0, sizeof(ctx->imit));
  if(length < 16)
  {
    uint32 imit2[4];
    memset(imit2, 0x0, sizeof(imit2));
    memcpy(imit2, text, length);
    modgost89_imit_bolck(ctx, imit2, 2);
  }
  else
  {
    modgost89_imit_bolck(ctx, text, length>>3);
    if(length & 0x7)
    {
      uint32 imit[2];
      uint32 len_ost= length & ~0x7;
      memset(imit, 0x0, sizeof(imit));
      memcpy(imit, (uint8*)text+len_ost, length&0x7);
      modgost89_imit_bolck(ctx, imit, 1);
    }
  }
  return *&ctx->imit[0];
}
//-------------------------------------------------------------------------------------------------
uint32 modgost89_imit_blocks(s_gost89* ctx, void* text, uint32 length, bool func_continue)
{
  if(func_continue == false)
  {
    memset(ctx->imit, 0x0, sizeof(ctx->imit));

    if(length < 16)
    {          
      uint32 imit2[4];
      memset(imit2, 0x0, sizeof(imit2));
      memcpy(imit2, text, length);
      modgost89_imit_bolck(ctx, imit2, 2); 
      return *&ctx->imit[0];
    }
  }
  modgost89_imit_bolck(ctx, text, length>>3);
  if(length & 0x7)
  {
    uint32 imit[2];
    uint32 len_ost = length & ~0x7;
    memset(imit, 0x0, sizeof(imit));
    memcpy(imit, (uint8*)text+len_ost, length&0x7);
    modgost89_imit_bolck(ctx, imit, 1);
  }
  return *&ctx->imit[0];
}
//-------------------------------------------------------------------------------------------------
// УПЗ шифрование блоков по 8 Байт (64 бит)
void modgost89_upz_encrypt(s_gost89* ctx, void* text, uint32 blocks)
{
  for(int32 i=0; i<blocks; i++)
    modgost89_upz_encrypt_block(ctx, &((uint32*)text)[i<<1]);
}
//-------------------------------------------------------------------------------------------------
// УПЗ дешифрование блока в 8 Байт (64 бит)
void modgost89_upz_decrypt(s_gost89* ctx, void* text, uint32 blocks)
{
  for(int32 i=0; i<blocks; i++)
    modgost89_upz_decrypt_block(ctx, &((uint32*)text)[i<<1]);
}
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//          Внутреннии функции
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
static uint32 f(uint32 x, s_gost89* ctx)
{
  uint32* p=ctx->bp;
  
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
  return y<<11| y>>(32-11);
}
//-------------------------------------------------------------------------------------------------
static void iter_increment(uint32* n, s_gost89* ctx)
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
//-------------------------------------------------------------------------------------------------
static void iter_decrement(uint32* n, s_gost89* ctx)
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
//-------------------------------------------------------------------------------------------------
// Подсчет имитовставки за блок в 8 Байт (64 бит)
static void modgost89_imit_bolck(s_gost89* ctx, void* text, uint32 blocks)
{
  uint32* txt=(uint32*)text;
  while (blocks--)
  {
    ctx->imit[0] ^= _mem4(&txt[0]);
    ctx->imit[1] ^= _mem4(&txt[1]);
    txt += 2;
    iter_increment(ctx->imit, ctx);
    iter_increment(ctx->imit, ctx);
  }
}
//-------------------------------------------------------------------------------------------------
// УПЗ шифрование блока в 8 Байт (64 бит)
static void modgost89_upz_encrypt_block(s_gost89* ctx, uint32* text)
{
  iter_increment(text,ctx);
  iter_increment(text,ctx);
  iter_increment(text,ctx);
  iter_decrement(text,ctx);

  uint32 tmp = _mem4(&text[0]);
  _mem4(&text[0]) = _mem4(&text[1]);
  _mem4(&text[1]) = tmp;
}
//-------------------------------------------------------------------------------------------------
// УПЗ дешифрование блока в 8 Байт (64 бит)
static void modgost89_upz_decrypt_block(s_gost89* ctx, uint32* text)
{
  iter_increment(text,ctx);
  iter_decrement(text,ctx);
  iter_decrement(text,ctx);
  iter_decrement(text,ctx);    

  uint32 tmp = _mem4(&text[0]);
  _mem4(&text[0]) = _mem4(&text[1]);
  _mem4(&text[1]) = tmp;
}
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//          Модульные функции
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
s_os_extension modgost89;

s_os_extension_f modgost89_f[] =
{
  { NULL, SYSCALL_CRYPTO_GOST89_LOAD_BP,           (uint32)&modgost89_load_bp      },
  { NULL, SYSCALL_CRYPTO_GOST89_LOAD_KEY,          (uint32)&modgost89_load_key     },
  { NULL, SYSCALL_CRYPTO_GOST89_START_GAMMA,       (uint32)&modgost89_start_gamma  },
  { NULL, SYSCALL_CRYPTO_GOST89_CONT_GAMMA,        (uint32)&modgost89_cont_gamma   },
  { NULL, SYSCALL_CRYPTO_GOST89_GAMMA,             (uint32)&modgost89_gamma        },
  { NULL, SYSCALL_CRYPTO_GOST89_IMIT,              (uint32)&modgost89_imit         },
  { NULL, SYSCALL_CRYPTO_GOST89_IMIT_BLOCKS,       (uint32)&modgost89_imit_blocks  },
  { NULL, SYSCALL_CRYPTO_GOST89_ENCRYPT_BLOCKS,    (uint32)&modgost89_upz_encrypt  },
  { NULL, SYSCALL_CRYPTO_GOST89_DECRYPT_BLOCKS,    (uint32)&modgost89_upz_decrypt  },
};
// ---------------------------------------------------------------------------
OS_MODULE_INICIATOR( modgost89 )
{
  OS_MODULE_INIT( modgost89 )
  {
    modgost89.name = "modgost89.lif";
    modgost89.f_count = sizeof(modgost89_f) / sizeof(s_os_extension_f);
    modgost89.f_tab = modgost89_f;
    modgost89.flags = EXT_F_STATIC;
    ext_plug( &modgost89 );
  }
  OS_MODULE_DEINIT( modgost89 ) { }
}
OS_MODULE_ACTIVATOR( modgost89 );
// ---------------------------------------------------------------------------


