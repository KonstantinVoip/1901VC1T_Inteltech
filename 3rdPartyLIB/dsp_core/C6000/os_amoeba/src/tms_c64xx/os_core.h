// -- DO NOT REMOVE ----------------------------------------------------------
// !: arch: tms320c64xx
// !: sarc: all
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// !: codepage: cp866
// !: d: ‡ Ј®«®ў®з­л© д ©«, б®¤Ґа¦ йЁ© аҐЈЁбва®ўго ¬®¤Ґ«м  ЇЇ а в­®Ј® п¤а ,
// !: d: бвагЄвгаг Є®­вҐЄбв  Їа®жҐбб  Ё § Ј®«®ўЄЁ дг­ЄжЁ© гЇа ў«Ґ­Ёп
// !: d: Їа®жҐбб ¬Ё.
// !: -:
// ---------------------------------------------------------------------------
#ifndef __OS_Core_H__
#define __OS_Core_H__

#include <os_types.h>
#include <os_message.h>

// -- Macros for include all code from library -------------------------------

#define OS_TOUCH_CODE() \
  { \
    extern void __os_touch__(); \
    volatile uint32 __os_touch_var0__ = (uint32)&__os_touch__; \
    volatile uint32 __os_touch_var1__ = __os_touch_var0__; \
    __os_touch_var0__ = __os_touch_var1__; \
    __os_touch_var1__ = __os_touch_var0__; \
  }

// -- Heap and memory manager constants --------------------------------------

#define HEAP_ALIGN_4            4
#define HEAP_ALIGN_8            8
#define HEAP_USED               0x80000000
#define HEAP_ALIGN              0x40000000
#define HEAP_SIZE_MASK          0x3fffffff
#define HEAP_END                0xffffffff

#define MPAGE_ALL               0xffffffff

// -- Access to the Control Registers ----------------------------------------

#ifdef _TMS320C6x
#  define CREGISTER cregister
#else
#  define CREGISTER
#endif

extern CREGISTER volatile unsigned int AMR;       
extern CREGISTER volatile unsigned int CSR;       
extern CREGISTER volatile unsigned int GFPGFR;
extern CREGISTER volatile unsigned int ICR;       
extern CREGISTER volatile unsigned int IER;       
extern CREGISTER volatile unsigned int IFR;       
extern CREGISTER volatile unsigned int IRP;       
extern CREGISTER volatile unsigned int ISR;       
extern CREGISTER volatile unsigned int ISTP;  
extern CREGISTER volatile unsigned int NRP;       

// -- External Memory Interface (EMIF) ---------------------------------------

#define REG_EMIFA_GBLCTL        (*(volatile uint32*)0x01800000) 
#define REG_EMIFB_GBLCTL        (*(volatile uint32*)0x01A80000) 

#define REG_EMIFA_CECTL0        (*(volatile uint32*)0x01800008) 
#define REG_EMIFA_CECTL1        (*(volatile uint32*)0x01800004) 
#define REG_EMIFA_CECTL2        (*(volatile uint32*)0x01800010) 
#define REG_EMIFA_CECTL3        (*(volatile uint32*)0x01800014) 

#define REG_EMIFB_CECTL0        (*(volatile uint32*)0x01A80008) 
#define REG_EMIFB_CECTL1        (*(volatile uint32*)0x01A80004) 
#define REG_EMIFB_CECTL2        (*(volatile uint32*)0x01A80010) 
#define REG_EMIFB_CECTL3        (*(volatile uint32*)0x01A80014) 

#define REG_EMIFA_CESEC0        (*(volatile uint32*)0x01800048) 
#define REG_EMIFA_CESEC1        (*(volatile uint32*)0x01800044) 
#define REG_EMIFA_CESEC2        (*(volatile uint32*)0x01800050) 
#define REG_EMIFA_CESEC3        (*(volatile uint32*)0x01800054) 
                
#define REG_EMIFB_CESEC0        (*(volatile uint32*)0x01A80048) 
#define REG_EMIFB_CESEC1        (*(volatile uint32*)0x01A80044) 
#define REG_EMIFB_CESEC2        (*(volatile uint32*)0x01A80050) 
#define REG_EMIFB_CESEC3        (*(volatile uint32*)0x01A80054) 

