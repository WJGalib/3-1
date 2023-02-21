.MODEL SMALL
.STACK 1000H
.DATA
	CR EQU 0DH
	LF EQU 0AH
	number DB "00000$"
	V9711411497121 DW 16 DUP (0000H)
	V1021059895109101109 DW 24 DUP (0000H)
	V95106 DW 1 DUP (0000H)
	V11011710998101114 DW 1 DUP (0000H)
	V87798268 DW 1 DUP (0000H)
	V119111114100 DW 1 DUP (0000H)
.CODE
;Definition of fibonacci()
F10210598111110979999105 PROC
	PUSH BP
	MOV BP, SP
	MOV AX, 0
	MOV DX, AX
	LEA SI, V1021059895109101109		;variable 'fib_mem'

	PUSH AX
	PUSH BX
	PUSH CX
	PUSH DX
	MOV AX, [BP+4]		;variable 'n'
	ADD SI, AX
	ADD SI, AX
	POP DX
	POP CX
	POP BX
	POP AX
	MOV AX, [SI]		;variable 'fib_mem'
	CMP AX, DX
	JNE L5
	JMP L4
L5:				;line-11
	LEA SI, V1021059895109101109		;variable 'fib_mem'

	PUSH AX
	PUSH BX
	PUSH CX
	PUSH DX
	MOV AX, [BP+4]		;variable 'n'
	ADD SI, AX
	ADD SI, AX
	POP DX
	POP CX
	POP BX
	POP AX
	MOV AX, [SI]		;variable 'fib_mem'
	JMP L16
L16:				;line-11
	POP BP
	RET 2
L4:				;line-11
	MOV AX, 0
	MOV DX, AX
	MOV AX, [BP+4]		;variable 'n'
	CMP AX, DX
	JE L17
	JMP L19
L19:				;line-12
	MOV AX, 1
	MOV DX, AX
	MOV AX, [BP+4]		;variable 'n'
	CMP AX, DX
	JE L17
	JMP L3
L17:				;line-12
	MOV AX, [BP+4]		;variable 'n'
	LEA SI, V1021059895109101109		;variable 'fib_mem'

	PUSH AX
	PUSH BX
	PUSH CX
	PUSH DX
	MOV AX, [BP+4]		;variable 'n'
	ADD SI, AX
	ADD SI, AX
	POP DX
	POP CX
	POP BX
	POP AX
	MOV [SI], AX		;variable 'fib_mem'
L22:				;line-13
	LEA SI, V1021059895109101109		;variable 'fib_mem'

	PUSH AX
	PUSH BX
	PUSH CX
	PUSH DX
	MOV AX, [BP+4]		;variable 'n'
	ADD SI, AX
	ADD SI, AX
	POP DX
	POP CX
	POP BX
	POP AX
	MOV AX, [SI]		;variable 'fib_mem'
	JMP L35
L35:				;line-14
	POP BP
	RET 2
L3:				;line-14
	PUSH BX
	PUSH BX
	MOV AX, [BP+4]		;variable 'n'
	MOV BX, AX
	MOV AX, 1
	SUB AX, BX
	NEG AX
	POP BX
	PUSH AX
	CALL F10210598111110979999105		;Calling fibonacci()
	MOV BX, AX
	PUSH BX
	MOV AX, [BP+4]		;variable 'n'
	MOV BX, AX
	MOV AX, 2
	SUB AX, BX
	NEG AX
	POP BX
	PUSH AX
	CALL F10210598111110979999105		;Calling fibonacci()
	ADD AX, BX
	POP BX
	LEA SI, V1021059895109101109		;variable 'fib_mem'

	PUSH AX
	PUSH BX
	PUSH CX
	PUSH DX
	MOV AX, [BP+4]		;variable 'n'
	ADD SI, AX
	ADD SI, AX
	POP DX
	POP CX
	POP BX
	POP AX
	MOV [SI], AX		;variable 'fib_mem'
L2:				;line-16
	LEA SI, V1021059895109101109		;variable 'fib_mem'

	PUSH AX
	PUSH BX
	PUSH CX
	PUSH DX
	MOV AX, [BP+4]		;variable 'n'
	ADD SI, AX
	ADD SI, AX
	POP DX
	POP CX
	POP BX
	POP AX
	MOV AX, [SI]		;variable 'fib_mem'
	JMP L54
