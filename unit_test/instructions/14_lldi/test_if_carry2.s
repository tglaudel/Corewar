.name "test"
.comment "test"

# il ne doit pas y avoir de boucle


live:
	lldi %50, %50, r5
st r5, 30
lldi %0, %0, r5
st r5, 40
zjmp %:live
