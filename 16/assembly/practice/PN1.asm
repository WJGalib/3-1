.MODEL SMALL
.STACK 100H
.DATA
.CODE
MAIN PROC
    MOV AH, 1
    INT 21H  

    MOV BL, 2
    MUL BL
    MOV BX, 284
    XOR AH, AH
    SUB BX, AX
    MOV DL, BL
    
    MOV AH, 2
    INT 21H
    
MAIN ENDP
END MAIN
        