.name "test"
.comment "test"

# le flag est active et du coup il doit zjmp en boucle

back:
	ld %0, r4

zjmp %:back
