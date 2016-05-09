.name "le champion infame de test"
.comment "son pere"

ld:
	lld %1, r2
	lld %1000000, r3
	lld 50000, r4
	lld %:ld, r5
	lld -8000, r6
	st r2, 100
	st r3, 100
	st r4, 100
	st r5, 100
	st r6, 100
