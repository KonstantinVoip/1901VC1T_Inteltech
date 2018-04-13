// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp866
// !: d: ╠юфхы№ ёюфхЁцшЄ ЁхрышчрЎш■ ьхэхфцхЁр фшэрьшўхёъющ чруЁєчъш яЁшыюцхэшщ.
// !: [os_lif.cpp]
// ---------------------------------------------------------------------------
#define SYSCALL_DIRECT
#include <os.h>
// ---------------------------------------------------------------------------
#define LIF_CODE_ALIGN          32

// ---------------------------------------------------------------------------
// !: fn: static uint32 lif_op( uint32 la, uint32 ra, uint32 type )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>╬яшёрэшх:</b><br>
// !: d: <br>
// !: d: ╘єэъЎш  тючтЁр∙рхЄ Ёхчєы№ЄрЄ ыюушўхёъющ юяхЁрЎшш type, т√ўшёыхээющ эр
// !: d: рЁуєьхэЄрї la ш ra. ┬ючьюцэ√ьш чэрўхэш ьш type ьюуєЄ с√Є№: LIF_AND,
// !: d: LIF_OR, LIF_XOR, LIF_NAND, LIF_NOR шыш LIF_EQU.<br>
// !: d: <br>
// !: d: <b>┬ючтЁр∙рхь√х чэрўхэш :</b><br>
// !: d: <br>
// !: d: ┼ёыш рЁуєьхэЄ type шьххЄ яЁртшы№эюх чэрўхэшх, ЇєэъЎш  тючтЁр∙рхЄ
// !: d: Ёхчєы№ЄрЄ єърчрээющ ыюушўхёъющ юяхЁрЎшш, шэрўх 0.
// ---------------------------------------------------------------------------
static uint32 lif_op( uint32 la, uint32 ra, uint32 type )
{
  switch( type )
  {
    case LIF_AND:
      return ( la & ra );

    case LIF_OR:
      return ( la | ra );

    case LIF_XOR:
      return ( la ^ ra );

    case LIF_NAND:
      return ~( la & ra );

    case LIF_NOR:
      return ~( la | ra );

    case LIF_EQU:
      return ~( la ^ ra );
  }

  return 0;
}
// ---------------------------------------------------------------------------
// !: fn: static uint32 lif_shift( uint32 a, uint32 type )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция выполняет двоичный сдвиг аргумента a влево (вправо), в
// !: d: зависимости от значения аргумента type. Если type находится на отрезке
// !: d: от 1 до 31 выполняется сдвиг влево на type. Если type находится на
// !: d: отрезке от 32 до 62 выполняется сдвиг вправо на type - 31. Если type
// !: d: равен 0 сдвиг не выполняется. Если type больше или равен 63 результат
// !: d: всегда 0.<br>
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: Функция возвращает результат сдвига числа a на type, в соответствии с
// !: d: описанной логикой.
// ---------------------------------------------------------------------------
static uint32 lif_shift( uint32 a, uint32 type )
{
  if( type == 0 )
  {
    return a;
  }
  else if( type >= 63 )
  {
    return 0;
  }
  else if( ( type >= 1 ) && ( type <= 31 ) )
  {
    return ( a << type );
  }
  else
  {
    return ( a >> ( type - 31 ) );
  }
}
// ---------------------------------------------------------------------------
// !: fn: static uint32 lif_neg( uint32 a, uint32 type )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция вычисляет побитовую инверсию числа a.<br>
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: Если type равен LIF_POS, функция возвращает a, если type равен
// !: d: LIF_NEG, функция возвращает побитовую инверсию a.
// ---------------------------------------------------------------------------
static uint32 lif_neg( uint32 a, uint32 type )
{
  if( type == LIF_POS ) return a;
  return ~a;
}
// ---------------------------------------------------------------------------
// !: fn: static uint32 lif_caddr( uint32 v, uint32 paddr, uint32 vaddr, uint32 type )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция осуществляет преобразование виртуального адреса v в
// !: d: соответствии с заданным типом преобразования type и адресами начала
// !: d: виртуальной страницы vaddr и физической paddr.<br>
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: Если type равен LIF_ABSOLUTE, функция возвращает v - vaddr + paddr.
// !: d: Если type равен LIF_RELATIVE, функция возвращает v - vaddr.
// !: d: Если type равен LIF_VIRTUAL, функция возвращает v.
// !: d: Если type равен LIF_OFFSET, функция возвращает v + paddr.
// ---------------------------------------------------------------------------
static uint32 lif_caddr( uint32 v, uint32 paddr, uint32 vaddr, uint32 type )
{
  switch( type )
  {
    case LIF_ABSOLUTE:
      return v - vaddr + paddr;
  
    case LIF_RELATIVE:
      return v - vaddr;
    
    case LIF_VIRTUAL:
      return v;

    case LIF_OFFSET:
      return v + paddr;
  }

  return 0;
}
// ---------------------------------------------------------------------------
// !: fn: static void lif_patch0( uint32 offset, uint32 paddr, uint32 vaddr, s_lif_patch& p )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция осуществляет патч кода нулевого и первого типа. <i>подробное описание будет в следующих версиях документа</i>
// ---------------------------------------------------------------------------
static void lif_patch0( uint32 offset, uint32 paddr, uint32 vaddr, s_lif_patch& p )
{
  uint32 d = (*(uint32*)offset);
  uint32 v = lif_caddr( p.v, paddr, vaddr, LIF_P_CADDR( p.method, 0 ) );
  d = lif_shift( d, LIF_P_SHIFT( p.method, 2 ) );
  v = lif_shift( v, LIF_P_SHIFT( p.method, 15 ) );
  uint32 m1 = lif_shift( p.a, LIF_P_SHIFT( p.method, 9 ) );
  uint32 m2 = lif_shift( p.a, LIF_P_SHIFT( p.method, 22 ) );
  m1 = lif_neg( m1, LIF_P_NEG( p.method, 8 ) );
  m2 = lif_neg( m1, LIF_P_NEG( p.method, 21 ) );
  (*(uint32*)offset) = ( d & m1 ) | ( v & m2 );
}
// ---------------------------------------------------------------------------
// !: fn: static void lif_patch2( uint32 offset, s_lif_patch& p )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция осуществляет патч кода второго типа. <i>подробное описание будет в следующих версиях документа</i>
// ---------------------------------------------------------------------------
static void lif_patch2( uint32 offset, s_lif_patch& p )
{
  uint32 d = (*(uint32*)offset);
  uint32 da = lif_shift( d, LIF_P_SHIFT( p.method, 22 ) );
  uint32 db = lif_shift( d, LIF_P_SHIFT( p.method, 16 ) );
  da = lif_op( da, p.a, LIF_P_OP( p.method, 10 ) );
  db = lif_op( db, p.b, LIF_P_OP( p.method, 7 ) );
  uint32 dv = lif_op( d, p.v, LIF_P_OP( p.method, 13 ) );
  da = lif_op( da, db, LIF_P_OP( p.method, 4 ) );
  (*(uint32*)offset) = lif_op( dv, da, LIF_P_OP( p.method, 1 ) );
}
// ---------------------------------------------------------------------------
// !: fn: static bool lif_patch( uint32 sn, uint32 scount, s_lif_section* s, s_lif_patch& p )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция выполняет линковочный патч кода, при загрузке LIF формата.<br>
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: Функция возвращает true в случае успеха и false при невозможности
// !: d: выполнения патча.
// ---------------------------------------------------------------------------
static bool lif_patch( uint32 sn, uint32 scount, s_lif_section* s, s_lif_patch& p )
{
  s_lif_patch tp;
  uint32 palign, offset;

  if( sn >= scount ) return false;
  if( s[sn].paddr & ( LIF_CODE_ALIGN - 1 ) ) palign = LIF_CODE_ALIGN - ( s[sn].paddr & ( LIF_CODE_ALIGN - 1 ) ); else palign = 0;
  offset = s[sn].paddr + palign + p.offset;

  switch( LIF_P_TYPE( p.method, 28 ) )
  {
    case 0:
    {
      lif_patch0( offset, s[sn].paddr + palign, s[sn].vaddr, p );
    }
    break;

    case 1:
    {
      uint32 tpalign;
      if( p.b >= scount ) return false;
      if( s[p.b].paddr & ( LIF_CODE_ALIGN - 1 ) ) tpalign = LIF_CODE_ALIGN - ( s[p.b].paddr & ( LIF_CODE_ALIGN - 1 ) ); else tpalign = 0;
      memcpy( &tp, &p, sizeof(s_lif_patch) );
      tp.v += ( s[tp.b].paddr + tpalign ) - ( s[sn].paddr + palign );
      lif_patch0( offset, s[sn].paddr + palign, s[tp.b].vaddr, tp );
    }
    break;

    case 2:
    {
      lif_patch2( offset, p );
    }
    break;
  }

  return true;
}
// ---------------------------------------------------------------------------
// !: fn: static int32 lif_link( const char* fname, s_lif_overlay* overlay )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция осуществляет загрузку и бинарного файла в LIF формате.<br>
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: В случае успеха функция возвращает OSE_OK, иначе одну из ошибок:<br><br>
// !: d: <table cellpadding=2 cellspacing=2 border=0>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_NULL_PARAM</td>
// !: d: <td> - </td>
// !: d: <td>один из переданных аргументов fname или overlay равен нулю;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_NO_DEVICE</td>
// !: d: <td> - </td>
// !: d: <td>не найдено устройство или файл из которого запрошена загрузка;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_CANT_OPEN</td>
// !: d: <td> - </td>
// !: d: <td>ошибка открытия устройства или файла из которого запрошена загрузка;</td>
// !: d: </tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_CANT_READ</td>
// !: d: <td> - </td>
// !: d: <td>ошибка чтения из устройства или файла из которого запрошена загрузка;</td>
// !: d: </tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_LIF_BAD_HEADER</td>
// !: d: <td> - </td>
// !: d: <td>плохой заголовок LIF формата;</td>
// !: d: </tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_LIF_WRONG_TARGET_CPU</td>
// !: d: <td> - </td>
// !: d: <td>попытка загрузить бинайрный файл для другой аппаратной архитектуры;</td>
// !: d: </tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_NO_MEMORY</td>
// !: d: <td> - </td>
// !: d: <td>недостаточно памяти для загрузки;</td>
// !: d: </tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_LIF_BAD_SECTION_HEADER</td>
// !: d: <td> - </td>
// !: d: <td>плохой заголовок секции LIF формата;</td>
// !: d: </tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_LIF_CANT_APPLY_PATCH</td>
// !: d: <td> - </td>
// !: d: <td>ошибка применения линковочного патча.</td>
// !: d: </tr>
// !: d: </table><br>
// ---------------------------------------------------------------------------
static int32 lif_link( const char* fname, s_lif_overlay* overlay )
{
  s_lif_header header;
  s_lif_patch patch;
  s_lif_section* section = NULL;
  int32 errc;
  uint32 d = RES_VOID;
  uint32 i, j;
  uint32 palign;

  // Check params
  if( ( fname == NULL ) || ( overlay == NULL ) ) return OSE_NULL_PARAM;

  // Clear overlay structure
  memset( overlay, 0, sizeof(s_lif_overlay) );

  // Open LIF file
  if( ( d = drv_mkd( fname ) ) == RES_VOID ) return OSE_NO_DEVICE;
  if( drv_open( d, DRV_RD ) != OSE_OK ) { errc = OSE_CANT_OPEN; goto l_fail; }

  // Read LIF header and check file format
  if( drv_read( d, &header, sizeof(header) ) != sizeof(header) ) { errc = OSE_CANT_READ; goto l_fail; }
  if( ( header.scount == 0 ) || ( header.magic != 0x3046494c ) || ( header.vepoint_snum >= header.scount ) ) { errc = OSE_LIF_BAD_HEADER; goto l_fail; }
  if( header.target != LIF_TGT_TMS320C64XX ) { errc = OSE_LIF_WRONG_TARGET_CPU; goto l_fail; }
  overlay->stack_size = header.stack;

  // Allocate memory for overlay structure
  if( header.symcount )
  {
    overlay->symbol = new s_lif_symbol[header.symcount];
    if( overlay->symbol == NULL )
    {
      errc = OSE_NO_MEMORY;
      goto l_fail;
    }
    overlay->symbol_count = header.symcount;
    memset( overlay->symbol, 0, sizeof(s_lif_symbol) * overlay->symbol_count );
  }
  overlay->page = new s_os_mem_block*[header.scount];
  if( overlay->page == NULL )
  {
    errc = OSE_NO_MEMORY;
    goto l_fail;
  }
  overlay->page_count = header.scount;
  memset( overlay->page, 0, sizeof(void*) * header.scount );

  // Allocate memory for section headers
  i = sizeof(s_lif_section) * header.scount;
  section = (s_lif_section*)heap_alloc( NULL, i, HEAP_ALIGN_4 );
  if( section == NULL ) { errc = OSE_NO_MEMORY; goto l_fail; }
  memset( section, 0, i );

  // Read section headers
  if( drv_read( d, section, i ) != i ) { errc = OSE_CANT_READ; goto l_fail; }

  // Read symbols
  if( header.symcount )
  {
    // todo
  }

  // Allocate memory for sections
  for( i = 0; i < header.scount; i++ )
  {
    if( section[i].flags & LIF_SF_STATIC ) continue;
    if( section[i].length < section[i].size ) { errc = OSE_LIF_BAD_SECTION_HEADER; goto l_fail; }
    if( ( overlay->page[i] = mem_alloc( section[i].length + LIF_CODE_ALIGN, MPAGE_ALL ) ) == NULL ) { errc = OSE_NO_MEMORY; goto l_fail; }
    section[i].paddr = (uint32)( (char*)overlay->page[i] + sizeof(s_os_mem_block) );
    if( section[i].paddr & ( LIF_CODE_ALIGN - 1 ) ) palign = LIF_CODE_ALIGN - ( section[i].paddr & ( LIF_CODE_ALIGN - 1 ) ); else palign = 0;
    if( drv_read( d, (uint8*)section[i].paddr + palign, section[i].size ) != section[i].size ) { errc = OSE_CANT_READ; goto l_fail; }
    if( palign ) memset( (uint8*)section[i].paddr, 0, palign );
    memset( (uint8*)section[i].paddr + palign + section[i].size, 0, section[i].length - section[i].size );
    if( section[i].flags & LIF_SF_BSS ) overlay->bss_point = section[i].paddr + palign;
  }

  // Patch section code
  for( i = 0; i < header.scount; i++ )
  {
    // Apply each section patch
    for( j = 0; j < section[i].pcount; j++ )
    {
      if( drv_read( d, &patch, sizeof(s_lif_patch) ) != sizeof(s_lif_patch) ) { errc = OSE_CANT_READ; goto l_fail; }
      if( !lif_patch( i, header.scount, section, patch ) ) { errc = OSE_LIF_CANT_APPLY_PATCH; goto l_fail; }
    }
  }

  drv_rmd( d );

  // Modify entry point
  if( section[header.vepoint_snum].paddr & ( LIF_CODE_ALIGN - 1 ) ) palign = LIF_CODE_ALIGN - ( section[header.vepoint_snum].paddr & ( LIF_CODE_ALIGN - 1 ) ); else palign = 0;
  overlay->entry_point = header.vepoint_offset + section[header.vepoint_snum].paddr + palign;

  // Writeback and invalidate L1P and L1D caches for loaded PO
  for( i = 0; i < header.scount; i++ )
  {
    if( ( palign = (uint32)overlay->page[i] ) == 0 ) continue;
    os_cache_writeback_invalidate( palign, overlay->page[i]->length + sizeof(s_os_mem_block) );
  }

  // Release section headers
  heap_free( NULL, section );

  return OSE_OK;

l_fail:

  drv_rmd( d );

  if( overlay->page )
  {
    for( i = 0; i < overlay->page_count; i++ ) mem_free( overlay->page[i] );
    delete[] overlay->page;
  }
  if( overlay->symbol )
  {
    for( i = 0; i < overlay->symbol_count; i++ ) delete[] overlay->symbol[i].name;
    delete[] overlay->symbol;
  }
  memset( overlay, 0, sizeof(s_lif_overlay) );

  heap_free( NULL, section );

  return errc;
}
// ---------------------------------------------------------------------------
static int32 lif_link_fixed( const char* fname, s_lif_overlay* overlay, uint32 paddr, uint32 psize )
{
  s_lif_header header;
  s_lif_patch patch;
  s_lif_section* section = NULL;
  int32 errc;
  uint32 d = RES_VOID;
  uint32 i, j;
  uint32 memlimit = paddr + psize - 1;
  int32 delta;

  // Check params
  if( ( fname == NULL ) || ( overlay == NULL ) ) return OSE_NULL_PARAM;

  // Clear overlay structure
  memset( overlay, 0, sizeof(s_lif_overlay) );

  // Open LIF file
  if( ( d = drv_mkd( fname ) ) == RES_VOID ) return OSE_NO_DEVICE;
  if( drv_open( d, DRV_RD ) != OSE_OK ) { errc = OSE_CANT_OPEN; goto l_fail; }

  // Read LIF header and check file format
  if( drv_read( d, &header, sizeof(header) ) != sizeof(header) ) { errc = OSE_CANT_READ; goto l_fail; }
  if( ( header.scount == 0 ) || ( header.magic != 0x3046494c ) || ( header.vepoint_snum >= header.scount ) ) { errc = OSE_LIF_BAD_HEADER; goto l_fail; }
  if( header.target != LIF_TGT_TMS320C64XX ) { errc = OSE_LIF_WRONG_TARGET_CPU; goto l_fail; }
  overlay->stack_size = header.stack;

  // Allocate memory for section headers
  i = sizeof(s_lif_section) * header.scount;
  section = (s_lif_section*)heap_alloc( NULL, i, HEAP_ALIGN_4 );
  if( section == NULL ) { errc = OSE_NO_MEMORY; goto l_fail; }
  memset( section, 0, i );

  // Read section headers
  if( drv_read( d, section, i ) != i ) { errc = OSE_CANT_READ; goto l_fail; }

  j = 0xffffffff;
  for( i = 0; i < header.scount; i++ )
  {
    if(section[i].vaddr < j) j = section[i].vaddr;
  }

  delta = paddr - j;
  // Read sections data to paddr region with psize limit
  for( i = 0; i < header.scount; i++ )
  {
    if( section[i].flags & LIF_SF_STATIC ) continue;
    if( section[i].length < section[i].size ) { errc = OSE_LIF_BAD_SECTION_HEADER; goto l_fail; }

    section[i].paddr = delta + section[i].vaddr;
    if( (section[i].paddr < paddr) || (section[i].paddr + section[i].length > memlimit) ) { errc = OSE_NO_MEMORY; goto l_fail; }
    if( drv_read( d, (uint8*)section[i].paddr, section[i].size ) != section[i].size ) { errc = OSE_CANT_READ; goto l_fail; }
    memset( (uint8*)section[i].paddr + section[i].size, 0, section[i].length - section[i].size );
    if( section[i].flags & LIF_SF_BSS ) overlay->bss_point = section[i].paddr;
  }

  // Patch section code
  for( i = 0; i < header.scount; i++ )
  {
    // Apply each section patch
    for( j = 0; j < section[i].pcount; j++ )
    {
      if( drv_read( d, &patch, sizeof(s_lif_patch) ) != sizeof(s_lif_patch) ) { errc = OSE_CANT_READ; goto l_fail; }
      if( !lif_patch( i, header.scount, section, patch ) ) { errc = OSE_LIF_CANT_APPLY_PATCH; goto l_fail; }
    }
  }

  drv_rmd( d );

  // Modify entry point
  overlay->entry_point = header.vepoint_offset + section[header.vepoint_snum].paddr;

  // Writeback and invalidate L1P and L1D caches for loaded PO
  os_cache_writeback_invalidate( paddr, psize );

  // Release section headers
  heap_free( NULL, section );

  return OSE_OK;

l_fail:

  drv_rmd( d );

  memset( overlay, 0, sizeof(s_lif_overlay) );

  heap_free( NULL, section );

  return errc;
}
// ---------------------------------------------------------------------------
static int32 lif_link_mem( void* prg_mem, s_lif_overlay* overlay, uint32 paddr, uint32 psize )
{
  s_lif_header header;
  s_lif_patch patch;
  s_lif_section* section = NULL;
  int32 errc;
  uint32 i, j;
  uint32 memlimit = paddr + psize - 1;
  int32 delta;

  // Check params
  if( ( prg_mem == NULL ) || ( overlay == NULL ) ) return OSE_NULL_PARAM;

  char* cur_mem_addr = NULL;
  char *prg_ptr = (char*)prg_mem; 

  // Clear overlay structure
  memset( overlay, 0, sizeof(s_lif_overlay) );

  // Read LIF header and check format
  memcpy(&header,prg_ptr,sizeof(header));
  if( ( header.scount == 0 ) || ( header.magic != 0x3046494c ) || ( header.vepoint_snum >= header.scount ) ) { errc = OSE_LIF_BAD_HEADER; goto l_fail; }
  if( header.target != LIF_TGT_TMS320C64XX ) { errc = OSE_LIF_WRONG_TARGET_CPU; goto l_fail; }
  overlay->stack_size = header.stack;

  i = sizeof(s_lif_section) * header.scount;

  section = (s_lif_section*)(prg_ptr + sizeof(header));//Адрес начала списка заголовков секций
  cur_mem_addr =  (char*)section + i;//Адрес начала самих секций
  
  j = 0xffffffff;
  for( i = 0; i < header.scount; i++ )
  {
    if(section[i].vaddr < j) j = section[i].vaddr;
  }

  delta = paddr - j;
  // Read sections data to paddr region with psize limit

  for( i = 0; i < header.scount; i++ )
  {
    if( section[i].flags & LIF_SF_STATIC ) continue;
    if( section[i].length < section[i].size ) { errc = OSE_LIF_BAD_SECTION_HEADER; goto l_fail; }

    section[i].paddr = delta + section[i].vaddr;
    
    if( (section[i].paddr < paddr) || (section[i].paddr + section[i].length > memlimit) ) { errc = OSE_NO_MEMORY; goto l_fail; }


    memcpy((uint8*)section[i].paddr,cur_mem_addr,section[i].size);
    cur_mem_addr += section[i].size;
    memset( (uint8*)section[i].paddr + section[i].size, 0, section[i].length - section[i].size );
    if( section[i].flags & LIF_SF_BSS ) overlay->bss_point = section[i].paddr;
  }

  // Patch section code
  for( i = 0; i < header.scount; i++ )
  {
    // Apply each section patch
    for( j = 0; j < section[i].pcount; j++ )
    {
      memcpy(&patch,cur_mem_addr,sizeof(s_lif_patch));
      cur_mem_addr += sizeof(s_lif_patch);
      if( !lif_patch( i, header.scount, section, patch ) ) { errc = OSE_LIF_CANT_APPLY_PATCH; goto l_fail; }
    }
  }
  // Modify entry point
  overlay->entry_point = header.vepoint_offset + section[header.vepoint_snum].paddr;

  // Writeback and invalidate L1P and L1D caches for loaded PO
  os_cache_writeback_invalidate( paddr, psize );

  return OSE_OK;

l_fail:

  return errc;
}
// ---------------------------------------------------------------------------
// !: fn: static int32 lif_execute( const char* path, const char* args )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция запускает приложение из устройства/файла path с аргументами
// !: d: args.<br>
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: В случае успеха функция возвращает идентификатор нового процесса
// !: d: (значение строго больше нуля), иначе одну из ошибок:<br><br>
// !: d: <table cellpadding=2 cellspacing=2 border=0>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_NULL_PARAM</td>
// !: d: <td> - </td>
// !: d: <td>один из переданных аргументов fname или overlay равен нулю;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_NO_DEVICE</td>
// !: d: <td> - </td>
// !: d: <td>не найдено устройство или файл из которого запрошена загрузка;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_CANT_OPEN</td>
// !: d: <td> - </td>
// !: d: <td>ошибка открытия устройства или файла из которого запрошена загрузка;</td>
// !: d: </tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_CANT_READ</td>
// !: d: <td> - </td>
// !: d: <td>ошибка чтения из устройства или файла из которого запрошена загрузка;</td>
// !: d: </tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_LIF_BAD_HEADER</td>
// !: d: <td> - </td>
// !: d: <td>плохой заголовок LIF формата;</td>
// !: d: </tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_LIF_WRONG_TARGET_CPU</td>
// !: d: <td> - </td>
// !: d: <td>попытка загрузить бинайрный файл для другой аппаратной архитектуры;</td>
// !: d: </tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_NO_MEMORY</td>
// !: d: <td> - </td>
// !: d: <td>недостаточно памяти для загрузки;</td>
// !: d: </tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_LIF_BAD_SECTION_HEADER</td>
// !: d: <td> - </td>
// !: d: <td>плохой заголовок секции LIF формата;</td>
// !: d: </tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_LIF_CANT_APPLY_PATCH</td>
// !: d: <td> - </td>
// !: d: <td>ошибка применения линковочного патча.</td>
// !: d: </tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_CANT_CREATE_PROCESS</td>
// !: d: <td> - </td>
// !: d: <td>ошибка при создании процесса, для загруженного приложения.</td>
// !: d: </tr>
// !: d: </table><br>
// ---------------------------------------------------------------------------
static int32 lif_execute( const char* path, const char* args )
{
  s_lif_overlay overlay;
  char* targ = NULL;
  int32 targlen;
  s_prc_attr pattr;
  int32 r = OSE_OK;
  register uint32 ps;

  // Form aguments
  targlen = strlen( path ) + 1;
  if( args ) targlen += strlen( args ) + 1;

  targ = new char[targlen];
  if( targ == NULL ) return OSE_NO_MEMORY;

  strcpy( targ, path );
  if( args )
  {
    strcat( targ, " " );
    strcat( targ, args );
  }

  // Load and link binary file
  if( ( r = lif_link( path, &overlay ) ) != OSE_OK )
  {
    delete[] targ;
    return r;
  }

  // Create new process
  memset( &pattr, 0, sizeof(pattr) );
  pattr.bss = overlay.bss_point;
  pattr.stack = overlay.stack_size ? overlay.stack_size : 4096;
  ps = prc_disable();
  if( ( r = prc_create( ((int(*)(void*))overlay.entry_point), targ, targlen, &pattr ) ) > 0 )
  {
    for( int32 i = 0; i < overlay.page_count; i++ )
    {
      if( overlay.page[i] ) overlay.page[i]->pid = (uint16)r;
    }
  }
  else
  {
    r = OSE_CANT_CREATE_PROCESS;
  }
  prc_enable( ps );
  os_lif_free( &overlay );
  delete[] targ;

  return r;
}

