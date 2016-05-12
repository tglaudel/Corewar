t############################################################################
#  _____                                                                   #
# /  __ \                                                                  #
# | /  \/ ___  _ __ _____      ____ _ _ __                                 #
# | |    / _ \| '__/ _ \ \ /\ / / _` | '__|                                #
# | \__/\ (_) | | |  __/\ V  V / (_| | |                                   #
#  \____/\___/|_|  \___| \_/\_/ \__,_|_|                                   #
#                                                                          #
#                                                                          #
############################################################################

COREWAR est un jeu dans lequel des champions essaie de se "détruire" les uns les
autres dans la mémoire d'une machine virtuelle.


VM explication :

############################################################################

La Machine Virtuel (VM, pour Virtual Machine) de Corewar
se découpe en plusieurs éléments :
	- le(s) champion(s);
	- la mémoire de la machine;
	- le(s) processus;
	- les instructions.

1) Le champion :
	- Nom :
Le nom du champion n'impacte pas la memoire. Il permet uniquement
d'afficher le nom du champion victorieux.

	- Commentaire :
N'a aucun impact sur la VM.

	- Instructions :
Une instruction est une action à effectuer par un processus.
Elle représente N octet en mémoire.
Les instructions sont diverses et peuvent notamment créer de nouveaux processus.
Une instruction peut agir sur la memoire de la VM ainsi que sur les
regitres dont sont composés chaque processus.

-------------------------------------------------------------------------------

2) Mémoire

La Mémoire représente "l'arène" dans laquelle les champions vont s'affronter.

La mémoire est de MEM_SIZE octets.
Elle est linéaire. Elle s'exécute en boucle :
L'adresse du premier octet est la même que celle du dernier + 1.
Elle est initialisée à 0 : on la remplie de '\0'.

Lors du chargement d'un champion dans la VM, toutes les instructions
qui le composent sont insérés à la suite dans l'espace qui lui est alloué.
Cet espace est défini arbitrairement à (MEM_SIZE / 6) octets.

-------------------------------------------------------------------------------

3) Les processus

