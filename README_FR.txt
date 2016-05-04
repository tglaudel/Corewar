############################################################################
#  _____                                                                   #
# /  __ \                                                                  #
# | /  \/ ___  _ __ _____      ____ _ _ __                                 #
# | |    / _ \| '__/ _ \ \ /\ / / _` | '__|                                #
# | \__/\ (_) | | |  __/\ V  V / (_| | |                                   #
#  \____/\___/|_|  \___| \_/\_/ \__,_|_|                                   #
#                                                                          #
#                                                                          #
############################################################################

VM explication :

############################################################################

La machine Virtuel de Corewar se découpe en plusieurs éléments :
	- le(s) champion(s)
	- la mémoire de la machine
	- les instructions
	- le(s) processus

1) Le champion :
	- son nom :

Le nom du champion n'impactera pas la memoire il permettra éventuellement
d'afficher qu'elle champion a gagné.

	- un commentaire :

Celui-ci n'impactera en rien du tout dams la machine virtuelle.

	- ses instructions :

Les instructions sont des actions á effectuer pour le champion. Une
instruction représente N octet en mémoire.
toutes les instructions seront écrites dans la mémoire de la machine a la suite
dans l'espace qui sera attribué au champion dans la mémoire.

Ses instructions sont diverses et peuvent notament créé de nouveaux processus.

Une instruction peut agir aussi bien sur la memoire de la machine, que les
regitres donc qui appartiennent aux processus.

2) la mémoire de la machine

Cette mémoire est dites linéaire et s'exécute en boucle et est remplie de '\0'.

Tous les champions donc leurs instructions sont chargées dans la mémoire de
façon équitable.

3) Les instructions

Une instruction est decompose de cette facon :

-	opcode (OPC)
-	octet de codage
-	parametres de l'OPC

	a) opcode

		definie dans le .h des ressources donc pas besoin d'en dire plus.

	b) octet de codage

		il va permettre de savoir ce que l'instruction attend comme parametres.
		//A completer

	c) parametres de l'insctruction

		ils seront de type DIR, INDIR ou REG
		//A completer

4) Les processus

Un processus est un "mini programme" ou "curseur". En debut de partie chaque
champions a un processus qui lui est **"propre" (a prendre avec nuance vous
comprendrez par la suite). Ce curseur va parcourir la memoire et contiendra
un certains nombre d'informations qu'on decoupera ainsi:
 	- les registres
	- le pc (program counter)
	- le carry


		a) Les registres

Les registres sont la memoire interne du programme. Ils sont de taille
REG_NUMBER initialises a 0 sauf le r1 qui lui aura la valeur du champion. chaque
registre est de taille REG_SIZE, pour ma part se sera 4 octets.

Il permettra par exemple de pouvoir stocker des valeur de la memoire les
modifier afin de les ecrire ailleurs dans la memoire.

		b) Le pc (program counter)

Le PC, est un pointeur vers la prochaine instruction a executer, le prochain
octet de la memoire ou devra aller le "curseur"

		c) Le carry

le flag carry est une valeur initialise a 0 dans chaque processus. Il permet de
savoir si le resultat de la derniere instruction modifie le carry a 1 ou non.
seul certaines instructions modifie le carry :
 - lld
 - ld
 - add
 - sub
 - lldi
 - and
 - or
Ces instructions feront passer le carry a 1 si le resultat de l'operation est 0.

le changement du carry a 1 interesse seulement l'instruction zjmp.

A savoir que se sera la derniere operation de qui sera pris en compte dans la
modification du carry.

Exemple:

Insctrution1->opearation == 0 carry = 1, Instruction2->operation != 0 carry = 0.

Il y a encore un element a prendre en compte. Si une instruction, avec un octet
de codage bon et des parametres du bon type mais pas avec les bonnes valeurs par
exemple un processus avec REG_NUMBER = 16, si on se retrouve avec r18
l'instruction ne s'executera simplement pas et le carry restera a son etat
precedent.

Exemple:

Insctrution1->opearation == 0 carry = 1, Instruction2->operation != 0  mais
parametres de l'insctrution non valide carry = 1.

Les erreurs concernant le processus :

	- si l'opcode est bon mais que les parametres ne sont pas bon l'instruction
	ne sera pas execute mais le processus attendra bien N cycle de l'instruction

Informations supplementaires sur les processus :

	- ** effectivement un processus appartient bien a un champion mais ce n'est
	pas parce qu'il va execute une instruction que celle-ci appartiendra au
	champion.

		Exemple :
		un processus avec r1 = player1 et une instruction live(player2). Le live
		sera execute pour le player 2 et non pour le player1.

	Le processus ne fait donc qu'execute les instructions independemment de
	l'appartenance de celui-ci a un player.
