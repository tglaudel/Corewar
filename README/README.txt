CYCLE_TO_DIE = le nombre de cycle entre chaque verification de live. En gros
			   tout les CYCLE_TO_DIE cycle, faut boucler sur les proc pour voir
			   ceux qui ont executer au moins un live et les autres, qui
			   meurent. ET POUR LUI JE PENSE QUE CE N'EST PAS UN RAPPORT AVEC LE
			   Processus, genre si un processus vient d'etre créer et que le
			   CYCLE_TO_DIE arrivent, bah si il a pas executé de live c'est
			   jambon on le tue.

			   en gros faire un FORK, faire un live. voila
			   et maintenant faut lié NBR_LIVE a ca

MAX_CHECKS = le nombre de verification max avant que le CYCLE_TO_DIE diminue
			 de CYCLE_DELTA. Ouais MAX_CHECKS bougera pas

CYCLE_DELTA = le  nombre de decrement a faire sur le CYCLE_TO_DIE.

NBR_LIVE = si un proc arrive a NBR_LIVE on decremente CYCLE_TO_DIE de CYCLE_DELTA
