.MODEL SMALL 
.STACK 100H 
.DATA  
.CODE 
MAIN PROC
    
    MOV AX, 07FFFh
    MOV BX, 08000h
    CMP AX, BX
    
    JA CASE_JA   ; unsigned jump
    JG CASE_JG   ; signed jump
    
    
    CASE_JA:
    MOV CX, 1
    JMP END_CASE
    
    CASE_JG:
    MOV CX, 2
    JMP END_CASE
    
    
    END_CASE:
    
    
	MOV AH, 4CH
    INT 21H
MAIN ENDP 
END MAIN 