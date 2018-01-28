/**********************************************************************************************************************
*                                        (c) COPYRIGHT by PAO Inteltech.                                             *
*                                               All rights reserved.                                                  *
***********************************************************************************************************************
* Module      : skd_dsp_arm_delay
* Description : ������ � ���������� �������� � ����������  1901��1�
* Author      : Konstantin Shiluaev
******************************************************************************
******************************************************************************
* Module's Description Record:
* ============================
* $State: Debug$
* $Revision: 0.0.0 $
* $Date: 2015/03/02 10:40:51 $
******************************************************************************/
#ifndef SKD_DSP_ARM_DELAY_H
#define SKD_DSP_ARM_DELAY_H

#include "stdio.h"

#include "skd_dsp_arm_memory.h"

extern unsigned long volatile dsp_TimerCounter;

/*Timer Reg*/
#define  	TIM                     0x0038
#define  	PRD                     0x0039
#define  	TCR                     0x003A

    /*��� ���� ����� � ��� ������� ��������� ������� ��� DSP � RISC ���������� ������������ ������ = 0xFFFF = 65535
    *  0xFFFF = 65535 �����[������������_������]  �������_hclk = 24 [���] = 24 000 000 [��]
    *  ����� 1 ���������� = 0.002730625 [c] = 2.730625 [��] //24 [���]
    *                       0.008191875 [c] = 8.191875 [��] //8  [���]
    *                       0.000682656 [c] = 0.68265  [��] //96 [���]
    * 
       ����� 1 ����       = 				  0.000125 [��] //8  [���]
    *                                                  [��] //24 [���]
    *                                                  [��] //96 [���] 
    *  //�������������� ����� ���������� 1[��] � 1 ���
    *  ��� ���� ����� � ��� ������� ��������� ������� ��� DSP � RISC ���������� ������������ ������ = 0x5DC0 = 24000
    *  �������_hclk = 24 [���] = 24 000 000 [��]
    *
    *         ����� 1 ���������� = 0.001 [c] =    1 [��] //24 [���]
    *  ��� ���� ����� � ��� ������� ��������� ������� ��� DSP � RISC ���������� ������������ ������ = 0x0018 = 24
    *         ����� 1 ���������� = 0.000001 [c] = 1 [���] //24 [���]   */
    
    /*16 ��������� ������ DSP ����*/
    //������� ������ ������� ����� �������� � ������� ������� �� �������� ���� ��������.
    //��� ������� 8  ���   1[c��] = ? ticks ,1[��]    = 0x1F40(8000)  [ticks] , 1[���] =0x0008(8) [ticks]
    //��� ������� 24 ���   1[c��] = ? ticks ,1[��]    = 0x5DC0(24000) [ticks] , 1[���] =0x0018(24)[ticks]
    //��� ������� 96 ���   1[c��] = ? ticks ,0.5[��]  = 0xBB80(48000) [ticks] , 1[���] =0x0060(96)[ticks]

    //����������� �������.                /*���������� ����������  ��� 1 �������*/
    //��� ������� 8   ���      1[���] =   1 �� *   (1000);
    //��� ������� 24  ���  =   1[���] =   1 �� *   (1000);
    //��� ������� 96  ���  =   1[���] =   0.5 �� * (2000);
	 
    /* ��������������� ������� ��� ��������: �����[�] = [������������ �����] /[�������] */
    /*������������ ��������� ����� DSP ����*/
    static const unsigned short DSP_TIMER_TICK_TEST = 1; 
    static const unsigned short DSP_TIMER_8MHz  = 0;
    static const unsigned short DSP_TIMER_24MHZ = 0;  
	static const unsigned short DSP_TIMER_96MHz = 0;  
   	/*����������� ���������� �������*/ 
	static const unsigned short SYSTIMER_MICROSECOND =0;
	static const unsigned short SYSTIMER_MILLISECOND =1;
	static const unsigned short SYSTIMER_SECOND =     0;
 
