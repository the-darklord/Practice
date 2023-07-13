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
        LDRH R2,[R0]
        LDRH R3,[R1]
        CMP R2,R3
		SUBGE R4,R2,R3
		SUBLE R4,R3,R2
        MUL R4,R4,R4
        LDR R5,=DST
        STR R4,[R5]
STOP    B STOP
N1 DCW 5
N2 DCW 10
        AREA mydata,DATA,READWRITE
DST DCD 0
        END