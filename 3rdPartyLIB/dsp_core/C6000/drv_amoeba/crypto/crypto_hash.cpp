//**************************************************************************************************
//                         Copyright (C) 2010 RCZI
//--------------------------------------------------------------------------------------------------
// FILENAME....... crypto_hash.cpp
// DATE CREATED... 03/03/2010
// LAST MODIFIED.. 04/03/2010
// VERSION........ 1.0
//--------------------------------------------------------------------------------------------------
//                  Вычисление Хэш-функции по ГОСТ.Р34 10.94
//--------------------------------------------------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
//
// !: codepage: cp1251 
//
// !: d: ГОСТ.Р34 10.94.<br>
// !: md: Вычисление Хэш-функции по ГОСТ.Р34 10.94.
// !: -:
//***sss********************************************************************************************
#include <rts.h>
#include <crypto_hash.h>

uint32  k1[256];
uint32  k2[256];
uint32  k3[256];
uint32  k4[256];

static const uint32 C2[8] =
{
  0xFF00FF00, 0xFF00FF00,   0x00FF00FF, 0x00FF00FF,
  0x00FFFF00, 0xFF0000FF,   0x000000FF, 0xFF00FFFF
};

static void hash_step(s_hash* ctx, uint32* mass);
static void hash_gost_encrypt_block(uint32* k, uint32* text);
static void hash_iter_increment(uint32* n,uint32* k);
static void hash_iter_decrement(uint32* n,uint32* k);
static void hash_xor(uint32* dst, const uint32* src1, const uint32* src2);
static void hash_swab16(void* array, uint32 length);
static void hash_sum(uint32 *vect1, const uint32 *vect2);
static void hash_transform_p(uint32* w, uint32* key );
static void hash_transform_a(uint32* vect);
static void hash_transform_x(uint32* vect );
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//          Внешнии функции
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
void modhash_init(const void* bp)
{
  uint32* uzb = (uint32*)bp;
  for (int i = 0; i < 256; i++)
  {
    k1[i] = (((uzb[(i >> 4)]&0xF0000000) | (uzb[(i&0xF)]&0x0F000000))&0xFF000000);
    k2[i] = (((uzb[(i >> 4)]&0xF00000) | (uzb[(i&0xF)]&0x0F0000))&0xFF0000);
    k3[i] = (((uzb[(i >> 4)]&0xF000) | (uzb[(i&0xF)]&0x0F00))&0xFF00);
    k4[i] = (((uzb[(i >> 4)]&0xF0) | (uzb[(i&0xF)]&0x0F))&0xFF);

    k1[i] = k1[i]<<11| k1[i]>>(32-11);
    k2[i] = k2[i]<<11| k2[i]>>(32-11);
    k3[i] = k3[i]<<11| k3[i]>>(32-11);
    k4[i] = k4[i]<<11| k4[i]>>(32-11);
  }
}
// ------------------------------------------------------------------------------------------------
void modhash_start(s_hash* ctx, void* start_vector)
{
  memcpy(ctx->h, start_vector, sizeof(ctx->h));
  memset(ctx->e, 0x00, sizeof(ctx->e));
  ctx->len=0;
}
// ------------------------------------------------------------------------------------------------
void modhash_cont(s_hash* ctx, void* text, uint32 len)
{
  uint8*   txt = (uint8*)text;
  uint32   mass[8];
  uint32   ost;

  for(register uint32 i=0; i<len/sizeof(mass); i++)
  {
    memcpy(mass, txt, sizeof(mass));
    hash_swab16(mass, sizeof(mass));
    hash_step(ctx, mass);
    ctx->len += sizeof(mass);
    txt += sizeof(mass);
    hash_sum(ctx->e, mass);
  }

  ost = len & (sizeof(mass)-1);
  if(ost)
  {
    memset(mass, 0x0, sizeof(mass));
    memcpy(mass, txt, ost);
    hash_swab16(mass, sizeof(mass));
    hash_step(ctx, mass);
    ctx->len += ost;
    hash_sum(ctx->e, mass);
  }
}
// ------------------------------------------------------------------------------------------------
void* modhash_end(s_hash* ctx)
{
  uint32 L[8];
  memset(L, 0x00, sizeof(L));
  L[0] = ctx->len*CHAR_BIT; 
  
  hash_step(ctx, L);
  hash_step(ctx, ctx->e);
  
  uint16* b = (uint16*)ctx->h;
  for(int i=0;i<8;i++)
  {
    uint16 t=b[i];
    b[i]=b[15-i];
    b[15-i]=t;
  } 
  return ctx->h;
}
// ------------------------------------------------------------------------------------------------
void* modhash_hash(s_hash* ctx, void* start_vector, void* text, uint32 len)
{
  modhash_start(ctx, start_vector);
  modhash_cont(ctx, text, len);
  modhash_end(ctx);
  return ctx->h;
}
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//          Внутреннии функции
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
static void hash_step(s_hash* ctx, uint32* mass)
{
  //Генерация ключей:
  int i;

  uint32 U[8];
  uint32 V[8];
  uint32 W[8];
  uint32 K[4][8];

  memcpy(U, ctx->h, sizeof(ctx->h));
  memcpy(V, mass, sizeof(ctx->h));

  hash_xor(W,U,V);
  hash_transform_p( W, K[0] );

  for(i=1; i<4; i++)
  {
    hash_transform_a(U);
    if (i==2) hash_xor( U, C2, U );
    hash_transform_a( V );
    hash_transform_a( V );
    hash_xor( W, U, V);
    hash_transform_p( W, K[i] );
  }

  //S=W
  memcpy(W, ctx->h, sizeof(W));
  hash_gost_encrypt_block(K[3], W+6);
  hash_gost_encrypt_block(K[2], W+4);
  hash_gost_encrypt_block(K[1], W+2);
  hash_gost_encrypt_block(K[0], W+0);
  for(i=12; i--;) 
    hash_transform_x( W );

  hash_xor( W, mass, W);
  hash_transform_x( W );
  hash_xor( ctx->h, ctx->h, W );

  for (i=61; i--;) 
    hash_transform_x( ctx->h );
}
// ------------------------------------------------------------------------------------------------
static uint32 f(uint32 x)
{
  uint32 y;
  y =k4[x&0xFF];
  x>>=8;
  y|=k3[x&0xFF];
  x>>=8;
  y|=k2[x&0xFF];
  x>>=8;
  y|=k1[x];
  return y;
}
// ------------------------------------------------------------------------------------------------
static void hash_gost_encrypt_block(uint32* k, uint32* text)
{
  register uint32 tmp;
  hash_iter_increment(text,k);
  hash_iter_increment(text,k);
  hash_iter_increment(text,k);
  hash_iter_decrement(text,k);
  tmp = _mem4(&text[0]);
  _mem4(&text[0]) = _mem4(&text[1]);
  _mem4(&text[1]) = tmp;
}
// ------------------------------------------------------------------------------------------------
static void hash_iter_increment(uint32* n,uint32* k)
{
  uint32 n0=_mem4(&n[0]);
  uint32 n1=_mem4(&n[1]);
  
  n1 ^= f(n0+(*k++));
  n0 ^= f(n1+(*k++));
  
  n1 ^= f(n0+(*k++));
  n0 ^= f(n1+(*k++));
  
  n1 ^= f(n0+(*k++));
  n0 ^= f(n1+(*k++));
  
  n1 ^= f(n0+(*k++));
  n0 ^= f(n1+(*k++));
  
  _mem4(&n[0])=n0;
  _mem4(&n[1])=n1;
}
// ------------------------------------------------------------------------------------------------
static void hash_iter_decrement(uint32* n,uint32* k)
{
  k+=7;
  uint32 n0=_mem4(&n[0]);
  uint32 n1=_mem4(&n[1]);
  
  n1 ^= f(n0+(*k--));
  n0 ^= f(n1+(*k--));
                   
  n1 ^= f(n0+(*k--));
  n0 ^= f(n1+(*k--));
                   
  n1 ^= f(n0+(*k--));
  n0 ^= f(n1+(*k--));
                   
  n1 ^= f(n0+(*k--));
  n0 ^= f(n1+(*k--));
  
  _mem4(&n[0])=n0;
  _mem4(&n[1])=n1;
}
// ------------------------------------------------------------------------------------------------
static void hash_xor(uint32* dst, const uint32* src1, const uint32* src2)
{
  *dst++ = *src1++ ^ *src2++;
  *dst++ = *src1++ ^ *src2++;
  *dst++ = *src1++ ^ *src2++;
  *dst++ = *src1++ ^ *src2++;
  *dst++ = *src1++ ^ *src2++;
  *dst++ = *src1++ ^ *src2++;
  *dst++ = *src1++ ^ *src2++;
  *dst++ = *src1++ ^ *src2++;
}
// ------------------------------------------------------------------------------------------------
static void hash_swab16(void* array, uint32 length)
{
  uint16*	arr = (uint16*)array;
  int32		len = length>>1;
  while(len--)
  {
    *arr = (*arr>>8)|(*arr<<8);
    arr++;
  }
}
// ------------------------------------------------------------------------------------------------
static void hash_sum(uint32 *vect1, const uint32 *vect2)
{
  uint32 c=0;
  for(int i=8; i--;)
  {
    *vect1+=*vect2+c;
    if(*vect1++<*vect2++) c=1;
    else c=0;
  }
}
// ------------------------------------------------------------------------------------------------
static void hash_transform_p(uint32* w, uint32* key )
{
  int32  i,k;
  w+=7;
  for(i=4;i--;)
  {
    uint32 w2=*w--;
    uint32 w1=*w--;
    for(k=0;k<4;k++)
    {
      key[k]=(key[k]<<8)|(w1&0xff);
      w1>>=8;
      key[4+k]=(key[4+k]<<8)|(w2&0xff);
      w2>>=8;
    }
  }
}
//----------------------------------------------------------------------------
static void hash_transform_a(uint32* vect)
{
  uint32 t1=vect[0];
  uint32 t2=vect[1];
  memcpy(&vect[0],&vect[2],6*sizeof(uint32));
  vect[6] = vect[0]^t1;
  vect[7] = vect[1]^t2;
}
//----------------------------------------------------------------------------
static void hash_transform_x(uint32* vect )
{
  uint16* t=(uint16*)vect;
  uint16 temp=(t[0])^(t[1])^(t[2])^(t[3])^(t[12])^(t[15]);
  memcpy(vect,(char*)vect+sizeof(uint16),sizeof(uint16)*15);
  t[15]=temp;
}
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
//          Модульные функции
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
s_os_extension modhash;

s_os_extension_f modhash_f[] =
{
  { NULL, SYSCALL_CRYPTO_GOST_HASH_INIT,  (uint32)&modhash_init  },
  { NULL, SYSCALL_CRYPTO_GOST_HASH_START, (uint32)&modhash_start },
  { NULL, SYSCALL_CRYPTO_GOST_HASH_CONT,  (uint32)&modhash_cont  },
  { NULL, SYSCALL_CRYPTO_GOST_HASH_END,   (uint32)&modhash_end   },
  { NULL, SYSCALL_CRYPTO_GOST_HASH,       (uint32)&modhash_hash  }
};
// ---------------------------------------------------------------------------
OS_MODULE_INICIATOR( modhash )
{
  OS_MODULE_INIT( modhash )
  {
    modhash.name = "modhash.lif";
    modhash.f_count = sizeof(modhash_f) / sizeof(s_os_extension_f);
    modhash.f_tab = modhash_f;
    modhash.flags = EXT_F_STATIC;
    ext_plug( &modhash );
  }
  OS_MODULE_DEINIT( modhash ) { }
}
OS_MODULE_ACTIVATOR( modhash );
// ---------------------------------------------------------------------------
