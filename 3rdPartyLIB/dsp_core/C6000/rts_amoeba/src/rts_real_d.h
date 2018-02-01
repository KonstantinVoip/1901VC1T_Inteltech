/****************************************************************************/
/*  realdi.h         v5.1.0                                                 */
/*  Copyright (c) 1997-2005  Texas Instruments Incorporated                 */
/****************************************************************************/
 
/* This source automatically generated on Wed Aug  2 15:53:41 CDT 2000 */
 
#ifndef __realdi__
#define __realdi__

#include <limits.h>
#include <math.h>

#endif

/****************************************************************************/
/*  c60_64.h         v5.1.0                                                 */
/*  Copyright (c) 1997-2005  Texas Instruments Incorporated                 */
/****************************************************************************/
 
/* This source automatically generated on Wed Aug  2 15:55:33 CDT 2000 */
 
#ifndef __c60_64__
#define __c60_64__
#if 0
/*---------------------------------------------------------------------------*/
/* C60-specific 64-bit REAL (and other) behavior descriptions.               */
/*---------------------------------------------------------------------------*/
#endif

#ifndef _TMS320C6x
  #define _TMS320C6x 1
#endif

#define Adds_Per_Add  1  /* ratio of REAL add  to add*/
#define Adds_Per_Mult 10 /* ratio of REAL mult to add */
#define Adds_Per_Div  50 /* ratio of REAL div  to add */

#define FLT_FIX_Faster_Than_MODF 0 /* (double)((int)(x)) faster than MODFF */

#define Floating_Sub_Has_Guard_Digit 0 /* safe value is 0 */

#undef Support_DENORM     /* do not support denormalized numbers            */
#undef Support_INFNAN     /* do not support INFINITY's and NAN's            */
#undef Support_SATURATION /* do not saturate overflows to MOST_POS,MOST_NEG */

#define INT_MOST_POS_P1 CNST( 2147483648.0) /* most pos int +1 as REAL */
#define INT_MOST_NEG    CNST(-2147483648.0) /* most neg int    as REAL */

#define BPAU 8        /* bits per Addressable Unit                  */
#define BPchar 8      /* bits per char                              */
#define BPshrt 16     /* bits per short                             */
#define BPint 32      /* bits per int                               */
#define BPlong 40     /* bits per long (0 if not supported)         */
#define BPlonglong 64 /* bits per long long (0 if not supported)    */
#define BPREAL 64     /* bits per REAL when in MEMORY               */
#define BPLEAN 32     /* bits per next smallest REAL when in MEMORY */


#ifndef _LITTLE_ENDIAN
   #ifdef _BIG_ENDIAN
      #define _LITTLE_ENDIAN !(_BIG_ENDIAN)
   #endif
#endif

#define MSB_In_Hi_Addr _LITTLE_ENDIAN /* ENDIANness. 0=big, 1=little */

#define IEEE_Hardware _TMS320C6700 /* 1 if IEEE hardware present */

#if 0
/*---------------------------------------------------------------------------*/
/* Pick the integer size on top of which REAL is to be implemented.          */
/*---------------------------------------------------------------------------*/
#endif

#if ((1) || (BPint==BPREAL)) /* for c60, always pick int */
   #define BPbigint BPint
   #define bigint int
   #define biguns unsigned
#elif (BPint >= BPlong)
   #define BPbigint BPint
   #define bigint int
   #define biguns unsigned
#elif (BPlong==BPREAL)
   #define BPbigint BPlong
   #define bigint long
   #define biguns unsigned long
#else
   #define BPbigint BPlong
   #define bigint long
   #define biguns unsigned long
#endif

biguns _lmbd (biguns, biguns);
#define COUNT_LZERO(nnn) _lmbd(1, nnn)

#define Pointers_Might_Not_Work 1

#endif
/****************************************************************************/
/*  formi64.h        v5.1.0                                                 */
/*  Copyright (c) 1997-2005  Texas Instruments Incorporated                 */
/****************************************************************************/
 
/* This source automatically generated on Wed Aug  2 15:55:34 CDT 2000 */
 
#ifndef __formi64__
#define __formi64__

#if 0
/*---------------------------------------------------------------------------*/
/* Description of the IEEE 64-bit float format.                              */
/*                                                                           */
/* This file is used in conjunction with the c pre-processor to build        */
/* customized product sources.  It is carefully constructed so that comments */
/* are removed by the preprocessor and all expansions result in a minimum    */
/* disruption of surrounding code.                                           */
/*                                                                           */
/* All floating-point constants in this file must be expressed either        */
/* exactly or to *MORE* places than REAL_DIGITS (REAL_DIGITS+3 is suggested).*/
/*---------------------------------------------------------------------------*/
#endif

#if 0
/*---------------------------------------------------------------------------*/
/* REAL is described in terms of the canonical form:  +/- f * r**e           */
/* where: r is "radix",                                                      */
/*        e is "exponent" (an integer),                                      */
/*        f is fractional part (mantissa) and  1/r <= f < 1,                 */
/*---------------------------------------------------------------------------*/
#endif

#define REAL_RADIX     2  /* radix (r)                                 */
#define REAL_MANTISSA 53  /* radix digits in mantissa                  */
#define REAL_EMAX   1024  /* max e for which +/- f has MANTISSA digits */
#define REAL_EMIN (-1021) /* min e for which +/- f has MANTISSA digits */
#define REAL_DIGITS   15  /* FLRF(REAL_MANTISSA-1)*Ln_RADIX/Ln_10)     */
                                
#if 0
/*---------------------------------------------------------------------------*/
/* Round to even is no longer supported.  The C99 spec says that halfway     */
/* cases should be rounded away from 0.                                      */
/*---------------------------------------------------------------------------*/
#define Round_To_Even
#endif

#define IEEE /* don't define "IEEE" at all if not ieee format */

#if defined(Generate_Sources)
   #define if_IEEE_Hardware #ifdef IEEE_Hardware
   #define elsif_not_IEEE_Hardware #else
   #define endif_IEEE_Hardware #endif
#elif defined(IEEE_Hardware)
   #define if_IEEE_Hardware if (IEEE_Hardware) {
   #define elsif_not_IEEE_Hardware } else {
   #define endif_IEEE_Hardware }
#else
   #define if_IEEE_Hardware if (0) {
   #define elsif_not_IEEE_Hardware } else {
   #define endif_IEEE_Hardware }
#endif

#define REAL_EXP_BITS 11   /* bits in unsigned_exp_field                    */
#define REAL_FRC_BITS 52   /* bits in fraction_field                        */
#define REAL_EXP_BIAS 1023 /* exponent = unsigned_exp_field - REAL_EXP_BIAS */

#if BPLEAN==0 /* no next-smaller REAL */
   #undef LEAN_DIGITS
   #undef LEAN_EXP_BITS
   #undef LEAN_FRC_BITS
   #undef LEAN_EXP_BIAS

#elif BPLEAN==32 /* shape of next-smaller REAL (for grow/slim routines) */

   #define LEAN_DIGITS 6
#define LEAN_EXP_BITS 8   /* bits in unsigned_exp_field                */
#define LEAN_FRC_BITS 23  /* bits in fraction_field                    */
#define LEAN_EXP_BIAS 127 /* exponent=unsigned_exp_field-LEAN_EXP_BIAS */

#else
   #error "LEAN_* not yet defined for this size LEAN"
#endif

#if 0
/*---------------------------------------------------------------------------*/
/* Absolute extremes of floating point range.                                */
/* f need not have full MANTISSA digits, but do not                          */
/* include consideration of NAN's, ZEROs, infinities.                        */
/* Express to *MORE* places than REAL_DIGITS.                                */
/*---------------------------------------------------------------------------*/
#endif
#define REAL_MOST_POS  CNST( 1.7976931348623157e+308)
#define REAL_MOST_NEG  CNST(-1.7976931348623157e+308)

