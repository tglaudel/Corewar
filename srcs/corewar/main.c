/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiraud <fgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 14:46:57 by tglaudel          #+#    #+#             */
/*   Updated: 2016/04/29 14:44:47 by fgiraud          ###   ########.fr       */
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
	e.opt = get_opt(&av[1], OPT_STRING);
	if (have_opt('h', e.opt))
		return (print_help());
	if (have_opt('n', e.opt))
		init_ncurses(&e);
	init_cor(&e, &av[1]);
	game_loop(&e);
	endwin();
	free(e.curse.principal);
	free(e.curse.secondary_2);
	free(e.curse.secondary_1);
}
