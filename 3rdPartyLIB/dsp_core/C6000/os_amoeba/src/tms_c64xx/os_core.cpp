// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp866
// !: d: Модуль содержит реализацию функций управления процессами, менеджер
// !: d: памяти и менеджер хипа.
// !: [os_core.cpp]
// ---------------------------------------------------------------------------
#define SYSCALL_DIRECT
#include <os.h>
// ---------------------------------------------------------------------------

#pragma DATA_ALIGN( 8 );
s_os_register v_os_process_null_register;
#pragma DATA_ALIGN( 8 );
s_os_register v_os_irctx_nmi;
#pragma DATA_ALIGN( 8 );
s_os_register v_os_irctx;

s_os_process_context* v_os_current_process;
s_os_process_context* v_os_process_ring;
s_os_process_context v_os_process_null_context;
uint32 v_os_process_count;
uint32 v_os_core_call;
s_os_heap* v_os_core_heap;
uint16 v_os_swto_pid;
void* __os_syscall_table__[SYSCALL__COUNT__];
int32 v_os_errno;

extern void* __bss__;
extern int os_process( void* args );
extern void os_config();

static s_os_mem_block* v_page[4];

// ---------------------------------------------------------------------------
int os_idle_process( void* args )
{
  while( true )
  {
    // TODO: calculating load
  }
}
/*****************************************************************************
Syntax:  void os_segfault()    	    
Remarks: Обработка Исключений.
OSSF_SEGMENTATION_FAULT -исключение, вызванное искажением указателя на блок 
динамической или попыткой доступа в несуществующее адресное пространство;

OSSF_STACK_OVERFLOW - исключение, вызванное переполнением стека процесса

OSSF_BAD_DESCRIPTOR - исключение, вызванное обращением к ресурсу по "некорректному" 
идентификатору ресурса;
			    
OSSF_UNIMPLEMENTED_SYSCALL - исключение, вызванное попыткой вызвать системную функцию,
которая в данный момент не определена; 

OSSF_PROTECTION_FAULT - исключение, вызванное попыткой
 несанкционированного доступа к ресурсу ОС.
*******************************************************************************/
void os_segfault()
{
  switch( v_os_current_process->sfault_code )
  {
    case OSSF_SEGMENTATION_FAULT:
    {
      while( true )
        asm( " nop" );
    }

    case OSSF_STACK_OVERFLOW:
    {
      while( true )
        asm( " nop" );
    }

    case OSSF_BAD_DESCRIPTOR:
    {
      while( true )
        asm( " nop" );
    }

    case OSSF_UNIMPLEMENTED_SYSCALL:
    {
      while( true )
        asm( " nop" );
    }

    case OSSF_PROTECTION_FAULT:
    {
      while( true )
        asm( " nop" );
    }

    default: // x_O probably someone break the system memory
    {
      int32 a = 0;
      while( a )
        asm( " nop" );
    }
  }

  return;
}
// ---------------------------------------------------------------------------
void os_process_switcher()
{
  uint32 i;
  bool albreak;
  s_os_semaphore* csem;
  s_os_locker* clocker;
  uint32 cpsp, cpr;

  // Save <errno> of current process
  v_os_current_process->errno = v_os_errno;

  v_os_core_call = 1;

  // Update time
  os_time_update();

  if( v_os_swto_pid != 0xffff )
  {
    albreak = false;
    for( i = 0; i < v_os_process_count; i++ )
    {
      v_os_current_process = v_os_current_process->next;
      if( v_os_current_process->sfault_code != 0 ) os_segfault();
      if( v_os_current_process->id == v_os_swto_pid )
      {
        if( v_os_current_process->locker.s != RES_VOID )
        {
          clocker = &v_os_current_process->locker;
          if( clocker->state == SEM_DESTROYED )
          {
            clocker->prev = NULL;
            clocker->next = NULL;
            clocker->s = RES_VOID;
            clocker->unlock_at = 0ull;
            v_os_current_process->pcnt = v_os_current_process->peff;
            albreak = true;
            break;
          }
          csem = v_os_semaphore_list[clocker->s&RES_I_MASK];
          if( csem->v <= csem->w )
          {
            if( clocker->unlock_at == 0 ) break;
            if( os_time_core_n() >= clocker->unlock_at )
            {
              clocker->state = OSE_TIMEOUT;
              csem->w++;
              csem->v++;
              clocker->unlock_at = 0ull;
              if( clocker->prev ) clocker->prev->next = clocker->next;
              if( clocker->next ) clocker->next->prev = clocker->prev;
              if( clocker == csem->first ) csem->first = clocker->next;
              clocker->s = RES_VOID;
              clocker->prev = NULL;
              clocker->next = NULL;
              v_os_current_process->pcnt = v_os_current_process->peff;
              albreak = true;
            }
            break;
          }
          if( clocker != csem->first ) break;
          clocker->state = SEM_OK;
          csem->w++;
          clocker->unlock_at = 0ull;
          csem->first = clocker->next;
          if( csem->first ) csem->first->prev = NULL;
          clocker->s = RES_VOID;
          clocker->prev = NULL;
          clocker->next = NULL;
          v_os_current_process->pcnt = v_os_current_process->peff;
        }
        albreak = true;
        break;
      }
    }
    v_os_swto_pid = 0xffff;
    if( albreak ) goto l_psw_end;
  }

  // Switch to active task
  while( true )
  {
    albreak = true;
    for( i = 0; i < v_os_process_count; i++ )
    {
      v_os_current_process = v_os_current_process->next;
      if( v_os_current_process->sfault_code != 0 ) os_segfault();
      if( ( v_os_current_process->pflags & PRIORITY_MASK ) == PRIORITY_IDLE ) continue;
      // If process locked
      if( v_os_current_process->locker.s != RES_VOID )
      {
        clocker = &v_os_current_process->locker;
        if( clocker->state == SEM_DESTROYED )
        {
          clocker->prev = NULL;
          clocker->next = NULL;
          clocker->s = RES_VOID;
          clocker->unlock_at = 0ull;
          v_os_current_process->pcnt = v_os_current_process->peff;
          albreak = true;
          break;
        }
        csem = v_os_semaphore_list[clocker->s&RES_I_MASK];
        if( csem->v <= csem->w )
        {
          if( clocker->unlock_at == 0 ) continue;
          if( os_time_core_n() >= clocker->unlock_at )
          {
            clocker->state = OSE_TIMEOUT;
            csem->w++;
            csem->v++;
            clocker->unlock_at = 0ull;
            if( clocker->prev ) clocker->prev->next = clocker->next;
            if( clocker->next ) clocker->next->prev = clocker->prev;
            if( clocker == csem->first ) csem->first = clocker->next;
            clocker->s = RES_VOID;
            clocker->prev = NULL;
            clocker->next = NULL;
            v_os_current_process->pcnt = v_os_current_process->peff;
            albreak = true;
            break;
          }
          continue;
        }
        if( clocker != csem->first ) continue;
        clocker->state = SEM_OK;
        csem->w++;
        clocker->unlock_at = 0ull;
        csem->first = clocker->next;
        if( csem->first ) csem->first->prev = NULL;
        clocker->s = RES_VOID;
        clocker->prev = NULL;
        clocker->next = NULL;
        v_os_current_process->pcnt = v_os_current_process->peff;
        albreak = true;
        break;
      }
      else
      {
        albreak = false;
      }
      // If process have low priority it must skip some loops
      if( v_os_current_process->pcnt > 0 )
      {
        v_os_current_process->pcnt--;
        continue;
      }
      // Update priority counter and run process
      v_os_current_process->pcnt = v_os_current_process->peff;
      albreak = true;
      break;
    }
    if( albreak ) break;
  }

  // Switch to idle task
  if( i == v_os_process_count )
  {
    for( i = 0; i < v_os_process_count; i++ )
    {
      v_os_current_process = v_os_current_process->next;
      if( v_os_current_process->sfault_code != 0 ) os_segfault();
      if( ( v_os_current_process->pflags & PRIORITY_MASK ) == PRIORITY_IDLE ) break;
    }
  }

l_psw_end:

  // Check stack
  cpsp = v_os_current_process->reg->b15;
  cpr = (uint32)v_os_current_process->stack + sizeof(s_os_mem_block);
  if( ( cpsp < cpr ) || ( cpsp >= ( cpr + v_os_current_process->stack->length ) ) )
  {
    v_os_current_process->sfault_code = OSSF_STACK_OVERFLOW;
    os_segfault();
  }

  v_os_core_call = 0;

  // Restore errno of current process
  v_os_errno = v_os_current_process->errno;
  // Clear quant counter for current process
  #if defined(CHIP_6412) || defined(CHIP_6416)
 	 REG_CNT0 = 0;
  #endif
 
  #if defined(CHIP_6457)
 	 REG_CNTLO0 = 0;
  #endif

  asm( " b    .s2   l_swt0     " );
  asm( " mvc  .s2   csr, b0    " );
  asm( " or   .s2   b0, 2, b0  " );
  asm( " mvc  .s2   b0, csr    " );
  asm( " nop        1          " );
  asm( " nop        1          " );
  asm( "l_swt0:                " );
}
// ---------------------------------------------------------------------------
void os_process_switch_to( uint16 pid )
{
  v_os_swto_pid = pid;
  prc_yield();
}
// ---------------------------------------------------------------------------
int32 os_process_create( int (*prc_func)(void*), void* arg, int32 arg_len, s_prc_attr* attr )
{
  register uint32 is;
  s_os_process_context* nprocess;
  s_os_process_context* tidp;
  int32 i, k;
  bool afla;
  uint32 tcc;
  int32 stack_len = attr->stack;
  int32 heap_len = attr->heap;
  s_os_register* npreg;
  uint32 mpage_number;

  if( prc_func == NULL ) return OSE_NULL_PARAM;
  if( ( arg != NULL ) && ( arg_len == 0 ) ) return OSE_BAD_PARAM;
  if( stack_len < 256 ) stack_len = 256;

  // Try to allocate memory for process context
  nprocess = (s_os_process_context*)os_heap_alloc( NULL, sizeof(s_os_process_context), HEAP_ALIGN_4 );
  if( nprocess == NULL ) return OSE_NO_MEMORY;
  memset( nprocess, 0, sizeof(s_os_process_context) );

  // Create join semaphore
  if( ( nprocess->join_sem = sem_alloc( 0, NULL ) ) == RES_VOID ) return OSE_CANT_CREATE_SEM;

  // Try to allocate memory for process registers context
  nprocess->reg = (s_os_register*)os_heap_alloc( NULL, sizeof(s_os_register), HEAP_ALIGN_8 );
  if( nprocess->reg == NULL )
  {
    os_heap_free( NULL, nprocess );
    return OSE_NO_MEMORY;
  }
  npreg = nprocess->reg;

  // Try to allocate memory for process stack
  tcc = v_os_core_call;
  v_os_core_call = 1;
  if( REG_OSCFG0 & OSCFG0_STACK_PAGEU ) mpage_number = REG_OSCFG0 & OSCFG0_STACK_PAGEM; else mpage_number = MPAGE_ALL;
  nprocess->stack = os_mem_alloc( stack_len, mpage_number );
  v_os_core_call = tcc;
  if( nprocess->stack == NULL )
  {
    os_heap_free( NULL, npreg );
    os_heap_free( NULL, nprocess );
    return OSE_CANT_CREATE_STACK;
  }
  nprocess->stack->flags |= MEM_READ | MEM_WRITE;

  // Modify process heap length
  if( arg_len > 0 )
  {
    if( heap_len < arg_len )
    {
      heap_len = ( ( arg_len >> 8 ) + 1 ) << 8;
    }
  }

  // Try to allocate memory for process heap
  if( heap_len > 0 )
  {
    if( REG_OSCFG0 & OSCFG0_HEAP_PAGEU ) mpage_number = ( REG_OSCFG0 & OSCFG0_HEAP_PAGEM ) >> 3; else mpage_number = MPAGE_ALL;
    s_os_mem_block* nhblock = os_mem_alloc( heap_len + sizeof(s_os_heap), mpage_number );
    if( nhblock == NULL )
    {
      os_mem_free( nprocess->stack );
      os_heap_free( NULL, npreg );
      os_heap_free( NULL, nprocess );
      return OSE_CANT_CREATE_HEAP;
    }
    s_os_heap* nhheap = (s_os_heap*)( (char*)nhblock + sizeof(s_os_mem_block) );
    memset( nhheap, 0, sizeof(s_os_heap) );
    nhheap->block = nhblock;
    os_heap_init( nhheap );
    nhheap->block->flags |= MEM_READ | MEM_WRITE;
    nprocess->heap = nhheap;
  }

  // Copy argument into a process memory
  if( arg_len == 0 )
  {
    nprocess->arg = NULL;
    nprocess->arglen = 0;
  }
  else
  {
    nprocess->arg = os_heap_alloc( nprocess->heap, arg_len, HEAP_ALIGN_4 );
    nprocess->arglen = arg_len;
    memcpy( nprocess->arg, arg, arg_len );
  }
  
  // Set start process function (it's for debug, may be deleted):
//  nprocess->func = prc_func;

  // Initialize process context
  memset( npreg, 0, sizeof(s_os_register) );
  
  // Load exit function pointer into B3 register
  if( attr->exit_vector ) npreg->b3 = (uint32)attr->exit_vector; else npreg->b3 = (uint32)&os_process_exit;
  // Load BSS pointer into B14 register
  if( attr->bss ) npreg->b14 = attr->bss; else npreg->b14 = (uint32)&__bss__;
  // Load process argument pointer into A4 register
  npreg->a4 = (uint32)nprocess->arg;
  // Load stack pointer into B15 register
  npreg->b15 = (uint32)nprocess->stack + sizeof(s_os_mem_block) + nprocess->stack->length - 8;
  // Push RETURN POINT into process stack
  uint32& reg_sp = npreg->b15;
  reg_sp -= 4; (*(uint32*)reg_sp) = (uint32)prc_func;
  // Push B13 value into process stack
  reg_sp -= 4; (*(uint32*)reg_sp) = 0;
  // Push ZERO value into process stack
  reg_sp -= 4; (*(uint32*)reg_sp) = 0;
  // Push ZERO value into process stack
  reg_sp -= 4; (*(uint32*)reg_sp) = 0;

  nprocess->pflags = (uint16)attr->priority & PRIORITY_MASK;
  nprocess->pcnt = 0;
  nprocess->locker.p = nprocess;
  nprocess->msg.p = nprocess;

  is = int_disable();

  // Allocate process id
  nprocess->id = 1;
  tidp = v_os_process_ring;
  while( true )
  {
    afla = true;
    for( i = 0; i < v_os_process_count; i++, tidp = tidp->next )
    {
      if( tidp->id == nprocess->id )
      {
        afla = false;
        nprocess->id++;
        break;
      }
    }
    if( afla ) break;
  }

  // Insert new process into the process ring
  if( v_os_process_ring == NULL )
  {
    v_os_process_ring = nprocess;
    nprocess->next = nprocess;
    nprocess->prev = nprocess;
  }
  else
  {
    nprocess->prev = v_os_process_ring->prev;
    nprocess->next = v_os_process_ring;
    v_os_process_ring->prev->next = nprocess;
    v_os_process_ring->prev = nprocess;
  }
  v_os_process_count++;

  // Mark all allocated memory blocks by process id
  if( nprocess->heap ) nprocess->heap->block->pid = nprocess->id;
  nprocess->stack->pid = nprocess->id;
  res_chown( nprocess->join_sem, nprocess->id );

  // Calculate new effective priority
  tidp = v_os_process_ring;
  for( k = PRIORITY_MASK, i = 0; i < v_os_process_count; i++, tidp = tidp->next )
  {
    if( ( tidp->pflags & PRIORITY_MASK ) == PRIORITY_IDLE ) continue;
    if( k > ( tidp->pflags & PRIORITY_MASK ) ) k = tidp->pflags & PRIORITY_MASK;
  }
  for( i = 0; i < v_os_process_count; i++, tidp = tidp->next )
  {
    if( ( tidp->pflags & PRIORITY_MASK ) == PRIORITY_IDLE ) continue;
    tidp->peff = ( tidp->pflags & PRIORITY_MASK ) - k;
  }

  int_enable( is );

  #ifdef OS_SUPPORT_SYNCHRONIZATION
	  int32 res = syn_open( nprocess->id );
	  if(res != OSE_OK)
	    return res;
  #endif

  return (int32)nprocess->id;
}
// ---------------------------------------------------------------------------
void os_process_exit()
{
  register uint32 is;

  // Terminate message exchange
  os_message_cleanup();
  // Release all driver descriptors and contexts owned by process
  os_driver_cleanup();

  // Lock process switching
  #ifdef OS_SUPPORT_SYNCHRONIZATION
  syn_close( v_os_current_process->id );
  #endif
  
  is = int_disable();

  // Unlink current process from process ring
  v_os_process_count--;
  v_os_current_process->prev->next = v_os_current_process->next;
  v_os_current_process->next->prev = v_os_current_process->prev;
  v_os_process_null_context.next = v_os_current_process->next;

  // Free all semaphores owned by process
  os_semaphore_cleanup();
  // Free all interrupts owned by process
  os_interrupt_cleanup();
  // Free all timers and periodic events owned by process
  os_time_cleanup();
  // Free all memory owned by process
  os_mem_free_by_pid( v_os_current_process->id );

  // Remove process context
  os_heap_free( NULL, v_os_current_process->reg );
  os_heap_free( NULL, v_os_current_process );

  // Unlock process switching and switch to next process in ring
  v_os_current_process = &v_os_process_null_context;
  asm( "        .global         _OS_STACK_END           " );
  asm( "        mvkl    .s2     _OS_STACK_END, b15      " );
  asm( "        mvkh    .s2     _OS_STACK_END, b15      " );
  asm( "        addk    .s2     -32, b15                " );

  int_enable( is );
  
  prc_yield();
}
// ---------------------------------------------------------------------------
int32 os_process_set_priority( int32 p )
{
  register uint32 is;
  s_os_process_context* tidp;
  int32 k, i;

  is = int_disable();

  v_os_current_process->pflags = ( v_os_current_process->pflags & ( PRIORITY_MASK ^ 0xffff ) ) | ( (uint16)p & PRIORITY_MASK );

  tidp = v_os_process_ring;
  for( k = PRIORITY_MASK, i = 0; i < v_os_process_count; i++, tidp = tidp->next )
  {
    if( ( tidp->pflags & PRIORITY_MASK ) == PRIORITY_IDLE ) continue;
    if( k > ( tidp->pflags & PRIORITY_MASK ) ) k = tidp->pflags & PRIORITY_MASK;
  }
  for( i = 0; i < v_os_process_count; i++, tidp = tidp->next )
  {
    if( ( tidp->pflags & PRIORITY_MASK ) == PRIORITY_IDLE ) continue;
    tidp->peff = ( tidp->pflags & PRIORITY_MASK ) - k;
  }

  int_enable( is );

  return OSE_OK;
}
// ---------------------------------------------------------------------------
uint16 os_process_id()
{
  return v_os_current_process->id;
}
// ---------------------------------------------------------------------------
uint16 os_process_priority()
{
  return v_os_current_process->pflags & PRIORITY_MASK;
}
// ---------------------------------------------------------------------------
void* os_process_arg()
{
  return v_os_current_process->arg;
}
// ---------------------------------------------------------------------------
int32 os_process_arg_length()
{
  return v_os_current_process->arglen;
}
// ---------------------------------------------------------------------------
s_os_heap* os_process_heap()
{
  return v_os_current_process->heap;
}
// ---------------------------------------------------------------------------
void os_process_set_flags( uint16 f )
{
  register uint32 is = int_disable();
  v_os_current_process->pflags = ( v_os_current_process->pflags & PRIORITY_MASK ) | ( f & PFLAG_MASK );
  int_enable( is );
}
// ---------------------------------------------------------------------------
uint16 os_process_flags()
{
  return v_os_current_process->pflags & PFLAG_MASK;
}
// ---------------------------------------------------------------------------
void os_process_system()
{
  // TODO: relink to system processes ring
  while( true ) prc_yield();
}
// ---------------------------------------------------------------------------
int32 os_process_join( uint16 pid )
{
  uint32 jsem = RES_VOID;
  register s_os_process_context* cprc;
  register uint32 is = int_disable();
  cprc = v_os_current_process;
  for( int i = 0; i < v_os_process_count; i++, cprc = cprc->next )
  {
    if( cprc->id == pid )
    {
      jsem = cprc->join_sem;
      break;
    }
  }
  int_enable( is );
  if( jsem == RES_VOID ) return OSE_NO_PROCESS;
  sem_lock( jsem, SEM_INFINITY );
  return OSE_OK;
}
// ---------------------------------------------------------------------------
s_os_mem_block* os_mem_alloc( int32 length, uint32 pagenum )
{
  s_os_mem_block* cblock;
  s_os_mem_block* rblock;
  int32 i, fi, ti;
  int32 nlength;
  register uint32 is;

  if( pagenum == MPAGE_ALL )
  {
    fi = 0;
    ti = 3;
  }
  else if( pagenum > 3 )
  {
    return NULL;
  }
  else
  {
    fi = ti = (int32)pagenum;
  }
  if( length <= 0 ) return NULL;

  if( length & 15 ) nlength = ( length & 0xfffffff0 ) + 16; else nlength = length;

  // Disable process switching
  is = int_disable();

  // Try allocate memory on all memory pages
  for( i = fi; i <= ti; i++ )
  {
    cblock = v_page[i];
    if( cblock == NULL ) continue;

    while( cblock )
    {
      if( ( cblock->flags & MEM_USED ) == 0 )
      {
        if( cblock->length >= nlength )
        {
          if( cblock->length > nlength  )
          {
            rblock = (s_os_mem_block*)( (uint32)cblock + nlength + 16 );
            rblock->next = cblock->next;
            rblock->prev = cblock;
            rblock->length = cblock->length - nlength - 16;
            rblock->flags = 0;
            rblock->pid = 0;
            if( rblock->next ) rblock->next->prev = rblock;
            cblock->next = rblock;
            cblock->length = nlength;
          }
          cblock->flags = MEM_USED;
          if( v_os_core_call ) cblock->pid = 0; else cblock->pid = v_os_current_process->id;
          // Restore process switching
          int_enable( is );
          return cblock;
        }
      }

      cblock = cblock->next;
    }

  }

  // Restore process switching
  int_enable( is );  

  return NULL;
}
// ---------------------------------------------------------------------------
void os_mem_free( s_os_mem_block* block )
{
  register uint32 is;
  bool left = false;
  bool right = false;
  s_os_mem_block* pblock;
  s_os_mem_block* nblock;

  if( block == NULL ) return;

  is = int_disable();

  // todo: insert <page fault> check

  pblock = block->prev;
  nblock = block->next;

  if( pblock ) if( ( pblock->flags & MEM_USED ) == 0 ) left = true;
  if( nblock ) if( ( nblock->flags & MEM_USED ) == 0 ) right = true;

  if( left && right )
  {
    pblock->length += 32 + block->length + nblock->length;
    pblock->next = nblock->next;
    if( nblock->next ) nblock->next->prev = pblock;
  }
  else if( left )
  {
    pblock->length += 16 + block->length;
    pblock->next = nblock;
    if( nblock ) nblock->prev = pblock;
  }
  else if( right )
  {
    block->length += 16 + nblock->length;
    block->next = nblock->next;
    if( nblock->next ) nblock->next->prev = block;
    block->pid = 0;
    block->flags = 0;
  }
  else
  {
    block->pid = 0;
    block->flags = 0;
  }

  int_enable( is );
}
/*****************************************************************************
Syntax:  void os_mem_free_by_pid( uint16 pid ) 	    
Remarks:			    
*******************************************************************************/
void os_mem_free_by_pid( uint16 pid )
{
  s_os_mem_block* page[4];
  s_os_mem_block* cblock;
  int32 i;
  register uint32 is;

  page[0] = (s_os_mem_block*)&OS_MPAGE0_BEGIN;
  page[1] = (s_os_mem_block*)&OS_MPAGE1_BEGIN;
 
 //SKD PAtch no OS_MPAGE2 and OS_MPAGE3
 //page[2] = (s_os_mem_block*)&OS_MPAGE2_BEGIN;
 //page[3] = (s_os_mem_block*)&OS_MPAGE3_BEGIN;

  is = int_disable();

  //skd patch 2 page block
  //for( i = 0; i < 4; i++ )
  for( i = 0; i < 2; i++ )
  {
    cblock = page[i];
    if( cblock == NULL ) continue;
    while( cblock )
    {
      if( ( cblock->flags & MEM_USED ) && ( cblock->pid == pid ) )
      {
        os_mem_free( cblock );
        cblock = page[i];
        continue;
      }
      cblock = cblock->next;
    }
  }

  int_enable( is );
}
/*****************************************************************************
Syntax:  void os_mem_stat( s_os_mem_stat* stat ) 	    
Remarks:			    
*******************************************************************************/
void os_mem_stat( s_os_mem_stat* stat )
{
  s_os_mem_block* page_end[4];
  s_os_mem_block* cblock;
  int32 i;
  register uint32 is;

  if( stat == NULL ) return;
  memset( stat, 0, sizeof(s_os_mem_stat) );

  page_end[0] = (s_os_mem_block*)&OS_MPAGE0_END;  //Internal RAM
  page_end[1] = (s_os_mem_block*)&OS_MPAGE1_END;  //External SDRAM
  
  //skd patch no MPAGE2 and MPAGE3
 //page_end[2] = (s_os_mem_block*)&OS_MPAGE2_END;
 //page_end[3] = (s_os_mem_block*)&OS_MPAGE3_END;

  is = int_disable();
  //for( i = 0; i < 4; i++ )
  for( i = 0; i < 2; i++ )
  {
    cblock = v_page[i];
    if( cblock == NULL ) continue;

    stat->total += (uint32)page_end[i] - (uint32)v_page[i];
    
    while( cblock )
    {
      stat->c_desc++;
      if( cblock->flags & MEM_USED )
      {
        stat->used += cblock->length;
        if( cblock->length < 64 ) stat->c_16_64++;
        else if( cblock->length < 256 ) stat->c_64_256++;
        else if( cblock->length < 1024 ) stat->c_256_1k++;
        else if( cblock->length < 4096 ) stat->c_1k_4k++;
        else if( cblock->length < 16384 ) stat->c_4k_16k++;
        else if( cblock->length < 65536 ) stat->c_16k_64k++;
        else if( cblock->length < 262144 ) stat->c_64k_256k++;
        else if( cblock->length < 1048576 ) stat->c_256k_1m++;
        else stat->c_1m_inf++;
      }
      else
      {
        stat->free += cblock->length;
      }

      cblock = cblock->next;
    }
  }

  int_enable( is );
}
// ---------------------------------------------------------------------------
void* os_mem_ptr( s_os_mem_block* block )
{
  return (void*)( (char*)block + sizeof(s_os_mem_block) );
}
// ---------------------------------------------------------------------------
void os_heap_init( s_os_heap* heap )
{
  uint32* heap_begin;
  if( heap == NULL ) return;

  // Start position for first free block finding
  heap_begin = (uint32*)( (uint32)heap + sizeof(s_os_heap) );
  heap_begin[0] = (uint32)heap_begin + 4;
  
  // One free block in heap
  heap_begin[1] = heap->block->length - sizeof(s_os_heap) - 12;
  
  // Heap terminator
  heap_begin = (uint32*)( (uint32)heap->block + heap->block->length + sizeof(s_os_mem_block) - 4 );
  heap_begin[0] = 0xffffffff;
}
// ---------------------------------------------------------------------------
void* os_heap_alloc( s_os_heap* heap, int32 size, int32 align )
{
  uint32* blast;
  uint32* bptr;
  uint32 b;
  uint32 blen;
  register uint32 is;
  uint32 nhlen;
  bool sysheap = false;

  if( ( (uint32)size & 0xc0000000ul ) || ( ( (uint32)size & 0x3fffffff ) == 0 ) ) return NULL;

  if( ( heap == NULL ) || ( heap == v_os_core_heap ) )
  {
    is = int_disable();
    heap = v_os_core_heap;
    sysheap = true;
  }

alloc_again:

  while( heap )
  {
    blast = (uint32*)( (uint32)heap + sizeof(s_os_heap) );
    bptr = (uint32*)(*blast);
    b = (*bptr);
    
    if( align == HEAP_ALIGN_8 )
    {
      if( size & 7 ) size = ( ( size >> 3 ) + 1 ) << 3;
    }
    else
    {
      if( size & 3 ) size = ( ( size >> 2 ) + 1 ) << 2;
    }
    
    while( true )
    {
      if( b == HEAP_END ) break;
      blen = b & HEAP_SIZE_MASK;
      
      if( ( b & HEAP_USED ) == 0 )
      {
        if( align == HEAP_ALIGN_8 )
        {
          if( ( (uint32)bptr & 7 ) == 4 )
          {
            if( blen >= size )
            {
              bptr[0] = HEAP_USED | size;
              if( blen != size ) (*(uint32*)( (uint32)bptr + 4 + size )) = blen - size - 4;
              if( (*blast) == (uint32)bptr ) (*blast) = (uint32)bptr + 4 + size;
              if( sysheap ) int_enable( is );
              return (void*)( (uint32)bptr + 4 );
            }
          }
          else
          {
            if( blen >= ( size + 4 ) )
            {
              bptr[0] = HEAP_USED | HEAP_ALIGN;
              bptr[1] = HEAP_USED | HEAP_ALIGN | size;
              if( blen != ( size + 4 ) ) (*(uint32*)( (uint32)bptr + 8 + size )) = blen - size - 8;
              if( (*blast) == (uint32)bptr ) (*blast) = (uint32)bptr + 8 + size;
              if( sysheap ) int_enable( is );
              return (void*)( (uint32)bptr + 8 );
            }
          }
        }
        else
        {
          if( blen >= size )
          {
            bptr[0] = HEAP_USED | size;
            if( blen != size ) (*(uint32*)( (uint32)bptr + 4 + size ) ) = blen - size - 4;
            if( (*blast) == (uint32)bptr ) (*blast) = (uint32)bptr + 4 + size;
            if( sysheap ) int_enable( is );
            return (void*)( (uint32)bptr + 4 );
          }
        }
      }

      bptr = (uint32*)( (uint32)bptr + 4 + blen );
      b = (*bptr);
    }

    heap = heap->next;
  }

  nhlen = (uint32)size + 64;
  if( nhlen & 4095 ) nhlen = ( nhlen & 0xfffff000 ) + 4096;
  if( sysheap ) { b = v_os_core_call; v_os_core_call = 1; }
  heap = os_heap_create( nhlen );
  if( sysheap ) v_os_core_call = b;
  if( heap != NULL ) goto alloc_again;

  if( sysheap ) int_enable( is );

  return NULL;
}
// ---------------------------------------------------------------------------
void os_heap_free( s_os_heap* heap, void* ptr )
{
  uint32 b;
  uint32* blast;
  uint32* bptr;
  uint32* bptr_prev;
  uint32* bptr_next;
  uint32 blen;
  bool left = false;
  bool right = false;
  register uint32 is;
  bool sysheap = false;

  if( ptr == NULL ) return;

  if( ( heap == NULL ) || ( heap == v_os_core_heap ) )
  {
    is = int_disable();
    heap = v_os_core_heap;
    sysheap = true;
  }

  while( heap )
  {
    if( ( (uint32)ptr >= ( (uint32)heap + sizeof(s_os_heap) ) ) && ( (uint32)ptr < ( (uint32)heap->block + heap->block->length + sizeof(s_os_mem_block) ) ) )
    {
      bptr_prev = NULL;
      blast = (uint32*)( (uint32)heap + sizeof(s_os_heap) );
      bptr = blast;
      bptr++;
      b = (*bptr);
      
      while( true )
      {
        if( b == HEAP_END ) break;
        blen = b & HEAP_SIZE_MASK;
      
        if( (uint32)ptr == ( (uint32)bptr + 4 ) )
        {
          bptr_next = (uint32*)( (uint32)bptr + 4 + blen );
          if( (*bptr_next) == HEAP_END ) bptr_next = NULL;
          if( bptr_prev ) if( ( (*bptr_prev) & HEAP_USED ) == 0 ) left = true;
          if( bptr_next ) if( ( (*bptr_next) & HEAP_USED ) == 0 ) right = true;
  
          if( left && right )
          {
            (*bptr_prev) = (uint32)bptr_next - (uint32)bptr_prev + ( (*bptr_next) & HEAP_SIZE_MASK );
          }
          else if( left )
          {
            (*bptr_prev) = (uint32)bptr - (uint32)bptr_prev + ( (*bptr) & HEAP_SIZE_MASK );
          }
          else if( right )
          {
            if( b & HEAP_ALIGN ) bptr--;
            (*bptr) = (uint32)bptr_next - (uint32)bptr + ( (*bptr_next) & HEAP_SIZE_MASK );
          }
          else
          {
            if( b & HEAP_ALIGN ) { bptr--; blen += 4; }
            (*bptr) = blen;
          }
  
          if( left )
          {
            if( (*blast) > (uint32)bptr_prev ) (*blast) = (uint32)bptr_prev;
          }
          else
          {
            if( (*blast) > (uint32)bptr ) (*blast) = (uint32)bptr;
          }
  
          if( sysheap ) int_enable( is );

          return;
        }
      
        if( blen == 0 )
        {
          if( ( b & HEAP_ALIGN ) == 0 ) bptr_prev = bptr;
        }
        else
        {
          bptr_prev = bptr;
        }

        bptr = (uint32*)( (uint32)bptr + 4 + blen );
        b = (*bptr);
      }
    }
    heap = heap->next;
  }

  if( sysheap ) int_enable( is );

  os_sfault( OSSF_BAD_DESCRIPTOR );
}
// ---------------------------------------------------------------------------
s_os_heap* os_heap_create( int32 size )
{
  s_os_heap* rheap;
  s_os_mem_block* rblock;
  register uint32 is;
  uint32 mpage_number = MPAGE_ALL;

  if( size <= 0 ) return NULL;
  if( size < 32 ) size = 32;
  if( size & 15 ) size = ( size & 0xfffffff0 ) + 16;
  size += sizeof(s_os_heap);

  // Allocate memory block
  if( ( v_os_core_call == 0 ) && ( REG_OSCFG0 & OSCFG0_HEAP_PAGEU ) ) mpage_number = ( REG_OSCFG0 & OSCFG0_HEAP_PAGEM ) >> 3;
  rblock = os_mem_alloc( size, mpage_number );
  if( rblock == NULL ) return NULL;

  // Attach heap structure to memory block
  rheap = (s_os_heap*)( (char*)rblock + sizeof(s_os_mem_block) );
  memset( rheap, 0, sizeof(s_os_heap) );
  rheap->block = rblock;

  // Insert new heap into heap list of current process
  is = int_disable();  

  if( v_os_core_call == 0 )
  {
    if( v_os_current_process->heap == NULL )
    {
      v_os_current_process->heap = rheap;
    }
    else
    {
      v_os_current_process->heap->prev = rheap;
      rheap->next = v_os_current_process->heap;
      v_os_current_process->heap = rheap;
    }
  }
  else
  {
    if( v_os_core_heap == NULL )
    {
      v_os_core_heap = rheap;
    }
    else
    {
      v_os_core_heap->prev = rheap;
      rheap->next = v_os_core_heap;
      v_os_core_heap = rheap;
    }
  }
  
  int_enable( is );

  // Initialize heap data
  os_heap_init( rheap );

  return rheap;
}
// ---------------------------------------------------------------------------
void os_heap_destroy( s_os_heap* heap )
{
  register uint32 is;

  if( heap == NULL ) return;

  if( v_os_core_call == 0 )
  {
    is = int_disable();
    s_os_heap* cheap = v_os_current_process->heap;
    while( cheap )
    {
      if( cheap == heap )
      {
        if( cheap == v_os_current_process->heap ) v_os_current_process->heap = v_os_current_process->heap->next;
        if( cheap->prev ) cheap->prev->next = cheap->next;
        if( cheap->next ) cheap->next->prev = cheap->prev;
        break;
      }
      cheap = cheap->next;
    }
    int_enable( is );
  }

  os_mem_free( heap->block );
}
// ---------------------------------------------------------------------------
bool os_heap_isin( s_os_heap* heap, void* ptr )
{
  register uint32 is;
  uint32* bptr;
  uint32 b;
  uint32 blen;
  bool res = false;
  bool sysheap = false;

  if( ( heap == NULL ) || ( heap == v_os_core_heap ) )
  {
    is = int_disable();
    heap = v_os_core_heap;
    sysheap = true;
  }

  bptr = (uint32*)( (uint32)heap + sizeof(s_os_heap) + 4 );
  b = (*bptr);

  while( true )
  {
    if( b == HEAP_END ) break;
    blen = b & HEAP_SIZE_MASK;

    if( (uint32)ptr == ( (uint32)bptr + 4 ) )
    {
      res = true;
      break;
    }

    bptr = (uint32*)( (uint32)bptr + 4 + blen );
    b = (*bptr);
  }

  if( sysheap ) int_enable( is );

  return res;
}
// ---------------------------------------------------------------------------
void os_heap_stat( s_os_heap* heap, s_os_heap_stat* stat )
{
  register uint32 is;
  uint32* bptr;
  uint32 b;
  uint32 blen;
  bool sysheap = false;

  if( stat == NULL ) return;
  memset( stat, 0, sizeof(s_os_heap_stat) );

  if( ( heap == NULL ) || ( heap == v_os_core_heap ) )
  {
    is = int_disable();
    heap = v_os_core_heap;
    sysheap = true;
  }

  bptr = (uint32*)( (uint32)heap + sizeof(s_os_heap) + 4 );
  b = (*bptr);

  stat->total = heap->block->length - sizeof(s_os_heap);

  while( true )
  {
    if( b == HEAP_END ) break;
    blen = b & HEAP_SIZE_MASK;

    stat->c_desc++;

    if( b & HEAP_USED )
    {
      stat->used += blen;
      if( blen == 0 ) stat->c_0++;
      else if( blen < 16 ) stat->c_4_16++;
      else if( blen < 64 ) stat->c_16_64++;
      else if( blen < 256 ) stat->c_64_256++;
      else if( blen < 1024 ) stat->c_256_1k++;
      else if( blen < 4096 ) stat->c_1k_4k++;
      else if( blen < 16384 ) stat->c_4k_16k++;
      else if( blen < 65536 ) stat->c_16k_64k++;
      else if( blen < 262144 ) stat->c_64k_256k++;
      else if( blen < 1048576 ) stat->c_256k_1m++;
      else stat->c_1m_inf++;
    }
    else
    {
      stat->free += blen;
    }

    bptr = (uint32*)( (uint32)bptr + 4 + blen );
    b = (*bptr);
  }

  if( sysheap ) int_enable( is );
}

