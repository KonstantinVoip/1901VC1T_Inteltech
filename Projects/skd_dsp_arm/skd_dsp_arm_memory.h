/**********************************************************************************************************************
*                                        (c) COPYRIGHT by PAO Inteltech.                                             *
*                                               All rights reserved.                                                  *
***********************************************************************************************************************
* Module      : skd_dsp_arm_memory
* Description : ������ � ������� DSP ���� 1901��1�
* Author      : Konstantin Shiluaev
******************************************************************************
******************************************************************************
* Module's Description Record:
* ============================
* $State: Debug$
* $Revision: 0.0.0 $
* $Date: 2015/03/02 10:40:51 $
******************************************************************************/
#ifndef SKD_DSP_ARM_MEMORY_H
#define SKD_DSP_ARM_MEMORY_H

/*���� ������ DSP ���� 1901��1�*/
/*signed short      16 bits 2s complement 		 -32 768 �� 32 767
* unsigned short    16 bits 2s complement		    0    �� 65 535
*
* signed long       32 bits 2s complement    -2 147 483 648  ��  2 147 483 647
* unsigned long     32 bits Binary 					0        ��  4 294 967 295
*
* double 			64 bits IEEE 32-bit 	1.175 494e-38    ��  3.40 282 346e+38 
*/


/* ���� � DSP 32 ����      
*  [�����] 0xC000 [��������]  
*                 11|22 | 33|44 
*
   ���� �  RISC   33|44 | 11|22 
*/



/*****************������ � 16 ������� ������� ***********/
////////////////////////////////�� -32 768 �� 32 767//////////////////////////
/*******************************************************************************
* Function Name  : signed short read_2bait_memory(const signed short memory_addr)
* Description    : ������� ������ ������ 16 ��� �� ������ = 2 ����� �� -32 768 �� 32 767
* input  value   : ����� ������ ������ ���� ������ ������������� :  �� 0x0000 �� 0xFFFF    
*******************************************************************************/
static inline signed short read_16bit_signed_mem(const unsigned short dsp_mem_addr)
{
   return  *(signed short*)(dsp_mem_addr);
}
/*******************************************************************************
* Function Name  : void write_2bait_memory(const signed short memaddr,c onst signed short mem_val)
* Description    : ������� ������ � ������ 16 ��� = 2 ����� �� -32 768 �� 32 767
* input  value   : dsp_mem_addr -> ����� ������ ������ ���� ������ ������������� :  �� 0x0000 �� 0xFFFF
*******************************************************************************/
static inline void write_16bit_signed_mem(const unsigned short dsp_mem_addr,const signed short mem_val)
{
 unsigned short  *dst;
 signed short    *src;
 
 dst = (unsigned short*)dsp_mem_addr;
 src = ((signed short*)&mem_val);
 * dst  = * src;
}


////////////////////////////////�� 0 �� 65535//////////////////////////
/*��� ������ � ���������� ���������� �� ����� ���� �������������� �������� */
/*******************************************************************************
* Function Name  : signed short read_2bait_memory(const signed short memory_addr)
* Description    : ������� ������ ������ 16 ��� �� ������ = 2 ����� �� 0 �� 65535
* input  value   : ����� ������ ������ ���� ������ ������������� :  �� 0x0000 �� 0xFFFF    
*******************************************************************************/
static inline unsigned short read_16bit_unsigned_mem(const unsigned short dsp_mem_addr)
{
   return  *(unsigned short*)(dsp_mem_addr);
}
/*******************************************************************************
* Function Name  : void write_2bait_memory(const signed short memaddr,c onst signed short mem_val)
* Description    : ������� ������ � ������ 16 ��� = 2 ����� �� 0 �� 65535
* input  value   : dsp_mem_addr -> ����� ������ ������ ���� ������ ������������� :  �� 0x0000 �� 0xFFFF
*******************************************************************************/
static inline void write_16bit_unsigned_mem(const unsigned short dsp_mem_addr,const unsigned short mem_val)
{
 unsigned short  *dst;
 unsigned short    *src;
 
 dst = (unsigned short*)dsp_mem_addr;
 src = ((unsigned short*)&mem_val);
 * dst  = * src;
}

/*********************������ � 32 ������� ������� **************/
/*******************************************************************************
* Function Name  : static inline signed long read_32bit_siged_mem(const unsigned short dsp_mem_addr)
* Description    : ������� ������ ������ 32 ��� �� ������ = 4 ����� �� -2 147 483 648  ��  2 147 483 647
* input  value   : dsp_mem_addr -> ����� ������ ������ ���� ������ ������������� :  �� 0x0000 �� 0xFFFF
*******************************************************************************/
static inline signed long read_32bit_siged_mem(const unsigned short dsp_mem_addr)
{
   return  *(signed long*)(dsp_mem_addr);
}

