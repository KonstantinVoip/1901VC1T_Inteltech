// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp866
// !: d: ������ �������� ���������� ��������� ������������ �������� ����������.
// !: [os_lif.cpp]
// ---------------------------------------------------------------------------
#define SYSCALL_DIRECT
#include <os.h>
// ---------------------------------------------------------------------------
#define LIF_CODE_ALIGN          32

// ---------------------------------------------------------------------------
// !: fn: static uint32 lif_op( uint32 la, uint32 ra, uint32 type )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>��������:</b><br>
// !: d: <br>
// !: d: ������� ���������� ��������� ���������� �������� type, ����������� ��
// !: d: ���������� la � ra. ���������� ���������� type ����� ����: LIF_AND,
// !: d: LIF_OR, LIF_XOR, LIF_NAND, LIF_NOR ��� LIF_EQU.<br>
// !: d: <br>
// !: d: <b>������������ ��������:</b><br>
// !: d: <br>
// !: d: ���� �������� type ����� ���������� ��������, ������� ����������
// !: d: ��������� ��������� ���������� ��������, ����� 0.
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
// !: d: <b>���ᠭ��:</b><br>
// !: d: <br>
// !: d: �㭪�� �믮���� ������ ᤢ�� ��㬥�� a ����� (��ࠢ�), �
// !: d: ����ᨬ��� �� ���祭�� ��㬥�� type. �᫨ type ��室���� �� ��१��
// !: d: �� 1 �� 31 �믮������ ᤢ�� ����� �� type. �᫨ type ��室���� ��
// !: d: ��१�� �� 32 �� 62 �믮������ ᤢ�� ��ࠢ� �� type - 31. �᫨ type
// !: d: ࠢ�� 0 ᤢ�� �� �믮������. �᫨ type ����� ��� ࠢ�� 63 १����
// !: d: �ᥣ�� 0.<br>
// !: d: <br>
// !: d: <b>�����頥�� ���祭��:</b><br>
// !: d: <br>
// !: d: �㭪�� �����頥� १���� ᤢ��� �᫠ a �� type, � ᮮ⢥��⢨� �
// !: d: ���ᠭ��� �������.
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
// !: d: <b>���ᠭ��:</b><br>
// !: d: <br>
// !: d: �㭪�� ������ ����⮢�� ������� �᫠ a.<br>
// !: d: <br>
// !: d: <b>�����頥�� ���祭��:</b><br>
// !: d: <br>
// !: d: �᫨ type ࠢ�� LIF_POS, �㭪�� �����頥� a, �᫨ type ࠢ��
// !: d: LIF_NEG, �㭪�� �����頥� ����⮢�� ������� a.
// ---------------------------------------------------------------------------
static uint32 lif_neg( uint32 a, uint32 type )
{
  if( type == LIF_POS ) return a;
  return ~a;
}
// ---------------------------------------------------------------------------
// !: fn: static uint32 lif_caddr( uint32 v, uint32 paddr, uint32 vaddr, uint32 type )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>���ᠭ��:</b><br>
// !: d: <br>
// !: d: �㭪�� �����⢫�� �८�ࠧ������ ����㠫쭮�� ���� v �
// !: d: ᮮ⢥��⢨� � ������� ⨯�� �८�ࠧ������ type � ���ᠬ� ��砫�
// !: d: ����㠫쭮� ��࠭��� vaddr � 䨧��᪮� paddr.<br>
// !: d: <br>
// !: d: <b>�����頥�� ���祭��:</b><br>
// !: d: <br>
// !: d: �᫨ type ࠢ�� LIF_ABSOLUTE, �㭪�� �����頥� v - vaddr + paddr.
// !: d: �᫨ type ࠢ�� LIF_RELATIVE, �㭪�� �����頥� v - vaddr.
// !: d: �᫨ type ࠢ�� LIF_VIRTUAL, �㭪�� �����頥� v.
// !: d: �᫨ type ࠢ�� LIF_OFFSET, �㭪�� �����頥� v + paddr.
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
// !: d: <b>���ᠭ��:</b><br>
// !: d: <br>
// !: d: �㭪�� �����⢫�� ���� ���� �㫥���� � ��ࢮ�� ⨯�. <i>���஡��� ���ᠭ�� �㤥� � ᫥����� ������ ���㬥��</i>
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
// !: d: <b>���ᠭ��:</b><br>
// !: d: <br>
// !: d: �㭪�� �����⢫�� ���� ���� ��ண� ⨯�. <i>���஡��� ���ᠭ�� �㤥� � ᫥����� ������ ���㬥��</i>
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
// !: d: <b>���ᠭ��:</b><br>
// !: d: <br>
// !: d: �㭪�� �믮���� ��������� ���� ����, �� ����㧪� LIF �ଠ�.<br>
// !: d: <br>
// !: d: <b>�����頥�� ���祭��:</b><br>
// !: d: <br>
// !: d: �㭪�� �����頥� true � ��砥 �ᯥ� � false �� ������������
// !: d: �믮������ ����.
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
// !: d: <b>���ᠭ��:</b><br>
// !: d: <br>
// !: d: �㭪�� �����⢫�� ����㧪� � ����୮�� 䠩�� � LIF �ଠ�.<br>
// !: d: <br>
// !: d: <b>�����頥�� ���祭��:</b><br>
// !: d: <br>
// !: d: � ��砥 �ᯥ� �㭪�� �����頥� OSE_OK, ���� ���� �� �訡��:<br><br>
// !: d: <table cellpadding=2 cellspacing=2 border=0>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_NULL_PARAM</td>
// !: d: <td> - </td>
// !: d: <td>���� �� ��।����� ��㬥�⮢ fname ��� overlay ࠢ�� ���;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_NO_DEVICE</td>
// !: d: <td> - </td>
// !: d: <td>�� ������� ���ன�⢮ ��� 䠩� �� ���ண� ����襭� ����㧪�;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_CANT_OPEN</td>
// !: d: <td> - </td>
// !: d: <td>�訡�� ������ ���ன�⢠ ��� 䠩�� �� ���ண� ����襭� ����㧪�;</td>
// !: d: </tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_CANT_READ</td>
// !: d: <td> - </td>
// !: d: <td>�訡�� �⥭�� �� ���ன�⢠ ��� 䠩�� �� ���ண� ����襭� ����㧪�;</td>
// !: d: </tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_LIF_BAD_HEADER</td>
// !: d: <td> - </td>
// !: d: <td>���宩 ��������� LIF �ଠ�;</td>
// !: d: </tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_LIF_WRONG_TARGET_CPU</td>
// !: d: <td> - </td>
// !: d: <td>����⪠ ����㧨�� ������� 䠩� ��� ��㣮� �����⭮� ���⥪����;</td>
// !: d: </tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_NO_MEMORY</td>
// !: d: <td> - </td>
// !: d: <td>�������筮 ����� ��� ����㧪�;</td>
// !: d: </tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_LIF_BAD_SECTION_HEADER</td>
// !: d: <td> - </td>
// !: d: <td>���宩 ��������� ᥪ樨 LIF �ଠ�;</td>
// !: d: </tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_LIF_CANT_APPLY_PATCH</td>
// !: d: <td> - </td>
// !: d: <td>�訡�� �ਬ������ �������筮�� ����.</td>
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

  section = (s_lif_section*)(prg_ptr + sizeof(header));//���� ��砫� ᯨ᪠ ���������� ᥪ権
  cur_mem_addr =  (char*)section + i;//���� ��砫� ᠬ�� ᥪ権
  
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
// !: d: <b>���ᠭ��:</b><br>
// !: d: <br>
// !: d: �㭪�� ����᪠�� �ਫ������ �� ���ன�⢠/䠩�� path � ��㬥�⠬�
// !: d: args.<br>
// !: d: <br>
// !: d: <b>�����頥�� ���祭��:</b><br>
// !: d: <br>
// !: d: � ��砥 �ᯥ� �㭪�� �����頥� �����䨪��� ������ �����
// !: d: (���祭�� ��ண� ����� ���), ���� ���� �� �訡��:<br><br>
// !: d: <table cellpadding=2 cellspacing=2 border=0>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_NULL_PARAM</td>
// !: d: <td> - </td>
// !: d: <td>���� �� ��।����� ��㬥�⮢ fname ��� overlay ࠢ�� ���;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_NO_DEVICE</td>
// !: d: <td> - </td>
// !: d: <td>�� ������� ���ன�⢮ ��� 䠩� �� ���ண� ����襭� ����㧪�;</td>
// !: d: </tr>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_CANT_OPEN</td>
// !: d: <td> - </td>
// !: d: <td>�訡�� ������ ���ன�⢠ ��� 䠩�� �� ���ண� ����襭� ����㧪�;</td>
// !: d: </tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_CANT_READ</td>
// !: d: <td> - </td>
// !: d: <td>�訡�� �⥭�� �� ���ன�⢠ ��� 䠩�� �� ���ண� ����襭� ����㧪�;</td>
// !: d: </tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_LIF_BAD_HEADER</td>
// !: d: <td> - </td>
// !: d: <td>���宩 ��������� LIF �ଠ�;</td>
// !: d: </tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_LIF_WRONG_TARGET_CPU</td>
// !: d: <td> - </td>
// !: d: <td>����⪠ ����㧨�� ������� 䠩� ��� ��㣮� �����⭮� ���⥪����;</td>
// !: d: </tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_NO_MEMORY</td>
// !: d: <td> - </td>
// !: d: <td>�������筮 ����� ��� ����㧪�;</td>
// !: d: </tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_LIF_BAD_SECTION_HEADER</td>
// !: d: <td> - </td>
// !: d: <td>���宩 ��������� ᥪ樨 LIF �ଠ�;</td>
// !: d: </tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_LIF_CANT_APPLY_PATCH</td>
// !: d: <td> - </td>
// !: d: <td>�訡�� �ਬ������ �������筮�� ����.</td>
// !: d: </tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_CANT_CREATE_PROCESS</td>
// !: d: <td> - </td>
// !: d: <td>�訡�� �� ᮧ����� �����, ��� ����㦥����� �ਫ������.</td>
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
// !: d: <b>Syscall �ᥢ�����:</b><br>
// !: d: <br>
// !: d: lif_load<br>
// !: d: <br>
// !: d: <b>���ᠭ��:</b><br>
// !: d: <br>
// !: d: �㭪�� �믮���� ����㧪� ����୮�� 䠩�� � LIF �ଠ� � ����� ��
// !: d: ०���� type (LIF_EXEC, LIF_LIBRARY, LIF_OVERLAY, LIF_EXTENSION).<br><br> �
// !: d: ०��� LIF_EXEC �㭪�� ����᪠�� �� �ᯮ������ �ਫ������ ��
// !: d: ���னᢠ/䠩�� fname, � ��㬥�⠬� args (�����⨬� ���祭�� NULL).
// !: d: � ०��� LIF_EXEC 㪠��⥫� descriptor ����������.<br><br> � ०���
// !: d: LIF_OVERLAY �ਫ������ ����㦠����, �� �� ����᪠���� �� �ᯮ������,
// !: d: ��� ���ଠ�� � ����㦥���� ᥪ��� ࠧ��頥��� � ������� ��
// !: d: ������ ��뫠���� 㪠��⥫� descriptor. � ०��� LIF_OVERLAY
// !: d: ��६����� args ����������.<br>
// !: d: <br>
// !: d: <b>�����頥�� ���祭��:</b><br>
// !: d: <br>
// !: d: � ०��� LIF_EXEC �㭪�� �����頥� ���祭�� �㭪樨 lif_execute.<br>
// !: d: � ०��� LIF_OVERLAY �㭪�� �����頥� ���祭�� �㭪樨 lif_link.<br>
// !: d: � ��砥 �᫨ ०�� ����㧪� ����୮�� 䠩�� 㪠��� �� �ࠢ��쭮
// !: d: �㭪�� �����頥� OSE_BAD_PARAM.
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
// !: d: <b>Syscall �ᥢ�����:</b><br>
// !: d: <br>
// !: d: lif_load<br>
// !: d: <br>
// !: d: <b>���ᠭ��:</b><br>
// !: d: <br>
// !: d: ���樠�쭠� ����� �㭪樨 os_lif_load ��� ����㧪� �ਫ������ � ���⪮ �������� ������� �����.<br> 
// !: d: �㭪�� �㤥� ����㦠�� ᥪ樨 lif-䠩�� c ��⥬ "fanme" ��� �� ����� "prg_mem" � ���浪� �� ᫥�������,<br>
// !: d: ��稭�� � ��������� 䨧��᪮�� ���� � ᬥ饭�ﬨ � ᮮ⢥��⢨� � lif-䠩���.<br>
// !: d: �� ��ࠢ������� � �ய�᪨ ���� ᮮ⢥��⢮���� ᮤ�ন���� lif-䠩��.
// !: d: � �����饥 �६� �।���������� ⮫쪮 ०�� LIF_EXEC.
// !: d: <br>
// !: d: <b>�����頥�� ���祭��:</b><br>
// !: d: <br>
// !: d: � ०��� LIF_EXEC �㭪�� �����頥� ���祭�� �㭪樨 lif_execute_fixed.<br>
// !: d: �᫨ ०�� ����㧪� ����୮�� 䠩�� 㪠��� �� �ࠢ��쭮,
// !: d: �㭪�� �����頥� OSE_BAD_PARAM.
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
// !: d: <b>Syscall �ᥢ�����:</b><br>
// !: d: <br>
// !: d: lif_unload<br>
// !: d: <br>
// !: d: <b>���ᠭ��:</b><br>
// !: d: <br>
// !: d: �㭪�� ���㦠�� �� ����� ���૥�, ���ଠ�� � ���஬ ��室���� �
// !: d: ������� �� ������ ��뫠���� 㪠��⥫� descriptor. ��᫥ ���㧪�
// !: d: �㭪�� ��頥� �������� �맮��� 䭪樨 lif_free.<br>
// !: d: <br>
// !: d: <b>�����頥�� ���祭��:</b><br>
// !: d: <br>
// !: d: � ��砥 �ᯥ� �㭪�� �����頥� OSE_OK, ���� ���� �� �訡��:<br><br>
// !: d: <table cellpadding=2 cellspacing=2 border=0>
// !: d: <tr>
// !: d: <td width=32></td>
// !: d: <td>OSE_NULL_PARAM</td>
// !: d: <td> - </td>
// !: d: <td>㪠��⥫� descriptor ࠢ�� ���.</td>
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
// !: d: <b>Syscall �ᥢ�����:</b><br>
// !: d: <br>
// !: d: lif_free<br>
// !: d: <br>
// !: d: <b>���ᠭ��:</b><br>
// !: d: <br>
// !: d: �㭪�� �᢮������� ��� ���������� ������ �易���� � ����뢠�饩
// !: d: ���૥� ������ன �� ������ ��뫠���� 㪠��⥫� descriptor.<br>
// !: d: <br>
// !: d: <b>�����頥�� ���祭��:</b><br>
// !: d: <br>
// !: d: �㭪�� �ᥣ�� 頢��蠥��� �ᯥ譮 � �����頥� OSE_OK.
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
