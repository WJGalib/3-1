.MODEL SMALL 
.STACK 100H 
.DATA 
.CODE 
MAIN PROC
     
 ; input
 MOV AH, 1
 INT 21H
 ; stored in AL
 MOV CL, AL
 
 ; output
 MOV AH, 2
 ; shows ascii in DL
 MOV DL, 41
 INT 21H
  
  
 ;interrupt to exit
 MOV AH, 4CH
 INT 21H 
  
MAIN ENDP 
END MAIN 