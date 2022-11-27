.MODEL SMALL 
.STACK 100H 
.DATA

.CODE 
MAIN PROC 
    
    MOV AX, 11
    
    ; if AX > 10, then BX = 1
    ; else, BX = 0
    
    CMP AX, 10
    JNG ELSE
    
    ; if true
    MOV BX, 1
    JMP END_IF
    
    ; if not true
    ELSE:
    MOV BX, 0
         
    END_IF:  

	; interrupt to exit
    MOV AH, 4CH
    INT 21H
    
  
MAIN ENDP 
END MAIN 


