/***********************************************************************************
*                             (c) COPYRIGHT by PAO Inteltech.     			*
*                             All rights reserved.         					*
*************************************************************************************
* Module      : F.c
* Description : Файл Определния функций КОДЕКА G.722
* Author      : Konstantin Shiluaev
******************************************************************************/
#include  <stdio.h>
#include "header.h"

void f ()
{
printf("Hello_Word\n\r");    
}


/*******************************************************************************
* Function Name :void * init_g722_encoder(unsigned short num_encoder)
* Description   :Инициализация Энкодера G.722
*******************************************************************************/
struct g722_init_encode_structure* init_g722_encoder(unsigned short num_encoder)
//void * init_g722_encoder(unsigned short num_encoder)
{
  
    struct g722_init_encode_structure *g722e;
   // memset(g722e, 0x0000, sizeof(*g722e));
 
    g722e =(struct g722_init_encode_structure *)malloc(sizeof (struct g722_init_encode_structure));

    //g722e =(struct g722_init_encode_structure *)malloc(sizeof (struct g722_init_encode_structure));
    //Проверяем что выделили память под структуры
    if(!g722e)
	{
    printf("Errror Memory Allocation g722 encoder =%d \n\r",num_encoder);
	return g722e;
	}
    
	//Очищаем поля Структуры
	memset(g722e, 0x0000, sizeof(*g722e));

    //Конфигурим Кодек выставляем частоту
    
    switch(rate)
   {
      case 48000:
      {
         g722e->bits_per_sample = 6;
         break;
      }
      case 56000:
      {
         g722e->bits_per_sample = 7;
         break;
      }
      default:
         g722e->bits_per_sample = 8;
   }
    
  	 if ((options & G722_SAMPLE_RATE_8000))
        g722e->eight_k = TRUE;
    if ((options & G722_PACKED)  &&  g722e->bits_per_sample != 8)
        g722e->packed = TRUE;
    else	
	 g722e->packed = FALSE;
     g722e->band[0].det = 32;
     g722e->band[1].det = 8;
    

  /*
   g722e->eight_k=(0!=(options & G722_SAMPLE_RATE_8000));
   g722e->packed=(0!=(options & G722_PACKED)) && (8!=g722e->bits_per_sample);
   g722e->band[0].det = 32;
   g722e->band[1].det = 8;
  */

    //Установка режима работы ENCODERA тестовый режим без блока Transmit quadrature mirror filters (QMFs)
	 g722e->itu_test_mode=FALSE;
  // g722e->itu_test_mode=TRUE;
     //g722e->eight_k = TRUE;
   
   return g722e;

 
}
/*******************************************************************************
* Function Name :void * init_g722_decoder(unsigned short num_decoder)
* Description   :Инициализация Декрдера G.722
*******************************************************************************/
//void * init_g722_decoder(unsigned short num_decoder)
struct g722_init_decode_structure* init_g722_decoder(unsigned short num_decoder)
{
    struct g722_init_decode_structure  *g722d;
    g722d =(struct g722_init_decode_structure *)malloc(sizeof (struct g722_init_decode_structure));
    //Проверяем что выделили память под структуры
    if(!g722d)
	{
    printf("Errror Memory Allocation g722 decoder=%d\n\r",num_decoder);
    return g722d; 
	}
   
    //Очищаем поля Структуры
	memset(g722d, 0x0000, sizeof(*g722d));
    
	//Инициализируем битрейрейт декодера
       //Конфигурим Кодек выставляем частоту
    
    switch(rate)
   {
      case 48000:
      {
         g722d->bits_per_sample = 6;
         break;
      }
      case 56000:
      {
         g722d->bits_per_sample = 7;
         break;
      }
      default:
         g722d->bits_per_sample = 8;
   }
   
   g722d->eight_k=(0!=(options & G722_SAMPLE_RATE_8000));
   g722d->packed=(0!=(options & G722_PACKED)) && (8!=g722d->bits_per_sample);
   g722d->band[0].det = 32;
   g722d->band[1].det = 8;
   
   //Установка режима работы Decodera тестовый режим без блока Transmit quadrature mirror filters (QMFs)
   //g722d->itu_test_mode=TRUE;
	 g722d->itu_test_mode=FALSE;
   //g722d->eight_k = TRUE;

   return g722d;
}