/*******************************************************************************
* Function Name  : unsigned short init_dsp_timer()
* Description    : ������������� ������� DSP ����������.
*******************************************************************************/
unsigned short init_dsp_timer()
{
// static unsigned short PRD_REG_value  = 0x5DC0;//0xFFFF;  //0-65535  //������� ������� 0x0000 - 0xFFFF
// static unsigned short TCR_TRRD_value = 0x0020;//0-15     //�������� ������� ������� = 0 (����)
 
  //Stop the timer by writing a 1 to TSS in TCR.
  write_16bit_unsigned_mem(TCR,0x0010);// STOP TIMER
  
  //��� ������������ ������������������ ���������� �����
  if(DSP_TIMER_TICK_TEST)
  {
   write_16bit_unsigned_mem(PRD,0xFFFF);// ������������� ������������ �������� 65535 ����� 
  }

  //��� 8 ���
  if(DSP_TIMER_8MHz) 
  { 
       if (SYSTIMER_MICROSECOND)
	   {
       write_16bit_unsigned_mem(PRD,0x0008);// set the PRD reg value
       }

       if(SYSTIMER_MILLISECOND)
	   {
       write_16bit_unsigned_mem(PRD,0x1F40);// set the PRD reg value
	   }

       if(SYSTIMER_SECOND)
	   {
       write_16bit_unsigned_mem(PRD,0x0000);// set the PRD reg value
	   }

  } //END DSP_TIMER_8MHz
 
  //��� 24 ���
   if(DSP_TIMER_24MHZ)
   {
         if(SYSTIMER_MICROSECOND)
  		 {
          write_16bit_unsigned_mem(PRD,0x0018);// set the PRD reg value
    	 }

         if(SYSTIMER_MILLISECOND)
	     {
         write_16bit_unsigned_mem(PRD,0x5DC0);// set the PRD reg value
	     }

         if(SYSTIMER_SECOND)
         { 
         write_16bit_unsigned_mem(PRD,0x0000);// set the PRD reg value 
         }
    }//END DSP_TIMER_24MHZ

  //��� 96 ���
  if (DSP_TIMER_96MHz) 
  {
        if (SYSTIMER_MICROSECOND)
		{
        write_16bit_unsigned_mem(PRD,0x0060);// set the PRD reg value
	    }

        if (SYSTIMER_MILLISECOND)
		{
        write_16bit_unsigned_mem(PRD,0xBB80);// set the PRD reg value
        }

        if(SYSTIMER_SECOND)
        {
        write_16bit_unsigned_mem(PRD,0x0000);// set the PRD reg value 
	    }
  
  }////END DSP_TIMER_96MHZ
 //Start the timer by reloading TCR to initialize TDDR.
 //write_16bit_unsigned_mem(TCR,TCR_TRRD_value);// START TIMER TSS=0 | TRB =1 |TRD=0x0
   
  return 1;
}
	
	
	
/*******************************************************************************
* Function Name  : void sys_timer_stop()
* Description    : ������� ������ � ������ 16 ��� = 2 ����� �� -32 768 �� 32 767
*******************************************************************************/
void sys_timer_stop()
{
  write_16bit_unsigned_mem(TCR,0x0010);// STOP TIMER
}	
/*******************************************************************************
* Function Name  : void sys_timer_start()
* Description    : ������� ������ � ������ 16 ��� = 2 ����� �� -32 768 �� 32 767
*******************************************************************************/	
void sys_timer_start()
{
  write_16bit_unsigned_mem(TCR,0x0020);// START TIMER TSS=0 | TRB =1 |TRD=0x0
}





////////////////////////////////�� 0 �� 65535//////////////////////////
/*��� ������ � ���������� ���������� �� ����� ���� �������������� �������� */
/*******************************************************************************
* Function Name  : void dsp_sys_timer_start_second(uint8_t second)
* Description    : ������ 0-60  [������]
*******************************************************************************/
void dsp_sys_timer_start_second(unsigned short second)
{
    //�������� ������
    dsp_TimerCounter = second;
    write_16bit_unsigned_mem(TCR,0x0020);// START TIMER TSS=0 | TRB =1 |TRD=0x0
} 


/*******************************************************************************
* Function Name  : void dsp_sys_timer_start_millisecond(uint16_t  millisecond)
* Description    : ������� ������ � ������ 16 ��� = 2 ����� �� 0 �� 65535
*******************************************************************************/
void dsp_sys_timer_start_millisecond(unsigned short  millisecond)
{
     
    dsp_TimerCounter = millisecond;
    //Start the timer by reloading TCR to initialize TDDR.
    write_16bit_unsigned_mem(TCR,0x0020);// START TIMER TSS=0 | TRB =1 |TRD=0x0
    

}

/*******************************************************************************
* Function Name  : void dsp_sys_timer_set_second_delay(uint8_t second)
* Description    : ������� ������ ������ 32 ��� �� ������ = 4 ����� �� -2 147 483 648  ��  2 147 483 647
*******************************************************************************/
void dsp_sys_timer_set_second_delay(unsigned short second)
{



}
/*******************************************************************************
* Function Name  : void dsp_sys_timer_set_millisecond_delay(uint16_t  millisecond)
* Description    : ������� ������ � ������ 32 ��� �� ������ = 4 ����� �� -2 147 483 648  ��  2 147 483 647
*******************************************************************************/
void dsp_sys_timer_set_millisecond_delay(unsigned short  millisecond)
{
	   dsp_sys_timer_start_second(millisecond);
	   while(dsp_TimerCounter)
	   {
	   }
       sys_timer_stop(); 
}

/*******************************************************************************
* Function Name  : void dsp_sys_timer_set_millisecond_delay(uint16_t  millisecond)
* Description    : ���� ������� �������� ����� �� �������.
*******************************************************************************/
unsigned short get_timer_tick_value()
{
  unsigned short val=0x0000;
  val=read_16bit_unsigned_mem(0x0038);
  
  return val;
}





/////////////////////////////////////////////////////////////////////////
#endif /* SKD_DSP_ARM_DELAY_H */
