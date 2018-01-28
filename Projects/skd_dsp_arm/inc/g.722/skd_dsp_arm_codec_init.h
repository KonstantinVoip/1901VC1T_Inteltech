/**********************************************************************************************************************
*                                        (c) COPYRIGHT by PAO Inteltech.                                             *
*                                               All rights reserved.                                                  *
***********************************************************************************************************************
* Module      : skd_dsp_arm_codec_init
* Description : Работа с Памятью 1901 ВЦ1Т
* Author      : Konstantin Shiluaev
******************************************************************************
******************************************************************************
* Module's Description Record:
* ============================
* $State: Debug$
* $Revision: 0.0.0 $
* $Date: 2015/03/02 10:40:51 $
******************************************************************************/
#ifndef SKD_DSP_ARM_CODEC_INIT_H
#define SKD_DSP_ARM_CODEC_INIT_H

/********Настройки и Инициализация кодека G.722******/
struct g722_init_decode_structure
{
    /*! TRUE if the operating in the special ITU test mode, with the band split filters
             disabled. */
    int itu_test_mode;
    /*! TRUE if the G.722 data is packed */
    int packed;
    /*! TRUE if decode to 8k samples/second */
    int eight_k;
    /*! 6 for 48000kbps, 7 for 56000kbps, or 8 for 64000kbps. */
    int bits_per_sample;

    /*! Signal history for the QMF */
   /* int x[24];*/
    long x[24];

    struct
    {
        int s;
        int sp;
        int sz;
       	long r[3];			//int r[3];
        long a[3];			//int a[3];
        long ap[3];			//int ap[3];
        long p[3];			//int p[3];
        long d[7];			//int d[7];
        long b[7];			//int b[7];
        long bp[7];			//int bp[7];
        long sg[7];			//int sg[7];
        long nb;			//int nb;
        long det;			//int det;
    } band[2];
    
    unsigned int in_buffer;
    int in_bits;
    unsigned int out_buffer;
    int out_bits;
};


struct g722_init_encode_structure
{
    /*! TRUE if the operating in the special ITU test mode, with the band split filters
             disabled. */
    int itu_test_mode;
    /*! TRUE if the G.722 data is packed */
    int packed;
    /*! TRUE if encode from 8k samples/second */
    int eight_k;
    /*! 6 for 48000kbps, 7 for 56000kbps, or 8 for 64000kbps. */
    int bits_per_sample;

    /*! Signal history for the QMF */
    long x[24];

    struct
    {
        int s;
        int sp;
       	int sz;
        int r[3];
        long a[3];		  /*int a[3];*/
        long ap[3];		  /*int ap[3];*/
        long p[3];		  /*int p[3];*/
        long d[7];		  /*int d[7];*/
        long b[7];		  /*int b[7];*/
        long bp[7];		  /*int bp[7];*/
        long sg[7];		  /*int sg[7];*/
        long nb;		  /*int nb;*/
        long det; 		  /*int det;*/
    } band[2];

    unsigned int in_buffer;
    int in_bits;
    unsigned int out_buffer;
    int out_bits;
};

//Режимы работы кодека ITU-T G.722
//Mode 1 64 kbit/s
//Mode 2 56 kbit/s
//Mode 3 48 kbit/s


//Настройки используемые при начальной инициализации структуры Энкодера G.722
//Установка(Режима работы кодека) бит-рейта 64K/bit ,56K/bit, 48000K/bit 
 // const long int rate=64000;////Mode 1  raw bits per second
  //const int rate=56000;////Mode 2 raw bits per second
  //const int rate=48000;////Mode 3  raw bits per second
  //Установка дополнительных опций по умолчанию =0  
 // const int options=0;
		
  enum
  {
  G722_SAMPLE_RATE_8000 = 0x0001,
  G722_PACKED = 0x0002
  };

/*Конец настройки кодека G.722*/








#endif /* SKD_DSP_ARM_CODEC_INIT_H */
