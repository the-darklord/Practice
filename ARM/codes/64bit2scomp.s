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
		LDR R2,=SRC
		MOV R0,#0
		MOV R1,#0
		ADD R2,#4
		LDR R3,[R2],#-4
		MOV R4,#0
		RSBS R0,R3,#0
		ADC R4,#0
		LDR R3,[R2]
		ADD R3,R4
		RSBS R1,R3,#0
STOP	B STOP
SRC DCD 1,2
		AREA mydata,DATA,READWRITE
		END