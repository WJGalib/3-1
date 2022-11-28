.MODEL SMALL
.STACK 100H
.DATA

.CODE

; 1905084        
        
MAIN PROC 
       
    MOV BH, 'z'
    ; STORING LOWEST IN BH           
    MOV AH, 1           
    WHILE1: 
        INT 21H        ; input
        CMP AL, 'a'
        JNGE END_WHILE1
        CMP AL, 'z'
        JNLE END_WHILE1
        
        CMP AL, BH     ;  IF...
        JNL END_IF
            MOV BH, AL ; UPDATING LOWEST
        END_IF:                    
        
    JMP WHILE1
    END_WHILE1:
       
        
    MOV AH, 2    ; printing
    MOV DL, 13   ; .
    INT 21H      ; .
    MOV DL, 10   ; .
    INT 21H      ; newline
       
                    
    SUB BH, 32   ; convert to uppercase
    MOV AH, 2
    MOV DL, BH
    INT 21H

    
    MOV AH, 4CH
    INT 21H

MAIN ENDP
END MAIN