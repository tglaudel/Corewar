/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 18:00:08 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/07 16:02:25 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

void print_processus_debug(t_proc *start, int nb_cycle)
{
	t_proc *proc;

	proc = start;
	ft_putstr("proc list : ");
	while (proc)
	{
		ft_putnbr(proc->index);
		ft_putchar(' ');
		proc = proc->next;
	}
	ft_printf(" ->cycle : %d", nb_cycle);
	ft_putchar('\n');
}

void print_in_memory(t_env *e, int val, int pos, t_proc *proc)
{
	int i;
	int j;
	unsigned char u;
	char mem_hexa[2];
	int color;

	i = -1;
	color = 0;
	while (++i < 4)
	{
		u = val >> (24 - (8 * i));
		e->mem[(pos + i) % MEM_SIZE] = u;
		if (have_opt('n', e->opt))
		{
			j = -1;
			e->col[(pos + i) % MEM_SIZE] = proc->champ_color;
			while (++j < 2) // itoa_base 16 u = case_mem;
			{
				mem_hexa[j] = BASE_HEXA[u % 16];
				u /= 16;
			}
			mvaddch((pos + i) % MEM_SIZE / 64, ((pos + i) % MEM_SIZE % 64) *\
			3, mem_hexa[1]);
			mvaddch((pos + i) % MEM_SIZE / 64, ((pos + i) % MEM_SIZE % 64) *\
			3 + 1, mem_hexa[0]);
			mvaddch((pos + i) % MEM_SIZE / 64, ((pos + i) % MEM_SIZE % 64) *\
			3 + 2, ' ');
			mvchgat((pos + i) % MEM_SIZE / 64, ((pos + i) % MEM_SIZE % 64) *\
			3, 2, A_NORMAL, proc->champ_color, NULL);
		}
	}
}
