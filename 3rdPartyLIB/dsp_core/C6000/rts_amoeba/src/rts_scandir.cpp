// ---------------------------------------------------------------------------
// dirent* scandir( DIR* dirp, int32 direction )
// ---------------------------------------------------------------------------
#include <rts.h>
// ---------------------------------------------------------------------------
static int32 nccmp( const char* s1, const char* s2 )
{
  char c1, c2;
  while( true )
  {
    if( ( (*s1) == 0 ) || ( (*s2) == 0 ) )
    {
      if( ( (*s1) == 0 ) && ( (*s2) == 0 ) ) break;
      if( (*s1) == 0 ) return -1;
      return 1;
    }
    c1 = tolower( (*s1) );
    c2 = tolower( (*s2) );
    if( c1 < c2 ) return -1;
    if( c1 > c2 ) return 1;
    s1++; s2++;
  }
  return 0;
}
// ---------------------------------------------------------------------------
int32 scandir( DIR* dirp, dirent** r, int32 direction, bool nocasecmp )
{
  int32 count;
  s_inode* list;
  s_inode* plist = NULL;
  s_inode* crec;
  s_inode* frec;
  dirent* dlist;

  if( ( dirp == NULL ) || ( r == NULL ) ) return -1;
  (*r) = NULL;
  if( drv_list( dirp->rid, &list ) != OSE_OK ) return -1;
  if( list == NULL ) return 0;

  count = 0;
  crec = list;
  while( crec )
  {
    count++;
    crec = crec->next;
  }

  dlist = new dirent[count];
  if( dlist == NULL )
  {
    drv_list_destroy( list );
    return 0;
  }

  for( int32 i = 0; i < count; i++ )
  {
    frec = list;
    if( direction != 0 )
    {
      crec = frec->next;
      while( crec )
      {
        if( direction < 0 )
        {
          if( nocasecmp )
          {
            if( nccmp( frec->name, crec->name ) < 0 ) frec = crec;
          }
          else
          {
            if( strcmp( frec->name, crec->name ) < 0 ) frec = crec;
          }
        }
        else if( direction > 0 )
        {
          if( nocasecmp )
          {
            if( nccmp( frec->name, crec->name ) > 0 ) frec = crec;
          }
          else
          {
            if( strcmp( frec->name, crec->name ) > 0 ) frec = crec;
          }
        }
        crec = crec->next;
      }
    }
    if( frec->next ) frec->next->prev = frec->prev;
    if( frec->prev ) frec->prev->next = frec->next; else list = frec->next;

    frec->prev = NULL;
    if( plist == NULL )
    {
      frec->next = NULL;
      plist = frec;
    }
    else
    {
      frec->next = plist;
      plist->prev = frec;
      plist = frec;
    }

    if( strlen( frec->name ) > NAME_MAX )
    {
      drv_list_destroy( list );
      drv_list_destroy( plist );
      delete[] dlist;
      return 0;
    }
    strcpy( dlist[i].d_name, frec->name );

    if( frec->type & INOT_FILE ) dlist[i].d_type = DT_REG;
    else if( frec->type & INOT_FOLDER ) dlist[i].d_type = DT_DIR;
    else dlist[i].d_type = DT_UNKNOWN;
    _mem8( &dlist[i].d_size ) = _mem8( &frec->size );
  }

  drv_list_destroy( plist );

  (*r) = dlist;

  return count;
}
// ---------------------------------------------------------------------------
