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

La machine Virtuel de Corewar suit se découpe en plusieurs éléments :
	- le(s) champion(s)
	- la mémoire de la machine
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

3) Les processus

Un processus est un "curseur" qui dispose de N registres qui seront initialisés
a 0 sauf le r1 qui aura le numéro du player et le dernier qui contiendra le
pc (program counter) qui aura l'adresse de la prochaine instruction a exécuter.

Au lancement de la VM un processus est donné a chaque champions est parcoura la
mémoire en boucle. Il exécutera toutes les instructions qu'il trouvera
indépendemment que l'instruction appartienne au même champion que le processus.

un processus va mourrir par défaut au bout de N cycle. Cette valeur peut être
revu a la baisse ou a la hausse sous certaines conditions.
