/*
###############################################################################
## XFERMAKE.CMD
## ------------
## 1901ВЦ1Т Linker Command File 
##
#############################################################################*/
/*****************************************************************************/
/* 1901ВЦ1Т DSK DSP Memory Map                                                  */
/*                                                                           */
/*****************************************************************************/
/*В нашем Случае при загрузке в регистре PMST  ,OVLY=0 ,DROM =0 p.44		  */
/*DSP процессор работает со словом word = 2 байт = 16 бит      */
/*В Данном файле размерность  0x1 = 1[К/слов] = 2 байт =16 бит */
/*Используеться расслоённое ОЗУ вся память поделена на 4 блока по 32Кбайт */
MEMORY
{ 
    /*Память Программм 128[Кбайт]=64[Кслов] = 131072[байт]=0x00020000 Programm RAM*/   
    
    /*---------0x0000-0x4000 size=0x4000[Кслов] 16 [Кслов]=32 Кбайт_1блок расслоенного ОЗУ*/ 
    /*PAGE 0:PRAM_BLOCK1:origin = 0x0000,len = 0x4000*/
    /*---------0x4000-0x8000=size=0x4000[Кслов] 16 [Кслов]=32 Кбайт_2блок расслоенного ОЗУ*/  
    /*PAGE 0:PRAM_BLOCK2:origin = 0x4000,len = 0x4000*/
    PAGE 0:PRAM_BLOCK1:origin = 0x0000,len = 0x8000
   
    /*---------0x8000-0xС000=size=0x4000[Кслов] 16 [Кслов]=32 Кбайт_3блок расслоенного ОЗУ*/
    PAGE 0:PRAM_BLOCK3:origin = 0x8000,len = 0x4000
    /*---------0xС000-0xFFFF=size=0x4000[Кслов] 16 [Кслов]=32 Кбайт_4блок расслоенного ОЗУ*/
    /*--Зарезервировано - 0xFF00-0xFF7F--*/
    PAGE 0:VECT:origin = 0xff80,len = 0x80  /*Здесь распологаються вектора Прерывний */
  
    /*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
    /*Память Данных 128[Кбайт]=64[Кслов] = 131072[байт]=0x00020000 DATA RAM*/ 
    
    /*---------0x0000-0x4000 size=0x4000[Кслов] 16 [Кслов]=32 Кбайт_1блок расслоенного ОЗУ*/  	
    PAGE 1:REGS:	origin = 0x0000, len = 0x80    /*Регистры Ядра+Перефирии 256 байт*/                                                    
    /*---------0x4000-0x8000=size=0x4000[Кслов] 16 [Кслов]=32 Кбайт_2блок расслоенного ОЗУ*/ 
    PAGE 1:DRAM_BLOCK2:   origin = 0x4000, len = 0x4000
    /*---------0x8000-0xС000=size=0x4000[Кслов] 16 [Кслов]=32 Кбайт_3блок расслоенного ОЗУ*/
    PAGE 1:DRAM_BLOCK3:   origin = 0x8000, len = 0x4000
    /*---------0xС000-0xFFFF=size=0x4000[Кслов] 16 [Кслов]=32 Кбайт_4блок расслоенного ОЗУ*/
    PAGE 1:DRAM_BLOCK4:   origin = 0xC000, len = 0x4000
  
}
    
  
    /*Mapping Памяти между DSP и RISC ядром 
     			     DSP   |     RISC        CodeMasterARM 2.40.00
                                             
	DRAM_BLOCK3_str=0x8000 | 0x3001_0000   //805371904

	DRAM_BLOCK3_end=0xC000 | 0x3001_8000   //805404672

	DRAM_BLOCK4_str=0xC000 | 0x3001_8000   //805404672

	DRAM_BLOCK4_end=0xFFFF | 0x3001_FFFF   //805437440
    */




