// ---------------------------------------------------------------------------
// int sem_getvalue( sem_t* sem, int* sval )
// ---------------------------------------------------------------------------
#include <rts.h>
// ---------------------------------------------------------------------------
int sem_getvalue( sem_t* sem, int* sval )
{
  int32 v;
  if( ( sem == NULL ) || ( sval == NULL ) ) { errno = EINVAL; return -1; }
  if( sem->rid == RES_VOID ) { errno = EINVAL; return -1; }
  if( sem_value( sem->rid, &v ) == SEM_OK ) { (*sval) = (int)v; return 0; }
  errno = ESEMDESTR;
  return -1;
}
// ---------------------------------------------------------------------------
