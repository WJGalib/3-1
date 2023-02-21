.MODEL SMALL
.STACK 1000H
.DATA
	number DB "00000$"
	word_0 DW 0
	WORD_1 DW 0
	number_2 DW 0
	_j_3 DW 0
	fib_mem_4 DW 24 DUP (0000H)
	array_5 DW 16 DUP (0000H)
.CODE

fibonacci_6 PROC
	PUSH BP
	MOV BP , SP
	SUB SP , 0

	; Compund statement starting at line 9

	; if statement starting at line 10
	PUSH BP[4]
	POP SI
	SHL SI , 1
	PUSH fib_mem_4[SI]
	MOV AX , 0
	PUSH AX
	POP CX
	POP AX
	CMP AX , CX
	JNE L1
	MOV AX , 0
	JMP L2
L1:
	MOV AX , 1
L2:
	PUSH AX
	POP AX
	CMP AX , 0
	JNE L3
	JMP L4
L3:
	; Return statement at line 10
	PUSH BP[4]
	POP SI
	SHL SI , 1
	PUSH fib_mem_4[SI]
	POP AX
	JMP L0
L4:
	; if statement ending at line 10

	; if statement starting at line 11
	PUSH BP[4]
	MOV AX , 0
	PUSH AX
	POP CX
	POP AX
	CMP AX , CX
	JE L7
	MOV AX , 0
	JMP L8
L7:
	MOV AX , 1
L8:
	PUSH AX
	POP AX
	CMP AX , 0
	JNE L5
	PUSH BP[4]
	MOV AX , 1
	PUSH AX
	POP CX
	POP AX
	CMP AX , CX
	JE L9
	MOV AX , 0
	JMP L10
L9:
	MOV AX , 1
L10:
	PUSH AX
	POP AX
	CMP AX , 0
	JNE L5
	MOV AX , 0
	JMP L6
L5:
	MOV AX , 1
L6:
	PUSH AX
	POP AX
	CMP AX , 0
	JNE L11
	JMP L12
L11:

	; Compund statement starting at line 11

	; Expression statement starting at line 12
	PUSH BP[4]
	POP BX
	PUSH BP[4]
	POP SI
	SHL SI , 1
	MOV fib_mem_4[SI] , BX
	PUSH BX
	POP AX
	; Expression statement ending at line 12
	; Return statement at line 13
	PUSH BP[4]
	POP SI
	SHL SI , 1
	PUSH fib_mem_4[SI]
	POP AX
	JMP L0
	; Compund statement ending at line 14
L12:
	; if statement ending at line 14

	; Expression statement starting at line 15
	PUSH BP[4]
	MOV AX , 1
	PUSH AX
	POP CX
	POP AX
	SUB AX , CX
	PUSH AX
	CALL fibonacci_6 ; At line 15
	PUSH AX
	PUSH BP[4]
	MOV AX , 2
	PUSH AX
	POP CX
	POP AX
	SUB AX , CX
	PUSH AX
	CALL fibonacci_6 ; At line 15
	PUSH AX
	POP CX
	POP AX
	ADD AX , CX
	PUSH AX
	POP BX
	PUSH BP[4]
	POP SI
	SHL SI , 1
	MOV fib_mem_4[SI] , BX
	PUSH BX
	POP AX
	; Expression statement ending at line 15
	; Return statement at line 16
	PUSH BP[4]
	POP SI
	SHL SI , 1
	PUSH fib_mem_4[SI]
	POP AX
	JMP L0
	; Compund statement ending at line 17
L0:
	ADD SP , 0
	POP BP
	RET 2

fibonacci_6 ENDP

factorial_7 PROC
	PUSH BP
	MOV BP , SP
	SUB SP , 2

	; Compund statement starting at line 19

	; if statement starting at line 20
	PUSH BP[4]
	MOV AX , 1
	PUSH AX
	POP CX
	POP AX
	CMP AX , CX
	JE L14
	MOV AX , 0
	JMP L15
L14:
	MOV AX , 1
L15:
	PUSH AX
	POP AX
	CMP AX , 0
	JNE L16
	JMP L17
L16:
	; Return statement at line 20
	PUSH BP[4]
	POP AX
	JMP L13
