.name "You Know nothing"
.comment "May the 4th be with you"

	st r2, %:live, r1
	and %0, r1, r1

live:	    live %1
	        zjmp %:live