#define REG_EMIFA_SDTIM         (*(volatile uint32*)0x0180001C)  
#define REG_EMIFB_SDTIM         (*(volatile uint32*)0x01A8001C)  

#define REG_EMIFA_SDEXT         (*(volatile uint32*)0x01800020)  
#define REG_EMIFB_SDEXT         (*(volatile uint32*)0x01A80020)  

#define REG_EMIFA_SDCTL         (*(volatile uint32*)0x01800018)  
#define REG_EMIFB_SDCTL         (*(volatile uint32*)0x01A80018)  

// -- GPIO registers ---------------------------------------------------------

#if defined(CHIP_6412) || defined(CHIP_6416)

#define REG_GPEN                (*(volatile uint32*)0x01B00000)
#define REG_GPDIR               (*(volatile uint32*)0x01B00004)
#define REG_GPVAL               (*(volatile uint32*)0x01B00008)
#define REG_GPDH                (*(volatile uint32*)0x01B00010)
#define REG_GPHM                (*(volatile uint32*)0x01B00014)
#define REG_GPDL                (*(volatile uint32*)0x01B00018)
#define REG_GPLM                (*(volatile uint32*)0x01B0001C)
#define REG_GPGC                (*(volatile uint32*)0x01B00020)
#define REG_GPPOL               (*(volatile uint32*)0x01B00024)

#endif
#if defined(CHIP_6457)

#define REG_GPIO_BINTEN         (*(volatile uint32*)0x02b00008) // GPIO interrupt per bank enable register
#define REG_GPIO_DIR            (*(volatile uint32*)0x02b00010) // GPIO Direction Register
#define REG_GPIO_OUT_DATA       (*(volatile uint32*)0x02b00014) // GPIO Output Data register
#define REG_GPIO_SET_DATA       (*(volatile uint32*)0x02b00018) // GPIO Set Data register
#define REG_GPIO_CLR_DATA       (*(volatile uint32*)0x02b0001c) // GPIO Clear Data Register
#define REG_GPIO_IN_DATA        (*(volatile uint32*)0x02b00020) // GPIO Input Data Register
#define REG_GPIO_SET_RIS_TRIG   (*(volatile uint32*)0x02b00024) // GPIO Set Rising Edge Interrupt Register
#define REG_GPIO_CLR_RIS_TRIG   (*(volatile uint32*)0x02b00028) // GPIO Clear Rising Edge Interrupt Register
#define REG_GPIO_SET_FAL_TRIG   (*(volatile uint32*)0x02b0002c) // GPIO Set Falling Edge Interrupt Register
#define REG_GPIO_CLR_FAL_TRIG   (*(volatile uint32*)0x02b00030) // GPIO Clear Falling Edge Interrupt Register

#endif

// -- McBSP registers --------------------------------------------------------

#define REG_McBSP0_DRR          (*(volatile uint32*)0x018C0000)
#define REG_McBSP0_DXR          (*(volatile uint32*)0x018C0004)
#define REG_McBSP0_SPCR         (*(volatile uint32*)0x018C0008)
#define REG_McBSP0_RCR          (*(volatile uint32*)0x018C000C)
#define REG_McBSP0_XCR          (*(volatile uint32*)0x018C0010)
#define REG_McBSP0_SRGR         (*(volatile uint32*)0x018C0014)
#define REG_McBSP0_MCR          (*(volatile uint32*)0x018C0018)
#define REG_McBSP0_RCER         (*(volatile uint32*)0x018C001C)
#define REG_McBSP0_XCER         (*(volatile uint32*)0x018C0020)
#define REG_McBSP0_PCR          (*(volatile uint32*)0x018C0024)
                                                        
