#ifndef __Message_API_H__
#define __Message_API_H__

#include <rts.h>

// -- Message API command codes ----------------------------------------------

#define MAPI_SYNTIME            0x00000001
#define MAPI_LOADAFTERME        0x00000002
#define MAPI_TERMINATE          0x00000003
#define MAPI_SPTESTACK          0x00000004
#define MAPI_SPTEST             0x00000005
#define MAPI_SPTESTOK           0x00000006
#define MAPI_SENSOR_TEST        0x00000007

#define MAPI_SPTESTOK_DRIVER    0x00000000
#define MAPI_SPTESTOK_INTERRUPT 0x00000001

//----------------------------------------------------------------------------
//-----state - ������ ��� ����� ������� ��������------------------------------ 
//----------------------------------------------------------------------------
#define MAPI_SENSORTEST_SIN     0x00000010 //������� ���������� � ����������� �������� ������� 
#define MAPI_SENSORTEST_ACK     0x00000020 //������� ����� � ���������� � ���������� �����
#define MAPI_SENSORTEST_TST     0x00000040 //������� �� ���������� ����� �� ��
#define MAPI_SENSORTEST_INT     0x00000080 //������� �� ���������� ����� �������� ������� ����������
#define MAPI_SENSORTEST_FIN     0x00000100 //������� �������� ����� ������� ���������� �� ��
//----------------------------------------------------------------------------

#define MAPI_DOOR_IS_OPEN       0x11111111//������� �������
#define MAPI_IFACE_CMP_ERROR    0x22222222//������ ������ �� ��
#define MAPI_COMM_CMP_ERROR     0x33333333//������ ������ �� ��
#define MAPI_MAIN_SPARCA_ERROR  0x44444444//������ ������ �� ��
#define MAPI_SPARCA_TEST_ERROR  0x55555555//������ ����� ������
#define MAPI_SENSOR_TEST_ERROR1 0x66666666//������ ����� �������� �������
#define MAPI_SENSOR_TEST_ERROR2 0x77777777//������ ����� ������� �������

// -- Message API data structures --------------------------------------------

struct s_mapi_syntime
{
  uint32                        cmd;
  uint32                        tm_s;
};

struct s_mapi_loadafterme
{
  uint32                        cmd;
  char                          path[252];
  void*                         mem_lif;
};

struct s_mapi_sptestack
{
  uint32                        cmd;
};

struct s_mapi_sptestok
{
  uint32                        cmd;
  uint32                        part;
};

struct s_mapi_sptest
{
  uint32                        cmd;
};

struct s_mapi_terminate
{
  uint32                        cmd;
  uint32                        err_code;
};

struct s_mapi_sensortest
{
  uint32                        cmd;//��� ������� mapi - ���� ������� ��������
  uint16                        state;//���� �����(����� � �����, ������ ����, ���� �� ���������� �� ��)
  uint16                        flags;//������ ����� ��� ������� (������� ��� ������), ��� �������� (���� �� ���� ����������)
};

// -- Message API wrappers ---------------------------------------------------

extern int32 mapi_syntime( uint32 d, uint32 tm_s );
extern int32 mapi_loadafterme( uint32 d, const char* path, void* mem_lif);
extern int32 mapi_sptestack( uint32 d );
extern int32 mapi_sptestok( uint32 d, uint32 p );
extern int32 mapi_sptest( uint32 d );
extern int32 mapi_terminate( uint32 d, uint32 err_code );
extern int32 mapi_sensortest( uint32 d, uint16 state, uint16 flags );
#endif
