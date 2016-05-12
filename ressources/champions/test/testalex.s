.name "ale-naou"
.comment "Ca sent pas bon"

#ld		%0, r2
#zjmp	%-1
#st		r2, 100

#ld		0, r3
#ld		%0, r2
#zjmp	%-1
#st		r3, -1

#ld		%21234567874523, r4
#ld		%21234567874523, r5
#ld		%42, r7
#sti 	r7, r4, r5
#sti	r8, r3, r7

ld %
