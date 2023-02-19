.MODEL SMALL
.STACK 1000H
.DATA
	CR EQU 0DH
	LF EQU 0AH
	number DB "00000$"
.CODE
main PROC
	MOV AX, @DATA
	MOV DS, AX
	PUSH BP
	MOV BP, SP
	SUB SP, 8
L25:		;line-3
	MOV AX, 0
	MOV [BP-2], AX
L26:		;line-5
	MOV AX, 6
	MOV DX, AX
	MOV AX, [BP-2]
	CMP AX, DX
	JL L27
	JMP L23
L27:		;line-5
	MOV AX, [BP-2]
	CALL print_output
	CALL new_line
L28:		;line-6
	MOV AX, [BP-2]
	PUSH AX
	INC AX
	MOV [BP-2], AX
	POP AX
	JMP L26
L23:		;line-5
	MOV AX, 4
	MOV [BP-6], AX
L21:		;line-9
	MOV AX, 6
	MOV [BP-8], AX
L19:		;line-10
L43:		;line-11
	MOV AX, 0
	MOV DX, AX
	MOV AX, [BP-6]
	CMP AX, DX
	JG L44
	JMP L17
L44:		;line-11
	MOV AX, [BP-8]
	MOV BX, AX
	MOV AX, 3
	ADD AX, BX
	MOV [BP-8], AX
L48:		;line-12
	MOV AX, [BP-6]
	PUSH AX
	DEC AX
	MOV [BP-6], AX
	POP AX
	JMP L43
L17:		;line-13
	MOV AX, [BP-8]
	CALL print_output
	CALL new_line
L15:		;line-16
	MOV AX, [BP-6]
	CALL print_output
	CALL new_line
L13:		;line-17
	MOV AX, 4
	MOV [BP-6], AX
L11:		;line-19
	MOV AX, 6
	MOV [BP-8], AX
L9:		;line-20
L63:		;line-22
	MOV AX, [BP-6]
	PUSH AX
	DEC AX
	MOV [BP-6], AX
	POP AX
	CMP AX, 0
	JNE L64
	JMP L7
L64:		;line-22
	MOV AX, [BP-8]
	MOV BX, AX
	MOV AX, 3
	ADD AX, BX
	MOV [BP-8], AX
	JMP L63
L7:		;line-23
	MOV AX, [BP-8]
	CALL print_output
	CALL new_line
L5:		;line-26
	MOV AX, [BP-6]
	CALL print_output
	CALL new_line
L3:		;line-27

	ADD SP, 8
	POP BP
	MOV AX, 4CH
	INT 21H
main ENDP
new_line proc
	push ax
	push dx
	mov ah,2
	mov dl,cr
	int 21h
	mov ah,2
	mov dl,lf
	int 21h
	pop dx
	pop ax
	ret
new_line endp

print_output proc  ;print what is in ax
	push ax
	push bx
	push cx
	push dx
	push si
	lea si,number
	mov bx,10
	add si,4
	cmp ax,0
	jnge negate
	print:
	xor dx,dx
	div bx
	mov [si],dl
	add [si],'0'
	dec si
	cmp ax,0
	jne print
	inc si
	lea dx,si
	mov ah,9
	int 21h
	pop si
	pop dx
	pop cx
	pop bx
	pop ax
	ret
	negate:
	push ax
	mov ah,2
	mov dl,'-'
	int 21h
	pop ax
	neg ax
	jmp print
print_output endp
END main
