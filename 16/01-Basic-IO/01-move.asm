.MODEL SMALL 
.STACK 100H 
.DATA

.CODE 
MAIN PROC 
 MOV AX, 1
 MOV BX, 2H       
 MOV AX, BX
  
 ; interrupt to exit
 MOV AH, 4CH
 INT 21H 
  
MAIN ENDP 
END MAIN 


