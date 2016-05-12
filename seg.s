.name "You Know nothing"
.comment "May the 4th be with you"

	and %0, r1, r1

live:	 # test
live %1
	        zjmp %:live