L17:
	; if statement ending at line 20

	; Expression statement starting at line 22
	PUSH BP[4]
	PUSH BP[4]
	MOV AX , 1
	PUSH AX
	POP CX
	POP AX
	SUB AX , CX
	PUSH AX
	CALL factorial_7 ; At line 22
	PUSH AX
	POP CX
	POP AX
	IMUL CX
	PUSH AX
	POP AX
	MOV BP[-2] , AX
	PUSH AX
	POP AX
	; Expression statement ending at line 22
	; Return statement at line 23
	PUSH BP[-2]
	POP AX
	JMP L13
	; Compund statement ending at line 24
L13:
	ADD SP , 2
	POP BP
	RET 2

factorial_7 ENDP

power_8 PROC
	PUSH BP
	MOV BP , SP
	SUB SP , 0

	; Compund statement starting at line 26

	; if statement starting at line 27
	PUSH BP[6]
	MOV AX , 0
	PUSH AX
	POP CX
	POP AX
	CMP AX , CX
	JE L19
	MOV AX , 0
	JMP L20
L19:
	MOV AX , 1
L20:
	PUSH AX
	POP AX
	CMP AX , 0
	JNE L21
	JMP L22
L21:
	; Return statement at line 27
	MOV AX , 1
	PUSH AX
	POP AX
	JMP L18
L22:
	; if statement ending at line 27
	; Return statement at line 28
	PUSH BP[4]
	PUSH BP[6]
	MOV AX , 1
	PUSH AX
	POP CX
	POP AX
	SUB AX , CX
	PUSH AX
	PUSH BP[4]
	CALL power_8 ; At line 28
	PUSH AX
	POP CX
	POP AX
	IMUL CX
	PUSH AX
	POP AX
	JMP L18
	; Compund statement ending at line 29
L18:
	ADD SP , 0
	POP BP
	RET 4

power_8 ENDP

merge_9 PROC
	PUSH BP
	MOV BP , SP
	SUB SP , 38

	; Compund statement starting at line 31

	; Expression statement starting at line 34
	PUSH BP[4]
	POP AX
	MOV BP[-2] , AX
	PUSH AX
	POP AX
	; Expression statement ending at line 34

	; Expression statement starting at line 35
	PUSH BP[6]
	MOV AX , 1
	PUSH AX
	POP CX
	POP AX
	ADD AX , CX
	PUSH AX
	POP AX
	MOV BP[-4] , AX
	PUSH AX
	POP AX
	; Expression statement ending at line 35

	; Expression statement starting at line 37
	MOV AX , 0
	PUSH AX
	POP AX
	MOV BP[-38] , AX
	PUSH AX
	POP AX
	; Expression statement ending at line 37

	; for loop starting at line 39
	; Expression statement starting at line 39
	MOV AX , 0
	PUSH AX
	POP AX
	MOV BP[-38] , AX
	PUSH AX
	POP AX
	; Expression statement ending at line 39
L24:

	; Expression statement starting at line 39
	PUSH BP[-38]
	PUSH BP[8]
	PUSH BP[4]
	POP CX
	POP AX
	SUB AX , CX
	PUSH AX
	MOV AX , 1
	PUSH AX
	POP CX
	POP AX
	ADD AX , CX
	PUSH AX
	POP CX
	POP AX
	CMP AX , CX
	JL L27
	MOV AX , 0
	JMP L28
L27:
	MOV AX , 1
L28:
	PUSH AX
	POP AX
	; Expression statement ending at line 39
	CMP AX , 0
	JNE L25
	JMP L26
L25:

	; Compund statement starting at line 39

	; if-else statement starting at line 40
	PUSH BP[-2]
	PUSH BP[6]
	POP CX
	POP AX
	CMP AX , CX
	JG L29
	MOV AX , 0
	JMP L30
L29:
	MOV AX , 1
L30:
	PUSH AX
	POP AX
	CMP AX , 0
	JNE L31
	JMP L32
L31:

	; Expression statement starting at line 40
	PUSH BP[-4]
	ADD WORD PTR BP[-4] , 1
	POP SI
	SHL SI , 1
	PUSH array_5[SI]
	POP BX
	PUSH BP[-38]
	POP SI
	SHL SI , 1
	ADD SI , -36
	MOV BP[SI] , BX
	PUSH BX
	POP AX
	; Expression statement ending at line 40
	JMP L33
