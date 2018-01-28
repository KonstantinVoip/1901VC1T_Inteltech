// ---------------------------------------------------------------------------
// int sem_wait( sem_t* sem )
// ---------------------------------------------------------------------------
#include <rts.h>
// ---------------------------------------------------------------------------
int sem_wait( sem_t* sem )
{
  uint32 r;
  if( sem == NULL ) { errno = EINVAL; return -1; }
  if( sem->rid == RES_VOID ) { errno = EINVAL; return -1; }
  r = sem_lock( sem->rid, SEM_INFINITY );
  if( r == SEM_OK ) return 0;
  errno = EDEADLK;
  return -1;
}
// ---------------------------------------------------------------------------
