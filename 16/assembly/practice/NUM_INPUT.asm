.MODEL SMALL
.STACK 100H

.DATA


.CODE

MAIN PROC
    MOV AX, @DATA
    MOV DS, AX 
    
    CALL NUM_INPUT 
    MOV BX, DX
    
    MOV AH, 2
    MOV DL, 13
    INT 21H
    MOV DL, 10
    INT 21H
          
    MOV DX, BX      
    CALL PRINT_NUM
    
    MOV AH, 4CH
    INT 21H
    
MAIN ENDP
             
             

NUM_INPUT PROC  ;STORES NUMBER IN DX
    
    PUSH AX
    PUSH BX
    PUSH CX
    XOR BX, BX
    XOR AX, AX
    XOR DX, DX 
    XOR CX, CX

    WHILE1:
    ;CMP AL, 0DH
    ;JE END_WHILE1
        MOV AH, 1
        INT 21H
        XOR AH, AH       
          
        CMP AL, 0DH
        JE END_WHILE1  

        CMP AL, '-'
        JNE END_IF1
            MOV CX, 1
            JMP WHILE1
        END_IF1:
        
        AND AL, 000FH
        MOV BL, AL
        MOV AX, DX
        MOV BH, 10
        MUL BH
        XOR BH, BH
        MOV DX, AX
        ADD DX, BX
    JMP WHILE1 
    END_WHILE1:

    CMP CX, 1
    JNE END_IF2
        NEG DX
    END_IF2:
    
    POP CX
    POP BX
    POP AX 
    RET     
    
NUM_INPUT ENDP
       
       
PRINT_NUM PROC; PRINTS NUMBER IN DX
    PUSH AX
    PUSH BX
    PUSH CX
    XOR CX, CX 
    
    CMP DX, 0
    JNL END_IF3
        NEG DX
        MOV CH, 1
    END_IF3:

    WHILE2:
    CMP DX, 0 
    JE END_WHILE2   
        MOV AX, DX
        MOV BH, 10
        DIV BH 
        XOR BH, BH
        MOV BL, AH
        AND BX, 000FH
        PUSH BX
        INC CL
        XOR AH, AH
        MOV DX, AX   
        JMP WHILE2
    END_WHILE2:

    MOV AH, 2
    CMP CH, 1
    JNE END_IF4
        MOV DL, '-'
        INT 21H
    END_IF4:

    XOR CH, CH
    
    FOR1:
        POP DX  
        ADD DX, 48
        INT 21H
    LOOP FOR1
    
    POP CX
    POP BX
    POP AX
    RET
PRINT_NUM ENDP

END MAIN