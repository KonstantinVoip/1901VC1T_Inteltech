// ---------------------------------------------------------------------------
// FILE* fopen( const char* path, const char* mode )
// ---------------------------------------------------------------------------
#include <rts.h>
#include <os_syscall.h>
// ---------------------------------------------------------------------------
FILE* fopen( const char* path, const char* mode )
{
  int32 i, l;
  bool m_0, m_1, m_2, m_3, m_4, m_5;
  bool hr = false;
  bool ha = false;
  bool hw = false;
  bool hplus = false;
  
  FILE* d = NULL;
  char* dpath = NULL;

  if( ( path == NULL ) || ( mode == NULL ) ) return NULL;

  l = strlen( mode );
  
  if( l == 0 )
  {
    d = new FILE;
    if( d == NULL ) return NULL;
    memset( d, 0, sizeof(FILE) );
    d->rid = drv_mkd( path );
    if( d->rid == RES_VOID )
    {
      delete d;
      return NULL;
    }
    return d;
  }

  for( i = 0; i < l; i++ )
  {
    if( mode[i] == 'r' ) hr = true;
    else if( mode[i] == 'w' ) hw = true;
    else if( mode[i] == 'a' ) ha = true;
    else if( mode[i] == '+' ) hplus = true;
  }

  if( ( hr && hw ) || ( hr && ha ) || ( hw && ha ) || ( !hr && !hw && !ha ) ) return NULL;

  m_0 = !hr && !hw &&  ha && !hplus;
  m_1 = !hr && !hw &&  ha &&  hplus;
  m_2 = !hr &&  hw && !ha && !hplus;
  m_3 = !hr &&  hw && !ha &&  hplus;
  m_4 =  hr && !hw && !ha && !hplus;
  m_5 =  hr && !hw && !ha &&  hplus;

  d = new FILE;
  if( d == NULL ) return NULL;
  memset( d, 0, sizeof(FILE) );

  for( i = l = strlen( path ) - 1; l >= 0; l-- ) if( ( path[l] == '/' ) || ( path[l] == '\\' ) ) break;
  if( l == i )
  {
    delete d;
    return NULL;
  }
  if( l < 0 )
  {
    // todo: current work dir
    delete d;
    return NULL;
  }

  dpath = new char[l+1];
  if( dpath == NULL )
  {
    delete d;
    return NULL;
  }
  memcpy( dpath, path, l );
  dpath[l] = 0;

  if( m_0 )      // "a" or "ab" or any fucking permutations
  {
    if( ( d->rid = drv_mkd( path ) ) == RES_VOID )
    {
      if( ( d->rid = drv_mkd( dpath ) ) == RES_VOID ) goto l_fail;
      if( drv_create( d->rid, path + l + 1, INOT_FILE ) != OSE_OK ) goto l_fail;
      if( drv_select( d->rid, path + l + 1 ) != OSE_OK ) goto l_fail;
    }
    if( drv_open( d->rid, DRV_WR ) != OSE_OK ) goto l_fail;
    fseek( d, 0, SEEK_END );
  }
  else if( m_1 ) // "a+" or "a+b" or "ab+" or any fucking permutations
  {
    if( ( d->rid = drv_mkd( path ) ) == RES_VOID )
    {
      if( ( d->rid = drv_mkd( dpath ) ) == RES_VOID ) goto l_fail;
      if( drv_create( d->rid, path + l + 1, INOT_FILE ) != OSE_OK ) goto l_fail;
      if( drv_select( d->rid, path + l + 1 ) != OSE_OK ) goto l_fail;
    }
    if( drv_open( d->rid, DRV_RD | DRV_WR ) != OSE_OK ) goto l_fail;
    fseek( d, 0, SEEK_END );
  }
  else if( m_2 ) // "w" or "wb" or any fucking permutations
  {
    if( ( d->rid = drv_mkd( path ) ) == RES_VOID )
    {
      if( ( d->rid = drv_mkd( dpath ) ) == RES_VOID ) goto l_fail;
      if( drv_create( d->rid, path + l + 1, INOT_FILE ) != OSE_OK ) goto l_fail;
      if( drv_select( d->rid, path + l + 1 ) != OSE_OK ) goto l_fail;
    }
    if( drv_open( d->rid, DRV_WR ) != OSE_OK ) goto l_fail;
    int64 nlen = 0;
    if( drv_ioctl( d->rid, IOC_RESIZE, &nlen ) != OSE_OK ) goto l_fail;
  }
  else if( m_3 ) // "w+" or "w+b" or "wb+" or any fucking permutations
  {
    if( ( d->rid = drv_mkd( path ) ) == RES_VOID )
    {
      if( ( d->rid = drv_mkd( dpath ) ) == RES_VOID ) goto l_fail;
      if( drv_create( d->rid, path + l + 1, INOT_FILE ) != OSE_OK ) goto l_fail;
      if( drv_select( d->rid, path + l + 1 ) != OSE_OK ) goto l_fail;
    }
    if( drv_open( d->rid, DRV_RD | DRV_WR ) != OSE_OK ) goto l_fail;
    int64 nlen = 0;
    if( drv_ioctl( d->rid, IOC_RESIZE, &nlen ) != OSE_OK ) goto l_fail;
  }
  else if( m_4 ) // "r" or "rb" or any fucking permutations
  {
    if( ( d->rid = drv_mkd( path ) ) == RES_VOID ) goto l_fail;
    if( drv_open( d->rid, DRV_RD ) != OSE_OK ) goto l_fail;
  }
  else if( m_5 ) // "r+" or "r+b" or "rb+" or any fucking permutations
  {
    if( ( d->rid = drv_mkd( path ) ) == RES_VOID ) goto l_fail;
    if( drv_open( d->rid, DRV_RD | DRV_WR ) != OSE_OK ) goto l_fail;
  }

  delete[] dpath;

  return d;

l_fail:

  delete[] dpath;
  if( d ) drv_rmd( d->rid );
  delete d;

  return NULL;
}
// ---------------------------------------------------------------------------
