// ---------------------------------------------------------------------------
// dirent* readdir( DIR* dirp )
// ---------------------------------------------------------------------------
#include <rts.h>
// ---------------------------------------------------------------------------
dirent* readdir( DIR* dirp )
{
  if( dirp == NULL ) { errno = EBADF; return NULL; }
  if( dirp->d_cnode == NULL ) { errno = ENOENT; return NULL; }
  if( strlen( dirp->d_cnode->name ) > NAME_MAX ) { dirp->d_cnode = dirp->d_cnode->next; errno = EOVERFLOW; return NULL; }
  strcpy( dirp->d_rec.d_name, dirp->d_cnode->name );
  if( dirp->d_cnode->type & INOT_FILE ) dirp->d_rec.d_type = DT_REG;
  else if( dirp->d_cnode->type & INOT_FOLDER ) dirp->d_rec.d_type = DT_DIR;
  else dirp->d_rec.d_type = DT_UNKNOWN;
  _mem8( &dirp->d_rec.d_size ) = _mem8( &dirp->d_cnode->size );
  dirp->d_cnode = dirp->d_cnode->next;
  return &dirp->d_rec;
}
// ---------------------------------------------------------------------------
