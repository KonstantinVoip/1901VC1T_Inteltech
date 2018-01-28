/**********************************************************************************************************************
*                                        (c) COPYRIGHT by ZAO RCZI FORT.                                             *
*        ..                                       All rights reserved.                                               *
***********************************************************************************************************************
* Module      : tpo_hash.cpp
* Description : Реализации функций хэширования
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
#include <crypto_hash.h>
#include <tpo_hash.h>
#include <tpo.h>



extern const uint8 hash_start_vect0[] = 
{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};



uint32 cry_hash_fwmem(s_hash* ctx, void* start_vector, hash_window* hwin)
{
  uint32   hash_text[128/4];
  uint32   hash_text_test[128/4];
  int32   fwm_file, error, size;
  uint32  length;
  uint32  offset = hwin->start_addr;
  fwmem_rwbuf fwrw;
  fwmem_rwbuf fwrw1;

	uint32 int_old = 0;


  fwm_file = drv_mkd("/fwmem");
  if(fwm_file == RES_VOID) return TPO_ERR_FWM;

  cry_hash_start(ctx, start_vector);
  while(true)
  {
    if( hwin->end_addr == 0 ) break;
    length = hwin->end_addr - hwin->start_addr + 1;
	offset = hwin->start_addr;

//once_again:
//    error = drv_ioctl(fwm_file, FWMEM_SET_OFFSET, &offset);
//    if(error) goto err_cry_hash;

    while(length)
    {
      size = (length > sizeof(hash_text)) ? sizeof(hash_text) : length;
      //Чтение данных:

	int_old = int_disable();

      error = drv_ioctl(fwm_file, FWMEM_SET_OFFSET,  &offset);
      fwrw.buffer = hash_text;
      fwrw.length = size;
      error = drv_ioctl(fwm_file, FWMEM_READ, &fwrw);

    int_enable(int_old);
      if(error) goto err_cry_hash;

	int_old = int_disable();
		
      error = drv_ioctl(fwm_file, FWMEM_SET_OFFSET, &offset);
      fwrw1.buffer = hash_text_test;
      fwrw1.length = size;
      error = drv_ioctl(fwm_file, FWMEM_READ, &fwrw1);

    int_enable(int_old);
      if(error) goto err_cry_hash;


	if(memcmp(hash_text, hash_text_test, size))
	goto err_cry_hash;


      cry_hash_cont(ctx, hash_text, size);
     	length -= size;
		offset += size;
    }
    hwin++;
  }
  cry_hash_end(ctx);  
  drv_rmd(fwm_file);
  return TPO_OK;

err_cry_hash:
drv_rmd(fwm_file);
return TPO_ERR_FWM;
}
/**************************************************************************************************\
*  Вычитывание ХЭШ из флэш
\***sss********************************************************************************************/

uint32 hash_get(s_hash* ctx)
{
  int32  fwm_file, error;
  uint32 offset;
  fwmem_rwbuf fwrw;

	uint32 int_old = 0;

  fwm_file = drv_mkd("/fwmem");
  if(fwm_file == RES_VOID) return TPO_ERR_FWM;

	int_old = int_disable();

  error = drv_ioctl(fwm_file, FWMEM_SIZE, &offset);
  if(error) goto err_get_hash;

  offset -= 64;


  error = drv_ioctl(fwm_file, FWMEM_SET_OFFSET, &offset);
  if(error) goto err_get_hash;

  memset(ctx, 0, sizeof(s_hash));

  fwrw.buffer = ctx->h;
  fwrw.length = 32;
  error = drv_ioctl(fwm_file, FWMEM_READ, &fwrw);
  if(error)	goto err_get_hash;

  int_enable(int_old);
  drv_rmd(fwm_file);
  return TPO_OK;

err_get_hash:
    int_enable(int_old);
	drv_rmd(fwm_file);
	return TPO_ERR_FWM;
}















