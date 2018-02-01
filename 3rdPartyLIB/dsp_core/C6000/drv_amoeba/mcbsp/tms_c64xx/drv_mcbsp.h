#ifndef __Driver_MCBSP_H__
#define __Driver_MCBSP_H__

#include "os_csl_mcbsp.h"

#ifndef MCBSP_PORT0
        #define MCBSP_PORT0     0x0
#endif

#ifndef MCBSP_PORT1
        #define MCBSP_PORT1     0x1
#endif

#ifndef MCBSP_PORT2
        #define MCBSP_PORT2     0x2
#endif

#define PORT_UNUSED             0x3

        
extern EDMA_Config iface_in_edmaCfg;
extern EDMA_Config iface_out_edmaCfg;
extern MCBSP_Config iface_in_mcbspCfg;
extern MCBSP_Config iface_out_mcbspCfg;

extern EDMA_Config main_in_edmaCfg;
extern EDMA_Config main_out_edmaCfg;
extern MCBSP_Config main_in_mcbspCfg;
extern MCBSP_Config main_out_mcbspCfg;

extern MCBSP_Config main_spi_mcbspCfg;

//Если второго приемного канала нет,(например как ЦП плата СВ22) 
//необходимо поставить для in_port2 флаг PORT_UNUSED
typedef struct _mcbsp_context
{
  uint16       out_port;                //Указать номер порта отправки //MCBSP_PORT0,MCBSP_PORT1 или MCBSP_PORT2
  uint16       in_port1;                //Указать номер порта приема 1 //MCBSP_PORT0,MCBSP_PORT1 или MCBSP_PORT2
  uint16       in_port2;                //Указать номер порта приема 2 //MCBSP_PORT0,MCBSP_PORT1 или MCBSP_PORT2

  MCBSP_Config mcbsp_cfg_in;    //MCBSP настройки на прием             
  MCBSP_Config mcbsp_cfg_out;   //MCBSP настройки на передачу              

  EDMA_Config  edma_cfg_in;             //EDMA настройки на прием
  EDMA_Config  edma_cfg_out;    //EDMA настройки на передачу

}mcbsp_context;

extern int32 drv_mcbsp_plug(mcbsp_context* ctx);
extern int32 drv_mcbsp_unplug();

#endif //__Driver_MCBSP_H__
