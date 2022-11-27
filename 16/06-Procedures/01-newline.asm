.MODEL SMALL 
.STACK 100H 
.DATA

MSG DB 'HELLO', '$'
CR EQU 13
LF EQU 10

.CODE 
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    LEA DX, MSG
    MOV AH, 9
    INT 21H
    
    CALL NEWLINE
    
    
    LEA DX, MSG
    MOV AH, 9
    INT 21H
    
    ; interrupt to exit
    MOV AH, 4CH
    INT 21H
MAIN ENDP


NEWLINE PROC
    MOV AH, 2
    MOV DL, CR
    INT 21H
    MOV DL, LF
    INT 21H
    RET
NEWLINE ENDP

END MAIN 


