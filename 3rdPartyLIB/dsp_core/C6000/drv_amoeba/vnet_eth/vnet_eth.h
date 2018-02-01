// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp1251
// !: d: ������ �������� ��������� �������, �������� ��������, ����� ������
// !: d: � ���������� ����������� ������ ��������� ��� �������� ����������� ������� ����
// !: d: �� ����� ���������� ������� �����������.
// !: -: 
// ---------------------------------------------------------------------------
#ifndef __VNET_ETH_H__
#define __VNET_ETH_H__

#include <os_types.h>

struct VNET_DEV
{ 
  uint32 handle;    //���������� ����������� ��������
  uint32 dev_sem;   //���������� ����������� ��������
  char   name[8];   //��� �������
  net_config vn_cfg;//������������ ����������� ��������
  uint16 vn_type;   //��� ���������� ��� �������� NetFS
};

#endif




