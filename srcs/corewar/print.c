/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 18:00:08 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/06 18:57:16 by tglaudel         ###   ########.fr       */
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
			while (++j < 2) // itoa_base 16 u = case_mem;
			{
				mem_hexa[j] = BASE_HEXA[u % 16];
				u /= 16;
			}
			mvaddch((pos + i) % MEM_SIZE / 64, ((pos + i) % MEM_SIZE % 64) * 3, mem_hexa[1]);
			mvaddch((pos + i) % MEM_SIZE / 64, ((pos + i) % MEM_SIZE % 64) * 3 + 1, mem_hexa[0]);
			mvaddch((pos + i) % MEM_SIZE / 64, ((pos + i) % MEM_SIZE % 64) * 3 + 2, ' ');
			mvchgat((pos + i) % MEM_SIZE / 64, ((pos + i) % MEM_SIZE % 64) * 3, 2, A_NORMAL, proc->champ_color, NULL);
		}
	}
}


// void		print_op(t_proc *proc, char *function)
// {
// 	if (g_op_tab[i].nb_arg == 1)
// 		ft_printf("P %5d| %s %d", proc->index, function, proc->inst.arg[0]);
// 	else if (g_op_tab[i].nb_arg == 2)
// 		ft_printf("P %5d| %s %d %d", proc->index, function, proc->inst.arg[0],\
// 		proc->inst.arg[1]);
// 	else if (g_op_tab[i].nb_arg == 3)
// 		ft_printf("P %5d| %s %d %d %d", proc->index, function, \
// 		proc->inst.arg[0], proc->inst.arg[1], proc->inst.arg[2]);
// }
