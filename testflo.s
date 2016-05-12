.name "le petit test"
.comment "flo la tarlouze"



add r1, r2, r2
st r2, 9
fork %:fork

live:
	live %-42

ld %:live, r5
ld %0, r6
zjmp %:live

fork:
	st r2, 6
	live %-42
	fork %:wall
	st r2, 6
	live %-42
	ld %0, r6
	zjmp %:fork


wall:
	st r2, 6
	live %-42
	st r6, -90
	st r6, -99
	st r6, -108
	st r6, -117
	st r6, -126
	st r6, -135
	st r6, -144
	st r6, -153
	st r6, -162
	st r6, -171
	st r6, -180
	st r6, -189
	st r6, -198
	st r6, -207
	st r6, -216
	st r6, -225
	st r6, -234
	st r6, -243
	st r6, -252
	st r6, -261
	st r6, -270
	st r6, -279
	st r6, -288
	st r6, -297
	st r6, -306
	st r6, -315
	st r2, 6
	live %-42
	ld %0, r6
	zjmp %:wall
