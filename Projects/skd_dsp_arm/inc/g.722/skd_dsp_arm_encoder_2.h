/**********************************************************************************************************************
*                                        (c) COPYRIGHT by PAO Inteltech.                                             *
*                                               All rights reserved.                                                  *
***********************************************************************************************************************
* Module      : skd_dsp_arm_g722.h
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
#ifndef SKD_DSP_ARM_ENCODER2_H
#define SKD_DSP_ARM_ENCODER2_H



static inline signed short saturate_encoder2(signed short amp)
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


static void block4_encoder2(struct g722_init_encode_structure *g722e, int band, int d)
{
   
   
   // int wd1;
   // int wd2;
   // int wd3;
   // int i;
    long wd1;
    long wd2;
    long wd3;
    long i;

 


    // Block 4, RECONS
    g722e->band[band].d[0] = d;
    g722e->band[band].r[0] = saturate_encoder2(g722e->band[band].s + d);

    // Block 4, PARREC 
    g722e->band[band].p[0] = saturate_encoder2(g722e->band[band].sz + d);

    // Block 4, UPPOL2 
    for (i = 0;  i < 3;  i++)
        g722e->band[band].sg[i] = g722e->band[band].p[i] >> 15;
    wd1 = saturate_encoder2(g722e->band[band].a[1] << 2);

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

    g722e->band[band].ap[1] = saturate_encoder2(wd1 + wd2);
    wd3 = saturate_encoder2(15360 - g722e->band[band].ap[2]);
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
        g722e->band[band].bp[i] = saturate_encoder2(wd2 + wd3);
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
    wd1 = saturate_encoder2(g722e->band[band].r[1] + g722e->band[band].r[1]);
    wd1 = (g722e->band[band].a[1]*wd1) >> 15;
    wd2 = saturate_encoder2(g722e->band[band].r[2] + g722e->band[band].r[2]);
    wd2 = (g722e->band[band].a[2]*wd2) >> 15;
    g722e->band[band].sp = saturate_encoder2(wd1 + wd2);

    // Block 4, FILTEZ 
    g722e->band[band].sz = 0;
    for (i = 6;  i > 0;  i--)
    {
        wd1 = saturate_encoder2(g722e->band[band].d[i] + g722e->band[band].d[i]);
        g722e->band[band].sz += (g722e->band[band].b[i]*wd1) >> 15;
    }
    g722e->band[band].sz = saturate_encoder2(g722e->band[band].sz);

    // Block 4, PREDIC
    g722e->band[band].s = saturate_encoder2(g722e->band[band].sp + g722e->band[band].sz);
}

int g722_encoder2(struct g722_init_encode_structure *g722e, unsigned char g722_data[], const signed short amp[], int len)
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
        el = saturate_encoder2(xlow - g722e->band[0].s);

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

        block4_encoder2(g722e, 0, dlow);
        
        if (g722e->eight_k)
        {
            // Just leave the high bits as zero 
            code = (0xC0 | ilow) >> (8 - g722e->bits_per_sample);
        }
        else
        {
            // Block 1H, SUBTRA 
            eh = saturate_encoder2(xhigh - g722e->band[1].s);

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

            block4_encoder2(g722e, 1, dhigh);
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
              g722_data[g722_bytes++] = (unsigned char) code;
		     // printf("data=%d\n\r",g722_bytes);

		}
    }//END FOR LEN 
  //printf("all_bytes=%d\n\r", g722_bytes);
  return g722_bytes;
}

#endif /* SKD_DSP_ARM_ENCODER1_H */



