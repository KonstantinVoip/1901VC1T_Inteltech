// -- DO NOT REMOVE ----------------------------------------------------------
//  mapi.loadafterme.cpp 
// !: arch: all
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp866
// !: d: ������ �������� ���������� ������� �������� ����������, �����
// !: d: ���������� �������� ��������.
// !: -:
// ---------------------------------------------------------------------------
#include <mapi.h>
// ---------------------------------------------------------------------------
// !: sn: s_mapi_loadafterme
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sd: ��������� ��������� ��� ������������� �������
// !: sc: uint32, cmd
// !: cd: ��� �������, ������ ����� MAPI_LOADAFTERME
// !: sc: uint16, process_id
// !: cd: ������������� �������������� ��������
// !: sc: char[252], path
// !: cd: ���� � ����������� ��������� (�������� 251 ��������)
// ---------------------------------------------------------------------------
// !: fn: int32 mapi_loadafterme( uint32 d, const char* path )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>��������:</b><br>
// !: d: <br>
// !: d: ������� ���������� ��������� ���� s_mapi_loadafterme ��������, �� �������
// !: d: ��������� ������������� ������� d (���������� ������� msg_discover).
// !: d: ������� ��������� ��������� ������ ����� � ����� �������� ����������
// !: d: �������� s_mapi_loadafterme::process_id, ��������� ��������� �����
// !: d: prc_join. ����� ���������� ��������, ��������� �������� ���������� �� 
// !: d: ���������� ���� s_mapi_loadafterme::path.<br>
// !: d: <br>
// !: d: <b>������������ ��������:</b><br>
// !: d: <br>
// !: d: � ������ ������ ������ ���������� OSE_OK, ����� ���� �� ��������� ������.<br>
// !: d: <br>
// !: d: <b>����������:</b><br>
// !: d: <br>
// !: d: � ���� ����, ��� ������� �������������� ������ ��������� �������
// !: d: ������� prc_join, �������� ������ ������� ����� ����� ���������������
// !: d: ��� ���������� ��������, ����� ��������� ���������� ����������
// !: d: �������� �����������.
// ---------------------------------------------------------------------------



/**************************************************************************************************
Syntax:      	    int32 mapi_loadafterme( uint32 d, const char* path, void* mem_lif)
Remarks:			������� �������� ���������� ��������� �������� ���� ��� �������� ���� ��� ��� �� ����

***************************************************************************************************/
int32 mapi_loadafterme( uint32 d, const char* path, void* mem_lif)
{
  s_mapi_loadafterme m;
  if( (path == NULL) & (mem_lif == NULL) ) return OSE_NULL_PARAM;
  if( strlen( path ) > 251 ) return OSE_TOO_LONG_STRING;
  memset( &m, 0, sizeof(m) );
  m.cmd = MAPI_LOADAFTERME;
  strcpy( m.path, path );
  m.mem_lif = mem_lif;
  return msg_send( d, &m, sizeof(m) );
}
// ---------------------------------------------------------------------------