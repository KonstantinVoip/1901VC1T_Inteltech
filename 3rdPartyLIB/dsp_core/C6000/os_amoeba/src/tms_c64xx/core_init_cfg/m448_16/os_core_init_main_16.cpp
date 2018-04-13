#include <os.h>
// Init core start param
/*
struct s_os_core_init
{
  uint32 core_heap_len; // Размер системного хипа
  uint32 sys_quant;     // Значение периода переключения процессов
  uint32 sem_list_len;  // Длинна списка семафоров по старту (список расширяемый)
  uint32 extram_start;  // Адрес начала внешнего ОЗУ (если равно 0, значит внешнего ОЗУ нет)
  uint32 extram_end;    // Адрес конца  внещнего ОЗУ (если равно 0, значит внешнего ОЗУ нет)
};//12 byte
*/
const s_os_core_init core_init_cfg ={8192,500000,256,0x80000000,0x81000000};	
