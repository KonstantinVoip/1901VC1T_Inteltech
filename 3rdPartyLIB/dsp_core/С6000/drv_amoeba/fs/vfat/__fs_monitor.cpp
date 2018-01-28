#include <__fs.h>
#include <rts.h>
// ---------------------------------------------------------------------------

File** fsMonitor::ofList = NULL;
FS_INT16 fsMonitor::maxOpenFiles = 0;
FS_INT16 fsMonitor::numOfOpenFiles = 0;

// ---------------------------------------------------------------------------
void fsMonitor::init( FS_INT16 iMaxOpenFiles )
{
  maxOpenFiles = iMaxOpenFiles;
  ofList = (File**)fs_alloc( sizeof(File*) * maxOpenFiles ); // new File*[maxOpenFiles];
  if( ofList == NULL )
  {
    // Critical error
    while(FS_TRUE);
  }
  for( FS_INT16 i = 0; i < maxOpenFiles; i++ ) ofList[i] = NULL;
}
// ---------------------------------------------------------------------------
void fsMonitor::deinit()
{
  for( FS_INT16 i = 0; i < maxOpenFiles; i++ ) delete ofList[i];
  fs_free( ofList );
  ofList = NULL;
  maxOpenFiles = 0;
  numOfOpenFiles = 0;
}
// ---------------------------------------------------------------------------
FS_BOOL fsMonitor::addOpenFile( File* f )
{
  if( f == NULL ) return FS_FALSE;
  for( FS_INT16 i = 0; i < maxOpenFiles; i++ )
  {
    if( ofList[i] == NULL )
    {
      ofList[i] = f;
      return FS_TRUE;
    }
  }
  return FS_FALSE;
}
// ---------------------------------------------------------------------------
FS_BOOL fsMonitor::delOpenFile( File* f )
{
  for(FS_INT16 i=0;i<maxOpenFiles;i++){
    if(ofList[i]==f){
      ofList[i] = NULL;
      return FS_TRUE;
    }
  }
  return FS_FALSE;
}
// ---------------------------------------------------------------------------
void fsMonitor::umount( FS_CHAR* mountPointName )
{
  FS_INT16 i, stl;
  FS_CHAR* cpath;
  for( i = 0; i < maxOpenFiles; i++ )
  {
    if( ofList[i] == NULL ) continue;
    cpath = ofList[i]->data->getPath();
    stl = strlen( mountPointName );
    if( stl > strlen( cpath ) ) continue;
    if( fsUtils::cmpL( cpath, mountPointName, stl ) && ( ( cpath[stl] == 0 ) || ( cpath[stl] == '/' ) ) )
    {
      if( ofList[i]->data != NULL ) delete ofList[i]->data;
      ofList[i]->data = NULL;
      ofList[i]->flt = &rootFs;
      ofList[i]->flt->init( ofList[i] );
    }
  }
}
// ---------------------------------------------------------------------------
FS_BOOL fsMonitor::checkOpened( File* f )
{
  if( f == NULL ) return FS_TRUE;
  for( FS_INT16 i = 0; i < maxOpenFiles; i++ )
  {
    if( ( ofList[i] != NULL ) && ( ofList[i] != f ) )
    {
      if( strcmp( f->data->getPath(), ofList[i]->data->getPath() ) == 0 ) return FS_TRUE;
    }
  }
  return FS_FALSE;
}
// ---------------------------------------------------------------------------
class fsMonitor_autoinit
{
  public:

    fsMonitor_autoinit()
    {
      fsMonitor::init( MAX_OPEN_FILES );
    }

    ~fsMonitor_autoinit()
    {
      fsMonitor::deinit();
    }

}
fsMonitor_Iniciator;
// ---------------------------------------------------------------------------

