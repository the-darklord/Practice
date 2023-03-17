		AREA RESET,DATA,READONLY
		EXPORT __Vectors
__Vectors
		DCD 0x10001000
		DCD Reset_Handler
		ALIGN
		AREA mycode,CODE,READONLY
		ENTRY
		EXPORT Reset_Handler
Reset_Handler
		LDR R0,=N1
		LDR R1,=N2
		LDR R10,=DST
		MOV R2,R0
		MOV R3,R1
		MOV R11,R10
		ADD R2,#12
		ADD R3,#12
		ADD R11,#12
		MOV R4,#4
		MOV R5,#0
		MOV R6,#0
UP		LDR R7,[R2],#-4
		LDR R8,[R3],#-4
		ADDS R6,R7,R5
		ADDS R6,R8
		ADC R5,#0
		STR R6,[R11],#-4
		SUB R4,#1
		CMP R4,#0
		BNE UP
STOP	B STOP
N1 DCD 1,2,3,4
N2 DCD 4,3,2,1
		AREA mydata,DATA,READWRITE
DST DCD 0
		END