Un processus est un "mini programme" se deplacant, à chaque cycle, sur l'octet
suivant dans la memoire.
En début de partie, un processus est crée sur la première instruction de chaque
champion, par souci d'équité, afin qu'il puisse effectuer leurs instructions
"simultanément". Ceci empêchant le premier champion chargé de "déployer" toute
sa stratégie, avant que les champions suivants n'ai pu faire quoique ce soit.
Cependant, il y a tout de même une notion de chronologie dans "l'activation"
de chaque processus : Le dernier crée sera le premier à effectuer une action.
	ex : Au début de partie, si il y a 3 champions, le premier processus, à
		 s'activer, sera celui du champion #3, puis celui du #2 et enfin le #1.
		 Si le champion 2 crée un nouveau processus, alors que les deux autres
	 	 champions n'en ont toujours qu'un chacun. L'ordre sera :
		 	- 4 (#2),
			- 3 (#3),
			- 2 (#2),
			- 1 (#1).

Un processus est composée :
 	- de registres;
	- d'un PC (program counter);
	- d'un carry.


	a) Les registres

Chaque processus a une mémoire qui lui est propre, les registres.
Ils sont au nombre de REG_NUMBER. Et initialisés à 0,
à l'expection du premier (r1) qui aura comme valeur le numéro du champion
lors de son chargement dans la mémoire.
Chaque registre est de taille REG_SIZE.
Un registre permettra, par exemple, de pouvoir stocker des valeurs dans
la memoire, de les modifier et de les réécrire ailleurs dans la mémoire.

		b) Le PC (program counter)

Le PC est un pointeur vers la prochaine instruction à executer :


l'addresse du prochain octet de la memoire sur lequel le processus devra se
rendre, une fois l'instruction en cours éxécutée.

		c) Le carry

Le "flag" carry aura une valeur de 0 ou 1 dans chaque processus. Et est
initialisé à zéro.
Il permet la validation de l'execution de l'instruction 'zjmp', si le carry a
été changé à 1.
Il peut être modifié par les instructions suivantes :
	 - ld;
	 - lld;
	 - lldi;
	 - add;
	 - sub;
	 - and;
	 - or;
	 - xor.
Il ne vaut 1 que lorsqu'une de ces instructions (opérations) a un résultat de 0.

A savoir que se sera la derniere operation qui sera pris en compte dans la
modification du carry.

-------------------------------------------------------------------------------

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

	pour ce projet corewar sont :

	nous allons parler ici de DIR, INDIR, et REG pour mieux comprendre ces
	termes lizer plus bas. Ainsi que "|" qui signifera "ou" et "," qui viendra
	dire "et". Nous allons aussi parler du carry je vous invite a aller voir la
	section consacre sur le carry pour mieux comprendre.

	a) live -> opcode = 1

	instruction qui permet de declarer a la VM qu'un processus est vivant et
	donc de le rester. Mais le plus important est de rapporter un live donc une
	instruction je suis en vie sur un personnage. La valeur du live determinera
	quel champion est en vie. -4 player4 -56 player56 meme si le nombre est
	normalement limite a 4 joueurs etc...

	il ne prendra qu'un parametre qui sera un DIR.

	nombre de cycle to wait : 10

	b) ld -> opcode = 2

	il prendra en parametre {DIR | IND, REG}.

	ld va prendre la valeur du premier parametre donc DIR ou IND et mettra cette
	valeur dans le le troisieme donc le registre. il changera la valeur du carry.

	nombre de cycle to wait : 5

	c) st -> opcode = 3

	il prendra en parametre {REG, IND | REG}

	pareil que pour ld sauf que la se sera directement la valeur du registre qui
	sera stocker dans la memoire.

	nombre de cycle to wait : 5

	d) add -> opcode = 4

	il prendre en parametre {REG, REG, REG}

	il va donc prendre trois registres et additionne les valeurs des deux
	premiers et stockera le resultat dans le troisieme. Il modifiera le carry.

	nombre de cycle to wait : 10

	e) sub -> opcode = 5

	il prendra en parametre {REG, REG, REG}


	pareil que pour add sauf que la il va soustraire les valeurs et modifiera
	aussi le carry.

	nombre de cycle to wait : 10

	f) and -> opcode = 6

	il prendra en parametre {REG | DIR | IND, REG | IND | DIR, REG}

	il va appliquer un & (et) binaire sur les deux premieres valeurs des deux
	premiers parametres et stocke le resultat dans le troisieme. Il va modifier
	le carry.

	nombre de cycle to wait : 6

	g) or -> opcode = 7

	il prendra en parametre {REG | DIR | IND, REG | IND | DIR, REG}

	il va appliquer un | (ou) binaire sur les deux premieres valeurs des deux
	premiers parametres et stocke le resultat dans le troisieme. Il va modifier
	le carry.

	nombre de cycle to wait : 6

	h) xor -> opcode = 8

	il prendra en parametre {REG | DIR | IND, REG | IND | DIR, REG}

	il va appliquer un ou exclusif binaire sur les deux premieres valeurs des deux
	premiers parametres et stocke le resultat dans le troisieme. Il va modifier
	le carry.

	i) zjmp -> opcode = 9

	il prendra en parametre un DIR.

	il enverra le curseur a la valeur contenu dans le DIR si et seulement si
	le carry est a 1.

	nombre de cycle to wait : 20

	j) ldi -> opcode = 10

	il prendra en parametre {REG | DIR | IND, DIR | REG, REG}.

	il va additionner les valeurs des deux premiers parametres les additionner
	afin de s'en servir comme une adresse relative a sa position et enverra
	a cette adresse la valeur du troisieme parametre.

	nombre de cycle to wait : 25

	k) sti -> opcode = 11

	il prendra en parametre {REG, REG | DIR | IND, DIR | REG}

	additionne les deux derniers parametres s'en sert comme une adresse et va
	mettre la valeur du premier a cette nouvelle adresse relative.

	nombre de cycle to wait : 25

	l) fork -> opcode = 12

	il prendra en parametre {DIR}

	il va creer un nouveau processus qui va herite de tous les elemes de son
	parents a part du pc qui sera mis a (PC + (1er paramètre % IDX_MOD)).

	nombre de cycle to wait : 800

	m) lld -> opcode = 13

	il prendra en parametre {DIR | IND, REG}

	meme chose que ld donc modifie le carry sauf qu'il n'y a pas besoin
	d'appliquer % IDX_MOD.

	nombre de cycle to wait : 10

	n) lldi -> opcode = 14

	il prendra en parametre {REG | DIR | IND, DIR | REG, REG}
	meme chose que ldi sans % IDX_MOD et lui par contre modifiera le carry.

	nombre de cycle to wait : 50

	o) lfork -> opcode = 15

	il prendra en parametre {DIR}

	exactement comme fork juste sans % IDX_MOD

	nombre de cycle to wait : 1000

	p) aff -> opcode = 16

	il prendra en parametre {REG}

	stock un evaleur dans un reg qui doit etre interprete comme un code ASCII
	et afficher sur l'entree standard

	nombre de cycle to wait : 2




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
