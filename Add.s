	AREA ADDITION,CODE,READONLY
	ENTRY

	MOV R1,#&FFFFFFFF
	MOV R2,#1
	ADDS R0,R1,R2
STOP B STOP

	END