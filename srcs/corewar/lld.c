/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 13:07:16 by fgiraud           #+#    #+#             */
/*   Updated: 2016/05/05 14:26:46 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

// • lld : Signifie long-load, donc son opcode est évidemment 13. C’est la même chose
// que ld, mais sans % IDX_MOD. Modifie le carry.

int		lld(t_env *e, t_proc *proc)
{
	int pos;

	if (proc->inst.arg[1] > REG_NUMBER || proc->inst.arg[1] <= 0)
		return (0);
	if (((proc->inst.odc >> 6) & IND_CODE) == IND_CODE)
	{
		pos = (proc->pos + (proc->inst.arg[0])) % MEM_SIZE;
		if (pos < 0)
			pos = MEM_SIZE - pos;
		proc->r[proc->inst.arg[1] - 1] = ind_to_int(e->mem, pos);
	}
	else
		proc->r[proc->inst.arg[1] - 1] = proc->inst.arg[0];
	if (proc->r[proc->inst.arg[1] - 1] == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	if (e->verbose & VERBOSE_OP)
		ft_printf("P %4d | %s %d r%d\n", proc->index, "lld",\
		proc->r[proc->inst.arg[1] - 1], proc->inst.arg[1]);
	return (1);
}
