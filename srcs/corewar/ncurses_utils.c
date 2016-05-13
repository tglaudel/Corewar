/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 15:53:08 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/13 16:17:01 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

char		get_move(void)
{
	int	c;

	if ((c = getch()))
	{
		if (c == KEY_UP)
			return ('s');
		if (c == KEY_RIGHT)
			return ('a');
		if (c == KEY_LEFT)
			return ('r');
	}
	return (0);
}

void		change_speed(t_env *e, int n)
{
	if (e->speed == 1000 && n == -1000)
		return ;
	if (e->speed >= 1000)
		e->speed += n;
	e->speed_mult = -(e->speed / 1000) + 10;
}

void		init_color_pair(void)
{
	init_pair(1, 1, COLOR_BLACK);
	init_pair(2, 2, COLOR_BLACK);
	init_pair(3, 3, COLOR_BLACK);
	init_pair(4, 4, COLOR_BLACK);
	init_pair(5, COLOR_BLACK, 1);
	init_pair(6, COLOR_BLACK, 2);
	init_pair(7, COLOR_BLACK, 3);
	init_pair(8, COLOR_BLACK, 4);
	init_pair(9, COLOR_BLACK, COLOR_BLACK);
	init_pair(10, COLOR_BLACK, COLOR_WHITE);
	init_pair(11, COLOR_BLACK, 8);
	init_pair(12, COLOR_BLACK, 6);
}

void		wait_cycle(t_env *e)
{
	char	c;

	while (1)
	{
		c = get_move();
		if (c == 'a')
			change_speed(e, -1000);
		else if (c == 'r')
			change_speed(e, 1000);
		else if (c == 's')
			break ;
	}
}