L54:				;line-17
	POP BP
	RET 2
F10210598111110979999105 ENDP		;End of definiton of fibonacci()

;Definition of factorial()
F102979911611111410597108 PROC
	PUSH BP
	MOV BP, SP
	SUB SP, 2
	MOV AX, 1
	MOV DX, AX
	MOV AX, [BP+4]		;variable 'n'
	CMP AX, DX
	JE L59
	JMP L58
L59:				;line-21
	MOV AX, [BP+4]		;variable 'n'
	JMP L64
L64:				;line-21
	ADD SP, 2
	POP BP
	RET 2
L58:				;line-21
L57:				;line-22
	PUSH CX
	MOV AX, [BP+4]		;variable 'n'
	MOV CX, AX
	PUSH BX
	MOV AX, [BP+4]		;variable 'n'
	MOV BX, AX
	MOV AX, 1
	SUB AX, BX
	NEG AX
	POP BX
	PUSH AX
	CALL F102979911611111410597108		;Calling factorial()
	MUL CX
	POP CX
	MOV [BP-2], AX		;variable 'k'
L56:				;line-23
	MOV AX, [BP-2]		;variable 'k'
	JMP L74
L74:				;line-24
	ADD SP, 2
	POP BP
	RET 2
F102979911611111410597108 ENDP		;End of definiton of factorial()

;Definition of power()
F112111119101114 PROC
	PUSH BP
	MOV BP, SP
	MOV AX, 0
	MOV DX, AX
	MOV AX, [BP+4]		;variable 'b'
	CMP AX, DX
	JE L77
	JMP L76
L77:				;line-28
	MOV AX, 1
	JMP L82
L82:				;line-28
	POP BP
	RET 4
L76:				;line-28
	PUSH CX
	MOV AX, [BP+6]		;variable 'a'
	MOV CX, AX
	MOV AX, [BP+6]		;variable 'a'
	PUSH AX
	PUSH BX
	MOV AX, [BP+4]		;variable 'b'
	MOV BX, AX
	MOV AX, 1
	SUB AX, BX
	NEG AX
	POP BX
	PUSH AX
	CALL F112111119101114		;Calling power()
	MUL CX
	POP CX
	JMP L92
L92:				;line-29
	POP BP
	RET 4
F112111119101114 ENDP		;End of definiton of power()

;Definition of merge()
F109101114103101 PROC
	PUSH BP
	MOV BP, SP
	SUB SP, 38
L100:				;line-33
L99:				;line-34
	MOV AX, [BP+8]		;variable 'begin'
	MOV [BP-2], AX		;variable 'i'
L98:				;line-35
	PUSH BX
	MOV AX, [BP+6]		;variable 'mid'
	MOV BX, AX
	MOV AX, 1
	ADD AX, BX
	POP BX
	MOV [BP-4], AX		;variable 'j'
L97:				;line-36
L96:				;line-37
	MOV AX, 0
	MOV [BP-38], AX		;variable 'counter'
L95:				;line-38
	MOV AX, 0
	MOV [BP-38], AX		;variable 'counter'
L110:				;line-40
	PUSH BX
	PUSH CX
	PUSH DX
	PUSH BX
	PUSH BX
	MOV AX, [BP+4]		;variable 'end'
	MOV BX, AX
	MOV AX, [BP+8]		;variable 'begin'
	SUB AX, BX
	NEG AX
	POP BX
	MOV BX, AX
	MOV AX, 1
	ADD AX, BX
	POP BX
	POP DX
	POP CX
	POP BX
	MOV DX, AX
	MOV AX, [BP-38]		;variable 'counter'
	CMP AX, DX
	JL L111
	JMP L94
L112:				;line-40
	MOV AX, [BP-38]
	PUSH AX
	INC AX
	MOV [BP-38], AX
	POP AX
		;variable 'counter'
	JMP L110
L111:				;line-40
	MOV AX, [BP+6]		;variable 'mid'
	MOV DX, AX
	MOV AX, [BP-2]		;variable 'i'
	CMP AX, DX
	JG L122
	JMP L123
