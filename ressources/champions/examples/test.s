.name "le champion infame de test"
.comment "son pere"

live:
	live %1

ld:
	ld %1, r1
	ld 42, r1
	ld %:ld, r1

st:
	st r1, r1
	st r1, 42

add:
	add r1, r1, r1

sub:
	sub r1, r1, r1

and:
	and r1, r1, r1
	and r1, 42, r1
	and r1, %1, r1
	and 42, r1, r1
	and 42, 42, r1
	and 42, %1, r1
	and %1, r1, r1
	and %1, 42, r1
	and %1, %1, r1
	and r1, %:ld, r1
	and 42, %:ld, r1
	and %:ld, r1, r1
	and %1, %:ld, r1
	and %:ld, %1, r1
	and %:ld, %:ld, r1

xor:
	xor r1, r1, r1
	xor r1, 42, r1
	xor r1, %1, r1
	xor 42, r1, r1
	xor 42, 42, r1
	xor 42, %1, r1
	xor %1, r1, r1
	xor %1, 42, r1
	xor %1, %1, r1
	xor r1, %:ld, r1
	xor 42, %:ld, r1
	xor %:ld, r1, r1
	xor %1, %:ld, r1
	xor %:ld, %1, r1
	xor %:ld, %:ld, r1

or:
	or r1, r1, r1
	or r1, 42, r1
	or r1, %1, r1
	or 42, r1, r1
	or 42, 42, r1
	or 42, %1, r1
	or %1, r1, r1
	or %1, 42, r1
	or %1, %1, r1
	or r1, %:ld, r1
	or 42, %:ld, r1
	or %:ld, r1, r1
	or %1, %:ld, r1
	or %:ld, %1, r1
	or %:ld, %:ld, r1

zjmp:
	zjmp %1
	zjmp %:ld

ldi:
	ldi r1, r1, r1
	ldi r1, %1, r1
	ldi %1, r1, r1
	ldi %1, %1, r1
	ldi 42, r1, r1
	ldi 42, %1, r1 #
	ldi r1, %:ld, r1
	ldi %:ld, r1, r1
	ldi 42, %:ld, r1
	ldi %1, %:ld, r1
	ldi %:ld, %1, r1
	ldi %:ld, %:ld, r1

sti:
	sti r1, r1, %1
	sti r1, r1, r1
	sti r1, %1, %1
	sti r1, %1, r1
	sti r1, 42, %1
	sti r1, 42, r1
	sti r1, %1, %:ld
	sti r1, %:ld, %1
	sti r1, 42, %:ld
	sti r1, %:ld, r1

fork:
	fork %1
	fork %:ld

lld:
	lld %1, r1
	lld 42, r1
	lld %:ld, r1

lldi:
	lldi r1, %1, r1
	lldi r1, r1, r1
	lldi %1, %1 , r1
	lldi %1, r1, r1
	lldi 42, %1, r1
	lldi 42, r1, r1 #
	lldi r1, %:ld, r1
	lldi %1, %:ld , r1
	lldi %:ld, r1, r1
	lldi 42, %:ld, r1
	lldi %:ld, %:ld , r1
	lldi %:ld, %1 , r1

lfork:
	lfork %1
	lfork %:ld

aff:
	aff r1
