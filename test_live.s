.name "test live"
.comment "test live"

live:
	live %16
zjmp:
	live %4294967295
	live %4294967295
	live %4294967295
	live %4294967295
	live %4294967295
	live %4294967295
	live %4294967295
	ld      %2, r15
	zjmp %:live
	ld      %15, r14
	zjmp %:test
	live %1
	live %1
	live %1

test:
	live %1
