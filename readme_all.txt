Запуск Отладочных Проектов.
-Первым Отладка IFACE  iface(ПП)_pv40:13-Init_IPMP0_MCBSP<->MAIN  (Здесь Ждём)
-Вторым Отладка COMM_0
-Вторым Отладка COMM_1
-Потом  Отладка MAIN_0 
-Потом  Отладка MAIN_1

Автоматически Сделаю потом когда отладки завершатьс\
и тогда всё OK


Пути Переменных окружения используемые в нашем проекте : 
AMOEBA_DRV_PATH            C:\1901VC1T_Inteltech\3rdPartyLIB\dsp_core\С6000\drv_amoeba
AMOEBA_OS_PATH             C:\1901VC1T_Inteltech\3rdPartyLIB\dsp_core\С6000\os_amoeba\src
AMOEBA_RTS_PATH            C:\1901VC1T_Inteltech\3rdPartyLIB\dsp_core\С6000\rts_amoeba
AMOEBA_TPO_PATH            C:\1901VC1T_Inteltech\3rdPartyLIB\dsp_core\С6000\tpo_amoeba

Папка workspace - здесь будут workspace для разных плат
папка out       - здесь формируються образы для записи на флэш lif,arch из исходных out
                - необходимо для сдачи в архив.
папка gel       - здесь gel файлы для разных плат
папка doc       - докментация на ТПО
папка out       - здесь формиравание бинарных файлов для Архива и АРМРИСКЗ
 
папак bin       - Здесь будут лежать бинарники из архива на приборы.



Описание некотрых DEFINE используемых при сборке проектов
ISP176_BUS_32==1 - шина 32 бита 
ISP176_BUS_32==0 - шина 16 бит
NO_OS_MEMTST     - тестирование памяти  drv_nvram.cpp,os_core.cpp
OS_SUPPORT_SYNCHRONIZATION  - поддкржка синхронизация Спарки. можно включить или выключить.


//Отладка USB
CONSOLE_DEBUG     вывод отладочной информации от drv_usb.cpp и drv_usbms.cpp


HAVE_ARAMEC   -??
NEED_STAT     -??  Статистика для IPMP

//Описание всех Ошибок ЗООСРВ   ->os_error.h





//Замечание
Файлы CMD распределение Памяти находяться в Папке Projects и внутри для 
кажого проекта в папке cmd  debug и release  отличия серъёзные в папке
в debug нету секций LOAD_PO  и поэтому невохможно получить lif файлы
только в release версии можно это сделать.!!!!
!!!WARNING!!!
!!КАРТА_ПАМЯТИ!!!



Загроузка 6 ки под отладками.

Сначала видимо запускаем сетевые COMM
Потом main
Потом iface

