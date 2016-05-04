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
	live %42949672959
	ld      %0, r17
	zjmp %:live
	ld      %15, r14
	zjmp %:liv
	live %1
	live %1
	live %1

test:
	live %15
