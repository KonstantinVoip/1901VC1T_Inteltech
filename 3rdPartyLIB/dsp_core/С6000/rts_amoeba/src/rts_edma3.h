#ifndef __RTS_EDMA3_H__
#define __RTS_EDMA3_H__


#include <os.h>


//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------

/* the Field MaKe macro */
#define CSL_FMK(PER_REG_FIELD, val)                                         \
    (((val) << CSL_##PER_REG_FIELD##_SHIFT) & CSL_##PER_REG_FIELD##_MASK)

/* the Field EXTract macro */
#define CSL_FEXT(reg, PER_REG_FIELD)                                        \
    (((reg) & CSL_##PER_REG_FIELD##_MASK) >> CSL_##PER_REG_FIELD##_SHIFT)

/* the Field INSert macro */
#define CSL_FINS(reg, PER_REG_FIELD, val)                                   \
    ((reg) = ((reg) & ~CSL_##PER_REG_FIELD##_MASK)                          \
    | CSL_FMK(PER_REG_FIELD, val))




/* the Field MaKe (Raw) macro */
#define CSL_FMKR(msb, lsb, val)                                             \
    (((val) & ((1 << ((msb) - (lsb) + 1)) - 1)) << (lsb))

/* the Field EXTract (Raw) macro */
#define CSL_FEXTR(reg, msb, lsb)                                            \
    (((reg) >> (lsb)) & ((1 << ((msb) - (lsb) + 1)) - 1))


/* the Field INSert (Raw) macro */
#define CSL_FINSR(reg, msb, lsb, val)                                       \
    ((reg) = ((reg) &~ (((1 << ((msb) - (lsb) + 1)) - 1) << (lsb)))         \
    | CSL_FMKR(msb, lsb, val))







/**************************************************************************\
* Register Overlay Structure for DRA 
\**************************************************************************/
typedef struct
{
    volatile uint32 DRAE;
    volatile uint32 DRAEH;
} CSL_Edma3ccDraRegs;

/**************************************************************************\
* Register Overlay Structure for QUEEVTENTRY
\**************************************************************************/
typedef struct
{
    volatile uint32 QUEEVT_ENTRY[16];
} CSL_Edma3ccQueevtentryRegs;

/**************************************************************************\
* Register Overlay Structure for SHADOW 
\**************************************************************************/
typedef struct
{
    volatile uint32 ER;
    volatile uint32 ERH;
    volatile uint32 ECR;
    volatile uint32 ECRH;
    volatile uint32 ESR;
    volatile uint32 ESRH;
    volatile uint32 CER;
    volatile uint32 CERH;
    volatile uint32 EER;
    volatile uint32 EERH;
    volatile uint32 EECR;
    volatile uint32 EECRH;
    volatile uint32 EESR;
    volatile uint32 EESRH;
    volatile uint32 SER;
    volatile uint32 SERH;
    volatile uint32 SECR;
    volatile uint32 SECRH;
    volatile uint8 RSVD0[8];
    volatile uint32 IER;
    volatile uint32 IERH;
    volatile uint32 IECR;
    volatile uint32 IECRH;
    volatile uint32 IESR;
    volatile uint32 IESRH;
    volatile uint32 IPR;
    volatile uint32 IPRH;
    volatile uint32 ICR;
    volatile uint32 ICRH;
    volatile uint32 IEVAL;
    volatile uint8 RSVD1[4];
    volatile uint32 QER;
    volatile uint32 QEER;
    volatile uint32 QEECR;
    volatile uint32 QEESR;
    volatile uint32 QSER;
    volatile uint32 QSECR;
    volatile uint8 RSVD2[360];
} CSL_Edma3ccShadowRegs;

/**************************************************************************\
* Overlay structure typedef definition
\**************************************************************************/

typedef volatile CSL_Edma3ccShadowRegs  *CSL_EdmaccShadowRegsOvly;

/**************************************************************************\
* Register Overlay Structure for PARAMSET 
\**************************************************************************/
typedef struct
{
    volatile uint32 OPT;
    volatile uint32 SRC;
    volatile uint32 A_B_CNT;
    volatile uint32 DST;
    volatile uint32 SRC_DST_BIDX;
    volatile uint32 LINK_BCNTRLD;
    volatile uint32 SRC_DST_CIDX;
    volatile uint32 CCNT;
} CSL_Edma3ccParamsetRegs;

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct
{
    volatile uint32 PID;
    volatile uint32 CCCFG;
    volatile uint8 RSVD0[248];
    volatile uint32 DCHMAP[64];
    volatile uint32 QCHMAP[8];
    volatile uint8 RSVD1[32];
    volatile uint32 DMAQNUM[8];
    volatile uint32 QDMAQNUM;
    volatile uint8 RSVD2[28];
    volatile uint32 QUETCMAP;
    volatile uint32 QUEPRI;
    volatile uint8 RSVD3[120];
    volatile uint32 EMR;
    volatile uint32 EMRH;
    volatile uint32 EMCR;
    volatile uint32 EMCRH;
    volatile uint32 QEMR;
    volatile uint32 QEMCR;
    volatile uint32 CCERR;
    volatile uint32 CCERRCLR;
    volatile uint32 EEVAL;
    volatile uint8 RSVD4[28];
    CSL_Edma3ccDraRegs DRA[8];
    volatile uint32 QRAE[8];
    volatile uint8 RSVD5[96];
    volatile uint32 QUEEVTENTRY[6][16];
    volatile uint8 RSVD6[128];
    volatile uint32 QSTAT[6];
    volatile uint8 RSVD7[8];
    volatile uint32 QWMTHRA;
    volatile uint32 QWMTHRB;
    volatile uint8 RSVD8[24];
    volatile uint32 CCSTAT;
    volatile uint8 RSVD9[444];
    volatile uint32 MPFAR;
    volatile uint32 MPFSR;
    volatile uint32 MPFCR;
    volatile uint32 MPPAG;
    volatile uint32 MPPA[8];
    volatile uint8 RSVD10[2000];
    volatile uint32 ER;
    volatile uint32 ERH;
    volatile uint32 ECR;
    volatile uint32 ECRH;
    volatile uint32 ESR;
    volatile uint32 ESRH;
    volatile uint32 CER;
    volatile uint32 CERH;
    volatile uint32 EER;
    volatile uint32 EERH;
    volatile uint32 EECR;
    volatile uint32 EECRH;
    volatile uint32 EESR;
    volatile uint32 EESRH;
    volatile uint32 SER;
    volatile uint32 SERH;
    volatile uint32 SECR;
    volatile uint32 SECRH;
    volatile uint8 RSVD11[8];
    volatile uint32 IER;
    volatile uint32 IERH;
    volatile uint32 IECR;
    volatile uint32 IECRH;
    volatile uint32 IESR;
    volatile uint32 IESRH;
    volatile uint32 IPR;
    volatile uint32 IPRH;
    volatile uint32 ICR;
    volatile uint32 ICRH;
    volatile uint32 IEVAL;
    volatile uint8 RSVD12[4];
    volatile uint32 QER;
    volatile uint32 QEER;
    volatile uint32 QEECR;
    volatile uint32 QEESR;
    volatile uint32 QSER;
    volatile uint32 QSECR;
    volatile uint8 RSVD13[3944];
    CSL_Edma3ccShadowRegs SHADOW[8];
    volatile uint8 RSVD14[4096];
    CSL_Edma3ccParamsetRegs PARAMSET[256];
} CSL_Edma3ccRegs;

/**************************************************************************\
* Overlay structure typedef definition
\**************************************************************************/
typedef volatile CSL_Edma3ccRegs  *CSL_Edma3ccRegsOvly;






/**************************************************************************\
* Register Overlay Structure for DFIREG 
\**************************************************************************/
typedef struct  {
    volatile uint32 DFOPT;
    volatile uint32 DFSRC;
    volatile uint32 DFCNT;
    volatile uint32 DFDST;
    volatile uint32 DFBIDX;
    volatile uint32 DFMPPRXY;
    volatile uint8 RSVD0[40];
} CSL_Edma3tcDfiregRegs;

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile uint32 PID;
    volatile uint32 TCCFG;
    volatile uint8 RSVD0[248];
    volatile uint32 TCSTAT;
    volatile uint8 RSVD1[28];
    volatile uint32 ERRSTAT;
    volatile uint32 ERREN;
    volatile uint32 ERRCLR;
    volatile uint32 ERRDET;
    volatile uint32 ERRCMD;
    volatile uint8 RSVD2[12];
    volatile uint32 RDRATE;
    volatile uint8 RSVD3[252];
    volatile uint32 SAOPT;
    volatile uint32 SASRC;
    volatile uint32 SACNT;
    volatile uint32 SADST;
    volatile uint32 SABIDX;
    volatile uint32 SAMPPRXY;
    volatile uint32 SACNTRLD;
    volatile uint32 SASRCBREF;
    volatile uint32 SADSTBREF;
    volatile uint8 RSVD4[28];
    volatile uint32 DFCNTRLD;
    volatile uint32 DFSRCBREF;
    volatile uint32 DFDSTBREF;
    volatile uint8 RSVD5[116];
    CSL_Edma3tcDfiregRegs DFIREG[4];
} CSL_Edma3tcRegs;

/**************************************************************************\
* Overlay structure typedef definition
\**************************************************************************/
typedef volatile CSL_Edma3tcRegs  *CSL_Edma3tcRegsOvly;





/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* PID */

#define CSL_EDMA3CC_PID_PID_MASK         (0xFFFFFFFFu)
#define CSL_EDMA3CC_PID_PID_SHIFT        (0x00000000u)
#define CSL_EDMA3CC_PID_PID_RESETVAL (0x40018B00u)

#define CSL_EDMA3CC_PID_RESETVAL (0x40018B00u)

/* CCCFG */

#define CSL_EDMA3CC_CCCFG_MP_EXIST_MASK  (0x02000000u)
#define CSL_EDMA3CC_CCCFG_MP_EXIST_SHIFT (0x00000019u)
#define CSL_EDMA3CC_CCCFG_MP_EXIST_RESETVAL (0x00000001u)

/*----MP_EXIST Tokens----*/
#define CSL_EDMA3CC_CCCFG_MP_EXIST_INCLUDED (0x00000001u)

#define CSL_EDMA3CC_CCCFG_CHMAP_EXIST_MASK (0x01000000u)
#define CSL_EDMA3CC_CCCFG_CHMAP_EXIST_SHIFT (0x00000018u)
#define CSL_EDMA3CC_CCCFG_CHMAP_EXIST_RESETVAL (0x00000001u)

/*----CHMAP_EXIST Tokens----*/
#define CSL_EDMA3CC_CCCFG_CHMAP_EXIST_INCLUDED (0x00000001u)

#define CSL_EDMA3CC_CCCFG_NUM_REGN_MASK  (0x00300000u)
#define CSL_EDMA3CC_CCCFG_NUM_REGN_SHIFT (0x00000014u)
#define CSL_EDMA3CC_CCCFG_NUM_REGN_RESETVAL (0x00000003u)

/*----NUM_REGN Tokens----*/
#define CSL_EDMA3CC_CCCFG_NUM_REGN_8     (0x00000003u)

#define CSL_EDMA3CC_CCCFG_NUM_EVQUE_MASK (0x00070000u)
#define CSL_EDMA3CC_CCCFG_NUM_EVQUE_SHIFT (0x00000010u)
#define CSL_EDMA3CC_CCCFG_NUM_EVQUE_RESETVAL (0x00000005u)

/*----NUM_EVQUE Tokens----*/
#define CSL_EDMA3CC_CCCFG_NUM_EVQUE_6    (0x00000005u)

#define CSL_EDMA3CC_CCCFG_NUM_PAENTRY_MASK (0x00007000u)
#define CSL_EDMA3CC_CCCFG_NUM_PAENTRY_SHIFT (0x0000000Cu)
#define CSL_EDMA3CC_CCCFG_NUM_PAENTRY_RESETVAL (0x00000004u)

/*----NUM_PAENTRY Tokens----*/
#define CSL_EDMA3CC_CCCFG_NUM_PAENTRY_256 (0x00000004u)

#define CSL_EDMA3CC_CCCFG_NUM_INTCH_MASK (0x00000700u)
#define CSL_EDMA3CC_CCCFG_NUM_INTCH_SHIFT (0x00000008u)
#define CSL_EDMA3CC_CCCFG_NUM_INTCH_RESETVAL (0x00000004u)

/*----NUM_INTCH Tokens----*/
#define CSL_EDMA3CC_CCCFG_NUM_INTCH_64   (0x00000004u)

#define CSL_EDMA3CC_CCCFG_NUM_QDMACH_MASK (0x00000070u)
#define CSL_EDMA3CC_CCCFG_NUM_QDMACH_SHIFT (0x00000004u)
#define CSL_EDMA3CC_CCCFG_NUM_QDMACH_RESETVAL (0x00000004u)

/*----NUM_QDMACH Tokens----*/
#define CSL_EDMA3CC_CCCFG_NUM_QDMACH_8 (0x00000004u)

#define CSL_EDMA3CC_CCCFG_NUM_DMACH_MASK (0x00000007u)
#define CSL_EDMA3CC_CCCFG_NUM_DMACH_SHIFT (0x00000000u)
#define CSL_EDMA3CC_CCCFG_NUM_DMACH_RESETVAL (0x00000005u)

/*----NUM_DMACH Tokens----*/
#define CSL_EDMA3CC_CCCFG_NUM_DMACH_64   (0x00000005u)

#define CSL_EDMA3CC_CCCFG_RESETVAL (0x03354445u)

/* DCHMAP */

#define CSL_EDMA3CC_DCHMAP_PAENTRY_MASK  (0x00003FE0u)
#define CSL_EDMA3CC_DCHMAP_PAENTRY_SHIFT (0x00000005u)
#define CSL_EDMA3CC_DCHMAP_PAENTRY_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_DCHMAP_RESETVAL      (0x00000000u)

/* QCHMAP */

#define CSL_EDMA3CC_QCHMAP_PAENTRY_MASK  (0x00003FE0u)
#define CSL_EDMA3CC_QCHMAP_PAENTRY_SHIFT (0x00000005u)
#define CSL_EDMA3CC_QCHMAP_PAENTRY_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_QCHMAP_TRWORD_MASK   (0x0000001Cu)
#define CSL_EDMA3CC_QCHMAP_TRWORD_SHIFT  (0x00000002u)
#define CSL_EDMA3CC_QCHMAP_TRWORD_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_QCHMAP_RESETVAL      (0x00000000u)

/* DMAQNUM */

#define CSL_EDMA3CC_DMAQNUM_E7_MASK      (0x70000000u)
#define CSL_EDMA3CC_DMAQNUM_E7_SHIFT     (0x0000001Cu)
#define CSL_EDMA3CC_DMAQNUM_E7_RESETVAL  (0x00000000u)

#define CSL_EDMA3CC_DMAQNUM_E6_MASK      (0x07000000u)
#define CSL_EDMA3CC_DMAQNUM_E6_SHIFT     (0x00000018u)
#define CSL_EDMA3CC_DMAQNUM_E6_RESETVAL  (0x00000000u)

#define CSL_EDMA3CC_DMAQNUM_E5_MASK      (0x00700000u)
#define CSL_EDMA3CC_DMAQNUM_E5_SHIFT     (0x00000014u)
#define CSL_EDMA3CC_DMAQNUM_E5_RESETVAL  (0x00000000u)

#define CSL_EDMA3CC_DMAQNUM_E4_MASK      (0x00070000u)
#define CSL_EDMA3CC_DMAQNUM_E4_SHIFT     (0x00000010u)
#define CSL_EDMA3CC_DMAQNUM_E4_RESETVAL  (0x00000000u)

#define CSL_EDMA3CC_DMAQNUM_E3_MASK      (0x00007000u)
#define CSL_EDMA3CC_DMAQNUM_E3_SHIFT     (0x0000000Cu)
#define CSL_EDMA3CC_DMAQNUM_E3_RESETVAL  (0x00000000u)

#define CSL_EDMA3CC_DMAQNUM_E2_MASK      (0x00000700u)
#define CSL_EDMA3CC_DMAQNUM_E2_SHIFT     (0x00000008u)
#define CSL_EDMA3CC_DMAQNUM_E2_RESETVAL  (0x00000000u)

#define CSL_EDMA3CC_DMAQNUM_E1_MASK      (0x00000070u)
#define CSL_EDMA3CC_DMAQNUM_E1_SHIFT     (0x00000004u)
#define CSL_EDMA3CC_DMAQNUM_E1_RESETVAL  (0x00000000u)

#define CSL_EDMA3CC_DMAQNUM_E0_MASK      (0x00000007u)
#define CSL_EDMA3CC_DMAQNUM_E0_SHIFT     (0x00000000u)
#define CSL_EDMA3CC_DMAQNUM_E0_RESETVAL  (0x00000000u)

#define CSL_EDMA3CC_DMAQNUM_RESETVAL     (0x00000000u)

/* QDMAQNUM */

#define CSL_EDMA3CC_QDMAQNUM_E7_MASK (0x70000000u)
#define CSL_EDMA3CC_QDMAQNUM_E7_SHIFT (0x0000001Cu)
#define CSL_EDMA3CC_QDMAQNUM_E7_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_QDMAQNUM_E6_MASK (0x07000000u)
#define CSL_EDMA3CC_QDMAQNUM_E6_SHIFT (0x00000018u)
#define CSL_EDMA3CC_QDMAQNUM_E6_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_QDMAQNUM_E5_MASK (0x00700000u)
#define CSL_EDMA3CC_QDMAQNUM_E5_SHIFT (0x00000014u)
#define CSL_EDMA3CC_QDMAQNUM_E5_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_QDMAQNUM_E4_MASK (0x00070000u)
#define CSL_EDMA3CC_QDMAQNUM_E4_SHIFT (0x00000010u)
#define CSL_EDMA3CC_QDMAQNUM_E4_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_QDMAQNUM_E3_MASK     (0x00007000u)
#define CSL_EDMA3CC_QDMAQNUM_E3_SHIFT    (0x0000000Cu)
#define CSL_EDMA3CC_QDMAQNUM_E3_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_QDMAQNUM_E2_MASK     (0x00000700u)
#define CSL_EDMA3CC_QDMAQNUM_E2_SHIFT    (0x00000008u)
#define CSL_EDMA3CC_QDMAQNUM_E2_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_QDMAQNUM_E1_MASK     (0x00000070u)
#define CSL_EDMA3CC_QDMAQNUM_E1_SHIFT    (0x00000004u)
#define CSL_EDMA3CC_QDMAQNUM_E1_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_QDMAQNUM_E0_MASK     (0x00000007u)
#define CSL_EDMA3CC_QDMAQNUM_E0_SHIFT    (0x00000000u)
#define CSL_EDMA3CC_QDMAQNUM_E0_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_QDMAQNUM_RESETVAL    (0x00000000u)

/* QUETCMAP */
#define CSL_EDMA3CC_QUETCMAP_TCNUMQ5_MASK (0x00700000u)
#define CSL_EDMA3CC_QUETCMAP_TCNUMQ5_SHIFT (0x00000014u)
#define CSL_EDMA3CC_QUETCMAP_TCNUMQ5_RESETVAL (0x00000005u)

#define CSL_EDMA3CC_QUETCMAP_TCNUMQ4_MASK (0x00070000u)
#define CSL_EDMA3CC_QUETCMAP_TCNUMQ4_SHIFT (0x00000010u)
#define CSL_EDMA3CC_QUETCMAP_TCNUMQ4_RESETVAL (0x00000004u)

#define CSL_EDMA3CC_QUETCMAP_TCNUMQ3_MASK (0x00007000u)
#define CSL_EDMA3CC_QUETCMAP_TCNUMQ3_SHIFT (0x0000000Cu)
#define CSL_EDMA3CC_QUETCMAP_TCNUMQ3_RESETVAL (0x00000003u)

#define CSL_EDMA3CC_QUETCMAP_TCNUMQ2_MASK (0x00000700u)
#define CSL_EDMA3CC_QUETCMAP_TCNUMQ2_SHIFT (0x00000008u)
#define CSL_EDMA3CC_QUETCMAP_TCNUMQ2_RESETVAL (0x00000002u)

#define CSL_EDMA3CC_QUETCMAP_TCNUMQ1_MASK (0x00000070u)
#define CSL_EDMA3CC_QUETCMAP_TCNUMQ1_SHIFT (0x00000004u)
#define CSL_EDMA3CC_QUETCMAP_TCNUMQ1_RESETVAL (0x00000001u)

#define CSL_EDMA3CC_QUETCMAP_TCNUMQ0_MASK (0x00000007u)
#define CSL_EDMA3CC_QUETCMAP_TCNUMQ0_SHIFT (0x00000000u)
#define CSL_EDMA3CC_QUETCMAP_TCNUMQ0_RESETVAL (0x00000000u)
#define CSL_EDMA3CC_QUETCMAP_RESETVAL (0x00543210u)

/* QUEPRI */

#define CSL_EDMA3CC_QUEPRI_PRIQ5_MASK (0x00700000u)
#define CSL_EDMA3CC_QUEPRI_PRIQ5_SHIFT (0x00000014u)
#define CSL_EDMA3CC_QUEPRI_PRIQ5_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_QUEPRI_PRIQ4_MASK (0x00070000u)
#define CSL_EDMA3CC_QUEPRI_PRIQ4_SHIFT (0x00000010u)
#define CSL_EDMA3CC_QUEPRI_PRIQ4_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_QUEPRI_PRIQ3_MASK    (0x00007000u)
#define CSL_EDMA3CC_QUEPRI_PRIQ3_SHIFT   (0x0000000Cu)
#define CSL_EDMA3CC_QUEPRI_PRIQ3_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_QUEPRI_PRIQ2_MASK    (0x00000700u)
#define CSL_EDMA3CC_QUEPRI_PRIQ2_SHIFT   (0x00000008u)
#define CSL_EDMA3CC_QUEPRI_PRIQ2_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_QUEPRI_PRIQ1_MASK    (0x00000070u)
#define CSL_EDMA3CC_QUEPRI_PRIQ1_SHIFT   (0x00000004u)
#define CSL_EDMA3CC_QUEPRI_PRIQ1_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_QUEPRI_PRIQ0_MASK    (0x00000007u)
#define CSL_EDMA3CC_QUEPRI_PRIQ0_SHIFT   (0x00000000u)
#define CSL_EDMA3CC_QUEPRI_PRIQ0_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_QUEPRI_RESETVAL      (0x00000000u)

/* EMR */

#define CSL_EDMA3CC_EMR_E31_MASK         (0x80000000u)
#define CSL_EDMA3CC_EMR_E31_SHIFT        (0x0000001Fu)
#define CSL_EDMA3CC_EMR_E31_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_EMR_E30_MASK         (0x40000000u)
#define CSL_EDMA3CC_EMR_E30_SHIFT        (0x0000001Eu)
#define CSL_EDMA3CC_EMR_E30_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_EMR_E29_MASK         (0x20000000u)
#define CSL_EDMA3CC_EMR_E29_SHIFT        (0x0000001Du)
#define CSL_EDMA3CC_EMR_E29_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_EMR_E28_MASK         (0x10000000u)
#define CSL_EDMA3CC_EMR_E28_SHIFT        (0x0000001Cu)
#define CSL_EDMA3CC_EMR_E28_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_EMR_E27_MASK         (0x08000000u)
#define CSL_EDMA3CC_EMR_E27_SHIFT        (0x0000001Bu)
#define CSL_EDMA3CC_EMR_E27_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_EMR_E26_MASK         (0x04000000u)
#define CSL_EDMA3CC_EMR_E26_SHIFT        (0x0000001Au)
#define CSL_EDMA3CC_EMR_E26_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_EMR_E25_MASK         (0x02000000u)
#define CSL_EDMA3CC_EMR_E25_SHIFT        (0x00000019u)
#define CSL_EDMA3CC_EMR_E25_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_EMR_E24_MASK         (0x01000000u)
#define CSL_EDMA3CC_EMR_E24_SHIFT        (0x00000018u)
#define CSL_EDMA3CC_EMR_E24_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_EMR_E23_MASK         (0x00800000u)
#define CSL_EDMA3CC_EMR_E23_SHIFT        (0x00000017u)
#define CSL_EDMA3CC_EMR_E23_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_EMR_E22_MASK         (0x00400000u)
#define CSL_EDMA3CC_EMR_E22_SHIFT        (0x00000016u)
#define CSL_EDMA3CC_EMR_E22_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_EMR_E21_MASK         (0x00200000u)
#define CSL_EDMA3CC_EMR_E21_SHIFT        (0x00000015u)
#define CSL_EDMA3CC_EMR_E21_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_EMR_E20_MASK         (0x00100000u)
#define CSL_EDMA3CC_EMR_E20_SHIFT        (0x00000014u)
#define CSL_EDMA3CC_EMR_E20_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_EMR_E19_MASK         (0x00080000u)
#define CSL_EDMA3CC_EMR_E19_SHIFT        (0x00000013u)
#define CSL_EDMA3CC_EMR_E19_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_EMR_E18_MASK         (0x00040000u)
#define CSL_EDMA3CC_EMR_E18_SHIFT        (0x00000012u)
#define CSL_EDMA3CC_EMR_E18_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_EMR_E17_MASK         (0x00020000u)
#define CSL_EDMA3CC_EMR_E17_SHIFT        (0x00000011u)
#define CSL_EDMA3CC_EMR_E17_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_EMR_E16_MASK         (0x00010000u)
#define CSL_EDMA3CC_EMR_E16_SHIFT        (0x00000010u)
#define CSL_EDMA3CC_EMR_E16_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_EMR_E15_MASK         (0x00008000u)
#define CSL_EDMA3CC_EMR_E15_SHIFT        (0x0000000Fu)
#define CSL_EDMA3CC_EMR_E15_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_EMR_E14_MASK         (0x00004000u)
#define CSL_EDMA3CC_EMR_E14_SHIFT        (0x0000000Eu)
#define CSL_EDMA3CC_EMR_E14_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_EMR_E13_MASK         (0x00002000u)
#define CSL_EDMA3CC_EMR_E13_SHIFT        (0x0000000Du)
#define CSL_EDMA3CC_EMR_E13_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_EMR_E12_MASK         (0x00001000u)
#define CSL_EDMA3CC_EMR_E12_SHIFT        (0x0000000Cu)
#define CSL_EDMA3CC_EMR_E12_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_EMR_E11_MASK         (0x00000800u)
#define CSL_EDMA3CC_EMR_E11_SHIFT        (0x0000000Bu)
#define CSL_EDMA3CC_EMR_E11_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_EMR_E10_MASK         (0x00000400u)
#define CSL_EDMA3CC_EMR_E10_SHIFT        (0x0000000Au)
#define CSL_EDMA3CC_EMR_E10_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_EMR_E9_MASK          (0x00000200u)
#define CSL_EDMA3CC_EMR_E9_SHIFT         (0x00000009u)
#define CSL_EDMA3CC_EMR_E9_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_EMR_E8_MASK          (0x00000100u)
#define CSL_EDMA3CC_EMR_E8_SHIFT         (0x00000008u)
#define CSL_EDMA3CC_EMR_E8_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_EMR_E7_MASK          (0x00000080u)
#define CSL_EDMA3CC_EMR_E7_SHIFT         (0x00000007u)
#define CSL_EDMA3CC_EMR_E7_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_EMR_E6_MASK          (0x00000040u)
#define CSL_EDMA3CC_EMR_E6_SHIFT         (0x00000006u)
#define CSL_EDMA3CC_EMR_E6_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_EMR_E5_MASK          (0x00000020u)
#define CSL_EDMA3CC_EMR_E5_SHIFT         (0x00000005u)
#define CSL_EDMA3CC_EMR_E5_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_EMR_E4_MASK          (0x00000010u)
#define CSL_EDMA3CC_EMR_E4_SHIFT         (0x00000004u)
#define CSL_EDMA3CC_EMR_E4_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_EMR_E3_MASK          (0x00000008u)
#define CSL_EDMA3CC_EMR_E3_SHIFT         (0x00000003u)
#define CSL_EDMA3CC_EMR_E3_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_EMR_E2_MASK          (0x00000004u)
#define CSL_EDMA3CC_EMR_E2_SHIFT         (0x00000002u)
#define CSL_EDMA3CC_EMR_E2_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_EMR_E1_MASK          (0x00000002u)
#define CSL_EDMA3CC_EMR_E1_SHIFT         (0x00000001u)
#define CSL_EDMA3CC_EMR_E1_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_EMR_E0_MASK          (0x00000001u)
#define CSL_EDMA3CC_EMR_E0_SHIFT         (0x00000000u)
#define CSL_EDMA3CC_EMR_E0_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_EMR_RESETVAL         (0x00000000u)

/* EMRH */

#define CSL_EDMA3CC_EMRH_E63_MASK        (0x80000000u)
#define CSL_EDMA3CC_EMRH_E63_SHIFT       (0x0000001Fu)
#define CSL_EDMA3CC_EMRH_E63_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EMRH_E62_MASK        (0x40000000u)
#define CSL_EDMA3CC_EMRH_E62_SHIFT       (0x0000001Eu)
#define CSL_EDMA3CC_EMRH_E62_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EMRH_E61_MASK        (0x20000000u)
#define CSL_EDMA3CC_EMRH_E61_SHIFT       (0x0000001Du)
#define CSL_EDMA3CC_EMRH_E61_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EMRH_E60_MASK        (0x10000000u)
#define CSL_EDMA3CC_EMRH_E60_SHIFT       (0x0000001Cu)
#define CSL_EDMA3CC_EMRH_E60_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EMRH_E59_MASK        (0x08000000u)
#define CSL_EDMA3CC_EMRH_E59_SHIFT       (0x0000001Bu)
#define CSL_EDMA3CC_EMRH_E59_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EMRH_E58_MASK        (0x04000000u)
#define CSL_EDMA3CC_EMRH_E58_SHIFT       (0x0000001Au)
#define CSL_EDMA3CC_EMRH_E58_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EMRH_E57_MASK        (0x02000000u)
#define CSL_EDMA3CC_EMRH_E57_SHIFT       (0x00000019u)
#define CSL_EDMA3CC_EMRH_E57_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EMRH_E56_MASK        (0x01000000u)
#define CSL_EDMA3CC_EMRH_E56_SHIFT       (0x00000018u)
#define CSL_EDMA3CC_EMRH_E56_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EMRH_E55_MASK        (0x00800000u)
#define CSL_EDMA3CC_EMRH_E55_SHIFT       (0x00000017u)
#define CSL_EDMA3CC_EMRH_E55_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EMRH_E54_MASK        (0x00400000u)
#define CSL_EDMA3CC_EMRH_E54_SHIFT       (0x00000016u)
#define CSL_EDMA3CC_EMRH_E54_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EMRH_E53_MASK        (0x00200000u)
#define CSL_EDMA3CC_EMRH_E53_SHIFT       (0x00000015u)
#define CSL_EDMA3CC_EMRH_E53_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EMRH_E52_MASK        (0x00100000u)
#define CSL_EDMA3CC_EMRH_E52_SHIFT       (0x00000014u)
#define CSL_EDMA3CC_EMRH_E52_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EMRH_E51_MASK        (0x00080000u)
#define CSL_EDMA3CC_EMRH_E51_SHIFT       (0x00000013u)
#define CSL_EDMA3CC_EMRH_E51_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EMRH_E50_MASK        (0x00040000u)
#define CSL_EDMA3CC_EMRH_E50_SHIFT       (0x00000012u)
#define CSL_EDMA3CC_EMRH_E50_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EMRH_E49_MASK        (0x00020000u)
#define CSL_EDMA3CC_EMRH_E49_SHIFT       (0x00000011u)
#define CSL_EDMA3CC_EMRH_E49_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EMRH_E48_MASK        (0x00010000u)
#define CSL_EDMA3CC_EMRH_E48_SHIFT       (0x00000010u)
#define CSL_EDMA3CC_EMRH_E48_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EMRH_E47_MASK        (0x00008000u)
#define CSL_EDMA3CC_EMRH_E47_SHIFT       (0x0000000Fu)
#define CSL_EDMA3CC_EMRH_E47_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EMRH_E46_MASK        (0x00004000u)
#define CSL_EDMA3CC_EMRH_E46_SHIFT       (0x0000000Eu)
#define CSL_EDMA3CC_EMRH_E46_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EMRH_E45_MASK        (0x00002000u)
#define CSL_EDMA3CC_EMRH_E45_SHIFT       (0x0000000Du)
#define CSL_EDMA3CC_EMRH_E45_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EMRH_E44_MASK        (0x00001000u)
#define CSL_EDMA3CC_EMRH_E44_SHIFT       (0x0000000Cu)
#define CSL_EDMA3CC_EMRH_E44_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EMRH_E43_MASK        (0x00000800u)
#define CSL_EDMA3CC_EMRH_E43_SHIFT       (0x0000000Bu)
#define CSL_EDMA3CC_EMRH_E43_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EMRH_E42_MASK        (0x00000400u)
#define CSL_EDMA3CC_EMRH_E42_SHIFT       (0x0000000Au)
#define CSL_EDMA3CC_EMRH_E42_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EMRH_E41_MASK        (0x00000200u)
#define CSL_EDMA3CC_EMRH_E41_SHIFT       (0x00000009u)
#define CSL_EDMA3CC_EMRH_E41_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EMRH_E40_MASK        (0x00000100u)
#define CSL_EDMA3CC_EMRH_E40_SHIFT       (0x00000008u)
#define CSL_EDMA3CC_EMRH_E40_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EMRH_E39_MASK        (0x00000080u)
#define CSL_EDMA3CC_EMRH_E39_SHIFT       (0x00000007u)
#define CSL_EDMA3CC_EMRH_E39_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EMRH_E38_MASK        (0x00000040u)
#define CSL_EDMA3CC_EMRH_E38_SHIFT       (0x00000006u)
#define CSL_EDMA3CC_EMRH_E38_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EMRH_E37_MASK        (0x00000020u)
#define CSL_EDMA3CC_EMRH_E37_SHIFT       (0x00000005u)
#define CSL_EDMA3CC_EMRH_E37_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EMRH_E36_MASK        (0x00000010u)
#define CSL_EDMA3CC_EMRH_E36_SHIFT       (0x00000004u)
#define CSL_EDMA3CC_EMRH_E36_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EMRH_E35_MASK        (0x00000008u)
#define CSL_EDMA3CC_EMRH_E35_SHIFT       (0x00000003u)
#define CSL_EDMA3CC_EMRH_E35_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EMRH_E34_MASK        (0x00000004u)
#define CSL_EDMA3CC_EMRH_E34_SHIFT       (0x00000002u)
#define CSL_EDMA3CC_EMRH_E34_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EMRH_E33_MASK        (0x00000002u)
#define CSL_EDMA3CC_EMRH_E33_SHIFT       (0x00000001u)
#define CSL_EDMA3CC_EMRH_E33_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EMRH_E32_MASK        (0x00000001u)
#define CSL_EDMA3CC_EMRH_E32_SHIFT       (0x00000000u)
#define CSL_EDMA3CC_EMRH_E32_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EMRH_RESETVAL        (0x00000000u)

/* EMCR */

#define CSL_EDMA3CC_EMCR_E31_MASK        (0x80000000u)
#define CSL_EDMA3CC_EMCR_E31_SHIFT       (0x0000001Fu)
#define CSL_EDMA3CC_EMCR_E31_RESETVAL    (0x00000000u)

/*----E31 Tokens----*/
#define CSL_EDMA3CC_EMCR_E31_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_EMCR_E30_MASK        (0x40000000u)
#define CSL_EDMA3CC_EMCR_E30_SHIFT       (0x0000001Eu)
#define CSL_EDMA3CC_EMCR_E30_RESETVAL    (0x00000000u)

/*----E30 Tokens----*/
#define CSL_EDMA3CC_EMCR_E30_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_EMCR_E29_MASK        (0x20000000u)
#define CSL_EDMA3CC_EMCR_E29_SHIFT       (0x0000001Du)
#define CSL_EDMA3CC_EMCR_E29_RESETVAL    (0x00000000u)

/*----E29 Tokens----*/
#define CSL_EDMA3CC_EMCR_E29_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_EMCR_E28_MASK        (0x10000000u)
#define CSL_EDMA3CC_EMCR_E28_SHIFT       (0x0000001Cu)
#define CSL_EDMA3CC_EMCR_E28_RESETVAL    (0x00000000u)

/*----E28 Tokens----*/
#define CSL_EDMA3CC_EMCR_E28_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_EMCR_E27_MASK        (0x08000000u)
#define CSL_EDMA3CC_EMCR_E27_SHIFT       (0x0000001Bu)
#define CSL_EDMA3CC_EMCR_E27_RESETVAL    (0x00000000u)

/*----E27 Tokens----*/
#define CSL_EDMA3CC_EMCR_E27_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_EMCR_E26_MASK        (0x04000000u)
#define CSL_EDMA3CC_EMCR_E26_SHIFT       (0x0000001Au)
#define CSL_EDMA3CC_EMCR_E26_RESETVAL    (0x00000000u)

/*----E26 Tokens----*/
#define CSL_EDMA3CC_EMCR_E26_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_EMCR_E25_MASK        (0x02000000u)
#define CSL_EDMA3CC_EMCR_E25_SHIFT       (0x00000019u)
#define CSL_EDMA3CC_EMCR_E25_RESETVAL    (0x00000000u)

/*----E25 Tokens----*/
#define CSL_EDMA3CC_EMCR_E25_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_EMCR_E24_MASK        (0x01000000u)
#define CSL_EDMA3CC_EMCR_E24_SHIFT       (0x00000018u)
#define CSL_EDMA3CC_EMCR_E24_RESETVAL    (0x00000000u)

/*----E24 Tokens----*/
#define CSL_EDMA3CC_EMCR_E24_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_EMCR_E23_MASK        (0x00800000u)
#define CSL_EDMA3CC_EMCR_E23_SHIFT       (0x00000017u)
#define CSL_EDMA3CC_EMCR_E23_RESETVAL    (0x00000000u)

/*----E23 Tokens----*/
#define CSL_EDMA3CC_EMCR_E23_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_EMCR_E22_MASK        (0x00400000u)
#define CSL_EDMA3CC_EMCR_E22_SHIFT       (0x00000016u)
#define CSL_EDMA3CC_EMCR_E22_RESETVAL    (0x00000000u)

/*----E22 Tokens----*/
#define CSL_EDMA3CC_EMCR_E22_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_EMCR_E21_MASK        (0x00200000u)
#define CSL_EDMA3CC_EMCR_E21_SHIFT       (0x00000015u)
#define CSL_EDMA3CC_EMCR_E21_RESETVAL    (0x00000000u)

/*----E21 Tokens----*/
#define CSL_EDMA3CC_EMCR_E21_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_EMCR_E20_MASK        (0x00100000u)
#define CSL_EDMA3CC_EMCR_E20_SHIFT       (0x00000014u)
#define CSL_EDMA3CC_EMCR_E20_RESETVAL    (0x00000000u)

/*----E20 Tokens----*/
#define CSL_EDMA3CC_EMCR_E20_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_EMCR_E19_MASK        (0x00080000u)
#define CSL_EDMA3CC_EMCR_E19_SHIFT       (0x00000013u)
#define CSL_EDMA3CC_EMCR_E19_RESETVAL    (0x00000000u)

/*----E19 Tokens----*/
#define CSL_EDMA3CC_EMCR_E19_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_EMCR_E18_MASK        (0x00040000u)
#define CSL_EDMA3CC_EMCR_E18_SHIFT       (0x00000012u)
#define CSL_EDMA3CC_EMCR_E18_RESETVAL    (0x00000000u)

/*----E18 Tokens----*/
#define CSL_EDMA3CC_EMCR_E18_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_EMCR_E17_MASK        (0x00020000u)
#define CSL_EDMA3CC_EMCR_E17_SHIFT       (0x00000011u)
#define CSL_EDMA3CC_EMCR_E17_RESETVAL    (0x00000000u)

/*----E17 Tokens----*/
#define CSL_EDMA3CC_EMCR_E17_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_EMCR_E16_MASK        (0x00010000u)
#define CSL_EDMA3CC_EMCR_E16_SHIFT       (0x00000010u)
#define CSL_EDMA3CC_EMCR_E16_RESETVAL    (0x00000000u)

/*----E16 Tokens----*/
#define CSL_EDMA3CC_EMCR_E16_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_EMCR_E15_MASK        (0x00008000u)
#define CSL_EDMA3CC_EMCR_E15_SHIFT       (0x0000000Fu)
#define CSL_EDMA3CC_EMCR_E15_RESETVAL    (0x00000000u)

/*----E15 Tokens----*/
#define CSL_EDMA3CC_EMCR_E15_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_EMCR_E14_MASK        (0x00004000u)
#define CSL_EDMA3CC_EMCR_E14_SHIFT       (0x0000000Eu)
#define CSL_EDMA3CC_EMCR_E14_RESETVAL    (0x00000000u)

/*----E14 Tokens----*/
#define CSL_EDMA3CC_EMCR_E14_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_EMCR_E13_MASK        (0x00002000u)
#define CSL_EDMA3CC_EMCR_E13_SHIFT       (0x0000000Du)
#define CSL_EDMA3CC_EMCR_E13_RESETVAL    (0x00000000u)

/*----E13 Tokens----*/
#define CSL_EDMA3CC_EMCR_E13_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_EMCR_E12_MASK        (0x00001000u)
#define CSL_EDMA3CC_EMCR_E12_SHIFT       (0x0000000Cu)
#define CSL_EDMA3CC_EMCR_E12_RESETVAL    (0x00000000u)

/*----E12 Tokens----*/
#define CSL_EDMA3CC_EMCR_E12_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_EMCR_E11_MASK        (0x00000800u)
#define CSL_EDMA3CC_EMCR_E11_SHIFT       (0x0000000Bu)
#define CSL_EDMA3CC_EMCR_E11_RESETVAL    (0x00000000u)

/*----E11 Tokens----*/
#define CSL_EDMA3CC_EMCR_E11_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_EMCR_E10_MASK        (0x00000400u)
#define CSL_EDMA3CC_EMCR_E10_SHIFT       (0x0000000Au)
#define CSL_EDMA3CC_EMCR_E10_RESETVAL    (0x00000000u)

/*----E10 Tokens----*/
#define CSL_EDMA3CC_EMCR_E10_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_EMCR_E9_MASK         (0x00000200u)
#define CSL_EDMA3CC_EMCR_E9_SHIFT        (0x00000009u)
#define CSL_EDMA3CC_EMCR_E9_RESETVAL     (0x00000000u)

/*----E9 Tokens----*/
#define CSL_EDMA3CC_EMCR_E9_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_EMCR_E8_MASK         (0x00000100u)
#define CSL_EDMA3CC_EMCR_E8_SHIFT        (0x00000008u)
#define CSL_EDMA3CC_EMCR_E8_RESETVAL     (0x00000000u)

/*----E8 Tokens----*/
#define CSL_EDMA3CC_EMCR_E8_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_EMCR_E7_MASK         (0x00000080u)
#define CSL_EDMA3CC_EMCR_E7_SHIFT        (0x00000007u)
#define CSL_EDMA3CC_EMCR_E7_RESETVAL     (0x00000000u)

/*----E7 Tokens----*/
#define CSL_EDMA3CC_EMCR_E7_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_EMCR_E6_MASK         (0x00000040u)
#define CSL_EDMA3CC_EMCR_E6_SHIFT        (0x00000006u)
#define CSL_EDMA3CC_EMCR_E6_RESETVAL     (0x00000000u)

/*----E6 Tokens----*/
#define CSL_EDMA3CC_EMCR_E6_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_EMCR_E5_MASK         (0x00000020u)
#define CSL_EDMA3CC_EMCR_E5_SHIFT        (0x00000005u)
#define CSL_EDMA3CC_EMCR_E5_RESETVAL     (0x00000000u)

/*----E5 Tokens----*/
#define CSL_EDMA3CC_EMCR_E5_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_EMCR_E4_MASK         (0x00000010u)
#define CSL_EDMA3CC_EMCR_E4_SHIFT        (0x00000004u)
#define CSL_EDMA3CC_EMCR_E4_RESETVAL     (0x00000000u)

/*----E4 Tokens----*/
#define CSL_EDMA3CC_EMCR_E4_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_EMCR_E3_MASK         (0x00000008u)
#define CSL_EDMA3CC_EMCR_E3_SHIFT        (0x00000003u)
#define CSL_EDMA3CC_EMCR_E3_RESETVAL     (0x00000000u)

/*----E3 Tokens----*/
#define CSL_EDMA3CC_EMCR_E3_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_EMCR_E2_MASK         (0x00000004u)
#define CSL_EDMA3CC_EMCR_E2_SHIFT        (0x00000002u)
#define CSL_EDMA3CC_EMCR_E2_RESETVAL     (0x00000000u)

/*----E2 Tokens----*/
#define CSL_EDMA3CC_EMCR_E2_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_EMCR_E1_MASK         (0x00000002u)
#define CSL_EDMA3CC_EMCR_E1_SHIFT        (0x00000001u)
#define CSL_EDMA3CC_EMCR_E1_RESETVAL     (0x00000000u)

/*----E1 Tokens----*/
#define CSL_EDMA3CC_EMCR_E1_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_EMCR_E0_MASK         (0x00000001u)
#define CSL_EDMA3CC_EMCR_E0_SHIFT        (0x00000000u)
#define CSL_EDMA3CC_EMCR_E0_RESETVAL     (0x00000000u)

/*----E0 Tokens----*/
#define CSL_EDMA3CC_EMCR_E0_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_EMCR_RESETVAL        (0x00000000u)

/* EMCRH */

#define CSL_EDMA3CC_EMCRH_E63_MASK       (0x80000000u)
#define CSL_EDMA3CC_EMCRH_E63_SHIFT      (0x0000001Fu)
#define CSL_EDMA3CC_EMCRH_E63_RESETVAL   (0x00000000u)

/*----E63 Tokens----*/
#define CSL_EDMA3CC_EMCRH_E63_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EMCRH_E62_MASK       (0x40000000u)
#define CSL_EDMA3CC_EMCRH_E62_SHIFT      (0x0000001Eu)
#define CSL_EDMA3CC_EMCRH_E62_RESETVAL   (0x00000000u)

/*----E62 Tokens----*/
#define CSL_EDMA3CC_EMCRH_E62_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EMCRH_E61_MASK       (0x20000000u)
#define CSL_EDMA3CC_EMCRH_E61_SHIFT      (0x0000001Du)
#define CSL_EDMA3CC_EMCRH_E61_RESETVAL   (0x00000000u)

/*----E61 Tokens----*/
#define CSL_EDMA3CC_EMCRH_E61_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EMCRH_E60_MASK       (0x10000000u)
#define CSL_EDMA3CC_EMCRH_E60_SHIFT      (0x0000001Cu)
#define CSL_EDMA3CC_EMCRH_E60_RESETVAL   (0x00000000u)

/*----E60 Tokens----*/
#define CSL_EDMA3CC_EMCRH_E60_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EMCRH_E59_MASK       (0x08000000u)
#define CSL_EDMA3CC_EMCRH_E59_SHIFT      (0x0000001Bu)
#define CSL_EDMA3CC_EMCRH_E59_RESETVAL   (0x00000000u)

/*----E59 Tokens----*/
#define CSL_EDMA3CC_EMCRH_E59_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EMCRH_E58_MASK       (0x04000000u)
#define CSL_EDMA3CC_EMCRH_E58_SHIFT      (0x0000001Au)
#define CSL_EDMA3CC_EMCRH_E58_RESETVAL   (0x00000000u)

/*----E58 Tokens----*/
#define CSL_EDMA3CC_EMCRH_E58_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EMCRH_E57_MASK       (0x02000000u)
#define CSL_EDMA3CC_EMCRH_E57_SHIFT      (0x00000019u)
#define CSL_EDMA3CC_EMCRH_E57_RESETVAL   (0x00000000u)

/*----E57 Tokens----*/
#define CSL_EDMA3CC_EMCRH_E57_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EMCRH_E56_MASK       (0x01000000u)
#define CSL_EDMA3CC_EMCRH_E56_SHIFT      (0x00000018u)
#define CSL_EDMA3CC_EMCRH_E56_RESETVAL   (0x00000000u)

/*----E56 Tokens----*/
#define CSL_EDMA3CC_EMCRH_E56_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EMCRH_E55_MASK       (0x00800000u)
#define CSL_EDMA3CC_EMCRH_E55_SHIFT      (0x00000017u)
#define CSL_EDMA3CC_EMCRH_E55_RESETVAL   (0x00000000u)

/*----E55 Tokens----*/
#define CSL_EDMA3CC_EMCRH_E55_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EMCRH_E54_MASK       (0x00400000u)
#define CSL_EDMA3CC_EMCRH_E54_SHIFT      (0x00000016u)
#define CSL_EDMA3CC_EMCRH_E54_RESETVAL   (0x00000000u)

/*----E54 Tokens----*/
#define CSL_EDMA3CC_EMCRH_E54_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EMCRH_E53_MASK       (0x00200000u)
#define CSL_EDMA3CC_EMCRH_E53_SHIFT      (0x00000015u)
#define CSL_EDMA3CC_EMCRH_E53_RESETVAL   (0x00000000u)

/*----E53 Tokens----*/
#define CSL_EDMA3CC_EMCRH_E53_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EMCRH_E52_MASK       (0x00100000u)
#define CSL_EDMA3CC_EMCRH_E52_SHIFT      (0x00000014u)
#define CSL_EDMA3CC_EMCRH_E52_RESETVAL   (0x00000000u)

/*----E52 Tokens----*/
#define CSL_EDMA3CC_EMCRH_E52_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EMCRH_E51_MASK       (0x00080000u)
#define CSL_EDMA3CC_EMCRH_E51_SHIFT      (0x00000013u)
#define CSL_EDMA3CC_EMCRH_E51_RESETVAL   (0x00000000u)

/*----E51 Tokens----*/
#define CSL_EDMA3CC_EMCRH_E51_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EMCRH_E50_MASK       (0x00040000u)
#define CSL_EDMA3CC_EMCRH_E50_SHIFT      (0x00000012u)
#define CSL_EDMA3CC_EMCRH_E50_RESETVAL   (0x00000000u)

/*----E50 Tokens----*/
#define CSL_EDMA3CC_EMCRH_E50_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EMCRH_E49_MASK       (0x00020000u)
#define CSL_EDMA3CC_EMCRH_E49_SHIFT      (0x00000011u)
#define CSL_EDMA3CC_EMCRH_E49_RESETVAL   (0x00000000u)

/*----E49 Tokens----*/
#define CSL_EDMA3CC_EMCRH_E49_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EMCRH_E48_MASK       (0x00010000u)
#define CSL_EDMA3CC_EMCRH_E48_SHIFT      (0x00000010u)
#define CSL_EDMA3CC_EMCRH_E48_RESETVAL   (0x00000000u)

/*----E48 Tokens----*/
#define CSL_EDMA3CC_EMCRH_E48_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EMCRH_E47_MASK       (0x00008000u)
#define CSL_EDMA3CC_EMCRH_E47_SHIFT      (0x0000000Fu)
#define CSL_EDMA3CC_EMCRH_E47_RESETVAL   (0x00000000u)

/*----E47 Tokens----*/
#define CSL_EDMA3CC_EMCRH_E47_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EMCRH_E46_MASK       (0x00004000u)
#define CSL_EDMA3CC_EMCRH_E46_SHIFT      (0x0000000Eu)
#define CSL_EDMA3CC_EMCRH_E46_RESETVAL   (0x00000000u)

/*----E46 Tokens----*/
#define CSL_EDMA3CC_EMCRH_E46_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EMCRH_E45_MASK       (0x00002000u)
#define CSL_EDMA3CC_EMCRH_E45_SHIFT      (0x0000000Du)
#define CSL_EDMA3CC_EMCRH_E45_RESETVAL   (0x00000000u)

/*----E45 Tokens----*/
#define CSL_EDMA3CC_EMCRH_E45_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EMCRH_E44_MASK       (0x00001000u)
#define CSL_EDMA3CC_EMCRH_E44_SHIFT      (0x0000000Cu)
#define CSL_EDMA3CC_EMCRH_E44_RESETVAL   (0x00000000u)

/*----E44 Tokens----*/
#define CSL_EDMA3CC_EMCRH_E44_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EMCRH_E43_MASK       (0x00000800u)
#define CSL_EDMA3CC_EMCRH_E43_SHIFT      (0x0000000Bu)
#define CSL_EDMA3CC_EMCRH_E43_RESETVAL   (0x00000000u)

/*----E43 Tokens----*/
#define CSL_EDMA3CC_EMCRH_E43_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EMCRH_E42_MASK       (0x00000400u)
#define CSL_EDMA3CC_EMCRH_E42_SHIFT      (0x0000000Au)
#define CSL_EDMA3CC_EMCRH_E42_RESETVAL   (0x00000000u)

/*----E42 Tokens----*/
#define CSL_EDMA3CC_EMCRH_E42_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EMCRH_E41_MASK       (0x00000200u)
#define CSL_EDMA3CC_EMCRH_E41_SHIFT      (0x00000009u)
#define CSL_EDMA3CC_EMCRH_E41_RESETVAL   (0x00000000u)

/*----E41 Tokens----*/
#define CSL_EDMA3CC_EMCRH_E41_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EMCRH_E40_MASK       (0x00000100u)
#define CSL_EDMA3CC_EMCRH_E40_SHIFT      (0x00000008u)
#define CSL_EDMA3CC_EMCRH_E40_RESETVAL   (0x00000000u)

/*----E40 Tokens----*/
#define CSL_EDMA3CC_EMCRH_E40_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EMCRH_E39_MASK       (0x00000080u)
#define CSL_EDMA3CC_EMCRH_E39_SHIFT      (0x00000007u)
#define CSL_EDMA3CC_EMCRH_E39_RESETVAL   (0x00000000u)

/*----E39 Tokens----*/
#define CSL_EDMA3CC_EMCRH_E39_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EMCRH_E38_MASK       (0x00000040u)
#define CSL_EDMA3CC_EMCRH_E38_SHIFT      (0x00000006u)
#define CSL_EDMA3CC_EMCRH_E38_RESETVAL   (0x00000000u)

/*----E38 Tokens----*/
#define CSL_EDMA3CC_EMCRH_E38_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EMCRH_E37_MASK       (0x00000020u)
#define CSL_EDMA3CC_EMCRH_E37_SHIFT      (0x00000005u)
#define CSL_EDMA3CC_EMCRH_E37_RESETVAL   (0x00000000u)

/*----E37 Tokens----*/
#define CSL_EDMA3CC_EMCRH_E37_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EMCRH_E36_MASK       (0x00000010u)
#define CSL_EDMA3CC_EMCRH_E36_SHIFT      (0x00000004u)
#define CSL_EDMA3CC_EMCRH_E36_RESETVAL   (0x00000000u)

/*----E36 Tokens----*/
#define CSL_EDMA3CC_EMCRH_E36_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EMCRH_E35_MASK       (0x00000008u)
#define CSL_EDMA3CC_EMCRH_E35_SHIFT      (0x00000003u)
#define CSL_EDMA3CC_EMCRH_E35_RESETVAL   (0x00000000u)

/*----E35 Tokens----*/
#define CSL_EDMA3CC_EMCRH_E35_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EMCRH_E34_MASK       (0x00000004u)
#define CSL_EDMA3CC_EMCRH_E34_SHIFT      (0x00000002u)
#define CSL_EDMA3CC_EMCRH_E34_RESETVAL   (0x00000000u)

/*----E34 Tokens----*/
#define CSL_EDMA3CC_EMCRH_E34_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EMCRH_E33_MASK       (0x00000002u)
#define CSL_EDMA3CC_EMCRH_E33_SHIFT      (0x00000001u)
#define CSL_EDMA3CC_EMCRH_E33_RESETVAL   (0x00000000u)

/*----E33 Tokens----*/
#define CSL_EDMA3CC_EMCRH_E33_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EMCRH_E32_MASK       (0x00000001u)
#define CSL_EDMA3CC_EMCRH_E32_SHIFT      (0x00000000u)
#define CSL_EDMA3CC_EMCRH_E32_RESETVAL   (0x00000000u)

/*----E32 Tokens----*/
#define CSL_EDMA3CC_EMCRH_E32_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EMCRH_RESETVAL       (0x00000000u)

/* QEMR */
#define CSL_EDMA3CC_QEMR_E7_MASK (0x00000080u)
#define CSL_EDMA3CC_QEMR_E7_SHIFT (0x00000007u)
#define CSL_EDMA3CC_QEMR_E7_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_QEMR_E6_MASK (0x00000040u)
#define CSL_EDMA3CC_QEMR_E6_SHIFT (0x00000006u)
#define CSL_EDMA3CC_QEMR_E6_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_QEMR_E5_MASK (0x00000020u)
#define CSL_EDMA3CC_QEMR_E5_SHIFT (0x00000005u)
#define CSL_EDMA3CC_QEMR_E5_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_QEMR_E4_MASK (0x00000010u)
#define CSL_EDMA3CC_QEMR_E4_SHIFT (0x00000004u)
#define CSL_EDMA3CC_QEMR_E4_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_QEMR_E3_MASK         (0x00000008u)
#define CSL_EDMA3CC_QEMR_E3_SHIFT        (0x00000003u)
#define CSL_EDMA3CC_QEMR_E3_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_QEMR_E2_MASK         (0x00000004u)
#define CSL_EDMA3CC_QEMR_E2_SHIFT        (0x00000002u)
#define CSL_EDMA3CC_QEMR_E2_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_QEMR_E1_MASK         (0x00000002u)
#define CSL_EDMA3CC_QEMR_E1_SHIFT        (0x00000001u)
#define CSL_EDMA3CC_QEMR_E1_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_QEMR_E0_MASK         (0x00000001u)
#define CSL_EDMA3CC_QEMR_E0_SHIFT        (0x00000000u)
#define CSL_EDMA3CC_QEMR_E0_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_QEMR_RESETVAL        (0x00000000u)

/* QEMCR */

#define CSL_EDMA3CC_QEMCR_E7_MASK (0x00000080u)
#define CSL_EDMA3CC_QEMCR_E7_SHIFT (0x00000007u)
#define CSL_EDMA3CC_QEMCR_E7_RESETVAL (0x00000000u)
/*----E7 Tokens----*/
#define CSL_EDMA3CC_QEMCR_E7_CLEAR (0x00000001u)

#define CSL_EDMA3CC_QEMCR_E6_MASK (0x00000040u)
#define CSL_EDMA3CC_QEMCR_E6_SHIFT (0x00000006u)
#define CSL_EDMA3CC_QEMCR_E6_RESETVAL (0x00000000u)
/*----E6 Tokens----*/
#define CSL_EDMA3CC_QEMCR_E6_CLEAR (0x00000001u)

#define CSL_EDMA3CC_QEMCR_E5_MASK (0x00000020u)
#define CSL_EDMA3CC_QEMCR_E5_SHIFT (0x00000005u)
#define CSL_EDMA3CC_QEMCR_E5_RESETVAL (0x00000000u)
/*----E5 Tokens----*/
#define CSL_EDMA3CC_QEMCR_E5_CLEAR (0x00000001u)

#define CSL_EDMA3CC_QEMCR_E4_MASK (0x00000010u)
#define CSL_EDMA3CC_QEMCR_E4_SHIFT (0x00000004u)
#define CSL_EDMA3CC_QEMCR_E4_RESETVAL (0x00000000u)
/*----E4 Tokens----*/
#define CSL_EDMA3CC_QEMCR_E4_CLEAR (0x00000001u)

#define CSL_EDMA3CC_QEMCR_E3_MASK        (0x00000008u)
#define CSL_EDMA3CC_QEMCR_E3_SHIFT       (0x00000003u)
#define CSL_EDMA3CC_QEMCR_E3_RESETVAL    (0x00000000u)

/*----E3 Tokens----*/
#define CSL_EDMA3CC_QEMCR_E3_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_QEMCR_E2_MASK        (0x00000004u)
#define CSL_EDMA3CC_QEMCR_E2_SHIFT       (0x00000002u)
#define CSL_EDMA3CC_QEMCR_E2_RESETVAL    (0x00000000u)

/*----E2 Tokens----*/
#define CSL_EDMA3CC_QEMCR_E2_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_QEMCR_E1_MASK        (0x00000002u)
#define CSL_EDMA3CC_QEMCR_E1_SHIFT       (0x00000001u)
#define CSL_EDMA3CC_QEMCR_E1_RESETVAL    (0x00000000u)

/*----E1 Tokens----*/
#define CSL_EDMA3CC_QEMCR_E1_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_QEMCR_E0_MASK        (0x00000001u)
#define CSL_EDMA3CC_QEMCR_E0_SHIFT       (0x00000000u)
#define CSL_EDMA3CC_QEMCR_E0_RESETVAL    (0x00000000u)

/*----E0 Tokens----*/
#define CSL_EDMA3CC_QEMCR_E0_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_QEMCR_RESETVAL       (0x00000000u)

/* CCERR */

#define CSL_EDMA3CC_CCERR_TCCERR_MASK    (0x00010000u)
#define CSL_EDMA3CC_CCERR_TCCERR_SHIFT   (0x00000010u)
#define CSL_EDMA3CC_CCERR_TCCERR_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_CCERR_QTHRXCD5_MASK (0x00000020u)
#define CSL_EDMA3CC_CCERR_QTHRXCD5_SHIFT (0x00000005u)
#define CSL_EDMA3CC_CCERR_QTHRXCD5_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_CCERR_QTHRXCD4_MASK (0x00000010u)
#define CSL_EDMA3CC_CCERR_QTHRXCD4_SHIFT (0x00000004u)
#define CSL_EDMA3CC_CCERR_QTHRXCD4_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_CCERR_QTHRXCD3_MASK  (0x00000008u)
#define CSL_EDMA3CC_CCERR_QTHRXCD3_SHIFT (0x00000003u)
#define CSL_EDMA3CC_CCERR_QTHRXCD3_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_CCERR_QTHRXCD2_MASK  (0x00000004u)
#define CSL_EDMA3CC_CCERR_QTHRXCD2_SHIFT (0x00000002u)
#define CSL_EDMA3CC_CCERR_QTHRXCD2_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_CCERR_QTHRXCD1_MASK  (0x00000002u)
#define CSL_EDMA3CC_CCERR_QTHRXCD1_SHIFT (0x00000001u)
#define CSL_EDMA3CC_CCERR_QTHRXCD1_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_CCERR_QTHRXCD0_MASK  (0x00000001u)
#define CSL_EDMA3CC_CCERR_QTHRXCD0_SHIFT (0x00000000u)
#define CSL_EDMA3CC_CCERR_QTHRXCD0_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_CCERR_RESETVAL       (0x00000000u)

/* CCERRCLR */

#define CSL_EDMA3CC_CCERRCLR_TCCERR_MASK (0x00010000u)
#define CSL_EDMA3CC_CCERRCLR_TCCERR_SHIFT (0x00000010u)
#define CSL_EDMA3CC_CCERRCLR_TCCERR_RESETVAL (0x00000000u)

/*----TCCERR Tokens----*/
#define CSL_EDMA3CC_CCERRCLR_TCCERR_CLEAR (0x00000001u)

#define CSL_EDMA3CC_CCERRCLR_QTHRXCD5_MASK (0x00000020u)
#define CSL_EDMA3CC_CCERRCLR_QTHRXCD5_SHIFT (0x00000005u)
#define CSL_EDMA3CC_CCERRCLR_QTHRXCD5_RESETVAL (0x00000000u)
/*----QTHRXCD5 Tokens----*/
#define CSL_EDMA3CC_CCERRCLR_QTHRXCD5_CLEAR (0x00000001u)

#define CSL_EDMA3CC_CCERRCLR_QTHRXCD4_MASK (0x00000010u)
#define CSL_EDMA3CC_CCERRCLR_QTHRXCD4_SHIFT (0x00000004u)
#define CSL_EDMA3CC_CCERRCLR_QTHRXCD4_RESETVAL (0x00000000u)
/*----QTHRXCD4 Tokens----*/
#define CSL_EDMA3CC_CCERRCLR_QTHRXCD4_CLEAR (0x00000001u)
#define CSL_EDMA3CC_CCERRCLR_QTHRXCD3_MASK (0x00000008u)
#define CSL_EDMA3CC_CCERRCLR_QTHRXCD3_SHIFT (0x00000003u)
#define CSL_EDMA3CC_CCERRCLR_QTHRXCD3_RESETVAL (0x00000000u)

/*----QTHRXCD3 Tokens----*/
#define CSL_EDMA3CC_CCERRCLR_QTHRXCD3_CLEAR (0x00000001u)

#define CSL_EDMA3CC_CCERRCLR_QTHRXCD2_MASK (0x00000004u)
#define CSL_EDMA3CC_CCERRCLR_QTHRXCD2_SHIFT (0x00000002u)
#define CSL_EDMA3CC_CCERRCLR_QTHRXCD2_RESETVAL (0x00000000u)

/*----QTHRXCD2 Tokens----*/
#define CSL_EDMA3CC_CCERRCLR_QTHRXCD2_CLEAR (0x00000001u)

#define CSL_EDMA3CC_CCERRCLR_QTHRXCD1_MASK (0x00000002u)
#define CSL_EDMA3CC_CCERRCLR_QTHRXCD1_SHIFT (0x00000001u)
#define CSL_EDMA3CC_CCERRCLR_QTHRXCD1_RESETVAL (0x00000000u)

/*----QTHRXCD1 Tokens----*/
#define CSL_EDMA3CC_CCERRCLR_QTHRXCD1_CLEAR (0x00000001u)

#define CSL_EDMA3CC_CCERRCLR_QTHRXCD0_MASK (0x00000001u)
#define CSL_EDMA3CC_CCERRCLR_QTHRXCD0_SHIFT (0x00000000u)
#define CSL_EDMA3CC_CCERRCLR_QTHRXCD0_RESETVAL (0x00000000u)

/*----QTHRXCD0 Tokens----*/
#define CSL_EDMA3CC_CCERRCLR_QTHRXCD0_CLEAR (0x00000001u)

#define CSL_EDMA3CC_CCERRCLR_RESETVAL    (0x00000000u)

/* EEVAL */

#define CSL_EDMA3CC_EEVAL_EVAL_MASK      (0x00000001u)
#define CSL_EDMA3CC_EEVAL_EVAL_SHIFT     (0x00000000u)
#define CSL_EDMA3CC_EEVAL_EVAL_RESETVAL  (0x00000000u)

/*----EVAL Tokens----*/
#define CSL_EDMA3CC_EEVAL_EVAL_EVAL      (0x00000001u)

#define CSL_EDMA3CC_EEVAL_RESETVAL       (0x00000000u)

/* DRAE */

#define CSL_EDMA3CC_DRAE_E31_MASK        (0x80000000u)
#define CSL_EDMA3CC_DRAE_E31_SHIFT       (0x0000001Fu)
#define CSL_EDMA3CC_DRAE_E31_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_DRAE_E30_MASK        (0x40000000u)
#define CSL_EDMA3CC_DRAE_E30_SHIFT       (0x0000001Eu)
#define CSL_EDMA3CC_DRAE_E30_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_DRAE_E29_MASK        (0x20000000u)
#define CSL_EDMA3CC_DRAE_E29_SHIFT       (0x0000001Du)
#define CSL_EDMA3CC_DRAE_E29_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_DRAE_E28_MASK        (0x10000000u)
#define CSL_EDMA3CC_DRAE_E28_SHIFT       (0x0000001Cu)
#define CSL_EDMA3CC_DRAE_E28_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_DRAE_E27_MASK        (0x08000000u)
#define CSL_EDMA3CC_DRAE_E27_SHIFT       (0x0000001Bu)
#define CSL_EDMA3CC_DRAE_E27_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_DRAE_E26_MASK        (0x04000000u)
#define CSL_EDMA3CC_DRAE_E26_SHIFT       (0x0000001Au)
#define CSL_EDMA3CC_DRAE_E26_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_DRAE_E25_MASK        (0x02000000u)
#define CSL_EDMA3CC_DRAE_E25_SHIFT       (0x00000019u)
#define CSL_EDMA3CC_DRAE_E25_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_DRAE_E24_MASK        (0x01000000u)
#define CSL_EDMA3CC_DRAE_E24_SHIFT       (0x00000018u)
#define CSL_EDMA3CC_DRAE_E24_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_DRAE_E23_MASK        (0x00800000u)
#define CSL_EDMA3CC_DRAE_E23_SHIFT       (0x00000017u)
#define CSL_EDMA3CC_DRAE_E23_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_DRAE_E22_MASK        (0x00400000u)
#define CSL_EDMA3CC_DRAE_E22_SHIFT       (0x00000016u)
#define CSL_EDMA3CC_DRAE_E22_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_DRAE_E21_MASK        (0x00200000u)
#define CSL_EDMA3CC_DRAE_E21_SHIFT       (0x00000015u)
#define CSL_EDMA3CC_DRAE_E21_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_DRAE_E20_MASK        (0x00100000u)
#define CSL_EDMA3CC_DRAE_E20_SHIFT       (0x00000014u)
#define CSL_EDMA3CC_DRAE_E20_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_DRAE_E19_MASK        (0x00080000u)
#define CSL_EDMA3CC_DRAE_E19_SHIFT       (0x00000013u)
#define CSL_EDMA3CC_DRAE_E19_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_DRAE_E18_MASK        (0x00040000u)
#define CSL_EDMA3CC_DRAE_E18_SHIFT       (0x00000012u)
#define CSL_EDMA3CC_DRAE_E18_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_DRAE_E17_MASK        (0x00020000u)
#define CSL_EDMA3CC_DRAE_E17_SHIFT       (0x00000011u)
#define CSL_EDMA3CC_DRAE_E17_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_DRAE_E16_MASK        (0x00010000u)
#define CSL_EDMA3CC_DRAE_E16_SHIFT       (0x00000010u)
#define CSL_EDMA3CC_DRAE_E16_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_DRAE_E15_MASK        (0x00008000u)
#define CSL_EDMA3CC_DRAE_E15_SHIFT       (0x0000000Fu)
#define CSL_EDMA3CC_DRAE_E15_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_DRAE_E14_MASK        (0x00004000u)
#define CSL_EDMA3CC_DRAE_E14_SHIFT       (0x0000000Eu)
#define CSL_EDMA3CC_DRAE_E14_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_DRAE_E13_MASK        (0x00002000u)
#define CSL_EDMA3CC_DRAE_E13_SHIFT       (0x0000000Du)
#define CSL_EDMA3CC_DRAE_E13_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_DRAE_E12_MASK        (0x00001000u)
#define CSL_EDMA3CC_DRAE_E12_SHIFT       (0x0000000Cu)
#define CSL_EDMA3CC_DRAE_E12_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_DRAE_E11_MASK        (0x00000800u)
#define CSL_EDMA3CC_DRAE_E11_SHIFT       (0x0000000Bu)
#define CSL_EDMA3CC_DRAE_E11_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_DRAE_E10_MASK        (0x00000400u)
#define CSL_EDMA3CC_DRAE_E10_SHIFT       (0x0000000Au)
#define CSL_EDMA3CC_DRAE_E10_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_DRAE_E9_MASK         (0x00000200u)
#define CSL_EDMA3CC_DRAE_E9_SHIFT        (0x00000009u)
#define CSL_EDMA3CC_DRAE_E9_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_DRAE_E8_MASK         (0x00000100u)
#define CSL_EDMA3CC_DRAE_E8_SHIFT        (0x00000008u)
#define CSL_EDMA3CC_DRAE_E8_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_DRAE_E7_MASK         (0x00000080u)
#define CSL_EDMA3CC_DRAE_E7_SHIFT        (0x00000007u)
#define CSL_EDMA3CC_DRAE_E7_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_DRAE_E6_MASK         (0x00000040u)
#define CSL_EDMA3CC_DRAE_E6_SHIFT        (0x00000006u)
#define CSL_EDMA3CC_DRAE_E6_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_DRAE_E5_MASK         (0x00000020u)
#define CSL_EDMA3CC_DRAE_E5_SHIFT        (0x00000005u)
#define CSL_EDMA3CC_DRAE_E5_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_DRAE_E4_MASK         (0x00000010u)
#define CSL_EDMA3CC_DRAE_E4_SHIFT        (0x00000004u)
#define CSL_EDMA3CC_DRAE_E4_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_DRAE_E3_MASK         (0x00000008u)
#define CSL_EDMA3CC_DRAE_E3_SHIFT        (0x00000003u)
#define CSL_EDMA3CC_DRAE_E3_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_DRAE_E2_MASK         (0x00000004u)
#define CSL_EDMA3CC_DRAE_E2_SHIFT        (0x00000002u)
#define CSL_EDMA3CC_DRAE_E2_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_DRAE_E1_MASK         (0x00000002u)
#define CSL_EDMA3CC_DRAE_E1_SHIFT        (0x00000001u)
#define CSL_EDMA3CC_DRAE_E1_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_DRAE_E0_MASK         (0x00000001u)
#define CSL_EDMA3CC_DRAE_E0_SHIFT        (0x00000000u)
#define CSL_EDMA3CC_DRAE_E0_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_DRAE_RESETVAL        (0x00000000u)

/* DRAEH */

#define CSL_EDMA3CC_DRAEH_E63_MASK       (0x80000000u)
#define CSL_EDMA3CC_DRAEH_E63_SHIFT      (0x0000001Fu)
#define CSL_EDMA3CC_DRAEH_E63_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_DRAEH_E62_MASK       (0x40000000u)
#define CSL_EDMA3CC_DRAEH_E62_SHIFT      (0x0000001Eu)
#define CSL_EDMA3CC_DRAEH_E62_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_DRAEH_E61_MASK       (0x20000000u)
#define CSL_EDMA3CC_DRAEH_E61_SHIFT      (0x0000001Du)
#define CSL_EDMA3CC_DRAEH_E61_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_DRAEH_E60_MASK       (0x10000000u)
#define CSL_EDMA3CC_DRAEH_E60_SHIFT      (0x0000001Cu)
#define CSL_EDMA3CC_DRAEH_E60_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_DRAEH_E59_MASK       (0x08000000u)
#define CSL_EDMA3CC_DRAEH_E59_SHIFT      (0x0000001Bu)
#define CSL_EDMA3CC_DRAEH_E59_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_DRAEH_E58_MASK       (0x04000000u)
#define CSL_EDMA3CC_DRAEH_E58_SHIFT      (0x0000001Au)
#define CSL_EDMA3CC_DRAEH_E58_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_DRAEH_E57_MASK       (0x02000000u)
#define CSL_EDMA3CC_DRAEH_E57_SHIFT      (0x00000019u)
#define CSL_EDMA3CC_DRAEH_E57_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_DRAEH_E56_MASK       (0x01000000u)
#define CSL_EDMA3CC_DRAEH_E56_SHIFT      (0x00000018u)
#define CSL_EDMA3CC_DRAEH_E56_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_DRAEH_E55_MASK       (0x00800000u)
#define CSL_EDMA3CC_DRAEH_E55_SHIFT      (0x00000017u)
#define CSL_EDMA3CC_DRAEH_E55_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_DRAEH_E54_MASK       (0x00400000u)
#define CSL_EDMA3CC_DRAEH_E54_SHIFT      (0x00000016u)
#define CSL_EDMA3CC_DRAEH_E54_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_DRAEH_E53_MASK       (0x00200000u)
#define CSL_EDMA3CC_DRAEH_E53_SHIFT      (0x00000015u)
#define CSL_EDMA3CC_DRAEH_E53_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_DRAEH_E52_MASK       (0x00100000u)
#define CSL_EDMA3CC_DRAEH_E52_SHIFT      (0x00000014u)
#define CSL_EDMA3CC_DRAEH_E52_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_DRAEH_E51_MASK       (0x00080000u)
#define CSL_EDMA3CC_DRAEH_E51_SHIFT      (0x00000013u)
#define CSL_EDMA3CC_DRAEH_E51_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_DRAEH_E50_MASK       (0x00040000u)
#define CSL_EDMA3CC_DRAEH_E50_SHIFT      (0x00000012u)
#define CSL_EDMA3CC_DRAEH_E50_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_DRAEH_E49_MASK       (0x00020000u)
#define CSL_EDMA3CC_DRAEH_E49_SHIFT      (0x00000011u)
#define CSL_EDMA3CC_DRAEH_E49_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_DRAEH_E48_MASK       (0x00010000u)
#define CSL_EDMA3CC_DRAEH_E48_SHIFT      (0x00000010u)
#define CSL_EDMA3CC_DRAEH_E48_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_DRAEH_E47_MASK       (0x00008000u)
#define CSL_EDMA3CC_DRAEH_E47_SHIFT      (0x0000000Fu)
#define CSL_EDMA3CC_DRAEH_E47_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_DRAEH_E46_MASK       (0x00004000u)
#define CSL_EDMA3CC_DRAEH_E46_SHIFT      (0x0000000Eu)
#define CSL_EDMA3CC_DRAEH_E46_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_DRAEH_E45_MASK       (0x00002000u)
#define CSL_EDMA3CC_DRAEH_E45_SHIFT      (0x0000000Du)
#define CSL_EDMA3CC_DRAEH_E45_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_DRAEH_E44_MASK       (0x00001000u)
#define CSL_EDMA3CC_DRAEH_E44_SHIFT      (0x0000000Cu)
#define CSL_EDMA3CC_DRAEH_E44_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_DRAEH_E43_MASK       (0x00000800u)
#define CSL_EDMA3CC_DRAEH_E43_SHIFT      (0x0000000Bu)
#define CSL_EDMA3CC_DRAEH_E43_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_DRAEH_E42_MASK       (0x00000400u)
#define CSL_EDMA3CC_DRAEH_E42_SHIFT      (0x0000000Au)
#define CSL_EDMA3CC_DRAEH_E42_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_DRAEH_E41_MASK       (0x00000200u)
#define CSL_EDMA3CC_DRAEH_E41_SHIFT      (0x00000009u)
#define CSL_EDMA3CC_DRAEH_E41_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_DRAEH_E40_MASK       (0x00000100u)
#define CSL_EDMA3CC_DRAEH_E40_SHIFT      (0x00000008u)
#define CSL_EDMA3CC_DRAEH_E40_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_DRAEH_E39_MASK       (0x00000080u)
#define CSL_EDMA3CC_DRAEH_E39_SHIFT      (0x00000007u)
#define CSL_EDMA3CC_DRAEH_E39_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_DRAEH_E38_MASK       (0x00000040u)
#define CSL_EDMA3CC_DRAEH_E38_SHIFT      (0x00000006u)
#define CSL_EDMA3CC_DRAEH_E38_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_DRAEH_E37_MASK       (0x00000020u)
#define CSL_EDMA3CC_DRAEH_E37_SHIFT      (0x00000005u)
#define CSL_EDMA3CC_DRAEH_E37_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_DRAEH_E36_MASK       (0x00000010u)
#define CSL_EDMA3CC_DRAEH_E36_SHIFT      (0x00000004u)
#define CSL_EDMA3CC_DRAEH_E36_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_DRAEH_E35_MASK       (0x00000008u)
#define CSL_EDMA3CC_DRAEH_E35_SHIFT      (0x00000003u)
#define CSL_EDMA3CC_DRAEH_E35_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_DRAEH_E34_MASK       (0x00000004u)
#define CSL_EDMA3CC_DRAEH_E34_SHIFT      (0x00000002u)
#define CSL_EDMA3CC_DRAEH_E34_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_DRAEH_E33_MASK       (0x00000002u)
#define CSL_EDMA3CC_DRAEH_E33_SHIFT      (0x00000001u)
#define CSL_EDMA3CC_DRAEH_E33_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_DRAEH_E32_MASK       (0x00000001u)
#define CSL_EDMA3CC_DRAEH_E32_SHIFT      (0x00000000u)
#define CSL_EDMA3CC_DRAEH_E32_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_DRAEH_RESETVAL       (0x00000000u)

/* QRAE */

#define CSL_EDMA3CC_QRAE_E7_MASK (0x00000080u)
#define CSL_EDMA3CC_QRAE_E7_SHIFT (0x00000007u)
#define CSL_EDMA3CC_QRAE_E7_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_QRAE_E6_MASK (0x00000040u)
#define CSL_EDMA3CC_QRAE_E6_SHIFT (0x00000006u)
#define CSL_EDMA3CC_QRAE_E6_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_QRAE_E5_MASK (0x00000020u)
#define CSL_EDMA3CC_QRAE_E5_SHIFT (0x00000005u)
#define CSL_EDMA3CC_QRAE_E5_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_QRAE_E4_MASK (0x00000010u)
#define CSL_EDMA3CC_QRAE_E4_SHIFT (0x00000004u)
#define CSL_EDMA3CC_QRAE_E4_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_QRAE_E3_MASK         (0x00000008u)
#define CSL_EDMA3CC_QRAE_E3_SHIFT        (0x00000003u)
#define CSL_EDMA3CC_QRAE_E3_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_QRAE_E2_MASK         (0x00000004u)
#define CSL_EDMA3CC_QRAE_E2_SHIFT        (0x00000002u)
#define CSL_EDMA3CC_QRAE_E2_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_QRAE_E1_MASK         (0x00000002u)
#define CSL_EDMA3CC_QRAE_E1_SHIFT        (0x00000001u)
#define CSL_EDMA3CC_QRAE_E1_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_QRAE_E0_MASK         (0x00000001u)
#define CSL_EDMA3CC_QRAE_E0_SHIFT        (0x00000000u)
#define CSL_EDMA3CC_QRAE_E0_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_QRAE_RESETVAL        (0x00000000u)

/* QUEEVT_ENTRY */

#define CSL_EDMA3CC_QUEEVT_ENTRY_RESV_MASK (0xFFFFFF00u)
#define CSL_EDMA3CC_QUEEVT_ENTRY_RESV_SHIFT (0x00000008u)
#define CSL_EDMA3CC_QUEEVT_ENTRY_RESV_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_QUEEVT_ENTRY_ETYPE_MASK (0x000000C0u)
#define CSL_EDMA3CC_QUEEVT_ENTRY_ETYPE_SHIFT (0x00000006u)
#define CSL_EDMA3CC_QUEEVT_ENTRY_ETYPE_RESETVAL (0x00000000u)

/*----ETYPE Tokens----*/
#define CSL_EDMA3CC_QUEEVT_ENTRY_ETYPE_EVENT (0x00000000u)
#define CSL_EDMA3CC_QUEEVT_ENTRY_ETYPE_MANUAL (0x00000001u)
#define CSL_EDMA3CC_QUEEVT_ENTRY_ETYPE_CHAIN (0x00000002u)
#define CSL_EDMA3CC_QUEEVT_ENTRY_ETYPE_AUTO (0x00000003u)

#define CSL_EDMA3CC_QUEEVT_ENTRY_ENUM_MASK (0x0000003Fu)
#define CSL_EDMA3CC_QUEEVT_ENTRY_ENUM_SHIFT (0x00000000u)
#define CSL_EDMA3CC_QUEEVT_ENTRY_ENUM_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_QUEEVT_ENTRY_RESETVAL (0x00000000u)

/* QSTAT */

#define CSL_EDMA3CC_QSTAT_THRXD_MASK     (0x01000000u)
#define CSL_EDMA3CC_QSTAT_THRXD_SHIFT    (0x00000018u)
#define CSL_EDMA3CC_QSTAT_THRXD_RESETVAL (0x00000000u)

/*----THRXD Tokens----*/
#define CSL_EDMA3CC_QSTAT_THRXD_NOTEXCEED (0x00000000u)
#define CSL_EDMA3CC_QSTAT_THRXD_EXCEED   (0x00000001u)

#define CSL_EDMA3CC_QSTAT_WM_MASK        (0x001F0000u)
#define CSL_EDMA3CC_QSTAT_WM_SHIFT       (0x00000010u)
#define CSL_EDMA3CC_QSTAT_WM_RESETVAL    (0x00000000u)

/*----WM Tokens----*/
#define CSL_EDMA3CC_QSTAT_WM_EMPTY       (0x00000000u)
#define CSL_EDMA3CC_QSTAT_WM_FULL        (0x00000010u)

#define CSL_EDMA3CC_QSTAT_NUMVAL_MASK    (0x00001F00u)
#define CSL_EDMA3CC_QSTAT_NUMVAL_SHIFT   (0x00000008u)
#define CSL_EDMA3CC_QSTAT_NUMVAL_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_QSTAT_STRTPTR_MASK   (0x0000000Fu)
#define CSL_EDMA3CC_QSTAT_STRTPTR_SHIFT  (0x00000000u)
#define CSL_EDMA3CC_QSTAT_STRTPTR_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_QSTAT_RESETVAL       (0x00000000u)

/* QWMTHRA */

#define CSL_EDMA3CC_QWMTHRA_Q3_MASK      (0x1F000000u)
#define CSL_EDMA3CC_QWMTHRA_Q3_SHIFT     (0x00000018u)
#define CSL_EDMA3CC_QWMTHRA_Q3_RESETVAL  (0x00000010u)

/*----Q3 Tokens----*/
#define CSL_EDMA3CC_QWMTHRA_Q3_DISABLE   (0x00000011u)

#define CSL_EDMA3CC_QWMTHRA_Q2_MASK      (0x001F0000u)
#define CSL_EDMA3CC_QWMTHRA_Q2_SHIFT     (0x00000010u)
#define CSL_EDMA3CC_QWMTHRA_Q2_RESETVAL  (0x00000010u)

/*----Q2 Tokens----*/
#define CSL_EDMA3CC_QWMTHRA_Q2_DISABLE   (0x00000011u)

#define CSL_EDMA3CC_QWMTHRA_Q1_MASK      (0x00001F00u)
#define CSL_EDMA3CC_QWMTHRA_Q1_SHIFT     (0x00000008u)
#define CSL_EDMA3CC_QWMTHRA_Q1_RESETVAL  (0x00000010u)

/*----Q1 Tokens----*/
#define CSL_EDMA3CC_QWMTHRA_Q1_DISABLE   (0x00000011u)

#define CSL_EDMA3CC_QWMTHRA_Q0_MASK      (0x0000001Fu)
#define CSL_EDMA3CC_QWMTHRA_Q0_SHIFT     (0x00000000u)
#define CSL_EDMA3CC_QWMTHRA_Q0_RESETVAL  (0x00000010u)

/*----Q0 Tokens----*/
#define CSL_EDMA3CC_QWMTHRA_Q0_DISABLE   (0x00000011u)

#define CSL_EDMA3CC_QWMTHRA_RESETVAL     (0x10101010u)

#define CSL_EDMA3CC_QWMTHRB_Q5_MASK (0x00001F00u)
#define CSL_EDMA3CC_QWMTHRB_Q5_SHIFT (0x00000008u)
#define CSL_EDMA3CC_QWMTHRB_Q5_RESETVAL (0x00000010u)
#define CSL_EDMA3CC_QWMTHRB_Q5_DISABLE (0x00000011u)


#define CSL_EDMA3CC_QWMTHRB_Q4_MASK (0x0000001Fu)
#define CSL_EDMA3CC_QWMTHRB_Q4_SHIFT (0x00000000u)
#define CSL_EDMA3CC_QWMTHRB_Q4_RESETVAL (0x00000010u)
#define CSL_EDMA3CC_QWMTHRB_Q4_DISABLE (0x00000011u)

#define CSL_EDMA3CC_QWMTHRB_RESETVAL (0x00001010u)
/* CCSTAT */

#define CSL_EDMA3CC_CCSTAT_QUEACTV5_MASK (0x00200000u)
#define CSL_EDMA3CC_CCSTAT_QUEACTV5_SHIFT (0x00000015u)
#define CSL_EDMA3CC_CCSTAT_QUEACTV5_RESETVAL (0x00000000u)
/*----QUEACTV5 Tokens----*/
#define CSL_EDMA3CC_CCSTAT_QUEACTV5_NONE (0x00000000u)
#define CSL_EDMA3CC_CCSTAT_QUEACTV5_ACTIVE (0x00000001u)

#define CSL_EDMA3CC_CCSTAT_QUEACTV4_MASK (0x00100000u)
#define CSL_EDMA3CC_CCSTAT_QUEACTV4_SHIFT (0x00000014u)
#define CSL_EDMA3CC_CCSTAT_QUEACTV4_RESETVAL (0x00000000u)
/*----QUEACTV4 Tokens----*/
#define CSL_EDMA3CC_CCSTAT_QUEACTV4_NONE (0x00000000u)
#define CSL_EDMA3CC_CCSTAT_QUEACTV4_ACTIVE (0x00000001u)

#define CSL_EDMA3CC_CCSTAT_QUEACTV3_MASK (0x00080000u)
#define CSL_EDMA3CC_CCSTAT_QUEACTV3_SHIFT (0x00000013u)
#define CSL_EDMA3CC_CCSTAT_QUEACTV3_RESETVAL (0x00000000u)

/*----QUEACTV3 Tokens----*/
#define CSL_EDMA3CC_CCSTAT_QUEACTV3_NONE (0x00000000u)
#define CSL_EDMA3CC_CCSTAT_QUEACTV3_ACTIVE (0x00000001u)

#define CSL_EDMA3CC_CCSTAT_QUEACTV2_MASK (0x00040000u)
#define CSL_EDMA3CC_CCSTAT_QUEACTV2_SHIFT (0x00000012u)
#define CSL_EDMA3CC_CCSTAT_QUEACTV2_RESETVAL (0x00000000u)

/*----QUEACTV2 Tokens----*/
#define CSL_EDMA3CC_CCSTAT_QUEACTV2_NONE (0x00000000u)
#define CSL_EDMA3CC_CCSTAT_QUEACTV2_ACTIVE (0x00000001u)

#define CSL_EDMA3CC_CCSTAT_QUEACTV1_MASK (0x00020000u)
#define CSL_EDMA3CC_CCSTAT_QUEACTV1_SHIFT (0x00000011u)
#define CSL_EDMA3CC_CCSTAT_QUEACTV1_RESETVAL (0x00000000u)

/*----QUEACTV1 Tokens----*/
#define CSL_EDMA3CC_CCSTAT_QUEACTV1_NONE (0x00000000u)
#define CSL_EDMA3CC_CCSTAT_QUEACTV1_ACTIVE (0x00000001u)

#define CSL_EDMA3CC_CCSTAT_QUEACTV0_MASK (0x00010000u)
#define CSL_EDMA3CC_CCSTAT_QUEACTV0_SHIFT (0x00000010u)
#define CSL_EDMA3CC_CCSTAT_QUEACTV0_RESETVAL (0x00000000u)

/*----QUEACTV0 Tokens----*/
#define CSL_EDMA3CC_CCSTAT_QUEACTV0_NONE (0x00000000u)
#define CSL_EDMA3CC_CCSTAT_QUEACTV0_ACTIVE (0x00000001u)

#define CSL_EDMA3CC_CCSTAT_COMPACTV_MASK (0x00003F00u)
#define CSL_EDMA3CC_CCSTAT_COMPACTV_SHIFT (0x00000008u)
#define CSL_EDMA3CC_CCSTAT_COMPACTV_RESETVAL (0x00000000u)

/*----COMPACTV Tokens----*/
#define CSL_EDMA3CC_CCSTAT_COMPACTV_NONE (0x00000000u)

#define CSL_EDMA3CC_CCSTAT_ACTV_MASK     (0x00000010u)
#define CSL_EDMA3CC_CCSTAT_ACTV_SHIFT    (0x00000004u)
#define CSL_EDMA3CC_CCSTAT_ACTV_RESETVAL (0x00000000u)

/*----ACTV Tokens----*/
#define CSL_EDMA3CC_CCSTAT_ACTV_IDLE     (0x00000000u)
#define CSL_EDMA3CC_CCSTAT_ACTV_BUSY     (0x00000001u)

#define CSL_EDMA3CC_CCSTAT_WSTATACTV_MASK (0x00000008u)
#define CSL_EDMA3CC_CCSTAT_WSTATACTV_SHIFT (0x00000003u)
#define CSL_EDMA3CC_CCSTAT_WSTATACTV_RESETVAL (0x00000000u)

/*----WSTATACTV Tokens----*/
#define CSL_EDMA3CC_CCSTAT_WSTATACTV_IDLE (0x00000000u)
#define CSL_EDMA3CC_CCSTAT_WSTATACTV_BUSY (0x00000001u)

#define CSL_EDMA3CC_CCSTAT_TRACTV_MASK   (0x00000004u)
#define CSL_EDMA3CC_CCSTAT_TRACTV_SHIFT  (0x00000002u)
#define CSL_EDMA3CC_CCSTAT_TRACTV_RESETVAL (0x00000000u)

/*----TRACTV Tokens----*/
#define CSL_EDMA3CC_CCSTAT_TRACTV_NONE   (0x00000000u)
#define CSL_EDMA3CC_CCSTAT_TRACTV_ACTIVE (0x00000001u)

#define CSL_EDMA3CC_CCSTAT_QEVTACTV_MASK (0x00000002u)
#define CSL_EDMA3CC_CCSTAT_QEVTACTV_SHIFT (0x00000001u)
#define CSL_EDMA3CC_CCSTAT_QEVTACTV_RESETVAL (0x00000000u)

/*----QEVTACTV Tokens----*/
#define CSL_EDMA3CC_CCSTAT_QEVTACTV_NONE (0x00000000u)
#define CSL_EDMA3CC_CCSTAT_QEVTACTV_ACTIVE (0x00000001u)

#define CSL_EDMA3CC_CCSTAT_EVTACTV_MASK  (0x00000001u)
#define CSL_EDMA3CC_CCSTAT_EVTACTV_SHIFT (0x00000000u)
#define CSL_EDMA3CC_CCSTAT_EVTACTV_RESETVAL (0x00000000u)

/*----EVTACTV Tokens----*/
#define CSL_EDMA3CC_CCSTAT_EVTACTV_NONE  (0x00000000u)
#define CSL_EDMA3CC_CCSTAT_EVTACTV_ACTIVE (0x00000001u)

#define CSL_EDMA3CC_CCSTAT_RESETVAL      (0x00000000u)

/* MPFAR */

#define CSL_EDMA3CC_MPFAR_FADDR_MASK     (0xFFFFFFFFu)
#define CSL_EDMA3CC_MPFAR_FADDR_SHIFT    (0x00000000u)
#define CSL_EDMA3CC_MPFAR_FADDR_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_MPFAR_RESETVAL       (0x00000000u)

/* MPFSR */

#define CSL_EDMA3CC_MPFSR_FID_MASK       (0x00001E00u)
#define CSL_EDMA3CC_MPFSR_FID_SHIFT      (0x00000009u)
#define CSL_EDMA3CC_MPFSR_FID_RESETVAL   (0x00000009u)

#define CSL_EDMA3CC_MPFSR_SRE_MASK       (0x00000020u)
#define CSL_EDMA3CC_MPFSR_SRE_SHIFT      (0x00000005u)
#define CSL_EDMA3CC_MPFSR_SRE_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_MPFSR_SWE_MASK       (0x00000010u)
#define CSL_EDMA3CC_MPFSR_SWE_SHIFT      (0x00000004u)
#define CSL_EDMA3CC_MPFSR_SWE_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_MPFSR_SXE_MASK       (0x00000008u)
#define CSL_EDMA3CC_MPFSR_SXE_SHIFT      (0x00000003u)
#define CSL_EDMA3CC_MPFSR_SXE_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_MPFSR_URE_MASK       (0x00000004u)
#define CSL_EDMA3CC_MPFSR_URE_SHIFT      (0x00000002u)
#define CSL_EDMA3CC_MPFSR_URE_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_MPFSR_UWE_MASK       (0x00000002u)
#define CSL_EDMA3CC_MPFSR_UWE_SHIFT      (0x00000001u)
#define CSL_EDMA3CC_MPFSR_UWE_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_MPFSR_UXE_MASK       (0x00000001u)
#define CSL_EDMA3CC_MPFSR_UXE_SHIFT      (0x00000000u)
#define CSL_EDMA3CC_MPFSR_UXE_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_MPFSR_RESETVAL       (0x00001200u)

/* MPFCR */

#define CSL_EDMA3CC_MPFCR_MPFCLR_MASK    (0x00000001u)
#define CSL_EDMA3CC_MPFCR_MPFCLR_SHIFT   (0x00000000u)
#define CSL_EDMA3CC_MPFCR_MPFCLR_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_MPFCR_RESETVAL       (0x00000000u)

/* MPPAG */

#define CSL_EDMA3CC_MPPAG_AID5_MASK      (0x00008000u)
#define CSL_EDMA3CC_MPPAG_AID5_SHIFT     (0x0000000Fu)
#define CSL_EDMA3CC_MPPAG_AID5_RESETVAL  (0x00000001u)

/*----AID5 Tokens----*/
#define CSL_EDMA3CC_MPPAG_AID5_BLOCK     (0x00000000u)
#define CSL_EDMA3CC_MPPAG_AID5_PERMIT    (0x00000001u)

#define CSL_EDMA3CC_MPPAG_AID4_MASK      (0x00004000u)
#define CSL_EDMA3CC_MPPAG_AID4_SHIFT     (0x0000000Eu)
#define CSL_EDMA3CC_MPPAG_AID4_RESETVAL  (0x00000001u)

/*----AID4 Tokens----*/
#define CSL_EDMA3CC_MPPAG_AID4_BLOCK     (0x00000000u)
#define CSL_EDMA3CC_MPPAG_AID4_PERMIT    (0x00000001u)

#define CSL_EDMA3CC_MPPAG_AID3_MASK      (0x00002000u)
#define CSL_EDMA3CC_MPPAG_AID3_SHIFT     (0x0000000Du)
#define CSL_EDMA3CC_MPPAG_AID3_RESETVAL  (0x00000001u)

/*----AID3 Tokens----*/
#define CSL_EDMA3CC_MPPAG_AID3_BLOCK     (0x00000000u)
#define CSL_EDMA3CC_MPPAG_AID3_PERMIT    (0x00000001u)

#define CSL_EDMA3CC_MPPAG_AID2_MASK      (0x00001000u)
#define CSL_EDMA3CC_MPPAG_AID2_SHIFT     (0x0000000Cu)
#define CSL_EDMA3CC_MPPAG_AID2_RESETVAL  (0x00000001u)

/*----AID2 Tokens----*/
#define CSL_EDMA3CC_MPPAG_AID2_BLOCK     (0x00000000u)
#define CSL_EDMA3CC_MPPAG_AID2_PERMIT    (0x00000001u)

#define CSL_EDMA3CC_MPPAG_AID1_MASK      (0x00000800u)
#define CSL_EDMA3CC_MPPAG_AID1_SHIFT     (0x0000000Bu)
#define CSL_EDMA3CC_MPPAG_AID1_RESETVAL  (0x00000001u)

/*----AID1 Tokens----*/
#define CSL_EDMA3CC_MPPAG_AID1_BLOCK     (0x00000000u)
#define CSL_EDMA3CC_MPPAG_AID1_PERMIT    (0x00000001u)

#define CSL_EDMA3CC_MPPAG_AID0_MASK      (0x00000400u)
#define CSL_EDMA3CC_MPPAG_AID0_SHIFT     (0x0000000Au)
#define CSL_EDMA3CC_MPPAG_AID0_RESETVAL  (0x00000001u)

/*----AID0 Tokens----*/
#define CSL_EDMA3CC_MPPAG_AID0_BLOCK     (0x00000000u)
#define CSL_EDMA3CC_MPPAG_AID0_PERMIT    (0x00000001u)

#define CSL_EDMA3CC_MPPAG_EXT_MASK       (0x00000200u)
#define CSL_EDMA3CC_MPPAG_EXT_SHIFT      (0x00000009u)
#define CSL_EDMA3CC_MPPAG_EXT_RESETVAL   (0x00000001u)

/*----EXT Tokens----*/
#define CSL_EDMA3CC_MPPAG_EXT_BLOCK      (0x00000000u)
#define CSL_EDMA3CC_MPPAG_EXT_PERMIT     (0x00000001u)

#define CSL_EDMA3CC_MPPAG_SR_MASK        (0x00000020u)
#define CSL_EDMA3CC_MPPAG_SR_SHIFT       (0x00000005u)
#define CSL_EDMA3CC_MPPAG_SR_RESETVAL    (0x00000001u)

/*----SR Tokens----*/
#define CSL_EDMA3CC_MPPAG_SR_BLOCK       (0x00000000u)
#define CSL_EDMA3CC_MPPAG_SR_PERMIT      (0x00000001u)

#define CSL_EDMA3CC_MPPAG_SW_MASK        (0x00000010u)
#define CSL_EDMA3CC_MPPAG_SW_SHIFT       (0x00000004u)
#define CSL_EDMA3CC_MPPAG_SW_RESETVAL    (0x00000001u)

/*----SW Tokens----*/
#define CSL_EDMA3CC_MPPAG_SW_BLOCK       (0x00000000u)
#define CSL_EDMA3CC_MPPAG_SW_PERMIT      (0x00000001u)

#define CSL_EDMA3CC_MPPAG_SX_MASK        (0x00000008u)
#define CSL_EDMA3CC_MPPAG_SX_SHIFT       (0x00000003u)
#define CSL_EDMA3CC_MPPAG_SX_RESETVAL    (0x00000000u)

/*----SX Tokens----*/
#define CSL_EDMA3CC_MPPAG_SX_BLOCK       (0x00000000u)
#define CSL_EDMA3CC_MPPAG_SX_PERMIT      (0x00000001u)

#define CSL_EDMA3CC_MPPAG_UR_MASK        (0x00000004u)
#define CSL_EDMA3CC_MPPAG_UR_SHIFT       (0x00000002u)
#define CSL_EDMA3CC_MPPAG_UR_RESETVAL    (0x00000001u)

/*----UR Tokens----*/
#define CSL_EDMA3CC_MPPAG_UR_BLOCK       (0x00000000u)
#define CSL_EDMA3CC_MPPAG_UR_PERMIT      (0x00000001u)

#define CSL_EDMA3CC_MPPAG_UW_MASK        (0x00000002u)
#define CSL_EDMA3CC_MPPAG_UW_SHIFT       (0x00000001u)
#define CSL_EDMA3CC_MPPAG_UW_RESETVAL    (0x00000001u)

/*----UW Tokens----*/
#define CSL_EDMA3CC_MPPAG_UW_BLOCK       (0x00000000u)
#define CSL_EDMA3CC_MPPAG_UW_PERMIT      (0x00000001u)

#define CSL_EDMA3CC_MPPAG_UX_MASK        (0x00000001u)
#define CSL_EDMA3CC_MPPAG_UX_SHIFT       (0x00000000u)
#define CSL_EDMA3CC_MPPAG_UX_RESETVAL    (0x00000000u)

/*----UX Tokens----*/
#define CSL_EDMA3CC_MPPAG_UX_BLOCK       (0x00000000u)
#define CSL_EDMA3CC_MPPAG_UX_PERMIT      (0x00000001u)

#define CSL_EDMA3CC_MPPAG_RESETVAL       (0x0000FEF6u)

/* MPPA */

#define CSL_EDMA3CC_MPPA_AID5_MASK       (0x00008000u)
#define CSL_EDMA3CC_MPPA_AID5_SHIFT      (0x0000000Fu)
#define CSL_EDMA3CC_MPPA_AID5_RESETVAL   (0x00000001u)

/*----AID5 Tokens----*/
#define CSL_EDMA3CC_MPPA_AID5_BLOCK      (0x00000000u)
#define CSL_EDMA3CC_MPPA_AID5_PERMIT     (0x00000001u)

#define CSL_EDMA3CC_MPPA_AID4_MASK       (0x00004000u)
#define CSL_EDMA3CC_MPPA_AID4_SHIFT      (0x0000000Eu)
#define CSL_EDMA3CC_MPPA_AID4_RESETVAL   (0x00000001u)

/*----AID4 Tokens----*/
#define CSL_EDMA3CC_MPPA_AID4_BLOCK      (0x00000000u)
#define CSL_EDMA3CC_MPPA_AID4_PERMIT     (0x00000001u)

#define CSL_EDMA3CC_MPPA_AID3_MASK       (0x00002000u)
#define CSL_EDMA3CC_MPPA_AID3_SHIFT      (0x0000000Du)
#define CSL_EDMA3CC_MPPA_AID3_RESETVAL   (0x00000001u)

/*----AID3 Tokens----*/
#define CSL_EDMA3CC_MPPA_AID3_BLOCK      (0x00000000u)
#define CSL_EDMA3CC_MPPA_AID3_PERMIT     (0x00000001u)

#define CSL_EDMA3CC_MPPA_AID2_MASK       (0x00001000u)
#define CSL_EDMA3CC_MPPA_AID2_SHIFT      (0x0000000Cu)
#define CSL_EDMA3CC_MPPA_AID2_RESETVAL   (0x00000001u)

/*----AID2 Tokens----*/
#define CSL_EDMA3CC_MPPA_AID2_BLOCK      (0x00000000u)
#define CSL_EDMA3CC_MPPA_AID2_PERMIT     (0x00000001u)

#define CSL_EDMA3CC_MPPA_AID1_MASK       (0x00000800u)
#define CSL_EDMA3CC_MPPA_AID1_SHIFT      (0x0000000Bu)
#define CSL_EDMA3CC_MPPA_AID1_RESETVAL   (0x00000001u)

/*----AID1 Tokens----*/
#define CSL_EDMA3CC_MPPA_AID1_BLOCK      (0x00000000u)
#define CSL_EDMA3CC_MPPA_AID1_PERMIT     (0x00000001u)

#define CSL_EDMA3CC_MPPA_AID0_MASK       (0x00000400u)
#define CSL_EDMA3CC_MPPA_AID0_SHIFT      (0x0000000Au)
#define CSL_EDMA3CC_MPPA_AID0_RESETVAL   (0x00000001u)

/*----AID0 Tokens----*/
#define CSL_EDMA3CC_MPPA_AID0_BLOCK      (0x00000000u)
#define CSL_EDMA3CC_MPPA_AID0_PERMIT     (0x00000001u)

#define CSL_EDMA3CC_MPPA_EXT_MASK        (0x00000200u)
#define CSL_EDMA3CC_MPPA_EXT_SHIFT       (0x00000009u)
#define CSL_EDMA3CC_MPPA_EXT_RESETVAL    (0x00000001u)

/*----EXT Tokens----*/
#define CSL_EDMA3CC_MPPA_EXT_BLOCK       (0x00000000u)
#define CSL_EDMA3CC_MPPA_EXT_PERMIT      (0x00000001u)

#define CSL_EDMA3CC_MPPA_SR_MASK         (0x00000020u)
#define CSL_EDMA3CC_MPPA_SR_SHIFT        (0x00000005u)
#define CSL_EDMA3CC_MPPA_SR_RESETVAL     (0x00000001u)

/*----SR Tokens----*/
#define CSL_EDMA3CC_MPPA_SR_BLOCK        (0x00000000u)
#define CSL_EDMA3CC_MPPA_SR_PERMIT       (0x00000001u)

#define CSL_EDMA3CC_MPPA_SW_MASK         (0x00000010u)
#define CSL_EDMA3CC_MPPA_SW_SHIFT        (0x00000004u)
#define CSL_EDMA3CC_MPPA_SW_RESETVAL     (0x00000001u)

/*----SW Tokens----*/
#define CSL_EDMA3CC_MPPA_SW_BLOCK        (0x00000000u)
#define CSL_EDMA3CC_MPPA_SW_PERMIT       (0x00000001u)

#define CSL_EDMA3CC_MPPA_SX_MASK         (0x00000008u)
#define CSL_EDMA3CC_MPPA_SX_SHIFT        (0x00000003u)
#define CSL_EDMA3CC_MPPA_SX_RESETVAL     (0x00000000u)

/*----SX Tokens----*/
#define CSL_EDMA3CC_MPPA_SX_BLOCK        (0x00000000u)
#define CSL_EDMA3CC_MPPA_SX_PERMIT       (0x00000001u)

#define CSL_EDMA3CC_MPPA_UR_MASK         (0x00000004u)
#define CSL_EDMA3CC_MPPA_UR_SHIFT        (0x00000002u)
#define CSL_EDMA3CC_MPPA_UR_RESETVAL     (0x00000001u)

/*----UR Tokens----*/
#define CSL_EDMA3CC_MPPA_UR_BLOCK        (0x00000000u)
#define CSL_EDMA3CC_MPPA_UR_PERMIT       (0x00000001u)

#define CSL_EDMA3CC_MPPA_UW_MASK         (0x00000002u)
#define CSL_EDMA3CC_MPPA_UW_SHIFT        (0x00000001u)
#define CSL_EDMA3CC_MPPA_UW_RESETVAL     (0x00000001u)

/*----UW Tokens----*/
#define CSL_EDMA3CC_MPPA_UW_BLOCK        (0x00000000u)
#define CSL_EDMA3CC_MPPA_UW_PERMIT       (0x00000001u)

#define CSL_EDMA3CC_MPPA_UX_MASK         (0x00000001u)
#define CSL_EDMA3CC_MPPA_UX_SHIFT        (0x00000000u)
#define CSL_EDMA3CC_MPPA_UX_RESETVAL     (0x00000000u)

/*----UX Tokens----*/
#define CSL_EDMA3CC_MPPA_UX_BLOCK        (0x00000000u)
#define CSL_EDMA3CC_MPPA_UX_PERMIT       (0x00000001u)

#define CSL_EDMA3CC_MPPA_RESETVAL        (0x0000FEF6u)

/* ER */

#define CSL_EDMA3CC_ER_E31_MASK          (0x80000000u)
#define CSL_EDMA3CC_ER_E31_SHIFT         (0x0000001Fu)
#define CSL_EDMA3CC_ER_E31_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_ER_E30_MASK          (0x40000000u)
#define CSL_EDMA3CC_ER_E30_SHIFT         (0x0000001Eu)
#define CSL_EDMA3CC_ER_E30_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_ER_E29_MASK          (0x20000000u)
#define CSL_EDMA3CC_ER_E29_SHIFT         (0x0000001Du)
#define CSL_EDMA3CC_ER_E29_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_ER_E28_MASK          (0x10000000u)
#define CSL_EDMA3CC_ER_E28_SHIFT         (0x0000001Cu)
#define CSL_EDMA3CC_ER_E28_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_ER_E27_MASK          (0x08000000u)
#define CSL_EDMA3CC_ER_E27_SHIFT         (0x0000001Bu)
#define CSL_EDMA3CC_ER_E27_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_ER_E26_MASK          (0x04000000u)
#define CSL_EDMA3CC_ER_E26_SHIFT         (0x0000001Au)
#define CSL_EDMA3CC_ER_E26_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_ER_E25_MASK          (0x02000000u)
#define CSL_EDMA3CC_ER_E25_SHIFT         (0x00000019u)
#define CSL_EDMA3CC_ER_E25_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_ER_E24_MASK          (0x01000000u)
#define CSL_EDMA3CC_ER_E24_SHIFT         (0x00000018u)
#define CSL_EDMA3CC_ER_E24_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_ER_E23_MASK          (0x00800000u)
#define CSL_EDMA3CC_ER_E23_SHIFT         (0x00000017u)
#define CSL_EDMA3CC_ER_E23_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_ER_E22_MASK          (0x00400000u)
#define CSL_EDMA3CC_ER_E22_SHIFT         (0x00000016u)
#define CSL_EDMA3CC_ER_E22_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_ER_E21_MASK          (0x00200000u)
#define CSL_EDMA3CC_ER_E21_SHIFT         (0x00000015u)
#define CSL_EDMA3CC_ER_E21_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_ER_E20_MASK          (0x00100000u)
#define CSL_EDMA3CC_ER_E20_SHIFT         (0x00000014u)
#define CSL_EDMA3CC_ER_E20_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_ER_E19_MASK          (0x00080000u)
#define CSL_EDMA3CC_ER_E19_SHIFT         (0x00000013u)
#define CSL_EDMA3CC_ER_E19_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_ER_E18_MASK          (0x00040000u)
#define CSL_EDMA3CC_ER_E18_SHIFT         (0x00000012u)
#define CSL_EDMA3CC_ER_E18_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_ER_E17_MASK          (0x00020000u)
#define CSL_EDMA3CC_ER_E17_SHIFT         (0x00000011u)
#define CSL_EDMA3CC_ER_E17_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_ER_E16_MASK          (0x00010000u)
#define CSL_EDMA3CC_ER_E16_SHIFT         (0x00000010u)
#define CSL_EDMA3CC_ER_E16_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_ER_E15_MASK          (0x00008000u)
#define CSL_EDMA3CC_ER_E15_SHIFT         (0x0000000Fu)
#define CSL_EDMA3CC_ER_E15_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_ER_E14_MASK          (0x00004000u)
#define CSL_EDMA3CC_ER_E14_SHIFT         (0x0000000Eu)
#define CSL_EDMA3CC_ER_E14_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_ER_E13_MASK          (0x00002000u)
#define CSL_EDMA3CC_ER_E13_SHIFT         (0x0000000Du)
#define CSL_EDMA3CC_ER_E13_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_ER_E12_MASK          (0x00001000u)
#define CSL_EDMA3CC_ER_E12_SHIFT         (0x0000000Cu)
#define CSL_EDMA3CC_ER_E12_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_ER_E11_MASK          (0x00000800u)
#define CSL_EDMA3CC_ER_E11_SHIFT         (0x0000000Bu)
#define CSL_EDMA3CC_ER_E11_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_ER_E10_MASK          (0x00000400u)
#define CSL_EDMA3CC_ER_E10_SHIFT         (0x0000000Au)
#define CSL_EDMA3CC_ER_E10_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_ER_E9_MASK           (0x00000200u)
#define CSL_EDMA3CC_ER_E9_SHIFT          (0x00000009u)
#define CSL_EDMA3CC_ER_E9_RESETVAL       (0x00000000u)

#define CSL_EDMA3CC_ER_E8_MASK           (0x00000100u)
#define CSL_EDMA3CC_ER_E8_SHIFT          (0x00000008u)
#define CSL_EDMA3CC_ER_E8_RESETVAL       (0x00000000u)

#define CSL_EDMA3CC_ER_E7_MASK           (0x00000080u)
#define CSL_EDMA3CC_ER_E7_SHIFT          (0x00000007u)
#define CSL_EDMA3CC_ER_E7_RESETVAL       (0x00000000u)

#define CSL_EDMA3CC_ER_E6_MASK           (0x00000040u)
#define CSL_EDMA3CC_ER_E6_SHIFT          (0x00000006u)
#define CSL_EDMA3CC_ER_E6_RESETVAL       (0x00000000u)

#define CSL_EDMA3CC_ER_E5_MASK           (0x00000020u)
#define CSL_EDMA3CC_ER_E5_SHIFT          (0x00000005u)
#define CSL_EDMA3CC_ER_E5_RESETVAL       (0x00000000u)

#define CSL_EDMA3CC_ER_E4_MASK           (0x00000010u)
#define CSL_EDMA3CC_ER_E4_SHIFT          (0x00000004u)
#define CSL_EDMA3CC_ER_E4_RESETVAL       (0x00000000u)

#define CSL_EDMA3CC_ER_E3_MASK           (0x00000008u)
#define CSL_EDMA3CC_ER_E3_SHIFT          (0x00000003u)
#define CSL_EDMA3CC_ER_E3_RESETVAL       (0x00000000u)

#define CSL_EDMA3CC_ER_E2_MASK           (0x00000004u)
#define CSL_EDMA3CC_ER_E2_SHIFT          (0x00000002u)
#define CSL_EDMA3CC_ER_E2_RESETVAL       (0x00000000u)

#define CSL_EDMA3CC_ER_E1_MASK           (0x00000002u)
#define CSL_EDMA3CC_ER_E1_SHIFT          (0x00000001u)
#define CSL_EDMA3CC_ER_E1_RESETVAL       (0x00000000u)

#define CSL_EDMA3CC_ER_E0_MASK           (0x00000001u)
#define CSL_EDMA3CC_ER_E0_SHIFT          (0x00000000u)
#define CSL_EDMA3CC_ER_E0_RESETVAL       (0x00000000u)

#define CSL_EDMA3CC_ER_RESETVAL          (0x00000000u)

/* ERH */

#define CSL_EDMA3CC_ERH_E63_MASK         (0x80000000u)
#define CSL_EDMA3CC_ERH_E63_SHIFT        (0x0000001Fu)
#define CSL_EDMA3CC_ERH_E63_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_ERH_E62_MASK         (0x40000000u)
#define CSL_EDMA3CC_ERH_E62_SHIFT        (0x0000001Eu)
#define CSL_EDMA3CC_ERH_E62_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_ERH_E61_MASK         (0x20000000u)
#define CSL_EDMA3CC_ERH_E61_SHIFT        (0x0000001Du)
#define CSL_EDMA3CC_ERH_E61_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_ERH_E60_MASK         (0x10000000u)
#define CSL_EDMA3CC_ERH_E60_SHIFT        (0x0000001Cu)
#define CSL_EDMA3CC_ERH_E60_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_ERH_E59_MASK         (0x08000000u)
#define CSL_EDMA3CC_ERH_E59_SHIFT        (0x0000001Bu)
#define CSL_EDMA3CC_ERH_E59_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_ERH_E58_MASK         (0x04000000u)
#define CSL_EDMA3CC_ERH_E58_SHIFT        (0x0000001Au)
#define CSL_EDMA3CC_ERH_E58_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_ERH_E57_MASK         (0x02000000u)
#define CSL_EDMA3CC_ERH_E57_SHIFT        (0x00000019u)
#define CSL_EDMA3CC_ERH_E57_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_ERH_E56_MASK         (0x01000000u)
#define CSL_EDMA3CC_ERH_E56_SHIFT        (0x00000018u)
#define CSL_EDMA3CC_ERH_E56_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_ERH_E55_MASK         (0x00800000u)
#define CSL_EDMA3CC_ERH_E55_SHIFT        (0x00000017u)
#define CSL_EDMA3CC_ERH_E55_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_ERH_E54_MASK         (0x00400000u)
#define CSL_EDMA3CC_ERH_E54_SHIFT        (0x00000016u)
#define CSL_EDMA3CC_ERH_E54_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_ERH_E53_MASK         (0x00200000u)
#define CSL_EDMA3CC_ERH_E53_SHIFT        (0x00000015u)
#define CSL_EDMA3CC_ERH_E53_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_ERH_E52_MASK         (0x00100000u)
#define CSL_EDMA3CC_ERH_E52_SHIFT        (0x00000014u)
#define CSL_EDMA3CC_ERH_E52_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_ERH_E51_MASK         (0x00080000u)
#define CSL_EDMA3CC_ERH_E51_SHIFT        (0x00000013u)
#define CSL_EDMA3CC_ERH_E51_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_ERH_E50_MASK         (0x00040000u)
#define CSL_EDMA3CC_ERH_E50_SHIFT        (0x00000012u)
#define CSL_EDMA3CC_ERH_E50_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_ERH_E49_MASK         (0x00020000u)
#define CSL_EDMA3CC_ERH_E49_SHIFT        (0x00000011u)
#define CSL_EDMA3CC_ERH_E49_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_ERH_E48_MASK         (0x00010000u)
#define CSL_EDMA3CC_ERH_E48_SHIFT        (0x00000010u)
#define CSL_EDMA3CC_ERH_E48_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_ERH_E47_MASK         (0x00008000u)
#define CSL_EDMA3CC_ERH_E47_SHIFT        (0x0000000Fu)
#define CSL_EDMA3CC_ERH_E47_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_ERH_E46_MASK         (0x00004000u)
#define CSL_EDMA3CC_ERH_E46_SHIFT        (0x0000000Eu)
#define CSL_EDMA3CC_ERH_E46_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_ERH_E45_MASK         (0x00002000u)
#define CSL_EDMA3CC_ERH_E45_SHIFT        (0x0000000Du)
#define CSL_EDMA3CC_ERH_E45_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_ERH_E44_MASK         (0x00001000u)
#define CSL_EDMA3CC_ERH_E44_SHIFT        (0x0000000Cu)
#define CSL_EDMA3CC_ERH_E44_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_ERH_E43_MASK         (0x00000800u)
#define CSL_EDMA3CC_ERH_E43_SHIFT        (0x0000000Bu)
#define CSL_EDMA3CC_ERH_E43_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_ERH_E42_MASK         (0x00000400u)
#define CSL_EDMA3CC_ERH_E42_SHIFT        (0x0000000Au)
#define CSL_EDMA3CC_ERH_E42_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_ERH_E41_MASK         (0x00000200u)
#define CSL_EDMA3CC_ERH_E41_SHIFT        (0x00000009u)
#define CSL_EDMA3CC_ERH_E41_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_ERH_E40_MASK         (0x00000100u)
#define CSL_EDMA3CC_ERH_E40_SHIFT        (0x00000008u)
#define CSL_EDMA3CC_ERH_E40_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_ERH_E39_MASK         (0x00000080u)
#define CSL_EDMA3CC_ERH_E39_SHIFT        (0x00000007u)
#define CSL_EDMA3CC_ERH_E39_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_ERH_E38_MASK         (0x00000040u)
#define CSL_EDMA3CC_ERH_E38_SHIFT        (0x00000006u)
#define CSL_EDMA3CC_ERH_E38_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_ERH_E37_MASK         (0x00000020u)
#define CSL_EDMA3CC_ERH_E37_SHIFT        (0x00000005u)
#define CSL_EDMA3CC_ERH_E37_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_ERH_E36_MASK         (0x00000010u)
#define CSL_EDMA3CC_ERH_E36_SHIFT        (0x00000004u)
#define CSL_EDMA3CC_ERH_E36_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_ERH_E35_MASK         (0x00000008u)
#define CSL_EDMA3CC_ERH_E35_SHIFT        (0x00000003u)
#define CSL_EDMA3CC_ERH_E35_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_ERH_E34_MASK         (0x00000004u)
#define CSL_EDMA3CC_ERH_E34_SHIFT        (0x00000002u)
#define CSL_EDMA3CC_ERH_E34_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_ERH_E33_MASK         (0x00000002u)
#define CSL_EDMA3CC_ERH_E33_SHIFT        (0x00000001u)
#define CSL_EDMA3CC_ERH_E33_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_ERH_E32_MASK         (0x00000001u)
#define CSL_EDMA3CC_ERH_E32_SHIFT        (0x00000000u)
#define CSL_EDMA3CC_ERH_E32_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_ERH_RESETVAL         (0x00000000u)

/* ECR */

#define CSL_EDMA3CC_ECR_E31_MASK         (0x80000000u)
#define CSL_EDMA3CC_ECR_E31_SHIFT        (0x0000001Fu)
#define CSL_EDMA3CC_ECR_E31_RESETVAL     (0x00000000u)

/*----E31 Tokens----*/
#define CSL_EDMA3CC_ECR_E31_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_ECR_E30_MASK         (0x40000000u)
#define CSL_EDMA3CC_ECR_E30_SHIFT        (0x0000001Eu)
#define CSL_EDMA3CC_ECR_E30_RESETVAL     (0x00000000u)

/*----E30 Tokens----*/
#define CSL_EDMA3CC_ECR_E30_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_ECR_E29_MASK         (0x20000000u)
#define CSL_EDMA3CC_ECR_E29_SHIFT        (0x0000001Du)
#define CSL_EDMA3CC_ECR_E29_RESETVAL     (0x00000000u)

/*----E29 Tokens----*/
#define CSL_EDMA3CC_ECR_E29_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_ECR_E28_MASK         (0x10000000u)
#define CSL_EDMA3CC_ECR_E28_SHIFT        (0x0000001Cu)
#define CSL_EDMA3CC_ECR_E28_RESETVAL     (0x00000000u)

/*----E28 Tokens----*/
#define CSL_EDMA3CC_ECR_E28_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_ECR_E27_MASK         (0x08000000u)
#define CSL_EDMA3CC_ECR_E27_SHIFT        (0x0000001Bu)
#define CSL_EDMA3CC_ECR_E27_RESETVAL     (0x00000000u)

/*----E27 Tokens----*/
#define CSL_EDMA3CC_ECR_E27_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_ECR_E26_MASK         (0x04000000u)
#define CSL_EDMA3CC_ECR_E26_SHIFT        (0x0000001Au)
#define CSL_EDMA3CC_ECR_E26_RESETVAL     (0x00000000u)

/*----E26 Tokens----*/
#define CSL_EDMA3CC_ECR_E26_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_ECR_E25_MASK         (0x02000000u)
#define CSL_EDMA3CC_ECR_E25_SHIFT        (0x00000019u)
#define CSL_EDMA3CC_ECR_E25_RESETVAL     (0x00000000u)

/*----E25 Tokens----*/
#define CSL_EDMA3CC_ECR_E25_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_ECR_E24_MASK         (0x01000000u)
#define CSL_EDMA3CC_ECR_E24_SHIFT        (0x00000018u)
#define CSL_EDMA3CC_ECR_E24_RESETVAL     (0x00000000u)

/*----E24 Tokens----*/
#define CSL_EDMA3CC_ECR_E24_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_ECR_E23_MASK         (0x00800000u)
#define CSL_EDMA3CC_ECR_E23_SHIFT        (0x00000017u)
#define CSL_EDMA3CC_ECR_E23_RESETVAL     (0x00000000u)

/*----E23 Tokens----*/
#define CSL_EDMA3CC_ECR_E23_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_ECR_E22_MASK         (0x00400000u)
#define CSL_EDMA3CC_ECR_E22_SHIFT        (0x00000016u)
#define CSL_EDMA3CC_ECR_E22_RESETVAL     (0x00000000u)

/*----E22 Tokens----*/
#define CSL_EDMA3CC_ECR_E22_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_ECR_E21_MASK         (0x00200000u)
#define CSL_EDMA3CC_ECR_E21_SHIFT        (0x00000015u)
#define CSL_EDMA3CC_ECR_E21_RESETVAL     (0x00000000u)

/*----E21 Tokens----*/
#define CSL_EDMA3CC_ECR_E21_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_ECR_E20_MASK         (0x00100000u)
#define CSL_EDMA3CC_ECR_E20_SHIFT        (0x00000014u)
#define CSL_EDMA3CC_ECR_E20_RESETVAL     (0x00000000u)

/*----E20 Tokens----*/
#define CSL_EDMA3CC_ECR_E20_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_ECR_E19_MASK         (0x00080000u)
#define CSL_EDMA3CC_ECR_E19_SHIFT        (0x00000013u)
#define CSL_EDMA3CC_ECR_E19_RESETVAL     (0x00000000u)

/*----E19 Tokens----*/
#define CSL_EDMA3CC_ECR_E19_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_ECR_E18_MASK         (0x00040000u)
#define CSL_EDMA3CC_ECR_E18_SHIFT        (0x00000012u)
#define CSL_EDMA3CC_ECR_E18_RESETVAL     (0x00000000u)

/*----E18 Tokens----*/
#define CSL_EDMA3CC_ECR_E18_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_ECR_E17_MASK         (0x00020000u)
#define CSL_EDMA3CC_ECR_E17_SHIFT        (0x00000011u)
#define CSL_EDMA3CC_ECR_E17_RESETVAL     (0x00000000u)

/*----E17 Tokens----*/
#define CSL_EDMA3CC_ECR_E17_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_ECR_E16_MASK         (0x00010000u)
#define CSL_EDMA3CC_ECR_E16_SHIFT        (0x00000010u)
#define CSL_EDMA3CC_ECR_E16_RESETVAL     (0x00000000u)

/*----E16 Tokens----*/
#define CSL_EDMA3CC_ECR_E16_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_ECR_E15_MASK         (0x00008000u)
#define CSL_EDMA3CC_ECR_E15_SHIFT        (0x0000000Fu)
#define CSL_EDMA3CC_ECR_E15_RESETVAL     (0x00000000u)

/*----E15 Tokens----*/
#define CSL_EDMA3CC_ECR_E15_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_ECR_E14_MASK         (0x00004000u)
#define CSL_EDMA3CC_ECR_E14_SHIFT        (0x0000000Eu)
#define CSL_EDMA3CC_ECR_E14_RESETVAL     (0x00000000u)

/*----E14 Tokens----*/
#define CSL_EDMA3CC_ECR_E14_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_ECR_E13_MASK         (0x00002000u)
#define CSL_EDMA3CC_ECR_E13_SHIFT        (0x0000000Du)
#define CSL_EDMA3CC_ECR_E13_RESETVAL     (0x00000000u)

/*----E13 Tokens----*/
#define CSL_EDMA3CC_ECR_E13_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_ECR_E12_MASK         (0x00001000u)
#define CSL_EDMA3CC_ECR_E12_SHIFT        (0x0000000Cu)
#define CSL_EDMA3CC_ECR_E12_RESETVAL     (0x00000000u)

/*----E12 Tokens----*/
#define CSL_EDMA3CC_ECR_E12_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_ECR_E11_MASK         (0x00000800u)
#define CSL_EDMA3CC_ECR_E11_SHIFT        (0x0000000Bu)
#define CSL_EDMA3CC_ECR_E11_RESETVAL     (0x00000000u)

/*----E11 Tokens----*/
#define CSL_EDMA3CC_ECR_E11_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_ECR_E10_MASK         (0x00000400u)
#define CSL_EDMA3CC_ECR_E10_SHIFT        (0x0000000Au)
#define CSL_EDMA3CC_ECR_E10_RESETVAL     (0x00000000u)

/*----E10 Tokens----*/
#define CSL_EDMA3CC_ECR_E10_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_ECR_E9_MASK          (0x00000200u)
#define CSL_EDMA3CC_ECR_E9_SHIFT         (0x00000009u)
#define CSL_EDMA3CC_ECR_E9_RESETVAL      (0x00000000u)

/*----E9 Tokens----*/
#define CSL_EDMA3CC_ECR_E9_CLEAR         (0x00000001u)

#define CSL_EDMA3CC_ECR_E8_MASK          (0x00000100u)
#define CSL_EDMA3CC_ECR_E8_SHIFT         (0x00000008u)
#define CSL_EDMA3CC_ECR_E8_RESETVAL      (0x00000000u)

/*----E8 Tokens----*/
#define CSL_EDMA3CC_ECR_E8_CLEAR         (0x00000001u)

#define CSL_EDMA3CC_ECR_E7_MASK          (0x00000080u)
#define CSL_EDMA3CC_ECR_E7_SHIFT         (0x00000007u)
#define CSL_EDMA3CC_ECR_E7_RESETVAL      (0x00000000u)

/*----E7 Tokens----*/
#define CSL_EDMA3CC_ECR_E7_CLEAR         (0x00000001u)

#define CSL_EDMA3CC_ECR_E6_MASK          (0x00000040u)
#define CSL_EDMA3CC_ECR_E6_SHIFT         (0x00000006u)
#define CSL_EDMA3CC_ECR_E6_RESETVAL      (0x00000000u)

/*----E6 Tokens----*/
#define CSL_EDMA3CC_ECR_E6_CLEAR         (0x00000001u)

#define CSL_EDMA3CC_ECR_E5_MASK          (0x00000020u)
#define CSL_EDMA3CC_ECR_E5_SHIFT         (0x00000005u)
#define CSL_EDMA3CC_ECR_E5_RESETVAL      (0x00000000u)

/*----E5 Tokens----*/
#define CSL_EDMA3CC_ECR_E5_CLEAR         (0x00000001u)

#define CSL_EDMA3CC_ECR_E4_MASK          (0x00000010u)
#define CSL_EDMA3CC_ECR_E4_SHIFT         (0x00000004u)
#define CSL_EDMA3CC_ECR_E4_RESETVAL      (0x00000000u)

/*----E4 Tokens----*/
#define CSL_EDMA3CC_ECR_E4_CLEAR         (0x00000001u)

#define CSL_EDMA3CC_ECR_E3_MASK          (0x00000008u)
#define CSL_EDMA3CC_ECR_E3_SHIFT         (0x00000003u)
#define CSL_EDMA3CC_ECR_E3_RESETVAL      (0x00000000u)

/*----E3 Tokens----*/
#define CSL_EDMA3CC_ECR_E3_CLEAR         (0x00000001u)

#define CSL_EDMA3CC_ECR_E2_MASK          (0x00000004u)
#define CSL_EDMA3CC_ECR_E2_SHIFT         (0x00000002u)
#define CSL_EDMA3CC_ECR_E2_RESETVAL      (0x00000000u)

/*----E2 Tokens----*/
#define CSL_EDMA3CC_ECR_E2_CLEAR         (0x00000001u)

#define CSL_EDMA3CC_ECR_E1_MASK          (0x00000002u)
#define CSL_EDMA3CC_ECR_E1_SHIFT         (0x00000001u)
#define CSL_EDMA3CC_ECR_E1_RESETVAL      (0x00000000u)

/*----E1 Tokens----*/
#define CSL_EDMA3CC_ECR_E1_CLEAR         (0x00000001u)

#define CSL_EDMA3CC_ECR_E0_MASK          (0x00000001u)
#define CSL_EDMA3CC_ECR_E0_SHIFT         (0x00000000u)
#define CSL_EDMA3CC_ECR_E0_RESETVAL      (0x00000000u)

/*----E0 Tokens----*/
#define CSL_EDMA3CC_ECR_E0_CLEAR         (0x00000001u)

#define CSL_EDMA3CC_ECR_RESETVAL         (0x00000000u)

/* ECRH */

#define CSL_EDMA3CC_ECRH_E63_MASK        (0x80000000u)
#define CSL_EDMA3CC_ECRH_E63_SHIFT       (0x0000001Fu)
#define CSL_EDMA3CC_ECRH_E63_RESETVAL    (0x00000000u)

/*----E63 Tokens----*/
#define CSL_EDMA3CC_ECRH_E63_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ECRH_E62_MASK        (0x40000000u)
#define CSL_EDMA3CC_ECRH_E62_SHIFT       (0x0000001Eu)
#define CSL_EDMA3CC_ECRH_E62_RESETVAL    (0x00000000u)

/*----E62 Tokens----*/
#define CSL_EDMA3CC_ECRH_E62_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ECRH_E61_MASK        (0x20000000u)
#define CSL_EDMA3CC_ECRH_E61_SHIFT       (0x0000001Du)
#define CSL_EDMA3CC_ECRH_E61_RESETVAL    (0x00000000u)

/*----E61 Tokens----*/
#define CSL_EDMA3CC_ECRH_E61_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ECRH_E60_MASK        (0x10000000u)
#define CSL_EDMA3CC_ECRH_E60_SHIFT       (0x0000001Cu)
#define CSL_EDMA3CC_ECRH_E60_RESETVAL    (0x00000000u)

/*----E60 Tokens----*/
#define CSL_EDMA3CC_ECRH_E60_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ECRH_E59_MASK        (0x08000000u)
#define CSL_EDMA3CC_ECRH_E59_SHIFT       (0x0000001Bu)
#define CSL_EDMA3CC_ECRH_E59_RESETVAL    (0x00000000u)

/*----E59 Tokens----*/
#define CSL_EDMA3CC_ECRH_E59_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ECRH_E58_MASK        (0x04000000u)
#define CSL_EDMA3CC_ECRH_E58_SHIFT       (0x0000001Au)
#define CSL_EDMA3CC_ECRH_E58_RESETVAL    (0x00000000u)

/*----E58 Tokens----*/
#define CSL_EDMA3CC_ECRH_E58_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ECRH_E57_MASK        (0x02000000u)
#define CSL_EDMA3CC_ECRH_E57_SHIFT       (0x00000019u)
#define CSL_EDMA3CC_ECRH_E57_RESETVAL    (0x00000000u)

/*----E57 Tokens----*/
#define CSL_EDMA3CC_ECRH_E57_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ECRH_E56_MASK        (0x01000000u)
#define CSL_EDMA3CC_ECRH_E56_SHIFT       (0x00000018u)
#define CSL_EDMA3CC_ECRH_E56_RESETVAL    (0x00000000u)

/*----E56 Tokens----*/
#define CSL_EDMA3CC_ECRH_E56_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ECRH_E55_MASK        (0x00800000u)
#define CSL_EDMA3CC_ECRH_E55_SHIFT       (0x00000017u)
#define CSL_EDMA3CC_ECRH_E55_RESETVAL    (0x00000000u)

/*----E55 Tokens----*/
#define CSL_EDMA3CC_ECRH_E55_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ECRH_E54_MASK        (0x00400000u)
#define CSL_EDMA3CC_ECRH_E54_SHIFT       (0x00000016u)
#define CSL_EDMA3CC_ECRH_E54_RESETVAL    (0x00000000u)

/*----E54 Tokens----*/
#define CSL_EDMA3CC_ECRH_E54_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ECRH_E53_MASK        (0x00200000u)
#define CSL_EDMA3CC_ECRH_E53_SHIFT       (0x00000015u)
#define CSL_EDMA3CC_ECRH_E53_RESETVAL    (0x00000000u)

/*----E53 Tokens----*/
#define CSL_EDMA3CC_ECRH_E53_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ECRH_E52_MASK        (0x00100000u)
#define CSL_EDMA3CC_ECRH_E52_SHIFT       (0x00000014u)
#define CSL_EDMA3CC_ECRH_E52_RESETVAL    (0x00000000u)

/*----E52 Tokens----*/
#define CSL_EDMA3CC_ECRH_E52_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ECRH_E51_MASK        (0x00080000u)
#define CSL_EDMA3CC_ECRH_E51_SHIFT       (0x00000013u)
#define CSL_EDMA3CC_ECRH_E51_RESETVAL    (0x00000000u)

/*----E51 Tokens----*/
#define CSL_EDMA3CC_ECRH_E51_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ECRH_E50_MASK        (0x00040000u)
#define CSL_EDMA3CC_ECRH_E50_SHIFT       (0x00000012u)
#define CSL_EDMA3CC_ECRH_E50_RESETVAL    (0x00000000u)

/*----E50 Tokens----*/
#define CSL_EDMA3CC_ECRH_E50_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ECRH_E49_MASK        (0x00020000u)
#define CSL_EDMA3CC_ECRH_E49_SHIFT       (0x00000011u)
#define CSL_EDMA3CC_ECRH_E49_RESETVAL    (0x00000000u)

/*----E49 Tokens----*/
#define CSL_EDMA3CC_ECRH_E49_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ECRH_E48_MASK        (0x00010000u)
#define CSL_EDMA3CC_ECRH_E48_SHIFT       (0x00000010u)
#define CSL_EDMA3CC_ECRH_E48_RESETVAL    (0x00000000u)

/*----E48 Tokens----*/
#define CSL_EDMA3CC_ECRH_E48_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ECRH_E47_MASK        (0x00008000u)
#define CSL_EDMA3CC_ECRH_E47_SHIFT       (0x0000000Fu)
#define CSL_EDMA3CC_ECRH_E47_RESETVAL    (0x00000000u)

/*----E47 Tokens----*/
#define CSL_EDMA3CC_ECRH_E47_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ECRH_E46_MASK        (0x00004000u)
#define CSL_EDMA3CC_ECRH_E46_SHIFT       (0x0000000Eu)
#define CSL_EDMA3CC_ECRH_E46_RESETVAL    (0x00000000u)

/*----E46 Tokens----*/
#define CSL_EDMA3CC_ECRH_E46_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ECRH_E45_MASK        (0x00002000u)
#define CSL_EDMA3CC_ECRH_E45_SHIFT       (0x0000000Du)
#define CSL_EDMA3CC_ECRH_E45_RESETVAL    (0x00000000u)

/*----E45 Tokens----*/
#define CSL_EDMA3CC_ECRH_E45_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ECRH_E44_MASK        (0x00001000u)
#define CSL_EDMA3CC_ECRH_E44_SHIFT       (0x0000000Cu)
#define CSL_EDMA3CC_ECRH_E44_RESETVAL    (0x00000000u)

/*----E44 Tokens----*/
#define CSL_EDMA3CC_ECRH_E44_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ECRH_E43_MASK        (0x00000800u)
#define CSL_EDMA3CC_ECRH_E43_SHIFT       (0x0000000Bu)
#define CSL_EDMA3CC_ECRH_E43_RESETVAL    (0x00000000u)

/*----E43 Tokens----*/
#define CSL_EDMA3CC_ECRH_E43_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ECRH_E42_MASK        (0x00000400u)
#define CSL_EDMA3CC_ECRH_E42_SHIFT       (0x0000000Au)
#define CSL_EDMA3CC_ECRH_E42_RESETVAL    (0x00000000u)

/*----E42 Tokens----*/
#define CSL_EDMA3CC_ECRH_E42_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ECRH_E41_MASK        (0x00000200u)
#define CSL_EDMA3CC_ECRH_E41_SHIFT       (0x00000009u)
#define CSL_EDMA3CC_ECRH_E41_RESETVAL    (0x00000000u)

/*----E41 Tokens----*/
#define CSL_EDMA3CC_ECRH_E41_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ECRH_E40_MASK        (0x00000100u)
#define CSL_EDMA3CC_ECRH_E40_SHIFT       (0x00000008u)
#define CSL_EDMA3CC_ECRH_E40_RESETVAL    (0x00000000u)

/*----E40 Tokens----*/
#define CSL_EDMA3CC_ECRH_E40_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ECRH_E39_MASK        (0x00000080u)
#define CSL_EDMA3CC_ECRH_E39_SHIFT       (0x00000007u)
#define CSL_EDMA3CC_ECRH_E39_RESETVAL    (0x00000000u)

/*----E39 Tokens----*/
#define CSL_EDMA3CC_ECRH_E39_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ECRH_E38_MASK        (0x00000040u)
#define CSL_EDMA3CC_ECRH_E38_SHIFT       (0x00000006u)
#define CSL_EDMA3CC_ECRH_E38_RESETVAL    (0x00000000u)

/*----E38 Tokens----*/
#define CSL_EDMA3CC_ECRH_E38_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ECRH_E37_MASK        (0x00000020u)
#define CSL_EDMA3CC_ECRH_E37_SHIFT       (0x00000005u)
#define CSL_EDMA3CC_ECRH_E37_RESETVAL    (0x00000000u)

/*----E37 Tokens----*/
#define CSL_EDMA3CC_ECRH_E37_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ECRH_E36_MASK        (0x00000010u)
#define CSL_EDMA3CC_ECRH_E36_SHIFT       (0x00000004u)
#define CSL_EDMA3CC_ECRH_E36_RESETVAL    (0x00000000u)

/*----E36 Tokens----*/
#define CSL_EDMA3CC_ECRH_E36_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ECRH_E35_MASK        (0x00000008u)
#define CSL_EDMA3CC_ECRH_E35_SHIFT       (0x00000003u)
#define CSL_EDMA3CC_ECRH_E35_RESETVAL    (0x00000000u)

/*----E35 Tokens----*/
#define CSL_EDMA3CC_ECRH_E35_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ECRH_E34_MASK        (0x00000004u)
#define CSL_EDMA3CC_ECRH_E34_SHIFT       (0x00000002u)
#define CSL_EDMA3CC_ECRH_E34_RESETVAL    (0x00000000u)

/*----E34 Tokens----*/
#define CSL_EDMA3CC_ECRH_E34_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ECRH_E33_MASK        (0x00000002u)
#define CSL_EDMA3CC_ECRH_E33_SHIFT       (0x00000001u)
#define CSL_EDMA3CC_ECRH_E33_RESETVAL    (0x00000000u)

/*----E33 Tokens----*/
#define CSL_EDMA3CC_ECRH_E33_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ECRH_E32_MASK        (0x00000001u)
#define CSL_EDMA3CC_ECRH_E32_SHIFT       (0x00000000u)
#define CSL_EDMA3CC_ECRH_E32_RESETVAL    (0x00000000u)

/*----E32 Tokens----*/
#define CSL_EDMA3CC_ECRH_E32_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ECRH_RESETVAL        (0x00000000u)

/* ESR */

#define CSL_EDMA3CC_ESR_E31_MASK         (0x80000000u)
#define CSL_EDMA3CC_ESR_E31_SHIFT        (0x0000001Fu)
#define CSL_EDMA3CC_ESR_E31_RESETVAL     (0x00000000u)

/*----E31 Tokens----*/
#define CSL_EDMA3CC_ESR_E31_SET          (0x00000001u)

#define CSL_EDMA3CC_ESR_E30_MASK         (0x40000000u)
#define CSL_EDMA3CC_ESR_E30_SHIFT        (0x0000001Eu)
#define CSL_EDMA3CC_ESR_E30_RESETVAL     (0x00000000u)

/*----E30 Tokens----*/
#define CSL_EDMA3CC_ESR_E30_SET          (0x00000001u)

#define CSL_EDMA3CC_ESR_E29_MASK         (0x20000000u)
#define CSL_EDMA3CC_ESR_E29_SHIFT        (0x0000001Du)
#define CSL_EDMA3CC_ESR_E29_RESETVAL     (0x00000000u)

/*----E29 Tokens----*/
#define CSL_EDMA3CC_ESR_E29_SET          (0x00000001u)

#define CSL_EDMA3CC_ESR_E28_MASK         (0x10000000u)
#define CSL_EDMA3CC_ESR_E28_SHIFT        (0x0000001Cu)
#define CSL_EDMA3CC_ESR_E28_RESETVAL     (0x00000000u)

/*----E28 Tokens----*/
#define CSL_EDMA3CC_ESR_E28_SET          (0x00000001u)

#define CSL_EDMA3CC_ESR_E27_MASK         (0x08000000u)
#define CSL_EDMA3CC_ESR_E27_SHIFT        (0x0000001Bu)
#define CSL_EDMA3CC_ESR_E27_RESETVAL     (0x00000000u)

/*----E27 Tokens----*/
#define CSL_EDMA3CC_ESR_E27_SET          (0x00000001u)

#define CSL_EDMA3CC_ESR_E26_MASK         (0x04000000u)
#define CSL_EDMA3CC_ESR_E26_SHIFT        (0x0000001Au)
#define CSL_EDMA3CC_ESR_E26_RESETVAL     (0x00000000u)

/*----E26 Tokens----*/
#define CSL_EDMA3CC_ESR_E26_SET          (0x00000001u)

#define CSL_EDMA3CC_ESR_E25_MASK         (0x02000000u)
#define CSL_EDMA3CC_ESR_E25_SHIFT        (0x00000019u)
#define CSL_EDMA3CC_ESR_E25_RESETVAL     (0x00000000u)

/*----E25 Tokens----*/
#define CSL_EDMA3CC_ESR_E25_SET          (0x00000001u)

#define CSL_EDMA3CC_ESR_E24_MASK         (0x01000000u)
#define CSL_EDMA3CC_ESR_E24_SHIFT        (0x00000018u)
#define CSL_EDMA3CC_ESR_E24_RESETVAL     (0x00000000u)

/*----E24 Tokens----*/
#define CSL_EDMA3CC_ESR_E24_SET          (0x00000001u)

#define CSL_EDMA3CC_ESR_E23_MASK         (0x00800000u)
#define CSL_EDMA3CC_ESR_E23_SHIFT        (0x00000017u)
#define CSL_EDMA3CC_ESR_E23_RESETVAL     (0x00000000u)

/*----E23 Tokens----*/
#define CSL_EDMA3CC_ESR_E23_SET          (0x00000001u)

#define CSL_EDMA3CC_ESR_E22_MASK         (0x00400000u)
#define CSL_EDMA3CC_ESR_E22_SHIFT        (0x00000016u)
#define CSL_EDMA3CC_ESR_E22_RESETVAL     (0x00000000u)

/*----E22 Tokens----*/
#define CSL_EDMA3CC_ESR_E22_SET          (0x00000001u)

#define CSL_EDMA3CC_ESR_E21_MASK         (0x00200000u)
#define CSL_EDMA3CC_ESR_E21_SHIFT        (0x00000015u)
#define CSL_EDMA3CC_ESR_E21_RESETVAL     (0x00000000u)

/*----E21 Tokens----*/
#define CSL_EDMA3CC_ESR_E21_SET          (0x00000001u)

#define CSL_EDMA3CC_ESR_E20_MASK         (0x00100000u)
#define CSL_EDMA3CC_ESR_E20_SHIFT        (0x00000014u)
#define CSL_EDMA3CC_ESR_E20_RESETVAL     (0x00000000u)

/*----E20 Tokens----*/
#define CSL_EDMA3CC_ESR_E20_SET          (0x00000001u)

#define CSL_EDMA3CC_ESR_E19_MASK         (0x00080000u)
#define CSL_EDMA3CC_ESR_E19_SHIFT        (0x00000013u)
#define CSL_EDMA3CC_ESR_E19_RESETVAL     (0x00000000u)

/*----E19 Tokens----*/
#define CSL_EDMA3CC_ESR_E19_SET          (0x00000001u)

#define CSL_EDMA3CC_ESR_E18_MASK         (0x00040000u)
#define CSL_EDMA3CC_ESR_E18_SHIFT        (0x00000012u)
#define CSL_EDMA3CC_ESR_E18_RESETVAL     (0x00000000u)

/*----E18 Tokens----*/
#define CSL_EDMA3CC_ESR_E18_SET          (0x00000001u)

#define CSL_EDMA3CC_ESR_E17_MASK         (0x00020000u)
#define CSL_EDMA3CC_ESR_E17_SHIFT        (0x00000011u)
#define CSL_EDMA3CC_ESR_E17_RESETVAL     (0x00000000u)

/*----E17 Tokens----*/
#define CSL_EDMA3CC_ESR_E17_SET          (0x00000001u)

#define CSL_EDMA3CC_ESR_E16_MASK         (0x00010000u)
#define CSL_EDMA3CC_ESR_E16_SHIFT        (0x00000010u)
#define CSL_EDMA3CC_ESR_E16_RESETVAL     (0x00000000u)

/*----E16 Tokens----*/
#define CSL_EDMA3CC_ESR_E16_SET          (0x00000001u)

#define CSL_EDMA3CC_ESR_E15_MASK         (0x00008000u)
#define CSL_EDMA3CC_ESR_E15_SHIFT        (0x0000000Fu)
#define CSL_EDMA3CC_ESR_E15_RESETVAL     (0x00000000u)

/*----E15 Tokens----*/
#define CSL_EDMA3CC_ESR_E15_SET          (0x00000001u)

#define CSL_EDMA3CC_ESR_E14_MASK         (0x00004000u)
#define CSL_EDMA3CC_ESR_E14_SHIFT        (0x0000000Eu)
#define CSL_EDMA3CC_ESR_E14_RESETVAL     (0x00000000u)

/*----E14 Tokens----*/
#define CSL_EDMA3CC_ESR_E14_SET          (0x00000001u)

#define CSL_EDMA3CC_ESR_E13_MASK         (0x00002000u)
#define CSL_EDMA3CC_ESR_E13_SHIFT        (0x0000000Du)
#define CSL_EDMA3CC_ESR_E13_RESETVAL     (0x00000000u)

/*----E13 Tokens----*/
#define CSL_EDMA3CC_ESR_E13_SET          (0x00000001u)

#define CSL_EDMA3CC_ESR_E12_MASK         (0x00001000u)
#define CSL_EDMA3CC_ESR_E12_SHIFT        (0x0000000Cu)
#define CSL_EDMA3CC_ESR_E12_RESETVAL     (0x00000000u)

/*----E12 Tokens----*/
#define CSL_EDMA3CC_ESR_E12_SET          (0x00000001u)

#define CSL_EDMA3CC_ESR_E11_MASK         (0x00000800u)
#define CSL_EDMA3CC_ESR_E11_SHIFT        (0x0000000Bu)
#define CSL_EDMA3CC_ESR_E11_RESETVAL     (0x00000000u)

/*----E11 Tokens----*/
#define CSL_EDMA3CC_ESR_E11_SET          (0x00000001u)

#define CSL_EDMA3CC_ESR_E10_MASK         (0x00000400u)
#define CSL_EDMA3CC_ESR_E10_SHIFT        (0x0000000Au)
#define CSL_EDMA3CC_ESR_E10_RESETVAL     (0x00000000u)

/*----E10 Tokens----*/
#define CSL_EDMA3CC_ESR_E10_SET          (0x00000001u)

#define CSL_EDMA3CC_ESR_E9_MASK          (0x00000200u)
#define CSL_EDMA3CC_ESR_E9_SHIFT         (0x00000009u)
#define CSL_EDMA3CC_ESR_E9_RESETVAL      (0x00000000u)

/*----E9 Tokens----*/
#define CSL_EDMA3CC_ESR_E9_SET           (0x00000001u)

#define CSL_EDMA3CC_ESR_E8_MASK          (0x00000100u)
#define CSL_EDMA3CC_ESR_E8_SHIFT         (0x00000008u)
#define CSL_EDMA3CC_ESR_E8_RESETVAL      (0x00000000u)

/*----E8 Tokens----*/
#define CSL_EDMA3CC_ESR_E8_SET           (0x00000001u)

#define CSL_EDMA3CC_ESR_E7_MASK          (0x00000080u)
#define CSL_EDMA3CC_ESR_E7_SHIFT         (0x00000007u)
#define CSL_EDMA3CC_ESR_E7_RESETVAL      (0x00000000u)

/*----E7 Tokens----*/
#define CSL_EDMA3CC_ESR_E7_SET           (0x00000001u)

#define CSL_EDMA3CC_ESR_E6_MASK          (0x00000040u)
#define CSL_EDMA3CC_ESR_E6_SHIFT         (0x00000006u)
#define CSL_EDMA3CC_ESR_E6_RESETVAL      (0x00000000u)

/*----E6 Tokens----*/
#define CSL_EDMA3CC_ESR_E6_SET           (0x00000001u)

#define CSL_EDMA3CC_ESR_E5_MASK          (0x00000020u)
#define CSL_EDMA3CC_ESR_E5_SHIFT         (0x00000005u)
#define CSL_EDMA3CC_ESR_E5_RESETVAL      (0x00000000u)

/*----E5 Tokens----*/
#define CSL_EDMA3CC_ESR_E5_SET           (0x00000001u)

#define CSL_EDMA3CC_ESR_E4_MASK          (0x00000010u)
#define CSL_EDMA3CC_ESR_E4_SHIFT         (0x00000004u)
#define CSL_EDMA3CC_ESR_E4_RESETVAL      (0x00000000u)

/*----E4 Tokens----*/
#define CSL_EDMA3CC_ESR_E4_SET           (0x00000001u)

#define CSL_EDMA3CC_ESR_E3_MASK          (0x00000008u)
#define CSL_EDMA3CC_ESR_E3_SHIFT         (0x00000003u)
#define CSL_EDMA3CC_ESR_E3_RESETVAL      (0x00000000u)

/*----E3 Tokens----*/
#define CSL_EDMA3CC_ESR_E3_SET           (0x00000001u)

#define CSL_EDMA3CC_ESR_E2_MASK          (0x00000004u)
#define CSL_EDMA3CC_ESR_E2_SHIFT         (0x00000002u)
#define CSL_EDMA3CC_ESR_E2_RESETVAL      (0x00000000u)

/*----E2 Tokens----*/
#define CSL_EDMA3CC_ESR_E2_SET           (0x00000001u)

#define CSL_EDMA3CC_ESR_E1_MASK          (0x00000002u)
#define CSL_EDMA3CC_ESR_E1_SHIFT         (0x00000001u)
#define CSL_EDMA3CC_ESR_E1_RESETVAL      (0x00000000u)

/*----E1 Tokens----*/
#define CSL_EDMA3CC_ESR_E1_SET           (0x00000001u)

#define CSL_EDMA3CC_ESR_E0_MASK          (0x00000001u)
#define CSL_EDMA3CC_ESR_E0_SHIFT         (0x00000000u)
#define CSL_EDMA3CC_ESR_E0_RESETVAL      (0x00000000u)

/*----E0 Tokens----*/
#define CSL_EDMA3CC_ESR_E0_SET           (0x00000001u)

#define CSL_EDMA3CC_ESR_RESETVAL         (0x00000000u)

/* ESRH */

#define CSL_EDMA3CC_ESRH_E63_MASK        (0x80000000u)
#define CSL_EDMA3CC_ESRH_E63_SHIFT       (0x0000001Fu)
#define CSL_EDMA3CC_ESRH_E63_RESETVAL    (0x00000000u)

/*----E63 Tokens----*/
#define CSL_EDMA3CC_ESRH_E63_SET         (0x00000001u)

#define CSL_EDMA3CC_ESRH_E62_MASK        (0x40000000u)
#define CSL_EDMA3CC_ESRH_E62_SHIFT       (0x0000001Eu)
#define CSL_EDMA3CC_ESRH_E62_RESETVAL    (0x00000000u)

/*----E62 Tokens----*/
#define CSL_EDMA3CC_ESRH_E62_SET         (0x00000001u)

#define CSL_EDMA3CC_ESRH_E61_MASK        (0x20000000u)
#define CSL_EDMA3CC_ESRH_E61_SHIFT       (0x0000001Du)
#define CSL_EDMA3CC_ESRH_E61_RESETVAL    (0x00000000u)

/*----E61 Tokens----*/
#define CSL_EDMA3CC_ESRH_E61_SET         (0x00000001u)

#define CSL_EDMA3CC_ESRH_E60_MASK        (0x10000000u)
#define CSL_EDMA3CC_ESRH_E60_SHIFT       (0x0000001Cu)
#define CSL_EDMA3CC_ESRH_E60_RESETVAL    (0x00000000u)

/*----E60 Tokens----*/
#define CSL_EDMA3CC_ESRH_E60_SET         (0x00000001u)

#define CSL_EDMA3CC_ESRH_E59_MASK        (0x08000000u)
#define CSL_EDMA3CC_ESRH_E59_SHIFT       (0x0000001Bu)
#define CSL_EDMA3CC_ESRH_E59_RESETVAL    (0x00000000u)

/*----E59 Tokens----*/
#define CSL_EDMA3CC_ESRH_E59_SET         (0x00000001u)

#define CSL_EDMA3CC_ESRH_E58_MASK        (0x04000000u)
#define CSL_EDMA3CC_ESRH_E58_SHIFT       (0x0000001Au)
#define CSL_EDMA3CC_ESRH_E58_RESETVAL    (0x00000000u)

/*----E58 Tokens----*/
#define CSL_EDMA3CC_ESRH_E58_SET         (0x00000001u)

#define CSL_EDMA3CC_ESRH_E57_MASK        (0x02000000u)
#define CSL_EDMA3CC_ESRH_E57_SHIFT       (0x00000019u)
#define CSL_EDMA3CC_ESRH_E57_RESETVAL    (0x00000000u)

/*----E57 Tokens----*/
#define CSL_EDMA3CC_ESRH_E57_SET         (0x00000001u)

#define CSL_EDMA3CC_ESRH_E56_MASK        (0x01000000u)
#define CSL_EDMA3CC_ESRH_E56_SHIFT       (0x00000018u)
#define CSL_EDMA3CC_ESRH_E56_RESETVAL    (0x00000000u)

/*----E56 Tokens----*/
#define CSL_EDMA3CC_ESRH_E56_SET         (0x00000001u)

#define CSL_EDMA3CC_ESRH_E55_MASK        (0x00800000u)
#define CSL_EDMA3CC_ESRH_E55_SHIFT       (0x00000017u)
#define CSL_EDMA3CC_ESRH_E55_RESETVAL    (0x00000000u)

/*----E55 Tokens----*/
#define CSL_EDMA3CC_ESRH_E55_SET         (0x00000001u)

#define CSL_EDMA3CC_ESRH_E54_MASK        (0x00400000u)
#define CSL_EDMA3CC_ESRH_E54_SHIFT       (0x00000016u)
#define CSL_EDMA3CC_ESRH_E54_RESETVAL    (0x00000000u)

/*----E54 Tokens----*/
#define CSL_EDMA3CC_ESRH_E54_SET         (0x00000001u)

#define CSL_EDMA3CC_ESRH_E53_MASK        (0x00200000u)
#define CSL_EDMA3CC_ESRH_E53_SHIFT       (0x00000015u)
#define CSL_EDMA3CC_ESRH_E53_RESETVAL    (0x00000000u)

/*----E53 Tokens----*/
#define CSL_EDMA3CC_ESRH_E53_SET         (0x00000001u)

#define CSL_EDMA3CC_ESRH_E52_MASK        (0x00100000u)
#define CSL_EDMA3CC_ESRH_E52_SHIFT       (0x00000014u)
#define CSL_EDMA3CC_ESRH_E52_RESETVAL    (0x00000000u)

/*----E52 Tokens----*/
#define CSL_EDMA3CC_ESRH_E52_SET         (0x00000001u)

#define CSL_EDMA3CC_ESRH_E51_MASK        (0x00080000u)
#define CSL_EDMA3CC_ESRH_E51_SHIFT       (0x00000013u)
#define CSL_EDMA3CC_ESRH_E51_RESETVAL    (0x00000000u)

/*----E51 Tokens----*/
#define CSL_EDMA3CC_ESRH_E51_SET         (0x00000001u)

#define CSL_EDMA3CC_ESRH_E50_MASK        (0x00040000u)
#define CSL_EDMA3CC_ESRH_E50_SHIFT       (0x00000012u)
#define CSL_EDMA3CC_ESRH_E50_RESETVAL    (0x00000000u)

/*----E50 Tokens----*/
#define CSL_EDMA3CC_ESRH_E50_SET         (0x00000001u)

#define CSL_EDMA3CC_ESRH_E49_MASK        (0x00020000u)
#define CSL_EDMA3CC_ESRH_E49_SHIFT       (0x00000011u)
#define CSL_EDMA3CC_ESRH_E49_RESETVAL    (0x00000000u)

/*----E49 Tokens----*/
#define CSL_EDMA3CC_ESRH_E49_SET         (0x00000001u)

#define CSL_EDMA3CC_ESRH_E48_MASK        (0x00010000u)
#define CSL_EDMA3CC_ESRH_E48_SHIFT       (0x00000010u)
#define CSL_EDMA3CC_ESRH_E48_RESETVAL    (0x00000000u)

/*----E48 Tokens----*/
#define CSL_EDMA3CC_ESRH_E48_SET         (0x00000001u)

#define CSL_EDMA3CC_ESRH_E47_MASK        (0x00008000u)
#define CSL_EDMA3CC_ESRH_E47_SHIFT       (0x0000000Fu)
#define CSL_EDMA3CC_ESRH_E47_RESETVAL    (0x00000000u)

/*----E47 Tokens----*/
#define CSL_EDMA3CC_ESRH_E47_SET         (0x00000001u)

#define CSL_EDMA3CC_ESRH_E46_MASK        (0x00004000u)
#define CSL_EDMA3CC_ESRH_E46_SHIFT       (0x0000000Eu)
#define CSL_EDMA3CC_ESRH_E46_RESETVAL    (0x00000000u)

/*----E46 Tokens----*/
#define CSL_EDMA3CC_ESRH_E46_SET         (0x00000001u)

#define CSL_EDMA3CC_ESRH_E45_MASK        (0x00002000u)
#define CSL_EDMA3CC_ESRH_E45_SHIFT       (0x0000000Du)
#define CSL_EDMA3CC_ESRH_E45_RESETVAL    (0x00000000u)

/*----E45 Tokens----*/
#define CSL_EDMA3CC_ESRH_E45_SET         (0x00000001u)

#define CSL_EDMA3CC_ESRH_E44_MASK        (0x00001000u)
#define CSL_EDMA3CC_ESRH_E44_SHIFT       (0x0000000Cu)
#define CSL_EDMA3CC_ESRH_E44_RESETVAL    (0x00000000u)

/*----E44 Tokens----*/
#define CSL_EDMA3CC_ESRH_E44_SET         (0x00000001u)

#define CSL_EDMA3CC_ESRH_E43_MASK        (0x00000800u)
#define CSL_EDMA3CC_ESRH_E43_SHIFT       (0x0000000Bu)
#define CSL_EDMA3CC_ESRH_E43_RESETVAL    (0x00000000u)

/*----E43 Tokens----*/
#define CSL_EDMA3CC_ESRH_E43_SET         (0x00000001u)

#define CSL_EDMA3CC_ESRH_E42_MASK        (0x00000400u)
#define CSL_EDMA3CC_ESRH_E42_SHIFT       (0x0000000Au)
#define CSL_EDMA3CC_ESRH_E42_RESETVAL    (0x00000000u)

/*----E42 Tokens----*/
#define CSL_EDMA3CC_ESRH_E42_SET         (0x00000001u)

#define CSL_EDMA3CC_ESRH_E41_MASK        (0x00000200u)
#define CSL_EDMA3CC_ESRH_E41_SHIFT       (0x00000009u)
#define CSL_EDMA3CC_ESRH_E41_RESETVAL    (0x00000000u)

/*----E41 Tokens----*/
#define CSL_EDMA3CC_ESRH_E41_SET         (0x00000001u)

#define CSL_EDMA3CC_ESRH_E40_MASK        (0x00000100u)
#define CSL_EDMA3CC_ESRH_E40_SHIFT       (0x00000008u)
#define CSL_EDMA3CC_ESRH_E40_RESETVAL    (0x00000000u)

/*----E40 Tokens----*/
#define CSL_EDMA3CC_ESRH_E40_SET         (0x00000001u)

#define CSL_EDMA3CC_ESRH_E39_MASK        (0x00000080u)
#define CSL_EDMA3CC_ESRH_E39_SHIFT       (0x00000007u)
#define CSL_EDMA3CC_ESRH_E39_RESETVAL    (0x00000000u)

/*----E39 Tokens----*/
#define CSL_EDMA3CC_ESRH_E39_SET         (0x00000001u)

#define CSL_EDMA3CC_ESRH_E38_MASK        (0x00000040u)
#define CSL_EDMA3CC_ESRH_E38_SHIFT       (0x00000006u)
#define CSL_EDMA3CC_ESRH_E38_RESETVAL    (0x00000000u)

/*----E38 Tokens----*/
#define CSL_EDMA3CC_ESRH_E38_SET         (0x00000001u)

#define CSL_EDMA3CC_ESRH_E37_MASK        (0x00000020u)
#define CSL_EDMA3CC_ESRH_E37_SHIFT       (0x00000005u)
#define CSL_EDMA3CC_ESRH_E37_RESETVAL    (0x00000000u)

/*----E37 Tokens----*/
#define CSL_EDMA3CC_ESRH_E37_SET         (0x00000001u)

#define CSL_EDMA3CC_ESRH_E36_MASK        (0x00000010u)
#define CSL_EDMA3CC_ESRH_E36_SHIFT       (0x00000004u)
#define CSL_EDMA3CC_ESRH_E36_RESETVAL    (0x00000000u)

/*----E36 Tokens----*/
#define CSL_EDMA3CC_ESRH_E36_SET         (0x00000001u)

#define CSL_EDMA3CC_ESRH_E35_MASK        (0x00000008u)
#define CSL_EDMA3CC_ESRH_E35_SHIFT       (0x00000003u)
#define CSL_EDMA3CC_ESRH_E35_RESETVAL    (0x00000000u)

/*----E35 Tokens----*/
#define CSL_EDMA3CC_ESRH_E35_SET         (0x00000001u)

#define CSL_EDMA3CC_ESRH_E34_MASK        (0x00000004u)
#define CSL_EDMA3CC_ESRH_E34_SHIFT       (0x00000002u)
#define CSL_EDMA3CC_ESRH_E34_RESETVAL    (0x00000000u)

/*----E34 Tokens----*/
#define CSL_EDMA3CC_ESRH_E34_SET         (0x00000001u)

#define CSL_EDMA3CC_ESRH_E33_MASK        (0x00000002u)
#define CSL_EDMA3CC_ESRH_E33_SHIFT       (0x00000001u)
#define CSL_EDMA3CC_ESRH_E33_RESETVAL    (0x00000000u)

/*----E33 Tokens----*/
#define CSL_EDMA3CC_ESRH_E33_SET         (0x00000001u)

#define CSL_EDMA3CC_ESRH_E32_MASK        (0x00000001u)
#define CSL_EDMA3CC_ESRH_E32_SHIFT       (0x00000000u)
#define CSL_EDMA3CC_ESRH_E32_RESETVAL    (0x00000000u)

/*----E32 Tokens----*/
#define CSL_EDMA3CC_ESRH_E32_SET         (0x00000001u)

#define CSL_EDMA3CC_ESRH_RESETVAL        (0x00000000u)

/* CER */

#define CSL_EDMA3CC_CER_E31_MASK         (0x80000000u)
#define CSL_EDMA3CC_CER_E31_SHIFT        (0x0000001Fu)
#define CSL_EDMA3CC_CER_E31_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_CER_E30_MASK         (0x40000000u)
#define CSL_EDMA3CC_CER_E30_SHIFT        (0x0000001Eu)
#define CSL_EDMA3CC_CER_E30_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_CER_E29_MASK         (0x20000000u)
#define CSL_EDMA3CC_CER_E29_SHIFT        (0x0000001Du)
#define CSL_EDMA3CC_CER_E29_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_CER_E28_MASK         (0x10000000u)
#define CSL_EDMA3CC_CER_E28_SHIFT        (0x0000001Cu)
#define CSL_EDMA3CC_CER_E28_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_CER_E27_MASK         (0x08000000u)
#define CSL_EDMA3CC_CER_E27_SHIFT        (0x0000001Bu)
#define CSL_EDMA3CC_CER_E27_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_CER_E26_MASK         (0x04000000u)
#define CSL_EDMA3CC_CER_E26_SHIFT        (0x0000001Au)
#define CSL_EDMA3CC_CER_E26_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_CER_E25_MASK         (0x02000000u)
#define CSL_EDMA3CC_CER_E25_SHIFT        (0x00000019u)
#define CSL_EDMA3CC_CER_E25_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_CER_E24_MASK         (0x01000000u)
#define CSL_EDMA3CC_CER_E24_SHIFT        (0x00000018u)
#define CSL_EDMA3CC_CER_E24_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_CER_E23_MASK         (0x00800000u)
#define CSL_EDMA3CC_CER_E23_SHIFT        (0x00000017u)
#define CSL_EDMA3CC_CER_E23_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_CER_E22_MASK         (0x00400000u)
#define CSL_EDMA3CC_CER_E22_SHIFT        (0x00000016u)
#define CSL_EDMA3CC_CER_E22_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_CER_E21_MASK         (0x00200000u)
#define CSL_EDMA3CC_CER_E21_SHIFT        (0x00000015u)
#define CSL_EDMA3CC_CER_E21_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_CER_E20_MASK         (0x00100000u)
#define CSL_EDMA3CC_CER_E20_SHIFT        (0x00000014u)
#define CSL_EDMA3CC_CER_E20_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_CER_E19_MASK         (0x00080000u)
#define CSL_EDMA3CC_CER_E19_SHIFT        (0x00000013u)
#define CSL_EDMA3CC_CER_E19_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_CER_E18_MASK         (0x00040000u)
#define CSL_EDMA3CC_CER_E18_SHIFT        (0x00000012u)
#define CSL_EDMA3CC_CER_E18_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_CER_E17_MASK         (0x00020000u)
#define CSL_EDMA3CC_CER_E17_SHIFT        (0x00000011u)
#define CSL_EDMA3CC_CER_E17_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_CER_E16_MASK         (0x00010000u)
#define CSL_EDMA3CC_CER_E16_SHIFT        (0x00000010u)
#define CSL_EDMA3CC_CER_E16_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_CER_E15_MASK         (0x00008000u)
#define CSL_EDMA3CC_CER_E15_SHIFT        (0x0000000Fu)
#define CSL_EDMA3CC_CER_E15_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_CER_E14_MASK         (0x00004000u)
#define CSL_EDMA3CC_CER_E14_SHIFT        (0x0000000Eu)
#define CSL_EDMA3CC_CER_E14_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_CER_E13_MASK         (0x00002000u)
#define CSL_EDMA3CC_CER_E13_SHIFT        (0x0000000Du)
#define CSL_EDMA3CC_CER_E13_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_CER_E12_MASK         (0x00001000u)
#define CSL_EDMA3CC_CER_E12_SHIFT        (0x0000000Cu)
#define CSL_EDMA3CC_CER_E12_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_CER_E11_MASK         (0x00000800u)
#define CSL_EDMA3CC_CER_E11_SHIFT        (0x0000000Bu)
#define CSL_EDMA3CC_CER_E11_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_CER_E10_MASK         (0x00000400u)
#define CSL_EDMA3CC_CER_E10_SHIFT        (0x0000000Au)
#define CSL_EDMA3CC_CER_E10_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_CER_E9_MASK          (0x00000200u)
#define CSL_EDMA3CC_CER_E9_SHIFT         (0x00000009u)
#define CSL_EDMA3CC_CER_E9_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_CER_E8_MASK          (0x00000100u)
#define CSL_EDMA3CC_CER_E8_SHIFT         (0x00000008u)
#define CSL_EDMA3CC_CER_E8_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_CER_E7_MASK          (0x00000080u)
#define CSL_EDMA3CC_CER_E7_SHIFT         (0x00000007u)
#define CSL_EDMA3CC_CER_E7_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_CER_E6_MASK          (0x00000040u)
#define CSL_EDMA3CC_CER_E6_SHIFT         (0x00000006u)
#define CSL_EDMA3CC_CER_E6_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_CER_E5_MASK          (0x00000020u)
#define CSL_EDMA3CC_CER_E5_SHIFT         (0x00000005u)
#define CSL_EDMA3CC_CER_E5_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_CER_E4_MASK          (0x00000010u)
#define CSL_EDMA3CC_CER_E4_SHIFT         (0x00000004u)
#define CSL_EDMA3CC_CER_E4_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_CER_E3_MASK          (0x00000008u)
#define CSL_EDMA3CC_CER_E3_SHIFT         (0x00000003u)
#define CSL_EDMA3CC_CER_E3_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_CER_E2_MASK          (0x00000004u)
#define CSL_EDMA3CC_CER_E2_SHIFT         (0x00000002u)
#define CSL_EDMA3CC_CER_E2_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_CER_E1_MASK          (0x00000002u)
#define CSL_EDMA3CC_CER_E1_SHIFT         (0x00000001u)
#define CSL_EDMA3CC_CER_E1_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_CER_E0_MASK          (0x00000001u)
#define CSL_EDMA3CC_CER_E0_SHIFT         (0x00000000u)
#define CSL_EDMA3CC_CER_E0_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_CER_RESETVAL         (0x00000000u)

/* CERH */

#define CSL_EDMA3CC_CERH_E63_MASK        (0x80000000u)
#define CSL_EDMA3CC_CERH_E63_SHIFT       (0x0000001Fu)
#define CSL_EDMA3CC_CERH_E63_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_CERH_E62_MASK        (0x40000000u)
#define CSL_EDMA3CC_CERH_E62_SHIFT       (0x0000001Eu)
#define CSL_EDMA3CC_CERH_E62_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_CERH_E61_MASK        (0x20000000u)
#define CSL_EDMA3CC_CERH_E61_SHIFT       (0x0000001Du)
#define CSL_EDMA3CC_CERH_E61_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_CERH_E60_MASK        (0x10000000u)
#define CSL_EDMA3CC_CERH_E60_SHIFT       (0x0000001Cu)
#define CSL_EDMA3CC_CERH_E60_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_CERH_E59_MASK        (0x08000000u)
#define CSL_EDMA3CC_CERH_E59_SHIFT       (0x0000001Bu)
#define CSL_EDMA3CC_CERH_E59_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_CERH_E58_MASK        (0x04000000u)
#define CSL_EDMA3CC_CERH_E58_SHIFT       (0x0000001Au)
#define CSL_EDMA3CC_CERH_E58_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_CERH_E57_MASK        (0x02000000u)
#define CSL_EDMA3CC_CERH_E57_SHIFT       (0x00000019u)
#define CSL_EDMA3CC_CERH_E57_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_CERH_E56_MASK        (0x01000000u)
#define CSL_EDMA3CC_CERH_E56_SHIFT       (0x00000018u)
#define CSL_EDMA3CC_CERH_E56_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_CERH_E55_MASK        (0x00800000u)
#define CSL_EDMA3CC_CERH_E55_SHIFT       (0x00000017u)
#define CSL_EDMA3CC_CERH_E55_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_CERH_E54_MASK        (0x00400000u)
#define CSL_EDMA3CC_CERH_E54_SHIFT       (0x00000016u)
#define CSL_EDMA3CC_CERH_E54_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_CERH_E53_MASK        (0x00200000u)
#define CSL_EDMA3CC_CERH_E53_SHIFT       (0x00000015u)
#define CSL_EDMA3CC_CERH_E53_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_CERH_E52_MASK        (0x00100000u)
#define CSL_EDMA3CC_CERH_E52_SHIFT       (0x00000014u)
#define CSL_EDMA3CC_CERH_E52_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_CERH_E51_MASK        (0x00080000u)
#define CSL_EDMA3CC_CERH_E51_SHIFT       (0x00000013u)
#define CSL_EDMA3CC_CERH_E51_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_CERH_E50_MASK        (0x00040000u)
#define CSL_EDMA3CC_CERH_E50_SHIFT       (0x00000012u)
#define CSL_EDMA3CC_CERH_E50_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_CERH_E49_MASK        (0x00020000u)
#define CSL_EDMA3CC_CERH_E49_SHIFT       (0x00000011u)
#define CSL_EDMA3CC_CERH_E49_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_CERH_E48_MASK        (0x00010000u)
#define CSL_EDMA3CC_CERH_E48_SHIFT       (0x00000010u)
#define CSL_EDMA3CC_CERH_E48_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_CERH_E47_MASK        (0x00008000u)
#define CSL_EDMA3CC_CERH_E47_SHIFT       (0x0000000Fu)
#define CSL_EDMA3CC_CERH_E47_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_CERH_E46_MASK        (0x00004000u)
#define CSL_EDMA3CC_CERH_E46_SHIFT       (0x0000000Eu)
#define CSL_EDMA3CC_CERH_E46_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_CERH_E45_MASK        (0x00002000u)
#define CSL_EDMA3CC_CERH_E45_SHIFT       (0x0000000Du)
#define CSL_EDMA3CC_CERH_E45_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_CERH_E44_MASK        (0x00001000u)
#define CSL_EDMA3CC_CERH_E44_SHIFT       (0x0000000Cu)
#define CSL_EDMA3CC_CERH_E44_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_CERH_E43_MASK        (0x00000800u)
#define CSL_EDMA3CC_CERH_E43_SHIFT       (0x0000000Bu)
#define CSL_EDMA3CC_CERH_E43_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_CERH_E42_MASK        (0x00000400u)
#define CSL_EDMA3CC_CERH_E42_SHIFT       (0x0000000Au)
#define CSL_EDMA3CC_CERH_E42_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_CERH_E41_MASK        (0x00000200u)
#define CSL_EDMA3CC_CERH_E41_SHIFT       (0x00000009u)
#define CSL_EDMA3CC_CERH_E41_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_CERH_E40_MASK        (0x00000100u)
#define CSL_EDMA3CC_CERH_E40_SHIFT       (0x00000008u)
#define CSL_EDMA3CC_CERH_E40_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_CERH_E39_MASK        (0x00000080u)
#define CSL_EDMA3CC_CERH_E39_SHIFT       (0x00000007u)
#define CSL_EDMA3CC_CERH_E39_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_CERH_E38_MASK        (0x00000040u)
#define CSL_EDMA3CC_CERH_E38_SHIFT       (0x00000006u)
#define CSL_EDMA3CC_CERH_E38_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_CERH_E37_MASK        (0x00000020u)
#define CSL_EDMA3CC_CERH_E37_SHIFT       (0x00000005u)
#define CSL_EDMA3CC_CERH_E37_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_CERH_E36_MASK        (0x00000010u)
#define CSL_EDMA3CC_CERH_E36_SHIFT       (0x00000004u)
#define CSL_EDMA3CC_CERH_E36_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_CERH_E35_MASK        (0x00000008u)
#define CSL_EDMA3CC_CERH_E35_SHIFT       (0x00000003u)
#define CSL_EDMA3CC_CERH_E35_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_CERH_E34_MASK        (0x00000004u)
#define CSL_EDMA3CC_CERH_E34_SHIFT       (0x00000002u)
#define CSL_EDMA3CC_CERH_E34_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_CERH_E33_MASK        (0x00000002u)
#define CSL_EDMA3CC_CERH_E33_SHIFT       (0x00000001u)
#define CSL_EDMA3CC_CERH_E33_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_CERH_E32_MASK        (0x00000001u)
#define CSL_EDMA3CC_CERH_E32_SHIFT       (0x00000000u)
#define CSL_EDMA3CC_CERH_E32_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_CERH_RESETVAL        (0x00000000u)

/* EER */

#define CSL_EDMA3CC_EER_E31_MASK         (0x80000000u)
#define CSL_EDMA3CC_EER_E31_SHIFT        (0x0000001Fu)
#define CSL_EDMA3CC_EER_E31_RESETVAL     (0x00000000u)

/*----E31 Tokens----*/
#define CSL_EDMA3CC_EER_E31_             (0x00000001u)

#define CSL_EDMA3CC_EER_E30_MASK         (0x40000000u)
#define CSL_EDMA3CC_EER_E30_SHIFT        (0x0000001Eu)
#define CSL_EDMA3CC_EER_E30_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_EER_E29_MASK         (0x20000000u)
#define CSL_EDMA3CC_EER_E29_SHIFT        (0x0000001Du)
#define CSL_EDMA3CC_EER_E29_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_EER_E28_MASK         (0x10000000u)
#define CSL_EDMA3CC_EER_E28_SHIFT        (0x0000001Cu)
#define CSL_EDMA3CC_EER_E28_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_EER_E27_MASK         (0x08000000u)
#define CSL_EDMA3CC_EER_E27_SHIFT        (0x0000001Bu)
#define CSL_EDMA3CC_EER_E27_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_EER_E26_MASK         (0x04000000u)
#define CSL_EDMA3CC_EER_E26_SHIFT        (0x0000001Au)
#define CSL_EDMA3CC_EER_E26_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_EER_E25_MASK         (0x02000000u)
#define CSL_EDMA3CC_EER_E25_SHIFT        (0x00000019u)
#define CSL_EDMA3CC_EER_E25_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_EER_E24_MASK         (0x01000000u)
#define CSL_EDMA3CC_EER_E24_SHIFT        (0x00000018u)
#define CSL_EDMA3CC_EER_E24_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_EER_E23_MASK         (0x00800000u)
#define CSL_EDMA3CC_EER_E23_SHIFT        (0x00000017u)
#define CSL_EDMA3CC_EER_E23_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_EER_E22_MASK         (0x00400000u)
#define CSL_EDMA3CC_EER_E22_SHIFT        (0x00000016u)
#define CSL_EDMA3CC_EER_E22_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_EER_E21_MASK         (0x00200000u)
#define CSL_EDMA3CC_EER_E21_SHIFT        (0x00000015u)
#define CSL_EDMA3CC_EER_E21_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_EER_E20_MASK         (0x00100000u)
#define CSL_EDMA3CC_EER_E20_SHIFT        (0x00000014u)
#define CSL_EDMA3CC_EER_E20_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_EER_E19_MASK         (0x00080000u)
#define CSL_EDMA3CC_EER_E19_SHIFT        (0x00000013u)
#define CSL_EDMA3CC_EER_E19_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_EER_E18_MASK         (0x00040000u)
#define CSL_EDMA3CC_EER_E18_SHIFT        (0x00000012u)
#define CSL_EDMA3CC_EER_E18_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_EER_E17_MASK         (0x00020000u)
#define CSL_EDMA3CC_EER_E17_SHIFT        (0x00000011u)
#define CSL_EDMA3CC_EER_E17_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_EER_E16_MASK         (0x00010000u)
#define CSL_EDMA3CC_EER_E16_SHIFT        (0x00000010u)
#define CSL_EDMA3CC_EER_E16_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_EER_E15_MASK         (0x00008000u)
#define CSL_EDMA3CC_EER_E15_SHIFT        (0x0000000Fu)
#define CSL_EDMA3CC_EER_E15_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_EER_E14_MASK         (0x00004000u)
#define CSL_EDMA3CC_EER_E14_SHIFT        (0x0000000Eu)
#define CSL_EDMA3CC_EER_E14_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_EER_E13_MASK         (0x00002000u)
#define CSL_EDMA3CC_EER_E13_SHIFT        (0x0000000Du)
#define CSL_EDMA3CC_EER_E13_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_EER_E12_MASK         (0x00001000u)
#define CSL_EDMA3CC_EER_E12_SHIFT        (0x0000000Cu)
#define CSL_EDMA3CC_EER_E12_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_EER_E11_MASK         (0x00000800u)
#define CSL_EDMA3CC_EER_E11_SHIFT        (0x0000000Bu)
#define CSL_EDMA3CC_EER_E11_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_EER_E10_MASK         (0x00000400u)
#define CSL_EDMA3CC_EER_E10_SHIFT        (0x0000000Au)
#define CSL_EDMA3CC_EER_E10_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_EER_E9_MASK          (0x00000200u)
#define CSL_EDMA3CC_EER_E9_SHIFT         (0x00000009u)
#define CSL_EDMA3CC_EER_E9_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_EER_E8_MASK          (0x00000100u)
#define CSL_EDMA3CC_EER_E8_SHIFT         (0x00000008u)
#define CSL_EDMA3CC_EER_E8_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_EER_E7_MASK          (0x00000080u)
#define CSL_EDMA3CC_EER_E7_SHIFT         (0x00000007u)
#define CSL_EDMA3CC_EER_E7_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_EER_E6_MASK          (0x00000040u)
#define CSL_EDMA3CC_EER_E6_SHIFT         (0x00000006u)
#define CSL_EDMA3CC_EER_E6_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_EER_E5_MASK          (0x00000020u)
#define CSL_EDMA3CC_EER_E5_SHIFT         (0x00000005u)
#define CSL_EDMA3CC_EER_E5_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_EER_E4_MASK          (0x00000010u)
#define CSL_EDMA3CC_EER_E4_SHIFT         (0x00000004u)
#define CSL_EDMA3CC_EER_E4_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_EER_E3_MASK          (0x00000008u)
#define CSL_EDMA3CC_EER_E3_SHIFT         (0x00000003u)
#define CSL_EDMA3CC_EER_E3_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_EER_E2_MASK          (0x00000004u)
#define CSL_EDMA3CC_EER_E2_SHIFT         (0x00000002u)
#define CSL_EDMA3CC_EER_E2_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_EER_E1_MASK          (0x00000002u)
#define CSL_EDMA3CC_EER_E1_SHIFT         (0x00000001u)
#define CSL_EDMA3CC_EER_E1_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_EER_E0_MASK          (0x00000001u)
#define CSL_EDMA3CC_EER_E0_SHIFT         (0x00000000u)
#define CSL_EDMA3CC_EER_E0_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_EER_RESETVAL         (0x00000000u)

/* EERH */

#define CSL_EDMA3CC_EERH_E63_MASK        (0x80000000u)
#define CSL_EDMA3CC_EERH_E63_SHIFT       (0x0000001Fu)
#define CSL_EDMA3CC_EERH_E63_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EERH_E62_MASK        (0x40000000u)
#define CSL_EDMA3CC_EERH_E62_SHIFT       (0x0000001Eu)
#define CSL_EDMA3CC_EERH_E62_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EERH_E61_MASK        (0x20000000u)
#define CSL_EDMA3CC_EERH_E61_SHIFT       (0x0000001Du)
#define CSL_EDMA3CC_EERH_E61_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EERH_E60_MASK        (0x10000000u)
#define CSL_EDMA3CC_EERH_E60_SHIFT       (0x0000001Cu)
#define CSL_EDMA3CC_EERH_E60_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EERH_E59_MASK        (0x08000000u)
#define CSL_EDMA3CC_EERH_E59_SHIFT       (0x0000001Bu)
#define CSL_EDMA3CC_EERH_E59_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EERH_E58_MASK        (0x04000000u)
#define CSL_EDMA3CC_EERH_E58_SHIFT       (0x0000001Au)
#define CSL_EDMA3CC_EERH_E58_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EERH_E57_MASK        (0x02000000u)
#define CSL_EDMA3CC_EERH_E57_SHIFT       (0x00000019u)
#define CSL_EDMA3CC_EERH_E57_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EERH_E56_MASK        (0x01000000u)
#define CSL_EDMA3CC_EERH_E56_SHIFT       (0x00000018u)
#define CSL_EDMA3CC_EERH_E56_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EERH_E55_MASK        (0x00800000u)
#define CSL_EDMA3CC_EERH_E55_SHIFT       (0x00000017u)
#define CSL_EDMA3CC_EERH_E55_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EERH_E54_MASK        (0x00400000u)
#define CSL_EDMA3CC_EERH_E54_SHIFT       (0x00000016u)
#define CSL_EDMA3CC_EERH_E54_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EERH_E53_MASK        (0x00200000u)
#define CSL_EDMA3CC_EERH_E53_SHIFT       (0x00000015u)
#define CSL_EDMA3CC_EERH_E53_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EERH_E52_MASK        (0x00100000u)
#define CSL_EDMA3CC_EERH_E52_SHIFT       (0x00000014u)
#define CSL_EDMA3CC_EERH_E52_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EERH_E51_MASK        (0x00080000u)
#define CSL_EDMA3CC_EERH_E51_SHIFT       (0x00000013u)
#define CSL_EDMA3CC_EERH_E51_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EERH_E50_MASK        (0x00040000u)
#define CSL_EDMA3CC_EERH_E50_SHIFT       (0x00000012u)
#define CSL_EDMA3CC_EERH_E50_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EERH_E49_MASK        (0x00020000u)
#define CSL_EDMA3CC_EERH_E49_SHIFT       (0x00000011u)
#define CSL_EDMA3CC_EERH_E49_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EERH_E48_MASK        (0x00010000u)
#define CSL_EDMA3CC_EERH_E48_SHIFT       (0x00000010u)
#define CSL_EDMA3CC_EERH_E48_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EERH_E47_MASK        (0x00008000u)
#define CSL_EDMA3CC_EERH_E47_SHIFT       (0x0000000Fu)
#define CSL_EDMA3CC_EERH_E47_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EERH_E46_MASK        (0x00004000u)
#define CSL_EDMA3CC_EERH_E46_SHIFT       (0x0000000Eu)
#define CSL_EDMA3CC_EERH_E46_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EERH_E45_MASK        (0x00002000u)
#define CSL_EDMA3CC_EERH_E45_SHIFT       (0x0000000Du)
#define CSL_EDMA3CC_EERH_E45_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EERH_E44_MASK        (0x00001000u)
#define CSL_EDMA3CC_EERH_E44_SHIFT       (0x0000000Cu)
#define CSL_EDMA3CC_EERH_E44_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EERH_E43_MASK        (0x00000800u)
#define CSL_EDMA3CC_EERH_E43_SHIFT       (0x0000000Bu)
#define CSL_EDMA3CC_EERH_E43_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EERH_E42_MASK        (0x00000400u)
#define CSL_EDMA3CC_EERH_E42_SHIFT       (0x0000000Au)
#define CSL_EDMA3CC_EERH_E42_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EERH_E41_MASK        (0x00000200u)
#define CSL_EDMA3CC_EERH_E41_SHIFT       (0x00000009u)
#define CSL_EDMA3CC_EERH_E41_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EERH_E40_MASK        (0x00000100u)
#define CSL_EDMA3CC_EERH_E40_SHIFT       (0x00000008u)
#define CSL_EDMA3CC_EERH_E40_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EERH_E39_MASK        (0x00000080u)
#define CSL_EDMA3CC_EERH_E39_SHIFT       (0x00000007u)
#define CSL_EDMA3CC_EERH_E39_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EERH_E38_MASK        (0x00000040u)
#define CSL_EDMA3CC_EERH_E38_SHIFT       (0x00000006u)
#define CSL_EDMA3CC_EERH_E38_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EERH_E37_MASK        (0x00000020u)
#define CSL_EDMA3CC_EERH_E37_SHIFT       (0x00000005u)
#define CSL_EDMA3CC_EERH_E37_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EERH_E36_MASK        (0x00000010u)
#define CSL_EDMA3CC_EERH_E36_SHIFT       (0x00000004u)
#define CSL_EDMA3CC_EERH_E36_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EERH_E35_MASK        (0x00000008u)
#define CSL_EDMA3CC_EERH_E35_SHIFT       (0x00000003u)
#define CSL_EDMA3CC_EERH_E35_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EERH_E34_MASK        (0x00000004u)
#define CSL_EDMA3CC_EERH_E34_SHIFT       (0x00000002u)
#define CSL_EDMA3CC_EERH_E34_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EERH_E33_MASK        (0x00000002u)
#define CSL_EDMA3CC_EERH_E33_SHIFT       (0x00000001u)
#define CSL_EDMA3CC_EERH_E33_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EERH_E32_MASK        (0x00000001u)
#define CSL_EDMA3CC_EERH_E32_SHIFT       (0x00000000u)
#define CSL_EDMA3CC_EERH_E32_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EERH_RESETVAL        (0x00000000u)

/* EECR */

#define CSL_EDMA3CC_EECR_E31_MASK        (0x80000000u)
#define CSL_EDMA3CC_EECR_E31_SHIFT       (0x0000001Fu)
#define CSL_EDMA3CC_EECR_E31_RESETVAL    (0x00000000u)

/*----E31 Tokens----*/
#define CSL_EDMA3CC_EECR_E31_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_EECR_E30_MASK        (0x40000000u)
#define CSL_EDMA3CC_EECR_E30_SHIFT       (0x0000001Eu)
#define CSL_EDMA3CC_EECR_E30_RESETVAL    (0x00000000u)

/*----E30 Tokens----*/
#define CSL_EDMA3CC_EECR_E30_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_EECR_E29_MASK        (0x20000000u)
#define CSL_EDMA3CC_EECR_E29_SHIFT       (0x0000001Du)
#define CSL_EDMA3CC_EECR_E29_RESETVAL    (0x00000000u)

/*----E29 Tokens----*/
#define CSL_EDMA3CC_EECR_E29_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_EECR_E28_MASK        (0x10000000u)
#define CSL_EDMA3CC_EECR_E28_SHIFT       (0x0000001Cu)
#define CSL_EDMA3CC_EECR_E28_RESETVAL    (0x00000000u)

/*----E28 Tokens----*/
#define CSL_EDMA3CC_EECR_E28_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_EECR_E27_MASK        (0x08000000u)
#define CSL_EDMA3CC_EECR_E27_SHIFT       (0x0000001Bu)
#define CSL_EDMA3CC_EECR_E27_RESETVAL    (0x00000000u)

/*----E27 Tokens----*/
#define CSL_EDMA3CC_EECR_E27_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_EECR_E26_MASK        (0x04000000u)
#define CSL_EDMA3CC_EECR_E26_SHIFT       (0x0000001Au)
#define CSL_EDMA3CC_EECR_E26_RESETVAL    (0x00000000u)

/*----E26 Tokens----*/
#define CSL_EDMA3CC_EECR_E26_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_EECR_E25_MASK        (0x02000000u)
#define CSL_EDMA3CC_EECR_E25_SHIFT       (0x00000019u)
#define CSL_EDMA3CC_EECR_E25_RESETVAL    (0x00000000u)

/*----E25 Tokens----*/
#define CSL_EDMA3CC_EECR_E25_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_EECR_E24_MASK        (0x01000000u)
#define CSL_EDMA3CC_EECR_E24_SHIFT       (0x00000018u)
#define CSL_EDMA3CC_EECR_E24_RESETVAL    (0x00000000u)

/*----E24 Tokens----*/
#define CSL_EDMA3CC_EECR_E24_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_EECR_E23_MASK        (0x00800000u)
#define CSL_EDMA3CC_EECR_E23_SHIFT       (0x00000017u)
#define CSL_EDMA3CC_EECR_E23_RESETVAL    (0x00000000u)

/*----E23 Tokens----*/
#define CSL_EDMA3CC_EECR_E23_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_EECR_E22_MASK        (0x00400000u)
#define CSL_EDMA3CC_EECR_E22_SHIFT       (0x00000016u)
#define CSL_EDMA3CC_EECR_E22_RESETVAL    (0x00000000u)

/*----E22 Tokens----*/
#define CSL_EDMA3CC_EECR_E22_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_EECR_E21_MASK        (0x00200000u)
#define CSL_EDMA3CC_EECR_E21_SHIFT       (0x00000015u)
#define CSL_EDMA3CC_EECR_E21_RESETVAL    (0x00000000u)

/*----E21 Tokens----*/
#define CSL_EDMA3CC_EECR_E21_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_EECR_E20_MASK        (0x00100000u)
#define CSL_EDMA3CC_EECR_E20_SHIFT       (0x00000014u)
#define CSL_EDMA3CC_EECR_E20_RESETVAL    (0x00000000u)

/*----E20 Tokens----*/
#define CSL_EDMA3CC_EECR_E20_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_EECR_E19_MASK        (0x00080000u)
#define CSL_EDMA3CC_EECR_E19_SHIFT       (0x00000013u)
#define CSL_EDMA3CC_EECR_E19_RESETVAL    (0x00000000u)

/*----E19 Tokens----*/
#define CSL_EDMA3CC_EECR_E19_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_EECR_E18_MASK        (0x00040000u)
#define CSL_EDMA3CC_EECR_E18_SHIFT       (0x00000012u)
#define CSL_EDMA3CC_EECR_E18_RESETVAL    (0x00000000u)

/*----E18 Tokens----*/
#define CSL_EDMA3CC_EECR_E18_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_EECR_E17_MASK        (0x00020000u)
#define CSL_EDMA3CC_EECR_E17_SHIFT       (0x00000011u)
#define CSL_EDMA3CC_EECR_E17_RESETVAL    (0x00000000u)

/*----E17 Tokens----*/
#define CSL_EDMA3CC_EECR_E17_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_EECR_E16_MASK        (0x00010000u)
#define CSL_EDMA3CC_EECR_E16_SHIFT       (0x00000010u)
#define CSL_EDMA3CC_EECR_E16_RESETVAL    (0x00000000u)

/*----E16 Tokens----*/
#define CSL_EDMA3CC_EECR_E16_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_EECR_E15_MASK        (0x00008000u)
#define CSL_EDMA3CC_EECR_E15_SHIFT       (0x0000000Fu)
#define CSL_EDMA3CC_EECR_E15_RESETVAL    (0x00000000u)

/*----E15 Tokens----*/
#define CSL_EDMA3CC_EECR_E15_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_EECR_E14_MASK        (0x00004000u)
#define CSL_EDMA3CC_EECR_E14_SHIFT       (0x0000000Eu)
#define CSL_EDMA3CC_EECR_E14_RESETVAL    (0x00000000u)

/*----E14 Tokens----*/
#define CSL_EDMA3CC_EECR_E14_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_EECR_E13_MASK        (0x00002000u)
#define CSL_EDMA3CC_EECR_E13_SHIFT       (0x0000000Du)
#define CSL_EDMA3CC_EECR_E13_RESETVAL    (0x00000000u)

/*----E13 Tokens----*/
#define CSL_EDMA3CC_EECR_E13_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_EECR_E12_MASK        (0x00001000u)
#define CSL_EDMA3CC_EECR_E12_SHIFT       (0x0000000Cu)
#define CSL_EDMA3CC_EECR_E12_RESETVAL    (0x00000000u)

/*----E12 Tokens----*/
#define CSL_EDMA3CC_EECR_E12_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_EECR_E11_MASK        (0x00000800u)
#define CSL_EDMA3CC_EECR_E11_SHIFT       (0x0000000Bu)
#define CSL_EDMA3CC_EECR_E11_RESETVAL    (0x00000000u)

/*----E11 Tokens----*/
#define CSL_EDMA3CC_EECR_E11_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_EECR_E10_MASK        (0x00000400u)
#define CSL_EDMA3CC_EECR_E10_SHIFT       (0x0000000Au)
#define CSL_EDMA3CC_EECR_E10_RESETVAL    (0x00000000u)

/*----E10 Tokens----*/
#define CSL_EDMA3CC_EECR_E10_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_EECR_E9_MASK         (0x00000200u)
#define CSL_EDMA3CC_EECR_E9_SHIFT        (0x00000009u)
#define CSL_EDMA3CC_EECR_E9_RESETVAL     (0x00000000u)

/*----E9 Tokens----*/
#define CSL_EDMA3CC_EECR_E9_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_EECR_E8_MASK         (0x00000100u)
#define CSL_EDMA3CC_EECR_E8_SHIFT        (0x00000008u)
#define CSL_EDMA3CC_EECR_E8_RESETVAL     (0x00000000u)

/*----E8 Tokens----*/
#define CSL_EDMA3CC_EECR_E8_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_EECR_E7_MASK         (0x00000080u)
#define CSL_EDMA3CC_EECR_E7_SHIFT        (0x00000007u)
#define CSL_EDMA3CC_EECR_E7_RESETVAL     (0x00000000u)

/*----E7 Tokens----*/
#define CSL_EDMA3CC_EECR_E7_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_EECR_E6_MASK         (0x00000040u)
#define CSL_EDMA3CC_EECR_E6_SHIFT        (0x00000006u)
#define CSL_EDMA3CC_EECR_E6_RESETVAL     (0x00000000u)

/*----E6 Tokens----*/
#define CSL_EDMA3CC_EECR_E6_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_EECR_E5_MASK         (0x00000020u)
#define CSL_EDMA3CC_EECR_E5_SHIFT        (0x00000005u)
#define CSL_EDMA3CC_EECR_E5_RESETVAL     (0x00000000u)

/*----E5 Tokens----*/
#define CSL_EDMA3CC_EECR_E5_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_EECR_E4_MASK         (0x00000010u)
#define CSL_EDMA3CC_EECR_E4_SHIFT        (0x00000004u)
#define CSL_EDMA3CC_EECR_E4_RESETVAL     (0x00000000u)

/*----E4 Tokens----*/
#define CSL_EDMA3CC_EECR_E4_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_EECR_E3_MASK         (0x00000008u)
#define CSL_EDMA3CC_EECR_E3_SHIFT        (0x00000003u)
#define CSL_EDMA3CC_EECR_E3_RESETVAL     (0x00000000u)

/*----E3 Tokens----*/
#define CSL_EDMA3CC_EECR_E3_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_EECR_E2_MASK         (0x00000004u)
#define CSL_EDMA3CC_EECR_E2_SHIFT        (0x00000002u)
#define CSL_EDMA3CC_EECR_E2_RESETVAL     (0x00000000u)

/*----E2 Tokens----*/
#define CSL_EDMA3CC_EECR_E2_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_EECR_E1_MASK         (0x00000002u)
#define CSL_EDMA3CC_EECR_E1_SHIFT        (0x00000001u)
#define CSL_EDMA3CC_EECR_E1_RESETVAL     (0x00000000u)

/*----E1 Tokens----*/
#define CSL_EDMA3CC_EECR_E1_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_EECR_E0_MASK         (0x00000001u)
#define CSL_EDMA3CC_EECR_E0_SHIFT        (0x00000000u)
#define CSL_EDMA3CC_EECR_E0_RESETVAL     (0x00000000u)

/*----E0 Tokens----*/
#define CSL_EDMA3CC_EECR_E0_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_EECR_RESETVAL        (0x00000000u)

/* EECRH */

#define CSL_EDMA3CC_EECRH_E63_MASK       (0x80000000u)
#define CSL_EDMA3CC_EECRH_E63_SHIFT      (0x0000001Fu)
#define CSL_EDMA3CC_EECRH_E63_RESETVAL   (0x00000000u)

/*----E63 Tokens----*/
#define CSL_EDMA3CC_EECRH_E63_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EECRH_E62_MASK       (0x40000000u)
#define CSL_EDMA3CC_EECRH_E62_SHIFT      (0x0000001Eu)
#define CSL_EDMA3CC_EECRH_E62_RESETVAL   (0x00000000u)

/*----E62 Tokens----*/
#define CSL_EDMA3CC_EECRH_E62_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EECRH_E61_MASK       (0x20000000u)
#define CSL_EDMA3CC_EECRH_E61_SHIFT      (0x0000001Du)
#define CSL_EDMA3CC_EECRH_E61_RESETVAL   (0x00000000u)

/*----E61 Tokens----*/
#define CSL_EDMA3CC_EECRH_E61_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EECRH_E60_MASK       (0x10000000u)
#define CSL_EDMA3CC_EECRH_E60_SHIFT      (0x0000001Cu)
#define CSL_EDMA3CC_EECRH_E60_RESETVAL   (0x00000000u)

/*----E60 Tokens----*/
#define CSL_EDMA3CC_EECRH_E60_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EECRH_E59_MASK       (0x08000000u)
#define CSL_EDMA3CC_EECRH_E59_SHIFT      (0x0000001Bu)
#define CSL_EDMA3CC_EECRH_E59_RESETVAL   (0x00000000u)

/*----E59 Tokens----*/
#define CSL_EDMA3CC_EECRH_E59_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EECRH_E58_MASK       (0x04000000u)
#define CSL_EDMA3CC_EECRH_E58_SHIFT      (0x0000001Au)
#define CSL_EDMA3CC_EECRH_E58_RESETVAL   (0x00000000u)

/*----E58 Tokens----*/
#define CSL_EDMA3CC_EECRH_E58_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EECRH_E57_MASK       (0x02000000u)
#define CSL_EDMA3CC_EECRH_E57_SHIFT      (0x00000019u)
#define CSL_EDMA3CC_EECRH_E57_RESETVAL   (0x00000000u)

/*----E57 Tokens----*/
#define CSL_EDMA3CC_EECRH_E57_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EECRH_E56_MASK       (0x01000000u)
#define CSL_EDMA3CC_EECRH_E56_SHIFT      (0x00000018u)
#define CSL_EDMA3CC_EECRH_E56_RESETVAL   (0x00000000u)

/*----E56 Tokens----*/
#define CSL_EDMA3CC_EECRH_E56_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EECRH_E55_MASK       (0x00800000u)
#define CSL_EDMA3CC_EECRH_E55_SHIFT      (0x00000017u)
#define CSL_EDMA3CC_EECRH_E55_RESETVAL   (0x00000000u)

/*----E55 Tokens----*/
#define CSL_EDMA3CC_EECRH_E55_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EECRH_E54_MASK       (0x00400000u)
#define CSL_EDMA3CC_EECRH_E54_SHIFT      (0x00000016u)
#define CSL_EDMA3CC_EECRH_E54_RESETVAL   (0x00000000u)

/*----E54 Tokens----*/
#define CSL_EDMA3CC_EECRH_E54_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EECRH_E53_MASK       (0x00200000u)
#define CSL_EDMA3CC_EECRH_E53_SHIFT      (0x00000015u)
#define CSL_EDMA3CC_EECRH_E53_RESETVAL   (0x00000000u)

/*----E53 Tokens----*/
#define CSL_EDMA3CC_EECRH_E53_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EECRH_E52_MASK       (0x00100000u)
#define CSL_EDMA3CC_EECRH_E52_SHIFT      (0x00000014u)
#define CSL_EDMA3CC_EECRH_E52_RESETVAL   (0x00000000u)

/*----E52 Tokens----*/
#define CSL_EDMA3CC_EECRH_E52_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EECRH_E51_MASK       (0x00080000u)
#define CSL_EDMA3CC_EECRH_E51_SHIFT      (0x00000013u)
#define CSL_EDMA3CC_EECRH_E51_RESETVAL   (0x00000000u)

/*----E51 Tokens----*/
#define CSL_EDMA3CC_EECRH_E51_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EECRH_E50_MASK       (0x00040000u)
#define CSL_EDMA3CC_EECRH_E50_SHIFT      (0x00000012u)
#define CSL_EDMA3CC_EECRH_E50_RESETVAL   (0x00000000u)

/*----E50 Tokens----*/
#define CSL_EDMA3CC_EECRH_E50_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EECRH_E49_MASK       (0x00020000u)
#define CSL_EDMA3CC_EECRH_E49_SHIFT      (0x00000011u)
#define CSL_EDMA3CC_EECRH_E49_RESETVAL   (0x00000000u)

/*----E49 Tokens----*/
#define CSL_EDMA3CC_EECRH_E49_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EECRH_E48_MASK       (0x00010000u)
#define CSL_EDMA3CC_EECRH_E48_SHIFT      (0x00000010u)
#define CSL_EDMA3CC_EECRH_E48_RESETVAL   (0x00000000u)

/*----E48 Tokens----*/
#define CSL_EDMA3CC_EECRH_E48_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EECRH_E47_MASK       (0x00008000u)
#define CSL_EDMA3CC_EECRH_E47_SHIFT      (0x0000000Fu)
#define CSL_EDMA3CC_EECRH_E47_RESETVAL   (0x00000000u)

/*----E47 Tokens----*/
#define CSL_EDMA3CC_EECRH_E47_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EECRH_E46_MASK       (0x00004000u)
#define CSL_EDMA3CC_EECRH_E46_SHIFT      (0x0000000Eu)
#define CSL_EDMA3CC_EECRH_E46_RESETVAL   (0x00000000u)

/*----E46 Tokens----*/
#define CSL_EDMA3CC_EECRH_E46_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EECRH_E45_MASK       (0x00002000u)
#define CSL_EDMA3CC_EECRH_E45_SHIFT      (0x0000000Du)
#define CSL_EDMA3CC_EECRH_E45_RESETVAL   (0x00000000u)

/*----E45 Tokens----*/
#define CSL_EDMA3CC_EECRH_E45_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EECRH_E44_MASK       (0x00001000u)
#define CSL_EDMA3CC_EECRH_E44_SHIFT      (0x0000000Cu)
#define CSL_EDMA3CC_EECRH_E44_RESETVAL   (0x00000000u)

/*----E44 Tokens----*/
#define CSL_EDMA3CC_EECRH_E44_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EECRH_E43_MASK       (0x00000800u)
#define CSL_EDMA3CC_EECRH_E43_SHIFT      (0x0000000Bu)
#define CSL_EDMA3CC_EECRH_E43_RESETVAL   (0x00000000u)

/*----E43 Tokens----*/
#define CSL_EDMA3CC_EECRH_E43_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EECRH_E42_MASK       (0x00000400u)
#define CSL_EDMA3CC_EECRH_E42_SHIFT      (0x0000000Au)
#define CSL_EDMA3CC_EECRH_E42_RESETVAL   (0x00000000u)

/*----E42 Tokens----*/
#define CSL_EDMA3CC_EECRH_E42_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EECRH_E41_MASK       (0x00000200u)
#define CSL_EDMA3CC_EECRH_E41_SHIFT      (0x00000009u)
#define CSL_EDMA3CC_EECRH_E41_RESETVAL   (0x00000000u)

/*----E41 Tokens----*/
#define CSL_EDMA3CC_EECRH_E41_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EECRH_E40_MASK       (0x00000100u)
#define CSL_EDMA3CC_EECRH_E40_SHIFT      (0x00000008u)
#define CSL_EDMA3CC_EECRH_E40_RESETVAL   (0x00000000u)

/*----E40 Tokens----*/
#define CSL_EDMA3CC_EECRH_E40_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EECRH_E39_MASK       (0x00000080u)
#define CSL_EDMA3CC_EECRH_E39_SHIFT      (0x00000007u)
#define CSL_EDMA3CC_EECRH_E39_RESETVAL   (0x00000000u)

/*----E39 Tokens----*/
#define CSL_EDMA3CC_EECRH_E39_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EECRH_E38_MASK       (0x00000040u)
#define CSL_EDMA3CC_EECRH_E38_SHIFT      (0x00000006u)
#define CSL_EDMA3CC_EECRH_E38_RESETVAL   (0x00000000u)

/*----E38 Tokens----*/
#define CSL_EDMA3CC_EECRH_E38_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EECRH_E37_MASK       (0x00000020u)
#define CSL_EDMA3CC_EECRH_E37_SHIFT      (0x00000005u)
#define CSL_EDMA3CC_EECRH_E37_RESETVAL   (0x00000000u)

/*----E37 Tokens----*/
#define CSL_EDMA3CC_EECRH_E37_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EECRH_E36_MASK       (0x00000010u)
#define CSL_EDMA3CC_EECRH_E36_SHIFT      (0x00000004u)
#define CSL_EDMA3CC_EECRH_E36_RESETVAL   (0x00000000u)

/*----E36 Tokens----*/
#define CSL_EDMA3CC_EECRH_E36_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EECRH_E35_MASK       (0x00000008u)
#define CSL_EDMA3CC_EECRH_E35_SHIFT      (0x00000003u)
#define CSL_EDMA3CC_EECRH_E35_RESETVAL   (0x00000000u)

/*----E35 Tokens----*/
#define CSL_EDMA3CC_EECRH_E35_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EECRH_E34_MASK       (0x00000004u)
#define CSL_EDMA3CC_EECRH_E34_SHIFT      (0x00000002u)
#define CSL_EDMA3CC_EECRH_E34_RESETVAL   (0x00000000u)

/*----E34 Tokens----*/
#define CSL_EDMA3CC_EECRH_E34_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EECRH_E33_MASK       (0x00000002u)
#define CSL_EDMA3CC_EECRH_E33_SHIFT      (0x00000001u)
#define CSL_EDMA3CC_EECRH_E33_RESETVAL   (0x00000000u)

/*----E33 Tokens----*/
#define CSL_EDMA3CC_EECRH_E33_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EECRH_E32_MASK       (0x00000001u)
#define CSL_EDMA3CC_EECRH_E32_SHIFT      (0x00000000u)
#define CSL_EDMA3CC_EECRH_E32_RESETVAL   (0x00000000u)

/*----E32 Tokens----*/
#define CSL_EDMA3CC_EECRH_E32_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_EECRH_RESETVAL       (0x00000000u)

/* EESR */

#define CSL_EDMA3CC_EESR_E31_MASK        (0x80000000u)
#define CSL_EDMA3CC_EESR_E31_SHIFT       (0x0000001Fu)
#define CSL_EDMA3CC_EESR_E31_RESETVAL    (0x00000000u)

/*----E31 Tokens----*/
#define CSL_EDMA3CC_EESR_E31_SET         (0x00000001u)

#define CSL_EDMA3CC_EESR_E30_MASK        (0x40000000u)
#define CSL_EDMA3CC_EESR_E30_SHIFT       (0x0000001Eu)
#define CSL_EDMA3CC_EESR_E30_RESETVAL    (0x00000000u)

/*----E30 Tokens----*/
#define CSL_EDMA3CC_EESR_E30_SET         (0x00000001u)

#define CSL_EDMA3CC_EESR_E29_MASK        (0x20000000u)
#define CSL_EDMA3CC_EESR_E29_SHIFT       (0x0000001Du)
#define CSL_EDMA3CC_EESR_E29_RESETVAL    (0x00000000u)

/*----E29 Tokens----*/
#define CSL_EDMA3CC_EESR_E29_SET         (0x00000001u)

#define CSL_EDMA3CC_EESR_E28_MASK        (0x10000000u)
#define CSL_EDMA3CC_EESR_E28_SHIFT       (0x0000001Cu)
#define CSL_EDMA3CC_EESR_E28_RESETVAL    (0x00000000u)

/*----E28 Tokens----*/
#define CSL_EDMA3CC_EESR_E28_SET         (0x00000001u)

#define CSL_EDMA3CC_EESR_E27_MASK        (0x08000000u)
#define CSL_EDMA3CC_EESR_E27_SHIFT       (0x0000001Bu)
#define CSL_EDMA3CC_EESR_E27_RESETVAL    (0x00000000u)

/*----E27 Tokens----*/
#define CSL_EDMA3CC_EESR_E27_SET         (0x00000001u)

#define CSL_EDMA3CC_EESR_E26_MASK        (0x04000000u)
#define CSL_EDMA3CC_EESR_E26_SHIFT       (0x0000001Au)
#define CSL_EDMA3CC_EESR_E26_RESETVAL    (0x00000000u)

/*----E26 Tokens----*/
#define CSL_EDMA3CC_EESR_E26_SET         (0x00000001u)

#define CSL_EDMA3CC_EESR_E25_MASK        (0x02000000u)
#define CSL_EDMA3CC_EESR_E25_SHIFT       (0x00000019u)
#define CSL_EDMA3CC_EESR_E25_RESETVAL    (0x00000000u)

/*----E25 Tokens----*/
#define CSL_EDMA3CC_EESR_E25_SET         (0x00000001u)

#define CSL_EDMA3CC_EESR_E24_MASK        (0x01000000u)
#define CSL_EDMA3CC_EESR_E24_SHIFT       (0x00000018u)
#define CSL_EDMA3CC_EESR_E24_RESETVAL    (0x00000000u)

/*----E24 Tokens----*/
#define CSL_EDMA3CC_EESR_E24_SET         (0x00000001u)

#define CSL_EDMA3CC_EESR_E23_MASK        (0x00800000u)
#define CSL_EDMA3CC_EESR_E23_SHIFT       (0x00000017u)
#define CSL_EDMA3CC_EESR_E23_RESETVAL    (0x00000000u)

/*----E23 Tokens----*/
#define CSL_EDMA3CC_EESR_E23_SET         (0x00000001u)

#define CSL_EDMA3CC_EESR_E22_MASK        (0x00400000u)
#define CSL_EDMA3CC_EESR_E22_SHIFT       (0x00000016u)
#define CSL_EDMA3CC_EESR_E22_RESETVAL    (0x00000000u)

/*----E22 Tokens----*/
#define CSL_EDMA3CC_EESR_E22_SET         (0x00000001u)

#define CSL_EDMA3CC_EESR_E21_MASK        (0x00200000u)
#define CSL_EDMA3CC_EESR_E21_SHIFT       (0x00000015u)
#define CSL_EDMA3CC_EESR_E21_RESETVAL    (0x00000000u)

/*----E21 Tokens----*/
#define CSL_EDMA3CC_EESR_E21_SET         (0x00000001u)

#define CSL_EDMA3CC_EESR_E20_MASK        (0x00100000u)
#define CSL_EDMA3CC_EESR_E20_SHIFT       (0x00000014u)
#define CSL_EDMA3CC_EESR_E20_RESETVAL    (0x00000000u)

/*----E20 Tokens----*/
#define CSL_EDMA3CC_EESR_E20_SET         (0x00000001u)

#define CSL_EDMA3CC_EESR_E19_MASK        (0x00080000u)
#define CSL_EDMA3CC_EESR_E19_SHIFT       (0x00000013u)
#define CSL_EDMA3CC_EESR_E19_RESETVAL    (0x00000000u)

/*----E19 Tokens----*/
#define CSL_EDMA3CC_EESR_E19_SET         (0x00000001u)

#define CSL_EDMA3CC_EESR_E18_MASK        (0x00040000u)
#define CSL_EDMA3CC_EESR_E18_SHIFT       (0x00000012u)
#define CSL_EDMA3CC_EESR_E18_RESETVAL    (0x00000000u)

/*----E18 Tokens----*/
#define CSL_EDMA3CC_EESR_E18_SET         (0x00000001u)

#define CSL_EDMA3CC_EESR_E17_MASK        (0x00020000u)
#define CSL_EDMA3CC_EESR_E17_SHIFT       (0x00000011u)
#define CSL_EDMA3CC_EESR_E17_RESETVAL    (0x00000000u)

/*----E17 Tokens----*/
#define CSL_EDMA3CC_EESR_E17_SET         (0x00000001u)

#define CSL_EDMA3CC_EESR_E16_MASK        (0x00010000u)
#define CSL_EDMA3CC_EESR_E16_SHIFT       (0x00000010u)
#define CSL_EDMA3CC_EESR_E16_RESETVAL    (0x00000000u)

/*----E16 Tokens----*/
#define CSL_EDMA3CC_EESR_E16_SET         (0x00000001u)

#define CSL_EDMA3CC_EESR_E15_MASK        (0x00008000u)
#define CSL_EDMA3CC_EESR_E15_SHIFT       (0x0000000Fu)
#define CSL_EDMA3CC_EESR_E15_RESETVAL    (0x00000000u)

/*----E15 Tokens----*/
#define CSL_EDMA3CC_EESR_E15_SET         (0x00000001u)

#define CSL_EDMA3CC_EESR_E14_MASK        (0x00004000u)
#define CSL_EDMA3CC_EESR_E14_SHIFT       (0x0000000Eu)
#define CSL_EDMA3CC_EESR_E14_RESETVAL    (0x00000000u)

/*----E14 Tokens----*/
#define CSL_EDMA3CC_EESR_E14_SET         (0x00000001u)

#define CSL_EDMA3CC_EESR_E13_MASK        (0x00002000u)
#define CSL_EDMA3CC_EESR_E13_SHIFT       (0x0000000Du)
#define CSL_EDMA3CC_EESR_E13_RESETVAL    (0x00000000u)

/*----E13 Tokens----*/
#define CSL_EDMA3CC_EESR_E13_SET         (0x00000001u)

#define CSL_EDMA3CC_EESR_E12_MASK        (0x00001000u)
#define CSL_EDMA3CC_EESR_E12_SHIFT       (0x0000000Cu)
#define CSL_EDMA3CC_EESR_E12_RESETVAL    (0x00000000u)

/*----E12 Tokens----*/
#define CSL_EDMA3CC_EESR_E12_SET         (0x00000001u)

#define CSL_EDMA3CC_EESR_E11_MASK        (0x00000800u)
#define CSL_EDMA3CC_EESR_E11_SHIFT       (0x0000000Bu)
#define CSL_EDMA3CC_EESR_E11_RESETVAL    (0x00000000u)

/*----E11 Tokens----*/
#define CSL_EDMA3CC_EESR_E11_SET         (0x00000001u)

#define CSL_EDMA3CC_EESR_E10_MASK        (0x00000400u)
#define CSL_EDMA3CC_EESR_E10_SHIFT       (0x0000000Au)
#define CSL_EDMA3CC_EESR_E10_RESETVAL    (0x00000000u)

/*----E10 Tokens----*/
#define CSL_EDMA3CC_EESR_E10_SET         (0x00000001u)

#define CSL_EDMA3CC_EESR_E9_MASK         (0x00000200u)
#define CSL_EDMA3CC_EESR_E9_SHIFT        (0x00000009u)
#define CSL_EDMA3CC_EESR_E9_RESETVAL     (0x00000000u)

/*----E9 Tokens----*/
#define CSL_EDMA3CC_EESR_E9_SET          (0x00000001u)

#define CSL_EDMA3CC_EESR_E8_MASK         (0x00000100u)
#define CSL_EDMA3CC_EESR_E8_SHIFT        (0x00000008u)
#define CSL_EDMA3CC_EESR_E8_RESETVAL     (0x00000000u)

/*----E8 Tokens----*/
#define CSL_EDMA3CC_EESR_E8_SET          (0x00000001u)

#define CSL_EDMA3CC_EESR_E7_MASK         (0x00000080u)
#define CSL_EDMA3CC_EESR_E7_SHIFT        (0x00000007u)
#define CSL_EDMA3CC_EESR_E7_RESETVAL     (0x00000000u)

/*----E7 Tokens----*/
#define CSL_EDMA3CC_EESR_E7_SET          (0x00000001u)

#define CSL_EDMA3CC_EESR_E6_MASK         (0x00000040u)
#define CSL_EDMA3CC_EESR_E6_SHIFT        (0x00000006u)
#define CSL_EDMA3CC_EESR_E6_RESETVAL     (0x00000000u)

/*----E6 Tokens----*/
#define CSL_EDMA3CC_EESR_E6_SET          (0x00000001u)

#define CSL_EDMA3CC_EESR_E5_MASK         (0x00000020u)
#define CSL_EDMA3CC_EESR_E5_SHIFT        (0x00000005u)
#define CSL_EDMA3CC_EESR_E5_RESETVAL     (0x00000000u)

/*----E5 Tokens----*/
#define CSL_EDMA3CC_EESR_E5_SET          (0x00000001u)

#define CSL_EDMA3CC_EESR_E4_MASK         (0x00000010u)
#define CSL_EDMA3CC_EESR_E4_SHIFT        (0x00000004u)
#define CSL_EDMA3CC_EESR_E4_RESETVAL     (0x00000000u)

/*----E4 Tokens----*/
#define CSL_EDMA3CC_EESR_E4_SET          (0x00000001u)

#define CSL_EDMA3CC_EESR_E3_MASK         (0x00000008u)
#define CSL_EDMA3CC_EESR_E3_SHIFT        (0x00000003u)
#define CSL_EDMA3CC_EESR_E3_RESETVAL     (0x00000000u)

/*----E3 Tokens----*/
#define CSL_EDMA3CC_EESR_E3_SET          (0x00000001u)

#define CSL_EDMA3CC_EESR_E2_MASK         (0x00000004u)
#define CSL_EDMA3CC_EESR_E2_SHIFT        (0x00000002u)
#define CSL_EDMA3CC_EESR_E2_RESETVAL     (0x00000000u)

/*----E2 Tokens----*/
#define CSL_EDMA3CC_EESR_E2_SET          (0x00000001u)

#define CSL_EDMA3CC_EESR_E1_MASK         (0x00000002u)
#define CSL_EDMA3CC_EESR_E1_SHIFT        (0x00000001u)
#define CSL_EDMA3CC_EESR_E1_RESETVAL     (0x00000000u)

/*----E1 Tokens----*/
#define CSL_EDMA3CC_EESR_E1_SET          (0x00000001u)

#define CSL_EDMA3CC_EESR_E0_MASK         (0x00000001u)
#define CSL_EDMA3CC_EESR_E0_SHIFT        (0x00000000u)
#define CSL_EDMA3CC_EESR_E0_RESETVAL     (0x00000000u)

/*----E0 Tokens----*/
#define CSL_EDMA3CC_EESR_E0_SET          (0x00000001u)

#define CSL_EDMA3CC_EESR_RESETVAL        (0x00000000u)

/* EESRH */

#define CSL_EDMA3CC_EESRH_E63_MASK       (0x80000000u)
#define CSL_EDMA3CC_EESRH_E63_SHIFT      (0x0000001Fu)
#define CSL_EDMA3CC_EESRH_E63_RESETVAL   (0x00000000u)

/*----E63 Tokens----*/
#define CSL_EDMA3CC_EESRH_E63_SET        (0x00000001u)

#define CSL_EDMA3CC_EESRH_E62_MASK       (0x40000000u)
#define CSL_EDMA3CC_EESRH_E62_SHIFT      (0x0000001Eu)
#define CSL_EDMA3CC_EESRH_E62_RESETVAL   (0x00000000u)

/*----E62 Tokens----*/
#define CSL_EDMA3CC_EESRH_E62_SET        (0x00000001u)

#define CSL_EDMA3CC_EESRH_E61_MASK       (0x20000000u)
#define CSL_EDMA3CC_EESRH_E61_SHIFT      (0x0000001Du)
#define CSL_EDMA3CC_EESRH_E61_RESETVAL   (0x00000000u)

/*----E61 Tokens----*/
#define CSL_EDMA3CC_EESRH_E61_SET        (0x00000001u)

#define CSL_EDMA3CC_EESRH_E60_MASK       (0x10000000u)
#define CSL_EDMA3CC_EESRH_E60_SHIFT      (0x0000001Cu)
#define CSL_EDMA3CC_EESRH_E60_RESETVAL   (0x00000000u)

/*----E60 Tokens----*/
#define CSL_EDMA3CC_EESRH_E60_SET        (0x00000001u)

#define CSL_EDMA3CC_EESRH_E59_MASK       (0x08000000u)
#define CSL_EDMA3CC_EESRH_E59_SHIFT      (0x0000001Bu)
#define CSL_EDMA3CC_EESRH_E59_RESETVAL   (0x00000000u)

/*----E59 Tokens----*/
#define CSL_EDMA3CC_EESRH_E59_SET        (0x00000001u)

#define CSL_EDMA3CC_EESRH_E58_MASK       (0x04000000u)
#define CSL_EDMA3CC_EESRH_E58_SHIFT      (0x0000001Au)
#define CSL_EDMA3CC_EESRH_E58_RESETVAL   (0x00000000u)

/*----E58 Tokens----*/
#define CSL_EDMA3CC_EESRH_E58_SET        (0x00000001u)

#define CSL_EDMA3CC_EESRH_E57_MASK       (0x02000000u)
#define CSL_EDMA3CC_EESRH_E57_SHIFT      (0x00000019u)
#define CSL_EDMA3CC_EESRH_E57_RESETVAL   (0x00000000u)

/*----E57 Tokens----*/
#define CSL_EDMA3CC_EESRH_E57_SET        (0x00000001u)

#define CSL_EDMA3CC_EESRH_E56_MASK       (0x01000000u)
#define CSL_EDMA3CC_EESRH_E56_SHIFT      (0x00000018u)
#define CSL_EDMA3CC_EESRH_E56_RESETVAL   (0x00000000u)

/*----E56 Tokens----*/
#define CSL_EDMA3CC_EESRH_E56_SET        (0x00000001u)

#define CSL_EDMA3CC_EESRH_E55_MASK       (0x00800000u)
#define CSL_EDMA3CC_EESRH_E55_SHIFT      (0x00000017u)
#define CSL_EDMA3CC_EESRH_E55_RESETVAL   (0x00000000u)

/*----E55 Tokens----*/
#define CSL_EDMA3CC_EESRH_E55_SET        (0x00000001u)

#define CSL_EDMA3CC_EESRH_E54_MASK       (0x00400000u)
#define CSL_EDMA3CC_EESRH_E54_SHIFT      (0x00000016u)
#define CSL_EDMA3CC_EESRH_E54_RESETVAL   (0x00000000u)

/*----E54 Tokens----*/
#define CSL_EDMA3CC_EESRH_E54_SET        (0x00000001u)

#define CSL_EDMA3CC_EESRH_E53_MASK       (0x00200000u)
#define CSL_EDMA3CC_EESRH_E53_SHIFT      (0x00000015u)
#define CSL_EDMA3CC_EESRH_E53_RESETVAL   (0x00000000u)

/*----E53 Tokens----*/
#define CSL_EDMA3CC_EESRH_E53_SET        (0x00000001u)

#define CSL_EDMA3CC_EESRH_E52_MASK       (0x00100000u)
#define CSL_EDMA3CC_EESRH_E52_SHIFT      (0x00000014u)
#define CSL_EDMA3CC_EESRH_E52_RESETVAL   (0x00000000u)

/*----E52 Tokens----*/
#define CSL_EDMA3CC_EESRH_E52_SET        (0x00000001u)

#define CSL_EDMA3CC_EESRH_E51_MASK       (0x00080000u)
#define CSL_EDMA3CC_EESRH_E51_SHIFT      (0x00000013u)
#define CSL_EDMA3CC_EESRH_E51_RESETVAL   (0x00000000u)

/*----E51 Tokens----*/
#define CSL_EDMA3CC_EESRH_E51_SET        (0x00000001u)

#define CSL_EDMA3CC_EESRH_E50_MASK       (0x00040000u)
#define CSL_EDMA3CC_EESRH_E50_SHIFT      (0x00000012u)
#define CSL_EDMA3CC_EESRH_E50_RESETVAL   (0x00000000u)

/*----E50 Tokens----*/
#define CSL_EDMA3CC_EESRH_E50_SET        (0x00000001u)

#define CSL_EDMA3CC_EESRH_E49_MASK       (0x00020000u)
#define CSL_EDMA3CC_EESRH_E49_SHIFT      (0x00000011u)
#define CSL_EDMA3CC_EESRH_E49_RESETVAL   (0x00000000u)

/*----E49 Tokens----*/
#define CSL_EDMA3CC_EESRH_E49_SET        (0x00000001u)

#define CSL_EDMA3CC_EESRH_E48_MASK       (0x00010000u)
#define CSL_EDMA3CC_EESRH_E48_SHIFT      (0x00000010u)
#define CSL_EDMA3CC_EESRH_E48_RESETVAL   (0x00000000u)

/*----E48 Tokens----*/
#define CSL_EDMA3CC_EESRH_E48_SET        (0x00000001u)

#define CSL_EDMA3CC_EESRH_E47_MASK       (0x00008000u)
#define CSL_EDMA3CC_EESRH_E47_SHIFT      (0x0000000Fu)
#define CSL_EDMA3CC_EESRH_E47_RESETVAL   (0x00000000u)

/*----E47 Tokens----*/
#define CSL_EDMA3CC_EESRH_E47_SET        (0x00000001u)

#define CSL_EDMA3CC_EESRH_E46_MASK       (0x00004000u)
#define CSL_EDMA3CC_EESRH_E46_SHIFT      (0x0000000Eu)
#define CSL_EDMA3CC_EESRH_E46_RESETVAL   (0x00000000u)

/*----E46 Tokens----*/
#define CSL_EDMA3CC_EESRH_E46_SET        (0x00000001u)

#define CSL_EDMA3CC_EESRH_E45_MASK       (0x00002000u)
#define CSL_EDMA3CC_EESRH_E45_SHIFT      (0x0000000Du)
#define CSL_EDMA3CC_EESRH_E45_RESETVAL   (0x00000000u)

/*----E45 Tokens----*/
#define CSL_EDMA3CC_EESRH_E45_SET        (0x00000001u)

#define CSL_EDMA3CC_EESRH_E44_MASK       (0x00001000u)
#define CSL_EDMA3CC_EESRH_E44_SHIFT      (0x0000000Cu)
#define CSL_EDMA3CC_EESRH_E44_RESETVAL   (0x00000000u)

/*----E44 Tokens----*/
#define CSL_EDMA3CC_EESRH_E44_SET        (0x00000001u)

#define CSL_EDMA3CC_EESRH_E43_MASK       (0x00000800u)
#define CSL_EDMA3CC_EESRH_E43_SHIFT      (0x0000000Bu)
#define CSL_EDMA3CC_EESRH_E43_RESETVAL   (0x00000000u)

/*----E43 Tokens----*/
#define CSL_EDMA3CC_EESRH_E43_SET        (0x00000001u)

#define CSL_EDMA3CC_EESRH_E42_MASK       (0x00000400u)
#define CSL_EDMA3CC_EESRH_E42_SHIFT      (0x0000000Au)
#define CSL_EDMA3CC_EESRH_E42_RESETVAL   (0x00000000u)

/*----E42 Tokens----*/
#define CSL_EDMA3CC_EESRH_E42_SET        (0x00000001u)

#define CSL_EDMA3CC_EESRH_E41_MASK       (0x00000200u)
#define CSL_EDMA3CC_EESRH_E41_SHIFT      (0x00000009u)
#define CSL_EDMA3CC_EESRH_E41_RESETVAL   (0x00000000u)

/*----E41 Tokens----*/
#define CSL_EDMA3CC_EESRH_E41_SET        (0x00000001u)

#define CSL_EDMA3CC_EESRH_E40_MASK       (0x00000100u)
#define CSL_EDMA3CC_EESRH_E40_SHIFT      (0x00000008u)
#define CSL_EDMA3CC_EESRH_E40_RESETVAL   (0x00000000u)

/*----E40 Tokens----*/
#define CSL_EDMA3CC_EESRH_E40_SET        (0x00000001u)

#define CSL_EDMA3CC_EESRH_E39_MASK       (0x00000080u)
#define CSL_EDMA3CC_EESRH_E39_SHIFT      (0x00000007u)
#define CSL_EDMA3CC_EESRH_E39_RESETVAL   (0x00000000u)

/*----E39 Tokens----*/
#define CSL_EDMA3CC_EESRH_E39_SET        (0x00000001u)

#define CSL_EDMA3CC_EESRH_E38_MASK       (0x00000040u)
#define CSL_EDMA3CC_EESRH_E38_SHIFT      (0x00000006u)
#define CSL_EDMA3CC_EESRH_E38_RESETVAL   (0x00000000u)

/*----E38 Tokens----*/
#define CSL_EDMA3CC_EESRH_E38_SET        (0x00000001u)

#define CSL_EDMA3CC_EESRH_E37_MASK       (0x00000020u)
#define CSL_EDMA3CC_EESRH_E37_SHIFT      (0x00000005u)
#define CSL_EDMA3CC_EESRH_E37_RESETVAL   (0x00000000u)

/*----E37 Tokens----*/
#define CSL_EDMA3CC_EESRH_E37_SET        (0x00000001u)

#define CSL_EDMA3CC_EESRH_E36_MASK       (0x00000010u)
#define CSL_EDMA3CC_EESRH_E36_SHIFT      (0x00000004u)
#define CSL_EDMA3CC_EESRH_E36_RESETVAL   (0x00000000u)

/*----E36 Tokens----*/
#define CSL_EDMA3CC_EESRH_E36_SET        (0x00000001u)

#define CSL_EDMA3CC_EESRH_E35_MASK       (0x00000008u)
#define CSL_EDMA3CC_EESRH_E35_SHIFT      (0x00000003u)
#define CSL_EDMA3CC_EESRH_E35_RESETVAL   (0x00000000u)

/*----E35 Tokens----*/
#define CSL_EDMA3CC_EESRH_E35_SET        (0x00000001u)

#define CSL_EDMA3CC_EESRH_E34_MASK       (0x00000004u)
#define CSL_EDMA3CC_EESRH_E34_SHIFT      (0x00000002u)
#define CSL_EDMA3CC_EESRH_E34_RESETVAL   (0x00000000u)

/*----E34 Tokens----*/
#define CSL_EDMA3CC_EESRH_E34_SET        (0x00000001u)

#define CSL_EDMA3CC_EESRH_E33_MASK       (0x00000002u)
#define CSL_EDMA3CC_EESRH_E33_SHIFT      (0x00000001u)
#define CSL_EDMA3CC_EESRH_E33_RESETVAL   (0x00000000u)

/*----E33 Tokens----*/
#define CSL_EDMA3CC_EESRH_E33_SET        (0x00000001u)

#define CSL_EDMA3CC_EESRH_E32_MASK       (0x00000001u)
#define CSL_EDMA3CC_EESRH_E32_SHIFT      (0x00000000u)
#define CSL_EDMA3CC_EESRH_E32_RESETVAL   (0x00000000u)

/*----E32 Tokens----*/
#define CSL_EDMA3CC_EESRH_E32_SET        (0x00000001u)

#define CSL_EDMA3CC_EESRH_RESETVAL       (0x00000000u)

/* SER */

#define CSL_EDMA3CC_SER_E31_MASK         (0x80000000u)
#define CSL_EDMA3CC_SER_E31_SHIFT        (0x0000001Fu)
#define CSL_EDMA3CC_SER_E31_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_SER_E30_MASK         (0x40000000u)
#define CSL_EDMA3CC_SER_E30_SHIFT        (0x0000001Eu)
#define CSL_EDMA3CC_SER_E30_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_SER_E29_MASK         (0x20000000u)
#define CSL_EDMA3CC_SER_E29_SHIFT        (0x0000001Du)
#define CSL_EDMA3CC_SER_E29_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_SER_E28_MASK         (0x10000000u)
#define CSL_EDMA3CC_SER_E28_SHIFT        (0x0000001Cu)
#define CSL_EDMA3CC_SER_E28_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_SER_E27_MASK         (0x08000000u)
#define CSL_EDMA3CC_SER_E27_SHIFT        (0x0000001Bu)
#define CSL_EDMA3CC_SER_E27_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_SER_E26_MASK         (0x04000000u)
#define CSL_EDMA3CC_SER_E26_SHIFT        (0x0000001Au)
#define CSL_EDMA3CC_SER_E26_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_SER_E25_MASK         (0x02000000u)
#define CSL_EDMA3CC_SER_E25_SHIFT        (0x00000019u)
#define CSL_EDMA3CC_SER_E25_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_SER_E24_MASK         (0x01000000u)
#define CSL_EDMA3CC_SER_E24_SHIFT        (0x00000018u)
#define CSL_EDMA3CC_SER_E24_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_SER_E23_MASK         (0x00800000u)
#define CSL_EDMA3CC_SER_E23_SHIFT        (0x00000017u)
#define CSL_EDMA3CC_SER_E23_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_SER_E22_MASK         (0x00400000u)
#define CSL_EDMA3CC_SER_E22_SHIFT        (0x00000016u)
#define CSL_EDMA3CC_SER_E22_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_SER_E21_MASK         (0x00200000u)
#define CSL_EDMA3CC_SER_E21_SHIFT        (0x00000015u)
#define CSL_EDMA3CC_SER_E21_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_SER_E20_MASK         (0x00100000u)
#define CSL_EDMA3CC_SER_E20_SHIFT        (0x00000014u)
#define CSL_EDMA3CC_SER_E20_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_SER_E19_MASK         (0x00080000u)
#define CSL_EDMA3CC_SER_E19_SHIFT        (0x00000013u)
#define CSL_EDMA3CC_SER_E19_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_SER_E18_MASK         (0x00040000u)
#define CSL_EDMA3CC_SER_E18_SHIFT        (0x00000012u)
#define CSL_EDMA3CC_SER_E18_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_SER_E17_MASK         (0x00020000u)
#define CSL_EDMA3CC_SER_E17_SHIFT        (0x00000011u)
#define CSL_EDMA3CC_SER_E17_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_SER_E16_MASK         (0x00010000u)
#define CSL_EDMA3CC_SER_E16_SHIFT        (0x00000010u)
#define CSL_EDMA3CC_SER_E16_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_SER_E15_MASK         (0x00008000u)
#define CSL_EDMA3CC_SER_E15_SHIFT        (0x0000000Fu)
#define CSL_EDMA3CC_SER_E15_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_SER_E14_MASK         (0x00004000u)
#define CSL_EDMA3CC_SER_E14_SHIFT        (0x0000000Eu)
#define CSL_EDMA3CC_SER_E14_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_SER_E13_MASK         (0x00002000u)
#define CSL_EDMA3CC_SER_E13_SHIFT        (0x0000000Du)
#define CSL_EDMA3CC_SER_E13_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_SER_E12_MASK         (0x00001000u)
#define CSL_EDMA3CC_SER_E12_SHIFT        (0x0000000Cu)
#define CSL_EDMA3CC_SER_E12_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_SER_E11_MASK         (0x00000800u)
#define CSL_EDMA3CC_SER_E11_SHIFT        (0x0000000Bu)
#define CSL_EDMA3CC_SER_E11_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_SER_E10_MASK         (0x00000400u)
#define CSL_EDMA3CC_SER_E10_SHIFT        (0x0000000Au)
#define CSL_EDMA3CC_SER_E10_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_SER_E9_MASK          (0x00000200u)
#define CSL_EDMA3CC_SER_E9_SHIFT         (0x00000009u)
#define CSL_EDMA3CC_SER_E9_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_SER_E8_MASK          (0x00000100u)
#define CSL_EDMA3CC_SER_E8_SHIFT         (0x00000008u)
#define CSL_EDMA3CC_SER_E8_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_SER_E7_MASK          (0x00000080u)
#define CSL_EDMA3CC_SER_E7_SHIFT         (0x00000007u)
#define CSL_EDMA3CC_SER_E7_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_SER_E6_MASK          (0x00000040u)
#define CSL_EDMA3CC_SER_E6_SHIFT         (0x00000006u)
#define CSL_EDMA3CC_SER_E6_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_SER_E5_MASK          (0x00000020u)
#define CSL_EDMA3CC_SER_E5_SHIFT         (0x00000005u)
#define CSL_EDMA3CC_SER_E5_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_SER_E4_MASK          (0x00000010u)
#define CSL_EDMA3CC_SER_E4_SHIFT         (0x00000004u)
#define CSL_EDMA3CC_SER_E4_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_SER_E3_MASK          (0x00000008u)
#define CSL_EDMA3CC_SER_E3_SHIFT         (0x00000003u)
#define CSL_EDMA3CC_SER_E3_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_SER_E2_MASK          (0x00000004u)
#define CSL_EDMA3CC_SER_E2_SHIFT         (0x00000002u)
#define CSL_EDMA3CC_SER_E2_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_SER_E1_MASK          (0x00000002u)
#define CSL_EDMA3CC_SER_E1_SHIFT         (0x00000001u)
#define CSL_EDMA3CC_SER_E1_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_SER_E0_MASK          (0x00000001u)
#define CSL_EDMA3CC_SER_E0_SHIFT         (0x00000000u)
#define CSL_EDMA3CC_SER_E0_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_SER_RESETVAL         (0x00000000u)

/* SERH */

#define CSL_EDMA3CC_SERH_E63_MASK        (0x80000000u)
#define CSL_EDMA3CC_SERH_E63_SHIFT       (0x0000001Fu)
#define CSL_EDMA3CC_SERH_E63_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_SERH_E62_MASK        (0x40000000u)
#define CSL_EDMA3CC_SERH_E62_SHIFT       (0x0000001Eu)
#define CSL_EDMA3CC_SERH_E62_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_SERH_E61_MASK        (0x20000000u)
#define CSL_EDMA3CC_SERH_E61_SHIFT       (0x0000001Du)
#define CSL_EDMA3CC_SERH_E61_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_SERH_E60_MASK        (0x10000000u)
#define CSL_EDMA3CC_SERH_E60_SHIFT       (0x0000001Cu)
#define CSL_EDMA3CC_SERH_E60_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_SERH_E59_MASK        (0x08000000u)
#define CSL_EDMA3CC_SERH_E59_SHIFT       (0x0000001Bu)
#define CSL_EDMA3CC_SERH_E59_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_SERH_E58_MASK        (0x04000000u)
#define CSL_EDMA3CC_SERH_E58_SHIFT       (0x0000001Au)
#define CSL_EDMA3CC_SERH_E58_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_SERH_E57_MASK        (0x02000000u)
#define CSL_EDMA3CC_SERH_E57_SHIFT       (0x00000019u)
#define CSL_EDMA3CC_SERH_E57_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_SERH_E56_MASK        (0x01000000u)
#define CSL_EDMA3CC_SERH_E56_SHIFT       (0x00000018u)
#define CSL_EDMA3CC_SERH_E56_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_SERH_E55_MASK        (0x00800000u)
#define CSL_EDMA3CC_SERH_E55_SHIFT       (0x00000017u)
#define CSL_EDMA3CC_SERH_E55_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_SERH_E54_MASK        (0x00400000u)
#define CSL_EDMA3CC_SERH_E54_SHIFT       (0x00000016u)
#define CSL_EDMA3CC_SERH_E54_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_SERH_E53_MASK        (0x00200000u)
#define CSL_EDMA3CC_SERH_E53_SHIFT       (0x00000015u)
#define CSL_EDMA3CC_SERH_E53_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_SERH_E52_MASK        (0x00100000u)
#define CSL_EDMA3CC_SERH_E52_SHIFT       (0x00000014u)
#define CSL_EDMA3CC_SERH_E52_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_SERH_E51_MASK        (0x00080000u)
#define CSL_EDMA3CC_SERH_E51_SHIFT       (0x00000013u)
#define CSL_EDMA3CC_SERH_E51_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_SERH_E50_MASK        (0x00040000u)
#define CSL_EDMA3CC_SERH_E50_SHIFT       (0x00000012u)
#define CSL_EDMA3CC_SERH_E50_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_SERH_E49_MASK        (0x00020000u)
#define CSL_EDMA3CC_SERH_E49_SHIFT       (0x00000011u)
#define CSL_EDMA3CC_SERH_E49_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_SERH_E48_MASK        (0x00010000u)
#define CSL_EDMA3CC_SERH_E48_SHIFT       (0x00000010u)
#define CSL_EDMA3CC_SERH_E48_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_SERH_E47_MASK        (0x00008000u)
#define CSL_EDMA3CC_SERH_E47_SHIFT       (0x0000000Fu)
#define CSL_EDMA3CC_SERH_E47_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_SERH_E46_MASK        (0x00004000u)
#define CSL_EDMA3CC_SERH_E46_SHIFT       (0x0000000Eu)
#define CSL_EDMA3CC_SERH_E46_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_SERH_E45_MASK        (0x00002000u)
#define CSL_EDMA3CC_SERH_E45_SHIFT       (0x0000000Du)
#define CSL_EDMA3CC_SERH_E45_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_SERH_E44_MASK        (0x00001000u)
#define CSL_EDMA3CC_SERH_E44_SHIFT       (0x0000000Cu)
#define CSL_EDMA3CC_SERH_E44_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_SERH_E43_MASK        (0x00000800u)
#define CSL_EDMA3CC_SERH_E43_SHIFT       (0x0000000Bu)
#define CSL_EDMA3CC_SERH_E43_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_SERH_E42_MASK        (0x00000400u)
#define CSL_EDMA3CC_SERH_E42_SHIFT       (0x0000000Au)
#define CSL_EDMA3CC_SERH_E42_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_SERH_E41_MASK        (0x00000200u)
#define CSL_EDMA3CC_SERH_E41_SHIFT       (0x00000009u)
#define CSL_EDMA3CC_SERH_E41_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_SERH_E40_MASK        (0x00000100u)
#define CSL_EDMA3CC_SERH_E40_SHIFT       (0x00000008u)
#define CSL_EDMA3CC_SERH_E40_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_SERH_E39_MASK        (0x00000080u)
#define CSL_EDMA3CC_SERH_E39_SHIFT       (0x00000007u)
#define CSL_EDMA3CC_SERH_E39_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_SERH_E38_MASK        (0x00000040u)
#define CSL_EDMA3CC_SERH_E38_SHIFT       (0x00000006u)
#define CSL_EDMA3CC_SERH_E38_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_SERH_E37_MASK        (0x00000020u)
#define CSL_EDMA3CC_SERH_E37_SHIFT       (0x00000005u)
#define CSL_EDMA3CC_SERH_E37_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_SERH_E36_MASK        (0x00000010u)
#define CSL_EDMA3CC_SERH_E36_SHIFT       (0x00000004u)
#define CSL_EDMA3CC_SERH_E36_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_SERH_E35_MASK        (0x00000008u)
#define CSL_EDMA3CC_SERH_E35_SHIFT       (0x00000003u)
#define CSL_EDMA3CC_SERH_E35_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_SERH_E34_MASK        (0x00000004u)
#define CSL_EDMA3CC_SERH_E34_SHIFT       (0x00000002u)
#define CSL_EDMA3CC_SERH_E34_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_SERH_E33_MASK        (0x00000002u)
#define CSL_EDMA3CC_SERH_E33_SHIFT       (0x00000001u)
#define CSL_EDMA3CC_SERH_E33_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_SERH_E32_MASK        (0x00000001u)
#define CSL_EDMA3CC_SERH_E32_SHIFT       (0x00000000u)
#define CSL_EDMA3CC_SERH_E32_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_SERH_RESETVAL        (0x00000000u)

/* SECR */

#define CSL_EDMA3CC_SECR_E31_MASK        (0x80000000u)
#define CSL_EDMA3CC_SECR_E31_SHIFT       (0x0000001Fu)
#define CSL_EDMA3CC_SECR_E31_RESETVAL    (0x00000000u)

/*----E31 Tokens----*/
#define CSL_EDMA3CC_SECR_E31_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_SECR_E30_MASK        (0x40000000u)
#define CSL_EDMA3CC_SECR_E30_SHIFT       (0x0000001Eu)
#define CSL_EDMA3CC_SECR_E30_RESETVAL    (0x00000000u)

/*----E30 Tokens----*/
#define CSL_EDMA3CC_SECR_E30_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_SECR_E29_MASK        (0x20000000u)
#define CSL_EDMA3CC_SECR_E29_SHIFT       (0x0000001Du)
#define CSL_EDMA3CC_SECR_E29_RESETVAL    (0x00000000u)

/*----E29 Tokens----*/
#define CSL_EDMA3CC_SECR_E29_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_SECR_E28_MASK        (0x10000000u)
#define CSL_EDMA3CC_SECR_E28_SHIFT       (0x0000001Cu)
#define CSL_EDMA3CC_SECR_E28_RESETVAL    (0x00000000u)

/*----E28 Tokens----*/
#define CSL_EDMA3CC_SECR_E28_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_SECR_E27_MASK        (0x08000000u)
#define CSL_EDMA3CC_SECR_E27_SHIFT       (0x0000001Bu)
#define CSL_EDMA3CC_SECR_E27_RESETVAL    (0x00000000u)

/*----E27 Tokens----*/
#define CSL_EDMA3CC_SECR_E27_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_SECR_E26_MASK        (0x04000000u)
#define CSL_EDMA3CC_SECR_E26_SHIFT       (0x0000001Au)
#define CSL_EDMA3CC_SECR_E26_RESETVAL    (0x00000000u)

/*----E26 Tokens----*/
#define CSL_EDMA3CC_SECR_E26_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_SECR_E25_MASK        (0x02000000u)
#define CSL_EDMA3CC_SECR_E25_SHIFT       (0x00000019u)
#define CSL_EDMA3CC_SECR_E25_RESETVAL    (0x00000000u)

/*----E25 Tokens----*/
#define CSL_EDMA3CC_SECR_E25_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_SECR_E24_MASK        (0x01000000u)
#define CSL_EDMA3CC_SECR_E24_SHIFT       (0x00000018u)
#define CSL_EDMA3CC_SECR_E24_RESETVAL    (0x00000000u)

/*----E24 Tokens----*/
#define CSL_EDMA3CC_SECR_E24_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_SECR_E23_MASK        (0x00800000u)
#define CSL_EDMA3CC_SECR_E23_SHIFT       (0x00000017u)
#define CSL_EDMA3CC_SECR_E23_RESETVAL    (0x00000000u)

/*----E23 Tokens----*/
#define CSL_EDMA3CC_SECR_E23_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_SECR_E22_MASK        (0x00400000u)
#define CSL_EDMA3CC_SECR_E22_SHIFT       (0x00000016u)
#define CSL_EDMA3CC_SECR_E22_RESETVAL    (0x00000000u)

/*----E22 Tokens----*/
#define CSL_EDMA3CC_SECR_E22_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_SECR_E21_MASK        (0x00200000u)
#define CSL_EDMA3CC_SECR_E21_SHIFT       (0x00000015u)
#define CSL_EDMA3CC_SECR_E21_RESETVAL    (0x00000000u)

/*----E21 Tokens----*/
#define CSL_EDMA3CC_SECR_E21_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_SECR_E20_MASK        (0x00100000u)
#define CSL_EDMA3CC_SECR_E20_SHIFT       (0x00000014u)
#define CSL_EDMA3CC_SECR_E20_RESETVAL    (0x00000000u)

/*----E20 Tokens----*/
#define CSL_EDMA3CC_SECR_E20_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_SECR_E19_MASK        (0x00080000u)
#define CSL_EDMA3CC_SECR_E19_SHIFT       (0x00000013u)
#define CSL_EDMA3CC_SECR_E19_RESETVAL    (0x00000000u)

/*----E19 Tokens----*/
#define CSL_EDMA3CC_SECR_E19_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_SECR_E18_MASK        (0x00040000u)
#define CSL_EDMA3CC_SECR_E18_SHIFT       (0x00000012u)
#define CSL_EDMA3CC_SECR_E18_RESETVAL    (0x00000000u)

/*----E18 Tokens----*/
#define CSL_EDMA3CC_SECR_E18_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_SECR_E17_MASK        (0x00020000u)
#define CSL_EDMA3CC_SECR_E17_SHIFT       (0x00000011u)
#define CSL_EDMA3CC_SECR_E17_RESETVAL    (0x00000000u)

/*----E17 Tokens----*/
#define CSL_EDMA3CC_SECR_E17_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_SECR_E16_MASK        (0x00010000u)
#define CSL_EDMA3CC_SECR_E16_SHIFT       (0x00000010u)
#define CSL_EDMA3CC_SECR_E16_RESETVAL    (0x00000000u)

/*----E16 Tokens----*/
#define CSL_EDMA3CC_SECR_E16_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_SECR_E15_MASK        (0x00008000u)
#define CSL_EDMA3CC_SECR_E15_SHIFT       (0x0000000Fu)
#define CSL_EDMA3CC_SECR_E15_RESETVAL    (0x00000000u)

/*----E15 Tokens----*/
#define CSL_EDMA3CC_SECR_E15_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_SECR_E14_MASK        (0x00004000u)
#define CSL_EDMA3CC_SECR_E14_SHIFT       (0x0000000Eu)
#define CSL_EDMA3CC_SECR_E14_RESETVAL    (0x00000000u)

/*----E14 Tokens----*/
#define CSL_EDMA3CC_SECR_E14_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_SECR_E13_MASK        (0x00002000u)
#define CSL_EDMA3CC_SECR_E13_SHIFT       (0x0000000Du)
#define CSL_EDMA3CC_SECR_E13_RESETVAL    (0x00000000u)

/*----E13 Tokens----*/
#define CSL_EDMA3CC_SECR_E13_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_SECR_E12_MASK        (0x00001000u)
#define CSL_EDMA3CC_SECR_E12_SHIFT       (0x0000000Cu)
#define CSL_EDMA3CC_SECR_E12_RESETVAL    (0x00000000u)

/*----E12 Tokens----*/
#define CSL_EDMA3CC_SECR_E12_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_SECR_E11_MASK        (0x00000800u)
#define CSL_EDMA3CC_SECR_E11_SHIFT       (0x0000000Bu)
#define CSL_EDMA3CC_SECR_E11_RESETVAL    (0x00000000u)

/*----E11 Tokens----*/
#define CSL_EDMA3CC_SECR_E11_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_SECR_E10_MASK        (0x00000400u)
#define CSL_EDMA3CC_SECR_E10_SHIFT       (0x0000000Au)
#define CSL_EDMA3CC_SECR_E10_RESETVAL    (0x00000000u)

/*----E10 Tokens----*/
#define CSL_EDMA3CC_SECR_E10_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_SECR_E9_MASK         (0x00000200u)
#define CSL_EDMA3CC_SECR_E9_SHIFT        (0x00000009u)
#define CSL_EDMA3CC_SECR_E9_RESETVAL     (0x00000000u)

/*----E9 Tokens----*/
#define CSL_EDMA3CC_SECR_E9_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_SECR_E8_MASK         (0x00000100u)
#define CSL_EDMA3CC_SECR_E8_SHIFT        (0x00000008u)
#define CSL_EDMA3CC_SECR_E8_RESETVAL     (0x00000000u)

/*----E8 Tokens----*/
#define CSL_EDMA3CC_SECR_E8_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_SECR_E7_MASK         (0x00000080u)
#define CSL_EDMA3CC_SECR_E7_SHIFT        (0x00000007u)
#define CSL_EDMA3CC_SECR_E7_RESETVAL     (0x00000000u)

/*----E7 Tokens----*/
#define CSL_EDMA3CC_SECR_E7_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_SECR_E6_MASK         (0x00000040u)
#define CSL_EDMA3CC_SECR_E6_SHIFT        (0x00000006u)
#define CSL_EDMA3CC_SECR_E6_RESETVAL     (0x00000000u)

/*----E6 Tokens----*/
#define CSL_EDMA3CC_SECR_E6_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_SECR_E5_MASK         (0x00000020u)
#define CSL_EDMA3CC_SECR_E5_SHIFT        (0x00000005u)
#define CSL_EDMA3CC_SECR_E5_RESETVAL     (0x00000000u)

/*----E5 Tokens----*/
#define CSL_EDMA3CC_SECR_E5_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_SECR_E4_MASK         (0x00000010u)
#define CSL_EDMA3CC_SECR_E4_SHIFT        (0x00000004u)
#define CSL_EDMA3CC_SECR_E4_RESETVAL     (0x00000000u)

/*----E4 Tokens----*/
#define CSL_EDMA3CC_SECR_E4_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_SECR_E3_MASK         (0x00000008u)
#define CSL_EDMA3CC_SECR_E3_SHIFT        (0x00000003u)
#define CSL_EDMA3CC_SECR_E3_RESETVAL     (0x00000000u)

/*----E3 Tokens----*/
#define CSL_EDMA3CC_SECR_E3_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_SECR_E2_MASK         (0x00000004u)
#define CSL_EDMA3CC_SECR_E2_SHIFT        (0x00000002u)
#define CSL_EDMA3CC_SECR_E2_RESETVAL     (0x00000000u)

/*----E2 Tokens----*/
#define CSL_EDMA3CC_SECR_E2_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_SECR_E1_MASK         (0x00000002u)
#define CSL_EDMA3CC_SECR_E1_SHIFT        (0x00000001u)
#define CSL_EDMA3CC_SECR_E1_RESETVAL     (0x00000000u)

/*----E1 Tokens----*/
#define CSL_EDMA3CC_SECR_E1_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_SECR_E0_MASK         (0x00000001u)
#define CSL_EDMA3CC_SECR_E0_SHIFT        (0x00000000u)
#define CSL_EDMA3CC_SECR_E0_RESETVAL     (0x00000000u)

/*----E0 Tokens----*/
#define CSL_EDMA3CC_SECR_E0_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_SECR_RESETVAL        (0x00000000u)

/* SECRH */

#define CSL_EDMA3CC_SECRH_E63_MASK       (0x80000000u)
#define CSL_EDMA3CC_SECRH_E63_SHIFT      (0x0000001Fu)
#define CSL_EDMA3CC_SECRH_E63_RESETVAL   (0x00000000u)

/*----E63 Tokens----*/
#define CSL_EDMA3CC_SECRH_E63_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_SECRH_E62_MASK       (0x40000000u)
#define CSL_EDMA3CC_SECRH_E62_SHIFT      (0x0000001Eu)
#define CSL_EDMA3CC_SECRH_E62_RESETVAL   (0x00000000u)

/*----E62 Tokens----*/
#define CSL_EDMA3CC_SECRH_E62_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_SECRH_E61_MASK       (0x20000000u)
#define CSL_EDMA3CC_SECRH_E61_SHIFT      (0x0000001Du)
#define CSL_EDMA3CC_SECRH_E61_RESETVAL   (0x00000000u)

/*----E61 Tokens----*/
#define CSL_EDMA3CC_SECRH_E61_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_SECRH_E60_MASK       (0x10000000u)
#define CSL_EDMA3CC_SECRH_E60_SHIFT      (0x0000001Cu)
#define CSL_EDMA3CC_SECRH_E60_RESETVAL   (0x00000000u)

/*----E60 Tokens----*/
#define CSL_EDMA3CC_SECRH_E60_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_SECRH_E59_MASK       (0x08000000u)
#define CSL_EDMA3CC_SECRH_E59_SHIFT      (0x0000001Bu)
#define CSL_EDMA3CC_SECRH_E59_RESETVAL   (0x00000000u)

/*----E59 Tokens----*/
#define CSL_EDMA3CC_SECRH_E59_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_SECRH_E58_MASK       (0x04000000u)
#define CSL_EDMA3CC_SECRH_E58_SHIFT      (0x0000001Au)
#define CSL_EDMA3CC_SECRH_E58_RESETVAL   (0x00000000u)

/*----E58 Tokens----*/
#define CSL_EDMA3CC_SECRH_E58_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_SECRH_E57_MASK       (0x02000000u)
#define CSL_EDMA3CC_SECRH_E57_SHIFT      (0x00000019u)
#define CSL_EDMA3CC_SECRH_E57_RESETVAL   (0x00000000u)

/*----E57 Tokens----*/
#define CSL_EDMA3CC_SECRH_E57_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_SECRH_E56_MASK       (0x01000000u)
#define CSL_EDMA3CC_SECRH_E56_SHIFT      (0x00000018u)
#define CSL_EDMA3CC_SECRH_E56_RESETVAL   (0x00000000u)

/*----E56 Tokens----*/
#define CSL_EDMA3CC_SECRH_E56_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_SECRH_E55_MASK       (0x00800000u)
#define CSL_EDMA3CC_SECRH_E55_SHIFT      (0x00000017u)
#define CSL_EDMA3CC_SECRH_E55_RESETVAL   (0x00000000u)

/*----E55 Tokens----*/
#define CSL_EDMA3CC_SECRH_E55_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_SECRH_E54_MASK       (0x00400000u)
#define CSL_EDMA3CC_SECRH_E54_SHIFT      (0x00000016u)
#define CSL_EDMA3CC_SECRH_E54_RESETVAL   (0x00000000u)

/*----E54 Tokens----*/
#define CSL_EDMA3CC_SECRH_E54_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_SECRH_E53_MASK       (0x00200000u)
#define CSL_EDMA3CC_SECRH_E53_SHIFT      (0x00000015u)
#define CSL_EDMA3CC_SECRH_E53_RESETVAL   (0x00000000u)

/*----E53 Tokens----*/
#define CSL_EDMA3CC_SECRH_E53_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_SECRH_E52_MASK       (0x00100000u)
#define CSL_EDMA3CC_SECRH_E52_SHIFT      (0x00000014u)
#define CSL_EDMA3CC_SECRH_E52_RESETVAL   (0x00000000u)

/*----E52 Tokens----*/
#define CSL_EDMA3CC_SECRH_E52_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_SECRH_E51_MASK       (0x00080000u)
#define CSL_EDMA3CC_SECRH_E51_SHIFT      (0x00000013u)
#define CSL_EDMA3CC_SECRH_E51_RESETVAL   (0x00000000u)

/*----E51 Tokens----*/
#define CSL_EDMA3CC_SECRH_E51_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_SECRH_E50_MASK       (0x00040000u)
#define CSL_EDMA3CC_SECRH_E50_SHIFT      (0x00000012u)
#define CSL_EDMA3CC_SECRH_E50_RESETVAL   (0x00000000u)

/*----E50 Tokens----*/
#define CSL_EDMA3CC_SECRH_E50_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_SECRH_E49_MASK       (0x00020000u)
#define CSL_EDMA3CC_SECRH_E49_SHIFT      (0x00000011u)
#define CSL_EDMA3CC_SECRH_E49_RESETVAL   (0x00000000u)

/*----E49 Tokens----*/
#define CSL_EDMA3CC_SECRH_E49_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_SECRH_E48_MASK       (0x00010000u)
#define CSL_EDMA3CC_SECRH_E48_SHIFT      (0x00000010u)
#define CSL_EDMA3CC_SECRH_E48_RESETVAL   (0x00000000u)

/*----E48 Tokens----*/
#define CSL_EDMA3CC_SECRH_E48_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_SECRH_E47_MASK       (0x00008000u)
#define CSL_EDMA3CC_SECRH_E47_SHIFT      (0x0000000Fu)
#define CSL_EDMA3CC_SECRH_E47_RESETVAL   (0x00000000u)

/*----E47 Tokens----*/
#define CSL_EDMA3CC_SECRH_E47_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_SECRH_E46_MASK       (0x00004000u)
#define CSL_EDMA3CC_SECRH_E46_SHIFT      (0x0000000Eu)
#define CSL_EDMA3CC_SECRH_E46_RESETVAL   (0x00000000u)

/*----E46 Tokens----*/
#define CSL_EDMA3CC_SECRH_E46_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_SECRH_E45_MASK       (0x00002000u)
#define CSL_EDMA3CC_SECRH_E45_SHIFT      (0x0000000Du)
#define CSL_EDMA3CC_SECRH_E45_RESETVAL   (0x00000000u)

/*----E45 Tokens----*/
#define CSL_EDMA3CC_SECRH_E45_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_SECRH_E44_MASK       (0x00001000u)
#define CSL_EDMA3CC_SECRH_E44_SHIFT      (0x0000000Cu)
#define CSL_EDMA3CC_SECRH_E44_RESETVAL   (0x00000000u)

/*----E44 Tokens----*/
#define CSL_EDMA3CC_SECRH_E44_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_SECRH_E43_MASK       (0x00000800u)
#define CSL_EDMA3CC_SECRH_E43_SHIFT      (0x0000000Bu)
#define CSL_EDMA3CC_SECRH_E43_RESETVAL   (0x00000000u)

/*----E43 Tokens----*/
#define CSL_EDMA3CC_SECRH_E43_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_SECRH_E42_MASK       (0x00000400u)
#define CSL_EDMA3CC_SECRH_E42_SHIFT      (0x0000000Au)
#define CSL_EDMA3CC_SECRH_E42_RESETVAL   (0x00000000u)

/*----E42 Tokens----*/
#define CSL_EDMA3CC_SECRH_E42_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_SECRH_E41_MASK       (0x00000200u)
#define CSL_EDMA3CC_SECRH_E41_SHIFT      (0x00000009u)
#define CSL_EDMA3CC_SECRH_E41_RESETVAL   (0x00000000u)

/*----E41 Tokens----*/
#define CSL_EDMA3CC_SECRH_E41_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_SECRH_E40_MASK       (0x00000100u)
#define CSL_EDMA3CC_SECRH_E40_SHIFT      (0x00000008u)
#define CSL_EDMA3CC_SECRH_E40_RESETVAL   (0x00000000u)

/*----E40 Tokens----*/
#define CSL_EDMA3CC_SECRH_E40_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_SECRH_E39_MASK       (0x00000080u)
#define CSL_EDMA3CC_SECRH_E39_SHIFT      (0x00000007u)
#define CSL_EDMA3CC_SECRH_E39_RESETVAL   (0x00000000u)

/*----E39 Tokens----*/
#define CSL_EDMA3CC_SECRH_E39_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_SECRH_E38_MASK       (0x00000040u)
#define CSL_EDMA3CC_SECRH_E38_SHIFT      (0x00000006u)
#define CSL_EDMA3CC_SECRH_E38_RESETVAL   (0x00000000u)

/*----E38 Tokens----*/
#define CSL_EDMA3CC_SECRH_E38_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_SECRH_E37_MASK       (0x00000020u)
#define CSL_EDMA3CC_SECRH_E37_SHIFT      (0x00000005u)
#define CSL_EDMA3CC_SECRH_E37_RESETVAL   (0x00000000u)

/*----E37 Tokens----*/
#define CSL_EDMA3CC_SECRH_E37_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_SECRH_E36_MASK       (0x00000010u)
#define CSL_EDMA3CC_SECRH_E36_SHIFT      (0x00000004u)
#define CSL_EDMA3CC_SECRH_E36_RESETVAL   (0x00000000u)

/*----E36 Tokens----*/
#define CSL_EDMA3CC_SECRH_E36_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_SECRH_E35_MASK       (0x00000008u)
#define CSL_EDMA3CC_SECRH_E35_SHIFT      (0x00000003u)
#define CSL_EDMA3CC_SECRH_E35_RESETVAL   (0x00000000u)

/*----E35 Tokens----*/
#define CSL_EDMA3CC_SECRH_E35_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_SECRH_E34_MASK       (0x00000004u)
#define CSL_EDMA3CC_SECRH_E34_SHIFT      (0x00000002u)
#define CSL_EDMA3CC_SECRH_E34_RESETVAL   (0x00000000u)

/*----E34 Tokens----*/
#define CSL_EDMA3CC_SECRH_E34_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_SECRH_E33_MASK       (0x00000002u)
#define CSL_EDMA3CC_SECRH_E33_SHIFT      (0x00000001u)
#define CSL_EDMA3CC_SECRH_E33_RESETVAL   (0x00000000u)

/*----E33 Tokens----*/
#define CSL_EDMA3CC_SECRH_E33_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_SECRH_E32_MASK       (0x00000001u)
#define CSL_EDMA3CC_SECRH_E32_SHIFT      (0x00000000u)
#define CSL_EDMA3CC_SECRH_E32_RESETVAL   (0x00000000u)

/*----E32 Tokens----*/
#define CSL_EDMA3CC_SECRH_E32_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_SECRH_RESETVAL       (0x00000000u)

/* IER */

#define CSL_EDMA3CC_IER_I31_MASK         (0x80000000u)
#define CSL_EDMA3CC_IER_I31_SHIFT        (0x0000001Fu)
#define CSL_EDMA3CC_IER_I31_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IER_I30_MASK         (0x40000000u)
#define CSL_EDMA3CC_IER_I30_SHIFT        (0x0000001Eu)
#define CSL_EDMA3CC_IER_I30_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IER_I29_MASK         (0x20000000u)
#define CSL_EDMA3CC_IER_I29_SHIFT        (0x0000001Du)
#define CSL_EDMA3CC_IER_I29_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IER_I28_MASK         (0x10000000u)
#define CSL_EDMA3CC_IER_I28_SHIFT        (0x0000001Cu)
#define CSL_EDMA3CC_IER_I28_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IER_I27_MASK         (0x08000000u)
#define CSL_EDMA3CC_IER_I27_SHIFT        (0x0000001Bu)
#define CSL_EDMA3CC_IER_I27_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IER_I26_MASK         (0x04000000u)
#define CSL_EDMA3CC_IER_I26_SHIFT        (0x0000001Au)
#define CSL_EDMA3CC_IER_I26_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IER_I25_MASK         (0x02000000u)
#define CSL_EDMA3CC_IER_I25_SHIFT        (0x00000019u)
#define CSL_EDMA3CC_IER_I25_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IER_I24_MASK         (0x01000000u)
#define CSL_EDMA3CC_IER_I24_SHIFT        (0x00000018u)
#define CSL_EDMA3CC_IER_I24_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IER_I23_MASK         (0x00800000u)
#define CSL_EDMA3CC_IER_I23_SHIFT        (0x00000017u)
#define CSL_EDMA3CC_IER_I23_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IER_I22_MASK         (0x00400000u)
#define CSL_EDMA3CC_IER_I22_SHIFT        (0x00000016u)
#define CSL_EDMA3CC_IER_I22_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IER_I21_MASK         (0x00200000u)
#define CSL_EDMA3CC_IER_I21_SHIFT        (0x00000015u)
#define CSL_EDMA3CC_IER_I21_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IER_I20_MASK         (0x00100000u)
#define CSL_EDMA3CC_IER_I20_SHIFT        (0x00000014u)
#define CSL_EDMA3CC_IER_I20_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IER_I19_MASK         (0x00080000u)
#define CSL_EDMA3CC_IER_I19_SHIFT        (0x00000013u)
#define CSL_EDMA3CC_IER_I19_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IER_I18_MASK         (0x00040000u)
#define CSL_EDMA3CC_IER_I18_SHIFT        (0x00000012u)
#define CSL_EDMA3CC_IER_I18_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IER_I17_MASK         (0x00020000u)
#define CSL_EDMA3CC_IER_I17_SHIFT        (0x00000011u)
#define CSL_EDMA3CC_IER_I17_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IER_I16_MASK         (0x00010000u)
#define CSL_EDMA3CC_IER_I16_SHIFT        (0x00000010u)
#define CSL_EDMA3CC_IER_I16_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IER_I15_MASK         (0x00008000u)
#define CSL_EDMA3CC_IER_I15_SHIFT        (0x0000000Fu)
#define CSL_EDMA3CC_IER_I15_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IER_I14_MASK         (0x00004000u)
#define CSL_EDMA3CC_IER_I14_SHIFT        (0x0000000Eu)
#define CSL_EDMA3CC_IER_I14_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IER_I13_MASK         (0x00002000u)
#define CSL_EDMA3CC_IER_I13_SHIFT        (0x0000000Du)
#define CSL_EDMA3CC_IER_I13_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IER_I12_MASK         (0x00001000u)
#define CSL_EDMA3CC_IER_I12_SHIFT        (0x0000000Cu)
#define CSL_EDMA3CC_IER_I12_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IER_I11_MASK         (0x00000800u)
#define CSL_EDMA3CC_IER_I11_SHIFT        (0x0000000Bu)
#define CSL_EDMA3CC_IER_I11_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IER_I10_MASK         (0x00000400u)
#define CSL_EDMA3CC_IER_I10_SHIFT        (0x0000000Au)
#define CSL_EDMA3CC_IER_I10_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IER_I9_MASK          (0x00000200u)
#define CSL_EDMA3CC_IER_I9_SHIFT         (0x00000009u)
#define CSL_EDMA3CC_IER_I9_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_IER_I8_MASK          (0x00000100u)
#define CSL_EDMA3CC_IER_I8_SHIFT         (0x00000008u)
#define CSL_EDMA3CC_IER_I8_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_IER_I7_MASK          (0x00000080u)
#define CSL_EDMA3CC_IER_I7_SHIFT         (0x00000007u)
#define CSL_EDMA3CC_IER_I7_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_IER_I6_MASK          (0x00000040u)
#define CSL_EDMA3CC_IER_I6_SHIFT         (0x00000006u)
#define CSL_EDMA3CC_IER_I6_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_IER_I5_MASK          (0x00000020u)
#define CSL_EDMA3CC_IER_I5_SHIFT         (0x00000005u)
#define CSL_EDMA3CC_IER_I5_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_IER_I4_MASK          (0x00000010u)
#define CSL_EDMA3CC_IER_I4_SHIFT         (0x00000004u)
#define CSL_EDMA3CC_IER_I4_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_IER_I3_MASK          (0x00000008u)
#define CSL_EDMA3CC_IER_I3_SHIFT         (0x00000003u)
#define CSL_EDMA3CC_IER_I3_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_IER_I2_MASK          (0x00000004u)
#define CSL_EDMA3CC_IER_I2_SHIFT         (0x00000002u)
#define CSL_EDMA3CC_IER_I2_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_IER_I1_MASK          (0x00000002u)
#define CSL_EDMA3CC_IER_I1_SHIFT         (0x00000001u)
#define CSL_EDMA3CC_IER_I1_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_IER_I0_MASK          (0x00000001u)
#define CSL_EDMA3CC_IER_I0_SHIFT         (0x00000000u)
#define CSL_EDMA3CC_IER_I0_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_IER_RESETVAL         (0x00000000u)

/* IERH */

#define CSL_EDMA3CC_IERH_I63_MASK        (0x80000000u)
#define CSL_EDMA3CC_IERH_I63_SHIFT       (0x0000001Fu)
#define CSL_EDMA3CC_IERH_I63_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IERH_I62_MASK        (0x40000000u)
#define CSL_EDMA3CC_IERH_I62_SHIFT       (0x0000001Eu)
#define CSL_EDMA3CC_IERH_I62_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IERH_I61_MASK        (0x20000000u)
#define CSL_EDMA3CC_IERH_I61_SHIFT       (0x0000001Du)
#define CSL_EDMA3CC_IERH_I61_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IERH_I60_MASK        (0x10000000u)
#define CSL_EDMA3CC_IERH_I60_SHIFT       (0x0000001Cu)
#define CSL_EDMA3CC_IERH_I60_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IERH_I59_MASK        (0x08000000u)
#define CSL_EDMA3CC_IERH_I59_SHIFT       (0x0000001Bu)
#define CSL_EDMA3CC_IERH_I59_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IERH_I58_MASK        (0x04000000u)
#define CSL_EDMA3CC_IERH_I58_SHIFT       (0x0000001Au)
#define CSL_EDMA3CC_IERH_I58_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IERH_I57_MASK        (0x02000000u)
#define CSL_EDMA3CC_IERH_I57_SHIFT       (0x00000019u)
#define CSL_EDMA3CC_IERH_I57_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IERH_I56_MASK        (0x01000000u)
#define CSL_EDMA3CC_IERH_I56_SHIFT       (0x00000018u)
#define CSL_EDMA3CC_IERH_I56_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IERH_I55_MASK        (0x00800000u)
#define CSL_EDMA3CC_IERH_I55_SHIFT       (0x00000017u)
#define CSL_EDMA3CC_IERH_I55_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IERH_I54_MASK        (0x00400000u)
#define CSL_EDMA3CC_IERH_I54_SHIFT       (0x00000016u)
#define CSL_EDMA3CC_IERH_I54_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IERH_I53_MASK        (0x00200000u)
#define CSL_EDMA3CC_IERH_I53_SHIFT       (0x00000015u)
#define CSL_EDMA3CC_IERH_I53_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IERH_I52_MASK        (0x00100000u)
#define CSL_EDMA3CC_IERH_I52_SHIFT       (0x00000014u)
#define CSL_EDMA3CC_IERH_I52_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IERH_I51_MASK        (0x00080000u)
#define CSL_EDMA3CC_IERH_I51_SHIFT       (0x00000013u)
#define CSL_EDMA3CC_IERH_I51_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IERH_I50_MASK        (0x00040000u)
#define CSL_EDMA3CC_IERH_I50_SHIFT       (0x00000012u)
#define CSL_EDMA3CC_IERH_I50_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IERH_I49_MASK        (0x00020000u)
#define CSL_EDMA3CC_IERH_I49_SHIFT       (0x00000011u)
#define CSL_EDMA3CC_IERH_I49_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IERH_I48_MASK        (0x00010000u)
#define CSL_EDMA3CC_IERH_I48_SHIFT       (0x00000010u)
#define CSL_EDMA3CC_IERH_I48_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IERH_I47_MASK        (0x00008000u)
#define CSL_EDMA3CC_IERH_I47_SHIFT       (0x0000000Fu)
#define CSL_EDMA3CC_IERH_I47_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IERH_I46_MASK        (0x00004000u)
#define CSL_EDMA3CC_IERH_I46_SHIFT       (0x0000000Eu)
#define CSL_EDMA3CC_IERH_I46_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IERH_I45_MASK        (0x00002000u)
#define CSL_EDMA3CC_IERH_I45_SHIFT       (0x0000000Du)
#define CSL_EDMA3CC_IERH_I45_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IERH_I44_MASK        (0x00001000u)
#define CSL_EDMA3CC_IERH_I44_SHIFT       (0x0000000Cu)
#define CSL_EDMA3CC_IERH_I44_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IERH_I43_MASK        (0x00000800u)
#define CSL_EDMA3CC_IERH_I43_SHIFT       (0x0000000Bu)
#define CSL_EDMA3CC_IERH_I43_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IERH_I42_MASK        (0x00000400u)
#define CSL_EDMA3CC_IERH_I42_SHIFT       (0x0000000Au)
#define CSL_EDMA3CC_IERH_I42_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IERH_I41_MASK        (0x00000200u)
#define CSL_EDMA3CC_IERH_I41_SHIFT       (0x00000009u)
#define CSL_EDMA3CC_IERH_I41_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IERH_I40_MASK        (0x00000100u)
#define CSL_EDMA3CC_IERH_I40_SHIFT       (0x00000008u)
#define CSL_EDMA3CC_IERH_I40_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IERH_I39_MASK        (0x00000080u)
#define CSL_EDMA3CC_IERH_I39_SHIFT       (0x00000007u)
#define CSL_EDMA3CC_IERH_I39_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IERH_I38_MASK        (0x00000040u)
#define CSL_EDMA3CC_IERH_I38_SHIFT       (0x00000006u)
#define CSL_EDMA3CC_IERH_I38_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IERH_I37_MASK        (0x00000020u)
#define CSL_EDMA3CC_IERH_I37_SHIFT       (0x00000005u)
#define CSL_EDMA3CC_IERH_I37_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IERH_I36_MASK        (0x00000010u)
#define CSL_EDMA3CC_IERH_I36_SHIFT       (0x00000004u)
#define CSL_EDMA3CC_IERH_I36_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IERH_I35_MASK        (0x00000008u)
#define CSL_EDMA3CC_IERH_I35_SHIFT       (0x00000003u)
#define CSL_EDMA3CC_IERH_I35_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IERH_I34_MASK        (0x00000004u)
#define CSL_EDMA3CC_IERH_I34_SHIFT       (0x00000002u)
#define CSL_EDMA3CC_IERH_I34_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IERH_I33_MASK        (0x00000002u)
#define CSL_EDMA3CC_IERH_I33_SHIFT       (0x00000001u)
#define CSL_EDMA3CC_IERH_I33_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IERH_I32_MASK        (0x00000001u)
#define CSL_EDMA3CC_IERH_I32_SHIFT       (0x00000000u)
#define CSL_EDMA3CC_IERH_I32_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IERH_RESETVAL        (0x00000000u)

/* IECR */

#define CSL_EDMA3CC_IECR_I31_MASK        (0x80000000u)
#define CSL_EDMA3CC_IECR_I31_SHIFT       (0x0000001Fu)
#define CSL_EDMA3CC_IECR_I31_RESETVAL    (0x00000000u)

/*----I31 Tokens----*/
#define CSL_EDMA3CC_IECR_I31_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_IECR_I30_MASK        (0x40000000u)
#define CSL_EDMA3CC_IECR_I30_SHIFT       (0x0000001Eu)
#define CSL_EDMA3CC_IECR_I30_RESETVAL    (0x00000000u)

/*----I30 Tokens----*/
#define CSL_EDMA3CC_IECR_I30_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_IECR_I29_MASK        (0x20000000u)
#define CSL_EDMA3CC_IECR_I29_SHIFT       (0x0000001Du)
#define CSL_EDMA3CC_IECR_I29_RESETVAL    (0x00000000u)

/*----I29 Tokens----*/
#define CSL_EDMA3CC_IECR_I29_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_IECR_I28_MASK        (0x10000000u)
#define CSL_EDMA3CC_IECR_I28_SHIFT       (0x0000001Cu)
#define CSL_EDMA3CC_IECR_I28_RESETVAL    (0x00000000u)

/*----I28 Tokens----*/
#define CSL_EDMA3CC_IECR_I28_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_IECR_I27_MASK        (0x08000000u)
#define CSL_EDMA3CC_IECR_I27_SHIFT       (0x0000001Bu)
#define CSL_EDMA3CC_IECR_I27_RESETVAL    (0x00000000u)

/*----I27 Tokens----*/
#define CSL_EDMA3CC_IECR_I27_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_IECR_I26_MASK        (0x04000000u)
#define CSL_EDMA3CC_IECR_I26_SHIFT       (0x0000001Au)
#define CSL_EDMA3CC_IECR_I26_RESETVAL    (0x00000000u)

/*----I26 Tokens----*/
#define CSL_EDMA3CC_IECR_I26_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_IECR_I25_MASK        (0x02000000u)
#define CSL_EDMA3CC_IECR_I25_SHIFT       (0x00000019u)
#define CSL_EDMA3CC_IECR_I25_RESETVAL    (0x00000000u)

/*----I25 Tokens----*/
#define CSL_EDMA3CC_IECR_I25_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_IECR_I24_MASK        (0x01000000u)
#define CSL_EDMA3CC_IECR_I24_SHIFT       (0x00000018u)
#define CSL_EDMA3CC_IECR_I24_RESETVAL    (0x00000000u)

/*----I24 Tokens----*/
#define CSL_EDMA3CC_IECR_I24_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_IECR_I23_MASK        (0x00800000u)
#define CSL_EDMA3CC_IECR_I23_SHIFT       (0x00000017u)
#define CSL_EDMA3CC_IECR_I23_RESETVAL    (0x00000000u)

/*----I23 Tokens----*/
#define CSL_EDMA3CC_IECR_I23_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_IECR_I22_MASK        (0x00400000u)
#define CSL_EDMA3CC_IECR_I22_SHIFT       (0x00000016u)
#define CSL_EDMA3CC_IECR_I22_RESETVAL    (0x00000000u)

/*----I22 Tokens----*/
#define CSL_EDMA3CC_IECR_I22_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_IECR_I21_MASK        (0x00200000u)
#define CSL_EDMA3CC_IECR_I21_SHIFT       (0x00000015u)
#define CSL_EDMA3CC_IECR_I21_RESETVAL    (0x00000000u)

/*----I21 Tokens----*/
#define CSL_EDMA3CC_IECR_I21_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_IECR_I20_MASK        (0x00100000u)
#define CSL_EDMA3CC_IECR_I20_SHIFT       (0x00000014u)
#define CSL_EDMA3CC_IECR_I20_RESETVAL    (0x00000000u)

/*----I20 Tokens----*/
#define CSL_EDMA3CC_IECR_I20_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_IECR_I19_MASK        (0x00080000u)
#define CSL_EDMA3CC_IECR_I19_SHIFT       (0x00000013u)
#define CSL_EDMA3CC_IECR_I19_RESETVAL    (0x00000000u)

/*----I19 Tokens----*/
#define CSL_EDMA3CC_IECR_I19_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_IECR_I18_MASK        (0x00040000u)
#define CSL_EDMA3CC_IECR_I18_SHIFT       (0x00000012u)
#define CSL_EDMA3CC_IECR_I18_RESETVAL    (0x00000000u)

/*----I18 Tokens----*/
#define CSL_EDMA3CC_IECR_I18_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_IECR_I17_MASK        (0x00020000u)
#define CSL_EDMA3CC_IECR_I17_SHIFT       (0x00000011u)
#define CSL_EDMA3CC_IECR_I17_RESETVAL    (0x00000000u)

/*----I17 Tokens----*/
#define CSL_EDMA3CC_IECR_I17_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_IECR_I16_MASK        (0x00010000u)
#define CSL_EDMA3CC_IECR_I16_SHIFT       (0x00000010u)
#define CSL_EDMA3CC_IECR_I16_RESETVAL    (0x00000000u)

/*----I16 Tokens----*/
#define CSL_EDMA3CC_IECR_I16_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_IECR_I15_MASK        (0x00008000u)
#define CSL_EDMA3CC_IECR_I15_SHIFT       (0x0000000Fu)
#define CSL_EDMA3CC_IECR_I15_RESETVAL    (0x00000000u)

/*----I15 Tokens----*/
#define CSL_EDMA3CC_IECR_I15_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_IECR_I14_MASK        (0x00004000u)
#define CSL_EDMA3CC_IECR_I14_SHIFT       (0x0000000Eu)
#define CSL_EDMA3CC_IECR_I14_RESETVAL    (0x00000000u)

/*----I14 Tokens----*/
#define CSL_EDMA3CC_IECR_I14_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_IECR_I13_MASK        (0x00002000u)
#define CSL_EDMA3CC_IECR_I13_SHIFT       (0x0000000Du)
#define CSL_EDMA3CC_IECR_I13_RESETVAL    (0x00000000u)

/*----I13 Tokens----*/
#define CSL_EDMA3CC_IECR_I13_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_IECR_I12_MASK        (0x00001000u)
#define CSL_EDMA3CC_IECR_I12_SHIFT       (0x0000000Cu)
#define CSL_EDMA3CC_IECR_I12_RESETVAL    (0x00000000u)

/*----I12 Tokens----*/
#define CSL_EDMA3CC_IECR_I12_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_IECR_I11_MASK        (0x00000800u)
#define CSL_EDMA3CC_IECR_I11_SHIFT       (0x0000000Bu)
#define CSL_EDMA3CC_IECR_I11_RESETVAL    (0x00000000u)

/*----I11 Tokens----*/
#define CSL_EDMA3CC_IECR_I11_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_IECR_I10_MASK        (0x00000400u)
#define CSL_EDMA3CC_IECR_I10_SHIFT       (0x0000000Au)
#define CSL_EDMA3CC_IECR_I10_RESETVAL    (0x00000000u)

/*----I10 Tokens----*/
#define CSL_EDMA3CC_IECR_I10_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_IECR_I9_MASK         (0x00000200u)
#define CSL_EDMA3CC_IECR_I9_SHIFT        (0x00000009u)
#define CSL_EDMA3CC_IECR_I9_RESETVAL     (0x00000000u)

/*----I9 Tokens----*/
#define CSL_EDMA3CC_IECR_I9_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_IECR_I8_MASK         (0x00000100u)
#define CSL_EDMA3CC_IECR_I8_SHIFT        (0x00000008u)
#define CSL_EDMA3CC_IECR_I8_RESETVAL     (0x00000000u)

/*----I8 Tokens----*/
#define CSL_EDMA3CC_IECR_I8_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_IECR_I7_MASK         (0x00000080u)
#define CSL_EDMA3CC_IECR_I7_SHIFT        (0x00000007u)
#define CSL_EDMA3CC_IECR_I7_RESETVAL     (0x00000000u)

/*----I7 Tokens----*/
#define CSL_EDMA3CC_IECR_I7_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_IECR_I6_MASK         (0x00000040u)
#define CSL_EDMA3CC_IECR_I6_SHIFT        (0x00000006u)
#define CSL_EDMA3CC_IECR_I6_RESETVAL     (0x00000000u)

/*----I6 Tokens----*/
#define CSL_EDMA3CC_IECR_I6_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_IECR_I5_MASK         (0x00000020u)
#define CSL_EDMA3CC_IECR_I5_SHIFT        (0x00000005u)
#define CSL_EDMA3CC_IECR_I5_RESETVAL     (0x00000000u)

/*----I5 Tokens----*/
#define CSL_EDMA3CC_IECR_I5_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_IECR_I4_MASK         (0x00000010u)
#define CSL_EDMA3CC_IECR_I4_SHIFT        (0x00000004u)
#define CSL_EDMA3CC_IECR_I4_RESETVAL     (0x00000000u)

/*----I4 Tokens----*/
#define CSL_EDMA3CC_IECR_I4_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_IECR_I3_MASK         (0x00000008u)
#define CSL_EDMA3CC_IECR_I3_SHIFT        (0x00000003u)
#define CSL_EDMA3CC_IECR_I3_RESETVAL     (0x00000000u)

/*----I3 Tokens----*/
#define CSL_EDMA3CC_IECR_I3_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_IECR_I2_MASK         (0x00000004u)
#define CSL_EDMA3CC_IECR_I2_SHIFT        (0x00000002u)
#define CSL_EDMA3CC_IECR_I2_RESETVAL     (0x00000000u)

/*----I2 Tokens----*/
#define CSL_EDMA3CC_IECR_I2_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_IECR_I1_MASK         (0x00000002u)
#define CSL_EDMA3CC_IECR_I1_SHIFT        (0x00000001u)
#define CSL_EDMA3CC_IECR_I1_RESETVAL     (0x00000000u)

/*----I1 Tokens----*/
#define CSL_EDMA3CC_IECR_I1_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_IECR_I0_MASK         (0x00000001u)
#define CSL_EDMA3CC_IECR_I0_SHIFT        (0x00000000u)
#define CSL_EDMA3CC_IECR_I0_RESETVAL     (0x00000000u)

/*----I0 Tokens----*/
#define CSL_EDMA3CC_IECR_I0_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_IECR_RESETVAL        (0x00000000u)

/* IECRH */

#define CSL_EDMA3CC_IECRH_I63_MASK       (0x80000000u)
#define CSL_EDMA3CC_IECRH_I63_SHIFT      (0x0000001Fu)
#define CSL_EDMA3CC_IECRH_I63_RESETVAL   (0x00000000u)

/*----I63 Tokens----*/
#define CSL_EDMA3CC_IECRH_I63_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_IECRH_I62_MASK       (0x40000000u)
#define CSL_EDMA3CC_IECRH_I62_SHIFT      (0x0000001Eu)
#define CSL_EDMA3CC_IECRH_I62_RESETVAL   (0x00000000u)

/*----I62 Tokens----*/
#define CSL_EDMA3CC_IECRH_I62_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_IECRH_I61_MASK       (0x20000000u)
#define CSL_EDMA3CC_IECRH_I61_SHIFT      (0x0000001Du)
#define CSL_EDMA3CC_IECRH_I61_RESETVAL   (0x00000000u)

/*----I61 Tokens----*/
#define CSL_EDMA3CC_IECRH_I61_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_IECRH_I60_MASK       (0x10000000u)
#define CSL_EDMA3CC_IECRH_I60_SHIFT      (0x0000001Cu)
#define CSL_EDMA3CC_IECRH_I60_RESETVAL   (0x00000000u)

/*----I60 Tokens----*/
#define CSL_EDMA3CC_IECRH_I60_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_IECRH_I59_MASK       (0x08000000u)
#define CSL_EDMA3CC_IECRH_I59_SHIFT      (0x0000001Bu)
#define CSL_EDMA3CC_IECRH_I59_RESETVAL   (0x00000000u)

/*----I59 Tokens----*/
#define CSL_EDMA3CC_IECRH_I59_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_IECRH_I58_MASK       (0x04000000u)
#define CSL_EDMA3CC_IECRH_I58_SHIFT      (0x0000001Au)
#define CSL_EDMA3CC_IECRH_I58_RESETVAL   (0x00000000u)

/*----I58 Tokens----*/
#define CSL_EDMA3CC_IECRH_I58_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_IECRH_I57_MASK       (0x02000000u)
#define CSL_EDMA3CC_IECRH_I57_SHIFT      (0x00000019u)
#define CSL_EDMA3CC_IECRH_I57_RESETVAL   (0x00000000u)

/*----I57 Tokens----*/
#define CSL_EDMA3CC_IECRH_I57_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_IECRH_I56_MASK       (0x01000000u)
#define CSL_EDMA3CC_IECRH_I56_SHIFT      (0x00000018u)
#define CSL_EDMA3CC_IECRH_I56_RESETVAL   (0x00000000u)

/*----I56 Tokens----*/
#define CSL_EDMA3CC_IECRH_I56_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_IECRH_I55_MASK       (0x00800000u)
#define CSL_EDMA3CC_IECRH_I55_SHIFT      (0x00000017u)
#define CSL_EDMA3CC_IECRH_I55_RESETVAL   (0x00000000u)

/*----I55 Tokens----*/
#define CSL_EDMA3CC_IECRH_I55_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_IECRH_I54_MASK       (0x00400000u)
#define CSL_EDMA3CC_IECRH_I54_SHIFT      (0x00000016u)
#define CSL_EDMA3CC_IECRH_I54_RESETVAL   (0x00000000u)

/*----I54 Tokens----*/
#define CSL_EDMA3CC_IECRH_I54_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_IECRH_I53_MASK       (0x00200000u)
#define CSL_EDMA3CC_IECRH_I53_SHIFT      (0x00000015u)
#define CSL_EDMA3CC_IECRH_I53_RESETVAL   (0x00000000u)

/*----I53 Tokens----*/
#define CSL_EDMA3CC_IECRH_I53_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_IECRH_I52_MASK       (0x00100000u)
#define CSL_EDMA3CC_IECRH_I52_SHIFT      (0x00000014u)
#define CSL_EDMA3CC_IECRH_I52_RESETVAL   (0x00000000u)

/*----I52 Tokens----*/
#define CSL_EDMA3CC_IECRH_I52_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_IECRH_I51_MASK       (0x00080000u)
#define CSL_EDMA3CC_IECRH_I51_SHIFT      (0x00000013u)
#define CSL_EDMA3CC_IECRH_I51_RESETVAL   (0x00000000u)

/*----I51 Tokens----*/
#define CSL_EDMA3CC_IECRH_I51_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_IECRH_I50_MASK       (0x00040000u)
#define CSL_EDMA3CC_IECRH_I50_SHIFT      (0x00000012u)
#define CSL_EDMA3CC_IECRH_I50_RESETVAL   (0x00000000u)

/*----I50 Tokens----*/
#define CSL_EDMA3CC_IECRH_I50_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_IECRH_I49_MASK       (0x00020000u)
#define CSL_EDMA3CC_IECRH_I49_SHIFT      (0x00000011u)
#define CSL_EDMA3CC_IECRH_I49_RESETVAL   (0x00000000u)

/*----I49 Tokens----*/
#define CSL_EDMA3CC_IECRH_I49_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_IECRH_I48_MASK       (0x00010000u)
#define CSL_EDMA3CC_IECRH_I48_SHIFT      (0x00000010u)
#define CSL_EDMA3CC_IECRH_I48_RESETVAL   (0x00000000u)

/*----I48 Tokens----*/
#define CSL_EDMA3CC_IECRH_I48_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_IECRH_I47_MASK       (0x00008000u)
#define CSL_EDMA3CC_IECRH_I47_SHIFT      (0x0000000Fu)
#define CSL_EDMA3CC_IECRH_I47_RESETVAL   (0x00000000u)

/*----I47 Tokens----*/
#define CSL_EDMA3CC_IECRH_I47_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_IECRH_I46_MASK       (0x00004000u)
#define CSL_EDMA3CC_IECRH_I46_SHIFT      (0x0000000Eu)
#define CSL_EDMA3CC_IECRH_I46_RESETVAL   (0x00000000u)

/*----I46 Tokens----*/
#define CSL_EDMA3CC_IECRH_I46_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_IECRH_I45_MASK       (0x00002000u)
#define CSL_EDMA3CC_IECRH_I45_SHIFT      (0x0000000Du)
#define CSL_EDMA3CC_IECRH_I45_RESETVAL   (0x00000000u)

/*----I45 Tokens----*/
#define CSL_EDMA3CC_IECRH_I45_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_IECRH_I44_MASK       (0x00001000u)
#define CSL_EDMA3CC_IECRH_I44_SHIFT      (0x0000000Cu)
#define CSL_EDMA3CC_IECRH_I44_RESETVAL   (0x00000000u)

/*----I44 Tokens----*/
#define CSL_EDMA3CC_IECRH_I44_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_IECRH_I43_MASK       (0x00000800u)
#define CSL_EDMA3CC_IECRH_I43_SHIFT      (0x0000000Bu)
#define CSL_EDMA3CC_IECRH_I43_RESETVAL   (0x00000000u)

/*----I43 Tokens----*/
#define CSL_EDMA3CC_IECRH_I43_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_IECRH_I42_MASK       (0x00000400u)
#define CSL_EDMA3CC_IECRH_I42_SHIFT      (0x0000000Au)
#define CSL_EDMA3CC_IECRH_I42_RESETVAL   (0x00000000u)

/*----I42 Tokens----*/
#define CSL_EDMA3CC_IECRH_I42_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_IECRH_I41_MASK       (0x00000200u)
#define CSL_EDMA3CC_IECRH_I41_SHIFT      (0x00000009u)
#define CSL_EDMA3CC_IECRH_I41_RESETVAL   (0x00000000u)

/*----I41 Tokens----*/
#define CSL_EDMA3CC_IECRH_I41_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_IECRH_I40_MASK       (0x00000100u)
#define CSL_EDMA3CC_IECRH_I40_SHIFT      (0x00000008u)
#define CSL_EDMA3CC_IECRH_I40_RESETVAL   (0x00000000u)

/*----I40 Tokens----*/
#define CSL_EDMA3CC_IECRH_I40_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_IECRH_I39_MASK       (0x00000080u)
#define CSL_EDMA3CC_IECRH_I39_SHIFT      (0x00000007u)
#define CSL_EDMA3CC_IECRH_I39_RESETVAL   (0x00000000u)

/*----I39 Tokens----*/
#define CSL_EDMA3CC_IECRH_I39_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_IECRH_I38_MASK       (0x00000040u)
#define CSL_EDMA3CC_IECRH_I38_SHIFT      (0x00000006u)
#define CSL_EDMA3CC_IECRH_I38_RESETVAL   (0x00000000u)

/*----I38 Tokens----*/
#define CSL_EDMA3CC_IECRH_I38_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_IECRH_I37_MASK       (0x00000020u)
#define CSL_EDMA3CC_IECRH_I37_SHIFT      (0x00000005u)
#define CSL_EDMA3CC_IECRH_I37_RESETVAL   (0x00000000u)

/*----I37 Tokens----*/
#define CSL_EDMA3CC_IECRH_I37_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_IECRH_I36_MASK       (0x00000010u)
#define CSL_EDMA3CC_IECRH_I36_SHIFT      (0x00000004u)
#define CSL_EDMA3CC_IECRH_I36_RESETVAL   (0x00000000u)

/*----I36 Tokens----*/
#define CSL_EDMA3CC_IECRH_I36_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_IECRH_I35_MASK       (0x00000008u)
#define CSL_EDMA3CC_IECRH_I35_SHIFT      (0x00000003u)
#define CSL_EDMA3CC_IECRH_I35_RESETVAL   (0x00000000u)

/*----I35 Tokens----*/
#define CSL_EDMA3CC_IECRH_I35_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_IECRH_I34_MASK       (0x00000004u)
#define CSL_EDMA3CC_IECRH_I34_SHIFT      (0x00000002u)
#define CSL_EDMA3CC_IECRH_I34_RESETVAL   (0x00000000u)

/*----I34 Tokens----*/
#define CSL_EDMA3CC_IECRH_I34_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_IECRH_I33_MASK       (0x00000002u)
#define CSL_EDMA3CC_IECRH_I33_SHIFT      (0x00000001u)
#define CSL_EDMA3CC_IECRH_I33_RESETVAL   (0x00000000u)

/*----I33 Tokens----*/
#define CSL_EDMA3CC_IECRH_I33_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_IECRH_I32_MASK       (0x00000001u)
#define CSL_EDMA3CC_IECRH_I32_SHIFT      (0x00000000u)
#define CSL_EDMA3CC_IECRH_I32_RESETVAL   (0x00000000u)

/*----I32 Tokens----*/
#define CSL_EDMA3CC_IECRH_I32_CLEAR      (0x00000001u)

#define CSL_EDMA3CC_IECRH_RESETVAL       (0x00000000u)

/* IESR */

#define CSL_EDMA3CC_IESR_I31_MASK        (0x80000000u)
#define CSL_EDMA3CC_IESR_I31_SHIFT       (0x0000001Fu)
#define CSL_EDMA3CC_IESR_I31_RESETVAL    (0x00000000u)

/*----I31 Tokens----*/
#define CSL_EDMA3CC_IESR_I31_SET         (0x00000001u)

#define CSL_EDMA3CC_IESR_I30_MASK        (0x40000000u)
#define CSL_EDMA3CC_IESR_I30_SHIFT       (0x0000001Eu)
#define CSL_EDMA3CC_IESR_I30_RESETVAL    (0x00000000u)

/*----I30 Tokens----*/
#define CSL_EDMA3CC_IESR_I30_SET         (0x00000001u)

#define CSL_EDMA3CC_IESR_I29_MASK        (0x20000000u)
#define CSL_EDMA3CC_IESR_I29_SHIFT       (0x0000001Du)
#define CSL_EDMA3CC_IESR_I29_RESETVAL    (0x00000000u)

/*----I29 Tokens----*/
#define CSL_EDMA3CC_IESR_I29_SET         (0x00000001u)

#define CSL_EDMA3CC_IESR_I28_MASK        (0x10000000u)
#define CSL_EDMA3CC_IESR_I28_SHIFT       (0x0000001Cu)
#define CSL_EDMA3CC_IESR_I28_RESETVAL    (0x00000000u)

/*----I28 Tokens----*/
#define CSL_EDMA3CC_IESR_I28_SET         (0x00000001u)

#define CSL_EDMA3CC_IESR_I27_MASK        (0x08000000u)
#define CSL_EDMA3CC_IESR_I27_SHIFT       (0x0000001Bu)
#define CSL_EDMA3CC_IESR_I27_RESETVAL    (0x00000000u)

/*----I27 Tokens----*/
#define CSL_EDMA3CC_IESR_I27_SET         (0x00000001u)

#define CSL_EDMA3CC_IESR_I26_MASK        (0x04000000u)
#define CSL_EDMA3CC_IESR_I26_SHIFT       (0x0000001Au)
#define CSL_EDMA3CC_IESR_I26_RESETVAL    (0x00000000u)

/*----I26 Tokens----*/
#define CSL_EDMA3CC_IESR_I26_SET         (0x00000001u)

#define CSL_EDMA3CC_IESR_I25_MASK        (0x02000000u)
#define CSL_EDMA3CC_IESR_I25_SHIFT       (0x00000019u)
#define CSL_EDMA3CC_IESR_I25_RESETVAL    (0x00000000u)

/*----I25 Tokens----*/
#define CSL_EDMA3CC_IESR_I25_SET         (0x00000001u)

#define CSL_EDMA3CC_IESR_I24_MASK        (0x01000000u)
#define CSL_EDMA3CC_IESR_I24_SHIFT       (0x00000018u)
#define CSL_EDMA3CC_IESR_I24_RESETVAL    (0x00000000u)

/*----I24 Tokens----*/
#define CSL_EDMA3CC_IESR_I24_SET         (0x00000001u)

#define CSL_EDMA3CC_IESR_I23_MASK        (0x00800000u)
#define CSL_EDMA3CC_IESR_I23_SHIFT       (0x00000017u)
#define CSL_EDMA3CC_IESR_I23_RESETVAL    (0x00000000u)

/*----I23 Tokens----*/
#define CSL_EDMA3CC_IESR_I23_SET         (0x00000001u)

#define CSL_EDMA3CC_IESR_I22_MASK        (0x00400000u)
#define CSL_EDMA3CC_IESR_I22_SHIFT       (0x00000016u)
#define CSL_EDMA3CC_IESR_I22_RESETVAL    (0x00000000u)

/*----I22 Tokens----*/
#define CSL_EDMA3CC_IESR_I22_SET         (0x00000001u)

#define CSL_EDMA3CC_IESR_I21_MASK        (0x00200000u)
#define CSL_EDMA3CC_IESR_I21_SHIFT       (0x00000015u)
#define CSL_EDMA3CC_IESR_I21_RESETVAL    (0x00000000u)

/*----I21 Tokens----*/
#define CSL_EDMA3CC_IESR_I21_SET         (0x00000001u)

#define CSL_EDMA3CC_IESR_I20_MASK        (0x00100000u)
#define CSL_EDMA3CC_IESR_I20_SHIFT       (0x00000014u)
#define CSL_EDMA3CC_IESR_I20_RESETVAL    (0x00000000u)

/*----I20 Tokens----*/
#define CSL_EDMA3CC_IESR_I20_SET         (0x00000001u)

#define CSL_EDMA3CC_IESR_I19_MASK        (0x00080000u)
#define CSL_EDMA3CC_IESR_I19_SHIFT       (0x00000013u)
#define CSL_EDMA3CC_IESR_I19_RESETVAL    (0x00000000u)

/*----I19 Tokens----*/
#define CSL_EDMA3CC_IESR_I19_SET         (0x00000001u)

#define CSL_EDMA3CC_IESR_I18_MASK        (0x00040000u)
#define CSL_EDMA3CC_IESR_I18_SHIFT       (0x00000012u)
#define CSL_EDMA3CC_IESR_I18_RESETVAL    (0x00000000u)

/*----I18 Tokens----*/
#define CSL_EDMA3CC_IESR_I18_SET         (0x00000001u)

#define CSL_EDMA3CC_IESR_I17_MASK        (0x00020000u)
#define CSL_EDMA3CC_IESR_I17_SHIFT       (0x00000011u)
#define CSL_EDMA3CC_IESR_I17_RESETVAL    (0x00000000u)

/*----I17 Tokens----*/
#define CSL_EDMA3CC_IESR_I17_SET         (0x00000001u)

#define CSL_EDMA3CC_IESR_I16_MASK        (0x00010000u)
#define CSL_EDMA3CC_IESR_I16_SHIFT       (0x00000010u)
#define CSL_EDMA3CC_IESR_I16_RESETVAL    (0x00000000u)

/*----I16 Tokens----*/
#define CSL_EDMA3CC_IESR_I16_SET         (0x00000001u)

#define CSL_EDMA3CC_IESR_I15_MASK        (0x00008000u)
#define CSL_EDMA3CC_IESR_I15_SHIFT       (0x0000000Fu)
#define CSL_EDMA3CC_IESR_I15_RESETVAL    (0x00000000u)

/*----I15 Tokens----*/
#define CSL_EDMA3CC_IESR_I15_SET         (0x00000001u)

#define CSL_EDMA3CC_IESR_I14_MASK        (0x00004000u)
#define CSL_EDMA3CC_IESR_I14_SHIFT       (0x0000000Eu)
#define CSL_EDMA3CC_IESR_I14_RESETVAL    (0x00000000u)

/*----I14 Tokens----*/
#define CSL_EDMA3CC_IESR_I14_SET         (0x00000001u)

#define CSL_EDMA3CC_IESR_I13_MASK        (0x00002000u)
#define CSL_EDMA3CC_IESR_I13_SHIFT       (0x0000000Du)
#define CSL_EDMA3CC_IESR_I13_RESETVAL    (0x00000000u)

/*----I13 Tokens----*/
#define CSL_EDMA3CC_IESR_I13_SET         (0x00000001u)

#define CSL_EDMA3CC_IESR_I12_MASK        (0x00001000u)
#define CSL_EDMA3CC_IESR_I12_SHIFT       (0x0000000Cu)
#define CSL_EDMA3CC_IESR_I12_RESETVAL    (0x00000000u)

/*----I12 Tokens----*/
#define CSL_EDMA3CC_IESR_I12_SET         (0x00000001u)

#define CSL_EDMA3CC_IESR_I11_MASK        (0x00000800u)
#define CSL_EDMA3CC_IESR_I11_SHIFT       (0x0000000Bu)
#define CSL_EDMA3CC_IESR_I11_RESETVAL    (0x00000000u)

/*----I11 Tokens----*/
#define CSL_EDMA3CC_IESR_I11_SET         (0x00000001u)

#define CSL_EDMA3CC_IESR_I10_MASK        (0x00000400u)
#define CSL_EDMA3CC_IESR_I10_SHIFT       (0x0000000Au)
#define CSL_EDMA3CC_IESR_I10_RESETVAL    (0x00000000u)

/*----I10 Tokens----*/
#define CSL_EDMA3CC_IESR_I10_SET         (0x00000001u)

#define CSL_EDMA3CC_IESR_I9_MASK         (0x00000200u)
#define CSL_EDMA3CC_IESR_I9_SHIFT        (0x00000009u)
#define CSL_EDMA3CC_IESR_I9_RESETVAL     (0x00000000u)

/*----I9 Tokens----*/
#define CSL_EDMA3CC_IESR_I9_SET          (0x00000001u)

#define CSL_EDMA3CC_IESR_I8_MASK         (0x00000100u)
#define CSL_EDMA3CC_IESR_I8_SHIFT        (0x00000008u)
#define CSL_EDMA3CC_IESR_I8_RESETVAL     (0x00000000u)

/*----I8 Tokens----*/
#define CSL_EDMA3CC_IESR_I8_SET          (0x00000001u)

#define CSL_EDMA3CC_IESR_I7_MASK         (0x00000080u)
#define CSL_EDMA3CC_IESR_I7_SHIFT        (0x00000007u)
#define CSL_EDMA3CC_IESR_I7_RESETVAL     (0x00000000u)

/*----I7 Tokens----*/
#define CSL_EDMA3CC_IESR_I7_SET          (0x00000001u)

#define CSL_EDMA3CC_IESR_I6_MASK         (0x00000040u)
#define CSL_EDMA3CC_IESR_I6_SHIFT        (0x00000006u)
#define CSL_EDMA3CC_IESR_I6_RESETVAL     (0x00000000u)

/*----I6 Tokens----*/
#define CSL_EDMA3CC_IESR_I6_SET          (0x00000001u)

#define CSL_EDMA3CC_IESR_I5_MASK         (0x00000020u)
#define CSL_EDMA3CC_IESR_I5_SHIFT        (0x00000005u)
#define CSL_EDMA3CC_IESR_I5_RESETVAL     (0x00000000u)

/*----I5 Tokens----*/
#define CSL_EDMA3CC_IESR_I5_SET          (0x00000001u)

#define CSL_EDMA3CC_IESR_I4_MASK         (0x00000010u)
#define CSL_EDMA3CC_IESR_I4_SHIFT        (0x00000004u)
#define CSL_EDMA3CC_IESR_I4_RESETVAL     (0x00000000u)

/*----I4 Tokens----*/
#define CSL_EDMA3CC_IESR_I4_SET          (0x00000001u)

#define CSL_EDMA3CC_IESR_I3_MASK         (0x00000008u)
#define CSL_EDMA3CC_IESR_I3_SHIFT        (0x00000003u)
#define CSL_EDMA3CC_IESR_I3_RESETVAL     (0x00000000u)

/*----I3 Tokens----*/
#define CSL_EDMA3CC_IESR_I3_SET          (0x00000001u)

#define CSL_EDMA3CC_IESR_I2_MASK         (0x00000004u)
#define CSL_EDMA3CC_IESR_I2_SHIFT        (0x00000002u)
#define CSL_EDMA3CC_IESR_I2_RESETVAL     (0x00000000u)

/*----I2 Tokens----*/
#define CSL_EDMA3CC_IESR_I2_SET          (0x00000001u)

#define CSL_EDMA3CC_IESR_I1_MASK         (0x00000002u)
#define CSL_EDMA3CC_IESR_I1_SHIFT        (0x00000001u)
#define CSL_EDMA3CC_IESR_I1_RESETVAL     (0x00000000u)

/*----I1 Tokens----*/
#define CSL_EDMA3CC_IESR_I1_SET          (0x00000001u)

#define CSL_EDMA3CC_IESR_I0_MASK         (0x00000001u)
#define CSL_EDMA3CC_IESR_I0_SHIFT        (0x00000000u)
#define CSL_EDMA3CC_IESR_I0_RESETVAL     (0x00000000u)

/*----I0 Tokens----*/
#define CSL_EDMA3CC_IESR_I0_SET          (0x00000001u)

#define CSL_EDMA3CC_IESR_RESETVAL        (0x00000000u)

/* IESRH */

#define CSL_EDMA3CC_IESRH_I63_MASK       (0x80000000u)
#define CSL_EDMA3CC_IESRH_I63_SHIFT      (0x0000001Fu)
#define CSL_EDMA3CC_IESRH_I63_RESETVAL   (0x00000000u)

/*----I63 Tokens----*/
#define CSL_EDMA3CC_IESRH_I63_SET        (0x00000001u)

#define CSL_EDMA3CC_IESRH_I62_MASK       (0x40000000u)
#define CSL_EDMA3CC_IESRH_I62_SHIFT      (0x0000001Eu)
#define CSL_EDMA3CC_IESRH_I62_RESETVAL   (0x00000000u)

/*----I62 Tokens----*/
#define CSL_EDMA3CC_IESRH_I62_SET        (0x00000001u)

#define CSL_EDMA3CC_IESRH_I61_MASK       (0x20000000u)
#define CSL_EDMA3CC_IESRH_I61_SHIFT      (0x0000001Du)
#define CSL_EDMA3CC_IESRH_I61_RESETVAL   (0x00000000u)

/*----I61 Tokens----*/
#define CSL_EDMA3CC_IESRH_I61_SET        (0x00000001u)

#define CSL_EDMA3CC_IESRH_I60_MASK       (0x10000000u)
#define CSL_EDMA3CC_IESRH_I60_SHIFT      (0x0000001Cu)
#define CSL_EDMA3CC_IESRH_I60_RESETVAL   (0x00000000u)

/*----I60 Tokens----*/
#define CSL_EDMA3CC_IESRH_I60_SET        (0x00000001u)

#define CSL_EDMA3CC_IESRH_I59_MASK       (0x08000000u)
#define CSL_EDMA3CC_IESRH_I59_SHIFT      (0x0000001Bu)
#define CSL_EDMA3CC_IESRH_I59_RESETVAL   (0x00000000u)

/*----I59 Tokens----*/
#define CSL_EDMA3CC_IESRH_I59_SET        (0x00000001u)

#define CSL_EDMA3CC_IESRH_I58_MASK       (0x04000000u)
#define CSL_EDMA3CC_IESRH_I58_SHIFT      (0x0000001Au)
#define CSL_EDMA3CC_IESRH_I58_RESETVAL   (0x00000000u)

/*----I58 Tokens----*/
#define CSL_EDMA3CC_IESRH_I58_SET        (0x00000001u)

#define CSL_EDMA3CC_IESRH_I57_MASK       (0x02000000u)
#define CSL_EDMA3CC_IESRH_I57_SHIFT      (0x00000019u)
#define CSL_EDMA3CC_IESRH_I57_RESETVAL   (0x00000000u)

/*----I57 Tokens----*/
#define CSL_EDMA3CC_IESRH_I57_SET        (0x00000001u)

#define CSL_EDMA3CC_IESRH_I56_MASK       (0x01000000u)
#define CSL_EDMA3CC_IESRH_I56_SHIFT      (0x00000018u)
#define CSL_EDMA3CC_IESRH_I56_RESETVAL   (0x00000000u)

/*----I56 Tokens----*/
#define CSL_EDMA3CC_IESRH_I56_SET        (0x00000001u)

#define CSL_EDMA3CC_IESRH_I55_MASK       (0x00800000u)
#define CSL_EDMA3CC_IESRH_I55_SHIFT      (0x00000017u)
#define CSL_EDMA3CC_IESRH_I55_RESETVAL   (0x00000000u)

/*----I55 Tokens----*/
#define CSL_EDMA3CC_IESRH_I55_SET        (0x00000001u)

#define CSL_EDMA3CC_IESRH_I54_MASK       (0x00400000u)
#define CSL_EDMA3CC_IESRH_I54_SHIFT      (0x00000016u)
#define CSL_EDMA3CC_IESRH_I54_RESETVAL   (0x00000000u)

/*----I54 Tokens----*/
#define CSL_EDMA3CC_IESRH_I54_SET        (0x00000001u)

#define CSL_EDMA3CC_IESRH_I53_MASK       (0x00200000u)
#define CSL_EDMA3CC_IESRH_I53_SHIFT      (0x00000015u)
#define CSL_EDMA3CC_IESRH_I53_RESETVAL   (0x00000000u)

/*----I53 Tokens----*/
#define CSL_EDMA3CC_IESRH_I53_SET        (0x00000001u)

#define CSL_EDMA3CC_IESRH_I52_MASK       (0x00100000u)
#define CSL_EDMA3CC_IESRH_I52_SHIFT      (0x00000014u)
#define CSL_EDMA3CC_IESRH_I52_RESETVAL   (0x00000000u)

/*----I52 Tokens----*/
#define CSL_EDMA3CC_IESRH_I52_SET        (0x00000001u)

#define CSL_EDMA3CC_IESRH_I51_MASK       (0x00080000u)
#define CSL_EDMA3CC_IESRH_I51_SHIFT      (0x00000013u)
#define CSL_EDMA3CC_IESRH_I51_RESETVAL   (0x00000000u)

/*----I51 Tokens----*/
#define CSL_EDMA3CC_IESRH_I51_SET        (0x00000001u)

#define CSL_EDMA3CC_IESRH_I50_MASK       (0x00040000u)
#define CSL_EDMA3CC_IESRH_I50_SHIFT      (0x00000012u)
#define CSL_EDMA3CC_IESRH_I50_RESETVAL   (0x00000000u)

/*----I50 Tokens----*/
#define CSL_EDMA3CC_IESRH_I50_SET        (0x00000001u)

#define CSL_EDMA3CC_IESRH_I49_MASK       (0x00020000u)
#define CSL_EDMA3CC_IESRH_I49_SHIFT      (0x00000011u)
#define CSL_EDMA3CC_IESRH_I49_RESETVAL   (0x00000000u)

/*----I49 Tokens----*/
#define CSL_EDMA3CC_IESRH_I49_SET        (0x00000001u)

#define CSL_EDMA3CC_IESRH_I48_MASK       (0x00010000u)
#define CSL_EDMA3CC_IESRH_I48_SHIFT      (0x00000010u)
#define CSL_EDMA3CC_IESRH_I48_RESETVAL   (0x00000000u)

/*----I48 Tokens----*/
#define CSL_EDMA3CC_IESRH_I48_SET        (0x00000001u)

#define CSL_EDMA3CC_IESRH_I47_MASK       (0x00008000u)
#define CSL_EDMA3CC_IESRH_I47_SHIFT      (0x0000000Fu)
#define CSL_EDMA3CC_IESRH_I47_RESETVAL   (0x00000000u)

/*----I47 Tokens----*/
#define CSL_EDMA3CC_IESRH_I47_SET        (0x00000001u)

#define CSL_EDMA3CC_IESRH_I46_MASK       (0x00004000u)
#define CSL_EDMA3CC_IESRH_I46_SHIFT      (0x0000000Eu)
#define CSL_EDMA3CC_IESRH_I46_RESETVAL   (0x00000000u)

/*----I46 Tokens----*/
#define CSL_EDMA3CC_IESRH_I46_SET        (0x00000001u)

#define CSL_EDMA3CC_IESRH_I45_MASK       (0x00002000u)
#define CSL_EDMA3CC_IESRH_I45_SHIFT      (0x0000000Du)
#define CSL_EDMA3CC_IESRH_I45_RESETVAL   (0x00000000u)

/*----I45 Tokens----*/
#define CSL_EDMA3CC_IESRH_I45_SET        (0x00000001u)

#define CSL_EDMA3CC_IESRH_I44_MASK       (0x00001000u)
#define CSL_EDMA3CC_IESRH_I44_SHIFT      (0x0000000Cu)
#define CSL_EDMA3CC_IESRH_I44_RESETVAL   (0x00000000u)

/*----I44 Tokens----*/
#define CSL_EDMA3CC_IESRH_I44_SET        (0x00000001u)

#define CSL_EDMA3CC_IESRH_I43_MASK       (0x00000800u)
#define CSL_EDMA3CC_IESRH_I43_SHIFT      (0x0000000Bu)
#define CSL_EDMA3CC_IESRH_I43_RESETVAL   (0x00000000u)

/*----I43 Tokens----*/
#define CSL_EDMA3CC_IESRH_I43_SET        (0x00000001u)

#define CSL_EDMA3CC_IESRH_I42_MASK       (0x00000400u)
#define CSL_EDMA3CC_IESRH_I42_SHIFT      (0x0000000Au)
#define CSL_EDMA3CC_IESRH_I42_RESETVAL   (0x00000000u)

/*----I42 Tokens----*/
#define CSL_EDMA3CC_IESRH_I42_SET        (0x00000001u)

#define CSL_EDMA3CC_IESRH_I41_MASK       (0x00000200u)
#define CSL_EDMA3CC_IESRH_I41_SHIFT      (0x00000009u)
#define CSL_EDMA3CC_IESRH_I41_RESETVAL   (0x00000000u)

/*----I41 Tokens----*/
#define CSL_EDMA3CC_IESRH_I41_SET        (0x00000001u)

#define CSL_EDMA3CC_IESRH_I40_MASK       (0x00000100u)
#define CSL_EDMA3CC_IESRH_I40_SHIFT      (0x00000008u)
#define CSL_EDMA3CC_IESRH_I40_RESETVAL   (0x00000000u)

/*----I40 Tokens----*/
#define CSL_EDMA3CC_IESRH_I40_SET        (0x00000001u)

#define CSL_EDMA3CC_IESRH_I39_MASK       (0x00000080u)
#define CSL_EDMA3CC_IESRH_I39_SHIFT      (0x00000007u)
#define CSL_EDMA3CC_IESRH_I39_RESETVAL   (0x00000000u)

/*----I39 Tokens----*/
#define CSL_EDMA3CC_IESRH_I39_SET        (0x00000001u)

#define CSL_EDMA3CC_IESRH_I38_MASK       (0x00000040u)
#define CSL_EDMA3CC_IESRH_I38_SHIFT      (0x00000006u)
#define CSL_EDMA3CC_IESRH_I38_RESETVAL   (0x00000000u)

/*----I38 Tokens----*/
#define CSL_EDMA3CC_IESRH_I38_SET        (0x00000001u)

#define CSL_EDMA3CC_IESRH_I37_MASK       (0x00000020u)
#define CSL_EDMA3CC_IESRH_I37_SHIFT      (0x00000005u)
#define CSL_EDMA3CC_IESRH_I37_RESETVAL   (0x00000000u)

/*----I37 Tokens----*/
#define CSL_EDMA3CC_IESRH_I37_SET        (0x00000001u)

#define CSL_EDMA3CC_IESRH_I36_MASK       (0x00000010u)
#define CSL_EDMA3CC_IESRH_I36_SHIFT      (0x00000004u)
#define CSL_EDMA3CC_IESRH_I36_RESETVAL   (0x00000000u)

/*----I36 Tokens----*/
#define CSL_EDMA3CC_IESRH_I36_SET        (0x00000001u)

#define CSL_EDMA3CC_IESRH_I35_MASK       (0x00000008u)
#define CSL_EDMA3CC_IESRH_I35_SHIFT      (0x00000003u)
#define CSL_EDMA3CC_IESRH_I35_RESETVAL   (0x00000000u)

/*----I35 Tokens----*/
#define CSL_EDMA3CC_IESRH_I35_SET        (0x00000001u)

#define CSL_EDMA3CC_IESRH_I34_MASK       (0x00000004u)
#define CSL_EDMA3CC_IESRH_I34_SHIFT      (0x00000002u)
#define CSL_EDMA3CC_IESRH_I34_RESETVAL   (0x00000000u)

/*----I34 Tokens----*/
#define CSL_EDMA3CC_IESRH_I34_SET        (0x00000001u)

#define CSL_EDMA3CC_IESRH_I33_MASK       (0x00000002u)
#define CSL_EDMA3CC_IESRH_I33_SHIFT      (0x00000001u)
#define CSL_EDMA3CC_IESRH_I33_RESETVAL   (0x00000000u)

/*----I33 Tokens----*/
#define CSL_EDMA3CC_IESRH_I33_SET        (0x00000001u)

#define CSL_EDMA3CC_IESRH_I32_MASK       (0x00000001u)
#define CSL_EDMA3CC_IESRH_I32_SHIFT      (0x00000000u)
#define CSL_EDMA3CC_IESRH_I32_RESETVAL   (0x00000000u)

/*----I32 Tokens----*/
#define CSL_EDMA3CC_IESRH_I32_SET        (0x00000001u)

#define CSL_EDMA3CC_IESRH_RESETVAL       (0x00000000u)

/* IPR */

#define CSL_EDMA3CC_IPR_I31_MASK         (0x80000000u)
#define CSL_EDMA3CC_IPR_I31_SHIFT        (0x0000001Fu)
#define CSL_EDMA3CC_IPR_I31_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IPR_I30_MASK         (0x40000000u)
#define CSL_EDMA3CC_IPR_I30_SHIFT        (0x0000001Eu)
#define CSL_EDMA3CC_IPR_I30_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IPR_I29_MASK         (0x20000000u)
#define CSL_EDMA3CC_IPR_I29_SHIFT        (0x0000001Du)
#define CSL_EDMA3CC_IPR_I29_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IPR_I28_MASK         (0x10000000u)
#define CSL_EDMA3CC_IPR_I28_SHIFT        (0x0000001Cu)
#define CSL_EDMA3CC_IPR_I28_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IPR_I27_MASK         (0x08000000u)
#define CSL_EDMA3CC_IPR_I27_SHIFT        (0x0000001Bu)
#define CSL_EDMA3CC_IPR_I27_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IPR_I26_MASK         (0x04000000u)
#define CSL_EDMA3CC_IPR_I26_SHIFT        (0x0000001Au)
#define CSL_EDMA3CC_IPR_I26_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IPR_I25_MASK         (0x02000000u)
#define CSL_EDMA3CC_IPR_I25_SHIFT        (0x00000019u)
#define CSL_EDMA3CC_IPR_I25_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IPR_I24_MASK         (0x01000000u)
#define CSL_EDMA3CC_IPR_I24_SHIFT        (0x00000018u)
#define CSL_EDMA3CC_IPR_I24_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IPR_I23_MASK         (0x00800000u)
#define CSL_EDMA3CC_IPR_I23_SHIFT        (0x00000017u)
#define CSL_EDMA3CC_IPR_I23_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IPR_I22_MASK         (0x00400000u)
#define CSL_EDMA3CC_IPR_I22_SHIFT        (0x00000016u)
#define CSL_EDMA3CC_IPR_I22_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IPR_I21_MASK         (0x00200000u)
#define CSL_EDMA3CC_IPR_I21_SHIFT        (0x00000015u)
#define CSL_EDMA3CC_IPR_I21_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IPR_I20_MASK         (0x00100000u)
#define CSL_EDMA3CC_IPR_I20_SHIFT        (0x00000014u)
#define CSL_EDMA3CC_IPR_I20_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IPR_I19_MASK         (0x00080000u)
#define CSL_EDMA3CC_IPR_I19_SHIFT        (0x00000013u)
#define CSL_EDMA3CC_IPR_I19_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IPR_I18_MASK         (0x00040000u)
#define CSL_EDMA3CC_IPR_I18_SHIFT        (0x00000012u)
#define CSL_EDMA3CC_IPR_I18_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IPR_I17_MASK         (0x00020000u)
#define CSL_EDMA3CC_IPR_I17_SHIFT        (0x00000011u)
#define CSL_EDMA3CC_IPR_I17_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IPR_I16_MASK         (0x00010000u)
#define CSL_EDMA3CC_IPR_I16_SHIFT        (0x00000010u)
#define CSL_EDMA3CC_IPR_I16_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IPR_I15_MASK         (0x00008000u)
#define CSL_EDMA3CC_IPR_I15_SHIFT        (0x0000000Fu)
#define CSL_EDMA3CC_IPR_I15_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IPR_I14_MASK         (0x00004000u)
#define CSL_EDMA3CC_IPR_I14_SHIFT        (0x0000000Eu)
#define CSL_EDMA3CC_IPR_I14_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IPR_I13_MASK         (0x00002000u)
#define CSL_EDMA3CC_IPR_I13_SHIFT        (0x0000000Du)
#define CSL_EDMA3CC_IPR_I13_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IPR_I12_MASK         (0x00001000u)
#define CSL_EDMA3CC_IPR_I12_SHIFT        (0x0000000Cu)
#define CSL_EDMA3CC_IPR_I12_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IPR_I11_MASK         (0x00000800u)
#define CSL_EDMA3CC_IPR_I11_SHIFT        (0x0000000Bu)
#define CSL_EDMA3CC_IPR_I11_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IPR_I10_MASK         (0x00000400u)
#define CSL_EDMA3CC_IPR_I10_SHIFT        (0x0000000Au)
#define CSL_EDMA3CC_IPR_I10_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IPR_I9_MASK          (0x00000200u)
#define CSL_EDMA3CC_IPR_I9_SHIFT         (0x00000009u)
#define CSL_EDMA3CC_IPR_I9_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_IPR_I8_MASK          (0x00000100u)
#define CSL_EDMA3CC_IPR_I8_SHIFT         (0x00000008u)
#define CSL_EDMA3CC_IPR_I8_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_IPR_I7_MASK          (0x00000080u)
#define CSL_EDMA3CC_IPR_I7_SHIFT         (0x00000007u)
#define CSL_EDMA3CC_IPR_I7_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_IPR_I6_MASK          (0x00000040u)
#define CSL_EDMA3CC_IPR_I6_SHIFT         (0x00000006u)
#define CSL_EDMA3CC_IPR_I6_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_IPR_I5_MASK          (0x00000020u)
#define CSL_EDMA3CC_IPR_I5_SHIFT         (0x00000005u)
#define CSL_EDMA3CC_IPR_I5_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_IPR_I4_MASK          (0x00000010u)
#define CSL_EDMA3CC_IPR_I4_SHIFT         (0x00000004u)
#define CSL_EDMA3CC_IPR_I4_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_IPR_I3_MASK          (0x00000008u)
#define CSL_EDMA3CC_IPR_I3_SHIFT         (0x00000003u)
#define CSL_EDMA3CC_IPR_I3_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_IPR_I2_MASK          (0x00000004u)
#define CSL_EDMA3CC_IPR_I2_SHIFT         (0x00000002u)
#define CSL_EDMA3CC_IPR_I2_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_IPR_I1_MASK          (0x00000002u)
#define CSL_EDMA3CC_IPR_I1_SHIFT         (0x00000001u)
#define CSL_EDMA3CC_IPR_I1_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_IPR_I0_MASK          (0x00000001u)
#define CSL_EDMA3CC_IPR_I0_SHIFT         (0x00000000u)
#define CSL_EDMA3CC_IPR_I0_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_IPR_RESETVAL         (0x00000000u)

/* IPRH */

#define CSL_EDMA3CC_IPRH_I63_MASK        (0x80000000u)
#define CSL_EDMA3CC_IPRH_I63_SHIFT       (0x0000001Fu)
#define CSL_EDMA3CC_IPRH_I63_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IPRH_I62_MASK        (0x40000000u)
#define CSL_EDMA3CC_IPRH_I62_SHIFT       (0x0000001Eu)
#define CSL_EDMA3CC_IPRH_I62_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IPRH_I61_MASK        (0x20000000u)
#define CSL_EDMA3CC_IPRH_I61_SHIFT       (0x0000001Du)
#define CSL_EDMA3CC_IPRH_I61_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IPRH_I60_MASK        (0x10000000u)
#define CSL_EDMA3CC_IPRH_I60_SHIFT       (0x0000001Cu)
#define CSL_EDMA3CC_IPRH_I60_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IPRH_I59_MASK        (0x08000000u)
#define CSL_EDMA3CC_IPRH_I59_SHIFT       (0x0000001Bu)
#define CSL_EDMA3CC_IPRH_I59_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IPRH_I58_MASK        (0x04000000u)
#define CSL_EDMA3CC_IPRH_I58_SHIFT       (0x0000001Au)
#define CSL_EDMA3CC_IPRH_I58_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IPRH_I57_MASK        (0x02000000u)
#define CSL_EDMA3CC_IPRH_I57_SHIFT       (0x00000019u)
#define CSL_EDMA3CC_IPRH_I57_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IPRH_I56_MASK        (0x01000000u)
#define CSL_EDMA3CC_IPRH_I56_SHIFT       (0x00000018u)
#define CSL_EDMA3CC_IPRH_I56_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IPRH_I55_MASK        (0x00800000u)
#define CSL_EDMA3CC_IPRH_I55_SHIFT       (0x00000017u)
#define CSL_EDMA3CC_IPRH_I55_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IPRH_I54_MASK        (0x00400000u)
#define CSL_EDMA3CC_IPRH_I54_SHIFT       (0x00000016u)
#define CSL_EDMA3CC_IPRH_I54_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IPRH_I53_MASK        (0x00200000u)
#define CSL_EDMA3CC_IPRH_I53_SHIFT       (0x00000015u)
#define CSL_EDMA3CC_IPRH_I53_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IPRH_I52_MASK        (0x00100000u)
#define CSL_EDMA3CC_IPRH_I52_SHIFT       (0x00000014u)
#define CSL_EDMA3CC_IPRH_I52_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IPRH_I51_MASK        (0x00080000u)
#define CSL_EDMA3CC_IPRH_I51_SHIFT       (0x00000013u)
#define CSL_EDMA3CC_IPRH_I51_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IPRH_I50_MASK        (0x00040000u)
#define CSL_EDMA3CC_IPRH_I50_SHIFT       (0x00000012u)
#define CSL_EDMA3CC_IPRH_I50_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IPRH_I49_MASK        (0x00020000u)
#define CSL_EDMA3CC_IPRH_I49_SHIFT       (0x00000011u)
#define CSL_EDMA3CC_IPRH_I49_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IPRH_I48_MASK        (0x00010000u)
#define CSL_EDMA3CC_IPRH_I48_SHIFT       (0x00000010u)
#define CSL_EDMA3CC_IPRH_I48_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IPRH_I47_MASK        (0x00008000u)
#define CSL_EDMA3CC_IPRH_I47_SHIFT       (0x0000000Fu)
#define CSL_EDMA3CC_IPRH_I47_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IPRH_I46_MASK        (0x00004000u)
#define CSL_EDMA3CC_IPRH_I46_SHIFT       (0x0000000Eu)
#define CSL_EDMA3CC_IPRH_I46_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IPRH_I45_MASK        (0x00002000u)
#define CSL_EDMA3CC_IPRH_I45_SHIFT       (0x0000000Du)
#define CSL_EDMA3CC_IPRH_I45_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IPRH_I44_MASK        (0x00001000u)
#define CSL_EDMA3CC_IPRH_I44_SHIFT       (0x0000000Cu)
#define CSL_EDMA3CC_IPRH_I44_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IPRH_I43_MASK        (0x00000800u)
#define CSL_EDMA3CC_IPRH_I43_SHIFT       (0x0000000Bu)
#define CSL_EDMA3CC_IPRH_I43_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IPRH_I42_MASK        (0x00000400u)
#define CSL_EDMA3CC_IPRH_I42_SHIFT       (0x0000000Au)
#define CSL_EDMA3CC_IPRH_I42_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IPRH_I41_MASK        (0x00000200u)
#define CSL_EDMA3CC_IPRH_I41_SHIFT       (0x00000009u)
#define CSL_EDMA3CC_IPRH_I41_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IPRH_I40_MASK        (0x00000100u)
#define CSL_EDMA3CC_IPRH_I40_SHIFT       (0x00000008u)
#define CSL_EDMA3CC_IPRH_I40_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IPRH_I39_MASK        (0x00000080u)
#define CSL_EDMA3CC_IPRH_I39_SHIFT       (0x00000007u)
#define CSL_EDMA3CC_IPRH_I39_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IPRH_I38_MASK        (0x00000040u)
#define CSL_EDMA3CC_IPRH_I38_SHIFT       (0x00000006u)
#define CSL_EDMA3CC_IPRH_I38_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IPRH_I37_MASK        (0x00000020u)
#define CSL_EDMA3CC_IPRH_I37_SHIFT       (0x00000005u)
#define CSL_EDMA3CC_IPRH_I37_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IPRH_I36_MASK        (0x00000010u)
#define CSL_EDMA3CC_IPRH_I36_SHIFT       (0x00000004u)
#define CSL_EDMA3CC_IPRH_I36_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IPRH_I35_MASK        (0x00000008u)
#define CSL_EDMA3CC_IPRH_I35_SHIFT       (0x00000003u)
#define CSL_EDMA3CC_IPRH_I35_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IPRH_I34_MASK        (0x00000004u)
#define CSL_EDMA3CC_IPRH_I34_SHIFT       (0x00000002u)
#define CSL_EDMA3CC_IPRH_I34_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IPRH_I33_MASK        (0x00000002u)
#define CSL_EDMA3CC_IPRH_I33_SHIFT       (0x00000001u)
#define CSL_EDMA3CC_IPRH_I33_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IPRH_I32_MASK        (0x00000001u)
#define CSL_EDMA3CC_IPRH_I32_SHIFT       (0x00000000u)
#define CSL_EDMA3CC_IPRH_I32_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IPRH_RESETVAL        (0x00000000u)

/* ICR */

#define CSL_EDMA3CC_ICR_I31_MASK         (0x80000000u)
#define CSL_EDMA3CC_ICR_I31_SHIFT        (0x0000001Fu)
#define CSL_EDMA3CC_ICR_I31_RESETVAL     (0x00000000u)

/*----I31 Tokens----*/
#define CSL_EDMA3CC_ICR_I31_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_ICR_I30_MASK         (0x40000000u)
#define CSL_EDMA3CC_ICR_I30_SHIFT        (0x0000001Eu)
#define CSL_EDMA3CC_ICR_I30_RESETVAL     (0x00000000u)

/*----I30 Tokens----*/
#define CSL_EDMA3CC_ICR_I30_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_ICR_I29_MASK         (0x20000000u)
#define CSL_EDMA3CC_ICR_I29_SHIFT        (0x0000001Du)
#define CSL_EDMA3CC_ICR_I29_RESETVAL     (0x00000000u)

/*----I29 Tokens----*/
#define CSL_EDMA3CC_ICR_I29_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_ICR_I28_MASK         (0x10000000u)
#define CSL_EDMA3CC_ICR_I28_SHIFT        (0x0000001Cu)
#define CSL_EDMA3CC_ICR_I28_RESETVAL     (0x00000000u)

/*----I28 Tokens----*/
#define CSL_EDMA3CC_ICR_I28_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_ICR_I27_MASK         (0x08000000u)
#define CSL_EDMA3CC_ICR_I27_SHIFT        (0x0000001Bu)
#define CSL_EDMA3CC_ICR_I27_RESETVAL     (0x00000000u)

/*----I27 Tokens----*/
#define CSL_EDMA3CC_ICR_I27_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_ICR_I26_MASK         (0x04000000u)
#define CSL_EDMA3CC_ICR_I26_SHIFT        (0x0000001Au)
#define CSL_EDMA3CC_ICR_I26_RESETVAL     (0x00000000u)

/*----I26 Tokens----*/
#define CSL_EDMA3CC_ICR_I26_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_ICR_I25_MASK         (0x02000000u)
#define CSL_EDMA3CC_ICR_I25_SHIFT        (0x00000019u)
#define CSL_EDMA3CC_ICR_I25_RESETVAL     (0x00000000u)

/*----I25 Tokens----*/
#define CSL_EDMA3CC_ICR_I25_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_ICR_I24_MASK         (0x01000000u)
#define CSL_EDMA3CC_ICR_I24_SHIFT        (0x00000018u)
#define CSL_EDMA3CC_ICR_I24_RESETVAL     (0x00000000u)

/*----I24 Tokens----*/
#define CSL_EDMA3CC_ICR_I24_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_ICR_I23_MASK         (0x00800000u)
#define CSL_EDMA3CC_ICR_I23_SHIFT        (0x00000017u)
#define CSL_EDMA3CC_ICR_I23_RESETVAL     (0x00000000u)

/*----I23 Tokens----*/
#define CSL_EDMA3CC_ICR_I23_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_ICR_I22_MASK         (0x00400000u)
#define CSL_EDMA3CC_ICR_I22_SHIFT        (0x00000016u)
#define CSL_EDMA3CC_ICR_I22_RESETVAL     (0x00000000u)

/*----I22 Tokens----*/
#define CSL_EDMA3CC_ICR_I22_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_ICR_I21_MASK         (0x00200000u)
#define CSL_EDMA3CC_ICR_I21_SHIFT        (0x00000015u)
#define CSL_EDMA3CC_ICR_I21_RESETVAL     (0x00000000u)

/*----I21 Tokens----*/
#define CSL_EDMA3CC_ICR_I21_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_ICR_I20_MASK         (0x00100000u)
#define CSL_EDMA3CC_ICR_I20_SHIFT        (0x00000014u)
#define CSL_EDMA3CC_ICR_I20_RESETVAL     (0x00000000u)

/*----I20 Tokens----*/
#define CSL_EDMA3CC_ICR_I20_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_ICR_I19_MASK         (0x00080000u)
#define CSL_EDMA3CC_ICR_I19_SHIFT        (0x00000013u)
#define CSL_EDMA3CC_ICR_I19_RESETVAL     (0x00000000u)

/*----I19 Tokens----*/
#define CSL_EDMA3CC_ICR_I19_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_ICR_I18_MASK         (0x00040000u)
#define CSL_EDMA3CC_ICR_I18_SHIFT        (0x00000012u)
#define CSL_EDMA3CC_ICR_I18_RESETVAL     (0x00000000u)

/*----I18 Tokens----*/
#define CSL_EDMA3CC_ICR_I18_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_ICR_I17_MASK         (0x00020000u)
#define CSL_EDMA3CC_ICR_I17_SHIFT        (0x00000011u)
#define CSL_EDMA3CC_ICR_I17_RESETVAL     (0x00000000u)

/*----I17 Tokens----*/
#define CSL_EDMA3CC_ICR_I17_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_ICR_I16_MASK         (0x00010000u)
#define CSL_EDMA3CC_ICR_I16_SHIFT        (0x00000010u)
#define CSL_EDMA3CC_ICR_I16_RESETVAL     (0x00000000u)

/*----I16 Tokens----*/
#define CSL_EDMA3CC_ICR_I16_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_ICR_I15_MASK         (0x00008000u)
#define CSL_EDMA3CC_ICR_I15_SHIFT        (0x0000000Fu)
#define CSL_EDMA3CC_ICR_I15_RESETVAL     (0x00000000u)

/*----I15 Tokens----*/
#define CSL_EDMA3CC_ICR_I15_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_ICR_I14_MASK         (0x00004000u)
#define CSL_EDMA3CC_ICR_I14_SHIFT        (0x0000000Eu)
#define CSL_EDMA3CC_ICR_I14_RESETVAL     (0x00000000u)

/*----I14 Tokens----*/
#define CSL_EDMA3CC_ICR_I14_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_ICR_I13_MASK         (0x00002000u)
#define CSL_EDMA3CC_ICR_I13_SHIFT        (0x0000000Du)
#define CSL_EDMA3CC_ICR_I13_RESETVAL     (0x00000000u)

/*----I13 Tokens----*/
#define CSL_EDMA3CC_ICR_I13_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_ICR_I12_MASK         (0x00001000u)
#define CSL_EDMA3CC_ICR_I12_SHIFT        (0x0000000Cu)
#define CSL_EDMA3CC_ICR_I12_RESETVAL     (0x00000000u)

/*----I12 Tokens----*/
#define CSL_EDMA3CC_ICR_I12_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_ICR_I11_MASK         (0x00000800u)
#define CSL_EDMA3CC_ICR_I11_SHIFT        (0x0000000Bu)
#define CSL_EDMA3CC_ICR_I11_RESETVAL     (0x00000000u)

/*----I11 Tokens----*/
#define CSL_EDMA3CC_ICR_I11_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_ICR_I10_MASK         (0x00000400u)
#define CSL_EDMA3CC_ICR_I10_SHIFT        (0x0000000Au)
#define CSL_EDMA3CC_ICR_I10_RESETVAL     (0x00000000u)

/*----I10 Tokens----*/
#define CSL_EDMA3CC_ICR_I10_CLEAR        (0x00000001u)

#define CSL_EDMA3CC_ICR_I9_MASK          (0x00000200u)
#define CSL_EDMA3CC_ICR_I9_SHIFT         (0x00000009u)
#define CSL_EDMA3CC_ICR_I9_RESETVAL      (0x00000000u)

/*----I9 Tokens----*/
#define CSL_EDMA3CC_ICR_I9_CLEAR         (0x00000001u)

#define CSL_EDMA3CC_ICR_I8_MASK          (0x00000100u)
#define CSL_EDMA3CC_ICR_I8_SHIFT         (0x00000008u)
#define CSL_EDMA3CC_ICR_I8_RESETVAL      (0x00000000u)

/*----I8 Tokens----*/
#define CSL_EDMA3CC_ICR_I8_CLEAR         (0x00000001u)

#define CSL_EDMA3CC_ICR_I7_MASK          (0x00000080u)
#define CSL_EDMA3CC_ICR_I7_SHIFT         (0x00000007u)
#define CSL_EDMA3CC_ICR_I7_RESETVAL      (0x00000000u)

/*----I7 Tokens----*/
#define CSL_EDMA3CC_ICR_I7_CLEAR         (0x00000001u)

#define CSL_EDMA3CC_ICR_I6_MASK          (0x00000040u)
#define CSL_EDMA3CC_ICR_I6_SHIFT         (0x00000006u)
#define CSL_EDMA3CC_ICR_I6_RESETVAL      (0x00000000u)

/*----I6 Tokens----*/
#define CSL_EDMA3CC_ICR_I6_CLEAR         (0x00000001u)

#define CSL_EDMA3CC_ICR_I5_MASK          (0x00000020u)
#define CSL_EDMA3CC_ICR_I5_SHIFT         (0x00000005u)
#define CSL_EDMA3CC_ICR_I5_RESETVAL      (0x00000000u)

/*----I5 Tokens----*/
#define CSL_EDMA3CC_ICR_I5_CLEAR         (0x00000001u)

#define CSL_EDMA3CC_ICR_I4_MASK          (0x00000010u)
#define CSL_EDMA3CC_ICR_I4_SHIFT         (0x00000004u)
#define CSL_EDMA3CC_ICR_I4_RESETVAL      (0x00000000u)

/*----I4 Tokens----*/
#define CSL_EDMA3CC_ICR_I4_CLEAR         (0x00000001u)

#define CSL_EDMA3CC_ICR_I3_MASK          (0x00000008u)
#define CSL_EDMA3CC_ICR_I3_SHIFT         (0x00000003u)
#define CSL_EDMA3CC_ICR_I3_RESETVAL      (0x00000000u)

/*----I3 Tokens----*/
#define CSL_EDMA3CC_ICR_I3_CLEAR         (0x00000001u)

#define CSL_EDMA3CC_ICR_I2_MASK          (0x00000004u)
#define CSL_EDMA3CC_ICR_I2_SHIFT         (0x00000002u)
#define CSL_EDMA3CC_ICR_I2_RESETVAL      (0x00000000u)

/*----I2 Tokens----*/
#define CSL_EDMA3CC_ICR_I2_CLEAR         (0x00000001u)

#define CSL_EDMA3CC_ICR_I1_MASK          (0x00000002u)
#define CSL_EDMA3CC_ICR_I1_SHIFT         (0x00000001u)
#define CSL_EDMA3CC_ICR_I1_RESETVAL      (0x00000000u)

/*----I1 Tokens----*/
#define CSL_EDMA3CC_ICR_I1_CLEAR         (0x00000001u)

#define CSL_EDMA3CC_ICR_I0_MASK          (0x00000001u)
#define CSL_EDMA3CC_ICR_I0_SHIFT         (0x00000000u)
#define CSL_EDMA3CC_ICR_I0_RESETVAL      (0x00000000u)

/*----I0 Tokens----*/
#define CSL_EDMA3CC_ICR_I0_CLEAR         (0x00000001u)

#define CSL_EDMA3CC_ICR_RESETVAL         (0x00000000u)

/* ICRH */

#define CSL_EDMA3CC_ICRH_I63_MASK        (0x80000000u)
#define CSL_EDMA3CC_ICRH_I63_SHIFT       (0x0000001Fu)
#define CSL_EDMA3CC_ICRH_I63_RESETVAL    (0x00000000u)

/*----I63 Tokens----*/
#define CSL_EDMA3CC_ICRH_I63_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ICRH_I62_MASK        (0x40000000u)
#define CSL_EDMA3CC_ICRH_I62_SHIFT       (0x0000001Eu)
#define CSL_EDMA3CC_ICRH_I62_RESETVAL    (0x00000000u)

/*----I62 Tokens----*/
#define CSL_EDMA3CC_ICRH_I62_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ICRH_I61_MASK        (0x20000000u)
#define CSL_EDMA3CC_ICRH_I61_SHIFT       (0x0000001Du)
#define CSL_EDMA3CC_ICRH_I61_RESETVAL    (0x00000000u)

/*----I61 Tokens----*/
#define CSL_EDMA3CC_ICRH_I61_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ICRH_I60_MASK        (0x10000000u)
#define CSL_EDMA3CC_ICRH_I60_SHIFT       (0x0000001Cu)
#define CSL_EDMA3CC_ICRH_I60_RESETVAL    (0x00000000u)

/*----I60 Tokens----*/
#define CSL_EDMA3CC_ICRH_I60_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ICRH_I59_MASK        (0x08000000u)
#define CSL_EDMA3CC_ICRH_I59_SHIFT       (0x0000001Bu)
#define CSL_EDMA3CC_ICRH_I59_RESETVAL    (0x00000000u)

/*----I59 Tokens----*/
#define CSL_EDMA3CC_ICRH_I59_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ICRH_I58_MASK        (0x04000000u)
#define CSL_EDMA3CC_ICRH_I58_SHIFT       (0x0000001Au)
#define CSL_EDMA3CC_ICRH_I58_RESETVAL    (0x00000000u)

/*----I58 Tokens----*/
#define CSL_EDMA3CC_ICRH_I58_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ICRH_I57_MASK        (0x02000000u)
#define CSL_EDMA3CC_ICRH_I57_SHIFT       (0x00000019u)
#define CSL_EDMA3CC_ICRH_I57_RESETVAL    (0x00000000u)

/*----I57 Tokens----*/
#define CSL_EDMA3CC_ICRH_I57_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ICRH_I56_MASK        (0x01000000u)
#define CSL_EDMA3CC_ICRH_I56_SHIFT       (0x00000018u)
#define CSL_EDMA3CC_ICRH_I56_RESETVAL    (0x00000000u)

/*----I56 Tokens----*/
#define CSL_EDMA3CC_ICRH_I56_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ICRH_I55_MASK        (0x00800000u)
#define CSL_EDMA3CC_ICRH_I55_SHIFT       (0x00000017u)
#define CSL_EDMA3CC_ICRH_I55_RESETVAL    (0x00000000u)

/*----I55 Tokens----*/
#define CSL_EDMA3CC_ICRH_I55_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ICRH_I54_MASK        (0x00400000u)
#define CSL_EDMA3CC_ICRH_I54_SHIFT       (0x00000016u)
#define CSL_EDMA3CC_ICRH_I54_RESETVAL    (0x00000000u)

/*----I54 Tokens----*/
#define CSL_EDMA3CC_ICRH_I54_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ICRH_I53_MASK        (0x00200000u)
#define CSL_EDMA3CC_ICRH_I53_SHIFT       (0x00000015u)
#define CSL_EDMA3CC_ICRH_I53_RESETVAL    (0x00000000u)

/*----I53 Tokens----*/
#define CSL_EDMA3CC_ICRH_I53_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ICRH_I52_MASK        (0x00100000u)
#define CSL_EDMA3CC_ICRH_I52_SHIFT       (0x00000014u)
#define CSL_EDMA3CC_ICRH_I52_RESETVAL    (0x00000000u)

/*----I52 Tokens----*/
#define CSL_EDMA3CC_ICRH_I52_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ICRH_I51_MASK        (0x00080000u)
#define CSL_EDMA3CC_ICRH_I51_SHIFT       (0x00000013u)
#define CSL_EDMA3CC_ICRH_I51_RESETVAL    (0x00000000u)

/*----I51 Tokens----*/
#define CSL_EDMA3CC_ICRH_I51_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ICRH_I50_MASK        (0x00040000u)
#define CSL_EDMA3CC_ICRH_I50_SHIFT       (0x00000012u)
#define CSL_EDMA3CC_ICRH_I50_RESETVAL    (0x00000000u)

/*----I50 Tokens----*/
#define CSL_EDMA3CC_ICRH_I50_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ICRH_I49_MASK        (0x00020000u)
#define CSL_EDMA3CC_ICRH_I49_SHIFT       (0x00000011u)
#define CSL_EDMA3CC_ICRH_I49_RESETVAL    (0x00000000u)

/*----I49 Tokens----*/
#define CSL_EDMA3CC_ICRH_I49_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ICRH_I48_MASK        (0x00010000u)
#define CSL_EDMA3CC_ICRH_I48_SHIFT       (0x00000010u)
#define CSL_EDMA3CC_ICRH_I48_RESETVAL    (0x00000000u)

/*----I48 Tokens----*/
#define CSL_EDMA3CC_ICRH_I48_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ICRH_I47_MASK        (0x00008000u)
#define CSL_EDMA3CC_ICRH_I47_SHIFT       (0x0000000Fu)
#define CSL_EDMA3CC_ICRH_I47_RESETVAL    (0x00000000u)

/*----I47 Tokens----*/
#define CSL_EDMA3CC_ICRH_I47_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ICRH_I46_MASK        (0x00004000u)
#define CSL_EDMA3CC_ICRH_I46_SHIFT       (0x0000000Eu)
#define CSL_EDMA3CC_ICRH_I46_RESETVAL    (0x00000000u)

/*----I46 Tokens----*/
#define CSL_EDMA3CC_ICRH_I46_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ICRH_I45_MASK        (0x00002000u)
#define CSL_EDMA3CC_ICRH_I45_SHIFT       (0x0000000Du)
#define CSL_EDMA3CC_ICRH_I45_RESETVAL    (0x00000000u)

/*----I45 Tokens----*/
#define CSL_EDMA3CC_ICRH_I45_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ICRH_I44_MASK        (0x00001000u)
#define CSL_EDMA3CC_ICRH_I44_SHIFT       (0x0000000Cu)
#define CSL_EDMA3CC_ICRH_I44_RESETVAL    (0x00000000u)

/*----I44 Tokens----*/
#define CSL_EDMA3CC_ICRH_I44_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ICRH_I43_MASK        (0x00000800u)
#define CSL_EDMA3CC_ICRH_I43_SHIFT       (0x0000000Bu)
#define CSL_EDMA3CC_ICRH_I43_RESETVAL    (0x00000000u)

/*----I43 Tokens----*/
#define CSL_EDMA3CC_ICRH_I43_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ICRH_I42_MASK        (0x00000400u)
#define CSL_EDMA3CC_ICRH_I42_SHIFT       (0x0000000Au)
#define CSL_EDMA3CC_ICRH_I42_RESETVAL    (0x00000000u)

/*----I42 Tokens----*/
#define CSL_EDMA3CC_ICRH_I42_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ICRH_I41_MASK        (0x00000200u)
#define CSL_EDMA3CC_ICRH_I41_SHIFT       (0x00000009u)
#define CSL_EDMA3CC_ICRH_I41_RESETVAL    (0x00000000u)

/*----I41 Tokens----*/
#define CSL_EDMA3CC_ICRH_I41_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ICRH_I40_MASK        (0x00000100u)
#define CSL_EDMA3CC_ICRH_I40_SHIFT       (0x00000008u)
#define CSL_EDMA3CC_ICRH_I40_RESETVAL    (0x00000000u)

/*----I40 Tokens----*/
#define CSL_EDMA3CC_ICRH_I40_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ICRH_I39_MASK        (0x00000080u)
#define CSL_EDMA3CC_ICRH_I39_SHIFT       (0x00000007u)
#define CSL_EDMA3CC_ICRH_I39_RESETVAL    (0x00000000u)

/*----I39 Tokens----*/
#define CSL_EDMA3CC_ICRH_I39_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ICRH_I38_MASK        (0x00000040u)
#define CSL_EDMA3CC_ICRH_I38_SHIFT       (0x00000006u)
#define CSL_EDMA3CC_ICRH_I38_RESETVAL    (0x00000000u)

/*----I38 Tokens----*/
#define CSL_EDMA3CC_ICRH_I38_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ICRH_I37_MASK        (0x00000020u)
#define CSL_EDMA3CC_ICRH_I37_SHIFT       (0x00000005u)
#define CSL_EDMA3CC_ICRH_I37_RESETVAL    (0x00000000u)

/*----I37 Tokens----*/
#define CSL_EDMA3CC_ICRH_I37_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ICRH_I36_MASK        (0x00000010u)
#define CSL_EDMA3CC_ICRH_I36_SHIFT       (0x00000004u)
#define CSL_EDMA3CC_ICRH_I36_RESETVAL    (0x00000000u)

/*----I36 Tokens----*/
#define CSL_EDMA3CC_ICRH_I36_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ICRH_I35_MASK        (0x00000008u)
#define CSL_EDMA3CC_ICRH_I35_SHIFT       (0x00000003u)
#define CSL_EDMA3CC_ICRH_I35_RESETVAL    (0x00000000u)

/*----I35 Tokens----*/
#define CSL_EDMA3CC_ICRH_I35_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ICRH_I34_MASK        (0x00000004u)
#define CSL_EDMA3CC_ICRH_I34_SHIFT       (0x00000002u)
#define CSL_EDMA3CC_ICRH_I34_RESETVAL    (0x00000000u)

/*----I34 Tokens----*/
#define CSL_EDMA3CC_ICRH_I34_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ICRH_I33_MASK        (0x00000002u)
#define CSL_EDMA3CC_ICRH_I33_SHIFT       (0x00000001u)
#define CSL_EDMA3CC_ICRH_I33_RESETVAL    (0x00000000u)

/*----I33 Tokens----*/
#define CSL_EDMA3CC_ICRH_I33_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ICRH_I32_MASK        (0x00000001u)
#define CSL_EDMA3CC_ICRH_I32_SHIFT       (0x00000000u)
#define CSL_EDMA3CC_ICRH_I32_RESETVAL    (0x00000000u)

/*----I32 Tokens----*/
#define CSL_EDMA3CC_ICRH_I32_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_ICRH_RESETVAL        (0x00000000u)

/* IEVAL */

#define CSL_EDMA3CC_IEVAL_EVAL_MASK      (0x00000001u)
#define CSL_EDMA3CC_IEVAL_EVAL_SHIFT     (0x00000000u)
#define CSL_EDMA3CC_IEVAL_EVAL_RESETVAL  (0x00000000u)

/*----EVAL Tokens----*/
#define CSL_EDMA3CC_IEVAL_EVAL_EVAL      (0x00000001u)

#define CSL_EDMA3CC_IEVAL_RESETVAL       (0x00000000u)

/* QER */

#define CSL_EDMA3CC_QER_E7_MASK (0x00000080u)
#define CSL_EDMA3CC_QER_E7_SHIFT (0x00000007u)
#define CSL_EDMA3CC_QER_E7_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_QER_E6_MASK (0x00000040u)
#define CSL_EDMA3CC_QER_E6_SHIFT (0x00000006u)
#define CSL_EDMA3CC_QER_E6_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_QER_E5_MASK (0x00000020u)
#define CSL_EDMA3CC_QER_E5_SHIFT (0x00000005u)
#define CSL_EDMA3CC_QER_E5_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_QER_E4_MASK (0x00000010u)
#define CSL_EDMA3CC_QER_E4_SHIFT (0x00000004u)
#define CSL_EDMA3CC_QER_E4_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_QER_E3_MASK (0x00000008u)
#define CSL_EDMA3CC_QER_E3_SHIFT         (0x00000003u)
#define CSL_EDMA3CC_QER_E3_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_QER_E2_MASK          (0x00000004u)
#define CSL_EDMA3CC_QER_E2_SHIFT         (0x00000002u)
#define CSL_EDMA3CC_QER_E2_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_QER_E1_MASK          (0x00000002u)
#define CSL_EDMA3CC_QER_E1_SHIFT         (0x00000001u)
#define CSL_EDMA3CC_QER_E1_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_QER_E0_MASK          (0x00000001u)
#define CSL_EDMA3CC_QER_E0_SHIFT         (0x00000000u)
#define CSL_EDMA3CC_QER_E0_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_QER_RESETVAL         (0x00000000u)

/* QEER */


#define CSL_EDMA3CC_QEER_E7_MASK (0x00000080u)
#define CSL_EDMA3CC_QEER_E7_SHIFT (0x00000007u)
#define CSL_EDMA3CC_QEER_E7_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_QEER_E6_MASK (0x00000040u)
#define CSL_EDMA3CC_QEER_E6_SHIFT (0x00000006u)
#define CSL_EDMA3CC_QEER_E6_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_QEER_E5_MASK (0x00000020u)
#define CSL_EDMA3CC_QEER_E5_SHIFT (0x00000005u)
#define CSL_EDMA3CC_QEER_E5_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_QEER_E4_MASK (0x00000010u)
#define CSL_EDMA3CC_QEER_E4_SHIFT (0x00000004u)
#define CSL_EDMA3CC_QEER_E4_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_QEER_E3_MASK         (0x00000008u)
#define CSL_EDMA3CC_QEER_E3_SHIFT        (0x00000003u)
#define CSL_EDMA3CC_QEER_E3_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_QEER_E2_MASK         (0x00000004u)
#define CSL_EDMA3CC_QEER_E2_SHIFT        (0x00000002u)
#define CSL_EDMA3CC_QEER_E2_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_QEER_E1_MASK         (0x00000002u)
#define CSL_EDMA3CC_QEER_E1_SHIFT        (0x00000001u)
#define CSL_EDMA3CC_QEER_E1_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_QEER_E0_MASK         (0x00000001u)
#define CSL_EDMA3CC_QEER_E0_SHIFT        (0x00000000u)
#define CSL_EDMA3CC_QEER_E0_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_QEER_RESETVAL        (0x00000000u)

/* QEECR */


#define CSL_EDMA3CC_QEECR_E7_MASK (0x00000080u)
#define CSL_EDMA3CC_QEECR_E7_SHIFT (0x00000007u)
#define CSL_EDMA3CC_QEECR_E7_RESETVAL (0x00000000u)
/*----E7 Tokens----*/
#define CSL_EDMA3CC_QEECR_E7_CLEAR (0x00000001u)

#define CSL_EDMA3CC_QEECR_E6_MASK (0x00000040u)
#define CSL_EDMA3CC_QEECR_E6_SHIFT (0x00000006u)
#define CSL_EDMA3CC_QEECR_E6_RESETVAL (0x00000000u)
/*----E6 Tokens----*/
#define CSL_EDMA3CC_QEECR_E6_CLEAR (0x00000001u)

#define CSL_EDMA3CC_QEECR_E5_MASK (0x00000020u)
#define CSL_EDMA3CC_QEECR_E5_SHIFT (0x00000005u)
#define CSL_EDMA3CC_QEECR_E5_RESETVAL (0x00000000u)
/*----E5 Tokens----*/
#define CSL_EDMA3CC_QEECR_E5_CLEAR (0x00000001u)

#define CSL_EDMA3CC_QEECR_E4_MASK (0x00000010u)
#define CSL_EDMA3CC_QEECR_E4_SHIFT (0x00000004u)
#define CSL_EDMA3CC_QEECR_E4_RESETVAL (0x00000000u)
/*----E4 Tokens----*/
#define CSL_EDMA3CC_QEECR_E4_CLEAR (0x00000001u)

#define CSL_EDMA3CC_QEECR_E3_MASK        (0x00000008u)
#define CSL_EDMA3CC_QEECR_E3_SHIFT       (0x00000003u)
#define CSL_EDMA3CC_QEECR_E3_RESETVAL    (0x00000000u)

/*----E3 Tokens----*/
#define CSL_EDMA3CC_QEECR_E3_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_QEECR_E2_MASK        (0x00000004u)
#define CSL_EDMA3CC_QEECR_E2_SHIFT       (0x00000002u)
#define CSL_EDMA3CC_QEECR_E2_RESETVAL    (0x00000000u)

/*----E2 Tokens----*/
#define CSL_EDMA3CC_QEECR_E2_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_QEECR_E1_MASK        (0x00000002u)
#define CSL_EDMA3CC_QEECR_E1_SHIFT       (0x00000001u)
#define CSL_EDMA3CC_QEECR_E1_RESETVAL    (0x00000000u)

/*----E1 Tokens----*/
#define CSL_EDMA3CC_QEECR_E1_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_QEECR_E0_MASK        (0x00000001u)
#define CSL_EDMA3CC_QEECR_E0_SHIFT       (0x00000000u)
#define CSL_EDMA3CC_QEECR_E0_RESETVAL    (0x00000000u)

/*----E0 Tokens----*/
#define CSL_EDMA3CC_QEECR_E0_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_QEECR_RESETVAL       (0x00000000u)

/* QEESR */


#define CSL_EDMA3CC_QEESR_E7_MASK (0x00000080u)
#define CSL_EDMA3CC_QEESR_E7_SHIFT (0x00000007u)
#define CSL_EDMA3CC_QEESR_E7_RESETVAL (0x00000000u)
/*----E7 Tokens----*/
#define CSL_EDMA3CC_QEESR_E7_SET (0x00000001u)

#define CSL_EDMA3CC_QEESR_E6_MASK (0x00000040u)
#define CSL_EDMA3CC_QEESR_E6_SHIFT (0x00000006u)
#define CSL_EDMA3CC_QEESR_E6_RESETVAL (0x00000000u)
/*----E6 Tokens----*/
#define CSL_EDMA3CC_QEESR_E6_SET (0x00000001u)

#define CSL_EDMA3CC_QEESR_E5_MASK (0x00000020u)
#define CSL_EDMA3CC_QEESR_E5_SHIFT (0x00000005u)
#define CSL_EDMA3CC_QEESR_E5_RESETVAL (0x00000000u)
/*----E5 Tokens----*/
#define CSL_EDMA3CC_QEESR_E5_SET (0x00000001u)

#define CSL_EDMA3CC_QEESR_E4_MASK (0x00000010u)
#define CSL_EDMA3CC_QEESR_E4_SHIFT (0x00000004u)
#define CSL_EDMA3CC_QEESR_E4_RESETVAL (0x00000000u)
/*----E4 Tokens----*/
#define CSL_EDMA3CC_QEESR_E4_SET (0x00000001u)

#define CSL_EDMA3CC_QEESR_E3_MASK        (0x00000008u)
#define CSL_EDMA3CC_QEESR_E3_SHIFT       (0x00000003u)
#define CSL_EDMA3CC_QEESR_E3_RESETVAL    (0x00000000u)

/*----E3 Tokens----*/
#define CSL_EDMA3CC_QEESR_E3_SET         (0x00000001u)

#define CSL_EDMA3CC_QEESR_E2_MASK        (0x00000004u)
#define CSL_EDMA3CC_QEESR_E2_SHIFT       (0x00000002u)
#define CSL_EDMA3CC_QEESR_E2_RESETVAL    (0x00000000u)

/*----E2 Tokens----*/
#define CSL_EDMA3CC_QEESR_E2_SET         (0x00000001u)

#define CSL_EDMA3CC_QEESR_E1_MASK        (0x00000002u)
#define CSL_EDMA3CC_QEESR_E1_SHIFT       (0x00000001u)
#define CSL_EDMA3CC_QEESR_E1_RESETVAL    (0x00000000u)

/*----E1 Tokens----*/
#define CSL_EDMA3CC_QEESR_E1_SET         (0x00000001u)

#define CSL_EDMA3CC_QEESR_E0_MASK        (0x00000001u)
#define CSL_EDMA3CC_QEESR_E0_SHIFT       (0x00000000u)
#define CSL_EDMA3CC_QEESR_E0_RESETVAL    (0x00000000u)

/*----E0 Tokens----*/
#define CSL_EDMA3CC_QEESR_E0_SET         (0x00000001u)

#define CSL_EDMA3CC_QEESR_RESETVAL       (0x00000000u)

/* QSER */

#define CSL_EDMA3CC_QSER_E7_MASK (0x00000080u)
#define CSL_EDMA3CC_QSER_E7_SHIFT (0x00000007u)
#define CSL_EDMA3CC_QSER_E7_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_QSER_E6_MASK (0x00000040u)
#define CSL_EDMA3CC_QSER_E6_SHIFT (0x00000006u)
#define CSL_EDMA3CC_QSER_E6_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_QSER_E5_MASK (0x00000020u)
#define CSL_EDMA3CC_QSER_E5_SHIFT (0x00000005u)
#define CSL_EDMA3CC_QSER_E5_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_QSER_E4_MASK (0x00000010u)
#define CSL_EDMA3CC_QSER_E4_SHIFT (0x00000004u)
#define CSL_EDMA3CC_QSER_E4_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_QSER_E3_MASK         (0x00000008u)
#define CSL_EDMA3CC_QSER_E3_SHIFT        (0x00000003u)
#define CSL_EDMA3CC_QSER_E3_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_QSER_E2_MASK         (0x00000004u)
#define CSL_EDMA3CC_QSER_E2_SHIFT        (0x00000002u)
#define CSL_EDMA3CC_QSER_E2_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_QSER_E1_MASK         (0x00000002u)
#define CSL_EDMA3CC_QSER_E1_SHIFT        (0x00000001u)
#define CSL_EDMA3CC_QSER_E1_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_QSER_E0_MASK         (0x00000001u)
#define CSL_EDMA3CC_QSER_E0_SHIFT        (0x00000000u)
#define CSL_EDMA3CC_QSER_E0_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_QSER_RESETVAL        (0x00000000u)

/* QSECR */


#define CSL_EDMA3CC_QSECR_E7_MASK (0x00000080u)
#define CSL_EDMA3CC_QSECR_E7_SHIFT (0x00000007u)
#define CSL_EDMA3CC_QSECR_E7_RESETVAL (0x00000000u)
/*----E7 Tokens----*/
#define CSL_EDMA3CC_QSECR_E7_CLEAR (0x00000001u)

#define CSL_EDMA3CC_QSECR_E6_MASK (0x00000040u)
#define CSL_EDMA3CC_QSECR_E6_SHIFT (0x00000006u)
#define CSL_EDMA3CC_QSECR_E6_RESETVAL (0x00000000u)
/*----E6 Tokens----*/
#define CSL_EDMA3CC_QSECR_E6_CLEAR (0x00000001u)

#define CSL_EDMA3CC_QSECR_E5_MASK (0x00000020u)
#define CSL_EDMA3CC_QSECR_E5_SHIFT (0x00000005u)
#define CSL_EDMA3CC_QSECR_E5_RESETVAL (0x00000000u)
/*----E5 Tokens----*/
#define CSL_EDMA3CC_QSECR_E5_CLEAR (0x00000001u)

#define CSL_EDMA3CC_QSECR_E4_MASK (0x00000010u)
#define CSL_EDMA3CC_QSECR_E4_SHIFT (0x00000004u)
#define CSL_EDMA3CC_QSECR_E4_RESETVAL (0x00000000u)
/*----E4 Tokens----*/
#define CSL_EDMA3CC_QSECR_E4_CLEAR (0x00000001u)

#define CSL_EDMA3CC_QSECR_E3_MASK        (0x00000008u)
#define CSL_EDMA3CC_QSECR_E3_SHIFT       (0x00000003u)
#define CSL_EDMA3CC_QSECR_E3_RESETVAL    (0x00000000u)

/*----E3 Tokens----*/
#define CSL_EDMA3CC_QSECR_E3_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_QSECR_E2_MASK        (0x00000004u)
#define CSL_EDMA3CC_QSECR_E2_SHIFT       (0x00000002u)
#define CSL_EDMA3CC_QSECR_E2_RESETVAL    (0x00000000u)

/*----E2 Tokens----*/
#define CSL_EDMA3CC_QSECR_E2_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_QSECR_E1_MASK        (0x00000002u)
#define CSL_EDMA3CC_QSECR_E1_SHIFT       (0x00000001u)
#define CSL_EDMA3CC_QSECR_E1_RESETVAL    (0x00000000u)

/*----E1 Tokens----*/
#define CSL_EDMA3CC_QSECR_E1_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_QSECR_E0_MASK        (0x00000001u)
#define CSL_EDMA3CC_QSECR_E0_SHIFT       (0x00000000u)
#define CSL_EDMA3CC_QSECR_E0_RESETVAL    (0x00000000u)

/*----E0 Tokens----*/
#define CSL_EDMA3CC_QSECR_E0_CLEAR       (0x00000001u)

#define CSL_EDMA3CC_QSECR_RESETVAL       (0x00000000u)

/* OPT */

#define CSL_EDMA3CC_OPT_PRIV_MASK        (0x80000000u)
#define CSL_EDMA3CC_OPT_PRIV_SHIFT       (0x0000001Fu)
#define CSL_EDMA3CC_OPT_PRIV_RESETVAL    (0x00000000u)

/*----PRIV Tokens----*/
#define CSL_EDMA3CC_OPT_PRIV_USER        (0x00000000u)
#define CSL_EDMA3CC_OPT_PRIV_SUPERVISOR  (0x00000001u)

#define CSL_EDMA3CC_OPT_PRIVID_MASK      (0x0F000000u)
#define CSL_EDMA3CC_OPT_PRIVID_SHIFT     (0x00000018u)
#define CSL_EDMA3CC_OPT_PRIVID_RESETVAL  (0x00000000u)

#define CSL_EDMA3CC_OPT_ITCCHEN_MASK     (0x00800000u)
#define CSL_EDMA3CC_OPT_ITCCHEN_SHIFT    (0x00000017u)
#define CSL_EDMA3CC_OPT_ITCCHEN_RESETVAL (0x00000000u)

/*----ITCCHEN Tokens----*/
#define CSL_EDMA3CC_OPT_ITCCHEN_DISABLE  (0x00000000u)
#define CSL_EDMA3CC_OPT_ITCCHEN_ENABLE   (0x00000001u)

#define CSL_EDMA3CC_OPT_TCCHEN_MASK      (0x00400000u)
#define CSL_EDMA3CC_OPT_TCCHEN_SHIFT     (0x00000016u)
#define CSL_EDMA3CC_OPT_TCCHEN_RESETVAL  (0x00000000u)

/*----TCCHEN Tokens----*/
#define CSL_EDMA3CC_OPT_TCCHEN_DISABLE   (0x00000000u)
#define CSL_EDMA3CC_OPT_TCCHEN_ENABLE    (0x00000001u)

#define CSL_EDMA3CC_OPT_ITCINTEN_MASK    (0x00200000u)
#define CSL_EDMA3CC_OPT_ITCINTEN_SHIFT   (0x00000015u)
#define CSL_EDMA3CC_OPT_ITCINTEN_RESETVAL (0x00000000u)

/*----ITCINTEN Tokens----*/
#define CSL_EDMA3CC_OPT_ITCINTEN_DISABLE (0x00000000u)
#define CSL_EDMA3CC_OPT_ITCINTEN_ENABLE  (0x00000001u)

#define CSL_EDMA3CC_OPT_TCINTEN_MASK     (0x00100000u)
#define CSL_EDMA3CC_OPT_TCINTEN_SHIFT    (0x00000014u)
#define CSL_EDMA3CC_OPT_TCINTEN_RESETVAL (0x00000000u)

/*----TCINTEN Tokens----*/
#define CSL_EDMA3CC_OPT_TCINTEN_DISABLE  (0x00000000u)
#define CSL_EDMA3CC_OPT_TCINTEN_ENABLE   (0x00000001u)

#define CSL_EDMA3CC_OPT_TCC_MASK         (0x0003F000u)
#define CSL_EDMA3CC_OPT_TCC_SHIFT        (0x0000000Cu)
#define CSL_EDMA3CC_OPT_TCC_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_OPT_TCCMODE_MASK     (0x00000800u)
#define CSL_EDMA3CC_OPT_TCCMODE_SHIFT    (0x0000000Bu)
#define CSL_EDMA3CC_OPT_TCCMODE_RESETVAL (0x00000000u)

/*----TCCMODE Tokens----*/
#define CSL_EDMA3CC_OPT_TCCMODE_NORMAL   (0x00000000u)
#define CSL_EDMA3CC_OPT_TCCMODE_EARLY    (0x00000001u)

#define CSL_EDMA3CC_OPT_FWID_MASK        (0x00000700u)
#define CSL_EDMA3CC_OPT_FWID_SHIFT       (0x00000008u)
#define CSL_EDMA3CC_OPT_FWID_RESETVAL    (0x00000000u)

/*----FWID Tokens----*/
#define CSL_EDMA3CC_OPT_FWID_8           (0x00000000u)
#define CSL_EDMA3CC_OPT_FWID_16          (0x00000001u)
#define CSL_EDMA3CC_OPT_FWID_32          (0x00000002u)
#define CSL_EDMA3CC_OPT_FWID_64          (0x00000003u)
#define CSL_EDMA3CC_OPT_FWID_128         (0x00000004u)
#define CSL_EDMA3CC_OPT_FWID_256         (0x00000005u)

#define CSL_EDMA3CC_OPT_STATIC_MASK      (0x00000008u)
#define CSL_EDMA3CC_OPT_STATIC_SHIFT     (0x00000003u)
#define CSL_EDMA3CC_OPT_STATIC_RESETVAL  (0x00000000u)

/*----STATIC Tokens----*/
#define CSL_EDMA3CC_OPT_STATIC_NORMAL    (0x00000000u)
#define CSL_EDMA3CC_OPT_STATIC_STATIC    (0x00000001u)

#define CSL_EDMA3CC_OPT_SYNCDIM_MASK     (0x00000004u)
#define CSL_EDMA3CC_OPT_SYNCDIM_SHIFT    (0x00000002u)
#define CSL_EDMA3CC_OPT_SYNCDIM_RESETVAL (0x00000000u)

/*----SYNCDIM Tokens----*/
#define CSL_EDMA3CC_OPT_SYNCDIM_ASYNC    (0x00000000u)
#define CSL_EDMA3CC_OPT_SYNCDIM_ABSYNC   (0x00000001u)

#define CSL_EDMA3CC_OPT_DAM_MASK         (0x00000002u)
#define CSL_EDMA3CC_OPT_DAM_SHIFT        (0x00000001u)
#define CSL_EDMA3CC_OPT_DAM_RESETVAL     (0x00000000u)

/*----DAM Tokens----*/
#define CSL_EDMA3CC_OPT_DAM_INCR         (0x00000000u)
#define CSL_EDMA3CC_OPT_DAM_CONST         (0x00000001u)

#define CSL_EDMA3CC_OPT_SAM_MASK         (0x00000001u)
#define CSL_EDMA3CC_OPT_SAM_SHIFT        (0x00000000u)
#define CSL_EDMA3CC_OPT_SAM_RESETVAL     (0x00000000u)

/*----SAM Tokens----*/
#define CSL_EDMA3CC_OPT_SAM_INCR         (0x00000000u)
#define CSL_EDMA3CC_OPT_SAM_CONST         (0x00000001u)

#define CSL_EDMA3CC_OPT_RESETVAL         (0x00000000u)

/* SRC */

#define CSL_EDMA3CC_SRC_SRC_MASK         (0xFFFFFFFFu)
#define CSL_EDMA3CC_SRC_SRC_SHIFT        (0x00000000u)
#define CSL_EDMA3CC_SRC_SRC_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_SRC_RESETVAL         (0x00000000u)

/* A_B_CNT */

#define CSL_EDMA3CC_A_B_CNT_BCNT_MASK    (0xFFFF0000u)
#define CSL_EDMA3CC_A_B_CNT_BCNT_SHIFT   (0x00000010u)
#define CSL_EDMA3CC_A_B_CNT_BCNT_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_A_B_CNT_ACNT_MASK    (0x0000FFFFu)
#define CSL_EDMA3CC_A_B_CNT_ACNT_SHIFT   (0x00000000u)
#define CSL_EDMA3CC_A_B_CNT_ACNT_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_A_B_CNT_RESETVAL     (0x00000000u)

/* DST */

#define CSL_EDMA3CC_DST_DST_MASK         (0xFFFFFFFFu)
#define CSL_EDMA3CC_DST_DST_SHIFT        (0x00000000u)
#define CSL_EDMA3CC_DST_DST_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_DST_RESETVAL         (0x00000000u)

/* SRC_DST_BIDX */

#define CSL_EDMA3CC_SRC_DST_BIDX_DSTBIDX_MASK (0xFFFF0000u)
#define CSL_EDMA3CC_SRC_DST_BIDX_DSTBIDX_SHIFT (0x00000010u)
#define CSL_EDMA3CC_SRC_DST_BIDX_DSTBIDX_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_SRC_DST_BIDX_SRCBIDX_MASK (0x0000FFFFu)
#define CSL_EDMA3CC_SRC_DST_BIDX_SRCBIDX_SHIFT (0x00000000u)
#define CSL_EDMA3CC_SRC_DST_BIDX_SRCBIDX_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_SRC_DST_BIDX_RESETVAL (0x00000000u)

/* LINK_BCNTRLD */

#define CSL_EDMA3CC_LINK_BCNTRLD_BCNTRLD_MASK (0xFFFF0000u)
#define CSL_EDMA3CC_LINK_BCNTRLD_BCNTRLD_SHIFT (0x00000010u)
#define CSL_EDMA3CC_LINK_BCNTRLD_BCNTRLD_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_LINK_BCNTRLD_LINK_MASK (0x0000FFFFu)
#define CSL_EDMA3CC_LINK_BCNTRLD_LINK_SHIFT (0x00000000u)
#define CSL_EDMA3CC_LINK_BCNTRLD_LINK_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_LINK_BCNTRLD_RESETVAL (0x00000000u)

/* SRC_DST_CIDX */

#define CSL_EDMA3CC_SRC_DST_CIDX_DSTCIDX_MASK (0xFFFF0000u)
#define CSL_EDMA3CC_SRC_DST_CIDX_DSTCIDX_SHIFT (0x00000010u)
#define CSL_EDMA3CC_SRC_DST_CIDX_DSTCIDX_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_SRC_DST_CIDX_SRCCIDX_MASK (0x0000FFFFu)
#define CSL_EDMA3CC_SRC_DST_CIDX_SRCCIDX_SHIFT (0x00000000u)
#define CSL_EDMA3CC_SRC_DST_CIDX_SRCCIDX_RESETVAL (0x00000000u)

#define CSL_EDMA3CC_SRC_DST_CIDX_RESETVAL (0x00000000u)

/* CCNT */

#define CSL_EDMA3CC_CCNT_CCNT_MASK       (0x0000FFFFu)
#define CSL_EDMA3CC_CCNT_CCNT_SHIFT      (0x00000000u)
#define CSL_EDMA3CC_CCNT_CCNT_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_CCNT_RESETVAL        (0x00000000u)

/* ER */

#define CSL_EDMA3CC_ER_REG_MASK          (0xFFFFFFFFu)
#define CSL_EDMA3CC_ER_REG_SHIFT         (0x00000000u)
#define CSL_EDMA3CC_ER_REG_RESETVAL      (0x00000000u)

#define CSL_EDMA3CC_ER_RESETVAL          (0x00000000u)

/* ERH */

#define CSL_EDMA3CC_ERH_REG_MASK         (0xFFFFFFFFu)
#define CSL_EDMA3CC_ERH_REG_SHIFT        (0x00000000u)
#define CSL_EDMA3CC_ERH_REG_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_ERH_RESETVAL         (0x00000000u)

/* ECR */

#define CSL_EDMA3CC_ECR_REG_MASK         (0xFFFFFFFFu)
#define CSL_EDMA3CC_ECR_REG_SHIFT        (0x00000000u)
#define CSL_EDMA3CC_ECR_REG_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_ECR_RESETVAL         (0x00000000u)

/* ECRH */

#define CSL_EDMA3CC_ECRH_REG_MASK        (0xFFFFFFFFu)
#define CSL_EDMA3CC_ECRH_REG_SHIFT       (0x00000000u)
#define CSL_EDMA3CC_ECRH_REG_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_ECRH_RESETVAL        (0x00000000u)

/* ESR */

#define CSL_EDMA3CC_ESR_REG_MASK         (0xFFFFFFFFu)
#define CSL_EDMA3CC_ESR_REG_SHIFT        (0x00000000u)
#define CSL_EDMA3CC_ESR_REG_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_ESR_RESETVAL         (0x00000000u)

/* ESRH */

#define CSL_EDMA3CC_ESRH_REG_MASK        (0xFFFFFFFFu)
#define CSL_EDMA3CC_ESRH_REG_SHIFT       (0x00000000u)
#define CSL_EDMA3CC_ESRH_REG_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_ESRH_RESETVAL        (0x00000000u)

/* CER */

#define CSL_EDMA3CC_CER_REG_MASK         (0xFFFFFFFFu)
#define CSL_EDMA3CC_CER_REG_SHIFT        (0x00000000u)
#define CSL_EDMA3CC_CER_REG_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_CER_RESETVAL         (0x00000000u)

/* CERH */

#define CSL_EDMA3CC_CERH_REG_MASK        (0xFFFFFFFFu)
#define CSL_EDMA3CC_CERH_REG_SHIFT       (0x00000000u)
#define CSL_EDMA3CC_CERH_REG_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_CERH_RESETVAL        (0x00000000u)

/* EER */

#define CSL_EDMA3CC_EER_REG_MASK         (0xFFFFFFFFu)
#define CSL_EDMA3CC_EER_REG_SHIFT        (0x00000000u)
#define CSL_EDMA3CC_EER_REG_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_EER_RESETVAL         (0x00000000u)

/* EERH */

#define CSL_EDMA3CC_EERH_REG_MASK        (0xFFFFFFFFu)
#define CSL_EDMA3CC_EERH_REG_SHIFT       (0x00000000u)
#define CSL_EDMA3CC_EERH_REG_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EERH_RESETVAL        (0x00000000u)

/* EECR */

#define CSL_EDMA3CC_EECR_REG_MASK        (0xFFFFFFFFu)
#define CSL_EDMA3CC_EECR_REG_SHIFT       (0x00000000u)
#define CSL_EDMA3CC_EECR_REG_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EECR_RESETVAL        (0x00000000u)

/* EECRH */

#define CSL_EDMA3CC_EECRH_REG_MASK       (0xFFFFFFFFu)
#define CSL_EDMA3CC_EECRH_REG_SHIFT      (0x00000000u)
#define CSL_EDMA3CC_EECRH_REG_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_EECRH_RESETVAL       (0x00000000u)

/* EESR */

#define CSL_EDMA3CC_EESR_REG_MASK        (0xFFFFFFFFu)
#define CSL_EDMA3CC_EESR_REG_SHIFT       (0x00000000u)
#define CSL_EDMA3CC_EESR_REG_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_EESR_RESETVAL        (0x00000000u)

/* EESRH */

#define CSL_EDMA3CC_EESRH_REG_MASK       (0xFFFFFFFFu)
#define CSL_EDMA3CC_EESRH_REG_SHIFT      (0x00000000u)
#define CSL_EDMA3CC_EESRH_REG_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_EESRH_RESETVAL       (0x00000000u)

/* SER */

#define CSL_EDMA3CC_SER_REG_MASK         (0xFFFFFFFFu)
#define CSL_EDMA3CC_SER_REG_SHIFT        (0x00000000u)
#define CSL_EDMA3CC_SER_REG_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_SER_RESETVAL         (0x00000000u)

/* SERH */

#define CSL_EDMA3CC_SERH_REG_MASK        (0xFFFFFFFFu)
#define CSL_EDMA3CC_SERH_REG_SHIFT       (0x00000000u)
#define CSL_EDMA3CC_SERH_REG_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_SERH_RESETVAL        (0x00000000u)

/* SECR */

#define CSL_EDMA3CC_SECR_REG_MASK        (0xFFFFFFFFu)
#define CSL_EDMA3CC_SECR_REG_SHIFT       (0x00000000u)
#define CSL_EDMA3CC_SECR_REG_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_SECR_RESETVAL        (0x00000000u)

/* SECRH */

#define CSL_EDMA3CC_SECRH_REG_MASK       (0xFFFFFFFFu)
#define CSL_EDMA3CC_SECRH_REG_SHIFT      (0x00000000u)
#define CSL_EDMA3CC_SECRH_REG_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_SECRH_RESETVAL       (0x00000000u)

/* IER */

#define CSL_EDMA3CC_IER_REG_MASK         (0xFFFFFFFFu)
#define CSL_EDMA3CC_IER_REG_SHIFT        (0x00000000u)
#define CSL_EDMA3CC_IER_REG_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IER_RESETVAL         (0x00000000u)

/* IERH */

#define CSL_EDMA3CC_IERH_REG_MASK        (0xFFFFFFFFu)
#define CSL_EDMA3CC_IERH_REG_SHIFT       (0x00000000u)
#define CSL_EDMA3CC_IERH_REG_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IERH_RESETVAL        (0x00000000u)

/* IECR */

#define CSL_EDMA3CC_IECR_REG_MASK        (0xFFFFFFFFu)
#define CSL_EDMA3CC_IECR_REG_SHIFT       (0x00000000u)
#define CSL_EDMA3CC_IECR_REG_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IECR_RESETVAL        (0x00000000u)

/* IECRH */

#define CSL_EDMA3CC_IECRH_REG_MASK       (0xFFFFFFFFu)
#define CSL_EDMA3CC_IECRH_REG_SHIFT      (0x00000000u)
#define CSL_EDMA3CC_IECRH_REG_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_IECRH_RESETVAL       (0x00000000u)

/* IESR */

#define CSL_EDMA3CC_IESR_REG_MASK        (0xFFFFFFFFu)
#define CSL_EDMA3CC_IESR_REG_SHIFT       (0x00000000u)
#define CSL_EDMA3CC_IESR_REG_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IESR_RESETVAL        (0x00000000u)

/* IESRH */

#define CSL_EDMA3CC_IESRH_REG_MASK       (0xFFFFFFFFu)
#define CSL_EDMA3CC_IESRH_REG_SHIFT      (0x00000000u)
#define CSL_EDMA3CC_IESRH_REG_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_IESRH_RESETVAL       (0x00000000u)

/* IPR */

#define CSL_EDMA3CC_IPR_REG_MASK         (0xFFFFFFFFu)
#define CSL_EDMA3CC_IPR_REG_SHIFT        (0x00000000u)
#define CSL_EDMA3CC_IPR_REG_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_IPR_RESETVAL         (0x00000000u)

/* IPRH */

#define CSL_EDMA3CC_IPRH_REG_MASK        (0xFFFFFFFFu)
#define CSL_EDMA3CC_IPRH_REG_SHIFT       (0x00000000u)
#define CSL_EDMA3CC_IPRH_REG_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_IPRH_RESETVAL        (0x00000000u)

/* ICR */

#define CSL_EDMA3CC_ICR_REG_MASK         (0xFFFFFFFFu)
#define CSL_EDMA3CC_ICR_REG_SHIFT        (0x00000000u)
#define CSL_EDMA3CC_ICR_REG_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_ICR_RESETVAL         (0x00000000u)

/* ICRH */

#define CSL_EDMA3CC_ICRH_REG_MASK        (0xFFFFFFFFu)
#define CSL_EDMA3CC_ICRH_REG_SHIFT       (0x00000000u)
#define CSL_EDMA3CC_ICRH_REG_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_ICRH_RESETVAL        (0x00000000u)

/* IEVAL */

#define CSL_EDMA3CC_IEVAL_EVAL_MASK      (0x00000001u)
#define CSL_EDMA3CC_IEVAL_EVAL_SHIFT     (0x00000000u)
#define CSL_EDMA3CC_IEVAL_EVAL_RESETVAL  (0x00000000u)

/*----EVAL Tokens----*/
#define CSL_EDMA3CC_IEVAL_EVAL_EVAL      (0x00000001u)

#define CSL_EDMA3CC_IEVAL_RESETVAL       (0x00000000u)

/* QER */

#define CSL_EDMA3CC_QER_REG_MASK         (0xFFFFFFFFu)
#define CSL_EDMA3CC_QER_REG_SHIFT        (0x00000000u)
#define CSL_EDMA3CC_QER_REG_RESETVAL     (0x00000000u)

#define CSL_EDMA3CC_QER_RESETVAL         (0x00000000u)

/* QEER */

#define CSL_EDMA3CC_QEER_REG_MASK        (0xFFFFFFFFu)
#define CSL_EDMA3CC_QEER_REG_SHIFT       (0x00000000u)
#define CSL_EDMA3CC_QEER_REG_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_QEER_RESETVAL        (0x00000000u)

/* QEECR */

#define CSL_EDMA3CC_QEECR_REG_MASK       (0xFFFFFFFFu)
#define CSL_EDMA3CC_QEECR_REG_SHIFT      (0x00000000u)
#define CSL_EDMA3CC_QEECR_REG_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_QEECR_RESETVAL       (0x00000000u)

/* QEESR */

#define CSL_EDMA3CC_QEESR_REG_MASK       (0xFFFFFFFFu)
#define CSL_EDMA3CC_QEESR_REG_SHIFT      (0x00000000u)
#define CSL_EDMA3CC_QEESR_REG_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_QEESR_RESETVAL       (0x00000000u)

/* QSER */

#define CSL_EDMA3CC_QSER_REG_MASK        (0xFFFFFFFFu)
#define CSL_EDMA3CC_QSER_REG_SHIFT       (0x00000000u)
#define CSL_EDMA3CC_QSER_REG_RESETVAL    (0x00000000u)

#define CSL_EDMA3CC_QSER_RESETVAL        (0x00000000u)

/* QSECR */

#define CSL_EDMA3CC_QSECR_REG_MASK       (0xFFFFFFFFu)
#define CSL_EDMA3CC_QSECR_REG_SHIFT      (0x00000000u)
#define CSL_EDMA3CC_QSECR_REG_RESETVAL   (0x00000000u)

#define CSL_EDMA3CC_QSECR_RESETVAL       (0x00000000u)


//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------





/**************************************************************************\
* Peripheral Instance count
\**************************************************************************/

/** @brief Number of EDMA3 CC instances */
#define CSL_EDMA3_CC_CNT                1

/** @brief Number of EDMA3 TC instances */
#define CSL_EDMA3_TC_CNT                6

/**************************************************************************\
* Peripheral Instance definitions.
\**************************************************************************/

/** @brief Peripheral Instance of EDMA instances */
#define CSL_EDMA3                       (0)

/**************************************************************************\
* Peripheral Base Address
\**************************************************************************/

/** @brief Base address of Channel controller  memory mapped registers */
#define CSL_EDMA3CC_0_REGS              (0x02A00000u)

/** @brief Base address of Transfer controller  memory mapped registers */
#define CSL_EDMA3TC_0_REGS               (0x02A20000u)
#define CSL_EDMA3TC_1_REGS               (0x02A28000u)
#define CSL_EDMA3TC_2_REGS               (0x02A30000u)
#define CSL_EDMA3TC_3_REGS               (0x02A38000u)
#define CSL_EDMA3TC_4_REGS               (0x02A40000u)
#define CSL_EDMA3TC_5_REGS               (0x02A48000u)

/*****************************************************************************\
* Interrupt Event IDs
\*****************************************************************************/

/* EDMA3 channel global completion interrupt */
#define    CSL_INTC_EVENTID_EDMA3CC_GINT    (24)





/**** EDMA RELATED DEFINES  *********/


/**************************************************************************\
*  Parameterizable Configuration:- These are fed directly from the RTL
*  parameters for the given SOC
\**************************************************************************/

#define CSL_EDMA3_NUM_DMACH            64
#define CSL_EDMA3_NUM_QDMACH            8
#define CSL_EDMA3_NUM_PARAMSETS       256
#define CSL_EDMA3_NUM_EVQUE             6
#define CSL_EDMA3_CHMAPEXIST            1
#define CSL_EDMA3_NUM_REGIONS           8
#define CSL_EDMA3_MEMPROTECT            1

/**************************************************************************\
* Channel Instance count
\**************************************************************************/
#define CSL_EDMA3_CHA_CNT              68

/* EDMA channel synchronization events */

/* HPI/PCI-to-DSP event          */
#define CSL_EDMA3_CHA_DSPINT    0
/* Timer 0 lower counter event   */
#define CSL_EDMA3_CHA_TEVTLO0   1
/* Timer 0 higher counter event  */
#define CSL_EDMA3_CHA_TEVTHI0   2

/* EDMA3 channel 3 */
#define CSL_EDMA3_CHA_3         3
/* EDMA3 channel 4 */
#define CSL_EDMA3_CHA_4         4
/* EDMA3 channel 5 */
#define CSL_EDMA3_CHA_5         5
/* EDMA3 channel 6 */
#define CSL_EDMA3_CHA_6         6
/* EDMA3 channel 7 */
#define CSL_EDMA3_CHA_7         7
/* EDMA3 channel 8 */
#define CSL_EDMA3_CHA_8         8
/* TETB is half full */
#define CSL_EDMA3_TETBHFULLINT  9
/* TETB is full */
#define CSL_EDMA3_TETBFULLINT  10
/* Acquisition has been completed on the TETB */
#define CSL_EDMA3_TETBACQINT   11

/* McBSP0 transmit event */
#define CSL_EDMA3_CHA_XEVT0    12
/* McBSP0 receive event  */
#define CSL_EDMA3_CHA_REVT0    13
/* McBSP1 transmit event */
#define CSL_EDMA3_CHA_XEVT1    14
/* McBSP1 receive event  */
#define CSL_EDMA3_CHA_REVT1    15
/* Timer 1 lower counter event  */
#define CSL_EDMA3_CHA_TEVTLO1   16
/* Timer 1 higher counter event */
#define CSL_EDMA3_CHA_TEVTHI1   17

/* Unused - EDMA channel 18*/
#define CSL_EDMA3_CHA_18        18

/* Rapid IO Interrupt 0 */
#define CSL_EDMA3_INTDST0       19
/* Rapid IO Interrupt 1 */
#define CSL_EDMA3_INTDST1       20
/* Rapid IO Interrupt 2 */
#define CSL_EDMA3_INTDST2       21
/* Rapid IO Interrupt 3 */
#define CSL_EDMA3_INTDST3       22
/* Rapid IO Interrupt 4 */
#define CSL_EDMA3_INTDST4       23
/* Rapid IO Interrupt 5 */
#define CSL_EDMA3_INTDST5       24
/* Rapid IO Interrupt 6 */
#define CSL_EDMA3_INTDST6       25

/* Unused - EDMA3 channel 26*/
#define CSL_EDMA3_CHA_26       26
/* Unused - EDMA3 channel 27*/
#define CSL_EDMA3_CHA_27       27

/* VCP2 receive event  */
#define CSL_EDMA3_CHA_VCP2REVT   28
/* VCP2 transmit event */
#define CSL_EDMA3_CHA_VCP2XEVT   29

/* TCP2 receive event  */
#define CSL_EDMA3_CHA_TCP2REVT   30
#define CSL_EDMA3_CHA_TCP2REVT0  30
/* TCP2 transmit event */
#define CSL_EDMA3_CHA_TCP2XEVT   31
#define CSL_EDMA3_CHA_TCP2XEVT0  31
/* UTOPIA receive event */
#define CSL_EDMA3_CHA_UREVT      32
/* EDMA3 channel 33 */
#define CSL_EDMA3_CHA_TCP2REVT1       33
/* EDMA3 channel 34 */
#define CSL_EDMA3_CHA_TCP2XEVT1       34

/* Unused - EDMA3 channel 35 */
#define CSL_EDMA3_CHA_35              35
/* Unused - EDMA3 channel 36 */
#define CSL_EDMA3_CHA_36              36
/* Unused - EDMA3 channel 37 */
#define CSL_EDMA3_CHA_37              37
/* Unused - EDMA3 channel 38 */
#define CSL_EDMA3_CHA_38              38
/* Unused - EDMA3 channel 39 */
#define CSL_EDMA3_CHA_39              39

/* UTOPIA transmit event */
#define CSL_EDMA3_CHA_UXEVT           40

/* Unused - EDMA3 channel 41*/
#define CSL_EDMA3_CHA_41              41
/* Unused - EDMA3 channel 42*/
#define CSL_EDMA3_CHA_42              42
/* Unused - EDMA3 channel 43*/
#define CSL_EDMA3_CHA_43              43

/* I2C receive event */
#define CSL_EDMA3_CHA_ICREVT          44
/* I2C transmit event */
#define CSL_EDMA3_CHA_ICXEVT          45

/** Unused - EDMA3 channel 46*/
#define CSL_EDMA3_CHA_46              46
/** Unused - EDMA3 channel 47*/
#define CSL_EDMA3_CHA_47              47

/* GPIO event 0 */
#define CSL_EDMA3_CHA_GPINT0          48
/* GPIO event 1 */
#define CSL_EDMA3_CHA_GPINT1          49
/* GPIO event 2 */
#define CSL_EDMA3_CHA_GPINT2          50
/* GPIO event 3 */
#define CSL_EDMA3_CHA_GPINT3          51
/* GPIO event 4 */
#define CSL_EDMA3_CHA_GPINT4          52
/* GPIO event 5 */
#define CSL_EDMA3_CHA_GPINT5          53
/* GPIO event 6 */
#define CSL_EDMA3_CHA_GPINT6          54
/* GPIO event 7 */
#define CSL_EDMA3_CHA_GPINT7          55
/* GPIO event 8 */
#define CSL_EDMA3_CHA_GPINT8          56
/* GPIO event 9 */
#define CSL_EDMA3_CHA_GPINT9          57
/* GPIO event 10 */
#define CSL_EDMA3_CHA_GPINT10         58
/* GPIO event 11 */
#define CSL_EDMA3_CHA_GPINT11         59
/* GPIO event 12 */
#define CSL_EDMA3_CHA_GPINT12         60
/* GPIO event 13 */
#define CSL_EDMA3_CHA_GPINT13         61
/* GPIO event 14 */
#define CSL_EDMA3_CHA_GPINT14         62
/* GPIO event 15 */
#define CSL_EDMA3_CHA_GPINT15         63

/* QDMA channels */
#define    CSL_EDMA3_QCHA_0           64   /* QDMA Channel 0*/
#define    CSL_EDMA3_QCHA_1           65   /* QDMA Channel 1*/
#define    CSL_EDMA3_QCHA_2           66   /* QDMA Channel 2*/
#define    CSL_EDMA3_QCHA_3           67   /* QDMA Channel 3*/
#define    CSL_EDMA3_QCHA_4           68   /* QDMA Channel 4*/
#define    CSL_EDMA3_QCHA_5           69   /* QDMA Channel 5*/
#define    CSL_EDMA3_QCHA_6           70   /* QDMA Channel 6*/
#define    CSL_EDMA3_QCHA_7           71   /* QDMA Channel 7*/


/* Enumerations for EDMA Event Queues */
typedef enum {
	CSL_EDMA3_QUE_0 = 0, /* Queue 0 */
	CSL_EDMA3_QUE_1 = 1, /* Queue 1 */
	CSL_EDMA3_QUE_2 = 2, /* Queue 2 */
	CSL_EDMA3_QUE_3 = 3,  /* Queue 3 */
	CSL_EDMA3_QUE_4 = 4,  /* Queue 4 */
	CSL_EDMA3_QUE_5 = 5  /* Queue 5 */
} CSL_Edma3Que;

/* Enumerations for EDMA Transfer Controllers
 *
 * There are 6 Transfer Controllers. Typically a one to one mapping exists
 * between Event Queues and Transfer Controllers.
 *
 */
typedef enum {
	CSL_EDMA3_TC_0 = 0, /* TC 0 */
	CSL_EDMA3_TC_1 = 1, /* TC 1 */
	CSL_EDMA3_TC_2 = 2, /* TC 2 */
	CSL_EDMA3_TC_3 = 3,  /* TC 3 */
	CSL_EDMA3_TC_4 = 4,  /* TC 4 */
	CSL_EDMA3_TC_5 = 5  /* TC 5 */
} CSL_Edma3Tc;

#define CSL_EDMA3_REGION_GLOBAL  -1
#define CSL_EDMA3_REGION_0  0
#define CSL_EDMA3_REGION_1  1
#define CSL_EDMA3_REGION_2  2
#define CSL_EDMA3_REGION_3  3
#define CSL_EDMA3_REGION_4  4
#define CSL_EDMA3_REGION_5  5
#define CSL_EDMA3_REGION_6  6
#define CSL_EDMA3_REGION_7  7



/*********** DAT RELATED DEFINES ******************/

/**************************************************************************\
*  Parameterizable Configuration:- These are fed directly from the RTL
*  parameters for the given SOC
\**************************************************************************/
/**************************************************************************\
* Channel Instance count
\**************************************************************************/
/** @brief Number of Generic Channel instances */


/** @brief Enumerations for EDMA channels
*
*  There are 8 QDMA channels -
*
*/
#define CSL_DAT_QCHA_0		   	0 /**< QDMA Channel 0*/
#define CSL_DAT_QCHA_1		   	1 /**< QDMA Channel 1*/
#define CSL_DAT_QCHA_2    	   	2 /**< QDMA Channel 2*/
#define CSL_DAT_QCHA_3		   	3 /**< QDMA Channel 3*/
#define CSL_DAT_QCHA_4		   	4 /**< QDMA Channel 4*/
#define CSL_DAT_QCHA_5		   	5 /**< QDMA Channel 5*/
#define CSL_DAT_QCHA_6    	   	6 /**< QDMA Channel 6*/
#define CSL_DAT_QCHA_7		   	7 /**< QDMA Channel 7*/

/** @brief Enumerations for EDMA Event Queues
 *
 *  There are 6 Event Queues. Q0 is the highest priority and Q3 is the least priority
 */
typedef enum {
	CSL_DAT_PRI_DEFAULT = 0, /* Queue 0 is default */
	CSL_DAT_PRI_0 	    = 0, /* Queue 0 */
	CSL_DAT_PRI_1 	    = 1, /* Queue 1 */
	CSL_DAT_PRI_2 	    = 2, /* Queue 2 */
	CSL_DAT_PRI_3 	    = 3,  /* Queue 3 */
	CSL_DAT_PRI_4 	    = 4, /* Queue 4 */
	CSL_DAT_PRI_5 	    = 5  /* Queue 5 */
} CSL_DatPriority;

/** @brief Enumeration for EDMA Regions */
#define	CSL_DAT_REGION_GLOBAL  -1  /* Global Region */
#define	CSL_DAT_REGION_0  0         /* EDMA Region 0 */
#define	CSL_DAT_REGION_1  1         /* EDMA Region 1 */
#define	CSL_DAT_REGION_2  2         /* EDMA Region 2 */
#define	CSL_DAT_REGION_3  3         /* EDMA Region 3 */
#define	CSL_DAT_REGION_4  4         /* EDMA Region 4 */
#define	CSL_DAT_REGION_5  5         /* EDMA Region 5 */
#define	CSL_DAT_REGION_6  6         /* EDMA Region 6 */
#define	CSL_DAT_REGION_7  7         /* EDMA Region 7 */


//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------


/* EDMA Symbols Defined */

/** Link to a Null Param set */
#define CSL_EDMA3_LINK_NULL                     0xFFFF 
/** Link to a Null Param set */
#define CSL_EDMA3_LINK_DEFAULT                  0xFFFF
/** A synchronized transfer  */
#define CSL_EDMA3_SYNC_A                        0
/** AB synchronized transfer */
#define CSL_EDMA3_SYNC_AB                       1
/** Normal Completion */
#define CSL_EDMA3_TCC_NORMAL                    0
/** Early  Completion */
#define CSL_EDMA3_TCC_EARLY                     1
/** Only for ease  */
#define CSL_EDMA3_FIFOWIDTH_NONE                0
/** 8 bit FIFO Width */
#define CSL_EDMA3_FIFOWIDTH_8BIT                0    
/** 16 bit FIFO Width */
#define CSL_EDMA3_FIFOWIDTH_16BIT               1    
/** 32 bit FIFO Width */
#define CSL_EDMA3_FIFOWIDTH_32BIT               2    
/** 64 bit FIFO Width */
#define CSL_EDMA3_FIFOWIDTH_64BIT               3    
/** 128 bit FIFO Width */
#define CSL_EDMA3_FIFOWIDTH_128BIT              4   
/** 256 bit FIFO Width */
#define CSL_EDMA3_FIFOWIDTH_256BIT              5    
/** Address Mode is incremental */
#define CSL_EDMA3_ADDRMODE_INCR                 0
/** Address Mode is such it wraps around after reaching FIFO width */
#define CSL_EDMA3_ADDRMODE_CONST                1



/* Bitwise OR of the below symbols are used for setting the Memory attributes 
   These are defined only if the Memory Protection feature exists */
#if CSL_EDMA3_MEMPROTECT
/** User Execute permission */
#define CSL_EDMA3_MEMACCESS_UX              0x0001  
/** User Write permission */  
#define CSL_EDMA3_MEMACCESS_UW              0x0002  
/** User Read permission */
#define CSL_EDMA3_MEMACCESS_UR              0x0004  
/** Supervisor Execute permission */  
#define CSL_EDMA3_MEMACCESS_SX              0x0008  
/** Supervisor Write permission */
#define CSL_EDMA3_MEMACCESS_SW              0x0010  
/** Supervisor Read permission */
#define CSL_EDMA3_MEMACCESS_SR              0x0020  
/** External Allowed ID. Requests with PrivID >= '6' are permitted 
 * if access type is allowed
 */
#define CSL_EDMA3_MEMACCESS_EXT            0x0200 
/** Allowed ID '0' */ 
#define CSL_EDMA3_MEMACCESS_AID0           0x0400  
/** Allowed ID '1' */
#define CSL_EDMA3_MEMACCESS_AID1           0x0800  
/** Allowed ID '2' */
#define CSL_EDMA3_MEMACCESS_AID2           0x1000  
/** Allowed ID '3' */
#define CSL_EDMA3_MEMACCESS_AID3           0x2000  
/** Allowed ID '4' */
#define CSL_EDMA3_MEMACCESS_AID4           0x4000  
/** Allowed ID '5' */
#define CSL_EDMA3_MEMACCESS_AID5           0x8000  
#endif

/** Intermediate transfer completion interrupt enable */  
#define CSL_EDMA3_ITCINT_EN             1
/** Intermediate transfer completion interrupt disable */ 
#define CSL_EDMA3_ITCINT_DIS            0
/** Intermediate transfer completion chaining enable */ 
#define CSL_EDMA3_ITCCH_EN              1
/** Intermediate transfer completion chaining disable */    
#define CSL_EDMA3_ITCCH_DIS             0
/** Transfer completion interrupt enable */  
#define CSL_EDMA3_TCINT_EN              1
/** Transfer completion interrupt disable */ 
#define CSL_EDMA3_TCINT_DIS             0
/** Transfer completion chaining enable */   
#define CSL_EDMA3_TCCH_EN               1
/** Transfer completion chaining disable */
#define CSL_EDMA3_TCCH_DIS              0
/** Enable Static */
#define CSL_EDMA3_STATIC_EN             1
/** Disable Static */
#define CSL_EDMA3_STATIC_DIS            0
/** Last trigger word in a QDMA parameter set */
#define CSL_EDMA3_TRIGWORD_DEFAULT        7
/** Trigger word option field */
#define CSL_EDMA3_TRIGWORD_OPT            0
/** Trigger word source  */
#define CSL_EDMA3_TRIGWORD_SRC            1
/** Trigger word AB count */
#define CSL_EDMA3_TRIGWORD_A_B_CNT        2
/** Trigger word destination */
#define CSL_EDMA3_TRIGWORD_DST            3
/** Trigger word src and dst B index */
#define CSL_EDMA3_TRIGWORD_SRC_DST_BIDX   4
/** Trigger word B count reload */
#define CSL_EDMA3_TRIGWORD_LINK_BCNTRLD   5
/** Trigger word src and dst C index */
#define CSL_EDMA3_TRIGWORD_SRC_DST_CIDX   6
/** Trigger word C count */
#define CSL_EDMA3_TRIGWORD_CCNT           7


   
    

/** Used for creating the options entry in the parameter ram */
#define CSL_EDMA3_OPT_MAKE(itcchEn, tcchEn, itcintEn, tcintEn, tcc, tccMode, \
                           fwid, stat, syncDim, dam, sam) \
(uint32)(\
     CSL_FMKR(23,23,itcchEn) \
    |CSL_FMKR(22,22,tcchEn) \
    |CSL_FMKR(21,21,itcintEn) \
    |CSL_FMKR(20,20,tcintEn) \
    |CSL_FMKR(17,12,tcc) \
    |CSL_FMKR(11,11,tccMode) \
    |CSL_FMKR(10,8,fwid) \
    |CSL_FMKR(3,3,stat) \
    |CSL_FMKR(2,2,syncDim) \
    |CSL_FMKR(1,1,dam) \
    |CSL_FMKR(0,0,sam)) 
    
/** Used for creating the A,B Count entry in the parameter ram */
#define CSL_EDMA3_CNT_MAKE(aCnt,bCnt) \
(uint32)(\
     CSL_FMK(EDMA3CC_A_B_CNT_ACNT,aCnt) \
    |CSL_FMK(EDMA3CC_A_B_CNT_BCNT,bCnt)\
    )

/** Used for creating the link and B count reload entry in the parameter ram */
#define CSL_EDMA3_LINKBCNTRLD_MAKE(link,bCntRld) \
(uint32)(\
     CSL_FMK(EDMA3CC_LINK_BCNTRLD_LINK,(uint32)link) \
    |CSL_FMK(EDMA3CC_LINK_BCNTRLD_BCNTRLD,bCntRld)\
    )

/** Used for creating the B index entry in the parameter ram */
#define CSL_EDMA3_BIDX_MAKE(src,dst) \
(uint32)(\
     CSL_FMK(EDMA3CC_SRC_DST_BIDX_DSTBIDX,(uint32)dst) \
    |CSL_FMK(EDMA3CC_SRC_DST_BIDX_SRCBIDX,(uint32)src)\
    )

/** Used for creating the C index entry in the parameter ram */
#define CSL_EDMA3_CIDX_MAKE(src,dst) \
(uint32)(\
     CSL_FMK(EDMA3CC_SRC_DST_CIDX_DSTCIDX,(uint32)dst) \
    |CSL_FMK(EDMA3CC_SRC_DST_CIDX_SRCCIDX,(uint32)src)\
    )

/** DMA Channel Setup  */
#define CSL_EDMA3_DMACHANNELSETUP_DEFAULT   {       \
   {CSL_EDMA3_QUE_0,0}, \
   {CSL_EDMA3_QUE_0,1}, \
   {CSL_EDMA3_QUE_0,2}, \
   {CSL_EDMA3_QUE_0,3}, \
   {CSL_EDMA3_QUE_0,4}, \
   {CSL_EDMA3_QUE_0,5}, \
   {CSL_EDMA3_QUE_0,6}, \
   {CSL_EDMA3_QUE_0,7}, \
   {CSL_EDMA3_QUE_0,8}, \
   {CSL_EDMA3_QUE_0,9}, \
   {CSL_EDMA3_QUE_0,10}, \
   {CSL_EDMA3_QUE_0,11}, \
   {CSL_EDMA3_QUE_0,12}, \
   {CSL_EDMA3_QUE_0,13}, \
   {CSL_EDMA3_QUE_0,14}, \
   {CSL_EDMA3_QUE_0,15}, \
   {CSL_EDMA3_QUE_0,16}, \
   {CSL_EDMA3_QUE_0,17}, \
   {CSL_EDMA3_QUE_0,18}, \
   {CSL_EDMA3_QUE_0,19}, \
   {CSL_EDMA3_QUE_0,20}, \
   {CSL_EDMA3_QUE_0,21}, \
   {CSL_EDMA3_QUE_0,22}, \
   {CSL_EDMA3_QUE_0,23}, \
   {CSL_EDMA3_QUE_0,24}, \
   {CSL_EDMA3_QUE_0,25}, \
   {CSL_EDMA3_QUE_0,26}, \
   {CSL_EDMA3_QUE_0,27}, \
   {CSL_EDMA3_QUE_0,28}, \
   {CSL_EDMA3_QUE_0,29}, \
   {CSL_EDMA3_QUE_0,30}, \
   {CSL_EDMA3_QUE_0,31}, \
   {CSL_EDMA3_QUE_0,32}, \
   {CSL_EDMA3_QUE_0,33}, \
   {CSL_EDMA3_QUE_0,34}, \
   {CSL_EDMA3_QUE_0,35}, \
   {CSL_EDMA3_QUE_0,36}, \
   {CSL_EDMA3_QUE_0,37}, \
   {CSL_EDMA3_QUE_0,38}, \
   {CSL_EDMA3_QUE_0,39}, \
   {CSL_EDMA3_QUE_0,40}, \
   {CSL_EDMA3_QUE_0,41}, \
   {CSL_EDMA3_QUE_0,42}, \
   {CSL_EDMA3_QUE_0,43}, \
   {CSL_EDMA3_QUE_0,44}, \
   {CSL_EDMA3_QUE_0,45}, \
   {CSL_EDMA3_QUE_0,46}, \
   {CSL_EDMA3_QUE_0,47}, \
   {CSL_EDMA3_QUE_0,48}, \
   {CSL_EDMA3_QUE_0,49}, \
   {CSL_EDMA3_QUE_0,50}, \
   {CSL_EDMA3_QUE_0,51}, \
   {CSL_EDMA3_QUE_0,52}, \
   {CSL_EDMA3_QUE_0,53}, \
   {CSL_EDMA3_QUE_0,54}, \
   {CSL_EDMA3_QUE_0,55}, \
   {CSL_EDMA3_QUE_0,56}, \
   {CSL_EDMA3_QUE_0,57}, \
   {CSL_EDMA3_QUE_0,58}, \
   {CSL_EDMA3_QUE_0,59}, \
   {CSL_EDMA3_QUE_0,60}, \
   {CSL_EDMA3_QUE_0,61}, \
   {CSL_EDMA3_QUE_0,62}, \
   {CSL_EDMA3_QUE_0,63} \
}

/** QDMA Channel Setup  */
#define CSL_EDMA3_QDMACHANNELSETUP_DEFAULT   {       \
   {CSL_EDMA3_QUE_0,64,CSL_EDMA3_TRIGWORD_DEFAULT}, \
   {CSL_EDMA3_QUE_0,65,CSL_EDMA3_TRIGWORD_DEFAULT}, \
   {CSL_EDMA3_QUE_0,66,CSL_EDMA3_TRIGWORD_DEFAULT}, \
   {CSL_EDMA3_QUE_0,67,CSL_EDMA3_TRIGWORD_DEFAULT}, \
   {CSL_EDMA3_QUE_0,68,CSL_EDMA3_TRIGWORD_DEFAULT}, \
   {CSL_EDMA3_QUE_0,69,CSL_EDMA3_TRIGWORD_DEFAULT}, \
   {CSL_EDMA3_QUE_0,70,CSL_EDMA3_TRIGWORD_DEFAULT}, \
   {CSL_EDMA3_QUE_0,71,CSL_EDMA3_TRIGWORD_DEFAULT}  \
}


/** @addtogroup CSL_EDMA3_ENUM
 @{ */
/** @brief Enumeration for System priorities
 *
 * This is used for Setting up the Que Priority level
 */
typedef enum {
    /** System priority level 0 */
    CSL_EDMA3_QUE_PRI_0 = 0,
    /** System priority level 1 */
    CSL_EDMA3_QUE_PRI_1 = 1,
    /** System priority level 2 */         
    CSL_EDMA3_QUE_PRI_2 = 2,
    /** System priority level 3 */
    CSL_EDMA3_QUE_PRI_3 = 3,
    /** System priority level 4 */     
    CSL_EDMA3_QUE_PRI_4 = 4,   
    /** System priority level 5 */
    CSL_EDMA3_QUE_PRI_5 = 5,   
    /** System priority level 6 */
    CSL_EDMA3_QUE_PRI_6 = 6,   
    /** System priority level 7 */
    CSL_EDMA3_QUE_PRI_7 = 7    
}CSL_Edma3QuePri;

/** @brief Enumeration for EDMA Que Thresholds
 *
 * This is used for Setting up the Que thresholds
 */
typedef enum {
    /** EDMA Que Threshold 0 */
    CSL_EDMA3_QUE_THR_0 = 0,
    /** EDMA Que Threshold 1 */        
    CSL_EDMA3_QUE_THR_1 = 1,
    /** EDMA Que Threshold 2 */        
    CSL_EDMA3_QUE_THR_2 = 2,
    /** EDMA Que Threshold 3 */        
    CSL_EDMA3_QUE_THR_3 = 3, 
    /** EDMA Que Threshold 4 */       
    CSL_EDMA3_QUE_THR_4 = 4,
    /** EDMA Que Threshold 5 */
    CSL_EDMA3_QUE_THR_5 = 5,
    /** EDMA Que Threshold 6 */   
    CSL_EDMA3_QUE_THR_6 = 6, 
    /** EDMA Que Threshold 7 */
    CSL_EDMA3_QUE_THR_7 = 7,
    /** EDMA Que Threshold 8 */
    CSL_EDMA3_QUE_THR_8 = 8,
    /** EDMA Que Threshold 9 */
    CSL_EDMA3_QUE_THR_9 = 9,
    /** EDMA Que Threshold 10 */
    CSL_EDMA3_QUE_THR_10 = 10,
    /** EDMA Que Threshold 11 */
    CSL_EDMA3_QUE_THR_11 = 11,
    /** EDMA Que Threshold 12 */
    CSL_EDMA3_QUE_THR_12 = 12, 
    /** EDMA Que Threshold 13 */
    CSL_EDMA3_QUE_THR_13 = 13,
    /** EDMA Que Threshold 14 */
    CSL_EDMA3_QUE_THR_14 = 14,
    /** EDMA Que Threshold 15 */
    CSL_EDMA3_QUE_THR_15 = 15, 
    /** EDMA Que Threshold 16 */
    CSL_EDMA3_QUE_THR_16 = 16, 
    /* EDMA Que Threshold Disable Errors */
    CSL_EDMA3_QUE_THR_DISABLE = 17  
}CSL_Edma3QueThr;

/** MODULE Level Commands */
typedef enum {
#if CSL_EDMA3_MEMPROTECT
        /**
         * @brief   Programmation of MPPAG,MPPA[0-7] attributes
         *
         * @param   (CSL_Edma3CmdRegion *)
         */
    CSL_EDMA3_CMD_MEMPROTECT_SET,
        /**
         * @brief   Clear Memory Fault
         *
         * @param   (None)
         */
    CSL_EDMA3_CMD_MEMFAULT_CLEAR,
#endif  
        /**
         * @brief   Enables bits as specified in the argument passed in 
         *          DRAE/DRAEH. Please note:If bits are already set in 
         *          DRAE/DRAEH this Control command will cause additional bits
         *          (as specified by the bitmask) to be set and does   
         * @param   (CSL_Edma3CmdDrae *)
         */
    CSL_EDMA3_CMD_DMAREGION_ENABLE,
        /**
         * @brief   Disables bits as specified in the argument passed in 
         *          DRAE/DRAEH   
         * @param   (CSL_Edma3CmdDrae *)
         */     
    CSL_EDMA3_CMD_DMAREGION_DISABLE,
        /**
         * @brief   Enables bits as specified in the argument 
         *          passed in QRAE.Pleasenote:If bits are already set in 
         *          QRAE/QRAEH this Control command will cause additional bits 
         *          (as specified by the bitmask) to be set and does  
         * @param   (CSL_Edma3CmdQrae *)
         */
    CSL_EDMA3_CMD_QDMAREGION_ENABLE,
        /**
         * @brief   Disables bits as specified in the argument passed in QRAE
         *          DRAE/DRAEH   
         * @param   (CSL_Edma3CmdQrae *)
         */    
    CSL_EDMA3_CMD_QDMAREGION_DISABLE,
        /**
         * @brief   Programmation of QUEPRI register with the specified priority
         *          DRAE/DRAEH   
         * @param   (CSL_Edma3CmdQuePri *)
         */ 
    CSL_EDMA3_CMD_QUEPRIORITY_SET,
        /**
         * @brief   Programmation of QUE Threshold levels
         *
         * @param   (CSL_Edma3CmdQueThr *)
         */      
    CSL_EDMA3_CMD_QUETHRESHOLD_SET,
        /**
         * @brief   Sets the EVAL bit in the EEVAL register
         *
         * @param   (None)
         */
    CSL_EDMA3_CMD_ERROR_EVAL,
        /**
         * @brief   Clears specified (Bitmask)pending interrupt at Module/Region
         *          Level
         * @param   (CSL_Edma3CmdIntr *)
         */         
    CSL_EDMA3_CMD_INTRPEND_CLEAR,
        /**
         * @brief   Enables specified interrupts(BitMask) at Module/Region Level
         *          
         * @param   (CSL_Edma3CmdIntr *)
         */  
    CSL_EDMA3_CMD_INTR_ENABLE, 
        /**
         * @brief   Disables specified interrupts(BitMask) at Module/Region 
         *          Level
         * @param   (CSL_Edma3CmdIntr *)
         */
    CSL_EDMA3_CMD_INTR_DISABLE,
        /**
         * @brief   Interrupt Evaluation asserted for the Module/Region
         *
         * @param   (Int *)
         */    
    CSL_EDMA3_CMD_INTR_EVAL, 
        /**
         * @brief   Clear the EDMA Controller Erorr
         *
         * @param   (CSL_Edma3CtrlErrStat *)
         */
    CSL_EDMA3_CMD_CTRLERROR_CLEAR , 
        /**
         * @brief   Pointer to an array of 3 elements, where element0 refers to 
         *          the EMR register to be cleared, element1 refers to the EMRH 
         *          register to be cleared, element2 refers to the QEMR register
         *          to be cleared.
         * @param   (CSL_BitMask32 *)
         */
    CSL_EDMA3_CMD_EVENTMISSED_CLEAR     
} CSL_Edma3HwControlCmd;

/** @brief MODULE Level Queries */
typedef enum {
#if CSL_EDMA3_MEMPROTECT
        /**
         * @brief   Return the Memory fault details
         *
         * @param   (CSL_Edma3MemFaultStat *)
         */    
    CSL_EDMA3_QUERY_MEMFAULT,
        /**
         * @brief   Return memory attribute of the specified region
         *
         * @param   (CSL_Edma3CmdRegion *)
         */             
    CSL_EDMA3_QUERY_MEMPROTECT,           
#endif
        /**
         * @brief   Return Controller Error
         *
         * @param   (CSL_Edma3CtrlErrStat *)
         */ 
    CSL_EDMA3_QUERY_CTRLERROR,
        /**
         * @brief   Return pend status of specified interrupt
         *
         * @param   (CSL_Edma3CmdIntr *)
         */             
    CSL_EDMA3_QUERY_INTRPEND,
        /**
         * @brief   Returns Miss Status of all Channels
         *          Pointer to an array of 3 elements, where element0 refers to 
         *          the EMR  registr, element1 refers to the EMRH register,  
         *          element2 refers to the QEMR register
         * @param   (CSL_BitMask32 *)
         */             
    CSL_EDMA3_QUERY_EVENTMISSED,
        /**
         * @brief   Returns the Que status
         *
         * @param   (CSL_Edma3QueStat *)
         */          
    CSL_EDMA3_QUERY_QUESTATUS,            
        /**
         * @brief   Returns the Channel Controller Active Status 
         *
         * @param   (CSL_Edma3ActivityStat *)
         */
    CSL_EDMA3_QUERY_ACTIVITY, 
        /**
         * @brief   Returns the Channel Controller Information viz. 
         *          Configuration, Revision Id  
         * @param   (CSL_Edma3QueryInfo *)
         */            
    CSL_EDMA3_QUERY_INFO                 
} CSL_Edma3HwStatusQuery;

/** @brief CHANNEL Commands */
typedef enum {
        /**
         * @brief   Enables specified Channel
         *
         * @param   (None)
         */ 
    CSL_EDMA3_CMD_CHANNEL_ENABLE,
        /**
         * @brief   Disables specified Channel
         *
         * @param   (None)
         */
    CSL_EDMA3_CMD_CHANNEL_DISABLE,
        /**
         * @brief   Manually sets the Channel Event,writes into ESR/ESRH 
         *          and not ER.NA for QDMA
         * @param   (None)
         */       
    CSL_EDMA3_CMD_CHANNEL_SET,
        /**
         * @brief   Manually clears the Channel Event, does not write into
         *          ESR/ESRH or ER/ERH but the ECR/ECRH. NA for QDMA
         * @param   (None)
         */            
    CSL_EDMA3_CMD_CHANNEL_CLEAR,
        /**
         * @brief   In case of DMA channels clears SER/SERH(by writing into 
         *          SECR/SECRH if "secEvt" and "missed" are both TRUE) and 
         *          EMR/EMRH(by writing into EMCR/EMCRH if "missed" is TRUE).
         *          In case of QDMA channels clears QSER(by writing into QSECR 
         *          if "ser" and "missed" are both TRUE) and QEMR(by writing 
         *          into QEMCR if "missed" is TRUE)
         * @param   (CSL_Edma3ChannelErr *)
         */ 
    CSL_EDMA3_CMD_CHANNEL_CLEARERR       
} CSL_Edma3HwChannelControlCmd;

/** @brief CHANNEL Queries */  
typedef enum  {
        /**
         * @brief   In case of DMA channels returns TRUE if ER/ERH is set,
         *          In case of QDMA channels returns TRUE if QER is set
         * @param   (Bool *)
         */ 
    CSL_EDMA3_QUERY_CHANNEL_STATUS,
        /**
         * @brief   In case of DMA channels,'missed' is set
         *          to TRUE if EMR/EMRH is set, 'secEvt' is set to TRUE if 
         *          SER/SERH is set.In case of QDMA channels,'missed' is set to 
         *          TRUE if QEMR is set, 'secEvt' is set to TRUE if QSER is set.
         *          It should be noted that if secEvt ONLY is set to TRUE it 
         *          may not be a valid error condition 
         * @param   (CSL_Edma3ChannelErr *)
         */  
    CSL_EDMA3_QUERY_CHANNEL_ERR      
} CSL_Edma3HwChannelStatusQuery;

/**
@}
*/

/** @addtogroup CSL_EDMA3_DATASTRUCT
 @{ */
/** @brief Module specific context information.
 *  This is a dummy handle. 
 */
typedef void *CSL_Edma3Context;      

/** @brief Module Attributes specific information.
 *  This is a dummy handle. 
 */
typedef void *CSL_Edma3ModuleAttr;

/** @brief This object contains the reference to the instance of Edma Module
 * opened using the @a CSL_edma3Open().
 *
 *  A pointer to this object is passed to all Edma Module level CSL APIs.
 */
 
typedef struct CSL_Edma3Obj {
    /** This is a pointer to the Edma Channel Controller registers of the module
     *   requested
     */
    CSL_Edma3ccRegsOvly regs;
    /** This is the instance of module number i.e CSL_EDMA3 */
    int32               instNum;
} CSL_Edma3Obj;

/** @brief EDMA handle */
typedef struct CSL_Edma3Obj *CSL_Edma3Handle;

/** CSL Parameter Set Handle */
typedef volatile CSL_Edma3ccParamsetRegs *CSL_Edma3ParamHandle;

/** @brief Edma ParamSetup Structure
 *
 *  An object of this type is allocated by the user and
 *  its address is passed as a parameter to the CSL_edma3ParamSetup().
 *  This structure is used to program the Param Set for EDMA/QDMA.
 *  The macros can be used to assign values to the fields of the structure.
 *  The setup structure should be setup using the macros provided OR
 *  as per the bit descriptions in the user guide..
 *  
 */
typedef struct CSL_Edma3ParamSetup {
    /** Options */
    uint32          option;
    /** Specifies the source address */               
    uint32          srcAddr;
    /** Lower 16 bits are A Count Upper 16 bits are B Count*/             
    uint32          aCntbCnt;            
    /** Specifies the destination address */                                          
    uint32          dstAddr;
    /** Lower 16 bits are source b index Upper 16 bits are
     * destination b index 
     */             
    uint32          srcDstBidx;          
    /** Lower 16 bits are link of the next param entry Upper 16 bits are 
     * b count reload 
     */
    uint32          linkBcntrld;         
    /** Lower 16 bits are source c index Upper 16 bits are destination 
     * c index 
     */             
    uint32          srcDstCidx;          
    /** C count */                                           
    uint32          cCnt;                
} CSL_Edma3ParamSetup;


/** @brief Edma Object Structure
 *
 *  An object of this type is allocated by the user and
 *  its address is passed as a parameter to the CSL_edma3ChannelOpen()
 *  The CSL_edma3ChannelOpen() updates all the members of the data structure
 *  and returns the objects address as a @a #CSL_Edma3ChannelHandle. The
 *  @a #CSL_Edma3ChannelHandle is used in all subsequent function calls.
 */
 
typedef struct CSL_Edma3ChannelObj {
    /** Pointer to the Edma Channel Controller module register 
     * Overlay structure 
     */
    CSL_Edma3ccRegsOvly      regs;               
    /** Region number to which the channel belongs to */ 
    int32                    region;              
    /** EDMA instance whose channel is being requested */
    int32                    edmaNum;             
    /** Channel Number being requested */
    int32                    chaNum;              
} CSL_Edma3ChannelObj;

/** CSL Channel Handle
 *  All channel level API calls must be made with this handle. 
 */
typedef struct CSL_Edma3ChannelObj *CSL_Edma3ChannelHandle;

#if CSL_EDMA3_MEMPROTECT    
/** @brief Edma Memory Protection Fault Error Status
 *
 *  An object of this type is allocated by the user and
 *  its address is passed as a parameter to the CSL_edma3GetMemoryFaultError()
 *  / CSL_edma3GetHwStatus() with the relevant command. This is relevant only is 
 *  MPEXIST is present for a given device.
 */
typedef struct CSL_Edma3MemFaultStat {
    /** Memory Protection Fault Address */
    uint32      addr;
    /** Bit Mask of the Errors */               
    uint16		error;
    /** Faulted ID */              
    uint16           fid;                
} CSL_Edma3MemFaultStat;
#endif
/** @brief Edma Controller Error Status. 
 *
 *  An object of this type is allocated by the user and
 *  its address is passed as a parameter to the CSL_edma3GetControllerError()
 *  /CSL_edma3GetHwStatus().
 */
typedef struct CSL_Edma3CtrlErrStat {
    /** Bit Mask of the Que Threshold Errors */
    uint16    error;
    /** Whether number of permissible outstanding Tcc's is exceeded */
    bool             exceedTcc;          
                                                  
} CSL_Edma3CtrlErrStat;
/** @brief Edma Controller Information
 *
 *  An object of this type is allocated by the user and
 *  its address is passed as a parameter to the CSL_edma3GetInfo()
 *  /CSL_edma3GetHwStatus().
 */
typedef struct CSL_Edma3QueryInfo{
    /** Revision/Periperhal id of the EDMA3 Channel Controller */
    uint32 revision;
    /** Channel Controller Configuration obtained from the CCCFG register */
    uint32 config;                      
} CSL_Edma3QueryInfo;

/** @brief Edma Channel Controller Activity Status
 *
 *  An object of this type is allocated by the user and
 *  its address is passed as a parameter to the CSL_edma3GetActivityStatus()
 *  /CSL_edma3GetHwStatus().
 */
typedef struct CSL_Edma3ActivityStat {
    /** Number of outstanding completion requests */
    uint16 outstandingTcc;
    /** BitMask of the que active in the Channel Controller */   
    uint16 queActive; 
    /** Indicates if the Channel Controller is active at all */
    bool active; 
    /** Indicates whether any QDMA events are active */
    bool qevtActive;
    /** Indicates whether any EDMA events are active */ 
    bool evtActive;
    /** Indicates whether the TR processing/submission logic is active*/  
    bool trActive;   
} CSL_Edma3ActivityStat;

/** @brief Edma Controller Que Status. 
 *
 *  An object of this type is allocated by the user and
 *  its address is passed as a parameter to the CSL_edma3GetQueStatus()
 *  /CSL_edma3GetHwStatus().
 */
typedef struct CSL_Edma3QueStat {
    /** Input field: Event Que. This needs to be specified by the user 
     *  before invocation of the above API 
     */
    CSL_Edma3Que que;                        
    /** Output field: The number of valid entries in a queue has exceeded the 
     * threshold specified in QWMTHRA has been exceeded 
     */    
    bool             exceed;                 
    /** Output field: The most entries that have been in Que since reset/last 
     * time the watermark was cleared
     */
    uint8            waterMark;              
    /** Output field: Number of valid entries in Que N*/                                                
    uint8            numVal;                 
    /** Output field: Start pointer/Head of the queue */
    uint8            startPtr;               
} CSL_Edma3QueStat;

/** @brief Edma Control/Query Command Structure for querying region specific 
 *  attributes. 
 *
 *  An object of this type is allocated by the user and
 *  its address is passed as a parameter to the 
 *   CSL_edma3GetHwStatus/CSL_edma3HwControl with the relevant command.   
 */
typedef struct CSL_Edma3CmdRegion {
    /** Input field:- this field needs to be initialized by the user before
     * issuing the query/command 
     */
    int32       region;                 
    /** Input/Output field:-this needs to be filled by the user in case 
     * of issuing a COMMAND or it will be filled in by the CSL when
     * used with a QUERY 
     */                                                
    uint32      regionVal;                                                            
} CSL_Edma3CmdRegion;

/** @brief Edma Control/Query Command Structure for querying qdma region access  
 *  enable attributes. 
 *
 *  An object of this type is allocated by the user and
 *  its address is passed as a parameter to the 
 *  CSL_edma3GetHwStatus/CSL_edma3HwControl with the relevant command.   
 */


typedef struct CSL_Edma3CmdQrae {
    /** this field needs to be initialized by the user before issuing 
     * the query/command
     */
    int32		region;             
    /** this needs to be filled by the user in case of issuing a 
     * COMMAND or it will be filled in by the CSL when  used with a QUERY 
     */
    uint32      qrae;               
                                                  
                                                 
} CSL_Edma3CmdQrae;

/** @brief Edma Control/Query Control Command structure for issuing commands 
 *  for Interrupt related APIs
 *  An object of this type is allocated by the user and
 *  its address is passed to the Control API. 
 */
typedef struct CSL_Edma3CmdIntr{
    /** Input field:- this field needs to be initialized by the user before
     * issuing the query/command 
     */
    int32		region;             
    /** Input/Output field:- this needs to be filled by the user in case 
     * of issuing a COMMAND or it will be filled in by the CSL when used with 
     * a QUERY 
     */                
    uint32      intr;               
    /** Input/Output:- this needs to be filled by the user in case of issuing a                                               
     * COMMAND or it will be filled in by the CSL when  used with a QUERY 
     */                                             
    uint32      intrh;              
                                                  
                                                  
} CSL_Edma3CmdIntr;
/** @brief Edma Command Structure for setting region specific 
 *  attributes.
 *
 *  An object of this type is allocated by the user and
 *  its address is passed as a parameter to the CSL_edma3GetHwStatus
 *  when 
 */


typedef struct CSL_Edma3CmdDrae {
    /** this field needs to be initialiazed by the user before issuing 
     * the command specifying the region for which attributes need to be set 
     */
    int32   	region;                
    /** DRAE Setting for the region  */
    uint32     	drae;
    /** DRAEH Setting for the region */
    uint32      draeh;     
} CSL_Edma3CmdDrae;


/** @brief Edma Command Structure used for setting Event Que priority level
 *
 *  An object of this type is allocated by the user and
 *  its address is passed as a parameter to the CSL_edma3HwControl API.
 */


typedef struct CSL_Edma3CmdQuePri {
    /** Specifies the Que that needs a priority change */
    CSL_Edma3Que         que;
    /** Que priority */              
    CSL_Edma3QuePri      pri;              
} CSL_Edma3CmdQuePri;    

/** @brief Edma Command Structure used for setting Event Que threshold level
 *
 *  An object of this type is allocated by the user and
 *  its address is passed as a parameter to the CSL_edma3HwControl API.
 */
typedef struct CSL_Edma3CmdQueThr {
    /** Specifies the Que that needs a change in the threshold setting */
    CSL_Edma3Que         que;
    /** Que threshold setting */              
    CSL_Edma3QueThr      threshold;        
} CSL_Edma3CmdQueThr;    

/** @brief This will have the base-address information for the module
 *  instance
 */
typedef struct {
    /** Base-address of the peripheral registers */
    CSL_Edma3ccRegsOvly regs;                   
} CSL_Edma3ModuleBaseAddress;

/** @brief Edma Channel parameter structure used for opening a channel
 */
typedef struct { 
     /** Region Number */   
    int32 regionNum;
    /** Channel number */                             
    int32 chaNum;                                 
} CSL_Edma3ChannelAttr;

/** @brief Edma Channel Error . 
 *
 *  An object of this type is allocated by the user and
 *  its address is passed as a parameter to the CSL_edma3GetChannelError()
 *  /CSL_edma3GetHwStatus()/ CSL_edma3ChannelErrorClear()
 *  /CSL_edma3HwChannelControl().
 */
typedef struct CSL_Edma3ChannelErr {
    /** a TRUE indicates an event is missed on this channel.  */
    bool    missed;      
    /** a TRUE indicates an event that no events on this channel will be
     * prioritized till this is cleared. This being TRUE does NOT necessarily
     * mean it is an error. ONLY if both missed and ser are set, this kind of 
     * error need  to be cleared.
     */
    bool    secEvt;      
} CSL_Edma3ChannelErr;

/** @brief QDMA Edma Channel Setup
 *
 *  An array of such objects are allocated by the user and
 *  address initialized in the CSL_Edma3HwSetup structure which is passed
 *  CSL_edma3HwSetup()
 */

typedef struct CSL_Edma3HwQdmaChannelSetup {
    /** Que number for the channel */
    CSL_Edma3Que que;                            
    /** Parameter set mapping for the channel. */             
    uint16  paramNum;                            
    /** Trigger word for the QDMA channels. */
    uint8   triggerWord;                         
} CSL_Edma3HwQdmaChannelSetup;

/** @brief QDMA Edma Channel Setup
 *
 *  An array of such objects are allocated by the user and
 *  address initialized in the CSL_Edma3HwSetup structure which is passed
 *  CSL_edma3HwSetup()
 */

typedef struct CSL_Edma3HwDmaChannelSetup {
    /** Que number for the channel */
    CSL_Edma3Que que;                     
#ifdef CSL_EDMA3_CHMAPEXIST
    /** Parameter set mapping for the channel. This may not be initialized 
     * for Edma channels on devices that do not have CHMAPEXIST.  
     */
    uint16  paramNum;                     
#endif
} CSL_Edma3HwDmaChannelSetup;

/** @brief Edma Hw Setup Structure 
 */
typedef struct {
    /** Edma Hw Channel setup */
    CSL_Edma3HwDmaChannelSetup *dmaChaSetup;
    /** QEdma Hw Channel setup */
    CSL_Edma3HwQdmaChannelSetup *qdmaChaSetup;
} CSL_Edma3HwSetup;
/**
@}
*/

/** @addtogroup CSL_EDMA3_FUNCTION
 @{ */
/**************************************************************************\
* EDMA global function declarations
\**************************************************************************/

/** ============================================================================
 *   @n@b CSL_edma3Init
 *
 *   @b Description
 *   @n This is the initialization function for the edma CSL. The function must 
 *      be called before calling any other API from this CSL.This function is 
 *      idem-potent. Currently, the function just return status CSL_SOK, 
 *      without doing anything.
 *
 * =============================================================================
 */
extern int32 EDMA3_init( CSL_Edma3Context *pContext );

/** ============================================================================
 *   @n@b CSL_edma3Open
 *
 *   @b Description
 *   @n This function returns the handle to the edma instance. This handle is 
 *      passed to all other CSL APIs.
 *
 * =============================================================================
 */
extern CSL_Edma3Handle EDMA3_open(
    CSL_Edma3Obj            *edmaObj,
    int32                   edmaNum,
    CSL_Edma3ModuleAttr		*attr,
    int32                   *status
);

/** ============================================================================
 *   @n@b CSL_edma3Close
 *
 *   @b Description
 *   @n This is a module level close require to invalidate the module handle.
 *      The module handle must not be used after this API call.
 *      
 * =============================================================================
 */
extern int32 EDMA3_close( CSL_Edma3Handle hEdma );

/** ============================================================================
 *   @n@b CSL_edma3HwSetup
 *
 *   @b Description
 *   @n This function initializes the device registers with the appropriate 
 *      values provided through the HwSetup Data structure. After the Setup is 
 *      completed, the device is ready for operation. For information passed 
 *      through the HwSetup Data structure, refer CSL_Edma3HwSetup.This does 
 *      the setup for all dma/qdma channels viz. the parameter entry mapping, 
 *      the trigger word setting (if QDMA channels) and the event queue mapping 
 *      of the channel.
 *
 * =============================================================================
 */
extern int32 EDMA3_hwSetup( CSL_Edma3Handle hMod, CSL_Edma3HwSetup *setup );

/** ============================================================================
 *   @n@b CSL_edma3GetHwSetup
 *
 *   @b Description
 *   @n It gets setup of the all dma/qdma channels
 *
 * =============================================================================
 */
extern int32 EDMA3_getHwSetup( CSL_Edma3Handle hMod, CSL_Edma3HwSetup *setup );

/** ============================================================================
 *   @n@b CSL_edma3HwControl
 *
 *   @b Description
 *   @n Takes a command with an optional argument & implements it. This function
 *      is used to carry out the different operations performed by EDMA.
 *
 * =============================================================================
 */
extern int32 EDMA3_hwControl(
	CSL_Edma3Handle           hMod,
    CSL_Edma3HwControlCmd     cmd,
    void                      *cmdArg
);

/** ============================================================================
 *   @n@b CSL_edma3ccGetModuleBaseAddr
 *
 *   @b Description
 *   @n  This function is used for getting the base-address of the peripheral
 *       instance. This function will be called inside the @ CSL_edma3Open()/
 *       CSL_edma3ChannelOpen() function call. 
 *
 *       Note: This function is open for re-implementing if the user wants to 
 *       modify the base address of the peripheral object to point to a 
 *       different location and there by allow CSL initiated write/reads into 
 *       peripheral MMR's go to an alternate location.
 *
 * ===========================================================================
 */
extern int32 EDMA3_ccGetModuleBaseAddr(
    int32                 		edmaNum,
    CSL_Edma3ModuleAttr         *pAttr,
    CSL_Edma3ModuleBaseAddress  *pBaseAddress
);

/** ============================================================================
 *   @n@b CSL_edma3GetHwStatus
 *
 *   @b Description
 *   @n Gets the status of the different operations or the current setup of EDMA 
 *      module.
 *
 * =============================================================================
 */
extern int32 EDMA3_getHwStatus(
    CSL_Edma3Handle              hMod,
    CSL_Edma3HwStatusQuery       myQuery,
    void                         *response
);

/** ============================================================================
 *   @n@b CSL_edma3ChannelOpen
 *
 *   @b Description
 *   @n The API returns a handle for the specified EDMA Channel for use. The 
 *      channel can be re-opened anytime after it has been normally closed if so
 *      required. The handle returned by this call is input as an essential 
 *      argument for many of the APIs described for this module.
 *
 * =============================================================================
 */
extern CSL_Edma3ChannelHandle EDMA3_channelOpen(
    CSL_Edma3ChannelObj     *edmaObj,
    int32                   edmaNum,
    CSL_Edma3ChannelAttr	*chAttr,
    int32                   *status
);

/** ============================================================================
 *   @n@b csl_edma3ChannelClose.c
 *
 *   @b Description
 *   @n This function marks the channel cannot be accessed anymore using 
 *      the handle. CSL for the EDMA channel need to be reopened before using 
 *      any edma channel.
 *
 * =============================================================================
 */
extern int32 EDMA3_channelClose( CSL_Edma3ChannelHandle hEdma );

/** ============================================================================
 *   @n@b CSL_edma3HwChannelSetupParam
 *
 *   @b Description
 *   @n Sets up the channel to parameter entry mapping.This writes the 
 *      DCHMAP[]/QCHMAP appropriately.
 *
 * =============================================================================
 */
extern int32 EDMA3_hwChannelSetupParam( CSL_Edma3ChannelHandle hEdma, uint32 paramNum );

/*
 * =============================================================================
 *   @func CSL_edma3ChannelSetupTriggerWord
 *
 *   @desc
 *      Sets up the channel trigger word.This is applicable only 
 *      for QDMA channels.
 *
 * ===========================================================================
 */
extern int32 EDMA3_hwChannelSetupTriggerWord(
    CSL_Edma3ChannelHandle      hEdma,
    uint8                       triggerWord   
);

/*
 * =============================================================================
 *   @func CSL_edma3ChannelSetupQue
 *
 *   @desc
 *      Does the Channel setup i.e the channel to que mapping
 *
 * ===========================================================================
 */
extern int32 EDMA3_hwChannelSetupQue(
    CSL_Edma3ChannelHandle       hEdma,
    CSL_Edma3Que                 que    
);

/** ============================================================================
 *   @n@b CSL_edma3GetHwChannelSetupParam
 *
 *   @b Description
 *   @n Obtains the Channel to Parameter Set mapping.This reads the 
 *      DCHMAP/QCHMAP appropriately.
 *
 * =============================================================================
 */
extern int32 EDMA3_getHwChannelSetupParam(
    CSL_Edma3ChannelHandle       hEdma,
    uint32                      *paramNum    
);

/*
 * =============================================================================
 *   @func CSL_edma3GetHwChannelSetupTriggerWord
 *
 *   @desc
 *      Gets channel trigger word.This is applicable only for QDMA channels.
 *
 * ===========================================================================
 */
extern int32 EDMA3_getHwChannelSetupTriggerWord(
    CSL_Edma3ChannelHandle      hEdma,
    uint8                       *triggerWord  
);

/*
 * =============================================================================
 *   @func CSL_edma3GetHwChannelSetupQue
 *
 *   @desc
 *      Obtains the Channel setup i.e the channel to que mapping
 *
 * ===========================================================================
 */
extern int32 EDMA3_getHwChannelSetupQue(
    CSL_Edma3ChannelHandle      hEdma,
    CSL_Edma3Que                *que   
);

/** ============================================================================
 *   @n@b CSL_edma3HwChannelControl
 *
 *   @b Description
 *   @n Takes a command with an optional argument & implements it. This function
 *      is used to carry out the different operations performed by EDMA.
 *
 * =============================================================================
 */
extern int32 EDMA3_hwChannelControl(
    CSL_Edma3ChannelHandle         hCh,
    CSL_Edma3HwChannelControlCmd   cmd,
    void                           *cmdArg
);

/** ============================================================================
 *   @n@b CSL_edma3GetHwChannelStatus
 *
 *   @b Description
 *   @n Gets the status of the different operations or the current setup of EDMA  
 *      module.
 *
 * =============================================================================
 */
extern int32 CSL_edma3GetHwChannelStatus(
    CSL_Edma3ChannelHandle          hCh,
    CSL_Edma3HwChannelStatusQuery   myQuery,
    void                            *response
);

/** ============================================================================
 *   @n@b CSL_edma3GetParamHandle
 *
 *   @b Description
 *   @n Acquires the Param entry as specified by the argument.
 *
 * =============================================================================
 */
extern CSL_Edma3ParamHandle EDMA3_getParamHandle(
    CSL_Edma3ChannelHandle       hEdma,
    int32                        paramNum,
    int32                        *status       
);

/** ============================================================================
 *   @n@b CSL_edma3ParamSetup
 *
 *   @b Description
 *   @n Configures the EDMA parameter Entry using the values passed in through
 *      the Param setup structure.
 *
 * =============================================================================
 */
extern int32 EDMA3_paramSetup(
    CSL_Edma3ParamHandle        hParam,
    CSL_Edma3ParamSetup         *pSetup  
);

/** ============================================================================
 *   @n@b CSL_edma3ParamWriteWord
 *
 *   @b Description
 *   @n This is for the ease of QDMA channels. Once the QDMA channel transfer is 
 *      triggered, subsequent triggers may be done with only writing the modified
 *      words in the parameter entry along with the trigger word. This API is 
 *      expected to achieve this purpose. Most usage scenarios, the user 
 *      should not be writing more than the trigger word entry.
 *
 * =============================================================================
 */
extern int32 EDMA3_paramWriteWord(
    CSL_Edma3ParamHandle       hParamHndl,
    uint32                     wordOffset,
    uint32                     word 
);













/**************************************************************************\
* EDMA aux function declarations
\**************************************************************************/

/* ============================================================================
 *   @n@b CSL_edma3GetEventMissed
 *
 *   @b Description
 *   @n Queries all the events missed.Since there may be upto 64 EDMA 
 *      channels + upto 8 QDMA channels,this points to an  array of 3, 
 *      32 bit elements.Gets the status of the missed events.
 *
 * ===========================================================================
 */
extern int32 EDMA3_getEventMissed(
    CSL_Edma3Handle     hModule,
    uint32				*missedLo,
    uint32	            *missedHi,
    uint32	            *missedQdma
);


/* ============================================================================
 *   @n@b CSL_edma3GetControllerError
 *
 *   @b Description
 *   @n Gets the status of the controller Error.
 *
 * ===========================================================================
 */
extern int32 EDMA3_getControllerError(
    CSL_Edma3Handle         hModule,
    CSL_Edma3CtrlErrStat    *ccStat
);


/* ============================================================================
 *   @n@b CSL_edma3GetIntrPendStatus
 *
 *   @b Description
 *   @n Queries the interrupt status of the interrupts.This is read from the 
 *      Global Channel Register.Gets the interrupt pend status.
 *
 * ===========================================================================
 */
extern int32 EDMA3_getIntrPendStatus(
    CSL_Edma3Handle     hModule,
    int32				region,
    uint32  	        *intrLo,
    uint32	            *intrHi
);


#if CSL_EDMA3_MEMPROTECT

/* ============================================================================
 *   @n@b CSL_edma3GetMemoryProtectionAttrib
 *
 *   @b Description
 *   @n Queries the Memory Access rights of the specified region. This 
 *      may be global/view.Gets the memory protection attributes.
 *
 * ===========================================================================
 */
extern uint32 EDMA3_getMemoryProtectionAttrib( CSL_Edma3Handle hModule, int32 region );


/* ============================================================================
 *   @n@b CSL_edma3GetMemoryFaultError
 *
 *   @b Description
 *   @n Queries the Channel controllers memory fault error and the error 
 *      attributes.Gets the memory fault status details, clears the fault.
 *
 * ===========================================================================
 */
extern int32 EDMA3_getMemoryFaultError(
    CSL_Edma3Handle             hModule,
    CSL_Edma3MemFaultStat       *memFault
);


/* =============================================================================
 *   @n@b CSL_edma3SetMemoryProtectionAttrib
 *
 *   @b Description
 *   @n This API sets the memory protection attributes for the specified region.
 *      Sets specified memory protection attributes for the specifed region.
 *
 * ===========================================================================
 */
extern int32 EDMA3_setMemoryProtectionAttrib(
    CSL_Edma3Handle     hModule,
    int32				edmaRegion,
    uint32		        mppa
);

#endif

/* =============================================================================
 *   @n@b CSL_edma3DmaRegionAccessEnable
 *
 *   @b Description
 *   @n This API sets the DRAE/DRAEH BitMask.Enables shadow region access bits
 *      DRAE,DRAEH.
 *
 * ===========================================================================
 */
extern int32 EDMA3_dmaRegionAccessEnable(
    CSL_Edma3Handle     hModule,
    int32				edmaRegion,
    uint32      		drae,
    uint32		        draeh
);

/* =============================================================================
 *   @n@b CSL_edma3DmaRegionAccessDisable
 *
 *   @b Description
 *   @n This API clears the DRAE/DRAEH BitMask..Disable shadow region access bits
 *      DRAE,DRAEH.
 *
 * ===========================================================================
 */
extern int32 EDMA3_dmaRegionAccessDisable(
    CSL_Edma3Handle     hModule,
    int32				edmaRegion,
    uint32       		drae,
    uint32       		draeh
);

/* =============================================================================
 *   @n@b CSL_edma3QdmaRegionAccessEnable
 *
 *   @b Description
 *   @n This API sets the QRAE BitMask.Enables shadow region access bits QRAE
 *
 * ===========================================================================
 */
extern int32 EDMA3_qdmaRegionAccessEnable(
    CSL_Edma3Handle     hModule,
    int32				edmaRegion,
    uint32				qrae
);

/* =============================================================================
 *   @n@b CSL_edma3QdmaRegionAccessDisable
 *
 *   @b Description
 *   @n This API clears the QRAE BitMask.Disables shadow region access bits QRAE
 *
 * ===========================================================================
 */
extern int32 EDMA3_qdmaRegionAccessDisable(
    CSL_Edma3Handle     hModule,
    int32				edmaRegion,
    uint32				qrae
);

/* =============================================================================
 *   @n@b CSL_edma3EventQueuePrioritySet
 *
 *   @b Description
 *   @n This API sets the Queue priority level to the appropriate value.
 *
 * ===========================================================================
 */
extern int32 EDMA3_eventQueuePrioritySet(
    CSL_Edma3Handle      hModule,
    CSL_Edma3Que         que,
    CSL_Edma3QuePri      pri
);

/* =============================================================================
 *   @n@b CSL_Edma3QueThresholdSet
 *
 *   @b Description
 *   @n Sets the specified threshold for the specified queue.This API sets the 
 *      Queue threshold to the appropriate level.
 * 
 * ===========================================================================
 */
extern int32 EDMA3_eventQueueThresholdSet(
    CSL_Edma3Handle      hModule,
    CSL_Edma3Que         que,
    CSL_Edma3QueThr      threshold
);

/* =============================================================================
 *   @n@b CSL_edma3ErrorEval
 *
 *   @b Description
 *   @n This API enables enables evaluation of errros for the specified 
 *      view/shadow region.Sets EVAL bit of the EEVAL register in the Global 
 *      register space
 * 
 * ===========================================================================
 */    
extern int32 EDMA3_errorEval( CSL_Edma3Handle hModule );


/* =============================================================================
 *   @n@b CSL_edma3InterruptEnable
 *
 *   @b Description
 *   @n Enables the specified interrupt in the Global Channel register space.
 *      This API enables the interrupts as specified in the BitMask.
 * 
 * ===========================================================================
 */    
extern int32 EDMA3_interruptEnable(
    CSL_Edma3Handle     hModule,
    int32				region,
    uint32				intrLo,
    uint32				intrHi
);

/* =============================================================================
 *   @n@b CSL_edma3InterruptDisable
 *
 *   @b Description
 *   @n Disables the specified interrupt in the Global Channel register space.
 *      This API disables the interrupts as specified in the BitMask.
 * 
 * ===========================================================================
 */    

extern int32 EDMA3_interruptDisable(
    CSL_Edma3Handle     hModule,
    int32				region,
    uint32          	intrLo,
    uint32				intrHi
);

/* =============================================================================
 *   @n@b CSL_edma3InterruptClear
 *
 *   @b Description
 *   @n This API clears the interrupt as specified.Clears the specified 
 *      interrupt in the Global Channel register space.
 * 
 * ===========================================================================
 */    
extern int32 EDMA3_interruptClear(
    CSL_Edma3Handle     hModule,
    int32				region,
    uint32          	intrLo,
    uint32          	intrHi
);

/* =============================================================================
 *   @n@b CSL_edma3InterruptEval
 *
 *   @b Description
 *   @n If any enabled interrutps are pending, the tpcc_intN output signal 
 *      to be pulsed.
 * 
 * ===========================================================================
 */    
extern int32 EDMA3_interruptEval( CSL_Edma3Handle hModule, int32 region );


/* =============================================================================
 *   @n@b CSL_edma3MemFaultClear
 *
 *   @b Description
 *   @n Clear Memory Fault.
 * 
 * ===========================================================================
 */    
extern int32 EDMA3_memFaultClear( CSL_Edma3Handle hModule );


/* =============================================================================
 *   @n@b CSL_edma3ControllerErrorClear
 *
 *   @b Description
 *   @n Channel Controller Error Fault.
 * 
 * ===========================================================================
 */    
extern int32 EDMA3_controllerErrorClear(
    CSL_Edma3Handle         hModule,
    CSL_Edma3CtrlErrStat   *ccStat
);

/* =============================================================================
 *   @n@b CSL_edma3EventMissedClear
 *
 *   @b Description
 *   @n Clear the Event missed errors
 * 
 * ===========================================================================
 */   
extern int32 EDMA3_eventsMissedClear(
    CSL_Edma3Handle     hModule,
    uint32          	missedLo,
    uint32          	missedHi,
    uint32          	missedQdma
);

/* =============================================================================
 *   @n@b CSL_edma3GetQueStatus
 *
 *   @b Description
 *   @n Obtains the queue status
 * 
 * ===========================================================================
 */   
extern int32 EDMA3_getQueStatus(
    CSL_Edma3Handle      hModule,
    CSL_Edma3Que         que,
    CSL_Edma3QueStat    *queStat
);

/* =============================================================================
 *   @n@b CSL_edma3GetActivityStatus
 *
 *   @b Description
 *   @n Obtains the Channel Controller Activity Status
 * 
 * ===========================================================================
 */   
extern int32 EDMA3_getActivityStatus(
    CSL_Edma3Handle          hModule,
    CSL_Edma3ActivityStat    *activityStat
);

/* =============================================================================
 *   @n@b CSL_edma3GetInfo
 *
 *   @b Description
 *   @n Obtains the Channel Controller's Information
 * 
 * ===========================================================================
 */   
extern int32 EDMA3_getInfo( CSL_Edma3Handle hModule, CSL_Edma3QueryInfo *response );


/* =============================================================================
 *   @n@b CSL_edma3HwChannelEnable
 *
 *   @b Description
 *   @n This API enables the event associated with the Channel. Enables
 *      the channel
 * 
 * ===========================================================================
 */   
extern int32 EDMA3_channelEnable( CSL_Edma3ChannelHandle hEdma );


/* =============================================================================
 *   @n@b CSL_edma3HwChannelDisable
 *
 *   @b Description
 *   @n This API disables the event associated with the Channel. Disables 
 *      the channel
 * 
 * ===========================================================================
 */   
extern int32 EDMA3_channelDisable( CSL_Edma3ChannelHandle hEdma );


/* =============================================================================
 *   @n@b CSL_edma3ChannelEventSet
 *
 *   @b Description
 *   @n Manually triggers an EDMA event by setting the ER register
 * 
 * ===========================================================================
 */   
extern int32 EDMA3_channelEventSet( CSL_Edma3ChannelHandle hEdma );


/* =============================================================================
 *   @n@b CSL_edma3ChannelEventClear
 *
 *   @b Description
 *   @n This API clears the event (if set) for the channel .Clears the EDMA 
 *      event by writing the ECR register for normal channels for QDMA channels
 * 
 * ===========================================================================
 */   
extern int32 EDMA3_channelEventClear( CSL_Edma3ChannelHandle hEdma );


/* =============================================================================
 *   @n@b CSL_Edma3GetChannelStatus
 *
 *   @b Description
 *   @n Obtains the Channel Status i.e whether an even is set.
 * 
 * ===========================================================================
 */   
extern int32 EDMA3_getChannelStatus( CSL_Edma3ChannelHandle hChannel, bool *response );


/* =============================================================================
 *   @n@b CSL_Edma3GetChannelErrStatus
 *
 *   @b Description
 *   @n Obtains the Channel Error Status.
 * 
 * ===========================================================================
 */   
extern int32 EDMA3_getChannelErrStatus(
    CSL_Edma3ChannelHandle      hChannel,
    CSL_Edma3ChannelErr         *errClr
);


/* =============================================================================
 *   @n@b CSL_Edma3ChannelErrorClear
 *
 *   @b Description
 *   @n Clears the channel and associated error conditions:- Clears 
 *      EMR/EMRH/QEMR and  SER/SERH/QSER. 
 *
 * ===========================================================================
 */   
extern int32 EDMA3_channelErrorClear(
    CSL_Edma3ChannelHandle      hChannel,
    CSL_Edma3ChannelErr         *errClr
);


/* =============================================================================
 *   EDMA3_qdmaInit
 *
 *   @b Description
 *   @n инициализация QDMA канала
 *      numCha - номер канала от 0 до 7
 *		paramNumm - номер набора параметров 0 - 255
 *
 * ===========================================================================
 */ 
void EDMA3_qdmaInit( uint32 numCha, uint32 paramNum );


/* =============================================================================
 *   EDMA3_qdmaConfigArgs
 *
 *   @b Description
 *   @n конфигурирование набора параметров для QDMA канала
 *		paramNumm - номер набора параметров 0 - 255
 *      ps - набор параметров
 *
 * ===========================================================================
 */ 
void EDMA3_qdmaConfigArgs( uint32 paramNum, CSL_Edma3ParamSetup* ps );

/* =============================================================================
 *   EDMA3_qdmaIntTest
 *
 *   @b Description
 *   @n проверка прерывания QDMA
 *      numCha - номер канала от 0 до 7
 *
 * ===========================================================================
 */ 
uint32 EDMA3_qdmaIntTest(uint32 numCha);


/* =============================================================================
 *   EDMA3_qdmaIntClear
 *
 *   @b Description
 *   @n сброс прерывания QDMA
 *      numCha - номер канала от 0 до 7
 *
 * ===========================================================================
 */ 
void EDMA3_qdmaIntClear(uint32 numCha);


#endif
















