#ifndef __RTS_EDMA_H__
#define __RTS_EDMA_H__

/*****************************************************************************\
* REGISTERS/PARAMETERS
*
* OPT    - options parameter
* SRC    - source address parameter
* CNT    - transfer count parameter
* DST    - destination address parameter
* IDX    - index parameter
* RLD    - count reload + link parameter
* QOPT   - QDMA options register
* QSRC   - QDMA source address register
* QCNT   - QDMA transfer count register
* QDST   - QDMA destination address register
* QIDX   - QDMA index register
* QSOPT  - QDMA options pseudo register
* QSSRC  - QDMA source address pseudo register
* QSCNT  - QDMA transfer count pseudo register
* QSDST  - QDMA destination address pseudo register
* QSIDX  - QDMA index pseudo register
* PQSR   - priority queue status register
* PQAR0  - priority queue allocation register 0
* PQAR1  - priority queue allocation register 1
* PQAR2  - priority queue allocation register 2
* PQAR3  - priority queue allocation register 3
* CIPR   - channel interrupt pending register
* CIPRL  - channel interrupt pending register, low half (1)
* CIPRH  - channel interrupt pending register, high half (1)
* CIER   - channel interrupt enable register
* CIERL  - channel interrupt enable register, low half (1)
* CIERH  - channel interrupt enable register, high half (1)
* CCER   - channel chain enable register
* CCERL  - channel chain enable register, low half (1)
* CCERH  - channel chain enable register, high half (1)
* ER     - event register
* ERL    - event register, low half (1)
* ERH    - event register, high half (1)
* EER    - event enable register
* EERL   - event enable register, low half (1)
* EERH   - event enable register, high half (1)
* EPRL   - event polarity register, low half (1)
* EPRH   - event polarity register, high half (1)
* ECR    - event clear register
* ECRL   - event clear register, low half (1)
* ECRH   - event clear register, high half (1)
* ESR    - event set register
* ESRL   - event set register, low half (1)
* ESRH   - event set register, high half (1)
*
*
* CHIP_6713, CHIP_DA610, CHIP_6711C and CHIP_6712C
* ESEL0  - event selection register 0 (2)
* ESEL1  - event selection register 1 (2)
* ESEL2  - event selection register 2 (2) (3)
* ESEL3  - event selection register 3 (2)
*
* (1) - only supported on C64x devices
* (2) - only supported on C6713, DA610, 6711C and 6712C
* (3) - the whole register is reserved
\******************************************************************************/
#ifndef _OS_CSL_EDMAHAL_H
#define _OS_CSL_EDMAHAL_H_

#ifndef _CSL_STDINC_H_
#define _CSL_STDINC_H_

#ifndef _CSL_STDINCHAL_H_
#define _CSL_STDINCHAL_H_

