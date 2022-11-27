.MODEL SMALL 
.STACK 100H 
.DATA

.CODE 
MAIN PROC 
    
    MOV CX, 1
    JMP LABEL
    
    MOV CX, 2
    
    LABEL:
    MOV CX, 0
	
	; interrupt to exit
    MOV AH, 4CH
    INT 21H
    
  
MAIN ENDP 
END MAIN 


