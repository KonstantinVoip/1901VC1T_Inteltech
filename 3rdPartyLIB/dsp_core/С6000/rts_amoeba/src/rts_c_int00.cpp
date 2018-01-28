// ---------------------------------------------------------------------------
// extern "C" void c_int00()
// ---------------------------------------------------------------------------
#include <os.h>
// ---------------------------------------------------------------------------

extern void* __syscall_tab[SYSCALL__COUNT__];
extern void* __cinit__;
extern void* __pinit__;
extern int os_main( void* args );

// ---------------------------------------------------------------------------
extern "C" int c_int00( void* args )
{
  uint8* sptr;
  uint8* dptr;
  uint32 length, shift;
  uint32 tptr;
  void (*pinit_func)();

  // Initialize syscall table
  syscall_init( __syscall_tab, sizeof(__syscall_tab) );

  // Initialize constants (.cinit)
  sptr = (uint8*)&__cinit__;

  if( (uint32)sptr != 0xffffffff )
  {
    while( true )
    {
      length = (*((uint32*)sptr));
      if( length == 0 ) break;
      shift = ( 8 - ( length & 7 ) ) & 7;
      sptr += 4;
      dptr = (uint8*)(*((uint32*)sptr));
      sptr += 4;
      while( length-- )
      {
        (*dptr) = (*sptr);
        dptr++;
        sptr++;
      }
      sptr += shift;
    }
  }

  // Initialize global classes (.pinit)
  sptr = (uint8*)&__pinit__;
  if( (uint32)sptr != 0xffffffff )
  {
    while( true )
    {
      dptr = (uint8*)(*((uint32*)sptr));
      if( dptr == NULL ) break;
      tptr = (uint32)dptr;
      pinit_func = (void(*)())tptr;
      pinit_func();
      sptr += 4;
    }
  }

  // Call os_main function
  return os_main( args );
}
// ---------------------------------------------------------------------------
int cpp_int00( void* args )
{
  return c_int00( args );
}
// ---------------------------------------------------------------------------
