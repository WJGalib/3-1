.MODEL SMALL 
.STACK 100H 

.DATA
FOO DB 10
BAR DW 200

.CODE 
MAIN PROC
    ; load data segment address
    MOV AX, @DATA
    MOV DS, AX
     
    MOV AX, BAR
    
    MOV BL, 1
    MOV BH, 2
    MOV BAR, BX
  
    ; interrupt to exit
    MOV AH, 4CH
    INT 21H 
  
MAIN ENDP 
END MAIN 


