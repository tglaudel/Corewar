.name "le champion infame de test"
.comment "son pere"

ld:
	live %-1
st:
	ld %2415919104, r2
	st r2, 1
	ld %0, r1
	zjmp %:st
