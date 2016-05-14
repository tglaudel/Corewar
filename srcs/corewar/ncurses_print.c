/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 15:49:58 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/14 11:19:43 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

void	print_processus(t_proc *start, t_env *e)
{
	t_proc	*proc;
	int		last_pos;

	proc = start;
	while (proc)
	{
		last_pos = proc->pos - 1;
		if (last_pos < 0)
			last_pos = 4095;
		mvchgat(last_pos / 64 + 2, last_pos % 64 * 3 + 6, 2, A_NORMAL,\
			e->col[last_pos], NULL);
		mvchgat(proc->pos / 64 + 2, proc->pos % 64 * 3 + 6, 2, A_BLINK,\
			proc->champ_color + 4, NULL);
		proc = proc->next;
	}
}

void	print_board(t_env *e)
{
	int		pos;
	char	mem_hexa[3];
	int		u;
	int		i;

	pos = -1;
	ft_bzero(mem_hexa, 3);
	while (++pos < MEM_SIZE)
	{
		i = -1;
		u = e->mem[pos];
		while (++i < 2)
		{
			mem_hexa[i] = BASE_HEXA[u % 16];
			u /= 16;
		}
		mvaddch(pos / 64 + 2, (pos % 64) * 3 + 6, mem_hexa[1] |\
		COLOR_PAIR(e->col[pos]));
		mvaddch(pos / 64 + 2, (pos % 64) * 3 + 1 + 6, mem_hexa[0] |\
		COLOR_PAIR(e->col[pos]));
		mvaddch(pos / 64 + 2, (pos % 64) * 3 + 2 + 6, ' ');
	}
	print_processus(e->proc_start, e);
}

void	print_info(t_env *e)
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

void	ncurses_winner(t_env *e)
{
	while (1)
	{
		mvprintw(45, 212, "WINNER IS  !!!");
		mvprintw(46, 212, "%s", e->winner.winner);
		mvprintw(48, 212, "KEY_UP for QUIT");
		if (get_move() == 's')
			break ;
	}
}

void	print_champ(t_env *e)
{
	t_champ	*champ;
	int		pos;

	champ = e->champ_start;
	pos = 10;
	while (champ)
	{
		mvprintw(pos, 212, "%s : %s\n", "Name", champ->name);
		mvprintw(pos + 1, 212, "%s : %d\n", "last_live",\
		champ->last_cycle_live);
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