L122:				;line-41
	LEA SI, V9711411497121		;variable 'array'

	PUSH AX
	PUSH BX
	PUSH CX
	PUSH DX
	MOV AX, [BP-4]
	PUSH AX
	INC AX
	MOV [BP-4], AX
	POP AX
		;variable 'j'
	ADD SI, AX
	ADD SI, AX
	POP DX
	POP CX
	POP BX
	POP AX
	MOV AX, [SI]		;variable 'array'
	LEA SI, BP
	SUB SI, 6
	PUSH AX
	PUSH BX
	PUSH CX
	PUSH DX
	MOV AX, [BP-38]		;variable 'counter'
	SUB SI, AX
	SUB SI, AX
	POP DX
	POP CX
	POP BX
	POP AX
	MOV [SI], AX		;variable 'temp'
	JMP L112
L123:				;line-41
	MOV AX, [BP+4]		;variable 'end'
	MOV DX, AX
	MOV AX, [BP-4]		;variable 'j'
	CMP AX, DX
	JG L134
	JMP L135
L134:				;line-42
	LEA SI, V9711411497121		;variable 'array'

	PUSH AX
	PUSH BX
	PUSH CX
	PUSH DX
	MOV AX, [BP-2]
	PUSH AX
	INC AX
	MOV [BP-2], AX
	POP AX
		;variable 'i'
	ADD SI, AX
	ADD SI, AX
	POP DX
	POP CX
	POP BX
	POP AX
	MOV AX, [SI]		;variable 'array'
	LEA SI, BP
	SUB SI, 6
	PUSH AX
	PUSH BX
	PUSH CX
	PUSH DX
	MOV AX, [BP-38]		;variable 'counter'
	SUB SI, AX
	SUB SI, AX
	POP DX
	POP CX
	POP BX
	POP AX
	MOV [SI], AX		;variable 'temp'
	JMP L112
L135:				;line-42
	LEA SI, V9711411497121		;variable 'array'

	PUSH AX
	PUSH BX
	PUSH CX
	PUSH DX
	MOV AX, [BP-4]		;variable 'j'
	ADD SI, AX
	ADD SI, AX
	POP DX
	POP CX
	POP BX
	POP AX
	MOV AX, [SI]		;variable 'array'
	MOV DX, AX
	LEA SI, V9711411497121		;variable 'array'

	PUSH AX
	PUSH BX
	PUSH CX
	PUSH DX
	MOV AX, [BP-2]		;variable 'i'
	ADD SI, AX
	ADD SI, AX
	POP DX
	POP CX
	POP BX
	POP AX
	MOV AX, [SI]		;variable 'array'
	CMP AX, DX
	JLE L146
	JMP L147
L146:				;line-43
	LEA SI, V9711411497121		;variable 'array'

	PUSH AX
	PUSH BX
	PUSH CX
	PUSH DX
	MOV AX, [BP-2]
	PUSH AX
	INC AX
	MOV [BP-2], AX
	POP AX
		;variable 'i'
	ADD SI, AX
	ADD SI, AX
	POP DX
	POP CX
	POP BX
	POP AX
	MOV AX, [SI]		;variable 'array'
	LEA SI, BP
	SUB SI, 6
	PUSH AX
	PUSH BX
	PUSH CX
	PUSH DX
	MOV AX, [BP-38]		;variable 'counter'
	SUB SI, AX
	SUB SI, AX
	POP DX
	POP CX
	POP BX
	POP AX
	MOV [SI], AX		;variable 'temp'
	JMP L112
L147:				;line-43
	LEA SI, V9711411497121		;variable 'array'

	PUSH AX
	PUSH BX
	PUSH CX
	PUSH DX
	MOV AX, [BP-4]
	PUSH AX
	INC AX
	MOV [BP-4], AX
	POP AX
		;variable 'j'
	ADD SI, AX
	ADD SI, AX
	POP DX
	POP CX
	POP BX
	POP AX
	MOV AX, [SI]		;variable 'array'
	LEA SI, BP
	SUB SI, 6
	PUSH AX
	PUSH BX
	PUSH CX
	PUSH DX
	MOV AX, [BP-38]		;variable 'counter'
	SUB SI, AX
	SUB SI, AX
	POP DX
	POP CX
	POP BX
	POP AX
	MOV [SI], AX		;variable 'temp'
	JMP L112
