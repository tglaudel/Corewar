.name "test"
.comment "test"

# le resultat doit etre a4 00 00 00

lldi %0, %1, r5
st r5, 20
