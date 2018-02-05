#define SYSCALL_DIRECT
#include <os.h>
#include <rts.h>
#include <drv_gpio.h>
#include <drv_fwmem.h>
#include <drv_usbhc.h>
#include <drv_usb.h>
#include <drv_usbms.h>
#include <drv_dbgout.h>
#include <drv_mcbsp.h>
#include <drv_ipmp.mcbsp.h>
#include <drv_ipmp.dsp-16.h>
#include <drv_nvram.h>
#include <drv_vfat.h>
#include <__fs.h>
// ---------------------------------------------------------------------------
DEFINE_USBDEV( USB1, 0, 0 );
DEFINE_USBDEV( USB2, 2, 0 );
// ---------------------------------------------------------------------------
uint32 usbhc_plug = 0;
// ---------------------------------------------------------------------------
void dev_assignLetter(uint32 usbhc_plug)
{
  switch(usbhc_plug)
  {
    case USBHC_NEC_PLUG: 
    {
      dev.assignLetter(USB1,0,1,4);
    }
    break;
    case USBHC_ISP_PLUG: 
    {
      dev.assignLetter(USB2,0,1,4);
    }
    break;    
  }  
}
// ---------------------------------------------------------------------------
extern int os_main(void* arg);
// ---------------------------------------------------------------------------
void os_config()
{
    syscall_init( __syscall_tab, sizeof(void*) * SYSCALL__COUNT__ );

    OS_TOUCH_CODE();

    sys_setname( "main" );

    sys_frequency = 1000000000llu;
    sys_quant = core_init_cfg.sys_quant;
  
    emif_init();
}
// ---------------------------------------------------------------------------
bool wait_msd0_flash()
{
  s_inode *first_list, *list;
  uint32 msd_found;

  uint32 d = drv_mkd("/dev");
  if( d == RES_VOID ) return false;

  msd_found = 0;
  while(msd_found == 0)
  {
    drv_ioctl(d, IOC_INODE_LIST, &first_list);
    list = first_list;
    while(list != NULL)
    {
      if(memcmp(list->name, "sd", 2)==0)
      {
        msd_found = 1;
        break;
      }
      list = list->next;
    }
    drv_list_destroy( first_list );
    if( msd_found ) break;
    prc_yield();
  }

  drv_rmd(d);
  
  return true;
}
// ---------------------------------------------------------------------------
int sios_debug_process( void* arg )
{
  int32         error, cmd, akn;
  uint32        msg_from, fwm_file;
  uint8         hash_text[128];
  uint32        start_addr;
  s_fwmem_rwbuf fwrw;
  s_message*    msg_desc;


  msg_open( "sios_debug" );
  fwm_file = drv_mkd("/fwmem");
  start_addr = 0x00000000;
  while(true)
  {
//    akn = *((uint32*)0x60000308);
    prc_yield();
//    memcpy(hash_text, (uint8*)0x64000000, 128);  //FLASH
//    memcpy(hash_text, (uint8*)0x68000000, 128);  //NVRAM
//    memcpy(hash_text, (uint8*)0x80000000, 128);  //SDRAM
/*
    error = drv_ioctl(fwm_file, FWMEM_SET_OFFSET, &start_addr);
    fwrw.buffer = hash_text;
    fwrw.length = sizeof(hash_text);
    error = drv_ioctl(fwm_file, FWMEM_READ, &fwrw);
*/  
  }

  while(true)
  {
    error = msg_recv( &msg_desc, SEM_INFINITY );
    if( (error != OSE_OK)||(msg_desc == NULL) ) continue;
    if(msg_desc->length != sizeof(int32))
    {
      akn = -3;
      msg_send(msg_desc->from, &akn, sizeof(int32));  
      msg_free(msg_desc);      
      continue;
    }
    msg_from = msg_desc->from;
    cmd = *(int32*)msg_desc->data;
    msg_free(msg_desc);      
    switch (cmd)
    {
          //Получение результата:
          case 0xC1000001:
          {
        error = drv_ioctl(fwm_file, FWMEM_SET_OFFSET, &start_addr);
        fwrw.buffer = hash_text;
        fwrw.length = sizeof(hash_text);
        error = drv_ioctl(fwm_file, FWMEM_READ, &fwrw);
        akn = 0x0;
        msg_send(msg_from, &akn, sizeof(int32));
          }
          break;
      default:
      {
        akn = 0xF;
        msg_send(msg_from, &akn, sizeof(int32));
      }
    }
  }
}

