.name "mon champion nul"
.comment "ton pere"


test: live %1
	st			r16, -400 #coucou
	st 		r12, -400
	sti			r2, 23, 400
	sti r1, %:live, %1
	#coucou
	add			r1, r2, r3
	aff		r1
	lld		12, r1
	xor		r1, r1, r3