/*Определение функции Энкодера и Декодера*/
static inline signed short saturate_1(signed short amp)
{
	signed short amp16;
//	static unsigned short count=0;
    // Hopefully this is optimised for the common case - not clipping 
    amp16 = (signed short) amp;
    if (amp == amp16)
	{
       // printf("return [%d] amp16=%d,in=%d\n\r",count++,amp16,amp); 
        return amp16;
    }
    if (amp > SHRT_MAX)
    {   
        //printf("return INT16_MAX\n\r");
        return  SHRT_MAX;
    }
  //printf("return INT16_MIN\n\r");  
  return  SHRT_MIN;
}



//#if 0

/*******************************************************************************
* Function Name  : static void block4_decoder1(struct g722_init_decode_structure *g722d, int band, int d)
* Description    : 
*******************************************************************************/
static void block4_decoder1(struct g722_init_decode_structure *g722d, int band, int d)
{
    long wd1;
    long wd2;
    long wd3;
    long i;

    /* Block 4, RECONS */
    g722d->band[band].d[0] = d;
    g722d->band[band].r[0] = saturate_1(g722d->band[band].s + d);

    /* Block 4, PARREC */
    g722d->band[band].p[0] = saturate_1(g722d->band[band].sz + d);

    /* Block 4, UPPOL2 */
    for (i = 0;  i < 3;  i++)
        g722d->band[band].sg[i] = g722d->band[band].p[i] >> 15;
    wd1 = saturate_1(g722d->band[band].a[1] << 2);

    wd2 = (g722d->band[band].sg[0] == g722d->band[band].sg[1])  ?  -wd1  :  wd1;
    if (wd2 > 32767)
        wd2 = 32767;
    wd3 = (g722d->band[band].sg[0] == g722d->band[band].sg[2])  ?  128  :  -128;
    wd3 += (wd2 >> 7);
    wd3 += (g722d->band[band].a[2]*32512) >> 15;
    if (wd3 > 12288)
        wd3 = 12288;
    else if (wd3 < -12288)
        wd3 = -12288;
    g722d->band[band].ap[2] = wd3;

    /* Block 4, UPPOL1 */
    g722d->band[band].sg[0] = g722d->band[band].p[0] >> 15;
    g722d->band[band].sg[1] = g722d->band[band].p[1] >> 15;
    wd1 = (g722d->band[band].sg[0] == g722d->band[band].sg[1])  ?  192  :  -192;
    wd2 = (g722d->band[band].a[1]*32640) >> 15;

    g722d->band[band].ap[1] = saturate_1(wd1 + wd2);
    wd3 = saturate_1(15360 - g722d->band[band].ap[2]);
    if (g722d->band[band].ap[1] > wd3)
        g722d->band[band].ap[1] = wd3;
    else if (g722d->band[band].ap[1] < -wd3)
        g722d->band[band].ap[1] = -wd3;

    /* Block 4, UPZERO */
    wd1 = (d == 0)  ?  0  :  128;
    g722d->band[band].sg[0] = d >> 15;
    for (i = 1;  i < 7;  i++)
    {
        g722d->band[band].sg[i] = g722d->band[band].d[i] >> 15;
        wd2 = (g722d->band[band].sg[i] == g722d->band[band].sg[0])  ?  wd1  :  -wd1;
        wd3 = (g722d->band[band].b[i]*32640) >> 15;
        g722d->band[band].bp[i] = saturate_1(wd2 + wd3);
    }

    /* Block 4, DELAYA */
    for (i = 6;  i > 0;  i--)
    {
        g722d->band[band].d[i] = g722d->band[band].d[i - 1];
        g722d->band[band].b[i] = g722d->band[band].bp[i];
    }
    
    for (i = 2;  i > 0;  i--)
    {
        g722d->band[band].r[i] = g722d->band[band].r[i - 1];
        g722d->band[band].p[i] = g722d->band[band].p[i - 1];
        g722d->band[band].a[i] = g722d->band[band].ap[i];
    }

    /* Block 4, FILTEP */
    wd1 = saturate_1(g722d->band[band].r[1] + g722d->band[band].r[1]);
    wd1 = (g722d->band[band].a[1]*wd1) >> 15;
    wd2 = saturate_1(g722d->band[band].r[2] + g722d->band[band].r[2]);
    wd2 = (g722d->band[band].a[2]*wd2) >> 15;
    g722d->band[band].sp = saturate_1(wd1 + wd2);

    /* Block 4, FILTEZ */
    g722d->band[band].sz = 0;
    for (i = 6;  i > 0;  i--)
    {
        wd1 = saturate_1(g722d->band[band].d[i] + g722d->band[band].d[i]);
        g722d->band[band].sz += (g722d->band[band].b[i]*wd1) >> 15;
    }
    g722d->band[band].sz = saturate_1(g722d->band[band].sz);

    /* Block 4, PREDIC */
    g722d->band[band].s = saturate_1(g722d->band[band].sp + g722d->band[band].sz);
}