#define REG_McBSP1_DRR          (*(volatile uint32*)0x01900000)
#define REG_McBSP1_DXR          (*(volatile uint32*)0x01900004)
#define REG_McBSP1_SPCR         (*(volatile uint32*)0x01900008)
#define REG_McBSP1_RCR          (*(volatile uint32*)0x0190000C)
#define REG_McBSP1_XCR          (*(volatile uint32*)0x01900010)
#define REG_McBSP1_SRGR         (*(volatile uint32*)0x01900014)
#define REG_McBSP1_MCR          (*(volatile uint32*)0x01900018)
#define REG_McBSP1_RCER         (*(volatile uint32*)0x0190001C)
#define REG_McBSP1_XCER         (*(volatile uint32*)0x01900020)
#define REG_McBSP1_PCR          (*(volatile uint32*)0x01900024)
                                                
#define REG_McBSP2_DRR          (*(volatile uint32*)0x01A40000)
#define REG_McBSP2_DXR          (*(volatile uint32*)0x01A40004)
#define REG_McBSP2_SPCR         (*(volatile uint32*)0x01A40008)
#define REG_McBSP2_RCR          (*(volatile uint32*)0x01A4000C)
#define REG_McBSP2_XCR          (*(volatile uint32*)0x01A40010)
#define REG_McBSP2_SRGR         (*(volatile uint32*)0x01A40014)
#define REG_McBSP2_MCR          (*(volatile uint32*)0x01A40018)
#define REG_McBSP2_RCER         (*(volatile uint32*)0x01A4001C)
#define REG_McBSP2_XCER         (*(volatile uint32*)0x01A40020)
#define REG_McBSP2_PCR          (*(volatile uint32*)0x01A40024)

// -- EDMA registers ---------------------------------------------------------

#define REG_EDMA_EPRH           (*(volatile uint32*)0x01A0FF9C) 
#define REG_EDMA_CIPRH          (*(volatile uint32*)0x01A0FFA4) 
#define REG_EDMA_CIERH          (*(volatile uint32*)0x01A0FFA8) 
#define REG_EDMA_CCERH          (*(volatile uint32*)0x01A0FFAC) 
#define REG_EDMA_ERH            (*(volatile uint32*)0x01A0FFB0) 
#define REG_EDMA_EERH           (*(volatile uint32*)0x01A0FFB4) 
#define REG_EDMA_ECRH           (*(volatile uint32*)0x01A0FFB8) 
#define REG_EDMA_ESRH           (*(volatile uint32*)0x01A0FFBC) 
#define REG_EDMA_PQAR0          (*(volatile uint32*)0x01A0FFC0) 
#define REG_EDMA_PQAR1          (*(volatile uint32*)0x01A0FFC4) 
#define REG_EDMA_PQAR2          (*(volatile uint32*)0x01A0FFC8) 
#define REG_EDMA_PQAR3          (*(volatile uint32*)0x01A0FFCC) 
#define REG_EDMA_EPRL           (*(volatile uint32*)0x01A0FFDC) 
#define REG_EDMA_PQSR           (*(volatile uint32*)0x01A0FFE0) 
#define REG_EDMA_CIPRL          (*(volatile uint32*)0x01A0FFE4) 
#define REG_EDMA_CIERL          (*(volatile uint32*)0x01A0FFE8) 
#define REG_EDMA_CCERL          (*(volatile uint32*)0x01A0FFEC) 
#define REG_EDMA_ERL            (*(volatile uint32*)0x01A0FFF0) 
#define REG_EDMA_EERL           (*(volatile uint32*)0x01A0FFF4) 
#define REG_EDMA_ECRL           (*(volatile uint32*)0x01A0FFF8) 
#define REG_EDMA_ESRL           (*(volatile uint32*)0x01A0FFFC) 

// -- QDMA registers ---------------------------------------------------------

// QDMA registers:
#define REG_QDMA_OPT            (*(volatile uint32*)0x02000000)
#define REG_QDMA_SRC            (*(volatile uint32*)0x02000004)
#define REG_QDMA_CNT            (*(volatile uint32*)0x02000008)
#define REG_QDMA_DST            (*(volatile uint32*)0x0200000C)
#define REG_QDMA_IDX            (*(volatile uint32*)0x02000010)
// QDMA pseudo-registers:
#define REG_QDMA_SOPT           (*(volatile uint32*)0x02000020)
#define REG_QDMA_SSRC           (*(volatile uint32*)0x02000024)
#define REG_QDMA_SCNT           (*(volatile uint32*)0x02000028)
#define REG_QDMA_SDST           (*(volatile uint32*)0x0200002C)
#define REG_QDMA_SIDX           (*(volatile uint32*)0x02000030)

