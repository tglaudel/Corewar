/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 14:32:18 by fgiraud           #+#    #+#             */
/*   Updated: 2016/05/14 10:51:16 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

int		xor(t_env *e, t_proc *proc)
{
	int val1;
	int val2;

	if (!check_args(proc, 6, 0) || !check_args(proc, 4, 1))
		return (0);
	if (proc->inst.arg[2] > REG_NUMBER || proc->inst.arg[2] <= 0)
		return (0);
	val1 = recup_value(e->mem, proc, 6, 0);
	val2 = recup_value(e->mem, proc, 4, 1);
	proc->r[proc->inst.arg[2] - 1] = val1 ^ val2;
	if (proc->r[proc->inst.arg[2] - 1] == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	if (e->verbose & VERBOSE_OP)
		ft_printf("P %4d | %s %d %d r%d\n", proc->index, "xor",\
		val1, val2, proc->inst.arg[2]);
	return (1);
}
