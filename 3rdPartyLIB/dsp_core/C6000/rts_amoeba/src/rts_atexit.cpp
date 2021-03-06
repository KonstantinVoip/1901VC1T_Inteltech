// ---------------------------------------------------------------------------
// extern int atexit( void (*fun)() )
// ---------------------------------------------------------------------------

int at_exit_count = 0;
void (*at_exit_fun[32])();

// ---------------------------------------------------------------------------
int atexit( void (*fun)() )
{
  if( at_exit_count >= 32 ) return 1;
  at_exit_fun[at_exit_count++] = fun;
  return 0;
}
// ---------------------------------------------------------------------------