// -- Segmentation fault status ----------------------------------------------

#define OSSF_SEGMENTATION_FAULT         1
#define OSSF_STACK_OVERFLOW             2
#define OSSF_BAD_DESCRIPTOR             3
#define OSSF_UNIMPLEMENTED_SYSCALL      4
#define OSSF_PROTECTION_FAULT           5
//skd add memory fault  12.04.2018
#define OSSF_SDRAMTEST_FAULT            6
#define OSSF_INTERNALRAMTEST_FAULT      7


// -- Structures -------------------------------------------------------------

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Registers set for TMS320C64xx

#if defined(CHIP_6412) || defined(CHIP_6416)
struct s_os_register
{               // Use                          Type
  uint32 a0;    // General purpose              Scratch (local)
  uint32 a1;    // General purpose              Scratch (local)
  uint32 b0;    // General purpose              Scratch (local)
  uint32 b1;    // General purpose              Scratch (local)
  uint32 a2;    // General purpose              Scratch (local)
  uint32 a3;    // General purpose              Scratch (local)
  uint32 b2;    // General purpose              Scratch (local)
  uint32 b3;    // Function return point        Scratch (local)
  uint32 a4;    // General purpose              Scratch (local)
  uint32 a5;    // General purpose              Scratch (local)
  uint32 b4;    // General purpose              Scratch (local)
  uint32 b5;    // General purpose              Scratch (local)
  uint32 a6;    // General purpose              Scratch (local)
  uint32 a7;    // General purpose              Scratch (local)
  uint32 b6;    // General purpose              Scratch (local)
  uint32 b7;    // General purpose              Scratch (local)
  uint32 a8;    // General purpose              Scratch (local)
  uint32 a9;    // General purpose              Scratch (local)
  uint32 b8;    // General purpose              Scratch (local)
  uint32 b9;    // General purpose              Scratch (local)
  uint32 a10;   // General purpose              Preserve (local)
  uint32 a11;   // General purpose              Preserve (local)
  uint32 b10;   // General purpose              Preserve (local)
  uint32 b11;   // General purpose              Preserve (local)
  uint32 a12;   // General purpose              Preserve (local)
  uint32 a13;   // General purpose              Preserve (local)
  uint32 b12;   // General purpose              Preserve (local)
  uint32 _b13;  // General purpose              Preserve (local)
  uint32 a14;   // General purpose              Preserve (local)
  uint32 a15;   // Frame pointer                Preserve (local)
  uint32 b14;   // Data Page pointer (.bss)     Preserve (local)
  uint32 b15;   // Stack pointer                Preserve (local)
  uint32 a16;   // General purpose              Scratch (local)
  uint32 a17;   // General purpose              Scratch (local)
  uint32 b16;   // General purpose              Scratch (local)
  uint32 b17;   // General purpose              Scratch (local)
  uint32 a18;   // General purpose              Scratch (local)
  uint32 a19;   // General purpose              Scratch (local)
  uint32 b18;   // General purpose              Scratch (local)
  uint32 b19;   // General purpose              Scratch (local)
  uint32 a20;   // General purpose              Scratch (local)
  uint32 a21;   // General purpose              Scratch (local)
  uint32 b20;   // General purpose              Scratch (local)
  uint32 b21;   // General purpose              Scratch (local)
  uint32 a22;   // General purpose              Scratch (local)
  uint32 a23;   // General purpose              Scratch (local)
  uint32 b22;   // General purpose              Scratch (local)
  uint32 b23;   // General purpose              Scratch (local)
  uint32 a24;   // General purpose              Scratch (local)
  uint32 a25;   // General purpose              Scratch (local)
  uint32 b24;   // General purpose              Scratch (local)
  uint32 b25;   // General purpose              Scratch (local)
  uint32 a26;   // General purpose              Scratch (local)
  uint32 a27;   // General purpose              Scratch (local)
  uint32 b26;   // General purpose              Scratch (local)
  uint32 b27;   // General purpose              Scratch (local)
  uint32 a28;   // General purpose              Scratch (local)
  uint32 a29;   // General purpose              Scratch (local)
  uint32 b28;   // General purpose              Scratch (local)
  uint32 b29;   // General purpose              Scratch (local)
  uint32 a30;   // General purpose              Scratch (local)
  uint32 a31;   // General purpose              Scratch (local)
  uint32 b30;   // General purpose              Scratch (local)
  uint32 b31;   // General purpose              Scratch (local)
  uint32 amr;   // Addressing Mode Register
};
#endif

