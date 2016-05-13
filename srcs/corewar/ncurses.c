/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 13:48:05 by ale-naou          #+#    #+#             */
/*   Updated: 2016/05/13 11:54:10 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cor.h"

void	print_boarder_second(void)
{
	int i;

	i = -1;
	while (++i < (50))
	{
		mvchgat(0, i + 206, 2, A_BLINK, 11 , NULL);
		mvchgat(67, i + 206 , 2, A_BLINK, 11 , NULL);
	}
	i = -1;
	while (++i < 67)
	{
		mvchgat(i, 206, 2, A_BLINK, 11 , NULL);
		mvchgat(i, 255, 2, A_BLINK, 11 , NULL);
	}
}

void	print_boarder_principal(void)
{
	int i;

	i = -1;
	while (++i < (204))
	{
		mvchgat(0, i, 2, A_BLINK, 11 , NULL);
		mvchgat(67, i, 2, A_BLINK, 11 , NULL);
	}
	i = -1;
	while (++i < 67)
	{
		mvchgat(i, 0, 2, A_BLINK, 11 , NULL);
		mvchgat(i, 203, 2, A_BLINK, 11 , NULL);
	}
}

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
		mvchgat(last_pos / 64 + 2, last_pos % 64 * 3 + 6, 2, A_NORMAL, e->col[last_pos], NULL);
		mvchgat(proc->pos / 64 + 2, proc->pos % 64 * 3 + 6, 2, A_BLINK, proc->champ_color + 4, NULL);
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
		mvprintw(pos, 212, "%s : %s\n", "Name", champ->name);
		mvprintw(pos + 1, 212, "%s : %d\n", "last_live", champ->last_cycle_live);
		mvprintw(pos + 2, 212, "%s : %d\n", "nb_live", champ->nb_live);
		mvchgat(pos, 209, 2, A_BLINK, champ->color + 4, NULL);
		mvchgat(pos + 1, 209, 2, A_BLINK, champ->color + 4, NULL);
		mvchgat(pos + 2, 209, 2, A_BLINK, champ->color + 4, NULL);
		champ = champ->next;
		pos += 5;
	}
	print_boarder_principal();
	print_boarder_second();
}

char	get_move(void)
{
	int c;
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

static void print_info(t_env *e)
{
	int i;

	i = -1;

	mvprintw(29, 212, "%s : %d\n", "NB_CYCLE", e->nb_cycle);
	mvprintw(30, 212, "%s : %d\n", "CYCLE_TO_DIE", e->c_to_die);
	mvprintw(31, 212, "%s : %d\n", "MAX_CHECKS", MAX_CHECKS);
	mvprintw(33, 212, "%s : %d\n", "NBR_LIVE", NBR_LIVE);
	mvprintw(34, 212, "%s : %d\n", "NB_PROC_IN_LIFE", e->nb_proc_in_life);
	mvprintw(36, 212, "%s : %d\n", "SPEED", e->speed_mult);
	mvprintw(3, 212, "%s", "  ___ ___  _ __ _____      ____ _ _ __ ");
	mvprintw(4, 212, "%s", " / __/ _ \\| '__/ _ \\ \\ /\\ / / _` | '__|");
	mvprintw(5, 212, "%s", "| (_| (_) | | |  __/\\ V  V / (_| | |   ");
	mvprintw(6, 212, "%s", " \\___\\___/|_|  \\___| \\_/\\_/ \\__,_|_|   ");
	mvprintw(7, 214, "%s", "By ale-naou, fgiraud, tglaudel");
	mvprintw(39, 216, "%s", "USAGE :");
	mvprintw(41, 212, "%s", "KEY_UP : start / pause");
	mvprintw(42, 212, "%s", "KEY_LEFT : speed--");
	mvprintw(43, 212, "%s", "KEY_RIGHT : speed++");
	while (++i < 8)
		mvchgat(29 + i, 209, 2, A_BLINK, 12, NULL);
}

void				ncurses_winner(t_env *e)
{
	while (1)
	{
		mvprintw(45, 212, "WINNER IS  !!!");
		mvprintw(46, 212, "%s", e->winner.winner);
		mvprintw(48, 212, "KEY_UP for QUIT");
		if (get_move() == 's')
			break;
	}
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
		mvaddch(pos / 64 + 2, (pos % 64) * 3 + 6, mem_hexa[1] | COLOR_PAIR(e->col[pos]));
		mvaddch(pos / 64 + 2, (pos % 64) * 3 + 1 + 6, mem_hexa[0] | COLOR_PAIR(e->col[pos]));
		mvaddch(pos / 64 + 2, (pos % 64) * 3 + 2 + 6, ' ');
	}
	usleep(10000);
	ft_strdel(&mem_hexa);
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
	init_pair(9, COLOR_BLACK, COLOR_BLACK);
	init_pair(10,COLOR_BLACK , COLOR_WHITE);
	init_pair(11, COLOR_BLACK, 8);
	init_pair(12, COLOR_BLACK, 6);
}

void	init_ncurses2(void)
{
	initscr();
	noecho();
	nodelay (stdscr, TRUE);
	keypad(stdscr, TRUE);
	start_color();
	init_color_pair();
	print_boarder_principal();
	print_boarder_second();
}

void	change_speed(t_env *e, int n)
{
	if (e->speed == 1000 && n == -1000)
		return ;
	if (e->speed >= 1000)
		e->speed += n;
	e->speed_mult = -(e->speed / 1000) + 10;
}

void	wait_cycle(t_env *e)
{
	char c;

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
