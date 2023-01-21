.MODEL SMALL
.STACK 100H
.DATA    
    OSTR DB 'ODD!', '$'
    ESTR DB 'EVEN!', '$'
.CODE
MAIN PROC       
    MOV AX, @DATA
    MOV DS, AX
    
    MOV AH, 1
    INT 21H
    
    MOV AH, 09H
    
    TEST AL, 1;
        JZ IFEVEN
        LEA DX, OSTR 
        JMP ENDIF
    IFEVEN:
        LEA DX, ESTR
    ENDIF:
    INT 21H
  
    MOV AH, 4CH
    INT 21H
    
MAIN ENDP
END MAIN