L32:

	; if-else statement starting at line 41
	PUSH BP[-4]
	PUSH BP[8]
	POP CX
	POP AX
	CMP AX , CX
	JG L34
	MOV AX , 0
	JMP L35
L34:
	MOV AX , 1
L35:
	PUSH AX
	POP AX
	CMP AX , 0
	JNE L36
	JMP L37
L36:

	; Expression statement starting at line 41
	PUSH BP[-2]
	ADD WORD PTR BP[-2] , 1
	POP SI
	SHL SI , 1
	PUSH array_5[SI]
	POP BX
	PUSH BP[-38]
	POP SI
	SHL SI , 1
	ADD SI , -36
	MOV BP[SI] , BX
	PUSH BX
	POP AX
	; Expression statement ending at line 41
	JMP L38
L37:

	; if-else statement starting at line 42
	PUSH BP[-2]
	POP SI
	SHL SI , 1
	PUSH array_5[SI]
	PUSH BP[-4]
	POP SI
	SHL SI , 1
	PUSH array_5[SI]
	POP CX
	POP AX
	CMP AX , CX
	JLE L39
	MOV AX , 0
	JMP L40
L39:
	MOV AX , 1
L40:
	PUSH AX
	POP AX
	CMP AX , 0
	JNE L41
	JMP L42
L41:

	; Expression statement starting at line 42
	PUSH BP[-2]
	ADD WORD PTR BP[-2] , 1
	POP SI
	SHL SI , 1
	PUSH array_5[SI]
	POP BX
	PUSH BP[-38]
	POP SI
	SHL SI , 1
	ADD SI , -36
	MOV BP[SI] , BX
	PUSH BX
	POP AX
	; Expression statement ending at line 42
	JMP L43
L42:

	; Expression statement starting at line 43
	PUSH BP[-4]
	ADD WORD PTR BP[-4] , 1
	POP SI
	SHL SI , 1
	PUSH array_5[SI]
	POP BX
	PUSH BP[-38]
	POP SI
	SHL SI , 1
	ADD SI , -36
	MOV BP[SI] , BX
	PUSH BX
	POP AX
	; Expression statement ending at line 43
L43:
	; if-else statement ending at line 43
L38:
	; if-else statement ending at line 43
L33:
	; if-else statement ending at line 43
	; Compund statement ending at line 44
	PUSH BP[-38]
	ADD WORD PTR BP[-38] , 1
	POP AX
	JMP L24
L26:	; for loop ending at line 44

	; for loop starting at line 46
	; Expression statement starting at line 46
	MOV AX , 0
	PUSH AX
	POP AX
	MOV BP[-38] , AX
	PUSH AX
	POP AX
	; Expression statement ending at line 46
L44:

	; Expression statement starting at line 46
	PUSH BP[-38]
	PUSH BP[8]
	PUSH BP[4]
	POP CX
	POP AX
	SUB AX , CX
	PUSH AX
	MOV AX , 1
	PUSH AX
	POP CX
	POP AX
	ADD AX , CX
	PUSH AX
	POP CX
	POP AX
	CMP AX , CX
	JL L47
	MOV AX , 0
	JMP L48
L47:
	MOV AX , 1
L48:
	PUSH AX
	POP AX
	; Expression statement ending at line 46
	CMP AX , 0
	JNE L45
	JMP L46
L45:

	; Compund statement starting at line 46

	; Expression statement starting at line 47
	PUSH BP[-38]
	POP SI
	SHL SI , 1
	ADD SI , -36
	PUSH BP[SI]
	POP BX
	PUSH BP[4]
	PUSH BP[-38]
	POP CX
	POP AX
	ADD AX , CX
	PUSH AX
	POP SI
	SHL SI , 1
	MOV array_5[SI] , BX
	PUSH BX
	POP AX
	; Expression statement ending at line 47
	; Compund statement ending at line 48
	PUSH BP[-38]
	ADD WORD PTR BP[-38] , 1
	POP AX
	JMP L44
L46:	; for loop ending at line 48
	; Compund statement ending at line 49
L23:
	ADD SP , 38
	POP BP
	RET 6

merge_9 ENDP

