.MODEL SMALL 
.STACK 100H 
.DATA

ARR DW 1,2,3,4,5

.CODE 
MAIN PROC
    ; init DS
    MOV AX, @DATA
    MOV DS, AX
    
    ; get 0th word
    MOV AX, ARR[SI]
    
    ; get 1st word
    ADD SI, 2
    MOV AX, ARR[SI]  

	; interrupt to exit
    MOV AH, 4CH
    INT 21H
    
  
MAIN ENDP 
END MAIN 


