// ---------------------------------------------------------------------------
// DIR* opendir( const char* dirname )
// ---------------------------------------------------------------------------
#include <rts.h>
// ---------------------------------------------------------------------------
DIR* opendir( const char* dirname )
{
  if( dirname == NULL ) return NULL;
  DIR* rdir = new DIR;
  if( rdir == NULL ) return NULL;
  memset( rdir, 0, sizeof(DIR) );
  rdir->rid = drv_mkd( dirname );
  if( rdir->rid == RES_VOID )
  {
    delete rdir;
    return NULL;
  }
  if( drv_list( rdir->rid, &rdir->d_list ) != OSE_OK )
  {
    drv_rmd( rdir->rid );
    delete rdir;
    return NULL;
  }
  rdir->d_cnode = rdir->d_list;
  return rdir;
}
// ---------------------------------------------------------------------------
