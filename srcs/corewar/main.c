/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 14:46:57 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/12 12:30:07 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

int				main(int ac, char **av)
{
	t_env e;

	if (ac < 2)
	{
		print_help();
		ft_errors("ERROR : invalide arguments.", 1, 0);
	}
	e.verbose = 0;
	e.opt = get_opt(&av[1], OPT_STRING);
	e.nb_cycle_max = -1;
	if (have_opt('v', e.opt))
		e.verbose = get_verbose(&av[1]);
	if (have_opt('d', e.opt))
		e.nb_cycle_max = get_ncycle(&av[1]);
	if (have_opt('h', e.opt))
		return (print_help());
	if (have_opt('c', e.opt))
		init_ncurses2();
	init_cor(&e, &av[1]);
	game_loop(&e);
	if (e.winner.winner != NULL)
		printf("Contestant %d, \"%s\", has won !\n", -e.winner.nb_win, e.winner.winner);
	print_board(&e);
	free_all(&e);
	endwin();
//	sleep(20);
	// free(e.curse.principal);
	// free(e.curse.secondary_2);
	// free(e.curse.secondary_1);
}