/*****************************************************************************
Syntax:  void os_syscall_sfault_vector()	    
Remarks:			    
*******************************************************************************/
void os_syscall_sfault_vector()
{
  os_sfault( OSSF_UNIMPLEMENTED_SYSCALL );
}

/*****************************************************************************
Syntax:  void os_syscall_null_vector()	    
Remarks:			    
*******************************************************************************/
void os_syscall_null_vector()
{
  /* Nothing */
}


/*****************************************************************************
Syntax: void os_syscall_init_table()	    
Remarks:			    
*******************************************************************************/
void os_syscall_init_table()
{
  for( int32 i = 0; i < SYSCALL__COUNT__; i++ ) __os_syscall_table__[i] = (void*)(uint32)&os_syscall_sfault_vector;
  __os_syscall_table__[SYSCALL_SYS_SETNAME] = (void*)(uint32)&os_system_setname;
  __os_syscall_table__[SYSCALL_SYS_GETNAME] = (void*)(uint32)&os_system_getname;
  __os_syscall_table__[SYSCALL_SYS_CHKNAME] = (void*)(uint32)&os_system_chkname;
  __os_syscall_table__[SYSCALL_SYS_REGGET] = (void*)(uint32)&os_system_regget;
  __os_syscall_table__[SYSCALL_SYS_REGSET] = (void*)(uint32)&os_system_regset;
  __os_syscall_table__[SYSCALL_SYS_REGLOCK] = (void*)(uint32)&os_system_reglock;
  __os_syscall_table__[SYSCALL_SYS_REGUNLOCK] = (void*)(uint32)&os_system_regunlock;
  __os_syscall_table__[SYSCALL_SYS_BUSLOCK] = (void*)(uint32)&os_system_buslock;
  __os_syscall_table__[SYSCALL_SYS_BUSUNLOCK] = (void*)(uint32)&os_system_busunlock;
  __os_syscall_table__[SYSCALL_SYS_DEBUG] = (void*)(uint32)&os_system_debug;
  __os_syscall_table__[SYSCALL_PRC_CREATE] = (void*)(uint32)&os_process_create;
  __os_syscall_table__[SYSCALL_PRC_EXIT] = (void*)(uint32)&os_process_exit;
  __os_syscall_table__[SYSCALL_PRC_YIELD] = (void*)(uint32)&os_process_yield_ll;
  __os_syscall_table__[SYSCALL_PRC_ID] = (void*)(uint32)&os_process_id;
  __os_syscall_table__[SYSCALL_PRC_PRIORITY] = (void*)(uint32)&os_process_priority;
  __os_syscall_table__[SYSCALL_PRC_ARG] = (void*)(uint32)&os_process_arg;
  __os_syscall_table__[SYSCALL_PRC_ARG_LENGTH] = (void*)(uint32)&os_process_arg_length;
  __os_syscall_table__[SYSCALL_PRC_HEAP] = (void*)(uint32)&os_process_heap;
  __os_syscall_table__[SYSCALL_PRC_SWTO] = (void*)(uint32)&os_process_switch_to;
  __os_syscall_table__[SYSCALL_PRC_SET_PRIORITY] = (void*)(uint32)&os_process_set_priority;
  __os_syscall_table__[SYSCALL_PRC_SET_FLAGS] = (void*)(uint32)&os_process_set_flags;
  __os_syscall_table__[SYSCALL_PRC_FLAGS] = (void*)(uint32)&os_process_flags;
  __os_syscall_table__[SYSCALL_PRC_SYSTEM] = (void*)(uint32)&os_process_system;
  __os_syscall_table__[SYSCALL_PRC_DISABLE] = (void*)(uint32)&os_process_disable_ll;
  __os_syscall_table__[SYSCALL_PRC_ENABLE] = (void*)(uint32)&os_process_enable_ll;
  __os_syscall_table__[SYSCALL_PRC_JOIN] = (void*)(uint32)&os_process_join;
  __os_syscall_table__[SYSCALL_MEM_ALLOC] = (void*)(uint32)&os_mem_alloc;
  __os_syscall_table__[SYSCALL_MEM_FREE] = (void*)(uint32)&os_mem_free;
  __os_syscall_table__[SYSCALL_MEM_STAT] = (void*)(uint32)&os_mem_stat;
  __os_syscall_table__[SYSCALL_MEM_PTR] = (void*)(uint32)&os_mem_ptr;
  __os_syscall_table__[SYSCALL_HEAP_CREATE] = (void*)(uint32)&os_heap_create;
  __os_syscall_table__[SYSCALL_HEAP_DESTROY] = (void*)(uint32)&os_heap_destroy;
  __os_syscall_table__[SYSCALL_HEAP_INIT] = (void*)(uint32)&os_heap_init;
  __os_syscall_table__[SYSCALL_HEAP_ALLOC] = (void*)(uint32)&os_heap_alloc;
  __os_syscall_table__[SYSCALL_HEAP_FREE] = (void*)(uint32)&os_heap_free;
  __os_syscall_table__[SYSCALL_HEAP_ISIN] = (void*)(uint32)&os_heap_isin;
  __os_syscall_table__[SYSCALL_HEAP_STAT] = (void*)(uint32)&os_heap_stat;
  __os_syscall_table__[SYSCALL_SEM_ALLOC] = (void*)(uint32)&os_semaphore_alloc;
  __os_syscall_table__[SYSCALL_SEM_RESET] = (void*)(uint32)&os_semaphore_reset;
  __os_syscall_table__[SYSCALL_SEM_FREE] = (void*)(uint32)&os_semaphore_free;
  __os_syscall_table__[SYSCALL_SEM_LOCK] = (void*)(uint32)&os_semaphore_lock;
  __os_syscall_table__[SYSCALL_SEM_UNLOCK] = (void*)(uint32)&os_semaphore_unlock;
  __os_syscall_table__[SYSCALL_SEM_UNLOCK_SW] = (void*)(uint32)&os_semaphore_unlock_sw;
  __os_syscall_table__[SYSCALL_SEM_LOCKUNLOCK] = (void*)(uint32)&os_semaphore_lockunlock;
  __os_syscall_table__[SYSCALL_SEM_LOCKED] = (void*)(uint32)&os_semaphore_locked;
  __os_syscall_table__[SYSCALL_SEM_VALUE] = (void*)(uint32)&os_semaphore_value;
  __os_syscall_table__[SYSCALL_INT_ENABLE] = (void*)(uint32)&os_interrupt_enable_ll;
  __os_syscall_table__[SYSCALL_INT_DISABLE] = (void*)(uint32)&os_interrupt_disable_ll;
  __os_syscall_table__[SYSCALL_INT_LOCK] = (void*)(uint32)&os_interrupt_lock;
  __os_syscall_table__[SYSCALL_INT_UNLOCK] = (void*)(uint32)&os_interrupt_unlock;
  __os_syscall_table__[SYSCALL_INT_ALLOC] = (void*)(uint32)&os_interrupt_alloc;
  __os_syscall_table__[SYSCALL_INT_FREE] = (void*)(uint32)&os_interrupt_free;
  __os_syscall_table__[SYSCALL_INT_SWTO] = (void*)(uint32)&os_interrupt_swto;
  __os_syscall_table__[SYSCALL_INT_CLEAR] = (void*)(uint32)&os_interrupt_clear;
  __os_syscall_table__[SYSCALL_INT_SET] = (void*)(uint32)&os_interrupt_set;
  __os_syscall_table__[SYSCALL_TIME_SET] = (void*)(uint32)&os_time_set;
  __os_syscall_table__[SYSCALL_TIME_S] = (void*)(uint32)&os_time_s;
  __os_syscall_table__[SYSCALL_TIME_M] = (void*)(uint32)&os_time_m;
  __os_syscall_table__[SYSCALL_TIME_U] = (void*)(uint32)&os_time_u;
  __os_syscall_table__[SYSCALL_TIME_N] = (void*)(uint32)&os_time_n;
  __os_syscall_table__[SYSCALL_TIME_CORE] = (void*)(uint32)&os_time_core;
  __os_syscall_table__[SYSCALL_TIME_CORE_N] = (void*)(uint32)&os_time_core_n;
  __os_syscall_table__[SYSCALL_SLEEP_S] = (void*)(uint32)&os_sleep_s;
  __os_syscall_table__[SYSCALL_SLEEP_M] = (void*)(uint32)&os_sleep_m;
  __os_syscall_table__[SYSCALL_SLEEP_U] = (void*)(uint32)&os_sleep_u;
  __os_syscall_table__[SYSCALL_DRV_PLUG] = (void*)(uint32)&os_driver_plug;
  __os_syscall_table__[SYSCALL_DRV_UNPLUG] = (void*)(uint32)&os_driver_unplug;
  __os_syscall_table__[SYSCALL_DRV_OPEN] = (void*)(uint32)&os_driver_open;
  __os_syscall_table__[SYSCALL_DRV_CLOSE] = (void*)(uint32)&os_driver_close;
  __os_syscall_table__[SYSCALL_DRV_READ] = (void*)(uint32)&os_driver_read;
  __os_syscall_table__[SYSCALL_DRV_WRITE] = (void*)(uint32)&os_driver_write;
  __os_syscall_table__[SYSCALL_DRV_IOCTL] = (void*)(uint32)&os_driver_ioctl;
  __os_syscall_table__[SYSCALL_DRV_SELECT] = (void*)(uint32)&os_driver_select;
  __os_syscall_table__[SYSCALL_DRV_MKD] = (void*)(uint32)&os_driver_mkd;
  __os_syscall_table__[SYSCALL_DRV_RMD] = (void*)(uint32)&os_driver_rmd;
  __os_syscall_table__[SYSCALL_DRV_CREATE] = (void*)(uint32)&os_driver_create;
  __os_syscall_table__[SYSCALL_DRV_INC] = (void*)(uint32)&os_driver_inc_path;
  __os_syscall_table__[SYSCALL_DRV_DEC] = (void*)(uint32)&os_driver_dec_path;
  __os_syscall_table__[SYSCALL_DRV_RFS] = (void*)(uint32)&os_driver_return_to_rfs;
  __os_syscall_table__[SYSCALL_DRV_LIST_DESTROY] = (void*)(uint32)&os_driver_list_destroy;
  __os_syscall_table__[SYSCALL_DRV_LIST] = (void*)(uint32)&os_driver_list;
  __os_syscall_table__[SYSCALL_DRV_REMOVE] = (void*)(uint32)&os_driver_remove;
  __os_syscall_table__[SYSCALL_DRV_RENAME] = (void*)(uint32)&os_driver_rename;
  __os_syscall_table__[SYSCALL_EXT_PLUG] = (void*)(uint32)&os_extension_plug;
  __os_syscall_table__[SYSCALL_EXT_UNPLUG] = (void*)(uint32)&os_extension_unplug;
  __os_syscall_table__[SYSCALL_EXT_LOAD] = (void*)(uint32)&os_extension_load;
  __os_syscall_table__[SYSCALL_EXT_UNLOAD] = (void*)(uint32)&os_extension_unload;
  __os_syscall_table__[SYSCALL_EXT_SYMBOL] = (void*)(uint32)&os_extension_symbol;
  __os_syscall_table__[SYSCALL_RES_SHARE] = (void*)(uint32)&os_resource_share;
  __os_syscall_table__[SYSCALL_RES_UNSHARE] = (void*)(uint32)&os_resource_unshare;
  __os_syscall_table__[SYSCALL_RES_SHARED] = (void*)(uint32)&os_resource_shared;
  __os_syscall_table__[SYSCALL_RES_CHOWN] = (void*)(uint32)&os_resource_chown;
  __os_syscall_table__[SYSCALL_MSG_START] = (void*)(uint32)&os_message_start;
  __os_syscall_table__[SYSCALL_MSG_END] = (void*)(uint32)&os_message_end;
  __os_syscall_table__[SYSCALL_MSG_OPEN] = (void*)(uint32)&os_message_open;
  __os_syscall_table__[SYSCALL_MSG_CLOSE] = (void*)(uint32)&os_message_close;
  __os_syscall_table__[SYSCALL_MSG_SEND] = (void*)(uint32)&os_message_send;
  __os_syscall_table__[SYSCALL_MSG_RECV] = (void*)(uint32)&os_message_recv;
  __os_syscall_table__[SYSCALL_MSG_HAVE] = (void*)(uint32)&os_message_have;
  __os_syscall_table__[SYSCALL_MSG_DISCOVER] = (void*)(uint32)&os_message_discover;
  __os_syscall_table__[SYSCALL_MSG_PID] = (void*)(uint32)&os_message_pid;
  __os_syscall_table__[SYSCALL_MSG_FREE] = (void*)(uint32)&os_message_free;
  __os_syscall_table__[SYSCALL_MSG_ALLOC] = (void*)(uint32)&os_message_alloc;
  __os_syscall_table__[SYSCALL_MSG_QUEUE_INIT] = (void*)(uint32)&os_message_queue_init;
  __os_syscall_table__[SYSCALL_MSG_QUEUE_PUSH] = (void*)(uint32)&os_message_queue_push;
  __os_syscall_table__[SYSCALL_MSG_QUEUE_POP] = (void*)(uint32)&os_message_queue_pop;
  __os_syscall_table__[SYSCALL_MSG_QUEUE_DEINIT] = (void*)(uint32)&os_message_queue_deinit;
  __os_syscall_table__[SYSCALL_MSG_REGPIPE] = (void*)(uint32)&os_message_regpipe;
  __os_syscall_table__[SYSCALL_LIF_LOAD] = (void*)(uint32)&os_lif_load;
  __os_syscall_table__[SYSCALL_LIF_UNLOAD] = (void*)(uint32)&os_lif_unload;
  __os_syscall_table__[SYSCALL_LIF_FREE] = (void*)(uint32)&os_lif_free;
  __os_syscall_table__[SYSCALL_LIF_LOAD_FIXED] = (void*)(uint32)&os_lif_load_fixed;
  __os_syscall_table__[SYSCALL_SYS_CACHE_CLEAR] = (void*)(uint32)&os_cache_writeback_invalidate;
}
// ---------------------------------------------------------------------------
void os_sfault( uint32 code )
{
  v_os_current_process->sfault_code = code;
  int_enable( 1 );
  prc_yield();
}
// ---------------------------------------------------------------------------