#ifdef Support_DENORM
#define REAL_LEAST_POS CNST( 4.9406564584124654e-324) /* denormalized */
#define REAL_LEAST_NEG CNST(-4.9406564584124654e-324) /* denormalized */
   #define LEAST_POS_INVERTABLE_NOT_LEAST_POS 1
#else
   #define REAL_LEAST_POS CNST( 2.225073858507201383e-308)
   #define REAL_LEAST_NEG CNST(-2.225073858507201383e-308)
   #define LEAST_POS_INVERTABLE_NOT_LEAST_POS 0
#endif

#define REAL_LEAST_POS_INVERTABLE CNST(2.225073858507201383e-308)
/* usually (-EMIN<EMAX) ? RADIX**(EMIN-1) : 1/MOST_POS */

#if 0
/*---------------------------------------------------------------------------*/
/* Constants derived from RADIX & MANTISSA needed for math.h routines.       */
/* Express to *MORE* places than REAL_DIGITS.                                */
/*---------------------------------------------------------------------------*/
#endif

#define RADIX                    CNST( 2.0) /* FLTIF(REAL_RADIX   )*/
#define MANTISSA                 CNST(53.0) /* FLTIF(REAL_MANTISSA)*/

#define Ln_RADIX                 Ln_2   /* ln(RADIX)  */
#define Sqrt_RADIX               Sqrt_2 /* sqrt(RADIX)*/

#define RADIX_to(x)              SCLF(ONE,x) /* RADIX**x, x an integer       */

#define RADIX_to_Hlf_MANTISSA_M1 CNST(33554432.0) /* RADIX**((MANTISSA/2)-1)  */
#define RADIX_to_Hlf_MANTISSA_M2 CNST(16777216.0) /* RADIX**((MANTISSA/2)-2)  */
#define RADIX_to_Hlf_MANTISSA    CNST(67108864.0) /* RADIX**( MANTISSA/2   )  */
#define RADIX_to_MANTISSA        CNST(9007199254740992.0) /* RADIX**MANTISSA */

#define One_Over_RADIX          CNST(0.5)                       /* RDX**(-1    )*/
#define RADIX_to_M_Hlf_MANTISSA CNST(1.490116119384765625e-08)  /* RDX**(-MNT/2)*/
#define RADIX_to_One_M_MANTISSA CNST(2.220446049250313081e-16)  /* RDX**(1-MNT )*/
#define RADIX_to_M_MANTISSA     CNST(1.110223024625156540e-16)  /* RDX**( -MNT )*/
#define RADIX_to_EMIN           CNST(4.450147717014402766e-308) /* RDX**(EMIN ) */

#ifndef BPint
   #error "target props .h file must be included before REAL format .h file"
#endif

#define RND_GLITCH ((REAL_MANTISSA+1) <= BPint)
#define RND_P_GLITCH RADIX_to_MANTISSA
#define RND_M_GLITCH CNST(-9007199254740991.0) /* -(RADIX**MANTISSA-1) */

#define SQRT_Sz_Newtons  3 /* (int)FLOOR(LOG2((MANTISSA-1)/5))  */
#define SQRT_CW_Newtons  4 /* (int)CEIL (LOG2( MANTISSA     ))-2*/

#define EXP_Max CNST(7.097827128933838594e+02)  /* ln(MOST_POS )*(1-RDX**-MNT) */
#define EXP_Min CNST(-7.077032713517040747e+02) /* ln(RDX**EMIN)*(1-RDX**-MNT) */

#define POW_Ovfl CNST( 11355.0) /* FLOOR(16*ln(MOST_POS)-1)   */
#define POW_Unfl CNST(-11323.0) /* FLOOR(16*ln(RADIX**EMIN)+1)*/

#define TANH_Max CNST(1.906154746539849754e+01) /* (Ln_2+(MNT+1)*Ln_RADIX)/2   */

#endif
/****************************************************************************/
/*  numconst.h       v5.1.0                                                 */
/*  Copyright (c) 1997-2005  Texas Instruments Incorporated                 */
/****************************************************************************/
 
/* This source automatically generated on Wed Aug  2 15:55:36 CDT 2000 */
 
#ifndef __numconst__
#define __numconst__

#if 0
/*---------------------------------------------------------------------------*/
/* Numerical Constants                                                       */
/*---------------------------------------------------------------------------*/
/* Most of the following constants are taken from                            */
/* "Standard Mathematical Tables", (18th edition, 1970),                     */
/* Editor-In-Chief: Samuel M. Selby Ph.D. Sc.D.,                             */
/* The Chemical Rubber Co. 18901 Cranwood Parkway, Cleveland, Ohio 44128.    */
/* Page 6.                                                                   */
/*---------------------------------------------------------------------------*/
/* The following conventions are used:                                       */
/* Ln  = "log base e"                                                        */
/* Log = "log base 10"                                                       */
/*                                                                           */
/* compile-time division is avoided in favor of multiplication.              */
/*---------------------------------------------------------------------------*/



/*---------------------------------------------------------------------------*/
/* Common values.                                                            */
/*---------------------------------------------------------------------------*/
#endif

#define ZERO      CNST(0.0)
#define SIXTEENTH CNST(0.0625)
#define EIGHTH    CNST(0.125)
#define TENTH     CNST(0.1)
#define QUARTER   CNST(0.25)
#define THIRD     CNST(0.3333333333333333333333333333333333333333333333333)
#define HALF      CNST(0.5)
#define ONE       CNST(1.0)
#define TWO       CNST(2.0)
#define THREE     CNST(3.0)
#define FOUR      CNST(4.0)
#define SIX       CNST(6.0)
#define TEN       CNST(10.0)
#define SIXTEEN   CNST(16.0)

#define M_ONE     CNST(-1.0)
#define M_TWO     CNST(-2.0)


#if 0
/*---------------------------------------------------------------------------*/
/* PI constants                                                              */
/*---------------------------------------------------------------------------*/
#endif
#define Pi          CNST(3.14159265358979323846264338327950288419716939937510)
#define Two_Pi      (MPYF(Pi,TWO))
#define One_Over_Pi CNST(0.31830988618379067153776752674502872406891929148091)
#define Two_Over_Pi (MPYF(TWO,One_Over_Pi))

#define Pi_Over_Two   (MPYF(Pi,HALF))
#define Pi_Over_Three (DIVF(Pi,CNST(3.0)))
#define Pi_Over_Four  (MPYF(Pi,CNST(0.25)))
#define Pi_Over_Six   (MPYF(Pi_Over_Three,HALF))

#define Pi_Squared   CNST(9.86960440108935861883449099987615113531369940724079)
#define Ln_Pi        CNST(1.14472988584940017414342735135305871164729481291531)
#define Log_Pi       CNST(0.49714987269413385435126828829089887365167832438044)
#define Log_Sqrt_Two_Pi CNST(0.39908993417905752478250359150769595020993410292127)


#if 0
/*---------------------------------------------------------------------------*/
/* Constants Involving e                                                     */
/*---------------------------------------------------------------------------*/
#endif
#define Naperian_e CNST(2.71828182845904523536028747135266249775724709369995)
#define One_Over_e CNST(0.36787944117144232159552377016146086744581113103176)

#define e_Squared CNST(7.38905609893065022723042746057500781318031557055184)

#define Ln_10 CNST(2.30258509299404568401799145468436420760110148862877)
#define One_Over_Log_e Ln_10

#define One_Over_Ln_10 CNST(0.43429448190325182765112891891660508229439700580366)
#define Log_e One_Over_Ln_10


#if 0
/*---------------------------------------------------------------------------*/
/* Pi**e and e**Pi Constants                                                 */
/*---------------------------------------------------------------------------*/
#endif
#define Pi_To_e            CNST(22.4591577183610454734271522) 
#define e_To_Pi            CNST(23.1406926327792690057290864)
#define e_To_Minus_Pi      CNST( 0.0432139182637722497744177)
#define e_To_Hlf_Pi        CNST( 4.8104773809653516554730357)
#define e_To_Minus_Hlf_Pi  CNST( 0.2078795763507619085469556)