L94:				;line-44
	MOV AX, 0
	MOV [BP-38], AX		;variable 'counter'
L173:				;line-47
	PUSH BX
	PUSH CX
	PUSH DX
	PUSH BX
	PUSH BX
	MOV AX, [BP+4]		;variable 'end'
	MOV BX, AX
	MOV AX, [BP+8]		;variable 'begin'
	SUB AX, BX
	NEG AX
	POP BX
	MOV BX, AX
	MOV AX, 1
	ADD AX, BX
	POP BX
	POP DX
	POP CX
	POP BX
	MOV DX, AX
	MOV AX, [BP-38]		;variable 'counter'
	CMP AX, DX
	JL L174
	JMP L93
L175:				;line-47
	MOV AX, [BP-38]
	PUSH AX
	INC AX
	MOV [BP-38], AX
	POP AX
		;variable 'counter'
	JMP L173
L174:				;line-47
	LEA SI, BP
	SUB SI, 6
	PUSH AX
	PUSH BX
	PUSH CX
	PUSH DX
	MOV AX, [BP-38]		;variable 'counter'
	SUB SI, AX
	SUB SI, AX
	POP DX
	POP CX
	POP BX
	POP AX
	MOV AX, [SI]		;variable 'temp'
	LEA SI, V9711411497121		;variable 'array'

	PUSH AX
	PUSH BX
	PUSH CX
	PUSH DX
	PUSH BX
	MOV AX, [BP+8]		;variable 'begin'
	MOV BX, AX
	MOV AX, [BP-38]		;variable 'counter'
	ADD AX, BX
	POP BX
	ADD SI, AX
	ADD SI, AX
	POP DX
	POP CX
	POP BX
	POP AX
	MOV [SI], AX		;variable 'array'
	JMP L175
L93:				;line-48
	ADD SP, 38
	POP BP
	RET 6
F109101114103101 ENDP		;End of definiton of merge()

;Definition of mergeSort()
F10910111410310183111114116 PROC
	PUSH BP
	MOV BP, SP
	SUB SP, 2
	MOV AX, [BP+4]		;variable 'end'
	MOV DX, AX
	MOV AX, [BP+6]		;variable 'begin'
	CMP AX, DX
	JGE L201
	JMP L200
L201:				;line-53
	MOV AX, 0
	JMP L206
L206:				;line-54
	ADD SP, 2
	POP BP
	RET 4
L200:				;line-54
L199:				;line-56
	PUSH BX
	MOV AX, [BP+6]		;variable 'begin'
	MOV BX, AX
	PUSH CX
	PUSH BX
	PUSH CX
	PUSH DX
	PUSH BX
	MOV AX, [BP+4]		;variable 'end'
	MOV BX, AX
	MOV AX, [BP+6]		;variable 'begin'
	SUB AX, BX
	NEG AX
	POP BX
	POP DX
	POP CX
	POP BX
	MOV CX, AX
	MOV AX, 2
	PUSH DX
	CWD
	XCHG AX, CX
	DIV CX
	POP DX
	POP CX
	ADD AX, BX
	POP BX
	MOV [BP-2], AX		;variable 'mid'
L198:				;line-57
	MOV AX, [BP+6]		;variable 'begin'
	PUSH AX
	MOV AX, [BP-2]		;variable 'mid'
	PUSH AX
	CALL F10910111410310183111114116		;Calling mergeSort()
L197:				;line-58
	PUSH BX
	MOV AX, [BP-2]		;variable 'mid'
	MOV BX, AX
	MOV AX, 1
	ADD AX, BX
	POP BX
	PUSH AX
	MOV AX, [BP+4]		;variable 'end'
	PUSH AX
	CALL F10910111410310183111114116		;Calling mergeSort()
L196:				;line-59
	MOV AX, [BP+6]		;variable 'begin'
	PUSH AX
	MOV AX, [BP-2]		;variable 'mid'
	PUSH AX
	MOV AX, [BP+4]		;variable 'end'
	PUSH AX
	CALL F109101114103101		;Calling merge()
L195:				;line-60
	MOV AX, 0
	JMP L246
L246:				;line-61
	ADD SP, 2
	POP BP
	RET 4
F10910111410310183111114116 ENDP		;End of definiton of mergeSort()

