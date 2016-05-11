/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 11:51:16 by fgiraud           #+#    #+#             */
/*   Updated: 2016/05/11 09:26:49 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

int		sti(t_env *e, t_proc *proc)
{
	int pos;
	int val1;
	int val2;
	int pos_in_mem;

	if (!check_args(proc, 4, 1) || !check_args(proc, 2, 2))
		return (0);
	if (proc->inst.arg[0] > REG_NUMBER || proc->inst.arg[0] <= 0)
		return (0);
	val1 = recup_value(e->mem, proc, 4, 1);
	// ft_putnbr(proc->r[proc->inst.arg[1]]);
	// ft_putchar('\n');
	// ft_putnbr(val1);
	// ft_putchar('\n');
	val2 = recup_value(e->mem, proc, 2, 2);
	pos = (val1 + val2) % IDX_MOD;
	pos = (pos + proc->pos) % MEM_SIZE;
	pos_in_mem = pos;
	if (pos < 0)
		pos = MEM_SIZE + pos;
	print_in_memory(e, proc->r[proc->inst.arg[0] - 1], pos, proc);
	if (e->verbose & VERBOSE_OP)
	{
		printf("P %4d | %s r%d %d %d\n", proc->index, "sti",\
		proc->inst.arg[0], val1, val2);
		printf("       | -> store to %d + %d = %d (with pc and mod %d)\n",\
		val1, val2, val1 + val2, pos_in_mem);
	}
	return (1);
}
