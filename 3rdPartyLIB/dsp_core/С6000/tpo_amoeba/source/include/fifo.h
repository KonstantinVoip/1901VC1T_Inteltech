#ifndef __FIFO_H__
#define __FIFO_H__

#include <rts.h>
//#include "posix.h"

int FIFO_inIsReady();
//----------------------------------------------------------------------------
uint16 FIFO_outIsReady();
//----------------------------------------------------------------------------
uint16 FIFO_WritePacket(void *hdr,void *packet,uint16 shift_ip, uint16 p_len);
//----------------------------------------------------------------------------
int FIFO_ReadHdr(void *hdr);
//----------------------------------------------------------------------------
//uint16 FIFO_ReadPacket(void *packet,uint16 lan);
int FIFO_ReadPacket(void *packet,uint16 lan, uint16 len);
//----------------------------------------------------------------------------
void FIFO_StartWritePacket(void *hdr,void *packet,uint16 shift_ip, uint16 p_len);
int FIFO_EndWritePacket();
//----------------------------------------------------------------------------
void FIFO_StartReadPacket(void *packet,uint16 lan, uint16 len);
int FIFO_EndReadPacket();
//----------------------------------------------------------------------------
void FIFO_DropPacket();
//----------------------------------------------------------------------------
void FIFO_FreeRD();
//----------------------------------------------------------------------------
uint16 CheckWritePacket();
//----------------------------------------------------------------------------
#endif
