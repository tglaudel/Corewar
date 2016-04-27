.name "le champion infame de test"
.comment "son pere"

	and %1, %1, r1
	or %1, %1, r1
	ldi %1, %1, r1
	lldi %1, %1, r1
ld:
	lldi %1, r1, r1
	ldi %1, r1, r1
	or %1, r1, r1
	and %1, r1, r1

	and r1, 42, r1
	or r1, 42, r1
	sti r1, 42, r1

	ldi r1, %1, r1
	sti r1, %1, r1
test:
	and %:test, %:test, r1
	or %:test, %:test, r1
	ldi %:test, %:test, r1
	lldi %:test, %:test, r1


		#{"and", 3, 6, 1, 0},
		#{"or", 3, 6, 1, 0},
		#{"ldi", 3, 25, 1, 1},
		#{"lldi", 3, 50, 1, 1},
		#{"sti", 3, 25, 1, 1},