#if defined(CHIP_6457)
struct s_os_register
{               // Use                          Type
  uint32 a0;    // General purpose              Scratch (local)
  uint32 a1;    // General purpose              Scratch (local)
  uint32 b0;    // General purpose              Scratch (local)
  uint32 b1;    // General purpose              Scratch (local)
  uint32 a2;    // General purpose              Scratch (local)
  uint32 a3;    // General purpose              Scratch (local)
  uint32 b2;    // General purpose              Scratch (local)
  uint32 b3;    // Function return point        Scratch (local)
  uint32 a4;    // General purpose              Scratch (local)
  uint32 a5;    // General purpose              Scratch (local)
  uint32 b4;    // General purpose              Scratch (local)
  uint32 b5;    // General purpose              Scratch (local)
  uint32 a6;    // General purpose              Scratch (local)
  uint32 a7;    // General purpose              Scratch (local)
  uint32 b6;    // General purpose              Scratch (local)
  uint32 b7;    // General purpose              Scratch (local)
  uint32 a8;    // General purpose              Scratch (local)
  uint32 a9;    // General purpose              Scratch (local)
  uint32 b8;    // General purpose              Scratch (local)
  uint32 b9;    // General purpose              Scratch (local)
  uint32 a10;   // General purpose              Preserve (local)
  uint32 a11;   // General purpose              Preserve (local)
  uint32 b10;   // General purpose              Preserve (local)
  uint32 b11;   // General purpose              Preserve (local)
  uint32 a12;   // General purpose              Preserve (local)
  uint32 a13;   // General purpose              Preserve (local)
  uint32 b12;   // General purpose              Preserve (local)
  uint32 _b13;  // General purpose              Preserve (local)
  uint32 a14;   // General purpose              Preserve (local)
  uint32 a15;   // Frame pointer                Preserve (local)
  uint32 b14;   // Data Page pointer (.bss)     Preserve (local)
  uint32 b15;   // Stack pointer                Preserve (local)
  uint32 a16;   // General purpose              Scratch (local)
  uint32 a17;   // General purpose              Scratch (local)
  uint32 b16;   // General purpose              Scratch (local)
  uint32 b17;   // General purpose              Scratch (local)
  uint32 a18;   // General purpose              Scratch (local)
  uint32 a19;   // General purpose              Scratch (local)
  uint32 b18;   // General purpose              Scratch (local)
  uint32 b19;   // General purpose              Scratch (local)
  uint32 a20;   // General purpose              Scratch (local)
  uint32 a21;   // General purpose              Scratch (local)
  uint32 b20;   // General purpose              Scratch (local)
  uint32 b21;   // General purpose              Scratch (local)
  uint32 a22;   // General purpose              Scratch (local)
  uint32 a23;   // General purpose              Scratch (local)
  uint32 b22;   // General purpose              Scratch (local)
  uint32 b23;   // General purpose              Scratch (local)
  uint32 a24;   // General purpose              Scratch (local)
  uint32 a25;   // General purpose              Scratch (local)
  uint32 b24;   // General purpose              Scratch (local)
  uint32 b25;   // General purpose              Scratch (local)
  uint32 a26;   // General purpose              Scratch (local)
  uint32 a27;   // General purpose              Scratch (local)
  uint32 b26;   // General purpose              Scratch (local)
  uint32 b27;   // General purpose              Scratch (local)
  uint32 a28;   // General purpose              Scratch (local)
  uint32 a29;   // General purpose              Scratch (local)
  uint32 b28;   // General purpose              Scratch (local)
  uint32 b29;   // General purpose              Scratch (local)
  uint32 a30;   // General purpose              Scratch (local)
  uint32 a31;   // General purpose              Scratch (local)
  uint32 b30;   // General purpose              Scratch (local)
  uint32 b31;   // General purpose              Scratch (local)
  uint32 amr;   // Addressing Mode Register
  uint32 tsr;   // Task state register
  uint32 gplya; // GMPY Polynomial-A Side Register
  uint32 gplyb; // GMPY Polynomial-B Side Register
  uint32 ilc;
  uint32 rilc;
  uint32 ssr;
  uint32 csr_sat;
};
#endif

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// System memory block record

