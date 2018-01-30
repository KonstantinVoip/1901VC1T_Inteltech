// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: all
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp866
// !: d:
// !: -:
// ---------------------------------------------------------------------------
#include <os.h>
// ---------------------------------------------------------------------------

s_os_extension crypto_e_crc16;

// ---------------------------------------------------------------------------
uint16 crypto_crc16( const void* buf, uint32 length, uint16 crc )
{
  uint8* cdata = (uint8*)const_cast<void*>( buf );
  uint16 v;
  int32 i;

  if( length == 0 ) return crc;

  crc ^= 0xffff;
  
  while( length-- )
  {
    v = ( crc ^ (*cdata) ) & 0x00ff;
    for( i = 0; i < 8; i++ )
    {
      if( v & 1 ) v = ( v >> 1 ) ^ 0x1021; else v >>= 1;
    }
    crc = v ^ ( crc >> 8 );
    cdata++;
  }
  
  crc ^= 0xffff;

  return crc;
}
// ---------------------------------------------------------------------------

s_os_extension modcry_crc16;

s_os_extension_f modcry_crc16_f[] =
{
  { NULL, SYSCALL_CRYPTO_CRC16, (uint32)&crypto_crc16 }
};

// ---------------------------------------------------------------------------
OS_MODULE_INICIATOR( modcry_crc16 )
{
  OS_MODULE_INIT( modcry_crc16 )
  {
    modcry_crc16.name = "modcry-crc16.lif";
    modcry_crc16.f_count = sizeof(modcry_crc16_f) / sizeof(s_os_extension_f);
    modcry_crc16.f_tab = modcry_crc16_f;
    modcry_crc16.flags = EXT_F_STATIC;
    ext_plug( &modcry_crc16 );
  }
  OS_MODULE_DEINIT( modcry_crc16 ) { }
}
OS_MODULE_ACTIVATOR( modcry_crc16 );
// ---------------------------------------------------------------------------
