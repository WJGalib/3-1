.MODEL SMALL
.STACK 100H

.DATA
    Z DB ? 
    X DB ?
    Y DB ?  
    PRX DB 'ENTER VALUE OF X: ', '$'
    PRY DB 'ENTER VALUE OF Y: ', '$'
    E1 DB 'Z = X-2Y = ', '$'
    E2 DB 'Z = 25-(X+Y) = ', '$'
    E3 DB 'Z = 2X-3Y = ', '$'
    E4 DB 'Z = Y-X-1 = ', '$'

.CODE 

MAIN PROC 
    MOV AX, @DATA
    MOV DS, AX
    
    ; PROMPT X
    LEA DX, PRX
    MOV AH, 09H
    INT 21H
    ; INPUT X
    MOV AH, 1
    INT 21H
    SUB AL, 48
    MOV X, AL
    
    ; NEWLINE
    MOV AH, 2
    MOV DL, 13
    INT 21H
    MOV DL, 10
    INT 21H     
    
    ; PROMPT y
    LEA DX, PRY
    MOV AH, 09H
    INT 21H
    ; INPUT y
    MOV AH, 1
    INT 21H
    SUB AL, 48
    MOV Y, AL     
    
    ; CALC E1
    ;MOV AL, Y
    ;MOV BL, X
    ;MOV BH, 2
    ;MUL BH
    ;SUB BL, AL
    ;MOV Z, BL
    MOV Z, 123   
    
    ; PRINT Z
    MOV AH, 2
    MOV DL, 13
    INT 21H
    MOV DL, 10
    INT 21H
    MOV AH, 09H
    LEA DX, E1
    INT 21H    
    
    MOV CX, 0     
    MOV AL, Z
    XOR AH, AH
    WHILE1:
    CMP AL, 0
    JZ END_WHILE1
        XOR AH, AH
        MOV BL, 10
        DIV BL
    INC CX
    JMP WHILE1
    END_WHILE1:
    MOV DH, CL
    
    DEC CX     
    MOV AL, Z
    XOR AH, AH
    WHILE2:
    CMP AL, 0
    JZ END_WHILE2
        XOR AH, AH
        MOV BL, 10
        DIV BL
    FOR2:
        MOV AH, 2
        MOV DL AL
        INT 21H
    
    JMP WHILE2
    END_WHILE2:        
        
    MOV AH, 4CH
    INT 21H
        
MAIN ENDP
END MAIN