#if 0
/*---------------------------------------------------------------------------*/
/* Numerical Constants                                                       */
/*---------------------------------------------------------------------------*/
#endif
#define Sqrt_2       CNST(1.41421356237309504880168872420969807856967187537694)
#define Cube_Root_2  CNST(1.25992104989487316476721060727822835057025146470150)
#define One_Over_Sqrt_2 CNST(0.70710678118654752440)
#define Ln_2         CNST(0.69314718055994530941723212145817656807550013436025)
#define One_Over_Ln_2 CNST(1.44269504088896340735)
#define Log_2        CNST(0.30102999566398119521373889472449302676818988146210)
#define Sqrt_3       CNST(1.73205080756887729352744634150587236694280525381038)

#define Cube_Root_3  CNST(1.44224957030740838232163831078010958839186925349935)
#define Ln_3         CNST(1.09861228866810969139524523692252570464749055782274)
#define Log_3        CNST(0.47712125471966243729502790325511530920012886419069)


#if 0
/*---------------------------------------------------------------------------*/
/* Other Constants                                                           */
/*---------------------------------------------------------------------------*/
#endif
#define Gamma     CNST( 0.57721566490153286061) // Euler's Constant 
#define Ln_Gamma  CNST(-0.54953931298164482234)

#define Phi CNST(1.618033988749894848204586834365638117720309180) // Gold Ratio

#endif /* __numconst__*/
/****************************************************************************/
/*  syntdi.h         v5.1.0                                                 */
/*  Copyright (c) 1997-2005  Texas Instruments Incorporated                 */
/****************************************************************************/
 
/* This source automatically generated on Wed Aug  2 15:53:43 CDT 2000 */
 
#ifndef __syntd__
#define __syntd__

#if 0
/*---------------------------------------------------------------------------*/
/* Bind abstract REAL to "double" syntax.                                    */
/* Use ANSI-style function calls for IEEE +,-,*,/, >,<,>=,<=,==,!=, =        */
/* Use d-suffix names for experimental math.h routines (sqrtd, sind, ... etc)*/
/*---------------------------------------------------------------------------*/
#endif

#define REAL double
#define EXPONENT_TYPE int

#if BPLEAN == 0
   #undef LEAN
#else /*  since REAL is "double", assume next smallest is "float" */
   #define LEAN float
#endif

#define CNST(x) (x)  /*  constants within statements */
#define TSNC
#define KNST(x) x    /*  constants within tables     */
#define TSNK

#if 0
/*---------------------------------------------------------------------------*/
/* Define Compiler Syntax For Basic Operations                               */
/*---------------------------------------------------------------------------*/
/* Names have form: <operation> F { 1 | 2 | 3 }?                             */
/* Where <operation> is one of:                                              */
/*    CPY  -- simple assignment                                              */
/*    NEG  -- negative                                                       */
/*    ABS  -- absolute value                                                 */
/*    SQR  -- square                                                         */
/*    INV  -- inverse (1/x)                                                  */
/*    ADD  -- plus                                                           */
/*    SUB  -- subtract                                                       */
/*    MPY  -- multiply                                                       */
/*    DIV  -- division                                                       */
/*    EQL  -- ==                                                             */
/*    NEQ  -- !=                                                             */
/*    GTR  -- >                                                              */
/*    GEQ  -- >=                                                             */
/*    LSS  -- <                                                              */
/*    LEQ  -- <=                                                             */
/*    EQZ  -- == 0.0                                                         */
/*    NEZ  -- != 0.0                                                         */
/*    GTZ  -- >  0.0                                                         */
/*    GEZ  -- >= 0.0                                                         */
/*    LSZ  -- <  0.0                                                         */
/*    LEZ  -- <= 0.0                                                         */
/* F means REAL                                                              */
/* If no 1,2 or 3 suffix then is function returning result.                  */
/* Optional 1,2 or 3 means 1-addr, 2-addr or 3-addr version:                 */
/*    1 -> right = operation right;                                          */
/*    2 -> dst   = operation right;      ( unary operations)                 */
/*         left  = left operation right; (binary operations)                 */
/*    3 -> dst   = left operation right;                                     */
/*---------------------------------------------------------------------------*/
#endif

#define CPYF(dst,right) dst=(right)

#define NEGF(right) _negd(right)
#define ABSF(right) _absd(right)
#define SQRF(right) MPYF(right,right)
#define INVF(right) DIVF(ONE,right)

#define ADDF(left,right) _addd(left,right)
#define SUBF(left,right) _subd(left,right)
#define MPYF(left,right) _mpyd(left,right)
#define DIVF(left,right) _divd(left,right)

#define NEGF2(dst,right) dst=NEGF(right)
#define ABSF2(dst,right) dst=ABSF(right)
#define SQRF2(dst,right) dst=MPYF(right,right)
#define INVF2(dst,right) dst=INVF(right)

#define ADDF3(dst,left,right) dst=ADDF(left,right)
#define SUBF3(dst,left,right) dst=SUBF(left,right)
#define MPYF3(dst,left,right) dst=MPYF(left,right)
#define DIVF3(dst,left,right) dst=DIVF(left,right)

#define NEGF1(right) (right)=NEGF(right)
#define ABSF1(right) (right)=ABSF(right)
#define SQRF1(right) (right)=MPYF(right,right)
#define INVF1(right) (right)=INVF(right)

#define ADDF2(left,right) (left)=ADDF(left,right)
#define SUBF2(left,right) (left)=SUBF(left,right)
#define RSBF2(left,right) (left)=SUBF(right,left)
#define MPYF2(left,right) (left)=MPYF(left,right)
#define DIVF2(left,right) (left)=DIVF(left,right)

#define EQLF(left,right) (_eqld(left,right))
#define NEQF(left,right) (_neqd(left,right))
#define LEQF(left,right) (_leqd(left,right))
#define GEQF(left,right) (_geqd(left,right))
#define LSSF(left,right) (_lssd(left,right))
#define GTRF(left,right) (_gtrd(left,right))

#define CMPF(left,right) _cmpd(left,right) /*  <0 if LT, 0 if EQ, >0 if GT */
#define CMPF3(dst,left,right) dst=CMPF(left,right)

#define EQZF(left) EQLF(left,ZERO)
#define NEZF(left) NEQF(left,ZERO)
#define LEZF(left) LEQF(left,ZERO)
#define GTZF(left) GTRF(left,ZERO)

   #define GEZF(left) GEQF(left,ZERO)
   #define LSZF(left) LSSF(left,ZERO)

#if 0
/*---------------------------------------------------------------------------*/
/* Compose and Decompose REAL                                                */
/* integer <-> REAL conversion operations                                    */
/* REAL whole number conversions, caller KNOWS whole number fits in int      */
/* Exact Remainder                                                           */
/*---------------------------------------------------------------------------*/
/* Names have form: <operation> F { 1 | 2 | 3 }?                             */
/* Where <operation> is one of:                                              */
/*    SCL  -- f * RADIX**e                                                   */
/*    RIP  -- decompose x into f,e such that x == f*RADIX**e and 1/RADIX<=f<1*/
/*                                                                           */
/*    FIX  -- truncate towards zero and convert to int                       */
/*    FLT  -- convert int  to REAL                                           */
/*    FIXU -- truncate towards zero and convert to unsigned int              */
/*    FLTU -- convert unsigned int  to REAL                                  */
/*                                                                           */
/*    TNC  -- truncate towards 0                (x fits in int)              */
/*    RND  -- round to nearest whole number REAL(x fits in int)              */
/*    FLR  -- truncate towards minus infinity   (x fits in int)              */
/*    CEI  -- truncate towards plus  infinity   (x fits in int)              */
/*                                                                           */
/*    REM  -- *EXACT* remainder (big horrible by-hand divide routine)        */
/*                                                                           */
/* Note that the following whole number approximation rtns exist in math.h:  */
/*    TRUNCF -- truncate towards 0                (x any value)              */
/*    ROUNDF -- round to nearest whole number REAL(x any value)              */
/*    FLOORF -- truncate towards minus infinity   (x any value)              */
/*    CEILF  -- truncate towards plus  infinity   (x any value)              */
/*                                                                           */
/* F means REAL                                                              */
/* If no 1,2 or 3 suffix then is function returning result.                  */
/* Optional 1,2 or 3 means 1-addr, 2-addr or 3-addr version:                 */
/*    1 -> right = operation right;                                          */
/*    2 -> dst   = operation right;      ( unary operations)                 */
/*         left  = left operation right; (binary operations)                 */
/*    3 -> dst   = left operation right;                                     */
/*---------------------------------------------------------------------------*/
#endif

