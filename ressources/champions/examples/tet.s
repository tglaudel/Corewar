.name "mon champion nul"
.comment "ton pere"


live: live %1
	st			r16, -400 #coucou
	st 		r12, -400
	sti			r2, 23, %1
	live %1
	sti r1, %:endwhile, %1
	#coucou
endwhile:	aff		r1
	lld		12, r1
	live %1
	xor		r1, r1, r3
	live %1
	zjmp	%:live		;if (carry)
	sti r1,%:live,%1
	and			r1, %0, r3
