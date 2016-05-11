/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 13:07:16 by fgiraud           #+#    #+#             */
/*   Updated: 2016/05/11 09:26:08 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

// • lld : Signifie long-load, donc son opcode est évidemment 13. C’est la même chose
// que ld, mais sans % IDX_MOD. Modifie le carry.

int		lld(t_env *e, t_proc *proc)
{
	int val1;

	if (proc->inst.arg[1] > REG_NUMBER || proc->inst.arg[1] <= 0)
		return (0);
	val1 = recup_value(e->mem, proc, 6, 0);
	if (val1 == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	proc->r[proc->inst.arg[1] - 1] = val1;
	if (e->verbose & VERBOSE_OP)
		printf("P %4d | %s %d r%d\n", proc->index, "lld",\
		val1, proc->inst.arg[1]);
	return (1);
}
