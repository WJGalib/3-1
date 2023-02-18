.CODE
main PROC
	MOV AX, @DATA
	MOV DS, AX
	PUSH BP
	MOV BP, SP
	SUB SP, 12
L1:
	MOV AX, 1
	MOV i, AX
L2:
	MOV AX, i
	CALL print_output
	CALL new_line
L3:
	MOV j, AX
L4:
	MOV AX, j
	CALL print_output
	CALL new_line
L5:
	MOV [BP-2], AX
L6:
	MOV AX, [BP-2]
	CALL print_output
	CALL new_line
L7:
	MOV [BP-6], AX
L8:
	MOV AX, [BP-6]
	CALL print_output
	CALL new_line
L9:
	MOV [BP-8], AX
L10:
	MOV AX, [BP-8]
	CALL print_output
	CALL new_line
L11:
	MOV [BP-10], AX
L12:
	MOV AX, [BP-10]
	CALL print_output
	CALL new_line
L13:
	MOV [BP-12], AX
L14:
	MOV AX, [BP-12]
	CALL print_output
	CALL new_line
L15:
	MOV [BP-12], AX
L16:
	MOV AX, [BP-12]
	CALL print_output
	CALL new_line
L17:
	MOV AX, p
L18:
	MOV AX, [BP-12]
	CALL print_output
	CALL new_line
L19:
	MOV [BP-2], AX
L20:
	MOV AX, [BP-2]
	CALL print_output
	CALL new_line
	ADD SP, 12
	POP BP
main ENDP