SECTIONS
{    
   .text    > PRAM_BLOCK1 PAGE 0   /*Исполняемый программный код*/                   
   .switch  > PRAM_BLOCK1 PAGE 0   /* switch table info         */    
   .cinit   > PRAM_BLOCK1 PAGE 0   /*Код инициализации Глобальных и Статических Переменных*/
   .vectors > VECT  	  PAGE 0   /* Вектора Прерываний*/      
   /*--------------------------------------------------------------*/
   .cio     > DRAM_BLOCK2 PAGE 1  /* C I/O             */         
   .data    > DRAM_BLOCK2 PAGE 1  /* initialized data  */      
   .bss     > DRAM_BLOCK2 PAGE 1  /*Глобальные и статические Переменные проинициализированные*/     
   .const   > DRAM_BLOCK2 PAGE 1  /*Глобальные и Статические Константы Проинициализированные*/                     
   .sysmem  > DRAM_BLOCK3 PAGE 1  /*Динамическая память (куча)*/          
   .stack   > DRAM_BLOCK3 PAGE 1  /*Область стека*/  
  /* .sysmem  > DRAM_BLOCK2 PAGE 1 */ /*Динамическая память (куча)*/          
  /* .stack   > DRAM_BLOCK2 PAGE 1 */ /*Область стека*/           


    /*Описание регистров DSP ядра 1901ВЦ1Т*/  
   /* IMR:                    0x0000 PAGE 1 */
              
    /*TIM Timer Register */
  /*TIM:                    0x0038 PAGE 1
    PRD:                    0x0039 PAGE 1
    TCR:                    0x003A PAGE 1*/
    /*DMA regs*/
	DMA_STATUSL: 			0x0060 PAGE 1
	DMA_STATUSH: 			0x0061 PAGE 1	 
	DMA_CONFIGL: 			0x0062 PAGE 1
	DMA_CONFIGH: 			0x0063 PAGE 1
	CTRL_BASE_PTRL: 		0x0064 PAGE 1
	CTRL_BASE_PTRH: 		0x0065 PAGE 1
	ALT_CTRL_BASE_PTRL: 	0x0066 PAGE 1
	ALT_CTRL_BASE_PTRH: 	0x0067 PAGE 1
	DMA_WAITONREG_STATUSL: 	0x0068 PAGE 1
	DMA_WAITONREG_STATUSH: 	0x0069 PAGE 1
	CHNL_SW_REQUESTL: 		0x006A PAGE 1
	CHNL_SW_REQUESTH: 		0x006B PAGE 1
	CHNL_USEBURST_SETL: 	0x006C PAGE 1
	CHNL_USEBURST_SETH: 	0x006D PAGE 1
	CHNL_USEBURST_CLRL: 	0x006E PAGE 1
	CHNL_USEBURST_CLRH: 	0x006F PAGE 1
	CHNL_REQ_MASK_SETL: 	0x0070 PAGE 1
	CHNL_REQ_MASK_SETH: 	0x0071 PAGE 1
	CHNL_REQ_MASK_CLRL: 	0x0072 PAGE 1
	CHNL_REQ_MASK_CLRH: 	0x0073 PAGE 1
	CHNL_ENABLE_SETL: 		0x0074 PAGE 1
	CHNL_ENABLE_SETH: 		0x0075 PAGE 1
	CHNL_ENABLE_CLRL: 		0x0076 PAGE 1
	CHNL_ENABLE_CLRH: 		0x0077 PAGE 1
	CHNL_PRI_ALT_SETL: 		0x0078 PAGE 1
	CHNL_PRI_ALT_SETH: 		0x0079 PAGE 1
	CHNL_PRI_ALT_CLRL: 		0x007A PAGE 1
	CHNL_PRI_ALT_CLRH: 		0x007B PAGE 1
	CHNL_PRIORITY_SETL: 	0x007C PAGE 1
	CHNL_PRIORITY_SETH: 	0x007D PAGE 1
	CHNL_PRIORITY_CLRL: 	0x007E PAGE 1
	CHNL_PRIORITY_CLRH: 	0x007F PAGE 1
    /*Audio Codec Reg*/
    /*
     DACREG                  0x005C PAGE 1
     ADCREG                  0x005A PAGE 1
     IRQFLAG                 0x0058 PAGE 1 
     MASKCTL                 0x0056 PAGE 1
     DACCTL:				 0x0054 PAGE 1
     ADCCTL:				 0x0052 PAGE 1
     POWCTL:				 0x0050 PAGE 1 */

}