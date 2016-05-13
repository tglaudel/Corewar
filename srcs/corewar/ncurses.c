/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 13:48:05 by ale-naou          #+#    #+#             */
/*   Updated: 2016/05/13 16:17:44 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

void	print_boarder_second(void)
{
	int i;

	i = -1;
	while (++i < (50))
	{
		mvchgat(0, i + 206, 2, A_BLINK, 11, NULL);
		mvchgat(67, i + 206, 2, A_BLINK, 11, NULL);
	}
	i = -1;
	while (++i < 67)
	{
		mvchgat(i, 206, 2, A_BLINK, 11, NULL);
		mvchgat(i, 255, 2, A_BLINK, 11, NULL);
	}
}

void	print_boarder_principal(void)
{
	int i;

	i = -1;
	while (++i < (204))
	{
		mvchgat(0, i, 2, A_BLINK, 11, NULL);
		mvchgat(67, i, 2, A_BLINK, 11, NULL);
	}
	i = -1;
	while (++i < 67)
	{
		mvchgat(i, 0, 2, A_BLINK, 11, NULL);
		mvchgat(i, 203, 2, A_BLINK, 11, NULL);
	}
}

void	init_ncurses(void)
{
	initscr();
	noecho();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	start_color();
	init_color_pair();
	print_boarder_principal();
	print_boarder_second();
}

void	ncurses_loop(t_env *e)
{
	char c;

	c = get_move();
	if (c == 'a')
		change_speed(e, -1000);
	else if (c == 'r')
		change_speed(e, 1000);
	else if (c == 's')
		wait_cycle(e);
	usleep(e->speed);
	print_info(e);
	print_champ(e);
	print_processus(e->proc_start, e);
	if (e->nb_cycle == 1)
		wait_cycle(e);
	refresh();
}
