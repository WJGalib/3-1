.MODEL SMALL 
.STACK 100H 
.DATA

.CODE 
MAIN PROC 
    
    MOV AX, 0
    
    ; if AX < 0: BX = -1
    ; else if AX = 0: BX = 0
    ; else: BX = 1
    
    CMP AX, 0
    JL NEGATIVE
    JE ZERO
    JG POSITIVE
    
    
    ; write cases first
    ; if AX < 0
    NEGATIVE:
    MOV BX, -1
    JMP END_CASE
    
    ; elif AX = 0
    ZERO:
    MOV BX, 0
    JMP END_CASE
    
    ; else
    POSITIVE:
    MOV BX, 1
    JMP END_CASE
    
    ; jump to end after finishing task inside case
    END_CASE:
      

	; interrupt to exit
    MOV AH, 4CH
    INT 21H
    
  
MAIN ENDP 
END MAIN 


