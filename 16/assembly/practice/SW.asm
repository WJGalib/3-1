.MODEL SMALL 
.STACK 100H     

.DATA 
    N DW 11
    
.CODE 
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    MOV AX, N     
    MOV BL, 2
    DIV BL
    MOV BX, N
    MOV BH, AL ; bh stores n/2
     
    MOV AH, 2  ; print mode
    
    MOV CX, 0  ; ch=i, cL=j
    FOR1:
    CMP CH, BH
    JNL END_FOR1 
        
        MOV CL, 0 
        
        MOV DL, '['  ; print []
        INT 21H      ; .
        MOV DL, ']'  ; .
        INT 21H      ; print []
        
        INC CL
        FOR11:   
        CMP CL, BH
        JNL END_FOR11        ; FOR CHECK
            MOV DL, ' '
            INT 21H
            INT 21H
        INC CL          ; INC
        JMP FOR11    
        END_FOR11:
            
        MOV DL, '['  ; print []
        INT 21H      ; .
        MOV DL, ']'  ; .
        INT 21H      ; print []
        
        INC CL            
        FOR12:   
        CMP CL, BL
        JNL END_FOR12        ; FOR CHECK  
            CMP CH, 0;
            JNE ELSE12
                MOV DL, '['  ; print []
                INT 21H      ; .
                MOV DL, ']'  ; .
                INT 21H      ; print []
                JMP ENDIF12
            ELSE12:
                MOV DL, ' '
                INT 21H
                INT 21H
            ENDIF12:
        INC CL          ; INC
        JMP FOR12    
        END_FOR12:            
        
        MOV DL, 13
        INT 21H
        MOV DL, 10
        INT 21H
            
    INC CH
    JMP FOR1  
    END_FOR1:      
    
    MOV CL, 0
    FOR2:
    CMP CL, BL
    JNL END_FOR2
        MOV DL, '['  ; print []
        INT 21H      ; .
        MOV DL, ']'  ; .
        INT 21H      ; print []    
    INC CL
    JMP FOR2
    END_FOR2: 
    
    MOV DL, 13
    INT 21H
    MOV DL, 10
    INT 21H
     
    INC CH
    FOR3:
    CMP CH, BL
    JNL END_FOR3 
        
        MOV CL, 0
        MOV DH, BL
        DEC DH 
        FOR31:   
        CMP CL, BH
        JNL END_FOR31        ; FOR CHECK
            CMP CH, DH;
            JNE ELSE31
                MOV DL, '['  ; print []
                INT 21H      ; .
                MOV DL, ']'  ; .
                INT 21H      ; print []
                JMP ENDIF31
            ELSE31:
                MOV DL, ' '
                INT 21H
                INT 21H
            ENDIF31: 
        INC CL          ; INC
        JMP FOR31    
        END_FOR31:
            
        MOV DL, '['  ; print []
        INT 21H      ; .
        MOV DL, ']'  ; .
        INT 21H      ; print []
        
        INC CL            
        FOR32:   
        CMP CL, DH
        JNL END_FOR32        ; FOR CHECK     
            MOV DL, ' '
            INT 21H
            INT 21H
        INC CL          ; INC
        JMP FOR32    
        END_FOR32:            
                 
        MOV DL, '['  ; print []
        INT 21H      ; .
        MOV DL, ']'  ; .
        INT 21H      ; print []
        MOV DL, 13
        INT 21H
        MOV DL, 10
        INT 21H
            
    INC CH
    JMP FOR3  
    END_FOR3:    
    
	MOV AH, 4CH
    INT 21H
MAIN ENDP 
END MAIN 