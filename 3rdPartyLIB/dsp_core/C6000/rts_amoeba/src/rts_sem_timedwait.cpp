// ---------------------------------------------------------------------------
// int sem_timedwait( sem_t* sem, const timespec* abs_timeout )
// ---------------------------------------------------------------------------
#include <rts.h>
// ---------------------------------------------------------------------------
int sem_timedwait( sem_t* sem, const timespec* abs_timeout )
{
  uint32 r, tmo;
  if( ( sem == NULL ) || ( abs_timeout == NULL ) ) { errno = EINVAL; return -1; }
  if( sem->rid == RES_VOID ) { errno = EINVAL; return -1; }
  if( ( abs_timeout->tv_nsec < 0 ) || ( abs_timeout->tv_nsec >= 1000000000 ) ) { errno = EINVAL; return -1; }
  tmo = abs_timeout->tv_nsec / 1000000 + abs_timeout->tv_sec * 1000;
  r = sem_lock( sem->rid, tmo );
  if( r == SEM_OK ) return 0;
  if( r == SEM_TIMEOUT ) { errno = ETIMEDOUT; return -1; }
  errno = ESEMDESTR;
  return -1;
}
// ---------------------------------------------------------------------------