mergeSort_10 PROC
	PUSH BP
	MOV BP , SP
	SUB SP , 2

	; Compund statement starting at line 51

	; if statement starting at line 52
	PUSH BP[4]
	PUSH BP[6]
	POP CX
	POP AX
	CMP AX , CX
	JGE L50
	MOV AX , 0
	JMP L51
L50:
	MOV AX , 1
L51:
	PUSH AX
	POP AX
	CMP AX , 0
	JNE L52
	JMP L53
L52:
	; Return statement at line 53
	MOV AX , 0
	PUSH AX
	POP AX
	JMP L49
L53:
	; if statement ending at line 53

	; Expression statement starting at line 56
	PUSH BP[4]
	PUSH BP[6]
	PUSH BP[4]
	POP CX
	POP AX
	SUB AX , CX
	PUSH AX
	MOV AX , 2
	PUSH AX
	POP CX
	POP AX
	CWD
	IDIV CX
	PUSH AX
	POP CX
	POP AX
	ADD AX , CX
	PUSH AX
	POP AX
	MOV BP[-2] , AX
	PUSH AX
	POP AX
	; Expression statement ending at line 56

	; Expression statement starting at line 57
	PUSH BP[-2]
	PUSH BP[4]
	CALL mergeSort_10 ; At line 57
	PUSH AX
	POP AX
	; Expression statement ending at line 57

	; Expression statement starting at line 58
	PUSH BP[6]
	PUSH BP[-2]
	MOV AX , 1
	PUSH AX
	POP CX
	POP AX
	ADD AX , CX
	PUSH AX
	CALL mergeSort_10 ; At line 58
	PUSH AX
	POP AX
	; Expression statement ending at line 58

	; Expression statement starting at line 59
	PUSH BP[6]
	PUSH BP[-2]
	PUSH BP[4]
	CALL merge_9 ; At line 59
	PUSH AX
	POP AX
	; Expression statement ending at line 59
	; Return statement at line 60
	MOV AX , 0
	PUSH AX
	POP AX
	JMP L49
	; Compund statement ending at line 61
L49:
	ADD SP , 2
	POP BP
	RET 4

mergeSort_10 ENDP

MERGE_11 PROC
	PUSH BP
	MOV BP , SP
	SUB SP , 0

	; Compund statement starting at line 63

	; Expression statement starting at line 64
	MOV AX , 15000
	PUSH AX
	POP AX
	NEG AX
	PUSH AX
	POP AX
	MOV number_2 , AX
	PUSH AX
	POP AX
	; Expression statement ending at line 64
	PUSH number_2
	POP AX
	CALL println ; At line 65
	; Return statement at line 66
	MOV AX , 1
	PUSH AX
	POP AX
	JMP L54
	; Compund statement ending at line 67
L54:
	ADD SP , 0
	POP BP
	RET 0

MERGE_11 ENDP

loop_test_12 PROC
	PUSH BP
	MOV BP , SP
	SUB SP , 204

	; Compund statement starting at line 69

	; for loop starting at line 71
	; Expression statement starting at line 71
	MOV AX , 0
	PUSH AX
	POP AX
	MOV BP[-2] , AX
	PUSH AX
	POP AX
	; Expression statement ending at line 71
L56:

	; Expression statement starting at line 71
	PUSH BP[-2]
	MOV AX , 100
	PUSH AX
	POP CX
	POP AX
	CMP AX , CX
	JL L59
	MOV AX , 0
	JMP L60
L59:
	MOV AX , 1
L60:
	PUSH AX
	POP AX
	; Expression statement ending at line 71
	CMP AX , 0
	JNE L57
	JMP L58
