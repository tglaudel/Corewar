/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 14:26:08 by fgiraud           #+#    #+#             */
/*   Updated: 2016/05/11 09:25:27 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

int and(t_env *e, t_proc *proc)
{
	int val1;
	int val2;

	if (!check_args(proc, 6, 0) || !check_args(proc, 4, 1))
		return (0);
	if (proc->inst.arg[2] > REG_NUMBER || proc->inst.arg[2] <= 0)
		return (0);
	val1 = recup_value(e->mem, proc, 6, 0);
	val2 = recup_value(e->mem, proc, 4, 1);
	proc->r[proc->inst.arg[2] - 1] = val1 & val2;
	if (proc->r[proc->inst.arg[2] - 1] == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	if (e->verbose & VERBOSE_OP)
		printf("P %4d | %s %d %d r%d\n", proc->index, "and",\
		val1, val2, proc->inst.arg[2]);
	return (1);
}
