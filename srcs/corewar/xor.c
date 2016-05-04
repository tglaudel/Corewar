/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 14:32:18 by fgiraud           #+#    #+#             */
/*   Updated: 2016/05/04 18:16:36 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

int xor(t_env *e, t_proc *proc)
{
	(void)e;
	if (proc->inst.arg[2] > REG_NUMBER || proc->inst.arg[2] <= 0)
		return (0);
	proc->r[proc->inst.arg[2] - 1] = proc->inst.arg[0] ^ proc->inst.arg[1];
	if (proc->r[proc->inst.arg[2] - 1] == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	if (e->verbose & VERBOSE_OP)
		ft_printf("P %4d | %s %d %d r%d\n", proc->index, "xor",\
		proc->inst.arg[0], proc->inst.arg[1], proc->inst.arg[2]);
	return (1);
}
