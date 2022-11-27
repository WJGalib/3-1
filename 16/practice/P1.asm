.MODEL SMALL    
.STACK 100H
.DATA
    X DB 0
    Y DB 0
    TEMP DB 0     
    PRX DB 'Enter value of X: ', '$'
    PRY DB 'Enter value of Y: ', '$'
    SHOWX DB 'The current value of X is ', '$'
    SHOWY DB 'The current value of Y is ', '$' 
    SWPSTR DB 'Swapping values...', '$'
    
.CODE 
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
        
    ;prompting x    
    LEA DX, PRX
    MOV AH, 09H
    INT 21H
    ;scanning x
    MOV AH, 1
    INT 21H
    MOV X, AL  
               
    MOV DL, 13
    MOV AH, 2
    INT 21H           
    MOV DL, 10
    MOV AH, 2
    INT 21H
    
    ;prompting y   
    LEA DX, PRY
    MOV AH, 09H
    INT 21H
    ;scanning y
    MOV AH, 1
    INT 21H
    MOV Y, AL    
    
    MOV DL, 13
    MOV AH, 2
    INT 21H           
    MOV DL, 10
    MOV AH, 2
    INT 21H
    
    ;show X
    LEA DX, SHOWX
    MOV AH, 09H
    INT 21H     
    MOV DL, X
    MOV AH, 2
    INT 21H   
    
    MOV DL, 13
    MOV AH, 2
    INT 21H           
    MOV DL, 10
    MOV AH, 2
    INT 21H
    
    ;show y
    LEA DX, SHOWY
    MOV AH, 09H
    INT 21H       
    MOV DL, Y
    MOV AH, 2
    INT 21H    
    
    MOV DL, 13
    MOV AH, 2
    INT 21H           
    MOV DL, 10
    MOV AH, 2
    INT 21H  
    
    LEA DX, SWPSTR
    MOV AH, 09H
    INT 21H  
    
    MOV DL, 13
    MOV AH, 2
    INT 21H           
    MOV DL, 10
    MOV AH, 2
    INT 21H  
    
    MOV AL, X
    MOV BL, Y
    MOV X, BL
    MOV Y, AL
    
    
    ;show X
    LEA DX, SHOWX
    MOV AH, 09H
    INT 21H     
    MOV DL, X
    MOV AH, 2
    INT 21H   
    
    MOV DL, 13
    MOV AH, 2
    INT 21H           
    MOV DL, 10
    MOV AH, 2
    INT 21H
    
    ;show y
    LEA DX, SHOWY
    MOV AH, 09H
    INT 21H       
    MOV DL, Y
    MOV AH, 2
    INT 21H    
    
    MOV DL, 13
    MOV AH, 2
    INT 21H           
    MOV DL, 10
    MOV AH, 2
    INT 21H  
    
    MOV AH, 4CH
    INT 21H
    
MAIN ENDP
END MAIN