;Definition of MERGE()
F7769827169 PROC
	PUSH BP
	MOV BP, SP
	MOV AX, 15000
	NEG AX
	MOV V11011710998101114, AX		;variable 'number'
L249:				;line-65
	MOV AX, V11011710998101114		;variable 'number'
	CALL PRINT_OUTPUT
	CALL NEW_LINE
L248:				;line-66
	MOV AX, 1
	JMP L257
L257:				;line-67
	POP BP
	RET 
F7769827169 ENDP		;End of definiton of MERGE()

;Definition of loop_test()
F10811111111295116101115116 PROC
	PUSH BP
	MOV BP, SP
	SUB SP, 2
L260:				;line-71
	MOV AX, 0
	MOV [BP-2], AX		;variable 'i'
L261:				;line-72
	MOV AX, 100
	MOV DX, AX
	MOV AX, [BP-2]		;variable 'i'
	CMP AX, DX
	JL L262
	JMP L259
L263:				;line-72
	MOV AX, [BP-2]
	PUSH AX
	INC AX
	MOV [BP-2], AX
	POP AX
		;variable 'i'
	JMP L261
L262:				;line-72
L273:				;line-73
	MOV AX, 0
	LEA SI, BP
	SUB SI, 4
	PUSH AX
	PUSH BX
	PUSH CX
	PUSH DX
	MOV AX, 97
	SUB SI, AX
	SUB SI, AX
	POP DX
	POP CX
	POP BX
	POP AX
	MOV [SI], AX		;variable 'k'
L272:				;line-74
	MOV AX, 0
	LEA SI, BP
	SUB SI, 4
	PUSH AX
	PUSH BX
	PUSH CX
	PUSH DX
	MOV AX, 98
	SUB SI, AX
	SUB SI, AX
	POP DX
	POP CX
	POP BX
	POP AX
	MOV [SI], AX		;variable 'k'
L271:				;line-75
	PUSH BX
	PUSH BX
	LEA SI, BP
	SUB SI, 4
	PUSH AX
	PUSH BX
	PUSH CX
	PUSH DX
	MOV AX, 98
	SUB SI, AX
	SUB SI, AX
	POP DX
	POP CX
	POP BX
	POP AX
	MOV AX, [SI]		;variable 'k'
	MOV BX, AX
	LEA SI, BP
	SUB SI, 4
	PUSH AX
	PUSH BX
	PUSH CX
	PUSH DX
	MOV AX, 97
	SUB SI, AX
	SUB SI, AX
	POP DX
	POP CX
	POP BX
	POP AX
	MOV AX, [SI]		;variable 'k'
	ADD AX, BX
	POP BX
	MOV BX, AX
	MOV AX, 111
	ADD AX, BX
	POP BX
	LEA SI, BP
	SUB SI, 4
	PUSH AX
	PUSH BX
	PUSH CX
	PUSH DX
	MOV AX, 99
	SUB SI, AX
	SUB SI, AX
	POP DX
	POP CX
	POP BX
	POP AX
	MOV [SI], AX		;variable 'k'
L270:				;line-76
	MOV AX, 97
	MOV DX, AX
	MOV AX, [BP-2]		;variable 'i'
	CMP AX, DX
	JE L298
	JMP L263
L298:				;line-77
L302:				;line-78
	LEA SI, BP
	SUB SI, 4
	PUSH AX
	PUSH BX
	PUSH CX
	PUSH DX
	MOV AX, 99
	SUB SI, AX
	SUB SI, AX
	POP DX
	POP CX
	POP BX
	POP AX
	MOV AX, [SI]		;variable 'k'
	MOV [BP-204], AX		;variable 'temp'
L301:				;line-79
	MOV AX, [BP-204]		;variable 'temp'
	CALL PRINT_OUTPUT
	CALL NEW_LINE
L300:				;line-80
	MOV AX, 0
	JMP L313
L313:				;line-81
	ADD SP, 2
	POP BP
	RET 
	JMP L263
L259:				;line-81
	MOV AX, [BP-2]		;variable 'i'
	CALL PRINT_OUTPUT
	CALL NEW_LINE
F10811111111295116101115116 ENDP		;End of definiton of loop_test()

;Definition of main()
MAIN PROC
	MOV AX, @DATA
	MOV DS, AX
	PUSH BP
	MOV BP, SP
	SUB SP, 6
