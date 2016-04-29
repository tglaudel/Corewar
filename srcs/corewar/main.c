/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 14:46:57 by tglaudel          #+#    #+#             */
/*   Updated: 2016/04/29 18:34:50 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

// void print_verbose(int verbose)
// {
// 	if (verbose & VERBOSE_LIVE)
// 		ft_putendl("VERBOSE_LIVE");
// 	if (verbose & VERBOSE_CYCLE)
// 		ft_putendl("VERBOSE_CYCLE");
// 	if (verbose & VERBOSE_OP)
// 		ft_putendl("VERBOSE_OP");
// 	if (verbose & VERBOSE_DIE)
// 		ft_putendl("VERBOSE_DIE");
// 	if (verbose & VERBOSE_PC)
// 		ft_putendl("VERBOSE_PC");
// }

int				main(int ac, char **av)
{
	t_env e;

	if (ac < 2)
	{
		print_help();
		ft_errors("ERROR : invalide arguments.", 1, 0);
	}
	e.opt = get_opt(&av[1], OPT_STRING);
	e.nb_cycle_max = -1;
	if (have_opt('v', e.opt))
		e.verbose = get_verbose(&av[1]);
	if (have_opt('d', e.opt))
		e.nb_cycle_max = get_ncycle(&av[1]);
	if (have_opt('h', e.opt))
		return (print_help());
	if (have_opt('n', e.opt))
		init_ncurses(&e);
	init_cor(&e, &av[1]);
	game_loop(&e);
	// endwin();
	// free(e.curse.principal);
	// free(e.curse.secondary_2);
	// free(e.curse.secondary_1);
}