#define RIPF(x,f,e) f=FREXPF((x),&e)

#define SCLF(f,e)            LDEXPF((f),(e))
#define SCLF2(f,e)       f = LDEXPF((f),(e))
#define SCLF3(dst,f,e) dst = LDEXPF((f),(e))

#define FIXFC(x) _fixdc(x) /* ((char)(x))    */
#define FLTCF(x) _fltcd(x) /* ((REAL)(x))    */

#define FIXFB(x) _fixdb(x) /* ((unsigned char)(x))*/
#define FLTBF(x) _fltbd(x) /* ((REAL)(x))        */

#define FIXFSI(x) _fixdsi(x) /* ((short)(x))   */
#define FLTSIF(x) _fltsid(x) /* ((REAL)(x))    */

#define FIXFUS(x) _fixdus(x) /* ((unsigned short)(x))*/
#define FLTUSF(x) _fltusd(x) /* ((REAL)(x))          */

#define FIXFI(x) _fixdi(x) /* ((int)(x))     */
#define FLTIF(x) _fltid(x) /* ((REAL)(x))    */

#define FIXFU(x) _fixdu(x) /* ((unsigned)(x))*/
#define FLTUF(x) _fltud(x) /* ((REAL)(x))    */

#define FIXFLI(x) _fixdli(x) /* ((long)(x))    */
#define FLTLIF(x) _fltlid(x) /* ((REAL)(x))    */

#define FIXFUL(x) _fixdul(x) /* ((unsigned long)(x))*/
#define FLTULF(x) _fltuld(x) /* ((REAL)(x))         */

#define FIXFLLI(x) _fixdlli(x) /* ((long long)(x))    */
#define FLTLLIF(x) _fltllid(x) /* ((REAL)(x))    */

#define FIXFULL(x) _fixdull(x) /* ((unsigned long long)(x))*/
#define FLTULLF(x) _fltulld(x) /* ((REAL)(x))         */

#if 0
/* TNCF, RNDF, FLRF, CEIF, may all use FLTIF(FIXFI(f(x))).                */
/* Call sites must be sure to enforce several rules:                      */
/* 1. TRUNCF(f(x)) must not exceed the integer range.                     */
/* 2. if REAL does unbiased round-towards-even,                           */
/*    input x to RNDF must never equal +/- RADIX_to_Mantissa-1.           */
#endif
#ifndef RND_GLITCH
   #error "REAL format .h file must be included before REAL syntax .h file"
#endif
#if (RND_GLITCH)
   #define RND_MAX_P1 RND_P_GLITCH
   #define RND_MIN    RND_M_GLITCH
#else
   #define RND_MAX_P1 INT_MOST_POS_P1
   #define RND_MIN    INT_MOST_NEG
#endif
#ifndef FLT_FIX_Faster_Than_MODF
   #error "target props .h file must be included before REAL syntax .h file"
#endif
#if (FLT_FIX_Faster_Than_MODF)
   #define TNCF(x) (FLTIF(FIXFI(x)))

   #define RNDF(x) (GEZF(x)? \
                    FLTIF(FIXFI((ADDF((x),HALF)))) : \
                    FLTIF(FIXFI((SUBF((x),HALF)))))

   #define FLRF(x) (GEZF(x) ? \
                    (FLTIF(FIXFI(x))) : \
                     (EQLF(x,FLTIF(FIXFI(x))) ? \
                      x : \
                      (FLTIF(NEGF(FIXFI(ADDF(NEGF(x),ONE)))))))

   #define CEIF(x) (LEZF(x) ? \
                    (FLTIF(FIXFI(x))) : \
                     (EQLF(x,FLTIF(FIXFI(x))) ? \
                      x : \
                      (FLTIF(NEGF(FIXFI(SUBF(NEGF(x),ONE)))))))

#else /*  call through to general purpose routines */
   #define TNCF(x) (TRUNCF(x))
   #define RNDF(x) (ROUNDF(x))
   #define FLRF(x) (FLOORF(x))
   #define CEIF(x) (CEILF(x))
#endif

#define FIXFI1(x) x=FIXFI(x)
#define FLTIF1(x) x=FLTIF(x)
#define FIXFU1(x) x=FIXFU(x)
#define FLTUF1(x) x=FLTUF(x)

#define TNCF1(x) x=TNCF(x)
#define RNDF1(x) x=RNDF(x)
#define FLRF1(x) x=FLRF(x)
#define CEIF1(x) x=CEIF(x)

#define FIXFI2(dst,right) dst=FIXFI(right)
#define FLTIF2(dst,right) dst=FLTIF(right)
#define FIXFU2(dst,right) dst=FIXFU(right)
#define FLTUF2(dst,right) dst=FLTUF(right)

#define TNCF2(dst,right) dst=TNCF(right)
#define RNDF2(dst,right) dst=RNDF(right)
#define FLRF2(dst,right) dst=FLRF(right)
#define CEIF2(dst,right) dst=CEIF(right)


#define REMF(right,left)           (FMODF(right,left))
#define REMF1(right,left)     right=FMODF(right,left)
#define REMF2(dst,right,left) dst  =FMODF(right,left)


#if 0
/*---------------------------------------------------------------------------*/
/* IEEE software support specific routines                                   */
/*---------------------------------------------------------------------------*/
#endif
#if (BPREAL == BPbigint)
   #define FRCMPYF(l,r) _frcmpyd(l,r)
   #define FRCDIVF(l,r) _frcdivd(l,r)
#elif (BPREAL == (BPbigint*2))
   #define RENORMF(x) renormd(x)
   #define FRCADDF(lx,lf,rx,rf) _frcaddd(lx,lf,rx,rf)
   #define FRCMPYF(p,l,r) _frcmpyd(p,l,r)
   #define FRCDIVF(q,l,r) _frcdivd(q,l,r)
#else
   #error "IEEE lowest-level support routines NYI for this size REAL"
#endif
#ifdef LEAN
#define GROWF(x) _cvtfd(x) /*  grow from LEAN to REAL */
#define SLIMF(x) _cvtdf(x) /*  slim from REAL to LEAN */
#endif

#if 0
/*---------------------------------------------------------------------------*/
/* Polynomial evaluation loops macros.                                       */
/*---------------------------------------------------------------------------*/
/* Loops are used for all polynomials.  It is assumed that this              */
/* is more DSP-friendly given that DSP hardware/software has:                */
/*   . zero-overhead looping,                                                */
/*   . optimizations to software pipeline multiply-accumulate,               */
/*   . the lack of full-precision floating-immediate address mode,           */
/*   . relatively expensive fetch of non-tabular constants,                  */
/*   . the existance of auto-increment addressing for table access.          */
/*---------------------------------------------------------------------------*/

