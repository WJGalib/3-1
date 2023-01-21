.MODEL SMALL 
.STACK 100H 
.DATA

.CODE 
MAIN PROC 
    
    MOV CX, 0
    
    MOV AX, 2
    CMP AX, 2
    JE EQUAL
    
    MOV CX, 1
    
    EQUAL:
    
    MOV AX, 4
    MOV BX, 3
    CMP AX, BX
    JG GREATER
    
    MOV CX, 1
    
    GREATER:
    
    MOV AX, 4
    MOV BX, 3
    CMP AX, BX 
    JL LOWER
    
    MOV CX, 1
    
    LOWER:
    MOV CX, 2
	
	; interrupt to exit
    MOV AH, 4CH
    INT 21H
    
  
MAIN ENDP 
END MAIN 


