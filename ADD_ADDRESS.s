	AREA ADDITION,CODE,READONLY
	ENTRY
	LDR R0,=0X40000000
	LDR R1,[R0]
	LDR R2,[R0,#4]
	ADDS R3,R1,R2
	STR R3,[R0,#8]
STOP B STOP    //used to keep executing this block only

	END