#define MEM_READ                0x0001
#define MEM_WRITE               0x0002
#define MEM_EXECUTE             0x0004
#define MEM_SYSTEM              0x0008
#define MEM_SHARED              0x0010
#define MEM_USED                0x8000

struct s_os_mem_block
{
  s_os_mem_block*               prev;   // Previouse memory block
  s_os_mem_block*               next;   // Next memory block
  uint32                        length; // Block length
  uint16                        pid;    // Owner process id
  uint16                        flags;  // Block type and attributes
};

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Locker

struct s_os_process_context;

struct s_os_locker
{
  s_os_process_context*         p;              // Process
  uint32                        s;              // Semaphore resource id
  s_os_locker*                  next;           // Next locked process
  s_os_locker*                  prev;           // Previouse locked process
  int32                         state;          // Semaphore state
  uint64                        unlock_at;      // Unlock process at <unlock_at> time
};

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// List element of process heap

struct s_os_heap
{
  s_os_heap*                    prev;   // Previouse memory block
  s_os_heap*                    next;   // Next memory block
  s_os_mem_block*               block;  // Pointer to memory block
  uint32                        flags;  // Flags
};
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Init core start param
struct s_os_core_init
{
  uint32 core_heap_len; // Размер системного хипа
  uint32 sys_quant;     // Значение периода переключения процессов
  uint32 sem_list_len;  // Длинна списка семафоров по старту (список расширяемый)
  uint32 extram_start;  // Адрес начала внешнего ОЗУ (если равно 0, значит внешнего ОЗУ нет)
  uint32 extram_end;    // Адрес конца  внещнего ОЗУ (если равно 0, значит внешнего ОЗУ нет)
};//12 byte
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
extern const s_os_core_init core_init_cfg;

// Process context
#define PRIORITY_MASK           0x00ff
#define PRIORITY_IDLE           255
#define PRIORITY_MAX            0
#define PRIORITY_MIN            254
#define PFLAG_MASK              0xff00

struct s_os_extension_link;

struct s_os_process_context
{
  s_os_register*                reg;                    // State of registers
  uint16                        id;                     // Process identificator
  uint16                        pflags;                 // Process priority and flags
  uint16                        peff;                   // Process effective priority
  uint16                        pcnt;                   // Process priority counter
  s_os_process_context*         next;                   // Next process in list
  s_os_process_context*         prev;                   // Previouse process in list
  s_os_locker                   locker;                 // Process locker
  s_os_heap*                    heap;                   // List of process memory blocks
  s_os_mem_block*               stack;                  // Process stack
  void*                         arg;                    // Process argument
  int32                         arglen;                 // Length of argument
  uint32                        sfault_code;            // Segmentation fault code
  s_os_process_context*         parent;                 // Parent process
  s_message_process_data        msg;                    // Data for message processing
  int32                         errno;                  // Process <errno>
  s_os_extension_link*          ext_used;               // List of used extensions
  uint32                        join_sem;               // Semaphore for prc_join function
//  int                           (*func)(void*);         // Start process function address
};

struct s_prc_attr
{
  int32                         stack;                  // Stack size
  int32                         heap;                   // Heap size
  int32                         priority;               // Process priority
  uint32                        bss;                    // BSS pointer
  void                          (*exit_vector)();       // Process exit function pointer
};

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Memory and Heap statistics structures

