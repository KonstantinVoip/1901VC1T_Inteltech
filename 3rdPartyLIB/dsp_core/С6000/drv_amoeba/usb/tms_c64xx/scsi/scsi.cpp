//**************************************************************************************************
//                         Copyright (C) 2009 RCZI
//--------------------------------------------------------------------------------------------------
// FILENAME....... scsi.cpp
//--------------------------------------------------------------------------------------------------
//                           SCSI Command
//-------------------------------------------------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
//
// !: codepage: cp1251 
//
// !: d: Функции формирования SCSI команд.<br>
// !: -:
//***sss********************************************************************************************/
#include	<rts.h>
//SCSI command block size:
#define SIZEOF_SCSI_CMD_BLOCK				 12
//SCSI Commands:
#define SCSI_CMD_FormatUnit                  0x04 //out
#define SCSI_CMD_Inquiry                     0x12 //in
#define SCSI_CMD_StartStop                   0x1B //---
#define SCSI_CMD_ModeSelect                  0x55 //out
#define SCSI_CMD_ModeSense_10                0x5A //in
#define SCSI_CMD_ModeSense_6                 0x5A //in
#define SCSI_CMD_PreventAllowMediumRemoval   0x1E //---
#define SCSI_CMD_Read10                      0x28 //in
#define SCSI_CMD_Read12                      0xA8 //in
#define SCSI_CMD_ReadCapacity                0x25 //in
#define SCSI_CMD_ReadFormatCapacity          0x23 //in
#define SCSI_CMD_RequestSense                0x03 //---
#define SCSI_CMD_RezeroUnit                  0x01 //---
#define SCSI_CMD_Seek10                      0x2B //---
#define SCSI_CMD_SendDiagnostic              0x1D //---
#define SCSI_CMD_TestUnitReady               0x00 //---
#define SCSI_CMD_Verify                      0x2F //---
#define SCSI_CMD_Write10                     0x2A //out
#define SCSI_CMD_Write12                     0xAA //out
#define SCSI_CMD_Write_and_Verify_10         0x2E //out
#define SCSI_CMD_Task_Management_Functions   0xA3
#define SCSI_CMD_PRE_FETCH_10                0x34

//===== MODE SENSE(10) command: 5Ah =============
void scsi_mode_sense_10(void* BufferSCSICommand, int32 iLLBAA, int32 iDBD, int32 iPC, int32 iPAGE_CODE, int32 iSUBPAGE_CODE, int32 iALLOCATION_LENGTH, int32 iCONTROL)
{
    uint8* SCSICommand = (uint8*) BufferSCSICommand;
    memset(SCSICommand,0x0,SIZEOF_SCSI_CMD_BLOCK);
    SCSICommand[0] = SCSI_CMD_ModeSense_10;
    SCSICommand[1] = ((iLLBAA&0x1)<<4)|((iDBD&0x1)<<3);
    SCSICommand[2] = ((iPC&0x3)<<6)|(iPAGE_CODE&0x3F);
    SCSICommand[3] = iSUBPAGE_CODE&0xFF;
    SCSICommand[7] = (iALLOCATION_LENGTH&0xFF00)>>0x8;
    SCSICommand[8] = iALLOCATION_LENGTH&0x00FF;
    SCSICommand[9] = iCONTROL&0xFF;
}