L57:

	; Compund statement starting at line 71

	; Expression statement starting at line 73
	MOV AX , 0
	PUSH AX
	POP BX
	MOV AX , 97
	PUSH AX
	POP SI
	SHL SI , 1
	ADD SI , -202
	MOV BP[SI] , BX
	PUSH BX
	POP AX
	; Expression statement ending at line 73

	; Expression statement starting at line 74
	MOV AX , 0
	PUSH AX
	POP BX
	MOV AX , 98
	PUSH AX
	POP SI
	SHL SI , 1
	ADD SI , -202
	MOV BP[SI] , BX
	PUSH BX
	POP AX
	; Expression statement ending at line 74

	; Expression statement starting at line 75
	MOV AX , 98
	PUSH AX
	POP SI
	SHL SI , 1
	ADD SI , -202
	PUSH BP[SI]
	MOV AX , 97
	PUSH AX
	POP SI
	SHL SI , 1
	ADD SI , -202
	PUSH BP[SI]
	POP CX
	POP AX
	ADD AX , CX
	PUSH AX
	MOV AX , 111
	PUSH AX
	POP CX
	POP AX
	ADD AX , CX
	PUSH AX
	POP BX
	MOV AX , 99
	PUSH AX
	POP SI
	SHL SI , 1
	ADD SI , -202
	MOV BP[SI] , BX
	PUSH BX
	POP AX
	; Expression statement ending at line 75

	; if statement starting at line 76
	PUSH BP[-2]
	MOV AX , 97
	PUSH AX
	POP CX
	POP AX
	CMP AX , CX
	JE L61
	MOV AX , 0
	JMP L62
L61:
	MOV AX , 1
L62:
	PUSH AX
	POP AX
	CMP AX , 0
	JNE L63
	JMP L64
L63:

	; Compund statement starting at line 76

	; Expression statement starting at line 78
	MOV AX , 99
	PUSH AX
	POP SI
	SHL SI , 1
	ADD SI , -202
	PUSH BP[SI]
	POP AX
	MOV BP[-204] , AX
	PUSH AX
	POP AX
	; Expression statement ending at line 78
	PUSH BP[-204]
	POP AX
	CALL println ; At line 79
	; Return statement at line 80
	MOV AX , 0
	PUSH AX
	POP AX
	JMP L55
	; Compund statement ending at line 81
L64:
	; if statement ending at line 81
	; Compund statement ending at line 82
	PUSH BP[-2]
	ADD WORD PTR BP[-2] , 1
	POP AX
	JMP L56
L58:	; for loop ending at line 82
	PUSH BP[-2]
	POP AX
	CALL println ; At line 83
	; Compund statement ending at line 84
L55:
	ADD SP , 204
	POP BP
	RET 0

loop_test_12 ENDP

main PROC
	MOV AX , @DATA
	MOV DS , AX
	PUSH BP
	MOV BP , SP
	SUB SP , 10

	; Compund statement starting at line 86

	; Expression statement starting at line 89
	MOV AX , 2
	PUSH AX
	POP AX
	MOV BP[-4] , AX
	PUSH AX
	POP AX
	; Expression statement ending at line 89

	; Expression statement starting at line 90
	MOV AX , 5
	PUSH AX
	POP AX
	MOV BP[-6] , AX
	PUSH AX
	POP AX
	; Expression statement ending at line 90

	; Expression statement starting at line 91
	PUSH BP[-6]
	PUSH BP[-4]
	CALL power_8 ; At line 91
	PUSH AX
	POP AX
	MOV number_2 , AX
	PUSH AX
	POP AX
	; Expression statement ending at line 91
	PUSH number_2
	POP AX
	CALL println ; At line 92

	; Expression statement starting at line 93
	MOV AX , 7
	PUSH AX
	CALL factorial_7 ; At line 93
	PUSH AX
	POP AX
	MOV number_2 , AX
	PUSH AX
	POP AX
	; Expression statement ending at line 93
	PUSH number_2
	POP AX
	CALL println ; At line 94

	; Expression statement starting at line 95
	CALL loop_test_12 ; At line 95
	PUSH AX
	POP AX
	; Expression statement ending at line 95

	; for loop starting at line 97
	; Expression statement starting at line 97
	MOV AX , 15
	PUSH AX
	POP AX
	MOV BP[-2] , AX
	PUSH AX
	POP AX
	; Expression statement ending at line 97
L66:

	; Expression statement starting at line 97
	PUSH BP[-2]
	MOV AX , 0
	PUSH AX
	POP CX
	POP AX
	CMP AX , CX
	JGE L69
	MOV AX , 0
	JMP L70
L69:
	MOV AX , 1
L70:
	PUSH AX
	POP AX
	; Expression statement ending at line 97
	CMP AX , 0
	JNE L67
	JMP L68
