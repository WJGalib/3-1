.MODEL SMALL 
.STACK 100H 
.DATA
.CODE 
MAIN PROC 
    MOV AX, 1 
    
    MOV CX, 10
    TOP:
    SHL AX, 1   ; shift left
    LOOP TOP  

	; interrupt to exit
    MOV AH, 4CH
    INT 21H
    
  
MAIN ENDP 
END MAIN 


