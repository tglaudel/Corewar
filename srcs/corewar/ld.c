/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 13:49:52 by fgiraud           #+#    #+#             */
/*   Updated: 2016/05/03 18:59:37 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

int		ld(t_env *e, t_proc *proc)
{
	int pos;

	if (proc->inst.arg[1] >= REG_NUMBER)
		return (0);
	if (((proc->inst.odc >> 6) & IND_CODE) == IND_CODE)
	{
		pos = proc->pos + (proc->inst.arg[0] % IDX_MOD);
		proc->r[proc->inst.arg[1] - 1] = ind_to_int(e->mem, pos);
	}
	else
		proc->r[proc->inst.arg[1] - 1] = proc->inst.arg[0];
	if (proc->r[proc->inst.arg[1] - 1] == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	if (e->verbose & VERBOSE_OP)
		ft_printf("P %4d | %s %d r%d\n", proc->index, "ld", proc->r[proc->inst.arg[1] - 1],\
		proc->inst.arg[1]);
	return (1);
}
