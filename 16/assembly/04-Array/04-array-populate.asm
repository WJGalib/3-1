.MODEL SMALL 
.STACK 100H 
.DATA

ARR DB 26 DUP(?)

.CODE 
MAIN PROC
    ; init DS
    MOV AX, @DATA
    MOV DS, AX
    
    ; populate array with A-Z
    MOV AL, 'A'
    MOV SI, 0    
    
    MOV CX, 26
    POPULATE:
    MOV ARR[SI], AL
    INC SI
    INC AL
    LOOP POPULATE
      

	; interrupt to exit
    MOV AH, 4CH
    INT 21H
    
  
MAIN ENDP 
END MAIN 


