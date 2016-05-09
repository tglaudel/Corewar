.name "ale-naou"
.comment "Ca sent pas bon"

#ld		%0, r2
#zjmp	%-1
#st		r2, 100

ld		0, r3
ld		%0, r2
zjmp	%-1
st		r3, -1
