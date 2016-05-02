/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 18:00:08 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/02 14:24:18 by tglaudel         ###   ########.fr       */
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

void		print_op(t_proc *proc, int i, int cycle)
{
	if (g_op_tab[i].nb_arg == 1)
		ft_printf("P %5d| %s %d -> cycle %d\n", proc->index, g_op_tab[i].name,\
		proc->inst.arg[0], cycle);
	else if (g_op_tab[i].nb_arg == 2)
		ft_printf("P %5d| %s %d %d -> cycle %d\n", proc->index, g_op_tab[i].name,\
		proc->inst.arg[0], proc->inst.arg[1], cycle);
	else if (g_op_tab[i].nb_arg == 3)
		ft_printf("P %5d| %s %d %d %d -> cycle %d\n", proc->index, g_op_tab[i].name,\
		proc->inst.arg[0], proc->inst.arg[1], proc->inst.arg[2], cycle);
}
