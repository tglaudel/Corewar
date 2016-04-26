;basic.s

.name		"basic"
.comment	"this is a basic stuff"

loop:
	st r1, 6
	live %42
	ld %0, r2
	zjmp %:loop
