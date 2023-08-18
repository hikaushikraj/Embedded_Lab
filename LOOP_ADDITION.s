	AREA ADDITION,CODE,READONLY						
	ENTRY                                           
	MOV R0,#2							       
	LDR R1,=0x40000000							
	LDR R2,[R1]
LOOP LDR R3,[R1,#4]!
	ADDS R3,R2,R3
	ADDCS R5,R5,#01
	MOV R2,R3

	SUBS R0,R0,#01
	CMP R0,#0
	BNE LOOP
STOP B STOP
	END