/*****************************************************************************
Syntax:  void os_cinit () 
Remarks: Функция производит инициализацию глобальных переменных и вызов
		 конструкторов классов глобальных переменых.			    
*******************************************************************************/
void os_cinit()
{
  uint8* sptr;
  uint8* dptr;
  uint32 length, shift;
  uint32 tptr;
  void (*pinit_func)(); 
  extern void* __cinit__;
  extern void* __pinit__;

  // Initialize syscall table
  syscall_init( __syscall_tab, sizeof(__syscall_tab) );

  // Initialize constants (.cinit)
  sptr = (uint8*)&__cinit__;
  if( (uint32)sptr != 0xffffffff )
  {
    while( true )
    {
      length = (*((uint32*)sptr));
      if( length == 0 ) break;
      shift = ( 8 - ( length & 7 ) ) & 7;
      sptr += 4;
      dptr = (uint8*)(*((uint32*)sptr));
      sptr += 4;
      while( length-- )
      {
        (*dptr) = (*sptr);
        dptr++;
        sptr++;
      }
      sptr += shift;
    }
  }

  // Initialize global classes (.pinit)
  sptr = (uint8*)&__pinit__;
  if( (uint32)sptr != 0xffffffff )
  {
    while( true )
    {
      dptr = (uint8*)(*((uint32*)sptr));
      if( dptr == NULL ) break;
      tptr = (uint32)dptr;
      pinit_func = (void(*)())tptr;
      pinit_func();
      sptr += 4;
    }
  }
}
// ---------------------------------------------------------------------------
#pragma CODE_SECTION( ".os_init_code" );
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#ifndef NO_OS_MEMTST
	static bool os_memncmp( char* ptr, char c, uint32 l )
	{
	  for( uint32 i = 0; i < l; i++, ptr++ ) if( (*ptr) != c ) return false;
	  return true;
	}