/* form of: r=(((K[0]*x + K[1])*x + K[2])*x); r not same as x */
#endif
#define POLYF(r,x,K,s) {int i; REAL *p=K;                             \
                        MPYF3(r,x,*p++);                              \
                        for (i=s-1; i>0; i--) MPYF3(r,x,ADDF(r,*p++));}

#if 0
/* extra add at the end */
/* form of: r=(((K[0]*x + K[1])*x + K[2])*x) + K[3];  r not same as x */
#endif
#define POLYaF(r,x,K,s) {int i; REAL *p=K;                             \
                         MPYF3(r,x,*p++);                              \
                         for (i=s-2; i>0; i--) MPYF3(r,x,ADDF(r,*p++));\
                         ADDF2(r,*p++);}

#if 0
/* form of: r=((x+K[0])*x + K[1])*x + K[2]) * x) + K[3]; r not same as x */
#endif
#define POLYbF(r,x,K,s) {int i; REAL *p=K;                             \
                         ADDF3(r,x,*p++);                              \
                         for (i=s-1; i>0; i--) ADDF3(r,*p++,MPYF(x,r));}

#if 0
/*---------------------------------------------------------------------------*/
/* Bind The Names Of The Math Library Routines                               */
/*---------------------------------------------------------------------------*/
#endif
#define SQRTF(x)    sqrt(x)
#define RSQRTF(x)   rsqrt(x)
#define EXPF(x)     exp(x)
#define EXP2F(x)    exp2(x)
#define EXP10F(x)   exp10(x)
#define LOGF(x)     log(x)
#define LOG2F(x)    log2(x)
#define LOG10F(x)   log10(x)
#define POWF(x,y)   pow(x,y)
#define POWIF(x,i)  powi(x,i)
#define SINF(x)     sin(x)
#define COSF(x)     cos(x)
#define TANF(x)     tan(x)
#define COTF(x)     cot(x)
#define ASINF(x)    asin(x)
#define ACOSF(x)    acos(x)
#define ATANF(x)    atan(x)
#define ATAN2F(y,x) atan2(y,x)
#define ACOTF(x)    acot(x)
#define ACOT2F(x,y) acot2(x,y)
#define SINHF(x)    sinh(x)
#define COSHF(x)    cosh(x)
#define TANHF(x)    tanh(x)
#define COTHF(x)    coth(x)
#define ASINHF(x)   asinh(x)
#define ACOSHF(x)   acosh(x)
#define ATANHF(x)   atanh(x)
#define ACOTHF(x)   acoth(x)

#define CEILF(x)    ceil(x)
#define FLOORF(x)   floor(x)
#define TRUNCF(x)   _trunc(x)
#define ROUNDF(x)   _round(x)

#define FABSF(x)    fabs(x)

#define LDEXPF(x,n)   ldexp(x,n)
#define FREXPF(x,exp) frexp(x,exp)
#define MODFF(x,ip)   modf(x,ip)
#define FMODF(x,y)    fmod(x,y)

#endif /* __syntd__*/
/****************************************************************************/
/*  ieeed.h          v5.1.0                                                 */
/*  Copyright (c) 1997-2005  Texas Instruments Incorporated                 */
/****************************************************************************/
 
/* This source automatically generated on Wed Aug  2 15:55:34 CDT 2000 */
 
#ifndef __ieeed__
#define __ieeed__

extern "C" double _absd(double x);
extern "C" double _negd(double x);

extern "C" double _addd(double left, double right);
extern "C" double _subd(double left, double right);
extern "C" double _mpyd(double left, double right);
extern "C" double _divd(double left, double right);

extern "C" int _cmpd(double left,
                 double right); /* <0 if LT, 0 if EQ, >0 if GT     */
                                /* no correct result if NaN source */

extern "C" int _eqld(double left, double right);
extern "C" int _neqd(double left, double right);
extern "C" int _leqd(double left, double right);
extern "C" int _geqd(double left, double right);
extern "C" int _lssd(double left, double right);
extern "C" int _gtrd(double left, double right);


/* char <-> double */
extern "C" double        _fltcd(  signed char x);
extern "C" double        _fltbd(unsigned char x);
extern "C"   signed char _fixdc(double x);
extern "C" unsigned char _fixdb(double x);

/* short <-> double */
extern "C" double         _fltsid(         short x);
extern "C" double         _fltusd(unsigned short x);
extern "C" short          _fixdsi(double x);
extern "C" unsigned short _fixdus(double x);

/* int <-> double */
extern "C" double   _fltid(int      x);
extern "C" double   _fltud(unsigned x);
extern "C" int      _fixdi(double x);
extern "C" unsigned _fixdu(double x);

/* long <-> double */
extern "C" double        _fltlid(         long x);
extern "C" double        _fltuld(unsigned long x);
extern "C" long          _fixdli(double x);
extern "C" unsigned long _fixdul(double x);


/* float <-> double */
extern "C" float  _cvtdf(double x); /* slim from double to float  */
extern "C" double _cvtfd(float  x); /* grow from float  to double */


#endif /* __ieeed__*/
/****************************************************************************/
/*  ieeemask.h       v5.1.0                                                 */
/*  Copyright (c) 1997-2005  Texas Instruments Incorporated                 */
/****************************************************************************/
 
/* This source automatically generated on Wed Aug  2 15:53:39 CDT 2000 */
 
#ifndef __ieeemask__
#define __ieeemask__

#ifndef BPint
   #error "target properties .h file must be included before ieeemask.h"
#endif

#if defined(Generate_Sources)
 #ifdef _TMS320C6x
  #define c6x_h #include <c6x.h>
c6x_h
 #endif
#elif defined(_TMS320C6x)
 #include <c6x.h>
#endif

