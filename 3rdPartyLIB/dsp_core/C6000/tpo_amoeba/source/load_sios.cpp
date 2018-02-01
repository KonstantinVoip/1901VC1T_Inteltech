/**********************************************************************************************************************
*                                        (c) COPYRIGHT by ZAO RCZI FORT.                                             *
*        ..                                       All rights reserved.                                               *
***********************************************************************************************************************
* Module      : load_sios.c
* Description : Функции перехода в СИОС
* Author      : 
******************************************************************************
******************************************************************************
* Module's Description Record:
* ============================
* Module's revision history:
* ==========================
* --------- $Log: mpcdrvlbcCyclone.h $
* --------- Initial revision
******************************************************************************/


#include <rts.h>
#include <mapi.h>     
#include <drv_fwmem.h>
#include "tpo.h"

/**************************************************************************************************\
*  Завершение ТПО и Загрузка СИОС
***********/

void load_lif(void* mem_lif);

void load_lif(void* mem_lif)
{

  int32        error;
  uint32       msg_pid_os;
  char         path[64];
  char         dsp_name[32];



	sys_getname(dsp_name, sizeof(dsp_name));

	if(mem_lif == NULL)
	{
      //Формирование пути:
      strcpy(path, "/fwmem/");
      strcat(path, "sios-");
	  //strcat(path, "tpo-");
      
      #ifdef COMM
      	strncat(path, dsp_name, 4);
      #else
     	 strcat(path, dsp_name);
      #endif
      
      strcat(path, ".lif");

	}

    //Установка обмена:
     msg_pid_os = msg_discover( dsp_name, "os", SEM_INFINITY );
      
     if(msg_pid_os != RES_VOID)
     {
		#ifdef TPO5
        //Команда на загрузку:
	  	if(mem_lif == NULL)
		{
		 //skd_comment  //Нужна библиотека MAPI
	      error = mapi_loadafterme( msg_pid_os, path, NULL);
			if(error)
				error++;
		}
		else
		{
	       //skd_comment
	       error = mapi_loadafterme( msg_pid_os, NULL, mem_lif);
			if(error)
				error++;
		}
		#else
          //skd_comment  
	      error = mapi_loadafterme( msg_pid_os, path, NULL);
			if(error)
				error++;
            

		#endif // TPO5

    }
	else 
	{

	while(1);

    }


}

void Load_lif_from_usb()
{

	uint32		msg_from;
	int32		error;
	kdg_cmd_ask	cdg_error;
	s_message*  msg_desc;
	uint32		len_lif;
	uint32		N_block;
	uint32		start_cmd;
	uint32		len_block = 128;

	s_os_mem_block*       mem_block;
	uint8*                buf;


  while(true)
  {
	if(msg_recv( &msg_desc, SEM_INFINITY) != OSE_OK)
		return;

    if(msg_desc == NULL) continue;
    if(msg_desc->length !=sizeof(uint32))
    {
      cdg_error.cmd = ERROR_CMD;
      cdg_error.ask = TPO_ERR;
      msg_send(msg_desc->from, &cdg_error, sizeof(kdg_cmd_ask));  
      msg_free(msg_desc);      
      continue;
    }
    else
     break;

  }
    msg_from = msg_desc->from;
	memcpy(&len_lif, msg_desc->data, msg_desc->length);
    msg_free(msg_desc);      

      mem_block = mem_alloc(len_lif, MPAGE_ALL);
      if(mem_block != NULL)
      {
		cdg_error.cmd = len_lif;
		cdg_error.ask = TPO_OK;
		msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));

      buf = (uint8*)mem_ptr(mem_block);
      }
      else
      {
		cdg_error.cmd = len_lif;
		cdg_error.ask = TPO_ERR;
		msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));

        mem_free(mem_block);
        return;
      }

N_block = (len_lif/len_block)+1;
	

for(int N = 0; N < N_block; N++)
{
	while(true)
	{
	if(msg_recv( &msg_desc, SEM_INFINITY) != OSE_OK)
		return;
    if(msg_desc != NULL) 
    	break;
	}
	
	memcpy(buf, msg_desc->data, msg_desc->length);
	buf = buf + msg_desc->length;
    msg_free(msg_desc);      

    cdg_error.cmd = ERROR_CMD;
    cdg_error.ask = TPO_OK;
    msg_send(msg_desc->from, &cdg_error, sizeof(kdg_cmd_ask));  
}

	buf = (uint8*)mem_ptr(mem_block);





  while(true)
  {
	if(msg_recv( &msg_desc, SEM_INFINITY) != OSE_OK)
		return;

    if(msg_desc == NULL) continue;
    if(msg_desc->length !=sizeof(uint32))
    {
      cdg_error.cmd = ERROR_CMD;
      cdg_error.ask = TPO_ERR;
      msg_send(msg_desc->from, &cdg_error, sizeof(kdg_cmd_ask));  
      msg_free(msg_desc);      
      continue;
    }
    else
     break;

  }

    msg_from = msg_desc->from;
	memcpy(&start_cmd, msg_desc->data, msg_desc->length);
    msg_free(msg_desc);      

      if(start_cmd == START_LIF)
      {
		cdg_error.cmd = len_lif;
		cdg_error.ask = TPO_OK;
		msg_send(msg_from, &cdg_error, sizeof(kdg_cmd_ask));

		load_lif(buf);
		mem_free(mem_block);
	  }
}