static int32 lif_execute_fixed( const char* path, void* prg_mem, const char* args, uint32 paddr, uint32 psize )
{
  s_lif_overlay overlay; // overlay in this special method used only to aquire bss_point, stack_size, entry_point
  int32 r = OSE_OK;

  if(prg_mem == NULL)
  {
    //Load and link binary file
    if( ( r = lif_link_fixed( path, &overlay, paddr, psize ) ) != OSE_OK )
      return r;
  }
  else
  {
    if( ( r = lif_link_mem( prg_mem, &overlay, paddr, psize ) ) != OSE_OK )
      return r;
  }

  char* targ = NULL;
  int32 targlen = 0;
  s_prc_attr pattr;
  register uint32 ps;

  if(path != NULL)
  {
    // Form aguments
    targlen = strlen( path ) + 1;
    if( args ) targlen += strlen( args ) + 1;

    targ = new char[targlen];
    if( targ == NULL ) return OSE_NO_MEMORY;

    strcpy( targ, path );
    if( args )
    { 
      strcat( targ, " " );
      strcat( targ, args );
    }
  }

  // Create new process
  memset( &pattr, 0, sizeof(pattr) );
  pattr.bss = overlay.bss_point;
  pattr.stack = overlay.stack_size ? overlay.stack_size : 4096;
  ps = prc_disable();
  if( ( r = prc_create( ((int(*)(void*))overlay.entry_point), targ, targlen, &pattr ) ) <= 0 )
    r = OSE_CANT_CREATE_PROCESS;
  prc_enable( ps );
  delete[] targ;

  return r;
}
// ---------------------------------------------------------------------------
// !: fn: int32 os_lif_load( const char* fname, const char* args, uint32 type, s_lif_overlay* descriptor )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall псевдоним:</b><br>
// !: d: <br>
// !: d: lif_load<br>
// !: d: <br>
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция выполняет загрузку бинарного файла в LIF формате в одном из
// !: d: режимов type (LIF_EXEC, LIF_LIBRARY, LIF_OVERLAY, LIF_EXTENSION).<br><br> В
// !: d: режиме LIF_EXEC функция запускает на исполнение приложение из
// !: d: устройсва/файла fname, с аргументами args (допустимо значение NULL).
// !: d: В режиме LIF_EXEC указатель descriptor игнорируется.<br><br> В режиме
// !: d: LIF_OVERLAY приложение загружается, но не запускается на исполнение,
// !: d: вся информация о загруженных секциях размещается в структуре на
// !: d: которую ссылается указатель descriptor. В режиме LIF_OVERLAY
// !: d: переменная args игнорируется.<br>
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: В режиме LIF_EXEC функция возвращает значение функции lif_execute.<br>
// !: d: В режиме LIF_OVERLAY функция возвращает значение функции lif_link.<br>
// !: d: В случае если режим загрузки бинарного файла указан не правильно
// !: d: функция возвращает OSE_BAD_PARAM.
// ---------------------------------------------------------------------------
int32 os_lif_load( const char* fname, const char* args, uint32 type, s_lif_overlay* descriptor )
{
  switch( type )
  {
    case LIF_EXEC:
      return lif_execute( fname, args );

    case LIF_LIBRARY:
    {
    }
    break;

    case LIF_OVERLAY:
      return lif_link( fname, descriptor );

    case LIF_EXTENSION:
    {
    }
    break;
  }

  return OSE_BAD_PARAM;
}
// ---------------------------------------------------------------------------
// !: fn: int32 os_lif_load_fixed( const char* fname, void* prg_mem,const char* args, uint32 type, uint32 paddr, uint32 psize )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall псевдоним:</b><br>
// !: d: <br>
// !: d: lif_load<br>
// !: d: <br>
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Специальная версия функции os_lif_load для загрузки приложения в жестко заданную область памяти.<br> 
// !: d: Функция будет загружать секции lif-файла c путем "fanme" или из памяти "prg_mem" в порядке их следования,<br>
// !: d: начиная с заданного физического адреса со смещениями в соответствии с lif-файлом.<br>
// !: d: Все выравнивания и пропуски будут соответствовать содержимому lif-файла.
// !: d: В настоящее время предполагается только режим LIF_EXEC.
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: В режиме LIF_EXEC функция возвращает значение функции lif_execute_fixed.<br>
// !: d: Если режим загрузки бинарного файла указан не правильно,
// !: d: функция возвращает OSE_BAD_PARAM.
// ---------------------------------------------------------------------------
int32 os_lif_load_fixed( const char* fname, void* prg_mem, const char* args, uint32 type, uint32 paddr, uint32 psize )
{

  switch( type )
  {
    case LIF_EXEC:
      return lif_execute_fixed( fname, prg_mem, args, paddr, psize );
  }

  return OSE_BAD_PARAM;
}
// ---------------------------------------------------------------------------
// !: fn: int32 os_lif_unload( s_lif_overlay* descriptor )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall псевдоним:</b><br>
// !: d: <br>
// !: d: lif_unload<br>
// !: d: <br>
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция выгружает из памяти оверлей, информация о котором находится в
// !: d: структуре на которую ссылается указатель descriptor. После выгрузки
// !: d: функция очищает структуру вызовом фнкции lif_free.<br>
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: В случае успеха функция возвращает OSE_OK, иначе одну из ошибок:<br><br>
// !: d: <table cellpadding=2 cellspacing=2 border=0>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_NULL_PARAM</td>
// !: d: <td> - </td>
// !: d: <td>указатель descriptor равен нулю.</td>
// !: d: </tr>
// !: d: </table><br>
// ---------------------------------------------------------------------------
int32 os_lif_unload( s_lif_overlay* descriptor )
{
  if( descriptor == NULL ) return OSE_NULL_PARAM;
  for( int32 i = 0; i < descriptor->page_count; i++ ) mem_free( descriptor->page[i] );
  return os_lif_free( descriptor );
}
// ---------------------------------------------------------------------------
// !: fn: int32 os_lif_free( s_lif_overlay* descriptor )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall псевдоним:</b><br>
// !: d: <br>
// !: d: lif_free<br>
// !: d: <br>
// !: d: <b>Описание:</b><br>
// !: d: <br>
// !: d: Функция освобождает всю динамическую память связанную с описывающей
// !: d: оверлей структурой на которую ссылается указатель descriptor.<br>
// !: d: <br>
// !: d: <b>Возвращаемые значения:</b><br>
// !: d: <br>
// !: d: Функция всегда щавершается успешно и возвращает OSE_OK.
// ---------------------------------------------------------------------------
int32 os_lif_free( s_lif_overlay* descriptor )
{
  if( descriptor == NULL ) return OSE_OK;
  if( descriptor->symbol )
  {
    for( int32 i = 0; i < descriptor->symbol_count; i++ ) delete[] descriptor->symbol->name;
    delete[] descriptor->symbol;
  }
  delete[] descriptor->page;
  memset( descriptor, 0, sizeof(s_lif_overlay) );
  return OSE_OK;
}
