// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp866
// !: d: ����� ᮤ�ন� ॠ������ �㭪権 ࠡ��� � ��⥬�� ⠩��஬,
// !: d: �६���� � ����প���.
// !: -:
// ---------------------------------------------------------------------------
#define SYSCALL_DIRECT
#include <os.h>
// ---------------------------------------------------------------------------

uint64 v_time;
uint64 v_time_core;
uint64 v_time_accumulator;
uint64 v_time_takt_k;
uint32 v_time_lclk;

// ---------------------------------------------------------------------------
// !: fn: void os_time_init_module( int32 stage )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>���ᠭ��:</b><br>
// !: d: <br>
// !: d: �㭪�� ���樠������� ��⥬�� ⠩���� � ����᪠�� ��. ������
// !: d: �㭪�� �� ����㯭� ���짮��⥫�.
// !: -:
// ---------------------------------------------------------------------------
#if defined(CHIP_6412) || defined(CHIP_6416)
void os_time_init_module( int32 stage )
{
  if( stage == 0 )
  {
    // Clear configuration registers
    REG_CTL0 = 0;
    REG_CNT0 = 0;
    REG_CTL1 = 0;
    REG_CNT1 = 0;
    REG_CTL2 = 0;
    REG_CNT2 = 0;
    // Clear counters
    v_time = 0;
    v_time_core = 1;
    v_time_accumulator = 0;
    v_time_lclk = 0;
    v_time_takt_k = 8000000000llu;
  }
  else if( stage == 1 )
  {
    // Configuring processor timers
    REG_PRD0 = sys_quant;
    REG_PRD1 = 0xffffffff;
    // Select source clock signal
    REG_CTL0 = TCTL_SPND | TCTL_CLKSRC | TCTL_HLD | TCTL_GO;
    REG_CTL1 = TCTL_SPND | TCTL_CLKSRC | TCTL_HLD | TCTL_GO;
  }
}
#endif
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
#if defined(CHIP_6457)
void os_time_init_module( int32 stage )
{
  if( stage == 0 )
  {
    // Clear configuration registers
    REG_EMUMGT_CLKSPD0 = 0;
    REG_WDTCR0 = 0;
    REG_TCR0 = TCR_ENAMODE_HI_DISABLED | TCR_ENAMODE_LO_DISABLED;
    REG_TCR1 = TCR_ENAMODE_HI_DISABLED | TCR_ENAMODE_LO_DISABLED;
    // Clear counters
    v_time = 0;
    v_time_core = 1;
    v_time_accumulator = 0;
    v_time_lclk = 0;
    v_time_takt_k = 1000000000ull * (uint64)( ( REG_EMUMGT_CLKSPD0 >> 16 ) & 0x0000000f );
  }
  else if( stage == 1 )
  {
    // Initialize system quant value
    sys_quant = sys_frequency / ( 1000 * ( ( REG_EMUMGT_CLKSPD0 >> 16 ) & 0x0000000f ) );
    // Configuring processor timers
    REG_CNTLO0 = 0;
    REG_CNTHI0 = 0;
    REG_PRDLO0 = sys_quant;
    REG_PRDHI0 = 0xffffffff;
    REG_TCR0 = TCR_ENAMODE_LO_ENABLED | TCR_CLKSRC_LO_INTERNAL | TCR_CP_LO_PULSE | TCR_PWID_LO_1 |
               TCR_ENAMODE_HI_ENABLED | TCR_CP_HI_PULSE | TCR_PWID_HI_1;
    REG_TGCR0 = TGCR_TIMMODE_32UNCHAINED | TGCR_TIMHIRS | TGCR_TIMLORS;
  }
}
#endif
// ---------------------------------------------------------------------------
// !: fn: void os_time_cleanup()
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>���ᠭ��:</b><br>
// !: d: <br>
// !: d: �㭪�� ����頥� �� ���짮��⥫�᪨� ����ᮬ �� ������
// !: d: (�易��� � ����� ���㫥�), ����� �� ���� �᢮������. ������
// !: d: �㭪�� �� ����㯭� ���짮��⥫�.
// !: -:
// ---------------------------------------------------------------------------
void os_time_cleanup()
{
  /* Nothing, yet */
}
// ---------------------------------------------------------------------------
// !: fn: void os_time_update()
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>���ᠭ��:</b><br>
// !: d: <br>
// !: d: �㭪�� �������� ���稪� �६��� ����樮���� ��⥬�. ������
// !: d: �㭪�� �� ����㯭� ���짮��⥫�.
// !: -:
// ---------------------------------------------------------------------------
void os_time_update()
{
  uint32 cclk;
  uint64 delta;
  #if defined(CHIP_6412) || defined(CHIP_6416)
  cclk = REG_CNT1;
  #endif
  #if defined(CHIP_6457)
  cclk = REG_CNTHI0;
  #endif
  v_time_accumulator += (uint64)( cclk - v_time_lclk ) * v_time_takt_k;
  delta = v_time_accumulator / sys_frequency;
  v_time += delta;
  v_time_core += delta;
  v_time_accumulator -= delta * sys_frequency;
  v_time_lclk = cclk;
}
// ---------------------------------------------------------------------------
// !: fn: void os_time_set( uint32 tm )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall �ᥢ�����:</b><br>
// !: d: <br>
// !: d: time_set<br>
// !: d: <br>
// !: d: <b>���ᠭ��:</b><br>
// !: d: <br>
// !: d: �㭪�� ��⠭�������� ��⥬��� �६� � ���祭�� ��६����� tm
// !: d: (UNIX �ଠ�).
// !: -:
// ---------------------------------------------------------------------------
void os_time_set( uint32 tm )
{
  register uint32 is = int_disable();
  v_time = (uint64)tm * 1000000000llu;
  int_enable( is );
}
// ---------------------------------------------------------------------------
// !: fn: uint32 os_time_s()
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall �ᥢ�����:</b><br>
// !: d: <br>
// !: d: time_s<br>
// !: d: <br>
// !: d: <b>�����頥�� ���祭��:</b><br>
// !: d: <br>
// !: d: �㭪�� �����頥� �६� � ᥪ㭤�� �� ��砫� 01.01.1970.
// !: -:
// ---------------------------------------------------------------------------
uint32 os_time_s()
{
  return (uint32)( v_time / 1000000000llu );
}
// ---------------------------------------------------------------------------
// !: fn: uint64 os_time_m()
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall �ᥢ�����:</b><br>
// !: d: <br>
// !: d: time_m<br>
// !: d: <br>
// !: d: <b>�����頥�� ���祭��:</b><br>
// !: d: <br>
// !: d: �㭪�� �����頥� �६� � ����ᥪ㭤�� �� ��砫� 01.01.1970.
// !: -:
// ---------------------------------------------------------------------------
uint64 os_time_m()
{
  return v_time / 1000000llu;
}
// ---------------------------------------------------------------------------
// !: fn: uint64 os_time_u()
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall �ᥢ�����:</b><br>
// !: d: <br>
// !: d: time_u<br>
// !: d: <br>
// !: d: <b>�����頥�� ���祭��:</b><br>
// !: d: <br>
// !: d: �㭪�� �����頥� �६� � ����ᥪ㭤�� �� ��砫� 01.01.1970.
// !: -:
// ---------------------------------------------------------------------------
uint64 os_time_u()
{
  register uint32 is = int_disable();
  os_time_update();
  int_enable( is );
  return v_time / 1000llu;
}
// ---------------------------------------------------------------------------
// !: fn: uint32 os_time_n()
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall �ᥢ�����:</b><br>
// !: d: <br>
// !: d: time_n<br>
// !: d: <br>
// !: d: <b>�����頥�� ���祭��:</b><br>
// !: d: <br>
// !: d: �㭪�� �����頥� �६� � ����ᥪ㭤�� �� ��砫� 01.01.1970.
// !: -:
// ---------------------------------------------------------------------------
uint64 os_time_n()
{
  register uint32 is = int_disable();
  os_time_update();
  int_enable( is );
  return v_time;
}
// ---------------------------------------------------------------------------
// !: fn: uint64 os_time_core()
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall �ᥢ�����:</b><br>
// !: d: <br>
// !: d: time_core<br>
// !: d: <br>
// !: d: <b>�����頥�� ���祭��:</b><br>
// !: d: <br>
// !: d: �㭪�� �����頥� �६� ࠡ��� ��⥬� (�� ������ ����㧪�) �
// !: d: ����ᥪ㭤��.
// !: -:
// ---------------------------------------------------------------------------
uint64 os_time_core()
{
  return v_time_core / 1000000ull;
}
// ---------------------------------------------------------------------------
uint64 os_time_core_n()
{
  return v_time_core;
}
// ---------------------------------------------------------------------------
// !: fn: void os_sleep_s( uint32 s )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall �ᥢ�����:</b><br>
// !: d: <br>
// !: d: sleep_s<br>
// !: d: <br>
// !: d: <b>���ᠭ��:</b><br>
// !: d: <br>
// !: d: �㭪�� ��ॢ���� ⥪�騩 ����� � ���ﭨ� �������� �ᯮ������
// !: d: �� ����� 祬 �� s ᥪ㭤
// !: -:
// ---------------------------------------------------------------------------
void os_sleep_s( uint32 s )
{
  uint32 sem = sem_alloc( 0, NULL );
  if( sem == RES_VOID ) return;
  sem_lock( sem, s * 1000 );
  sem_free( sem );
}
// ---------------------------------------------------------------------------
// !: fn: void os_sleep_m( uint32 ms )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall �ᥢ�����:</b><br>
// !: d: <br>
// !: d: sleep_m<br>
// !: d: <br>
// !: d: <b>���ᠭ��:</b><br>
// !: d: <br>
// !: d: �㭪�� ��ॢ���� ⥪�騩 ����� � ���ﭨ� �������� �ᯮ������
// !: d: �� ����� 祬 �� ms ����ᥪ㭤.
// !: -:
// ---------------------------------------------------------------------------
void os_sleep_m( uint32 ms )
{
  uint32 sem = sem_alloc( 0, NULL );
  if( sem == RES_VOID ) return;
  sem_lock( sem, ms );
  sem_free( sem );
}
// ---------------------------------------------------------------------------
// !: fn: void os_sleep_u( uint32 us )
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: d: <b>Syscall �ᥢ�����:</b><br>
// !: d: <br>
// !: d: sleep_u<br>
// !: d: <br>
// !: d: <b>���ᠭ��:</b><br>
// !: d: <br>
// !: d: �㭪�� �����⢫�� ����প� �� ����� 祬 �� us ����ᥪ㭤. �����
// !: d: �� ���室�� � ���ﭨ� �������� �ᯮ������.
// !: -:
// ---------------------------------------------------------------------------
void os_sleep_u( uint32 us )
{
  uint64 us_start;
  if( us == 0 ) return;
  us_start = time_u();
  while( ( time_u() - us_start ) < (uint64)us );
}
// ---------------------------------------------------------------------------
