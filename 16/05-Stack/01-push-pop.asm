.MODEL SMALL 
.STACK 100H 
.DATA

ARR DW 1,2,3,4,5

.CODE 
MAIN PROC
    ; init DS
    MOV AX, @DATA
    MOV DS, AX
    
    MOV AX, 2
    MOV BX, 3
    
    PUSH AX
    PUSH BX
    
    MOV AX, 0
    MOV BX, 0
    
    POP BX
    POP AX
    
    ; interrupt to exit
    MOV AH, 4CH
    INT 21H
    
  
MAIN ENDP 
END MAIN 


