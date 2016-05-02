.name "test"
.comment "test"

sti		r2, %50, %18
ld	%17, r1


en meme temps il est tout cuit le mien

ca c'est la fonction ncurses au faite
*3 pour les 'pixel'

ncurses c'est un tableau de LINES / COLS

x y représente ta position sur ces var la.

du coup comme une case memoire s'affiche forcement sur 3 x y

x y 1 = char 1
x y 2 = char 2
x y 3 = ' '

BON

ALORS

suite

implementation :

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

typedef struct		s_winst
{
	char			pos;
	char			taille;
	char			color;
	struct s_winst	*next;
}					t_winst

fonction(pos, taile ecriture, color)
