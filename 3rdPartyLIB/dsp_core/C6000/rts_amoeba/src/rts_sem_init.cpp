// ---------------------------------------------------------------------------
// int sem_init( sem_t* sem, int pshared, unsigned int value )
// ---------------------------------------------------------------------------
#include <rts.h>
// ---------------------------------------------------------------------------
int sem_init( sem_t* sem, int pshared, unsigned int value )
{
  if( sem == NULL ) { errno = EINVAL; return -1; }
  if( value >= SEM_VALUE_MAX ) { errno = EINVAL; return -1; }
  sem->rid = sem_alloc( (int32)value, NULL );
  if( sem->rid == RES_VOID ) { errno = ENOSPC; return -1; }
  sem->nauna = 0;
  return 0;
}
// ---------------------------------------------------------------------------
