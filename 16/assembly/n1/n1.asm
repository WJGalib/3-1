.MODEL SMALL
.STACK 100H

.DATA

.CODE
MAIN PROC
    
    MOV AH, 4CH
    INT 21H
MAIN ENDP
END MAIN