#if 0
/*---------------------------------------------------------------------------*/
/* There are two ways to get at the bits associated with REAL:               */
/*                                                                           */
/* 1. Efficient size-specific casting:                                       */
/*    . for (BPREAL==   BPbigint) use {bigint crx; REALasINT(crx,x); ... etc}*/
/*    . for (BPREAL== 2*BPbigint) use {REAL_2UNS crx; crx.r=x; x.msh ...}    */
/*    These have also been size-abstracted as CREAL (pronounced "Cast REAL") */
/*      {CREAL crx; REALasCREAL(crx,x); ...etc}                              */
/*                                                                           */
/* 2. Slightly less efficient size-independent:                              */
/*       {bigint *pr = (bigint *)(&x)+MSBI_OFFSET;                           */
/*        msbi = *pr;   --fetch most significant bigint part                 */
/*        NEXT_MS(pr);  --advance ptr to next-most significant bigint part   */
/*    The macros MSI,LSI,MSBI,LSBI will allow access to the most/least       */
/*    significant int/bigint parts without having to declare pr.             */
/*                                                                           */
/* The pointer method is less efficient because most compilers cannot track  */
/* pointer usage sufficiently well to determine the variables changed when   */
/* writing through a pointer.  This causes many keep-it-in-a-register        */
/* opportunities to be lost around write sites.                              */
/* Furthermore, some compilers do not guarantee that reads and writes        */
/* through aliased pointer variables have *ANY* relationship with the        */
/* variables they alias and will optimize code such that desired data        */
/* dependencies are not maintained.  A sometimes-cure for this unfriendly    */
/* behavior is to insert an optmization fence before and after any use of a  */
/* pointer or a pointer cast.  ANSI specifies that char* is itself a fence   */
/* so if the REAL can be processed a char-at-a-time, use the MSC macros.     */
/*                                                                           */
/* Advantages of both models may be obtained by keeping REALs as CREALs      */
/* and using pointers to address of the CREAL version.                       */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* CREAL casting type and associated operations.                          */
/*---------------------------------------------------------------------------*/
#endif
#if (BPREAL == BPbigint)
   union REAL_UNS_u {
      REAL r;
      biguns u;
   };
   typedef union REAL_UNS_u REAL_UNS;
   union REAL_INT_u {
      REAL r;
      bigint i;
   };
   typedef union REAL_INT_u REAL_INT;

 #ifdef Pointers_Might_Not_Work
  #if (defined(_TMS320C6x) && (BPbigint == BPint))
   #define REALasINT(I, R) (I)=(biguns)_ftoi(R)
   #define REALasUNS(U, R) (U)=_ftoi(R)
   #define INTasREAL(R, I) (R)=_itof((biguns)(I))
   #define UNSasREAL(R, U) (R)=_itof(U)

   #define return_REALasINT(R) return (biguns)_ftoi(R)
   #define return_REALasUNS(R) return _ftoi(R)
   #define return_INTasREAL(I) return _itof((biguns)(I))
   #define return_UNSasREAL(U) return _itof(U)

  #else
   #define REALasINT(I, R) do{REAL_INT XX; XX.r =(R); (I)= XX.i;}while(0)
   #define REALasUNS(U, R) do{REAL_UNS XX; XX.r =(R); (U)= XX.u;}while(0)
   #define INTasREAL(R, I) do{REAL_INT XX; XX.i =(I); (R)= XX.r;}while(0)
   #define UNSasREAL(R, U) do{REAL_UNS XX; XX.u =(U); (R)= XX.r;}while(0)

   #define return_REALasINT(R) do{REAL_INT XX; XX.r=(R); return XX.i;}while(0)
   #define return_REALasUNS(R) do{REAL_UNS XX; XX.r=(R); return XX.u;}while(0)
   #define return_INTasREAL(I) do{REAL_INT XX; XX.i=(I); return XX.r;}while(0)
   #define return_UNSasREAL(U) do{REAL_UNS XX; XX.u=(U); return XX.r;}while(0)
  #endif

 #else
   #define REALasINT(I, R) do{I= *(bigint *)&(R);}while (0)
   #define REALasUNS(U, R) do{U= *(biguns *)&(R);}while (0)
   #define INTasREAL(R, I) do{R= *(REAL *)&(I);}while (0)
   #define UNSasREAL(R, U) do{R= *(REAL *)&(U);}while (0)

   #define return_REALasINT(R) do{REAL mem_REAL=R;\
                                  return *(bigint *)&(mem_REAL);}while (0)
   #define return_REALasUNS(R) do{REAL mem_REAL=R;\
                                  return *(biguns *)&(mem_REAL);}while (0)
   #define return_INTasREAL(I) do{bigint mem_int=I;\
                                  return *(REAL *)&(mem_int);}while (0)
   #define return_UNSasREAL(U) do{biguns mem_uns=U;\
                                  return *(REAL *)&(mem_uns);}while (0)
 #endif

   #define CREAL REAL_UNS
   #define REALasCREAL(CR,R) CR.r=(R)
   #define CREALasREAL(R,CR) (R)=CR.r
   #define UNSasCREAL(CR,U) CR.u=(U)
   #define INTasCREAL(CR,I) CR.i=(I)
   #define CREAL_SAME(l, r) (l==r)

   #define CREAL_IS_NAN(CR) (CR.u>REAL_INFNAN)

#elif (BPREAL==(2*BPbigint))
   union REAL_2UNS_u {
      REAL r;
      struct {
      #if MSB_In_Hi_Addr
         biguns lsh;
         biguns msh;
      #else
         biguns msh;
         biguns lsh;
      #endif
      } u;
   };
   typedef union REAL_2UNS_u REAL_2UNS;
   union REAL_2INT_u {
      REAL r;
      struct {
      #if MSB_In_Hi_Addr
         bigint lsh;
         bigint msh;
      #else
         bigint msh;
         bigint lsh;
      #endif
      } u;
   };
   typedef union REAL_2INT_u REAL_2INT;

#if 0
   /* INTasREAL and UNSasREAL have no meaning unless I,U is *p++ */
#endif
   #if (MSB_In_Hi_Addr)
      #define INTasREAL(R,I) do{LSBI(R)= I; \
                                MSBI(R)= I;} while(0) /* I usually *p++ */
      #define UNSasREAL(R,U) do{LSBI(R)= U; \
                                MSBI(R)= U;} while(0) /* U usually *p++ */
   #else
      #define INTasREAL(R,I) do{MSBI(R)= I; \
                                LSBI(R)= I;} while(0) /* I usually *p++ */
      #define UNSasREAL(R,U) do{MSBI(R)= U; \
                                LSBI(R)= U;} while(0) /* U usually *p++ */
   #endif

   #define CREAL REAL_2UNS
   #define REALasCREAL(CR,R) CR.r=R
   #define CREALasREAL(R,CR) R=CR.r
   #if (MSB_In_Hi_Addr)
      #define UNSasCREAL(CR, U) CR.u.lsh=(U); CR.u.msh=(U)  /* u usually *p++*/
      #define INTasCREAL(CR, I) CR.u.lsh=(biguns)(I); CR.u.msh=(biguns)(I)
   #else
      #define UNSasCREAL(CR, U) CR.u.msh=(u); CR.u.lsh=(U)  /* u usually *p++*/
      #define INTasCREAL(CR, I) CR.u.msh=(biguns)(I); CR.u.lsh=(biguns)(I)
   #endif

   #define CREAL_SAME(l, r) (((l).u.msh == (r).u.msh) && \
                             ((l).u.lsh == (r).u.lsh))

   #define CREAL_IS_NAN(cr) ( ((cr).u.msh> REAL_INFNAN)|| \
                             (((cr).u.msh==REAL_INFNAN)&&((cr).u.lsh>0)))

   
   #define NEG2sCOMP(xx) xx.u.msh = ~xx.u.msh + ((xx.u.lsh = -xx.u.lsh) == 0)

   #define RIGHT_SHIFT(lll, nnn) do { \
      int sc = nnn; \
      if (sc >= BPbigint) {lll.u.lsh= lll.u.msh >> sc-BPbigint; lll.u.msh=0;} \
      else { lll.u.lsh = (lll.u.msh << BPbigint-sc) + (lll.u.lsh >> sc); \
             lll.u.msh >>= sc;}} while (0)

   #define LEFT_SHIFT(lll, nnn) do { \
      int sc = nnn; \
      if (sc >= BPbigint) {lll.u.msh= lll.u.lsh << sc-BPbigint; lll.u.lsh=0;} \
      else { lll.u.msh = (lll.u.lsh >> BPbigint-sc) + (lll.u.msh << sc); \
             lll.u.lsh <<= sc;}} while (0)

   #define RIGHT_SHIFT1(lll) do {\
      lll->u.lsh = (lll->u.lsh >> 1) + (lll->u.msh << BPbigint-1);\
      lll->u.msh >>=1;} while (0)

   #define LEFT_SHIFT1(lll) do {\
      lll->u.msh = (lll->u.msh << 1) + (lll->u.lsh >> BPbigint-1);\
      lll->u.lsh <<=1;} while (0)

   #define RSH1(msh,lsh) \
      do {lsh = (lsh >> 1) + (msh << BPbigint-1); msh >>=1;} while (0)

   #define LSH1(msh,lsh) \
      do {msh = (msh << 1) + (lsh >> BPbigint-1);  lsh <<=1;} while (0)

 #if 0 /* alternative implementations of interest */
   #define RSH1(msh,lsh) \
      do {lsh >>= 1; if (msh & 1) lsh += MINUS; msh >>=1;} while (0)
   #define LSH1(msh,lsh) \
      do {msh <<= 1; if ((int)lsh < 0) msh++; lsh <<=1;} while (0)
 #endif

#else
   #error "no casting type defined for this size REAL"
#endif


#if 0
/*---------------------------------------------------------------------------*/
/* For use with (int *) ptr to REAL, and (bigint *) ptr to REAL.             */
/*    MSC  is "Least Significant   char part"                                */
/*    MSI  is "Least Significant    int part"                                */
/*    MSBI is "Least Significant bigint part"                                */
/*    LSC  is "Least Significant   char part"                                */
/*    LSI  is "Least Significant    int part"                                */
/*    LSBI is "Least Significant bigint part"                                */
/*---------------------------------------------------------------------------*/
#endif