//===== MODE SENSE(6) command: 1Ah =============
void scsi_mode_sense_6(void* BufferSCSICommand, int32 iDBD, int32 iPC, int32 iPAGE_CODE, int32 iSUBPAGE_CODE, int32 iALLOCATION_LENGTH, int32 iCONTROL)
{
    uint8* SCSICommand = (uint8*) BufferSCSICommand;
    memset(SCSICommand,0x0,SIZEOF_SCSI_CMD_BLOCK);
    SCSICommand[0] = SCSI_CMD_ModeSense_6;
    SCSICommand[1] = (iDBD&0x1)<<3;
    SCSICommand[2] = ((iPC&0x3)<<6)|(iPAGE_CODE&0x3F);
    SCSICommand[3] = iSUBPAGE_CODE&0xFF;
    SCSICommand[4] = iALLOCATION_LENGTH&0xFF;
    SCSICommand[5] = iCONTROL&0xFF;
}
//===== TASK MANAGEMENT FUNCTIONS command: A3h ==
void scsi_task_management_functions(void* BufferSCSICommand,int32 iAllocationLength)
{
    uint8* SCSICommand = (uint8*) BufferSCSICommand;
    memset(SCSICommand,0x0,SIZEOF_SCSI_CMD_BLOCK);
    SCSICommand[0] = SCSI_CMD_Task_Management_Functions;
    SCSICommand[1] = 0x0D;
    SCSICommand[6] = (iAllocationLength & 0xFF000000)>>24;
    SCSICommand[7] = (iAllocationLength & 0x00FF0000)>>16;
    SCSICommand[8] = (iAllocationLength & 0x0000FF00)>>8;
    SCSICommand[9] = (iAllocationLength & 0x000000FF);
}
//===== WRITE(10) Command: 2Ah ==================
void scsi_write_10(void* BufferSCSICommand, int32 iLBA, int32 iTransferLength, int32 iWRPROTECT, int32 iDPO, int32 iFUA, int32 iFUA_NV, int32 iGROUP_NUMBER, int32 iCONTROL)
{
    uint8* SCSICommand = (uint8*) BufferSCSICommand;
    memset(SCSICommand,0x0,SIZEOF_SCSI_CMD_BLOCK);
    SCSICommand[0] = SCSI_CMD_Write10;
    SCSICommand[1] = ((iWRPROTECT&0x7)<<5)|((iDPO&0x1)<<4)|((iFUA&0x1)<<3)|((iFUA_NV&0x1)<<1);
    SCSICommand[2] = ((iLBA>>24) & 0xFF);
    SCSICommand[3] = ((iLBA>>16) & 0xFF);
    SCSICommand[4] = ((iLBA>>8) & 0xFF);
    SCSICommand[5] = (iLBA & 0xFF);
    SCSICommand[6] = (iGROUP_NUMBER & 0x1F);
    SCSICommand[7] = ((iTransferLength>>8) & 0xFF);
    SCSICommand[8] = (iTransferLength & 0xFF);
    SCSICommand[9] = (iCONTROL & 0xFF);
}
//===== READ(10) Command: 28h ==================
void scsi_read_10(void* BufferSCSICommand, int32 iLBA, int32 iTransferLength, int32 iRDPROTECT, int32 iDPO, int32 iFUA, int32 iFUA_NV, int32 iGROUP_NUMBER, int32 iCONTROL)
{
    uint8* SCSICommand = (uint8*) BufferSCSICommand;
    memset(SCSICommand,0x0,SIZEOF_SCSI_CMD_BLOCK);
    SCSICommand[0] = SCSI_CMD_Read10;
    SCSICommand[1] = ((iRDPROTECT&0x7)<<5)|((iDPO&0x1)<<4)|((iFUA&0x1)<<3)|((iFUA_NV&0x1)<<1);
    SCSICommand[2] = ((iLBA>>24) & 0xFF);
    SCSICommand[3] = ((iLBA>>16) & 0xFF);
    SCSICommand[4] = ((iLBA>>8) & 0xFF);
    SCSICommand[5] = (iLBA & 0xFF);
    SCSICommand[6] = (iGROUP_NUMBER & 0x1F);
    SCSICommand[7] = ((iTransferLength>>8) & 0xFF);
    SCSICommand[8] = (iTransferLength & 0xFF);
    SCSICommand[9] = (iCONTROL & 0xFF);
}
//===== WRITE AND VERIFY(10) Command: 2Eh ==================
void scsi_write_and_verify_10(void* BufferSCSICommand, int32 iLBA, int32 iTransferLength, int32 iWRPROTECT, int32 iDPO, int32 iBYTCHK, int32 iGROUP_NUMBER, int32 iCONTROL)
{
    uint8* SCSICommand = (uint8*) BufferSCSICommand;
    memset(SCSICommand,0x0,SIZEOF_SCSI_CMD_BLOCK);
    SCSICommand[0] = SCSI_CMD_Write_and_Verify_10;
    SCSICommand[1] = ((iWRPROTECT&0x7)<<5)|((iDPO&0x1)<<4)|((iBYTCHK&0x1)<<1);
    SCSICommand[2] = ((iLBA>>24) & 0xFF);
    SCSICommand[3] = ((iLBA>>16) & 0xFF);
    SCSICommand[4] = ((iLBA>>8)  & 0xFF);
    SCSICommand[5] = (iLBA & 0xFF);
    SCSICommand[6] = (iGROUP_NUMBER & 0x1F);
    SCSICommand[7] = ((iTransferLength>>8) & 0xFF);
    SCSICommand[8] = (iTransferLength & 0xFF);
    SCSICommand[9] = (iCONTROL & 0xFF);
}
//===== START-STOP UNIT Command: 1Bh ============
void scsi_start_stot_unit(void* BufferSCSICommand,int32 iIMMED,int32 iPOWER_CONDITION, int32 iLOEJ, int32 iSTART,int32 iCONTROL)
{
    uint8* SCSICommand = (uint8*) BufferSCSICommand;
    memset(SCSICommand,0x0,SIZEOF_SCSI_CMD_BLOCK);
    SCSICommand[0] = SCSI_CMD_StartStop;
    SCSICommand[1] = iIMMED&0x1;
    SCSICommand[4] = ((iPOWER_CONDITION&0xF)<<4)|((iLOEJ&0x1)<<1)|(iSTART&0x1);
    SCSICommand[5] = iCONTROL&0xFF;
}
//===== INQUIRY Command: 12h ====================
void scsi_inquiry(void* BufferSCSICommand,int32 iEVPD, int32 iPAGECODE, int32 iALLOCATIONLENGTH,int32 iCONTROL)
{
    uint8* SCSICommand = (uint8*) BufferSCSICommand;
    memset(SCSICommand,0x0,SIZEOF_SCSI_CMD_BLOCK);
    SCSICommand[0] = SCSI_CMD_Inquiry;
    SCSICommand[1] = iEVPD&0x1;
    SCSICommand[2] = iPAGECODE&0xFF;
    SCSICommand[3] = (iALLOCATIONLENGTH&0xFF00)>>0x8;
    SCSICommand[4] = iALLOCATIONLENGTH&0x00FF;
    SCSICommand[5] = iCONTROL&0xFF;
}
//===== READ CAPACITY Command: 25h ==============
void scsi_read_capacity(void* BufferSCSICommand,int32 iLBA,int32 iPMI,int32 iCONTROL)
{
    uint8* SCSICommand = (uint8*) BufferSCSICommand;
    memset(SCSICommand,0x0,SIZEOF_SCSI_CMD_BLOCK);
    SCSICommand[0] = SCSI_CMD_ReadCapacity;
    SCSICommand[2] = ((iLBA>>24) & 0xFF);
    SCSICommand[3] = ((iLBA>>16) & 0xFF);
    SCSICommand[4] = ((iLBA>>8)  & 0xFF);
    SCSICommand[5] = (iLBA & 0xFF);
    SCSICommand[8] = iPMI&0x1;
    SCSICommand[9] = iCONTROL&0xFF;
}
//===== TEST UNIT READY Command: 00h ============
void scsi_test_unit_ready(void* BufferSCSICommand)
{
    uint8* SCSICommand = (uint8*) BufferSCSICommand;
    memset(SCSICommand,0x0,SIZEOF_SCSI_CMD_BLOCK);
    SCSICommand[0] = SCSI_CMD_TestUnitReady;
}
//===== REQUEST SENSE Command: 03h ==============
void scsi_request_sense(void* BufferSCSICommand,int32 iDESC,int32 iALLOCATION_LENGTH,int32 iCONTROL)
{
    uint8* SCSICommand = (uint8*) BufferSCSICommand;
    memset(SCSICommand,0x0,SIZEOF_SCSI_CMD_BLOCK);
    SCSICommand[0] = SCSI_CMD_RequestSense;
    SCSICommand[1] = iDESC&0x1;;
    SCSICommand[4] = iALLOCATION_LENGTH&0xFF;
    SCSICommand[5] = iCONTROL&0xFF;
}
//===== PRE-FETCH (10) command: 34h =============
void scsi_pre_fetch_10(void* BufferSCSICommand, int32 iLBA, int32 iPreFetchLength, int32 iGROUP_NUMBER, int32 iCONTROL)
{
    int32 iIMMED = 0;
    uint8* SCSICommand = (uint8*) BufferSCSICommand;
    memset(SCSICommand,0x0,SIZEOF_SCSI_CMD_BLOCK);
    SCSICommand[0] = SCSI_CMD_PRE_FETCH_10;
    SCSICommand[1] = ((iIMMED&0x1)<<1);
    SCSICommand[2] = ((iLBA>>24) & 0xFF);
    SCSICommand[3] = ((iLBA>>16) & 0xFF);
    SCSICommand[4] = ((iLBA>>8) & 0xFF);
    SCSICommand[5] = (iLBA & 0xFF);
    SCSICommand[6] = (iGROUP_NUMBER & 0x1F);
    SCSICommand[7] = ((iPreFetchLength>>8) & 0xFF);
    SCSICommand[8] = (iPreFetchLength & 0xFF);
    SCSICommand[9] = (iCONTROL & 0xFF);
}