/*******************************************************************************
* Function Name  : static void block4_encoder1(struct g722_init_encode_structure *g722e, int band, int d)
* Description    : 
*******************************************************************************/
static void block4_encoder1(struct g722_init_encode_structure *g722e, int band, int d)
{
    long wd1;
    long wd2;
    long wd3;
    long i;

    // Block 4, RECONS
    g722e->band[band].d[0] = d;
    g722e->band[band].r[0] = saturate_1(g722e->band[band].s + d);

    // Block 4, PARREC 
    g722e->band[band].p[0] = saturate_1(g722e->band[band].sz + d);

    // Block 4, UPPOL2 
    for (i = 0;  i < 3;  i++)
        g722e->band[band].sg[i] = g722e->band[band].p[i] >> 15;
    wd1 = saturate_1(g722e->band[band].a[1] << 2);

    wd2 = (g722e->band[band].sg[0] == g722e->band[band].sg[1])  ?  -wd1  :  wd1;
    if (wd2 > 32767)
        wd2 = 32767;
    wd3 = (wd2 >> 7) + ((g722e->band[band].sg[0] == g722e->band[band].sg[2])  ?  128  :  -128);
    wd3 += (g722e->band[band].a[2]*32512) >> 15;
    if (wd3 > 12288)
        wd3 = 12288;
    else if (wd3 < -12288)
        wd3 = -12288;
    g722e->band[band].ap[2] = wd3;

    // Block 4, UPPOL1 
    g722e->band[band].sg[0] = g722e->band[band].p[0] >> 15;
    g722e->band[band].sg[1] = g722e->band[band].p[1] >> 15;
    wd1 = (g722e->band[band].sg[0] == g722e->band[band].sg[1])  ?  192  :  -192;
    wd2 = (g722e->band[band].a[1]*32640) >> 15;

    g722e->band[band].ap[1] = saturate_1(wd1 + wd2);
    wd3 = saturate_1(15360 - g722e->band[band].ap[2]);
    if (g722e->band[band].ap[1] > wd3)
        g722e->band[band].ap[1] = wd3;
    else if (g722e->band[band].ap[1] < -wd3)
        g722e->band[band].ap[1] = -wd3;

    // Block 4, UPZERO 
    wd1 = (d == 0)  ?  0  :  128;
    g722e->band[band].sg[0] = d >> 15;
    for (i = 1;  i < 7;  i++)
    {
        g722e->band[band].sg[i] = g722e->band[band].d[i] >> 15;
        wd2 = (g722e->band[band].sg[i] == g722e->band[band].sg[0])  ?  wd1  :  -wd1;
        wd3 = (g722e->band[band].b[i]*32640) >> 15;
        g722e->band[band].bp[i] = saturate_1(wd2 + wd3);
    }

    // Block 4, DELAYA 
    for (i = 6;  i > 0;  i--)
    {
        g722e->band[band].d[i] = g722e->band[band].d[i - 1];
        g722e->band[band].b[i] = g722e->band[band].bp[i];
    }
    
    for (i = 2;  i > 0;  i--)
    {
        g722e->band[band].r[i] = g722e->band[band].r[i - 1];
        g722e->band[band].p[i] = g722e->band[band].p[i - 1];
        g722e->band[band].a[i] = g722e->band[band].ap[i];
    }

    // Block 4, FILTEP 
    wd1 = saturate_1(g722e->band[band].r[1] + g722e->band[band].r[1]);
    wd1 = (g722e->band[band].a[1]*wd1) >> 15;
    wd2 = saturate_1(g722e->band[band].r[2] + g722e->band[band].r[2]);
    wd2 = (g722e->band[band].a[2]*wd2) >> 15;
    g722e->band[band].sp = saturate_1(wd1 + wd2);

    // Block 4, FILTEZ 
    g722e->band[band].sz = 0;
    for (i = 6;  i > 0;  i--)
    {
        wd1 = saturate_1(g722e->band[band].d[i] + g722e->band[band].d[i]);
        g722e->band[band].sz += (g722e->band[band].b[i]*wd1) >> 15;
    }
    g722e->band[band].sz = saturate_1(g722e->band[band].sz);

    // Block 4, PREDIC
    g722e->band[band].s = saturate_1(g722e->band[band].sp + g722e->band[band].sz);
}

