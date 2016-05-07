/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 11:51:16 by fgiraud           #+#    #+#             */
/*   Updated: 2016/05/07 19:11:59 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

int		sti(t_env *e, t_proc *proc)
{
	int pos;
	int val1;
	int val2;

	if (!check_args(proc, 4, 1) || !check_args(proc, 2, 2))
		return (0);
	if (proc->inst.arg[0] > REG_NUMBER || proc->inst.arg[0] <= 0)
		return (0);
	val1 = recup_value(e->mem, proc, 4, 1);
	val2 = recup_value(e->mem, proc, 2, 2);
	pos = ((val1 + val2) + proc->pos) % MEM_SIZE;
	if (pos < 0)
		pos = MEM_SIZE + pos;
	print_in_memory(e, proc->r[proc->inst.arg[0] - 1], pos, proc);
	if (e->verbose & VERBOSE_OP)
		ft_printf("P %4d | %s r%d %d %d\n", proc->index, "sti",\
		proc->inst.arg[0], proc->inst.arg[1], proc->inst.arg[2]);
	return (1);
}
