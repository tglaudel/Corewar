.name "test live"
.comment "test live"

live:
zjmp:
	ld  0, r3
	st		r3, 50
	zjmp %:live
	ld      %8, r14
	zjmp %:live
	live %1
	live %1
	live %1

test:
	live %15