#if 0
/* The C6x compiler exhibits some rather unfriendly this week   */
/* in that it rearranges code with pointer casts such that      */
/* desired data dependencies are not forthcoming and code       */
/* function is unpredictable.  A fix for this is to isolate     */
/* reads and writes and place optimization blocks around them.  */
/* Probably this too will stop working some day.  Beware.       */
#endif
#define OPTIMIZATION_BLOCK asm(" ")

#if (MSB_In_Hi_Addr)
   #define MSC_OFFSET ((BPREAL/BPchar)-1) 
   #define LSC_OFFSET 0
   #define MSI_OFFSET ((BPREAL/BPint)-1) 
   #define LSI_OFFSET 0
   #define MSBI_OFFSET ((BPREAL/BPbigint)-1) 
   #define LSBI_OFFSET 0
   #define NEXT_MS_OFFSET (-1)
   #define CONSUME_MS(ptr) *ptr--
#else
   #define MSC_OFFSET 0
   #define LSC_OFFSET ((BPREAL/BPchar)-1)
   #define MSI_OFFSET 0
   #define LSI_OFFSET ((BPREAL/BPint)-1)
   #define MSBI_OFFSET 0
   #define LSBI_OFFSET ((BPREAL/BPbigint)-1) 
   #define NEXT_MS_OFFSET 1
   #define CONSUME_MS(ptr) *ptr++
#endif

#define LSC(right)  *((  char *)(&right)+ LSC_OFFSET)
#define LSI(right)  *((   int *)(&right)+ LSI_OFFSET)
#define LSBI(right) *((bigint *)(&right)+LSBI_OFFSET)

#define MSC(right)  *((  char *)(&right)+ MSC_OFFSET)
#define MSI(right)  *((   int *)(&right)+ MSI_OFFSET)
#define MSBI(right) *((bigint *)(&right)+MSBI_OFFSET)

#define NEXT_MS(ptr) ptr+=NEXT_MS_OFFSET;

#define SIGN_SET(right) (MSC(right) < 0)
#define MINUSC (((char)1)<<(BPchar-1))




#if 0
/*---------------------------------------------------------------------------*/
/* Masks and constants for the top BPbigint bits of the IEEE number.         */
/*---------------------------------------------------------------------------*/
#endif

#define MINUS (((biguns)1)<<(BPbigint-1))
#define UNORDERED (((int)1)<<(BPint-1)) /* return this for NAN input to CMPF */
#define MASK(bb) ((((bigint)1)<<(bb))-1) /*clear bits above the 2**(bb-1) bit*/

#define REAL_EXP_INFNAN ((((bigint)1)<<REAL_EXP_BITS)-1)
#define REAL_EXP_MASK   ((((bigint)1)<<REAL_EXP_BITS)-1)

#define REAL_FRC_MSBs (REAL_FRC_BITS % BPbigint) /*frc bits MS part*/
# if REAL_FRC_BITS > (BPbigint * 2)
#  error Sorry, this size float too large for this target.
# endif
#define REAL_FRC_MASK  ((((bigint)1)<< REAL_FRC_MSBs)-1)
#define REAL_HIDDEN_BIT (((bigint)1)<< REAL_FRC_MSBs)
#define REAL_INFNAN (((bigint)REAL_EXP_INFNAN) << REAL_FRC_MSBs)
#define REAL_NSNAN_BIT (((bigint)1)<<(REAL_FRC_MSBs-1)) /* MSB of fraction */
#define REAL_NAN    (REAL_INFNAN+1) /* signalling NAN */
#define REAL_NSNAN  (REAL_INFNAN+REAL_NSNAN_BIT) /*non-signl NAN*/

#define REAL_MOSTPOS (((REAL_EXP_INFNAN-1)<<REAL_FRC_MSBs)+REAL_FRC_MASK)
#define REAL_MOSTNEG (((REAL_EXP_INFNAN-1)<<REAL_FRC_MSBs)+REAL_FRC_MASK+MINUS)

#if 0
/*---------------------------------------------------------------------------*/
/* Similar constants as above,                                               */
/* but defined for LEAN, the next smallest floating point format.            */
/*---------------------------------------------------------------------------*/
#endif
   
#if !defined(LEAN) /* no smaller float size to provide conversion to/from */
   
#elif (BPLEAN == BPbigint)
   union LEAN_UNS_u {
      LEAN r;
      biguns u;
   };
   typedef union LEAN_UNS_u LEAN_UNS;
   union LEAN_INT_u {
      LEAN r;
      bigint i;
   };
   typedef union LEAN_INT_u LEAN_INT;

 #ifdef Pointers_Might_Not_Work
  #if (defined(_TMS320C6x) && (BPbigint == BPint))
   #define LEANasINT(I, R) (I)=(biguns)_ftoi(R)
   #define LEANasUNS(U, R) (U)=_ftoi(R)
   #define INTasLEAN(R, I) (R)=_itof((biguns)(I))
   #define UNSasLEAN(R, U) (R)=_itof(U)

   #define return_LEANasINT(R) return (biguns)_ftoi(R)
   #define return_LEANasUNS(R) return _ftoi(R)
   #define return_INTasLEAN(I) return _itof((biguns)(I))
   #define return_UNSasLEAN(U) return _itof(U)
  #else
   #define LEANasINT(I, R) do{LEAN_INT XX; XX.r =(R); (I)= XX.i;}while (0)
   #define LEANasUNS(U, R) do{LEAN_UNS XX; XX.r =(R); (U)= XX.u;}while (0)
   #define INTasLEAN(R, I) do{LEAN_INT XX; XX.i =(I); (R)= XX.r;}while (0)
   #define UNSasLEAN(R, U) do{LEAN_UNS XX; XX.u =(U); (R)= XX.r;}while (0)

   #define return_LEANasINT(R) do{LEAN_INT XX; XX.r=(R); return XX.i;}while (0)
   #define return_LEANasUNS(R) do{LEAN_UNS XX; XX.r=(R); return XX.u;}while (0)
   #define return_INTasLEAN(I) do{LEAN_INT XX; XX.i=(I); return XX.r;}while (0)
   #define return_UNSasLEAN(U) do{LEAN_UNS XX; XX.u=(U); return XX.r;}while (0)
  #endif
 #else
   #define LEANasINT(I, R) do{I= *(bigint *)&(R);}while (0)
   #define LEANasUNS(U, R) do{U= *(biguns *)&(R);}while (0)
   #define INTasLEAN(R, I) do{R= *(LEAN *)&(I);}while (0)
   #define UNSasLEAN(R, U) do{R= *(LEAN *)&(U);}while (0)

   #define return_LEANasINT(R) do{LEAN mem_LEAN=R;\
                                  return *(bigint *)&(mem_LEAN);}while (0)
   #define return_LEANasUNS(R) do{LEAN mem_LEAN=R;\
                                  return *(biguns *)&(mem_LEAN);}while (0)
   #define return_INTasLEAN(I) do{bigint mem_int=I;\
                                  return *(LEAN *)&(mem_int);}while (0)
   #define return_UNSasLEAN(U) do{biguns mem_uns=U;\
                                  return *(LEAN *)&(mem_uns);}while (0)
 #endif

   #define CLEAN LEAN_UNS
   #define LEANasCLEAN(CR,R) CR.r=(R)
   #define CLEANasLEAN(R,CR) (R)=CR.r
   #define UNSasCLEAN(CR,U) CR.u=(U)
   #define INTasCLEAN(CR,I) CR.i=(I)
   #define CLEAN_SAME(l, r) (l==r)

   #define LEAN_IS_NAN(CR) (CR.u>LEAN_INFNAN)

