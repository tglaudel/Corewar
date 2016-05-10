/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiraud <fgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 13:48:05 by ale-naou          #+#    #+#             */
/*   Updated: 2016/05/09 18:07:45 by fgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

void				print_processus(t_proc *start, t_env *e)
{
	t_proc	*proc;
	int last_pos;

	proc = start;
	while (proc)
	{
		last_pos = proc->pos - 1;
		if (last_pos < 0)
			last_pos = 4095;
		mvchgat(last_pos / 64, last_pos % 64 * 3, 2, A_NORMAL, e->col[last_pos], NULL);
		mvchgat(proc->pos / 64, proc->pos % 64 * 3, 2, A_BLINK, proc->champ_color + 4, NULL);
		proc = proc->next;
	}
}

static void print_champ(t_env *e)
{
	t_champ *champ;
	int pos;

	champ = e->champ_start;
	pos = 10;
	while (champ)
	{
		mvprintw(pos, 200, "%s : %s\n", "Name", champ->name);
		mvprintw(pos + 1, 200, "%s : %d\n", "last_live", champ->last_cycle_live);
		mvprintw(pos + 2, 200, "%s : %d\n", "nb_live", champ->nb_live);;
		champ = champ->next;
		pos += 5;
	}
}

static void print_info(t_env *e)
{
	mvprintw(29, 200, "%s : %d\n", "NB_CYCLE", e->nb_cycle);
	mvprintw(30, 200, "%s : %d\n", "CYCLE_TO_DIE", e->c_to_die);
	mvprintw(31, 200, "%s : %d\n", "MAX_CHECKS", MAX_CHECKS);
	mvprintw(32, 200, "%s : %d\n", "NBR_LIVE", NBR_LIVE);
	mvprintw(32, 200, "%s : %d\n", "NB_PROC_IN_LIFE", e->nb_proc_in_life);
}

void				print_board(t_env *e)
{
	int		pos;
	char	*mem_hexa;
	int		u;
	int		i;

	mem_hexa = (char*)malloc(sizeof(char) * 3);
	pos = -1;
	mem_hexa[2] = '\0';
	while (++pos < MEM_SIZE)
	{
		i = -1;
		u = e->mem[pos];
		while (++i < 2)
		{
			mem_hexa[i] = BASE_HEXA[u % 16];
			u /= 16;
		}
		mvaddch(pos / 64, (pos % 64) * 3, mem_hexa[1] | COLOR_PAIR(e->col[pos]));
		mvaddch(pos / 64, (pos % 64) * 3 + 1, mem_hexa[0] | COLOR_PAIR(e->col[pos]));
		mvaddch(pos / 64, (pos % 64) * 3 + 2, ' ');
	}
	usleep(10000);
	print_processus(e->proc_start, e);
	refresh();
}

static void		init_color_pair(void)
{
	init_pair(1, 1, COLOR_BLACK);
	init_pair(2, 2, COLOR_BLACK);
	init_pair(3, 3, COLOR_BLACK);
	init_pair(4, 4, COLOR_BLACK);
	init_pair(5, COLOR_BLACK, 1);
	init_pair(6, COLOR_BLACK, 2);
	init_pair(7, COLOR_BLACK, 3);
	init_pair(8, COLOR_BLACK, 4);
	init_pair(10, COLOR_WHITE, COLOR_BLACK);
}

void	init_ncurses2(void)
{
	initscr();
	keypad(stdscr, TRUE);
	start_color();
	init_color_pair();
}

void	ncruses_loop(t_env *e)
{
	usleep(50000);
	print_info(e);
	print_champ(e);
	print_processus(e->proc_start, e);
	refresh();
}


// void	init_ncurses(t_env *e)
// {
// 	e->curse.key = 0;
// 	initscr();
// 	noecho();
// 	e->curse.principal = subwin(stdscr, LINES, COLS / 1.4, 0, 0);
// 	e->curse.secondary_1 = subwin(stdscr,  LINES / 3, COLS / 4, 0, COLS / 1.4);
// 	e->curse.secondary_2 = subwin(stdscr,  LINES / 2, COLS / 4, LINES / 3, COLS / 1.4);
//
// 	box (e->curse.principal, ACS_VLINE, ACS_HLINE);
// 	box (e->curse.secondary_2, ACS_VLINE, ACS_HLINE);
// 	box (e->curse.secondary_1, ACS_VLINE, ACS_HLINE);
// 	raw();
// 	keypad(stdscr, TRUE);
// }
