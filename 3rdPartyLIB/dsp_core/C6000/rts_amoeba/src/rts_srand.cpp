// ---------------------------------------------------------------------------
// void srand( unsigned int seed )
// ---------------------------------------------------------------------------
extern unsigned long __rts_rand_x;
// ---------------------------------------------------------------------------
void srand( unsigned int seed )
{
  __rts_rand_x = seed;
}
// ---------------------------------------------------------------------------
