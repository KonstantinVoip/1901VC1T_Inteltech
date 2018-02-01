//**************************************************************************************************
//                         Copyright (C) 2009 RCZI
//--------------------------------------------------------------------------------------------------
// FILENAME....... drv_rik_redirect.h
// DATE CREATED... 12/05/2011
// LAST MODIFIED.. 12/05/2011
// DRIVER VERSION. 1.0
//--------------------------------------------------------------------------------------------------
//                  ƒ–¿…¬≈– –Œ——»…— Œ… »Õ“≈ÀÀ≈ “”¿À‹ÕŒ…  ¿–“€
//**************************************************************************************************
#ifndef     __Driver_Rik_Redirect_H__
#define     __Driver_Rik_Redirect_H__
#include    <drv_rik.h>
//--- Command structur --------------------------------------------------------
struct  s_drv_rik_errno
{
  uint16          code;
  uint16          length;
};
struct  s_drv_rik_var
{
  s_drv_rik_errno error;
  uint16          dir_pointer;
  uint16          select_reader;
  uint16          zone;
  uint16          offset;
  uint16          rw_cmd_left;
  uint32          ppid;
  s_rik_reset     card_data;
};
struct s_msg_cmd
{
  uint32         cmd;
  s_drv_rik_var  rikdata;
};
struct s_msg_akn
{
  int32          akn;
  uint16         rw_cmd_left;
};
struct s_msg_akn_reset
{
  int32          akn;
  uint16         rw_cmd_left;
  s_rik_reset    reset;
};
struct s_msg_akn_rw
{
  int32          akn;
  uint16         rw_cmd_left;
  uint32         len;
};
struct s_msg_password
{
    uint8       n_pwd;
    uint8       pwd[8];
};
//--- Command for redirect ----------------------------------------------------
#define MSG_RIK_WRITE               0xD1000000
#define MSG_RIK_READ                0xD1000001
#define MSG_RIK_GET_RESET_STRUCT    0xD1000002
#define MSG_RIK_VERIFY_PASSWORD     0xD1000003
#define MSG_RIK_CHANGE_PASSWORD     0xD1000004
#define MSG_RIK_UNLOCK_CARD         0xD1000005
#define MSG_RIK_CHECK_DOOR          0xD1000006 
#define MSG_RIK_CHECK               0xD1000007
#define MSG_RIK_EXIT                0xD1000008

#endif //__Driver_Rik_Redirect_H__
