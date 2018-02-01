// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: m448-15-iface
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp866
// !: d:
// !: -: 
// ---------------------------------------------------------------------------
#include <drv_fwmem.h>
#include <drv_gpio.h>
#include <os.h>
// ---------------------------------------------------------------------------
uint32 fwmem_at49bv322d_gpio_translate_address( s_fwmem_context* ctx, uint32 address )
{
  register uint32 hbit = ( address >> 20 ) & 0x00000003;
  if( ctx->arg1 != hbit )
  {
    register uint32 is = int_disable();
    register uint32 cval = REG_GPVAL;
    if( hbit & 1 ) cval |= 0x00000001; else cval &= 0xfffffffe;
    if( hbit & 2 ) cval |= 0x00000008; else cval &= 0xfffffff7;
    REG_GPVAL = cval;
    int_enable( is );
    ctx->arg1 = hbit;
  }
  return address & 0xffcfffff;
}
// ---------------------------------------------------------------------------
int32 fwmem_at49bv322d_gpio_init( s_fwmem_context* ctx )
{
  int32 r;
  uint32 gpio;
  volatile uint8& REG_555 = (*(uint8*)( ctx->address + 0x00000555 ));
  volatile uint8& REG_AAA = (*(uint8*)( ctx->address + 0x00000aaa ));
  ctx->arg0 = drv_mkd( "/dev/gpio" );
  ctx->arg1 = 0xffffffff;
  if( ctx->arg0 == RES_VOID ) return OSE_NO_DEVICE;
  res_share( ctx->arg0 );
  gpio = 0;
  if( ( r = drv_ioctl( ctx->arg0, GPIO_LOCK, &gpio ) ) != OSE_OK ) return r;
  gpio = 3;
  if( ( r = drv_ioctl( ctx->arg0, GPIO_LOCK, &gpio ) ) != OSE_OK ) return r;
  REG_GPEN |= 0x00000009;
  REG_GPDIR |= 0x00000009;
  fwmem_at49bv322d_gpio_translate_address( ctx, ctx->address );
  REG_AAA = 0xaa;
  REG_555 = 0x55;
  REG_AAA = 0xd0;
  (*(uint8*)ctx->address) = 0x00;
  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 fwmem_at49bv322d_gpio_deinit( s_fwmem_context* ctx )
{
  drv_rmd( ctx->arg0 );
  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 fwmem_at49bv322d_gpio_sector_size( s_fwmem_context* ctx, s_fwmem_sector_size* arg )
{
  if( arg->n >= 71 ) return OSE_OUT_OF_A_RANGE;
  if( arg->n < 8 ) arg->size = 8192; else arg->size = 65536;
  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 fwmem_at49bv322d_gpio_sector_count( s_fwmem_context* ctx, uint32* arg )
{
  (*arg) = 71;
  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 fwmem_at49bv322d_gpio_sector_clear( s_fwmem_context* ctx, uint32 sector )
{
  volatile uint8& REG_555 = (*(uint8*)( ctx->address + 0x00000555 ));
  volatile uint8& REG_AAA = (*(uint8*)( ctx->address + 0x00000aaa ));
  uint32 offset;
  volatile uint8 tgl0, tgl1;

  if( sector >= 71 ) return OSE_OUT_OF_A_RANGE;
  if( sector < 8 ) offset = sector << 13; else offset = ( sector - 7 ) << 16;

  fwmem_at49bv322d_gpio_translate_address( ctx, ctx->address );

  REG_AAA = 0xaa;
  REG_555 = 0x55;
  REG_AAA = 0x80;
  REG_AAA = 0xaa;
  REG_555 = 0x55;
  
  volatile uint8& REG_DATA = (*(uint8*)fwmem_at49bv322d_gpio_translate_address( ctx, ctx->address + offset ));
  REG_DATA = 0x30;

  tgl1 = REG_DATA;
  while( true )
  {
    tgl0 = REG_DATA;
    if( ( ( tgl0 ^ tgl1 ) & 0x44 ) == 0x00 ) break;
    if( ( tgl0 & 0x28 ) == 0x28 )
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
// ---------------------------------------------------------------------------
int32 fwmem_at49bv322d_gpio_write_buffer( s_fwmem_context* ctx, uint32 offset, void* data, uint32 length )
{
  volatile uint8 chkv;
  volatile uint8& REG_555 = (*(volatile uint8*)( ctx->address + 0x00000555 ));
  volatile uint8& REG_AAA = (*(volatile uint8*)( ctx->address + 0x00000aaa ));
  register uint32 addr;
  register uint8* u8;

  if( ( offset + length ) > 4194304 ) return OSE_OUT_OF_A_RANGE;

  addr = ctx->address + offset;
  u8 = (uint8*)data;
  for( uint32 i = 0; i < length; i++ )
  {
    fwmem_at49bv322d_gpio_translate_address( ctx, ctx->address );

    REG_AAA = 0xaa;
    REG_555 = 0x55;
    REG_AAA = 0xa0;

    volatile uint8& REG_DATA = (*(uint8*)fwmem_at49bv322d_gpio_translate_address( ctx, addr ));
    REG_DATA = (*u8);

    while( true )
    {
      chkv = REG_DATA;
      if( ( ( chkv ^ (*u8) ) & 0x80 ) == 0x00 ) break;
      if( ( chkv & 0x28 ) == 0x28 )
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
// ---------------------------------------------------------------------------
int32 fwmem_at49bv322d_gpio_read_buffer( s_fwmem_context* ctx, uint32 offset, void* data, uint32 length )
{
  register uint32 addr;
  register uint8* u8;
  if( ( offset + length ) > 4194304 ) return OSE_OUT_OF_A_RANGE;
  addr = ctx->address + offset;
  u8 = (uint8*)data;
  for( uint32 i = 0; i < length; i++ )
  {
    (*u8) = (*(uint8*)fwmem_at49bv322d_gpio_translate_address( ctx, addr ));
    addr++;
    u8++;
  }
  return OSE_OK;
}
// ---------------------------------------------------------------------------
int32 fwmem_at49bv322d_gpio_size( s_fwmem_context* ctx, uint32* size )
{
  _mem4( size ) = 4194304;
  return OSE_OK;
}
// ---------------------------------------------------------------------------
s_fwmem_selector fwmem_at49bv322d_gpio =
{
  &fwmem_at49bv322d_gpio_init,
  &fwmem_at49bv322d_gpio_deinit,
  &fwmem_at49bv322d_gpio_sector_count,
  &fwmem_at49bv322d_gpio_sector_size,
  &fwmem_at49bv322d_gpio_sector_clear,
  &fwmem_at49bv322d_gpio_write_buffer,
  &fwmem_at49bv322d_gpio_read_buffer,
  &fwmem_at49bv322d_gpio_size
};
// ---------------------------------------------------------------------------