#endif


// ---------------------------------------------------------------------------
#pragma CODE_SECTION( ".os_init_code" );
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
/*****************************************************************************
Syntax:  static bool os_memtst( uint32 start_mem, uint32 end_mem )	    
Remarks: Функция Тестирования ОЗУ SDRAM Центрального Процессора.очень долго!			    
*******************************************************************************/
static bool os_memtst( uint32 start_mem, uint32 end_mem )
{
 
  #ifdef NO_OS_MEMTST
 	  return true;
  #else
	  uint32 i, length;
	  uint8* ptr;

	  if((!start_mem)&&(!end_mem))return true;

	  if(end_mem < start_mem)return false;   

	  length = ( end_mem - start_mem ) & 0xfffffff0;
	  
	  // Address test
	  for( ptr = (uint8*)start_mem, i = 0; i < length; i++, ptr++ ) (*ptr) = i;
	  for( ptr = (uint8*)start_mem, i = 0; i < length; i++, ptr++ ) if( (*ptr) != (uint8)( i & 0x000000ff ) ) return false;
	  // Data test
	  memset( (void*)start_mem, 0x55, length );
	  if( !os_memncmp( (char*)start_mem, 0x55, length ) ) return false;
	  memset( (void*)start_mem, 0xaa, length );
	  if( !os_memncmp( (char*)start_mem, 0xaa, length ) ) return false;
	  // Clear
	  memset( (void*)start_mem, 0, length );
	  return true;
  #endif
}
// ---------------------------------------------------------------------------
#pragma CODE_SECTION( ".os_init_code" );
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
static s_os_mem_block* os_init_mem_page(uint32 start_addr_page, uint32 end_addr_page)
{
  uint32 length;
  s_os_mem_block* page = (s_os_mem_block*)start_addr_page;

  if(!page)
     return NULL;

  length = ( end_addr_page - start_addr_page ) & 0xfffffff0;

  page->prev = NULL;
  page->next = NULL;
  page->length = length - 16;
  page->pid = 0;
  page->flags = 0;

  return page;
}
// ---------------------------------------------------------------------------

