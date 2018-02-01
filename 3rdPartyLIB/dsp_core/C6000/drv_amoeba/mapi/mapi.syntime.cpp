// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: all
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp866
// !: d: ������ �������� ���������� ������� ������������� �������.
// !: -:
// ---------------------------------------------------------------------------
#include <mapi.h>
// ---------------------------------------------------------------------------
// !: sn: s_mapi_syntime
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: sd: ��������� ��������� ��� ������������� �������
// !: sc: uint32, cmd
// !: cd: ��� �������, ������ ����� MAPI_SYNTIME
// !: sc: uint32, time_s
// !: cd: ����� � �������� �� 01.01.1970
// ---------------------------------------------------------------------------
// !: fn: int32 mapi_syntime( uint32 d, uint32 tm_s )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>��������:</b><br>
// !: d: <br>
// !: d: ������� ���������� ��������� ���� s_mapi_syntime ��������, �� �������
// !: d: ��������� ������������� ������� d (���������� ������� msg_discover).
// !: d: ������� ��������� ��������� ������ ������� ������� time_set � ����������
// !: d: s_mapi_syntime::tm_s.<br>
// !: d: <br>
// !: d: <b>������������ ��������:</b><br>
// !: d: <br>
// !: d: � ������ ������ ������ ���������� OSE_OK, ����� ���� �� ��������� ������.<br>
// ---------------------------------------------------------------------------



/**************************************************************************************************
Syntax:      	    int32 mapi_syntime( uint32 d, uint32 tm_s )
Remarks:			������� �������� ���������� ��������� �������� ����, ������������� ���������� ������� �� ����� ��������� �������
Returns:
***************************************************************************************************/
int32 mapi_syntime( uint32 d, uint32 tm_s )
{
  s_mapi_syntime m;
  m.cmd = MAPI_SYNTIME;
  m.tm_s = tm_s;
  return msg_send( d, &m, sizeof(m) );
}
// ---------------------------------------------------------------------------