L67:

	; Expression statement starting at line 98
	MOV AX , 17000
	PUSH AX
	POP AX
	NEG AX
	PUSH AX
	MOV AX , 1000
	PUSH AX
	PUSH BP[-2]
	POP CX
	POP AX
	IMUL CX
	PUSH AX
	POP CX
	POP AX
	SUB AX , CX
	PUSH AX
	POP BX
	PUSH BP[-2]
	POP SI
	SHL SI , 1
	MOV array_5[SI] , BX
	PUSH BX
	POP AX
	; Expression statement ending at line 98
	PUSH BP[-2]
	SUB WORD PTR BP[-2] , 1
	POP AX
	JMP L66
L68:	; for loop ending at line 98

	; Expression statement starting at line 99
	MOV AX , 16
	PUSH AX
	POP AX
	MOV BP[-2] , AX
	PUSH AX
	POP AX
	; Expression statement ending at line 99
L71:	; while loop starting at line 100
	PUSH BP[-2]
	SUB WORD PTR BP[-2] , 1
	POP AX
	CMP AX , 0
	JNE L72
	JMP L73
L72:

	; Compund statement starting at line 100

	; Expression statement starting at line 102
	MOV AX , 15
	PUSH AX
	PUSH BP[-2]
	POP CX
	POP AX
	SUB AX , CX
	PUSH AX
	POP SI
	SHL SI , 1
	PUSH array_5[SI]
	POP AX
	MOV BP[-8] , AX
	PUSH AX
	POP AX
	; Expression statement ending at line 102
	PUSH BP[-8]
	POP AX
	CALL println ; At line 103
	; Compund statement ending at line 104
	JMP L71
L73:	; while loop ending at line 104
	PUSH BP[-2]
	POP AX
	CALL println ; At line 106

	; Expression statement starting at line 107
	MOV AX , 0
	PUSH AX
	POP AX
	MOV BP[-4] , AX
	PUSH AX
	POP AX
	; Expression statement ending at line 107

	; Expression statement starting at line 108
	MOV AX , 15
	PUSH AX
	POP AX
	MOV BP[-6] , AX
	PUSH AX
	POP AX
	; Expression statement ending at line 108

	; Expression statement starting at line 109
	PUSH BP[-6]
	PUSH BP[-4]
	CALL mergeSort_10 ; At line 109
	PUSH AX
	POP AX
	; Expression statement ending at line 109

	; for loop starting at line 111
	; Expression statement starting at line 111
	MOV AX , 0
	PUSH AX
	POP AX
	MOV BP[-2] , AX
	PUSH AX
	POP AX
	; Expression statement ending at line 111
L74:

	; Expression statement starting at line 111
	PUSH BP[-2]
	MOV AX , 16
	PUSH AX
	POP CX
	POP AX
	CMP AX , CX
	JL L77
	MOV AX , 0
	JMP L78
L77:
	MOV AX , 1
L78:
	PUSH AX
	POP AX
	; Expression statement ending at line 111
	CMP AX , 0
	JNE L75
	JMP L76
L75:

	; Compund statement starting at line 111

	; if statement starting at line 112
	PUSH BP[-2]
	MOV AX , 0
	PUSH AX
	POP CX
	POP AX
	CMP AX , CX
	JGE L81
	MOV AX , 0
	JMP L82
L81:
	MOV AX , 1
L82:
	PUSH AX
	POP AX
	CMP AX , 0
	JNE L79
	CALL MERGE_11 ; At line 112
	PUSH AX
	POP AX
	CMP AX , 0
	JNE L79
	MOV AX , 0
	JMP L80
L79:
	MOV AX , 1
L80:
	PUSH AX
	POP AX
	CMP AX , 0
	JNE L83
	JMP L84
L83:

	; Compund statement starting at line 112

	; Expression statement starting at line 113
	MOV AX , 1
	PUSH AX
	POP AX
	MOV WORD_1 , AX
	PUSH AX
	POP AX
	; Expression statement ending at line 113

	; Expression statement starting at line 114
	MOV AX , 3
	PUSH AX
	POP AX
	MOV WORD_1 , AX
	PUSH AX
	POP AX
	; Expression statement ending at line 114

	; Expression statement starting at line 115
	PUSH BP[-2]
	POP SI
	SHL SI , 1
	PUSH array_5[SI]
	POP AX
	MOV WORD_1 , AX
	PUSH AX
	POP AX
	; Expression statement ending at line 115
	PUSH WORD_1
	POP AX
	CALL println ; At line 116
	; Compund statement ending at line 117
