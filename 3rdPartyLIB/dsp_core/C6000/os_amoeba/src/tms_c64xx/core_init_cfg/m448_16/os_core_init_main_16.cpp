#include <os.h>
// Init core start param
/*
struct s_os_core_init
{
  uint32 core_heap_len; // ������ ���������� ����
  uint32 sys_quant;     // �������� ������� ������������ ���������
  uint32 sem_list_len;  // ������ ������ ��������� �� ������ (������ �����������)
  uint32 extram_start;  // ����� ������ �������� ��� (���� ����� 0, ������ �������� ��� ���)
  uint32 extram_end;    // ����� �����  �������� ��� (���� ����� 0, ������ �������� ��� ���)
};//12 byte
*/
const s_os_core_init core_init_cfg ={8192,500000,256,0x80000000,0x81000000};	
