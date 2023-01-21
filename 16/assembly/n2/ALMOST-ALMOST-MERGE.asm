.MODEL SMALL
.STACK 100H

.DATA
N DW ?
ARR DW 50 DUP (?)
INV_I DW ?
I DW ?
J DW ?

.CODE

MAIN PROC
    MOV AX, @DATA
    MOV DS, AX 
    
    LEA SI, ARR
    
    CALL NUM_INPUT
    CALL ENDL 
    MOV N, DX
    MOV CX, N
    
    FOR1M:       
        XOR DX,DX
        CALL NUM_INPUT
        MOV WORD PTR [SI], DX
        INC SI
        INC SI
    LOOP FOR1M 
         
    CALL ENDL
    
    LEA SI, ARR
    CALL INVERSION_INDEX
    
    LEA SI, ARR
    LEA DI, ARR
    CALL ENDL
    CALL MERGE_SORT
    CALL ENDL  
    
    LEA SI, ARR
    MOV CX, N
    FOR2M:
        MOV DX, [SI]
        CALL PRINT_NUM
        CALL SPACE
        INC SI
        INC SI
    LOOP FOR2M
          
    
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
        JE THEN
        CMP AL, ' '
        JE THEN 
        JE OR_ELSE
        THEN:
        JE END_WHILE1 
        
         
        OR_ELSE:
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

ENDL PROC 
    PUSH AX
    PUSH DX
    MOV AH, 2
    MOV DL, 13
    INT 21H
    MOV DL, 10
    INT 21H
    POP DX
    POP AX
    RET
ENDL ENDP  

SPACE PROC 
    PUSH AX
    PUSH DX
    MOV AH, 2
    MOV DL, ' '
    INT 21H
    POP DX
    POP AX
    RET
SPACE ENDP   


INVERSION_INDEX PROC; FIND INVERSION ID OF ARR AT SI
    PUSH AX
    PUSH BX
    PUSH DX
    XOR DX, DX
    MOV CX, N
    DEC CX   
    FOR_INV:
        MOV AX, [SI]
        MOV BX, [SI+1] 
        CMP AX, BX
            JG END_FOR_INV
        INC SI
        INC DX
    LOOP FOR_INV    
    END_FOR_INV:
    
    INC DX
    MOV INV_I, DX
    POP DX
    POP BX
    POP AX
    RET
INVERSION_INDEX ENDP

MERGE_SORT PROC
    PUSH AX
    PUSH BX
    PUSH CX
    PUSH DX
      
    XOR AX, AX
    MOV BX, INV_I
    MOV CX, N
    
    M_LOOP:
    CMP BX, CX
    JE END_M_LOOP
        LEA SI, ARR
        ADD SI, AX
        ADD SI, AX
        MOV CX, [SI]
        LEA SI, ARR
        ADD SI, BX
        ADD SI ,BX
        MOV DX, [SI]
        CMP CX, DX
        JG M_ELSE1
            MOV DX, CX
            CALL PRINT_NUM
            CALL SPACE
            INC AX    
            JMP END_M_IF1
        M_ELSE1:
            ;MOV DX, [DI]
            CALL PRINT_NUM
            CALL SPACE
            INC BX  
        END_M_IF1:
        MOV CX, N
    JMP M_LOOP
    END_M_LOOP:
      
    
    POP DX
    POP CX
    POP BX
    POP AX
    RET
MERGE_SORT ENDP
    

END MAIN