.MODEL SMALL 
.STACK 100H 
.DATA

ARR DW 1,2,3,4,5

.CODE 
MAIN PROC
    ; init DS
    MOV AX, @DATA
    MOV DS, AX
    
    LEA SI, ARR
    ; MOV [SI], 2
    MOV WORD PTR [SI], 2   

	; interrupt to exit
    MOV AH, 4CH
    INT 21H
    
  
MAIN ENDP 
END MAIN 


