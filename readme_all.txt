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

 



Описание некотрых DEFINE используемых при сборке проектов
ISP176_BUS_32==1 - шина 32 бита 
ISP176_BUS_32==0 - шина 16 бит
NO_OS_MEMTST     - тестирование памяти  drv_nvram.cpp,os_core.cpp
OS_SUPPORT_SYNCHRONIZATION  - поддкржка синхронизация Спарки. можно включить или выключить.
s