#elif (BPLEAN==(2*BPbigint))
   #define INTasLEAN(r,i) do{int j; bigint *q = &r; \  /* i usually *p++ */
                             for (j=1; j<=BPLEAN/BPbigint; j++)\
                                *q++ = i;}while(0)
   #define UNSasLEAN(r,u) do{int j; biguns *q = &r; \  /* u usually *p++ */
                             for (j=1; j<=BPLEAN/BPbigint; j++)\
                                *q++ = u;}while(0)

   union LEAN_2UNSs_u {
      LEAN r;
      struct {
      #if MSB_In_Hi_Addr
         biguns lsh;
         biguns msh;
      #else
         biguns msh;
         biguns lsh;
      #endif
      } u;
   };
   typedef union LEAN_2UNSs_u LEAN_2UNSs;

   #define CLEAN LEAN_2UNSs
   #define LEANasCLEAN(cr,R) cr.r=R
   #define CLEANasLEAN(R,cr) R=cr.r
   #if (MSB_In_Hi_Addr)
      #define UNSasCLEAN(cr, u) cr.u.lsh=(u); cr.u.msh=(u) /*u usually *p++*/
      #define INTasCLEAN(cr, i) cr.u.lsh=(biguns)(i); cr.u.msh=(biguns)(i)
   #else
      #define UNSasCLEAN(cr, u) cr.u.msh=(u); cr.u.lsh=(u) /*u usually *p++*/
      #define INTasCLEAN(cr, i) cr.u.msh=(biguns)(i); cr.u.lsh=(biguns)(i)
   #endif

   #define CLEAN_SAME(l, r) (((l).u.msh == (r).u.msh) && \
                             ((l).u.lsh == (r).u.lsh))

   #define CLEAN_IS_NAN(cr) ( ((cr).u.msh> LEAN_INFNAN)|| \
                             (((cr).u.msh==LEAN_INFNAN)&&((cr).u.lsh>0)))
#else
   #error "no casting type defined for this size LEAN format"
#endif


#define LEAN_EXP_INFNAN ((((bigint)1)<<LEAN_EXP_BITS)-1)
#define LEAN_EXP_MASK ((((bigint)1)<<LEAN_EXP_BITS)-1)

#define LEAN_EXP_INFNAN ((((bigint)1)<<LEAN_EXP_BITS)-1)
#define LEAN_EXP_MASK   ((((bigint)1)<<LEAN_EXP_BITS)-1)

#define LEAN_FRC_MSBs (LEAN_FRC_BITS % BPbigint) /*frc bits MS part*/
#define LEAN_FRC_MASK  ((((bigint)1)<< LEAN_FRC_MSBs)-1)
#define LEAN_HIDDEN_BIT (((bigint)1)<< LEAN_FRC_MSBs)
#define LEAN_INFNAN (((bigint)LEAN_EXP_INFNAN) << LEAN_FRC_MSBs)
#define LEAN_NSNAN_BIT (((bigint)1)<<(LEAN_FRC_MSBs-1)) /* MSB of fraction */
#define LEAN_NAN    (LEAN_INFNAN+1) /* signalling NAN */
#define LEAN_NSNAN  (LEAN_INFNAN+LEAN_NSNAN_BIT) /*non-signl NAN*/

#endif /* __ieeemask__ */
/****************************************************************************/
/*  renormd.h        v5.1.0                                                 */
/*  Copyright (c) 1997-2005  Texas Instruments Incorporated                 */
/****************************************************************************/
 
/* This source automatically generated on Wed Aug  2 15:53:42 CDT 2000 */
 
#ifndef __RENORMF__
#define __RENORMF__

#if (BPREAL == BPbigint)
   /* #define COUNT_LZERO(nnn) DEFAULT_IS_UNDEFINED                          */
   /* If defined, must be macro that returns the count of the number of      */
   /* consecutive zero bits at the most significant end of nnn.              */
   /* If COUNT_LZERO is not defined, alternate implementations will be used. */


   /* int RENORMF(bigint ff, int ee)                                         */
   /* ff (0<ff<REAL_HIDDEN_BIT) is left shifted until ff >= REAL_HIDDEN_BIT. */
   /* At least one shift is required.                                        */
   /* ee is decremented by the number of shifts.                             */
   #ifdef Support_DENORM
      #ifdef COUNT_LZERO
         #define RENORMF(ff,ee) do {int tmp = \
                                   COUNT_LZERO(ff)-BPbigint+\
                                   (REAL_FRC_MSBs)+1;\
                                ff <<= tmp; ee -= tmp-1;} while(0)
      #else
         #define RENORMF(ff,ee) while ((ff <<= 1) < REAL_HIDDEN_BIT) ee -= 1
      #endif
   #endif

   /* int RENORM2F(bigint ff, int ee)                                        */
   /* ff (0<ff<REAL_HIDDEN_BIT*2) is left shifted until ff>=REAL_HIDDEN_BIT*2*/
   /* At least one shift is required.                                        */
   /* ee is decremented by the number of shifts.                             */
   #ifdef COUNT_LZERO
      #define RENORM2F(ff,ee) do {int tmp=\
                                COUNT_LZERO(ff)-BPbigint+\
                                (REAL_FRC_BITS%BPbigint)+2;\
                               ff <<= tmp; ee -= tmp;} while (0)
   #else
      #define RENORM2F(ff,ee) do ee -= 1; while ((ff <<= 1) < REAL_HIDDEN_BIT*2)
   #endif
#elif (BPREAL == (BPbigint*2))
   extern int RENORMF(REAL_2UNS *ff);
#else
   #error "RENORMF not yet implemented for this size REAL"
#endif

#endif /* __RENORMF__ */
/****************************************************************************/
/*  frcaddd.h        v5.1.0                                                 */
/*  Copyright (c) 1997-2005  Texas Instruments Incorporated                 */
/****************************************************************************/
 
/* This source automatically generated on Wed Aug  2 15:53:37 CDT 2000 */
 
#ifndef __FRCADDF__
#define __FRCADDF__

#if (BPREAL == BPbigint) /* use compiler support for bigint add */

#elif (BPREAL == (BPbigint*2))
__EXTERN int FRCADDF(int lx, REAL_2UNS *lf, 
                     int rx, REAL_2UNS *rf);
#else
   #error "FRCADDF not yet implemented for this size REAL"
#endif

#endif /* __FRCADDF__ */

/****************************************************************************/
/*  frcmpyd.h        v5.1.0                                                 */
/*  Copyright (c) 1997-2005  Texas Instruments Incorporated                 */
/****************************************************************************/
 
/* This source automatically generated on Wed Aug  2 15:53:38 CDT 2000 */
 
#ifndef __FRCMPYF__
#define __FRCMPYF__

#if (BPREAL == BPbigint)
__EXTERN biguns FRCMPYF(biguns l, biguns r);

#elif (BPREAL == (BPbigint*2))
__EXTERN int FRCMPYF(REAL_2UNS *p, REAL_2UNS *l, REAL_2UNS *r);

#else
   #error "FRCMPYF not yet implemented for this size REAL"
#endif

#endif /*__FRCMPYF__*/
/****************************************************************************/
/*  frcdivd.h        v5.1.0                                                 */
/*  Copyright (c) 1997-2005  Texas Instruments Incorporated                 */
/****************************************************************************/
 
/* This source automatically generated on Wed Aug  2 15:53:38 CDT 2000 */
 
#ifndef __FRCDIVF__
#define __FRCDIVF__

#if (BPREAL == BPbigint)
__EXTERN biguns FRCDIVF(biguns l, biguns r);
#elif (BPREAL == (BPbigint*2))
__EXTERN int FRCDIVF(REAL_2UNS *p, REAL_2UNS *l, REAL_2UNS *r);

#else
   #error "FRCDIVF not yet implemented for this size REAL"
#endif

#endif /*__FRCDIVF__*/