struct s_os_mem_stat
{
  uint64                        total;
  uint64                        used;
  uint64                        free;
  uint32                        c_desc;
  uint32                        c_16_64;
  uint32                        c_64_256;
  uint32                        c_256_1k;
  uint32                        c_1k_4k;
  uint32                        c_4k_16k;
  uint32                        c_16k_64k;
  uint32                        c_64k_256k;
  uint32                        c_256k_1m;
  uint32                        c_1m_inf;
};

struct s_os_heap_stat
{
  uint32                        total;
  uint32                        used;
  uint32                        free;
  uint32                        c_desc;
  uint32                        c_0;
  uint32                        c_4_16;
  uint32                        c_16_64;
  uint32                        c_64_256;
  uint32                        c_256_1k;
  uint32                        c_1k_4k;
  uint32                        c_4k_16k;
  uint32                        c_16k_64k;
  uint32                        c_64k_256k;
  uint32                        c_256k_1m;
  uint32                        c_1m_inf;
};

// -- Command constants ------------------------------------------------------

extern void*                    OS_STACK_BEGIN;
extern void*                    OS_STACK_END;
extern void*                    OS_ISTACK_BEGIN;
extern void*                    OS_ISTACK_END;
extern void*                    OS_MPAGE0_BEGIN;
extern void*                    OS_MPAGE0_END;
extern void*                    OS_MPAGE1_BEGIN;
extern void*                    OS_MPAGE1_END;
extern void*                    OS_MPAGE2_BEGIN;
extern void*                    OS_MPAGE2_END;
extern void*                    OS_MPAGE3_BEGIN;
extern void*                    OS_MPAGE3_END;
extern void*                    OS_NMISTACK_END;

// -- Low layer functions and data -------------------------------------------

extern void                     os_core_initialize_ll();
extern void                     os_process_yield_ll();
extern uint32                   os_process_disable_ll();
extern void                     os_process_enable_ll( uint32 state );

// -- Hi layer functions and data --------------------------------------------

extern s_os_process_context*    v_os_current_process;
extern s_os_process_context*    v_os_process_ring;
extern s_os_process_context     v_os_process_null_context;
extern s_os_register            v_os_irctx_nmi;
extern s_os_register            v_os_irctx;
extern uint32                   v_os_process_count;
extern uint32                   v_os_core_call;
extern uint16                   v_os_swto_pid;
extern void*                    __os_syscall_table__[];
extern int32                    v_os_errno;

extern void                     os_syscall_init_table();
extern void                     os_syscall_copy_table( void* dst, int32 length );
extern void                     os_syscall_sfault_vector();
extern void                     os_initialize_core();
extern void                     os_process_switcher();
extern void                     os_process_switch_to( uint16 pid );
extern int32                    os_process_create( int (*prc_func)(void*), void* arg, int32 arg_len, s_prc_attr* attr );
extern void                     os_process_exit();
extern uint16                   os_process_id();
extern uint16                   os_process_priority();
extern void*                    os_process_arg();
extern int32                    os_process_arg_length();
extern s_os_heap*               os_process_heap();
extern int32                    os_process_set_priority( int32 p );
extern void                     os_process_set_flags( uint16 f );
extern uint16                   os_process_flags();
extern void                     os_process_system();
extern int32                    os_process_join( uint16 pid );
extern s_os_mem_block*          os_mem_alloc( int32 length, uint32 pagenum );
extern void                     os_mem_free( s_os_mem_block* block );
extern void                     os_mem_free_by_pid( uint16 pid );
extern void                     os_mem_stat( s_os_mem_stat* stat );
extern void*                    os_mem_ptr( s_os_mem_block* block );
extern s_os_heap*               os_heap_create( int32 size );
extern void                     os_heap_destroy( s_os_heap* heap );
extern void                     os_heap_init( s_os_heap* heap );
extern void*                    os_heap_alloc( s_os_heap* heap, int32 size, int32 align );
extern void                     os_heap_free( s_os_heap* heap, void* ptr );
extern bool                     os_heap_isin( s_os_heap* heap, void* ptr );
extern void                     os_heap_stat( s_os_heap* heap, s_os_heap_stat* stat );

extern void                     os_cinit();
extern void                     os_sfault( uint32 code );

#endif