//  #define CHIP_6416 1

  #define _VALUEOF(x) ((uint32)(x))

  #define _PER_FSHIFT(PER,REG,FIELD) \
    _##PER##_##REG##_##FIELD##_SHIFT

  #define _PER_FMASK(PER,REG,FIELD) \
    _##PER##_##REG##_##FIELD##_MASK

  #define _PER_FSYM(PER,REG,FIELD,SYM)\
    PER##_##REG##_##FIELD##_##SYM

  #define _PER_FDEFAULT(PER,REG,FIELD) \
    ((##PER##_##REG##_##FIELD##_DEFAULT << _##PER##_##REG##_##FIELD##_SHIFT) \
    & _##PER##_##REG##_##FIELD##_MASK)

  #define _PER_FMK(PER,REG,FIELD,x) (\
    (((uint32)(x))<<_PER_FSHIFT(##PER,##REG,##FIELD))\
    &_PER_FMASK(##PER,##REG,##FIELD)\
  )

  #define _PER_FMKS(PER,REG,FIELD,SYM) (\
    (_PER_FSYM(##PER,##REG,##FIELD,##SYM)<<_PER_FSHIFT(##PER,##REG,##FIELD))\
    &_PER_FMASK(##PER,##REG,##FIELD)\
  )

  #define _PER_FEXTRACT(PER,REG,FIELD,reg) (uint32)(\
    (((uint32)(reg)&_PER_FMASK(##PER,##REG,##FIELD))\
    >>_PER_FSHIFT(##PER,##REG,##FIELD))\
  )

  #define _PER_FINSERT(PER,REG,FIELD,reg,field) (uint32)(\
    (((uint32)(reg)&~_PER_FMASK(##PER,##REG,##FIELD))|\
    (((uint32)(field)<<_PER_FSHIFT(##PER,##REG,##FIELD))\
    &_PER_FMASK(##PER,##REG,##FIELD)))\
  )

  /*******************************************************/
  /* macros for memmory mapped registers                 */
  /*******************************************************/

  #define _PER_RAOI(addr,PER,REG,and,or,inv)\
    (*(volatile uint32*)(addr))=(\
      ((((*(volatile uint32*)(addr))\
      &((uint32)(and)))\
      |((uint32)(or)))\
      ^((uint32)(inv)))\
    )

  #define _PER_RGET(addr,PER,REG) \
    (*(volatile uint32*)(addr))

  #define _PER_RSET(addr,PER,REG,x) \
    (*(volatile uint32*)(addr))=((uint32)(x))

  #define _PER_FGET(addr,PER,REG,FIELD) \
    _PER_FEXTRACT(##PER,##REG,##FIELD,_PER_RGET(addr,##PER,##REG))

  #define _PER_FSET(addr,PER,REG,FIELD,field)\
    _PER_RSET(addr,##PER,##REG,\
    _PER_FINSERT(##PER,##REG,##FIELD,_PER_RGET(addr,##PER,##REG),field))

  #define _PER_FSETS(addr,PER,REG,FIELD,SYM)\
    _PER_RSET(addr,##PER,##REG,_PER_FINSERT(##PER,##REG,##FIELD,_PER_RGET(addr,##PER,##REG),\
    _PER_FSYM(##PER,##REG,##FIELD,##SYM)))

  /*******************************************************/
  /* macros for CPU control registers                    */
  /*******************************************************/

  #define _PER_CRGET(PER,REG) \
    REG

  #define _PER_CRSET(PER,REG,reg) \
    REG=((uint32)(reg))

  #define _PER_CFGET(PER,REG,FIELD) \
    _PER_FEXTRACT(##PER,##REG,##FIELD,_PER_CRGET(##PER,##REG))

  #define _PER_CFSET(PER,REG,FIELD,field)\
    _PER_CRSET(##PER,##REG,\
    _PER_FINSERT(##PER,##REG,##FIELD,_PER_CRGET(##PER,##REG),field))

  #define _PER_CFSETS(PER,REG,FIELD,SYM)\
    _PER_CRSET(##PER,##REG,\
    _PER_FINSERT(##PER,##REG,FIELD,_PER_CRGET(##PER,##REG),\
    _PER_FSYM(##PER,##REG,##FIELD,##SYM)))

/*----------------------------------------------------------------------------*/
#endif /* _CSL_STDINCHAL_H_ */


#ifndef TRUE
  #define TRUE   1
#endif
#ifndef FALSE
  #define FALSE  0
#endif

#ifndef INV
  #define INV    ((void*)(-1))
#endif

#ifndef UNREFERENCED_PARAMETER
  #define UNREFERENCED_PARAMETER(P)    ((P)=(P))
#endif

#ifndef REG32
  #define REG32(addr) (*(volatile unsigned int*)(addr))
  #define REG16(addr) (*(volatile unsigned short*)(addr))
  #define REG8(addr)  (*(volatile unsigned char*)(addr))
#endif

//#include <tistdtypes.h> /* use typedefs provided with CCS*/

#endif /* _CSL_STDINC_H_ */


/******************************************************************************\
* MISC section
\******************************************************************************/

#if defined(CHIP_6416)
  #define _EDMA_CHA_CNT         64
  #define _EDMA_BASE_PRAM       0x01A00000u
  #define _EDMA_PRAM_START      _EDMA_BASE_PRAM
  #define _EDMA_PRAM_SIZE       0x00000800u
  #define _EDMA_PRAM_ERASE       0x00000600u
#endif

#if defined(CHIP_6412)
  #define _EDMA_CHA_CNT         64
  #define _EDMA_BASE_PRAM       0x01A00000u
  #define _EDMA_PRAM_START      _EDMA_BASE_PRAM
  #define _EDMA_PRAM_SIZE       0x00001400u
  #define _EDMA_PRAM_ERASE      0x00000600u
#endif

  #define _EDMA_ENTRY_SIZE      0x00000018u
  #define _EDMA_NULL_PARAM      (_EDMA_PRAM_START+_EDMA_ENTRY_SIZE*_EDMA_CHA_CNT)
  #define _EDMA_RSVD_PARAM      (_EDMA_NULL_PARAM+_EDMA_ENTRY_SIZE)
  #define _EDMA_LINK_START      (_EDMA_RSVD_PARAM+_EDMA_ENTRY_SIZE)
  #define _EDMA_LINK_CNT        ((_EDMA_PRAM_SIZE/_EDMA_ENTRY_SIZE)-(_EDMA_CHA_CNT+2))
  #define _EDMA_SCRATCH_START   (_EDMA_LINK_START+_EDMA_LINK_CNT*_EDMA_ENTRY_SIZE)
  #define _EDMA_SCRATCH_SIZE    (_EDMA_PRAM_START+_EDMA_PRAM_SIZE-_EDMA_SCRATCH_START)

/******************************************************************************\
* module level register/field access macros
\******************************************************************************/

  /* ----------------- */
  /* FIELD MAKE MACROS */
  /* ----------------- */

  #define EDMA_FMK(REG,FIELD,x)\
    _PER_FMK(EDMA,##REG,##FIELD,x)

  #define EDMA_FMKS(REG,FIELD,SYM)\
    _PER_FMKS(EDMA,##REG,##FIELD,##SYM)


  /* -------------------------------- */
  /* RAW REGISTER/FIELD ACCESS MACROS */
  /* -------------------------------- */

  #define EDMA_REG(REG)  (*(volatile uint32*)(_EDMA_##REG##_ADDR))

  #define EDMA_ADDR(REG)\
    _EDMA_##REG##_ADDR

  #define EDMA_RGET(REG)\
    _PER_RGET(_EDMA_##REG##_ADDR,EDMA,##REG)

  #define EDMA_RSET(REG,x)\
    _PER_RSET(_EDMA_##REG##_ADDR,EDMA,##REG,x)

  #define EDMA_FGET(REG,FIELD)\
    _EDMA_##REG##_FGET(##FIELD)

  #define EDMA_FSET(REG,FIELD,x)\
    _EDMA_##REG##_FSET(##FIELD,##x)

  #define EDMA_FSETS(REG,FIELD,SYM)\
    _EDMA_##REG##_FSETS(##FIELD,##SYM)


  /* ------------------------------------------ */
  /* ADDRESS BASED REGISTER/FIELD ACCESS MACROS */
  /* ------------------------------------------ */

  #define EDMA_RGETA(addr,REG)\
    _PER_RGET(addr,EDMA,##REG)

  #define EDMA_RSETA(addr,REG,x)\
    _PER_RSET(addr,EDMA,##REG,x)

  #define EDMA_FGETA(addr,REG,FIELD)\
    _PER_FGET(addr,EDMA,##REG,##FIELD)

  #define EDMA_FSETA(addr,REG,FIELD,x)\
    _PER_FSET(addr,EDMA,##REG,##FIELD,x)

  #define EDMA_FSETSA(addr,REG,FIELD,SYM)\
    _PER_FSETS(addr,EDMA,##REG,##FIELD,##SYM)


  /* ----------------------------------------- */
  /* HANDLE BASED REGISTER/FIELD ACCESS MACROS */
  /* ----------------------------------------- */

  #define EDMA_ADDRH(h,REG)\
    ((((uint32)(h))&0x0000FFFF)+_EDMA_PRAM_START+(_EDMA_##REG##_OFFSET<<2))

  #define EDMA_RGETH(h,REG)\
    EDMA_RGETA(EDMA_ADDRH(h,##REG),##REG)


  #define EDMA_RSETH(h,REG,x)\
    EDMA_RSETA(EDMA_ADDRH(h,##REG),##REG,x)


  #define EDMA_FGETH(h,REG,FIELD)\
    EDMA_FGETA(EDMA_ADDRH(h,##REG),##REG,##FIELD)


  #define EDMA_FSETH(h,REG,FIELD,x)\
    EDMA_FSETA(EDMA_ADDRH(h,##REG),##REG,##FIELD,x)


  #define EDMA_FSETSH(h,REG,FIELD,SYM)\
    EDMA_FSETSA(EDMA_ADDRH(h,##REG),##REG,##FIELD,##SYM)



/******************************************************************************\
* _____________________
* |                   |
* |  O P T            |
* |  Q O P T          |
* |  Q S O P T        |
* |___________________|
*
* OPT    - options parameter
* QOPT   - QDMA options register
* QSOPT  - QDMA options pseudo register
*
* FIELDS (msb -> lsb)
* (rw) PRI
* (rw) ESIZE
* (rw) 2DS
* (rw) SUM
* (rw) 2DD
* (rw) DUM
* (rw) TCINT
* (rw) TCC
* (rw) TCCM (1)
* (rw) ATCINT (1)
* (rw) ATCC (1)
* (rw) PDTS (1)
* (rw) PDTD (1)
* (rw) LINK
* (rw) FS
*
* (1) - only supported on C64x devices
*
\******************************************************************************/
  #define _EDMA_OPT_OFFSET             0
  #define _EDMA_QOPT_OFFSET            0
  #define _EDMA_QSOPT_OFFSET           8

  #define _EDMA_QOPT_ADDR              0x02000000u
  #define _EDMA_QSOPT_ADDR             0x02000020u

  #define  EDMA_QOPT                   EDMA_REG(QOPT)
  #define  EDMA_QSOPT                  EDMA_REG(QSOPT)

  #define _EDMA_OPT_PRI_MASK           0xE0000000u
  #define _EDMA_OPT_PRI_SHIFT          0x0000001Du
  #define  EDMA_OPT_PRI_DEFAULT        0x00000000u
  #define  EDMA_OPT_PRI_OF(x)          _VALUEOF(x)
  #define  EDMA_OPT_PRI_URGENT       0x00000000u
  #define  EDMA_OPT_PRI_HIGH         0x00000001u
  #define  EDMA_OPT_PRI_MEDIUM       0x00000002u
  #define  EDMA_OPT_PRI_LOW          0x00000003u

  #define _EDMA_OPT_ESIZE_MASK         0x18000000u
  #define _EDMA_OPT_ESIZE_SHIFT        0x0000001Bu
  #define  EDMA_OPT_ESIZE_DEFAULT      0x00000000u
  #define  EDMA_OPT_ESIZE_OF(x)        _VALUEOF(x)
  #define  EDMA_OPT_ESIZE_32BIT        0x00000000u
  #define  EDMA_OPT_ESIZE_16BIT        0x00000001u
  #define  EDMA_OPT_ESIZE_8BIT         0x00000002u

  #define _EDMA_OPT_2DS_MASK           0x04000000u
  #define _EDMA_OPT_2DS_SHIFT          0x0000001Au
  #define  EDMA_OPT_2DS_DEFAULT        0x00000000u
  #define  EDMA_OPT_2DS_OF(x)          _VALUEOF(x)
  #define  EDMA_OPT_2DS_NO             0x00000000u
  #define  EDMA_OPT_2DS_YES            0x00000001u

  #define _EDMA_OPT_SUM_MASK           0x03000000u
  #define _EDMA_OPT_SUM_SHIFT          0x00000018u
  #define  EDMA_OPT_SUM_DEFAULT        0x00000000u
  #define  EDMA_OPT_SUM_OF(x)          _VALUEOF(x)
  #define  EDMA_OPT_SUM_NONE           0x00000000u
  #define  EDMA_OPT_SUM_INC            0x00000001u
  #define  EDMA_OPT_SUM_DEC            0x00000002u
  #define  EDMA_OPT_SUM_IDX            0x00000003u

  #define _EDMA_OPT_2DD_MASK           0x00800000u
  #define _EDMA_OPT_2DD_SHIFT          0x00000017u
  #define  EDMA_OPT_2DD_DEFAULT        0x00000000u
  #define  EDMA_OPT_2DD_OF(x)          _VALUEOF(x)
  #define  EDMA_OPT_2DD_NO             0x00000000u
  #define  EDMA_OPT_2DD_YES            0x00000001u

  #define _EDMA_OPT_DUM_MASK           0x00600000u
  #define _EDMA_OPT_DUM_SHIFT          0x00000015u
  #define  EDMA_OPT_DUM_DEFAULT        0x00000000u
  #define  EDMA_OPT_DUM_OF(x)          _VALUEOF(x)
  #define  EDMA_OPT_DUM_NONE           0x00000000u
  #define  EDMA_OPT_DUM_INC            0x00000001u
  #define  EDMA_OPT_DUM_DEC            0x00000002u
  #define  EDMA_OPT_DUM_IDX            0x00000003u

  #define _EDMA_OPT_TCINT_MASK         0x00100000u
  #define _EDMA_OPT_TCINT_SHIFT        0x00000014u
  #define  EDMA_OPT_TCINT_DEFAULT      0x00000000u
  #define  EDMA_OPT_TCINT_OF(x)        _VALUEOF(x)
  #define  EDMA_OPT_TCINT_NO           0x00000000u
  #define  EDMA_OPT_TCINT_YES          0x00000001u

  #define _EDMA_OPT_TCC_MASK           0x000F0000u
  #define _EDMA_OPT_TCC_SHIFT          0x00000010u
  #define  EDMA_OPT_TCC_DEFAULT        0x00000000u
  #define  EDMA_OPT_TCC_OF(x)          _VALUEOF(x)

  #define _EDMA_OPT_TCCM_MASK          0x00006000u
  #define _EDMA_OPT_TCCM_SHIFT         0x0000000Du
  #define  EDMA_OPT_TCCM_DEFAULT       0x00000000u
  #define  EDMA_OPT_TCCM_OF(x)         _VALUEOF(x)

  #define _EDMA_OPT_ATCINT_MASK        0x00001000u
  #define _EDMA_OPT_ATCINT_SHIFT       0x0000000Cu
  #define  EDMA_OPT_ATCINT_DEFAULT     0x00000000u
  #define  EDMA_OPT_ATCINT_OF(x)       _VALUEOF(x)
  #define  EDMA_OPT_ATCINT_NO          0x00000000u
  #define  EDMA_OPT_ATCINT_YES         0x00000001u

  #define _EDMA_OPT_ATCC_MASK          0x000007E0u
  #define _EDMA_OPT_ATCC_SHIFT         0x00000005u
  #define  EDMA_OPT_ATCC_DEFAULT       0x00000000u
  #define  EDMA_OPT_ATCC_OF(x)         _VALUEOF(x)

  #define _EDMA_OPT_PDTS_MASK          0x00000008u
  #define _EDMA_OPT_PDTS_SHIFT         0x00000003u
  #define  EDMA_OPT_PDTS_DEFAULT       0x00000000u
  #define  EDMA_OPT_PDTS_OF(x)         _VALUEOF(x)
  #define  EDMA_OPT_PDTS_DISABLE       0x00000000u
  #define  EDMA_OPT_PDTS_ENABLE        0x00000001u

  #define _EDMA_OPT_PDTD_MASK          0x00000004u
  #define _EDMA_OPT_PDTD_SHIFT         0x00000002u
  #define  EDMA_OPT_PDTD_DEFAULT       0x00000000u
  #define  EDMA_OPT_PDTD_OF(x)         _VALUEOF(x)
  #define  EDMA_OPT_PDTD_DISABLE       0x00000000u
  #define  EDMA_OPT_PDTD_ENABLE        0x00000001u

  #define _EDMA_OPT_LINK_MASK          0x00000002u
  #define _EDMA_OPT_LINK_SHIFT         0x00000001u
  #define  EDMA_OPT_LINK_DEFAULT       0x00000000u
  #define  EDMA_OPT_LINK_OF(x)         _VALUEOF(x)
  #define  EDMA_OPT_LINK_NA            0x00000000u
  #define  EDMA_OPT_LINK_NO            0x00000000u
  #define  EDMA_OPT_LINK_YES           0x00000001u

  #define _EDMA_OPT_FS_MASK            0x00000001u
  #define _EDMA_OPT_FS_SHIFT           0x00000000u
  #define  EDMA_OPT_FS_DEFAULT         0x00000000u
  #define  EDMA_OPT_FS_OF(x)           _VALUEOF(x)
  #define  EDMA_OPT_FS_NO              0x00000000u
  #define  EDMA_OPT_FS_YES             0x00000001u

  #define  EDMA_OPT_OF(x)              _VALUEOF(x)

  #define EDMA_OPT_DEFAULT (uint32)(\
     _PER_FDEFAULT(EDMA,OPT,PRI)\
    |_PER_FDEFAULT(EDMA,OPT,ESIZE)\
    |_PER_FDEFAULT(EDMA,OPT,2DS)\
    |_PER_FDEFAULT(EDMA,OPT,SUM)\
    |_PER_FDEFAULT(EDMA,OPT,2DD)\
    |_PER_FDEFAULT(EDMA,OPT,DUM)\
    |_PER_FDEFAULT(EDMA,OPT,TCINT)\
    |_PER_FDEFAULT(EDMA,OPT,TCC)\
    |_PER_FDEFAULT(EDMA,OPT,TCCM)\
    |_PER_FDEFAULT(EDMA,OPT,ATCINT) \
    |_PER_FDEFAULT(EDMA,OPT,ATCC) \
    |_PER_FDEFAULT(EDMA,OPT,PDTS) \
    |_PER_FDEFAULT(EDMA,OPT,PDTD) \
    |_PER_FDEFAULT(EDMA,OPT,LINK)\
    |_PER_FDEFAULT(EDMA,OPT,FS)\
  )

  #define EDMA_OPT_RMK(pri,esize,ds2,sum,dd2,dum,tcint,tcc,tccm,atcint,atcc,\
    pdts,pdtd,link,fs) (uint32)(\
     _PER_FMK(EDMA,OPT,PRI,pri) \
    |_PER_FMK(EDMA,OPT,ESIZE,esize) \
    |_PER_FMK(EDMA,OPT,2DS,ds2) \
    |_PER_FMK(EDMA,OPT,SUM,sum) \
    |_PER_FMK(EDMA,OPT,2DD,dd2) \
    |_PER_FMK(EDMA,OPT,DUM,dum) \
    |_PER_FMK(EDMA,OPT,TCINT,tcint) \
    |_PER_FMK(EDMA,OPT,TCC,tcc) \
    |_PER_FMK(EDMA,OPT,TCCM,tccm) \
    |_PER_FMK(EDMA,OPT,ATCINT,atcint) \
    |_PER_FMK(EDMA,OPT,ATCC,atcc) \
    |_PER_FMK(EDMA,OPT,PDTS,pdts) \
    |_PER_FMK(EDMA,OPT,PDTD,pdtd) \
    |_PER_FMK(EDMA,OPT,LINK,link) \
    |_PER_FMK(EDMA,OPT,FS,fs) \
  )

  #define _EDMA_QOPT_FGET(FIELD)\
    _PER_FGET(_EDMA_QOPT_ADDR,EDMA,OPT,##FIELD)

  #define _EDMA_QOPT_FSET(FIELD,field)\
    _PER_FSET(_EDMA_QOPT_ADDR,EDMA,OPT,##FIELD,field)

  #define _EDMA_QOPT_FSETS(FIELD,SYM)\
    _PER_FSETS(_EDMA_QOPT_ADDR,EDMA,OPT,##FIELD,##SYM)

  #define _EDMA_QSOPT_FGET(FIELD)\
    _PER_FGET(_EDMA_QSOPT_ADDR,EDMA,OPT,##FIELD)

  #define _EDMA_QSOPT_FSET(FIELD,field)\
    _PER_FSET(_EDMA_QSOPT_ADDR,EDMA,OPT,##FIELD,field)

  #define _EDMA_QSOPT_FSETS(FIELD,SYM)\
    _PER_FSETS(_EDMA_QSOPT_ADDR,EDMA,OPT,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  S R C            |
* |  Q S R C          |
* |  Q S S R C        |
* |___________________|
*
* SRC    - source address parameter
* QSRC   - QDMA source address register
* QSSRC  - QDMA source address pseudo register
*
* FIELDS (msb -> lsb)
* (rw) SRC
*
\******************************************************************************/
  #define _EDMA_SRC_OFFSET             1
  #define _EDMA_QSRC_OFFSET            1
  #define _EDMA_QSSRC_OFFSET           9

  #define _EDMA_QSRC_ADDR              0x02000004u
  #define _EDMA_QSSRC_ADDR             0x02000024u

  #define  EDMA_QSRC                   EDMA_REG(QSRC)
  #define  EDMA_QSSRC                  EDMA_REG(QSSRC)

  #define _EDMA_SRC_SRC_MASK           0xFFFFFFFFu
  #define _EDMA_SRC_SRC_SHIFT          0x00000000u
  #define  EDMA_SRC_SRC_DEFAULT        0x00000000u
  #define  EDMA_SRC_SRC_OF(x)          _VALUEOF(x)

  #define  EDMA_SRC_OF(x)              _VALUEOF(x)

  #define EDMA_SRC_DEFAULT (uint32)(\
     _PER_FDEFAULT(EDMA,SRC,SRC)\
  )

  #define EDMA_SRC_RMK(src) (uint32)(\
     _PER_FMK(EDMA,SRC,SRC,src) \
  )

  #define _EDMA_QSRC_FGET(FIELD)\
    _PER_FGET(_EDMA_QSRC_ADDR,EDMA,SRC,##FIELD)

  #define _EDMA_QSRC_FSET(FIELD,field)\
    _PER_FSET(_EDMA_QSRC_ADDR,EDMA,SRC,##FIELD,field)

  #define _EDMA_QSRC_FSETS(FIELD,SYM)\
    _PER_FSETS(_EDMA_QSRC_ADDR,EDMA,SRC,##FIELD,##SYM)

  #define _EDMA_QSSRC_FGET(FIELD)\
    _PER_FGET(_EDMA_QSSRC_ADDR,EDMA,SRC,##FIELD)

  #define _EDMA_QSSRC_FSET(FIELD,field)\
    _PER_FSET(_EDMA_QSSRC_ADDR,EDMA,SRC,##FIELD,field)

  #define _EDMA_QSSRC_FSETS(FIELD,SYM)\
    _PER_FSETS(_EDMA_QSSRC_ADDR,EDMA,SRC,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  C N T            |
* |  Q C N T          |
* |  Q S C N T        |
* |___________________|
*
* CNT    - transfer count parameter
* QCNT   - QDMA transfer count register
* QSCNT  - QDMA transfer count pseudo register
*
* FIELDS (msb -> lsb)
* (rw) FRMCNT
* (rw) ELECNT
*
\******************************************************************************/
  #define _EDMA_CNT_OFFSET             2
  #define _EDMA_QCNT_OFFSET            2
  #define _EDMA_QSCNT_OFFSET           10

  #define _EDMA_QCNT_ADDR              0x02000008u
  #define _EDMA_QSCNT_ADDR             0x02000028u

  #define  EDMA_QCNT                   EDMA_REG(QCNT)
  #define  EDMA_QSCNT                  EDMA_REG(QSCNT)

  #define _EDMA_CNT_FRMCNT_MASK        0xFFFF0000u
  #define _EDMA_CNT_FRMCNT_SHIFT       0x00000010u
  #define  EDMA_CNT_FRMCNT_DEFAULT     0x00000000u
  #define  EDMA_CNT_FRMCNT_OF(x)       _VALUEOF(x)

  #define _EDMA_CNT_ELECNT_MASK        0x0000FFFFu
  #define _EDMA_CNT_ELECNT_SHIFT       0x00000000u
  #define  EDMA_CNT_ELECNT_DEFAULT     0x00000000u
  #define  EDMA_CNT_ELECNT_OF(x)       _VALUEOF(x)

  #define  EDMA_CNT_OF(x)              _VALUEOF(x)

  #define EDMA_CNT_DEFAULT (uint32)(\
     _PER_FDEFAULT(EDMA,CNT,FRMCNT)\
    |_PER_FDEFAULT(EDMA,CNT,ELECNT)\
  )

  #define EDMA_CNT_RMK(frmcnt,elecnt) (uint32)(\
     _PER_FMK(EDMA,CNT,FRMCNT,frmcnt) \
    |_PER_FMK(EDMA,CNT,ELECNT,elecnt) \
  )

  #define _EDMA_QCNT_FGET(FIELD)\
    _PER_FGET(_EDMA_QCNT_ADDR,EDMA,CNT,##FIELD)

  #define _EDMA_QCNT_FSET(FIELD,field)\
    _PER_FSET(_EDMA_QCNT_ADDR,EDMA,CNT,##FIELD,field)

  #define _EDMA_QCNT_FSETS(FIELD,SYM)\
    _PER_FSETS(_EDMA_QCNT_ADDR,EDMA,CNT,##FIELD,##SYM)

  #define _EDMA_QSCNT_FGET(FIELD)\
    _PER_FGET(_EDMA_QSCNT_ADDR,EDMA,CNT,##FIELD)

  #define _EDMA_QSCNT_FSET(FIELD,field)\
    _PER_FSET(_EDMA_QSCNT_ADDR,EDMA,CNT,##FIELD,field)

  #define _EDMA_QSCNT_FSETS(FIELD,SYM)\
    _PER_FSETS(_EDMA_QSCNT_ADDR,EDMA,CNT,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  D S T            |
* |  Q D S T          |
* |  Q S D S T        |
* |___________________|
*
* DST    - destination address parameter
* QDST   - QDMA destination address register
* QSDST  - QDMA destination address pseudo register
*
* FIELDS (msb -> lsb)
* (rw) DST
*
\******************************************************************************/
  #define _EDMA_DST_OFFSET             3
  #define _EDMA_QDST_OFFSET            3
  #define _EDMA_QSDST_OFFSET           11

  #define _EDMA_QDST_ADDR              0x0200000Cu
  #define _EDMA_QSDST_ADDR             0x0200002Cu

  #define  EDMA_QDST                   EDMA_REG(QDST)
  #define  EDMA_QSDST                  EDMA_REG(QSDST)

  #define _EDMA_DST_DST_MASK           0xFFFFFFFFu
  #define _EDMA_DST_DST_SHIFT          0x00000000u
  #define  EDMA_DST_DST_DEFAULT        0x00000000u
  #define  EDMA_DST_DST_OF(x)          _VALUEOF(x)

  #define  EDMA_DST_OF(x)              _VALUEOF(x)

  #define EDMA_DST_DEFAULT (uint32)(\
     _PER_FDEFAULT(EDMA,DST,DST)\
  )

  #define EDMA_DST_RMK(dst) (uint32)(\
     _PER_FMK(EDMA,DST,DST,dst) \
  )

  #define _EDMA_QDST_FGET(FIELD)\
    _PER_FGET(_EDMA_QDST_ADDR,EDMA,DST,##FIELD)

  #define _EDMA_QDST_FSET(FIELD,field)\
    _PER_FSET(_EDMA_QDST_ADDR,EDMA,DST,##FIELD,field)

  #define _EDMA_QDST_FSETS(FIELD,SYM)\
    _PER_FSETS(_EDMA_QDST_ADDR,EDMA,DST,##FIELD,##SYM)

  #define _EDMA_QSDST_FGET(FIELD)\
    _PER_FGET(_EDMA_QSDST_ADDR,EDMA,DST,##FIELD)

  #define _EDMA_QSDST_FSET(FIELD,field)\
    _PER_FSET(_EDMA_QSDST_ADDR,EDMA,DST,##FIELD,field)

  #define _EDMA_QSDST_FSETS(FIELD,SYM)\
    _PER_FSETS(_EDMA_QSDST_ADDR,EDMA,DST,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  I D X            |
* |  Q I D X          |
* |  Q S I D X        |
* |___________________|
*
* IDX    - index parameter
* QIDX   - QDMA index register
* QSIDX  - QDMA index pseudo register
*
* FIELDS (msb -> lsb)
* (rw) FRMIDX
* (rw) ELEIDX
*
\******************************************************************************/
  #define _EDMA_IDX_OFFSET             4
  #define _EDMA_QIDX_OFFSET            4
  #define _EDMA_QSIDX_OFFSET           12

  #define _EDMA_QIDX_ADDR              0x02000010u
  #define _EDMA_QSIDX_ADDR             0x02000030u

  #define  EDMA_QIDX                   EDMA_REG(QIDX)
  #define  EDMA_QSIDX                  EDMA_REG(QSIDX)

  #define _EDMA_IDX_FRMIDX_MASK        0xFFFF0000u
  #define _EDMA_IDX_FRMIDX_SHIFT       0x00000010u
  #define  EDMA_IDX_FRMIDX_DEFAULT     0x00000000u
  #define  EDMA_IDX_FRMIDX_OF(x)       _VALUEOF(x)

  #define _EDMA_IDX_ELEIDX_MASK        0x0000FFFFu
  #define _EDMA_IDX_ELEIDX_SHIFT       0x00000000u
  #define  EDMA_IDX_ELEIDX_DEFAULT     0x00000000u
  #define  EDMA_IDX_ELEIDX_OF(x)       _VALUEOF(x)

  #define  EDMA_IDX_OF(x)              _VALUEOF(x)

  #define EDMA_IDX_DEFAULT (uint32)(\
     _PER_FDEFAULT(EDMA,IDX,FRMIDX)\
    |_PER_FDEFAULT(EDMA,IDX,ELEIDX)\
  )

  #define EDMA_IDX_RMK(frmidx,eleidx) (uint32)(\
     _PER_FMK(EDMA,IDX,FRMIDX,frmidx) \
    |_PER_FMK(EDMA,IDX,ELEIDX,eleidx) \
  )

  #define _EDMA_QIDX_FGET(FIELD)\
    _PER_FGET(_EDMA_QIDX_ADDR,EDMA,IDX,##FIELD)

  #define _EDMA_QIDX_FSET(FIELD,field)\
    _PER_FSET(_EDMA_QIDX_ADDR,EDMA,IDX,##FIELD,field)

  #define _EDMA_QIDX_FSETS(FIELD,SYM)\
    _PER_FSETS(_EDMA_QIDX_ADDR,EDMA,IDX,##FIELD,##SYM)

  #define _EDMA_QSIDX_FGET(FIELD)\
    _PER_FGET(_EDMA_QSIDX_ADDR,EDMA,IDX,##FIELD)

  #define _EDMA_QSIDX_FSET(FIELD,field)\
    _PER_FSET(_EDMA_QSIDX_ADDR,EDMA,IDX,##FIELD,field)

  #define _EDMA_QSIDX_FSETS(FIELD,SYM)\
    _PER_FSETS(_EDMA_QSIDX_ADDR,EDMA,IDX,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  R L D            |
* |  Q R L D          |
* |  Q S R L D        |
* |___________________|
*
* RLD - count reload/link parameter
*
* FIELDS (msb -> lsb)
* (rw) ELECNT
* (rw) LINK
*
\******************************************************************************/
  #define _EDMA_RLD_OFFSET             5
  #define _EDMA_QRLD_OFFSET            5
  #define _EDMA_QSRLD_OFFSET           13

  #define _EDMA_QRLD_ADDR              0x02000014u
  #define _EDMA_QSRLD_ADDR             0x02000034u

  #define  EDMA_QRLD                   EDMA_REG(QRLD)
  #define  EDMA_QSRLD                  EDMA_REG(QSRLD)

  #define _EDMA_RLD_ELERLD_MASK        0xFFFF0000u
  #define _EDMA_RLD_ELERLD_SHIFT       0x00000010u
  #define  EDMA_RLD_ELERLD_DEFAULT     0x00000000u
  #define  EDMA_RLD_ELERLD_OF(x)       _VALUEOF(x)

  #define _EDMA_RLD_LINK_MASK          0x0000FFFFu
  #define _EDMA_RLD_LINK_SHIFT         0x00000000u
  #define  EDMA_RLD_LINK_DEFAULT       0x00000000u
  #define  EDMA_RLD_LINK_OF(x)         _VALUEOF(x)

  #define  EDMA_RLD_OF(x)              _VALUEOF(x)

  #define EDMA_RLD_DEFAULT (uint32)(\
     _PER_FDEFAULT(EDMA,RLD,ELERLD)\
    |_PER_FDEFAULT(EDMA,RLD,LINK)\
  )

  #define EDMA_RLD_RMK(elerld,link) (uint32)(\
     _PER_FMK(EDMA,RLD,ELERLD,elerld) \
    |_PER_FMK(EDMA,RLD,LINK,link) \
  )

  #define _EDMA_QRLD_FGET(FIELD)\
    _PER_FGET(_EDMA_QRLD_ADDR,EDMA,RLD,##FIELD)

  #define _EDMA_QRLD_FSET(FIELD,field)\
    _PER_FSET(_EDMA_QRLD_ADDR,EDMA,RLD,##FIELD,field)

  #define _EDMA_QRLD_FSETS(FIELD,SYM)\
    _PER_FSETS(_EDMA_QRLD_ADDR,EDMA,RLD,##FIELD,##SYM)

  #define _EDMA_QSRLD_FGET(FIELD)\
    _PER_FGET(_EDMA_QSRLD_ADDR,EDMA,RLD,##FIELD)

  #define _EDMA_QSRLD_FSET(FIELD,field)\
    _PER_FSET(_EDMA_QSRLD_ADDR,EDMA,RLD,##FIELD,field)

  #define _EDMA_QSRLD_FSETS(FIELD,SYM)\
    _PER_FSETS(_EDMA_QSRLD_ADDR,EDMA,RLD,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  P Q S R          |
* |___________________|
*
* PQSR - priority queue status register
*
* FIELDS (msb -> lsb)
* (r) PQ
*
\******************************************************************************/
  #define _EDMA_PQSR_ADDR              0x01A0FFE0u

  #define  EDMA_PQSR                   EDMA_REG(PQSR)

  #define _EDMA_PQSR_PQ_MASK           0x0000000Fu
  #define _EDMA_PQSR_PQ_SHIFT          0x00000000u
  #define  EDMA_PQSR_PQ_DEFAULT        0x0000000Fu
  #define  EDMA_PQSR_PQ_OF(x)          _VALUEOF(x)

  #define  EDMA_PQSR_OF(x)             _VALUEOF(x)

  #define EDMA_PQSR_DEFAULT (uint32)(\
     _PER_FDEFAULT(EDMA,PQSR,PQ)\
  )
 #if (!(CHIP_6410 | CHIP_6413 | CHIP_6418))
  #define EDMA_PQSR_RMK(pq) (uint32)(\
     _PER_FMK(EDMA,PQSR,PQ,pq)\
  )
 #endif
 
  #define _EDMA_PQSR_FGET(FIELD)\
    _PER_FGET(_EDMA_PQSR_ADDR,EDMA,PQSR,##FIELD)

  #define _EDMA_PQSR_FSET(FIELD,field)\
    _PER_FSET(_EDMA_PQSR_ADDR,EDMA,PQSR,##FIELD,field)

  #define _EDMA_PQSR_FSETS(FIELD,SYM)\
    _PER_FSETS(_EDMA_PQSR_ADDR,EDMA,PQSR,##FIELD,##SYM)

/******************************************************************************\
* _____________________
* |                   |
* |  P Q A R 0        |
* |___________________|
*
* PQAR0 - priority queue allocation register 0
*
* FIELDS (msb -> lsb)
* (r) PQA
*
\******************************************************************************/
  #define _EDMA_PQAR0_ADDR              0x01A0FFC0u

  #define  EDMA_PQAR0                   EDMA_REG(PQAR0)

  #define _EDMA_PQAR0_PQA_MASK           0x00000007u
  #define _EDMA_PQAR0_PQA_SHIFT          0x00000000u
  #define  EDMA_PQAR0_PQA_DEFAULT        0x00000002u
  #define  EDMA_PQAR0_PQA_OF(x)          _VALUEOF(x)

  #define  EDMA_PQAR0_OF(x)             _VALUEOF(x)

  #define EDMA_PQAR0_DEFAULT (uint32)(\
     _PER_FDEFAULT(EDMA,PQAR0,PQA)\
  )

  #if (!(CHIP_6413 | CHIP_6418 | CHIP_6410))
    #define EDMA_PQAR0_RMK(pqa) (uint32)(\
       _PER_FMK(EDMA,PQAR0,PQA,pqa)\
    )
  #endif

  #define _EDMA_PQAR0_FSET(FIELD,field)\
    _PER_FSET(_EDMA_PQAR0_ADDR,EDMA,PQAR0,FIELD,field)

  #define _EDMA_PQAR0_FSETS(FIELD,SYM)\
    _PER_FSETS(_EDMA_PQAR0_ADDR,EDMA,PQAR0,FIELD,##SYM)

  #define _EDMA_PQAR0_FGET(FIELD)\
    _PER_FGET(_EDMA_PQAR0_ADDR,EDMA,PQAR0,FIELD)

/******************************************************************************\
* _____________________
* |                   |
* |  P Q A R 1        |
* |___________________|
*
* PQAR1 - priority queue allocation register 1
*
* FIELDS (msb -> lsb)
* (r) PQA
*
\******************************************************************************/
  #define _EDMA_PQAR1_ADDR              0x01A0FFC4u

  #define  EDMA_PQAR1                   EDMA_REG(PQAR1)

  #define _EDMA_PQAR1_PQA_MASK           0x00000007u
  #define _EDMA_PQAR1_PQA_SHIFT          0x00000000u
  #define  EDMA_PQAR1_PQA_DEFAULT        0x00000006u
  #define  EDMA_PQAR1_PQA_OF(x)          _VALUEOF(x)

  #define  EDMA_PQAR1_OF(x)             _VALUEOF(x)
 
  #define EDMA_PQAR1_DEFAULT (uint32)(\
     _PER_FDEFAULT(EDMA,PQAR1,PQA)\
  )

  #define _EDMA_PQAR1_FGET(FIELD)\
    _PER_FGET(_EDMA_PQAR1_ADDR,EDMA,PQAR1,FIELD)

  #define _EDMA_PQAR1_FSET(FIELD,field)\
    _PER_FSET(_EDMA_PQAR1_ADDR,EDMA,PQAR1,FIELD,field)
 
  #define _EDMA_PQAR1_FSETS(FIELD,SYM)\
    _PER_FSETS(_EDMA_PQAR1_ADDR,EDMA,PQAR1,FIELD,##SYM)
 
/******************************************************************************\
* _____________________
* |                   |
* |  P Q A R 2        |
* |___________________|
*
* PQAR2 - priority queue allocation register 2
*
* FIELDS (msb -> lsb)
* (r) PQA
*
\******************************************************************************/
  #define _EDMA_PQAR2_ADDR              0x01A0FFC8u

  #define  EDMA_PQAR2                   EDMA_REG(PQAR2)

  #define _EDMA_PQAR2_PQA_MASK           0x00000007u
  #define _EDMA_PQAR2_PQA_SHIFT          0x00000000u
  #define  EDMA_PQAR2_PQA_DEFAULT        0x00000002u
  #define  EDMA_PQAR2_PQA_OF(x)          _VALUEOF(x)

  #define  EDMA_PQAR2_OF(x)             _VALUEOF(x)

  #define EDMA_PQAR2_DEFAULT (uint32)(\
     _PER_FDEFAULT(EDMA,PQAR2,PQA)\
  )

  #if (!(CHIP_6413 | CHIP_6418 | CHIP_6410))
      #define EDMA_PQAR2_RMK(pqa) (uint32)(\
         _PER_FMK(EDMA,PQAR2,PQA,pqa)\
      )
  #endif

  #define _EDMA_PQAR2_FGET(FIELD)\
    _PER_FGET(_EDMA_PQAR2_ADDR,EDMA,PQAR2,FIELD)

  #define _EDMA_PQAR2_FSET(FIELD,field)\
    _PER_FSET(_EDMA_PQAR2_ADDR,EDMA,PQAR2,FIELD,field)
 
  #define _EDMA_PQAR2_FSETS(FIELD,SYM)\
    _PER_FSETS(_EDMA_PQAR2_ADDR,EDMA,PQAR2,FIELD,##SYM)
 
/******************************************************************************\
* _____________________
* |                   |
* |  P Q A R 3        |
* |___________________|
*
* PQAR3 - priority queue allocation register 3
*
* FIELDS (msb -> lsb)
* (r) PQA
*
\******************************************************************************/
  #define _EDMA_PQAR3_ADDR              0x01A0FFCCu

  #define  EDMA_PQAR3                   EDMA_REG(PQAR3)

  #define _EDMA_PQAR3_PQA_MASK           0x00000007u
  #define _EDMA_PQAR3_PQA_SHIFT          0x00000000u
  #define  EDMA_PQAR3_PQA_DEFAULT        0x00000006u
  #define  EDMA_PQAR3_PQA_OF(x)          _VALUEOF(x)

  #define  EDMA_PQAR3_OF(x)             _VALUEOF(x)

  #define EDMA_PQAR3_DEFAULT (uint32)(\
     _PER_FDEFAULT(EDMA,PQAR3,PQA)\
  )

  #define _EDMA_PQAR3_FGET(FIELD)\
    _PER_FGET(_EDMA_PQAR3_ADDR,EDMA,PQAR3,FIELD)

  #define _EDMA_PQAR3_FSET(FIELD,field)\
    _PER_FSET(_EDMA_PQAR3_ADDR,EDMA,PQAR3,FIELD,field)
 
  #define _EDMA_PQAR3_FSETS(FIELD,SYM)\
    _PER_FSETS(_EDMA_PQAR3_ADDR,EDMA,PQAR3,FIELD,##SYM)

/******************************************************************************\
* _____________________
* |                   |
* |  C I P R          |
* |___________________|
*
* CIPR  - channel interrupt pending register
*
* FIELDS (msb -> lsb)
* (rw) CIP
*
\******************************************************************************/
 #define _EDMA_CIPR_ADDR              0x01A0FFE4u

  #define  EDMA_CIPR                   EDMA_REG(CIPR)

  #define _EDMA_CIPR_CIP_MASK          0xFFFFFFFFu
  #define _EDMA_CIPR_CIP_SHIFT         0x00000000u
  #define  EDMA_CIPR_CIP_DEFAULT       0x00000000u
  #define  EDMA_CIPR_CIP_OF(x)         _VALUEOF(x)

  #define  EDMA_CIPR_OF(x)             _VALUEOF(x)

  #define EDMA_CIPR_DEFAULT (uint32)(\
     _PER_FDEFAULT(EDMA,CIPR,CIP)\
  )

  #define EDMA_CIPR_RMK(cip) (uint32)(\
     _PER_FMK(EDMA,CIPR,CIP,cip)\
  )

  #define _EDMA_CIPR_FGET(FIELD)\
    _PER_FGET(_EDMA_CIPR_ADDR,EDMA,CIPR,##FIELD)

  #define _EDMA_CIPR_FSET(FIELD,field)\
    _PER_FSET(_EDMA_CIPR_ADDR,EDMA,CIPR,##FIELD,field)

  #define _EDMA_CIPR_FSETS(FIELD,SYM)\
    _PER_FSETS(_EDMA_CIPR_ADDR,EDMA,CIPR,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  C I P R L        |
* |___________________|
*
* CIPRL - channel interrupt pending register, low half (1)
*
* (1) - C64x devices only
*
* FIELDS (msb -> lsb)
* (rw) CIP
*
\******************************************************************************/
  #define _EDMA_CIPRL_ADDR              0x01A0FFE4u

  #define  EDMA_CIPRL                   EDMA_REG(CIPRL)

  #define _EDMA_CIPRL_CIP_MASK          0xFFFFFFFFu
  #define _EDMA_CIPRL_CIP_SHIFT         0x00000000u
  #define  EDMA_CIPRL_CIP_DEFAULT       0x00000000u
  #define  EDMA_CIPRL_CIP_OF(x)         _VALUEOF(x)

  #define  EDMA_CIPRL_OF(x)             _VALUEOF(x)

  #define EDMA_CIPRL_DEFAULT (uint32)(\
     _PER_FDEFAULT(EDMA,CIPRL,CIP)\
  )

  #define EDMA_CIPRL_RMK(cip) (uint32)(\
     _PER_FMK(EDMA,CIPRL,CIP,cip)\
  )

  #define _EDMA_CIPRL_FGET(FIELD)\
    _PER_FGET(_EDMA_CIPRL_ADDR,EDMA,CIPRL,##FIELD)

  #define _EDMA_CIPRL_FSET(FIELD,field)\
    _PER_FSET(_EDMA_CIPRL_ADDR,EDMA,CIPRL,##FIELD,field)

  #define _EDMA_CIPRL_FSETS(FIELD,SYM)\
    _PER_FSETS(_EDMA_CIPRL_ADDR,EDMA,CIPRL,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  C I P R H        |
* |___________________|
*
* CIPRH - channel interrupt pending register, high half (1)
*
* (1) - C64x devices only
*
* FIELDS (msb -> lsb)
* (rw) CIP
*
\******************************************************************************/
  #define _EDMA_CIPRH_ADDR              0x01A0FFA4u

  #define  EDMA_CIPRH                   EDMA_REG(CIPRH)

  #define _EDMA_CIPRH_CIP_MASK          0xFFFFFFFFu
  #define _EDMA_CIPRH_CIP_SHIFT         0x00000000u
  #define  EDMA_CIPRH_CIP_DEFAULT       0x00000000u
  #define  EDMA_CIPRH_CIP_OF(x)         _VALUEOF(x)

  #define  EDMA_CIPRH_OF(x)             _VALUEOF(x)

  #define EDMA_CIPRH_DEFAULT (uint32)(\
     _PER_FDEFAULT(EDMA,CIPRH,CIP)\
  )

  #define EDMA_CIPRH_RMK(cip) (uint32)(\
     _PER_FMK(EDMA,CIPRH,CIP,cip)\
  )

  #define _EDMA_CIPRH_FGET(FIELD)\
    _PER_FGET(_EDMA_CIPRH_ADDR,EDMA,CIPRH,##FIELD)

  #define _EDMA_CIPRH_FSET(FIELD,field)\
    _PER_FSET(_EDMA_CIPRH_ADDR,EDMA,CIPRH,##FIELD,field)

  #define _EDMA_CIPRH_FSETS(FIELD,SYM)\
    _PER_FSETS(_EDMA_CIPRH_ADDR,EDMA,CIPRH,##FIELD,##SYM)

/******************************************************************************\
* _____________________
* |                   |
* |  C I E R          |
* |___________________|
*
* CIER - channel interrupt enable register
*
* FIELDS (msb -> lsb)
* (rw) CIE
*
\******************************************************************************/
  #define _EDMA_CIER_ADDR              0x01A0FFE8u

  #define  EDMA_CIER                   EDMA_REG(CIER)

  #define _EDMA_CIER_CIE_MASK          0xFFFFFFFFu
  #define _EDMA_CIER_CIE_SHIFT         0x00000000u
  #define  EDMA_CIER_CIE_DEFAULT       0x00000000u
  #define  EDMA_CIER_CIE_OF(x)         _VALUEOF(x)

  #define  EDMA_CIER_OF(x)             _VALUEOF(x)

  #define EDMA_CIER_DEFAULT (uint32)(\
     _PER_FDEFAULT(EDMA,CIER,CIE)\
  )

  #define EDMA_CIER_RMK(cie) (uint32)(\
     _PER_FMK(EDMA,CIER,CIE,cie)\
  )

  #define _EDMA_CIER_FGET(FIELD)\
    _PER_FGET(_EDMA_CIER_ADDR,EDMA,CIER,##FIELD)

  #define _EDMA_CIER_FSET(FIELD,field)\
    _PER_FSET(_EDMA_CIER_ADDR,EDMA,CIER,##FIELD,field)

  #define _EDMA_CIER_FSETS(FIELD,SYM)\
    _PER_FSETS(_EDMA_CIER_ADDR,EDMA,CIER,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  C I E R L        |
* |___________________|
*
* CIERL - channel interrupt enable register, low half (1)
*
* (1) - C64x devices only
*
* FIELDS (msb -> lsb)
* (rw) CIE
*
\******************************************************************************/
  #define _EDMA_CIERL_ADDR              0x01A0FFE8u

  #define  EDMA_CIERL                   EDMA_REG(CIERL)

  #define _EDMA_CIERL_CIE_MASK          0xFFFFFFFFu
  #define _EDMA_CIERL_CIE_SHIFT         0x00000000u
  #define  EDMA_CIERL_CIE_DEFAULT       0x00000000u
  #define  EDMA_CIERL_CIE_OF(x)         _VALUEOF(x)

  #define  EDMA_CIERL_OF(x)             _VALUEOF(x)

  #define EDMA_CIERL_DEFAULT (uint32)(\
     _PER_FDEFAULT(EDMA,CIERL,CIE)\
  )

  #define EDMA_CIERL_RMK(cie) (uint32)(\
     _PER_FMK(EDMA,CIERL,CIE,cie)\
  )

  #define _EDMA_CIERL_FGET(FIELD)\
    _PER_FGET(_EDMA_CIERL_ADDR,EDMA,CIERL,##FIELD)

  #define _EDMA_CIERL_FSET(FIELD,field)\
    _PER_FSET(_EDMA_CIERL_ADDR,EDMA,CIERL,##FIELD,field)

  #define _EDMA_CIERL_FSETS(FIELD,SYM)\
    _PER_FSETS(_EDMA_CIERL_ADDR,EDMA,CIERL,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  C I E R H        |
* |___________________|
*
* CIERL - channel interrupt enable register, high half (1)
*
* (1) - C64x devices only
*
* FIELDS (msb -> lsb)
* (rw) CIE
*
\******************************************************************************/
  #define _EDMA_CIERH_ADDR              0x01A0FFA8u

  #define  EDMA_CIERH                   EDMA_REG(CIERH)

  #define _EDMA_CIERH_CIE_MASK          0xFFFFFFFFu
  #define _EDMA_CIERH_CIE_SHIFT         0x00000000u
  #define  EDMA_CIERH_CIE_DEFAULT       0x00000000u
  #define  EDMA_CIERH_CIE_OF(x)         _VALUEOF(x)

  #define  EDMA_CIERH_OF(x)             _VALUEOF(x)

  #define EDMA_CIERH_DEFAULT (uint32)(\
     _PER_FDEFAULT(EDMA,CIERH,CIE)\
  )

  #define EDMA_CIERH_RMK(cie) (uint32)(\
     _PER_FMK(EDMA,CIERH,CIE,cie)\
  )

  #define _EDMA_CIERH_FGET(FIELD)\
    _PER_FGET(_EDMA_CIERH_ADDR,EDMA,CIERH,##FIELD)

  #define _EDMA_CIERH_FSET(FIELD,field)\
    _PER_FSET(_EDMA_CIERH_ADDR,EDMA,CIERH,##FIELD,field)

  #define _EDMA_CIERH_FSETS(FIELD,SYM)\
    _PER_FSETS(_EDMA_CIERH_ADDR,EDMA,CIERH,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  C C E R          |
* |___________________|
*
* CCER - channel chain enable register
*
* FIELDS (msb -> lsb)
* (rw) CCE
*
\******************************************************************************/
  #define _EDMA_CCER_ADDR              0x01A0FFECu

  #define  EDMA_CCER                   EDMA_REG(CCER)

  #define _EDMA_CCER_CCE_MASK          0xFFFFFFFFu
  #define _EDMA_CCER_CCE_SHIFT         0x00000000u
  #define  EDMA_CCER_CCE_DEFAULT       0x00000000u
  #define  EDMA_CCER_CCE_OF(x)         _VALUEOF(x)

  #define  EDMA_CCER_OF(x)             _VALUEOF(x)

  #define EDMA_CCER_DEFAULT (uint32)(\
     _PER_FDEFAULT(EDMA,CCER,CCE)\
  )

  #define EDMA_CCER_RMK(cce) (uint32)(\
     _PER_FMK(EDMA,CCER,CCE,cce)\
  )

  #define _EDMA_CCER_FGET(FIELD)\
    _PER_FGET(_EDMA_CCER_ADDR,EDMA,CCER,##FIELD)

  #define _EDMA_CCER_FSET(FIELD,field)\
    _PER_FSET(_EDMA_CCER_ADDR,EDMA,CCER,##FIELD,field)

  #define _EDMA_CCER_FSETS(FIELD,SYM)\
    _PER_FSETS(_EDMA_CCER_ADDR,EDMA,CCER,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  C C E R L        |
* |___________________|
*
* CCERL - channel chain enable register, low half (1)
*
* (1) - C64x devices only
*
* FIELDS (msb -> lsb)
* (rw) CCE
*
\******************************************************************************/
  #define _EDMA_CCERL_ADDR              0x01A0FFECu

  #define  EDMA_CCERL                   EDMA_REG(CCERL)

  #define _EDMA_CCERL_CCE_MASK          0xFFFFFFFFu
  #define _EDMA_CCERL_CCE_SHIFT         0x00000000u
  #define  EDMA_CCERL_CCE_DEFAULT       0x00000000u
  #define  EDMA_CCERL_CCE_OF(x)         _VALUEOF(x)

  #define  EDMA_CCERL_OF(x)             _VALUEOF(x)

  #define EDMA_CCERL_DEFAULT (uint32)(\
     _PER_FDEFAULT(EDMA,CCERL,CCE)\
  )

  #define EDMA_CCERL_RMK(cce) (uint32)(\
     _PER_FMK(EDMA,CCERL,CCE,cce)\
  )

  #define _EDMA_CCERL_FGET(FIELD)\
    _PER_FGET(_EDMA_CCERL_ADDR,EDMA,CCERL,##FIELD)

  #define _EDMA_CCERL_FSET(FIELD,field)\
    _PER_FSET(_EDMA_CCERL_ADDR,EDMA,CCERL,##FIELD,field)

  #define _EDMA_CCERL_FSETS(FIELD,SYM)\
    _PER_FSETS(_EDMA_CCERL_ADDR,EDMA,CCERL,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  C C E R H        |
* |___________________|
*
* CCERH - channel chain enable register, high half (1)
*
* (1) - C64x devices only
*
* FIELDS (msb -> lsb)
* (rw) CCE
*
\******************************************************************************/
  #define _EDMA_CCERH_ADDR              0x01A0FFACu

  #define  EDMA_CCERH                   EDMA_REG(CCERH)

  #define _EDMA_CCERH_CCE_MASK          0xFFFFFFFFu
  #define _EDMA_CCERH_CCE_SHIFT         0x00000000u
  #define  EDMA_CCERH_CCE_DEFAULT       0x00000000u
  #define  EDMA_CCERH_CCE_OF(x)         _VALUEOF(x)

  #define  EDMA_CCERH_OF(x)             _VALUEOF(x)

  #define EDMA_CCERH_DEFAULT (uint32)(\
     _PER_FDEFAULT(EDMA,CCERH,CCE)\
  )

  #define EDMA_CCERH_RMK(cce) (uint32)(\
     _PER_FMK(EDMA,CCERH,CCE,cce)\
  )

  #define _EDMA_CCERH_FGET(FIELD)\
    _PER_FGET(_EDMA_CCERH_ADDR,EDMA,CCERH,##FIELD)

  #define _EDMA_CCERH_FSET(FIELD,field)\
    _PER_FSET(_EDMA_CCERH_ADDR,EDMA,CCERH,##FIELD,field)

  #define _EDMA_CCERH_FSETS(FIELD,SYM)\
    _PER_FSETS(_EDMA_CCERH_ADDR,EDMA,CCERH,##FIELD,##SYM)

/******************************************************************************\
* _____________________
* |                   |
* |  E R              |
* |___________________|
*
* ER - event register
*
* FIELDS (msb -> lsb)
* (r) EVT
*
\******************************************************************************/
  #define _EDMA_ER_ADDR              0x01A0FFF0u

  #define  EDMA_ER                   EDMA_REG(ER)

  #define _EDMA_ER_EVT_MASK          0xFFFFFFFFu
  #define _EDMA_ER_EVT_SHIFT         0x00000000u
  #define  EDMA_ER_EVT_DEFAULT       0x00000000u
  #define  EDMA_ER_EVT_OF(x)         _VALUEOF(x)

  #define  EDMA_ER_OF(x)             _VALUEOF(x)

  #define EDMA_ER_DEFAULT (uint32)(\
     _PER_FDEFAULT(EDMA,ER,EVT)\
  )

  #define _EDMA_ER_FGET(FIELD)\
    _PER_FGET(_EDMA_ER_ADDR,EDMA,ER,##FIELD)

/******************************************************************************\
* _____________________
* |                   |
* |  E R L            |
* |___________________|
*
* ERL - event register, low half (1)
*
* (1) - C64x devices only
*
* FIELDS (msb -> lsb)
* (r) EVT
*
\******************************************************************************/
  #define _EDMA_ERL_ADDR              0x01A0FFF0u

  #define  EDMA_ERL                   EDMA_REG(ERL)

  #define _EDMA_ERL_EVT_MASK          0xFFFFFFFFu
  #define _EDMA_ERL_EVT_SHIFT         0x00000000u
  #define  EDMA_ERL_EVT_DEFAULT       0x00000000u
  #define  EDMA_ERL_EVT_OF(x)         _VALUEOF(x)

  #define  EDMA_ERL_OF(x)             _VALUEOF(x)

  #define EDMA_ERL_DEFAULT (uint32)(\
     _PERL_FDEFAULT(EDMA,ERL,EVT)\
  )

  #define _EDMA_ERL_FGET(FIELD)\
    _PERL_FGET(_EDMA_ERL_ADDR,EDMA,ERL,FIELD)

/******************************************************************************\
* _____________________
* |                   |
* |  E R H            |
* |___________________|
*
* ERH - event register, high half (1)
*
* (1) - C64x devices only
*
* FIELDS (msb -> lsb)
* (r) EVT
*
\******************************************************************************/
  #define _EDMA_ERH_ADDR              0x01A0FFB0u

  #define  EDMA_ERH                   EDMA_REG(ERH)

  #define _EDMA_ERH_EVT_MASK          0xFFFFFFFFu
  #define _EDMA_ERH_EVT_SHIFT         0x00000000u
  #define  EDMA_ERH_EVT_DEFAULT       0x00000000u
  #define  EDMA_ERH_EVT_OF(x)         _VALUEOF(x)

  #define  EDMA_ERH_OF(x)             _VALUEOF(x)

  #define EDMA_ERH_DEFAULT (uint32)(\
     _PERH_FDEFAULT(EDMA,ERH,EVT)\
  )

  #define _EDMA_ERH_FGET(FIELD)\
    _PERH_FGET(_EDMA_ERH_ADDR,EDMA,ERH,FIELD)

/******************************************************************************\
* _____________________
* |                   |
* |  E E R            |
* |___________________|
*
* EER - event enable register
*
* FIELDS (msb -> lsb)
* (rw) EE
*
\******************************************************************************/
  #define _EDMA_EER_ADDR             0x01A0FFF4u

  #define  EDMA_EER                  EDMA_REG(EER)

  #define _EDMA_EER_EE_MASK          0xFFFFFFFFu
  #define _EDMA_EER_EE_SHIFT         0x00000000u
  #define  EDMA_EER_EE_DEFAULT       0x00000000u
  #define  EDMA_EER_EE_OF(x)         _VALUEOF(x)

  #define  EDMA_EER_OF(x)            _VALUEOF(x)

  #define EDMA_EER_DEFAULT (uint32)(\
     _PER_FDEFAULT(EDMA,EER,EE)\
  )

  #define EDMA_EER_RMK(ee) (uint32)(\
     _PER_FMK(EDMA,EER,EE,ee)\
  )

  #define _EDMA_EER_FGET(FIELD)\
    _PER_FGET(_EDMA_EER_ADDR,EDMA,EER,##FIELD)

  #define _EDMA_EER_FSET(FIELD,field)\
    _PER_FSET(_EDMA_EER_ADDR,EDMA,EER,##FIELD,field)

  #define _EDMA_EER_FSETS(FIELD,SYM)\
    _PER_FSETS(_EDMA_EER_ADDR,EDMA,EER,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  E E R L          |
* |___________________|
*
* EERL - event enable register, low half (1)
*
* (1) - C64x devices only
*
* FIELDS (msb -> lsb)
* (rw) EE
*
\******************************************************************************/
  #define _EDMA_EERL_ADDR             0x01A0FFF4u

  #define  EDMA_EERL                  EDMA_REG(EERL)

  #define _EDMA_EERL_EE_MASK          0xFFFFFFFFu
  #define _EDMA_EERL_EE_SHIFT         0x00000000u
  #define  EDMA_EERL_EE_DEFAULT       0x00000000u
  #define  EDMA_EERL_EE_OF(x)         _VALUEOF(x)

  #define  EDMA_EERL_OF(x)            _VALUEOF(x)

  #define EDMA_EERL_DEFAULT (uint32)(\
     _PER_FDEFAULT(EDMA,EERL,EE)\
  )

  #define EDMA_EERL_RMK(ee) (uint32)(\
     _PER_FMK(EDMA,EERL,EE,ee)\
  )

  #define _EDMA_EERL_FGET(FIELD)\
    _PER_FGET(_EDMA_EERL_ADDR,EDMA,EERL,##FIELD)

  #define _EDMA_EERL_FSET(FIELD,field)\
    _PER_FSET(_EDMA_EERL_ADDR,EDMA,EERL,##FIELD,field)

  #define _EDMA_EERL_FSETS(FIELD,SYM)\
    _PER_FSETS(_EDMA_EERL_ADDR,EDMA,EERL,##FIELD,##SYM)

/******************************************************************************\
* _____________________
* |                   |
* |  E E R H          |
* |___________________|
*
* EERH - event enable register, high half (1)
*
* (1) - C64x devices only
*
* FIELDS (msb -> lsb)
* (rw) EE
*
\******************************************************************************/
  #define _EDMA_EERH_ADDR             0x01A0FFB4u

  #define  EDMA_EERH                  EDMA_REG(EERH)

  #define _EDMA_EERH_EE_MASK          0xFFFFFFFFu
  #define _EDMA_EERH_EE_SHIFT         0x00000000u
  #define  EDMA_EERH_EE_DEFAULT       0x00000000u
  #define  EDMA_EERH_EE_OF(x)         _VALUEOF(x)

  #define  EDMA_EERH_OF(x)            _VALUEOF(x)

  #define EDMA_EERH_DEFAULT (uint32)(\
     _PER_FDEFAULT(EDMA,EERH,EE)\
  )

  #define EDMA_EERH_RMK(ee) (uint32)(\
     _PER_FMK(EDMA,EERH,EE,ee)\
  )

  #define _EDMA_EERH_FGET(FIELD)\
    _PER_FGET(_EDMA_EERH_ADDR,EDMA,EERH,##FIELD)

  #define _EDMA_EERH_FSET(FIELD,field)\
    _PER_FSET(_EDMA_EERH_ADDR,EDMA,EERH,##FIELD,field)

  #define _EDMA_EERH_FSETS(FIELD,SYM)\
    _PER_FSETS(_EDMA_EERH_ADDR,EDMA,EERH,##FIELD,##SYM)
/******************************************************************************\
* _____________________
* |                   |
* |  E P R L          |
* |___________________|
*
* EPRL - event polarity register, low half (1)
*
* (1) - C64x devices only
*
* FIELDS (msb -> lsb)
* (rw) EP
*
\******************************************************************************/
  #define _EDMA_EPRL_ADDR             0x01A0FFDCu

  #define  EDMA_EPRL                  EDMA_REG(EPRL)

  #define _EDMA_EPRL_EP_MASK          0xFFFFFFFFu
  #define _EDMA_EPRL_EP_SHIFT         0x00000000u
  #define  EDMA_EPRL_EP_DEFAULT       0x00000000u
  #define  EDMA_EPRL_EP_OF(x)         _VALUEOF(x)

  #define  EDMA_EPRL_OF(x)            _VALUEOF(x)

  #define EDMA_EPRL_DEFAULT (uint32)(\
     _PER_FDEFAULT(EDMA,EPRL,EP)\
  )

  #define EDMA_EPRL_RMK(ep) (uint32)(\
     _PER_FMK(EDMA,EPRL,EP,ep)\
  )

  #define _EDMA_EPRL_FGET(FIELD)\
    _PER_FGET(_EDMA_EPRL_ADDR,EDMA,EPRL,##FIELD)

  #define _EDMA_EPRL_FSET(FIELD,field)\
    _PER_FSET(_EDMA_EPRL_ADDR,EDMA,EPRL,##FIELD,field)

  #define _EDMA_EPRL_FSETS(FIELD,SYM)\
    _PER_FSETS(_EDMA_EPRL_ADDR,EDMA,EPRL,##FIELD,##SYM)
/******************************************************************************\
* _____________________
* |                   |
* |  E E R H          |
* |___________________|
*
* EPRH - event enable register, high half (1)
*
* (1) - C64x devices only
*
* FIELDS (msb -> lsb)
* (rw) EP
*
\******************************************************************************/
  #define _EDMA_EPRH_ADDR             0x01A0FF9Cu

  #define  EDMA_EPRH                  EDMA_REG(EPRH)

  #define _EDMA_EPRH_EP_MASK          0xFFFFFFFFu
  #define _EDMA_EPRH_EP_SHIFT         0x00000000u
  #define  EDMA_EPRH_EP_DEFAULT       0x00000000u
  #define  EDMA_EPRH_EP_OF(x)         _VALUEOF(x)

  #define  EDMA_EPRH_OF(x)            _VALUEOF(x)

  #define EDMA_EPRH_DEFAULT (uint32)(\
     _PER_FDEFAULT(EDMA,EPRH,EP)\
  )

  #define EDMA_EPRH_RMK(ep) (uint32)(\
     _PER_FMK(EDMA,EPRH,EP,ep)\
  )

  #define _EDMA_EPRH_FGET(FIELD)\
    _PER_FGET(_EDMA_EPRH_ADDR,EDMA,EPRH,##FIELD)

  #define _EDMA_EPRH_FSET(FIELD,field)\
    _PER_FSET(_EDMA_EPRH_ADDR,EDMA,EPRH,##FIELD,field)

  #define _EDMA_EPRH_FSETS(FIELD,SYM)\
    _PER_FSETS(_EDMA_EPRH_ADDR,EDMA,EPRH,##FIELD,##SYM)
/******************************************************************************\
* _____________________
* |                   |
* |  E C R            |
* |___________________|
*
* ECR - event clear register
*
* FIELDS (msb -> lsb)
* (rw) EC
*
\******************************************************************************/
  #define _EDMA_ECR_ADDR             0x01A0FFF8u

  #define  EDMA_ECR                  EDMA_REG(ECR)

  #define _EDMA_ECR_EC_MASK          0xFFFFFFFFu
  #define _EDMA_ECR_EC_SHIFT         0x00000000u
  #define  EDMA_ECR_EC_DEFAULT       0x00000000u
  #define  EDMA_ECR_EC_OF(x)         _VALUEOF(x)

  #define  EDMA_EPR_OF(x)            _VALUEOF(x)

  #define EDMA_ECR_DEFAULT (uint32)(\
     _PER_FDEFAULT(EDMA,ECR,EC)\
  )

  #define EDMA_ECR_RMK(ec) (uint32)(\
     _PER_FMK(EDMA,ECR,EC,ec)\
  )

  #define _EDMA_ECR_FGET(FIELD)\
    _PER_FGET(_EDMA_ECR_ADDR,EDMA,ECR,##FIELD)

  #define _EDMA_ECR_FSET(FIELD,field)\
    _PER_FSET(_EDMA_ECR_ADDR,EDMA,ECR,##FIELD,field)

  #define _EDMA_ECR_FSETS(FIELD,SYM)\
    _PER_FSETS(_EDMA_ECR_ADDR,EDMA,ECR,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  E C R L          |
* |___________________|
*
* ECRL - event clear register, low half (1)
*
* (1) - C64x devices only
*
* FIELDS (msb -> lsb)
* (rw) EC
*
\******************************************************************************/
  #define _EDMA_ECRL_ADDR             0x01A0FFF8u

  #define  EDMA_ECRL                  EDMA_REG(ECRL)

  #define _EDMA_ECRL_EC_MASK          0xFFFFFFFFu
  #define _EDMA_ECRL_EC_SHIFT         0x00000000u
  #define  EDMA_ECRL_EC_DEFAULT       0x00000000u
  #define  EDMA_ECRL_EC_OF(x)         _VALUEOF(x)

  #define  EDMA_EER_OF(x)            _VALUEOF(x)

  #define EDMA_ECRL_DEFAULT (uint32)(\
     _PER_FDEFAULT(EDMA,ECRL,EC)\
  )

  #define EDMA_ECRL_RMK(ec) (uint32)(\
     _PER_FMK(EDMA,ECRL,EC,ec)\
  )

  #define _EDMA_ECRL_FGET(FIELD)\
    _PER_FGET(_EDMA_ECRL_ADDR,EDMA,ECRL,##FIELD)

  #define _EDMA_ECRL_FSET(FIELD,field)\
    _PER_FSET(_EDMA_ECRL_ADDR,EDMA,ECRL,##FIELD,field)

  #define _EDMA_ECRL_FSETS(FIELD,SYM)\
    _PER_FSETS(_EDMA_ECRL_ADDR,EDMA,ECRL,##FIELD,##SYM)

/******************************************************************************\
* _____________________
* |                   |
* |  E C R H          |
* |___________________|
*
* ECRH - event clear register, high half (1)
*
* (1) - C64x devices only
*
* FIELDS (msb -> lsb)
* (rw) EC
*
\******************************************************************************/
  #define _EDMA_ECRH_ADDR             0x01A0FFB8u

  #define  EDMA_ECRH                  EDMA_REG(ECRH)

  #define _EDMA_ECRH_EC_MASK          0xFFFFFFFFu
  #define _EDMA_ECRH_EC_SHIFT         0x00000000u
  #define  EDMA_ECRH_EC_DEFAULT       0x00000000u
  #define  EDMA_ECRH_EC_OF(x)         _VALUEOF(x)

  #define  EDMA_EER_OF(x)            _VALUEOF(x)

  #define EDMA_ECRH_DEFAULT (uint32)(\
     _PER_FDEFAULT(EDMA,ECRH,EC)\
  )

  #define EDMA_ECRH_RMK(ec) (uint32)(\
     _PER_FMK(EDMA,ECRH,EC,ec)\
  )

  #define _EDMA_ECRH_FGET(FIELD)\
    _PER_FGET(_EDMA_ECRH_ADDR,EDMA,ECRH,##FIELD)

  #define _EDMA_ECRH_FSET(FIELD,field)\
    _PER_FSET(_EDMA_ECRH_ADDR,EDMA,ECRH,##FIELD,field)

  #define _EDMA_ECRH_FSETS(FIELD,SYM)\
    _PER_FSETS(_EDMA_ECRH_ADDR,EDMA,ECRH,##FIELD,##SYM)

/******************************************************************************\
* _____________________
* |                   |
* |  E S R            |
* |___________________|
*
* ESR - event set register
*
* FIELDS (msb -> lsb)
* (rw) ES
*
\******************************************************************************/
  #define _EDMA_ESR_ADDR             0x01A0FFFCu

  #define  EDMA_ESR                  EDMA_REG(ESR)

  #define _EDMA_ESR_ES_MASK          0xFFFFFFFFu
  #define _EDMA_ESR_ES_SHIFT         0x00000000u
  #define  EDMA_ESR_ES_DEFAULT       0x00000000u
  #define  EDMA_ESR_ES_OF(x)         _VALUEOF(x)

  #define  EDMA_ESR_OF(x)            _VALUEOF(x)

  #define EDMA_ESR_DEFAULT (uint32)(\
     _PER_FDEFAULT(EDMA,ESR,ES)\
  )

  #define EDMA_ESR_RMK(es) (uint32)(\
     _PER_FMK(EDMA,ESR,ES,es)\
  )

  #define _EDMA_ESR_FGET(FIELD)\
    _PER_FGET(_EDMA_ESR_ADDR,EDMA,ESR,##FIELD)

  #define _EDMA_ESR_FSET(FIELD,field)\
    _PER_FSET(_EDMA_ESR_ADDR,EDMA,ESR,##FIELD,field)

  #define _EDMA_ESR_FSETS(FIELD,SYM)\
    _PER_FSETS(_EDMA_ESR_ADDR,EDMA,ESR,##FIELD,##SYM)


/******************************************************************************\
* _____________________
* |                   |
* |  E S R L          |
* |___________________|
*
* ESRL - event set register, low half (1)
*
* (1) - C64x devices only
*
* FIELDS (msb -> lsb)
* (rw) ES
*
\******************************************************************************/
  #define _EDMA_ESRL_ADDR             0x01A0FFFCu

  #define  EDMA_ESRL                  EDMA_REG(ESRL)

  #define _EDMA_ESRL_ES_MASK          0xFFFFFFFFu
  #define _EDMA_ESRL_ES_SHIFT         0x00000000u
  #define  EDMA_ESRL_ES_DEFAULT       0x00000000u
  #define  EDMA_ESRL_ES_OF(x)         _VALUEOF(x)

  #define  EDMA_ESRL_OF(x)            _VALUEOF(x)

  #define EDMA_ESRL_DEFAULT (uint32)(\
     _PER_FDEFAULT(EDMA,ESRL,ES)\
  )

  #define EDMA_ESRL_RMK(es) (uint32)(\
     _PER_FMK(EDMA,ESRL,ES,es)\
  )

  #define _EDMA_ESRL_FGET(FIELD)\
    _PER_FGET(_EDMA_ESRL_ADDR,EDMA,ESRL,##FIELD)

  #define _EDMA_ESRL_FSET(FIELD,field)\
    _PER_FSET(_EDMA_ESRL_ADDR,EDMA,ESRL,##FIELD,field)

  #define _EDMA_ESRL_FSETS(FIELD,SYM)\
    _PER_FSETS(_EDMA_ESRL_ADDR,EDMA,ESRL,##FIELD,##SYM)
/******************************************************************************\
* _____________________
* |                   |
* |  E S R H          |
* |___________________|
*
* ESRH - event set register, high half (1)
*
* (1) - C64x devices only
*
* FIELDS (msb -> lsb)
* (rw) ES
*
\******************************************************************************/
  #define _EDMA_ESRH_ADDR             0x01A0FFBCu

  #define  EDMA_ESRH                  EDMA_REG(ESRH)

  #define _EDMA_ESRH_ES_MASK          0xFFFFFFFFu
  #define _EDMA_ESRH_ES_SHIFT         0x00000000u
  #define  EDMA_ESRH_ES_DEFAULT       0x00000000u
  #define  EDMA_ESRH_ES_OF(x)         _VALUEOF(x)

  #define  EDMA_ESRH_OF(x)            _VALUEOF(x)

  #define EDMA_ESRH_DEFAULT (uint32)(\
     _PER_FDEFAULT(EDMA,ESRH,ES)\
  )

  #define EDMA_ESRH_RMK(es) (uint32)(\
     _PER_FMK(EDMA,ESRH,ES,es)\
  )

  #define _EDMA_ESRH_FGET(FIELD)\
    _PER_FGET(_EDMA_ESRH_ADDR,EDMA,ESRH,##FIELD)

  #define _EDMA_ESRH_FSET(FIELD,field)\
    _PER_FSET(_EDMA_ESRH_ADDR,EDMA,ESRH,##FIELD,field)

  #define _EDMA_ESRH_FSETS(FIELD,SYM)\
    _PER_FSETS(_EDMA_ESRH_ADDR,EDMA,ESRH,##FIELD,##SYM)
/*----------------------------------------------------------------------------*/
#endif /* _OS_CSL_EDMAHAL_H_ */


#ifndef _OS_CSL_EDMA_H_
#define _OS_CSL_EDMA_H_

/******************************************************************************\
* global macro declarations
\******************************************************************************/
#define EDMA_CHA_CNT              (_EDMA_CHA_CNT)
#define EDMA_TABLE_CNT            (_EDMA_LINK_CNT)
#define EDMA_ALLOC_ANY            (-1)

#define EDMA_OPEN_RESET           (0x00000001)
#define EDMA_OPEN_ENABLE          (0x00000002)

#if (CHIP_6416)
  #define EDMA_CHA_ANY      -1
  #define EDMA_CHA_DSPINT    0
  #define EDMA_CHA_TINT0     1
  #define EDMA_CHA_TINT1     2
  #define EDMA_CHA_SDINT     3
  #define EDMA_CHA_EXTINT4   4
  #define EDMA_CHA_GPINT4    4
  #define EDMA_CHA_EXTINT5   5
  #define EDMA_CHA_GPINT5    5
  #define EDMA_CHA_EXTINT6   6
  #define EDMA_CHA_GPINT6    6
  #define EDMA_CHA_EXTINT7   7
  #define EDMA_CHA_GPINT7    7
  #define EDMA_CHA_TCC8      8
  #define EDMA_CHA_GPINT0    8
  #define EDMA_CHA_TCC9      9
  #define EDMA_CHA_GPINT1    9
  #define EDMA_CHA_TCC10    10
  #define EDMA_CHA_GPINT2   10
  #define EDMA_CHA_TCC11    11
  #define EDMA_CHA_GPINT3   11
  #define EDMA_CHA_XEVT0    12
  #define EDMA_CHA_REVT0    13
  #define EDMA_CHA_XEVT1    14
  #define EDMA_CHA_REVT1    15

/* Individual mappings for next few events are specified under #ifdefs below. */

  #define EDMA_CHA_GPINT8   48
  #define EDMA_CHA_GPINT9   49
  #define EDMA_CHA_GPINT10  50
  #define EDMA_CHA_GPINT11  51
  #define EDMA_CHA_GPINT12  52
  #define EDMA_CHA_GPINT13  53
  #define EDMA_CHA_GPINT14  54
  #define EDMA_CHA_GPINT15  55
#endif


#if (CHIP_6416 )
  #define EDMA_CHA_XEVT2    17
  #define EDMA_CHA_REVT2    18
  #define EDMA_CHA_TINT2    19
  #define EDMA_CHA_SDINTB   20
  #define EDMA_CHA_PCI      21
  #define EDMA_CHA_VCPREVT  28
  #define EDMA_CHA_VCPXEVT  29
  #define EDMA_CHA_TCPREVT  30
  #define EDMA_CHA_TCPXEVT  31
  #define EDMA_CHA_UREVT    32
  #define EDMA_CHA_UREVT0   32
  #define EDMA_CHA_UREVT1   33
  #define EDMA_CHA_UREVT2   34
  #define EDMA_CHA_UREVT3   35
  #define EDMA_CHA_UREVT4   36
  #define EDMA_CHA_UREVT5   37
  #define EDMA_CHA_UREVT6   38
  #define EDMA_CHA_UREVT7   39
  #define EDMA_CHA_UXEVT    40
  #define EDMA_CHA_UXEVT0   40
  #define EDMA_CHA_UXEVT1   41
  #define EDMA_CHA_UXEVT2   42
  #define EDMA_CHA_UXEVT3   43
  #define EDMA_CHA_UXEVT4   44
  #define EDMA_CHA_UXEVT5   45
  #define EDMA_CHA_UXEVT6   46
  #define EDMA_CHA_UXEVT7   47
#endif

#if defined(CHIP_6412)
  #define EDMA_CHA_ANY      -1

  #define EDMA_CHA_DSPINT   0

  #define EDMA_CHA_TINT0    1
  #define EDMA_CHA_TINT1    2
  #define EDMA_CHA_SDINT    3
  #define EDMA_CHA_EXTINT4  4
  #define EDMA_CHA_GPINT4   4
  #define EDMA_CHA_EXTINT5  5
  #define EDMA_CHA_GPINT5   5
  #define EDMA_CHA_EXTINT6  6
  #define EDMA_CHA_GPINT6   6
  #define EDMA_CHA_EXTINT7  7
  #define EDMA_CHA_GPINT7   7
  #define EDMA_CHA_GPINT0   8
  #define EDMA_CHA_TCC8     8
  #define EDMA_CHA_GPINT1   9
  #define EDMA_CHA_TCC9     9
  #define EDMA_CHA_GPINT2   10
  #define EDMA_CHA_TCC10    10
  #define EDMA_CHA_GPINT3   11
  #define EDMA_CHA_TCC11    11
  #define EDMA_CHA_XEVT0    12
  #define EDMA_CHA_REVT0    13
  #define EDMA_CHA_XEVT1    14
  #define EDMA_CHA_REVT1    15
  #define EDMA_CHA_TINT2    19
  #define EDMA_CHA_ICREVT0  44
  #define EDMA_CHA_ICXEVT0  45
  #define EDMA_CHA_GPINT8   48
  #define EDMA_CHA_GPINT9   49
  #define EDMA_CHA_GPINT10  50
  #define EDMA_CHA_GPINT11  51
  #define EDMA_CHA_GPINT12  52
  #define EDMA_CHA_GPINT13  53
  #define EDMA_CHA_GPINT14  54
  #define EDMA_CHA_GPINT15  55
#endif

#define _EDMA_TYPE_C   (0x80000000)
#define _EDMA_TYPE_T   (0x40000000)
#define _EDMA_TYPE_Q   (0x20000000)
#define _EDMA_TYPE_S   (0x10000000)


#define _EDMA_MK_HANDLE(base,index,flags) (EDMA_Handle)(\
  ((base)&0x0000FFFF)|(((index)<<16)&0x00FF0000)|((flags)&0xFF000000)\
)

#define EDMA_HQDMA    _EDMA_MK_HANDLE(0x00000000,0,_EDMA_TYPE_Q)
#define EDMA_HQSDMA   _EDMA_MK_HANDLE(0x00000000,0,_EDMA_TYPE_S)
#define EDMA_HINV     _EDMA_MK_HANDLE(0x00000000,0,0)

#define EDMA_HNULL    _EDMA_MK_HANDLE(_EDMA_NULL_PARAM,0,_EDMA_TYPE_T)
#define NULL_FUNC     0

/* Priority Queues */
#define EDMA_Q0       0
#define EDMA_Q1       1
#define EDMA_Q2       2
#define EDMA_Q3       3

/* Event Polarity */
#define EDMA_EVT_LOWHIGH   0
#define EDMA_EVT_HIGHLOW   1

/* Chaining Flag */
#define EDMA_TCC_SET       1
#define EDMA_ATCC_SET      1

/******************************************************************************\
* global typedef declarations
\******************************************************************************/
typedef uint32 EDMA_Handle;

typedef struct {
  uint32 opt;
  uint32 src;
  uint32 cnt;
  uint32 dst;
  uint32 idx;
  uint32 rld;
} EDMA_Config;

typedef void (*EDMA_IntHandler)(int tccNum);

/******************************************************************************\
* global variable declarations
\******************************************************************************/
#define EDMA_hNull EDMA_HNULL

/******************************************************************************\
* global function declarations
\******************************************************************************/
extern void EDMA_reset(EDMA_Handle hEdma);
extern void EDMA_resetAll();

extern EDMA_Handle EDMA_open(int chaNum, uint32 flags);
extern void EDMA_close(EDMA_Handle hEdma);
extern EDMA_Handle EDMA_allocTable(int tableNum);
extern void EDMA_freeTable(EDMA_Handle hEdma);

extern int EDMA_allocTableEx(int cnt, EDMA_Handle *array);
extern void EDMA_freeTableEx(int cnt, EDMA_Handle *array);

extern void EDMA_clearPram(uint32 val);

extern int EDMA_intAlloc(int tcc);
extern void EDMA_intFree(int tcc);

extern EDMA_IntHandler EDMA_intHook(int tccNum, EDMA_IntHandler funcAddr);
extern void EDMA_intDefaultHandler(int tccNum);
extern void EDMA_intDispatcher();

extern uint32 EDMA_getScratchAddr();
extern uint32 EDMA_getScratchSize();
extern uint32 EDMA_getPriQStatus();
extern void   EDMA_setPriQLength(uint32 priNum, uint32 length);
extern void   EDMA_resetPriQLength(uint32 priNum);

extern void   EDMA_enableChannel(EDMA_Handle hEdma);
extern void   EDMA_disableChannel(EDMA_Handle hEdma);
extern void   EDMA_setChannel(EDMA_Handle hEdma);
extern uint32 EDMA_getChannel(EDMA_Handle hEdma);
extern void   EDMA_clearChannel(EDMA_Handle hEdma);
extern void   EDMA_setEvtPolarity(EDMA_Handle hEdma,int polarity);
extern uint32 EDMA_getTableAddress(EDMA_Handle hEdma);

extern void   EDMA_intEnable(uint32 tccIntNum);
extern void   EDMA_intDisable(uint32 tccIntNum);
extern void   EDMA_intClear(uint32 tccIntNum);
extern uint32 EDMA_intTest(uint32 tccIntNum);
extern void   EDMA_intReset(uint32 tccIntNum);
extern void   EDMA_intResetAll();

extern void   EDMA_link(EDMA_Handle parent, EDMA_Handle child);

extern void EDMA_config(EDMA_Handle hEdma, EDMA_Config *config);
extern void EDMA_configArgs(EDMA_Handle hEdma, uint32 opt, uint32 src, uint32 cnt, uint32 dst, uint32 idx, uint32 rld);
extern void EDMA_getConfig(EDMA_Handle hEdma, EDMA_Config *config);

extern void EDMA_qdmaConfig(EDMA_Config *config);
extern void EDMA_qdmaConfigArgs(uint32 opt, uint32 src, uint32 cnt, uint32 dst, uint32 idx);
extern void EDMA_qdmaGetConfig(EDMA_Config *config);

extern void EDMA_enableChaining(EDMA_Handle hEdma);
extern void EDMA_disableChaining(EDMA_Handle hEdma);
extern void EDMA_chain(EDMA_Handle parent, EDMA_Handle nextChannel,int tccflag, int atccflag);

#endif /* _OS_CSL_EDMA_H_ */


extern far uint32 _lmbd(uint32 src1, uint32 src2);

extern uint32 rts_edma__allocMaskCL;
extern uint32 rts_edma__allocMaskCH;
extern uint32 rts_edma__allocMaskT[4];
extern uint8 rts_edma__tccAllocTable[64];

#endif
