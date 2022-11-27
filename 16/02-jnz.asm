.MODEL SMALL 
.STACK 100H 
.DATA

.CODE 
MAIN PROC 

    MOV AH, 2		; print char function
    MOV CX, 26		; 26 characters
    MOV DL, 65		; set DL to 'A'
    
PRINT_LOOP:
    INT 21H			; print DL
    INC DL			; increase DL
    DEC CX			; decrement CX
    JNZ PRINT_LOOP	; if CX != 0, jump
	
	; interrupt to exit
    MOV AH, 4CH
    INT 21H
  
MAIN ENDP 
END MAIN 