L335:				;line-89
	MOV AX, 2
	MOV [BP-4], AX		;variable 'a'
L334:				;line-90
	MOV AX, 5
	MOV [BP-6], AX		;variable 'b'
L333:				;line-91
	MOV AX, [BP-4]		;variable 'a'
	PUSH AX
	MOV AX, [BP-6]		;variable 'b'
	PUSH AX
	CALL F112111119101114		;Calling power()
	MOV V11011710998101114, AX		;variable 'number'
L332:				;line-92
	MOV AX, V11011710998101114		;variable 'number'
	CALL PRINT_OUTPUT
	CALL NEW_LINE
L331:				;line-93
	MOV AX, 7
	PUSH AX
	CALL F102979911611111410597108		;Calling factorial()
	MOV V11011710998101114, AX		;variable 'number'
L330:				;line-94
	MOV AX, V11011710998101114		;variable 'number'
	CALL PRINT_OUTPUT
	CALL NEW_LINE
L329:				;line-95
	CALL F10811111111295116101115116		;Calling loop_test()
L328:				;line-96
	MOV AX, 15
	MOV [BP-2], AX		;variable 'i'
L362:				;line-98
	MOV AX, 0
	MOV DX, AX
	MOV AX, [BP-2]		;variable 'i'
	CMP AX, DX
	JGE L363
	JMP L327
L364:				;line-98
	MOV AX, [BP-2]
	PUSH AX
	DEC AX
	MOV [BP-2], AX
	POP AX
		;variable 'i'
	JMP L362
L363:				;line-98
	PUSH BX
	MOV AX, 17000
	NEG AX
	MOV BX, AX
	PUSH CX
	MOV AX, 1000
	MOV CX, AX
	MOV AX, [BP-2]		;variable 'i'
	MUL CX
	POP CX
	SUB AX, BX
	NEG AX
	POP BX
	LEA SI, V9711411497121		;variable 'array'

	PUSH AX
	PUSH BX
	PUSH CX
	PUSH DX
	MOV AX, [BP-2]		;variable 'i'
	ADD SI, AX
	ADD SI, AX
	POP DX
	POP CX
	POP BX
	POP AX
	MOV [SI], AX		;variable 'array'
	JMP L364
L327:				;line-99
	MOV AX, 16
	MOV [BP-2], AX		;variable 'i'
L326:				;line-100
L380:				;line-105
	MOV AX, [BP-2]
	PUSH AX
	DEC AX
	MOV [BP-2], AX
	POP AX
		;variable 'i'
	CMP AX, 0
	JNE L381
	JMP L325
L381:				;line-101
L384:				;line-102
	LEA SI, V9711411497121		;variable 'array'

	PUSH AX
	PUSH BX
	PUSH CX
	PUSH DX
	PUSH BX
	MOV AX, 15
	MOV BX, AX
	MOV AX, [BP-2]		;variable 'i'
	SUB AX, BX
	NEG AX
	POP BX
	ADD SI, AX
	ADD SI, AX
	POP DX
	POP CX
	POP BX
	POP AX
	MOV AX, [SI]		;variable 'array'
	MOV [BP-8], AX		;variable 'temp'
L383:				;line-103
	MOV AX, [BP-8]		;variable 'temp'
	CALL PRINT_OUTPUT
	CALL NEW_LINE
	JMP L380
L325:				;line-104
	MOV AX, [BP-2]		;variable 'i'
	CALL PRINT_OUTPUT
	CALL NEW_LINE
L324:				;line-107
	MOV AX, 0
	MOV [BP-4], AX		;variable 'a'
L323:				;line-108
	MOV AX, 15
	MOV [BP-6], AX		;variable 'b'
L322:				;line-109
	MOV AX, [BP-4]		;variable 'a'
	PUSH AX
	MOV AX, [BP-6]		;variable 'b'
	PUSH AX
	CALL F10910111410310183111114116		;Calling mergeSort()
L321:				;line-110
	MOV AX, 0
	MOV [BP-2], AX		;variable 'i'
L408:				;line-112
	MOV AX, 16
	MOV DX, AX
	MOV AX, [BP-2]		;variable 'i'
	CMP AX, DX
	JL L409
	JMP L320
