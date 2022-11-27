.MODEL SMALL 
.STACK 100H 
.DATA

NUMBER_STRING DB '00000$'

.CODE 
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    
    MOV AX, 12345
    CALL PRINT
    
    ; interrupt to exit
    MOV AH, 4CH
    INT 21H
MAIN ENDP


PRINT PROC
    
    LEA SI, NUMBER_STRING
    ADD SI, 5
    
    PRINT_LOOP:
        DEC SI
        
        MOV DX, 0
        ; DX:AX = 0000:AX
        
        MOV CX, 10
        DIV CX
        
        ADD DL, '0'
        MOV [SI], DL
        
        CMP AX, 0
        JNE PRINT_LOOP
    
    MOV DX, SI
    MOV AH, 9
    INT 21H
    
    RET

PRINT ENDP

END MAIN 


