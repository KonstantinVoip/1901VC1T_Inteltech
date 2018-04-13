// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: m632-comm
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp866
// !: d:Драйвер Нижнего Уровня для работы с Паралельной Флэшкой S29AL032D емкостью [4М/байт].
// !: [drv_fwmem.s29al032dxxxx04_gpio.m632]
// ---------------------------------------------------------------------------
#include <drv_fwmem.h>
#include <drv_gpio.h>
#include <os.h>

/*****************************************************************************
Syntax:  uint32 fwmem_s29al032dxxxxx04_gpio_translate_address( s_fwmem_context* ctx, uint32 address )	    
Remarks: ?			    
*******************************************************************************/
uint32 fwmem_s29al032dxxxxx04_gpio_translate_address( s_fwmem_context* ctx, uint32 address )
{
/*
  register uint32 hbit = ( address >> 6 ) & 0x0000c000;

  if( ctx->arg1 != hbit )
  {
    REG_GPIO_CLR_DATA = ( ~hbit ) & 0x0000c000;
    REG_GPIO_SET_DATA = hbit;
    ctx->arg1 = hbit;
  }
  return address & 0xffcfffff;
*/  
  return address & 0xffffffff;
}

/*****************************************************************************
Syntax:  int32 fwmem_s29al032dxxxxx04_gpio_init( s_fwmem_context* ctx )	    
Remarks: 		    
*******************************************************************************/
int32 fwmem_s29al032dxxxxx04_gpio_init( s_fwmem_context* ctx )
{
  ctx->arg0 = RES_VOID;
  ctx->arg1 = 0xffffffff;

  REG_GPIO_DIR &= ~( 0x0000c000 );
  REG_GPIO_CLR_DATA = 0x0000c000;
  
  fwmem_s29al032dxxxxx04_gpio_translate_address( ctx, ctx->address );
  
  (*(uint8*)ctx->address) = 0xf0;
  
  return OSE_OK;
}