/*
uint32 cry_hash_fwmem(s_hash* ctx, void* start_vector, hash_window* hwin)
{
  uint32   hash_text[128/4];
  uint32   hash_text_test[128/4];
  int32   fwm_file, error, size;
  uint32  length;
  uint32  offset = hwin->start_addr;
  fwmem_rwbuf fwrw;
  fwmem_rwbuf fwrw1;

	uint32 int_old = 0;


  fwm_file = drv_mkd("/fwmem");
  if(fwm_file == RES_VOID) return TPO_ERR_FWM;

  cry_hash_start(ctx, start_vector);
  while(true)
  {
    if( hwin->end_addr == 0 ) break;
    length = hwin->end_addr - hwin->start_addr + 1;
	offset = hwin->start_addr;

once_again:
//    if(error) goto err_cry_hash;

    while(length)
    {
	int_old = int_disable();

	  error = drv_ioctl(fwm_file, FWMEM_SET_OFFSET, &offset);
      if(error)
      {
      int_enable(int_old);
      goto once_again;
	  }
      size = (length > sizeof(hash_text)) ? sizeof(hash_text) : length;
      //Чтение данных:
//      error = drv_ioctl(fwm_file, FWMEM_SET_OFFSET, (&hwin->start_addr) + offset);
      fwrw.buffer = hash_text;
      fwrw.length = size;
      error = drv_ioctl(fwm_file, FWMEM_READ, &fwrw);
      int_enable(int_old);
      if(error) goto once_again;
//      if(error) goto err_cry_hash;
		
	  int_old = int_disable();
      error = drv_ioctl(fwm_file, FWMEM_SET_OFFSET, &offset); //двойное вычит
      if(error)
      {
      int_enable(int_old);
      goto once_again;
	  }
      fwrw1.buffer = hash_text_test;
      fwrw1.length = size;
      error = drv_ioctl(fwm_file, FWMEM_READ, &fwrw1);
      int_enable(int_old);
      if(error) goto once_again;
//      if(error) goto err_cry_hash;

	if(memcmp(hash_text, hash_text_test, size))
	goto once_again;


      cry_hash_cont(ctx, hash_text, size);
     	length -= size;
		offset += size;
    }
    hwin++;
  }
  cry_hash_end(ctx);  
  drv_rmd(fwm_file);
  return TPO_OK;

err_cry_hash:
drv_rmd(fwm_file);
return TPO_ERR_FWM;
}
*/
/**************************************************************************************************\
*  Вычитывание ХЭШ из флэш
\***sss********************************************************************************************/
/*
uint32 hash_get(s_hash* ctx)
{
  int32  fwm_file, error;
  uint32 offset;
  fwmem_rwbuf fwrw;
  fwmem_rwbuf fwrw_check;
  uint8 buf[32];

	uint32 int_old = 0;

  fwm_file = drv_mkd("/fwmem");
  if(fwm_file == RES_VOID) return TPO_ERR_FWM;

  error = drv_ioctl(fwm_file, FWMEM_SIZE, &offset);
  if(error) goto err_get_hash;

  offset -= 64;

once_again_get:

	int_old = int_disable();

  error = drv_ioctl(fwm_file, FWMEM_SET_OFFSET, &offset);
  if(error)
  {
  int_enable(int_old);
  goto once_again_get;
  }

  memset(ctx, 0, sizeof(s_hash));

  fwrw.buffer = ctx->h;
  fwrw.length = 32;
  error = drv_ioctl(fwm_file, FWMEM_READ, &fwrw);
  int_enable(int_old);
  if(error)
  {
  int_enable(int_old);
  goto once_again_get;
  }


//еще раз
	int_old = int_disable();
  error = drv_ioctl(fwm_file, FWMEM_SET_OFFSET, &offset);
  if(error) goto once_again_get;

  memset(buf, 0, sizeof(buf));

  fwrw_check.buffer = buf;
  fwrw_check.length = 32;
  error = drv_ioctl(fwm_file, FWMEM_READ, &fwrw_check);
  int_enable(int_old);
  if(error)	goto once_again_get;


	if(memcmp(fwrw.buffer, fwrw_check.buffer, 32))
	goto once_again_get;




  drv_rmd(fwm_file);
  return TPO_OK;

err_get_hash:
	drv_rmd(fwm_file);
	return TPO_ERR_FWM;
}
*/
/**************************************************************************************************\
*  Подсчет HASH за всю флеш на нулевом стартово векторе
\***sss********************************************************************************************/

uint32 analysis_hash_fwmem(hash_window* hwin)
{
  register int32       error;
  msg_hash_fwm       msg_hash;
//повтор 3 раза... тк. появл. редкие ошибки
  int32	ret = 3;

//m_retry3:
while(ret--)
{
  memset(&msg_hash, 0x0, sizeof(msg_hash_fwm));
  error = cry_hash_fwmem(&msg_hash.hash, const_cast<uint8*>(hash_start_vect0), hwin);
  if(error != TPO_OK)
  {
   msg_hash.akn = error;
//    goto m_return;
  }
  msg_hash.akn = hash_get(&msg_hash.hash_fwm);

 if(0x0 == memcmp(&msg_hash.hash.h, &msg_hash.hash_fwm.h, sizeof(msg_hash.hash.h)))
    return TPO_OK;
}

//m_return:
    return TPO_ER_HASH;
}


/*
uint32 analysis_hash_fwmem_main(hash_window* hwin)
{
  register int32       error;
  msg_hash_fwm       msg_hash;
  memset(&msg_hash, 0x0, sizeof(msg_hash_fwm));
  error = cry_hash_fwmem(&msg_hash.hash, const_cast<uint8*>(hash_start_vect0), hwin);
  if(error != TPO_OK)
  {
    msg_hash.akn = error;
    goto m_return;
  }
  msg_hash.akn = hash_get(&msg_hash.hash_fwm);

m_return:
  if(0x0 != memcmp(&msg_hash.hash.h, &msg_hash.hash_fwm.h, sizeof(msg_hash.hash.h)))
    return TPO_ER_HASH;
  else
    return TPO_OK;
}
*/