/*******************************************************************************
* Function Name  : void write_2bait_memory(const signed short memaddr,c onst signed short mem_val)
* Description    : ������� ������ � ������ 32 ��� �� ������ = 4 ����� �� -2 147 483 648  ��  2 147 483 647
* input  value   : dsp_mem_addr -> ����� ������ ������ ���� ������ ������������� :  �� 0x0000 �� 0xFFFF
*******************************************************************************/
static inline void write_32bit_signed_mem(const unsigned short dsp_mem_addr,const signed long mem_val)
{
 //�������� ������ ���� ��� �����
 /*����� �������� ������ ������ 32 ��� ���� �������� ������ 16 ��� 
  �� ���� ������ 32 ������ �������� ����������� ������ 16 ���*/
 signed short low_word;
 signed short high_word;
 signed long  l_mem_val;
 
  //����� ��������� �� ��� ����������� ��������� � �������� ���� �� ������
 unsigned short    *dst_high_value;
 unsigned short    *dst_low_value;
 
 unsigned short    *src_high_value;
 unsigned short    *src_low_value;


 low_word =(signed short)mem_val;
 l_mem_val=(mem_val&&0xFFFF0000)>>16;
 high_word=(signed short)l_mem_val;
  
 //����� ������� ����� 16 ��� high_word
 dst_high_value = (unsigned short*)dsp_mem_addr;
 src_high_value = ((unsigned short*)&high_word);
 * dst_high_value  = * src_high_value;

//����� ������� ����� 16 ���  low_word
 dst_low_value = (unsigned short*)dsp_mem_addr+1;
 src_low_value = ((unsigned short*)&low_word);
 * dst_low_value  = * src_low_value;

 

}
/*************************************************************************/
/*************************************************************************/
/*************************************************************************/
/*������� ������ � ������� ��� ����������� �������������� � �� DSP � RISC*/
/*************************************************************************/
/*************************************************************************/
/*************************************************************************/
static inline void write_16bit_unsigned_to_RISC(const unsigned short dsp_mem_addr,const unsigned short mem_val)
{
 unsigned short    *dst;
 unsigned short    *src;
 
 dst = (unsigned short*)dsp_mem_addr;
 src = ((unsigned short*)&mem_val);
 * dst  = * src;
}



/*******************************************************************************
* Function Name  : void write_2bait_memory(const signed short memaddr,c onst signed short mem_val)
* Description    : ������� ������ � ������ 16 ��� = 2 ����� �� -32 768 �� 32 767
* input  value   : dsp_mem_addr -> ����� ������ ������ ���� ������ ������������� :  �� 0x0000 �� 0xFFFF
*******************************************************************************/
static inline void write_16bit_signed_to_RISC(const unsigned short dsp_mem_addr,const signed short mem_val)
{
 unsigned short  *dst;
 signed short    *src;
 
 dst = (unsigned short*)dsp_mem_addr;
 src = ((signed short*)&mem_val);
 * dst  = * src;
}



/////////////////////////////////////////////////////////////////////////
static inline void write_32bit_signed_to_RISC(const unsigned short dsp_mem_addr,const signed long mem_val)
{
 //�������� ������ ���� ��� �����
 /*����� �������� ������ ������ 32 ��� ���� �������� ������ 16 ��� 
  �� ���� ������ 32 ������ �������� ����������� ������ 16 ���*/
 signed short low_word;
 signed short high_word;
 signed long  l_mem_val;
 
  //����� ��������� �� ��� ����������� ��������� � �������� ���� �� ������
 unsigned short    *dst_high_value;
 unsigned short    *dst_low_value;
 
 unsigned short    *src_high_value;
 unsigned short    *src_low_value;


 low_word =(signed short)mem_val;
 l_mem_val=(mem_val&0xFFFF0000)>>16;
 high_word=(signed short)l_mem_val;
  
 //��� ������ � ������ RISC ������ ������� high_word � low_word ������������� ������
 //���� ����� ������ ������ �������.

 //����� ������� ����� 16 ��� high_word
 dst_high_value = (unsigned short*)dsp_mem_addr+1;
 src_high_value = ((unsigned short*)&high_word);
 * dst_high_value  = * src_high_value;

//����� ������� ����� 16 ���  low_word
 dst_low_value = (unsigned short*)dsp_mem_addr;
 src_low_value = ((unsigned short*)&low_word);
 * dst_low_value  = * src_low_value;

}


#endif /* SKD_DSP_ARM_MEMORY_H */
