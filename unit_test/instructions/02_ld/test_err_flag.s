.name "test"
.comment "test"

# le flag est active puis desactive il ne doit pas zjmp

back:
	ld %0, r4

ld %1, r4

zjmp %:back
