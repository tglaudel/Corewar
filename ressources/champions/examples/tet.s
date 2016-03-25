.name "mon champion nul"
.comment "ton pere"


live: live %1
	st			r16, -400 #coucou
	st 		r12, -400
	sti			r2, 23, %1
	live %1
	sti r1, %:endwhile, %1
	#coucou
	add			r1, r2, r3
endwhile:	aff		r1
	lld		12, r1
	live %1
	xor		r1, r1, r3
	live %1
	zjmp	%:live		;if (carry)
