/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 18:00:08 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/04 15:44:31 by tglaudel         ###   ########.fr       */
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

void print_in_memory(unsigned char *mem, int val, int pos)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		mem[(pos + i) % MEM_SIZE] = val >> (24 - (8 * i));
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
