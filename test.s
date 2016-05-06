.name "le petit test"
.comment "flo la tarlouze"

#24 + (-40 mod IDX_MOD = 472)

player:
	add r1, r7, r14
	st 	r14, 6

live:
	live %:player
	live %:player

ld %0, r7

wall:
	st r7, -40

ld %0, r14
zjmp %:player
