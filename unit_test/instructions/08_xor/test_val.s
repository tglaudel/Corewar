.name "test"
.comment "test"

# le resultat doit etre 00 00 00 00 | 00 00 b1 21 | 00 00 00 00

live:

st r3, 30
ld %45345, r3
st r3, 40
xor r3, r3, r4
st r4, 50
