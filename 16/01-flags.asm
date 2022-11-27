.MODEL SMALL 
.STACK 100H 
.DATA

.CODE 
MAIN PROC 

    MOV AX, 0FFFFH
    MOV BX, 01H
    ADD AX, BX
    
    MOV AX, 01
    MOV BX, 02
    SUB AX, BX
    
    MOV AX, 07FFFH
    MOV BX, 07FFFH
    ADD AX, BX
	
	; interrupt to exit
    MOV AH, 4CH
    INT 21H
  
MAIN ENDP 
END MAIN 


