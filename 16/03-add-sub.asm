.MODEL SMALL 
.STACK 100H 
.DATA 
.CODE 
MAIN PROC
     
    MOV AX, 3
    MOV BX, 5
    ADD AX, BX   ; stores 8 in AX
    
    MOV AX, 3
    MOV BX, 5
    SUB AX, BX   ; stores -2 in AX
  
  
    ;interrupt to exit
    MOV AH, 4CH
    INT 21H 
  
MAIN ENDP 
END MAIN 