// ---------------------------------------------------------------------------
int test_process_rx( void* arg )
{
  s_message* m;
  uint32 st, et;
  int32 traf[5];
  FILE* dout;
  
  dout = fopen( "/dev/dbgout", "wb" );
  
  msg_open( "speed_test_rx" );
  
  st = time_s();
  memset( &traf, 0, sizeof(traf) );
  while( true )
  {
    msg_recv( &m, SEM_INFINITY );
    et = time_s();
    traf[((m->from>>16)&0xf)-1] += m->length;
    msg_free( m );
    if( ( et - st ) >= 10 )
    {
      st = et;
      fprintf( dout, "speed:" );
      for( int i = 0; i < 5; i++ )
      {
        traf[i] <<= 3;
        fprintf( dout, " %d.%03d", traf[i] / 10000000, (traf[i] % 10000000)/10000 );
        traf[i] = 0;
      }
      fprintf( dout, "\n" );
    }
  }
  
  msg_close();
  
  fclose( dout );
}
// ---------------------------------------------------------------------------
int test_process_tx( void* arg )
{
  uint32 d_main;
  uint32 d_iface;
  uint32 d_comm0;
  uint32 d_comm1;
  uint32 d_comm2;
  #define L 4
  char buf[L];
  
  msg_open( "speed_test_tx" );
  
  d_main = msg_discover( "main", "speed_test_rx", SEM_INFINITY );
  d_iface = msg_discover( "iface", "speed_test_rx", SEM_INFINITY );
  d_comm0 = msg_discover( "comm0", "speed_test_rx", SEM_INFINITY );
  d_comm1 = msg_discover( "comm1", "speed_test_rx", SEM_INFINITY );
  d_comm2 = msg_discover( "comm2", "speed_test_rx", SEM_INFINITY );
  
  for( int32 i = 0; i < L; i++ ) buf[i] = i;
  
  while( true )
  {
    msg_send( d_main, buf, L );
    msg_send( d_iface, buf, L );
    msg_send( d_comm0, buf, L );
    msg_send( d_comm1, buf, L );
    msg_send( d_comm2, buf, L );
  }
  
  msg_close();
}
// ---------------------------------------------------------------------------
void dozu_test()
{
  #define VREG64( a )             (*(volatile uint64*)(a))    
  int32   exit, ok[3];
  uint64* data = (uint64*)0xA0000000;
  while(true)
  {  
    VREG64( 0xA0000000 ) = 0x0011223333221100;
    VREG64( 0xA0001000 ) = 0x0011223333221100;
    VREG64( 0xA0002000 ) = 0x0011223333221100;
    ok[0] = 0;
    ok[1] = 0;
    ok[2] = 0;
    while( true )
    {
          exit = 1;
      exit &= ok[0];
      exit &= ok[1];
      exit &= ok[2];
      if( exit == 1 )
      {
        asm(" nop");
        break;
      }
          if( VREG64( 0xA0000000 ) == 0x0033445555443300 )
        ok[0] = 1;
          if( VREG64( 0xA0001000 ) == 0x0033445555443300 )
        ok[1] = 1;
          if( VREG64( 0xA0002000 ) == 0x0033445555443300 )
        ok[2] = 1;
      asm(" nop");
    }
    asm(" nop");     
  }
}
// ---------------------------------------------------------------------------
int os_process(void* arg)
{
  FILE* dbg_out;
  s_usbhc_plug usbhc;
  mcbsp_context mcbsp_ctx;
  s_gpio_start_value gpio;
  int32 error;  
  uint32 d = drv_mkd( "/" );

  if( d == RES_VOID ) goto fail;
  drv_create( d, "dev", INOT_FOLDER );
  drv_create( d, "mnt", INOT_FOLDER );
  drv_select( d, "dev" );
  drv_create( d, "ipmp",INOT_FOLDER );
  drv_create( d, "net",INOT_FOLDER );
  drv_rmd( d );

  mcbsp_ctx.out_port      = MCBSP_PORT0;
  mcbsp_ctx.in_port1      = MCBSP_PORT1;
  mcbsp_ctx.in_port2      = PORT_UNUSED;
  mcbsp_ctx.mcbsp_cfg_in  = main_in_mcbspCfg;   
  mcbsp_ctx.mcbsp_cfg_out = main_out_mcbspCfg;
  mcbsp_ctx.edma_cfg_in   = main_in_edmaCfg;    
  mcbsp_ctx.edma_cfg_out  = main_out_edmaCfg;

  error = drv_dbgout_plug();
  dbg_out = fopen( "/dev/dbgout", "w" );

  gpio.reg_gpen  = 0x06f0;
  gpio.reg_gpdir = 0x0600;
  gpio.reg_gpval = 0x0000;    
  fprintf(dbg_out,"01 - Инициализация GPIO\n");
  if( drv_gpio_plug( &gpio ) != OSE_OK )
  {
    REG_OSTS0 |= OSTS0_GPIO_FAIL;
  }
  else
  {
    // Reset PLIS
    s_gpio_load_plis lplis;
    d = drv_mkd( "/dev/gpio" );
    memset( &lplis, 0, sizeof(lplis) );
    drv_ioctl( d, GPIO_RESET_PLIS, &lplis );
    drv_rmd( d );
  }

  fprintf(dbg_out,"02 - Инициализация драйвера спарки\n");
  syn_init( 20, 60*60000, NULL );
        
  // -- Initialize extensions ------------------------------------------------
  fprintf(dbg_out,"03 - Инициализация внутренней флэш\n");
  error = drv_fwmem_plug("/fwmem", 0x64000000, &fwmem_s29al032dxxxxx04_gpio );
  if(error) REG_OSTS0 |= OSTS0_FWMEM_FAIL;  

  fprintf(dbg_out,"04 - Инициализация MCBSP\n");
  error = drv_mcbsp_plug(&mcbsp_ctx);
  if(error) REG_OSTS0 |= OSTS0_MCBSP_FAIL;

  fprintf(dbg_out,"05 - Инициализация межпроцессорного обмена сообщениями(IPMP MCBSP) c IFACE\n");
  error = drv_ipmp_mcbsp_plug( "/dev/ipmp/ipmp0" );
  if(error) REG_OSTS0 |= OSTS0_MCBSP_FAIL;

  fprintf(dbg_out,"06 - Инициализация журнала syslog\n");
  syslog_init();

  usbhc.isp.gpio_number = 8;
  usbhc.nec.gpio_number = 7;    

  fprintf(dbg_out,"07 - Инициализация контроллера USB\n");
  error = drv_usbhc_plug( &usbhc, &usbhc_plug );
  if(error) REG_OSTS0 |= OSTS0_USBHC_FAIL;
  else
  {
    sleep_s(2);
    error = drv_usb_plug();
    if(error) REG_OSTS0 |= OSTS0_USB_FAIL;
    else
    {
      s_usb_driver_context    msd;
      msd.device_class = USB_DEVICE_CLASS_STORAGE;
      msd.open_func    = &usbms_open;
      msd.close_func   = &usbms_close;
      msd.read_func    = &usbms_read;
      msd.write_func   = &usbms_write;
      msd.ioctl_func   = &usbms_ioctl;                    
      uint32 d = drv_mkd("/dev/usb/");
      drv_ioctl(d, USB_ADD_DEVICE_CLASS, &msd);
      drv_rmd(d);
    }
  }
  fprintf(dbg_out,"08 - Инициализация внутренней USB-флеш...\n");
  if( wait_msd0_flash() == false ) REG_OSTS0 |= OSTS0_MSD0_FAIL;

  dev_assignLetter(usbhc_plug);
  drv_vfat_trigger_plug();

  fprintf(dbg_out,"09 - Загрузка ПЛИС ДОЗУ и инициализация межпроцессорного обмена сообщениями(IPMP DOZU) с COMM0\n");
  error = drv_ipmp_dsp16_plug( "/dev/ipmp/ipmp1", 0 );
  if(error) REG_OSTS0 |= OSTS0_MCBSP_FAIL;
  fprintf(dbg_out,"10 - Инициализация межпроцессорного обмена сообщениями(IPMP DOZU) с COMM1\n");
  error = drv_ipmp_dsp16_plug( "/dev/ipmp/ipmp2", 1 );
  if(error) REG_OSTS0 |= OSTS0_MCBSP_FAIL;
  fprintf(dbg_out,"11 - Инициализация межпроцессорного обмена сообщениями(IPMP DOZU) с COMM2\n");
  error = drv_ipmp_dsp16_plug( "/dev/ipmp/ipmp3", 2 );
  if(error) REG_OSTS0 |= OSTS0_MCBSP_FAIL;

  fprintf(dbg_out,"12 - Инициализация энергонезависимого ОЗУ(NVRAM)\n");
  if( ( error = drv_nvram_plug("/dev/nvram") ) != OSE_OK )
  {
    if(error == OSE_DATA_TEST_ERROR)
      REG_OSTS0 |= OSTS0_NVRAM_FAIL1;
    else
      REG_OSTS0 |= OSTS0_NVRAM_FAIL2;
  }

  fprintf(dbg_out,"13 - Инициализация стека TCP\\IP\n");
  socket_init(8);

  fprintf(dbg_out,"14 - Начало системного обмена сообщениями\n");
  msg_start( 2, 8 );
    
//    dozu_test();
  //BEGIN: TEST FLASH
/*
  #define READ_SIZE  256
  uint32 file = drv_mkd("/fwmem");
  uint8  buf[3][READ_SIZE];
  s_fwmem_rwbuf  fwrw;
  for(uint32 offset=0; offset<0x400000; offset+=READ_SIZE )
  {
    error = drv_ioctl(file, FWMEM_SET_OFFSET, &offset);
    fwrw.buffer = &buf[0];
    fwrw.length = READ_SIZE;
    error = drv_ioctl(file, FWMEM_READ, &fwrw);
    for(uint32 i=0; i<1000; i++)
    {
      error = drv_ioctl(file, FWMEM_SET_OFFSET, &offset);
      fwrw.buffer = &buf[1];
      fwrw.length = READ_SIZE;
      error = drv_ioctl(file, FWMEM_READ, &fwrw);
      memcpy(&buf[2], &buf[1], READ_SIZE);
	  if( syn_data(&buf[1], READ_SIZE, 0) != OSE_OK)
	    asm(" nop");
      if( memcmp(&buf[0], &buf[1], READ_SIZE) != 0x0)
        asm(" nop");
    }
  }
*/
  //END: TEST FLASH

  s_prc_attr pattr;
  memset( &pattr, 0, sizeof(pattr) );
  pattr.stack = 4096;
  fprintf(dbg_out,"15 - Создание основного процесса СИОС\n");
  prc_create( &os_main, NULL, 0, &pattr );

//    prc_create( &sios_debug_process, NULL, 0, &pattr );
//    sleep_s( 10 );
//    prc_create( &test_process_rx, NULL, 0, &pattr );
//    prc_create( &test_process_tx, NULL, 0, &pattr );

    fprintf(dbg_out,"16 - Система запущена!!!\n");
    fclose(dbg_out);
    prc_system();

fail:

    while( true )
        asm( " nop" );
}

