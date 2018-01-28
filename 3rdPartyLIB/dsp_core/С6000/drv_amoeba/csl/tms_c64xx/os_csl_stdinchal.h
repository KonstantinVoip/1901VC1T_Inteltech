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

