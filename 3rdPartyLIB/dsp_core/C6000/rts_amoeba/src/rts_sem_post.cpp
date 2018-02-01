// ---------------------------------------------------------------------------
// int sem_post( sem_t* sem )
// ---------------------------------------------------------------------------
#include <rts.h>
// ---------------------------------------------------------------------------
int sem_post( sem_t* sem )
{
  if( sem == NULL ) { errno = EINVAL; return -1; }
  if( sem->rid == RES_VOID ) { errno = EINVAL; return -1; }
  sem_unlock( sem->rid );
  return 0;
}
// ---------------------------------------------------------------------------
