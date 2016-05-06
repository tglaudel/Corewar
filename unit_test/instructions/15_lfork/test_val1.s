.name "test"
.comment "test"

# le nouveau curseur devra commencer a partir de l'adresse de live donc du premier ld 02

live:
	ld %5, r2

lfork %:live