#pragma CODE_SECTION( ".os_init_code" );

/*****************************************************************************
Syntax:  void os_initialize_core()	    
Remarks: Инициализация нижнего уровня		    
*******************************************************************************/
void os_initialize_core()
{
  s_prc_attr pattr;

  // Disable all timers
  os_time_init_module( 0 );

  // Initialize PLL
  #if defined(CHIP_6457)
  	os_pll_init_module();
  #endif

  // System init stage 0
  os_system_init_module( 0 );

  // Initialize variables
  v_os_swto_pid = 0xffff;
  v_os_errno = 0;
  memset( &pattr, 0, sizeof(pattr) );

  // All calls from this function is OS calls
  v_os_core_call = 1;

  // Initialize memory pages
  if( os_memtst( (uint32)&OS_MPAGE0_BEGIN, (uint32)&OS_MPAGE0_END ) )
  {
    v_page[0] = os_init_mem_page( (uint32)&OS_MPAGE0_BEGIN, (uint32)&OS_MPAGE0_END );
  }
  else
  {
    REG_OSTS1 |= OSTS1_MPAGE0_FAIL;
    v_page[0] = NULL;
  }
  v_page[1] = NULL;
  v_page[2] = NULL;
  v_page[3] = NULL;

  // Initialize core heap
  if( ( v_os_core_heap = heap_create( core_init_cfg.core_heap_len ) ) == NULL )
  {
    while( true )
      asm( " nop " );
  }

  // Set current context to null process context
  memset( &v_os_process_null_context, 0, sizeof(v_os_process_null_context) );
  memset( &v_os_process_null_register, 0, sizeof(v_os_process_null_register) );
  v_os_process_null_context.reg = &v_os_process_null_register;
  v_os_current_process = &v_os_process_null_context;

  // Initialize semaphores and system
  os_semaphore_init_module( 0 );
  os_system_init_module( 1 );

  // Initialize syscall table
  os_syscall_init_table();
  // Load all constants
  os_cinit();
  // Configure core
  os_config();

  // Test external memory
  if((core_init_cfg.extram_start != 0)&&((core_init_cfg.extram_end != 0)))
  {
    if( !os_memtst(core_init_cfg.extram_start, core_init_cfg.extram_end ) )
    {
      REG_OSTS1 |= OSTS1_EXTRAM_FAIL;
    }
  }
  // Test MPAGE memory
  if( !os_memtst((uint32)&OS_MPAGE1_BEGIN, (uint32)&OS_MPAGE1_END ) )
  {
    REG_OSTS1 |= OSTS1_MPAGE1_FAIL;
  }
  
  /*   //SKD PATCH no MPAGE2 and MPAGE3 from device
  if( !os_memtst((uint32)&OS_MPAGE2_BEGIN, (uint32)&OS_MPAGE2_END ) )
  {
    REG_OSTS1 |= OSTS1_MPAGE2_FAIL;
  }
  if( !os_memtst((uint32)&OS_MPAGE3_BEGIN, (uint32)&OS_MPAGE3_END ) )
  {
    REG_OSTS1 |= OSTS1_MPAGE3_FAIL;
  }
  */

 // Initialize external memory pages
  v_page[1] = os_init_mem_page( (uint32)&OS_MPAGE1_BEGIN, (uint32)&OS_MPAGE1_END );
 
    //Skd patch no external Memory Page MPAGE2 and MPAGE3
  /* 
  v_page[2] = os_init_mem_page( (uint32)&OS_MPAGE2_BEGIN, (uint32)&OS_MPAGE2_END );
  v_page[3] = os_init_mem_page( (uint32)&OS_MPAGE3_BEGIN, (uint32)&OS_MPAGE3_END );
  */

  // Create IDLE process
  pattr.priority = PRIORITY_IDLE;
  if( os_process_create( &os_idle_process, NULL, 0, &pattr ) < 0 )
  {
    while( true )
      asm( " nop" );
  }

  // Create core process
  pattr.priority = 0;
  pattr.stack = sys_stack;
  if( os_process_create( &os_process, NULL, 0, &pattr ) < 0 )
  {
    while( true )
      asm( " nop" );
  }

  // Set first process to call
  v_os_process_null_context.next = v_os_process_ring;

  // Initialize interrupt contexts and interrupt allocation table
  memset( &v_os_irctx_nmi, 0, sizeof(v_os_irctx_nmi) );
  memset( &v_os_irctx, 0, sizeof(v_os_irctx) );
  
  // Initialize core modules
  os_driver_init_module();
  os_message_init_module();
  os_extension_init_module();

  // Initialize timers
  os_time_init_module( 1 );

  // Initialize interrupt module
  os_interrupt_init_module();

  // Enable process switcher and switch context to a first process
  prc_enable( 1 );
  prc_yield();
}
// ---------------------------------------------------------------------------
#pragma CODE_SECTION( ".os_init_scall" );
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

/*****************************************************************************
Syntax:  void os_syscall_copy_table( void* dst, int32 length ) 	    
Remarks:			    
*******************************************************************************/
void os_syscall_copy_table( void* dst, int32 length )
{
  if( (uint32)dst <= (uint32)&OS_NMISTACK_END ) return;
  memcpy( dst, __os_syscall_table__, length );
}
// ---------------------------------------------------------------------------