L84:
	; if statement ending at line 117
	; Compund statement ending at line 118
	PUSH BP[-2]
	ADD WORD PTR BP[-2] , 1
	POP AX
	JMP L74
L76:	; for loop ending at line 118

	; for loop starting at line 119
	; Expression statement starting at line 119
	MOV AX , 0
	PUSH AX
	POP AX
	MOV BP[-2] , AX
	PUSH AX
	POP AX
	; Expression statement ending at line 119
L85:

	; Expression statement starting at line 119
	PUSH BP[-2]
	MOV AX , 16
	PUSH AX
	POP CX
	POP AX
	CMP AX , CX
	JL L88
	MOV AX , 0
	JMP L89
L88:
	MOV AX , 1
L89:
	PUSH AX
	POP AX
	; Expression statement ending at line 119
	CMP AX , 0
	JNE L86
	JMP L87
L86:

	; if statement starting at line 120
	PUSH BP[-2]
	MOV AX , 0
	PUSH AX
	POP CX
	POP AX
	CMP AX , CX
	JL L92
	MOV AX , 0
	JMP L93
L92:
	MOV AX , 1
L93:
	PUSH AX
	POP AX
	CMP AX , 0
	JE L90
	CALL MERGE_11 ; At line 120
	PUSH AX
	POP AX
	CMP AX , 0
	JE L90
	MOV AX , 1
	JMP L91
L90:
	MOV AX , 0
L91:
	PUSH AX
	POP AX
	CMP AX , 0
	JNE L94
	JMP L95
L94:

	; Compund statement starting at line 120

	; Expression statement starting at line 121
	PUSH BP[-2]
	POP SI
	SHL SI , 1
	PUSH array_5[SI]
	POP AX
	MOV _j_3 , AX
	PUSH AX
	POP AX
	; Expression statement ending at line 121
	PUSH _j_3
	POP AX
	CALL println ; At line 122
	; Compund statement ending at line 123
L95:
	; if statement ending at line 123
	PUSH BP[-2]
	ADD WORD PTR BP[-2] , 1
	POP AX
	JMP L85
L87:	; for loop ending at line 123

	; Expression statement starting at line 125
	MOV AX , 200
	PUSH AX
	POP AX
	MOV word_0 , AX
	PUSH AX
	POP AX
	; Expression statement ending at line 125
	PUSH word_0
	POP AX
	CALL println ; At line 126

	; Expression statement starting at line 127
	MOV AX , 23
	PUSH AX
	CALL fibonacci_6 ; At line 127
	PUSH AX
	POP AX
	; Expression statement ending at line 127

	; for loop starting at line 128
	; Expression statement starting at line 128
	MOV AX , 0
	PUSH AX
	POP AX
	MOV BP[-2] , AX
	PUSH AX
	POP AX
	; Expression statement ending at line 128
L96:

	; Expression statement starting at line 128
	PUSH BP[-2]
	MOV AX , 24
	PUSH AX
	POP CX
	POP AX
	CMP AX , CX
	JL L99
	MOV AX , 0
	JMP L100
L99:
	MOV AX , 1
L100:
	PUSH AX
	POP AX
	; Expression statement ending at line 128
	CMP AX , 0
	JNE L97
	JMP L98
L97:

	; Compund statement starting at line 128

	; Expression statement starting at line 130
	PUSH BP[-2]
	POP SI
	SHL SI , 1
	PUSH fib_mem_4[SI]
	POP AX
	MOV BP[-10] , AX
	PUSH AX
	POP AX
	; Expression statement ending at line 130
	PUSH BP[-10]
	POP AX
	CALL println ; At line 131
	; Compund statement ending at line 132
	PUSH BP[-2]
	ADD WORD PTR BP[-2] , 1
	POP AX
	JMP L96
L98:	; for loop ending at line 132
	; Compund statement ending at line 133
L65:
	ADD SP , 10
	POP BP
	MOV AH , 4CH
	INT 21H

main ENDP
println proc  ;print what is in ax
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
    mov ah,2
    mov dl,0DH
    int 21h
    mov ah,2
    mov dl,0AH
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
println endp

END MAIN
