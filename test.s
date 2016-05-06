.name "le petit test"
.comment "flo la tarlouze"

player:
	add r1, r7, r14
	st 	r14, 6

live:
	live %:player
	live %:player

ld:
	ld %7, r7


st r7, -70
st r7, -79
st r7, -88
st r7, -97
st r7, -106
st r7, -115
st r7, -124
st r7, -133
st r7, -142
st r7, -151
st r7, -160
st r7, -169
st r7, -178
st r7, -187
st r7, -196
st r7, -205
st r7, -214
zjmp %:live
ld %1, r6
ld %0, r7
sti r7, %:ld, r6
fork %:live
fork %:test
fork %:live
fork %:test
fork %:test
zjmp %:player


test:
	ld %0, r13
	ld %30, r13
	add r13, r11, r11
	sti r14, r11, %0
	ld %0, r13
	zjmp %:test
