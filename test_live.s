.name "test live"
.comment "test live"

live:
	live %4294967295
zjmp:
	live %4294967295
	live %4294967295
	live %4294967295
	live %4294967295
	live %4294967295
	live %4294967295
	live %4294967295
	zjmp %:test
	live %1
	live %1
	live %1

test:
	live %1
