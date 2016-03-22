.name "zork"
.comment "I'M ALIIIIVE"

live:	live %1
		zjmp %:live

l2:		sti r1, %:live, %1
		and r1, %0, r1
		add	r1, r2, r3
		add	r1, r2, r3
		sub	r1, r2, r3
		sti r1, %:live, %1
		st r2, -400

