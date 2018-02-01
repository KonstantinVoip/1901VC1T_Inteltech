// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: all
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp866
// !: d: Модуль содержит прототипы функций и структуры менеджера динамической
// !: d: загрузки приложений.
// !: -:
// ---------------------------------------------------------------------------
#ifndef __Loadable_Image_Format_H__
#define __Loadable_Image_Format_H__

#include <os_types.h>
#include <os_core.h>

// ---------------------------------------------------------------------------
#define LIF_TGT_TMS320C64XX     0x00000001
#define LIF_TGT_CORTEX_A8       0x00000002

#define LIF_T_EXECUTABLE        0x00000001
#define LIF_T_LIBRARY           0x00000002
#define LIF_T_DRIVER            0x00000003
#define LIF_T_EXTENSION         0x00000004
#define LIF_T_SEED              0xff000001

struct s_lif_header
{
  uint32                        magic;          // File format identificator `LIF0'
  uint32                        type;           // File type (executable,shared library, etc)
  uint32                        target;         // Target processor
  uint32                        length;         // Size of all data in file
  uint32                        vepoint_offset; // Entry point offset
  uint32                        vepoint_snum;   // Entry point section number
  uint32                        version;        // Version of software
  uint32                        revision;       // Revision of software
  uint32                        flags;          // Flags
  uint32                        scount;         // Section count
  uint32                        stack;          // Stack size for architectures without virtual memory
  uint32                        symcount;       // Exported symbols count
  uint32                        btime;          // Build time
  uint32                        reserved[3];
  uint32                        chk[16];        // 64 bytes field for checksumm
};

#define LIF_SF_BSS              0x00000001
#define LIF_SF_METADATA         0x00000002
#define LIF_SF_STATIC           0x00000004

struct s_lif_section
{
  uint32                        magic;          // Section identificator
  uint32                        size;           // Size of section in file
  uint32                        length;         // Section length in memory
  uint32                        vaddr;          // Virtual address of section
  uint32                        paddr;          // Physical address of section
  uint32                        pcount;         // Patch count
  uint32                        flags;          // Section flags
  uint32                        reserved;
};

#define LIF_P_SHIFT( a, b )     ( ( a >> b ) & 0x0000003f )
#define LIF_P_NEG( a, b )       ( ( a >> b ) & 0x00000001 )
#define LIF_P_CADDR( a, b )     ( ( a >> b ) & 0x00000003 )
#define LIF_P_OP( a, b )        ( ( a >> b ) & 0x00000007 )
#define LIF_P_TYPE( a, b )      ( ( a >> b ) & 0x0000000f )

#define LIF_BL_SHIFT            6
#define LIF_BL_NEG              1
#define LIF_BL_RTYPE            2
#define LIF_BL_OP               3

#define LIF_AND                 0
#define LIF_OR                  1
#define LIF_XOR                 2
#define LIF_NAND                3
#define LIF_NOR                 4
#define LIF_EQU                 5

#define LIF_POS                 0
#define LIF_NEG                 1

#define LIF_ABSOLUTE            0
#define LIF_RELATIVE            1
#define LIF_VIRTUAL             2
#define LIF_OFFSET              3