L410:				;line-112
	MOV AX, [BP-2]
	PUSH AX
	INC AX
	MOV [BP-2], AX
	POP AX
		;variable 'i'
	JMP L408
L409:				;line-112
	MOV AX, 0
	MOV DX, AX
	MOV AX, [BP-2]		;variable 'i'
	CMP AX, DX
	JGE L417
	JMP L419
L419:				;line-113
	CALL F7769827169		;Calling MERGE()
	CMP AX, 0
	JNE L417
	JMP L410
L417:				;line-113
	MOV AX, 1
	MOV V87798268, AX		;variable 'WORD'
L424:				;line-114
	MOV AX, 3
	MOV V87798268, AX		;variable 'WORD'
L423:				;line-115
	LEA SI, V9711411497121		;variable 'array'

	PUSH AX
	PUSH BX
	PUSH CX
	PUSH DX
	MOV AX, [BP-2]		;variable 'i'
	ADD SI, AX
	ADD SI, AX
	POP DX
	POP CX
	POP BX
	POP AX
	MOV AX, [SI]		;variable 'array'
	MOV V87798268, AX		;variable 'WORD'
L422:				;line-116
	MOV AX, V87798268		;variable 'WORD'
	CALL PRINT_OUTPUT
	CALL NEW_LINE
	JMP L410
L320:				;line-117
	MOV AX, 0
	MOV [BP-2], AX		;variable 'i'
L438:				;line-120
	MOV AX, 16
	MOV DX, AX
	MOV AX, [BP-2]		;variable 'i'
	CMP AX, DX
	JL L439
	JMP L319
L440:				;line-120
	MOV AX, [BP-2]
	PUSH AX
	INC AX
	MOV [BP-2], AX
	POP AX
		;variable 'i'
	JMP L438
L439:				;line-120
	MOV AX, 0
	MOV DX, AX
	MOV AX, [BP-2]		;variable 'i'
	CMP AX, DX
	JL L449
	JMP L440
L449:				;line-121
	CALL F7769827169		;Calling MERGE()
	CMP AX, 0
	JNE L447
	JMP L440
L447:				;line-121
	LEA SI, V9711411497121		;variable 'array'

	PUSH AX
	PUSH BX
	PUSH CX
	PUSH DX
	MOV AX, [BP-2]		;variable 'i'
	ADD SI, AX
	ADD SI, AX
	POP DX
	POP CX
	POP BX
	POP AX
	MOV AX, [SI]		;variable 'array'
	MOV V95106, AX		;variable '_j'
L452:				;line-122
	MOV AX, V95106		;variable '_j'
	CALL PRINT_OUTPUT
	CALL NEW_LINE
	JMP L440
L319:				;line-123
	MOV AX, 200
	MOV V119111114100, AX		;variable 'word'
L318:				;line-126
	MOV AX, V119111114100		;variable 'word'
	CALL PRINT_OUTPUT
	CALL NEW_LINE
L317:				;line-127
	MOV AX, 23
	PUSH AX
	CALL F10210598111110979999105		;Calling fibonacci()
L316:				;line-128
	MOV AX, 0
	MOV [BP-2], AX		;variable 'i'
L470:				;line-129
	MOV AX, 24
	MOV DX, AX
	MOV AX, [BP-2]		;variable 'i'
	CMP AX, DX
	JL L471
	JMP L315
L472:				;line-129
	MOV AX, [BP-2]
	PUSH AX
	INC AX
	MOV [BP-2], AX
	POP AX
		;variable 'i'
	JMP L470
L471:				;line-129
L480:				;line-130
	LEA SI, V1021059895109101109		;variable 'fib_mem'

	PUSH AX
	PUSH BX
	PUSH CX
	PUSH DX
	MOV AX, [BP-2]		;variable 'i'
	ADD SI, AX
	ADD SI, AX
	POP DX
	POP CX
	POP BX
	POP AX
	MOV AX, [SI]		;variable 'fib_mem'
	MOV [BP-10], AX		;variable 'temp'
L479:				;line-131
	MOV AX, [BP-10]		;variable 'temp'
	CALL PRINT_OUTPUT
	CALL NEW_LINE
	JMP L472
L315:				;line-132
	ADD SP, 6
	POP BP
	RET 
MAIN ENDP		;End of definiton of main()

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
