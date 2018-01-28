	.sect	".text"
	.clink
	.global	__strasgi
        
__strasgi:  .asmfunc

;** -----------PROLOG---------------------------------------------------------*

           LDW     .D2T2   *B4++,B2     ;            
||         SHR     .S2X    A6,2,B0      ;     
||         SHR     .S1     A6,2,A1      ;      
      
           LDW     .D2T2   *B4++,B5     ;            
||         MV      .L1     A4, A0       ; Save dst

           LDW     .D2T2   *B4++,B6     ;            

           LDW     .D2T2   *B4++,B7     ;             

           LDW     .D2T2   *B4++,B8     ;            
||         SUB     .S2     B0,6,B0      ;

           LDW     .D2T2   *B4++,B9     ;             
||         MV      .L1X    B2,A3        ;           
||         CMPGT   .L2     B0,6,B1      ; Do we need to Loop anymore?

;** -----------KERNEL---------------------------------------------------------*
LOOP:

   [ B1]   B       .S2     LOOP 
|| [ B0]   LDW     .D2T2   *B4++,B2     ;            
|| [ B0]   SUB     .L2     B0,1,B0      ;      
|| [ A1]   STW     .D1T1   A3,*A4++     ;      
|| [ A1]   SUB     .S1     A1,1,A1      ;    
||         MV      .L1X    B5,A5        ;           
      
   [ B0]   LDW     .D2T2   *B4++,B5     ;            
|| [ B0]   SUB     .S2     B0,1,B0      ;   
|| [ A1]   STW     .D1T1   A5,*A4++     ;      
|| [ A1]   SUB     .S1     A1,1,A1      ;   
||         MV      .L1X    B6,A6        ;           

   [ B0]   LDW     .D2T2   *B4++,B6     ;            
|| [ B0]   SUB     .S2     B0,1,B0      ;   
|| [ A1]   STW     .D1T1   A6,*A4++     ;      
|| [ A1]   SUB     .S1     A1,1,A1      ;
||         MV      .L1X    B7,A7        ;           

   [ B0]   LDW     .D2T2   *B4++,B7     ;            
|| [ B0]   SUB     .S2     B0,1,B0      ;   
|| [ A1]   STW     .D1T1   A7,*A4++     ;      
|| [ A1]   SUB     .S1     A1,1,A1      ;   
||         MV      .L1X    B8,A8        ;           

   [ B0]   LDW     .D2T2   *B4++,B8     ;            
|| [ B0]   SUB     .S2     B0,1,B0      ;   
|| [ A1]   STW     .D1T1   A8,*A4++     ;      
|| [ A1]   SUB     .S1     A1,1,A1      ;   
||         MV      .L1X    B9,A9        ;           

   [ B0]   LDW     .D2T2   *B4++,B9     ;            
|| [ B0]   SUB     .S2     B0,1,B0      ;   
|| [ A1]   STW     .D1T1   A9,*A4++     ;      
|| [ A1]   SUB     .S1     A1,1,A1      ;   
||         MV      .L1X    B2,A3        ;           
||         CMPGT   .L2     B0,6,B1      ; Do we need to Loop anymore?

;** -----------EPILOG---------------------------------------------------------*

           RET     .S2     B3
|| [ A1]   STW     .D1T2   B2,*A4++     ;      
|| [ A1]   SUB     .S1     A1,1,A1      ;   
      
   [ A1]   STW     .D1T2   B5,*A4++     ;      
|| [ A1]   SUB     .S1     A1,1,A1      ;   

   [ A1]   STW     .D1T2   B6,*A4++     ;      
|| [ A1]   SUB     .S1     A1,1,A1      ;   

   [ A1]   STW     .D1T2   B7,*A4++     ;      
|| [ A1]   SUB     .S1     A1,1,A1      ;   

   [ A1]   STW     .D1T2   B8,*A4++     ;      
|| [ A1]   SUB     .S1     A1,1,A1      ;   

   [ A1]   STW     .D1T2   B9,*A4       ;      
||         MV      .L1     A0, A4       ; Restore dst

        .endasmfunc