// ---------------------------------------------------------------------------
// Legend
//
//   sof{x} - difference between physical addresses of current section and
//            <x> section
//
//   *{x,t} - convert <x> into <t> address type
//
//              t == 0: *{x,t} = x - vaddr + paddr      ( LIF_ABSOLUTE )
//              t == 1: *{x,t} = x - vaddr              ( LIF_RELATIVE )
//              t == 2: *{x,t} = x                      ( LIF_VIRTUAL  )
//              t == 3: *{x,t} = x + paddr              ( LIF_OFFSET   )
//              t == *: *{x,t} = 0
//
//            vaddr - virtual address off current section
//            paddr - physical address off current section
//
//   op{x,y,t} - calculate logical operation <t> on arguments <x> and <y>:
//
//              t == 0: op{x,y,t} = x & y               ( AND  )
//              t == 1: op{x,y,t} = x | y               ( OR   )
//              t == 2: op{x,y,t} = x ^ y               ( XOR  )
//              t == 3: op{x,y,t} = ~( x & y )          ( NAND )
//              t == 4: op{x,y,t} = ~( x | y )          ( NOR  )
//              t == 5: op{x,y,t} = ~( x ^ y )          ( EQU  )
//              t == *: op{x,y,t} = 0
//
//   <<>>   - encoded left/right shift
//
//   ~x~    - controlled inversion, if <x> == 1 argument after operation must
//            be inverted
//
//   d      - data for patch retrived from address = paddr + patch::offset
//
//   v,a,b  - patch arguments
//
// ---------------------------------------------------------------------------
// Patch method:0 description
//
//  31  30  29  28  27  26  25  24  23  22  21  20  19  18  17  16
// .---.---.---.---.---.---.---.---.---.---.---.---.---.---.---.---.
// | 0   0   0   0 |         a2_s          |n2 |          v_s       
// `---'---'---'---'---'---'---'---'---'---'---'---'---'---'---'---`
//  15  14  13  12  11  10  9   8   7   6   5   4   3   2   1   0
// .---.---.---.---.---.---.---.---.---.---.---.---.---.---.---.---,
//     |         a1_s          |n1 |          d_s          | caddr |
// `---'---'---'---'---'---'---'---'---'---'---'---'---'---'---'---'
//
// d = ( ( d <<>> d_s ) & ~n1~( a <<>> a1_s ) ) | ( ( *{v,caddr} <<>> v_s ) & ~n2~( a <<>> a2_s ) )
// 
// ---------------------------------------------------------------------------
// Patch method:1 description
//
//  31  30  29  28  27  26  25  24  23  22  21  20  19  18  17  16
// .---.---.---.---.---.---.---.---.---.---.---.---.---.---.---.---.
// | 0   0   0   1 |         a2_s          |n2 |          v_s       
// `---'---'---'---'---'---'---'---'---'---'---'---'---'---'---'---`
//  15  14  13  12  11  10  9   8   7   6   5   4   3   2   1   0
// .---.---.---.---.---.---.---.---.---.---.---.---.---.---.---.---,
//     |         a1_s          |n1 |          d_s          | caddr |
// `---'---'---'---'---'---'---'---'---'---'---'---'---'---'---'---'
// 
// d = ( ( d <<>> d_s ) & ~n1~( a <<>> a1_s ) ) | ( ( *{v+sof{b},caddr} <<>> v_s ) & ~n2~( a <<>> a2_s ) )
//
// Note: In this method virtual address of section <b> is used!
// 
// ---------------------------------------------------------------------------
// Patch method:2 description (logical patch)
//
//  31  30  29  28  27  26  25  24  23  22  21  20  19  18  17  16
// .---.---.---.---.---.---.---.---.---.---.---.---.---.---.---.---.
// | 0   0   1   0 |          a_s          |          b_s          |
// `---'---'---'---'---'---'---'---'---'---'---'---'---'---'---'---`
//  15  14  13  12  11  10  9   8   7   6   5   4   3   2   1   0
// .---.---.---.---.---.---.---.---.---.---.---.---.---.---.---.---,
// |    t5     |    t4     |    t3     |    t2     |    t1     | 0 |
// `---'---'---'---'---'---'---'---'---'---'---'---'---'---'---'---'
// 
// d = op{ op{ d, v, t1 }, op{ op{ d <<>> a_s, a, t2 }, op{ d <<>> b_s, b, t3 }, t4 }, t5 }
//
// ---------------------------------------------------------------------------

struct s_lif_patch
{
  uint32                        method;         // Method of patch (encoded formula)
  uint32                        offset;         // offset - offset of patch in section
  uint32                        v;              // v - parameter of patch function
  uint32                        a;              // a - parameter of patch function
  uint32                        b;              // b - parameter of patch function
};

struct s_lif_symbol
{
  char*                         name;           // Name of symbol
  uint32                        address;        // Address of symbol (function/variable)
};

struct s_lif_overlay
{
  uint32                        entry_point;    // Entry point of executable module
  uint32                        bss_point;      // BSS section address
  uint32                        stack_size;     // Stack size
  s_lif_symbol*                 symbol;         // Symbol list
  uint32                        symbol_count;   // Symbol count
  s_os_mem_block**              page;           // Memory page list
  uint32                        page_count;     // Memory page count
};

// -- Load types -------------------------------------------------------------

#define LIF_EXEC                0
#define LIF_LIBRARY             1
#define LIF_OVERLAY             2
#define LIF_EXTENSION           3
// -- Functions --------------------------------------------------------------

extern int32                    os_lif_load( const char* fname, const char* args, uint32 type, s_lif_overlay* descriptor );
extern int32                    os_lif_unload( s_lif_overlay* descriptor );
extern int32                    os_lif_free( s_lif_overlay* descriptor );

extern int32                    os_lif_load_fixed( const char* fname, void* prg_mem, const char* args, uint32 type, uint32 paddr, uint32 psize );

#endif
