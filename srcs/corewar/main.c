/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 14:46:57 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/14 11:03:59 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

static void		define_opt(t_env *e, char **av)
{
	e->verbose = 0;
	e->opt = get_opt(&av[1], OPT_STRING);
	e->nb_cycle_max = -1;
	if (have_opt('v', e->opt))
		e->verbose = get_verbose(&av[1]);
	if (have_opt('d', e->opt))
		e->nb_cycle_max = get_ncycle(&av[1]);
}

int				main(int ac, char **av)
{
	t_env e;

	if (ac < 2)
	{
		print_help();
		ft_errors("ERROR : invalide arguments.", 1, 0);
	}
	define_opt(&e, av);
	if (have_opt('h', e.opt))
		return (print_help());
	init_cor(&e, &av[1]);
	if (have_opt('c', e.opt))
		init_ncurses();
	game_loop(&e);
	if (have_opt('c', e.opt))
		ncurses_winner(&e);
	if (e.winner.winner != NULL)
		printf("Contestant %d, \"%s\", has won !\n", \
		-e.winner.nb_win, e.winner.winner);
	else
		printf("Contestant %d, \"%s\", has won !\n", \
		-e.champ_start->nb_champ, e.champ_start->name);
	print_board(&e);
	free_all(&e);
	endwin();
}
