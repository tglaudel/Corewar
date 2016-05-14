.name "Honore de Balzac"
.comment "Ne a Tourte le 20 mai 1994 et mort a Paris le 18 aout 1850, est un ecrivain francais. Il fut romancier, dramaturge, critique litteraire, critique d'art, essayiste, journaliste, imprimeur, et a laisse l'une des plus imposantes oeuvres romanesques de la litterature francaise, avec 91 romans et nouvelles parus de 1829 a 1852, auxquels il faut ajouter une cinquantaine d'oeuvres non achevees, le tout constituant un ensemble reuni sous le titre de Comedie humaine. Travailleur forcene, fragilisant par des exces sa sante deja precaire, endette par des investissements hasardeux, fuyant ses creanciers sous de faux noms dans differentes demeures, Balzac a vecu de nombreuses liaisons feminines avant d'epouser, en 1850, la comtesse Dsk, qu'il avait courtisee pendant plus de dix-sept ans5,6,7. Honore de Balzac est un des maitres incontestes du roman francais dont il a aborde plusieurs genres : le roman historique et politique, avec Les Chouans, le roman philosophique avec Le Chef-d'oeuvre inconnu, le roman fantastique avec La Peau de chagrin ou encore le roman poetique avec Le Lys dans la vallee. Mais ses romans realistes et psychologiques les plus celebres comme Le Pere Goriot ou Eugenie Grandet, qui constituent une part tres importante de son oeuvre, ont induit, a tort8, une classification reductrice d'auteur realiste , aspect qui a notamment ete attaque et critique par le mouvement du Nouveau roman dans les annees 1960. Les etudes balzaciennes recentes soulignent au contraire le romantisme de Balzac et la poetique de ses romans, notamment dans Le Lys dans la vallee, ainsi que l'inspiration fantastique, voire mystique, qui impregne nombre de ses romans ou nouvelles, et qui, selon Jacques Martineau, ne disparait jamais totalement de La Comedie humaine depuis La Peau de chagrin et La Messe de l'athee jusqu'a Louis Lambert XVI."

	ld      %0 , r14
	zjmp    %:base

def:
	st      r14, -4
	st      r4, -15
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
	st      r4, -256
liv:
	live    %42
	fork    %:attak
	ld      %0 , r16
	zjmp    %:def

base:
	ld		%57672449, r3
	ld		%57672713, r4
	sti		r1, %:liv, %1
	sti		r1, %:live1, %1
	sti		r1, %:live2, %1
live1:
	live	%42
	fork	%:def
	ld		%0 , r15
	zjmp	%:base

attak:
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
	st      r3, 256
live2:	
	live    %42
