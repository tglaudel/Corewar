/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiraud <fgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 13:48:05 by ale-naou          #+#    #+#             */
/*   Updated: 2016/04/29 15:09:54 by fgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

void	init_ncurses(t_env *e)
{
	e->curse.key = 0;
	initscr();
	noecho();
	e->curse.principal = subwin(stdscr, LINES, COLS / 1.4, 0, 0);
	e->curse.secondary_1 = subwin(stdscr,  LINES / 3, COLS / 4, 0, COLS / 1.4);
	e->curse.secondary_2 = subwin(stdscr,  LINES / 2, COLS / 4, LINES / 3, COLS / 1.4);

	box (e->curse.principal, ACS_VLINE, ACS_HLINE);
	box (e->curse.secondary_2, ACS_VLINE, ACS_HLINE);
	box (e->curse.secondary_1, ACS_VLINE, ACS_HLINE);
	raw();
	keypad(stdscr, TRUE);
}
