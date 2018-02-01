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

//���� ������� ��������� ������ ���,(�������� ��� �� ����� ��22) 
//���������� ��������� ��� in_port2 ���� PORT_UNUSED
typedef struct _mcbsp_context
{
  uint16       out_port;                //������� ����� ����� �������� //MCBSP_PORT0,MCBSP_PORT1 ��� MCBSP_PORT2
  uint16       in_port1;                //������� ����� ����� ������ 1 //MCBSP_PORT0,MCBSP_PORT1 ��� MCBSP_PORT2
  uint16       in_port2;                //������� ����� ����� ������ 2 //MCBSP_PORT0,MCBSP_PORT1 ��� MCBSP_PORT2

  MCBSP_Config mcbsp_cfg_in;    //MCBSP ��������� �� �����             
  MCBSP_Config mcbsp_cfg_out;   //MCBSP ��������� �� ��������              

  EDMA_Config  edma_cfg_in;             //EDMA ��������� �� �����
  EDMA_Config  edma_cfg_out;    //EDMA ��������� �� ��������

}mcbsp_context;

extern int32 drv_mcbsp_plug(mcbsp_context* ctx);
extern int32 drv_mcbsp_unplug();

#endif //__Driver_MCBSP_H__