/*******************************************************************************
* Function Name  : int g722_encoder1(struct g722_init_encode_structure *g722e, unsigned char g722_data[], const signed short amp[], int len)
* Description    : Нужно сделать дополнительное схатие так тут только 16 бит данные.
*******************************************************************************/
int g722_encoder1(struct g722_init_encode_structure *g722e, unsigned short g722_data[], const signed short amp[], int len)
{
    static const int q6[32] =
    {
           0,   35,   72,  110,  150,  190,  233,  276,
         323,  370,  422,  473,  530,  587,  650,  714,
         786,  858,  940, 1023, 1121, 1219, 1339, 1458,
        1612, 1765, 1980, 2195, 2557, 2919,    0,    0
    };
    static const int iln[32] =
    {
         0, 63, 62, 31, 30, 29, 28, 27,
        26, 25, 24, 23, 22, 21, 20, 19,
        18, 17, 16, 15, 14, 13, 12, 11,
        10,  9,  8,  7,  6,  5,  4,  0
    };
    static const int ilp[32] =
    {
         0, 61, 60, 59, 58, 57, 56, 55,
        54, 53, 52, 51, 50, 49, 48, 47,
        46, 45, 44, 43, 42, 41, 40, 39,
        38, 37, 36, 35, 34, 33, 32,  0
    };
    static const int wl[8] =
    {
        -60, -30, 58, 172, 334, 538, 1198, 3042
    };
    static const int rl42[16] =
    {
        0, 7, 6, 5, 4, 3, 2, 1, 7, 6, 5, 4, 3, 2, 1, 0
    };
    static const int ilb[32] =
    {
        2048, 2093, 2139, 2186, 2233, 2282, 2332,
        2383, 2435, 2489, 2543, 2599, 2656, 2714,
        2774, 2834, 2896, 2960, 3025, 3091, 3158,
        3228, 3298, 3371, 3444, 3520, 3597, 3676,
        3756, 3838, 3922, 4008
    };
    static const int qm4[16] =
    {
             0, -20456, -12896, -8968,
         -6288,  -4240,  -2584, -1200,
         20456,  12896,   8968,  6288,
          4240,   2584,   1200,     0
    };
    static const int qm2[4] =
    {
        -7408,  -1616,   7408,   1616
    };
    static const int qmf_coeffs[12] =
    {
           3,  -11,   12,   32, -210,  951, 3876, -805,  362, -156,   53,  -11,
    };
    static const int ihn[3] = {0, 1, 0};
    static const int ihp[3] = {0, 3, 2};
    static const int wh[3] = {0, -214, 798};
    static const int rh2[4] = {2, 1, 2, 1};
   
    long dlow;    //int dlow;
    long dhigh;	  //int  dhigh;
    long el;	  //int el;
    long wd;	  	    //int wd;
    long wd1;		//int wd1;
    long ril;		//int ril;
    long wd2;		//int wd2;
    long il4;			//int il4;
    long ih2;		//int ih2;
    long wd3;		//int wd3;
    long eh;			//int eh;
    long mih;		//int mih;
    int i;
    int j;
    // Low and high band PCM from the QMF 
    long xlow;		//int xlow;
    long xhigh;		//int xhigh;
    int g722_bytes;
    // Even and odd tap accumulators 
    long sumeven;		//int sumeven;
    long sumodd;		//int sumodd;
    long ihigh;		//int ihigh;
    long ilow;		//int ilow;
    long code;		//int code;



    g722_bytes = 0;
    xhigh = 0;
    for (j = 0;  j < len;  )
    {
        if (g722e->itu_test_mode)
        {
            xlow =
            xhigh = amp[j++] >> 1;
        }
        else
        {
            if (g722e->eight_k)
            {
                xlow = amp[j++];
            }
            else
            {
                // Apply the transmit QMF 
                // Shuffle the buffer down 
                memcpy(g722e->x, &g722e->x[2], 22*sizeof(g722e->x[0]));
                g722e->x[22] = amp[j++];
                g722e->x[23] = amp[j++];
    
                // Discard every other QMF output 
                sumeven = 0;
                sumodd = 0;
                for (i = 0;  i < 12;  i++)
                {
                    sumodd += g722e->x[2*i]*qmf_coeffs[i];
                    sumeven += g722e->x[2*i + 1]*qmf_coeffs[11 - i];
                }
                xlow = (sumeven + sumodd) >> 13;
                xhigh = (sumeven - sumodd) >> 13;
            }
        }
         //Block 1L, SUBTRA 
        el = saturate_1(xlow - g722e->band[0].s);

        // Block 1L, QUANTL 
        wd = (el >= 0)  ?  el  :  -(el + 1);

        for (i = 1;  i < 30;  i++)
        {
            wd1 = (q6[i]*g722e->band[0].det) >> 12;
            if (wd < wd1)
                break;
        }
        ilow = (el < 0)  ?  iln[i]  :  ilp[i];

        // Block 2L, INVQAL 
        ril = ilow >> 2;
        wd2 = qm4[ril];
        dlow = (g722e->band[0].det*wd2) >> 15;

        // Block 3L, LOGSCL 
        il4 = rl42[ril];
        wd = (g722e->band[0].nb*127) >> 7;
        g722e->band[0].nb = wd + wl[il4];
        if (g722e->band[0].nb < 0)
            g722e->band[0].nb = 0;
        else if (g722e->band[0].nb > 18432)
            g722e->band[0].nb = 18432;

        // Block 3L, SCALEL 
        wd1 = (g722e->band[0].nb >> 6) & 31;
        wd2 = 8 - (g722e->band[0].nb >> 11);
        wd3 = (wd2 < 0)  ?  (ilb[wd1] << -wd2)  :  (ilb[wd1] >> wd2);
        g722e->band[0].det = wd3 << 2;

        block4_encoder1(g722e, 0, dlow);
        
        if (g722e->eight_k)
        {
            // Just leave the high bits as zero 
            code = (0xC0 | ilow) >> (8 - g722e->bits_per_sample);
        }
        else
        {
            // Block 1H, SUBTRA 
            eh = saturate_1(xhigh - g722e->band[1].s);

            // Block 1H, QUANTH 
            wd = (eh >= 0)  ?  eh  :  -(eh + 1);
            wd1 = (564*g722e->band[1].det) >> 12;
            mih = (wd >= wd1)  ?  2  :  1;
            ihigh = (eh < 0)  ?  ihn[mih]  :  ihp[mih];

            // Block 2H, INVQAH 
            wd2 = qm2[ihigh];
            dhigh = (g722e->band[1].det*wd2) >> 15;

            // Block 3H, LOGSCH 
            ih2 = rh2[ihigh];
            wd = (g722e->band[1].nb*127) >> 7;
            g722e->band[1].nb = wd + wh[ih2];
            if (g722e->band[1].nb < 0)
                g722e->band[1].nb = 0;
            else if (g722e->band[1].nb > 22528)
                g722e->band[1].nb = 22528;

            // Block 3H, SCALEH 
            wd1 = (g722e->band[1].nb >> 6) & 31;
            wd2 = 10 - (g722e->band[1].nb >> 11);
            wd3 = (wd2 < 0)  ?  (ilb[wd1] << -wd2)  :  (ilb[wd1] >> wd2);
            g722e->band[1].det = wd3 << 2;

            block4_encoder1(g722e, 1, dhigh);
            code = ((ihigh << 6) | ilow) >> (8 - g722e->bits_per_sample);
        }

        if (g722e->packed)
        {
            // Pack the code bits 
            g722e->out_buffer |= (code << g722e->out_bits);
            g722e->out_bits += g722e->bits_per_sample;
            if (g722e->out_bits >= 8)
            {
                 //my_comment
				//g722_data[g722_bytes++] = (uint8_t) (g722e->out_buffer & 0xFF);                                 
                //(signed char) (g722e->out_buffer & 0xFF);                               
				 
				g722e->out_bits -= 8;
                g722e->out_buffer >>= 8;
            }
        }
        else
        {
			 //my_comment
           // g722_data[g722_bytes++] = (uint8_t) code;
           // g722_data[g722_bytes++] = (unsigned char) code;
		      g722_data[g722_bytes++] = (unsigned short) code;

		}
    }
    return g722_bytes;
}
/*******************************************************************************
* Function Name  : int g722_decoder1(struct g722_init_decode_structure *g722d, signed short amp[], const signed short g722_data[], int len)
* Description    : 
*******************************************************************************/
int g722_decoder1(struct g722_init_decode_structure *g722d, signed short amp[], const signed short g722_data[], int len)
{
    static const int wl[8] =
    {
        -60, -30, 58, 172, 334, 538, 1198, 3042
    };
    static const int rl42[16] =
    {
        0, 7, 6, 5, 4, 3, 2, 1, 7, 6, 5, 4, 3,  2, 1, 0
    };
    static const int ilb[32] =
    {
        2048, 2093, 2139, 2186, 2233, 2282, 2332,
        2383, 2435, 2489, 2543, 2599, 2656, 2714,
        2774, 2834, 2896, 2960, 3025, 3091, 3158,
        3228, 3298, 3371, 3444, 3520, 3597, 3676,
        3756, 3838, 3922, 4008
    };
    static const int wh[3] =
    {
        0, -214, 798
    };
    static const int rh2[4] =
    {
        2, 1, 2, 1
    };
    static const int qm2[4] =
    {
        -7408, -1616,  7408,   1616
    };
    static const int qm4[16] = 
    {
              0, -20456, -12896,  -8968, 
          -6288,  -4240,  -2584,  -1200,
          20456,  12896,   8968,   6288,
           4240,   2584,   1200,      0
    };
    static const int qm5[32] =
    {
           -280,   -280, -23352, -17560,
         -14120, -11664,  -9752,  -8184,
          -6864,  -5712,  -4696,  -3784,
          -2960,  -2208,  -1520,   -880,
          23352,  17560,  14120,  11664,
           9752,   8184,   6864,   5712,
           4696,   3784,   2960,   2208,
           1520,    880,    280,   -280
    };
    static const int qm6[64] =
    {
           -136,   -136,   -136,   -136,
         -24808, -21904, -19008, -16704,
         -14984, -13512, -12280, -11192,
         -10232,  -9360,  -8576,  -7856,
          -7192,  -6576,  -6000,  -5456,
          -4944,  -4464,  -4008,  -3576,
          -3168,  -2776,  -2400,  -2032,
          -1688,  -1360,  -1040,   -728,
          24808,  21904,  19008,  16704,
          14984,  13512,  12280,  11192,
          10232,   9360,   8576,   7856,
           7192,   6576,   6000,   5456,
           4944,   4464,   4008,   3576,
           3168,   2776,   2400,   2032,
           1688,   1360,   1040,    728,
            432,    136,   -432,   -136
    };
    static const int qmf_coeffs[12] =
    {
           3,  -11,   12,   32, -210,  951, 3876, -805,  362, -156,   53,  -11,
    };

    long dlowt;
    long rlow;
    long ihigh;
    long dhigh;
    long rhigh;
    long xout1;
    long xout2;
    long wd1;
    long wd2;
    long wd3;
	int code;
    int outlen;
    int i;
    int j;
  
    outlen = 0;
    rhigh = 0;
    for (j = 0;  j < len;  )
    {
        if (g722d->packed)
        {
            /* Unpack the code bits */
            if (g722d->in_bits < g722d->bits_per_sample)
            {
                g722d->in_buffer |= (g722_data[j++] << g722d->in_bits);
                g722d->in_bits += 8;
            }
            code = g722d->in_buffer & ((1 << g722d->bits_per_sample) - 1);
            g722d->in_buffer >>= g722d->bits_per_sample;
            g722d->in_bits -= g722d->bits_per_sample;
        }
        else
        {
            code = g722_data[j++];
        }

        switch (g722d->bits_per_sample)
        {
        default:
        case 8:
            wd1 = code & 0x3F;
            ihigh = (code >> 6) & 0x03;
            wd2 = qm6[wd1];
            wd1 >>= 2;
            break;
        case 7:
            wd1 = code & 0x1F;
            ihigh = (code >> 5) & 0x03;
            wd2 = qm5[wd1];
            wd1 >>= 1;
            break;
        case 6:
            wd1 = code & 0x0F;
            ihigh = (code >> 4) & 0x03;
            wd2 = qm4[wd1];
            break;
        }
        /* Block 5L, LOW BAND INVQBL */
        wd2 = (g722d->band[0].det*wd2) >> 15;
        /* Block 5L, RECONS */
        rlow = g722d->band[0].s + wd2;
        /* Block 6L, LIMIT */
        if (rlow > 16383)
            rlow = 16383;
        else if (rlow < -16384)
            rlow = -16384;

        /* Block 2L, INVQAL */
        wd2 = qm4[wd1];
        dlowt = (g722d->band[0].det*wd2) >> 15;

        /* Block 3L, LOGSCL */
        wd2 = rl42[wd1];
        wd1 = (g722d->band[0].nb*127) >> 7;
        wd1 += wl[wd2];
        if (wd1 < 0)
            wd1 = 0;
        else if (wd1 > 18432)
            wd1 = 18432;
        g722d->band[0].nb = wd1;
            
        /* Block 3L, SCALEL */
        wd1 = (g722d->band[0].nb >> 6) & 31;
        wd2 = 8 - (g722d->band[0].nb >> 11);
        wd3 = (wd2 < 0)  ?  (ilb[wd1] << -wd2)  :  (ilb[wd1] >> wd2);
        g722d->band[0].det = wd3 << 2;

            block4_decoder1(g722d, 0, dlowt);
        //  block5(g722d, 0, dlowt);  

        if (!g722d->eight_k)
        {
            /* Block 2H, INVQAH */
            wd2 = qm2[ihigh];
            dhigh = (g722d->band[1].det*wd2) >> 15;
            /* Block 5H, RECONS */
            rhigh = dhigh + g722d->band[1].s;
            /* Block 6H, LIMIT */
            if (rhigh > 16383)
                rhigh = 16383;
            else if (rhigh < -16384)
                rhigh = -16384;

            /* Block 2H, INVQAH */
            wd2 = rh2[ihigh];
            wd1 = (g722d->band[1].nb*127) >> 7;
            wd1 += wh[wd2];
            if (wd1 < 0)
                wd1 = 0;
            else if (wd1 > 22528)
                wd1 = 22528;
            g722d->band[1].nb = wd1;
            
            /* Block 3H, SCALEH */
            wd1 = (g722d->band[1].nb >> 6) & 31;
            wd2 = 10 - (g722d->band[1].nb >> 11);
            wd3 = (wd2 < 0)  ?  (ilb[wd1] << -wd2)  :  (ilb[wd1] >> wd2);
            g722d->band[1].det = wd3 << 2;

                block4_decoder1(g722d, 1, dhigh);
            //  block5(g722d, 1, dhigh);
        }

        if (g722d->itu_test_mode)
        {
            //amp[outlen++] = (int16_t) (rlow << 1);
            //amp[outlen++] = (int16_t) (rhigh << 1);
             amp[outlen++] = (signed short) (rlow << 1);
             amp[outlen++] = (signed short) (rhigh << 1);  
        }
        else
        {
            if (g722d->eight_k)
            {
                //amp[outlen++] = (int16_t) rlow;
                  amp[outlen++] = (signed short) rlow;
            }
            else
            {
                /* Apply the receive QMF */
                memcpy(g722d->x, &g722d->x[2], 22*sizeof(g722d->x[0]));
                g722d->x[22] = rlow + rhigh;
                g722d->x[23] = rlow - rhigh;

                xout1 = 0;
                xout2 = 0;
                for (i = 0;  i < 12;  i++)
                {
                    xout2 += g722d->x[2*i]*qmf_coeffs[i];
                    xout1 += g722d->x[2*i + 1]*qmf_coeffs[11 - i];
                }
               // amp[outlen++] = (int16_t) (xout1 >> 12);
               // amp[outlen++] = (int16_t) (xout2 >> 12);
                   amp[outlen++] = (signed short) (xout1 >> 12);
                   amp[outlen++] = (signed short) (xout2 >> 12);
                   
            }
        }
    }
    return outlen;
}

//#endif