/*****************************************************************************
Syntax:  int32 fwmem_s29al032dxxxxx04_gpio_deinit( s_fwmem_context* ctx )   
Remarks: 		    
*******************************************************************************/
int32 fwmem_s29al032dxxxxx04_gpio_deinit( s_fwmem_context* ctx )
{
  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 fwmem_s29al032dxxxxx04_gpio_sector_size( s_fwmem_context* ctx, s_fwmem_sector_size* arg )
{
  if( arg->n >= 71 ) return OSE_OUT_OF_A_RANGE;
  if( arg->n < 8 ) arg->size = 8192; else arg->size = 65536;
  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 fwmem_s29al032dxxxxx04_gpio_sector_count( s_fwmem_context* ctx, uint32* arg )
{
  (*arg) = 71;
  return OSE_OK;
}
/*****************************************************************************
Syntax:  int32 fwmem_s29al032dxxxxx04_gpio_sector_clear( s_fwmem_context* ctx, uint32 sector ) 
Remarks: Стираем Сектор в FLASH памяти.		    
*******************************************************************************/
int32 fwmem_s29al032dxxxxx04_gpio_sector_clear( s_fwmem_context* ctx, uint32 sector )
{
  volatile uint8& REG_555 = (*(uint8*)( ctx->address + 0x00000555 ));
  volatile uint8& REG_AAA = (*(uint8*)( ctx->address + 0x00000aaa ));
  uint32 offset;
  volatile uint8 tgl0, tgl1;

  if( sector >= 71 ) return OSE_OUT_OF_A_RANGE;
  if( sector < 8 ) offset = sector << 13; else offset = ( sector - 7 ) << 16;

  fwmem_s29al032dxxxxx04_gpio_translate_address( ctx, ctx->address );

  REG_AAA = 0xaa;
  REG_555 = 0x55;
  REG_AAA = 0x80;
  REG_AAA = 0xaa;
  REG_555 = 0x55;
  
  volatile uint8& REG_DATA = (*(uint8*)fwmem_s29al032dxxxxx04_gpio_translate_address( ctx, ctx->address + offset ));
  REG_DATA = 0x30;

  tgl1 = REG_DATA;
  while( true )
  {
    tgl0 = REG_DATA;
    if( ( ( tgl0 ^ tgl1 ) & 0x44 ) == 0x00 ) break;
    if( tgl0 & 0x20 )
    {
      tgl1 = REG_DATA;
      tgl0 = REG_DATA;
      if( ( ( tgl0 ^ tgl1 ) & 0x44 ) == 0x00 ) break;
      REG_DATA = 0xf0;
      return FWMEM_CANT_ERASE_SECTOR;
    }
    tgl1 = tgl0;
  }

  return OSE_OK;
}


/*****************************************************************************
Syntax:  int32 fwmem_s29al032dxxxxx04_gpio_write_buffer( s_fwmem_context* ctx, uint32 offset, void* data, uint32 length )    
Remarks: Пишем данные в Паралельную FLASH память		    
*******************************************************************************/
int32 fwmem_s29al032dxxxxx04_gpio_write_buffer( s_fwmem_context* ctx, uint32 offset, void* data, uint32 length )
{
  volatile uint8 chkv;
  volatile uint8& REG_555 = (*(uint8*)( ctx->address + 0x00000555 ));
  volatile uint8& REG_AAA = (*(uint8*)( ctx->address + 0x00000aaa ));
  register uint32 addr;
  register uint8* u8;

  if( ( offset + length ) > 4194304 ) return OSE_OUT_OF_A_RANGE;

  u8 = (uint8*)data;
  addr = ctx->address + offset;
  for( uint32 i = 0; i < length; i++ )
  {
    fwmem_s29al032dxxxxx04_gpio_translate_address( ctx, ctx->address );
    
    REG_AAA = 0xaa;
    REG_555 = 0x55;
    REG_AAA = 0xa0;
    
    volatile uint8& REG_DATA = (*(uint8*)fwmem_s29al032dxxxxx04_gpio_translate_address( ctx, addr ));
    REG_DATA = (*u8);
    
    while( true )
    {
      chkv = REG_DATA;
      if( ( ( chkv ^ (*u8) ) & 0x80 ) == 0x00 ) break;
      if( chkv & 0x20 )
      {
        chkv = REG_DATA;
        if( ( ( chkv ^ (*u8) ) & 0x80 ) == 0x00 ) break;
        REG_DATA = 0xf0;
        return FWMEM_CANT_WRITE;
      }
    }

    addr++;
    u8++;
  }

  return OSE_OK;
}

/*****************************************************************************
Syntax:  int32 fwmem_s29al032dxxxxx04_gpio_read_buffer( s_fwmem_context* ctx, uint32 offset, void* data, uint32 length   
Remarks: Читаем данные из Паралельной FLASH памяти		    
*******************************************************************************/
int32 fwmem_s29al032dxxxxx04_gpio_read_buffer( s_fwmem_context* ctx, uint32 offset, void* data, uint32 length )
{
  register uint32 addr;
  register uint8* u8;
  if( ( offset + length ) > 4194304 ) return OSE_OUT_OF_A_RANGE;
  addr = ctx->address + offset;
  u8 = (uint8*)data;
  for( uint32 i = 0; i < length; i++ )
  {
    (*u8) = (*(uint8*)fwmem_s29al032dxxxxx04_gpio_translate_address( ctx, addr ));
    addr++;
    u8++;
  }
  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 fwmem_s29al032dxxxxx04_gpio_size( s_fwmem_context* ctx, uint32* size )
{
  _mem4( size ) = 4194304;
  return OSE_OK;
}
// ---------------------------------------------------------------------------
s_fwmem_selector fwmem_s29al032dxxxxx04_gpio_m632_comm =
{
  &fwmem_s29al032dxxxxx04_gpio_init,
  &fwmem_s29al032dxxxxx04_gpio_deinit,
  &fwmem_s29al032dxxxxx04_gpio_sector_count,
  &fwmem_s29al032dxxxxx04_gpio_sector_size,
  &fwmem_s29al032dxxxxx04_gpio_sector_clear,
  &fwmem_s29al032dxxxxx04_gpio_write_buffer,
  &fwmem_s29al032dxxxxx04_gpio_read_buffer,
  &fwmem_s29al032dxxxxx04_gpio_size
};
// ---------------------------------------------------------------------------
